extern char __aux_snat_v6_nhm_nat_entry;
extern char __aux_snat_v6_nhm_tuple;
extern char __config_enable_ipv6_fragments;
extern char __config_enable_jiffies;
extern char __config_enable_nodeport_source_lookup;
extern char __config_eth_header_length;
extern char __config_events_map_burst_limit;
extern char __config_events_map_rate_limit;
extern char __config_host_ep_id;
extern char __config_nodeport_port_max;
extern char __config_router_ipv6;
extern char __config_supports_fib_lookup_skip_neigh;
extern char __config_supports_fib_lookup_src;
extern char __config_trace_payload_len;
extern char __config_tracing_ip_option_type;
extern char _aux_max_off;
extern char _aux_stride;
extern char cilium_calls;
extern char cilium_devices;
extern char cilium_events;
extern char cilium_ipcache_v2;
extern char cilium_ipv6_frag_datagrams;
extern char cilium_metrics;
extern char cilium_percpu_trace_id;
extern char cilium_ratelimit;
extern char cilium_ratelimit_metrics;
extern char cilium_signals;
extern char cilium_snat_v6_alloc_retries;
extern char cilium_snat_v6_external;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int cilium_bpf_host_tail_nodeport_nat_egress_ipv6_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0xa: mov    QWORD PTR [rsp+0x100],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1099511627776ULL);
x86_l_16:
	/* 0x16: mov    DWORD PTR [rsp+0x140],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1374389534720ULL);
x86_l_21:
	/* 0x21: mov    QWORD PTR [rsp+0x138],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1340029796352ULL);
x86_l_2d:
	/* 0x2d: mov    QWORD PTR [rsp+0x130],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1305670057984ULL);
x86_l_39:
	/* 0x39: mov    QWORD PTR [rsp+0x128],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1271310319616ULL);
x86_l_45:
	/* 0x45: mov    QWORD PTR [rsp+0x120],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1236950581248ULL);
x86_l_51:
	/* 0x51: mov    QWORD PTR [rsp+0x118],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1202590842880ULL);
x86_l_5d:
	/* 0x5d: mov    QWORD PTR [rsp+0x110],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1168231104512ULL);
x86_l_69:
	/* 0x69: mov    QWORD PTR [rsp+0x108],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1133871366144ULL);
x86_l_75:
	/* 0x75: mov    r15,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDI, X86_WIDTH_64);
x86_l_78:
	/* 0x78: mov    BYTE PTR [rsp+0x100],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 1099511627786ULL);
x86_l_80:
	/* 0x80: mov    eax,DWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_83:
	/* 0x83: mov    DWORD PTR [rsp+0x108],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_8a:
	/* 0x8a: mov    QWORD PTR [rsp+0xe0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 962072674304ULL);
x86_l_96:
	/* 0x96: mov    QWORD PTR [rsp+0xd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 927712935936ULL);
x86_l_a2:
	/* 0xa2: mov    rax,QWORD PTR [rip+0x88d7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_nodeport_port_max)));
x86_l_a9:
	/* 0xa9: movzx  esi,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_ac:
	/* 0xac: mov    QWORD PTR [rsp+0xbe],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 816043786240ULL);
x86_l_b8:
	/* 0xb8: mov    QWORD PTR [rsp+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_c4:
	/* 0xc4: mov    QWORD PTR [rsp+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_d0:
	/* 0xd0: mov    QWORD PTR [rsp+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_dc:
	/* 0xdc: mov    QWORD PTR [rsp+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_e8:
	/* 0xe8: mov    rax,QWORD PTR [rip+0x88d7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_ef:
	/* 0xef: mov    ebx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f1:
	/* 0xf1: mov    r13,QWORD PTR [rip+0x88d7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_f8:
	/* 0xf8: movzx  eax,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_fd:
	/* 0xfd: mov    r12d,DWORD PTR [rdi+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_101:
	/* 0x101: mov    ecx,DWORD PTR [rdi+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_104:
	/* 0x104: lea    rdx,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_108:
	/* 0x108: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_10c:
	/* 0x10c: cmp    rdx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_10f:
	/* 0x10f: jbe    184 <tail_nodeport_nat_egress_ipv6+0x184> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x10f, 0x184, x86_l_184);
x86_l_111:
	/* 0x111: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_116:
	/* 0x116: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_119:
	/* 0x119: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_11b:
	/* 0x11b: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_11d:
	/* 0x11d: cmovs  eax,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RBP, X86_WIDTH_32, X86_CC_S);
x86_l_120:
	/* 0x120: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_123:
	/* 0x123: movzx  ecx,r13b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R13, X86_WIDTH_32, X86_WIDTH_8);
x86_l_127:
	/* 0x127: shl    ecx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_12a:
	/* 0x12a: mov    QWORD PTR [r15+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_132:
	/* 0x132: or     ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_OR);
x86_l_134:
	/* 0x134: mov    DWORD PTR [r15+0x38],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_138:
	/* 0x138: movabs rcx,0x54c680200000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 381794426218872832ULL);
x86_l_142:
	/* 0x142: mov    QWORD PTR [r15+0x3c],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_146:
	/* 0x146: mov    ebx,DWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_149:
	/* 0x149: movabs rcx,0x68054c0200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 446765466112ULL);
x86_l_153:
	/* 0x153: mov    QWORD PTR [rsp+0x58],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_158:
	/* 0x158: mov    BYTE PTR [rsp+0x58],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_15c:
	/* 0x15c: mov    rdi,QWORD PTR [rip+0x88d7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_163:
	/* 0x163: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_168:
	/* 0x168: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_16d:
	/* 0x16d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16f:
	/* 0x16f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_172:
	/* 0x172: je     227 <tail_nodeport_nat_egress_ipv6+0x227> */
	X86_SIM_X86_JCC(X86_CC_E, 0x172, 0x227, x86_l_227);
x86_l_178:
	/* 0x178: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_17b:
	/* 0x17b: add    QWORD PTR [rax+0x8],rbx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_17f:
	/* 0x17f: jmp    24f <tail_nodeport_nat_egress_ipv6+0x24f> */
	X86_SIM_X86_JMP(0x17f, 0x24f, x86_l_24f);
x86_l_184:
	/* 0x184: mov    QWORD PTR [rsp+0x98],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_18c:
	/* 0x18c: mov    QWORD PTR [rsp],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_190:
	/* 0x190: add    r12,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_193:
	/* 0x193: movzx  r15d,BYTE PTR [r12+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_199:
	/* 0x199: movzx  eax,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_19e:
	/* 0x19e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a0:
	/* 0x1a0: mov    BYTE PTR [rsp+0xc4],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_1a8:
	/* 0x1a8: cmp    r15,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 60ULL);
x86_l_1ac:
	/* 0x1ac: ja     3d2 <tail_nodeport_nat_egress_ipv6+0x3d2> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1ac, 0x3d2, x86_l_3d2);
x86_l_1b2:
	/* 0x1b2: mov    r14d,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4294967140ULL);
x86_l_1b8:
	/* 0x1b8: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_1c2:
	/* 0x1c2: bt     rdx,r15 */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1c6:
	/* 0x1c6: jae    28f <tail_nodeport_nat_egress_ipv6+0x28f> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x1c6, 0x28f, x86_l_28f);
x86_l_1cc:
	/* 0x1cc: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1d4:
	/* 0x1d4: lea    ebp,[rax+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1d7:
	/* 0x1d7: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1dc:
	/* 0x1dc: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1e1:
	/* 0x1e1: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e5:
	/* 0x1e5: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_1e7:
	/* 0x1e7: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1ec:
	/* 0x1ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ee:
	/* 0x1ee: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1f0:
	/* 0x1f0: js     67d <tail_nodeport_nat_egress_ipv6+0x67d> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1f0, 0x67d, x86_l_67d);
x86_l_1f6:
	/* 0x1f6: movzx  esi,BYTE PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_1fb:
	/* 0x1fb: cmp    r15d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 43ULL);
x86_l_1ff:
	/* 0x1ff: mov    DWORD PTR [rsp+0x90],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_206:
	/* 0x206: jle    270 <tail_nodeport_nat_egress_ipv6+0x270> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x206, 0x270, x86_l_270);
x86_l_208:
	/* 0x208: cmp    r15d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 60ULL);
x86_l_20c:
	/* 0x20c: je     270 <tail_nodeport_nat_egress_ipv6+0x270> */
	X86_SIM_X86_JCC(X86_CC_E, 0x20c, 0x270, x86_l_270);
x86_l_20e:
	/* 0x20e: cmp    r15d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 51ULL);
x86_l_212:
	/* 0x212: jne    2af <tail_nodeport_nat_egress_ipv6+0x2af> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x212, 0x2af, x86_l_2af);
x86_l_218:
	/* 0x218: movzx  eax,BYTE PTR [rsp+0x11] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 17ULL);
x86_l_21d:
	/* 0x21d: lea    r13d,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_225:
	/* 0x225: jmp    288 <tail_nodeport_nat_egress_ipv6+0x288> */
	X86_SIM_X86_JMP(0x225, 0x288, x86_l_288);
x86_l_227:
	/* 0x227: mov    QWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_230:
	/* 0x230: mov    QWORD PTR [rsp+0x18],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_235:
	/* 0x235: mov    rdi,QWORD PTR [rip+0x88d7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_23c:
	/* 0x23c: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_241:
	/* 0x241: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_246:
	/* 0x246: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_24b:
	/* 0x24b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_24d:
	/* 0x24d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24f:
	/* 0x24f: mov    rsi,QWORD PTR [rip+0x88d7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_256:
	/* 0x256: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_25b:
	/* 0x25b: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_25e:
	/* 0x25e: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_263:
	/* 0x263: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_265:
	/* 0x265: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_26b:
	/* 0x26b: jmp    683 <tail_nodeport_nat_egress_ipv6+0x683> */
	X86_SIM_X86_JMP(0x26b, 0x683, x86_l_683);
x86_l_270:
	/* 0x270: movzx  eax,BYTE PTR [rsp+0x11] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 17ULL);
x86_l_275:
	/* 0x275: lea    r13d,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_27d:
	/* 0x27d: cmp    r15b,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_8, 44ULL);
x86_l_281:
	/* 0x281: jne    288 <tail_nodeport_nat_egress_ipv6+0x288> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x281, 0x288, x86_l_288);
x86_l_283:
	/* 0x283: mov    r15d,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSI, X86_WIDTH_32);
x86_l_286:
	/* 0x286: jmp    2b8 <tail_nodeport_nat_egress_ipv6+0x2b8> */
	X86_SIM_X86_JMP(0x286, 0x2b8, x86_l_2b8);
x86_l_288:
	/* 0x288: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_28a:
	/* 0x28a: jmp    324 <tail_nodeport_nat_egress_ipv6+0x324> */
	X86_SIM_X86_JMP(0x28a, 0x324, x86_l_324);
x86_l_28f:
	/* 0x28f: mov    eax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 40ULL);
x86_l_294:
	/* 0x294: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_299:
	/* 0x299: mov    DWORD PTR [rsp+0x90],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2a0:
	/* 0x2a0: cmp    r15,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 59ULL);
x86_l_2a4:
	/* 0x2a4: je     683 <tail_nodeport_nat_egress_ipv6+0x683> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2a4, 0x683, x86_l_683);
x86_l_2aa:
	/* 0x2aa: jmp    6a3 <tail_nodeport_nat_egress_ipv6+0x6a3> */
	X86_SIM_X86_JMP(0x2aa, 0x6a3, x86_l_6a3);
x86_l_2af:
	/* 0x2af: mov    r15d,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSI, X86_WIDTH_32);
x86_l_2b2:
	/* 0x2b2: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_2b8:
	/* 0x2b8: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2c1:
	/* 0x2c1: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c6:
	/* 0x2c6: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_2cb:
	/* 0x2cb: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2cf:
	/* 0x2cf: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_2d1:
	/* 0x2d1: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2d6:
	/* 0x2d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d8:
	/* 0x2d8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2da:
	/* 0x2da: js     67d <tail_nodeport_nat_egress_ipv6+0x67d> */
	X86_SIM_X86_JCC(X86_CC_S, 0x2da, 0x67d, x86_l_67d);
x86_l_2e0:
	/* 0x2e0: mov    eax,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2e4:
	/* 0x2e4: movzx  ecx,BYTE PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_2e9:
	/* 0x2e9: shl    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_2ed:
	/* 0x2ed: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2f0:
	/* 0x2f0: movzx  eax,WORD PTR [rsp+0x12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18ULL);
x86_l_2f5:
	/* 0x2f5: movabs rdx,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1099511627776ULL);
x86_l_2ff:
	/* 0x2ff: or     rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_302:
	/* 0x302: test   eax,0xf9ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63999ULL);
x86_l_307:
	/* 0x307: cmove  rdx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_64, X86_CC_E);
x86_l_30b:
	/* 0x30b: movabs rcx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2199023255552ULL);
x86_l_315:
	/* 0x315: or     rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_OR);
x86_l_318:
	/* 0x318: test   eax,0xf8ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63743ULL);
x86_l_31d:
	/* 0x31d: cmove  rcx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_321:
	/* 0x321: mov    esi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_324:
	/* 0x324: movzx  ebx,sil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RSI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_328:
	/* 0x328: lea    eax,[r13+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_32c:
	/* 0x32c: cmp    ebx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 60ULL);
x86_l_32f:
	/* 0x32f: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_333:
	/* 0x333: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_338:
	/* 0x338: ja     520 <tail_nodeport_nat_egress_ipv6+0x520> */
	X86_SIM_X86_JCC(X86_CC_A, 0x338, 0x520, x86_l_520);
x86_l_33e:
	/* 0x33e: mov    eax,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_32);
x86_l_340:
	/* 0x340: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_34a:
	/* 0x34a: bt     rdx,rax */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_34e:
	/* 0x34e: jae    3b9 <tail_nodeport_nat_egress_ipv6+0x3b9> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x34e, 0x3b9, x86_l_3b9);
x86_l_350:
	/* 0x350: mov    BYTE PTR [rsp+0x94],sil */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_358:
	/* 0x358: mov    QWORD PTR [rsp+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_360:
	/* 0x360: mov    rax,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_368:
	/* 0x368: lea    ebp,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_36c:
	/* 0x36c: add    ebp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 40ULL);
x86_l_36f:
	/* 0x36f: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_374:
	/* 0x374: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_379:
	/* 0x379: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_37b:
	/* 0x37b: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_380:
	/* 0x380: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_382:
	/* 0x382: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_384:
	/* 0x384: js     67d <tail_nodeport_nat_egress_ipv6+0x67d> */
	X86_SIM_X86_JCC(X86_CC_S, 0x384, 0x67d, x86_l_67d);
x86_l_38a:
	/* 0x38a: movzx  r15d,BYTE PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_390:
	/* 0x390: cmp    ebx,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 43ULL);
x86_l_393:
	/* 0x393: jle    3e8 <tail_nodeport_nat_egress_ipv6+0x3e8> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x393, 0x3e8, x86_l_3e8);
x86_l_395:
	/* 0x395: cmp    ebx,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 44ULL);
x86_l_398:
	/* 0x398: je     404 <tail_nodeport_nat_egress_ipv6+0x404> */
	X86_SIM_X86_JCC(X86_CC_E, 0x398, 0x404, x86_l_404);
x86_l_39a:
	/* 0x39a: cmp    ebx,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 51ULL);
x86_l_39d:
	/* 0x39d: movzx  ecx,BYTE PTR [rsp+0x94] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 148ULL);
x86_l_3a5:
	/* 0x3a5: jne    3f0 <tail_nodeport_nat_egress_ipv6+0x3f0> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3a5, 0x3f0, x86_l_3f0);
x86_l_3a7:
	/* 0x3a7: movzx  eax,BYTE PTR [rsp+0x11] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 17ULL);
x86_l_3ac:
	/* 0x3ac: lea    r13d,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_3b4:
	/* 0x3b4: jmp    47b <tail_nodeport_nat_egress_ipv6+0x47b> */
	X86_SIM_X86_JMP(0x3b4, 0x47b, x86_l_47b);
x86_l_3b9:
	/* 0x3b9: mov    r15d,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSI, X86_WIDTH_32);
x86_l_3bc:
	/* 0x3bc: cmp    rax,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 59ULL);
x86_l_3c0:
	/* 0x3c0: mov    r13,QWORD PTR [rip+0x88d7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_3c7:
	/* 0x3c7: je     683 <tail_nodeport_nat_egress_ipv6+0x683> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3c7, 0x683, x86_l_683);
x86_l_3cd:
	/* 0x3cd: jmp    6a3 <tail_nodeport_nat_egress_ipv6+0x6a3> */
	X86_SIM_X86_JMP(0x3cd, 0x6a3, x86_l_6a3);
x86_l_3d2:
	/* 0x3d2: mov    eax,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 40ULL);
x86_l_3d7:
	/* 0x3d7: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3dc:
	/* 0x3dc: mov    DWORD PTR [rsp+0x90],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_3e3:
	/* 0x3e3: jmp    6a3 <tail_nodeport_nat_egress_ipv6+0x6a3> */
	X86_SIM_X86_JMP(0x3e3, 0x6a3, x86_l_6a3);
x86_l_3e8:
	/* 0x3e8: movzx  ecx,BYTE PTR [rsp+0x94] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 148ULL);
x86_l_3f0:
	/* 0x3f0: movzx  eax,BYTE PTR [rsp+0x11] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 17ULL);
x86_l_3f5:
	/* 0x3f5: lea    r13d,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_3fd:
	/* 0x3fd: cmp    cl,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 44ULL);
x86_l_400:
	/* 0x400: je     40a <tail_nodeport_nat_egress_ipv6+0x40a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x400, 0x40a, x86_l_40a);
x86_l_402:
	/* 0x402: jmp    47b <tail_nodeport_nat_egress_ipv6+0x47b> */
	X86_SIM_X86_JMP(0x402, 0x47b, x86_l_47b);
x86_l_404:
	/* 0x404: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_40a:
	/* 0x40a: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_413:
	/* 0x413: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_418:
	/* 0x418: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_41d:
	/* 0x41d: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_421:
	/* 0x421: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_423:
	/* 0x423: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_428:
	/* 0x428: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_42a:
	/* 0x42a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_42c:
	/* 0x42c: js     67d <tail_nodeport_nat_egress_ipv6+0x67d> */
	X86_SIM_X86_JCC(X86_CC_S, 0x42c, 0x67d, x86_l_67d);
