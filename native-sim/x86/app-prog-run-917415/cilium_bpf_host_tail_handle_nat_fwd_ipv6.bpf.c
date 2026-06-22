extern char __config_debug_lb;
extern char __config_enable_conntrack_accounting;
extern char __config_enable_ipv6_fragments;
extern char __config_enable_jiffies;
extern char __config_eth_header_length;
extern char __config_events_map_burst_limit;
extern char __config_events_map_rate_limit;
extern char __config_host_ep_id;
extern char __config_interface_ifindex;
extern char __config_kernel_hz;
extern char __config_supports_fib_lookup_skip_neigh;
extern char __config_trace_payload_len;
extern char __config_trace_payload_len_overlay;
extern char __config_tracing_ip_option_type;
extern char __config_tunnel_protocol;
extern char cilium_calls;
extern char cilium_ct6_global;
extern char cilium_ct_any6_global;
extern char cilium_devices;
extern char cilium_events;
extern char cilium_ipv6_frag_datagrams;
extern char cilium_lb6_reverse_nat;
extern char cilium_metrics;
extern char cilium_percpu_trace_id;
extern char cilium_ratelimit;
extern char cilium_ratelimit_metrics;
extern char cilium_snat_v6_external;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int cilium_bpf_host_tail_handle_nat_fwd_ipv6_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0xf8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 248ULL);
x86_l_a:
	/* 0xa: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: mov    r14d,DWORD PTR [rdi+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_11:
	/* 0x11: mov    eax,DWORD PTR [rdi+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_14:
	/* 0x14: mov    DWORD PTR [rsp+0x4c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_18:
	/* 0x18: mov    DWORD PTR [rdi+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1f:
	/* 0x1f: mov    DWORD PTR [rdi+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_26:
	/* 0x26: mov    rax,QWORD PTR [rip+0x119a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_2d:
	/* 0x2d: mov    r13d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30:
	/* 0x30: mov    DWORD PTR [rsp+0xe8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 996432412672ULL);
x86_l_3b:
	/* 0x3b: mov    QWORD PTR [rsp+0xe0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 962072674304ULL);
x86_l_47:
	/* 0x47: mov    QWORD PTR [rsp+0xd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 927712935936ULL);
x86_l_53:
	/* 0x53: mov    QWORD PTR [rsp+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_5f:
	/* 0x5f: mov    QWORD PTR [rsp+0xc8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 858993459200ULL);
x86_l_6b:
	/* 0x6b: mov    QWORD PTR [rsp+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_77:
	/* 0x77: mov    QWORD PTR [rsp+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_83:
	/* 0x83: mov    QWORD PTR [rsp+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_8f:
	/* 0x8f: mov    QWORD PTR [rsp+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_9b:
	/* 0x9b: mov    QWORD PTR [rsp+0x7e],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 541165879296ULL);
x86_l_a4:
	/* 0xa4: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_ad:
	/* 0xad: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_b6:
	/* 0xb6: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_bf:
	/* 0xbf: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_c8:
	/* 0xc8: mov    rdi,QWORD PTR [rip+0x119a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_cf:
	/* 0xcf: movzx  eax,BYTE PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_d2:
	/* 0xd2: mov    r15d,DWORD PTR [rbx+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_d6:
	/* 0xd6: mov    ecx,DWORD PTR [rbx+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_d9:
	/* 0xd9: lea    rdx,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_dd:
	/* 0xdd: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_e1:
	/* 0xe1: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_e6:
	/* 0xe6: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e9:
	/* 0xe9: mov    BYTE PTR [rsp+0xc],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 51539607557ULL);
x86_l_ee:
	/* 0xee: cmp    rdx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_f1:
	/* 0xf1: ja     480 <tail_handle_nat_fwd_ipv6+0x480> */
	X86_SIM_X86_JCC(X86_CC_A, 0xf1, 0x480, x86_l_480);
x86_l_f7:
	/* 0xf7: mov    DWORD PTR [rsp+0x8],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fc:
	/* 0xfc: add    r15,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_ff:
	/* 0xff: movzx  r13d,BYTE PTR [r15+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_104:
	/* 0x104: movzx  r12d,BYTE PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_108:
	/* 0x108: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10b:
	/* 0x10b: mov    BYTE PTR [rsp+0x84],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_113:
	/* 0x113: mov    esi,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 40ULL);
x86_l_118:
	/* 0x118: cmp    r13,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 60ULL);
x86_l_11c:
	/* 0x11c: ja     a2f <tail_handle_nat_fwd_ipv6+0xa2f> */
	X86_SIM_X86_JCC(X86_CC_A, 0x11c, 0xa2f, x86_l_a2f);
x86_l_122:
	/* 0x122: mov    eax,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967140ULL);
x86_l_127:
	/* 0x127: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_131:
	/* 0x131: bt     rcx,r13 */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_135:
	/* 0x135: jae    1d4 <tail_handle_nat_fwd_ipv6+0x1d4> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x135, 0x1d4, x86_l_1d4);
x86_l_13b:
	/* 0x13b: mov    DWORD PTR [rsp+0x4],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_140:
	/* 0x140: lea    r14d,[r12+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_145:
	/* 0x145: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_14a:
	/* 0x14a: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_14f:
	/* 0x14f: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_152:
	/* 0x152: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_155:
	/* 0x155: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_15a:
	/* 0x15a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15c:
	/* 0x15c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_15e:
	/* 0x15e: js     1a3 <tail_handle_nat_fwd_ipv6+0x1a3> */
	X86_SIM_X86_JCC(X86_CC_S, 0x15e, 0x1a3, x86_l_1a3);
x86_l_160:
	/* 0x160: movzx  edx,BYTE PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 32ULL);
x86_l_165:
	/* 0x165: cmp    r13d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 43ULL);
x86_l_169:
	/* 0x169: mov    QWORD PTR [rsp+0x18],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_16e:
	/* 0x16e: jle    18b <tail_handle_nat_fwd_ipv6+0x18b> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x16e, 0x18b, x86_l_18b);
x86_l_170:
	/* 0x170: cmp    r13d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 60ULL);
x86_l_174:
	/* 0x174: je     18b <tail_handle_nat_fwd_ipv6+0x18b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x174, 0x18b, x86_l_18b);
x86_l_176:
	/* 0x176: cmp    r13d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 51ULL);
x86_l_17a:
	/* 0x17a: jne    1e3 <tail_handle_nat_fwd_ipv6+0x1e3> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x17a, 0x1e3, x86_l_1e3);
x86_l_17c:
	/* 0x17c: movzx  eax,BYTE PTR [rsp+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_181:
	/* 0x181: lea    r12d,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_189:
	/* 0x189: jmp    1b2 <tail_handle_nat_fwd_ipv6+0x1b2> */
	X86_SIM_X86_JMP(0x189, 0x1b2, x86_l_1b2);
x86_l_18b:
	/* 0x18b: movzx  eax,BYTE PTR [rsp+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_190:
	/* 0x190: lea    r12d,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_198:
	/* 0x198: cmp    r13b,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_8, 44ULL);
x86_l_19c:
	/* 0x19c: jne    1b2 <tail_handle_nat_fwd_ipv6+0x1b2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x19c, 0x1b2, x86_l_1b2);
x86_l_19e:
	/* 0x19e: mov    r13d,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_32);
x86_l_1a1:
	/* 0x1a1: jmp    1ec <tail_handle_nat_fwd_ipv6+0x1ec> */
	X86_SIM_X86_JMP(0x1a1, 0x1ec, x86_l_1ec);
x86_l_1a3:
	/* 0x1a3: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_1a8:
	/* 0x1a8: mov    r14d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1ad:
	/* 0x1ad: jmp    476 <tail_handle_nat_fwd_ipv6+0x476> */
	X86_SIM_X86_JMP(0x1ad, 0x476, x86_l_476);
x86_l_1b2:
	/* 0x1b2: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b5:
	/* 0x1b5: mov    rdi,QWORD PTR [rip+0x119a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_1bc:
	/* 0x1bc: movzx  r14d,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1c0:
	/* 0x1c0: lea    esi,[r12+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1c5:
	/* 0x1c5: cmp    r14d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 60ULL);
x86_l_1c9:
	/* 0x1c9: jbe    272 <tail_handle_nat_fwd_ipv6+0x272> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x1c9, 0x272, x86_l_272);
x86_l_1cf:
	/* 0x1cf: jmp    a27 <tail_handle_nat_fwd_ipv6+0xa27> */
	X86_SIM_X86_JMP(0x1cf, 0xa27, x86_l_a27);
x86_l_1d4:
	/* 0x1d4: cmp    r13,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_64, 59ULL);
x86_l_1d8:
	/* 0x1d8: je     476 <tail_handle_nat_fwd_ipv6+0x476> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1d8, 0x476, x86_l_476);
x86_l_1de:
	/* 0x1de: jmp    a2f <tail_handle_nat_fwd_ipv6+0xa2f> */
	X86_SIM_X86_JMP(0x1de, 0xa2f, x86_l_a2f);
x86_l_1e3:
	/* 0x1e3: mov    r13d,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_32);
x86_l_1e6:
	/* 0x1e6: mov    r12d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 8ULL);
x86_l_1ec:
	/* 0x1ec: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1f5:
	/* 0x1f5: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1fa:
	/* 0x1fa: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1ff:
	/* 0x1ff: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_202:
	/* 0x202: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_205:
	/* 0x205: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_20a:
	/* 0x20a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20c:
	/* 0x20c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_20e:
	/* 0x20e: js     a15 <tail_handle_nat_fwd_ipv6+0xa15> */
	X86_SIM_X86_JCC(X86_CC_S, 0x20e, 0xa15, x86_l_a15);
