extern char __config_debug_lb;
extern char __config_enable_conntrack_accounting;
extern char __config_enable_ipv4_fragments;
extern char __config_enable_jiffies;
extern char __config_kernel_hz;
extern char __config_nodeport_port_max;
extern char __config_security_label;
extern char __config_supports_fib_lookup_skip_neigh;
extern char __config_trace_payload_len;
extern char cilium_calls;
extern char cilium_ct4_global;
extern char cilium_ct_any4_global;
extern char cilium_devices;
extern char cilium_ipv4_frag_datagrams;
extern char cilium_lb4_reverse_nat;
extern char cilium_metrics;
extern char cilium_snat_v4_external;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int cilium_bpf_lxc_tail_nodeport_nat_ingress_ipv4_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0x14: mov    rax,QWORD PTR [rip+0x3250] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_nodeport_port_max)));
x86_l_1b:
	/* 0x1b: movzx  ebp,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1e:
	/* 0x1e: mov    r13,QWORD PTR [rip+0x3250] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_25:
	/* 0x25: mov    eax,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29:
	/* 0x29: mov    r14d,DWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2d:
	/* 0x2d: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_35:
	/* 0x35: mov    eax,DWORD PTR [rdi+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_38:
	/* 0x38: sub    eax,DWORD PTR [rdi+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RDI, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_3b:
	/* 0x3b: mov    r12d,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967162ULL);
x86_l_41:
	/* 0x41: cmp    eax,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 34ULL);
x86_l_44:
	/* 0x44: jb     1080 <tail_nodeport_nat_ingress_ipv4+0x1080> */
	X86_SIM_X86_JCC(X86_CC_B, 0x44, 0x1080, x86_l_1080);
x86_l_4a:
	/* 0x4a: movabs r9,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_64, 2199023255552ULL);
x86_l_54:
	/* 0x54: movabs r8,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_64, 1099511627776ULL);
x86_l_5e:
	/* 0x5e: mov    rsi,QWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_65:
	/* 0x65: movzx  ecx,WORD PTR [rsi+0x12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18ULL);
x86_l_69:
	/* 0x69: movzx  eax,BYTE PTR [rsi+0x17] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 23ULL);
x86_l_6d:
	/* 0x6d: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_70:
	/* 0x70: shl    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_74:
	/* 0x74: or     rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_77:
	/* 0x77: movzx  edi,WORD PTR [rsi+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 20ULL);
x86_l_7b:
	/* 0x7b: mov    QWORD PTR [rsp+0x88],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_83:
	/* 0x83: add    r8,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_86:
	/* 0x86: test   edi,0xff3f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDI, X86_WIDTH_32, 65343ULL);
x86_l_8c:
	/* 0x8c: cmove  r8,rdx */
	X86_SIM_L_EXEC_CMOV(X86_R8, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_90:
	/* 0x90: lea    r10,[r8+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_94:
	/* 0x94: mov    BYTE PTR [rsp+0x34],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_98:
	/* 0x98: mov    ecx,DWORD PTR [rsi+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_9b:
	/* 0x9b: mov    DWORD PTR [rsp+0x28],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_9f:
	/* 0x9f: test   edi,0xff1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDI, X86_WIDTH_32, 65311ULL);
x86_l_a5:
	/* 0xa5: mov    edx,DWORD PTR [rsi+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_a8:
	/* 0xa8: mov    DWORD PTR [rsp+0x2c],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_ac:
	/* 0xac: mov    BYTE PTR [rsp+0x35],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 227633266689ULL);
x86_l_b1:
	/* 0xb1: cmove  r10,r8 */
	X86_SIM_L_EXEC_CMOV(X86_R10, X86_R8, X86_WIDTH_64, X86_CC_E);
x86_l_b5:
	/* 0xb5: mov    r15d,DWORD PTR [rsi+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_b9:
	/* 0xb9: shl    r15d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHL, 2ULL);
x86_l_bd:
	/* 0xbd: and    r15d,0x3c */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 60ULL);
x86_l_c1:
	/* 0xc1: lea    esi,[r15+0xe] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_c5:
	/* 0xc5: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c8:
	/* 0xc8: je     1d3 <tail_nodeport_nat_ingress_ipv4+0x1d3> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc8, 0x1d3, x86_l_1d3);
x86_l_ce:
	/* 0xce: mov    r12d,0xffffff53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967123ULL);
x86_l_d4:
	/* 0xd4: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_d7:
	/* 0xd7: je     e2 <tail_nodeport_nat_ingress_ipv4+0xe2> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd7, 0xe2, x86_l_e2);
x86_l_d9:
	/* 0xd9: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_dc:
	/* 0xdc: jne    1080 <tail_nodeport_nat_ingress_ipv4+0x1080> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xdc, 0x1080, x86_l_1080);
x86_l_e2:
	/* 0xe2: mov    QWORD PTR [rsp+0x38],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_e7:
	/* 0xe7: mov    r13d,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R14, X86_WIDTH_32);
x86_l_ea:
	/* 0xea: lea    r14,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ef:
	/* 0xef: mov    rax,QWORD PTR [rip+0x3250] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_ipv4_fragments)));
x86_l_f6:
	/* 0xf6: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f9:
	/* 0xf9: mov    DWORD PTR [rsp+0x58],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_fd:
	/* 0xfd: je     24b <tail_nodeport_nat_ingress_ipv4+0x24b> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfd, 0x24b, x86_l_24b);
x86_l_103:
	/* 0x103: mov    DWORD PTR [rsp+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_107:
	/* 0x107: mov    DWORD PTR [rsp+0xc],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_10b:
	/* 0x10b: mov    WORD PTR [rsp+0x10],r10w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R10, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_111:
	/* 0x111: mov    rax,r10 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R10, X86_WIDTH_64);
x86_l_114:
	/* 0x114: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_118:
	/* 0x118: mov    BYTE PTR [rsp+0x12],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_11c:
	/* 0x11c: mov    BYTE PTR [rsp+0x13],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 81604378624ULL);
x86_l_121:
	/* 0x121: mov    r15,r10 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R10, X86_WIDTH_64);
x86_l_124:
	/* 0x124: test   r10,r9 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R10, X86_R9, X86_WIDTH_64);
x86_l_127:
	/* 0x127: jne    1536 <tail_nodeport_nat_ingress_ipv4+0x1536> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x127, 0x1536, x86_l_1536);
x86_l_12d:
	/* 0x12d: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_132:
	/* 0x132: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_135:
	/* 0x135: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_138:
	/* 0x138: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_13d:
	/* 0x13d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13f:
	/* 0x13f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_141:
	/* 0x141: js     3b2 <tail_nodeport_nat_ingress_ipv4+0x3b2> */
	X86_SIM_X86_JCC(X86_CC_S, 0x141, 0x3b2, x86_l_3b2);
x86_l_147:
	/* 0x147: movabs rax,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 1099511627776ULL);
x86_l_151:
	/* 0x151: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_154:
	/* 0x154: test   r15,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_157:
	/* 0x157: je     274 <tail_nodeport_nat_ingress_ipv4+0x274> */
	X86_SIM_X86_JCC(X86_CC_E, 0x157, 0x274, x86_l_274);
x86_l_15d:
	/* 0x15d: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_162:
	/* 0x162: mov    rdi,QWORD PTR [rip+0x3250] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv4_frag_datagrams)));
x86_l_169:
	/* 0x169: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16e:
	/* 0x16e: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_171:
	/* 0x171: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_173:
	/* 0x173: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_175:
	/* 0x175: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_178:
	/* 0x178: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_17a:
	/* 0x17a: je     274 <tail_nodeport_nat_ingress_ipv4+0x274> */
	X86_SIM_X86_JCC(X86_CC_E, 0x17a, 0x274, x86_l_274);
x86_l_180:
	/* 0x180: mov    r14d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_184:
	/* 0x184: mov    QWORD PTR [rsp+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_190:
	/* 0x190: mov    QWORD PTR [rsp+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_19c:
	/* 0x19c: movabs rax,0x6b0085010a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 459570217226ULL);
x86_l_1a6:
	/* 0x1a6: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1ab:
	/* 0x1ab: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1b0:
	/* 0x1b0: mov    rdi,QWORD PTR [rip+0x3250] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1b7:
	/* 0x1b7: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1bc:
	/* 0x1bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1be:
	/* 0x1be: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1c1:
	/* 0x1c1: je     19b1 <tail_nodeport_nat_ingress_ipv4+0x19b1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1c1, 0x19b1, x86_l_19b1);
x86_l_1c7:
	/* 0x1c7: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1ca:
	/* 0x1ca: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1ce:
	/* 0x1ce: jmp    1558 <tail_nodeport_nat_ingress_ipv4+0x1558> */
	X86_SIM_X86_JMP(0x1ce, 0x1558, x86_l_1558);
x86_l_1d3:
	/* 0x1d3: mov    DWORD PTR [rsp+0x4],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1d8:
	/* 0x1d8: movabs rax,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 1099511627776ULL);
x86_l_1e2:
	/* 0x1e2: mov    QWORD PTR [rsp+0x20],r10 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R10, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e7:
	/* 0x1e7: test   r10,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R10, X86_RAX, X86_WIDTH_64);
x86_l_1ea:
	/* 0x1ea: jne    107b <tail_nodeport_nat_ingress_ipv4+0x107b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1ea, 0x107b, x86_l_107b);
x86_l_1f0:
	/* 0x1f0: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1f5:
	/* 0x1f5: mov    DWORD PTR [rsp+0x58],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1f9:
	/* 0x1f9: movzx  ebp,sil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RSI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1fd:
	/* 0x1fd: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_202:
	/* 0x202: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_205:
	/* 0x205: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_207:
	/* 0x207: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_20c:
	/* 0x20c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20e:
	/* 0x20e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_210:
	/* 0x210: js     107b <tail_nodeport_nat_ingress_ipv4+0x107b> */
	X86_SIM_X86_JCC(X86_CC_S, 0x210, 0x107b, x86_l_107b);
x86_l_216:
	/* 0x216: movzx  eax,BYTE PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 96ULL);
x86_l_21b:
	/* 0x21b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_21d:
	/* 0x21d: je     4dd <tail_nodeport_nat_ingress_ipv4+0x4dd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x21d, 0x4dd, x86_l_4dd);
x86_l_223:
	/* 0x223: mov    r12d,0xffffff53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967123ULL);
x86_l_229:
	/* 0x229: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_22c:
	/* 0x22c: je     3c0 <tail_nodeport_nat_ingress_ipv4+0x3c0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x22c, 0x3c0, x86_l_3c0);
x86_l_232:
	/* 0x232: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_235:
	/* 0x235: jne    107b <tail_nodeport_nat_ingress_ipv4+0x107b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x235, 0x107b, x86_l_107b);
x86_l_23b:
	/* 0x23b: cmp    BYTE PTR [rsp+0x61],0xf */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 416611827727ULL);
x86_l_240:
	/* 0x240: jbe    3cb <tail_nodeport_nat_ingress_ipv4+0x3cb> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x240, 0x3cb, x86_l_3cb);
x86_l_246:
	/* 0x246: jmp    107b <tail_nodeport_nat_ingress_ipv4+0x107b> */
	X86_SIM_X86_JMP(0x246, 0x107b, x86_l_107b);
x86_l_24b:
	/* 0x24b: test   r10,r9 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R10, X86_R9, X86_WIDTH_64);
x86_l_24e:
	/* 0x24e: jne    156b <tail_nodeport_nat_ingress_ipv4+0x156b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x24e, 0x156b, x86_l_156b);
x86_l_254:
	/* 0x254: mov    r15,r10 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R10, X86_WIDTH_64);
x86_l_257:
	/* 0x257: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_25c:
	/* 0x25c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_25f:
	/* 0x25f: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_262:
	/* 0x262: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_267:
	/* 0x267: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_269:
	/* 0x269: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_26b:
	/* 0x26b: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_26e:
	/* 0x26e: js     3b2 <tail_nodeport_nat_ingress_ipv4+0x3b2> */
	X86_SIM_X86_JCC(X86_CC_S, 0x26e, 0x3b2, x86_l_3b2);
x86_l_274:
	/* 0x274: inc    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_276:
	/* 0x276: movzx  eax,WORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_27b:
	/* 0x27b: movzx  ecx,WORD PTR [rsp+0x32] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 50ULL);
x86_l_280:
	/* 0x280: mov    WORD PTR [rsp+0x32],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 50ULL);
x86_l_285:
	/* 0x285: mov    WORD PTR [rsp+0x30],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_28a:
	/* 0x28a: rol    cx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_28e:
	/* 0x28e: mov    r15d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 2ULL);
x86_l_294:
	/* 0x294: cmp    cx,bp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_16);
x86_l_297:
	/* 0x297: mov    r14d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R13, X86_WIDTH_32);
x86_l_29a:
	/* 0x29a: mov    r13,QWORD PTR [rip+0x3250] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_2a1:
	/* 0x2a1: jb     1080 <tail_nodeport_nat_ingress_ipv4+0x1080> */
	X86_SIM_X86_JCC(X86_CC_B, 0x2a1, 0x1080, x86_l_1080);
x86_l_2a7:
	/* 0x2a7: mov    QWORD PTR [rsp+0x20],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ac:
	/* 0x2ac: mov    DWORD PTR [rsp+0x4],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2b1:
	/* 0x2b1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2b6:
	/* 0x2b6: mov    rdi,QWORD PTR [rip+0x3250] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_2bd:
	/* 0x2bd: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2c2:
	/* 0x2c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c4:
	/* 0x2c4: mov    r12d,0xffffff59 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967129ULL);
x86_l_2ca:
	/* 0x2ca: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2cd:
	/* 0x2cd: je     107b <tail_nodeport_nat_ingress_ipv4+0x107b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2cd, 0x107b, x86_l_107b);
x86_l_2d3:
	/* 0x2d3: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_2d6:
	/* 0x2d6: mov    DWORD PTR [rsp+0x98],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2de:
	/* 0x2de: mov    eax,DWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2e1:
	/* 0x2e1: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2e5:
	/* 0x2e5: movzx  eax,WORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_2ea:
	/* 0x2ea: mov    WORD PTR [rsp+0x12],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_2ef:
	/* 0x2ef: mov    eax,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2f3:
	/* 0x2f3: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f7:
	/* 0x2f7: movzx  eax,WORD PTR [rsp+0x32] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 50ULL);
x86_l_2fc:
	/* 0x2fc: mov    WORD PTR [rsp+0x10],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_301:
	/* 0x301: movzx  eax,BYTE PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 52ULL);
x86_l_306:
	/* 0x306: mov    BYTE PTR [rsp+0x14],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_30a:
	/* 0x30a: mov    BYTE PTR [rsp+0x15],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 90194313216ULL);
x86_l_30f:
	/* 0x30f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_314:
	/* 0x314: mov    rdi,QWORD PTR [rip+0x3250] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_31b:
	/* 0x31b: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_320:
	/* 0x320: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_322:
	/* 0x322: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_325:
	/* 0x325: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_32a:
	/* 0x32a: jne    558 <tail_nodeport_nat_ingress_ipv4+0x558> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x32a, 0x558, x86_l_558);
x86_l_330:
	/* 0x330: mov    QWORD PTR [rsp+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_33c:
	/* 0x33c: mov    QWORD PTR [rsp+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_348:
	/* 0x348: mov    QWORD PTR [rsp+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_354:
	/* 0x354: mov    QWORD PTR [rsp+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_360:
	/* 0x360: mov    QWORD PTR [rsp+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_36c:
	/* 0x36c: mov    eax,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_370:
	/* 0x370: mov    DWORD PTR [rsp+0xc0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_377:
	/* 0x377: movzx  eax,WORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_37c:
	/* 0x37c: mov    WORD PTR [rsp+0xc4],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 196ULL);
x86_l_384:
	/* 0x384: mov    rax,QWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_388:
	/* 0x388: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_390:
	/* 0x390: mov    rax,QWORD PTR [rip+0x3250] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_397:
	/* 0x397: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_39a:
	/* 0x39a: je     508 <tail_nodeport_nat_ingress_ipv4+0x508> */
	X86_SIM_X86_JCC(X86_CC_E, 0x39a, 0x508, x86_l_508);
x86_l_3a0:
	/* 0x3a0: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_3a5:
	/* 0x3a5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3a7:
	/* 0x3a7: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_3a9:
	/* 0x3a9: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_3ad:
	/* 0x3ad: jmp    52b <tail_nodeport_nat_ingress_ipv4+0x52b> */
	X86_SIM_X86_JMP(0x3ad, 0x52b, x86_l_52b);
x86_l_3b2:
	/* 0x3b2: mov    r12d,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967161ULL);
x86_l_3b8:
	/* 0x3b8: mov    r14d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R13, X86_WIDTH_32);
x86_l_3bb:
	/* 0x3bb: jmp    1080 <tail_nodeport_nat_ingress_ipv4+0x1080> */
	X86_SIM_X86_JMP(0x3bb, 0x1080, x86_l_1080);
x86_l_3c0:
	/* 0x3c0: cmp    BYTE PTR [rsp+0x61],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 416611827713ULL);
x86_l_3c5:
	/* 0x3c5: ja     107b <tail_nodeport_nat_ingress_ipv4+0x107b> */
	X86_SIM_X86_JCC(X86_CC_A, 0x3c5, 0x107b, x86_l_107b);
x86_l_3cb:
	/* 0x3cb: mov    DWORD PTR [rsp+0x58],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3cf:
	/* 0x3cf: lea    eax,[r15+0x16] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_3d3:
	/* 0x3d3: mov    QWORD PTR [rsp+0xe],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60129542144ULL);
x86_l_3dc:
	/* 0x3dc: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_3e5:
	/* 0x3e5: mov    r14d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3e9:
	/* 0x3e9: mov    r8d,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 26ULL);
x86_l_3ef:
	/* 0x3ef: movzx  ebp,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_3f2:
	/* 0x3f2: lea    rdx,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_3fa:
	/* 0x3fa: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_3fd:
	/* 0x3fd: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_3ff:
	/* 0x3ff: mov    ecx,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 20ULL);
x86_l_404:
	/* 0x404: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_407:
	/* 0x407: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_409:
	/* 0x409: js     966 <tail_nodeport_nat_ingress_ipv4+0x966> */
	X86_SIM_X86_JCC(X86_CC_S, 0x409, 0x966, x86_l_966);