x86_l_432:
	/* 0x432: mov    eax,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_436:
	/* 0x436: movzx  ecx,BYTE PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_43b:
	/* 0x43b: shl    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_43f:
	/* 0x43f: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_442:
	/* 0x442: movzx  eax,WORD PTR [rsp+0x12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18ULL);
x86_l_447:
	/* 0x447: movabs rdx,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1099511627776ULL);
x86_l_451:
	/* 0x451: or     rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_454:
	/* 0x454: test   eax,0xf9ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63999ULL);
x86_l_459:
	/* 0x459: cmove  rdx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_64, X86_CC_E);
x86_l_45d:
	/* 0x45d: movabs rcx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2199023255552ULL);
x86_l_467:
	/* 0x467: or     rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_OR);
x86_l_46a:
	/* 0x46a: test   eax,0xf8ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63743ULL);
x86_l_46f:
	/* 0x46f: cmove  rcx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_473:
	/* 0x473: mov    QWORD PTR [rsp+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_47b:
	/* 0x47b: movzx  ebx,r15b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_R15, X86_WIDTH_32, X86_WIDTH_8);
x86_l_47f:
	/* 0x47f: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_484:
	/* 0x484: add    ecx,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_487:
	/* 0x487: cmp    ebx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 60ULL);
x86_l_48a:
	/* 0x48a: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_48f:
	/* 0x48f: ja     636 <tail_nodeport_nat_egress_ipv6+0x636> */
	X86_SIM_X86_JCC(X86_CC_A, 0x48f, 0x636, x86_l_636);
x86_l_495:
	/* 0x495: mov    eax,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_32);
x86_l_497:
	/* 0x497: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_4a1:
	/* 0x4a1: bt     rdx,rax */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_4a5:
	/* 0x4a5: mov    r13,QWORD PTR [rip+0x88d7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_4ac:
	/* 0x4ac: jae    626 <tail_nodeport_nat_egress_ipv6+0x626> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x4ac, 0x626, x86_l_626);
x86_l_4b2:
	/* 0x4b2: mov    rax,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_4ba:
	/* 0x4ba: lea    ebp,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4bd:
	/* 0x4bd: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4c2:
	/* 0x4c2: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_4c7:
	/* 0x4c7: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4cb:
	/* 0x4cb: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_4cd:
	/* 0x4cd: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_4d2:
	/* 0x4d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d4:
	/* 0x4d4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4d6:
	/* 0x4d6: js     67d <tail_nodeport_nat_egress_ipv6+0x67d> */
	X86_SIM_X86_JCC(X86_CC_S, 0x4d6, 0x67d, x86_l_67d);
x86_l_4dc:
	/* 0x4dc: movzx  edx,BYTE PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_4e1:
	/* 0x4e1: cmp    ebx,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 43ULL);
x86_l_4e4:
	/* 0x4e4: jle    505 <tail_nodeport_nat_egress_ipv6+0x505> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x4e4, 0x505, x86_l_505);
x86_l_4e6:
	/* 0x4e6: cmp    ebx,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 44ULL);
x86_l_4e9:
	/* 0x4e9: je     52f <tail_nodeport_nat_egress_ipv6+0x52f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4e9, 0x52f, x86_l_52f);
x86_l_4eb:
	/* 0x4eb: cmp    ebx,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 51ULL);
x86_l_4ee:
	/* 0x4ee: jne    505 <tail_nodeport_nat_egress_ipv6+0x505> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4ee, 0x505, x86_l_505);
x86_l_4f0:
	/* 0x4f0: mov    rbx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R13, X86_WIDTH_64);
x86_l_4f3:
	/* 0x4f3: movzx  eax,BYTE PTR [rsp+0x11] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 17ULL);
x86_l_4f8:
	/* 0x4f8: lea    r13d,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_500:
	/* 0x500: jmp    5af <tail_nodeport_nat_egress_ipv6+0x5af> */
	X86_SIM_X86_JMP(0x500, 0x5af, x86_l_5af);
x86_l_505:
	/* 0x505: mov    rbx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R13, X86_WIDTH_64);
x86_l_508:
	/* 0x508: movzx  eax,BYTE PTR [rsp+0x11] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 17ULL);
x86_l_50d:
	/* 0x50d: lea    r13d,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_515:
	/* 0x515: cmp    r15b,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_8, 44ULL);
x86_l_519:
	/* 0x519: je     538 <tail_nodeport_nat_egress_ipv6+0x538> */
	X86_SIM_X86_JCC(X86_CC_E, 0x519, 0x538, x86_l_538);
x86_l_51b:
	/* 0x51b: jmp    5af <tail_nodeport_nat_egress_ipv6+0x5af> */
	X86_SIM_X86_JMP(0x51b, 0x5af, x86_l_5af);
x86_l_520:
	/* 0x520: mov    r15d,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSI, X86_WIDTH_32);
x86_l_523:
	/* 0x523: mov    r13,QWORD PTR [rip+0x88d7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_52a:
	/* 0x52a: jmp    6a3 <tail_nodeport_nat_egress_ipv6+0x6a3> */
	X86_SIM_X86_JMP(0x52a, 0x6a3, x86_l_6a3);
x86_l_52f:
	/* 0x52f: mov    rbx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R13, X86_WIDTH_64);
x86_l_532:
	/* 0x532: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_538:
	/* 0x538: mov    r15d,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_32);
x86_l_53b:
	/* 0x53b: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_544:
	/* 0x544: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_549:
	/* 0x549: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_54e:
	/* 0x54e: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_552:
	/* 0x552: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_554:
	/* 0x554: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_559:
	/* 0x559: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_55b:
	/* 0x55b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_55d:
	/* 0x55d: js     67d <tail_nodeport_nat_egress_ipv6+0x67d> */
	X86_SIM_X86_JCC(X86_CC_S, 0x55d, 0x67d, x86_l_67d);
x86_l_563:
	/* 0x563: mov    eax,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_567:
	/* 0x567: movzx  ecx,BYTE PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_56c:
	/* 0x56c: shl    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_570:
	/* 0x570: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_573:
	/* 0x573: movzx  eax,WORD PTR [rsp+0x12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18ULL);
x86_l_578:
	/* 0x578: movabs rdx,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1099511627776ULL);
x86_l_582:
	/* 0x582: or     rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_585:
	/* 0x585: test   eax,0xf9ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63999ULL);
x86_l_58a:
	/* 0x58a: cmove  rdx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_64, X86_CC_E);
x86_l_58e:
	/* 0x58e: movabs rcx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2199023255552ULL);
x86_l_598:
	/* 0x598: or     rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_OR);
x86_l_59b:
	/* 0x59b: test   eax,0xf8ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63743ULL);
x86_l_5a0:
	/* 0x5a0: cmove  rcx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_5a4:
	/* 0x5a4: mov    QWORD PTR [rsp+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_5ac:
	/* 0x5ac: mov    edx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_32);
x86_l_5af:
	/* 0x5af: movzx  ebp,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_5b2:
	/* 0x5b2: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b7:
	/* 0x5b7: add    eax,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_5ba:
	/* 0x5ba: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5bf:
	/* 0x5bf: cmp    ebp,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_5c2:
	/* 0x5c2: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5c6:
	/* 0x5c6: ja     695 <tail_nodeport_nat_egress_ipv6+0x695> */
	X86_SIM_X86_JCC(X86_CC_A, 0x5c6, 0x695, x86_l_695);
x86_l_5cc:
	/* 0x5cc: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_5ce:
	/* 0x5ce: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_5d8:
	/* 0x5d8: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_5dc:
	/* 0x5dc: jae    620 <tail_nodeport_nat_egress_ipv6+0x620> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x5dc, 0x620, x86_l_620);
x86_l_5de:
	/* 0x5de: mov    r15d,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_32);
x86_l_5e1:
	/* 0x5e1: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5e6:
	/* 0x5e6: add    esi,DWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RSI, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 136ULL);
x86_l_5ed:
	/* 0x5ed: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5f2:
	/* 0x5f2: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_5f7:
	/* 0x5f7: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_5fa:
	/* 0x5fa: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_5ff:
	/* 0x5ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_601:
	/* 0x601: mov    r14d,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4294967162ULL);
x86_l_607:
	/* 0x607: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_609:
	/* 0x609: js     683 <tail_nodeport_nat_egress_ipv6+0x683> */
	X86_SIM_X86_JCC(X86_CC_S, 0x609, 0x683, x86_l_683);
x86_l_60b:
	/* 0x60b: cmp    ebp,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 43ULL);
x86_l_60e:
	/* 0x60e: jle    63f <tail_nodeport_nat_egress_ipv6+0x63f> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x60e, 0x63f, x86_l_63f);
x86_l_610:
	/* 0x610: cmp    ebp,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 44ULL);
x86_l_613:
	/* 0x613: je     651 <tail_nodeport_nat_egress_ipv6+0x651> */
	X86_SIM_X86_JCC(X86_CC_E, 0x613, 0x651, x86_l_651);
x86_l_615:
	/* 0x615: cmp    ebp,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 51ULL);
x86_l_618:
	/* 0x618: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_61c:
	/* 0x61c: jne    643 <tail_nodeport_nat_egress_ipv6+0x643> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x61c, 0x643, x86_l_643);
x86_l_61e:
	/* 0x61e: jmp    675 <tail_nodeport_nat_egress_ipv6+0x675> */
	X86_SIM_X86_JMP(0x61e, 0x675, x86_l_675);
x86_l_620:
	/* 0x620: mov    r13,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBX, X86_WIDTH_64);
x86_l_623:
	/* 0x623: mov    r15d,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_32);
x86_l_626:
	/* 0x626: cmp    rax,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 59ULL);
x86_l_62a:
	/* 0x62a: mov    rcx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_632:
	/* 0x632: je     683 <tail_nodeport_nat_egress_ipv6+0x683> */
	X86_SIM_X86_JCC(X86_CC_E, 0x632, 0x683, x86_l_683);
x86_l_634:
	/* 0x634: jmp    6a3 <tail_nodeport_nat_egress_ipv6+0x6a3> */
	X86_SIM_X86_JMP(0x634, 0x6a3, x86_l_6a3);
x86_l_636:
	/* 0x636: mov    r13,QWORD PTR [rip+0x88d7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_63d:
	/* 0x63d: jmp    69b <tail_nodeport_nat_egress_ipv6+0x69b> */
	X86_SIM_X86_JMP(0x63d, 0x69b, x86_l_69b);
x86_l_63f:
	/* 0x63f: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_643:
	/* 0x643: mov    r14d,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4294967140ULL);
x86_l_649:
	/* 0x649: cmp    r15b,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_8, 44ULL);
x86_l_64d:
	/* 0x64d: jne    683 <tail_nodeport_nat_egress_ipv6+0x683> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x64d, 0x683, x86_l_683);
x86_l_64f:
	/* 0x64f: jmp    655 <tail_nodeport_nat_egress_ipv6+0x655> */
	X86_SIM_X86_JMP(0x64f, 0x655, x86_l_655);
x86_l_651:
	/* 0x651: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_655:
	/* 0x655: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_65e:
	/* 0x65e: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_663:
	/* 0x663: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_668:
	/* 0x668: mov    esi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_32);
x86_l_66a:
	/* 0x66a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_66f:
	/* 0x66f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_671:
	/* 0x671: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_673:
	/* 0x673: js     67d <tail_nodeport_nat_egress_ipv6+0x67d> */
	X86_SIM_X86_JCC(X86_CC_S, 0x673, 0x67d, x86_l_67d);
x86_l_675:
	/* 0x675: mov    r14d,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4294967140ULL);
x86_l_67b:
	/* 0x67b: jmp    683 <tail_nodeport_nat_egress_ipv6+0x683> */
	X86_SIM_X86_JMP(0x67b, 0x683, x86_l_683);
x86_l_67d:
	/* 0x67d: mov    r14d,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4294967162ULL);
x86_l_683:
	/* 0x683: mov    eax,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_32);
x86_l_686:
	/* 0x686: add    rsp,0x148 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 328ULL);
x86_l_68d:
	/* 0x68d: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_68f:
	/* 0x68f: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_690:
	/* 0x690: jmp    2184 <tail_nodeport_nat_egress_ipv6+0x2184> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_695:
	/* 0x695: mov    r15d,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_32);
x86_l_698:
	/* 0x698: mov    r13,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBX, X86_WIDTH_64);
x86_l_69b:
	/* 0x69b: mov    rcx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_6a3:
	/* 0x6a3: mov    QWORD PTR [rsp+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_6ab:
	/* 0x6ab: mov    BYTE PTR [rsp+0xc4],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_6b3:
	/* 0x6b3: movzx  ebx,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_6b8:
	/* 0x6b8: mov    WORD PTR [rsp+0x16],0x200 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 94489281024ULL);
x86_l_6bf:
	/* 0x6bf: mov    DWORD PTR [rsp+0x10],0xa0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476896ULL);
x86_l_6c7:
	/* 0x6c7: mov    rax,QWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6cc:
	/* 0x6cc: mov    rcx,QWORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6d1:
	/* 0x6d1: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6d6:
	/* 0x6d6: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6db:
	/* 0x6db: mov    WORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_6e2:
	/* 0x6e2: mov    rdi,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipcache_v2)));
x86_l_6e9:
	/* 0x6e9: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6ee:
	/* 0x6ee: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6f3:
	/* 0x6f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6f5:
	/* 0x6f5: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_6f8:
	/* 0x6f8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6fb:
	/* 0x6fb: je     734 <tail_nodeport_nat_egress_ipv6+0x734> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6fb, 0x734, x86_l_734);
x86_l_6fd:
	/* 0x6fd: movzx  eax,BYTE PTR [r14+0x17] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 23ULL);
x86_l_702:
	/* 0x702: and    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_AND, 3ULL);
x86_l_704:
	/* 0x704: cmp    al,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 2ULL);
x86_l_706:
	/* 0x706: jne    734 <tail_nodeport_nat_egress_ipv6+0x734> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x706, 0x734, x86_l_734);
x86_l_708:
	/* 0x708: mov    rax,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_router_ipv6)));
x86_l_70f:
	/* 0x70f: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_712:
	/* 0x712: mov    QWORD PTR [rsp+0xe0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_71a:
	/* 0x71a: mov    rax,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_71e:
	/* 0x71e: mov    QWORD PTR [rsp+0xd8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_726:
	/* 0x726: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_72a:
	/* 0x72a: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_72f:
	/* 0x72f: jmp    81e <tail_nodeport_nat_egress_ipv6+0x81e> */
	X86_SIM_X86_JMP(0x72f, 0x81e, x86_l_81e);
x86_l_734:
	/* 0x734: mov    rax,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_nodeport_source_lookup)));
x86_l_73b:
	/* 0x73b: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_73e:
	/* 0x73e: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_742:
	/* 0x742: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_747:
	/* 0x747: je     81e <tail_nodeport_nat_egress_ipv6+0x81e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x747, 0x81e, x86_l_81e);
x86_l_74d:
	/* 0x74d: mov    DWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_755:
	/* 0x755: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_75e:
	/* 0x75e: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_767:
	/* 0x767: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_770:
	/* 0x770: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_779:
	/* 0x779: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_782:
	/* 0x782: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_78b:
	/* 0x78b: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_794:
	/* 0x794: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_79d:
	/* 0x79d: mov    rax,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_supports_fib_lookup_src)));
x86_l_7a4:
	/* 0x7a4: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7a7:
	/* 0x7a7: je     81e <tail_nodeport_nat_egress_ipv6+0x81e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7a7, 0x81e, x86_l_81e);
x86_l_7a9:
	/* 0x7a9: mov    BYTE PTR [rsp+0x10],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68719476746ULL);
x86_l_7ae:
	/* 0x7ae: mov    eax,DWORD PTR [r15+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_7b2:
	/* 0x7b2: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_7b6:
	/* 0x7b6: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_7bf:
	/* 0x7bf: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_7c8:
	/* 0x7c8: mov    rax,QWORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7cd:
	/* 0x7cd: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_7d2:
	/* 0x7d2: mov    rax,QWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_7d7:
	/* 0x7d7: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7dc:
	/* 0x7dc: mov    rax,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_supports_fib_lookup_skip_neigh)));
x86_l_7e3:
	/* 0x7e3: movzx  ecx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_7e6:
	/* 0x7e6: shl    ecx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 2ULL);
x86_l_7e9:
	/* 0x7e9: or     ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_OR, 16ULL);
x86_l_7ec:
	/* 0x7ec: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7f1:
	/* 0x7f1: mov    eax,0x45 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 69ULL);
x86_l_7f6:
	/* 0x7f6: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_7f9:
	/* 0x7f9: mov    edx,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 64ULL);
x86_l_7fe:
	/* 0x7fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_800:
	/* 0x800: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_802:
	/* 0x802: jne    81e <tail_nodeport_nat_egress_ipv6+0x81e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x802, 0x81e, x86_l_81e);
x86_l_804:
	/* 0x804: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_809:
	/* 0x809: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_80e:
	/* 0x80e: mov    QWORD PTR [rsp+0xd8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_816:
	/* 0x816: mov    QWORD PTR [rsp+0xe0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_81e:
	/* 0x81e: mov    rax,QWORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_823:
	/* 0x823: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_82b:
	/* 0x82b: mov    rax,QWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_830:
	/* 0x830: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_838:
	/* 0x838: mov    rax,QWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_83d:
	/* 0x83d: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_845:
	/* 0x845: mov    rax,QWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_84a:
	/* 0x84a: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_852:
	/* 0x852: movzx  eax,BYTE PTR [rsp+0xc4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 196ULL);
x86_l_85a:
	/* 0x85a: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_85d:
	/* 0x85d: je     871 <tail_nodeport_nat_egress_ipv6+0x871> */
	X86_SIM_X86_JCC(X86_CC_E, 0x85d, 0x871, x86_l_871);
