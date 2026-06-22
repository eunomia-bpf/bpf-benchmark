extern char __aux_snat_v6_nhm_nat_entry;
extern char __aux_snat_v6_nhm_tuple;
extern char __config_enable_ipv6_fragments;
extern char __config_enable_jiffies;
extern char __config_enable_nodeport_source_lookup;
extern char __config_nodeport_port_max;
extern char __config_router_ipv6;
extern char __config_supports_fib_lookup_skip_neigh;
extern char __config_supports_fib_lookup_src;
extern char __config_trace_payload_len;
extern char _aux_max_off;
extern char _aux_stride;
extern char cilium_calls;
extern char cilium_devices;
extern char cilium_ipcache_v2;
extern char cilium_ipv6_frag_datagrams;
extern char cilium_metrics;
extern char cilium_signals;
extern char cilium_snat_v6_alloc_retries;
extern char cilium_snat_v6_external;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int cilium_bpf_wireguard_tail_nodeport_nat_egress_ipv6_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0x138 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 312ULL);
x86_l_a:
	/* 0xa: mov    QWORD PTR [rsp+0xd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 927712935936ULL);
x86_l_16:
	/* 0x16: mov    DWORD PTR [rsp+0x118],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1202590842880ULL);
x86_l_21:
	/* 0x21: mov    QWORD PTR [rsp+0x110],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1168231104512ULL);
x86_l_2d:
	/* 0x2d: mov    QWORD PTR [rsp+0x108],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1133871366144ULL);
x86_l_39:
	/* 0x39: mov    QWORD PTR [rsp+0x100],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1099511627776ULL);
x86_l_45:
	/* 0x45: mov    QWORD PTR [rsp+0xf8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1065151889408ULL);
x86_l_51:
	/* 0x51: mov    QWORD PTR [rsp+0xf0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1030792151040ULL);
x86_l_5d:
	/* 0x5d: mov    QWORD PTR [rsp+0xe8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 996432412672ULL);
x86_l_69:
	/* 0x69: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_6c:
	/* 0x6c: mov    QWORD PTR [rsp+0xe0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 962072674304ULL);
x86_l_78:
	/* 0x78: mov    BYTE PTR [rsp+0xd8],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 927712935946ULL);
x86_l_80:
	/* 0x80: mov    eax,DWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_83:
	/* 0x83: mov    DWORD PTR [rsp+0xe0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_8a:
	/* 0x8a: mov    QWORD PTR [rsp+0xc8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 858993459200ULL);
x86_l_96:
	/* 0x96: mov    QWORD PTR [rsp+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_a2:
	/* 0xa2: mov    rax,QWORD PTR [rip+0x6247] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_nodeport_port_max)));
x86_l_a9:
	/* 0xa9: movzx  r13d,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_ad:
	/* 0xad: mov    QWORD PTR [rsp+0xa6],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 712964571136ULL);
x86_l_b9:
	/* 0xb9: mov    QWORD PTR [rsp+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_c5:
	/* 0xc5: mov    QWORD PTR [rsp+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_d1:
	/* 0xd1: mov    QWORD PTR [rsp+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_dd:
	/* 0xdd: mov    QWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_e9:
	/* 0xe9: mov    rax,QWORD PTR [rip+0x6247] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_f0:
	/* 0xf0: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f2:
	/* 0xf2: mov    r12d,DWORD PTR [rdi+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_f6:
	/* 0xf6: mov    eax,DWORD PTR [rdi+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_f9:
	/* 0xf9: lea    rcx,[r12+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_fe:
	/* 0xfe: cmp    rcx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_101:
	/* 0x101: jbe    171 <tail_nodeport_nat_egress_ipv6+0x171> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x101, 0x171, x86_l_171);
x86_l_103:
	/* 0x103: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_108:
	/* 0x108: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10b:
	/* 0x10b: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_10d:
	/* 0x10d: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_10f:
	/* 0x10f: cmovs  eax,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RBP, X86_WIDTH_32, X86_CC_S);
x86_l_112:
	/* 0x112: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_115:
	/* 0x115: movzx  ecx,r13b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R13, X86_WIDTH_32, X86_WIDTH_8);
x86_l_119:
	/* 0x119: shl    ecx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_11c:
	/* 0x11c: mov    QWORD PTR [rbx+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_124:
	/* 0x124: or     ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_OR);
x86_l_126:
	/* 0x126: mov    DWORD PTR [rbx+0x38],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_129:
	/* 0x129: movabs rcx,0x54c680200000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 381794426218872832ULL);
x86_l_133:
	/* 0x133: mov    QWORD PTR [rbx+0x3c],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_137:
	/* 0x137: mov    r14d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13a:
	/* 0x13a: movabs rcx,0x68054c0200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 446765466112ULL);
x86_l_144:
	/* 0x144: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_148:
	/* 0x148: mov    BYTE PTR [rsp],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14b:
	/* 0x14b: mov    rdi,QWORD PTR [rip+0x6247] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_152:
	/* 0x152: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_155:
	/* 0x155: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_15a:
	/* 0x15a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15c:
	/* 0x15c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15f:
	/* 0x15f: je     1fb <tail_nodeport_nat_egress_ipv6+0x1fb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x15f, 0x1fb, x86_l_1fb);
x86_l_165:
	/* 0x165: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_168:
	/* 0x168: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_16c:
	/* 0x16c: jmp    221 <tail_nodeport_nat_egress_ipv6+0x221> */
	X86_SIM_X86_JMP(0x16c, 0x221, x86_l_221);
x86_l_171:
	/* 0x171: movzx  ebp,BYTE PTR [r12+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_177:
	/* 0x177: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17a:
	/* 0x17a: mov    BYTE PTR [rsp+0xac],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_182:
	/* 0x182: mov    esi,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 40ULL);
x86_l_187:
	/* 0x187: cmp    rbp,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 60ULL);
x86_l_18b:
	/* 0x18b: ja     608 <tail_nodeport_nat_egress_ipv6+0x608> */
	X86_SIM_X86_JCC(X86_CC_A, 0x18b, 0x608, x86_l_608);
x86_l_191:
	/* 0x191: mov    r15d,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967140ULL);
x86_l_197:
	/* 0x197: movabs rax,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_1a1:
	/* 0x1a1: bt     rax,rbp */
	X86_SIM_L_EXEC_BT(X86_RAX, X86_RBP, X86_WIDTH_64);
x86_l_1a5:
	/* 0x1a5: jae    2e6 <tail_nodeport_nat_egress_ipv6+0x2e6> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x1a5, 0x2e6, x86_l_2e6);
x86_l_1ab:
	/* 0x1ab: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1b0:
	/* 0x1b0: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1b5:
	/* 0x1b5: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1b8:
	/* 0x1b8: mov    esi,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 40ULL);
x86_l_1bd:
	/* 0x1bd: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1c2:
	/* 0x1c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c4:
	/* 0x1c4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1c6:
	/* 0x1c6: js     5d7 <tail_nodeport_nat_egress_ipv6+0x5d7> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1c6, 0x5d7, x86_l_5d7);
x86_l_1cc:
	/* 0x1cc: movzx  r14d,BYTE PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 40ULL);
x86_l_1d2:
	/* 0x1d2: cmp    ebp,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 43ULL);
x86_l_1d5:
	/* 0x1d5: mov    QWORD PTR [rsp+0x80],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1dd:
	/* 0x1dd: jle    242 <tail_nodeport_nat_egress_ipv6+0x242> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x1dd, 0x242, x86_l_242);
x86_l_1df:
	/* 0x1df: cmp    ebp,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_1e2:
	/* 0x1e2: je     242 <tail_nodeport_nat_egress_ipv6+0x242> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1e2, 0x242, x86_l_242);
x86_l_1e4:
	/* 0x1e4: cmp    ebp,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 51ULL);
x86_l_1e7:
	/* 0x1e7: jne    2f5 <tail_nodeport_nat_egress_ipv6+0x2f5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1e7, 0x2f5, x86_l_2f5);
x86_l_1ed:
	/* 0x1ed: movzx  eax,BYTE PTR [rsp+0x29] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 41ULL);
x86_l_1f2:
	/* 0x1f2: lea    esi,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_1f9:
	/* 0x1f9: jmp    25c <tail_nodeport_nat_egress_ipv6+0x25c> */
	X86_SIM_X86_JMP(0x1f9, 0x25c, x86_l_25c);
x86_l_1fb:
	/* 0x1fb: mov    QWORD PTR [rsp+0x28],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691841ULL);
x86_l_204:
	/* 0x204: mov    QWORD PTR [rsp+0x30],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_209:
	/* 0x209: mov    rdi,QWORD PTR [rip+0x6247] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_210:
	/* 0x210: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_213:
	/* 0x213: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_218:
	/* 0x218: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_21d:
	/* 0x21d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_21f:
	/* 0x21f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_221:
	/* 0x221: mov    rsi,QWORD PTR [rip+0x6247] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_228:
	/* 0x228: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_22d:
	/* 0x22d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_230:
	/* 0x230: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_235:
	/* 0x235: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_237:
	/* 0x237: mov    r15d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 2ULL);
x86_l_23d:
	/* 0x23d: jmp    5dd <tail_nodeport_nat_egress_ipv6+0x5dd> */
	X86_SIM_X86_JMP(0x23d, 0x5dd, x86_l_5dd);
x86_l_242:
	/* 0x242: movzx  eax,BYTE PTR [rsp+0x29] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 41ULL);
x86_l_247:
	/* 0x247: lea    esi,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_24e:
	/* 0x24e: cmp    bpl,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 44ULL);
x86_l_252:
	/* 0x252: jne    25c <tail_nodeport_nat_egress_ipv6+0x25c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x252, 0x25c, x86_l_25c);
x86_l_254:
	/* 0x254: mov    r13,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSI, X86_WIDTH_64);
x86_l_257:
	/* 0x257: jmp    2fb <tail_nodeport_nat_egress_ipv6+0x2fb> */
	X86_SIM_X86_JMP(0x257, 0x2fb, x86_l_2fb);
x86_l_25c:
	/* 0x25c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_25e:
	/* 0x25e: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_263:
	/* 0x263: movzx  r13d,r14b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R13, X86_R14, X86_WIDTH_32, X86_WIDTH_8);
x86_l_267:
	/* 0x267: add    esi,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 40ULL);
x86_l_26a:
	/* 0x26a: cmp    r13d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 60ULL);
x86_l_26e:
	/* 0x26e: ja     37f <tail_nodeport_nat_egress_ipv6+0x37f> */
	X86_SIM_X86_JCC(X86_CC_A, 0x26e, 0x37f, x86_l_37f);
x86_l_274:
	/* 0x274: mov    eax,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_277:
	/* 0x277: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_281:
	/* 0x281: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_285:
	/* 0x285: jae    387 <tail_nodeport_nat_egress_ipv6+0x387> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x285, 0x387, x86_l_387);
x86_l_28b:
	/* 0x28b: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_290:
	/* 0x290: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_295:
	/* 0x295: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_298:
	/* 0x298: mov    QWORD PTR [rsp+0x78],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_29d:
	/* 0x29d: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2a2:
	/* 0x2a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a4:
	/* 0x2a4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a6:
	/* 0x2a6: js     5d7 <tail_nodeport_nat_egress_ipv6+0x5d7> */
	X86_SIM_X86_JCC(X86_CC_S, 0x2a6, 0x5d7, x86_l_5d7);
x86_l_2ac:
	/* 0x2ac: movzx  ebp,BYTE PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 40ULL);
x86_l_2b1:
	/* 0x2b1: cmp    r13d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 43ULL);
x86_l_2b5:
	/* 0x2b5: jle    38f <tail_nodeport_nat_egress_ipv6+0x38f> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x2b5, 0x38f, x86_l_38f);
x86_l_2bb:
	/* 0x2bb: cmp    r13d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 44ULL);
x86_l_2bf:
	/* 0x2bf: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_2c4:
	/* 0x2c4: je     3a9 <tail_nodeport_nat_egress_ipv6+0x3a9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2c4, 0x3a9, x86_l_3a9);
x86_l_2ca:
	/* 0x2ca: cmp    r13d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 51ULL);
x86_l_2ce:
	/* 0x2ce: jne    394 <tail_nodeport_nat_egress_ipv6+0x394> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2ce, 0x394, x86_l_394);
x86_l_2d4:
	/* 0x2d4: movzx  eax,BYTE PTR [rsp+0x29] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 41ULL);
x86_l_2d9:
	/* 0x2d9: lea    r13d,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2e1:
	/* 0x2e1: jmp    41f <tail_nodeport_nat_egress_ipv6+0x41f> */
	X86_SIM_X86_JMP(0x2e1, 0x41f, x86_l_41f);
x86_l_2e6:
	/* 0x2e6: cmp    rbp,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 59ULL);
x86_l_2ea:
	/* 0x2ea: je     5dd <tail_nodeport_nat_egress_ipv6+0x5dd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2ea, 0x5dd, x86_l_5dd);
x86_l_2f0:
	/* 0x2f0: jmp    608 <tail_nodeport_nat_egress_ipv6+0x608> */
	X86_SIM_X86_JMP(0x2f0, 0x608, x86_l_608);
x86_l_2f5:
	/* 0x2f5: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_2fb:
	/* 0x2fb: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_304:
	/* 0x304: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_309:
	/* 0x309: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_30e:
	/* 0x30e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_311:
	/* 0x311: mov    esi,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 40ULL);
x86_l_316:
	/* 0x316: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_31b:
	/* 0x31b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31d:
	/* 0x31d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_31f:
	/* 0x31f: js     5d7 <tail_nodeport_nat_egress_ipv6+0x5d7> */
	X86_SIM_X86_JCC(X86_CC_S, 0x31f, 0x5d7, x86_l_5d7);
x86_l_325:
	/* 0x325: mov    eax,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_329:
	/* 0x329: movzx  ecx,BYTE PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 40ULL);
x86_l_32e:
	/* 0x32e: shl    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_332:
	/* 0x332: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_335:
	/* 0x335: movzx  eax,WORD PTR [rsp+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 42ULL);
x86_l_33a:
	/* 0x33a: movabs rdx,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1099511627776ULL);
x86_l_344:
	/* 0x344: or     rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_347:
	/* 0x347: test   eax,0xf9ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63999ULL);
x86_l_34c:
	/* 0x34c: cmove  rdx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_64, X86_CC_E);
x86_l_350:
	/* 0x350: movabs rcx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2199023255552ULL);
x86_l_35a:
	/* 0x35a: or     rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_OR);
x86_l_35d:
	/* 0x35d: test   eax,0xf8ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63743ULL);
x86_l_362:
	/* 0x362: cmove  rcx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_366:
	/* 0x366: mov    QWORD PTR [rsp+0x70],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_36b:
	/* 0x36b: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_36e:
	/* 0x36e: movzx  r13d,r14b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R13, X86_R14, X86_WIDTH_32, X86_WIDTH_8);
x86_l_372:
	/* 0x372: add    esi,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 40ULL);
x86_l_375:
	/* 0x375: cmp    r13d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 60ULL);
x86_l_379:
	/* 0x379: jbe    274 <tail_nodeport_nat_egress_ipv6+0x274> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x379, 0x274, x86_l_274);
x86_l_37f:
	/* 0x37f: mov    ebp,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R14, X86_WIDTH_32);
x86_l_382:
	/* 0x382: jmp    5fb <tail_nodeport_nat_egress_ipv6+0x5fb> */
	X86_SIM_X86_JMP(0x382, 0x5fb, x86_l_5fb);
x86_l_387:
	/* 0x387: mov    ebp,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R14, X86_WIDTH_32);
x86_l_38a:
	/* 0x38a: jmp    48e <tail_nodeport_nat_egress_ipv6+0x48e> */
	X86_SIM_X86_JMP(0x38a, 0x48e, x86_l_48e);
x86_l_38f:
	/* 0x38f: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_394:
	/* 0x394: movzx  eax,BYTE PTR [rsp+0x29] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 41ULL);
x86_l_399:
	/* 0x399: lea    r13d,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_3a1:
	/* 0x3a1: cmp    r14b,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 44ULL);
x86_l_3a5:
	/* 0x3a5: je     3af <tail_nodeport_nat_egress_ipv6+0x3af> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3a5, 0x3af, x86_l_3af);
x86_l_3a7:
	/* 0x3a7: jmp    41f <tail_nodeport_nat_egress_ipv6+0x41f> */
	X86_SIM_X86_JMP(0x3a7, 0x41f, x86_l_41f);
