extern char __config_allow_icmp_frag_needed;
extern char __config_cilium_host_mac;
extern char __config_cilium_net_ifindex;
extern char __config_debug_lb;
extern char __config_enable_conntrack_accounting;
extern char __config_enable_icmp_rule;
extern char __config_enable_ipv6_fragments;
extern char __config_enable_jiffies;
extern char __config_enable_policy_accounting;
extern char __config_endpoint_id;
extern char __config_events_map_burst_limit;
extern char __config_events_map_rate_limit;
extern char __config_interface_ifindex;
extern char __config_interface_mac;
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
int cilium_bpf_lxc_tail_ipv6_to_endpoint_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0x108 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 264ULL);
x86_l_a:
	/* 0xa: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: mov    ebp,DWORD PTR [rdi+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_10:
	/* 0x10: mov    r15d,DWORD PTR [rdi+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_14:
	/* 0x14: mov    DWORD PTR [rdi+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1b:
	/* 0x1b: mov    eax,DWORD PTR [rdi+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1e:
	/* 0x1e: lea    rcx,[r15+0x36] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_22:
	/* 0x22: cmp    rcx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_25:
	/* 0x25: jbe    b3 <tail_ipv6_to_endpoint+0xb3> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x25, 0xb3, x86_l_b3);
x86_l_2b:
	/* 0x2b: mov    r12d,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967162ULL);
x86_l_31:
	/* 0x31: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_34:
	/* 0x34: mov    rax,QWORD PTR [rip+0x1e447] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_security_label)));
x86_l_3b:
	/* 0x3b: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3d:
	/* 0x3d: mov    rcx,QWORD PTR [rip+0x1e447] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_endpoint_id)));
x86_l_44:
	/* 0x44: movzx  ecx,WORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_47:
	/* 0x47: mov    edx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_32);
x86_l_4a:
	/* 0x4a: neg    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_4c:
	/* 0x4c: cmovs  edx,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_R12, X86_WIDTH_32, X86_CC_S);
x86_l_50:
	/* 0x50: movzx  edx,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_53:
	/* 0x53: movzx  esi,r15b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_R15, X86_WIDTH_32, X86_WIDTH_8);
x86_l_57:
	/* 0x57: shl    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_5a:
	/* 0x5a: or     esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_5c:
	/* 0x5c: mov    DWORD PTR [rbx+0x30],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5f:
	/* 0x5f: mov    DWORD PTR [rbx+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_62:
	/* 0x62: mov    DWORD PTR [rbx+0x38],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_65:
	/* 0x65: mov    DWORD PTR [rbx+0x3c],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_68:
	/* 0x68: mov    DWORD PTR [rbx+0x40],0x8600202 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 275018416642ULL);
x86_l_6f:
	/* 0x6f: mov    r14d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_72:
	/* 0x72: movabs rax,0x207d30100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8721203456ULL);
x86_l_7c:
	/* 0x7c: add    rax,0x8d0000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 9240576ULL);
x86_l_82:
	/* 0x82: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_87:
	/* 0x87: mov    BYTE PTR [rsp+0x70],dl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_8b:
	/* 0x8b: mov    rdi,QWORD PTR [rip+0x1e447] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_92:
	/* 0x92: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_97:
	/* 0x97: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_9c:
	/* 0x9c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9e:
	/* 0x9e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a1:
	/* 0xa1: je     1ae <tail_ipv6_to_endpoint+0x1ae> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa1, 0x1ae, x86_l_1ae);
x86_l_a7:
	/* 0xa7: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_aa:
	/* 0xaa: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_ae:
	/* 0xae: jmp    1d6 <tail_ipv6_to_endpoint+0x1d6> */
	X86_SIM_X86_JMP(0xae, 0x1d6, x86_l_1d6);
x86_l_b3:
	/* 0xb3: cmp    BYTE PTR [r15+0x14],0x3a */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 85899345978ULL);
x86_l_b8:
	/* 0xb8: jne    e6 <tail_ipv6_to_endpoint+0xe6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb8, 0xe6, x86_l_e6);
x86_l_ba:
	/* 0xba: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_bf:
	/* 0xbf: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_c4:
	/* 0xc4: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_c7:
	/* 0xc7: mov    esi,0x36 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 54ULL);
x86_l_cc:
	/* 0xcc: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_d1:
	/* 0xd1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d3:
	/* 0xd3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_d5:
	/* 0xd5: js     e6 <tail_ipv6_to_endpoint+0xe6> */
	X86_SIM_X86_JCC(X86_CC_S, 0xd5, 0xe6, x86_l_e6);
x86_l_d7:
	/* 0xd7: movzx  eax,BYTE PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 32ULL);
x86_l_dc:
	/* 0xdc: add    al,0x79 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_ADD, 121ULL);
x86_l_de:
	/* 0xde: cmp    al,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 2ULL);
x86_l_e0:
	/* 0xe0: jb     676 <tail_ipv6_to_endpoint+0x676> */
	X86_SIM_X86_JCC(X86_CC_B, 0xe0, 0x676, x86_l_676);
x86_l_e6:
	/* 0xe6: cmp    ebp,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_e9:
	/* 0xe9: jb     108 <tail_ipv6_to_endpoint+0x108> */
	X86_SIM_X86_JCC(X86_CC_B, 0xe9, 0x108, x86_l_108);
x86_l_eb:
	/* 0xeb: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_ed:
	/* 0xed: and    eax,0xff000000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4278190080ULL);
x86_l_f2:
	/* 0xf2: cmp    eax,0x2000000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 33554432ULL);
x86_l_f7:
	/* 0xf7: je     108 <tail_ipv6_to_endpoint+0x108> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf7, 0x108, x86_l_108);
x86_l_f9:
	/* 0xf9: cmp    ebp,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_fc:
	/* 0xfc: ja     150 <tail_ipv6_to_endpoint+0x150> */
	X86_SIM_X86_JCC(X86_CC_A, 0xfc, 0x150, x86_l_150);
x86_l_fe:
	/* 0xfe: mov    eax,0x6c0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1728ULL);
x86_l_103:
	/* 0x103: bt     eax,ebp */
	X86_SIM_L_EXEC_BT(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_106:
	/* 0x106: jae    150 <tail_ipv6_to_endpoint+0x150> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x106, 0x150, x86_l_150);
x86_l_108:
	/* 0x108: mov    WORD PTR [rsp+0x26],0x200 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 163208757760ULL);
x86_l_10f:
	/* 0x10f: mov    DWORD PTR [rsp+0x20],0xa0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953632ULL);
x86_l_117:
	/* 0x117: mov    rax,QWORD PTR [r15+0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_11b:
	/* 0x11b: mov    rcx,QWORD PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_11f:
	/* 0x11f: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_124:
	/* 0x124: mov    QWORD PTR [rsp+0x30],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_129:
	/* 0x129: mov    WORD PTR [rsp+0x24],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 154618822656ULL);
x86_l_130:
	/* 0x130: mov    rdi,QWORD PTR [rip+0x1e447] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipcache_v2)));
x86_l_137:
	/* 0x137: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_13c:
	/* 0x13c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_141:
	/* 0x141: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_143:
	/* 0x143: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_146:
	/* 0x146: je     150 <tail_ipv6_to_endpoint+0x150> */
	X86_SIM_X86_JCC(X86_CC_E, 0x146, 0x150, x86_l_150);
x86_l_148:
	/* 0x148: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14a:
	/* 0x14a: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14d:
	/* 0x14d: cmovne ebp,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RAX, X86_WIDTH_32, X86_CC_NE);
x86_l_150:
	/* 0x150: mov    rax,QWORD PTR [rip+0x1e447] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_endpoint_id)));
x86_l_157:
	/* 0x157: movzx  eax,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_15a:
	/* 0x15a: mov    rax,QWORD PTR [rip+0x1e447] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_security_label)));
x86_l_161:
	/* 0x161: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_163:
	/* 0x163: mov    r14d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_166:
	/* 0x166: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_16f:
	/* 0x16f: movabs rax,0x207d30100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8721203456ULL);
x86_l_179:
	/* 0x179: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_182:
	/* 0x182: add    rax,0x7b0000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 8060928ULL);
x86_l_188:
	/* 0x188: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_18d:
	/* 0x18d: mov    rdi,QWORD PTR [rip+0x1e447] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_194:
	/* 0x194: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_199:
	/* 0x199: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_19e:
	/* 0x19e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a0:
	/* 0x1a0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a3:
	/* 0x1a3: je     1f7 <tail_ipv6_to_endpoint+0x1f7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a3, 0x1f7, x86_l_1f7);
x86_l_1a5:
	/* 0x1a5: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1a8:
	/* 0x1a8: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1ac:
	/* 0x1ac: jmp    21f <tail_ipv6_to_endpoint+0x21f> */
	X86_SIM_X86_JMP(0x1ac, 0x21f, x86_l_21f);
x86_l_1ae:
	/* 0x1ae: mov    QWORD PTR [rsp+0x20],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953473ULL);
x86_l_1b7:
	/* 0x1b7: mov    QWORD PTR [rsp+0x28],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1bc:
	/* 0x1bc: mov    rdi,QWORD PTR [rip+0x1e447] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1c3:
	/* 0x1c3: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1c8:
	/* 0x1c8: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1cd:
	/* 0x1cd: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1d2:
	/* 0x1d2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d4:
	/* 0x1d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d6:
	/* 0x1d6: mov    rsi,QWORD PTR [rip+0x1e447] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_1dd:
	/* 0x1dd: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1e2:
	/* 0x1e2: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1e5:
	/* 0x1e5: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_1ea:
	/* 0x1ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ec:
	/* 0x1ec: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_1f2:
	/* 0x1f2: jmp    1b9a <tail_ipv6_to_endpoint+0x1b9a> */
	X86_SIM_X86_JMP(0x1f2, 0x1b9a, x86_l_1b9a);
x86_l_1f7:
	/* 0x1f7: mov    QWORD PTR [rsp+0x20],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953473ULL);
x86_l_200:
	/* 0x200: mov    QWORD PTR [rsp+0x28],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_205:
	/* 0x205: mov    rdi,QWORD PTR [rip+0x1e447] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_20c:
	/* 0x20c: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_211:
	/* 0x211: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_216:
	/* 0x216: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_21b:
	/* 0x21b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_21d:
	/* 0x21d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_21f:
	/* 0x21f: mov    rax,QWORD PTR [rip+0x1e447] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_interface_ifindex)));
x86_l_226:
	/* 0x226: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_228:
	/* 0x228: mov    DWORD PTR [rsp+0xc0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_22f:
	/* 0x22f: mov    DWORD PTR [rsp+0xdc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 944892805120ULL);
x86_l_23a:
	/* 0x23a: mov    rax,QWORD PTR [r15+0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_23e:
	/* 0x23e: mov    QWORD PTR [rsp+0xd0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_246:
	/* 0x246: mov    rax,QWORD PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_24a:
	/* 0x24a: mov    QWORD PTR [rsp+0xc8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_252:
	/* 0x252: mov    rdi,QWORD PTR [rip+0x1e447] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_tail_call_buffer6)));
x86_l_259:
	/* 0x259: lea    rsi,[rsp+0xdc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 220ULL);
x86_l_261:
	/* 0x261: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_266:
	/* 0x266: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_268:
	/* 0x268: mov    r12d,0xffffff48 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967112ULL);
x86_l_26e:
	/* 0x26e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_271:
	/* 0x271: je     1b84 <tail_ipv6_to_endpoint+0x1b84> */
	X86_SIM_X86_JCC(X86_CC_E, 0x271, 0x1b84, x86_l_1b84);
x86_l_277:
	/* 0x277: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_27a:
	/* 0x27a: mov    rax,QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27e:
	/* 0x27e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_281:
	/* 0x281: jne    28e <tail_ipv6_to_endpoint+0x28e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x281, 0x28e, x86_l_28e);
x86_l_283:
	/* 0x283: cmp    QWORD PTR [r14+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_288:
	/* 0x288: je     1b84 <tail_ipv6_to_endpoint+0x1b84> */
	X86_SIM_X86_JCC(X86_CC_E, 0x288, 0x1b84, x86_l_1b84);
x86_l_28e:
	/* 0x28e: mov    ecx,DWORD PTR [r14+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_292:
	/* 0x292: mov    DWORD PTR [rsp+0xa4],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_299:
	/* 0x299: mov    edx,DWORD PTR [r14+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_29d:
	/* 0x29d: mov    esi,DWORD PTR [r14+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2a1:
	/* 0x2a1: mov    r13,QWORD PTR [r14+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2a5:
	/* 0x2a5: mov    rcx,QWORD PTR [rip+0x1e447] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_2ac:
	/* 0x2ac: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2af:
	/* 0x2af: sete   r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_E);
x86_l_2b3:
	/* 0x2b3: mov    DWORD PTR [rsp+0xa0],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_2ba:
	/* 0x2ba: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_2bc:
	/* 0x2bc: and    ecx,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_2bf:
	/* 0x2bf: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2c2:
	/* 0x2c2: jne    2f3 <tail_ipv6_to_endpoint+0x2f3> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2c2, 0x2f3, x86_l_2f3);
x86_l_2c4:
	/* 0x2c4: movzx  edx,WORD PTR [r14+0x3c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 60ULL);
x86_l_2c9:
	/* 0x2c9: test   dl,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_8, 32ULL);
x86_l_2cc:
	/* 0x2cc: jne    2e8 <tail_ipv6_to_endpoint+0x2e8> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2cc, 0x2e8, x86_l_2e8);
x86_l_2ce:
	/* 0x2ce: test   dl,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_8, 16ULL);
x86_l_2d1:
	/* 0x2d1: je     362 <tail_ipv6_to_endpoint+0x362> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2d1, 0x362, x86_l_362);
x86_l_2d7:
	/* 0x2d7: mov    ecx,DWORD PTR [rbx+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2da:
	/* 0x2da: mov    DWORD PTR [rsp+0x20],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2de:
	/* 0x2de: test   DWORD PTR [rsp+0x20],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953474ULL);
x86_l_2e6:
	/* 0x2e6: jne    362 <tail_ipv6_to_endpoint+0x362> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2e6, 0x362, x86_l_362);
x86_l_2e8:
	/* 0x2e8: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2eb:
	/* 0x2eb: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ee:
	/* 0x2ee: jmp    11ba <tail_ipv6_to_endpoint+0x11ba> */
	X86_SIM_X86_JMP(0x2ee, 0x11ba, x86_l_11ba);
x86_l_2f3:
	/* 0x2f3: mov    eax,DWORD PTR [rbx+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2f6:
	/* 0x2f6: mov    DWORD PTR [rsp+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2fa:
	/* 0x2fa: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2fe:
	/* 0x2fe: test   al,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_300:
	/* 0x300: jne    4f5 <tail_ipv6_to_endpoint+0x4f5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x300, 0x4f5, x86_l_4f5);
x86_l_306:
	/* 0x306: mov    rax,QWORD PTR [rip+0x1e447] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_service_loopback_ipv6)));
x86_l_30d:
	/* 0x30d: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_310:
	/* 0x310: mov    QWORD PTR [rsp+0x100],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_318:
	/* 0x318: mov    rax,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31c:
	/* 0x31c: mov    QWORD PTR [rsp+0xf8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_324:
	/* 0x324: cmp    DWORD PTR [rsp+0xa0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_32c:
	/* 0x32c: jne    3c4 <tail_ipv6_to_endpoint+0x3c4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x32c, 0x3c4, x86_l_3c4);
x86_l_332:
	/* 0x332: cmp    QWORD PTR [r15+0x16],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R15, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_336:
	/* 0x336: jne    3c4 <tail_ipv6_to_endpoint+0x3c4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x336, 0x3c4, x86_l_3c4);
x86_l_33c:
	/* 0x33c: cmp    QWORD PTR [r15+0x1e],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_340:
	/* 0x340: jne    3c4 <tail_ipv6_to_endpoint+0x3c4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x340, 0x3c4, x86_l_3c4);
x86_l_346:
	/* 0x346: movzx  eax,BYTE PTR [r14+0x25] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 37ULL);
x86_l_34b:
	/* 0x34b: mov    BYTE PTR [rsp+0x8],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_34f:
	/* 0x34f: cmp    BYTE PTR [r14+0x24],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 154618822662ULL);
x86_l_354:
	/* 0x354: jne    390 <tail_ipv6_to_endpoint+0x390> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x354, 0x390, x86_l_390);
x86_l_356:
	/* 0x356: mov    r15,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSI, X86_WIDTH_64);
x86_l_359:
	/* 0x359: mov    rdi,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct6_global)));
x86_l_360:
	/* 0x360: jmp    39a <tail_ipv6_to_endpoint+0x39a> */
	X86_SIM_X86_JMP(0x360, 0x39a, x86_l_39a);
x86_l_362:
	/* 0x362: movzx  ecx,WORD PTR [r14+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_367:
	/* 0x367: movzx  edi,WORD PTR [r14+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_36c:
	/* 0x36c: test   di,di */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_16);