x86_l_85f:
	/* 0x85f: cmp    eax,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 58ULL);
x86_l_862:
	/* 0x862: je     8f0 <tail_nodeport_nat_egress_ipv6+0x8f0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x862, 0x8f0, x86_l_8f0);
x86_l_868:
	/* 0x868: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_86b:
	/* 0x86b: jne    8fd <tail_nodeport_nat_egress_ipv6+0x8fd> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x86b, 0x8fd, x86_l_8fd);
x86_l_871:
	/* 0x871: add    ebp,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_873:
	/* 0x873: movabs rdx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 2199023255552ULL);
x86_l_87d:
	/* 0x87d: lea    r13,[rsp+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_885:
	/* 0x885: mov    rax,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_88c:
	/* 0x88c: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_88f:
	/* 0x88f: je     907 <tail_nodeport_nat_egress_ipv6+0x907> */
	X86_SIM_X86_JCC(X86_CC_E, 0x88f, 0x907, x86_l_907);
x86_l_891:
	/* 0x891: mov    rbx,QWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_895:
	/* 0x895: mov    QWORD PTR [r12],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_89d:
	/* 0x89d: mov    rcx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_8a5:
	/* 0x8a5: mov    DWORD PTR [r12],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8a9:
	/* 0x8a9: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_8ac:
	/* 0x8ac: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_8b0:
	/* 0x8b0: mov    BYTE PTR [r12+0x4],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_8b5:
	/* 0x8b5: test   rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_8b8:
	/* 0x8b8: jne    1658 <tail_nodeport_nat_egress_ipv6+0x1658> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x8b8, 0x1658, x86_l_1658);
x86_l_8be:
	/* 0x8be: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_8c3:
	/* 0x8c3: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_8c6:
	/* 0x8c6: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_8c8:
	/* 0x8c8: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_8cb:
	/* 0x8cb: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_8d0:
	/* 0x8d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8d2:
	/* 0x8d2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_8d4:
	/* 0x8d4: js     9a6 <tail_nodeport_nat_egress_ipv6+0x9a6> */
	X86_SIM_X86_JCC(X86_CC_S, 0x8d4, 0x9a6, x86_l_9a6);
x86_l_8da:
	/* 0x8da: bt     QWORD PTR [rsp+0x80],0x28 */
	X86_SIM_L_EXEC_BT_MEM_IMM(X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 549755813928ULL);
x86_l_8e4:
	/* 0x8e4: jb     168d <tail_nodeport_nat_egress_ipv6+0x168d> */
	X86_SIM_X86_JCC(X86_CC_B, 0x8e4, 0x168d, x86_l_168d);
x86_l_8ea:
	/* 0x8ea: mov    QWORD PTR [r12],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8ee:
	/* 0x8ee: jmp    931 <tail_nodeport_nat_egress_ipv6+0x931> */
	X86_SIM_X86_JMP(0x8ee, 0x931, x86_l_931);
x86_l_8f0:
	/* 0x8f0: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8f3:
	/* 0x8f3: mov    ebp,0xffffff61 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967137ULL);
x86_l_8f8:
	/* 0x8f8: jmp    119 <tail_nodeport_nat_egress_ipv6+0x119> */
	X86_SIM_X86_JMP(0x8f8, 0x119, x86_l_119);
x86_l_8fd:
	/* 0x8fd: mov    ebp,0xffffff72 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967154ULL);
x86_l_902:
	/* 0x902: jmp    116 <tail_nodeport_nat_egress_ipv6+0x116> */
	X86_SIM_X86_JMP(0x902, 0x116, x86_l_116);
x86_l_907:
	/* 0x907: test   QWORD PTR [rsp+0x80],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_90f:
	/* 0x90f: jne    16f0 <tail_nodeport_nat_egress_ipv6+0x16f0> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x90f, 0x16f0, x86_l_16f0);
x86_l_915:
	/* 0x915: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_91a:
	/* 0x91a: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_91d:
	/* 0x91d: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_91f:
	/* 0x91f: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_922:
	/* 0x922: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_927:
	/* 0x927: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_929:
	/* 0x929: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_92b:
	/* 0x92b: js     caa <tail_nodeport_nat_egress_ipv6+0xcaa> */
	X86_SIM_X86_JCC(X86_CC_S, 0x92b, 0xcaa, x86_l_caa);
x86_l_931:
	/* 0x931: mov    QWORD PTR [rsp+0x8],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_936:
	/* 0x936: rol    DWORD PTR [rsp+0xc0],0x10 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_32, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_ROL)), 824633720848ULL);
x86_l_93e:
	/* 0x93e: mov    BYTE PTR [rsp+0xc5],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 846108557312ULL);
x86_l_946:
	/* 0x946: mov    rax,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_94d:
	/* 0x94d: movzx  ebx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_950:
	/* 0x950: lea    ebp,[rbx+0x7] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_953:
	/* 0x953: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_958:
	/* 0x958: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_95d:
	/* 0x95d: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_960:
	/* 0x960: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_962:
	/* 0x962: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_967:
	/* 0x967: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_969:
	/* 0x969: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_96b:
	/* 0x96b: js     111 <tail_nodeport_nat_egress_ipv6+0x111> */
	X86_SIM_X86_JCC(X86_CC_S, 0x96b, 0x111, x86_l_111);
x86_l_971:
	/* 0x971: movzx  eax,BYTE PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_976:
	/* 0x976: cmp    al,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 2ULL);
x86_l_978:
	/* 0x978: jae    9b4 <tail_nodeport_nat_egress_ipv6+0x9b4> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x978, 0x9b4, x86_l_9b4);
x86_l_97a:
	/* 0x97a: mov    DWORD PTR [r15+0x30],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_97e:
	/* 0x97e: mov    DWORD PTR [r15+0x34],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 223338299394ULL);
x86_l_986:
	/* 0x986: mov    rsi,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_98d:
	/* 0x98d: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_992:
	/* 0x992: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_995:
	/* 0x995: mov    edx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_99a:
	/* 0x99a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_99c:
	/* 0x99c: mov    ebp,0xffffff74 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967156ULL);
x86_l_9a1:
	/* 0x9a1: jmp    116 <tail_nodeport_nat_egress_ipv6+0x116> */
	X86_SIM_X86_JMP(0x9a1, 0x116, x86_l_116);
x86_l_9a6:
	/* 0x9a6: mov    ebp,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967161ULL);
x86_l_9ab:
	/* 0x9ab: mov    QWORD PTR [r12],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9af:
	/* 0x9af: jmp    116 <tail_nodeport_nat_egress_ipv6+0x116> */
	X86_SIM_X86_JMP(0x9af, 0x116, x86_l_116);
x86_l_9b4:
	/* 0x9b4: dec    al */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_DEC, 1);
x86_l_9b6:
	/* 0x9b6: mov    BYTE PTR [rsp+0x10],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9ba:
	/* 0x9ba: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9bf:
	/* 0x9bf: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_9c4:
	/* 0x9c4: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_9c7:
	/* 0x9c7: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_9c9:
	/* 0x9c9: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_9ce:
	/* 0x9ce: mov    r8d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 1ULL);
x86_l_9d4:
	/* 0x9d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9d6:
	/* 0x9d6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_9d8:
	/* 0x9d8: js     cb4 <tail_nodeport_nat_egress_ipv6+0xcb4> */
	X86_SIM_X86_JCC(X86_CC_S, 0x9d8, 0xcb4, x86_l_cb4);
x86_l_9de:
	/* 0x9de: mov    rdi,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_9e5:
	/* 0x9e5: lea    rsi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
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
	/* 0x9f7: je     b09 <tail_nodeport_nat_egress_ipv6+0xb09> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9f7, 0xb09, x86_l_b09);
x86_l_9fd:
	/* 0x9fd: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_a00:
	/* 0xa00: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a05:
	/* 0xa05: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a07:
	/* 0xa07: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_a09:
	/* 0xa09: mov    r15,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&_aux_stride)));
x86_l_a10:
	/* 0xa10: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a12:
	/* 0xa12: imul   rax,QWORD PTR [r15] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_a16:
	/* 0xa16: mov    rbx,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&_aux_max_off)));
x86_l_a1d:
	/* 0xa1d: cmp    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_a20:
	/* 0xa20: jbe    a25 <tail_nodeport_nat_egress_ipv6+0xa25> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xa20, 0xa25, x86_l_a25);
x86_l_a22:
	/* 0xa22: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a25:
	/* 0xa25: mov    rcx,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__aux_snat_v6_nhm_tuple)));
x86_l_a2c:
	/* 0xa2c: mov    BYTE PTR [rcx+rax*1+0x25],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 158913789953ULL);
x86_l_a31:
	/* 0xa31: movzx  edx,BYTE PTR [rsp+0xc4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 196ULL);
x86_l_a39:
	/* 0xa39: mov    BYTE PTR [rcx+rax*1+0x24],dl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 36ULL);
x86_l_a3d:
	/* 0xa3d: mov    rdx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_a45:
	/* 0xa45: mov    rsi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_a4d:
	/* 0xa4d: mov    QWORD PTR [rcx+rax*1+0x10],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 16ULL);
x86_l_a52:
	/* 0xa52: mov    QWORD PTR [rcx+rax*1+0x18],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 24ULL);
x86_l_a57:
	/* 0xa57: mov    rdx,QWORD PTR [r13+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a5b:
	/* 0xa5b: mov    rsi,QWORD PTR [r13+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a5f:
	/* 0xa5f: mov    QWORD PTR [rcx+rax*1],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_a63:
	/* 0xa63: mov    QWORD PTR [rcx+rax*1+0x8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 8ULL);
x86_l_a68:
	/* 0xa68: movzx  edx,WORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 192ULL);
x86_l_a70:
	/* 0xa70: mov    WORD PTR [rcx+rax*1+0x22],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 0), 34ULL);
x86_l_a75:
	/* 0xa75: movzx  edx,WORD PTR [r13+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_a7a:
	/* 0xa7a: lea    r12,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_a7e:
	/* 0xa7e: mov    WORD PTR [rcx+rax*1+0x20],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 0), 32ULL);
x86_l_a83:
	/* 0xa83: mov    rax,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_a8b:
	/* 0xa8b: cmp    rax,QWORD PTR [r13+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_a8f:
	/* 0xa8f: mov    QWORD PTR [rsp+0x88],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_a97:
	/* 0xa97: jne    ab2 <tail_nodeport_nat_egress_ipv6+0xab2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa97, 0xab2, x86_l_ab2);
x86_l_a99:
	/* 0xa99: mov    rax,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_aa1:
	/* 0xaa1: cmp    rax,QWORD PTR [r13+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_aa5:
	/* 0xaa5: jne    ab2 <tail_nodeport_nat_egress_ipv6+0xab2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xaa5, 0xab2, x86_l_ab2);
x86_l_aa7:
	/* 0xaa7: cmp    QWORD PTR [r13+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_aac:
	/* 0xaac: je     14e0 <tail_nodeport_nat_egress_ipv6+0x14e0> */
	X86_SIM_X86_JCC(X86_CC_E, 0xaac, 0x14e0, x86_l_14e0);
x86_l_ab2:
	/* 0xab2: mov    rdi,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_ab9:
	/* 0xab9: lea    rsi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_ac1:
	/* 0xac1: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_ac6:
	/* 0xac6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ac8:
	/* 0xac8: mov    ebp,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_aca:
	/* 0xaca: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_acd:
	/* 0xacd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_acf:
	/* 0xacf: js     177a <tail_nodeport_nat_egress_ipv6+0x177a> */
	X86_SIM_X86_JCC(X86_CC_S, 0xacf, 0x177a, x86_l_177a);
x86_l_ad5:
	/* 0xad5: cmp    ebp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_ad8:
	/* 0xad8: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_adc:
	/* 0xadc: je     18b3 <tail_nodeport_nat_egress_ipv6+0x18b3> */
	X86_SIM_X86_JCC(X86_CC_E, 0xadc, 0x18b3, x86_l_18b3);
x86_l_ae2:
	/* 0xae2: mov    rdi,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_ae9:
	/* 0xae9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_aee:
	/* 0xaee: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_af1:
	/* 0xaf1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_af3:
	/* 0xaf3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_af6:
	/* 0xaf6: je     b09 <tail_nodeport_nat_egress_ipv6+0xb09> */
	X86_SIM_X86_JCC(X86_CC_E, 0xaf6, 0xb09, x86_l_b09);
x86_l_af8:
	/* 0xaf8: mov    rdi,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_aff:
	/* 0xaff: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_b04:
	/* 0xb04: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_b07:
	/* 0xb07: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b09:
	/* 0xb09: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_b11:
	/* 0xb11: lea    ebp,[rax+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_b14:
	/* 0xb14: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_b19:
	/* 0xb19: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b1b:
	/* 0xb1b: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_b1d:
	/* 0xb1d: mov    rcx,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&_aux_stride)));
x86_l_b24:
	/* 0xb24: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b26:
	/* 0xb26: imul   rax,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_b2a:
	/* 0xb2a: mov    rcx,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&_aux_max_off)));
x86_l_b31:
	/* 0xb31: cmp    rax,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_b34:
	/* 0xb34: jbe    b39 <tail_nodeport_nat_egress_ipv6+0xb39> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xb34, 0xb39, x86_l_b39);
x86_l_b36:
	/* 0xb36: mov    rax,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b39:
	/* 0xb39: mov    rcx,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__aux_snat_v6_nhm_nat_entry)));
x86_l_b40:
	/* 0xb40: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_b49:
	/* 0xb49: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_b52:
	/* 0xb52: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_b5b:
	/* 0xb5b: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_b64:
	/* 0xb64: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_b6d:
	/* 0xb6d: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_b76:
	/* 0xb76: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_b7f:
	/* 0xb7f: mov    QWORD PTR [rcx+rax*1],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_b87:
	/* 0xb87: mov    QWORD PTR [rcx+rax*1+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 34359738368ULL);
x86_l_b90:
	/* 0xb90: mov    QWORD PTR [rcx+rax*1+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 68719476736ULL);
x86_l_b99:
	/* 0xb99: mov    QWORD PTR [rcx+rax*1+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 103079215104ULL);
x86_l_ba2:
	/* 0xba2: mov    QWORD PTR [rcx+rax*1+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 137438953472ULL);
x86_l_bab:
	/* 0xbab: mov    QWORD PTR [rcx+rax*1+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 171798691840ULL);
x86_l_bb4:
	/* 0xbb4: mov    QWORD PTR [rcx+rax*1+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 206158430208ULL);
x86_l_bbd:
	/* 0xbbd: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_bc5:
	/* 0xbc5: mov    rdx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bc8:
	/* 0xbc8: mov    rsi,QWORD PTR [rsi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bcc:
	/* 0xbcc: mov    QWORD PTR [rsp+0x30],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_bd1:
	/* 0xbd1: mov    QWORD PTR [rsp+0x38],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_bd6:
	/* 0xbd6: movzx  ebx,WORD PTR [rsp+0xc2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 194ULL);
x86_l_bde:
	/* 0xbde: mov    WORD PTR [rsp+0x40],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_be3:
	/* 0xbe3: mov    rdx,QWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_beb:
	/* 0xbeb: mov    QWORD PTR [rcx+rax*1+0x20],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 32ULL);
x86_l_bf0:
	/* 0xbf0: mov    rsi,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_bf8:
	/* 0xbf8: mov    QWORD PTR [rcx+rax*1+0x28],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 40ULL);
x86_l_bfd:
	/* 0xbfd: mov    BYTE PTR [rsp+0x7d],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 536870912001ULL);
x86_l_c02:
	/* 0xc02: movzx  edi,BYTE PTR [rsp+0xc4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 196ULL);
x86_l_c0a:
	/* 0xc0a: mov    BYTE PTR [rsp+0x7c],dil */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_c0f:
	/* 0xc0f: mov    rdi,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_c17:
	/* 0xc17: mov    QWORD PTR [rsp+0x68],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_c1c:
	/* 0xc1c: mov    rdi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_c24:
	/* 0xc24: mov    QWORD PTR [rsp+0x70],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_c29:
	/* 0xc29: mov    QWORD PTR [rsp+0x60],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_c2e:
	/* 0xc2e: mov    QWORD PTR [rsp+0x58],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_c33:
	/* 0xc33: movzx  edx,WORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 192ULL);
x86_l_c3b:
	/* 0xc3b: mov    WORD PTR [rsp+0x7a],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 122ULL);
x86_l_c40:
	/* 0xc40: lea    r15,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_c44:
	/* 0xc44: mov    WORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_c4b:
	/* 0xc4b: rol    bx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_c4f:
	/* 0xc4f: cmp    bx,bp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_RBP, X86_WIDTH_16);
x86_l_c52:
	/* 0xc52: jae    c76 <tail_nodeport_nat_egress_ipv6+0xc76> */
	X86_SIM_X86_JCC(X86_CC_AE, 0xc52, 0xc76, x86_l_c76);
x86_l_c54:
	/* 0xc54: mov    ecx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_c59:
	/* 0xc59: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c5b:
	/* 0xc5b: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_c5d:
	/* 0xc5d: mov    rcx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_c65:
	/* 0xc65: xor    ecx,0xffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 65535ULL);
x86_l_c6b:
	/* 0xc6b: movzx  ebx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_c6e:
	/* 0xc6e: imul   ebx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_c71:
	/* 0xc71: shr    ebx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_c74:
	/* 0xc74: add    ebx,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_c76:
	/* 0xc76: mov    QWORD PTR [r15+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_c7e:
	/* 0xc7e: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_c87:
	/* 0xc87: mov    rax,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_c8e:
	/* 0xc8e: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c91:
	/* 0xc91: mov    QWORD PTR [rsp+0x88],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_c99:
	/* 0xc99: je     cbe <tail_nodeport_nat_egress_ipv6+0xcbe> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc99, 0xcbe, x86_l_cbe);
x86_l_c9b:
	/* 0xc9b: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_ca0:
	/* 0xca0: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ca2:
	/* 0xca2: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_ca4:
	/* 0xca4: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_ca8:
	/* 0xca8: jmp    ce1 <tail_nodeport_nat_egress_ipv6+0xce1> */
	X86_SIM_X86_JMP(0xca8, 0xce1, x86_l_ce1);
x86_l_caa:
	/* 0xcaa: mov    ebp,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967161ULL);
x86_l_caf:
	/* 0xcaf: jmp    116 <tail_nodeport_nat_egress_ipv6+0x116> */
	X86_SIM_X86_JMP(0xcaf, 0x116, x86_l_116);
x86_l_cb4:
	/* 0xcb4: mov    ebp,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967155ULL);
x86_l_cb9:
	/* 0xcb9: jmp    116 <tail_nodeport_nat_egress_ipv6+0x116> */
	X86_SIM_X86_JMP(0xcb9, 0x116, x86_l_116);
