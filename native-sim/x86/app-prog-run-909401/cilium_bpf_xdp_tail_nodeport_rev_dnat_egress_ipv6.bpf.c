extern char __config_debug_lb;
extern char __config_enable_conntrack_accounting;
extern char __config_enable_ipv6_fragments;
extern char __config_enable_jiffies;
extern char __config_hash_init6_seed;
extern char __config_kernel_hz;
extern char __config_supports_fib_lookup_src;
extern char __config_trace_payload_len;
extern char __config_tunnel_port;
extern char __config_tunnel_protocol;
extern char cilium_calls;
extern char cilium_ct6_global;
extern char cilium_ct_any6_global;
extern char cilium_devices;
extern char cilium_egress_gw_policy_v6;
extern char cilium_ipcache_v2;
extern char cilium_ipv6_frag_datagrams;
extern char cilium_lb6_reverse_nat;
extern char cilium_metrics;
extern char cilium_nodeport_neigh4;
extern char cilium_nodeport_neigh6;
extern char cilium_xdp_scratch;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int cilium_bpf_xdp_tail_nodeport_rev_dnat_egress_ipv6_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0xd8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 216ULL);
x86_l_a:
	/* 0xa: mov    rax,QWORD PTR [rip+0x25b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_11:
	/* 0x11: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13:
	/* 0x13: mov    QWORD PTR [rsp+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_1f:
	/* 0x1f: mov    DWORD PTR [rsp+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_2a:
	/* 0x2a: mov    QWORD PTR [rsp+0xc8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 858993459200ULL);
x86_l_36:
	/* 0x36: mov    QWORD PTR [rsp+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_42:
	/* 0x42: mov    QWORD PTR [rsp+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_4e:
	/* 0x4e: mov    QWORD PTR [rsp+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_5a:
	/* 0x5a: mov    QWORD PTR [rsp+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_66:
	/* 0x66: mov    QWORD PTR [rsp+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_72:
	/* 0x72: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_75:
	/* 0x75: mov    QWORD PTR [rsp+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_81:
	/* 0x81: mov    BYTE PTR [rsp+0x90],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 618475290634ULL);
x86_l_89:
	/* 0x89: mov    eax,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_8c:
	/* 0x8c: mov    DWORD PTR [rsp+0x98],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_93:
	/* 0x93: mov    WORD PTR [rsp+0x84],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 566935683072ULL);
x86_l_9d:
	/* 0x9d: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_a8:
	/* 0xa8: mov    r12,QWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ab:
	/* 0xab: mov    rax,QWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_af:
	/* 0xaf: lea    rdi,[r12+0x36] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_b4:
	/* 0xb4: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_b9:
	/* 0xb9: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bc:
	/* 0xbc: cmp    rdi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_bf:
	/* 0xbf: ja     1111 <tail_nodeport_rev_dnat_egress_ipv6+0x1111> */
	X86_SIM_X86_JCC(X86_CC_A, 0xbf, 0x1111, x86_l_1111);
x86_l_c5:
	/* 0xc5: movzx  r15d,BYTE PTR [r12+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 20ULL);
x86_l_cb:
	/* 0xcb: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ce:
	/* 0xce: mov    r13d,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 40ULL);
x86_l_d4:
	/* 0xd4: cmp    r15,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 60ULL);
x86_l_d8:
	/* 0xd8: ja     224 <tail_nodeport_rev_dnat_egress_ipv6+0x224> */
	X86_SIM_X86_JCC(X86_CC_A, 0xd8, 0x224, x86_l_224);
x86_l_de:
	/* 0xde: mov    ebp,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967140ULL);
x86_l_e3:
	/* 0xe3: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_ed:
	/* 0xed: bt     rcx,r15 */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_f1:
	/* 0xf1: jae    143 <tail_nodeport_rev_dnat_egress_ipv6+0x143> */
	X86_SIM_X86_JCC(X86_CC_AE, 0xf1, 0x143, x86_l_143);
x86_l_f3:
	/* 0xf3: lea    rdx,[r12+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_f8:
	/* 0xf8: cmp    rdx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_fb:
	/* 0xfb: ja     110c <tail_nodeport_rev_dnat_egress_ipv6+0x110c> */
	X86_SIM_X86_JCC(X86_CC_A, 0xfb, 0x110c, x86_l_110c);
x86_l_101:
	/* 0x101: movzx  edx,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_104:
	/* 0x104: mov    esi,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_106:
	/* 0x106: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_109:
	/* 0x109: cmp    r15d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 43ULL);
x86_l_10d:
	/* 0x10d: jle    11f <tail_nodeport_rev_dnat_egress_ipv6+0x11f> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x10d, 0x11f, x86_l_11f);
x86_l_10f:
	/* 0x10f: cmp    r15d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 44ULL);
x86_l_113:
	/* 0x113: je     158 <tail_nodeport_rev_dnat_egress_ipv6+0x158> */
	X86_SIM_X86_JCC(X86_CC_E, 0x113, 0x158, x86_l_158);
x86_l_115:
	/* 0x115: cmp    r15d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 60ULL);
x86_l_119:
	/* 0x119: jne    1bd <tail_nodeport_rev_dnat_egress_ipv6+0x1bd> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x119, 0x1bd, x86_l_1bd);
x86_l_11f:
	/* 0x11f: movzx  esi,si */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_122:
	/* 0x122: lea    esi,[rsi*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 3), 8ULL);
x86_l_129:
	/* 0x129: cmp    r15b,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_8, 44ULL);
x86_l_12d:
	/* 0x12d: jne    1c4 <tail_nodeport_rev_dnat_egress_ipv6+0x1c4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x12d, 0x1c4, x86_l_1c4);
x86_l_133:
	/* 0x133: lea    r8,[r12+0x3e] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 62ULL);
x86_l_138:
	/* 0x138: cmp    r8,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RAX, X86_WIDTH_64);
x86_l_13b:
	/* 0x13b: ja     110c <tail_nodeport_rev_dnat_egress_ipv6+0x110c> */
	X86_SIM_X86_JCC(X86_CC_A, 0x13b, 0x110c, x86_l_110c);
x86_l_141:
	/* 0x141: jmp    16b <tail_nodeport_rev_dnat_egress_ipv6+0x16b> */
	X86_SIM_X86_JMP(0x141, 0x16b, x86_l_16b);
x86_l_143:
	/* 0x143: mov    r10d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_32, 0ULL);
x86_l_149:
	/* 0x149: cmp    r15,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 59ULL);
x86_l_14d:
	/* 0x14d: je     1111 <tail_nodeport_rev_dnat_egress_ipv6+0x1111> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14d, 0x1111, x86_l_1111);
x86_l_153:
	/* 0x153: jmp    3da <tail_nodeport_rev_dnat_egress_ipv6+0x3da> */
	X86_SIM_X86_JMP(0x153, 0x3da, x86_l_3da);
x86_l_158:
	/* 0x158: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_15d:
	/* 0x15d: lea    r8,[r12+0x3e] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 62ULL);
x86_l_162:
	/* 0x162: cmp    r8,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RAX, X86_WIDTH_64);
x86_l_165:
	/* 0x165: ja     110c <tail_nodeport_rev_dnat_egress_ipv6+0x110c> */
	X86_SIM_X86_JCC(X86_CC_A, 0x165, 0x110c, x86_l_110c);
x86_l_16b:
	/* 0x16b: mov    rdi,QWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16e:
	/* 0x16e: rorx   r8,rdi,0x20 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_R8, X86_RDI, X86_WIDTH_64, 0, 32ULL);
x86_l_174:
	/* 0x174: shr    edi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_177:
	/* 0x177: mov    r9d,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 4294967295ULL);
x86_l_17d:
	/* 0x17d: movabs r10,0xff00000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_64, 1095216660480ULL);
x86_l_187:
	/* 0x187: or     r10,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R9, X86_WIDTH_64, X86_ALU_OR);
x86_l_18a:
	/* 0x18a: and    r8,r10 */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R10, X86_WIDTH_64, X86_ALU_AND);
x86_l_18d:
	/* 0x18d: movabs r9,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_64, 1099511627776ULL);
x86_l_197:
	/* 0x197: or     r9,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_64, X86_ALU_OR);
x86_l_19a:
	/* 0x19a: test   edi,0xf9ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDI, X86_WIDTH_32, 63999ULL);
x86_l_1a0:
	/* 0x1a0: cmove  r9,r8 */
	X86_SIM_L_EXEC_CMOV(X86_R9, X86_R8, X86_WIDTH_64, X86_CC_E);
x86_l_1a4:
	/* 0x1a4: movabs r10,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_64, 2199023255552ULL);
x86_l_1ae:
	/* 0x1ae: or     r10,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R9, X86_WIDTH_64, X86_ALU_OR);
x86_l_1b1:
	/* 0x1b1: test   edi,0xf8ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDI, X86_WIDTH_32, 63743ULL);
x86_l_1b7:
	/* 0x1b7: cmove  r10,r9 */
	X86_SIM_L_EXEC_CMOV(X86_R10, X86_R9, X86_WIDTH_64, X86_CC_E);
x86_l_1bb:
	/* 0x1bb: jmp    1c7 <tail_nodeport_rev_dnat_egress_ipv6+0x1c7> */
	X86_SIM_X86_JMP(0x1bb, 0x1c7, x86_l_1c7);
x86_l_1bd:
	/* 0x1bd: lea    esi,[rsi*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 8ULL);
x86_l_1c4:
	/* 0x1c4: xor    r10d,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R10, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c7:
	/* 0x1c7: lea    r13d,[rsi+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1cb:
	/* 0x1cb: cmp    dl,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_8, 60ULL);
x86_l_1ce:
	/* 0x1ce: ja     3c8 <tail_nodeport_rev_dnat_egress_ipv6+0x3c8> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1ce, 0x3c8, x86_l_3c8);
x86_l_1d4:
	/* 0x1d4: movzx  r8d,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1d8:
	/* 0x1d8: bt     rcx,r8 */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_R8, X86_WIDTH_64);
x86_l_1dc:
	/* 0x1dc: jae    22c <tail_nodeport_rev_dnat_egress_ipv6+0x22c> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x1dc, 0x22c, x86_l_22c);
x86_l_1de:
	/* 0x1de: add    esi,0x36 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 54ULL);
x86_l_1e1:
	/* 0x1e1: movzx  edi,sil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1e5:
	/* 0x1e5: lea    rsi,[r12+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_1e9:
	/* 0x1e9: add    rsi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_1ed:
	/* 0x1ed: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_1f0:
	/* 0x1f0: ja     110c <tail_nodeport_rev_dnat_egress_ipv6+0x110c> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1f0, 0x110c, x86_l_110c);
x86_l_1f6:
	/* 0x1f6: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1f9:
	/* 0x1f9: movzx  r15d,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1fd:
	/* 0x1fd: mov    esi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_200:
	/* 0x200: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_203:
	/* 0x203: cmp    r8d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 43ULL);
x86_l_207:
	/* 0x207: jle    23e <tail_nodeport_rev_dnat_egress_ipv6+0x23e> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x207, 0x23e, x86_l_23e);
x86_l_209:
	/* 0x209: cmp    r8d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 44ULL);
x86_l_20d:
	/* 0x20d: je     24c <tail_nodeport_rev_dnat_egress_ipv6+0x24c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x20d, 0x24c, x86_l_24c);
x86_l_20f:
	/* 0x20f: cmp    r8d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 51ULL);
x86_l_213:
	/* 0x213: jne    23e <tail_nodeport_rev_dnat_egress_ipv6+0x23e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x213, 0x23e, x86_l_23e);
x86_l_215:
	/* 0x215: movzx  edx,si */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RSI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_218:
	/* 0x218: lea    esi,[rdx*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 2), 8ULL);
x86_l_21f:
	/* 0x21f: jmp    2ae <tail_nodeport_rev_dnat_egress_ipv6+0x2ae> */
	X86_SIM_X86_JMP(0x21f, 0x2ae, x86_l_2ae);
x86_l_224:
	/* 0x224: xor    r10d,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R10, X86_WIDTH_32, X86_ALU_XOR);
x86_l_227:
	/* 0x227: jmp    3da <tail_nodeport_rev_dnat_egress_ipv6+0x3da> */
	X86_SIM_X86_JMP(0x227, 0x3da, x86_l_3da);
x86_l_22c:
	/* 0x22c: mov    r15d,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_32);
x86_l_22f:
	/* 0x22f: cmp    r8,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_64, 59ULL);
x86_l_233:
	/* 0x233: je     1111 <tail_nodeport_rev_dnat_egress_ipv6+0x1111> */
	X86_SIM_X86_JCC(X86_CC_E, 0x233, 0x1111, x86_l_1111);
x86_l_239:
	/* 0x239: jmp    3da <tail_nodeport_rev_dnat_egress_ipv6+0x3da> */
	X86_SIM_X86_JMP(0x239, 0x3da, x86_l_3da);
x86_l_23e:
	/* 0x23e: lea    esi,[rsi*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 3), 8ULL);
x86_l_245:
	/* 0x245: cmp    dl,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_8, 44ULL);
x86_l_248:
	/* 0x248: je     251 <tail_nodeport_rev_dnat_egress_ipv6+0x251> */
	X86_SIM_X86_JCC(X86_CC_E, 0x248, 0x251, x86_l_251);
x86_l_24a:
	/* 0x24a: jmp    2ae <tail_nodeport_rev_dnat_egress_ipv6+0x2ae> */
	X86_SIM_X86_JMP(0x24a, 0x2ae, x86_l_2ae);
x86_l_24c:
	/* 0x24c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_251:
	/* 0x251: lea    rdx,[rdi+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_255:
	/* 0x255: cmp    rdx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_258:
	/* 0x258: ja     110c <tail_nodeport_rev_dnat_egress_ipv6+0x110c> */
	X86_SIM_X86_JCC(X86_CC_A, 0x258, 0x110c, x86_l_110c);
x86_l_25e:
	/* 0x25e: mov    rdx,QWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_261:
	/* 0x261: rorx   rdi,rdx,0x20 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDI, X86_RDX, X86_WIDTH_64, 0, 32ULL);
x86_l_267:
	/* 0x267: shr    edx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_26a:
	/* 0x26a: mov    r8d,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 4294967295ULL);
x86_l_270:
	/* 0x270: movabs r9,0xff00000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_64, 1095216660480ULL);
x86_l_27a:
	/* 0x27a: or     r9,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_64, X86_ALU_OR);
x86_l_27d:
	/* 0x27d: and    rdi,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R9, X86_WIDTH_64, X86_ALU_AND);
x86_l_280:
	/* 0x280: movabs r8,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_64, 1099511627776ULL);
x86_l_28a:
	/* 0x28a: or     r8,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDI, X86_WIDTH_64, X86_ALU_OR);
x86_l_28d:
	/* 0x28d: test   edx,0xf9ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_32, 63999ULL);
x86_l_293:
	/* 0x293: cmove  r8,rdi */
	X86_SIM_L_EXEC_CMOV(X86_R8, X86_RDI, X86_WIDTH_64, X86_CC_E);
