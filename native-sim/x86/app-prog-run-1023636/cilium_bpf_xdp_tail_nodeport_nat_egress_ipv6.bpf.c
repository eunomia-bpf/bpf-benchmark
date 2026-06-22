extern char __aux_snat_v6_nhm_nat_entry;
extern char __aux_snat_v6_nhm_tuple;
extern char __config_enable_ipv6_fragments;
extern char __config_enable_jiffies;
extern char __config_enable_nodeport_source_lookup;
extern char __config_nodeport_port_max;
extern char __config_supports_fib_lookup_src;
extern char __config_trace_payload_len;
extern char _aux_max_off;
extern char _aux_stride;
extern char cilium_calls;
extern char cilium_devices;
extern char cilium_ipv6_frag_datagrams;
extern char cilium_metrics;
extern char cilium_signals;
extern char cilium_snat_v6_alloc_retries;
extern char cilium_snat_v6_external;
extern char cilium_xdp_scratch;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int cilium_bpf_xdp_tail_nodeport_nat_egress_ipv6_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0x118 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 280ULL);
x86_l_a:
	/* 0xa: mov    QWORD PTR [rsp+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_16:
	/* 0x16: mov    DWORD PTR [rsp+0x100],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1099511627776ULL);
x86_l_21:
	/* 0x21: mov    QWORD PTR [rsp+0xf8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1065151889408ULL);
x86_l_2d:
	/* 0x2d: mov    QWORD PTR [rsp+0xf0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1030792151040ULL);
x86_l_39:
	/* 0x39: mov    QWORD PTR [rsp+0xe8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 996432412672ULL);
x86_l_45:
	/* 0x45: mov    QWORD PTR [rsp+0xe0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 962072674304ULL);
x86_l_51:
	/* 0x51: mov    QWORD PTR [rsp+0xd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 927712935936ULL);
x86_l_5d:
	/* 0x5d: mov    QWORD PTR [rsp+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_69:
	/* 0x69: mov    QWORD PTR [rsp+0xc8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 858993459200ULL);
x86_l_75:
	/* 0x75: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_78:
	/* 0x78: mov    BYTE PTR [rsp+0xc0],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 824633720842ULL);
x86_l_80:
	/* 0x80: mov    eax,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_83:
	/* 0x83: mov    DWORD PTR [rsp+0xc8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_8a:
	/* 0x8a: mov    rcx,QWORD PTR [rip+0x68b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_nodeport_port_max)));
x86_l_91:
	/* 0x91: movzx  r15d,WORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_95:
	/* 0x95: mov    QWORD PTR [rsp+0xa6],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 712964571136ULL);
x86_l_a1:
	/* 0xa1: mov    QWORD PTR [rsp+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_ad:
	/* 0xad: mov    QWORD PTR [rsp+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_b9:
	/* 0xb9: mov    QWORD PTR [rsp+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_c5:
	/* 0xc5: mov    QWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_d1:
	/* 0xd1: mov    rcx,QWORD PTR [rip+0x68b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_d8:
	/* 0xd8: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_da:
	/* 0xda: mov    rbp,QWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_dd:
	/* 0xdd: mov    rcx,QWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e1:
	/* 0xe1: lea    r9,[rbp+0x36] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_e5:
	/* 0xe5: cmp    r9,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R9, X86_RCX, X86_WIDTH_64);
x86_l_e8:
	/* 0xe8: jbe    208 <tail_nodeport_nat_egress_ipv6+0x208> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xe8, 0x208, x86_l_208);
x86_l_ee:
	/* 0xee: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f0:
	/* 0xf0: mov    r12d,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967162ULL);
x86_l_f6:
	/* 0xf6: mov    r14d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R12, X86_WIDTH_32);
x86_l_f9:
	/* 0xf9: neg    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_fc:
	/* 0xfc: cmovs  r14d,r12d */
	X86_SIM_L_EXEC_CMOV(X86_R14, X86_R12, X86_WIDTH_32, X86_CC_S);
x86_l_100:
	/* 0x100: mov    DWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_108:
	/* 0x108: mov    rdi,QWORD PTR [rip+0x68b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_10f:
	/* 0x10f: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_114:
	/* 0x114: mov    r15d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 1ULL);
x86_l_11a:
	/* 0x11a: call   r15 */
	X86_SIM_BPF_CALL_REG(X86_R15);
x86_l_11d:
	/* 0x11d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_120:
	/* 0x120: je     128 <tail_nodeport_nat_egress_ipv6+0x128> */
	X86_SIM_X86_JCC(X86_CC_E, 0x120, 0x128, x86_l_128);
x86_l_122:
	/* 0x122: mov    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_128:
	/* 0x128: mov    DWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_130:
	/* 0x130: mov    rdi,QWORD PTR [rip+0x68b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_137:
	/* 0x137: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_13c:
	/* 0x13c: call   r15 */
	X86_SIM_BPF_CALL_REG(X86_R15);
x86_l_13f:
	/* 0x13f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_142:
	/* 0x142: je     14b <tail_nodeport_nat_egress_ipv6+0x14b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x142, 0x14b, x86_l_14b);
x86_l_144:
	/* 0x144: mov    DWORD PTR [rax+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_14b:
	/* 0x14b: mov    DWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_153:
	/* 0x153: mov    rdi,QWORD PTR [rip+0x68b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_15a:
	/* 0x15a: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_15f:
	/* 0x15f: mov    r15d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 1ULL);
x86_l_165:
	/* 0x165: call   r15 */
	X86_SIM_BPF_CALL_REG(X86_R15);
x86_l_168:
	/* 0x168: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_16b:
	/* 0x16b: je     17d <tail_nodeport_nat_egress_ipv6+0x17d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x16b, 0x17d, x86_l_17d);
x86_l_16d:
	/* 0x16d: movzx  ecx,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_171:
	/* 0x171: movzx  edx,r14b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_R14, X86_WIDTH_32, X86_WIDTH_8);
x86_l_175:
	/* 0x175: shl    ecx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_178:
	/* 0x178: or     ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_17a:
	/* 0x17a: mov    DWORD PTR [rax+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17d:
	/* 0x17d: mov    DWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_185:
	/* 0x185: mov    rdi,QWORD PTR [rip+0x68b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_18c:
	/* 0x18c: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_191:
	/* 0x191: call   r15 */
	X86_SIM_BPF_CALL_REG(X86_R15);
x86_l_194:
	/* 0x194: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_197:
	/* 0x197: je     1a0 <tail_nodeport_nat_egress_ipv6+0x1a0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x197, 0x1a0, x86_l_1a0);
x86_l_199:
	/* 0x199: mov    DWORD PTR [rax+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_1a0:
	/* 0x1a0: mov    DWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1a8:
	/* 0x1a8: mov    rdi,QWORD PTR [rip+0x68b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_1af:
	/* 0x1af: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1b4:
	/* 0x1b4: mov    r15d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 1ULL);
x86_l_1ba:
	/* 0x1ba: call   r15 */
	X86_SIM_BPF_CALL_REG(X86_R15);
x86_l_1bd:
	/* 0x1bd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1c0:
	/* 0x1c0: je     1c9 <tail_nodeport_nat_egress_ipv6+0x1c9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1c0, 0x1c9, x86_l_1c9);
x86_l_1c2:
	/* 0x1c2: mov    DWORD PTR [rax+0x10],0x54c6801 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68808370177ULL);
x86_l_1c9:
	/* 0x1c9: mov    r12,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cd:
	/* 0x1cd: sub    r12,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 0ULL);
x86_l_1d0:
	/* 0x1d0: movabs rax,0x68054c0200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 446765466112ULL);
x86_l_1da:
	/* 0x1da: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1df:
	/* 0x1df: mov    BYTE PTR [rsp+0x10],r14b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e4:
	/* 0x1e4: mov    rdi,QWORD PTR [rip+0x68b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1eb:
	/* 0x1eb: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1f0:
	/* 0x1f0: call   r15 */
	X86_SIM_BPF_CALL_REG(X86_R15);
x86_l_1f3:
	/* 0x1f3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f6:
	/* 0x1f6: je     28d <tail_nodeport_nat_egress_ipv6+0x28d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1f6, 0x28d, x86_l_28d);
x86_l_1fc:
	/* 0x1fc: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1ff:
	/* 0x1ff: add    QWORD PTR [rax+0x8],r12 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_203:
	/* 0x203: jmp    2b5 <tail_nodeport_nat_egress_ipv6+0x2b5> */
	X86_SIM_X86_JMP(0x203, 0x2b5, x86_l_2b5);
x86_l_208:
	/* 0x208: movzx  esi,BYTE PTR [rbp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 20ULL);
x86_l_20c:
	/* 0x20c: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_20f:
	/* 0x20f: mov    r14d,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 40ULL);
x86_l_215:
	/* 0x215: cmp    rsi,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 60ULL);
x86_l_219:
	/* 0x219: ja     59e <tail_nodeport_nat_egress_ipv6+0x59e> */
	X86_SIM_X86_JCC(X86_CC_A, 0x219, 0x59e, x86_l_59e);
x86_l_21f:
	/* 0x21f: mov    r12d,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967140ULL);
x86_l_225:
	/* 0x225: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_22f:
	/* 0x22f: bt     rdx,rsi */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_233:
	/* 0x233: jae    2d6 <tail_nodeport_nat_egress_ipv6+0x2d6> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x233, 0x2d6, x86_l_2d6);
x86_l_239:
	/* 0x239: lea    rdi,[rbp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_23d:
	/* 0x23d: cmp    rdi,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RCX, X86_WIDTH_64);
x86_l_240:
	/* 0x240: ja     46b <tail_nodeport_nat_egress_ipv6+0x46b> */
	X86_SIM_X86_JCC(X86_CC_A, 0x240, 0x46b, x86_l_46b);
x86_l_246:
	/* 0x246: movzx  edi,WORD PTR [r9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R9, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_24a:
	/* 0x24a: mov    r8d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RDI, X86_WIDTH_32);
x86_l_24d:
	/* 0x24d: shr    r8d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_251:
	/* 0x251: cmp    esi,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 43ULL);
x86_l_254:
	/* 0x254: jle    268 <tail_nodeport_nat_egress_ipv6+0x268> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x254, 0x268, x86_l_268);
x86_l_256:
	/* 0x256: cmp    esi,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 44ULL);
x86_l_259:
	/* 0x259: je     2e5 <tail_nodeport_nat_egress_ipv6+0x2e5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x259, 0x2e5, x86_l_2e5);
x86_l_25f:
	/* 0x25f: cmp    esi,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 60ULL);
x86_l_262:
	/* 0x262: jne    34a <tail_nodeport_nat_egress_ipv6+0x34a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x262, 0x34a, x86_l_34a);
x86_l_268:
	/* 0x268: movzx  r8d,r8w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_R8, X86_WIDTH_32, X86_WIDTH_16);
x86_l_26c:
	/* 0x26c: lea    r8d,[r8*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R8, 3), 8ULL);
x86_l_274:
	/* 0x274: cmp    sil,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_8, 44ULL);
x86_l_278:
	/* 0x278: jne    352 <tail_nodeport_nat_egress_ipv6+0x352> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x278, 0x352, x86_l_352);
x86_l_27e:
	/* 0x27e: lea    rsi,[rbp+0x3e] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 62ULL);
x86_l_282:
	/* 0x282: cmp    rsi,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_64);
x86_l_285:
	/* 0x285: ja     46b <tail_nodeport_nat_egress_ipv6+0x46b> */
	X86_SIM_X86_JCC(X86_CC_A, 0x285, 0x46b, x86_l_46b);
x86_l_28b:
	/* 0x28b: jmp    2f8 <tail_nodeport_nat_egress_ipv6+0x2f8> */
	X86_SIM_X86_JMP(0x28b, 0x2f8, x86_l_2f8);
x86_l_28d:
	/* 0x28d: mov    QWORD PTR [rsp+0x40],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906945ULL);
x86_l_296:
	/* 0x296: mov    QWORD PTR [rsp+0x48],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_29b:
	/* 0x29b: mov    rdi,QWORD PTR [rip+0x68b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_2a2:
	/* 0x2a2: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a7:
	/* 0x2a7: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2ac:
	/* 0x2ac: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2b1:
	/* 0x2b1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2b3:
	/* 0x2b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b5:
	/* 0x2b5: mov    rsi,QWORD PTR [rip+0x68b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_2bc:
	/* 0x2bc: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_2c2:
	/* 0x2c2: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2c7:
	/* 0x2c7: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2ca:
	/* 0x2ca: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_2cf:
	/* 0x2cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d1:
	/* 0x2d1: jmp    471 <tail_nodeport_nat_egress_ipv6+0x471> */
	X86_SIM_X86_JMP(0x2d1, 0x471, x86_l_471);
x86_l_2d6:
	/* 0x2d6: cmp    rsi,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 59ULL);
x86_l_2da:
	/* 0x2da: je     471 <tail_nodeport_nat_egress_ipv6+0x471> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2da, 0x471, x86_l_471);
x86_l_2e0:
	/* 0x2e0: jmp    59e <tail_nodeport_nat_egress_ipv6+0x59e> */
	X86_SIM_X86_JMP(0x2e0, 0x59e, x86_l_59e);
x86_l_2e5:
	/* 0x2e5: mov    r8d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 8ULL);
x86_l_2eb:
	/* 0x2eb: lea    rsi,[rbp+0x3e] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 62ULL);
x86_l_2ef:
	/* 0x2ef: cmp    rsi,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_64);
x86_l_2f2:
	/* 0x2f2: ja     46b <tail_nodeport_nat_egress_ipv6+0x46b> */
	X86_SIM_X86_JCC(X86_CC_A, 0x2f2, 0x46b, x86_l_46b);
x86_l_2f8:
	/* 0x2f8: mov    rsi,QWORD PTR [r9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fb:
	/* 0x2fb: rorx   r9,rsi,0x20 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_R9, X86_RSI, X86_WIDTH_64, 0, 32ULL);
x86_l_301:
	/* 0x301: shr    esi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_304:
	/* 0x304: mov    r10d,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_32, 4294967295ULL);
x86_l_30a:
	/* 0x30a: movabs r11,0xff00000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R11, X86_WIDTH_64, 1095216660480ULL);
x86_l_314:
	/* 0x314: or     r11,r10 */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_R10, X86_WIDTH_64, X86_ALU_OR);
x86_l_317:
	/* 0x317: and    r9,r11 */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R11, X86_WIDTH_64, X86_ALU_AND);
x86_l_31a:
	/* 0x31a: movabs r10,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_64, 1099511627776ULL);
x86_l_324:
	/* 0x324: or     r10,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R9, X86_WIDTH_64, X86_ALU_OR);
x86_l_327:
	/* 0x327: test   esi,0xf9ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RSI, X86_WIDTH_32, 63999ULL);
x86_l_32d:
	/* 0x32d: cmove  r10,r9 */
	X86_SIM_L_EXEC_CMOV(X86_R10, X86_R9, X86_WIDTH_64, X86_CC_E);
x86_l_331:
	/* 0x331: movabs r13,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 2199023255552ULL);
x86_l_33b:
	/* 0x33b: or     r13,r10 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R10, X86_WIDTH_64, X86_ALU_OR);
x86_l_33e:
	/* 0x33e: test   esi,0xf8ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RSI, X86_WIDTH_32, 63743ULL);
x86_l_344:
	/* 0x344: cmove  r13,r10 */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_R10, X86_WIDTH_64, X86_CC_E);
x86_l_348:
	/* 0x348: jmp    355 <tail_nodeport_nat_egress_ipv6+0x355> */
	X86_SIM_X86_JMP(0x348, 0x355, x86_l_355);