x86_l_cbe:
	/* 0xcbe: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_cc3:
	/* 0xcc3: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_cc5:
	/* 0xcc5: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_cc7:
	/* 0xcc7: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_ccb:
	/* 0xccb: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_cd5:
	/* 0xcd5: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_cd8:
	/* 0xcd8: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_cdd:
	/* 0xcdd: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_ce1:
	/* 0xce1: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ce6:
	/* 0xce6: movbe  WORD PTR [rsp+0x78],bx */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_RBX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 120ULL);
x86_l_ced:
	/* 0xced: mov    rdi,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_cf4:
	/* 0xcf4: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_cf9:
	/* 0xcf9: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_cfe:
	/* 0xcfe: mov    r13d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 1ULL);
x86_l_d04:
	/* 0xd04: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_d09:
	/* 0xd09: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_d0e:
	/* 0xd0e: call   rbx */
	X86_SIM_BPF_CALL_REG(X86_RBX);
x86_l_d10:
	/* 0xd10: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_d12:
	/* 0xd12: je     14bc <tail_nodeport_nat_egress_ipv6+0x14bc> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd12, 0x14bc, x86_l_14bc);
x86_l_d18:
	/* 0xd18: mov    eax,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967294ULL);
x86_l_d1d:
	/* 0xd1d: sub    eax,DWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 152ULL);
x86_l_d24:
	/* 0xd24: movzx  r15d,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_d28:
	/* 0xd28: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_d2b:
	/* 0xd2b: mov    ecx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_d30:
	/* 0xd30: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d32:
	/* 0xd32: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_d34:
	/* 0xd34: movzx  r12d,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_d38:
	/* 0xd38: imul   r12d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_d3c:
	/* 0xd3c: shr    r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_d40:
	/* 0xd40: add    r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_d43:
	/* 0xd43: movbe  WORD PTR [rsp+0x78],r12w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 120ULL);
x86_l_d4b:
	/* 0xd4b: mov    rdi,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_d52:
	/* 0xd52: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_d57:
	/* 0xd57: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d5c:
	/* 0xd5c: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_d61:
	/* 0xd61: call   rbx */
	X86_SIM_BPF_CALL_REG(X86_RBX);
x86_l_d63:
	/* 0xd63: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d65:
	/* 0xd65: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_d67:
	/* 0xd67: je     17fb <tail_nodeport_nat_egress_ipv6+0x17fb> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd67, 0x17fb, x86_l_17fb);
x86_l_d6d:
	/* 0xd6d: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_d70:
	/* 0xd70: movzx  r12d,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_d74:
	/* 0xd74: imul   r12d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_d78:
	/* 0xd78: shr    r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_d7c:
	/* 0xd7c: add    r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_d7f:
	/* 0xd7f: movbe  WORD PTR [rsp+0x78],r12w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 120ULL);
x86_l_d87:
	/* 0xd87: mov    rdi,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_d8e:
	/* 0xd8e: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_d93:
	/* 0xd93: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d98:
	/* 0xd98: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_d9d:
	/* 0xd9d: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_da2:
	/* 0xda2: call   rbx */
	X86_SIM_BPF_CALL_REG(X86_RBX);
x86_l_da4:
	/* 0xda4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_da6:
	/* 0xda6: je     14c6 <tail_nodeport_nat_egress_ipv6+0x14c6> */
	X86_SIM_X86_JCC(X86_CC_E, 0xda6, 0x14c6, x86_l_14c6);
x86_l_dac:
	/* 0xdac: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_daf:
	/* 0xdaf: movzx  r12d,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_db3:
	/* 0xdb3: imul   r12d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_db7:
	/* 0xdb7: shr    r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_dbb:
	/* 0xdbb: add    r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_dbe:
	/* 0xdbe: movbe  WORD PTR [rsp+0x78],r12w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 120ULL);
x86_l_dc6:
	/* 0xdc6: mov    rdi,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_dcd:
	/* 0xdcd: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_dd2:
	/* 0xdd2: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_dd7:
	/* 0xdd7: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_ddc:
	/* 0xddc: call   rbx */
	X86_SIM_BPF_CALL_REG(X86_RBX);
x86_l_dde:
	/* 0xdde: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_de0:
	/* 0xde0: je     14d3 <tail_nodeport_nat_egress_ipv6+0x14d3> */
	X86_SIM_X86_JCC(X86_CC_E, 0xde0, 0x14d3, x86_l_14d3);
x86_l_de6:
	/* 0xde6: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_de9:
	/* 0xde9: movzx  r12d,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_ded:
	/* 0xded: imul   r12d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_df1:
	/* 0xdf1: shr    r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_df5:
	/* 0xdf5: add    r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_df8:
	/* 0xdf8: movbe  WORD PTR [rsp+0x78],r12w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 120ULL);
x86_l_e00:
	/* 0xe00: mov    rdi,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_e07:
	/* 0xe07: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_e0c:
	/* 0xe0c: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e11:
	/* 0xe11: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_e16:
	/* 0xe16: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_e1b:
	/* 0xe1b: call   rbx */
	X86_SIM_BPF_CALL_REG(X86_RBX);
x86_l_e1d:
	/* 0xe1d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_e1f:
	/* 0xe1f: je     159b <tail_nodeport_nat_egress_ipv6+0x159b> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe1f, 0x159b, x86_l_159b);
x86_l_e25:
	/* 0xe25: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_e28:
	/* 0xe28: movzx  r12d,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_e2c:
	/* 0xe2c: imul   r12d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_e30:
	/* 0xe30: shr    r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_e34:
	/* 0xe34: add    r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_e37:
	/* 0xe37: movbe  WORD PTR [rsp+0x78],r12w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 120ULL);
x86_l_e3f:
	/* 0xe3f: mov    rdi,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_e46:
	/* 0xe46: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_e4b:
	/* 0xe4b: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e50:
	/* 0xe50: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_e55:
	/* 0xe55: call   rbx */
	X86_SIM_BPF_CALL_REG(X86_RBX);
x86_l_e57:
	/* 0xe57: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_e59:
	/* 0xe59: je     15a8 <tail_nodeport_nat_egress_ipv6+0x15a8> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe59, 0x15a8, x86_l_15a8);
x86_l_e5f:
	/* 0xe5f: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_e62:
	/* 0xe62: movzx  r12d,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_e66:
	/* 0xe66: imul   r12d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_e6a:
	/* 0xe6a: shr    r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_e6e:
	/* 0xe6e: add    r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_e71:
	/* 0xe71: movbe  WORD PTR [rsp+0x78],r12w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 120ULL);
x86_l_e79:
	/* 0xe79: mov    rdi,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_e80:
	/* 0xe80: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_e85:
	/* 0xe85: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e8a:
	/* 0xe8a: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_e8f:
	/* 0xe8f: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_e94:
	/* 0xe94: call   rbx */
	X86_SIM_BPF_CALL_REG(X86_RBX);
x86_l_e96:
	/* 0xe96: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_e98:
	/* 0xe98: je     15b5 <tail_nodeport_nat_egress_ipv6+0x15b5> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe98, 0x15b5, x86_l_15b5);
x86_l_e9e:
	/* 0xe9e: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_ea1:
	/* 0xea1: movzx  r12d,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_ea5:
	/* 0xea5: imul   r12d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_ea9:
	/* 0xea9: shr    r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_ead:
	/* 0xead: add    r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_eb0:
	/* 0xeb0: movbe  WORD PTR [rsp+0x78],r12w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 120ULL);
x86_l_eb8:
	/* 0xeb8: mov    rdi,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_ebf:
	/* 0xebf: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_ec4:
	/* 0xec4: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ec9:
	/* 0xec9: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_ece:
	/* 0xece: call   rbx */
	X86_SIM_BPF_CALL_REG(X86_RBX);
x86_l_ed0:
	/* 0xed0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ed2:
	/* 0xed2: je     15c2 <tail_nodeport_nat_egress_ipv6+0x15c2> */
	X86_SIM_X86_JCC(X86_CC_E, 0xed2, 0x15c2, x86_l_15c2);
x86_l_ed8:
	/* 0xed8: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_edb:
	/* 0xedb: movzx  r12d,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_edf:
	/* 0xedf: imul   r12d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_ee3:
	/* 0xee3: shr    r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_ee7:
	/* 0xee7: add    r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_eea:
	/* 0xeea: movbe  WORD PTR [rsp+0x78],r12w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 120ULL);
x86_l_ef2:
	/* 0xef2: mov    rdi,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_ef9:
	/* 0xef9: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_efe:
	/* 0xefe: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f03:
	/* 0xf03: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_f08:
	/* 0xf08: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_f0d:
	/* 0xf0d: call   rbx */
	X86_SIM_BPF_CALL_REG(X86_RBX);
x86_l_f0f:
	/* 0xf0f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_f11:
	/* 0xf11: je     1631 <tail_nodeport_nat_egress_ipv6+0x1631> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf11, 0x1631, x86_l_1631);
x86_l_f17:
	/* 0xf17: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_f1a:
	/* 0xf1a: movzx  r12d,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_f1e:
	/* 0xf1e: imul   r12d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_f22:
	/* 0xf22: shr    r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_f26:
	/* 0xf26: add    r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_f29:
	/* 0xf29: movbe  WORD PTR [rsp+0x78],r12w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 120ULL);
x86_l_f31:
	/* 0xf31: mov    rdi,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_f38:
	/* 0xf38: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_f3d:
	/* 0xf3d: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f42:
	/* 0xf42: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_f47:
	/* 0xf47: call   rbx */
	X86_SIM_BPF_CALL_REG(X86_RBX);
x86_l_f49:
	/* 0xf49: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_f4b:
	/* 0xf4b: je     163e <tail_nodeport_nat_egress_ipv6+0x163e> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf4b, 0x163e, x86_l_163e);
x86_l_f51:
	/* 0xf51: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_f54:
	/* 0xf54: movzx  r12d,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_f58:
	/* 0xf58: imul   r12d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_f5c:
	/* 0xf5c: shr    r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_f60:
	/* 0xf60: add    r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_f63:
	/* 0xf63: movbe  WORD PTR [rsp+0x78],r12w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 120ULL);
x86_l_f6b:
	/* 0xf6b: mov    rdi,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_f72:
	/* 0xf72: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_f77:
	/* 0xf77: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f7c:
	/* 0xf7c: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_f81:
	/* 0xf81: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_f86:
	/* 0xf86: call   rbx */
	X86_SIM_BPF_CALL_REG(X86_RBX);
x86_l_f88:
	/* 0xf88: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_f8a:
	/* 0xf8a: je     164b <tail_nodeport_nat_egress_ipv6+0x164b> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf8a, 0x164b, x86_l_164b);
x86_l_f90:
	/* 0xf90: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_f93:
	/* 0xf93: movzx  r12d,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_f97:
	/* 0xf97: imul   r12d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_f9b:
	/* 0xf9b: shr    r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_f9f:
	/* 0xf9f: add    r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_fa2:
	/* 0xfa2: movbe  WORD PTR [rsp+0x78],r12w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 120ULL);
x86_l_faa:
	/* 0xfaa: mov    rdi,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_fb1:
	/* 0xfb1: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_fb6:
	/* 0xfb6: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_fbb:
	/* 0xfbb: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_fc0:
	/* 0xfc0: call   rbx */
	X86_SIM_BPF_CALL_REG(X86_RBX);
x86_l_fc2:
	/* 0xfc2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_fc4:
	/* 0xfc4: je     1680 <tail_nodeport_nat_egress_ipv6+0x1680> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfc4, 0x1680, x86_l_1680);
x86_l_fca:
	/* 0xfca: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_fcd:
	/* 0xfcd: movzx  r12d,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_fd1:
	/* 0xfd1: imul   r12d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_fd5:
	/* 0xfd5: shr    r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_fd9:
	/* 0xfd9: add    r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_fdc:
	/* 0xfdc: movbe  WORD PTR [rsp+0x78],r12w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 120ULL);
x86_l_fe4:
	/* 0xfe4: mov    rdi,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_feb:
	/* 0xfeb: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_ff0:
	/* 0xff0: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ff5:
	/* 0xff5: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_ffa:
	/* 0xffa: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_fff:
	/* 0xfff: call   rbx */
	X86_SIM_BPF_CALL_REG(X86_RBX);
x86_l_1001:
	/* 0x1001: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1003:
	/* 0x1003: je     16fa <tail_nodeport_nat_egress_ipv6+0x16fa> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1003, 0x16fa, x86_l_16fa);
x86_l_1009:
	/* 0x1009: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_100c:
	/* 0x100c: movzx  r12d,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1010:
	/* 0x1010: imul   r12d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_1014:
	/* 0x1014: shr    r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1018:
	/* 0x1018: add    r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_101b:
	/* 0x101b: movbe  WORD PTR [rsp+0x78],r12w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 120ULL);
x86_l_1023:
	/* 0x1023: mov    rdi,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_102a:
	/* 0x102a: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_102f:
	/* 0x102f: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1034:
	/* 0x1034: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1039:
	/* 0x1039: call   rbx */
	X86_SIM_BPF_CALL_REG(X86_RBX);
x86_l_103b:
	/* 0x103b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_103d:
	/* 0x103d: je     1715 <tail_nodeport_nat_egress_ipv6+0x1715> */
	X86_SIM_X86_JCC(X86_CC_E, 0x103d, 0x1715, x86_l_1715);
x86_l_1043:
	/* 0x1043: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1046:
	/* 0x1046: movzx  r12d,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_104a:
	/* 0x104a: imul   r12d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_104e:
	/* 0x104e: shr    r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1052:
	/* 0x1052: add    r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1055:
	/* 0x1055: movbe  WORD PTR [rsp+0x78],r12w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 120ULL);
x86_l_105d:
	/* 0x105d: mov    rdi,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_1064:
	/* 0x1064: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1069:
	/* 0x1069: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_106e:
	/* 0x106e: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_1073:
	/* 0x1073: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1078:
	/* 0x1078: call   rbx */
	X86_SIM_BPF_CALL_REG(X86_RBX);
x86_l_107a:
	/* 0x107a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_107c:
	/* 0x107c: je     1722 <tail_nodeport_nat_egress_ipv6+0x1722> */
	X86_SIM_X86_JCC(X86_CC_E, 0x107c, 0x1722, x86_l_1722);
x86_l_1082:
	/* 0x1082: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1085:
	/* 0x1085: movzx  r12d,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1089:
	/* 0x1089: imul   r12d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_108d:
	/* 0x108d: shr    r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1091:
	/* 0x1091: add    r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1094:
	/* 0x1094: movbe  WORD PTR [rsp+0x78],r12w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 120ULL);
x86_l_109c:
	/* 0x109c: mov    rdi,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_10a3:
	/* 0x10a3: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_10a8:
	/* 0x10a8: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10ad:
	/* 0x10ad: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_10b2:
	/* 0x10b2: call   rbx */
	X86_SIM_BPF_CALL_REG(X86_RBX);
x86_l_10b4:
	/* 0x10b4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_10b6:
	/* 0x10b6: je     1760 <tail_nodeport_nat_egress_ipv6+0x1760> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10b6, 0x1760, x86_l_1760);
x86_l_10bc:
	/* 0x10bc: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_10bf:
	/* 0x10bf: movzx  r12d,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_10c3:
	/* 0x10c3: imul   r12d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_10c7:
	/* 0x10c7: shr    r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_10cb:
	/* 0x10cb: add    r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_10ce:
	/* 0x10ce: movbe  WORD PTR [rsp+0x78],r12w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 120ULL);
x86_l_10d6:
	/* 0x10d6: mov    rdi,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_10dd:
	/* 0x10dd: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_10e2:
	/* 0x10e2: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10e7:
	/* 0x10e7: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_10ec:
	/* 0x10ec: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_10f1:
	/* 0x10f1: call   rbx */
	X86_SIM_BPF_CALL_REG(X86_RBX);
x86_l_10f3:
	/* 0x10f3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_10f5:
	/* 0x10f5: je     176d <tail_nodeport_nat_egress_ipv6+0x176d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10f5, 0x176d, x86_l_176d);
x86_l_10fb:
	/* 0x10fb: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_10fe:
	/* 0x10fe: movzx  r12d,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1102:
	/* 0x1102: imul   r12d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_1106:
	/* 0x1106: shr    r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_110a:
	/* 0x110a: add    r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_110d:
	/* 0x110d: movbe  WORD PTR [rsp+0x78],r12w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 120ULL);
x86_l_1115:
	/* 0x1115: mov    rdi,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_111c:
	/* 0x111c: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1121:
	/* 0x1121: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1126:
	/* 0x1126: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_112b:
	/* 0x112b: call   rbx */
	X86_SIM_BPF_CALL_REG(X86_RBX);
x86_l_112d:
	/* 0x112d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_112f:
	/* 0x112f: je     1783 <tail_nodeport_nat_egress_ipv6+0x1783> */
	X86_SIM_X86_JCC(X86_CC_E, 0x112f, 0x1783, x86_l_1783);
x86_l_1135:
	/* 0x1135: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1138:
	/* 0x1138: movzx  r12d,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_113c:
	/* 0x113c: imul   r12d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_1140:
	/* 0x1140: shr    r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1144:
	/* 0x1144: add    r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1147:
	/* 0x1147: movbe  WORD PTR [rsp+0x78],r12w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 120ULL);
x86_l_114f:
	/* 0x114f: mov    rdi,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_1156:
	/* 0x1156: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_115b:
	/* 0x115b: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1160:
	/* 0x1160: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_1165:
	/* 0x1165: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_116a:
	/* 0x116a: call   rbx */
	X86_SIM_BPF_CALL_REG(X86_RBX);
x86_l_116c:
	/* 0x116c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_116e:
	/* 0x116e: je     178b <tail_nodeport_nat_egress_ipv6+0x178b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x116e, 0x178b, x86_l_178b);
x86_l_1174:
	/* 0x1174: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1177:
	/* 0x1177: movzx  r12d,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_117b:
	/* 0x117b: imul   r12d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_117f:
	/* 0x117f: shr    r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1183:
	/* 0x1183: add    r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1186:
	/* 0x1186: movbe  WORD PTR [rsp+0x78],r12w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 120ULL);
x86_l_118e:
	/* 0x118e: mov    rdi,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_1195:
	/* 0x1195: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_119a:
	/* 0x119a: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_119f:
	/* 0x119f: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_11a4:
	/* 0x11a4: call   rbx */
	X86_SIM_BPF_CALL_REG(X86_RBX);