x86_l_297:
	/* 0x297: movabs r10,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_64, 2199023255552ULL);
x86_l_2a1:
	/* 0x2a1: or     r10,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R8, X86_WIDTH_64, X86_ALU_OR);
x86_l_2a4:
	/* 0x2a4: test   edx,0xf8ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_32, 63743ULL);
x86_l_2aa:
	/* 0x2aa: cmove  r10,r8 */
	X86_SIM_L_EXEC_CMOV(X86_R10, X86_R8, X86_WIDTH_64, X86_CC_E);
x86_l_2ae:
	/* 0x2ae: add    r13d,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2b1:
	/* 0x2b1: cmp    r15b,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_8, 60ULL);
x86_l_2b5:
	/* 0x2b5: ja     3da <tail_nodeport_rev_dnat_egress_ipv6+0x3da> */
	X86_SIM_X86_JCC(X86_CC_A, 0x2b5, 0x3da, x86_l_3da);
x86_l_2bb:
	/* 0x2bb: movzx  esi,r15b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_R15, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2bf:
	/* 0x2bf: bt     rcx,rsi */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RSI, X86_WIDTH_64);
x86_l_2c3:
	/* 0x2c3: jae    3d0 <tail_nodeport_rev_dnat_egress_ipv6+0x3d0> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x2c3, 0x3d0, x86_l_3d0);
x86_l_2c9:
	/* 0x2c9: lea    edx,[r13+0xe] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_2cd:
	/* 0x2cd: movzx  edi,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2d0:
	/* 0x2d0: lea    rdx,[r12+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_2d4:
	/* 0x2d4: add    rdx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_2d8:
	/* 0x2d8: cmp    rdx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2db:
	/* 0x2db: ja     110c <tail_nodeport_rev_dnat_egress_ipv6+0x110c> */
	X86_SIM_X86_JCC(X86_CC_A, 0x2db, 0x110c, x86_l_110c);
x86_l_2e1:
	/* 0x2e1: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2e4:
	/* 0x2e4: movzx  edx,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2e7:
	/* 0x2e7: mov    r8d,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RDX, X86_WIDTH_32);
x86_l_2ea:
	/* 0x2ea: shr    r8d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_2ee:
	/* 0x2ee: cmp    esi,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 43ULL);
x86_l_2f1:
	/* 0x2f1: jle    30a <tail_nodeport_rev_dnat_egress_ipv6+0x30a> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x2f1, 0x30a, x86_l_30a);
x86_l_2f3:
	/* 0x2f3: cmp    esi,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 44ULL);
x86_l_2f6:
	/* 0x2f6: je     31a <tail_nodeport_rev_dnat_egress_ipv6+0x31a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2f6, 0x31a, x86_l_31a);
x86_l_2f8:
	/* 0x2f8: cmp    esi,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 51ULL);
x86_l_2fb:
	/* 0x2fb: jne    30a <tail_nodeport_rev_dnat_egress_ipv6+0x30a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2fb, 0x30a, x86_l_30a);
x86_l_2fd:
	/* 0x2fd: movzx  esi,r8w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_R8, X86_WIDTH_32, X86_WIDTH_16);
x86_l_301:
	/* 0x301: lea    esi,[rsi*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 8ULL);
x86_l_308:
	/* 0x308: jmp    37c <tail_nodeport_rev_dnat_egress_ipv6+0x37c> */
	X86_SIM_X86_JMP(0x308, 0x37c, x86_l_37c);
x86_l_30a:
	/* 0x30a: lea    esi,[r8*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R8, 3), 8ULL);
x86_l_312:
	/* 0x312: cmp    r15b,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_8, 44ULL);
x86_l_316:
	/* 0x316: je     31f <tail_nodeport_rev_dnat_egress_ipv6+0x31f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x316, 0x31f, x86_l_31f);
x86_l_318:
	/* 0x318: jmp    37c <tail_nodeport_rev_dnat_egress_ipv6+0x37c> */
	X86_SIM_X86_JMP(0x318, 0x37c, x86_l_37c);
x86_l_31a:
	/* 0x31a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_31f:
	/* 0x31f: lea    r8,[rdi+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_323:
	/* 0x323: cmp    r8,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RAX, X86_WIDTH_64);
x86_l_326:
	/* 0x326: ja     110c <tail_nodeport_rev_dnat_egress_ipv6+0x110c> */
	X86_SIM_X86_JCC(X86_CC_A, 0x326, 0x110c, x86_l_110c);
x86_l_32c:
	/* 0x32c: mov    rdi,QWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32f:
	/* 0x32f: rorx   r8,rdi,0x20 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_R8, X86_RDI, X86_WIDTH_64, 0, 32ULL);
x86_l_335:
	/* 0x335: shr    edi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_338:
	/* 0x338: mov    r9d,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 4294967295ULL);
x86_l_33e:
	/* 0x33e: movabs r10,0xff00000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_64, 1095216660480ULL);
x86_l_348:
	/* 0x348: or     r10,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R9, X86_WIDTH_64, X86_ALU_OR);
x86_l_34b:
	/* 0x34b: and    r8,r10 */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R10, X86_WIDTH_64, X86_ALU_AND);
x86_l_34e:
	/* 0x34e: movabs r9,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_64, 1099511627776ULL);
x86_l_358:
	/* 0x358: or     r9,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_64, X86_ALU_OR);
x86_l_35b:
	/* 0x35b: test   edi,0xf9ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDI, X86_WIDTH_32, 63999ULL);
x86_l_361:
	/* 0x361: cmove  r9,r8 */
	X86_SIM_L_EXEC_CMOV(X86_R9, X86_R8, X86_WIDTH_64, X86_CC_E);
x86_l_365:
	/* 0x365: movabs r10,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_64, 2199023255552ULL);
x86_l_36f:
	/* 0x36f: or     r10,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R9, X86_WIDTH_64, X86_ALU_OR);
x86_l_372:
	/* 0x372: test   edi,0xf8ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDI, X86_WIDTH_32, 63743ULL);
x86_l_378:
	/* 0x378: cmove  r10,r9 */
	X86_SIM_L_EXEC_CMOV(X86_R10, X86_R9, X86_WIDTH_64, X86_CC_E);
x86_l_37c:
	/* 0x37c: add    r13d,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_37f:
	/* 0x37f: cmp    dl,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_8, 60ULL);
x86_l_382:
	/* 0x382: ja     3c8 <tail_nodeport_rev_dnat_egress_ipv6+0x3c8> */
	X86_SIM_X86_JCC(X86_CC_A, 0x382, 0x3c8, x86_l_3c8);
x86_l_384:
	/* 0x384: movzx  esi,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_387:
	/* 0x387: bt     rcx,rsi */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RSI, X86_WIDTH_64);
x86_l_38b:
	/* 0x38b: jae    3cd <tail_nodeport_rev_dnat_egress_ipv6+0x3cd> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x38b, 0x3cd, x86_l_3cd);
x86_l_38d:
	/* 0x38d: add    r13d,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 14ULL);
x86_l_391:
	/* 0x391: movzx  ecx,r13b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R13, X86_WIDTH_32, X86_WIDTH_8);
x86_l_395:
	/* 0x395: lea    rsi,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_399:
	/* 0x399: add    rsi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_39d:
	/* 0x39d: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_3a0:
	/* 0x3a0: ja     110c <tail_nodeport_rev_dnat_egress_ipv6+0x110c> */
	X86_SIM_X86_JCC(X86_CC_A, 0x3a0, 0x110c, x86_l_110c);
x86_l_3a6:
	/* 0x3a6: add    r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3a9:
	/* 0x3a9: add    r12,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3ad:
	/* 0x3ad: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_3b0:
	/* 0x3b0: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_3b5:
	/* 0x3b5: mov    eax,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967140ULL);
x86_l_3ba:
	/* 0x3ba: cmovbe ebp,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RAX, X86_WIDTH_32, X86_CC_BE);
x86_l_3bd:
	/* 0x3bd: cmp    dl,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_8, 44ULL);
x86_l_3c0:
	/* 0x3c0: cmovne ebp,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RAX, X86_WIDTH_32, X86_CC_NE);
x86_l_3c3:
	/* 0x3c3: jmp    1111 <tail_nodeport_rev_dnat_egress_ipv6+0x1111> */
	X86_SIM_X86_JMP(0x3c3, 0x1111, x86_l_1111);
x86_l_3c8:
	/* 0x3c8: mov    r15d,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_32);
x86_l_3cb:
	/* 0x3cb: jmp    3da <tail_nodeport_rev_dnat_egress_ipv6+0x3da> */
	X86_SIM_X86_JMP(0x3cb, 0x3da, x86_l_3da);
x86_l_3cd:
	/* 0x3cd: mov    r15d,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_32);
x86_l_3d0:
	/* 0x3d0: cmp    rsi,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 59ULL);
x86_l_3d4:
	/* 0x3d4: je     1111 <tail_nodeport_rev_dnat_egress_ipv6+0x1111> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3d4, 0x1111, x86_l_1111);
x86_l_3da:
	/* 0x3da: mov    BYTE PTR [rsp+0x84],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_3e2:
	/* 0x3e2: mov    rcx,QWORD PTR [r12+0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 46ULL);
x86_l_3e7:
	/* 0x3e7: mov    QWORD PTR [rsp+0x68],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3ec:
	/* 0x3ec: mov    rcx,QWORD PTR [r12+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_3f1:
	/* 0x3f1: mov    QWORD PTR [rsp+0x60],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3f6:
	/* 0x3f6: mov    rcx,QWORD PTR [r12+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_3fb:
	/* 0x3fb: mov    QWORD PTR [rsp+0x78],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_400:
	/* 0x400: mov    rcx,QWORD PTR [r12+0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_405:
	/* 0x405: mov    QWORD PTR [rsp+0x70],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_40a:
	/* 0x40a: cmp    r15b,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_8, 17ULL);
x86_l_40e:
	/* 0x40e: je     41d <tail_nodeport_rev_dnat_egress_ipv6+0x41d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x40e, 0x41d, x86_l_41d);
x86_l_410:
	/* 0x410: movzx  ecx,r15b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R15, X86_WIDTH_32, X86_WIDTH_8);
x86_l_414:
	/* 0x414: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_417:
	/* 0x417: jne    e2b <tail_nodeport_rev_dnat_egress_ipv6+0xe2b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x417, 0xe2b, x86_l_e2b);
x86_l_41d:
	/* 0x41d: lea    r8d,[r13+0xe] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_421:
	/* 0x421: movabs rsi,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 2199023255552ULL);
x86_l_42b:
	/* 0x42b: mov    r9,QWORD PTR [rip+0x25b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R9, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_432:
	/* 0x432: cmp    BYTE PTR [r9],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_436:
	/* 0x436: je     487 <tail_nodeport_rev_dnat_egress_ipv6+0x487> */
	X86_SIM_X86_JCC(X86_CC_E, 0x436, 0x487, x86_l_487);
x86_l_438:
	/* 0x438: lea    r11,[r12+0xe] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_43d:
	/* 0x43d: mov    r15,QWORD PTR [r12+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_442:
	/* 0x442: mov    QWORD PTR [r12+0xe],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60129542144ULL);
x86_l_44b:
	/* 0x44b: mov    DWORD PTR [r12+0xe],r10d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R10, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_450:
	/* 0x450: mov    rax,r10 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R10, X86_WIDTH_64);
x86_l_453:
	/* 0x453: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_457:
	/* 0x457: mov    BYTE PTR [r12+0x12],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_45c:
	/* 0x45c: test   r10,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R10, X86_RSI, X86_WIDTH_64);
x86_l_45f:
	/* 0x45f: jne    b5d <tail_nodeport_rev_dnat_egress_ipv6+0xb5d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x45f, 0xb5d, x86_l_b5d);
x86_l_465:
	/* 0x465: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_468:
	/* 0x468: movzx  ecx,r8b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R8, X86_WIDTH_32, X86_WIDTH_8);
x86_l_46c:
	/* 0x46c: lea    rdx,[rax+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_470:
	/* 0x470: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_474:
	/* 0x474: mov    ebp,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967161ULL);
x86_l_479:
	/* 0x479: cmp    rdx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_47d:
	/* 0x47d: jbe    4c5 <tail_nodeport_rev_dnat_egress_ipv6+0x4c5> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x47d, 0x4c5, x86_l_4c5);
x86_l_47f:
	/* 0x47f: mov    QWORD PTR [r11],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R11, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_482:
	/* 0x482: jmp    1111 <tail_nodeport_rev_dnat_egress_ipv6+0x1111> */
	X86_SIM_X86_JMP(0x482, 0x1111, x86_l_1111);
x86_l_487:
	/* 0x487: test   r10,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R10, X86_RSI, X86_WIDTH_64);
x86_l_48a:
	/* 0x48a: jne    b91 <tail_nodeport_rev_dnat_egress_ipv6+0xb91> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x48a, 0xb91, x86_l_b91);
x86_l_490:
	/* 0x490: movzx  ecx,r8b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R8, X86_WIDTH_32, X86_WIDTH_8);
x86_l_494:
	/* 0x494: lea    rdx,[r12+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_498:
	/* 0x498: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_49c:
	/* 0x49c: mov    ebp,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967161ULL);
x86_l_4a1:
	/* 0x4a1: cmp    rdx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_4a4:
	/* 0x4a4: ja     1111 <tail_nodeport_rev_dnat_egress_ipv6+0x1111> */
	X86_SIM_X86_JCC(X86_CC_A, 0x4a4, 0x1111, x86_l_1111);
x86_l_4aa:
	/* 0x4aa: add    rcx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4ad:
	/* 0x4ad: mov    eax,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4af:
	/* 0x4af: mov    DWORD PTR [rsp+0x80],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_4b6:
	/* 0x4b6: cmp    r15b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_8, 6ULL);
x86_l_4ba:
	/* 0x4ba: je     4ee <tail_nodeport_rev_dnat_egress_ipv6+0x4ee> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4ba, 0x4ee, x86_l_4ee);
x86_l_4bc:
	/* 0x4bc: mov    rdi,QWORD PTR [rip+0x25b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct_any6_global)));
x86_l_4c3:
	/* 0x4c3: jmp    4f5 <tail_nodeport_rev_dnat_egress_ipv6+0x4f5> */
	X86_SIM_X86_JMP(0x4c3, 0x4f5, x86_l_4f5);
x86_l_4c5:
	/* 0x4c5: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4c8:
	/* 0x4c8: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ca:
	/* 0x4ca: mov    DWORD PTR [rsp+0x80],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_4d1:
	/* 0x4d1: bt     r10,0x28 */
	X86_SIM_L_EXEC_BT_IMM(X86_R10, X86_WIDTH_64, 40ULL);
