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
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0xc8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 200ULL);
x86_l_a:
	/* 0xa: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: mov    rax,QWORD PTR [rip+0x23c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_nodeport_port_max)));
x86_l_14:
	/* 0x14: movzx  r14d,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_18:
	/* 0x18: mov    rax,QWORD PTR [rip+0x23c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_1f:
	/* 0x1f: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21:
	/* 0x21: mov    DWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_29:
	/* 0x29: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e:
	/* 0x2e: mov    rdi,QWORD PTR [rip+0x23c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_35:
	/* 0x35: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3a:
	/* 0x3a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c:
	/* 0x3c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3f:
	/* 0x3f: je     c44 <tail_nodeport_nat_ingress_ipv4+0xc44> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3f, 0xc44, x86_l_c44);
x86_l_45:
	/* 0x45: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_47:
	/* 0x47: mov    DWORD PTR [rsp+0xb4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 180ULL);
x86_l_4e:
	/* 0x4e: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_56:
	/* 0x56: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_59:
	/* 0x59: mov    r15,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5d:
	/* 0x5d: lea    rcx,[rax+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_61:
	/* 0x61: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_66:
	/* 0x66: cmp    rcx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_69:
	/* 0x69: jbe    1df <tail_nodeport_nat_ingress_ipv4+0x1df> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x69, 0x1df, x86_l_1df);
x86_l_6f:
	/* 0x6f: cmp    ebp,0xffffff53 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4294967123ULL);
x86_l_75:
	/* 0x75: je     82 <tail_nodeport_nat_ingress_ipv4+0x82> */
	X86_SIM_X86_JCC(X86_CC_E, 0x75, 0x82, x86_l_82);
x86_l_77:
	/* 0x77: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7a:
	/* 0x7a: cmp    ebp,0xffffff59 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 4294967129ULL);
x86_l_80:
	/* 0x80: jne    ca <tail_nodeport_nat_ingress_ipv4+0xca> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x80, 0xca, x86_l_ca);
x86_l_82:
	/* 0x82: mov    DWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_8a:
	/* 0x8a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_8f:
	/* 0x8f: mov    rdi,QWORD PTR [rip+0x23c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_96:
	/* 0x96: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_9b:
	/* 0x9b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9d:
	/* 0x9d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a0:
	/* 0xa0: je     a9 <tail_nodeport_nat_ingress_ipv4+0xa9> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa0, 0xa9, x86_l_a9);
x86_l_a2:
	/* 0xa2: mov    DWORD PTR [rax+0x14],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345921ULL);
x86_l_a9:
	/* 0xa9: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_ae:
	/* 0xae: mov    rsi,QWORD PTR [rip+0x23c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_b5:
	/* 0xb5: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_b8:
	/* 0xb8: mov    edx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_bd:
	/* 0xbd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bf:
	/* 0xbf: mov    ebp,0xffffff74 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967156ULL);
x86_l_c4:
	/* 0xc4: mov    r12d,0x700 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1792ULL);
x86_l_ca:
	/* 0xca: mov    r14d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RBP, X86_WIDTH_32);
x86_l_cd:
	/* 0xcd: neg    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_d0:
	/* 0xd0: cmovs  r14d,ebp */
	X86_SIM_L_EXEC_CMOV(X86_R14, X86_RBP, X86_WIDTH_32, X86_CC_S);
x86_l_d4:
	/* 0xd4: mov    DWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_dc:
	/* 0xdc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e1:
	/* 0xe1: mov    rdi,QWORD PTR [rip+0x23c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_e8:
	/* 0xe8: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_ed:
	/* 0xed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ef:
	/* 0xef: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f2:
	/* 0xf2: je     fd <tail_nodeport_nat_ingress_ipv4+0xfd> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf2, 0xfd, x86_l_fd);
x86_l_f4:
	/* 0xf4: mov    ecx,DWORD PTR [rsp+0xb4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 180ULL);
x86_l_fb:
	/* 0xfb: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fd:
	/* 0xfd: mov    DWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_105:
	/* 0x105: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_10a:
	/* 0x10a: mov    rdi,QWORD PTR [rip+0x23c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_111:
	/* 0x111: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_116:
	/* 0x116: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_118:
	/* 0x118: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_11b:
	/* 0x11b: je     124 <tail_nodeport_nat_ingress_ipv4+0x124> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11b, 0x124, x86_l_124);
x86_l_11d:
	/* 0x11d: mov    DWORD PTR [rax+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_124:
	/* 0x124: mov    DWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_12c:
	/* 0x12c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_131:
	/* 0x131: mov    rdi,QWORD PTR [rip+0x23c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_138:
	/* 0x138: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_13d:
	/* 0x13d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13f:
	/* 0x13f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_142:
	/* 0x142: je     14e <tail_nodeport_nat_ingress_ipv4+0x14e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x142, 0x14e, x86_l_14e);
x86_l_144:
	/* 0x144: movzx  ecx,r14b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R14, X86_WIDTH_32, X86_WIDTH_8);
x86_l_148:
	/* 0x148: or     ecx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R12, X86_WIDTH_32, X86_ALU_OR);
x86_l_14b:
	/* 0x14b: mov    DWORD PTR [rax+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14e:
	/* 0x14e: mov    DWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_156:
	/* 0x156: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_15b:
	/* 0x15b: mov    rdi,QWORD PTR [rip+0x23c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_162:
	/* 0x162: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_167:
	/* 0x167: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_169:
	/* 0x169: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_16c:
	/* 0x16c: je     175 <tail_nodeport_nat_ingress_ipv4+0x175> */
	X86_SIM_X86_JCC(X86_CC_E, 0x16c, 0x175, x86_l_175);
x86_l_16e:
	/* 0x16e: mov    DWORD PTR [rax+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_175:
	/* 0x175: mov    DWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_17d:
	/* 0x17d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_182:
	/* 0x182: mov    rdi,QWORD PTR [rip+0x23c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_189:
	/* 0x189: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_18e:
	/* 0x18e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_190:
	/* 0x190: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_193:
	/* 0x193: je     19c <tail_nodeport_nat_ingress_ipv4+0x19c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x193, 0x19c, x86_l_19c);
x86_l_195:
	/* 0x195: mov    DWORD PTR [rax+0x10],0x9d96801 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68884719617ULL);
x86_l_19c:
	/* 0x19c: mov    r15,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a0:
	/* 0x1a0: sub    r15,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 0ULL);
x86_l_1a3:
	/* 0x1a3: movabs rax,0x6809d90100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 446841815296ULL);
x86_l_1ad:
	/* 0x1ad: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1b2:
	/* 0x1b2: mov    BYTE PTR [rsp+0x18],r14b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1b7:
	/* 0x1b7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1bc:
	/* 0x1bc: mov    rdi,QWORD PTR [rip+0x23c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1c3:
	/* 0x1c3: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1c8:
	/* 0x1c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ca:
	/* 0x1ca: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1cd:
	/* 0x1cd: je     2db <tail_nodeport_nat_ingress_ipv4+0x2db> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1cd, 0x2db, x86_l_2db);
x86_l_1d3:
	/* 0x1d3: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1d6:
	/* 0x1d6: add    QWORD PTR [rax+0x8],r15 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1da:
	/* 0x1da: jmp    303 <tail_nodeport_nat_ingress_ipv4+0x303> */
	X86_SIM_X86_JMP(0x1da, 0x303, x86_l_303);
x86_l_1df:
	/* 0x1df: movabs r9,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_64, 2199023255552ULL);
x86_l_1e9:
	/* 0x1e9: movabs r10,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_64, 1099511627776ULL);
x86_l_1f3:
	/* 0x1f3: movzx  edx,WORD PTR [rax+0x12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18ULL);
x86_l_1f7:
	/* 0x1f7: movzx  ecx,BYTE PTR [rax+0x17] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 23ULL);
x86_l_1fb:
	/* 0x1fb: mov    rsi,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RCX, X86_WIDTH_64);
x86_l_1fe:
	/* 0x1fe: shl    rsi,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_202:
	/* 0x202: or     rsi,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_64, X86_ALU_OR);
x86_l_205:
	/* 0x205: movzx  edi,WORD PTR [rax+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 20ULL);
x86_l_209:
	/* 0x209: lea    r8,[rsi+r10*1] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_R10, 0), 0ULL);
x86_l_20d:
	/* 0x20d: test   edi,0xff3f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDI, X86_WIDTH_32, 65343ULL);
x86_l_213:
	/* 0x213: cmove  r8,rsi */
	X86_SIM_L_EXEC_CMOV(X86_R8, X86_RSI, X86_WIDTH_64, X86_CC_E);
x86_l_217:
	/* 0x217: lea    r12,[r8+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_21b:
	/* 0x21b: mov    BYTE PTR [rsp+0x14],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_21f:
	/* 0x21f: mov    edx,DWORD PTR [rax+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_222:
	/* 0x222: mov    DWORD PTR [rsp+0x8],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_226:
	/* 0x226: test   edi,0xff1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDI, X86_WIDTH_32, 65311ULL);
x86_l_22c:
	/* 0x22c: mov    esi,DWORD PTR [rax+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_22f:
	/* 0x22f: mov    DWORD PTR [rsp+0xc],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_233:
	/* 0x233: mov    BYTE PTR [rsp+0x15],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 90194313217ULL);
x86_l_238:
	/* 0x238: cmove  r12,r8 */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_R8, X86_WIDTH_64, X86_CC_E);
x86_l_23c:
	/* 0x23c: mov    r13d,DWORD PTR [rax+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_240:
	/* 0x240: shl    r13d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHL, 2ULL);
x86_l_244:
	/* 0x244: and    r13d,0x3c */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 60ULL);
x86_l_248:
	/* 0x248: lea    r8,[r13+0xe] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_24c:
	/* 0x24c: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_24f:
	/* 0x24f: je     32f <tail_nodeport_nat_ingress_ipv4+0x32f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x24f, 0x32f, x86_l_32f);
x86_l_255:
	/* 0x255: mov    ebp,0xffffff53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967123ULL);
x86_l_25a:
	/* 0x25a: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_25d:
	/* 0x25d: je     268 <tail_nodeport_nat_ingress_ipv4+0x268> */
	X86_SIM_X86_JCC(X86_CC_E, 0x25d, 0x268, x86_l_268);
x86_l_25f:
	/* 0x25f: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_262:
	/* 0x262: jne    6f <tail_nodeport_nat_ingress_ipv4+0x6f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x262, 0x6f, x86_l_6f);
x86_l_268:
	/* 0x268: mov    rcx,QWORD PTR [rip+0x23c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_ipv4_fragments)));
x86_l_26f:
	/* 0x26f: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_272:
	/* 0x272: je     386 <tail_nodeport_nat_ingress_ipv4+0x386> */
	X86_SIM_X86_JCC(X86_CC_E, 0x272, 0x386, x86_l_386);
x86_l_278:
	/* 0x278: mov    DWORD PTR [rsp+0x18],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_27c:
	/* 0x27c: mov    DWORD PTR [rsp+0x1c],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_280:
	/* 0x280: mov    WORD PTR [rsp+0x20],r12w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_286:
	/* 0x286: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_289:
	/* 0x289: shr    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_28d:
	/* 0x28d: mov    BYTE PTR [rsp+0x22],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_291:
	/* 0x291: mov    BYTE PTR [rsp+0x23],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 150323855360ULL);
x86_l_296:
	/* 0x296: test   r12,r9 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R9, X86_WIDTH_64);
x86_l_299:
	/* 0x299: jne    138b <tail_nodeport_nat_ingress_ipv4+0x138b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x299, 0x138b, x86_l_138b);
x86_l_29f:
	/* 0x29f: lea    rcx,[rax+r8*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_2a3:
	/* 0x2a3: add    rcx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_2a7:
	/* 0x2a7: mov    ebp,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967161ULL);
x86_l_2ac:
	/* 0x2ac: cmp    rcx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_2af:
	/* 0x2af: ja     6f <tail_nodeport_nat_ingress_ipv4+0x6f> */
	X86_SIM_X86_JCC(X86_CC_A, 0x2af, 0x6f, x86_l_6f);
x86_l_2b5:
	/* 0x2b5: add    rax,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R8, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2b8:
	/* 0x2b8: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ba:
	/* 0x2ba: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2be:
	/* 0x2be: test   r12,r10 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R10, X86_WIDTH_64);
x86_l_2c1:
	/* 0x2c1: jne    13c2 <tail_nodeport_nat_ingress_ipv4+0x13c2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2c1, 0x13c2, x86_l_13c2);
x86_l_2c7:
	/* 0x2c7: mov    QWORD PTR [rsp+0x28],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2cc:
	/* 0x2cc: movzx  ecx,WORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_2d1:
	/* 0x2d1: movzx  eax,WORD PTR [rsp+0x12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18ULL);
x86_l_2d6:
	/* 0x2d6: jmp    3b6 <tail_nodeport_nat_ingress_ipv4+0x3b6> */
	X86_SIM_X86_JMP(0x2d6, 0x3b6, x86_l_3b6);
x86_l_2db:
	/* 0x2db: mov    QWORD PTR [rsp+0x60],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860417ULL);
x86_l_2e4:
	/* 0x2e4: mov    QWORD PTR [rsp+0x68],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_2e9:
	/* 0x2e9: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2ee:
	/* 0x2ee: mov    rdi,QWORD PTR [rip+0x23c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_2f5:
	/* 0x2f5: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2fa:
	/* 0x2fa: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2ff:
	/* 0x2ff: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_301:
	/* 0x301: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_303:
	/* 0x303: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_308:
	/* 0x308: mov    rsi,QWORD PTR [rip+0x23c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_30f:
	/* 0x30f: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_314:
	/* 0x314: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_317:
	/* 0x317: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_31c:
	/* 0x31c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31e:
	/* 0x31e: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_320:
	/* 0x320: add    rsp,0xc8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 200ULL);
x86_l_327:
	/* 0x327: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_329:
	/* 0x329: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_32a:
	/* 0x32a: jmp    1ed3 <tail_nodeport_nat_ingress_ipv4+0x1ed3> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_32f:
	/* 0x32f: test   r12,r10 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R10, X86_WIDTH_64);
x86_l_332:
	/* 0x332: jne    6f <tail_nodeport_nat_ingress_ipv4+0x6f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x332, 0x6f, x86_l_6f);
x86_l_338:
	/* 0x338: lea    rcx,[rax+r8*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_33c:
	/* 0x33c: add    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_340:
	/* 0x340: cmp    rcx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_343:
	/* 0x343: ja     6f <tail_nodeport_nat_ingress_ipv4+0x6f> */
	X86_SIM_X86_JCC(X86_CC_A, 0x343, 0x6f, x86_l_6f);
x86_l_349:
	/* 0x349: lea    r14,[rax+r8*1] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_34d:
	/* 0x34d: mov    rdx,QWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_350:
	/* 0x350: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_352:
	/* 0x352: je     4f3 <tail_nodeport_nat_ingress_ipv4+0x4f3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x352, 0x4f3, x86_l_4f3);
x86_l_358:
	/* 0x358: mov    esi,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RDX, X86_WIDTH_32);
x86_l_35a:
	/* 0x35a: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_35d:
	/* 0x35d: movzx  edx,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_360:
	/* 0x360: mov    ebp,0xffffff53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967123ULL);
x86_l_365:
	/* 0x365: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_368:
	/* 0x368: je     4c0 <tail_nodeport_nat_ingress_ipv4+0x4c0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x368, 0x4c0, x86_l_4c0);
x86_l_36e:
	/* 0x36e: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_371:
	/* 0x371: jne    6f <tail_nodeport_nat_ingress_ipv4+0x6f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x371, 0x6f, x86_l_6f);
x86_l_377:
	/* 0x377: cmp    sil,0xf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_8, 15ULL);
x86_l_37b:
	/* 0x37b: ja     6f <tail_nodeport_nat_ingress_ipv4+0x6f> */
	X86_SIM_X86_JCC(X86_CC_A, 0x37b, 0x6f, x86_l_6f);
x86_l_381:
	/* 0x381: jmp    4ca <tail_nodeport_nat_ingress_ipv4+0x4ca> */
	X86_SIM_X86_JMP(0x381, 0x4ca, x86_l_4ca);
x86_l_386:
	/* 0x386: test   r12,r9 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R9, X86_WIDTH_64);
x86_l_389:
	/* 0x389: jne    13b8 <tail_nodeport_nat_ingress_ipv4+0x13b8> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x389, 0x13b8, x86_l_13b8);
x86_l_38f:
	/* 0x38f: mov    QWORD PTR [rsp+0x28],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_394:
	/* 0x394: lea    rcx,[rax+r8*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_398:
	/* 0x398: add    rcx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_39c:
	/* 0x39c: mov    ebp,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967161ULL);
x86_l_3a1:
	/* 0x3a1: cmp    rcx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_3a4:
	/* 0x3a4: ja     6f <tail_nodeport_nat_ingress_ipv4+0x6f> */
	X86_SIM_X86_JCC(X86_CC_A, 0x3a4, 0x6f, x86_l_6f);
x86_l_3aa:
	/* 0x3aa: add    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_3af:
	/* 0x3af: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3b1:
	/* 0x3b1: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_3b3:
	/* 0x3b3: shr    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_3b6:
	/* 0x3b6: mov    WORD PTR [rsp+0x12],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_3bb:
	/* 0x3bb: mov    WORD PTR [rsp+0x10],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3c0:
	/* 0x3c0: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3c3:
	/* 0x3c3: rol    ax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_3c7:
	/* 0x3c7: mov    cl,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_3c9:
	/* 0x3c9: mov    ebp,0xffffff53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967123ULL);
x86_l_3ce:
	/* 0x3ce: cmp    ax,r14w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R14, X86_WIDTH_16);
x86_l_3d2:
	/* 0x3d2: jb     6f <tail_nodeport_nat_ingress_ipv4+0x6f> */
	X86_SIM_X86_JCC(X86_CC_B, 0x3d2, 0x6f, x86_l_6f);
x86_l_3d8:
	/* 0x3d8: mov    DWORD PTR [rsp+0x30],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3dc:
	/* 0x3dc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3e1:
	/* 0x3e1: mov    rdi,QWORD PTR [rip+0x23ca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_3e8:
	/* 0x3e8: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3ed:
	/* 0x3ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ef:
	/* 0x3ef: mov    ebp,0xffffff59 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967129ULL);
x86_l_3f4:
	/* 0x3f4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3f7:
	/* 0x3f7: je     6f <tail_nodeport_nat_ingress_ipv4+0x6f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3f7, 0x6f, x86_l_6f);
x86_l_3fd:
	/* 0x3fd: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_400:
	/* 0x400: mov    eax,DWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_403:
	/* 0x403: mov    DWORD PTR [rsp+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_407:
	/* 0x407: movzx  eax,WORD PTR [r15+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_40c:
	/* 0x40c: mov    WORD PTR [rsp+0x22],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_411:
	/* 0x411: mov    eax,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_415:
	/* 0x415: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_419:
	/* 0x419: movzx  eax,WORD PTR [rsp+0x12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18ULL);
x86_l_41e:
	/* 0x41e: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_423:
	/* 0x423: movzx  eax,BYTE PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 20ULL);
x86_l_428:
	/* 0x428: mov    BYTE PTR [rsp+0x24],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_42c:
	/* 0x42c: mov    BYTE PTR [rsp+0x25],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 158913789952ULL);
x86_l_431:
	/* 0x431: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_436:
	/* 0x436: mov    rdi,QWORD PTR [rip+0x23ca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_43d:
	/* 0x43d: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_442:
	/* 0x442: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_444:
	/* 0x444: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_447:
	/* 0x447: jne    624 <tail_nodeport_nat_ingress_ipv4+0x624> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x447, 0x624, x86_l_624);
x86_l_44d:
	/* 0x44d: mov    QWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_459:
	/* 0x459: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_462:
	/* 0x462: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_46b:
	/* 0x46b: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_474:
	/* 0x474: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_47d:
	/* 0x47d: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_481:
	/* 0x481: mov    DWORD PTR [rsp+0x80],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_488:
	/* 0x488: movzx  eax,WORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_48d:
	/* 0x48d: mov    WORD PTR [rsp+0x84],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_495:
	/* 0x495: mov    rax,QWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_499:
	/* 0x499: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_49e:
	/* 0x49e: mov    rax,QWORD PTR [rip+0x23ca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_4a5:
	/* 0x4a5: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4a8:
	/* 0x4a8: je     5da <tail_nodeport_nat_ingress_ipv4+0x5da> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4a8, 0x5da, x86_l_5da);
x86_l_4ae:
	/* 0x4ae: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_4b3:
	/* 0x4b3: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4b5:
	/* 0x4b5: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_4b7:
	/* 0x4b7: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_4bb:
	/* 0x4bb: jmp    5fd <tail_nodeport_nat_ingress_ipv4+0x5fd> */
	X86_SIM_X86_JMP(0x4bb, 0x5fd, x86_l_5fd);
