extern char __config_allow_icmp_frag_needed;
extern char __config_cilium_host_mac;
extern char __config_cilium_net_ifindex;
extern char __config_debug_lb;
extern char __config_enable_conntrack_accounting;
extern char __config_enable_icmp_rule;
extern char __config_enable_ipv4_fragments;
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
int cilium_bpf_lxc_tail_ipv4_to_endpoint_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0xa: sub    rsp,0xe8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 232ULL);
x86_l_11:
	/* 0x11: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_14:
	/* 0x14: movabs r13,0x2090b0100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 8741650688ULL);
x86_l_1e:
	/* 0x1e: mov    r12d,DWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_22:
	/* 0x22: mov    eax,DWORD PTR [rdi+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_25:
	/* 0x25: mov    DWORD PTR [rdi+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_2c:
	/* 0x2c: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_2e:
	/* 0x2e: sub    ecx,DWORD PTR [rdi+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_31:
	/* 0x31: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_36:
	/* 0x36: cmp    ecx,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 34ULL);
x86_l_39:
	/* 0x39: jae    b5 <tail_ipv4_to_endpoint+0xb5> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x39, 0xb5, x86_l_b5);
x86_l_3b:
	/* 0x3b: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3e:
	/* 0x3e: mov    rcx,QWORD PTR [rip+0xdbc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_security_label)));
x86_l_45:
	/* 0x45: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_47:
	/* 0x47: mov    rdx,QWORD PTR [rip+0xdbc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_endpoint_id)));
x86_l_4e:
	/* 0x4e: movzx  edx,WORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_51:
	/* 0x51: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_53:
	/* 0x53: neg    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_55:
	/* 0x55: cmovs  esi,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RBP, X86_WIDTH_32, X86_CC_S);
x86_l_58:
	/* 0x58: movzx  esi,sil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_5c:
	/* 0x5c: movzx  edi,r15b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDI, X86_R15, X86_WIDTH_32, X86_WIDTH_8);
x86_l_60:
	/* 0x60: shl    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_63:
	/* 0x63: or     edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_OR);
x86_l_65:
	/* 0x65: mov    DWORD PTR [rbx+0x28],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_69:
	/* 0x69: mov    DWORD PTR [rbx+0x2c],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_6c:
	/* 0x6c: mov    DWORD PTR [rbx+0x30],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6f:
	/* 0x6f: mov    DWORD PTR [rbx+0x34],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_72:
	/* 0x72: mov    DWORD PTR [rbx+0x38],0x9a00202 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240679649794ULL);
x86_l_79:
	/* 0x79: mov    r14d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_32);
x86_l_7c:
	/* 0x7c: add    r13,0x950000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 9764864ULL);
x86_l_83:
	/* 0x83: mov    QWORD PTR [rsp+0x8],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_88:
	/* 0x88: mov    BYTE PTR [rsp+0x8],sil */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8d:
	/* 0x8d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_92:
	/* 0x92: mov    rdi,QWORD PTR [rip+0xdbc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_99:
	/* 0x99: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9e:
	/* 0x9e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a0:
	/* 0xa0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a3:
	/* 0xa3: je     18f <tail_ipv4_to_endpoint+0x18f> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa3, 0x18f, x86_l_18f);
x86_l_a9:
	/* 0xa9: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_ac:
	/* 0xac: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_b0:
	/* 0xb0: jmp    1b7 <tail_ipv4_to_endpoint+0x1b7> */
	X86_SIM_X86_JMP(0xb0, 0x1b7, x86_l_1b7);
x86_l_b5:
	/* 0xb5: mov    r14,QWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_bc:
	/* 0xbc: cmp    r12d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 3ULL);
x86_l_c0:
	/* 0xc0: jae    11a <tail_ipv4_to_endpoint+0x11a> */
	X86_SIM_X86_JCC(X86_CC_AE, 0xc0, 0x11a, x86_l_11a);
x86_l_c2:
	/* 0xc2: mov    eax,DWORD PTR [r14+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_c6:
	/* 0xc6: mov    QWORD PTR [rsp+0x36],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 231928233984ULL);
x86_l_cf:
	/* 0xcf: mov    WORD PTR [rsp+0x46],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 300647710720ULL);
x86_l_d6:
	/* 0xd6: mov    QWORD PTR [rsp+0x3e],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 266287972352ULL);
x86_l_df:
	/* 0xdf: mov    DWORD PTR [rsp+0x30],0x40 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430272ULL);
x86_l_e7:
	/* 0xe7: mov    BYTE PTR [rsp+0x37],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 236223201281ULL);
x86_l_ec:
	/* 0xec: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_f0:
	/* 0xf0: mov    WORD PTR [rsp+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_f7:
	/* 0xf7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_fc:
	/* 0xfc: mov    rdi,QWORD PTR [rip+0xdbc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipcache_v2)));
x86_l_103:
	/* 0x103: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_108:
	/* 0x108: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10a:
	/* 0x10a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10d:
	/* 0x10d: je     134 <tail_ipv4_to_endpoint+0x134> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10d, 0x134, x86_l_134);
x86_l_10f:
	/* 0x10f: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_111:
	/* 0x111: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_114:
	/* 0x114: cmovne r12d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RAX, X86_WIDTH_32, X86_CC_NE);
x86_l_118:
	/* 0x118: jmp    134 <tail_ipv4_to_endpoint+0x134> */
	X86_SIM_X86_JMP(0x118, 0x134, x86_l_134);
x86_l_11a:
	/* 0x11a: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_11d:
	/* 0x11d: and    eax,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_120:
	/* 0x120: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_123:
	/* 0x123: je     c2 <tail_ipv4_to_endpoint+0xc2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x123, 0xc2, x86_l_c2);
x86_l_125:
	/* 0x125: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_128:
	/* 0x128: and    eax,0xff000000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4278190080ULL);
x86_l_12d:
	/* 0x12d: cmp    eax,0x2000000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 33554432ULL);
x86_l_132:
	/* 0x132: je     c2 <tail_ipv4_to_endpoint+0xc2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x132, 0xc2, x86_l_c2);
x86_l_134:
	/* 0x134: mov    DWORD PTR [rsp+0x4],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_139:
	/* 0x139: mov    rax,QWORD PTR [rip+0xdbc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_endpoint_id)));
x86_l_140:
	/* 0x140: movzx  eax,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_143:
	/* 0x143: mov    rax,QWORD PTR [rip+0xdbc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_security_label)));
x86_l_14a:
	/* 0x14a: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14c:
	/* 0x14c: mov    r15d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_150:
	/* 0x150: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_159:
	/* 0x159: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_162:
	/* 0x162: lea    rax,[r13+0x7e0000] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8257536ULL);
x86_l_169:
	/* 0x169: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16e:
	/* 0x16e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_173:
	/* 0x173: mov    rdi,QWORD PTR [rip+0xdbc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_17a:
	/* 0x17a: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17f:
	/* 0x17f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_181:
	/* 0x181: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_184:
	/* 0x184: je     1d7 <tail_ipv4_to_endpoint+0x1d7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x184, 0x1d7, x86_l_1d7);
x86_l_186:
	/* 0x186: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_189:
	/* 0x189: add    QWORD PTR [rax+0x8],r15 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_18d:
	/* 0x18d: jmp    1ff <tail_ipv4_to_endpoint+0x1ff> */
	X86_SIM_X86_JMP(0x18d, 0x1ff, x86_l_1ff);
x86_l_18f:
	/* 0x18f: mov    QWORD PTR [rsp+0x30],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430209ULL);
x86_l_198:
	/* 0x198: mov    QWORD PTR [rsp+0x38],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_19d:
	/* 0x19d: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1a2:
	/* 0x1a2: mov    rdi,QWORD PTR [rip+0xdbc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1a9:
	/* 0x1a9: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ae:
	/* 0x1ae: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1b3:
	/* 0x1b3: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b5:
	/* 0x1b5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b7:
	/* 0x1b7: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1bc:
	/* 0x1bc: mov    rsi,QWORD PTR [rip+0xdbc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_1c3:
	/* 0x1c3: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1c6:
	/* 0x1c6: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_1cb:
	/* 0x1cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cd:
	/* 0x1cd: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_1d2:
	/* 0x1d2: jmp    1600 <tail_ipv4_to_endpoint+0x1600> */
	X86_SIM_X86_JMP(0x1d2, 0x1600, x86_l_1600);
x86_l_1d7:
	/* 0x1d7: mov    QWORD PTR [rsp+0x30],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430209ULL);
x86_l_1e0:
	/* 0x1e0: mov    QWORD PTR [rsp+0x38],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1e5:
	/* 0x1e5: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1ea:
	/* 0x1ea: mov    rdi,QWORD PTR [rip+0xdbc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1f1:
	/* 0x1f1: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f6:
	/* 0x1f6: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1fb:
	/* 0x1fb: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1fd:
	/* 0x1fd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ff:
	/* 0x1ff: mov    rax,QWORD PTR [rip+0xdbc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_interface_ifindex)));
x86_l_206:
	/* 0x206: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_208:
	/* 0x208: mov    DWORD PTR [rsp+0xb4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 180ULL);
x86_l_20f:
	/* 0x20f: mov    DWORD PTR [rsp+0xc4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 841813590016ULL);
x86_l_21a:
	/* 0x21a: movzx  r15d,WORD PTR [r14+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 20ULL);
x86_l_21f:
	/* 0x21f: test   r15d,0xff3f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R15, X86_WIDTH_32, 65343ULL);
x86_l_226:
	/* 0x226: setne  BYTE PTR [rsp+0x28] */
	X86_SIM_L_EXEC_SETCC_MEM(X86_RSP, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_REG_AUX_SRC_SHIFT(X86_CC_NE)), 40ULL);
x86_l_22b:
	/* 0x22b: mov    eax,DWORD PTR [r14+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_22f:
	/* 0x22f: mov    DWORD PTR [rsp+0x9c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_236:
	/* 0x236: mov    rax,QWORD PTR [rip+0xdbc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_ipv4_fragments)));
x86_l_23d:
	/* 0x23d: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_240:
	/* 0x240: sete   r13b */
	X86_SIM_L_EXEC_SETCC(X86_R13, X86_CC_E);
x86_l_244:
	/* 0x244: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_249:
	/* 0x249: mov    rdi,QWORD PTR [rip+0xdbc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_tail_call_buffer4)));
x86_l_250:
	/* 0x250: lea    rsi,[rsp+0xc4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_258:
	/* 0x258: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25a:
	/* 0x25a: mov    r12d,0xffffff48 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967112ULL);
x86_l_260:
	/* 0x260: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_263:
	/* 0x263: je     15da <tail_ipv4_to_endpoint+0x15da> */
	X86_SIM_X86_JCC(X86_CC_E, 0x263, 0x15da, x86_l_15da);
x86_l_269:
	/* 0x269: cmp    DWORD PTR [rax+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_26d:
	/* 0x26d: je     15da <tail_ipv4_to_endpoint+0x15da> */
	X86_SIM_X86_JCC(X86_CC_E, 0x26d, 0x15da, x86_l_15da);
x86_l_273:
	/* 0x273: mov    ecx,DWORD PTR [rax+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_276:
	/* 0x276: mov    DWORD PTR [rsp+0x8c],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_27d:
	/* 0x27d: mov    ecx,DWORD PTR [rax+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_280:
	/* 0x280: mov    esi,DWORD PTR [rax+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_283:
	/* 0x283: mov    DWORD PTR [rsp+0x84],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_28a:
	/* 0x28a: and    ecx,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_28d:
	/* 0x28d: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_290:
	/* 0x290: jne    2ca <tail_ipv4_to_endpoint+0x2ca> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x290, 0x2ca, x86_l_2ca);
x86_l_292:
	/* 0x292: movzx  r12d,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_297:
	/* 0x297: test   r12b,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R12, X86_WIDTH_8, 16ULL);
x86_l_29b:
	/* 0x29b: je     322 <tail_ipv4_to_endpoint+0x322> */
	X86_SIM_X86_JCC(X86_CC_E, 0x29b, 0x322, x86_l_322);
x86_l_2a1:
	/* 0x2a1: movzx  ecx,WORD PTR [rbx+0x86] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 134ULL);
x86_l_2a8:
	/* 0x2a8: mov    DWORD PTR [rsp+0x30],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2ac:
	/* 0x2ac: test   DWORD PTR [rsp+0x30],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430210ULL);
x86_l_2b4:
	/* 0x2b4: jne    322 <tail_ipv4_to_endpoint+0x322> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2b4, 0x322, x86_l_322);
x86_l_2b6:
	/* 0x2b6: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2b8:
	/* 0x2b8: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2bb:
	/* 0x2bb: movabs r13,0x2090b0100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 8741650688ULL);
x86_l_2c5:
	/* 0x2c5: jmp    c09 <tail_ipv4_to_endpoint+0xc09> */
	X86_SIM_X86_JMP(0x2c5, 0xc09, x86_l_c09);
x86_l_2ca:
	/* 0x2ca: movzx  ecx,WORD PTR [rbx+0x86] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 134ULL);
x86_l_2d1:
	/* 0x2d1: mov    DWORD PTR [rsp+0x30],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2d5:
	/* 0x2d5: mov    ecx,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2d9:
	/* 0x2d9: test   cl,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_2dc:
	/* 0x2dc: jne    3df <tail_ipv4_to_endpoint+0x3df> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2dc, 0x3df, x86_l_3df);
x86_l_2e2:
	/* 0x2e2: cmp    DWORD PTR [rsp+0x84],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_2ea:
	/* 0x2ea: mov    r12d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2ef:
	/* 0x2ef: jne    38a <tail_ipv4_to_endpoint+0x38a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2ef, 0x38a, x86_l_38a);
x86_l_2f5:
	/* 0x2f5: mov    ecx,DWORD PTR [r14+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_2f9:
	/* 0x2f9: mov    rdx,QWORD PTR [rip+0xdbc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_service_loopback_ipv4)));
x86_l_300:
	/* 0x300: cmp    ecx,DWORD PTR [rdx] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_302:
	/* 0x302: jne    38a <tail_ipv4_to_endpoint+0x38a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x302, 0x38a, x86_l_38a);
x86_l_308:
	/* 0x308: movzx  ecx,BYTE PTR [rax+0xd] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 13ULL);
x86_l_30c:
	/* 0x30c: mov    BYTE PTR [rsp+0x20],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_310:
	/* 0x310: cmp    BYTE PTR [rax+0xc],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 51539607558ULL);
x86_l_314:
	/* 0x314: jne    34e <tail_ipv4_to_endpoint+0x34e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x314, 0x34e, x86_l_34e);
x86_l_316:
	/* 0x316: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_319:
	/* 0x319: mov    rdi,QWORD PTR [rip+0xdbc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct4_global)));
x86_l_320:
	/* 0x320: jmp    358 <tail_ipv4_to_endpoint+0x358> */
	X86_SIM_X86_JMP(0x320, 0x358, x86_l_358);
x86_l_322:
	/* 0x322: movzx  ecx,WORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_326:
	/* 0x326: movzx  edx,WORD PTR [rax+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_32a:
	/* 0x32a: test   dx,dx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_16);
x86_l_32d:
	/* 0x32d: movabs r13,0x2090b0100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 8741650688ULL);
x86_l_337:
	/* 0x337: jne    1003 <tail_ipv4_to_endpoint+0x1003> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x337, 0x1003, x86_l_1003);
x86_l_33d:
	/* 0x33d: test   cx,cx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_16);
x86_l_340:
	/* 0x340: jne    1027 <tail_ipv4_to_endpoint+0x1027> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x340, 0x1027, x86_l_1027);
x86_l_346:
	/* 0x346: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_349:
	/* 0x349: jmp    1267 <tail_ipv4_to_endpoint+0x1267> */
	X86_SIM_X86_JMP(0x349, 0x1267, x86_l_1267);