x86_l_40f:
	/* 0x40f: movzx  eax,BYTE PTR [rsp+0xa9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 169ULL);
x86_l_417:
	/* 0x417: mov    ecx,DWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_41e:
	/* 0x41e: mov    BYTE PTR [rsp+0x14],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_422:
	/* 0x422: mov    rdx,QWORD PTR [rsp+0xac] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_42a:
	/* 0x42a: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_42f:
	/* 0x42f: and    ecx,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_432:
	/* 0x432: mov    BYTE PTR [rsp+0x15],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 90194313217ULL);
x86_l_437:
	/* 0x437: lea    r13d,[rbp+rcx*4+0x0] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 0ULL);
x86_l_43c:
	/* 0x43c: mov    r12d,0xffffff53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967123ULL);
x86_l_442:
	/* 0x442: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_445:
	/* 0x445: je     910 <tail_nodeport_nat_ingress_ipv4+0x910> */
	X86_SIM_X86_JCC(X86_CC_E, 0x445, 0x910, x86_l_910);
x86_l_44b:
	/* 0x44b: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_44e:
	/* 0x44e: je     459 <tail_nodeport_nat_ingress_ipv4+0x459> */
	X86_SIM_X86_JCC(X86_CC_E, 0x44e, 0x459, x86_l_459);
x86_l_450:
	/* 0x450: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_453:
	/* 0x453: jne    107b <tail_nodeport_nat_ingress_ipv4+0x107b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x453, 0x107b, x86_l_107b);
x86_l_459:
	/* 0x459: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_45e:
	/* 0x45e: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_463:
	/* 0x463: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_466:
	/* 0x466: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_469:
	/* 0x469: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_46e:
	/* 0x46e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_470:
	/* 0x470: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_472:
	/* 0x472: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_474:
	/* 0x474: js     966 <tail_nodeport_nat_ingress_ipv4+0x966> */
	X86_SIM_X86_JCC(X86_CC_S, 0x474, 0x966, x86_l_966);
x86_l_47a:
	/* 0x47a: mov    DWORD PTR [rsp+0x38],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_47f:
	/* 0x47f: mov    DWORD PTR [rsp+0x44],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_483:
	/* 0x483: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_488:
	/* 0x488: mov    rdi,QWORD PTR [rip+0x3250] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_48f:
	/* 0x48f: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_494:
	/* 0x494: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_496:
	/* 0x496: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_499:
	/* 0x499: je     107b <tail_nodeport_nat_ingress_ipv4+0x107b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x499, 0x107b, x86_l_107b);
x86_l_49f:
	/* 0x49f: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_4a2:
	/* 0x4a2: movzx  eax,BYTE PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 20ULL);
x86_l_4a7:
	/* 0x4a7: mov    cl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_4a9:
	/* 0x4a9: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_4ac:
	/* 0x4ac: je     f1e <tail_nodeport_nat_ingress_ipv4+0xf1e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4ac, 0xf1e, x86_l_f1e);
x86_l_4b2:
	/* 0x4b2: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_4b5:
	/* 0x4b5: jne    f58 <tail_nodeport_nat_ingress_ipv4+0xf58> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4b5, 0xf58, x86_l_f58);
x86_l_4bb:
	/* 0x4bb: mov    edx,DWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_4bf:
	/* 0x4bf: sub    edx,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RBP, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4c1:
	/* 0x4c1: mov    eax,DWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_4c8:
	/* 0x4c8: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_4cb:
	/* 0x4cb: lea    eax,[rax*4+0x12] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 18ULL);
x86_l_4d2:
	/* 0x4d2: cmp    edx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_4d4:
	/* 0x4d4: setae  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_AE);
x86_l_4d8:
	/* 0x4d8: jmp    f5b <tail_nodeport_nat_ingress_ipv4+0xf5b> */
	X86_SIM_X86_JMP(0x4d8, 0xf5b, x86_l_f5b);
x86_l_4dd:
	/* 0x4dd: mov    QWORD PTR [rsp+0x38],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_4e2:
	/* 0x4e2: movzx  eax,WORD PTR [rsp+0x64] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 100ULL);
x86_l_4e7:
	/* 0x4e7: mov    WORD PTR [rsp+0x30],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4ec:
	/* 0x4ec: mov    WORD PTR [rsp+0x32],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 214748364800ULL);
x86_l_4f3:
	/* 0x4f3: mov    r15d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4ULL);
x86_l_4f9:
	/* 0x4f9: mov    r14d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4fe:
	/* 0x4fe: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_503:
	/* 0x503: jmp    2a7 <tail_nodeport_nat_ingress_ipv4+0x2a7> */
	X86_SIM_X86_JMP(0x503, 0x2a7, x86_l_2a7);
x86_l_508:
	/* 0x508: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_50d:
	/* 0x50d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_50f:
	/* 0x50f: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_511:
	/* 0x511: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_515:
	/* 0x515: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_51f:
	/* 0x51f: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_522:
	/* 0x522: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_527:
	/* 0x527: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_52b:
	/* 0x52b: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_533:
	/* 0x533: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_538:
	/* 0x538: mov    rdi,QWORD PTR [rip+0x3250] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_53f:
	/* 0x53f: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_544:
	/* 0x544: lea    rdx,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_54c:
	/* 0x54c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_54e:
	/* 0x54e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_550:
	/* 0x550: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_552:
	/* 0x552: js     107b <tail_nodeport_nat_ingress_ipv4+0x107b> */
	X86_SIM_X86_JCC(X86_CC_S, 0x552, 0x107b, x86_l_107b);
x86_l_558:
	/* 0x558: cmp    QWORD PTR [r14+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_55d:
	/* 0x55d: movabs r10,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_64, 2199023255552ULL);
x86_l_567:
	/* 0x567: mov    r8,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_56c:
	/* 0x56c: je     a1f <tail_nodeport_nat_ingress_ipv4+0xa1f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x56c, 0xa1f, x86_l_a1f);
x86_l_572:
	/* 0x572: movzx  eax,WORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 52ULL);
x86_l_577:
	/* 0x577: mov    WORD PTR [rsp+0x14],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_57c:
	/* 0x57c: movzx  ecx,WORD PTR [rsp+0x32] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 50ULL);
x86_l_581:
	/* 0x581: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_586:
	/* 0x586: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_58b:
	/* 0x58b: mov    edx,DWORD PTR [r14+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_58f:
	/* 0x58f: mov    DWORD PTR [rsp+0x8],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_593:
	/* 0x593: movzx  edx,WORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_598:
	/* 0x598: mov    WORD PTR [rsp+0x12],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_59d:
	/* 0x59d: mov    WORD PTR [rsp+0x10],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5a2:
	/* 0x5a2: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_5a5:
	/* 0x5a5: mov    DWORD PTR [rsp+0x44],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_5a9:
	/* 0x5a9: cmp    ax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_16, 6ULL);
x86_l_5ad:
	/* 0x5ad: jne    5b8 <tail_nodeport_nat_ingress_ipv4+0x5b8> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x5ad, 0x5b8, x86_l_5b8);
x86_l_5af:
	/* 0x5af: mov    rdi,QWORD PTR [rip+0x3250] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct4_global)));
x86_l_5b6:
	/* 0x5b6: jmp    5bf <tail_nodeport_nat_ingress_ipv4+0x5bf> */
	X86_SIM_X86_JMP(0x5b6, 0x5bf, x86_l_5bf);
x86_l_5b8:
	/* 0x5b8: mov    rdi,QWORD PTR [rip+0x3250] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct_any4_global)));
x86_l_5bf:
	/* 0x5bf: mov    BYTE PTR [rsp+0x15],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 90194313216ULL);
x86_l_5c4:
	/* 0x5c4: mov    DWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_5cc:
	/* 0x5cc: mov    rax,QWORD PTR [rip+0x3250] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_ipv4_fragments)));
x86_l_5d3:
	/* 0x5d3: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5d6:
	/* 0x5d6: mov    QWORD PTR [rsp+0x70],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_5db:
	/* 0x5db: je     683 <tail_nodeport_nat_ingress_ipv4+0x683> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5db, 0x683, x86_l_683);
x86_l_5e1:
	/* 0x5e1: mov    rax,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R8, X86_WIDTH_64);
x86_l_5e4:
	/* 0x5e4: movabs rcx,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1099511627776ULL);
x86_l_5ee:
	/* 0x5ee: and    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_5f1:
	/* 0x5f1: je     683 <tail_nodeport_nat_ingress_ipv4+0x683> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5f1, 0x683, x86_l_683);
x86_l_5f7:
	/* 0x5f7: mov    r12,r10 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R10, X86_WIDTH_64);
x86_l_5fa:
	/* 0x5fa: mov    ebp,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_5fd:
	/* 0x5fd: mov    QWORD PTR [rsp+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_609:
	/* 0x609: mov    QWORD PTR [rsp+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_615:
	/* 0x615: movabs rax,0x6c03a50109 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 463917613321ULL);
x86_l_61f:
	/* 0x61f: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_624:
	/* 0x624: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_629:
	/* 0x629: mov    rdi,QWORD PTR [rip+0x3250] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_630:
	/* 0x630: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_635:
	/* 0x635: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_637:
	/* 0x637: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_63a:
	/* 0x63a: je     645 <tail_nodeport_nat_ingress_ipv4+0x645> */
	X86_SIM_X86_JCC(X86_CC_E, 0x63a, 0x645, x86_l_645);
x86_l_63c:
	/* 0x63c: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_63f:
	/* 0x63f: add    QWORD PTR [rax+0x8],rbp */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_643:
	/* 0x643: jmp    676 <tail_nodeport_nat_ingress_ipv4+0x676> */
	X86_SIM_X86_JMP(0x643, 0x676, x86_l_676);
x86_l_645:
	/* 0x645: mov    QWORD PTR [rsp+0xa0],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767361ULL);
x86_l_651:
	/* 0x651: mov    QWORD PTR [rsp+0xa8],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_659:
	/* 0x659: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_65e:
	/* 0x65e: mov    rdi,QWORD PTR [rip+0x3250] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_665:
	/* 0x665: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_66a:
	/* 0x66a: lea    rdx,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_672:
	/* 0x672: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_674:
	/* 0x674: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_676:
	/* 0x676: mov    r10,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R10, X86_R12, X86_WIDTH_64);
x86_l_679:
	/* 0x679: mov    r8,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_67e:
	/* 0x67e: mov    rdi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_683:
	/* 0x683: cmp    WORD PTR [rsp+0x44],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 292057776134ULL);
x86_l_689:
	/* 0x689: jne    6ea <tail_nodeport_nat_ingress_ipv4+0x6ea> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x689, 0x6ea, x86_l_6ea);
x86_l_68b:
	/* 0x68b: mov    rax,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R8, X86_WIDTH_64);
x86_l_68e:
	/* 0x68e: and    rax,r10 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R10, X86_WIDTH_64, X86_ALU_AND);
x86_l_691:
	/* 0x691: jne    6ea <tail_nodeport_nat_ingress_ipv4+0x6ea> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x691, 0x6ea, x86_l_6ea);
x86_l_693:
	/* 0x693: mov    rbp,r10 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R10, X86_WIDTH_64);
x86_l_696:
	/* 0x696: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_69b:
	/* 0x69b: lea    ecx,[r15+0x1a] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_69f:
	/* 0x69f: movzx  esi,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_6a2:
	/* 0x6a2: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_6a7:
	/* 0x6a7: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_6aa:
	/* 0x6aa: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_6af:
	/* 0x6af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6b1:
	/* 0x6b1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_6b3:
	/* 0x6b3: js     74c <tail_nodeport_nat_ingress_ipv4+0x74c> */
	X86_SIM_X86_JCC(X86_CC_S, 0x6b3, 0x74c, x86_l_74c);
x86_l_6b9:
	/* 0x6b9: mov    r12d,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_6be:
	/* 0x6be: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_6c1:
	/* 0x6c1: and    eax,0x1200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4608ULL);
x86_l_6c6:
	/* 0x6c6: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6c8:
	/* 0x6c8: cmp    eax,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 512ULL);
x86_l_6cd:
	/* 0x6cd: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_6d0:
	/* 0x6d0: test   r12d,0x500 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R12, X86_WIDTH_32, 1280ULL);
x86_l_6d7:
	/* 0x6d7: jne    1a1c <tail_nodeport_nat_ingress_ipv4+0x1a1c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x6d7, 0x1a1c, x86_l_1a1c);
x86_l_6dd:
	/* 0x6dd: mov    cl,al */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_8);
x86_l_6df:
	/* 0x6df: mov    rdi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_6e4:
	/* 0x6e4: mov    DWORD PTR [rsp+0x78],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_6e8:
	/* 0x6e8: jmp    6fa <tail_nodeport_nat_ingress_ipv4+0x6fa> */
	X86_SIM_X86_JMP(0x6e8, 0x6fa, x86_l_6fa);
x86_l_6ea:
	/* 0x6ea: mov    rbp,r10 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R10, X86_WIDTH_64);
x86_l_6ed:
	/* 0x6ed: mov    DWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_6f5:
	/* 0x6f5: mov    r12d,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_6fa:
	/* 0x6fa: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6ff:
	/* 0x6ff: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_704:
	/* 0x704: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_706:
	/* 0x706: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_709:
	/* 0x709: mov    r10,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R10, X86_RBP, X86_WIDTH_64);
x86_l_70c:
	/* 0x70c: mov    r8,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_711:
	/* 0x711: je     a1b <tail_nodeport_nat_ingress_ipv4+0xa1b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x711, 0xa1b, x86_l_a1b);
x86_l_717:
	/* 0x717: mov    r9,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RAX, X86_WIDTH_64);
x86_l_71a:
	/* 0x71a: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_71d:
	/* 0x71d: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_71f:
	/* 0x71f: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_721:
	/* 0x721: test   cl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_724:
	/* 0x724: je     84f <tail_nodeport_nat_ingress_ipv4+0x84f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x724, 0x84f, x86_l_84f);
x86_l_72a:
	/* 0x72a: mov    DWORD PTR [rsp+0x70],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_72f:
	/* 0x72f: mov    rdx,QWORD PTR [rip+0x3250] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_736:
	/* 0x736: cmp    BYTE PTR [rdx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_739:
	/* 0x739: je     757 <tail_nodeport_nat_ingress_ipv4+0x757> */
	X86_SIM_X86_JCC(X86_CC_E, 0x739, 0x757, x86_l_757);
x86_l_73b:
	/* 0x73b: mov    rcx,QWORD PTR [rip+0x3250] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_742:
	/* 0x742: imul   r12d,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_746:
	/* 0x746: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_74a:
	/* 0x74a: jmp    75d <tail_nodeport_nat_ingress_ipv4+0x75d> */
	X86_SIM_X86_JMP(0x74a, 0x75d, x86_l_75d);
x86_l_74c:
	/* 0x74c: mov    r12d,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967161ULL);
x86_l_752:
	/* 0x752: jmp    107b <tail_nodeport_nat_ingress_ipv4+0x107b> */
	X86_SIM_X86_JMP(0x752, 0x107b, x86_l_107b);
x86_l_757:
	/* 0x757: mov    r12d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 60ULL);
x86_l_75d:
	/* 0x75d: cmp    WORD PTR [rsp+0x44],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 292057776134ULL);
x86_l_763:
	/* 0x763: jne    79d <tail_nodeport_nat_ingress_ipv4+0x79d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x763, 0x79d, x86_l_79d);
x86_l_765:
	/* 0x765: mov    ecx,DWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_769:
	/* 0x769: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_76b:
	/* 0x76b: shr    ecx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_76e:
	/* 0x76e: and    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_771:
	/* 0x771: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_773:
	/* 0x773: mov    WORD PTR [r9+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R9, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_778:
	/* 0x778: test   al,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 16ULL);
x86_l_77a:
	/* 0x77a: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_77f:
	/* 0x77f: mov    r12d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 21600ULL);
x86_l_785:
	/* 0x785: cmove  r12d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_789:
	/* 0x789: cmp    BYTE PTR [rdx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_78c:
	/* 0x78c: je     79d <tail_nodeport_nat_ingress_ipv4+0x79d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x78c, 0x79d, x86_l_79d);
x86_l_78e:
	/* 0x78e: mov    rax,QWORD PTR [rip+0x3250] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_795:
	/* 0x795: imul   r12d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_799:
	/* 0x799: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_79d:
	/* 0x79d: mov    QWORD PTR [rsp+0x80],r9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_7a5:
	/* 0x7a5: mov    ebp,DWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_7a9:
	/* 0x7a9: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_7ac:
	/* 0x7ac: cmp    BYTE PTR [rdx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7af:
	/* 0x7af: je     7c0 <tail_nodeport_nat_ingress_ipv4+0x7c0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7af, 0x7c0, x86_l_7c0);
x86_l_7b1:
	/* 0x7b1: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_7b6:
	/* 0x7b6: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7b8:
	/* 0x7b8: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_7ba:
	/* 0x7ba: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_7be:
	/* 0x7be: jmp    7e3 <tail_nodeport_nat_ingress_ipv4+0x7e3> */
	X86_SIM_X86_JMP(0x7be, 0x7e3, x86_l_7e3);