x86_l_4c0:
	/* 0x4c0: cmp    sil,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_8, 1ULL);
x86_l_4c4:
	/* 0x4c4: ja     6f <tail_nodeport_nat_ingress_ipv4+0x6f> */
	X86_SIM_X86_JCC(X86_CC_A, 0x4c4, 0x6f, x86_l_6f);
x86_l_4ca:
	/* 0x4ca: mov    QWORD PTR [rsp+0x66],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 438086664192ULL);
x86_l_4d3:
	/* 0x4d3: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_4dc:
	/* 0x4dc: lea    rdx,[rax+r8*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_4e0:
	/* 0x4e0: add    rdx,0x1c */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 28ULL);
x86_l_4e4:
	/* 0x4e4: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_4e7:
	/* 0x4e7: jbe    508 <tail_nodeport_nat_ingress_ipv4+0x508> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x4e7, 0x508, x86_l_508);
x86_l_4e9:
	/* 0x4e9: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_4ee:
	/* 0x4ee: jmp    6f <tail_nodeport_nat_ingress_ipv4+0x6f> */
	X86_SIM_X86_JMP(0x4ee, 0x6f, x86_l_6f);
x86_l_4f3:
	/* 0x4f3: mov    QWORD PTR [rsp+0x28],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4f8:
	/* 0x4f8: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_4fc:
	/* 0x4fc: mov    WORD PTR [rsp+0x10],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_501:
	/* 0x501: mov    cl,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 4ULL);
x86_l_503:
	/* 0x503: jmp    3d8 <tail_nodeport_nat_ingress_ipv4+0x3d8> */
	X86_SIM_X86_JMP(0x503, 0x3d8, x86_l_3d8);
x86_l_508:
	/* 0x508: mov    edx,DWORD PTR [rcx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_50b:
	/* 0x50b: mov    rsi,QWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_50f:
	/* 0x50f: mov    edi,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_511:
	/* 0x511: mov    rcx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_64);
x86_l_514:
	/* 0x514: shr    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_518:
	/* 0x518: mov    BYTE PTR [rsp+0x6c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_51c:
	/* 0x51c: mov    DWORD PTR [rsp+0x64],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 100ULL);
x86_l_520:
	/* 0x520: shr    rsi,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_524:
	/* 0x524: mov    DWORD PTR [rsp+0x60],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_528:
	/* 0x528: mov    BYTE PTR [rsp+0x6d],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 468151435265ULL);
x86_l_52d:
	/* 0x52d: lea    rsi,[r8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_531:
	/* 0x531: shl    edi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHL, 2ULL);
x86_l_534:
	/* 0x534: and    edi,0x3c */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 60ULL);
x86_l_537:
	/* 0x537: add    esi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_539:
	/* 0x539: cmp    cl,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_53c:
	/* 0x53c: je     98b <tail_nodeport_nat_ingress_ipv4+0x98b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x53c, 0x98b, x86_l_98b);
x86_l_542:
	/* 0x542: movzx  ecx,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_545:
	/* 0x545: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_548:
	/* 0x548: je     553 <tail_nodeport_nat_ingress_ipv4+0x553> */
	X86_SIM_X86_JCC(X86_CC_E, 0x548, 0x553, x86_l_553);
x86_l_54a:
	/* 0x54a: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_54d:
	/* 0x54d: jne    6f <tail_nodeport_nat_ingress_ipv4+0x6f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x54d, 0x6f, x86_l_6f);
x86_l_553:
	/* 0x553: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_555:
	/* 0x555: lea    rdx,[rax+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_559:
	/* 0x559: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_55d:
	/* 0x55d: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_560:
	/* 0x560: ja     4e9 <tail_nodeport_nat_ingress_ipv4+0x4e9> */
	X86_SIM_X86_JCC(X86_CC_A, 0x560, 0x4e9, x86_l_4e9);
x86_l_562:
	/* 0x562: mov    QWORD PTR [rsp+0x40],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_567:
	/* 0x567: mov    QWORD PTR [rsp+0x30],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_56c:
	/* 0x56c: mov    QWORD PTR [rsp+0x28],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_571:
	/* 0x571: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_574:
	/* 0x574: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_576:
	/* 0x576: mov    DWORD PTR [rsp+0x68],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_57a:
	/* 0x57a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_57c:
	/* 0x57c: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_581:
	/* 0x581: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_586:
	/* 0x586: mov    rdi,QWORD PTR [rip+0x23ca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_58d:
	/* 0x58d: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_592:
	/* 0x592: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_594:
	/* 0x594: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_597:
	/* 0x597: je     6f <tail_nodeport_nat_ingress_ipv4+0x6f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x597, 0x6f, x86_l_6f);
x86_l_59d:
	/* 0x59d: mov    r10,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R10, X86_RAX, X86_WIDTH_64);
x86_l_5a0:
	/* 0x5a0: movzx  ecx,BYTE PTR [rsp+0x6c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 108ULL);
x86_l_5a5:
	/* 0x5a5: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_5a7:
	/* 0x5a7: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_5aa:
	/* 0x5aa: je     c54 <tail_nodeport_nat_ingress_ipv4+0xc54> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5aa, 0xc54, x86_l_c54);
x86_l_5b0:
	/* 0x5b0: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_5b3:
	/* 0x5b3: jne    c7d <tail_nodeport_nat_ingress_ipv4+0xc7d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x5b3, 0xc7d, x86_l_c7d);
x86_l_5b9:
	/* 0x5b9: sub    r15,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R14, X86_WIDTH_64, X86_ALU_SUB);
x86_l_5bc:
	/* 0x5bc: mov    edx,0xfffffff8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967288ULL);
x86_l_5c1:
	/* 0x5c1: add    rdx,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R15, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5c4:
	/* 0x5c4: mov    edx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_5c6:
	/* 0x5c6: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_5cb:
	/* 0x5cb: add    esi,0x12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 18ULL);
x86_l_5ce:
	/* 0x5ce: cmp    rdx,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_5d1:
	/* 0x5d1: setae  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_AE);
x86_l_5d5:
	/* 0x5d5: jmp    c80 <tail_nodeport_nat_ingress_ipv4+0xc80> */
	X86_SIM_X86_JMP(0x5d5, 0xc80, x86_l_c80);
x86_l_5da:
	/* 0x5da: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_5df:
	/* 0x5df: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5e1:
	/* 0x5e1: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_5e3:
	/* 0x5e3: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_5e7:
	/* 0x5e7: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_5f1:
	/* 0x5f1: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_5f4:
	/* 0x5f4: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_5f9:
	/* 0x5f9: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_5fd:
	/* 0x5fd: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_602:
	/* 0x602: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_607:
	/* 0x607: mov    rdi,QWORD PTR [rip+0x23ca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_60e:
	/* 0x60e: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_613:
	/* 0x613: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_618:
	/* 0x618: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_61a:
	/* 0x61a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_61c:
	/* 0x61c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_61e:
	/* 0x61e: js     6f <tail_nodeport_nat_ingress_ipv4+0x6f> */
	X86_SIM_X86_JCC(X86_CC_S, 0x61e, 0x6f, x86_l_6f);
x86_l_624:
	/* 0x624: cmp    QWORD PTR [r15+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_629:
	/* 0x629: je     a8b <tail_nodeport_nat_ingress_ipv4+0xa8b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x629, 0xa8b, x86_l_a8b);
x86_l_62f:
	/* 0x62f: movzx  eax,WORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 20ULL);
x86_l_634:
	/* 0x634: mov    WORD PTR [rsp+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_639:
	/* 0x639: movzx  ecx,WORD PTR [rsp+0x12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18ULL);
x86_l_63e:
	/* 0x63e: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_643:
	/* 0x643: mov    QWORD PTR [rsp+0x18],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_648:
	/* 0x648: mov    edx,DWORD PTR [r15+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_64c:
	/* 0x64c: mov    DWORD PTR [rsp+0x18],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_650:
	/* 0x650: movzx  edx,WORD PTR [r15+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_655:
	/* 0x655: mov    WORD PTR [rsp+0x22],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_65a:
	/* 0x65a: mov    WORD PTR [rsp+0x20],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_65f:
	/* 0x65f: movzx  ebp,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_662:
	/* 0x662: cmp    bp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_16, 6ULL);
x86_l_666:
	/* 0x666: jne    671 <tail_nodeport_nat_ingress_ipv4+0x671> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x666, 0x671, x86_l_671);
x86_l_668:
	/* 0x668: mov    rdi,QWORD PTR [rip+0x23ca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct4_global)));
x86_l_66f:
	/* 0x66f: jmp    678 <tail_nodeport_nat_ingress_ipv4+0x678> */
	X86_SIM_X86_JMP(0x66f, 0x678, x86_l_678);
x86_l_671:
	/* 0x671: mov    rdi,QWORD PTR [rip+0x23ca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct_any4_global)));
x86_l_678:
	/* 0x678: movabs rcx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2199023255552ULL);
x86_l_682:
	/* 0x682: movabs rdx,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1099511627776ULL);
x86_l_68c:
	/* 0x68c: mov    BYTE PTR [rsp+0x25],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 158913789952ULL);
x86_l_691:
	/* 0x691: mov    rax,QWORD PTR [rip+0x23ca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_ipv4_fragments)));
x86_l_698:
	/* 0x698: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_69b:
	/* 0x69b: je     73c <tail_nodeport_nat_ingress_ipv4+0x73c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x69b, 0x73c, x86_l_73c);
x86_l_6a1:
	/* 0x6a1: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_6a4:
	/* 0x6a4: and    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_AND);
x86_l_6a7:
	/* 0x6a7: je     73c <tail_nodeport_nat_ingress_ipv4+0x73c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6a7, 0x73c, x86_l_73c);
x86_l_6ad:
	/* 0x6ad: mov    QWORD PTR [rsp+0x58],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_6b2:
	/* 0x6b2: mov    DWORD PTR [rsp+0x40],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_6b6:
	/* 0x6b6: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_6b9:
	/* 0x6b9: mov    r15,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RCX, X86_WIDTH_64);
x86_l_6bc:
	/* 0x6bc: mov    r14,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6c0:
	/* 0x6c0: sub    r14,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 0ULL);
x86_l_6c3:
	/* 0x6c3: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_6cc:
	/* 0x6cc: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_6d5:
	/* 0x6d5: movabs rax,0x6c03a50109 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 463917613321ULL);
x86_l_6df:
	/* 0x6df: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_6e4:
	/* 0x6e4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6e9:
	/* 0x6e9: mov    rdi,QWORD PTR [rip+0x23ca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_6f0:
	/* 0x6f0: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_6f5:
	/* 0x6f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6f7:
	/* 0x6f7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6fa:
	/* 0x6fa: je     705 <tail_nodeport_nat_ingress_ipv4+0x705> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6fa, 0x705, x86_l_705);
x86_l_6fc:
	/* 0x6fc: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_6ff:
	/* 0x6ff: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_703:
	/* 0x703: jmp    72d <tail_nodeport_nat_ingress_ipv4+0x72d> */
	X86_SIM_X86_JMP(0x703, 0x72d, x86_l_72d);
x86_l_705:
	/* 0x705: mov    QWORD PTR [rsp+0x60],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860417ULL);
x86_l_70e:
	/* 0x70e: mov    QWORD PTR [rsp+0x68],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_713:
	/* 0x713: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_718:
	/* 0x718: mov    rdi,QWORD PTR [rip+0x23ca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_71f:
	/* 0x71f: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_724:
	/* 0x724: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_729:
	/* 0x729: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_72b:
	/* 0x72b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_72d:
	/* 0x72d: mov    rcx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_730:
	/* 0x730: mov    r15,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_64);
x86_l_733:
	/* 0x733: mov    ebp,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_737:
	/* 0x737: mov    rdi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_73c:
	/* 0x73c: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_73e:
	/* 0x73e: cmp    bp,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_16, 6ULL);
x86_l_742:
	/* 0x742: jne    771 <tail_nodeport_nat_ingress_ipv4+0x771> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x742, 0x771, x86_l_771);
x86_l_744:
	/* 0x744: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_747:
	/* 0x747: mov    r14d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 0ULL);
x86_l_74d:
	/* 0x74d: and    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_750:
	/* 0x750: jne    79e <tail_nodeport_nat_ingress_ipv4+0x79e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x750, 0x79e, x86_l_79e);
x86_l_752:
	/* 0x752: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_755:
	/* 0x755: movzx  ecx,r13b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R13, X86_WIDTH_32, X86_WIDTH_8);
x86_l_759:
	/* 0x759: lea    rdx,[rax+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_75d:
	/* 0x75d: add    rdx,0x1c */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 28ULL);
x86_l_761:
	/* 0x761: cmp    rdx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_765:
	/* 0x765: jbe    776 <tail_nodeport_nat_ingress_ipv4+0x776> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x765, 0x776, x86_l_776);
x86_l_767:
	/* 0x767: mov    ebp,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967161ULL);
x86_l_76c:
	/* 0x76c: jmp    6f <tail_nodeport_nat_ingress_ipv4+0x6f> */
	X86_SIM_X86_JMP(0x76c, 0x6f, x86_l_6f);
x86_l_771:
	/* 0x771: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_774:
	/* 0x774: jmp    79e <tail_nodeport_nat_ingress_ipv4+0x79e> */
	X86_SIM_X86_JMP(0x774, 0x79e, x86_l_79e);
x86_l_776:
	/* 0x776: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_779:
	/* 0x779: movzx  edx,WORD PTR [rax+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 26ULL);
x86_l_77d:
	/* 0x77d: mov    eax,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_77f:
	/* 0x77f: and    eax,0x1200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4608ULL);
x86_l_784:
	/* 0x784: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_787:
	/* 0x787: cmp    eax,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 512ULL);
x86_l_78c:
	/* 0x78c: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_78f:
	/* 0x78f: test   edx,0x500 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_32, 1280ULL);
x86_l_795:
	/* 0x795: jne    1abe <tail_nodeport_nat_ingress_ipv4+0x1abe> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x795, 0x1abe, x86_l_1abe);
x86_l_79b:
	/* 0x79b: mov    r14b,al */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_8);
x86_l_79e:
	/* 0x79e: mov    DWORD PTR [rsp+0x3c],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_7a2:
	/* 0x7a2: mov    QWORD PTR [rsp+0x58],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_7a7:
	/* 0x7a7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7ac:
	/* 0x7ac: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_7b1:
	/* 0x7b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7b3:
	/* 0x7b3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7b6:
	/* 0x7b6: je     a7d <tail_nodeport_nat_ingress_ipv4+0xa7d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7b6, 0xa7d, x86_l_a7d);
x86_l_7bc:
	/* 0x7bc: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_7bf:
	/* 0x7bf: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_7c2:
	/* 0x7c2: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_7c4:
	/* 0x7c4: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_7c6:
	/* 0x7c6: test   cl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_7c9:
	/* 0x7c9: je     8d3 <tail_nodeport_nat_ingress_ipv4+0x8d3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7c9, 0x8d3, x86_l_8d3);
x86_l_7cf:
	/* 0x7cf: mov    DWORD PTR [rsp+0x40],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_7d3:
	/* 0x7d3: mov    rsi,QWORD PTR [rip+0x23ca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_7da:
	/* 0x7da: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7dd:
	/* 0x7dd: mov    edx,DWORD PTR [rsp+0x3c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_7e1:
	/* 0x7e1: je     7f2 <tail_nodeport_nat_ingress_ipv4+0x7f2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7e1, 0x7f2, x86_l_7f2);
x86_l_7e3:
	/* 0x7e3: mov    rcx,QWORD PTR [rip+0x23ca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_7ea:
	/* 0x7ea: imul   ebp,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_7ed:
	/* 0x7ed: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_7f0:
	/* 0x7f0: jmp    7f7 <tail_nodeport_nat_ingress_ipv4+0x7f7> */
	X86_SIM_X86_JMP(0x7f0, 0x7f7, x86_l_7f7);
x86_l_7f2:
	/* 0x7f2: mov    ebp,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_7f7:
	/* 0x7f7: cmp    WORD PTR [rsp+0x40],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 274877906950ULL);
x86_l_7fd:
	/* 0x7fd: jne    830 <tail_nodeport_nat_ingress_ipv4+0x830> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x7fd, 0x830, x86_l_830);
x86_l_7ff:
	/* 0x7ff: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_801:
	/* 0x801: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_803:
	/* 0x803: shr    ecx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_806:
	/* 0x806: and    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_809:
	/* 0x809: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_80b:
	/* 0x80b: mov    WORD PTR [rdi+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_80f:
	/* 0x80f: test   al,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 16ULL);
x86_l_811:
	/* 0x811: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_816:
	/* 0x816: mov    ebp,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 21600ULL);
x86_l_81b:
	/* 0x81b: cmove  ebp,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_81e:
	/* 0x81e: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_821:
	/* 0x821: je     830 <tail_nodeport_nat_ingress_ipv4+0x830> */
	X86_SIM_X86_JCC(X86_CC_E, 0x821, 0x830, x86_l_830);
x86_l_823:
	/* 0x823: mov    rax,QWORD PTR [rip+0x23ca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_82a:
	/* 0x82a: imul   ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_82d:
	/* 0x82d: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_830:
	/* 0x830: mov    QWORD PTR [rsp+0xa8],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_838:
	/* 0x838: movzx  r15d,dx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_RDX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_83c:
	/* 0x83c: shr    r15d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_840:
	/* 0x840: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_843:
	/* 0x843: je     854 <tail_nodeport_nat_ingress_ipv4+0x854> */
	X86_SIM_X86_JCC(X86_CC_E, 0x843, 0x854, x86_l_854);
x86_l_845:
	/* 0x845: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_84a:
	/* 0x84a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_84c:
	/* 0x84c: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_84e:
	/* 0x84e: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_852:
	/* 0x852: jmp    877 <tail_nodeport_nat_ingress_ipv4+0x877> */
	X86_SIM_X86_JMP(0x852, 0x877, x86_l_877);
x86_l_854:
	/* 0x854: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_859:
	/* 0x859: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_85b:
	/* 0x85b: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_85d:
	/* 0x85d: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_861:
	/* 0x861: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_86b:
	/* 0x86b: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_86e:
	/* 0x86e: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_873:
	/* 0x873: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_877:
	/* 0x877: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_879:
	/* 0x879: mov    rdi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_881:
	/* 0x881: mov    DWORD PTR [rdi+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_884:
	/* 0x884: movzx  ecx,BYTE PTR [rdi+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_888:
	/* 0x888: mov    edx,DWORD PTR [rdi+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_88b:
	/* 0x88b: and    r15b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_88f:
	/* 0x88f: mov    rsi,QWORD PTR [rip+0x23ca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_896:
	/* 0x896: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_899:
	/* 0x899: je     8ac <tail_nodeport_nat_ingress_ipv4+0x8ac> */
	X86_SIM_X86_JCC(X86_CC_E, 0x899, 0x8ac, x86_l_8ac);
x86_l_89b:
	/* 0x89b: mov    rsi,QWORD PTR [rip+0x23ca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_8a2:
	/* 0x8a2: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8a4:
	/* 0x8a4: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_8a7:
	/* 0x8a7: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_8aa:
	/* 0x8aa: jmp    8b1 <tail_nodeport_nat_ingress_ipv4+0x8b1> */
	X86_SIM_X86_JMP(0x8aa, 0x8b1, x86_l_8b1);
x86_l_8ac:
	/* 0x8ac: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_8b1:
	/* 0x8b1: mov    ebp,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_8b5:
	/* 0x8b5: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_8b7:
	/* 0x8b7: or     r15b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_8ba:
	/* 0x8ba: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_8bc:
	/* 0x8bc: jb     8c3 <tail_nodeport_nat_ingress_ipv4+0x8c3> */
	X86_SIM_X86_JCC(X86_CC_B, 0x8bc, 0x8c3, x86_l_8c3);
x86_l_8be:
	/* 0x8be: cmp    cl,r15b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R15, X86_WIDTH_8);
x86_l_8c1:
	/* 0x8c1: je     8d3 <tail_nodeport_nat_ingress_ipv4+0x8d3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8c1, 0x8d3, x86_l_8d3);
x86_l_8c3:
	/* 0x8c3: mov    BYTE PTR [rdi+0x2b],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_8c7:
	/* 0x8c7: mov    DWORD PTR [rdi+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_8ca:
	/* 0x8ca: mov    rax,QWORD PTR [rip+0x23ca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_8d1:
	/* 0x8d1: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8d3:
	/* 0x8d3: mov    rax,QWORD PTR [rip+0x23ca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_8da:
	/* 0x8da: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8dd:
	/* 0x8dd: mov    edx,DWORD PTR [rsp+0x3c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_8e1:
	/* 0x8e1: je     8f4 <tail_nodeport_nat_ingress_ipv4+0x8f4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8e1, 0x8f4, x86_l_8f4);
x86_l_8e3:
	/* 0x8e3: inc QWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RDI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 16ULL);
x86_l_8e8:
	/* 0x8e8: mov    rax,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8ec:
	/* 0x8ec: sub    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 0ULL);
x86_l_8ef:
	/* 0x8ef: add QWORD PTR [rdi+0x18],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RDI, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_8f4:
	/* 0x8f4: cmp    r14d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 2ULL);
x86_l_8f8:
	/* 0x8f8: je     946 <tail_nodeport_nat_ingress_ipv4+0x946> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8f8, 0x946, x86_l_946);
x86_l_8fa:
	/* 0x8fa: cmp    r14d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1ULL);
x86_l_8fe:
	/* 0x8fe: jne    a86 <tail_nodeport_nat_ingress_ipv4+0xa86> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x8fe, 0xa86, x86_l_a86);
x86_l_904:
	/* 0x904: movzx  eax,WORD PTR [rdi+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_908:
	/* 0x908: test   al,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 3ULL);
x86_l_90a:
	/* 0x90a: je     a86 <tail_nodeport_nat_ingress_ipv4+0xa86> */
	X86_SIM_X86_JCC(X86_CC_E, 0x90a, 0xa86, x86_l_a86);