x86_l_36f:
	/* 0x36f: jne    78d <tail_ipv6_to_endpoint+0x78d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x36f, 0x78d, x86_l_78d);
x86_l_375:
	/* 0x375: test   cx,cx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_16);
x86_l_378:
	/* 0x378: jne    7db <tail_ipv6_to_endpoint+0x7db> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x378, 0x7db, x86_l_7db);
x86_l_37e:
	/* 0x37e: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_381:
	/* 0x381: movabs r13,0x207d30100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 8721203456ULL);
x86_l_38b:
	/* 0x38b: jmp    1369 <tail_ipv6_to_endpoint+0x1369> */
	X86_SIM_X86_JMP(0x38b, 0x1369, x86_l_1369);
x86_l_390:
	/* 0x390: mov    r15,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSI, X86_WIDTH_64);
x86_l_393:
	/* 0x393: mov    rdi,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct_any6_global)));
x86_l_39a:
	/* 0x39a: mov    BYTE PTR [r14+0x25],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 158913789952ULL);
x86_l_39f:
	/* 0x39f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3a4:
	/* 0x3a4: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_3a7:
	/* 0x3a7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a9:
	/* 0x3a9: movzx  ecx,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_3ae:
	/* 0x3ae: mov    BYTE PTR [r14+0x25],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 37ULL);
x86_l_3b2:
	/* 0x3b2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3b5:
	/* 0x3b5: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_3b8:
	/* 0x3b8: je     3c4 <tail_ipv6_to_endpoint+0x3c4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3b8, 0x3c4, x86_l_3c4);
x86_l_3ba:
	/* 0x3ba: test   BYTE PTR [rax+0x24],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 154618822664ULL);
x86_l_3be:
	/* 0x3be: jne    663 <tail_ipv6_to_endpoint+0x663> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3be, 0x663, x86_l_663);
x86_l_3c4:
	/* 0x3c4: test   BYTE PTR [r14+0x3c],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 257698037761ULL);
x86_l_3c9:
	/* 0x3c9: jne    4f5 <tail_ipv6_to_endpoint+0x4f5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3c9, 0x4f5, x86_l_4f5);
x86_l_3cf:
	/* 0x3cf: mov    rax,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_security_label)));
x86_l_3d6:
	/* 0x3d6: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3d8:
	/* 0x3d8: movzx  eax,WORD PTR [r14+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_3dd:
	/* 0x3dd: movzx  r15d,BYTE PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 36ULL);
x86_l_3e2:
	/* 0x3e2: mov    DWORD PTR [rsp+0x58],0x40 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 377957122112ULL);
x86_l_3ea:
	/* 0x3ea: mov    DWORD PTR [rsp+0x5c],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_3ee:
	/* 0x3ee: mov    BYTE PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_3f3:
	/* 0x3f3: mov    BYTE PTR [rsp+0x61],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 97ULL);
x86_l_3f8:
	/* 0x3f8: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3fb:
	/* 0x3fb: mov    WORD PTR [rsp+0x62],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 98ULL);
x86_l_400:
	/* 0x400: mov    rax,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_allow_icmp_frag_needed)));
x86_l_407:
	/* 0x407: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_40a:
	/* 0x40a: jne    418 <tail_ipv6_to_endpoint+0x418> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x40a, 0x418, x86_l_418);
x86_l_40c:
	/* 0x40c: mov    rax,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_icmp_rule)));
x86_l_413:
	/* 0x413: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_416:
	/* 0x416: je     455 <tail_ipv6_to_endpoint+0x455> */
	X86_SIM_X86_JCC(X86_CC_E, 0x416, 0x455, x86_l_455);
x86_l_418:
	/* 0x418: mov    rax,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_icmp_rule)));
x86_l_41f:
	/* 0x41f: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_422:
	/* 0x422: cmp    r15b,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_8, 58ULL);
x86_l_426:
	/* 0x426: jne    455 <tail_ipv6_to_endpoint+0x455> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x426, 0x455, x86_l_455);
x86_l_428:
	/* 0x428: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_42a:
	/* 0x42a: je     455 <tail_ipv6_to_endpoint+0x455> */
	X86_SIM_X86_JCC(X86_CC_E, 0x42a, 0x455, x86_l_455);
x86_l_42c:
	/* 0x42c: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_431:
	/* 0x431: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_436:
	/* 0x436: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_439:
	/* 0x439: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_43e:
	/* 0x43e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_440:
	/* 0x440: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_442:
	/* 0x442: js     532 <tail_ipv6_to_endpoint+0x532> */
	X86_SIM_X86_JCC(X86_CC_S, 0x442, 0x532, x86_l_532);
x86_l_448:
	/* 0x448: movzx  eax,BYTE PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 32ULL);
x86_l_44d:
	/* 0x44d: shl    eax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_450:
	/* 0x450: mov    WORD PTR [rsp+0x62],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 98ULL);
x86_l_455:
	/* 0x455: mov    DWORD PTR [rsp+0x8],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_45a:
	/* 0x45a: mov    rdi,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_policy_v2)));
x86_l_461:
	/* 0x461: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_466:
	/* 0x466: mov    r15d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 1ULL);
x86_l_46c:
	/* 0x46c: call   r15 */
	X86_SIM_BPF_CALL_REG(X86_R15);
x86_l_46f:
	/* 0x46f: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_472:
	/* 0x472: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_475:
	/* 0x475: je     68a <tail_ipv6_to_endpoint+0x68a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x475, 0x68a, x86_l_68a);
x86_l_47b:
	/* 0x47b: cmp    DWORD PTR [rdi+0x4],0xffffffff */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 21474836479ULL);
x86_l_47f:
	/* 0x47f: jne    6cf <tail_ipv6_to_endpoint+0x6cf> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x47f, 0x6cf, x86_l_6cf);
x86_l_485:
	/* 0x485: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_487:
	/* 0x487: movzx  r12d,WORD PTR [rdi+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_48c:
	/* 0x48c: mov    rcx,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_policy_accounting)));
x86_l_493:
	/* 0x493: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_496:
	/* 0x496: mov    r8d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R12, X86_WIDTH_32);
x86_l_499:
	/* 0x499: je     5c6 <tail_ipv6_to_endpoint+0x5c6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x499, 0x5c6, x86_l_5c6);
x86_l_49f:
	/* 0x49f: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_4a2:
	/* 0x4a2: shr    sil,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_8, X86_ALU_SHR, 3ULL);
x86_l_4a6:
	/* 0x4a6: movzx  ecx,BYTE PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 96ULL);
x86_l_4ab:
	/* 0x4ab: mov    r13d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ae:
	/* 0x4ae: mov    rdx,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_endpoint_id)));
x86_l_4b5:
	/* 0x4b5: movzx  edx,WORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4b8:
	/* 0x4b8: mov    WORD PTR [rsp+0x70],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_4bd:
	/* 0x4bd: mov    BYTE PTR [rsp+0x72],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 489626271744ULL);
x86_l_4c2:
	/* 0x4c2: mov    BYTE PTR [rsp+0x73],sil */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 115ULL);
x86_l_4c7:
	/* 0x4c7: and    cl,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 1ULL);
x86_l_4ca:
	/* 0x4ca: mov    DWORD PTR [rsp+0x74],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_4ce:
	/* 0x4ce: mov    BYTE PTR [rsp+0x78],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_4d2:
	/* 0x4d2: cmp    r12b,0x47 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_8, 71ULL);
x86_l_4d6:
	/* 0x4d6: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4db:
	/* 0x4db: mov    r15,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDI, X86_WIDTH_64);
x86_l_4de:
	/* 0x4de: ja     50e <tail_ipv6_to_endpoint+0x50e> */
	X86_SIM_X86_JCC(X86_CC_A, 0x4de, 0x50e, x86_l_50e);
x86_l_4e0:
	/* 0x4e0: movzx  eax,sil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RSI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_4e4:
	/* 0x4e4: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4e6:
	/* 0x4e6: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_4e9:
	/* 0x4e9: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ed:
	/* 0x4ed: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_4f0:
	/* 0x4f0: cmovne eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_NE);
x86_l_4f3:
	/* 0x4f3: jmp    562 <tail_ipv6_to_endpoint+0x562> */
	X86_SIM_X86_JMP(0x4f3, 0x562, x86_l_562);
x86_l_4f5:
	/* 0x4f5: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4fc:
	/* 0x4fc: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4ff:
	/* 0x4ff: movabs r13,0x207d30100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 8721203456ULL);
x86_l_509:
	/* 0x509: jmp    f42 <tail_ipv6_to_endpoint+0xf42> */
	X86_SIM_X86_JMP(0x509, 0xf42, x86_l_f42);
x86_l_50e:
	/* 0x50e: cmp    r12b,0xbf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_8, 191ULL);
x86_l_512:
	/* 0x512: ja     55b <tail_ipv6_to_endpoint+0x55b> */
	X86_SIM_X86_JCC(X86_CC_A, 0x512, 0x55b, x86_l_55b);
x86_l_514:
	/* 0x514: mov    cl,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 24ULL);
x86_l_516:
	/* 0x516: sub    cl,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_8, X86_ALU_SUB);
x86_l_519:
	/* 0x519: mov    eax,0xffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 65535ULL);
x86_l_51e:
	/* 0x51e: shlx   eax,eax,ecx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RAX, X86_RAX, X86_WIDTH_32, X86_RCX, X86_ALU_SHL);
x86_l_523:
	/* 0x523: rol    ax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_527:
	/* 0x527: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_52a:
	/* 0x52a: and    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_AND);
x86_l_52c:
	/* 0x52c: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_530:
	/* 0x530: jmp    562 <tail_ipv6_to_endpoint+0x562> */
	X86_SIM_X86_JMP(0x530, 0x562, x86_l_562);
x86_l_532:
	/* 0x532: mov    r12d,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967162ULL);
x86_l_538:
	/* 0x538: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_53a:
	/* 0x53a: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_53c:
	/* 0x53c: mov    dil,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_8, 1ULL);
x86_l_53f:
	/* 0x53f: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_542:
	/* 0x542: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_545:
	/* 0x545: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_54c:
	/* 0x54c: movabs r13,0x207d30100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 8721203456ULL);
x86_l_556:
	/* 0x556: jmp    bfa <tail_ipv6_to_endpoint+0xbfa> */
	X86_SIM_X86_JMP(0x556, 0xbfa, x86_l_bfa);
x86_l_55b:
	/* 0x55b: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_55f:
	/* 0x55f: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_562:
	/* 0x562: mov    BYTE PTR [rsp+0x79],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 121ULL);
x86_l_566:
	/* 0x566: mov    WORD PTR [rsp+0x7a],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 122ULL);
x86_l_56b:
	/* 0x56b: mov    rdi,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_policystats)));
x86_l_572:
	/* 0x572: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_577:
	/* 0x577: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_57c:
	/* 0x57c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_57e:
	/* 0x57e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_581:
	/* 0x581: je     58e <tail_ipv6_to_endpoint+0x58e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x581, 0x58e, x86_l_58e);
x86_l_583:
	/* 0x583: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_587:
	/* 0x587: add QWORD PTR [rax+0x8],r13 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_58c:
	/* 0x58c: jmp    5b9 <tail_ipv6_to_endpoint+0x5b9> */
	X86_SIM_X86_JMP(0x58c, 0x5b9, x86_l_5b9);
x86_l_58e:
	/* 0x58e: mov    QWORD PTR [rsp+0x20],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953473ULL);
x86_l_597:
	/* 0x597: mov    QWORD PTR [rsp+0x28],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_59c:
	/* 0x59c: mov    rdi,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_policystats)));
x86_l_5a3:
	/* 0x5a3: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_5a8:
	/* 0x5a8: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5ad:
	/* 0x5ad: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5b2:
	/* 0x5b2: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_5b7:
	/* 0x5b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b9:
	/* 0x5b9: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_5bc:
	/* 0x5bc: movzx  r8d,WORD PTR [r15+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_5c1:
	/* 0x5c1: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5c6:
	/* 0x5c6: cmp    r12b,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_8, 8ULL);
x86_l_5ca:
	/* 0x5ca: setae  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_AE);
x86_l_5cd:
	/* 0x5cd: shl    cl,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_SHL, 2ULL);
x86_l_5d0:
	/* 0x5d0: or     cl,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_OR, 1ULL);
x86_l_5d3:
	/* 0x5d3: cmp    r12b,0x48 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_8, 72ULL);
x86_l_5d7:
	/* 0x5d7: movzx  ecx,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_5da:
	/* 0x5da: mov    edx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_5df:
	/* 0x5df: cmovb  edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_B);
x86_l_5e2:
	/* 0x5e2: mov    esi,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5e5:
	/* 0x5e5: test   r8b,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R8, X86_WIDTH_8, 1ULL);
x86_l_5e9:
	/* 0x5e9: movabs r13,0x207d30100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 8721203456ULL);
x86_l_5f3:
	/* 0x5f3: jne    af0 <tail_ipv6_to_endpoint+0xaf0> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x5f3, 0xaf0, x86_l_af0);
x86_l_5f9:
	/* 0x5f9: movzx  r15d,r8w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R8, X86_WIDTH_32, X86_WIDTH_16);
x86_l_5fd:
	/* 0x5fd: shr    r15d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_601:
	/* 0x601: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_604:
	/* 0x604: je     627 <tail_ipv6_to_endpoint+0x627> */
	X86_SIM_X86_JCC(X86_CC_E, 0x604, 0x627, x86_l_627);
x86_l_606:
	/* 0x606: test   r8w,r8w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R8, X86_R8, X86_WIDTH_16);
x86_l_60a:
	/* 0x60a: js     627 <tail_ipv6_to_endpoint+0x627> */
	X86_SIM_X86_JCC(X86_CC_S, 0x60a, 0x627, x86_l_627);
x86_l_60c:
	/* 0x60c: mov    ecx,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_60f:
	/* 0x60f: cmp    DWORD PTR [rax+0x4],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_612:
	/* 0x612: jne    627 <tail_ipv6_to_endpoint+0x627> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x612, 0x627, x86_l_627);
x86_l_614:
	/* 0x614: movzx  eax,BYTE PTR [rax+0x3] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 3ULL);
x86_l_618:
	/* 0x618: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_61a:
	/* 0x61a: and    ecx,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 127ULL);
x86_l_61d:
	/* 0x61d: cmp    cx,r15w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R15, X86_WIDTH_16);
x86_l_621:
	/* 0x621: ja     95d <tail_ipv6_to_endpoint+0x95d> */
	X86_SIM_X86_JCC(X86_CC_A, 0x621, 0x95d, x86_l_95d);