x86_l_4d6:
	/* 0x4d6: jb     c12 <tail_nodeport_rev_dnat_egress_ipv6+0xc12> */
	X86_SIM_X86_JCC(X86_CC_B, 0x4d6, 0xc12, x86_l_c12);
x86_l_4dc:
	/* 0x4dc: mov    QWORD PTR [r11],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R11, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4df:
	/* 0x4df: movzx  r15d,BYTE PTR [rsp+0x84] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 132ULL);
x86_l_4e8:
	/* 0x4e8: cmp    r15b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_8, 6ULL);
x86_l_4ec:
	/* 0x4ec: jne    4bc <tail_nodeport_rev_dnat_egress_ipv6+0x4bc> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4ec, 0x4bc, x86_l_4bc);
x86_l_4ee:
	/* 0x4ee: mov    rdi,QWORD PTR [rip+0x25b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct6_global)));
x86_l_4f5:
	/* 0x4f5: mov    BYTE PTR [rsp+0x85],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 571230650368ULL);
x86_l_4fd:
	/* 0x4fd: cmp    BYTE PTR [r9],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_501:
	/* 0x501: mov    DWORD PTR [rsp],r8d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_505:
	/* 0x505: je     5a9 <tail_nodeport_rev_dnat_egress_ipv6+0x5a9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x505, 0x5a9, x86_l_5a9);
x86_l_50b:
	/* 0x50b: movabs rax,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 1099511627776ULL);
x86_l_515:
	/* 0x515: and    rax,r10 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R10, X86_WIDTH_64, X86_ALU_AND);
x86_l_518:
	/* 0x518: je     5a9 <tail_nodeport_rev_dnat_egress_ipv6+0x5a9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x518, 0x5a9, x86_l_5a9);
x86_l_51e:
	/* 0x51e: mov    QWORD PTR [rsp+0x8],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_523:
	/* 0x523: mov    r14,r10 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R10, X86_WIDTH_64);
x86_l_526:
	/* 0x526: mov    rbp,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_52a:
	/* 0x52a: sub    rbp,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 0ULL);
x86_l_52d:
	/* 0x52d: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_536:
	/* 0x536: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_53f:
	/* 0x53f: movabs rax,0x6c02a30109 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 463900705033ULL);
x86_l_549:
	/* 0x549: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_54e:
	/* 0x54e: mov    rdi,QWORD PTR [rip+0x25b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_555:
	/* 0x555: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_55a:
	/* 0x55a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_55f:
	/* 0x55f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_561:
	/* 0x561: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_564:
	/* 0x564: je     56f <tail_nodeport_rev_dnat_egress_ipv6+0x56f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x564, 0x56f, x86_l_56f);
x86_l_566:
	/* 0x566: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_569:
	/* 0x569: add    QWORD PTR [rax+0x8],rbp */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_56d:
	/* 0x56d: jmp    597 <tail_nodeport_rev_dnat_egress_ipv6+0x597> */
	X86_SIM_X86_JMP(0x56d, 0x597, x86_l_597);
x86_l_56f:
	/* 0x56f: mov    QWORD PTR [rsp+0x18],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215105ULL);
x86_l_578:
	/* 0x578: mov    QWORD PTR [rsp+0x20],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_57d:
	/* 0x57d: mov    rdi,QWORD PTR [rip+0x25b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_584:
	/* 0x584: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_589:
	/* 0x589: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_58e:
	/* 0x58e: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_593:
	/* 0x593: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_595:
	/* 0x595: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_597:
	/* 0x597: mov    r10,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R10, X86_R14, X86_WIDTH_64);
x86_l_59a:
	/* 0x59a: movabs rsi,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 2199023255552ULL);
x86_l_5a4:
	/* 0x5a4: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a9:
	/* 0x5a9: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5ac:
	/* 0x5ac: cmp    r15b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_8, 6ULL);
x86_l_5b0:
	/* 0x5b0: jne    607 <tail_nodeport_rev_dnat_egress_ipv6+0x607> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x5b0, 0x607, x86_l_607);
x86_l_5b2:
	/* 0x5b2: mov    rax,r10 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R10, X86_WIDTH_64);
x86_l_5b5:
	/* 0x5b5: mov    ebp,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 0ULL);
x86_l_5ba:
	/* 0x5ba: and    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_AND);
x86_l_5bd:
	/* 0x5bd: jne    609 <tail_nodeport_rev_dnat_egress_ipv6+0x609> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x5bd, 0x609, x86_l_609);
x86_l_5bf:
	/* 0x5bf: add    r13d,0x1a */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_ADD, 26ULL);
x86_l_5c3:
	/* 0x5c3: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5c6:
	/* 0x5c6: movzx  ecx,r13b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R13, X86_WIDTH_32, X86_WIDTH_8);
x86_l_5ca:
	/* 0x5ca: lea    rdx,[rax+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_5ce:
	/* 0x5ce: add    rdx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_5d2:
	/* 0x5d2: cmp    rdx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_5d6:
	/* 0x5d6: ja     e2b <tail_nodeport_rev_dnat_egress_ipv6+0xe2b> */
	X86_SIM_X86_JCC(X86_CC_A, 0x5d6, 0xe2b, x86_l_e2b);
x86_l_5dc:
	/* 0x5dc: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5df:
	/* 0x5df: movzx  r14d,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5e3:
	/* 0x5e3: mov    eax,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_32);
x86_l_5e6:
	/* 0x5e6: and    eax,0x1200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4608ULL);
x86_l_5eb:
	/* 0x5eb: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5ed:
	/* 0x5ed: cmp    eax,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 512ULL);
x86_l_5f2:
	/* 0x5f2: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_5f5:
	/* 0x5f5: test   r14d,0x500 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R14, X86_WIDTH_32, 1280ULL);
x86_l_5fc:
	/* 0x5fc: jne    cb6 <tail_nodeport_rev_dnat_egress_ipv6+0xcb6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x5fc, 0xcb6, x86_l_cb6);
x86_l_602:
	/* 0x602: mov    bpl,al */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_8);
x86_l_605:
	/* 0x605: jmp    609 <tail_nodeport_rev_dnat_egress_ipv6+0x609> */
	X86_SIM_X86_JMP(0x605, 0x609, x86_l_609);
x86_l_607:
	/* 0x607: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_609:
	/* 0x609: mov    QWORD PTR [rsp+0x8],r10 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R10, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_60e:
	/* 0x60e: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_613:
	/* 0x613: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_618:
	/* 0x618: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_61a:
	/* 0x61a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_61d:
	/* 0x61d: je     e22 <tail_nodeport_rev_dnat_egress_ipv6+0xe22> */
	X86_SIM_X86_JCC(X86_CC_E, 0x61d, 0xe22, x86_l_e22);
x86_l_623:
	/* 0x623: movzx  ecx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_627:
	/* 0x627: test   cl,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_62a:
	/* 0x62a: je     e22 <tail_nodeport_rev_dnat_egress_ipv6+0xe22> */
	X86_SIM_X86_JCC(X86_CC_E, 0x62a, 0xe22, x86_l_e22);
x86_l_630:
	/* 0x630: cmp    WORD PTR [rax+0x26],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 163208757248ULL);
x86_l_635:
	/* 0x635: je     e22 <tail_nodeport_rev_dnat_egress_ipv6+0xe22> */
	X86_SIM_X86_JCC(X86_CC_E, 0x635, 0xe22, x86_l_e22);
x86_l_63b:
	/* 0x63b: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_63d:
	/* 0x63d: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_63f:
	/* 0x63f: test   dl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_8, 3ULL);
x86_l_642:
	/* 0x642: mov    r8,QWORD PTR [rip+0x25b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R8, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_649:
	/* 0x649: je     761 <tail_nodeport_rev_dnat_egress_ipv6+0x761> */
	X86_SIM_X86_JCC(X86_CC_E, 0x649, 0x761, x86_l_761);
x86_l_64f:
	/* 0x64f: mov    DWORD PTR [rsp+0x4],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_654:
	/* 0x654: mov    rsi,QWORD PTR [rip+0x25b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_65b:
	/* 0x65b: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_65e:
	/* 0x65e: je     671 <tail_nodeport_rev_dnat_egress_ipv6+0x671> */
	X86_SIM_X86_JCC(X86_CC_E, 0x65e, 0x671, x86_l_671);
x86_l_660:
	/* 0x660: mov    rdx,QWORD PTR [rip+0x25b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_667:
	/* 0x667: imul   r14d,DWORD PTR [rdx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R14, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_66b:
	/* 0x66b: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_66f:
	/* 0x66f: jmp    677 <tail_nodeport_rev_dnat_egress_ipv6+0x677> */
	X86_SIM_X86_JMP(0x66f, 0x677, x86_l_677);
x86_l_671:
	/* 0x671: mov    r14d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 60ULL);
x86_l_677:
	/* 0x677: cmp    r15b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_8, 6ULL);
x86_l_67b:
	/* 0x67b: jne    6b5 <tail_nodeport_rev_dnat_egress_ipv6+0x6b5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x67b, 0x6b5, x86_l_6b5);
x86_l_67d:
	/* 0x67d: mov    edx,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_681:
	/* 0x681: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_683:
	/* 0x683: shr    edx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_686:
	/* 0x686: and    edx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_689:
	/* 0x689: or     ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_68b:
	/* 0x68b: mov    WORD PTR [rax+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_68f:
	/* 0x68f: test   cl,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 16ULL);
x86_l_692:
	/* 0x692: mov    ecx,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 60ULL);
x86_l_697:
	/* 0x697: mov    r14d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 21600ULL);
x86_l_69d:
	/* 0x69d: cmove  r14d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R14, X86_RCX, X86_WIDTH_32, X86_CC_E);
x86_l_6a1:
	/* 0x6a1: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6a4:
	/* 0x6a4: je     6b5 <tail_nodeport_rev_dnat_egress_ipv6+0x6b5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6a4, 0x6b5, x86_l_6b5);
x86_l_6a6:
	/* 0x6a6: mov    rcx,QWORD PTR [rip+0x25b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_6ad:
	/* 0x6ad: imul   r14d,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_6b1:
	/* 0x6b1: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_6b5:
	/* 0x6b5: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_6bd:
	/* 0x6bd: movzx  r13d,WORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_6c3:
	/* 0x6c3: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_6c7:
	/* 0x6c7: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6ca:
	/* 0x6ca: je     6de <tail_nodeport_rev_dnat_egress_ipv6+0x6de> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6ca, 0x6de, x86_l_6de);
x86_l_6cc:
	/* 0x6cc: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_6d1:
	/* 0x6d1: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6d3:
	/* 0x6d3: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_6d5:
	/* 0x6d5: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_6d8:
	/* 0x6d8: shr    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_6dc:
	/* 0x6dc: jmp    701 <tail_nodeport_rev_dnat_egress_ipv6+0x701> */
	X86_SIM_X86_JMP(0x6dc, 0x701, x86_l_701);
x86_l_6de:
	/* 0x6de: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_6e3:
	/* 0x6e3: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6e5:
	/* 0x6e5: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_6e7:
	/* 0x6e7: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_6eb:
	/* 0x6eb: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_6f5:
	/* 0x6f5: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_6f8:
	/* 0x6f8: mulx   rcx,rcx,rcx */
	X86_SIM_L_EXEC_MULX(X86_RCX, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_6fd:
	/* 0x6fd: shr    rcx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_701:
	/* 0x701: add    r14d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_704:
	/* 0x704: mov    rax,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_70c:
	/* 0x70c: mov    DWORD PTR [rax+0x20],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_710:
	/* 0x710: movzx  edx,BYTE PTR [rax+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_714:
	/* 0x714: mov    esi,DWORD PTR [rax+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_717:
	/* 0x717: and    r13b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_71b:
	/* 0x71b: mov    rdi,QWORD PTR [rip+0x25b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_722:
	/* 0x722: cmp    BYTE PTR [rdi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_725:
	/* 0x725: mov    r8,QWORD PTR [rip+0x25b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R8, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_72c:
	/* 0x72c: je     73f <tail_nodeport_rev_dnat_egress_ipv6+0x73f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x72c, 0x73f, x86_l_73f);
x86_l_72e:
	/* 0x72e: mov    rdi,QWORD PTR [rip+0x25b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_735:
	/* 0x735: mov    edi,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_737:
	/* 0x737: lea    edi,[rdi+rdi*4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_73a:
	/* 0x73a: shr    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_73d:
	/* 0x73d: jmp    744 <tail_nodeport_rev_dnat_egress_ipv6+0x744> */
	X86_SIM_X86_JMP(0x73d, 0x744, x86_l_744);
x86_l_73f:
	/* 0x73f: mov    edi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 5ULL);
x86_l_744:
	/* 0x744: mov    r14d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_749:
	/* 0x749: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_74b:
	/* 0x74b: or     r13b,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_74e:
	/* 0x74e: cmp    edi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RCX, X86_WIDTH_32);
x86_l_750:
	/* 0x750: jb     757 <tail_nodeport_rev_dnat_egress_ipv6+0x757> */
	X86_SIM_X86_JCC(X86_CC_B, 0x750, 0x757, x86_l_757);
x86_l_752:
	/* 0x752: cmp    dl,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_8);
x86_l_755:
	/* 0x755: je     761 <tail_nodeport_rev_dnat_egress_ipv6+0x761> */
	X86_SIM_X86_JCC(X86_CC_E, 0x755, 0x761, x86_l_761);
x86_l_757:
	/* 0x757: mov    BYTE PTR [rax+0x2b],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_75b:
	/* 0x75b: mov    DWORD PTR [rax+0x34],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_75e:
	/* 0x75e: mov    ecx,DWORD PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_761:
	/* 0x761: mov    rcx,QWORD PTR [rip+0x25b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_768:
	/* 0x768: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_76b:
	/* 0x76b: je     77e <tail_nodeport_rev_dnat_egress_ipv6+0x77e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x76b, 0x77e, x86_l_77e);
x86_l_76d:
	/* 0x76d: inc QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 16ULL);
x86_l_772:
	/* 0x772: mov    rcx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_776:
	/* 0x776: sub    rcx,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 0ULL);
x86_l_779:
	/* 0x779: add QWORD PTR [rax+0x18],rcx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_77e:
	/* 0x77e: cmp    ebp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_781:
	/* 0x781: je     7d3 <tail_nodeport_rev_dnat_egress_ipv6+0x7d3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x781, 0x7d3, x86_l_7d3);
x86_l_783:
	/* 0x783: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_786:
	/* 0x786: jne    8b6 <tail_nodeport_rev_dnat_egress_ipv6+0x8b6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x786, 0x8b6, x86_l_8b6);
x86_l_78c:
	/* 0x78c: movzx  ecx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_790:
	/* 0x790: test   cl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_793:
	/* 0x793: je     8b6 <tail_nodeport_rev_dnat_egress_ipv6+0x8b6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x793, 0x8b6, x86_l_8b6);
x86_l_799:
	/* 0x799: mov    edx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_32);
x86_l_79c:
	/* 0x79c: mov    WORD PTR [rax+0x2a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 180388626432ULL);
x86_l_7a2:
	/* 0x7a2: and    ecx,0xffec */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 65516ULL);