x86_l_34e:
	/* 0x34e: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_351:
	/* 0x351: mov    rdi,QWORD PTR [rip+0xdbc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct_any4_global)));
x86_l_358:
	/* 0x358: mov    BYTE PTR [rax+0xd],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 55834574848ULL);
x86_l_35c:
	/* 0x35c: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_361:
	/* 0x361: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_364:
	/* 0x364: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_367:
	/* 0x367: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_369:
	/* 0x369: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_36c:
	/* 0x36c: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_36f:
	/* 0x36f: movzx  edx,BYTE PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 32ULL);
x86_l_374:
	/* 0x374: mov    BYTE PTR [r15+0xd],dl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 13ULL);
x86_l_378:
	/* 0x378: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_37b:
	/* 0x37b: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_37e:
	/* 0x37e: je     38a <tail_ipv4_to_endpoint+0x38a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x37e, 0x38a, x86_l_38a);
x86_l_380:
	/* 0x380: test   BYTE PTR [rcx+0x24],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 154618822664ULL);
x86_l_384:
	/* 0x384: jne    9eb <tail_ipv4_to_endpoint+0x9eb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x384, 0x9eb, x86_l_9eb);
x86_l_38a:
	/* 0x38a: test   BYTE PTR [rax+0x24],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 154618822657ULL);
x86_l_38e:
	/* 0x38e: jne    3df <tail_ipv4_to_endpoint+0x3df> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x38e, 0x3df, x86_l_3df);
x86_l_390:
	/* 0x390: mov    rcx,QWORD PTR [rip+0xdbc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_security_label)));
x86_l_397:
	/* 0x397: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_399:
	/* 0x399: movzx  ecx,WORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_39d:
	/* 0x39d: movzx  r15d,BYTE PTR [rax+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 12ULL);
x86_l_3a2:
	/* 0x3a2: mov    DWORD PTR [rsp+0x70],0x40 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 481036337216ULL);
x86_l_3aa:
	/* 0x3aa: mov    DWORD PTR [rsp+0x74],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_3af:
	/* 0x3af: mov    BYTE PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_3b4:
	/* 0x3b4: mov    BYTE PTR [rsp+0x79],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 121ULL);
x86_l_3b9:
	/* 0x3b9: mov    WORD PTR [rsp+0x7a],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 122ULL);
x86_l_3be:
	/* 0x3be: mov    r14,QWORD PTR [rip+0xdbc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_allow_icmp_frag_needed)));
x86_l_3c5:
	/* 0x3c5: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3c9:
	/* 0x3c9: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3ce:
	/* 0x3ce: mov    DWORD PTR [rsp+0x20],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3d2:
	/* 0x3d2: je     3f3 <tail_ipv4_to_endpoint+0x3f3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3d2, 0x3f3, x86_l_3f3);
x86_l_3d4:
	/* 0x3d4: cmp    r15b,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_8, 1ULL);
x86_l_3d8:
	/* 0x3d8: je     40f <tail_ipv4_to_endpoint+0x40f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3d8, 0x40f, x86_l_40f);
x86_l_3da:
	/* 0x3da: jmp    490 <tail_ipv4_to_endpoint+0x490> */
	X86_SIM_X86_JMP(0x3da, 0x490, x86_l_490);
x86_l_3df:
	/* 0x3df: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3e1:
	/* 0x3e1: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3e4:
	/* 0x3e4: movabs r13,0x2090b0100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 8741650688ULL);
x86_l_3ee:
	/* 0x3ee: jmp    9be <tail_ipv4_to_endpoint+0x9be> */
	X86_SIM_X86_JMP(0x3ee, 0x9be, x86_l_9be);
x86_l_3f3:
	/* 0x3f3: mov    rax,QWORD PTR [rip+0xdbc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_icmp_rule)));
x86_l_3fa:
	/* 0x3fa: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_3fd:
	/* 0x3fd: cmp    r15b,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_8, 1ULL);
x86_l_401:
	/* 0x401: jne    490 <tail_ipv4_to_endpoint+0x490> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x401, 0x490, x86_l_490);
x86_l_407:
	/* 0x407: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_409:
	/* 0x409: je     490 <tail_ipv4_to_endpoint+0x490> */
	X86_SIM_X86_JCC(X86_CC_E, 0x409, 0x490, x86_l_490);
x86_l_40f:
	/* 0x40f: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_414:
	/* 0x414: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_419:
	/* 0x419: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_41c:
	/* 0x41c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_421:
	/* 0x421: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_423:
	/* 0x423: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_425:
	/* 0x425: js     559 <tail_ipv4_to_endpoint+0x559> */
	X86_SIM_X86_JCC(X86_CC_S, 0x425, 0x559, x86_l_559);
x86_l_42b:
	/* 0x42b: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_42f:
	/* 0x42f: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_434:
	/* 0x434: je     478 <tail_ipv4_to_endpoint+0x478> */
	X86_SIM_X86_JCC(X86_CC_E, 0x434, 0x478, x86_l_478);
x86_l_436:
	/* 0x436: cmp    BYTE PTR [rsp+0x30],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430211ULL);
x86_l_43b:
	/* 0x43b: jne    478 <tail_ipv4_to_endpoint+0x478> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x43b, 0x478, x86_l_478);
x86_l_43d:
	/* 0x43d: cmp    BYTE PTR [rsp+0x31],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 210453397508ULL);
x86_l_442:
	/* 0x442: jne    478 <tail_ipv4_to_endpoint+0x478> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x442, 0x478, x86_l_478);
x86_l_444:
	/* 0x444: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_447:
	/* 0x447: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_449:
	/* 0x449: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_44b:
	/* 0x44b: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_44e:
	/* 0x44e: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_451:
	/* 0x451: movabs r13,0x2090b0100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 8741650688ULL);
x86_l_45b:
	/* 0x45b: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_45e:
	/* 0x45e: setne  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_NE);
x86_l_462:
	/* 0x462: cmp    DWORD PTR [rsp+0x84],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 566935683073ULL);
x86_l_46a:
	/* 0x46a: je     680 <tail_ipv4_to_endpoint+0x680> */
	X86_SIM_X86_JCC(X86_CC_E, 0x46a, 0x680, x86_l_680);
x86_l_470:
	/* 0x470: mov    r10d,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_R10, X86_R15, X86_WIDTH_32);
x86_l_473:
	/* 0x473: jmp    68c <tail_ipv4_to_endpoint+0x68c> */
	X86_SIM_X86_JMP(0x473, 0x68c, x86_l_68c);
x86_l_478:
	/* 0x478: mov    rax,QWORD PTR [rip+0xdbc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_icmp_rule)));
x86_l_47f:
	/* 0x47f: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_482:
	/* 0x482: je     490 <tail_ipv4_to_endpoint+0x490> */
	X86_SIM_X86_JCC(X86_CC_E, 0x482, 0x490, x86_l_490);
x86_l_484:
	/* 0x484: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_488:
	/* 0x488: shl    eax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_48b:
	/* 0x48b: mov    WORD PTR [rsp+0x7a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 122ULL);
x86_l_490:
	/* 0x490: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_495:
	/* 0x495: mov    rdi,QWORD PTR [rip+0xdbc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_policy_v2)));
x86_l_49c:
	/* 0x49c: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_4a1:
	/* 0x4a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a3:
	/* 0x4a3: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_4a6:
	/* 0x4a6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4a9:
	/* 0x4a9: je     107c <tail_ipv4_to_endpoint+0x107c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4a9, 0x107c, x86_l_107c);
x86_l_4af:
	/* 0x4af: cmp    DWORD PTR [r12+0x4],0xffffffff */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 21474836479ULL);
x86_l_4b5:
	/* 0x4b5: jne    107c <tail_ipv4_to_endpoint+0x107c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4b5, 0x107c, x86_l_107c);
x86_l_4bb:
	/* 0x4bb: xor    r9d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R9, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4be:
	/* 0x4be: movzx  r14d,WORD PTR [r12+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_4c4:
	/* 0x4c4: mov    rax,QWORD PTR [rip+0xdbc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_policy_accounting)));
x86_l_4cb:
	/* 0x4cb: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ce:
	/* 0x4ce: mov    ecx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_32);
x86_l_4d1:
	/* 0x4d1: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4d6:
	/* 0x4d6: movabs r13,0x2090b0100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 8741650688ULL);
x86_l_4e0:
	/* 0x4e0: je     5f9 <tail_ipv4_to_endpoint+0x5f9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4e0, 0x5f9, x86_l_5f9);
x86_l_4e6:
	/* 0x4e6: mov    ecx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_32);
x86_l_4e9:
	/* 0x4e9: shr    cl,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_SHR, 3ULL);
x86_l_4ec:
	/* 0x4ec: movzx  edx,BYTE PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 120ULL);
x86_l_4f1:
	/* 0x4f1: mov    r13d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_4f5:
	/* 0x4f5: mov    rsi,QWORD PTR [rip+0xdbc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_endpoint_id)));
x86_l_4fc:
	/* 0x4fc: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4ff:
	/* 0x4ff: mov    WORD PTR [rsp+0x8],si */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_504:
	/* 0x504: mov    BYTE PTR [rsp+0xa],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42949672960ULL);
x86_l_509:
	/* 0x509: mov    BYTE PTR [rsp+0xb],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 11ULL);
x86_l_50d:
	/* 0x50d: and    dl,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_8, X86_ALU_AND, 1ULL);
x86_l_510:
	/* 0x510: mov    esi,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_514:
	/* 0x514: mov    DWORD PTR [rsp+0xc],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_518:
	/* 0x518: mov    BYTE PTR [rsp+0x10],dl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_51c:
	/* 0x51c: cmp    r14b,0x47 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 71ULL);
x86_l_520:
	/* 0x520: mov    QWORD PTR [rsp+0x68],r9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_525:
	/* 0x525: ja     539 <tail_ipv4_to_endpoint+0x539> */
	X86_SIM_X86_JCC(X86_CC_A, 0x525, 0x539, x86_l_539);
x86_l_527:
	/* 0x527: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_52a:
	/* 0x52a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_52c:
	/* 0x52c: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_52f:
	/* 0x52f: movzx  r15d,r15b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_8);
x86_l_533:
	/* 0x533: cmovne r15d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R15, X86_RCX, X86_WIDTH_32, X86_CC_NE);
x86_l_537:
	/* 0x537: jmp    587 <tail_ipv4_to_endpoint+0x587> */
	X86_SIM_X86_JMP(0x537, 0x587, x86_l_587);
x86_l_539:
	/* 0x539: cmp    r14b,0xbf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 191ULL);
x86_l_53d:
	/* 0x53d: ja     583 <tail_ipv4_to_endpoint+0x583> */
	X86_SIM_X86_JCC(X86_CC_A, 0x53d, 0x583, x86_l_583);
x86_l_53f:
	/* 0x53f: mov    al,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 24ULL);
x86_l_541:
	/* 0x541: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_543:
	/* 0x543: mov    ecx,0xffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 65535ULL);
x86_l_548:
	/* 0x548: shlx   eax,ecx,eax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RAX, X86_RCX, X86_WIDTH_32, X86_RAX, X86_ALU_SHL);
x86_l_54d:
	/* 0x54d: rol    ax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_551:
	/* 0x551: mov    ecx,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_555:
	/* 0x555: and    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_AND);
x86_l_557:
	/* 0x557: jmp    587 <tail_ipv4_to_endpoint+0x587> */
	X86_SIM_X86_JMP(0x557, 0x587, x86_l_587);
x86_l_559:
	/* 0x559: xor    r10d,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R10, X86_WIDTH_32, X86_ALU_XOR);
x86_l_55c:
	/* 0x55c: mov    r12d,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967162ULL);
x86_l_562:
	/* 0x562: mov    r9b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_8, 1ULL);
x86_l_565:
	/* 0x565: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_568:
	/* 0x568: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_56a:
	/* 0x56a: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_56c:
	/* 0x56c: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_56f:
	/* 0x56f: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_574:
	/* 0x574: movabs r13,0x2090b0100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 8741650688ULL);
x86_l_57e:
	/* 0x57e: jmp    68c <tail_ipv4_to_endpoint+0x68c> */
	X86_SIM_X86_JMP(0x57e, 0x68c, x86_l_68c);
x86_l_583:
	/* 0x583: mov    ecx,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_587:
	/* 0x587: mov    BYTE PTR [rsp+0x11],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17ULL);
x86_l_58c:
	/* 0x58c: mov    WORD PTR [rsp+0x12],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_591:
	/* 0x591: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_596:
	/* 0x596: mov    rdi,QWORD PTR [rip+0xdbc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_policystats)));
x86_l_59d:
	/* 0x59d: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a2:
	/* 0x5a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a4:
	/* 0x5a4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5a7:
	/* 0x5a7: je     5b4 <tail_ipv4_to_endpoint+0x5b4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5a7, 0x5b4, x86_l_5b4);
x86_l_5a9:
	/* 0x5a9: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_5ad:
	/* 0x5ad: add QWORD PTR [rax+0x8],r13 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5b2:
	/* 0x5b2: jmp    5df <tail_ipv4_to_endpoint+0x5df> */
	X86_SIM_X86_JMP(0x5b2, 0x5df, x86_l_5df);
x86_l_5b4:
	/* 0x5b4: mov    QWORD PTR [rsp+0x30],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430209ULL);
x86_l_5bd:
	/* 0x5bd: mov    QWORD PTR [rsp+0x38],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_5c2:
	/* 0x5c2: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5c7:
	/* 0x5c7: mov    rdi,QWORD PTR [rip+0xdbc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_policystats)));
x86_l_5ce:
	/* 0x5ce: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d3:
	/* 0x5d3: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5d8:
	/* 0x5d8: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_5dd:
	/* 0x5dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5df:
	/* 0x5df: movzx  ecx,WORD PTR [r12+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_5e5:
	/* 0x5e5: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5ea:
	/* 0x5ea: movabs r13,0x2090b0100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 8741650688ULL);
x86_l_5f4:
	/* 0x5f4: mov    r9,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_5f9:
	/* 0x5f9: cmp    r14b,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 8ULL);
x86_l_5fd:
	/* 0x5fd: setae  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_AE);
x86_l_600:
	/* 0x600: shl    dl,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_8, X86_ALU_SHL, 2ULL);
x86_l_603:
	/* 0x603: or     dl,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_8, X86_ALU_OR, 1ULL);
x86_l_606:
	/* 0x606: cmp    r14b,0x48 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 72ULL);
x86_l_60a:
	/* 0x60a: movzx  edx,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_60d:
	/* 0x60d: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_613:
	/* 0x613: cmovb  r8d,edx */
	X86_SIM_L_EXEC_CMOV(X86_R8, X86_RDX, X86_WIDTH_32, X86_CC_B);
x86_l_617:
	/* 0x617: mov    edi,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_61c:
	/* 0x61c: test   cl,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_61f:
	/* 0x61f: jne    19a5 <tail_ipv4_to_endpoint+0x19a5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x61f, 0x19a5, x86_l_19a5);
x86_l_625:
	/* 0x625: movzx  r15d,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_629:
	/* 0x629: shr    r15d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_62d:
	/* 0x62d: test   r9,r9 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R9, X86_R9, X86_WIDTH_64);
x86_l_630:
	/* 0x630: je     656 <tail_ipv4_to_endpoint+0x656> */
	X86_SIM_X86_JCC(X86_CC_E, 0x630, 0x656, x86_l_656);
x86_l_632:
	/* 0x632: test   cx,cx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_16);
x86_l_635:
	/* 0x635: js     656 <tail_ipv4_to_endpoint+0x656> */
	X86_SIM_X86_JCC(X86_CC_S, 0x635, 0x656, x86_l_656);
