extern char __config_cluster_id_bits;
extern char __config_debug_lb;
extern char __config_enable_conntrack_accounting;
extern char __config_enable_identity_mark;
extern char __config_enable_ipv4_fragments;
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
extern char cilium_ct4_global;
extern char cilium_ct_any4_global;
extern char cilium_devices;
extern char cilium_events;
extern char cilium_ipv4_frag_datagrams;
extern char cilium_lb4_reverse_nat;
extern char cilium_metrics;
extern char cilium_percpu_trace_id;
extern char cilium_ratelimit;
extern char cilium_ratelimit_metrics;
extern char cilium_snat_v4_external;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int cilium_bpf_host_cil_to_netdev_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0xc8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 200ULL);
x86_l_a:
	/* 0xa: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: mov    ebp,DWORD PTR [rdi+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_13:
	/* 0x13: mov    rax,QWORD PTR [rdi+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1a:
	/* 0x1a: mov    ecx,DWORD PTR [rdi+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1d:
	/* 0x1d: mov    edx,DWORD PTR [rdi+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_20:
	/* 0x20: mov    r13,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_27:
	/* 0x27: movzx  esi,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2c:
	/* 0x2c: cmp    BYTE PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_31:
	/* 0x31: je     3d <cil_to_netdev+0x3d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x31, 0x3d, x86_l_3d);
x86_l_33:
	/* 0x33: sub    ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_35:
	/* 0x35: cmp    ecx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_37:
	/* 0x37: jae    46 <cil_to_netdev+0x46> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x37, 0x46, x86_l_46);
x86_l_39:
	/* 0x39: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3b:
	/* 0x3b: jmp    4a <cil_to_netdev+0x4a> */
	X86_SIM_X86_JMP(0x3b, 0x4a, x86_l_4a);
x86_l_3d:
	/* 0x3d: movzx  eax,WORD PTR [rbx+0xb4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 180ULL);
x86_l_44:
	/* 0x44: jmp    4a <cil_to_netdev+0x4a> */
	X86_SIM_X86_JMP(0x44, 0x4a, x86_l_4a);
x86_l_46:
	/* 0x46: movzx  eax,WORD PTR [rax+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_4a:
	/* 0x4a: mov    DWORD PTR [rsp+0xbc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_51:
	/* 0x51: mov    DWORD PTR [rbx+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_58:
	/* 0x58: mov    DWORD PTR [rbx+0x2c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561024ULL);
x86_l_5f:
	/* 0x5f: mov    DWORD PTR [rbx+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_66:
	/* 0x66: mov    DWORD PTR [rbx+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_6d:
	/* 0x6d: mov    DWORD PTR [rbx+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_74:
	/* 0x74: mov    r15,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_tracing_ip_option_type)));
x86_l_7b:
	/* 0x7b: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7f:
	/* 0x7f: je     105 <cil_to_netdev+0x105> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7f, 0x105, x86_l_105);
x86_l_85:
	/* 0x85: movzx  r12d,BYTE PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_89:
	/* 0x89: mov    rax,QWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_90:
	/* 0x90: mov    ecx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_93:
	/* 0x93: sub    ecx,DWORD PTR [rbx+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_96:
	/* 0x96: movzx  edx,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_9b:
	/* 0x9b: cmp    BYTE PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a0:
	/* 0xa0: je     b8 <cil_to_netdev+0xb8> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa0, 0xb8, x86_l_b8);
x86_l_a2:
	/* 0xa2: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_a4:
	/* 0xa4: jb     de <cil_to_netdev+0xde> */
	X86_SIM_X86_JCC(X86_CC_B, 0xa4, 0xde, x86_l_de);
x86_l_a6:
	/* 0xa6: movzx  edx,WORD PTR [rax+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_aa:
	/* 0xaa: cmp    dx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_16, 6ULL);
x86_l_ae:
	/* 0xae: jb     de <cil_to_netdev+0xde> */
	X86_SIM_X86_JCC(X86_CC_B, 0xae, 0xde, x86_l_de);
x86_l_b0:
	/* 0xb0: cmp    dx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_16, 8ULL);
x86_l_b4:
	/* 0xb4: je     c5 <cil_to_netdev+0xc5> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb4, 0xc5, x86_l_c5);
x86_l_b6:
	/* 0xb6: jmp    de <cil_to_netdev+0xde> */
	X86_SIM_X86_JMP(0xb6, 0xde, x86_l_de);
x86_l_b8:
	/* 0xb8: movzx  edx,WORD PTR [rbx+0xb4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 180ULL);
x86_l_bf:
	/* 0xbf: cmp    dx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_16, 8ULL);
x86_l_c3:
	/* 0xc3: jne    de <cil_to_netdev+0xde> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xc3, 0xde, x86_l_de);
x86_l_c5:
	/* 0xc5: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_c8:
	/* 0xc8: movzx  edx,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_cd:
	/* 0xcd: lea    rsi,[rax+rdx*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_d1:
	/* 0xd1: add    rsi,0x14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 20ULL);
x86_l_d5:
	/* 0xd5: cmp    rsi,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_64);
x86_l_d8:
	/* 0xd8: jbe    53d <cil_to_netdev+0x53d> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xd8, 0x53d, x86_l_53d);
x86_l_de:
	/* 0xde: mov    DWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_e6:
	/* 0xe6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_eb:
	/* 0xeb: mov    rdi,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_percpu_trace_id)));
x86_l_f2:
	/* 0xf2: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_f7:
	/* 0xf7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f9:
	/* 0xf9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_fc:
	/* 0xfc: je     105 <cil_to_netdev+0x105> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfc, 0x105, x86_l_105);
x86_l_fe:
	/* 0xfe: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_105:
	/* 0x105: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_107:
	/* 0x107: and    eax,0x700 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 1792ULL);
x86_l_10c:
	/* 0x10c: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_112:
	/* 0x112: cmp    eax,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1024ULL);
x86_l_117:
	/* 0x117: je     19e <cil_to_netdev+0x19e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x117, 0x19e, x86_l_19e);
x86_l_11d:
	/* 0x11d: and    ebp,0xf00 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 3840ULL);
x86_l_123:
	/* 0x123: cmp    ebp,0xe00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 3584ULL);
x86_l_129:
	/* 0x129: je     19e <cil_to_netdev+0x19e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x129, 0x19e, x86_l_19e);
x86_l_12b:
	/* 0x12b: cmp    ebp,0xb00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 2816ULL);
x86_l_131:
	/* 0x131: je     14a <cil_to_netdev+0x14a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x131, 0x14a, x86_l_14a);
x86_l_133:
	/* 0x133: mov    rax,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_identity_mark)));
x86_l_13a:
	/* 0x13a: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13d:
	/* 0x13d: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_140:
	/* 0x140: je     19e <cil_to_netdev+0x19e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x140, 0x19e, x86_l_19e);
x86_l_142:
	/* 0x142: cmp    ebp,0xf00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 3840ULL);
x86_l_148:
	/* 0x148: jne    19e <cil_to_netdev+0x19e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x148, 0x19e, x86_l_19e);
x86_l_14a:
	/* 0x14a: mov    eax,DWORD PTR [rbx+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_150:
	/* 0x150: movzx  edx,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_153:
	/* 0x153: mov    rcx,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_cluster_id_bits)));
x86_l_15a:
	/* 0x15a: mov    esi,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15c:
	/* 0x15c: mov    edi,0x7fffff00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 2147483392ULL);
x86_l_161:
	/* 0x161: bzhi   esi,edi,esi */
	X86_SIM_RUN_OP(X86_OP_BZHI, X86_RSI, X86_RDI, X86_WIDTH_32, X86_RSI, 0);
x86_l_166:
	/* 0x166: mov    edi,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_168:
	/* 0x168: neg    dil */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_8, X86_ALU_NEG, 0);
x86_l_16b:
	/* 0x16b: shlx   esi,esi,edi */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RSI, X86_RSI, X86_WIDTH_32, X86_RDI, X86_ALU_SHL);
x86_l_170:
	/* 0x170: and    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_AND);
x86_l_172:
	/* 0x172: mov    edi,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_174:
	/* 0x174: neg    dil */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_8, X86_ALU_NEG, 0);
x86_l_177:
	/* 0x177: shrx   esi,esi,edi */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RSI, X86_RSI, X86_WIDTH_32, X86_RDI, X86_ALU_SHR);
x86_l_17c:
	/* 0x17c: or     esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_17e:
	/* 0x17e: shr    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_181:
	/* 0x181: mov    edx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_183:
	/* 0x183: mov    dil,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_8, 24ULL);
x86_l_186:
	/* 0x186: mov    r8b,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_8, 24ULL);
x86_l_189:
	/* 0x189: sub    r8b,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_18c:
	/* 0x18c: bzhi   eax,eax,r8d */
	X86_SIM_RUN_OP(X86_OP_BZHI, X86_RAX, X86_RAX, X86_WIDTH_32, X86_R8, 0);
x86_l_191:
	/* 0x191: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_193:
	/* 0x193: sub    dil,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_196:
	/* 0x196: shlx   r12d,esi,edi */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_R12, X86_RSI, X86_WIDTH_32, X86_RDI, X86_ALU_SHL);
x86_l_19b:
	/* 0x19b: or     r12d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_32, X86_ALU_OR);
x86_l_19e:
	/* 0x19e: mov    ecx,DWORD PTR [rbx+0x9c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_1a4:
	/* 0x1a4: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1a6:
	/* 0x1a6: je     1fc <cil_to_netdev+0x1fc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a6, 0x1fc, x86_l_1fc);
x86_l_1a8:
	/* 0x1a8: test   ecx,0xfff0000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_32, 268369920ULL);
x86_l_1ae:
	/* 0x1ae: je     1fc <cil_to_netdev+0x1fc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1ae, 0x1fc, x86_l_1fc);
x86_l_1b0:
	/* 0x1b0: mov    rax,QWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b4:
	/* 0x1b4: mov    ebp,0xffffff4a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967114ULL);
x86_l_1b9:
	/* 0x1b9: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1bc:
	/* 0x1bc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1bf:
	/* 0x1bf: je     1598 <cil_to_netdev+0x1598> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1bf, 0x1598, x86_l_1598);
x86_l_1c5:
	/* 0x1c5: mov    eax,DWORD PTR [rax+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_1cb:
	/* 0x1cb: cmp    eax,0x75 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 117ULL);
x86_l_1ce:
	/* 0x1ce: je     5ae <cil_to_netdev+0x5ae> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1ce, 0x5ae, x86_l_5ae);
x86_l_1d4:
	/* 0x1d4: cmp    eax,0x74 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 116ULL);
x86_l_1d7:
	/* 0x1d7: jne    1598 <cil_to_netdev+0x1598> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1d7, 0x1598, x86_l_1598);
x86_l_1dd:
	/* 0x1dd: and    ecx,0xffe0000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 268304384ULL);
x86_l_1e3:
	/* 0x1e3: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e6:
	/* 0x1e6: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_1eb:
	/* 0x1eb: cmp    ecx,0xfa00000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 262144000ULL);
x86_l_1f1:
	/* 0x1f1: jne    1598 <cil_to_netdev+0x1598> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1f1, 0x1598, x86_l_1598);
x86_l_1f7:
	/* 0x1f7: jmp    1641 <cil_to_netdev+0x1641> */
	X86_SIM_X86_JMP(0x1f7, 0x1641, x86_l_1641);
x86_l_1fc:
	/* 0x1fc: mov    eax,0xf00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3840ULL);
x86_l_201:
	/* 0x201: and    eax,DWORD PTR [rbx+0xa8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 168ULL);
x86_l_207:
	/* 0x207: mov    r14b,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_8, 5ULL);
x86_l_20a:
	/* 0x20a: cmp    eax,0x300 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 768ULL);
x86_l_20f:
	/* 0x20f: je     2eb <cil_to_netdev+0x2eb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x20f, 0x2eb, x86_l_2eb);
x86_l_215:
	/* 0x215: cmp    eax,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1024ULL);
x86_l_21a:
	/* 0x21a: je     2eb <cil_to_netdev+0x2eb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x21a, 0x2eb, x86_l_2eb);
x86_l_220:
	/* 0x220: cmp    WORD PTR [rsp+0xbc],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 807453851656ULL);
x86_l_229:
	/* 0x229: jne    2eb <cil_to_netdev+0x2eb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x229, 0x2eb, x86_l_2eb);
x86_l_22f:
	/* 0x22f: mov    DWORD PTR [rsp+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_23a:
	/* 0x23a: mov    QWORD PTR [rsp+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_246:
	/* 0x246: mov    QWORD PTR [rsp+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_252:
	/* 0x252: mov    QWORD PTR [rsp+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_25e:
	/* 0x25e: mov    QWORD PTR [rsp+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_26a:
	/* 0x26a: mov    QWORD PTR [rsp+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_276:
	/* 0x276: mov    QWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_282:
	/* 0x282: mov    QWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_28e:
	/* 0x28e: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_297:
	/* 0x297: movzx  edi,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_29c:
	/* 0x29c: mov    QWORD PTR [rsp+0x1e],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128849018880ULL);
x86_l_2a5:
	/* 0x2a5: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_2ae:
	/* 0x2ae: movzx  ecx,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2b3:
	/* 0x2b3: mov    edx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2b6:
	/* 0x2b6: sub    edx,DWORD PTR [rbx+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_2b9:
	/* 0x2b9: mov    rax,QWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_2c0:
	/* 0x2c0: add    rdx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2c3:
	/* 0x2c3: lea    rsi,[rax+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_2c7:
	/* 0x2c7: add    rsi,0x14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 20ULL);
x86_l_2cb:
	/* 0x2cb: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_2d0:
	/* 0x2d0: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d3:
	/* 0x2d3: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_2d6:
	/* 0x2d6: jbe    7ae <cil_to_netdev+0x7ae> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x2d6, 0x7ae, x86_l_7ae);
x86_l_2dc:
	/* 0x2dc: mov    DWORD PTR [rsp+0xc],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2e1:
	/* 0x2e1: mov    r12d,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2e6:
	/* 0x2e6: jmp    1598 <cil_to_netdev+0x1598> */
	X86_SIM_X86_JMP(0x2e6, 0x1598, x86_l_1598);
