extern char __config_allow_icmp_frag_needed;
extern char __config_debug_lb;
extern char __config_enable_conntrack_accounting;
extern char __config_enable_icmp_rule;
extern char __config_enable_ipv6_fragments;
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
extern char __config_service_loopback_ipv6;
extern char __config_trace_payload_len;
extern char __config_tracing_ip_option_type;
extern char cilium_auth_map;
extern char cilium_calls;
extern char cilium_ct6_global;
extern char cilium_ct_any6_global;
extern char cilium_events;
extern char cilium_ipcache_v2;
extern char cilium_lb6_reverse_nat;
extern char cilium_metrics;
extern char cilium_node_map_v2;
extern char cilium_percpu_trace_id;
extern char cilium_policy_v2;
extern char cilium_policystats;
extern char cilium_ratelimit;
extern char cilium_ratelimit_metrics;
extern char cilium_runtime_config;
extern char cilium_signals;
extern char cilium_tail_call_buffer6;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int cilium_bpf_lxc_tail_ipv6_policy_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0x148 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 328ULL);
x86_l_a:
	/* 0xa: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: mov    QWORD PTR [rsp+0xee],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1022202216448ULL);
x86_l_19:
	/* 0x19: mov    QWORD PTR [rsp+0xe8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 996432412672ULL);
x86_l_25:
	/* 0x25: mov    QWORD PTR [rsp+0xe0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 962072674304ULL);
x86_l_31:
	/* 0x31: mov    QWORD PTR [rsp+0xd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 927712935936ULL);
x86_l_3d:
	/* 0x3d: mov    QWORD PTR [rsp+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_49:
	/* 0x49: mov    r12d,DWORD PTR [rdi+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4d:
	/* 0x4d: mov    edi,DWORD PTR [rdi+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_50:
	/* 0x50: mov    DWORD PTR [rbx+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_57:
	/* 0x57: mov    edx,DWORD PTR [rbx+0x3c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_5a:
	/* 0x5a: mov    esi,DWORD PTR [rbx+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_5d:
	/* 0x5d: mov    QWORD PTR [rbx+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_65:
	/* 0x65: mov    eax,DWORD PTR [rbx+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_68:
	/* 0x68: mov    r13d,DWORD PTR [rbx+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_6c:
	/* 0x6c: lea    rcx,[r13+0x36] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_70:
	/* 0x70: cmp    rcx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_73:
	/* 0x73: jbe    80 <tail_ipv6_policy+0x80> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x73, 0x80, x86_l_80);
x86_l_75:
	/* 0x75: mov    r15d,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967162ULL);
x86_l_7b:
	/* 0x7b: jmp    181 <tail_ipv6_policy+0x181> */
	X86_SIM_X86_JMP(0x7b, 0x181, x86_l_181);
x86_l_80:
	/* 0x80: mov    DWORD PTR [rsp+0xf8],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_87:
	/* 0x87: mov    DWORD PTR [rsp+0xc4],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_8e:
	/* 0x8e: mov    DWORD PTR [rsp+0x58],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_92:
	/* 0x92: mov    rax,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_interface_ifindex)));
x86_l_99:
	/* 0x99: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9b:
	/* 0x9b: mov    DWORD PTR [rsp+0x104],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 260ULL);
x86_l_a2:
	/* 0xa2: mov    DWORD PTR [rsp+0x11c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1219770712064ULL);
x86_l_ad:
	/* 0xad: mov    rbp,QWORD PTR [r13+0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_b1:
	/* 0xb1: mov    rax,QWORD PTR [r13+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_b5:
	/* 0xb5: mov    QWORD PTR [rsp+0x110],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_bd:
	/* 0xbd: mov    rdi,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_tail_call_buffer6)));
x86_l_c4:
	/* 0xc4: lea    rsi,[rsp+0x11c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 284ULL);
x86_l_cc:
	/* 0xcc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d1:
	/* 0xd1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d3:
	/* 0xd3: mov    r15d,0xffffff48 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967112ULL);
x86_l_d9:
	/* 0xd9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_dc:
	/* 0xdc: je     181 <tail_ipv6_policy+0x181> */
	X86_SIM_X86_JCC(X86_CC_E, 0xdc, 0x181, x86_l_181);
x86_l_e2:
	/* 0xe2: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_e5:
	/* 0xe5: mov    rax,QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e9:
	/* 0xe9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ec:
	/* 0xec: jne    f9 <tail_ipv6_policy+0xf9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xec, 0xf9, x86_l_f9);
x86_l_ee:
	/* 0xee: cmp    QWORD PTR [r14+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_f3:
	/* 0xf3: je     181 <tail_ipv6_policy+0x181> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf3, 0x181, x86_l_181);
x86_l_f9:
	/* 0xf9: mov    QWORD PTR [rsp+0x108],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_101:
	/* 0x101: mov    DWORD PTR [rsp+0x4],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_106:
	/* 0x106: mov    ecx,DWORD PTR [r14+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_10a:
	/* 0x10a: mov    DWORD PTR [rsp+0xc0],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_111:
	/* 0x111: mov    edx,DWORD PTR [r14+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_115:
	/* 0x115: mov    esi,DWORD PTR [r14+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_119:
	/* 0x119: mov    rbp,QWORD PTR [r14+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_11d:
	/* 0x11d: mov    rcx,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_124:
	/* 0x124: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_127:
	/* 0x127: sete   r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_E);
x86_l_12b:
	/* 0x12b: mov    DWORD PTR [rsp+0xa8],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_132:
	/* 0x132: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_134:
	/* 0x134: and    ecx,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_137:
	/* 0x137: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_13a:
	/* 0x13a: jne    252 <tail_ipv6_policy+0x252> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x13a, 0x252, x86_l_252);
x86_l_140:
	/* 0x140: movzx  edx,WORD PTR [r14+0x3c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 60ULL);
x86_l_145:
	/* 0x145: test   dl,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_8, 32ULL);
x86_l_148:
	/* 0x148: jne    2bd <tail_ipv6_policy+0x2bd> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x148, 0x2bd, x86_l_2bd);
x86_l_14e:
	/* 0x14e: test   dl,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_8, 16ULL);
x86_l_151:
	/* 0x151: mov    r12d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_156:
	/* 0x156: je     2d2 <tail_ipv6_policy+0x2d2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x156, 0x2d2, x86_l_2d2);
x86_l_15c:
	/* 0x15c: mov    ecx,DWORD PTR [rbx+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_15f:
	/* 0x15f: mov    DWORD PTR [rsp+0x20],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_163:
	/* 0x163: test   DWORD PTR [rsp+0x20],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953474ULL);
x86_l_16b:
	/* 0x16b: jne    2d2 <tail_ipv6_policy+0x2d2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x16b, 0x2d2, x86_l_2d2);
x86_l_171:
	/* 0x171: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_179:
	/* 0x179: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17c:
	/* 0x17c: jmp    114a <tail_ipv6_policy+0x114a> */
	X86_SIM_X86_JMP(0x17c, 0x114a, x86_l_114a);
x86_l_181:
	/* 0x181: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_184:
	/* 0x184: mov    rax,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_security_label)));
x86_l_18b:
	/* 0x18b: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18d:
	/* 0x18d: mov    rcx,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_endpoint_id)));
x86_l_194:
	/* 0x194: movzx  ecx,WORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_197:
	/* 0x197: mov    edx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_32);
x86_l_19a:
	/* 0x19a: neg    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_19c:
	/* 0x19c: cmovs  edx,r15d */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_R15, X86_WIDTH_32, X86_CC_S);
x86_l_1a0:
	/* 0x1a0: movzx  edx,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1a3:
	/* 0x1a3: movzx  esi,r13b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_R13, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1a7:
	/* 0x1a7: shl    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_1aa:
	/* 0x1aa: or     esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1ac:
	/* 0x1ac: mov    DWORD PTR [rbx+0x30],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1b0:
	/* 0x1b0: mov    DWORD PTR [rbx+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1b3:
	/* 0x1b3: mov    DWORD PTR [rbx+0x38],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1b6:
	/* 0x1b6: mov    DWORD PTR [rbx+0x3c],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_1b9:
	/* 0x1b9: mov    DWORD PTR [rbx+0x40],0x81c0202 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 275013960194ULL);
x86_l_1c0:
	/* 0x1c0: mov    r14d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c3:
	/* 0x1c3: movabs rax,0x207d30100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8721203456ULL);
x86_l_1cd:
	/* 0x1cd: add    rax,0x490000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 4784128ULL);
x86_l_1d3:
	/* 0x1d3: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1db:
	/* 0x1db: mov    BYTE PTR [rsp+0x80],dl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1e2:
	/* 0x1e2: mov    rdi,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1e9:
	/* 0x1e9: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1f1:
	/* 0x1f1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1f6:
	/* 0x1f6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f8:
	/* 0x1f8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1fb:
	/* 0x1fb: je     206 <tail_ipv6_policy+0x206> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1fb, 0x206, x86_l_206);
x86_l_1fd:
	/* 0x1fd: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_200:
	/* 0x200: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_204:
	/* 0x204: jmp    231 <tail_ipv6_policy+0x231> */
	X86_SIM_X86_JMP(0x204, 0x231, x86_l_231);
x86_l_206:
	/* 0x206: mov    QWORD PTR [rsp+0x20],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953473ULL);
x86_l_20f:
	/* 0x20f: mov    QWORD PTR [rsp+0x28],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_214:
	/* 0x214: mov    rdi,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_21b:
	/* 0x21b: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_223:
	/* 0x223: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_228:
	/* 0x228: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_22d:
	/* 0x22d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_22f:
	/* 0x22f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_231:
	/* 0x231: mov    rsi,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_238:
	/* 0x238: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_23d:
	/* 0x23d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_240:
	/* 0x240: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_245:
	/* 0x245: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_247:
	/* 0x247: mov    r15d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 2ULL);
x86_l_24d:
	/* 0x24d: jmp    1e29 <tail_ipv6_policy+0x1e29> */
	X86_SIM_X86_JMP(0x24d, 0x1e29, x86_l_1e29);
x86_l_252:
	/* 0x252: mov    eax,DWORD PTR [rbx+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_255:
	/* 0x255: mov    DWORD PTR [rsp+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_259:
	/* 0x259: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_25d:
	/* 0x25d: test   al,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_25f:
	/* 0x25f: jne    465 <tail_ipv6_policy+0x465> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x25f, 0x465, x86_l_465);
x86_l_265:
	/* 0x265: mov    rax,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_service_loopback_ipv6)));
x86_l_26c:
	/* 0x26c: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26f:
	/* 0x26f: mov    QWORD PTR [rsp+0x140],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 320ULL);
x86_l_277:
	/* 0x277: mov    rax,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27b:
	/* 0x27b: mov    QWORD PTR [rsp+0x138],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 312ULL);
x86_l_283:
	/* 0x283: cmp    DWORD PTR [rsp+0xa8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_28b:
	/* 0x28b: jne    325 <tail_ipv6_policy+0x325> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x28b, 0x325, x86_l_325);
x86_l_291:
	/* 0x291: cmp    QWORD PTR [r13+0x16],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_295:
	/* 0x295: jne    325 <tail_ipv6_policy+0x325> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x295, 0x325, x86_l_325);
x86_l_29b:
	/* 0x29b: cmp    QWORD PTR [r13+0x1e],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_29f:
	/* 0x29f: jne    325 <tail_ipv6_policy+0x325> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x29f, 0x325, x86_l_325);
x86_l_2a5:
	/* 0x2a5: movzx  r15d,BYTE PTR [r14+0x25] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 37ULL);
x86_l_2aa:
	/* 0x2aa: cmp    BYTE PTR [r14+0x24],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 154618822662ULL);
x86_l_2af:
	/* 0x2af: jne    2f6 <tail_ipv6_policy+0x2f6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2af, 0x2f6, x86_l_2f6);
x86_l_2b1:
	/* 0x2b1: mov    r13,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSI, X86_WIDTH_64);
x86_l_2b4:
	/* 0x2b4: mov    rdi,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct6_global)));
x86_l_2bb:
	/* 0x2bb: jmp    300 <tail_ipv6_policy+0x300> */
	X86_SIM_X86_JMP(0x2bb, 0x300, x86_l_300);
x86_l_2bd:
	/* 0x2bd: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_2c5:
	/* 0x2c5: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c8:
	/* 0x2c8: mov    r12d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2cd:
	/* 0x2cd: jmp    114a <tail_ipv6_policy+0x114a> */
	X86_SIM_X86_JMP(0x2cd, 0x114a, x86_l_114a);
x86_l_2d2:
	/* 0x2d2: movzx  ecx,WORD PTR [r14+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_2d7:
	/* 0x2d7: movzx  edi,WORD PTR [r14+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_2dc:
	/* 0x2dc: test   di,di */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_16);
x86_l_2df:
	/* 0x2df: jne    6f4 <tail_ipv6_policy+0x6f4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2df, 0x6f4, x86_l_6f4);
x86_l_2e5:
	/* 0x2e5: test   cx,cx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_16);
x86_l_2e8:
	/* 0x2e8: jne    748 <tail_ipv6_policy+0x748> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2e8, 0x748, x86_l_748);
x86_l_2ee:
	/* 0x2ee: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f1:
	/* 0x2f1: jmp    1a00 <tail_ipv6_policy+0x1a00> */
	X86_SIM_X86_JMP(0x2f1, 0x1a00, x86_l_1a00);
x86_l_2f6:
	/* 0x2f6: mov    r13,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSI, X86_WIDTH_64);
x86_l_2f9:
	/* 0x2f9: mov    rdi,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct_any6_global)));
x86_l_300:
	/* 0x300: mov    BYTE PTR [r14+0x25],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 158913789952ULL);
x86_l_305:
	/* 0x305: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_30a:
	/* 0x30a: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_30d:
	/* 0x30d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30f:
	/* 0x30f: mov    BYTE PTR [r14+0x25],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 37ULL);
x86_l_313:
	/* 0x313: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_316:
	/* 0x316: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_319:
	/* 0x319: je     325 <tail_ipv6_policy+0x325> */
	X86_SIM_X86_JCC(X86_CC_E, 0x319, 0x325, x86_l_325);
x86_l_31b:
	/* 0x31b: test   BYTE PTR [rax+0x24],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 154618822664ULL);
x86_l_31f:
	/* 0x31f: jne    5c4 <tail_ipv6_policy+0x5c4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x31f, 0x5c4, x86_l_5c4);
x86_l_325:
	/* 0x325: test   BYTE PTR [r14+0x3c],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 257698037761ULL);
x86_l_32a:
	/* 0x32a: jne    465 <tail_ipv6_policy+0x465> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x32a, 0x465, x86_l_465);
x86_l_330:
	/* 0x330: mov    rax,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_security_label)));
x86_l_337:
	/* 0x337: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_339:
	/* 0x339: movzx  ecx,WORD PTR [r14+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_33e:
	/* 0x33e: movzx  r13d,BYTE PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 36ULL);
x86_l_343:
	/* 0x343: mov    DWORD PTR [rsp+0x60],0x40 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 412316860480ULL);
x86_l_34b:
	/* 0x34b: mov    eax,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_34f:
	/* 0x34f: mov    DWORD PTR [rsp+0x64],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 100ULL);
x86_l_353:
	/* 0x353: mov    BYTE PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_358:
	/* 0x358: mov    BYTE PTR [rsp+0x69],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 105ULL);
x86_l_35d:
	/* 0x35d: mov    DWORD PTR [rsp+0x18],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_361:
	/* 0x361: mov    WORD PTR [rsp+0x6a],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 106ULL);
x86_l_366:
	/* 0x366: mov    rax,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_allow_icmp_frag_needed)));
x86_l_36d:
	/* 0x36d: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_370:
	/* 0x370: jne    37e <tail_ipv6_policy+0x37e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x370, 0x37e, x86_l_37e);
x86_l_372:
	/* 0x372: mov    rax,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_icmp_rule)));
x86_l_379:
	/* 0x379: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_37c:
	/* 0x37c: je     3bb <tail_ipv6_policy+0x3bb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x37c, 0x3bb, x86_l_3bb);
x86_l_37e:
	/* 0x37e: mov    rax,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_icmp_rule)));
x86_l_385:
	/* 0x385: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_388:
	/* 0x388: cmp    r13b,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_8, 58ULL);
x86_l_38c:
	/* 0x38c: jne    3bb <tail_ipv6_policy+0x3bb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x38c, 0x3bb, x86_l_3bb);
x86_l_38e:
	/* 0x38e: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_390:
	/* 0x390: je     3bb <tail_ipv6_policy+0x3bb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x390, 0x3bb, x86_l_3bb);
x86_l_392:
	/* 0x392: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_397:
	/* 0x397: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_39c:
	/* 0x39c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_39f:
	/* 0x39f: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_3a4:
	/* 0x3a4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a6:
	/* 0x3a6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3a8:
	/* 0x3a8: js     496 <tail_ipv6_policy+0x496> */
	X86_SIM_X86_JCC(X86_CC_S, 0x3a8, 0x496, x86_l_496);