x86_l_34a:
	/* 0x34a: lea    r8d,[r8*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R8, 2), 8ULL);
x86_l_352:
	/* 0x352: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_355:
	/* 0x355: lea    r14d,[r8+0x28] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_359:
	/* 0x359: cmp    dil,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_8, 60ULL);
x86_l_35d:
	/* 0x35d: ja     572 <tail_nodeport_nat_egress_ipv6+0x572> */
	X86_SIM_X86_JCC(X86_CC_A, 0x35d, 0x572, x86_l_572);
x86_l_363:
	/* 0x363: movzx  r10d,dil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R10, X86_RDI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_367:
	/* 0x367: bt     rdx,r10 */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_R10, X86_WIDTH_64);
x86_l_36b:
	/* 0x36b: jae    3b7 <tail_nodeport_nat_egress_ipv6+0x3b7> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x36b, 0x3b7, x86_l_3b7);
x86_l_36d:
	/* 0x36d: add    r8d,0x36 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_ADD, 54ULL);
x86_l_371:
	/* 0x371: movzx  r9d,r8b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R9, X86_R8, X86_WIDTH_32, X86_WIDTH_8);
x86_l_375:
	/* 0x375: lea    rsi,[r9+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_379:
	/* 0x379: add    rsi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_37d:
	/* 0x37d: cmp    rsi,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_64);
x86_l_380:
	/* 0x380: ja     46b <tail_nodeport_nat_egress_ipv6+0x46b> */
	X86_SIM_X86_JCC(X86_CC_A, 0x380, 0x46b, x86_l_46b);
x86_l_386:
	/* 0x386: add    r9,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_389:
	/* 0x389: movzx  esi,WORD PTR [r9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R9, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_38d:
	/* 0x38d: mov    r8d,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RSI, X86_WIDTH_32);
x86_l_390:
	/* 0x390: shr    r8d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_394:
	/* 0x394: cmp    r10d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 43ULL);
x86_l_398:
	/* 0x398: jle    3c8 <tail_nodeport_nat_egress_ipv6+0x3c8> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x398, 0x3c8, x86_l_3c8);
x86_l_39a:
	/* 0x39a: cmp    r10d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 44ULL);
x86_l_39e:
	/* 0x39e: je     3d8 <tail_nodeport_nat_egress_ipv6+0x3d8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x39e, 0x3d8, x86_l_3d8);
x86_l_3a0:
	/* 0x3a0: cmp    r10d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_32, 51ULL);
x86_l_3a4:
	/* 0x3a4: jne    3c8 <tail_nodeport_nat_egress_ipv6+0x3c8> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3a4, 0x3c8, x86_l_3c8);
x86_l_3a6:
	/* 0x3a6: movzx  edi,r8w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDI, X86_R8, X86_WIDTH_32, X86_WIDTH_16);
x86_l_3aa:
	/* 0x3aa: lea    r8d,[rdi*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 8ULL);
x86_l_3b2:
	/* 0x3b2: jmp    43b <tail_nodeport_nat_egress_ipv6+0x43b> */
	X86_SIM_X86_JMP(0x3b2, 0x43b, x86_l_43b);
x86_l_3b7:
	/* 0x3b7: mov    esi,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RDI, X86_WIDTH_32);
x86_l_3b9:
	/* 0x3b9: cmp    r10,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_64, 59ULL);
x86_l_3bd:
	/* 0x3bd: je     471 <tail_nodeport_nat_egress_ipv6+0x471> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3bd, 0x471, x86_l_471);
x86_l_3c3:
	/* 0x3c3: jmp    59e <tail_nodeport_nat_egress_ipv6+0x59e> */
	X86_SIM_X86_JMP(0x3c3, 0x59e, x86_l_59e);
x86_l_3c8:
	/* 0x3c8: lea    r8d,[r8*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R8, 3), 8ULL);
x86_l_3d0:
	/* 0x3d0: cmp    dil,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_8, 44ULL);
x86_l_3d4:
	/* 0x3d4: je     3de <tail_nodeport_nat_egress_ipv6+0x3de> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3d4, 0x3de, x86_l_3de);
x86_l_3d6:
	/* 0x3d6: jmp    43b <tail_nodeport_nat_egress_ipv6+0x43b> */
	X86_SIM_X86_JMP(0x3d6, 0x43b, x86_l_43b);
x86_l_3d8:
	/* 0x3d8: mov    r8d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 8ULL);
x86_l_3de:
	/* 0x3de: lea    rdi,[r9+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3e2:
	/* 0x3e2: cmp    rdi,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RCX, X86_WIDTH_64);
x86_l_3e5:
	/* 0x3e5: ja     46b <tail_nodeport_nat_egress_ipv6+0x46b> */
	X86_SIM_X86_JCC(X86_CC_A, 0x3e5, 0x46b, x86_l_46b);
x86_l_3eb:
	/* 0x3eb: mov    rdi,QWORD PTR [r9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3ee:
	/* 0x3ee: rorx   r9,rdi,0x20 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_R9, X86_RDI, X86_WIDTH_64, 0, 32ULL);
x86_l_3f4:
	/* 0x3f4: shr    edi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_3f7:
	/* 0x3f7: mov    r10d,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_32, 4294967295ULL);
x86_l_3fd:
	/* 0x3fd: movabs r11,0xff00000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R11, X86_WIDTH_64, 1095216660480ULL);
x86_l_407:
	/* 0x407: or     r11,r10 */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_R10, X86_WIDTH_64, X86_ALU_OR);
x86_l_40a:
	/* 0x40a: and    r9,r11 */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R11, X86_WIDTH_64, X86_ALU_AND);
x86_l_40d:
	/* 0x40d: movabs r10,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_64, 1099511627776ULL);
x86_l_417:
	/* 0x417: or     r10,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R9, X86_WIDTH_64, X86_ALU_OR);
x86_l_41a:
	/* 0x41a: test   edi,0xf9ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDI, X86_WIDTH_32, 63999ULL);
x86_l_420:
	/* 0x420: cmove  r10,r9 */
	X86_SIM_L_EXEC_CMOV(X86_R10, X86_R9, X86_WIDTH_64, X86_CC_E);
x86_l_424:
	/* 0x424: movabs r13,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 2199023255552ULL);
x86_l_42e:
	/* 0x42e: or     r13,r10 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R10, X86_WIDTH_64, X86_ALU_OR);
x86_l_431:
	/* 0x431: test   edi,0xf8ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDI, X86_WIDTH_32, 63743ULL);
x86_l_437:
	/* 0x437: cmove  r13,r10 */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_R10, X86_WIDTH_64, X86_CC_E);
x86_l_43b:
	/* 0x43b: add    r14d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R8, X86_WIDTH_32, X86_ALU_ADD);
x86_l_43e:
	/* 0x43e: cmp    sil,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_8, 60ULL);
x86_l_442:
	/* 0x442: ja     59e <tail_nodeport_nat_egress_ipv6+0x59e> */
	X86_SIM_X86_JCC(X86_CC_A, 0x442, 0x59e, x86_l_59e);
x86_l_448:
	/* 0x448: movzx  r8d,sil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_RSI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_44c:
	/* 0x44c: bt     rdx,r8 */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_R8, X86_WIDTH_64);
x86_l_450:
	/* 0x450: jae    594 <tail_nodeport_nat_egress_ipv6+0x594> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x450, 0x594, x86_l_594);
x86_l_456:
	/* 0x456: lea    edi,[r14+0xe] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_45a:
	/* 0x45a: movzx  r9d,dil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R9, X86_RDI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_45e:
	/* 0x45e: lea    rdi,[r9+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_462:
	/* 0x462: add    rdi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_466:
	/* 0x466: cmp    rdi,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RCX, X86_WIDTH_64);
x86_l_469:
	/* 0x469: jbe    483 <tail_nodeport_nat_egress_ipv6+0x483> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x469, 0x483, x86_l_483);
x86_l_46b:
	/* 0x46b: mov    r12d,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967162ULL);
x86_l_471:
	/* 0x471: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_474:
	/* 0x474: add    rsp,0x118 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 280ULL);
x86_l_47b:
	/* 0x47b: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_47d:
	/* 0x47d: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_47e:
	/* 0x47e: jmp    1bba <tail_nodeport_nat_egress_ipv6+0x1bba> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_483:
	/* 0x483: add    r9,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_486:
	/* 0x486: movzx  edi,WORD PTR [r9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R9, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_48a:
	/* 0x48a: mov    r10d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R10, X86_RDI, X86_WIDTH_32);
x86_l_48d:
	/* 0x48d: shr    r10d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_491:
	/* 0x491: cmp    r8d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 43ULL);
x86_l_495:
	/* 0x495: jle    4b1 <tail_nodeport_nat_egress_ipv6+0x4b1> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x495, 0x4b1, x86_l_4b1);
x86_l_497:
	/* 0x497: cmp    r8d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 44ULL);
x86_l_49b:
	/* 0x49b: je     4c1 <tail_nodeport_nat_egress_ipv6+0x4c1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x49b, 0x4c1, x86_l_4c1);
x86_l_49d:
	/* 0x49d: cmp    r8d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 51ULL);
x86_l_4a1:
	/* 0x4a1: jne    4b1 <tail_nodeport_nat_egress_ipv6+0x4b1> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4a1, 0x4b1, x86_l_4b1);
x86_l_4a3:
	/* 0x4a3: movzx  esi,r10w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_R10, X86_WIDTH_32, X86_WIDTH_16);
x86_l_4a7:
	/* 0x4a7: lea    r8d,[rsi*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 8ULL);
x86_l_4af:
	/* 0x4af: jmp    520 <tail_nodeport_nat_egress_ipv6+0x520> */
	X86_SIM_X86_JMP(0x4af, 0x520, x86_l_520);
x86_l_4b1:
	/* 0x4b1: lea    r8d,[r10*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R10, 3), 8ULL);
x86_l_4b9:
	/* 0x4b9: cmp    sil,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_8, 44ULL);
x86_l_4bd:
	/* 0x4bd: je     4c7 <tail_nodeport_nat_egress_ipv6+0x4c7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4bd, 0x4c7, x86_l_4c7);
x86_l_4bf:
	/* 0x4bf: jmp    520 <tail_nodeport_nat_egress_ipv6+0x520> */
	X86_SIM_X86_JMP(0x4bf, 0x520, x86_l_520);
x86_l_4c1:
	/* 0x4c1: mov    r8d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 8ULL);
x86_l_4c7:
	/* 0x4c7: lea    rsi,[r9+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4cb:
	/* 0x4cb: cmp    rsi,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_64);
x86_l_4ce:
	/* 0x4ce: ja     46b <tail_nodeport_nat_egress_ipv6+0x46b> */
	X86_SIM_X86_JCC(X86_CC_A, 0x4ce, 0x46b, x86_l_46b);
x86_l_4d0:
	/* 0x4d0: mov    rsi,QWORD PTR [r9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4d3:
	/* 0x4d3: rorx   r9,rsi,0x20 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_R9, X86_RSI, X86_WIDTH_64, 0, 32ULL);
x86_l_4d9:
	/* 0x4d9: shr    esi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_4dc:
	/* 0x4dc: mov    r10d,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_32, 4294967295ULL);
x86_l_4e2:
	/* 0x4e2: movabs r11,0xff00000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R11, X86_WIDTH_64, 1095216660480ULL);
x86_l_4ec:
	/* 0x4ec: or     r11,r10 */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_R10, X86_WIDTH_64, X86_ALU_OR);
x86_l_4ef:
	/* 0x4ef: and    r9,r11 */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R11, X86_WIDTH_64, X86_ALU_AND);
x86_l_4f2:
	/* 0x4f2: movabs r10,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_64, 1099511627776ULL);
x86_l_4fc:
	/* 0x4fc: or     r10,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R9, X86_WIDTH_64, X86_ALU_OR);
x86_l_4ff:
	/* 0x4ff: test   esi,0xf9ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RSI, X86_WIDTH_32, 63999ULL);
x86_l_505:
	/* 0x505: cmove  r10,r9 */
	X86_SIM_L_EXEC_CMOV(X86_R10, X86_R9, X86_WIDTH_64, X86_CC_E);
x86_l_509:
	/* 0x509: movabs r13,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 2199023255552ULL);
x86_l_513:
	/* 0x513: or     r13,r10 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R10, X86_WIDTH_64, X86_ALU_OR);
x86_l_516:
	/* 0x516: test   esi,0xf8ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RSI, X86_WIDTH_32, 63743ULL);
x86_l_51c:
	/* 0x51c: cmove  r13,r10 */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_R10, X86_WIDTH_64, X86_CC_E);
x86_l_520:
	/* 0x520: add    r14d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R8, X86_WIDTH_32, X86_ALU_ADD);
x86_l_523:
	/* 0x523: cmp    dil,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_8, 60ULL);
x86_l_527:
	/* 0x527: ja     572 <tail_nodeport_nat_egress_ipv6+0x572> */
	X86_SIM_X86_JCC(X86_CC_A, 0x527, 0x572, x86_l_572);
x86_l_529:
	/* 0x529: movzx  r8d,dil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_RDI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_52d:
	/* 0x52d: bt     rdx,r8 */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_R8, X86_WIDTH_64);
x86_l_531:
	/* 0x531: jae    592 <tail_nodeport_nat_egress_ipv6+0x592> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x531, 0x592, x86_l_592);
x86_l_533:
	/* 0x533: add    r14d,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 14ULL);
x86_l_537:
	/* 0x537: movzx  eax,r14b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R14, X86_WIDTH_32, X86_WIDTH_8);
x86_l_53b:
	/* 0x53b: lea    rdx,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_53f:
	/* 0x53f: add    rdx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_543:
	/* 0x543: mov    r12d,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967162ULL);
x86_l_549:
	/* 0x549: cmp    rdx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_54c:
	/* 0x54c: ja     471 <tail_nodeport_nat_egress_ipv6+0x471> */
	X86_SIM_X86_JCC(X86_CC_A, 0x54c, 0x471, x86_l_471);
x86_l_552:
	/* 0x552: add    rbp,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_555:
	/* 0x555: add    rbp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_559:
	/* 0x559: cmp    rbp,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RCX, X86_WIDTH_64);
x86_l_55c:
	/* 0x55c: mov    eax,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967140ULL);
x86_l_561:
	/* 0x561: cmovbe r12d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RAX, X86_WIDTH_32, X86_CC_BE);
x86_l_565:
	/* 0x565: cmp    dil,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_8, 44ULL);
x86_l_569:
	/* 0x569: cmovne r12d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RAX, X86_WIDTH_32, X86_CC_NE);
x86_l_56d:
	/* 0x56d: jmp    471 <tail_nodeport_nat_egress_ipv6+0x471> */
	X86_SIM_X86_JMP(0x56d, 0x471, x86_l_471);
x86_l_572:
	/* 0x572: mov    esi,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RDI, X86_WIDTH_32);
x86_l_574:
	/* 0x574: mov    BYTE PTR [rsp+0xac],sil */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_57c:
	/* 0x57c: mov    rcx,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_nodeport_source_lookup)));
x86_l_583:
	/* 0x583: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_586:
	/* 0x586: jne    5b2 <tail_nodeport_nat_egress_ipv6+0x5b2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x586, 0x5b2, x86_l_5b2);
x86_l_588:
	/* 0x588: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_58b:
	/* 0x58b: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_58d:
	/* 0x58d: jmp    674 <tail_nodeport_nat_egress_ipv6+0x674> */
	X86_SIM_X86_JMP(0x58d, 0x674, x86_l_674);
x86_l_592:
	/* 0x592: mov    esi,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RDI, X86_WIDTH_32);
x86_l_594:
	/* 0x594: cmp    r8,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_64, 59ULL);
x86_l_598:
	/* 0x598: je     471 <tail_nodeport_nat_egress_ipv6+0x471> */
	X86_SIM_X86_JCC(X86_CC_E, 0x598, 0x471, x86_l_471);