x86_l_910:
	/* 0x910: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_912:
	/* 0x912: mov    WORD PTR [rdi+0x2a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 180388626432ULL);
x86_l_918:
	/* 0x918: and    eax,0xffec */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 65516ULL);
x86_l_91d:
	/* 0x91d: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_920:
	/* 0x920: mov    WORD PTR [rdi+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_924:
	/* 0x924: mov    rcx,QWORD PTR [rip+0x23ca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_92b:
	/* 0x92b: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_92e:
	/* 0x92e: je     1c4c <tail_nodeport_nat_ingress_ipv4+0x1c4c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x92e, 0x1c4c, x86_l_1c4c);
x86_l_934:
	/* 0x934: mov    rcx,QWORD PTR [rip+0x23ca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_93b:
	/* 0x93b: imul   ebp,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_93e:
	/* 0x93e: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_941:
	/* 0x941: jmp    1c51 <tail_nodeport_nat_ingress_ipv4+0x1c51> */
	X86_SIM_X86_JMP(0x941, 0x1c51, x86_l_1c51);
x86_l_946:
	/* 0x946: mov    eax,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_948:
	/* 0x948: shr    eax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_94b:
	/* 0x94b: and    eax,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2ULL);
x86_l_94e:
	/* 0x94e: or     ax,WORD PTR [rdi+0x24] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RDI, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 36ULL);
x86_l_952:
	/* 0x952: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_954:
	/* 0x954: or     ecx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_OR, 1ULL);
x86_l_957:
	/* 0x957: mov    WORD PTR [rdi+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_95b:
	/* 0x95b: mov    rcx,QWORD PTR [rip+0x23ca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_962:
	/* 0x962: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_964:
	/* 0x964: test   al,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 2ULL);
x86_l_966:
	/* 0x966: je     a86 <tail_nodeport_nat_ingress_ipv4+0xa86> */
	X86_SIM_X86_JCC(X86_CC_E, 0x966, 0xa86, x86_l_a86);
x86_l_96c:
	/* 0x96c: mov    rcx,QWORD PTR [rip+0x23ca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_973:
	/* 0x973: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_976:
	/* 0x976: je     9eb <tail_nodeport_nat_ingress_ipv4+0x9eb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x976, 0x9eb, x86_l_9eb);
x86_l_978:
	/* 0x978: mov    rax,QWORD PTR [rip+0x23ca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_97f:
	/* 0x97f: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_981:
	/* 0x981: add    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_983:
	/* 0x983: lea    ebp,[rax+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_986:
	/* 0x986: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_989:
	/* 0x989: jmp    9f0 <tail_nodeport_nat_ingress_ipv4+0x9f0> */
	X86_SIM_X86_JMP(0x989, 0x9f0, x86_l_9f0);
x86_l_98b:
	/* 0x98b: mov    ecx,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RSI, X86_WIDTH_32);
x86_l_98d:
	/* 0x98d: lea    rdx,[rax+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_991:
	/* 0x991: inc    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_994:
	/* 0x994: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_997:
	/* 0x997: ja     4e9 <tail_nodeport_nat_ingress_ipv4+0x4e9> */
	X86_SIM_X86_JCC(X86_CC_A, 0x997, 0x4e9, x86_l_4e9);
x86_l_99d:
	/* 0x99d: lea    rdx,[rax+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_9a1:
	/* 0x9a1: movzx  edx,BYTE PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_9a4:
	/* 0x9a4: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_9a6:
	/* 0x9a6: je     6f <tail_nodeport_nat_ingress_ipv4+0x6f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9a6, 0x6f, x86_l_6f);
x86_l_9ac:
	/* 0x9ac: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_9af:
	/* 0x9af: jne    d90 <tail_nodeport_nat_ingress_ipv4+0xd90> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x9af, 0xd90, x86_l_d90);
x86_l_9b5:
	/* 0x9b5: lea    rdx,[rax+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_9b9:
	/* 0x9b9: add    rdx,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 6ULL);
x86_l_9bd:
	/* 0x9bd: cmp    rdx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_9c0:
	/* 0x9c0: ja     4e9 <tail_nodeport_nat_ingress_ipv4+0x4e9> */
	X86_SIM_X86_JCC(X86_CC_A, 0x9c0, 0x4e9, x86_l_4e9);
x86_l_9c6:
	/* 0x9c6: mov    QWORD PTR [rsp+0x40],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_9cb:
	/* 0x9cb: mov    QWORD PTR [rsp+0x30],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9d0:
	/* 0x9d0: mov    QWORD PTR [rsp+0x28],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_9d5:
	/* 0x9d5: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_9d8:
	/* 0x9d8: movzx  eax,WORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_9dc:
	/* 0x9dc: mov    WORD PTR [rsp+0x68],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_9e1:
	/* 0x9e1: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_9e6:
	/* 0x9e6: jmp    57c <tail_nodeport_nat_ingress_ipv4+0x57c> */
	X86_SIM_X86_JMP(0x9e6, 0x57c, x86_l_57c);
x86_l_9eb:
	/* 0x9eb: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_9f0:
	/* 0x9f0: mov    r15,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDI, X86_WIDTH_64);
x86_l_9f3:
	/* 0x9f3: movzx  r14d,dx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_RDX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_9f7:
	/* 0x9f7: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_9fb:
	/* 0x9fb: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9fe:
	/* 0x9fe: je     a0f <tail_nodeport_nat_ingress_ipv4+0xa0f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9fe, 0xa0f, x86_l_a0f);
x86_l_a00:
	/* 0xa00: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_a05:
	/* 0xa05: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a07:
	/* 0xa07: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_a09:
	/* 0xa09: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_a0d:
	/* 0xa0d: jmp    a32 <tail_nodeport_nat_ingress_ipv4+0xa32> */
	X86_SIM_X86_JMP(0xa0d, 0xa32, x86_l_a32);
x86_l_a0f:
	/* 0xa0f: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_a14:
	/* 0xa14: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a16:
	/* 0xa16: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_a18:
	/* 0xa18: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_a1c:
	/* 0xa1c: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_a26:
	/* 0xa26: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_a29:
	/* 0xa29: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_a2e:
	/* 0xa2e: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_a32:
	/* 0xa32: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_a34:
	/* 0xa34: mov    DWORD PTR [r15+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a38:
	/* 0xa38: movzx  ecx,BYTE PTR [r15+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_a3d:
	/* 0xa3d: mov    edx,DWORD PTR [r15+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_a41:
	/* 0xa41: and    r14b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_a45:
	/* 0xa45: mov    rsi,QWORD PTR [rip+0x23ca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_a4c:
	/* 0xa4c: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a4f:
	/* 0xa4f: je     a62 <tail_nodeport_nat_ingress_ipv4+0xa62> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa4f, 0xa62, x86_l_a62);
x86_l_a51:
	/* 0xa51: mov    rsi,QWORD PTR [rip+0x23ca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_a58:
	/* 0xa58: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a5a:
	/* 0xa5a: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_a5d:
	/* 0xa5d: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_a60:
	/* 0xa60: jmp    a67 <tail_nodeport_nat_ingress_ipv4+0xa67> */
	X86_SIM_X86_JMP(0xa60, 0xa67, x86_l_a67);
x86_l_a62:
	/* 0xa62: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_a67:
	/* 0xa67: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_a69:
	/* 0xa69: or     r14b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_a6c:
	/* 0xa6c: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_a6e:
	/* 0xa6e: jb     a75 <tail_nodeport_nat_ingress_ipv4+0xa75> */
	X86_SIM_X86_JCC(X86_CC_B, 0xa6e, 0xa75, x86_l_a75);
x86_l_a70:
	/* 0xa70: cmp    cl,r14b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R14, X86_WIDTH_8);
x86_l_a73:
	/* 0xa73: je     a86 <tail_nodeport_nat_ingress_ipv4+0xa86> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa73, 0xa86, x86_l_a86);
x86_l_a75:
	/* 0xa75: mov    BYTE PTR [r15+0x2b],r14b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R14, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_a79:
	/* 0xa79: mov    DWORD PTR [r15+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_a7d:
	/* 0xa7d: mov    rax,QWORD PTR [rip+0x23ca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_a84:
	/* 0xa84: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a86:
	/* 0xa86: mov    r15,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_a8b:
	/* 0xa8b: movzx  r9d,WORD PTR [r15+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_a90:
	/* 0xa90: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a92:
	/* 0xa92: movzx  r8d,BYTE PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 20ULL);
x86_l_a98:
	/* 0xa98: mov    edx,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a9c:
	/* 0xa9c: mov    esi,DWORD PTR [r15+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_aa0:
	/* 0xaa0: movzx  r10d,WORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_aa6:
	/* 0xaa6: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_aa8:
	/* 0xaa8: mov    r14d,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_aad:
	/* 0xaad: jne    abd <tail_nodeport_nat_ingress_ipv4+0xabd> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xaad, 0xabd, x86_l_abd);
x86_l_aaf:
	/* 0xaaf: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ab1:
	/* 0xab1: jne    abd <tail_nodeport_nat_ingress_ipv4+0xabd> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xab1, 0xabd, x86_l_abd);
x86_l_ab3:
	/* 0xab3: cmp    r10w,r9w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R10, X86_R9, X86_WIDTH_16);
x86_l_ab7:
	/* 0xab7: je     e58 <tail_nodeport_nat_ingress_ipv4+0xe58> */
	X86_SIM_X86_JCC(X86_CC_E, 0xab7, 0xe58, x86_l_e58);
x86_l_abd:
	/* 0xabd: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_abf:
	/* 0xabf: add    edx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_ac1:
	/* 0xac1: adc    edx,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_ac4:
	/* 0xac4: mov    rcx,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ac7:
	/* 0xac7: mov    rdi,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_acb:
	/* 0xacb: lea    r11,[rcx+0x22] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_acf:
	/* 0xacf: mov    ebp,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967155ULL);
x86_l_ad4:
	/* 0xad4: cmp    r11,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R11, X86_RDI, X86_WIDTH_64);
x86_l_ad7:
	/* 0xad7: ja     6f <tail_nodeport_nat_ingress_ipv4+0x6f> */
	X86_SIM_X86_JCC(X86_CC_A, 0xad7, 0x6f, x86_l_6f);
x86_l_add:
	/* 0xadd: movzx  r11d,WORD PTR [rcx+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 24ULL);
x86_l_ae2:
	/* 0xae2: not    r11d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_ae5:
	/* 0xae5: add    r11d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_ae8:
	/* 0xae8: adc    r11d,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_aec:
	/* 0xaec: movzx  ebp,r11w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_R11, X86_WIDTH_32, X86_WIDTH_16);
x86_l_af0:
	/* 0xaf0: shr    r11d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_af4:
	/* 0xaf4: add    r11d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_af7:
	/* 0xaf7: mov    ebp,r11d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R11, X86_WIDTH_32);
x86_l_afa:
	/* 0xafa: shr    ebp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_afd:
	/* 0xafd: add    ebp,r11d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R11, X86_WIDTH_32, X86_ALU_ADD);
x86_l_b00:
	/* 0xb00: mov    DWORD PTR [rcx+0x1e],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_b03:
	/* 0xb03: not    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_b05:
	/* 0xb05: mov    WORD PTR [rcx+0x18],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b09:
	/* 0xb09: movabs rsi,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 2199023255552ULL);
x86_l_b13:
	/* 0xb13: test   r12,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_RSI, X86_WIDTH_64);
x86_l_b16:
	/* 0xb16: jne    e58 <tail_nodeport_nat_ingress_ipv4+0xe58> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb16, 0xe58, x86_l_e58);
x86_l_b1c:
	/* 0xb1c: mov    sil,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_8, 1ULL);
x86_l_b1f:
	/* 0xb1f: cmp    r8d,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 58ULL);
x86_l_b23:
	/* 0xb23: je     b41 <tail_nodeport_nat_ingress_ipv4+0xb41> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb23, 0xb41, x86_l_b41);
x86_l_b25:
	/* 0xb25: cmp    r8d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 17ULL);
x86_l_b29:
	/* 0xb29: je     b38 <tail_nodeport_nat_ingress_ipv4+0xb38> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb29, 0xb38, x86_l_b38);
x86_l_b2b:
	/* 0xb2b: cmp    r8d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 6ULL);
x86_l_b2f:
	/* 0xb2f: jne    b48 <tail_nodeport_nat_ingress_ipv4+0xb48> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb2f, 0xb48, x86_l_b48);
x86_l_b31:
	/* 0xb31: mov    r11w,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R11, X86_WIDTH_16, 16ULL);
x86_l_b36:
	/* 0xb36: jmp    b4b <tail_nodeport_nat_ingress_ipv4+0xb4b> */
	X86_SIM_X86_JMP(0xb36, 0xb4b, x86_l_b4b);
x86_l_b38:
	/* 0xb38: mov    r11w,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R11, X86_WIDTH_16, 6ULL);
x86_l_b3d:
	/* 0xb3d: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b3f:
	/* 0xb3f: jmp    b4b <tail_nodeport_nat_ingress_ipv4+0xb4b> */
	X86_SIM_X86_JMP(0xb3f, 0xb4b, x86_l_b4b);
x86_l_b41:
	/* 0xb41: mov    r11w,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R11, X86_WIDTH_16, 2ULL);
x86_l_b46:
	/* 0xb46: jmp    b4b <tail_nodeport_nat_ingress_ipv4+0xb4b> */
	X86_SIM_X86_JMP(0xb46, 0xb4b, x86_l_b4b);
x86_l_b48:
	/* 0xb48: xor    r11d,r11d */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_R11, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b4b:
	/* 0xb4b: cmp    r10w,r9w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R10, X86_R9, X86_WIDTH_16);
x86_l_b4f:
	/* 0xb4f: jne    ba2 <tail_nodeport_nat_ingress_ipv4+0xba2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb4f, 0xba2, x86_l_ba2);
x86_l_b51:
	/* 0xb51: test   r11w,r11w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R11, X86_R11, X86_WIDTH_16);
x86_l_b55:
	/* 0xb55: je     deb <tail_nodeport_nat_ingress_ipv4+0xdeb> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb55, 0xdeb, x86_l_deb);
x86_l_b5b:
	/* 0xb5b: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b60:
	/* 0xb60: add    al,r11b */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R11, X86_WIDTH_8, X86_ALU_ADD);
x86_l_b63:
	/* 0xb63: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_b66:
	/* 0xb66: lea    r8,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_b6a:
	/* 0xb6a: add    r8,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_b6e:
	/* 0xb6e: mov    ebp,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967142ULL);
x86_l_b73:
	/* 0xb73: cmp    r8,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDI, X86_WIDTH_64);
x86_l_b76:
	/* 0xb76: ja     6f <tail_nodeport_nat_ingress_ipv4+0x6f> */
	X86_SIM_X86_JCC(X86_CC_A, 0xb76, 0x6f, x86_l_6f);
x86_l_b7c:
	/* 0xb7c: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_b7f:
	/* 0xb7f: movzx  eax,WORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_b82:
	/* 0xb82: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b84:
	/* 0xb84: setne  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_NE);
x86_l_b88:
	/* 0xb88: or     dil,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_8, X86_ALU_OR);
x86_l_b8b:
	/* 0xb8b: cmp    dil,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_8, 1ULL);
x86_l_b8f:
	/* 0xb8f: jne    e58 <tail_nodeport_nat_ingress_ipv4+0xe58> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb8f, 0xe58, x86_l_e58);
x86_l_b95:
	/* 0xb95: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_b97:
	/* 0xb97: add    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_b99:
	/* 0xb99: setb   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_B);
x86_l_b9d:
	/* 0xb9d: jmp    e2c <tail_nodeport_nat_ingress_ipv4+0xe2c> */
	X86_SIM_X86_JMP(0xb9d, 0xe2c, x86_l_e2c);
x86_l_ba2:
	/* 0xba2: cmp    r8d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 17ULL);
x86_l_ba6:
	/* 0xba6: je     bc2 <tail_nodeport_nat_ingress_ipv4+0xbc2> */
	X86_SIM_X86_JCC(X86_CC_E, 0xba6, 0xbc2, x86_l_bc2);
x86_l_ba8:
	/* 0xba8: cmp    r8d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 6ULL);
x86_l_bac:
	/* 0xbac: je     bc2 <tail_nodeport_nat_ingress_ipv4+0xbc2> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbac, 0xbc2, x86_l_bc2);
x86_l_bae:
	/* 0xbae: mov    ebp,0xffffff72 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967154ULL);
x86_l_bb3:
	/* 0xbb3: cmp    r8d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 1ULL);
x86_l_bb7:
	/* 0xbb7: jne    6f <tail_nodeport_nat_ingress_ipv4+0x6f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xbb7, 0x6f, x86_l_6f);
x86_l_bbd:
	/* 0xbbd: mov    r11w,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R11, X86_WIDTH_16, 2ULL);
x86_l_bc2:
	/* 0xbc2: add    r14b,BYTE PTR [rsp+0x28] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RSP, X86_WIDTH_8, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 40ULL);
x86_l_bc7:
	/* 0xbc7: movzx  r14d,r14b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_R14, X86_WIDTH_32, X86_WIDTH_8);
x86_l_bcb:
	/* 0xbcb: lea    r15,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_bcf:
	/* 0xbcf: add    r15,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_bd3:
	/* 0xbd3: mov    ebp,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967155ULL);
x86_l_bd8:
	/* 0xbd8: cmp    r15,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R15, X86_RDI, X86_WIDTH_64);
x86_l_bdb:
	/* 0xbdb: ja     6f <tail_nodeport_nat_ingress_ipv4+0x6f> */
	X86_SIM_X86_JCC(X86_CC_A, 0xbdb, 0x6f, x86_l_6f);
x86_l_be1:
	/* 0xbe1: add    r14,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_be4:
	/* 0xbe4: mov    WORD PTR [r14],r9w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R9, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_be8:
	/* 0xbe8: mov    r14,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_bed:
	/* 0xbed: lea    ebp,[r14+r11*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R11, 0), 0ULL);
x86_l_bf1:
	/* 0xbf1: movzx  r14d,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_bf5:
	/* 0xbf5: lea    r15,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_bf9:
	/* 0xbf9: add    r15,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_bfd:
	/* 0xbfd: mov    ebp,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967142ULL);
x86_l_c02:
	/* 0xc02: cmp    r15,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R15, X86_RDI, X86_WIDTH_64);
x86_l_c05:
	/* 0xc05: ja     6f <tail_nodeport_nat_ingress_ipv4+0x6f> */
	X86_SIM_X86_JCC(X86_CC_A, 0xc05, 0x6f, x86_l_6f);
x86_l_c0b:
	/* 0xc0b: add    r14,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_c0e:
	/* 0xc0e: test   sil,sil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_8);
x86_l_c11:
	/* 0xc11: jne    c1e <tail_nodeport_nat_ingress_ipv4+0xc1e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xc11, 0xc1e, x86_l_c1e);
x86_l_c13:
	/* 0xc13: cmp    WORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c18:
	/* 0xc18: je     de1 <tail_nodeport_nat_ingress_ipv4+0xde1> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc18, 0xde1, x86_l_de1);
x86_l_c1e:
	/* 0xc1e: movzx  ebp,r9w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_R9, X86_WIDTH_32, X86_WIDTH_16);
x86_l_c22:
	/* 0xc22: test   r10d,r10d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R10, X86_R10, X86_WIDTH_32);
x86_l_c25:
	/* 0xc25: je     d9a <tail_nodeport_nat_ingress_ipv4+0xd9a> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc25, 0xd9a, x86_l_d9a);
x86_l_c2b:
	/* 0xc2b: not    r10d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_c2e:
	/* 0xc2e: add    r10d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_c31:
	/* 0xc31: adc    r10d,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_c35:
	/* 0xc35: movzx  r9d,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_c39:
	/* 0xc39: not    r9d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_c3c:
	/* 0xc3c: add    r9d,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R10, X86_WIDTH_32, X86_ALU_ADD);
x86_l_c3f:
	/* 0xc3f: jmp    da4 <tail_nodeport_nat_ingress_ipv4+0xda4> */
	X86_SIM_X86_JMP(0xc3f, 0xda4, x86_l_da4);