x86_l_637:
	/* 0x637: mov    ecx,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_63c:
	/* 0x63c: cmp    DWORD PTR [r9+0x4],ecx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R9, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_640:
	/* 0x640: jne    656 <tail_ipv4_to_endpoint+0x656> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x640, 0x656, x86_l_656);
x86_l_642:
	/* 0x642: movzx  ecx,BYTE PTR [r9+0x3] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R9, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 3ULL);
x86_l_647:
	/* 0x647: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_649:
	/* 0x649: and    edx,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 127ULL);
x86_l_64c:
	/* 0x64c: cmp    dx,r15w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_16);
x86_l_650:
	/* 0x650: ja     169e <tail_ipv4_to_endpoint+0x169e> */
	X86_SIM_X86_JCC(X86_CC_A, 0x650, 0x169e, x86_l_169e);
x86_l_656:
	/* 0x656: movzx  esi,WORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_65b:
	/* 0x65b: and    r15b,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_8, X86_ALU_AND, 127ULL);
x86_l_65f:
	/* 0x65f: jne    18ba <tail_ipv4_to_endpoint+0x18ba> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x65f, 0x18ba, x86_l_18ba);
x86_l_665:
	/* 0x665: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_668:
	/* 0x668: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_66b:
	/* 0x66b: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_66e:
	/* 0x66e: setne  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_NE);
x86_l_672:
	/* 0x672: cmp    DWORD PTR [rsp+0x84],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 566935683073ULL);
x86_l_67a:
	/* 0x67a: jne    470 <tail_ipv4_to_endpoint+0x470> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x67a, 0x470, x86_l_470);
x86_l_680:
	/* 0x680: mov    r10d,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_R10, X86_R15, X86_WIDTH_32);
x86_l_683:
	/* 0x683: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_686:
	/* 0x686: je     c00 <tail_ipv4_to_endpoint+0xc00> */
	X86_SIM_X86_JCC(X86_CC_E, 0x686, 0xc00, x86_l_c00);
x86_l_68c:
	/* 0x68c: movzx  ecx,WORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_690:
	/* 0x690: mov    WORD PTR [rsp+0x68],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_695:
	/* 0x695: movzx  ecx,BYTE PTR [rax+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 12ULL);
x86_l_699:
	/* 0x699: mov    BYTE PTR [rsp+0x20],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_69d:
	/* 0x69d: mov    r14d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_6a1:
	/* 0x6a1: mov    rcx,QWORD PTR [rip+0xdbc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_6a8:
	/* 0x6a8: mov    r11d,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6ab:
	/* 0x6ab: cmp    r14d,r11d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R14, X86_R11, X86_WIDTH_32);
x86_l_6ae:
	/* 0x6ae: cmovb  r11d,r14d */
	X86_SIM_L_EXEC_CMOV(X86_R11, X86_R14, X86_WIDTH_32, X86_CC_B);
x86_l_6b2:
	/* 0x6b2: mov    QWORD PTR [rsp+0x70],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337154ULL);
x86_l_6bb:
	/* 0x6bb: mov    rcx,QWORD PTR [rip+0xdbc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_policy_verdict_log_filter)));
x86_l_6c2:
	/* 0x6c2: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6c4:
	/* 0x6c4: mov    BYTE PTR [rsp+0x30],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 206158430209ULL);
x86_l_6c9:
	/* 0x6c9: movzx  edx,BYTE PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 48ULL);
x86_l_6ce:
	/* 0x6ce: test   ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_6d0:
	/* 0x6d0: je     9b5 <tail_ipv4_to_endpoint+0x9b5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6d0, 0x9b5, x86_l_9b5);
x86_l_6d6:
	/* 0x6d6: mov    BYTE PTR [rsp+0xa8],r9b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_6de:
	/* 0x6de: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_6e1:
	/* 0x6e1: mov    DWORD PTR [rsp+0x28],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6e5:
	/* 0x6e5: movzx  r13d,si */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R13, X86_RSI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_6e9:
	/* 0x6e9: cmovne r13d,r12d */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_R12, X86_WIDTH_32, X86_CC_NE);
x86_l_6ed:
	/* 0x6ed: mov    rax,QWORD PTR [rip+0xdbc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_events_map_rate_limit)));
x86_l_6f4:
	/* 0x6f4: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6f7:
	/* 0x6f7: je     8f3 <tail_ipv4_to_endpoint+0x8f3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6f7, 0x8f3, x86_l_8f3);
x86_l_6fd:
	/* 0x6fd: mov    QWORD PTR [rsp+0xb8],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_705:
	/* 0x705: mov    DWORD PTR [rsp+0x98],r10d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R10, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_70d:
	/* 0x70d: mov    DWORD PTR [rsp+0x80],r8d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_715:
	/* 0x715: mov    QWORD PTR [rsp+0xa0],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_71d:
	/* 0x71d: mov    rcx,QWORD PTR [rip+0xdbc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_events_map_burst_limit)));
x86_l_724:
	/* 0x724: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_726:
	/* 0x726: mov    QWORD PTR [rsp+0xe0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_72e:
	/* 0x72e: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_730:
	/* 0x730: mov    QWORD PTR [rsp+0xc8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_738:
	/* 0x738: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_73d:
	/* 0x73d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_73f:
	/* 0x73f: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_741:
	/* 0x741: mov    QWORD PTR [rsp+0xd0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_749:
	/* 0x749: mov    eax,DWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_74d:
	/* 0x74d: mov    DWORD PTR [rsp+0x90],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_754:
	/* 0x754: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_759:
	/* 0x759: mov    rdi,QWORD PTR [rip+0xdbc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit_metrics)));
x86_l_760:
	/* 0x760: lea    rsi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_768:
	/* 0x768: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_76a:
	/* 0x76a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_76d:
	/* 0x76d: jne    7a5 <tail_ipv4_to_endpoint+0x7a5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x76d, 0x7a5, x86_l_7a5);
x86_l_76f:
	/* 0x76f: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_778:
	/* 0x778: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_77d:
	/* 0x77d: mov    rdi,QWORD PTR [rip+0xdbc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit_metrics)));
x86_l_784:
	/* 0x784: lea    rsi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_78c:
	/* 0x78c: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_791:
	/* 0x791: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_793:
	/* 0x793: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_795:
	/* 0x795: lea    rcx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_79a:
	/* 0x79a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_79c:
	/* 0x79c: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_79f:
	/* 0x79f: js     999 <tail_ipv4_to_endpoint+0x999> */
	X86_SIM_X86_JCC(X86_CC_S, 0x79f, 0x999, x86_l_999);
x86_l_7a5:
	/* 0x7a5: mov    QWORD PTR [rsp+0xd8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_7ad:
	/* 0x7ad: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7b2:
	/* 0x7b2: mov    rdi,QWORD PTR [rip+0xdbc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit)));
x86_l_7b9:
	/* 0x7b9: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_7be:
	/* 0x7be: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7c0:
	/* 0x7c0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7c3:
	/* 0x7c3: je     85f <tail_ipv4_to_endpoint+0x85f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7c3, 0x85f, x86_l_85f);
x86_l_7c9:
	/* 0x7c9: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7cc:
	/* 0x7cc: mov    rdi,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_7d4:
	/* 0x7d4: mov    rsi,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RDI, X86_WIDTH_64);
x86_l_7d7:
	/* 0x7d7: sub    rsi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_7da:
	/* 0x7da: cmp    rsi,0x3b9aca00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 1000000000ULL);
x86_l_7e1:
	/* 0x7e1: jbe    8bf <tail_ipv4_to_endpoint+0x8bf> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x7e1, 0x8bf, x86_l_8bf);
x86_l_7e7:
	/* 0x7e7: mov    rdx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_7ea:
	/* 0x7ea: shr    rdx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_7ee:
	/* 0x7ee: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_7f8:
	/* 0x7f8: mulx   rcx,rcx,rcx */
	X86_SIM_L_EXEC_MULX(X86_RCX, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_7fd:
	/* 0x7fd: shr    rcx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_801:
	/* 0x801: imul   rdx,rcx,0x3b9aca00 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RDX, X86_RCX, X86_WIDTH_64, 1000000000ULL);
x86_l_808:
	/* 0x808: imul   rcx,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 200ULL);
x86_l_811:
	/* 0x811: add    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_815:
	/* 0x815: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_819:
	/* 0x819: sub    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_81c:
	/* 0x81c: add    rdi,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_81f:
	/* 0x81f: mov    QWORD PTR [rax],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_822:
	/* 0x822: mov    rdx,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_82a:
	/* 0x82a: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_82d:
	/* 0x82d: mov    rdi,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_835:
	/* 0x835: mov    r8d,DWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_83d:
	/* 0x83d: mov    r10d,DWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_845:
	/* 0x845: mov    r11,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_84d:
	/* 0x84d: jbe    8e3 <tail_ipv4_to_endpoint+0x8e3> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x84d, 0x8e3, x86_l_8e3);
x86_l_853:
	/* 0x853: mov    QWORD PTR [rax+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_857:
	/* 0x857: mov    rcx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_85a:
	/* 0x85a: jmp    8e3 <tail_ipv4_to_endpoint+0x8e3> */
	X86_SIM_X86_JMP(0x85a, 0x8e3, x86_l_8e3);
x86_l_85f:
	/* 0x85f: mov    rax,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_867:
	/* 0x867: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_86c:
	/* 0x86c: mov    rax,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_874:
	/* 0x874: dec    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_877:
	/* 0x877: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_87c:
	/* 0x87c: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_881:
	/* 0x881: mov    rdi,QWORD PTR [rip+0xdbc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit)));
x86_l_888:
	/* 0x888: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_88d:
	/* 0x88d: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_892:
	/* 0x892: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_894:
	/* 0x894: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_896:
	/* 0x896: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_898:
	/* 0x898: mov    rdi,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_8a0:
	/* 0x8a0: mov    r8d,DWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_8a8:
	/* 0x8a8: mov    r10d,DWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_8b0:
	/* 0x8b0: mov    r11,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_8b8:
	/* 0x8b8: jns    8f3 <tail_ipv4_to_endpoint+0x8f3> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x8b8, 0x8f3, x86_l_8f3);
x86_l_8ba:
	/* 0x8ba: jmp    ff3 <tail_ipv4_to_endpoint+0xff3> */
	X86_SIM_X86_JMP(0x8ba, 0xff3, x86_l_ff3);
x86_l_8bf:
	/* 0x8bf: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8c3:
	/* 0x8c3: mov    rdi,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_8cb:
	/* 0x8cb: mov    r8d,DWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_8d3:
	/* 0x8d3: mov    r10d,DWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_8db:
	/* 0x8db: mov    r11,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_8e3:
	/* 0x8e3: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_8e6:
	/* 0x8e6: je     ff3 <tail_ipv4_to_endpoint+0xff3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8e6, 0xff3, x86_l_ff3);
x86_l_8ec:
	/* 0x8ec: dec    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_8ef:
	/* 0x8ef: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8f3:
	/* 0x8f3: mov    rax,QWORD PTR [rip+0xdbc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_endpoint_id)));
x86_l_8fa:
	/* 0x8fa: movzx  eax,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_8fd:
	/* 0x8fd: mov    ecx,DWORD PTR [rbx+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_903:
	/* 0x903: mov    BYTE PTR [rsp+0x4f],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 339302416384ULL);
x86_l_908:
	/* 0x908: mov    WORD PTR [rsp+0x4d],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 330712481792ULL);
x86_l_90f:
	/* 0x90f: mov    WORD PTR [rsp+0x30],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 206158430213ULL);
x86_l_916:
	/* 0x916: mov    WORD PTR [rsp+0x32],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 50ULL);
x86_l_91b:
	/* 0x91b: mov    DWORD PTR [rsp+0x34],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_91f:
	/* 0x91f: mov    DWORD PTR [rsp+0x38],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_924:
	/* 0x924: mov    WORD PTR [rsp+0x3c],r11w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_92a:
	/* 0x92a: mov    WORD PTR [rsp+0x3e],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 266287972353ULL);
x86_l_931:
	/* 0x931: mov    eax,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_935:
	/* 0x935: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_939:
	/* 0x939: mov    DWORD PTR [rsp+0x44],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_93e:
	/* 0x93e: movzx  eax,WORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 104ULL);
x86_l_943:
	/* 0x943: movbe  WORD PTR [rsp+0x48],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 72ULL);
x86_l_94a:
	/* 0x94a: shl    r8b,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_94e:
	/* 0x94e: or     r8b,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_8, X86_ALU_OR, 1ULL);
x86_l_952:
	/* 0x952: movzx  eax,BYTE PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 32ULL);
x86_l_957:
	/* 0x957: mov    BYTE PTR [rsp+0x4a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 74ULL);
x86_l_95b:
	/* 0x95b: mov    BYTE PTR [rsp+0x4b],r8b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 75ULL);
x86_l_960:
	/* 0x960: mov    BYTE PTR [rsp+0x4c],r10b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R10, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_965:
	/* 0x965: mov    DWORD PTR [rsp+0x50],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_969:
	/* 0x969: mov    DWORD PTR [rsp+0x54],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360777252864ULL);
x86_l_971:
	/* 0x971: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_976:
	/* 0x976: shl    r11,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_97a:
	/* 0x97a: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_97f:
	/* 0x97f: or     rdx,r11 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R11, X86_WIDTH_64, X86_ALU_OR);
x86_l_982:
	/* 0x982: mov    rsi,QWORD PTR [rip+0xdbc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_events)));
x86_l_989:
	/* 0x989: lea    rcx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_98e:
	/* 0x98e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_991:
	/* 0x991: mov    r8d,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 40ULL);
x86_l_997:
	/* 0x997: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_999:
	/* 0x999: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_99e:
	/* 0x99e: movabs r13,0x2090b0100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 8741650688ULL);
x86_l_9a8:
	/* 0x9a8: mov    esi,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_9ac:
	/* 0x9ac: movzx  r9d,BYTE PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 168ULL);
x86_l_9b5:
	/* 0x9b5: test   r9b,r9b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R9, X86_R9, X86_WIDTH_8);
x86_l_9b8:
	/* 0x9b8: jne    15e7 <tail_ipv4_to_endpoint+0x15e7> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x9b8, 0x15e7, x86_l_15e7);
x86_l_9be:
	/* 0x9be: cmp    DWORD PTR [rsp+0x84],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_9c6:
	/* 0x9c6: jne    c00 <tail_ipv4_to_endpoint+0xc00> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x9c6, 0xc00, x86_l_c00);
x86_l_9cc:
	/* 0x9cc: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9ce:
	/* 0x9ce: test   si,si */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_16);
x86_l_9d1:
	/* 0x9d1: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_9d4:
	/* 0x9d4: shl    ecx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 4ULL);
x86_l_9d7:
	/* 0x9d7: mov    r12d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_9dc:
	/* 0x9dc: cmp    BYTE PTR [rax+0xc],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 51539607558ULL);
x86_l_9e0:
	/* 0x9e0: jne    9fa <tail_ipv4_to_endpoint+0x9fa> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x9e0, 0x9fa, x86_l_9fa);
x86_l_9e2:
	/* 0x9e2: mov    rdx,QWORD PTR [rip+0xdbc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&cilium_ct4_global)));
x86_l_9e9:
	/* 0x9e9: jmp    a01 <tail_ipv4_to_endpoint+0xa01> */
	X86_SIM_X86_JMP(0x9e9, 0xa01, x86_l_a01);