x86_l_59e:
	/* 0x59e: mov    BYTE PTR [rsp+0xac],sil */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_5a6:
	/* 0x5a6: mov    rcx,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_nodeport_source_lookup)));
x86_l_5ad:
	/* 0x5ad: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5b0:
	/* 0x5b0: je     588 <tail_nodeport_nat_egress_ipv6+0x588> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5b0, 0x588, x86_l_588);
x86_l_5b2:
	/* 0x5b2: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_5bd:
	/* 0x5bd: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_5c6:
	/* 0x5c6: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_5cf:
	/* 0x5cf: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_5d8:
	/* 0x5d8: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_5e1:
	/* 0x5e1: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_5ea:
	/* 0x5ea: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_5f3:
	/* 0x5f3: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_5fc:
	/* 0x5fc: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_605:
	/* 0x605: mov    rcx,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_supports_fib_lookup_src)));
x86_l_60c:
	/* 0x60c: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_60f:
	/* 0x60f: je     65b <tail_nodeport_nat_egress_ipv6+0x65b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x60f, 0x65b, x86_l_65b);
x86_l_611:
	/* 0x611: mov    BYTE PTR [rsp+0x40],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 274877906954ULL);
x86_l_616:
	/* 0x616: mov    DWORD PTR [rsp+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_61a:
	/* 0x61a: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_623:
	/* 0x623: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_62c:
	/* 0x62c: mov    rax,QWORD PTR [rbp+0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 46ULL);
x86_l_630:
	/* 0x630: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_635:
	/* 0x635: mov    rax,QWORD PTR [rbp+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_639:
	/* 0x639: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_63e:
	/* 0x63e: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_643:
	/* 0x643: mov    eax,0x45 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 69ULL);
x86_l_648:
	/* 0x648: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_64b:
	/* 0x64b: mov    edx,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 64ULL);
x86_l_650:
	/* 0x650: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_655:
	/* 0x655: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_657:
	/* 0x657: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_659:
	/* 0x659: je     662 <tail_nodeport_nat_egress_ipv6+0x662> */
	X86_SIM_X86_JCC(X86_CC_E, 0x659, 0x662, x86_l_662);
x86_l_65b:
	/* 0x65b: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_65e:
	/* 0x65e: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_660:
	/* 0x660: jmp    66c <tail_nodeport_nat_egress_ipv6+0x66c> */
	X86_SIM_X86_JMP(0x660, 0x66c, x86_l_66c);
x86_l_662:
	/* 0x662: mov    r8,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_667:
	/* 0x667: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_66c:
	/* 0x66c: movzx  esi,BYTE PTR [rsp+0xac] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 172ULL);
x86_l_674:
	/* 0x674: mov    rax,QWORD PTR [rbp+0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 46ULL);
x86_l_678:
	/* 0x678: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_680:
	/* 0x680: mov    rax,QWORD PTR [rbp+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_684:
	/* 0x684: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_68c:
	/* 0x68c: mov    rax,QWORD PTR [rbp+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_690:
	/* 0x690: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_698:
	/* 0x698: mov    rax,QWORD PTR [rbp+0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_69c:
	/* 0x69c: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_6a4:
	/* 0x6a4: cmp    sil,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_8, 6ULL);
x86_l_6a8:
	/* 0x6a8: je     6b8 <tail_nodeport_nat_egress_ipv6+0x6b8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6a8, 0x6b8, x86_l_6b8);
x86_l_6aa:
	/* 0x6aa: movzx  eax,sil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RSI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_6ae:
	/* 0x6ae: cmp    eax,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 58ULL);
x86_l_6b1:
	/* 0x6b1: je     71e <tail_nodeport_nat_egress_ipv6+0x71e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6b1, 0x71e, x86_l_71e);
x86_l_6b3:
	/* 0x6b3: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_6b6:
	/* 0x6b6: jne    72b <tail_nodeport_nat_egress_ipv6+0x72b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x6b6, 0x72b, x86_l_72b);
x86_l_6b8:
	/* 0x6b8: add    r14d,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 14ULL);
x86_l_6bc:
	/* 0x6bc: movabs rcx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2199023255552ULL);
x86_l_6c6:
	/* 0x6c6: mov    rax,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_6cd:
	/* 0x6cd: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6d0:
	/* 0x6d0: je     738 <tail_nodeport_nat_egress_ipv6+0x738> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6d0, 0x738, x86_l_738);
x86_l_6d2:
	/* 0x6d2: lea    rsi,[rbp+0xe] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_6d6:
	/* 0x6d6: mov    r9,QWORD PTR [rbp+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_6da:
	/* 0x6da: mov    QWORD PTR [rbp+0xe],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60129542144ULL);
x86_l_6e2:
	/* 0x6e2: mov    DWORD PTR [rbp+0xe],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_6e6:
	/* 0x6e6: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_6e9:
	/* 0x6e9: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_6ed:
	/* 0x6ed: mov    BYTE PTR [rbp+0x12],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_6f0:
	/* 0x6f0: test   r13,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_RCX, X86_WIDTH_64);
x86_l_6f3:
	/* 0x6f3: jne    14bf <tail_nodeport_nat_egress_ipv6+0x14bf> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x6f3, 0x14bf, x86_l_14bf);
x86_l_6f9:
	/* 0x6f9: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6fc:
	/* 0x6fc: movzx  ecx,r14b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R14, X86_WIDTH_32, X86_WIDTH_8);
x86_l_700:
	/* 0x700: lea    rdx,[rax+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_704:
	/* 0x704: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_708:
	/* 0x708: mov    r12d,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967161ULL);
x86_l_70e:
	/* 0x70e: cmp    rdx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_712:
	/* 0x712: jbe    766 <tail_nodeport_nat_egress_ipv6+0x766> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x712, 0x766, x86_l_766);
x86_l_714:
	/* 0x714: mov    QWORD PTR [rsi],r9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_717:
	/* 0x717: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_719:
	/* 0x719: jmp    f6 <tail_nodeport_nat_egress_ipv6+0xf6> */
	X86_SIM_X86_JMP(0x719, 0xf6, x86_l_f6);
x86_l_71e:
	/* 0x71e: mov    r12d,0xffffff61 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967137ULL);
x86_l_724:
	/* 0x724: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_726:
	/* 0x726: jmp    f6 <tail_nodeport_nat_egress_ipv6+0xf6> */
	X86_SIM_X86_JMP(0x726, 0xf6, x86_l_f6);
x86_l_72b:
	/* 0x72b: mov    r12d,0xffffff72 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967154ULL);
x86_l_731:
	/* 0x731: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_733:
	/* 0x733: jmp    f6 <tail_nodeport_nat_egress_ipv6+0xf6> */
	X86_SIM_X86_JMP(0x733, 0xf6, x86_l_f6);
x86_l_738:
	/* 0x738: test   r13,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_RCX, X86_WIDTH_64);
x86_l_73b:
	/* 0x73b: jne    1504 <tail_nodeport_nat_egress_ipv6+0x1504> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x73b, 0x1504, x86_l_1504);
x86_l_741:
	/* 0x741: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_744:
	/* 0x744: mov    rcx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_748:
	/* 0x748: movzx  edx,r14b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_R14, X86_WIDTH_32, X86_WIDTH_8);
x86_l_74c:
	/* 0x74c: lea    rsi,[rax+rdx*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_750:
	/* 0x750: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_754:
	/* 0x754: cmp    rsi,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_64);
x86_l_757:
	/* 0x757: jbe    799 <tail_nodeport_nat_egress_ipv6+0x799> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x757, 0x799, x86_l_799);
x86_l_759:
	/* 0x759: mov    r12d,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967161ULL);
x86_l_75f:
	/* 0x75f: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_761:
	/* 0x761: jmp    f6 <tail_nodeport_nat_egress_ipv6+0xf6> */
	X86_SIM_X86_JMP(0x761, 0xf6, x86_l_f6);
x86_l_766:
	/* 0x766: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_769:
	/* 0x769: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_76b:
	/* 0x76b: mov    DWORD PTR [rsp+0xa8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_772:
	/* 0x772: bt     r13,0x28 */
	X86_SIM_L_EXEC_BT_IMM(X86_R13, X86_WIDTH_64, 40ULL);
x86_l_777:
	/* 0x777: jb     151f <tail_nodeport_nat_egress_ipv6+0x151f> */
	X86_SIM_X86_JCC(X86_CC_B, 0x777, 0x151f, x86_l_151f);
x86_l_77d:
	/* 0x77d: mov    QWORD PTR [rsi],r9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSI, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_780:
	/* 0x780: movzx  edx,WORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 168ULL);
x86_l_788:
	/* 0x788: movzx  esi,WORD PTR [rsp+0xaa] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 170ULL);
x86_l_790:
	/* 0x790: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_793:
	/* 0x793: mov    rcx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_797:
	/* 0x797: jmp    7a3 <tail_nodeport_nat_egress_ipv6+0x7a3> */
	X86_SIM_X86_JMP(0x797, 0x7a3, x86_l_7a3);
x86_l_799:
	/* 0x799: add    rdx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_79c:
	/* 0x79c: mov    edx,DWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_79e:
	/* 0x79e: mov    esi,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_7a0:
	/* 0x7a0: shr    esi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_7a3:
	/* 0x7a3: mov    WORD PTR [rsp+0xaa],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 170ULL);
x86_l_7ab:
	/* 0x7ab: mov    WORD PTR [rsp+0xa8],si */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_7b3:
	/* 0x7b3: mov    BYTE PTR [rsp+0xad],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 743029342208ULL);
x86_l_7bb:
	/* 0x7bb: lea    rdx,[rax+0x16] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_7bf:
	/* 0x7bf: cmp    rdx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_7c2:
	/* 0x7c2: ja     ee <tail_nodeport_nat_egress_ipv6+0xee> */
	X86_SIM_X86_JCC(X86_CC_A, 0x7c2, 0xee, x86_l_ee);
x86_l_7c8:
	/* 0x7c8: movzx  ecx,BYTE PTR [rax+0x15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 21ULL);
x86_l_7cc:
	/* 0x7cc: cmp    cl,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_7cf:
	/* 0x7cf: jae    7de <tail_nodeport_nat_egress_ipv6+0x7de> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x7cf, 0x7de, x86_l_7de);
x86_l_7d1:
	/* 0x7d1: mov    r12d,0xffffff3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967100ULL);
x86_l_7d7:
	/* 0x7d7: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7d9:
	/* 0x7d9: jmp    f6 <tail_nodeport_nat_egress_ipv6+0xf6> */
	X86_SIM_X86_JMP(0x7d9, 0xf6, x86_l_f6);
x86_l_7de:
	/* 0x7de: mov    QWORD PTR [rsp],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7e2:
	/* 0x7e2: mov    QWORD PTR [rsp+0x8],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7e7:
	/* 0x7e7: mov    QWORD PTR [rsp+0xb8],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_7ef:
	/* 0x7ef: dec    cl */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_DEC, 1);
x86_l_7f1:
	/* 0x7f1: mov    BYTE PTR [rax+0x15],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 21ULL);
x86_l_7f4:
	/* 0x7f4: mov    rdi,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_7fb:
	/* 0x7fb: lea    rsi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_803:
	/* 0x803: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_808:
	/* 0x808: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_80a:
	/* 0x80a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_80d:
	/* 0x80d: je     916 <tail_nodeport_nat_egress_ipv6+0x916> */
	X86_SIM_X86_JCC(X86_CC_E, 0x80d, 0x916, x86_l_916);
x86_l_813:
	/* 0x813: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_818:
	/* 0x818: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_81d:
	/* 0x81d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_81f:
	/* 0x81f: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_821:
	/* 0x821: mov    rbp,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBP, (void *)(long)(((__u64)(long)&_aux_stride)));
x86_l_828:
	/* 0x828: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_82a:
	/* 0x82a: imul   rax,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_82f:
	/* 0x82f: mov    r12,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&_aux_max_off)));
x86_l_836:
	/* 0x836: cmp    rax,QWORD PTR [r12] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_83a:
	/* 0x83a: jbe    840 <tail_nodeport_nat_egress_ipv6+0x840> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x83a, 0x840, x86_l_840);
x86_l_83c:
	/* 0x83c: mov    rax,QWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_840:
	/* 0x840: mov    rcx,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__aux_snat_v6_nhm_tuple)));
x86_l_847:
	/* 0x847: lea    r14,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_84b:
	/* 0x84b: mov    BYTE PTR [rcx+rax*1+0x25],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 158913789953ULL);
x86_l_850:
	/* 0x850: movzx  edx,BYTE PTR [rsp+0xac] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 172ULL);
x86_l_858:
	/* 0x858: mov    BYTE PTR [rcx+rax*1+0x24],dl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 36ULL);
x86_l_85c:
	/* 0x85c: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_864:
	/* 0x864: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_86c:
	/* 0x86c: mov    QWORD PTR [rcx+rax*1+0x10],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 16ULL);
x86_l_871:
	/* 0x871: mov    QWORD PTR [rcx+rax*1+0x18],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 24ULL);
x86_l_876:
	/* 0x876: mov    rdi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_87b:
	/* 0x87b: mov    rdx,QWORD PTR [rdi+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_87f:
	/* 0x87f: mov    rsi,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_883:
	/* 0x883: mov    QWORD PTR [rcx+rax*1],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_887:
	/* 0x887: mov    QWORD PTR [rcx+rax*1+0x8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 8ULL);
x86_l_88c:
	/* 0x88c: movzx  edx,WORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 168ULL);
x86_l_894:
	/* 0x894: mov    WORD PTR [rcx+rax*1+0x22],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 0), 34ULL);
x86_l_899:
	/* 0x899: movzx  edx,WORD PTR [rdi+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_89d:
	/* 0x89d: mov    WORD PTR [rcx+rax*1+0x20],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 0), 32ULL);
x86_l_8a2:
	/* 0x8a2: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8a7:
	/* 0x8a7: cmp    rax,QWORD PTR [rdi+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_8ab:
	/* 0x8ab: jne    8c2 <tail_nodeport_nat_egress_ipv6+0x8c2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x8ab, 0x8c2, x86_l_8c2);
x86_l_8ad:
	/* 0x8ad: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8b1:
	/* 0x8b1: cmp    rax,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 40ULL);
x86_l_8b5:
	/* 0x8b5: jne    8c2 <tail_nodeport_nat_egress_ipv6+0x8c2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x8b5, 0x8c2, x86_l_8c2);
x86_l_8b7:
	/* 0x8b7: cmp    QWORD PTR [rdi+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_8bc:
	/* 0x8bc: je     1345 <tail_nodeport_nat_egress_ipv6+0x1345> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8bc, 0x1345, x86_l_1345);
x86_l_8c2:
	/* 0x8c2: mov    rdi,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_8c9:
	/* 0x8c9: lea    rsi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_8d1:
	/* 0x8d1: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_8d6:
	/* 0x8d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8d8:
	/* 0x8d8: mov    r12d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_32);
x86_l_8db:
	/* 0x8db: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8dd:
	/* 0x8dd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_8df:
	/* 0x8df: js     175c <tail_nodeport_nat_egress_ipv6+0x175c> */
	X86_SIM_X86_JCC(X86_CC_S, 0x8df, 0x175c, x86_l_175c);
x86_l_8e5:
	/* 0x8e5: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_8e9:
	/* 0x8e9: je     175c <tail_nodeport_nat_egress_ipv6+0x175c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8e9, 0x175c, x86_l_175c);
x86_l_8ef:
	/* 0x8ef: mov    rdi,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_8f6:
	/* 0x8f6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_8fb:
	/* 0x8fb: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_8fe:
	/* 0x8fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_900:
	/* 0x900: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_903:
	/* 0x903: je     916 <tail_nodeport_nat_egress_ipv6+0x916> */
	X86_SIM_X86_JCC(X86_CC_E, 0x903, 0x916, x86_l_916);
