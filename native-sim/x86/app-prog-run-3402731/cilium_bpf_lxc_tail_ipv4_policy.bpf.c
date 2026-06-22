extern char __config_allow_icmp_frag_needed;
extern char __config_debug_lb;
extern char __config_enable_conntrack_accounting;
extern char __config_enable_icmp_rule;
extern char __config_enable_ipv4_fragments;
extern char __config_enable_jiffies;
extern char __config_enable_netkit;
extern char __config_enable_policy_accounting;
extern char __config_enable_tproxy;
extern char __config_endpoint_id;
extern char __config_events_map_burst_limit;
extern char __config_events_map_rate_limit;
extern char __config_interface_ifindex;
extern char __config_kernel_hz;
extern char __config_policy_verdict_log_filter;
extern char __config_security_label;
extern char __config_service_loopback_ipv4;
extern char __config_trace_payload_len;
extern char __config_tracing_ip_option_type;
extern char cilium_auth_map;
extern char cilium_calls;
extern char cilium_ct4_global;
extern char cilium_ct_any4_global;
extern char cilium_events;
extern char cilium_ipcache_v2;
extern char cilium_lb4_reverse_nat;
extern char cilium_metrics;
extern char cilium_node_map_v2;
extern char cilium_percpu_trace_id;
extern char cilium_policy_v2;
extern char cilium_policystats;
extern char cilium_ratelimit;
extern char cilium_ratelimit_metrics;
extern char cilium_runtime_config;
extern char cilium_signals;
extern char cilium_tail_call_buffer4;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int cilium_bpf_lxc_tail_ipv4_policy_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0xa: sub    rsp,0xf8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 248ULL);
x86_l_11:
	/* 0x11: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_14:
	/* 0x14: mov    QWORD PTR [rsp+0x9e],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 678604832768ULL);
x86_l_20:
	/* 0x20: mov    QWORD PTR [rsp+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_2c:
	/* 0x2c: mov    r14d,DWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_30:
	/* 0x30: mov    esi,DWORD PTR [rdi+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_33:
	/* 0x33: mov    DWORD PTR [rdi+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_3a:
	/* 0x3a: mov    ecx,DWORD PTR [rdi+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_3d:
	/* 0x3d: mov    QWORD PTR [rdi+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_45:
	/* 0x45: mov    edx,DWORD PTR [rdi+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_48:
	/* 0x48: mov    DWORD PTR [rdi+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_4f:
	/* 0x4f: mov    eax,DWORD PTR [rdi+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_52:
	/* 0x52: sub    eax,DWORD PTR [rdi+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RDI, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_55:
	/* 0x55: cmp    eax,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 34ULL);
x86_l_58:
	/* 0x58: jae    68 <tail_ipv4_policy+0x68> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x58, 0x68, x86_l_68);
x86_l_5a:
	/* 0x5a: mov    r15d,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967162ULL);
x86_l_60:
	/* 0x60: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_63:
	/* 0x63: jmp    1722 <tail_ipv4_policy+0x1722> */
	X86_SIM_X86_JMP(0x63, 0x1722, x86_l_1722);
x86_l_68:
	/* 0x68: mov    DWORD PTR [rsp+0xc8],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_6f:
	/* 0x6f: mov    DWORD PTR [rsp+0xb4],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 180ULL);
x86_l_76:
	/* 0x76: mov    DWORD PTR [rsp+0xc4],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_7d:
	/* 0x7d: mov    DWORD PTR [rsp+0x8],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_82:
	/* 0x82: mov    r14,QWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_89:
	/* 0x89: mov    rax,QWORD PTR [rip+0xbf00] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_interface_ifindex)));
x86_l_90:
	/* 0x90: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_92:
	/* 0x92: mov    DWORD PTR [rsp+0xd0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_99:
	/* 0x99: mov    DWORD PTR [rsp+0xd4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 910533066752ULL);
x86_l_a4:
	/* 0xa4: movzx  r13d,WORD PTR [r14+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 20ULL);
x86_l_a9:
	/* 0xa9: test   r13d,0xff3f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R13, X86_WIDTH_32, 65343ULL);
x86_l_b0:
	/* 0xb0: setne  bpl */
	X86_SIM_L_EXEC_SETCC(X86_RBP, X86_CC_NE);
x86_l_b4:
	/* 0xb4: mov    eax,DWORD PTR [r14+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_b8:
	/* 0xb8: mov    DWORD PTR [rsp+0xc0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_bf:
	/* 0xbf: mov    rax,QWORD PTR [rip+0xbf00] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_ipv4_fragments)));
x86_l_c6:
	/* 0xc6: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c9:
	/* 0xc9: sete   r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_E);
x86_l_cd:
	/* 0xcd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d2:
	/* 0xd2: mov    rdi,QWORD PTR [rip+0xbf00] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_tail_call_buffer4)));
x86_l_d9:
	/* 0xd9: lea    rsi,[rsp+0xd4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 212ULL);
x86_l_e1:
	/* 0xe1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e3:
	/* 0xe3: mov    r15d,0xffffff48 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967112ULL);
x86_l_e9:
	/* 0xe9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ec:
	/* 0xec: je     171a <tail_ipv4_policy+0x171a> */
	X86_SIM_X86_JCC(X86_CC_E, 0xec, 0x171a, x86_l_171a);
x86_l_f2:
	/* 0xf2: mov    r8,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RAX, X86_WIDTH_64);
x86_l_f5:
	/* 0xf5: cmp    DWORD PTR [rax+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_f9:
	/* 0xf9: je     171a <tail_ipv4_policy+0x171a> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf9, 0x171a, x86_l_171a);
x86_l_ff:
	/* 0xff: mov    eax,DWORD PTR [r8+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_103:
	/* 0x103: mov    DWORD PTR [rsp+0xb0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_10a:
	/* 0x10a: mov    eax,DWORD PTR [r8+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_10e:
	/* 0x10e: mov    esi,DWORD PTR [r8+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_112:
	/* 0x112: mov    DWORD PTR [rsp+0x88],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_119:
	/* 0x119: and    eax,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_11c:
	/* 0x11c: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_11f:
	/* 0x11f: mov    QWORD PTR [rsp+0x18],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_124:
	/* 0x124: jne    156 <tail_ipv4_policy+0x156> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x124, 0x156, x86_l_156);
x86_l_126:
	/* 0x126: movzx  r15d,WORD PTR [r8+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_12b:
	/* 0x12b: test   r15b,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R15, X86_WIDTH_8, 16ULL);
x86_l_12f:
	/* 0x12f: je     1a2 <tail_ipv4_policy+0x1a2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12f, 0x1a2, x86_l_1a2);
x86_l_131:
	/* 0x131: movzx  eax,WORD PTR [rbx+0x86] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 134ULL);
x86_l_138:
	/* 0x138: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_13c:
	/* 0x13c: test   DWORD PTR [rsp+0x38],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168578ULL);
x86_l_144:
	/* 0x144: jne    1a2 <tail_ipv4_policy+0x1a2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x144, 0x1a2, x86_l_1a2);
x86_l_146:
	/* 0x146: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_149:
	/* 0x149: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14c:
	/* 0x14c: mov    r14d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_151:
	/* 0x151: jmp    a80 <tail_ipv4_policy+0xa80> */
	X86_SIM_X86_JMP(0x151, 0xa80, x86_l_a80);
x86_l_156:
	/* 0x156: movzx  eax,WORD PTR [rbx+0x86] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 134ULL);
x86_l_15d:
	/* 0x15d: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_161:
	/* 0x161: mov    eax,DWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_165:
	/* 0x165: test   al,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_167:
	/* 0x167: jne    256 <tail_ipv4_policy+0x256> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x167, 0x256, x86_l_256);
x86_l_16d:
	/* 0x16d: cmp    DWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_175:
	/* 0x175: jne    201 <tail_ipv4_policy+0x201> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x175, 0x201, x86_l_201);
x86_l_17b:
	/* 0x17b: mov    eax,DWORD PTR [r14+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_17f:
	/* 0x17f: mov    rcx,QWORD PTR [rip+0xbf00] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_service_loopback_ipv4)));
x86_l_186:
	/* 0x186: cmp    eax,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_188:
	/* 0x188: jne    201 <tail_ipv4_policy+0x201> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x188, 0x201, x86_l_201);
x86_l_18a:
	/* 0x18a: movzx  r14d,BYTE PTR [r8+0xd] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 13ULL);
x86_l_18f:
	/* 0x18f: cmp    BYTE PTR [r8+0xc],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 51539607558ULL);
x86_l_194:
	/* 0x194: jne    1cb <tail_ipv4_policy+0x1cb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x194, 0x1cb, x86_l_1cb);
x86_l_196:
	/* 0x196: mov    r15,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSI, X86_WIDTH_64);
x86_l_199:
	/* 0x199: mov    rdi,QWORD PTR [rip+0xbf00] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct4_global)));
x86_l_1a0:
	/* 0x1a0: jmp    1d5 <tail_ipv4_policy+0x1d5> */
	X86_SIM_X86_JMP(0x1a0, 0x1d5, x86_l_1d5);
x86_l_1a2:
	/* 0x1a2: movzx  eax,WORD PTR [r8+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_1a7:
	/* 0x1a7: movzx  edx,WORD PTR [r8+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_1ac:
	/* 0x1ac: test   dx,dx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_16);
x86_l_1af:
	/* 0x1af: jne    10ea <tail_ipv4_policy+0x10ea> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1af, 0x10ea, x86_l_10ea);
x86_l_1b5:
	/* 0x1b5: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_1b8:
	/* 0x1b8: mov    r14d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bd:
	/* 0x1bd: jne    1109 <tail_ipv4_policy+0x1109> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1bd, 0x1109, x86_l_1109);
x86_l_1c3:
	/* 0x1c3: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c6:
	/* 0x1c6: jmp    1334 <tail_ipv4_policy+0x1334> */
	X86_SIM_X86_JMP(0x1c6, 0x1334, x86_l_1334);
x86_l_1cb:
	/* 0x1cb: mov    r15,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSI, X86_WIDTH_64);
x86_l_1ce:
	/* 0x1ce: mov    rdi,QWORD PTR [rip+0xbf00] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct_any4_global)));
x86_l_1d5:
	/* 0x1d5: mov    BYTE PTR [r8+0xd],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 55834574848ULL);
x86_l_1da:
	/* 0x1da: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1df:
	/* 0x1df: mov    rsi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1e4:
	/* 0x1e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e6:
	/* 0x1e6: mov    r8,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1eb:
	/* 0x1eb: mov    BYTE PTR [r8+0xd],r14b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R8, X86_R14, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 13ULL);
x86_l_1ef:
	/* 0x1ef: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f2:
	/* 0x1f2: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_1f5:
	/* 0x1f5: je     201 <tail_ipv4_policy+0x201> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1f5, 0x201, x86_l_201);
x86_l_1f7:
	/* 0x1f7: test   BYTE PTR [rax+0x24],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 154618822664ULL);
x86_l_1fb:
	/* 0x1fb: jne    862 <tail_ipv4_policy+0x862> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1fb, 0x862, x86_l_862);
x86_l_201:
	/* 0x201: test   BYTE PTR [r8+0x24],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 154618822657ULL);
x86_l_206:
	/* 0x206: jne    256 <tail_ipv4_policy+0x256> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x206, 0x256, x86_l_256);
x86_l_208:
	/* 0x208: mov    rax,QWORD PTR [rip+0xbf00] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_security_label)));
x86_l_20f:
	/* 0x20f: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_211:
	/* 0x211: movzx  ecx,WORD PTR [r8+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_216:
	/* 0x216: movzx  r13d,BYTE PTR [r8+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 12ULL);
x86_l_21b:
	/* 0x21b: mov    DWORD PTR [rsp+0x70],0x40 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337216ULL);
x86_l_223:
	/* 0x223: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_227:
	/* 0x227: mov    DWORD PTR [rsp+0x74],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_22b:
	/* 0x22b: mov    BYTE PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_230:
	/* 0x230: mov    BYTE PTR [rsp+0x79],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 121ULL);
x86_l_235:
	/* 0x235: mov    WORD PTR [rsp+0x7a],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 122ULL);
x86_l_23a:
	/* 0x23a: mov    r14,QWORD PTR [rip+0xbf00] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_allow_icmp_frag_needed)));
x86_l_241:
	/* 0x241: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_245:
	/* 0x245: mov    DWORD PTR [rsp+0x30],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_249:
	/* 0x249: je     274 <tail_ipv4_policy+0x274> */
	X86_SIM_X86_JCC(X86_CC_E, 0x249, 0x274, x86_l_274);
x86_l_24b:
	/* 0x24b: cmp    r13b,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_8, 1ULL);
x86_l_24f:
	/* 0x24f: je     290 <tail_ipv4_policy+0x290> */
	X86_SIM_X86_JCC(X86_CC_E, 0x24f, 0x290, x86_l_290);
x86_l_251:
	/* 0x251: jmp    30c <tail_ipv4_policy+0x30c> */
	X86_SIM_X86_JMP(0x251, 0x30c, x86_l_30c);
x86_l_256:
	/* 0x256: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_259:
	/* 0x259: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_25c:
	/* 0x25c: mov    r14d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_261:
	/* 0x261: cmp    DWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_269:
	/* 0x269: jne    a76 <tail_ipv4_policy+0xa76> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x269, 0xa76, x86_l_a76);
x86_l_26f:
	/* 0x26f: jmp    831 <tail_ipv4_policy+0x831> */
	X86_SIM_X86_JMP(0x26f, 0x831, x86_l_831);
x86_l_274:
	/* 0x274: mov    rax,QWORD PTR [rip+0xbf00] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_icmp_rule)));
x86_l_27b:
	/* 0x27b: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_27e:
	/* 0x27e: cmp    r13b,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_8, 1ULL);
x86_l_282:
	/* 0x282: jne    30c <tail_ipv4_policy+0x30c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x282, 0x30c, x86_l_30c);
x86_l_288:
	/* 0x288: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_28a:
	/* 0x28a: je     30c <tail_ipv4_policy+0x30c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x28a, 0x30c, x86_l_30c);
x86_l_290:
	/* 0x290: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_295:
	/* 0x295: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_29a:
	/* 0x29a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_29d:
	/* 0x29d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2a2:
	/* 0x2a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a4:
	/* 0x2a4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a6:
	/* 0x2a6: js     3c8 <tail_ipv4_policy+0x3c8> */
	X86_SIM_X86_JCC(X86_CC_S, 0x2a6, 0x3c8, x86_l_3c8);
x86_l_2ac:
	/* 0x2ac: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b0:
	/* 0x2b0: mov    r8,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2b5:
	/* 0x2b5: je     2f4 <tail_ipv4_policy+0x2f4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2b5, 0x2f4, x86_l_2f4);
x86_l_2b7:
	/* 0x2b7: cmp    BYTE PTR [rsp+0x38],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 240518168579ULL);
x86_l_2bc:
	/* 0x2bc: jne    2f4 <tail_ipv4_policy+0x2f4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2bc, 0x2f4, x86_l_2f4);
x86_l_2be:
	/* 0x2be: cmp    BYTE PTR [rsp+0x39],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 244813135876ULL);
x86_l_2c3:
	/* 0x2c3: jne    2f4 <tail_ipv4_policy+0x2f4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2c3, 0x2f4, x86_l_2f4);
x86_l_2c5:
	/* 0x2c5: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c7:
	/* 0x2c7: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c9:
	/* 0x2c9: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2cc:
	/* 0x2cc: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2cf:
	/* 0x2cf: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d2:
	/* 0x2d2: mov    r14d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d7:
	/* 0x2d7: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_2da:
	/* 0x2da: setne  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_NE);
x86_l_2de:
	/* 0x2de: cmp    DWORD PTR [rsp+0x88],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 584115552257ULL);
x86_l_2e6:
	/* 0x2e6: je     4d7 <tail_ipv4_policy+0x4d7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2e6, 0x4d7, x86_l_4d7);
x86_l_2ec:
	/* 0x2ec: mov    r9d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_R13, X86_WIDTH_32);
x86_l_2ef:
	/* 0x2ef: jmp    4e3 <tail_ipv4_policy+0x4e3> */
	X86_SIM_X86_JMP(0x2ef, 0x4e3, x86_l_4e3);