x86_l_3a9:
	/* 0x3a9: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_3af:
	/* 0x3af: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_3b8:
	/* 0x3b8: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3bd:
	/* 0x3bd: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_3c2:
	/* 0x3c2: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_3c5:
	/* 0x3c5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3ca:
	/* 0x3ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3cc:
	/* 0x3cc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3ce:
	/* 0x3ce: js     5d7 <tail_nodeport_nat_egress_ipv6+0x5d7> */
	X86_SIM_X86_JCC(X86_CC_S, 0x3ce, 0x5d7, x86_l_5d7);
x86_l_3d4:
	/* 0x3d4: mov    eax,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_3d8:
	/* 0x3d8: movzx  ecx,BYTE PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 40ULL);
x86_l_3dd:
	/* 0x3dd: shl    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_3e1:
	/* 0x3e1: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_3e4:
	/* 0x3e4: movzx  eax,WORD PTR [rsp+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 42ULL);
x86_l_3e9:
	/* 0x3e9: movabs rdx,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1099511627776ULL);
x86_l_3f3:
	/* 0x3f3: or     rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_3f6:
	/* 0x3f6: test   eax,0xf9ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63999ULL);
x86_l_3fb:
	/* 0x3fb: cmove  rdx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_64, X86_CC_E);
x86_l_3ff:
	/* 0x3ff: movabs rcx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2199023255552ULL);
x86_l_409:
	/* 0x409: or     rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_OR);
x86_l_40c:
	/* 0x40c: test   eax,0xf8ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63743ULL);
x86_l_411:
	/* 0x411: cmove  rcx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_415:
	/* 0x415: mov    QWORD PTR [rsp+0x70],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_41a:
	/* 0x41a: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_41f:
	/* 0x41f: movzx  r14d,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_423:
	/* 0x423: add    esi,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_426:
	/* 0x426: cmp    r14d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 60ULL);
x86_l_42a:
	/* 0x42a: ja     5fb <tail_nodeport_nat_egress_ipv6+0x5fb> */
	X86_SIM_X86_JCC(X86_CC_A, 0x42a, 0x5fb, x86_l_5fb);
x86_l_430:
	/* 0x430: mov    eax,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_32);
x86_l_433:
	/* 0x433: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_43d:
	/* 0x43d: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_441:
	/* 0x441: jae    48e <tail_nodeport_nat_egress_ipv6+0x48e> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x441, 0x48e, x86_l_48e);
x86_l_443:
	/* 0x443: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_448:
	/* 0x448: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_44d:
	/* 0x44d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_450:
	/* 0x450: mov    r13,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSI, X86_WIDTH_64);
x86_l_453:
	/* 0x453: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_458:
	/* 0x458: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_45a:
	/* 0x45a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_45c:
	/* 0x45c: js     5d7 <tail_nodeport_nat_egress_ipv6+0x5d7> */
	X86_SIM_X86_JCC(X86_CC_S, 0x45c, 0x5d7, x86_l_5d7);
x86_l_462:
	/* 0x462: movzx  edx,BYTE PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 40ULL);
x86_l_467:
	/* 0x467: cmp    r14d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 43ULL);
x86_l_46b:
	/* 0x46b: jle    4aa <tail_nodeport_nat_egress_ipv6+0x4aa> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x46b, 0x4aa, x86_l_4aa);
x86_l_46d:
	/* 0x46d: cmp    r14d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 44ULL);
x86_l_471:
	/* 0x471: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_474:
	/* 0x474: je     4c2 <tail_nodeport_nat_egress_ipv6+0x4c2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x474, 0x4c2, x86_l_4c2);
x86_l_476:
	/* 0x476: cmp    r14d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 51ULL);
x86_l_47a:
	/* 0x47a: jne    4ad <tail_nodeport_nat_egress_ipv6+0x4ad> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x47a, 0x4ad, x86_l_4ad);
x86_l_47c:
	/* 0x47c: movzx  eax,BYTE PTR [rsp+0x29] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 41ULL);
x86_l_481:
	/* 0x481: lea    r14d,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_489:
	/* 0x489: jmp    53a <tail_nodeport_nat_egress_ipv6+0x53a> */
	X86_SIM_X86_JMP(0x489, 0x53a, x86_l_53a);
x86_l_48e:
	/* 0x48e: cmp    rax,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 59ULL);
x86_l_492:
	/* 0x492: mov    r14,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_497:
	/* 0x497: mov    r13,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_49f:
	/* 0x49f: je     5dd <tail_nodeport_nat_egress_ipv6+0x5dd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x49f, 0x5dd, x86_l_5dd);
x86_l_4a5:
	/* 0x4a5: jmp    608 <tail_nodeport_nat_egress_ipv6+0x608> */
	X86_SIM_X86_JMP(0x4a5, 0x608, x86_l_608);
x86_l_4aa:
	/* 0x4aa: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_4ad:
	/* 0x4ad: movzx  eax,BYTE PTR [rsp+0x29] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 41ULL);
x86_l_4b2:
	/* 0x4b2: lea    r14d,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_4ba:
	/* 0x4ba: cmp    bpl,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 44ULL);
x86_l_4be:
	/* 0x4be: je     4c8 <tail_nodeport_nat_egress_ipv6+0x4c8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4be, 0x4c8, x86_l_4c8);
x86_l_4c0:
	/* 0x4c0: jmp    53a <tail_nodeport_nat_egress_ipv6+0x53a> */
	X86_SIM_X86_JMP(0x4c0, 0x53a, x86_l_53a);
x86_l_4c2:
	/* 0x4c2: mov    r14d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 8ULL);
x86_l_4c8:
	/* 0x4c8: mov    ebp,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_32);
x86_l_4ca:
	/* 0x4ca: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_4d3:
	/* 0x4d3: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4d8:
	/* 0x4d8: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_4dd:
	/* 0x4dd: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_4e0:
	/* 0x4e0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4e5:
	/* 0x4e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e7:
	/* 0x4e7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4e9:
	/* 0x4e9: js     5d7 <tail_nodeport_nat_egress_ipv6+0x5d7> */
	X86_SIM_X86_JCC(X86_CC_S, 0x4e9, 0x5d7, x86_l_5d7);
x86_l_4ef:
	/* 0x4ef: mov    eax,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_4f3:
	/* 0x4f3: movzx  ecx,BYTE PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 40ULL);
x86_l_4f8:
	/* 0x4f8: shl    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_4fc:
	/* 0x4fc: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_4ff:
	/* 0x4ff: movzx  eax,WORD PTR [rsp+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 42ULL);
x86_l_504:
	/* 0x504: movabs rdx,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1099511627776ULL);
x86_l_50e:
	/* 0x50e: or     rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_511:
	/* 0x511: test   eax,0xf9ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63999ULL);
x86_l_516:
	/* 0x516: cmove  rdx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_64, X86_CC_E);
x86_l_51a:
	/* 0x51a: movabs rcx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2199023255552ULL);
x86_l_524:
	/* 0x524: or     rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_OR);
x86_l_527:
	/* 0x527: test   eax,0xf8ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63743ULL);
x86_l_52c:
	/* 0x52c: cmove  rcx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_530:
	/* 0x530: mov    QWORD PTR [rsp+0x70],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_535:
	/* 0x535: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_538:
	/* 0x538: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_53a:
	/* 0x53a: movzx  ebp,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_53d:
	/* 0x53d: add    esi,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R14, X86_WIDTH_32, X86_ALU_ADD);
x86_l_540:
	/* 0x540: cmp    ebp,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_543:
	/* 0x543: ja     5f9 <tail_nodeport_nat_egress_ipv6+0x5f9> */
	X86_SIM_X86_JCC(X86_CC_A, 0x543, 0x5f9, x86_l_5f9);
x86_l_549:
	/* 0x549: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_54b:
	/* 0x54b: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_555:
	/* 0x555: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_559:
	/* 0x559: mov    r14,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_55e:
	/* 0x55e: mov    r13,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_566:
	/* 0x566: jae    5ef <tail_nodeport_nat_egress_ipv6+0x5ef> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x566, 0x5ef, x86_l_5ef);
x86_l_56c:
	/* 0x56c: mov    r12d,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDX, X86_WIDTH_32);
x86_l_56f:
	/* 0x56f: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_574:
	/* 0x574: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_579:
	/* 0x579: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_57c:
	/* 0x57c: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_57f:
	/* 0x57f: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_584:
	/* 0x584: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_586:
	/* 0x586: mov    r15d,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967162ULL);
x86_l_58c:
	/* 0x58c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_58e:
	/* 0x58e: js     5dd <tail_nodeport_nat_egress_ipv6+0x5dd> */
	X86_SIM_X86_JCC(X86_CC_S, 0x58e, 0x5dd, x86_l_5dd);
x86_l_590:
	/* 0x590: cmp    ebp,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 43ULL);
x86_l_593:
	/* 0x593: jle    59f <tail_nodeport_nat_egress_ipv6+0x59f> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x593, 0x59f, x86_l_59f);
x86_l_595:
	/* 0x595: cmp    ebp,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 44ULL);
x86_l_598:
	/* 0x598: je     5ab <tail_nodeport_nat_egress_ipv6+0x5ab> */
	X86_SIM_X86_JCC(X86_CC_E, 0x598, 0x5ab, x86_l_5ab);
x86_l_59a:
	/* 0x59a: cmp    ebp,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 51ULL);
x86_l_59d:
	/* 0x59d: je     5cf <tail_nodeport_nat_egress_ipv6+0x5cf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x59d, 0x5cf, x86_l_5cf);
x86_l_59f:
	/* 0x59f: mov    r15d,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967140ULL);
x86_l_5a5:
	/* 0x5a5: cmp    r12b,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_8, 44ULL);
x86_l_5a9:
	/* 0x5a9: jne    5dd <tail_nodeport_nat_egress_ipv6+0x5dd> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x5a9, 0x5dd, x86_l_5dd);
x86_l_5ab:
	/* 0x5ab: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_5b4:
	/* 0x5b4: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5b9:
	/* 0x5b9: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_5be:
	/* 0x5be: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_5c1:
	/* 0x5c1: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_5c4:
	/* 0x5c4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5c9:
	/* 0x5c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5cb:
	/* 0x5cb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5cd:
	/* 0x5cd: js     5d7 <tail_nodeport_nat_egress_ipv6+0x5d7> */
	X86_SIM_X86_JCC(X86_CC_S, 0x5cd, 0x5d7, x86_l_5d7);
x86_l_5cf:
	/* 0x5cf: mov    r15d,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967140ULL);
x86_l_5d5:
	/* 0x5d5: jmp    5dd <tail_nodeport_nat_egress_ipv6+0x5dd> */
	X86_SIM_X86_JMP(0x5d5, 0x5dd, x86_l_5dd);
x86_l_5d7:
	/* 0x5d7: mov    r15d,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967162ULL);
x86_l_5dd:
	/* 0x5dd: mov    eax,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_5e0:
	/* 0x5e0: add    rsp,0x138 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 312ULL);
x86_l_5e7:
	/* 0x5e7: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_5e9:
	/* 0x5e9: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_5ea:
	/* 0x5ea: jmp    1d23 <tail_nodeport_nat_egress_ipv6+0x1d23> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_5ef:
	/* 0x5ef: mov    ebp,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_32);
x86_l_5f1:
	/* 0x5f1: cmp    rax,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 59ULL);
x86_l_5f5:
	/* 0x5f5: je     5dd <tail_nodeport_nat_egress_ipv6+0x5dd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5f5, 0x5dd, x86_l_5dd);
x86_l_5f7:
	/* 0x5f7: jmp    608 <tail_nodeport_nat_egress_ipv6+0x608> */
	X86_SIM_X86_JMP(0x5f7, 0x608, x86_l_608);
x86_l_5f9:
	/* 0x5f9: mov    ebp,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDX, X86_WIDTH_32);
x86_l_5fb:
	/* 0x5fb: mov    r14,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_600:
	/* 0x600: mov    r13,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_608:
	/* 0x608: mov    QWORD PTR [rsp+0x78],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_60d:
	/* 0x60d: mov    BYTE PTR [rsp+0xac],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_615:
	/* 0x615: mov    WORD PTR [rsp+0x2e],0x200 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 197568496128ULL);
x86_l_61c:
	/* 0x61c: mov    DWORD PTR [rsp+0x28],0xa0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798692000ULL);
x86_l_624:
	/* 0x624: mov    rax,QWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_629:
	/* 0x629: mov    rcx,QWORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_62e:
	/* 0x62e: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_633:
	/* 0x633: mov    QWORD PTR [rsp+0x38],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_638:
	/* 0x638: mov    WORD PTR [rsp+0x2c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 188978561024ULL);
x86_l_63f:
	/* 0x63f: mov    rdi,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipcache_v2)));
x86_l_646:
	/* 0x646: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_64b:
	/* 0x64b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_650:
	/* 0x650: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_652:
	/* 0x652: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_655:
	/* 0x655: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_658:
	/* 0x658: je     68d <tail_nodeport_nat_egress_ipv6+0x68d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x658, 0x68d, x86_l_68d);
x86_l_65a:
	/* 0x65a: movzx  eax,BYTE PTR [r15+0x17] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 23ULL);
x86_l_65f:
	/* 0x65f: and    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_AND, 3ULL);
x86_l_661:
	/* 0x661: cmp    al,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 2ULL);
x86_l_663:
	/* 0x663: jne    68d <tail_nodeport_nat_egress_ipv6+0x68d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x663, 0x68d, x86_l_68d);
x86_l_665:
	/* 0x665: mov    rax,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_router_ipv6)));
x86_l_66c:
	/* 0x66c: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_66f:
	/* 0x66f: mov    QWORD PTR [rsp+0xc8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_677:
	/* 0x677: mov    rax,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_67b:
	/* 0x67b: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_683:
	/* 0x683: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_688:
	/* 0x688: jmp    777 <tail_nodeport_nat_egress_ipv6+0x777> */
	X86_SIM_X86_JMP(0x688, 0x777, x86_l_777);
x86_l_68d:
	/* 0x68d: mov    rax,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_nodeport_source_lookup)));
x86_l_694:
	/* 0x694: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_697:
	/* 0x697: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_69c:
	/* 0x69c: je     777 <tail_nodeport_nat_egress_ipv6+0x777> */
	X86_SIM_X86_JCC(X86_CC_E, 0x69c, 0x777, x86_l_777);