x86_l_905:
	/* 0x905: mov    rdi,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_90c:
	/* 0x90c: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_911:
	/* 0x911: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_914:
	/* 0x914: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_916:
	/* 0x916: lea    ebp,[r15+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_91a:
	/* 0x91a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_91f:
	/* 0x91f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_921:
	/* 0x921: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_923:
	/* 0x923: mov    rcx,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&_aux_stride)));
x86_l_92a:
	/* 0x92a: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_92c:
	/* 0x92c: imul   rax,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_930:
	/* 0x930: mov    rcx,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&_aux_max_off)));
x86_l_937:
	/* 0x937: cmp    rax,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_93a:
	/* 0x93a: jbe    93f <tail_nodeport_nat_egress_ipv6+0x93f> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x93a, 0x93f, x86_l_93f);
x86_l_93c:
	/* 0x93c: mov    rax,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_93f:
	/* 0x93f: mov    rcx,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__aux_snat_v6_nhm_nat_entry)));
x86_l_946:
	/* 0x946: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_94f:
	/* 0x94f: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_958:
	/* 0x958: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_961:
	/* 0x961: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_96a:
	/* 0x96a: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_973:
	/* 0x973: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_97c:
	/* 0x97c: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_985:
	/* 0x985: mov    QWORD PTR [rcx+rax*1],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_98d:
	/* 0x98d: mov    QWORD PTR [rcx+rax*1+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 34359738368ULL);
x86_l_996:
	/* 0x996: mov    QWORD PTR [rcx+rax*1+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 68719476736ULL);
x86_l_99f:
	/* 0x99f: mov    QWORD PTR [rcx+rax*1+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 103079215104ULL);
x86_l_9a8:
	/* 0x9a8: mov    QWORD PTR [rcx+rax*1+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 137438953472ULL);
x86_l_9b1:
	/* 0x9b1: mov    QWORD PTR [rcx+rax*1+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 171798691840ULL);
x86_l_9ba:
	/* 0x9ba: mov    QWORD PTR [rcx+rax*1+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 206158430208ULL);
x86_l_9c3:
	/* 0x9c3: lea    rsi,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_9cb:
	/* 0x9cb: mov    rdx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9ce:
	/* 0x9ce: mov    rsi,QWORD PTR [rsi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9d2:
	/* 0x9d2: mov    QWORD PTR [rsp+0x60],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_9d7:
	/* 0x9d7: mov    QWORD PTR [rsp+0x68],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_9dc:
	/* 0x9dc: movzx  r14d,WORD PTR [rsp+0xaa] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 170ULL);
x86_l_9e5:
	/* 0x9e5: mov    WORD PTR [rsp+0x70],r14w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_9eb:
	/* 0x9eb: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9f0:
	/* 0x9f0: mov    QWORD PTR [rcx+rax*1+0x20],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 32ULL);
x86_l_9f5:
	/* 0x9f5: mov    r8,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9f9:
	/* 0x9f9: mov    QWORD PTR [rcx+rax*1+0x28],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 40ULL);
x86_l_9fe:
	/* 0x9fe: mov    BYTE PTR [rsp+0x35],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 227633266689ULL);
x86_l_a03:
	/* 0xa03: movzx  edx,BYTE PTR [rsp+0xac] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 172ULL);
x86_l_a0b:
	/* 0xa0b: mov    BYTE PTR [rsp+0x34],dl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_a0f:
	/* 0xa0f: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_a17:
	/* 0xa17: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_a1f:
	/* 0xa1f: mov    QWORD PTR [rsp+0x20],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a24:
	/* 0xa24: mov    QWORD PTR [rsp+0x28],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a29:
	/* 0xa29: mov    QWORD PTR [rsp+0x18],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_a2e:
	/* 0xa2e: mov    QWORD PTR [rsp+0x10],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a33:
	/* 0xa33: movzx  edx,WORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 168ULL);
x86_l_a3b:
	/* 0xa3b: mov    WORD PTR [rsp+0x32],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 50ULL);
x86_l_a40:
	/* 0xa40: lea    r12,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_a44:
	/* 0xa44: mov    WORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_a4b:
	/* 0xa4b: rol    r14w,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_a50:
	/* 0xa50: cmp    r14w,bp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R14, X86_RBP, X86_WIDTH_16);
x86_l_a54:
	/* 0xa54: jae    a77 <tail_nodeport_nat_egress_ipv6+0xa77> */
	X86_SIM_X86_JCC(X86_CC_AE, 0xa54, 0xa77, x86_l_a77);
x86_l_a56:
	/* 0xa56: mov    ecx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_a5b:
	/* 0xa5b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a5d:
	/* 0xa5d: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_a5f:
	/* 0xa5f: mov    ecx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_32);
x86_l_a62:
	/* 0xa62: xor    ecx,0xffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 65535ULL);
x86_l_a68:
	/* 0xa68: movzx  r14d,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_a6c:
	/* 0xa6c: imul   r14d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_a70:
	/* 0xa70: shr    r14d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_a74:
	/* 0xa74: add    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_a77:
	/* 0xa77: mov    QWORD PTR [r12+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_a80:
	/* 0xa80: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_a89:
	/* 0xa89: mov    rax,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_a90:
	/* 0xa90: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a93:
	/* 0xa93: mov    QWORD PTR [rsp+0x38],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_a98:
	/* 0xa98: je     aa9 <tail_nodeport_nat_egress_ipv6+0xaa9> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa98, 0xaa9, x86_l_aa9);
x86_l_a9a:
	/* 0xa9a: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_a9f:
	/* 0xa9f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_aa1:
	/* 0xaa1: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_aa3:
	/* 0xaa3: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_aa7:
	/* 0xaa7: jmp    acc <tail_nodeport_nat_egress_ipv6+0xacc> */
	X86_SIM_X86_JMP(0xaa7, 0xacc, x86_l_acc);
x86_l_aa9:
	/* 0xaa9: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_aae:
	/* 0xaae: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ab0:
	/* 0xab0: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_ab2:
	/* 0xab2: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_ab6:
	/* 0xab6: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_ac0:
	/* 0xac0: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_ac3:
	/* 0xac3: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_ac8:
	/* 0xac8: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_acc:
	/* 0xacc: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_ad1:
	/* 0xad1: movbe  WORD PTR [rsp+0x30],r14w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_ad9:
	/* 0xad9: mov    rdi,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_ae0:
	/* 0xae0: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ae5:
	/* 0xae5: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_aea:
	/* 0xaea: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_af0:
	/* 0xaf0: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_af6:
	/* 0xaf6: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_afb:
	/* 0xafb: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_afe:
	/* 0xafe: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b00:
	/* 0xb00: je     131e <tail_nodeport_nat_egress_ipv6+0x131e> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb00, 0x131e, x86_l_131e);
x86_l_b06:
	/* 0xb06: mov    eax,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967294ULL);
x86_l_b0b:
	/* 0xb0b: sub    eax,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_32, X86_ALU_SUB);
x86_l_b0e:
	/* 0xb0e: mov    DWORD PTR [rsp+0x8],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b12:
	/* 0xb12: movzx  ebp,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_b15:
	/* 0xb15: inc    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_b17:
	/* 0xb17: mov    ecx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_b1c:
	/* 0xb1c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b1e:
	/* 0xb1e: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_b20:
	/* 0xb20: movzx  r15d,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_b24:
	/* 0xb24: mov    DWORD PTR [rsp],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b27:
	/* 0xb27: imul   r15d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBP, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_b2b:
	/* 0xb2b: mov    ebp,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b2f:
	/* 0xb2f: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_b33:
	/* 0xb33: add    r15d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_b36:
	/* 0xb36: movbe  WORD PTR [rsp+0x30],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_b3e:
	/* 0xb3e: mov    rdi,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_b45:
	/* 0xb45: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b4a:
	/* 0xb4a: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_b4f:
	/* 0xb4f: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_b54:
	/* 0xb54: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_b57:
	/* 0xb57: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b5a:
	/* 0xb5a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b5c:
	/* 0xb5c: je     16a9 <tail_nodeport_nat_egress_ipv6+0x16a9> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb5c, 0x16a9, x86_l_16a9);
x86_l_b62:
	/* 0xb62: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_b65:
	/* 0xb65: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_b69:
	/* 0xb69: mov    r12d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b6d:
	/* 0xb6d: imul   r15d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R12, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_b71:
	/* 0xb71: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_b75:
	/* 0xb75: add    r15d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_b78:
	/* 0xb78: movbe  WORD PTR [rsp+0x30],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_b80:
	/* 0xb80: mov    rdi,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_b87:
	/* 0xb87: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b8c:
	/* 0xb8c: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_b91:
	/* 0xb91: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_b97:
	/* 0xb97: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_b9c:
	/* 0xb9c: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_b9f:
	/* 0xb9f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ba1:
	/* 0xba1: je     1329 <tail_nodeport_nat_egress_ipv6+0x1329> */
	X86_SIM_X86_JCC(X86_CC_E, 0xba1, 0x1329, x86_l_1329);
x86_l_ba7:
	/* 0xba7: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_baa:
	/* 0xbaa: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_bae:
	/* 0xbae: imul   r15d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R12, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_bb2:
	/* 0xbb2: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_bb6:
	/* 0xbb6: add    r15d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_bb9:
	/* 0xbb9: movbe  WORD PTR [rsp+0x30],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_bc1:
	/* 0xbc1: mov    rdi,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_bc8:
	/* 0xbc8: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_bcd:
	/* 0xbcd: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_bd2:
	/* 0xbd2: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_bd7:
	/* 0xbd7: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_bda:
	/* 0xbda: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_bdc:
	/* 0xbdc: je     1337 <tail_nodeport_nat_egress_ipv6+0x1337> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbdc, 0x1337, x86_l_1337);
x86_l_be2:
	/* 0xbe2: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_be5:
	/* 0xbe5: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_be9:
	/* 0xbe9: imul   r15d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R12, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_bed:
	/* 0xbed: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_bf1:
	/* 0xbf1: add    r15d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_bf4:
	/* 0xbf4: movbe  WORD PTR [rsp+0x30],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_bfc:
	/* 0xbfc: mov    rdi,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_c03:
	/* 0xc03: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c08:
	/* 0xc08: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_c0d:
	/* 0xc0d: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_c13:
	/* 0xc13: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_c18:
	/* 0xc18: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_c1b:
	/* 0xc1b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c1d:
	/* 0xc1d: je     1403 <tail_nodeport_nat_egress_ipv6+0x1403> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc1d, 0x1403, x86_l_1403);
x86_l_c23:
	/* 0xc23: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_c26:
	/* 0xc26: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_c2a:
	/* 0xc2a: imul   r15d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R12, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_c2e:
	/* 0xc2e: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_c32:
	/* 0xc32: add    r15d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_c35:
	/* 0xc35: movbe  WORD PTR [rsp+0x30],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_c3d:
	/* 0xc3d: mov    rdi,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_c44:
	/* 0xc44: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c49:
	/* 0xc49: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_c4e:
	/* 0xc4e: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_c53:
	/* 0xc53: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_c56:
	/* 0xc56: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c58:
	/* 0xc58: je     1411 <tail_nodeport_nat_egress_ipv6+0x1411> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc58, 0x1411, x86_l_1411);
x86_l_c5e:
	/* 0xc5e: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_c61:
	/* 0xc61: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_c65:
	/* 0xc65: imul   r15d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R12, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_c69:
	/* 0xc69: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_c6d:
	/* 0xc6d: add    r15d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_c70:
	/* 0xc70: movbe  WORD PTR [rsp+0x30],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_c78:
	/* 0xc78: mov    rdi,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_c7f:
	/* 0xc7f: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c84:
	/* 0xc84: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_c89:
	/* 0xc89: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_c8f:
	/* 0xc8f: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_c94:
	/* 0xc94: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_c97:
	/* 0xc97: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c99:
	/* 0xc99: je     141f <tail_nodeport_nat_egress_ipv6+0x141f> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc99, 0x141f, x86_l_141f);
x86_l_c9f:
	/* 0xc9f: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_ca2:
	/* 0xca2: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_ca6:
	/* 0xca6: imul   r15d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R12, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_caa:
	/* 0xcaa: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_cae:
	/* 0xcae: add    r15d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_cb1:
	/* 0xcb1: movbe  WORD PTR [rsp+0x30],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_cb9:
	/* 0xcb9: mov    rdi,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_cc0:
	/* 0xcc0: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_cc5:
	/* 0xcc5: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_cca:
	/* 0xcca: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_ccf:
	/* 0xccf: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_cd2:
	/* 0xcd2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_cd4:
	/* 0xcd4: je     142d <tail_nodeport_nat_egress_ipv6+0x142d> */
	X86_SIM_X86_JCC(X86_CC_E, 0xcd4, 0x142d, x86_l_142d);
x86_l_cda:
	/* 0xcda: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_cdd:
	/* 0xcdd: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_ce1:
	/* 0xce1: imul   r15d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R12, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_ce5:
	/* 0xce5: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_ce9:
	/* 0xce9: add    r15d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_cec:
	/* 0xcec: movbe  WORD PTR [rsp+0x30],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_cf4:
	/* 0xcf4: mov    rdi,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_cfb:
	/* 0xcfb: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d00:
	/* 0xd00: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_d05:
	/* 0xd05: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_d0b:
	/* 0xd0b: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_d10:
	/* 0xd10: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_d13:
	/* 0xd13: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_d15:
	/* 0xd15: je     1495 <tail_nodeport_nat_egress_ipv6+0x1495> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd15, 0x1495, x86_l_1495);
x86_l_d1b:
	/* 0xd1b: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_d1e:
	/* 0xd1e: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_d22:
	/* 0xd22: imul   r15d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R12, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_d26:
	/* 0xd26: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_d2a:
	/* 0xd2a: add    r15d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_d2d:
	/* 0xd2d: movbe  WORD PTR [rsp+0x30],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_d35:
	/* 0xd35: mov    rdi,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_d3c:
	/* 0xd3c: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d41:
	/* 0xd41: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_d46:
	/* 0xd46: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_d4b:
	/* 0xd4b: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_d4e:
	/* 0xd4e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_d50:
	/* 0xd50: je     14a3 <tail_nodeport_nat_egress_ipv6+0x14a3> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd50, 0x14a3, x86_l_14a3);
x86_l_d56:
	/* 0xd56: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_d59:
	/* 0xd59: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_d5d:
	/* 0xd5d: imul   r15d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R12, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_d61:
	/* 0xd61: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_d65:
	/* 0xd65: add    r15d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_d68:
	/* 0xd68: movbe  WORD PTR [rsp+0x30],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_d70:
	/* 0xd70: mov    rdi,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_d77:
	/* 0xd77: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d7c:
	/* 0xd7c: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_d81:
	/* 0xd81: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_d87:
	/* 0xd87: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_d8c:
	/* 0xd8c: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_d8f:
	/* 0xd8f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_d91:
	/* 0xd91: je     14b1 <tail_nodeport_nat_egress_ipv6+0x14b1> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd91, 0x14b1, x86_l_14b1);
x86_l_d97:
	/* 0xd97: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_d9a:
	/* 0xd9a: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_d9e:
	/* 0xd9e: imul   r15d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_da3:
	/* 0xda3: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_da7:
	/* 0xda7: add    r15d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_dac:
	/* 0xdac: movbe  WORD PTR [rsp+0x30],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_db4:
	/* 0xdb4: mov    rdi,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_dbb:
	/* 0xdbb: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_dc0:
	/* 0xdc0: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_dc5:
	/* 0xdc5: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_dca:
	/* 0xdca: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_dcd:
	/* 0xdcd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_dcf:
	/* 0xdcf: je     14f6 <tail_nodeport_nat_egress_ipv6+0x14f6> */
	X86_SIM_X86_JCC(X86_CC_E, 0xdcf, 0x14f6, x86_l_14f6);