x86_l_c44:
	/* 0xc44: mov    DWORD PTR [rsp+0xb4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 773094113280ULL);
x86_l_c4f:
	/* 0xc4f: jmp    4e <tail_nodeport_nat_ingress_ipv4+0x4e> */
	X86_SIM_X86_JMP(0xc4f, 0x4e, x86_l_4e);
x86_l_c54:
	/* 0xc54: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c57:
	/* 0xc57: mov    edx,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c5b:
	/* 0xc5b: lea    rsi,[rax+rdx*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_c5f:
	/* 0xc5f: add    rsi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_c63:
	/* 0xc63: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_c68:
	/* 0xc68: cmp    rsi,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_c6c:
	/* 0xc6c: ja     6f <tail_nodeport_nat_ingress_ipv4+0x6f> */
	X86_SIM_X86_JCC(X86_CC_A, 0xc6c, 0x6f, x86_l_6f);
x86_l_c72:
	/* 0xc72: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_c75:
	/* 0xc75: cmp    WORD PTR [rax+0x6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 25769803776ULL);
x86_l_c7a:
	/* 0xc7a: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_c7d:
	/* 0xc7d: mov    sil,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_8, 1ULL);
x86_l_c80:
	/* 0xc80: mov    edx,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_c84:
	/* 0xc84: mov    rdi,r10 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R10, X86_WIDTH_64);
x86_l_c87:
	/* 0xc87: mov    r8d,DWORD PTR [r10+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R10, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c8b:
	/* 0xc8b: movzx  r11d,WORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 104ULL);
x86_l_c91:
	/* 0xc91: movzx  r14d,WORD PTR [r10+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R10, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_c96:
	/* 0xc96: movzx  edi,r14w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDI, X86_R14, X86_WIDTH_32, X86_WIDTH_16);
x86_l_c9a:
	/* 0xc9a: test   sil,sil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_8);
x86_l_c9d:
	/* 0xc9d: je     cb3 <tail_nodeport_nat_ingress_ipv4+0xcb3> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc9d, 0xcb3, x86_l_cb3);
x86_l_c9f:
	/* 0xc9f: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_ca1:
	/* 0xca1: je     cb3 <tail_nodeport_nat_ingress_ipv4+0xcb3> */
	X86_SIM_X86_JCC(X86_CC_E, 0xca1, 0xcb3, x86_l_cb3);
x86_l_ca3:
	/* 0xca3: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ca5:
	/* 0xca5: cmp    edx,r8d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R8, X86_WIDTH_32);
x86_l_ca8:
	/* 0xca8: je     cc5 <tail_nodeport_nat_ingress_ipv4+0xcc5> */
	X86_SIM_X86_JCC(X86_CC_E, 0xca8, 0xcc5, x86_l_cc5);
x86_l_caa:
	/* 0xcaa: mov    eax,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R8, X86_WIDTH_32);
x86_l_cad:
	/* 0xcad: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_caf:
	/* 0xcaf: add    eax,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_cb1:
	/* 0xcb1: jmp    cc2 <tail_nodeport_nat_ingress_ipv4+0xcc2> */
	X86_SIM_X86_JMP(0xcb1, 0xcc2, x86_l_cc2);
x86_l_cb3:
	/* 0xcb3: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_cb5:
	/* 0xcb5: cmp    r11w,r14w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R11, X86_R14, X86_WIDTH_16);
x86_l_cb9:
	/* 0xcb9: je     cc5 <tail_nodeport_nat_ingress_ipv4+0xcc5> */
	X86_SIM_X86_JCC(X86_CC_E, 0xcb9, 0xcc5, x86_l_cc5);
x86_l_cbb:
	/* 0xcbb: mov    eax,r11d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R11, X86_WIDTH_32);
x86_l_cbe:
	/* 0xcbe: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_cc0:
	/* 0xcc0: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_cc2:
	/* 0xcc2: adc    eax,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_cc5:
	/* 0xcc5: cmp    edx,r8d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R8, X86_WIDTH_32);
x86_l_cc8:
	/* 0xcc8: jne    ce3 <tail_nodeport_nat_ingress_ipv4+0xce3> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xcc8, 0xce3, x86_l_ce3);
x86_l_cca:
	/* 0xcca: cmp    r11w,r14w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R11, X86_R14, X86_WIDTH_16);
x86_l_cce:
	/* 0xcce: jne    ce3 <tail_nodeport_nat_ingress_ipv4+0xce3> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xcce, 0xce3, x86_l_ce3);
x86_l_cd0:
	/* 0xcd0: xor    r9d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R9, X86_WIDTH_32, X86_ALU_XOR);
x86_l_cd3:
	/* 0xcd3: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_cdb:
	/* 0xcdb: mov    r15,r10 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R10, X86_WIDTH_64);
x86_l_cde:
	/* 0xcde: jmp    a92 <tail_nodeport_nat_ingress_ipv4+0xa92> */
	X86_SIM_X86_JMP(0xcde, 0xa92, x86_l_a92);
x86_l_ce3:
	/* 0xce3: mov    DWORD PTR [rsp+0x3c],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_ce7:
	/* 0xce7: mov    BYTE PTR [rsp+0x40],sil */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_cec:
	/* 0xcec: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_cee:
	/* 0xcee: add    edx,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R8, X86_WIDTH_32, X86_ALU_ADD);
x86_l_cf1:
	/* 0xcf1: adc    edx,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_cf4:
	/* 0xcf4: mov    r9,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cf7:
	/* 0xcf7: mov    rsi,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cfb:
	/* 0xcfb: mov    rdi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_d00:
	/* 0xd00: lea    r15,[r9+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_d04:
	/* 0xd04: add    r15,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_d08:
	/* 0xd08: mov    ebp,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967155ULL);
x86_l_d0d:
	/* 0xd0d: cmp    r15,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R15, X86_RSI, X86_WIDTH_64);
x86_l_d10:
	/* 0xd10: ja     6f <tail_nodeport_nat_ingress_ipv4+0x6f> */
	X86_SIM_X86_JCC(X86_CC_A, 0xd10, 0x6f, x86_l_6f);
x86_l_d16:
	/* 0xd16: mov    QWORD PTR [rsp+0xa8],r9 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_d1e:
	/* 0xd1e: lea    r15,[r9+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_d22:
	/* 0xd22: lea    rdi,[r15+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_d26:
	/* 0xd26: mov    DWORD PTR [r15+0x14],r8d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_d2a:
	/* 0xd2a: mov    ebp,0xffffff67 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967143ULL);
x86_l_d2f:
	/* 0xd2f: cmp    rdi,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_64);
x86_l_d32:
	/* 0xd32: ja     6f <tail_nodeport_nat_ingress_ipv4+0x6f> */
	X86_SIM_X86_JCC(X86_CC_A, 0xd32, 0x6f, x86_l_6f);
x86_l_d38:
	/* 0xd38: mov    QWORD PTR [rsp+0xb8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_d40:
	/* 0xd40: movzx  edi,WORD PTR [r15+0x12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18ULL);
x86_l_d45:
	/* 0xd45: not    edi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_d47:
	/* 0xd47: add    edi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_d49:
	/* 0xd49: adc    edi,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_d4c:
	/* 0xd4c: movzx  r8d,di */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_RDI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_d50:
	/* 0xd50: shr    edi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_d53:
	/* 0xd53: add    edi,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R8, X86_WIDTH_32, X86_ALU_ADD);
x86_l_d56:
	/* 0xd56: mov    r8d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RDI, X86_WIDTH_32);
x86_l_d59:
	/* 0xd59: shr    r8d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_d5d:
	/* 0xd5d: add    r8d,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_d60:
	/* 0xd60: not    r8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_d63:
	/* 0xd63: mov    WORD PTR [r15+0x12],r8w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R8, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_d68:
	/* 0xd68: mov    r8b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_8, 1ULL);
x86_l_d6b:
	/* 0xd6b: cmp    ecx,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 58ULL);
x86_l_d6e:
	/* 0xd6e: je     1447 <tail_nodeport_nat_ingress_ipv4+0x1447> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd6e, 0x1447, x86_l_1447);
x86_l_d74:
	/* 0xd74: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_d77:
	/* 0xd77: je     143d <tail_nodeport_nat_ingress_ipv4+0x143d> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd77, 0x143d, x86_l_143d);
x86_l_d7d:
	/* 0xd7d: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_d80:
	/* 0xd80: jne    144e <tail_nodeport_nat_ingress_ipv4+0x144e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xd80, 0x144e, x86_l_144e);
x86_l_d86:
	/* 0xd86: mov    r15w,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_16, 16ULL);
x86_l_d8b:
	/* 0xd8b: jmp    1451 <tail_nodeport_nat_ingress_ipv4+0x1451> */
	X86_SIM_X86_JMP(0xd8b, 0x1451, x86_l_1451);
x86_l_d90:
	/* 0xd90: mov    ebp,0xffffff71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967153ULL);
x86_l_d95:
	/* 0xd95: jmp    6f <tail_nodeport_nat_ingress_ipv4+0x6f> */
	X86_SIM_X86_JMP(0xd95, 0x6f, x86_l_6f);
x86_l_d9a:
	/* 0xd9a: movzx  r9d,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_d9e:
	/* 0xd9e: not    r9d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_da1:
	/* 0xda1: add    r9d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_da4:
	/* 0xda4: setb   r10b */
	X86_SIM_L_EXEC_SETCC(X86_R10, X86_CC_B);
x86_l_da8:
	/* 0xda8: movzx  r10d,r10b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R10, X86_R10, X86_WIDTH_32, X86_WIDTH_8);
x86_l_dac:
	/* 0xdac: add    r10d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R9, X86_WIDTH_32, X86_ALU_ADD);
x86_l_daf:
	/* 0xdaf: movzx  r9d,r10w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R9, X86_R10, X86_WIDTH_32, X86_WIDTH_16);
x86_l_db3:
	/* 0xdb3: shr    r10d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_db7:
	/* 0xdb7: add    r10d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R9, X86_WIDTH_32, X86_ALU_ADD);
x86_l_dba:
	/* 0xdba: mov    r9d,r10d */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_R10, X86_WIDTH_32);
x86_l_dbd:
	/* 0xdbd: shr    r9d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_dc1:
	/* 0xdc1: add    r9d,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R10, X86_WIDTH_32, X86_ALU_ADD);
x86_l_dc4:
	/* 0xdc4: cmp    r9w,0xffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_16, 65535ULL);
x86_l_dc9:
	/* 0xdc9: not    r9d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_dcc:
	/* 0xdcc: mov    r10d,0xffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_32, 65535ULL);
x86_l_dd2:
	/* 0xdd2: cmovne r10d,r9d */
	X86_SIM_L_EXEC_CMOV(X86_R10, X86_R9, X86_WIDTH_32, X86_CC_NE);
x86_l_dd6:
	/* 0xdd6: test   sil,sil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_8);
x86_l_dd9:
	/* 0xdd9: cmovne r10d,r9d */
	X86_SIM_L_EXEC_CMOV(X86_R10, X86_R9, X86_WIDTH_32, X86_CC_NE);
x86_l_ddd:
	/* 0xddd: mov    WORD PTR [r14],r10w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R10, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_de1:
	/* 0xde1: cmp    r8d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 1ULL);
x86_l_de5:
	/* 0xde5: jne    b51 <tail_nodeport_nat_ingress_ipv4+0xb51> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xde5, 0xb51, x86_l_b51);
x86_l_deb:
	/* 0xdeb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ded:
	/* 0xded: je     e58 <tail_nodeport_nat_ingress_ipv4+0xe58> */
	X86_SIM_X86_JCC(X86_CC_E, 0xded, 0xe58, x86_l_e58);
x86_l_def:
	/* 0xdef: movzx  edx,r13b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_R13, X86_WIDTH_32, X86_WIDTH_8);
x86_l_df3:
	/* 0xdf3: lea    r8,[rcx+rdx*1] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_df7:
	/* 0xdf7: add    r8,0x12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_64, X86_ALU_ADD, 18ULL);
x86_l_dfb:
	/* 0xdfb: mov    ebp,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967142ULL);
x86_l_e00:
	/* 0xe00: cmp    r8,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RDI, X86_WIDTH_64);
x86_l_e03:
	/* 0xe03: ja     6f <tail_nodeport_nat_ingress_ipv4+0x6f> */
	X86_SIM_X86_JCC(X86_CC_A, 0xe03, 0x6f, x86_l_6f);
x86_l_e09:
	/* 0xe09: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_e0c:
	/* 0xe0c: add    rcx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_e10:
	/* 0xe10: movzx  edx,WORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_e13:
	/* 0xe13: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_e15:
	/* 0xe15: setne  dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_NE);
x86_l_e19:
	/* 0xe19: or     dil,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_8, X86_ALU_OR);
x86_l_e1c:
	/* 0xe1c: cmp    dil,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDI, X86_WIDTH_8, 1ULL);
x86_l_e20:
	/* 0xe20: jne    e58 <tail_nodeport_nat_ingress_ipv4+0xe58> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe20, 0xe58, x86_l_e58);
x86_l_e22:
	/* 0xe22: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_e24:
	/* 0xe24: add    eax,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_e26:
	/* 0xe26: setb   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_B);
x86_l_e2a:
	/* 0xe2a: mov    edx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_e2c:
	/* 0xe2c: movzx  eax,dil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_e30:
	/* 0xe30: add    eax,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_e32:
	/* 0xe32: movzx  edx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_e35:
	/* 0xe35: shr    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_e38:
	/* 0xe38: add    eax,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_e3a:
	/* 0xe3a: mov    edx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_e3c:
	/* 0xe3c: shr    edx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_e3f:
	/* 0xe3f: add    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_e41:
	/* 0xe41: cmp    dx,0xffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_16, 65535ULL);
x86_l_e45:
	/* 0xe45: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_e47:
	/* 0xe47: mov    eax,0xffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 65535ULL);
x86_l_e4c:
	/* 0xe4c: cmovne eax,edx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RDX, X86_WIDTH_32, X86_CC_NE);
x86_l_e4f:
	/* 0xe4f: test   sil,sil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_8);
x86_l_e52:
	/* 0xe52: cmovne eax,edx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RDX, X86_WIDTH_32, X86_CC_NE);
x86_l_e55:
	/* 0xe55: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e58:
	/* 0xe58: mov    DWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_e60:
	/* 0xe60: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e65:
	/* 0xe65: mov    rdi,QWORD PTR [rip+0x23ca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_e6c:
	/* 0xe6c: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_e71:
	/* 0xe71: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e73:
	/* 0xe73: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e76:
	/* 0xe76: je     176e <tail_nodeport_nat_ingress_ipv4+0x176e> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe76, 0x176e, x86_l_176e);
x86_l_e7c:
	/* 0xe7c: mov    ebp,DWORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_e7f:
	/* 0xe7f: mov    DWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_e87:
	/* 0xe87: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e8c:
	/* 0xe8c: mov    rdi,QWORD PTR [rip+0x23ca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_e93:
	/* 0xe93: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_e98:
	/* 0xe98: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e9a:
	/* 0xe9a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e9d:
	/* 0xe9d: je     ea5 <tail_nodeport_nat_ingress_ipv4+0xea5> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe9d, 0xea5, x86_l_ea5);
x86_l_e9f:
	/* 0xe9f: or     ebp,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_OR, 4ULL);
x86_l_ea2:
	/* 0xea2: mov    DWORD PTR [rax+0x18],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ea5:
	/* 0xea5: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_eae:
	/* 0xeae: mov    DWORD PTR [rsp+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_eb9:
	/* 0xeb9: mov    QWORD PTR [rsp+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_ec5:
	/* 0xec5: mov    QWORD PTR [rsp+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_ed1:
	/* 0xed1: mov    QWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_edd:
	/* 0xedd: mov    QWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_ee9:
	/* 0xee9: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_ef2:
	/* 0xef2: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_efb:
	/* 0xefb: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_f04:
	/* 0xf04: mov    BYTE PTR [rsp+0x60],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 412316860418ULL);
x86_l_f09:
	/* 0xf09: mov    eax,DWORD PTR [rbx+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_f0c:
	/* 0xf0c: mov    DWORD PTR [rsp+0x68],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_f10:
	/* 0xf10: mov    WORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_f17:
	/* 0xf17: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_f1f:
	/* 0xf1f: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f22:
	/* 0xf22: mov    rcx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f26:
	/* 0xf26: lea    rdx,[rax+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_f2a:
	/* 0xf2a: mov    r15d,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967162ULL);
x86_l_f30:
	/* 0xf30: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f33:
	/* 0xf33: cmp    rdx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_f36:
	/* 0xf36: movabs r9,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_64, 2199023255552ULL);
x86_l_f40:
	/* 0xf40: movabs r10,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_64, 1099511627776ULL);
x86_l_f4a:
	/* 0xf4a: jbe    f5c <tail_nodeport_nat_ingress_ipv4+0xf5c> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xf4a, 0xf5c, x86_l_f5c);
x86_l_f4c:
	/* 0xf4c: shl    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_f50:
	/* 0xf50: movzx  r12d,r14w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R14, X86_WIDTH_32, X86_WIDTH_16);
x86_l_f54:
	/* 0xf54: mov    ebp,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_32);
x86_l_f57:
	/* 0xf57: jmp    ca <tail_nodeport_nat_ingress_ipv4+0xca> */
	X86_SIM_X86_JMP(0xf57, 0xca, x86_l_ca);
x86_l_f5c:
	/* 0xf5c: movzx  edx,WORD PTR [rax+0x12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18ULL);
x86_l_f60:
	/* 0xf60: movzx  r12d,BYTE PTR [rax+0x17] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 23ULL);
x86_l_f65:
	/* 0xf65: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_f68:
	/* 0xf68: shl    rsi,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_f6c:
	/* 0xf6c: or     rsi,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_64, X86_ALU_OR);
x86_l_f6f:
	/* 0xf6f: movzx  edx,WORD PTR [rax+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 20ULL);
x86_l_f73:
	/* 0xf73: mov    r8,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RSI, X86_WIDTH_64);
x86_l_f76:
	/* 0xf76: or     r8,r10 */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R10, X86_WIDTH_64, X86_ALU_OR);
x86_l_f79:
	/* 0xf79: test   edx,0xff3f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_32, 65343ULL);
x86_l_f7f:
	/* 0xf7f: cmove  r8,rsi */
	X86_SIM_L_EXEC_CMOV(X86_R8, X86_RSI, X86_WIDTH_64, X86_CC_E);
x86_l_f83:
	/* 0xf83: mov    r13,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R8, X86_WIDTH_64);
x86_l_f86:
	/* 0xf86: or     r13,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R9, X86_WIDTH_64, X86_ALU_OR);
x86_l_f89:
	/* 0xf89: test   edx,0xff1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_32, 65311ULL);
x86_l_f8f:
	/* 0xf8f: mov    edi,DWORD PTR [rax+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_f92:
	/* 0xf92: mov    BYTE PTR [rsp+0x14],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_f97:
	/* 0xf97: mov    edx,DWORD PTR [rax+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_f9a:
	/* 0xf9a: mov    DWORD PTR [rsp+0x8],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f9e:
	/* 0xf9e: cmove  r13,r8 */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_R8, X86_WIDTH_64, X86_CC_E);
x86_l_fa2:
	/* 0xfa2: mov    esi,DWORD PTR [rax+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_fa5:
	/* 0xfa5: mov    DWORD PTR [rsp+0xc],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_fa9:
	/* 0xfa9: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_fae:
	/* 0xfae: cmp    r12d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 17ULL);
x86_l_fb2:
	/* 0xfb2: je     fbe <tail_nodeport_nat_ingress_ipv4+0xfbe> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfb2, 0xfbe, x86_l_fbe);
x86_l_fb4:
	/* 0xfb4: cmp    r12d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 6ULL);
x86_l_fb8:
	/* 0xfb8: jne    1eb1 <tail_nodeport_nat_ingress_ipv4+0x1eb1> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xfb8, 0x1eb1, x86_l_1eb1);
x86_l_fbe:
	/* 0xfbe: and    edi,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_fc1:
	/* 0xfc1: lea    r11,[rdi*4+0xe] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 2), 14ULL);
x86_l_fc9:
	/* 0xfc9: mov    r8,QWORD PTR [rip+0x23ca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R8, (void *)(long)(((__u64)(long)&__config_enable_ipv4_fragments)));
x86_l_fd0:
	/* 0xfd0: cmp    BYTE PTR [r8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fd4:
	/* 0xfd4: je     102e <tail_nodeport_nat_ingress_ipv4+0x102e> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfd4, 0x102e, x86_l_102e);
x86_l_fd6:
	/* 0xfd6: mov    DWORD PTR [rsp+0x48],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_fda:
	/* 0xfda: mov    DWORD PTR [rsp+0x4c],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_fde:
	/* 0xfde: mov    WORD PTR [rsp+0x50],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_fe4:
	/* 0xfe4: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_fe7:
	/* 0xfe7: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_feb:
	/* 0xfeb: mov    BYTE PTR [rsp+0x52],dl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 82ULL);
x86_l_fef:
	/* 0xfef: mov    BYTE PTR [rsp+0x53],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 356482285568ULL);
x86_l_ff4:
	/* 0xff4: test   r13,r9 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R9, X86_WIDTH_64);
x86_l_ff7:
	/* 0xff7: jne    1b40 <tail_nodeport_nat_ingress_ipv4+0x1b40> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xff7, 0x1b40, x86_l_1b40);
x86_l_ffd:
	/* 0xffd: lea    rdx,[rax+r11*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R11, 0), 0ULL);
x86_l_1001:
	/* 0x1001: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1005:
	/* 0x1005: mov    r15d,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967161ULL);
x86_l_100b:
	/* 0x100b: cmp    rdx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_100e:
	/* 0x100e: ja     f4c <tail_nodeport_nat_ingress_ipv4+0xf4c> */
	X86_SIM_X86_JCC(X86_CC_A, 0x100e, 0xf4c, x86_l_f4c);