x86_l_627:
	/* 0x627: movzx  eax,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_62a:
	/* 0x62a: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_62d:
	/* 0x62d: and    r15b,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_8, X86_ALU_AND, 127ULL);
x86_l_631:
	/* 0x631: jne    a21 <tail_ipv6_to_endpoint+0xa21> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x631, 0xa21, x86_l_a21);
x86_l_637:
	/* 0x637: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_63a:
	/* 0x63a: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_63d:
	/* 0x63d: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_640:
	/* 0x640: setne  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_NE);
x86_l_644:
	/* 0x644: cmp    DWORD PTR [rsp+0xa0],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 687194767361ULL);
x86_l_64c:
	/* 0x64c: jne    bf7 <tail_ipv6_to_endpoint+0xbf7> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x64c, 0xbf7, x86_l_bf7);
x86_l_652:
	/* 0x652: mov    r8d,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R15, X86_WIDTH_32);
x86_l_655:
	/* 0x655: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_658:
	/* 0x658: je     11ac <tail_ipv6_to_endpoint+0x11ac> */
	X86_SIM_X86_JCC(X86_CC_E, 0x658, 0x11ac, x86_l_11ac);
x86_l_65e:
	/* 0x65e: jmp    bfa <tail_ipv6_to_endpoint+0xbfa> */
	X86_SIM_X86_JMP(0x65e, 0xbfa, x86_l_bfa);
x86_l_663:
	/* 0x663: mov    ax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 1ULL);
x86_l_667:
	/* 0x667: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_66e:
	/* 0x66e: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_671:
	/* 0x671: jmp    f5d <tail_ipv6_to_endpoint+0xf5d> */
	X86_SIM_X86_JMP(0x671, 0xf5d, x86_l_f5d);
x86_l_676:
	/* 0x676: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_679:
	/* 0x679: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_67c:
	/* 0x67c: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_67f:
	/* 0x67f: jns    1b90 <tail_ipv6_to_endpoint+0x1b90> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x67f, 0x1b90, x86_l_1b90);
x86_l_685:
	/* 0x685: jmp    34 <tail_ipv6_to_endpoint+0x34> */
	X86_SIM_X86_JMP(0x685, 0x34, x86_l_34);
x86_l_68a:
	/* 0x68a: mov    DWORD PTR [rsp+0x5c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 395136991232ULL);
x86_l_692:
	/* 0x692: mov    QWORD PTR [rsp+0x18],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_697:
	/* 0x697: mov    rdi,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_policy_v2)));
x86_l_69e:
	/* 0x69e: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_6a3:
	/* 0x6a3: call   r15 */
	X86_SIM_BPF_CALL_REG(X86_R15);
x86_l_6a6:
	/* 0x6a6: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6ab:
	/* 0x6ab: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6ae:
	/* 0x6ae: jne    70c <tail_ipv6_to_endpoint+0x70c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x6ae, 0x70c, x86_l_70c);
x86_l_6b0:
	/* 0x6b0: shr    r13,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_SHR, 40ULL);
x86_l_6b4:
	/* 0x6b4: and    r13d,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 1ULL);
x86_l_6b8:
	/* 0x6b8: and    r12b,r13b */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R13, X86_WIDTH_8, X86_ALU_AND);
x86_l_6bb:
	/* 0x6bb: mov    eax,0xffffff63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967139ULL);
x86_l_6c0:
	/* 0x6c0: mov    r12d,0xffffff7b */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967163ULL);
x86_l_6c6:
	/* 0x6c6: cmovne r12d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RAX, X86_WIDTH_32, X86_CC_NE);
x86_l_6ca:
	/* 0x6ca: jmp    538 <tail_ipv6_to_endpoint+0x538> */
	X86_SIM_X86_JMP(0x6ca, 0x538, x86_l_538);
x86_l_6cf:
	/* 0x6cf: mov    r15,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDI, X86_WIDTH_64);
x86_l_6d2:
	/* 0x6d2: mov    DWORD PTR [rsp+0x5c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 395136991232ULL);
x86_l_6da:
	/* 0x6da: mov    rdi,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_policy_v2)));
x86_l_6e1:
	/* 0x6e1: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_6e6:
	/* 0x6e6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6eb:
	/* 0x6eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6ed:
	/* 0x6ed: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6f0:
	/* 0x6f0: je     8d6 <tail_ipv6_to_endpoint+0x8d6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6f0, 0x8d6, x86_l_8d6);
x86_l_6f6:
	/* 0x6f6: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_6f9:
	/* 0x6f9: mov    eax,DWORD PTR [r15+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_6fd:
	/* 0x6fd: cmp    DWORD PTR [rcx+0x4],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_700:
	/* 0x700: jbe    92e <tail_ipv6_to_endpoint+0x92e> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x700, 0x92e, x86_l_92e);
x86_l_706:
	/* 0x706: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_709:
	/* 0x709: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_70c:
	/* 0x70c: mov    QWORD PTR [rsp+0x18],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_711:
	/* 0x711: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_714:
	/* 0x714: movzx  r12d,WORD PTR [rax+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_719:
	/* 0x719: mov    rax,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_policy_accounting)));
x86_l_720:
	/* 0x720: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_723:
	/* 0x723: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_726:
	/* 0x726: je     9a5 <tail_ipv6_to_endpoint+0x9a5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x726, 0x9a5, x86_l_9a5);
x86_l_72c:
	/* 0x72c: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_72f:
	/* 0x72f: shr    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHR, 3ULL);
x86_l_732:
	/* 0x732: movzx  ecx,BYTE PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 96ULL);
x86_l_737:
	/* 0x737: mov    r15d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_73a:
	/* 0x73a: mov    rdx,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_endpoint_id)));
x86_l_741:
	/* 0x741: movzx  edx,WORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_744:
	/* 0x744: mov    WORD PTR [rsp+0x70],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_749:
	/* 0x749: mov    BYTE PTR [rsp+0x72],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 489626271744ULL);
x86_l_74e:
	/* 0x74e: mov    BYTE PTR [rsp+0x73],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 115ULL);
x86_l_752:
	/* 0x752: and    cl,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 1ULL);
x86_l_755:
	/* 0x755: mov    DWORD PTR [rsp+0x74],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 498216206336ULL);
x86_l_75d:
	/* 0x75d: mov    BYTE PTR [rsp+0x78],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_761:
	/* 0x761: cmp    r12b,0x47 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_8, 71ULL);
x86_l_765:
	/* 0x765: ja     8e0 <tail_ipv6_to_endpoint+0x8e0> */
	X86_SIM_X86_JCC(X86_CC_A, 0x765, 0x8e0, x86_l_8e0);
x86_l_76b:
	/* 0x76b: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_76e:
	/* 0x76e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_770:
	/* 0x770: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_773:
	/* 0x773: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_777:
	/* 0x777: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_77a:
	/* 0x77a: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_781:
	/* 0x781: cmovne eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_NE);
x86_l_784:
	/* 0x784: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_788:
	/* 0x788: jmp    8fb <tail_ipv6_to_endpoint+0x8fb> */
	X86_SIM_X86_JMP(0x788, 0x8fb, x86_l_8fb);
x86_l_78d:
	/* 0x78d: mov    QWORD PTR [rsp+0x8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_792:
	/* 0x792: test   dl,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_8, 1ULL);
x86_l_795:
	/* 0x795: sete   r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_E);
x86_l_799:
	/* 0x799: bt     r13,0x29 */
	X86_SIM_L_EXEC_BT_IMM(X86_R13, X86_WIDTH_64, 41ULL);
x86_l_79e:
	/* 0x79e: setae  r13b */
	X86_SIM_L_EXEC_SETCC(X86_R13, X86_CC_AE);
x86_l_7a2:
	/* 0x7a2: test   cx,cx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_16);
x86_l_7a5:
	/* 0x7a5: jne    7f0 <tail_ipv6_to_endpoint+0x7f0> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x7a5, 0x7f0, x86_l_7f0);
x86_l_7a7:
	/* 0x7a7: mov    WORD PTR [rsp+0x70],di */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_7ac:
	/* 0x7ac: mov    rax,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_7b3:
	/* 0x7b3: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_7b6:
	/* 0x7b6: mov    rdi,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb6_reverse_nat)));
x86_l_7bd:
	/* 0x7bd: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_7c2:
	/* 0x7c2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7c7:
	/* 0x7c7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7c9:
	/* 0x7c9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7cc:
	/* 0x7cc: je     37e <tail_ipv6_to_endpoint+0x37e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7cc, 0x37e, x86_l_37e);
x86_l_7d2:
	/* 0x7d2: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_7d5:
	/* 0x7d5: mov    rax,QWORD PTR [r14+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7d9:
	/* 0x7d9: jmp    80c <tail_ipv6_to_endpoint+0x80c> */
	X86_SIM_X86_JMP(0x7d9, 0x80c, x86_l_80c);
x86_l_7db:
	/* 0x7db: mov    QWORD PTR [rsp+0x8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7e0:
	/* 0x7e0: test   dl,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_8, 1ULL);
x86_l_7e3:
	/* 0x7e3: sete   r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_E);
x86_l_7e7:
	/* 0x7e7: bt     r13,0x29 */
	X86_SIM_L_EXEC_BT_IMM(X86_R13, X86_WIDTH_64, 41ULL);
x86_l_7ec:
	/* 0x7ec: setae  r13b */
	X86_SIM_L_EXEC_SETCC(X86_R13, X86_CC_AE);
x86_l_7f0:
	/* 0x7f0: mov    rdx,QWORD PTR [r14+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7f4:
	/* 0x7f4: mov    QWORD PTR [rsp+0x28],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_7f9:
	/* 0x7f9: mov    rdx,QWORD PTR [r14+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_7fd:
	/* 0x7fd: mov    QWORD PTR [rsp+0x20],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_802:
	/* 0x802: mov    WORD PTR [rsp+0x30],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_807:
	/* 0x807: lea    r15,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_80c:
	/* 0x80c: mov    rcx,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_813:
	/* 0x813: movzx  edx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_816:
	/* 0x816: mov    rdx,QWORD PTR [r14+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_81a:
	/* 0x81a: mov    QWORD PTR [rsp+0x78],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_81f:
	/* 0x81f: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_824:
	/* 0x824: mov    rax,QWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_828:
	/* 0x828: mov    QWORD PTR [r14+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_82c:
	/* 0x82c: mov    rax,QWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_82f:
	/* 0x82f: mov    QWORD PTR [r14+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_833:
	/* 0x833: test   r12b,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_8);
x86_l_836:
	/* 0x836: jne    19ed <tail_ipv6_to_endpoint+0x19ed> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x836, 0x19ed, x86_l_19ed);
x86_l_83c:
	/* 0x83c: mov    rax,QWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_840:
	/* 0x840: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_845:
	/* 0x845: mov    rax,QWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_848:
	/* 0x848: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_84d:
	/* 0x84d: movzx  eax,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_850:
	/* 0x850: lea    rdx,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_855:
	/* 0x855: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_85a:
	/* 0x85a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_85d:
	/* 0x85d: mov    esi,0x26 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 38ULL);
x86_l_862:
	/* 0x862: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_867:
	/* 0x867: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_86a:
	/* 0x86a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_86c:
	/* 0x86c: mov    r12d,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967155ULL);
x86_l_872:
	/* 0x872: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_874:
	/* 0x874: js     1b84 <tail_ipv6_to_endpoint+0x1b84> */
	X86_SIM_X86_JCC(X86_CC_S, 0x874, 0x1b84, x86_l_1b84);
x86_l_87a:
	/* 0x87a: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_87d:
	/* 0x87d: je     1b84 <tail_ipv6_to_endpoint+0x1b84> */
	X86_SIM_X86_JCC(X86_CC_E, 0x87d, 0x1b84, x86_l_1b84);
x86_l_883:
	/* 0x883: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_888:
	/* 0x888: mov    QWORD PTR [r14+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_88c:
	/* 0x88c: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_891:
	/* 0x891: mov    QWORD PTR [r14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_894:
	/* 0x894: test   r13b,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_8);
x86_l_897:
	/* 0x897: je     19ed <tail_ipv6_to_endpoint+0x19ed> */
	X86_SIM_X86_JCC(X86_CC_E, 0x897, 0x19ed, x86_l_19ed);
x86_l_89d:
	/* 0x89d: movzx  eax,BYTE PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 36ULL);
x86_l_8a2:
	/* 0x8a2: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8a9:
	/* 0x8a9: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_8ac:
	/* 0x8ac: je     197e <tail_ipv6_to_endpoint+0x197e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8ac, 0x197e, x86_l_197e);
x86_l_8b2:
	/* 0x8b2: cmp    eax,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 58ULL);
x86_l_8b5:
	/* 0x8b5: je     1976 <tail_ipv6_to_endpoint+0x1976> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8b5, 0x1976, x86_l_1976);
x86_l_8bb:
	/* 0x8bb: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_8be:
	/* 0x8be: jne    19ed <tail_ipv6_to_endpoint+0x19ed> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x8be, 0x19ed, x86_l_19ed);
x86_l_8c4:
	/* 0x8c4: mov    DWORD PTR [rsp],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_8cb:
	/* 0x8cb: mov    r12d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 6ULL);
x86_l_8d1:
	/* 0x8d1: jmp    1984 <tail_ipv6_to_endpoint+0x1984> */
	X86_SIM_X86_JMP(0x8d1, 0x1984, x86_l_1984);
x86_l_8d6:
	/* 0x8d6: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8d8:
	/* 0x8d8: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_8db:
	/* 0x8db: jmp    487 <tail_ipv6_to_endpoint+0x487> */
	X86_SIM_X86_JMP(0x8db, 0x487, x86_l_487);
x86_l_8e0:
	/* 0x8e0: cmp    r12b,0xbf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_8, 191ULL);
x86_l_8e4:
	/* 0x8e4: ja     8fb <tail_ipv6_to_endpoint+0x8fb> */
	X86_SIM_X86_JCC(X86_CC_A, 0x8e4, 0x8fb, x86_l_8fb);
x86_l_8e6:
	/* 0x8e6: mov    cl,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 24ULL);
x86_l_8e8:
	/* 0x8e8: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_8ea:
	/* 0x8ea: mov    eax,0xffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 65535ULL);
x86_l_8ef:
	/* 0x8ef: shlx   eax,eax,ecx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RAX, X86_RAX, X86_WIDTH_32, X86_RCX, X86_ALU_SHL);
x86_l_8f4:
	/* 0x8f4: rol    ax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_8f8:
	/* 0x8f8: and    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 0ULL);
x86_l_8fb:
	/* 0x8fb: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8ff:
	/* 0x8ff: mov    BYTE PTR [rsp+0x79],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 121ULL);
x86_l_903:
	/* 0x903: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_906:
	/* 0x906: mov    WORD PTR [rsp+0x7a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 122ULL);
x86_l_90b:
	/* 0x90b: mov    rdi,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_policystats)));
x86_l_912:
	/* 0x912: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_917:
	/* 0x917: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_91c:
	/* 0x91c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_91e:
	/* 0x91e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_921:
	/* 0x921: je     975 <tail_ipv6_to_endpoint+0x975> */
	X86_SIM_X86_JCC(X86_CC_E, 0x921, 0x975, x86_l_975);
x86_l_923:
	/* 0x923: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_927:
	/* 0x927: add QWORD PTR [rax+0x8],r15 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_92c:
	/* 0x92c: jmp    9a0 <tail_ipv6_to_endpoint+0x9a0> */
	X86_SIM_X86_JMP(0x92c, 0x9a0, x86_l_9a0);
x86_l_92e:
	/* 0x92e: jne    196b <tail_ipv6_to_endpoint+0x196b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x92e, 0x196b, x86_l_196b);
x86_l_934:
	/* 0x934: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_937:
	/* 0x937: movzx  edx,WORD PTR [rcx+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_93b:
	/* 0x93b: shr    edx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 3ULL);
x86_l_93e:
	/* 0x93e: and    edx,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 31ULL);
x86_l_941:
	/* 0x941: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_944:
	/* 0x944: movzx  ecx,WORD PTR [r15+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_949:
	/* 0x949: shr    ecx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 3ULL);
x86_l_94c:
	/* 0x94c: and    ecx,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 31ULL);
x86_l_94f:
	/* 0x94f: cmp    dx,cx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_16);
x86_l_952:
	/* 0x952: jbe    487 <tail_ipv6_to_endpoint+0x487> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x952, 0x487, x86_l_487);
x86_l_958:
	/* 0x958: jmp    70c <tail_ipv6_to_endpoint+0x70c> */
	X86_SIM_X86_JMP(0x958, 0x70c, x86_l_70c);