x86_l_2f4:
	/* 0x2f4: mov    rax,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_icmp_rule)));
x86_l_2fb:
	/* 0x2fb: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fe:
	/* 0x2fe: je     30c <tail_ipv4_policy+0x30c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2fe, 0x30c, x86_l_30c);
x86_l_300:
	/* 0x300: mov    eax,DWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_304:
	/* 0x304: shl    eax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_307:
	/* 0x307: mov    WORD PTR [rsp+0x7a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 122ULL);
x86_l_30c:
	/* 0x30c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_311:
	/* 0x311: mov    rdi,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_policy_v2)));
x86_l_318:
	/* 0x318: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_31d:
	/* 0x31d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31f:
	/* 0x31f: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_322:
	/* 0x322: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_325:
	/* 0x325: mov    r14d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_32a:
	/* 0x32a: je     1154 <tail_ipv4_policy+0x1154> */
	X86_SIM_X86_JCC(X86_CC_E, 0x32a, 0x1154, x86_l_1154);
x86_l_330:
	/* 0x330: cmp    DWORD PTR [r15+0x4],0xffffffff */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 21474836479ULL);
x86_l_335:
	/* 0x335: jne    1154 <tail_ipv4_policy+0x1154> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x335, 0x1154, x86_l_1154);
x86_l_33b:
	/* 0x33b: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_33d:
	/* 0x33d: movzx  ebp,WORD PTR [r15+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_342:
	/* 0x342: mov    rax,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_policy_accounting)));
x86_l_349:
	/* 0x349: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_34c:
	/* 0x34c: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_34e:
	/* 0x34e: mov    r8,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_353:
	/* 0x353: je     458 <tail_ipv4_policy+0x458> */
	X86_SIM_X86_JCC(X86_CC_E, 0x353, 0x458, x86_l_458);
x86_l_359:
	/* 0x359: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_35b:
	/* 0x35b: shr    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHR, 3ULL);
x86_l_35e:
	/* 0x35e: movzx  ecx,BYTE PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 120ULL);
x86_l_363:
	/* 0x363: mov    r12d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_367:
	/* 0x367: mov    rdx,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_endpoint_id)));
x86_l_36e:
	/* 0x36e: movzx  edx,WORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_371:
	/* 0x371: mov    WORD PTR [rsp+0x20],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_376:
	/* 0x376: mov    BYTE PTR [rsp+0x22],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 146028888064ULL);
x86_l_37b:
	/* 0x37b: mov    BYTE PTR [rsp+0x23],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 35ULL);
x86_l_37f:
	/* 0x37f: and    cl,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 1ULL);
x86_l_382:
	/* 0x382: mov    DWORD PTR [rsp+0x24],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_387:
	/* 0x387: mov    BYTE PTR [rsp+0x28],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_38b:
	/* 0x38b: cmp    bpl,0x47 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 71ULL);
x86_l_38f:
	/* 0x38f: mov    QWORD PTR [rsp+0x10],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_394:
	/* 0x394: ja     3a8 <tail_ipv4_policy+0x3a8> */
	X86_SIM_X86_JCC(X86_CC_A, 0x394, 0x3a8, x86_l_3a8);
x86_l_396:
	/* 0x396: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_399:
	/* 0x399: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_39b:
	/* 0x39b: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_39e:
	/* 0x39e: movzx  r13d,r13b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R13, X86_R13, X86_WIDTH_32, X86_WIDTH_8);
x86_l_3a2:
	/* 0x3a2: cmovne r13d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RCX, X86_WIDTH_32, X86_CC_NE);
x86_l_3a6:
	/* 0x3a6: jmp    3f1 <tail_ipv4_policy+0x3f1> */
	X86_SIM_X86_JMP(0x3a6, 0x3f1, x86_l_3f1);
x86_l_3a8:
	/* 0x3a8: cmp    bpl,0xbf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 191ULL);
x86_l_3ac:
	/* 0x3ac: ja     3ed <tail_ipv4_policy+0x3ed> */
	X86_SIM_X86_JCC(X86_CC_A, 0x3ac, 0x3ed, x86_l_3ed);
x86_l_3ae:
	/* 0x3ae: mov    cl,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 24ULL);
x86_l_3b0:
	/* 0x3b0: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_3b2:
	/* 0x3b2: mov    eax,0xffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 65535ULL);
x86_l_3b7:
	/* 0x3b7: shlx   eax,eax,ecx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RAX, X86_RAX, X86_WIDTH_32, X86_RCX, X86_ALU_SHL);
x86_l_3bc:
	/* 0x3bc: rol    ax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_3c0:
	/* 0x3c0: mov    ecx,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3c4:
	/* 0x3c4: and    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_AND);
x86_l_3c6:
	/* 0x3c6: jmp    3f1 <tail_ipv4_policy+0x3f1> */
	X86_SIM_X86_JMP(0x3c6, 0x3f1, x86_l_3f1);
x86_l_3c8:
	/* 0x3c8: xor    r9d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R9, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3cb:
	/* 0x3cb: mov    r15d,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967162ULL);
x86_l_3d1:
	/* 0x3d1: mov    sil,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_8, 1ULL);
x86_l_3d4:
	/* 0x3d4: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3d7:
	/* 0x3d7: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3da:
	/* 0x3da: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3dc:
	/* 0x3dc: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3de:
	/* 0x3de: mov    r14d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3e3:
	/* 0x3e3: mov    r8,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3e8:
	/* 0x3e8: jmp    4e3 <tail_ipv4_policy+0x4e3> */
	X86_SIM_X86_JMP(0x3e8, 0x4e3, x86_l_4e3);
x86_l_3ed:
	/* 0x3ed: mov    ecx,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3f1:
	/* 0x3f1: mov    BYTE PTR [rsp+0x29],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 41ULL);
x86_l_3f6:
	/* 0x3f6: mov    WORD PTR [rsp+0x2a],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_3fb:
	/* 0x3fb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_400:
	/* 0x400: mov    rdi,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_policystats)));
x86_l_407:
	/* 0x407: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_40c:
	/* 0x40c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_40e:
	/* 0x40e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_411:
	/* 0x411: je     41e <tail_ipv4_policy+0x41e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x411, 0x41e, x86_l_41e);
x86_l_413:
	/* 0x413: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_417:
	/* 0x417: add QWORD PTR [rax+0x8],r12 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_41c:
	/* 0x41c: jmp    449 <tail_ipv4_policy+0x449> */
	X86_SIM_X86_JMP(0x41c, 0x449, x86_l_449);
x86_l_41e:
	/* 0x41e: mov    QWORD PTR [rsp+0x38],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168577ULL);
x86_l_427:
	/* 0x427: mov    QWORD PTR [rsp+0x40],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_42c:
	/* 0x42c: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_431:
	/* 0x431: mov    rdi,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_policystats)));
x86_l_438:
	/* 0x438: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_43d:
	/* 0x43d: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_442:
	/* 0x442: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_447:
	/* 0x447: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_449:
	/* 0x449: movzx  eax,WORD PTR [r15+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_44e:
	/* 0x44e: mov    r8,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_453:
	/* 0x453: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_458:
	/* 0x458: cmp    bpl,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 8ULL);
x86_l_45c:
	/* 0x45c: setae  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_AE);
x86_l_45f:
	/* 0x45f: shl    cl,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_SHL, 2ULL);
x86_l_462:
	/* 0x462: or     cl,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_OR, 1ULL);
x86_l_465:
	/* 0x465: cmp    bpl,0x48 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 72ULL);
x86_l_469:
	/* 0x469: movzx  ecx,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_46c:
	/* 0x46c: mov    edi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 2ULL);
x86_l_471:
	/* 0x471: cmovb  edi,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDI, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_474:
	/* 0x474: mov    edx,DWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_478:
	/* 0x478: test   al,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_47a:
	/* 0x47a: jne    1b70 <tail_ipv4_policy+0x1b70> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x47a, 0x1b70, x86_l_1b70);
x86_l_480:
	/* 0x480: movzx  r13d,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_484:
	/* 0x484: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_488:
	/* 0x488: test   rsi,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_64);
x86_l_48b:
	/* 0x48b: je     4ae <tail_ipv4_policy+0x4ae> */
	X86_SIM_X86_JCC(X86_CC_E, 0x48b, 0x4ae, x86_l_4ae);
x86_l_48d:
	/* 0x48d: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_490:
	/* 0x490: js     4ae <tail_ipv4_policy+0x4ae> */
	X86_SIM_X86_JCC(X86_CC_S, 0x490, 0x4ae, x86_l_4ae);
x86_l_492:
	/* 0x492: mov    eax,DWORD PTR [r15+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_496:
	/* 0x496: cmp    DWORD PTR [rsi+0x4],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_499:
	/* 0x499: jne    4ae <tail_ipv4_policy+0x4ae> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x499, 0x4ae, x86_l_4ae);
x86_l_49b:
	/* 0x49b: movzx  eax,BYTE PTR [rsi+0x3] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 3ULL);
x86_l_49f:
	/* 0x49f: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_4a1:
	/* 0x4a1: and    ecx,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 127ULL);
x86_l_4a4:
	/* 0x4a4: cmp    cx,r13w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R13, X86_WIDTH_16);
x86_l_4a8:
	/* 0x4a8: ja     1875 <tail_ipv4_policy+0x1875> */
	X86_SIM_X86_JCC(X86_CC_A, 0x4a8, 0x1875, x86_l_1875);
x86_l_4ae:
	/* 0x4ae: movzx  r12d,WORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4b2:
	/* 0x4b2: and    r13b,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_8, X86_ALU_AND, 127ULL);
x86_l_4b6:
	/* 0x4b6: jne    1a8a <tail_ipv4_policy+0x1a8a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4b6, 0x1a8a, x86_l_1a8a);
x86_l_4bc:
	/* 0x4bc: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4bf:
	/* 0x4bf: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4c2:
	/* 0x4c2: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_4c5:
	/* 0x4c5: setne  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_NE);
x86_l_4c9:
	/* 0x4c9: cmp    DWORD PTR [rsp+0x88],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 584115552257ULL);
x86_l_4d1:
	/* 0x4d1: jne    2ec <tail_ipv4_policy+0x2ec> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4d1, 0x2ec, x86_l_2ec);
x86_l_4d7:
	/* 0x4d7: mov    r9d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_R13, X86_WIDTH_32);
x86_l_4da:
	/* 0x4da: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_4dd:
	/* 0x4dd: je     a76 <tail_ipv4_policy+0xa76> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4dd, 0xa76, x86_l_a76);
x86_l_4e3:
	/* 0x4e3: mov    DWORD PTR [rsp+0x30],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4e8:
	/* 0x4e8: movzx  r11d,WORD PTR [r8+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_4ed:
	/* 0x4ed: movzx  r10d,BYTE PTR [r8+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 12ULL);
x86_l_4f2:
	/* 0x4f2: mov    r12d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_4f6:
	/* 0x4f6: mov    rax,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_4fd:
	/* 0x4fd: mov    ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ff:
	/* 0x4ff: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_502:
	/* 0x502: cmovb  ebp,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R12, X86_WIDTH_32, X86_CC_B);
x86_l_506:
	/* 0x506: mov    QWORD PTR [rsp+0x70],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337154ULL);
x86_l_50f:
	/* 0x50f: mov    rax,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_policy_verdict_log_filter)));
x86_l_516:
	/* 0x516: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_518:
	/* 0x518: mov    BYTE PTR [rsp+0x38],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 240518168577ULL);
x86_l_51d:
	/* 0x51d: movzx  ecx,BYTE PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 56ULL);
x86_l_522:
	/* 0x522: test   eax,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_524:
	/* 0x524: je     80b <tail_ipv4_policy+0x80b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x524, 0x80b, x86_l_80b);
x86_l_52a:
	/* 0x52a: mov    BYTE PTR [rsp+0x10],sil */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_52f:
	/* 0x52f: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_532:
	/* 0x532: movzx  esi,WORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_537:
	/* 0x537: cmovne esi,r15d */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_R15, X86_WIDTH_32, X86_CC_NE);
x86_l_53b:
	/* 0x53b: mov    rax,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_events_map_rate_limit)));
x86_l_542:
	/* 0x542: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_545:
	/* 0x545: je     768 <tail_ipv4_policy+0x768> */
	X86_SIM_X86_JCC(X86_CC_E, 0x545, 0x768, x86_l_768);
x86_l_54b:
	/* 0x54b: mov    DWORD PTR [rsp+0xb8],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_552:
	/* 0x552: mov    WORD PTR [rsp+0x7e],r11w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 126ULL);
x86_l_558:
	/* 0x558: mov    BYTE PTR [rsp+0xf],r10b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R10, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 15ULL);
x86_l_55d:
	/* 0x55d: mov    DWORD PTR [rsp+0xbc],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_565:
	/* 0x565: mov    DWORD PTR [rsp+0x90],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_56c:
	/* 0x56c: mov    QWORD PTR [rsp+0x80],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_574:
	/* 0x574: mov    rcx,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_events_map_burst_limit)));
x86_l_57b:
	/* 0x57b: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_57d:
	/* 0x57d: mov    QWORD PTR [rsp+0xf0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_585:
	/* 0x585: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_587:
	/* 0x587: mov    QWORD PTR [rsp+0xe0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_58f:
	/* 0x58f: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_594:
	/* 0x594: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_596:
	/* 0x596: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_598:
	/* 0x598: mov    QWORD PTR [rsp+0xe8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_5a0:
	/* 0x5a0: mov    eax,DWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_5a4:
	/* 0x5a4: mov    DWORD PTR [rsp+0xa8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_5ab:
	/* 0x5ab: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5b0:
	/* 0x5b0: mov    rdi,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit_metrics)));
x86_l_5b7:
	/* 0x5b7: lea    rsi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_5bf:
	/* 0x5bf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5c1:
	/* 0x5c1: mov    QWORD PTR [rsp+0xd8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_5c9:
	/* 0x5c9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5cc:
	/* 0x5cc: jne    604 <tail_ipv4_policy+0x604> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x5cc, 0x604, x86_l_604);
x86_l_5ce:
	/* 0x5ce: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_5d7:
	/* 0x5d7: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5dc:
	/* 0x5dc: mov    rdi,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit_metrics)));
x86_l_5e3:
	/* 0x5e3: lea    rsi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_5eb:
	/* 0x5eb: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5f0:
	/* 0x5f0: mov    QWORD PTR [rsp+0xd8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_5f8:
	/* 0x5f8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5fa:
	/* 0x5fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5fc:
	/* 0x5fc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5fe:
	/* 0x5fe: js     801 <tail_ipv4_policy+0x801> */
	X86_SIM_X86_JCC(X86_CC_S, 0x5fe, 0x801, x86_l_801);