x86_l_3ae:
	/* 0x3ae: movzx  eax,BYTE PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 32ULL);
x86_l_3b3:
	/* 0x3b3: shl    eax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_3b6:
	/* 0x3b6: mov    WORD PTR [rsp+0x6a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 106ULL);
x86_l_3bb:
	/* 0x3bb: mov    rdi,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_policy_v2)));
x86_l_3c2:
	/* 0x3c2: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3c7:
	/* 0x3c7: mov    r15d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 1ULL);
x86_l_3cd:
	/* 0x3cd: call   r15 */
	X86_SIM_BPF_CALL_REG(X86_R15);
x86_l_3d0:
	/* 0x3d0: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_3d3:
	/* 0x3d3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3d6:
	/* 0x3d6: je     5e9 <tail_ipv6_policy+0x5e9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3d6, 0x5e9, x86_l_5e9);
x86_l_3dc:
	/* 0x3dc: cmp    DWORD PTR [rdi+0x4],0xffffffff */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 21474836479ULL);
x86_l_3e0:
	/* 0x3e0: jne    62d <tail_ipv6_policy+0x62d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3e0, 0x62d, x86_l_62d);
x86_l_3e6:
	/* 0x3e6: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3e8:
	/* 0x3e8: movzx  ebp,WORD PTR [rdi+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_3ec:
	/* 0x3ec: mov    rcx,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_policy_accounting)));
x86_l_3f3:
	/* 0x3f3: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f6:
	/* 0x3f6: mov    r8d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RBP, X86_WIDTH_32);
x86_l_3f9:
	/* 0x3f9: je     52b <tail_ipv6_policy+0x52b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3f9, 0x52b, x86_l_52b);
x86_l_3ff:
	/* 0x3ff: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_401:
	/* 0x401: shr    sil,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_8, X86_ALU_SHR, 3ULL);
x86_l_405:
	/* 0x405: movzx  ecx,BYTE PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 104ULL);
x86_l_40a:
	/* 0x40a: mov    r12d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_40d:
	/* 0x40d: mov    rdx,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_endpoint_id)));
x86_l_414:
	/* 0x414: movzx  edx,WORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_417:
	/* 0x417: mov    WORD PTR [rsp+0x80],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_41f:
	/* 0x41f: mov    BYTE PTR [rsp+0x82],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 558345748480ULL);
x86_l_427:
	/* 0x427: mov    BYTE PTR [rsp+0x83],sil */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 131ULL);
x86_l_42f:
	/* 0x42f: and    cl,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 1ULL);
x86_l_432:
	/* 0x432: mov    edx,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_436:
	/* 0x436: mov    DWORD PTR [rsp+0x84],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_43d:
	/* 0x43d: mov    BYTE PTR [rsp+0x88],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_444:
	/* 0x444: cmp    bpl,0x47 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 71ULL);
x86_l_448:
	/* 0x448: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_44d:
	/* 0x44d: mov    r15,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDI, X86_WIDTH_64);
x86_l_450:
	/* 0x450: ja     475 <tail_ipv6_policy+0x475> */
	X86_SIM_X86_JCC(X86_CC_A, 0x450, 0x475, x86_l_475);
x86_l_452:
	/* 0x452: movzx  eax,sil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RSI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_456:
	/* 0x456: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_458:
	/* 0x458: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_45b:
	/* 0x45b: movzx  r13d,r13b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R13, X86_R13, X86_WIDTH_32, X86_WIDTH_8);
x86_l_45f:
	/* 0x45f: cmovne r13d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RCX, X86_WIDTH_32, X86_CC_NE);
x86_l_463:
	/* 0x463: jmp    4ba <tail_ipv6_policy+0x4ba> */
	X86_SIM_X86_JMP(0x463, 0x4ba, x86_l_4ba);
x86_l_465:
	/* 0x465: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_46d:
	/* 0x46d: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_470:
	/* 0x470: jmp    eb8 <tail_ipv6_policy+0xeb8> */
	X86_SIM_X86_JMP(0x470, 0xeb8, x86_l_eb8);
x86_l_475:
	/* 0x475: cmp    bpl,0xbf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 191ULL);
x86_l_479:
	/* 0x479: ja     4b6 <tail_ipv6_policy+0x4b6> */
	X86_SIM_X86_JCC(X86_CC_A, 0x479, 0x4b6, x86_l_4b6);
x86_l_47b:
	/* 0x47b: mov    cl,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 24ULL);
x86_l_47d:
	/* 0x47d: sub    cl,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_8, X86_ALU_SUB);
x86_l_480:
	/* 0x480: mov    eax,0xffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 65535ULL);
x86_l_485:
	/* 0x485: shlx   eax,eax,ecx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RAX, X86_RAX, X86_WIDTH_32, X86_RCX, X86_ALU_SHL);
x86_l_48a:
	/* 0x48a: rol    ax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_48e:
	/* 0x48e: mov    ecx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_492:
	/* 0x492: and    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_AND);
x86_l_494:
	/* 0x494: jmp    4ba <tail_ipv6_policy+0x4ba> */
	X86_SIM_X86_JMP(0x494, 0x4ba, x86_l_4ba);
x86_l_496:
	/* 0x496: mov    r15d,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967162ULL);
x86_l_49c:
	/* 0x49c: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_49e:
	/* 0x49e: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4a0:
	/* 0x4a0: mov    dil,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_8, 1ULL);
x86_l_4a3:
	/* 0x4a3: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4a6:
	/* 0x4a6: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4a9:
	/* 0x4a9: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_4b1:
	/* 0x4b1: jmp    b8c <tail_ipv6_policy+0xb8c> */
	X86_SIM_X86_JMP(0x4b1, 0xb8c, x86_l_b8c);
x86_l_4b6:
	/* 0x4b6: mov    ecx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4ba:
	/* 0x4ba: mov    BYTE PTR [rsp+0x89],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 137ULL);
x86_l_4c2:
	/* 0x4c2: mov    WORD PTR [rsp+0x8a],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 138ULL);
x86_l_4ca:
	/* 0x4ca: mov    rdi,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_policystats)));
x86_l_4d1:
	/* 0x4d1: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_4d9:
	/* 0x4d9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4de:
	/* 0x4de: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e0:
	/* 0x4e0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4e3:
	/* 0x4e3: je     4f0 <tail_ipv6_policy+0x4f0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4e3, 0x4f0, x86_l_4f0);
x86_l_4e5:
	/* 0x4e5: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_4e9:
	/* 0x4e9: add QWORD PTR [rax+0x8],r12 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4ee:
	/* 0x4ee: jmp    51e <tail_ipv6_policy+0x51e> */
	X86_SIM_X86_JMP(0x4ee, 0x51e, x86_l_51e);
x86_l_4f0:
	/* 0x4f0: mov    QWORD PTR [rsp+0x20],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953473ULL);
x86_l_4f9:
	/* 0x4f9: mov    QWORD PTR [rsp+0x28],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4fe:
	/* 0x4fe: mov    rdi,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_policystats)));
x86_l_505:
	/* 0x505: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_50d:
	/* 0x50d: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_512:
	/* 0x512: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_517:
	/* 0x517: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_51c:
	/* 0x51c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_51e:
	/* 0x51e: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_521:
	/* 0x521: movzx  r8d,WORD PTR [r15+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_526:
	/* 0x526: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_52b:
	/* 0x52b: cmp    bpl,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 8ULL);
x86_l_52f:
	/* 0x52f: setae  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_AE);
x86_l_532:
	/* 0x532: shl    cl,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_SHL, 2ULL);
x86_l_535:
	/* 0x535: or     cl,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_OR, 1ULL);
x86_l_538:
	/* 0x538: cmp    bpl,0x48 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 72ULL);
x86_l_53c:
	/* 0x53c: movzx  ecx,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_53f:
	/* 0x53f: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_544:
	/* 0x544: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_547:
	/* 0x547: mov    esi,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_54a:
	/* 0x54a: test   r8b,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R8, X86_WIDTH_8, 1ULL);
x86_l_54e:
	/* 0x54e: jne    a8b <tail_ipv6_policy+0xa8b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x54e, 0xa8b, x86_l_a8b);
x86_l_554:
	/* 0x554: movzx  r13d,r8w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R13, X86_R8, X86_WIDTH_32, X86_WIDTH_16);
x86_l_558:
	/* 0x558: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_55c:
	/* 0x55c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_55f:
	/* 0x55f: mov    r12d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_564:
	/* 0x564: je     587 <tail_ipv6_policy+0x587> */
	X86_SIM_X86_JCC(X86_CC_E, 0x564, 0x587, x86_l_587);
x86_l_566:
	/* 0x566: test   r8w,r8w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R8, X86_R8, X86_WIDTH_16);
x86_l_56a:
	/* 0x56a: js     587 <tail_ipv6_policy+0x587> */
	X86_SIM_X86_JCC(X86_CC_S, 0x56a, 0x587, x86_l_587);
x86_l_56c:
	/* 0x56c: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_56f:
	/* 0x56f: cmp    DWORD PTR [rax+0x4],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_572:
	/* 0x572: jne    587 <tail_ipv6_policy+0x587> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x572, 0x587, x86_l_587);
x86_l_574:
	/* 0x574: movzx  eax,BYTE PTR [rax+0x3] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 3ULL);
x86_l_578:
	/* 0x578: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_57a:
	/* 0x57a: and    ecx,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 127ULL);
x86_l_57d:
	/* 0x57d: cmp    cx,r13w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R13, X86_WIDTH_16);
x86_l_581:
	/* 0x581: ja     8ec <tail_ipv6_policy+0x8ec> */
	X86_SIM_X86_JCC(X86_CC_A, 0x581, 0x8ec, x86_l_8ec);
x86_l_587:
	/* 0x587: movzx  eax,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_58a:
	/* 0x58a: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_58e:
	/* 0x58e: and    r13b,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_8, X86_ALU_AND, 127ULL);
x86_l_592:
	/* 0x592: jne    9ad <tail_ipv6_policy+0x9ad> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x592, 0x9ad, x86_l_9ad);
x86_l_598:
	/* 0x598: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_59b:
	/* 0x59b: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_59e:
	/* 0x59e: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_5a1:
	/* 0x5a1: setne  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_NE);
x86_l_5a5:
	/* 0x5a5: cmp    DWORD PTR [rsp+0xa8],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 721554505729ULL);
x86_l_5ad:
	/* 0x5ad: jne    b89 <tail_ipv6_policy+0xb89> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x5ad, 0xb89, x86_l_b89);
x86_l_5b3:
	/* 0x5b3: mov    r8d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R13, X86_WIDTH_32);
x86_l_5b6:
	/* 0x5b6: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_5b9:
	/* 0x5b9: je     113e <tail_ipv6_policy+0x113e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5b9, 0x113e, x86_l_113e);
x86_l_5bf:
	/* 0x5bf: jmp    b8c <tail_ipv6_policy+0xb8c> */
	X86_SIM_X86_JMP(0x5bf, 0xb8c, x86_l_b8c);
x86_l_5c4:
	/* 0x5c4: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5c6:
	/* 0x5c6: cmp    DWORD PTR [rsp+0xc4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 841813590016ULL);
x86_l_5ce:
	/* 0x5ce: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_5d1:
	/* 0x5d1: shl    eax,0xa */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 10ULL);
x86_l_5d4:
	/* 0x5d4: or     eax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 8ULL);
x86_l_5d7:
	/* 0x5d7: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_5df:
	/* 0x5df: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5e2:
	/* 0x5e2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5e4:
	/* 0x5e4: jmp    eea <tail_ipv6_policy+0xeea> */
	X86_SIM_X86_JMP(0x5e4, 0xeea, x86_l_eea);
x86_l_5e9:
	/* 0x5e9: mov    DWORD PTR [rsp+0x64],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 429496729600ULL);
x86_l_5f1:
	/* 0x5f1: mov    QWORD PTR [rsp+0x8],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5f6:
	/* 0x5f6: mov    rdi,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_policy_v2)));
x86_l_5fd:
	/* 0x5fd: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_602:
	/* 0x602: call   r15 */
	X86_SIM_BPF_CALL_REG(X86_R15);
x86_l_605:
	/* 0x605: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_60a:
	/* 0x60a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_60d:
	/* 0x60d: jne    66a <tail_ipv6_policy+0x66a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x60d, 0x66a, x86_l_66a);
x86_l_60f:
	/* 0x60f: shr    rbp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_SHR, 40ULL);
x86_l_613:
	/* 0x613: and    ebp,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 1ULL);
x86_l_616:
	/* 0x616: and    r12b,bpl */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_8, X86_ALU_AND);
x86_l_619:
	/* 0x619: mov    eax,0xffffff63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967139ULL);
x86_l_61e:
	/* 0x61e: mov    r15d,0xffffff7b */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967163ULL);
x86_l_624:
	/* 0x624: cmovne r15d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R15, X86_RAX, X86_WIDTH_32, X86_CC_NE);
x86_l_628:
	/* 0x628: jmp    49c <tail_ipv6_policy+0x49c> */
	X86_SIM_X86_JMP(0x628, 0x49c, x86_l_49c);
x86_l_62d:
	/* 0x62d: mov    r15,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDI, X86_WIDTH_64);
x86_l_630:
	/* 0x630: mov    DWORD PTR [rsp+0x64],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 429496729600ULL);
x86_l_638:
	/* 0x638: mov    rdi,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_policy_v2)));
x86_l_63f:
	/* 0x63f: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_644:
	/* 0x644: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_649:
	/* 0x649: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_64b:
	/* 0x64b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_64e:
	/* 0x64e: je     858 <tail_ipv6_policy+0x858> */
	X86_SIM_X86_JCC(X86_CC_E, 0x64e, 0x858, x86_l_858);
x86_l_654:
	/* 0x654: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_657:
	/* 0x657: mov    eax,DWORD PTR [r15+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_65b:
	/* 0x65b: cmp    DWORD PTR [rcx+0x4],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_65e:
	/* 0x65e: jbe    8bd <tail_ipv6_policy+0x8bd> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x65e, 0x8bd, x86_l_8bd);
x86_l_664:
	/* 0x664: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_667:
	/* 0x667: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_66a:
	/* 0x66a: mov    r15,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDI, X86_WIDTH_64);
x86_l_66d:
	/* 0x66d: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_670:
	/* 0x670: movzx  ebp,WORD PTR [rax+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_674:
	/* 0x674: mov    rax,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_policy_accounting)));
x86_l_67b:
	/* 0x67b: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_67e:
	/* 0x67e: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_680:
	/* 0x680: je     93e <tail_ipv6_policy+0x93e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x680, 0x93e, x86_l_93e);
x86_l_686:
	/* 0x686: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_688:
	/* 0x688: shr    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHR, 3ULL);
x86_l_68b:
	/* 0x68b: movzx  ecx,BYTE PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 104ULL);
x86_l_690:
	/* 0x690: mov    edx,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_692:
	/* 0x692: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_697:
	/* 0x697: mov    rdx,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_endpoint_id)));
x86_l_69e:
	/* 0x69e: movzx  edx,WORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_6a1:
	/* 0x6a1: mov    WORD PTR [rsp+0x80],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_6a9:
	/* 0x6a9: mov    BYTE PTR [rsp+0x82],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 558345748480ULL);
x86_l_6b1:
	/* 0x6b1: mov    BYTE PTR [rsp+0x83],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 131ULL);
x86_l_6b8:
	/* 0x6b8: and    cl,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 1ULL);
x86_l_6bb:
	/* 0x6bb: mov    DWORD PTR [rsp+0x84],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_6c6:
	/* 0x6c6: mov    BYTE PTR [rsp+0x88],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_6cd:
	/* 0x6cd: cmp    bpl,0x47 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 71ULL);
x86_l_6d1:
	/* 0x6d1: ja     862 <tail_ipv6_policy+0x862> */
	X86_SIM_X86_JCC(X86_CC_A, 0x6d1, 0x862, x86_l_862);
x86_l_6d7:
	/* 0x6d7: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_6da:
	/* 0x6da: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6dc:
	/* 0x6dc: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_6df:
	/* 0x6df: movzx  r13d,r13b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R13, X86_R13, X86_WIDTH_32, X86_WIDTH_8);
x86_l_6e3:
	/* 0x6e3: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_6eb:
	/* 0x6eb: cmovne r13d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RCX, X86_WIDTH_32, X86_CC_NE);
x86_l_6ef:
	/* 0x6ef: jmp    87e <tail_ipv6_policy+0x87e> */
	X86_SIM_X86_JMP(0x6ef, 0x87e, x86_l_87e);
x86_l_6f4:
	/* 0x6f4: mov    QWORD PTR [rsp+0x18],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6f9:
	/* 0x6f9: test   dl,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_8, 1ULL);
x86_l_6fc:
	/* 0x6fc: sete   r15b */
	X86_SIM_L_EXEC_SETCC(X86_R15, X86_CC_E);