x86_l_9eb:
	/* 0x9eb: mov    cx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_16, 1ULL);
x86_l_9ef:
	/* 0x9ef: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9f1:
	/* 0x9f1: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9f4:
	/* 0x9f4: cmp    BYTE PTR [rax+0xc],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 51539607558ULL);
x86_l_9f8:
	/* 0x9f8: je     9e2 <tail_ipv4_to_endpoint+0x9e2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9f8, 0x9e2, x86_l_9e2);
x86_l_9fa:
	/* 0x9fa: mov    rdx,QWORD PTR [rip+0xdbc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&cilium_ct_any4_global)));
x86_l_a01:
	/* 0xa01: mov    QWORD PTR [rsp+0x20],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a06:
	/* 0xa06: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_a0f:
	/* 0xa0f: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_a18:
	/* 0xa18: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_a21:
	/* 0xa21: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_a2a:
	/* 0xa2a: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_a33:
	/* 0xa33: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_a3c:
	/* 0xa3c: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_a45:
	/* 0xa45: movzx  r14d,BYTE PTR [rax+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 12ULL);
x86_l_a4a:
	/* 0xa4a: mov    DWORD PTR [rsp+0x5c],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_a4f:
	/* 0xa4f: movzx  ecx,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_a52:
	/* 0xa52: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_a54:
	/* 0xa54: and    edx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 1ULL);
x86_l_a57:
	/* 0xa57: mov    WORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_a5e:
	/* 0xa5e: shl    ecx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 2ULL);
x86_l_a61:
	/* 0xa61: and    ecx,0xffffffc0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967232ULL);
x86_l_a64:
	/* 0xa64: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_a6d:
	/* 0xa6d: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_a76:
	/* 0xa76: lea    ecx,[rcx+rdx*8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 3), 0ULL);
x86_l_a79:
	/* 0xa79: mov    WORD PTR [rsp+0x54],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_a7e:
	/* 0xa7e: mov    r13,QWORD PTR [rip+0xdbc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_a85:
	/* 0xa85: cmp    BYTE PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a8a:
	/* 0xa8a: je     a9d <tail_ipv4_to_endpoint+0xa9d> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa8a, 0xa9d, x86_l_a9d);
x86_l_a8c:
	/* 0xa8c: mov    rdx,QWORD PTR [rip+0xdbc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_a93:
	/* 0xa93: imul   r12d,DWORD PTR [rdx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R12, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_a97:
	/* 0xa97: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_a9b:
	/* 0xa9b: jmp    aa3 <tail_ipv4_to_endpoint+0xaa3> */
	X86_SIM_X86_JMP(0xa9b, 0xaa3, x86_l_aa3);
x86_l_a9d:
	/* 0xa9d: mov    r12d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 60ULL);
x86_l_aa3:
	/* 0xaa3: cmp    r14b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 6ULL);
x86_l_aa7:
	/* 0xaa7: jne    acc <tail_ipv4_to_endpoint+0xacc> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xaa7, 0xacc, x86_l_acc);
x86_l_aa9:
	/* 0xaa9: mov    WORD PTR [rsp+0x54],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_aae:
	/* 0xaae: cmp    BYTE PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ab3:
	/* 0xab3: je     ac6 <tail_ipv4_to_endpoint+0xac6> */
	X86_SIM_X86_JCC(X86_CC_E, 0xab3, 0xac6, x86_l_ac6);
x86_l_ab5:
	/* 0xab5: mov    rcx,QWORD PTR [rip+0xdbc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_abc:
	/* 0xabc: imul   r12d,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_ac0:
	/* 0xac0: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_ac4:
	/* 0xac4: jmp    acc <tail_ipv4_to_endpoint+0xacc> */
	X86_SIM_X86_JMP(0xac4, 0xacc, x86_l_acc);
x86_l_ac6:
	/* 0xac6: mov    r12d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 60ULL);
x86_l_acc:
	/* 0xacc: mov    DWORD PTR [rsp+0x28],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_ad0:
	/* 0xad0: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ad5:
	/* 0xad5: cmp    BYTE PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ada:
	/* 0xada: je     aeb <tail_ipv4_to_endpoint+0xaeb> */
	X86_SIM_X86_JCC(X86_CC_E, 0xada, 0xaeb, x86_l_aeb);
x86_l_adc:
	/* 0xadc: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_ae1:
	/* 0xae1: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ae3:
	/* 0xae3: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_ae5:
	/* 0xae5: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_ae9:
	/* 0xae9: jmp    b0e <tail_ipv4_to_endpoint+0xb0e> */
	X86_SIM_X86_JMP(0xae9, 0xb0e, x86_l_b0e);
x86_l_aeb:
	/* 0xaeb: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_af0:
	/* 0xaf0: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_af2:
	/* 0xaf2: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_af4:
	/* 0xaf4: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_af8:
	/* 0xaf8: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_b02:
	/* 0xb02: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_b05:
	/* 0xb05: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_b0a:
	/* 0xb0a: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_b0e:
	/* 0xb0e: cmp    r14b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 6ULL);
x86_l_b12:
	/* 0xb12: sete   dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_E);
x86_l_b15:
	/* 0xb15: add    r12d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_b18:
	/* 0xb18: mov    DWORD PTR [rsp+0x50],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_b1d:
	/* 0xb1d: movzx  esi,BYTE PTR [rsp+0x5b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 91ULL);
x86_l_b22:
	/* 0xb22: mov    edi,DWORD PTR [rsp+0x64] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 100ULL);
x86_l_b26:
	/* 0xb26: add    dl,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_8, X86_ALU_ADD);
x86_l_b28:
	/* 0xb28: cmp    BYTE PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b2d:
	/* 0xb2d: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b32:
	/* 0xb32: je     b48 <tail_ipv4_to_endpoint+0xb48> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb32, 0xb48, x86_l_b48);
x86_l_b34:
	/* 0xb34: mov    r8,QWORD PTR [rip+0xdbc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R8, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_b3b:
	/* 0xb3b: mov    r8d,DWORD PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b3e:
	/* 0xb3e: lea    r8d,[r8+r8*4] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_R8, 2), 0ULL);
x86_l_b42:
	/* 0xb42: shr    r8d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_b46:
	/* 0xb46: jmp    b4e <tail_ipv4_to_endpoint+0xb4e> */
	X86_SIM_X86_JMP(0xb46, 0xb4e, x86_l_b4e);
x86_l_b48:
	/* 0xb48: mov    r8d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 5ULL);
x86_l_b4e:
	/* 0xb4e: movabs r13,0x2090b0100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 8741650688ULL);
x86_l_b58:
	/* 0xb58: add    r8d,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_b5b:
	/* 0xb5b: or     dl,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_8, X86_ALU_OR);
x86_l_b5e:
	/* 0xb5e: cmp    r8d,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RAX, X86_WIDTH_32);
x86_l_b61:
	/* 0xb61: jb     b68 <tail_ipv4_to_endpoint+0xb68> */
	X86_SIM_X86_JCC(X86_CC_B, 0xb61, 0xb68, x86_l_b68);
x86_l_b63:
	/* 0xb63: cmp    sil,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_8);
x86_l_b66:
	/* 0xb66: je     b79 <tail_ipv4_to_endpoint+0xb79> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb66, 0xb79, x86_l_b79);
x86_l_b68:
	/* 0xb68: mov    BYTE PTR [rsp+0x5b],dl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 91ULL);
x86_l_b6c:
	/* 0xb6c: mov    DWORD PTR [rsp+0x64],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 100ULL);
x86_l_b70:
	/* 0xb70: mov    rax,QWORD PTR [rip+0xdbc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_b77:
	/* 0xb77: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b79:
	/* 0xb79: mov    eax,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b7b:
	/* 0xb7b: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b7f:
	/* 0xb7f: mov    eax,DWORD PTR [rcx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_b82:
	/* 0xb82: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_b86:
	/* 0xb86: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_b8e:
	/* 0xb8e: mov    BYTE PTR [rsp+0x14],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 85899345921ULL);
x86_l_b93:
	/* 0xb93: movzx  eax,BYTE PTR [rcx+0xd] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 13ULL);
x86_l_b97:
	/* 0xb97: or     al,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_OR, 2ULL);
x86_l_b99:
	/* 0xb99: mov    BYTE PTR [rsp+0x15],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 21ULL);
x86_l_b9d:
	/* 0xb9d: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_ba2:
	/* 0xba2: mov    rdi,QWORD PTR [rip+0xdbc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct_any4_global)));
x86_l_ba9:
	/* 0xba9: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bae:
	/* 0xbae: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_bb3:
	/* 0xbb3: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bb5:
	/* 0xbb5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bb7:
	/* 0xbb7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_bb9:
	/* 0xbb9: js     df3 <tail_ipv4_to_endpoint+0xdf3> */
	X86_SIM_X86_JCC(X86_CC_S, 0xbb9, 0xdf3, x86_l_df3);
x86_l_bbf:
	/* 0xbbf: mov    rax,QWORD PTR [rip+0xdbc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_bc6:
	/* 0xbc6: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bc9:
	/* 0xbc9: je     bdc <tail_ipv4_to_endpoint+0xbdc> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbc9, 0xbdc, x86_l_bdc);
x86_l_bcb:
	/* 0xbcb: mov    QWORD PTR [rsp+0x40],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906945ULL);
x86_l_bd4:
	/* 0xbd4: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_bd7:
	/* 0xbd7: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_bdc:
	/* 0xbdc: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_be1:
	/* 0xbe1: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_be6:
	/* 0xbe6: mov    rdi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_beb:
	/* 0xbeb: mov    rsi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_bf0:
	/* 0xbf0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bf2:
	/* 0xbf2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bf4:
	/* 0xbf4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_bf6:
	/* 0xbf6: js     df3 <tail_ipv4_to_endpoint+0xdf3> */
	X86_SIM_X86_JCC(X86_CC_S, 0xbf6, 0xdf3, x86_l_df3);
x86_l_bfc:
	/* 0xbfc: mov    esi,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c00:
	/* 0xc00: test   si,si */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_16);
x86_l_c03:
	/* 0xc03: je     1267 <tail_ipv4_to_endpoint+0x1267> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc03, 0x1267, x86_l_1267);
x86_l_c09:
	/* 0xc09: mov    DWORD PTR [rsp+0x28],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c0d:
	/* 0xc0d: mov    rax,QWORD PTR [rip+0xdbc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_security_label)));
x86_l_c14:
	/* 0xc14: mov    r14d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c17:
	/* 0xc17: mov    rax,QWORD PTR [rip+0xdbc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_tracing_ip_option_type)));
x86_l_c1e:
	/* 0xc1e: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c21:
	/* 0xc21: mov    r12d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_c26:
	/* 0xc26: mov    DWORD PTR [rsp+0x18],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c2b:
	/* 0xc2b: je     c52 <tail_ipv4_to_endpoint+0xc52> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc2b, 0xc52, x86_l_c52);
x86_l_c2d:
	/* 0xc2d: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_c35:
	/* 0xc35: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c3a:
	/* 0xc3a: mov    rdi,QWORD PTR [rip+0xdbc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_percpu_trace_id)));
x86_l_c41:
	/* 0xc41: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c46:
	/* 0xc46: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c48:
	/* 0xc48: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c4b:
	/* 0xc4b: je     c52 <tail_ipv4_to_endpoint+0xc52> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc4b, 0xc52, x86_l_c52);
x86_l_c4d:
	/* 0xc4d: mov    r8,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c50:
	/* 0xc50: jmp    c55 <tail_ipv4_to_endpoint+0xc55> */
	X86_SIM_X86_JMP(0xc50, 0xc55, x86_l_c55);
x86_l_c52:
	/* 0xc52: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c55:
	/* 0xc55: mov    r14d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_c59:
	/* 0xc59: mov    QWORD PTR [rsp+0x90],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290626ULL);
x86_l_c65:
	/* 0xc65: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_c6e:
	/* 0xc6e: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_c77:
	/* 0xc77: cmp    DWORD PTR [rsp+0x8c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_c7f:
	/* 0xc7f: je     eea <tail_ipv4_to_endpoint+0xeea> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc7f, 0xeea, x86_l_eea);
x86_l_c85:
	/* 0xc85: mov    rax,QWORD PTR [rip+0xdbc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_events_map_rate_limit)));
x86_l_c8c:
	/* 0xc8c: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c8f:
	/* 0xc8f: mov    ecx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_32);
x86_l_c92:
	/* 0xc92: je     e2c <tail_ipv4_to_endpoint+0xe2c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc92, 0xe2c, x86_l_e2c);
x86_l_c98:
	/* 0xc98: mov    QWORD PTR [rsp+0x20],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c9d:
	/* 0xc9d: mov    rcx,QWORD PTR [rip+0xdbc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_events_map_burst_limit)));
x86_l_ca4:
	/* 0xca4: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ca6:
	/* 0xca6: mov    QWORD PTR [rsp+0xa8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_cae:
	/* 0xcae: mov    r13d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cb1:
	/* 0xcb1: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_cb6:
	/* 0xcb6: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_cb8:
	/* 0xcb8: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_cba:
	/* 0xcba: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_cbd:
	/* 0xcbd: mov    DWORD PTR [rsp+0x88],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 584115552258ULL);
x86_l_cc8:
	/* 0xcc8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ccd:
	/* 0xccd: mov    rdi,QWORD PTR [rip+0xdbc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit_metrics)));
x86_l_cd4:
	/* 0xcd4: lea    rsi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_cdc:
	/* 0xcdc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cde:
	/* 0xcde: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_ce3:
	/* 0xce3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ce6:
	/* 0xce6: jne    d1b <tail_ipv4_to_endpoint+0xd1b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xce6, 0xd1b, x86_l_d1b);
x86_l_ce8:
	/* 0xce8: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_cf1:
	/* 0xcf1: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_cf6:
	/* 0xcf6: mov    rdi,QWORD PTR [rip+0xdbc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit_metrics)));
x86_l_cfd:
	/* 0xcfd: lea    rsi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_d05:
	/* 0xd05: lea    rdx,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_d0a:
	/* 0xd0a: mov    QWORD PTR [rsp+0x68],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_d0f:
	/* 0xd0f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d11:
	/* 0xd11: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d13:
	/* 0xd13: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_d15:
	/* 0xd15: js     fdf <tail_ipv4_to_endpoint+0xfdf> */
	X86_SIM_X86_JCC(X86_CC_S, 0xd15, 0xfdf, x86_l_fdf);