x86_l_604:
	/* 0x604: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_609:
	/* 0x609: mov    rdi,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit)));
x86_l_610:
	/* 0x610: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_615:
	/* 0x615: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_617:
	/* 0x617: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_61a:
	/* 0x61a: je     6c0 <tail_ipv4_policy+0x6c0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x61a, 0x6c0, x86_l_6c0);
x86_l_620:
	/* 0x620: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_623:
	/* 0x623: mov    rdi,QWORD PTR [rsp+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_62b:
	/* 0x62b: mov    rsi,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RDI, X86_WIDTH_64);
x86_l_62e:
	/* 0x62e: sub    rsi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_631:
	/* 0x631: cmp    rsi,0x3b9aca00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 1000000000ULL);
x86_l_638:
	/* 0x638: jbe    72a <tail_ipv4_policy+0x72a> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x638, 0x72a, x86_l_72a);
x86_l_63e:
	/* 0x63e: mov    rdx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_641:
	/* 0x641: shr    rdx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_645:
	/* 0x645: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_64f:
	/* 0x64f: mulx   rcx,rcx,rcx */
	X86_SIM_L_EXEC_MULX(X86_RCX, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_654:
	/* 0x654: shr    rcx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_658:
	/* 0x658: imul   rdx,rcx,0x3b9aca00 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RDX, X86_RCX, X86_WIDTH_64, 1000000000ULL);
x86_l_65f:
	/* 0x65f: imul   rcx,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 224ULL);
x86_l_668:
	/* 0x668: add    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_66c:
	/* 0x66c: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_670:
	/* 0x670: sub    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_673:
	/* 0x673: add    rdi,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_676:
	/* 0x676: mov    QWORD PTR [rax],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_679:
	/* 0x679: mov    r8,QWORD PTR [rsp+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_681:
	/* 0x681: cmp    rcx,r8 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R8, X86_WIDTH_64);
x86_l_684:
	/* 0x684: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_68c:
	/* 0x68c: mov    edi,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_693:
	/* 0x693: mov    r9d,DWORD PTR [rsp+0xbc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_69b:
	/* 0x69b: movzx  r10d,BYTE PTR [rsp+0xf] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 15ULL);
x86_l_6a1:
	/* 0x6a1: movzx  r11d,WORD PTR [rsp+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_6a7:
	/* 0x6a7: mov    esi,DWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_6ae:
	/* 0x6ae: jbe    758 <tail_ipv4_policy+0x758> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x6ae, 0x758, x86_l_758);
x86_l_6b4:
	/* 0x6b4: mov    QWORD PTR [rax+0x8],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6b8:
	/* 0x6b8: mov    rcx,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R8, X86_WIDTH_64);
x86_l_6bb:
	/* 0x6bb: jmp    758 <tail_ipv4_policy+0x758> */
	X86_SIM_X86_JMP(0x6bb, 0x758, x86_l_758);
x86_l_6c0:
	/* 0x6c0: mov    rax,QWORD PTR [rsp+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_6c8:
	/* 0x6c8: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_6cd:
	/* 0x6cd: mov    rax,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_6d5:
	/* 0x6d5: dec    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_6d8:
	/* 0x6d8: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_6dd:
	/* 0x6dd: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_6e2:
	/* 0x6e2: mov    rdi,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit)));
x86_l_6e9:
	/* 0x6e9: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_6ee:
	/* 0x6ee: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_6f3:
	/* 0x6f3: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6f5:
	/* 0x6f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6f7:
	/* 0x6f7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_6f9:
	/* 0x6f9: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_701:
	/* 0x701: mov    edi,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_708:
	/* 0x708: mov    r9d,DWORD PTR [rsp+0xbc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_710:
	/* 0x710: movzx  r10d,BYTE PTR [rsp+0xf] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 15ULL);
x86_l_716:
	/* 0x716: movzx  r11d,WORD PTR [rsp+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_71c:
	/* 0x71c: mov    esi,DWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_723:
	/* 0x723: jns    768 <tail_ipv4_policy+0x768> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x723, 0x768, x86_l_768);
x86_l_725:
	/* 0x725: jmp    10da <tail_ipv4_policy+0x10da> */
	X86_SIM_X86_JMP(0x725, 0x10da, x86_l_10da);
x86_l_72a:
	/* 0x72a: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_72e:
	/* 0x72e: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_736:
	/* 0x736: mov    edi,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_73d:
	/* 0x73d: mov    r9d,DWORD PTR [rsp+0xbc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_745:
	/* 0x745: movzx  r10d,BYTE PTR [rsp+0xf] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 15ULL);
x86_l_74b:
	/* 0x74b: movzx  r11d,WORD PTR [rsp+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_751:
	/* 0x751: mov    esi,DWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_758:
	/* 0x758: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_75b:
	/* 0x75b: je     10da <tail_ipv4_policy+0x10da> */
	X86_SIM_X86_JCC(X86_CC_E, 0x75b, 0x10da, x86_l_10da);
x86_l_761:
	/* 0x761: dec    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_764:
	/* 0x764: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_768:
	/* 0x768: mov    rax,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_endpoint_id)));
x86_l_76f:
	/* 0x76f: movzx  eax,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_772:
	/* 0x772: mov    ecx,DWORD PTR [rbx+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_778:
	/* 0x778: mov    BYTE PTR [rsp+0x57],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 373662154752ULL);
x86_l_77d:
	/* 0x77d: mov    WORD PTR [rsp+0x55],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 365072220160ULL);
x86_l_784:
	/* 0x784: mov    WORD PTR [rsp+0x38],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 240518168581ULL);
x86_l_78b:
	/* 0x78b: mov    WORD PTR [rsp+0x3a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_790:
	/* 0x790: mov    DWORD PTR [rsp+0x3c],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_794:
	/* 0x794: mov    DWORD PTR [rsp+0x40],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_799:
	/* 0x799: mov    WORD PTR [rsp+0x44],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_79e:
	/* 0x79e: mov    WORD PTR [rsp+0x46],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 300647710721ULL);
x86_l_7a5:
	/* 0x7a5: mov    DWORD PTR [rsp+0x48],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_7aa:
	/* 0x7aa: mov    DWORD PTR [rsp+0x4c],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_7ae:
	/* 0x7ae: movbe  WORD PTR [rsp+0x50],r11w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R11, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 80ULL);
x86_l_7b6:
	/* 0x7b6: shl    dil,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_7ba:
	/* 0x7ba: or     dil,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_8, X86_ALU_OR, 1ULL);
x86_l_7be:
	/* 0x7be: mov    BYTE PTR [rsp+0x52],r10b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R10, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 82ULL);
x86_l_7c3:
	/* 0x7c3: mov    BYTE PTR [rsp+0x53],dil */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 83ULL);
x86_l_7c8:
	/* 0x7c8: mov    BYTE PTR [rsp+0x54],r9b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_7cd:
	/* 0x7cd: mov    DWORD PTR [rsp+0x58],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_7d1:
	/* 0x7d1: mov    DWORD PTR [rsp+0x5c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 395136991232ULL);
x86_l_7d9:
	/* 0x7d9: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_7de:
	/* 0x7de: shl    rbp,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_7e2:
	/* 0x7e2: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_7e7:
	/* 0x7e7: or     rdx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBP, X86_WIDTH_64, X86_ALU_OR);
x86_l_7ea:
	/* 0x7ea: mov    rsi,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_events)));
x86_l_7f1:
	/* 0x7f1: lea    rcx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_7f6:
	/* 0x7f6: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_7f9:
	/* 0x7f9: mov    r8d,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 40ULL);
x86_l_7ff:
	/* 0x7ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_801:
	/* 0x801: mov    r8,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_806:
	/* 0x806: movzx  esi,BYTE PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_80b:
	/* 0x80b: test   sil,sil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_8);
x86_l_80e:
	/* 0x80e: je     81e <tail_ipv4_policy+0x81e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x80e, 0x81e, x86_l_81e);
x86_l_810:
	/* 0x810: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_813:
	/* 0x813: jne    1722 <tail_ipv4_policy+0x1722> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x813, 0x1722, x86_l_1722);
x86_l_819:
	/* 0x819: jmp    1691 <tail_ipv4_policy+0x1691> */
	X86_SIM_X86_JMP(0x819, 0x1691, x86_l_1691);
x86_l_81e:
	/* 0x81e: mov    r12d,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_823:
	/* 0x823: cmp    DWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_82b:
	/* 0x82b: jne    a76 <tail_ipv4_policy+0xa76> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x82b, 0xa76, x86_l_a76);
x86_l_831:
	/* 0x831: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_833:
	/* 0x833: cmp    DWORD PTR [rsp+0xb4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_83b:
	/* 0x83b: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_83e:
	/* 0x83e: shl    eax,0xa */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 10ULL);
x86_l_841:
	/* 0x841: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_843:
	/* 0x843: test   r12w,r12w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_16);
x86_l_847:
	/* 0x847: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_84a:
	/* 0x84a: shl    ecx,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 6ULL);
x86_l_84d:
	/* 0x84d: cmp    BYTE PTR [r8+0xc],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 51539607558ULL);
x86_l_852:
	/* 0x852: mov    DWORD PTR [rsp+0x30],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_857:
	/* 0x857: jne    88e <tail_ipv4_policy+0x88e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x857, 0x88e, x86_l_88e);
x86_l_859:
	/* 0x859: mov    rdx,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&cilium_ct4_global)));
x86_l_860:
	/* 0x860: jmp    895 <tail_ipv4_policy+0x895> */
	X86_SIM_X86_JMP(0x860, 0x895, x86_l_895);
x86_l_862:
	/* 0x862: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_864:
	/* 0x864: cmp    DWORD PTR [rsp+0xb4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_86c:
	/* 0x86c: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_86f:
	/* 0x86f: shl    eax,0xa */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 10ULL);
x86_l_872:
	/* 0x872: or     eax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 8ULL);
x86_l_875:
	/* 0x875: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_878:
	/* 0x878: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_87b:
	/* 0x87b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_87d:
	/* 0x87d: mov    r14d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_882:
	/* 0x882: cmp    BYTE PTR [r8+0xc],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 51539607558ULL);
x86_l_887:
	/* 0x887: mov    DWORD PTR [rsp+0x30],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_88c:
	/* 0x88c: je     859 <tail_ipv4_policy+0x859> */
	X86_SIM_X86_JCC(X86_CC_E, 0x88c, 0x859, x86_l_859);
x86_l_88e:
	/* 0x88e: mov    rdx,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&cilium_ct_any4_global)));
x86_l_895:
	/* 0x895: mov    QWORD PTR [rsp+0x10],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_89a:
	/* 0x89a: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_8a3:
	/* 0x8a3: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_8ac:
	/* 0x8ac: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_8b5:
	/* 0x8b5: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_8be:
	/* 0x8be: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_8c7:
	/* 0x8c7: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_8d0:
	/* 0x8d0: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_8d9:
	/* 0x8d9: movzx  ebp,BYTE PTR [r8+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 12ULL);
x86_l_8de:
	/* 0x8de: mov    DWORD PTR [rsp+0x64],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 100ULL);
x86_l_8e3:
	/* 0x8e3: mov    WORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_8ea:
	/* 0x8ea: movzx  ecx,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_8ed:
	/* 0x8ed: movzx  eax,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_8f0:
	/* 0x8f0: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_8f9:
	/* 0x8f9: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_902:
	/* 0x902: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_904:
	/* 0x904: mov    WORD PTR [rsp+0x5c],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_909:
	/* 0x909: mov    r12,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_910:
	/* 0x910: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_915:
	/* 0x915: je     928 <tail_ipv4_policy+0x928> */
	X86_SIM_X86_JCC(X86_CC_E, 0x915, 0x928, x86_l_928);
x86_l_917:
	/* 0x917: mov    rcx,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_91e:
	/* 0x91e: imul   r15d,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R15, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_922:
	/* 0x922: shr    r15d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_926:
	/* 0x926: jmp    92e <tail_ipv4_policy+0x92e> */
	X86_SIM_X86_JMP(0x926, 0x92e, x86_l_92e);
x86_l_928:
	/* 0x928: mov    r15d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 60ULL);
x86_l_92e:
	/* 0x92e: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_932:
	/* 0x932: jne    957 <tail_ipv4_policy+0x957> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x932, 0x957, x86_l_957);
x86_l_934:
	/* 0x934: mov    WORD PTR [rsp+0x5c],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_939:
	/* 0x939: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_93e:
	/* 0x93e: je     951 <tail_ipv4_policy+0x951> */
	X86_SIM_X86_JCC(X86_CC_E, 0x93e, 0x951, x86_l_951);
x86_l_940:
	/* 0x940: mov    rax,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_947:
	/* 0x947: imul   r15d,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_94b:
	/* 0x94b: shr    r15d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_94f:
	/* 0x94f: jmp    957 <tail_ipv4_policy+0x957> */
	X86_SIM_X86_JMP(0x94f, 0x957, x86_l_957);
x86_l_951:
	/* 0x951: mov    r15d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 60ULL);
x86_l_957:
	/* 0x957: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_95c:
	/* 0x95c: je     96d <tail_ipv4_policy+0x96d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x95c, 0x96d, x86_l_96d);
x86_l_95e:
	/* 0x95e: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_963:
	/* 0x963: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_965:
	/* 0x965: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_967:
	/* 0x967: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_96b:
	/* 0x96b: jmp    990 <tail_ipv4_policy+0x990> */
	X86_SIM_X86_JMP(0x96b, 0x990, x86_l_990);
x86_l_96d:
	/* 0x96d: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_972:
	/* 0x972: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_974:
	/* 0x974: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_976:
	/* 0x976: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_97a:
	/* 0x97a: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_984:
	/* 0x984: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_987:
	/* 0x987: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_98c:
	/* 0x98c: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_990:
	/* 0x990: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_994:
	/* 0x994: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_997:
	/* 0x997: add    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_99a:
	/* 0x99a: mov    DWORD PTR [rsp+0x58],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_99f:
	/* 0x99f: movzx  edx,BYTE PTR [rsp+0x63] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 99ULL);
x86_l_9a4:
	/* 0x9a4: mov    esi,DWORD PTR [rsp+0x6c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_9a8:
	/* 0x9a8: add    cl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_8, X86_ALU_ADD);
x86_l_9aa:
	/* 0x9aa: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9af:
	/* 0x9af: je     9c2 <tail_ipv4_policy+0x9c2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9af, 0x9c2, x86_l_9c2);
x86_l_9b1:
	/* 0x9b1: mov    rdi,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_9b8:
	/* 0x9b8: mov    edi,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9ba:
	/* 0x9ba: lea    edi,[rdi+rdi*4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_9bd:
	/* 0x9bd: shr    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_9c0:
	/* 0x9c0: jmp    9c7 <tail_ipv4_policy+0x9c7> */
	X86_SIM_X86_JMP(0x9c0, 0x9c7, x86_l_9c7);
x86_l_9c2:
	/* 0x9c2: mov    edi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 5ULL);
x86_l_9c7:
	/* 0x9c7: mov    r12d,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9cc:
	/* 0x9cc: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_9ce:
	/* 0x9ce: or     cl,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_9d0:
	/* 0x9d0: cmp    edi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_9d2:
	/* 0x9d2: jb     9d8 <tail_ipv4_policy+0x9d8> */
	X86_SIM_X86_JCC(X86_CC_B, 0x9d2, 0x9d8, x86_l_9d8);
x86_l_9d4:
	/* 0x9d4: cmp    dl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_8);
x86_l_9d6:
	/* 0x9d6: je     9e9 <tail_ipv4_policy+0x9e9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9d6, 0x9e9, x86_l_9e9);
x86_l_9d8:
	/* 0x9d8: mov    BYTE PTR [rsp+0x63],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 99ULL);
x86_l_9dc:
	/* 0x9dc: mov    DWORD PTR [rsp+0x6c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_9e0:
	/* 0x9e0: mov    rax,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_9e7:
	/* 0x9e7: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9e9:
	/* 0x9e9: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_9ee:
	/* 0x9ee: mov    eax,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9f0:
	/* 0x9f0: mov    DWORD PTR [rsp+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9f4:
	/* 0x9f4: mov    eax,DWORD PTR [rcx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_9f7:
	/* 0x9f7: mov    DWORD PTR [rsp+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_9fb:
	/* 0x9fb: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_a03:
	/* 0xa03: mov    BYTE PTR [rsp+0x2c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 188978561025ULL);
x86_l_a08:
	/* 0xa08: movzx  eax,BYTE PTR [rcx+0xd] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 13ULL);
x86_l_a0c:
	/* 0xa0c: or     al,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_OR, 2ULL);
x86_l_a0e:
	/* 0xa0e: mov    BYTE PTR [rsp+0x2d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 45ULL);
x86_l_a12:
	/* 0xa12: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_a17:
	/* 0xa17: mov    rdi,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct_any4_global)));
x86_l_a1e:
	/* 0xa1e: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a23:
	/* 0xa23: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_a28:
	/* 0xa28: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a2a:
	/* 0xa2a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a2c:
	/* 0xa2c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a2e:
	/* 0xa2e: js     ca3 <tail_ipv4_policy+0xca3> */
	X86_SIM_X86_JCC(X86_CC_S, 0xa2e, 0xca3, x86_l_ca3);
x86_l_a34:
	/* 0xa34: mov    rax,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_a3b:
	/* 0xa3b: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a3e:
	/* 0xa3e: je     a51 <tail_ipv4_policy+0xa51> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa3e, 0xa51, x86_l_a51);
x86_l_a40:
	/* 0xa40: mov    QWORD PTR [rsp+0x48],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645313ULL);
x86_l_a49:
	/* 0xa49: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_a4c:
	/* 0xa4c: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_a51:
	/* 0xa51: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_a56:
	/* 0xa56: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_a5b:
	/* 0xa5b: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a60:
	/* 0xa60: mov    rsi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_a65:
	/* 0xa65: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a67:
	/* 0xa67: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a69:
	/* 0xa69: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a6b:
	/* 0xa6b: js     ca3 <tail_ipv4_policy+0xca3> */
	X86_SIM_X86_JCC(X86_CC_S, 0xa6b, 0xca3, x86_l_ca3);