x86_l_95d:
	/* 0x95d: mov    r15d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_32);
x86_l_960:
	/* 0x960: movzx  eax,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_963:
	/* 0x963: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_966:
	/* 0x966: and    r15b,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_8, X86_ALU_AND, 127ULL);
x86_l_96a:
	/* 0x96a: je     637 <tail_ipv6_to_endpoint+0x637> */
	X86_SIM_X86_JCC(X86_CC_E, 0x96a, 0x637, x86_l_637);
x86_l_970:
	/* 0x970: jmp    a21 <tail_ipv6_to_endpoint+0xa21> */
	X86_SIM_X86_JMP(0x970, 0xa21, x86_l_a21);
x86_l_975:
	/* 0x975: mov    QWORD PTR [rsp+0x20],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953473ULL);
x86_l_97e:
	/* 0x97e: mov    QWORD PTR [rsp+0x28],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_983:
	/* 0x983: mov    rdi,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_policystats)));
x86_l_98a:
	/* 0x98a: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_98f:
	/* 0x98f: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_994:
	/* 0x994: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_999:
	/* 0x999: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_99e:
	/* 0x99e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9a0:
	/* 0x9a0: movzx  eax,WORD PTR [r13+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_9a5:
	/* 0x9a5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9a7:
	/* 0x9a7: cmp    r12b,0x48 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_8, 72ULL);
x86_l_9ab:
	/* 0x9ab: setb   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_B);
x86_l_9ae:
	/* 0x9ae: cmp    r12b,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_8, 8ULL);
x86_l_9b2:
	/* 0x9b2: lea    ecx,[rcx+rcx*2+0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 1), 3ULL);
x86_l_9b6:
	/* 0x9b6: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_9bb:
	/* 0x9bb: cmovae edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_AE);
x86_l_9be:
	/* 0x9be: mov    esi,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9c2:
	/* 0x9c2: test   al,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_9c4:
	/* 0x9c4: jne    af0 <tail_ipv6_to_endpoint+0xaf0> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x9c4, 0xaf0, x86_l_af0);
x86_l_9ca:
	/* 0x9ca: movzx  r15d,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_9ce:
	/* 0x9ce: shr    r15d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_9d2:
	/* 0x9d2: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_9d8:
	/* 0x9d8: je     a05 <tail_ipv6_to_endpoint+0xa05> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9d8, 0xa05, x86_l_a05);
x86_l_9da:
	/* 0x9da: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_9dd:
	/* 0x9dd: js     a05 <tail_ipv6_to_endpoint+0xa05> */
	X86_SIM_X86_JCC(X86_CC_S, 0x9dd, 0xa05, x86_l_a05);
x86_l_9df:
	/* 0x9df: mov    eax,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_9e3:
	/* 0x9e3: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_9e8:
	/* 0x9e8: cmp    DWORD PTR [rcx+0x4],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_9eb:
	/* 0x9eb: jne    a05 <tail_ipv6_to_endpoint+0xa05> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x9eb, 0xa05, x86_l_a05);
x86_l_9ed:
	/* 0x9ed: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_9f2:
	/* 0x9f2: movzx  eax,BYTE PTR [rax+0x3] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 3ULL);
x86_l_9f6:
	/* 0x9f6: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_9f8:
	/* 0x9f8: and    ecx,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 127ULL);
x86_l_9fb:
	/* 0x9fb: cmp    cx,r15w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R15, X86_WIDTH_16);
x86_l_9ff:
	/* 0x9ff: ja     1bd7 <tail_ipv6_to_endpoint+0x1bd7> */
	X86_SIM_X86_JCC(X86_CC_A, 0x9ff, 0x1bd7, x86_l_1bd7);
x86_l_a05:
	/* 0xa05: movzx  eax,WORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_a0a:
	/* 0xa0a: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a0d:
	/* 0xa0d: and    r15b,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_8, X86_ALU_AND, 127ULL);
x86_l_a11:
	/* 0xa11: movabs r13,0x207d30100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 8721203456ULL);
x86_l_a1b:
	/* 0xa1b: je     637 <tail_ipv6_to_endpoint+0x637> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa1b, 0x637, x86_l_637);
x86_l_a21:
	/* 0xa21: mov    DWORD PTR [rsp+0x98],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_a28:
	/* 0xa28: mov    DWORD PTR [rsp+0x18],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_a2c:
	/* 0xa2c: movabs rax,0x2000000000000a0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 144115188075856032ULL);
x86_l_a36:
	/* 0xa36: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a3b:
	/* 0xa3b: mov    rax,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_a43:
	/* 0xa43: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a48:
	/* 0xa48: mov    rax,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_a50:
	/* 0xa50: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a55:
	/* 0xa55: mov    rdi,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipcache_v2)));
x86_l_a5c:
	/* 0xa5c: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a61:
	/* 0xa61: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a66:
	/* 0xa66: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a68:
	/* 0xa68: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a6b:
	/* 0xa6b: je     afb <tail_ipv6_to_endpoint+0xafb> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa6b, 0xafb, x86_l_afb);
x86_l_a71:
	/* 0xa71: mov    rcx,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_security_label)));
x86_l_a78:
	/* 0xa78: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a7a:
	/* 0xa7a: mov    eax,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_a7d:
	/* 0xa7d: mov    DWORD PTR [rsp+0x70],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_a81:
	/* 0xa81: mov    DWORD PTR [rsp+0x74],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_a85:
	/* 0xa85: mov    WORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_a8c:
	/* 0xa8c: mov    BYTE PTR [rsp+0x7a],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 122ULL);
x86_l_a91:
	/* 0xa91: mov    BYTE PTR [rsp+0x7b],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 528280977408ULL);
x86_l_a96:
	/* 0xa96: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a98:
	/* 0xa98: je     b21 <tail_ipv6_to_endpoint+0xb21> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa98, 0xb21, x86_l_b21);
x86_l_a9e:
	/* 0xa9e: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_aa7:
	/* 0xaa7: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_aaf:
	/* 0xaaf: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_ab8:
	/* 0xab8: mov    BYTE PTR [rsp+0x23],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 150323855361ULL);
x86_l_abd:
	/* 0xabd: mov    DWORD PTR [rsp+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_ac1:
	/* 0xac1: mov    rdi,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_node_map_v2)));
x86_l_ac8:
	/* 0xac8: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_acd:
	/* 0xacd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ad2:
	/* 0xad2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ad4:
	/* 0xad4: mov    r12d,0xffffff3b */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967099ULL);
x86_l_ada:
	/* 0xada: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_add:
	/* 0xadd: je     bcd <tail_ipv6_to_endpoint+0xbcd> */
	X86_SIM_X86_JCC(X86_CC_E, 0xadd, 0xbcd, x86_l_bcd);
x86_l_ae3:
	/* 0xae3: movzx  eax,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_ae6:
	/* 0xae6: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_ae9:
	/* 0xae9: jne    b23 <tail_ipv6_to_endpoint+0xb23> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xae9, 0xb23, x86_l_b23);
x86_l_aeb:
	/* 0xaeb: jmp    bcd <tail_ipv6_to_endpoint+0xbcd> */
	X86_SIM_X86_JMP(0xaeb, 0xbcd, x86_l_bcd);
x86_l_af0:
	/* 0xaf0: mov    r12d,0xffffff4b */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967115ULL);
x86_l_af6:
	/* 0xaf6: jmp    53c <tail_ipv6_to_endpoint+0x53c> */
	X86_SIM_X86_JMP(0xaf6, 0x53c, x86_l_53c);
x86_l_afb:
	/* 0xafb: mov    r12d,0xffffff43 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967107ULL);
x86_l_b01:
	/* 0xb01: mov    dil,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_8, 1ULL);
x86_l_b04:
	/* 0xb04: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b07:
	/* 0xb07: movabs r13,0x207d30100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 8721203456ULL);
x86_l_b11:
	/* 0xb11: mov    edx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b15:
	/* 0xb15: mov    esi,DWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_b1c:
	/* 0xb1c: jmp    bfa <tail_ipv6_to_endpoint+0xbfa> */
	X86_SIM_X86_JMP(0xb1c, 0xbfa, x86_l_bfa);
x86_l_b21:
	/* 0xb21: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b23:
	/* 0xb23: mov    WORD PTR [rsp+0x78],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_b28:
	/* 0xb28: mov    rdi,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_auth_map)));
x86_l_b2f:
	/* 0xb2f: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_b34:
	/* 0xb34: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b39:
	/* 0xb39: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b3b:
	/* 0xb3b: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b40:
	/* 0xb40: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b43:
	/* 0xb43: je     b8c <tail_ipv6_to_endpoint+0xb8c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb43, 0xb8c, x86_l_b8c);
x86_l_b45:
	/* 0xb45: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b48:
	/* 0xb48: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_b4d:
	/* 0xb4d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b4f:
	/* 0xb4f: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_b51:
	/* 0xb51: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_b54:
	/* 0xb54: shr    r13,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_b58:
	/* 0xb58: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_b60:
	/* 0xb60: mov    rdi,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_runtime_config)));
x86_l_b67:
	/* 0xb67: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b6c:
	/* 0xb6c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b71:
	/* 0xb71: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b73:
	/* 0xb73: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b76:
	/* 0xb76: je     1bbf <tail_ipv6_to_endpoint+0x1bbf> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb76, 0x1bbf, x86_l_1bbf);
x86_l_b7c:
	/* 0xb7c: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b7f:
	/* 0xb7f: add    rax,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_b82:
	/* 0xb82: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b87:
	/* 0xb87: cmp    rax,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_b8a:
	/* 0xb8a: jb     bcd <tail_ipv6_to_endpoint+0xbcd> */
	X86_SIM_X86_JCC(X86_CC_B, 0xb8a, 0xbcd, x86_l_bcd);
x86_l_b8c:
	/* 0xb8c: mov    DWORD PTR [rsp+0x20],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953474ULL);
x86_l_b94:
	/* 0xb94: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_b99:
	/* 0xb99: mov    QWORD PTR [rsp+0x24],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_b9e:
	/* 0xb9e: mov    eax,DWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_ba2:
	/* 0xba2: mov    DWORD PTR [rsp+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_ba6:
	/* 0xba6: mov    rsi,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_signals)));
x86_l_bad:
	/* 0xbad: lea    rcx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_bb2:
	/* 0xbb2: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_bb7:
	/* 0xbb7: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_bbc:
	/* 0xbbc: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_bbf:
	/* 0xbbf: mov    r8d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 16ULL);
x86_l_bc5:
	/* 0xbc5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bc7:
	/* 0xbc7: mov    r12d,0xffffff43 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967107ULL);
x86_l_bcd:
	/* 0xbcd: movabs r13,0x207d30100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 8721203456ULL);
x86_l_bd7:
	/* 0xbd7: mov    edx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_bdb:
	/* 0xbdb: mov    esi,DWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_be2:
	/* 0xbe2: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_be5:
	/* 0xbe5: setne  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_NE);
x86_l_be9:
	/* 0xbe9: cmp    DWORD PTR [rsp+0xa0],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 687194767361ULL);
x86_l_bf1:
	/* 0xbf1: je     652 <tail_ipv6_to_endpoint+0x652> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbf1, 0x652, x86_l_652);
x86_l_bf7:
	/* 0xbf7: mov    r8d,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R15, X86_WIDTH_32);
x86_l_bfa:
	/* 0xbfa: mov    DWORD PTR [rsp+0x8],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bff:
	/* 0xbff: movzx  r9d,WORD PTR [r14+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_c04:
	/* 0xc04: movzx  r10d,BYTE PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 36ULL);
x86_l_c09:
	/* 0xc09: mov    r11d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c0c:
	/* 0xc0c: mov    rax,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_c13:
	/* 0xc13: mov    r15d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c16:
	/* 0xc16: cmp    r11d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R11, X86_R15, X86_WIDTH_32);
x86_l_c19:
	/* 0xc19: cmovb  r15d,r11d */
	X86_SIM_L_EXEC_CMOV(X86_R15, X86_R11, X86_WIDTH_32, X86_CC_B);
x86_l_c1d:
	/* 0xc1d: mov    QWORD PTR [rsp+0x58],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122050ULL);
x86_l_c26:
	/* 0xc26: mov    rax,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_policy_verdict_log_filter)));
x86_l_c2d:
	/* 0xc2d: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c2f:
	/* 0xc2f: mov    BYTE PTR [rsp+0x20],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 137438953473ULL);
x86_l_c34:
	/* 0xc34: movzx  ecx,BYTE PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 32ULL);
x86_l_c39:
	/* 0xc39: test   eax,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_c3b:
	/* 0xc3b: je     f34 <tail_ipv6_to_endpoint+0xf34> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc3b, 0xf34, x86_l_f34);
x86_l_c41:
	/* 0xc41: mov    BYTE PTR [rsp+0x10],dil */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c46:
	/* 0xc46: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_c49:
	/* 0xc49: movzx  edi,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_c4d:
	/* 0xc4d: cmovne edi,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RDI, X86_R12, X86_WIDTH_32, X86_CC_NE);
x86_l_c51:
	/* 0xc51: mov    rax,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_events_map_rate_limit)));
x86_l_c58:
	/* 0xc58: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c5b:
	/* 0xc5b: je     e9c <tail_ipv6_to_endpoint+0xe9c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc5b, 0xe9c, x86_l_e9c);
x86_l_c61:
	/* 0xc61: mov    DWORD PTR [rsp+0xb8],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_c68:
	/* 0xc68: mov    DWORD PTR [rsp+0xbc],r11d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_c70:
	/* 0xc70: mov    BYTE PTR [rsp+0x7],r10b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R10, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_c75:
	/* 0xc75: mov    WORD PTR [rsp+0x6e],r9w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 110ULL);
x86_l_c7b:
	/* 0xc7b: mov    DWORD PTR [rsp+0xb0],r8d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_c83:
	/* 0xc83: mov    DWORD PTR [rsp+0x98],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_c8a:
	/* 0xc8a: mov    DWORD PTR [rsp+0x18],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c8e:
	/* 0xc8e: mov    rcx,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_events_map_burst_limit)));
x86_l_c95:
	/* 0xc95: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c97:
	/* 0xc97: mov    QWORD PTR [rsp+0xe0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_c9f:
	/* 0xc9f: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ca1:
	/* 0xca1: mov    QWORD PTR [rsp+0xe8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_ca9:
	/* 0xca9: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_cae:
	/* 0xcae: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_cb0:
	/* 0xcb0: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_cb2:
	/* 0xcb2: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_cb5:
	/* 0xcb5: mov    eax,DWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_cb9:
	/* 0xcb9: mov    DWORD PTR [rsp+0xa8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_cc0:
	/* 0xcc0: mov    rdi,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit_metrics)));
x86_l_cc7:
	/* 0xcc7: lea    rsi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_ccf:
	/* 0xccf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_cd4:
	/* 0xcd4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cd6:
	/* 0xcd6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_cd9:
	/* 0xcd9: jne    d11 <tail_ipv6_to_endpoint+0xd11> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xcd9, 0xd11, x86_l_d11);
x86_l_cdb:
	/* 0xcdb: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_ce4:
	/* 0xce4: mov    rdi,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit_metrics)));
x86_l_ceb:
	/* 0xceb: lea    rsi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_cf3:
	/* 0xcf3: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_cf8:
	/* 0xcf8: lea    rdx,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_cfd:
	/* 0xcfd: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_cff:
	/* 0xcff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d01:
	/* 0xd01: lea    rcx,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_d06:
	/* 0xd06: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_d08:
	/* 0xd08: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_d0b:
	/* 0xd0b: js     195c <tail_ipv6_to_endpoint+0x195c> */
	X86_SIM_X86_JCC(X86_CC_S, 0xd0b, 0x195c, x86_l_195c);