x86_l_d1b:
	/* 0xd1b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d20:
	/* 0xd20: mov    rdi,QWORD PTR [rip+0xdbc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit)));
x86_l_d27:
	/* 0xd27: lea    rsi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_d2f:
	/* 0xd2f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d31:
	/* 0xd31: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d34:
	/* 0xd34: je     dac <tail_ipv4_to_endpoint+0xdac> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd34, 0xdac, x86_l_dac);
x86_l_d36:
	/* 0xd36: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d39:
	/* 0xd39: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_d3c:
	/* 0xd3c: sub    rsi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_d3f:
	/* 0xd3f: cmp    rsi,0x3b9aca00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 1000000000ULL);
x86_l_d46:
	/* 0xd46: jbe    e01 <tail_ipv4_to_endpoint+0xe01> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xd46, 0xe01, x86_l_e01);
x86_l_d4c:
	/* 0xd4c: mov    rdx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_d4f:
	/* 0xd4f: shr    rdx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_d53:
	/* 0xd53: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_d5d:
	/* 0xd5d: mulx   rcx,rcx,rcx */
	X86_SIM_L_EXEC_MULX(X86_RCX, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_d62:
	/* 0xd62: shr    rcx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_d66:
	/* 0xd66: imul   rdx,rcx,0x3b9aca00 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RDX, X86_RCX, X86_WIDTH_64, 1000000000ULL);
x86_l_d6d:
	/* 0xd6d: imul   rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_IMUL);
x86_l_d71:
	/* 0xd71: add    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_d75:
	/* 0xd75: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d79:
	/* 0xd79: sub    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_d7c:
	/* 0xd7c: add    r12,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_d7f:
	/* 0xd7f: mov    QWORD PTR [rax],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d82:
	/* 0xd82: mov    rdx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_d8a:
	/* 0xd8a: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_d8d:
	/* 0xd8d: movabs r13,0x2090b0100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 8741650688ULL);
x86_l_d97:
	/* 0xd97: mov    r12d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_d9c:
	/* 0xd9c: mov    r8,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_da1:
	/* 0xda1: jbe    e19 <tail_ipv4_to_endpoint+0xe19> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xda1, 0xe19, x86_l_e19);
x86_l_da3:
	/* 0xda3: mov    QWORD PTR [rax+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_da7:
	/* 0xda7: mov    rcx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_daa:
	/* 0xdaa: jmp    e19 <tail_ipv4_to_endpoint+0xe19> */
	X86_SIM_X86_JMP(0xdaa, 0xe19, x86_l_e19);
x86_l_dac:
	/* 0xdac: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_db1:
	/* 0xdb1: dec    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_db4:
	/* 0xdb4: mov    QWORD PTR [rsp+0x10],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_db9:
	/* 0xdb9: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_dbe:
	/* 0xdbe: mov    rdi,QWORD PTR [rip+0xdbc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit)));
x86_l_dc5:
	/* 0xdc5: lea    rsi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_dcd:
	/* 0xdcd: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_dd2:
	/* 0xdd2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_dd4:
	/* 0xdd4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dd6:
	/* 0xdd6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_dd8:
	/* 0xdd8: movabs r13,0x2090b0100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 8741650688ULL);
x86_l_de2:
	/* 0xde2: mov    r12d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_de7:
	/* 0xde7: mov    r8,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_dec:
	/* 0xdec: jns    e29 <tail_ipv4_to_endpoint+0xe29> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xdec, 0xe29, x86_l_e29);
x86_l_dee:
	/* 0xdee: jmp    fd7 <tail_ipv4_to_endpoint+0xfd7> */
	X86_SIM_X86_JMP(0xdee, 0xfd7, x86_l_fd7);
x86_l_df3:
	/* 0xdf3: mov    r15d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_32);
x86_l_df6:
	/* 0xdf6: mov    r12d,0xffffff65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967141ULL);
x86_l_dfc:
	/* 0xdfc: jmp    15e7 <tail_ipv4_to_endpoint+0x15e7> */
	X86_SIM_X86_JMP(0xdfc, 0x15e7, x86_l_15e7);
x86_l_e01:
	/* 0xe01: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e05:
	/* 0xe05: movabs r13,0x2090b0100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 8741650688ULL);
x86_l_e0f:
	/* 0xe0f: mov    r12d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_e14:
	/* 0xe14: mov    r8,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e19:
	/* 0xe19: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_e1c:
	/* 0xe1c: je     fd7 <tail_ipv4_to_endpoint+0xfd7> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe1c, 0xfd7, x86_l_fd7);
x86_l_e22:
	/* 0xe22: dec    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_e25:
	/* 0xe25: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e29:
	/* 0xe29: mov    ecx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_e2c:
	/* 0xe2c: mov    eax,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_e30:
	/* 0xe30: mov    edx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_e32:
	/* 0xe32: rol    dx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_e36:
	/* 0xe36: mov    rsi,QWORD PTR [rip+0xdbc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_e3d:
	/* 0xe3d: mov    eax,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e3f:
	/* 0xe3f: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e41:
	/* 0xe41: mov    edi,DWORD PTR [rsp+0x8c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_e48:
	/* 0xe48: cmp    esi,edi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDI, X86_WIDTH_32);
x86_l_e4a:
	/* 0xe4a: cmovne eax,edi */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RDI, X86_WIDTH_32, X86_CC_NE);
x86_l_e4d:
	/* 0xe4d: cmp    eax,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_e4f:
	/* 0xe4f: mov    rsi,QWORD PTR [rip+0xdbc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_endpoint_id)));
x86_l_e56:
	/* 0xe56: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_e59:
	/* 0xe59: cmovae eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_AE);
x86_l_e5c:
	/* 0xe5c: mov    ecx,DWORD PTR [rbx+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_e62:
	/* 0xe62: mov    WORD PTR [rsp+0x30],0x104 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 206158430468ULL);
x86_l_e69:
	/* 0xe69: mov    WORD PTR [rsp+0x32],si */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 50ULL);
x86_l_e6e:
	/* 0xe6e: mov    DWORD PTR [rsp+0x34],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_e72:
	/* 0xe72: mov    DWORD PTR [rsp+0x38],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_e77:
	/* 0xe77: mov    WORD PTR [rsp+0x3c],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_e7c:
	/* 0xe7c: mov    WORD PTR [rsp+0x3e],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 266287972354ULL);
x86_l_e83:
	/* 0xe83: mov    DWORD PTR [rsp+0x40],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_e88:
	/* 0xe88: mov    ecx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_e8c:
	/* 0xe8c: mov    DWORD PTR [rsp+0x44],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_e90:
	/* 0xe90: mov    WORD PTR [rsp+0x48],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_e95:
	/* 0xe95: mov    ecx,DWORD PTR [rsp+0x84] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_e9c:
	/* 0xe9c: mov    BYTE PTR [rsp+0x4a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 74ULL);
x86_l_ea0:
	/* 0xea0: mov    BYTE PTR [rsp+0x4b],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 322122547200ULL);
x86_l_ea5:
	/* 0xea5: mov    ecx,DWORD PTR [rsp+0xb4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 180ULL);
x86_l_eac:
	/* 0xeac: mov    DWORD PTR [rsp+0x4c],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_eb0:
	/* 0xeb0: mov    ecx,DWORD PTR [rsp+0x9c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_eb7:
	/* 0xeb7: mov    DWORD PTR [rsp+0x50],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_ebb:
	/* 0xebb: mov    QWORD PTR [rsp+0x60],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_ec0:
	/* 0xec0: mov    r9d,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 25ULL);
x86_l_ec6:
	/* 0xec6: shl    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_eca:
	/* 0xeca: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_ecf:
	/* 0xecf: or     rdx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_ed2:
	/* 0xed2: mov    rsi,QWORD PTR [rip+0xdbc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_events)));
x86_l_ed9:
	/* 0xed9: lea    rcx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ede:
	/* 0xede: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_ee1:
	/* 0xee1: mov    r8d,0x38 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 56ULL);
x86_l_ee7:
	/* 0xee7: call   r9 */
	X86_SIM_BPF_CALL_REG(X86_R9);
x86_l_eea:
	/* 0xeea: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_eed:
	/* 0xeed: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_eef:
	/* 0xeef: sub    ecx,DWORD PTR [rbx+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_ef2:
	/* 0xef2: cmp    ecx,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 34ULL);
x86_l_ef5:
	/* 0xef5: jb     3e <tail_ipv4_to_endpoint+0x3e> */
	X86_SIM_X86_JCC(X86_CC_B, 0xef5, 0x3e, x86_l_3e);
x86_l_efb:
	/* 0xefb: mov    rax,QWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_f02:
	/* 0xf02: mov    rcx,QWORD PTR [rip+0xdbc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_cilium_host_mac)));
x86_l_f09:
	/* 0xf09: mov    rcx,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f0c:
	/* 0xf0c: mov    QWORD PTR [rsp+0x30],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f11:
	/* 0xf11: mov    rcx,QWORD PTR [rip+0xdbc0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_interface_mac)));
x86_l_f18:
	/* 0xf18: mov    rcx,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f1b:
	/* 0xf1b: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f20:
	/* 0xf20: mov    ecx,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_f24:
	/* 0xf24: shl    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_f27:
	/* 0xf27: or     ecx,0x200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_OR, 512ULL);
x86_l_f2d:
	/* 0xf2d: mov    DWORD PTR [rbx+0x28],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_f30:
	/* 0xf30: movzx  edx,BYTE PTR [rax+0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 22ULL);
x86_l_f34:
	/* 0xf34: mov    ebp,0xffffff3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967100ULL);
x86_l_f39:
	/* 0xf39: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_f3c:
	/* 0xf3c: jb     fc1 <tail_ipv4_to_endpoint+0xfc1> */
	X86_SIM_X86_JCC(X86_CC_B, 0xf3c, 0xfc1, x86_l_fc1);
x86_l_f42:
	/* 0xf42: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_f45:
	/* 0xf45: mov    BYTE PTR [rax+0x16],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_f48:
	/* 0xf48: movzx  ecx,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_f4b:
	/* 0xf4b: mov    eax,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_f50:
	/* 0xf50: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_f53:
	/* 0xf53: mov    esi,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 24ULL);
x86_l_f58:
	/* 0xf58: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_f5e:
	/* 0xf5e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f60:
	/* 0xf60: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_f62:
	/* 0xf62: js     fbc <tail_ipv4_to_endpoint+0xfbc> */
	X86_SIM_X86_JCC(X86_CC_S, 0xf62, 0xfbc, x86_l_fbc);
x86_l_f64:
	/* 0xf64: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_f69:
	/* 0xf69: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f6e:
	/* 0xf6e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_f71:
	/* 0xf71: mov    esi,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 6ULL);
x86_l_f76:
	/* 0xf76: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_f7b:
	/* 0xf7b: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f7e:
	/* 0xf7e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f80:
	/* 0xf80: mov    ebp,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967155ULL);
x86_l_f85:
	/* 0xf85: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_f87:
	/* 0xf87: js     fc1 <tail_ipv4_to_endpoint+0xfc1> */
	X86_SIM_X86_JCC(X86_CC_S, 0xf87, 0xfc1, x86_l_fc1);
x86_l_f89:
	/* 0xf89: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_f8e:
	/* 0xf8e: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f93:
	/* 0xf93: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_f96:
	/* 0xf96: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f98:
	/* 0xf98: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_f9d:
	/* 0xf9d: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_fa0:
	/* 0xfa0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fa2:
	/* 0xfa2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_fa4:
	/* 0xfa4: js     fc1 <tail_ipv4_to_endpoint+0xfc1> */
	X86_SIM_X86_JCC(X86_CC_S, 0xfa4, 0xfc1, x86_l_fc1);
x86_l_fa6:
	/* 0xfa6: mov    rax,QWORD PTR [rip+0xdbbc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_cilium_net_ifindex)));
x86_l_fad:
	/* 0xfad: mov    edi,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_faf:
	/* 0xfaf: mov    eax,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 23ULL);
x86_l_fb4:
	/* 0xfb4: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_fb6:
	/* 0xfb6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fb8:
	/* 0xfb8: mov    ebp,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_fba:
	/* 0xfba: jmp    fc1 <tail_ipv4_to_endpoint+0xfc1> */
	X86_SIM_X86_JMP(0xfba, 0xfc1, x86_l_fc1);
x86_l_fbc:
	/* 0xfbc: mov    ebp,0xffffff67 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967143ULL);
x86_l_fc1:
	/* 0xfc1: mov    eax,DWORD PTR [rbx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_fc4:
	/* 0xfc4: mov    DWORD PTR [rbx+0xa8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_fca:
	/* 0xfca: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_fcc:
	/* 0xfcc: jns    15f7 <tail_ipv4_to_endpoint+0x15f7> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xfcc, 0x15f7, x86_l_15f7);
x86_l_fd2:
	/* 0xfd2: jmp    1af4 <tail_ipv4_to_endpoint+0x1af4> */
	X86_SIM_X86_JMP(0xfd2, 0x1af4, x86_l_1af4);
x86_l_fd7:
	/* 0xfd7: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_fdc:
	/* 0xfdc: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_fdf:
	/* 0xfdf: movabs r13,0x2090b0100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 8741650688ULL);
x86_l_fe9:
	/* 0xfe9: mov    r12d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_fee:
	/* 0xfee: jmp    eea <tail_ipv4_to_endpoint+0xeea> */
	X86_SIM_X86_JMP(0xfee, 0xeea, x86_l_eea);
x86_l_ff3:
	/* 0xff3: mov    rax,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_ffb:
	/* 0xffb: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_ffe:
	/* 0xffe: jmp    999 <tail_ipv4_to_endpoint+0x999> */
	X86_SIM_X86_JMP(0xffe, 0x999, x86_l_999);
x86_l_1003:
	/* 0x1003: mov    QWORD PTR [rsp+0x20],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1008:
	/* 0x1008: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_100d:
	/* 0x100d: test   r12b,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R12, X86_WIDTH_8, 1ULL);
x86_l_1011:
	/* 0x1011: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_1014:
	/* 0x1014: test   cx,cx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_16);
x86_l_1017:
	/* 0x1017: je     1137 <tail_ipv4_to_endpoint+0x1137> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1017, 0x1137, x86_l_1137);
x86_l_101d:
	/* 0x101d: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1022:
	/* 0x1022: mov    edx,DWORD PTR [rdx+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1025:
	/* 0x1025: jmp    103b <tail_ipv4_to_endpoint+0x103b> */
	X86_SIM_X86_JMP(0x1025, 0x103b, x86_l_103b);
x86_l_1027:
	/* 0x1027: mov    QWORD PTR [rsp+0x20],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_102c:
	/* 0x102c: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1031:
	/* 0x1031: mov    edx,DWORD PTR [rax+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1034:
	/* 0x1034: test   r12b,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R12, X86_WIDTH_8, 1ULL);
x86_l_1038:
	/* 0x1038: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_103b:
	/* 0x103b: lea    rsi,[rsp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1040:
	/* 0x1040: mov    QWORD PTR [rsp+0x28],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1045:
	/* 0x1045: mov    DWORD PTR [rsp+0x30],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1049:
	/* 0x1049: mov    WORD PTR [rsp+0x34],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_104e:
	/* 0x104e: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1053:
	/* 0x1053: mov    esi,DWORD PTR [rcx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1056:
	/* 0x1056: mov    DWORD PTR [rsp+0x8],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_105a:
	/* 0x105a: mov    rsi,QWORD PTR [rip+0xdbbc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_1061:
	/* 0x1061: movzx  esi,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1064:
	/* 0x1064: mov    DWORD PTR [rcx+0x4],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1067:
	/* 0x1067: lea    r14,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_106c:
	/* 0x106c: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_106e:
	/* 0x106e: je     1191 <tail_ipv4_to_endpoint+0x1191> */
	X86_SIM_X86_JCC(X86_CC_E, 0x106e, 0x1191, x86_l_1191);
x86_l_1074:
	/* 0x1074: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1077:
	/* 0x1077: jmp    11ec <tail_ipv4_to_endpoint+0x11ec> */
	X86_SIM_X86_JMP(0x1077, 0x11ec, x86_l_11ec);
x86_l_107c:
	/* 0x107c: mov    DWORD PTR [rsp+0x74],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 498216206336ULL);
x86_l_1084:
	/* 0x1084: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1089:
	/* 0x1089: mov    rdi,QWORD PTR [rip+0xdbbc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_policy_v2)));
x86_l_1090:
	/* 0x1090: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1095:
	/* 0x1095: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1097:
	/* 0x1097: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_109c:
	/* 0x109c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_109f:
	/* 0x109f: je     1647 <tail_ipv4_to_endpoint+0x1647> */
	X86_SIM_X86_JCC(X86_CC_E, 0x109f, 0x1647, x86_l_1647);