x86_l_dd5:
	/* 0xdd5: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_dd8:
	/* 0xdd8: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_ddc:
	/* 0xddc: imul   r15d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_de1:
	/* 0xde1: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_de5:
	/* 0xde5: add    r15d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_dea:
	/* 0xdea: movbe  WORD PTR [rsp+0x30],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_df2:
	/* 0xdf2: mov    rdi,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_df9:
	/* 0xdf9: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_dfe:
	/* 0xdfe: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_e03:
	/* 0xe03: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_e09:
	/* 0xe09: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_e0e:
	/* 0xe0e: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_e11:
	/* 0xe11: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_e13:
	/* 0xe13: je     1511 <tail_nodeport_nat_egress_ipv6+0x1511> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe13, 0x1511, x86_l_1511);
x86_l_e19:
	/* 0xe19: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_e1c:
	/* 0xe1c: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_e20:
	/* 0xe20: imul   r15d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_e25:
	/* 0xe25: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_e29:
	/* 0xe29: add    r15d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_e2e:
	/* 0xe2e: movbe  WORD PTR [rsp+0x30],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_e36:
	/* 0xe36: mov    rdi,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_e3d:
	/* 0xe3d: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e42:
	/* 0xe42: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_e47:
	/* 0xe47: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_e4c:
	/* 0xe4c: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_e4f:
	/* 0xe4f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_e51:
	/* 0xe51: je     15bd <tail_nodeport_nat_egress_ipv6+0x15bd> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe51, 0x15bd, x86_l_15bd);
x86_l_e57:
	/* 0xe57: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_e5a:
	/* 0xe5a: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_e5e:
	/* 0xe5e: imul   r15d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_e63:
	/* 0xe63: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_e67:
	/* 0xe67: add    r15d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_e6c:
	/* 0xe6c: movbe  WORD PTR [rsp+0x30],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_e74:
	/* 0xe74: mov    rdi,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_e7b:
	/* 0xe7b: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e80:
	/* 0xe80: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_e85:
	/* 0xe85: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_e8b:
	/* 0xe8b: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_e90:
	/* 0xe90: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_e93:
	/* 0xe93: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_e95:
	/* 0xe95: je     15cb <tail_nodeport_nat_egress_ipv6+0x15cb> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe95, 0x15cb, x86_l_15cb);
x86_l_e9b:
	/* 0xe9b: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_e9e:
	/* 0xe9e: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_ea2:
	/* 0xea2: imul   r15d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_ea7:
	/* 0xea7: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_eab:
	/* 0xeab: add    r15d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_eb0:
	/* 0xeb0: movbe  WORD PTR [rsp+0x30],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_eb8:
	/* 0xeb8: mov    rdi,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_ebf:
	/* 0xebf: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ec4:
	/* 0xec4: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_ec9:
	/* 0xec9: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_ece:
	/* 0xece: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_ed1:
	/* 0xed1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ed3:
	/* 0xed3: je     15d9 <tail_nodeport_nat_egress_ipv6+0x15d9> */
	X86_SIM_X86_JCC(X86_CC_E, 0xed3, 0x15d9, x86_l_15d9);
x86_l_ed9:
	/* 0xed9: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_edc:
	/* 0xedc: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_ee0:
	/* 0xee0: imul   r15d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_ee5:
	/* 0xee5: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_ee9:
	/* 0xee9: add    r15d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_eee:
	/* 0xeee: movbe  WORD PTR [rsp+0x30],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_ef6:
	/* 0xef6: mov    rdi,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_efd:
	/* 0xefd: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f02:
	/* 0xf02: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_f07:
	/* 0xf07: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_f0d:
	/* 0xf0d: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_f12:
	/* 0xf12: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_f15:
	/* 0xf15: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_f17:
	/* 0xf17: je     1625 <tail_nodeport_nat_egress_ipv6+0x1625> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf17, 0x1625, x86_l_1625);
x86_l_f1d:
	/* 0xf1d: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_f20:
	/* 0xf20: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_f24:
	/* 0xf24: imul   r15d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_f29:
	/* 0xf29: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_f2d:
	/* 0xf2d: add    r15d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_f32:
	/* 0xf32: movbe  WORD PTR [rsp+0x30],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_f3a:
	/* 0xf3a: mov    rdi,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_f41:
	/* 0xf41: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f46:
	/* 0xf46: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_f4b:
	/* 0xf4b: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_f50:
	/* 0xf50: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_f53:
	/* 0xf53: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_f55:
	/* 0xf55: je     1630 <tail_nodeport_nat_egress_ipv6+0x1630> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf55, 0x1630, x86_l_1630);
x86_l_f5b:
	/* 0xf5b: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_f5e:
	/* 0xf5e: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_f62:
	/* 0xf62: imul   r15d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_f67:
	/* 0xf67: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_f6b:
	/* 0xf6b: add    r15d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_f70:
	/* 0xf70: movbe  WORD PTR [rsp+0x30],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_f78:
	/* 0xf78: mov    rdi,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_f7f:
	/* 0xf7f: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f84:
	/* 0xf84: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_f89:
	/* 0xf89: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_f8f:
	/* 0xf8f: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_f94:
	/* 0xf94: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_f97:
	/* 0xf97: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_f99:
	/* 0xf99: je     1638 <tail_nodeport_nat_egress_ipv6+0x1638> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf99, 0x1638, x86_l_1638);
x86_l_f9f:
	/* 0xf9f: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_fa2:
	/* 0xfa2: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_fa6:
	/* 0xfa6: imul   r15d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_fab:
	/* 0xfab: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_faf:
	/* 0xfaf: add    r15d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_fb4:
	/* 0xfb4: movbe  WORD PTR [rsp+0x30],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_fbc:
	/* 0xfbc: mov    rdi,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_fc3:
	/* 0xfc3: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_fc8:
	/* 0xfc8: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_fcd:
	/* 0xfcd: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_fd2:
	/* 0xfd2: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_fd5:
	/* 0xfd5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_fd7:
	/* 0xfd7: je     1640 <tail_nodeport_nat_egress_ipv6+0x1640> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfd7, 0x1640, x86_l_1640);
x86_l_fdd:
	/* 0xfdd: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_fe0:
	/* 0xfe0: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_fe4:
	/* 0xfe4: imul   r15d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_fe9:
	/* 0xfe9: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_fed:
	/* 0xfed: add    r15d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_ff2:
	/* 0xff2: movbe  WORD PTR [rsp+0x30],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_ffa:
	/* 0xffa: mov    rdi,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_1001:
	/* 0x1001: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1006:
	/* 0x1006: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_100b:
	/* 0x100b: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_1011:
	/* 0x1011: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1016:
	/* 0x1016: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_1019:
	/* 0x1019: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_101b:
	/* 0x101b: je     1648 <tail_nodeport_nat_egress_ipv6+0x1648> */
	X86_SIM_X86_JCC(X86_CC_E, 0x101b, 0x1648, x86_l_1648);
x86_l_1021:
	/* 0x1021: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1024:
	/* 0x1024: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1028:
	/* 0x1028: imul   r15d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_102d:
	/* 0x102d: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1031:
	/* 0x1031: add    r15d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1036:
	/* 0x1036: movbe  WORD PTR [rsp+0x30],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_103e:
	/* 0x103e: mov    rdi,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_1045:
	/* 0x1045: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_104a:
	/* 0x104a: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_104f:
	/* 0x104f: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1054:
	/* 0x1054: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_1057:
	/* 0x1057: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1059:
	/* 0x1059: je     1650 <tail_nodeport_nat_egress_ipv6+0x1650> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1059, 0x1650, x86_l_1650);
x86_l_105f:
	/* 0x105f: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1062:
	/* 0x1062: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1066:
	/* 0x1066: imul   r15d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_106b:
	/* 0x106b: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_106f:
	/* 0x106f: add    r15d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1074:
	/* 0x1074: movbe  WORD PTR [rsp+0x30],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_107c:
	/* 0x107c: mov    rdi,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_1083:
	/* 0x1083: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1088:
	/* 0x1088: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_108d:
	/* 0x108d: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_1093:
	/* 0x1093: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1098:
	/* 0x1098: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_109b:
	/* 0x109b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_109d:
	/* 0x109d: je     1658 <tail_nodeport_nat_egress_ipv6+0x1658> */
	X86_SIM_X86_JCC(X86_CC_E, 0x109d, 0x1658, x86_l_1658);
x86_l_10a3:
	/* 0x10a3: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_10a6:
	/* 0x10a6: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_10aa:
	/* 0x10aa: imul   r15d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_10af:
	/* 0x10af: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_10b3:
	/* 0x10b3: add    r15d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_10b8:
	/* 0x10b8: movbe  WORD PTR [rsp+0x30],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_10c0:
	/* 0x10c0: mov    rdi,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_10c7:
	/* 0x10c7: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10cc:
	/* 0x10cc: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_10d1:
	/* 0x10d1: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_10d6:
	/* 0x10d6: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_10d9:
	/* 0x10d9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_10db:
	/* 0x10db: je     1660 <tail_nodeport_nat_egress_ipv6+0x1660> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10db, 0x1660, x86_l_1660);
x86_l_10e1:
	/* 0x10e1: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_10e4:
	/* 0x10e4: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_10e8:
	/* 0x10e8: imul   r15d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_10ed:
	/* 0x10ed: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_10f1:
	/* 0x10f1: add    r15d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_10f6:
	/* 0x10f6: movbe  WORD PTR [rsp+0x30],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_10fe:
	/* 0x10fe: mov    rdi,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_1105:
	/* 0x1105: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_110a:
	/* 0x110a: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_110f:
	/* 0x110f: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_1115:
	/* 0x1115: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_111a:
	/* 0x111a: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_111d:
	/* 0x111d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_111f:
	/* 0x111f: je     1668 <tail_nodeport_nat_egress_ipv6+0x1668> */
	X86_SIM_X86_JCC(X86_CC_E, 0x111f, 0x1668, x86_l_1668);
x86_l_1125:
	/* 0x1125: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1128:
	/* 0x1128: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_112c:
	/* 0x112c: imul   r15d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_1131:
	/* 0x1131: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1135:
	/* 0x1135: add    r15d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_113a:
	/* 0x113a: movbe  WORD PTR [rsp+0x30],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_1142:
	/* 0x1142: mov    rdi,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_1149:
	/* 0x1149: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_114e:
	/* 0x114e: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1153:
	/* 0x1153: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1158:
	/* 0x1158: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_115b:
	/* 0x115b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_115d:
	/* 0x115d: je     1670 <tail_nodeport_nat_egress_ipv6+0x1670> */
	X86_SIM_X86_JCC(X86_CC_E, 0x115d, 0x1670, x86_l_1670);
x86_l_1163:
	/* 0x1163: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1166:
	/* 0x1166: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_116a:
	/* 0x116a: imul   r15d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_116f:
	/* 0x116f: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1173:
	/* 0x1173: add    r15d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1178:
	/* 0x1178: movbe  WORD PTR [rsp+0x30],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_1180:
	/* 0x1180: mov    rdi,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_1187:
	/* 0x1187: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_118c:
	/* 0x118c: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1191:
	/* 0x1191: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_1197:
	/* 0x1197: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_119c:
	/* 0x119c: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_119f:
	/* 0x119f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_11a1:
	/* 0x11a1: je     1678 <tail_nodeport_nat_egress_ipv6+0x1678> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11a1, 0x1678, x86_l_1678);
x86_l_11a7:
	/* 0x11a7: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_11aa:
	/* 0x11aa: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_11ae:
	/* 0x11ae: imul   r15d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_11b3:
	/* 0x11b3: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_11b7:
	/* 0x11b7: add    r15d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_11bc:
	/* 0x11bc: movbe  WORD PTR [rsp+0x30],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_11c4:
	/* 0x11c4: mov    rdi,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_11cb:
	/* 0x11cb: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11d0:
	/* 0x11d0: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_11d5:
	/* 0x11d5: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_11da:
	/* 0x11da: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_11dd:
	/* 0x11dd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_11df:
	/* 0x11df: je     1680 <tail_nodeport_nat_egress_ipv6+0x1680> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11df, 0x1680, x86_l_1680);
x86_l_11e5:
	/* 0x11e5: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_11e8:
	/* 0x11e8: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_11ec:
	/* 0x11ec: imul   r15d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_11f1:
	/* 0x11f1: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_11f5:
	/* 0x11f5: add    r15d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_11fa:
	/* 0x11fa: movbe  WORD PTR [rsp+0x30],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_1202:
	/* 0x1202: mov    rdi,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_1209:
	/* 0x1209: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_120e:
	/* 0x120e: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1213:
	/* 0x1213: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_1219:
	/* 0x1219: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_121e:
	/* 0x121e: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_1221:
	/* 0x1221: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1223:
	/* 0x1223: je     1688 <tail_nodeport_nat_egress_ipv6+0x1688> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1223, 0x1688, x86_l_1688);
x86_l_1229:
	/* 0x1229: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_122c:
	/* 0x122c: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1230:
	/* 0x1230: imul   r15d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_1235:
	/* 0x1235: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1239:
	/* 0x1239: add    r15d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_123e:
	/* 0x123e: movbe  WORD PTR [rsp+0x30],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_1246:
	/* 0x1246: mov    rdi,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_124d:
	/* 0x124d: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1252:
	/* 0x1252: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1257:
	/* 0x1257: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_125c:
	/* 0x125c: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_125f:
	/* 0x125f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1261:
	/* 0x1261: je     1690 <tail_nodeport_nat_egress_ipv6+0x1690> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1261, 0x1690, x86_l_1690);
x86_l_1267:
	/* 0x1267: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_126a:
	/* 0x126a: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_126e:
	/* 0x126e: imul   r15d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_1273:
	/* 0x1273: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1277:
	/* 0x1277: add    r15d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_127c:
	/* 0x127c: movbe  WORD PTR [rsp+0x30],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_1284:
	/* 0x1284: mov    rdi,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_128b:
	/* 0x128b: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1290:
	/* 0x1290: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1295:
	/* 0x1295: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_129b:
	/* 0x129b: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_12a0:
	/* 0x12a0: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_12a3:
	/* 0x12a3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_12a5:
	/* 0x12a5: je     1698 <tail_nodeport_nat_egress_ipv6+0x1698> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12a5, 0x1698, x86_l_1698);
x86_l_12ab:
	/* 0x12ab: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_12ae:
	/* 0x12ae: movzx  eax,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_12b2:
	/* 0x12b2: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12b5:
	/* 0x12b5: imul   ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_12b8:
	/* 0x12b8: shr    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_12bb:
	/* 0x12bb: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12bf:
	/* 0x12bf: add    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_12c1:
	/* 0x12c1: movbe  WORD PTR [rsp+0x30],ax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_12c8:
	/* 0x12c8: mov    rdi,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_12cf:
	/* 0x12cf: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12d4:
	/* 0x12d4: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_12d9:
	/* 0x12d9: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_12de:
	/* 0x12de: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_12e1:
	/* 0x12e1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_12e3:
	/* 0x12e3: je     16a0 <tail_nodeport_nat_egress_ipv6+0x16a0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12e3, 0x16a0, x86_l_16a0);
x86_l_12e9:
	/* 0x12e9: mov    DWORD PTR [rsp+0xb4],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 773094113312ULL);
x86_l_12f4:
	/* 0x12f4: mov    rdi,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_alloc_retries)));
x86_l_12fb:
	/* 0x12fb: lea    rsi,[rsp+0xb4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 180ULL);
x86_l_1303:
	/* 0x1303: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1308:
	/* 0x1308: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_130a:
	/* 0x130a: mov    r12d,0xffffff59 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967129ULL);
x86_l_1310:
	/* 0x1310: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1313:
	/* 0x1313: je     1317 <tail_nodeport_nat_egress_ipv6+0x1317> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1313, 0x1317, x86_l_1317);
x86_l_1315:
	/* 0x1315: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1317:
	/* 0x1317: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1319:
	/* 0x1319: jmp    1726 <tail_nodeport_nat_egress_ipv6+0x1726> */
	X86_SIM_X86_JMP(0x1319, 0x1726, x86_l_1726);