x86_l_7a8:
	/* 0x7a8: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_7ab:
	/* 0x7ab: mov    WORD PTR [rax+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_7af:
	/* 0x7af: mov    rax,QWORD PTR [rip+0x25b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_7b6:
	/* 0x7b6: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7b9:
	/* 0x7b9: je     d46 <tail_nodeport_rev_dnat_egress_ipv6+0xd46> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7b9, 0xd46, x86_l_d46);
x86_l_7bf:
	/* 0x7bf: mov    rax,QWORD PTR [rip+0x25b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_7c6:
	/* 0x7c6: imul   r13d,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_7ca:
	/* 0x7ca: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_7ce:
	/* 0x7ce: jmp    d4c <tail_nodeport_rev_dnat_egress_ipv6+0xd4c> */
	X86_SIM_X86_JMP(0x7ce, 0xd4c, x86_l_d4c);
x86_l_7d3:
	/* 0x7d3: mov    ecx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_32);
x86_l_7d6:
	/* 0x7d6: shr    ecx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_7d9:
	/* 0x7d9: and    ecx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2ULL);
x86_l_7dc:
	/* 0x7dc: or     cx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RAX, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 36ULL);
x86_l_7e0:
	/* 0x7e0: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_7e2:
	/* 0x7e2: or     edx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_OR, 1ULL);
x86_l_7e5:
	/* 0x7e5: mov    WORD PTR [rax+0x24],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_7e9:
	/* 0x7e9: mov    edx,DWORD PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7ec:
	/* 0x7ec: test   cl,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_7ef:
	/* 0x7ef: je     8b6 <tail_nodeport_rev_dnat_egress_ipv6+0x8b6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7ef, 0x8b6, x86_l_8b6);
x86_l_7f5:
	/* 0x7f5: mov    edx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_32);
x86_l_7f8:
	/* 0x7f8: mov    r14,QWORD PTR [rip+0x25b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_7ff:
	/* 0x7ff: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_803:
	/* 0x803: je     81a <tail_nodeport_rev_dnat_egress_ipv6+0x81a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x803, 0x81a, x86_l_81a);
x86_l_805:
	/* 0x805: mov    rcx,QWORD PTR [rip+0x25b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_80c:
	/* 0x80c: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_80e:
	/* 0x80e: add    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_810:
	/* 0x810: lea    r15d,[rcx+rcx*4] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 0ULL);
x86_l_814:
	/* 0x814: shr    r15d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_818:
	/* 0x818: jmp    820 <tail_nodeport_rev_dnat_egress_ipv6+0x820> */
	X86_SIM_X86_JMP(0x818, 0x820, x86_l_820);
x86_l_81a:
	/* 0x81a: mov    r15d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 10ULL);
x86_l_820:
	/* 0x820: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_823:
	/* 0x823: movzx  ebp,dx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RDX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_826:
	/* 0x826: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_829:
	/* 0x829: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_82d:
	/* 0x82d: je     841 <tail_nodeport_rev_dnat_egress_ipv6+0x841> */
	X86_SIM_X86_JCC(X86_CC_E, 0x82d, 0x841, x86_l_841);
x86_l_82f:
	/* 0x82f: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_834:
	/* 0x834: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_836:
	/* 0x836: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_838:
	/* 0x838: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_83b:
	/* 0x83b: shr    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_83f:
	/* 0x83f: jmp    864 <tail_nodeport_rev_dnat_egress_ipv6+0x864> */
	X86_SIM_X86_JMP(0x83f, 0x864, x86_l_864);
x86_l_841:
	/* 0x841: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_846:
	/* 0x846: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_848:
	/* 0x848: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_84a:
	/* 0x84a: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_84e:
	/* 0x84e: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_858:
	/* 0x858: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_85b:
	/* 0x85b: mulx   rcx,rcx,rcx */
	X86_SIM_L_EXEC_MULX(X86_RCX, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_860:
	/* 0x860: shr    rcx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_864:
	/* 0x864: add    r15d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_867:
	/* 0x867: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_86a:
	/* 0x86a: mov    DWORD PTR [r13+0x20],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_86e:
	/* 0x86e: movzx  edx,BYTE PTR [r13+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_873:
	/* 0x873: mov    esi,DWORD PTR [r13+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_877:
	/* 0x877: and    bpl,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_87b:
	/* 0x87b: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_87f:
	/* 0x87f: mov    r8,QWORD PTR [rip+0x25b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R8, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_886:
	/* 0x886: je     899 <tail_nodeport_rev_dnat_egress_ipv6+0x899> */
	X86_SIM_X86_JCC(X86_CC_E, 0x886, 0x899, x86_l_899);
x86_l_888:
	/* 0x888: mov    rdi,QWORD PTR [rip+0x25b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_88f:
	/* 0x88f: mov    edi,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_891:
	/* 0x891: lea    edi,[rdi+rdi*4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_894:
	/* 0x894: shr    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_897:
	/* 0x897: jmp    89e <tail_nodeport_rev_dnat_egress_ipv6+0x89e> */
	X86_SIM_X86_JMP(0x897, 0x89e, x86_l_89e);
x86_l_899:
	/* 0x899: mov    edi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 5ULL);
x86_l_89e:
	/* 0x89e: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_8a0:
	/* 0x8a0: or     bpl,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_8a3:
	/* 0x8a3: cmp    edi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RCX, X86_WIDTH_32);
x86_l_8a5:
	/* 0x8a5: jb     8ac <tail_nodeport_rev_dnat_egress_ipv6+0x8ac> */
	X86_SIM_X86_JCC(X86_CC_B, 0x8a5, 0x8ac, x86_l_8ac);
x86_l_8a7:
	/* 0x8a7: cmp    dl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBP, X86_WIDTH_8);
x86_l_8aa:
	/* 0x8aa: je     8b6 <tail_nodeport_rev_dnat_egress_ipv6+0x8b6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8aa, 0x8b6, x86_l_8b6);
x86_l_8ac:
	/* 0x8ac: mov    BYTE PTR [rax+0x2b],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_8b0:
	/* 0x8b0: mov    DWORD PTR [rax+0x34],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_8b3:
	/* 0x8b3: mov    ecx,DWORD PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8b6:
	/* 0x8b6: test   BYTE PTR [rsp+0x85],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 571230650370ULL);
x86_l_8be:
	/* 0x8be: jne    e2b <tail_nodeport_rev_dnat_egress_ipv6+0xe2b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x8be, 0xe2b, x86_l_e2b);
x86_l_8c4:
	/* 0x8c4: mov    rcx,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8c7:
	/* 0x8c7: lea    rdx,[rcx+0x16] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_8cb:
	/* 0x8cb: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8ce:
	/* 0x8ce: cmp    rdx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_8d2:
	/* 0x8d2: ja     110c <tail_nodeport_rev_dnat_egress_ipv6+0x110c> */
	X86_SIM_X86_JCC(X86_CC_A, 0x8d2, 0x110c, x86_l_110c);
x86_l_8d8:
	/* 0x8d8: movzx  edx,BYTE PTR [rcx+0x15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 21ULL);
x86_l_8dc:
	/* 0x8dc: mov    ebp,0xffffff3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967100ULL);
x86_l_8e1:
	/* 0x8e1: cmp    dl,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_8, 2ULL);
x86_l_8e4:
	/* 0x8e4: jb     1111 <tail_nodeport_rev_dnat_egress_ipv6+0x1111> */
	X86_SIM_X86_JCC(X86_CC_B, 0x8e4, 0x1111, x86_l_1111);
x86_l_8ea:
	/* 0x8ea: movzx  eax,WORD PTR [rax+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_8ee:
	/* 0x8ee: dec    dl */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_8, X86_ALU_DEC, 1);
x86_l_8f0:
	/* 0x8f0: mov    BYTE PTR [rcx+0x15],dl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 21ULL);
x86_l_8f3:
	/* 0x8f3: mov    WORD PTR [rsp+0x18],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_8f8:
	/* 0x8f8: mov    r15,QWORD PTR [rip+0x25b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_8ff:
	/* 0x8ff: movzx  eax,BYTE PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_903:
	/* 0x903: mov    rdi,QWORD PTR [rip+0x25b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb6_reverse_nat)));
x86_l_90a:
	/* 0x90a: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_90f:
	/* 0x90f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_914:
	/* 0x914: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_916:
	/* 0x916: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_919:
	/* 0x919: je     a1b <tail_nodeport_rev_dnat_egress_ipv6+0xa1b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x919, 0xa1b, x86_l_a1b);
x86_l_91f:
	/* 0x91f: movzx  esi,WORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_923:
	/* 0x923: movzx  ecx,BYTE PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_927:
	/* 0x927: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_92c:
	/* 0x92c: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_931:
	/* 0x931: mov    QWORD PTR [rsp+0x20],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_936:
	/* 0x936: mov    QWORD PTR [rsp+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_93b:
	/* 0x93b: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_93f:
	/* 0x93f: mov    QWORD PTR [rsp+0x78],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_944:
	/* 0x944: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_947:
	/* 0x947: mov    QWORD PTR [rsp+0x70],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_94c:
	/* 0x94c: mov    rcx,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_94f:
	/* 0x94f: mov    rdi,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_953:
	/* 0x953: lea    rdx,[rcx+0x26] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_957:
	/* 0x957: mov    ebp,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967155ULL);
x86_l_95c:
	/* 0x95c: cmp    rdx,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_95f:
	/* 0x95f: jbe    969 <tail_nodeport_rev_dnat_egress_ipv6+0x969> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x95f, 0x969, x86_l_969);
x86_l_961:
	/* 0x961: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_964:
	/* 0x964: jmp    1119 <tail_nodeport_rev_dnat_egress_ipv6+0x1119> */
	X86_SIM_X86_JMP(0x964, 0x1119, x86_l_1119);
x86_l_969:
	/* 0x969: mov    rdx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_96d:
	/* 0x96d: mov    QWORD PTR [rcx+0x1e],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_971:
	/* 0x971: mov    rdx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_974:
	/* 0x974: mov    QWORD PTR [rcx+0x16],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_978:
	/* 0x978: movabs rdx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 2199023255552ULL);
x86_l_982:
	/* 0x982: test   QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_987:
	/* 0x987: jne    a1b <tail_nodeport_rev_dnat_egress_ipv6+0xa1b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x987, 0xa1b, x86_l_a1b);
x86_l_98d:
	/* 0x98d: movzx  r9d,BYTE PTR [rsp+0x84] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 132ULL);
x86_l_996:
	/* 0x996: mov    r15b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_8, 1ULL);
x86_l_999:
	/* 0x999: cmp    r9d,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 58ULL);
x86_l_99d:
	/* 0x99d: je     9c0 <tail_nodeport_rev_dnat_egress_ipv6+0x9c0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x99d, 0x9c0, x86_l_9c0);
x86_l_99f:
	/* 0x99f: cmp    r9d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 17ULL);
x86_l_9a3:
	/* 0x9a3: je     9b3 <tail_nodeport_rev_dnat_egress_ipv6+0x9b3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9a3, 0x9b3, x86_l_9b3);
x86_l_9a5:
	/* 0x9a5: cmp    r9d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 6ULL);
x86_l_9a9:
	/* 0x9a9: jne    9ca <tail_nodeport_rev_dnat_egress_ipv6+0x9ca> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x9a9, 0x9ca, x86_l_9ca);
x86_l_9ab:
	/* 0x9ab: mov    r12d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 16ULL);
x86_l_9b1:
	/* 0x9b1: jmp    9c6 <tail_nodeport_rev_dnat_egress_ipv6+0x9c6> */
	X86_SIM_X86_JMP(0x9b1, 0x9c6, x86_l_9c6);
x86_l_9b3:
	/* 0x9b3: mov    r12d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 6ULL);
x86_l_9b9:
	/* 0x9b9: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9bb:
	/* 0x9bb: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9be:
	/* 0x9be: jmp    9cf <tail_nodeport_rev_dnat_egress_ipv6+0x9cf> */
	X86_SIM_X86_JMP(0x9be, 0x9cf, x86_l_9cf);
x86_l_9c0:
	/* 0x9c0: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_9c6:
	/* 0x9c6: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9c8:
	/* 0x9c8: jmp    9cf <tail_nodeport_rev_dnat_egress_ipv6+0x9cf> */
	X86_SIM_X86_JMP(0x9c8, 0x9cf, x86_l_9cf);
x86_l_9ca:
	/* 0x9ca: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9cd:
	/* 0x9cd: mov    dl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_8, 1ULL);
x86_l_9cf:
	/* 0x9cf: test   si,si */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_16);
x86_l_9d2:
	/* 0x9d2: je     a13 <tail_nodeport_rev_dnat_egress_ipv6+0xa13> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9d2, 0xa13, x86_l_a13);
x86_l_9d4:
	/* 0x9d4: movzx  r8d,WORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 128ULL);
x86_l_9dd:
	/* 0x9dd: mov    ebp,0xffffff72 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967154ULL);
x86_l_9e2:
	/* 0x9e2: cmp    r9d,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 16ULL);
x86_l_9e6:
	/* 0x9e6: jg     9f9 <tail_nodeport_rev_dnat_egress_ipv6+0x9f9> */
	X86_SIM_X86_JCC(X86_CC_G, 0x9e6, 0x9f9, x86_l_9f9);
x86_l_9e8:
	/* 0x9e8: cmp    r9d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 1ULL);
x86_l_9ec:
	/* 0x9ec: je     a13 <tail_nodeport_rev_dnat_egress_ipv6+0xa13> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9ec, 0xa13, x86_l_a13);
x86_l_9ee:
	/* 0x9ee: cmp    r9d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 6ULL);
x86_l_9f2:
	/* 0x9f2: je     a09 <tail_nodeport_rev_dnat_egress_ipv6+0xa09> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9f2, 0xa09, x86_l_a09);
x86_l_9f4:
	/* 0x9f4: jmp    961 <tail_nodeport_rev_dnat_egress_ipv6+0x961> */
	X86_SIM_X86_JMP(0x9f4, 0x961, x86_l_961);
x86_l_9f9:
	/* 0x9f9: cmp    r9d,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 58ULL);
x86_l_9fd:
	/* 0x9fd: je     a13 <tail_nodeport_rev_dnat_egress_ipv6+0xa13> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9fd, 0xa13, x86_l_a13);
x86_l_9ff:
	/* 0x9ff: cmp    r9d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 17ULL);
x86_l_a03:
	/* 0xa03: jne    961 <tail_nodeport_rev_dnat_egress_ipv6+0x961> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa03, 0x961, x86_l_961);
x86_l_a09:
	/* 0xa09: cmp    si,r8w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_R8, X86_WIDTH_16);
x86_l_a0d:
	/* 0xa0d: jne    b9b <tail_nodeport_rev_dnat_egress_ipv6+0xb9b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa0d, 0xb9b, x86_l_b9b);
x86_l_a13:
	/* 0xa13: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_a15:
	/* 0xa15: je     ad2 <tail_nodeport_rev_dnat_egress_ipv6+0xad2> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa15, 0xad2, x86_l_ad2);
x86_l_a1b:
	/* 0xa1b: mov    r15,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a1e:
	/* 0xa1e: lea    rax,[r15+0x36] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_a22:
	/* 0xa22: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_a27:
	/* 0xa27: cmp    rax,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_a2b:
	/* 0xa2b: ja     1111 <tail_nodeport_rev_dnat_egress_ipv6+0x1111> */
	X86_SIM_X86_JCC(X86_CC_A, 0xa2b, 0x1111, x86_l_1111);