x86_l_214:
	/* 0x214: mov    eax,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_218:
	/* 0x218: movzx  ecx,BYTE PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 32ULL);
x86_l_21d:
	/* 0x21d: shl    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_221:
	/* 0x221: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_224:
	/* 0x224: movzx  eax,WORD PTR [rsp+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_229:
	/* 0x229: movabs rdx,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1099511627776ULL);
x86_l_233:
	/* 0x233: or     rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_236:
	/* 0x236: test   eax,0xf9ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63999ULL);
x86_l_23b:
	/* 0x23b: cmove  rdx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_64, X86_CC_E);
x86_l_23f:
	/* 0x23f: movabs r8,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_64, 2199023255552ULL);
x86_l_249:
	/* 0x249: or     r8,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDX, X86_WIDTH_64, X86_ALU_OR);
x86_l_24c:
	/* 0x24c: test   eax,0xf8ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63743ULL);
x86_l_251:
	/* 0x251: cmove  r8,rdx */
	X86_SIM_L_EXEC_CMOV(X86_R8, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_255:
	/* 0x255: mov    rdi,QWORD PTR [rip+0x119a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_25c:
	/* 0x25c: mov    edx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_32);
x86_l_25f:
	/* 0x25f: movzx  r14d,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_263:
	/* 0x263: lea    esi,[r12+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_268:
	/* 0x268: cmp    r14d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 60ULL);
x86_l_26c:
	/* 0x26c: ja     a27 <tail_handle_nat_fwd_ipv6+0xa27> */
	X86_SIM_X86_JCC(X86_CC_A, 0x26c, 0xa27, x86_l_a27);
x86_l_272:
	/* 0x272: mov    eax,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_32);
x86_l_275:
	/* 0x275: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_27f:
	/* 0x27f: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_283:
	/* 0x283: jae    30c <tail_handle_nat_fwd_ipv6+0x30c> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x283, 0x30c, x86_l_30c);
x86_l_289:
	/* 0x289: mov    BYTE PTR [rsp+0xf0],dl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_290:
	/* 0x290: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_293:
	/* 0x293: mov    rbx,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R8, X86_WIDTH_64);
x86_l_296:
	/* 0x296: mov    QWORD PTR [rsp+0x10],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_29b:
	/* 0x29b: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2a0:
	/* 0x2a0: lea    r12d,[r12+rax*1+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 40ULL);
x86_l_2a5:
	/* 0x2a5: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2aa:
	/* 0x2aa: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_2af:
	/* 0x2af: mov    QWORD PTR [rsp+0x50],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2b4:
	/* 0x2b4: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_2b7:
	/* 0x2b7: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2bc:
	/* 0x2bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2be:
	/* 0x2be: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2c0:
	/* 0x2c0: js     451 <tail_handle_nat_fwd_ipv6+0x451> */
	X86_SIM_X86_JCC(X86_CC_S, 0x2c0, 0x451, x86_l_451);
x86_l_2c6:
	/* 0x2c6: movzx  r13d,BYTE PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 32ULL);
x86_l_2cc:
	/* 0x2cc: cmp    r14d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 43ULL);
x86_l_2d0:
	/* 0x2d0: mov    rdi,QWORD PTR [rip+0x119a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_2d7:
	/* 0x2d7: mov    r8,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RBX, X86_WIDTH_64);
x86_l_2da:
	/* 0x2da: jle    314 <tail_handle_nat_fwd_ipv6+0x314> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x2da, 0x314, x86_l_314);
x86_l_2dc:
	/* 0x2dc: cmp    r14d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 44ULL);
x86_l_2e0:
	/* 0x2e0: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e5:
	/* 0x2e5: mov    rbx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2ea:
	/* 0x2ea: je     33a <tail_handle_nat_fwd_ipv6+0x33a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2ea, 0x33a, x86_l_33a);
x86_l_2ec:
	/* 0x2ec: cmp    r14d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 51ULL);
x86_l_2f0:
	/* 0x2f0: movzx  ecx,BYTE PTR [rsp+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 240ULL);
x86_l_2f8:
	/* 0x2f8: jne    326 <tail_handle_nat_fwd_ipv6+0x326> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2f8, 0x326, x86_l_326);
x86_l_2fa:
	/* 0x2fa: movzx  eax,BYTE PTR [rsp+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_2ff:
	/* 0x2ff: lea    r14d,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_307:
	/* 0x307: jmp    3b5 <tail_handle_nat_fwd_ipv6+0x3b5> */
	X86_SIM_X86_JMP(0x307, 0x3b5, x86_l_3b5);
x86_l_30c:
	/* 0x30c: mov    r13d,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_32);
x86_l_30f:
	/* 0x30f: jmp    462 <tail_handle_nat_fwd_ipv6+0x462> */
	X86_SIM_X86_JMP(0x30f, 0x462, x86_l_462);
x86_l_314:
	/* 0x314: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_319:
	/* 0x319: mov    rbx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_31e:
	/* 0x31e: movzx  ecx,BYTE PTR [rsp+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 240ULL);
x86_l_326:
	/* 0x326: movzx  eax,BYTE PTR [rsp+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_32b:
	/* 0x32b: lea    r14d,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_333:
	/* 0x333: cmp    cl,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 44ULL);
x86_l_336:
	/* 0x336: je     340 <tail_handle_nat_fwd_ipv6+0x340> */
	X86_SIM_X86_JCC(X86_CC_E, 0x336, 0x340, x86_l_340);
x86_l_338:
	/* 0x338: jmp    3b5 <tail_handle_nat_fwd_ipv6+0x3b5> */
	X86_SIM_X86_JMP(0x338, 0x3b5, x86_l_3b5);
x86_l_33a:
	/* 0x33a: mov    r14d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 8ULL);
x86_l_340:
	/* 0x340: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_349:
	/* 0x349: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_34e:
	/* 0x34e: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_353:
	/* 0x353: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_356:
	/* 0x356: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_359:
	/* 0x359: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_35e:
	/* 0x35e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_360:
	/* 0x360: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_362:
	/* 0x362: js     a15 <tail_handle_nat_fwd_ipv6+0xa15> */
	X86_SIM_X86_JCC(X86_CC_S, 0x362, 0xa15, x86_l_a15);
x86_l_368:
	/* 0x368: mov    eax,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_36c:
	/* 0x36c: movzx  ecx,BYTE PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 32ULL);
x86_l_371:
	/* 0x371: shl    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_375:
	/* 0x375: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_378:
	/* 0x378: movzx  eax,WORD PTR [rsp+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_37d:
	/* 0x37d: movabs rdx,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1099511627776ULL);
x86_l_387:
	/* 0x387: or     rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_38a:
	/* 0x38a: test   eax,0xf9ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63999ULL);
x86_l_38f:
	/* 0x38f: cmove  rdx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_64, X86_CC_E);
x86_l_393:
	/* 0x393: movabs r8,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_64, 2199023255552ULL);
x86_l_39d:
	/* 0x39d: or     r8,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDX, X86_WIDTH_64, X86_ALU_OR);
x86_l_3a0:
	/* 0x3a0: test   eax,0xf8ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63743ULL);
x86_l_3a5:
	/* 0x3a5: cmove  r8,rdx */
	X86_SIM_L_EXEC_CMOV(X86_R8, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_3a9:
	/* 0x3a9: mov    rdi,QWORD PTR [rip+0x119a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_3b0:
	/* 0x3b0: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3b5:
	/* 0x3b5: movzx  r12d,r13b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R13, X86_WIDTH_32, X86_WIDTH_8);
x86_l_3b9:
	/* 0x3b9: add    esi,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R14, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3bc:
	/* 0x3bc: cmp    r12d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 60ULL);
x86_l_3c0:
	/* 0x3c0: ja     a2a <tail_handle_nat_fwd_ipv6+0xa2a> */
	X86_SIM_X86_JCC(X86_CC_A, 0x3c0, 0xa2a, x86_l_a2a);
x86_l_3c6:
	/* 0x3c6: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_3c9:
	/* 0x3c9: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_3d3:
	/* 0x3d3: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_3d7:
	/* 0x3d7: jae    462 <tail_handle_nat_fwd_ipv6+0x462> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x3d7, 0x462, x86_l_462);
x86_l_3dd:
	/* 0x3dd: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_3e0:
	/* 0x3e0: mov    rbx,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R8, X86_WIDTH_64);
x86_l_3e3:
	/* 0x3e3: mov    QWORD PTR [rsp+0x10],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e8:
	/* 0x3e8: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3ed:
	/* 0x3ed: lea    r14d,[rsi+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_3f1:
	/* 0x3f1: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3f6:
	/* 0x3f6: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_3fb:
	/* 0x3fb: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_3fe:
	/* 0x3fe: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_403:
	/* 0x403: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_405:
	/* 0x405: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_407:
	/* 0x407: js     451 <tail_handle_nat_fwd_ipv6+0x451> */
	X86_SIM_X86_JCC(X86_CC_S, 0x407, 0x451, x86_l_451);
x86_l_409:
	/* 0x409: movzx  edx,BYTE PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 32ULL);
x86_l_40e:
	/* 0x40e: cmp    r12d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 43ULL);
x86_l_412:
	/* 0x412: mov    rdi,QWORD PTR [rip+0x119a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_419:
	/* 0x419: mov    r8,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RBX, X86_WIDTH_64);
x86_l_41c:
	/* 0x41c: jle    8cd <tail_handle_nat_fwd_ipv6+0x8cd> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x41c, 0x8cd, x86_l_8cd);
x86_l_422:
	/* 0x422: cmp    r12d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 44ULL);
x86_l_426:
	/* 0x426: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_42b:
	/* 0x42b: mov    rbx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_430:
	/* 0x430: je     8ee <tail_handle_nat_fwd_ipv6+0x8ee> */
	X86_SIM_X86_JCC(X86_CC_E, 0x430, 0x8ee, x86_l_8ee);
x86_l_436:
	/* 0x436: cmp    r12d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 51ULL);
x86_l_43a:
	/* 0x43a: jne    8d7 <tail_handle_nat_fwd_ipv6+0x8d7> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x43a, 0x8d7, x86_l_8d7);
x86_l_440:
	/* 0x440: movzx  eax,BYTE PTR [rsp+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_445:
	/* 0x445: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_44c:
	/* 0x44c: jmp    974 <tail_handle_nat_fwd_ipv6+0x974> */
	X86_SIM_X86_JMP(0x44c, 0x974, x86_l_974);
x86_l_451:
	/* 0x451: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_456:
	/* 0x456: mov    r14d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_45b:
	/* 0x45b: mov    rbx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_460:
	/* 0x460: jmp    476 <tail_handle_nat_fwd_ipv6+0x476> */
	X86_SIM_X86_JMP(0x460, 0x476, x86_l_476);
x86_l_462:
	/* 0x462: cmp    rax,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 59ULL);
x86_l_466:
	/* 0x466: mov    r14d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_46b:
	/* 0x46b: mov    eax,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967140ULL);
x86_l_470:
	/* 0x470: jne    a2f <tail_handle_nat_fwd_ipv6+0xa2f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x470, 0xa2f, x86_l_a2f);
x86_l_476:
	/* 0x476: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_479:
	/* 0x479: mov    ebp,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_47b:
	/* 0x47b: mov    r13d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_480:
	/* 0x480: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_482:
	/* 0x482: js     16c8 <tail_handle_nat_fwd_ipv6+0x16c8> */
	X86_SIM_X86_JCC(X86_CC_S, 0x482, 0x16c8, x86_l_16c8);
x86_l_488:
	/* 0x488: cmp    ebp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_48b:
	/* 0x48b: je     16c8 <tail_handle_nat_fwd_ipv6+0x16c8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x48b, 0x16c8, x86_l_16c8);
x86_l_491:
	/* 0x491: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_493:
	/* 0x493: jne    8b7 <tail_handle_nat_fwd_ipv6+0x8b7> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x493, 0x8b7, x86_l_8b7);
x86_l_499:
	/* 0x499: mov    rax,QWORD PTR [rip+0x119a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_interface_ifindex)));
x86_l_4a0:
	/* 0x4a0: mov    r15d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4a3:
	/* 0x4a3: mov    rax,QWORD PTR [rip+0x119a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_tracing_ip_option_type)));
x86_l_4aa:
	/* 0x4aa: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ad:
	/* 0x4ad: je     4da <tail_handle_nat_fwd_ipv6+0x4da> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4ad, 0x4da, x86_l_4da);
x86_l_4af:
	/* 0x4af: mov    DWORD PTR [rsp+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_4ba:
	/* 0x4ba: mov    rdi,QWORD PTR [rip+0x119a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_percpu_trace_id)));
x86_l_4c1:
	/* 0x4c1: lea    rsi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_4c9:
	/* 0x4c9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4ce:
	/* 0x4ce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d0:
	/* 0x4d0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4d3:
	/* 0x4d3: je     4e2 <tail_handle_nat_fwd_ipv6+0x4e2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4d3, 0x4e2, x86_l_4e2);
x86_l_4d5:
	/* 0x4d5: mov    r12,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4d8:
	/* 0x4d8: jmp    4e5 <tail_handle_nat_fwd_ipv6+0x4e5> */
	X86_SIM_X86_JMP(0x4d8, 0x4e5, x86_l_4e5);
x86_l_4da:
	/* 0x4da: mov    ebp,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R14, X86_WIDTH_32);
x86_l_4dd:
	/* 0x4dd: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4e0:
	/* 0x4e0: jmp    4e8 <tail_handle_nat_fwd_ipv6+0x4e8> */
	X86_SIM_X86_JMP(0x4e0, 0x4e8, x86_l_4e8);
x86_l_4e2:
	/* 0x4e2: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4e5:
	/* 0x4e5: mov    ebp,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R14, X86_WIDTH_32);
x86_l_4e8:
	/* 0x4e8: mov    r14d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4eb:
	/* 0x4eb: mov    QWORD PTR [rsp+0x90],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290626ULL);
x86_l_4f7:
	/* 0x4f7: mov    QWORD PTR [rsp+0xd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 927712935936ULL);
x86_l_503:
	/* 0x503: mov    QWORD PTR [rsp+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_50f:
	/* 0x50f: mov    QWORD PTR [rsp+0xc8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 858993459200ULL);
x86_l_51b:
	/* 0x51b: mov    QWORD PTR [rsp+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_527:
	/* 0x527: mov    QWORD PTR [rsp+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_533:
	/* 0x533: mov    QWORD PTR [rsp+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_53f:
	/* 0x53f: mov    QWORD PTR [rsp+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_54b:
	/* 0x54b: movabs rax,0x7101180200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 485349655040ULL);
x86_l_555:
	/* 0x555: or     rax,0x50000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_OR, 327680ULL);
x86_l_55b:
	/* 0x55b: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_560:
	/* 0x560: mov    rdi,QWORD PTR [rip+0x119a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_567:
	/* 0x567: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_56c:
	/* 0x56c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_571:
	/* 0x571: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_573:
	/* 0x573: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_576:
	/* 0x576: je     593 <tail_handle_nat_fwd_ipv6+0x593> */
	X86_SIM_X86_JCC(X86_CC_E, 0x576, 0x593, x86_l_593);
x86_l_578:
	/* 0x578: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_57b:
	/* 0x57b: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_57f:
	/* 0x57f: mov    r9,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_R14, X86_WIDTH_64);
x86_l_582:
	/* 0x582: test   r13d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_32);
x86_l_585:
	/* 0x585: mov    rdx,QWORD PTR [rip+0x119a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_58c:
	/* 0x58c: jne    5ce <tail_handle_nat_fwd_ipv6+0x5ce> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x58c, 0x5ce, x86_l_5ce);
x86_l_58e:
	/* 0x58e: jmp    8b5 <tail_handle_nat_fwd_ipv6+0x8b5> */
	X86_SIM_X86_JMP(0x58e, 0x8b5, x86_l_8b5);
x86_l_593:
	/* 0x593: mov    QWORD PTR [rsp+0x20],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953473ULL);
x86_l_59c:
	/* 0x59c: mov    QWORD PTR [rsp+0x28],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5a1:
	/* 0x5a1: mov    rdi,QWORD PTR [rip+0x119a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_5a8:
	/* 0x5a8: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_5ad:
	/* 0x5ad: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5b2:
	/* 0x5b2: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5b7:
	/* 0x5b7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5b9:
	/* 0x5b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5bb:
	/* 0x5bb: mov    r9,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_R14, X86_WIDTH_64);
x86_l_5be:
	/* 0x5be: test   r13d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_32);
x86_l_5c1:
	/* 0x5c1: mov    rdx,QWORD PTR [rip+0x119a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_5c8:
	/* 0x5c8: je     8b5 <tail_handle_nat_fwd_ipv6+0x8b5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5c8, 0x8b5, x86_l_8b5);
x86_l_5ce:
	/* 0x5ce: mov    rax,QWORD PTR [rip+0x119a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_events_map_rate_limit)));
x86_l_5d5:
	/* 0x5d5: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5d8:
	/* 0x5d8: mov    r11d,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R15, X86_WIDTH_32);
x86_l_5db:
	/* 0x5db: je     76a <tail_handle_nat_fwd_ipv6+0x76a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5db, 0x76a, x86_l_76a);
x86_l_5e1:
	/* 0x5e1: mov    QWORD PTR [rsp+0x10],r9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5e6:
	/* 0x5e6: mov    QWORD PTR [rsp+0x18],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5eb:
	/* 0x5eb: mov    DWORD PTR [rsp+0x4c],r11d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_5f0:
	/* 0x5f0: mov    DWORD PTR [rsp+0x8],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5f5:
	/* 0x5f5: mov    DWORD PTR [rsp+0x4],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_5f9:
	/* 0x5f9: mov    rcx,QWORD PTR [rip+0x119a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_events_map_burst_limit)));
x86_l_600:
	/* 0x600: mov    r15d,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_603:
	/* 0x603: mov    r13d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_606:
	/* 0x606: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_60b:
	/* 0x60b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_60d:
	/* 0x60d: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_60f:
	/* 0x60f: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_612:
	/* 0x612: mov    DWORD PTR [rsp+0x58],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 377957122050ULL);
x86_l_61a:
	/* 0x61a: mov    rdi,QWORD PTR [rip+0x119a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit_metrics)));
x86_l_621:
	/* 0x621: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_626:
	/* 0x626: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_62b:
	/* 0x62b: call   rbp */
	X86_SIM_BPF_CALL_REG(X86_RBP);
x86_l_62d:
	/* 0x62d: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_630:
	/* 0x630: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_633:
	/* 0x633: jne    663 <tail_handle_nat_fwd_ipv6+0x663> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x633, 0x663, x86_l_663);
x86_l_635:
	/* 0x635: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_63e:
	/* 0x63e: mov    rdi,QWORD PTR [rip+0x119a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit_metrics)));
x86_l_645:
	/* 0x645: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_64a:
	/* 0x64a: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_64f:
	/* 0x64f: lea    r14,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_654:
	/* 0x654: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_657:
	/* 0x657: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_659:
	/* 0x659: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_65b:
	/* 0x65b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_65d:
	/* 0x65d: js     8b5 <tail_handle_nat_fwd_ipv6+0x8b5> */
	X86_SIM_X86_JCC(X86_CC_S, 0x65d, 0x8b5, x86_l_8b5);
x86_l_663:
	/* 0x663: mov    rdi,QWORD PTR [rip+0x119a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit)));
x86_l_66a:
	/* 0x66a: lea    rsi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_672:
	/* 0x672: call   rbp */
	X86_SIM_BPF_CALL_REG(X86_RBP);
x86_l_674:
	/* 0x674: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_677:
	/* 0x677: je     6ee <tail_handle_nat_fwd_ipv6+0x6ee> */
	X86_SIM_X86_JCC(X86_CC_E, 0x677, 0x6ee, x86_l_6ee);
x86_l_679:
	/* 0x679: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_67c:
	/* 0x67c: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_67f:
	/* 0x67f: sub    rsi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_682:
	/* 0x682: cmp    rsi,0x3b9aca00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 1000000000ULL);
x86_l_689:
	/* 0x689: mov    r11d,DWORD PTR [rsp+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_68e:
	/* 0x68e: jbe    73c <tail_handle_nat_fwd_ipv6+0x73c> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x68e, 0x73c, x86_l_73c);
x86_l_694:
	/* 0x694: mov    rdx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_697:
	/* 0x697: shr    rdx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_69b:
	/* 0x69b: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_6a5:
	/* 0x6a5: mulx   rcx,rcx,rcx */
	X86_SIM_L_EXEC_MULX(X86_RCX, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_6aa:
	/* 0x6aa: shr    rcx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_6ae:
	/* 0x6ae: imul   rdx,rcx,0x3b9aca00 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RDX, X86_RCX, X86_WIDTH_64, 1000000000ULL);
x86_l_6b5:
	/* 0x6b5: imul   rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_IMUL);
x86_l_6b9:
	/* 0x6b9: add    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_6bd:
	/* 0x6bd: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6c1:
	/* 0x6c1: sub    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_6c4:
	/* 0x6c4: add    r12,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_6c7:
	/* 0x6c7: mov    QWORD PTR [rax],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6ca:
	/* 0x6ca: cmp    rcx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_6cd:
	/* 0x6cd: mov    rdx,QWORD PTR [rip+0x119a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_6d4:
	/* 0x6d4: mov    r13d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6d9:
	/* 0x6d9: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6de:
	/* 0x6de: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6e3:
	/* 0x6e3: jbe    756 <tail_handle_nat_fwd_ipv6+0x756> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x6e3, 0x756, x86_l_756);
x86_l_6e5:
	/* 0x6e5: mov    QWORD PTR [rax+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6e9:
	/* 0x6e9: mov    rcx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_6ec:
	/* 0x6ec: jmp    756 <tail_handle_nat_fwd_ipv6+0x756> */
	X86_SIM_X86_JMP(0x6ec, 0x756, x86_l_756);
x86_l_6ee:
	/* 0x6ee: mov    QWORD PTR [rsp+0x20],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6f3:
	/* 0x6f3: dec    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_6f6:
	/* 0x6f6: mov    QWORD PTR [rsp+0x28],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6fb:
	/* 0x6fb: mov    rdi,QWORD PTR [rip+0x119a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit)));
x86_l_702:
	/* 0x702: lea    rsi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_70a:
	/* 0x70a: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_70f:
	/* 0x70f: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_714:
	/* 0x714: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_716:
	/* 0x716: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_718:
	/* 0x718: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_71a:
	/* 0x71a: mov    rdx,QWORD PTR [rip+0x119a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_721:
	/* 0x721: mov    r13d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_726:
	/* 0x726: mov    r11d,DWORD PTR [rsp+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_72b:
	/* 0x72b: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_730:
	/* 0x730: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_735:
	/* 0x735: jns    766 <tail_handle_nat_fwd_ipv6+0x766> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x735, 0x766, x86_l_766);
x86_l_737:
	/* 0x737: jmp    8c8 <tail_handle_nat_fwd_ipv6+0x8c8> */
	X86_SIM_X86_JMP(0x737, 0x8c8, x86_l_8c8);
x86_l_73c:
	/* 0x73c: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_740:
	/* 0x740: mov    rdx,QWORD PTR [rip+0x119a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_747:
	/* 0x747: mov    r13d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_74c:
	/* 0x74c: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_751:
	/* 0x751: mov    r9,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_756:
	/* 0x756: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_759:
	/* 0x759: je     8c8 <tail_handle_nat_fwd_ipv6+0x8c8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x759, 0x8c8, x86_l_8c8);
x86_l_75f:
	/* 0x75f: dec    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_762:
	/* 0x762: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_766:
	/* 0x766: mov    ebp,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_76a:
	/* 0x76a: cmp    BYTE PTR [rdx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_76d:
	/* 0x76d: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_770:
	/* 0x770: add    al,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_8, X86_ALU_ADD);
x86_l_772:
	/* 0x772: or     al,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_OR, 1ULL);
x86_l_774:
	/* 0x774: mov    ecx,0xf00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 3840ULL);
x86_l_779:
	/* 0x779: and    ecx,DWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 8ULL);
x86_l_77c:
	/* 0x77c: cmp    ecx,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1024ULL);
x86_l_782:
	/* 0x782: jne    7ad <tail_handle_nat_fwd_ipv6+0x7ad> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x782, 0x7ad, x86_l_7ad);
x86_l_784:
	/* 0x784: mov    rdx,QWORD PTR [rip+0x119a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_tunnel_protocol)));
x86_l_78b:
	/* 0x78b: movzx  esi,BYTE PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_78e:
	/* 0x78e: mov    cl,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 4ULL);
x86_l_790:
	/* 0x790: cmp    sil,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_8, 1ULL);
x86_l_794:
	/* 0x794: mov    r8,QWORD PTR [rip+0x119a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R8, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_79b:
	/* 0x79b: je     7a9 <tail_handle_nat_fwd_ipv6+0x7a9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x79b, 0x7a9, x86_l_7a9);
x86_l_79d:
	/* 0x79d: movzx  ecx,BYTE PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_7a0:
	/* 0x7a0: cmp    cl,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_7a3:
	/* 0x7a3: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_7a6:
	/* 0x7a6: shl    cl,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_7a9:
	/* 0x7a9: or     al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_7ab:
	/* 0x7ab: jmp    7b4 <tail_handle_nat_fwd_ipv6+0x7b4> */
	X86_SIM_X86_JMP(0x7ab, 0x7b4, x86_l_7b4);
x86_l_7ad:
	/* 0x7ad: mov    r8,QWORD PTR [rip+0x119a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R8, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_7b4:
	/* 0x7b4: mov    ecx,DWORD PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7b7:
	/* 0x7b7: mov    rsi,QWORD PTR [rip+0x119a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_tunnel_protocol)));
x86_l_7be:
	/* 0x7be: movzx  edi,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_7c1:
	/* 0x7c1: mov    dl,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_8, 4ULL);
x86_l_7c3:
	/* 0x7c3: cmp    dil,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_8, 1ULL);
x86_l_7c7:
	/* 0x7c7: je     7d5 <tail_handle_nat_fwd_ipv6+0x7d5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7c7, 0x7d5, x86_l_7d5);
x86_l_7c9:
	/* 0x7c9: movzx  edx,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_7cc:
	/* 0x7cc: cmp    dl,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_8, 2ULL);
x86_l_7cf:
	/* 0x7cf: sete   dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_E);
x86_l_7d2:
	/* 0x7d2: shl    dl,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_7d5:
	/* 0x7d5: test   dl,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RAX, X86_WIDTH_8);
x86_l_7d7:
	/* 0x7d7: je     7e2 <tail_handle_nat_fwd_ipv6+0x7e2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7d7, 0x7e2, x86_l_7e2);
x86_l_7d9:
	/* 0x7d9: mov    rcx,QWORD PTR [rip+0x119a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_trace_payload_len_overlay)));
x86_l_7e0:
	/* 0x7e0: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7e2:
	/* 0x7e2: mov    edx,DWORD PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7e5:
	/* 0x7e5: cmp    edx,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_32);
x86_l_7e8:
	/* 0x7e8: cmovne ecx,r13d */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_R13, X86_WIDTH_32, X86_CC_NE);
x86_l_7ec:
	/* 0x7ec: mov    edx,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7ee:
	/* 0x7ee: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_7f0:
	/* 0x7f0: mov    rsi,QWORD PTR [rip+0x119a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_host_ep_id)));
x86_l_7f7:
	/* 0x7f7: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_7fa:
	/* 0x7fa: cmovae ecx,edx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_32, X86_CC_AE);
x86_l_7fd:
	/* 0x7fd: mov    edx,DWORD PTR [rbx+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_800:
	/* 0x800: mov    WORD PTR [rsp+0xa8],0xb04 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 721554508548ULL);
x86_l_80a:
	/* 0x80a: mov    WORD PTR [rsp+0xaa],si */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 170ULL);
x86_l_812:
	/* 0x812: mov    DWORD PTR [rsp+0xac],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_819:
	/* 0x819: mov    DWORD PTR [rsp+0xb0],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_821:
	/* 0x821: mov    WORD PTR [rsp+0xb4],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 180ULL);
x86_l_829:
	/* 0x829: mov    WORD PTR [rsp+0xb6],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 781684047874ULL);
x86_l_833:
	/* 0x833: mov    DWORD PTR [rsp+0xb8],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_83a:
	/* 0x83a: mov    DWORD PTR [rsp+0xbc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 807453851648ULL);
x86_l_845:
	/* 0x845: mov    WORD PTR [rsp+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_84f:
	/* 0x84f: movzx  edx,BYTE PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 12ULL);
x86_l_854:
	/* 0x854: mov    BYTE PTR [rsp+0xc2],dl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 194ULL);
x86_l_85b:
	/* 0x85b: mov    BYTE PTR [rsp+0xc3],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 195ULL);
x86_l_862:
	/* 0x862: mov    DWORD PTR [rsp+0xc4],r11d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_86a:
	/* 0x86a: mov    QWORD PTR [rsp+0xd8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_872:
	/* 0x872: shl    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_876:
	/* 0x876: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_87b:
	/* 0x87b: or     rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_87e:
	/* 0x87e: mov    QWORD PTR [rsp+0xc8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 858993459200ULL);
x86_l_88a:
	/* 0x88a: mov    QWORD PTR [rsp+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_896:
	/* 0x896: mov    rsi,QWORD PTR [rip+0x119a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_events)));
x86_l_89d:
	/* 0x89d: lea    rcx,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_8a5:
	/* 0x8a5: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_8aa:
	/* 0x8aa: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_8ad:
	/* 0x8ad: mov    r8d,0x38 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 56ULL);
x86_l_8b3:
	/* 0x8b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8b5:
	/* 0x8b5: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8b7:
	/* 0x8b7: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_8b9:
	/* 0x8b9: add    rsp,0xf8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 248ULL);
x86_l_8c0:
	/* 0x8c0: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_8c2:
	/* 0x8c2: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_8c3:
	/* 0x8c3: jmp    178f <tail_handle_nat_fwd_ipv6+0x178f> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_8c8:
	/* 0x8c8: inc    QWORD PTR [r14] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_8cb:
	/* 0x8cb: jmp    8b5 <tail_handle_nat_fwd_ipv6+0x8b5> */
	X86_SIM_X86_JMP(0x8cb, 0x8b5, x86_l_8b5);
x86_l_8cd:
	/* 0x8cd: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8d2:
	/* 0x8d2: mov    rbx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_8d7:
	/* 0x8d7: movzx  eax,BYTE PTR [rsp+0x21] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 33ULL);
x86_l_8dc:
	/* 0x8dc: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_8e3:
	/* 0x8e3: cmp    r13b,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_8, 44ULL);
x86_l_8e7:
	/* 0x8e7: je     8f3 <tail_handle_nat_fwd_ipv6+0x8f3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8e7, 0x8f3, x86_l_8f3);
x86_l_8e9:
	/* 0x8e9: jmp    974 <tail_handle_nat_fwd_ipv6+0x974> */
	X86_SIM_X86_JMP(0x8e9, 0x974, x86_l_974);
x86_l_8ee:
	/* 0x8ee: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_8f3:
	/* 0x8f3: mov    r13d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_8f6:
	/* 0x8f6: mov    r12d,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDX, X86_WIDTH_32);
x86_l_8f9:
	/* 0x8f9: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_902:
	/* 0x902: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_907:
	/* 0x907: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_90c:
	/* 0x90c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_90f:
	/* 0x90f: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_912:
	/* 0x912: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_917:
	/* 0x917: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_919:
	/* 0x919: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_91b:
	/* 0x91b: js     a15 <tail_handle_nat_fwd_ipv6+0xa15> */
	X86_SIM_X86_JCC(X86_CC_S, 0x91b, 0xa15, x86_l_a15);
x86_l_921:
	/* 0x921: mov    eax,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_925:
	/* 0x925: movzx  ecx,BYTE PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 32ULL);
x86_l_92a:
	/* 0x92a: shl    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_92e:
	/* 0x92e: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_931:
	/* 0x931: movzx  eax,WORD PTR [rsp+0x22] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 34ULL);
x86_l_936:
	/* 0x936: movabs rdx,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1099511627776ULL);
x86_l_940:
	/* 0x940: or     rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_943:
	/* 0x943: test   eax,0xf9ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63999ULL);
x86_l_948:
	/* 0x948: cmove  rdx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_64, X86_CC_E);
x86_l_94c:
	/* 0x94c: movabs r8,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_64, 2199023255552ULL);
x86_l_956:
	/* 0x956: or     r8,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDX, X86_WIDTH_64, X86_ALU_OR);
x86_l_959:
	/* 0x959: test   eax,0xf8ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63743ULL);
x86_l_95e:
	/* 0x95e: cmove  r8,rdx */
	X86_SIM_L_EXEC_CMOV(X86_R8, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_962:
	/* 0x962: mov    rdi,QWORD PTR [rip+0x119aa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_969:
	/* 0x969: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_96e:
	/* 0x96e: mov    edx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_32);
x86_l_971:
	/* 0x971: mov    eax,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_974:
	/* 0x974: movzx  r12d,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_978:
	/* 0x978: add    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_97a:
	/* 0x97a: cmp    r12d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 60ULL);
x86_l_97e:
	/* 0x97e: ja     a27 <tail_handle_nat_fwd_ipv6+0xa27> */
	X86_SIM_X86_JCC(X86_CC_A, 0x97e, 0xa27, x86_l_a27);
x86_l_984:
	/* 0x984: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_987:
	/* 0x987: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_991:
	/* 0x991: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_995:
	/* 0x995: mov    r14d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_99a:
	/* 0x99a: jae    c3c <tail_handle_nat_fwd_ipv6+0xc3c> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x99a, 0xc3c, x86_l_c3c);
x86_l_9a0:
	/* 0x9a0: mov    ebp,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_32);
x86_l_9a2:
	/* 0x9a2: add    esi,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RSI, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_9a6:
	/* 0x9a6: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9ab:
	/* 0x9ab: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_9b0:
	/* 0x9b0: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_9b3:
	/* 0x9b3: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_9b8:
	/* 0x9b8: mov    r15,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSI, X86_WIDTH_64);
x86_l_9bb:
	/* 0x9bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9bd:
	/* 0x9bd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_9bf:
	/* 0x9bf: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_9c4:
	/* 0x9c4: js     476 <tail_handle_nat_fwd_ipv6+0x476> */
	X86_SIM_X86_JCC(X86_CC_S, 0x9c4, 0x476, x86_l_476);
x86_l_9ca:
	/* 0x9ca: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_9cd:
	/* 0x9cd: cmp    r12d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 43ULL);
x86_l_9d1:
	/* 0x9d1: jle    9e3 <tail_handle_nat_fwd_ipv6+0x9e3> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x9d1, 0x9e3, x86_l_9e3);
x86_l_9d3:
	/* 0x9d3: cmp    r12d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 44ULL);
x86_l_9d7:
	/* 0x9d7: je     9ed <tail_handle_nat_fwd_ipv6+0x9ed> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9d7, 0x9ed, x86_l_9ed);
x86_l_9d9:
	/* 0x9d9: cmp    r12d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 51ULL);
x86_l_9dd:
	/* 0x9dd: je     c2f <tail_handle_nat_fwd_ipv6+0xc2f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9dd, 0xc2f, x86_l_c2f);
x86_l_9e3:
	/* 0x9e3: cmp    bpl,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 44ULL);
x86_l_9e7:
	/* 0x9e7: jne    c2f <tail_handle_nat_fwd_ipv6+0xc2f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x9e7, 0xc2f, x86_l_c2f);
x86_l_9ed:
	/* 0x9ed: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_9f6:
	/* 0x9f6: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9fb:
	/* 0x9fb: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_a00:
	/* 0xa00: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_a03:
	/* 0xa03: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a08:
	/* 0xa08: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a0a:
	/* 0xa0a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a0c:
	/* 0xa0c: js     a15 <tail_handle_nat_fwd_ipv6+0xa15> */
	X86_SIM_X86_JCC(X86_CC_S, 0xa0c, 0xa15, x86_l_a15);
x86_l_a0e:
	/* 0xa0e: mov    ebp,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967140ULL);
x86_l_a13:
	/* 0xa13: jmp    a1a <tail_handle_nat_fwd_ipv6+0xa1a> */
	X86_SIM_X86_JMP(0xa13, 0xa1a, x86_l_a1a);
x86_l_a15:
	/* 0xa15: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_a1a:
	/* 0xa1a: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a1d:
	/* 0xa1d: mov    r14d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_a22:
	/* 0xa22: jmp    47b <tail_handle_nat_fwd_ipv6+0x47b> */
	X86_SIM_X86_JMP(0xa22, 0x47b, x86_l_47b);
x86_l_a27:
	/* 0xa27: mov    r13d,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_32);
x86_l_a2a:
	/* 0xa2a: mov    r14d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_a2f:
	/* 0xa2f: mov    BYTE PTR [rsp+0x84],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_a37:
	/* 0xa37: movzx  eax,BYTE PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_a3a:
	/* 0xa3a: mov    rcx,QWORD PTR [r15+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a3e:
	/* 0xa3e: mov    QWORD PTR [rsp+0x68],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_a43:
	/* 0xa43: mov    rcx,QWORD PTR [r15+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_a47:
	/* 0xa47: mov    QWORD PTR [rsp+0x60],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_a4c:
	/* 0xa4c: mov    rcx,QWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a50:
	/* 0xa50: mov    QWORD PTR [rsp+0x78],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_a55:
	/* 0xa55: mov    rcx,QWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a59:
	/* 0xa59: mov    QWORD PTR [rsp+0x70],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_a5e:
	/* 0xa5e: cmp    r13b,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_8, 17ULL);
x86_l_a62:
	/* 0xa62: je     a71 <tail_handle_nat_fwd_ipv6+0xa71> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa62, 0xa71, x86_l_a71);
x86_l_a64:
	/* 0xa64: movzx  ecx,r13b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R13, X86_WIDTH_32, X86_WIDTH_8);
x86_l_a68:
	/* 0xa68: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_a6b:
	/* 0xa6b: jne    1693 <tail_handle_nat_fwd_ipv6+0x1693> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa6b, 0x1693, x86_l_1693);
x86_l_a71:
	/* 0xa71: add    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_a73:
	/* 0xa73: movabs rcx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2199023255552ULL);
x86_l_a7d:
	/* 0xa7d: lea    r13,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_a85:
	/* 0xa85: mov    rax,QWORD PTR [rip+0x119aa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_a8c:
	/* 0xa8c: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a8f:
	/* 0xa8f: mov    QWORD PTR [rsp+0x18],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_a94:
	/* 0xa94: mov    QWORD PTR [rsp+0x10],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a99:
	/* 0xa99: je     aed <tail_handle_nat_fwd_ipv6+0xaed> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa99, 0xaed, x86_l_aed);
x86_l_a9b:
	/* 0xa9b: mov    r12,QWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a9e:
	/* 0xa9e: mov    QWORD PTR [r15],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_aa5:
	/* 0xaa5: mov    DWORD PTR [r15],r8d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_aa8:
	/* 0xaa8: mov    rax,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R8, X86_WIDTH_64);
x86_l_aab:
	/* 0xaab: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_aaf:
	/* 0xaaf: mov    BYTE PTR [r15+0x4],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_ab3:
	/* 0xab3: test   r8,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R8, X86_RCX, X86_WIDTH_64);
x86_l_ab6:
	/* 0xab6: jne    14bb <tail_handle_nat_fwd_ipv6+0x14bb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xab6, 0x14bb, x86_l_14bb);
x86_l_abc:
	/* 0xabc: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_ac1:
	/* 0xac1: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_ac4:
	/* 0xac4: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_ac7:
	/* 0xac7: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_acc:
	/* 0xacc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ace:
	/* 0xace: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ad0:
	/* 0xad0: js     bb1 <tail_handle_nat_fwd_ipv6+0xbb1> */
	X86_SIM_X86_JCC(X86_CC_S, 0xad0, 0xbb1, x86_l_bb1);
x86_l_ad6:
	/* 0xad6: mov    DWORD PTR [rsp+0x4],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_adb:
	/* 0xadb: bt     QWORD PTR [rsp+0x18],0x28 */
	X86_SIM_L_EXEC_BT_MEM_IMM(X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 103079215144ULL);
x86_l_ae2:
	/* 0xae2: jb     1501 <tail_handle_nat_fwd_ipv6+0x1501> */
	X86_SIM_X86_JCC(X86_CC_B, 0xae2, 0x1501, x86_l_1501);
x86_l_ae8:
	/* 0xae8: mov    QWORD PTR [r15],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_aeb:
	/* 0xaeb: jmp    b18 <tail_handle_nat_fwd_ipv6+0xb18> */
	X86_SIM_X86_JMP(0xaeb, 0xb18, x86_l_b18);
x86_l_aed:
	/* 0xaed: mov    DWORD PTR [rsp+0x4],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_af2:
	/* 0xaf2: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_af5:
	/* 0xaf5: test   r8,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R8, X86_RCX, X86_WIDTH_64);
x86_l_af8:
	/* 0xaf8: jne    156d <tail_handle_nat_fwd_ipv6+0x156d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xaf8, 0x156d, x86_l_156d);
x86_l_afe:
	/* 0xafe: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_b03:
	/* 0xb03: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_b06:
	/* 0xb06: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_b09:
	/* 0xb09: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_b0e:
	/* 0xb0e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b10:
	/* 0xb10: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b12:
	/* 0xb12: js     c25 <tail_handle_nat_fwd_ipv6+0xc25> */
	X86_SIM_X86_JCC(X86_CC_S, 0xb12, 0xc25, x86_l_c25);
x86_l_b18:
	/* 0xb18: movzx  r14d,BYTE PTR [rsp+0x85] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 133ULL);
x86_l_b21:
	/* 0xb21: cmp    BYTE PTR [rsp+0x84],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 566935683078ULL);
x86_l_b29:
	/* 0xb29: jne    b34 <tail_handle_nat_fwd_ipv6+0xb34> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb29, 0xb34, x86_l_b34);
x86_l_b2b:
	/* 0xb2b: mov    rdi,QWORD PTR [rip+0x119aa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct6_global)));
x86_l_b32:
	/* 0xb32: jmp    b3b <tail_handle_nat_fwd_ipv6+0xb3b> */
	X86_SIM_X86_JMP(0xb32, 0xb3b, x86_l_b3b);
x86_l_b34:
	/* 0xb34: mov    rdi,QWORD PTR [rip+0x119aa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct_any6_global)));
x86_l_b3b:
	/* 0xb3b: mov    BYTE PTR [rsp+0x85],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 571230650368ULL);
x86_l_b43:
	/* 0xb43: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_b48:
	/* 0xb48: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b4d:
	/* 0xb4d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b4f:
	/* 0xb4f: mov    BYTE PTR [rsp+0x85],r14b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 133ULL);
x86_l_b57:
	/* 0xb57: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b5a:
	/* 0xb5a: mov    r14d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_b5f:
	/* 0xb5f: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b64:
	/* 0xb64: je     1693 <tail_handle_nat_fwd_ipv6+0x1693> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb64, 0x1693, x86_l_1693);
x86_l_b6a:
	/* 0xb6a: movzx  ecx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_b6e:
	/* 0xb6e: test   cl,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_b71:
	/* 0xb71: jne    bbb <tail_handle_nat_fwd_ipv6+0xbbb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb71, 0xbbb, x86_l_bbb);
x86_l_b73:
	/* 0xb73: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_b75:
	/* 0xb75: jns    1693 <tail_handle_nat_fwd_ipv6+0x1693> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xb75, 0x1693, x86_l_1693);
x86_l_b7b:
	/* 0xb7b: movzx  esi,WORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 40ULL);
x86_l_b7f:
	/* 0xb7f: test   si,si */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_16);
x86_l_b82:
	/* 0xb82: je     c53 <tail_handle_nat_fwd_ipv6+0xc53> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb82, 0xc53, x86_l_c53);
x86_l_b88:
	/* 0xb88: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b8c:
	/* 0xb8c: mov    QWORD PTR [rsp+0x98],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_b94:
	/* 0xb94: mov    rdx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b97:
	/* 0xb97: mov    QWORD PTR [rsp+0x90],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_b9f:
	/* 0xb9f: mov    WORD PTR [rsp+0xa0],si */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_ba7:
	/* 0xba7: mov    r13d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bac:
	/* 0xbac: jmp    ce3 <tail_handle_nat_fwd_ipv6+0xce3> */
	X86_SIM_X86_JMP(0xbac, 0xce3, x86_l_ce3);
x86_l_bb1:
	/* 0xbb1: mov    ebp,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967161ULL);
x86_l_bb6:
	/* 0xbb6: mov    QWORD PTR [r15],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bb9:
	/* 0xbb9: jmp    c34 <tail_handle_nat_fwd_ipv6+0xc34> */
	X86_SIM_X86_JMP(0xbb9, 0xc34, x86_l_c34);
x86_l_bbb:
	/* 0xbbb: movzx  eax,WORD PTR [rax+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_bbf:
	/* 0xbbf: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_bc2:
	/* 0xbc2: je     1693 <tail_handle_nat_fwd_ipv6+0x1693> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbc2, 0x1693, x86_l_1693);
x86_l_bc8:
	/* 0xbc8: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_bcd:
	/* 0xbcd: mov    rax,QWORD PTR [rip+0x119aa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_bd4:
	/* 0xbd4: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_bd7:
	/* 0xbd7: mov    rdi,QWORD PTR [rip+0x119aa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb6_reverse_nat)));
x86_l_bde:
	/* 0xbde: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_be3:
	/* 0xbe3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_be8:
	/* 0xbe8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bea:
	/* 0xbea: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_bef:
	/* 0xbef: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_bf2:
	/* 0xbf2: je     1693 <tail_handle_nat_fwd_ipv6+0x1693> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbf2, 0x1693, x86_l_1693);
x86_l_bf8:
	/* 0xbf8: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bfc:
	/* 0xbfc: mov    QWORD PTR [rsp+0x98],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_c04:
	/* 0xc04: mov    rdx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c07:
	/* 0xc07: mov    QWORD PTR [rsp+0x90],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_c0f:
	/* 0xc0f: movzx  eax,WORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_c13:
	/* 0xc13: mov    WORD PTR [rsp+0xa0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_c1b:
	/* 0xc1b: mov    r13d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c20:
	/* 0xc20: jmp    ce3 <tail_handle_nat_fwd_ipv6+0xce3> */
	X86_SIM_X86_JMP(0xc20, 0xce3, x86_l_ce3);
x86_l_c25:
	/* 0xc25: mov    ebp,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967161ULL);
x86_l_c2a:
	/* 0xc2a: jmp    a1d <tail_handle_nat_fwd_ipv6+0xa1d> */
	X86_SIM_X86_JMP(0xc2a, 0xa1d, x86_l_a1d);
x86_l_c2f:
	/* 0xc2f: mov    ebp,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967140ULL);
x86_l_c34:
	/* 0xc34: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c37:
	/* 0xc37: jmp    47b <tail_handle_nat_fwd_ipv6+0x47b> */
	X86_SIM_X86_JMP(0xc37, 0x47b, x86_l_47b);
x86_l_c3c:
	/* 0xc3c: mov    r13d,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_32);
x86_l_c3f:
	/* 0xc3f: cmp    rax,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 59ULL);
x86_l_c43:
	/* 0xc43: mov    eax,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967140ULL);
x86_l_c48:
	/* 0xc48: je     476 <tail_handle_nat_fwd_ipv6+0x476> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc48, 0x476, x86_l_476);
x86_l_c4e:
	/* 0xc4e: jmp    a2f <tail_handle_nat_fwd_ipv6+0xa2f> */
	X86_SIM_X86_JMP(0xc4e, 0xa2f, x86_l_a2f);
x86_l_c53:
	/* 0xc53: mov    rax,QWORD PTR [rsp+0x7d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 125ULL);
x86_l_c58:
	/* 0xc58: mov    QWORD PTR [rsp+0x3d],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 61ULL);
x86_l_c5d:
	/* 0xc5d: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_c62:
	/* 0xc62: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_c67:
	/* 0xc67: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_c6c:
	/* 0xc6c: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c71:
	/* 0xc71: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_c76:
	/* 0xc76: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_c7b:
	/* 0xc7b: mov    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c80:
	/* 0xc80: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c85:
	/* 0xc85: mov    BYTE PTR [rsp+0x45],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 296352743424ULL);
x86_l_c8a:
	/* 0xc8a: rorx   eax,DWORD PTR [rsp+0x80],0x10 */
	X86_SIM_RUN_OP(X86_OP_RORX_MEM, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 549755813904ULL);
x86_l_c95:
	/* 0xc95: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_c99:
	/* 0xc99: mov    rdi,QWORD PTR [rip+0x119aa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_ca0:
	/* 0xca0: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ca5:
	/* 0xca5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_caa:
	/* 0xcaa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cac:
	/* 0xcac: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_caf:
	/* 0xcaf: mov    r13d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cb4:
	/* 0xcb4: je     1693 <tail_handle_nat_fwd_ipv6+0x1693> */
	X86_SIM_X86_JCC(X86_CC_E, 0xcb4, 0x1693, x86_l_1693);
x86_l_cba:
	/* 0xcba: mov    rcx,QWORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_cbe:
	/* 0xcbe: mov    QWORD PTR [rsp+0x98],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_cc6:
	/* 0xcc6: mov    rdx,QWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_cca:
	/* 0xcca: mov    QWORD PTR [rsp+0x90],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_cd2:
	/* 0xcd2: movzx  eax,WORD PTR [rax+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_cd6:
	/* 0xcd6: mov    WORD PTR [rsp+0xa0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_cde:
	/* 0xcde: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ce3:
	/* 0xce3: test   BYTE PTR [rsp+0x4c],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 326417514497ULL);
x86_l_ce8:
	/* 0xce8: jne    e13 <tail_handle_nat_fwd_ipv6+0xe13> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xce8, 0xe13, x86_l_e13);
x86_l_cee:
	/* 0xcee: mov    BYTE PTR [rsp+0xa8],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 721554505738ULL);
x86_l_cf6:
	/* 0xcf6: mov    eax,DWORD PTR [rbx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_cf9:
	/* 0xcf9: mov    DWORD PTR [rsp+0xb0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_d00:
	/* 0xd00: mov    QWORD PTR [rsp+0xc0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_d08:
	/* 0xd08: mov    QWORD PTR [rsp+0xb8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_d10:
	/* 0xd10: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_d15:
	/* 0xd15: mov    QWORD PTR [rsp+0xd0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_d1d:
	/* 0xd1d: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_d22:
	/* 0xd22: mov    QWORD PTR [rsp+0xc8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_d2a:
	/* 0xd2a: mov    rax,QWORD PTR [rip+0x119aa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_supports_fib_lookup_skip_neigh)));
x86_l_d31:
	/* 0xd31: movzx  ecx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_d34:
	/* 0xd34: shl    ecx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 2ULL);
x86_l_d37:
	/* 0xd37: lea    rsi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_d3f:
	/* 0xd3f: mov    eax,0x45 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 69ULL);
x86_l_d44:
	/* 0xd44: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_d47:
	/* 0xd47: mov    edx,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 64ULL);
x86_l_d4c:
	/* 0xd4c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d4e:
	/* 0xd4e: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_d51:
	/* 0xd51: je     d5e <tail_handle_nat_fwd_ipv6+0xd5e> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd51, 0xd5e, x86_l_d5e);
x86_l_d53:
	/* 0xd53: mov    r12d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_32);
x86_l_d56:
	/* 0xd56: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_d58:
	/* 0xd58: jne    deb <tail_handle_nat_fwd_ipv6+0xdeb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xd58, 0xdeb, x86_l_deb);
x86_l_d5e:
	/* 0xd5e: mov    r15d,DWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_d66:
	/* 0xd66: mov    rax,QWORD PTR [rip+0x119aa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_interface_ifindex)));
x86_l_d6d:
	/* 0xd6d: cmp    r15d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_d70:
	/* 0xd70: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d75:
	/* 0xd75: je     e13 <tail_handle_nat_fwd_ipv6+0xe13> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd75, 0xe13, x86_l_e13);
x86_l_d7b:
	/* 0xd7b: mov    DWORD PTR [rsp+0x20],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d80:
	/* 0xd80: mov    rdi,QWORD PTR [rip+0x119aa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_devices)));
x86_l_d87:
	/* 0xd87: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d8c:
	/* 0xd8c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d91:
	/* 0xd91: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d93:
	/* 0xd93: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d96:
	/* 0xd96: je     d9e <tail_handle_nat_fwd_ipv6+0xd9e> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd96, 0xd9e, x86_l_d9e);
x86_l_d98:
	/* 0xd98: test   BYTE PTR [rax+0x8],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_d9c:
	/* 0xd9c: jne    df5 <tail_handle_nat_fwd_ipv6+0xdf5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xd9c, 0xdf5, x86_l_df5);
x86_l_d9e:
	/* 0xd9e: mov    rax,QWORD PTR [rip+0x119aa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_da5:
	/* 0xda5: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_da8:
	/* 0xda8: je     fd0 <tail_handle_nat_fwd_ipv6+0xfd0> */
	X86_SIM_X86_JCC(X86_CC_E, 0xda8, 0xfd0, x86_l_fd0);
x86_l_dae:
	/* 0xdae: lea    rax,[rsp+0xc8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_db6:
	/* 0xdb6: movzx  ecx,BYTE PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 168ULL);
x86_l_dbe:
	/* 0xdbe: mov    DWORD PTR [rsp+0x20],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_dc2:
	/* 0xdc2: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_dc5:
	/* 0xdc5: mov    rax,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_dc9:
	/* 0xdc9: mov    QWORD PTR [rsp+0x24],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_dce:
	/* 0xdce: mov    QWORD PTR [rsp+0x2c],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_dd3:
	/* 0xdd3: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_dd8:
	/* 0xdd8: mov    eax,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 152ULL);
x86_l_ddd:
	/* 0xddd: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_de0:
	/* 0xde0: mov    edx,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 20ULL);
x86_l_de5:
	/* 0xde5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_de7:
	/* 0xde7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_de9:
	/* 0xde9: jmp    e01 <tail_handle_nat_fwd_ipv6+0xe01> */
	X86_SIM_X86_JMP(0xde9, 0xe01, x86_l_e01);
x86_l_deb:
	/* 0xdeb: mov    ebp,0xffffff57 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967127ULL);
x86_l_df0:
	/* 0xdf0: jmp    480 <tail_handle_nat_fwd_ipv6+0x480> */
	X86_SIM_X86_JMP(0xdf0, 0x480, x86_l_480);
x86_l_df5:
	/* 0xdf5: mov    eax,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 23ULL);
x86_l_dfa:
	/* 0xdfa: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_dfd:
	/* 0xdfd: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_dff:
	/* 0xdff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e01:
	/* 0xe01: mov    ebp,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_e03:
	/* 0xe03: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e06:
	/* 0xe06: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_e08:
	/* 0xe08: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_e0d:
	/* 0xe0d: jne    480 <tail_handle_nat_fwd_ipv6+0x480> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe0d, 0x480, x86_l_480);
x86_l_e13:
	/* 0xe13: movzx  r12d,BYTE PTR [rsp+0x84] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 132ULL);
x86_l_e1c:
	/* 0xe1c: cmp    r12b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_8, 6ULL);
x86_l_e20:
	/* 0xe20: jne    e2b <tail_handle_nat_fwd_ipv6+0xe2b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe20, 0xe2b, x86_l_e2b);
x86_l_e22:
	/* 0xe22: mov    r15,QWORD PTR [rip+0x119aa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&cilium_ct6_global)));
x86_l_e29:
	/* 0xe29: jmp    e32 <tail_handle_nat_fwd_ipv6+0xe32> */
	X86_SIM_X86_JMP(0xe29, 0xe32, x86_l_e32);
x86_l_e2b:
	/* 0xe2b: mov    r15,QWORD PTR [rip+0x119aa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&cilium_ct_any6_global)));
x86_l_e32:
	/* 0xe32: mov    r13,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e37:
	/* 0xe37: mov    rax,QWORD PTR [rip+0x119aa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_e3e:
	/* 0xe3e: mov    BYTE PTR [rsp+0x85],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 571230650368ULL);
x86_l_e46:
	/* 0xe46: mov    DWORD PTR [rsp+0x8c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_e51:
	/* 0xe51: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e54:
	/* 0xe54: je     ee1 <tail_handle_nat_fwd_ipv6+0xee1> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe54, 0xee1, x86_l_ee1);
x86_l_e5a:
	/* 0xe5a: movabs rax,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 1099511627776ULL);
x86_l_e64:
	/* 0xe64: and    rax,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_64, X86_ALU_AND);
x86_l_e67:
	/* 0xe67: je     ee1 <tail_handle_nat_fwd_ipv6+0xee1> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe67, 0xee1, x86_l_ee1);
x86_l_e69:
	/* 0xe69: mov    ebp,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R14, X86_WIDTH_32);
x86_l_e6c:
	/* 0xe6c: mov    r14d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e6f:
	/* 0xe6f: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_e78:
	/* 0xe78: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_e81:
	/* 0xe81: movabs rax,0x6c02a30109 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 463900705033ULL);
x86_l_e8b:
	/* 0xe8b: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_e90:
	/* 0xe90: mov    rdi,QWORD PTR [rip+0x119aa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_e97:
	/* 0xe97: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_e9c:
	/* 0xe9c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ea1:
	/* 0xea1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ea3:
	/* 0xea3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ea6:
	/* 0xea6: je     eb1 <tail_handle_nat_fwd_ipv6+0xeb1> */
	X86_SIM_X86_JCC(X86_CC_E, 0xea6, 0xeb1, x86_l_eb1);
x86_l_ea8:
	/* 0xea8: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_eab:
	/* 0xeab: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_eaf:
	/* 0xeaf: jmp    ed9 <tail_handle_nat_fwd_ipv6+0xed9> */
	X86_SIM_X86_JMP(0xeaf, 0xed9, x86_l_ed9);
x86_l_eb1:
	/* 0xeb1: mov    QWORD PTR [rsp+0x20],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953473ULL);
x86_l_eba:
	/* 0xeba: mov    QWORD PTR [rsp+0x28],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_ebf:
	/* 0xebf: mov    rdi,QWORD PTR [rip+0x119aa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_ec6:
	/* 0xec6: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_ecb:
	/* 0xecb: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ed0:
	/* 0xed0: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_ed5:
	/* 0xed5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ed7:
	/* 0xed7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ed9:
	/* 0xed9: mov    r14d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RBP, X86_WIDTH_32);
x86_l_edc:
	/* 0xedc: mov    rdi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ee1:
	/* 0xee1: cmp    r12b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_8, 6ULL);
x86_l_ee5:
	/* 0xee5: jne    f46 <tail_handle_nat_fwd_ipv6+0xf46> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xee5, 0xf46, x86_l_f46);
x86_l_ee7:
	/* 0xee7: mov    rax,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDI, X86_WIDTH_64);
x86_l_eea:
	/* 0xeea: movabs rcx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2199023255552ULL);
x86_l_ef4:
	/* 0xef4: and    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_ef7:
	/* 0xef7: jne    f46 <tail_handle_nat_fwd_ipv6+0xf46> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xef7, 0xf46, x86_l_f46);
x86_l_ef9:
	/* 0xef9: lea    esi,[r13+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_efd:
	/* 0xefd: lea    rdx,[rsp+0x8c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_f05:
	/* 0xf05: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_f0a:
	/* 0xf0a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_f0d:
	/* 0xf0d: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_f12:
	/* 0xf12: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f14:
	/* 0xf14: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_f16:
	/* 0xf16: js     1693 <tail_handle_nat_fwd_ipv6+0x1693> */
	X86_SIM_X86_JCC(X86_CC_S, 0xf16, 0x1693, x86_l_1693);
x86_l_f1c:
	/* 0xf1c: mov    ebp,DWORD PTR [rsp+0x8c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_f23:
	/* 0xf23: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_f25:
	/* 0xf25: and    eax,0x1200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4608ULL);
x86_l_f2a:
	/* 0xf2a: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f2d:
	/* 0xf2d: cmp    eax,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 512ULL);
x86_l_f32:
	/* 0xf32: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_f35:
	/* 0xf35: test   ebp,0x500 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RBP, X86_WIDTH_32, 1280ULL);
x86_l_f3b:
	/* 0xf3b: jne    15b9 <tail_handle_nat_fwd_ipv6+0x15b9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf3b, 0x15b9, x86_l_15b9);
x86_l_f41:
	/* 0xf41: mov    r13b,al */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_8);