x86_l_d11:
	/* 0xd11: mov    QWORD PTR [rsp+0xf0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_d19:
	/* 0xd19: mov    rdi,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit)));
x86_l_d20:
	/* 0xd20: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_d25:
	/* 0xd25: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d2a:
	/* 0xd2a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d2c:
	/* 0xd2c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d2f:
	/* 0xd2f: je     de0 <tail_ipv6_to_endpoint+0xde0> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd2f, 0xde0, x86_l_de0);
x86_l_d35:
	/* 0xd35: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d38:
	/* 0xd38: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_d3b:
	/* 0xd3b: sub    rsi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_d3e:
	/* 0xd3e: cmp    rsi,0x3b9aca00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 1000000000ULL);
x86_l_d45:
	/* 0xd45: jbe    e50 <tail_ipv6_to_endpoint+0xe50> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xd45, 0xe50, x86_l_e50);
x86_l_d4b:
	/* 0xd4b: mov    rdx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_d4e:
	/* 0xd4e: shr    rdx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_d52:
	/* 0xd52: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_d5c:
	/* 0xd5c: mulx   rcx,rcx,rcx */
	X86_SIM_L_EXEC_MULX(X86_RCX, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_d61:
	/* 0xd61: shr    rcx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_d65:
	/* 0xd65: imul   rdx,rcx,0x3b9aca00 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RDX, X86_RCX, X86_WIDTH_64, 1000000000ULL);
x86_l_d6c:
	/* 0xd6c: imul   rcx,QWORD PTR [rsp+0xe8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 232ULL);
x86_l_d75:
	/* 0xd75: add    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_d79:
	/* 0xd79: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d7d:
	/* 0xd7d: sub    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_d80:
	/* 0xd80: add    r13,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_d83:
	/* 0xd83: mov    QWORD PTR [rax],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d86:
	/* 0xd86: mov    rdx,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_d8e:
	/* 0xd8e: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_d91:
	/* 0xd91: movabs r13,0x207d30100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 8721203456ULL);
x86_l_d9b:
	/* 0xd9b: mov    edx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d9f:
	/* 0xd9f: mov    esi,DWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_da6:
	/* 0xda6: mov    r8d,DWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_dae:
	/* 0xdae: movzx  r9d,WORD PTR [rsp+0x6e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 110ULL);
x86_l_db4:
	/* 0xdb4: movzx  r10d,BYTE PTR [rsp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_dba:
	/* 0xdba: mov    r11d,DWORD PTR [rsp+0xbc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_dc2:
	/* 0xdc2: mov    edi,DWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_dc9:
	/* 0xdc9: jbe    e8c <tail_ipv6_to_endpoint+0xe8c> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xdc9, 0xe8c, x86_l_e8c);
x86_l_dcf:
	/* 0xdcf: mov    rcx,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_dd7:
	/* 0xdd7: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ddb:
	/* 0xddb: jmp    e8c <tail_ipv6_to_endpoint+0xe8c> */
	X86_SIM_X86_JMP(0xddb, 0xe8c, x86_l_e8c);
x86_l_de0:
	/* 0xde0: mov    QWORD PTR [rsp+0x20],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_de5:
	/* 0xde5: mov    rax,QWORD PTR [rsp+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_ded:
	/* 0xded: dec    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_df0:
	/* 0xdf0: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_df5:
	/* 0xdf5: mov    rdi,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit)));
x86_l_dfc:
	/* 0xdfc: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_e01:
	/* 0xe01: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e06:
	/* 0xe06: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_e0b:
	/* 0xe0b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e0d:
	/* 0xe0d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e0f:
	/* 0xe0f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_e11:
	/* 0xe11: movabs r13,0x207d30100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 8721203456ULL);
x86_l_e1b:
	/* 0xe1b: mov    edx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_e1f:
	/* 0xe1f: mov    esi,DWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_e26:
	/* 0xe26: mov    r8d,DWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_e2e:
	/* 0xe2e: movzx  r9d,WORD PTR [rsp+0x6e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 110ULL);
x86_l_e34:
	/* 0xe34: movzx  r10d,BYTE PTR [rsp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_e3a:
	/* 0xe3a: mov    r11d,DWORD PTR [rsp+0xbc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_e42:
	/* 0xe42: mov    edi,DWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_e49:
	/* 0xe49: jns    e9c <tail_ipv6_to_endpoint+0xe9c> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xe49, 0xe9c, x86_l_e9c);
x86_l_e4b:
	/* 0xe4b: jmp    1951 <tail_ipv6_to_endpoint+0x1951> */
	X86_SIM_X86_JMP(0xe4b, 0x1951, x86_l_1951);
x86_l_e50:
	/* 0xe50: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e54:
	/* 0xe54: movabs r13,0x207d30100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 8721203456ULL);
x86_l_e5e:
	/* 0xe5e: mov    edx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_e62:
	/* 0xe62: mov    esi,DWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_e69:
	/* 0xe69: mov    r8d,DWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_e71:
	/* 0xe71: movzx  r9d,WORD PTR [rsp+0x6e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 110ULL);
x86_l_e77:
	/* 0xe77: movzx  r10d,BYTE PTR [rsp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_e7d:
	/* 0xe7d: mov    r11d,DWORD PTR [rsp+0xbc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_e85:
	/* 0xe85: mov    edi,DWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_e8c:
	/* 0xe8c: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_e8f:
	/* 0xe8f: je     1951 <tail_ipv6_to_endpoint+0x1951> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe8f, 0x1951, x86_l_1951);
x86_l_e95:
	/* 0xe95: dec    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_e98:
	/* 0xe98: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e9c:
	/* 0xe9c: mov    rax,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_endpoint_id)));
x86_l_ea3:
	/* 0xea3: movzx  eax,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_ea6:
	/* 0xea6: mov    ecx,DWORD PTR [rbx+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_ea9:
	/* 0xea9: shl    dl,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_eac:
	/* 0xeac: mov    BYTE PTR [rsp+0x3f],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 270582939648ULL);
x86_l_eb1:
	/* 0xeb1: mov    WORD PTR [rsp+0x3d],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 261993005056ULL);
x86_l_eb8:
	/* 0xeb8: mov    WORD PTR [rsp+0x20],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 137438953477ULL);
x86_l_ebf:
	/* 0xebf: mov    WORD PTR [rsp+0x22],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_ec4:
	/* 0xec4: mov    DWORD PTR [rsp+0x24],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_ec8:
	/* 0xec8: mov    DWORD PTR [rsp+0x28],r11d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_ecd:
	/* 0xecd: mov    WORD PTR [rsp+0x2c],r15w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_ed3:
	/* 0xed3: mov    WORD PTR [rsp+0x2e],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 197568495617ULL);
x86_l_eda:
	/* 0xeda: mov    DWORD PTR [rsp+0x30],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ede:
	/* 0xede: mov    DWORD PTR [rsp+0x34],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_ee2:
	/* 0xee2: or     dl,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_8, X86_ALU_OR, 5ULL);
x86_l_ee5:
	/* 0xee5: movbe  WORD PTR [rsp+0x38],r9w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R9, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_eed:
	/* 0xeed: mov    BYTE PTR [rsp+0x3a],r10b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R10, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_ef2:
	/* 0xef2: mov    BYTE PTR [rsp+0x3b],dl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 59ULL);
x86_l_ef6:
	/* 0xef6: mov    BYTE PTR [rsp+0x3c],r8b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_efb:
	/* 0xefb: mov    DWORD PTR [rsp+0x40],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_eff:
	/* 0xeff: mov    DWORD PTR [rsp+0x44],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 292057776128ULL);
x86_l_f07:
	/* 0xf07: shl    r15,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_f0b:
	/* 0xf0b: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_f10:
	/* 0xf10: or     rdx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_64, X86_ALU_OR);
x86_l_f13:
	/* 0xf13: mov    rsi,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_events)));
x86_l_f1a:
	/* 0xf1a: lea    rcx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f1f:
	/* 0xf1f: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_f24:
	/* 0xf24: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_f27:
	/* 0xf27: mov    r8d,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 40ULL);
x86_l_f2d:
	/* 0xf2d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f2f:
	/* 0xf2f: movzx  edi,BYTE PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_f34:
	/* 0xf34: test   dil,dil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_8);
x86_l_f37:
	/* 0xf37: mov    r15d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f3c:
	/* 0xf3c: jne    1b87 <tail_ipv6_to_endpoint+0x1b87> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf3c, 0x1b87, x86_l_1b87);
x86_l_f42:
	/* 0xf42: cmp    DWORD PTR [rsp+0xa0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_f4a:
	/* 0xf4a: jne    11ac <tail_ipv6_to_endpoint+0x11ac> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf4a, 0x11ac, x86_l_11ac);
x86_l_f50:
	/* 0xf50: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f52:
	/* 0xf52: cmp    WORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f57:
	/* 0xf57: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_f5a:
	/* 0xf5a: shl    eax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 4ULL);
x86_l_f5d:
	/* 0xf5d: cmp    BYTE PTR [r14+0x24],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 154618822662ULL);
x86_l_f62:
	/* 0xf62: mov    DWORD PTR [rsp+0x8],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f67:
	/* 0xf67: jne    f72 <tail_ipv6_to_endpoint+0xf72> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf67, 0xf72, x86_l_f72);
x86_l_f69:
	/* 0xf69: mov    rcx,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&cilium_ct6_global)));
x86_l_f70:
	/* 0xf70: jmp    f79 <tail_ipv6_to_endpoint+0xf79> */
	X86_SIM_X86_JMP(0xf70, 0xf79, x86_l_f79);
x86_l_f72:
	/* 0xf72: mov    rcx,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&cilium_ct_any6_global)));
x86_l_f79:
	/* 0xf79: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f7e:
	/* 0xf7e: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_f87:
	/* 0xf87: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_f90:
	/* 0xf90: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_f99:
	/* 0xf99: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_fa2:
	/* 0xfa2: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_fab:
	/* 0xfab: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_fb4:
	/* 0xfb4: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_fbd:
	/* 0xfbd: movzx  r12d,BYTE PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 36ULL);
x86_l_fc2:
	/* 0xfc2: mov    DWORD PTR [rsp+0x4c],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_fc6:
	/* 0xfc6: movzx  eax,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_fc9:
	/* 0xfc9: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_fcb:
	/* 0xfcb: and    ecx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1ULL);
x86_l_fce:
	/* 0xfce: mov    WORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_fd5:
	/* 0xfd5: shl    eax,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 2ULL);
x86_l_fd8:
	/* 0xfd8: and    eax,0xffffffc0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967232ULL);
x86_l_fdb:
	/* 0xfdb: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_fe4:
	/* 0xfe4: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_fed:
	/* 0xfed: lea    eax,[rax+rcx*8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 3), 0ULL);
x86_l_ff0:
	/* 0xff0: mov    WORD PTR [rsp+0x44],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_ff5:
	/* 0xff5: mov    r15,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_ffc:
	/* 0xffc: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1000:
	/* 0x1000: je     1013 <tail_ipv6_to_endpoint+0x1013> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1000, 0x1013, x86_l_1013);
x86_l_1002:
	/* 0x1002: mov    rcx,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1009:
	/* 0x1009: imul   r13d,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_100d:
	/* 0x100d: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1011:
	/* 0x1011: jmp    1019 <tail_ipv6_to_endpoint+0x1019> */
	X86_SIM_X86_JMP(0x1011, 0x1019, x86_l_1019);
x86_l_1013:
	/* 0x1013: mov    r13d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 60ULL);
x86_l_1019:
	/* 0x1019: cmp    r12b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_8, 6ULL);
x86_l_101d:
	/* 0x101d: jne    1041 <tail_ipv6_to_endpoint+0x1041> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x101d, 0x1041, x86_l_1041);
x86_l_101f:
	/* 0x101f: mov    WORD PTR [rsp+0x44],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_1024:
	/* 0x1024: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1028:
	/* 0x1028: je     103b <tail_ipv6_to_endpoint+0x103b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1028, 0x103b, x86_l_103b);
x86_l_102a:
	/* 0x102a: mov    rax,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1031:
	/* 0x1031: imul   r13d,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_1035:
	/* 0x1035: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1039:
	/* 0x1039: jmp    1041 <tail_ipv6_to_endpoint+0x1041> */
	X86_SIM_X86_JMP(0x1039, 0x1041, x86_l_1041);
x86_l_103b:
	/* 0x103b: mov    r13d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 60ULL);
x86_l_1041:
	/* 0x1041: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1045:
	/* 0x1045: je     1056 <tail_ipv6_to_endpoint+0x1056> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1045, 0x1056, x86_l_1056);
x86_l_1047:
	/* 0x1047: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_104c:
	/* 0x104c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_104e:
	/* 0x104e: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1050:
	/* 0x1050: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_1054:
	/* 0x1054: jmp    1079 <tail_ipv6_to_endpoint+0x1079> */
	X86_SIM_X86_JMP(0x1054, 0x1079, x86_l_1079);
x86_l_1056:
	/* 0x1056: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_105b:
	/* 0x105b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_105d:
	/* 0x105d: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_105f:
	/* 0x105f: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1063:
	/* 0x1063: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_106d:
	/* 0x106d: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1070:
	/* 0x1070: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1075:
	/* 0x1075: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_1079:
	/* 0x1079: cmp    r12b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_8, 6ULL);
x86_l_107d:
	/* 0x107d: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_1080:
	/* 0x1080: add    r13d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1083:
	/* 0x1083: mov    DWORD PTR [rsp+0x40],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1088:
	/* 0x1088: movzx  edx,BYTE PTR [rsp+0x4b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 75ULL);
x86_l_108d:
	/* 0x108d: mov    esi,DWORD PTR [rsp+0x54] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_1091:
	/* 0x1091: add    cl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_8, X86_ALU_ADD);
x86_l_1093:
	/* 0x1093: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1097:
	/* 0x1097: je     10aa <tail_ipv6_to_endpoint+0x10aa> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1097, 0x10aa, x86_l_10aa);
x86_l_1099:
	/* 0x1099: mov    rdi,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_10a0:
	/* 0x10a0: mov    edi,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10a2:
	/* 0x10a2: lea    edi,[rdi+rdi*4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_10a5:
	/* 0x10a5: shr    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_10a8:
	/* 0x10a8: jmp    10af <tail_ipv6_to_endpoint+0x10af> */
	X86_SIM_X86_JMP(0x10a8, 0x10af, x86_l_10af);
x86_l_10aa:
	/* 0x10aa: mov    edi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 5ULL);
x86_l_10af:
	/* 0x10af: movabs r13,0x207d30100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 8721203456ULL);
x86_l_10b9:
	/* 0x10b9: mov    r15d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10be:
	/* 0x10be: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_10c0:
	/* 0x10c0: or     cl,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_10c2:
	/* 0x10c2: cmp    edi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_10c4:
	/* 0x10c4: jb     10ca <tail_ipv6_to_endpoint+0x10ca> */
	X86_SIM_X86_JCC(X86_CC_B, 0x10c4, 0x10ca, x86_l_10ca);
x86_l_10c6:
	/* 0x10c6: cmp    dl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_8);
x86_l_10c8:
	/* 0x10c8: je     10db <tail_ipv6_to_endpoint+0x10db> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10c8, 0x10db, x86_l_10db);
x86_l_10ca:
	/* 0x10ca: mov    BYTE PTR [rsp+0x4b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 75ULL);
x86_l_10ce:
	/* 0x10ce: mov    DWORD PTR [rsp+0x54],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_10d2:
	/* 0x10d2: mov    rax,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_10d9:
	/* 0x10d9: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10db:
	/* 0x10db: mov    QWORD PTR [rsp+0x8e],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 609885356032ULL);
x86_l_10e7:
	/* 0x10e7: mov    QWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_10f3:
	/* 0x10f3: mov    QWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_10ff:
	/* 0x10ff: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_1108:
	/* 0x1108: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_1111:
	/* 0x1111: mov    BYTE PTR [rsp+0x94],0x3a */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 635655159866ULL);