x86_l_7c0:
	/* 0x7c0: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_7c5:
	/* 0x7c5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7c7:
	/* 0x7c7: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_7c9:
	/* 0x7c9: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_7cd:
	/* 0x7cd: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_7d7:
	/* 0x7d7: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_7da:
	/* 0x7da: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_7df:
	/* 0x7df: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_7e3:
	/* 0x7e3: add    r12d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_7e6:
	/* 0x7e6: mov    r9,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_7ee:
	/* 0x7ee: mov    DWORD PTR [r9+0x20],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R9, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7f2:
	/* 0x7f2: movzx  ecx,BYTE PTR [r9+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R9, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_7f7:
	/* 0x7f7: mov    edx,DWORD PTR [r9+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_7fb:
	/* 0x7fb: and    bpl,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_7ff:
	/* 0x7ff: mov    rsi,QWORD PTR [rip+0x3250] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_806:
	/* 0x806: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_809:
	/* 0x809: movabs r10,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_64, 2199023255552ULL);
x86_l_813:
	/* 0x813: mov    r8,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_818:
	/* 0x818: je     82b <tail_nodeport_nat_ingress_ipv4+0x82b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x818, 0x82b, x86_l_82b);
x86_l_81a:
	/* 0x81a: mov    rsi,QWORD PTR [rip+0x3250] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_821:
	/* 0x821: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_823:
	/* 0x823: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_826:
	/* 0x826: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_829:
	/* 0x829: jmp    830 <tail_nodeport_nat_ingress_ipv4+0x830> */
	X86_SIM_X86_JMP(0x829, 0x830, x86_l_830);
x86_l_82b:
	/* 0x82b: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_830:
	/* 0x830: mov    r12d,DWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_835:
	/* 0x835: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_837:
	/* 0x837: or     bpl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_83a:
	/* 0x83a: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_83c:
	/* 0x83c: jb     843 <tail_nodeport_nat_ingress_ipv4+0x843> */
	X86_SIM_X86_JCC(X86_CC_B, 0x83c, 0x843, x86_l_843);
x86_l_83e:
	/* 0x83e: cmp    cl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_8);
x86_l_841:
	/* 0x841: je     84f <tail_nodeport_nat_ingress_ipv4+0x84f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x841, 0x84f, x86_l_84f);
x86_l_843:
	/* 0x843: mov    BYTE PTR [r9+0x2b],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R9, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_847:
	/* 0x847: mov    DWORD PTR [r9+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R9, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_84b:
	/* 0x84b: mov    eax,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_84f:
	/* 0x84f: mov    rax,QWORD PTR [rip+0x3250] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_856:
	/* 0x856: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_859:
	/* 0x859: je     868 <tail_nodeport_nat_ingress_ipv4+0x868> */
	X86_SIM_X86_JCC(X86_CC_E, 0x859, 0x868, x86_l_868);
x86_l_85b:
	/* 0x85b: inc QWORD PTR [r9+0x10] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R9, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 16ULL);
x86_l_860:
	/* 0x860: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_863:
	/* 0x863: add QWORD PTR [r9+0x18],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R9, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_868:
	/* 0x868: mov    eax,DWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_86c:
	/* 0x86c: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_86f:
	/* 0x86f: je     8cd <tail_nodeport_nat_ingress_ipv4+0x8cd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x86f, 0x8cd, x86_l_8cd);
x86_l_871:
	/* 0x871: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_874:
	/* 0x874: jne    a1f <tail_nodeport_nat_ingress_ipv4+0xa1f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x874, 0xa1f, x86_l_a1f);
x86_l_87a:
	/* 0x87a: movzx  eax,WORD PTR [r9+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R9, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_87f:
	/* 0x87f: test   al,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 3ULL);
x86_l_881:
	/* 0x881: je     a1f <tail_nodeport_nat_ingress_ipv4+0xa1f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x881, 0xa1f, x86_l_a1f);
x86_l_887:
	/* 0x887: mov    ebp,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R12, X86_WIDTH_32);
x86_l_88a:
	/* 0x88a: mov    QWORD PTR [rsp+0x38],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_88f:
	/* 0x88f: mov    WORD PTR [r9+0x2a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 180388626432ULL);
x86_l_896:
	/* 0x896: and    eax,0xffec */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 65516ULL);
x86_l_89b:
	/* 0x89b: mov    QWORD PTR [rsp+0x80],r9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_8a3:
	/* 0x8a3: mov    WORD PTR [r9+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R9, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_8a8:
	/* 0x8a8: mov    r15,QWORD PTR [rip+0x3250] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_8af:
	/* 0x8af: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8b3:
	/* 0x8b3: je     1a6a <tail_nodeport_nat_ingress_ipv4+0x1a6a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8b3, 0x1a6a, x86_l_1a6a);
x86_l_8b9:
	/* 0x8b9: mov    rcx,QWORD PTR [rip+0x3250] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_8c0:
	/* 0x8c0: imul   r12d,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_8c4:
	/* 0x8c4: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_8c8:
	/* 0x8c8: jmp    1a70 <tail_nodeport_nat_ingress_ipv4+0x1a70> */
	X86_SIM_X86_JMP(0x8c8, 0x1a70, x86_l_1a70);
x86_l_8cd:
	/* 0x8cd: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_8d0:
	/* 0x8d0: shr    eax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_8d3:
	/* 0x8d3: and    eax,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2ULL);
x86_l_8d6:
	/* 0x8d6: or     ax,WORD PTR [r9+0x24] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R9, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 36ULL);
x86_l_8db:
	/* 0x8db: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_8dd:
	/* 0x8dd: or     ecx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_OR, 1ULL);
x86_l_8e0:
	/* 0x8e0: mov    WORD PTR [r9+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R9, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_8e5:
	/* 0x8e5: mov    ecx,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8e9:
	/* 0x8e9: test   al,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 2ULL);
x86_l_8eb:
	/* 0x8eb: je     a1f <tail_nodeport_nat_ingress_ipv4+0xa1f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8eb, 0xa1f, x86_l_a1f);
x86_l_8f1:
	/* 0x8f1: mov    rcx,QWORD PTR [rip+0x3250] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_8f8:
	/* 0x8f8: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8fb:
	/* 0x8fb: je     971 <tail_nodeport_nat_ingress_ipv4+0x971> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8fb, 0x971, x86_l_971);
x86_l_8fd:
	/* 0x8fd: mov    rax,QWORD PTR [rip+0x3250] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_904:
	/* 0x904: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_906:
	/* 0x906: add    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_908:
	/* 0x908: lea    ebp,[rax+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_90b:
	/* 0x90b: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_90e:
	/* 0x90e: jmp    976 <tail_nodeport_nat_ingress_ipv4+0x976> */
	X86_SIM_X86_JMP(0x90e, 0x976, x86_l_976);
x86_l_910:
	/* 0x910: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_915:
	/* 0x915: lea    rdx,[rsp+0x57] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 87ULL);
x86_l_91a:
	/* 0x91a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_91d:
	/* 0x91d: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_920:
	/* 0x920: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_925:
	/* 0x925: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_927:
	/* 0x927: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_929:
	/* 0x929: js     966 <tail_nodeport_nat_ingress_ipv4+0x966> */
	X86_SIM_X86_JCC(X86_CC_S, 0x929, 0x966, x86_l_966);
x86_l_92b:
	/* 0x92b: movzx  eax,BYTE PTR [rsp+0x57] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 87ULL);
x86_l_930:
	/* 0x930: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_932:
	/* 0x932: je     107b <tail_nodeport_nat_ingress_ipv4+0x107b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x932, 0x107b, x86_l_107b);
x86_l_938:
	/* 0x938: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_93b:
	/* 0x93b: jne    1271 <tail_nodeport_nat_ingress_ipv4+0x1271> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x93b, 0x1271, x86_l_1271);
x86_l_941:
	/* 0x941: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_946:
	/* 0x946: lea    esi,[r13+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_94a:
	/* 0x94a: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_94f:
	/* 0x94f: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_952:
	/* 0x952: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_957:
	/* 0x957: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_959:
	/* 0x959: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_95e:
	/* 0x95e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_960:
	/* 0x960: jns    47a <tail_nodeport_nat_ingress_ipv4+0x47a> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x960, 0x47a, x86_l_47a);
x86_l_966:
	/* 0x966: mov    r12d,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967162ULL);
x86_l_96c:
	/* 0x96c: jmp    107b <tail_nodeport_nat_ingress_ipv4+0x107b> */
	X86_SIM_X86_JMP(0x96c, 0x107b, x86_l_107b);
x86_l_971:
	/* 0x971: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_976:
	/* 0x976: mov    QWORD PTR [rsp+0x80],r9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_97e:
	/* 0x97e: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_982:
	/* 0x982: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_985:
	/* 0x985: je     996 <tail_nodeport_nat_ingress_ipv4+0x996> */
	X86_SIM_X86_JCC(X86_CC_E, 0x985, 0x996, x86_l_996);
x86_l_987:
	/* 0x987: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_98c:
	/* 0x98c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_98e:
	/* 0x98e: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_990:
	/* 0x990: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_994:
	/* 0x994: jmp    9b9 <tail_nodeport_nat_ingress_ipv4+0x9b9> */
	X86_SIM_X86_JMP(0x994, 0x9b9, x86_l_9b9);
x86_l_996:
	/* 0x996: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_99b:
	/* 0x99b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_99d:
	/* 0x99d: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_99f:
	/* 0x99f: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_9a3:
	/* 0x9a3: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_9ad:
	/* 0x9ad: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_9b0:
	/* 0x9b0: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_9b5:
	/* 0x9b5: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_9b9:
	/* 0x9b9: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_9bb:
	/* 0x9bb: mov    r9,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_9c3:
	/* 0x9c3: mov    DWORD PTR [r9+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R9, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9c7:
	/* 0x9c7: movzx  ecx,BYTE PTR [r9+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R9, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_9cc:
	/* 0x9cc: mov    edx,DWORD PTR [r9+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_9d0:
	/* 0x9d0: and    r12b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_9d4:
	/* 0x9d4: mov    rsi,QWORD PTR [rip+0x3250] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_9db:
	/* 0x9db: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9de:
	/* 0x9de: movabs r10,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_64, 2199023255552ULL);
x86_l_9e8:
	/* 0x9e8: mov    r8,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9ed:
	/* 0x9ed: je     a00 <tail_nodeport_nat_ingress_ipv4+0xa00> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9ed, 0xa00, x86_l_a00);
x86_l_9ef:
	/* 0x9ef: mov    rsi,QWORD PTR [rip+0x3250] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_9f6:
	/* 0x9f6: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9f8:
	/* 0x9f8: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_9fb:
	/* 0x9fb: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_9fe:
	/* 0x9fe: jmp    a05 <tail_nodeport_nat_ingress_ipv4+0xa05> */
	X86_SIM_X86_JMP(0x9fe, 0xa05, x86_l_a05);
x86_l_a00:
	/* 0xa00: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_a05:
	/* 0xa05: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_a07:
	/* 0xa07: or     r12b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_a0a:
	/* 0xa0a: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_a0c:
	/* 0xa0c: jb     a13 <tail_nodeport_nat_ingress_ipv4+0xa13> */
	X86_SIM_X86_JCC(X86_CC_B, 0xa0c, 0xa13, x86_l_a13);
x86_l_a0e:
	/* 0xa0e: cmp    cl,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R12, X86_WIDTH_8);
x86_l_a11:
	/* 0xa11: je     a1f <tail_nodeport_nat_ingress_ipv4+0xa1f> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa11, 0xa1f, x86_l_a1f);
x86_l_a13:
	/* 0xa13: mov    BYTE PTR [r9+0x2b],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R9, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_a17:
	/* 0xa17: mov    DWORD PTR [r9+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R9, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_a1b:
	/* 0xa1b: mov    eax,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a1f:
	/* 0xa1f: movzx  ebp,WORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_a24:
	/* 0xa24: movzx  eax,BYTE PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 88ULL);
x86_l_a29:
	/* 0xa29: mov    DWORD PTR [rsp+0x58],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_a2d:
	/* 0xa2d: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a2f:
	/* 0xa2f: movzx  r13d,BYTE PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 52ULL);
x86_l_a35:
	/* 0xa35: mov    eax,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a39:
	/* 0xa39: mov    r14d,DWORD PTR [r14+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a3d:
	/* 0xa3d: movzx  ecx,WORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_a42:
	/* 0xa42: mov    DWORD PTR [rsp+0xa0],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_a4a:
	/* 0xa4a: cmp    eax,r14d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R14, X86_WIDTH_32);
x86_l_a4d:
	/* 0xa4d: jne    a5c <tail_nodeport_nat_ingress_ipv4+0xa5c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa4d, 0xa5c, x86_l_a5c);
x86_l_a4f:
	/* 0xa4f: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_a51:
	/* 0xa51: jne    a5c <tail_nodeport_nat_ingress_ipv4+0xa5c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa51, 0xa5c, x86_l_a5c);
x86_l_a53:
	/* 0xa53: cmp    cx,bp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_16);
x86_l_a56:
	/* 0xa56: je     c13 <tail_nodeport_nat_ingress_ipv4+0xc13> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa56, 0xc13, x86_l_c13);
x86_l_a5c:
	/* 0xa5c: mov    DWORD PTR [rsp+0x44],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_a60:
	/* 0xa60: mov    DWORD PTR [rsp+0x38],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_a64:
	/* 0xa64: mov    r12,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R15, X86_WIDTH_64);
x86_l_a67:
	/* 0xa67: mov    r15,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R8, X86_WIDTH_64);
x86_l_a6a:
	/* 0xa6a: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_a6c:
	/* 0xa6c: add    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_a6f:
	/* 0xa6f: adc    r14d,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_a73:
	/* 0xa73: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_a78:
	/* 0xa78: lea    rdx,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_a80:
	/* 0xa80: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_a83:
	/* 0xa83: mov    esi,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 30ULL);
x86_l_a88:
	/* 0xa88: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_a8d:
	/* 0xa8d: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a90:
	/* 0xa90: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a92:
	/* 0xa92: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a94:
	/* 0xa94: js     106d <tail_nodeport_nat_ingress_ipv4+0x106d> */
	X86_SIM_X86_JCC(X86_CC_S, 0xa94, 0x106d, x86_l_106d);
x86_l_a9a:
	/* 0xa9a: mov    eax,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_a9f:
	/* 0xa9f: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_aa2:
	/* 0xaa2: mov    esi,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 24ULL);
x86_l_aa7:
	/* 0xaa7: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_aa9:
	/* 0xaa9: mov    ecx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_32);
x86_l_aac:
	/* 0xaac: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_aaf:
	/* 0xaaf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ab1:
	/* 0xab1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ab3:
	/* 0xab3: js     1075 <tail_nodeport_nat_ingress_ipv4+0x1075> */
	X86_SIM_X86_JCC(X86_CC_S, 0xab3, 0x1075, x86_l_1075);
x86_l_ab9:
	/* 0xab9: movabs r10,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_64, 2199023255552ULL);
x86_l_ac3:
	/* 0xac3: test   r15,r10 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R10, X86_WIDTH_64);
x86_l_ac6:
	/* 0xac6: mov    ecx,DWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_aca:
	/* 0xaca: mov    edx,DWORD PTR [rsp+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_ace:
	/* 0xace: jne    c13 <tail_nodeport_nat_ingress_ipv4+0xc13> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xace, 0xc13, x86_l_c13);
x86_l_ad4:
	/* 0xad4: mov    r15,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R12, X86_WIDTH_64);
x86_l_ad7:
	/* 0xad7: mov    eax,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_ada:
	/* 0xada: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_add:
	/* 0xadd: cmp    r13d,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 58ULL);
x86_l_ae1:
	/* 0xae1: je     b01 <tail_nodeport_nat_ingress_ipv4+0xb01> */
	X86_SIM_X86_JCC(X86_CC_E, 0xae1, 0xb01, x86_l_b01);
x86_l_ae3:
	/* 0xae3: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_ae6:
	/* 0xae6: je     af4 <tail_nodeport_nat_ingress_ipv4+0xaf4> */
	X86_SIM_X86_JCC(X86_CC_E, 0xae6, 0xaf4, x86_l_af4);
x86_l_ae8:
	/* 0xae8: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_aeb:
	/* 0xaeb: jne    b08 <tail_nodeport_nat_ingress_ipv4+0xb08> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xaeb, 0xb08, x86_l_b08);
x86_l_aed:
	/* 0xaed: mov    r12w,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_16, 16ULL);
x86_l_af2:
	/* 0xaf2: jmp    b0b <tail_nodeport_nat_ingress_ipv4+0xb0b> */
	X86_SIM_X86_JMP(0xaf2, 0xb0b, x86_l_b0b);
x86_l_af4:
	/* 0xaf4: mov    r8d,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 32ULL);
x86_l_afa:
	/* 0xafa: mov    r12w,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_16, 6ULL);
x86_l_aff:
	/* 0xaff: jmp    b0b <tail_nodeport_nat_ingress_ipv4+0xb0b> */
	X86_SIM_X86_JMP(0xaff, 0xb0b, x86_l_b0b);
x86_l_b01:
	/* 0xb01: mov    r12w,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_16, 2ULL);
x86_l_b06:
	/* 0xb06: jmp    b0b <tail_nodeport_nat_ingress_ipv4+0xb0b> */
	X86_SIM_X86_JMP(0xb06, 0xb0b, x86_l_b0b);
x86_l_b08:
	/* 0xb08: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b0b:
	/* 0xb0b: cmp    dx,bp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBP, X86_WIDTH_16);
x86_l_b0e:
	/* 0xb0e: jne    b4e <tail_nodeport_nat_ingress_ipv4+0xb4e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb0e, 0xb4e, x86_l_b4e);
x86_l_b10:
	/* 0xb10: test   r12w,r12w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_16);
x86_l_b14:
	/* 0xb14: je     be9 <tail_nodeport_nat_ingress_ipv4+0xbe9> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb14, 0xbe9, x86_l_be9);
x86_l_b1a:
	/* 0xb1a: movzx  eax,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_b1e:
	/* 0xb1e: mov    esi,DWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_b22:
	/* 0xb22: add    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_b24:
	/* 0xb24: or     r8d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 16ULL);
x86_l_b28:
	/* 0xb28: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_b2d:
	/* 0xb2d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_b30:
	/* 0xb30: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b32:
	/* 0xb32: mov    ecx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_32);
x86_l_b35:
	/* 0xb35: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b37:
	/* 0xb37: movabs r10,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_64, 2199023255552ULL);
x86_l_b41:
	/* 0xb41: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b43:
	/* 0xb43: jns    c13 <tail_nodeport_nat_ingress_ipv4+0xc13> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xb43, 0xc13, x86_l_c13);
x86_l_b49:
	/* 0xb49: jmp    f13 <tail_nodeport_nat_ingress_ipv4+0xf13> */
	X86_SIM_X86_JMP(0xb49, 0xf13, x86_l_f13);