x86_l_6a2:
	/* 0x6a2: mov    DWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_6aa:
	/* 0x6aa: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_6b3:
	/* 0x6b3: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_6bc:
	/* 0x6bc: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_6c5:
	/* 0x6c5: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_6ce:
	/* 0x6ce: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_6d7:
	/* 0x6d7: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_6e0:
	/* 0x6e0: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_6e9:
	/* 0x6e9: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_6f2:
	/* 0x6f2: mov    rax,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_supports_fib_lookup_src)));
x86_l_6f9:
	/* 0x6f9: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6fc:
	/* 0x6fc: je     777 <tail_nodeport_nat_egress_ipv6+0x777> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6fc, 0x777, x86_l_777);
x86_l_6fe:
	/* 0x6fe: mov    BYTE PTR [rsp+0x28],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691850ULL);
x86_l_703:
	/* 0x703: mov    eax,DWORD PTR [rbx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_706:
	/* 0x706: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_70a:
	/* 0x70a: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_713:
	/* 0x713: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_71c:
	/* 0x71c: mov    rax,QWORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_721:
	/* 0x721: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_726:
	/* 0x726: mov    rax,QWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_72b:
	/* 0x72b: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_730:
	/* 0x730: mov    rax,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_supports_fib_lookup_skip_neigh)));
x86_l_737:
	/* 0x737: movzx  ecx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_73a:
	/* 0x73a: shl    ecx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 2ULL);
x86_l_73d:
	/* 0x73d: or     ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_OR, 16ULL);
x86_l_740:
	/* 0x740: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_745:
	/* 0x745: mov    eax,0x45 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 69ULL);
x86_l_74a:
	/* 0x74a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_74d:
	/* 0x74d: mov    edx,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 64ULL);
x86_l_752:
	/* 0x752: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_754:
	/* 0x754: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_759:
	/* 0x759: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_75b:
	/* 0x75b: jne    777 <tail_nodeport_nat_egress_ipv6+0x777> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x75b, 0x777, x86_l_777);
x86_l_75d:
	/* 0x75d: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_762:
	/* 0x762: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_767:
	/* 0x767: mov    QWORD PTR [rsp+0xc0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_76f:
	/* 0x76f: mov    QWORD PTR [rsp+0xc8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_777:
	/* 0x777: mov    rax,QWORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_77c:
	/* 0x77c: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_784:
	/* 0x784: mov    rax,QWORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_789:
	/* 0x789: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_791:
	/* 0x791: mov    rax,QWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_796:
	/* 0x796: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_79e:
	/* 0x79e: mov    rax,QWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7a3:
	/* 0x7a3: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_7ab:
	/* 0x7ab: movzx  eax,BYTE PTR [rsp+0xac] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 172ULL);
x86_l_7b3:
	/* 0x7b3: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_7b6:
	/* 0x7b6: je     7ca <tail_nodeport_nat_egress_ipv6+0x7ca> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7b6, 0x7ca, x86_l_7ca);
x86_l_7b8:
	/* 0x7b8: cmp    eax,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 58ULL);
x86_l_7bb:
	/* 0x7bb: je     84c <tail_nodeport_nat_egress_ipv6+0x84c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7bb, 0x84c, x86_l_84c);
x86_l_7c1:
	/* 0x7c1: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_7c4:
	/* 0x7c4: jne    859 <tail_nodeport_nat_egress_ipv6+0x859> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x7c4, 0x859, x86_l_859);
x86_l_7ca:
	/* 0x7ca: mov    QWORD PTR [rsp+0x120],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_7d2:
	/* 0x7d2: mov    r15,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_64);
x86_l_7d5:
	/* 0x7d5: movabs rdx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 2199023255552ULL);
x86_l_7df:
	/* 0x7df: lea    r13,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_7e7:
	/* 0x7e7: mov    rax,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_7ee:
	/* 0x7ee: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7f1:
	/* 0x7f1: je     863 <tail_nodeport_nat_egress_ipv6+0x863> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7f1, 0x863, x86_l_863);
x86_l_7f3:
	/* 0x7f3: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_7f6:
	/* 0x7f6: mov    r14,QWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7fa:
	/* 0x7fa: mov    QWORD PTR [r12],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_802:
	/* 0x802: mov    DWORD PTR [r12],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_806:
	/* 0x806: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_809:
	/* 0x809: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_80d:
	/* 0x80d: mov    BYTE PTR [r12+0x4],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_812:
	/* 0x812: mov    rbp,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RCX, X86_WIDTH_64);
x86_l_815:
	/* 0x815: test   rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_818:
	/* 0x818: jne    159b <tail_nodeport_nat_egress_ipv6+0x159b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x818, 0x159b, x86_l_159b);
x86_l_81e:
	/* 0x81e: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_823:
	/* 0x823: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_826:
	/* 0x826: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_829:
	/* 0x829: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_82e:
	/* 0x82e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_830:
	/* 0x830: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_832:
	/* 0x832: js     8ee <tail_nodeport_nat_egress_ipv6+0x8ee> */
	X86_SIM_X86_JCC(X86_CC_S, 0x832, 0x8ee, x86_l_8ee);
x86_l_838:
	/* 0x838: bt     rbp,0x28 */
	X86_SIM_L_EXEC_BT_IMM(X86_RBP, X86_WIDTH_64, 40ULL);
x86_l_83d:
	/* 0x83d: jb     15d1 <tail_nodeport_nat_egress_ipv6+0x15d1> */
	X86_SIM_X86_JCC(X86_CC_B, 0x83d, 0x15d1, x86_l_15d1);
x86_l_843:
	/* 0x843: mov    QWORD PTR [r12],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_847:
	/* 0x847: mov    r14,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RBP, X86_WIDTH_64);
x86_l_84a:
	/* 0x84a: jmp    886 <tail_nodeport_nat_egress_ipv6+0x886> */
	X86_SIM_X86_JMP(0x84a, 0x886, x86_l_886);
x86_l_84c:
	/* 0x84c: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_84f:
	/* 0x84f: mov    ebp,0xffffff61 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967137ULL);
x86_l_854:
	/* 0x854: jmp    10b <tail_nodeport_nat_egress_ipv6+0x10b> */
	X86_SIM_X86_JMP(0x854, 0x10b, x86_l_10b);
x86_l_859:
	/* 0x859: mov    ebp,0xffffff72 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967154ULL);
x86_l_85e:
	/* 0x85e: jmp    108 <tail_nodeport_nat_egress_ipv6+0x108> */
	X86_SIM_X86_JMP(0x85e, 0x108, x86_l_108);
x86_l_863:
	/* 0x863: test   r14,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_RDX, X86_WIDTH_64);
x86_l_866:
	/* 0x866: jne    1634 <tail_nodeport_nat_egress_ipv6+0x1634> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x866, 0x1634, x86_l_1634);
x86_l_86c:
	/* 0x86c: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_871:
	/* 0x871: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_874:
	/* 0x874: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_877:
	/* 0x877: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_87c:
	/* 0x87c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_87e:
	/* 0x87e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_880:
	/* 0x880: js     bfc <tail_nodeport_nat_egress_ipv6+0xbfc> */
	X86_SIM_X86_JCC(X86_CC_S, 0x880, 0xbfc, x86_l_bfc);
x86_l_886:
	/* 0x886: rol    DWORD PTR [rsp+0xa8],0x10 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_32, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_ROL)), 721554505744ULL);
x86_l_88e:
	/* 0x88e: mov    BYTE PTR [rsp+0xad],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 743029342208ULL);
x86_l_896:
	/* 0x896: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_89b:
	/* 0x89b: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_8a0:
	/* 0x8a0: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_8a3:
	/* 0x8a3: mov    esi,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 7ULL);
x86_l_8a8:
	/* 0x8a8: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_8ad:
	/* 0x8ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8af:
	/* 0x8af: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_8b1:
	/* 0x8b1: js     103 <tail_nodeport_nat_egress_ipv6+0x103> */
	X86_SIM_X86_JCC(X86_CC_S, 0x8b1, 0x103, x86_l_103);
x86_l_8b7:
	/* 0x8b7: movzx  eax,BYTE PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 40ULL);
x86_l_8bc:
	/* 0x8bc: cmp    al,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 2ULL);
x86_l_8be:
	/* 0x8be: jae    8fc <tail_nodeport_nat_egress_ipv6+0x8fc> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x8be, 0x8fc, x86_l_8fc);
x86_l_8c0:
	/* 0x8c0: movabs rax,0x200000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934592ULL);
x86_l_8ca:
	/* 0x8ca: mov    QWORD PTR [rbx+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_8ce:
	/* 0x8ce: mov    rsi,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_8d5:
	/* 0x8d5: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_8da:
	/* 0x8da: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_8dd:
	/* 0x8dd: mov    edx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_8e2:
	/* 0x8e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8e4:
	/* 0x8e4: mov    ebp,0xffffff74 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967156ULL);
x86_l_8e9:
	/* 0x8e9: jmp    108 <tail_nodeport_nat_egress_ipv6+0x108> */
	X86_SIM_X86_JMP(0x8e9, 0x108, x86_l_108);
x86_l_8ee:
	/* 0x8ee: mov    ebp,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967161ULL);
x86_l_8f3:
	/* 0x8f3: mov    QWORD PTR [r12],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8f7:
	/* 0x8f7: jmp    108 <tail_nodeport_nat_egress_ipv6+0x108> */
	X86_SIM_X86_JMP(0x8f7, 0x108, x86_l_108);
x86_l_8fc:
	/* 0x8fc: dec    al */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_DEC, 1);
x86_l_8fe:
	/* 0x8fe: mov    BYTE PTR [rsp+0x28],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_902:
	/* 0x902: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_907:
	/* 0x907: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_90c:
	/* 0x90c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_90f:
	/* 0x90f: mov    esi,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 7ULL);
x86_l_914:
	/* 0x914: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_919:
	/* 0x919: mov    r8d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 1ULL);
x86_l_91f:
	/* 0x91f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_921:
	/* 0x921: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_923:
	/* 0x923: js     c06 <tail_nodeport_nat_egress_ipv6+0xc06> */
	X86_SIM_X86_JCC(X86_CC_S, 0x923, 0xc06, x86_l_c06);
x86_l_929:
	/* 0x929: mov    rdi,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_930:
	/* 0x930: lea    rsi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_938:
	/* 0x938: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_93d:
	/* 0x93d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_93f:
	/* 0x93f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_942:
	/* 0x942: mov    QWORD PTR [rsp+0x70],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_947:
	/* 0x947: je     a5c <tail_nodeport_nat_egress_ipv6+0xa5c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x947, 0xa5c, x86_l_a5c);
x86_l_94d:
	/* 0x94d: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_950:
	/* 0x950: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_955:
	/* 0x955: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_957:
	/* 0x957: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_959:
	/* 0x959: mov    r13,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&_aux_stride)));
x86_l_960:
	/* 0x960: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_962:
	/* 0x962: imul   rax,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_967:
	/* 0x967: mov    r14,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&_aux_max_off)));
x86_l_96e:
	/* 0x96e: cmp    rax,QWORD PTR [r14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_971:
	/* 0x971: jbe    976 <tail_nodeport_nat_egress_ipv6+0x976> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x971, 0x976, x86_l_976);
x86_l_973:
	/* 0x973: mov    rax,QWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_976:
	/* 0x976: mov    rcx,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__aux_snat_v6_nhm_tuple)));
x86_l_97d:
	/* 0x97d: mov    BYTE PTR [rcx+rax*1+0x25],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 158913789953ULL);
x86_l_982:
	/* 0x982: movzx  edx,BYTE PTR [rsp+0xac] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 172ULL);
x86_l_98a:
	/* 0x98a: mov    BYTE PTR [rcx+rax*1+0x24],dl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 36ULL);
x86_l_98e:
	/* 0x98e: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_996:
	/* 0x996: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_99e:
	/* 0x99e: mov    QWORD PTR [rcx+rax*1+0x10],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 16ULL);
x86_l_9a3:
	/* 0x9a3: mov    QWORD PTR [rcx+rax*1+0x18],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 24ULL);
x86_l_9a8:
	/* 0x9a8: mov    rdx,QWORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9ad:
	/* 0x9ad: mov    rsi,QWORD PTR [r12+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_9b2:
	/* 0x9b2: mov    QWORD PTR [rcx+rax*1],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_9b6:
	/* 0x9b6: mov    QWORD PTR [rcx+rax*1+0x8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 8ULL);
x86_l_9bb:
	/* 0x9bb: movzx  edx,WORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 168ULL);
x86_l_9c3:
	/* 0x9c3: mov    WORD PTR [rcx+rax*1+0x22],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 0), 34ULL);
x86_l_9c8:
	/* 0x9c8: movzx  edx,WORD PTR [r12+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_9ce:
	/* 0x9ce: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_9d1:
	/* 0x9d1: lea    r12,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_9d5:
	/* 0x9d5: mov    WORD PTR [rcx+rax*1+0x20],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 0), 32ULL);
x86_l_9da:
	/* 0x9da: mov    rax,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_9e2:
	/* 0x9e2: cmp    rax,QWORD PTR [rsi+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_9e6:
	/* 0x9e6: mov    QWORD PTR [rsp+0xb8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_9ee:
	/* 0x9ee: jne    a09 <tail_nodeport_nat_egress_ipv6+0xa09> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x9ee, 0xa09, x86_l_a09);
x86_l_9f0:
	/* 0x9f0: mov    rax,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_9f8:
	/* 0x9f8: cmp    rax,QWORD PTR [rsi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_9fc:
	/* 0x9fc: jne    a09 <tail_nodeport_nat_egress_ipv6+0xa09> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x9fc, 0xa09, x86_l_a09);
x86_l_9fe:
	/* 0x9fe: cmp    QWORD PTR [rsi+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_a03:
	/* 0xa03: je     141f <tail_nodeport_nat_egress_ipv6+0x141f> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa03, 0x141f, x86_l_141f);
x86_l_a09:
	/* 0xa09: mov    rdi,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_a10:
	/* 0xa10: lea    rsi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_a18:
	/* 0xa18: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_a1d:
	/* 0xa1d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a1f:
	/* 0xa1f: mov    ebp,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_a21:
	/* 0xa21: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a24:
	/* 0xa24: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a26:
	/* 0xa26: js     17e2 <tail_nodeport_nat_egress_ipv6+0x17e2> */
	X86_SIM_X86_JCC(X86_CC_S, 0xa26, 0x17e2, x86_l_17e2);
x86_l_a2c:
	/* 0xa2c: cmp    ebp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_a2f:
	/* 0xa2f: je     17e2 <tail_nodeport_nat_egress_ipv6+0x17e2> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa2f, 0x17e2, x86_l_17e2);
x86_l_a35:
	/* 0xa35: mov    rdi,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_a3c:
	/* 0xa3c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a41:
	/* 0xa41: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_a44:
	/* 0xa44: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a46:
	/* 0xa46: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a49:
	/* 0xa49: je     a5c <tail_nodeport_nat_egress_ipv6+0xa5c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa49, 0xa5c, x86_l_a5c);
x86_l_a4b:
	/* 0xa4b: mov    rdi,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_a52:
	/* 0xa52: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_a57:
	/* 0xa57: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_a5a:
	/* 0xa5a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a5c:
	/* 0xa5c: mov    r13,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R15, X86_WIDTH_64);
x86_l_a5f:
	/* 0xa5f: lea    ebp,[r15+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_a63:
	/* 0xa63: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a68:
	/* 0xa68: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a6a:
	/* 0xa6a: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_a6c:
	/* 0xa6c: mov    rcx,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&_aux_stride)));
x86_l_a73:
	/* 0xa73: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a75:
	/* 0xa75: imul   rax,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_a79:
	/* 0xa79: mov    rcx,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&_aux_max_off)));
x86_l_a80:
	/* 0xa80: cmp    rax,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_a83:
	/* 0xa83: jbe    a88 <tail_nodeport_nat_egress_ipv6+0xa88> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xa83, 0xa88, x86_l_a88);
x86_l_a85:
	/* 0xa85: mov    rax,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a88:
	/* 0xa88: mov    rcx,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__aux_snat_v6_nhm_nat_entry)));
x86_l_a8f:
	/* 0xa8f: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_a98:
	/* 0xa98: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_aa1:
	/* 0xaa1: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_aaa:
	/* 0xaaa: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_ab3:
	/* 0xab3: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_abc:
	/* 0xabc: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_ac5:
	/* 0xac5: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_ace:
	/* 0xace: mov    QWORD PTR [rcx+rax*1],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_ad6:
	/* 0xad6: mov    QWORD PTR [rcx+rax*1+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 34359738368ULL);
x86_l_adf:
	/* 0xadf: mov    QWORD PTR [rcx+rax*1+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 68719476736ULL);
x86_l_ae8:
	/* 0xae8: mov    QWORD PTR [rcx+rax*1+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 103079215104ULL);
x86_l_af1:
	/* 0xaf1: mov    QWORD PTR [rcx+rax*1+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 137438953472ULL);
x86_l_afa:
	/* 0xafa: mov    QWORD PTR [rcx+rax*1+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 171798691840ULL);
x86_l_b03:
	/* 0xb03: mov    QWORD PTR [rcx+rax*1+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 206158430208ULL);
x86_l_b0c:
	/* 0xb0c: lea    rsi,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_b14:
	/* 0xb14: mov    rdx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b17:
	/* 0xb17: mov    rsi,QWORD PTR [rsi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b1b:
	/* 0xb1b: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_b20:
	/* 0xb20: mov    QWORD PTR [rsp+0x50],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_b25:
	/* 0xb25: movzx  r14d,WORD PTR [rsp+0xaa] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 170ULL);
x86_l_b2e:
	/* 0xb2e: mov    WORD PTR [rsp+0x58],r14w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_b34:
	/* 0xb34: mov    rdx,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_b3c:
	/* 0xb3c: mov    QWORD PTR [rcx+rax*1+0x20],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 32ULL);
x86_l_b41:
	/* 0xb41: mov    rsi,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_b49:
	/* 0xb49: mov    QWORD PTR [rcx+rax*1+0x28],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 40ULL);
x86_l_b4e:
	/* 0xb4e: mov    BYTE PTR [rsp+0x25],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 158913789953ULL);
x86_l_b53:
	/* 0xb53: movzx  edi,BYTE PTR [rsp+0xac] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 172ULL);
x86_l_b5b:
	/* 0xb5b: mov    BYTE PTR [rsp+0x24],dil */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_b60:
	/* 0xb60: mov    rdi,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_b68:
	/* 0xb68: mov    QWORD PTR [rsp+0x10],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b6d:
	/* 0xb6d: mov    rdi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_b75:
	/* 0xb75: mov    QWORD PTR [rsp+0x18],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b7a:
	/* 0xb7a: mov    QWORD PTR [rsp+0x8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b7f:
	/* 0xb7f: mov    QWORD PTR [rsp],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b83:
	/* 0xb83: movzx  edx,WORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 168ULL);
x86_l_b8b:
	/* 0xb8b: mov    WORD PTR [rsp+0x22],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_b90:
	/* 0xb90: lea    r12,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_b94:
	/* 0xb94: mov    WORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_b9b:
	/* 0xb9b: rol    r14w,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_ba0:
	/* 0xba0: cmp    r14w,bp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R14, X86_RBP, X86_WIDTH_16);
x86_l_ba4:
	/* 0xba4: jae    bc7 <tail_nodeport_nat_egress_ipv6+0xbc7> */
	X86_SIM_X86_JCC(X86_CC_AE, 0xba4, 0xbc7, x86_l_bc7);