x86_l_1014:
	/* 0x1014: add    rax,r11 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R11, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1017:
	/* 0x1017: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1019:
	/* 0x1019: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_101d:
	/* 0x101d: test   r13,r10 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R10, X86_WIDTH_64);
x86_l_1020:
	/* 0x1020: jne    1bb1 <tail_nodeport_nat_ingress_ipv4+0x1bb1> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1020, 0x1bb1, x86_l_1bb1);
x86_l_1026:
	/* 0x1026: movzx  r12d,BYTE PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 20ULL);
x86_l_102c:
	/* 0x102c: jmp    105b <tail_nodeport_nat_ingress_ipv4+0x105b> */
	X86_SIM_X86_JMP(0x102c, 0x105b, x86_l_105b);
x86_l_102e:
	/* 0x102e: test   r13,r9 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R9, X86_WIDTH_64);
x86_l_1031:
	/* 0x1031: jne    1b72 <tail_nodeport_nat_ingress_ipv4+0x1b72> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1031, 0x1b72, x86_l_1b72);
x86_l_1037:
	/* 0x1037: movzx  edx,r11b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_R11, X86_WIDTH_32, X86_WIDTH_8);
x86_l_103b:
	/* 0x103b: lea    rsi,[rax+rdx*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_103f:
	/* 0x103f: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1043:
	/* 0x1043: mov    r15d,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967161ULL);
x86_l_1049:
	/* 0x1049: cmp    rsi,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_64);
x86_l_104c:
	/* 0x104c: ja     f4c <tail_nodeport_nat_ingress_ipv4+0xf4c> */
	X86_SIM_X86_JCC(X86_CC_A, 0x104c, 0xf4c, x86_l_f4c);
x86_l_1052:
	/* 0x1052: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1055:
	/* 0x1055: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1057:
	/* 0x1057: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_105b:
	/* 0x105b: cmp    r12b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_8, 6ULL);
x86_l_105f:
	/* 0x105f: jne    106a <tail_nodeport_nat_ingress_ipv4+0x106a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x105f, 0x106a, x86_l_106a);
x86_l_1061:
	/* 0x1061: mov    rdi,QWORD PTR [rip+0x23ca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct4_global)));
x86_l_1068:
	/* 0x1068: jmp    1071 <tail_nodeport_nat_ingress_ipv4+0x1071> */
	X86_SIM_X86_JMP(0x1068, 0x1071, x86_l_1071);
x86_l_106a:
	/* 0x106a: mov    rdi,QWORD PTR [rip+0x23ca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct_any4_global)));
x86_l_1071:
	/* 0x1071: mov    BYTE PTR [rsp+0x15],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 90194313216ULL);
x86_l_1076:
	/* 0x1076: cmp    BYTE PTR [r8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_107a:
	/* 0x107a: mov    QWORD PTR [rsp+0x28],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_107f:
	/* 0x107f: je     1114 <tail_nodeport_nat_ingress_ipv4+0x1114> */
	X86_SIM_X86_JCC(X86_CC_E, 0x107f, 0x1114, x86_l_1114);
x86_l_1085:
	/* 0x1085: and    r10,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_1088:
	/* 0x1088: je     1114 <tail_nodeport_nat_ingress_ipv4+0x1114> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1088, 0x1114, x86_l_1114);
x86_l_108e:
	/* 0x108e: mov    QWORD PTR [rsp+0x30],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1093:
	/* 0x1093: mov    r14,r9 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R9, X86_WIDTH_64);
x86_l_1096:
	/* 0x1096: mov    r15,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_109a:
	/* 0x109a: sub    r15,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 0ULL);
x86_l_109d:
	/* 0x109d: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_10a6:
	/* 0x10a6: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_10af:
	/* 0x10af: movabs rax,0x6c03a50109 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 463917613321ULL);
x86_l_10b9:
	/* 0x10b9: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_10be:
	/* 0x10be: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_10c3:
	/* 0x10c3: mov    rdi,QWORD PTR [rip+0x23ca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_10ca:
	/* 0x10ca: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_10cf:
	/* 0x10cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10d1:
	/* 0x10d1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10d4:
	/* 0x10d4: je     10df <tail_nodeport_nat_ingress_ipv4+0x10df> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10d4, 0x10df, x86_l_10df);
x86_l_10d6:
	/* 0x10d6: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_10d9:
	/* 0x10d9: add    QWORD PTR [rax+0x8],r15 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_10dd:
	/* 0x10dd: jmp    1107 <tail_nodeport_nat_ingress_ipv4+0x1107> */
	X86_SIM_X86_JMP(0x10dd, 0x1107, x86_l_1107);
x86_l_10df:
	/* 0x10df: mov    QWORD PTR [rsp+0x18],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215105ULL);
x86_l_10e8:
	/* 0x10e8: mov    QWORD PTR [rsp+0x20],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_10ed:
	/* 0x10ed: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_10f2:
	/* 0x10f2: mov    rdi,QWORD PTR [rip+0x23ca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_10f9:
	/* 0x10f9: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_10fe:
	/* 0x10fe: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1103:
	/* 0x1103: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1105:
	/* 0x1105: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1107:
	/* 0x1107: mov    r9,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_R14, X86_WIDTH_64);
x86_l_110a:
	/* 0x110a: mov    r11,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_110f:
	/* 0x110f: mov    rdi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1114:
	/* 0x1114: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1117:
	/* 0x1117: cmp    r12b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_8, 6ULL);
x86_l_111b:
	/* 0x111b: jne    1171 <tail_nodeport_nat_ingress_ipv4+0x1171> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x111b, 0x1171, x86_l_1171);
x86_l_111d:
	/* 0x111d: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_1120:
	/* 0x1120: mov    r15d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 0ULL);
x86_l_1126:
	/* 0x1126: and    rax,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R9, X86_WIDTH_64, X86_ALU_AND);
x86_l_1129:
	/* 0x1129: jne    1174 <tail_nodeport_nat_ingress_ipv4+0x1174> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1129, 0x1174, x86_l_1174);
x86_l_112b:
	/* 0x112b: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_112e:
	/* 0x112e: movzx  ecx,r11b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R11, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1132:
	/* 0x1132: lea    rdx,[rax+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_1136:
	/* 0x1136: add    rdx,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 14ULL);
x86_l_113a:
	/* 0x113a: cmp    rdx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_113e:
	/* 0x113e: ja     1eb1 <tail_nodeport_nat_ingress_ipv4+0x1eb1> */
	X86_SIM_X86_JCC(X86_CC_A, 0x113e, 0x1eb1, x86_l_1eb1);
x86_l_1144:
	/* 0x1144: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1147:
	/* 0x1147: movzx  r14d,WORD PTR [rax+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_114c:
	/* 0x114c: mov    eax,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_32);
x86_l_114f:
	/* 0x114f: and    eax,0x1200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4608ULL);
x86_l_1154:
	/* 0x1154: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1157:
	/* 0x1157: cmp    eax,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 512ULL);
x86_l_115c:
	/* 0x115c: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_115f:
	/* 0x115f: test   r14d,0x500 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R14, X86_WIDTH_32, 1280ULL);
x86_l_1166:
	/* 0x1166: jne    1d3c <tail_nodeport_nat_ingress_ipv4+0x1d3c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1166, 0x1d3c, x86_l_1d3c);
x86_l_116c:
	/* 0x116c: mov    r15b,al */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_8);
x86_l_116f:
	/* 0x116f: jmp    1174 <tail_nodeport_nat_ingress_ipv4+0x1174> */
	X86_SIM_X86_JMP(0x116f, 0x1174, x86_l_1174);
x86_l_1171:
	/* 0x1171: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1174:
	/* 0x1174: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1179:
	/* 0x1179: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_117e:
	/* 0x117e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1180:
	/* 0x1180: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1183:
	/* 0x1183: je     1ea8 <tail_nodeport_nat_ingress_ipv4+0x1ea8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1183, 0x1ea8, x86_l_1ea8);
x86_l_1189:
	/* 0x1189: movzx  ecx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_118d:
	/* 0x118d: test   cl,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_1190:
	/* 0x1190: je     1ea8 <tail_nodeport_nat_ingress_ipv4+0x1ea8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1190, 0x1ea8, x86_l_1ea8);
x86_l_1196:
	/* 0x1196: cmp    WORD PTR [rax+0x26],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 163208757248ULL);
x86_l_119b:
	/* 0x119b: je     1ea8 <tail_nodeport_nat_ingress_ipv4+0x1ea8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x119b, 0x1ea8, x86_l_1ea8);
x86_l_11a1:
	/* 0x11a1: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_11a3:
	/* 0x11a3: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_11a5:
	/* 0x11a5: test   dl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_8, 3ULL);
x86_l_11a8:
	/* 0x11a8: je     12c0 <tail_nodeport_nat_ingress_ipv4+0x12c0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11a8, 0x12c0, x86_l_12c0);
x86_l_11ae:
	/* 0x11ae: mov    DWORD PTR [rsp+0x30],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_11b3:
	/* 0x11b3: mov    rsi,QWORD PTR [rip+0x23ca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_11ba:
	/* 0x11ba: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11bd:
	/* 0x11bd: je     11d0 <tail_nodeport_nat_ingress_ipv4+0x11d0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11bd, 0x11d0, x86_l_11d0);
x86_l_11bf:
	/* 0x11bf: mov    rdx,QWORD PTR [rip+0x23ca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_11c6:
	/* 0x11c6: imul   r14d,DWORD PTR [rdx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R14, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_11ca:
	/* 0x11ca: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_11ce:
	/* 0x11ce: jmp    11d6 <tail_nodeport_nat_ingress_ipv4+0x11d6> */
	X86_SIM_X86_JMP(0x11ce, 0x11d6, x86_l_11d6);
x86_l_11d0:
	/* 0x11d0: mov    r14d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 60ULL);
x86_l_11d6:
	/* 0x11d6: cmp    r12b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_8, 6ULL);
x86_l_11da:
	/* 0x11da: jne    1214 <tail_nodeport_nat_ingress_ipv4+0x1214> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x11da, 0x1214, x86_l_1214);
x86_l_11dc:
	/* 0x11dc: mov    edx,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_11e0:
	/* 0x11e0: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_11e2:
	/* 0x11e2: shr    edx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_11e5:
	/* 0x11e5: and    edx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_11e8:
	/* 0x11e8: or     ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_11ea:
	/* 0x11ea: mov    WORD PTR [rax+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_11ee:
	/* 0x11ee: test   cl,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 16ULL);
x86_l_11f1:
	/* 0x11f1: mov    ecx,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 60ULL);
x86_l_11f6:
	/* 0x11f6: mov    r14d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 21600ULL);
x86_l_11fc:
	/* 0x11fc: cmove  r14d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R14, X86_RCX, X86_WIDTH_32, X86_CC_E);
x86_l_1200:
	/* 0x1200: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1203:
	/* 0x1203: je     1214 <tail_nodeport_nat_ingress_ipv4+0x1214> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1203, 0x1214, x86_l_1214);
x86_l_1205:
	/* 0x1205: mov    rcx,QWORD PTR [rip+0x23ca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_120c:
	/* 0x120c: imul   r14d,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_1210:
	/* 0x1210: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1214:
	/* 0x1214: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1219:
	/* 0x1219: movzx  eax,WORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_121e:
	/* 0x121e: shr    eax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1221:
	/* 0x1221: mov    DWORD PTR [rsp+0x58],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1225:
	/* 0x1225: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1228:
	/* 0x1228: je     123c <tail_nodeport_nat_ingress_ipv4+0x123c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1228, 0x123c, x86_l_123c);
x86_l_122a:
	/* 0x122a: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_122f:
	/* 0x122f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1231:
	/* 0x1231: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1233:
	/* 0x1233: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1236:
	/* 0x1236: shr    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_123a:
	/* 0x123a: jmp    125f <tail_nodeport_nat_ingress_ipv4+0x125f> */
	X86_SIM_X86_JMP(0x123a, 0x125f, x86_l_125f);
x86_l_123c:
	/* 0x123c: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1241:
	/* 0x1241: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1243:
	/* 0x1243: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1245:
	/* 0x1245: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1249:
	/* 0x1249: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_1253:
	/* 0x1253: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1256:
	/* 0x1256: mulx   rcx,rcx,rcx */
	X86_SIM_L_EXEC_MULX(X86_RCX, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_125b:
	/* 0x125b: shr    rcx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_125f:
	/* 0x125f: add    r14d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1262:
	/* 0x1262: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1267:
	/* 0x1267: mov    DWORD PTR [rax+0x20],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_126b:
	/* 0x126b: movzx  edx,BYTE PTR [rax+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_126f:
	/* 0x126f: mov    esi,DWORD PTR [rax+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1272:
	/* 0x1272: mov    r8d,DWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1277:
	/* 0x1277: and    r8b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_127b:
	/* 0x127b: mov    rdi,QWORD PTR [rip+0x23ca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1282:
	/* 0x1282: cmp    BYTE PTR [rdi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1285:
	/* 0x1285: je     1298 <tail_nodeport_nat_ingress_ipv4+0x1298> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1285, 0x1298, x86_l_1298);
x86_l_1287:
	/* 0x1287: mov    rdi,QWORD PTR [rip+0x23ca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_128e:
	/* 0x128e: mov    edi,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1290:
	/* 0x1290: lea    edi,[rdi+rdi*4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_1293:
	/* 0x1293: shr    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1296:
	/* 0x1296: jmp    129d <tail_nodeport_nat_ingress_ipv4+0x129d> */
	X86_SIM_X86_JMP(0x1296, 0x129d, x86_l_129d);
x86_l_1298:
	/* 0x1298: mov    edi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 5ULL);
x86_l_129d:
	/* 0x129d: mov    r14d,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_12a2:
	/* 0x12a2: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_12a4:
	/* 0x12a4: or     r8b,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_12a7:
	/* 0x12a7: cmp    edi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RCX, X86_WIDTH_32);
x86_l_12a9:
	/* 0x12a9: jb     12b0 <tail_nodeport_nat_ingress_ipv4+0x12b0> */
	X86_SIM_X86_JCC(X86_CC_B, 0x12a9, 0x12b0, x86_l_12b0);
x86_l_12ab:
	/* 0x12ab: cmp    dl,r8b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R8, X86_WIDTH_8);
x86_l_12ae:
	/* 0x12ae: je     12c0 <tail_nodeport_nat_ingress_ipv4+0x12c0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12ae, 0x12c0, x86_l_12c0);
x86_l_12b0:
	/* 0x12b0: mov    BYTE PTR [rax+0x2b],r8b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R8, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_12b4:
	/* 0x12b4: mov    DWORD PTR [rax+0x34],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_12b7:
	/* 0x12b7: mov    rcx,QWORD PTR [rip+0x23ca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_12be:
	/* 0x12be: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12c0:
	/* 0x12c0: mov    rcx,QWORD PTR [rip+0x23ca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_12c7:
	/* 0x12c7: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12ca:
	/* 0x12ca: je     12dd <tail_nodeport_nat_ingress_ipv4+0x12dd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12ca, 0x12dd, x86_l_12dd);
x86_l_12cc:
	/* 0x12cc: inc QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 16ULL);
x86_l_12d1:
	/* 0x12d1: mov    rcx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12d5:
	/* 0x12d5: sub    rcx,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 0ULL);
x86_l_12d8:
	/* 0x12d8: add QWORD PTR [rax+0x18],rcx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_12dd:
	/* 0x12dd: cmp    r15d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 2ULL);
x86_l_12e1:
	/* 0x12e1: je     1335 <tail_nodeport_nat_ingress_ipv4+0x1335> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12e1, 0x1335, x86_l_1335);
x86_l_12e3:
	/* 0x12e3: cmp    r15d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 1ULL);
x86_l_12e7:
	/* 0x12e7: jne    1622 <tail_nodeport_nat_ingress_ipv4+0x1622> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x12e7, 0x1622, x86_l_1622);
x86_l_12ed:
	/* 0x12ed: movzx  ecx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_12f1:
	/* 0x12f1: test   cl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_12f4:
	/* 0x12f4: je     1622 <tail_nodeport_nat_ingress_ipv4+0x1622> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12f4, 0x1622, x86_l_1622);
x86_l_12fa:
	/* 0x12fa: mov    edx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_32);
x86_l_12fd:
	/* 0x12fd: mov    WORD PTR [rax+0x2a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 180388626432ULL);
x86_l_1303:
	/* 0x1303: and    ecx,0xffec */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 65516ULL);
x86_l_1309:
	/* 0x1309: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_130c:
	/* 0x130c: mov    WORD PTR [rax+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1310:
	/* 0x1310: mov    r15,QWORD PTR [rip+0x23ca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1317:
	/* 0x1317: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_131b:
	/* 0x131b: je     1ddc <tail_nodeport_nat_ingress_ipv4+0x1ddc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x131b, 0x1ddc, x86_l_1ddc);
x86_l_1321:
	/* 0x1321: mov    rax,QWORD PTR [rip+0x23ca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1328:
	/* 0x1328: imul   r13d,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_132c:
	/* 0x132c: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1330:
	/* 0x1330: jmp    1de2 <tail_nodeport_nat_ingress_ipv4+0x1de2> */
	X86_SIM_X86_JMP(0x1330, 0x1de2, x86_l_1de2);
x86_l_1335:
	/* 0x1335: mov    ecx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_32);
x86_l_1338:
	/* 0x1338: shr    ecx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_133b:
	/* 0x133b: and    ecx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2ULL);
x86_l_133e:
	/* 0x133e: or     cx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RAX, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 36ULL);
x86_l_1342:
	/* 0x1342: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_1344:
	/* 0x1344: or     edx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_OR, 1ULL);
x86_l_1347:
	/* 0x1347: mov    WORD PTR [rax+0x24],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_134b:
	/* 0x134b: mov    rdx,QWORD PTR [rip+0x23ca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_1352:
	/* 0x1352: mov    edx,DWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1354:
	/* 0x1354: test   cl,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_1357:
	/* 0x1357: je     1622 <tail_nodeport_nat_ingress_ipv4+0x1622> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1357, 0x1622, x86_l_1622);
x86_l_135d:
	/* 0x135d: mov    ecx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_32);
x86_l_1360:
	/* 0x1360: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_1363:
	/* 0x1363: mov    rax,QWORD PTR [rip+0x23ca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_136a:
	/* 0x136a: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_136d:
	/* 0x136d: je     1579 <tail_nodeport_nat_ingress_ipv4+0x1579> */
	X86_SIM_X86_JCC(X86_CC_E, 0x136d, 0x1579, x86_l_1579);
x86_l_1373:
	/* 0x1373: mov    rax,QWORD PTR [rip+0x23ca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_137a:
	/* 0x137a: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_137c:
	/* 0x137c: add    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_137e:
	/* 0x137e: lea    r12d,[rax+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_1382:
	/* 0x1382: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1386:
	/* 0x1386: jmp    157f <tail_nodeport_nat_ingress_ipv4+0x157f> */
	X86_SIM_X86_JMP(0x1386, 0x157f, x86_l_157f);
x86_l_138b:
	/* 0x138b: mov    r15,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R8, X86_WIDTH_64);
x86_l_138e:
	/* 0x138e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1393:
	/* 0x1393: mov    rdi,QWORD PTR [rip+0x23ca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv4_frag_datagrams)));
x86_l_139a:
	/* 0x139a: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_139f:
	/* 0x139f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13a1:
	/* 0x13a1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13a4:
	/* 0x13a4: je     156f <tail_nodeport_nat_ingress_ipv4+0x156f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13a4, 0x156f, x86_l_156f);
x86_l_13aa:
	/* 0x13aa: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13ac:
	/* 0x13ac: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13b0:
	/* 0x13b0: mov    r8,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R15, X86_WIDTH_64);
x86_l_13b3:
	/* 0x13b3: jmp    2c7 <tail_nodeport_nat_ingress_ipv4+0x2c7> */
	X86_SIM_X86_JMP(0x13b3, 0x2c7, x86_l_2c7);