x86_l_a71:
	/* 0xa71: mov    r8,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_a76:
	/* 0xa76: test   r12w,r12w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_16);
x86_l_a7a:
	/* 0xa7a: je     1334 <tail_ipv4_policy+0x1334> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa7a, 0x1334, x86_l_1334);
x86_l_a80:
	/* 0xa80: mov    rax,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_security_label)));
x86_l_a87:
	/* 0xa87: mov    r15d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a8a:
	/* 0xa8a: mov    rax,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_tracing_ip_option_type)));
x86_l_a91:
	/* 0xa91: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a94:
	/* 0xa94: je     abb <tail_ipv4_policy+0xabb> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa94, 0xabb, x86_l_abb);
x86_l_a96:
	/* 0xa96: mov    DWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_a9e:
	/* 0xa9e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_aa3:
	/* 0xaa3: mov    rdi,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_percpu_trace_id)));
x86_l_aaa:
	/* 0xaaa: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_aaf:
	/* 0xaaf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ab1:
	/* 0xab1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ab4:
	/* 0xab4: je     ac0 <tail_ipv4_policy+0xac0> */
	X86_SIM_X86_JCC(X86_CC_E, 0xab4, 0xac0, x86_l_ac0);
x86_l_ab6:
	/* 0xab6: mov    r9,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ab9:
	/* 0xab9: jmp    ac3 <tail_ipv4_policy+0xac3> */
	X86_SIM_X86_JMP(0xab9, 0xac3, x86_l_ac3);
x86_l_abb:
	/* 0xabb: xor    r9d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R9, X86_WIDTH_32, X86_ALU_XOR);
x86_l_abe:
	/* 0xabe: jmp    ac8 <tail_ipv4_policy+0xac8> */
	X86_SIM_X86_JMP(0xabe, 0xac8, x86_l_ac8);
x86_l_ac0:
	/* 0xac0: xor    r9d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R9, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ac3:
	/* 0xac3: mov    r8,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ac8:
	/* 0xac8: mov    ebp,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_acb:
	/* 0xacb: mov    QWORD PTR [rsp+0xa8],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505730ULL);
x86_l_ad7:
	/* 0xad7: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_ae0:
	/* 0xae0: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_ae9:
	/* 0xae9: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_af2:
	/* 0xaf2: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_afb:
	/* 0xafb: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_b04:
	/* 0xb04: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_b0d:
	/* 0xb0d: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_b16:
	/* 0xb16: cmp    DWORD PTR [rsp+0xb0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_b1e:
	/* 0xb1e: je     d96 <tail_ipv4_policy+0xd96> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb1e, 0xd96, x86_l_d96);
x86_l_b24:
	/* 0xb24: mov    rax,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_events_map_rate_limit)));
x86_l_b2b:
	/* 0xb2b: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b2e:
	/* 0xb2e: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_b30:
	/* 0xb30: je     cda <tail_ipv4_policy+0xcda> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb30, 0xcda, x86_l_cda);
x86_l_b36:
	/* 0xb36: mov    QWORD PTR [rsp+0xc8],r9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_b3e:
	/* 0xb3e: mov    DWORD PTR [rsp+0x10],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b43:
	/* 0xb43: mov    DWORD PTR [rsp+0x30],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_b48:
	/* 0xb48: mov    rcx,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_events_map_burst_limit)));
x86_l_b4f:
	/* 0xb4f: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b51:
	/* 0xb51: mov    QWORD PTR [rsp+0x90],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_b59:
	/* 0xb59: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b5b:
	/* 0xb5b: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_b63:
	/* 0xb63: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_b68:
	/* 0xb68: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b6a:
	/* 0xb6a: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_b6c:
	/* 0xb6c: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_b6f:
	/* 0xb6f: mov    eax,DWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_b76:
	/* 0xb76: mov    DWORD PTR [rsp+0x8c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_b7d:
	/* 0xb7d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b82:
	/* 0xb82: mov    rdi,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit_metrics)));
x86_l_b89:
	/* 0xb89: lea    rsi,[rsp+0x8c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_b91:
	/* 0xb91: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b93:
	/* 0xb93: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_b96:
	/* 0xb96: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b99:
	/* 0xb99: jne    bcc <tail_ipv4_policy+0xbcc> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb99, 0xbcc, x86_l_bcc);
x86_l_b9b:
	/* 0xb9b: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_ba4:
	/* 0xba4: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_ba9:
	/* 0xba9: mov    rdi,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit_metrics)));
x86_l_bb0:
	/* 0xbb0: lea    rsi,[rsp+0x8c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_bb8:
	/* 0xbb8: lea    r15,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_bbd:
	/* 0xbbd: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_bc0:
	/* 0xbc0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bc2:
	/* 0xbc2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bc4:
	/* 0xbc4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_bc6:
	/* 0xbc6: js     f0c <tail_ipv4_policy+0xf0c> */
	X86_SIM_X86_JCC(X86_CC_S, 0xbc6, 0xf0c, x86_l_f0c);
x86_l_bcc:
	/* 0xbcc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_bd1:
	/* 0xbd1: mov    rdi,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit)));
x86_l_bd8:
	/* 0xbd8: lea    rsi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_be0:
	/* 0xbe0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_be2:
	/* 0xbe2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_be5:
	/* 0xbe5: je     c5b <tail_ipv4_policy+0xc5b> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbe5, 0xc5b, x86_l_c5b);
x86_l_be7:
	/* 0xbe7: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bea:
	/* 0xbea: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_bed:
	/* 0xbed: sub    rsi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_bf0:
	/* 0xbf0: cmp    rsi,0x3b9aca00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 1000000000ULL);
x86_l_bf7:
	/* 0xbf7: jbe    cb1 <tail_ipv4_policy+0xcb1> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xbf7, 0xcb1, x86_l_cb1);
x86_l_bfd:
	/* 0xbfd: mov    rdx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_c00:
	/* 0xc00: shr    rdx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_c04:
	/* 0xc04: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_c0e:
	/* 0xc0e: mulx   rcx,rcx,rcx */
	X86_SIM_L_EXEC_MULX(X86_RCX, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_c13:
	/* 0xc13: shr    rcx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_c17:
	/* 0xc17: imul   rdx,rcx,0x3b9aca00 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RDX, X86_RCX, X86_WIDTH_64, 1000000000ULL);
x86_l_c1e:
	/* 0xc1e: imul   rcx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 128ULL);
x86_l_c27:
	/* 0xc27: add    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_c2b:
	/* 0xc2b: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c2f:
	/* 0xc2f: sub    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_c32:
	/* 0xc32: add    r12,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_c35:
	/* 0xc35: mov    QWORD PTR [rax],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c38:
	/* 0xc38: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_c40:
	/* 0xc40: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_c43:
	/* 0xc43: mov    r12d,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c48:
	/* 0xc48: mov    r9,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_c50:
	/* 0xc50: jbe    cc2 <tail_ipv4_policy+0xcc2> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xc50, 0xcc2, x86_l_cc2);
x86_l_c52:
	/* 0xc52: mov    QWORD PTR [rax+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c56:
	/* 0xc56: mov    rcx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_c59:
	/* 0xc59: jmp    cc2 <tail_ipv4_policy+0xcc2> */
	X86_SIM_X86_JMP(0xc59, 0xcc2, x86_l_cc2);
x86_l_c5b:
	/* 0xc5b: mov    QWORD PTR [rsp+0x20],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c60:
	/* 0xc60: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_c68:
	/* 0xc68: dec    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_c6b:
	/* 0xc6b: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c70:
	/* 0xc70: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_c75:
	/* 0xc75: mov    rdi,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit)));
x86_l_c7c:
	/* 0xc7c: lea    rsi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_c84:
	/* 0xc84: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c89:
	/* 0xc89: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c8b:
	/* 0xc8b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c8d:
	/* 0xc8d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c8f:
	/* 0xc8f: mov    r12d,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c94:
	/* 0xc94: mov    r9,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_c9c:
	/* 0xc9c: jns    cd2 <tail_ipv4_policy+0xcd2> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xc9c, 0xcd2, x86_l_cd2);
x86_l_c9e:
	/* 0xc9e: jmp    f09 <tail_ipv4_policy+0xf09> */
	X86_SIM_X86_JMP(0xc9e, 0xf09, x86_l_f09);
x86_l_ca3:
	/* 0xca3: mov    r13d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_ca6:
	/* 0xca6: mov    r15d,0xffffff65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967141ULL);
x86_l_cac:
	/* 0xcac: jmp    1722 <tail_ipv4_policy+0x1722> */
	X86_SIM_X86_JMP(0xcac, 0x1722, x86_l_1722);
x86_l_cb1:
	/* 0xcb1: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cb5:
	/* 0xcb5: mov    r12d,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_cba:
	/* 0xcba: mov    r9,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_cc2:
	/* 0xcc2: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_cc5:
	/* 0xcc5: je     f09 <tail_ipv4_policy+0xf09> */
	X86_SIM_X86_JCC(X86_CC_E, 0xcc5, 0xf09, x86_l_f09);
x86_l_ccb:
	/* 0xccb: dec    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_cce:
	/* 0xcce: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cd2:
	/* 0xcd2: mov    ecx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_cd5:
	/* 0xcd5: mov    r15d,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_cda:
	/* 0xcda: mov    edx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_32);
x86_l_cdd:
	/* 0xcdd: rol    dx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_ce1:
	/* 0xce1: mov    rsi,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_ce8:
	/* 0xce8: mov    eax,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cea:
	/* 0xcea: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cec:
	/* 0xcec: mov    edi,DWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_cf3:
	/* 0xcf3: cmp    esi,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDI, X86_WIDTH_32);
x86_l_cf5:
	/* 0xcf5: cmovne eax,edi */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RDI, X86_WIDTH_32, X86_CC_NE);
x86_l_cf8:
	/* 0xcf8: cmp    eax,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_cfa:
	/* 0xcfa: mov    rsi,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_endpoint_id)));
x86_l_d01:
	/* 0xd01: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_d04:
	/* 0xd04: cmovae eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_AE);
x86_l_d07:
	/* 0xd07: mov    ecx,DWORD PTR [rbx+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_d0d:
	/* 0xd0d: mov    WORD PTR [rsp+0x38],0x104 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 240518168836ULL);
x86_l_d14:
	/* 0xd14: mov    WORD PTR [rsp+0x3a],si */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_d19:
	/* 0xd19: mov    DWORD PTR [rsp+0x3c],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_d1d:
	/* 0xd1d: mov    DWORD PTR [rsp+0x40],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_d21:
	/* 0xd21: mov    WORD PTR [rsp+0x44],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_d26:
	/* 0xd26: mov    WORD PTR [rsp+0x46],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 300647710722ULL);
x86_l_d2d:
	/* 0xd2d: mov    DWORD PTR [rsp+0x48],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_d32:
	/* 0xd32: mov    DWORD PTR [rsp+0x4c],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_d37:
	/* 0xd37: mov    WORD PTR [rsp+0x50],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_d3c:
	/* 0xd3c: mov    ecx,DWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_d43:
	/* 0xd43: mov    BYTE PTR [rsp+0x52],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 82ULL);
x86_l_d47:
	/* 0xd47: mov    BYTE PTR [rsp+0x53],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 356482285568ULL);
x86_l_d4c:
	/* 0xd4c: mov    ecx,DWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_d53:
	/* 0xd53: mov    DWORD PTR [rsp+0x54],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_d57:
	/* 0xd57: mov    ecx,DWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_d5e:
	/* 0xd5e: mov    DWORD PTR [rsp+0x58],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_d62:
	/* 0xd62: mov    QWORD PTR [rsp+0x68],r9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_d67:
	/* 0xd67: mov    r9d,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 25ULL);
x86_l_d6d:
	/* 0xd6d: shl    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_d71:
	/* 0xd71: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_d76:
	/* 0xd76: or     rdx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_d79:
	/* 0xd79: mov    rsi,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_events)));
x86_l_d80:
	/* 0xd80: lea    rcx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_d85:
	/* 0xd85: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_d88:
	/* 0xd88: mov    r8d,0x38 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 56ULL);
x86_l_d8e:
	/* 0xd8e: call   r9 */
	X86_SIM_BPF_CALL_REG(X86_R9);
x86_l_d91:
	/* 0xd91: mov    r8,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d96:
	/* 0xd96: mov    rax,QWORD PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d99:
	/* 0xd99: mov    rcx,QWORD PTR [r8+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_d9d:
	/* 0xd9d: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_da5:
	/* 0xda5: mov    QWORD PTR [rsp+0x9e],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 158ULL);
x86_l_dad:
	/* 0xdad: cmp    DWORD PTR [rsp+0xb4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_db5:
	/* 0xdb5: je     dc3 <tail_ipv4_policy+0xdc3> */
	X86_SIM_X86_JCC(X86_CC_E, 0xdb5, 0xdc3, x86_l_dc3);
x86_l_db7:
	/* 0xdb7: mov    eax,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_dbc:
	/* 0xdbc: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_dbf:
	/* 0xdbf: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_dc1:
	/* 0xdc1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dc3:
	/* 0xdc3: mov    rax,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_tproxy)));
x86_l_dca:
	/* 0xdca: movzx  ecx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_dcd:
	/* 0xdcd: cmp    DWORD PTR [rsp+0xc4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 841813590016ULL);
x86_l_dd5:
	/* 0xdd5: jne    de4 <tail_ipv4_policy+0xde4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xdd5, 0xde4, x86_l_de4);
x86_l_dd7:
	/* 0xdd7: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_dd9:
	/* 0xdd9: je     de4 <tail_ipv4_policy+0xde4> */
	X86_SIM_X86_JCC(X86_CC_E, 0xdd9, 0xde4, x86_l_de4);
x86_l_ddb:
	/* 0xddb: or     BYTE PTR [rbx+0xa9],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RBX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 725849473026ULL);
x86_l_de2:
	/* 0xde2: jmp    df6 <tail_ipv4_policy+0xdf6> */
	X86_SIM_X86_JMP(0xde2, 0xdf6, x86_l_df6);
x86_l_de4:
	/* 0xde4: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_de7:
	/* 0xde7: shl    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_dea:
	/* 0xdea: or     ecx,0x200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_OR, 512ULL);
x86_l_df0:
	/* 0xdf0: mov    DWORD PTR [rbx+0xa8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_df6:
	/* 0xdf6: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_df9:
	/* 0xdf9: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_dfc:
	/* 0xdfc: cmp    DWORD PTR [rsp+0xc4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 841813590016ULL);
x86_l_e04:
	/* 0xe04: jne    10c3 <tail_ipv4_policy+0x10c3> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe04, 0x10c3, x86_l_10c3);
x86_l_e0a:
	/* 0xe0a: test   r12w,r12w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_16);
x86_l_e0e:
	/* 0xe0e: je     10c3 <tail_ipv4_policy+0x10c3> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe0e, 0x10c3, x86_l_10c3);
x86_l_e14:
	/* 0xe14: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_e16:
	/* 0xe16: je     10c3 <tail_ipv4_policy+0x10c3> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe16, 0x10c3, x86_l_10c3);
x86_l_e1c:
	/* 0xe1c: movzx  ebp,BYTE PTR [rsp+0xa4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 164ULL);
x86_l_e24:
	/* 0xe24: rol    DWORD PTR [rsp+0xa0],0x10 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_32, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_ROL)), 687194767376ULL);
x86_l_e2c:
	/* 0xe2c: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_e2f:
	/* 0xe2f: jne    e80 <tail_ipv4_policy+0xe80> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe2f, 0xe80, x86_l_e80);
x86_l_e31:
	/* 0xe31: mov    eax,0x63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 99ULL);
x86_l_e36:
	/* 0xe36: lea    rsi,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_e3e:
	/* 0xe3e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_e41:
	/* 0xe41: mov    edx,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_e46:
	/* 0xe46: mov    rcx,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_e4d:
	/* 0xe4d: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e50:
	/* 0xe50: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e52:
	/* 0xe52: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_e57:
	/* 0xe57: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e5a:
	/* 0xe5a: je     f51 <tail_ipv4_policy+0xf51> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe5a, 0xf51, x86_l_f51);
x86_l_e60:
	/* 0xe60: mov    ecx,DWORD PTR [rax+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_e63:
	/* 0xe63: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_e66:
	/* 0xe66: je     e71 <tail_ipv4_policy+0xe71> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe66, 0xe71, x86_l_e71);
x86_l_e68:
	/* 0xe68: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_e6b:
	/* 0xe6b: jne    f1b <tail_ipv4_policy+0xf1b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe6b, 0xf1b, x86_l_f1b);
x86_l_e71:
	/* 0xe71: mov    ecx,0x56 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 86ULL);
x86_l_e76:
	/* 0xe76: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_e79:
	/* 0xe79: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_e7b:
	/* 0xe7b: jmp    f51 <tail_ipv4_policy+0xf51> */
	X86_SIM_X86_JMP(0xe7b, 0xf51, x86_l_f51);