x86_l_700:
	/* 0x700: bt     rbp,0x29 */
	X86_SIM_L_EXEC_BT_IMM(X86_RBP, X86_WIDTH_64, 41ULL);
x86_l_705:
	/* 0x705: setae  bpl */
	X86_SIM_L_EXEC_SETCC(X86_RBP, X86_CC_AE);
x86_l_709:
	/* 0x709: test   cx,cx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_16);
x86_l_70c:
	/* 0x70c: jne    75d <tail_ipv6_policy+0x75d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x70c, 0x75d, x86_l_75d);
x86_l_70e:
	/* 0x70e: mov    WORD PTR [rsp+0x80],di */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_716:
	/* 0x716: mov    rax,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_71d:
	/* 0x71d: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_720:
	/* 0x720: mov    rdi,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb6_reverse_nat)));
x86_l_727:
	/* 0x727: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_72f:
	/* 0x72f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_734:
	/* 0x734: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_736:
	/* 0x736: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_739:
	/* 0x739: je     19f8 <tail_ipv6_policy+0x19f8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x739, 0x19f8, x86_l_19f8);
x86_l_73f:
	/* 0x73f: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_742:
	/* 0x742: mov    rax,QWORD PTR [r14+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_746:
	/* 0x746: jmp    779 <tail_ipv6_policy+0x779> */
	X86_SIM_X86_JMP(0x746, 0x779, x86_l_779);
x86_l_748:
	/* 0x748: mov    QWORD PTR [rsp+0x18],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_74d:
	/* 0x74d: test   dl,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_8, 1ULL);
x86_l_750:
	/* 0x750: sete   r15b */
	X86_SIM_L_EXEC_SETCC(X86_R15, X86_CC_E);
x86_l_754:
	/* 0x754: bt     rbp,0x29 */
	X86_SIM_L_EXEC_BT_IMM(X86_RBP, X86_WIDTH_64, 41ULL);
x86_l_759:
	/* 0x759: setae  bpl */
	X86_SIM_L_EXEC_SETCC(X86_RBP, X86_CC_AE);
x86_l_75d:
	/* 0x75d: mov    rdx,QWORD PTR [r14+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_761:
	/* 0x761: mov    QWORD PTR [rsp+0x28],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_766:
	/* 0x766: mov    rdx,QWORD PTR [r14+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_76a:
	/* 0x76a: mov    QWORD PTR [rsp+0x20],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_76f:
	/* 0x76f: mov    WORD PTR [rsp+0x30],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_774:
	/* 0x774: lea    r13,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_779:
	/* 0x779: mov    rcx,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_780:
	/* 0x780: movzx  edx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_783:
	/* 0x783: mov    rdx,QWORD PTR [r14+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_787:
	/* 0x787: mov    QWORD PTR [rsp+0x88],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_78f:
	/* 0x78f: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_797:
	/* 0x797: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_79a:
	/* 0x79a: mov    rax,QWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_79e:
	/* 0x79e: mov    QWORD PTR [r14+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_7a2:
	/* 0x7a2: mov    rax,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7a6:
	/* 0x7a6: mov    QWORD PTR [r14+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7aa:
	/* 0x7aa: test   r15b,r15b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_8);
x86_l_7ad:
	/* 0x7ad: jne    1875 <tail_ipv6_policy+0x1875> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x7ad, 0x1875, x86_l_1875);
x86_l_7b3:
	/* 0x7b3: mov    rax,QWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7b7:
	/* 0x7b7: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_7bc:
	/* 0x7bc: mov    rax,QWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7bf:
	/* 0x7bf: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_7c4:
	/* 0x7c4: movzx  eax,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_7c7:
	/* 0x7c7: lea    rdx,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_7cf:
	/* 0x7cf: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_7d4:
	/* 0x7d4: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_7d7:
	/* 0x7d7: mov    esi,0x26 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 38ULL);
x86_l_7dc:
	/* 0x7dc: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_7e1:
	/* 0x7e1: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7e4:
	/* 0x7e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7e6:
	/* 0x7e6: mov    r15d,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967155ULL);
x86_l_7ec:
	/* 0x7ec: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_7ee:
	/* 0x7ee: js     1e41 <tail_ipv6_policy+0x1e41> */
	X86_SIM_X86_JCC(X86_CC_S, 0x7ee, 0x1e41, x86_l_1e41);
x86_l_7f4:
	/* 0x7f4: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_7f7:
	/* 0x7f7: je     1e41 <tail_ipv6_policy+0x1e41> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7f7, 0x1e41, x86_l_1e41);
x86_l_7fd:
	/* 0x7fd: mov    rax,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_805:
	/* 0x805: mov    QWORD PTR [r14+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_809:
	/* 0x809: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_811:
	/* 0x811: mov    QWORD PTR [r14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_814:
	/* 0x814: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_817:
	/* 0x817: je     1875 <tail_ipv6_policy+0x1875> */
	X86_SIM_X86_JCC(X86_CC_E, 0x817, 0x1875, x86_l_1875);
x86_l_81d:
	/* 0x81d: movzx  eax,BYTE PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 36ULL);
x86_l_822:
	/* 0x822: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_82a:
	/* 0x82a: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_82d:
	/* 0x82d: je     1803 <tail_ipv6_policy+0x1803> */
	X86_SIM_X86_JCC(X86_CC_E, 0x82d, 0x1803, x86_l_1803);
x86_l_833:
	/* 0x833: cmp    eax,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 58ULL);
x86_l_836:
	/* 0x836: je     17fb <tail_ipv6_policy+0x17fb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x836, 0x17fb, x86_l_17fb);
x86_l_83c:
	/* 0x83c: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_83f:
	/* 0x83f: jne    1875 <tail_ipv6_policy+0x1875> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x83f, 0x1875, x86_l_1875);
x86_l_845:
	/* 0x845: mov    DWORD PTR [rsp+0x8],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738400ULL);
x86_l_84d:
	/* 0x84d: mov    r15d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 6ULL);
x86_l_853:
	/* 0x853: jmp    1809 <tail_ipv6_policy+0x1809> */
	X86_SIM_X86_JMP(0x853, 0x1809, x86_l_1809);
x86_l_858:
	/* 0x858: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_85a:
	/* 0x85a: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_85d:
	/* 0x85d: jmp    3e8 <tail_ipv6_policy+0x3e8> */
	X86_SIM_X86_JMP(0x85d, 0x3e8, x86_l_3e8);
x86_l_862:
	/* 0x862: cmp    bpl,0xbf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 191ULL);
x86_l_866:
	/* 0x866: ja     87e <tail_ipv6_policy+0x87e> */
	X86_SIM_X86_JCC(X86_CC_A, 0x866, 0x87e, x86_l_87e);
x86_l_868:
	/* 0x868: mov    cl,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 24ULL);
x86_l_86a:
	/* 0x86a: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_86c:
	/* 0x86c: mov    eax,0xffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 65535ULL);
x86_l_871:
	/* 0x871: shlx   eax,eax,ecx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RAX, X86_RAX, X86_WIDTH_32, X86_RCX, X86_ALU_SHL);
x86_l_876:
	/* 0x876: rol    ax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_87a:
	/* 0x87a: and    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 24ULL);
x86_l_87e:
	/* 0x87e: mov    BYTE PTR [rsp+0x89],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 137ULL);
x86_l_886:
	/* 0x886: mov    eax,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_88a:
	/* 0x88a: mov    WORD PTR [rsp+0x8a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 138ULL);
x86_l_892:
	/* 0x892: mov    rdi,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_policystats)));
x86_l_899:
	/* 0x899: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_8a1:
	/* 0x8a1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_8a6:
	/* 0x8a6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8a8:
	/* 0x8a8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8ab:
	/* 0x8ab: je     905 <tail_ipv6_policy+0x905> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8ab, 0x905, x86_l_905);
x86_l_8ad:
	/* 0x8ad: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_8b1:
	/* 0x8b1: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8b6:
	/* 0x8b6: add QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_8bb:
	/* 0x8bb: jmp    938 <tail_ipv6_policy+0x938> */
	X86_SIM_X86_JMP(0x8bb, 0x938, x86_l_938);
x86_l_8bd:
	/* 0x8bd: jne    17f0 <tail_ipv6_policy+0x17f0> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x8bd, 0x17f0, x86_l_17f0);
x86_l_8c3:
	/* 0x8c3: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_8c6:
	/* 0x8c6: movzx  edx,WORD PTR [rcx+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_8ca:
	/* 0x8ca: shr    edx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 3ULL);
x86_l_8cd:
	/* 0x8cd: and    edx,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 31ULL);
x86_l_8d0:
	/* 0x8d0: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_8d3:
	/* 0x8d3: movzx  ecx,WORD PTR [r15+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_8d8:
	/* 0x8d8: shr    ecx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 3ULL);
x86_l_8db:
	/* 0x8db: and    ecx,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 31ULL);
x86_l_8de:
	/* 0x8de: cmp    dx,cx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_16);
x86_l_8e1:
	/* 0x8e1: jbe    3e8 <tail_ipv6_policy+0x3e8> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x8e1, 0x3e8, x86_l_3e8);
x86_l_8e7:
	/* 0x8e7: jmp    66a <tail_ipv6_policy+0x66a> */
	X86_SIM_X86_JMP(0x8e7, 0x66a, x86_l_66a);
x86_l_8ec:
	/* 0x8ec: mov    r13d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_8ef:
	/* 0x8ef: movzx  eax,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_8f2:
	/* 0x8f2: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_8f6:
	/* 0x8f6: and    r13b,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_8, X86_ALU_AND, 127ULL);
x86_l_8fa:
	/* 0x8fa: je     598 <tail_ipv6_policy+0x598> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8fa, 0x598, x86_l_598);
x86_l_900:
	/* 0x900: jmp    9ad <tail_ipv6_policy+0x9ad> */
	X86_SIM_X86_JMP(0x900, 0x9ad, x86_l_9ad);
x86_l_905:
	/* 0x905: mov    QWORD PTR [rsp+0x20],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953473ULL);
x86_l_90e:
	/* 0x90e: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_913:
	/* 0x913: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_918:
	/* 0x918: mov    rdi,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_policystats)));
x86_l_91f:
	/* 0x91f: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_927:
	/* 0x927: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_92c:
	/* 0x92c: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_931:
	/* 0x931: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_936:
	/* 0x936: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_938:
	/* 0x938: movzx  eax,WORD PTR [r12+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_93e:
	/* 0x93e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_940:
	/* 0x940: cmp    bpl,0x48 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 72ULL);
x86_l_944:
	/* 0x944: setb   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_B);
x86_l_947:
	/* 0x947: cmp    bpl,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 8ULL);
x86_l_94b:
	/* 0x94b: lea    ecx,[rcx+rcx*2+0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 1), 3ULL);
x86_l_94f:
	/* 0x94f: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_954:
	/* 0x954: cmovae edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_AE);
x86_l_957:
	/* 0x957: mov    esi,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_95c:
	/* 0x95c: test   al,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_95e:
	/* 0x95e: jne    a8b <tail_ipv6_policy+0xa8b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x95e, 0xa8b, x86_l_a8b);
x86_l_964:
	/* 0x964: movzx  r13d,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_968:
	/* 0x968: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_96c:
	/* 0x96c: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_96f:
	/* 0x96f: je     995 <tail_ipv6_policy+0x995> */
	X86_SIM_X86_JCC(X86_CC_E, 0x96f, 0x995, x86_l_995);
x86_l_971:
	/* 0x971: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_974:
	/* 0x974: js     995 <tail_ipv6_policy+0x995> */
	X86_SIM_X86_JCC(X86_CC_S, 0x974, 0x995, x86_l_995);
x86_l_976:
	/* 0x976: mov    eax,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_97b:
	/* 0x97b: cmp    DWORD PTR [r15+0x4],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_97f:
	/* 0x97f: jne    995 <tail_ipv6_policy+0x995> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x97f, 0x995, x86_l_995);
x86_l_981:
	/* 0x981: movzx  eax,BYTE PTR [r15+0x3] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 3ULL);
x86_l_986:
	/* 0x986: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_988:
	/* 0x988: and    ecx,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 127ULL);
x86_l_98b:
	/* 0x98b: cmp    cx,r13w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R13, X86_WIDTH_16);
x86_l_98f:
	/* 0x98f: ja     1e6a <tail_ipv6_policy+0x1e6a> */
	X86_SIM_X86_JCC(X86_CC_A, 0x98f, 0x1e6a, x86_l_1e6a);
x86_l_995:
	/* 0x995: movzx  eax,WORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_99a:
	/* 0x99a: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_99e:
	/* 0x99e: and    r13b,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_8, X86_ALU_AND, 127ULL);
x86_l_9a2:
	/* 0x9a2: mov    r12d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_9a7:
	/* 0x9a7: je     598 <tail_ipv6_policy+0x598> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9a7, 0x598, x86_l_598);
x86_l_9ad:
	/* 0x9ad: mov    DWORD PTR [rsp+0x70],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_9b1:
	/* 0x9b1: mov    DWORD PTR [rsp+0xb0],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_9b8:
	/* 0x9b8: movabs rax,0x2000000000000a0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 144115188075856032ULL);
x86_l_9c2:
	/* 0x9c2: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9c7:
	/* 0x9c7: mov    rax,QWORD PTR [rsp+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_9cf:
	/* 0x9cf: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_9d4:
	/* 0x9d4: mov    rax,QWORD PTR [rsp+0x110] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_9dc:
	/* 0x9dc: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9e1:
	/* 0x9e1: mov    rdi,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipcache_v2)));
x86_l_9e8:
	/* 0x9e8: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9ed:
	/* 0x9ed: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_9f2:
	/* 0x9f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9f4:
	/* 0x9f4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9f7:
	/* 0x9f7: je     a96 <tail_ipv6_policy+0xa96> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9f7, 0xa96, x86_l_a96);
x86_l_9fd:
	/* 0x9fd: mov    rcx,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_security_label)));
x86_l_a04:
	/* 0xa04: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a06:
	/* 0xa06: mov    eax,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_a09:
	/* 0xa09: mov    DWORD PTR [rsp+0x80],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_a10:
	/* 0xa10: mov    ecx,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_a14:
	/* 0xa14: mov    DWORD PTR [rsp+0x84],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_a1b:
	/* 0xa1b: mov    WORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_a25:
	/* 0xa25: mov    BYTE PTR [rsp+0x8a],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 138ULL);
x86_l_a2d:
	/* 0xa2d: mov    BYTE PTR [rsp+0x8b],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 597000454144ULL);
x86_l_a35:
	/* 0xa35: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a37:
	/* 0xa37: je     ab2 <tail_ipv6_policy+0xab2> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa37, 0xab2, x86_l_ab2);
x86_l_a39:
	/* 0xa39: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_a42:
	/* 0xa42: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_a4a:
	/* 0xa4a: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_a53:
	/* 0xa53: mov    BYTE PTR [rsp+0x23],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 150323855361ULL);
x86_l_a58:
	/* 0xa58: mov    DWORD PTR [rsp+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_a5c:
	/* 0xa5c: mov    rdi,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_node_map_v2)));
x86_l_a63:
	/* 0xa63: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a68:
	/* 0xa68: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a6d:
	/* 0xa6d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a6f:
	/* 0xa6f: mov    r15d,0xffffff3b */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967099ULL);
x86_l_a75:
	/* 0xa75: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a78:
	/* 0xa78: je     b64 <tail_ipv6_policy+0xb64> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa78, 0xb64, x86_l_b64);
x86_l_a7e:
	/* 0xa7e: movzx  eax,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_a81:
	/* 0xa81: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_a84:
	/* 0xa84: jne    ab4 <tail_ipv6_policy+0xab4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa84, 0xab4, x86_l_ab4);
x86_l_a86:
	/* 0xa86: jmp    b64 <tail_ipv6_policy+0xb64> */
	X86_SIM_X86_JMP(0xa86, 0xb64, x86_l_b64);
x86_l_a8b:
	/* 0xa8b: mov    r15d,0xffffff4b */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967115ULL);
x86_l_a91:
	/* 0xa91: jmp    4a0 <tail_ipv6_policy+0x4a0> */
	X86_SIM_X86_JMP(0xa91, 0x4a0, x86_l_4a0);
x86_l_a96:
	/* 0xa96: mov    r15d,0xffffff43 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967107ULL);
x86_l_a9c:
	/* 0xa9c: mov    dil,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_8, 1ULL);
x86_l_a9f:
	/* 0xa9f: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_aa2:
	/* 0xaa2: mov    edx,DWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_aa6:
	/* 0xaa6: mov    esi,DWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_aad:
	/* 0xaad: jmp    b8c <tail_ipv6_policy+0xb8c> */
	X86_SIM_X86_JMP(0xaad, 0xb8c, x86_l_b8c);