x86_l_2eb:
	/* 0x2eb: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2f3:
	/* 0x2f3: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f5:
	/* 0x2f5: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_2f7:
	/* 0x2f7: js     1650 <cil_to_netdev+0x1650> */
	X86_SIM_X86_JCC(X86_CC_S, 0x2f7, 0x1650, x86_l_1650);
x86_l_2fd:
	/* 0x2fd: cmp    ebp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_300:
	/* 0x300: je     1650 <cil_to_netdev+0x1650> */
	X86_SIM_X86_JCC(X86_CC_E, 0x300, 0x1650, x86_l_1650);
x86_l_306:
	/* 0x306: mov    rax,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_interface_ifindex)));
x86_l_30d:
	/* 0x30d: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30f:
	/* 0x30f: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_313:
	/* 0x313: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_317:
	/* 0x317: je     33e <cil_to_netdev+0x33e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x317, 0x33e, x86_l_33e);
x86_l_319:
	/* 0x319: mov    DWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_321:
	/* 0x321: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_326:
	/* 0x326: mov    rdi,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_percpu_trace_id)));
x86_l_32d:
	/* 0x32d: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_332:
	/* 0x332: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_334:
	/* 0x334: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_337:
	/* 0x337: je     34a <cil_to_netdev+0x34a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x337, 0x34a, x86_l_34a);
x86_l_339:
	/* 0x339: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_33c:
	/* 0x33c: jmp    34c <cil_to_netdev+0x34c> */
	X86_SIM_X86_JMP(0x33c, 0x34c, x86_l_34c);
x86_l_33e:
	/* 0x33e: mov    r15d,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R14, X86_WIDTH_32);
x86_l_341:
	/* 0x341: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_343:
	/* 0x343: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_348:
	/* 0x348: jmp    354 <cil_to_netdev+0x354> */
	X86_SIM_X86_JMP(0x348, 0x354, x86_l_354);
x86_l_34a:
	/* 0x34a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_34c:
	/* 0x34c: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_351:
	/* 0x351: mov    r15d,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R14, X86_WIDTH_32);
x86_l_354:
	/* 0x354: mov    r14d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_358:
	/* 0x358: mov    QWORD PTR [rsp+0x68],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598786ULL);
x86_l_361:
	/* 0x361: mov    QWORD PTR [rsp+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_36d:
	/* 0x36d: mov    QWORD PTR [rsp+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_379:
	/* 0x379: mov    QWORD PTR [rsp+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_385:
	/* 0x385: mov    QWORD PTR [rsp+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_391:
	/* 0x391: mov    QWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_39d:
	/* 0x39d: mov    QWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_3a9:
	/* 0x3a9: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_3b2:
	/* 0x3b2: mov    eax,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_3b7:
	/* 0x3b7: add    rax,0x5f30201 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 99811841ULL);
x86_l_3bd:
	/* 0x3bd: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3c2:
	/* 0x3c2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3c7:
	/* 0x3c7: mov    rdi,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_3ce:
	/* 0x3ce: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3d3:
	/* 0x3d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d5:
	/* 0x3d5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3d8:
	/* 0x3d8: je     3f0 <cil_to_netdev+0x3f0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3d8, 0x3f0, x86_l_3f0);
x86_l_3da:
	/* 0x3da: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_3dd:
	/* 0x3dd: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3e1:
	/* 0x3e1: mov    r9,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_R14, X86_WIDTH_64);
x86_l_3e4:
	/* 0x3e4: cmp    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_3e9:
	/* 0x3e9: jne    426 <cil_to_netdev+0x426> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3e9, 0x426, x86_l_426);
x86_l_3eb:
	/* 0x3eb: jmp    7a7 <cil_to_netdev+0x7a7> */
	X86_SIM_X86_JMP(0x3eb, 0x7a7, x86_l_7a7);
x86_l_3f0:
	/* 0x3f0: mov    QWORD PTR [rsp+0x28],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691841ULL);
x86_l_3f9:
	/* 0x3f9: mov    QWORD PTR [rsp+0x30],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3fe:
	/* 0x3fe: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_403:
	/* 0x403: mov    rdi,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_40a:
	/* 0x40a: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_40f:
	/* 0x40f: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_414:
	/* 0x414: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_416:
	/* 0x416: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_418:
	/* 0x418: mov    r9,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_R14, X86_WIDTH_64);
x86_l_41b:
	/* 0x41b: cmp    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_420:
	/* 0x420: je     7a7 <cil_to_netdev+0x7a7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x420, 0x7a7, x86_l_7a7);
x86_l_426:
	/* 0x426: mov    rax,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_events_map_rate_limit)));
x86_l_42d:
	/* 0x42d: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_430:
	/* 0x430: je     63f <cil_to_netdev+0x63f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x430, 0x63f, x86_l_63f);
x86_l_436:
	/* 0x436: mov    QWORD PTR [rsp+0x58],r9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_43b:
	/* 0x43b: mov    BYTE PTR [rsp+0x3c],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_440:
	/* 0x440: mov    DWORD PTR [rsp+0xc],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_445:
	/* 0x445: mov    rcx,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_events_map_burst_limit)));
x86_l_44c:
	/* 0x44c: mov    r15d,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_44f:
	/* 0x44f: mov    r13d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_452:
	/* 0x452: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_457:
	/* 0x457: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_459:
	/* 0x459: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_45b:
	/* 0x45b: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_45e:
	/* 0x45e: mov    DWORD PTR [rsp+0x60],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 412316860418ULL);
x86_l_466:
	/* 0x466: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_46b:
	/* 0x46b: mov    rdi,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit_metrics)));
x86_l_472:
	/* 0x472: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_477:
	/* 0x477: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_479:
	/* 0x479: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_47c:
	/* 0x47c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_47f:
	/* 0x47f: jne    4af <cil_to_netdev+0x4af> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x47f, 0x4af, x86_l_4af);
x86_l_481:
	/* 0x481: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_48a:
	/* 0x48a: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_48f:
	/* 0x48f: mov    rdi,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit_metrics)));
x86_l_496:
	/* 0x496: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_49b:
	/* 0x49b: lea    r14,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4a0:
	/* 0x4a0: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_4a3:
	/* 0x4a3: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4a5:
	/* 0x4a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a7:
	/* 0x4a7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4a9:
	/* 0x4a9: js     7a7 <cil_to_netdev+0x7a7> */
	X86_SIM_X86_JCC(X86_CC_S, 0x4a9, 0x7a7, x86_l_7a7);
x86_l_4af:
	/* 0x4af: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4b4:
	/* 0x4b4: mov    rdi,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit)));
x86_l_4bb:
	/* 0x4bb: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_4c0:
	/* 0x4c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c2:
	/* 0x4c2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4c5:
	/* 0x4c5: je     5d3 <cil_to_netdev+0x5d3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4c5, 0x5d3, x86_l_5d3);
x86_l_4cb:
	/* 0x4cb: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ce:
	/* 0x4ce: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_4d1:
	/* 0x4d1: sub    rsi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_4d4:
	/* 0x4d4: cmp    rsi,0x3b9aca00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 1000000000ULL);
x86_l_4db:
	/* 0x4db: jbe    614 <cil_to_netdev+0x614> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x4db, 0x614, x86_l_614);
x86_l_4e1:
	/* 0x4e1: mov    rdx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_4e4:
	/* 0x4e4: shr    rdx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_4e8:
	/* 0x4e8: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_4f2:
	/* 0x4f2: mulx   rcx,rcx,rcx */
	X86_SIM_L_EXEC_MULX(X86_RCX, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_4f7:
	/* 0x4f7: shr    rcx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_4fb:
	/* 0x4fb: imul   rdx,rcx,0x3b9aca00 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RDX, X86_RCX, X86_WIDTH_64, 1000000000ULL);
x86_l_502:
	/* 0x502: imul   rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_IMUL);
x86_l_506:
	/* 0x506: add    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_50a:
	/* 0x50a: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_50e:
	/* 0x50e: sub    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_511:
	/* 0x511: add    r12,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_514:
	/* 0x514: mov    QWORD PTR [rax],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_517:
	/* 0x517: cmp    rcx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_51a:
	/* 0x51a: mov    r13,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_521:
	/* 0x521: mov    r12d,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_526:
	/* 0x526: mov    r9,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_52b:
	/* 0x52b: jbe    629 <cil_to_netdev+0x629> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x52b, 0x629, x86_l_629);
x86_l_531:
	/* 0x531: mov    QWORD PTR [rax+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_535:
	/* 0x535: mov    rcx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_538:
	/* 0x538: jmp    629 <cil_to_netdev+0x629> */
	X86_SIM_X86_JMP(0x538, 0x629, x86_l_629);
x86_l_53d:
	/* 0x53d: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_540:
	/* 0x540: movzx  r13d,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_544:
	/* 0x544: mov    eax,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_547:
	/* 0x547: and    al,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_AND, 14ULL);
x86_l_549:
	/* 0x549: cmp    al,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 6ULL);
x86_l_54b:
	/* 0x54b: jb     b5b <cil_to_netdev+0xb5b> */
	X86_SIM_X86_JCC(X86_CC_B, 0x54b, 0xb5b, x86_l_b5b);
x86_l_551:
	/* 0x551: mov    rax,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_558:
	/* 0x558: movzx  r14d,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_55c:
	/* 0x55c: shl    r13d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHL, 2ULL);
x86_l_560:
	/* 0x560: and    r13d,0x3c */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 60ULL);
x86_l_564:
	/* 0x564: je     b5b <cil_to_netdev+0xb5b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x564, 0xb5b, x86_l_b5b);
x86_l_56a:
	/* 0x56a: lea    esi,[r14+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_56e:
	/* 0x56e: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_573:
	/* 0x573: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_578:
	/* 0x578: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_57b:
	/* 0x57b: mov    QWORD PTR [rsp+0x10],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_580:
	/* 0x580: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_585:
	/* 0x585: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_587:
	/* 0x587: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_589:
	/* 0x589: js     b91 <cil_to_netdev+0xb91> */
	X86_SIM_X86_JCC(X86_CC_S, 0x589, 0xb91, x86_l_b91);
x86_l_58f:
	/* 0x58f: movzx  eax,BYTE PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 40ULL);
x86_l_594:
	/* 0x594: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_596:
	/* 0x596: je     b5b <cil_to_netdev+0xb5b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x596, 0xb5b, x86_l_b5b);
x86_l_59c:
	/* 0x59c: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_59f:
	/* 0x59f: jne    9f9 <cil_to_netdev+0x9f9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x59f, 0x9f9, x86_l_9f9);
x86_l_5a5:
	/* 0x5a5: lea    eax,[r14+0x15] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 21ULL);
x86_l_5a9:
	/* 0x5a9: jmp    a7f <cil_to_netdev+0xa7f> */
	X86_SIM_X86_JMP(0x5a9, 0xa7f, x86_l_a7f);
x86_l_5ae:
	/* 0x5ae: shr    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_5b1:
	/* 0x5b1: and    ecx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5b7:
	/* 0x5b7: add    ecx,0xfffff05d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 4294963293ULL);
x86_l_5bd:
	/* 0x5bd: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5c0:
	/* 0x5c0: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_5c5:
	/* 0x5c5: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_5c8:
	/* 0x5c8: jae    1598 <cil_to_netdev+0x1598> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x5c8, 0x1598, x86_l_1598);
x86_l_5ce:
	/* 0x5ce: jmp    1641 <cil_to_netdev+0x1641> */
	X86_SIM_X86_JMP(0x5ce, 0x1641, x86_l_1641);