x86_l_b4e:
	/* 0xb4e: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_b51:
	/* 0xb51: je     b6c <tail_nodeport_nat_ingress_ipv4+0xb6c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb51, 0xb6c, x86_l_b6c);
x86_l_b53:
	/* 0xb53: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_b56:
	/* 0xb56: je     b6c <tail_nodeport_nat_ingress_ipv4+0xb6c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb56, 0xb6c, x86_l_b6c);
x86_l_b58:
	/* 0xb58: mov    r12d,0xffffff72 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967154ULL);
x86_l_b5e:
	/* 0xb5e: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b61:
	/* 0xb61: jne    107b <tail_nodeport_nat_ingress_ipv4+0x107b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb61, 0x107b, x86_l_107b);
x86_l_b67:
	/* 0xb67: mov    r12w,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_16, 2ULL);
x86_l_b6c:
	/* 0xb6c: mov    DWORD PTR [rsp+0x20],r8d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b71:
	/* 0xb71: mov    WORD PTR [rsp+0x8],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b76:
	/* 0xb76: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_b7b:
	/* 0xb7b: mov    esi,DWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_b82:
	/* 0xb82: mov    ebp,DWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_b86:
	/* 0xb86: add    esi,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_b88:
	/* 0xb88: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b8d:
	/* 0xb8d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_b90:
	/* 0xb90: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_b95:
	/* 0xb95: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b98:
	/* 0xb98: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b9a:
	/* 0xb9a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b9c:
	/* 0xb9c: js     106d <tail_nodeport_nat_ingress_ipv4+0x106d> */
	X86_SIM_X86_JCC(X86_CC_S, 0xb9c, 0x106d, x86_l_106d);
x86_l_ba2:
	/* 0xba2: movzx  ecx,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_ba7:
	/* 0xba7: movzx  esi,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_bab:
	/* 0xbab: add    esi,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_bad:
	/* 0xbad: mov    r8d,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_bb2:
	/* 0xbb2: or     r8d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_bb6:
	/* 0xbb6: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_bbb:
	/* 0xbbb: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_bbe:
	/* 0xbbe: mov    edx,DWORD PTR [rsp+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_bc2:
	/* 0xbc2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bc4:
	/* 0xbc4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_bc6:
	/* 0xbc6: js     f13 <tail_nodeport_nat_ingress_ipv4+0xf13> */
	X86_SIM_X86_JCC(X86_CC_S, 0xbc6, 0xf13, x86_l_f13);
x86_l_bcc:
	/* 0xbcc: cmp    r13d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 1ULL);
x86_l_bd0:
	/* 0xbd0: movabs r10,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_64, 2199023255552ULL);
x86_l_bda:
	/* 0xbda: mov    ecx,DWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_bde:
	/* 0xbde: mov    r8d,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_be3:
	/* 0xbe3: jne    b10 <tail_nodeport_nat_ingress_ipv4+0xb10> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xbe3, 0xb10, x86_l_b10);
x86_l_be9:
	/* 0xbe9: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_beb:
	/* 0xbeb: je     c13 <tail_nodeport_nat_ingress_ipv4+0xc13> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbeb, 0xc13, x86_l_c13);
x86_l_bed:
	/* 0xbed: add    r15b,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_8, X86_ALU_ADD, 16ULL);
x86_l_bf1:
	/* 0xbf1: movzx  esi,r15b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_R15, X86_WIDTH_32, X86_WIDTH_8);
x86_l_bf5:
	/* 0xbf5: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_bfa:
	/* 0xbfa: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_bfd:
	/* 0xbfd: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bff:
	/* 0xbff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c01:
	/* 0xc01: movabs r10,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_64, 2199023255552ULL);
x86_l_c0b:
	/* 0xc0b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c0d:
	/* 0xc0d: js     f13 <tail_nodeport_nat_ingress_ipv4+0xf13> */
	X86_SIM_X86_JCC(X86_CC_S, 0xc0d, 0xf13, x86_l_f13);
x86_l_c13:
	/* 0xc13: mov    eax,0xfffff0ff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294963455ULL);
x86_l_c18:
	/* 0xc18: and    eax,DWORD PTR [rbx+0xa8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 168ULL);
x86_l_c1e:
	/* 0xc1e: or     eax,0x300 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 768ULL);
x86_l_c23:
	/* 0xc23: mov    DWORD PTR [rbx+0xa8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_c29:
	/* 0xc29: mov    QWORD PTR [rsp+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_c35:
	/* 0xc35: mov    DWORD PTR [rsp+0xe0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 962072674304ULL);
x86_l_c40:
	/* 0xc40: mov    QWORD PTR [rsp+0xd8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 927712935936ULL);
x86_l_c4c:
	/* 0xc4c: mov    QWORD PTR [rsp+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_c58:
	/* 0xc58: mov    QWORD PTR [rsp+0xc8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 858993459200ULL);
x86_l_c64:
	/* 0xc64: mov    QWORD PTR [rsp+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_c70:
	/* 0xc70: mov    QWORD PTR [rsp+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_c7c:
	/* 0xc7c: mov    QWORD PTR [rsp+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_c88:
	/* 0xc88: mov    QWORD PTR [rsp+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_c94:
	/* 0xc94: mov    BYTE PTR [rsp+0xa0],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 687194767362ULL);
x86_l_c9c:
	/* 0xc9c: mov    rax,QWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ca0:
	/* 0xca0: mov    ecx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 0ULL);
x86_l_ca5:
	/* 0xca5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ca8:
	/* 0xca8: je     cb0 <tail_nodeport_nat_ingress_ipv4+0xcb0> */
	X86_SIM_X86_JCC(X86_CC_E, 0xca8, 0xcb0, x86_l_cb0);
x86_l_caa:
	/* 0xcaa: mov    ecx,DWORD PTR [rax+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_cb0:
	/* 0xcb0: mov    DWORD PTR [rsp+0xa8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_cb7:
	/* 0xcb7: mov    WORD PTR [rsp+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_cbe:
	/* 0xcbe: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_cc6:
	/* 0xcc6: mov    rax,QWORD PTR [rip+0x3250] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_security_label)));
x86_l_ccd:
	/* 0xccd: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ccf:
	/* 0xccf: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_cd2:
	/* 0xcd2: sub    eax,DWORD PTR [rbx+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_cd5:
	/* 0xcd5: cmp    eax,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 34ULL);
x86_l_cd8:
	/* 0xcd8: mov    r14d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_cdd:
	/* 0xcdd: jae    cec <tail_nodeport_nat_ingress_ipv4+0xcec> */
	X86_SIM_X86_JCC(X86_CC_AE, 0xcdd, 0xcec, x86_l_cec);
x86_l_cdf:
	/* 0xcdf: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ce1:
	/* 0xce1: mov    r12d,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967162ULL);
x86_l_ce7:
	/* 0xce7: jmp    10bc <tail_nodeport_nat_ingress_ipv4+0x10bc> */
	X86_SIM_X86_JMP(0xce7, 0x10bc, x86_l_10bc);
x86_l_cec:
	/* 0xcec: mov    rdx,QWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_cf3:
	/* 0xcf3: movzx  ecx,WORD PTR [rdx+0x12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18ULL);
x86_l_cf7:
	/* 0xcf7: movzx  eax,BYTE PTR [rdx+0x17] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 23ULL);
x86_l_cfb:
	/* 0xcfb: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_cfe:
	/* 0xcfe: shl    rsi,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_d02:
	/* 0xd02: or     rsi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_d05:
	/* 0xd05: movzx  ecx,WORD PTR [rdx+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 20ULL);
x86_l_d09:
	/* 0xd09: mov    rdi,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSI, X86_WIDTH_64);
x86_l_d0c:
	/* 0xd0c: movabs r9,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_64, 1099511627776ULL);
x86_l_d16:
	/* 0xd16: or     rdi,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R9, X86_WIDTH_64, X86_ALU_OR);
x86_l_d19:
	/* 0xd19: test   ecx,0xff3f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_32, 65343ULL);
x86_l_d1f:
	/* 0xd1f: cmove  rdi,rsi */
	X86_SIM_L_EXEC_CMOV(X86_RDI, X86_RSI, X86_WIDTH_64, X86_CC_E);
x86_l_d23:
	/* 0xd23: mov    r15,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDI, X86_WIDTH_64);
x86_l_d26:
	/* 0xd26: or     r15,r10 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R10, X86_WIDTH_64, X86_ALU_OR);
x86_l_d29:
	/* 0xd29: test   ecx,0xff1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_32, 65311ULL);
x86_l_d2f:
	/* 0xd2f: cmove  r15,rdi */
	X86_SIM_L_EXEC_CMOV(X86_R15, X86_RDI, X86_WIDTH_64, X86_CC_E);
x86_l_d33:
	/* 0xd33: mov    esi,DWORD PTR [rdx+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_d36:
	/* 0xd36: mov    BYTE PTR [rsp+0x34],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_d3a:
	/* 0xd3a: mov    ecx,DWORD PTR [rdx+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_d3d:
	/* 0xd3d: mov    DWORD PTR [rsp+0x28],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_d41:
	/* 0xd41: mov    edx,DWORD PTR [rdx+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_d44:
	/* 0xd44: mov    DWORD PTR [rsp+0x2c],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_d48:
	/* 0xd48: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_d4b:
	/* 0xd4b: je     d56 <tail_nodeport_nat_ingress_ipv4+0xd56> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd4b, 0xd56, x86_l_d56);
x86_l_d4d:
	/* 0xd4d: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_d50:
	/* 0xd50: jne    1094 <tail_nodeport_nat_ingress_ipv4+0x1094> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xd50, 0x1094, x86_l_1094);
x86_l_d56:
	/* 0xd56: and    esi,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_d59:
	/* 0xd59: lea    eax,[rsi*4+0xe] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 14ULL);
x86_l_d60:
	/* 0xd60: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_d65:
	/* 0xd65: lea    r12,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d6a:
	/* 0xd6a: mov    rbp,QWORD PTR [rip+0x3250] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBP, (void *)(long)(((__u64)(long)&__config_enable_ipv4_fragments)));
x86_l_d71:
	/* 0xd71: cmp    BYTE PTR [rbp+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d75:
	/* 0xd75: je     e4d <tail_nodeport_nat_ingress_ipv4+0xe4d> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd75, 0xe4d, x86_l_e4d);
x86_l_d7b:
	/* 0xd7b: mov    DWORD PTR [rsp+0x60],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_d7f:
	/* 0xd7f: mov    DWORD PTR [rsp+0x64],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 100ULL);
x86_l_d83:
	/* 0xd83: mov    WORD PTR [rsp+0x68],r15w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_d89:
	/* 0xd89: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_d8c:
	/* 0xd8c: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_d90:
	/* 0xd90: mov    BYTE PTR [rsp+0x6a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 106ULL);
x86_l_d94:
	/* 0xd94: mov    BYTE PTR [rsp+0x6b],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 459561500672ULL);
x86_l_d99:
	/* 0xd99: mov    r13,r10 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R10, X86_WIDTH_64);
x86_l_d9c:
	/* 0xd9c: test   r15,r10 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R10, X86_WIDTH_64);
x86_l_d9f:
	/* 0xd9f: jne    1a36 <tail_nodeport_nat_ingress_ipv4+0x1a36> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xd9f, 0x1a36, x86_l_1a36);
x86_l_da5:
	/* 0xda5: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_daa:
	/* 0xdaa: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_dad:
	/* 0xdad: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_db2:
	/* 0xdb2: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_db5:
	/* 0xdb5: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_dba:
	/* 0xdba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dbc:
	/* 0xdbc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_dbe:
	/* 0xdbe: js     e8a <tail_nodeport_nat_ingress_ipv4+0xe8a> */
	X86_SIM_X86_JCC(X86_CC_S, 0xdbe, 0xe8a, x86_l_e8a);
x86_l_dc4:
	/* 0xdc4: movabs rax,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 1099511627776ULL);
x86_l_dce:
	/* 0xdce: test   r15,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_dd1:
	/* 0xdd1: je     e74 <tail_nodeport_nat_ingress_ipv4+0xe74> */
	X86_SIM_X86_JCC(X86_CC_E, 0xdd1, 0xe74, x86_l_e74);
x86_l_dd7:
	/* 0xdd7: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_ddc:
	/* 0xddc: mov    rdi,QWORD PTR [rip+0x3250] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv4_frag_datagrams)));
x86_l_de3:
	/* 0xde3: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_de8:
	/* 0xde8: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_deb:
	/* 0xdeb: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ded:
	/* 0xded: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_def:
	/* 0xdef: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_df1:
	/* 0xdf1: je     e74 <tail_nodeport_nat_ingress_ipv4+0xe74> */
	X86_SIM_X86_JCC(X86_CC_E, 0xdf1, 0xe74, x86_l_e74);
x86_l_df7:
	/* 0xdf7: mov    r12d,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R14, X86_WIDTH_32);
x86_l_dfa:
	/* 0xdfa: mov    r14d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_dfe:
	/* 0xdfe: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_e07:
	/* 0xe07: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_e10:
	/* 0xe10: movabs rax,0x6b0085010a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 459570217226ULL);
x86_l_e1a:
	/* 0xe1a: add    rax,0x100 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 256ULL);
x86_l_e20:
	/* 0xe20: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_e25:
	/* 0xe25: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e2a:
	/* 0xe2a: mov    rdi,QWORD PTR [rip+0x324c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_e31:
	/* 0xe31: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_e36:
	/* 0xe36: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e38:
	/* 0xe38: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e3b:
	/* 0xe3b: je     1b78 <tail_nodeport_nat_ingress_ipv4+0x1b78> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe3b, 0x1b78, x86_l_1b78);
x86_l_e41:
	/* 0xe41: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_e44:
	/* 0xe44: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_e48:
	/* 0xe48: mov    r14d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R12, X86_WIDTH_32);
x86_l_e4b:
	/* 0xe4b: jmp    e74 <tail_nodeport_nat_ingress_ipv4+0xe74> */
	X86_SIM_X86_JMP(0xe4b, 0xe74, x86_l_e74);
x86_l_e4d:
	/* 0xe4d: test   r15,r10 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R10, X86_WIDTH_64);
x86_l_e50:
	/* 0xe50: jne    1a5d <tail_nodeport_nat_ingress_ipv4+0x1a5d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe50, 0x1a5d, x86_l_1a5d);
x86_l_e56:
	/* 0xe56: mov    r13,r10 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R10, X86_WIDTH_64);
x86_l_e59:
	/* 0xe59: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_e5e:
	/* 0xe5e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_e61:
	/* 0xe61: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_e66:
	/* 0xe66: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_e69:
	/* 0xe69: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_e6e:
	/* 0xe6e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e70:
	/* 0xe70: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_e72:
	/* 0xe72: js     e8a <tail_nodeport_nat_ingress_ipv4+0xe8a> */
	X86_SIM_X86_JCC(X86_CC_S, 0xe72, 0xe8a, x86_l_e8a);
x86_l_e74:
	/* 0xe74: movzx  eax,BYTE PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 52ULL);
x86_l_e79:
	/* 0xe79: mov    BYTE PTR [rsp+0x20],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e7d:
	/* 0xe7d: cmp    al,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 6ULL);
x86_l_e7f:
	/* 0xe7f: jne    e97 <tail_nodeport_nat_ingress_ipv4+0xe97> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe7f, 0xe97, x86_l_e97);
x86_l_e81:
	/* 0xe81: mov    r12,QWORD PTR [rip+0x324c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&cilium_ct4_global)));
x86_l_e88:
	/* 0xe88: jmp    e9e <tail_nodeport_nat_ingress_ipv4+0xe9e> */
	X86_SIM_X86_JMP(0xe88, 0xe9e, x86_l_e9e);
x86_l_e8a:
	/* 0xe8a: mov    r12d,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967161ULL);
x86_l_e90:
	/* 0xe90: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e92:
	/* 0xe92: jmp    10bc <tail_nodeport_nat_ingress_ipv4+0x10bc> */
	X86_SIM_X86_JMP(0xe92, 0x10bc, x86_l_10bc);
x86_l_e97:
	/* 0xe97: mov    r12,QWORD PTR [rip+0x324c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&cilium_ct_any4_global)));
x86_l_e9e:
	/* 0xe9e: mov    BYTE PTR [rsp+0x35],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 227633266688ULL);
x86_l_ea3:
	/* 0xea3: mov    DWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_eab:
	/* 0xeab: cmp    BYTE PTR [rbp+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_eaf:
	/* 0xeaf: je     11af <tail_nodeport_nat_ingress_ipv4+0x11af> */
	X86_SIM_X86_JCC(X86_CC_E, 0xeaf, 0x11af, x86_l_11af);
x86_l_eb5:
	/* 0xeb5: and    QWORD PTR [rsp+0x88],r15 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 136ULL);
x86_l_ebd:
	/* 0xebd: je     11af <tail_nodeport_nat_ingress_ipv4+0x11af> */
	X86_SIM_X86_JCC(X86_CC_E, 0xebd, 0x11af, x86_l_11af);