x86_l_ba6:
	/* 0xba6: mov    ecx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_bab:
	/* 0xbab: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bad:
	/* 0xbad: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_baf:
	/* 0xbaf: mov    ecx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_32);
x86_l_bb2:
	/* 0xbb2: xor    ecx,0xffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 65535ULL);
x86_l_bb8:
	/* 0xbb8: movzx  r14d,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_bbc:
	/* 0xbbc: imul   r14d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_bc0:
	/* 0xbc0: shr    r14d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_bc4:
	/* 0xbc4: add    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_bc7:
	/* 0xbc7: mov    QWORD PTR [r12+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_bd0:
	/* 0xbd0: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_bd9:
	/* 0xbd9: mov    rax,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_be0:
	/* 0xbe0: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_be3:
	/* 0xbe3: mov    QWORD PTR [rsp+0xb8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_beb:
	/* 0xbeb: je     c10 <tail_nodeport_nat_egress_ipv6+0xc10> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbeb, 0xc10, x86_l_c10);
x86_l_bed:
	/* 0xbed: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_bf2:
	/* 0xbf2: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bf4:
	/* 0xbf4: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_bf6:
	/* 0xbf6: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_bfa:
	/* 0xbfa: jmp    c33 <tail_nodeport_nat_egress_ipv6+0xc33> */
	X86_SIM_X86_JMP(0xbfa, 0xc33, x86_l_c33);
x86_l_bfc:
	/* 0xbfc: mov    ebp,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967161ULL);
x86_l_c01:
	/* 0xc01: jmp    108 <tail_nodeport_nat_egress_ipv6+0x108> */
	X86_SIM_X86_JMP(0xc01, 0x108, x86_l_108);
x86_l_c06:
	/* 0xc06: mov    ebp,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967155ULL);
x86_l_c0b:
	/* 0xc0b: jmp    108 <tail_nodeport_nat_egress_ipv6+0x108> */
	X86_SIM_X86_JMP(0xc0b, 0x108, x86_l_108);
x86_l_c10:
	/* 0xc10: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_c15:
	/* 0xc15: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c17:
	/* 0xc17: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_c19:
	/* 0xc19: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_c1d:
	/* 0xc1d: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_c27:
	/* 0xc27: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_c2a:
	/* 0xc2a: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_c2f:
	/* 0xc2f: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_c33:
	/* 0xc33: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c38:
	/* 0xc38: movbe  WORD PTR [rsp+0x20],r14w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_c40:
	/* 0xc40: mov    rdi,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_c47:
	/* 0xc47: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_c4a:
	/* 0xc4a: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c4f:
	/* 0xc4f: mov    r13d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 1ULL);
x86_l_c55:
	/* 0xc55: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_c5b:
	/* 0xc5b: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_c60:
	/* 0xc60: call   r12 */
	X86_SIM_BPF_CALL_REG(X86_R12);
x86_l_c63:
	/* 0xc63: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c65:
	/* 0xc65: je     13f8 <tail_nodeport_nat_egress_ipv6+0x13f8> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc65, 0x13f8, x86_l_13f8);
x86_l_c6b:
	/* 0xc6b: mov    eax,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967294ULL);
x86_l_c70:
	/* 0xc70: sub    eax,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_32, X86_ALU_SUB);
x86_l_c73:
	/* 0xc73: movzx  r15d,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_c77:
	/* 0xc77: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_c7a:
	/* 0xc7a: mov    ecx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_c7f:
	/* 0xc7f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c81:
	/* 0xc81: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_c83:
	/* 0xc83: movzx  r14d,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_c87:
	/* 0xc87: imul   r14d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_c8b:
	/* 0xc8b: shr    r14d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_c8f:
	/* 0xc8f: add    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_c92:
	/* 0xc92: movbe  WORD PTR [rsp+0x20],r14w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_c9a:
	/* 0xc9a: mov    rdi,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_ca1:
	/* 0xca1: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_ca4:
	/* 0xca4: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_ca9:
	/* 0xca9: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_cae:
	/* 0xcae: call   r12 */
	X86_SIM_BPF_CALL_REG(X86_R12);
x86_l_cb1:
	/* 0xcb1: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_cb4:
	/* 0xcb4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_cb6:
	/* 0xcb6: je     172f <tail_nodeport_nat_egress_ipv6+0x172f> */
	X86_SIM_X86_JCC(X86_CC_E, 0xcb6, 0x172f, x86_l_172f);
x86_l_cbc:
	/* 0xcbc: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_cbf:
	/* 0xcbf: movzx  r14d,r14w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_R14, X86_WIDTH_32, X86_WIDTH_16);
x86_l_cc3:
	/* 0xcc3: imul   r14d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_cc7:
	/* 0xcc7: shr    r14d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_ccb:
	/* 0xccb: add    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_cce:
	/* 0xcce: movbe  WORD PTR [rsp+0x20],r14w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_cd6:
	/* 0xcd6: mov    rdi,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_cdd:
	/* 0xcdd: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_ce0:
	/* 0xce0: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_ce5:
	/* 0xce5: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_ceb:
	/* 0xceb: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_cf0:
	/* 0xcf0: call   r12 */
	X86_SIM_BPF_CALL_REG(X86_R12);
x86_l_cf3:
	/* 0xcf3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_cf5:
	/* 0xcf5: je     1403 <tail_nodeport_nat_egress_ipv6+0x1403> */
	X86_SIM_X86_JCC(X86_CC_E, 0xcf5, 0x1403, x86_l_1403);
x86_l_cfb:
	/* 0xcfb: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_cfe:
	/* 0xcfe: movzx  r14d,r14w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_R14, X86_WIDTH_32, X86_WIDTH_16);
x86_l_d02:
	/* 0xd02: imul   r14d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_d06:
	/* 0xd06: shr    r14d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_d0a:
	/* 0xd0a: add    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_d0d:
	/* 0xd0d: movbe  WORD PTR [rsp+0x20],r14w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_d15:
	/* 0xd15: mov    rdi,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_d1c:
	/* 0xd1c: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_d1f:
	/* 0xd1f: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_d24:
	/* 0xd24: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_d29:
	/* 0xd29: call   r12 */
	X86_SIM_BPF_CALL_REG(X86_R12);
x86_l_d2c:
	/* 0xd2c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_d2e:
	/* 0xd2e: je     1411 <tail_nodeport_nat_egress_ipv6+0x1411> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd2e, 0x1411, x86_l_1411);
x86_l_d34:
	/* 0xd34: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_d37:
	/* 0xd37: movzx  r14d,r14w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_R14, X86_WIDTH_32, X86_WIDTH_16);
x86_l_d3b:
	/* 0xd3b: imul   r14d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_d3f:
	/* 0xd3f: shr    r14d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_d43:
	/* 0xd43: add    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_d46:
	/* 0xd46: movbe  WORD PTR [rsp+0x20],r14w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_d4e:
	/* 0xd4e: mov    rdi,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_d55:
	/* 0xd55: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_d58:
	/* 0xd58: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_d5d:
	/* 0xd5d: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_d63:
	/* 0xd63: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_d68:
	/* 0xd68: call   r12 */
	X86_SIM_BPF_CALL_REG(X86_R12);
x86_l_d6b:
	/* 0xd6b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_d6d:
	/* 0xd6d: je     14db <tail_nodeport_nat_egress_ipv6+0x14db> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd6d, 0x14db, x86_l_14db);
x86_l_d73:
	/* 0xd73: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_d76:
	/* 0xd76: movzx  r14d,r14w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_R14, X86_WIDTH_32, X86_WIDTH_16);
x86_l_d7a:
	/* 0xd7a: imul   r14d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_d7e:
	/* 0xd7e: shr    r14d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_d82:
	/* 0xd82: add    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_d85:
	/* 0xd85: movbe  WORD PTR [rsp+0x20],r14w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_d8d:
	/* 0xd8d: mov    rdi,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_d94:
	/* 0xd94: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_d97:
	/* 0xd97: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_d9c:
	/* 0xd9c: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_da1:
	/* 0xda1: call   r12 */
	X86_SIM_BPF_CALL_REG(X86_R12);
x86_l_da4:
	/* 0xda4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_da6:
	/* 0xda6: je     14e9 <tail_nodeport_nat_egress_ipv6+0x14e9> */
	X86_SIM_X86_JCC(X86_CC_E, 0xda6, 0x14e9, x86_l_14e9);
x86_l_dac:
	/* 0xdac: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_daf:
	/* 0xdaf: movzx  r14d,r14w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_R14, X86_WIDTH_32, X86_WIDTH_16);
x86_l_db3:
	/* 0xdb3: imul   r14d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_db7:
	/* 0xdb7: shr    r14d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_dbb:
	/* 0xdbb: add    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_dbe:
	/* 0xdbe: movbe  WORD PTR [rsp+0x20],r14w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_dc6:
	/* 0xdc6: mov    rdi,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_dcd:
	/* 0xdcd: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_dd0:
	/* 0xdd0: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_dd5:
	/* 0xdd5: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_ddb:
	/* 0xddb: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_de0:
	/* 0xde0: call   r12 */
	X86_SIM_BPF_CALL_REG(X86_R12);
x86_l_de3:
	/* 0xde3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_de5:
	/* 0xde5: je     14f7 <tail_nodeport_nat_egress_ipv6+0x14f7> */
	X86_SIM_X86_JCC(X86_CC_E, 0xde5, 0x14f7, x86_l_14f7);
x86_l_deb:
	/* 0xdeb: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_dee:
	/* 0xdee: movzx  r14d,r14w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_R14, X86_WIDTH_32, X86_WIDTH_16);
x86_l_df2:
	/* 0xdf2: imul   r14d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_df6:
	/* 0xdf6: shr    r14d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_dfa:
	/* 0xdfa: add    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_dfd:
	/* 0xdfd: movbe  WORD PTR [rsp+0x20],r14w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_e05:
	/* 0xe05: mov    rdi,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_e0c:
	/* 0xe0c: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_e0f:
	/* 0xe0f: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_e14:
	/* 0xe14: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_e19:
	/* 0xe19: call   r12 */
	X86_SIM_BPF_CALL_REG(X86_R12);
x86_l_e1c:
	/* 0xe1c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_e1e:
	/* 0xe1e: je     1505 <tail_nodeport_nat_egress_ipv6+0x1505> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe1e, 0x1505, x86_l_1505);
x86_l_e24:
	/* 0xe24: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_e27:
	/* 0xe27: movzx  r14d,r14w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_R14, X86_WIDTH_32, X86_WIDTH_16);
x86_l_e2b:
	/* 0xe2b: imul   r14d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_e2f:
	/* 0xe2f: shr    r14d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_e33:
	/* 0xe33: add    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_e36:
	/* 0xe36: movbe  WORD PTR [rsp+0x20],r14w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_e3e:
	/* 0xe3e: mov    rdi,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_e45:
	/* 0xe45: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_e48:
	/* 0xe48: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_e4d:
	/* 0xe4d: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_e53:
	/* 0xe53: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_e58:
	/* 0xe58: call   r12 */
	X86_SIM_BPF_CALL_REG(X86_R12);
x86_l_e5b:
	/* 0xe5b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_e5d:
	/* 0xe5d: je     1571 <tail_nodeport_nat_egress_ipv6+0x1571> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe5d, 0x1571, x86_l_1571);
x86_l_e63:
	/* 0xe63: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_e66:
	/* 0xe66: movzx  r14d,r14w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_R14, X86_WIDTH_32, X86_WIDTH_16);
x86_l_e6a:
	/* 0xe6a: imul   r14d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_e6e:
	/* 0xe6e: shr    r14d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_e72:
	/* 0xe72: add    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_e75:
	/* 0xe75: movbe  WORD PTR [rsp+0x20],r14w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_e7d:
	/* 0xe7d: mov    rdi,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_e84:
	/* 0xe84: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_e87:
	/* 0xe87: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_e8c:
	/* 0xe8c: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_e91:
	/* 0xe91: call   r12 */
	X86_SIM_BPF_CALL_REG(X86_R12);
x86_l_e94:
	/* 0xe94: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_e96:
	/* 0xe96: je     157f <tail_nodeport_nat_egress_ipv6+0x157f> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe96, 0x157f, x86_l_157f);
x86_l_e9c:
	/* 0xe9c: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_e9f:
	/* 0xe9f: movzx  r14d,r14w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_R14, X86_WIDTH_32, X86_WIDTH_16);
x86_l_ea3:
	/* 0xea3: imul   r14d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_ea7:
	/* 0xea7: shr    r14d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_eab:
	/* 0xeab: add    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_eae:
	/* 0xeae: movbe  WORD PTR [rsp+0x20],r14w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_eb6:
	/* 0xeb6: mov    rdi,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_ebd:
	/* 0xebd: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_ec0:
	/* 0xec0: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_ec5:
	/* 0xec5: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_ecb:
	/* 0xecb: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_ed0:
	/* 0xed0: call   r12 */
	X86_SIM_BPF_CALL_REG(X86_R12);
x86_l_ed3:
	/* 0xed3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ed5:
	/* 0xed5: je     158d <tail_nodeport_nat_egress_ipv6+0x158d> */
	X86_SIM_X86_JCC(X86_CC_E, 0xed5, 0x158d, x86_l_158d);
x86_l_edb:
	/* 0xedb: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_ede:
	/* 0xede: movzx  r14d,r14w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_R14, X86_WIDTH_32, X86_WIDTH_16);
x86_l_ee2:
	/* 0xee2: imul   r14d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_ee6:
	/* 0xee6: shr    r14d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_eea:
	/* 0xeea: add    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_eed:
	/* 0xeed: movbe  WORD PTR [rsp+0x20],r14w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_ef5:
	/* 0xef5: mov    rdi,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_efc:
	/* 0xefc: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_eff:
	/* 0xeff: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_f04:
	/* 0xf04: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_f09:
	/* 0xf09: call   r12 */
	X86_SIM_BPF_CALL_REG(X86_R12);
x86_l_f0c:
	/* 0xf0c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_f0e:
	/* 0xf0e: je     15c3 <tail_nodeport_nat_egress_ipv6+0x15c3> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf0e, 0x15c3, x86_l_15c3);
x86_l_f14:
	/* 0xf14: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_f17:
	/* 0xf17: movzx  r14d,r14w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_R14, X86_WIDTH_32, X86_WIDTH_16);
x86_l_f1b:
	/* 0xf1b: imul   r14d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_f1f:
	/* 0xf1f: shr    r14d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_f23:
	/* 0xf23: add    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_f26:
	/* 0xf26: movbe  WORD PTR [rsp+0x20],r14w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_f2e:
	/* 0xf2e: mov    rdi,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_f35:
	/* 0xf35: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_f38:
	/* 0xf38: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_f3d:
	/* 0xf3d: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_f43:
	/* 0xf43: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_f48:
	/* 0xf48: call   r12 */
	X86_SIM_BPF_CALL_REG(X86_R12);
