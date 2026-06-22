extern char __config_debug_lb;
extern char __config_enable_conntrack_accounting;
extern char __config_enable_ipv4_fragments;
extern char __config_enable_jiffies;
extern char __config_kernel_hz;
extern char __config_nodeport_port_max;
extern char __config_trace_payload_len;
extern char cilium_calls;
extern char cilium_ct4_global;
extern char cilium_ct_any4_global;
extern char cilium_devices;
extern char cilium_ipv4_frag_datagrams;
extern char cilium_lb4_reverse_nat;
extern char cilium_metrics;
extern char cilium_nodeport_neigh4;
extern char cilium_snat_v4_external;
extern char cilium_xdp_scratch;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int cilium_bpf_xdp_tail_nodeport_nat_ingress_ipv4_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0xa: sub    rsp,0xc8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 200ULL);
x86_l_11:
	/* 0x11: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_14:
	/* 0x14: mov    rax,QWORD PTR [rip+0x23c0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_nodeport_port_max)));
x86_l_1b:
	/* 0x1b: movzx  r14d,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1f:
	/* 0x1f: mov    rax,QWORD PTR [rip+0x23c0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_26:
	/* 0x26: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28:
	/* 0x28: mov    DWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_30:
	/* 0x30: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_35:
	/* 0x35: mov    rdi,QWORD PTR [rip+0x23c0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_3c:
	/* 0x3c: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_41:
	/* 0x41: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_43:
	/* 0x43: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_46:
	/* 0x46: je     c52 <tail_nodeport_nat_ingress_ipv4+0xc52> */
	X86_SIM_X86_JCC(X86_CC_E, 0x46, 0xc52, x86_l_c52);
x86_l_4c:
	/* 0x4c: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4e:
	/* 0x4e: mov    DWORD PTR [rsp+0xb4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 180ULL);
x86_l_55:
	/* 0x55: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_5d:
	/* 0x5d: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_60:
	/* 0x60: mov    r15,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_64:
	/* 0x64: lea    rcx,[rax+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_68:
	/* 0x68: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_6d:
	/* 0x6d: cmp    rcx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_70:
	/* 0x70: jbe    1e6 <tail_nodeport_nat_ingress_ipv4+0x1e6> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x70, 0x1e6, x86_l_1e6);
x86_l_76:
	/* 0x76: cmp    ebp,0xffffff53 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4294967123ULL);
x86_l_7c:
	/* 0x7c: je     89 <tail_nodeport_nat_ingress_ipv4+0x89> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7c, 0x89, x86_l_89);
x86_l_7e:
	/* 0x7e: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_81:
	/* 0x81: cmp    ebp,0xffffff59 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4294967129ULL);
x86_l_87:
	/* 0x87: jne    d1 <tail_nodeport_nat_ingress_ipv4+0xd1> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x87, 0xd1, x86_l_d1);
x86_l_89:
	/* 0x89: mov    DWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_91:
	/* 0x91: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_96:
	/* 0x96: mov    rdi,QWORD PTR [rip+0x23c0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_9d:
	/* 0x9d: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_a2:
	/* 0xa2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a4:
	/* 0xa4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a7:
	/* 0xa7: je     b0 <tail_nodeport_nat_ingress_ipv4+0xb0> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa7, 0xb0, x86_l_b0);
x86_l_a9:
	/* 0xa9: mov    DWORD PTR [rax+0x14],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345921ULL);
x86_l_b0:
	/* 0xb0: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_b5:
	/* 0xb5: mov    rsi,QWORD PTR [rip+0x23c0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_bc:
	/* 0xbc: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_bf:
	/* 0xbf: mov    edx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_c4:
	/* 0xc4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c6:
	/* 0xc6: mov    ebp,0xffffff74 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967156ULL);
x86_l_cb:
	/* 0xcb: mov    r12d,0x700 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1792ULL);
x86_l_d1:
	/* 0xd1: mov    r14d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RBP, X86_WIDTH_32);
x86_l_d4:
	/* 0xd4: neg    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_d7:
	/* 0xd7: cmovs  r14d,ebp */
	X86_SIM_L_EXEC_CMOV(X86_R14, X86_RBP, X86_WIDTH_32, X86_CC_S);
x86_l_db:
	/* 0xdb: mov    DWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_e3:
	/* 0xe3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e8:
	/* 0xe8: mov    rdi,QWORD PTR [rip+0x23c0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_ef:
	/* 0xef: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_f4:
	/* 0xf4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f6:
	/* 0xf6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f9:
	/* 0xf9: je     104 <tail_nodeport_nat_ingress_ipv4+0x104> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf9, 0x104, x86_l_104);
x86_l_fb:
	/* 0xfb: mov    ecx,DWORD PTR [rsp+0xb4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 180ULL);
x86_l_102:
	/* 0x102: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_104:
	/* 0x104: mov    DWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_10c:
	/* 0x10c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_111:
	/* 0x111: mov    rdi,QWORD PTR [rip+0x23c0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_118:
	/* 0x118: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_11d:
	/* 0x11d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11f:
	/* 0x11f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_122:
	/* 0x122: je     12b <tail_nodeport_nat_ingress_ipv4+0x12b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x122, 0x12b, x86_l_12b);
x86_l_124:
	/* 0x124: mov    DWORD PTR [rax+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_12b:
	/* 0x12b: mov    DWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_133:
	/* 0x133: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_138:
	/* 0x138: mov    rdi,QWORD PTR [rip+0x23c0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_13f:
	/* 0x13f: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_144:
	/* 0x144: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_146:
	/* 0x146: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_149:
	/* 0x149: je     155 <tail_nodeport_nat_ingress_ipv4+0x155> */
	X86_SIM_X86_JCC(X86_CC_E, 0x149, 0x155, x86_l_155);
x86_l_14b:
	/* 0x14b: movzx  ecx,r14b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R14, X86_WIDTH_32, X86_WIDTH_8);
x86_l_14f:
	/* 0x14f: or     ecx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R12, X86_WIDTH_32, X86_ALU_OR);
x86_l_152:
	/* 0x152: mov    DWORD PTR [rax+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_155:
	/* 0x155: mov    DWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_15d:
	/* 0x15d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_162:
	/* 0x162: mov    rdi,QWORD PTR [rip+0x23c0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_169:
	/* 0x169: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_16e:
	/* 0x16e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_170:
	/* 0x170: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_173:
	/* 0x173: je     17c <tail_nodeport_nat_ingress_ipv4+0x17c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x173, 0x17c, x86_l_17c);
x86_l_175:
	/* 0x175: mov    DWORD PTR [rax+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_17c:
	/* 0x17c: mov    DWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_184:
	/* 0x184: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_189:
	/* 0x189: mov    rdi,QWORD PTR [rip+0x23c0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_190:
	/* 0x190: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_195:
	/* 0x195: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_197:
	/* 0x197: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_19a:
	/* 0x19a: je     1a3 <tail_nodeport_nat_ingress_ipv4+0x1a3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x19a, 0x1a3, x86_l_1a3);
x86_l_19c:
	/* 0x19c: mov    DWORD PTR [rax+0x10],0x9d96801 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68884719617ULL);
x86_l_1a3:
	/* 0x1a3: mov    r15,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a7:
	/* 0x1a7: sub    r15,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 0ULL);
x86_l_1aa:
	/* 0x1aa: movabs rax,0x6809d90100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 446841815296ULL);
x86_l_1b4:
	/* 0x1b4: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1b9:
	/* 0x1b9: mov    BYTE PTR [rsp+0x18],r14b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1be:
	/* 0x1be: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1c3:
	/* 0x1c3: mov    rdi,QWORD PTR [rip+0x23c0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1ca:
	/* 0x1ca: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1cf:
	/* 0x1cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d1:
	/* 0x1d1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1d4:
	/* 0x1d4: je     2e2 <tail_nodeport_nat_ingress_ipv4+0x2e2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1d4, 0x2e2, x86_l_2e2);
x86_l_1da:
	/* 0x1da: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1dd:
	/* 0x1dd: add    QWORD PTR [rax+0x8],r15 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1e1:
	/* 0x1e1: jmp    30a <tail_nodeport_nat_ingress_ipv4+0x30a> */
	X86_SIM_X86_JMP(0x1e1, 0x30a, x86_l_30a);
x86_l_1e6:
	/* 0x1e6: movabs r9,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_64, 2199023255552ULL);
x86_l_1f0:
	/* 0x1f0: movabs r10,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_64, 1099511627776ULL);
x86_l_1fa:
	/* 0x1fa: movzx  edx,WORD PTR [rax+0x12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18ULL);
x86_l_1fe:
	/* 0x1fe: movzx  ecx,BYTE PTR [rax+0x17] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 23ULL);
x86_l_202:
	/* 0x202: mov    rsi,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RCX, X86_WIDTH_64);
x86_l_205:
	/* 0x205: shl    rsi,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_209:
	/* 0x209: or     rsi,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_64, X86_ALU_OR);
x86_l_20c:
	/* 0x20c: movzx  edi,WORD PTR [rax+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 20ULL);
x86_l_210:
	/* 0x210: lea    r8,[rsi+r10*1] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_R10, 0), 0ULL);
x86_l_214:
	/* 0x214: test   edi,0xff3f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDI, X86_WIDTH_32, 65343ULL);
x86_l_21a:
	/* 0x21a: cmove  r8,rsi */
	X86_SIM_L_EXEC_CMOV(X86_R8, X86_RSI, X86_WIDTH_64, X86_CC_E);
x86_l_21e:
	/* 0x21e: lea    r12,[r8+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_222:
	/* 0x222: mov    BYTE PTR [rsp+0x14],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_226:
	/* 0x226: mov    edx,DWORD PTR [rax+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_229:
	/* 0x229: mov    DWORD PTR [rsp+0x8],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22d:
	/* 0x22d: test   edi,0xff1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDI, X86_WIDTH_32, 65311ULL);
x86_l_233:
	/* 0x233: mov    esi,DWORD PTR [rax+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_236:
	/* 0x236: mov    DWORD PTR [rsp+0xc],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_23a:
	/* 0x23a: mov    BYTE PTR [rsp+0x15],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 90194313217ULL);
x86_l_23f:
	/* 0x23f: cmove  r12,r8 */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_R8, X86_WIDTH_64, X86_CC_E);
x86_l_243:
	/* 0x243: mov    r13d,DWORD PTR [rax+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_247:
	/* 0x247: shl    r13d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHL, 2ULL);
x86_l_24b:
	/* 0x24b: and    r13d,0x3c */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 60ULL);
x86_l_24f:
	/* 0x24f: lea    r8,[r13+0xe] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_253:
	/* 0x253: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_256:
	/* 0x256: je     33d <tail_nodeport_nat_ingress_ipv4+0x33d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x256, 0x33d, x86_l_33d);
x86_l_25c:
	/* 0x25c: mov    ebp,0xffffff53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967123ULL);
x86_l_261:
	/* 0x261: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_264:
	/* 0x264: je     26f <tail_nodeport_nat_ingress_ipv4+0x26f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x264, 0x26f, x86_l_26f);
x86_l_266:
	/* 0x266: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_269:
	/* 0x269: jne    76 <tail_nodeport_nat_ingress_ipv4+0x76> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x269, 0x76, x86_l_76);
x86_l_26f:
	/* 0x26f: mov    rcx,QWORD PTR [rip+0x23c0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_ipv4_fragments)));
x86_l_276:
	/* 0x276: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_279:
	/* 0x279: je     394 <tail_nodeport_nat_ingress_ipv4+0x394> */
	X86_SIM_X86_JCC(X86_CC_E, 0x279, 0x394, x86_l_394);
x86_l_27f:
	/* 0x27f: mov    DWORD PTR [rsp+0x18],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_283:
	/* 0x283: mov    DWORD PTR [rsp+0x1c],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_287:
	/* 0x287: mov    WORD PTR [rsp+0x20],r12w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_28d:
	/* 0x28d: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_290:
	/* 0x290: shr    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_294:
	/* 0x294: mov    BYTE PTR [rsp+0x22],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_298:
	/* 0x298: mov    BYTE PTR [rsp+0x23],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 150323855360ULL);
x86_l_29d:
	/* 0x29d: test   r12,r9 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R9, X86_WIDTH_64);
x86_l_2a0:
	/* 0x2a0: jne    1399 <tail_nodeport_nat_ingress_ipv4+0x1399> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2a0, 0x1399, x86_l_1399);
x86_l_2a6:
	/* 0x2a6: lea    rcx,[rax+r8*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_2aa:
	/* 0x2aa: add    rcx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2ae:
	/* 0x2ae: mov    ebp,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967161ULL);
x86_l_2b3:
	/* 0x2b3: cmp    rcx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_2b6:
	/* 0x2b6: ja     76 <tail_nodeport_nat_ingress_ipv4+0x76> */
	X86_SIM_X86_JCC(X86_CC_A, 0x2b6, 0x76, x86_l_76);
x86_l_2bc:
	/* 0x2bc: add    rax,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R8, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2bf:
	/* 0x2bf: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c1:
	/* 0x2c1: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c5:
	/* 0x2c5: test   r12,r10 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R10, X86_WIDTH_64);
x86_l_2c8:
	/* 0x2c8: jne    13d0 <tail_nodeport_nat_ingress_ipv4+0x13d0> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2c8, 0x13d0, x86_l_13d0);
x86_l_2ce:
	/* 0x2ce: mov    QWORD PTR [rsp+0x28],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2d3:
	/* 0x2d3: movzx  ecx,WORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_2d8:
	/* 0x2d8: movzx  eax,WORD PTR [rsp+0x12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18ULL);
x86_l_2dd:
	/* 0x2dd: jmp    3c4 <tail_nodeport_nat_ingress_ipv4+0x3c4> */
	X86_SIM_X86_JMP(0x2dd, 0x3c4, x86_l_3c4);
x86_l_2e2:
	/* 0x2e2: mov    QWORD PTR [rsp+0x60],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860417ULL);
x86_l_2eb:
	/* 0x2eb: mov    QWORD PTR [rsp+0x68],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2f0:
	/* 0x2f0: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2f5:
	/* 0x2f5: mov    rdi,QWORD PTR [rip+0x23c0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_2fc:
	/* 0x2fc: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_301:
	/* 0x301: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_306:
	/* 0x306: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_308:
	/* 0x308: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30a:
	/* 0x30a: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_30f:
	/* 0x30f: mov    rsi,QWORD PTR [rip+0x23c0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_316:
	/* 0x316: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_31b:
	/* 0x31b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_31e:
	/* 0x31e: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_323:
	/* 0x323: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_325:
	/* 0x325: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_327:
	/* 0x327: add    rsp,0xc8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 200ULL);
x86_l_32e:
	/* 0x32e: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_32f:
	/* 0x32f: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_331:
	/* 0x331: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_333:
	/* 0x333: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_335:
	/* 0x335: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_337:
	/* 0x337: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_338:
	/* 0x338: jmp    1ee1 <tail_nodeport_nat_ingress_ipv4+0x1ee1> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_33d:
	/* 0x33d: test   r12,r10 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R10, X86_WIDTH_64);
x86_l_340:
	/* 0x340: jne    76 <tail_nodeport_nat_ingress_ipv4+0x76> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x340, 0x76, x86_l_76);
x86_l_346:
	/* 0x346: lea    rcx,[rax+r8*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_34a:
	/* 0x34a: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_34e:
	/* 0x34e: cmp    rcx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_351:
	/* 0x351: ja     76 <tail_nodeport_nat_ingress_ipv4+0x76> */
	X86_SIM_X86_JCC(X86_CC_A, 0x351, 0x76, x86_l_76);
x86_l_357:
	/* 0x357: lea    r14,[rax+r8*1] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_35b:
	/* 0x35b: mov    rdx,QWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35e:
	/* 0x35e: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_360:
	/* 0x360: je     501 <tail_nodeport_nat_ingress_ipv4+0x501> */
	X86_SIM_X86_JCC(X86_CC_E, 0x360, 0x501, x86_l_501);
x86_l_366:
	/* 0x366: mov    esi,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_368:
	/* 0x368: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_36b:
	/* 0x36b: movzx  edx,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_36e:
	/* 0x36e: mov    ebp,0xffffff53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967123ULL);
x86_l_373:
	/* 0x373: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_376:
	/* 0x376: je     4ce <tail_nodeport_nat_ingress_ipv4+0x4ce> */
	X86_SIM_X86_JCC(X86_CC_E, 0x376, 0x4ce, x86_l_4ce);
x86_l_37c:
	/* 0x37c: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_37f:
	/* 0x37f: jne    76 <tail_nodeport_nat_ingress_ipv4+0x76> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x37f, 0x76, x86_l_76);
x86_l_385:
	/* 0x385: cmp    sil,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_8, 15ULL);
x86_l_389:
	/* 0x389: ja     76 <tail_nodeport_nat_ingress_ipv4+0x76> */
	X86_SIM_X86_JCC(X86_CC_A, 0x389, 0x76, x86_l_76);
x86_l_38f:
	/* 0x38f: jmp    4d8 <tail_nodeport_nat_ingress_ipv4+0x4d8> */
	X86_SIM_X86_JMP(0x38f, 0x4d8, x86_l_4d8);
x86_l_394:
	/* 0x394: test   r12,r9 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R9, X86_WIDTH_64);
x86_l_397:
	/* 0x397: jne    13c6 <tail_nodeport_nat_ingress_ipv4+0x13c6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x397, 0x13c6, x86_l_13c6);
x86_l_39d:
	/* 0x39d: mov    QWORD PTR [rsp+0x28],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3a2:
	/* 0x3a2: lea    rcx,[rax+r8*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_3a6:
	/* 0x3a6: add    rcx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_3aa:
	/* 0x3aa: mov    ebp,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967161ULL);
x86_l_3af:
	/* 0x3af: cmp    rcx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_3b2:
	/* 0x3b2: ja     76 <tail_nodeport_nat_ingress_ipv4+0x76> */
	X86_SIM_X86_JCC(X86_CC_A, 0x3b2, 0x76, x86_l_76);
x86_l_3b8:
	/* 0x3b8: add    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_3bd:
	/* 0x3bd: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3bf:
	/* 0x3bf: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_3c1:
	/* 0x3c1: shr    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_3c4:
	/* 0x3c4: mov    WORD PTR [rsp+0x12],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_3c9:
	/* 0x3c9: mov    WORD PTR [rsp+0x10],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3ce:
	/* 0x3ce: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3d1:
	/* 0x3d1: rol    ax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_3d5:
	/* 0x3d5: mov    cl,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_3d7:
	/* 0x3d7: mov    ebp,0xffffff53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967123ULL);
x86_l_3dc:
	/* 0x3dc: cmp    ax,r14w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R14, X86_WIDTH_16);
x86_l_3e0:
	/* 0x3e0: jb     76 <tail_nodeport_nat_ingress_ipv4+0x76> */
	X86_SIM_X86_JCC(X86_CC_B, 0x3e0, 0x76, x86_l_76);
x86_l_3e6:
	/* 0x3e6: mov    DWORD PTR [rsp+0x30],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3ea:
	/* 0x3ea: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3ef:
	/* 0x3ef: mov    rdi,QWORD PTR [rip+0x23bc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_3f6:
	/* 0x3f6: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3fb:
	/* 0x3fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3fd:
	/* 0x3fd: mov    ebp,0xffffff59 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967129ULL);
x86_l_402:
	/* 0x402: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_405:
	/* 0x405: je     76 <tail_nodeport_nat_ingress_ipv4+0x76> */
	X86_SIM_X86_JCC(X86_CC_E, 0x405, 0x76, x86_l_76);
x86_l_40b:
	/* 0x40b: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_40e:
	/* 0x40e: mov    eax,DWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_411:
	/* 0x411: mov    DWORD PTR [rsp+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_415:
	/* 0x415: movzx  eax,WORD PTR [r15+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_41a:
	/* 0x41a: mov    WORD PTR [rsp+0x22],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_41f:
	/* 0x41f: mov    eax,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_423:
	/* 0x423: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_427:
	/* 0x427: movzx  eax,WORD PTR [rsp+0x12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18ULL);
x86_l_42c:
	/* 0x42c: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_431:
	/* 0x431: movzx  eax,BYTE PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 20ULL);
x86_l_436:
	/* 0x436: mov    BYTE PTR [rsp+0x24],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_43a:
	/* 0x43a: mov    BYTE PTR [rsp+0x25],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 158913789952ULL);
x86_l_43f:
	/* 0x43f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_444:
	/* 0x444: mov    rdi,QWORD PTR [rip+0x23bc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_44b:
	/* 0x44b: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_450:
	/* 0x450: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_452:
	/* 0x452: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_455:
	/* 0x455: jne    632 <tail_nodeport_nat_ingress_ipv4+0x632> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x455, 0x632, x86_l_632);
x86_l_45b:
	/* 0x45b: mov    QWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_467:
	/* 0x467: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_470:
	/* 0x470: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_479:
	/* 0x479: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_482:
	/* 0x482: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_48b:
	/* 0x48b: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_48f:
	/* 0x48f: mov    DWORD PTR [rsp+0x80],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_496:
	/* 0x496: movzx  eax,WORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_49b:
	/* 0x49b: mov    WORD PTR [rsp+0x84],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_4a3:
	/* 0x4a3: mov    rax,QWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a7:
	/* 0x4a7: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_4ac:
	/* 0x4ac: mov    rax,QWORD PTR [rip+0x23bc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_4b3:
	/* 0x4b3: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4b6:
	/* 0x4b6: je     5e8 <tail_nodeport_nat_ingress_ipv4+0x5e8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4b6, 0x5e8, x86_l_5e8);
x86_l_4bc:
	/* 0x4bc: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_4c1:
	/* 0x4c1: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4c3:
	/* 0x4c3: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_4c5:
	/* 0x4c5: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_4c9:
	/* 0x4c9: jmp    60b <tail_nodeport_nat_ingress_ipv4+0x60b> */
	X86_SIM_X86_JMP(0x4c9, 0x60b, x86_l_60b);