x86_l_13b8:
	/* 0x13b8: mov    ebp,0xffffff63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967139ULL);
x86_l_13bd:
	/* 0x13bd: jmp    6f <tail_nodeport_nat_ingress_ipv4+0x6f> */
	X86_SIM_X86_JMP(0x13bd, 0x6f, x86_l_6f);
x86_l_13c2:
	/* 0x13c2: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13c7:
	/* 0x13c7: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_13cc:
	/* 0x13cc: mov    rdi,QWORD PTR [rip+0x23ca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv4_frag_datagrams)));
x86_l_13d3:
	/* 0x13d3: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_13d8:
	/* 0x13d8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13da:
	/* 0x13da: mov    rbp,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R8, X86_WIDTH_64);
x86_l_13dd:
	/* 0x13dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13df:
	/* 0x13df: mov    r8,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RBP, X86_WIDTH_64);
x86_l_13e2:
	/* 0x13e2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_13e4:
	/* 0x13e4: je     2c7 <tail_nodeport_nat_ingress_ipv4+0x2c7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13e4, 0x2c7, x86_l_2c7);
x86_l_13ea:
	/* 0x13ea: mov    r15,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13ee:
	/* 0x13ee: sub    r15,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 0ULL);
x86_l_13f1:
	/* 0x13f1: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_13fa:
	/* 0x13fa: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_1403:
	/* 0x1403: movabs rax,0x6b0085010a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 459570217226ULL);
x86_l_140d:
	/* 0x140d: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1412:
	/* 0x1412: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1417:
	/* 0x1417: mov    rdi,QWORD PTR [rip+0x23ca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_141e:
	/* 0x141e: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1423:
	/* 0x1423: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1425:
	/* 0x1425: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1428:
	/* 0x1428: je     173e <tail_nodeport_nat_ingress_ipv4+0x173e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1428, 0x173e, x86_l_173e);
x86_l_142e:
	/* 0x142e: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1431:
	/* 0x1431: add    QWORD PTR [rax+0x8],r15 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1435:
	/* 0x1435: mov    r8,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RBP, X86_WIDTH_64);
x86_l_1438:
	/* 0x1438: jmp    2c7 <tail_nodeport_nat_ingress_ipv4+0x2c7> */
	X86_SIM_X86_JMP(0x1438, 0x2c7, x86_l_2c7);
x86_l_143d:
	/* 0x143d: mov    r15w,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_16, 6ULL);
x86_l_1442:
	/* 0x1442: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1445:
	/* 0x1445: jmp    1451 <tail_nodeport_nat_ingress_ipv4+0x1451> */
	X86_SIM_X86_JMP(0x1445, 0x1451, x86_l_1451);
x86_l_1447:
	/* 0x1447: mov    r15w,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_16, 2ULL);
x86_l_144c:
	/* 0x144c: jmp    1451 <tail_nodeport_nat_ingress_ipv4+0x1451> */
	X86_SIM_X86_JMP(0x144c, 0x1451, x86_l_1451);
x86_l_144e:
	/* 0x144e: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1451:
	/* 0x1451: cmp    r11w,r14w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R11, X86_R14, X86_WIDTH_16);
x86_l_1455:
	/* 0x1455: jne    14e1 <tail_nodeport_nat_ingress_ipv4+0x14e1> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1455, 0x14e1, x86_l_14e1);
x86_l_145b:
	/* 0x145b: test   r15w,r15w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_16);
x86_l_145f:
	/* 0x145f: je     cd0 <tail_nodeport_nat_ingress_ipv4+0xcd0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x145f, 0xcd0, x86_l_cd0);
x86_l_1465:
	/* 0x1465: movzx  edi,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDI, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1469:
	/* 0x1469: mov    ecx,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_146d:
	/* 0x146d: mov    r11,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1475:
	/* 0x1475: add    r11,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_RDI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1478:
	/* 0x1478: lea    rdi,[rcx+r11*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R11, 0), 0ULL);
x86_l_147c:
	/* 0x147c: add    rdi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_1480:
	/* 0x1480: cmp    rdi,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 184ULL);
x86_l_1488:
	/* 0x1488: ja     155a <tail_nodeport_nat_ingress_ipv4+0x155a> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1488, 0x155a, x86_l_155a);
x86_l_148e:
	/* 0x148e: mov    r9,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_R11, X86_WIDTH_64);
x86_l_1491:
	/* 0x1491: add    r9,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1494:
	/* 0x1494: movzx  ecx,WORD PTR [r9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R9, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1498:
	/* 0x1498: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_149a:
	/* 0x149a: setne  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_NE);
x86_l_149e:
	/* 0x149e: or     sil,r8b */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R8, X86_WIDTH_8, X86_ALU_OR);
x86_l_14a1:
	/* 0x14a1: cmp    sil,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_8, 1ULL);
x86_l_14a5:
	/* 0x14a5: jne    cd0 <tail_nodeport_nat_ingress_ipv4+0xcd0> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x14a5, 0xcd0, x86_l_cd0);
x86_l_14ab:
	/* 0x14ab: mov    rdi,r9 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R9, X86_WIDTH_64);
x86_l_14ae:
	/* 0x14ae: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_14b0:
	/* 0x14b0: add    edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_14b2:
	/* 0x14b2: adc    edx,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_14b5:
	/* 0x14b5: movzx  ecx,dx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RDX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_14b8:
	/* 0x14b8: shr    edx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_14bb:
	/* 0x14bb: add    edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_14bd:
	/* 0x14bd: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_14bf:
	/* 0x14bf: shr    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_14c2:
	/* 0x14c2: add    ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_14c4:
	/* 0x14c4: cmp    cx,0xffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 65535ULL);
x86_l_14c8:
	/* 0x14c8: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_14ca:
	/* 0x14ca: mov    edx,0xffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 65535ULL);
x86_l_14cf:
	/* 0x14cf: cmovne edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_NE);
x86_l_14d2:
	/* 0x14d2: test   r8b,r8b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R8, X86_R8, X86_WIDTH_8);
x86_l_14d5:
	/* 0x14d5: cmovne edx,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_32, X86_CC_NE);
x86_l_14d8:
	/* 0x14d8: mov    WORD PTR [r9],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R9, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14dc:
	/* 0x14dc: jmp    cd0 <tail_nodeport_nat_ingress_ipv4+0xcd0> */
	X86_SIM_X86_JMP(0x14dc, 0xcd0, x86_l_cd0);
x86_l_14e1:
	/* 0x14e1: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_14e4:
	/* 0x14e4: je     14fe <tail_nodeport_nat_ingress_ipv4+0x14fe> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14e4, 0x14fe, x86_l_14fe);
x86_l_14e6:
	/* 0x14e6: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_14e9:
	/* 0x14e9: je     14fe <tail_nodeport_nat_ingress_ipv4+0x14fe> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14e9, 0x14fe, x86_l_14fe);
x86_l_14eb:
	/* 0x14eb: mov    ebp,0xffffff72 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967154ULL);
x86_l_14f0:
	/* 0x14f0: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_14f3:
	/* 0x14f3: jne    6f <tail_nodeport_nat_ingress_ipv4+0x6f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x14f3, 0x6f, x86_l_6f);
x86_l_14f9:
	/* 0x14f9: mov    r15w,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_16, 2ULL);
x86_l_14fe:
	/* 0x14fe: mov    rbp,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1503:
	/* 0x1503: add    ebp,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_1507:
	/* 0x1507: mov    rdi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_150f:
	/* 0x150f: mov    r9,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RBP, X86_WIDTH_64);
x86_l_1512:
	/* 0x1512: add    rdi,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1515:
	/* 0x1515: add    rdi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_1519:
	/* 0x1519: mov    ebp,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967155ULL);
x86_l_151e:
	/* 0x151e: mov    rsi,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1526:
	/* 0x1526: cmp    rdi,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_64);
x86_l_1529:
	/* 0x1529: ja     6f <tail_nodeport_nat_ingress_ipv4+0x6f> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1529, 0x6f, x86_l_6f);
x86_l_152f:
	/* 0x152f: mov    rdi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1537:
	/* 0x1537: add    r9,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_RDI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_153a:
	/* 0x153a: mov    WORD PTR [r9],r14w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R9, X86_R14, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_153e:
	/* 0x153e: movzx  r14d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1542:
	/* 0x1542: mov    ebp,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1546:
	/* 0x1546: add    r14,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RDI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1549:
	/* 0x1549: lea    rdi,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_154d:
	/* 0x154d: add    rdi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_1551:
	/* 0x1551: cmp    rdi,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_64);
x86_l_1554:
	/* 0x1554: jbe    1706 <tail_nodeport_nat_ingress_ipv4+0x1706> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x1554, 0x1706, x86_l_1706);
x86_l_155a:
	/* 0x155a: mov    ebp,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967142ULL);
x86_l_155f:
	/* 0x155f: cmp    BYTE PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_1564:
	/* 0x1564: jne    6f <tail_nodeport_nat_ingress_ipv4+0x6f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1564, 0x6f, x86_l_6f);
x86_l_156a:
	/* 0x156a: jmp    cd0 <tail_nodeport_nat_ingress_ipv4+0xcd0> */
	X86_SIM_X86_JMP(0x156a, 0xcd0, x86_l_cd0);
x86_l_156f:
	/* 0x156f: mov    ebp,0xffffff51 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967121ULL);
x86_l_1574:
	/* 0x1574: jmp    6f <tail_nodeport_nat_ingress_ipv4+0x6f> */
	X86_SIM_X86_JMP(0x1574, 0x6f, x86_l_6f);
x86_l_1579:
	/* 0x1579: mov    r12d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 10ULL);
x86_l_157f:
	/* 0x157f: movzx  r15d,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1583:
	/* 0x1583: shr    r15d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1587:
	/* 0x1587: mov    rax,QWORD PTR [rip+0x23ca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_158e:
	/* 0x158e: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1591:
	/* 0x1591: je     15a5 <tail_nodeport_nat_ingress_ipv4+0x15a5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1591, 0x15a5, x86_l_15a5);
x86_l_1593:
	/* 0x1593: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_1598:
	/* 0x1598: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_159a:
	/* 0x159a: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_159c:
	/* 0x159c: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_159f:
	/* 0x159f: shr    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_15a3:
	/* 0x15a3: jmp    15c8 <tail_nodeport_nat_ingress_ipv4+0x15c8> */
	X86_SIM_X86_JMP(0x15a3, 0x15c8, x86_l_15c8);
x86_l_15a5:
	/* 0x15a5: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_15aa:
	/* 0x15aa: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15ac:
	/* 0x15ac: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_15ae:
	/* 0x15ae: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_15b2:
	/* 0x15b2: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_15bc:
	/* 0x15bc: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_15bf:
	/* 0x15bf: mulx   rcx,rcx,rcx */
	X86_SIM_L_EXEC_MULX(X86_RCX, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_15c4:
	/* 0x15c4: shr    rcx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_15c8:
	/* 0x15c8: add    r12d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_15cb:
	/* 0x15cb: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_15ce:
	/* 0x15ce: mov    DWORD PTR [r14+0x20],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_15d2:
	/* 0x15d2: movzx  edx,BYTE PTR [r14+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_15d7:
	/* 0x15d7: mov    eax,DWORD PTR [r14+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_15db:
	/* 0x15db: and    r15b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_15df:
	/* 0x15df: mov    rsi,QWORD PTR [rip+0x23ca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_15e6:
	/* 0x15e6: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15e9:
	/* 0x15e9: je     15fc <tail_nodeport_nat_ingress_ipv4+0x15fc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x15e9, 0x15fc, x86_l_15fc);
x86_l_15eb:
	/* 0x15eb: mov    rsi,QWORD PTR [rip+0x23ca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_15f2:
	/* 0x15f2: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15f4:
	/* 0x15f4: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_15f7:
	/* 0x15f7: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_15fa:
	/* 0x15fa: jmp    1601 <tail_nodeport_nat_ingress_ipv4+0x1601> */
	X86_SIM_X86_JMP(0x15fa, 0x1601, x86_l_1601);
x86_l_15fc:
	/* 0x15fc: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_1601:
	/* 0x1601: add    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1603:
	/* 0x1603: or     r15b,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_1606:
	/* 0x1606: cmp    esi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_1608:
	/* 0x1608: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_160b:
	/* 0x160b: jb     1612 <tail_nodeport_nat_ingress_ipv4+0x1612> */
	X86_SIM_X86_JCC(X86_CC_B, 0x160b, 0x1612, x86_l_1612);
x86_l_160d:
	/* 0x160d: cmp    dl,r15b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_8);
x86_l_1610:
	/* 0x1610: je     1622 <tail_nodeport_nat_ingress_ipv4+0x1622> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1610, 0x1622, x86_l_1622);
x86_l_1612:
	/* 0x1612: mov    BYTE PTR [rax+0x2b],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_1616:
	/* 0x1616: mov    DWORD PTR [rax+0x34],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1619:
	/* 0x1619: mov    rcx,QWORD PTR [rip+0x23ca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_1620:
	/* 0x1620: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1622:
	/* 0x1622: test   BYTE PTR [rsp+0x15],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 90194313218ULL);
x86_l_1627:
	/* 0x1627: jne    1eb1 <tail_nodeport_nat_ingress_ipv4+0x1eb1> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1627, 0x1eb1, x86_l_1eb1);
x86_l_162d:
	/* 0x162d: movzx  eax,WORD PTR [rax+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_1631:
	/* 0x1631: mov    WORD PTR [rsp+0x18],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1636:
	/* 0x1636: mov    r14,QWORD PTR [rip+0x23ca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_163d:
	/* 0x163d: movzx  eax,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1641:
	/* 0x1641: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1646:
	/* 0x1646: mov    rdi,QWORD PTR [rip+0x23ca] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_reverse_nat)));
x86_l_164d:
	/* 0x164d: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1652:
	/* 0x1652: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1654:
	/* 0x1654: mov    r12,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1657:
	/* 0x1657: mov    rcx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_165b:
	/* 0x165b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_165e:
	/* 0x165e: je     17dc <tail_nodeport_nat_ingress_ipv4+0x17dc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x165e, 0x17dc, x86_l_17dc);
x86_l_1664:
	/* 0x1664: mov    edx,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1668:
	/* 0x1668: movzx  esi,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_166c:
	/* 0x166c: mov    esi,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_166e:
	/* 0x166e: mov    DWORD PTR [rsp+0xc],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1672:
	/* 0x1672: lea    rsi,[r12+0x1e] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_1677:
	/* 0x1677: cmp    rsi,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_64);
x86_l_167a:
	/* 0x167a: jbe    168a <tail_nodeport_nat_ingress_ipv4+0x168a> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x167a, 0x168a, x86_l_168a);
x86_l_167c:
	/* 0x167c: mov    r15d,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967155ULL);
x86_l_1682:
	/* 0x1682: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1685:
	/* 0x1685: jmp    f4c <tail_nodeport_nat_ingress_ipv4+0xf4c> */
	X86_SIM_X86_JMP(0x1685, 0xf4c, x86_l_f4c);
x86_l_168a:
	/* 0x168a: mov    esi,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_168c:
	/* 0x168c: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_168e:
	/* 0x168e: add    edx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1690:
	/* 0x1690: adc    edx,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_1693:
	/* 0x1693: movzx  edi,WORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 24ULL);
x86_l_1699:
	/* 0x1699: not    edi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_169b:
	/* 0x169b: add    edi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_169d:
	/* 0x169d: adc    edi,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_16a0:
	/* 0x16a0: movzx  r8d,di */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_RDI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_16a4:
	/* 0x16a4: shr    edi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_16a7:
	/* 0x16a7: add    edi,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R8, X86_WIDTH_32, X86_ALU_ADD);
x86_l_16aa:
	/* 0x16aa: mov    r8d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RDI, X86_WIDTH_32);
x86_l_16ad:
	/* 0x16ad: shr    r8d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_16b1:
	/* 0x16b1: add    r8d,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_16b4:
	/* 0x16b4: mov    DWORD PTR [r12+0x1a],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_16b9:
	/* 0x16b9: not    r8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_16bc:
	/* 0x16bc: mov    WORD PTR [r12+0x18],r8w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R8, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_16c2:
	/* 0x16c2: movabs rsi,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 2199023255552ULL);
x86_l_16cc:
	/* 0x16cc: test   r13,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_RSI, X86_WIDTH_64);
x86_l_16cf:
	/* 0x16cf: jne    17dc <tail_nodeport_nat_ingress_ipv4+0x17dc> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x16cf, 0x17dc, x86_l_17dc);
x86_l_16d5:
	/* 0x16d5: movzx  r11d,BYTE PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 20ULL);
x86_l_16db:
	/* 0x16db: mov    sil,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_8, 1ULL);
x86_l_16de:
	/* 0x16de: cmp    r11d,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 58ULL);
x86_l_16e2:
	/* 0x16e2: je     177e <tail_nodeport_nat_ingress_ipv4+0x177e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x16e2, 0x177e, x86_l_177e);
x86_l_16e8:
	/* 0x16e8: cmp    r11d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 17ULL);
x86_l_16ec:
	/* 0x16ec: je     1775 <tail_nodeport_nat_ingress_ipv4+0x1775> */
	X86_SIM_X86_JCC(X86_CC_E, 0x16ec, 0x1775, x86_l_1775);
x86_l_16f2:
	/* 0x16f2: cmp    r11d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 6ULL);
x86_l_16f6:
	/* 0x16f6: jne    1788 <tail_nodeport_nat_ingress_ipv4+0x1788> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x16f6, 0x1788, x86_l_1788);
x86_l_16fc:
	/* 0x16fc: mov    edi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 16ULL);
x86_l_1701:
	/* 0x1701: jmp    1783 <tail_nodeport_nat_ingress_ipv4+0x1783> */
	X86_SIM_X86_JMP(0x1701, 0x1783, x86_l_1783);
x86_l_1706:
	/* 0x1706: add    r14,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1709:
	/* 0x1709: test   r8b,r8b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R8, X86_R8, X86_WIDTH_8);
x86_l_170c:
	/* 0x170c: jne    1719 <tail_nodeport_nat_ingress_ipv4+0x1719> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x170c, 0x1719, x86_l_1719);
x86_l_170e:
	/* 0x170e: cmp    WORD PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1713:
	/* 0x1713: je     1ab0 <tail_nodeport_nat_ingress_ipv4+0x1ab0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1713, 0x1ab0, x86_l_1ab0);
x86_l_1719:
	/* 0x1719: test   r11d,r11d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R11, X86_R11, X86_WIDTH_32);
x86_l_171c:
	/* 0x171c: je     1a69 <tail_nodeport_nat_ingress_ipv4+0x1a69> */
	X86_SIM_X86_JCC(X86_CC_E, 0x171c, 0x1a69, x86_l_1a69);
x86_l_1722:
	/* 0x1722: not    r11d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1725:
	/* 0x1725: mov    esi,DWORD PTR [rsp+0x3c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_1729:
	/* 0x1729: add    esi,r11d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R11, X86_WIDTH_32, X86_ALU_ADD);
x86_l_172c:
	/* 0x172c: adc    esi,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_172f:
	/* 0x172f: movzx  r11d,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1733:
	/* 0x1733: not    r11d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1736:
	/* 0x1736: add    r11d,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1739:
	/* 0x1739: jmp    1a75 <tail_nodeport_nat_ingress_ipv4+0x1a75> */
	X86_SIM_X86_JMP(0x1739, 0x1a75, x86_l_1a75);
x86_l_173e:
	/* 0x173e: mov    QWORD PTR [rsp+0x60],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860417ULL);
x86_l_1747:
	/* 0x1747: mov    QWORD PTR [rsp+0x68],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_174c:
	/* 0x174c: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1751:
	/* 0x1751: mov    rdi,QWORD PTR [rip+0x23c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1758:
	/* 0x1758: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_175d:
	/* 0x175d: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1762:
	/* 0x1762: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1764:
	/* 0x1764: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1766:
	/* 0x1766: mov    r8,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RBP, X86_WIDTH_64);
x86_l_1769:
	/* 0x1769: jmp    2c7 <tail_nodeport_nat_ingress_ipv4+0x2c7> */
	X86_SIM_X86_JMP(0x1769, 0x2c7, x86_l_2c7);
x86_l_176e:
	/* 0x176e: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1770:
	/* 0x1770: jmp    e7f <tail_nodeport_nat_ingress_ipv4+0xe7f> */
	X86_SIM_X86_JMP(0x1770, 0xe7f, x86_l_e7f);
x86_l_1775:
	/* 0x1775: mov    edi,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 6ULL);
x86_l_177a:
	/* 0x177a: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_177c:
	/* 0x177c: jmp    1783 <tail_nodeport_nat_ingress_ipv4+0x1783> */
	X86_SIM_X86_JMP(0x177c, 0x1783, x86_l_1783);
x86_l_177e:
	/* 0x177e: mov    edi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 2ULL);
x86_l_1783:
	/* 0x1783: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1786:
	/* 0x1786: jmp    178d <tail_nodeport_nat_ingress_ipv4+0x178d> */
	X86_SIM_X86_JMP(0x1786, 0x178d, x86_l_178d);
x86_l_1788:
	/* 0x1788: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_178a:
	/* 0x178a: mov    r8b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_8, 1ULL);
x86_l_178d:
	/* 0x178d: movzx  r9d,WORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_1792:
	/* 0x1792: test   r9d,r9d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R9, X86_R9, X86_WIDTH_32);
x86_l_1795:
	/* 0x1795: je     17d3 <tail_nodeport_nat_ingress_ipv4+0x17d3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1795, 0x17d3, x86_l_17d3);
x86_l_1797:
	/* 0x1797: movzx  r10d,WORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_179d:
	/* 0x179d: mov    ebp,0xffffff72 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967154ULL);
x86_l_17a2:
	/* 0x17a2: cmp    r11d,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 16ULL);
x86_l_17a6:
	/* 0x17a6: jg     17b9 <tail_nodeport_nat_ingress_ipv4+0x17b9> */
	X86_SIM_X86_JCC(X86_CC_G, 0x17a6, 0x17b9, x86_l_17b9);
x86_l_17a8:
	/* 0x17a8: cmp    r11d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 1ULL);
x86_l_17ac:
	/* 0x17ac: je     17d3 <tail_nodeport_nat_ingress_ipv4+0x17d3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x17ac, 0x17d3, x86_l_17d3);
x86_l_17ae:
	/* 0x17ae: cmp    r11d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 6ULL);
x86_l_17b2:
	/* 0x17b2: je     17c9 <tail_nodeport_nat_ingress_ipv4+0x17c9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x17b2, 0x17c9, x86_l_17c9);
x86_l_17b4:
	/* 0x17b4: jmp    1a61 <tail_nodeport_nat_ingress_ipv4+0x1a61> */
	X86_SIM_X86_JMP(0x17b4, 0x1a61, x86_l_1a61);
x86_l_17b9:
	/* 0x17b9: cmp    r11d,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 58ULL);
x86_l_17bd:
	/* 0x17bd: je     17d3 <tail_nodeport_nat_ingress_ipv4+0x17d3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x17bd, 0x17d3, x86_l_17d3);
x86_l_17bf:
	/* 0x17bf: cmp    r11d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 17ULL);
x86_l_17c3:
	/* 0x17c3: jne    1a61 <tail_nodeport_nat_ingress_ipv4+0x1a61> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x17c3, 0x1a61, x86_l_1a61);
x86_l_17c9:
	/* 0x17c9: cmp    r9w,r10w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R9, X86_R10, X86_WIDTH_16);
x86_l_17cd:
	/* 0x17cd: jne    1a27 <tail_nodeport_nat_ingress_ipv4+0x1a27> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x17cd, 0x1a27, x86_l_1a27);
x86_l_17d3:
	/* 0x17d3: test   r8b,r8b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R8, X86_R8, X86_WIDTH_8);
x86_l_17d6:
	/* 0x17d6: je     19b7 <tail_nodeport_nat_ingress_ipv4+0x19b7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x17d6, 0x19b7, x86_l_19b7);
x86_l_17dc:
	/* 0x17dc: lea    rax,[r12+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_17e1:
	/* 0x17e1: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17e4:
	/* 0x17e4: mov    r15d,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967162ULL);
x86_l_17ea:
	/* 0x17ea: cmp    rax,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_17ed:
	/* 0x17ed: ja     f4c <tail_nodeport_nat_ingress_ipv4+0xf4c> */
	X86_SIM_X86_JCC(X86_CC_A, 0x17ed, 0xf4c, x86_l_f4c);
x86_l_17f3:
	/* 0x17f3: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_17fb:
	/* 0x17fb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1800:
	/* 0x1800: mov    rdi,QWORD PTR [rip+0x23c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_1807:
	/* 0x1807: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_180c:
	/* 0x180c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_180e:
	/* 0x180e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1811:
	/* 0x1811: je     1dd5 <tail_nodeport_nat_ingress_ipv4+0x1dd5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1811, 0x1dd5, x86_l_1dd5);
x86_l_1817:
	/* 0x1817: mov    ebp,DWORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_181a:
	/* 0x181a: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1822:
	/* 0x1822: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1827:
	/* 0x1827: mov    rdi,QWORD PTR [rip+0x23c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_182e:
	/* 0x182e: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1833:
	/* 0x1833: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1835:
	/* 0x1835: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1838:
	/* 0x1838: je     1840 <tail_nodeport_nat_ingress_ipv4+0x1840> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1838, 0x1840, x86_l_1840);
x86_l_183a:
	/* 0x183a: or     ebp,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_OR, 4ULL);
x86_l_183d:
	/* 0x183d: mov    DWORD PTR [rax+0x18],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1840:
	/* 0x1840: mov    eax,DWORD PTR [r12+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_1845:
	/* 0x1845: mov    DWORD PTR [rsp+0x70],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1849:
	/* 0x1849: mov    eax,DWORD PTR [r12+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_184e:
	/* 0x184e: mov    DWORD PTR [rsp+0x80],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1855:
	/* 0x1855: movzx  ecx,BYTE PTR [r12+0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 22ULL);
x86_l_185b:
	/* 0x185b: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_185e:
	/* 0x185e: mov    r15d,0xffffff3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967100ULL);
x86_l_1864:
	/* 0x1864: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1867:
	/* 0x1867: jb     f4c <tail_nodeport_nat_ingress_ipv4+0xf4c> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1867, 0xf4c, x86_l_f4c);
x86_l_186d:
	/* 0x186d: lea    edx,[rcx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_1870:
	/* 0x1870: mov    BYTE PTR [r12+0x16],dl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_1875:
	/* 0x1875: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1878:
	/* 0x1878: lea    rsi,[rax+0x1a] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_187c:
	/* 0x187c: mov    r15d,0xffffff67 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967143ULL);
x86_l_1882:
	/* 0x1882: cmp    rsi,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_1886:
	/* 0x1886: ja     f4c <tail_nodeport_nat_ingress_ipv4+0xf4c> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1886, 0xf4c, x86_l_f4c);
x86_l_188c:
	/* 0x188c: movzx  edx,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_188f:
	/* 0x188f: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1891:
	/* 0x1891: add    ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1893:
	/* 0x1893: adc    ecx,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_1896:
	/* 0x1896: movzx  edx,WORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 24ULL);
x86_l_189a:
	/* 0x189a: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_189c:
	/* 0x189c: add    edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_189e:
	/* 0x189e: adc    edx,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_18a1:
	/* 0x18a1: movzx  ecx,dx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RDX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_18a4:
	/* 0x18a4: shr    edx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_18a7:
	/* 0x18a7: add    edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_18a9:
	/* 0x18a9: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_18ab:
	/* 0x18ab: shr    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_18ae:
	/* 0x18ae: add    ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_18b0:
	/* 0x18b0: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_18b2:
	/* 0x18b2: mov    WORD PTR [rax+0x18],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_18b6:
	/* 0x18b6: mov    eax,0x45 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 69ULL);
x86_l_18bb:
	/* 0x18bb: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_18c0:
	/* 0x18c0: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_18c3:
	/* 0x18c3: mov    edx,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 64ULL);
x86_l_18c8:
	/* 0x18c8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18ca:
	/* 0x18ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18cc:
	/* 0x18cc: mov    r14d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_32);
x86_l_18cf:
	/* 0x18cf: mov    r15d,0xffffff57 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967127ULL);
x86_l_18d5:
	/* 0x18d5: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_18d8:
	/* 0x18d8: je     18e3 <tail_nodeport_nat_ingress_ipv4+0x18e3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x18d8, 0x18e3, x86_l_18e3);
x86_l_18da:
	/* 0x18da: test   r14d,r14d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_32);
x86_l_18dd:
	/* 0x18dd: jne    f4c <tail_nodeport_nat_ingress_ipv4+0xf4c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x18dd, 0xf4c, x86_l_f4c);
x86_l_18e3:
	/* 0x18e3: mov    ebp,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_18e7:
	/* 0x18e7: mov    DWORD PTR [rsp+0x18],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_18eb:
	/* 0x18eb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_18f0:
	/* 0x18f0: mov    rdi,QWORD PTR [rip+0x23c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_devices)));
x86_l_18f7:
	/* 0x18f7: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_18fc:
	/* 0x18fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18fe:
	/* 0x18fe: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1901:
	/* 0x1901: je     190d <tail_nodeport_nat_ingress_ipv4+0x190d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1901, 0x190d, x86_l_190d);
x86_l_1903:
	/* 0x1903: test   BYTE PTR [rax+0x8],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_1907:
	/* 0x1907: jne    1b1f <tail_nodeport_nat_ingress_ipv4+0x1b1f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1907, 0x1b1f, x86_l_1b1f);
x86_l_190d:
	/* 0x190d: test   r14d,r14d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_32);
x86_l_1910:
	/* 0x1910: je     1ac9 <tail_nodeport_nat_ingress_ipv4+0x1ac9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1910, 0x1ac9, x86_l_1ac9);
x86_l_1916:
	/* 0x1916: mov    DWORD PTR [rsp+0x18],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_191a:
	/* 0x191a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_191f:
	/* 0x191f: mov    rdi,QWORD PTR [rip+0x23c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_devices)));
x86_l_1926:
	/* 0x1926: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_192b:
	/* 0x192b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_192d:
	/* 0x192d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1930:
	/* 0x1930: lea    r12,[rip+0x23c7] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 9159ULL);
x86_l_1937:
	/* 0x1937: cmovne r12,rax */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RAX, X86_WIDTH_64, X86_CC_NE);