x86_l_e80:
	/* 0xe80: mov    WORD PTR [rsp+0xa2],r12w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 162ULL);
x86_l_e89:
	/* 0xe89: mov    WORD PTR [rsp+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_e93:
	/* 0xe93: movabs rax,0x100007f00000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 72058139498774528ULL);
x86_l_e9d:
	/* 0xe9d: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_ea5:
	/* 0xea5: cmp    ebp,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 17ULL);
x86_l_ea8:
	/* 0xea8: jne    feb <tail_ipv4_policy+0xfeb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xea8, 0xfeb, x86_l_feb);
x86_l_eae:
	/* 0xeae: mov    eax,0x55 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 85ULL);
x86_l_eb3:
	/* 0xeb3: lea    rsi,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_ebb:
	/* 0xebb: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_ebe:
	/* 0xebe: mov    edx,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_ec3:
	/* 0xec3: mov    rcx,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_eca:
	/* 0xeca: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ecd:
	/* 0xecd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ecf:
	/* 0xecf: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_ed4:
	/* 0xed4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ed7:
	/* 0xed7: je     fd1 <tail_ipv4_policy+0xfd1> */
	X86_SIM_X86_JCC(X86_CC_E, 0xed7, 0xfd1, x86_l_fd1);
x86_l_edd:
	/* 0xedd: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_ee2:
	/* 0xee2: mov    eax,0x7c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 124ULL);
x86_l_ee7:
	/* 0xee7: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_eec:
	/* 0xeec: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_eef:
	/* 0xeef: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ef1:
	/* 0xef1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ef3:
	/* 0xef3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ef5:
	/* 0xef5: mov    r14d,0xffffff4d */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4294967117ULL);
x86_l_efb:
	/* 0xefb: cmove  r14d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R14, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_eff:
	/* 0xeff: mov    eax,0x56 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 86ULL);
x86_l_f04:
	/* 0xf04: jmp    fc8 <tail_ipv4_policy+0xfc8> */
	X86_SIM_X86_JMP(0xf04, 0xfc8, x86_l_fc8);
x86_l_f09:
	/* 0xf09: inc    QWORD PTR [r15] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_f0c:
	/* 0xf0c: mov    r8,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_f11:
	/* 0xf11: mov    r12d,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f16:
	/* 0xf16: jmp    d96 <tail_ipv4_policy+0xd96> */
	X86_SIM_X86_JMP(0xf16, 0xd96, x86_l_d96);
x86_l_f1b:
	/* 0xf1b: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_f20:
	/* 0xf20: mov    eax,0x7c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 124ULL);
x86_l_f25:
	/* 0xf25: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_f2a:
	/* 0xf2a: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f2d:
	/* 0xf2d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_f30:
	/* 0xf30: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f32:
	/* 0xf32: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f34:
	/* 0xf34: mov    r14d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_32);
x86_l_f37:
	/* 0xf37: mov    eax,0x56 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 86ULL);
x86_l_f3c:
	/* 0xf3c: mov    rdi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_f41:
	/* 0xf41: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f43:
	/* 0xf43: test   r14d,r14d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_32);
x86_l_f46:
	/* 0xf46: mov    r14d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f4b:
	/* 0xf4b: je     10c3 <tail_ipv4_policy+0x10c3> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf4b, 0x10c3, x86_l_10c3);
x86_l_f51:
	/* 0xf51: mov    WORD PTR [rsp+0xa2],r12w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 162ULL);
x86_l_f5a:
	/* 0xf5a: mov    WORD PTR [rsp+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_f64:
	/* 0xf64: movabs rax,0x100007f00000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 72058139498774528ULL);
x86_l_f6e:
	/* 0xf6e: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_f76:
	/* 0xf76: mov    eax,0x63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 99ULL);
x86_l_f7b:
	/* 0xf7b: lea    rsi,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_f83:
	/* 0xf83: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_f86:
	/* 0xf86: mov    edx,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_f8b:
	/* 0xf8b: mov    rcx,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_f92:
	/* 0xf92: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f95:
	/* 0xf95: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f97:
	/* 0xf97: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_f9c:
	/* 0xf9c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f9f:
	/* 0xf9f: je     fd1 <tail_ipv4_policy+0xfd1> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf9f, 0xfd1, x86_l_fd1);
x86_l_fa1:
	/* 0xfa1: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_fa6:
	/* 0xfa6: mov    eax,0x7c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 124ULL);
x86_l_fab:
	/* 0xfab: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_fb0:
	/* 0xfb0: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_fb3:
	/* 0xfb3: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_fb5:
	/* 0xfb5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fb7:
	/* 0xfb7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_fb9:
	/* 0xfb9: mov    r14d,0xffffff4d */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4294967117ULL);
x86_l_fbf:
	/* 0xfbf: cmove  r14d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R14, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_fc3:
	/* 0xfc3: mov    eax,0x56 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 86ULL);
x86_l_fc8:
	/* 0xfc8: mov    rdi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_fcd:
	/* 0xfcd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fcf:
	/* 0xfcf: jmp    fd7 <tail_ipv4_policy+0xfd7> */
	X86_SIM_X86_JMP(0xfcf, 0xfd7, x86_l_fd7);
x86_l_fd1:
	/* 0xfd1: mov    r14d,0xffffff4e */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4294967118ULL);
x86_l_fd7:
	/* 0xfd7: mov    r15d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 0ULL);
x86_l_fdd:
	/* 0xfdd: test   r14d,r14d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_32);
x86_l_fe0:
	/* 0xfe0: mov    r14d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fe5:
	/* 0xfe5: je     10c3 <tail_ipv4_policy+0x10c3> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfe5, 0x10c3, x86_l_10c3);
x86_l_feb:
	/* 0xfeb: mov    DWORD PTR [rsp+0x9c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 670014898176ULL);
x86_l_ff6:
	/* 0xff6: cmp    ebp,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 17ULL);
x86_l_ff9:
	/* 0xff9: je     1062 <tail_ipv4_policy+0x1062> */
	X86_SIM_X86_JCC(X86_CC_E, 0xff9, 0x1062, x86_l_1062);
x86_l_ffb:
	/* 0xffb: mov    r15d,0xffffff4c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967116ULL);
x86_l_1001:
	/* 0x1001: cmp    ebp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_1004:
	/* 0x1004: jne    10c3 <tail_ipv4_policy+0x10c3> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1004, 0x10c3, x86_l_10c3);
x86_l_100a:
	/* 0x100a: mov    eax,0x63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 99ULL);
x86_l_100f:
	/* 0x100f: lea    rsi,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1017:
	/* 0x1017: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_101a:
	/* 0x101a: mov    edx,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_101f:
	/* 0x101f: mov    rcx,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1026:
	/* 0x1026: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1029:
	/* 0x1029: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_102b:
	/* 0x102b: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1030:
	/* 0x1030: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1033:
	/* 0x1033: je     10bd <tail_ipv4_policy+0x10bd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1033, 0x10bd, x86_l_10bd);
x86_l_1039:
	/* 0x1039: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_103e:
	/* 0x103e: mov    eax,0x7c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 124ULL);
x86_l_1043:
	/* 0x1043: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1048:
	/* 0x1048: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_104b:
	/* 0x104b: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_104d:
	/* 0x104d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_104f:
	/* 0x104f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1051:
	/* 0x1051: mov    r15d,0xffffff4d */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967117ULL);
x86_l_1057:
	/* 0x1057: cmove  r15d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R15, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_105b:
	/* 0x105b: mov    eax,0x56 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 86ULL);
x86_l_1060:
	/* 0x1060: jmp    10b4 <tail_ipv4_policy+0x10b4> */
	X86_SIM_X86_JMP(0x1060, 0x10b4, x86_l_10b4);
x86_l_1062:
	/* 0x1062: mov    eax,0x55 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 85ULL);
x86_l_1067:
	/* 0x1067: lea    rsi,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_106f:
	/* 0x106f: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1072:
	/* 0x1072: mov    edx,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_1077:
	/* 0x1077: mov    rcx,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_107e:
	/* 0x107e: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1081:
	/* 0x1081: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1083:
	/* 0x1083: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1088:
	/* 0x1088: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_108b:
	/* 0x108b: je     10bd <tail_ipv4_policy+0x10bd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x108b, 0x10bd, x86_l_10bd);
x86_l_108d:
	/* 0x108d: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1092:
	/* 0x1092: mov    eax,0x7c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 124ULL);
x86_l_1097:
	/* 0x1097: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_109c:
	/* 0x109c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_109f:
	/* 0x109f: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10a1:
	/* 0x10a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10a3:
	/* 0x10a3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_10a5:
	/* 0x10a5: mov    r15d,0xffffff4d */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967117ULL);
x86_l_10ab:
	/* 0x10ab: cmove  r15d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R15, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_10af:
	/* 0x10af: mov    eax,0x56 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 86ULL);
x86_l_10b4:
	/* 0x10b4: mov    rdi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_10b9:
	/* 0x10b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10bb:
	/* 0x10bb: jmp    10c3 <tail_ipv4_policy+0x10c3> */
	X86_SIM_X86_JMP(0x10bb, 0x10c3, x86_l_10c3);
x86_l_10bd:
	/* 0x10bd: mov    r15d,0xffffff4e */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967118ULL);
x86_l_10c3:
	/* 0x10c3: mov    eax,DWORD PTR [rbx+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_10c9:
	/* 0x10c9: mov    DWORD PTR [rbx+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_10cc:
	/* 0x10cc: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_10cf:
	/* 0x10cf: jns    1708 <tail_ipv4_policy+0x1708> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x10cf, 0x1708, x86_l_1708);
x86_l_10d5:
	/* 0x10d5: jmp    1722 <tail_ipv4_policy+0x1722> */
	X86_SIM_X86_JMP(0x10d5, 0x1722, x86_l_1722);
x86_l_10da:
	/* 0x10da: mov    rax,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_10e2:
	/* 0x10e2: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_10e5:
	/* 0x10e5: jmp    801 <tail_ipv4_policy+0x801> */
	X86_SIM_X86_JMP(0x10e5, 0x801, x86_l_801);
x86_l_10ea:
	/* 0x10ea: mov    QWORD PTR [rsp+0x30],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_10ef:
	/* 0x10ef: test   r15b,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R15, X86_WIDTH_8, 1ULL);
x86_l_10f3:
	/* 0x10f3: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_10f6:
	/* 0x10f6: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_10f9:
	/* 0x10f9: je     120b <tail_ipv4_policy+0x120b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10f9, 0x120b, x86_l_120b);
x86_l_10ff:
	/* 0x10ff: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1104:
	/* 0x1104: mov    edx,DWORD PTR [rdx+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1107:
	/* 0x1107: jmp    1119 <tail_ipv4_policy+0x1119> */
	X86_SIM_X86_JMP(0x1107, 0x1119, x86_l_1119);
x86_l_1109:
	/* 0x1109: mov    QWORD PTR [rsp+0x30],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_110e:
	/* 0x110e: mov    edx,DWORD PTR [r8+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1112:
	/* 0x1112: test   r15b,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R15, X86_WIDTH_8, 1ULL);
x86_l_1116:
	/* 0x1116: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_1119:
	/* 0x1119: lea    r12,[rsp+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_111e:
	/* 0x111e: mov    DWORD PTR [rsp+0x38],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1122:
	/* 0x1122: mov    WORD PTR [rsp+0x3c],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_1127:
	/* 0x1127: mov    rsi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_112c:
	/* 0x112c: mov    eax,DWORD PTR [rsi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_112f:
	/* 0x112f: mov    DWORD PTR [rsp+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1133:
	/* 0x1133: mov    rax,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_113a:
	/* 0x113a: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_113d:
	/* 0x113d: mov    DWORD PTR [rsi+0x4],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1140:
	/* 0x1140: lea    r14,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1145:
	/* 0x1145: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_1147:
	/* 0x1147: je     1267 <tail_ipv4_policy+0x1267> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1147, 0x1267, x86_l_1267);
x86_l_114d:
	/* 0x114d: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_114f:
	/* 0x114f: jmp    12be <tail_ipv4_policy+0x12be> */
	X86_SIM_X86_JMP(0x114f, 0x12be, x86_l_12be);
x86_l_1154:
	/* 0x1154: mov    DWORD PTR [rsp+0x74],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 498216206336ULL);
x86_l_115c:
	/* 0x115c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1161:
	/* 0x1161: mov    rdi,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_policy_v2)));
x86_l_1168:
	/* 0x1168: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_116d:
	/* 0x116d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_116f:
	/* 0x116f: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1174:
	/* 0x1174: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1177:
	/* 0x1177: je     182a <tail_ipv4_policy+0x182a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1177, 0x182a, x86_l_182a);
x86_l_117d:
	/* 0x117d: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_1180:
	/* 0x1180: je     1194 <tail_ipv4_policy+0x1194> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1180, 0x1194, x86_l_1194);
x86_l_1182:
	/* 0x1182: mov    eax,DWORD PTR [r15+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1186:
	/* 0x1186: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_118b:
	/* 0x118b: cmp    DWORD PTR [rcx+0x4],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_118e:
	/* 0x118e: jbe    1841 <tail_ipv4_policy+0x1841> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x118e, 0x1841, x86_l_1841);
x86_l_1194:
	/* 0x1194: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1199:
	/* 0x1199: movzx  ebp,WORD PTR [rax+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_119d:
	/* 0x119d: mov    rax,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_policy_accounting)));
x86_l_11a4:
	/* 0x11a4: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11a7:
	/* 0x11a7: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_11a9:
	/* 0x11a9: je     1a10 <tail_ipv4_policy+0x1a10> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11a9, 0x1a10, x86_l_1a10);
x86_l_11af:
	/* 0x11af: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_11b1:
	/* 0x11b1: shr    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHR, 3ULL);
x86_l_11b4:
	/* 0x11b4: movzx  ecx,BYTE PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 120ULL);
x86_l_11b9:
	/* 0x11b9: mov    r12d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_11bd:
	/* 0x11bd: mov    rdx,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_endpoint_id)));
x86_l_11c4:
	/* 0x11c4: movzx  edx,WORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_11c7:
	/* 0x11c7: mov    WORD PTR [rsp+0x20],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_11cc:
	/* 0x11cc: mov    BYTE PTR [rsp+0x22],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 146028888064ULL);
x86_l_11d1:
	/* 0x11d1: mov    BYTE PTR [rsp+0x23],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 35ULL);
x86_l_11d5:
	/* 0x11d5: and    cl,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 1ULL);
x86_l_11d8:
	/* 0x11d8: mov    DWORD PTR [rsp+0x24],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 154618822656ULL);
x86_l_11e0:
	/* 0x11e0: mov    BYTE PTR [rsp+0x28],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_11e4:
	/* 0x11e4: cmp    bpl,0x47 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 71ULL);
x86_l_11e8:
	/* 0x11e8: ja     188b <tail_ipv4_policy+0x188b> */
	X86_SIM_X86_JCC(X86_CC_A, 0x11e8, 0x188b, x86_l_188b);
x86_l_11ee:
	/* 0x11ee: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_11f1:
	/* 0x11f1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11f3:
	/* 0x11f3: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_11f6:
	/* 0x11f6: movzx  r13d,r13b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R13, X86_R13, X86_WIDTH_32, X86_WIDTH_8);
x86_l_11fa:
	/* 0x11fa: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1202:
	/* 0x1202: cmovne r13d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RCX, X86_WIDTH_32, X86_CC_NE);
x86_l_1206:
	/* 0x1206: jmp    18a7 <tail_ipv4_policy+0x18a7> */
	X86_SIM_X86_JMP(0x1206, 0x18a7, x86_l_18a7);