x86_l_ab2:
	/* 0xab2: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ab4:
	/* 0xab4: mov    WORD PTR [rsp+0x88],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_abc:
	/* 0xabc: mov    rdi,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_auth_map)));
x86_l_ac3:
	/* 0xac3: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_acb:
	/* 0xacb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ad0:
	/* 0xad0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ad2:
	/* 0xad2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ad5:
	/* 0xad5: je     b1d <tail_ipv6_policy+0xb1d> */
	X86_SIM_X86_JCC(X86_CC_E, 0xad5, 0xb1d, x86_l_b1d);
x86_l_ad7:
	/* 0xad7: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_ada:
	/* 0xada: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_add:
	/* 0xadd: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_ae2:
	/* 0xae2: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ae4:
	/* 0xae4: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_ae6:
	/* 0xae6: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_ae9:
	/* 0xae9: shr    r12,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_aed:
	/* 0xaed: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_af5:
	/* 0xaf5: mov    rdi,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_runtime_config)));
x86_l_afc:
	/* 0xafc: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b01:
	/* 0xb01: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b06:
	/* 0xb06: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b08:
	/* 0xb08: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b0b:
	/* 0xb0b: je     1e56 <tail_ipv6_policy+0x1e56> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb0b, 0x1e56, x86_l_1e56);
x86_l_b11:
	/* 0xb11: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b14:
	/* 0xb14: add    rax,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_b17:
	/* 0xb17: cmp    rax,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_b1b:
	/* 0xb1b: jb     b64 <tail_ipv6_policy+0xb64> */
	X86_SIM_X86_JCC(X86_CC_B, 0xb1b, 0xb64, x86_l_b64);
x86_l_b1d:
	/* 0xb1d: mov    DWORD PTR [rsp+0x20],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953474ULL);
x86_l_b25:
	/* 0xb25: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_b2d:
	/* 0xb2d: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_b32:
	/* 0xb32: mov    eax,DWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_b39:
	/* 0xb39: mov    DWORD PTR [rsp+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_b3d:
	/* 0xb3d: mov    rsi,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_signals)));
x86_l_b44:
	/* 0xb44: lea    rcx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b49:
	/* 0xb49: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_b4e:
	/* 0xb4e: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_b53:
	/* 0xb53: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_b56:
	/* 0xb56: mov    r8d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 16ULL);
x86_l_b5c:
	/* 0xb5c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b5e:
	/* 0xb5e: mov    r15d,0xffffff43 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967107ULL);
x86_l_b64:
	/* 0xb64: mov    r12d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_b69:
	/* 0xb69: mov    edx,DWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_b6d:
	/* 0xb6d: mov    esi,DWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_b74:
	/* 0xb74: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_b77:
	/* 0xb77: setne  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_NE);
x86_l_b7b:
	/* 0xb7b: cmp    DWORD PTR [rsp+0xa8],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 721554505729ULL);
x86_l_b83:
	/* 0xb83: je     5b3 <tail_ipv6_policy+0x5b3> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb83, 0x5b3, x86_l_5b3);
x86_l_b89:
	/* 0xb89: mov    r8d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R13, X86_WIDTH_32);
x86_l_b8c:
	/* 0xb8c: movzx  r9d,WORD PTR [r14+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_b91:
	/* 0xb91: movzx  r10d,BYTE PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 36ULL);
x86_l_b96:
	/* 0xb96: mov    r12d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b99:
	/* 0xb99: mov    rax,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_ba0:
	/* 0xba0: mov    ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ba2:
	/* 0xba2: cmp    r12d,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_ba5:
	/* 0xba5: cmovb  ebp,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R12, X86_WIDTH_32, X86_CC_B);
x86_l_ba9:
	/* 0xba9: mov    QWORD PTR [rsp+0x60],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860418ULL);
x86_l_bb2:
	/* 0xbb2: mov    rax,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_policy_verdict_log_filter)));
x86_l_bb9:
	/* 0xbb9: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bbb:
	/* 0xbbb: mov    BYTE PTR [rsp+0x20],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 137438953473ULL);
x86_l_bc0:
	/* 0xbc0: movzx  ecx,BYTE PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 32ULL);
x86_l_bc5:
	/* 0xbc5: test   eax,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_bc7:
	/* 0xbc7: je     e9b <tail_ipv6_policy+0xe9b> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbc7, 0xe9b, x86_l_e9b);
x86_l_bcd:
	/* 0xbcd: mov    BYTE PTR [rsp+0x7c],dil */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_bd2:
	/* 0xbd2: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_bd5:
	/* 0xbd5: movzx  edi,WORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 24ULL);
x86_l_bda:
	/* 0xbda: cmovne edi,r15d */
	X86_SIM_L_EXEC_CMOV(X86_RDI, X86_R15, X86_WIDTH_32, X86_CC_NE);
x86_l_bde:
	/* 0xbde: mov    rax,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_events_map_rate_limit)));
x86_l_be5:
	/* 0xbe5: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_be8:
	/* 0xbe8: je     e00 <tail_ipv6_policy+0xe00> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbe8, 0xe00, x86_l_e00);
x86_l_bee:
	/* 0xbee: mov    DWORD PTR [rsp+0xc8],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_bf5:
	/* 0xbf5: mov    BYTE PTR [rsp+0x17],r10b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R10, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 23ULL);
x86_l_bfa:
	/* 0xbfa: mov    WORD PTR [rsp+0x5e],r9w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 94ULL);
x86_l_c00:
	/* 0xc00: mov    DWORD PTR [rsp+0xcc],r8d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_c08:
	/* 0xc08: mov    DWORD PTR [rsp+0xb0],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_c0f:
	/* 0xc0f: mov    DWORD PTR [rsp+0x70],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_c13:
	/* 0xc13: mov    DWORD PTR [rsp+0x8],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c18:
	/* 0xc18: mov    rcx,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_events_map_burst_limit)));
x86_l_c1f:
	/* 0xc1f: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c21:
	/* 0xc21: mov    QWORD PTR [rsp+0x130],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_c29:
	/* 0xc29: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c2b:
	/* 0xc2b: mov    QWORD PTR [rsp+0x128],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_c33:
	/* 0xc33: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_c38:
	/* 0xc38: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c3a:
	/* 0xc3a: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_c3c:
	/* 0xc3c: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_c3f:
	/* 0xc3f: mov    eax,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_c43:
	/* 0xc43: mov    DWORD PTR [rsp+0xb8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_c4a:
	/* 0xc4a: mov    rdi,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit_metrics)));
x86_l_c51:
	/* 0xc51: lea    rsi,[rsp+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_c59:
	/* 0xc59: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c5e:
	/* 0xc5e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c60:
	/* 0xc60: mov    QWORD PTR [rsp+0x120],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_c68:
	/* 0xc68: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c6b:
	/* 0xc6b: jne    ca9 <tail_ipv6_policy+0xca9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xc6b, 0xca9, x86_l_ca9);
x86_l_c6d:
	/* 0xc6d: mov    QWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_c79:
	/* 0xc79: mov    rdi,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit_metrics)));
x86_l_c80:
	/* 0xc80: lea    rsi,[rsp+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_c88:
	/* 0xc88: lea    rdx,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_c90:
	/* 0xc90: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_c95:
	/* 0xc95: mov    QWORD PTR [rsp+0x120],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_c9d:
	/* 0xc9d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c9f:
	/* 0xc9f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ca1:
	/* 0xca1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ca3:
	/* 0xca3: js     17d7 <tail_ipv6_policy+0x17d7> */
	X86_SIM_X86_JCC(X86_CC_S, 0xca3, 0x17d7, x86_l_17d7);
x86_l_ca9:
	/* 0xca9: mov    rdi,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit)));
x86_l_cb0:
	/* 0xcb0: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_cb5:
	/* 0xcb5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_cba:
	/* 0xcba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cbc:
	/* 0xcbc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_cbf:
	/* 0xcbf: je     d5e <tail_ipv6_policy+0xd5e> */
	X86_SIM_X86_JCC(X86_CC_E, 0xcbf, 0xd5e, x86_l_d5e);
x86_l_cc5:
	/* 0xcc5: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cc8:
	/* 0xcc8: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_ccb:
	/* 0xccb: sub    rsi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_cce:
	/* 0xcce: cmp    rsi,0x3b9aca00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 1000000000ULL);
x86_l_cd5:
	/* 0xcd5: jbe    dc1 <tail_ipv6_policy+0xdc1> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xcd5, 0xdc1, x86_l_dc1);
x86_l_cdb:
	/* 0xcdb: mov    rdx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_cde:
	/* 0xcde: shr    rdx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_ce2:
	/* 0xce2: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_cec:
	/* 0xcec: mulx   rcx,rcx,rcx */
	X86_SIM_L_EXEC_MULX(X86_RCX, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_cf1:
	/* 0xcf1: shr    rcx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_cf5:
	/* 0xcf5: imul   rdx,rcx,0x3b9aca00 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RDX, X86_RCX, X86_WIDTH_64, 1000000000ULL);
x86_l_cfc:
	/* 0xcfc: imul   rcx,QWORD PTR [rsp+0x128] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 296ULL);
x86_l_d05:
	/* 0xd05: add    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_d09:
	/* 0xd09: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d0d:
	/* 0xd0d: sub    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_d10:
	/* 0xd10: add    r13,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_d13:
	/* 0xd13: mov    QWORD PTR [rax],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d16:
	/* 0xd16: mov    r11,QWORD PTR [rsp+0x130] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 304ULL);
x86_l_d1e:
	/* 0xd1e: cmp    rcx,r11 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R11, X86_WIDTH_64);
x86_l_d21:
	/* 0xd21: mov    r13d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d26:
	/* 0xd26: mov    edx,DWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_d2a:
	/* 0xd2a: mov    esi,DWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_d31:
	/* 0xd31: mov    r8d,DWORD PTR [rsp+0xcc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_d39:
	/* 0xd39: movzx  r9d,WORD PTR [rsp+0x5e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 94ULL);
x86_l_d3f:
	/* 0xd3f: movzx  r10d,BYTE PTR [rsp+0x17] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 23ULL);
x86_l_d45:
	/* 0xd45: mov    edi,DWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_d4c:
	/* 0xd4c: jbe    df0 <tail_ipv6_policy+0xdf0> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xd4c, 0xdf0, x86_l_df0);
x86_l_d52:
	/* 0xd52: mov    QWORD PTR [rax+0x8],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d56:
	/* 0xd56: mov    rcx,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R11, X86_WIDTH_64);
x86_l_d59:
	/* 0xd59: jmp    df0 <tail_ipv6_policy+0xdf0> */
	X86_SIM_X86_JMP(0xd59, 0xdf0, x86_l_df0);
x86_l_d5e:
	/* 0xd5e: mov    QWORD PTR [rsp+0x20],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d63:
	/* 0xd63: mov    rax,QWORD PTR [rsp+0x128] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_d6b:
	/* 0xd6b: dec    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_d6e:
	/* 0xd6e: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_d73:
	/* 0xd73: mov    rdi,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit)));
x86_l_d7a:
	/* 0xd7a: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_d7f:
	/* 0xd7f: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d84:
	/* 0xd84: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_d89:
	/* 0xd89: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d8b:
	/* 0xd8b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d8d:
	/* 0xd8d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_d8f:
	/* 0xd8f: mov    r13d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d94:
	/* 0xd94: mov    edx,DWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_d98:
	/* 0xd98: mov    esi,DWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_d9f:
	/* 0xd9f: mov    r8d,DWORD PTR [rsp+0xcc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_da7:
	/* 0xda7: movzx  r9d,WORD PTR [rsp+0x5e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 94ULL);
x86_l_dad:
	/* 0xdad: movzx  r10d,BYTE PTR [rsp+0x17] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 23ULL);
x86_l_db3:
	/* 0xdb3: mov    edi,DWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_dba:
	/* 0xdba: jns    e00 <tail_ipv6_policy+0xe00> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xdba, 0xe00, x86_l_e00);
x86_l_dbc:
	/* 0xdbc: jmp    17cc <tail_ipv6_policy+0x17cc> */
	X86_SIM_X86_JMP(0xdbc, 0x17cc, x86_l_17cc);
x86_l_dc1:
	/* 0xdc1: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_dc5:
	/* 0xdc5: mov    r13d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_dca:
	/* 0xdca: mov    edx,DWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_dce:
	/* 0xdce: mov    esi,DWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_dd5:
	/* 0xdd5: mov    r8d,DWORD PTR [rsp+0xcc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 204ULL);
x86_l_ddd:
	/* 0xddd: movzx  r9d,WORD PTR [rsp+0x5e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 94ULL);
x86_l_de3:
	/* 0xde3: movzx  r10d,BYTE PTR [rsp+0x17] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 23ULL);
x86_l_de9:
	/* 0xde9: mov    edi,DWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_df0:
	/* 0xdf0: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_df3:
	/* 0xdf3: je     17cc <tail_ipv6_policy+0x17cc> */
	X86_SIM_X86_JCC(X86_CC_E, 0xdf3, 0x17cc, x86_l_17cc);
x86_l_df9:
	/* 0xdf9: dec    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_dfc:
	/* 0xdfc: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e00:
	/* 0xe00: mov    rax,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_endpoint_id)));
x86_l_e07:
	/* 0xe07: movzx  eax,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_e0a:
	/* 0xe0a: mov    ecx,DWORD PTR [rbx+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_e0d:
	/* 0xe0d: shl    dl,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_e10:
	/* 0xe10: mov    BYTE PTR [rsp+0x3f],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 270582939648ULL);
x86_l_e15:
	/* 0xe15: mov    WORD PTR [rsp+0x3d],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 261993005056ULL);
x86_l_e1c:
	/* 0xe1c: mov    WORD PTR [rsp+0x20],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 137438953477ULL);
x86_l_e23:
	/* 0xe23: mov    WORD PTR [rsp+0x22],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_e28:
	/* 0xe28: mov    DWORD PTR [rsp+0x24],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_e2c:
	/* 0xe2c: mov    DWORD PTR [rsp+0x28],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_e31:
	/* 0xe31: mov    WORD PTR [rsp+0x2c],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_e36:
	/* 0xe36: mov    WORD PTR [rsp+0x2e],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 197568495617ULL);
x86_l_e3d:
	/* 0xe3d: mov    eax,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_e41:
	/* 0xe41: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e45:
	/* 0xe45: mov    DWORD PTR [rsp+0x34],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_e49:
	/* 0xe49: or     dl,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_8, X86_ALU_OR, 5ULL);
x86_l_e4c:
	/* 0xe4c: movbe  WORD PTR [rsp+0x38],r9w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R9, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_e54:
	/* 0xe54: mov    BYTE PTR [rsp+0x3a],r10b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R10, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_e59:
	/* 0xe59: mov    BYTE PTR [rsp+0x3b],dl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 59ULL);
x86_l_e5d:
	/* 0xe5d: mov    BYTE PTR [rsp+0x3c],r8b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_e62:
	/* 0xe62: mov    DWORD PTR [rsp+0x40],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_e66:
	/* 0xe66: mov    DWORD PTR [rsp+0x44],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 292057776128ULL);
x86_l_e6e:
	/* 0xe6e: shl    rbp,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_e72:
	/* 0xe72: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_e77:
	/* 0xe77: or     rdx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBP, X86_WIDTH_64, X86_ALU_OR);
x86_l_e7a:
	/* 0xe7a: mov    rsi,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_events)));
x86_l_e81:
	/* 0xe81: lea    rcx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e86:
	/* 0xe86: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_e8b:
	/* 0xe8b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_e8e:
	/* 0xe8e: mov    r8d,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 40ULL);
x86_l_e94:
	/* 0xe94: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e96:
	/* 0xe96: movzx  edi,BYTE PTR [rsp+0x7c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 124ULL);
x86_l_e9b:
	/* 0xe9b: test   dil,dil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_8);
x86_l_e9e:
	/* 0xe9e: je     eb8 <tail_ipv6_policy+0xeb8> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe9e, 0xeb8, x86_l_eb8);
x86_l_ea0:
	/* 0xea0: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_ea3:
	/* 0xea3: mov    r12d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_ea8:
	/* 0xea8: mov    r14d,DWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_ead:
	/* 0xead: jne    184 <tail_ipv6_policy+0x184> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xead, 0x184, x86_l_184);
x86_l_eb3:
	/* 0xeb3: jmp    1d9c <tail_ipv6_policy+0x1d9c> */
	X86_SIM_X86_JMP(0xeb3, 0x1d9c, x86_l_1d9c);
x86_l_eb8:
	/* 0xeb8: cmp    DWORD PTR [rsp+0xa8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_ec0:
	/* 0xec0: je     ecc <tail_ipv6_policy+0xecc> */
	X86_SIM_X86_JCC(X86_CC_E, 0xec0, 0xecc, x86_l_ecc);
x86_l_ec2:
	/* 0xec2: mov    r12d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_ec7:
	/* 0xec7: jmp    113e <tail_ipv6_policy+0x113e> */
	X86_SIM_X86_JMP(0xec7, 0x113e, x86_l_113e);
x86_l_ecc:
	/* 0xecc: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ece:
	/* 0xece: cmp    DWORD PTR [rsp+0xc4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 841813590016ULL);
x86_l_ed6:
	/* 0xed6: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_ed9:
	/* 0xed9: shl    eax,0xa */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 10ULL);