x86_l_193b:
	/* 0x193b: mov    r14d,0x64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 100ULL);
x86_l_1941:
	/* 0x1941: cmp    BYTE PTR [rsp+0x60],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 412316860418ULL);
x86_l_1946:
	/* 0x1946: jne    f4c <tail_nodeport_nat_ingress_ipv4+0xf4c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1946, 0xf4c, x86_l_f4c);
x86_l_194c:
	/* 0x194c: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1954:
	/* 0x1954: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1959:
	/* 0x1959: mov    rdi,QWORD PTR [rip+0x23c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_nodeport_neigh4)));
x86_l_1960:
	/* 0x1960: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1962:
	/* 0x1962: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1965:
	/* 0x1965: je     f4c <tail_nodeport_nat_ingress_ipv4+0xf4c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1965, 0xf4c, x86_l_f4c);
x86_l_196b:
	/* 0x196b: mov    rcx,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_196e:
	/* 0x196e: mov    rdx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1972:
	/* 0x1972: lea    rsi,[rcx+0x6] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_1976:
	/* 0x1976: mov    r15d,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967155ULL);
x86_l_197c:
	/* 0x197c: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_197f:
	/* 0x197f: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_1982:
	/* 0x1982: ja     f4c <tail_nodeport_nat_ingress_ipv4+0xf4c> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1982, 0xf4c, x86_l_f4c);
x86_l_1988:
	/* 0x1988: movzx  esi,WORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_198c:
	/* 0x198c: mov    WORD PTR [rcx+0x4],si */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RSI, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1990:
	/* 0x1990: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1992:
	/* 0x1992: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1994:
	/* 0x1994: lea    rax,[rcx+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1998:
	/* 0x1998: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_199b:
	/* 0x199b: ja     f4c <tail_nodeport_nat_ingress_ipv4+0xf4c> */
	X86_SIM_X86_JCC(X86_CC_A, 0x199b, 0xf4c, x86_l_f4c);
x86_l_19a1:
	/* 0x19a1: movzx  eax,WORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_19a7:
	/* 0x19a7: mov    WORD PTR [rcx+0xa],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 10ULL);
x86_l_19ab:
	/* 0x19ab: mov    eax,DWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19af:
	/* 0x19af: mov    DWORD PTR [rcx+0x6],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_19b2:
	/* 0x19b2: jmp    1b1f <tail_nodeport_nat_ingress_ipv4+0x1b1f> */
	X86_SIM_X86_JMP(0x19b2, 0x1b1f, x86_l_1b1f);
x86_l_19b7:
	/* 0x19b7: movzx  eax,BYTE PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 40ULL);
x86_l_19bc:
	/* 0x19bc: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_19bf:
	/* 0x19bf: lea    r8,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_19c3:
	/* 0x19c3: add    r8,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_19c7:
	/* 0x19c7: mov    ebp,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967142ULL);
x86_l_19cc:
	/* 0x19cc: cmp    r8,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RCX, X86_WIDTH_64);
x86_l_19cf:
	/* 0x19cf: ja     1a61 <tail_nodeport_nat_ingress_ipv4+0x1a61> */
	X86_SIM_X86_JCC(X86_CC_A, 0x19cf, 0x1a61, x86_l_1a61);
x86_l_19d5:
	/* 0x19d5: add    rdi,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_19d8:
	/* 0x19d8: movzx  eax,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_19db:
	/* 0x19db: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_19dd:
	/* 0x19dd: setne  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_NE);
x86_l_19e1:
	/* 0x19e1: or     r8b,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RSI, X86_WIDTH_8, X86_ALU_OR);
x86_l_19e4:
	/* 0x19e4: cmp    r8b,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_8, 1ULL);
x86_l_19e8:
	/* 0x19e8: jne    17dc <tail_nodeport_nat_ingress_ipv4+0x17dc> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x19e8, 0x17dc, x86_l_17dc);
x86_l_19ee:
	/* 0x19ee: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_19f0:
	/* 0x19f0: add    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_19f2:
	/* 0x19f2: adc    edx,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_19f5:
	/* 0x19f5: movzx  eax,dx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_19f8:
	/* 0x19f8: shr    edx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_19fb:
	/* 0x19fb: add    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_19fd:
	/* 0x19fd: mov    eax,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_19ff:
	/* 0x19ff: shr    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1a02:
	/* 0x1a02: add    eax,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1a04:
	/* 0x1a04: cmp    ax,0xffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_16, 65535ULL);
x86_l_1a08:
	/* 0x1a08: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1a0a:
	/* 0x1a0a: mov    ecx,0xffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 65535ULL);
x86_l_1a0f:
	/* 0x1a0f: cmovne ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_NE);
x86_l_1a12:
	/* 0x1a12: test   sil,sil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_8);
x86_l_1a15:
	/* 0x1a15: cmovne ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_NE);
x86_l_1a18:
	/* 0x1a18: mov    WORD PTR [rdi],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a1b:
	/* 0x1a1b: mov    r12,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a1e:
	/* 0x1a1e: mov    rcx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a22:
	/* 0x1a22: jmp    17dc <tail_nodeport_nat_ingress_ipv4+0x17dc> */
	X86_SIM_X86_JMP(0x1a22, 0x17dc, x86_l_17dc);
x86_l_1a27:
	/* 0x1a27: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1a2c:
	/* 0x1a2c: add    rax,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1a2f:
	/* 0x1a2f: add    rax,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_1a33:
	/* 0x1a33: mov    ebp,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967155ULL);
x86_l_1a38:
	/* 0x1a38: cmp    rax,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_1a3b:
	/* 0x1a3b: ja     1a61 <tail_nodeport_nat_ingress_ipv4+0x1a61> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1a3b, 0x1a61, x86_l_1a61);
x86_l_1a3d:
	/* 0x1a3d: mov    r11,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1a42:
	/* 0x1a42: lea    rax,[r12+r11*1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_R11, 0), 0ULL);
x86_l_1a46:
	/* 0x1a46: mov    WORD PTR [r12+r11*1],r9w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R9, X86_WIDTH_16, X86_MEM_AUX(X86_R11, 0), 0ULL);
x86_l_1a4b:
	/* 0x1a4b: lea    r11,[rdi+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1a4f:
	/* 0x1a4f: add    r11,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_1a53:
	/* 0x1a53: mov    ebp,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967142ULL);
x86_l_1a58:
	/* 0x1a58: cmp    r11,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R11, X86_RCX, X86_WIDTH_64);
x86_l_1a5b:
	/* 0x1a5b: jbe    1b7d <tail_nodeport_nat_ingress_ipv4+0x1b7d> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x1a5b, 0x1b7d, x86_l_1b7d);
x86_l_1a61:
	/* 0x1a61: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a64:
	/* 0x1a64: jmp    ca <tail_nodeport_nat_ingress_ipv4+0xca> */
	X86_SIM_X86_JMP(0x1a64, 0xca, x86_l_ca);
x86_l_1a69:
	/* 0x1a69: movzx  r11d,WORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1a6d:
	/* 0x1a6d: not    r11d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1a70:
	/* 0x1a70: add    r11d,DWORD PTR [rsp+0x3c] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R11, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 60ULL);
x86_l_1a75:
	/* 0x1a75: setb   dil */
	X86_SIM_L_EXEC_SETCC(X86_RDI, X86_CC_B);
x86_l_1a79:
	/* 0x1a79: movzx  edi,dil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDI, X86_RDI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1a7d:
	/* 0x1a7d: add    edi,r11d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R11, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1a80:
	/* 0x1a80: movzx  r11d,di */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R11, X86_RDI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1a84:
	/* 0x1a84: shr    edi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1a87:
	/* 0x1a87: add    edi,r11d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R11, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1a8a:
	/* 0x1a8a: mov    r11d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_RDI, X86_WIDTH_32);
x86_l_1a8d:
	/* 0x1a8d: shr    r11d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1a91:
	/* 0x1a91: add    r11d,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1a94:
	/* 0x1a94: cmp    r11w,0xffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_16, 65535ULL);
x86_l_1a99:
	/* 0x1a99: not    r11d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1a9c:
	/* 0x1a9c: mov    edi,0xffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 65535ULL);
x86_l_1aa1:
	/* 0x1aa1: cmovne edi,r11d */
	X86_SIM_L_EXEC_CMOV(X86_RDI, X86_R11, X86_WIDTH_32, X86_CC_NE);
x86_l_1aa5:
	/* 0x1aa5: test   r8b,r8b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R8, X86_R8, X86_WIDTH_8);
x86_l_1aa8:
	/* 0x1aa8: cmovne edi,r11d */
	X86_SIM_L_EXEC_CMOV(X86_RDI, X86_R11, X86_WIDTH_32, X86_CC_NE);
x86_l_1aac:
	/* 0x1aac: mov    WORD PTR [r14],di */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDI, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ab0:
	/* 0x1ab0: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1ab3:
	/* 0x1ab3: je     cd0 <tail_nodeport_nat_ingress_ipv4+0xcd0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1ab3, 0xcd0, x86_l_cd0);
x86_l_1ab9:
	/* 0x1ab9: jmp    145b <tail_nodeport_nat_ingress_ipv4+0x145b> */
	X86_SIM_X86_JMP(0x1ab9, 0x145b, x86_l_145b);
x86_l_1abe:
	/* 0x1abe: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_1ac4:
	/* 0x1ac4: jmp    79e <tail_nodeport_nat_ingress_ipv4+0x79e> */
	X86_SIM_X86_JMP(0x1ac4, 0x79e, x86_l_79e);
x86_l_1ac9:
	/* 0x1ac9: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1acc:
	/* 0x1acc: lea    rcx,[rax+0x6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_1ad0:
	/* 0x1ad0: mov    r15d,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967155ULL);
x86_l_1ad6:
	/* 0x1ad6: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ad9:
	/* 0x1ad9: cmp    rcx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_1add:
	/* 0x1add: ja     f4c <tail_nodeport_nat_ingress_ipv4+0xf4c> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1add, 0xf4c, x86_l_f4c);
x86_l_1ae3:
	/* 0x1ae3: movzx  ecx,WORD PTR [rsp+0x9e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 158ULL);
x86_l_1aeb:
	/* 0x1aeb: mov    WORD PTR [rax+0x4],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1aef:
	/* 0x1aef: mov    ecx,DWORD PTR [rsp+0x9a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 154ULL);
x86_l_1af6:
	/* 0x1af6: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1af8:
	/* 0x1af8: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1afb:
	/* 0x1afb: lea    rcx,[rax+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1aff:
	/* 0x1aff: cmp    rcx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_1b03:
	/* 0x1b03: ja     f4c <tail_nodeport_nat_ingress_ipv4+0xf4c> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1b03, 0xf4c, x86_l_f4c);
x86_l_1b09:
	/* 0x1b09: movzx  ecx,WORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 152ULL);
x86_l_1b11:
	/* 0x1b11: mov    WORD PTR [rax+0xa],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 10ULL);
x86_l_1b15:
	/* 0x1b15: mov    ecx,DWORD PTR [rsp+0x94] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_1b1c:
	/* 0x1b1c: mov    DWORD PTR [rax+0x6],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_1b1f:
	/* 0x1b1f: cmp    DWORD PTR [rbx+0xc],ebp */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1b22:
	/* 0x1b22: jne    1b2e <tail_nodeport_nat_ingress_ipv4+0x1b2e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1b22, 0x1b2e, x86_l_1b2e);
x86_l_1b24:
	/* 0x1b24: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_1b29:
	/* 0x1b29: jmp    31e <tail_nodeport_nat_ingress_ipv4+0x31e> */
	X86_SIM_X86_JMP(0x1b29, 0x31e, x86_l_31e);