x86_l_4ce:
	/* 0x4ce: cmp    sil,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_8, 1ULL);
x86_l_4d2:
	/* 0x4d2: ja     76 <tail_nodeport_nat_ingress_ipv4+0x76> */
	X86_SIM_X86_JCC(X86_CC_A, 0x4d2, 0x76, x86_l_76);
x86_l_4d8:
	/* 0x4d8: mov    QWORD PTR [rsp+0x66],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 438086664192ULL);
x86_l_4e1:
	/* 0x4e1: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_4ea:
	/* 0x4ea: lea    rdx,[rax+r8*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_4ee:
	/* 0x4ee: add    rdx,0x1c */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 28ULL);
x86_l_4f2:
	/* 0x4f2: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_4f5:
	/* 0x4f5: jbe    516 <tail_nodeport_nat_ingress_ipv4+0x516> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x4f5, 0x516, x86_l_516);
x86_l_4f7:
	/* 0x4f7: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_4fc:
	/* 0x4fc: jmp    76 <tail_nodeport_nat_ingress_ipv4+0x76> */
	X86_SIM_X86_JMP(0x4fc, 0x76, x86_l_76);
x86_l_501:
	/* 0x501: mov    QWORD PTR [rsp+0x28],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_506:
	/* 0x506: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_50a:
	/* 0x50a: mov    WORD PTR [rsp+0x10],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_50f:
	/* 0x50f: mov    cl,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 4ULL);
x86_l_511:
	/* 0x511: jmp    3e6 <tail_nodeport_nat_ingress_ipv4+0x3e6> */
	X86_SIM_X86_JMP(0x511, 0x3e6, x86_l_3e6);
x86_l_516:
	/* 0x516: mov    edx,DWORD PTR [rcx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_519:
	/* 0x519: mov    rsi,QWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_51d:
	/* 0x51d: mov    edi,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_51f:
	/* 0x51f: mov    rcx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_64);
x86_l_522:
	/* 0x522: shr    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_526:
	/* 0x526: mov    BYTE PTR [rsp+0x6c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_52a:
	/* 0x52a: mov    DWORD PTR [rsp+0x64],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 100ULL);
x86_l_52e:
	/* 0x52e: shr    rsi,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_532:
	/* 0x532: mov    DWORD PTR [rsp+0x60],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_536:
	/* 0x536: mov    BYTE PTR [rsp+0x6d],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 468151435265ULL);
x86_l_53b:
	/* 0x53b: lea    rsi,[r8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_53f:
	/* 0x53f: shl    edi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHL, 2ULL);
x86_l_542:
	/* 0x542: and    edi,0x3c */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 60ULL);
x86_l_545:
	/* 0x545: add    esi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_547:
	/* 0x547: cmp    cl,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_54a:
	/* 0x54a: je     999 <tail_nodeport_nat_ingress_ipv4+0x999> */
	X86_SIM_X86_JCC(X86_CC_E, 0x54a, 0x999, x86_l_999);
x86_l_550:
	/* 0x550: movzx  ecx,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_553:
	/* 0x553: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_556:
	/* 0x556: je     561 <tail_nodeport_nat_ingress_ipv4+0x561> */
	X86_SIM_X86_JCC(X86_CC_E, 0x556, 0x561, x86_l_561);
x86_l_558:
	/* 0x558: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_55b:
	/* 0x55b: jne    76 <tail_nodeport_nat_ingress_ipv4+0x76> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x55b, 0x76, x86_l_76);
x86_l_561:
	/* 0x561: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_563:
	/* 0x563: lea    rdx,[rax+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_567:
	/* 0x567: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_56b:
	/* 0x56b: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_56e:
	/* 0x56e: ja     4f7 <tail_nodeport_nat_ingress_ipv4+0x4f7> */
	X86_SIM_X86_JCC(X86_CC_A, 0x56e, 0x4f7, x86_l_4f7);
x86_l_570:
	/* 0x570: mov    QWORD PTR [rsp+0x40],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_575:
	/* 0x575: mov    QWORD PTR [rsp+0x30],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_57a:
	/* 0x57a: mov    QWORD PTR [rsp+0x28],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_57f:
	/* 0x57f: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_582:
	/* 0x582: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_584:
	/* 0x584: mov    DWORD PTR [rsp+0x68],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_588:
	/* 0x588: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_58a:
	/* 0x58a: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_58f:
	/* 0x58f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_594:
	/* 0x594: mov    rdi,QWORD PTR [rip+0x23bc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_59b:
	/* 0x59b: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_5a0:
	/* 0x5a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a2:
	/* 0x5a2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5a5:
	/* 0x5a5: je     76 <tail_nodeport_nat_ingress_ipv4+0x76> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5a5, 0x76, x86_l_76);
x86_l_5ab:
	/* 0x5ab: mov    r10,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R10, X86_RAX, X86_WIDTH_64);
x86_l_5ae:
	/* 0x5ae: movzx  ecx,BYTE PTR [rsp+0x6c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 108ULL);
x86_l_5b3:
	/* 0x5b3: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_5b5:
	/* 0x5b5: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_5b8:
	/* 0x5b8: je     c62 <tail_nodeport_nat_ingress_ipv4+0xc62> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5b8, 0xc62, x86_l_c62);
x86_l_5be:
	/* 0x5be: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_5c1:
	/* 0x5c1: jne    c8b <tail_nodeport_nat_ingress_ipv4+0xc8b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x5c1, 0xc8b, x86_l_c8b);
x86_l_5c7:
	/* 0x5c7: sub    r15,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R14, X86_WIDTH_64, X86_ALU_SUB);
x86_l_5ca:
	/* 0x5ca: mov    edx,0xfffffff8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967288ULL);
x86_l_5cf:
	/* 0x5cf: add    rdx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5d2:
	/* 0x5d2: mov    edx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_5d4:
	/* 0x5d4: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_5d9:
	/* 0x5d9: add    esi,0x12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 18ULL);
x86_l_5dc:
	/* 0x5dc: cmp    rdx,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_5df:
	/* 0x5df: setae  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_AE);
x86_l_5e3:
	/* 0x5e3: jmp    c8e <tail_nodeport_nat_ingress_ipv4+0xc8e> */
	X86_SIM_X86_JMP(0x5e3, 0xc8e, x86_l_c8e);
x86_l_5e8:
	/* 0x5e8: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_5ed:
	/* 0x5ed: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5ef:
	/* 0x5ef: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_5f1:
	/* 0x5f1: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_5f5:
	/* 0x5f5: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_5ff:
	/* 0x5ff: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_602:
	/* 0x602: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_607:
	/* 0x607: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_60b:
	/* 0x60b: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_610:
	/* 0x610: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_615:
	/* 0x615: mov    rdi,QWORD PTR [rip+0x23bc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_61c:
	/* 0x61c: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_621:
	/* 0x621: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_626:
	/* 0x626: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_628:
	/* 0x628: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_62a:
	/* 0x62a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_62c:
	/* 0x62c: js     76 <tail_nodeport_nat_ingress_ipv4+0x76> */
	X86_SIM_X86_JCC(X86_CC_S, 0x62c, 0x76, x86_l_76);
x86_l_632:
	/* 0x632: cmp    QWORD PTR [r15+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_637:
	/* 0x637: je     a99 <tail_nodeport_nat_ingress_ipv4+0xa99> */
	X86_SIM_X86_JCC(X86_CC_E, 0x637, 0xa99, x86_l_a99);
x86_l_63d:
	/* 0x63d: movzx  eax,WORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 20ULL);
x86_l_642:
	/* 0x642: mov    WORD PTR [rsp+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_647:
	/* 0x647: movzx  ecx,WORD PTR [rsp+0x12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18ULL);
x86_l_64c:
	/* 0x64c: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_651:
	/* 0x651: mov    QWORD PTR [rsp+0x18],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_656:
	/* 0x656: mov    edx,DWORD PTR [r15+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_65a:
	/* 0x65a: mov    DWORD PTR [rsp+0x18],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_65e:
	/* 0x65e: movzx  edx,WORD PTR [r15+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_663:
	/* 0x663: mov    WORD PTR [rsp+0x22],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_668:
	/* 0x668: mov    WORD PTR [rsp+0x20],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_66d:
	/* 0x66d: movzx  ebp,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_670:
	/* 0x670: cmp    bp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_16, 6ULL);
x86_l_674:
	/* 0x674: jne    67f <tail_nodeport_nat_ingress_ipv4+0x67f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x674, 0x67f, x86_l_67f);
x86_l_676:
	/* 0x676: mov    rdi,QWORD PTR [rip+0x23bc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct4_global)));
x86_l_67d:
	/* 0x67d: jmp    686 <tail_nodeport_nat_ingress_ipv4+0x686> */
	X86_SIM_X86_JMP(0x67d, 0x686, x86_l_686);
x86_l_67f:
	/* 0x67f: mov    rdi,QWORD PTR [rip+0x23bc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct_any4_global)));
x86_l_686:
	/* 0x686: movabs rcx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2199023255552ULL);
x86_l_690:
	/* 0x690: movabs rdx,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1099511627776ULL);
x86_l_69a:
	/* 0x69a: mov    BYTE PTR [rsp+0x25],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 158913789952ULL);
x86_l_69f:
	/* 0x69f: mov    rax,QWORD PTR [rip+0x23bc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_ipv4_fragments)));
x86_l_6a6:
	/* 0x6a6: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6a9:
	/* 0x6a9: je     74a <tail_nodeport_nat_ingress_ipv4+0x74a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6a9, 0x74a, x86_l_74a);
x86_l_6af:
	/* 0x6af: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_6b2:
	/* 0x6b2: and    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_AND);
x86_l_6b5:
	/* 0x6b5: je     74a <tail_nodeport_nat_ingress_ipv4+0x74a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6b5, 0x74a, x86_l_74a);
x86_l_6bb:
	/* 0x6bb: mov    QWORD PTR [rsp+0x58],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_6c0:
	/* 0x6c0: mov    DWORD PTR [rsp+0x40],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_6c4:
	/* 0x6c4: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_6c7:
	/* 0x6c7: mov    r15,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RCX, X86_WIDTH_64);
x86_l_6ca:
	/* 0x6ca: mov    r14,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6ce:
	/* 0x6ce: sub    r14,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 0ULL);
x86_l_6d1:
	/* 0x6d1: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_6da:
	/* 0x6da: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_6e3:
	/* 0x6e3: movabs rax,0x6c03a50109 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 463917613321ULL);
x86_l_6ed:
	/* 0x6ed: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_6f2:
	/* 0x6f2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6f7:
	/* 0x6f7: mov    rdi,QWORD PTR [rip+0x23bc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_6fe:
	/* 0x6fe: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_703:
	/* 0x703: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_705:
	/* 0x705: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_708:
	/* 0x708: je     713 <tail_nodeport_nat_ingress_ipv4+0x713> */
	X86_SIM_X86_JCC(X86_CC_E, 0x708, 0x713, x86_l_713);
x86_l_70a:
	/* 0x70a: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_70d:
	/* 0x70d: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_711:
	/* 0x711: jmp    73b <tail_nodeport_nat_ingress_ipv4+0x73b> */
	X86_SIM_X86_JMP(0x711, 0x73b, x86_l_73b);
x86_l_713:
	/* 0x713: mov    QWORD PTR [rsp+0x60],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860417ULL);
x86_l_71c:
	/* 0x71c: mov    QWORD PTR [rsp+0x68],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_721:
	/* 0x721: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_726:
	/* 0x726: mov    rdi,QWORD PTR [rip+0x23bc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_72d:
	/* 0x72d: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_732:
	/* 0x732: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_737:
	/* 0x737: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_739:
	/* 0x739: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_73b:
	/* 0x73b: mov    rcx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_73e:
	/* 0x73e: mov    r15,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_64);
x86_l_741:
	/* 0x741: mov    ebp,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_745:
	/* 0x745: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_74a:
	/* 0x74a: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_74c:
	/* 0x74c: cmp    bp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_16, 6ULL);
x86_l_750:
	/* 0x750: jne    77f <tail_nodeport_nat_ingress_ipv4+0x77f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x750, 0x77f, x86_l_77f);
x86_l_752:
	/* 0x752: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_755:
	/* 0x755: mov    r14d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 0ULL);
x86_l_75b:
	/* 0x75b: and    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_75e:
	/* 0x75e: jne    7ac <tail_nodeport_nat_ingress_ipv4+0x7ac> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x75e, 0x7ac, x86_l_7ac);
x86_l_760:
	/* 0x760: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_763:
	/* 0x763: movzx  ecx,r13b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R13, X86_WIDTH_32, X86_WIDTH_8);
x86_l_767:
	/* 0x767: lea    rdx,[rax+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_76b:
	/* 0x76b: add    rdx,0x1c */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 28ULL);
x86_l_76f:
	/* 0x76f: cmp    rdx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_773:
	/* 0x773: jbe    784 <tail_nodeport_nat_ingress_ipv4+0x784> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x773, 0x784, x86_l_784);
x86_l_775:
	/* 0x775: mov    ebp,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967161ULL);
x86_l_77a:
	/* 0x77a: jmp    76 <tail_nodeport_nat_ingress_ipv4+0x76> */
	X86_SIM_X86_JMP(0x77a, 0x76, x86_l_76);
x86_l_77f:
	/* 0x77f: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_782:
	/* 0x782: jmp    7ac <tail_nodeport_nat_ingress_ipv4+0x7ac> */
	X86_SIM_X86_JMP(0x782, 0x7ac, x86_l_7ac);
x86_l_784:
	/* 0x784: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_787:
	/* 0x787: movzx  edx,WORD PTR [rax+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 26ULL);
x86_l_78b:
	/* 0x78b: mov    eax,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_78d:
	/* 0x78d: and    eax,0x1200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4608ULL);
x86_l_792:
	/* 0x792: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_795:
	/* 0x795: cmp    eax,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 512ULL);
x86_l_79a:
	/* 0x79a: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_79d:
	/* 0x79d: test   edx,0x500 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_32, 1280ULL);
x86_l_7a3:
	/* 0x7a3: jne    1acc <tail_nodeport_nat_ingress_ipv4+0x1acc> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x7a3, 0x1acc, x86_l_1acc);
x86_l_7a9:
	/* 0x7a9: mov    r14b,al */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_8);
x86_l_7ac:
	/* 0x7ac: mov    DWORD PTR [rsp+0x3c],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_7b0:
	/* 0x7b0: mov    QWORD PTR [rsp+0x58],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_7b5:
	/* 0x7b5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7ba:
	/* 0x7ba: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_7bf:
	/* 0x7bf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7c1:
	/* 0x7c1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7c4:
	/* 0x7c4: je     a8b <tail_nodeport_nat_ingress_ipv4+0xa8b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7c4, 0xa8b, x86_l_a8b);
x86_l_7ca:
	/* 0x7ca: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_7cd:
	/* 0x7cd: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_7d0:
	/* 0x7d0: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_7d2:
	/* 0x7d2: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_7d4:
	/* 0x7d4: test   cl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_7d7:
	/* 0x7d7: je     8e1 <tail_nodeport_nat_ingress_ipv4+0x8e1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7d7, 0x8e1, x86_l_8e1);
x86_l_7dd:
	/* 0x7dd: mov    DWORD PTR [rsp+0x40],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_7e1:
	/* 0x7e1: mov    rsi,QWORD PTR [rip+0x23bc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_7e8:
	/* 0x7e8: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7eb:
	/* 0x7eb: mov    edx,DWORD PTR [rsp+0x3c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_7ef:
	/* 0x7ef: je     800 <tail_nodeport_nat_ingress_ipv4+0x800> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7ef, 0x800, x86_l_800);
x86_l_7f1:
	/* 0x7f1: mov    rcx,QWORD PTR [rip+0x23bc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_7f8:
	/* 0x7f8: imul   ebp,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_7fb:
	/* 0x7fb: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_7fe:
	/* 0x7fe: jmp    805 <tail_nodeport_nat_ingress_ipv4+0x805> */
	X86_SIM_X86_JMP(0x7fe, 0x805, x86_l_805);
x86_l_800:
	/* 0x800: mov    ebp,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_805:
	/* 0x805: cmp    WORD PTR [rsp+0x40],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 274877906950ULL);
x86_l_80b:
	/* 0x80b: jne    83e <tail_nodeport_nat_ingress_ipv4+0x83e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x80b, 0x83e, x86_l_83e);
x86_l_80d:
	/* 0x80d: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_80f:
	/* 0x80f: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_811:
	/* 0x811: shr    ecx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_814:
	/* 0x814: and    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_817:
	/* 0x817: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_819:
	/* 0x819: mov    WORD PTR [rdi+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_81d:
	/* 0x81d: test   al,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 16ULL);
x86_l_81f:
	/* 0x81f: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_824:
	/* 0x824: mov    ebp,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 21600ULL);
x86_l_829:
	/* 0x829: cmove  ebp,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_82c:
	/* 0x82c: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_82f:
	/* 0x82f: je     83e <tail_nodeport_nat_ingress_ipv4+0x83e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x82f, 0x83e, x86_l_83e);
x86_l_831:
	/* 0x831: mov    rax,QWORD PTR [rip+0x23bc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_838:
	/* 0x838: imul   ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_83b:
	/* 0x83b: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_83e:
	/* 0x83e: mov    QWORD PTR [rsp+0xa8],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_846:
	/* 0x846: movzx  r15d,dx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_RDX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_84a:
	/* 0x84a: shr    r15d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_84e:
	/* 0x84e: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_851:
	/* 0x851: je     862 <tail_nodeport_nat_ingress_ipv4+0x862> */
	X86_SIM_X86_JCC(X86_CC_E, 0x851, 0x862, x86_l_862);
x86_l_853:
	/* 0x853: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_858:
	/* 0x858: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_85a:
	/* 0x85a: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_85c:
	/* 0x85c: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_860:
	/* 0x860: jmp    885 <tail_nodeport_nat_ingress_ipv4+0x885> */
	X86_SIM_X86_JMP(0x860, 0x885, x86_l_885);
x86_l_862:
	/* 0x862: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_867:
	/* 0x867: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_869:
	/* 0x869: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_86b:
	/* 0x86b: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_86f:
	/* 0x86f: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_879:
	/* 0x879: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_87c:
	/* 0x87c: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_881:
	/* 0x881: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_885:
	/* 0x885: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_887:
	/* 0x887: mov    rdi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_88f:
	/* 0x88f: mov    DWORD PTR [rdi+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_892:
	/* 0x892: movzx  ecx,BYTE PTR [rdi+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_896:
	/* 0x896: mov    edx,DWORD PTR [rdi+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_899:
	/* 0x899: and    r15b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_89d:
	/* 0x89d: mov    rsi,QWORD PTR [rip+0x23bc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_8a4:
	/* 0x8a4: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8a7:
	/* 0x8a7: je     8ba <tail_nodeport_nat_ingress_ipv4+0x8ba> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8a7, 0x8ba, x86_l_8ba);
x86_l_8a9:
	/* 0x8a9: mov    rsi,QWORD PTR [rip+0x23bc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_8b0:
	/* 0x8b0: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8b2:
	/* 0x8b2: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_8b5:
	/* 0x8b5: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_8b8:
	/* 0x8b8: jmp    8bf <tail_nodeport_nat_ingress_ipv4+0x8bf> */
	X86_SIM_X86_JMP(0x8b8, 0x8bf, x86_l_8bf);
x86_l_8ba:
	/* 0x8ba: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_8bf:
	/* 0x8bf: mov    ebp,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_8c3:
	/* 0x8c3: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_8c5:
	/* 0x8c5: or     r15b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_8c8:
	/* 0x8c8: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_8ca:
	/* 0x8ca: jb     8d1 <tail_nodeport_nat_ingress_ipv4+0x8d1> */
	X86_SIM_X86_JCC(X86_CC_B, 0x8ca, 0x8d1, x86_l_8d1);