x86_l_10a5:
	/* 0x10a5: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_10a8:
	/* 0x10a8: je     10bd <tail_ipv4_to_endpoint+0x10bd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10a8, 0x10bd, x86_l_10bd);
x86_l_10aa:
	/* 0x10aa: mov    eax,DWORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_10af:
	/* 0x10af: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_10b4:
	/* 0x10b4: cmp    DWORD PTR [rcx+0x4],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_10b7:
	/* 0x10b7: jbe    166e <tail_ipv4_to_endpoint+0x166e> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x10b7, 0x166e, x86_l_166e);
x86_l_10bd:
	/* 0x10bd: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_10c2:
	/* 0x10c2: movzx  r14d,WORD PTR [rax+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_10c7:
	/* 0x10c7: mov    rax,QWORD PTR [rip+0xdbbc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_policy_accounting)));
x86_l_10ce:
	/* 0x10ce: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10d1:
	/* 0x10d1: mov    eax,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_32);
x86_l_10d4:
	/* 0x10d4: je     1838 <tail_ipv4_to_endpoint+0x1838> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10d4, 0x1838, x86_l_1838);
x86_l_10da:
	/* 0x10da: mov    eax,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_32);
x86_l_10dd:
	/* 0x10dd: shr    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHR, 3ULL);
x86_l_10e0:
	/* 0x10e0: movzx  ecx,BYTE PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 120ULL);
x86_l_10e5:
	/* 0x10e5: mov    r13d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_10e9:
	/* 0x10e9: mov    rdx,QWORD PTR [rip+0xdbbc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_endpoint_id)));
x86_l_10f0:
	/* 0x10f0: movzx  edx,WORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_10f3:
	/* 0x10f3: mov    WORD PTR [rsp+0x8],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10f8:
	/* 0x10f8: mov    BYTE PTR [rsp+0xa],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42949672960ULL);
x86_l_10fd:
	/* 0x10fd: mov    BYTE PTR [rsp+0xb],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 11ULL);
x86_l_1101:
	/* 0x1101: and    cl,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 1ULL);
x86_l_1104:
	/* 0x1104: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_110c:
	/* 0x110c: mov    BYTE PTR [rsp+0x10],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1110:
	/* 0x1110: cmp    r14b,0x47 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 71ULL);
x86_l_1114:
	/* 0x1114: ja     16b5 <tail_ipv4_to_endpoint+0x16b5> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1114, 0x16b5, x86_l_16b5);
x86_l_111a:
	/* 0x111a: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_111d:
	/* 0x111d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_111f:
	/* 0x111f: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_1122:
	/* 0x1122: movzx  r15d,r15b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1126:
	/* 0x1126: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_112e:
	/* 0x112e: cmovne r15d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R15, X86_RCX, X86_WIDTH_32, X86_CC_NE);
x86_l_1132:
	/* 0x1132: jmp    16d1 <tail_ipv4_to_endpoint+0x16d1> */
	X86_SIM_X86_JMP(0x1132, 0x16d1, x86_l_16d1);
x86_l_1137:
	/* 0x1137: mov    WORD PTR [rsp+0x8],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_113c:
	/* 0x113c: mov    rbp,QWORD PTR [rip+0xdbbc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBP, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_1143:
	/* 0x1143: movzx  eax,BYTE PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1147:
	/* 0x1147: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_114c:
	/* 0x114c: mov    rdi,QWORD PTR [rip+0xdbbc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_reverse_nat)));
x86_l_1153:
	/* 0x1153: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1158:
	/* 0x1158: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_115a:
	/* 0x115a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_115d:
	/* 0x115d: je     125a <tail_ipv4_to_endpoint+0x125a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x115d, 0x125a, x86_l_125a);
x86_l_1163:
	/* 0x1163: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_1166:
	/* 0x1166: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1169:
	/* 0x1169: add    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_116d:
	/* 0x116d: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1172:
	/* 0x1172: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1177:
	/* 0x1177: mov    ecx,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_117a:
	/* 0x117a: mov    DWORD PTR [rsp+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_117e:
	/* 0x117e: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1181:
	/* 0x1181: movzx  ecx,BYTE PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1185:
	/* 0x1185: mov    ecx,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1188:
	/* 0x1188: mov    DWORD PTR [rax+0x4],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_118b:
	/* 0x118b: test   r12b,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R12, X86_WIDTH_8, 1ULL);
x86_l_118f:
	/* 0x118f: je     11ec <tail_ipv4_to_endpoint+0x11ec> */
	X86_SIM_X86_JCC(X86_CC_E, 0x118f, 0x11ec, x86_l_11ec);
x86_l_1191:
	/* 0x1191: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1196:
	/* 0x1196: mov    r13d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1199:
	/* 0x1199: mov    rax,QWORD PTR [rip+0xdbbc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_11a0:
	/* 0x11a0: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_11a3:
	/* 0x11a3: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_11a8:
	/* 0x11a8: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11ad:
	/* 0x11ad: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_11b0:
	/* 0x11b0: mov    esi,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 30ULL);
x86_l_11b5:
	/* 0x11b5: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_11ba:
	/* 0x11ba: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11bd:
	/* 0x11bd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11bf:
	/* 0x11bf: mov    r12d,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967155ULL);
x86_l_11c5:
	/* 0x11c5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_11c7:
	/* 0x11c7: js     15da <tail_ipv4_to_endpoint+0x15da> */
	X86_SIM_X86_JCC(X86_CC_S, 0x11c7, 0x15da, x86_l_15da);
x86_l_11cd:
	/* 0x11cd: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_11d0:
	/* 0x11d0: je     15da <tail_ipv4_to_endpoint+0x15da> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11d0, 0x15da, x86_l_15da);
x86_l_11d6:
	/* 0x11d6: not    r13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_11d9:
	/* 0x11d9: mov    ecx,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11dd:
	/* 0x11dd: add    r13d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_11e0:
	/* 0x11e0: adc    r13d,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_11e4:
	/* 0x11e4: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_11e9:
	/* 0x11e9: mov    DWORD PTR [rax+0x4],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_11ec:
	/* 0x11ec: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_11f1:
	/* 0x11f1: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_11f4:
	/* 0x11f4: mov    esi,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 26ULL);
x86_l_11f9:
	/* 0x11f9: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_11fc:
	/* 0x11fc: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1201:
	/* 0x1201: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1204:
	/* 0x1204: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1206:
	/* 0x1206: mov    r12d,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967155ULL);
x86_l_120c:
	/* 0x120c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_120e:
	/* 0x120e: js     15da <tail_ipv4_to_endpoint+0x15da> */
	X86_SIM_X86_JCC(X86_CC_S, 0x120e, 0x15da, x86_l_15da);
x86_l_1214:
	/* 0x1214: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1217:
	/* 0x1217: je     15da <tail_ipv4_to_endpoint+0x15da> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1217, 0x15da, x86_l_15da);
x86_l_121d:
	/* 0x121d: mov    ebp,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1221:
	/* 0x1221: not    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1223:
	/* 0x1223: add    ebp,DWORD PTR [r14] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_R14, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1226:
	/* 0x1226: adc    ebp,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_1229:
	/* 0x1229: add    ebp,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_122c:
	/* 0x122c: adc    ebp,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_122f:
	/* 0x122f: mov    eax,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_1234:
	/* 0x1234: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1237:
	/* 0x1237: mov    esi,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 24ULL);
x86_l_123c:
	/* 0x123c: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_123e:
	/* 0x123e: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_1240:
	/* 0x1240: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1243:
	/* 0x1243: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1245:
	/* 0x1245: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1247:
	/* 0x1247: js     15d4 <tail_ipv4_to_endpoint+0x15d4> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1247, 0x15d4, x86_l_15d4);
x86_l_124d:
	/* 0x124d: test   r15d,0xff1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R15, X86_WIDTH_32, 65311ULL);
x86_l_1254:
	/* 0x1254: je     1618 <tail_ipv4_to_endpoint+0x1618> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1254, 0x1618, x86_l_1618);
x86_l_125a:
	/* 0x125a: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_125d:
	/* 0x125d: movabs r13,0x2090b0100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 8741650688ULL);
x86_l_1267:
	/* 0x1267: mov    rax,QWORD PTR [rip+0xdbbc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_security_label)));
x86_l_126e:
	/* 0x126e: mov    r14d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1271:
	/* 0x1271: mov    rax,QWORD PTR [rip+0xdbbc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_endpoint_id)));
x86_l_1278:
	/* 0x1278: movzx  eax,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_127b:
	/* 0x127b: mov    WORD PTR [rsp+0x28],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1280:
	/* 0x1280: mov    rax,QWORD PTR [rip+0xdbbc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_tracing_ip_option_type)));
x86_l_1287:
	/* 0x1287: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_128a:
	/* 0x128a: mov    r12d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_128f:
	/* 0x128f: je     12b6 <tail_ipv4_to_endpoint+0x12b6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x128f, 0x12b6, x86_l_12b6);
x86_l_1291:
	/* 0x1291: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1299:
	/* 0x1299: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_129e:
	/* 0x129e: mov    rdi,QWORD PTR [rip+0xdbbc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_percpu_trace_id)));
x86_l_12a5:
	/* 0x12a5: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_12aa:
	/* 0x12aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12ac:
	/* 0x12ac: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_12af:
	/* 0x12af: je     12b6 <tail_ipv4_to_endpoint+0x12b6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12af, 0x12b6, x86_l_12b6);
x86_l_12b1:
	/* 0x12b1: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12b4:
	/* 0x12b4: jmp    12b8 <tail_ipv4_to_endpoint+0x12b8> */
	X86_SIM_X86_JMP(0x12b4, 0x12b8, x86_l_12b8);
x86_l_12b6:
	/* 0x12b6: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12b8:
	/* 0x12b8: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_12bd:
	/* 0x12bd: mov    ebp,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_12c0:
	/* 0x12c0: mov    QWORD PTR [rsp+0x90],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290626ULL);
x86_l_12cc:
	/* 0x12cc: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_12d5:
	/* 0x12d5: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_12de:
	/* 0x12de: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_12e7:
	/* 0x12e7: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_12f0:
	/* 0x12f0: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_12f9:
	/* 0x12f9: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1302:
	/* 0x1302: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_130b:
	/* 0x130b: mov    QWORD PTR [rsp+0x70],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1310:
	/* 0x1310: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1315:
	/* 0x1315: mov    rdi,QWORD PTR [rip+0xdbbc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_131c:
	/* 0x131c: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1321:
	/* 0x1321: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1323:
	/* 0x1323: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1326:
	/* 0x1326: je     133e <tail_ipv4_to_endpoint+0x133e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1326, 0x133e, x86_l_133e);
x86_l_1328:
	/* 0x1328: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_132b:
	/* 0x132b: add    QWORD PTR [rax+0x8],rbp */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_132f:
	/* 0x132f: cmp    DWORD PTR [rsp+0x8c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_1337:
	/* 0x1337: jne    1374 <tail_ipv4_to_endpoint+0x1374> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1337, 0x1374, x86_l_1374);
x86_l_1339:
	/* 0x1339: jmp    15b8 <tail_ipv4_to_endpoint+0x15b8> */
	X86_SIM_X86_JMP(0x1339, 0x15b8, x86_l_15b8);
x86_l_133e:
	/* 0x133e: mov    QWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_1347:
	/* 0x1347: mov    QWORD PTR [rsp+0x10],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_134c:
	/* 0x134c: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1351:
	/* 0x1351: mov    rdi,QWORD PTR [rip+0xdbbc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1358:
	/* 0x1358: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_135d:
	/* 0x135d: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1362:
	/* 0x1362: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1364:
	/* 0x1364: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1366:
	/* 0x1366: cmp    DWORD PTR [rsp+0x8c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_136e:
	/* 0x136e: je     15b8 <tail_ipv4_to_endpoint+0x15b8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x136e, 0x15b8, x86_l_15b8);
x86_l_1374:
	/* 0x1374: mov    rax,QWORD PTR [rip+0xdbbc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_events_map_rate_limit)));
x86_l_137b:
	/* 0x137b: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_137e:
	/* 0x137e: je     14fb <tail_ipv4_to_endpoint+0x14fb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x137e, 0x14fb, x86_l_14fb);
x86_l_1384:
	/* 0x1384: mov    DWORD PTR [rsp+0x20],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1389:
	/* 0x1389: mov    rcx,QWORD PTR [rip+0xdbbc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_events_map_burst_limit)));
x86_l_1390:
	/* 0x1390: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1392:
	/* 0x1392: mov    QWORD PTR [rsp+0x68],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1397:
	/* 0x1397: mov    r13d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_139a:
	/* 0x139a: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_139f:
	/* 0x139f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13a1:
	/* 0x13a1: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_13a3:
	/* 0x13a3: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_13a6:
	/* 0x13a6: mov    DWORD PTR [rsp+0x88],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 584115552258ULL);
x86_l_13b1:
	/* 0x13b1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13b6:
	/* 0x13b6: mov    rdi,QWORD PTR [rip+0xdbbc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit_metrics)));
x86_l_13bd:
	/* 0x13bd: lea    rsi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_13c5:
	/* 0x13c5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13c7:
	/* 0x13c7: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_13ca:
	/* 0x13ca: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13cd:
	/* 0x13cd: jne    1400 <tail_ipv4_to_endpoint+0x1400> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x13cd, 0x1400, x86_l_1400);
x86_l_13cf:
	/* 0x13cf: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_13d8:
	/* 0x13d8: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_13dd:
	/* 0x13dd: mov    rdi,QWORD PTR [rip+0xdbbc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit_metrics)));
x86_l_13e4:
	/* 0x13e4: lea    rsi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_13ec:
	/* 0x13ec: lea    r14,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_13f1:
	/* 0x13f1: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_13f4:
	/* 0x13f4: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13f6:
	/* 0x13f6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13f8:
	/* 0x13f8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_13fa:
	/* 0x13fa: js     15c8 <tail_ipv4_to_endpoint+0x15c8> */
	X86_SIM_X86_JCC(X86_CC_S, 0x13fa, 0x15c8, x86_l_15c8);