x86_l_1b2e:
	/* 0x1b2e: mov    eax,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 23ULL);
x86_l_1b33:
	/* 0x1b33: mov    edi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_32);
x86_l_1b35:
	/* 0x1b35: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b37:
	/* 0x1b37: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b39:
	/* 0x1b39: mov    ebp,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_1b3b:
	/* 0x1b3b: jmp    1eb1 <tail_nodeport_nat_ingress_ipv4+0x1eb1> */
	X86_SIM_X86_JMP(0x1b3b, 0x1eb1, x86_l_1eb1);
x86_l_1b40:
	/* 0x1b40: mov    QWORD PTR [rsp+0x28],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1b45:
	/* 0x1b45: mov    r12,r10 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R10, X86_WIDTH_64);
x86_l_1b48:
	/* 0x1b48: mov    r15,r9 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R9, X86_WIDTH_64);
x86_l_1b4b:
	/* 0x1b4b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1b50:
	/* 0x1b50: mov    rdi,QWORD PTR [rip+0x23c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv4_frag_datagrams)));
x86_l_1b57:
	/* 0x1b57: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1b5c:
	/* 0x1b5c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b5e:
	/* 0x1b5e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b61:
	/* 0x1b61: je     1d31 <tail_nodeport_nat_ingress_ipv4+0x1d31> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1b61, 0x1d31, x86_l_1d31);
x86_l_1b67:
	/* 0x1b67: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b69:
	/* 0x1b69: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b6d:
	/* 0x1b6d: jmp    1dbe <tail_nodeport_nat_ingress_ipv4+0x1dbe> */
	X86_SIM_X86_JMP(0x1b6d, 0x1dbe, x86_l_1dbe);
x86_l_1b72:
	/* 0x1b72: mov    r15d,0xffffff63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967139ULL);
x86_l_1b78:
	/* 0x1b78: jmp    f4c <tail_nodeport_nat_ingress_ipv4+0xf4c> */
	X86_SIM_X86_JMP(0x1b78, 0xf4c, x86_l_f4c);
x86_l_1b7d:
	/* 0x1b7d: add    rax,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1b80:
	/* 0x1b80: test   sil,sil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_8);
x86_l_1b83:
	/* 0x1b83: jne    1b8f <tail_nodeport_nat_ingress_ipv4+0x1b8f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1b83, 0x1b8f, x86_l_1b8f);
x86_l_1b85:
	/* 0x1b85: cmp    WORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b89:
	/* 0x1b89: je     17d3 <tail_nodeport_nat_ingress_ipv4+0x17d3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1b89, 0x17d3, x86_l_17d3);
x86_l_1b8f:
	/* 0x1b8f: test   r10d,r10d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R10, X86_R10, X86_WIDTH_32);
x86_l_1b92:
	/* 0x1b92: je     1d47 <tail_nodeport_nat_ingress_ipv4+0x1d47> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1b92, 0x1d47, x86_l_1d47);
x86_l_1b98:
	/* 0x1b98: not    r10d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1b9b:
	/* 0x1b9b: add    r10d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R9, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1b9e:
	/* 0x1b9e: adc    r10d,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_1ba2:
	/* 0x1ba2: movzx  r11d,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1ba6:
	/* 0x1ba6: not    r11d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1ba9:
	/* 0x1ba9: add    r11d,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_R10, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1bac:
	/* 0x1bac: jmp    1d51 <tail_nodeport_nat_ingress_ipv4+0x1d51> */
	X86_SIM_X86_JMP(0x1bac, 0x1d51, x86_l_1d51);
x86_l_1bb1:
	/* 0x1bb1: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1bb6:
	/* 0x1bb6: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1bbb:
	/* 0x1bbb: mov    QWORD PTR [rsp+0x28],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1bc0:
	/* 0x1bc0: mov    rdi,QWORD PTR [rip+0x23c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv4_frag_datagrams)));
x86_l_1bc7:
	/* 0x1bc7: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1bcc:
	/* 0x1bcc: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1bce:
	/* 0x1bce: mov    r15,r9 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R9, X86_WIDTH_64);
x86_l_1bd1:
	/* 0x1bd1: mov    r12,r10 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R10, X86_WIDTH_64);
x86_l_1bd4:
	/* 0x1bd4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bd6:
	/* 0x1bd6: mov    r8,QWORD PTR [rip+0x23c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R8, (void *)(long)(((__u64)(long)&__config_enable_ipv4_fragments)));
x86_l_1bdd:
	/* 0x1bdd: mov    r11,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1be2:
	/* 0x1be2: mov    r10,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R10, X86_R12, X86_WIDTH_64);
x86_l_1be5:
	/* 0x1be5: mov    r9,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_R15, X86_WIDTH_64);
x86_l_1be8:
	/* 0x1be8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1bea:
	/* 0x1bea: je     1026 <tail_nodeport_nat_ingress_ipv4+0x1026> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1bea, 0x1026, x86_l_1026);
x86_l_1bf0:
	/* 0x1bf0: mov    r14,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bf4:
	/* 0x1bf4: sub    r14,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 0ULL);
x86_l_1bf7:
	/* 0x1bf7: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1c00:
	/* 0x1c00: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1c09:
	/* 0x1c09: movabs rax,0x6b0085010a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 459570217226ULL);
x86_l_1c13:
	/* 0x1c13: add    rax,0x100 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 256ULL);
x86_l_1c19:
	/* 0x1c19: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1c21:
	/* 0x1c21: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1c26:
	/* 0x1c26: mov    rdi,QWORD PTR [rip+0x23c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1c2d:
	/* 0x1c2d: lea    rsi,[rsp+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1c35:
	/* 0x1c35: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c37:
	/* 0x1c37: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1c3a:
	/* 0x1c3a: je     1d93 <tail_nodeport_nat_ingress_ipv4+0x1d93> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1c3a, 0x1d93, x86_l_1d93);
x86_l_1c40:
	/* 0x1c40: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1c43:
	/* 0x1c43: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1c47:
	/* 0x1c47: jmp    1dbe <tail_nodeport_nat_ingress_ipv4+0x1dbe> */
	X86_SIM_X86_JMP(0x1c47, 0x1dbe, x86_l_1dbe);
x86_l_1c4c:
	/* 0x1c4c: mov    ebp,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_1c51:
	/* 0x1c51: cmp    dx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_16, 6ULL);
x86_l_1c55:
	/* 0x1c55: jne    1c92 <tail_nodeport_nat_ingress_ipv4+0x1c92> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1c55, 0x1c92, x86_l_1c92);
x86_l_1c57:
	/* 0x1c57: mov    ecx,DWORD PTR [rsp+0x3c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_1c5b:
	/* 0x1c5b: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1c5d:
	/* 0x1c5d: shr    ecx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_1c60:
	/* 0x1c60: and    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_1c63:
	/* 0x1c63: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1c65:
	/* 0x1c65: mov    WORD PTR [r14+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1c6a:
	/* 0x1c6a: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1c6c:
	/* 0x1c6c: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_1c71:
	/* 0x1c71: mov    ebp,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 21600ULL);
x86_l_1c76:
	/* 0x1c76: cmove  ebp,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_1c79:
	/* 0x1c79: mov    rax,QWORD PTR [rip+0x23c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1c80:
	/* 0x1c80: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c83:
	/* 0x1c83: je     1c92 <tail_nodeport_nat_ingress_ipv4+0x1c92> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1c83, 0x1c92, x86_l_1c92);
x86_l_1c85:
	/* 0x1c85: mov    rax,QWORD PTR [rip+0x23c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1c8c:
	/* 0x1c8c: imul   ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_1c8f:
	/* 0x1c8f: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1c92:
	/* 0x1c92: movzx  r15d,WORD PTR [rsp+0x3c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 60ULL);
x86_l_1c98:
	/* 0x1c98: shr    r15d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1c9c:
	/* 0x1c9c: mov    rax,QWORD PTR [rip+0x23c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1ca3:
	/* 0x1ca3: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ca6:
	/* 0x1ca6: je     1cb7 <tail_nodeport_nat_ingress_ipv4+0x1cb7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1ca6, 0x1cb7, x86_l_1cb7);
x86_l_1ca8:
	/* 0x1ca8: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_1cad:
	/* 0x1cad: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1caf:
	/* 0x1caf: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1cb1:
	/* 0x1cb1: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_1cb5:
	/* 0x1cb5: jmp    1cda <tail_nodeport_nat_ingress_ipv4+0x1cda> */
	X86_SIM_X86_JMP(0x1cb5, 0x1cda, x86_l_1cda);
x86_l_1cb7:
	/* 0x1cb7: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1cbc:
	/* 0x1cbc: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1cbe:
	/* 0x1cbe: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1cc0:
	/* 0x1cc0: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1cc4:
	/* 0x1cc4: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_1cce:
	/* 0x1cce: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1cd1:
	/* 0x1cd1: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1cd6:
	/* 0x1cd6: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_1cda:
	/* 0x1cda: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1cdc:
	/* 0x1cdc: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_1cdf:
	/* 0x1cdf: mov    DWORD PTR [r14+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ce3:
	/* 0x1ce3: movzx  ecx,BYTE PTR [r14+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_1ce8:
	/* 0x1ce8: mov    edx,DWORD PTR [r14+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1cec:
	/* 0x1cec: and    r15b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_1cf0:
	/* 0x1cf0: mov    rsi,QWORD PTR [rip+0x23c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1cf7:
	/* 0x1cf7: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cfa:
	/* 0x1cfa: je     1d0d <tail_nodeport_nat_ingress_ipv4+0x1d0d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1cfa, 0x1d0d, x86_l_1d0d);
x86_l_1cfc:
	/* 0x1cfc: mov    rsi,QWORD PTR [rip+0x23c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1d03:
	/* 0x1d03: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d05:
	/* 0x1d05: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_1d08:
	/* 0x1d08: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1d0b:
	/* 0x1d0b: jmp    1d12 <tail_nodeport_nat_ingress_ipv4+0x1d12> */
	X86_SIM_X86_JMP(0x1d0b, 0x1d12, x86_l_1d12);
x86_l_1d0d:
	/* 0x1d0d: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_1d12:
	/* 0x1d12: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1d14:
	/* 0x1d14: or     r15b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_1d17:
	/* 0x1d17: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_1d19:
	/* 0x1d19: jb     1d24 <tail_nodeport_nat_ingress_ipv4+0x1d24> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1d19, 0x1d24, x86_l_1d24);
x86_l_1d1b:
	/* 0x1d1b: cmp    cl,r15b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R15, X86_WIDTH_8);
x86_l_1d1e:
	/* 0x1d1e: je     a86 <tail_nodeport_nat_ingress_ipv4+0xa86> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1d1e, 0xa86, x86_l_a86);
x86_l_1d24:
	/* 0x1d24: mov    BYTE PTR [r14+0x2b],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_1d28:
	/* 0x1d28: mov    DWORD PTR [r14+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1d2c:
	/* 0x1d2c: jmp    a7d <tail_nodeport_nat_ingress_ipv4+0xa7d> */
	X86_SIM_X86_JMP(0x1d2c, 0xa7d, x86_l_a7d);
x86_l_1d31:
	/* 0x1d31: mov    r15d,0xffffff51 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967121ULL);
x86_l_1d37:
	/* 0x1d37: jmp    f4c <tail_nodeport_nat_ingress_ipv4+0xf4c> */
	X86_SIM_X86_JMP(0x1d37, 0xf4c, x86_l_f4c);
x86_l_1d3c:
	/* 0x1d3c: mov    r15d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 2ULL);
x86_l_1d42:
	/* 0x1d42: jmp    1174 <tail_nodeport_nat_ingress_ipv4+0x1174> */
	X86_SIM_X86_JMP(0x1d42, 0x1174, x86_l_1174);
x86_l_1d47:
	/* 0x1d47: movzx  r11d,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1d4b:
	/* 0x1d4b: not    r11d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1d4e:
	/* 0x1d4e: add    r11d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_R9, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1d51:
	/* 0x1d51: setb   r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_B);
x86_l_1d55:
	/* 0x1d55: movzx  r9d,r9b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R9, X86_R9, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1d59:
	/* 0x1d59: add    r9d,r11d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R11, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1d5c:
	/* 0x1d5c: movzx  r10d,r9w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R10, X86_R9, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1d60:
	/* 0x1d60: shr    r9d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1d64:
	/* 0x1d64: add    r9d,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R10, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1d67:
	/* 0x1d67: mov    r10d,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_R10, X86_R9, X86_WIDTH_32);
x86_l_1d6a:
	/* 0x1d6a: shr    r10d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1d6e:
	/* 0x1d6e: add    r10d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R9, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1d71:
	/* 0x1d71: cmp    r10w,0xffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_16, 65535ULL);
x86_l_1d76:
	/* 0x1d76: not    r10d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1d79:
	/* 0x1d79: mov    r9d,0xffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 65535ULL);
x86_l_1d7f:
	/* 0x1d7f: cmovne r9d,r10d */
	X86_SIM_L_EXEC_CMOV(X86_R9, X86_R10, X86_WIDTH_32, X86_CC_NE);
x86_l_1d83:
	/* 0x1d83: test   sil,sil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_8);
x86_l_1d86:
	/* 0x1d86: cmovne r9d,r10d */
	X86_SIM_L_EXEC_CMOV(X86_R9, X86_R10, X86_WIDTH_32, X86_CC_NE);
x86_l_1d8a:
	/* 0x1d8a: mov    WORD PTR [rax],r9w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R9, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d8e:
	/* 0x1d8e: jmp    17d3 <tail_nodeport_nat_ingress_ipv4+0x17d3> */
	X86_SIM_X86_JMP(0x1d8e, 0x17d3, x86_l_17d3);
x86_l_1d93:
	/* 0x1d93: mov    QWORD PTR [rsp+0x18],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215105ULL);
x86_l_1d9c:
	/* 0x1d9c: mov    QWORD PTR [rsp+0x20],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1da1:
	/* 0x1da1: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1da6:
	/* 0x1da6: mov    rdi,QWORD PTR [rip+0x23c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1dad:
	/* 0x1dad: lea    rsi,[rsp+0xc0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1db5:
	/* 0x1db5: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1dba:
	/* 0x1dba: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1dbc:
	/* 0x1dbc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dbe:
	/* 0x1dbe: mov    r9,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_R15, X86_WIDTH_64);
x86_l_1dc1:
	/* 0x1dc1: mov    r10,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R10, X86_R12, X86_WIDTH_64);
x86_l_1dc4:
	/* 0x1dc4: mov    r11,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1dc9:
	/* 0x1dc9: mov    r8,QWORD PTR [rip+0x23c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R8, (void *)(long)(((__u64)(long)&__config_enable_ipv4_fragments)));
x86_l_1dd0:
	/* 0x1dd0: jmp    1026 <tail_nodeport_nat_ingress_ipv4+0x1026> */
	X86_SIM_X86_JMP(0x1dd0, 0x1026, x86_l_1026);
x86_l_1dd5:
	/* 0x1dd5: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1dd7:
	/* 0x1dd7: jmp    181a <tail_nodeport_nat_ingress_ipv4+0x181a> */
	X86_SIM_X86_JMP(0x1dd7, 0x181a, x86_l_181a);
x86_l_1ddc:
	/* 0x1ddc: mov    r13d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 60ULL);
x86_l_1de2:
	/* 0x1de2: cmp    r12b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_8, 6ULL);
x86_l_1de6:
	/* 0x1de6: jne    1e1f <tail_nodeport_nat_ingress_ipv4+0x1e1f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1de6, 0x1e1f, x86_l_1e1f);
x86_l_1de8:
	/* 0x1de8: mov    eax,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_1dea:
	/* 0x1dea: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1dec:
	/* 0x1dec: shr    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_1def:
	/* 0x1def: and    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_1df2:
	/* 0x1df2: or     ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1df4:
	/* 0x1df4: mov    WORD PTR [r14+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1df9:
	/* 0x1df9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1dfb:
	/* 0x1dfb: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_1e00:
	/* 0x1e00: mov    r13d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 21600ULL);
x86_l_1e06:
	/* 0x1e06: cmove  r13d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_1e0a:
	/* 0x1e0a: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e0e:
	/* 0x1e0e: je     1e1f <tail_nodeport_nat_ingress_ipv4+0x1e1f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1e0e, 0x1e1f, x86_l_1e1f);
x86_l_1e10:
	/* 0x1e10: mov    rax,QWORD PTR [rip+0x23c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1e17:
	/* 0x1e17: imul   r13d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_1e1b:
	/* 0x1e1b: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1e1f:
	/* 0x1e1f: movzx  r12d,dx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_RDX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1e23:
	/* 0x1e23: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1e27:
	/* 0x1e27: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e2b:
	/* 0x1e2b: je     1e3c <tail_nodeport_nat_ingress_ipv4+0x1e3c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1e2b, 0x1e3c, x86_l_1e3c);
x86_l_1e2d:
	/* 0x1e2d: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_1e32:
	/* 0x1e32: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e34:
	/* 0x1e34: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1e36:
	/* 0x1e36: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_1e3a:
	/* 0x1e3a: jmp    1e5f <tail_nodeport_nat_ingress_ipv4+0x1e5f> */
	X86_SIM_X86_JMP(0x1e3a, 0x1e5f, x86_l_1e5f);
x86_l_1e3c:
	/* 0x1e3c: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1e41:
	/* 0x1e41: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e43:
	/* 0x1e43: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1e45:
	/* 0x1e45: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1e49:
	/* 0x1e49: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_1e53:
	/* 0x1e53: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1e56:
	/* 0x1e56: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1e5b:
	/* 0x1e5b: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_1e5f:
	/* 0x1e5f: add    r13d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1e62:
	/* 0x1e62: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_1e65:
	/* 0x1e65: mov    DWORD PTR [r14+0x20],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e69:
	/* 0x1e69: movzx  ecx,BYTE PTR [r14+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_1e6e:
	/* 0x1e6e: mov    edx,DWORD PTR [r14+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1e72:
	/* 0x1e72: and    r12b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_1e76:
	/* 0x1e76: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e7a:
	/* 0x1e7a: je     1e8d <tail_nodeport_nat_ingress_ipv4+0x1e8d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1e7a, 0x1e8d, x86_l_1e8d);
x86_l_1e7c:
	/* 0x1e7c: mov    rsi,QWORD PTR [rip+0x23c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1e83:
	/* 0x1e83: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e85:
	/* 0x1e85: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_1e88:
	/* 0x1e88: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1e8b:
	/* 0x1e8b: jmp    1e92 <tail_nodeport_nat_ingress_ipv4+0x1e92> */
	X86_SIM_X86_JMP(0x1e8b, 0x1e92, x86_l_1e92);
x86_l_1e8d:
	/* 0x1e8d: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_1e92:
	/* 0x1e92: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1e94:
	/* 0x1e94: or     r12b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_1e97:
	/* 0x1e97: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_1e99:
	/* 0x1e99: jb     1ea0 <tail_nodeport_nat_ingress_ipv4+0x1ea0> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1e99, 0x1ea0, x86_l_1ea0);
x86_l_1e9b:
	/* 0x1e9b: cmp    cl,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R12, X86_WIDTH_8);
x86_l_1e9e:
	/* 0x1e9e: je     1eb1 <tail_nodeport_nat_ingress_ipv4+0x1eb1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1e9e, 0x1eb1, x86_l_1eb1);
x86_l_1ea0:
	/* 0x1ea0: mov    BYTE PTR [r14+0x2b],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_1ea4:
	/* 0x1ea4: mov    DWORD PTR [r14+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1ea8:
	/* 0x1ea8: mov    rax,QWORD PTR [rip+0x23c7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_1eaf:
	/* 0x1eaf: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1eb1:
	/* 0x1eb1: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1eb4:
	/* 0x1eb4: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_1eb6:
	/* 0x1eb6: js     ca <tail_nodeport_nat_ingress_ipv4+0xca> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1eb6, 0xca, x86_l_ca);
x86_l_1ebc:
	/* 0x1ebc: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_1ebf:
	/* 0x1ebf: je     ca <tail_nodeport_nat_ingress_ipv4+0xca> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1ebf, 0xca, x86_l_ca);
x86_l_1ec5:
	/* 0x1ec5: cmp    ebp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_1ec8:
	/* 0x1ec8: je     82 <tail_nodeport_nat_ingress_ipv4+0x82> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1ec8, 0x82, x86_l_82);
x86_l_1ece:
	/* 0x1ece: jmp    31e <tail_nodeport_nat_ingress_ipv4+0x31e> */
	X86_SIM_X86_JMP(0x1ece, 0x31e, x86_l_31e);
x86_l_1ed3:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