x86_l_1119:
	/* 0x1119: movzx  eax,BYTE PTR [r14+0x25] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 37ULL);
x86_l_111e:
	/* 0x111e: or     al,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_OR, 2ULL);
x86_l_1120:
	/* 0x1120: mov    BYTE PTR [rsp+0x95],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 149ULL);
x86_l_1127:
	/* 0x1127: mov    rax,QWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_112b:
	/* 0x112b: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1130:
	/* 0x1130: mov    rax,QWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1133:
	/* 0x1133: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1138:
	/* 0x1138: mov    rax,QWORD PTR [r14+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_113c:
	/* 0x113c: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1144:
	/* 0x1144: mov    rax,QWORD PTR [r14+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1148:
	/* 0x1148: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1150:
	/* 0x1150: mov    rdi,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct_any6_global)));
x86_l_1157:
	/* 0x1157: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_115c:
	/* 0x115c: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1161:
	/* 0x1161: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1166:
	/* 0x1166: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1168:
	/* 0x1168: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_116a:
	/* 0x116a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_116c:
	/* 0x116c: js     1841 <tail_ipv6_to_endpoint+0x1841> */
	X86_SIM_X86_JCC(X86_CC_S, 0x116c, 0x1841, x86_l_1841);
x86_l_1172:
	/* 0x1172: mov    rax,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_1179:
	/* 0x1179: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_117c:
	/* 0x117c: je     118e <tail_ipv6_to_endpoint+0x118e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x117c, 0x118e, x86_l_118e);
x86_l_117e:
	/* 0x117e: mov    QWORD PTR [rsp+0x30],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430209ULL);
x86_l_1187:
	/* 0x1187: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1189:
	/* 0x1189: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_118e:
	/* 0x118e: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1193:
	/* 0x1193: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1198:
	/* 0x1198: mov    rdi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_119d:
	/* 0x119d: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_11a0:
	/* 0x11a0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11a2:
	/* 0x11a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11a4:
	/* 0x11a4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_11a6:
	/* 0x11a6: js     1841 <tail_ipv6_to_endpoint+0x1841> */
	X86_SIM_X86_JCC(X86_CC_S, 0x11a6, 0x1841, x86_l_1841);
x86_l_11ac:
	/* 0x11ac: mov    r14d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11b0:
	/* 0x11b0: test   r14w,r14w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_16);
x86_l_11b4:
	/* 0x11b4: je     1369 <tail_ipv6_to_endpoint+0x1369> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11b4, 0x1369, x86_l_1369);
x86_l_11ba:
	/* 0x11ba: mov    rax,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_security_label)));
x86_l_11c1:
	/* 0x11c1: mov    r13d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11c4:
	/* 0x11c4: mov    rax,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_tracing_ip_option_type)));
x86_l_11cb:
	/* 0x11cb: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11ce:
	/* 0x11ce: je     120e <tail_ipv6_to_endpoint+0x120e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11ce, 0x120e, x86_l_120e);
x86_l_11d0:
	/* 0x11d0: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_11d8:
	/* 0x11d8: mov    rdi,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_percpu_trace_id)));
x86_l_11df:
	/* 0x11df: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_11e4:
	/* 0x11e4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_11e9:
	/* 0x11e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11eb:
	/* 0x11eb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_11ee:
	/* 0x11ee: je     120e <tail_ipv6_to_endpoint+0x120e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11ee, 0x120e, x86_l_120e);
x86_l_11f0:
	/* 0x11f0: mov    r8,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11f3:
	/* 0x11f3: mov    r12d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11f6:
	/* 0x11f6: mov    QWORD PTR [rsp+0x58],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122050ULL);
x86_l_11ff:
	/* 0x11ff: cmp    DWORD PTR [rsp+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_1207:
	/* 0x1207: jne    122b <tail_ipv6_to_endpoint+0x122b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1207, 0x122b, x86_l_122b);
x86_l_1209:
	/* 0x1209: jmp    16c8 <tail_ipv6_to_endpoint+0x16c8> */
	X86_SIM_X86_JMP(0x1209, 0x16c8, x86_l_16c8);
x86_l_120e:
	/* 0x120e: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1211:
	/* 0x1211: mov    r12d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1214:
	/* 0x1214: mov    QWORD PTR [rsp+0x58],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122050ULL);
x86_l_121d:
	/* 0x121d: cmp    DWORD PTR [rsp+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_1225:
	/* 0x1225: je     16c8 <tail_ipv6_to_endpoint+0x16c8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1225, 0x16c8, x86_l_16c8);
x86_l_122b:
	/* 0x122b: mov    rax,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_events_map_rate_limit)));
x86_l_1232:
	/* 0x1232: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1235:
	/* 0x1235: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_1238:
	/* 0x1238: je     1607 <tail_ipv6_to_endpoint+0x1607> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1238, 0x1607, x86_l_1607);
x86_l_123e:
	/* 0x123e: mov    QWORD PTR [rsp+0x18],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1243:
	/* 0x1243: mov    DWORD PTR [rsp+0x10],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1248:
	/* 0x1248: mov    DWORD PTR [rsp],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_124c:
	/* 0x124c: mov    DWORD PTR [rsp+0x8],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1251:
	/* 0x1251: mov    rcx,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_events_map_burst_limit)));
x86_l_1258:
	/* 0x1258: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_125a:
	/* 0x125a: mov    QWORD PTR [rsp+0xb0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1262:
	/* 0x1262: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1264:
	/* 0x1264: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_126c:
	/* 0x126c: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1271:
	/* 0x1271: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1273:
	/* 0x1273: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1275:
	/* 0x1275: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1278:
	/* 0x1278: mov    DWORD PTR [rsp+0xa8],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 721554505730ULL);
x86_l_1283:
	/* 0x1283: mov    rdi,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit_metrics)));
x86_l_128a:
	/* 0x128a: lea    rsi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1292:
	/* 0x1292: mov    r13d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 1ULL);
x86_l_1298:
	/* 0x1298: call   r13 */
	X86_SIM_BPF_CALL_REG(X86_R13);
x86_l_129b:
	/* 0x129b: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_129e:
	/* 0x129e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_12a1:
	/* 0x12a1: jne    12d4 <tail_ipv6_to_endpoint+0x12d4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x12a1, 0x12d4, x86_l_12d4);
x86_l_12a3:
	/* 0x12a3: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_12ac:
	/* 0x12ac: mov    rdi,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit_metrics)));
x86_l_12b3:
	/* 0x12b3: lea    rsi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_12bb:
	/* 0x12bb: lea    r14,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_12c0:
	/* 0x12c0: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_12c5:
	/* 0x12c5: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_12c8:
	/* 0x12c8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12ca:
	/* 0x12ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12cc:
	/* 0x12cc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_12ce:
	/* 0x12ce: js     17f3 <tail_ipv6_to_endpoint+0x17f3> */
	X86_SIM_X86_JCC(X86_CC_S, 0x12ce, 0x17f3, x86_l_17f3);
x86_l_12d4:
	/* 0x12d4: mov    rdi,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit)));
x86_l_12db:
	/* 0x12db: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_12e0:
	/* 0x12e0: call   r13 */
	X86_SIM_BPF_CALL_REG(X86_R13);
x86_l_12e3:
	/* 0x12e3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_12e6:
	/* 0x12e6: je     159c <tail_ipv6_to_endpoint+0x159c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12e6, 0x159c, x86_l_159c);
x86_l_12ec:
	/* 0x12ec: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12ef:
	/* 0x12ef: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_12f2:
	/* 0x12f2: sub    rsi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_12f5:
	/* 0x12f5: cmp    rsi,0x3b9aca00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 1000000000ULL);
x86_l_12fc:
	/* 0x12fc: mov    r13d,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1301:
	/* 0x1301: jbe    15e3 <tail_ipv6_to_endpoint+0x15e3> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x1301, 0x15e3, x86_l_15e3);
x86_l_1307:
	/* 0x1307: mov    rdx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_130a:
	/* 0x130a: shr    rdx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_130e:
	/* 0x130e: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_1318:
	/* 0x1318: mulx   rcx,rcx,rcx */
	X86_SIM_L_EXEC_MULX(X86_RCX, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_131d:
	/* 0x131d: shr    rcx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_1321:
	/* 0x1321: imul   rdx,rcx,0x3b9aca00 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RDX, X86_RCX, X86_WIDTH_64, 1000000000ULL);
x86_l_1328:
	/* 0x1328: imul   rcx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 152ULL);
x86_l_1331:
	/* 0x1331: add    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1335:
	/* 0x1335: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1339:
	/* 0x1339: sub    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_133c:
	/* 0x133c: add    r15,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_133f:
	/* 0x133f: mov    QWORD PTR [rax],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1342:
	/* 0x1342: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_134a:
	/* 0x134a: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_134d:
	/* 0x134d: mov    r15d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1352:
	/* 0x1352: mov    r8,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1357:
	/* 0x1357: jbe    15f1 <tail_ipv6_to_endpoint+0x15f1> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x1357, 0x15f1, x86_l_15f1);
x86_l_135d:
	/* 0x135d: mov    QWORD PTR [rax+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1361:
	/* 0x1361: mov    rcx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1364:
	/* 0x1364: jmp    15f1 <tail_ipv6_to_endpoint+0x15f1> */
	X86_SIM_X86_JMP(0x1364, 0x15f1, x86_l_15f1);
x86_l_1369:
	/* 0x1369: mov    rax,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_security_label)));
x86_l_1370:
	/* 0x1370: mov    r12d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1373:
	/* 0x1373: mov    rax,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_endpoint_id)));
x86_l_137a:
	/* 0x137a: movzx  eax,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_137d:
	/* 0x137d: mov    WORD PTR [rsp],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1381:
	/* 0x1381: mov    rax,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_tracing_ip_option_type)));
x86_l_1388:
	/* 0x1388: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_138b:
	/* 0x138b: mov    DWORD PTR [rsp+0x8],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1390:
	/* 0x1390: je     13b7 <tail_ipv6_to_endpoint+0x13b7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1390, 0x13b7, x86_l_13b7);
x86_l_1392:
	/* 0x1392: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_139a:
	/* 0x139a: mov    rdi,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_percpu_trace_id)));
x86_l_13a1:
	/* 0x13a1: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_13a6:
	/* 0x13a6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13ab:
	/* 0x13ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13ad:
	/* 0x13ad: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13b0:
	/* 0x13b0: je     13b7 <tail_ipv6_to_endpoint+0x13b7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13b0, 0x13b7, x86_l_13b7);
x86_l_13b2:
	/* 0x13b2: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13b5:
	/* 0x13b5: jmp    13b9 <tail_ipv6_to_endpoint+0x13b9> */
	X86_SIM_X86_JMP(0x13b5, 0x13b9, x86_l_13b9);
x86_l_13b7:
	/* 0x13b7: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13b9:
	/* 0x13b9: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13be:
	/* 0x13be: mov    r14d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13c1:
	/* 0x13c1: mov    QWORD PTR [rsp+0xa8],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505730ULL);
x86_l_13cd:
	/* 0x13cd: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_13d6:
	/* 0x13d6: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_13df:
	/* 0x13df: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_13e8:
	/* 0x13e8: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_13f1:
	/* 0x13f1: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_13fa:
	/* 0x13fa: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1403:
	/* 0x1403: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_140c:
	/* 0x140c: mov    QWORD PTR [rsp+0x58],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1411:
	/* 0x1411: mov    rdi,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1418:
	/* 0x1418: lea    r15,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_141d:
	/* 0x141d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1422:
	/* 0x1422: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_1425:
	/* 0x1425: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1427:
	/* 0x1427: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_142a:
	/* 0x142a: je     1442 <tail_ipv6_to_endpoint+0x1442> */
	X86_SIM_X86_JCC(X86_CC_E, 0x142a, 0x1442, x86_l_1442);
x86_l_142c:
	/* 0x142c: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_142f:
	/* 0x142f: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1433:
	/* 0x1433: cmp    DWORD PTR [rsp+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_143b:
	/* 0x143b: jne    1478 <tail_ipv6_to_endpoint+0x1478> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x143b, 0x1478, x86_l_1478);
x86_l_143d:
	/* 0x143d: jmp    1936 <tail_ipv6_to_endpoint+0x1936> */
	X86_SIM_X86_JMP(0x143d, 0x1936, x86_l_1936);
x86_l_1442:
	/* 0x1442: mov    QWORD PTR [rsp+0x70],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337153ULL);
x86_l_144b:
	/* 0x144b: mov    QWORD PTR [rsp+0x78],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1450:
	/* 0x1450: mov    rdi,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1457:
	/* 0x1457: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_145c:
	/* 0x145c: lea    rdx,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1461:
	/* 0x1461: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1466:
	/* 0x1466: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1468:
	/* 0x1468: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_146a:
	/* 0x146a: cmp    DWORD PTR [rsp+0xa4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 704374636544ULL);
x86_l_1472:
	/* 0x1472: je     1936 <tail_ipv6_to_endpoint+0x1936> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1472, 0x1936, x86_l_1936);
x86_l_1478:
	/* 0x1478: mov    rax,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_events_map_rate_limit)));
x86_l_147f:
	/* 0x147f: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1482:
	/* 0x1482: je     1871 <tail_ipv6_to_endpoint+0x1871> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1482, 0x1871, x86_l_1871);
x86_l_1488:
	/* 0x1488: mov    DWORD PTR [rsp+0x18],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_148d:
	/* 0x148d: mov    rcx,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_events_map_burst_limit)));
x86_l_1494:
	/* 0x1494: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1496:
	/* 0x1496: mov    QWORD PTR [rsp+0xb0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_149e:
	/* 0x149e: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14a0:
	/* 0x14a0: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_14a8:
	/* 0x14a8: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_14ad:
	/* 0x14ad: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14af:
	/* 0x14af: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_14b1:
	/* 0x14b1: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_14b4:
	/* 0x14b4: mov    DWORD PTR [rsp+0xc4],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 841813590018ULL);
x86_l_14bf:
	/* 0x14bf: mov    rdi,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit_metrics)));
x86_l_14c6:
	/* 0x14c6: lea    rsi,[rsp+0xc4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_14ce:
	/* 0x14ce: mov    r13d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 1ULL);
x86_l_14d4:
	/* 0x14d4: call   r13 */
	X86_SIM_BPF_CALL_REG(X86_R13);
x86_l_14d7:
	/* 0x14d7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14da:
	/* 0x14da: jne    150b <tail_ipv6_to_endpoint+0x150b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x14da, 0x150b, x86_l_150b);
x86_l_14dc:
	/* 0x14dc: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_14e5:
	/* 0x14e5: mov    rdi,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit_metrics)));
x86_l_14ec:
	/* 0x14ec: lea    rsi,[rsp+0xc4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_14f4:
	/* 0x14f4: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_14f9:
	/* 0x14f9: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_14fc:
	/* 0x14fc: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14fe:
	/* 0x14fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1500:
	/* 0x1500: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1502:
	/* 0x1502: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_1505:
	/* 0x1505: js     1936 <tail_ipv6_to_endpoint+0x1936> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1505, 0x1936, x86_l_1936);
x86_l_150b:
	/* 0x150b: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_150e:
	/* 0x150e: mov    rdi,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit)));
x86_l_1515:
	/* 0x1515: lea    rsi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_151d:
	/* 0x151d: call   r13 */
	X86_SIM_BPF_CALL_REG(X86_R13);
x86_l_1520:
	/* 0x1520: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1523:
	/* 0x1523: je     1801 <tail_ipv6_to_endpoint+0x1801> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1523, 0x1801, x86_l_1801);
x86_l_1529:
	/* 0x1529: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_152c:
	/* 0x152c: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_152f:
	/* 0x152f: sub    rsi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1532:
	/* 0x1532: cmp    rsi,0x3b9aca00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 1000000000ULL);
x86_l_1539:
	/* 0x1539: jbe    1858 <tail_ipv6_to_endpoint+0x1858> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x1539, 0x1858, x86_l_1858);
x86_l_153f:
	/* 0x153f: mov    rdx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_1542:
	/* 0x1542: shr    rdx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1546:
	/* 0x1546: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_1550:
	/* 0x1550: mulx   rcx,rcx,rcx */
	X86_SIM_L_EXEC_MULX(X86_RCX, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_1555:
	/* 0x1555: shr    rcx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_1559:
	/* 0x1559: imul   rdx,rcx,0x3b9aca00 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RDX, X86_RCX, X86_WIDTH_64, 1000000000ULL);
x86_l_1560:
	/* 0x1560: imul   rcx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 152ULL);
x86_l_1569:
	/* 0x1569: add    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_156d:
	/* 0x156d: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1571:
	/* 0x1571: sub    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1574:
	/* 0x1574: add    r12,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1577:
	/* 0x1577: mov    QWORD PTR [rax],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_157a:
	/* 0x157a: mov    rdx,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1582:
	/* 0x1582: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1585:
	/* 0x1585: mov    r12d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_158a:
	/* 0x158a: jbe    1861 <tail_ipv6_to_endpoint+0x1861> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x158a, 0x1861, x86_l_1861);
x86_l_1590:
	/* 0x1590: mov    QWORD PTR [rax+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1594:
	/* 0x1594: mov    rcx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1597:
	/* 0x1597: jmp    1861 <tail_ipv6_to_endpoint+0x1861> */
	X86_SIM_X86_JMP(0x1597, 0x1861, x86_l_1861);
x86_l_159c:
	/* 0x159c: mov    QWORD PTR [rsp+0x20],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_15a1:
	/* 0x15a1: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_15a9:
	/* 0x15a9: dec    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_15ac:
	/* 0x15ac: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_15b1:
	/* 0x15b1: mov    rdi,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit)));
x86_l_15b8:
	/* 0x15b8: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_15bd:
	/* 0x15bd: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_15c2:
	/* 0x15c2: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_15c7:
	/* 0x15c7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15c9:
	/* 0x15c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15cb:
	/* 0x15cb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_15cd:
	/* 0x15cd: mov    r15d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15d2:
	/* 0x15d2: mov    r13d,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15d7:
	/* 0x15d7: mov    r8,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_15dc:
	/* 0x15dc: jns    1601 <tail_ipv6_to_endpoint+0x1601> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x15dc, 0x1601, x86_l_1601);
x86_l_15de:
	/* 0x15de: jmp    17f0 <tail_ipv6_to_endpoint+0x17f0> */
	X86_SIM_X86_JMP(0x15de, 0x17f0, x86_l_17f0);
x86_l_15e3:
	/* 0x15e3: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15e7:
	/* 0x15e7: mov    r15d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15ec:
	/* 0x15ec: mov    r8,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_15f1:
	/* 0x15f1: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_15f4:
	/* 0x15f4: je     17f0 <tail_ipv6_to_endpoint+0x17f0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x15f4, 0x17f0, x86_l_17f0);
x86_l_15fa:
	/* 0x15fa: dec    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_15fd:
	/* 0x15fd: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1601:
	/* 0x1601: mov    ecx,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1603:
	/* 0x1603: mov    r14d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1607:
	/* 0x1607: mov    edx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_32);
x86_l_160a:
	/* 0x160a: rol    dx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_160e:
	/* 0x160e: mov    rsi,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_1615:
	/* 0x1615: mov    eax,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1617:
	/* 0x1617: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1619:
	/* 0x1619: mov    edi,DWORD PTR [rsp+0xa4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_1620:
	/* 0x1620: cmp    esi,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDI, X86_WIDTH_32);
x86_l_1622:
	/* 0x1622: cmovne eax,edi */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RDI, X86_WIDTH_32, X86_CC_NE);
x86_l_1625:
	/* 0x1625: cmp    eax,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_1627:
	/* 0x1627: mov    rsi,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_endpoint_id)));
x86_l_162e:
	/* 0x162e: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1631:
	/* 0x1631: cmovae eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_AE);
x86_l_1634:
	/* 0x1634: mov    ecx,DWORD PTR [rbx+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_1637:
	/* 0x1637: mov    WORD PTR [rsp+0x20],0x104 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 137438953732ULL);
x86_l_163e:
	/* 0x163e: mov    WORD PTR [rsp+0x22],si */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_1643:
	/* 0x1643: mov    DWORD PTR [rsp+0x24],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1647:
	/* 0x1647: mov    DWORD PTR [rsp+0x28],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_164c:
	/* 0x164c: mov    WORD PTR [rsp+0x2c],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1651:
	/* 0x1651: mov    WORD PTR [rsp+0x2e],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 197568495618ULL);
x86_l_1658:
	/* 0x1658: mov    DWORD PTR [rsp+0x30],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_165c:
	/* 0x165c: mov    DWORD PTR [rsp+0x34],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1661:
	/* 0x1661: mov    WORD PTR [rsp+0x38],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1666:
	/* 0x1666: mov    ecx,DWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_166d:
	/* 0x166d: mov    BYTE PTR [rsp+0x3a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_1671:
	/* 0x1671: mov    BYTE PTR [rsp+0x3b],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 253403070465ULL);
x86_l_1676:
	/* 0x1676: mov    ecx,DWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_167d:
	/* 0x167d: mov    DWORD PTR [rsp+0x3c],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_1681:
	/* 0x1681: mov    QWORD PTR [rsp+0x50],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1686:
	/* 0x1686: mov    rcx,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_168e:
	/* 0x168e: mov    QWORD PTR [rsp+0x48],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1693:
	/* 0x1693: mov    rcx,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_169b:
	/* 0x169b: mov    QWORD PTR [rsp+0x40],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_16a0:
	/* 0x16a0: shl    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_16a4:
	/* 0x16a4: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_16a9:
	/* 0x16a9: or     rdx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_16ac:
	/* 0x16ac: mov    rsi,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_events)));
x86_l_16b3:
	/* 0x16b3: lea    rcx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_16b8:
	/* 0x16b8: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_16bd:
	/* 0x16bd: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_16c0:
	/* 0x16c0: mov    r8d,0x38 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 56ULL);
x86_l_16c6:
	/* 0x16c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16c8:
	/* 0x16c8: mov    rax,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_cilium_host_mac)));
x86_l_16cf:
	/* 0x16cf: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16d2:
	/* 0x16d2: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_16d7:
	/* 0x16d7: mov    rax,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_interface_mac)));
x86_l_16de:
	/* 0x16de: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16e1:
	/* 0x16e1: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_16e6:
	/* 0x16e6: shl    r14d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_16ea:
	/* 0x16ea: or     r14d,0x200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_OR, 512ULL);
x86_l_16f1:
	/* 0x16f1: mov    DWORD PTR [rbx+0x30],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_16f5:
	/* 0x16f5: lea    rdx,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_16fa:
	/* 0x16fa: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_16ff:
	/* 0x16ff: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1702:
	/* 0x1702: mov    esi,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 21ULL);
x86_l_1707:
	/* 0x1707: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_170c:
	/* 0x170c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_170e:
	/* 0x170e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1710:
	/* 0x1710: js     174a <tail_ipv6_to_endpoint+0x174a> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1710, 0x174a, x86_l_174a);
x86_l_1712:
	/* 0x1712: movzx  eax,BYTE PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 88ULL);
x86_l_1717:
	/* 0x1717: cmp    al,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 2ULL);
x86_l_1719:
	/* 0x1719: jae    1755 <tail_ipv6_to_endpoint+0x1755> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x1719, 0x1755, x86_l_1755);
x86_l_171b:
	/* 0x171b: movabs rax,0x20000000e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934606ULL);
x86_l_1725:
	/* 0x1725: mov    QWORD PTR [rbx+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1729:
	/* 0x1729: mov    rsi,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_1730:
	/* 0x1730: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1735:
	/* 0x1735: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1738:
	/* 0x1738: mov    edx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_173d:
	/* 0x173d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_173f:
	/* 0x173f: mov    r12d,0xffffff74 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967156ULL);
x86_l_1745:
	/* 0x1745: jmp    17dc <tail_ipv6_to_endpoint+0x17dc> */
	X86_SIM_X86_JMP(0x1745, 0x17dc, x86_l_17dc);
x86_l_174a:
	/* 0x174a: mov    r12d,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967162ULL);
x86_l_1750:
	/* 0x1750: jmp    17dc <tail_ipv6_to_endpoint+0x17dc> */
	X86_SIM_X86_JMP(0x1750, 0x17dc, x86_l_17dc);
x86_l_1755:
	/* 0x1755: dec    al */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_DEC, 1);