x86_l_11a6:
	/* 0x11a6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_11a8:
	/* 0x11a8: je     1793 <tail_nodeport_nat_egress_ipv6+0x1793> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11a8, 0x1793, x86_l_1793);
x86_l_11ae:
	/* 0x11ae: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_11b1:
	/* 0x11b1: movzx  r12d,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_11b5:
	/* 0x11b5: imul   r12d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_11b9:
	/* 0x11b9: shr    r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_11bd:
	/* 0x11bd: add    r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_11c0:
	/* 0x11c0: movbe  WORD PTR [rsp+0x78],r12w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 120ULL);
x86_l_11c8:
	/* 0x11c8: mov    rdi,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_11cf:
	/* 0x11cf: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_11d4:
	/* 0x11d4: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11d9:
	/* 0x11d9: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_11de:
	/* 0x11de: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_11e3:
	/* 0x11e3: call   rbx */
	X86_SIM_BPF_CALL_REG(X86_RBX);
x86_l_11e5:
	/* 0x11e5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_11e7:
	/* 0x11e7: je     179b <tail_nodeport_nat_egress_ipv6+0x179b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11e7, 0x179b, x86_l_179b);
x86_l_11ed:
	/* 0x11ed: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_11f0:
	/* 0x11f0: movzx  r12d,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_11f4:
	/* 0x11f4: imul   r12d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_11f8:
	/* 0x11f8: shr    r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_11fc:
	/* 0x11fc: add    r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_11ff:
	/* 0x11ff: movbe  WORD PTR [rsp+0x78],r12w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 120ULL);
x86_l_1207:
	/* 0x1207: mov    rdi,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_120e:
	/* 0x120e: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1213:
	/* 0x1213: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1218:
	/* 0x1218: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_121d:
	/* 0x121d: call   rbx */
	X86_SIM_BPF_CALL_REG(X86_RBX);
x86_l_121f:
	/* 0x121f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1221:
	/* 0x1221: je     17a3 <tail_nodeport_nat_egress_ipv6+0x17a3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1221, 0x17a3, x86_l_17a3);
x86_l_1227:
	/* 0x1227: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_122a:
	/* 0x122a: movzx  r12d,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_122e:
	/* 0x122e: imul   r12d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_1232:
	/* 0x1232: shr    r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1236:
	/* 0x1236: add    r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1239:
	/* 0x1239: movbe  WORD PTR [rsp+0x78],r12w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 120ULL);
x86_l_1241:
	/* 0x1241: mov    rdi,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_1248:
	/* 0x1248: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_124d:
	/* 0x124d: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1252:
	/* 0x1252: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_1257:
	/* 0x1257: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_125c:
	/* 0x125c: call   rbx */
	X86_SIM_BPF_CALL_REG(X86_RBX);
x86_l_125e:
	/* 0x125e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1260:
	/* 0x1260: je     17ab <tail_nodeport_nat_egress_ipv6+0x17ab> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1260, 0x17ab, x86_l_17ab);
x86_l_1266:
	/* 0x1266: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1269:
	/* 0x1269: movzx  r12d,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_126d:
	/* 0x126d: imul   r12d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_1271:
	/* 0x1271: shr    r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1275:
	/* 0x1275: add    r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1278:
	/* 0x1278: movbe  WORD PTR [rsp+0x78],r12w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 120ULL);
x86_l_1280:
	/* 0x1280: mov    rdi,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_1287:
	/* 0x1287: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_128c:
	/* 0x128c: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1291:
	/* 0x1291: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1296:
	/* 0x1296: call   rbx */
	X86_SIM_BPF_CALL_REG(X86_RBX);
x86_l_1298:
	/* 0x1298: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_129a:
	/* 0x129a: je     17b3 <tail_nodeport_nat_egress_ipv6+0x17b3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x129a, 0x17b3, x86_l_17b3);
x86_l_12a0:
	/* 0x12a0: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_12a3:
	/* 0x12a3: movzx  r12d,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_12a7:
	/* 0x12a7: imul   r12d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_12ab:
	/* 0x12ab: shr    r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_12af:
	/* 0x12af: add    r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_12b2:
	/* 0x12b2: movbe  WORD PTR [rsp+0x78],r12w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 120ULL);
x86_l_12ba:
	/* 0x12ba: mov    rdi,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_12c1:
	/* 0x12c1: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_12c6:
	/* 0x12c6: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12cb:
	/* 0x12cb: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_12d0:
	/* 0x12d0: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_12d5:
	/* 0x12d5: call   rbx */
	X86_SIM_BPF_CALL_REG(X86_RBX);
x86_l_12d7:
	/* 0x12d7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_12d9:
	/* 0x12d9: je     17bb <tail_nodeport_nat_egress_ipv6+0x17bb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12d9, 0x17bb, x86_l_17bb);
x86_l_12df:
	/* 0x12df: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_12e2:
	/* 0x12e2: movzx  r12d,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_12e6:
	/* 0x12e6: imul   r12d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_12ea:
	/* 0x12ea: shr    r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_12ee:
	/* 0x12ee: add    r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_12f1:
	/* 0x12f1: movbe  WORD PTR [rsp+0x78],r12w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 120ULL);
x86_l_12f9:
	/* 0x12f9: mov    rdi,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_1300:
	/* 0x1300: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1305:
	/* 0x1305: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_130a:
	/* 0x130a: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_130f:
	/* 0x130f: call   rbx */
	X86_SIM_BPF_CALL_REG(X86_RBX);
x86_l_1311:
	/* 0x1311: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1313:
	/* 0x1313: je     17c3 <tail_nodeport_nat_egress_ipv6+0x17c3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1313, 0x17c3, x86_l_17c3);
x86_l_1319:
	/* 0x1319: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_131c:
	/* 0x131c: movzx  r12d,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1320:
	/* 0x1320: imul   r12d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_1324:
	/* 0x1324: shr    r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1328:
	/* 0x1328: add    r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_132b:
	/* 0x132b: movbe  WORD PTR [rsp+0x78],r12w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 120ULL);
x86_l_1333:
	/* 0x1333: mov    rdi,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_133a:
	/* 0x133a: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_133f:
	/* 0x133f: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1344:
	/* 0x1344: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_1349:
	/* 0x1349: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_134e:
	/* 0x134e: call   rbx */
	X86_SIM_BPF_CALL_REG(X86_RBX);
x86_l_1350:
	/* 0x1350: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1352:
	/* 0x1352: je     17cb <tail_nodeport_nat_egress_ipv6+0x17cb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1352, 0x17cb, x86_l_17cb);
x86_l_1358:
	/* 0x1358: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_135b:
	/* 0x135b: movzx  r12d,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_135f:
	/* 0x135f: imul   r12d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_1363:
	/* 0x1363: shr    r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1367:
	/* 0x1367: add    r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_136a:
	/* 0x136a: movbe  WORD PTR [rsp+0x78],r12w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 120ULL);
x86_l_1372:
	/* 0x1372: mov    rdi,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_1379:
	/* 0x1379: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_137e:
	/* 0x137e: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1383:
	/* 0x1383: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1388:
	/* 0x1388: call   rbx */
	X86_SIM_BPF_CALL_REG(X86_RBX);
x86_l_138a:
	/* 0x138a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_138c:
	/* 0x138c: je     17d3 <tail_nodeport_nat_egress_ipv6+0x17d3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x138c, 0x17d3, x86_l_17d3);
x86_l_1392:
	/* 0x1392: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1395:
	/* 0x1395: movzx  r12d,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1399:
	/* 0x1399: imul   r12d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_139d:
	/* 0x139d: shr    r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_13a1:
	/* 0x13a1: add    r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_13a4:
	/* 0x13a4: movbe  WORD PTR [rsp+0x78],r12w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 120ULL);
x86_l_13ac:
	/* 0x13ac: mov    rdi,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_13b3:
	/* 0x13b3: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_13b8:
	/* 0x13b8: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13bd:
	/* 0x13bd: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_13c2:
	/* 0x13c2: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_13c7:
	/* 0x13c7: call   rbx */
	X86_SIM_BPF_CALL_REG(X86_RBX);
x86_l_13c9:
	/* 0x13c9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_13cb:
	/* 0x13cb: je     17db <tail_nodeport_nat_egress_ipv6+0x17db> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13cb, 0x17db, x86_l_17db);
x86_l_13d1:
	/* 0x13d1: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_13d4:
	/* 0x13d4: movzx  r12d,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_13d8:
	/* 0x13d8: imul   r12d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_13dc:
	/* 0x13dc: shr    r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_13e0:
	/* 0x13e0: add    r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_13e3:
	/* 0x13e3: movbe  WORD PTR [rsp+0x78],r12w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 120ULL);
x86_l_13eb:
	/* 0x13eb: mov    rdi,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_13f2:
	/* 0x13f2: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_13f7:
	/* 0x13f7: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13fc:
	/* 0x13fc: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1401:
	/* 0x1401: call   rbx */
	X86_SIM_BPF_CALL_REG(X86_RBX);
x86_l_1403:
	/* 0x1403: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1405:
	/* 0x1405: je     17e3 <tail_nodeport_nat_egress_ipv6+0x17e3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1405, 0x17e3, x86_l_17e3);
x86_l_140b:
	/* 0x140b: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_140e:
	/* 0x140e: movzx  r12d,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1412:
	/* 0x1412: imul   r12d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_1416:
	/* 0x1416: shr    r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_141a:
	/* 0x141a: add    r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_141d:
	/* 0x141d: movbe  WORD PTR [rsp+0x78],r12w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 120ULL);
x86_l_1425:
	/* 0x1425: mov    rdi,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_142c:
	/* 0x142c: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1431:
	/* 0x1431: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1436:
	/* 0x1436: mov    ebx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 2ULL);
x86_l_143b:
	/* 0x143b: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1440:
	/* 0x1440: call   rbx */
	X86_SIM_BPF_CALL_REG(X86_RBX);
x86_l_1442:
	/* 0x1442: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1444:
	/* 0x1444: je     17eb <tail_nodeport_nat_egress_ipv6+0x17eb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1444, 0x17eb, x86_l_17eb);
x86_l_144a:
	/* 0x144a: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_144d:
	/* 0x144d: movzx  eax,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1451:
	/* 0x1451: imul   r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_1455:
	/* 0x1455: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1459:
	/* 0x1459: add    ebp,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R15, X86_WIDTH_32, X86_ALU_ADD);
x86_l_145c:
	/* 0x145c: movbe  WORD PTR [rsp+0x78],bp */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 120ULL);
x86_l_1463:
	/* 0x1463: mov    rdi,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_146a:
	/* 0x146a: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_146f:
	/* 0x146f: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1474:
	/* 0x1474: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1479:
	/* 0x1479: call   rbx */
	X86_SIM_BPF_CALL_REG(X86_RBX);
x86_l_147b:
	/* 0x147b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_147d:
	/* 0x147d: je     17f3 <tail_nodeport_nat_egress_ipv6+0x17f3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x147d, 0x17f3, x86_l_17f3);
x86_l_1483:
	/* 0x1483: mov    DWORD PTR [rsp+0xc8],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 858993459232ULL);
x86_l_148e:
	/* 0x148e: mov    rdi,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_alloc_retries)));
x86_l_1495:
	/* 0x1495: lea    rsi,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_149d:
	/* 0x149d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14a2:
	/* 0x14a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14a4:
	/* 0x14a4: mov    ebp,0xffffff59 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967129ULL);
x86_l_14a9:
	/* 0x14a9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14ac:
	/* 0x14ac: je     14b0 <tail_nodeport_nat_egress_ipv6+0x14b0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14ac, 0x14b0, x86_l_14b0);
x86_l_14ae:
	/* 0x14ae: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_14b0:
	/* 0x14b0: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14b3:
	/* 0x14b3: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14b7:
	/* 0x14b7: jmp    187d <tail_nodeport_nat_egress_ipv6+0x187d> */
	X86_SIM_X86_JMP(0x14b7, 0x187d, x86_l_187d);
x86_l_14bc:
	/* 0x14bc: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14be:
	/* 0x14be: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14c1:
	/* 0x14c1: jmp    17fb <tail_nodeport_nat_egress_ipv6+0x17fb> */
	X86_SIM_X86_JMP(0x14c1, 0x17fb, x86_l_17fb);
x86_l_14c6:
	/* 0x14c6: mov    r13d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 2ULL);
x86_l_14cc:
	/* 0x14cc: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14ce:
	/* 0x14ce: jmp    17fb <tail_nodeport_nat_egress_ipv6+0x17fb> */
	X86_SIM_X86_JMP(0x14ce, 0x17fb, x86_l_17fb);
x86_l_14d3:
	/* 0x14d3: mov    r13d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 3ULL);
x86_l_14d9:
	/* 0x14d9: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14db:
	/* 0x14db: jmp    17fb <tail_nodeport_nat_egress_ipv6+0x17fb> */
	X86_SIM_X86_JMP(0x14db, 0x17fb, x86_l_17fb);
x86_l_14e0:
	/* 0x14e0: mov    rdi,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_14e7:
	/* 0x14e7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14ec:
	/* 0x14ec: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_14ef:
	/* 0x14ef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14f1:
	/* 0x14f1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14f4:
	/* 0x14f4: jne    1610 <tail_nodeport_nat_egress_ipv6+0x1610> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x14f4, 0x1610, x86_l_1610);
x86_l_14fa:
	/* 0x14fa: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_14ff:
	/* 0x14ff: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1501:
	/* 0x1501: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1503:
	/* 0x1503: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1505:
	/* 0x1505: imul   rax,QWORD PTR [r15] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_1509:
	/* 0x1509: cmp    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_150c:
	/* 0x150c: jbe    1511 <tail_nodeport_nat_egress_ipv6+0x1511> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x150c, 0x1511, x86_l_1511);
x86_l_150e:
	/* 0x150e: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1511:
	/* 0x1511: mov    rcx,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__aux_snat_v6_nhm_nat_entry)));
x86_l_1518:
	/* 0x1518: mov    QWORD PTR [rcx+rax*1+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 206158430208ULL);
x86_l_1521:
	/* 0x1521: mov    QWORD PTR [rcx+rax*1+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 171798691840ULL);
x86_l_152a:
	/* 0x152a: mov    QWORD PTR [rcx+rax*1+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 137438953472ULL);
x86_l_1533:
	/* 0x1533: mov    QWORD PTR [rcx+rax*1+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 103079215104ULL);
x86_l_153c:
	/* 0x153c: mov    QWORD PTR [rcx+rax*1+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 68719476736ULL);
x86_l_1545:
	/* 0x1545: mov    QWORD PTR [rcx+rax*1+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 34359738368ULL);
x86_l_154e:
	/* 0x154e: mov    QWORD PTR [rcx+rax*1],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1556:
	/* 0x1556: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_155e:
	/* 0x155e: mov    rdx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1561:
	/* 0x1561: mov    rsi,QWORD PTR [rsi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1565:
	/* 0x1565: mov    QWORD PTR [rcx+rax*1+0x20],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 32ULL);
x86_l_156a:
	/* 0x156a: mov    QWORD PTR [rcx+rax*1+0x28],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 40ULL);
x86_l_156f:
	/* 0x156f: movzx  edx,WORD PTR [rsp+0xc2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 194ULL);
x86_l_1577:
	/* 0x1577: lea    r13,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_157b:
	/* 0x157b: mov    WORD PTR [rcx+rax*1+0x30],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 0), 48ULL);
x86_l_1580:
	/* 0x1580: mov    rax,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1587:
	/* 0x1587: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_158a:
	/* 0x158a: je     15cf <tail_nodeport_nat_egress_ipv6+0x15cf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x158a, 0x15cf, x86_l_15cf);
x86_l_158c:
	/* 0x158c: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_1591:
	/* 0x1591: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1593:
	/* 0x1593: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1595:
	/* 0x1595: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_1599:
	/* 0x1599: jmp    15f2 <tail_nodeport_nat_egress_ipv6+0x15f2> */
	X86_SIM_X86_JMP(0x1599, 0x15f2, x86_l_15f2);
x86_l_159b:
	/* 0x159b: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_15a1:
	/* 0x15a1: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15a3:
	/* 0x15a3: jmp    17fb <tail_nodeport_nat_egress_ipv6+0x17fb> */
	X86_SIM_X86_JMP(0x15a3, 0x17fb, x86_l_17fb);
x86_l_15a8:
	/* 0x15a8: mov    r13d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 5ULL);
x86_l_15ae:
	/* 0x15ae: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15b0:
	/* 0x15b0: jmp    17fb <tail_nodeport_nat_egress_ipv6+0x17fb> */
	X86_SIM_X86_JMP(0x15b0, 0x17fb, x86_l_17fb);
x86_l_15b5:
	/* 0x15b5: mov    r13d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 6ULL);
x86_l_15bb:
	/* 0x15bb: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15bd:
	/* 0x15bd: jmp    17fb <tail_nodeport_nat_egress_ipv6+0x17fb> */
	X86_SIM_X86_JMP(0x15bd, 0x17fb, x86_l_17fb);
x86_l_15c2:
	/* 0x15c2: mov    r13d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 7ULL);
x86_l_15c8:
	/* 0x15c8: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15ca:
	/* 0x15ca: jmp    17fb <tail_nodeport_nat_egress_ipv6+0x17fb> */
	X86_SIM_X86_JMP(0x15ca, 0x17fb, x86_l_17fb);
x86_l_15cf:
	/* 0x15cf: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_15d4:
	/* 0x15d4: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15d6:
	/* 0x15d6: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_15d8:
	/* 0x15d8: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_15dc:
	/* 0x15dc: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_15e6:
	/* 0x15e6: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_15e9:
	/* 0x15e9: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_15ee:
	/* 0x15ee: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_15f2:
	/* 0x15f2: mov    QWORD PTR [r13+0x0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15f6:
	/* 0x15f6: mov    rdi,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_15fd:
	/* 0x15fd: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1602:
	/* 0x1602: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_1605:
	/* 0x1605: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1608:
	/* 0x1608: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_160a:
	/* 0x160a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_160c:
	/* 0x160c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_160e:
	/* 0x160e: js     1620 <tail_nodeport_nat_egress_ipv6+0x1620> */
	X86_SIM_X86_JCC(X86_CC_S, 0x160e, 0x1620, x86_l_1620);