x86_l_5d3:
	/* 0x5d3: mov    QWORD PTR [rsp+0x28],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5d8:
	/* 0x5d8: dec    r13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_5db:
	/* 0x5db: mov    QWORD PTR [rsp+0x30],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5e0:
	/* 0x5e0: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5e5:
	/* 0x5e5: mov    rdi,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit)));
x86_l_5ec:
	/* 0x5ec: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_5f1:
	/* 0x5f1: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5f6:
	/* 0x5f6: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5f8:
	/* 0x5f8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5fa:
	/* 0x5fa: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5fc:
	/* 0x5fc: mov    r13,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_603:
	/* 0x603: mov    r12d,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_608:
	/* 0x608: mov    r9,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_60d:
	/* 0x60d: jns    639 <cil_to_netdev+0x639> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x60d, 0x639, x86_l_639);
x86_l_60f:
	/* 0x60f: jmp    902 <cil_to_netdev+0x902> */
	X86_SIM_X86_JMP(0x60f, 0x902, x86_l_902);
x86_l_614:
	/* 0x614: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_618:
	/* 0x618: mov    r13,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_61f:
	/* 0x61f: mov    r12d,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_624:
	/* 0x624: mov    r9,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_629:
	/* 0x629: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_62c:
	/* 0x62c: je     902 <cil_to_netdev+0x902> */
	X86_SIM_X86_JCC(X86_CC_E, 0x62c, 0x902, x86_l_902);
x86_l_632:
	/* 0x632: dec    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_635:
	/* 0x635: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_639:
	/* 0x639: movzx  r15d,BYTE PTR [rsp+0x3c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 60ULL);
x86_l_63f:
	/* 0x63f: mov    eax,DWORD PTR [rsp+0xbc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188ULL);
x86_l_646:
	/* 0x646: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_649:
	/* 0x649: jne    652 <cil_to_netdev+0x652> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x649, 0x652, x86_l_652);
x86_l_64b:
	/* 0x64b: movzx  eax,WORD PTR [rbx+0xb4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 180ULL);
x86_l_652:
	/* 0x652: cmp    BYTE PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_657:
	/* 0x657: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_65a:
	/* 0x65a: add    cl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_8, X86_ALU_ADD);
x86_l_65c:
	/* 0x65c: movzx  eax,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_65f:
	/* 0x65f: cmp    eax,0xdd86 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 56710ULL);
x86_l_664:
	/* 0x664: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_667:
	/* 0x667: or     al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_669:
	/* 0x669: mov    ecx,0xf00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 3840ULL);
x86_l_66e:
	/* 0x66e: and    ecx,DWORD PTR [rbx+0xa8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 168ULL);
x86_l_674:
	/* 0x674: cmp    ecx,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1024ULL);
x86_l_67a:
	/* 0x67a: jne    69c <cil_to_netdev+0x69c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x67a, 0x69c, x86_l_69c);
x86_l_67c:
	/* 0x67c: mov    rdx,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_tunnel_protocol)));
x86_l_683:
	/* 0x683: movzx  esi,BYTE PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_686:
	/* 0x686: mov    cl,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 4ULL);
x86_l_688:
	/* 0x688: cmp    sil,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_8, 1ULL);
x86_l_68c:
	/* 0x68c: je     69a <cil_to_netdev+0x69a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x68c, 0x69a, x86_l_69a);
x86_l_68e:
	/* 0x68e: movzx  ecx,BYTE PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_691:
	/* 0x691: cmp    cl,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_694:
	/* 0x694: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_697:
	/* 0x697: shl    cl,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_69a:
	/* 0x69a: or     al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_69c:
	/* 0x69c: mov    rcx,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_6a3:
	/* 0x6a3: mov    edx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6a5:
	/* 0x6a5: mov    rdi,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_tunnel_protocol)));
x86_l_6ac:
	/* 0x6ac: movzx  r8d,BYTE PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_6b0:
	/* 0x6b0: mov    sil,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_8, 4ULL);
x86_l_6b3:
	/* 0x6b3: cmp    r8b,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_8, 1ULL);
x86_l_6b7:
	/* 0x6b7: je     6c8 <cil_to_netdev+0x6c8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6b7, 0x6c8, x86_l_6c8);
x86_l_6b9:
	/* 0x6b9: movzx  esi,BYTE PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_6bc:
	/* 0x6bc: cmp    sil,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_8, 2ULL);
x86_l_6c0:
	/* 0x6c0: sete   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_E);
x86_l_6c4:
	/* 0x6c4: shl    sil,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_6c8:
	/* 0x6c8: test   sil,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RAX, X86_WIDTH_8);
x86_l_6cb:
	/* 0x6cb: je     6d6 <cil_to_netdev+0x6d6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6cb, 0x6d6, x86_l_6d6);
x86_l_6cd:
	/* 0x6cd: mov    rdx,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_trace_payload_len_overlay)));
x86_l_6d4:
	/* 0x6d4: mov    edx,DWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6d6:
	/* 0x6d6: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6d8:
	/* 0x6d8: mov    esi,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6dc:
	/* 0x6dc: cmp    ecx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_6de:
	/* 0x6de: cmovne edx,esi */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RSI, X86_WIDTH_32, X86_CC_NE);
x86_l_6e1:
	/* 0x6e1: mov    ecx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_6e4:
	/* 0x6e4: cmp    edx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_6e6:
	/* 0x6e6: mov    rsi,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_host_ep_id)));
x86_l_6ed:
	/* 0x6ed: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_6f0:
	/* 0x6f0: cmovae edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_AE);
x86_l_6f3:
	/* 0x6f3: mov    ecx,DWORD PTR [rbx+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_6f9:
	/* 0x6f9: mov    WORD PTR [rsp+0x78],0xb04 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 515396078340ULL);
x86_l_700:
	/* 0x700: mov    WORD PTR [rsp+0x7a],si */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 122ULL);
x86_l_705:
	/* 0x705: mov    DWORD PTR [rsp+0x7c],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_709:
	/* 0x709: mov    DWORD PTR [rsp+0x80],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_711:
	/* 0x711: mov    WORD PTR [rsp+0x84],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_719:
	/* 0x719: mov    WORD PTR [rsp+0x86],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 575525617666ULL);
x86_l_723:
	/* 0x723: mov    DWORD PTR [rsp+0x88],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_72b:
	/* 0x72b: mov    DWORD PTR [rsp+0x8c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_736:
	/* 0x736: mov    WORD PTR [rsp+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_740:
	/* 0x740: mov    BYTE PTR [rsp+0x92],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 146ULL);
x86_l_748:
	/* 0x748: mov    BYTE PTR [rsp+0x93],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 147ULL);
x86_l_74f:
	/* 0x74f: mov    eax,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_753:
	/* 0x753: mov    DWORD PTR [rsp+0x94],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_75a:
	/* 0x75a: mov    rax,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_75f:
	/* 0x75f: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_767:
	/* 0x767: mov    QWORD PTR [rsp+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_773:
	/* 0x773: mov    QWORD PTR [rsp+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_77f:
	/* 0x77f: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_784:
	/* 0x784: shl    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_788:
	/* 0x788: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_78d:
	/* 0x78d: or     rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_790:
	/* 0x790: mov    rsi,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_events)));
x86_l_797:
	/* 0x797: lea    rcx,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_79c:
	/* 0x79c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_79f:
	/* 0x79f: mov    r8d,0x38 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 56ULL);
x86_l_7a5:
	/* 0x7a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7a7:
	/* 0x7a7: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_7a9:
	/* 0x7a9: jmp    1641 <cil_to_netdev+0x1641> */
	X86_SIM_X86_JMP(0x7a9, 0x1641, x86_l_1641);
x86_l_7ae:
	/* 0x7ae: mov    QWORD PTR [rsp+0x48],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_7b3:
	/* 0x7b3: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_7b6:
	/* 0x7b6: movabs r9,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_64, 2199023255552ULL);
x86_l_7c0:
	/* 0x7c0: mov    r8,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R13, X86_WIDTH_64);
x86_l_7c3:
	/* 0x7c3: movabs r13,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 1099511627776ULL);
x86_l_7cd:
	/* 0x7cd: movzx  edx,WORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_7d1:
	/* 0x7d1: movzx  ecx,BYTE PTR [rax+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_7d5:
	/* 0x7d5: mov    rsi,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RCX, X86_WIDTH_64);
x86_l_7d8:
	/* 0x7d8: shl    rsi,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_7dc:
	/* 0x7dc: or     rsi,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_64, X86_ALU_OR);
x86_l_7df:
	/* 0x7df: movzx  edx,WORD PTR [rax+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_7e3:
	/* 0x7e3: lea    rdi,[rsi+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_7e7:
	/* 0x7e7: test   edx,0xff3f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_32, 65343ULL);
x86_l_7ed:
	/* 0x7ed: cmove  rdi,rsi */
	X86_SIM_L_EXEC_CMOV(X86_RDI, X86_RSI, X86_WIDTH_64, X86_CC_E);
x86_l_7f1:
	/* 0x7f1: lea    rsi,[rdi+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_7f5:
	/* 0x7f5: test   edx,0xff1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_32, 65311ULL);
x86_l_7fb:
	/* 0x7fb: cmove  rsi,rdi */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RDI, X86_WIDTH_64, X86_CC_E);
x86_l_7ff:
	/* 0x7ff: mov    QWORD PTR [rsp+0x40],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_804:
	/* 0x804: movzx  esi,BYTE PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_808:
	/* 0x808: mov    edi,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_80a:
	/* 0x80a: mov    BYTE PTR [rsp+0x24],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_80e:
	/* 0x80e: mov    edx,DWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_811:
	/* 0x811: mov    DWORD PTR [rsp+0x18],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_815:
	/* 0x815: mov    eax,DWORD PTR [rax+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_818:
	/* 0x818: mov    DWORD PTR [rsp+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_81c:
	/* 0x81c: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_81f:
	/* 0x81f: je     82a <cil_to_netdev+0x82a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x81f, 0x82a, x86_l_82a);
x86_l_821:
	/* 0x821: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_824:
	/* 0x824: jne    156c <cil_to_netdev+0x156c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x824, 0x156c, x86_l_156c);
x86_l_82a:
	/* 0x82a: mov    DWORD PTR [rsp+0xc],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_82f:
	/* 0x82f: and    edi,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_832:
	/* 0x832: lea    ebp,[rsi+rdi*4] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_835:
	/* 0x835: lea    r12,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_83a:
	/* 0x83a: mov    rcx,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_ipv4_fragments)));
x86_l_841:
	/* 0x841: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_844:
	/* 0x844: je     90c <cil_to_netdev+0x90c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x844, 0x90c, x86_l_90c);
x86_l_84a:
	/* 0x84a: mov    DWORD PTR [rsp+0x68],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_84e:
	/* 0x84e: mov    DWORD PTR [rsp+0x6c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_852:
	/* 0x852: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_857:
	/* 0x857: mov    WORD PTR [rsp+0x70],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_85c:
	/* 0x85c: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_85f:
	/* 0x85f: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_863:
	/* 0x863: mov    BYTE PTR [rsp+0x72],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 114ULL);
x86_l_867:
	/* 0x867: mov    BYTE PTR [rsp+0x73],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 493921239040ULL);
x86_l_86c:
	/* 0x86c: test   rcx,r9 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_R9, X86_WIDTH_64);
x86_l_86f:
	/* 0x86f: jne    140f <cil_to_netdev+0x140f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x86f, 0x140f, x86_l_140f);
x86_l_875:
	/* 0x875: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_87a:
	/* 0x87a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_87d:
	/* 0x87d: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_87f:
	/* 0x87f: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_882:
	/* 0x882: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_887:
	/* 0x887: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_889:
	/* 0x889: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_88b:
	/* 0x88b: js     949 <cil_to_netdev+0x949> */
	X86_SIM_X86_JCC(X86_CC_S, 0x88b, 0x949, x86_l_949);
x86_l_891:
	/* 0x891: test   QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_896:
	/* 0x896: je     92f <cil_to_netdev+0x92f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x896, 0x92f, x86_l_92f);
x86_l_89c:
	/* 0x89c: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_8a1:
	/* 0x8a1: mov    rdi,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv4_frag_datagrams)));
x86_l_8a8:
	/* 0x8a8: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_8ad:
	/* 0x8ad: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_8b0:
	/* 0x8b0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8b2:
	/* 0x8b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8b4:
	/* 0x8b4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_8b6:
	/* 0x8b6: je     92f <cil_to_netdev+0x92f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8b6, 0x92f, x86_l_92f);
x86_l_8b8:
	/* 0x8b8: mov    r14d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_8bc:
	/* 0x8bc: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_8c5:
	/* 0x8c5: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_8ce:
	/* 0x8ce: movabs rax,0x6b0085020a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 459570217482ULL);
x86_l_8d8:
	/* 0x8d8: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_8dd:
	/* 0x8dd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_8e2:
	/* 0x8e2: mov    rdi,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_8e9:
	/* 0x8e9: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_8ee:
	/* 0x8ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8f0:
	/* 0x8f0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8f3:
	/* 0x8f3: je     145f <cil_to_netdev+0x145f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8f3, 0x145f, x86_l_145f);
x86_l_8f9:
	/* 0x8f9: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_8fc:
	/* 0x8fc: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_900:
	/* 0x900: jmp    92f <cil_to_netdev+0x92f> */
	X86_SIM_X86_JMP(0x900, 0x92f, x86_l_92f);