x86_l_8cc:
	/* 0x8cc: cmp    cl,r15b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R15, X86_WIDTH_8);
x86_l_8cf:
	/* 0x8cf: je     8e1 <tail_nodeport_nat_ingress_ipv4+0x8e1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8cf, 0x8e1, x86_l_8e1);
x86_l_8d1:
	/* 0x8d1: mov    BYTE PTR [rdi+0x2b],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_8d5:
	/* 0x8d5: mov    DWORD PTR [rdi+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_8d8:
	/* 0x8d8: mov    rax,QWORD PTR [rip+0x23bc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_8df:
	/* 0x8df: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8e1:
	/* 0x8e1: mov    rax,QWORD PTR [rip+0x23bc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_8e8:
	/* 0x8e8: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8eb:
	/* 0x8eb: mov    edx,DWORD PTR [rsp+0x3c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_8ef:
	/* 0x8ef: je     902 <tail_nodeport_nat_ingress_ipv4+0x902> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8ef, 0x902, x86_l_902);
x86_l_8f1:
	/* 0x8f1: inc QWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RDI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 16ULL);
x86_l_8f6:
	/* 0x8f6: mov    rax,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8fa:
	/* 0x8fa: sub    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 0ULL);
x86_l_8fd:
	/* 0x8fd: add QWORD PTR [rdi+0x18],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RDI, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_902:
	/* 0x902: cmp    r14d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 2ULL);
x86_l_906:
	/* 0x906: je     954 <tail_nodeport_nat_ingress_ipv4+0x954> */
	X86_SIM_X86_JCC(X86_CC_E, 0x906, 0x954, x86_l_954);
x86_l_908:
	/* 0x908: cmp    r14d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1ULL);
x86_l_90c:
	/* 0x90c: jne    a94 <tail_nodeport_nat_ingress_ipv4+0xa94> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x90c, 0xa94, x86_l_a94);
x86_l_912:
	/* 0x912: movzx  eax,WORD PTR [rdi+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_916:
	/* 0x916: test   al,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 3ULL);
x86_l_918:
	/* 0x918: je     a94 <tail_nodeport_nat_ingress_ipv4+0xa94> */
	X86_SIM_X86_JCC(X86_CC_E, 0x918, 0xa94, x86_l_a94);
x86_l_91e:
	/* 0x91e: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_920:
	/* 0x920: mov    WORD PTR [rdi+0x2a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 180388626432ULL);
x86_l_926:
	/* 0x926: and    eax,0xffec */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 65516ULL);
x86_l_92b:
	/* 0x92b: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_92e:
	/* 0x92e: mov    WORD PTR [rdi+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_932:
	/* 0x932: mov    rcx,QWORD PTR [rip+0x23bc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_939:
	/* 0x939: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_93c:
	/* 0x93c: je     1c5a <tail_nodeport_nat_ingress_ipv4+0x1c5a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x93c, 0x1c5a, x86_l_1c5a);
x86_l_942:
	/* 0x942: mov    rcx,QWORD PTR [rip+0x23bc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_949:
	/* 0x949: imul   ebp,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_94c:
	/* 0x94c: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_94f:
	/* 0x94f: jmp    1c5f <tail_nodeport_nat_ingress_ipv4+0x1c5f> */
	X86_SIM_X86_JMP(0x94f, 0x1c5f, x86_l_1c5f);
x86_l_954:
	/* 0x954: mov    eax,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_956:
	/* 0x956: shr    eax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_959:
	/* 0x959: and    eax,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2ULL);
x86_l_95c:
	/* 0x95c: or     ax,WORD PTR [rdi+0x24] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RDI, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 36ULL);
x86_l_960:
	/* 0x960: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_962:
	/* 0x962: or     ecx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_OR, 1ULL);
x86_l_965:
	/* 0x965: mov    WORD PTR [rdi+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_969:
	/* 0x969: mov    rcx,QWORD PTR [rip+0x23bc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_970:
	/* 0x970: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_972:
	/* 0x972: test   al,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 2ULL);
x86_l_974:
	/* 0x974: je     a94 <tail_nodeport_nat_ingress_ipv4+0xa94> */
	X86_SIM_X86_JCC(X86_CC_E, 0x974, 0xa94, x86_l_a94);
x86_l_97a:
	/* 0x97a: mov    rcx,QWORD PTR [rip+0x23bc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_981:
	/* 0x981: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_984:
	/* 0x984: je     9f9 <tail_nodeport_nat_ingress_ipv4+0x9f9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x984, 0x9f9, x86_l_9f9);
x86_l_986:
	/* 0x986: mov    rax,QWORD PTR [rip+0x23bc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_98d:
	/* 0x98d: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_98f:
	/* 0x98f: add    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_991:
	/* 0x991: lea    ebp,[rax+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_994:
	/* 0x994: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_997:
	/* 0x997: jmp    9fe <tail_nodeport_nat_ingress_ipv4+0x9fe> */
	X86_SIM_X86_JMP(0x997, 0x9fe, x86_l_9fe);
x86_l_999:
	/* 0x999: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_99b:
	/* 0x99b: lea    rdx,[rax+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_99f:
	/* 0x99f: inc    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_9a2:
	/* 0x9a2: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_9a5:
	/* 0x9a5: ja     4f7 <tail_nodeport_nat_ingress_ipv4+0x4f7> */
	X86_SIM_X86_JCC(X86_CC_A, 0x9a5, 0x4f7, x86_l_4f7);
x86_l_9ab:
	/* 0x9ab: lea    rdx,[rax+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_9af:
	/* 0x9af: movzx  edx,BYTE PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_9b2:
	/* 0x9b2: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_9b4:
	/* 0x9b4: je     76 <tail_nodeport_nat_ingress_ipv4+0x76> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9b4, 0x76, x86_l_76);
x86_l_9ba:
	/* 0x9ba: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_9bd:
	/* 0x9bd: jne    d9e <tail_nodeport_nat_ingress_ipv4+0xd9e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x9bd, 0xd9e, x86_l_d9e);
x86_l_9c3:
	/* 0x9c3: lea    rdx,[rax+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_9c7:
	/* 0x9c7: add    rdx,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 6ULL);
x86_l_9cb:
	/* 0x9cb: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_9ce:
	/* 0x9ce: ja     4f7 <tail_nodeport_nat_ingress_ipv4+0x4f7> */
	X86_SIM_X86_JCC(X86_CC_A, 0x9ce, 0x4f7, x86_l_4f7);
x86_l_9d4:
	/* 0x9d4: mov    QWORD PTR [rsp+0x40],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_9d9:
	/* 0x9d9: mov    QWORD PTR [rsp+0x30],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9de:
	/* 0x9de: mov    QWORD PTR [rsp+0x28],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_9e3:
	/* 0x9e3: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_9e6:
	/* 0x9e6: movzx  eax,WORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_9ea:
	/* 0x9ea: mov    WORD PTR [rsp+0x68],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_9ef:
	/* 0x9ef: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_9f4:
	/* 0x9f4: jmp    58a <tail_nodeport_nat_ingress_ipv4+0x58a> */
	X86_SIM_X86_JMP(0x9f4, 0x58a, x86_l_58a);
x86_l_9f9:
	/* 0x9f9: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_9fe:
	/* 0x9fe: mov    r15,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDI, X86_WIDTH_64);
x86_l_a01:
	/* 0xa01: movzx  r14d,dx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_RDX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_a05:
	/* 0xa05: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_a09:
	/* 0xa09: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a0c:
	/* 0xa0c: je     a1d <tail_nodeport_nat_ingress_ipv4+0xa1d> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa0c, 0xa1d, x86_l_a1d);
x86_l_a0e:
	/* 0xa0e: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_a13:
	/* 0xa13: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a15:
	/* 0xa15: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_a17:
	/* 0xa17: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_a1b:
	/* 0xa1b: jmp    a40 <tail_nodeport_nat_ingress_ipv4+0xa40> */
	X86_SIM_X86_JMP(0xa1b, 0xa40, x86_l_a40);
x86_l_a1d:
	/* 0xa1d: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_a22:
	/* 0xa22: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a24:
	/* 0xa24: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_a26:
	/* 0xa26: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_a2a:
	/* 0xa2a: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_a34:
	/* 0xa34: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_a37:
	/* 0xa37: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_a3c:
	/* 0xa3c: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_a40:
	/* 0xa40: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_a42:
	/* 0xa42: mov    DWORD PTR [r15+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a46:
	/* 0xa46: movzx  ecx,BYTE PTR [r15+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_a4b:
	/* 0xa4b: mov    edx,DWORD PTR [r15+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_a4f:
	/* 0xa4f: and    r14b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_a53:
	/* 0xa53: mov    rsi,QWORD PTR [rip+0x23bc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_a5a:
	/* 0xa5a: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a5d:
	/* 0xa5d: je     a70 <tail_nodeport_nat_ingress_ipv4+0xa70> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa5d, 0xa70, x86_l_a70);
x86_l_a5f:
	/* 0xa5f: mov    rsi,QWORD PTR [rip+0x23bc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_a66:
	/* 0xa66: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a68:
	/* 0xa68: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_a6b:
	/* 0xa6b: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_a6e:
	/* 0xa6e: jmp    a75 <tail_nodeport_nat_ingress_ipv4+0xa75> */
	X86_SIM_X86_JMP(0xa6e, 0xa75, x86_l_a75);
x86_l_a70:
	/* 0xa70: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_a75:
	/* 0xa75: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_a77:
	/* 0xa77: or     r14b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_a7a:
	/* 0xa7a: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_a7c:
	/* 0xa7c: jb     a83 <tail_nodeport_nat_ingress_ipv4+0xa83> */
	X86_SIM_X86_JCC(X86_CC_B, 0xa7c, 0xa83, x86_l_a83);
x86_l_a7e:
	/* 0xa7e: cmp    cl,r14b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R14, X86_WIDTH_8);
x86_l_a81:
	/* 0xa81: je     a94 <tail_nodeport_nat_ingress_ipv4+0xa94> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa81, 0xa94, x86_l_a94);
x86_l_a83:
	/* 0xa83: mov    BYTE PTR [r15+0x2b],r14b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R14, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_a87:
	/* 0xa87: mov    DWORD PTR [r15+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_a8b:
	/* 0xa8b: mov    rax,QWORD PTR [rip+0x23bc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_a92:
	/* 0xa92: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a94:
	/* 0xa94: mov    r15,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_a99:
	/* 0xa99: movzx  r9d,WORD PTR [r15+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_a9e:
	/* 0xa9e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_aa0:
	/* 0xaa0: movzx  r8d,BYTE PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 20ULL);
x86_l_aa6:
	/* 0xaa6: mov    edx,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_aaa:
	/* 0xaaa: mov    esi,DWORD PTR [r15+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_aae:
	/* 0xaae: movzx  r10d,WORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_ab4:
	/* 0xab4: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_ab6:
	/* 0xab6: mov    r14d,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_abb:
	/* 0xabb: jne    acb <tail_nodeport_nat_ingress_ipv4+0xacb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xabb, 0xacb, x86_l_acb);
x86_l_abd:
	/* 0xabd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_abf:
	/* 0xabf: jne    acb <tail_nodeport_nat_ingress_ipv4+0xacb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xabf, 0xacb, x86_l_acb);
x86_l_ac1:
	/* 0xac1: cmp    r10w,r9w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R10, X86_R9, X86_WIDTH_16);
x86_l_ac5:
	/* 0xac5: je     e66 <tail_nodeport_nat_ingress_ipv4+0xe66> */
	X86_SIM_X86_JCC(X86_CC_E, 0xac5, 0xe66, x86_l_e66);
x86_l_acb:
	/* 0xacb: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_acd:
	/* 0xacd: add    edx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_acf:
	/* 0xacf: adc    edx,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_ad2:
	/* 0xad2: mov    rcx,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ad5:
	/* 0xad5: mov    rdi,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ad9:
	/* 0xad9: lea    r11,[rcx+0x22] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_add:
	/* 0xadd: mov    ebp,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967155ULL);
x86_l_ae2:
	/* 0xae2: cmp    r11,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R11, X86_RDI, X86_WIDTH_64);
x86_l_ae5:
	/* 0xae5: ja     76 <tail_nodeport_nat_ingress_ipv4+0x76> */
	X86_SIM_X86_JCC(X86_CC_A, 0xae5, 0x76, x86_l_76);
x86_l_aeb:
	/* 0xaeb: movzx  r11d,WORD PTR [rcx+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 24ULL);
x86_l_af0:
	/* 0xaf0: not    r11d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_af3:
	/* 0xaf3: add    r11d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_af6:
	/* 0xaf6: adc    r11d,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_afa:
	/* 0xafa: movzx  ebp,r11w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_R11, X86_WIDTH_32, X86_WIDTH_16);
x86_l_afe:
	/* 0xafe: shr    r11d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_b02:
	/* 0xb02: add    r11d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_b05:
	/* 0xb05: mov    ebp,r11d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R11, X86_WIDTH_32);
x86_l_b08:
	/* 0xb08: shr    ebp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_b0b:
	/* 0xb0b: add    ebp,r11d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R11, X86_WIDTH_32, X86_ALU_ADD);
x86_l_b0e:
	/* 0xb0e: mov    DWORD PTR [rcx+0x1e],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_b11:
	/* 0xb11: not    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_b13:
	/* 0xb13: mov    WORD PTR [rcx+0x18],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b17:
	/* 0xb17: movabs rsi,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 2199023255552ULL);
x86_l_b21:
	/* 0xb21: test   r12,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_RSI, X86_WIDTH_64);
x86_l_b24:
	/* 0xb24: jne    e66 <tail_nodeport_nat_ingress_ipv4+0xe66> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb24, 0xe66, x86_l_e66);
x86_l_b2a:
	/* 0xb2a: mov    sil,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_8, 1ULL);
x86_l_b2d:
	/* 0xb2d: cmp    r8d,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 58ULL);
x86_l_b31:
	/* 0xb31: je     b4f <tail_nodeport_nat_ingress_ipv4+0xb4f> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb31, 0xb4f, x86_l_b4f);
x86_l_b33:
	/* 0xb33: cmp    r8d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 17ULL);
x86_l_b37:
	/* 0xb37: je     b46 <tail_nodeport_nat_ingress_ipv4+0xb46> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb37, 0xb46, x86_l_b46);
x86_l_b39:
	/* 0xb39: cmp    r8d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 6ULL);
x86_l_b3d:
	/* 0xb3d: jne    b56 <tail_nodeport_nat_ingress_ipv4+0xb56> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb3d, 0xb56, x86_l_b56);
x86_l_b3f:
	/* 0xb3f: mov    r11w,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R11, X86_WIDTH_16, 16ULL);
x86_l_b44:
	/* 0xb44: jmp    b59 <tail_nodeport_nat_ingress_ipv4+0xb59> */
	X86_SIM_X86_JMP(0xb44, 0xb59, x86_l_b59);
x86_l_b46:
	/* 0xb46: mov    r11w,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R11, X86_WIDTH_16, 6ULL);
x86_l_b4b:
	/* 0xb4b: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b4d:
	/* 0xb4d: jmp    b59 <tail_nodeport_nat_ingress_ipv4+0xb59> */
	X86_SIM_X86_JMP(0xb4d, 0xb59, x86_l_b59);
x86_l_b4f:
	/* 0xb4f: mov    r11w,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R11, X86_WIDTH_16, 2ULL);
x86_l_b54:
	/* 0xb54: jmp    b59 <tail_nodeport_nat_ingress_ipv4+0xb59> */
	X86_SIM_X86_JMP(0xb54, 0xb59, x86_l_b59);
x86_l_b56:
	/* 0xb56: xor    r11d,r11d */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_R11, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b59:
	/* 0xb59: cmp    r10w,r9w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R10, X86_R9, X86_WIDTH_16);
x86_l_b5d:
	/* 0xb5d: jne    bb0 <tail_nodeport_nat_ingress_ipv4+0xbb0> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb5d, 0xbb0, x86_l_bb0);
x86_l_b5f:
	/* 0xb5f: test   r11w,r11w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R11, X86_R11, X86_WIDTH_16);
x86_l_b63:
	/* 0xb63: je     df9 <tail_nodeport_nat_ingress_ipv4+0xdf9> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb63, 0xdf9, x86_l_df9);
x86_l_b69:
	/* 0xb69: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b6e:
	/* 0xb6e: add    al,r11b */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R11, X86_WIDTH_8, X86_ALU_ADD);
x86_l_b71:
	/* 0xb71: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_b74:
	/* 0xb74: lea    r8,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_b78:
	/* 0xb78: add    r8,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_b7c:
	/* 0xb7c: mov    ebp,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967142ULL);
x86_l_b81:
	/* 0xb81: cmp    r8,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDI, X86_WIDTH_64);
x86_l_b84:
	/* 0xb84: ja     76 <tail_nodeport_nat_ingress_ipv4+0x76> */
	X86_SIM_X86_JCC(X86_CC_A, 0xb84, 0x76, x86_l_76);
x86_l_b8a:
	/* 0xb8a: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_b8d:
	/* 0xb8d: movzx  eax,WORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_b90:
	/* 0xb90: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b92:
	/* 0xb92: setne  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_NE);
x86_l_b96:
	/* 0xb96: or     dil,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_8, X86_ALU_OR);
x86_l_b99:
	/* 0xb99: cmp    dil,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_8, 1ULL);
x86_l_b9d:
	/* 0xb9d: jne    e66 <tail_nodeport_nat_ingress_ipv4+0xe66> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb9d, 0xe66, x86_l_e66);
x86_l_ba3:
	/* 0xba3: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_ba5:
	/* 0xba5: add    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_ba7:
	/* 0xba7: setb   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_B);
x86_l_bab:
	/* 0xbab: jmp    e3a <tail_nodeport_nat_ingress_ipv4+0xe3a> */
	X86_SIM_X86_JMP(0xbab, 0xe3a, x86_l_e3a);
x86_l_bb0:
	/* 0xbb0: cmp    r8d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 17ULL);
x86_l_bb4:
	/* 0xbb4: je     bd0 <tail_nodeport_nat_ingress_ipv4+0xbd0> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbb4, 0xbd0, x86_l_bd0);
x86_l_bb6:
	/* 0xbb6: cmp    r8d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 6ULL);
x86_l_bba:
	/* 0xbba: je     bd0 <tail_nodeport_nat_ingress_ipv4+0xbd0> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbba, 0xbd0, x86_l_bd0);
x86_l_bbc:
	/* 0xbbc: mov    ebp,0xffffff72 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967154ULL);
x86_l_bc1:
	/* 0xbc1: cmp    r8d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 1ULL);
x86_l_bc5:
	/* 0xbc5: jne    76 <tail_nodeport_nat_ingress_ipv4+0x76> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xbc5, 0x76, x86_l_76);
x86_l_bcb:
	/* 0xbcb: mov    r11w,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R11, X86_WIDTH_16, 2ULL);
x86_l_bd0:
	/* 0xbd0: add    r14b,BYTE PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RSP, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_bd5:
	/* 0xbd5: movzx  r14d,r14b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_R14, X86_WIDTH_32, X86_WIDTH_8);
x86_l_bd9:
	/* 0xbd9: lea    r15,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_bdd:
	/* 0xbdd: add    r15,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_be1:
	/* 0xbe1: mov    ebp,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967155ULL);
x86_l_be6:
	/* 0xbe6: cmp    r15,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R15, X86_RDI, X86_WIDTH_64);
x86_l_be9:
	/* 0xbe9: ja     76 <tail_nodeport_nat_ingress_ipv4+0x76> */
	X86_SIM_X86_JCC(X86_CC_A, 0xbe9, 0x76, x86_l_76);
x86_l_bef:
	/* 0xbef: add    r14,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_bf2:
	/* 0xbf2: mov    WORD PTR [r14],r9w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R9, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bf6:
	/* 0xbf6: mov    r14,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_bfb:
	/* 0xbfb: lea    ebp,[r14+r11*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R11, 0), 0ULL);
x86_l_bff:
	/* 0xbff: movzx  r14d,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_c03:
	/* 0xc03: lea    r15,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_c07:
	/* 0xc07: add    r15,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_c0b:
	/* 0xc0b: mov    ebp,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967142ULL);
x86_l_c10:
	/* 0xc10: cmp    r15,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R15, X86_RDI, X86_WIDTH_64);
x86_l_c13:
	/* 0xc13: ja     76 <tail_nodeport_nat_ingress_ipv4+0x76> */
	X86_SIM_X86_JCC(X86_CC_A, 0xc13, 0x76, x86_l_76);
x86_l_c19:
	/* 0xc19: add    r14,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_c1c:
	/* 0xc1c: test   sil,sil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_8);
x86_l_c1f:
	/* 0xc1f: jne    c2c <tail_nodeport_nat_ingress_ipv4+0xc2c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xc1f, 0xc2c, x86_l_c2c);
x86_l_c21:
	/* 0xc21: cmp    WORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c26:
	/* 0xc26: je     def <tail_nodeport_nat_ingress_ipv4+0xdef> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc26, 0xdef, x86_l_def);
x86_l_c2c:
	/* 0xc2c: movzx  ebp,r9w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_R9, X86_WIDTH_32, X86_WIDTH_16);
x86_l_c30:
	/* 0xc30: test   r10d,r10d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R10, X86_R10, X86_WIDTH_32);
x86_l_c33:
	/* 0xc33: je     da8 <tail_nodeport_nat_ingress_ipv4+0xda8> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc33, 0xda8, x86_l_da8);
x86_l_c39:
	/* 0xc39: not    r10d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_c3c:
	/* 0xc3c: add    r10d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_c3f:
	/* 0xc3f: adc    r10d,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_c43:
	/* 0xc43: movzx  r9d,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_c47:
	/* 0xc47: not    r9d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_c4a:
	/* 0xc4a: add    r9d,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R10, X86_WIDTH_32, X86_ALU_ADD);
x86_l_c4d:
	/* 0xc4d: jmp    db2 <tail_nodeport_nat_ingress_ipv4+0xdb2> */
	X86_SIM_X86_JMP(0xc4d, 0xdb2, x86_l_db2);