x86_l_1610:
	/* 0x1610: mov    rax,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1618:
	/* 0x1618: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_161b:
	/* 0x161b: jmp    18bb <tail_nodeport_nat_egress_ipv6+0x18bb> */
	X86_SIM_X86_JMP(0x161b, 0x18bb, x86_l_18bb);
x86_l_1620:
	/* 0x1620: mov    r13d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_1623:
	/* 0x1623: mov    ebp,0xffffff59 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967129ULL);
x86_l_1628:
	/* 0x1628: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_162c:
	/* 0x162c: jmp    119 <tail_nodeport_nat_egress_ipv6+0x119> */
	X86_SIM_X86_JMP(0x162c, 0x119, x86_l_119);
x86_l_1631:
	/* 0x1631: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_1637:
	/* 0x1637: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1639:
	/* 0x1639: jmp    17fb <tail_nodeport_nat_egress_ipv6+0x17fb> */
	X86_SIM_X86_JMP(0x1639, 0x17fb, x86_l_17fb);
x86_l_163e:
	/* 0x163e: mov    r13d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 9ULL);
x86_l_1644:
	/* 0x1644: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1646:
	/* 0x1646: jmp    17fb <tail_nodeport_nat_egress_ipv6+0x17fb> */
	X86_SIM_X86_JMP(0x1646, 0x17fb, x86_l_17fb);
x86_l_164b:
	/* 0x164b: mov    r13d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 10ULL);
x86_l_1651:
	/* 0x1651: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1653:
	/* 0x1653: jmp    17fb <tail_nodeport_nat_egress_ipv6+0x17fb> */
	X86_SIM_X86_JMP(0x1653, 0x17fb, x86_l_17fb);
x86_l_1658:
	/* 0x1658: mov    rdi,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv6_frag_datagrams)));
x86_l_165f:
	/* 0x165f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1664:
	/* 0x1664: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_1667:
	/* 0x1667: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1669:
	/* 0x1669: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_166c:
	/* 0x166c: je     1707 <tail_nodeport_nat_egress_ipv6+0x1707> */
	X86_SIM_X86_JCC(X86_CC_E, 0x166c, 0x1707, x86_l_1707);
x86_l_1672:
	/* 0x1672: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1674:
	/* 0x1674: mov    DWORD PTR [rsp+0xc0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_167b:
	/* 0x167b: jmp    1757 <tail_nodeport_nat_egress_ipv6+0x1757> */
	X86_SIM_X86_JMP(0x167b, 0x1757, x86_l_1757);
x86_l_1680:
	/* 0x1680: mov    r13d,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 11ULL);
x86_l_1686:
	/* 0x1686: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1688:
	/* 0x1688: jmp    17fb <tail_nodeport_nat_egress_ipv6+0x17fb> */
	X86_SIM_X86_JMP(0x1688, 0x17fb, x86_l_17fb);
x86_l_168d:
	/* 0x168d: mov    rdi,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv6_frag_datagrams)));
x86_l_1694:
	/* 0x1694: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1699:
	/* 0x1699: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_169c:
	/* 0x169c: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_169f:
	/* 0x169f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16a1:
	/* 0x16a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16a3:
	/* 0x16a3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_16a5:
	/* 0x16a5: je     8ea <tail_nodeport_nat_egress_ipv6+0x8ea> */
	X86_SIM_X86_JCC(X86_CC_E, 0x16a5, 0x8ea, x86_l_8ea);
x86_l_16ab:
	/* 0x16ab: mov    r15d,DWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16ae:
	/* 0x16ae: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_16b7:
	/* 0x16b7: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_16c0:
	/* 0x16c0: movabs rax,0x7201a9020a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 489654125066ULL);
x86_l_16ca:
	/* 0x16ca: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_16cf:
	/* 0x16cf: mov    rdi,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_16d6:
	/* 0x16d6: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_16db:
	/* 0x16db: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_16e0:
	/* 0x16e0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16e2:
	/* 0x16e2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_16e5:
	/* 0x16e5: je     172f <tail_nodeport_nat_egress_ipv6+0x172f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x16e5, 0x172f, x86_l_172f);
x86_l_16e7:
	/* 0x16e7: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_16ea:
	/* 0x16ea: add    QWORD PTR [rax+0x8],r15 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_16ee:
	/* 0x16ee: jmp    1757 <tail_nodeport_nat_egress_ipv6+0x1757> */
	X86_SIM_X86_JMP(0x16ee, 0x1757, x86_l_1757);
x86_l_16f0:
	/* 0x16f0: mov    ebp,0xffffff63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967139ULL);
x86_l_16f5:
	/* 0x16f5: jmp    116 <tail_nodeport_nat_egress_ipv6+0x116> */
	X86_SIM_X86_JMP(0x16f5, 0x116, x86_l_116);
x86_l_16fa:
	/* 0x16fa: mov    r13d,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 12ULL);
x86_l_1700:
	/* 0x1700: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1702:
	/* 0x1702: jmp    17fb <tail_nodeport_nat_egress_ipv6+0x17fb> */
	X86_SIM_X86_JMP(0x1702, 0x17fb, x86_l_17fb);
x86_l_1707:
	/* 0x1707: mov    ebp,0xffffff51 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967121ULL);
x86_l_170c:
	/* 0x170c: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1710:
	/* 0x1710: jmp    9ab <tail_nodeport_nat_egress_ipv6+0x9ab> */
	X86_SIM_X86_JMP(0x1710, 0x9ab, x86_l_9ab);
x86_l_1715:
	/* 0x1715: mov    r13d,0xd */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 13ULL);
x86_l_171b:
	/* 0x171b: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_171d:
	/* 0x171d: jmp    17fb <tail_nodeport_nat_egress_ipv6+0x17fb> */
	X86_SIM_X86_JMP(0x171d, 0x17fb, x86_l_17fb);
x86_l_1722:
	/* 0x1722: mov    r13d,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 14ULL);
x86_l_1728:
	/* 0x1728: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_172a:
	/* 0x172a: jmp    17fb <tail_nodeport_nat_egress_ipv6+0x17fb> */
	X86_SIM_X86_JMP(0x172a, 0x17fb, x86_l_17fb);
x86_l_172f:
	/* 0x172f: mov    QWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_1738:
	/* 0x1738: mov    QWORD PTR [rsp+0x18],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_173d:
	/* 0x173d: mov    rdi,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1744:
	/* 0x1744: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1749:
	/* 0x1749: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_174e:
	/* 0x174e: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1753:
	/* 0x1753: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1755:
	/* 0x1755: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1757:
	/* 0x1757: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_175b:
	/* 0x175b: jmp    8ea <tail_nodeport_nat_egress_ipv6+0x8ea> */
	X86_SIM_X86_JMP(0x175b, 0x8ea, x86_l_8ea);
x86_l_1760:
	/* 0x1760: mov    r13d,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 15ULL);
x86_l_1766:
	/* 0x1766: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1768:
	/* 0x1768: jmp    17fb <tail_nodeport_nat_egress_ipv6+0x17fb> */
	X86_SIM_X86_JMP(0x1768, 0x17fb, x86_l_17fb);
x86_l_176d:
	/* 0x176d: mov    r13d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 16ULL);
x86_l_1773:
	/* 0x1773: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1775:
	/* 0x1775: jmp    17fb <tail_nodeport_nat_egress_ipv6+0x17fb> */
	X86_SIM_X86_JMP(0x1775, 0x17fb, x86_l_17fb);
x86_l_177a:
	/* 0x177a: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_177e:
	/* 0x177e: jmp    18b3 <tail_nodeport_nat_egress_ipv6+0x18b3> */
	X86_SIM_X86_JMP(0x177e, 0x18b3, x86_l_18b3);
x86_l_1783:
	/* 0x1783: mov    r13d,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 17ULL);
x86_l_1789:
	/* 0x1789: jmp    17f9 <tail_nodeport_nat_egress_ipv6+0x17f9> */
	X86_SIM_X86_JMP(0x1789, 0x17f9, x86_l_17f9);
x86_l_178b:
	/* 0x178b: mov    r13d,0x12 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 18ULL);
x86_l_1791:
	/* 0x1791: jmp    17f9 <tail_nodeport_nat_egress_ipv6+0x17f9> */
	X86_SIM_X86_JMP(0x1791, 0x17f9, x86_l_17f9);
x86_l_1793:
	/* 0x1793: mov    r13d,0x13 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 19ULL);
x86_l_1799:
	/* 0x1799: jmp    17f9 <tail_nodeport_nat_egress_ipv6+0x17f9> */
	X86_SIM_X86_JMP(0x1799, 0x17f9, x86_l_17f9);
x86_l_179b:
	/* 0x179b: mov    r13d,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 20ULL);
x86_l_17a1:
	/* 0x17a1: jmp    17f9 <tail_nodeport_nat_egress_ipv6+0x17f9> */
	X86_SIM_X86_JMP(0x17a1, 0x17f9, x86_l_17f9);
x86_l_17a3:
	/* 0x17a3: mov    r13d,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 21ULL);
x86_l_17a9:
	/* 0x17a9: jmp    17f9 <tail_nodeport_nat_egress_ipv6+0x17f9> */
	X86_SIM_X86_JMP(0x17a9, 0x17f9, x86_l_17f9);
x86_l_17ab:
	/* 0x17ab: mov    r13d,0x16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 22ULL);
x86_l_17b1:
	/* 0x17b1: jmp    17f9 <tail_nodeport_nat_egress_ipv6+0x17f9> */
	X86_SIM_X86_JMP(0x17b1, 0x17f9, x86_l_17f9);
x86_l_17b3:
	/* 0x17b3: mov    r13d,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 23ULL);
x86_l_17b9:
	/* 0x17b9: jmp    17f9 <tail_nodeport_nat_egress_ipv6+0x17f9> */
	X86_SIM_X86_JMP(0x17b9, 0x17f9, x86_l_17f9);
x86_l_17bb:
	/* 0x17bb: mov    r13d,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 24ULL);
x86_l_17c1:
	/* 0x17c1: jmp    17f9 <tail_nodeport_nat_egress_ipv6+0x17f9> */
	X86_SIM_X86_JMP(0x17c1, 0x17f9, x86_l_17f9);
x86_l_17c3:
	/* 0x17c3: mov    r13d,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 25ULL);
x86_l_17c9:
	/* 0x17c9: jmp    17f9 <tail_nodeport_nat_egress_ipv6+0x17f9> */
	X86_SIM_X86_JMP(0x17c9, 0x17f9, x86_l_17f9);
x86_l_17cb:
	/* 0x17cb: mov    r13d,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 26ULL);
x86_l_17d1:
	/* 0x17d1: jmp    17f9 <tail_nodeport_nat_egress_ipv6+0x17f9> */
	X86_SIM_X86_JMP(0x17d1, 0x17f9, x86_l_17f9);
x86_l_17d3:
	/* 0x17d3: mov    r13d,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 27ULL);
x86_l_17d9:
	/* 0x17d9: jmp    17f9 <tail_nodeport_nat_egress_ipv6+0x17f9> */
	X86_SIM_X86_JMP(0x17d9, 0x17f9, x86_l_17f9);
x86_l_17db:
	/* 0x17db: mov    r13d,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 28ULL);
x86_l_17e1:
	/* 0x17e1: jmp    17f9 <tail_nodeport_nat_egress_ipv6+0x17f9> */
	X86_SIM_X86_JMP(0x17e1, 0x17f9, x86_l_17f9);
x86_l_17e3:
	/* 0x17e3: mov    r13d,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 29ULL);
x86_l_17e9:
	/* 0x17e9: jmp    17f9 <tail_nodeport_nat_egress_ipv6+0x17f9> */
	X86_SIM_X86_JMP(0x17e9, 0x17f9, x86_l_17f9);
x86_l_17eb:
	/* 0x17eb: mov    r13d,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 30ULL);
x86_l_17f1:
	/* 0x17f1: jmp    17f9 <tail_nodeport_nat_egress_ipv6+0x17f9> */
	X86_SIM_X86_JMP(0x17f1, 0x17f9, x86_l_17f9);
x86_l_17f3:
	/* 0x17f3: mov    r13d,0x1f */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 31ULL);
x86_l_17f9:
	/* 0x17f9: mov    bl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_8, 1ULL);
x86_l_17fb:
	/* 0x17fb: mov    DWORD PTR [rsp+0xc8],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1803:
	/* 0x1803: mov    rdi,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_alloc_retries)));
x86_l_180a:
	/* 0x180a: lea    rsi,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1812:
	/* 0x1812: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1817:
	/* 0x1817: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1819:
	/* 0x1819: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_181c:
	/* 0x181c: je     1820 <tail_nodeport_nat_egress_ipv6+0x1820> */
	X86_SIM_X86_JCC(X86_CC_E, 0x181c, 0x1820, x86_l_1820);
x86_l_181e:
	/* 0x181e: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1820:
	/* 0x1820: movzx  eax,WORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 120ULL);
x86_l_1825:
	/* 0x1825: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_182d:
	/* 0x182d: mov    WORD PTR [rdx+0x30],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1831:
	/* 0x1831: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1836:
	/* 0x1836: mov    QWORD PTR [rdx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1839:
	/* 0x1839: mov    rdi,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_1840:
	/* 0x1840: lea    rsi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1848:
	/* 0x1848: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_184b:
	/* 0x184b: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1850:
	/* 0x1850: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1852:
	/* 0x1852: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1854:
	/* 0x1854: mov    ebp,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_1856:
	/* 0x1856: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1858:
	/* 0x1858: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_185c:
	/* 0x185c: jns    1879 <tail_nodeport_nat_egress_ipv6+0x1879> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x185c, 0x1879, x86_l_1879);
x86_l_185e:
	/* 0x185e: mov    rdi,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_1865:
	/* 0x1865: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_186a:
	/* 0x186a: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_186f:
	/* 0x186f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1871:
	/* 0x1871: mov    r13d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBP, X86_WIDTH_32);
x86_l_1874:
	/* 0x1874: mov    ebp,0xffffff59 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967129ULL);
x86_l_1879:
	/* 0x1879: test   bl,bl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_8);
x86_l_187b:
	/* 0x187b: je     18b3 <tail_nodeport_nat_egress_ipv6+0x18b3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x187b, 0x18b3, x86_l_18b3);
x86_l_187d:
	/* 0x187d: movabs rax,0x100000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 4294967296ULL);
x86_l_1887:
	/* 0x1887: mov    QWORD PTR [rsp+0xf0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_188f:
	/* 0x188f: mov    rsi,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_signals)));
x86_l_1896:
	/* 0x1896: lea    rcx,[rsp+0xf0] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_189e:
	/* 0x189e: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_18a3:
	/* 0x18a3: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_18a8:
	/* 0x18a8: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_18ab:
	/* 0x18ab: mov    r8d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 8ULL);
x86_l_18b1:
	/* 0x18b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18b3:
	/* 0x18b3: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_18b5:
	/* 0x18b5: js     119 <tail_nodeport_nat_egress_ipv6+0x119> */
	X86_SIM_X86_JCC(X86_CC_S, 0x18b5, 0x119, x86_l_119);
x86_l_18bb:
	/* 0x18bb: mov    rcx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_18c3:
	/* 0x18c3: movzx  esi,WORD PTR [rcx+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_18c7:
	/* 0x18c7: movzx  r15d,BYTE PTR [rsp+0xc4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 196ULL);
x86_l_18d0:
	/* 0x18d0: mov    rax,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_18d7:
	/* 0x18d7: movzx  r12d,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_18db:
	/* 0x18db: movzx  edx,WORD PTR [rsp+0xc2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 194ULL);
x86_l_18e3:
	/* 0x18e3: mov    rax,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_18eb:
	/* 0x18eb: cmp    rax,QWORD PTR [rcx+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_18ef:
	/* 0x18ef: mov    DWORD PTR [rsp+0x94],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_18f6:
	/* 0x18f6: mov    WORD PTR [rsp+0x98],si */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_18fe:
	/* 0x18fe: jne    1926 <tail_nodeport_nat_egress_ipv6+0x1926> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x18fe, 0x1926, x86_l_1926);
x86_l_1900:
	/* 0x1900: cmp    dx,si */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_16);
x86_l_1903:
	/* 0x1903: sete   bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_E);
x86_l_1906:
	/* 0x1906: jne    192c <tail_nodeport_nat_egress_ipv6+0x192c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1906, 0x192c, x86_l_192c);
x86_l_1908:
	/* 0x1908: mov    rax,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1910:
	/* 0x1910: mov    rax,QWORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1914:
	/* 0x1914: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1916:
	/* 0x1916: cmp    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_191e:
	/* 0x191e: je     1ac7 <tail_nodeport_nat_egress_ipv6+0x1ac7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x191e, 0x1ac7, x86_l_1ac7);
x86_l_1924:
	/* 0x1924: jmp    192c <tail_nodeport_nat_egress_ipv6+0x192c> */
	X86_SIM_X86_JMP(0x1924, 0x192c, x86_l_192c);
x86_l_1926:
	/* 0x1926: cmp    dx,si */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_16);
x86_l_1929:
	/* 0x1929: sete   bl */
	X86_SIM_L_EXEC_SETCC(X86_RBX, X86_CC_E);
x86_l_192c:
	/* 0x192c: mov    rax,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1934:
	/* 0x1934: lea    rbp,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1938:
	/* 0x1938: mov    eax,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_193d:
	/* 0x193d: lea    rdi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1945:
	/* 0x1945: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_194a:
	/* 0x194a: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_194d:
	/* 0x194d: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1952:
	/* 0x1952: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1955:
	/* 0x1955: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1957:
	/* 0x1957: mov    DWORD PTR [rsp+0xec],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 236ULL);
x86_l_195e:
	/* 0x195e: add    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_ADD, 8ULL);
x86_l_1962:
	/* 0x1962: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_1967:
	/* 0x1967: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_196b:
	/* 0x196b: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_196e:
	/* 0x196e: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1971:
	/* 0x1971: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1976:
	/* 0x1976: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1979:
	/* 0x1979: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_197b:
	/* 0x197b: mov    ebp,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_197d:
	/* 0x197d: sar    ebp,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SAR, 31ULL);
x86_l_1980:
	/* 0x1980: and    ebp,0xffffff73 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4294967155ULL);
x86_l_1986:
	/* 0x1986: movabs rcx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2199023255552ULL);
x86_l_1990:
	/* 0x1990: test   QWORD PTR [rsp+0x80],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1998:
	/* 0x1998: jne    1ac7 <tail_nodeport_nat_egress_ipv6+0x1ac7> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1998, 0x1ac7, x86_l_1ac7);
x86_l_199e:
	/* 0x199e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_19a0:
	/* 0x19a0: js     1ac7 <tail_nodeport_nat_egress_ipv6+0x1ac7> */
	X86_SIM_X86_JCC(X86_CC_S, 0x19a0, 0x1ac7, x86_l_1ac7);