x86_l_ec3:
	/* 0xec3: mov    ebp,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R14, X86_WIDTH_32);
x86_l_ec6:
	/* 0xec6: mov    r14d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_eca:
	/* 0xeca: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_ed3:
	/* 0xed3: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_edc:
	/* 0xedc: movabs rax,0x6c03a50109 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 463917613321ULL);
x86_l_ee6:
	/* 0xee6: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_eeb:
	/* 0xeeb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ef0:
	/* 0xef0: mov    rdi,QWORD PTR [rip+0x324c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_ef7:
	/* 0xef7: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_efc:
	/* 0xefc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_efe:
	/* 0xefe: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f01:
	/* 0xf01: je     1184 <tail_nodeport_nat_ingress_ipv4+0x1184> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf01, 0x1184, x86_l_1184);
x86_l_f07:
	/* 0xf07: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_f0a:
	/* 0xf0a: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_f0e:
	/* 0xf0e: jmp    11ac <tail_nodeport_nat_ingress_ipv4+0x11ac> */
	X86_SIM_X86_JMP(0xf0e, 0x11ac, x86_l_11ac);
x86_l_f13:
	/* 0xf13: mov    r12d,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967142ULL);
x86_l_f19:
	/* 0xf19: jmp    107b <tail_nodeport_nat_ingress_ipv4+0x107b> */
	X86_SIM_X86_JMP(0xf19, 0x107b, x86_l_107b);
x86_l_f1e:
	/* 0xf1e: mov    WORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_f25:
	/* 0xf25: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_f2a:
	/* 0xf2a: lea    esi,[r13+0x6] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_f2e:
	/* 0xf2e: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_f33:
	/* 0xf33: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_f36:
	/* 0xf36: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_f3b:
	/* 0xf3b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f3d:
	/* 0xf3d: cmp    WORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_f43:
	/* 0xf43: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_f46:
	/* 0xf46: mov    sil,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_8, 1ULL);
x86_l_f49:
	/* 0xf49: mov    r12d,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967162ULL);
x86_l_f4f:
	/* 0xf4f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_f51:
	/* 0xf51: jns    f5b <tail_nodeport_nat_ingress_ipv4+0xf5b> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xf51, 0xf5b, x86_l_f5b);
x86_l_f53:
	/* 0xf53: jmp    107b <tail_nodeport_nat_ingress_ipv4+0x107b> */
	X86_SIM_X86_JMP(0xf53, 0x107b, x86_l_107b);
x86_l_f58:
	/* 0xf58: mov    sil,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_8, 1ULL);
x86_l_f5b:
	/* 0xf5b: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f5f:
	/* 0xf5f: mov    r12d,DWORD PTR [r14+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f63:
	/* 0xf63: movzx  edi,WORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_f68:
	/* 0xf68: movzx  r8d,WORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_f6d:
	/* 0xf6d: test   sil,sil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_8);
x86_l_f70:
	/* 0xf70: mov    QWORD PTR [rsp+0x98],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_f78:
	/* 0xf78: je     f8e <tail_nodeport_nat_ingress_ipv4+0xf8e> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf78, 0xf8e, x86_l_f8e);
x86_l_f7a:
	/* 0xf7a: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_f7c:
	/* 0xf7c: je     f8e <tail_nodeport_nat_ingress_ipv4+0xf8e> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf7c, 0xf8e, x86_l_f8e);
x86_l_f7e:
	/* 0xf7e: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f80:
	/* 0xf80: cmp    eax,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_f83:
	/* 0xf83: je     fa3 <tail_nodeport_nat_ingress_ipv4+0xfa3> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf83, 0xfa3, x86_l_fa3);
x86_l_f85:
	/* 0xf85: mov    edx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_32);
x86_l_f88:
	/* 0xf88: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_f8a:
	/* 0xf8a: add    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_f8c:
	/* 0xf8c: jmp    fa0 <tail_nodeport_nat_ingress_ipv4+0xfa0> */
	X86_SIM_X86_JMP(0xf8c, 0xfa0, x86_l_fa0);
x86_l_f8e:
	/* 0xf8e: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f90:
	/* 0xf90: cmp    di,r8w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_R8, X86_WIDTH_16);
x86_l_f94:
	/* 0xf94: je     fa3 <tail_nodeport_nat_ingress_ipv4+0xfa3> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf94, 0xfa3, x86_l_fa3);
x86_l_f96:
	/* 0xf96: movzx  ecx,r8w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R8, X86_WIDTH_32, X86_WIDTH_16);
x86_l_f9a:
	/* 0xf9a: mov    edx,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_32);
x86_l_f9c:
	/* 0xf9c: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_f9e:
	/* 0xf9e: add    edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_fa0:
	/* 0xfa0: adc    edx,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_fa3:
	/* 0xfa3: movzx  ecx,BYTE PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 20ULL);
x86_l_fa8:
	/* 0xfa8: mov    DWORD PTR [rsp+0x48],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_fad:
	/* 0xfad: cmp    eax,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_fb0:
	/* 0xfb0: jne    fd9 <tail_nodeport_nat_ingress_ipv4+0xfd9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xfb0, 0xfd9, x86_l_fd9);
x86_l_fb2:
	/* 0xfb2: cmp    di,r8w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_R8, X86_WIDTH_16);
x86_l_fb6:
	/* 0xfb6: jne    fd9 <tail_nodeport_nat_ingress_ipv4+0xfd9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xfb6, 0xfd9, x86_l_fd9);
x86_l_fb8:
	/* 0xfb8: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_fba:
	/* 0xfba: mov    DWORD PTR [rsp+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_fc5:
	/* 0xfc5: movabs r10,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_64, 2199023255552ULL);
x86_l_fcf:
	/* 0xfcf: mov    r8,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_fd4:
	/* 0xfd4: jmp    a2f <tail_nodeport_nat_ingress_ipv4+0xa2f> */
	X86_SIM_X86_JMP(0xfd4, 0xa2f, x86_l_a2f);
x86_l_fd9:
	/* 0xfd9: mov    DWORD PTR [rsp+0x78],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_fdd:
	/* 0xfdd: mov    r13d,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R8, X86_WIDTH_32);
x86_l_fe0:
	/* 0xfe0: mov    DWORD PTR [rsp+0x70],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_fe4:
	/* 0xfe4: mov    BYTE PTR [rsp+0x80],sil */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_fec:
	/* 0xfec: mov    DWORD PTR [rsp+0x38],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_ff0:
	/* 0xff0: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_ff2:
	/* 0xff2: add    r12d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_ff5:
	/* 0xff5: adc    r12d,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_ff9:
	/* 0xff9: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_ffe:
	/* 0xffe: lea    esi,[rbp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1001:
	/* 0x1001: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1006:
	/* 0x1006: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1009:
	/* 0x1009: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_100e:
	/* 0x100e: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1011:
	/* 0x1011: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1013:
	/* 0x1013: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1015:
	/* 0x1015: js     106d <tail_nodeport_nat_ingress_ipv4+0x106d> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1015, 0x106d, x86_l_106d);
x86_l_1017:
	/* 0x1017: add    ebp,0xa */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 10ULL);
x86_l_101a:
	/* 0x101a: mov    DWORD PTR [rsp+0x94],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_1025:
	/* 0x1025: mov    eax,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_102a:
	/* 0x102a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_102d:
	/* 0x102d: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_102f:
	/* 0x102f: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1031:
	/* 0x1031: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_1034:
	/* 0x1034: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1037:
	/* 0x1037: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1039:
	/* 0x1039: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_103b:
	/* 0x103b: js     1075 <tail_nodeport_nat_ingress_ipv4+0x1075> */
	X86_SIM_X86_JCC(X86_CC_S, 0x103b, 0x1075, x86_l_1075);
x86_l_103d:
	/* 0x103d: mov    ecx,DWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1041:
	/* 0x1041: cmp    ecx,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 58ULL);
x86_l_1044:
	/* 0x1044: je     1435 <tail_nodeport_nat_ingress_ipv4+0x1435> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1044, 0x1435, x86_l_1435);
x86_l_104a:
	/* 0x104a: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_104d:
	/* 0x104d: mov    edx,DWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1051:
	/* 0x1051: mov    eax,DWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1055:
	/* 0x1055: je     1424 <tail_nodeport_nat_ingress_ipv4+0x1424> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1055, 0x1424, x86_l_1424);
x86_l_105b:
	/* 0x105b: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_105e:
	/* 0x105e: jne    1443 <tail_nodeport_nat_ingress_ipv4+0x1443> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x105e, 0x1443, x86_l_1443);
x86_l_1064:
	/* 0x1064: mov    bp,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_16, 16ULL);
x86_l_1068:
	/* 0x1068: jmp    1445 <tail_nodeport_nat_ingress_ipv4+0x1445> */
	X86_SIM_X86_JMP(0x1068, 0x1445, x86_l_1445);
x86_l_106d:
	/* 0x106d: mov    r12d,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967155ULL);
x86_l_1073:
	/* 0x1073: jmp    107b <tail_nodeport_nat_ingress_ipv4+0x107b> */
	X86_SIM_X86_JMP(0x1073, 0x107b, x86_l_107b);
x86_l_1075:
	/* 0x1075: mov    r12d,0xffffff67 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967143ULL);
x86_l_107b:
	/* 0x107b: mov    r14d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1080:
	/* 0x1080: cmp    r12d,0xffffff53 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4294967123ULL);
x86_l_1087:
	/* 0x1087: je     1094 <tail_nodeport_nat_ingress_ipv4+0x1094> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1087, 0x1094, x86_l_1094);
x86_l_1089:
	/* 0x1089: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_108b:
	/* 0x108b: cmp    r12d,0xffffff59 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4294967129ULL);
x86_l_1092:
	/* 0x1092: jne    10bc <tail_nodeport_nat_ingress_ipv4+0x10bc> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1092, 0x10bc, x86_l_10bc);
x86_l_1094:
	/* 0x1094: or     BYTE PTR [rbx+0x86],0x4 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RBX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 575525617668ULL);
x86_l_109b:
	/* 0x109b: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_10a0:
	/* 0x10a0: mov    rsi,QWORD PTR [rip+0x324c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_10a7:
	/* 0x10a7: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_10aa:
	/* 0x10aa: mov    edx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_10af:
	/* 0x10af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10b1:
	/* 0x10b1: mov    r12d,0xffffff74 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967156ULL);
x86_l_10b7:
	/* 0x10b7: mov    ebp,0x700 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1792ULL);
x86_l_10bc:
	/* 0x10bc: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_10bf:
	/* 0x10bf: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_10c1:
	/* 0x10c1: cmovs  eax,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_R12, X86_WIDTH_32, X86_CC_S);
x86_l_10c5:
	/* 0x10c5: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_10c8:
	/* 0x10c8: or     eax,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_32, X86_ALU_OR);
x86_l_10ca:
	/* 0x10ca: mov    DWORD PTR [rbx+0x28],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_10ce:
	/* 0x10ce: mov    DWORD PTR [rbx+0x2c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561024ULL);
x86_l_10d5:
	/* 0x10d5: mov    DWORD PTR [rbx+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_10d8:
	/* 0x10d8: movabs rcx,0x9d9680200000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 709712774086787072ULL);
x86_l_10e2:
	/* 0x10e2: mov    QWORD PTR [rbx+0x34],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_10e6:
	/* 0x10e6: mov    r14d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_10ea:
	/* 0x10ea: movabs rcx,0x6809d90100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 446841815296ULL);
x86_l_10f4:
	/* 0x10f4: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10f9:
	/* 0x10f9: mov    BYTE PTR [rsp+0x8],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10fd:
	/* 0x10fd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1102:
	/* 0x1102: mov    rdi,QWORD PTR [rip+0x324c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1109:
	/* 0x1109: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_110e:
	/* 0x110e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1110:
	/* 0x1110: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1113:
	/* 0x1113: je     111e <tail_nodeport_nat_ingress_ipv4+0x111e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1113, 0x111e, x86_l_111e);
x86_l_1115:
	/* 0x1115: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1118:
	/* 0x1118: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_111c:
	/* 0x111c: jmp    114f <tail_nodeport_nat_ingress_ipv4+0x114f> */
	X86_SIM_X86_JMP(0x111c, 0x114f, x86_l_114f);
x86_l_111e:
	/* 0x111e: mov    QWORD PTR [rsp+0xa0],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767361ULL);
x86_l_112a:
	/* 0x112a: mov    QWORD PTR [rsp+0xa8],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1132:
	/* 0x1132: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1137:
	/* 0x1137: mov    rdi,QWORD PTR [rip+0x324c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_113e:
	/* 0x113e: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1143:
	/* 0x1143: lea    rdx,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_114b:
	/* 0x114b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_114d:
	/* 0x114d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_114f:
	/* 0x114f: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1154:
	/* 0x1154: mov    rsi,QWORD PTR [rip+0x324c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_115b:
	/* 0x115b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_115e:
	/* 0x115e: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_1163:
	/* 0x1163: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1165:
	/* 0x1165: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_116b:
	/* 0x116b: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_116e:
	/* 0x116e: add    rsp,0xe8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 232ULL);
x86_l_1175:
	/* 0x1175: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_1176:
	/* 0x1176: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_1178:
	/* 0x1178: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_117a:
	/* 0x117a: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_117c:
	/* 0x117c: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_117e:
	/* 0x117e: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_117f:
	/* 0x117f: jmp    1c89 <tail_nodeport_nat_ingress_ipv4+0x1c89> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_1184:
	/* 0x1184: mov    QWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_118d:
	/* 0x118d: mov    QWORD PTR [rsp+0x10],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1192:
	/* 0x1192: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1197:
	/* 0x1197: mov    rdi,QWORD PTR [rip+0x3248] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_119e:
	/* 0x119e: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_11a3:
	/* 0x11a3: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11a8:
	/* 0x11a8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11aa:
	/* 0x11aa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11ac:
	/* 0x11ac: mov    r14d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RBP, X86_WIDTH_32);
x86_l_11af:
	/* 0x11af: cmp    BYTE PTR [rsp+0x20],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 137438953478ULL);
x86_l_11b4:
	/* 0x11b4: mov    DWORD PTR [rsp+0x4],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_11b9:
	/* 0x11b9: jne    1210 <tail_nodeport_nat_ingress_ipv4+0x1210> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x11b9, 0x1210, x86_l_1210);
x86_l_11bb:
	/* 0x11bb: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_11be:
	/* 0x11be: and    rax,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_11c1:
	/* 0x11c1: jne    1210 <tail_nodeport_nat_ingress_ipv4+0x1210> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x11c1, 0x1210, x86_l_1210);
x86_l_11c3:
	/* 0x11c3: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_11c8:
	/* 0x11c8: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_11cd:
	/* 0x11cd: lea    esi,[rcx+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_11d0:
	/* 0x11d0: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_11d5:
	/* 0x11d5: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_11d8:
	/* 0x11d8: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_11dd:
	/* 0x11dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11df:
	/* 0x11df: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_11e1:
	/* 0x11e1: js     1094 <tail_nodeport_nat_ingress_ipv4+0x1094> */
	X86_SIM_X86_JCC(X86_CC_S, 0x11e1, 0x1094, x86_l_1094);
x86_l_11e7:
	/* 0x11e7: mov    r13d,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_11ec:
	/* 0x11ec: mov    eax,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_11ef:
	/* 0x11ef: and    eax,0x1200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4608ULL);
x86_l_11f4:
	/* 0x11f4: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11f6:
	/* 0x11f6: cmp    eax,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 512ULL);
x86_l_11fb:
	/* 0x11fb: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_11fe:
	/* 0x11fe: test   r13d,0x500 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R13, X86_WIDTH_32, 1280ULL);
x86_l_1205:
	/* 0x1205: jne    1b6e <tail_nodeport_nat_ingress_ipv4+0x1b6e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1205, 0x1b6e, x86_l_1b6e);
x86_l_120b:
	/* 0x120b: mov    bpl,al */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_8);
x86_l_120e:
	/* 0x120e: jmp    1217 <tail_nodeport_nat_ingress_ipv4+0x1217> */
	X86_SIM_X86_JMP(0x120e, 0x1217, x86_l_1217);
x86_l_1210:
	/* 0x1210: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1212:
	/* 0x1212: mov    r13d,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1217:
	/* 0x1217: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_121c:
	/* 0x121c: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1221:
	/* 0x1221: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1224:
	/* 0x1224: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1226:
	/* 0x1226: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1229:
	/* 0x1229: je     1c76 <tail_nodeport_nat_ingress_ipv4+0x1c76> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1229, 0x1c76, x86_l_1c76);
x86_l_122f:
	/* 0x122f: movzx  ecx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_1233:
	/* 0x1233: test   cl,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_1236:
	/* 0x1236: je     1c76 <tail_nodeport_nat_ingress_ipv4+0x1c76> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1236, 0x1c76, x86_l_1c76);
x86_l_123c:
	/* 0x123c: cmp    WORD PTR [rax+0x26],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 163208757248ULL);
x86_l_1241:
	/* 0x1241: je     1c76 <tail_nodeport_nat_ingress_ipv4+0x1c76> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1241, 0x1c76, x86_l_1c76);
x86_l_1247:
	/* 0x1247: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_1249:
	/* 0x1249: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_124b:
	/* 0x124b: test   dl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_8, 3ULL);
x86_l_124e:
	/* 0x124e: je     1363 <tail_nodeport_nat_ingress_ipv4+0x1363> */
	X86_SIM_X86_JCC(X86_CC_E, 0x124e, 0x1363, x86_l_1363);
x86_l_1254:
	/* 0x1254: mov    rsi,QWORD PTR [rip+0x3248] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_125b:
	/* 0x125b: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_125e:
	/* 0x125e: je     127c <tail_nodeport_nat_ingress_ipv4+0x127c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x125e, 0x127c, x86_l_127c);
x86_l_1260:
	/* 0x1260: mov    rdx,QWORD PTR [rip+0x3248] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1267:
	/* 0x1267: imul   r14d,DWORD PTR [rdx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R14, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_126b:
	/* 0x126b: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_126f:
	/* 0x126f: jmp    1282 <tail_nodeport_nat_ingress_ipv4+0x1282> */
	X86_SIM_X86_JMP(0x126f, 0x1282, x86_l_1282);