x86_l_edc:
	/* 0xedc: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ede:
	/* 0xede: cmp    WORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_ee4:
	/* 0xee4: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_ee7:
	/* 0xee7: shl    ecx,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 6ULL);
x86_l_eea:
	/* 0xeea: cmp    BYTE PTR [r14+0x24],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 154618822662ULL);
x86_l_eef:
	/* 0xeef: mov    edx,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_ef3:
	/* 0xef3: jne    efe <tail_ipv6_policy+0xefe> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xef3, 0xefe, x86_l_efe);
x86_l_ef5:
	/* 0xef5: mov    rsi,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_ct6_global)));
x86_l_efc:
	/* 0xefc: jmp    f05 <tail_ipv6_policy+0xf05> */
	X86_SIM_X86_JMP(0xefc, 0xf05, x86_l_f05);
x86_l_efe:
	/* 0xefe: mov    rsi,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_ct_any6_global)));
x86_l_f05:
	/* 0xf05: mov    QWORD PTR [rsp+0x8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f0a:
	/* 0xf0a: mov    r15d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_32);
x86_l_f0d:
	/* 0xf0d: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_f16:
	/* 0xf16: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_f1f:
	/* 0xf1f: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_f28:
	/* 0xf28: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_f31:
	/* 0xf31: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_f3a:
	/* 0xf3a: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_f43:
	/* 0xf43: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_f4c:
	/* 0xf4c: movzx  ebp,BYTE PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 36ULL);
x86_l_f51:
	/* 0xf51: mov    DWORD PTR [rsp+0x4c],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_f55:
	/* 0xf55: mov    WORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_f5c:
	/* 0xf5c: movzx  ecx,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_f5f:
	/* 0xf5f: movzx  eax,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_f62:
	/* 0xf62: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_f6b:
	/* 0xf6b: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_f74:
	/* 0xf74: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_f76:
	/* 0xf76: mov    WORD PTR [rsp+0x44],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_f7b:
	/* 0xf7b: mov    r12,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_f82:
	/* 0xf82: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f87:
	/* 0xf87: je     f9a <tail_ipv6_policy+0xf9a> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf87, 0xf9a, x86_l_f9a);
x86_l_f89:
	/* 0xf89: mov    rcx,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_f90:
	/* 0xf90: imul   r13d,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_f94:
	/* 0xf94: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_f98:
	/* 0xf98: jmp    fa0 <tail_ipv6_policy+0xfa0> */
	X86_SIM_X86_JMP(0xf98, 0xfa0, x86_l_fa0);
x86_l_f9a:
	/* 0xf9a: mov    r13d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 60ULL);
x86_l_fa0:
	/* 0xfa0: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_fa4:
	/* 0xfa4: jne    fc9 <tail_ipv6_policy+0xfc9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xfa4, 0xfc9, x86_l_fc9);
x86_l_fa6:
	/* 0xfa6: mov    WORD PTR [rsp+0x44],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_fab:
	/* 0xfab: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fb0:
	/* 0xfb0: je     fc3 <tail_ipv6_policy+0xfc3> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfb0, 0xfc3, x86_l_fc3);
x86_l_fb2:
	/* 0xfb2: mov    rax,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_fb9:
	/* 0xfb9: imul   r13d,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_fbd:
	/* 0xfbd: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_fc1:
	/* 0xfc1: jmp    fc9 <tail_ipv6_policy+0xfc9> */
	X86_SIM_X86_JMP(0xfc1, 0xfc9, x86_l_fc9);
x86_l_fc3:
	/* 0xfc3: mov    r13d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 60ULL);
x86_l_fc9:
	/* 0xfc9: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fce:
	/* 0xfce: je     fdf <tail_ipv6_policy+0xfdf> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfce, 0xfdf, x86_l_fdf);
x86_l_fd0:
	/* 0xfd0: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_fd5:
	/* 0xfd5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_fd7:
	/* 0xfd7: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_fd9:
	/* 0xfd9: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_fdd:
	/* 0xfdd: jmp    1002 <tail_ipv6_policy+0x1002> */
	X86_SIM_X86_JMP(0xfdd, 0x1002, x86_l_1002);
x86_l_fdf:
	/* 0xfdf: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_fe4:
	/* 0xfe4: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_fe6:
	/* 0xfe6: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_fe8:
	/* 0xfe8: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_fec:
	/* 0xfec: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_ff6:
	/* 0xff6: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_ff9:
	/* 0xff9: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_ffe:
	/* 0xffe: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_1002:
	/* 0x1002: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_1006:
	/* 0x1006: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_1009:
	/* 0x1009: add    r13d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_100c:
	/* 0x100c: mov    DWORD PTR [rsp+0x40],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1011:
	/* 0x1011: movzx  edx,BYTE PTR [rsp+0x4b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 75ULL);
x86_l_1016:
	/* 0x1016: mov    esi,DWORD PTR [rsp+0x54] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_101a:
	/* 0x101a: add    cl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_8, X86_ALU_ADD);
x86_l_101c:
	/* 0x101c: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1021:
	/* 0x1021: je     1034 <tail_ipv6_policy+0x1034> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1021, 0x1034, x86_l_1034);
x86_l_1023:
	/* 0x1023: mov    rdi,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_102a:
	/* 0x102a: mov    edi,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_102c:
	/* 0x102c: lea    edi,[rdi+rdi*4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_102f:
	/* 0x102f: shr    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1032:
	/* 0x1032: jmp    1039 <tail_ipv6_policy+0x1039> */
	X86_SIM_X86_JMP(0x1032, 0x1039, x86_l_1039);
x86_l_1034:
	/* 0x1034: mov    edi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 5ULL);
x86_l_1039:
	/* 0x1039: mov    r12d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_103e:
	/* 0x103e: mov    r13d,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R15, X86_WIDTH_32);
x86_l_1041:
	/* 0x1041: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1043:
	/* 0x1043: or     cl,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_1045:
	/* 0x1045: cmp    edi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_1047:
	/* 0x1047: jb     104d <tail_ipv6_policy+0x104d> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1047, 0x104d, x86_l_104d);
x86_l_1049:
	/* 0x1049: cmp    dl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_8);
x86_l_104b:
	/* 0x104b: je     105e <tail_ipv6_policy+0x105e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x104b, 0x105e, x86_l_105e);
x86_l_104d:
	/* 0x104d: mov    BYTE PTR [rsp+0x4b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 75ULL);
x86_l_1051:
	/* 0x1051: mov    DWORD PTR [rsp+0x54],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_1055:
	/* 0x1055: mov    rax,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_105c:
	/* 0x105c: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_105e:
	/* 0x105e: mov    QWORD PTR [rsp+0x9e],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 678604832768ULL);
x86_l_106a:
	/* 0x106a: mov    QWORD PTR [rsp+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_1076:
	/* 0x1076: mov    QWORD PTR [rsp+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_1082:
	/* 0x1082: mov    QWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_108e:
	/* 0x108e: mov    QWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_109a:
	/* 0x109a: mov    BYTE PTR [rsp+0xa4],0x3a */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 704374636602ULL);
x86_l_10a2:
	/* 0x10a2: movzx  eax,BYTE PTR [r14+0x25] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 37ULL);
x86_l_10a7:
	/* 0x10a7: or     al,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_OR, 2ULL);
x86_l_10a9:
	/* 0x10a9: mov    BYTE PTR [rsp+0xa5],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 165ULL);
x86_l_10b0:
	/* 0x10b0: mov    rax,QWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10b4:
	/* 0x10b4: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_10bc:
	/* 0x10bc: mov    rax,QWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10bf:
	/* 0x10bf: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_10c7:
	/* 0x10c7: mov    rax,QWORD PTR [r14+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_10cb:
	/* 0x10cb: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_10d3:
	/* 0x10d3: mov    rax,QWORD PTR [r14+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10d7:
	/* 0x10d7: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_10df:
	/* 0x10df: mov    rdi,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct_any6_global)));
x86_l_10e6:
	/* 0x10e6: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_10ee:
	/* 0x10ee: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_10f3:
	/* 0x10f3: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_10f8:
	/* 0x10f8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10fa:
	/* 0x10fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10fc:
	/* 0x10fc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_10fe:
	/* 0x10fe: js     179f <tail_ipv6_policy+0x179f> */
	X86_SIM_X86_JCC(X86_CC_S, 0x10fe, 0x179f, x86_l_179f);
x86_l_1104:
	/* 0x1104: mov    rax,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_110b:
	/* 0x110b: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_110e:
	/* 0x110e: je     1120 <tail_ipv6_policy+0x1120> */
	X86_SIM_X86_JCC(X86_CC_E, 0x110e, 0x1120, x86_l_1120);
x86_l_1110:
	/* 0x1110: mov    QWORD PTR [rsp+0x30],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430209ULL);
x86_l_1119:
	/* 0x1119: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_111b:
	/* 0x111b: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1120:
	/* 0x1120: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1125:
	/* 0x1125: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_112a:
	/* 0x112a: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_112f:
	/* 0x112f: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_1132:
	/* 0x1132: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1134:
	/* 0x1134: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1136:
	/* 0x1136: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1138:
	/* 0x1138: js     179f <tail_ipv6_policy+0x179f> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1138, 0x179f, x86_l_179f);
x86_l_113e:
	/* 0x113e: cmp    WORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1144:
	/* 0x1144: je     1a00 <tail_ipv6_policy+0x1a00> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1144, 0x1a00, x86_l_1a00);
x86_l_114a:
	/* 0x114a: mov    rax,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_security_label)));
x86_l_1151:
	/* 0x1151: mov    r15d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1154:
	/* 0x1154: mov    rax,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_tracing_ip_option_type)));
x86_l_115b:
	/* 0x115b: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_115e:
	/* 0x115e: je     1185 <tail_ipv6_policy+0x1185> */
	X86_SIM_X86_JCC(X86_CC_E, 0x115e, 0x1185, x86_l_1185);
x86_l_1160:
	/* 0x1160: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1168:
	/* 0x1168: mov    rdi,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_percpu_trace_id)));
x86_l_116f:
	/* 0x116f: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1174:
	/* 0x1174: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1179:
	/* 0x1179: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_117b:
	/* 0x117b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_117e:
	/* 0x117e: je     1185 <tail_ipv6_policy+0x1185> */
	X86_SIM_X86_JCC(X86_CC_E, 0x117e, 0x1185, x86_l_1185);
x86_l_1180:
	/* 0x1180: mov    r8,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1183:
	/* 0x1183: jmp    1188 <tail_ipv6_policy+0x1188> */
	X86_SIM_X86_JMP(0x1183, 0x1188, x86_l_1188);
x86_l_1185:
	/* 0x1185: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1188:
	/* 0x1188: mov    ebp,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_118a:
	/* 0x118a: mov    QWORD PTR [rsp+0xb8],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982466ULL);
x86_l_1196:
	/* 0x1196: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_119f:
	/* 0x119f: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_11a8:
	/* 0x11a8: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_11b1:
	/* 0x11b1: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_11ba:
	/* 0x11ba: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_11c3:
	/* 0x11c3: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_11cc:
	/* 0x11cc: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_11d5:
	/* 0x11d5: cmp    DWORD PTR [rsp+0xc0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_11dd:
	/* 0x11dd: je     145b <tail_ipv6_policy+0x145b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11dd, 0x145b, x86_l_145b);
x86_l_11e3:
	/* 0x11e3: mov    rax,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_events_map_rate_limit)));
x86_l_11ea:
	/* 0x11ea: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11ed:
	/* 0x11ed: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_11ef:
	/* 0x11ef: je     1397 <tail_ipv6_policy+0x1397> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11ef, 0x1397, x86_l_1397);
x86_l_11f5:
	/* 0x11f5: mov    QWORD PTR [rsp+0xf8],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_11fd:
	/* 0x11fd: mov    DWORD PTR [rsp+0x7c],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_1202:
	/* 0x1202: mov    DWORD PTR [rsp+0x8],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1207:
	/* 0x1207: mov    rcx,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_events_map_burst_limit)));
x86_l_120e:
	/* 0x120e: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1210:
	/* 0x1210: mov    QWORD PTR [rsp+0xb0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1218:
	/* 0x1218: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_121a:
	/* 0x121a: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_121f:
	/* 0x121f: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1224:
	/* 0x1224: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1226:
	/* 0x1226: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1228:
	/* 0x1228: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_122b:
	/* 0x122b: mov    eax,DWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1232:
	/* 0x1232: mov    DWORD PTR [rsp+0xac],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_1239:
	/* 0x1239: mov    rdi,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit_metrics)));
x86_l_1240:
	/* 0x1240: lea    rsi,[rsp+0xac] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_1248:
	/* 0x1248: mov    r13d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 1ULL);
x86_l_124e:
	/* 0x124e: call   r13 */
	X86_SIM_BPF_CALL_REG(X86_R13);
x86_l_1251:
	/* 0x1251: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1254:
	/* 0x1254: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1257:
	/* 0x1257: jne    128a <tail_ipv6_policy+0x128a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1257, 0x128a, x86_l_128a);
x86_l_1259:
	/* 0x1259: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_1262:
	/* 0x1262: mov    rdi,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit_metrics)));
x86_l_1269:
	/* 0x1269: lea    rsi,[rsp+0xac] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_1271:
	/* 0x1271: lea    r15,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1276:
	/* 0x1276: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_127b:
	/* 0x127b: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_127e:
	/* 0x127e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1280:
	/* 0x1280: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1282:
	/* 0x1282: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1284:
	/* 0x1284: js     1795 <tail_ipv6_policy+0x1795> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1284, 0x1795, x86_l_1795);
x86_l_128a:
	/* 0x128a: mov    rdi,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit)));
x86_l_1291:
	/* 0x1291: lea    rsi,[rsp+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1299:
	/* 0x1299: call   r13 */
	X86_SIM_BPF_CALL_REG(X86_R13);
x86_l_129c:
	/* 0x129c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_129f:
	/* 0x129f: je     1317 <tail_ipv6_policy+0x1317> */
	X86_SIM_X86_JCC(X86_CC_E, 0x129f, 0x1317, x86_l_1317);
x86_l_12a1:
	/* 0x12a1: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12a4:
	/* 0x12a4: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_12a7:
	/* 0x12a7: sub    rsi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_12aa:
	/* 0x12aa: cmp    rsi,0x3b9aca00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 1000000000ULL);
x86_l_12b1:
	/* 0x12b1: jbe    136a <tail_ipv6_policy+0x136a> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x12b1, 0x136a, x86_l_136a);
x86_l_12b7:
	/* 0x12b7: mov    rdx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_12ba:
	/* 0x12ba: shr    rdx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_12be:
	/* 0x12be: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_12c8:
	/* 0x12c8: mulx   rcx,rcx,rcx */
	X86_SIM_L_EXEC_MULX(X86_RCX, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_12cd:
	/* 0x12cd: shr    rcx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_12d1:
	/* 0x12d1: imul   rdx,rcx,0x3b9aca00 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RDX, X86_RCX, X86_WIDTH_64, 1000000000ULL);
x86_l_12d8:
	/* 0x12d8: imul   rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 112ULL);
x86_l_12de:
	/* 0x12de: add    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_12e2:
	/* 0x12e2: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12e6:
	/* 0x12e6: sub    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_12e9:
	/* 0x12e9: add    r12,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_12ec:
	/* 0x12ec: mov    QWORD PTR [rax],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12ef:
	/* 0x12ef: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_12f7:
	/* 0x12f7: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_12fa:
	/* 0x12fa: mov    r12d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_12ff:
	/* 0x12ff: mov    r13d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1304:
	/* 0x1304: mov    r8,QWORD PTR [rsp+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_130c:
	/* 0x130c: jbe    1380 <tail_ipv6_policy+0x1380> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x130c, 0x1380, x86_l_1380);
x86_l_130e:
	/* 0x130e: mov    QWORD PTR [rax+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1312:
	/* 0x1312: mov    rcx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1315:
	/* 0x1315: jmp    1380 <tail_ipv6_policy+0x1380> */
	X86_SIM_X86_JMP(0x1315, 0x1380, x86_l_1380);
x86_l_1317:
	/* 0x1317: mov    QWORD PTR [rsp+0x80],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_131f:
	/* 0x131f: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1324:
	/* 0x1324: dec    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_1327:
	/* 0x1327: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_132f:
	/* 0x132f: mov    rdi,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit)));
x86_l_1336:
	/* 0x1336: lea    rsi,[rsp+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_133e:
	/* 0x133e: lea    rdx,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1346:
	/* 0x1346: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_134b:
	/* 0x134b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_134d:
	/* 0x134d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_134f:
	/* 0x134f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1351:
	/* 0x1351: mov    r12d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1356:
	/* 0x1356: mov    r13d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_135b:
	/* 0x135b: mov    r8,QWORD PTR [rsp+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_1363:
	/* 0x1363: jns    1390 <tail_ipv6_policy+0x1390> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1363, 0x1390, x86_l_1390);
x86_l_1365:
	/* 0x1365: jmp    1792 <tail_ipv6_policy+0x1792> */
	X86_SIM_X86_JMP(0x1365, 0x1792, x86_l_1792);
x86_l_136a:
	/* 0x136a: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_136e:
	/* 0x136e: mov    r12d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1373:
	/* 0x1373: mov    r13d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1378:
	/* 0x1378: mov    r8,QWORD PTR [rsp+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_1380:
	/* 0x1380: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_1383:
	/* 0x1383: je     1792 <tail_ipv6_policy+0x1792> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1383, 0x1792, x86_l_1792);
x86_l_1389:
	/* 0x1389: dec    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_138c:
	/* 0x138c: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1390:
	/* 0x1390: mov    ecx,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1392:
	/* 0x1392: mov    r15d,DWORD PTR [rsp+0x7c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_1397:
	/* 0x1397: mov    eax,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_139b:
	/* 0x139b: mov    edx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_139d:
	/* 0x139d: rol    dx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_13a1:
	/* 0x13a1: mov    rsi,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_13a8:
	/* 0x13a8: mov    eax,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13aa:
	/* 0x13aa: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13ac:
	/* 0x13ac: mov    edi,DWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_13b3:
	/* 0x13b3: cmp    esi,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDI, X86_WIDTH_32);
x86_l_13b5:
	/* 0x13b5: cmovne eax,edi */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RDI, X86_WIDTH_32, X86_CC_NE);