x86_l_1757:
	/* 0x1757: mov    BYTE PTR [rsp+0x58],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_175b:
	/* 0x175b: lea    rdx,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1760:
	/* 0x1760: mov    r14d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 9ULL);
x86_l_1766:
	/* 0x1766: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1769:
	/* 0x1769: mov    esi,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 21ULL);
x86_l_176e:
	/* 0x176e: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1773:
	/* 0x1773: mov    r8d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 1ULL);
x86_l_1779:
	/* 0x1779: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_177c:
	/* 0x177c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_177e:
	/* 0x177e: js     17d6 <tail_ipv6_to_endpoint+0x17d6> */
	X86_SIM_X86_JCC(X86_CC_S, 0x177e, 0x17d6, x86_l_17d6);
x86_l_1780:
	/* 0x1780: lea    rdx,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1785:
	/* 0x1785: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1788:
	/* 0x1788: mov    esi,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 6ULL);
x86_l_178d:
	/* 0x178d: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1792:
	/* 0x1792: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1795:
	/* 0x1795: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_1798:
	/* 0x1798: mov    r12d,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967155ULL);
x86_l_179e:
	/* 0x179e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_17a0:
	/* 0x17a0: js     17dc <tail_ipv6_to_endpoint+0x17dc> */
	X86_SIM_X86_JCC(X86_CC_S, 0x17a0, 0x17dc, x86_l_17dc);
x86_l_17a2:
	/* 0x17a2: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_17a7:
	/* 0x17a7: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_17ac:
	/* 0x17ac: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_17af:
	/* 0x17af: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17b1:
	/* 0x17b1: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_17b6:
	/* 0x17b6: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17b9:
	/* 0x17b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17bb:
	/* 0x17bb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_17bd:
	/* 0x17bd: js     17dc <tail_ipv6_to_endpoint+0x17dc> */
	X86_SIM_X86_JCC(X86_CC_S, 0x17bd, 0x17dc, x86_l_17dc);
x86_l_17bf:
	/* 0x17bf: mov    rax,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_cilium_net_ifindex)));
x86_l_17c6:
	/* 0x17c6: mov    edi,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17c8:
	/* 0x17c8: mov    eax,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 23ULL);
x86_l_17cd:
	/* 0x17cd: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17cf:
	/* 0x17cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17d1:
	/* 0x17d1: mov    r12d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_32);
x86_l_17d4:
	/* 0x17d4: jmp    17dc <tail_ipv6_to_endpoint+0x17dc> */
	X86_SIM_X86_JMP(0x17d4, 0x17dc, x86_l_17dc);
x86_l_17d6:
	/* 0x17d6: mov    r12d,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967155ULL);
x86_l_17dc:
	/* 0x17dc: mov    eax,DWORD PTR [rbx+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_17df:
	/* 0x17df: mov    DWORD PTR [rbx+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17e2:
	/* 0x17e2: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_17e5:
	/* 0x17e5: jns    1b90 <tail_ipv6_to_endpoint+0x1b90> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x17e5, 0x1b90, x86_l_1b90);
x86_l_17eb:
	/* 0x17eb: jmp    34 <tail_ipv6_to_endpoint+0x34> */
	X86_SIM_X86_JMP(0x17eb, 0x34, x86_l_34);
x86_l_17f0:
	/* 0x17f0: inc    QWORD PTR [r14] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_17f3:
	/* 0x17f3: mov    r15d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17f8:
	/* 0x17f8: mov    r14d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17fc:
	/* 0x17fc: jmp    16c8 <tail_ipv6_to_endpoint+0x16c8> */
	X86_SIM_X86_JMP(0x17fc, 0x16c8, x86_l_16c8);
x86_l_1801:
	/* 0x1801: mov    QWORD PTR [rsp+0x70],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1806:
	/* 0x1806: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_180e:
	/* 0x180e: dec    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_1811:
	/* 0x1811: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1816:
	/* 0x1816: mov    rdi,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit)));
x86_l_181d:
	/* 0x181d: lea    rsi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1825:
	/* 0x1825: lea    rdx,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_182a:
	/* 0x182a: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_182f:
	/* 0x182f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1831:
	/* 0x1831: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1833:
	/* 0x1833: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1835:
	/* 0x1835: mov    r12d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_183a:
	/* 0x183a: jns    1871 <tail_ipv6_to_endpoint+0x1871> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x183a, 0x1871, x86_l_1871);
x86_l_183c:
	/* 0x183c: jmp    194c <tail_ipv6_to_endpoint+0x194c> */
	X86_SIM_X86_JMP(0x183c, 0x194c, x86_l_194c);
x86_l_1841:
	/* 0x1841: mov    r15d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_32);
x86_l_1844:
	/* 0x1844: mov    r12d,0xffffff65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967141ULL);
x86_l_184a:
	/* 0x184a: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_184d:
	/* 0x184d: jns    1b90 <tail_ipv6_to_endpoint+0x1b90> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x184d, 0x1b90, x86_l_1b90);
x86_l_1853:
	/* 0x1853: jmp    34 <tail_ipv6_to_endpoint+0x34> */
	X86_SIM_X86_JMP(0x1853, 0x34, x86_l_34);
x86_l_1858:
	/* 0x1858: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_185c:
	/* 0x185c: mov    r12d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1861:
	/* 0x1861: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_1864:
	/* 0x1864: je     194c <tail_ipv6_to_endpoint+0x194c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1864, 0x194c, x86_l_194c);
x86_l_186a:
	/* 0x186a: dec    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_186d:
	/* 0x186d: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1871:
	/* 0x1871: mov    rcx,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_1878:
	/* 0x1878: mov    eax,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_187a:
	/* 0x187a: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_187c:
	/* 0x187c: mov    edx,DWORD PTR [rsp+0xa4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 164ULL);
x86_l_1883:
	/* 0x1883: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_1885:
	/* 0x1885: cmovne eax,edx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RDX, X86_WIDTH_32, X86_CC_NE);
x86_l_1888:
	/* 0x1888: mov    ecx,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_188a:
	/* 0x188a: cmp    eax,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_188c:
	/* 0x188c: mov    rdx,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_endpoint_id)));
x86_l_1893:
	/* 0x1893: movzx  edx,WORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1896:
	/* 0x1896: cmovae eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_AE);
x86_l_1899:
	/* 0x1899: mov    ecx,DWORD PTR [rbx+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_189c:
	/* 0x189c: mov    WORD PTR [rsp+0x20],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 137438953476ULL);
x86_l_18a3:
	/* 0x18a3: mov    WORD PTR [rsp+0x22],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_18a8:
	/* 0x18a8: mov    DWORD PTR [rsp+0x24],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_18ac:
	/* 0x18ac: mov    DWORD PTR [rsp+0x28],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_18b1:
	/* 0x18b1: mov    WORD PTR [rsp+0x2c],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_18b6:
	/* 0x18b6: mov    WORD PTR [rsp+0x2e],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 197568495618ULL);
x86_l_18bd:
	/* 0x18bd: mov    DWORD PTR [rsp+0x30],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_18c1:
	/* 0x18c1: mov    DWORD PTR [rsp+0x34],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_18c6:
	/* 0x18c6: movzx  ecx,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_18ca:
	/* 0x18ca: mov    WORD PTR [rsp+0x38],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_18cf:
	/* 0x18cf: mov    ecx,DWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_18d6:
	/* 0x18d6: mov    BYTE PTR [rsp+0x3a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_18da:
	/* 0x18da: mov    BYTE PTR [rsp+0x3b],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 253403070465ULL);
x86_l_18df:
	/* 0x18df: mov    ecx,DWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_18e6:
	/* 0x18e6: mov    DWORD PTR [rsp+0x3c],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_18ea:
	/* 0x18ea: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_18ef:
	/* 0x18ef: mov    QWORD PTR [rsp+0x50],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_18f4:
	/* 0x18f4: mov    rcx,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_18fc:
	/* 0x18fc: mov    QWORD PTR [rsp+0x48],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1901:
	/* 0x1901: mov    rcx,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1909:
	/* 0x1909: mov    QWORD PTR [rsp+0x40],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_190e:
	/* 0x190e: shl    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_1912:
	/* 0x1912: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_1917:
	/* 0x1917: or     rdx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_191a:
	/* 0x191a: mov    rsi,QWORD PTR [rip+0x1e443] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_events)));
x86_l_1921:
	/* 0x1921: lea    rcx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1926:
	/* 0x1926: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_192b:
	/* 0x192b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_192e:
	/* 0x192e: mov    r8d,0x38 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 56ULL);
x86_l_1934:
	/* 0x1934: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1936:
	/* 0x1936: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1939:
	/* 0x1939: mov    r15d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_193e:
	/* 0x193e: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_1941:
	/* 0x1941: jns    1b90 <tail_ipv6_to_endpoint+0x1b90> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1941, 0x1b90, x86_l_1b90);
x86_l_1947:
	/* 0x1947: jmp    34 <tail_ipv6_to_endpoint+0x34> */
	X86_SIM_X86_JMP(0x1947, 0x34, x86_l_34);