x86_l_1271:
	/* 0x1271: mov    r12d,0xffffff71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967153ULL);
x86_l_1277:
	/* 0x1277: jmp    107b <tail_nodeport_nat_ingress_ipv4+0x107b> */
	X86_SIM_X86_JMP(0x1277, 0x107b, x86_l_107b);
x86_l_127c:
	/* 0x127c: mov    r14d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 60ULL);
x86_l_1282:
	/* 0x1282: cmp    BYTE PTR [rsp+0x20],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 137438953478ULL);
x86_l_1287:
	/* 0x1287: jne    12c0 <tail_nodeport_nat_ingress_ipv4+0x12c0> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1287, 0x12c0, x86_l_12c0);
x86_l_1289:
	/* 0x1289: mov    edx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_32);
x86_l_128c:
	/* 0x128c: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_128e:
	/* 0x128e: shr    edx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_1291:
	/* 0x1291: and    edx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_1294:
	/* 0x1294: or     ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1296:
	/* 0x1296: mov    WORD PTR [rax+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_129a:
	/* 0x129a: test   cl,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 16ULL);
x86_l_129d:
	/* 0x129d: mov    ecx,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 60ULL);
x86_l_12a2:
	/* 0x12a2: mov    r14d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 21600ULL);
x86_l_12a8:
	/* 0x12a8: cmove  r14d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R14, X86_RCX, X86_WIDTH_32, X86_CC_E);
x86_l_12ac:
	/* 0x12ac: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12af:
	/* 0x12af: je     12c0 <tail_nodeport_nat_ingress_ipv4+0x12c0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12af, 0x12c0, x86_l_12c0);
x86_l_12b1:
	/* 0x12b1: mov    rcx,QWORD PTR [rip+0x3248] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_12b8:
	/* 0x12b8: imul   r14d,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_12bc:
	/* 0x12bc: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_12c0:
	/* 0x12c0: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_12c8:
	/* 0x12c8: mov    r12d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R13, X86_WIDTH_32);
x86_l_12cb:
	/* 0x12cb: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_12cf:
	/* 0x12cf: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12d2:
	/* 0x12d2: je     12e6 <tail_nodeport_nat_ingress_ipv4+0x12e6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12d2, 0x12e6, x86_l_12e6);
x86_l_12d4:
	/* 0x12d4: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_12d9:
	/* 0x12d9: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12db:
	/* 0x12db: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_12dd:
	/* 0x12dd: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_12e0:
	/* 0x12e0: shr    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_12e4:
	/* 0x12e4: jmp    1309 <tail_nodeport_nat_ingress_ipv4+0x1309> */
	X86_SIM_X86_JMP(0x12e4, 0x1309, x86_l_1309);
x86_l_12e6:
	/* 0x12e6: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_12eb:
	/* 0x12eb: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12ed:
	/* 0x12ed: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_12ef:
	/* 0x12ef: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_12f3:
	/* 0x12f3: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_12fd:
	/* 0x12fd: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1300:
	/* 0x1300: mulx   rcx,rcx,rcx */
	X86_SIM_L_EXEC_MULX(X86_RCX, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_1305:
	/* 0x1305: shr    rcx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_1309:
	/* 0x1309: add    r14d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_130c:
	/* 0x130c: mov    rax,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1314:
	/* 0x1314: mov    DWORD PTR [rax+0x20],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1318:
	/* 0x1318: movzx  edx,BYTE PTR [rax+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_131c:
	/* 0x131c: mov    esi,DWORD PTR [rax+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_131f:
	/* 0x131f: and    r12b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_1323:
	/* 0x1323: mov    rdi,QWORD PTR [rip+0x3248] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_132a:
	/* 0x132a: cmp    BYTE PTR [rdi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_132d:
	/* 0x132d: je     1340 <tail_nodeport_nat_ingress_ipv4+0x1340> */
	X86_SIM_X86_JCC(X86_CC_E, 0x132d, 0x1340, x86_l_1340);
x86_l_132f:
	/* 0x132f: mov    rdi,QWORD PTR [rip+0x3248] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1336:
	/* 0x1336: mov    edi,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1338:
	/* 0x1338: lea    edi,[rdi+rdi*4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_133b:
	/* 0x133b: shr    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_133e:
	/* 0x133e: jmp    1345 <tail_nodeport_nat_ingress_ipv4+0x1345> */
	X86_SIM_X86_JMP(0x133e, 0x1345, x86_l_1345);
x86_l_1340:
	/* 0x1340: mov    edi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 5ULL);
x86_l_1345:
	/* 0x1345: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1347:
	/* 0x1347: or     r12b,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_134a:
	/* 0x134a: cmp    edi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RCX, X86_WIDTH_32);
x86_l_134c:
	/* 0x134c: jb     1353 <tail_nodeport_nat_ingress_ipv4+0x1353> */
	X86_SIM_X86_JCC(X86_CC_B, 0x134c, 0x1353, x86_l_1353);
x86_l_134e:
	/* 0x134e: cmp    dl,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_8);
x86_l_1351:
	/* 0x1351: je     1363 <tail_nodeport_nat_ingress_ipv4+0x1363> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1351, 0x1363, x86_l_1363);
x86_l_1353:
	/* 0x1353: mov    BYTE PTR [rax+0x2b],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_1357:
	/* 0x1357: mov    DWORD PTR [rax+0x34],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_135a:
	/* 0x135a: mov    rcx,QWORD PTR [rip+0x3248] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_1361:
	/* 0x1361: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1363:
	/* 0x1363: mov    rcx,QWORD PTR [rip+0x3248] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_136a:
	/* 0x136a: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_136d:
	/* 0x136d: je     137c <tail_nodeport_nat_ingress_ipv4+0x137c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x136d, 0x137c, x86_l_137c);
x86_l_136f:
	/* 0x136f: inc QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 16ULL);
x86_l_1374:
	/* 0x1374: mov    ecx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1377:
	/* 0x1377: add QWORD PTR [rax+0x18],rcx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_137c:
	/* 0x137c: cmp    ebp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_137f:
	/* 0x137f: mov    r14d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1384:
	/* 0x1384: je     13d2 <tail_nodeport_nat_ingress_ipv4+0x13d2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1384, 0x13d2, x86_l_13d2);
x86_l_1386:
	/* 0x1386: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_1389:
	/* 0x1389: jne    1618 <tail_nodeport_nat_ingress_ipv4+0x1618> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1389, 0x1618, x86_l_1618);
x86_l_138f:
	/* 0x138f: movzx  ecx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_1393:
	/* 0x1393: test   cl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_1396:
	/* 0x1396: je     1618 <tail_nodeport_nat_ingress_ipv4+0x1618> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1396, 0x1618, x86_l_1618);
x86_l_139c:
	/* 0x139c: mov    WORD PTR [rax+0x2a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 180388626432ULL);
x86_l_13a2:
	/* 0x13a2: and    ecx,0xffec */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 65516ULL);
x86_l_13a8:
	/* 0x13a8: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_13ab:
	/* 0x13ab: mov    WORD PTR [rax+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_13af:
	/* 0x13af: mov    r15,QWORD PTR [rip+0x3248] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_13b6:
	/* 0x13b6: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13ba:
	/* 0x13ba: je     1bb2 <tail_nodeport_nat_ingress_ipv4+0x1bb2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13ba, 0x1bb2, x86_l_1bb2);
x86_l_13c0:
	/* 0x13c0: mov    rax,QWORD PTR [rip+0x3248] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_13c7:
	/* 0x13c7: imul   ebp,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_13ca:
	/* 0x13ca: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_13cd:
	/* 0x13cd: jmp    1bb7 <tail_nodeport_nat_ingress_ipv4+0x1bb7> */
	X86_SIM_X86_JMP(0x13cd, 0x1bb7, x86_l_1bb7);
x86_l_13d2:
	/* 0x13d2: mov    ecx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_32);
x86_l_13d5:
	/* 0x13d5: shr    ecx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_13d8:
	/* 0x13d8: and    ecx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2ULL);
x86_l_13db:
	/* 0x13db: or     cx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RAX, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 36ULL);
x86_l_13df:
	/* 0x13df: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_13e1:
	/* 0x13e1: or     edx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_OR, 1ULL);
x86_l_13e4:
	/* 0x13e4: mov    WORD PTR [rax+0x24],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_13e8:
	/* 0x13e8: mov    rdx,QWORD PTR [rip+0x3248] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_13ef:
	/* 0x13ef: mov    edx,DWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13f1:
	/* 0x13f1: test   cl,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_13f4:
	/* 0x13f4: je     1618 <tail_nodeport_nat_ingress_ipv4+0x1618> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13f4, 0x1618, x86_l_1618);
x86_l_13fa:
	/* 0x13fa: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_13fd:
	/* 0x13fd: mov    r14,QWORD PTR [rip+0x3248] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1404:
	/* 0x1404: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1408:
	/* 0x1408: je     1579 <tail_nodeport_nat_ingress_ipv4+0x1579> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1408, 0x1579, x86_l_1579);
x86_l_140e:
	/* 0x140e: mov    rax,QWORD PTR [rip+0x3248] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1415:
	/* 0x1415: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1417:
	/* 0x1417: add    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1419:
	/* 0x1419: lea    ebp,[rax+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_141c:
	/* 0x141c: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_141f:
	/* 0x141f: jmp    157e <tail_nodeport_nat_ingress_ipv4+0x157e> */
	X86_SIM_X86_JMP(0x141f, 0x157e, x86_l_157e);
x86_l_1424:
	/* 0x1424: mov    DWORD PTR [rsp+0x94],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 635655159840ULL);
x86_l_142f:
	/* 0x142f: mov    bp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_16, 6ULL);
x86_l_1433:
	/* 0x1433: jmp    1445 <tail_nodeport_nat_ingress_ipv4+0x1445> */
	X86_SIM_X86_JMP(0x1433, 0x1445, x86_l_1445);
x86_l_1435:
	/* 0x1435: mov    bp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_16, 2ULL);
x86_l_1439:
	/* 0x1439: mov    edx,DWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_143d:
	/* 0x143d: mov    eax,DWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1441:
	/* 0x1441: jmp    1445 <tail_nodeport_nat_ingress_ipv4+0x1445> */
	X86_SIM_X86_JMP(0x1441, 0x1445, x86_l_1445);
x86_l_1443:
	/* 0x1443: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1445:
	/* 0x1445: cmp    ax,r13w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R13, X86_WIDTH_16);
x86_l_1449:
	/* 0x1449: jne    1498 <tail_nodeport_nat_ingress_ipv4+0x1498> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1449, 0x1498, x86_l_1498);
x86_l_144b:
	/* 0x144b: test   bp,bp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_16);
x86_l_144e:
	/* 0x144e: je     fb8 <tail_nodeport_nat_ingress_ipv4+0xfb8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x144e, 0xfb8, x86_l_fb8);
x86_l_1454:
	/* 0x1454: movzx  esi,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1457:
	/* 0x1457: add    esi,DWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RSI, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 152ULL);
x86_l_145e:
	/* 0x145e: mov    r8d,DWORD PTR [rsp+0x94] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_1466:
	/* 0x1466: or     r8d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 16ULL);
x86_l_146a:
	/* 0x146a: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_146f:
	/* 0x146f: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1472:
	/* 0x1472: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1474:
	/* 0x1474: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_1477:
	/* 0x1477: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1479:
	/* 0x1479: movzx  ecx,BYTE PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 128ULL);
x86_l_1481:
	/* 0x1481: mov    edx,DWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1485:
	/* 0x1485: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1487:
	/* 0x1487: jns    fb8 <tail_nodeport_nat_ingress_ipv4+0xfb8> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1487, 0xfb8, x86_l_fb8);
x86_l_148d:
	/* 0x148d: mov    r12d,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967142ULL);
x86_l_1493:
	/* 0x1493: jmp    172b <tail_nodeport_nat_ingress_ipv4+0x172b> */
	X86_SIM_X86_JMP(0x1493, 0x172b, x86_l_172b);
x86_l_1498:
	/* 0x1498: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_149b:
	/* 0x149b: mov    DWORD PTR [rsp+0xe4],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 228ULL);
x86_l_14a3:
	/* 0x14a3: je     14bd <tail_nodeport_nat_ingress_ipv4+0x14bd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14a3, 0x14bd, x86_l_14bd);
x86_l_14a5:
	/* 0x14a5: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_14a8:
	/* 0x14a8: je     14bd <tail_nodeport_nat_ingress_ipv4+0x14bd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14a8, 0x14bd, x86_l_14bd);
x86_l_14aa:
	/* 0x14aa: mov    r12d,0xffffff72 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967154ULL);
x86_l_14b0:
	/* 0x14b0: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_14b3:
	/* 0x14b3: jne    107b <tail_nodeport_nat_ingress_ipv4+0x107b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x14b3, 0x107b, x86_l_107b);
x86_l_14b9:
	/* 0x14b9: mov    bp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_16, 2ULL);
x86_l_14bd:
	/* 0x14bd: mov    WORD PTR [rsp+0x7e],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 126ULL);
x86_l_14c3:
	/* 0x14c3: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_14c8:
	/* 0x14c8: mov    r12,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_14d0:
	/* 0x14d0: mov    esi,DWORD PTR [rsp+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_14d4:
	/* 0x14d4: add    esi,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R12, X86_WIDTH_32, X86_ALU_ADD);
x86_l_14d7:
	/* 0x14d7: lea    rdx,[rsp+0x7e] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 126ULL);
x86_l_14dc:
	/* 0x14dc: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_14df:
	/* 0x14df: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_14e4:
	/* 0x14e4: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14e7:
	/* 0x14e7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14e9:
	/* 0x14e9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_14eb:
	/* 0x14eb: js     1560 <tail_nodeport_nat_ingress_ipv4+0x1560> */
	X86_SIM_X86_JCC(X86_CC_S, 0x14eb, 0x1560, x86_l_1560);
x86_l_14ed:
	/* 0x14ed: movzx  ecx,WORD PTR [rsp+0x7e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 126ULL);
x86_l_14f2:
	/* 0x14f2: movzx  esi,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_14f5:
	/* 0x14f5: add    esi,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R12, X86_WIDTH_32, X86_ALU_ADD);
x86_l_14f8:
	/* 0x14f8: mov    r8d,DWORD PTR [rsp+0x94] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_1500:
	/* 0x1500: or     r8d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_1504:
	/* 0x1504: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_1509:
	/* 0x1509: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_150c:
	/* 0x150c: mov    edx,DWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1510:
	/* 0x1510: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1512:
	/* 0x1512: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1514:
	/* 0x1514: js     1719 <tail_nodeport_nat_ingress_ipv4+0x1719> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1514, 0x1719, x86_l_1719);
x86_l_151a:
	/* 0x151a: cmp    DWORD PTR [rsp+0x78],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 515396075521ULL);
x86_l_151f:
	/* 0x151f: mov    edx,DWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1523:
	/* 0x1523: mov    r12d,DWORD PTR [rsp+0xe4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 228ULL);
x86_l_152b:
	/* 0x152b: je     fb8 <tail_nodeport_nat_ingress_ipv4+0xfb8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x152b, 0xfb8, x86_l_fb8);
x86_l_1531:
	/* 0x1531: jmp    144b <tail_nodeport_nat_ingress_ipv4+0x144b> */
	X86_SIM_X86_JMP(0x1531, 0x144b, x86_l_144b);
x86_l_1536:
	/* 0x1536: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_153b:
	/* 0x153b: mov    rdi,QWORD PTR [rip+0x3248] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv4_frag_datagrams)));
x86_l_1542:
	/* 0x1542: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1547:
	/* 0x1547: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1549:
	/* 0x1549: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_154c:
	/* 0x154c: je     1742 <tail_nodeport_nat_ingress_ipv4+0x1742> */
	X86_SIM_X86_JCC(X86_CC_E, 0x154c, 0x1742, x86_l_1742);
x86_l_1552:
	/* 0x1552: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1554:
	/* 0x1554: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1558:
	/* 0x1558: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_155b:
	/* 0x155b: jmp    274 <tail_nodeport_nat_ingress_ipv4+0x274> */
	X86_SIM_X86_JMP(0x155b, 0x274, x86_l_274);
x86_l_1560:
	/* 0x1560: mov    r12d,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967155ULL);
x86_l_1566:
	/* 0x1566: jmp    171f <tail_nodeport_nat_ingress_ipv4+0x171f> */
	X86_SIM_X86_JMP(0x1566, 0x171f, x86_l_171f);
x86_l_156b:
	/* 0x156b: mov    r12d,0xffffff63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967139ULL);
x86_l_1571:
	/* 0x1571: mov    r14d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R13, X86_WIDTH_32);
x86_l_1574:
	/* 0x1574: jmp    1080 <tail_nodeport_nat_ingress_ipv4+0x1080> */
	X86_SIM_X86_JMP(0x1574, 0x1080, x86_l_1080);
x86_l_1579:
	/* 0x1579: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_157e:
	/* 0x157e: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1582:
	/* 0x1582: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1586:
	/* 0x1586: je     159a <tail_nodeport_nat_ingress_ipv4+0x159a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1586, 0x159a, x86_l_159a);
x86_l_1588:
	/* 0x1588: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_158d:
	/* 0x158d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_158f:
	/* 0x158f: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1591:
	/* 0x1591: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1594:
	/* 0x1594: shr    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_1598:
	/* 0x1598: jmp    15bd <tail_nodeport_nat_ingress_ipv4+0x15bd> */
	X86_SIM_X86_JMP(0x1598, 0x15bd, x86_l_15bd);