x86_l_13b8:
	/* 0x13b8: cmp    eax,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_13ba:
	/* 0x13ba: mov    rsi,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_endpoint_id)));
x86_l_13c1:
	/* 0x13c1: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_13c4:
	/* 0x13c4: cmovae eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_AE);
x86_l_13c7:
	/* 0x13c7: mov    ecx,DWORD PTR [rbx+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_13ca:
	/* 0x13ca: mov    WORD PTR [rsp+0x20],0x104 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 137438953732ULL);
x86_l_13d1:
	/* 0x13d1: mov    WORD PTR [rsp+0x22],si */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_13d6:
	/* 0x13d6: mov    DWORD PTR [rsp+0x24],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_13da:
	/* 0x13da: mov    DWORD PTR [rsp+0x28],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_13de:
	/* 0x13de: mov    WORD PTR [rsp+0x2c],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_13e3:
	/* 0x13e3: mov    WORD PTR [rsp+0x2e],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 197568495618ULL);
x86_l_13ea:
	/* 0x13ea: mov    DWORD PTR [rsp+0x30],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_13ef:
	/* 0x13ef: mov    DWORD PTR [rsp+0x34],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_13f4:
	/* 0x13f4: mov    WORD PTR [rsp+0x38],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_13f9:
	/* 0x13f9: mov    ecx,DWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1400:
	/* 0x1400: mov    BYTE PTR [rsp+0x3a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_1404:
	/* 0x1404: mov    BYTE PTR [rsp+0x3b],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 253403070465ULL);
x86_l_1409:
	/* 0x1409: mov    ecx,DWORD PTR [rsp+0x104] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 260ULL);
x86_l_1410:
	/* 0x1410: mov    DWORD PTR [rsp+0x3c],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_1414:
	/* 0x1414: mov    QWORD PTR [rsp+0x50],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1419:
	/* 0x1419: mov    rcx,QWORD PTR [rsp+0x110] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_1421:
	/* 0x1421: mov    QWORD PTR [rsp+0x48],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1426:
	/* 0x1426: mov    rcx,QWORD PTR [rsp+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_142e:
	/* 0x142e: mov    QWORD PTR [rsp+0x40],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1433:
	/* 0x1433: shl    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_1437:
	/* 0x1437: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_143c:
	/* 0x143c: or     rdx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_143f:
	/* 0x143f: mov    rsi,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_events)));
x86_l_1446:
	/* 0x1446: lea    rcx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_144b:
	/* 0x144b: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_1450:
	/* 0x1450: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1453:
	/* 0x1453: mov    r8d,0x38 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 56ULL);
x86_l_1459:
	/* 0x1459: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_145b:
	/* 0x145b: movzx  r12d,WORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_1460:
	/* 0x1460: mov    WORD PTR [rsp+0xf4],r12w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 244ULL);
x86_l_1469:
	/* 0x1469: mov    ebp,DWORD PTR [r14+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_146d:
	/* 0x146d: mov    DWORD PTR [rsp+0xf0],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_1474:
	/* 0x1474: mov    rax,QWORD PTR [r14+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1478:
	/* 0x1478: mov    QWORD PTR [rsp+0xe8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_1480:
	/* 0x1480: mov    rax,QWORD PTR [r14+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1484:
	/* 0x1484: mov    QWORD PTR [rsp+0xe0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_148c:
	/* 0x148c: mov    rax,QWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1490:
	/* 0x1490: mov    QWORD PTR [rsp+0xd8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_1498:
	/* 0x1498: mov    rax,QWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_149b:
	/* 0x149b: mov    QWORD PTR [rsp+0xd0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_14a3:
	/* 0x14a3: cmp    DWORD PTR [rsp+0xc4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 841813590016ULL);
x86_l_14ab:
	/* 0x14ab: je     14b9 <tail_ipv6_policy+0x14b9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14ab, 0x14b9, x86_l_14b9);
x86_l_14ad:
	/* 0x14ad: mov    eax,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_14b2:
	/* 0x14b2: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_14b5:
	/* 0x14b5: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14b7:
	/* 0x14b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14b9:
	/* 0x14b9: mov    rax,QWORD PTR [rip+0x1c5c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_tproxy)));
x86_l_14c0:
	/* 0x14c0: movzx  ecx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_14c3:
	/* 0x14c3: mov    edx,DWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_14c7:
	/* 0x14c7: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_14c9:
	/* 0x14c9: jne    14d5 <tail_ipv6_policy+0x14d5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x14c9, 0x14d5, x86_l_14d5);
x86_l_14cb:
	/* 0x14cb: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_14cd:
	/* 0x14cd: je     14d5 <tail_ipv6_policy+0x14d5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14cd, 0x14d5, x86_l_14d5);
x86_l_14cf:
	/* 0x14cf: or     BYTE PTR [rbx+0x9],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RBX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 38654705666ULL);
x86_l_14d3:
	/* 0x14d3: jmp    14e5 <tail_ipv6_policy+0x14e5> */
	X86_SIM_X86_JMP(0x14d3, 0x14e5, x86_l_14e5);
x86_l_14d5:
	/* 0x14d5: mov    ecx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_14d9:
	/* 0x14d9: shl    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_14dc:
	/* 0x14dc: or     ecx,0x200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_OR, 512ULL);
x86_l_14e2:
	/* 0x14e2: mov    DWORD PTR [rbx+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14e5:
	/* 0x14e5: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14e8:
	/* 0x14e8: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_14eb:
	/* 0x14eb: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_14ed:
	/* 0x14ed: jne    17b3 <tail_ipv6_policy+0x17b3> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x14ed, 0x17b3, x86_l_17b3);
x86_l_14f3:
	/* 0x14f3: cmp    WORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_14f9:
	/* 0x14f9: je     17b3 <tail_ipv6_policy+0x17b3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14f9, 0x17b3, x86_l_17b3);
x86_l_14ff:
	/* 0x14ff: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1501:
	/* 0x1501: je     17b3 <tail_ipv6_policy+0x17b3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1501, 0x17b3, x86_l_17b3);
x86_l_1507:
	/* 0x1507: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_1509:
	/* 0x1509: shr    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_150c:
	/* 0x150c: mov    WORD PTR [rsp+0xf0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_1514:
	/* 0x1514: mov    WORD PTR [rsp+0xf2],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 242ULL);
x86_l_151c:
	/* 0x151c: cmp    r12b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_8, 6ULL);
x86_l_1520:
	/* 0x1520: jne    1612 <tail_ipv6_policy+0x1612> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1520, 0x1612, x86_l_1612);
x86_l_1526:
	/* 0x1526: lea    rsi,[rsp+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_152e:
	/* 0x152e: mov    eax,0x63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 99ULL);
x86_l_1533:
	/* 0x1533: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1536:
	/* 0x1536: mov    edx,0x24 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 36ULL);
x86_l_153b:
	/* 0x153b: mov    rcx,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1542:
	/* 0x1542: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1545:
	/* 0x1545: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1547:
	/* 0x1547: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_154c:
	/* 0x154c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_154f:
	/* 0x154f: je     158d <tail_ipv6_policy+0x158d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x154f, 0x158d, x86_l_158d);
x86_l_1551:
	/* 0x1551: mov    ecx,DWORD PTR [rax+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1554:
	/* 0x1554: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1557:
	/* 0x1557: je     1583 <tail_ipv6_policy+0x1583> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1557, 0x1583, x86_l_1583);
x86_l_1559:
	/* 0x1559: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_155c:
	/* 0x155c: je     1583 <tail_ipv6_policy+0x1583> */
	X86_SIM_X86_JCC(X86_CC_E, 0x155c, 0x1583, x86_l_1583);
x86_l_155e:
	/* 0x155e: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1563:
	/* 0x1563: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1568:
	/* 0x1568: mov    eax,0x7c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 124ULL);
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
	/* 0x1574: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1576:
	/* 0x1576: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_157b:
	/* 0x157b: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_157d:
	/* 0x157d: je     17e1 <tail_ipv6_policy+0x17e1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x157d, 0x17e1, x86_l_17e1);
x86_l_1583:
	/* 0x1583: mov    ecx,0x56 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 86ULL);
x86_l_1588:
	/* 0x1588: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_158b:
	/* 0x158b: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_158d:
	/* 0x158d: mov    eax,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1591:
	/* 0x1591: mov    WORD PTR [rsp+0xf2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 242ULL);
x86_l_1599:
	/* 0x1599: mov    WORD PTR [rsp+0xf0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1030792151040ULL);
x86_l_15a3:
	/* 0x15a3: movabs rax,0x100000000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 72057594037927936ULL);
x86_l_15ad:
	/* 0x15ad: mov    QWORD PTR [rsp+0xe8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_15b5:
	/* 0x15b5: mov    QWORD PTR [rsp+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_15c1:
	/* 0x15c1: mov    QWORD PTR [rsp+0xd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 927712935936ULL);
x86_l_15cd:
	/* 0x15cd: mov    QWORD PTR [rsp+0xe0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 962072674304ULL);
x86_l_15d9:
	/* 0x15d9: lea    rsi,[rsp+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_15e1:
	/* 0x15e1: mov    eax,0x63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 99ULL);
x86_l_15e6:
	/* 0x15e6: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_15e9:
	/* 0x15e9: mov    edx,0x24 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 36ULL);
x86_l_15ee:
	/* 0x15ee: mov    rcx,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_15f5:
	/* 0x15f5: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15f8:
	/* 0x15f8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15fa:
	/* 0x15fa: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_15ff:
	/* 0x15ff: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1602:
	/* 0x1602: je     16c4 <tail_ipv6_policy+0x16c4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1602, 0x16c4, x86_l_16c4);
x86_l_1608:
	/* 0x1608: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_160d:
	/* 0x160d: jmp    1694 <tail_ipv6_policy+0x1694> */
	X86_SIM_X86_JMP(0x160d, 0x1694, x86_l_1694);
x86_l_1612:
	/* 0x1612: mov    eax,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1616:
	/* 0x1616: mov    WORD PTR [rsp+0xf2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 242ULL);
x86_l_161e:
	/* 0x161e: mov    WORD PTR [rsp+0xf0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 1030792151040ULL);
x86_l_1628:
	/* 0x1628: movabs rax,0x100000000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 72057594037927936ULL);
x86_l_1632:
	/* 0x1632: mov    QWORD PTR [rsp+0xe8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_163a:
	/* 0x163a: mov    QWORD PTR [rsp+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_1646:
	/* 0x1646: mov    QWORD PTR [rsp+0xd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 927712935936ULL);
x86_l_1652:
	/* 0x1652: mov    QWORD PTR [rsp+0xe0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 962072674304ULL);
x86_l_165e:
	/* 0x165e: cmp    r12b,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_8, 17ULL);
x86_l_1662:
	/* 0x1662: jne    16d1 <tail_ipv6_policy+0x16d1> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1662, 0x16d1, x86_l_16d1);
x86_l_1664:
	/* 0x1664: lea    rsi,[rsp+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_166c:
	/* 0x166c: mov    eax,0x55 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 85ULL);
x86_l_1671:
	/* 0x1671: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1674:
	/* 0x1674: mov    edx,0x24 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 36ULL);
x86_l_1679:
	/* 0x1679: mov    rcx,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1680:
	/* 0x1680: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1683:
	/* 0x1683: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1685:
	/* 0x1685: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_168a:
	/* 0x168a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_168d:
	/* 0x168d: je     16c4 <tail_ipv6_policy+0x16c4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x168d, 0x16c4, x86_l_16c4);
x86_l_168f:
	/* 0x168f: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1694:
	/* 0x1694: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1699:
	/* 0x1699: mov    eax,0x7c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 124ULL);
x86_l_169e:
	/* 0x169e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_16a1:
	/* 0x16a1: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16a3:
	/* 0x16a3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16a5:
	/* 0x16a5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_16a7:
	/* 0x16a7: mov    ebp,0xffffff4d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967117ULL);
x86_l_16ac:
	/* 0x16ac: cmove  ebp,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_16af:
	/* 0x16af: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_16b4:
	/* 0x16b4: mov    eax,0x56 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 86ULL);
x86_l_16b9:
	/* 0x16b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16bb:
	/* 0x16bb: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_16bd:
	/* 0x16bd: jne    16d1 <tail_ipv6_policy+0x16d1> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x16bd, 0x16d1, x86_l_16d1);
x86_l_16bf:
	/* 0x16bf: jmp    17b3 <tail_ipv6_policy+0x17b3> */
	X86_SIM_X86_JMP(0x16bf, 0x17b3, x86_l_17b3);
x86_l_16c4:
	/* 0x16c4: mov    ebp,0xffffff4e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967118ULL);
x86_l_16c9:
	/* 0x16c9: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_16cb:
	/* 0x16cb: je     17b3 <tail_ipv6_policy+0x17b3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x16cb, 0x17b3, x86_l_17b3);
x86_l_16d1:
	/* 0x16d1: lea    rax,[rsp+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_16d9:
	/* 0x16d9: mov    QWORD PTR [rax+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_16e1:
	/* 0x16e1: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16e8:
	/* 0x16e8: cmp    r12b,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_8, 17ULL);
x86_l_16ec:
	/* 0x16ec: je     1737 <tail_ipv6_policy+0x1737> */
	X86_SIM_X86_JCC(X86_CC_E, 0x16ec, 0x1737, x86_l_1737);
x86_l_16ee:
	/* 0x16ee: movzx  eax,r12b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R12, X86_WIDTH_32, X86_WIDTH_8);
x86_l_16f2:
	/* 0x16f2: mov    r15d,0xffffff4c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967116ULL);
x86_l_16f8:
	/* 0x16f8: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_16fb:
	/* 0x16fb: jne    17b3 <tail_ipv6_policy+0x17b3> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x16fb, 0x17b3, x86_l_17b3);
x86_l_1701:
	/* 0x1701: lea    rsi,[rsp+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1709:
	/* 0x1709: mov    eax,0x63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 99ULL);
x86_l_170e:
	/* 0x170e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1711:
	/* 0x1711: mov    edx,0x24 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 36ULL);
x86_l_1716:
	/* 0x1716: mov    rcx,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_171d:
	/* 0x171d: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1720:
	/* 0x1720: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1722:
	/* 0x1722: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1727:
	/* 0x1727: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_172a:
	/* 0x172a: je     17ad <tail_ipv6_policy+0x17ad> */
	X86_SIM_X86_JCC(X86_CC_E, 0x172a, 0x17ad, x86_l_17ad);
x86_l_1730:
	/* 0x1730: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1735:
	/* 0x1735: jmp    1767 <tail_ipv6_policy+0x1767> */
	X86_SIM_X86_JMP(0x1735, 0x1767, x86_l_1767);
x86_l_1737:
	/* 0x1737: lea    rsi,[rsp+0xd0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_173f:
	/* 0x173f: mov    eax,0x55 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 85ULL);
x86_l_1744:
	/* 0x1744: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1747:
	/* 0x1747: mov    edx,0x24 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 36ULL);
x86_l_174c:
	/* 0x174c: mov    rcx,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_1753:
	/* 0x1753: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1756:
	/* 0x1756: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1758:
	/* 0x1758: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_175d:
	/* 0x175d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1760:
	/* 0x1760: je     17ad <tail_ipv6_policy+0x17ad> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1760, 0x17ad, x86_l_17ad);
x86_l_1762:
	/* 0x1762: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1767:
	/* 0x1767: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_176c:
	/* 0x176c: mov    eax,0x7c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 124ULL);
x86_l_1771:
	/* 0x1771: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1774:
	/* 0x1774: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1776:
	/* 0x1776: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1778:
	/* 0x1778: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_177a:
	/* 0x177a: mov    r15d,0xffffff4d */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967117ULL);