x86_l_c52:
	/* 0xc52: mov    DWORD PTR [rsp+0xb4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_c5d:
	/* 0xc5d: jmp    55 <tail_nodeport_nat_ingress_ipv4+0x55> */
	X86_SIM_X86_JMP(0xc5d, 0x55, x86_l_55);
x86_l_c62:
	/* 0xc62: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c65:
	/* 0xc65: mov    edx,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c69:
	/* 0xc69: lea    rsi,[rax+rdx*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_c6d:
	/* 0xc6d: add    rsi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_c71:
	/* 0xc71: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_c76:
	/* 0xc76: cmp    rsi,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_c7a:
	/* 0xc7a: ja     76 <tail_nodeport_nat_ingress_ipv4+0x76> */
	X86_SIM_X86_JCC(X86_CC_A, 0xc7a, 0x76, x86_l_76);
x86_l_c80:
	/* 0xc80: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_c83:
	/* 0xc83: cmp    WORD PTR [rax+0x6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 25769803776ULL);
x86_l_c88:
	/* 0xc88: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_c8b:
	/* 0xc8b: mov    sil,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_8, 1ULL);
x86_l_c8e:
	/* 0xc8e: mov    edx,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_c92:
	/* 0xc92: mov    rdi,r10 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R10, X86_WIDTH_64);
x86_l_c95:
	/* 0xc95: mov    r8d,DWORD PTR [r10+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R10, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c99:
	/* 0xc99: movzx  r11d,WORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 104ULL);
x86_l_c9f:
	/* 0xc9f: movzx  r14d,WORD PTR [r10+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R10, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_ca4:
	/* 0xca4: movzx  edi,r14w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDI, X86_R14, X86_WIDTH_32, X86_WIDTH_16);
x86_l_ca8:
	/* 0xca8: test   sil,sil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_8);
x86_l_cab:
	/* 0xcab: je     cc1 <tail_nodeport_nat_ingress_ipv4+0xcc1> */
	X86_SIM_X86_JCC(X86_CC_E, 0xcab, 0xcc1, x86_l_cc1);
x86_l_cad:
	/* 0xcad: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_caf:
	/* 0xcaf: je     cc1 <tail_nodeport_nat_ingress_ipv4+0xcc1> */
	X86_SIM_X86_JCC(X86_CC_E, 0xcaf, 0xcc1, x86_l_cc1);
x86_l_cb1:
	/* 0xcb1: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_cb3:
	/* 0xcb3: cmp    edx,r8d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R8, X86_WIDTH_32);
x86_l_cb6:
	/* 0xcb6: je     cd3 <tail_nodeport_nat_ingress_ipv4+0xcd3> */
	X86_SIM_X86_JCC(X86_CC_E, 0xcb6, 0xcd3, x86_l_cd3);
x86_l_cb8:
	/* 0xcb8: mov    eax,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R8, X86_WIDTH_32);
x86_l_cbb:
	/* 0xcbb: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_cbd:
	/* 0xcbd: add    eax,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_cbf:
	/* 0xcbf: jmp    cd0 <tail_nodeport_nat_ingress_ipv4+0xcd0> */
	X86_SIM_X86_JMP(0xcbf, 0xcd0, x86_l_cd0);
x86_l_cc1:
	/* 0xcc1: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_cc3:
	/* 0xcc3: cmp    r11w,r14w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R11, X86_R14, X86_WIDTH_16);
x86_l_cc7:
	/* 0xcc7: je     cd3 <tail_nodeport_nat_ingress_ipv4+0xcd3> */
	X86_SIM_X86_JCC(X86_CC_E, 0xcc7, 0xcd3, x86_l_cd3);
x86_l_cc9:
	/* 0xcc9: mov    eax,r11d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R11, X86_WIDTH_32);
x86_l_ccc:
	/* 0xccc: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_cce:
	/* 0xcce: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_cd0:
	/* 0xcd0: adc    eax,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_cd3:
	/* 0xcd3: cmp    edx,r8d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R8, X86_WIDTH_32);
x86_l_cd6:
	/* 0xcd6: jne    cf1 <tail_nodeport_nat_ingress_ipv4+0xcf1> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xcd6, 0xcf1, x86_l_cf1);
x86_l_cd8:
	/* 0xcd8: cmp    r11w,r14w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R11, X86_R14, X86_WIDTH_16);
x86_l_cdc:
	/* 0xcdc: jne    cf1 <tail_nodeport_nat_ingress_ipv4+0xcf1> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xcdc, 0xcf1, x86_l_cf1);
x86_l_cde:
	/* 0xcde: xor    r9d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R9, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ce1:
	/* 0xce1: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_ce9:
	/* 0xce9: mov    r15,r10 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R10, X86_WIDTH_64);
x86_l_cec:
	/* 0xcec: jmp    aa0 <tail_nodeport_nat_ingress_ipv4+0xaa0> */
	X86_SIM_X86_JMP(0xcec, 0xaa0, x86_l_aa0);
x86_l_cf1:
	/* 0xcf1: mov    DWORD PTR [rsp+0x3c],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_cf5:
	/* 0xcf5: mov    BYTE PTR [rsp+0x40],sil */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_cfa:
	/* 0xcfa: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_cfc:
	/* 0xcfc: add    edx,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_32, X86_ALU_ADD);
x86_l_cff:
	/* 0xcff: adc    edx,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_d02:
	/* 0xd02: mov    r9,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d05:
	/* 0xd05: mov    rsi,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d09:
	/* 0xd09: mov    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_d0e:
	/* 0xd0e: lea    r15,[r9+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_d12:
	/* 0xd12: add    r15,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_d16:
	/* 0xd16: mov    ebp,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967155ULL);
x86_l_d1b:
	/* 0xd1b: cmp    r15,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R15, X86_RSI, X86_WIDTH_64);
x86_l_d1e:
	/* 0xd1e: ja     76 <tail_nodeport_nat_ingress_ipv4+0x76> */
	X86_SIM_X86_JCC(X86_CC_A, 0xd1e, 0x76, x86_l_76);
x86_l_d24:
	/* 0xd24: mov    QWORD PTR [rsp+0xa8],r9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_d2c:
	/* 0xd2c: lea    r15,[r9+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_d30:
	/* 0xd30: lea    rdi,[r15+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_d34:
	/* 0xd34: mov    DWORD PTR [r15+0x14],r8d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_d38:
	/* 0xd38: mov    ebp,0xffffff67 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967143ULL);
x86_l_d3d:
	/* 0xd3d: cmp    rdi,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_64);
x86_l_d40:
	/* 0xd40: ja     76 <tail_nodeport_nat_ingress_ipv4+0x76> */
	X86_SIM_X86_JCC(X86_CC_A, 0xd40, 0x76, x86_l_76);
x86_l_d46:
	/* 0xd46: mov    QWORD PTR [rsp+0xb8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_d4e:
	/* 0xd4e: movzx  edi,WORD PTR [r15+0x12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18ULL);
x86_l_d53:
	/* 0xd53: not    edi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_d55:
	/* 0xd55: add    edi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_d57:
	/* 0xd57: adc    edi,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_d5a:
	/* 0xd5a: movzx  r8d,di */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_RDI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_d5e:
	/* 0xd5e: shr    edi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_d61:
	/* 0xd61: add    edi,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R8, X86_WIDTH_32, X86_ALU_ADD);
x86_l_d64:
	/* 0xd64: mov    r8d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RDI, X86_WIDTH_32);
x86_l_d67:
	/* 0xd67: shr    r8d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_d6b:
	/* 0xd6b: add    r8d,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_d6e:
	/* 0xd6e: not    r8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_d71:
	/* 0xd71: mov    WORD PTR [r15+0x12],r8w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R8, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_d76:
	/* 0xd76: mov    r8b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_8, 1ULL);
x86_l_d79:
	/* 0xd79: cmp    ecx,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 58ULL);
x86_l_d7c:
	/* 0xd7c: je     1455 <tail_nodeport_nat_ingress_ipv4+0x1455> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd7c, 0x1455, x86_l_1455);
x86_l_d82:
	/* 0xd82: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_d85:
	/* 0xd85: je     144b <tail_nodeport_nat_ingress_ipv4+0x144b> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd85, 0x144b, x86_l_144b);
x86_l_d8b:
	/* 0xd8b: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_d8e:
	/* 0xd8e: jne    145c <tail_nodeport_nat_ingress_ipv4+0x145c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xd8e, 0x145c, x86_l_145c);
x86_l_d94:
	/* 0xd94: mov    r15w,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_16, 16ULL);
x86_l_d99:
	/* 0xd99: jmp    145f <tail_nodeport_nat_ingress_ipv4+0x145f> */
	X86_SIM_X86_JMP(0xd99, 0x145f, x86_l_145f);
x86_l_d9e:
	/* 0xd9e: mov    ebp,0xffffff71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967153ULL);
x86_l_da3:
	/* 0xda3: jmp    76 <tail_nodeport_nat_ingress_ipv4+0x76> */
	X86_SIM_X86_JMP(0xda3, 0x76, x86_l_76);
x86_l_da8:
	/* 0xda8: movzx  r9d,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_dac:
	/* 0xdac: not    r9d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_daf:
	/* 0xdaf: add    r9d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_db2:
	/* 0xdb2: setb   r10b */
	X86_SIM_L_EXEC_SETCC(X86_R10, X86_CC_B);
x86_l_db6:
	/* 0xdb6: movzx  r10d,r10b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R10, X86_R10, X86_WIDTH_32, X86_WIDTH_8);
x86_l_dba:
	/* 0xdba: add    r10d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R9, X86_WIDTH_32, X86_ALU_ADD);
x86_l_dbd:
	/* 0xdbd: movzx  r9d,r10w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R9, X86_R10, X86_WIDTH_32, X86_WIDTH_16);
x86_l_dc1:
	/* 0xdc1: shr    r10d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_dc5:
	/* 0xdc5: add    r10d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R9, X86_WIDTH_32, X86_ALU_ADD);
x86_l_dc8:
	/* 0xdc8: mov    r9d,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_R10, X86_WIDTH_32);
x86_l_dcb:
	/* 0xdcb: shr    r9d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_dcf:
	/* 0xdcf: add    r9d,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R10, X86_WIDTH_32, X86_ALU_ADD);
x86_l_dd2:
	/* 0xdd2: cmp    r9w,0xffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_16, 65535ULL);
x86_l_dd7:
	/* 0xdd7: not    r9d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_dda:
	/* 0xdda: mov    r10d,0xffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_32, 65535ULL);
x86_l_de0:
	/* 0xde0: cmovne r10d,r9d */
	X86_SIM_L_EXEC_CMOV(X86_R10, X86_R9, X86_WIDTH_32, X86_CC_NE);
x86_l_de4:
	/* 0xde4: test   sil,sil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_8);
x86_l_de7:
	/* 0xde7: cmovne r10d,r9d */
	X86_SIM_L_EXEC_CMOV(X86_R10, X86_R9, X86_WIDTH_32, X86_CC_NE);
x86_l_deb:
	/* 0xdeb: mov    WORD PTR [r14],r10w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R10, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_def:
	/* 0xdef: cmp    r8d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 1ULL);
x86_l_df3:
	/* 0xdf3: jne    b5f <tail_nodeport_nat_ingress_ipv4+0xb5f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xdf3, 0xb5f, x86_l_b5f);
x86_l_df9:
	/* 0xdf9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_dfb:
	/* 0xdfb: je     e66 <tail_nodeport_nat_ingress_ipv4+0xe66> */
	X86_SIM_X86_JCC(X86_CC_E, 0xdfb, 0xe66, x86_l_e66);
x86_l_dfd:
	/* 0xdfd: movzx  edx,r13b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_R13, X86_WIDTH_32, X86_WIDTH_8);
x86_l_e01:
	/* 0xe01: lea    r8,[rcx+rdx*1] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_e05:
	/* 0xe05: add    r8,0x12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_64, X86_ALU_ADD, 18ULL);
x86_l_e09:
	/* 0xe09: mov    ebp,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967142ULL);
x86_l_e0e:
	/* 0xe0e: cmp    r8,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDI, X86_WIDTH_64);
x86_l_e11:
	/* 0xe11: ja     76 <tail_nodeport_nat_ingress_ipv4+0x76> */
	X86_SIM_X86_JCC(X86_CC_A, 0xe11, 0x76, x86_l_76);
x86_l_e17:
	/* 0xe17: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_e1a:
	/* 0xe1a: add    rcx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_e1e:
	/* 0xe1e: movzx  edx,WORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_e21:
	/* 0xe21: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_e23:
	/* 0xe23: setne  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_NE);
x86_l_e27:
	/* 0xe27: or     dil,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_8, X86_ALU_OR);
x86_l_e2a:
	/* 0xe2a: cmp    dil,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_8, 1ULL);
x86_l_e2e:
	/* 0xe2e: jne    e66 <tail_nodeport_nat_ingress_ipv4+0xe66> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe2e, 0xe66, x86_l_e66);
x86_l_e30:
	/* 0xe30: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_e32:
	/* 0xe32: add    eax,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_e34:
	/* 0xe34: setb   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_B);
x86_l_e38:
	/* 0xe38: mov    edx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_e3a:
	/* 0xe3a: movzx  eax,dil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_e3e:
	/* 0xe3e: add    eax,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_e40:
	/* 0xe40: movzx  edx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_e43:
	/* 0xe43: shr    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_e46:
	/* 0xe46: add    eax,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_e48:
	/* 0xe48: mov    edx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_e4a:
	/* 0xe4a: shr    edx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_e4d:
	/* 0xe4d: add    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_e4f:
	/* 0xe4f: cmp    dx,0xffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_16, 65535ULL);
x86_l_e53:
	/* 0xe53: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_e55:
	/* 0xe55: mov    eax,0xffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 65535ULL);
x86_l_e5a:
	/* 0xe5a: cmovne eax,edx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RDX, X86_WIDTH_32, X86_CC_NE);
x86_l_e5d:
	/* 0xe5d: test   sil,sil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_8);
x86_l_e60:
	/* 0xe60: cmovne eax,edx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RDX, X86_WIDTH_32, X86_CC_NE);
x86_l_e63:
	/* 0xe63: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e66:
	/* 0xe66: mov    DWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_e6e:
	/* 0xe6e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e73:
	/* 0xe73: mov    rdi,QWORD PTR [rip+0x23bc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_e7a:
	/* 0xe7a: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_e7f:
	/* 0xe7f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e81:
	/* 0xe81: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e84:
	/* 0xe84: je     177c <tail_nodeport_nat_ingress_ipv4+0x177c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe84, 0x177c, x86_l_177c);
x86_l_e8a:
	/* 0xe8a: mov    ebp,DWORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_e8d:
	/* 0xe8d: mov    DWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_e95:
	/* 0xe95: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e9a:
	/* 0xe9a: mov    rdi,QWORD PTR [rip+0x23bc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_ea1:
	/* 0xea1: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_ea6:
	/* 0xea6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ea8:
	/* 0xea8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_eab:
	/* 0xeab: je     eb3 <tail_nodeport_nat_ingress_ipv4+0xeb3> */
	X86_SIM_X86_JCC(X86_CC_E, 0xeab, 0xeb3, x86_l_eb3);
x86_l_ead:
	/* 0xead: or     ebp,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_OR, 4ULL);
x86_l_eb0:
	/* 0xeb0: mov    DWORD PTR [rax+0x18],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_eb3:
	/* 0xeb3: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_ebc:
	/* 0xebc: mov    DWORD PTR [rsp+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_ec7:
	/* 0xec7: mov    QWORD PTR [rsp+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_ed3:
	/* 0xed3: mov    QWORD PTR [rsp+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_edf:
	/* 0xedf: mov    QWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_eeb:
	/* 0xeeb: mov    QWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_ef7:
	/* 0xef7: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_f00:
	/* 0xf00: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_f09:
	/* 0xf09: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_f12:
	/* 0xf12: mov    BYTE PTR [rsp+0x60],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 412316860418ULL);
x86_l_f17:
	/* 0xf17: mov    eax,DWORD PTR [rbx+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_f1a:
	/* 0xf1a: mov    DWORD PTR [rsp+0x68],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_f1e:
	/* 0xf1e: mov    WORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_f25:
	/* 0xf25: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_f2d:
	/* 0xf2d: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f30:
	/* 0xf30: mov    rcx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f34:
	/* 0xf34: lea    rdx,[rax+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_f38:
	/* 0xf38: mov    r15d,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967162ULL);
x86_l_f3e:
	/* 0xf3e: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f41:
	/* 0xf41: cmp    rdx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_f44:
	/* 0xf44: movabs r9,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_64, 2199023255552ULL);
x86_l_f4e:
	/* 0xf4e: movabs r10,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_64, 1099511627776ULL);
x86_l_f58:
	/* 0xf58: jbe    f6a <tail_nodeport_nat_ingress_ipv4+0xf6a> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xf58, 0xf6a, x86_l_f6a);
x86_l_f5a:
	/* 0xf5a: shl    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_f5e:
	/* 0xf5e: movzx  r12d,r14w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R14, X86_WIDTH_32, X86_WIDTH_16);
x86_l_f62:
	/* 0xf62: mov    ebp,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_32);
x86_l_f65:
	/* 0xf65: jmp    d1 <tail_nodeport_nat_ingress_ipv4+0xd1> */
	X86_SIM_X86_JMP(0xf65, 0xd1, x86_l_d1);
x86_l_f6a:
	/* 0xf6a: movzx  edx,WORD PTR [rax+0x12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18ULL);
x86_l_f6e:
	/* 0xf6e: movzx  r12d,BYTE PTR [rax+0x17] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 23ULL);
x86_l_f73:
	/* 0xf73: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_f76:
	/* 0xf76: shl    rsi,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_f7a:
	/* 0xf7a: or     rsi,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_64, X86_ALU_OR);
x86_l_f7d:
	/* 0xf7d: movzx  edx,WORD PTR [rax+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 20ULL);
x86_l_f81:
	/* 0xf81: mov    r8,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RSI, X86_WIDTH_64);
x86_l_f84:
	/* 0xf84: or     r8,r10 */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R10, X86_WIDTH_64, X86_ALU_OR);
x86_l_f87:
	/* 0xf87: test   edx,0xff3f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_32, 65343ULL);
x86_l_f8d:
	/* 0xf8d: cmove  r8,rsi */
	X86_SIM_L_EXEC_CMOV(X86_R8, X86_RSI, X86_WIDTH_64, X86_CC_E);
x86_l_f91:
	/* 0xf91: mov    r13,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R8, X86_WIDTH_64);
x86_l_f94:
	/* 0xf94: or     r13,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R9, X86_WIDTH_64, X86_ALU_OR);
x86_l_f97:
	/* 0xf97: test   edx,0xff1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_32, 65311ULL);
x86_l_f9d:
	/* 0xf9d: mov    edi,DWORD PTR [rax+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_fa0:
	/* 0xfa0: mov    BYTE PTR [rsp+0x14],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_fa5:
	/* 0xfa5: mov    edx,DWORD PTR [rax+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_fa8:
	/* 0xfa8: mov    DWORD PTR [rsp+0x8],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fac:
	/* 0xfac: cmove  r13,r8 */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_R8, X86_WIDTH_64, X86_CC_E);