x86_l_159a:
	/* 0x159a: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_159f:
	/* 0x159f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15a1:
	/* 0x15a1: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_15a3:
	/* 0x15a3: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_15a7:
	/* 0x15a7: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_15b1:
	/* 0x15b1: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_15b4:
	/* 0x15b4: mulx   rcx,rcx,rcx */
	X86_SIM_L_EXEC_MULX(X86_RCX, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_15b9:
	/* 0x15b9: shr    rcx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_15bd:
	/* 0x15bd: add    ebp,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_15bf:
	/* 0x15bf: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_15c2:
	/* 0x15c2: mov    DWORD PTR [r12+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_15c7:
	/* 0x15c7: movzx  edx,BYTE PTR [r12+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_15cd:
	/* 0x15cd: mov    eax,DWORD PTR [r12+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_15d2:
	/* 0x15d2: and    r13b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_15d6:
	/* 0x15d6: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15da:
	/* 0x15da: je     15ed <tail_nodeport_nat_ingress_ipv4+0x15ed> */
	X86_SIM_X86_JCC(X86_CC_E, 0x15da, 0x15ed, x86_l_15ed);
x86_l_15dc:
	/* 0x15dc: mov    rsi,QWORD PTR [rip+0x3248] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_15e3:
	/* 0x15e3: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15e5:
	/* 0x15e5: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_15e8:
	/* 0x15e8: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_15eb:
	/* 0x15eb: jmp    15f2 <tail_nodeport_nat_ingress_ipv4+0x15f2> */
	X86_SIM_X86_JMP(0x15eb, 0x15f2, x86_l_15f2);
x86_l_15ed:
	/* 0x15ed: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_15f2:
	/* 0x15f2: add    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_15f4:
	/* 0x15f4: or     r13b,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_15f7:
	/* 0x15f7: cmp    esi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_15f9:
	/* 0x15f9: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_15fc:
	/* 0x15fc: mov    r14d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1601:
	/* 0x1601: jb     1608 <tail_nodeport_nat_ingress_ipv4+0x1608> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1601, 0x1608, x86_l_1608);
x86_l_1603:
	/* 0x1603: cmp    dl,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_8);
x86_l_1606:
	/* 0x1606: je     1618 <tail_nodeport_nat_ingress_ipv4+0x1618> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1606, 0x1618, x86_l_1618);
x86_l_1608:
	/* 0x1608: mov    BYTE PTR [rax+0x2b],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_160c:
	/* 0x160c: mov    DWORD PTR [rax+0x34],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_160f:
	/* 0x160f: mov    rcx,QWORD PTR [rip+0x3248] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_1616:
	/* 0x1616: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1618:
	/* 0x1618: test   BYTE PTR [rsp+0x35],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 227633266690ULL);
x86_l_161d:
	/* 0x161d: jne    1094 <tail_nodeport_nat_ingress_ipv4+0x1094> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x161d, 0x1094, x86_l_1094);
x86_l_1623:
	/* 0x1623: movzx  eax,WORD PTR [rax+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_1627:
	/* 0x1627: mov    WORD PTR [rsp+0x8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_162c:
	/* 0x162c: mov    r14,QWORD PTR [rip+0x3248] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_1633:
	/* 0x1633: movzx  eax,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1637:
	/* 0x1637: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_163c:
	/* 0x163c: mov    rdi,QWORD PTR [rip+0x3248] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_reverse_nat)));
x86_l_1643:
	/* 0x1643: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1648:
	/* 0x1648: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_164a:
	/* 0x164a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_164d:
	/* 0x164d: je     185b <tail_nodeport_nat_ingress_ipv4+0x185b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x164d, 0x185b, x86_l_185b);
x86_l_1653:
	/* 0x1653: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_1656:
	/* 0x1656: mov    eax,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_165a:
	/* 0x165a: mov    DWORD PTR [rsp+0x88],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1661:
	/* 0x1661: movzx  eax,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1665:
	/* 0x1665: mov    eax,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1669:
	/* 0x1669: mov    DWORD PTR [rsp+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_166d:
	/* 0x166d: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_1672:
	/* 0x1672: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1674:
	/* 0x1674: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1677:
	/* 0x1677: mov    esi,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 26ULL);
x86_l_167c:
	/* 0x167c: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_167f:
	/* 0x167f: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1684:
	/* 0x1684: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1687:
	/* 0x1687: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1689:
	/* 0x1689: mov    r12d,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967155ULL);
x86_l_168f:
	/* 0x168f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1691:
	/* 0x1691: js     1ba8 <tail_nodeport_nat_ingress_ipv4+0x1ba8> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1691, 0x1ba8, x86_l_1ba8);
x86_l_1697:
	/* 0x1697: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_169a:
	/* 0x169a: mov    r14d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_169f:
	/* 0x169f: je     10bc <tail_nodeport_nat_ingress_ipv4+0x10bc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x169f, 0x10bc, x86_l_10bc);
x86_l_16a5:
	/* 0x16a5: mov    r12d,DWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_16ad:
	/* 0x16ad: not    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_16b0:
	/* 0x16b0: add    r12d,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_R13, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_16b4:
	/* 0x16b4: adc    r12d,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_16b8:
	/* 0x16b8: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16ba:
	/* 0x16ba: mov    eax,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_16bf:
	/* 0x16bf: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_16c2:
	/* 0x16c2: mov    esi,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 24ULL);
x86_l_16c7:
	/* 0x16c7: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16c9:
	/* 0x16c9: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_16cc:
	/* 0x16cc: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16cf:
	/* 0x16cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16d1:
	/* 0x16d1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_16d3:
	/* 0x16d3: js     170e <tail_nodeport_nat_ingress_ipv4+0x170e> */
	X86_SIM_X86_JCC(X86_CC_S, 0x16d3, 0x170e, x86_l_170e);
x86_l_16d5:
	/* 0x16d5: mov    DWORD PTR [rsp+0x88],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_16dd:
	/* 0x16dd: movabs rax,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2199023255552ULL);
x86_l_16e7:
	/* 0x16e7: test   r15,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_16ea:
	/* 0x16ea: jne    185b <tail_nodeport_nat_ingress_ipv4+0x185b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x16ea, 0x185b, x86_l_185b);
x86_l_16f0:
	/* 0x16f0: movzx  eax,BYTE PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 52ULL);
x86_l_16f5:
	/* 0x16f5: cmp    eax,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 58ULL);
x86_l_16f8:
	/* 0x16f8: je     1767 <tail_nodeport_nat_ingress_ipv4+0x1767> */
	X86_SIM_X86_JCC(X86_CC_E, 0x16f8, 0x1767, x86_l_1767);
x86_l_16fa:
	/* 0x16fa: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_16fd:
	/* 0x16fd: je     1750 <tail_nodeport_nat_ingress_ipv4+0x1750> */
	X86_SIM_X86_JCC(X86_CC_E, 0x16fd, 0x1750, x86_l_1750);
x86_l_16ff:
	/* 0x16ff: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_1702:
	/* 0x1702: jne    1776 <tail_nodeport_nat_ingress_ipv4+0x1776> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1702, 0x1776, x86_l_1776);
x86_l_1704:
	/* 0x1704: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1707:
	/* 0x1707: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_170c:
	/* 0x170c: jmp    176f <tail_nodeport_nat_ingress_ipv4+0x176f> */
	X86_SIM_X86_JMP(0x170c, 0x176f, x86_l_176f);
x86_l_170e:
	/* 0x170e: mov    r12d,0xffffff67 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967143ULL);
x86_l_1714:
	/* 0x1714: jmp    10bc <tail_nodeport_nat_ingress_ipv4+0x10bc> */
	X86_SIM_X86_JMP(0x1714, 0x10bc, x86_l_10bc);
x86_l_1719:
	/* 0x1719: mov    r12d,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967142ULL);
x86_l_171f:
	/* 0x171f: mov    edx,DWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1723:
	/* 0x1723: movzx  ecx,BYTE PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 128ULL);
x86_l_172b:
	/* 0x172b: cmp    r12d,0xffffff66 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4294967142ULL);
x86_l_1732:
	/* 0x1732: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_1735:
	/* 0x1735: or     cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_OR);
x86_l_1737:
	/* 0x1737: je     fb8 <tail_nodeport_nat_ingress_ipv4+0xfb8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1737, 0xfb8, x86_l_fb8);
x86_l_173d:
	/* 0x173d: jmp    107b <tail_nodeport_nat_ingress_ipv4+0x107b> */
	X86_SIM_X86_JMP(0x173d, 0x107b, x86_l_107b);
x86_l_1742:
	/* 0x1742: mov    r12d,0xffffff51 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967121ULL);
x86_l_1748:
	/* 0x1748: mov    r14d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R13, X86_WIDTH_32);
x86_l_174b:
	/* 0x174b: jmp    1080 <tail_nodeport_nat_ingress_ipv4+0x1080> */
	X86_SIM_X86_JMP(0x174b, 0x1080, x86_l_1080);
x86_l_1750:
	/* 0x1750: mov    DWORD PTR [rsp+0x38],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168608ULL);
x86_l_1758:
	/* 0x1758: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_175d:
	/* 0x175d: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1762:
	/* 0x1762: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1765:
	/* 0x1765: jmp    1788 <tail_nodeport_nat_ingress_ipv4+0x1788> */
	X86_SIM_X86_JMP(0x1765, 0x1788, x86_l_1788);
x86_l_1767:
	/* 0x1767: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_176a:
	/* 0x176a: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_176f:
	/* 0x176f: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1774:
	/* 0x1774: jmp    1780 <tail_nodeport_nat_ingress_ipv4+0x1780> */
	X86_SIM_X86_JMP(0x1774, 0x1780, x86_l_1780);
x86_l_1776:
	/* 0x1776: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1778:
	/* 0x1778: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_177d:
	/* 0x177d: mov    r15b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_8, 1ULL);
x86_l_1780:
	/* 0x1780: mov    DWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1788:
	/* 0x1788: movzx  ecx,WORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_178d:
	/* 0x178d: test   cx,cx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_16);
x86_l_1790:
	/* 0x1790: je     1827 <tail_nodeport_nat_ingress_ipv4+0x1827> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1790, 0x1827, x86_l_1827);
x86_l_1796:
	/* 0x1796: movzx  r13d,WORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_179c:
	/* 0x179c: mov    r12d,0xffffff72 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967154ULL);
x86_l_17a2:
	/* 0x17a2: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17a4:
	/* 0x17a4: cmp    eax,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_17a7:
	/* 0x17a7: jg     17b3 <tail_nodeport_nat_ingress_ipv4+0x17b3> */
	X86_SIM_X86_JCC(X86_CC_G, 0x17a7, 0x17b3, x86_l_17b3);
x86_l_17a9:
	/* 0x17a9: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_17ac:
	/* 0x17ac: je     1827 <tail_nodeport_nat_ingress_ipv4+0x1827> */
	X86_SIM_X86_JCC(X86_CC_E, 0x17ac, 0x1827, x86_l_1827);
x86_l_17ae:
	/* 0x17ae: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_17b1:
	/* 0x17b1: jmp    17bb <tail_nodeport_nat_ingress_ipv4+0x17bb> */
	X86_SIM_X86_JMP(0x17b1, 0x17bb, x86_l_17bb);
x86_l_17b3:
	/* 0x17b3: cmp    eax,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 58ULL);
x86_l_17b6:
	/* 0x17b6: je     1827 <tail_nodeport_nat_ingress_ipv4+0x1827> */
	X86_SIM_X86_JCC(X86_CC_E, 0x17b6, 0x1827, x86_l_1827);
x86_l_17b8:
	/* 0x17b8: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_17bb:
	/* 0x17bb: mov    r14d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_17c0:
	/* 0x17c0: jne    10bc <tail_nodeport_nat_ingress_ipv4+0x10bc> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x17c0, 0x10bc, x86_l_10bc);
x86_l_17c6:
	/* 0x17c6: cmp    cx,r13w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R13, X86_WIDTH_16);
x86_l_17ca:
	/* 0x17ca: je     1827 <tail_nodeport_nat_ingress_ipv4+0x1827> */
	X86_SIM_X86_JCC(X86_CC_E, 0x17ca, 0x1827, x86_l_1827);
x86_l_17cc:
	/* 0x17cc: mov    WORD PTR [rsp+0x8],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17d1:
	/* 0x17d1: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_17d6:
	/* 0x17d6: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17db:
	/* 0x17db: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17dd:
	/* 0x17dd: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_17e0:
	/* 0x17e0: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_17e5:
	/* 0x17e5: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_17ea:
	/* 0x17ea: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17ed:
	/* 0x17ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17ef:
	/* 0x17ef: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_17f1:
	/* 0x17f1: js     1a26 <tail_nodeport_nat_ingress_ipv4+0x1a26> */
	X86_SIM_X86_JCC(X86_CC_S, 0x17f1, 0x1a26, x86_l_1a26);
x86_l_17f7:
	/* 0x17f7: movzx  ecx,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_17fc:
	/* 0x17fc: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1801:
	/* 0x1801: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1806:
	/* 0x1806: lea    esi,[rdx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1809:
	/* 0x1809: mov    r8d,DWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_180e:
	/* 0x180e: or     r8d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_1812:
	/* 0x1812: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_1817:
	/* 0x1817: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_181a:
	/* 0x181a: mov    edx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_32);
x86_l_181d:
	/* 0x181d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_181f:
	/* 0x181f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1821:
	/* 0x1821: js     19a1 <tail_nodeport_nat_ingress_ipv4+0x19a1> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1821, 0x19a1, x86_l_19a1);
x86_l_1827:
	/* 0x1827: test   r15b,r15b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_8);
x86_l_182a:
	/* 0x182a: jne    185b <tail_nodeport_nat_ingress_ipv4+0x185b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x182a, 0x185b, x86_l_185b);
x86_l_182c:
	/* 0x182c: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1831:
	/* 0x1831: add    esi,DWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RSI, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 88ULL);
x86_l_1835:
	/* 0x1835: mov    r8d,DWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_183a:
	/* 0x183a: or     r8d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 16ULL);
x86_l_183e:
	/* 0x183e: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1840:
	/* 0x1840: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_1845:
	/* 0x1845: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1848:
	/* 0x1848: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_184a:
	/* 0x184a: mov    ecx,DWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1851:
	/* 0x1851: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1853:
	/* 0x1853: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1855:
	/* 0x1855: js     19a1 <tail_nodeport_nat_ingress_ipv4+0x19a1> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1855, 0x19a1, x86_l_19a1);
x86_l_185b:
	/* 0x185b: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_185e:
	/* 0x185e: sub    eax,DWORD PTR [rbx+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_1861:
	/* 0x1861: cmp    eax,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 34ULL);
x86_l_1864:
	/* 0x1864: jae    1878 <tail_nodeport_nat_ingress_ipv4+0x1878> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x1864, 0x1878, x86_l_1878);
x86_l_1866:
	/* 0x1866: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1868:
	/* 0x1868: mov    r12d,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967162ULL);
x86_l_186e:
	/* 0x186e: mov    r14d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1873:
	/* 0x1873: jmp    10bc <tail_nodeport_nat_ingress_ipv4+0x10bc> */
	X86_SIM_X86_JMP(0x1873, 0x10bc, x86_l_10bc);
x86_l_1878:
	/* 0x1878: mov    rax,QWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_187f:
	/* 0x187f: mov    ecx,0xfffff0ff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294963455ULL);
x86_l_1884:
	/* 0x1884: and    ecx,DWORD PTR [rbx+0xa8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 168ULL);
x86_l_188a:
	/* 0x188a: or     ecx,0x300 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_OR, 768ULL);
x86_l_1890:
	/* 0x1890: mov    DWORD PTR [rbx+0xa8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1896:
	/* 0x1896: mov    ecx,DWORD PTR [rax+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_1899:
	/* 0x1899: mov    DWORD PTR [rsp+0xb0],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_18a0:
	/* 0x18a0: mov    ecx,DWORD PTR [rax+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_18a3:
	/* 0x18a3: mov    DWORD PTR [rsp+0xc0],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_18aa:
	/* 0x18aa: movzx  edx,BYTE PTR [rax+0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 22ULL);
x86_l_18ae:
	/* 0x18ae: mov    r12d,0xffffff3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967100ULL);
x86_l_18b4:
	/* 0x18b4: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_18b7:
	/* 0x18b7: jb     197f <tail_nodeport_nat_ingress_ipv4+0x197f> */
	X86_SIM_X86_JCC(X86_CC_B, 0x18b7, 0x197f, x86_l_197f);
x86_l_18bd:
	/* 0x18bd: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_18c0:
	/* 0x18c0: mov    BYTE PTR [rax+0x16],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_18c3:
	/* 0x18c3: movzx  ecx,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_18c6:
	/* 0x18c6: mov    eax,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_18cb:
	/* 0x18cb: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_18ce:
	/* 0x18ce: mov    esi,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 24ULL);
x86_l_18d3:
	/* 0x18d3: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_18d9:
	/* 0x18d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18db:
	/* 0x18db: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_18dd:
	/* 0x18dd: js     1979 <tail_nodeport_nat_ingress_ipv4+0x1979> */
	X86_SIM_X86_JCC(X86_CC_S, 0x18dd, 0x1979, x86_l_1979);
x86_l_18e3:
	/* 0x18e3: mov    eax,0x45 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 69ULL);
x86_l_18e8:
	/* 0x18e8: mov    rcx,QWORD PTR [rip+0x3248] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_supports_fib_lookup_skip_neigh)));
x86_l_18ef:
	/* 0x18ef: movzx  ecx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_18f2:
	/* 0x18f2: shl    ecx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 2ULL);
x86_l_18f5:
	/* 0x18f5: lea    rsi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_18fd:
	/* 0x18fd: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1900:
	/* 0x1900: mov    edx,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 64ULL);
x86_l_1905:
	/* 0x1905: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1907:
	/* 0x1907: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1909:
	/* 0x1909: je     1910 <tail_nodeport_nat_ingress_ipv4+0x1910> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1909, 0x1910, x86_l_1910);
x86_l_190b:
	/* 0x190b: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_190e:
	/* 0x190e: jne    198b <tail_nodeport_nat_ingress_ipv4+0x198b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x190e, 0x198b, x86_l_198b);
x86_l_1910:
	/* 0x1910: mov    ebp,DWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1917:
	/* 0x1917: mov    DWORD PTR [rsp+0x8],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_191b:
	/* 0x191b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1920:
	/* 0x1920: mov    rdi,QWORD PTR [rip+0x3248] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_devices)));
x86_l_1927:
	/* 0x1927: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_192c:
	/* 0x192c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_192e:
	/* 0x192e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1931:
	/* 0x1931: je     193d <tail_nodeport_nat_ingress_ipv4+0x193d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1931, 0x193d, x86_l_193d);
x86_l_1933:
	/* 0x1933: test   BYTE PTR [rax+0x8],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_1937:
	/* 0x1937: jne    19e7 <tail_nodeport_nat_ingress_ipv4+0x19e7> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1937, 0x19e7, x86_l_19e7);
x86_l_193d:
	/* 0x193d: lea    rax,[rsp+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1945:
	/* 0x1945: movzx  ecx,BYTE PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 160ULL);
x86_l_194d:
	/* 0x194d: mov    DWORD PTR [rsp+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1951:
	/* 0x1951: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1954:
	/* 0x1954: mov    rax,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1958:
	/* 0x1958: mov    QWORD PTR [rsp+0xc],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_195d:
	/* 0x195d: mov    QWORD PTR [rsp+0x14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1962:
	/* 0x1962: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1967:
	/* 0x1967: mov    eax,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 152ULL);
x86_l_196c:
	/* 0x196c: mov    edi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_32);
x86_l_196e:
	/* 0x196e: mov    edx,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 20ULL);
x86_l_1973:
	/* 0x1973: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1975:
	/* 0x1975: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1977:
	/* 0x1977: jmp    19f2 <tail_nodeport_nat_ingress_ipv4+0x19f2> */
	X86_SIM_X86_JMP(0x1977, 0x19f2, x86_l_19f2);
x86_l_1979:
	/* 0x1979: mov    r12d,0xffffff67 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967143ULL);
x86_l_197f:
	/* 0x197f: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1981:
	/* 0x1981: mov    r14d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1986:
	/* 0x1986: jmp    10bc <tail_nodeport_nat_ingress_ipv4+0x10bc> */
	X86_SIM_X86_JMP(0x1986, 0x10bc, x86_l_10bc);
x86_l_198b:
	/* 0x198b: shl    eax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_198e:
	/* 0x198e: movzx  ebp,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1991:
	/* 0x1991: mov    r12d,0xffffff57 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967127ULL);
x86_l_1997:
	/* 0x1997: mov    r14d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_199c:
	/* 0x199c: jmp    10bc <tail_nodeport_nat_ingress_ipv4+0x10bc> */
	X86_SIM_X86_JMP(0x199c, 0x10bc, x86_l_10bc);
x86_l_19a1:
	/* 0x19a1: mov    r12d,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967142ULL);
x86_l_19a7:
	/* 0x19a7: mov    r14d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_19ac:
	/* 0x19ac: jmp    10bc <tail_nodeport_nat_ingress_ipv4+0x10bc> */
	X86_SIM_X86_JMP(0x19ac, 0x10bc, x86_l_10bc);
x86_l_19b1:
	/* 0x19b1: mov    QWORD PTR [rsp+0xa0],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767361ULL);
x86_l_19bd:
	/* 0x19bd: mov    QWORD PTR [rsp+0xa8],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_19c5:
	/* 0x19c5: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_19ca:
	/* 0x19ca: mov    rdi,QWORD PTR [rip+0x3248] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_19d1:
	/* 0x19d1: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_19d6:
	/* 0x19d6: lea    rdx,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_19de:
	/* 0x19de: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19e0:
	/* 0x19e0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19e2:
	/* 0x19e2: jmp    1558 <tail_nodeport_nat_ingress_ipv4+0x1558> */
	X86_SIM_X86_JMP(0x19e2, 0x1558, x86_l_1558);
x86_l_19e7:
	/* 0x19e7: mov    eax,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 23ULL);
x86_l_19ec:
	/* 0x19ec: mov    edi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_32);
x86_l_19ee:
	/* 0x19ee: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19f0:
	/* 0x19f0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19f2:
	/* 0x19f2: mov    r12d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_32);
x86_l_19f5:
	/* 0x19f5: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19f7:
	/* 0x19f7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_19f9:
	/* 0x19f9: js     1ba8 <tail_nodeport_nat_ingress_ipv4+0x1ba8> */
	X86_SIM_X86_JCC(X86_CC_S, 0x19f9, 0x1ba8, x86_l_1ba8);
x86_l_19ff:
	/* 0x19ff: cmp    r12d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 2ULL);
x86_l_1a03:
	/* 0x1a03: je     1ba8 <tail_nodeport_nat_ingress_ipv4+0x1ba8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a03, 0x1ba8, x86_l_1ba8);
x86_l_1a09:
	/* 0x1a09: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_1a0c:
	/* 0x1a0c: mov    r14d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1a11:
	/* 0x1a11: jne    116b <tail_nodeport_nat_ingress_ipv4+0x116b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1a11, 0x116b, x86_l_116b);
x86_l_1a17:
	/* 0x1a17: jmp    1094 <tail_nodeport_nat_ingress_ipv4+0x1094> */
	X86_SIM_X86_JMP(0x1a17, 0x1094, x86_l_1094);
x86_l_1a1c:
	/* 0x1a1c: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1a21:
	/* 0x1a21: jmp    6df <tail_nodeport_nat_ingress_ipv4+0x6df> */
	X86_SIM_X86_JMP(0x1a21, 0x6df, x86_l_6df);
x86_l_1a26:
	/* 0x1a26: mov    r12d,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967155ULL);
x86_l_1a2c:
	/* 0x1a2c: mov    r14d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1a31:
	/* 0x1a31: jmp    10bc <tail_nodeport_nat_ingress_ipv4+0x10bc> */
	X86_SIM_X86_JMP(0x1a31, 0x10bc, x86_l_10bc);
x86_l_1a36:
	/* 0x1a36: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a3b:
	/* 0x1a3b: mov    rdi,QWORD PTR [rip+0x3248] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv4_frag_datagrams)));
x86_l_1a42:
	/* 0x1a42: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1a47:
	/* 0x1a47: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a49:
	/* 0x1a49: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a4c:
	/* 0x1a4c: je     1b61 <tail_nodeport_nat_ingress_ipv4+0x1b61> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a4c, 0x1b61, x86_l_1b61);
x86_l_1a52:
	/* 0x1a52: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a54:
	/* 0x1a54: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1a58:
	/* 0x1a58: jmp    e74 <tail_nodeport_nat_ingress_ipv4+0xe74> */
	X86_SIM_X86_JMP(0x1a58, 0xe74, x86_l_e74);
x86_l_1a5d:
	/* 0x1a5d: mov    r12d,0xffffff63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967139ULL);
x86_l_1a63:
	/* 0x1a63: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a65:
	/* 0x1a65: jmp    10bc <tail_nodeport_nat_ingress_ipv4+0x10bc> */
	X86_SIM_X86_JMP(0x1a65, 0x10bc, x86_l_10bc);
x86_l_1a6a:
	/* 0x1a6a: mov    r12d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 60ULL);
x86_l_1a70:
	/* 0x1a70: cmp    WORD PTR [rsp+0x44],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 292057776134ULL);
x86_l_1a76:
	/* 0x1a76: jne    1ab6 <tail_nodeport_nat_ingress_ipv4+0x1ab6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1a76, 0x1ab6, x86_l_1ab6);
x86_l_1a78:
	/* 0x1a78: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_1a7a:
	/* 0x1a7a: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1a7c:
	/* 0x1a7c: shr    ecx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_1a7f:
	/* 0x1a7f: and    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_1a82:
	/* 0x1a82: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1a84:
	/* 0x1a84: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1a8c:
	/* 0x1a8c: mov    WORD PTR [rdx+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1a90:
	/* 0x1a90: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1a92:
	/* 0x1a92: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_1a97:
	/* 0x1a97: mov    r12d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 21600ULL);
x86_l_1a9d:
	/* 0x1a9d: cmove  r12d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_1aa1:
	/* 0x1aa1: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1aa5:
	/* 0x1aa5: je     1ab6 <tail_nodeport_nat_ingress_ipv4+0x1ab6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1aa5, 0x1ab6, x86_l_1ab6);
x86_l_1aa7:
	/* 0x1aa7: mov    rax,QWORD PTR [rip+0x3248] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1aae:
	/* 0x1aae: imul   r12d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_1ab2:
	/* 0x1ab2: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1ab6:
	/* 0x1ab6: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1ab9:
	/* 0x1ab9: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1abd:
	/* 0x1abd: je     1ace <tail_nodeport_nat_ingress_ipv4+0x1ace> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1abd, 0x1ace, x86_l_1ace);
x86_l_1abf:
	/* 0x1abf: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_1ac4:
	/* 0x1ac4: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ac6:
	/* 0x1ac6: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1ac8:
	/* 0x1ac8: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_1acc:
	/* 0x1acc: jmp    1af1 <tail_nodeport_nat_ingress_ipv4+0x1af1> */
	X86_SIM_X86_JMP(0x1acc, 0x1af1, x86_l_1af1);
x86_l_1ace:
	/* 0x1ace: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1ad3:
	/* 0x1ad3: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ad5:
	/* 0x1ad5: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1ad7:
	/* 0x1ad7: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1adb:
	/* 0x1adb: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_1ae5:
	/* 0x1ae5: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1ae8:
	/* 0x1ae8: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1aed:
	/* 0x1aed: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_1af1:
	/* 0x1af1: add    r12d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1af4:
	/* 0x1af4: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1afc:
	/* 0x1afc: mov    DWORD PTR [rdx+0x20],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b00:
	/* 0x1b00: movzx  ecx,BYTE PTR [rdx+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_1b04:
	/* 0x1b04: mov    edx,DWORD PTR [rdx+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1b07:
	/* 0x1b07: and    bpl,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_1b0b:
	/* 0x1b0b: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b0f:
	/* 0x1b0f: je     1b22 <tail_nodeport_nat_ingress_ipv4+0x1b22> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1b0f, 0x1b22, x86_l_1b22);
x86_l_1b11:
	/* 0x1b11: mov    rsi,QWORD PTR [rip+0x3248] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1b18:
	/* 0x1b18: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b1a:
	/* 0x1b1a: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_1b1d:
	/* 0x1b1d: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1b20:
	/* 0x1b20: jmp    1b27 <tail_nodeport_nat_ingress_ipv4+0x1b27> */
	X86_SIM_X86_JMP(0x1b20, 0x1b27, x86_l_1b27);
x86_l_1b22:
	/* 0x1b22: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_1b27:
	/* 0x1b27: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1b29:
	/* 0x1b29: or     bpl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_1b2c:
	/* 0x1b2c: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_1b2e:
	/* 0x1b2e: movabs r10,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_64, 2199023255552ULL);
x86_l_1b38:
	/* 0x1b38: mov    r8,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b3d:
	/* 0x1b3d: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1b42:
	/* 0x1b42: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1b4a:
	/* 0x1b4a: jb     1b55 <tail_nodeport_nat_ingress_ipv4+0x1b55> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1b4a, 0x1b55, x86_l_1b55);
x86_l_1b4c:
	/* 0x1b4c: cmp    cl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_8);
x86_l_1b4f:
	/* 0x1b4f: je     a1f <tail_nodeport_nat_ingress_ipv4+0xa1f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1b4f, 0xa1f, x86_l_a1f);
x86_l_1b55:
	/* 0x1b55: mov    BYTE PTR [rdx+0x2b],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_1b59:
	/* 0x1b59: mov    DWORD PTR [rdx+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1b5c:
	/* 0x1b5c: jmp    a1b <tail_nodeport_nat_ingress_ipv4+0xa1b> */
	X86_SIM_X86_JMP(0x1b5c, 0xa1b, x86_l_a1b);
x86_l_1b61:
	/* 0x1b61: mov    r12d,0xffffff51 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967121ULL);
x86_l_1b67:
	/* 0x1b67: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b69:
	/* 0x1b69: jmp    10bc <tail_nodeport_nat_ingress_ipv4+0x10bc> */
	X86_SIM_X86_JMP(0x1b69, 0x10bc, x86_l_10bc);
x86_l_1b6e:
	/* 0x1b6e: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_1b73:
	/* 0x1b73: jmp    1217 <tail_nodeport_nat_ingress_ipv4+0x1217> */
	X86_SIM_X86_JMP(0x1b73, 0x1217, x86_l_1217);
x86_l_1b78:
	/* 0x1b78: mov    QWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_1b81:
	/* 0x1b81: mov    QWORD PTR [rsp+0x10],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b86:
	/* 0x1b86: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1b8b:
	/* 0x1b8b: mov    rdi,QWORD PTR [rip+0x3248] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1b92:
	/* 0x1b92: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1b97:
	/* 0x1b97: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b9c:
	/* 0x1b9c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b9e:
	/* 0x1b9e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ba0:
	/* 0x1ba0: mov    r14d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R12, X86_WIDTH_32);
x86_l_1ba3:
	/* 0x1ba3: jmp    e74 <tail_nodeport_nat_ingress_ipv4+0xe74> */
	X86_SIM_X86_JMP(0x1ba3, 0xe74, x86_l_e74);
x86_l_1ba8:
	/* 0x1ba8: mov    r14d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1bad:
	/* 0x1bad: jmp    10bc <tail_nodeport_nat_ingress_ipv4+0x10bc> */
	X86_SIM_X86_JMP(0x1bad, 0x10bc, x86_l_10bc);
x86_l_1bb2:
	/* 0x1bb2: mov    ebp,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_1bb7:
	/* 0x1bb7: cmp    BYTE PTR [rsp+0x20],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 137438953478ULL);
x86_l_1bbc:
	/* 0x1bbc: jne    1bf2 <tail_nodeport_nat_ingress_ipv4+0x1bf2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1bbc, 0x1bf2, x86_l_1bf2);
x86_l_1bbe:
	/* 0x1bbe: mov    eax,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_1bc1:
	/* 0x1bc1: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1bc3:
	/* 0x1bc3: shr    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_1bc6:
	/* 0x1bc6: and    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_1bc9:
	/* 0x1bc9: or     ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1bcb:
	/* 0x1bcb: mov    WORD PTR [r14+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1bd0:
	/* 0x1bd0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1bd2:
	/* 0x1bd2: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_1bd7:
	/* 0x1bd7: mov    ebp,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 21600ULL);
x86_l_1bdc:
	/* 0x1bdc: cmove  ebp,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_1bdf:
	/* 0x1bdf: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1be3:
	/* 0x1be3: je     1bf2 <tail_nodeport_nat_ingress_ipv4+0x1bf2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1be3, 0x1bf2, x86_l_1bf2);
x86_l_1be5:
	/* 0x1be5: mov    rax,QWORD PTR [rip+0x3248] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1bec:
	/* 0x1bec: imul   ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_1bef:
	/* 0x1bef: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1bf2:
	/* 0x1bf2: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1bf6:
	/* 0x1bf6: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bfa:
	/* 0x1bfa: je     1c0b <tail_nodeport_nat_ingress_ipv4+0x1c0b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1bfa, 0x1c0b, x86_l_1c0b);
x86_l_1bfc:
	/* 0x1bfc: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_1c01:
	/* 0x1c01: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c03:
	/* 0x1c03: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1c05:
	/* 0x1c05: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_1c09:
	/* 0x1c09: jmp    1c2e <tail_nodeport_nat_ingress_ipv4+0x1c2e> */
	X86_SIM_X86_JMP(0x1c09, 0x1c2e, x86_l_1c2e);
x86_l_1c0b:
	/* 0x1c0b: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1c10:
	/* 0x1c10: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c12:
	/* 0x1c12: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1c14:
	/* 0x1c14: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1c18:
	/* 0x1c18: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_1c22:
	/* 0x1c22: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1c25:
	/* 0x1c25: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1c2a:
	/* 0x1c2a: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_1c2e:
	/* 0x1c2e: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1c30:
	/* 0x1c30: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_1c33:
	/* 0x1c33: mov    DWORD PTR [r14+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c37:
	/* 0x1c37: movzx  ecx,BYTE PTR [r14+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_1c3c:
	/* 0x1c3c: mov    edx,DWORD PTR [r14+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1c40:
	/* 0x1c40: and    r13b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_1c44:
	/* 0x1c44: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c48:
	/* 0x1c48: je     1c5b <tail_nodeport_nat_ingress_ipv4+0x1c5b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1c48, 0x1c5b, x86_l_1c5b);
x86_l_1c4a:
	/* 0x1c4a: mov    rsi,QWORD PTR [rip+0x3248] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1c51:
	/* 0x1c51: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c53:
	/* 0x1c53: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_1c56:
	/* 0x1c56: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1c59:
	/* 0x1c59: jmp    1c60 <tail_nodeport_nat_ingress_ipv4+0x1c60> */
	X86_SIM_X86_JMP(0x1c59, 0x1c60, x86_l_1c60);
x86_l_1c5b:
	/* 0x1c5b: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_1c60:
	/* 0x1c60: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1c62:
	/* 0x1c62: or     r13b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_1c65:
	/* 0x1c65: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_1c67:
	/* 0x1c67: jb     1c6e <tail_nodeport_nat_ingress_ipv4+0x1c6e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1c67, 0x1c6e, x86_l_1c6e);
x86_l_1c69:
	/* 0x1c69: cmp    cl,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R13, X86_WIDTH_8);
x86_l_1c6c:
	/* 0x1c6c: je     1c7f <tail_nodeport_nat_ingress_ipv4+0x1c7f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1c6c, 0x1c7f, x86_l_1c7f);
x86_l_1c6e:
	/* 0x1c6e: mov    BYTE PTR [r14+0x2b],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_1c72:
	/* 0x1c72: mov    DWORD PTR [r14+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1c76:
	/* 0x1c76: mov    rax,QWORD PTR [rip+0x3248] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_1c7d:
	/* 0x1c7d: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c7f:
	/* 0x1c7f: mov    r14d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1c84:
	/* 0x1c84: jmp    1094 <tail_nodeport_nat_ingress_ipv4+0x1094> */
	X86_SIM_X86_JMP(0x1c84, 0x1094, x86_l_1094);
x86_l_1c89:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