x86_l_1780:
	/* 0x1780: cmove  r15d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R15, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_1784:
	/* 0x1784: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1789:
	/* 0x1789: mov    eax,0x56 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 86ULL);
x86_l_178e:
	/* 0x178e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1790:
	/* 0x1790: jmp    17b3 <tail_ipv6_policy+0x17b3> */
	X86_SIM_X86_JMP(0x1790, 0x17b3, x86_l_17b3);
x86_l_1792:
	/* 0x1792: inc    QWORD PTR [r15] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1795:
	/* 0x1795: mov    r13d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_179a:
	/* 0x179a: jmp    145b <tail_ipv6_policy+0x145b> */
	X86_SIM_X86_JMP(0x179a, 0x145b, x86_l_145b);
x86_l_179f:
	/* 0x179f: mov    r13d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_17a2:
	/* 0x17a2: mov    r15d,0xffffff65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967141ULL);
x86_l_17a8:
	/* 0x17a8: jmp    184 <tail_ipv6_policy+0x184> */
	X86_SIM_X86_JMP(0x17a8, 0x184, x86_l_184);
x86_l_17ad:
	/* 0x17ad: mov    r15d,0xffffff4e */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967118ULL);
x86_l_17b3:
	/* 0x17b3: mov    eax,DWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17b6:
	/* 0x17b6: mov    DWORD PTR [rbx+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_17b9:
	/* 0x17b9: mov    r12d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_17be:
	/* 0x17be: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_17c1:
	/* 0x17c1: jns    1e1f <tail_ipv6_policy+0x1e1f> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x17c1, 0x1e1f, x86_l_1e1f);
x86_l_17c7:
	/* 0x17c7: jmp    184 <tail_ipv6_policy+0x184> */
	X86_SIM_X86_JMP(0x17c7, 0x184, x86_l_184);
x86_l_17cc:
	/* 0x17cc: mov    rax,QWORD PTR [rsp+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_17d4:
	/* 0x17d4: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_17d7:
	/* 0x17d7: mov    r13d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17dc:
	/* 0x17dc: jmp    e96 <tail_ipv6_policy+0xe96> */
	X86_SIM_X86_JMP(0x17dc, 0xe96, x86_l_e96);
x86_l_17e1:
	/* 0x17e1: mov    ecx,0x56 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 86ULL);
x86_l_17e6:
	/* 0x17e6: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_17e9:
	/* 0x17e9: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_17eb:
	/* 0x17eb: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17ee:
	/* 0x17ee: jmp    17b3 <tail_ipv6_policy+0x17b3> */
	X86_SIM_X86_JMP(0x17ee, 0x17b3, x86_l_17b3);
x86_l_17f0:
	/* 0x17f0: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_17f3:
	/* 0x17f3: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_17f6:
	/* 0x17f6: jmp    3e8 <tail_ipv6_policy+0x3e8> */
	X86_SIM_X86_JMP(0x17f6, 0x3e8, x86_l_3e8);
x86_l_17fb:
	/* 0x17fb: mov    r15d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 2ULL);
x86_l_1801:
	/* 0x1801: jmp    1809 <tail_ipv6_policy+0x1809> */
	X86_SIM_X86_JMP(0x1801, 0x1809, x86_l_1809);
x86_l_1803:
	/* 0x1803: mov    r15d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 16ULL);
x86_l_1809:
	/* 0x1809: lea    rdi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_180e:
	/* 0x180e: lea    rdx,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1816:
	/* 0x1816: mov    eax,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_181b:
	/* 0x181b: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1820:
	/* 0x1820: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1825:
	/* 0x1825: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1828:
	/* 0x1828: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_182a:
	/* 0x182a: add    r15d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_182f:
	/* 0x182f: mov    r8d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1834:
	/* 0x1834: or     r8d,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 144ULL);
x86_l_183b:
	/* 0x183b: mov    r9d,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 11ULL);
x86_l_1841:
	/* 0x1841: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1844:
	/* 0x1844: mov    esi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_1847:
	/* 0x1847: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1849:
	/* 0x1849: mov    r12d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_32);
x86_l_184c:
	/* 0x184c: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_184e:
	/* 0x184e: call   r9 */
	X86_SIM_BPF_CALL_REG(X86_R9);
x86_l_1851:
	/* 0x1851: cmp    eax,0xffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967274ULL);
x86_l_1854:
	/* 0x1854: jne    186d <tail_ipv6_policy+0x186d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1854, 0x186d, x86_l_186d);
x86_l_1856:
	/* 0x1856: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1859:
	/* 0x1859: mov    esi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_185c:
	/* 0x185c: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_185e:
	/* 0x185e: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_1861:
	/* 0x1861: mov    r8d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1866:
	/* 0x1866: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_186b:
	/* 0x186b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_186d:
	/* 0x186d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_186f:
	/* 0x186f: js     1e3b <tail_ipv6_policy+0x1e3b> */
	X86_SIM_X86_JCC(X86_CC_S, 0x186f, 0x1e3b, x86_l_1e3b);
x86_l_1875:
	/* 0x1875: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_187a:
	/* 0x187a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_187d:
	/* 0x187d: mov    esi,0x16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 22ULL);
x86_l_1882:
	/* 0x1882: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1885:
	/* 0x1885: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_188a:
	/* 0x188a: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_188d:
	/* 0x188d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_188f:
	/* 0x188f: mov    r15d,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967155ULL);
x86_l_1895:
	/* 0x1895: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1897:
	/* 0x1897: js     1e41 <tail_ipv6_policy+0x1e41> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1897, 0x1e41, x86_l_1e41);
x86_l_189d:
	/* 0x189d: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_18a0:
	/* 0x18a0: je     1e41 <tail_ipv6_policy+0x1e41> */
	X86_SIM_X86_JCC(X86_CC_E, 0x18a0, 0x1e41, x86_l_1e41);
x86_l_18a6:
	/* 0x18a6: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_18a9:
	/* 0x18a9: je     19f8 <tail_ipv6_policy+0x19f8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x18a9, 0x19f8, x86_l_19f8);
x86_l_18af:
	/* 0x18af: movzx  eax,BYTE PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 36ULL);
x86_l_18b4:
	/* 0x18b4: cmp    eax,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 58ULL);
x86_l_18b7:
	/* 0x18b7: je     18df <tail_ipv6_policy+0x18df> */
	X86_SIM_X86_JCC(X86_CC_E, 0x18b7, 0x18df, x86_l_18df);
x86_l_18b9:
	/* 0x18b9: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_18bc:
	/* 0x18bc: je     18cd <tail_ipv6_policy+0x18cd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x18bc, 0x18cd, x86_l_18cd);
x86_l_18be:
	/* 0x18be: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_18c1:
	/* 0x18c1: jne    18e9 <tail_ipv6_policy+0x18e9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x18c1, 0x18e9, x86_l_18e9);
x86_l_18c3:
	/* 0x18c3: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18c5:
	/* 0x18c5: mov    r12d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 16ULL);
x86_l_18cb:
	/* 0x18cb: jmp    18ef <tail_ipv6_policy+0x18ef> */
	X86_SIM_X86_JMP(0x18cb, 0x18ef, x86_l_18ef);
x86_l_18cd:
	/* 0x18cd: mov    DWORD PTR [rsp+0x8],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738400ULL);
x86_l_18d5:
	/* 0x18d5: mov    r12d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 6ULL);
x86_l_18db:
	/* 0x18db: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18dd:
	/* 0x18dd: jmp    18f7 <tail_ipv6_policy+0x18f7> */
	X86_SIM_X86_JMP(0x18dd, 0x18f7, x86_l_18f7);
x86_l_18df:
	/* 0x18df: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18e1:
	/* 0x18e1: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_18e7:
	/* 0x18e7: jmp    18ef <tail_ipv6_policy+0x18ef> */
	X86_SIM_X86_JMP(0x18e7, 0x18ef, x86_l_18ef);
x86_l_18e9:
	/* 0x18e9: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18ec:
	/* 0x18ec: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_18ef:
	/* 0x18ef: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_18f7:
	/* 0x18f7: movzx  ecx,WORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_18fc:
	/* 0x18fc: test   cx,cx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_16);
x86_l_18ff:
	/* 0x18ff: je     198d <tail_ipv6_policy+0x198d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x18ff, 0x198d, x86_l_198d);
x86_l_1905:
	/* 0x1905: movzx  r14d,WORD PTR [r14+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_190a:
	/* 0x190a: mov    r15d,0xffffff72 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967154ULL);
x86_l_1910:
	/* 0x1910: cmp    eax,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_1913:
	/* 0x1913: jg     1924 <tail_ipv6_policy+0x1924> */
	X86_SIM_X86_JCC(X86_CC_G, 0x1913, 0x1924, x86_l_1924);
x86_l_1915:
	/* 0x1915: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1918:
	/* 0x1918: je     198d <tail_ipv6_policy+0x198d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1918, 0x198d, x86_l_198d);
x86_l_191a:
	/* 0x191a: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_191d:
	/* 0x191d: je     1932 <tail_ipv6_policy+0x1932> */
	X86_SIM_X86_JCC(X86_CC_E, 0x191d, 0x1932, x86_l_1932);
x86_l_191f:
	/* 0x191f: jmp    1e41 <tail_ipv6_policy+0x1e41> */
	X86_SIM_X86_JMP(0x191f, 0x1e41, x86_l_1e41);
x86_l_1924:
	/* 0x1924: cmp    eax,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 58ULL);
x86_l_1927:
	/* 0x1927: je     198d <tail_ipv6_policy+0x198d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1927, 0x198d, x86_l_198d);
x86_l_1929:
	/* 0x1929: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_192c:
	/* 0x192c: jne    1e41 <tail_ipv6_policy+0x1e41> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x192c, 0x1e41, x86_l_1e41);
x86_l_1932:
	/* 0x1932: cmp    cx,r14w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R14, X86_WIDTH_16);
x86_l_1936:
	/* 0x1936: je     198d <tail_ipv6_policy+0x198d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1936, 0x198d, x86_l_198d);
x86_l_1938:
	/* 0x1938: mov    WORD PTR [rsp+0x60],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_193d:
	/* 0x193d: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1942:
	/* 0x1942: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_1947:
	/* 0x1947: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_194a:
	/* 0x194a: mov    rsi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_194f:
	/* 0x194f: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1954:
	/* 0x1954: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1957:
	/* 0x1957: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1959:
	/* 0x1959: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_195b:
	/* 0x195b: js     1e4e <tail_ipv6_policy+0x1e4e> */
	X86_SIM_X86_JCC(X86_CC_S, 0x195b, 0x1e4e, x86_l_1e4e);
x86_l_1961:
	/* 0x1961: movzx  ecx,WORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 96ULL);
x86_l_1966:
	/* 0x1966: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_196b:
	/* 0x196b: lea    esi,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_196f:
	/* 0x196f: mov    r8d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1974:
	/* 0x1974: or     r8d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_1978:
	/* 0x1978: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_197d:
	/* 0x197d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1980:
	/* 0x1980: mov    edx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_32);
x86_l_1983:
	/* 0x1983: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1985:
	/* 0x1985: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1987:
	/* 0x1987: js     1e3b <tail_ipv6_policy+0x1e3b> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1987, 0x1e3b, x86_l_1e3b);
x86_l_198d:
	/* 0x198d: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_1990:
	/* 0x1990: jne    19f8 <tail_ipv6_policy+0x19f8> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1990, 0x19f8, x86_l_19f8);
x86_l_1992:
	/* 0x1992: lea    rdi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_199a:
	/* 0x199a: mov    eax,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_199f:
	/* 0x199f: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_19a4:
	/* 0x19a4: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_19a7:
	/* 0x19a7: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_19ac:
	/* 0x19ac: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19af:
	/* 0x19af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19b1:
	/* 0x19b1: mov    r14d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_32);
x86_l_19b4:
	/* 0x19b4: add    r12d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_19b9:
	/* 0x19b9: mov    r8d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19be:
	/* 0x19be: or     r8d,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 144ULL);
x86_l_19c5:
	/* 0x19c5: mov    r15d,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 11ULL);
x86_l_19cb:
	/* 0x19cb: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_19ce:
	/* 0x19ce: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_19d1:
	/* 0x19d1: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19d3:
	/* 0x19d3: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_19d5:
	/* 0x19d5: call   r15 */
	X86_SIM_BPF_CALL_REG(X86_R15);
x86_l_19d8:
	/* 0x19d8: cmp    eax,0xffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967274ULL);
x86_l_19db:
	/* 0x19db: jne    19f0 <tail_ipv6_policy+0x19f0> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x19db, 0x19f0, x86_l_19f0);
x86_l_19dd:
	/* 0x19dd: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_19e0:
	/* 0x19e0: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_19e3:
	/* 0x19e3: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19e5:
	/* 0x19e5: mov    ecx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_32);
x86_l_19e8:
	/* 0x19e8: mov    r8d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19ed:
	/* 0x19ed: call   r15 */
	X86_SIM_BPF_CALL_REG(X86_R15);
x86_l_19f0:
	/* 0x19f0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_19f2:
	/* 0x19f2: js     1e3b <tail_ipv6_policy+0x1e3b> */
	X86_SIM_X86_JCC(X86_CC_S, 0x19f2, 0x1e3b, x86_l_1e3b);
x86_l_19f8:
	/* 0x19f8: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19fb:
	/* 0x19fb: mov    r12d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1a00:
	/* 0x1a00: mov    rax,QWORD PTR [rip+0x1c5c3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_security_label)));
x86_l_1a07:
	/* 0x1a07: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a09:
	/* 0x1a09: mov    rax,QWORD PTR [rip+0x1c5c3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_endpoint_id)));
x86_l_1a10:
	/* 0x1a10: movzx  edx,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1a13:
	/* 0x1a13: mov    rax,QWORD PTR [rip+0x1c5c3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_tracing_ip_option_type)));
x86_l_1a1a:
	/* 0x1a1a: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a1d:
	/* 0x1a1d: mov    DWORD PTR [rsp+0x18],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a21:
	/* 0x1a21: mov    WORD PTR [rsp+0x7c],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_1a26:
	/* 0x1a26: je     1a52 <tail_ipv6_policy+0x1a52> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a26, 0x1a52, x86_l_1a52);
x86_l_1a28:
	/* 0x1a28: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1a30:
	/* 0x1a30: mov    rdi,QWORD PTR [rip+0x1c5c3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_percpu_trace_id)));
x86_l_1a37:
	/* 0x1a37: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a3c:
	/* 0x1a3c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a41:
	/* 0x1a41: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a43:
	/* 0x1a43: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a46:
	/* 0x1a46: mov    r14d,DWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1a4b:
	/* 0x1a4b: je     1a60 <tail_ipv6_policy+0x1a60> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a4b, 0x1a60, x86_l_1a60);
x86_l_1a4d:
	/* 0x1a4d: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a50:
	/* 0x1a50: jmp    1a62 <tail_ipv6_policy+0x1a62> */
	X86_SIM_X86_JMP(0x1a50, 0x1a62, x86_l_1a62);
x86_l_1a52:
	/* 0x1a52: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a54:
	/* 0x1a54: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1a59:
	/* 0x1a59: mov    r14d,DWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1a5e:
	/* 0x1a5e: jmp    1a67 <tail_ipv6_policy+0x1a67> */
	X86_SIM_X86_JMP(0x1a5e, 0x1a67, x86_l_1a67);
x86_l_1a60:
	/* 0x1a60: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a62:
	/* 0x1a62: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1a67:
	/* 0x1a67: mov    ebp,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a69:
	/* 0x1a69: mov    QWORD PTR [rsp+0xb8],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982466ULL);
x86_l_1a75:
	/* 0x1a75: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_1a7e:
	/* 0x1a7e: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1a87:
	/* 0x1a87: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1a90:
	/* 0x1a90: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1a99:
	/* 0x1a99: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1aa2:
	/* 0x1aa2: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1aab:
	/* 0x1aab: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1ab4:
	/* 0x1ab4: mov    QWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_1ac0:
	/* 0x1ac0: mov    QWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_1acc:
	/* 0x1acc: movabs rax,0x207d30100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8721203456ULL);
x86_l_1ad6:
	/* 0x1ad6: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1adb:
	/* 0x1adb: mov    rdi,QWORD PTR [rip+0x1c5c3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1ae2:
	/* 0x1ae2: lea    r15,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1ae7:
	/* 0x1ae7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1aec:
	/* 0x1aec: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_1aef:
	/* 0x1aef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1af1:
	/* 0x1af1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1af4:
	/* 0x1af4: je     1b0c <tail_ipv6_policy+0x1b0c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1af4, 0x1b0c, x86_l_1b0c);
x86_l_1af6:
	/* 0x1af6: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1af9:
	/* 0x1af9: add    QWORD PTR [rax+0x8],rbp */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1afd:
	/* 0x1afd: cmp    DWORD PTR [rsp+0xc0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_1b05:
	/* 0x1b05: jne    1b4b <tail_ipv6_policy+0x1b4b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1b05, 0x1b4b, x86_l_1b4b);
x86_l_1b07:
	/* 0x1b07: jmp    1d9c <tail_ipv6_policy+0x1d9c> */
	X86_SIM_X86_JMP(0x1b07, 0x1d9c, x86_l_1d9c);