x86_l_120b:
	/* 0x120b: mov    WORD PTR [rsp+0x20],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1210:
	/* 0x1210: mov    rax,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_1217:
	/* 0x1217: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_121a:
	/* 0x121a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_121f:
	/* 0x121f: mov    rdi,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_reverse_nat)));
x86_l_1226:
	/* 0x1226: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_122b:
	/* 0x122b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_122d:
	/* 0x122d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1230:
	/* 0x1230: je     132c <tail_ipv4_policy+0x132c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1230, 0x132c, x86_l_132c);
x86_l_1236:
	/* 0x1236: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_1239:
	/* 0x1239: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_123c:
	/* 0x123c: mov    r12,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R14, X86_WIDTH_64);
x86_l_123f:
	/* 0x123f: add    r12,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1243:
	/* 0x1243: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1248:
	/* 0x1248: mov    eax,DWORD PTR [rcx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_124b:
	/* 0x124b: mov    DWORD PTR [rsp+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_124f:
	/* 0x124f: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1251:
	/* 0x1251: mov    rax,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_1258:
	/* 0x1258: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_125b:
	/* 0x125b: mov    eax,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_125e:
	/* 0x125e: mov    DWORD PTR [rcx+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1261:
	/* 0x1261: test   r15b,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R15, X86_WIDTH_8, 1ULL);
x86_l_1265:
	/* 0x1265: je     12be <tail_ipv4_policy+0x12be> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1265, 0x12be, x86_l_12be);
x86_l_1267:
	/* 0x1267: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_126c:
	/* 0x126c: mov    ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_126e:
	/* 0x126e: mov    rax,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_1275:
	/* 0x1275: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1278:
	/* 0x1278: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_127d:
	/* 0x127d: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1282:
	/* 0x1282: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1285:
	/* 0x1285: mov    esi,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 30ULL);
x86_l_128a:
	/* 0x128a: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_128f:
	/* 0x128f: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1292:
	/* 0x1292: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1294:
	/* 0x1294: mov    r15d,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967155ULL);
x86_l_129a:
	/* 0x129a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_129c:
	/* 0x129c: js     171a <tail_ipv4_policy+0x171a> */
	X86_SIM_X86_JCC(X86_CC_S, 0x129c, 0x171a, x86_l_171a);
x86_l_12a2:
	/* 0x12a2: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_12a5:
	/* 0x12a5: je     171a <tail_ipv4_policy+0x171a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12a5, 0x171a, x86_l_171a);
x86_l_12ab:
	/* 0x12ab: not    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_12ad:
	/* 0x12ad: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_12b1:
	/* 0x12b1: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_12b3:
	/* 0x12b3: adc    ebp,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_12b6:
	/* 0x12b6: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_12bb:
	/* 0x12bb: mov    DWORD PTR [rcx+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_12be:
	/* 0x12be: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_12c3:
	/* 0x12c3: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_12c6:
	/* 0x12c6: mov    esi,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 26ULL);
x86_l_12cb:
	/* 0x12cb: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_12ce:
	/* 0x12ce: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_12d3:
	/* 0x12d3: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12d6:
	/* 0x12d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12d8:
	/* 0x12d8: mov    r15d,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967155ULL);
x86_l_12de:
	/* 0x12de: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_12e0:
	/* 0x12e0: js     171a <tail_ipv4_policy+0x171a> */
	X86_SIM_X86_JCC(X86_CC_S, 0x12e0, 0x171a, x86_l_171a);
x86_l_12e6:
	/* 0x12e6: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_12e9:
	/* 0x12e9: je     171a <tail_ipv4_policy+0x171a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12e9, 0x171a, x86_l_171a);
x86_l_12ef:
	/* 0x12ef: mov    ecx,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_12f3:
	/* 0x12f3: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_12f5:
	/* 0x12f5: add    ecx,DWORD PTR [r14] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_12f8:
	/* 0x12f8: adc    ecx,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_12fb:
	/* 0x12fb: add    ecx,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_12fd:
	/* 0x12fd: adc    ecx,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_1300:
	/* 0x1300: mov    eax,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_1305:
	/* 0x1305: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1308:
	/* 0x1308: mov    esi,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 24ULL);
x86_l_130d:
	/* 0x130d: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_130f:
	/* 0x130f: mov    r14d,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RCX, X86_WIDTH_32);
x86_l_1312:
	/* 0x1312: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1315:
	/* 0x1315: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1317:
	/* 0x1317: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1319:
	/* 0x1319: js     1714 <tail_ipv4_policy+0x1714> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1319, 0x1714, x86_l_1714);
x86_l_131f:
	/* 0x131f: test   r13d,0xff1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R13, X86_WIDTH_32, 65311ULL);
x86_l_1326:
	/* 0x1326: je     17f9 <tail_ipv4_policy+0x17f9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1326, 0x17f9, x86_l_17f9);
x86_l_132c:
	/* 0x132c: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_132f:
	/* 0x132f: mov    r14d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1334:
	/* 0x1334: mov    rax,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_security_label)));
x86_l_133b:
	/* 0x133b: mov    r12d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_133e:
	/* 0x133e: mov    rax,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_endpoint_id)));
x86_l_1345:
	/* 0x1345: movzx  eax,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1348:
	/* 0x1348: mov    WORD PTR [rsp+0x18],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_134d:
	/* 0x134d: mov    rax,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_tracing_ip_option_type)));
x86_l_1354:
	/* 0x1354: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1357:
	/* 0x1357: je     137e <tail_ipv4_policy+0x137e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1357, 0x137e, x86_l_137e);
x86_l_1359:
	/* 0x1359: mov    DWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1361:
	/* 0x1361: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1366:
	/* 0x1366: mov    rdi,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_percpu_trace_id)));
x86_l_136d:
	/* 0x136d: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1372:
	/* 0x1372: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1374:
	/* 0x1374: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1377:
	/* 0x1377: je     137e <tail_ipv4_policy+0x137e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1377, 0x137e, x86_l_137e);
x86_l_1379:
	/* 0x1379: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_137c:
	/* 0x137c: jmp    1380 <tail_ipv4_policy+0x1380> */
	X86_SIM_X86_JMP(0x137c, 0x1380, x86_l_1380);
x86_l_137e:
	/* 0x137e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1380:
	/* 0x1380: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1385:
	/* 0x1385: mov    ebp,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1388:
	/* 0x1388: mov    QWORD PTR [rsp+0xa8],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505730ULL);
x86_l_1394:
	/* 0x1394: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_139d:
	/* 0x139d: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_13a6:
	/* 0x13a6: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_13af:
	/* 0x13af: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_13b8:
	/* 0x13b8: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_13c1:
	/* 0x13c1: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_13ca:
	/* 0x13ca: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_13d3:
	/* 0x13d3: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_13dc:
	/* 0x13dc: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_13e5:
	/* 0x13e5: movabs rax,0x2090b0100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8741650688ULL);
x86_l_13ef:
	/* 0x13ef: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_13f4:
	/* 0x13f4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13f9:
	/* 0x13f9: mov    rdi,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1400:
	/* 0x1400: lea    r15,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1405:
	/* 0x1405: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_1408:
	/* 0x1408: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_140a:
	/* 0x140a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_140d:
	/* 0x140d: je     1425 <tail_ipv4_policy+0x1425> */
	X86_SIM_X86_JCC(X86_CC_E, 0x140d, 0x1425, x86_l_1425);
x86_l_140f:
	/* 0x140f: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1412:
	/* 0x1412: add    QWORD PTR [rax+0x8],rbp */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1416:
	/* 0x1416: cmp    DWORD PTR [rsp+0xb0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_141e:
	/* 0x141e: jne    145b <tail_ipv4_policy+0x145b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x141e, 0x145b, x86_l_145b);
x86_l_1420:
	/* 0x1420: jmp    1691 <tail_ipv4_policy+0x1691> */
	X86_SIM_X86_JMP(0x1420, 0x1691, x86_l_1691);
x86_l_1425:
	/* 0x1425: mov    QWORD PTR [rsp+0x20],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953473ULL);
x86_l_142e:
	/* 0x142e: mov    QWORD PTR [rsp+0x28],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1433:
	/* 0x1433: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1438:
	/* 0x1438: mov    rdi,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_143f:
	/* 0x143f: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1444:
	/* 0x1444: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1449:
	/* 0x1449: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_144b:
	/* 0x144b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_144d:
	/* 0x144d: cmp    DWORD PTR [rsp+0xb0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_1455:
	/* 0x1455: je     1691 <tail_ipv4_policy+0x1691> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1455, 0x1691, x86_l_1691);
x86_l_145b:
	/* 0x145b: mov    rax,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_events_map_rate_limit)));
x86_l_1462:
	/* 0x1462: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1465:
	/* 0x1465: je     15d4 <tail_ipv4_policy+0x15d4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1465, 0x15d4, x86_l_15d4);
x86_l_146b:
	/* 0x146b: mov    DWORD PTR [rsp+0x10],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1470:
	/* 0x1470: mov    rcx,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_events_map_burst_limit)));
x86_l_1477:
	/* 0x1477: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1479:
	/* 0x1479: mov    QWORD PTR [rsp+0x90],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1481:
	/* 0x1481: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1483:
	/* 0x1483: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_148b:
	/* 0x148b: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1490:
	/* 0x1490: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1492:
	/* 0x1492: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1494:
	/* 0x1494: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1497:
	/* 0x1497: mov    DWORD PTR [rsp+0x8c],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 601295421442ULL);
x86_l_14a2:
	/* 0x14a2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14a7:
	/* 0x14a7: mov    rdi,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit_metrics)));
x86_l_14ae:
	/* 0x14ae: lea    rsi,[rsp+0x8c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_14b6:
	/* 0x14b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14b8:
	/* 0x14b8: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_14bb:
	/* 0x14bb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14be:
	/* 0x14be: jne    14ef <tail_ipv4_policy+0x14ef> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x14be, 0x14ef, x86_l_14ef);
x86_l_14c0:
	/* 0x14c0: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_14c9:
	/* 0x14c9: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_14ce:
	/* 0x14ce: mov    rdi,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit_metrics)));
x86_l_14d5:
	/* 0x14d5: lea    rsi,[rsp+0x8c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_14dd:
	/* 0x14dd: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_14e0:
	/* 0x14e0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14e2:
	/* 0x14e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14e4:
	/* 0x14e4: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_14e7:
	/* 0x14e7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_14e9:
	/* 0x14e9: js     16f1 <tail_ipv4_policy+0x16f1> */
	X86_SIM_X86_JCC(X86_CC_S, 0x14e9, 0x16f1, x86_l_16f1);
x86_l_14ef:
	/* 0x14ef: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14f4:
	/* 0x14f4: mov    rdi,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit)));
x86_l_14fb:
	/* 0x14fb: lea    rsi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1503:
	/* 0x1503: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1505:
	/* 0x1505: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1508:
	/* 0x1508: je     1576 <tail_ipv4_policy+0x1576> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1508, 0x1576, x86_l_1576);
x86_l_150a:
	/* 0x150a: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_150d:
	/* 0x150d: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_1510:
	/* 0x1510: sub    rsi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1513:
	/* 0x1513: cmp    rsi,0x3b9aca00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 1000000000ULL);
x86_l_151a:
	/* 0x151a: jbe    15b6 <tail_ipv4_policy+0x15b6> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x151a, 0x15b6, x86_l_15b6);
x86_l_1520:
	/* 0x1520: mov    rdx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_1523:
	/* 0x1523: shr    rdx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1527:
	/* 0x1527: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_1531:
	/* 0x1531: mulx   rcx,rcx,rcx */
	X86_SIM_L_EXEC_MULX(X86_RCX, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_1536:
	/* 0x1536: shr    rcx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_153a:
	/* 0x153a: imul   rdx,rcx,0x3b9aca00 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RDX, X86_RCX, X86_WIDTH_64, 1000000000ULL);
x86_l_1541:
	/* 0x1541: imul   rcx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 128ULL);
x86_l_154a:
	/* 0x154a: add    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_154e:
	/* 0x154e: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1552:
	/* 0x1552: sub    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1555:
	/* 0x1555: add    r12,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1558:
	/* 0x1558: mov    QWORD PTR [rax],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_155b:
	/* 0x155b: mov    rdx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1563:
	/* 0x1563: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1566:
	/* 0x1566: mov    r12d,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_156b:
	/* 0x156b: jbe    15bf <tail_ipv4_policy+0x15bf> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x156b, 0x15bf, x86_l_15bf);
x86_l_156d:
	/* 0x156d: mov    QWORD PTR [rax+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1571:
	/* 0x1571: mov    rcx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1574:
	/* 0x1574: jmp    15bf <tail_ipv4_policy+0x15bf> */
	X86_SIM_X86_JMP(0x1574, 0x15bf, x86_l_15bf);
x86_l_1576:
	/* 0x1576: mov    QWORD PTR [rsp+0x20],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_157b:
	/* 0x157b: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1583:
	/* 0x1583: dec    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_1586:
	/* 0x1586: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_158b:
	/* 0x158b: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1590:
	/* 0x1590: mov    rdi,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit)));
x86_l_1597:
	/* 0x1597: lea    rsi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_159f:
	/* 0x159f: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_15a4:
	/* 0x15a4: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15a6:
	/* 0x15a6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15a8:
	/* 0x15a8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_15aa:
	/* 0x15aa: mov    r12d,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15af:
	/* 0x15af: jns    15cf <tail_ipv4_policy+0x15cf> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x15af, 0x15cf, x86_l_15cf);
x86_l_15b1:
	/* 0x15b1: jmp    16ee <tail_ipv4_policy+0x16ee> */
	X86_SIM_X86_JMP(0x15b1, 0x16ee, x86_l_16ee);
x86_l_15b6:
	/* 0x15b6: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15ba:
	/* 0x15ba: mov    r12d,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15bf:
	/* 0x15bf: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_15c2:
	/* 0x15c2: je     16ee <tail_ipv4_policy+0x16ee> */
	X86_SIM_X86_JCC(X86_CC_E, 0x15c2, 0x16ee, x86_l_16ee);
x86_l_15c8:
	/* 0x15c8: dec    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_15cb:
	/* 0x15cb: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15cf:
	/* 0x15cf: mov    r14d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15d4:
	/* 0x15d4: mov    rcx,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_15db:
	/* 0x15db: mov    eax,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15dd:
	/* 0x15dd: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15df:
	/* 0x15df: mov    edx,DWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_15e6:
	/* 0x15e6: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_15e8:
	/* 0x15e8: cmovne eax,edx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RDX, X86_WIDTH_32, X86_CC_NE);
x86_l_15eb:
	/* 0x15eb: mov    ecx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_15ee:
	/* 0x15ee: cmp    eax,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_15f0:
	/* 0x15f0: mov    rdx,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_endpoint_id)));
x86_l_15f7:
	/* 0x15f7: movzx  edx,WORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_15fa:
	/* 0x15fa: cmovae eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_AE);
x86_l_15fd:
	/* 0x15fd: mov    ecx,DWORD PTR [rbx+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1603:
	/* 0x1603: mov    WORD PTR [rsp+0x38],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 240518168580ULL);
x86_l_160a:
	/* 0x160a: mov    WORD PTR [rsp+0x3a],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_160f:
	/* 0x160f: mov    DWORD PTR [rsp+0x3c],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_1613:
	/* 0x1613: mov    DWORD PTR [rsp+0x40],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1617:
	/* 0x1617: mov    WORD PTR [rsp+0x44],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_161c:
	/* 0x161c: mov    WORD PTR [rsp+0x46],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 300647710722ULL);
x86_l_1623:
	/* 0x1623: mov    DWORD PTR [rsp+0x48],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1628:
	/* 0x1628: mov    DWORD PTR [rsp+0x4c],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_162d:
	/* 0x162d: movzx  ecx,WORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 24ULL);
x86_l_1632:
	/* 0x1632: mov    WORD PTR [rsp+0x50],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1637:
	/* 0x1637: mov    ecx,DWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_163e:
	/* 0x163e: mov    BYTE PTR [rsp+0x52],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 82ULL);
x86_l_1642:
	/* 0x1642: mov    BYTE PTR [rsp+0x53],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 356482285568ULL);
x86_l_1647:
	/* 0x1647: mov    ecx,DWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_164e:
	/* 0x164e: mov    DWORD PTR [rsp+0x54],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_1652:
	/* 0x1652: mov    ecx,DWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1659:
	/* 0x1659: mov    DWORD PTR [rsp+0x58],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_165d:
	/* 0x165d: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1662:
	/* 0x1662: mov    QWORD PTR [rsp+0x68],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1667:
	/* 0x1667: mov    r9d,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 25ULL);
x86_l_166d:
	/* 0x166d: shl    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_1671:
	/* 0x1671: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_1676:
	/* 0x1676: or     rdx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1679:
	/* 0x1679: mov    rsi,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_events)));
x86_l_1680:
	/* 0x1680: lea    rcx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1685:
	/* 0x1685: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1688:
	/* 0x1688: mov    r8d,0x38 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 56ULL);
x86_l_168e:
	/* 0x168e: call   r9 */
	X86_SIM_BPF_CALL_REG(X86_R9);
x86_l_1691:
	/* 0x1691: cmp    DWORD PTR [rsp+0xc8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 858993459200ULL);
x86_l_1699:
	/* 0x1699: je     1700 <tail_ipv4_policy+0x1700> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1699, 0x1700, x86_l_1700);
x86_l_169b:
	/* 0x169b: mov    rax,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_interface_ifindex)));
x86_l_16a2:
	/* 0x16a2: mov    edi,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16a4:
	/* 0x16a4: cmp    DWORD PTR [rsp+0xc4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 841813590016ULL);
x86_l_16ac:
	/* 0x16ac: jne    16ba <tail_ipv4_policy+0x16ba> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x16ac, 0x16ba, x86_l_16ba);
x86_l_16ae:
	/* 0x16ae: mov    rax,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_netkit)));
x86_l_16b5:
	/* 0x16b5: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16b8:
	/* 0x16b8: je     16cd <tail_ipv4_policy+0x16cd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x16b8, 0x16cd, x86_l_16cd);
x86_l_16ba:
	/* 0x16ba: mov    eax,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 23ULL);
x86_l_16bf:
	/* 0x16bf: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16c1:
	/* 0x16c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16c3:
	/* 0x16c3: mov    r15d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_32);
x86_l_16c6:
	/* 0x16c6: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_16c9:
	/* 0x16c9: jns    1708 <tail_ipv4_policy+0x1708> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x16c9, 0x1708, x86_l_1708);
x86_l_16cb:
	/* 0x16cb: jmp    1722 <tail_ipv4_policy+0x1722> */
	X86_SIM_X86_JMP(0x16cb, 0x1722, x86_l_1722);
x86_l_16cd:
	/* 0x16cd: cmp    DWORD PTR [rsp+0xb4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_16d5:
	/* 0x16d5: je     16e7 <tail_ipv4_policy+0x16e7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x16d5, 0x16e7, x86_l_16e7);
x86_l_16d7:
	/* 0x16d7: mov    eax,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_16dc:
	/* 0x16dc: mov    ebp,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDI, X86_WIDTH_32);
x86_l_16de:
	/* 0x16de: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_16e1:
	/* 0x16e1: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16e3:
	/* 0x16e3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16e5:
	/* 0x16e5: mov    edi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_32);
x86_l_16e7:
	/* 0x16e7: mov    eax,0x9b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 155ULL);
x86_l_16ec:
	/* 0x16ec: jmp    16bf <tail_ipv4_policy+0x16bf> */
	X86_SIM_X86_JMP(0x16ec, 0x16bf, x86_l_16bf);
x86_l_16ee:
	/* 0x16ee: inc    QWORD PTR [r14] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_16f1:
	/* 0x16f1: mov    r14d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16f6:
	/* 0x16f6: cmp    DWORD PTR [rsp+0xc8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 858993459200ULL);
x86_l_16fe:
	/* 0x16fe: jne    169b <tail_ipv4_policy+0x169b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x16fe, 0x169b, x86_l_169b);
x86_l_1700:
	/* 0x1700: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1703:
	/* 0x1703: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_1706:
	/* 0x1706: js     1722 <tail_ipv4_policy+0x1722> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1706, 0x1722, x86_l_1722);
x86_l_1708:
	/* 0x1708: cmp    r15d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 2ULL);
x86_l_170c:
	/* 0x170c: jne    17e0 <tail_ipv4_policy+0x17e0> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x170c, 0x17e0, x86_l_17e0);
x86_l_1712:
	/* 0x1712: jmp    1722 <tail_ipv4_policy+0x1722> */
	X86_SIM_X86_JMP(0x1712, 0x1722, x86_l_1722);
x86_l_1714:
	/* 0x1714: mov    r15d,0xffffff67 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967143ULL);
x86_l_171a:
	/* 0x171a: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_171d:
	/* 0x171d: mov    r14d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1722:
	/* 0x1722: mov    rax,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_security_label)));
x86_l_1729:
	/* 0x1729: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_172b:
	/* 0x172b: mov    rcx,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_endpoint_id)));
x86_l_1732:
	/* 0x1732: movzx  ecx,WORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1735:
	/* 0x1735: mov    edx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_32);
x86_l_1738:
	/* 0x1738: neg    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_173a:
	/* 0x173a: cmovs  edx,r15d */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_R15, X86_WIDTH_32, X86_CC_S);