x86_l_a31:
	/* 0xa31: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_a39:
	/* 0xa39: mov    rdi,QWORD PTR [rip+0x25b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_a40:
	/* 0xa40: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_a45:
	/* 0xa45: mov    r14d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 1ULL);
x86_l_a4b:
	/* 0xa4b: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_a4e:
	/* 0xa4e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a51:
	/* 0xa51: je     1609 <tail_nodeport_rev_dnat_egress_ipv6+0x1609> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa51, 0x1609, x86_l_1609);
x86_l_a57:
	/* 0xa57: mov    ebp,DWORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_a5a:
	/* 0xa5a: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_a62:
	/* 0xa62: mov    rdi,QWORD PTR [rip+0x25b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_a69:
	/* 0xa69: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_a6e:
	/* 0xa6e: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_a71:
	/* 0xa71: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a74:
	/* 0xa74: je     a7c <tail_nodeport_rev_dnat_egress_ipv6+0xa7c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa74, 0xa7c, x86_l_a7c);
x86_l_a76:
	/* 0xa76: or     ebp,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_OR, 4ULL);
x86_l_a79:
	/* 0xa79: mov    DWORD PTR [rax+0x18],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_a7c:
	/* 0xa7c: cmp    QWORD PTR [r15+0x16],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 94489280512ULL);
x86_l_a81:
	/* 0xa81: jne    a9a <tail_nodeport_rev_dnat_egress_ipv6+0xa9a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa81, 0xa9a, x86_l_a9a);
x86_l_a83:
	/* 0xa83: cmp    DWORD PTR [r15+0x1e],0xffff0000 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 133143920640ULL);
x86_l_a8b:
	/* 0xa8b: jne    a9a <tail_nodeport_rev_dnat_egress_ipv6+0xa9a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa8b, 0xa9a, x86_l_a9a);
x86_l_a8d:
	/* 0xa8d: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a90:
	/* 0xa90: mov    ebp,0xffffff5f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967135ULL);
x86_l_a95:
	/* 0xa95: jmp    1111 <tail_nodeport_rev_dnat_egress_ipv6+0x1111> */
	X86_SIM_X86_JMP(0xa95, 0x1111, x86_l_1111);
x86_l_a9a:
	/* 0xa9a: mov    rax,QWORD PTR [r15+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_a9e:
	/* 0xa9e: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_aa6:
	/* 0xaa6: mov    rax,QWORD PTR [r15+0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_aaa:
	/* 0xaaa: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_ab2:
	/* 0xab2: mov    rax,QWORD PTR [r15+0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 46ULL);
x86_l_ab6:
	/* 0xab6: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_abe:
	/* 0xabe: mov    rax,QWORD PTR [r15+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_ac2:
	/* 0xac2: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_aca:
	/* 0xaca: mov    r12b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_8, 1ULL);
x86_l_acd:
	/* 0xacd: jmp    141b <tail_nodeport_rev_dnat_egress_ipv6+0x141b> */
	X86_SIM_X86_JMP(0xacd, 0x141b, x86_l_141b);
x86_l_ad2:
	/* 0xad2: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ad7:
	/* 0xad7: mov    r9d,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 28ULL);
x86_l_add:
	/* 0xadd: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_ae2:
	/* 0xae2: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_ae5:
	/* 0xae5: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_aea:
	/* 0xaea: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_aed:
	/* 0xaed: call   r9 */
	X86_SIM_BPF_CALL_REG(X86_R9);
x86_l_af0:
	/* 0xaf0: add    r12d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_af4:
	/* 0xaf4: mov    rcx,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_af7:
	/* 0xaf7: movzx  edx,r12b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_R12, X86_WIDTH_32, X86_WIDTH_8);
x86_l_afb:
	/* 0xafb: lea    rsi,[rcx+rdx*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_aff:
	/* 0xaff: add    rsi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_b03:
	/* 0xb03: mov    ebp,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967142ULL);
x86_l_b08:
	/* 0xb08: cmp    rsi,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_b0c:
	/* 0xb0c: ja     961 <tail_nodeport_rev_dnat_egress_ipv6+0x961> */
	X86_SIM_X86_JCC(X86_CC_A, 0xb0c, 0x961, x86_l_961);
x86_l_b12:
	/* 0xb12: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_b15:
	/* 0xb15: movzx  edx,WORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_b18:
	/* 0xb18: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_b1a:
	/* 0xb1a: setne  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_NE);
x86_l_b1e:
	/* 0xb1e: or     sil,r15b */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R15, X86_WIDTH_8, X86_ALU_OR);
x86_l_b21:
	/* 0xb21: cmp    sil,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_8, 1ULL);
x86_l_b25:
	/* 0xb25: jne    a1b <tail_nodeport_rev_dnat_egress_ipv6+0xa1b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb25, 0xa1b, x86_l_a1b);
x86_l_b2b:
	/* 0xb2b: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_b2d:
	/* 0xb2d: add    eax,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_b2f:
	/* 0xb2f: adc    eax,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_b32:
	/* 0xb32: movzx  edx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_b35:
	/* 0xb35: shr    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_b38:
	/* 0xb38: add    eax,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_b3a:
	/* 0xb3a: mov    edx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_b3c:
	/* 0xb3c: shr    edx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_b3f:
	/* 0xb3f: add    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_b41:
	/* 0xb41: cmp    dx,0xffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_16, 65535ULL);
x86_l_b45:
	/* 0xb45: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_b47:
	/* 0xb47: mov    eax,0xffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 65535ULL);
x86_l_b4c:
	/* 0xb4c: cmovne eax,edx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RDX, X86_WIDTH_32, X86_CC_NE);
x86_l_b4f:
	/* 0xb4f: test   r15b,r15b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_8);
x86_l_b52:
	/* 0xb52: cmovne eax,edx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RDX, X86_WIDTH_32, X86_CC_NE);
x86_l_b55:
	/* 0xb55: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b58:
	/* 0xb58: jmp    a1b <tail_nodeport_rev_dnat_egress_ipv6+0xa1b> */
	X86_SIM_X86_JMP(0xb58, 0xa1b, x86_l_a1b);
x86_l_b5d:
	/* 0xb5d: mov    DWORD PTR [rsp],r8d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b61:
	/* 0xb61: mov    rbp,r10 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R10, X86_WIDTH_64);
x86_l_b64:
	/* 0xb64: mov    rdi,QWORD PTR [rip+0x25b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv6_frag_datagrams)));
x86_l_b6b:
	/* 0xb6b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b70:
	/* 0xb70: mov    QWORD PTR [rsp+0x8],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b75:
	/* 0xb75: mov    rsi,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R11, X86_WIDTH_64);
x86_l_b78:
	/* 0xb78: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b7a:
	/* 0xb7a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b7d:
	/* 0xb7d: je     ca7 <tail_nodeport_rev_dnat_egress_ipv6+0xca7> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb7d, 0xca7, x86_l_ca7);
x86_l_b83:
	/* 0xb83: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b85:
	/* 0xb85: mov    DWORD PTR [rsp+0x80],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_b8c:
	/* 0xb8c: jmp    ce8 <tail_nodeport_rev_dnat_egress_ipv6+0xce8> */
	X86_SIM_X86_JMP(0xb8c, 0xce8, x86_l_ce8);
x86_l_b91:
	/* 0xb91: mov    ebp,0xffffff63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967139ULL);
x86_l_b96:
	/* 0xb96: jmp    1111 <tail_nodeport_rev_dnat_egress_ipv6+0x1111> */
	X86_SIM_X86_JMP(0xb96, 0x1111, x86_l_1111);
x86_l_b9b:
	/* 0xb9b: mov    r9d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b9f:
	/* 0xb9f: movzx  r10d,r9b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R10, X86_R9, X86_WIDTH_32, X86_WIDTH_8);
x86_l_ba3:
	/* 0xba3: lea    r11,[rcx+r10*1] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R10, 0), 0ULL);
x86_l_ba7:
	/* 0xba7: add    r11,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_bab:
	/* 0xbab: mov    ebp,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967155ULL);
x86_l_bb0:
	/* 0xbb0: cmp    r11,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R11, X86_RDI, X86_WIDTH_64);
x86_l_bb3:
	/* 0xbb3: ja     961 <tail_nodeport_rev_dnat_egress_ipv6+0x961> */
	X86_SIM_X86_JCC(X86_CC_A, 0xbb3, 0x961, x86_l_961);
x86_l_bb9:
	/* 0xbb9: add    r10,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_bbc:
	/* 0xbbc: mov    WORD PTR [r10],si */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R10, X86_RSI, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bc0:
	/* 0xbc0: add    r9d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R12, X86_WIDTH_32, X86_ALU_ADD);
x86_l_bc3:
	/* 0xbc3: movzx  r9d,r9b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R9, X86_R9, X86_WIDTH_32, X86_WIDTH_8);
x86_l_bc7:
	/* 0xbc7: lea    r10,[rcx+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_bcb:
	/* 0xbcb: add    r10,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_bcf:
	/* 0xbcf: mov    ebp,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967142ULL);
x86_l_bd4:
	/* 0xbd4: cmp    r10,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R10, X86_RDI, X86_WIDTH_64);
x86_l_bd7:
	/* 0xbd7: ja     961 <tail_nodeport_rev_dnat_egress_ipv6+0x961> */
	X86_SIM_X86_JCC(X86_CC_A, 0xbd7, 0x961, x86_l_961);
x86_l_bdd:
	/* 0xbdd: add    rcx,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R9, X86_WIDTH_64, X86_ALU_ADD);
x86_l_be0:
	/* 0xbe0: test   r15b,r15b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_8);
x86_l_be3:
	/* 0xbe3: jne    bef <tail_nodeport_rev_dnat_egress_ipv6+0xbef> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xbe3, 0xbef, x86_l_bef);
x86_l_be5:
	/* 0xbe5: cmp    WORD PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_be9:
	/* 0xbe9: je     a13 <tail_nodeport_rev_dnat_egress_ipv6+0xa13> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbe9, 0xa13, x86_l_a13);
x86_l_bef:
	/* 0xbef: movzx  edi,si */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDI, X86_RSI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_bf2:
	/* 0xbf2: test   r8d,r8d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R8, X86_R8, X86_WIDTH_32);
x86_l_bf5:
	/* 0xbf5: je     d0a <tail_nodeport_rev_dnat_egress_ipv6+0xd0a> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbf5, 0xd0a, x86_l_d0a);
x86_l_bfb:
	/* 0xbfb: not    r8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_bfe:
	/* 0xbfe: add    r8d,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_c01:
	/* 0xc01: adc    r8d,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_c05:
	/* 0xc05: movzx  esi,WORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_c08:
	/* 0xc08: not    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_c0a:
	/* 0xc0a: add    esi,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R8, X86_WIDTH_32, X86_ALU_ADD);
x86_l_c0d:
	/* 0xc0d: jmp    d11 <tail_nodeport_rev_dnat_egress_ipv6+0xd11> */
	X86_SIM_X86_JMP(0xc0d, 0xd11, x86_l_d11);
x86_l_c12:
	/* 0xc12: lea    rdx,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_c1a:
	/* 0xc1a: mov    rdi,QWORD PTR [rip+0x25b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv6_frag_datagrams)));
x86_l_c21:
	/* 0xc21: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_c26:
	/* 0xc26: mov    rsi,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R11, X86_WIDTH_64);
x86_l_c29:
	/* 0xc29: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c2b:
	/* 0xc2b: mov    rbp,r10 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R10, X86_WIDTH_64);
x86_l_c2e:
	/* 0xc2e: mov    DWORD PTR [rsp],r8d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c32:
	/* 0xc32: mov    QWORD PTR [rsp+0x8],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c37:
	/* 0xc37: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c39:
	/* 0xc39: mov    r11,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c3e:
	/* 0xc3e: mov    r9,QWORD PTR [rip+0x25b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R9, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_c45:
	/* 0xc45: movabs rsi,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 2199023255552ULL);
x86_l_c4f:
	/* 0xc4f: mov    r8d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c53:
	/* 0xc53: mov    r10,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R10, X86_RBP, X86_WIDTH_64);
x86_l_c56:
	/* 0xc56: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c58:
	/* 0xc58: je     4dc <tail_nodeport_rev_dnat_egress_ipv6+0x4dc> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc58, 0x4dc, x86_l_4dc);
x86_l_c5e:
	/* 0xc5e: mov    r14,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c62:
	/* 0xc62: sub    r14,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 0ULL);
x86_l_c65:
	/* 0xc65: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_c6e:
	/* 0xc6e: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_c77:
	/* 0xc77: movabs rax,0x7201a9020a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 489654125066ULL);
x86_l_c81:
	/* 0xc81: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c86:
	/* 0xc86: mov    rdi,QWORD PTR [rip+0x25b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_c8d:
	/* 0xc8d: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c92:
	/* 0xc92: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c97:
	/* 0xc97: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c99:
	/* 0xc99: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c9c:
	/* 0xc9c: je     cc0 <tail_nodeport_rev_dnat_egress_ipv6+0xcc0> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc9c, 0xcc0, x86_l_cc0);
x86_l_c9e:
	/* 0xc9e: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_ca1:
	/* 0xca1: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_ca5:
	/* 0xca5: jmp    ce8 <tail_nodeport_rev_dnat_egress_ipv6+0xce8> */
	X86_SIM_X86_JMP(0xca5, 0xce8, x86_l_ce8);
x86_l_ca7:
	/* 0xca7: mov    ebp,0xffffff51 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967121ULL);
x86_l_cac:
	/* 0xcac: mov    r11,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cb1:
	/* 0xcb1: jmp    47f <tail_nodeport_rev_dnat_egress_ipv6+0x47f> */
	X86_SIM_X86_JMP(0xcb1, 0x47f, x86_l_47f);
x86_l_cb6:
	/* 0xcb6: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_cbb:
	/* 0xcbb: jmp    609 <tail_nodeport_rev_dnat_egress_ipv6+0x609> */
	X86_SIM_X86_JMP(0xcbb, 0x609, x86_l_609);