x86_l_1b0c:
	/* 0x1b0c: mov    QWORD PTR [rsp+0x80],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813889ULL);
x86_l_1b18:
	/* 0x1b18: mov    QWORD PTR [rsp+0x88],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1b20:
	/* 0x1b20: mov    rdi,QWORD PTR [rip+0x1c5c3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1b27:
	/* 0x1b27: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1b2c:
	/* 0x1b2c: lea    rdx,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1b34:
	/* 0x1b34: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1b39:
	/* 0x1b39: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b3b:
	/* 0x1b3b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b3d:
	/* 0x1b3d: cmp    DWORD PTR [rsp+0xc0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_1b45:
	/* 0x1b45: je     1d9c <tail_ipv6_policy+0x1d9c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1b45, 0x1d9c, x86_l_1d9c);
x86_l_1b4b:
	/* 0x1b4b: mov    rax,QWORD PTR [rip+0x1c5c3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_events_map_rate_limit)));
x86_l_1b52:
	/* 0x1b52: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b55:
	/* 0x1b55: je     1cd3 <tail_ipv6_policy+0x1cd3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1b55, 0x1cd3, x86_l_1cd3);
x86_l_1b5b:
	/* 0x1b5b: mov    DWORD PTR [rsp+0x8],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b60:
	/* 0x1b60: mov    rcx,QWORD PTR [rip+0x1c5c3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_events_map_burst_limit)));
x86_l_1b67:
	/* 0x1b67: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b69:
	/* 0x1b69: mov    QWORD PTR [rsp+0xb0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1b71:
	/* 0x1b71: mov    r13d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b74:
	/* 0x1b74: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1b79:
	/* 0x1b79: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b7b:
	/* 0x1b7b: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1b7d:
	/* 0x1b7d: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1b80:
	/* 0x1b80: mov    DWORD PTR [rsp+0xac],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 738734374914ULL);
x86_l_1b8b:
	/* 0x1b8b: mov    rdi,QWORD PTR [rip+0x1c5c3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit_metrics)));
x86_l_1b92:
	/* 0x1b92: lea    rsi,[rsp+0xac] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_1b9a:
	/* 0x1b9a: mov    r14d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 1ULL);
x86_l_1ba0:
	/* 0x1ba0: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_1ba3:
	/* 0x1ba3: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1ba6:
	/* 0x1ba6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ba9:
	/* 0x1ba9: jne    1bda <tail_ipv6_policy+0x1bda> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1ba9, 0x1bda, x86_l_1bda);
x86_l_1bab:
	/* 0x1bab: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_1bb4:
	/* 0x1bb4: mov    rdi,QWORD PTR [rip+0x1c5c3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit_metrics)));
x86_l_1bbb:
	/* 0x1bbb: lea    rsi,[rsp+0xac] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_1bc3:
	/* 0x1bc3: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1bc8:
	/* 0x1bc8: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1bcb:
	/* 0x1bcb: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1bcd:
	/* 0x1bcd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bcf:
	/* 0x1bcf: mov    rcx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_1bd2:
	/* 0x1bd2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1bd4:
	/* 0x1bd4: js     1dfa <tail_ipv6_policy+0x1dfa> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1bd4, 0x1dfa, x86_l_1dfa);
x86_l_1bda:
	/* 0x1bda: mov    r15,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RCX, X86_WIDTH_64);
x86_l_1bdd:
	/* 0x1bdd: mov    rdi,QWORD PTR [rip+0x1c5c3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit)));
x86_l_1be4:
	/* 0x1be4: lea    rsi,[rsp+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1bec:
	/* 0x1bec: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_1bef:
	/* 0x1bef: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1bf2:
	/* 0x1bf2: je     1c65 <tail_ipv6_policy+0x1c65> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1bf2, 0x1c65, x86_l_1c65);
x86_l_1bf4:
	/* 0x1bf4: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bf7:
	/* 0x1bf7: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_1bfa:
	/* 0x1bfa: sub    rsi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1bfd:
	/* 0x1bfd: cmp    rsi,0x3b9aca00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 1000000000ULL);
x86_l_1c04:
	/* 0x1c04: jbe    1cb0 <tail_ipv6_policy+0x1cb0> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x1c04, 0x1cb0, x86_l_1cb0);
x86_l_1c0a:
	/* 0x1c0a: mov    rdx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_1c0d:
	/* 0x1c0d: shr    rdx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1c11:
	/* 0x1c11: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_1c1b:
	/* 0x1c1b: mulx   rcx,rcx,rcx */
	X86_SIM_L_EXEC_MULX(X86_RCX, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_1c20:
	/* 0x1c20: shr    rcx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_1c24:
	/* 0x1c24: imul   rdx,rcx,0x3b9aca00 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RDX, X86_RCX, X86_WIDTH_64, 1000000000ULL);
x86_l_1c2b:
	/* 0x1c2b: imul   rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_IMUL);
x86_l_1c2f:
	/* 0x1c2f: add    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1c33:
	/* 0x1c33: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c37:
	/* 0x1c37: sub    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1c3a:
	/* 0x1c3a: add    r12,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1c3d:
	/* 0x1c3d: mov    QWORD PTR [rax],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c40:
	/* 0x1c40: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1c48:
	/* 0x1c48: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1c4b:
	/* 0x1c4b: mov    r12d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1c50:
	/* 0x1c50: mov    r14d,DWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1c55:
	/* 0x1c55: mov    r13d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c5a:
	/* 0x1c5a: jbe    1cc3 <tail_ipv6_policy+0x1cc3> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x1c5a, 0x1cc3, x86_l_1cc3);
x86_l_1c5c:
	/* 0x1c5c: mov    QWORD PTR [rax+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c60:
	/* 0x1c60: mov    rcx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1c63:
	/* 0x1c63: jmp    1cc3 <tail_ipv6_policy+0x1cc3> */
	X86_SIM_X86_JMP(0x1c63, 0x1cc3, x86_l_1cc3);
x86_l_1c65:
	/* 0x1c65: mov    QWORD PTR [rsp+0x80],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1c6d:
	/* 0x1c6d: dec    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_1c70:
	/* 0x1c70: mov    QWORD PTR [rsp+0x88],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1c78:
	/* 0x1c78: mov    rdi,QWORD PTR [rip+0x1c5c3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit)));
x86_l_1c7f:
	/* 0x1c7f: lea    rsi,[rsp+0xb8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1c87:
	/* 0x1c87: lea    rdx,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1c8f:
	/* 0x1c8f: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1c94:
	/* 0x1c94: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c96:
	/* 0x1c96: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c98:
	/* 0x1c98: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1c9a:
	/* 0x1c9a: mov    r12d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1c9f:
	/* 0x1c9f: mov    r14d,DWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1ca4:
	/* 0x1ca4: mov    r13d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ca9:
	/* 0x1ca9: jns    1cd3 <tail_ipv6_policy+0x1cd3> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1ca9, 0x1cd3, x86_l_1cd3);
x86_l_1cab:
	/* 0x1cab: jmp    1df7 <tail_ipv6_policy+0x1df7> */
	X86_SIM_X86_JMP(0x1cab, 0x1df7, x86_l_1df7);
x86_l_1cb0:
	/* 0x1cb0: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cb4:
	/* 0x1cb4: mov    r12d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1cb9:
	/* 0x1cb9: mov    r14d,DWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1cbe:
	/* 0x1cbe: mov    r13d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cc3:
	/* 0x1cc3: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_1cc6:
	/* 0x1cc6: je     1df7 <tail_ipv6_policy+0x1df7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1cc6, 0x1df7, x86_l_1df7);
x86_l_1ccc:
	/* 0x1ccc: dec    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_1ccf:
	/* 0x1ccf: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cd3:
	/* 0x1cd3: mov    rcx,QWORD PTR [rip+0x1c5c3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_1cda:
	/* 0x1cda: mov    eax,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cdc:
	/* 0x1cdc: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cde:
	/* 0x1cde: mov    edx,DWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1ce5:
	/* 0x1ce5: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_1ce7:
	/* 0x1ce7: cmovne eax,edx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RDX, X86_WIDTH_32, X86_CC_NE);
x86_l_1cea:
	/* 0x1cea: mov    ecx,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cec:
	/* 0x1cec: cmp    eax,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_1cee:
	/* 0x1cee: mov    rdx,QWORD PTR [rip+0x1c5c3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_endpoint_id)));
x86_l_1cf5:
	/* 0x1cf5: movzx  edx,WORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1cf8:
	/* 0x1cf8: cmovae eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_AE);
x86_l_1cfb:
	/* 0x1cfb: mov    ecx,DWORD PTR [rbx+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_1cfe:
	/* 0x1cfe: mov    WORD PTR [rsp+0x20],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 137438953476ULL);
x86_l_1d05:
	/* 0x1d05: mov    WORD PTR [rsp+0x22],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_1d0a:
	/* 0x1d0a: mov    DWORD PTR [rsp+0x24],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1d0e:
	/* 0x1d0e: mov    DWORD PTR [rsp+0x28],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1d12:
	/* 0x1d12: mov    WORD PTR [rsp+0x2c],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1d17:
	/* 0x1d17: mov    WORD PTR [rsp+0x2e],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 197568495618ULL);
x86_l_1d1e:
	/* 0x1d1e: mov    DWORD PTR [rsp+0x30],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1d23:
	/* 0x1d23: mov    ecx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d27:
	/* 0x1d27: mov    DWORD PTR [rsp+0x34],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1d2b:
	/* 0x1d2b: movzx  ecx,WORD PTR [rsp+0x7c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 124ULL);
x86_l_1d30:
	/* 0x1d30: mov    WORD PTR [rsp+0x38],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1d35:
	/* 0x1d35: mov    ecx,DWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1d3c:
	/* 0x1d3c: mov    BYTE PTR [rsp+0x3a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_1d40:
	/* 0x1d40: mov    BYTE PTR [rsp+0x3b],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 253403070465ULL);
x86_l_1d45:
	/* 0x1d45: mov    ecx,DWORD PTR [rsp+0x104] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 260ULL);
x86_l_1d4c:
	/* 0x1d4c: mov    DWORD PTR [rsp+0x3c],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_1d50:
	/* 0x1d50: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1d55:
	/* 0x1d55: mov    QWORD PTR [rsp+0x50],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1d5a:
	/* 0x1d5a: mov    rcx,QWORD PTR [rsp+0x110] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_1d62:
	/* 0x1d62: mov    QWORD PTR [rsp+0x48],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1d67:
	/* 0x1d67: mov    rcx,QWORD PTR [rsp+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_1d6f:
	/* 0x1d6f: mov    QWORD PTR [rsp+0x40],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1d74:
	/* 0x1d74: shl    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_1d78:
	/* 0x1d78: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_1d7d:
	/* 0x1d7d: or     rdx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1d80:
	/* 0x1d80: mov    rsi,QWORD PTR [rip+0x1c5c3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_events)));
x86_l_1d87:
	/* 0x1d87: lea    rcx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d8c:
	/* 0x1d8c: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_1d91:
	/* 0x1d91: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1d94:
	/* 0x1d94: mov    r8d,0x38 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 56ULL);
x86_l_1d9a:
	/* 0x1d9a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d9c:
	/* 0x1d9c: cmp    DWORD PTR [rsp+0xf8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1065151889408ULL);
x86_l_1da4:
	/* 0x1da4: je     1e13 <tail_ipv6_policy+0x1e13> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1da4, 0x1e13, x86_l_1e13);
x86_l_1da6:
	/* 0x1da6: mov    rax,QWORD PTR [rip+0x1c5c3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_interface_ifindex)));
x86_l_1dad:
	/* 0x1dad: mov    edi,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1daf:
	/* 0x1daf: test   r14d,r14d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_32);
x86_l_1db2:
	/* 0x1db2: jne    1dc0 <tail_ipv6_policy+0x1dc0> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1db2, 0x1dc0, x86_l_1dc0);
x86_l_1db4:
	/* 0x1db4: mov    rax,QWORD PTR [rip+0x1c5c3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_netkit)));
x86_l_1dbb:
	/* 0x1dbb: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1dbe:
	/* 0x1dbe: je     1dd6 <tail_ipv6_policy+0x1dd6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1dbe, 0x1dd6, x86_l_1dd6);
x86_l_1dc0:
	/* 0x1dc0: mov    eax,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 23ULL);
x86_l_1dc5:
	/* 0x1dc5: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1dc7:
	/* 0x1dc7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dc9:
	/* 0x1dc9: mov    r15d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_32);
x86_l_1dcc:
	/* 0x1dcc: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_1dcf:
	/* 0x1dcf: jns    1e1f <tail_ipv6_policy+0x1e1f> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1dcf, 0x1e1f, x86_l_1e1f);
x86_l_1dd1:
	/* 0x1dd1: jmp    184 <tail_ipv6_policy+0x184> */
	X86_SIM_X86_JMP(0x1dd1, 0x184, x86_l_184);
x86_l_1dd6:
	/* 0x1dd6: cmp    DWORD PTR [rsp+0xc4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 841813590016ULL);
x86_l_1dde:
	/* 0x1dde: je     1df0 <tail_ipv6_policy+0x1df0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1dde, 0x1df0, x86_l_1df0);
x86_l_1de0:
	/* 0x1de0: mov    eax,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_1de5:
	/* 0x1de5: mov    ebp,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDI, X86_WIDTH_32);
x86_l_1de7:
	/* 0x1de7: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1dea:
	/* 0x1dea: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1dec:
	/* 0x1dec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dee:
	/* 0x1dee: mov    edi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_32);
x86_l_1df0:
	/* 0x1df0: mov    eax,0x9b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 155ULL);
x86_l_1df5:
	/* 0x1df5: jmp    1dc5 <tail_ipv6_policy+0x1dc5> */
	X86_SIM_X86_JMP(0x1df5, 0x1dc5, x86_l_1dc5);
x86_l_1df7:
	/* 0x1df7: inc    QWORD PTR [r15] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1dfa:
	/* 0x1dfa: mov    r12d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1dff:
	/* 0x1dff: mov    r14d,DWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1e04:
	/* 0x1e04: mov    r13d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e09:
	/* 0x1e09: cmp    DWORD PTR [rsp+0xf8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1065151889408ULL);
x86_l_1e11:
	/* 0x1e11: jne    1da6 <tail_ipv6_policy+0x1da6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1e11, 0x1da6, x86_l_1da6);
x86_l_1e13:
	/* 0x1e13: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e16:
	/* 0x1e16: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_1e19:
	/* 0x1e19: js     184 <tail_ipv6_policy+0x184> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1e19, 0x184, x86_l_184);
x86_l_1e1f:
	/* 0x1e1f: cmp    r15d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 2ULL);
x86_l_1e23:
	/* 0x1e23: je     184 <tail_ipv6_policy+0x184> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1e23, 0x184, x86_l_184);
x86_l_1e29:
	/* 0x1e29: mov    eax,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_1e2c:
	/* 0x1e2c: add    rsp,0x148 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 328ULL);
x86_l_1e33:
	/* 0x1e33: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_1e35:
	/* 0x1e35: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_1e36:
	/* 0x1e36: jmp    1e72 <tail_ipv6_policy+0x1e72> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_1e3b:
	/* 0x1e3b: mov    r15d,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967142ULL);
x86_l_1e41:
	/* 0x1e41: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e44:
	/* 0x1e44: mov    r12d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1e49:
	/* 0x1e49: jmp    184 <tail_ipv6_policy+0x184> */
	X86_SIM_X86_JMP(0x1e49, 0x184, x86_l_184);
x86_l_1e4e:
	/* 0x1e4e: mov    r15d,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967155ULL);
x86_l_1e54:
	/* 0x1e54: jmp    1e41 <tail_ipv6_policy+0x1e41> */
	X86_SIM_X86_JMP(0x1e54, 0x1e41, x86_l_1e41);
x86_l_1e56:
	/* 0x1e56: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e58:
	/* 0x1e58: add    rax,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1e5b:
	/* 0x1e5b: cmp    rax,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_1e5f:
	/* 0x1e5f: jae    b1d <tail_ipv6_policy+0xb1d> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x1e5f, 0xb1d, x86_l_b1d);
x86_l_1e65:
	/* 0x1e65: jmp    b64 <tail_ipv6_policy+0xb64> */
	X86_SIM_X86_JMP(0x1e65, 0xb64, x86_l_b64);
x86_l_1e6a:
	/* 0x1e6a: mov    r13d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_1e6d:
	/* 0x1e6d: jmp    995 <tail_ipv6_policy+0x995> */
	X86_SIM_X86_JMP(0x1e6d, 0x995, x86_l_995);
x86_l_1e72:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