x86_l_f44:
	/* 0xf44: jmp    f50 <tail_handle_nat_fwd_ipv6+0xf50> */
	X86_SIM_X86_JMP(0xf44, 0xf50, x86_l_f50);
x86_l_f46:
	/* 0xf46: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f49:
	/* 0xf49: mov    ebp,DWORD PTR [rsp+0x8c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_f50:
	/* 0xf50: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_f55:
	/* 0xf55: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f5a:
	/* 0xf5a: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_f5d:
	/* 0xf5d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f5f:
	/* 0xf5f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f62:
	/* 0xf62: mov    r8,QWORD PTR [rip+0x119aa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R8, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_f69:
	/* 0xf69: mov    rsi,QWORD PTR [rip+0x119aa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_f70:
	/* 0xf70: je     1690 <tail_handle_nat_fwd_ipv6+0x1690> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf70, 0x1690, x86_l_1690);
x86_l_f76:
	/* 0xf76: movzx  ecx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_f7a:
	/* 0xf7a: test   cl,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_f7d:
	/* 0xf7d: jne    f88 <tail_handle_nat_fwd_ipv6+0xf88> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf7d, 0xf88, x86_l_f88);
x86_l_f7f:
	/* 0xf7f: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_f81:
	/* 0xf81: js     f9a <tail_handle_nat_fwd_ipv6+0xf9a> */
	X86_SIM_X86_JCC(X86_CC_S, 0xf81, 0xf9a, x86_l_f9a);