x86_l_1400:
	/* 0x1400: mov    QWORD PTR [rsp+0xa8],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1408:
	/* 0x1408: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_140d:
	/* 0x140d: mov    rdi,QWORD PTR [rip+0xdbbc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit)));
x86_l_1414:
	/* 0x1414: lea    rsi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_141c:
	/* 0x141c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_141e:
	/* 0x141e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1421:
	/* 0x1421: je     1491 <tail_ipv4_to_endpoint+0x1491> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1421, 0x1491, x86_l_1491);
x86_l_1423:
	/* 0x1423: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1426:
	/* 0x1426: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_1429:
	/* 0x1429: sub    rsi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_142c:
	/* 0x142c: cmp    rsi,0x3b9aca00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 1000000000ULL);
x86_l_1433:
	/* 0x1433: jbe    14d3 <tail_ipv4_to_endpoint+0x14d3> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x1433, 0x14d3, x86_l_14d3);
x86_l_1439:
	/* 0x1439: mov    rdx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_143c:
	/* 0x143c: shr    rdx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1440:
	/* 0x1440: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_144a:
	/* 0x144a: mulx   rcx,rcx,rcx */
	X86_SIM_L_EXEC_MULX(X86_RCX, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_144f:
	/* 0x144f: shr    rcx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_1453:
	/* 0x1453: imul   rdx,rcx,0x3b9aca00 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RDX, X86_RCX, X86_WIDTH_64, 1000000000ULL);
x86_l_145a:
	/* 0x145a: imul   rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_IMUL);
x86_l_145e:
	/* 0x145e: add    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1462:
	/* 0x1462: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1466:
	/* 0x1466: sub    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1469:
	/* 0x1469: add    r12,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_146c:
	/* 0x146c: mov    QWORD PTR [rax],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_146f:
	/* 0x146f: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1474:
	/* 0x1474: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1477:
	/* 0x1477: movabs r13,0x2090b0100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 8741650688ULL);
x86_l_1481:
	/* 0x1481: mov    r12d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1486:
	/* 0x1486: jbe    14e6 <tail_ipv4_to_endpoint+0x14e6> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x1486, 0x14e6, x86_l_14e6);
x86_l_1488:
	/* 0x1488: mov    QWORD PTR [rax+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_148c:
	/* 0x148c: mov    rcx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_148f:
	/* 0x148f: jmp    14e6 <tail_ipv4_to_endpoint+0x14e6> */
	X86_SIM_X86_JMP(0x148f, 0x14e6, x86_l_14e6);
x86_l_1491:
	/* 0x1491: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1496:
	/* 0x1496: dec    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_1499:
	/* 0x1499: mov    QWORD PTR [rsp+0x10],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_149e:
	/* 0x149e: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_14a3:
	/* 0x14a3: mov    rdi,QWORD PTR [rip+0xdbbc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit)));
x86_l_14aa:
	/* 0x14aa: lea    rsi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_14b2:
	/* 0x14b2: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14b7:
	/* 0x14b7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14b9:
	/* 0x14b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14bb:
	/* 0x14bb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_14bd:
	/* 0x14bd: movabs r13,0x2090b0100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 8741650688ULL);
x86_l_14c7:
	/* 0x14c7: mov    r12d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_14cc:
	/* 0x14cc: jns    14f6 <tail_ipv4_to_endpoint+0x14f6> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x14cc, 0x14f6, x86_l_14f6);
x86_l_14ce:
	/* 0x14ce: jmp    15bd <tail_ipv4_to_endpoint+0x15bd> */
	X86_SIM_X86_JMP(0x14ce, 0x15bd, x86_l_15bd);
x86_l_14d3:
	/* 0x14d3: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14d7:
	/* 0x14d7: movabs r13,0x2090b0100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 8741650688ULL);
x86_l_14e1:
	/* 0x14e1: mov    r12d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_14e6:
	/* 0x14e6: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_14e9:
	/* 0x14e9: je     15bd <tail_ipv4_to_endpoint+0x15bd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14e9, 0x15bd, x86_l_15bd);
x86_l_14ef:
	/* 0x14ef: dec    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_14f2:
	/* 0x14f2: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14f6:
	/* 0x14f6: mov    r14d,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_14fb:
	/* 0x14fb: mov    rcx,QWORD PTR [rip+0xdbbc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_1502:
	/* 0x1502: mov    eax,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1504:
	/* 0x1504: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1506:
	/* 0x1506: mov    edx,DWORD PTR [rsp+0x8c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_150d:
	/* 0x150d: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_150f:
	/* 0x150f: cmovne eax,edx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RDX, X86_WIDTH_32, X86_CC_NE);
x86_l_1512:
	/* 0x1512: mov    ecx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1515:
	/* 0x1515: cmp    eax,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_1517:
	/* 0x1517: mov    rdx,QWORD PTR [rip+0xdbbc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_endpoint_id)));
x86_l_151e:
	/* 0x151e: movzx  edx,WORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1521:
	/* 0x1521: cmovae eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_AE);
x86_l_1524:
	/* 0x1524: mov    ecx,DWORD PTR [rbx+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_152a:
	/* 0x152a: mov    WORD PTR [rsp+0x30],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 206158430212ULL);
x86_l_1531:
	/* 0x1531: mov    WORD PTR [rsp+0x32],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 50ULL);
x86_l_1536:
	/* 0x1536: mov    DWORD PTR [rsp+0x34],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_153a:
	/* 0x153a: mov    DWORD PTR [rsp+0x38],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_153e:
	/* 0x153e: mov    WORD PTR [rsp+0x3c],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_1543:
	/* 0x1543: mov    WORD PTR [rsp+0x3e],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 266287972354ULL);
x86_l_154a:
	/* 0x154a: mov    DWORD PTR [rsp+0x40],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_154f:
	/* 0x154f: mov    DWORD PTR [rsp+0x44],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_1554:
	/* 0x1554: movzx  ecx,WORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 40ULL);
x86_l_1559:
	/* 0x1559: mov    WORD PTR [rsp+0x48],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_155e:
	/* 0x155e: mov    ecx,DWORD PTR [rsp+0x84] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_1565:
	/* 0x1565: mov    BYTE PTR [rsp+0x4a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 74ULL);
x86_l_1569:
	/* 0x1569: mov    BYTE PTR [rsp+0x4b],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 322122547200ULL);
x86_l_156e:
	/* 0x156e: mov    ecx,DWORD PTR [rsp+0xb4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 180ULL);
x86_l_1575:
	/* 0x1575: mov    DWORD PTR [rsp+0x4c],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_1579:
	/* 0x1579: mov    ecx,DWORD PTR [rsp+0x9c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_1580:
	/* 0x1580: mov    DWORD PTR [rsp+0x50],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1584:
	/* 0x1584: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1589:
	/* 0x1589: mov    QWORD PTR [rsp+0x60],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_158e:
	/* 0x158e: mov    r9d,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 25ULL);
x86_l_1594:
	/* 0x1594: shl    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_1598:
	/* 0x1598: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_159d:
	/* 0x159d: or     rdx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_15a0:
	/* 0x15a0: mov    rsi,QWORD PTR [rip+0xdbbc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_events)));
x86_l_15a7:
	/* 0x15a7: lea    rcx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_15ac:
	/* 0x15ac: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_15af:
	/* 0x15af: mov    r8d,0x38 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 56ULL);
x86_l_15b5:
	/* 0x15b5: call   r9 */
	X86_SIM_BPF_CALL_REG(X86_R9);
x86_l_15b8:
	/* 0x15b8: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15bb:
	/* 0x15bb: jmp    15e7 <tail_ipv4_to_endpoint+0x15e7> */
	X86_SIM_X86_JMP(0x15bb, 0x15e7, x86_l_15e7);
x86_l_15bd:
	/* 0x15bd: mov    rax,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_15c5:
	/* 0x15c5: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_15c8:
	/* 0x15c8: movabs r13,0x2090b0100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 8741650688ULL);
x86_l_15d2:
	/* 0x15d2: jmp    15b8 <tail_ipv4_to_endpoint+0x15b8> */
	X86_SIM_X86_JMP(0x15d2, 0x15b8, x86_l_15b8);
x86_l_15d4:
	/* 0x15d4: mov    r12d,0xffffff67 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967143ULL);
x86_l_15da:
	/* 0x15da: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15dd:
	/* 0x15dd: movabs r13,0x2090b0100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 8741650688ULL);
x86_l_15e7:
	/* 0x15e7: mov    ebp,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_32);
x86_l_15ea:
	/* 0x15ea: mov    r12d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_15ef:
	/* 0x15ef: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_15f1:
	/* 0x15f1: js     1af4 <tail_ipv4_to_endpoint+0x1af4> */
	X86_SIM_X86_JCC(X86_CC_S, 0x15f1, 0x1af4, x86_l_1af4);
x86_l_15f7:
	/* 0x15f7: cmp    ebp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_15fa:
	/* 0x15fa: je     1af4 <tail_ipv4_to_endpoint+0x1af4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x15fa, 0x1af4, x86_l_1af4);
x86_l_1600:
	/* 0x1600: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_1602:
	/* 0x1602: add    rsp,0xe8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 232ULL);
x86_l_1609:
	/* 0x1609: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_160a:
	/* 0x160a: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_160c:
	/* 0x160c: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_160e:
	/* 0x160e: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_1610:
	/* 0x1610: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_1612:
	/* 0x1612: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_1613:
	/* 0x1613: jmp    1afc <tail_ipv4_to_endpoint+0x1afc> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_1618:
	/* 0x1618: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_161d:
	/* 0x161d: movzx  eax,BYTE PTR [rax+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 12ULL);
x86_l_1621:
	/* 0x1621: cmp    eax,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 58ULL);
x86_l_1624:
	/* 0x1624: je     1717 <tail_ipv4_to_endpoint+0x1717> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1624, 0x1717, x86_l_1717);
x86_l_162a:
	/* 0x162a: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_162d:
	/* 0x162d: je     1709 <tail_ipv4_to_endpoint+0x1709> */
	X86_SIM_X86_JCC(X86_CC_E, 0x162d, 0x1709, x86_l_1709);
x86_l_1633:
	/* 0x1633: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_1636:
	/* 0x1636: jne    1725 <tail_ipv4_to_endpoint+0x1725> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1636, 0x1725, x86_l_1725);
x86_l_163c:
	/* 0x163c: mov    r14d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 16ULL);
x86_l_1642:
	/* 0x1642: jmp    171d <tail_ipv4_to_endpoint+0x171d> */
	X86_SIM_X86_JMP(0x1642, 0x171d, x86_l_171d);
x86_l_1647:
	/* 0x1647: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1649:
	/* 0x1649: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_164c:
	/* 0x164c: jne    4bb <tail_ipv4_to_endpoint+0x4bb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x164c, 0x4bb, x86_l_4bb);
x86_l_1652:
	/* 0x1652: and    r13b,BYTE PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_RSP, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 40ULL);
x86_l_1657:
	/* 0x1657: mov    eax,0xffffff63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967139ULL);
x86_l_165c:
	/* 0x165c: mov    r12d,0xffffff7b */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967163ULL);
x86_l_1662:
	/* 0x1662: cmovne r12d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RAX, X86_WIDTH_32, X86_CC_NE);
x86_l_1666:
	/* 0x1666: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1669:
	/* 0x1669: jmp    19ab <tail_ipv4_to_endpoint+0x19ab> */
	X86_SIM_X86_JMP(0x1669, 0x19ab, x86_l_19ab);
x86_l_166e:
	/* 0x166e: jne    1694 <tail_ipv4_to_endpoint+0x1694> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x166e, 0x1694, x86_l_1694);
x86_l_1670:
	/* 0x1670: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1675:
	/* 0x1675: movzx  eax,WORD PTR [rax+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_1679:
	/* 0x1679: shr    eax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 3ULL);
x86_l_167c:
	/* 0x167c: and    eax,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 31ULL);
x86_l_167f:
	/* 0x167f: movzx  ecx,WORD PTR [r12+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_1685:
	/* 0x1685: shr    ecx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 3ULL);
x86_l_1688:
	/* 0x1688: and    ecx,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 31ULL);
x86_l_168b:
	/* 0x168b: cmp    ax,cx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_16);
x86_l_168e:
	/* 0x168e: ja     10bd <tail_ipv4_to_endpoint+0x10bd> */
	X86_SIM_X86_JCC(X86_CC_A, 0x168e, 0x10bd, x86_l_10bd);
x86_l_1694:
	/* 0x1694: mov    r9,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1699:
	/* 0x1699: jmp    4be <tail_ipv4_to_endpoint+0x4be> */
	X86_SIM_X86_JMP(0x1699, 0x4be, x86_l_4be);
x86_l_169e:
	/* 0x169e: mov    r15d,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RCX, X86_WIDTH_32);
x86_l_16a1:
	/* 0x16a1: movzx  esi,WORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_16a6:
	/* 0x16a6: and    r15b,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_8, X86_ALU_AND, 127ULL);
x86_l_16aa:
	/* 0x16aa: je     665 <tail_ipv4_to_endpoint+0x665> */
	X86_SIM_X86_JCC(X86_CC_E, 0x16aa, 0x665, x86_l_665);
x86_l_16b0:
	/* 0x16b0: jmp    18ba <tail_ipv4_to_endpoint+0x18ba> */
	X86_SIM_X86_JMP(0x16b0, 0x18ba, x86_l_18ba);
x86_l_16b5:
	/* 0x16b5: cmp    r14b,0xbf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 191ULL);
x86_l_16b9:
	/* 0x16b9: ja     16d1 <tail_ipv4_to_endpoint+0x16d1> */
	X86_SIM_X86_JCC(X86_CC_A, 0x16b9, 0x16d1, x86_l_16d1);
x86_l_16bb:
	/* 0x16bb: mov    cl,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 24ULL);
x86_l_16bd:
	/* 0x16bd: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_16bf:
	/* 0x16bf: mov    eax,0xffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 65535ULL);
x86_l_16c4:
	/* 0x16c4: shlx   eax,eax,ecx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RAX, X86_RAX, X86_WIDTH_32, X86_RCX, X86_ALU_SHL);
x86_l_16c9:
	/* 0x16c9: rol    ax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_16cd:
	/* 0x16cd: and    DWORD PTR [rsp+0x20],eax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 32ULL);
x86_l_16d1:
	/* 0x16d1: mov    BYTE PTR [rsp+0x11],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 17ULL);
x86_l_16d6:
	/* 0x16d6: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_16da:
	/* 0x16da: mov    WORD PTR [rsp+0x12],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_16df:
	/* 0x16df: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_16e4:
	/* 0x16e4: mov    rdi,QWORD PTR [rip+0xdbb8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_policystats)));
x86_l_16eb:
	/* 0x16eb: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16f0:
	/* 0x16f0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16f2:
	/* 0x16f2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_16f5:
	/* 0x16f5: je     1804 <tail_ipv4_to_endpoint+0x1804> */
	X86_SIM_X86_JCC(X86_CC_E, 0x16f5, 0x1804, x86_l_1804);
x86_l_16fb:
	/* 0x16fb: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_16ff:
	/* 0x16ff: add QWORD PTR [rax+0x8],r13 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1704:
	/* 0x1704: jmp    182f <tail_ipv4_to_endpoint+0x182f> */
	X86_SIM_X86_JMP(0x1704, 0x182f, x86_l_182f);
x86_l_1709:
	/* 0x1709: mov    r14d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 6ULL);
x86_l_170f:
	/* 0x170f: mov    r13d,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 32ULL);
x86_l_1715:
	/* 0x1715: jmp    1720 <tail_ipv4_to_endpoint+0x1720> */
	X86_SIM_X86_JMP(0x1715, 0x1720, x86_l_1720);
x86_l_1717:
	/* 0x1717: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_171d:
	/* 0x171d: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1720:
	/* 0x1720: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1723:
	/* 0x1723: jmp    172e <tail_ipv4_to_endpoint+0x172e> */
	X86_SIM_X86_JMP(0x1723, 0x172e, x86_l_172e);
x86_l_1725:
	/* 0x1725: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1728:
	/* 0x1728: mov    r15b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_8, 1ULL);
x86_l_172b:
	/* 0x172b: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_172e:
	/* 0x172e: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1733:
	/* 0x1733: movzx  ecx,WORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1736:
	/* 0x1736: test   cx,cx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_16);
x86_l_1739:
	/* 0x1739: je     17cb <tail_ipv4_to_endpoint+0x17cb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1739, 0x17cb, x86_l_17cb);
x86_l_173f:
	/* 0x173f: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1744:
	/* 0x1744: movzx  edx,WORD PTR [rdx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_1748:
	/* 0x1748: mov    DWORD PTR [rsp+0x28],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_174c:
	/* 0x174c: mov    r12d,0xffffff72 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967154ULL);
x86_l_1752:
	/* 0x1752: cmp    eax,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_1755:
	/* 0x1755: jg     1766 <tail_ipv4_to_endpoint+0x1766> */
	X86_SIM_X86_JCC(X86_CC_G, 0x1755, 0x1766, x86_l_1766);
x86_l_1757:
	/* 0x1757: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_175a:
	/* 0x175a: je     17cb <tail_ipv4_to_endpoint+0x17cb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x175a, 0x17cb, x86_l_17cb);
x86_l_175c:
	/* 0x175c: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_175f:
	/* 0x175f: je     1774 <tail_ipv4_to_endpoint+0x1774> */
	X86_SIM_X86_JCC(X86_CC_E, 0x175f, 0x1774, x86_l_1774);
x86_l_1761:
	/* 0x1761: jmp    15da <tail_ipv4_to_endpoint+0x15da> */
	X86_SIM_X86_JMP(0x1761, 0x15da, x86_l_15da);
x86_l_1766:
	/* 0x1766: cmp    eax,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 58ULL);
x86_l_1769:
	/* 0x1769: je     17cb <tail_ipv4_to_endpoint+0x17cb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1769, 0x17cb, x86_l_17cb);
x86_l_176b:
	/* 0x176b: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_176e:
	/* 0x176e: jne    15da <tail_ipv4_to_endpoint+0x15da> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x176e, 0x15da, x86_l_15da);
x86_l_1774:
	/* 0x1774: cmp    cx,WORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 40ULL);
x86_l_1779:
	/* 0x1779: je     17cb <tail_ipv4_to_endpoint+0x17cb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1779, 0x17cb, x86_l_17cb);
x86_l_177b:
	/* 0x177b: mov    WORD PTR [rsp+0x70],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1780:
	/* 0x1780: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_1785:
	/* 0x1785: lea    rdx,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_178a:
	/* 0x178a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_178d:
	/* 0x178d: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1792:
	/* 0x1792: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1797:
	/* 0x1797: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_179a:
	/* 0x179a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_179c:
	/* 0x179c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_179e:
	/* 0x179e: js     1ad1 <tail_ipv4_to_endpoint+0x1ad1> */
	X86_SIM_X86_JCC(X86_CC_S, 0x179e, 0x1ad1, x86_l_1ad1);