x86_l_19a6:
	/* 0x19a6: cmp    r15d,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 58ULL);
x86_l_19aa:
	/* 0x19aa: je     19ce <tail_nodeport_nat_egress_ipv6+0x19ce> */
	X86_SIM_X86_JCC(X86_CC_E, 0x19aa, 0x19ce, x86_l_19ce);
x86_l_19ac:
	/* 0x19ac: cmp    r15d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 17ULL);
x86_l_19b0:
	/* 0x19b0: je     19c0 <tail_nodeport_nat_egress_ipv6+0x19c0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x19b0, 0x19c0, x86_l_19c0);
x86_l_19b2:
	/* 0x19b2: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_19b6:
	/* 0x19b6: jne    19db <tail_nodeport_nat_egress_ipv6+0x19db> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x19b6, 0x19db, x86_l_19db);
x86_l_19b8:
	/* 0x19b8: mov    r12d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 16ULL);
x86_l_19be:
	/* 0x19be: jmp    19d4 <tail_nodeport_nat_egress_ipv6+0x19d4> */
	X86_SIM_X86_JMP(0x19be, 0x19d4, x86_l_19d4);
x86_l_19c0:
	/* 0x19c0: mov    r12d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 6ULL);
x86_l_19c6:
	/* 0x19c6: mov    r8d,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 32ULL);
x86_l_19cc:
	/* 0x19cc: jmp    19d7 <tail_nodeport_nat_egress_ipv6+0x19d7> */
	X86_SIM_X86_JMP(0x19cc, 0x19d7, x86_l_19d7);
x86_l_19ce:
	/* 0x19ce: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_19d4:
	/* 0x19d4: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19d7:
	/* 0x19d7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19d9:
	/* 0x19d9: jmp    19e3 <tail_nodeport_nat_egress_ipv6+0x19e3> */
	X86_SIM_X86_JMP(0x19d9, 0x19e3, x86_l_19e3);
x86_l_19db:
	/* 0x19db: mov    cl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_19dd:
	/* 0x19dd: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19e0:
	/* 0x19e0: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19e3:
	/* 0x19e3: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19e8:
	/* 0x19e8: test   bl,bl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_8);
x86_l_19ea:
	/* 0x19ea: jne    1a91 <tail_nodeport_nat_egress_ipv6+0x1a91> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x19ea, 0x1a91, x86_l_1a91);
x86_l_19f0:
	/* 0x19f0: mov    ebp,0xffffff72 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967154ULL);
x86_l_19f5:
	/* 0x19f5: cmp    r15d,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 58ULL);
x86_l_19f9:
	/* 0x19f9: ja     1ac7 <tail_nodeport_nat_egress_ipv6+0x1ac7> */
	X86_SIM_X86_JCC(X86_CC_A, 0x19f9, 0x1ac7, x86_l_1ac7);
x86_l_19ff:
	/* 0x19ff: mov    DWORD PTR [rsp+0xe8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_1a06:
	/* 0x1a06: mov    DWORD PTR [rsp+0x80],r8d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1a0e:
	/* 0x1a0e: mov    eax,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_1a11:
	/* 0x1a11: movabs rcx,0x400000000020040 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 288230376151842880ULL);
x86_l_1a1b:
	/* 0x1a1b: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1a1f:
	/* 0x1a1f: jae    1ac7 <tail_nodeport_nat_egress_ipv6+0x1ac7> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x1a1f, 0x1ac7, x86_l_1ac7);
x86_l_1a25:
	/* 0x1a25: movzx  eax,WORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 152ULL);
x86_l_1a2d:
	/* 0x1a2d: mov    WORD PTR [rsp+0x10],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a32:
	/* 0x1a32: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a37:
	/* 0x1a37: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_1a3c:
	/* 0x1a3c: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a40:
	/* 0x1a40: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1a43:
	/* 0x1a43: mov    rbp,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a48:
	/* 0x1a48: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_1a4a:
	/* 0x1a4a: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1a4f:
	/* 0x1a4f: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a52:
	/* 0x1a52: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a54:
	/* 0x1a54: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1a56:
	/* 0x1a56: js     1ac2 <tail_nodeport_nat_egress_ipv6+0x1ac2> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1a56, 0x1ac2, x86_l_1ac2);
x86_l_1a58:
	/* 0x1a58: movzx  ecx,WORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_1a5d:
	/* 0x1a5d: lea    esi,[r12+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_1a61:
	/* 0x1a61: mov    r8d,DWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1a69:
	/* 0x1a69: or     r8d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_1a6d:
	/* 0x1a6d: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_1a72:
	/* 0x1a72: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1a75:
	/* 0x1a75: mov    edx,DWORD PTR [rsp+0x94] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_1a7c:
	/* 0x1a7c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a7e:
	/* 0x1a7e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1a80:
	/* 0x1a80: js     1abb <tail_nodeport_nat_egress_ipv6+0x1abb> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1a80, 0x1abb, x86_l_1abb);
x86_l_1a82:
	/* 0x1a82: mov    r8d,DWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1a8a:
	/* 0x1a8a: mov    ecx,DWORD PTR [rsp+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_1a91:
	/* 0x1a91: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_1a93:
	/* 0x1a93: jne    1ab7 <tail_nodeport_nat_egress_ipv6+0x1ab7> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1a93, 0x1ab7, x86_l_1ab7);
x86_l_1a95:
	/* 0x1a95: add    r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1a98:
	/* 0x1a98: or     r8d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 16ULL);
x86_l_1a9c:
	/* 0x1a9c: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_1aa1:
	/* 0x1aa1: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1aa5:
	/* 0x1aa5: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_1aa8:
	/* 0x1aa8: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1aaa:
	/* 0x1aaa: mov    ecx,DWORD PTR [rsp+0xec] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 236ULL);
x86_l_1ab1:
	/* 0x1ab1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ab3:
	/* 0x1ab3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1ab5:
	/* 0x1ab5: js     1abb <tail_nodeport_nat_egress_ipv6+0x1abb> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1ab5, 0x1abb, x86_l_1abb);
x86_l_1ab7:
	/* 0x1ab7: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ab9:
	/* 0x1ab9: jmp    1ac7 <tail_nodeport_nat_egress_ipv6+0x1ac7> */
	X86_SIM_X86_JMP(0x1ab9, 0x1ac7, x86_l_1ac7);
x86_l_1abb:
	/* 0x1abb: mov    ebp,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967142ULL);
x86_l_1ac0:
	/* 0x1ac0: jmp    1ac7 <tail_nodeport_nat_egress_ipv6+0x1ac7> */
	X86_SIM_X86_JMP(0x1ac0, 0x1ac7, x86_l_1ac7);
x86_l_1ac2:
	/* 0x1ac2: mov    ebp,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967155ULL);
x86_l_1ac7:
	/* 0x1ac7: mov    rcx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1acf:
	/* 0x1acf: mov    rax,QWORD PTR [rcx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1ad3:
	/* 0x1ad3: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1adb:
	/* 0x1adb: mov    rax,QWORD PTR [rcx+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1adf:
	/* 0x1adf: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1ae7:
	/* 0x1ae7: movzx  eax,WORD PTR [rcx+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_1aeb:
	/* 0x1aeb: mov    WORD PTR [rsp+0xc2],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 194ULL);
x86_l_1af3:
	/* 0x1af3: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_1af5:
	/* 0x1af5: js     217b <tail_nodeport_nat_egress_ipv6+0x217b> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1af5, 0x217b, x86_l_217b);
x86_l_1afb:
	/* 0x1afb: mov    eax,0xfffff0ff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294963455ULL);
x86_l_1b00:
	/* 0x1b00: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b04:
	/* 0x1b04: and    eax,DWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 8ULL);
x86_l_1b08:
	/* 0x1b08: or     eax,0x300 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 768ULL);
x86_l_1b0d:
	/* 0x1b0d: mov    DWORD PTR [r15+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b11:
	/* 0x1b11: test   r14,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64);
x86_l_1b14:
	/* 0x1b14: mov    ebx,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1b1b:
	/* 0x1b1b: je     1b77 <tail_nodeport_nat_egress_ipv6+0x1b77> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1b1b, 0x1b77, x86_l_1b77);
x86_l_1b1d:
	/* 0x1b1d: movzx  eax,BYTE PTR [r14+0x17] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 23ULL);
x86_l_1b22:
	/* 0x1b22: and    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_AND, 3ULL);
x86_l_1b24:
	/* 0x1b24: cmp    al,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 2ULL);
x86_l_1b26:
	/* 0x1b26: jne    1b77 <tail_nodeport_nat_egress_ipv6+0x1b77> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1b26, 0x1b77, x86_l_1b77);
x86_l_1b28:
	/* 0x1b28: mov    rax,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_1b2f:
	/* 0x1b2f: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b32:
	/* 0x1b32: je     1d13 <tail_nodeport_nat_egress_ipv6+0x1d13> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1b32, 0x1d13, x86_l_1d13);
x86_l_1b38:
	/* 0x1b38: mov    ebp,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b3b:
	/* 0x1b3b: mov    rax,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_tracing_ip_option_type)));
x86_l_1b42:
	/* 0x1b42: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b45:
	/* 0x1b45: je     1c82 <tail_nodeport_nat_egress_ipv6+0x1c82> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1b45, 0x1c82, x86_l_1c82);
x86_l_1b4b:
	/* 0x1b4b: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1b53:
	/* 0x1b53: mov    rdi,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_percpu_trace_id)));
x86_l_1b5a:
	/* 0x1b5a: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b5f:
	/* 0x1b5f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1b64:
	/* 0x1b64: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b66:
	/* 0x1b66: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b69:
	/* 0x1b69: je     1c82 <tail_nodeport_nat_egress_ipv6+0x1c82> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1b69, 0x1c82, x86_l_1c82);
x86_l_1b6f:
	/* 0x1b6f: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b72:
	/* 0x1b72: jmp    1c84 <tail_nodeport_nat_egress_ipv6+0x1c84> */
	X86_SIM_X86_JMP(0x1b72, 0x1c84, x86_l_1c84);
x86_l_1b77:
	/* 0x1b77: mov    rax,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_1b7e:
	/* 0x1b7e: movzx  ecx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1b81:
	/* 0x1b81: mov    eax,DWORD PTR [r15+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_1b85:
	/* 0x1b85: mov    edx,DWORD PTR [r15+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1b89:
	/* 0x1b89: lea    rsi,[rax+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1b8d:
	/* 0x1b8d: add    rsi,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_1b91:
	/* 0x1b91: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_1b96:
	/* 0x1b96: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_1b99:
	/* 0x1b99: ja     119 <tail_nodeport_nat_egress_ipv6+0x119> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1b99, 0x119, x86_l_119);
x86_l_1b9f:
	/* 0x1b9f: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1ba2:
	/* 0x1ba2: mov    rcx,QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ba6:
	/* 0x1ba6: mov    QWORD PTR [rsp+0x118],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 280ULL);
x86_l_1bae:
	/* 0x1bae: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bb2:
	/* 0x1bb2: mov    QWORD PTR [rsp+0x110],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 272ULL);
x86_l_1bba:
	/* 0x1bba: mov    rcx,QWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1bbe:
	/* 0x1bbe: mov    QWORD PTR [rsp+0x128],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_1bc6:
	/* 0x1bc6: mov    rax,QWORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1bca:
	/* 0x1bca: mov    QWORD PTR [rsp+0x120],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_1bd2:
	/* 0x1bd2: mov    rax,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_supports_fib_lookup_skip_neigh)));
x86_l_1bd9:
	/* 0x1bd9: movzx  ecx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1bdc:
	/* 0x1bdc: shl    ecx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 2ULL);
x86_l_1bdf:
	/* 0x1bdf: lea    rsi,[rsp+0x100] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_1be7:
	/* 0x1be7: mov    eax,0x45 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 69ULL);
x86_l_1bec:
	/* 0x1bec: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1bef:
	/* 0x1bef: mov    edx,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 64ULL);
x86_l_1bf4:
	/* 0x1bf4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bf6:
	/* 0x1bf6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1bf8:
	/* 0x1bf8: je     1c03 <tail_nodeport_nat_egress_ipv6+0x1c03> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1bf8, 0x1c03, x86_l_1c03);
x86_l_1bfa:
	/* 0x1bfa: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_1bfd:
	/* 0x1bfd: jne    1d6e <tail_nodeport_nat_egress_ipv6+0x1d6e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1bfd, 0x1d6e, x86_l_1d6e);
x86_l_1c03:
	/* 0x1c03: mov    r14d,DWORD PTR [rsp+0x108] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_1c0b:
	/* 0x1c0b: mov    DWORD PTR [rsp+0x10],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c10:
	/* 0x1c10: mov    rdi,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_devices)));
x86_l_1c17:
	/* 0x1c17: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c1c:
	/* 0x1c1c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1c21:
	/* 0x1c21: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c23:
	/* 0x1c23: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1c26:
	/* 0x1c26: je     1c32 <tail_nodeport_nat_egress_ipv6+0x1c32> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1c26, 0x1c32, x86_l_1c32);
x86_l_1c28:
	/* 0x1c28: test   BYTE PTR [rax+0x8],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_1c2c:
	/* 0x1c2c: jne    1edd <tail_nodeport_nat_egress_ipv6+0x1edd> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1c2c, 0x1edd, x86_l_1edd);
x86_l_1c32:
	/* 0x1c32: mov    rax,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_1c39:
	/* 0x1c39: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c3c:
	/* 0x1c3c: je     1eff <tail_nodeport_nat_egress_ipv6+0x1eff> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1c3c, 0x1eff, x86_l_1eff);
x86_l_1c42:
	/* 0x1c42: lea    rax,[rsp+0x120] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_1c4a:
	/* 0x1c4a: movzx  ecx,BYTE PTR [rsp+0x100] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 256ULL);
x86_l_1c52:
	/* 0x1c52: mov    DWORD PTR [rsp+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c56:
	/* 0x1c56: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c59:
	/* 0x1c59: mov    rax,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c5d:
	/* 0x1c5d: mov    QWORD PTR [rsp+0x14],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1c62:
	/* 0x1c62: mov    QWORD PTR [rsp+0x1c],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1c67:
	/* 0x1c67: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c6c:
	/* 0x1c6c: mov    eax,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 152ULL);
x86_l_1c71:
	/* 0x1c71: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_1c74:
	/* 0x1c74: mov    edx,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 20ULL);
x86_l_1c79:
	/* 0x1c79: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c7b:
	/* 0x1c7b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c7d:
	/* 0x1c7d: jmp    1ee9 <tail_nodeport_nat_egress_ipv6+0x1ee9> */
	X86_SIM_X86_JMP(0x1c7d, 0x1ee9, x86_l_1ee9);
x86_l_1c82:
	/* 0x1c82: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c84:
	/* 0x1c84: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c89:
	/* 0x1c89: mov    r15d,DWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c8c:
	/* 0x1c8c: mov    QWORD PTR [rsp+0xc8],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 858993459202ULL);
x86_l_1c98:
	/* 0x1c98: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1ca1:
	/* 0x1ca1: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1caa:
	/* 0x1caa: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1cb3:
	/* 0x1cb3: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1cbc:
	/* 0x1cbc: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1cc5:
	/* 0x1cc5: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1cce:
	/* 0x1cce: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1cd7:
	/* 0x1cd7: movabs rax,0x6f00220200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 476743598592ULL);
x86_l_1ce1:
	/* 0x1ce1: mov    QWORD PTR [rsp+0xf0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_1ce9:
	/* 0x1ce9: mov    rdi,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1cf0:
	/* 0x1cf0: lea    r12,[rsp+0xf0] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_1cf8:
	/* 0x1cf8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1cfd:
	/* 0x1cfd: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_1d00:
	/* 0x1d00: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d02:
	/* 0x1d02: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d05:
	/* 0x1d05: je     1d7b <tail_nodeport_nat_egress_ipv6+0x1d7b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1d05, 0x1d7b, x86_l_1d7b);
x86_l_1d07:
	/* 0x1d07: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1d0a:
	/* 0x1d0a: add    QWORD PTR [rax+0x8],r15 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1d0e:
	/* 0x1d0e: jmp    1da6 <tail_nodeport_nat_egress_ipv6+0x1da6> */
	X86_SIM_X86_JMP(0x1d0e, 0x1da6, x86_l_1da6);
x86_l_1d13:
	/* 0x1d13: mov    r12d,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBX, X86_WIDTH_32);
x86_l_1d16:
	/* 0x1d16: mov    ebx,DWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d1a:
	/* 0x1d1a: mov    eax,0x2b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_1d1f:
	/* 0x1d1f: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1d22:
	/* 0x1d22: mov    esi,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 14ULL);
x86_l_1d27:
	/* 0x1d27: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d29:
	/* 0x1d29: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d2b:
	/* 0x1d2b: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_1d30:
	/* 0x1d30: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1d32:
	/* 0x1d32: jne    119 <tail_nodeport_nat_egress_ipv6+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1d32, 0x119, x86_l_119);
x86_l_1d38:
	/* 0x1d38: mov    WORD PTR [rsp+0x10],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d3d:
	/* 0x1d3d: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d42:
	/* 0x1d42: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_1d47:
	/* 0x1d47: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1d4a:
	/* 0x1d4a: mov    esi,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 12ULL);
x86_l_1d4f:
	/* 0x1d4f: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1d54:
	/* 0x1d54: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d57:
	/* 0x1d57: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d59:
	/* 0x1d59: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1d5b:
	/* 0x1d5b: mov    ebx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R12, X86_WIDTH_32);
x86_l_1d5e:
	/* 0x1d5e: jns    1b38 <tail_nodeport_nat_egress_ipv6+0x1b38> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1d5e, 0x1b38, x86_l_1b38);
x86_l_1d64:
	/* 0x1d64: mov    ebp,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967155ULL);
x86_l_1d69:
	/* 0x1d69: jmp    119 <tail_nodeport_nat_egress_ipv6+0x119> */
	X86_SIM_X86_JMP(0x1d69, 0x119, x86_l_119);