x86_l_173e:
	/* 0x173e: movzx  edx,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1741:
	/* 0x1741: movzx  esi,r13b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_R13, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1745:
	/* 0x1745: shl    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_1748:
	/* 0x1748: or     esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_174a:
	/* 0x174a: mov    DWORD PTR [rbx+0x28],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_174e:
	/* 0x174e: mov    DWORD PTR [rbx+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1751:
	/* 0x1751: mov    DWORD PTR [rbx+0x30],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1754:
	/* 0x1754: mov    DWORD PTR [rbx+0x34],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1757:
	/* 0x1757: mov    DWORD PTR [rbx+0x38],0x95d0202 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240675258882ULL);
x86_l_175e:
	/* 0x175e: mov    r14d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1762:
	/* 0x1762: movabs rax,0x2090b0100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8741650688ULL);
x86_l_176c:
	/* 0x176c: add    rax,0x520000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 5373952ULL);
x86_l_1772:
	/* 0x1772: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1777:
	/* 0x1777: mov    BYTE PTR [rsp+0x20],dl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_177b:
	/* 0x177b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1780:
	/* 0x1780: mov    rdi,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1787:
	/* 0x1787: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_178c:
	/* 0x178c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_178e:
	/* 0x178e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1791:
	/* 0x1791: je     179c <tail_ipv4_policy+0x179c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1791, 0x179c, x86_l_179c);
x86_l_1793:
	/* 0x1793: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1796:
	/* 0x1796: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_179a:
	/* 0x179a: jmp    17c4 <tail_ipv4_policy+0x17c4> */
	X86_SIM_X86_JMP(0x179a, 0x17c4, x86_l_17c4);
x86_l_179c:
	/* 0x179c: mov    QWORD PTR [rsp+0x38],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168577ULL);
x86_l_17a5:
	/* 0x17a5: mov    QWORD PTR [rsp+0x40],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_17aa:
	/* 0x17aa: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_17af:
	/* 0x17af: mov    rdi,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_17b6:
	/* 0x17b6: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_17bb:
	/* 0x17bb: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_17c0:
	/* 0x17c0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17c2:
	/* 0x17c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17c4:
	/* 0x17c4: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_17c9:
	/* 0x17c9: mov    rsi,QWORD PTR [rip+0xbefc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_17d0:
	/* 0x17d0: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_17d3:
	/* 0x17d3: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_17d8:
	/* 0x17d8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17da:
	/* 0x17da: mov    r15d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 2ULL);
x86_l_17e0:
	/* 0x17e0: mov    eax,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_17e3:
	/* 0x17e3: add    rsp,0xf8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 248ULL);
x86_l_17ea:
	/* 0x17ea: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_17eb:
	/* 0x17eb: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_17ed:
	/* 0x17ed: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_17ef:
	/* 0x17ef: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_17f1:
	/* 0x17f1: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_17f3:
	/* 0x17f3: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_17f4:
	/* 0x17f4: jmp    1cc5 <tail_ipv4_policy+0x1cc5> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_17f9:
	/* 0x17f9: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_17fe:
	/* 0x17fe: movzx  eax,BYTE PTR [rax+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 12ULL);
x86_l_1802:
	/* 0x1802: cmp    eax,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 58ULL);
x86_l_1805:
	/* 0x1805: je     18f1 <tail_ipv4_policy+0x18f1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1805, 0x18f1, x86_l_18f1);
x86_l_180b:
	/* 0x180b: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_180e:
	/* 0x180e: je     18df <tail_ipv4_policy+0x18df> */
	X86_SIM_X86_JCC(X86_CC_E, 0x180e, 0x18df, x86_l_18df);
x86_l_1814:
	/* 0x1814: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_1817:
	/* 0x1817: jne    18fb <tail_ipv4_policy+0x18fb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1817, 0x18fb, x86_l_18fb);
x86_l_181d:
	/* 0x181d: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_181f:
	/* 0x181f: mov    r13d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 16ULL);
x86_l_1825:
	/* 0x1825: jmp    1901 <tail_ipv4_policy+0x1901> */
	X86_SIM_X86_JMP(0x1825, 0x1901, x86_l_1901);
x86_l_182a:
	/* 0x182a: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_182c:
	/* 0x182c: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_182f:
	/* 0x182f: je     1c94 <tail_ipv4_policy+0x1c94> */
	X86_SIM_X86_JCC(X86_CC_E, 0x182f, 0x1c94, x86_l_1c94);
x86_l_1835:
	/* 0x1835: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1837:
	/* 0x1837: mov    r14d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_183c:
	/* 0x183c: jmp    33d <tail_ipv4_policy+0x33d> */
	X86_SIM_X86_JMP(0x183c, 0x33d, x86_l_33d);
x86_l_1841:
	/* 0x1841: jne    1866 <tail_ipv4_policy+0x1866> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1841, 0x1866, x86_l_1866);
x86_l_1843:
	/* 0x1843: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1848:
	/* 0x1848: movzx  eax,WORD PTR [rax+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_184c:
	/* 0x184c: shr    eax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 3ULL);
x86_l_184f:
	/* 0x184f: and    eax,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 31ULL);
x86_l_1852:
	/* 0x1852: movzx  ecx,WORD PTR [r15+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_1857:
	/* 0x1857: shr    ecx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 3ULL);
x86_l_185a:
	/* 0x185a: and    ecx,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 31ULL);
x86_l_185d:
	/* 0x185d: cmp    ax,cx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_16);
x86_l_1860:
	/* 0x1860: ja     1194 <tail_ipv4_policy+0x1194> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1860, 0x1194, x86_l_1194);
x86_l_1866:
	/* 0x1866: mov    r14d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_186b:
	/* 0x186b: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1870:
	/* 0x1870: jmp    33d <tail_ipv4_policy+0x33d> */
	X86_SIM_X86_JMP(0x1870, 0x33d, x86_l_33d);
x86_l_1875:
	/* 0x1875: mov    r13d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_1878:
	/* 0x1878: movzx  r12d,WORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_187c:
	/* 0x187c: and    r13b,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_8, X86_ALU_AND, 127ULL);
x86_l_1880:
	/* 0x1880: je     4bc <tail_ipv4_policy+0x4bc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1880, 0x4bc, x86_l_4bc);
x86_l_1886:
	/* 0x1886: jmp    1a8a <tail_ipv4_policy+0x1a8a> */
	X86_SIM_X86_JMP(0x1886, 0x1a8a, x86_l_1a8a);
x86_l_188b:
	/* 0x188b: cmp    bpl,0xbf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 191ULL);
x86_l_188f:
	/* 0x188f: ja     18a7 <tail_ipv4_policy+0x18a7> */
	X86_SIM_X86_JCC(X86_CC_A, 0x188f, 0x18a7, x86_l_18a7);
x86_l_1891:
	/* 0x1891: mov    cl,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 24ULL);
x86_l_1893:
	/* 0x1893: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_1895:
	/* 0x1895: mov    eax,0xffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 65535ULL);
x86_l_189a:
	/* 0x189a: shlx   eax,eax,ecx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RAX, X86_RAX, X86_WIDTH_32, X86_RCX, X86_ALU_SHL);
x86_l_189f:
	/* 0x189f: rol    ax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_18a3:
	/* 0x18a3: and    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 48ULL);
x86_l_18a7:
	/* 0x18a7: mov    BYTE PTR [rsp+0x29],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 41ULL);
x86_l_18ac:
	/* 0x18ac: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_18b0:
	/* 0x18b0: mov    WORD PTR [rsp+0x2a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_18b5:
	/* 0x18b5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_18ba:
	/* 0x18ba: mov    rdi,QWORD PTR [rip+0xbef8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_policystats)));
x86_l_18c1:
	/* 0x18c1: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_18c6:
	/* 0x18c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18c8:
	/* 0x18c8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_18cb:
	/* 0x18cb: je     19dc <tail_ipv4_policy+0x19dc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x18cb, 0x19dc, x86_l_19dc);
x86_l_18d1:
	/* 0x18d1: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_18d5:
	/* 0x18d5: add QWORD PTR [rax+0x8],r12 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_18da:
	/* 0x18da: jmp    1a07 <tail_ipv4_policy+0x1a07> */
	X86_SIM_X86_JMP(0x18da, 0x1a07, x86_l_1a07);
x86_l_18df:
	/* 0x18df: mov    DWORD PTR [rsp+0x10],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476768ULL);
x86_l_18e7:
	/* 0x18e7: mov    r13d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 6ULL);
x86_l_18ed:
	/* 0x18ed: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18ef:
	/* 0x18ef: jmp    1909 <tail_ipv4_policy+0x1909> */
	X86_SIM_X86_JMP(0x18ef, 0x1909, x86_l_1909);
x86_l_18f1:
	/* 0x18f1: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18f3:
	/* 0x18f3: mov    r13d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 2ULL);
x86_l_18f9:
	/* 0x18f9: jmp    1901 <tail_ipv4_policy+0x1901> */
	X86_SIM_X86_JMP(0x18f9, 0x1901, x86_l_1901);
x86_l_18fb:
	/* 0x18fb: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18fe:
	/* 0x18fe: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_1901:
	/* 0x1901: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1909:
	/* 0x1909: movzx  ecx,WORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_190e:
	/* 0x190e: test   cx,cx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_16);
x86_l_1911:
	/* 0x1911: je     19a0 <tail_ipv4_policy+0x19a0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1911, 0x19a0, x86_l_19a0);
x86_l_1917:
	/* 0x1917: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_191c:
	/* 0x191c: movzx  r12d,WORD PTR [rdx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_1921:
	/* 0x1921: mov    r15d,0xffffff72 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967154ULL);
x86_l_1927:
	/* 0x1927: cmp    eax,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_192a:
	/* 0x192a: jg     193b <tail_ipv4_policy+0x193b> */
	X86_SIM_X86_JCC(X86_CC_G, 0x192a, 0x193b, x86_l_193b);
x86_l_192c:
	/* 0x192c: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_192f:
	/* 0x192f: je     19a0 <tail_ipv4_policy+0x19a0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x192f, 0x19a0, x86_l_19a0);
x86_l_1931:
	/* 0x1931: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_1934:
	/* 0x1934: je     1949 <tail_ipv4_policy+0x1949> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1934, 0x1949, x86_l_1949);
x86_l_1936:
	/* 0x1936: jmp    171a <tail_ipv4_policy+0x171a> */
	X86_SIM_X86_JMP(0x1936, 0x171a, x86_l_171a);