x86_l_fb0:
	/* 0xfb0: mov    esi,DWORD PTR [rax+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_fb3:
	/* 0xfb3: mov    DWORD PTR [rsp+0xc],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_fb7:
	/* 0xfb7: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_fbc:
	/* 0xfbc: cmp    r12d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 17ULL);
x86_l_fc0:
	/* 0xfc0: je     fcc <tail_nodeport_nat_ingress_ipv4+0xfcc> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfc0, 0xfcc, x86_l_fcc);
x86_l_fc2:
	/* 0xfc2: cmp    r12d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 6ULL);
x86_l_fc6:
	/* 0xfc6: jne    1ebf <tail_nodeport_nat_ingress_ipv4+0x1ebf> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xfc6, 0x1ebf, x86_l_1ebf);
x86_l_fcc:
	/* 0xfcc: and    edi,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_fcf:
	/* 0xfcf: lea    r11,[rdi*4+0xe] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 2), 14ULL);
x86_l_fd7:
	/* 0xfd7: mov    r8,QWORD PTR [rip+0x23bc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R8, (void *)(long)(((__u64)(long)&__config_enable_ipv4_fragments)));
x86_l_fde:
	/* 0xfde: cmp    BYTE PTR [r8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fe2:
	/* 0xfe2: je     103c <tail_nodeport_nat_ingress_ipv4+0x103c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfe2, 0x103c, x86_l_103c);
x86_l_fe4:
	/* 0xfe4: mov    DWORD PTR [rsp+0x48],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_fe8:
	/* 0xfe8: mov    DWORD PTR [rsp+0x4c],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_fec:
	/* 0xfec: mov    WORD PTR [rsp+0x50],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_ff2:
	/* 0xff2: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_ff5:
	/* 0xff5: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_ff9:
	/* 0xff9: mov    BYTE PTR [rsp+0x52],dl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 82ULL);
x86_l_ffd:
	/* 0xffd: mov    BYTE PTR [rsp+0x53],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 356482285568ULL);
x86_l_1002:
	/* 0x1002: test   r13,r9 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R9, X86_WIDTH_64);
x86_l_1005:
	/* 0x1005: jne    1b4e <tail_nodeport_nat_ingress_ipv4+0x1b4e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1005, 0x1b4e, x86_l_1b4e);
x86_l_100b:
	/* 0x100b: lea    rdx,[rax+r11*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R11, 0), 0ULL);
x86_l_100f:
	/* 0x100f: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1013:
	/* 0x1013: mov    r15d,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967161ULL);
x86_l_1019:
	/* 0x1019: cmp    rdx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_101c:
	/* 0x101c: ja     f5a <tail_nodeport_nat_ingress_ipv4+0xf5a> */
	X86_SIM_X86_JCC(X86_CC_A, 0x101c, 0xf5a, x86_l_f5a);
x86_l_1022:
	/* 0x1022: add    rax,r11 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R11, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1025:
	/* 0x1025: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1027:
	/* 0x1027: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_102b:
	/* 0x102b: test   r13,r10 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R10, X86_WIDTH_64);
x86_l_102e:
	/* 0x102e: jne    1bbf <tail_nodeport_nat_ingress_ipv4+0x1bbf> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x102e, 0x1bbf, x86_l_1bbf);
x86_l_1034:
	/* 0x1034: movzx  r12d,BYTE PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 20ULL);
x86_l_103a:
	/* 0x103a: jmp    1069 <tail_nodeport_nat_ingress_ipv4+0x1069> */
	X86_SIM_X86_JMP(0x103a, 0x1069, x86_l_1069);
x86_l_103c:
	/* 0x103c: test   r13,r9 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R9, X86_WIDTH_64);
x86_l_103f:
	/* 0x103f: jne    1b80 <tail_nodeport_nat_ingress_ipv4+0x1b80> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x103f, 0x1b80, x86_l_1b80);
x86_l_1045:
	/* 0x1045: movzx  edx,r11b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_R11, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1049:
	/* 0x1049: lea    rsi,[rax+rdx*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_104d:
	/* 0x104d: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1051:
	/* 0x1051: mov    r15d,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967161ULL);
x86_l_1057:
	/* 0x1057: cmp    rsi,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_64);
x86_l_105a:
	/* 0x105a: ja     f5a <tail_nodeport_nat_ingress_ipv4+0xf5a> */
	X86_SIM_X86_JCC(X86_CC_A, 0x105a, 0xf5a, x86_l_f5a);
x86_l_1060:
	/* 0x1060: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1063:
	/* 0x1063: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1065:
	/* 0x1065: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1069:
	/* 0x1069: cmp    r12b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_8, 6ULL);
x86_l_106d:
	/* 0x106d: jne    1078 <tail_nodeport_nat_ingress_ipv4+0x1078> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x106d, 0x1078, x86_l_1078);
x86_l_106f:
	/* 0x106f: mov    rdi,QWORD PTR [rip+0x23bc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct4_global)));
x86_l_1076:
	/* 0x1076: jmp    107f <tail_nodeport_nat_ingress_ipv4+0x107f> */
	X86_SIM_X86_JMP(0x1076, 0x107f, x86_l_107f);
x86_l_1078:
	/* 0x1078: mov    rdi,QWORD PTR [rip+0x23bc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct_any4_global)));
x86_l_107f:
	/* 0x107f: mov    BYTE PTR [rsp+0x15],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 90194313216ULL);
x86_l_1084:
	/* 0x1084: cmp    BYTE PTR [r8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1088:
	/* 0x1088: mov    QWORD PTR [rsp+0x28],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_108d:
	/* 0x108d: je     1122 <tail_nodeport_nat_ingress_ipv4+0x1122> */
	X86_SIM_X86_JCC(X86_CC_E, 0x108d, 0x1122, x86_l_1122);
x86_l_1093:
	/* 0x1093: and    r10,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1096:
	/* 0x1096: je     1122 <tail_nodeport_nat_ingress_ipv4+0x1122> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1096, 0x1122, x86_l_1122);
x86_l_109c:
	/* 0x109c: mov    QWORD PTR [rsp+0x30],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_10a1:
	/* 0x10a1: mov    r14,r9 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R9, X86_WIDTH_64);
x86_l_10a4:
	/* 0x10a4: mov    r15,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10a8:
	/* 0x10a8: sub    r15,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 0ULL);
x86_l_10ab:
	/* 0x10ab: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_10b4:
	/* 0x10b4: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_10bd:
	/* 0x10bd: movabs rax,0x6c03a50109 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 463917613321ULL);
x86_l_10c7:
	/* 0x10c7: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_10cc:
	/* 0x10cc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_10d1:
	/* 0x10d1: mov    rdi,QWORD PTR [rip+0x23bc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_10d8:
	/* 0x10d8: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_10dd:
	/* 0x10dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10df:
	/* 0x10df: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10e2:
	/* 0x10e2: je     10ed <tail_nodeport_nat_ingress_ipv4+0x10ed> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10e2, 0x10ed, x86_l_10ed);
x86_l_10e4:
	/* 0x10e4: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_10e7:
	/* 0x10e7: add    QWORD PTR [rax+0x8],r15 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_10eb:
	/* 0x10eb: jmp    1115 <tail_nodeport_nat_ingress_ipv4+0x1115> */
	X86_SIM_X86_JMP(0x10eb, 0x1115, x86_l_1115);
x86_l_10ed:
	/* 0x10ed: mov    QWORD PTR [rsp+0x18],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215105ULL);
x86_l_10f6:
	/* 0x10f6: mov    QWORD PTR [rsp+0x20],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_10fb:
	/* 0x10fb: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1100:
	/* 0x1100: mov    rdi,QWORD PTR [rip+0x23bc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1107:
	/* 0x1107: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_110c:
	/* 0x110c: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1111:
	/* 0x1111: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1113:
	/* 0x1113: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1115:
	/* 0x1115: mov    r9,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_R14, X86_WIDTH_64);
x86_l_1118:
	/* 0x1118: mov    r11,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_111d:
	/* 0x111d: mov    rdi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1122:
	/* 0x1122: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1125:
	/* 0x1125: cmp    r12b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_8, 6ULL);
x86_l_1129:
	/* 0x1129: jne    117f <tail_nodeport_nat_ingress_ipv4+0x117f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1129, 0x117f, x86_l_117f);
x86_l_112b:
	/* 0x112b: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_112e:
	/* 0x112e: mov    r15d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 0ULL);
x86_l_1134:
	/* 0x1134: and    rax,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R9, X86_WIDTH_64, X86_ALU_AND);
x86_l_1137:
	/* 0x1137: jne    1182 <tail_nodeport_nat_ingress_ipv4+0x1182> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1137, 0x1182, x86_l_1182);
x86_l_1139:
	/* 0x1139: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_113c:
	/* 0x113c: movzx  ecx,r11b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R11, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1140:
	/* 0x1140: lea    rdx,[rax+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1144:
	/* 0x1144: add    rdx,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 14ULL);
x86_l_1148:
	/* 0x1148: cmp    rdx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_114c:
	/* 0x114c: ja     1ebf <tail_nodeport_nat_ingress_ipv4+0x1ebf> */
	X86_SIM_X86_JCC(X86_CC_A, 0x114c, 0x1ebf, x86_l_1ebf);
x86_l_1152:
	/* 0x1152: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1155:
	/* 0x1155: movzx  r14d,WORD PTR [rax+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_115a:
	/* 0x115a: mov    eax,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_32);
x86_l_115d:
	/* 0x115d: and    eax,0x1200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4608ULL);
x86_l_1162:
	/* 0x1162: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1165:
	/* 0x1165: cmp    eax,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 512ULL);
x86_l_116a:
	/* 0x116a: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_116d:
	/* 0x116d: test   r14d,0x500 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R14, X86_WIDTH_32, 1280ULL);
x86_l_1174:
	/* 0x1174: jne    1d4a <tail_nodeport_nat_ingress_ipv4+0x1d4a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1174, 0x1d4a, x86_l_1d4a);
x86_l_117a:
	/* 0x117a: mov    r15b,al */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_8);
x86_l_117d:
	/* 0x117d: jmp    1182 <tail_nodeport_nat_ingress_ipv4+0x1182> */
	X86_SIM_X86_JMP(0x117d, 0x1182, x86_l_1182);
x86_l_117f:
	/* 0x117f: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1182:
	/* 0x1182: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1187:
	/* 0x1187: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_118c:
	/* 0x118c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_118e:
	/* 0x118e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1191:
	/* 0x1191: je     1eb6 <tail_nodeport_nat_ingress_ipv4+0x1eb6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1191, 0x1eb6, x86_l_1eb6);
x86_l_1197:
	/* 0x1197: movzx  ecx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_119b:
	/* 0x119b: test   cl,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_119e:
	/* 0x119e: je     1eb6 <tail_nodeport_nat_ingress_ipv4+0x1eb6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x119e, 0x1eb6, x86_l_1eb6);
x86_l_11a4:
	/* 0x11a4: cmp    WORD PTR [rax+0x26],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 163208757248ULL);
x86_l_11a9:
	/* 0x11a9: je     1eb6 <tail_nodeport_nat_ingress_ipv4+0x1eb6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11a9, 0x1eb6, x86_l_1eb6);
x86_l_11af:
	/* 0x11af: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_11b1:
	/* 0x11b1: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_11b3:
	/* 0x11b3: test   dl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_8, 3ULL);
x86_l_11b6:
	/* 0x11b6: je     12ce <tail_nodeport_nat_ingress_ipv4+0x12ce> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11b6, 0x12ce, x86_l_12ce);
x86_l_11bc:
	/* 0x11bc: mov    DWORD PTR [rsp+0x30],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_11c1:
	/* 0x11c1: mov    rsi,QWORD PTR [rip+0x23bc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_11c8:
	/* 0x11c8: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11cb:
	/* 0x11cb: je     11de <tail_nodeport_nat_ingress_ipv4+0x11de> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11cb, 0x11de, x86_l_11de);
x86_l_11cd:
	/* 0x11cd: mov    rdx,QWORD PTR [rip+0x23bc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_11d4:
	/* 0x11d4: imul   r14d,DWORD PTR [rdx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R14, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_11d8:
	/* 0x11d8: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_11dc:
	/* 0x11dc: jmp    11e4 <tail_nodeport_nat_ingress_ipv4+0x11e4> */
	X86_SIM_X86_JMP(0x11dc, 0x11e4, x86_l_11e4);
x86_l_11de:
	/* 0x11de: mov    r14d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 60ULL);
x86_l_11e4:
	/* 0x11e4: cmp    r12b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_8, 6ULL);
x86_l_11e8:
	/* 0x11e8: jne    1222 <tail_nodeport_nat_ingress_ipv4+0x1222> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x11e8, 0x1222, x86_l_1222);
x86_l_11ea:
	/* 0x11ea: mov    edx,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_11ee:
	/* 0x11ee: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_11f0:
	/* 0x11f0: shr    edx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_11f3:
	/* 0x11f3: and    edx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_11f6:
	/* 0x11f6: or     ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_11f8:
	/* 0x11f8: mov    WORD PTR [rax+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_11fc:
	/* 0x11fc: test   cl,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 16ULL);
x86_l_11ff:
	/* 0x11ff: mov    ecx,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 60ULL);
x86_l_1204:
	/* 0x1204: mov    r14d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 21600ULL);
x86_l_120a:
	/* 0x120a: cmove  r14d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R14, X86_RCX, X86_WIDTH_32, X86_CC_E);
x86_l_120e:
	/* 0x120e: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1211:
	/* 0x1211: je     1222 <tail_nodeport_nat_ingress_ipv4+0x1222> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1211, 0x1222, x86_l_1222);
x86_l_1213:
	/* 0x1213: mov    rcx,QWORD PTR [rip+0x23bc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_121a:
	/* 0x121a: imul   r14d,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_121e:
	/* 0x121e: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1222:
	/* 0x1222: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1227:
	/* 0x1227: movzx  eax,WORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_122c:
	/* 0x122c: shr    eax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_122f:
	/* 0x122f: mov    DWORD PTR [rsp+0x58],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1233:
	/* 0x1233: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1236:
	/* 0x1236: je     124a <tail_nodeport_nat_ingress_ipv4+0x124a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1236, 0x124a, x86_l_124a);
x86_l_1238:
	/* 0x1238: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_123d:
	/* 0x123d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_123f:
	/* 0x123f: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1241:
	/* 0x1241: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1244:
	/* 0x1244: shr    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_1248:
	/* 0x1248: jmp    126d <tail_nodeport_nat_ingress_ipv4+0x126d> */
	X86_SIM_X86_JMP(0x1248, 0x126d, x86_l_126d);
x86_l_124a:
	/* 0x124a: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_124f:
	/* 0x124f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1251:
	/* 0x1251: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1253:
	/* 0x1253: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1257:
	/* 0x1257: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_1261:
	/* 0x1261: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1264:
	/* 0x1264: mulx   rcx,rcx,rcx */
	X86_SIM_L_EXEC_MULX(X86_RCX, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_1269:
	/* 0x1269: shr    rcx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_126d:
	/* 0x126d: add    r14d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1270:
	/* 0x1270: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1275:
	/* 0x1275: mov    DWORD PTR [rax+0x20],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1279:
	/* 0x1279: movzx  edx,BYTE PTR [rax+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_127d:
	/* 0x127d: mov    esi,DWORD PTR [rax+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1280:
	/* 0x1280: mov    r8d,DWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1285:
	/* 0x1285: and    r8b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_1289:
	/* 0x1289: mov    rdi,QWORD PTR [rip+0x23bc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1290:
	/* 0x1290: cmp    BYTE PTR [rdi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1293:
	/* 0x1293: je     12a6 <tail_nodeport_nat_ingress_ipv4+0x12a6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1293, 0x12a6, x86_l_12a6);
x86_l_1295:
	/* 0x1295: mov    rdi,QWORD PTR [rip+0x23bc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_129c:
	/* 0x129c: mov    edi,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_129e:
	/* 0x129e: lea    edi,[rdi+rdi*4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_12a1:
	/* 0x12a1: shr    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_12a4:
	/* 0x12a4: jmp    12ab <tail_nodeport_nat_ingress_ipv4+0x12ab> */
	X86_SIM_X86_JMP(0x12a4, 0x12ab, x86_l_12ab);
x86_l_12a6:
	/* 0x12a6: mov    edi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 5ULL);
x86_l_12ab:
	/* 0x12ab: mov    r14d,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_12b0:
	/* 0x12b0: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_12b2:
	/* 0x12b2: or     r8b,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_12b5:
	/* 0x12b5: cmp    edi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RCX, X86_WIDTH_32);
x86_l_12b7:
	/* 0x12b7: jb     12be <tail_nodeport_nat_ingress_ipv4+0x12be> */
	X86_SIM_X86_JCC(X86_CC_B, 0x12b7, 0x12be, x86_l_12be);
x86_l_12b9:
	/* 0x12b9: cmp    dl,r8b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R8, X86_WIDTH_8);
x86_l_12bc:
	/* 0x12bc: je     12ce <tail_nodeport_nat_ingress_ipv4+0x12ce> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12bc, 0x12ce, x86_l_12ce);
x86_l_12be:
	/* 0x12be: mov    BYTE PTR [rax+0x2b],r8b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R8, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_12c2:
	/* 0x12c2: mov    DWORD PTR [rax+0x34],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_12c5:
	/* 0x12c5: mov    rcx,QWORD PTR [rip+0x23bc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_12cc:
	/* 0x12cc: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12ce:
	/* 0x12ce: mov    rcx,QWORD PTR [rip+0x23bc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_12d5:
	/* 0x12d5: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12d8:
	/* 0x12d8: je     12eb <tail_nodeport_nat_ingress_ipv4+0x12eb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12d8, 0x12eb, x86_l_12eb);
x86_l_12da:
	/* 0x12da: inc QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 16ULL);
x86_l_12df:
	/* 0x12df: mov    rcx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12e3:
	/* 0x12e3: sub    rcx,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 0ULL);
x86_l_12e6:
	/* 0x12e6: add QWORD PTR [rax+0x18],rcx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_12eb:
	/* 0x12eb: cmp    r15d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 2ULL);
x86_l_12ef:
	/* 0x12ef: je     1343 <tail_nodeport_nat_ingress_ipv4+0x1343> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12ef, 0x1343, x86_l_1343);
x86_l_12f1:
	/* 0x12f1: cmp    r15d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 1ULL);
x86_l_12f5:
	/* 0x12f5: jne    1630 <tail_nodeport_nat_ingress_ipv4+0x1630> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x12f5, 0x1630, x86_l_1630);
x86_l_12fb:
	/* 0x12fb: movzx  ecx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_12ff:
	/* 0x12ff: test   cl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_1302:
	/* 0x1302: je     1630 <tail_nodeport_nat_ingress_ipv4+0x1630> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1302, 0x1630, x86_l_1630);
x86_l_1308:
	/* 0x1308: mov    edx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_32);
x86_l_130b:
	/* 0x130b: mov    WORD PTR [rax+0x2a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 180388626432ULL);
x86_l_1311:
	/* 0x1311: and    ecx,0xffec */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 65516ULL);
x86_l_1317:
	/* 0x1317: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_131a:
	/* 0x131a: mov    WORD PTR [rax+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_131e:
	/* 0x131e: mov    r15,QWORD PTR [rip+0x23bc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1325:
	/* 0x1325: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1329:
	/* 0x1329: je     1dea <tail_nodeport_nat_ingress_ipv4+0x1dea> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1329, 0x1dea, x86_l_1dea);
x86_l_132f:
	/* 0x132f: mov    rax,QWORD PTR [rip+0x23bc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1336:
	/* 0x1336: imul   r13d,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_133a:
	/* 0x133a: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_133e:
	/* 0x133e: jmp    1df0 <tail_nodeport_nat_ingress_ipv4+0x1df0> */
	X86_SIM_X86_JMP(0x133e, 0x1df0, x86_l_1df0);
x86_l_1343:
	/* 0x1343: mov    ecx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_32);
x86_l_1346:
	/* 0x1346: shr    ecx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_1349:
	/* 0x1349: and    ecx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2ULL);
x86_l_134c:
	/* 0x134c: or     cx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RAX, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 36ULL);
x86_l_1350:
	/* 0x1350: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_1352:
	/* 0x1352: or     edx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_OR, 1ULL);
x86_l_1355:
	/* 0x1355: mov    WORD PTR [rax+0x24],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1359:
	/* 0x1359: mov    rdx,QWORD PTR [rip+0x23bc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_1360:
	/* 0x1360: mov    edx,DWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1362:
	/* 0x1362: test   cl,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_1365:
	/* 0x1365: je     1630 <tail_nodeport_nat_ingress_ipv4+0x1630> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1365, 0x1630, x86_l_1630);
x86_l_136b:
	/* 0x136b: mov    ecx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_32);
x86_l_136e:
	/* 0x136e: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_1371:
	/* 0x1371: mov    rax,QWORD PTR [rip+0x23bc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1378:
	/* 0x1378: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_137b:
	/* 0x137b: je     1587 <tail_nodeport_nat_ingress_ipv4+0x1587> */
	X86_SIM_X86_JCC(X86_CC_E, 0x137b, 0x1587, x86_l_1587);
x86_l_1381:
	/* 0x1381: mov    rax,QWORD PTR [rip+0x23bc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1388:
	/* 0x1388: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_138a:
	/* 0x138a: add    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_138c:
	/* 0x138c: lea    r12d,[rax+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_1390:
	/* 0x1390: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1394:
	/* 0x1394: jmp    158d <tail_nodeport_nat_ingress_ipv4+0x158d> */
	X86_SIM_X86_JMP(0x1394, 0x158d, x86_l_158d);