x86_l_131e:
	/* 0x131e: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1321:
	/* 0x1321: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1324:
	/* 0x1324: jmp    16a9 <tail_nodeport_nat_egress_ipv6+0x16a9> */
	X86_SIM_X86_JMP(0x1324, 0x16a9, x86_l_16a9);
x86_l_1329:
	/* 0x1329: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_132f:
	/* 0x132f: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1332:
	/* 0x1332: jmp    16a9 <tail_nodeport_nat_egress_ipv6+0x16a9> */
	X86_SIM_X86_JMP(0x1332, 0x16a9, x86_l_16a9);
x86_l_1337:
	/* 0x1337: mov    r12d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 3ULL);
x86_l_133d:
	/* 0x133d: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1340:
	/* 0x1340: jmp    16a9 <tail_nodeport_nat_egress_ipv6+0x16a9> */
	X86_SIM_X86_JMP(0x1340, 0x16a9, x86_l_16a9);
x86_l_1345:
	/* 0x1345: mov    rdi,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_134c:
	/* 0x134c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1351:
	/* 0x1351: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_1354:
	/* 0x1354: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1356:
	/* 0x1356: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1359:
	/* 0x1359: jne    147c <tail_nodeport_nat_egress_ipv6+0x147c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1359, 0x147c, x86_l_147c);
x86_l_135f:
	/* 0x135f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1364:
	/* 0x1364: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1366:
	/* 0x1366: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1368:
	/* 0x1368: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_136a:
	/* 0x136a: imul   rax,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_136f:
	/* 0x136f: cmp    rax,QWORD PTR [r12] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_1373:
	/* 0x1373: jbe    1379 <tail_nodeport_nat_egress_ipv6+0x1379> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x1373, 0x1379, x86_l_1379);
x86_l_1375:
	/* 0x1375: mov    rax,QWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1379:
	/* 0x1379: mov    rcx,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__aux_snat_v6_nhm_nat_entry)));
x86_l_1380:
	/* 0x1380: mov    QWORD PTR [rcx+rax*1+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 206158430208ULL);
x86_l_1389:
	/* 0x1389: mov    QWORD PTR [rcx+rax*1+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 171798691840ULL);
x86_l_1392:
	/* 0x1392: mov    QWORD PTR [rcx+rax*1+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 137438953472ULL);
x86_l_139b:
	/* 0x139b: mov    QWORD PTR [rcx+rax*1+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 103079215104ULL);
x86_l_13a4:
	/* 0x13a4: mov    QWORD PTR [rcx+rax*1+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 68719476736ULL);
x86_l_13ad:
	/* 0x13ad: mov    QWORD PTR [rcx+rax*1+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 34359738368ULL);
x86_l_13b6:
	/* 0x13b6: mov    QWORD PTR [rcx+rax*1],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_13be:
	/* 0x13be: lea    rsi,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_13c6:
	/* 0x13c6: mov    rdx,QWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13c9:
	/* 0x13c9: mov    rsi,QWORD PTR [rsi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13cd:
	/* 0x13cd: mov    QWORD PTR [rcx+rax*1+0x20],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 32ULL);
x86_l_13d2:
	/* 0x13d2: mov    QWORD PTR [rcx+rax*1+0x28],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 40ULL);
x86_l_13d7:
	/* 0x13d7: movzx  edx,WORD PTR [rsp+0xaa] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 170ULL);
x86_l_13df:
	/* 0x13df: lea    r12,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_13e3:
	/* 0x13e3: mov    WORD PTR [rcx+rax*1+0x30],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 0), 48ULL);
x86_l_13e8:
	/* 0x13e8: mov    rax,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_13ef:
	/* 0x13ef: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13f2:
	/* 0x13f2: je     143b <tail_nodeport_nat_egress_ipv6+0x143b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13f2, 0x143b, x86_l_143b);
x86_l_13f4:
	/* 0x13f4: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_13f9:
	/* 0x13f9: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13fb:
	/* 0x13fb: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_13fd:
	/* 0x13fd: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_1401:
	/* 0x1401: jmp    145e <tail_nodeport_nat_egress_ipv6+0x145e> */
	X86_SIM_X86_JMP(0x1401, 0x145e, x86_l_145e);
x86_l_1403:
	/* 0x1403: mov    r12d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4ULL);
x86_l_1409:
	/* 0x1409: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_140c:
	/* 0x140c: jmp    16a9 <tail_nodeport_nat_egress_ipv6+0x16a9> */
	X86_SIM_X86_JMP(0x140c, 0x16a9, x86_l_16a9);
x86_l_1411:
	/* 0x1411: mov    r12d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 5ULL);
x86_l_1417:
	/* 0x1417: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_141a:
	/* 0x141a: jmp    16a9 <tail_nodeport_nat_egress_ipv6+0x16a9> */
	X86_SIM_X86_JMP(0x141a, 0x16a9, x86_l_16a9);
x86_l_141f:
	/* 0x141f: mov    r12d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 6ULL);
x86_l_1425:
	/* 0x1425: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1428:
	/* 0x1428: jmp    16a9 <tail_nodeport_nat_egress_ipv6+0x16a9> */
	X86_SIM_X86_JMP(0x1428, 0x16a9, x86_l_16a9);
x86_l_142d:
	/* 0x142d: mov    r12d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 7ULL);
x86_l_1433:
	/* 0x1433: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1436:
	/* 0x1436: jmp    16a9 <tail_nodeport_nat_egress_ipv6+0x16a9> */
	X86_SIM_X86_JMP(0x1436, 0x16a9, x86_l_16a9);
x86_l_143b:
	/* 0x143b: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1440:
	/* 0x1440: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1442:
	/* 0x1442: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1444:
	/* 0x1444: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1448:
	/* 0x1448: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_1452:
	/* 0x1452: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1455:
	/* 0x1455: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_145a:
	/* 0x145a: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_145e:
	/* 0x145e: mov    QWORD PTR [r12],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1462:
	/* 0x1462: mov    rdi,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_1469:
	/* 0x1469: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_146e:
	/* 0x146e: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_1471:
	/* 0x1471: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1474:
	/* 0x1474: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1476:
	/* 0x1476: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1478:
	/* 0x1478: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_147a:
	/* 0x147a: js     1488 <tail_nodeport_nat_egress_ipv6+0x1488> */
	X86_SIM_X86_JCC(X86_CC_S, 0x147a, 0x1488, x86_l_1488);
x86_l_147c:
	/* 0x147c: mov    rax,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1481:
	/* 0x1481: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1483:
	/* 0x1483: jmp    1765 <tail_nodeport_nat_egress_ipv6+0x1765> */
	X86_SIM_X86_JMP(0x1483, 0x1765, x86_l_1765);
x86_l_1488:
	/* 0x1488: mov    ebp,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_148a:
	/* 0x148a: mov    r12d,0xffffff59 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967129ULL);
x86_l_1490:
	/* 0x1490: jmp    f6 <tail_nodeport_nat_egress_ipv6+0xf6> */
	X86_SIM_X86_JMP(0x1490, 0xf6, x86_l_f6);
x86_l_1495:
	/* 0x1495: mov    r12d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 8ULL);
x86_l_149b:
	/* 0x149b: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_149e:
	/* 0x149e: jmp    16a9 <tail_nodeport_nat_egress_ipv6+0x16a9> */
	X86_SIM_X86_JMP(0x149e, 0x16a9, x86_l_16a9);
x86_l_14a3:
	/* 0x14a3: mov    r12d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 9ULL);
x86_l_14a9:
	/* 0x14a9: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14ac:
	/* 0x14ac: jmp    16a9 <tail_nodeport_nat_egress_ipv6+0x16a9> */
	X86_SIM_X86_JMP(0x14ac, 0x16a9, x86_l_16a9);
x86_l_14b1:
	/* 0x14b1: mov    r12d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 10ULL);
x86_l_14b7:
	/* 0x14b7: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14ba:
	/* 0x14ba: jmp    16a9 <tail_nodeport_nat_egress_ipv6+0x16a9> */
	X86_SIM_X86_JMP(0x14ba, 0x16a9, x86_l_16a9);
x86_l_14bf:
	/* 0x14bf: mov    QWORD PTR [rsp+0x38],r9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_14c4:
	/* 0x14c4: mov    QWORD PTR [rsp],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14c8:
	/* 0x14c8: mov    r12,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R8, X86_WIDTH_64);
x86_l_14cb:
	/* 0x14cb: mov    rdi,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv6_frag_datagrams)));
x86_l_14d2:
	/* 0x14d2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14d7:
	/* 0x14d7: mov    rbp,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RSI, X86_WIDTH_64);
x86_l_14da:
	/* 0x14da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14dc:
	/* 0x14dc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14df:
	/* 0x14df: je     15aa <tail_nodeport_nat_egress_ipv6+0x15aa> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14df, 0x15aa, x86_l_15aa);
x86_l_14e5:
	/* 0x14e5: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14e7:
	/* 0x14e7: mov    DWORD PTR [rsp+0xa8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_14ee:
	/* 0x14ee: mov    r8,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R12, X86_WIDTH_64);
x86_l_14f1:
	/* 0x14f1: jmp    1614 <tail_nodeport_nat_egress_ipv6+0x1614> */
	X86_SIM_X86_JMP(0x14f1, 0x1614, x86_l_1614);
x86_l_14f6:
	/* 0x14f6: mov    r12d,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 11ULL);
x86_l_14fc:
	/* 0x14fc: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14ff:
	/* 0x14ff: jmp    16a9 <tail_nodeport_nat_egress_ipv6+0x16a9> */
	X86_SIM_X86_JMP(0x14ff, 0x16a9, x86_l_16a9);
x86_l_1504:
	/* 0x1504: mov    r12d,0xffffff63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967139ULL);
x86_l_150a:
	/* 0x150a: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_150c:
	/* 0x150c: jmp    f6 <tail_nodeport_nat_egress_ipv6+0xf6> */
	X86_SIM_X86_JMP(0x150c, 0xf6, x86_l_f6);
x86_l_1511:
	/* 0x1511: mov    r12d,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 12ULL);
x86_l_1517:
	/* 0x1517: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_151a:
	/* 0x151a: jmp    16a9 <tail_nodeport_nat_egress_ipv6+0x16a9> */
	X86_SIM_X86_JMP(0x151a, 0x16a9, x86_l_16a9);
x86_l_151f:
	/* 0x151f: lea    rdx,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1527:
	/* 0x1527: mov    QWORD PTR [rsp],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_152b:
	/* 0x152b: mov    rdi,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv6_frag_datagrams)));
x86_l_1532:
	/* 0x1532: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1537:
	/* 0x1537: mov    rbp,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RSI, X86_WIDTH_64);
x86_l_153a:
	/* 0x153a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_153c:
	/* 0x153c: mov    QWORD PTR [rsp+0x8],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1541:
	/* 0x1541: mov    QWORD PTR [rsp+0x38],r9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1546:
	/* 0x1546: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1548:
	/* 0x1548: mov    r9,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_154d:
	/* 0x154d: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_1550:
	/* 0x1550: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1554:
	/* 0x1554: mov    r8,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1559:
	/* 0x1559: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_155b:
	/* 0x155b: je     77d <tail_nodeport_nat_egress_ipv6+0x77d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x155b, 0x77d, x86_l_77d);
x86_l_1561:
	/* 0x1561: mov    r12,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1565:
	/* 0x1565: sub    r12,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 0ULL);
x86_l_1568:
	/* 0x1568: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1571:
	/* 0x1571: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_157a:
	/* 0x157a: movabs rax,0x7201a9020a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 489654125066ULL);
x86_l_1584:
	/* 0x1584: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1589:
	/* 0x1589: mov    rdi,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1590:
	/* 0x1590: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1595:
	/* 0x1595: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_159a:
	/* 0x159a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_159c:
	/* 0x159c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_159f:
	/* 0x159f: je     15e7 <tail_nodeport_nat_egress_ipv6+0x15e7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x159f, 0x15e7, x86_l_15e7);
x86_l_15a1:
	/* 0x15a1: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_15a4:
	/* 0x15a4: add    QWORD PTR [rax+0x8],r12 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_15a8:
	/* 0x15a8: jmp    160f <tail_nodeport_nat_egress_ipv6+0x160f> */
	X86_SIM_X86_JMP(0x15a8, 0x160f, x86_l_160f);
x86_l_15aa:
	/* 0x15aa: mov    r12d,0xffffff51 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967121ULL);
x86_l_15b0:
	/* 0x15b0: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_15b3:
	/* 0x15b3: mov    r9,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_15b8:
	/* 0x15b8: jmp    714 <tail_nodeport_nat_egress_ipv6+0x714> */
	X86_SIM_X86_JMP(0x15b8, 0x714, x86_l_714);
x86_l_15bd:
	/* 0x15bd: mov    r12d,0xd */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 13ULL);
x86_l_15c3:
	/* 0x15c3: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15c6:
	/* 0x15c6: jmp    16a9 <tail_nodeport_nat_egress_ipv6+0x16a9> */
	X86_SIM_X86_JMP(0x15c6, 0x16a9, x86_l_16a9);
x86_l_15cb:
	/* 0x15cb: mov    r12d,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 14ULL);
x86_l_15d1:
	/* 0x15d1: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15d4:
	/* 0x15d4: jmp    16a9 <tail_nodeport_nat_egress_ipv6+0x16a9> */
	X86_SIM_X86_JMP(0x15d4, 0x16a9, x86_l_16a9);
x86_l_15d9:
	/* 0x15d9: mov    r12d,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 15ULL);
x86_l_15df:
	/* 0x15df: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15e2:
	/* 0x15e2: jmp    16a9 <tail_nodeport_nat_egress_ipv6+0x16a9> */
	X86_SIM_X86_JMP(0x15e2, 0x16a9, x86_l_16a9);
x86_l_15e7:
	/* 0x15e7: mov    QWORD PTR [rsp+0x40],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906945ULL);
x86_l_15f0:
	/* 0x15f0: mov    QWORD PTR [rsp+0x48],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_15f5:
	/* 0x15f5: mov    rdi,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_15fc:
	/* 0x15fc: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1601:
	/* 0x1601: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1606:
	/* 0x1606: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_160b:
	/* 0x160b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_160d:
	/* 0x160d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_160f:
	/* 0x160f: mov    r8,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1614:
	/* 0x1614: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1618:
	/* 0x1618: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_161b:
	/* 0x161b: mov    r9,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1620:
	/* 0x1620: jmp    77d <tail_nodeport_nat_egress_ipv6+0x77d> */
	X86_SIM_X86_JMP(0x1620, 0x77d, x86_l_77d);
x86_l_1625:
	/* 0x1625: mov    r12d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 16ULL);
x86_l_162b:
	/* 0x162b: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_162e:
	/* 0x162e: jmp    16a9 <tail_nodeport_nat_egress_ipv6+0x16a9> */
	X86_SIM_X86_JMP(0x162e, 0x16a9, x86_l_16a9);
x86_l_1630:
	/* 0x1630: mov    r12d,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 17ULL);
x86_l_1636:
	/* 0x1636: jmp    16a6 <tail_nodeport_nat_egress_ipv6+0x16a6> */
	X86_SIM_X86_JMP(0x1636, 0x16a6, x86_l_16a6);