x86_l_cc0:
	/* 0xcc0: mov    QWORD PTR [rsp+0x18],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215105ULL);
x86_l_cc9:
	/* 0xcc9: mov    QWORD PTR [rsp+0x20],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_cce:
	/* 0xcce: mov    rdi,QWORD PTR [rip+0x25b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_cd5:
	/* 0xcd5: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_cda:
	/* 0xcda: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_cdf:
	/* 0xcdf: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_ce4:
	/* 0xce4: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ce6:
	/* 0xce6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ce8:
	/* 0xce8: mov    r10,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R10, X86_RBP, X86_WIDTH_64);
x86_l_ceb:
	/* 0xceb: mov    r8d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cef:
	/* 0xcef: movabs rsi,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 2199023255552ULL);
x86_l_cf9:
	/* 0xcf9: mov    r9,QWORD PTR [rip+0x25b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R9, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_d00:
	/* 0xd00: mov    r11,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d05:
	/* 0xd05: jmp    4dc <tail_nodeport_rev_dnat_egress_ipv6+0x4dc> */
	X86_SIM_X86_JMP(0xd05, 0x4dc, x86_l_4dc);
x86_l_d0a:
	/* 0xd0a: movzx  esi,WORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_d0d:
	/* 0xd0d: not    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_d0f:
	/* 0xd0f: add    esi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_d11:
	/* 0xd11: setb   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_B);
x86_l_d15:
	/* 0xd15: movzx  edi,dil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDI, X86_RDI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_d19:
	/* 0xd19: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_d1b:
	/* 0xd1b: movzx  esi,di */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RDI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_d1e:
	/* 0xd1e: shr    edi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_d21:
	/* 0xd21: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_d23:
	/* 0xd23: mov    esi,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RDI, X86_WIDTH_32);
x86_l_d25:
	/* 0xd25: shr    esi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_d28:
	/* 0xd28: add    esi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_d2a:
	/* 0xd2a: cmp    si,0xffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_16, 65535ULL);
x86_l_d2e:
	/* 0xd2e: not    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_d30:
	/* 0xd30: mov    edi,0xffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 65535ULL);
x86_l_d35:
	/* 0xd35: cmovne edi,esi */
	X86_SIM_L_EXEC_CMOV(X86_RDI, X86_RSI, X86_WIDTH_32, X86_CC_NE);
x86_l_d38:
	/* 0xd38: test   r15b,r15b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_8);
x86_l_d3b:
	/* 0xd3b: cmovne edi,esi */
	X86_SIM_L_EXEC_CMOV(X86_RDI, X86_RSI, X86_WIDTH_32, X86_CC_NE);
x86_l_d3e:
	/* 0xd3e: mov    WORD PTR [rcx],di */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDI, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d41:
	/* 0xd41: jmp    a13 <tail_nodeport_rev_dnat_egress_ipv6+0xa13> */
	X86_SIM_X86_JMP(0xd41, 0xa13, x86_l_a13);
x86_l_d46:
	/* 0xd46: mov    r13d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 60ULL);
x86_l_d4c:
	/* 0xd4c: cmp    r15b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_8, 6ULL);
x86_l_d50:
	/* 0xd50: jne    d8f <tail_nodeport_rev_dnat_egress_ipv6+0xd8f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xd50, 0xd8f, x86_l_d8f);
x86_l_d52:
	/* 0xd52: mov    eax,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_d54:
	/* 0xd54: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_d56:
	/* 0xd56: shr    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_d59:
	/* 0xd59: and    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_d5c:
	/* 0xd5c: or     ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_OR);
x86_l_d5e:
	/* 0xd5e: mov    WORD PTR [r14+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_d63:
	/* 0xd63: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_d65:
	/* 0xd65: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_d6a:
	/* 0xd6a: mov    r13d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 21600ULL);
x86_l_d70:
	/* 0xd70: cmove  r13d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_d74:
	/* 0xd74: mov    rax,QWORD PTR [rip+0x25b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_d7b:
	/* 0xd7b: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d7e:
	/* 0xd7e: je     d8f <tail_nodeport_rev_dnat_egress_ipv6+0xd8f> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd7e, 0xd8f, x86_l_d8f);
x86_l_d80:
	/* 0xd80: mov    rax,QWORD PTR [rip+0x25b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_d87:
	/* 0xd87: imul   r13d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_d8b:
	/* 0xd8b: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_d8f:
	/* 0xd8f: movzx  ebp,dx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RDX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_d92:
	/* 0xd92: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_d95:
	/* 0xd95: mov    rax,QWORD PTR [rip+0x25b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_d9c:
	/* 0xd9c: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d9f:
	/* 0xd9f: je     db0 <tail_nodeport_rev_dnat_egress_ipv6+0xdb0> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd9f, 0xdb0, x86_l_db0);
x86_l_da1:
	/* 0xda1: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_da6:
	/* 0xda6: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_da8:
	/* 0xda8: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_daa:
	/* 0xdaa: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_dae:
	/* 0xdae: jmp    dd3 <tail_nodeport_rev_dnat_egress_ipv6+0xdd3> */
	X86_SIM_X86_JMP(0xdae, 0xdd3, x86_l_dd3);
x86_l_db0:
	/* 0xdb0: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_db5:
	/* 0xdb5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_db7:
	/* 0xdb7: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_db9:
	/* 0xdb9: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_dbd:
	/* 0xdbd: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_dc7:
	/* 0xdc7: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_dca:
	/* 0xdca: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_dcf:
	/* 0xdcf: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_dd3:
	/* 0xdd3: add    r13d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_dd6:
	/* 0xdd6: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_dd9:
	/* 0xdd9: mov    DWORD PTR [r14+0x20],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ddd:
	/* 0xddd: movzx  ecx,BYTE PTR [r14+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_de2:
	/* 0xde2: mov    edx,DWORD PTR [r14+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_de6:
	/* 0xde6: and    bpl,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_dea:
	/* 0xdea: mov    rsi,QWORD PTR [rip+0x25b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_df1:
	/* 0xdf1: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_df4:
	/* 0xdf4: je     e07 <tail_nodeport_rev_dnat_egress_ipv6+0xe07> */
	X86_SIM_X86_JCC(X86_CC_E, 0xdf4, 0xe07, x86_l_e07);
x86_l_df6:
	/* 0xdf6: mov    rsi,QWORD PTR [rip+0x25b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_dfd:
	/* 0xdfd: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_dff:
	/* 0xdff: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_e02:
	/* 0xe02: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_e05:
	/* 0xe05: jmp    e0c <tail_nodeport_rev_dnat_egress_ipv6+0xe0c> */
	X86_SIM_X86_JMP(0xe05, 0xe0c, x86_l_e0c);
x86_l_e07:
	/* 0xe07: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_e0c:
	/* 0xe0c: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_e0e:
	/* 0xe0e: or     bpl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_e11:
	/* 0xe11: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_e13:
	/* 0xe13: jb     e1a <tail_nodeport_rev_dnat_egress_ipv6+0xe1a> */
	X86_SIM_X86_JCC(X86_CC_B, 0xe13, 0xe1a, x86_l_e1a);
x86_l_e15:
	/* 0xe15: cmp    cl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_8);
x86_l_e18:
	/* 0xe18: je     e2b <tail_nodeport_rev_dnat_egress_ipv6+0xe2b> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe18, 0xe2b, x86_l_e2b);
x86_l_e1a:
	/* 0xe1a: mov    BYTE PTR [r14+0x2b],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_e1e:
	/* 0xe1e: mov    DWORD PTR [r14+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_e22:
	/* 0xe22: mov    rax,QWORD PTR [rip+0x25b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_e29:
	/* 0xe29: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e2b:
	/* 0xe2b: lea    r14,[r12+0x26] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_e30:
	/* 0xe30: add    r12,0x16 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 22ULL);
x86_l_e34:
	/* 0xe34: mov    DWORD PTR [rsp+0x18],0x100 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215360ULL);
x86_l_e3c:
	/* 0xe3c: mov    rax,QWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e3f:
	/* 0xe3f: mov    rcx,QWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e43:
	/* 0xe43: mov    QWORD PTR [rsp+0x1c],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_e48:
	/* 0xe48: mov    QWORD PTR [rsp+0x24],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_e4d:
	/* 0xe4d: mov    rax,QWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e51:
	/* 0xe51: mov    rcx,QWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e56:
	/* 0xe56: mov    QWORD PTR [rsp+0x2c],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_e5b:
	/* 0xe5b: mov    QWORD PTR [rsp+0x34],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_e60:
	/* 0xe60: mov    rdi,QWORD PTR [rip+0x25b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_egress_gw_policy_v6)));
x86_l_e67:
	/* 0xe67: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_e6c:
	/* 0xe6c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e71:
	/* 0xe71: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e73:
	/* 0xe73: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_e78:
	/* 0xe78: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e7b:
	/* 0xe7b: je     159f <tail_nodeport_rev_dnat_egress_ipv6+0x159f> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe7b, 0x159f, x86_l_159f);
x86_l_e81:
	/* 0xe81: test   DWORD PTR [rax+0x10],0xfeffffff */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72997666815ULL);
x86_l_e88:
	/* 0xe88: je     159f <tail_nodeport_rev_dnat_egress_ipv6+0x159f> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe88, 0x159f, x86_l_159f);
x86_l_e8e:
	/* 0xe8e: mov    WORD PTR [rsp+0x1e],0x200 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 128849019392ULL);
x86_l_e95:
	/* 0xe95: mov    DWORD PTR [rsp+0x18],0xa0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215264ULL);
x86_l_e9d:
	/* 0xe9d: mov    rax,QWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ea0:
	/* 0xea0: mov    rcx,QWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ea4:
	/* 0xea4: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ea9:
	/* 0xea9: mov    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_eae:
	/* 0xeae: mov    WORD PTR [rsp+0x1c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 120259084288ULL);
x86_l_eb5:
	/* 0xeb5: mov    rdi,QWORD PTR [rip+0x25b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipcache_v2)));
x86_l_ebc:
	/* 0xebc: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ec1:
	/* 0xec1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ec6:
	/* 0xec6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ec8:
	/* 0xec8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ecb:
	/* 0xecb: je     159f <tail_nodeport_rev_dnat_egress_ipv6+0x159f> */
	X86_SIM_X86_JCC(X86_CC_E, 0xecb, 0x159f, x86_l_159f);
x86_l_ed1:
	/* 0xed1: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_ed4:
	/* 0xed4: mov    eax,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_ed7:
	/* 0xed7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ed9:
	/* 0xed9: je     159f <tail_nodeport_rev_dnat_egress_ipv6+0x159f> */
	X86_SIM_X86_JCC(X86_CC_E, 0xed9, 0x159f, x86_l_159f);
x86_l_edf:
	/* 0xedf: movzx  ecx,WORD PTR [rsp+0x82] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 130ULL);
x86_l_ee7:
	/* 0xee7: mov    edx,DWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_eeb:
	/* 0xeeb: mov    esi,DWORD PTR [rsp+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_eef:
	/* 0xeef: mov    edi,DWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_ef3:
	/* 0xef3: sub    edx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_ef5:
	/* 0xef5: rorx   r8d,edi,0x1c */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_R8, X86_RDI, X86_WIDTH_32, 0, 28ULL);
x86_l_efb:
	/* 0xefb: xor    r8d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_efe:
	/* 0xefe: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_f00:
	/* 0xf00: sub    esi,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R8, X86_WIDTH_32, X86_ALU_SUB);
x86_l_f03:
	/* 0xf03: rorx   edx,r8d,0x1a */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_R8, X86_WIDTH_32, 0, 26ULL);
x86_l_f09:
	/* 0xf09: xor    edx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f0b:
	/* 0xf0b: add    r8d,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_f0e:
	/* 0xf0e: sub    edi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_f10:
	/* 0xf10: rorx   esi,edx,0x18 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RSI, X86_RDX, X86_WIDTH_32, 0, 24ULL);
x86_l_f16:
	/* 0xf16: xor    esi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f18:
	/* 0xf18: add    edx,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_32, X86_ALU_ADD);
x86_l_f1b:
	/* 0xf1b: sub    r8d,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RSI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_f1e:
	/* 0xf1e: rorx   edi,esi,0x10 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDI, X86_RSI, X86_WIDTH_32, 0, 16ULL);
x86_l_f24:
	/* 0xf24: xor    edi,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f27:
	/* 0xf27: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_f29:
	/* 0xf29: sub    edx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_32, X86_ALU_SUB);
x86_l_f2b:
	/* 0xf2b: rorx   r8d,edi,0xd */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_R8, X86_RDI, X86_WIDTH_32, 0, 13ULL);
x86_l_f31:
	/* 0xf31: xor    r8d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f34:
	/* 0xf34: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_f36:
	/* 0xf36: sub    esi,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R8, X86_WIDTH_32, X86_ALU_SUB);
x86_l_f39:
	/* 0xf39: rorx   edx,r8d,0x1c */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_R8, X86_WIDTH_32, 0, 28ULL);
x86_l_f3f:
	/* 0xf3f: xor    edx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f41:
	/* 0xf41: mov    esi,DWORD PTR [rsp+0x7c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_f45:
	/* 0xf45: add    esi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_f47:
	/* 0xf47: mov    r9d,DWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_f4f:
	/* 0xf4f: shl    r9d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_f53:
	/* 0xf53: or     r9d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_f56:
	/* 0xf56: add    r9d,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_f59:
	/* 0xf59: add    r9d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_ADD);
x86_l_f5c:
	/* 0xf5c: movzx  ecx,BYTE PTR [rsp+0x84] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 132ULL);
x86_l_f64:
	/* 0xf64: add    ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_f66:
	/* 0xf66: sub    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_f68:
	/* 0xf68: rorx   edx,ecx,0x1c */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 28ULL);
x86_l_f6e:
	/* 0xf6e: xor    edx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f70:
	/* 0xf70: add    ecx,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R9, X86_WIDTH_32, X86_ALU_ADD);
x86_l_f73:
	/* 0xf73: sub    r9d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_f76:
	/* 0xf76: rorx   r12d,edx,0x1a */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_R12, X86_RDX, X86_WIDTH_32, 0, 26ULL);