x86_l_1399:
	/* 0x1399: mov    r15,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R8, X86_WIDTH_64);
x86_l_139c:
	/* 0x139c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13a1:
	/* 0x13a1: mov    rdi,QWORD PTR [rip+0x23bc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv4_frag_datagrams)));
x86_l_13a8:
	/* 0x13a8: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_13ad:
	/* 0x13ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13af:
	/* 0x13af: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13b2:
	/* 0x13b2: je     157d <tail_nodeport_nat_ingress_ipv4+0x157d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13b2, 0x157d, x86_l_157d);
x86_l_13b8:
	/* 0x13b8: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13ba:
	/* 0x13ba: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13be:
	/* 0x13be: mov    r8,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R15, X86_WIDTH_64);
x86_l_13c1:
	/* 0x13c1: jmp    2ce <tail_nodeport_nat_ingress_ipv4+0x2ce> */
	X86_SIM_X86_JMP(0x13c1, 0x2ce, x86_l_2ce);
x86_l_13c6:
	/* 0x13c6: mov    ebp,0xffffff63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967139ULL);
x86_l_13cb:
	/* 0x13cb: jmp    76 <tail_nodeport_nat_ingress_ipv4+0x76> */
	X86_SIM_X86_JMP(0x13cb, 0x76, x86_l_76);
x86_l_13d0:
	/* 0x13d0: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13d5:
	/* 0x13d5: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_13da:
	/* 0x13da: mov    rdi,QWORD PTR [rip+0x23bc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv4_frag_datagrams)));
x86_l_13e1:
	/* 0x13e1: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_13e6:
	/* 0x13e6: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13e8:
	/* 0x13e8: mov    rbp,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R8, X86_WIDTH_64);
x86_l_13eb:
	/* 0x13eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13ed:
	/* 0x13ed: mov    r8,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RBP, X86_WIDTH_64);
x86_l_13f0:
	/* 0x13f0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_13f2:
	/* 0x13f2: je     2ce <tail_nodeport_nat_ingress_ipv4+0x2ce> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13f2, 0x2ce, x86_l_2ce);
x86_l_13f8:
	/* 0x13f8: mov    r15,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13fc:
	/* 0x13fc: sub    r15,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 0ULL);
x86_l_13ff:
	/* 0x13ff: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_1408:
	/* 0x1408: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_1411:
	/* 0x1411: movabs rax,0x6b0085010a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 459570217226ULL);
x86_l_141b:
	/* 0x141b: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1420:
	/* 0x1420: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1425:
	/* 0x1425: mov    rdi,QWORD PTR [rip+0x23bc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_142c:
	/* 0x142c: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1431:
	/* 0x1431: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1433:
	/* 0x1433: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1436:
	/* 0x1436: je     174c <tail_nodeport_nat_ingress_ipv4+0x174c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1436, 0x174c, x86_l_174c);
x86_l_143c:
	/* 0x143c: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_143f:
	/* 0x143f: add    QWORD PTR [rax+0x8],r15 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1443:
	/* 0x1443: mov    r8,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RBP, X86_WIDTH_64);
x86_l_1446:
	/* 0x1446: jmp    2ce <tail_nodeport_nat_ingress_ipv4+0x2ce> */
	X86_SIM_X86_JMP(0x1446, 0x2ce, x86_l_2ce);
x86_l_144b:
	/* 0x144b: mov    r15w,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_16, 6ULL);
x86_l_1450:
	/* 0x1450: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1453:
	/* 0x1453: jmp    145f <tail_nodeport_nat_ingress_ipv4+0x145f> */
	X86_SIM_X86_JMP(0x1453, 0x145f, x86_l_145f);
x86_l_1455:
	/* 0x1455: mov    r15w,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_16, 2ULL);
x86_l_145a:
	/* 0x145a: jmp    145f <tail_nodeport_nat_ingress_ipv4+0x145f> */
	X86_SIM_X86_JMP(0x145a, 0x145f, x86_l_145f);
x86_l_145c:
	/* 0x145c: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_145f:
	/* 0x145f: cmp    r11w,r14w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R11, X86_R14, X86_WIDTH_16);
x86_l_1463:
	/* 0x1463: jne    14ef <tail_nodeport_nat_ingress_ipv4+0x14ef> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1463, 0x14ef, x86_l_14ef);
x86_l_1469:
	/* 0x1469: test   r15w,r15w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_16);
x86_l_146d:
	/* 0x146d: je     cde <tail_nodeport_nat_ingress_ipv4+0xcde> */
	X86_SIM_X86_JCC(X86_CC_E, 0x146d, 0xcde, x86_l_cde);
x86_l_1473:
	/* 0x1473: movzx  edi,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDI, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1477:
	/* 0x1477: mov    ecx,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_147b:
	/* 0x147b: mov    r11,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1483:
	/* 0x1483: add    r11,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_RDI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1486:
	/* 0x1486: lea    rdi,[rcx+r11*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R11, 0), 0ULL);
x86_l_148a:
	/* 0x148a: add    rdi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_148e:
	/* 0x148e: cmp    rdi,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 184ULL);
x86_l_1496:
	/* 0x1496: ja     1568 <tail_nodeport_nat_ingress_ipv4+0x1568> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1496, 0x1568, x86_l_1568);
x86_l_149c:
	/* 0x149c: mov    r9,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_R11, X86_WIDTH_64);
x86_l_149f:
	/* 0x149f: add    r9,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_14a2:
	/* 0x14a2: movzx  ecx,WORD PTR [r9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R9, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_14a6:
	/* 0x14a6: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_14a8:
	/* 0x14a8: setne  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_NE);
x86_l_14ac:
	/* 0x14ac: or     sil,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R8, X86_WIDTH_8, X86_ALU_OR);
x86_l_14af:
	/* 0x14af: cmp    sil,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_8, 1ULL);
x86_l_14b3:
	/* 0x14b3: jne    cde <tail_nodeport_nat_ingress_ipv4+0xcde> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x14b3, 0xcde, x86_l_cde);
x86_l_14b9:
	/* 0x14b9: mov    rdi,r9 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R9, X86_WIDTH_64);
x86_l_14bc:
	/* 0x14bc: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_14be:
	/* 0x14be: add    edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_14c0:
	/* 0x14c0: adc    edx,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_14c3:
	/* 0x14c3: movzx  ecx,dx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RDX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_14c6:
	/* 0x14c6: shr    edx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_14c9:
	/* 0x14c9: add    edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_14cb:
	/* 0x14cb: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_14cd:
	/* 0x14cd: shr    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_14d0:
	/* 0x14d0: add    ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_14d2:
	/* 0x14d2: cmp    cx,0xffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 65535ULL);
x86_l_14d6:
	/* 0x14d6: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_14d8:
	/* 0x14d8: mov    edx,0xffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 65535ULL);
x86_l_14dd:
	/* 0x14dd: cmovne edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_NE);
x86_l_14e0:
	/* 0x14e0: test   r8b,r8b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R8, X86_R8, X86_WIDTH_8);
x86_l_14e3:
	/* 0x14e3: cmovne edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_NE);
x86_l_14e6:
	/* 0x14e6: mov    WORD PTR [r9],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R9, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14ea:
	/* 0x14ea: jmp    cde <tail_nodeport_nat_ingress_ipv4+0xcde> */
	X86_SIM_X86_JMP(0x14ea, 0xcde, x86_l_cde);
x86_l_14ef:
	/* 0x14ef: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_14f2:
	/* 0x14f2: je     150c <tail_nodeport_nat_ingress_ipv4+0x150c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14f2, 0x150c, x86_l_150c);
x86_l_14f4:
	/* 0x14f4: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_14f7:
	/* 0x14f7: je     150c <tail_nodeport_nat_ingress_ipv4+0x150c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14f7, 0x150c, x86_l_150c);
x86_l_14f9:
	/* 0x14f9: mov    ebp,0xffffff72 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967154ULL);
x86_l_14fe:
	/* 0x14fe: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1501:
	/* 0x1501: jne    76 <tail_nodeport_nat_ingress_ipv4+0x76> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1501, 0x76, x86_l_76);
x86_l_1507:
	/* 0x1507: mov    r15w,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_16, 2ULL);
x86_l_150c:
	/* 0x150c: mov    rbp,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1511:
	/* 0x1511: add    ebp,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_1515:
	/* 0x1515: mov    rdi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_151d:
	/* 0x151d: mov    r9,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RBP, X86_WIDTH_64);
x86_l_1520:
	/* 0x1520: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1523:
	/* 0x1523: add    rdi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_1527:
	/* 0x1527: mov    ebp,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967155ULL);
x86_l_152c:
	/* 0x152c: mov    rsi,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1534:
	/* 0x1534: cmp    rdi,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_64);
x86_l_1537:
	/* 0x1537: ja     76 <tail_nodeport_nat_ingress_ipv4+0x76> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1537, 0x76, x86_l_76);
x86_l_153d:
	/* 0x153d: mov    rdi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1545:
	/* 0x1545: add    r9,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_RDI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1548:
	/* 0x1548: mov    WORD PTR [r9],r14w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R9, X86_R14, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_154c:
	/* 0x154c: movzx  r14d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1550:
	/* 0x1550: mov    ebp,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1554:
	/* 0x1554: add    r14,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RDI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1557:
	/* 0x1557: lea    rdi,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_155b:
	/* 0x155b: add    rdi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_155f:
	/* 0x155f: cmp    rdi,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_64);
x86_l_1562:
	/* 0x1562: jbe    1714 <tail_nodeport_nat_ingress_ipv4+0x1714> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x1562, 0x1714, x86_l_1714);
x86_l_1568:
	/* 0x1568: mov    ebp,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967142ULL);
x86_l_156d:
	/* 0x156d: cmp    BYTE PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1572:
	/* 0x1572: jne    76 <tail_nodeport_nat_ingress_ipv4+0x76> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1572, 0x76, x86_l_76);
x86_l_1578:
	/* 0x1578: jmp    cde <tail_nodeport_nat_ingress_ipv4+0xcde> */
	X86_SIM_X86_JMP(0x1578, 0xcde, x86_l_cde);
x86_l_157d:
	/* 0x157d: mov    ebp,0xffffff51 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967121ULL);
x86_l_1582:
	/* 0x1582: jmp    76 <tail_nodeport_nat_ingress_ipv4+0x76> */
	X86_SIM_X86_JMP(0x1582, 0x76, x86_l_76);
x86_l_1587:
	/* 0x1587: mov    r12d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 10ULL);
x86_l_158d:
	/* 0x158d: movzx  r15d,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1591:
	/* 0x1591: shr    r15d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1595:
	/* 0x1595: mov    rax,QWORD PTR [rip+0x23bc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_159c:
	/* 0x159c: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_159f:
	/* 0x159f: je     15b3 <tail_nodeport_nat_ingress_ipv4+0x15b3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x159f, 0x15b3, x86_l_15b3);
x86_l_15a1:
	/* 0x15a1: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_15a6:
	/* 0x15a6: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15a8:
	/* 0x15a8: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_15aa:
	/* 0x15aa: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_15ad:
	/* 0x15ad: shr    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_15b1:
	/* 0x15b1: jmp    15d6 <tail_nodeport_nat_ingress_ipv4+0x15d6> */
	X86_SIM_X86_JMP(0x15b1, 0x15d6, x86_l_15d6);
x86_l_15b3:
	/* 0x15b3: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_15b8:
	/* 0x15b8: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15ba:
	/* 0x15ba: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_15bc:
	/* 0x15bc: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_15c0:
	/* 0x15c0: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_15ca:
	/* 0x15ca: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_15cd:
	/* 0x15cd: mulx   rcx,rcx,rcx */
	X86_SIM_L_EXEC_MULX(X86_RCX, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_15d2:
	/* 0x15d2: shr    rcx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_15d6:
	/* 0x15d6: add    r12d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_15d9:
	/* 0x15d9: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_15dc:
	/* 0x15dc: mov    DWORD PTR [r14+0x20],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_15e0:
	/* 0x15e0: movzx  edx,BYTE PTR [r14+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_15e5:
	/* 0x15e5: mov    eax,DWORD PTR [r14+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_15e9:
	/* 0x15e9: and    r15b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_15ed:
	/* 0x15ed: mov    rsi,QWORD PTR [rip+0x23bc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_15f4:
	/* 0x15f4: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15f7:
	/* 0x15f7: je     160a <tail_nodeport_nat_ingress_ipv4+0x160a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x15f7, 0x160a, x86_l_160a);
x86_l_15f9:
	/* 0x15f9: mov    rsi,QWORD PTR [rip+0x23bc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1600:
	/* 0x1600: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1602:
	/* 0x1602: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_1605:
	/* 0x1605: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1608:
	/* 0x1608: jmp    160f <tail_nodeport_nat_ingress_ipv4+0x160f> */
	X86_SIM_X86_JMP(0x1608, 0x160f, x86_l_160f);
x86_l_160a:
	/* 0x160a: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_160f:
	/* 0x160f: add    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1611:
	/* 0x1611: or     r15b,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_1614:
	/* 0x1614: cmp    esi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_1616:
	/* 0x1616: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_1619:
	/* 0x1619: jb     1620 <tail_nodeport_nat_ingress_ipv4+0x1620> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1619, 0x1620, x86_l_1620);
x86_l_161b:
	/* 0x161b: cmp    dl,r15b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_8);
x86_l_161e:
	/* 0x161e: je     1630 <tail_nodeport_nat_ingress_ipv4+0x1630> */
	X86_SIM_X86_JCC(X86_CC_E, 0x161e, 0x1630, x86_l_1630);
x86_l_1620:
	/* 0x1620: mov    BYTE PTR [rax+0x2b],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_1624:
	/* 0x1624: mov    DWORD PTR [rax+0x34],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1627:
	/* 0x1627: mov    rcx,QWORD PTR [rip+0x23bc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_162e:
	/* 0x162e: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1630:
	/* 0x1630: test   BYTE PTR [rsp+0x15],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 90194313218ULL);
x86_l_1635:
	/* 0x1635: jne    1ebf <tail_nodeport_nat_ingress_ipv4+0x1ebf> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1635, 0x1ebf, x86_l_1ebf);
x86_l_163b:
	/* 0x163b: movzx  eax,WORD PTR [rax+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_163f:
	/* 0x163f: mov    WORD PTR [rsp+0x18],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1644:
	/* 0x1644: mov    r14,QWORD PTR [rip+0x23bc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_164b:
	/* 0x164b: movzx  eax,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_164f:
	/* 0x164f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1654:
	/* 0x1654: mov    rdi,QWORD PTR [rip+0x23bc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_reverse_nat)));
x86_l_165b:
	/* 0x165b: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1660:
	/* 0x1660: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1662:
	/* 0x1662: mov    r12,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1665:
	/* 0x1665: mov    rcx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1669:
	/* 0x1669: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_166c:
	/* 0x166c: je     17ea <tail_nodeport_nat_ingress_ipv4+0x17ea> */
	X86_SIM_X86_JCC(X86_CC_E, 0x166c, 0x17ea, x86_l_17ea);
x86_l_1672:
	/* 0x1672: mov    edx,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1676:
	/* 0x1676: movzx  esi,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_167a:
	/* 0x167a: mov    esi,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_167c:
	/* 0x167c: mov    DWORD PTR [rsp+0xc],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1680:
	/* 0x1680: lea    rsi,[r12+0x1e] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_1685:
	/* 0x1685: cmp    rsi,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_64);
x86_l_1688:
	/* 0x1688: jbe    1698 <tail_nodeport_nat_ingress_ipv4+0x1698> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x1688, 0x1698, x86_l_1698);
x86_l_168a:
	/* 0x168a: mov    r15d,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967155ULL);
x86_l_1690:
	/* 0x1690: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1693:
	/* 0x1693: jmp    f5a <tail_nodeport_nat_ingress_ipv4+0xf5a> */
	X86_SIM_X86_JMP(0x1693, 0xf5a, x86_l_f5a);
x86_l_1698:
	/* 0x1698: mov    esi,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_169a:
	/* 0x169a: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_169c:
	/* 0x169c: add    edx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_169e:
	/* 0x169e: adc    edx,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_16a1:
	/* 0x16a1: movzx  edi,WORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 24ULL);
x86_l_16a7:
	/* 0x16a7: not    edi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_16a9:
	/* 0x16a9: add    edi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_16ab:
	/* 0x16ab: adc    edi,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_16ae:
	/* 0x16ae: movzx  r8d,di */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_RDI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_16b2:
	/* 0x16b2: shr    edi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_16b5:
	/* 0x16b5: add    edi,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R8, X86_WIDTH_32, X86_ALU_ADD);
x86_l_16b8:
	/* 0x16b8: mov    r8d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RDI, X86_WIDTH_32);
x86_l_16bb:
	/* 0x16bb: shr    r8d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_16bf:
	/* 0x16bf: add    r8d,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_16c2:
	/* 0x16c2: mov    DWORD PTR [r12+0x1a],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_16c7:
	/* 0x16c7: not    r8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_16ca:
	/* 0x16ca: mov    WORD PTR [r12+0x18],r8w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R8, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_16d0:
	/* 0x16d0: movabs rsi,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 2199023255552ULL);
x86_l_16da:
	/* 0x16da: test   r13,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_RSI, X86_WIDTH_64);
x86_l_16dd:
	/* 0x16dd: jne    17ea <tail_nodeport_nat_ingress_ipv4+0x17ea> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x16dd, 0x17ea, x86_l_17ea);
x86_l_16e3:
	/* 0x16e3: movzx  r11d,BYTE PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 20ULL);
x86_l_16e9:
	/* 0x16e9: mov    sil,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_8, 1ULL);
x86_l_16ec:
	/* 0x16ec: cmp    r11d,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 58ULL);
x86_l_16f0:
	/* 0x16f0: je     178c <tail_nodeport_nat_ingress_ipv4+0x178c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x16f0, 0x178c, x86_l_178c);
x86_l_16f6:
	/* 0x16f6: cmp    r11d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 17ULL);
x86_l_16fa:
	/* 0x16fa: je     1783 <tail_nodeport_nat_ingress_ipv4+0x1783> */
	X86_SIM_X86_JCC(X86_CC_E, 0x16fa, 0x1783, x86_l_1783);
x86_l_1700:
	/* 0x1700: cmp    r11d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 6ULL);
x86_l_1704:
	/* 0x1704: jne    1796 <tail_nodeport_nat_ingress_ipv4+0x1796> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1704, 0x1796, x86_l_1796);
x86_l_170a:
	/* 0x170a: mov    edi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 16ULL);
x86_l_170f:
	/* 0x170f: jmp    1791 <tail_nodeport_nat_ingress_ipv4+0x1791> */
	X86_SIM_X86_JMP(0x170f, 0x1791, x86_l_1791);
x86_l_1714:
	/* 0x1714: add    r14,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1717:
	/* 0x1717: test   r8b,r8b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R8, X86_R8, X86_WIDTH_8);
x86_l_171a:
	/* 0x171a: jne    1727 <tail_nodeport_nat_ingress_ipv4+0x1727> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x171a, 0x1727, x86_l_1727);
x86_l_171c:
	/* 0x171c: cmp    WORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1721:
	/* 0x1721: je     1abe <tail_nodeport_nat_ingress_ipv4+0x1abe> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1721, 0x1abe, x86_l_1abe);
x86_l_1727:
	/* 0x1727: test   r11d,r11d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R11, X86_R11, X86_WIDTH_32);
x86_l_172a:
	/* 0x172a: je     1a77 <tail_nodeport_nat_ingress_ipv4+0x1a77> */
	X86_SIM_X86_JCC(X86_CC_E, 0x172a, 0x1a77, x86_l_1a77);
x86_l_1730:
	/* 0x1730: not    r11d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1733:
	/* 0x1733: mov    esi,DWORD PTR [rsp+0x3c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_1737:
	/* 0x1737: add    esi,r11d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R11, X86_WIDTH_32, X86_ALU_ADD);
x86_l_173a:
	/* 0x173a: adc    esi,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_173d:
	/* 0x173d: movzx  r11d,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1741:
	/* 0x1741: not    r11d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1744:
	/* 0x1744: add    r11d,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1747:
	/* 0x1747: jmp    1a83 <tail_nodeport_nat_ingress_ipv4+0x1a83> */
	X86_SIM_X86_JMP(0x1747, 0x1a83, x86_l_1a83);
x86_l_174c:
	/* 0x174c: mov    QWORD PTR [rsp+0x60],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860417ULL);
x86_l_1755:
	/* 0x1755: mov    QWORD PTR [rsp+0x68],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_175a:
	/* 0x175a: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_175f:
	/* 0x175f: mov    rdi,QWORD PTR [rip+0x23b9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1766:
	/* 0x1766: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_176b:
	/* 0x176b: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1770:
	/* 0x1770: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1772:
	/* 0x1772: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1774:
	/* 0x1774: mov    r8,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RBP, X86_WIDTH_64);
x86_l_1777:
	/* 0x1777: jmp    2ce <tail_nodeport_nat_ingress_ipv4+0x2ce> */
	X86_SIM_X86_JMP(0x1777, 0x2ce, x86_l_2ce);
x86_l_177c:
	/* 0x177c: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_177e:
	/* 0x177e: jmp    e8d <tail_nodeport_nat_ingress_ipv4+0xe8d> */
	X86_SIM_X86_JMP(0x177e, 0xe8d, x86_l_e8d);
x86_l_1783:
	/* 0x1783: mov    edi,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 6ULL);
x86_l_1788:
	/* 0x1788: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_178a:
	/* 0x178a: jmp    1791 <tail_nodeport_nat_ingress_ipv4+0x1791> */
	X86_SIM_X86_JMP(0x178a, 0x1791, x86_l_1791);
x86_l_178c:
	/* 0x178c: mov    edi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 2ULL);
x86_l_1791:
	/* 0x1791: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1794:
	/* 0x1794: jmp    179b <tail_nodeport_nat_ingress_ipv4+0x179b> */
	X86_SIM_X86_JMP(0x1794, 0x179b, x86_l_179b);
x86_l_1796:
	/* 0x1796: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1798:
	/* 0x1798: mov    r8b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_8, 1ULL);
x86_l_179b:
	/* 0x179b: movzx  r9d,WORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_17a0:
	/* 0x17a0: test   r9d,r9d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R9, X86_R9, X86_WIDTH_32);
x86_l_17a3:
	/* 0x17a3: je     17e1 <tail_nodeport_nat_ingress_ipv4+0x17e1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x17a3, 0x17e1, x86_l_17e1);
x86_l_17a5:
	/* 0x17a5: movzx  r10d,WORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_17ab:
	/* 0x17ab: mov    ebp,0xffffff72 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967154ULL);
x86_l_17b0:
	/* 0x17b0: cmp    r11d,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 16ULL);
x86_l_17b4:
	/* 0x17b4: jg     17c7 <tail_nodeport_nat_ingress_ipv4+0x17c7> */
	X86_SIM_X86_JCC(X86_CC_G, 0x17b4, 0x17c7, x86_l_17c7);
x86_l_17b6:
	/* 0x17b6: cmp    r11d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 1ULL);
x86_l_17ba:
	/* 0x17ba: je     17e1 <tail_nodeport_nat_ingress_ipv4+0x17e1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x17ba, 0x17e1, x86_l_17e1);
x86_l_17bc:
	/* 0x17bc: cmp    r11d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 6ULL);
x86_l_17c0:
	/* 0x17c0: je     17d7 <tail_nodeport_nat_ingress_ipv4+0x17d7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x17c0, 0x17d7, x86_l_17d7);
x86_l_17c2:
	/* 0x17c2: jmp    1a6f <tail_nodeport_nat_ingress_ipv4+0x1a6f> */
	X86_SIM_X86_JMP(0x17c2, 0x1a6f, x86_l_1a6f);
x86_l_17c7:
	/* 0x17c7: cmp    r11d,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 58ULL);
x86_l_17cb:
	/* 0x17cb: je     17e1 <tail_nodeport_nat_ingress_ipv4+0x17e1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x17cb, 0x17e1, x86_l_17e1);
x86_l_17cd:
	/* 0x17cd: cmp    r11d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 17ULL);
x86_l_17d1:
	/* 0x17d1: jne    1a6f <tail_nodeport_nat_ingress_ipv4+0x1a6f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x17d1, 0x1a6f, x86_l_1a6f);
x86_l_17d7:
	/* 0x17d7: cmp    r9w,r10w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R9, X86_R10, X86_WIDTH_16);
x86_l_17db:
	/* 0x17db: jne    1a35 <tail_nodeport_nat_ingress_ipv4+0x1a35> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x17db, 0x1a35, x86_l_1a35);
x86_l_17e1:
	/* 0x17e1: test   r8b,r8b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R8, X86_R8, X86_WIDTH_8);
x86_l_17e4:
	/* 0x17e4: je     19c5 <tail_nodeport_nat_ingress_ipv4+0x19c5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x17e4, 0x19c5, x86_l_19c5);
x86_l_17ea:
	/* 0x17ea: lea    rax,[r12+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_17ef:
	/* 0x17ef: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17f2:
	/* 0x17f2: mov    r15d,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967162ULL);
x86_l_17f8:
	/* 0x17f8: cmp    rax,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_17fb:
	/* 0x17fb: ja     f5a <tail_nodeport_nat_ingress_ipv4+0xf5a> */
	X86_SIM_X86_JCC(X86_CC_A, 0x17fb, 0xf5a, x86_l_f5a);
x86_l_1801:
	/* 0x1801: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1809:
	/* 0x1809: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_180e:
	/* 0x180e: mov    rdi,QWORD PTR [rip+0x23b9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_1815:
	/* 0x1815: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_181a:
	/* 0x181a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_181c:
	/* 0x181c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_181f:
	/* 0x181f: je     1de3 <tail_nodeport_nat_ingress_ipv4+0x1de3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x181f, 0x1de3, x86_l_1de3);
x86_l_1825:
	/* 0x1825: mov    ebp,DWORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1828:
	/* 0x1828: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1830:
	/* 0x1830: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1835:
	/* 0x1835: mov    rdi,QWORD PTR [rip+0x23b9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_183c:
	/* 0x183c: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1841:
	/* 0x1841: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1843:
	/* 0x1843: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1846:
	/* 0x1846: je     184e <tail_nodeport_nat_ingress_ipv4+0x184e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1846, 0x184e, x86_l_184e);
x86_l_1848:
	/* 0x1848: or     ebp,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_OR, 4ULL);
x86_l_184b:
	/* 0x184b: mov    DWORD PTR [rax+0x18],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_184e:
	/* 0x184e: mov    eax,DWORD PTR [r12+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_1853:
	/* 0x1853: mov    DWORD PTR [rsp+0x70],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1857:
	/* 0x1857: mov    eax,DWORD PTR [r12+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_185c:
	/* 0x185c: mov    DWORD PTR [rsp+0x80],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1863:
	/* 0x1863: movzx  ecx,BYTE PTR [r12+0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 22ULL);
x86_l_1869:
	/* 0x1869: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_186c:
	/* 0x186c: mov    r15d,0xffffff3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967100ULL);
x86_l_1872:
	/* 0x1872: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1875:
	/* 0x1875: jb     f5a <tail_nodeport_nat_ingress_ipv4+0xf5a> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1875, 0xf5a, x86_l_f5a);
x86_l_187b:
	/* 0x187b: lea    edx,[rcx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_187e:
	/* 0x187e: mov    BYTE PTR [r12+0x16],dl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_1883:
	/* 0x1883: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1886:
	/* 0x1886: lea    rsi,[rax+0x1a] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_188a:
	/* 0x188a: mov    r15d,0xffffff67 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967143ULL);
x86_l_1890:
	/* 0x1890: cmp    rsi,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_1894:
	/* 0x1894: ja     f5a <tail_nodeport_nat_ingress_ipv4+0xf5a> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1894, 0xf5a, x86_l_f5a);
x86_l_189a:
	/* 0x189a: movzx  edx,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_189d:
	/* 0x189d: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_189f:
	/* 0x189f: add    ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_18a1:
	/* 0x18a1: adc    ecx,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_18a4:
	/* 0x18a4: movzx  edx,WORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 24ULL);
x86_l_18a8:
	/* 0x18a8: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_18aa:
	/* 0x18aa: add    edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_18ac:
	/* 0x18ac: adc    edx,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_18af:
	/* 0x18af: movzx  ecx,dx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RDX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_18b2:
	/* 0x18b2: shr    edx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_18b5:
	/* 0x18b5: add    edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_18b7:
	/* 0x18b7: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_18b9:
	/* 0x18b9: shr    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_18bc:
	/* 0x18bc: add    ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_18be:
	/* 0x18be: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_18c0:
	/* 0x18c0: mov    WORD PTR [rax+0x18],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_18c4:
	/* 0x18c4: mov    eax,0x45 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 69ULL);
x86_l_18c9:
	/* 0x18c9: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_18ce:
	/* 0x18ce: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_18d1:
	/* 0x18d1: mov    edx,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 64ULL);
x86_l_18d6:
	/* 0x18d6: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18d8:
	/* 0x18d8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18da:
	/* 0x18da: mov    r14d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_32);
x86_l_18dd:
	/* 0x18dd: mov    r15d,0xffffff57 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967127ULL);
x86_l_18e3:
	/* 0x18e3: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_18e6:
	/* 0x18e6: je     18f1 <tail_nodeport_nat_ingress_ipv4+0x18f1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x18e6, 0x18f1, x86_l_18f1);
x86_l_18e8:
	/* 0x18e8: test   r14d,r14d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_32);
x86_l_18eb:
	/* 0x18eb: jne    f5a <tail_nodeport_nat_ingress_ipv4+0xf5a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x18eb, 0xf5a, x86_l_f5a);
x86_l_18f1:
	/* 0x18f1: mov    ebp,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_18f5:
	/* 0x18f5: mov    DWORD PTR [rsp+0x18],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_18f9:
	/* 0x18f9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_18fe:
	/* 0x18fe: mov    rdi,QWORD PTR [rip+0x23b9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_devices)));
x86_l_1905:
	/* 0x1905: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_190a:
	/* 0x190a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_190c:
	/* 0x190c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_190f:
	/* 0x190f: je     191b <tail_nodeport_nat_ingress_ipv4+0x191b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x190f, 0x191b, x86_l_191b);
x86_l_1911:
	/* 0x1911: test   BYTE PTR [rax+0x8],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_1915:
	/* 0x1915: jne    1b2d <tail_nodeport_nat_ingress_ipv4+0x1b2d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1915, 0x1b2d, x86_l_1b2d);
x86_l_191b:
	/* 0x191b: test   r14d,r14d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_32);
x86_l_191e:
	/* 0x191e: je     1ad7 <tail_nodeport_nat_ingress_ipv4+0x1ad7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x191e, 0x1ad7, x86_l_1ad7);
x86_l_1924:
	/* 0x1924: mov    DWORD PTR [rsp+0x18],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1928:
	/* 0x1928: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_192d:
	/* 0x192d: mov    rdi,QWORD PTR [rip+0x23b9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_devices)));
x86_l_1934:
	/* 0x1934: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1939:
	/* 0x1939: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_193b:
	/* 0x193b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_193e:
	/* 0x193e: lea    r12,[rip+0x23b9] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 9145ULL);
x86_l_1945:
	/* 0x1945: cmovne r12,rax */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RAX, X86_WIDTH_64, X86_CC_NE);