x86_l_f83:
	/* 0xf83: jmp    1690 <tail_handle_nat_fwd_ipv6+0x1690> */
	X86_SIM_X86_JMP(0xf83, 0x1690, x86_l_1690);
x86_l_f88:
	/* 0xf88: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_f8a:
	/* 0xf8a: and    edx,0x80 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 128ULL);
x86_l_f90:
	/* 0xf90: or     dx,WORD PTR [rax+0x26] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RAX, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 38ULL);
x86_l_f94:
	/* 0xf94: je     1690 <tail_handle_nat_fwd_ipv6+0x1690> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf94, 0x1690, x86_l_1690);
x86_l_f9a:
	/* 0xf9a: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_f9c:
	/* 0xf9c: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_f9e:
	/* 0xf9e: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_fa6:
	/* 0xfa6: test   dl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_8, 3ULL);
x86_l_fa9:
	/* 0xfa9: mov    DWORD PTR [rsp+0xc],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_fad:
	/* 0xfad: je     10e8 <tail_handle_nat_fwd_ipv6+0x10e8> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfad, 0x10e8, x86_l_10e8);
x86_l_fb3:
	/* 0xfb3: mov    rsi,QWORD PTR [rip+0x119aa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_fba:
	/* 0xfba: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fbd:
	/* 0xfbd: je     ffb <tail_handle_nat_fwd_ipv6+0xffb> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfbd, 0xffb, x86_l_ffb);
x86_l_fbf:
	/* 0xfbf: mov    rdx,QWORD PTR [rip+0x119aa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_fc6:
	/* 0xfc6: imul   r15d,DWORD PTR [rdx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R15, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_fca:
	/* 0xfca: shr    r15d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_fce:
	/* 0xfce: jmp    1001 <tail_handle_nat_fwd_ipv6+0x1001> */
	X86_SIM_X86_JMP(0xfce, 0x1001, x86_l_1001);