x86_l_17a4:
	/* 0x17a4: movzx  ecx,WORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 112ULL);
x86_l_17a9:
	/* 0x17a9: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_17ae:
	/* 0x17ae: lea    esi,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_17b2:
	/* 0x17b2: mov    r8d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R13, X86_WIDTH_32);
x86_l_17b5:
	/* 0x17b5: or     r8d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_17b9:
	/* 0x17b9: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_17be:
	/* 0x17be: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_17c1:
	/* 0x17c1: mov    edx,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_17c5:
	/* 0x17c5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17c7:
	/* 0x17c7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_17c9:
	/* 0x17c9: js     17f9 <tail_ipv4_to_endpoint+0x17f9> */
	X86_SIM_X86_JCC(X86_CC_S, 0x17c9, 0x17f9, x86_l_17f9);
x86_l_17cb:
	/* 0x17cb: test   r15b,r15b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_8);
x86_l_17ce:
	/* 0x17ce: jne    125a <tail_ipv4_to_endpoint+0x125a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x17ce, 0x125a, x86_l_125a);
x86_l_17d4:
	/* 0x17d4: add    r14d,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 32ULL);
x86_l_17d9:
	/* 0x17d9: or     r13d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_OR, 16ULL);
x86_l_17dd:
	/* 0x17dd: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_17e2:
	/* 0x17e2: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_17e5:
	/* 0x17e5: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_17e8:
	/* 0x17e8: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17ea:
	/* 0x17ea: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_17ec:
	/* 0x17ec: mov    r8d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R13, X86_WIDTH_32);
x86_l_17ef:
	/* 0x17ef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17f1:
	/* 0x17f1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_17f3:
	/* 0x17f3: jns    125a <tail_ipv4_to_endpoint+0x125a> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x17f3, 0x125a, x86_l_125a);
x86_l_17f9:
	/* 0x17f9: mov    r12d,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967142ULL);
x86_l_17ff:
	/* 0x17ff: jmp    15da <tail_ipv4_to_endpoint+0x15da> */
	X86_SIM_X86_JMP(0x17ff, 0x15da, x86_l_15da);
x86_l_1804:
	/* 0x1804: mov    QWORD PTR [rsp+0x30],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430209ULL);
x86_l_180d:
	/* 0x180d: mov    QWORD PTR [rsp+0x38],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1812:
	/* 0x1812: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1817:
	/* 0x1817: mov    rdi,QWORD PTR [rip+0xdbb8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_policystats)));
x86_l_181e:
	/* 0x181e: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1823:
	/* 0x1823: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1828:
	/* 0x1828: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_182d:
	/* 0x182d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_182f:
	/* 0x182f: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1834:
	/* 0x1834: movzx  eax,WORD PTR [rax+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_1838:
	/* 0x1838: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_183a:
	/* 0x183a: cmp    r14b,0x48 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 72ULL);
x86_l_183e:
	/* 0x183e: setb   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_B);
x86_l_1841:
	/* 0x1841: cmp    r14b,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 8ULL);
x86_l_1845:
	/* 0x1845: lea    ecx,[rcx+rcx*2+0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 1), 3ULL);
x86_l_1849:
	/* 0x1849: mov    r8d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 4ULL);
x86_l_184f:
	/* 0x184f: cmovae r8d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R8, X86_RCX, X86_WIDTH_32, X86_CC_AE);
x86_l_1853:
	/* 0x1853: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1858:
	/* 0x1858: mov    edi,DWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_185b:
	/* 0x185b: test   al,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_185d:
	/* 0x185d: jne    19a5 <tail_ipv4_to_endpoint+0x19a5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x185d, 0x19a5, x86_l_19a5);
x86_l_1863:
	/* 0x1863: movzx  r15d,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1867:
	/* 0x1867: shr    r15d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_186b:
	/* 0x186b: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_186e:
	/* 0x186e: je     1899 <tail_ipv4_to_endpoint+0x1899> */
	X86_SIM_X86_JCC(X86_CC_E, 0x186e, 0x1899, x86_l_1899);
x86_l_1870:
	/* 0x1870: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_1873:
	/* 0x1873: js     1899 <tail_ipv4_to_endpoint+0x1899> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1873, 0x1899, x86_l_1899);
x86_l_1875:
	/* 0x1875: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_187a:
	/* 0x187a: mov    eax,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_187d:
	/* 0x187d: cmp    DWORD PTR [r12+0x4],eax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1882:
	/* 0x1882: jne    1899 <tail_ipv4_to_endpoint+0x1899> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1882, 0x1899, x86_l_1899);
x86_l_1884:
	/* 0x1884: movzx  eax,BYTE PTR [r12+0x3] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 3ULL);
x86_l_188a:
	/* 0x188a: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_188c:
	/* 0x188c: and    ecx,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 127ULL);
x86_l_188f:
	/* 0x188f: cmp    cx,r15w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R15, X86_WIDTH_16);
x86_l_1893:
	/* 0x1893: ja     1aec <tail_ipv4_to_endpoint+0x1aec> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1893, 0x1aec, x86_l_1aec);
x86_l_1899:
	/* 0x1899: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_189e:
	/* 0x189e: movzx  esi,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_18a1:
	/* 0x18a1: and    r15b,0x7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_8, X86_ALU_AND, 127ULL);
x86_l_18a5:
	/* 0x18a5: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_18aa:
	/* 0x18aa: movabs r13,0x2090b0100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 8741650688ULL);
x86_l_18b4:
	/* 0x18b4: je     665 <tail_ipv4_to_endpoint+0x665> */
	X86_SIM_X86_JCC(X86_CC_E, 0x18b4, 0x665, x86_l_665);
x86_l_18ba:
	/* 0x18ba: mov    DWORD PTR [rsp+0x80],r8d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_18c2:
	/* 0x18c2: mov    QWORD PTR [rsp+0xa0],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_18ca:
	/* 0x18ca: mov    DWORD PTR [rsp+0x28],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_18ce:
	/* 0x18ce: mov    QWORD PTR [rsp+0x36],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 231928233984ULL);
x86_l_18d7:
	/* 0x18d7: mov    WORD PTR [rsp+0x46],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 300647710720ULL);
x86_l_18de:
	/* 0x18de: mov    QWORD PTR [rsp+0x3e],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 266287972352ULL);
x86_l_18e7:
	/* 0x18e7: mov    DWORD PTR [rsp+0x30],0x40 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430272ULL);
x86_l_18ef:
	/* 0x18ef: mov    BYTE PTR [rsp+0x37],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 236223201281ULL);
x86_l_18f4:
	/* 0x18f4: mov    eax,DWORD PTR [rsp+0x9c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_18fb:
	/* 0x18fb: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_18ff:
	/* 0x18ff: mov    WORD PTR [rsp+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_1906:
	/* 0x1906: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_190b:
	/* 0x190b: mov    rdi,QWORD PTR [rip+0xdbb8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipcache_v2)));
x86_l_1912:
	/* 0x1912: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1917:
	/* 0x1917: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1919:
	/* 0x1919: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_191c:
	/* 0x191c: je     19bb <tail_ipv4_to_endpoint+0x19bb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x191c, 0x19bb, x86_l_19bb);
x86_l_1922:
	/* 0x1922: mov    rcx,QWORD PTR [rip+0xdbb8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_security_label)));
x86_l_1929:
	/* 0x1929: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_192b:
	/* 0x192b: mov    eax,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_192e:
	/* 0x192e: mov    DWORD PTR [rsp+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1932:
	/* 0x1932: mov    ecx,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1936:
	/* 0x1936: mov    DWORD PTR [rsp+0xc],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_193a:
	/* 0x193a: mov    WORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1941:
	/* 0x1941: mov    BYTE PTR [rsp+0x12],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_1946:
	/* 0x1946: mov    BYTE PTR [rsp+0x13],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 81604378624ULL);
x86_l_194b:
	/* 0x194b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_194d:
	/* 0x194d: je     19ef <tail_ipv4_to_endpoint+0x19ef> */
	X86_SIM_X86_JCC(X86_CC_E, 0x194d, 0x19ef, x86_l_19ef);
x86_l_1953:
	/* 0x1953: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_195c:
	/* 0x195c: mov    DWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1964:
	/* 0x1964: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_196d:
	/* 0x196d: mov    BYTE PTR [rsp+0x33],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 219043332097ULL);
x86_l_1972:
	/* 0x1972: mov    DWORD PTR [rsp+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1976:
	/* 0x1976: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_197b:
	/* 0x197b: mov    rdi,QWORD PTR [rip+0xdbb8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_node_map_v2)));
x86_l_1982:
	/* 0x1982: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1987:
	/* 0x1987: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1989:
	/* 0x1989: mov    r12d,0xffffff3b */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967099ULL);
x86_l_198f:
	/* 0x198f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1992:
	/* 0x1992: je     1a94 <tail_ipv4_to_endpoint+0x1a94> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1992, 0x1a94, x86_l_1a94);
x86_l_1998:
	/* 0x1998: movzx  eax,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_199b:
	/* 0x199b: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_199e:
	/* 0x199e: jne    19f1 <tail_ipv4_to_endpoint+0x19f1> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x199e, 0x19f1, x86_l_19f1);
x86_l_19a0:
	/* 0x19a0: jmp    1a94 <tail_ipv4_to_endpoint+0x1a94> */
	X86_SIM_X86_JMP(0x19a0, 0x1a94, x86_l_1a94);
x86_l_19a5:
	/* 0x19a5: mov    r12d,0xffffff4b */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967115ULL);
x86_l_19ab:
	/* 0x19ab: mov    r9b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_8, 1ULL);
x86_l_19ae:
	/* 0x19ae: xor    r10d,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R10, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19b1:
	/* 0x19b1: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19b4:
	/* 0x19b4: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19b6:
	/* 0x19b6: jmp    56f <tail_ipv4_to_endpoint+0x56f> */
	X86_SIM_X86_JMP(0x19b6, 0x56f, x86_l_56f);
x86_l_19bb:
	/* 0x19bb: mov    r12d,0xffffff43 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967107ULL);
x86_l_19c1:
	/* 0x19c1: mov    r9b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_8, 1ULL);
x86_l_19c4:
	/* 0x19c4: xor    r10d,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R10, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19c7:
	/* 0x19c7: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_19cc:
	/* 0x19cc: movabs r13,0x2090b0100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 8741650688ULL);
x86_l_19d6:
	/* 0x19d6: mov    esi,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_19da:
	/* 0x19da: mov    rdi,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_19e2:
	/* 0x19e2: mov    r8d,DWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_19ea:
	/* 0x19ea: jmp    68c <tail_ipv4_to_endpoint+0x68c> */
	X86_SIM_X86_JMP(0x19ea, 0x68c, x86_l_68c);
x86_l_19ef:
	/* 0x19ef: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19f1:
	/* 0x19f1: mov    WORD PTR [rsp+0x10],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19f6:
	/* 0x19f6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_19fb:
	/* 0x19fb: mov    rdi,QWORD PTR [rip+0xdbb8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_auth_map)));
x86_l_1a02:
	/* 0x1a02: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a07:
	/* 0x1a07: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a09:
	/* 0x1a09: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a0c:
	/* 0x1a0c: je     1a53 <tail_ipv4_to_endpoint+0x1a53> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a0c, 0x1a53, x86_l_1a53);
x86_l_1a0e:
	/* 0x1a0e: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_1a11:
	/* 0x1a11: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1a16:
	/* 0x1a16: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a19:
	/* 0x1a19: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a1b:
	/* 0x1a1b: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1a1d:
	/* 0x1a1d: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_1a20:
	/* 0x1a20: shr    r13,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1a24:
	/* 0x1a24: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1a2c:
	/* 0x1a2c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a31:
	/* 0x1a31: mov    rdi,QWORD PTR [rip+0xdbb8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_runtime_config)));
x86_l_1a38:
	/* 0x1a38: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1a3d:
	/* 0x1a3d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a3f:
	/* 0x1a3f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a42:
	/* 0x1a42: je     1adc <tail_ipv4_to_endpoint+0x1adc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a42, 0x1adc, x86_l_1adc);
x86_l_1a48:
	/* 0x1a48: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a4b:
	/* 0x1a4b: add    rax,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1a4e:
	/* 0x1a4e: cmp    rax,QWORD PTR [r14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_1a51:
	/* 0x1a51: jb     1a94 <tail_ipv4_to_endpoint+0x1a94> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1a51, 0x1a94, x86_l_1a94);
x86_l_1a53:
	/* 0x1a53: mov    DWORD PTR [rsp+0x30],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430210ULL);
x86_l_1a5b:
	/* 0x1a5b: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a60:
	/* 0x1a60: mov    QWORD PTR [rsp+0x34],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1a65:
	/* 0x1a65: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a69:
	/* 0x1a69: mov    DWORD PTR [rsp+0x3c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_1a6d:
	/* 0x1a6d: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_1a72:
	/* 0x1a72: mov    rsi,QWORD PTR [rip+0xdbb8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_signals)));
x86_l_1a79:
	/* 0x1a79: lea    rcx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1a7e:
	/* 0x1a7e: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_1a83:
	/* 0x1a83: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1a86:
	/* 0x1a86: mov    r8d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 16ULL);
x86_l_1a8c:
	/* 0x1a8c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a8e:
	/* 0x1a8e: mov    r12d,0xffffff43 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967107ULL);
x86_l_1a94:
	/* 0x1a94: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a99:
	/* 0x1a99: movabs r13,0x2090b0100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 8741650688ULL);
x86_l_1aa3:
	/* 0x1aa3: mov    esi,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1aa7:
	/* 0x1aa7: mov    rdi,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1aaf:
	/* 0x1aaf: mov    r8d,DWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1ab7:
	/* 0x1ab7: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_1aba:
	/* 0x1aba: setne  r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_NE);
x86_l_1abe:
	/* 0x1abe: cmp    DWORD PTR [rsp+0x84],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 566935683073ULL);
x86_l_1ac6:
	/* 0x1ac6: je     680 <tail_ipv4_to_endpoint+0x680> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1ac6, 0x680, x86_l_680);
x86_l_1acc:
	/* 0x1acc: jmp    470 <tail_ipv4_to_endpoint+0x470> */
	X86_SIM_X86_JMP(0x1acc, 0x470, x86_l_470);
x86_l_1ad1:
	/* 0x1ad1: mov    r12d,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967155ULL);
x86_l_1ad7:
	/* 0x1ad7: jmp    15da <tail_ipv4_to_endpoint+0x15da> */
	X86_SIM_X86_JMP(0x1ad7, 0x15da, x86_l_15da);
x86_l_1adc:
	/* 0x1adc: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ade:
	/* 0x1ade: add    rax,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1ae1:
	/* 0x1ae1: cmp    rax,QWORD PTR [r14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_1ae4:
	/* 0x1ae4: jae    1a53 <tail_ipv4_to_endpoint+0x1a53> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x1ae4, 0x1a53, x86_l_1a53);
x86_l_1aea:
	/* 0x1aea: jmp    1a94 <tail_ipv4_to_endpoint+0x1a94> */
	X86_SIM_X86_JMP(0x1aea, 0x1a94, x86_l_1a94);
x86_l_1aec:
	/* 0x1aec: mov    r15d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_32);
x86_l_1aef:
	/* 0x1aef: jmp    1899 <tail_ipv4_to_endpoint+0x1899> */
	X86_SIM_X86_JMP(0x1aef, 0x1899, x86_l_1899);
x86_l_1af4:
	/* 0x1af4: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1af7:
	/* 0x1af7: jmp    3e <tail_ipv4_to_endpoint+0x3e> */
	X86_SIM_X86_JMP(0x1af7, 0x3e, x86_l_3e);
x86_l_1afc:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