x86_l_f4b:
	/* 0xf4b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_f4d:
	/* 0xf4d: je     163e <tail_nodeport_nat_egress_ipv6+0x163e> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf4d, 0x163e, x86_l_163e);
x86_l_f53:
	/* 0xf53: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_f56:
	/* 0xf56: movzx  r14d,r14w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_R14, X86_WIDTH_32, X86_WIDTH_16);
x86_l_f5a:
	/* 0xf5a: imul   r14d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_f5e:
	/* 0xf5e: shr    r14d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_f62:
	/* 0xf62: add    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_f65:
	/* 0xf65: movbe  WORD PTR [rsp+0x20],r14w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_f6d:
	/* 0xf6d: mov    rdi,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_f74:
	/* 0xf74: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_f77:
	/* 0xf77: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_f7c:
	/* 0xf7c: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_f81:
	/* 0xf81: call   r12 */
	X86_SIM_BPF_CALL_REG(X86_R12);
x86_l_f84:
	/* 0xf84: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_f86:
	/* 0xf86: je     1656 <tail_nodeport_nat_egress_ipv6+0x1656> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf86, 0x1656, x86_l_1656);
x86_l_f8c:
	/* 0xf8c: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_f8f:
	/* 0xf8f: movzx  r14d,r14w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_R14, X86_WIDTH_32, X86_WIDTH_16);
x86_l_f93:
	/* 0xf93: imul   r14d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_f97:
	/* 0xf97: shr    r14d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_f9b:
	/* 0xf9b: add    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_f9e:
	/* 0xf9e: movbe  WORD PTR [rsp+0x20],r14w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_fa6:
	/* 0xfa6: mov    rdi,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_fad:
	/* 0xfad: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_fb0:
	/* 0xfb0: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_fb5:
	/* 0xfb5: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_fbb:
	/* 0xfbb: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_fc0:
	/* 0xfc0: call   r12 */
	X86_SIM_BPF_CALL_REG(X86_R12);
x86_l_fc3:
	/* 0xfc3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_fc5:
	/* 0xfc5: je     1664 <tail_nodeport_nat_egress_ipv6+0x1664> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfc5, 0x1664, x86_l_1664);
x86_l_fcb:
	/* 0xfcb: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_fce:
	/* 0xfce: movzx  r14d,r14w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_R14, X86_WIDTH_32, X86_WIDTH_16);
x86_l_fd2:
	/* 0xfd2: imul   r14d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_fd6:
	/* 0xfd6: shr    r14d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_fda:
	/* 0xfda: add    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_fdd:
	/* 0xfdd: movbe  WORD PTR [rsp+0x20],r14w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_fe5:
	/* 0xfe5: mov    rdi,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_fec:
	/* 0xfec: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_fef:
	/* 0xfef: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_ff4:
	/* 0xff4: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_ff9:
	/* 0xff9: call   r12 */
	X86_SIM_BPF_CALL_REG(X86_R12);
x86_l_ffc:
	/* 0xffc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ffe:
	/* 0xffe: je     169d <tail_nodeport_nat_egress_ipv6+0x169d> */
	X86_SIM_X86_JCC(X86_CC_E, 0xffe, 0x169d, x86_l_169d);
x86_l_1004:
	/* 0x1004: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1007:
	/* 0x1007: movzx  r14d,r14w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_R14, X86_WIDTH_32, X86_WIDTH_16);
x86_l_100b:
	/* 0x100b: imul   r14d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_100f:
	/* 0x100f: shr    r14d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1013:
	/* 0x1013: add    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1016:
	/* 0x1016: movbe  WORD PTR [rsp+0x20],r14w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_101e:
	/* 0x101e: mov    rdi,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_1025:
	/* 0x1025: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1028:
	/* 0x1028: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_102d:
	/* 0x102d: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_1033:
	/* 0x1033: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1038:
	/* 0x1038: call   r12 */
	X86_SIM_BPF_CALL_REG(X86_R12);
x86_l_103b:
	/* 0x103b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_103d:
	/* 0x103d: je     16ab <tail_nodeport_nat_egress_ipv6+0x16ab> */
	X86_SIM_X86_JCC(X86_CC_E, 0x103d, 0x16ab, x86_l_16ab);
x86_l_1043:
	/* 0x1043: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1046:
	/* 0x1046: movzx  r14d,r14w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_R14, X86_WIDTH_32, X86_WIDTH_16);
x86_l_104a:
	/* 0x104a: imul   r14d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_104e:
	/* 0x104e: shr    r14d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1052:
	/* 0x1052: add    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1055:
	/* 0x1055: movbe  WORD PTR [rsp+0x20],r14w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_105d:
	/* 0x105d: mov    rdi,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_1064:
	/* 0x1064: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1067:
	/* 0x1067: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_106c:
	/* 0x106c: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1071:
	/* 0x1071: call   r12 */
	X86_SIM_BPF_CALL_REG(X86_R12);
x86_l_1074:
	/* 0x1074: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1076:
	/* 0x1076: je     16b6 <tail_nodeport_nat_egress_ipv6+0x16b6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1076, 0x16b6, x86_l_16b6);
x86_l_107c:
	/* 0x107c: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_107f:
	/* 0x107f: movzx  r14d,r14w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_R14, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1083:
	/* 0x1083: imul   r14d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_1087:
	/* 0x1087: shr    r14d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_108b:
	/* 0x108b: add    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_108e:
	/* 0x108e: movbe  WORD PTR [rsp+0x20],r14w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_1096:
	/* 0x1096: mov    rdi,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_109d:
	/* 0x109d: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_10a0:
	/* 0x10a0: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_10a5:
	/* 0x10a5: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_10ab:
	/* 0x10ab: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_10b0:
	/* 0x10b0: call   r12 */
	X86_SIM_BPF_CALL_REG(X86_R12);
x86_l_10b3:
	/* 0x10b3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_10b5:
	/* 0x10b5: je     16be <tail_nodeport_nat_egress_ipv6+0x16be> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10b5, 0x16be, x86_l_16be);
x86_l_10bb:
	/* 0x10bb: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_10be:
	/* 0x10be: movzx  r14d,r14w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_R14, X86_WIDTH_32, X86_WIDTH_16);
x86_l_10c2:
	/* 0x10c2: imul   r14d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_10c6:
	/* 0x10c6: shr    r14d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_10ca:
	/* 0x10ca: add    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_10cd:
	/* 0x10cd: movbe  WORD PTR [rsp+0x20],r14w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_10d5:
	/* 0x10d5: mov    rdi,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_10dc:
	/* 0x10dc: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_10df:
	/* 0x10df: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_10e4:
	/* 0x10e4: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_10e9:
	/* 0x10e9: call   r12 */
	X86_SIM_BPF_CALL_REG(X86_R12);
x86_l_10ec:
	/* 0x10ec: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_10ee:
	/* 0x10ee: je     16c6 <tail_nodeport_nat_egress_ipv6+0x16c6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10ee, 0x16c6, x86_l_16c6);
x86_l_10f4:
	/* 0x10f4: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_10f7:
	/* 0x10f7: movzx  r14d,r14w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_R14, X86_WIDTH_32, X86_WIDTH_16);
x86_l_10fb:
	/* 0x10fb: imul   r14d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_10ff:
	/* 0x10ff: shr    r14d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1103:
	/* 0x1103: add    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1106:
	/* 0x1106: movbe  WORD PTR [rsp+0x20],r14w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_110e:
	/* 0x110e: mov    rdi,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_1115:
	/* 0x1115: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1118:
	/* 0x1118: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_111d:
	/* 0x111d: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_1123:
	/* 0x1123: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1128:
	/* 0x1128: call   r12 */
	X86_SIM_BPF_CALL_REG(X86_R12);
x86_l_112b:
	/* 0x112b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_112d:
	/* 0x112d: je     16ce <tail_nodeport_nat_egress_ipv6+0x16ce> */
	X86_SIM_X86_JCC(X86_CC_E, 0x112d, 0x16ce, x86_l_16ce);
x86_l_1133:
	/* 0x1133: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1136:
	/* 0x1136: movzx  r14d,r14w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_R14, X86_WIDTH_32, X86_WIDTH_16);
x86_l_113a:
	/* 0x113a: imul   r14d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_113e:
	/* 0x113e: shr    r14d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1142:
	/* 0x1142: add    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1145:
	/* 0x1145: movbe  WORD PTR [rsp+0x20],r14w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_114d:
	/* 0x114d: mov    rdi,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_1154:
	/* 0x1154: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1157:
	/* 0x1157: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_115c:
	/* 0x115c: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1161:
	/* 0x1161: call   r12 */
	X86_SIM_BPF_CALL_REG(X86_R12);
x86_l_1164:
	/* 0x1164: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1166:
	/* 0x1166: je     16d6 <tail_nodeport_nat_egress_ipv6+0x16d6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1166, 0x16d6, x86_l_16d6);
x86_l_116c:
	/* 0x116c: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_116f:
	/* 0x116f: movzx  r14d,r14w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_R14, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1173:
	/* 0x1173: imul   r14d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_1177:
	/* 0x1177: shr    r14d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_117b:
	/* 0x117b: add    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_117e:
	/* 0x117e: movbe  WORD PTR [rsp+0x20],r14w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_1186:
	/* 0x1186: mov    rdi,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_118d:
	/* 0x118d: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1190:
	/* 0x1190: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1195:
	/* 0x1195: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_119b:
	/* 0x119b: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_11a0:
	/* 0x11a0: call   r12 */
	X86_SIM_BPF_CALL_REG(X86_R12);
x86_l_11a3:
	/* 0x11a3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_11a5:
	/* 0x11a5: je     16de <tail_nodeport_nat_egress_ipv6+0x16de> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11a5, 0x16de, x86_l_16de);
x86_l_11ab:
	/* 0x11ab: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_11ae:
	/* 0x11ae: movzx  r14d,r14w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_R14, X86_WIDTH_32, X86_WIDTH_16);
x86_l_11b2:
	/* 0x11b2: imul   r14d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_11b6:
	/* 0x11b6: shr    r14d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_11ba:
	/* 0x11ba: add    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_11bd:
	/* 0x11bd: movbe  WORD PTR [rsp+0x20],r14w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_11c5:
	/* 0x11c5: mov    rdi,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_11cc:
	/* 0x11cc: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_11cf:
	/* 0x11cf: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_11d4:
	/* 0x11d4: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_11d9:
	/* 0x11d9: call   r12 */
	X86_SIM_BPF_CALL_REG(X86_R12);
x86_l_11dc:
	/* 0x11dc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_11de:
	/* 0x11de: je     16e6 <tail_nodeport_nat_egress_ipv6+0x16e6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11de, 0x16e6, x86_l_16e6);
x86_l_11e4:
	/* 0x11e4: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_11e7:
	/* 0x11e7: movzx  r14d,r14w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_R14, X86_WIDTH_32, X86_WIDTH_16);
x86_l_11eb:
	/* 0x11eb: imul   r14d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_11ef:
	/* 0x11ef: shr    r14d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_11f3:
	/* 0x11f3: add    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_11f6:
	/* 0x11f6: movbe  WORD PTR [rsp+0x20],r14w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_11fe:
	/* 0x11fe: mov    rdi,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_1205:
	/* 0x1205: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1208:
	/* 0x1208: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_120d:
	/* 0x120d: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_1213:
	/* 0x1213: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1218:
	/* 0x1218: call   r12 */
	X86_SIM_BPF_CALL_REG(X86_R12);
x86_l_121b:
	/* 0x121b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_121d:
	/* 0x121d: je     16ee <tail_nodeport_nat_egress_ipv6+0x16ee> */
	X86_SIM_X86_JCC(X86_CC_E, 0x121d, 0x16ee, x86_l_16ee);
x86_l_1223:
	/* 0x1223: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1226:
	/* 0x1226: movzx  r14d,r14w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_R14, X86_WIDTH_32, X86_WIDTH_16);
x86_l_122a:
	/* 0x122a: imul   r14d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_122e:
	/* 0x122e: shr    r14d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1232:
	/* 0x1232: add    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1235:
	/* 0x1235: movbe  WORD PTR [rsp+0x20],r14w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_123d:
	/* 0x123d: mov    rdi,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_1244:
	/* 0x1244: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1247:
	/* 0x1247: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_124c:
	/* 0x124c: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1251:
	/* 0x1251: call   r12 */
	X86_SIM_BPF_CALL_REG(X86_R12);
x86_l_1254:
	/* 0x1254: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1256:
	/* 0x1256: je     16f6 <tail_nodeport_nat_egress_ipv6+0x16f6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1256, 0x16f6, x86_l_16f6);
x86_l_125c:
	/* 0x125c: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_125f:
	/* 0x125f: movzx  r14d,r14w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_R14, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1263:
	/* 0x1263: imul   r14d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_1267:
	/* 0x1267: shr    r14d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_126b:
	/* 0x126b: add    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_126e:
	/* 0x126e: movbe  WORD PTR [rsp+0x20],r14w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_1276:
	/* 0x1276: mov    rdi,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_127d:
	/* 0x127d: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1280:
	/* 0x1280: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1285:
	/* 0x1285: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_128b:
	/* 0x128b: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1290:
	/* 0x1290: call   r12 */
	X86_SIM_BPF_CALL_REG(X86_R12);
x86_l_1293:
	/* 0x1293: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1295:
	/* 0x1295: je     16fe <tail_nodeport_nat_egress_ipv6+0x16fe> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1295, 0x16fe, x86_l_16fe);
x86_l_129b:
	/* 0x129b: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_129e:
	/* 0x129e: movzx  r14d,r14w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_R14, X86_WIDTH_32, X86_WIDTH_16);
x86_l_12a2:
	/* 0x12a2: imul   r14d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_12a6:
	/* 0x12a6: shr    r14d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_12aa:
	/* 0x12aa: add    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_12ad:
	/* 0x12ad: movbe  WORD PTR [rsp+0x20],r14w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_12b5:
	/* 0x12b5: mov    rdi,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_12bc:
	/* 0x12bc: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_12bf:
	/* 0x12bf: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_12c4:
	/* 0x12c4: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_12c9:
	/* 0x12c9: call   r12 */
	X86_SIM_BPF_CALL_REG(X86_R12);
x86_l_12cc:
	/* 0x12cc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_12ce:
	/* 0x12ce: je     1706 <tail_nodeport_nat_egress_ipv6+0x1706> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12ce, 0x1706, x86_l_1706);
x86_l_12d4:
	/* 0x12d4: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_12d7:
	/* 0x12d7: movzx  r14d,r14w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_R14, X86_WIDTH_32, X86_WIDTH_16);
x86_l_12db:
	/* 0x12db: imul   r14d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_12df:
	/* 0x12df: shr    r14d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_12e3:
	/* 0x12e3: add    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_12e6:
	/* 0x12e6: movbe  WORD PTR [rsp+0x20],r14w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_12ee:
	/* 0x12ee: mov    rdi,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_12f5:
	/* 0x12f5: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_12f8:
	/* 0x12f8: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_12fd:
	/* 0x12fd: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_1303:
	/* 0x1303: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1308:
	/* 0x1308: call   r12 */
	X86_SIM_BPF_CALL_REG(X86_R12);
x86_l_130b:
	/* 0x130b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_130d:
	/* 0x130d: je     170e <tail_nodeport_nat_egress_ipv6+0x170e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x130d, 0x170e, x86_l_170e);
x86_l_1313:
	/* 0x1313: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1316:
	/* 0x1316: movzx  r14d,r14w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_R14, X86_WIDTH_32, X86_WIDTH_16);
x86_l_131a:
	/* 0x131a: imul   r14d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_131e:
	/* 0x131e: shr    r14d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1322:
	/* 0x1322: add    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1325:
	/* 0x1325: movbe  WORD PTR [rsp+0x20],r14w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_132d:
	/* 0x132d: mov    rdi,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_1334:
	/* 0x1334: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1337:
	/* 0x1337: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_133c:
	/* 0x133c: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1341:
	/* 0x1341: call   r12 */
	X86_SIM_BPF_CALL_REG(X86_R12);