x86_l_1d6e:
	/* 0x1d6e: mov    ebp,0xffffff57 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967127ULL);
x86_l_1d73:
	/* 0x1d73: mov    r13d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_1d76:
	/* 0x1d76: jmp    119 <tail_nodeport_nat_egress_ipv6+0x119> */
	X86_SIM_X86_JMP(0x1d76, 0x119, x86_l_119);
x86_l_1d7b:
	/* 0x1d7b: mov    QWORD PTR [rsp+0x58],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122049ULL);
x86_l_1d84:
	/* 0x1d84: mov    QWORD PTR [rsp+0x60],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1d89:
	/* 0x1d89: mov    rdi,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1d90:
	/* 0x1d90: lea    rsi,[rsp+0xf0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_1d98:
	/* 0x1d98: lea    rdx,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1d9d:
	/* 0x1d9d: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1da2:
	/* 0x1da2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1da4:
	/* 0x1da4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1da6:
	/* 0x1da6: test   ebx,ebx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32);
x86_l_1da8:
	/* 0x1da8: je     2079 <tail_nodeport_nat_egress_ipv6+0x2079> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1da8, 0x2079, x86_l_2079);
x86_l_1dae:
	/* 0x1dae: mov    rax,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_events_map_rate_limit)));
x86_l_1db5:
	/* 0x1db5: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1db8:
	/* 0x1db8: je     1fb9 <tail_nodeport_nat_egress_ipv6+0x1fb9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1db8, 0x1fb9, x86_l_1fb9);
x86_l_1dbe:
	/* 0x1dbe: mov    DWORD PTR [rsp+0x88],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1dc5:
	/* 0x1dc5: mov    DWORD PTR [rsp+0x90],ebx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1dcc:
	/* 0x1dcc: mov    rcx,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_events_map_burst_limit)));
x86_l_1dd3:
	/* 0x1dd3: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1dd5:
	/* 0x1dd5: mov    QWORD PTR [rsp+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1ddd:
	/* 0x1ddd: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ddf:
	/* 0x1ddf: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1de7:
	/* 0x1de7: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1dec:
	/* 0x1dec: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1dee:
	/* 0x1dee: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1df0:
	/* 0x1df0: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_1df3:
	/* 0x1df3: mov    DWORD PTR [rsp+0xd4],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 910533066754ULL);
x86_l_1dfe:
	/* 0x1dfe: mov    rdi,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit_metrics)));
x86_l_1e05:
	/* 0x1e05: lea    rsi,[rsp+0xd4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 212ULL);
x86_l_1e0d:
	/* 0x1e0d: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_1e12:
	/* 0x1e12: call   rbx */
	X86_SIM_BPF_CALL_REG(X86_RBX);
x86_l_1e14:
	/* 0x1e14: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e17:
	/* 0x1e17: jne    1e4b <tail_nodeport_nat_egress_ipv6+0x1e4b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1e17, 0x1e4b, x86_l_1e4b);
x86_l_1e19:
	/* 0x1e19: mov    QWORD PTR [rsp+0xf0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1030792151040ULL);
x86_l_1e25:
	/* 0x1e25: mov    rdi,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit_metrics)));
x86_l_1e2c:
	/* 0x1e2c: lea    rsi,[rsp+0xd4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 212ULL);
x86_l_1e34:
	/* 0x1e34: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1e39:
	/* 0x1e39: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1e3c:
	/* 0x1e3c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e3e:
	/* 0x1e3e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e40:
	/* 0x1e40: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1e42:
	/* 0x1e42: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_1e45:
	/* 0x1e45: js     2079 <tail_nodeport_nat_egress_ipv6+0x2079> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1e45, 0x2079, x86_l_2079);
x86_l_1e4b:
	/* 0x1e4b: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1e4e:
	/* 0x1e4e: mov    rdi,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit)));
x86_l_1e55:
	/* 0x1e55: lea    rsi,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1e5d:
	/* 0x1e5d: call   rbx */
	X86_SIM_BPF_CALL_REG(X86_RBX);
x86_l_1e5f:
	/* 0x1e5f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1e62:
	/* 0x1e62: je     1f55 <tail_nodeport_nat_egress_ipv6+0x1f55> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1e62, 0x1f55, x86_l_1f55);
x86_l_1e68:
	/* 0x1e68: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e6b:
	/* 0x1e6b: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_1e6e:
	/* 0x1e6e: sub    rsi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1e71:
	/* 0x1e71: cmp    rsi,0x3b9aca00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 1000000000ULL);
x86_l_1e78:
	/* 0x1e78: mov    ebx,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1e7f:
	/* 0x1e7f: jbe    1f9e <tail_nodeport_nat_egress_ipv6+0x1f9e> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x1e7f, 0x1f9e, x86_l_1f9e);
x86_l_1e85:
	/* 0x1e85: mov    rdx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_1e88:
	/* 0x1e88: shr    rdx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1e8c:
	/* 0x1e8c: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_1e96:
	/* 0x1e96: mulx   rcx,rcx,rcx */
	X86_SIM_L_EXEC_MULX(X86_RCX, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_1e9b:
	/* 0x1e9b: shr    rcx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_1e9f:
	/* 0x1e9f: imul   rdx,rcx,0x3b9aca00 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RDX, X86_RCX, X86_WIDTH_64, 1000000000ULL);
x86_l_1ea6:
	/* 0x1ea6: imul   rcx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 152ULL);
x86_l_1eaf:
	/* 0x1eaf: add    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1eb3:
	/* 0x1eb3: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1eb7:
	/* 0x1eb7: sub    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1eba:
	/* 0x1eba: add    rbp,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1ebd:
	/* 0x1ebd: mov    QWORD PTR [rax],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ec0:
	/* 0x1ec0: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1ec8:
	/* 0x1ec8: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1ecb:
	/* 0x1ecb: jbe    1fa2 <tail_nodeport_nat_egress_ipv6+0x1fa2> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x1ecb, 0x1fa2, x86_l_1fa2);
x86_l_1ed1:
	/* 0x1ed1: mov    QWORD PTR [rax+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ed5:
	/* 0x1ed5: mov    rcx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_1ed8:
	/* 0x1ed8: jmp    1fa2 <tail_nodeport_nat_egress_ipv6+0x1fa2> */
	X86_SIM_X86_JMP(0x1ed8, 0x1fa2, x86_l_1fa2);
x86_l_1edd:
	/* 0x1edd: mov    eax,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 23ULL);
x86_l_1ee2:
	/* 0x1ee2: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_1ee5:
	/* 0x1ee5: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ee7:
	/* 0x1ee7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ee9:
	/* 0x1ee9: mov    ebp,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_1eeb:
	/* 0x1eeb: mov    r14d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 7ULL);
x86_l_1ef1:
	/* 0x1ef1: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_1ef4:
	/* 0x1ef4: jne    119 <tail_nodeport_nat_egress_ipv6+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1ef4, 0x119, x86_l_119);
x86_l_1efa:
	/* 0x1efa: jmp    683 <tail_nodeport_nat_egress_ipv6+0x683> */
	X86_SIM_X86_JMP(0x1efa, 0x683, x86_l_683);
x86_l_1eff:
	/* 0x1eff: mov    ebx,DWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f03:
	/* 0x1f03: mov    eax,0x2b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_1f08:
	/* 0x1f08: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1f0b:
	/* 0x1f0b: mov    esi,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 14ULL);
x86_l_1f10:
	/* 0x1f10: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f12:
	/* 0x1f12: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f14:
	/* 0x1f14: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1f16:
	/* 0x1f16: jne    119 <tail_nodeport_nat_egress_ipv6+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1f16, 0x119, x86_l_119);
x86_l_1f1c:
	/* 0x1f1c: mov    WORD PTR [rsp+0x10],bx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f21:
	/* 0x1f21: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f26:
	/* 0x1f26: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_1f2b:
	/* 0x1f2b: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_1f2e:
	/* 0x1f2e: mov    esi,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 12ULL);
x86_l_1f33:
	/* 0x1f33: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1f38:
	/* 0x1f38: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f3b:
	/* 0x1f3b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f3d:
	/* 0x1f3d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1f3f:
	/* 0x1f3f: jns    1c42 <tail_nodeport_nat_egress_ipv6+0x1c42> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1f3f, 0x1c42, x86_l_1c42);
x86_l_1f45:
	/* 0x1f45: mov    ebp,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_1f47:
	/* 0x1f47: sar    ebp,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SAR, 31ULL);
x86_l_1f4a:
	/* 0x1f4a: and    ebp,0xffffff73 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4294967155ULL);
x86_l_1f50:
	/* 0x1f50: jmp    119 <tail_nodeport_nat_egress_ipv6+0x119> */
	X86_SIM_X86_JMP(0x1f50, 0x119, x86_l_119);
x86_l_1f55:
	/* 0x1f55: mov    QWORD PTR [rsp+0x58],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1f5a:
	/* 0x1f5a: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1f62:
	/* 0x1f62: dec    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_1f65:
	/* 0x1f65: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1f6a:
	/* 0x1f6a: mov    rdi,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit)));
x86_l_1f71:
	/* 0x1f71: lea    rsi,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1f79:
	/* 0x1f79: lea    rdx,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1f7e:
	/* 0x1f7e: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1f83:
	/* 0x1f83: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f85:
	/* 0x1f85: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f87:
	/* 0x1f87: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1f89:
	/* 0x1f89: mov    ebx,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1f90:
	/* 0x1f90: mov    ebp,DWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1f97:
	/* 0x1f97: jns    1fb9 <tail_nodeport_nat_egress_ipv6+0x1fb9> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1f97, 0x1fb9, x86_l_1fb9);
x86_l_1f99:
	/* 0x1f99: jmp    20ed <tail_nodeport_nat_egress_ipv6+0x20ed> */
	X86_SIM_X86_JMP(0x1f99, 0x20ed, x86_l_20ed);
x86_l_1f9e:
	/* 0x1f9e: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1fa2:
	/* 0x1fa2: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_1fa5:
	/* 0x1fa5: mov    ebp,DWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1fac:
	/* 0x1fac: je     20ed <tail_nodeport_nat_egress_ipv6+0x20ed> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1fac, 0x20ed, x86_l_20ed);
x86_l_1fb2:
	/* 0x1fb2: dec    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_1fb5:
	/* 0x1fb5: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1fb9:
	/* 0x1fb9: mov    rax,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_1fc0:
	/* 0x1fc0: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fc3:
	/* 0x1fc3: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_1fc6:
	/* 0x1fc6: add    cl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_8, X86_ALU_ADD);
x86_l_1fc8:
	/* 0x1fc8: or     cl,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_OR, 1ULL);
x86_l_1fcb:
	/* 0x1fcb: mov    rdx,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_1fd2:
	/* 0x1fd2: mov    eax,DWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fd4:
	/* 0x1fd4: mov    edx,DWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fd6:
	/* 0x1fd6: cmp    edx,ebx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBX, X86_WIDTH_32);
x86_l_1fd8:
	/* 0x1fd8: cmovne eax,ebx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RBX, X86_WIDTH_32, X86_CC_NE);
x86_l_1fdb:
	/* 0x1fdb: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fdf:
	/* 0x1fdf: mov    edx,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fe1:
	/* 0x1fe1: cmp    eax,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_1fe3:
	/* 0x1fe3: mov    rsi,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_host_ep_id)));
x86_l_1fea:
	/* 0x1fea: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1fed:
	/* 0x1fed: cmovae eax,edx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RDX, X86_WIDTH_32, X86_CC_AE);
x86_l_1ff0:
	/* 0x1ff0: mov    edx,DWORD PTR [rdi+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_1ff3:
	/* 0x1ff3: mov    WORD PTR [rsp+0x10],0x404 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 68719477764ULL);
x86_l_1ffa:
	/* 0x1ffa: mov    WORD PTR [rsp+0x12],si */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_1fff:
	/* 0x1fff: mov    DWORD PTR [rsp+0x14],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2003:
	/* 0x2003: mov    DWORD PTR [rsp+0x18],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2008:
	/* 0x2008: mov    WORD PTR [rsp+0x1c],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_200d:
	/* 0x200d: mov    WORD PTR [rsp+0x1e],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 128849018882ULL);
x86_l_2014:
	/* 0x2014: mov    DWORD PTR [rsp+0x20],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953482ULL);
x86_l_201c:
	/* 0x201c: mov    DWORD PTR [rsp+0x24],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2020:
	/* 0x2020: mov    WORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_2027:
	/* 0x2027: mov    BYTE PTR [rsp+0x2a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 180388626432ULL);
x86_l_202c:
	/* 0x202c: mov    BYTE PTR [rsp+0x2b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_2030:
	/* 0x2030: mov    DWORD PTR [rsp+0x2c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561025ULL);
x86_l_2038:
	/* 0x2038: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_203d:
	/* 0x203d: mov    QWORD PTR [rsp+0x40],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2042:
	/* 0x2042: shl    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_2046:
	/* 0x2046: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_204b:
	/* 0x204b: or     rdx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_204e:
	/* 0x204e: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_2057:
	/* 0x2057: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_2060:
	/* 0x2060: mov    rsi,QWORD PTR [rip+0x88da] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_events)));
x86_l_2067:
	/* 0x2067: lea    rcx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_206c:
	/* 0x206c: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_2071:
	/* 0x2071: mov    r8d,0x38 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 56ULL);
x86_l_2077:
	/* 0x2077: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2079:
	/* 0x2079: test   BYTE PTR [r14+0x17],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 98784247812ULL);
x86_l_207e:
	/* 0x207e: jne    20f8 <tail_nodeport_nat_egress_ipv6+0x20f8> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x207e, 0x20f8, x86_l_20f8);
x86_l_2080:
	/* 0x2080: mov    eax,DWORD PTR [r14+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2084:
	/* 0x2084: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_208d:
	/* 0x208d: mov    DWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_2095:
	/* 0x2095: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_209e:
	/* 0x209e: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_20a7:
	/* 0x20a7: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_20b0:
	/* 0x20b0: mov    DWORD PTR [rsp+0x10],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476738ULL);
x86_l_20b8:
	/* 0x20b8: movbe  DWORD PTR [rsp+0x14],eax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 20ULL);
x86_l_20be:
	/* 0x20be: mov    BYTE PTR [rsp+0x25],0x40 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 158913790016ULL);
x86_l_20c3:
	/* 0x20c3: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20c8:
	/* 0x20c8: mov    eax,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 21ULL);
x86_l_20cd:
	/* 0x20cd: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20d1:
	/* 0x20d1: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_20d4:
	/* 0x20d4: mov    edx,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 28ULL);
x86_l_20d9:
	/* 0x20d9: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_20de:
	/* 0x20de: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20e0:
	/* 0x20e0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_20e2:
	/* 0x20e2: jns    2165 <tail_nodeport_nat_egress_ipv6+0x2165> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x20e2, 0x2165, x86_l_2165);
x86_l_20e8:
	/* 0x20e8: jmp    1d64 <tail_nodeport_nat_egress_ipv6+0x1d64> */
	X86_SIM_X86_JMP(0x20e8, 0x1d64, x86_l_1d64);
x86_l_20ed:
	/* 0x20ed: inc    QWORD PTR [r12] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_20f1:
	/* 0x20f1: test   BYTE PTR [r14+0x17],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 98784247812ULL);
x86_l_20f6:
	/* 0x20f6: je     2080 <tail_nodeport_nat_egress_ipv6+0x2080> */
	X86_SIM_X86_JCC(X86_CC_E, 0x20f6, 0x2080, x86_l_2080);
x86_l_20f8:
	/* 0x20f8: mov    QWORD PTR [rsp+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_2101:
	/* 0x2101: mov    QWORD PTR [rsp+0x2c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188978561024ULL);
x86_l_210a:
	/* 0x210a: mov    QWORD PTR [rsp+0x24],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 154618822656ULL);
x86_l_2113:
	/* 0x2113: mov    DWORD PTR [rsp+0x10],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476738ULL);
x86_l_211b:
	/* 0x211b: mov    eax,DWORD PTR [r14+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_211f:
	/* 0x211f: mov    DWORD PTR [rsp+0x14],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2123:
	/* 0x2123: mov    eax,DWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2127:
	/* 0x2127: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_212b:
	/* 0x212b: mov    eax,DWORD PTR [r14+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_212f:
	/* 0x212f: mov    DWORD PTR [rsp+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2133:
	/* 0x2133: mov    eax,DWORD PTR [r14+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2137:
	/* 0x2137: mov    DWORD PTR [rsp+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_213b:
	/* 0x213b: mov    BYTE PTR [rsp+0x25],0x40 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 158913790016ULL);
x86_l_2140:
	/* 0x2140: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2145:
	/* 0x2145: mov    eax,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 21ULL);
x86_l_214a:
	/* 0x214a: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_214e:
	/* 0x214e: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_2151:
	/* 0x2151: mov    edx,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 28ULL);
x86_l_2156:
	/* 0x2156: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_215b:
	/* 0x215b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_215d:
	/* 0x215d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_215f:
	/* 0x215f: js     1d64 <tail_nodeport_nat_egress_ipv6+0x1d64> */
	X86_SIM_X86_JCC(X86_CC_S, 0x215f, 0x1d64, x86_l_1d64);
x86_l_2165:
	/* 0x2165: mov    eax,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 23ULL);
x86_l_216a:
	/* 0x216a: mov    edi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 1ULL);
x86_l_216f:
	/* 0x216f: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2171:
	/* 0x2171: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2173:
	/* 0x2173: mov    r14d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_32);
x86_l_2176:
	/* 0x2176: jmp    683 <tail_nodeport_nat_egress_ipv6+0x683> */
	X86_SIM_X86_JMP(0x2176, 0x683, x86_l_683);
x86_l_217b:
	/* 0x217b: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_217f:
	/* 0x217f: jmp    119 <tail_nodeport_nat_egress_ipv6+0x119> */
	X86_SIM_X86_JMP(0x217f, 0x119, x86_l_119);
x86_l_2184:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