x86_l_902:
	/* 0x902: inc    QWORD PTR [r14] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_905:
	/* 0x905: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_907:
	/* 0x907: jmp    1641 <cil_to_netdev+0x1641> */
	X86_SIM_X86_JMP(0x907, 0x1641, x86_l_1641);
x86_l_90c:
	/* 0x90c: test   QWORD PTR [rsp+0x40],r9 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RSP, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_911:
	/* 0x911: jne    1432 <cil_to_netdev+0x1432> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x911, 0x1432, x86_l_1432);
x86_l_917:
	/* 0x917: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_91c:
	/* 0x91c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_91f:
	/* 0x91f: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_921:
	/* 0x921: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_924:
	/* 0x924: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_929:
	/* 0x929: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_92b:
	/* 0x92b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_92d:
	/* 0x92d: js     949 <cil_to_netdev+0x949> */
	X86_SIM_X86_JCC(X86_CC_S, 0x92d, 0x949, x86_l_949);
x86_l_92f:
	/* 0x92f: mov    QWORD PTR [rsp+0x58],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_934:
	/* 0x934: movzx  ebp,BYTE PTR [rsp+0x25] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 37ULL);
x86_l_939:
	/* 0x939: cmp    BYTE PTR [rsp+0x24],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 154618822662ULL);
x86_l_93e:
	/* 0x93e: jne    958 <cil_to_netdev+0x958> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x93e, 0x958, x86_l_958);
x86_l_940:
	/* 0x940: mov    rdi,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct4_global)));
x86_l_947:
	/* 0x947: jmp    95f <cil_to_netdev+0x95f> */
	X86_SIM_X86_JMP(0x947, 0x95f, x86_l_95f);
x86_l_949:
	/* 0x949: mov    ebp,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967161ULL);
x86_l_94e:
	/* 0x94e: mov    r12d,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_953:
	/* 0x953: jmp    1598 <cil_to_netdev+0x1598> */
	X86_SIM_X86_JMP(0x953, 0x1598, x86_l_1598);
x86_l_958:
	/* 0x958: mov    rdi,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct_any4_global)));
x86_l_95f:
	/* 0x95f: mov    r12d,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_964:
	/* 0x964: mov    BYTE PTR [rsp+0x25],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 158913789952ULL);
x86_l_969:
	/* 0x969: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_96e:
	/* 0x96e: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_973:
	/* 0x973: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_975:
	/* 0x975: mov    BYTE PTR [rsp+0x25],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 37ULL);
x86_l_97a:
	/* 0x97a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_97d:
	/* 0x97d: je     156c <cil_to_netdev+0x156c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x97d, 0x156c, x86_l_156c);
x86_l_983:
	/* 0x983: movzx  ecx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_987:
	/* 0x987: test   cl,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_98a:
	/* 0x98a: jne    9ad <cil_to_netdev+0x9ad> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x98a, 0x9ad, x86_l_9ad);
x86_l_98c:
	/* 0x98c: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_98e:
	/* 0x98e: jns    156c <cil_to_netdev+0x156c> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x98e, 0x156c, x86_l_156c);
x86_l_994:
	/* 0x994: movzx  edx,WORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 40ULL);
x86_l_998:
	/* 0x998: test   dx,dx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_16);
x86_l_99b:
	/* 0x99b: je     b9d <cil_to_netdev+0xb9d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x99b, 0xb9d, x86_l_b9d);
x86_l_9a1:
	/* 0x9a1: mov    ecx,DWORD PTR [rax+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_9a4:
	/* 0x9a4: mov    DWORD PTR [rsp+0x50],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_9a8:
	/* 0x9a8: jmp    be9 <cil_to_netdev+0xbe9> */
	X86_SIM_X86_JMP(0x9a8, 0xbe9, x86_l_be9);
x86_l_9ad:
	/* 0x9ad: movzx  eax,WORD PTR [rax+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_9b1:
	/* 0x9b1: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_9b4:
	/* 0x9b4: je     156c <cil_to_netdev+0x156c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9b4, 0x156c, x86_l_156c);
x86_l_9ba:
	/* 0x9ba: mov    WORD PTR [rsp+0x28],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_9bf:
	/* 0x9bf: mov    rax,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_9c6:
	/* 0x9c6: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_9c9:
	/* 0x9c9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_9ce:
	/* 0x9ce: mov    rdi,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_reverse_nat)));
x86_l_9d5:
	/* 0x9d5: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_9da:
	/* 0x9da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9dc:
	/* 0x9dc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9df:
	/* 0x9df: je     156c <cil_to_netdev+0x156c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9df, 0x156c, x86_l_156c);
x86_l_9e5:
	/* 0x9e5: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9e7:
	/* 0x9e7: mov    DWORD PTR [rsp+0x50],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_9eb:
	/* 0x9eb: movzx  eax,WORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_9ef:
	/* 0x9ef: mov    WORD PTR [rsp+0x54],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_9f4:
	/* 0x9f4: jmp    bee <cil_to_netdev+0xbee> */
	X86_SIM_X86_JMP(0x9f4, 0xbee, x86_l_bee);
x86_l_9f9:
	/* 0x9f9: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_9fe:
	/* 0x9fe: lea    esi,[r14+0x15] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 21ULL);
x86_l_a02:
	/* 0xa02: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_a07:
	/* 0xa07: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_a0a:
	/* 0xa0a: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_a0f:
	/* 0xa0f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a11:
	/* 0xa11: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a13:
	/* 0xa13: js     b91 <cil_to_netdev+0xb91> */
	X86_SIM_X86_JCC(X86_CC_S, 0xa13, 0xb91, x86_l_b91);
x86_l_a19:
	/* 0xa19: cmp    BYTE PTR [rsp+0x28],r12b */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a1e:
	/* 0xa1e: jne    a70 <cil_to_netdev+0xa70> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa1e, 0xa70, x86_l_a70);
x86_l_a20:
	/* 0xa20: movzx  eax,BYTE PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 24ULL);
x86_l_a25:
	/* 0xa25: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_a28:
	/* 0xa28: je     df7 <cil_to_netdev+0xdf7> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa28, 0xdf7, x86_l_df7);
x86_l_a2e:
	/* 0xa2e: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_a31:
	/* 0xa31: je     dca <cil_to_netdev+0xdca> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa31, 0xdca, x86_l_dca);
x86_l_a37:
	/* 0xa37: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_a3a:
	/* 0xa3a: jne    b91 <cil_to_netdev+0xb91> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa3a, 0xb91, x86_l_b91);
x86_l_a40:
	/* 0xa40: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_a45:
	/* 0xa45: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a4a:
	/* 0xa4a: add    esi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_a4d:
	/* 0xa4d: lea    rdx,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_a52:
	/* 0xa52: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_a55:
	/* 0xa55: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_a5a:
	/* 0xa5a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a5c:
	/* 0xa5c: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a5f:
	/* 0xa5f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a61:
	/* 0xa61: movbe  cx,WORD PTR [rsp+0x78] */
	X86_SIM_RUN_OP(X86_OP_MOVBE_LOAD, X86_RCX, X86_RSP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 120ULL);
x86_l_a68:
	/* 0xa68: movzx  ecx,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_a6b:
	/* 0xa6b: jmp    e1f <cil_to_netdev+0xe1f> */
	X86_SIM_X86_JMP(0xa6b, 0xe1f, x86_l_e1f);
x86_l_a70:
	/* 0xa70: movzx  eax,BYTE PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 24ULL);
x86_l_a75:
	/* 0xa75: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a7a:
	/* 0xa7a: add    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_a7c:
	/* 0xa7c: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_a7f:
	/* 0xa7f: add    r14d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_a82:
	/* 0xa82: add    r14d,0x14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 20ULL);
x86_l_a86:
	/* 0xa86: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a8b:
	/* 0xa8b: cmp    eax,r14d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R14, X86_WIDTH_32);
x86_l_a8e:
	/* 0xa8e: jae    b5b <cil_to_netdev+0xb5b> */
	X86_SIM_X86_JCC(X86_CC_AE, 0xa8e, 0xb5b, x86_l_b5b);
x86_l_a94:
	/* 0xa94: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_a99:
	/* 0xa99: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a9e:
	/* 0xa9e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_aa1:
	/* 0xaa1: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_aa6:
	/* 0xaa6: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_aab:
	/* 0xaab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aad:
	/* 0xaad: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_aaf:
	/* 0xaaf: js     b91 <cil_to_netdev+0xb91> */
	X86_SIM_X86_JCC(X86_CC_S, 0xaaf, 0xb91, x86_l_b91);
x86_l_ab5:
	/* 0xab5: movzx  eax,BYTE PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 40ULL);
x86_l_aba:
	/* 0xaba: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_abc:
	/* 0xabc: je     b5b <cil_to_netdev+0xb5b> */
	X86_SIM_X86_JCC(X86_CC_E, 0xabc, 0xb5b, x86_l_b5b);
x86_l_ac2:
	/* 0xac2: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ac5:
	/* 0xac5: je     afb <cil_to_netdev+0xafb> */
	X86_SIM_X86_JCC(X86_CC_E, 0xac5, 0xafb, x86_l_afb);
x86_l_ac7:
	/* 0xac7: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_acc:
	/* 0xacc: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ad1:
	/* 0xad1: lea    esi,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_ad4:
	/* 0xad4: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ad9:
	/* 0xad9: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_adc:
	/* 0xadc: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_ae1:
	/* 0xae1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ae3:
	/* 0xae3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ae5:
	/* 0xae5: js     b91 <cil_to_netdev+0xb91> */
	X86_SIM_X86_JCC(X86_CC_S, 0xae5, 0xb91, x86_l_b91);
x86_l_aeb:
	/* 0xaeb: cmp    BYTE PTR [rsp+0x28],r12b */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_af0:
	/* 0xaf0: je     a20 <cil_to_netdev+0xa20> */
	X86_SIM_X86_JCC(X86_CC_E, 0xaf0, 0xa20, x86_l_a20);
x86_l_af6:
	/* 0xaf6: movzx  eax,BYTE PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 24ULL);
x86_l_afb:
	/* 0xafb: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b00:
	/* 0xb00: add    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_b02:
	/* 0xb02: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b07:
	/* 0xb07: cmp    ecx,r14d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R14, X86_WIDTH_32);
x86_l_b0a:
	/* 0xb0a: jae    b5b <cil_to_netdev+0xb5b> */
	X86_SIM_X86_JCC(X86_CC_AE, 0xb0a, 0xb5b, x86_l_b5b);
x86_l_b0c:
	/* 0xb0c: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_b11:
	/* 0xb11: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b16:
	/* 0xb16: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_b19:
	/* 0xb19: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b1e:
	/* 0xb1e: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_b23:
	/* 0xb23: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b25:
	/* 0xb25: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b27:
	/* 0xb27: js     b91 <cil_to_netdev+0xb91> */
	X86_SIM_X86_JCC(X86_CC_S, 0xb27, 0xb91, x86_l_b91);
x86_l_b29:
	/* 0xb29: cmp    BYTE PTR [rsp+0x28],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691842ULL);
x86_l_b2e:
	/* 0xb2e: jb     b5b <cil_to_netdev+0xb5b> */
	X86_SIM_X86_JCC(X86_CC_B, 0xb2e, 0xb5b, x86_l_b5b);
x86_l_b30:
	/* 0xb30: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_b35:
	/* 0xb35: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b3a:
	/* 0xb3a: lea    esi,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_b3d:
	/* 0xb3d: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b42:
	/* 0xb42: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_b45:
	/* 0xb45: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_b4a:
	/* 0xb4a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b4c:
	/* 0xb4c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b4e:
	/* 0xb4e: js     b91 <cil_to_netdev+0xb91> */
	X86_SIM_X86_JCC(X86_CC_S, 0xb4e, 0xb91, x86_l_b91);
x86_l_b50:
	/* 0xb50: cmp    BYTE PTR [rsp+0x28],r12b */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b55:
	/* 0xb55: je     a20 <cil_to_netdev+0xa20> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb55, 0xa20, x86_l_a20);
x86_l_b5b:
	/* 0xb5b: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b5e:
	/* 0xb5e: mov    r13,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_b65:
	/* 0xb65: mov    DWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_b6d:
	/* 0xb6d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b72:
	/* 0xb72: mov    rdi,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_percpu_trace_id)));
x86_l_b79:
	/* 0xb79: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_b7e:
	/* 0xb7e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b80:
	/* 0xb80: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b83:
	/* 0xb83: je     105 <cil_to_netdev+0x105> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb83, 0x105, x86_l_105);
x86_l_b89:
	/* 0xb89: mov    QWORD PTR [rax],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b8c:
	/* 0xb8c: jmp    105 <cil_to_netdev+0x105> */
	X86_SIM_X86_JMP(0xb8c, 0x105, x86_l_105);