x86_l_1949:
	/* 0x1949: mov    r14d,0x64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 100ULL);
x86_l_194f:
	/* 0x194f: cmp    BYTE PTR [rsp+0x60],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 412316860418ULL);
x86_l_1954:
	/* 0x1954: jne    f5a <tail_nodeport_nat_ingress_ipv4+0xf5a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1954, 0xf5a, x86_l_f5a);
x86_l_195a:
	/* 0x195a: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1962:
	/* 0x1962: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1967:
	/* 0x1967: mov    rdi,QWORD PTR [rip+0x23b9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_nodeport_neigh4)));
x86_l_196e:
	/* 0x196e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1970:
	/* 0x1970: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1973:
	/* 0x1973: je     f5a <tail_nodeport_nat_ingress_ipv4+0xf5a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1973, 0xf5a, x86_l_f5a);
x86_l_1979:
	/* 0x1979: mov    rcx,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_197c:
	/* 0x197c: mov    rdx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1980:
	/* 0x1980: lea    rsi,[rcx+0x6] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_1984:
	/* 0x1984: mov    r15d,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967155ULL);
x86_l_198a:
	/* 0x198a: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_198d:
	/* 0x198d: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_1990:
	/* 0x1990: ja     f5a <tail_nodeport_nat_ingress_ipv4+0xf5a> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1990, 0xf5a, x86_l_f5a);
x86_l_1996:
	/* 0x1996: movzx  esi,WORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_199a:
	/* 0x199a: mov    WORD PTR [rcx+0x4],si */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RSI, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_199e:
	/* 0x199e: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19a0:
	/* 0x19a0: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19a2:
	/* 0x19a2: lea    rax,[rcx+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_19a6:
	/* 0x19a6: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_19a9:
	/* 0x19a9: ja     f5a <tail_nodeport_nat_ingress_ipv4+0xf5a> */
	X86_SIM_X86_JCC(X86_CC_A, 0x19a9, 0xf5a, x86_l_f5a);
x86_l_19af:
	/* 0x19af: movzx  eax,WORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_19b5:
	/* 0x19b5: mov    WORD PTR [rcx+0xa],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 10ULL);
x86_l_19b9:
	/* 0x19b9: mov    eax,DWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19bd:
	/* 0x19bd: mov    DWORD PTR [rcx+0x6],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_19c0:
	/* 0x19c0: jmp    1b2d <tail_nodeport_nat_ingress_ipv4+0x1b2d> */
	X86_SIM_X86_JMP(0x19c0, 0x1b2d, x86_l_1b2d);
x86_l_19c5:
	/* 0x19c5: movzx  eax,BYTE PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 40ULL);
x86_l_19ca:
	/* 0x19ca: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_19cd:
	/* 0x19cd: lea    r8,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_19d1:
	/* 0x19d1: add    r8,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_19d5:
	/* 0x19d5: mov    ebp,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967142ULL);
x86_l_19da:
	/* 0x19da: cmp    r8,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RCX, X86_WIDTH_64);
x86_l_19dd:
	/* 0x19dd: ja     1a6f <tail_nodeport_nat_ingress_ipv4+0x1a6f> */
	X86_SIM_X86_JCC(X86_CC_A, 0x19dd, 0x1a6f, x86_l_1a6f);
x86_l_19e3:
	/* 0x19e3: add    rdi,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_19e6:
	/* 0x19e6: movzx  eax,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_19e9:
	/* 0x19e9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_19eb:
	/* 0x19eb: setne  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_NE);
x86_l_19ef:
	/* 0x19ef: or     r8b,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RSI, X86_WIDTH_8, X86_ALU_OR);
x86_l_19f2:
	/* 0x19f2: cmp    r8b,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_8, 1ULL);
x86_l_19f6:
	/* 0x19f6: jne    17ea <tail_nodeport_nat_ingress_ipv4+0x17ea> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x19f6, 0x17ea, x86_l_17ea);
x86_l_19fc:
	/* 0x19fc: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_19fe:
	/* 0x19fe: add    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1a00:
	/* 0x1a00: adc    edx,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_1a03:
	/* 0x1a03: movzx  eax,dx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1a06:
	/* 0x1a06: shr    edx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1a09:
	/* 0x1a09: add    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1a0b:
	/* 0x1a0b: mov    eax,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_1a0d:
	/* 0x1a0d: shr    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1a10:
	/* 0x1a10: add    eax,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1a12:
	/* 0x1a12: cmp    ax,0xffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_16, 65535ULL);
x86_l_1a16:
	/* 0x1a16: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1a18:
	/* 0x1a18: mov    ecx,0xffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 65535ULL);
x86_l_1a1d:
	/* 0x1a1d: cmovne ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_NE);
x86_l_1a20:
	/* 0x1a20: test   sil,sil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_8);
x86_l_1a23:
	/* 0x1a23: cmovne ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_NE);
x86_l_1a26:
	/* 0x1a26: mov    WORD PTR [rdi],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a29:
	/* 0x1a29: mov    r12,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a2c:
	/* 0x1a2c: mov    rcx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a30:
	/* 0x1a30: jmp    17ea <tail_nodeport_nat_ingress_ipv4+0x17ea> */
	X86_SIM_X86_JMP(0x1a30, 0x17ea, x86_l_17ea);
x86_l_1a35:
	/* 0x1a35: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1a3a:
	/* 0x1a3a: add    rax,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1a3d:
	/* 0x1a3d: add    rax,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_1a41:
	/* 0x1a41: mov    ebp,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967155ULL);
x86_l_1a46:
	/* 0x1a46: cmp    rax,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_1a49:
	/* 0x1a49: ja     1a6f <tail_nodeport_nat_ingress_ipv4+0x1a6f> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1a49, 0x1a6f, x86_l_1a6f);
x86_l_1a4b:
	/* 0x1a4b: mov    r11,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1a50:
	/* 0x1a50: lea    rax,[r12+r11*1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_R11, 0), 0ULL);
x86_l_1a54:
	/* 0x1a54: mov    WORD PTR [r12+r11*1],r9w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R9, X86_WIDTH_16, X86_MEM_AUX(X86_R11, 0), 0ULL);
x86_l_1a59:
	/* 0x1a59: lea    r11,[rdi+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1a5d:
	/* 0x1a5d: add    r11,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_1a61:
	/* 0x1a61: mov    ebp,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967142ULL);
x86_l_1a66:
	/* 0x1a66: cmp    r11,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R11, X86_RCX, X86_WIDTH_64);
x86_l_1a69:
	/* 0x1a69: jbe    1b8b <tail_nodeport_nat_ingress_ipv4+0x1b8b> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x1a69, 0x1b8b, x86_l_1b8b);
x86_l_1a6f:
	/* 0x1a6f: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a72:
	/* 0x1a72: jmp    d1 <tail_nodeport_nat_ingress_ipv4+0xd1> */
	X86_SIM_X86_JMP(0x1a72, 0xd1, x86_l_d1);
x86_l_1a77:
	/* 0x1a77: movzx  r11d,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1a7b:
	/* 0x1a7b: not    r11d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1a7e:
	/* 0x1a7e: add    r11d,DWORD PTR [rsp+0x3c] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R11, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 60ULL);
x86_l_1a83:
	/* 0x1a83: setb   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_B);
x86_l_1a87:
	/* 0x1a87: movzx  edi,dil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDI, X86_RDI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1a8b:
	/* 0x1a8b: add    edi,r11d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R11, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1a8e:
	/* 0x1a8e: movzx  r11d,di */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R11, X86_RDI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1a92:
	/* 0x1a92: shr    edi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1a95:
	/* 0x1a95: add    edi,r11d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R11, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1a98:
	/* 0x1a98: mov    r11d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_RDI, X86_WIDTH_32);
x86_l_1a9b:
	/* 0x1a9b: shr    r11d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1a9f:
	/* 0x1a9f: add    r11d,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1aa2:
	/* 0x1aa2: cmp    r11w,0xffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_16, 65535ULL);
x86_l_1aa7:
	/* 0x1aa7: not    r11d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1aaa:
	/* 0x1aaa: mov    edi,0xffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 65535ULL);
x86_l_1aaf:
	/* 0x1aaf: cmovne edi,r11d */
	X86_SIM_L_EXEC_CMOV(X86_RDI, X86_R11, X86_WIDTH_32, X86_CC_NE);
x86_l_1ab3:
	/* 0x1ab3: test   r8b,r8b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R8, X86_R8, X86_WIDTH_8);
x86_l_1ab6:
	/* 0x1ab6: cmovne edi,r11d */
	X86_SIM_L_EXEC_CMOV(X86_RDI, X86_R11, X86_WIDTH_32, X86_CC_NE);
x86_l_1aba:
	/* 0x1aba: mov    WORD PTR [r14],di */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDI, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1abe:
	/* 0x1abe: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1ac1:
	/* 0x1ac1: je     cde <tail_nodeport_nat_ingress_ipv4+0xcde> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1ac1, 0xcde, x86_l_cde);
x86_l_1ac7:
	/* 0x1ac7: jmp    1469 <tail_nodeport_nat_ingress_ipv4+0x1469> */
	X86_SIM_X86_JMP(0x1ac7, 0x1469, x86_l_1469);
x86_l_1acc:
	/* 0x1acc: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_1ad2:
	/* 0x1ad2: jmp    7ac <tail_nodeport_nat_ingress_ipv4+0x7ac> */
	X86_SIM_X86_JMP(0x1ad2, 0x7ac, x86_l_7ac);
x86_l_1ad7:
	/* 0x1ad7: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ada:
	/* 0x1ada: lea    rcx,[rax+0x6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_1ade:
	/* 0x1ade: mov    r15d,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967155ULL);
x86_l_1ae4:
	/* 0x1ae4: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ae7:
	/* 0x1ae7: cmp    rcx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_1aeb:
	/* 0x1aeb: ja     f5a <tail_nodeport_nat_ingress_ipv4+0xf5a> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1aeb, 0xf5a, x86_l_f5a);
x86_l_1af1:
	/* 0x1af1: movzx  ecx,WORD PTR [rsp+0x9e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 158ULL);
x86_l_1af9:
	/* 0x1af9: mov    WORD PTR [rax+0x4],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1afd:
	/* 0x1afd: mov    ecx,DWORD PTR [rsp+0x9a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 154ULL);
x86_l_1b04:
	/* 0x1b04: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b06:
	/* 0x1b06: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b09:
	/* 0x1b09: lea    rcx,[rax+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1b0d:
	/* 0x1b0d: cmp    rcx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_1b11:
	/* 0x1b11: ja     f5a <tail_nodeport_nat_ingress_ipv4+0xf5a> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1b11, 0xf5a, x86_l_f5a);
x86_l_1b17:
	/* 0x1b17: movzx  ecx,WORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 152ULL);
x86_l_1b1f:
	/* 0x1b1f: mov    WORD PTR [rax+0xa],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 10ULL);
x86_l_1b23:
	/* 0x1b23: mov    ecx,DWORD PTR [rsp+0x94] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_1b2a:
	/* 0x1b2a: mov    DWORD PTR [rax+0x6],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_1b2d:
	/* 0x1b2d: cmp    DWORD PTR [rbx+0xc],ebp */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1b30:
	/* 0x1b30: jne    1b3c <tail_nodeport_nat_ingress_ipv4+0x1b3c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1b30, 0x1b3c, x86_l_1b3c);
x86_l_1b32:
	/* 0x1b32: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_1b37:
	/* 0x1b37: jmp    325 <tail_nodeport_nat_ingress_ipv4+0x325> */
	X86_SIM_X86_JMP(0x1b37, 0x325, x86_l_325);