x86_l_fd0:
	/* 0xfd0: mov    r13d,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R14, X86_WIDTH_32);
x86_l_fd3:
	/* 0xfd3: mov    r14d,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_fd7:
	/* 0xfd7: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_fda:
	/* 0xfda: mov    eax,0x2b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_fdf:
	/* 0xfdf: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_fe2:
	/* 0xfe2: mov    esi,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 14ULL);
x86_l_fe7:
	/* 0xfe7: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_fe9:
	/* 0xfe9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_feb:
	/* 0xfeb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_fed:
	/* 0xfed: je     11a8 <tail_handle_nat_fwd_ipv6+0x11a8> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfed, 0x11a8, x86_l_11a8);
x86_l_ff3:
	/* 0xff3: mov    r14d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R13, X86_WIDTH_32);
x86_l_ff6:
	/* 0xff6: jmp    47b <tail_handle_nat_fwd_ipv6+0x47b> */
	X86_SIM_X86_JMP(0xff6, 0x47b, x86_l_47b);
x86_l_ffb:
	/* 0xffb: mov    r15d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 60ULL);
x86_l_1001:
	/* 0x1001: cmp    r12b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_8, 6ULL);
x86_l_1005:
	/* 0x1005: jne    103d <tail_handle_nat_fwd_ipv6+0x103d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1005, 0x103d, x86_l_103d);
x86_l_1007:
	/* 0x1007: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_1009:
	/* 0x1009: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_100b:
	/* 0x100b: shr    edx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_100e:
	/* 0x100e: and    edx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_1011:
	/* 0x1011: or     edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1013:
	/* 0x1013: mov    WORD PTR [rax+0x24],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1017:
	/* 0x1017: test   dl,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_8, 16ULL);
x86_l_101a:
	/* 0x101a: mov    ecx,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 60ULL);
x86_l_101f:
	/* 0x101f: mov    r15d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 21600ULL);
x86_l_1025:
	/* 0x1025: cmove  r15d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R15, X86_RCX, X86_WIDTH_32, X86_CC_E);
x86_l_1029:
	/* 0x1029: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_102c:
	/* 0x102c: je     103d <tail_handle_nat_fwd_ipv6+0x103d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x102c, 0x103d, x86_l_103d);
x86_l_102e:
	/* 0x102e: mov    rcx,QWORD PTR [rip+0x119aa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1035:
	/* 0x1035: imul   r15d,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_1039:
	/* 0x1039: shr    r15d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_103d:
	/* 0x103d: mov    QWORD PTR [rsp+0xf0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_1045:
	/* 0x1045: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1048:
	/* 0x1048: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_104b:
	/* 0x104b: je     105f <tail_handle_nat_fwd_ipv6+0x105f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x104b, 0x105f, x86_l_105f);
x86_l_104d:
	/* 0x104d: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_1052:
	/* 0x1052: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1054:
	/* 0x1054: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1056:
	/* 0x1056: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1059:
	/* 0x1059: shr    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_105d:
	/* 0x105d: jmp    1082 <tail_handle_nat_fwd_ipv6+0x1082> */
	X86_SIM_X86_JMP(0x105d, 0x1082, x86_l_1082);