x86_l_b91:
	/* 0xb91: mov    r13,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_b98:
	/* 0xb98: jmp    de <cil_to_netdev+0xde> */
	X86_SIM_X86_JMP(0xb98, 0xde, x86_l_de);
x86_l_b9d:
	/* 0xb9d: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ba2:
	/* 0xba2: mov    rcx,QWORD PTR [rsp+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 29ULL);
x86_l_ba7:
	/* 0xba7: mov    QWORD PTR [rsp+0x2d],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 45ULL);
x86_l_bac:
	/* 0xbac: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_bb1:
	/* 0xbb1: mov    BYTE PTR [rsp+0x35],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 227633266688ULL);
x86_l_bb6:
	/* 0xbb6: rorx   eax,DWORD PTR [rsp+0x20],0x10 */
	X86_SIM_RUN_OP(X86_OP_RORX_MEM, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 137438953488ULL);
x86_l_bbe:
	/* 0xbbe: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_bc2:
	/* 0xbc2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_bc7:
	/* 0xbc7: mov    rdi,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_bce:
	/* 0xbce: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_bd3:
	/* 0xbd3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bd5:
	/* 0xbd5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_bd8:
	/* 0xbd8: je     156c <cil_to_netdev+0x156c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbd8, 0x156c, x86_l_156c);
x86_l_bde:
	/* 0xbde: mov    ecx,DWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_be1:
	/* 0xbe1: mov    DWORD PTR [rsp+0x50],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_be5:
	/* 0xbe5: movzx  edx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_be9:
	/* 0xbe9: mov    WORD PTR [rsp+0x54],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_bee:
	/* 0xbee: mov    r14b,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_8, 5ULL);
x86_l_bf1:
	/* 0xbf1: mov    BYTE PTR [rsp+0x78],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 515396075522ULL);
x86_l_bf6:
	/* 0xbf6: mov    rax,QWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_bfa:
	/* 0xbfa: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_bfd:
	/* 0xbfd: je     c07 <cil_to_netdev+0xc07> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbfd, 0xc07, x86_l_c07);
x86_l_bff:
	/* 0xbff: mov    eax,DWORD PTR [rax+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_c05:
	/* 0xc05: jmp    c09 <cil_to_netdev+0xc09> */
	X86_SIM_X86_JMP(0xc05, 0xc09, x86_l_c09);
x86_l_c07:
	/* 0xc07: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c09:
	/* 0xc09: mov    DWORD PTR [rsp+0x80],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_c10:
	/* 0xc10: mov    DWORD PTR [rsp+0x88],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_c17:
	/* 0xc17: mov    eax,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c1b:
	/* 0xc1b: mov    DWORD PTR [rsp+0x98],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_c22:
	/* 0xc22: mov    eax,0x45 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 69ULL);
x86_l_c27:
	/* 0xc27: mov    rcx,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_supports_fib_lookup_skip_neigh)));
x86_l_c2e:
	/* 0xc2e: movzx  ecx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_c31:
	/* 0xc31: shl    ecx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 2ULL);
x86_l_c34:
	/* 0xc34: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_c39:
	/* 0xc39: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_c3c:
	/* 0xc3c: mov    edx,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 64ULL);
x86_l_c41:
	/* 0xc41: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c43:
	/* 0xc43: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_c46:
	/* 0xc46: je     c50 <cil_to_netdev+0xc50> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc46, 0xc50, x86_l_c50);
x86_l_c48:
	/* 0xc48: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c4a:
	/* 0xc4a: jne    cda <cil_to_netdev+0xcda> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xc4a, 0xcda, x86_l_cda);
x86_l_c50:
	/* 0xc50: mov    r12d,DWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_c58:
	/* 0xc58: mov    rax,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_interface_ifindex)));
x86_l_c5f:
	/* 0xc5f: cmp    r12d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_c62:
	/* 0xc62: je     d29 <cil_to_netdev+0xd29> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc62, 0xd29, x86_l_d29);
x86_l_c68:
	/* 0xc68: mov    DWORD PTR [rsp+0x28],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c6d:
	/* 0xc6d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c72:
	/* 0xc72: mov    rdi,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_devices)));
x86_l_c79:
	/* 0xc79: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c7e:
	/* 0xc7e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c80:
	/* 0xc80: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c83:
	/* 0xc83: je     c8b <cil_to_netdev+0xc8b> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc83, 0xc8b, x86_l_c8b);
x86_l_c85:
	/* 0xc85: test   BYTE PTR [rax+0x8],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_c89:
	/* 0xc89: jne    cf0 <cil_to_netdev+0xcf0> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xc89, 0xcf0, x86_l_cf0);
x86_l_c8b:
	/* 0xc8b: mov    rax,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_c92:
	/* 0xc92: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c95:
	/* 0xc95: je     e37 <cil_to_netdev+0xe37> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc95, 0xe37, x86_l_e37);
x86_l_c9b:
	/* 0xc9b: lea    rax,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_ca3:
	/* 0xca3: movzx  ecx,BYTE PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 120ULL);
x86_l_ca8:
	/* 0xca8: mov    DWORD PTR [rsp+0x28],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_cac:
	/* 0xcac: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_caf:
	/* 0xcaf: mov    rax,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cb3:
	/* 0xcb3: mov    QWORD PTR [rsp+0x2c],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_cb8:
	/* 0xcb8: mov    QWORD PTR [rsp+0x34],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_cbd:
	/* 0xcbd: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_cc2:
	/* 0xcc2: mov    eax,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 152ULL);
x86_l_cc7:
	/* 0xcc7: mov    edi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_32);
x86_l_cca:
	/* 0xcca: mov    edx,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 20ULL);
x86_l_ccf:
	/* 0xccf: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_cd1:
	/* 0xcd1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cd3:
	/* 0xcd3: mov    ebp,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_cd5:
	/* 0xcd5: mov    r14b,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_8, 5ULL);
x86_l_cd8:
	/* 0xcd8: jmp    cfe <cil_to_netdev+0xcfe> */
	X86_SIM_X86_JMP(0xcd8, 0xcfe, x86_l_cfe);
x86_l_cda:
	/* 0xcda: shl    eax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_cdd:
	/* 0xcdd: movzx  r14d,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_ce1:
	/* 0xce1: mov    ebp,0xffffff57 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967127ULL);
x86_l_ce6:
	/* 0xce6: mov    r12d,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_ceb:
	/* 0xceb: jmp    1598 <cil_to_netdev+0x1598> */
	X86_SIM_X86_JMP(0xceb, 0x1598, x86_l_1598);
x86_l_cf0:
	/* 0xcf0: mov    eax,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 23ULL);
x86_l_cf5:
	/* 0xcf5: mov    edi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_32);
x86_l_cf8:
	/* 0xcf8: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_cfa:
	/* 0xcfa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cfc:
	/* 0xcfc: mov    ebp,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_cfe:
	/* 0xcfe: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_d00:
	/* 0xd00: je     d29 <cil_to_netdev+0xd29> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd00, 0xd29, x86_l_d29);
x86_l_d02:
	/* 0xd02: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_d0a:
	/* 0xd0a: mov    eax,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_d0f:
	/* 0xd0f: cmp    ebp,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 7ULL);
x86_l_d12:
	/* 0xd12: mov    r13,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_d19:
	/* 0xd19: mov    r12d,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_d1e:
	/* 0xd1e: jne    2f5 <cil_to_netdev+0x2f5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xd1e, 0x2f5, x86_l_2f5);
x86_l_d24:
	/* 0xd24: jmp    1641 <cil_to_netdev+0x1641> */
	X86_SIM_X86_JMP(0xd24, 0x1641, x86_l_1641);
x86_l_d29:
	/* 0xd29: movzx  eax,BYTE PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 36ULL);
x86_l_d2e:
	/* 0xd2e: mov    BYTE PTR [rsp+0x3c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_d32:
	/* 0xd32: cmp    al,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 6ULL);
x86_l_d34:
	/* 0xd34: jne    d3f <cil_to_netdev+0xd3f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xd34, 0xd3f, x86_l_d3f);
x86_l_d36:
	/* 0xd36: mov    r12,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&cilium_ct4_global)));
x86_l_d3d:
	/* 0xd3d: jmp    d46 <cil_to_netdev+0xd46> */
	X86_SIM_X86_JMP(0xd3d, 0xd46, x86_l_d46);
x86_l_d3f:
	/* 0xd3f: mov    r12,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&cilium_ct_any4_global)));
x86_l_d46:
	/* 0xd46: mov    rbp,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_d4b:
	/* 0xd4b: movabs r14,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 2199023255552ULL);
x86_l_d55:
	/* 0xd55: mov    BYTE PTR [rsp+0x25],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 158913789952ULL);
x86_l_d5a:
	/* 0xd5a: mov    DWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_d62:
	/* 0xd62: mov    rax,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_ipv4_fragments)));
x86_l_d69:
	/* 0xd69: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d6c:
	/* 0xd6c: je     ec4 <cil_to_netdev+0xec4> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd6c, 0xec4, x86_l_ec4);
x86_l_d72:
	/* 0xd72: and    r13,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 64ULL);
x86_l_d77:
	/* 0xd77: je     ec4 <cil_to_netdev+0xec4> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd77, 0xec4, x86_l_ec4);
x86_l_d7d:
	/* 0xd7d: mov    r13d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_d81:
	/* 0xd81: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_d8a:
	/* 0xd8a: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_d93:
	/* 0xd93: movabs rax,0x6c03a50109 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 463917613321ULL);
x86_l_d9d:
	/* 0xd9d: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_da2:
	/* 0xda2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_da7:
	/* 0xda7: mov    rdi,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_dae:
	/* 0xdae: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_db3:
	/* 0xdb3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_db5:
	/* 0xdb5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_db8:
	/* 0xdb8: je     e9c <cil_to_netdev+0xe9c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xdb8, 0xe9c, x86_l_e9c);
x86_l_dbe:
	/* 0xdbe: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_dc1:
	/* 0xdc1: add    QWORD PTR [rax+0x8],r13 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_dc5:
	/* 0xdc5: jmp    ec4 <cil_to_netdev+0xec4> */
	X86_SIM_X86_JMP(0xdc5, 0xec4, x86_l_ec4);
x86_l_dca:
	/* 0xdca: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_dcf:
	/* 0xdcf: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_dd4:
	/* 0xdd4: add    esi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_dd7:
	/* 0xdd7: lea    rdx,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_ddc:
	/* 0xddc: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_ddf:
	/* 0xddf: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_de4:
	/* 0xde4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_de6:
	/* 0xde6: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_de8:
	/* 0xde8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_dea:
	/* 0xdea: movbe  r14d,DWORD PTR [rsp+0x78] */
	X86_SIM_RUN_OP(X86_OP_MOVBE_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 120ULL);
x86_l_df1:
	/* 0xdf1: cmovs  r14d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R14, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_df5:
	/* 0xdf5: jmp    e23 <cil_to_netdev+0xe23> */
	X86_SIM_X86_JMP(0xdf5, 0xe23, x86_l_e23);
x86_l_df7:
	/* 0xdf7: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_dfc:
	/* 0xdfc: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e01:
	/* 0xe01: add    esi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_e04:
	/* 0xe04: lea    rdx,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_e09:
	/* 0xe09: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_e0c:
	/* 0xe0c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_e11:
	/* 0xe11: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e13:
	/* 0xe13: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e16:
	/* 0xe16: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_e18:
	/* 0xe18: movbe  rcx,QWORD PTR [rsp+0x78] */
	X86_SIM_RUN_OP(X86_OP_MOVBE_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 120ULL);
x86_l_e1f:
	/* 0xe1f: cmovns r14,rcx */
	X86_SIM_L_EXEC_CMOV(X86_R14, X86_RCX, X86_WIDTH_64, X86_CC_NS);
x86_l_e23:
	/* 0xe23: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_e25:
	/* 0xe25: mov    r13,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_e2c:
	/* 0xe2c: jns    b65 <cil_to_netdev+0xb65> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xe2c, 0xb65, x86_l_b65);
x86_l_e32:
	/* 0xe32: jmp    de <cil_to_netdev+0xde> */
	X86_SIM_X86_JMP(0xe32, 0xde, x86_l_de);