x86_l_f7c:
	/* 0xf7c: xor    r12d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R9, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f7f:
	/* 0xf7f: add    edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_f81:
	/* 0xf81: sub    ecx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R12, X86_WIDTH_32, X86_ALU_SUB);
x86_l_f84:
	/* 0xf84: rorx   r13d,r12d,0x18 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_R13, X86_R12, X86_WIDTH_32, 0, 24ULL);
x86_l_f8a:
	/* 0xf8a: xor    r13d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f8d:
	/* 0xf8d: add    r12d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_f90:
	/* 0xf90: sub    edx,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R13, X86_WIDTH_32, X86_ALU_SUB);
x86_l_f93:
	/* 0xf93: rorx   r15d,r13d,0x10 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_R15, X86_R13, X86_WIDTH_32, 0, 16ULL);
x86_l_f99:
	/* 0xf99: xor    r15d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f9c:
	/* 0xf9c: add    r13d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R12, X86_WIDTH_32, X86_ALU_ADD);
x86_l_f9f:
	/* 0xf9f: lea    esi,[r15+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_fa3:
	/* 0xfa3: mov    rcx,QWORD PTR [rip+0x25b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_hash_init6_seed)));
x86_l_faa:
	/* 0xfaa: mov    edx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fac:
	/* 0xfac: mov    DWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_fb4:
	/* 0xfb4: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_fbd:
	/* 0xfbd: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_fc6:
	/* 0xfc6: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_fcf:
	/* 0xfcf: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_fd8:
	/* 0xfd8: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_fe1:
	/* 0xfe1: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_fea:
	/* 0xfea: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_ff3:
	/* 0xff3: add    edx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_ff5:
	/* 0xff5: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_ffe:
	/* 0xffe: mov    rcx,QWORD PTR [rip+0x25b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_supports_fib_lookup_src)));
x86_l_1005:
	/* 0x1005: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1008:
	/* 0x1008: mov    DWORD PTR [rsp+0x8],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_100c:
	/* 0x100c: mov    DWORD PTR [rsp+0x4],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1010:
	/* 0x1010: je     1055 <tail_nodeport_rev_dnat_egress_ipv6+0x1055> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1010, 0x1055, x86_l_1055);
x86_l_1012:
	/* 0x1012: mov    BYTE PTR [rsp+0x18],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 103079215106ULL);
x86_l_1017:
	/* 0x1017: mov    ecx,DWORD PTR [rbx+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_101a:
	/* 0x101a: mov    DWORD PTR [rsp+0x20],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_101e:
	/* 0x101e: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1026:
	/* 0x1026: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_102a:
	/* 0x102a: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_102f:
	/* 0x102f: mov    eax,0x45 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 69ULL);
x86_l_1034:
	/* 0x1034: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1037:
	/* 0x1037: mov    edx,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 64ULL);
x86_l_103c:
	/* 0x103c: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1041:
	/* 0x1041: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1043:
	/* 0x1043: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1045:
	/* 0x1045: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1047:
	/* 0x1047: jne    104d <tail_nodeport_rev_dnat_egress_ipv6+0x104d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1047, 0x104d, x86_l_104d);
x86_l_1049:
	/* 0x1049: mov    ecx,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_104d:
	/* 0x104d: mov    DWORD PTR [rsp],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1050:
	/* 0x1050: mov    rbp,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R14, X86_WIDTH_64);
x86_l_1053:
	/* 0x1053: jmp    105f <tail_nodeport_rev_dnat_egress_ipv6+0x105f> */
	X86_SIM_X86_JMP(0x1053, 0x105f, x86_l_105f);
x86_l_1055:
	/* 0x1055: mov    rbp,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R14, X86_WIDTH_64);
x86_l_1058:
	/* 0x1058: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_105f:
	/* 0x105f: mov    r14,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1063:
	/* 0x1063: sub    r14,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 0ULL);
x86_l_1066:
	/* 0x1066: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_106f:
	/* 0x106f: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1078:
	/* 0x1078: movabs rax,0x6f00220200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 476743598592ULL);
x86_l_1082:
	/* 0x1082: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1087:
	/* 0x1087: mov    rdi,QWORD PTR [rip+0x25b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_108e:
	/* 0x108e: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1093:
	/* 0x1093: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1098:
	/* 0x1098: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_109a:
	/* 0x109a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_109d:
	/* 0x109d: je     10a8 <tail_nodeport_rev_dnat_egress_ipv6+0x10a8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x109d, 0x10a8, x86_l_10a8);
x86_l_109f:
	/* 0x109f: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_10a2:
	/* 0x10a2: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_10a6:
	/* 0x10a6: jmp    10d0 <tail_nodeport_rev_dnat_egress_ipv6+0x10d0> */
	X86_SIM_X86_JMP(0x10a6, 0x10d0, x86_l_10d0);
x86_l_10a8:
	/* 0x10a8: mov    QWORD PTR [rsp+0x18],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215105ULL);
x86_l_10b1:
	/* 0x10b1: mov    QWORD PTR [rsp+0x20],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_10b6:
	/* 0x10b6: mov    rdi,QWORD PTR [rip+0x25b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_10bd:
	/* 0x10bd: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10c2:
	/* 0x10c2: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_10c7:
	/* 0x10c7: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_10cc:
	/* 0x10cc: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10ce:
	/* 0x10ce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10d0:
	/* 0x10d0: mov    r14,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RBP, X86_WIDTH_64);
x86_l_10d3:
	/* 0x10d3: test   BYTE PTR [rbp+0x17],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 98784247812ULL);
x86_l_10d7:
	/* 0x10d7: jne    13fa <tail_nodeport_rev_dnat_egress_ipv6+0x13fa> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x10d7, 0x13fa, x86_l_13fa);
x86_l_10dd:
	/* 0x10dd: mov    eax,DWORD PTR [r14+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_10e1:
	/* 0x10e1: mov    DWORD PTR [rsp+0x88],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_10e8:
	/* 0x10e8: mov    rbp,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10ec:
	/* 0x10ec: sub    rbp,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 0ULL);
x86_l_10ef:
	/* 0x10ef: mov    eax,0x2c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_10f4:
	/* 0x10f4: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_10f7:
	/* 0x10f7: mov    esi,0xffffffce */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4294967246ULL);
x86_l_10fc:
	/* 0x10fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10fe:
	/* 0x10fe: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_1101:
	/* 0x1101: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1104:
	/* 0x1104: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1106:
	/* 0x1106: je     127e <tail_nodeport_rev_dnat_egress_ipv6+0x127e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1106, 0x127e, x86_l_127e);
x86_l_110c:
	/* 0x110c: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_1111:
	/* 0x1111: shl    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_1115:
	/* 0x1115: movzx  r15d,r14w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R14, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1119:
	/* 0x1119: mov    r14d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RBP, X86_WIDTH_32);
x86_l_111c:
	/* 0x111c: neg    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_111f:
	/* 0x111f: cmovs  r14d,ebp */
	X86_SIM_L_EXEC_CMOV(X86_R14, X86_RBP, X86_WIDTH_32, X86_CC_S);
x86_l_1123:
	/* 0x1123: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_112b:
	/* 0x112b: mov    rdi,QWORD PTR [rip+0x25b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_1132:
	/* 0x1132: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1137:
	/* 0x1137: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_113d:
	/* 0x113d: call   r12 */
	X86_SIM_BPF_CALL_REG(X86_R12);
x86_l_1140:
	/* 0x1140: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1143:
	/* 0x1143: je     114b <tail_nodeport_rev_dnat_egress_ipv6+0x114b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1143, 0x114b, x86_l_114b);
x86_l_1145:
	/* 0x1145: mov    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_114b:
	/* 0x114b: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1153:
	/* 0x1153: mov    rdi,QWORD PTR [rip+0x25b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_115a:
	/* 0x115a: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_115f:
	/* 0x115f: call   r12 */
	X86_SIM_BPF_CALL_REG(X86_R12);
x86_l_1162:
	/* 0x1162: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1165:
	/* 0x1165: je     116e <tail_nodeport_rev_dnat_egress_ipv6+0x116e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1165, 0x116e, x86_l_116e);
x86_l_1167:
	/* 0x1167: mov    DWORD PTR [rax+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_116e:
	/* 0x116e: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1176:
	/* 0x1176: mov    rdi,QWORD PTR [rip+0x25b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_117d:
	/* 0x117d: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1182:
	/* 0x1182: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_1188:
	/* 0x1188: call   r12 */
	X86_SIM_BPF_CALL_REG(X86_R12);
x86_l_118b:
	/* 0x118b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_118e:
	/* 0x118e: je     119a <tail_nodeport_rev_dnat_egress_ipv6+0x119a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x118e, 0x119a, x86_l_119a);
x86_l_1190:
	/* 0x1190: movzx  ecx,r14b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R14, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1194:
	/* 0x1194: or     ecx,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R15, X86_WIDTH_32, X86_ALU_OR);
x86_l_1197:
	/* 0x1197: mov    DWORD PTR [rax+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_119a:
	/* 0x119a: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_11a2:
	/* 0x11a2: mov    rdi,QWORD PTR [rip+0x25b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_11a9:
	/* 0x11a9: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_11ae:
	/* 0x11ae: call   r12 */
	X86_SIM_BPF_CALL_REG(X86_R12);
x86_l_11b1:
	/* 0x11b1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_11b4:
	/* 0x11b4: je     11bd <tail_nodeport_rev_dnat_egress_ipv6+0x11bd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11b4, 0x11bd, x86_l_11bd);
x86_l_11b6:
	/* 0x11b6: mov    DWORD PTR [rax+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_11bd:
	/* 0x11bd: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_11c5:
	/* 0x11c5: mov    rdi,QWORD PTR [rip+0x25b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_11cc:
	/* 0x11cc: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_11d1:
	/* 0x11d1: mov    r15d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 1ULL);
x86_l_11d7:
	/* 0x11d7: call   r15 */
	X86_SIM_BPF_CALL_REG(X86_R15);
x86_l_11da:
	/* 0x11da: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_11dd:
	/* 0x11dd: je     11e6 <tail_nodeport_rev_dnat_egress_ipv6+0x11e6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11dd, 0x11e6, x86_l_11e6);
x86_l_11df:
	/* 0x11df: mov    DWORD PTR [rax+0x10],0x4536801 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68792051713ULL);
x86_l_11e6:
	/* 0x11e6: mov    r12,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11ea:
	/* 0x11ea: sub    r12,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 0ULL);
x86_l_11ed:
	/* 0x11ed: movabs rax,0x6804530200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 446749147648ULL);
x86_l_11f7:
	/* 0x11f7: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_11ff:
	/* 0x11ff: mov    BYTE PTR [rsp+0x90],r14b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1207:
	/* 0x1207: mov    rdi,QWORD PTR [rip+0x25b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_120e:
	/* 0x120e: lea    rsi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1216:
	/* 0x1216: call   r15 */
	X86_SIM_BPF_CALL_REG(X86_R15);
x86_l_1219:
	/* 0x1219: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_121c:
	/* 0x121c: je     1227 <tail_nodeport_rev_dnat_egress_ipv6+0x1227> */
	X86_SIM_X86_JCC(X86_CC_E, 0x121c, 0x1227, x86_l_1227);
x86_l_121e:
	/* 0x121e: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1221:
	/* 0x1221: add    QWORD PTR [rax+0x8],r12 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1225:
	/* 0x1225: jmp    1252 <tail_nodeport_rev_dnat_egress_ipv6+0x1252> */
	X86_SIM_X86_JMP(0x1225, 0x1252, x86_l_1252);
x86_l_1227:
	/* 0x1227: mov    QWORD PTR [rsp+0x18],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215105ULL);
x86_l_1230:
	/* 0x1230: mov    QWORD PTR [rsp+0x20],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1235:
	/* 0x1235: mov    rdi,QWORD PTR [rip+0x25b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_123c:
	/* 0x123c: lea    rsi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1244:
	/* 0x1244: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1249:
	/* 0x1249: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_124e:
	/* 0x124e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1250:
	/* 0x1250: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1252:
	/* 0x1252: mov    rsi,QWORD PTR [rip+0x25b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_1259:
	/* 0x1259: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_125e:
	/* 0x125e: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1263:
	/* 0x1263: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1266:
	/* 0x1266: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_126b:
	/* 0x126b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_126d:
	/* 0x126d: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_126f:
	/* 0x126f: add    rsp,0xd8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 216ULL);
x86_l_1276:
	/* 0x1276: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_1278:
	/* 0x1278: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_1279:
	/* 0x1279: jmp    1610 <tail_nodeport_rev_dnat_egress_ipv6+0x1610> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_127e:
	/* 0x127e: mov    r10,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R10, X86_RBP, X86_WIDTH_64);
x86_l_1281:
	/* 0x1281: mov    r9d,DWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1289:
	/* 0x1289: mov    r8,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_128c:
	/* 0x128c: lea    rax,[r8+0x32] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 50ULL);
x86_l_1290:
	/* 0x1290: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_1295:
	/* 0x1295: cmp    rax,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_1299:
	/* 0x1299: ja     1111 <tail_nodeport_rev_dnat_egress_ipv6+0x1111> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1299, 0x1111, x86_l_1111);
x86_l_129f:
	/* 0x129f: sub    r12d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R15, X86_WIDTH_32, X86_ALU_SUB);
x86_l_12a2:
	/* 0x12a2: rorx   ecx,r15d,0xd */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_R15, X86_WIDTH_32, 0, 13ULL);
x86_l_12a8:
	/* 0x12a8: xor    ecx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12ab:
	/* 0x12ab: sub    r13d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_12ae:
	/* 0x12ae: rorx   eax,ecx,0x1c */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RAX, X86_RCX, X86_WIDTH_32, 0, 28ULL);
x86_l_12b4:
	/* 0x12b4: xor    eax,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12b7:
	/* 0x12b7: add    ecx,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 4ULL);
x86_l_12bb:
	/* 0x12bb: xor    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12bd:
	/* 0x12bd: rorx   edx,ecx,0x12 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 18ULL);
x86_l_12c3:
	/* 0x12c3: sub    eax,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_12c5:
	/* 0x12c5: mov    edi,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12c9:
	/* 0x12c9: xor    edi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12cb:
	/* 0x12cb: rorx   edx,eax,0x15 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RAX, X86_WIDTH_32, 0, 21ULL);
x86_l_12d1:
	/* 0x12d1: sub    edi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_12d3:
	/* 0x12d3: xor    ecx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12d5:
	/* 0x12d5: rorx   edx,edi,0x7 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RDI, X86_WIDTH_32, 0, 7ULL);
x86_l_12db:
	/* 0x12db: sub    ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_12dd:
	/* 0x12dd: xor    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12df:
	/* 0x12df: rorx   edx,ecx,0x10 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RCX, X86_WIDTH_32, 0, 16ULL);
x86_l_12e5:
	/* 0x12e5: sub    eax,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_12e7:
	/* 0x12e7: xor    edi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12e9:
	/* 0x12e9: rorx   edx,eax,0x1c */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RAX, X86_WIDTH_32, 0, 28ULL);