x86_l_105f:
	/* 0x105f: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1064:
	/* 0x1064: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1066:
	/* 0x1066: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1068:
	/* 0x1068: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_106c:
	/* 0x106c: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_1076:
	/* 0x1076: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1079:
	/* 0x1079: mulx   rcx,rcx,rcx */
	X86_SIM_L_EXEC_MULX(X86_RCX, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_107e:
	/* 0x107e: shr    rcx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_1082:
	/* 0x1082: add    r15d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1085:
	/* 0x1085: mov    rax,QWORD PTR [rsp+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_108d:
	/* 0x108d: mov    DWORD PTR [rax+0x20],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1091:
	/* 0x1091: movzx  edx,BYTE PTR [rax+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_1095:
	/* 0x1095: mov    esi,DWORD PTR [rax+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1098:
	/* 0x1098: and    bpl,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_109c:
	/* 0x109c: mov    rdi,QWORD PTR [rip+0x119aa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_10a3:
	/* 0x10a3: cmp    BYTE PTR [rdi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10a6:
	/* 0x10a6: je     10b9 <tail_handle_nat_fwd_ipv6+0x10b9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10a6, 0x10b9, x86_l_10b9);
x86_l_10a8:
	/* 0x10a8: mov    rdi,QWORD PTR [rip+0x119aa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_10af:
	/* 0x10af: mov    edi,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10b1:
	/* 0x10b1: lea    edi,[rdi+rdi*4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_10b4:
	/* 0x10b4: shr    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_10b7:
	/* 0x10b7: jmp    10be <tail_handle_nat_fwd_ipv6+0x10be> */
	X86_SIM_X86_JMP(0x10b7, 0x10be, x86_l_10be);
x86_l_10b9:
	/* 0x10b9: mov    edi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 5ULL);
x86_l_10be:
	/* 0x10be: mov    r8,QWORD PTR [rip+0x119aa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R8, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_10c5:
	/* 0x10c5: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_10c7:
	/* 0x10c7: or     bpl,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_10ca:
	/* 0x10ca: cmp    edi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RCX, X86_WIDTH_32);
x86_l_10cc:
	/* 0x10cc: mov    rsi,QWORD PTR [rip+0x119aa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_10d3:
	/* 0x10d3: jb     10da <tail_handle_nat_fwd_ipv6+0x10da> */
	X86_SIM_X86_JCC(X86_CC_B, 0x10d3, 0x10da, x86_l_10da);
x86_l_10d5:
	/* 0x10d5: cmp    dl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBP, X86_WIDTH_8);
x86_l_10d8:
	/* 0x10d8: je     10e8 <tail_handle_nat_fwd_ipv6+0x10e8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10d8, 0x10e8, x86_l_10e8);
x86_l_10da:
	/* 0x10da: mov    BYTE PTR [rax+0x2b],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_10de:
	/* 0x10de: mov    DWORD PTR [rax+0x34],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_10e1:
	/* 0x10e1: mov    ecx,DWORD PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10e4:
	/* 0x10e4: mov    DWORD PTR [rsp+0x4],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_10e8:
	/* 0x10e8: mov    rcx,QWORD PTR [rip+0x119aa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_10ef:
	/* 0x10ef: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10f2:
	/* 0x10f2: je     1100 <tail_handle_nat_fwd_ipv6+0x1100> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10f2, 0x1100, x86_l_1100);
x86_l_10f4:
	/* 0x10f4: inc QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 16ULL);
x86_l_10f9:
	/* 0x10f9: mov    ecx,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10fb:
	/* 0x10fb: add QWORD PTR [rax+0x18],rcx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_1100:
	/* 0x1100: cmp    r13d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 2ULL);
x86_l_1104:
	/* 0x1104: mov    r15d,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1109:
	/* 0x1109: je     115c <tail_handle_nat_fwd_ipv6+0x115c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1109, 0x115c, x86_l_115c);
x86_l_110b:
	/* 0x110b: cmp    r13d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 1ULL);
x86_l_110f:
	/* 0x110f: jne    1286 <tail_handle_nat_fwd_ipv6+0x1286> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x110f, 0x1286, x86_l_1286);
x86_l_1115:
	/* 0x1115: movzx  ecx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_1119:
	/* 0x1119: test   cl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_111c:
	/* 0x111c: je     1286 <tail_handle_nat_fwd_ipv6+0x1286> */
	X86_SIM_X86_JCC(X86_CC_E, 0x111c, 0x1286, x86_l_1286);
x86_l_1122:
	/* 0x1122: mov    QWORD PTR [rsp+0x50],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1127:
	/* 0x1127: mov    WORD PTR [rax+0x2a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 180388626432ULL);
x86_l_112d:
	/* 0x112d: and    ecx,0xffec */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 65516ULL);
x86_l_1133:
	/* 0x1133: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_1136:
	/* 0x1136: mov    WORD PTR [rax+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_113a:
	/* 0x113a: mov    rbx,QWORD PTR [rip+0x119aa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1141:
	/* 0x1141: cmp    BYTE PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1144:
	/* 0x1144: je     15c4 <tail_handle_nat_fwd_ipv6+0x15c4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1144, 0x15c4, x86_l_15c4);
x86_l_114a:
	/* 0x114a: mov    rax,QWORD PTR [rip+0x119aa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1151:
	/* 0x1151: imul   ebp,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_1154:
	/* 0x1154: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1157:
	/* 0x1157: jmp    15c9 <tail_handle_nat_fwd_ipv6+0x15c9> */
	X86_SIM_X86_JMP(0x1157, 0x15c9, x86_l_15c9);
x86_l_115c:
	/* 0x115c: mov    ecx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_32);
x86_l_115f:
	/* 0x115f: shr    ecx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_1162:
	/* 0x1162: and    ecx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2ULL);
x86_l_1165:
	/* 0x1165: or     cx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RAX, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 36ULL);
x86_l_1169:
	/* 0x1169: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_116b:
	/* 0x116b: or     edx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_OR, 1ULL);
x86_l_116e:
	/* 0x116e: mov    WORD PTR [rax+0x24],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1172:
	/* 0x1172: mov    edx,DWORD PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1175:
	/* 0x1175: test   cl,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_1178:
	/* 0x1178: mov    DWORD PTR [rsp+0x4],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_117c:
	/* 0x117c: je     1286 <tail_handle_nat_fwd_ipv6+0x1286> */
	X86_SIM_X86_JCC(X86_CC_E, 0x117c, 0x1286, x86_l_1286);
x86_l_1182:
	/* 0x1182: mov    r13d,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R15, X86_WIDTH_32);
x86_l_1185:
	/* 0x1185: mov    r15,QWORD PTR [rip+0x119aa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_118c:
	/* 0x118c: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1190:
	/* 0x1190: je     11e7 <tail_handle_nat_fwd_ipv6+0x11e7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1190, 0x11e7, x86_l_11e7);
x86_l_1192:
	/* 0x1192: mov    r12d,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R14, X86_WIDTH_32);
x86_l_1195:
	/* 0x1195: mov    rcx,QWORD PTR [rip+0x119aa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_119c:
	/* 0x119c: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_119e:
	/* 0x119e: add    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_11a0:
	/* 0x11a0: lea    ebp,[rcx+rcx*4] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 0ULL);
x86_l_11a3:
	/* 0x11a3: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_11a6:
	/* 0x11a6: jmp    11ef <tail_handle_nat_fwd_ipv6+0x11ef> */
	X86_SIM_X86_JMP(0x11a6, 0x11ef, x86_l_11ef);
x86_l_11a8:
	/* 0x11a8: mov    WORD PTR [rsp+0x20],r14w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_11ae:
	/* 0x11ae: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_11b3:
	/* 0x11b3: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11b6:
	/* 0x11b6: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_11bb:
	/* 0x11bb: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_11be:
	/* 0x11be: mov    esi,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 12ULL);
x86_l_11c3:
	/* 0x11c3: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_11c8:
	/* 0x11c8: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11cb:
	/* 0x11cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11cd:
	/* 0x11cd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_11cf:
	/* 0x11cf: mov    r14d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R13, X86_WIDTH_32);
x86_l_11d2:
	/* 0x11d2: mov    r13d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11d7:
	/* 0x11d7: jns    dae <tail_handle_nat_fwd_ipv6+0xdae> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x11d7, 0xdae, x86_l_dae);
x86_l_11dd:
	/* 0x11dd: mov    ebp,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967155ULL);
x86_l_11e2:
	/* 0x11e2: jmp    480 <tail_handle_nat_fwd_ipv6+0x480> */
	X86_SIM_X86_JMP(0x11e2, 0x480, x86_l_480);