x86_l_e37:
	/* 0xe37: movzx  eax,WORD PTR [rbx+0xb4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 180ULL);
x86_l_e3e:
	/* 0xe3e: mov    WORD PTR [rsp+0x10],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e43:
	/* 0xe43: mov    eax,0x2b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_e48:
	/* 0xe48: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e4b:
	/* 0xe4b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_e4e:
	/* 0xe4e: mov    esi,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 14ULL);
x86_l_e53:
	/* 0xe53: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e55:
	/* 0xe55: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e57:
	/* 0xe57: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_e5c:
	/* 0xe5c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_e5e:
	/* 0xe5e: jne    ce6 <cil_to_netdev+0xce6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe5e, 0xce6, x86_l_ce6);
x86_l_e64:
	/* 0xe64: movzx  eax,WORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_e69:
	/* 0xe69: mov    WORD PTR [rsp+0x28],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_e6e:
	/* 0xe6e: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_e73:
	/* 0xe73: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_e78:
	/* 0xe78: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_e7b:
	/* 0xe7b: mov    esi,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 12ULL);
x86_l_e80:
	/* 0xe80: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_e85:
	/* 0xe85: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e88:
	/* 0xe88: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e8a:
	/* 0xe8a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_e8c:
	/* 0xe8c: jns    c9b <cil_to_netdev+0xc9b> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xe8c, 0xc9b, x86_l_c9b);
x86_l_e92:
	/* 0xe92: mov    ebp,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967155ULL);
x86_l_e97:
	/* 0xe97: jmp    ce6 <cil_to_netdev+0xce6> */
	X86_SIM_X86_JMP(0xe97, 0xce6, x86_l_ce6);
x86_l_e9c:
	/* 0xe9c: mov    QWORD PTR [rsp+0x28],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691841ULL);
x86_l_ea5:
	/* 0xea5: mov    QWORD PTR [rsp+0x30],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_eaa:
	/* 0xeaa: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_eaf:
	/* 0xeaf: mov    rdi,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_eb6:
	/* 0xeb6: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_ebb:
	/* 0xebb: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_ec0:
	/* 0xec0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ec2:
	/* 0xec2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ec4:
	/* 0xec4: cmp    BYTE PTR [rsp+0x3c],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 257698037766ULL);
x86_l_ec9:
	/* 0xec9: jne    f1e <cil_to_netdev+0xf1e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xec9, 0xf1e, x86_l_f1e);
x86_l_ecb:
	/* 0xecb: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_ed0:
	/* 0xed0: and    rax,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_ed3:
	/* 0xed3: jne    f1e <cil_to_netdev+0xf1e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xed3, 0xf1e, x86_l_f1e);
x86_l_ed5:
	/* 0xed5: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_eda:
	/* 0xeda: lea    esi,[rbp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_edd:
	/* 0xedd: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_ee2:
	/* 0xee2: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_ee5:
	/* 0xee5: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_eea:
	/* 0xeea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_eec:
	/* 0xeec: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_eee:
	/* 0xeee: js     f87 <cil_to_netdev+0xf87> */
	X86_SIM_X86_JCC(X86_CC_S, 0xeee, 0xf87, x86_l_f87);
x86_l_ef4:
	/* 0xef4: mov    r14d,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_ef9:
	/* 0xef9: mov    eax,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_32);
x86_l_efc:
	/* 0xefc: and    eax,0x1200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4608ULL);
x86_l_f01:
	/* 0xf01: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f04:
	/* 0xf04: cmp    eax,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 512ULL);
x86_l_f09:
	/* 0xf09: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_f0c:
	/* 0xf0c: test   r14d,0x500 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R14, X86_WIDTH_32, 1280ULL);
x86_l_f13:
	/* 0xf13: jne    148c <cil_to_netdev+0x148c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf13, 0x148c, x86_l_148c);
x86_l_f19:
	/* 0xf19: mov    r13b,al */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_8);
x86_l_f1c:
	/* 0xf1c: jmp    f26 <cil_to_netdev+0xf26> */
	X86_SIM_X86_JMP(0xf1c, 0xf26, x86_l_f26);
x86_l_f1e:
	/* 0xf1e: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f21:
	/* 0xf21: mov    r14d,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_f26:
	/* 0xf26: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f2b:
	/* 0xf2b: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_f30:
	/* 0xf30: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_f33:
	/* 0xf33: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f35:
	/* 0xf35: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f38:
	/* 0xf38: mov    r12d,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_f3d:
	/* 0xf3d: je     1563 <cil_to_netdev+0x1563> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf3d, 0x1563, x86_l_1563);
x86_l_f43:
	/* 0xf43: movzx  ecx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_f47:
	/* 0xf47: test   cl,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_f4a:
	/* 0xf4a: jne    f55 <cil_to_netdev+0xf55> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf4a, 0xf55, x86_l_f55);
x86_l_f4c:
	/* 0xf4c: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_f4e:
	/* 0xf4e: js     f67 <cil_to_netdev+0xf67> */
	X86_SIM_X86_JCC(X86_CC_S, 0xf4e, 0xf67, x86_l_f67);
x86_l_f50:
	/* 0xf50: jmp    1563 <cil_to_netdev+0x1563> */
	X86_SIM_X86_JMP(0xf50, 0x1563, x86_l_1563);
x86_l_f55:
	/* 0xf55: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_f57:
	/* 0xf57: and    edx,0x80 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 128ULL);
x86_l_f5d:
	/* 0xf5d: or     dx,WORD PTR [rax+0x26] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RAX, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 38ULL);
x86_l_f61:
	/* 0xf61: je     1563 <cil_to_netdev+0x1563> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf61, 0x1563, x86_l_1563);
x86_l_f67:
	/* 0xf67: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_f69:
	/* 0xf69: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_f6b:
	/* 0xf6b: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_f73:
	/* 0xf73: test   dl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_8, 3ULL);
x86_l_f76:
	/* 0xf76: jne    f91 <cil_to_netdev+0xf91> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf76, 0xf91, x86_l_f91);
x86_l_f78:
	/* 0xf78: movabs r8,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_64, 2199023255552ULL);
x86_l_f82:
	/* 0xf82: jmp    10a7 <cil_to_netdev+0x10a7> */
	X86_SIM_X86_JMP(0xf82, 0x10a7, x86_l_10a7);
x86_l_f87:
	/* 0xf87: mov    r12d,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_f8c:
	/* 0xf8c: jmp    156c <cil_to_netdev+0x156c> */
	X86_SIM_X86_JMP(0xf8c, 0x156c, x86_l_156c);
x86_l_f91:
	/* 0xf91: mov    rsi,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_f98:
	/* 0xf98: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f9b:
	/* 0xf9b: je     fae <cil_to_netdev+0xfae> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf9b, 0xfae, x86_l_fae);
x86_l_f9d:
	/* 0xf9d: mov    rdx,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_fa4:
	/* 0xfa4: imul   r12d,DWORD PTR [rdx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R12, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_fa8:
	/* 0xfa8: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_fac:
	/* 0xfac: jmp    fb4 <cil_to_netdev+0xfb4> */
	X86_SIM_X86_JMP(0xfac, 0xfb4, x86_l_fb4);
x86_l_fae:
	/* 0xfae: mov    r12d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 60ULL);
x86_l_fb4:
	/* 0xfb4: cmp    BYTE PTR [rsp+0x3c],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 257698037766ULL);
x86_l_fb9:
	/* 0xfb9: jne    ff2 <cil_to_netdev+0xff2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xfb9, 0xff2, x86_l_ff2);
x86_l_fbb:
	/* 0xfbb: mov    edx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_32);
x86_l_fbe:
	/* 0xfbe: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_fc0:
	/* 0xfc0: shr    edx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_fc3:
	/* 0xfc3: and    edx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_fc6:
	/* 0xfc6: or     edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_fc8:
	/* 0xfc8: mov    WORD PTR [rax+0x24],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_fcc:
	/* 0xfcc: test   dl,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_8, 16ULL);
x86_l_fcf:
	/* 0xfcf: mov    ecx,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 60ULL);
x86_l_fd4:
	/* 0xfd4: mov    r12d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 21600ULL);
x86_l_fda:
	/* 0xfda: cmove  r12d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RCX, X86_WIDTH_32, X86_CC_E);
x86_l_fde:
	/* 0xfde: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fe1:
	/* 0xfe1: je     ff2 <cil_to_netdev+0xff2> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfe1, 0xff2, x86_l_ff2);
x86_l_fe3:
	/* 0xfe3: mov    rcx,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_fea:
	/* 0xfea: imul   r12d,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_fee:
	/* 0xfee: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_ff2:
	/* 0xff2: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_ffa:
	/* 0xffa: mov    ebp,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R14, X86_WIDTH_32);
x86_l_ffd:
	/* 0xffd: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1000:
	/* 0x1000: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1003:
	/* 0x1003: je     1017 <cil_to_netdev+0x1017> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1003, 0x1017, x86_l_1017);
x86_l_1005:
	/* 0x1005: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_100a:
	/* 0x100a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_100c:
	/* 0x100c: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_100e:
	/* 0x100e: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1011:
	/* 0x1011: shr    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_1015:
	/* 0x1015: jmp    103a <cil_to_netdev+0x103a> */
	X86_SIM_X86_JMP(0x1015, 0x103a, x86_l_103a);
x86_l_1017:
	/* 0x1017: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_101c:
	/* 0x101c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_101e:
	/* 0x101e: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1020:
	/* 0x1020: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1024:
	/* 0x1024: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_102e:
	/* 0x102e: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1031:
	/* 0x1031: mulx   rcx,rcx,rcx */
	X86_SIM_L_EXEC_MULX(X86_RCX, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_1036:
	/* 0x1036: shr    rcx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_103a:
	/* 0x103a: add    r12d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_103d:
	/* 0x103d: mov    rax,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1045:
	/* 0x1045: mov    DWORD PTR [rax+0x20],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1049:
	/* 0x1049: movzx  edx,BYTE PTR [rax+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_104d:
	/* 0x104d: mov    esi,DWORD PTR [rax+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1050:
	/* 0x1050: and    bpl,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_1054:
	/* 0x1054: mov    rdi,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_105b:
	/* 0x105b: cmp    BYTE PTR [rdi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_105e:
	/* 0x105e: movabs r8,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_64, 2199023255552ULL);
x86_l_1068:
	/* 0x1068: je     107b <cil_to_netdev+0x107b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1068, 0x107b, x86_l_107b);
x86_l_106a:
	/* 0x106a: mov    rdi,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1071:
	/* 0x1071: mov    edi,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1073:
	/* 0x1073: lea    edi,[rdi+rdi*4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_1076:
	/* 0x1076: shr    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1079:
	/* 0x1079: jmp    1080 <cil_to_netdev+0x1080> */
	X86_SIM_X86_JMP(0x1079, 0x1080, x86_l_1080);
x86_l_107b:
	/* 0x107b: mov    edi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 5ULL);
x86_l_1080:
	/* 0x1080: mov    r12d,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1085:
	/* 0x1085: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1087:
	/* 0x1087: or     bpl,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_108a:
	/* 0x108a: cmp    edi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RCX, X86_WIDTH_32);
x86_l_108c:
	/* 0x108c: jb     1093 <cil_to_netdev+0x1093> */
	X86_SIM_X86_JCC(X86_CC_B, 0x108c, 0x1093, x86_l_1093);
x86_l_108e:
	/* 0x108e: cmp    dl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBP, X86_WIDTH_8);
x86_l_1091:
	/* 0x1091: je     10a7 <cil_to_netdev+0x10a7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1091, 0x10a7, x86_l_10a7);
x86_l_1093:
	/* 0x1093: mov    BYTE PTR [rax+0x2b],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_1097:
	/* 0x1097: mov    DWORD PTR [rax+0x34],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_109a:
	/* 0x109a: mov    rcx,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_10a1:
	/* 0x10a1: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10a3:
	/* 0x10a3: mov    DWORD PTR [rsp+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10a7:
	/* 0x10a7: mov    rcx,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_10ae:
	/* 0x10ae: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10b1:
	/* 0x10b1: je     10c0 <cil_to_netdev+0x10c0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10b1, 0x10c0, x86_l_10c0);
x86_l_10b3:
	/* 0x10b3: inc QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 16ULL);
x86_l_10b8:
	/* 0x10b8: mov    ecx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_10bb:
	/* 0x10bb: add QWORD PTR [rax+0x18],rcx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_10c0:
	/* 0x10c0: cmp    r13d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 2ULL);
x86_l_10c4:
	/* 0x10c4: je     1114 <cil_to_netdev+0x1114> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10c4, 0x1114, x86_l_1114);
x86_l_10c6:
	/* 0x10c6: cmp    r13d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 1ULL);
x86_l_10ca:
	/* 0x10ca: jne    120c <cil_to_netdev+0x120c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x10ca, 0x120c, x86_l_120c);
x86_l_10d0:
	/* 0x10d0: movzx  ecx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_10d4:
	/* 0x10d4: test   cl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_10d7:
	/* 0x10d7: je     120c <cil_to_netdev+0x120c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10d7, 0x120c, x86_l_120c);
x86_l_10dd:
	/* 0x10dd: mov    WORD PTR [rax+0x2a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 180388626432ULL);
x86_l_10e3:
	/* 0x10e3: and    ecx,0xffec */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 65516ULL);