x86_l_1638:
	/* 0x1638: mov    r12d,0x12 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 18ULL);
x86_l_163e:
	/* 0x163e: jmp    16a6 <tail_nodeport_nat_egress_ipv6+0x16a6> */
	X86_SIM_X86_JMP(0x163e, 0x16a6, x86_l_16a6);
x86_l_1640:
	/* 0x1640: mov    r12d,0x13 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 19ULL);
x86_l_1646:
	/* 0x1646: jmp    16a6 <tail_nodeport_nat_egress_ipv6+0x16a6> */
	X86_SIM_X86_JMP(0x1646, 0x16a6, x86_l_16a6);
x86_l_1648:
	/* 0x1648: mov    r12d,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 20ULL);
x86_l_164e:
	/* 0x164e: jmp    16a6 <tail_nodeport_nat_egress_ipv6+0x16a6> */
	X86_SIM_X86_JMP(0x164e, 0x16a6, x86_l_16a6);
x86_l_1650:
	/* 0x1650: mov    r12d,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 21ULL);
x86_l_1656:
	/* 0x1656: jmp    16a6 <tail_nodeport_nat_egress_ipv6+0x16a6> */
	X86_SIM_X86_JMP(0x1656, 0x16a6, x86_l_16a6);
x86_l_1658:
	/* 0x1658: mov    r12d,0x16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 22ULL);
x86_l_165e:
	/* 0x165e: jmp    16a6 <tail_nodeport_nat_egress_ipv6+0x16a6> */
	X86_SIM_X86_JMP(0x165e, 0x16a6, x86_l_16a6);
x86_l_1660:
	/* 0x1660: mov    r12d,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 23ULL);
x86_l_1666:
	/* 0x1666: jmp    16a6 <tail_nodeport_nat_egress_ipv6+0x16a6> */
	X86_SIM_X86_JMP(0x1666, 0x16a6, x86_l_16a6);
x86_l_1668:
	/* 0x1668: mov    r12d,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 24ULL);
x86_l_166e:
	/* 0x166e: jmp    16a6 <tail_nodeport_nat_egress_ipv6+0x16a6> */
	X86_SIM_X86_JMP(0x166e, 0x16a6, x86_l_16a6);
x86_l_1670:
	/* 0x1670: mov    r12d,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 25ULL);
x86_l_1676:
	/* 0x1676: jmp    16a6 <tail_nodeport_nat_egress_ipv6+0x16a6> */
	X86_SIM_X86_JMP(0x1676, 0x16a6, x86_l_16a6);
x86_l_1678:
	/* 0x1678: mov    r12d,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 26ULL);
x86_l_167e:
	/* 0x167e: jmp    16a6 <tail_nodeport_nat_egress_ipv6+0x16a6> */
	X86_SIM_X86_JMP(0x167e, 0x16a6, x86_l_16a6);
x86_l_1680:
	/* 0x1680: mov    r12d,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 27ULL);
x86_l_1686:
	/* 0x1686: jmp    16a6 <tail_nodeport_nat_egress_ipv6+0x16a6> */
	X86_SIM_X86_JMP(0x1686, 0x16a6, x86_l_16a6);
x86_l_1688:
	/* 0x1688: mov    r12d,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 28ULL);
x86_l_168e:
	/* 0x168e: jmp    16a6 <tail_nodeport_nat_egress_ipv6+0x16a6> */
	X86_SIM_X86_JMP(0x168e, 0x16a6, x86_l_16a6);
x86_l_1690:
	/* 0x1690: mov    r12d,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 29ULL);
x86_l_1696:
	/* 0x1696: jmp    16a6 <tail_nodeport_nat_egress_ipv6+0x16a6> */
	X86_SIM_X86_JMP(0x1696, 0x16a6, x86_l_16a6);
x86_l_1698:
	/* 0x1698: mov    r12d,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 30ULL);
x86_l_169e:
	/* 0x169e: jmp    16a6 <tail_nodeport_nat_egress_ipv6+0x16a6> */
	X86_SIM_X86_JMP(0x169e, 0x16a6, x86_l_16a6);
x86_l_16a0:
	/* 0x16a0: mov    r12d,0x1f */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 31ULL);
x86_l_16a6:
	/* 0x16a6: mov    r14b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_8, 1ULL);
x86_l_16a9:
	/* 0x16a9: mov    DWORD PTR [rsp+0xb4],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 180ULL);
x86_l_16b1:
	/* 0x16b1: mov    rdi,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_alloc_retries)));
x86_l_16b8:
	/* 0x16b8: lea    rsi,[rsp+0xb4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 180ULL);
x86_l_16c0:
	/* 0x16c0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_16c5:
	/* 0x16c5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16c7:
	/* 0x16c7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_16ca:
	/* 0x16ca: je     16ce <tail_nodeport_nat_egress_ipv6+0x16ce> */
	X86_SIM_X86_JCC(X86_CC_E, 0x16ca, 0x16ce, x86_l_16ce);
x86_l_16cc:
	/* 0x16cc: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_16ce:
	/* 0x16ce: movzx  eax,WORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_16d3:
	/* 0x16d3: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_16d8:
	/* 0x16d8: mov    WORD PTR [rdx+0x30],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_16dc:
	/* 0x16dc: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_16e1:
	/* 0x16e1: mov    QWORD PTR [rdx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16e4:
	/* 0x16e4: mov    rdi,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_16eb:
	/* 0x16eb: lea    rsi,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_16f3:
	/* 0x16f3: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16f5:
	/* 0x16f5: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_16fa:
	/* 0x16fa: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16fc:
	/* 0x16fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16fe:
	/* 0x16fe: mov    r12d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_32);
x86_l_1701:
	/* 0x1701: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1703:
	/* 0x1703: jns    1721 <tail_nodeport_nat_egress_ipv6+0x1721> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1703, 0x1721, x86_l_1721);
x86_l_1705:
	/* 0x1705: mov    rdi,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_170c:
	/* 0x170c: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1711:
	/* 0x1711: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1716:
	/* 0x1716: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1718:
	/* 0x1718: mov    ebp,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_32);
x86_l_171b:
	/* 0x171b: mov    r12d,0xffffff59 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967129ULL);
x86_l_1721:
	/* 0x1721: test   r14b,r14b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_8);
x86_l_1724:
	/* 0x1724: je     175c <tail_nodeport_nat_egress_ipv6+0x175c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1724, 0x175c, x86_l_175c);
x86_l_1726:
	/* 0x1726: movabs rax,0x100000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 4294967296ULL);
x86_l_1730:
	/* 0x1730: mov    QWORD PTR [rsp+0x108],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_1738:
	/* 0x1738: mov    rsi,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_signals)));
x86_l_173f:
	/* 0x173f: lea    rcx,[rsp+0x108] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 264ULL);
x86_l_1747:
	/* 0x1747: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_174c:
	/* 0x174c: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_1751:
	/* 0x1751: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1754:
	/* 0x1754: mov    r8d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 8ULL);
x86_l_175a:
	/* 0x175a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_175c:
	/* 0x175c: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_175f:
	/* 0x175f: js     f6 <tail_nodeport_nat_egress_ipv6+0xf6> */
	X86_SIM_X86_JCC(X86_CC_S, 0x175f, 0xf6, x86_l_f6);
x86_l_1765:
	/* 0x1765: mov    r12,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_176a:
	/* 0x176a: movzx  edx,WORD PTR [r12+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_1770:
	/* 0x1770: movzx  r14d,BYTE PTR [rsp+0xac] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 172ULL);
x86_l_1779:
	/* 0x1779: movzx  ecx,WORD PTR [rsp+0xaa] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 170ULL);
x86_l_1781:
	/* 0x1781: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1789:
	/* 0x1789: cmp    rax,QWORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 32ULL);
x86_l_178e:
	/* 0x178e: mov    DWORD PTR [rsp+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1792:
	/* 0x1792: mov    WORD PTR [rsp],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1796:
	/* 0x1796: jne    17b6 <tail_nodeport_nat_egress_ipv6+0x17b6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1796, 0x17b6, x86_l_17b6);
x86_l_1798:
	/* 0x1798: cmp    cx,dx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_16);
x86_l_179b:
	/* 0x179b: sete   r15b */
	X86_SIM_L_EXEC_SETCC(X86_R15, X86_CC_E);
x86_l_179f:
	/* 0x179f: jne    17bd <tail_nodeport_nat_egress_ipv6+0x17bd> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x179f, 0x17bd, x86_l_17bd);
x86_l_17a1:
	/* 0x17a1: mov    rax,QWORD PTR [r12+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_17a6:
	/* 0x17a6: cmp    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_17ae:
	/* 0x17ae: je     18bf <tail_nodeport_nat_egress_ipv6+0x18bf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x17ae, 0x18bf, x86_l_18bf);
x86_l_17b4:
	/* 0x17b4: jmp    17bd <tail_nodeport_nat_egress_ipv6+0x17bd> */
	X86_SIM_X86_JMP(0x17b4, 0x17bd, x86_l_17bd);
x86_l_17b6:
	/* 0x17b6: cmp    cx,dx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_16);
x86_l_17b9:
	/* 0x17b9: sete   r15b */
	X86_SIM_L_EXEC_SETCC(X86_R15, X86_CC_E);
x86_l_17bd:
	/* 0x17bd: lea    rdx,[r12+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_17c2:
	/* 0x17c2: mov    eax,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_17c7:
	/* 0x17c7: lea    rdi,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_17cf:
	/* 0x17cf: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_17d4:
	/* 0x17d4: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_17d9:
	/* 0x17d9: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17dc:
	/* 0x17dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17de:
	/* 0x17de: mov    rcx,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17e1:
	/* 0x17e1: mov    rsi,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17e5:
	/* 0x17e5: lea    rdx,[rcx+0x26] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_17e9:
	/* 0x17e9: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_17ec:
	/* 0x17ec: mov    r12d,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967155ULL);
x86_l_17f2:
	/* 0x17f2: cmp    rdx,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_17f5:
	/* 0x17f5: ja     1b3c <tail_nodeport_nat_egress_ipv6+0x1b3c> */
	X86_SIM_X86_JCC(X86_CC_A, 0x17f5, 0x1b3c, x86_l_1b3c);
x86_l_17fb:
	/* 0x17fb: mov    rdx,QWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_17ff:
	/* 0x17ff: mov    QWORD PTR [rcx+0x1e],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_1803:
	/* 0x1803: mov    rdx,QWORD PTR [rdi+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1807:
	/* 0x1807: mov    QWORD PTR [rcx+0x16],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_180b:
	/* 0x180b: movabs rdx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 2199023255552ULL);
x86_l_1815:
	/* 0x1815: test   r13,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_RDX, X86_WIDTH_64);
x86_l_1818:
	/* 0x1818: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_181b:
	/* 0x181b: jne    18bf <tail_nodeport_nat_egress_ipv6+0x18bf> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x181b, 0x18bf, x86_l_18bf);
x86_l_1821:
	/* 0x1821: mov    dl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_8, 1ULL);
x86_l_1823:
	/* 0x1823: cmp    r14d,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 58ULL);
x86_l_1827:
	/* 0x1827: je     1845 <tail_nodeport_nat_egress_ipv6+0x1845> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1827, 0x1845, x86_l_1845);
x86_l_1829:
	/* 0x1829: cmp    r14d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 17ULL);
x86_l_182d:
	/* 0x182d: je     183c <tail_nodeport_nat_egress_ipv6+0x183c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x182d, 0x183c, x86_l_183c);
x86_l_182f:
	/* 0x182f: cmp    r14d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 6ULL);
x86_l_1833:
	/* 0x1833: jne    184f <tail_nodeport_nat_egress_ipv6+0x184f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1833, 0x184f, x86_l_184f);
x86_l_1835:
	/* 0x1835: mov    edi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 16ULL);
x86_l_183a:
	/* 0x183a: jmp    184a <tail_nodeport_nat_egress_ipv6+0x184a> */
	X86_SIM_X86_JMP(0x183a, 0x184a, x86_l_184a);
x86_l_183c:
	/* 0x183c: mov    edi,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 6ULL);
x86_l_1841:
	/* 0x1841: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1843:
	/* 0x1843: jmp    184a <tail_nodeport_nat_egress_ipv6+0x184a> */
	X86_SIM_X86_JMP(0x1843, 0x184a, x86_l_184a);
x86_l_1845:
	/* 0x1845: mov    edi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 2ULL);
x86_l_184a:
	/* 0x184a: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_184d:
	/* 0x184d: jmp    1854 <tail_nodeport_nat_egress_ipv6+0x1854> */
	X86_SIM_X86_JMP(0x184d, 0x1854, x86_l_1854);
x86_l_184f:
	/* 0x184f: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1851:
	/* 0x1851: mov    r8b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_8, 1ULL);
x86_l_1854:
	/* 0x1854: test   r15b,r15b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_8);
x86_l_1857:
	/* 0x1857: je     1a92 <tail_nodeport_nat_egress_ipv6+0x1a92> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1857, 0x1a92, x86_l_1a92);
x86_l_185d:
	/* 0x185d: test   r8b,r8b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R8, X86_R8, X86_WIDTH_8);
x86_l_1860:
	/* 0x1860: jne    18bf <tail_nodeport_nat_egress_ipv6+0x18bf> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1860, 0x18bf, x86_l_18bf);
x86_l_1862:
	/* 0x1862: add    edi,DWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDI, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 184ULL);
x86_l_1869:
	/* 0x1869: movzx  edi,dil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDI, X86_RDI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_186d:
	/* 0x186d: lea    r8,[rcx+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_1871:
	/* 0x1871: add    r8,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_1875:
	/* 0x1875: cmp    r8,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RSI, X86_WIDTH_64);
x86_l_1878:
	/* 0x1878: ja     1b36 <tail_nodeport_nat_egress_ipv6+0x1b36> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1878, 0x1b36, x86_l_1b36);
x86_l_187e:
	/* 0x187e: add    rcx,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1881:
	/* 0x1881: movzx  esi,WORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1884:
	/* 0x1884: test   esi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_32);
x86_l_1886:
	/* 0x1886: setne  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_NE);
x86_l_188a:
	/* 0x188a: or     dil,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_188d:
	/* 0x188d: cmp    dil,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_8, 1ULL);
x86_l_1891:
	/* 0x1891: jne    18bf <tail_nodeport_nat_egress_ipv6+0x18bf> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1891, 0x18bf, x86_l_18bf);
x86_l_1893:
	/* 0x1893: not    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1895:
	/* 0x1895: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1897:
	/* 0x1897: adc    eax,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_189a:
	/* 0x189a: movzx  esi,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_189d:
	/* 0x189d: shr    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_18a0:
	/* 0x18a0: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_18a2:
	/* 0x18a2: mov    esi,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_18a4:
	/* 0x18a4: shr    esi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_18a7:
	/* 0x18a7: add    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_18a9:
	/* 0x18a9: cmp    si,0xffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_16, 65535ULL);
x86_l_18ad:
	/* 0x18ad: not    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_18af:
	/* 0x18af: mov    eax,0xffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 65535ULL);
x86_l_18b4:
	/* 0x18b4: cmovne eax,esi */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RSI, X86_WIDTH_32, X86_CC_NE);
x86_l_18b7:
	/* 0x18b7: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_18b9:
	/* 0x18b9: cmovne eax,esi */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RSI, X86_WIDTH_32, X86_CC_NE);