x86_l_12ef:
	/* 0x12ef: sub    edi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_12f1:
	/* 0x12f1: xor    ecx,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12f3:
	/* 0x12f3: rorx   edx,edi,0x12 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RDI, X86_WIDTH_32, 0, 18ULL);
x86_l_12f9:
	/* 0x12f9: sub    ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_12fb:
	/* 0x12fb: xor    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12fd:
	/* 0x12fd: rorx   ecx,ecx,0x8 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 8ULL);
x86_l_1303:
	/* 0x1303: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1305:
	/* 0x1305: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1307:
	/* 0x1307: shr    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_130a:
	/* 0x130a: xor    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_130c:
	/* 0x130c: mov    WORD PTR [r8+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1313:
	/* 0x1313: mov    QWORD PTR [r8+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_131b:
	/* 0x131b: mov    QWORD PTR [r8+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1323:
	/* 0x1323: mov    QWORD PTR [r8+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_132b:
	/* 0x132b: mov    QWORD PTR [r8+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1333:
	/* 0x1333: mov    QWORD PTR [r8+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_133b:
	/* 0x133b: lea    rdx,[r8+0xe] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_133f:
	/* 0x133f: mov    QWORD PTR [r8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1346:
	/* 0x1346: mov    rax,QWORD PTR [rip+0x25ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_tunnel_protocol)));
x86_l_134d:
	/* 0x134d: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1350:
	/* 0x1350: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1353:
	/* 0x1353: je     136a <tail_nodeport_rev_dnat_egress_ipv6+0x136a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1353, 0x136a, x86_l_136a);
x86_l_1355:
	/* 0x1355: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1358:
	/* 0x1358: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_135b:
	/* 0x135b: mov    esi,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_135e:
	/* 0x135e: jne    1380 <tail_nodeport_rev_dnat_egress_ipv6+0x1380> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x135e, 0x1380, x86_l_1380);
x86_l_1360:
	/* 0x1360: mov    DWORD PTR [r8+0x2a],0x58650000 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 181871640576ULL);
x86_l_1368:
	/* 0x1368: jmp    1378 <tail_nodeport_rev_dnat_egress_ipv6+0x1378> */
	X86_SIM_X86_JMP(0x1368, 0x1378, x86_l_1378);
x86_l_136a:
	/* 0x136a: mov    DWORD PTR [r8+0x2a],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 180388626440ULL);
x86_l_1372:
	/* 0x1372: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_1375:
	/* 0x1375: mov    esi,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1378:
	/* 0x1378: mov    DWORD PTR [r8+0x2e],0x20000 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 197568626688ULL);
x86_l_1380:
	/* 0x1380: mov    WORD PTR [r8+0x22],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R8, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_1385:
	/* 0x1385: mov    rax,QWORD PTR [rip+0x25ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_tunnel_port)));
x86_l_138c:
	/* 0x138c: movzx  eax,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_138f:
	/* 0x138f: movbe  WORD PTR [r8+0x24],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_R8, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_1396:
	/* 0x1396: lea    eax,[r10+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R10, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_139a:
	/* 0x139a: movbe  WORD PTR [r8+0x26],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_R8, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_13a1:
	/* 0x13a1: mov    WORD PTR [r8+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_13a8:
	/* 0x13a8: mov    BYTE PTR [r8+0xe],0x45 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 60129542213ULL);
x86_l_13ad:
	/* 0x13ad: add    r10d,0x24 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_ADD, 36ULL);
x86_l_13b1:
	/* 0x13b1: movbe  WORD PTR [r8+0x10],r10w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_R8, X86_R10, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_13b8:
	/* 0x13b8: mov    WORD PTR [r8+0x16],0x1140 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 94489284928ULL);
x86_l_13bf:
	/* 0x13bf: mov    DWORD PTR [r8+0x1a],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R8, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_13c3:
	/* 0x13c3: mov    DWORD PTR [r8+0x1e],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R8, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_13c7:
	/* 0x13c7: mov    eax,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_13cc:
	/* 0x13cc: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13ce:
	/* 0x13ce: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13d0:
	/* 0x13d0: mov    ecx,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 20ULL);
x86_l_13d5:
	/* 0x13d5: mov    r15,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R8, X86_WIDTH_64);
x86_l_13d8:
	/* 0x13d8: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13db:
	/* 0x13db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13dd:
	/* 0x13dd: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_13e0:
	/* 0x13e0: shr    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_13e3:
	/* 0x13e3: add    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_13e5:
	/* 0x13e5: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_13e7:
	/* 0x13e7: shr    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_13ea:
	/* 0x13ea: add    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_13ec:
	/* 0x13ec: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_13ee:
	/* 0x13ee: mov    WORD PTR [r15+0x18],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_13f3:
	/* 0x13f3: mov    WORD PTR [r15+0xc],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 51539607560ULL);
x86_l_13fa:
	/* 0x13fa: mov    DWORD PTR [rsp+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_1405:
	/* 0x1405: mov    eax,DWORD PTR [r14+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1409:
	/* 0x1409: mov    DWORD PTR [rsp+0xb0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1410:
	/* 0x1410: mov    BYTE PTR [rsp+0x90],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 618475290626ULL);
x86_l_1418:
	/* 0x1418: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_141b:
	/* 0x141b: lea    rsi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1423:
	/* 0x1423: mov    eax,0x45 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 69ULL);
x86_l_1428:
	/* 0x1428: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_142b:
	/* 0x142b: mov    edx,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 64ULL);
x86_l_1430:
	/* 0x1430: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1432:
	/* 0x1432: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1434:
	/* 0x1434: mov    r14d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_32);
x86_l_1437:
	/* 0x1437: mov    ebp,0xffffff57 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967127ULL);
x86_l_143c:
	/* 0x143c: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_143f:
	/* 0x143f: je     144a <tail_nodeport_rev_dnat_egress_ipv6+0x144a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x143f, 0x144a, x86_l_144a);
x86_l_1441:
	/* 0x1441: test   r14d,r14d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_32);
x86_l_1444:
	/* 0x1444: jne    1111 <tail_nodeport_rev_dnat_egress_ipv6+0x1111> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1444, 0x1111, x86_l_1111);
x86_l_144a:
	/* 0x144a: mov    r15d,DWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1452:
	/* 0x1452: mov    DWORD PTR [rsp+0x18],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1457:
	/* 0x1457: mov    rdi,QWORD PTR [rip+0x25ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_devices)));
x86_l_145e:
	/* 0x145e: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1463:
	/* 0x1463: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1468:
	/* 0x1468: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_146a:
	/* 0x146a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_146d:
	/* 0x146d: je     1479 <tail_nodeport_rev_dnat_egress_ipv6+0x1479> */
	X86_SIM_X86_JCC(X86_CC_E, 0x146d, 0x1479, x86_l_1479);
x86_l_146f:
	/* 0x146f: test   BYTE PTR [rax+0x8],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_1473:
	/* 0x1473: jne    1581 <tail_nodeport_rev_dnat_egress_ipv6+0x1581> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1473, 0x1581, x86_l_1581);
x86_l_1479:
	/* 0x1479: test   r14d,r14d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_32);
x86_l_147c:
	/* 0x147c: je     14ce <tail_nodeport_rev_dnat_egress_ipv6+0x14ce> */
	X86_SIM_X86_JCC(X86_CC_E, 0x147c, 0x14ce, x86_l_14ce);
x86_l_147e:
	/* 0x147e: mov    DWORD PTR [rsp+0x18],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1483:
	/* 0x1483: mov    rdi,QWORD PTR [rip+0x25ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_devices)));
x86_l_148a:
	/* 0x148a: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_148f:
	/* 0x148f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1494:
	/* 0x1494: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1496:
	/* 0x1496: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1499:
	/* 0x1499: lea    r13,[rip+0x25ba] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 9658ULL);
x86_l_14a0:
	/* 0x14a0: cmovne r13,rax */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RAX, X86_WIDTH_64, X86_CC_NE);
x86_l_14a4:
	/* 0x14a4: mov    r14d,0x64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 100ULL);
x86_l_14aa:
	/* 0x14aa: test   r12b,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_8);
x86_l_14ad:
	/* 0x14ad: je     1111 <tail_nodeport_rev_dnat_egress_ipv6+0x1111> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14ad, 0x1111, x86_l_1111);
x86_l_14b3:
	/* 0x14b3: cmp    BYTE PTR [rsp+0x90],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 618475290626ULL);
x86_l_14bb:
	/* 0x14bb: lea    rsi,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_14c3:
	/* 0x14c3: jne    1525 <tail_nodeport_rev_dnat_egress_ipv6+0x1525> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x14c3, 0x1525, x86_l_1525);
x86_l_14c5:
	/* 0x14c5: mov    rdi,QWORD PTR [rip+0x25ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_nodeport_neigh4)));
x86_l_14cc:
	/* 0x14cc: jmp    152c <tail_nodeport_rev_dnat_egress_ipv6+0x152c> */
	X86_SIM_X86_JMP(0x14cc, 0x152c, x86_l_152c);
x86_l_14ce:
	/* 0x14ce: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14d1:
	/* 0x14d1: lea    rcx,[rax+0x6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_14d5:
	/* 0x14d5: mov    ebp,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967155ULL);
x86_l_14da:
	/* 0x14da: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14dd:
	/* 0x14dd: cmp    rcx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_14e1:
	/* 0x14e1: ja     1111 <tail_nodeport_rev_dnat_egress_ipv6+0x1111> */
	X86_SIM_X86_JCC(X86_CC_A, 0x14e1, 0x1111, x86_l_1111);
x86_l_14e7:
	/* 0x14e7: movzx  ecx,WORD PTR [rsp+0xce] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 206ULL);
x86_l_14ef:
	/* 0x14ef: mov    WORD PTR [rax+0x4],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_14f3:
	/* 0x14f3: mov    ecx,DWORD PTR [rsp+0xca] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 202ULL);
x86_l_14fa:
	/* 0x14fa: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14fc:
	/* 0x14fc: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14ff:
	/* 0x14ff: lea    rcx,[rax+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1503:
	/* 0x1503: cmp    rcx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_1507:
	/* 0x1507: ja     1111 <tail_nodeport_rev_dnat_egress_ipv6+0x1111> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1507, 0x1111, x86_l_1111);
x86_l_150d:
	/* 0x150d: movzx  ecx,WORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 200ULL);
x86_l_1515:
	/* 0x1515: mov    WORD PTR [rax+0xa],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 10ULL);
x86_l_1519:
	/* 0x1519: mov    ecx,DWORD PTR [rsp+0xc4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_1520:
	/* 0x1520: mov    DWORD PTR [rax+0x6],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_1523:
	/* 0x1523: jmp    1581 <tail_nodeport_rev_dnat_egress_ipv6+0x1581> */
	X86_SIM_X86_JMP(0x1523, 0x1581, x86_l_1581);
x86_l_1525:
	/* 0x1525: mov    rdi,QWORD PTR [rip+0x25ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_nodeport_neigh6)));
x86_l_152c:
	/* 0x152c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1531:
	/* 0x1531: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1533:
	/* 0x1533: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1536:
	/* 0x1536: je     1111 <tail_nodeport_rev_dnat_egress_ipv6+0x1111> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1536, 0x1111, x86_l_1111);
x86_l_153c:
	/* 0x153c: mov    rcx,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_153f:
	/* 0x153f: mov    rdx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1543:
	/* 0x1543: lea    rsi,[rcx+0x6] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_1547:
	/* 0x1547: mov    ebp,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967155ULL);
x86_l_154c:
	/* 0x154c: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_154f:
	/* 0x154f: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_1552:
	/* 0x1552: ja     1111 <tail_nodeport_rev_dnat_egress_ipv6+0x1111> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1552, 0x1111, x86_l_1111);
x86_l_1558:
	/* 0x1558: movzx  esi,WORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_155c:
	/* 0x155c: mov    WORD PTR [rcx+0x4],si */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RSI, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1560:
	/* 0x1560: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1562:
	/* 0x1562: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1564:
	/* 0x1564: lea    rax,[rcx+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1568:
	/* 0x1568: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_156b:
	/* 0x156b: ja     1111 <tail_nodeport_rev_dnat_egress_ipv6+0x1111> */
	X86_SIM_X86_JCC(X86_CC_A, 0x156b, 0x1111, x86_l_1111);
x86_l_1571:
	/* 0x1571: movzx  eax,WORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_1576:
	/* 0x1576: mov    WORD PTR [rcx+0xa],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 10ULL);
x86_l_157a:
	/* 0x157a: mov    eax,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_157e:
	/* 0x157e: mov    DWORD PTR [rcx+0x6],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_1581:
	/* 0x1581: cmp    DWORD PTR [rbx+0xc],r15d */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1585:
	/* 0x1585: jne    1591 <tail_nodeport_rev_dnat_egress_ipv6+0x1591> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1585, 0x1591, x86_l_1591);
x86_l_1587:
	/* 0x1587: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_158c:
	/* 0x158c: jmp    126d <tail_nodeport_rev_dnat_egress_ipv6+0x126d> */
	X86_SIM_X86_JMP(0x158c, 0x126d, x86_l_126d);
x86_l_1591:
	/* 0x1591: mov    eax,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 23ULL);
x86_l_1596:
	/* 0x1596: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_1599:
	/* 0x1599: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_159b:
	/* 0x159b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_159d:
	/* 0x159d: mov    ebp,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_159f:
	/* 0x159f: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15a2:
	/* 0x15a2: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_15a4:
	/* 0x15a4: js     1119 <tail_nodeport_rev_dnat_egress_ipv6+0x1119> */
	X86_SIM_X86_JCC(X86_CC_S, 0x15a4, 0x1119, x86_l_1119);
x86_l_15aa:
	/* 0x15aa: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_15ad:
	/* 0x15ad: je     1119 <tail_nodeport_rev_dnat_egress_ipv6+0x1119> */
	X86_SIM_X86_JCC(X86_CC_E, 0x15ad, 0x1119, x86_l_1119);
x86_l_15b3:
	/* 0x15b3: cmp    ebp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_15b6:
	/* 0x15b6: jne    126d <tail_nodeport_rev_dnat_egress_ipv6+0x126d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x15b6, 0x126d, x86_l_126d);
x86_l_15bc:
	/* 0x15bc: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_15c4:
	/* 0x15c4: mov    rdi,QWORD PTR [rip+0x25ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_15cb:
	/* 0x15cb: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_15d0:
	/* 0x15d0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_15d5:
	/* 0x15d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15d7:
	/* 0x15d7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15da:
	/* 0x15da: je     15e3 <tail_nodeport_rev_dnat_egress_ipv6+0x15e3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x15da, 0x15e3, x86_l_15e3);
x86_l_15dc:
	/* 0x15dc: mov    DWORD PTR [rax+0x14],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345921ULL);
x86_l_15e3:
	/* 0x15e3: mov    rsi,QWORD PTR [rip+0x25ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_15ea:
	/* 0x15ea: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_15ef:
	/* 0x15ef: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_15f2:
	/* 0x15f2: mov    edx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_15f7:
	/* 0x15f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15f9:
	/* 0x15f9: mov    ebp,0xffffff74 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967156ULL);
x86_l_15fe:
	/* 0x15fe: mov    r15d,0xa00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 2560ULL);
x86_l_1604:
	/* 0x1604: jmp    1119 <tail_nodeport_rev_dnat_egress_ipv6+0x1119> */
	X86_SIM_X86_JMP(0x1604, 0x1119, x86_l_1119);
x86_l_1609:
	/* 0x1609: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_160b:
	/* 0x160b: jmp    a5a <tail_nodeport_rev_dnat_egress_ipv6+0xa5a> */
	X86_SIM_X86_JMP(0x160b, 0xa5a, x86_l_a5a);
x86_l_1610:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