x86_l_10e9:
	/* 0x10e9: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_10ec:
	/* 0x10ec: mov    WORD PTR [rax+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_10f0:
	/* 0x10f0: mov    r12,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_10f7:
	/* 0x10f7: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10fc:
	/* 0x10fc: je     1497 <cil_to_netdev+0x1497> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10fc, 0x1497, x86_l_1497);
x86_l_1102:
	/* 0x1102: mov    rax,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1109:
	/* 0x1109: imul   ebp,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_110c:
	/* 0x110c: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_110f:
	/* 0x110f: jmp    149c <cil_to_netdev+0x149c> */
	X86_SIM_X86_JMP(0x110f, 0x149c, x86_l_149c);
x86_l_1114:
	/* 0x1114: mov    ecx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_32);
x86_l_1117:
	/* 0x1117: shr    ecx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_111a:
	/* 0x111a: and    ecx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2ULL);
x86_l_111d:
	/* 0x111d: or     cx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RAX, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 36ULL);
x86_l_1121:
	/* 0x1121: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_1123:
	/* 0x1123: or     edx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_OR, 1ULL);
x86_l_1126:
	/* 0x1126: mov    WORD PTR [rax+0x24],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_112a:
	/* 0x112a: mov    rdx,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_1131:
	/* 0x1131: mov    edx,DWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1133:
	/* 0x1133: mov    DWORD PTR [rsp+0x10],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1137:
	/* 0x1137: test   cl,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_113a:
	/* 0x113a: je     120c <cil_to_netdev+0x120c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x113a, 0x120c, x86_l_120c);
x86_l_1140:
	/* 0x1140: mov    r13d,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R14, X86_WIDTH_32);
x86_l_1143:
	/* 0x1143: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1146:
	/* 0x1146: mov    r14,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_114d:
	/* 0x114d: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1151:
	/* 0x1151: je     1166 <cil_to_netdev+0x1166> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1151, 0x1166, x86_l_1166);
x86_l_1153:
	/* 0x1153: mov    rax,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_115a:
	/* 0x115a: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_115c:
	/* 0x115c: add    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_115e:
	/* 0x115e: lea    ebp,[rax+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_1161:
	/* 0x1161: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1164:
	/* 0x1164: jmp    116b <cil_to_netdev+0x116b> */
	X86_SIM_X86_JMP(0x1164, 0x116b, x86_l_116b);
x86_l_1166:
	/* 0x1166: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_116b:
	/* 0x116b: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_116f:
	/* 0x116f: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1173:
	/* 0x1173: je     1184 <cil_to_netdev+0x1184> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1173, 0x1184, x86_l_1184);
x86_l_1175:
	/* 0x1175: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_117a:
	/* 0x117a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_117c:
	/* 0x117c: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_117e:
	/* 0x117e: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_1182:
	/* 0x1182: jmp    11a7 <cil_to_netdev+0x11a7> */
	X86_SIM_X86_JMP(0x1182, 0x11a7, x86_l_11a7);
x86_l_1184:
	/* 0x1184: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1189:
	/* 0x1189: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_118b:
	/* 0x118b: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_118d:
	/* 0x118d: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1191:
	/* 0x1191: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_119b:
	/* 0x119b: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_119e:
	/* 0x119e: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_11a3:
	/* 0x11a3: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_11a7:
	/* 0x11a7: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_11a9:
	/* 0x11a9: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_11ac:
	/* 0x11ac: mov    DWORD PTR [r12+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_11b1:
	/* 0x11b1: movzx  ecx,BYTE PTR [r12+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_11b7:
	/* 0x11b7: mov    edx,DWORD PTR [r12+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_11bc:
	/* 0x11bc: and    r13b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_11c0:
	/* 0x11c0: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11c4:
	/* 0x11c4: je     11d7 <cil_to_netdev+0x11d7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11c4, 0x11d7, x86_l_11d7);
x86_l_11c6:
	/* 0x11c6: mov    rsi,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_11cd:
	/* 0x11cd: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11cf:
	/* 0x11cf: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_11d2:
	/* 0x11d2: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_11d5:
	/* 0x11d5: jmp    11dc <cil_to_netdev+0x11dc> */
	X86_SIM_X86_JMP(0x11d5, 0x11dc, x86_l_11dc);
x86_l_11d7:
	/* 0x11d7: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_11dc:
	/* 0x11dc: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_11de:
	/* 0x11de: or     r13b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_11e1:
	/* 0x11e1: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_11e3:
	/* 0x11e3: jb     11ea <cil_to_netdev+0x11ea> */
	X86_SIM_X86_JCC(X86_CC_B, 0x11e3, 0x11ea, x86_l_11ea);
x86_l_11e5:
	/* 0x11e5: cmp    cl,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R13, X86_WIDTH_8);
x86_l_11e8:
	/* 0x11e8: je     11fd <cil_to_netdev+0x11fd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11e8, 0x11fd, x86_l_11fd);
x86_l_11ea:
	/* 0x11ea: mov    BYTE PTR [r12+0x2b],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_11ef:
	/* 0x11ef: mov    DWORD PTR [r12+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_11f4:
	/* 0x11f4: mov    rax,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_11fb:
	/* 0x11fb: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11fd:
	/* 0x11fd: mov    r12d,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1202:
	/* 0x1202: movabs r8,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_64, 2199023255552ULL);
x86_l_120c:
	/* 0x120c: test   BYTE PTR [rsp+0x25],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 158913789954ULL);
x86_l_1211:
	/* 0x1211: jne    156c <cil_to_netdev+0x156c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1211, 0x156c, x86_l_156c);
x86_l_1217:
	/* 0x1217: mov    r13,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R8, X86_WIDTH_64);
x86_l_121a:
	/* 0x121a: mov    r12d,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_121f:
	/* 0x121f: mov    rax,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_1226:
	/* 0x1226: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1229:
	/* 0x1229: mov    eax,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_122d:
	/* 0x122d: mov    DWORD PTR [rsp+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1231:
	/* 0x1231: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_1236:
	/* 0x1236: mov    rcx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_123b:
	/* 0x123b: lea    esi,[rcx+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_123e:
	/* 0x123e: lea    rdx,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1243:
	/* 0x1243: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1246:
	/* 0x1246: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1249:
	/* 0x1249: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_124e:
	/* 0x124e: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1251:
	/* 0x1251: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1253:
	/* 0x1253: mov    ebp,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967155ULL);
x86_l_1258:
	/* 0x1258: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_125a:
	/* 0x125a: js     ce6 <cil_to_netdev+0xce6> */
	X86_SIM_X86_JCC(X86_CC_S, 0x125a, 0xce6, x86_l_ce6);
x86_l_1260:
	/* 0x1260: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1263:
	/* 0x1263: je     ce6 <cil_to_netdev+0xce6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1263, 0xce6, x86_l_ce6);
x86_l_1269:
	/* 0x1269: not    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_126c:
	/* 0x126c: add    r12d,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 80ULL);
x86_l_1271:
	/* 0x1271: adc    r12d,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_1275:
	/* 0x1275: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_127a:
	/* 0x127a: add    esi,0xa */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 10ULL);
x86_l_127d:
	/* 0x127d: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1280:
	/* 0x1280: mov    eax,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_1285:
	/* 0x1285: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1288:
	/* 0x1288: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_128a:
	/* 0x128a: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_128d:
	/* 0x128d: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1290:
	/* 0x1290: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1292:
	/* 0x1292: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1294:
	/* 0x1294: js     12bf <cil_to_netdev+0x12bf> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1294, 0x12bf, x86_l_12bf);
x86_l_1296:
	/* 0x1296: test   QWORD PTR [rsp+0x40],r13 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_129b:
	/* 0x129b: jne    13d4 <cil_to_netdev+0x13d4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x129b, 0x13d4, x86_l_13d4);
x86_l_12a1:
	/* 0x12a1: movzx  eax,BYTE PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 36ULL);
x86_l_12a6:
	/* 0x12a6: cmp    eax,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 58ULL);
x86_l_12a9:
	/* 0x12a9: je     12e5 <cil_to_netdev+0x12e5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12a9, 0x12e5, x86_l_12e5);
x86_l_12ab:
	/* 0x12ab: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_12ae:
	/* 0x12ae: je     12ce <cil_to_netdev+0x12ce> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12ae, 0x12ce, x86_l_12ce);
x86_l_12b0:
	/* 0x12b0: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_12b3:
	/* 0x12b3: jne    12f4 <cil_to_netdev+0x12f4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x12b3, 0x12f4, x86_l_12f4);
x86_l_12b5:
	/* 0x12b5: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12b8:
	/* 0x12b8: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_12bd:
	/* 0x12bd: jmp    12ed <cil_to_netdev+0x12ed> */
	X86_SIM_X86_JMP(0x12bd, 0x12ed, x86_l_12ed);
x86_l_12bf:
	/* 0x12bf: mov    ebp,0xffffff67 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967143ULL);
x86_l_12c4:
	/* 0x12c4: mov    r12d,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_12c9:
	/* 0x12c9: jmp    1598 <cil_to_netdev+0x1598> */
	X86_SIM_X86_JMP(0x12c9, 0x1598, x86_l_1598);
x86_l_12ce:
	/* 0x12ce: mov    DWORD PTR [rsp+0x48],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 309237645344ULL);
x86_l_12d6:
	/* 0x12d6: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_12db:
	/* 0x12db: mov    QWORD PTR [rsp+0x40],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_12e0:
	/* 0x12e0: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12e3:
	/* 0x12e3: jmp    1306 <cil_to_netdev+0x1306> */
	X86_SIM_X86_JMP(0x12e3, 0x1306, x86_l_1306);
x86_l_12e5:
	/* 0x12e5: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12e8:
	/* 0x12e8: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_12ed:
	/* 0x12ed: mov    QWORD PTR [rsp+0x40],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_12f2:
	/* 0x12f2: jmp    12fe <cil_to_netdev+0x12fe> */
	X86_SIM_X86_JMP(0x12f2, 0x12fe, x86_l_12fe);
x86_l_12f4:
	/* 0x12f4: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12f6:
	/* 0x12f6: mov    QWORD PTR [rsp+0x40],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_12fb:
	/* 0x12fb: mov    r13b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_8, 1ULL);
x86_l_12fe:
	/* 0x12fe: mov    DWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1306:
	/* 0x1306: movzx  ecx,WORD PTR [rsp+0x54] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 84ULL);
x86_l_130b:
	/* 0x130b: test   cx,cx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_16);
x86_l_130e:
	/* 0x130e: je     13a7 <cil_to_netdev+0x13a7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x130e, 0x13a7, x86_l_13a7);
x86_l_1314:
	/* 0x1314: movzx  edx,WORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_1319:
	/* 0x1319: mov    DWORD PTR [rsp+0x3c],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_131d:
	/* 0x131d: mov    ebp,0xffffff72 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967154ULL);
x86_l_1322:
	/* 0x1322: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1325:
	/* 0x1325: cmp    eax,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_1328:
	/* 0x1328: jg     1339 <cil_to_netdev+0x1339> */
	X86_SIM_X86_JCC(X86_CC_G, 0x1328, 0x1339, x86_l_1339);
x86_l_132a:
	/* 0x132a: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_132d:
	/* 0x132d: je     13a7 <cil_to_netdev+0x13a7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x132d, 0x13a7, x86_l_13a7);
x86_l_132f:
	/* 0x132f: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_1332:
	/* 0x1332: je     1347 <cil_to_netdev+0x1347> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1332, 0x1347, x86_l_1347);
x86_l_1334:
	/* 0x1334: jmp    ce6 <cil_to_netdev+0xce6> */
	X86_SIM_X86_JMP(0x1334, 0xce6, x86_l_ce6);
x86_l_1339:
	/* 0x1339: cmp    eax,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 58ULL);
x86_l_133c:
	/* 0x133c: je     13a7 <cil_to_netdev+0x13a7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x133c, 0x13a7, x86_l_13a7);
x86_l_133e:
	/* 0x133e: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_1341:
	/* 0x1341: jne    ce6 <cil_to_netdev+0xce6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1341, 0xce6, x86_l_ce6);
x86_l_1347:
	/* 0x1347: cmp    cx,WORD PTR [rsp+0x3c] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 60ULL);
x86_l_134c:
	/* 0x134c: je     13a7 <cil_to_netdev+0x13a7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x134c, 0x13a7, x86_l_13a7);
x86_l_134e:
	/* 0x134e: mov    WORD PTR [rsp+0x28],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1353:
	/* 0x1353: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_1358:
	/* 0x1358: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_135d:
	/* 0x135d: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1360:
	/* 0x1360: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1363:
	/* 0x1363: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1368:
	/* 0x1368: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_136d:
	/* 0x136d: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1370:
	/* 0x1370: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1372:
	/* 0x1372: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1374:
	/* 0x1374: js     1441 <cil_to_netdev+0x1441> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1374, 0x1441, x86_l_1441);
x86_l_137a:
	/* 0x137a: movzx  ecx,WORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 40ULL);
x86_l_137f:
	/* 0x137f: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1384:
	/* 0x1384: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1389:
	/* 0x1389: lea    esi,[rdx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_138c:
	/* 0x138c: mov    r8d,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1391:
	/* 0x1391: or     r8d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_1395:
	/* 0x1395: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_139a:
	/* 0x139a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_139d:
	/* 0x139d: mov    edx,DWORD PTR [rsp+0x3c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_13a1:
	/* 0x13a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13a3:
	/* 0x13a3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_13a5:
	/* 0x13a5: js     1400 <cil_to_netdev+0x1400> */
	X86_SIM_X86_JCC(X86_CC_S, 0x13a5, 0x1400, x86_l_1400);