x86_l_11e7:
	/* 0x11e7: mov    r12d,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R14, X86_WIDTH_32);
x86_l_11ea:
	/* 0x11ea: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_11ef:
	/* 0x11ef: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_11f2:
	/* 0x11f2: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_11f6:
	/* 0x11f6: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11fa:
	/* 0x11fa: je     120b <tail_handle_nat_fwd_ipv6+0x120b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11fa, 0x120b, x86_l_120b);
x86_l_11fc:
	/* 0x11fc: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_1201:
	/* 0x1201: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1203:
	/* 0x1203: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1205:
	/* 0x1205: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_1209:
	/* 0x1209: jmp    122e <tail_handle_nat_fwd_ipv6+0x122e> */
	X86_SIM_X86_JMP(0x1209, 0x122e, x86_l_122e);
x86_l_120b:
	/* 0x120b: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1210:
	/* 0x1210: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1212:
	/* 0x1212: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1214:
	/* 0x1214: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1218:
	/* 0x1218: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_1222:
	/* 0x1222: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1225:
	/* 0x1225: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_122a:
	/* 0x122a: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_122e:
	/* 0x122e: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1230:
	/* 0x1230: mov    DWORD PTR [r14+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1234:
	/* 0x1234: movzx  ecx,BYTE PTR [r14+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_1239:
	/* 0x1239: mov    edx,DWORD PTR [r14+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_123d:
	/* 0x123d: and    r13b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_1241:
	/* 0x1241: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1245:
	/* 0x1245: je     1258 <tail_handle_nat_fwd_ipv6+0x1258> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1245, 0x1258, x86_l_1258);
x86_l_1247:
	/* 0x1247: mov    rsi,QWORD PTR [rip+0x119aa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_124e:
	/* 0x124e: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1250:
	/* 0x1250: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_1253:
	/* 0x1253: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1256:
	/* 0x1256: jmp    125d <tail_handle_nat_fwd_ipv6+0x125d> */
	X86_SIM_X86_JMP(0x1256, 0x125d, x86_l_125d);
x86_l_1258:
	/* 0x1258: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_125d:
	/* 0x125d: mov    rdi,QWORD PTR [rip+0x119aa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_1264:
	/* 0x1264: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1266:
	/* 0x1266: or     r13b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_1269:
	/* 0x1269: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_126b:
	/* 0x126b: jb     1272 <tail_handle_nat_fwd_ipv6+0x1272> */
	X86_SIM_X86_JCC(X86_CC_B, 0x126b, 0x1272, x86_l_1272);
x86_l_126d:
	/* 0x126d: cmp    cl,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R13, X86_WIDTH_8);
x86_l_1270:
	/* 0x1270: je     127c <tail_handle_nat_fwd_ipv6+0x127c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1270, 0x127c, x86_l_127c);
x86_l_1272:
	/* 0x1272: mov    BYTE PTR [r14+0x2b],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_1276:
	/* 0x1276: mov    DWORD PTR [r14+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_127a:
	/* 0x127a: mov    eax,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_127c:
	/* 0x127c: mov    r14d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R12, X86_WIDTH_32);
x86_l_127f:
	/* 0x127f: mov    rsi,QWORD PTR [rip+0x119aa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_1286:
	/* 0x1286: test   BYTE PTR [rsp+0x85],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 571230650370ULL);
x86_l_128e:
	/* 0x128e: jne    1693 <tail_handle_nat_fwd_ipv6+0x1693> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x128e, 0x1693, x86_l_1693);
x86_l_1294:
	/* 0x1294: mov    rax,QWORD PTR [rip+0x119aa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_129b:
	/* 0x129b: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_129e:
	/* 0x129e: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_12a3:
	/* 0x12a3: mov    rcx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_12a8:
	/* 0x12a8: mov    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_12ad:
	/* 0x12ad: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_12b2:
	/* 0x12b2: mov    rax,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_12ba:
	/* 0x12ba: mov    rcx,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_12c2:
	/* 0x12c2: mov    QWORD PTR [rsp+0x78],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_12c7:
	/* 0x12c7: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_12cc:
	/* 0x12cc: movzx  esi,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_12cf:
	/* 0x12cf: add    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 8ULL);
x86_l_12d2:
	/* 0x12d2: lea    rdx,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_12da:
	/* 0x12da: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12dd:
	/* 0x12dd: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_12e2:
	/* 0x12e2: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_12e5:
	/* 0x12e5: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_12ea:
	/* 0x12ea: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12ed:
	/* 0x12ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12ef:
	/* 0x12ef: mov    ebp,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967155ULL);
x86_l_12f4:
	/* 0x12f4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_12f6:
	/* 0x12f6: js     14f2 <tail_handle_nat_fwd_ipv6+0x14f2> */
	X86_SIM_X86_JCC(X86_CC_S, 0x12f6, 0x14f2, x86_l_14f2);
x86_l_12fc:
	/* 0x12fc: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_12ff:
	/* 0x12ff: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1304:
	/* 0x1304: movabs rcx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2199023255552ULL);
x86_l_130e:
	/* 0x130e: je     14f2 <tail_handle_nat_fwd_ipv6+0x14f2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x130e, 0x14f2, x86_l_14f2);
x86_l_1314:
	/* 0x1314: test   rax,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_1317:
	/* 0x1317: jne    1484 <tail_handle_nat_fwd_ipv6+0x1484> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1317, 0x1484, x86_l_1484);
x86_l_131d:
	/* 0x131d: movzx  eax,BYTE PTR [rsp+0x84] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 132ULL);
x86_l_1325:
	/* 0x1325: cmp    eax,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 58ULL);
x86_l_1328:
	/* 0x1328: je     1350 <tail_handle_nat_fwd_ipv6+0x1350> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1328, 0x1350, x86_l_1350);
x86_l_132a:
	/* 0x132a: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_132d:
	/* 0x132d: je     133f <tail_handle_nat_fwd_ipv6+0x133f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x132d, 0x133f, x86_l_133f);
x86_l_132f:
	/* 0x132f: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_1332:
	/* 0x1332: jne    135b <tail_handle_nat_fwd_ipv6+0x135b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1332, 0x135b, x86_l_135b);
x86_l_1334:
	/* 0x1334: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1337:
	/* 0x1337: mov    r15d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 16ULL);
x86_l_133d:
	/* 0x133d: jmp    1361 <tail_handle_nat_fwd_ipv6+0x1361> */
	X86_SIM_X86_JMP(0x133d, 0x1361, x86_l_1361);
x86_l_133f:
	/* 0x133f: mov    r8d,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 32ULL);
x86_l_1345:
	/* 0x1345: mov    r15d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 6ULL);
x86_l_134b:
	/* 0x134b: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_134e:
	/* 0x134e: jmp    1364 <tail_handle_nat_fwd_ipv6+0x1364> */
	X86_SIM_X86_JMP(0x134e, 0x1364, x86_l_1364);
x86_l_1350:
	/* 0x1350: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1353:
	/* 0x1353: mov    r15d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 2ULL);
x86_l_1359:
	/* 0x1359: jmp    1361 <tail_handle_nat_fwd_ipv6+0x1361> */
	X86_SIM_X86_JMP(0x1359, 0x1361, x86_l_1361);
x86_l_135b:
	/* 0x135b: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_135e:
	/* 0x135e: mov    r13b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_8, 1ULL);
x86_l_1361:
	/* 0x1361: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1364:
	/* 0x1364: movzx  ecx,WORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 160ULL);
x86_l_136c:
	/* 0x136c: test   cx,cx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_16);
x86_l_136f:
	/* 0x136f: je     1418 <tail_handle_nat_fwd_ipv6+0x1418> */
	X86_SIM_X86_JCC(X86_CC_E, 0x136f, 0x1418, x86_l_1418);
x86_l_1375:
	/* 0x1375: movzx  edx,WORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 128ULL);
x86_l_137d:
	/* 0x137d: mov    ebp,0xffffff72 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967154ULL);
x86_l_1382:
	/* 0x1382: cmp    eax,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_1385:
	/* 0x1385: jg     139a <tail_handle_nat_fwd_ipv6+0x139a> */
	X86_SIM_X86_JCC(X86_CC_G, 0x1385, 0x139a, x86_l_139a);
x86_l_1387:
	/* 0x1387: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_138a:
	/* 0x138a: je     1418 <tail_handle_nat_fwd_ipv6+0x1418> */
	X86_SIM_X86_JCC(X86_CC_E, 0x138a, 0x1418, x86_l_1418);
x86_l_1390:
	/* 0x1390: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_1393:
	/* 0x1393: je     13a8 <tail_handle_nat_fwd_ipv6+0x13a8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1393, 0x13a8, x86_l_13a8);
x86_l_1395:
	/* 0x1395: jmp    14f2 <tail_handle_nat_fwd_ipv6+0x14f2> */
	X86_SIM_X86_JMP(0x1395, 0x14f2, x86_l_14f2);
x86_l_139a:
	/* 0x139a: cmp    eax,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 58ULL);
x86_l_139d:
	/* 0x139d: je     1418 <tail_handle_nat_fwd_ipv6+0x1418> */
	X86_SIM_X86_JCC(X86_CC_E, 0x139d, 0x1418, x86_l_1418);
x86_l_139f:
	/* 0x139f: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_13a2:
	/* 0x13a2: jne    14f2 <tail_handle_nat_fwd_ipv6+0x14f2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x13a2, 0x14f2, x86_l_14f2);
x86_l_13a8:
	/* 0x13a8: cmp    cx,dx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_16);
x86_l_13ab:
	/* 0x13ab: je     1418 <tail_handle_nat_fwd_ipv6+0x1418> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13ab, 0x1418, x86_l_1418);
x86_l_13ad:
	/* 0x13ad: mov    DWORD PTR [rsp+0xc],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_13b1:
	/* 0x13b1: mov    DWORD PTR [rsp+0x8],r8d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13b6:
	/* 0x13b6: mov    WORD PTR [rsp+0x58],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_13bb:
	/* 0x13bb: lea    rdx,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_13c0:
	/* 0x13c0: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_13c5:
	/* 0x13c5: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_13c8:
	/* 0x13c8: mov    rbp,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13cd:
	/* 0x13cd: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_13cf:
	/* 0x13cf: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_13d4:
	/* 0x13d4: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13d7:
	/* 0x13d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13d9:
	/* 0x13d9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_13db:
	/* 0x13db: mov    QWORD PTR [rsp+0x50],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_13e0:
	/* 0x13e0: js     14b4 <tail_handle_nat_fwd_ipv6+0x14b4> */
	X86_SIM_X86_JCC(X86_CC_S, 0x13e0, 0x14b4, x86_l_14b4);
x86_l_13e6:
	/* 0x13e6: movzx  ecx,WORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 88ULL);
x86_l_13eb:
	/* 0x13eb: lea    esi,[r15+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_13ef:
	/* 0x13ef: mov    r8d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13f4:
	/* 0x13f4: or     r8d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_13f8:
	/* 0x13f8: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_13fd:
	/* 0x13fd: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1400:
	/* 0x1400: mov    edx,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1404:
	/* 0x1404: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1406:
	/* 0x1406: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1408:
	/* 0x1408: js     14e8 <tail_handle_nat_fwd_ipv6+0x14e8> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1408, 0x14e8, x86_l_14e8);
x86_l_140e:
	/* 0x140e: mov    rbx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1413:
	/* 0x1413: mov    r8d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1418:
	/* 0x1418: test   r13b,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_8);
x86_l_141b:
	/* 0x141b: jne    1484 <tail_handle_nat_fwd_ipv6+0x1484> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x141b, 0x1484, x86_l_1484);
x86_l_141d:
	/* 0x141d: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1422:
	/* 0x1422: lea    rdx,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_142a:
	/* 0x142a: mov    eax,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_142f:
	/* 0x142f: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1434:
	/* 0x1434: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1439:
	/* 0x1439: mov    r13d,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R8, X86_WIDTH_32);
x86_l_143c:
	/* 0x143c: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_143f:
	/* 0x143f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1441:
	/* 0x1441: mov    ebp,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_1443:
	/* 0x1443: add    r15d,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_1448:
	/* 0x1448: mov    r8d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R13, X86_WIDTH_32);
x86_l_144b:
	/* 0x144b: or     r8d,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 144ULL);
x86_l_1452:
	/* 0x1452: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_1457:
	/* 0x1457: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_145a:
	/* 0x145a: mov    esi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_145d:
	/* 0x145d: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_145f:
	/* 0x145f: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_1461:
	/* 0x1461: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1463:
	/* 0x1463: cmp    eax,0xffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967274ULL);
x86_l_1466:
	/* 0x1466: jne    1480 <tail_handle_nat_fwd_ipv6+0x1480> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1466, 0x1480, x86_l_1480);
x86_l_1468:
	/* 0x1468: or     r13d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_OR, 16ULL);
x86_l_146c:
	/* 0x146c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_146f:
	/* 0x146f: mov    esi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_1472:
	/* 0x1472: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1474:
	/* 0x1474: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_1476:
	/* 0x1476: mov    r8d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R13, X86_WIDTH_32);
x86_l_1479:
	/* 0x1479: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_147e:
	/* 0x147e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1480:
	/* 0x1480: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1482:
	/* 0x1482: js     14ad <tail_handle_nat_fwd_ipv6+0x14ad> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1482, 0x14ad, x86_l_14ad);
x86_l_1484:
	/* 0x1484: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1487:
	/* 0x1487: mov    BYTE PTR [rsp+0xc],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 51539607554ULL);
x86_l_148c:
	/* 0x148c: test   BYTE PTR [rsp+0x4c],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 326417514497ULL);
x86_l_1491:
	/* 0x1491: jne    14a3 <tail_handle_nat_fwd_ipv6+0x14a3> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1491, 0x14a3, x86_l_14a3);
x86_l_1493:
	/* 0x1493: mov    eax,0xfffff0ff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294963455ULL);
x86_l_1498:
	/* 0x1498: and    eax,DWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 8ULL);
x86_l_149b:
	/* 0x149b: or     eax,0x300 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 768ULL);
x86_l_14a0:
	/* 0x14a0: mov    DWORD PTR [rbx+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14a3:
	/* 0x14a3: mov    r13d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_14a8:
	/* 0x14a8: jmp    1737 <tail_handle_nat_fwd_ipv6+0x1737> */
	X86_SIM_X86_JMP(0x14a8, 0x1737, x86_l_1737);