x86_l_18bc:
	/* 0x18bc: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18bf:
	/* 0x18bf: mov    rax,QWORD PTR [r12+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_18c4:
	/* 0x18c4: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_18cc:
	/* 0x18cc: mov    rax,QWORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_18d1:
	/* 0x18d1: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_18d9:
	/* 0x18d9: movzx  eax,WORD PTR [r12+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_18df:
	/* 0x18df: mov    WORD PTR [rsp+0xaa],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 170ULL);
x86_l_18e7:
	/* 0x18e7: mov    DWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_18ef:
	/* 0x18ef: mov    rdi,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_18f6:
	/* 0x18f6: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_18fb:
	/* 0x18fb: mov    r14d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 1ULL);
x86_l_1901:
	/* 0x1901: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_1904:
	/* 0x1904: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1907:
	/* 0x1907: je     1a87 <tail_nodeport_nat_egress_ipv6+0x1a87> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1907, 0x1a87, x86_l_1a87);
x86_l_190d:
	/* 0x190d: mov    r15d,DWORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1911:
	/* 0x1911: or     r15d,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_OR, 4ULL);
x86_l_1915:
	/* 0x1915: mov    DWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_191d:
	/* 0x191d: mov    rdi,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_1924:
	/* 0x1924: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1929:
	/* 0x1929: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_192c:
	/* 0x192c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_192f:
	/* 0x192f: je     1935 <tail_nodeport_nat_egress_ipv6+0x1935> */
	X86_SIM_X86_JCC(X86_CC_E, 0x192f, 0x1935, x86_l_1935);
x86_l_1931:
	/* 0x1931: mov    DWORD PTR [rax+0x18],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1935:
	/* 0x1935: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1938:
	/* 0x1938: lea    rcx,[rax+0x36] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_193c:
	/* 0x193c: cmp    rcx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_1940:
	/* 0x1940: ja     f0 <tail_nodeport_nat_egress_ipv6+0xf0> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1940, 0xf0, x86_l_f0);
x86_l_1946:
	/* 0x1946: mov    rcx,QWORD PTR [rax+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_194a:
	/* 0x194a: mov    QWORD PTR [rsp+0xd8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_1952:
	/* 0x1952: mov    rcx,QWORD PTR [rax+0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_1956:
	/* 0x1956: mov    QWORD PTR [rsp+0xd0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_195e:
	/* 0x195e: mov    rcx,QWORD PTR [rax+0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 46ULL);
x86_l_1962:
	/* 0x1962: mov    QWORD PTR [rsp+0xe8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_196a:
	/* 0x196a: mov    rax,QWORD PTR [rax+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_196e:
	/* 0x196e: mov    QWORD PTR [rsp+0xe0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_1976:
	/* 0x1976: lea    rsi,[rsp+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_197e:
	/* 0x197e: mov    eax,0x45 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 69ULL);
x86_l_1983:
	/* 0x1983: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1986:
	/* 0x1986: mov    edx,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 64ULL);
x86_l_198b:
	/* 0x198b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_198d:
	/* 0x198d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_198f:
	/* 0x198f: mov    r15d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_32);
x86_l_1992:
	/* 0x1992: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1994:
	/* 0x1994: je     199c <tail_nodeport_nat_egress_ipv6+0x199c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1994, 0x199c, x86_l_199c);
x86_l_1996:
	/* 0x1996: cmp    r15d,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 7ULL);
x86_l_199a:
	/* 0x199a: jne    19f6 <tail_nodeport_nat_egress_ipv6+0x19f6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x199a, 0x19f6, x86_l_19f6);
x86_l_199c:
	/* 0x199c: mov    r14d,DWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_19a4:
	/* 0x19a4: mov    DWORD PTR [rsp+0x40],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_19a9:
	/* 0x19a9: mov    rdi,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_devices)));
x86_l_19b0:
	/* 0x19b0: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_19b5:
	/* 0x19b5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_19ba:
	/* 0x19ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19bc:
	/* 0x19bc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_19bf:
	/* 0x19bf: je     19cb <tail_nodeport_nat_egress_ipv6+0x19cb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x19bf, 0x19cb, x86_l_19cb);
x86_l_19c1:
	/* 0x19c1: test   BYTE PTR [rax+0x8],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_19c5:
	/* 0x19c5: jne    1a57 <tail_nodeport_nat_egress_ipv6+0x1a57> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x19c5, 0x1a57, x86_l_1a57);
x86_l_19cb:
	/* 0x19cb: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_19ce:
	/* 0x19ce: je     1a04 <tail_nodeport_nat_egress_ipv6+0x1a04> */
	X86_SIM_X86_JCC(X86_CC_E, 0x19ce, 0x1a04, x86_l_1a04);
x86_l_19d0:
	/* 0x19d0: mov    DWORD PTR [rsp+0x40],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_19d5:
	/* 0x19d5: mov    rdi,QWORD PTR [rip+0x68ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_devices)));
x86_l_19dc:
	/* 0x19dc: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_19e1:
	/* 0x19e1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_19e6:
	/* 0x19e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19e8:
	/* 0x19e8: mov    r12d,0xffffff57 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967127ULL);
x86_l_19ee:
	/* 0x19ee: mov    bpl,0x64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 100ULL);
x86_l_19f1:
	/* 0x19f1: jmp    f6 <tail_nodeport_nat_egress_ipv6+0xf6> */
	X86_SIM_X86_JMP(0x19f1, 0xf6, x86_l_f6);
x86_l_19f6:
	/* 0x19f6: mov    r12d,0xffffff57 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967127ULL);
x86_l_19fc:
	/* 0x19fc: mov    ebp,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_32);
x86_l_19ff:
	/* 0x19ff: jmp    f6 <tail_nodeport_nat_egress_ipv6+0xf6> */
	X86_SIM_X86_JMP(0x19ff, 0xf6, x86_l_f6);
x86_l_1a04:
	/* 0x1a04: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a07:
	/* 0x1a07: lea    rcx,[rax+0x6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_1a0b:
	/* 0x1a0b: mov    r12d,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967155ULL);
x86_l_1a11:
	/* 0x1a11: cmp    rcx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_1a15:
	/* 0x1a15: ja     f6 <tail_nodeport_nat_egress_ipv6+0xf6> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1a15, 0xf6, x86_l_f6);
x86_l_1a1b:
	/* 0x1a1b: movzx  ecx,WORD PTR [rsp+0xfe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 254ULL);
x86_l_1a23:
	/* 0x1a23: mov    WORD PTR [rax+0x4],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1a27:
	/* 0x1a27: mov    ecx,DWORD PTR [rsp+0xfa] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 250ULL);
x86_l_1a2e:
	/* 0x1a2e: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a30:
	/* 0x1a30: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a33:
	/* 0x1a33: lea    rcx,[rax+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1a37:
	/* 0x1a37: cmp    rcx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_1a3b:
	/* 0x1a3b: ja     f6 <tail_nodeport_nat_egress_ipv6+0xf6> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1a3b, 0xf6, x86_l_f6);
x86_l_1a41:
	/* 0x1a41: movzx  ecx,WORD PTR [rsp+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 248ULL);
x86_l_1a49:
	/* 0x1a49: mov    WORD PTR [rax+0xa],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 10ULL);
x86_l_1a4d:
	/* 0x1a4d: mov    ecx,DWORD PTR [rsp+0xf4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 244ULL);
x86_l_1a54:
	/* 0x1a54: mov    DWORD PTR [rax+0x6],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_1a57:
	/* 0x1a57: mov    r12d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 3ULL);
x86_l_1a5d:
	/* 0x1a5d: cmp    DWORD PTR [rbx+0xc],r14d */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1a61:
	/* 0x1a61: je     471 <tail_nodeport_nat_egress_ipv6+0x471> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a61, 0x471, x86_l_471);
x86_l_1a67:
	/* 0x1a67: mov    eax,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 23ULL);
x86_l_1a6c:
	/* 0x1a6c: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_1a6f:
	/* 0x1a6f: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a71:
	/* 0x1a71: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a73:
	/* 0x1a73: mov    r12d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_32);
x86_l_1a76:
	/* 0x1a76: add    eax,0xfffffffd */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4294967293ULL);
x86_l_1a79:
	/* 0x1a79: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1a7c:
	/* 0x1a7c: jae    f6 <tail_nodeport_nat_egress_ipv6+0xf6> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x1a7c, 0xf6, x86_l_f6);
x86_l_1a82:
	/* 0x1a82: jmp    471 <tail_nodeport_nat_egress_ipv6+0x471> */
	X86_SIM_X86_JMP(0x1a82, 0x471, x86_l_471);
x86_l_1a87:
	/* 0x1a87: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_1a8d:
	/* 0x1a8d: jmp    1915 <tail_nodeport_nat_egress_ipv6+0x1915> */
	X86_SIM_X86_JMP(0x1a8d, 0x1915, x86_l_1915);
x86_l_1a92:
	/* 0x1a92: mov    r12d,0xffffff72 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967154ULL);
x86_l_1a98:
	/* 0x1a98: cmp    r14d,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 58ULL);
x86_l_1a9c:
	/* 0x1a9c: ja     1b3c <tail_nodeport_nat_egress_ipv6+0x1b3c> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1a9c, 0x1b3c, x86_l_1b3c);
x86_l_1aa2:
	/* 0x1aa2: mov    r9d,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_R14, X86_WIDTH_32);
x86_l_1aa5:
	/* 0x1aa5: movabs r10,0x400000000020040 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_64, 288230376151842880ULL);
x86_l_1aaf:
	/* 0x1aaf: bt     r10,r9 */
	X86_SIM_L_EXEC_BT(X86_R10, X86_R9, X86_WIDTH_64);
x86_l_1ab3:
	/* 0x1ab3: jae    1b3c <tail_nodeport_nat_egress_ipv6+0x1b3c> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x1ab3, 0x1b3c, x86_l_1b3c);
x86_l_1ab9:
	/* 0x1ab9: mov    r9d,DWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1ac1:
	/* 0x1ac1: movzx  r10d,r9b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R10, X86_R9, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1ac5:
	/* 0x1ac5: lea    r11,[rcx+r10*1] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R10, 0), 0ULL);
x86_l_1ac9:
	/* 0x1ac9: add    r11,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_1acd:
	/* 0x1acd: mov    r12d,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967155ULL);
x86_l_1ad3:
	/* 0x1ad3: cmp    r11,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R11, X86_RSI, X86_WIDTH_64);
x86_l_1ad6:
	/* 0x1ad6: ja     1b3c <tail_nodeport_nat_egress_ipv6+0x1b3c> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1ad6, 0x1b3c, x86_l_1b3c);
x86_l_1ad8:
	/* 0x1ad8: add    r10,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1adb:
	/* 0x1adb: movzx  r11d,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1ae0:
	/* 0x1ae0: mov    WORD PTR [r10],r11w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R10, X86_R11, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ae4:
	/* 0x1ae4: add    r9d,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1ae7:
	/* 0x1ae7: movzx  r9d,r9b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R9, X86_R9, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1aeb:
	/* 0x1aeb: lea    r10,[rcx+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_1aef:
	/* 0x1aef: add    r10,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_1af3:
	/* 0x1af3: cmp    r10,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R10, X86_RSI, X86_WIDTH_64);
x86_l_1af6:
	/* 0x1af6: ja     1b36 <tail_nodeport_nat_egress_ipv6+0x1b36> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1af6, 0x1b36, x86_l_1b36);
x86_l_1af8:
	/* 0x1af8: add    r9,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1afb:
	/* 0x1afb: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1afd:
	/* 0x1afd: mov    r12,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1b02:
	/* 0x1b02: jne    1b0f <tail_nodeport_nat_egress_ipv6+0x1b0f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1b02, 0x1b0f, x86_l_1b0f);
x86_l_1b04:
	/* 0x1b04: cmp    WORD PTR [r9],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b09:
	/* 0x1b09: je     185d <tail_nodeport_nat_egress_ipv6+0x185d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1b09, 0x185d, x86_l_185d);
x86_l_1b0f:
	/* 0x1b0f: movzx  r11d,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1b14:
	/* 0x1b14: cmp    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1b19:
	/* 0x1b19: je     1b6a <tail_nodeport_nat_egress_ipv6+0x1b6a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1b19, 0x1b6a, x86_l_1b6a);
x86_l_1b1b:
	/* 0x1b1b: mov    r14d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b20:
	/* 0x1b20: not    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1b23:
	/* 0x1b23: add    r14d,r11d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R11, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1b26:
	/* 0x1b26: adc    r14d,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_1b2a:
	/* 0x1b2a: movzx  r10d,WORD PTR [r9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_R9, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1b2e:
	/* 0x1b2e: not    r10d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1b31:
	/* 0x1b31: add    r10d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R14, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1b34:
	/* 0x1b34: jmp    1b74 <tail_nodeport_nat_egress_ipv6+0x1b74> */
	X86_SIM_X86_JMP(0x1b34, 0x1b74, x86_l_1b74);
x86_l_1b36:
	/* 0x1b36: mov    r12d,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967142ULL);
x86_l_1b3c:
	/* 0x1b3c: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1b41:
	/* 0x1b41: mov    rax,QWORD PTR [rcx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1b45:
	/* 0x1b45: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1b4d:
	/* 0x1b4d: mov    rax,QWORD PTR [rcx+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b51:
	/* 0x1b51: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1b59:
	/* 0x1b59: movzx  eax,WORD PTR [rcx+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_1b5d:
	/* 0x1b5d: mov    WORD PTR [rsp+0xaa],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 170ULL);
x86_l_1b65:
	/* 0x1b65: jmp    f6 <tail_nodeport_nat_egress_ipv6+0xf6> */
	X86_SIM_X86_JMP(0x1b65, 0xf6, x86_l_f6);
x86_l_1b6a:
	/* 0x1b6a: movzx  r10d,WORD PTR [r9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_R9, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1b6e:
	/* 0x1b6e: not    r10d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1b71:
	/* 0x1b71: add    r10d,r11d */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R11, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1b74:
	/* 0x1b74: setb   r11b */
	X86_SIM_L_EXEC_SETCC(X86_R11, X86_CC_B);
x86_l_1b78:
	/* 0x1b78: movzx  r11d,r11b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R11, X86_R11, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1b7c:
	/* 0x1b7c: add    r11d,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_R10, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1b7f:
	/* 0x1b7f: movzx  r10d,r11w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R10, X86_R11, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1b83:
	/* 0x1b83: shr    r11d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1b87:
	/* 0x1b87: add    r11d,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_R10, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1b8a:
	/* 0x1b8a: mov    r10d,r11d */
	X86_SIM_L_EXEC_MOV_REG(X86_R10, X86_R11, X86_WIDTH_32);
x86_l_1b8d:
	/* 0x1b8d: shr    r10d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1b91:
	/* 0x1b91: add    r10d,r11d */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R11, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1b94:
	/* 0x1b94: cmp    r10w,0xffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_16, 65535ULL);
x86_l_1b99:
	/* 0x1b99: not    r10d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1b9c:
	/* 0x1b9c: mov    r11d,0xffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R11, X86_WIDTH_32, 65535ULL);
x86_l_1ba2:
	/* 0x1ba2: cmovne r11d,r10d */
	X86_SIM_L_EXEC_CMOV(X86_R11, X86_R10, X86_WIDTH_32, X86_CC_NE);
x86_l_1ba6:
	/* 0x1ba6: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_1ba8:
	/* 0x1ba8: cmovne r11d,r10d */
	X86_SIM_L_EXEC_CMOV(X86_R11, X86_R10, X86_WIDTH_32, X86_CC_NE);
x86_l_1bac:
	/* 0x1bac: mov    WORD PTR [r9],r11w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R9, X86_R11, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bb0:
	/* 0x1bb0: mov    r12,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1bb5:
	/* 0x1bb5: jmp    185d <tail_nodeport_nat_egress_ipv6+0x185d> */
	X86_SIM_X86_JMP(0x1bb5, 0x185d, x86_l_185d);
x86_l_1bba:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