x86_l_1344:
	/* 0x1344: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1346:
	/* 0x1346: je     1716 <tail_nodeport_nat_egress_ipv6+0x1716> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1346, 0x1716, x86_l_1716);
x86_l_134c:
	/* 0x134c: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_134f:
	/* 0x134f: movzx  r14d,r14w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_R14, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1353:
	/* 0x1353: imul   r14d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_1357:
	/* 0x1357: shr    r14d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_135b:
	/* 0x135b: add    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_135e:
	/* 0x135e: movbe  WORD PTR [rsp+0x20],r14w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_1366:
	/* 0x1366: mov    rdi,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_136d:
	/* 0x136d: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1370:
	/* 0x1370: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1375:
	/* 0x1375: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_137b:
	/* 0x137b: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1380:
	/* 0x1380: call   r12 */
	X86_SIM_BPF_CALL_REG(X86_R12);
x86_l_1383:
	/* 0x1383: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1385:
	/* 0x1385: je     171e <tail_nodeport_nat_egress_ipv6+0x171e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1385, 0x171e, x86_l_171e);
x86_l_138b:
	/* 0x138b: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_138e:
	/* 0x138e: movzx  eax,r14w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R14, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1392:
	/* 0x1392: imul   r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_1396:
	/* 0x1396: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_139a:
	/* 0x139a: add    ebp,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R15, X86_WIDTH_32, X86_ALU_ADD);
x86_l_139d:
	/* 0x139d: movbe  WORD PTR [rsp+0x20],bp */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_13a4:
	/* 0x13a4: mov    rdi,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_13ab:
	/* 0x13ab: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_13ae:
	/* 0x13ae: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_13b3:
	/* 0x13b3: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_13b8:
	/* 0x13b8: call   r12 */
	X86_SIM_BPF_CALL_REG(X86_R12);
x86_l_13bb:
	/* 0x13bb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_13bd:
	/* 0x13bd: je     1726 <tail_nodeport_nat_egress_ipv6+0x1726> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13bd, 0x1726, x86_l_1726);
x86_l_13c3:
	/* 0x13c3: mov    DWORD PTR [rsp+0xb4],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 773094113312ULL);
x86_l_13ce:
	/* 0x13ce: mov    rdi,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_alloc_retries)));
x86_l_13d5:
	/* 0x13d5: lea    rsi,[rsp+0xb4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 180ULL);
x86_l_13dd:
	/* 0x13dd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13e2:
	/* 0x13e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13e4:
	/* 0x13e4: mov    ebp,0xffffff59 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967129ULL);
x86_l_13e9:
	/* 0x13e9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13ec:
	/* 0x13ec: je     13f0 <tail_nodeport_nat_egress_ipv6+0x13f0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13ec, 0x13f0, x86_l_13f0);
x86_l_13ee:
	/* 0x13ee: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_13f0:
	/* 0x13f0: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13f3:
	/* 0x13f3: jmp    17ac <tail_nodeport_nat_egress_ipv6+0x17ac> */
	X86_SIM_X86_JMP(0x13f3, 0x17ac, x86_l_17ac);
x86_l_13f8:
	/* 0x13f8: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13fb:
	/* 0x13fb: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13fe:
	/* 0x13fe: jmp    172f <tail_nodeport_nat_egress_ipv6+0x172f> */
	X86_SIM_X86_JMP(0x13fe, 0x172f, x86_l_172f);
x86_l_1403:
	/* 0x1403: mov    r13d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 2ULL);
x86_l_1409:
	/* 0x1409: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_140c:
	/* 0x140c: jmp    172f <tail_nodeport_nat_egress_ipv6+0x172f> */
	X86_SIM_X86_JMP(0x140c, 0x172f, x86_l_172f);
x86_l_1411:
	/* 0x1411: mov    r13d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 3ULL);
x86_l_1417:
	/* 0x1417: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_141a:
	/* 0x141a: jmp    172f <tail_nodeport_nat_egress_ipv6+0x172f> */
	X86_SIM_X86_JMP(0x141a, 0x172f, x86_l_172f);
x86_l_141f:
	/* 0x141f: mov    rdi,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_1426:
	/* 0x1426: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_142b:
	/* 0x142b: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_142e:
	/* 0x142e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1430:
	/* 0x1430: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1433:
	/* 0x1433: jne    1554 <tail_nodeport_nat_egress_ipv6+0x1554> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1433, 0x1554, x86_l_1554);
x86_l_1439:
	/* 0x1439: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_143e:
	/* 0x143e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1440:
	/* 0x1440: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1442:
	/* 0x1442: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1444:
	/* 0x1444: imul   rax,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_1449:
	/* 0x1449: cmp    rax,QWORD PTR [r14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_144c:
	/* 0x144c: jbe    1451 <tail_nodeport_nat_egress_ipv6+0x1451> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x144c, 0x1451, x86_l_1451);
x86_l_144e:
	/* 0x144e: mov    rax,QWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1451:
	/* 0x1451: mov    rcx,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__aux_snat_v6_nhm_nat_entry)));
x86_l_1458:
	/* 0x1458: mov    QWORD PTR [rcx+rax*1+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 206158430208ULL);
x86_l_1461:
	/* 0x1461: mov    QWORD PTR [rcx+rax*1+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 171798691840ULL);
x86_l_146a:
	/* 0x146a: mov    QWORD PTR [rcx+rax*1+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 137438953472ULL);
x86_l_1473:
	/* 0x1473: mov    QWORD PTR [rcx+rax*1+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 103079215104ULL);
x86_l_147c:
	/* 0x147c: mov    QWORD PTR [rcx+rax*1+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 68719476736ULL);
x86_l_1485:
	/* 0x1485: mov    QWORD PTR [rcx+rax*1+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 34359738368ULL);
x86_l_148e:
	/* 0x148e: mov    QWORD PTR [rcx+rax*1],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1496:
	/* 0x1496: lea    rsi,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_149e:
	/* 0x149e: mov    rdx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14a1:
	/* 0x14a1: mov    rsi,QWORD PTR [rsi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14a5:
	/* 0x14a5: mov    QWORD PTR [rcx+rax*1+0x20],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 32ULL);
x86_l_14aa:
	/* 0x14aa: mov    QWORD PTR [rcx+rax*1+0x28],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 40ULL);
x86_l_14af:
	/* 0x14af: movzx  edx,WORD PTR [rsp+0xaa] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 170ULL);
x86_l_14b7:
	/* 0x14b7: lea    r13,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_14bb:
	/* 0x14bb: mov    WORD PTR [rcx+rax*1+0x30],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 0), 48ULL);
x86_l_14c0:
	/* 0x14c0: mov    rax,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_14c7:
	/* 0x14c7: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14ca:
	/* 0x14ca: je     1513 <tail_nodeport_nat_egress_ipv6+0x1513> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14ca, 0x1513, x86_l_1513);
x86_l_14cc:
	/* 0x14cc: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_14d1:
	/* 0x14d1: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14d3:
	/* 0x14d3: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_14d5:
	/* 0x14d5: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_14d9:
	/* 0x14d9: jmp    1536 <tail_nodeport_nat_egress_ipv6+0x1536> */
	X86_SIM_X86_JMP(0x14d9, 0x1536, x86_l_1536);
x86_l_14db:
	/* 0x14db: mov    r13d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4ULL);
x86_l_14e1:
	/* 0x14e1: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14e4:
	/* 0x14e4: jmp    172f <tail_nodeport_nat_egress_ipv6+0x172f> */
	X86_SIM_X86_JMP(0x14e4, 0x172f, x86_l_172f);
x86_l_14e9:
	/* 0x14e9: mov    r13d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 5ULL);
x86_l_14ef:
	/* 0x14ef: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14f2:
	/* 0x14f2: jmp    172f <tail_nodeport_nat_egress_ipv6+0x172f> */
	X86_SIM_X86_JMP(0x14f2, 0x172f, x86_l_172f);
x86_l_14f7:
	/* 0x14f7: mov    r13d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 6ULL);
x86_l_14fd:
	/* 0x14fd: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1500:
	/* 0x1500: jmp    172f <tail_nodeport_nat_egress_ipv6+0x172f> */
	X86_SIM_X86_JMP(0x1500, 0x172f, x86_l_172f);
x86_l_1505:
	/* 0x1505: mov    r13d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 7ULL);
x86_l_150b:
	/* 0x150b: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_150e:
	/* 0x150e: jmp    172f <tail_nodeport_nat_egress_ipv6+0x172f> */
	X86_SIM_X86_JMP(0x150e, 0x172f, x86_l_172f);
x86_l_1513:
	/* 0x1513: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1518:
	/* 0x1518: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_151a:
	/* 0x151a: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_151c:
	/* 0x151c: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1520:
	/* 0x1520: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_152a:
	/* 0x152a: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_152d:
	/* 0x152d: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1532:
	/* 0x1532: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_1536:
	/* 0x1536: mov    QWORD PTR [r13+0x0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_153a:
	/* 0x153a: mov    rdi,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_1541:
	/* 0x1541: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1546:
	/* 0x1546: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_1549:
	/* 0x1549: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_154c:
	/* 0x154c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_154e:
	/* 0x154e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1550:
	/* 0x1550: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1552:
	/* 0x1552: js     1564 <tail_nodeport_nat_egress_ipv6+0x1564> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1552, 0x1564, x86_l_1564);
x86_l_1554:
	/* 0x1554: mov    rax,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_155c:
	/* 0x155c: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_155f:
	/* 0x155f: jmp    17ea <tail_nodeport_nat_egress_ipv6+0x17ea> */
	X86_SIM_X86_JMP(0x155f, 0x17ea, x86_l_17ea);
x86_l_1564:
	/* 0x1564: mov    r13d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_1567:
	/* 0x1567: mov    ebp,0xffffff59 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967129ULL);
x86_l_156c:
	/* 0x156c: jmp    10b <tail_nodeport_nat_egress_ipv6+0x10b> */
	X86_SIM_X86_JMP(0x156c, 0x10b, x86_l_10b);
x86_l_1571:
	/* 0x1571: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_1577:
	/* 0x1577: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_157a:
	/* 0x157a: jmp    172f <tail_nodeport_nat_egress_ipv6+0x172f> */
	X86_SIM_X86_JMP(0x157a, 0x172f, x86_l_172f);
x86_l_157f:
	/* 0x157f: mov    r13d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 9ULL);
x86_l_1585:
	/* 0x1585: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1588:
	/* 0x1588: jmp    172f <tail_nodeport_nat_egress_ipv6+0x172f> */
	X86_SIM_X86_JMP(0x1588, 0x172f, x86_l_172f);
x86_l_158d:
	/* 0x158d: mov    r13d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 10ULL);
x86_l_1593:
	/* 0x1593: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1596:
	/* 0x1596: jmp    172f <tail_nodeport_nat_egress_ipv6+0x172f> */
	X86_SIM_X86_JMP(0x1596, 0x172f, x86_l_172f);
x86_l_159b:
	/* 0x159b: mov    rdi,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv6_frag_datagrams)));
x86_l_15a2:
	/* 0x15a2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_15a7:
	/* 0x15a7: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_15aa:
	/* 0x15aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15ac:
	/* 0x15ac: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15af:
	/* 0x15af: je     164c <tail_nodeport_nat_egress_ipv6+0x164c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x15af, 0x164c, x86_l_164c);
x86_l_15b5:
	/* 0x15b5: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15b7:
	/* 0x15b7: mov    DWORD PTR [rsp+0xa8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_15be:
	/* 0x15be: jmp    843 <tail_nodeport_nat_egress_ipv6+0x843> */
	X86_SIM_X86_JMP(0x15be, 0x843, x86_l_843);
x86_l_15c3:
	/* 0x15c3: mov    r13d,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 11ULL);
x86_l_15c9:
	/* 0x15c9: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15cc:
	/* 0x15cc: jmp    172f <tail_nodeport_nat_egress_ipv6+0x172f> */
	X86_SIM_X86_JMP(0x15cc, 0x172f, x86_l_172f);
x86_l_15d1:
	/* 0x15d1: mov    rdi,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv6_frag_datagrams)));
x86_l_15d8:
	/* 0x15d8: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_15dd:
	/* 0x15dd: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_15e0:
	/* 0x15e0: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_15e3:
	/* 0x15e3: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15e5:
	/* 0x15e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15e7:
	/* 0x15e7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_15e9:
	/* 0x15e9: je     843 <tail_nodeport_nat_egress_ipv6+0x843> */
	X86_SIM_X86_JCC(X86_CC_E, 0x15e9, 0x843, x86_l_843);
x86_l_15ef:
	/* 0x15ef: mov    r13d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15f2:
	/* 0x15f2: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_15fb:
	/* 0x15fb: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1604:
	/* 0x1604: movabs rax,0x7201a9020a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 489654125066ULL);
x86_l_160e:
	/* 0x160e: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1612:
	/* 0x1612: mov    rdi,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1619:
	/* 0x1619: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_161c:
	/* 0x161c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1621:
	/* 0x1621: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1623:
	/* 0x1623: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1626:
	/* 0x1626: je     1672 <tail_nodeport_nat_egress_ipv6+0x1672> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1626, 0x1672, x86_l_1672);
x86_l_1628:
	/* 0x1628: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_162b:
	/* 0x162b: add    QWORD PTR [rax+0x8],r13 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_162f:
	/* 0x162f: jmp    843 <tail_nodeport_nat_egress_ipv6+0x843> */
	X86_SIM_X86_JMP(0x162f, 0x843, x86_l_843);
x86_l_1634:
	/* 0x1634: mov    ebp,0xffffff63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967139ULL);
x86_l_1639:
	/* 0x1639: jmp    108 <tail_nodeport_nat_egress_ipv6+0x108> */
	X86_SIM_X86_JMP(0x1639, 0x108, x86_l_108);
x86_l_163e:
	/* 0x163e: mov    r13d,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 12ULL);
x86_l_1644:
	/* 0x1644: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1647:
	/* 0x1647: jmp    172f <tail_nodeport_nat_egress_ipv6+0x172f> */
	X86_SIM_X86_JMP(0x1647, 0x172f, x86_l_172f);
x86_l_164c:
	/* 0x164c: mov    ebp,0xffffff51 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967121ULL);
x86_l_1651:
	/* 0x1651: jmp    8f3 <tail_nodeport_nat_egress_ipv6+0x8f3> */
	X86_SIM_X86_JMP(0x1651, 0x8f3, x86_l_8f3);
x86_l_1656:
	/* 0x1656: mov    r13d,0xd */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 13ULL);
x86_l_165c:
	/* 0x165c: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_165f:
	/* 0x165f: jmp    172f <tail_nodeport_nat_egress_ipv6+0x172f> */
	X86_SIM_X86_JMP(0x165f, 0x172f, x86_l_172f);
x86_l_1664:
	/* 0x1664: mov    r13d,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 14ULL);
x86_l_166a:
	/* 0x166a: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_166d:
	/* 0x166d: jmp    172f <tail_nodeport_nat_egress_ipv6+0x172f> */
	X86_SIM_X86_JMP(0x166d, 0x172f, x86_l_172f);
x86_l_1672:
	/* 0x1672: mov    QWORD PTR [rsp+0x28],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691841ULL);
x86_l_167b:
	/* 0x167b: mov    QWORD PTR [rsp+0x30],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1680:
	/* 0x1680: mov    rdi,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1687:
	/* 0x1687: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_168a:
	/* 0x168a: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_168f:
	/* 0x168f: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1694:
	/* 0x1694: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1696:
	/* 0x1696: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1698:
	/* 0x1698: jmp    843 <tail_nodeport_nat_egress_ipv6+0x843> */
	X86_SIM_X86_JMP(0x1698, 0x843, x86_l_843);
x86_l_169d:
	/* 0x169d: mov    r13d,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 15ULL);
x86_l_16a3:
	/* 0x16a3: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16a6:
	/* 0x16a6: jmp    172f <tail_nodeport_nat_egress_ipv6+0x172f> */
	X86_SIM_X86_JMP(0x16a6, 0x172f, x86_l_172f);
x86_l_16ab:
	/* 0x16ab: mov    r13d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 16ULL);
x86_l_16b1:
	/* 0x16b1: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16b4:
	/* 0x16b4: jmp    172f <tail_nodeport_nat_egress_ipv6+0x172f> */
	X86_SIM_X86_JMP(0x16b4, 0x172f, x86_l_172f);
x86_l_16b6:
	/* 0x16b6: mov    r13d,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 17ULL);
x86_l_16bc:
	/* 0x16bc: jmp    172c <tail_nodeport_nat_egress_ipv6+0x172c> */
	X86_SIM_X86_JMP(0x16bc, 0x172c, x86_l_172c);