x86_l_194c:
	/* 0x194c: inc    QWORD PTR [r15] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_194f:
	/* 0x194f: jmp    1936 <tail_ipv6_to_endpoint+0x1936> */
	X86_SIM_X86_JMP(0x194f, 0x1936, x86_l_1936);
x86_l_1951:
	/* 0x1951: mov    rax,QWORD PTR [rsp+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_1959:
	/* 0x1959: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_195c:
	/* 0x195c: movabs r13,0x207d30100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 8721203456ULL);
x86_l_1966:
	/* 0x1966: jmp    f2f <tail_ipv6_to_endpoint+0xf2f> */
	X86_SIM_X86_JMP(0x1966, 0xf2f, x86_l_f2f);
x86_l_196b:
	/* 0x196b: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_196e:
	/* 0x196e: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_1971:
	/* 0x1971: jmp    487 <tail_ipv6_to_endpoint+0x487> */
	X86_SIM_X86_JMP(0x1971, 0x487, x86_l_487);
x86_l_1976:
	/* 0x1976: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_197c:
	/* 0x197c: jmp    1984 <tail_ipv6_to_endpoint+0x1984> */
	X86_SIM_X86_JMP(0x197c, 0x1984, x86_l_1984);
x86_l_197e:
	/* 0x197e: mov    r12d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 16ULL);
x86_l_1984:
	/* 0x1984: lea    rdi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1989:
	/* 0x1989: lea    rdx,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_198e:
	/* 0x198e: mov    eax,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_1993:
	/* 0x1993: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1998:
	/* 0x1998: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_199d:
	/* 0x199d: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19a0:
	/* 0x19a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19a2:
	/* 0x19a2: add    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_19a7:
	/* 0x19a7: mov    r8d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19ab:
	/* 0x19ab: or     r8d,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 144ULL);
x86_l_19b2:
	/* 0x19b2: mov    r9d,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 11ULL);
x86_l_19b8:
	/* 0x19b8: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_19bb:
	/* 0x19bb: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_19be:
	/* 0x19be: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19c0:
	/* 0x19c0: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19c4:
	/* 0x19c4: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_19c6:
	/* 0x19c6: call   r9 */
	X86_SIM_BPF_CALL_REG(X86_R9);
x86_l_19c9:
	/* 0x19c9: cmp    eax,0xffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967274ULL);
x86_l_19cc:
	/* 0x19cc: jne    19e5 <tail_ipv6_to_endpoint+0x19e5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x19cc, 0x19e5, x86_l_19e5);
x86_l_19ce:
	/* 0x19ce: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_19d1:
	/* 0x19d1: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_19d4:
	/* 0x19d4: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19d6:
	/* 0x19d6: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19da:
	/* 0x19da: mov    r8d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19de:
	/* 0x19de: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_19e3:
	/* 0x19e3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19e5:
	/* 0x19e5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_19e7:
	/* 0x19e7: js     1b7e <tail_ipv6_to_endpoint+0x1b7e> */
	X86_SIM_X86_JCC(X86_CC_S, 0x19e7, 0x1b7e, x86_l_1b7e);
x86_l_19ed:
	/* 0x19ed: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_19f2:
	/* 0x19f2: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_19f5:
	/* 0x19f5: mov    esi,0x16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 22ULL);
x86_l_19fa:
	/* 0x19fa: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_19fd:
	/* 0x19fd: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1a02:
	/* 0x1a02: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a05:
	/* 0x1a05: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a07:
	/* 0x1a07: mov    r12d,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967155ULL);
x86_l_1a0d:
	/* 0x1a0d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1a0f:
	/* 0x1a0f: js     1b84 <tail_ipv6_to_endpoint+0x1b84> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1a0f, 0x1b84, x86_l_1b84);
x86_l_1a15:
	/* 0x1a15: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1a18:
	/* 0x1a18: je     1b84 <tail_ipv6_to_endpoint+0x1b84> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a18, 0x1b84, x86_l_1b84);
x86_l_1a1e:
	/* 0x1a1e: test   r13b,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_8);
x86_l_1a21:
	/* 0x1a21: je     37e <tail_ipv6_to_endpoint+0x37e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a21, 0x37e, x86_l_37e);
x86_l_1a27:
	/* 0x1a27: movzx  eax,BYTE PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 36ULL);
x86_l_1a2c:
	/* 0x1a2c: cmp    eax,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 58ULL);
x86_l_1a2f:
	/* 0x1a2f: je     1a5b <tail_ipv6_to_endpoint+0x1a5b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a2f, 0x1a5b, x86_l_1a5b);
x86_l_1a31:
	/* 0x1a31: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_1a34:
	/* 0x1a34: je     1a45 <tail_ipv6_to_endpoint+0x1a45> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a34, 0x1a45, x86_l_1a45);
x86_l_1a36:
	/* 0x1a36: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_1a39:
	/* 0x1a39: jne    1a6a <tail_ipv6_to_endpoint+0x1a6a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1a39, 0x1a6a, x86_l_1a6a);
x86_l_1a3b:
	/* 0x1a3b: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a3e:
	/* 0x1a3e: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1a43:
	/* 0x1a43: jmp    1a63 <tail_ipv6_to_endpoint+0x1a63> */
	X86_SIM_X86_JMP(0x1a43, 0x1a63, x86_l_1a63);
x86_l_1a45:
	/* 0x1a45: mov    DWORD PTR [rsp],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a4c:
	/* 0x1a4c: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1a51:
	/* 0x1a51: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a56:
	/* 0x1a56: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a59:
	/* 0x1a59: jmp    1a7b <tail_ipv6_to_endpoint+0x1a7b> */
	X86_SIM_X86_JMP(0x1a59, 0x1a7b, x86_l_1a7b);
x86_l_1a5b:
	/* 0x1a5b: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a5e:
	/* 0x1a5e: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1a63:
	/* 0x1a63: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a68:
	/* 0x1a68: jmp    1a74 <tail_ipv6_to_endpoint+0x1a74> */
	X86_SIM_X86_JMP(0x1a68, 0x1a74, x86_l_1a74);
x86_l_1a6a:
	/* 0x1a6a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a6c:
	/* 0x1a6c: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a71:
	/* 0x1a71: mov    r13b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_8, 1ULL);
x86_l_1a74:
	/* 0x1a74: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a7b:
	/* 0x1a7b: movzx  ecx,WORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_1a80:
	/* 0x1a80: test   cx,cx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_16);
x86_l_1a83:
	/* 0x1a83: je     1b10 <tail_ipv6_to_endpoint+0x1b10> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a83, 0x1b10, x86_l_1b10);
x86_l_1a89:
	/* 0x1a89: movzx  r14d,WORD PTR [r14+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_1a8e:
	/* 0x1a8e: mov    r12d,0xffffff72 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967154ULL);
x86_l_1a94:
	/* 0x1a94: cmp    eax,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_1a97:
	/* 0x1a97: jg     1aa8 <tail_ipv6_to_endpoint+0x1aa8> */
	X86_SIM_X86_JCC(X86_CC_G, 0x1a97, 0x1aa8, x86_l_1aa8);
x86_l_1a99:
	/* 0x1a99: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a9c:
	/* 0x1a9c: je     1b10 <tail_ipv6_to_endpoint+0x1b10> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a9c, 0x1b10, x86_l_1b10);
x86_l_1a9e:
	/* 0x1a9e: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_1aa1:
	/* 0x1aa1: je     1ab6 <tail_ipv6_to_endpoint+0x1ab6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1aa1, 0x1ab6, x86_l_1ab6);
x86_l_1aa3:
	/* 0x1aa3: jmp    1b84 <tail_ipv6_to_endpoint+0x1b84> */
	X86_SIM_X86_JMP(0x1aa3, 0x1b84, x86_l_1b84);
x86_l_1aa8:
	/* 0x1aa8: cmp    eax,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 58ULL);
x86_l_1aab:
	/* 0x1aab: je     1b10 <tail_ipv6_to_endpoint+0x1b10> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1aab, 0x1b10, x86_l_1b10);
x86_l_1aad:
	/* 0x1aad: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_1ab0:
	/* 0x1ab0: jne    1b84 <tail_ipv6_to_endpoint+0x1b84> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1ab0, 0x1b84, x86_l_1b84);
x86_l_1ab6:
	/* 0x1ab6: cmp    cx,r14w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R14, X86_WIDTH_16);
x86_l_1aba:
	/* 0x1aba: je     1b10 <tail_ipv6_to_endpoint+0x1b10> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1aba, 0x1b10, x86_l_1b10);
x86_l_1abc:
	/* 0x1abc: mov    WORD PTR [rsp+0x58],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1ac1:
	/* 0x1ac1: lea    rdx,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1ac6:
	/* 0x1ac6: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_1acb:
	/* 0x1acb: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1ace:
	/* 0x1ace: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ad3:
	/* 0x1ad3: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1ad8:
	/* 0x1ad8: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1adb:
	/* 0x1adb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1add:
	/* 0x1add: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1adf:
	/* 0x1adf: js     1bac <tail_ipv6_to_endpoint+0x1bac> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1adf, 0x1bac, x86_l_1bac);
x86_l_1ae5:
	/* 0x1ae5: movzx  ecx,WORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 88ULL);
x86_l_1aea:
	/* 0x1aea: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1aef:
	/* 0x1aef: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1af4:
	/* 0x1af4: lea    esi,[rdx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1af7:
	/* 0x1af7: mov    r8d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1afb:
	/* 0x1afb: or     r8d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_1aff:
	/* 0x1aff: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_1b04:
	/* 0x1b04: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1b07:
	/* 0x1b07: mov    edx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_32);
x86_l_1b0a:
	/* 0x1b0a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b0c:
	/* 0x1b0c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1b0e:
	/* 0x1b0e: js     1b7e <tail_ipv6_to_endpoint+0x1b7e> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1b0e, 0x1b7e, x86_l_1b7e);
x86_l_1b10:
	/* 0x1b10: test   r13b,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_8);
x86_l_1b13:
	/* 0x1b13: jne    37e <tail_ipv6_to_endpoint+0x37e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1b13, 0x37e, x86_l_37e);
x86_l_1b19:
	/* 0x1b19: lea    rdi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1b1e:
	/* 0x1b1e: mov    eax,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_1b23:
	/* 0x1b23: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1b28:
	/* 0x1b28: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1b2b:
	/* 0x1b2b: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1b30:
	/* 0x1b30: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b33:
	/* 0x1b33: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b35:
	/* 0x1b35: mov    r14d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_32);
x86_l_1b38:
	/* 0x1b38: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b3d:
	/* 0x1b3d: add    esi,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RSI, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1b41:
	/* 0x1b41: mov    r8d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b45:
	/* 0x1b45: or     r8d,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 144ULL);
x86_l_1b4c:
	/* 0x1b4c: mov    r15d,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 11ULL);
x86_l_1b52:
	/* 0x1b52: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1b55:
	/* 0x1b55: mov    r12,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RSI, X86_WIDTH_64);
x86_l_1b58:
	/* 0x1b58: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b5a:
	/* 0x1b5a: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1b5c:
	/* 0x1b5c: call   r15 */
	X86_SIM_BPF_CALL_REG(X86_R15);
x86_l_1b5f:
	/* 0x1b5f: cmp    eax,0xffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967274ULL);
x86_l_1b62:
	/* 0x1b62: jne    1b76 <tail_ipv6_to_endpoint+0x1b76> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1b62, 0x1b76, x86_l_1b76);
x86_l_1b64:
	/* 0x1b64: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1b67:
	/* 0x1b67: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_1b6a:
	/* 0x1b6a: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b6c:
	/* 0x1b6c: mov    ecx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_32);
x86_l_1b6f:
	/* 0x1b6f: mov    r8d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b73:
	/* 0x1b73: call   r15 */
	X86_SIM_BPF_CALL_REG(X86_R15);
x86_l_1b76:
	/* 0x1b76: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1b78:
	/* 0x1b78: jns    37e <tail_ipv6_to_endpoint+0x37e> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1b78, 0x37e, x86_l_37e);
x86_l_1b7e:
	/* 0x1b7e: mov    r12d,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967142ULL);
x86_l_1b84:
	/* 0x1b84: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b87:
	/* 0x1b87: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_1b8a:
	/* 0x1b8a: js     34 <tail_ipv6_to_endpoint+0x34> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1b8a, 0x34, x86_l_34);
x86_l_1b90:
	/* 0x1b90: cmp    r12d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 2ULL);
x86_l_1b94:
	/* 0x1b94: je     34 <tail_ipv6_to_endpoint+0x34> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1b94, 0x34, x86_l_34);
x86_l_1b9a:
	/* 0x1b9a: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_1b9d:
	/* 0x1b9d: add    rsp,0x108 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 264ULL);
x86_l_1ba4:
	/* 0x1ba4: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_1ba6:
	/* 0x1ba6: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_1ba7:
	/* 0x1ba7: jmp    1bdf <tail_ipv6_to_endpoint+0x1bdf> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_1bac:
	/* 0x1bac: mov    r12d,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967155ULL);
x86_l_1bb2:
	/* 0x1bb2: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1bb5:
	/* 0x1bb5: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_1bb8:
	/* 0x1bb8: jns    1b90 <tail_ipv6_to_endpoint+0x1b90> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1bb8, 0x1b90, x86_l_1b90);
x86_l_1bba:
	/* 0x1bba: jmp    34 <tail_ipv6_to_endpoint+0x34> */
	X86_SIM_X86_JMP(0x1bba, 0x34, x86_l_34);
x86_l_1bbf:
	/* 0x1bbf: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1bc1:
	/* 0x1bc1: add    rax,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1bc4:
	/* 0x1bc4: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bc9:
	/* 0x1bc9: cmp    rax,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_1bcc:
	/* 0x1bcc: jae    b8c <tail_ipv6_to_endpoint+0xb8c> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x1bcc, 0xb8c, x86_l_b8c);
x86_l_1bd2:
	/* 0x1bd2: jmp    bcd <tail_ipv6_to_endpoint+0xbcd> */
	X86_SIM_X86_JMP(0x1bd2, 0xbcd, x86_l_bcd);
x86_l_1bd7:
	/* 0x1bd7: mov    r15d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_32);
x86_l_1bda:
	/* 0x1bda: jmp    a05 <tail_ipv6_to_endpoint+0xa05> */
	X86_SIM_X86_JMP(0x1bda, 0xa05, x86_l_a05);
x86_l_1bdf:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