x86_l_193b:
	/* 0x193b: cmp    eax,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 58ULL);
x86_l_193e:
	/* 0x193e: je     19a0 <tail_ipv4_policy+0x19a0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x193e, 0x19a0, x86_l_19a0);
x86_l_1940:
	/* 0x1940: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_1943:
	/* 0x1943: jne    171a <tail_ipv4_policy+0x171a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1943, 0x171a, x86_l_171a);
x86_l_1949:
	/* 0x1949: cmp    cx,r12w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R12, X86_WIDTH_16);
x86_l_194d:
	/* 0x194d: je     19a0 <tail_ipv4_policy+0x19a0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x194d, 0x19a0, x86_l_19a0);
x86_l_194f:
	/* 0x194f: mov    WORD PTR [rsp+0x70],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1954:
	/* 0x1954: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_1959:
	/* 0x1959: lea    rdx,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_195e:
	/* 0x195e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1961:
	/* 0x1961: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1966:
	/* 0x1966: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_196b:
	/* 0x196b: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_196e:
	/* 0x196e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1970:
	/* 0x1970: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1972:
	/* 0x1972: js     1c89 <tail_ipv4_policy+0x1c89> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1972, 0x1c89, x86_l_1c89);
x86_l_1978:
	/* 0x1978: movzx  ecx,WORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 112ULL);
x86_l_197d:
	/* 0x197d: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1982:
	/* 0x1982: lea    esi,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_1986:
	/* 0x1986: mov    r8d,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_198b:
	/* 0x198b: or     r8d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_198f:
	/* 0x198f: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_1994:
	/* 0x1994: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1997:
	/* 0x1997: mov    edx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_32);
x86_l_199a:
	/* 0x199a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_199c:
	/* 0x199c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_199e:
	/* 0x199e: js     19d1 <tail_ipv4_policy+0x19d1> */
	X86_SIM_X86_JCC(X86_CC_S, 0x199e, 0x19d1, x86_l_19d1);
x86_l_19a0:
	/* 0x19a0: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_19a3:
	/* 0x19a3: jne    132c <tail_ipv4_policy+0x132c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x19a3, 0x132c, x86_l_132c);
x86_l_19a9:
	/* 0x19a9: add    r13d,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_19ae:
	/* 0x19ae: mov    r8d,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19b3:
	/* 0x19b3: or     r8d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 16ULL);
x86_l_19b7:
	/* 0x19b7: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_19bc:
	/* 0x19bc: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_19bf:
	/* 0x19bf: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_19c2:
	/* 0x19c2: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19c4:
	/* 0x19c4: mov    ecx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_32);
x86_l_19c7:
	/* 0x19c7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19c9:
	/* 0x19c9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_19cb:
	/* 0x19cb: jns    132c <tail_ipv4_policy+0x132c> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x19cb, 0x132c, x86_l_132c);
x86_l_19d1:
	/* 0x19d1: mov    r15d,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967142ULL);
x86_l_19d7:
	/* 0x19d7: jmp    171a <tail_ipv4_policy+0x171a> */
	X86_SIM_X86_JMP(0x19d7, 0x171a, x86_l_171a);
x86_l_19dc:
	/* 0x19dc: mov    QWORD PTR [rsp+0x38],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168577ULL);
x86_l_19e5:
	/* 0x19e5: mov    QWORD PTR [rsp+0x40],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_19ea:
	/* 0x19ea: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_19ef:
	/* 0x19ef: mov    rdi,QWORD PTR [rip+0xbef8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_policystats)));
x86_l_19f6:
	/* 0x19f6: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_19fb:
	/* 0x19fb: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1a00:
	/* 0x1a00: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1a05:
	/* 0x1a05: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a07:
	/* 0x1a07: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a0c:
	/* 0x1a0c: movzx  eax,WORD PTR [rax+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_1a10:
	/* 0x1a10: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a12:
	/* 0x1a12: cmp    bpl,0x48 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 72ULL);
x86_l_1a16:
	/* 0x1a16: setb   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_B);
x86_l_1a19:
	/* 0x1a19: cmp    bpl,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 8ULL);
x86_l_1a1d:
	/* 0x1a1d: lea    ecx,[rcx+rcx*2+0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 1), 3ULL);
x86_l_1a21:
	/* 0x1a21: mov    edi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 4ULL);
x86_l_1a26:
	/* 0x1a26: cmovae edi,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDI, X86_RCX, X86_WIDTH_32, X86_CC_AE);
x86_l_1a29:
	/* 0x1a29: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a2e:
	/* 0x1a2e: mov    edx,DWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a31:
	/* 0x1a31: test   al,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_1a33:
	/* 0x1a33: jne    1b70 <tail_ipv4_policy+0x1b70> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1a33, 0x1b70, x86_l_1b70);
x86_l_1a39:
	/* 0x1a39: movzx  r13d,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1a3d:
	/* 0x1a3d: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1a41:
	/* 0x1a41: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_1a44:
	/* 0x1a44: je     1a6d <tail_ipv4_policy+0x1a6d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a44, 0x1a6d, x86_l_1a6d);
x86_l_1a46:
	/* 0x1a46: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_1a49:
	/* 0x1a49: js     1a6d <tail_ipv4_policy+0x1a6d> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1a49, 0x1a6d, x86_l_1a6d);
x86_l_1a4b:
	/* 0x1a4b: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a50:
	/* 0x1a50: mov    eax,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1a53:
	/* 0x1a53: cmp    DWORD PTR [r15+0x4],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1a57:
	/* 0x1a57: jne    1a6d <tail_ipv4_policy+0x1a6d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1a57, 0x1a6d, x86_l_1a6d);
x86_l_1a59:
	/* 0x1a59: movzx  eax,BYTE PTR [r15+0x3] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 3ULL);
x86_l_1a5e:
	/* 0x1a5e: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1a60:
	/* 0x1a60: and    ecx,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 127ULL);
x86_l_1a63:
	/* 0x1a63: cmp    cx,r13w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R13, X86_WIDTH_16);
x86_l_1a67:
	/* 0x1a67: ja     1cbd <tail_ipv4_policy+0x1cbd> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1a67, 0x1cbd, x86_l_1cbd);
x86_l_1a6d:
	/* 0x1a6d: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a72:
	/* 0x1a72: movzx  r12d,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1a76:
	/* 0x1a76: and    r13b,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_8, X86_ALU_AND, 127ULL);
x86_l_1a7a:
	/* 0x1a7a: mov    r14d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a7f:
	/* 0x1a7f: mov    r8,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a84:
	/* 0x1a84: je     4bc <tail_ipv4_policy+0x4bc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a84, 0x4bc, x86_l_4bc);
x86_l_1a8a:
	/* 0x1a8a: mov    DWORD PTR [rsp+0x90],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1a91:
	/* 0x1a91: mov    QWORD PTR [rsp+0x80],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1a99:
	/* 0x1a99: mov    QWORD PTR [rsp+0x3e],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 266287972352ULL);
x86_l_1aa2:
	/* 0x1aa2: mov    WORD PTR [rsp+0x4e],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 335007449088ULL);
x86_l_1aa9:
	/* 0x1aa9: mov    QWORD PTR [rsp+0x46],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 300647710720ULL);
x86_l_1ab2:
	/* 0x1ab2: mov    DWORD PTR [rsp+0x38],0x40 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168640ULL);
x86_l_1aba:
	/* 0x1aba: mov    BYTE PTR [rsp+0x3f],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 270582939649ULL);
x86_l_1abf:
	/* 0x1abf: mov    eax,DWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1ac6:
	/* 0x1ac6: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1aca:
	/* 0x1aca: mov    WORD PTR [rsp+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_1ad1:
	/* 0x1ad1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1ad6:
	/* 0x1ad6: mov    rdi,QWORD PTR [rip+0xbef8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipcache_v2)));
x86_l_1add:
	/* 0x1add: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1ae2:
	/* 0x1ae2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ae4:
	/* 0x1ae4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ae7:
	/* 0x1ae7: je     1b87 <tail_ipv4_policy+0x1b87> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1ae7, 0x1b87, x86_l_1b87);
x86_l_1aed:
	/* 0x1aed: mov    rcx,QWORD PTR [rip+0xbef8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_security_label)));
x86_l_1af4:
	/* 0x1af4: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1af6:
	/* 0x1af6: mov    eax,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1af9:
	/* 0x1af9: mov    DWORD PTR [rsp+0x20],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1afd:
	/* 0x1afd: mov    ecx,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b01:
	/* 0x1b01: mov    DWORD PTR [rsp+0x24],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1b05:
	/* 0x1b05: mov    WORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1b0c:
	/* 0x1b0c: mov    BYTE PTR [rsp+0x2a],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_1b11:
	/* 0x1b11: mov    BYTE PTR [rsp+0x2b],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 184683593728ULL);
x86_l_1b16:
	/* 0x1b16: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1b18:
	/* 0x1b18: je     1bb1 <tail_ipv4_policy+0x1bb1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1b18, 0x1bb1, x86_l_1bb1);
x86_l_1b1e:
	/* 0x1b1e: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1b27:
	/* 0x1b27: mov    DWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1b2f:
	/* 0x1b2f: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1b38:
	/* 0x1b38: mov    BYTE PTR [rsp+0x3b],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 253403070465ULL);
x86_l_1b3d:
	/* 0x1b3d: mov    DWORD PTR [rsp+0x3c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_1b41:
	/* 0x1b41: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1b46:
	/* 0x1b46: mov    rdi,QWORD PTR [rip+0xbef8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_node_map_v2)));
x86_l_1b4d:
	/* 0x1b4d: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1b52:
	/* 0x1b52: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b54:
	/* 0x1b54: mov    r15d,0xffffff3b */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967099ULL);
x86_l_1b5a:
	/* 0x1b5a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b5d:
	/* 0x1b5d: je     1c56 <tail_ipv4_policy+0x1c56> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1b5d, 0x1c56, x86_l_1c56);
x86_l_1b63:
	/* 0x1b63: movzx  eax,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1b66:
	/* 0x1b66: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_1b69:
	/* 0x1b69: jne    1bb3 <tail_ipv4_policy+0x1bb3> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1b69, 0x1bb3, x86_l_1bb3);
x86_l_1b6b:
	/* 0x1b6b: jmp    1c56 <tail_ipv4_policy+0x1c56> */
	X86_SIM_X86_JMP(0x1b6b, 0x1c56, x86_l_1c56);
x86_l_1b70:
	/* 0x1b70: mov    r15d,0xffffff4b */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967115ULL);
x86_l_1b76:
	/* 0x1b76: mov    sil,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_8, 1ULL);
x86_l_1b79:
	/* 0x1b79: xor    r9d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R9, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b7c:
	/* 0x1b7c: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b7f:
	/* 0x1b7f: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b82:
	/* 0x1b82: jmp    3de <tail_ipv4_policy+0x3de> */
	X86_SIM_X86_JMP(0x1b82, 0x3de, x86_l_3de);
x86_l_1b87:
	/* 0x1b87: mov    r15d,0xffffff43 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967107ULL);
x86_l_1b8d:
	/* 0x1b8d: mov    sil,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_8, 1ULL);
x86_l_1b90:
	/* 0x1b90: xor    r9d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R9, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b93:
	/* 0x1b93: mov    r14d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b98:
	/* 0x1b98: mov    r8,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1b9d:
	/* 0x1b9d: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1ba5:
	/* 0x1ba5: mov    edi,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1bac:
	/* 0x1bac: jmp    4e3 <tail_ipv4_policy+0x4e3> */
	X86_SIM_X86_JMP(0x1bac, 0x4e3, x86_l_4e3);
x86_l_1bb1:
	/* 0x1bb1: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1bb3:
	/* 0x1bb3: mov    WORD PTR [rsp+0x28],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1bb8:
	/* 0x1bb8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1bbd:
	/* 0x1bbd: mov    rdi,QWORD PTR [rip+0xbef8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_auth_map)));
x86_l_1bc4:
	/* 0x1bc4: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1bc9:
	/* 0x1bc9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bcb:
	/* 0x1bcb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1bce:
	/* 0x1bce: je     1c15 <tail_ipv4_policy+0x1c15> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1bce, 0x1c15, x86_l_1c15);
x86_l_1bd0:
	/* 0x1bd0: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_1bd3:
	/* 0x1bd3: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1bd8:
	/* 0x1bd8: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1bdb:
	/* 0x1bdb: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1bdd:
	/* 0x1bdd: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1bdf:
	/* 0x1bdf: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_1be2:
	/* 0x1be2: shr    rbp,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1be6:
	/* 0x1be6: mov    DWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1bee:
	/* 0x1bee: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1bf3:
	/* 0x1bf3: mov    rdi,QWORD PTR [rip+0xbef8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_runtime_config)));
x86_l_1bfa:
	/* 0x1bfa: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1bff:
	/* 0x1bff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c01:
	/* 0x1c01: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1c04:
	/* 0x1c04: je     1cad <tail_ipv4_policy+0x1cad> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1c04, 0x1cad, x86_l_1cad);
x86_l_1c0a:
	/* 0x1c0a: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c0d:
	/* 0x1c0d: add    rax,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1c10:
	/* 0x1c10: cmp    rax,QWORD PTR [r14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_1c13:
	/* 0x1c13: jb     1c56 <tail_ipv4_policy+0x1c56> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1c13, 0x1c56, x86_l_1c56);
x86_l_1c15:
	/* 0x1c15: mov    DWORD PTR [rsp+0x38],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168578ULL);
x86_l_1c1d:
	/* 0x1c1d: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c22:
	/* 0x1c22: mov    QWORD PTR [rsp+0x3c],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_1c27:
	/* 0x1c27: mov    eax,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1c2b:
	/* 0x1c2b: mov    DWORD PTR [rsp+0x44],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_1c2f:
	/* 0x1c2f: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_1c34:
	/* 0x1c34: mov    rsi,QWORD PTR [rip+0xbef8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_signals)));
x86_l_1c3b:
	/* 0x1c3b: lea    rcx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1c40:
	/* 0x1c40: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_1c45:
	/* 0x1c45: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1c48:
	/* 0x1c48: mov    r8d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 16ULL);
x86_l_1c4e:
	/* 0x1c4e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c50:
	/* 0x1c50: mov    r15d,0xffffff43 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967107ULL);
x86_l_1c56:
	/* 0x1c56: mov    r14d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c5b:
	/* 0x1c5b: mov    r8,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1c60:
	/* 0x1c60: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1c68:
	/* 0x1c68: mov    edi,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1c6f:
	/* 0x1c6f: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_1c72:
	/* 0x1c72: setne  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_NE);
x86_l_1c76:
	/* 0x1c76: cmp    DWORD PTR [rsp+0x88],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 584115552257ULL);
x86_l_1c7e:
	/* 0x1c7e: je     4d7 <tail_ipv4_policy+0x4d7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1c7e, 0x4d7, x86_l_4d7);
x86_l_1c84:
	/* 0x1c84: jmp    2ec <tail_ipv4_policy+0x2ec> */
	X86_SIM_X86_JMP(0x1c84, 0x2ec, x86_l_2ec);
x86_l_1c89:
	/* 0x1c89: mov    r15d,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967155ULL);
x86_l_1c8f:
	/* 0x1c8f: jmp    171a <tail_ipv4_policy+0x171a> */
	X86_SIM_X86_JMP(0x1c8f, 0x171a, x86_l_171a);
x86_l_1c94:
	/* 0x1c94: and    r12b,bpl */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_8, X86_ALU_AND);
x86_l_1c97:
	/* 0x1c97: mov    eax,0xffffff63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967139ULL);
x86_l_1c9c:
	/* 0x1c9c: mov    r15d,0xffffff7b */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967163ULL);
x86_l_1ca2:
	/* 0x1ca2: cmovne r15d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R15, X86_RAX, X86_WIDTH_32, X86_CC_NE);
x86_l_1ca6:
	/* 0x1ca6: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ca8:
	/* 0x1ca8: jmp    1b76 <tail_ipv4_policy+0x1b76> */
	X86_SIM_X86_JMP(0x1ca8, 0x1b76, x86_l_1b76);
x86_l_1cad:
	/* 0x1cad: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1caf:
	/* 0x1caf: add    rax,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1cb2:
	/* 0x1cb2: cmp    rax,QWORD PTR [r14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_1cb5:
	/* 0x1cb5: jae    1c15 <tail_ipv4_policy+0x1c15> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x1cb5, 0x1c15, x86_l_1c15);
x86_l_1cbb:
	/* 0x1cbb: jmp    1c56 <tail_ipv4_policy+0x1c56> */
	X86_SIM_X86_JMP(0x1cbb, 0x1c56, x86_l_1c56);
x86_l_1cbd:
	/* 0x1cbd: mov    r13d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_1cc0:
	/* 0x1cc0: jmp    1a6d <tail_ipv4_policy+0x1a6d> */
	X86_SIM_X86_JMP(0x1cc0, 0x1a6d, x86_l_1a6d);
x86_l_1cc5:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