x86_l_16be:
	/* 0x16be: mov    r13d,0x12 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 18ULL);
x86_l_16c4:
	/* 0x16c4: jmp    172c <tail_nodeport_nat_egress_ipv6+0x172c> */
	X86_SIM_X86_JMP(0x16c4, 0x172c, x86_l_172c);
x86_l_16c6:
	/* 0x16c6: mov    r13d,0x13 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 19ULL);
x86_l_16cc:
	/* 0x16cc: jmp    172c <tail_nodeport_nat_egress_ipv6+0x172c> */
	X86_SIM_X86_JMP(0x16cc, 0x172c, x86_l_172c);
x86_l_16ce:
	/* 0x16ce: mov    r13d,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 20ULL);
x86_l_16d4:
	/* 0x16d4: jmp    172c <tail_nodeport_nat_egress_ipv6+0x172c> */
	X86_SIM_X86_JMP(0x16d4, 0x172c, x86_l_172c);
x86_l_16d6:
	/* 0x16d6: mov    r13d,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 21ULL);
x86_l_16dc:
	/* 0x16dc: jmp    172c <tail_nodeport_nat_egress_ipv6+0x172c> */
	X86_SIM_X86_JMP(0x16dc, 0x172c, x86_l_172c);
x86_l_16de:
	/* 0x16de: mov    r13d,0x16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 22ULL);
x86_l_16e4:
	/* 0x16e4: jmp    172c <tail_nodeport_nat_egress_ipv6+0x172c> */
	X86_SIM_X86_JMP(0x16e4, 0x172c, x86_l_172c);
x86_l_16e6:
	/* 0x16e6: mov    r13d,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 23ULL);
x86_l_16ec:
	/* 0x16ec: jmp    172c <tail_nodeport_nat_egress_ipv6+0x172c> */
	X86_SIM_X86_JMP(0x16ec, 0x172c, x86_l_172c);
x86_l_16ee:
	/* 0x16ee: mov    r13d,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 24ULL);
x86_l_16f4:
	/* 0x16f4: jmp    172c <tail_nodeport_nat_egress_ipv6+0x172c> */
	X86_SIM_X86_JMP(0x16f4, 0x172c, x86_l_172c);
x86_l_16f6:
	/* 0x16f6: mov    r13d,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 25ULL);
x86_l_16fc:
	/* 0x16fc: jmp    172c <tail_nodeport_nat_egress_ipv6+0x172c> */
	X86_SIM_X86_JMP(0x16fc, 0x172c, x86_l_172c);
x86_l_16fe:
	/* 0x16fe: mov    r13d,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 26ULL);
x86_l_1704:
	/* 0x1704: jmp    172c <tail_nodeport_nat_egress_ipv6+0x172c> */
	X86_SIM_X86_JMP(0x1704, 0x172c, x86_l_172c);
x86_l_1706:
	/* 0x1706: mov    r13d,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 27ULL);
x86_l_170c:
	/* 0x170c: jmp    172c <tail_nodeport_nat_egress_ipv6+0x172c> */
	X86_SIM_X86_JMP(0x170c, 0x172c, x86_l_172c);
x86_l_170e:
	/* 0x170e: mov    r13d,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 28ULL);
x86_l_1714:
	/* 0x1714: jmp    172c <tail_nodeport_nat_egress_ipv6+0x172c> */
	X86_SIM_X86_JMP(0x1714, 0x172c, x86_l_172c);
x86_l_1716:
	/* 0x1716: mov    r13d,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 29ULL);
x86_l_171c:
	/* 0x171c: jmp    172c <tail_nodeport_nat_egress_ipv6+0x172c> */
	X86_SIM_X86_JMP(0x171c, 0x172c, x86_l_172c);
x86_l_171e:
	/* 0x171e: mov    r13d,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 30ULL);
x86_l_1724:
	/* 0x1724: jmp    172c <tail_nodeport_nat_egress_ipv6+0x172c> */
	X86_SIM_X86_JMP(0x1724, 0x172c, x86_l_172c);
x86_l_1726:
	/* 0x1726: mov    r13d,0x1f */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 31ULL);
x86_l_172c:
	/* 0x172c: mov    r12b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_8, 1ULL);
x86_l_172f:
	/* 0x172f: mov    DWORD PTR [rsp+0xb4],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 180ULL);
x86_l_1737:
	/* 0x1737: mov    rdi,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_alloc_retries)));
x86_l_173e:
	/* 0x173e: lea    rsi,[rsp+0xb4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 180ULL);
x86_l_1746:
	/* 0x1746: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_174b:
	/* 0x174b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_174d:
	/* 0x174d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1750:
	/* 0x1750: je     1754 <tail_nodeport_nat_egress_ipv6+0x1754> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1750, 0x1754, x86_l_1754);
x86_l_1752:
	/* 0x1752: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1754:
	/* 0x1754: movzx  eax,WORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_1759:
	/* 0x1759: mov    rdx,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1761:
	/* 0x1761: mov    WORD PTR [rdx+0x30],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1765:
	/* 0x1765: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_176a:
	/* 0x176a: mov    QWORD PTR [rdx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_176d:
	/* 0x176d: mov    rdi,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_1774:
	/* 0x1774: lea    rsi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_177c:
	/* 0x177c: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_177f:
	/* 0x177f: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1784:
	/* 0x1784: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1786:
	/* 0x1786: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1788:
	/* 0x1788: mov    ebp,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_178a:
	/* 0x178a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_178c:
	/* 0x178c: jns    17a7 <tail_nodeport_nat_egress_ipv6+0x17a7> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x178c, 0x17a7, x86_l_17a7);
x86_l_178e:
	/* 0x178e: mov    rdi,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_1795:
	/* 0x1795: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1798:
	/* 0x1798: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_179d:
	/* 0x179d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_179f:
	/* 0x179f: mov    r13d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBP, X86_WIDTH_32);
x86_l_17a2:
	/* 0x17a2: mov    ebp,0xffffff59 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967129ULL);
x86_l_17a7:
	/* 0x17a7: test   r12b,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_8);
x86_l_17aa:
	/* 0x17aa: je     17e2 <tail_nodeport_nat_egress_ipv6+0x17e2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x17aa, 0x17e2, x86_l_17e2);
x86_l_17ac:
	/* 0x17ac: movabs rax,0x100000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 4294967296ULL);
x86_l_17b6:
	/* 0x17b6: mov    QWORD PTR [rsp+0x128],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_17be:
	/* 0x17be: mov    rsi,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_signals)));
x86_l_17c5:
	/* 0x17c5: lea    rcx,[rsp+0x128] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 296ULL);
x86_l_17cd:
	/* 0x17cd: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_17d2:
	/* 0x17d2: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_17d7:
	/* 0x17d7: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_17da:
	/* 0x17da: mov    r8d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 8ULL);
x86_l_17e0:
	/* 0x17e0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17e2:
	/* 0x17e2: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_17e4:
	/* 0x17e4: js     10b <tail_nodeport_nat_egress_ipv6+0x10b> */
	X86_SIM_X86_JCC(X86_CC_S, 0x17e4, 0x10b, x86_l_10b);
x86_l_17ea:
	/* 0x17ea: mov    rcx,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_17f2:
	/* 0x17f2: movzx  esi,WORD PTR [rcx+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_17f6:
	/* 0x17f6: movzx  r15d,BYTE PTR [rsp+0xac] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 172ULL);
x86_l_17ff:
	/* 0x17ff: movzx  edx,WORD PTR [rsp+0xaa] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 170ULL);
x86_l_1807:
	/* 0x1807: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_180f:
	/* 0x180f: cmp    rax,QWORD PTR [rcx+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_1813:
	/* 0x1813: mov    DWORD PTR [rsp+0xd4],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 212ULL);
x86_l_181a:
	/* 0x181a: mov    WORD PTR [rsp+0x80],si */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1822:
	/* 0x1822: jne    1843 <tail_nodeport_nat_egress_ipv6+0x1843> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1822, 0x1843, x86_l_1843);
x86_l_1824:
	/* 0x1824: cmp    dx,si */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_16);
x86_l_1827:
	/* 0x1827: sete   r14b */
	X86_SIM_L_EXEC_SETCC(X86_R14, X86_CC_E);
x86_l_182b:
	/* 0x182b: jne    184a <tail_nodeport_nat_egress_ipv6+0x184a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x182b, 0x184a, x86_l_184a);
x86_l_182d:
	/* 0x182d: mov    rax,QWORD PTR [rcx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1831:
	/* 0x1831: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1833:
	/* 0x1833: cmp    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_183b:
	/* 0x183b: je     19c4 <tail_nodeport_nat_egress_ipv6+0x19c4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x183b, 0x19c4, x86_l_19c4);
x86_l_1841:
	/* 0x1841: jmp    184a <tail_nodeport_nat_egress_ipv6+0x184a> */
	X86_SIM_X86_JMP(0x1841, 0x184a, x86_l_184a);
x86_l_1843:
	/* 0x1843: cmp    dx,si */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_16);
x86_l_1846:
	/* 0x1846: sete   r14b */
	X86_SIM_L_EXEC_SETCC(X86_R14, X86_CC_E);
x86_l_184a:
	/* 0x184a: mov    rax,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1852:
	/* 0x1852: lea    r12,[rax+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1856:
	/* 0x1856: mov    eax,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_185b:
	/* 0x185b: lea    rdi,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1863:
	/* 0x1863: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1868:
	/* 0x1868: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_186b:
	/* 0x186b: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1870:
	/* 0x1870: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1873:
	/* 0x1873: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1875:
	/* 0x1875: mov    DWORD PTR [rsp+0xd0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_187c:
	/* 0x187c: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_1881:
	/* 0x1881: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1884:
	/* 0x1884: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1889:
	/* 0x1889: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_188c:
	/* 0x188c: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1891:
	/* 0x1891: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1894:
	/* 0x1894: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1896:
	/* 0x1896: mov    ebp,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_1898:
	/* 0x1898: sar    ebp,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SAR, 31ULL);
x86_l_189b:
	/* 0x189b: and    ebp,0xffffff73 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4294967155ULL);
x86_l_18a1:
	/* 0x18a1: movabs rcx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2199023255552ULL);
x86_l_18ab:
	/* 0x18ab: test   QWORD PTR [rsp+0x70],rcx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_18b0:
	/* 0x18b0: jne    19c4 <tail_nodeport_nat_egress_ipv6+0x19c4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x18b0, 0x19c4, x86_l_19c4);
x86_l_18b6:
	/* 0x18b6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_18b8:
	/* 0x18b8: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_18bd:
	/* 0x18bd: js     19c4 <tail_nodeport_nat_egress_ipv6+0x19c4> */
	X86_SIM_X86_JCC(X86_CC_S, 0x18bd, 0x19c4, x86_l_19c4);
x86_l_18c3:
	/* 0x18c3: mov    eax,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_18c6:
	/* 0x18c6: cmp    r15d,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 58ULL);
x86_l_18ca:
	/* 0x18ca: je     18f0 <tail_nodeport_nat_egress_ipv6+0x18f0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x18ca, 0x18f0, x86_l_18f0);
x86_l_18cc:
	/* 0x18cc: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_18cf:
	/* 0x18cf: je     18e0 <tail_nodeport_nat_egress_ipv6+0x18e0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x18cf, 0x18e0, x86_l_18e0);
x86_l_18d1:
	/* 0x18d1: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_18d4:
	/* 0x18d4: jne    18fa <tail_nodeport_nat_egress_ipv6+0x18fa> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x18d4, 0x18fa, x86_l_18fa);
x86_l_18d6:
	/* 0x18d6: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18d8:
	/* 0x18d8: mov    r15d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 16ULL);
x86_l_18de:
	/* 0x18de: jmp    18ff <tail_nodeport_nat_egress_ipv6+0x18ff> */
	X86_SIM_X86_JMP(0x18de, 0x18ff, x86_l_18ff);
x86_l_18e0:
	/* 0x18e0: mov    r12d,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 32ULL);
x86_l_18e6:
	/* 0x18e6: mov    r15d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 6ULL);
x86_l_18ec:
	/* 0x18ec: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18ee:
	/* 0x18ee: jmp    1902 <tail_nodeport_nat_egress_ipv6+0x1902> */
	X86_SIM_X86_JMP(0x18ee, 0x1902, x86_l_1902);
x86_l_18f0:
	/* 0x18f0: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18f2:
	/* 0x18f2: mov    r15d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 2ULL);
x86_l_18f8:
	/* 0x18f8: jmp    18ff <tail_nodeport_nat_egress_ipv6+0x18ff> */
	X86_SIM_X86_JMP(0x18f8, 0x18ff, x86_l_18ff);
x86_l_18fa:
	/* 0x18fa: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18fd:
	/* 0x18fd: mov    dl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_8, 1ULL);
x86_l_18ff:
	/* 0x18ff: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1902:
	/* 0x1902: test   r14b,r14b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_8);
x86_l_1905:
	/* 0x1905: jne    198c <tail_nodeport_nat_egress_ipv6+0x198c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1905, 0x198c, x86_l_198c);
x86_l_190b:
	/* 0x190b: mov    ebp,0xffffff72 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967154ULL);
x86_l_1910:
	/* 0x1910: cmp    eax,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 58ULL);
x86_l_1913:
	/* 0x1913: ja     19c4 <tail_nodeport_nat_egress_ipv6+0x19c4> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1913, 0x19c4, x86_l_19c4);
x86_l_1919:
	/* 0x1919: mov    DWORD PTR [rsp+0x70],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_191d:
	/* 0x191d: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_191f:
	/* 0x191f: movabs rcx,0x400000000020040 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 288230376151842880ULL);
x86_l_1929:
	/* 0x1929: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_192d:
	/* 0x192d: jae    19c4 <tail_nodeport_nat_egress_ipv6+0x19c4> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x192d, 0x19c4, x86_l_19c4);
x86_l_1933:
	/* 0x1933: movzx  eax,WORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 128ULL);
x86_l_193b:
	/* 0x193b: mov    WORD PTR [rsp+0x28],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1940:
	/* 0x1940: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1945:
	/* 0x1945: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_194a:
	/* 0x194a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_194d:
	/* 0x194d: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_1950:
	/* 0x1950: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1955:
	/* 0x1955: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1958:
	/* 0x1958: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_195a:
	/* 0x195a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_195c:
	/* 0x195c: js     19bf <tail_nodeport_nat_egress_ipv6+0x19bf> */
	X86_SIM_X86_JCC(X86_CC_S, 0x195c, 0x19bf, x86_l_19bf);
x86_l_195e:
	/* 0x195e: movzx  ecx,WORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 40ULL);
x86_l_1963:
	/* 0x1963: lea    esi,[r15+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_1967:
	/* 0x1967: mov    r8d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R12, X86_WIDTH_32);
x86_l_196a:
	/* 0x196a: or     r8d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_196e:
	/* 0x196e: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_1973:
	/* 0x1973: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1976:
	/* 0x1976: mov    edx,DWORD PTR [rsp+0xd4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 212ULL);
x86_l_197d:
	/* 0x197d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_197f:
	/* 0x197f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1981:
	/* 0x1981: js     19b8 <tail_nodeport_nat_egress_ipv6+0x19b8> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1981, 0x19b8, x86_l_19b8);
x86_l_1983:
	/* 0x1983: mov    rsi,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1988:
	/* 0x1988: mov    edx,DWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_198c:
	/* 0x198c: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_198e:
	/* 0x198e: jne    19b4 <tail_nodeport_nat_egress_ipv6+0x19b4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x198e, 0x19b4, x86_l_19b4);
x86_l_1990:
	/* 0x1990: add    r15d,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1993:
	/* 0x1993: or     r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_OR, 16ULL);
x86_l_1997:
	/* 0x1997: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_199c:
	/* 0x199c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_199f:
	/* 0x199f: mov    esi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_19a2:
	/* 0x19a2: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19a4:
	/* 0x19a4: mov    ecx,DWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_19ab:
	/* 0x19ab: mov    r8d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R12, X86_WIDTH_32);
x86_l_19ae:
	/* 0x19ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19b0:
	/* 0x19b0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_19b2:
	/* 0x19b2: js     19b8 <tail_nodeport_nat_egress_ipv6+0x19b8> */
	X86_SIM_X86_JCC(X86_CC_S, 0x19b2, 0x19b8, x86_l_19b8);