x86_l_1b3c:
	/* 0x1b3c: mov    eax,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 23ULL);
x86_l_1b41:
	/* 0x1b41: mov    edi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_32);
x86_l_1b43:
	/* 0x1b43: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b45:
	/* 0x1b45: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b47:
	/* 0x1b47: mov    ebp,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_1b49:
	/* 0x1b49: jmp    1ebf <tail_nodeport_nat_ingress_ipv4+0x1ebf> */
	X86_SIM_X86_JMP(0x1b49, 0x1ebf, x86_l_1ebf);
x86_l_1b4e:
	/* 0x1b4e: mov    QWORD PTR [rsp+0x28],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1b53:
	/* 0x1b53: mov    r12,r10 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R10, X86_WIDTH_64);
x86_l_1b56:
	/* 0x1b56: mov    r15,r9 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R9, X86_WIDTH_64);
x86_l_1b59:
	/* 0x1b59: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1b5e:
	/* 0x1b5e: mov    rdi,QWORD PTR [rip+0x23b9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv4_frag_datagrams)));
x86_l_1b65:
	/* 0x1b65: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1b6a:
	/* 0x1b6a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b6c:
	/* 0x1b6c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b6f:
	/* 0x1b6f: je     1d3f <tail_nodeport_nat_ingress_ipv4+0x1d3f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1b6f, 0x1d3f, x86_l_1d3f);
x86_l_1b75:
	/* 0x1b75: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b77:
	/* 0x1b77: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b7b:
	/* 0x1b7b: jmp    1dcc <tail_nodeport_nat_ingress_ipv4+0x1dcc> */
	X86_SIM_X86_JMP(0x1b7b, 0x1dcc, x86_l_1dcc);
x86_l_1b80:
	/* 0x1b80: mov    r15d,0xffffff63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967139ULL);
x86_l_1b86:
	/* 0x1b86: jmp    f5a <tail_nodeport_nat_ingress_ipv4+0xf5a> */
	X86_SIM_X86_JMP(0x1b86, 0xf5a, x86_l_f5a);
x86_l_1b8b:
	/* 0x1b8b: add    rax,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1b8e:
	/* 0x1b8e: test   sil,sil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_8);
x86_l_1b91:
	/* 0x1b91: jne    1b9d <tail_nodeport_nat_ingress_ipv4+0x1b9d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1b91, 0x1b9d, x86_l_1b9d);
x86_l_1b93:
	/* 0x1b93: cmp    WORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b97:
	/* 0x1b97: je     17e1 <tail_nodeport_nat_ingress_ipv4+0x17e1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1b97, 0x17e1, x86_l_17e1);
x86_l_1b9d:
	/* 0x1b9d: test   r10d,r10d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R10, X86_R10, X86_WIDTH_32);
x86_l_1ba0:
	/* 0x1ba0: je     1d55 <tail_nodeport_nat_ingress_ipv4+0x1d55> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1ba0, 0x1d55, x86_l_1d55);
x86_l_1ba6:
	/* 0x1ba6: not    r10d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1ba9:
	/* 0x1ba9: add    r10d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R9, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1bac:
	/* 0x1bac: adc    r10d,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_1bb0:
	/* 0x1bb0: movzx  r11d,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1bb4:
	/* 0x1bb4: not    r11d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1bb7:
	/* 0x1bb7: add    r11d,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_R10, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1bba:
	/* 0x1bba: jmp    1d5f <tail_nodeport_nat_ingress_ipv4+0x1d5f> */
	X86_SIM_X86_JMP(0x1bba, 0x1d5f, x86_l_1d5f);
x86_l_1bbf:
	/* 0x1bbf: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1bc4:
	/* 0x1bc4: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1bc9:
	/* 0x1bc9: mov    QWORD PTR [rsp+0x28],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1bce:
	/* 0x1bce: mov    rdi,QWORD PTR [rip+0x23b9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv4_frag_datagrams)));
x86_l_1bd5:
	/* 0x1bd5: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1bda:
	/* 0x1bda: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1bdc:
	/* 0x1bdc: mov    r15,r9 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R9, X86_WIDTH_64);
x86_l_1bdf:
	/* 0x1bdf: mov    r12,r10 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R10, X86_WIDTH_64);
x86_l_1be2:
	/* 0x1be2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1be4:
	/* 0x1be4: mov    r8,QWORD PTR [rip+0x23b9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R8, (void *)(long)(((__u64)(long)&__config_enable_ipv4_fragments)));
x86_l_1beb:
	/* 0x1beb: mov    r11,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1bf0:
	/* 0x1bf0: mov    r10,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R10, X86_R12, X86_WIDTH_64);
x86_l_1bf3:
	/* 0x1bf3: mov    r9,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_R15, X86_WIDTH_64);
x86_l_1bf6:
	/* 0x1bf6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1bf8:
	/* 0x1bf8: je     1034 <tail_nodeport_nat_ingress_ipv4+0x1034> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1bf8, 0x1034, x86_l_1034);
x86_l_1bfe:
	/* 0x1bfe: mov    r14,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c02:
	/* 0x1c02: sub    r14,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 0ULL);
x86_l_1c05:
	/* 0x1c05: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1c0e:
	/* 0x1c0e: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1c17:
	/* 0x1c17: movabs rax,0x6b0085010a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 459570217226ULL);
x86_l_1c21:
	/* 0x1c21: add    rax,0x100 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 256ULL);
x86_l_1c27:
	/* 0x1c27: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1c2f:
	/* 0x1c2f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1c34:
	/* 0x1c34: mov    rdi,QWORD PTR [rip+0x23b9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1c3b:
	/* 0x1c3b: lea    rsi,[rsp+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1c43:
	/* 0x1c43: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c45:
	/* 0x1c45: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1c48:
	/* 0x1c48: je     1da1 <tail_nodeport_nat_ingress_ipv4+0x1da1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1c48, 0x1da1, x86_l_1da1);
x86_l_1c4e:
	/* 0x1c4e: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1c51:
	/* 0x1c51: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1c55:
	/* 0x1c55: jmp    1dcc <tail_nodeport_nat_ingress_ipv4+0x1dcc> */
	X86_SIM_X86_JMP(0x1c55, 0x1dcc, x86_l_1dcc);
x86_l_1c5a:
	/* 0x1c5a: mov    ebp,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_1c5f:
	/* 0x1c5f: cmp    dx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_16, 6ULL);
x86_l_1c63:
	/* 0x1c63: jne    1ca0 <tail_nodeport_nat_ingress_ipv4+0x1ca0> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1c63, 0x1ca0, x86_l_1ca0);
x86_l_1c65:
	/* 0x1c65: mov    ecx,DWORD PTR [rsp+0x3c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_1c69:
	/* 0x1c69: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1c6b:
	/* 0x1c6b: shr    ecx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_1c6e:
	/* 0x1c6e: and    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_1c71:
	/* 0x1c71: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1c73:
	/* 0x1c73: mov    WORD PTR [r14+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1c78:
	/* 0x1c78: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1c7a:
	/* 0x1c7a: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_1c7f:
	/* 0x1c7f: mov    ebp,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 21600ULL);
x86_l_1c84:
	/* 0x1c84: cmove  ebp,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_1c87:
	/* 0x1c87: mov    rax,QWORD PTR [rip+0x23b9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1c8e:
	/* 0x1c8e: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c91:
	/* 0x1c91: je     1ca0 <tail_nodeport_nat_ingress_ipv4+0x1ca0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1c91, 0x1ca0, x86_l_1ca0);
x86_l_1c93:
	/* 0x1c93: mov    rax,QWORD PTR [rip+0x23b9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1c9a:
	/* 0x1c9a: imul   ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_1c9d:
	/* 0x1c9d: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1ca0:
	/* 0x1ca0: movzx  r15d,WORD PTR [rsp+0x3c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 60ULL);
x86_l_1ca6:
	/* 0x1ca6: shr    r15d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1caa:
	/* 0x1caa: mov    rax,QWORD PTR [rip+0x23b9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1cb1:
	/* 0x1cb1: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cb4:
	/* 0x1cb4: je     1cc5 <tail_nodeport_nat_ingress_ipv4+0x1cc5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1cb4, 0x1cc5, x86_l_1cc5);
x86_l_1cb6:
	/* 0x1cb6: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_1cbb:
	/* 0x1cbb: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1cbd:
	/* 0x1cbd: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1cbf:
	/* 0x1cbf: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_1cc3:
	/* 0x1cc3: jmp    1ce8 <tail_nodeport_nat_ingress_ipv4+0x1ce8> */
	X86_SIM_X86_JMP(0x1cc3, 0x1ce8, x86_l_1ce8);
x86_l_1cc5:
	/* 0x1cc5: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1cca:
	/* 0x1cca: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ccc:
	/* 0x1ccc: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1cce:
	/* 0x1cce: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1cd2:
	/* 0x1cd2: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_1cdc:
	/* 0x1cdc: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1cdf:
	/* 0x1cdf: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1ce4:
	/* 0x1ce4: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_1ce8:
	/* 0x1ce8: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1cea:
	/* 0x1cea: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_1ced:
	/* 0x1ced: mov    DWORD PTR [r14+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1cf1:
	/* 0x1cf1: movzx  ecx,BYTE PTR [r14+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_1cf6:
	/* 0x1cf6: mov    edx,DWORD PTR [r14+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1cfa:
	/* 0x1cfa: and    r15b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_1cfe:
	/* 0x1cfe: mov    rsi,QWORD PTR [rip+0x23b9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1d05:
	/* 0x1d05: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d08:
	/* 0x1d08: je     1d1b <tail_nodeport_nat_ingress_ipv4+0x1d1b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1d08, 0x1d1b, x86_l_1d1b);
x86_l_1d0a:
	/* 0x1d0a: mov    rsi,QWORD PTR [rip+0x23b9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1d11:
	/* 0x1d11: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d13:
	/* 0x1d13: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_1d16:
	/* 0x1d16: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1d19:
	/* 0x1d19: jmp    1d20 <tail_nodeport_nat_ingress_ipv4+0x1d20> */
	X86_SIM_X86_JMP(0x1d19, 0x1d20, x86_l_1d20);
x86_l_1d1b:
	/* 0x1d1b: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_1d20:
	/* 0x1d20: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1d22:
	/* 0x1d22: or     r15b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_1d25:
	/* 0x1d25: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_1d27:
	/* 0x1d27: jb     1d32 <tail_nodeport_nat_ingress_ipv4+0x1d32> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1d27, 0x1d32, x86_l_1d32);
x86_l_1d29:
	/* 0x1d29: cmp    cl,r15b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R15, X86_WIDTH_8);
x86_l_1d2c:
	/* 0x1d2c: je     a94 <tail_nodeport_nat_ingress_ipv4+0xa94> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1d2c, 0xa94, x86_l_a94);
x86_l_1d32:
	/* 0x1d32: mov    BYTE PTR [r14+0x2b],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_1d36:
	/* 0x1d36: mov    DWORD PTR [r14+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1d3a:
	/* 0x1d3a: jmp    a8b <tail_nodeport_nat_ingress_ipv4+0xa8b> */
	X86_SIM_X86_JMP(0x1d3a, 0xa8b, x86_l_a8b);
x86_l_1d3f:
	/* 0x1d3f: mov    r15d,0xffffff51 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967121ULL);
x86_l_1d45:
	/* 0x1d45: jmp    f5a <tail_nodeport_nat_ingress_ipv4+0xf5a> */
	X86_SIM_X86_JMP(0x1d45, 0xf5a, x86_l_f5a);
x86_l_1d4a:
	/* 0x1d4a: mov    r15d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 2ULL);
x86_l_1d50:
	/* 0x1d50: jmp    1182 <tail_nodeport_nat_ingress_ipv4+0x1182> */
	X86_SIM_X86_JMP(0x1d50, 0x1182, x86_l_1182);
x86_l_1d55:
	/* 0x1d55: movzx  r11d,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1d59:
	/* 0x1d59: not    r11d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1d5c:
	/* 0x1d5c: add    r11d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_R9, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1d5f:
	/* 0x1d5f: setb   r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_B);
x86_l_1d63:
	/* 0x1d63: movzx  r9d,r9b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R9, X86_R9, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1d67:
	/* 0x1d67: add    r9d,r11d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R11, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1d6a:
	/* 0x1d6a: movzx  r10d,r9w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R10, X86_R9, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1d6e:
	/* 0x1d6e: shr    r9d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1d72:
	/* 0x1d72: add    r9d,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R10, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1d75:
	/* 0x1d75: mov    r10d,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_R10, X86_R9, X86_WIDTH_32);
x86_l_1d78:
	/* 0x1d78: shr    r10d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1d7c:
	/* 0x1d7c: add    r10d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R9, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1d7f:
	/* 0x1d7f: cmp    r10w,0xffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_16, 65535ULL);
x86_l_1d84:
	/* 0x1d84: not    r10d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1d87:
	/* 0x1d87: mov    r9d,0xffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 65535ULL);
x86_l_1d8d:
	/* 0x1d8d: cmovne r9d,r10d */
	X86_SIM_L_EXEC_CMOV(X86_R9, X86_R10, X86_WIDTH_32, X86_CC_NE);
x86_l_1d91:
	/* 0x1d91: test   sil,sil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_8);
x86_l_1d94:
	/* 0x1d94: cmovne r9d,r10d */
	X86_SIM_L_EXEC_CMOV(X86_R9, X86_R10, X86_WIDTH_32, X86_CC_NE);
x86_l_1d98:
	/* 0x1d98: mov    WORD PTR [rax],r9w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R9, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d9c:
	/* 0x1d9c: jmp    17e1 <tail_nodeport_nat_ingress_ipv4+0x17e1> */
	X86_SIM_X86_JMP(0x1d9c, 0x17e1, x86_l_17e1);
x86_l_1da1:
	/* 0x1da1: mov    QWORD PTR [rsp+0x18],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215105ULL);
x86_l_1daa:
	/* 0x1daa: mov    QWORD PTR [rsp+0x20],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1daf:
	/* 0x1daf: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1db4:
	/* 0x1db4: mov    rdi,QWORD PTR [rip+0x23b9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1dbb:
	/* 0x1dbb: lea    rsi,[rsp+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1dc3:
	/* 0x1dc3: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1dc8:
	/* 0x1dc8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1dca:
	/* 0x1dca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dcc:
	/* 0x1dcc: mov    r9,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_R15, X86_WIDTH_64);
x86_l_1dcf:
	/* 0x1dcf: mov    r10,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R10, X86_R12, X86_WIDTH_64);
x86_l_1dd2:
	/* 0x1dd2: mov    r11,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1dd7:
	/* 0x1dd7: mov    r8,QWORD PTR [rip+0x23b9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R8, (void *)(long)(((__u64)(long)&__config_enable_ipv4_fragments)));
x86_l_1dde:
	/* 0x1dde: jmp    1034 <tail_nodeport_nat_ingress_ipv4+0x1034> */
	X86_SIM_X86_JMP(0x1dde, 0x1034, x86_l_1034);
x86_l_1de3:
	/* 0x1de3: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1de5:
	/* 0x1de5: jmp    1828 <tail_nodeport_nat_ingress_ipv4+0x1828> */
	X86_SIM_X86_JMP(0x1de5, 0x1828, x86_l_1828);
x86_l_1dea:
	/* 0x1dea: mov    r13d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 60ULL);
x86_l_1df0:
	/* 0x1df0: cmp    r12b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_8, 6ULL);
x86_l_1df4:
	/* 0x1df4: jne    1e2d <tail_nodeport_nat_ingress_ipv4+0x1e2d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1df4, 0x1e2d, x86_l_1e2d);
x86_l_1df6:
	/* 0x1df6: mov    eax,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_1df8:
	/* 0x1df8: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1dfa:
	/* 0x1dfa: shr    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_1dfd:
	/* 0x1dfd: and    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_1e00:
	/* 0x1e00: or     ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1e02:
	/* 0x1e02: mov    WORD PTR [r14+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1e07:
	/* 0x1e07: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1e09:
	/* 0x1e09: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_1e0e:
	/* 0x1e0e: mov    r13d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 21600ULL);
x86_l_1e14:
	/* 0x1e14: cmove  r13d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_1e18:
	/* 0x1e18: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e1c:
	/* 0x1e1c: je     1e2d <tail_nodeport_nat_ingress_ipv4+0x1e2d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1e1c, 0x1e2d, x86_l_1e2d);
x86_l_1e1e:
	/* 0x1e1e: mov    rax,QWORD PTR [rip+0x23b9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1e25:
	/* 0x1e25: imul   r13d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_1e29:
	/* 0x1e29: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1e2d:
	/* 0x1e2d: movzx  r12d,dx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_RDX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1e31:
	/* 0x1e31: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1e35:
	/* 0x1e35: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e39:
	/* 0x1e39: je     1e4a <tail_nodeport_nat_ingress_ipv4+0x1e4a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1e39, 0x1e4a, x86_l_1e4a);
x86_l_1e3b:
	/* 0x1e3b: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_1e40:
	/* 0x1e40: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e42:
	/* 0x1e42: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1e44:
	/* 0x1e44: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_1e48:
	/* 0x1e48: jmp    1e6d <tail_nodeport_nat_ingress_ipv4+0x1e6d> */
	X86_SIM_X86_JMP(0x1e48, 0x1e6d, x86_l_1e6d);
x86_l_1e4a:
	/* 0x1e4a: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1e4f:
	/* 0x1e4f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e51:
	/* 0x1e51: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1e53:
	/* 0x1e53: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1e57:
	/* 0x1e57: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_1e61:
	/* 0x1e61: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1e64:
	/* 0x1e64: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1e69:
	/* 0x1e69: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_1e6d:
	/* 0x1e6d: add    r13d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1e70:
	/* 0x1e70: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_1e73:
	/* 0x1e73: mov    DWORD PTR [r14+0x20],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e77:
	/* 0x1e77: movzx  ecx,BYTE PTR [r14+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_1e7c:
	/* 0x1e7c: mov    edx,DWORD PTR [r14+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1e80:
	/* 0x1e80: and    r12b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_1e84:
	/* 0x1e84: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e88:
	/* 0x1e88: je     1e9b <tail_nodeport_nat_ingress_ipv4+0x1e9b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1e88, 0x1e9b, x86_l_1e9b);
x86_l_1e8a:
	/* 0x1e8a: mov    rsi,QWORD PTR [rip+0x23b9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1e91:
	/* 0x1e91: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e93:
	/* 0x1e93: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_1e96:
	/* 0x1e96: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1e99:
	/* 0x1e99: jmp    1ea0 <tail_nodeport_nat_ingress_ipv4+0x1ea0> */
	X86_SIM_X86_JMP(0x1e99, 0x1ea0, x86_l_1ea0);
x86_l_1e9b:
	/* 0x1e9b: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_1ea0:
	/* 0x1ea0: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1ea2:
	/* 0x1ea2: or     r12b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_1ea5:
	/* 0x1ea5: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_1ea7:
	/* 0x1ea7: jb     1eae <tail_nodeport_nat_ingress_ipv4+0x1eae> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1ea7, 0x1eae, x86_l_1eae);
x86_l_1ea9:
	/* 0x1ea9: cmp    cl,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R12, X86_WIDTH_8);
x86_l_1eac:
	/* 0x1eac: je     1ebf <tail_nodeport_nat_ingress_ipv4+0x1ebf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1eac, 0x1ebf, x86_l_1ebf);
x86_l_1eae:
	/* 0x1eae: mov    BYTE PTR [r14+0x2b],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_1eb2:
	/* 0x1eb2: mov    DWORD PTR [r14+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1eb6:
	/* 0x1eb6: mov    rax,QWORD PTR [rip+0x23b9] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_1ebd:
	/* 0x1ebd: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ebf:
	/* 0x1ebf: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ec2:
	/* 0x1ec2: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_1ec4:
	/* 0x1ec4: js     d1 <tail_nodeport_nat_ingress_ipv4+0xd1> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1ec4, 0xd1, x86_l_d1);
x86_l_1eca:
	/* 0x1eca: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_1ecd:
	/* 0x1ecd: je     d1 <tail_nodeport_nat_ingress_ipv4+0xd1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1ecd, 0xd1, x86_l_d1);
x86_l_1ed3:
	/* 0x1ed3: cmp    ebp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_1ed6:
	/* 0x1ed6: je     89 <tail_nodeport_nat_ingress_ipv4+0x89> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1ed6, 0x89, x86_l_89);
x86_l_1edc:
	/* 0x1edc: jmp    325 <tail_nodeport_nat_ingress_ipv4+0x325> */
	X86_SIM_X86_JMP(0x1edc, 0x325, x86_l_325);
x86_l_1ee1:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