x86_l_14ad:
	/* 0x14ad: mov    ebp,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967142ULL);
x86_l_14b2:
	/* 0x14b2: jmp    14f2 <tail_handle_nat_fwd_ipv6+0x14f2> */
	X86_SIM_X86_JMP(0x14b2, 0x14f2, x86_l_14f2);
x86_l_14b4:
	/* 0x14b4: mov    ebp,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967155ULL);
x86_l_14b9:
	/* 0x14b9: jmp    14ed <tail_handle_nat_fwd_ipv6+0x14ed> */
	X86_SIM_X86_JMP(0x14b9, 0x14ed, x86_l_14ed);
x86_l_14bb:
	/* 0x14bb: mov    DWORD PTR [rsp+0x4],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_14c0:
	/* 0x14c0: mov    rdi,QWORD PTR [rip+0x119aa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv6_frag_datagrams)));
x86_l_14c7:
	/* 0x14c7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14cc:
	/* 0x14cc: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_14cf:
	/* 0x14cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14d1:
	/* 0x14d1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14d4:
	/* 0x14d4: je     1577 <tail_handle_nat_fwd_ipv6+0x1577> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14d4, 0x1577, x86_l_1577);
x86_l_14da:
	/* 0x14da: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14dc:
	/* 0x14dc: mov    DWORD PTR [rsp+0x80],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_14e3:
	/* 0x14e3: jmp    ae8 <tail_handle_nat_fwd_ipv6+0xae8> */
	X86_SIM_X86_JMP(0x14e3, 0xae8, x86_l_ae8);
x86_l_14e8:
	/* 0x14e8: mov    ebp,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967142ULL);
x86_l_14ed:
	/* 0x14ed: mov    rbx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_14f2:
	/* 0x14f2: mov    BYTE PTR [rsp+0xc],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 51539607554ULL);
x86_l_14f7:
	/* 0x14f7: mov    r13d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_14fc:
	/* 0x14fc: jmp    480 <tail_handle_nat_fwd_ipv6+0x480> */
	X86_SIM_X86_JMP(0x14fc, 0x480, x86_l_480);
x86_l_1501:
	/* 0x1501: mov    rdi,QWORD PTR [rip+0x119aa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv6_frag_datagrams)));
x86_l_1508:
	/* 0x1508: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_150d:
	/* 0x150d: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_1510:
	/* 0x1510: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1513:
	/* 0x1513: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1515:
	/* 0x1515: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1517:
	/* 0x1517: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1519:
	/* 0x1519: je     ae8 <tail_handle_nat_fwd_ipv6+0xae8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1519, 0xae8, x86_l_ae8);
x86_l_151f:
	/* 0x151f: mov    r13,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBX, X86_WIDTH_64);
x86_l_1522:
	/* 0x1522: mov    r14d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1525:
	/* 0x1525: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_152e:
	/* 0x152e: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1537:
	/* 0x1537: movabs rax,0x7201a9020a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 489654125066ULL);
x86_l_1541:
	/* 0x1541: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1546:
	/* 0x1546: mov    rdi,QWORD PTR [rip+0x119aa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_154d:
	/* 0x154d: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1552:
	/* 0x1552: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1557:
	/* 0x1557: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1559:
	/* 0x1559: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_155c:
	/* 0x155c: je     1589 <tail_handle_nat_fwd_ipv6+0x1589> */
	X86_SIM_X86_JCC(X86_CC_E, 0x155c, 0x1589, x86_l_1589);
x86_l_155e:
	/* 0x155e: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1561:
	/* 0x1561: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1565:
	/* 0x1565: mov    rbx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R13, X86_WIDTH_64);
x86_l_1568:
	/* 0x1568: jmp    ae8 <tail_handle_nat_fwd_ipv6+0xae8> */
	X86_SIM_X86_JMP(0x1568, 0xae8, x86_l_ae8);
x86_l_156d:
	/* 0x156d: mov    ebp,0xffffff63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967139ULL);
x86_l_1572:
	/* 0x1572: jmp    a1d <tail_handle_nat_fwd_ipv6+0xa1d> */
	X86_SIM_X86_JMP(0x1572, 0xa1d, x86_l_a1d);
x86_l_1577:
	/* 0x1577: mov    ebp,0xffffff51 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967121ULL);
x86_l_157c:
	/* 0x157c: mov    r14d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1581:
	/* 0x1581: mov    QWORD PTR [r15],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1584:
	/* 0x1584: jmp    c34 <tail_handle_nat_fwd_ipv6+0xc34> */
	X86_SIM_X86_JMP(0x1584, 0xc34, x86_l_c34);
x86_l_1589:
	/* 0x1589: mov    QWORD PTR [rsp+0x20],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953473ULL);
x86_l_1592:
	/* 0x1592: mov    QWORD PTR [rsp+0x28],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1597:
	/* 0x1597: mov    rdi,QWORD PTR [rip+0x119aa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_159e:
	/* 0x159e: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_15a3:
	/* 0x15a3: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_15a8:
	/* 0x15a8: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_15ad:
	/* 0x15ad: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15af:
	/* 0x15af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15b1:
	/* 0x15b1: mov    rbx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_R13, X86_WIDTH_64);
x86_l_15b4:
	/* 0x15b4: jmp    ae8 <tail_handle_nat_fwd_ipv6+0xae8> */
	X86_SIM_X86_JMP(0x15b4, 0xae8, x86_l_ae8);
x86_l_15b9:
	/* 0x15b9: mov    r13d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 2ULL);
x86_l_15bf:
	/* 0x15bf: jmp    f50 <tail_handle_nat_fwd_ipv6+0xf50> */
	X86_SIM_X86_JMP(0x15bf, 0xf50, x86_l_f50);
x86_l_15c4:
	/* 0x15c4: mov    ebp,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_15c9:
	/* 0x15c9: cmp    r12b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_8, 6ULL);
x86_l_15cd:
	/* 0x15cd: jne    1602 <tail_handle_nat_fwd_ipv6+0x1602> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x15cd, 0x1602, x86_l_1602);
x86_l_15cf:
	/* 0x15cf: mov    eax,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_15d2:
	/* 0x15d2: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_15d4:
	/* 0x15d4: shr    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_15d7:
	/* 0x15d7: and    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_15da:
	/* 0x15da: or     ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_OR);
x86_l_15dc:
	/* 0x15dc: mov    WORD PTR [r13+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_15e1:
	/* 0x15e1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_15e3:
	/* 0x15e3: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_15e8:
	/* 0x15e8: mov    ebp,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 21600ULL);
x86_l_15ed:
	/* 0x15ed: cmove  ebp,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_15f0:
	/* 0x15f0: cmp    BYTE PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15f3:
	/* 0x15f3: je     1602 <tail_handle_nat_fwd_ipv6+0x1602> */
	X86_SIM_X86_JCC(X86_CC_E, 0x15f3, 0x1602, x86_l_1602);
x86_l_15f5:
	/* 0x15f5: mov    rax,QWORD PTR [rip+0x119aa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_15fc:
	/* 0x15fc: imul   ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_15ff:
	/* 0x15ff: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1602:
	/* 0x1602: shr    r15d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1606:
	/* 0x1606: cmp    BYTE PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1609:
	/* 0x1609: je     161a <tail_handle_nat_fwd_ipv6+0x161a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1609, 0x161a, x86_l_161a);
x86_l_160b:
	/* 0x160b: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_1610:
	/* 0x1610: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1612:
	/* 0x1612: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1614:
	/* 0x1614: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_1618:
	/* 0x1618: jmp    163d <tail_handle_nat_fwd_ipv6+0x163d> */
	X86_SIM_X86_JMP(0x1618, 0x163d, x86_l_163d);
x86_l_161a:
	/* 0x161a: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_161f:
	/* 0x161f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1621:
	/* 0x1621: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1623:
	/* 0x1623: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1627:
	/* 0x1627: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_1631:
	/* 0x1631: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1634:
	/* 0x1634: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1639:
	/* 0x1639: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_163d:
	/* 0x163d: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_163f:
	/* 0x163f: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1642:
	/* 0x1642: mov    DWORD PTR [r13+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1646:
	/* 0x1646: movzx  ecx,BYTE PTR [r13+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_164b:
	/* 0x164b: mov    edx,DWORD PTR [r13+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_164f:
	/* 0x164f: and    r15b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_1653:
	/* 0x1653: cmp    BYTE PTR [rbx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1656:
	/* 0x1656: je     1669 <tail_handle_nat_fwd_ipv6+0x1669> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1656, 0x1669, x86_l_1669);
x86_l_1658:
	/* 0x1658: mov    rsi,QWORD PTR [rip+0x119aa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_165f:
	/* 0x165f: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1661:
	/* 0x1661: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_1664:
	/* 0x1664: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1667:
	/* 0x1667: jmp    166e <tail_handle_nat_fwd_ipv6+0x166e> */
	X86_SIM_X86_JMP(0x1667, 0x166e, x86_l_166e);
x86_l_1669:
	/* 0x1669: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_166e:
	/* 0x166e: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1670:
	/* 0x1670: or     r15b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_1673:
	/* 0x1673: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_1675:
	/* 0x1675: mov    rbx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_167a:
	/* 0x167a: jb     1681 <tail_handle_nat_fwd_ipv6+0x1681> */
	X86_SIM_X86_JCC(X86_CC_B, 0x167a, 0x1681, x86_l_1681);
x86_l_167c:
	/* 0x167c: cmp    cl,r15b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R15, X86_WIDTH_8);
x86_l_167f:
	/* 0x167f: je     1693 <tail_handle_nat_fwd_ipv6+0x1693> */
	X86_SIM_X86_JCC(X86_CC_E, 0x167f, 0x1693, x86_l_1693);
x86_l_1681:
	/* 0x1681: mov    BYTE PTR [r13+0x2b],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_1685:
	/* 0x1685: mov    DWORD PTR [r13+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1689:
	/* 0x1689: mov    r8,QWORD PTR [rip+0x119aa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R8, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_1690:
	/* 0x1690: mov    eax,DWORD PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1693:
	/* 0x1693: test   BYTE PTR [rsp+0x4c],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 326417514497ULL);
x86_l_1698:
	/* 0x1698: mov    r13d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_169d:
	/* 0x169d: jne    172f <tail_handle_nat_fwd_ipv6+0x172f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x169d, 0x172f, x86_l_172f);
x86_l_16a3:
	/* 0x16a3: mov    DWORD PTR [rbx+0x30],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_16a7:
	/* 0x16a7: mov    rsi,QWORD PTR [rip+0x119aa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_16ae:
	/* 0x16ae: mov    r12d,0x27 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 39ULL);
x86_l_16b4:
	/* 0x16b4: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_16b9:
	/* 0x16b9: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_16bc:
	/* 0x16bc: mov    edx,0x27 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 39ULL);
x86_l_16c1:
	/* 0x16c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16c3:
	/* 0x16c3: mov    ebp,0xffffff74 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967156ULL);
x86_l_16c8:
	/* 0x16c8: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_16ca:
	/* 0x16ca: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_16cc:
	/* 0x16cc: cmovs  eax,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RBP, X86_WIDTH_32, X86_CC_S);
x86_l_16cf:
	/* 0x16cf: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_16d2:
	/* 0x16d2: shl    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_16d6:
	/* 0x16d6: movzx  ecx,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_16da:
	/* 0x16da: mov    DWORD PTR [rbx+0x30],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_16de:
	/* 0x16de: mov    DWORD PTR [rbx+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_16e5:
	/* 0x16e5: or     ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_OR);
x86_l_16e7:
	/* 0x16e7: mov    DWORD PTR [rbx+0x38],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_16ea:
	/* 0x16ea: movabs rcx,0x118710200000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 78937246882856960ULL);
x86_l_16f4:
	/* 0x16f4: mov    QWORD PTR [rbx+0x3c],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_16f8:
	/* 0x16f8: mov    r14d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16fb:
	/* 0x16fb: movabs rcx,0x7101180200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 485349655040ULL);
x86_l_1705:
	/* 0x1705: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_170a:
	/* 0x170a: mov    BYTE PTR [rsp+0x20],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_170e:
	/* 0x170e: mov    rdi,QWORD PTR [rip+0x119aa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1715:
	/* 0x1715: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_171a:
	/* 0x171a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_171f:
	/* 0x171f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1721:
	/* 0x1721: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1724:
	/* 0x1724: je     173e <tail_handle_nat_fwd_ipv6+0x173e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1724, 0x173e, x86_l_173e);
x86_l_1726:
	/* 0x1726: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1729:
	/* 0x1729: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_172d:
	/* 0x172d: jmp    176f <tail_handle_nat_fwd_ipv6+0x176f> */
	X86_SIM_X86_JMP(0x172d, 0x176f, x86_l_176f);
x86_l_172f:
	/* 0x172f: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1732:
	/* 0x1732: mov    BYTE PTR [rsp+0xc],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 51539607557ULL);
x86_l_1737:
	/* 0x1737: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1739:
	/* 0x1739: jmp    480 <tail_handle_nat_fwd_ipv6+0x480> */
	X86_SIM_X86_JMP(0x1739, 0x480, x86_l_480);
x86_l_173e:
	/* 0x173e: mov    QWORD PTR [rsp+0xa8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505729ULL);
x86_l_174a:
	/* 0x174a: mov    QWORD PTR [rsp+0xb0],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1752:
	/* 0x1752: mov    rdi,QWORD PTR [rip+0x119aa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1759:
	/* 0x1759: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_175e:
	/* 0x175e: lea    rdx,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1766:
	/* 0x1766: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_176b:
	/* 0x176b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_176d:
	/* 0x176d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_176f:
	/* 0x176f: mov    rsi,QWORD PTR [rip+0x119aa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_1776:
	/* 0x1776: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_177b:
	/* 0x177b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_177e:
	/* 0x177e: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_1783:
	/* 0x1783: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1785:
	/* 0x1785: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_178a:
	/* 0x178a: jmp    8b7 <tail_handle_nat_fwd_ipv6+0x8b7> */
	X86_SIM_X86_JMP(0x178a, 0x8b7, x86_l_8b7);
x86_l_178f:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