x86_l_19b4:
	/* 0x19b4: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19b6:
	/* 0x19b6: jmp    19c4 <tail_nodeport_nat_egress_ipv6+0x19c4> */
	X86_SIM_X86_JMP(0x19b6, 0x19c4, x86_l_19c4);
x86_l_19b8:
	/* 0x19b8: mov    ebp,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967142ULL);
x86_l_19bd:
	/* 0x19bd: jmp    19c4 <tail_nodeport_nat_egress_ipv6+0x19c4> */
	X86_SIM_X86_JMP(0x19bd, 0x19c4, x86_l_19c4);
x86_l_19bf:
	/* 0x19bf: mov    ebp,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967155ULL);
x86_l_19c4:
	/* 0x19c4: mov    rcx,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_19cc:
	/* 0x19cc: mov    rax,QWORD PTR [rcx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_19d0:
	/* 0x19d0: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_19d8:
	/* 0x19d8: mov    rax,QWORD PTR [rcx+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_19dc:
	/* 0x19dc: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_19e4:
	/* 0x19e4: movzx  eax,WORD PTR [rcx+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_19e8:
	/* 0x19e8: mov    WORD PTR [rsp+0xaa],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 170ULL);
x86_l_19f0:
	/* 0x19f0: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_19f2:
	/* 0x19f2: js     10b <tail_nodeport_nat_egress_ipv6+0x10b> */
	X86_SIM_X86_JCC(X86_CC_S, 0x19f2, 0x10b, x86_l_10b);
x86_l_19f8:
	/* 0x19f8: mov    eax,0xfffff0ff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294963455ULL);
x86_l_19fd:
	/* 0x19fd: and    eax,DWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 8ULL);
x86_l_1a00:
	/* 0x1a00: or     eax,0x300 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 768ULL);
x86_l_1a05:
	/* 0x1a05: mov    DWORD PTR [rbx+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a08:
	/* 0x1a08: mov    r15,QWORD PTR [rsp+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_1a10:
	/* 0x1a10: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_1a13:
	/* 0x1a13: je     1ab0 <tail_nodeport_nat_egress_ipv6+0x1ab0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a13, 0x1ab0, x86_l_1ab0);
x86_l_1a19:
	/* 0x1a19: movzx  eax,BYTE PTR [r15+0x17] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 23ULL);
x86_l_1a1e:
	/* 0x1a1e: and    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_AND, 3ULL);
x86_l_1a20:
	/* 0x1a20: cmp    al,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 2ULL);
x86_l_1a22:
	/* 0x1a22: jne    1ab0 <tail_nodeport_nat_egress_ipv6+0x1ab0> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1a22, 0x1ab0, x86_l_1ab0);
x86_l_1a28:
	/* 0x1a28: mov    r14d,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a2c:
	/* 0x1a2c: mov    eax,0x2b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_1a31:
	/* 0x1a31: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1a34:
	/* 0x1a34: mov    esi,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 14ULL);
x86_l_1a39:
	/* 0x1a39: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a3b:
	/* 0x1a3b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a3d:
	/* 0x1a3d: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_1a42:
	/* 0x1a42: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1a44:
	/* 0x1a44: jne    10b <tail_nodeport_nat_egress_ipv6+0x10b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1a44, 0x10b, x86_l_10b);
x86_l_1a4a:
	/* 0x1a4a: mov    WORD PTR [rsp+0x28],r14w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1a50:
	/* 0x1a50: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1a55:
	/* 0x1a55: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_1a5a:
	/* 0x1a5a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1a5d:
	/* 0x1a5d: mov    esi,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 12ULL);
x86_l_1a62:
	/* 0x1a62: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1a67:
	/* 0x1a67: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a6a:
	/* 0x1a6a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a6c:
	/* 0x1a6c: mov    ebp,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967155ULL);
x86_l_1a71:
	/* 0x1a71: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1a73:
	/* 0x1a73: js     10b <tail_nodeport_nat_egress_ipv6+0x10b> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1a73, 0x10b, x86_l_10b);
x86_l_1a79:
	/* 0x1a79: mov    r14d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a7c:
	/* 0x1a7c: movabs rax,0x6f00220200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 476743598592ULL);
x86_l_1a86:
	/* 0x1a86: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a8a:
	/* 0x1a8a: mov    rdi,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1a91:
	/* 0x1a91: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1a94:
	/* 0x1a94: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a99:
	/* 0x1a99: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a9b:
	/* 0x1a9b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a9e:
	/* 0x1a9e: je     1c0b <tail_nodeport_nat_egress_ipv6+0x1c0b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a9e, 0x1c0b, x86_l_1c0b);
x86_l_1aa4:
	/* 0x1aa4: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1aa7:
	/* 0x1aa7: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1aab:
	/* 0x1aab: jmp    1c31 <tail_nodeport_nat_egress_ipv6+0x1c31> */
	X86_SIM_X86_JMP(0x1aab, 0x1c31, x86_l_1c31);
x86_l_1ab0:
	/* 0x1ab0: mov    eax,DWORD PTR [rbx+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_1ab3:
	/* 0x1ab3: mov    ecx,DWORD PTR [rbx+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1ab6:
	/* 0x1ab6: lea    rdx,[rax+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1aba:
	/* 0x1aba: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_1abf:
	/* 0x1abf: cmp    rdx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1ac2:
	/* 0x1ac2: ja     10b <tail_nodeport_nat_egress_ipv6+0x10b> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1ac2, 0x10b, x86_l_10b);
x86_l_1ac8:
	/* 0x1ac8: mov    rcx,QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1acc:
	/* 0x1acc: mov    QWORD PTR [rsp+0xf0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_1ad4:
	/* 0x1ad4: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ad8:
	/* 0x1ad8: mov    QWORD PTR [rsp+0xe8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_1ae0:
	/* 0x1ae0: mov    rcx,QWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ae4:
	/* 0x1ae4: mov    QWORD PTR [rsp+0x100],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_1aec:
	/* 0x1aec: mov    rax,QWORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1af0:
	/* 0x1af0: mov    QWORD PTR [rsp+0xf8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_1af8:
	/* 0x1af8: mov    rax,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_supports_fib_lookup_skip_neigh)));
x86_l_1aff:
	/* 0x1aff: movzx  ecx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1b02:
	/* 0x1b02: shl    ecx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 2ULL);
x86_l_1b05:
	/* 0x1b05: lea    rsi,[rsp+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_1b0d:
	/* 0x1b0d: mov    eax,0x45 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 69ULL);
x86_l_1b12:
	/* 0x1b12: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1b15:
	/* 0x1b15: mov    edx,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 64ULL);
x86_l_1b1a:
	/* 0x1b1a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b1c:
	/* 0x1b1c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1b1e:
	/* 0x1b1e: je     1b29 <tail_nodeport_nat_egress_ipv6+0x1b29> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1b1e, 0x1b29, x86_l_1b29);
x86_l_1b20:
	/* 0x1b20: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_1b23:
	/* 0x1b23: jne    1bdc <tail_nodeport_nat_egress_ipv6+0x1bdc> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1b23, 0x1bdc, x86_l_1bdc);
x86_l_1b29:
	/* 0x1b29: mov    r14d,DWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_1b31:
	/* 0x1b31: mov    DWORD PTR [rsp+0x28],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1b36:
	/* 0x1b36: mov    rdi,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_devices)));
x86_l_1b3d:
	/* 0x1b3d: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1b42:
	/* 0x1b42: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1b47:
	/* 0x1b47: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b49:
	/* 0x1b49: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b4c:
	/* 0x1b4c: je     1b58 <tail_nodeport_nat_egress_ipv6+0x1b58> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1b4c, 0x1b58, x86_l_1b58);
x86_l_1b4e:
	/* 0x1b4e: test   BYTE PTR [rax+0x8],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_1b52:
	/* 0x1b52: jne    1be9 <tail_nodeport_nat_egress_ipv6+0x1be9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1b52, 0x1be9, x86_l_1be9);
x86_l_1b58:
	/* 0x1b58: mov    r15d,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b5c:
	/* 0x1b5c: mov    eax,0x2b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_1b61:
	/* 0x1b61: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1b64:
	/* 0x1b64: mov    esi,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 14ULL);
x86_l_1b69:
	/* 0x1b69: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b6b:
	/* 0x1b6b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b6d:
	/* 0x1b6d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1b6f:
	/* 0x1b6f: jne    10b <tail_nodeport_nat_egress_ipv6+0x10b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1b6f, 0x10b, x86_l_10b);
x86_l_1b75:
	/* 0x1b75: mov    WORD PTR [rsp+0x28],r15w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1b7b:
	/* 0x1b7b: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1b80:
	/* 0x1b80: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_1b85:
	/* 0x1b85: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1b88:
	/* 0x1b88: mov    esi,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 12ULL);
x86_l_1b8d:
	/* 0x1b8d: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1b92:
	/* 0x1b92: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b95:
	/* 0x1b95: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b97:
	/* 0x1b97: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1b99:
	/* 0x1b99: js     1d13 <tail_nodeport_nat_egress_ipv6+0x1d13> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1b99, 0x1d13, x86_l_1d13);
x86_l_1b9f:
	/* 0x1b9f: lea    rax,[rsp+0xf8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_1ba7:
	/* 0x1ba7: movzx  ecx,BYTE PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 216ULL);
x86_l_1baf:
	/* 0x1baf: mov    DWORD PTR [rsp+0x28],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1bb3:
	/* 0x1bb3: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bb6:
	/* 0x1bb6: mov    rax,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bba:
	/* 0x1bba: mov    QWORD PTR [rsp+0x2c],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1bbf:
	/* 0x1bbf: mov    QWORD PTR [rsp+0x34],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1bc4:
	/* 0x1bc4: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1bc9:
	/* 0x1bc9: mov    eax,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 152ULL);
x86_l_1bce:
	/* 0x1bce: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_1bd1:
	/* 0x1bd1: mov    edx,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 20ULL);
x86_l_1bd6:
	/* 0x1bd6: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1bd8:
	/* 0x1bd8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bda:
	/* 0x1bda: jmp    1bf5 <tail_nodeport_nat_egress_ipv6+0x1bf5> */
	X86_SIM_X86_JMP(0x1bda, 0x1bf5, x86_l_1bf5);
x86_l_1bdc:
	/* 0x1bdc: mov    ebp,0xffffff57 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967127ULL);
x86_l_1be1:
	/* 0x1be1: mov    r13d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_1be4:
	/* 0x1be4: jmp    10b <tail_nodeport_nat_egress_ipv6+0x10b> */
	X86_SIM_X86_JMP(0x1be4, 0x10b, x86_l_10b);
x86_l_1be9:
	/* 0x1be9: mov    eax,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 23ULL);
x86_l_1bee:
	/* 0x1bee: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_1bf1:
	/* 0x1bf1: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1bf3:
	/* 0x1bf3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bf5:
	/* 0x1bf5: mov    ebp,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_1bf7:
	/* 0x1bf7: mov    r15d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 7ULL);
x86_l_1bfd:
	/* 0x1bfd: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_1c00:
	/* 0x1c00: jne    10b <tail_nodeport_nat_egress_ipv6+0x10b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1c00, 0x10b, x86_l_10b);
x86_l_1c06:
	/* 0x1c06: jmp    5dd <tail_nodeport_nat_egress_ipv6+0x5dd> */
	X86_SIM_X86_JMP(0x1c06, 0x5dd, x86_l_5dd);
x86_l_1c0b:
	/* 0x1c0b: mov    QWORD PTR [rsp+0x28],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691841ULL);
x86_l_1c14:
	/* 0x1c14: mov    QWORD PTR [rsp+0x30],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1c19:
	/* 0x1c19: mov    rdi,QWORD PTR [rip+0x624a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1c20:
	/* 0x1c20: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1c23:
	/* 0x1c23: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1c28:
	/* 0x1c28: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1c2d:
	/* 0x1c2d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c2f:
	/* 0x1c2f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c31:
	/* 0x1c31: test   BYTE PTR [r15+0x17],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 98784247812ULL);
x86_l_1c36:
	/* 0x1c36: jne    1c94 <tail_nodeport_nat_egress_ipv6+0x1c94> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1c36, 0x1c94, x86_l_1c94);
x86_l_1c38:
	/* 0x1c38: mov    eax,DWORD PTR [r15+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1c3c:
	/* 0x1c3c: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1c45:
	/* 0x1c45: mov    DWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_1c4d:
	/* 0x1c4d: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1c56:
	/* 0x1c56: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1c5f:
	/* 0x1c5f: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1c68:
	/* 0x1c68: mov    DWORD PTR [rsp+0x28],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691842ULL);
x86_l_1c70:
	/* 0x1c70: movbe  DWORD PTR [rsp+0x2c],eax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 44ULL);
x86_l_1c76:
	/* 0x1c76: mov    BYTE PTR [rsp+0x3d],0x40 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 261993005120ULL);
x86_l_1c7b:
	/* 0x1c7b: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1c80:
	/* 0x1c80: mov    eax,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 21ULL);
x86_l_1c85:
	/* 0x1c85: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1c88:
	/* 0x1c88: mov    edx,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 28ULL);
x86_l_1c8d:
	/* 0x1c8d: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1c92:
	/* 0x1c92: jmp    1cf3 <tail_nodeport_nat_egress_ipv6+0x1cf3> */
	X86_SIM_X86_JMP(0x1c92, 0x1cf3, x86_l_1cf3);
x86_l_1c94:
	/* 0x1c94: mov    QWORD PTR [rsp+0x4c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 326417514496ULL);
x86_l_1c9d:
	/* 0x1c9d: mov    QWORD PTR [rsp+0x44],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 292057776128ULL);
x86_l_1ca6:
	/* 0x1ca6: mov    QWORD PTR [rsp+0x3c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 257698037760ULL);
x86_l_1caf:
	/* 0x1caf: mov    DWORD PTR [rsp+0x28],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691842ULL);
x86_l_1cb7:
	/* 0x1cb7: mov    eax,DWORD PTR [r15+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1cbb:
	/* 0x1cbb: mov    DWORD PTR [rsp+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1cbf:
	/* 0x1cbf: mov    eax,DWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cc3:
	/* 0x1cc3: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1cc7:
	/* 0x1cc7: mov    eax,DWORD PTR [r15+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1ccb:
	/* 0x1ccb: mov    DWORD PTR [rsp+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1ccf:
	/* 0x1ccf: mov    eax,DWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1cd3:
	/* 0x1cd3: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1cd7:
	/* 0x1cd7: mov    BYTE PTR [rsp+0x3d],0x40 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 261993005120ULL);
x86_l_1cdc:
	/* 0x1cdc: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1ce1:
	/* 0x1ce1: mov    eax,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 21ULL);
x86_l_1ce6:
	/* 0x1ce6: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1ce9:
	/* 0x1ce9: mov    edx,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 28ULL);
x86_l_1cee:
	/* 0x1cee: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1cf3:
	/* 0x1cf3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1cf5:
	/* 0x1cf5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1cf7:
	/* 0x1cf7: js     10b <tail_nodeport_nat_egress_ipv6+0x10b> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1cf7, 0x10b, x86_l_10b);
x86_l_1cfd:
	/* 0x1cfd: mov    eax,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 23ULL);
x86_l_1d02:
	/* 0x1d02: mov    edi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 1ULL);
x86_l_1d07:
	/* 0x1d07: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d09:
	/* 0x1d09: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d0b:
	/* 0x1d0b: mov    r15d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_32);
x86_l_1d0e:
	/* 0x1d0e: jmp    5dd <tail_nodeport_nat_egress_ipv6+0x5dd> */
	X86_SIM_X86_JMP(0x1d0e, 0x5dd, x86_l_5dd);
x86_l_1d13:
	/* 0x1d13: mov    ebp,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_1d15:
	/* 0x1d15: sar    ebp,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SAR, 31ULL);
x86_l_1d18:
	/* 0x1d18: and    ebp,0xffffff73 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4294967155ULL);
x86_l_1d1e:
	/* 0x1d1e: jmp    10b <tail_nodeport_nat_egress_ipv6+0x10b> */
	X86_SIM_X86_JMP(0x1d1e, 0x10b, x86_l_10b);
x86_l_1d23:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