x86_l_13a7:
	/* 0x13a7: test   r13b,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_8);
x86_l_13aa:
	/* 0x13aa: jne    13d4 <cil_to_netdev+0x13d4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x13aa, 0x13d4, x86_l_13d4);
x86_l_13ac:
	/* 0x13ac: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_13b1:
	/* 0x13b1: add    esi,DWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RSI, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 88ULL);
x86_l_13b5:
	/* 0x13b5: mov    r8d,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_13ba:
	/* 0x13ba: or     r8d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 16ULL);
x86_l_13be:
	/* 0x13be: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13c1:
	/* 0x13c1: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_13c6:
	/* 0x13c6: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_13c9:
	/* 0x13c9: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13cb:
	/* 0x13cb: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_13ce:
	/* 0x13ce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13d0:
	/* 0x13d0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_13d2:
	/* 0x13d2: js     1400 <cil_to_netdev+0x1400> */
	X86_SIM_X86_JCC(X86_CC_S, 0x13d2, 0x1400, x86_l_1400);
x86_l_13d4:
	/* 0x13d4: mov    eax,0xfffff0ff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294963455ULL);
x86_l_13d9:
	/* 0x13d9: and    eax,DWORD PTR [rbx+0xa8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 168ULL);
x86_l_13df:
	/* 0x13df: or     eax,0x300 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 768ULL);
x86_l_13e4:
	/* 0x13e4: mov    DWORD PTR [rbx+0xa8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_13ea:
	/* 0x13ea: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13ec:
	/* 0x13ec: mov    r14b,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_8, 2ULL);
x86_l_13ef:
	/* 0x13ef: mov    r13,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_13f6:
	/* 0x13f6: mov    r12d,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_13fb:
	/* 0x13fb: jmp    2f5 <cil_to_netdev+0x2f5> */
	X86_SIM_X86_JMP(0x13fb, 0x2f5, x86_l_2f5);
x86_l_1400:
	/* 0x1400: mov    ebp,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967142ULL);
x86_l_1405:
	/* 0x1405: mov    r12d,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_140a:
	/* 0x140a: jmp    1598 <cil_to_netdev+0x1598> */
	X86_SIM_X86_JMP(0x140a, 0x1598, x86_l_1598);
x86_l_140f:
	/* 0x140f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1414:
	/* 0x1414: mov    rdi,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv4_frag_datagrams)));
x86_l_141b:
	/* 0x141b: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1420:
	/* 0x1420: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1422:
	/* 0x1422: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1425:
	/* 0x1425: je     1450 <cil_to_netdev+0x1450> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1425, 0x1450, x86_l_1450);
x86_l_1427:
	/* 0x1427: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1429:
	/* 0x1429: mov    DWORD PTR [rsp+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_142d:
	/* 0x142d: jmp    92f <cil_to_netdev+0x92f> */
	X86_SIM_X86_JMP(0x142d, 0x92f, x86_l_92f);
x86_l_1432:
	/* 0x1432: mov    ebp,0xffffff63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967139ULL);
x86_l_1437:
	/* 0x1437: mov    r12d,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_143c:
	/* 0x143c: jmp    1598 <cil_to_netdev+0x1598> */
	X86_SIM_X86_JMP(0x143c, 0x1598, x86_l_1598);
x86_l_1441:
	/* 0x1441: mov    ebp,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967155ULL);
x86_l_1446:
	/* 0x1446: mov    r12d,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_144b:
	/* 0x144b: jmp    1598 <cil_to_netdev+0x1598> */
	X86_SIM_X86_JMP(0x144b, 0x1598, x86_l_1598);
x86_l_1450:
	/* 0x1450: mov    ebp,0xffffff51 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967121ULL);
x86_l_1455:
	/* 0x1455: mov    r12d,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_145a:
	/* 0x145a: jmp    1598 <cil_to_netdev+0x1598> */
	X86_SIM_X86_JMP(0x145a, 0x1598, x86_l_1598);
x86_l_145f:
	/* 0x145f: mov    QWORD PTR [rsp+0x28],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691841ULL);
x86_l_1468:
	/* 0x1468: mov    QWORD PTR [rsp+0x30],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_146d:
	/* 0x146d: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1472:
	/* 0x1472: mov    rdi,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1479:
	/* 0x1479: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_147e:
	/* 0x147e: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1483:
	/* 0x1483: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1485:
	/* 0x1485: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1487:
	/* 0x1487: jmp    92f <cil_to_netdev+0x92f> */
	X86_SIM_X86_JMP(0x1487, 0x92f, x86_l_92f);
x86_l_148c:
	/* 0x148c: mov    r13d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 2ULL);
x86_l_1492:
	/* 0x1492: jmp    f26 <cil_to_netdev+0xf26> */
	X86_SIM_X86_JMP(0x1492, 0xf26, x86_l_f26);
x86_l_1497:
	/* 0x1497: mov    ebp,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_149c:
	/* 0x149c: cmp    BYTE PTR [rsp+0x3c],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 257698037766ULL);
x86_l_14a1:
	/* 0x14a1: jne    14d8 <cil_to_netdev+0x14d8> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x14a1, 0x14d8, x86_l_14d8);
x86_l_14a3:
	/* 0x14a3: mov    eax,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_32);
x86_l_14a6:
	/* 0x14a6: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_14a8:
	/* 0x14a8: shr    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_14ab:
	/* 0x14ab: and    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_14ae:
	/* 0x14ae: or     ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_OR);
x86_l_14b0:
	/* 0x14b0: mov    WORD PTR [r15+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_14b5:
	/* 0x14b5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_14b7:
	/* 0x14b7: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_14bc:
	/* 0x14bc: mov    ebp,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 21600ULL);
x86_l_14c1:
	/* 0x14c1: cmove  ebp,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_14c4:
	/* 0x14c4: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14c9:
	/* 0x14c9: je     14d8 <cil_to_netdev+0x14d8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14c9, 0x14d8, x86_l_14d8);
x86_l_14cb:
	/* 0x14cb: mov    rax,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_14d2:
	/* 0x14d2: imul   ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_14d5:
	/* 0x14d5: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_14d8:
	/* 0x14d8: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_14dc:
	/* 0x14dc: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14e1:
	/* 0x14e1: je     14f2 <cil_to_netdev+0x14f2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14e1, 0x14f2, x86_l_14f2);
x86_l_14e3:
	/* 0x14e3: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_14e8:
	/* 0x14e8: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14ea:
	/* 0x14ea: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_14ec:
	/* 0x14ec: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_14f0:
	/* 0x14f0: jmp    1515 <cil_to_netdev+0x1515> */
	X86_SIM_X86_JMP(0x14f0, 0x1515, x86_l_1515);
x86_l_14f2:
	/* 0x14f2: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_14f7:
	/* 0x14f7: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14f9:
	/* 0x14f9: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_14fb:
	/* 0x14fb: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_14ff:
	/* 0x14ff: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_1509:
	/* 0x1509: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_150c:
	/* 0x150c: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1511:
	/* 0x1511: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_1515:
	/* 0x1515: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1517:
	/* 0x1517: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_151a:
	/* 0x151a: mov    DWORD PTR [r15+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_151e:
	/* 0x151e: movzx  ecx,BYTE PTR [r15+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_1523:
	/* 0x1523: mov    edx,DWORD PTR [r15+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1527:
	/* 0x1527: and    r14b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_152b:
	/* 0x152b: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1530:
	/* 0x1530: je     1543 <cil_to_netdev+0x1543> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1530, 0x1543, x86_l_1543);
x86_l_1532:
	/* 0x1532: mov    rsi,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1539:
	/* 0x1539: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_153b:
	/* 0x153b: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_153e:
	/* 0x153e: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1541:
	/* 0x1541: jmp    1548 <cil_to_netdev+0x1548> */
	X86_SIM_X86_JMP(0x1541, 0x1548, x86_l_1548);
x86_l_1543:
	/* 0x1543: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_1548:
	/* 0x1548: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_154a:
	/* 0x154a: or     r14b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_154d:
	/* 0x154d: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_154f:
	/* 0x154f: mov    r12d,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1554:
	/* 0x1554: jb     155b <cil_to_netdev+0x155b> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1554, 0x155b, x86_l_155b);
x86_l_1556:
	/* 0x1556: cmp    cl,r14b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R14, X86_WIDTH_8);
x86_l_1559:
	/* 0x1559: je     156c <cil_to_netdev+0x156c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1559, 0x156c, x86_l_156c);
x86_l_155b:
	/* 0x155b: mov    BYTE PTR [r15+0x2b],r14b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R14, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_155f:
	/* 0x155f: mov    DWORD PTR [r15+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1563:
	/* 0x1563: mov    rax,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_156a:
	/* 0x156a: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_156c:
	/* 0x156c: mov    DWORD PTR [rbx+0x2c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561024ULL);
x86_l_1573:
	/* 0x1573: mov    DWORD PTR [rbx+0x28],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1577:
	/* 0x1577: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_157c:
	/* 0x157c: mov    rsi,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_1583:
	/* 0x1583: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1586:
	/* 0x1586: mov    edx,0x26 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 38ULL);
x86_l_158b:
	/* 0x158b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_158d:
	/* 0x158d: mov    ebp,0xffffff74 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967156ULL);
x86_l_1592:
	/* 0x1592: mov    r14d,0x2600 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 9728ULL);
x86_l_1598:
	/* 0x1598: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_159a:
	/* 0x159a: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_159c:
	/* 0x159c: cmovs  eax,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RBP, X86_WIDTH_32, X86_CC_S);
x86_l_159f:
	/* 0x159f: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_15a2:
	/* 0x15a2: or     eax,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R14, X86_WIDTH_32, X86_ALU_OR);
x86_l_15a5:
	/* 0x15a5: mov    DWORD PTR [rbx+0x28],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_15a9:
	/* 0x15a9: mov    DWORD PTR [rbx+0x2c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561024ULL);
x86_l_15b0:
	/* 0x15b0: mov    DWORD PTR [rbx+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_15b3:
	/* 0x15b3: movabs rcx,0x5f9010200000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 430376347492155392ULL);
x86_l_15bd:
	/* 0x15bd: mov    QWORD PTR [rbx+0x34],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_15c1:
	/* 0x15c1: mov    r14d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_15c5:
	/* 0x15c5: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_15ca:
	/* 0x15ca: add    rcx,0x5f90201 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 100205057ULL);
x86_l_15d1:
	/* 0x15d1: mov    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_15d6:
	/* 0x15d6: mov    BYTE PTR [rsp+0x28],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_15da:
	/* 0x15da: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_15df:
	/* 0x15df: mov    rdi,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_15e6:
	/* 0x15e6: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_15eb:
	/* 0x15eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15ed:
	/* 0x15ed: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15f0:
	/* 0x15f0: je     15fb <cil_to_netdev+0x15fb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x15f0, 0x15fb, x86_l_15fb);
x86_l_15f2:
	/* 0x15f2: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_15f5:
	/* 0x15f5: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_15f9:
	/* 0x15f9: jmp    1626 <cil_to_netdev+0x1626> */
	X86_SIM_X86_JMP(0x15f9, 0x1626, x86_l_1626);
x86_l_15fb:
	/* 0x15fb: mov    QWORD PTR [rsp+0x78],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075521ULL);
x86_l_1604:
	/* 0x1604: mov    QWORD PTR [rsp+0x80],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_160c:
	/* 0x160c: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1611:
	/* 0x1611: mov    rdi,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1618:
	/* 0x1618: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_161d:
	/* 0x161d: lea    rdx,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1622:
	/* 0x1622: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1624:
	/* 0x1624: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1626:
	/* 0x1626: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_162b:
	/* 0x162b: mov    rsi,QWORD PTR [rip+0x1767] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_1632:
	/* 0x1632: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1635:
	/* 0x1635: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_163a:
	/* 0x163a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_163c:
	/* 0x163c: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1641:
	/* 0x1641: add    rsp,0xc8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 200ULL);
x86_l_1648:
	/* 0x1648: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_164a:
	/* 0x164a: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_164b:
	/* 0x164b: jmp    1658 <cil_to_netdev+0x1658> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_1650:
	/* 0x1650: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1653:
	/* 0x1653: jmp    1598 <cil_to_netdev+0x1598> */
	X86_SIM_X86_JMP(0x1653, 0x1598, x86_l_1598);
x86_l_1658:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
