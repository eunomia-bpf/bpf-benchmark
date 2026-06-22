extern char __config_debug_lb;
extern char __config_enable_conntrack_accounting;
extern char __config_enable_ipv4_fragments;
extern char __config_enable_jiffies;
extern char __config_eth_header_length;
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
int cilium_bpf_host_tail_nodeport_nat_ingress_ipv4_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0xa: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: mov    rax,QWORD PTR [rip+0x30f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_nodeport_port_max)));
x86_l_14:
	/* 0x14: movzx  ebp,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_17:
	/* 0x17: mov    rax,QWORD PTR [rip+0x30f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_1e:
	/* 0x1e: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20:
	/* 0x20: mov    r13d,DWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_24:
	/* 0x24: mov    DWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_2c:
	/* 0x2c: mov    rax,QWORD PTR [rip+0x30f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_33:
	/* 0x33: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_36:
	/* 0x36: mov    rcx,QWORD PTR [rdi+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_3d:
	/* 0x3d: mov    edx,DWORD PTR [rdi+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_40:
	/* 0x40: sub    edx,DWORD PTR [rdi+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RDI, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_43:
	/* 0x43: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_46:
	/* 0x46: lea    rsi,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_4a:
	/* 0x4a: add    rsi,0x14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 20ULL);
x86_l_4e:
	/* 0x4e: mov    r12d,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967162ULL);
x86_l_54:
	/* 0x54: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_57:
	/* 0x57: ja     1005 <tail_nodeport_nat_ingress_ipv4+0x1005> */
	X86_SIM_X86_JCC(X86_CC_A, 0x57, 0x1005, x86_l_1005);
x86_l_5d:
	/* 0x5d: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_60:
	/* 0x60: movabs r9,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_64, 2199023255552ULL);
x86_l_6a:
	/* 0x6a: movabs r10,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_64, 1099511627776ULL);
x86_l_74:
	/* 0x74: movzx  esi,WORD PTR [rcx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_78:
	/* 0x78: movzx  edx,BYTE PTR [rcx+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_7c:
	/* 0x7c: mov    rdi,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_7f:
	/* 0x7f: shl    rdi,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_83:
	/* 0x83: or     rdi,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_64, X86_ALU_OR);
x86_l_86:
	/* 0x86: movzx  esi,WORD PTR [rcx+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_8a:
	/* 0x8a: lea    r8,[rdi+r10*1] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_R10, 0), 0ULL);
x86_l_8e:
	/* 0x8e: test   esi,0xff3f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RSI, X86_WIDTH_32, 65343ULL);
x86_l_94:
	/* 0x94: cmove  r8,rdi */
	X86_SIM_L_EXEC_CMOV(X86_R8, X86_RDI, X86_WIDTH_64, X86_CC_E);
x86_l_98:
	/* 0x98: lea    r14,[r8+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_9c:
	/* 0x9c: test   esi,0xff1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RSI, X86_WIDTH_32, 65311ULL);
x86_l_a2:
	/* 0xa2: cmove  r14,r8 */
	X86_SIM_L_EXEC_CMOV(X86_R14, X86_R8, X86_WIDTH_64, X86_CC_E);
x86_l_a6:
	/* 0xa6: mov    BYTE PTR [rsp+0x3c],dl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_aa:
	/* 0xaa: mov    r8d,DWORD PTR [rcx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ae:
	/* 0xae: mov    DWORD PTR [rsp+0x30],r8d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_b3:
	/* 0xb3: mov    edi,DWORD PTR [rcx+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_b6:
	/* 0xb6: mov    DWORD PTR [rsp+0x34],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_ba:
	/* 0xba: mov    BYTE PTR [rsp+0x3d],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 261993005057ULL);
x86_l_bf:
	/* 0xbf: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c1:
	/* 0xc1: and    ecx,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_c4:
	/* 0xc4: lea    rsi,[rax+rcx*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 2), 0ULL);
x86_l_c8:
	/* 0xc8: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_cb:
	/* 0xcb: je     1c7 <tail_nodeport_nat_ingress_ipv4+0x1c7> */
	X86_SIM_X86_JCC(X86_CC_E, 0xcb, 0x1c7, x86_l_1c7);
x86_l_d1:
	/* 0xd1: mov    r12d,0xffffff53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967123ULL);
x86_l_d7:
	/* 0xd7: cmp    edx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 17ULL);
x86_l_da:
	/* 0xda: je     e5 <tail_nodeport_nat_ingress_ipv4+0xe5> */
	X86_SIM_X86_JCC(X86_CC_E, 0xda, 0xe5, x86_l_e5);
x86_l_dc:
	/* 0xdc: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_df:
	/* 0xdf: jne    1005 <tail_nodeport_nat_ingress_ipv4+0x1005> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xdf, 0x1005, x86_l_1005);
x86_l_e5:
	/* 0xe5: lea    r15,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_ea:
	/* 0xea: mov    rax,QWORD PTR [rip+0x30f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_ipv4_fragments)));
x86_l_f1:
	/* 0xf1: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f4:
	/* 0xf4: mov    QWORD PTR [rsp+0x50],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_f9:
	/* 0xf9: je     22b <tail_nodeport_nat_ingress_ipv4+0x22b> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf9, 0x22b, x86_l_22b);
x86_l_ff:
	/* 0xff: mov    DWORD PTR [rsp+0x8],r8d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_104:
	/* 0x104: mov    DWORD PTR [rsp+0xc],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_108:
	/* 0x108: mov    WORD PTR [rsp+0x10],r14w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10e:
	/* 0x10e: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_111:
	/* 0x111: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_115:
	/* 0x115: mov    BYTE PTR [rsp+0x12],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_119:
	/* 0x119: mov    BYTE PTR [rsp+0x13],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 81604378624ULL);
x86_l_11e:
	/* 0x11e: test   r14,r9 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R9, X86_WIDTH_64);
x86_l_121:
	/* 0x121: jne    14ab <tail_nodeport_nat_ingress_ipv4+0x14ab> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x121, 0x14ab, x86_l_14ab);
x86_l_127:
	/* 0x127: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_12c:
	/* 0x12c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_12f:
	/* 0x12f: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_132:
	/* 0x132: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_137:
	/* 0x137: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_139:
	/* 0x139: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_13b:
	/* 0x13b: js     373 <tail_nodeport_nat_ingress_ipv4+0x373> */
	X86_SIM_X86_JCC(X86_CC_S, 0x13b, 0x373, x86_l_373);
x86_l_141:
	/* 0x141: movabs rax,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 1099511627776ULL);
x86_l_14b:
	/* 0x14b: test   r14,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_14e:
	/* 0x14e: je     24e <tail_nodeport_nat_ingress_ipv4+0x24e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14e, 0x24e, x86_l_24e);
x86_l_154:
	/* 0x154: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_159:
	/* 0x159: mov    rdi,QWORD PTR [rip+0x30f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv4_frag_datagrams)));
x86_l_160:
	/* 0x160: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_165:
	/* 0x165: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_168:
	/* 0x168: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16a:
	/* 0x16a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16c:
	/* 0x16c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_16e:
	/* 0x16e: je     24e <tail_nodeport_nat_ingress_ipv4+0x24e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x16e, 0x24e, x86_l_24e);
x86_l_174:
	/* 0x174: mov    r15d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_178:
	/* 0x178: mov    QWORD PTR [rsp+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_184:
	/* 0x184: mov    QWORD PTR [rsp+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_190:
	/* 0x190: movabs rax,0x6b0085010a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 459570217226ULL);
x86_l_19a:
	/* 0x19a: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_19f:
	/* 0x19f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a4:
	/* 0x1a4: mov    rdi,QWORD PTR [rip+0x30f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1ab:
	/* 0x1ab: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1b0:
	/* 0x1b0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b2:
	/* 0x1b2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b5:
	/* 0x1b5: je     1928 <tail_nodeport_nat_ingress_ipv4+0x1928> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1b5, 0x1928, x86_l_1928);
x86_l_1bb:
	/* 0x1bb: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1be:
	/* 0x1be: add    QWORD PTR [rax+0x8],r15 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1c2:
	/* 0x1c2: jmp    24e <tail_nodeport_nat_ingress_ipv4+0x24e> */
	X86_SIM_X86_JMP(0x1c2, 0x24e, x86_l_24e);
x86_l_1c7:
	/* 0x1c7: mov    DWORD PTR [rsp+0x4],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1cc:
	/* 0x1cc: test   r14,r10 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R10, X86_WIDTH_64);
x86_l_1cf:
	/* 0x1cf: jne    1000 <tail_nodeport_nat_ingress_ipv4+0x1000> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1cf, 0x1000, x86_l_1000);
x86_l_1d5:
	/* 0x1d5: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1da:
	/* 0x1da: lea    rdx,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1df:
	/* 0x1df: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1e2:
	/* 0x1e2: mov    QWORD PTR [rsp+0x50],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1e7:
	/* 0x1e7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1ec:
	/* 0x1ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ee:
	/* 0x1ee: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1f0:
	/* 0x1f0: js     1000 <tail_nodeport_nat_ingress_ipv4+0x1000> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1f0, 0x1000, x86_l_1000);
x86_l_1f6:
	/* 0x1f6: movzx  eax,BYTE PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 104ULL);
x86_l_1fb:
	/* 0x1fb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1fd:
	/* 0x1fd: je     494 <tail_nodeport_nat_ingress_ipv4+0x494> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1fd, 0x494, x86_l_494);
x86_l_203:
	/* 0x203: mov    r12d,0xffffff53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967123ULL);
x86_l_209:
	/* 0x209: cmp    eax,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_20c:
	/* 0x20c: je     37e <tail_nodeport_nat_ingress_ipv4+0x37e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x20c, 0x37e, x86_l_37e);
x86_l_212:
	/* 0x212: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_215:
	/* 0x215: jne    1000 <tail_nodeport_nat_ingress_ipv4+0x1000> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x215, 0x1000, x86_l_1000);
x86_l_21b:
	/* 0x21b: cmp    BYTE PTR [rsp+0x69],0xf */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 450971566095ULL);
x86_l_220:
	/* 0x220: jbe    389 <tail_nodeport_nat_ingress_ipv4+0x389> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x220, 0x389, x86_l_389);
x86_l_226:
	/* 0x226: jmp    1000 <tail_nodeport_nat_ingress_ipv4+0x1000> */
	X86_SIM_X86_JMP(0x226, 0x1000, x86_l_1000);
x86_l_22b:
	/* 0x22b: test   r14,r9 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R9, X86_WIDTH_64);
x86_l_22e:
	/* 0x22e: jne    14dd <tail_nodeport_nat_ingress_ipv4+0x14dd> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x22e, 0x14dd, x86_l_14dd);
x86_l_234:
	/* 0x234: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_239:
	/* 0x239: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_23c:
	/* 0x23c: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_23f:
	/* 0x23f: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_244:
	/* 0x244: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_246:
	/* 0x246: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_248:
	/* 0x248: js     373 <tail_nodeport_nat_ingress_ipv4+0x373> */
	X86_SIM_X86_JCC(X86_CC_S, 0x248, 0x373, x86_l_373);
x86_l_24e:
	/* 0x24e: inc    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_250:
	/* 0x250: movzx  eax,WORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_255:
	/* 0x255: movzx  ecx,WORD PTR [rsp+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_25a:
	/* 0x25a: mov    WORD PTR [rsp+0x3a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_25f:
	/* 0x25f: mov    WORD PTR [rsp+0x38],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_264:
	/* 0x264: rol    cx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_268:
	/* 0x268: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_26d:
	/* 0x26d: cmp    cx,bp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_16);
x86_l_270:
	/* 0x270: jb     1005 <tail_nodeport_nat_ingress_ipv4+0x1005> */
	X86_SIM_X86_JCC(X86_CC_B, 0x270, 0x1005, x86_l_1005);
x86_l_276:
	/* 0x276: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_27a:
	/* 0x27a: mov    DWORD PTR [rsp+0x4],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_27f:
	/* 0x27f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_284:
	/* 0x284: mov    rdi,QWORD PTR [rip+0x30f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_28b:
	/* 0x28b: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_290:
	/* 0x290: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_292:
	/* 0x292: mov    r12d,0xffffff59 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967129ULL);
x86_l_298:
	/* 0x298: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_29b:
	/* 0x29b: je     1000 <tail_nodeport_nat_ingress_ipv4+0x1000> */
	X86_SIM_X86_JCC(X86_CC_E, 0x29b, 0x1000, x86_l_1000);
x86_l_2a1:
	/* 0x2a1: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_2a4:
	/* 0x2a4: mov    eax,DWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2a7:
	/* 0x2a7: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2ab:
	/* 0x2ab: movzx  eax,WORD PTR [r15+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_2b0:
	/* 0x2b0: mov    WORD PTR [rsp+0x12],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_2b5:
	/* 0x2b5: mov    eax,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2b9:
	/* 0x2b9: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2bd:
	/* 0x2bd: movzx  eax,WORD PTR [rsp+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_2c2:
	/* 0x2c2: mov    WORD PTR [rsp+0x10],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2c7:
	/* 0x2c7: movzx  eax,BYTE PTR [rsp+0x3c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 60ULL);
x86_l_2cc:
	/* 0x2cc: mov    BYTE PTR [rsp+0x14],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2d0:
	/* 0x2d0: mov    BYTE PTR [rsp+0x15],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 90194313216ULL);
x86_l_2d5:
	/* 0x2d5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2da:
	/* 0x2da: mov    rdi,QWORD PTR [rip+0x30f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_2e1:
	/* 0x2e1: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e6:
	/* 0x2e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e8:
	/* 0x2e8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2eb:
	/* 0x2eb: jne    504 <tail_nodeport_nat_ingress_ipv4+0x504> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2eb, 0x504, x86_l_504);
x86_l_2f1:
	/* 0x2f1: mov    QWORD PTR [rsp+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_2fd:
	/* 0x2fd: mov    QWORD PTR [rsp+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_309:
	/* 0x309: mov    QWORD PTR [rsp+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_315:
	/* 0x315: mov    QWORD PTR [rsp+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_321:
	/* 0x321: mov    QWORD PTR [rsp+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_32d:
	/* 0x32d: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_331:
	/* 0x331: mov    DWORD PTR [rsp+0xb0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_338:
	/* 0x338: movzx  eax,WORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_33d:
	/* 0x33d: mov    WORD PTR [rsp+0xb4],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 180ULL);
x86_l_345:
	/* 0x345: mov    rax,QWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_349:
	/* 0x349: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_351:
	/* 0x351: mov    rax,QWORD PTR [rip+0x30f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_358:
	/* 0x358: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35b:
	/* 0x35b: je     4b4 <tail_nodeport_nat_ingress_ipv4+0x4b4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x35b, 0x4b4, x86_l_4b4);
x86_l_361:
	/* 0x361: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_366:
	/* 0x366: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_368:
	/* 0x368: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_36a:
	/* 0x36a: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_36e:
	/* 0x36e: jmp    4d7 <tail_nodeport_nat_ingress_ipv4+0x4d7> */
	X86_SIM_X86_JMP(0x36e, 0x4d7, x86_l_4d7);
x86_l_373:
	/* 0x373: mov    r12d,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967161ULL);
x86_l_379:
	/* 0x379: jmp    1005 <tail_nodeport_nat_ingress_ipv4+0x1005> */
	X86_SIM_X86_JMP(0x379, 0x1005, x86_l_1005);
x86_l_37e:
	/* 0x37e: cmp    BYTE PTR [rsp+0x69],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 450971566081ULL);
x86_l_383:
	/* 0x383: ja     1000 <tail_nodeport_nat_ingress_ipv4+0x1000> */
	X86_SIM_X86_JCC(X86_CC_A, 0x383, 0x1000, x86_l_1000);
x86_l_389:
	/* 0x389: mov    QWORD PTR [rsp+0xe],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60129542144ULL);
x86_l_392:
	/* 0x392: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_39b:
	/* 0x39b: mov    ebp,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_39e:
	/* 0x39e: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_3a3:
	/* 0x3a3: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3a8:
	/* 0x3a8: lea    r15d,[rcx+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3ac:
	/* 0x3ac: lea    rdx,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_3b4:
	/* 0x3b4: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_3b7:
	/* 0x3b7: mov    esi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_3ba:
	/* 0x3ba: mov    ecx,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 20ULL);
x86_l_3bf:
	/* 0x3bf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c1:
	/* 0x3c1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3c3:
	/* 0x3c3: js     8dd <tail_nodeport_nat_ingress_ipv4+0x8dd> */
	X86_SIM_X86_JCC(X86_CC_S, 0x3c3, 0x8dd, x86_l_8dd);
x86_l_3c9:
	/* 0x3c9: movzx  eax,BYTE PTR [rsp+0x99] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 153ULL);
x86_l_3d1:
	/* 0x3d1: mov    ecx,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_3d8:
	/* 0x3d8: mov    BYTE PTR [rsp+0x14],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_3dc:
	/* 0x3dc: mov    rdx,QWORD PTR [rsp+0x9c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_3e4:
	/* 0x3e4: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3e9:
	/* 0x3e9: and    ecx,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_3ec:
	/* 0x3ec: mov    BYTE PTR [rsp+0x15],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 90194313217ULL);
x86_l_3f1:
	/* 0x3f1: lea    r13d,[r15+rcx*4] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 0ULL);
x86_l_3f5:
	/* 0x3f5: mov    r12d,0xffffff53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967123ULL);
x86_l_3fb:
	/* 0x3fb: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3fe:
	/* 0x3fe: je     887 <tail_nodeport_nat_ingress_ipv4+0x887> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3fe, 0x887, x86_l_887);
x86_l_404:
	/* 0x404: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_407:
	/* 0x407: je     412 <tail_nodeport_nat_ingress_ipv4+0x412> */
	X86_SIM_X86_JCC(X86_CC_E, 0x407, 0x412, x86_l_412);
x86_l_409:
	/* 0x409: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_40c:
	/* 0x40c: jne    1000 <tail_nodeport_nat_ingress_ipv4+0x1000> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x40c, 0x1000, x86_l_1000);
x86_l_412:
	/* 0x412: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_417:
	/* 0x417: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_41c:
	/* 0x41c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_41f:
	/* 0x41f: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_422:
	/* 0x422: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_427:
	/* 0x427: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_429:
	/* 0x429: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_42b:
	/* 0x42b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_42d:
	/* 0x42d: js     8dd <tail_nodeport_nat_ingress_ipv4+0x8dd> */
	X86_SIM_X86_JCC(X86_CC_S, 0x42d, 0x8dd, x86_l_8dd);
x86_l_433:
	/* 0x433: mov    QWORD PTR [rsp+0x40],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_438:
	/* 0x438: mov    DWORD PTR [rsp+0x20],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_43c:
	/* 0x43c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_441:
	/* 0x441: mov    rdi,QWORD PTR [rip+0x30f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_448:
	/* 0x448: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_44d:
	/* 0x44d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_44f:
	/* 0x44f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_452:
	/* 0x452: je     1000 <tail_nodeport_nat_ingress_ipv4+0x1000> */
	X86_SIM_X86_JCC(X86_CC_E, 0x452, 0x1000, x86_l_1000);
x86_l_458:
	/* 0x458: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_45b:
	/* 0x45b: movzx  eax,BYTE PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 20ULL);
x86_l_460:
	/* 0x460: mov    cl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_462:
	/* 0x462: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_465:
	/* 0x465: je     e9c <tail_nodeport_nat_ingress_ipv4+0xe9c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x465, 0xe9c, x86_l_e9c);
x86_l_46b:
	/* 0x46b: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_46e:
	/* 0x46e: jne    ed6 <tail_nodeport_nat_ingress_ipv4+0xed6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x46e, 0xed6, x86_l_ed6);
x86_l_474:
	/* 0x474: sub    ebp,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 64ULL);
x86_l_478:
	/* 0x478: mov    eax,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_47f:
	/* 0x47f: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_482:
	/* 0x482: lea    eax,[rax*4+0x12] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 18ULL);
x86_l_489:
	/* 0x489: cmp    ebp,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_48b:
	/* 0x48b: setae  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_AE);
x86_l_48f:
	/* 0x48f: jmp    ed9 <tail_nodeport_nat_ingress_ipv4+0xed9> */
	X86_SIM_X86_JMP(0x48f, 0xed9, x86_l_ed9);
x86_l_494:
	/* 0x494: movzx  eax,WORD PTR [rsp+0x6c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 108ULL);
x86_l_499:
	/* 0x499: mov    WORD PTR [rsp+0x38],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_49e:
	/* 0x49e: mov    WORD PTR [rsp+0x3a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 249108103168ULL);
x86_l_4a5:
	/* 0x4a5: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_4aa:
	/* 0x4aa: mov    r13d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4af:
	/* 0x4af: jmp    276 <tail_nodeport_nat_ingress_ipv4+0x276> */
	X86_SIM_X86_JMP(0x4af, 0x276, x86_l_276);
x86_l_4b4:
	/* 0x4b4: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_4b9:
	/* 0x4b9: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4bb:
	/* 0x4bb: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_4bd:
	/* 0x4bd: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_4c1:
	/* 0x4c1: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_4cb:
	/* 0x4cb: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_4ce:
	/* 0x4ce: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_4d3:
	/* 0x4d3: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_4d7:
	/* 0x4d7: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_4df:
	/* 0x4df: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4e4:
	/* 0x4e4: mov    rdi,QWORD PTR [rip+0x30f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_4eb:
	/* 0x4eb: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f0:
	/* 0x4f0: lea    rdx,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_4f8:
	/* 0x4f8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4fa:
	/* 0x4fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4fc:
	/* 0x4fc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4fe:
	/* 0x4fe: js     1000 <tail_nodeport_nat_ingress_ipv4+0x1000> */
	X86_SIM_X86_JCC(X86_CC_S, 0x4fe, 0x1000, x86_l_1000);
x86_l_504:
	/* 0x504: cmp    QWORD PTR [r15+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_509:
	/* 0x509: movabs r9,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_64, 2199023255552ULL);
x86_l_513:
	/* 0x513: je     98f <tail_nodeport_nat_ingress_ipv4+0x98f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x513, 0x98f, x86_l_98f);
x86_l_519:
	/* 0x519: movzx  eax,WORD PTR [rsp+0x3c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 60ULL);
x86_l_51e:
	/* 0x51e: mov    WORD PTR [rsp+0x14],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_523:
	/* 0x523: movzx  ecx,WORD PTR [rsp+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_528:
	/* 0x528: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_52d:
	/* 0x52d: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_532:
	/* 0x532: mov    edx,DWORD PTR [r15+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_536:
	/* 0x536: mov    DWORD PTR [rsp+0x8],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_53a:
	/* 0x53a: movzx  edx,WORD PTR [r15+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_53f:
	/* 0x53f: mov    WORD PTR [rsp+0x12],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_544:
	/* 0x544: mov    WORD PTR [rsp+0x10],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_549:
	/* 0x549: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_54c:
	/* 0x54c: mov    DWORD PTR [rsp+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_550:
	/* 0x550: cmp    ax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_16, 6ULL);
x86_l_554:
	/* 0x554: jne    55f <tail_nodeport_nat_ingress_ipv4+0x55f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x554, 0x55f, x86_l_55f);
x86_l_556:
	/* 0x556: mov    r12,QWORD PTR [rip+0x30f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&cilium_ct4_global)));
x86_l_55d:
	/* 0x55d: jmp    566 <tail_nodeport_nat_ingress_ipv4+0x566> */
	X86_SIM_X86_JMP(0x55d, 0x566, x86_l_566);
x86_l_55f:
	/* 0x55f: mov    r12,QWORD PTR [rip+0x30f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&cilium_ct_any4_global)));
x86_l_566:
	/* 0x566: mov    BYTE PTR [rsp+0x15],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 90194313216ULL);
x86_l_56b:
	/* 0x56b: mov    DWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_573:
	/* 0x573: mov    rax,QWORD PTR [rip+0x30f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_ipv4_fragments)));
x86_l_57a:
	/* 0x57a: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_57d:
	/* 0x57d: je     61b <tail_nodeport_nat_ingress_ipv4+0x61b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x57d, 0x61b, x86_l_61b);
x86_l_583:
	/* 0x583: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_586:
	/* 0x586: movabs rcx,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1099511627776ULL);
x86_l_590:
	/* 0x590: and    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_593:
	/* 0x593: je     61b <tail_nodeport_nat_ingress_ipv4+0x61b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x593, 0x61b, x86_l_61b);
x86_l_599:
	/* 0x599: mov    r13,r9 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R9, X86_WIDTH_64);
x86_l_59c:
	/* 0x59c: mov    ebp,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_59f:
	/* 0x59f: mov    QWORD PTR [rsp+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_5ab:
	/* 0x5ab: mov    QWORD PTR [rsp+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_5b7:
	/* 0x5b7: movabs rax,0x6c03a50109 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 463917613321ULL);
x86_l_5c1:
	/* 0x5c1: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_5c6:
	/* 0x5c6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5cb:
	/* 0x5cb: mov    rdi,QWORD PTR [rip+0x30f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_5d2:
	/* 0x5d2: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_5d7:
	/* 0x5d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d9:
	/* 0x5d9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5dc:
	/* 0x5dc: je     5e7 <tail_nodeport_nat_ingress_ipv4+0x5e7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5dc, 0x5e7, x86_l_5e7);
x86_l_5de:
	/* 0x5de: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_5e1:
	/* 0x5e1: add    QWORD PTR [rax+0x8],rbp */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_5e5:
	/* 0x5e5: jmp    618 <tail_nodeport_nat_ingress_ipv4+0x618> */
	X86_SIM_X86_JMP(0x5e5, 0x618, x86_l_618);
x86_l_5e7:
	/* 0x5e7: mov    QWORD PTR [rsp+0x90],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290625ULL);
x86_l_5f3:
	/* 0x5f3: mov    QWORD PTR [rsp+0x98],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_5fb:
	/* 0x5fb: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_600:
	/* 0x600: mov    rdi,QWORD PTR [rip+0x30f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_607:
	/* 0x607: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_60c:
	/* 0x60c: lea    rdx,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_614:
	/* 0x614: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_616:
	/* 0x616: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_618:
	/* 0x618: mov    r9,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_R13, X86_WIDTH_64);
x86_l_61b:
	/* 0x61b: cmp    WORD PTR [rsp+0x48],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 309237645318ULL);
x86_l_621:
	/* 0x621: jne    67e <tail_nodeport_nat_ingress_ipv4+0x67e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x621, 0x67e, x86_l_67e);
x86_l_623:
	/* 0x623: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_626:
	/* 0x626: and    rax,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R9, X86_WIDTH_64, X86_ALU_AND);
x86_l_629:
	/* 0x629: jne    67e <tail_nodeport_nat_ingress_ipv4+0x67e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x629, 0x67e, x86_l_67e);
x86_l_62b:
	/* 0x62b: mov    r13,r9 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R9, X86_WIDTH_64);
x86_l_62e:
	/* 0x62e: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_633:
	/* 0x633: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_638:
	/* 0x638: lea    esi,[rcx+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_63b:
	/* 0x63b: lea    rdx,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_640:
	/* 0x640: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_643:
	/* 0x643: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_648:
	/* 0x648: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_64a:
	/* 0x64a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_64c:
	/* 0x64c: js     6df <tail_nodeport_nat_ingress_ipv4+0x6df> */
	X86_SIM_X86_JCC(X86_CC_S, 0x64c, 0x6df, x86_l_6df);
x86_l_652:
	/* 0x652: mov    ebp,DWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_656:
	/* 0x656: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_658:
	/* 0x658: and    eax,0x1200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4608ULL);
x86_l_65d:
	/* 0x65d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_65f:
	/* 0x65f: cmp    eax,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 512ULL);
x86_l_664:
	/* 0x664: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_667:
	/* 0x667: test   ebp,0x500 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RBP, X86_WIDTH_32, 1280ULL);
x86_l_66d:
	/* 0x66d: jne    19c4 <tail_nodeport_nat_ingress_ipv4+0x19c4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x66d, 0x19c4, x86_l_19c4);
x86_l_673:
	/* 0x673: mov    cl,al */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_8);
x86_l_675:
	/* 0x675: mov    DWORD PTR [rsp+0x80],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_67c:
	/* 0x67c: jmp    690 <tail_nodeport_nat_ingress_ipv4+0x690> */
	X86_SIM_X86_JMP(0x67c, 0x690, x86_l_690);
x86_l_67e:
	/* 0x67e: mov    r13,r9 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R9, X86_WIDTH_64);
x86_l_681:
	/* 0x681: mov    DWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_68c:
	/* 0x68c: mov    ebp,DWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_690:
	/* 0x690: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_695:
	/* 0x695: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_69a:
	/* 0x69a: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_69d:
	/* 0x69d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_69f:
	/* 0x69f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6a2:
	/* 0x6a2: mov    r9,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_R13, X86_WIDTH_64);
x86_l_6a5:
	/* 0x6a5: je     986 <tail_nodeport_nat_ingress_ipv4+0x986> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6a5, 0x986, x86_l_986);
x86_l_6ab:
	/* 0x6ab: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_6ae:
	/* 0x6ae: mov    DWORD PTR [rsp+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6b2:
	/* 0x6b2: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_6b5:
	/* 0x6b5: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_6b7:
	/* 0x6b7: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_6b9:
	/* 0x6b9: test   cl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_6bc:
	/* 0x6bc: je     7cf <tail_nodeport_nat_ingress_ipv4+0x7cf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6bc, 0x7cf, x86_l_7cf);
x86_l_6c2:
	/* 0x6c2: mov    rdx,QWORD PTR [rip+0x30f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_6c9:
	/* 0x6c9: cmp    BYTE PTR [rdx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6cc:
	/* 0x6cc: je     6ea <tail_nodeport_nat_ingress_ipv4+0x6ea> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6cc, 0x6ea, x86_l_6ea);
x86_l_6ce:
	/* 0x6ce: mov    rcx,QWORD PTR [rip+0x30f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_6d5:
	/* 0x6d5: imul   r12d,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_6d9:
	/* 0x6d9: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_6dd:
	/* 0x6dd: jmp    6f0 <tail_nodeport_nat_ingress_ipv4+0x6f0> */
	X86_SIM_X86_JMP(0x6dd, 0x6f0, x86_l_6f0);
x86_l_6df:
	/* 0x6df: mov    r12d,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967161ULL);
x86_l_6e5:
	/* 0x6e5: jmp    1000 <tail_nodeport_nat_ingress_ipv4+0x1000> */
	X86_SIM_X86_JMP(0x6e5, 0x1000, x86_l_1000);
x86_l_6ea:
	/* 0x6ea: mov    r12d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 60ULL);
x86_l_6f0:
	/* 0x6f0: mov    ebp,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6f4:
	/* 0x6f4: cmp    WORD PTR [rsp+0x48],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 309237645318ULL);
x86_l_6fa:
	/* 0x6fa: jne    731 <tail_nodeport_nat_ingress_ipv4+0x731> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x6fa, 0x731, x86_l_731);
x86_l_6fc:
	/* 0x6fc: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_6fe:
	/* 0x6fe: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_700:
	/* 0x700: shr    ecx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_703:
	/* 0x703: and    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_706:
	/* 0x706: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_708:
	/* 0x708: mov    WORD PTR [rdi+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_70c:
	/* 0x70c: test   al,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 16ULL);
x86_l_70e:
	/* 0x70e: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_713:
	/* 0x713: mov    r12d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 21600ULL);
x86_l_719:
	/* 0x719: cmove  r12d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_71d:
	/* 0x71d: cmp    BYTE PTR [rdx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_720:
	/* 0x720: je     731 <tail_nodeport_nat_ingress_ipv4+0x731> */
	X86_SIM_X86_JCC(X86_CC_E, 0x720, 0x731, x86_l_731);
x86_l_722:
	/* 0x722: mov    rax,QWORD PTR [rip+0x30f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_729:
	/* 0x729: imul   r12d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_72d:
	/* 0x72d: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_731:
	/* 0x731: mov    r13,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDI, X86_WIDTH_64);
x86_l_734:
	/* 0x734: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_737:
	/* 0x737: cmp    BYTE PTR [rdx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_73a:
	/* 0x73a: je     74b <tail_nodeport_nat_ingress_ipv4+0x74b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x73a, 0x74b, x86_l_74b);
x86_l_73c:
	/* 0x73c: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_741:
	/* 0x741: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_743:
	/* 0x743: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_745:
	/* 0x745: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_749:
	/* 0x749: jmp    76e <tail_nodeport_nat_ingress_ipv4+0x76e> */
	X86_SIM_X86_JMP(0x749, 0x76e, x86_l_76e);
x86_l_74b:
	/* 0x74b: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_750:
	/* 0x750: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_752:
	/* 0x752: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_754:
	/* 0x754: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_758:
	/* 0x758: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_762:
	/* 0x762: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_765:
	/* 0x765: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_76a:
	/* 0x76a: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_76e:
	/* 0x76e: add    r12d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_771:
	/* 0x771: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_774:
	/* 0x774: mov    DWORD PTR [r13+0x20],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_778:
	/* 0x778: movzx  ecx,BYTE PTR [r13+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_77d:
	/* 0x77d: mov    edx,DWORD PTR [r13+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_781:
	/* 0x781: and    bpl,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_785:
	/* 0x785: mov    rsi,QWORD PTR [rip+0x30f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_78c:
	/* 0x78c: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_78f:
	/* 0x78f: movabs r9,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_64, 2199023255552ULL);
x86_l_799:
	/* 0x799: je     7ac <tail_nodeport_nat_ingress_ipv4+0x7ac> */
	X86_SIM_X86_JCC(X86_CC_E, 0x799, 0x7ac, x86_l_7ac);
x86_l_79b:
	/* 0x79b: mov    rsi,QWORD PTR [rip+0x30f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_7a2:
	/* 0x7a2: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7a4:
	/* 0x7a4: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_7a7:
	/* 0x7a7: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_7aa:
	/* 0x7aa: jmp    7b1 <tail_nodeport_nat_ingress_ipv4+0x7b1> */
	X86_SIM_X86_JMP(0x7aa, 0x7b1, x86_l_7b1);
x86_l_7ac:
	/* 0x7ac: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_7b1:
	/* 0x7b1: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_7b3:
	/* 0x7b3: or     bpl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_7b6:
	/* 0x7b6: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_7b8:
	/* 0x7b8: jb     7bf <tail_nodeport_nat_ingress_ipv4+0x7bf> */
	X86_SIM_X86_JCC(X86_CC_B, 0x7b8, 0x7bf, x86_l_7bf);
x86_l_7ba:
	/* 0x7ba: cmp    cl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_8);
x86_l_7bd:
	/* 0x7bd: je     7cf <tail_nodeport_nat_ingress_ipv4+0x7cf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7bd, 0x7cf, x86_l_7cf);
x86_l_7bf:
	/* 0x7bf: mov    BYTE PTR [rdi+0x2b],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_7c3:
	/* 0x7c3: mov    DWORD PTR [rdi+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_7c6:
	/* 0x7c6: mov    rax,QWORD PTR [rip+0x30f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_7cd:
	/* 0x7cd: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7cf:
	/* 0x7cf: mov    rax,QWORD PTR [rip+0x30f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_7d6:
	/* 0x7d6: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7d9:
	/* 0x7d9: je     7e8 <tail_nodeport_nat_ingress_ipv4+0x7e8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7d9, 0x7e8, x86_l_7e8);
x86_l_7db:
	/* 0x7db: inc QWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RDI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 16ULL);
x86_l_7e0:
	/* 0x7e0: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_7e3:
	/* 0x7e3: add QWORD PTR [rdi+0x18],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RDI, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_7e8:
	/* 0x7e8: mov    ecx,DWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_7ef:
	/* 0x7ef: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_7f2:
	/* 0x7f2: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7f6:
	/* 0x7f6: je     844 <tail_nodeport_nat_ingress_ipv4+0x844> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7f6, 0x844, x86_l_844);
x86_l_7f8:
	/* 0x7f8: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_7fb:
	/* 0x7fb: jne    98f <tail_nodeport_nat_ingress_ipv4+0x98f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x7fb, 0x98f, x86_l_98f);
x86_l_801:
	/* 0x801: movzx  eax,WORD PTR [rdi+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_805:
	/* 0x805: test   al,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 3ULL);
x86_l_807:
	/* 0x807: je     98f <tail_nodeport_nat_ingress_ipv4+0x98f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x807, 0x98f, x86_l_98f);
x86_l_80d:
	/* 0x80d: mov    WORD PTR [rdi+0x2a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 180388626432ULL);
x86_l_813:
	/* 0x813: and    eax,0xffec */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 65516ULL);
x86_l_818:
	/* 0x818: mov    r13,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDI, X86_WIDTH_64);
x86_l_81b:
	/* 0x81b: mov    WORD PTR [rdi+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_81f:
	/* 0x81f: mov    rbp,QWORD PTR [rip+0x30f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBP, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_826:
	/* 0x826: cmp    BYTE PTR [rbp+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_82a:
	/* 0x82a: je     1a58 <tail_nodeport_nat_ingress_ipv4+0x1a58> */
	X86_SIM_X86_JCC(X86_CC_E, 0x82a, 0x1a58, x86_l_1a58);
x86_l_830:
	/* 0x830: mov    rcx,QWORD PTR [rip+0x30f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_837:
	/* 0x837: imul   r12d,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_83b:
	/* 0x83b: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_83f:
	/* 0x83f: jmp    1a5e <tail_nodeport_nat_ingress_ipv4+0x1a5e> */
	X86_SIM_X86_JMP(0x83f, 0x1a5e, x86_l_1a5e);
x86_l_844:
	/* 0x844: shr    eax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_847:
	/* 0x847: and    eax,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2ULL);
x86_l_84a:
	/* 0x84a: or     ax,WORD PTR [rdi+0x24] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RDI, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 36ULL);
x86_l_84e:
	/* 0x84e: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_850:
	/* 0x850: or     ecx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_OR, 1ULL);
x86_l_853:
	/* 0x853: mov    WORD PTR [rdi+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_857:
	/* 0x857: mov    rcx,QWORD PTR [rip+0x30f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_85e:
	/* 0x85e: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_860:
	/* 0x860: test   al,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 2ULL);
x86_l_862:
	/* 0x862: je     98f <tail_nodeport_nat_ingress_ipv4+0x98f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x862, 0x98f, x86_l_98f);
x86_l_868:
	/* 0x868: mov    rcx,QWORD PTR [rip+0x30f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_86f:
	/* 0x86f: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_872:
	/* 0x872: je     8e8 <tail_nodeport_nat_ingress_ipv4+0x8e8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x872, 0x8e8, x86_l_8e8);
x86_l_874:
	/* 0x874: mov    rax,QWORD PTR [rip+0x30f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_87b:
	/* 0x87b: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_87d:
	/* 0x87d: add    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_87f:
	/* 0x87f: lea    ebp,[rax+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_882:
	/* 0x882: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_885:
	/* 0x885: jmp    8ed <tail_nodeport_nat_ingress_ipv4+0x8ed> */
	X86_SIM_X86_JMP(0x885, 0x8ed, x86_l_8ed);
x86_l_887:
	/* 0x887: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_88c:
	/* 0x88c: lea    rdx,[rsp+0x67] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103ULL);
x86_l_891:
	/* 0x891: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_894:
	/* 0x894: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_897:
	/* 0x897: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_89c:
	/* 0x89c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_89e:
	/* 0x89e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_8a0:
	/* 0x8a0: js     8dd <tail_nodeport_nat_ingress_ipv4+0x8dd> */
	X86_SIM_X86_JCC(X86_CC_S, 0x8a0, 0x8dd, x86_l_8dd);
x86_l_8a2:
	/* 0x8a2: movzx  eax,BYTE PTR [rsp+0x67] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 103ULL);
x86_l_8a7:
	/* 0x8a7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_8a9:
	/* 0x8a9: je     1000 <tail_nodeport_nat_ingress_ipv4+0x1000> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8a9, 0x1000, x86_l_1000);
x86_l_8af:
	/* 0x8af: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_8b2:
	/* 0x8b2: jne    11ea <tail_nodeport_nat_ingress_ipv4+0x11ea> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x8b2, 0x11ea, x86_l_11ea);
x86_l_8b8:
	/* 0x8b8: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_8bd:
	/* 0x8bd: lea    esi,[r13+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_8c1:
	/* 0x8c1: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8c6:
	/* 0x8c6: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_8c9:
	/* 0x8c9: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_8ce:
	/* 0x8ce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8d0:
	/* 0x8d0: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_8d5:
	/* 0x8d5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_8d7:
	/* 0x8d7: jns    433 <tail_nodeport_nat_ingress_ipv4+0x433> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x8d7, 0x433, x86_l_433);
x86_l_8dd:
	/* 0x8dd: mov    r12d,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967162ULL);
x86_l_8e3:
	/* 0x8e3: jmp    1000 <tail_nodeport_nat_ingress_ipv4+0x1000> */
	X86_SIM_X86_JMP(0x8e3, 0x1000, x86_l_1000);
x86_l_8e8:
	/* 0x8e8: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_8ed:
	/* 0x8ed: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_8f0:
	/* 0x8f0: mov    r13,r9 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R9, X86_WIDTH_64);
x86_l_8f3:
	/* 0x8f3: shr    DWORD PTR [rsp+0x20],0x8 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_32, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_SHR)), 137438953480ULL);
x86_l_8f8:
	/* 0x8f8: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8fb:
	/* 0x8fb: je     90c <tail_nodeport_nat_ingress_ipv4+0x90c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8fb, 0x90c, x86_l_90c);
x86_l_8fd:
	/* 0x8fd: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_902:
	/* 0x902: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_904:
	/* 0x904: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_906:
	/* 0x906: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_90a:
	/* 0x90a: jmp    92f <tail_nodeport_nat_ingress_ipv4+0x92f> */
	X86_SIM_X86_JMP(0x90a, 0x92f, x86_l_92f);
x86_l_90c:
	/* 0x90c: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_911:
	/* 0x911: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_913:
	/* 0x913: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_915:
	/* 0x915: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_919:
	/* 0x919: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_923:
	/* 0x923: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_926:
	/* 0x926: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_92b:
	/* 0x92b: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_92f:
	/* 0x92f: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_931:
	/* 0x931: mov    DWORD PTR [r12+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_936:
	/* 0x936: movzx  ecx,BYTE PTR [r12+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_93c:
	/* 0x93c: mov    edx,DWORD PTR [r12+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_941:
	/* 0x941: mov    edi,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_945:
	/* 0x945: and    dil,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_949:
	/* 0x949: mov    rsi,QWORD PTR [rip+0x30f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_950:
	/* 0x950: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_953:
	/* 0x953: mov    r9,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_R13, X86_WIDTH_64);
x86_l_956:
	/* 0x956: je     969 <tail_nodeport_nat_ingress_ipv4+0x969> */
	X86_SIM_X86_JCC(X86_CC_E, 0x956, 0x969, x86_l_969);
x86_l_958:
	/* 0x958: mov    rsi,QWORD PTR [rip+0x30f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_95f:
	/* 0x95f: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_961:
	/* 0x961: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_964:
	/* 0x964: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_967:
	/* 0x967: jmp    96e <tail_nodeport_nat_ingress_ipv4+0x96e> */
	X86_SIM_X86_JMP(0x967, 0x96e, x86_l_96e);
x86_l_969:
	/* 0x969: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_96e:
	/* 0x96e: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_970:
	/* 0x970: or     dil,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_973:
	/* 0x973: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_975:
	/* 0x975: jb     97c <tail_nodeport_nat_ingress_ipv4+0x97c> */
	X86_SIM_X86_JCC(X86_CC_B, 0x975, 0x97c, x86_l_97c);
x86_l_977:
	/* 0x977: cmp    cl,dil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDI, X86_WIDTH_8);
x86_l_97a:
	/* 0x97a: je     98f <tail_nodeport_nat_ingress_ipv4+0x98f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x97a, 0x98f, x86_l_98f);
x86_l_97c:
	/* 0x97c: mov    BYTE PTR [r12+0x2b],dil */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RDI, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_981:
	/* 0x981: mov    DWORD PTR [r12+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_986:
	/* 0x986: mov    rax,QWORD PTR [rip+0x30f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_98d:
	/* 0x98d: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_98f:
	/* 0x98f: movzx  ebp,WORD PTR [r15+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_994:
	/* 0x994: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_996:
	/* 0x996: movzx  r13d,BYTE PTR [rsp+0x3c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 60ULL);
x86_l_99c:
	/* 0x99c: mov    rax,QWORD PTR [rip+0x30f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_9a3:
	/* 0x9a3: movzx  r12d,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_9a7:
	/* 0x9a7: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9ab:
	/* 0x9ab: mov    r15d,DWORD PTR [r15+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9af:
	/* 0x9af: movzx  ecx,WORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_9b4:
	/* 0x9b4: mov    DWORD PTR [rsp+0x90],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_9bc:
	/* 0x9bc: cmp    eax,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_9bf:
	/* 0x9bf: jne    9ce <tail_nodeport_nat_ingress_ipv4+0x9ce> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x9bf, 0x9ce, x86_l_9ce);
x86_l_9c1:
	/* 0x9c1: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_9c3:
	/* 0x9c3: jne    9ce <tail_nodeport_nat_ingress_ipv4+0x9ce> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x9c3, 0x9ce, x86_l_9ce);
x86_l_9c5:
	/* 0x9c5: cmp    cx,bp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_16);
x86_l_9c8:
	/* 0x9c8: je     b7e <tail_nodeport_nat_ingress_ipv4+0xb7e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9c8, 0xb7e, x86_l_b7e);
x86_l_9ce:
	/* 0x9ce: mov    DWORD PTR [rsp+0x20],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9d2:
	/* 0x9d2: mov    DWORD PTR [rsp+0x48],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_9d6:
	/* 0x9d6: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_9d8:
	/* 0x9d8: add    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_9db:
	/* 0x9db: adc    r15d,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_9df:
	/* 0x9df: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_9e4:
	/* 0x9e4: lea    esi,[r12+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9e9:
	/* 0x9e9: lea    rdx,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_9f1:
	/* 0x9f1: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_9f4:
	/* 0x9f4: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_9f9:
	/* 0x9f9: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9fc:
	/* 0x9fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9fe:
	/* 0x9fe: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a00:
	/* 0xa00: js     ff2 <tail_nodeport_nat_ingress_ipv4+0xff2> */
	X86_SIM_X86_JCC(X86_CC_S, 0xa00, 0xff2, x86_l_ff2);
x86_l_a06:
	/* 0xa06: add    r12d,0xa */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_ADD, 10ULL);
x86_l_a0a:
	/* 0xa0a: mov    eax,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_a0f:
	/* 0xa0f: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_a12:
	/* 0xa12: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_a15:
	/* 0xa15: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a17:
	/* 0xa17: mov    ecx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_32);
x86_l_a1a:
	/* 0xa1a: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a1d:
	/* 0xa1d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a1f:
	/* 0xa1f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a21:
	/* 0xa21: js     ffa <tail_nodeport_nat_ingress_ipv4+0xffa> */
	X86_SIM_X86_JCC(X86_CC_S, 0xa21, 0xffa, x86_l_ffa);
x86_l_a27:
	/* 0xa27: movabs r9,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_64, 2199023255552ULL);
x86_l_a31:
	/* 0xa31: test   r14,r9 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R9, X86_WIDTH_64);
x86_l_a34:
	/* 0xa34: mov    ecx,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_a38:
	/* 0xa38: mov    edx,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a3c:
	/* 0xa3c: jne    b7e <tail_nodeport_nat_ingress_ipv4+0xb7e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa3c, 0xb7e, x86_l_b7e);
x86_l_a42:
	/* 0xa42: mov    eax,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_a45:
	/* 0xa45: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a48:
	/* 0xa48: cmp    r13d,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 58ULL);
x86_l_a4c:
	/* 0xa4c: je     a71 <tail_nodeport_nat_ingress_ipv4+0xa71> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa4c, 0xa71, x86_l_a71);
x86_l_a4e:
	/* 0xa4e: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_a51:
	/* 0xa51: mov    r8,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_a56:
	/* 0xa56: je     a64 <tail_nodeport_nat_ingress_ipv4+0xa64> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa56, 0xa64, x86_l_a64);
x86_l_a58:
	/* 0xa58: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_a5b:
	/* 0xa5b: jne    a7d <tail_nodeport_nat_ingress_ipv4+0xa7d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa5b, 0xa7d, x86_l_a7d);
x86_l_a5d:
	/* 0xa5d: mov    r14w,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_16, 16ULL);
x86_l_a62:
	/* 0xa62: jmp    a80 <tail_nodeport_nat_ingress_ipv4+0xa80> */
	X86_SIM_X86_JMP(0xa62, 0xa80, x86_l_a80);
x86_l_a64:
	/* 0xa64: mov    r12d,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 32ULL);
x86_l_a6a:
	/* 0xa6a: mov    r14w,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_16, 6ULL);
x86_l_a6f:
	/* 0xa6f: jmp    a80 <tail_nodeport_nat_ingress_ipv4+0xa80> */
	X86_SIM_X86_JMP(0xa6f, 0xa80, x86_l_a80);
x86_l_a71:
	/* 0xa71: mov    r14w,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_16, 2ULL);
x86_l_a76:
	/* 0xa76: mov    r8,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_a7b:
	/* 0xa7b: jmp    a80 <tail_nodeport_nat_ingress_ipv4+0xa80> */
	X86_SIM_X86_JMP(0xa7b, 0xa80, x86_l_a80);
x86_l_a7d:
	/* 0xa7d: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a80:
	/* 0xa80: cmp    dx,bp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBP, X86_WIDTH_16);
x86_l_a83:
	/* 0xa83: jne    aaf <tail_nodeport_nat_ingress_ipv4+0xaaf> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa83, 0xaaf, x86_l_aaf);
x86_l_a85:
	/* 0xa85: test   r14w,r14w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_16);
x86_l_a89:
	/* 0xa89: je     b51 <tail_nodeport_nat_ingress_ipv4+0xb51> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa89, 0xb51, x86_l_b51);
x86_l_a8f:
	/* 0xa8f: movzx  eax,r14w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R14, X86_WIDTH_32, X86_WIDTH_16);
x86_l_a93:
	/* 0xa93: add    r8d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_a96:
	/* 0xa96: or     r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_OR, 16ULL);
x86_l_a9a:
	/* 0xa9a: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_a9f:
	/* 0xa9f: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_aa2:
	/* 0xaa2: mov    esi,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R8, X86_WIDTH_32);
x86_l_aa5:
	/* 0xaa5: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_aa7:
	/* 0xaa7: mov    ecx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_32);
x86_l_aaa:
	/* 0xaaa: jmp    b67 <tail_nodeport_nat_ingress_ipv4+0xb67> */
	X86_SIM_X86_JMP(0xaaa, 0xb67, x86_l_b67);
x86_l_aaf:
	/* 0xaaf: mov    DWORD PTR [rsp+0x80],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_ab7:
	/* 0xab7: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_aba:
	/* 0xaba: je     ad5 <tail_nodeport_nat_ingress_ipv4+0xad5> */
	X86_SIM_X86_JCC(X86_CC_E, 0xaba, 0xad5, x86_l_ad5);
x86_l_abc:
	/* 0xabc: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_abf:
	/* 0xabf: je     ad5 <tail_nodeport_nat_ingress_ipv4+0xad5> */
	X86_SIM_X86_JCC(X86_CC_E, 0xabf, 0xad5, x86_l_ad5);
x86_l_ac1:
	/* 0xac1: mov    r12d,0xffffff72 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967154ULL);
x86_l_ac7:
	/* 0xac7: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_aca:
	/* 0xaca: jne    1000 <tail_nodeport_nat_ingress_ipv4+0x1000> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xaca, 0x1000, x86_l_1000);
x86_l_ad0:
	/* 0xad0: mov    r14w,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_16, 2ULL);
x86_l_ad5:
	/* 0xad5: mov    WORD PTR [rsp+0x8],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ada:
	/* 0xada: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_adf:
	/* 0xadf: mov    esi,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_ae3:
	/* 0xae3: add    esi,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R8, X86_WIDTH_32, X86_ALU_ADD);
x86_l_ae6:
	/* 0xae6: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_aeb:
	/* 0xaeb: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_aee:
	/* 0xaee: mov    r12,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R8, X86_WIDTH_64);
x86_l_af1:
	/* 0xaf1: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_af6:
	/* 0xaf6: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_af9:
	/* 0xaf9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_afb:
	/* 0xafb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_afd:
	/* 0xafd: js     ff2 <tail_nodeport_nat_ingress_ipv4+0xff2> */
	X86_SIM_X86_JCC(X86_CC_S, 0xafd, 0xff2, x86_l_ff2);
x86_l_b03:
	/* 0xb03: movzx  ecx,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_b08:
	/* 0xb08: movzx  esi,r14w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_R14, X86_WIDTH_32, X86_WIDTH_16);
x86_l_b0c:
	/* 0xb0c: add    esi,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R12, X86_WIDTH_32, X86_ALU_ADD);
x86_l_b0f:
	/* 0xb0f: mov    r12d,DWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_b17:
	/* 0xb17: mov    r8d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R12, X86_WIDTH_32);
x86_l_b1a:
	/* 0xb1a: or     r8d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_b1e:
	/* 0xb1e: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_b23:
	/* 0xb23: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_b26:
	/* 0xb26: mov    edx,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b2a:
	/* 0xb2a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b2c:
	/* 0xb2c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b2e:
	/* 0xb2e: js     e91 <tail_nodeport_nat_ingress_ipv4+0xe91> */
	X86_SIM_X86_JCC(X86_CC_S, 0xb2e, 0xe91, x86_l_e91);
x86_l_b34:
	/* 0xb34: cmp    r13d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 1ULL);
x86_l_b38:
	/* 0xb38: movabs r9,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_64, 2199023255552ULL);
x86_l_b42:
	/* 0xb42: mov    r8,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_b47:
	/* 0xb47: mov    ecx,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_b4b:
	/* 0xb4b: jne    a85 <tail_nodeport_nat_ingress_ipv4+0xa85> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb4b, 0xa85, x86_l_a85);
x86_l_b51:
	/* 0xb51: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_b53:
	/* 0xb53: je     b7e <tail_nodeport_nat_ingress_ipv4+0xb7e> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb53, 0xb7e, x86_l_b7e);
x86_l_b55:
	/* 0xb55: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_b5a:
	/* 0xb5a: add    esi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_b5d:
	/* 0xb5d: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_b62:
	/* 0xb62: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_b65:
	/* 0xb65: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b67:
	/* 0xb67: mov    r8d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R12, X86_WIDTH_32);
x86_l_b6a:
	/* 0xb6a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b6c:
	/* 0xb6c: movabs r9,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_64, 2199023255552ULL);
x86_l_b76:
	/* 0xb76: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b78:
	/* 0xb78: js     e91 <tail_nodeport_nat_ingress_ipv4+0xe91> */
	X86_SIM_X86_JCC(X86_CC_S, 0xb78, 0xe91, x86_l_e91);
x86_l_b7e:
	/* 0xb7e: mov    eax,0xfffff0ff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294963455ULL);
x86_l_b83:
	/* 0xb83: and    eax,DWORD PTR [rbx+0xa8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 168ULL);
x86_l_b89:
	/* 0xb89: or     eax,0x300 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 768ULL);
x86_l_b8e:
	/* 0xb8e: mov    DWORD PTR [rbx+0xa8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_b94:
	/* 0xb94: mov    QWORD PTR [rsp+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_ba0:
	/* 0xba0: mov    DWORD PTR [rsp+0xd0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 893353197568ULL);
x86_l_bab:
	/* 0xbab: mov    QWORD PTR [rsp+0xc8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 858993459200ULL);
x86_l_bb7:
	/* 0xbb7: mov    QWORD PTR [rsp+0xc0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_bc3:
	/* 0xbc3: mov    QWORD PTR [rsp+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_bcf:
	/* 0xbcf: mov    QWORD PTR [rsp+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_bdb:
	/* 0xbdb: mov    QWORD PTR [rsp+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_be7:
	/* 0xbe7: mov    QWORD PTR [rsp+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_bf3:
	/* 0xbf3: mov    QWORD PTR [rsp+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_bff:
	/* 0xbff: mov    BYTE PTR [rsp+0x90],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 618475290626ULL);
x86_l_c07:
	/* 0xc07: mov    rax,QWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c0b:
	/* 0xc0b: mov    ecx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 0ULL);
x86_l_c10:
	/* 0xc10: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c13:
	/* 0xc13: je     c1b <tail_nodeport_nat_ingress_ipv4+0xc1b> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc13, 0xc1b, x86_l_c1b);
x86_l_c15:
	/* 0xc15: mov    ecx,DWORD PTR [rax+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_c1b:
	/* 0xc1b: mov    DWORD PTR [rsp+0x98],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_c22:
	/* 0xc22: mov    r8,QWORD PTR [rip+0x30f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R8, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_c29:
	/* 0xc29: movzx  r11d,BYTE PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_c2d:
	/* 0xc2d: mov    QWORD PTR [rsp+0x36],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 231928233984ULL);
x86_l_c36:
	/* 0xc36: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_c3f:
	/* 0xc3f: mov    rax,QWORD PTR [rip+0x30f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_security_label)));
x86_l_c46:
	/* 0xc46: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c48:
	/* 0xc48: movzx  ecx,BYTE PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_c4c:
	/* 0xc4c: mov    rax,QWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_c53:
	/* 0xc53: mov    edx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_c56:
	/* 0xc56: sub    edx,DWORD PTR [rbx+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_c59:
	/* 0xc59: add    rdx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_c5c:
	/* 0xc5c: lea    rsi,[rax+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_c60:
	/* 0xc60: add    rsi,0x14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 20ULL);
x86_l_c64:
	/* 0xc64: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_c67:
	/* 0xc67: movabs r10,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R10, X86_WIDTH_64, 1099511627776ULL);
x86_l_c71:
	/* 0xc71: jbe    c85 <tail_nodeport_nat_ingress_ipv4+0xc85> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xc71, 0xc85, x86_l_c85);
x86_l_c73:
	/* 0xc73: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c75:
	/* 0xc75: mov    r12d,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967162ULL);
x86_l_c7b:
	/* 0xc7b: mov    r13d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_c80:
	/* 0xc80: jmp    1041 <tail_nodeport_nat_ingress_ipv4+0x1041> */
	X86_SIM_X86_JMP(0xc80, 0x1041, x86_l_1041);
x86_l_c85:
	/* 0xc85: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_c88:
	/* 0xc88: movzx  edx,WORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_c8c:
	/* 0xc8c: movzx  ecx,BYTE PTR [rax+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_c90:
	/* 0xc90: mov    rsi,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RCX, X86_WIDTH_64);
x86_l_c93:
	/* 0xc93: shl    rsi,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_c97:
	/* 0xc97: or     rsi,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_64, X86_ALU_OR);
x86_l_c9a:
	/* 0xc9a: movzx  edx,WORD PTR [rax+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_c9e:
	/* 0xc9e: mov    rdi,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSI, X86_WIDTH_64);
x86_l_ca1:
	/* 0xca1: mov    r14,r10 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R10, X86_WIDTH_64);
x86_l_ca4:
	/* 0xca4: or     rdi,r10 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R10, X86_WIDTH_64, X86_ALU_OR);
x86_l_ca7:
	/* 0xca7: test   edx,0xff3f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_32, 65343ULL);
x86_l_cad:
	/* 0xcad: cmove  rdi,rsi */
	X86_SIM_L_EXEC_CMOV(X86_RDI, X86_RSI, X86_WIDTH_64, X86_CC_E);
x86_l_cb1:
	/* 0xcb1: mov    r15,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDI, X86_WIDTH_64);
x86_l_cb4:
	/* 0xcb4: or     r15,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R9, X86_WIDTH_64, X86_ALU_OR);
x86_l_cb7:
	/* 0xcb7: test   edx,0xff1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_32, 65311ULL);
x86_l_cbd:
	/* 0xcbd: cmove  r15,rdi */
	X86_SIM_L_EXEC_CMOV(X86_R15, X86_RDI, X86_WIDTH_64, X86_CC_E);
x86_l_cc1:
	/* 0xcc1: movzx  esi,BYTE PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_cc5:
	/* 0xcc5: mov    edi,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cc7:
	/* 0xcc7: mov    BYTE PTR [rsp+0x3c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_ccb:
	/* 0xccb: mov    edx,DWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_cce:
	/* 0xcce: mov    DWORD PTR [rsp+0x30],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_cd2:
	/* 0xcd2: mov    eax,DWORD PTR [rax+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_cd5:
	/* 0xcd5: mov    DWORD PTR [rsp+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_cd9:
	/* 0xcd9: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_cdc:
	/* 0xcdc: je     ce7 <tail_nodeport_nat_ingress_ipv4+0xce7> */
	X86_SIM_X86_JCC(X86_CC_E, 0xcdc, 0xce7, x86_l_ce7);
x86_l_cde:
	/* 0xcde: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_ce1:
	/* 0xce1: jne    1c54 <tail_nodeport_nat_ingress_ipv4+0x1c54> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xce1, 0x1c54, x86_l_1c54);
x86_l_ce7:
	/* 0xce7: mov    QWORD PTR [rsp+0x48],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_cec:
	/* 0xcec: and    edi,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_cef:
	/* 0xcef: lea    ecx,[rsi+rdi*4] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_cf2:
	/* 0xcf2: mov    QWORD PTR [rsp+0x50],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_cf7:
	/* 0xcf7: lea    r12,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_cfc:
	/* 0xcfc: mov    rbp,QWORD PTR [rip+0x30f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBP, (void *)(long)(((__u64)(long)&__config_enable_ipv4_fragments)));
x86_l_d03:
	/* 0xd03: cmp    BYTE PTR [rbp+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d07:
	/* 0xd07: je     dcb <tail_nodeport_nat_ingress_ipv4+0xdcb> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd07, 0xdcb, x86_l_dcb);
x86_l_d0d:
	/* 0xd0d: mov    DWORD PTR [rsp+0x68],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_d11:
	/* 0xd11: mov    DWORD PTR [rsp+0x6c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_d15:
	/* 0xd15: mov    WORD PTR [rsp+0x70],r15w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_d1b:
	/* 0xd1b: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_d1e:
	/* 0xd1e: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_d22:
	/* 0xd22: mov    BYTE PTR [rsp+0x72],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 114ULL);
x86_l_d26:
	/* 0xd26: mov    BYTE PTR [rsp+0x73],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 493921239040ULL);
x86_l_d2b:
	/* 0xd2b: mov    r13,r9 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R9, X86_WIDTH_64);
x86_l_d2e:
	/* 0xd2e: test   r15,r9 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R9, X86_WIDTH_64);
x86_l_d31:
	/* 0xd31: jne    1a26 <tail_nodeport_nat_ingress_ipv4+0x1a26> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xd31, 0x1a26, x86_l_1a26);
x86_l_d37:
	/* 0xd37: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_d3c:
	/* 0xd3c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_d3f:
	/* 0xd3f: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_d44:
	/* 0xd44: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_d47:
	/* 0xd47: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_d4c:
	/* 0xd4c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d4e:
	/* 0xd4e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_d50:
	/* 0xd50: js     e08 <tail_nodeport_nat_ingress_ipv4+0xe08> */
	X86_SIM_X86_JCC(X86_CC_S, 0xd50, 0xe08, x86_l_e08);
x86_l_d56:
	/* 0xd56: test   r15,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R14, X86_WIDTH_64);
x86_l_d59:
	/* 0xd59: je     df2 <tail_nodeport_nat_ingress_ipv4+0xdf2> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd59, 0xdf2, x86_l_df2);
x86_l_d5f:
	/* 0xd5f: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_d64:
	/* 0xd64: mov    rdi,QWORD PTR [rip+0x30f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv4_frag_datagrams)));
x86_l_d6b:
	/* 0xd6b: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_d70:
	/* 0xd70: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_d73:
	/* 0xd73: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d75:
	/* 0xd75: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d77:
	/* 0xd77: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_d79:
	/* 0xd79: je     df2 <tail_nodeport_nat_ingress_ipv4+0xdf2> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd79, 0xdf2, x86_l_df2);
x86_l_d7b:
	/* 0xd7b: mov    r12d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_d7f:
	/* 0xd7f: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_d88:
	/* 0xd88: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_d91:
	/* 0xd91: movabs rax,0x6b0085010a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 459570217226ULL);
x86_l_d9b:
	/* 0xd9b: add    rax,0x100 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 256ULL);
x86_l_da1:
	/* 0xda1: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_da6:
	/* 0xda6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_dab:
	/* 0xdab: mov    rdi,QWORD PTR [rip+0x30f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_db2:
	/* 0xdb2: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_db7:
	/* 0xdb7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_db9:
	/* 0xdb9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_dbc:
	/* 0xdbc: je     1b57 <tail_nodeport_nat_ingress_ipv4+0x1b57> */
	X86_SIM_X86_JCC(X86_CC_E, 0xdbc, 0x1b57, x86_l_1b57);
x86_l_dc2:
	/* 0xdc2: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_dc5:
	/* 0xdc5: add    QWORD PTR [rax+0x8],r12 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_dc9:
	/* 0xdc9: jmp    df2 <tail_nodeport_nat_ingress_ipv4+0xdf2> */
	X86_SIM_X86_JMP(0xdc9, 0xdf2, x86_l_df2);
x86_l_dcb:
	/* 0xdcb: test   r15,r9 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R9, X86_WIDTH_64);
x86_l_dce:
	/* 0xdce: jne    1a4d <tail_nodeport_nat_ingress_ipv4+0x1a4d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xdce, 0x1a4d, x86_l_1a4d);
x86_l_dd4:
	/* 0xdd4: mov    r13,r9 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R9, X86_WIDTH_64);
x86_l_dd7:
	/* 0xdd7: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_ddc:
	/* 0xddc: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_ddf:
	/* 0xddf: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_de4:
	/* 0xde4: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_de7:
	/* 0xde7: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_dec:
	/* 0xdec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dee:
	/* 0xdee: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_df0:
	/* 0xdf0: js     e08 <tail_nodeport_nat_ingress_ipv4+0xe08> */
	X86_SIM_X86_JCC(X86_CC_S, 0xdf0, 0xe08, x86_l_e08);
x86_l_df2:
	/* 0xdf2: movzx  eax,BYTE PTR [rsp+0x3c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 60ULL);
x86_l_df7:
	/* 0xdf7: mov    BYTE PTR [rsp+0x40],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_dfb:
	/* 0xdfb: cmp    al,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 6ULL);
x86_l_dfd:
	/* 0xdfd: jne    e1a <tail_nodeport_nat_ingress_ipv4+0xe1a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xdfd, 0xe1a, x86_l_e1a);
x86_l_dff:
	/* 0xdff: mov    r12,QWORD PTR [rip+0x30f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&cilium_ct4_global)));
x86_l_e06:
	/* 0xe06: jmp    e21 <tail_nodeport_nat_ingress_ipv4+0xe21> */
	X86_SIM_X86_JMP(0xe06, 0xe21, x86_l_e21);
x86_l_e08:
	/* 0xe08: mov    r12d,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967161ULL);
x86_l_e0e:
	/* 0xe0e: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e10:
	/* 0xe10: mov    r13d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_e15:
	/* 0xe15: jmp    1041 <tail_nodeport_nat_ingress_ipv4+0x1041> */
	X86_SIM_X86_JMP(0xe15, 0x1041, x86_l_1041);
x86_l_e1a:
	/* 0xe1a: mov    r12,QWORD PTR [rip+0x30f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&cilium_ct_any4_global)));
x86_l_e21:
	/* 0xe21: mov    BYTE PTR [rsp+0x3d],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 261993005056ULL);
x86_l_e26:
	/* 0xe26: mov    DWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_e2e:
	/* 0xe2e: cmp    BYTE PTR [rbp+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e32:
	/* 0xe32: je     112d <tail_nodeport_nat_ingress_ipv4+0x112d> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe32, 0x112d, x86_l_112d);
x86_l_e38:
	/* 0xe38: and    r14,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_e3b:
	/* 0xe3b: je     112d <tail_nodeport_nat_ingress_ipv4+0x112d> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe3b, 0x112d, x86_l_112d);
x86_l_e41:
	/* 0xe41: mov    rbp,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R13, X86_WIDTH_64);
x86_l_e44:
	/* 0xe44: mov    r13d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_e48:
	/* 0xe48: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_e51:
	/* 0xe51: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_e5a:
	/* 0xe5a: movabs rax,0x6c03a50109 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 463917613321ULL);
x86_l_e64:
	/* 0xe64: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_e69:
	/* 0xe69: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e6e:
	/* 0xe6e: mov    rdi,QWORD PTR [rip+0x30f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_e75:
	/* 0xe75: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_e7a:
	/* 0xe7a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e7c:
	/* 0xe7c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e7f:
	/* 0xe7f: je     1102 <tail_nodeport_nat_ingress_ipv4+0x1102> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe7f, 0x1102, x86_l_1102);
x86_l_e85:
	/* 0xe85: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_e88:
	/* 0xe88: add    QWORD PTR [rax+0x8],r13 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_e8c:
	/* 0xe8c: jmp    112a <tail_nodeport_nat_ingress_ipv4+0x112a> */
	X86_SIM_X86_JMP(0xe8c, 0x112a, x86_l_112a);
x86_l_e91:
	/* 0xe91: mov    r12d,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967142ULL);
x86_l_e97:
	/* 0xe97: jmp    1000 <tail_nodeport_nat_ingress_ipv4+0x1000> */
	X86_SIM_X86_JMP(0xe97, 0x1000, x86_l_1000);
x86_l_e9c:
	/* 0xe9c: mov    WORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_ea3:
	/* 0xea3: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_ea8:
	/* 0xea8: lea    esi,[r13+0x6] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_eac:
	/* 0xeac: lea    rdx,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_eb1:
	/* 0xeb1: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_eb4:
	/* 0xeb4: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_eb9:
	/* 0xeb9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ebb:
	/* 0xebb: cmp    WORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_ec1:
	/* 0xec1: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_ec4:
	/* 0xec4: mov    sil,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_8, 1ULL);
x86_l_ec7:
	/* 0xec7: mov    r12d,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967162ULL);
x86_l_ecd:
	/* 0xecd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ecf:
	/* 0xecf: jns    ed9 <tail_nodeport_nat_ingress_ipv4+0xed9> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xecf, 0xed9, x86_l_ed9);
x86_l_ed1:
	/* 0xed1: jmp    1000 <tail_nodeport_nat_ingress_ipv4+0x1000> */
	X86_SIM_X86_JMP(0xed1, 0x1000, x86_l_1000);
x86_l_ed6:
	/* 0xed6: mov    sil,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_8, 1ULL);
x86_l_ed9:
	/* 0xed9: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_edd:
	/* 0xedd: mov    ebp,DWORD PTR [r15+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ee1:
	/* 0xee1: movzx  edi,WORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_ee6:
	/* 0xee6: movzx  r8d,WORD PTR [r15+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_eeb:
	/* 0xeeb: test   sil,sil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_8);
x86_l_eee:
	/* 0xeee: mov    QWORD PTR [rsp+0x80],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_ef6:
	/* 0xef6: je     f0a <tail_nodeport_nat_ingress_ipv4+0xf0a> */
	X86_SIM_X86_JCC(X86_CC_E, 0xef6, 0xf0a, x86_l_f0a);
x86_l_ef8:
	/* 0xef8: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_efa:
	/* 0xefa: je     f0a <tail_nodeport_nat_ingress_ipv4+0xf0a> */
	X86_SIM_X86_JCC(X86_CC_E, 0xefa, 0xf0a, x86_l_f0a);
x86_l_efc:
	/* 0xefc: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_efe:
	/* 0xefe: cmp    eax,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_f00:
	/* 0xf00: je     f1f <tail_nodeport_nat_ingress_ipv4+0xf1f> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf00, 0xf1f, x86_l_f1f);
x86_l_f02:
	/* 0xf02: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_f04:
	/* 0xf04: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_f06:
	/* 0xf06: add    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_f08:
	/* 0xf08: jmp    f1c <tail_nodeport_nat_ingress_ipv4+0xf1c> */
	X86_SIM_X86_JMP(0xf08, 0xf1c, x86_l_f1c);
x86_l_f0a:
	/* 0xf0a: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f0c:
	/* 0xf0c: cmp    di,r8w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_R8, X86_WIDTH_16);
x86_l_f10:
	/* 0xf10: je     f1f <tail_nodeport_nat_ingress_ipv4+0xf1f> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf10, 0xf1f, x86_l_f1f);
x86_l_f12:
	/* 0xf12: movzx  ecx,r8w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R8, X86_WIDTH_32, X86_WIDTH_16);
x86_l_f16:
	/* 0xf16: mov    edx,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_32);
x86_l_f18:
	/* 0xf18: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_f1a:
	/* 0xf1a: add    edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_f1c:
	/* 0xf1c: adc    edx,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_f1f:
	/* 0xf1f: movzx  ecx,BYTE PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 20ULL);
x86_l_f24:
	/* 0xf24: mov    DWORD PTR [rsp+0x58],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_f28:
	/* 0xf28: cmp    eax,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_f2a:
	/* 0xf2a: jne    f4b <tail_nodeport_nat_ingress_ipv4+0xf4b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf2a, 0xf4b, x86_l_f4b);
x86_l_f2c:
	/* 0xf2c: cmp    di,r8w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_R8, X86_WIDTH_16);
x86_l_f30:
	/* 0xf30: jne    f4b <tail_nodeport_nat_ingress_ipv4+0xf4b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf30, 0xf4b, x86_l_f4b);
x86_l_f32:
	/* 0xf32: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f34:
	/* 0xf34: mov    DWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_f3c:
	/* 0xf3c: movabs r9,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_64, 2199023255552ULL);
x86_l_f46:
	/* 0xf46: jmp    996 <tail_nodeport_nat_ingress_ipv4+0x996> */
	X86_SIM_X86_JMP(0xf46, 0x996, x86_l_996);
x86_l_f4b:
	/* 0xf4b: mov    DWORD PTR [rsp+0x8c],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_f52:
	/* 0xf52: mov    r13d,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R8, X86_WIDTH_32);
x86_l_f55:
	/* 0xf55: mov    DWORD PTR [rsp+0x40],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_f59:
	/* 0xf59: mov    BYTE PTR [rsp+0x2f],sil */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 47ULL);
x86_l_f5e:
	/* 0xf5e: mov    DWORD PTR [rsp+0x48],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_f62:
	/* 0xf62: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_f64:
	/* 0xf64: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_f66:
	/* 0xf66: adc    ebp,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_f69:
	/* 0xf69: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_f6e:
	/* 0xf6e: mov    r12,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_f73:
	/* 0xf73: lea    esi,[r12+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_f78:
	/* 0xf78: lea    rdx,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_f7d:
	/* 0xf7d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_f80:
	/* 0xf80: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_f85:
	/* 0xf85: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f88:
	/* 0xf88: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f8a:
	/* 0xf8a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_f8c:
	/* 0xf8c: js     ff2 <tail_nodeport_nat_ingress_ipv4+0xff2> */
	X86_SIM_X86_JCC(X86_CC_S, 0xf8c, 0xff2, x86_l_ff2);
x86_l_f8e:
	/* 0xf8e: lea    esi,[r12+0x12] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_f93:
	/* 0xf93: mov    eax,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_f98:
	/* 0xf98: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_f9b:
	/* 0xf9b: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f9d:
	/* 0xf9d: mov    DWORD PTR [rsp+0x88],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_fa4:
	/* 0xfa4: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_fa6:
	/* 0xfa6: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_fa9:
	/* 0xfa9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fab:
	/* 0xfab: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_fad:
	/* 0xfad: js     ffa <tail_nodeport_nat_ingress_ipv4+0xffa> */
	X86_SIM_X86_JCC(X86_CC_S, 0xfad, 0xffa, x86_l_ffa);
x86_l_faf:
	/* 0xfaf: mov    esi,DWORD PTR [rsp+0x8c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_fb6:
	/* 0xfb6: cmp    esi,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 58ULL);
x86_l_fb9:
	/* 0xfb9: je     13a6 <tail_nodeport_nat_ingress_ipv4+0x13a6> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfb9, 0x13a6, x86_l_13a6);
x86_l_fbf:
	/* 0xfbf: cmp    esi,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_fc2:
	/* 0xfc2: mov    edx,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_fc6:
	/* 0xfc6: mov    ecx,DWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_fcd:
	/* 0xfcd: mov    eax,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_fd1:
	/* 0xfd1: je     1397 <tail_nodeport_nat_ingress_ipv4+0x1397> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfd1, 0x1397, x86_l_1397);
x86_l_fd7:
	/* 0xfd7: mov    DWORD PTR [rsp+0x7c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_fdf:
	/* 0xfdf: cmp    esi,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 6ULL);
x86_l_fe2:
	/* 0xfe2: jne    13c4 <tail_nodeport_nat_ingress_ipv4+0x13c4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xfe2, 0x13c4, x86_l_13c4);
x86_l_fe8:
	/* 0xfe8: mov    r12w,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_16, 16ULL);
x86_l_fed:
	/* 0xfed: jmp    13c7 <tail_nodeport_nat_ingress_ipv4+0x13c7> */
	X86_SIM_X86_JMP(0xfed, 0x13c7, x86_l_13c7);
x86_l_ff2:
	/* 0xff2: mov    r12d,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967155ULL);
x86_l_ff8:
	/* 0xff8: jmp    1000 <tail_nodeport_nat_ingress_ipv4+0x1000> */
	X86_SIM_X86_JMP(0xff8, 0x1000, x86_l_1000);
x86_l_ffa:
	/* 0xffa: mov    r12d,0xffffff67 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967143ULL);
x86_l_1000:
	/* 0x1000: mov    r13d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1005:
	/* 0x1005: cmp    r12d,0xffffff53 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4294967123ULL);
x86_l_100c:
	/* 0x100c: je     1019 <tail_nodeport_nat_ingress_ipv4+0x1019> */
	X86_SIM_X86_JCC(X86_CC_E, 0x100c, 0x1019, x86_l_1019);
x86_l_100e:
	/* 0x100e: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1010:
	/* 0x1010: cmp    r12d,0xffffff59 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4294967129ULL);
x86_l_1017:
	/* 0x1017: jne    1041 <tail_nodeport_nat_ingress_ipv4+0x1041> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1017, 0x1041, x86_l_1041);
x86_l_1019:
	/* 0x1019: or     BYTE PTR [rbx+0x86],0x4 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RBX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 575525617668ULL);
x86_l_1020:
	/* 0x1020: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1025:
	/* 0x1025: mov    rsi,QWORD PTR [rip+0x30f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_102c:
	/* 0x102c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_102f:
	/* 0x102f: mov    edx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_1034:
	/* 0x1034: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1036:
	/* 0x1036: mov    r12d,0xffffff74 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967156ULL);
x86_l_103c:
	/* 0x103c: mov    ebp,0x700 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1792ULL);
x86_l_1041:
	/* 0x1041: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_1044:
	/* 0x1044: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_1046:
	/* 0x1046: cmovs  eax,r12d */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_R12, X86_WIDTH_32, X86_CC_S);
x86_l_104a:
	/* 0x104a: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_104d:
	/* 0x104d: or     eax,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_32, X86_ALU_OR);
x86_l_104f:
	/* 0x104f: mov    DWORD PTR [rbx+0x28],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1053:
	/* 0x1053: mov    DWORD PTR [rbx+0x2c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561024ULL);
x86_l_105a:
	/* 0x105a: mov    DWORD PTR [rbx+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_105d:
	/* 0x105d: movabs rcx,0x9d9680200000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 709712774086787072ULL);
x86_l_1067:
	/* 0x1067: mov    QWORD PTR [rbx+0x34],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_106b:
	/* 0x106b: mov    r14d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_106f:
	/* 0x106f: movabs rcx,0x6809d90100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 446841815296ULL);
x86_l_1079:
	/* 0x1079: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_107e:
	/* 0x107e: mov    BYTE PTR [rsp+0x8],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1082:
	/* 0x1082: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1087:
	/* 0x1087: mov    rdi,QWORD PTR [rip+0x30f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_108e:
	/* 0x108e: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1093:
	/* 0x1093: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1095:
	/* 0x1095: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1098:
	/* 0x1098: je     10a3 <tail_nodeport_nat_ingress_ipv4+0x10a3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1098, 0x10a3, x86_l_10a3);
x86_l_109a:
	/* 0x109a: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_109d:
	/* 0x109d: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_10a1:
	/* 0x10a1: jmp    10d4 <tail_nodeport_nat_ingress_ipv4+0x10d4> */
	X86_SIM_X86_JMP(0x10a1, 0x10d4, x86_l_10d4);
x86_l_10a3:
	/* 0x10a3: mov    QWORD PTR [rsp+0x90],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290625ULL);
x86_l_10af:
	/* 0x10af: mov    QWORD PTR [rsp+0x98],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_10b7:
	/* 0x10b7: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_10bc:
	/* 0x10bc: mov    rdi,QWORD PTR [rip+0x30f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_10c3:
	/* 0x10c3: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10c8:
	/* 0x10c8: lea    rdx,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_10d0:
	/* 0x10d0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10d2:
	/* 0x10d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10d4:
	/* 0x10d4: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_10d9:
	/* 0x10d9: mov    rsi,QWORD PTR [rip+0x30f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_10e0:
	/* 0x10e0: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_10e3:
	/* 0x10e3: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_10e8:
	/* 0x10e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10ea:
	/* 0x10ea: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_10f0:
	/* 0x10f0: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_10f3:
	/* 0x10f3: add    rsp,0xd8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 216ULL);
x86_l_10fa:
	/* 0x10fa: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_10fc:
	/* 0x10fc: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_10fd:
	/* 0x10fd: jmp    1c5e <tail_nodeport_nat_ingress_ipv4+0x1c5e> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_1102:
	/* 0x1102: mov    QWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_110b:
	/* 0x110b: mov    QWORD PTR [rsp+0x10],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1110:
	/* 0x1110: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1115:
	/* 0x1115: mov    rdi,QWORD PTR [rip+0x30fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_111c:
	/* 0x111c: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1121:
	/* 0x1121: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1126:
	/* 0x1126: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1128:
	/* 0x1128: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_112a:
	/* 0x112a: mov    r13,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBP, X86_WIDTH_64);
x86_l_112d:
	/* 0x112d: cmp    BYTE PTR [rsp+0x40],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 274877906950ULL);
x86_l_1132:
	/* 0x1132: jne    1189 <tail_nodeport_nat_ingress_ipv4+0x1189> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1132, 0x1189, x86_l_1189);
x86_l_1134:
	/* 0x1134: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_1137:
	/* 0x1137: and    rax,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_113a:
	/* 0x113a: jne    1189 <tail_nodeport_nat_ingress_ipv4+0x1189> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x113a, 0x1189, x86_l_1189);
x86_l_113c:
	/* 0x113c: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1141:
	/* 0x1141: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1146:
	/* 0x1146: lea    esi,[rcx+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1149:
	/* 0x1149: lea    rdx,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_114e:
	/* 0x114e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1151:
	/* 0x1151: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1156:
	/* 0x1156: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1158:
	/* 0x1158: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_115a:
	/* 0x115a: js     1c54 <tail_nodeport_nat_ingress_ipv4+0x1c54> */
	X86_SIM_X86_JCC(X86_CC_S, 0x115a, 0x1c54, x86_l_1c54);
x86_l_1160:
	/* 0x1160: mov    r14d,DWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1165:
	/* 0x1165: mov    eax,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_32);
x86_l_1168:
	/* 0x1168: and    eax,0x1200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4608ULL);
x86_l_116d:
	/* 0x116d: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_116f:
	/* 0x116f: cmp    eax,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 512ULL);
x86_l_1174:
	/* 0x1174: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_1177:
	/* 0x1177: test   r14d,0x500 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R14, X86_WIDTH_32, 1280ULL);
x86_l_117e:
	/* 0x117e: jne    1b4d <tail_nodeport_nat_ingress_ipv4+0x1b4d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x117e, 0x1b4d, x86_l_1b4d);
x86_l_1184:
	/* 0x1184: mov    bpl,al */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_8);
x86_l_1187:
	/* 0x1187: jmp    1190 <tail_nodeport_nat_ingress_ipv4+0x1190> */
	X86_SIM_X86_JMP(0x1187, 0x1190, x86_l_1190);
x86_l_1189:
	/* 0x1189: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_118b:
	/* 0x118b: mov    r14d,DWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1190:
	/* 0x1190: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1195:
	/* 0x1195: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_119a:
	/* 0x119a: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_119d:
	/* 0x119d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_119f:
	/* 0x119f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_11a2:
	/* 0x11a2: je     1c4b <tail_nodeport_nat_ingress_ipv4+0x1c4b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11a2, 0x1c4b, x86_l_1c4b);
x86_l_11a8:
	/* 0x11a8: movzx  ecx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_11ac:
	/* 0x11ac: test   cl,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_11af:
	/* 0x11af: je     1c4b <tail_nodeport_nat_ingress_ipv4+0x1c4b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11af, 0x1c4b, x86_l_1c4b);
x86_l_11b5:
	/* 0x11b5: cmp    WORD PTR [rax+0x26],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 163208757248ULL);
x86_l_11ba:
	/* 0x11ba: je     1c4b <tail_nodeport_nat_ingress_ipv4+0x1c4b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11ba, 0x1c4b, x86_l_1c4b);
x86_l_11c0:
	/* 0x11c0: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_11c2:
	/* 0x11c2: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_11c4:
	/* 0x11c4: test   dl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_8, 3ULL);
x86_l_11c7:
	/* 0x11c7: je     12d6 <tail_nodeport_nat_ingress_ipv4+0x12d6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11c7, 0x12d6, x86_l_12d6);
x86_l_11cd:
	/* 0x11cd: mov    rsi,QWORD PTR [rip+0x30fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_11d4:
	/* 0x11d4: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11d7:
	/* 0x11d7: je     11f5 <tail_nodeport_nat_ingress_ipv4+0x11f5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11d7, 0x11f5, x86_l_11f5);
x86_l_11d9:
	/* 0x11d9: mov    rdx,QWORD PTR [rip+0x30fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_11e0:
	/* 0x11e0: imul   r12d,DWORD PTR [rdx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R12, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_11e4:
	/* 0x11e4: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_11e8:
	/* 0x11e8: jmp    11fb <tail_nodeport_nat_ingress_ipv4+0x11fb> */
	X86_SIM_X86_JMP(0x11e8, 0x11fb, x86_l_11fb);
x86_l_11ea:
	/* 0x11ea: mov    r12d,0xffffff71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967153ULL);
x86_l_11f0:
	/* 0x11f0: jmp    1000 <tail_nodeport_nat_ingress_ipv4+0x1000> */
	X86_SIM_X86_JMP(0x11f0, 0x1000, x86_l_1000);
x86_l_11f5:
	/* 0x11f5: mov    r12d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 60ULL);
x86_l_11fb:
	/* 0x11fb: cmp    BYTE PTR [rsp+0x40],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 274877906950ULL);
x86_l_1200:
	/* 0x1200: jne    1239 <tail_nodeport_nat_ingress_ipv4+0x1239> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1200, 0x1239, x86_l_1239);
x86_l_1202:
	/* 0x1202: mov    edx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_32);
x86_l_1205:
	/* 0x1205: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1207:
	/* 0x1207: shr    edx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_120a:
	/* 0x120a: and    edx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_120d:
	/* 0x120d: or     ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_120f:
	/* 0x120f: mov    WORD PTR [rax+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1213:
	/* 0x1213: test   cl,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 16ULL);
x86_l_1216:
	/* 0x1216: mov    ecx,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 60ULL);
x86_l_121b:
	/* 0x121b: mov    r12d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 21600ULL);
x86_l_1221:
	/* 0x1221: cmove  r12d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RCX, X86_WIDTH_32, X86_CC_E);
x86_l_1225:
	/* 0x1225: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1228:
	/* 0x1228: je     1239 <tail_nodeport_nat_ingress_ipv4+0x1239> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1228, 0x1239, x86_l_1239);
x86_l_122a:
	/* 0x122a: mov    rcx,QWORD PTR [rip+0x30fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1231:
	/* 0x1231: imul   r12d,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_1235:
	/* 0x1235: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1239:
	/* 0x1239: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_123e:
	/* 0x123e: mov    r13d,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R14, X86_WIDTH_32);
x86_l_1241:
	/* 0x1241: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1245:
	/* 0x1245: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1248:
	/* 0x1248: je     125c <tail_nodeport_nat_ingress_ipv4+0x125c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1248, 0x125c, x86_l_125c);
x86_l_124a:
	/* 0x124a: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_124f:
	/* 0x124f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1251:
	/* 0x1251: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1253:
	/* 0x1253: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1256:
	/* 0x1256: shr    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_125a:
	/* 0x125a: jmp    127f <tail_nodeport_nat_ingress_ipv4+0x127f> */
	X86_SIM_X86_JMP(0x125a, 0x127f, x86_l_127f);
x86_l_125c:
	/* 0x125c: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1261:
	/* 0x1261: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1263:
	/* 0x1263: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1265:
	/* 0x1265: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1269:
	/* 0x1269: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_1273:
	/* 0x1273: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1276:
	/* 0x1276: mulx   rcx,rcx,rcx */
	X86_SIM_L_EXEC_MULX(X86_RCX, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_127b:
	/* 0x127b: shr    rcx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_127f:
	/* 0x127f: add    r12d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1282:
	/* 0x1282: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1287:
	/* 0x1287: mov    DWORD PTR [rax+0x20],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_128b:
	/* 0x128b: movzx  edx,BYTE PTR [rax+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_128f:
	/* 0x128f: mov    esi,DWORD PTR [rax+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1292:
	/* 0x1292: and    r13b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_1296:
	/* 0x1296: mov    rdi,QWORD PTR [rip+0x30fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_129d:
	/* 0x129d: cmp    BYTE PTR [rdi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12a0:
	/* 0x12a0: je     12b3 <tail_nodeport_nat_ingress_ipv4+0x12b3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12a0, 0x12b3, x86_l_12b3);
x86_l_12a2:
	/* 0x12a2: mov    rdi,QWORD PTR [rip+0x30fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_12a9:
	/* 0x12a9: mov    edi,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12ab:
	/* 0x12ab: lea    edi,[rdi+rdi*4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_12ae:
	/* 0x12ae: shr    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_12b1:
	/* 0x12b1: jmp    12b8 <tail_nodeport_nat_ingress_ipv4+0x12b8> */
	X86_SIM_X86_JMP(0x12b1, 0x12b8, x86_l_12b8);
x86_l_12b3:
	/* 0x12b3: mov    edi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 5ULL);
x86_l_12b8:
	/* 0x12b8: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_12ba:
	/* 0x12ba: or     r13b,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_12bd:
	/* 0x12bd: cmp    edi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RCX, X86_WIDTH_32);
x86_l_12bf:
	/* 0x12bf: jb     12c6 <tail_nodeport_nat_ingress_ipv4+0x12c6> */
	X86_SIM_X86_JCC(X86_CC_B, 0x12bf, 0x12c6, x86_l_12c6);
x86_l_12c1:
	/* 0x12c1: cmp    dl,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_8);
x86_l_12c4:
	/* 0x12c4: je     12d6 <tail_nodeport_nat_ingress_ipv4+0x12d6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12c4, 0x12d6, x86_l_12d6);
x86_l_12c6:
	/* 0x12c6: mov    BYTE PTR [rax+0x2b],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_12ca:
	/* 0x12ca: mov    DWORD PTR [rax+0x34],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_12cd:
	/* 0x12cd: mov    rcx,QWORD PTR [rip+0x30fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_12d4:
	/* 0x12d4: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12d6:
	/* 0x12d6: mov    rcx,QWORD PTR [rip+0x30fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_12dd:
	/* 0x12dd: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12e0:
	/* 0x12e0: je     12ef <tail_nodeport_nat_ingress_ipv4+0x12ef> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12e0, 0x12ef, x86_l_12ef);
x86_l_12e2:
	/* 0x12e2: inc QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 16ULL);
x86_l_12e7:
	/* 0x12e7: mov    ecx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_12ea:
	/* 0x12ea: add QWORD PTR [rax+0x18],rcx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_12ef:
	/* 0x12ef: cmp    ebp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_12f2:
	/* 0x12f2: je     1341 <tail_nodeport_nat_ingress_ipv4+0x1341> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12f2, 0x1341, x86_l_1341);
x86_l_12f4:
	/* 0x12f4: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_12f7:
	/* 0x12f7: jne    1584 <tail_nodeport_nat_ingress_ipv4+0x1584> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x12f7, 0x1584, x86_l_1584);
x86_l_12fd:
	/* 0x12fd: movzx  ecx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_1301:
	/* 0x1301: test   cl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_1304:
	/* 0x1304: je     1584 <tail_nodeport_nat_ingress_ipv4+0x1584> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1304, 0x1584, x86_l_1584);
x86_l_130a:
	/* 0x130a: mov    WORD PTR [rax+0x2a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 180388626432ULL);
x86_l_1310:
	/* 0x1310: and    ecx,0xffec */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 65516ULL);
x86_l_1316:
	/* 0x1316: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1319:
	/* 0x1319: mov    WORD PTR [rax+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_131d:
	/* 0x131d: mov    r12,QWORD PTR [rip+0x30fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1324:
	/* 0x1324: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1329:
	/* 0x1329: je     1b84 <tail_nodeport_nat_ingress_ipv4+0x1b84> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1329, 0x1b84, x86_l_1b84);
x86_l_132f:
	/* 0x132f: mov    rax,QWORD PTR [rip+0x30fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1336:
	/* 0x1336: imul   ebp,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_1339:
	/* 0x1339: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_133c:
	/* 0x133c: jmp    1b89 <tail_nodeport_nat_ingress_ipv4+0x1b89> */
	X86_SIM_X86_JMP(0x133c, 0x1b89, x86_l_1b89);
x86_l_1341:
	/* 0x1341: mov    ecx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_32);
x86_l_1344:
	/* 0x1344: shr    ecx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_1347:
	/* 0x1347: and    ecx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2ULL);
x86_l_134a:
	/* 0x134a: or     cx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RAX, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 36ULL);
x86_l_134e:
	/* 0x134e: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_1350:
	/* 0x1350: or     edx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_OR, 1ULL);
x86_l_1353:
	/* 0x1353: mov    WORD PTR [rax+0x24],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1357:
	/* 0x1357: mov    rdx,QWORD PTR [rip+0x30fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_135e:
	/* 0x135e: mov    edx,DWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1360:
	/* 0x1360: test   cl,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_1363:
	/* 0x1363: je     1584 <tail_nodeport_nat_ingress_ipv4+0x1584> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1363, 0x1584, x86_l_1584);
x86_l_1369:
	/* 0x1369: mov    r13d,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R14, X86_WIDTH_32);
x86_l_136c:
	/* 0x136c: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_136f:
	/* 0x136f: mov    r12,QWORD PTR [rip+0x30fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1376:
	/* 0x1376: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_137b:
	/* 0x137b: je     14e8 <tail_nodeport_nat_ingress_ipv4+0x14e8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x137b, 0x14e8, x86_l_14e8);
x86_l_1381:
	/* 0x1381: mov    rax,QWORD PTR [rip+0x30fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1388:
	/* 0x1388: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_138a:
	/* 0x138a: add    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_138c:
	/* 0x138c: lea    ebp,[rax+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_138f:
	/* 0x138f: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1392:
	/* 0x1392: jmp    14ed <tail_nodeport_nat_ingress_ipv4+0x14ed> */
	X86_SIM_X86_JMP(0x1392, 0x14ed, x86_l_14ed);
x86_l_1397:
	/* 0x1397: mov    DWORD PTR [rsp+0x7c],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 532575944736ULL);
x86_l_139f:
	/* 0x139f: mov    r12w,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_16, 6ULL);
x86_l_13a4:
	/* 0x13a4: jmp    13c7 <tail_nodeport_nat_ingress_ipv4+0x13c7> */
	X86_SIM_X86_JMP(0x13a4, 0x13c7, x86_l_13c7);
x86_l_13a6:
	/* 0x13a6: mov    DWORD PTR [rsp+0x7c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_13ae:
	/* 0x13ae: mov    r12w,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_16, 2ULL);
x86_l_13b3:
	/* 0x13b3: mov    edx,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_13b7:
	/* 0x13b7: mov    ecx,DWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_13be:
	/* 0x13be: mov    eax,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_13c2:
	/* 0x13c2: jmp    13c7 <tail_nodeport_nat_ingress_ipv4+0x13c7> */
	X86_SIM_X86_JMP(0x13c2, 0x13c7, x86_l_13c7);
x86_l_13c4:
	/* 0x13c4: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13c7:
	/* 0x13c7: cmp    ax,r13w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R13, X86_WIDTH_16);
x86_l_13cb:
	/* 0x13cb: jne    1416 <tail_nodeport_nat_ingress_ipv4+0x1416> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x13cb, 0x1416, x86_l_1416);
x86_l_13cd:
	/* 0x13cd: test   r12w,r12w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_16);
x86_l_13d1:
	/* 0x13d1: je     f32 <tail_nodeport_nat_ingress_ipv4+0xf32> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13d1, 0xf32, x86_l_f32);
x86_l_13d7:
	/* 0x13d7: movzx  eax,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_13db:
	/* 0x13db: mov    rsi,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_13e3:
	/* 0x13e3: add    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_13e5:
	/* 0x13e5: mov    r8d,DWORD PTR [rsp+0x7c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_13ea:
	/* 0x13ea: or     r8d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 16ULL);
x86_l_13ee:
	/* 0x13ee: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_13f3:
	/* 0x13f3: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_13f6:
	/* 0x13f6: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13f8:
	/* 0x13f8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13fa:
	/* 0x13fa: movzx  ecx,BYTE PTR [rsp+0x2f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 47ULL);
x86_l_13ff:
	/* 0x13ff: mov    edx,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1403:
	/* 0x1403: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1405:
	/* 0x1405: jns    f32 <tail_nodeport_nat_ingress_ipv4+0xf32> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1405, 0xf32, x86_l_f32);
x86_l_140b:
	/* 0x140b: mov    r12d,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967142ULL);
x86_l_1411:
	/* 0x1411: jmp    168c <tail_nodeport_nat_ingress_ipv4+0x168c> */
	X86_SIM_X86_JMP(0x1411, 0x168c, x86_l_168c);
x86_l_1416:
	/* 0x1416: cmp    esi,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_1419:
	/* 0x1419: je     1434 <tail_nodeport_nat_ingress_ipv4+0x1434> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1419, 0x1434, x86_l_1434);
x86_l_141b:
	/* 0x141b: cmp    esi,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 6ULL);
x86_l_141e:
	/* 0x141e: je     1434 <tail_nodeport_nat_ingress_ipv4+0x1434> */
	X86_SIM_X86_JCC(X86_CC_E, 0x141e, 0x1434, x86_l_1434);
x86_l_1420:
	/* 0x1420: mov    r12d,0xffffff72 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967154ULL);
x86_l_1426:
	/* 0x1426: cmp    esi,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_1429:
	/* 0x1429: jne    1000 <tail_nodeport_nat_ingress_ipv4+0x1000> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1429, 0x1000, x86_l_1000);
x86_l_142f:
	/* 0x142f: mov    r12w,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_16, 2ULL);
x86_l_1434:
	/* 0x1434: mov    WORD PTR [rsp+0x7a],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 122ULL);
x86_l_143a:
	/* 0x143a: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_143f:
	/* 0x143f: mov    rbp,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1447:
	/* 0x1447: mov    esi,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_144b:
	/* 0x144b: add    esi,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_144d:
	/* 0x144d: lea    rdx,[rsp+0x7a] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 122ULL);
x86_l_1452:
	/* 0x1452: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1455:
	/* 0x1455: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_145a:
	/* 0x145a: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_145d:
	/* 0x145d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_145f:
	/* 0x145f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1461:
	/* 0x1461: js     14d2 <tail_nodeport_nat_ingress_ipv4+0x14d2> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1461, 0x14d2, x86_l_14d2);
x86_l_1463:
	/* 0x1463: movzx  ecx,WORD PTR [rsp+0x7a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 122ULL);
x86_l_1468:
	/* 0x1468: movzx  esi,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_146c:
	/* 0x146c: add    esi,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_146e:
	/* 0x146e: mov    r8d,DWORD PTR [rsp+0x7c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_1473:
	/* 0x1473: or     r8d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_1477:
	/* 0x1477: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_147c:
	/* 0x147c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_147f:
	/* 0x147f: mov    edx,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1483:
	/* 0x1483: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1485:
	/* 0x1485: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1487:
	/* 0x1487: js     167d <tail_nodeport_nat_ingress_ipv4+0x167d> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1487, 0x167d, x86_l_167d);
x86_l_148d:
	/* 0x148d: cmp    DWORD PTR [rsp+0x8c],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 601295421441ULL);
x86_l_1495:
	/* 0x1495: mov    edx,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1499:
	/* 0x1499: mov    ecx,DWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_14a0:
	/* 0x14a0: je     f32 <tail_nodeport_nat_ingress_ipv4+0xf32> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14a0, 0xf32, x86_l_f32);
x86_l_14a6:
	/* 0x14a6: jmp    13cd <tail_nodeport_nat_ingress_ipv4+0x13cd> */
	X86_SIM_X86_JMP(0x14a6, 0x13cd, x86_l_13cd);
x86_l_14ab:
	/* 0x14ab: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14b0:
	/* 0x14b0: mov    rdi,QWORD PTR [rip+0x30fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv4_frag_datagrams)));
x86_l_14b7:
	/* 0x14b7: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14bc:
	/* 0x14bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14be:
	/* 0x14be: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14c1:
	/* 0x14c1: je     16a3 <tail_nodeport_nat_ingress_ipv4+0x16a3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14c1, 0x16a3, x86_l_16a3);
x86_l_14c7:
	/* 0x14c7: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14c9:
	/* 0x14c9: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_14cd:
	/* 0x14cd: jmp    24e <tail_nodeport_nat_ingress_ipv4+0x24e> */
	X86_SIM_X86_JMP(0x14cd, 0x24e, x86_l_24e);
x86_l_14d2:
	/* 0x14d2: mov    r12d,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967155ULL);
x86_l_14d8:
	/* 0x14d8: jmp    1683 <tail_nodeport_nat_ingress_ipv4+0x1683> */
	X86_SIM_X86_JMP(0x14d8, 0x1683, x86_l_1683);
x86_l_14dd:
	/* 0x14dd: mov    r12d,0xffffff63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967139ULL);
x86_l_14e3:
	/* 0x14e3: jmp    1005 <tail_nodeport_nat_ingress_ipv4+0x1005> */
	X86_SIM_X86_JMP(0x14e3, 0x1005, x86_l_1005);
x86_l_14e8:
	/* 0x14e8: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_14ed:
	/* 0x14ed: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_14f1:
	/* 0x14f1: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14f6:
	/* 0x14f6: je     150a <tail_nodeport_nat_ingress_ipv4+0x150a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14f6, 0x150a, x86_l_150a);
x86_l_14f8:
	/* 0x14f8: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_14fd:
	/* 0x14fd: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14ff:
	/* 0x14ff: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1501:
	/* 0x1501: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1504:
	/* 0x1504: shr    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_1508:
	/* 0x1508: jmp    152d <tail_nodeport_nat_ingress_ipv4+0x152d> */
	X86_SIM_X86_JMP(0x1508, 0x152d, x86_l_152d);
x86_l_150a:
	/* 0x150a: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_150f:
	/* 0x150f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1511:
	/* 0x1511: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1513:
	/* 0x1513: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1517:
	/* 0x1517: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_1521:
	/* 0x1521: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1524:
	/* 0x1524: mulx   rcx,rcx,rcx */
	X86_SIM_L_EXEC_MULX(X86_RCX, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_1529:
	/* 0x1529: shr    rcx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_152d:
	/* 0x152d: add    ebp,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_152f:
	/* 0x152f: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_1532:
	/* 0x1532: mov    DWORD PTR [r14+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1536:
	/* 0x1536: movzx  edx,BYTE PTR [r14+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_153b:
	/* 0x153b: mov    eax,DWORD PTR [r14+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_153f:
	/* 0x153f: and    r13b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_1543:
	/* 0x1543: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1548:
	/* 0x1548: je     155b <tail_nodeport_nat_ingress_ipv4+0x155b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1548, 0x155b, x86_l_155b);
x86_l_154a:
	/* 0x154a: mov    rsi,QWORD PTR [rip+0x30fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1551:
	/* 0x1551: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1553:
	/* 0x1553: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_1556:
	/* 0x1556: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1559:
	/* 0x1559: jmp    1560 <tail_nodeport_nat_ingress_ipv4+0x1560> */
	X86_SIM_X86_JMP(0x1559, 0x1560, x86_l_1560);
x86_l_155b:
	/* 0x155b: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_1560:
	/* 0x1560: add    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1562:
	/* 0x1562: or     r13b,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_1565:
	/* 0x1565: cmp    esi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_1567:
	/* 0x1567: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_156a:
	/* 0x156a: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_156d:
	/* 0x156d: jb     1574 <tail_nodeport_nat_ingress_ipv4+0x1574> */
	X86_SIM_X86_JCC(X86_CC_B, 0x156d, 0x1574, x86_l_1574);
x86_l_156f:
	/* 0x156f: cmp    dl,sil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_8);
x86_l_1572:
	/* 0x1572: je     1584 <tail_nodeport_nat_ingress_ipv4+0x1584> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1572, 0x1584, x86_l_1584);
x86_l_1574:
	/* 0x1574: mov    BYTE PTR [rax+0x2b],sil */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RSI, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_1578:
	/* 0x1578: mov    DWORD PTR [rax+0x34],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_157b:
	/* 0x157b: mov    rcx,QWORD PTR [rip+0x30fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_1582:
	/* 0x1582: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1584:
	/* 0x1584: test   BYTE PTR [rsp+0x3d],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 261993005058ULL);
x86_l_1589:
	/* 0x1589: jne    1c54 <tail_nodeport_nat_ingress_ipv4+0x1c54> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1589, 0x1c54, x86_l_1c54);
x86_l_158f:
	/* 0x158f: movzx  eax,WORD PTR [rax+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_1593:
	/* 0x1593: mov    WORD PTR [rsp+0x8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1598:
	/* 0x1598: mov    r14,QWORD PTR [rip+0x30fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_159f:
	/* 0x159f: movzx  eax,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_15a3:
	/* 0x15a3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_15a8:
	/* 0x15a8: mov    rdi,QWORD PTR [rip+0x30fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_reverse_nat)));
x86_l_15af:
	/* 0x15af: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15b4:
	/* 0x15b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15b6:
	/* 0x15b6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15b9:
	/* 0x15b9: je     17b5 <tail_nodeport_nat_ingress_ipv4+0x17b5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x15b9, 0x17b5, x86_l_17b5);
x86_l_15bf:
	/* 0x15bf: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_15c2:
	/* 0x15c2: mov    eax,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_15c6:
	/* 0x15c6: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_15ca:
	/* 0x15ca: movzx  eax,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_15ce:
	/* 0x15ce: mov    eax,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15d2:
	/* 0x15d2: mov    DWORD PTR [rsp+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_15d6:
	/* 0x15d6: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_15db:
	/* 0x15db: mov    rcx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_15e0:
	/* 0x15e0: lea    esi,[rcx+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_15e3:
	/* 0x15e3: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15e5:
	/* 0x15e5: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_15e8:
	/* 0x15e8: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_15eb:
	/* 0x15eb: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_15f0:
	/* 0x15f0: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15f3:
	/* 0x15f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15f5:
	/* 0x15f5: mov    r12d,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967155ULL);
x86_l_15fb:
	/* 0x15fb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_15fd:
	/* 0x15fd: js     e10 <tail_nodeport_nat_ingress_ipv4+0xe10> */
	X86_SIM_X86_JCC(X86_CC_S, 0x15fd, 0xe10, x86_l_e10);
x86_l_1603:
	/* 0x1603: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1606:
	/* 0x1606: je     e10 <tail_nodeport_nat_ingress_ipv4+0xe10> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1606, 0xe10, x86_l_e10);
x86_l_160c:
	/* 0x160c: mov    r14d,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1611:
	/* 0x1611: not    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1614:
	/* 0x1614: add    r14d,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_R13, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1618:
	/* 0x1618: adc    r14d,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_161c:
	/* 0x161c: mov    rax,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1621:
	/* 0x1621: lea    esi,[rax+0xa] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 10ULL);
x86_l_1624:
	/* 0x1624: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1626:
	/* 0x1626: mov    eax,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_162b:
	/* 0x162b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_162e:
	/* 0x162e: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1630:
	/* 0x1630: mov    ecx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_32);
x86_l_1633:
	/* 0x1633: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1636:
	/* 0x1636: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1638:
	/* 0x1638: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_163a:
	/* 0x163a: js     166d <tail_nodeport_nat_ingress_ipv4+0x166d> */
	X86_SIM_X86_JCC(X86_CC_S, 0x163a, 0x166d, x86_l_166d);
x86_l_163c:
	/* 0x163c: movabs rax,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2199023255552ULL);
x86_l_1646:
	/* 0x1646: test   r15,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1649:
	/* 0x1649: jne    17b5 <tail_nodeport_nat_ingress_ipv4+0x17b5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1649, 0x17b5, x86_l_17b5);
x86_l_164f:
	/* 0x164f: movzx  eax,BYTE PTR [rsp+0x3c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 60ULL);
x86_l_1654:
	/* 0x1654: cmp    eax,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 58ULL);
x86_l_1657:
	/* 0x1657: je     16c5 <tail_nodeport_nat_ingress_ipv4+0x16c5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1657, 0x16c5, x86_l_16c5);
x86_l_1659:
	/* 0x1659: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_165c:
	/* 0x165c: je     16ae <tail_nodeport_nat_ingress_ipv4+0x16ae> */
	X86_SIM_X86_JCC(X86_CC_E, 0x165c, 0x16ae, x86_l_16ae);
x86_l_165e:
	/* 0x165e: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_1661:
	/* 0x1661: jne    16d4 <tail_nodeport_nat_ingress_ipv4+0x16d4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1661, 0x16d4, x86_l_16d4);
x86_l_1663:
	/* 0x1663: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1666:
	/* 0x1666: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_166b:
	/* 0x166b: jmp    16cd <tail_nodeport_nat_ingress_ipv4+0x16cd> */
	X86_SIM_X86_JMP(0x166b, 0x16cd, x86_l_16cd);
x86_l_166d:
	/* 0x166d: mov    r12d,0xffffff67 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967143ULL);
x86_l_1673:
	/* 0x1673: mov    r13d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1678:
	/* 0x1678: jmp    1041 <tail_nodeport_nat_ingress_ipv4+0x1041> */
	X86_SIM_X86_JMP(0x1678, 0x1041, x86_l_1041);
x86_l_167d:
	/* 0x167d: mov    r12d,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967142ULL);
x86_l_1683:
	/* 0x1683: mov    edx,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1687:
	/* 0x1687: movzx  ecx,BYTE PTR [rsp+0x2f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 47ULL);
x86_l_168c:
	/* 0x168c: cmp    r12d,0xffffff66 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 4294967142ULL);
x86_l_1693:
	/* 0x1693: setne  al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_NE);
x86_l_1696:
	/* 0x1696: or     cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_OR);
x86_l_1698:
	/* 0x1698: je     f32 <tail_nodeport_nat_ingress_ipv4+0xf32> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1698, 0xf32, x86_l_f32);
x86_l_169e:
	/* 0x169e: jmp    1000 <tail_nodeport_nat_ingress_ipv4+0x1000> */
	X86_SIM_X86_JMP(0x169e, 0x1000, x86_l_1000);
x86_l_16a3:
	/* 0x16a3: mov    r12d,0xffffff51 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967121ULL);
x86_l_16a9:
	/* 0x16a9: jmp    1005 <tail_nodeport_nat_ingress_ipv4+0x1005> */
	X86_SIM_X86_JMP(0x16a9, 0x1005, x86_l_1005);
x86_l_16ae:
	/* 0x16ae: mov    DWORD PTR [rsp+0x20],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953504ULL);
x86_l_16b6:
	/* 0x16b6: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_16bb:
	/* 0x16bb: mov    QWORD PTR [rsp+0x40],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_16c0:
	/* 0x16c0: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16c3:
	/* 0x16c3: jmp    16e6 <tail_nodeport_nat_ingress_ipv4+0x16e6> */
	X86_SIM_X86_JMP(0x16c3, 0x16e6, x86_l_16e6);
x86_l_16c5:
	/* 0x16c5: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16c8:
	/* 0x16c8: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_16cd:
	/* 0x16cd: mov    QWORD PTR [rsp+0x40],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_16d2:
	/* 0x16d2: jmp    16de <tail_nodeport_nat_ingress_ipv4+0x16de> */
	X86_SIM_X86_JMP(0x16d2, 0x16de, x86_l_16de);
x86_l_16d4:
	/* 0x16d4: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16d6:
	/* 0x16d6: mov    QWORD PTR [rsp+0x40],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_16db:
	/* 0x16db: mov    r15b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_8, 1ULL);
x86_l_16de:
	/* 0x16de: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_16e6:
	/* 0x16e6: movzx  ecx,WORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_16eb:
	/* 0x16eb: test   cx,cx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_16);
x86_l_16ee:
	/* 0x16ee: je     1785 <tail_nodeport_nat_ingress_ipv4+0x1785> */
	X86_SIM_X86_JCC(X86_CC_E, 0x16ee, 0x1785, x86_l_1785);
x86_l_16f4:
	/* 0x16f4: movzx  r13d,WORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_16fa:
	/* 0x16fa: mov    r12d,0xffffff72 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967154ULL);
x86_l_1700:
	/* 0x1700: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1702:
	/* 0x1702: cmp    eax,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_1705:
	/* 0x1705: jg     1716 <tail_nodeport_nat_ingress_ipv4+0x1716> */
	X86_SIM_X86_JCC(X86_CC_G, 0x1705, 0x1716, x86_l_1716);
x86_l_1707:
	/* 0x1707: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_170a:
	/* 0x170a: je     1785 <tail_nodeport_nat_ingress_ipv4+0x1785> */
	X86_SIM_X86_JCC(X86_CC_E, 0x170a, 0x1785, x86_l_1785);
x86_l_170c:
	/* 0x170c: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_170f:
	/* 0x170f: je     1724 <tail_nodeport_nat_ingress_ipv4+0x1724> */
	X86_SIM_X86_JCC(X86_CC_E, 0x170f, 0x1724, x86_l_1724);
x86_l_1711:
	/* 0x1711: jmp    e10 <tail_nodeport_nat_ingress_ipv4+0xe10> */
	X86_SIM_X86_JMP(0x1711, 0xe10, x86_l_e10);
x86_l_1716:
	/* 0x1716: cmp    eax,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 58ULL);
x86_l_1719:
	/* 0x1719: je     1785 <tail_nodeport_nat_ingress_ipv4+0x1785> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1719, 0x1785, x86_l_1785);
x86_l_171b:
	/* 0x171b: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_171e:
	/* 0x171e: jne    e10 <tail_nodeport_nat_ingress_ipv4+0xe10> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x171e, 0xe10, x86_l_e10);
x86_l_1724:
	/* 0x1724: cmp    cx,r13w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R13, X86_WIDTH_16);
x86_l_1728:
	/* 0x1728: je     1785 <tail_nodeport_nat_ingress_ipv4+0x1785> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1728, 0x1785, x86_l_1785);
x86_l_172a:
	/* 0x172a: mov    WORD PTR [rsp+0x8],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_172f:
	/* 0x172f: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_1734:
	/* 0x1734: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1739:
	/* 0x1739: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_173b:
	/* 0x173b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_173e:
	/* 0x173e: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1743:
	/* 0x1743: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1748:
	/* 0x1748: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_174b:
	/* 0x174b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_174d:
	/* 0x174d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_174f:
	/* 0x174f: js     19ce <tail_nodeport_nat_ingress_ipv4+0x19ce> */
	X86_SIM_X86_JCC(X86_CC_S, 0x174f, 0x19ce, x86_l_19ce);
x86_l_1755:
	/* 0x1755: movzx  ecx,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_175a:
	/* 0x175a: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_175f:
	/* 0x175f: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1764:
	/* 0x1764: lea    esi,[rdx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_1767:
	/* 0x1767: mov    r8d,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_176c:
	/* 0x176c: or     r8d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_1770:
	/* 0x1770: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_1775:
	/* 0x1775: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1778:
	/* 0x1778: mov    edx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_32);
x86_l_177b:
	/* 0x177b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_177d:
	/* 0x177d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_177f:
	/* 0x177f: js     1918 <tail_nodeport_nat_ingress_ipv4+0x1918> */
	X86_SIM_X86_JCC(X86_CC_S, 0x177f, 0x1918, x86_l_1918);
x86_l_1785:
	/* 0x1785: test   r15b,r15b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_8);
x86_l_1788:
	/* 0x1788: jne    17b5 <tail_nodeport_nat_ingress_ipv4+0x17b5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1788, 0x17b5, x86_l_17b5);
x86_l_178a:
	/* 0x178a: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_178f:
	/* 0x178f: add    esi,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RSI, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 80ULL);
x86_l_1793:
	/* 0x1793: mov    r8d,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1798:
	/* 0x1798: or     r8d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 16ULL);
x86_l_179c:
	/* 0x179c: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_179e:
	/* 0x179e: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_17a3:
	/* 0x17a3: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_17a6:
	/* 0x17a6: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17a8:
	/* 0x17a8: mov    ecx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_32);
x86_l_17ab:
	/* 0x17ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17ad:
	/* 0x17ad: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_17af:
	/* 0x17af: js     1918 <tail_nodeport_nat_ingress_ipv4+0x1918> */
	X86_SIM_X86_JCC(X86_CC_S, 0x17af, 0x1918, x86_l_1918);
x86_l_17b5:
	/* 0x17b5: mov    rax,QWORD PTR [rip+0x30fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_17bc:
	/* 0x17bc: movzx  ecx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_17bf:
	/* 0x17bf: mov    rax,QWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_17c6:
	/* 0x17c6: mov    edx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_17c9:
	/* 0x17c9: sub    edx,DWORD PTR [rbx+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_17cc:
	/* 0x17cc: add    rdx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_17cf:
	/* 0x17cf: lea    rsi,[rax+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_17d3:
	/* 0x17d3: add    rsi,0x14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 20ULL);
x86_l_17d7:
	/* 0x17d7: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_17da:
	/* 0x17da: ja     c73 <tail_nodeport_nat_ingress_ipv4+0xc73> */
	X86_SIM_X86_JCC(X86_CC_A, 0x17da, 0xc73, x86_l_c73);
x86_l_17e0:
	/* 0x17e0: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_17e3:
	/* 0x17e3: mov    ecx,0xfffff0ff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294963455ULL);
x86_l_17e8:
	/* 0x17e8: and    ecx,DWORD PTR [rbx+0xa8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 168ULL);
x86_l_17ee:
	/* 0x17ee: or     ecx,0x300 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_OR, 768ULL);
x86_l_17f4:
	/* 0x17f4: mov    DWORD PTR [rbx+0xa8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_17fa:
	/* 0x17fa: mov    ecx,DWORD PTR [rax+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_17fd:
	/* 0x17fd: mov    DWORD PTR [rsp+0xa0],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1804:
	/* 0x1804: mov    ecx,DWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1807:
	/* 0x1807: mov    DWORD PTR [rsp+0xb0],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_180e:
	/* 0x180e: movzx  edx,BYTE PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_1812:
	/* 0x1812: mov    r12d,0xffffff3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967100ULL);
x86_l_1818:
	/* 0x1818: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_181b:
	/* 0x181b: jb     e0e <tail_nodeport_nat_ingress_ipv4+0xe0e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x181b, 0xe0e, x86_l_e0e);
x86_l_1821:
	/* 0x1821: lea    ecx,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_1824:
	/* 0x1824: mov    BYTE PTR [rax+0x8],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1827:
	/* 0x1827: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_182c:
	/* 0x182c: add    esi,0xa */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 10ULL);
x86_l_182f:
	/* 0x182f: movzx  ecx,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1832:
	/* 0x1832: mov    eax,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_1837:
	/* 0x1837: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_183a:
	/* 0x183a: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_1840:
	/* 0x1840: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1842:
	/* 0x1842: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1844:
	/* 0x1844: js     18f7 <tail_nodeport_nat_ingress_ipv4+0x18f7> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1844, 0x18f7, x86_l_18f7);
x86_l_184a:
	/* 0x184a: mov    eax,0x45 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 69ULL);
x86_l_184f:
	/* 0x184f: mov    rcx,QWORD PTR [rip+0x30fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_supports_fib_lookup_skip_neigh)));
x86_l_1856:
	/* 0x1856: movzx  ecx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1859:
	/* 0x1859: shl    ecx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 2ULL);
x86_l_185c:
	/* 0x185c: lea    rsi,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1864:
	/* 0x1864: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1867:
	/* 0x1867: mov    edx,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 64ULL);
x86_l_186c:
	/* 0x186c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_186e:
	/* 0x186e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1870:
	/* 0x1870: je     187b <tail_nodeport_nat_ingress_ipv4+0x187b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1870, 0x187b, x86_l_187b);
x86_l_1872:
	/* 0x1872: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_1875:
	/* 0x1875: jne    1902 <tail_nodeport_nat_ingress_ipv4+0x1902> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1875, 0x1902, x86_l_1902);
x86_l_187b:
	/* 0x187b: mov    r14d,DWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1883:
	/* 0x1883: mov    DWORD PTR [rsp+0x8],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1888:
	/* 0x1888: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_188d:
	/* 0x188d: mov    rdi,QWORD PTR [rip+0x30fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_devices)));
x86_l_1894:
	/* 0x1894: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1899:
	/* 0x1899: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_189b:
	/* 0x189b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_189e:
	/* 0x189e: je     18aa <tail_nodeport_nat_ingress_ipv4+0x18aa> */
	X86_SIM_X86_JCC(X86_CC_E, 0x189e, 0x18aa, x86_l_18aa);
x86_l_18a0:
	/* 0x18a0: test   BYTE PTR [rax+0x8],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_18a4:
	/* 0x18a4: jne    195e <tail_nodeport_nat_ingress_ipv4+0x195e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x18a4, 0x195e, x86_l_195e);
x86_l_18aa:
	/* 0x18aa: mov    rax,QWORD PTR [rip+0x30fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_18b1:
	/* 0x18b1: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18b4:
	/* 0x18b4: je     1995 <tail_nodeport_nat_ingress_ipv4+0x1995> */
	X86_SIM_X86_JCC(X86_CC_E, 0x18b4, 0x1995, x86_l_1995);
x86_l_18ba:
	/* 0x18ba: lea    rax,[rsp+0xb0] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_18c2:
	/* 0x18c2: movzx  ecx,BYTE PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 144ULL);
x86_l_18ca:
	/* 0x18ca: mov    DWORD PTR [rsp+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18ce:
	/* 0x18ce: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18d1:
	/* 0x18d1: mov    rax,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18d5:
	/* 0x18d5: mov    QWORD PTR [rsp+0xc],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_18da:
	/* 0x18da: mov    QWORD PTR [rsp+0x14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_18df:
	/* 0x18df: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_18e4:
	/* 0x18e4: mov    eax,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 152ULL);
x86_l_18e9:
	/* 0x18e9: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_18ec:
	/* 0x18ec: mov    edx,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 20ULL);
x86_l_18f1:
	/* 0x18f1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18f3:
	/* 0x18f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18f5:
	/* 0x18f5: jmp    196a <tail_nodeport_nat_ingress_ipv4+0x196a> */
	X86_SIM_X86_JMP(0x18f5, 0x196a, x86_l_196a);
x86_l_18f7:
	/* 0x18f7: mov    r12d,0xffffff67 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967143ULL);
x86_l_18fd:
	/* 0x18fd: jmp    e0e <tail_nodeport_nat_ingress_ipv4+0xe0e> */
	X86_SIM_X86_JMP(0x18fd, 0xe0e, x86_l_e0e);
x86_l_1902:
	/* 0x1902: shl    eax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_1905:
	/* 0x1905: movzx  ebp,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1908:
	/* 0x1908: mov    r12d,0xffffff57 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967127ULL);
x86_l_190e:
	/* 0x190e: mov    r13d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1913:
	/* 0x1913: jmp    1041 <tail_nodeport_nat_ingress_ipv4+0x1041> */
	X86_SIM_X86_JMP(0x1913, 0x1041, x86_l_1041);
x86_l_1918:
	/* 0x1918: mov    r12d,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967142ULL);
x86_l_191e:
	/* 0x191e: mov    r13d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1923:
	/* 0x1923: jmp    1041 <tail_nodeport_nat_ingress_ipv4+0x1041> */
	X86_SIM_X86_JMP(0x1923, 0x1041, x86_l_1041);
x86_l_1928:
	/* 0x1928: mov    QWORD PTR [rsp+0x90],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290625ULL);
x86_l_1934:
	/* 0x1934: mov    QWORD PTR [rsp+0x98],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_193c:
	/* 0x193c: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1941:
	/* 0x1941: mov    rdi,QWORD PTR [rip+0x30fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1948:
	/* 0x1948: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_194d:
	/* 0x194d: lea    rdx,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1955:
	/* 0x1955: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1957:
	/* 0x1957: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1959:
	/* 0x1959: jmp    24e <tail_nodeport_nat_ingress_ipv4+0x24e> */
	X86_SIM_X86_JMP(0x1959, 0x24e, x86_l_24e);
x86_l_195e:
	/* 0x195e: mov    eax,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 23ULL);
x86_l_1963:
	/* 0x1963: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_1966:
	/* 0x1966: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1968:
	/* 0x1968: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_196a:
	/* 0x196a: mov    r12d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_32);
x86_l_196d:
	/* 0x196d: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_196f:
	/* 0x196f: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_1972:
	/* 0x1972: js     e10 <tail_nodeport_nat_ingress_ipv4+0xe10> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1972, 0xe10, x86_l_e10);
x86_l_1978:
	/* 0x1978: cmp    r12d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 2ULL);
x86_l_197c:
	/* 0x197c: je     e10 <tail_nodeport_nat_ingress_ipv4+0xe10> */
	X86_SIM_X86_JCC(X86_CC_E, 0x197c, 0xe10, x86_l_e10);
x86_l_1982:
	/* 0x1982: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_1985:
	/* 0x1985: mov    r13d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_198a:
	/* 0x198a: jne    10f0 <tail_nodeport_nat_ingress_ipv4+0x10f0> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x198a, 0x10f0, x86_l_10f0);
x86_l_1990:
	/* 0x1990: jmp    1019 <tail_nodeport_nat_ingress_ipv4+0x1019> */
	X86_SIM_X86_JMP(0x1990, 0x1019, x86_l_1019);
x86_l_1995:
	/* 0x1995: movzx  r15d,WORD PTR [rbx+0xb4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 180ULL);
x86_l_199d:
	/* 0x199d: mov    eax,0x2b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_19a2:
	/* 0x19a2: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19a4:
	/* 0x19a4: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_19a7:
	/* 0x19a7: mov    esi,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 14ULL);
x86_l_19ac:
	/* 0x19ac: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19ae:
	/* 0x19ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19b0:
	/* 0x19b0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_19b2:
	/* 0x19b2: je     19de <tail_nodeport_nat_ingress_ipv4+0x19de> */
	X86_SIM_X86_JCC(X86_CC_E, 0x19b2, 0x19de, x86_l_19de);
x86_l_19b4:
	/* 0x19b4: mov    r12d,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967162ULL);
x86_l_19ba:
	/* 0x19ba: mov    r13d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_19bf:
	/* 0x19bf: jmp    1041 <tail_nodeport_nat_ingress_ipv4+0x1041> */
	X86_SIM_X86_JMP(0x19bf, 0x1041, x86_l_1041);
x86_l_19c4:
	/* 0x19c4: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_19c9:
	/* 0x19c9: jmp    675 <tail_nodeport_nat_ingress_ipv4+0x675> */
	X86_SIM_X86_JMP(0x19c9, 0x675, x86_l_675);
x86_l_19ce:
	/* 0x19ce: mov    r12d,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967155ULL);
x86_l_19d4:
	/* 0x19d4: mov    r13d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_19d9:
	/* 0x19d9: jmp    1041 <tail_nodeport_nat_ingress_ipv4+0x1041> */
	X86_SIM_X86_JMP(0x19d9, 0x1041, x86_l_1041);
x86_l_19de:
	/* 0x19de: mov    WORD PTR [rsp+0x8],r15w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19e4:
	/* 0x19e4: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_19e9:
	/* 0x19e9: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_19ee:
	/* 0x19ee: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_19f1:
	/* 0x19f1: mov    esi,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 12ULL);
x86_l_19f6:
	/* 0x19f6: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_19fb:
	/* 0x19fb: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19fe:
	/* 0x19fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a00:
	/* 0x1a00: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1a02:
	/* 0x1a02: jns    18ba <tail_nodeport_nat_ingress_ipv4+0x18ba> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1a02, 0x18ba, x86_l_18ba);
x86_l_1a08:
	/* 0x1a08: mov    r12d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_32);
x86_l_1a0b:
	/* 0x1a0b: sar    r12d,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SAR, 31ULL);
x86_l_1a0f:
	/* 0x1a0f: and    r12d,0xffffff73 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 4294967155ULL);
x86_l_1a16:
	/* 0x1a16: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a18:
	/* 0x1a18: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_1a1b:
	/* 0x1a1b: jns    1978 <tail_nodeport_nat_ingress_ipv4+0x1978> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1a1b, 0x1978, x86_l_1978);
x86_l_1a21:
	/* 0x1a21: jmp    e10 <tail_nodeport_nat_ingress_ipv4+0xe10> */
	X86_SIM_X86_JMP(0x1a21, 0xe10, x86_l_e10);
x86_l_1a26:
	/* 0x1a26: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a2b:
	/* 0x1a2b: mov    rdi,QWORD PTR [rip+0x30fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv4_frag_datagrams)));
x86_l_1a32:
	/* 0x1a32: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1a37:
	/* 0x1a37: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a39:
	/* 0x1a39: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a3c:
	/* 0x1a3c: je     1b42 <tail_nodeport_nat_ingress_ipv4+0x1b42> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a3c, 0x1b42, x86_l_1b42);
x86_l_1a42:
	/* 0x1a42: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a44:
	/* 0x1a44: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1a48:
	/* 0x1a48: jmp    df2 <tail_nodeport_nat_ingress_ipv4+0xdf2> */
	X86_SIM_X86_JMP(0x1a48, 0xdf2, x86_l_df2);
x86_l_1a4d:
	/* 0x1a4d: mov    r12d,0xffffff63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967139ULL);
x86_l_1a53:
	/* 0x1a53: jmp    e0e <tail_nodeport_nat_ingress_ipv4+0xe0e> */
	X86_SIM_X86_JMP(0x1a53, 0xe0e, x86_l_e0e);
x86_l_1a58:
	/* 0x1a58: mov    r12d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 60ULL);
x86_l_1a5e:
	/* 0x1a5e: cmp    WORD PTR [rsp+0x48],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 309237645318ULL);
x86_l_1a64:
	/* 0x1a64: jne    1a9f <tail_nodeport_nat_ingress_ipv4+0x1a9f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1a64, 0x1a9f, x86_l_1a9f);
x86_l_1a66:
	/* 0x1a66: mov    ecx,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a6a:
	/* 0x1a6a: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1a6c:
	/* 0x1a6c: shr    ecx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_1a6f:
	/* 0x1a6f: and    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_1a72:
	/* 0x1a72: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1a74:
	/* 0x1a74: mov    WORD PTR [r13+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1a79:
	/* 0x1a79: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1a7b:
	/* 0x1a7b: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_1a80:
	/* 0x1a80: mov    r12d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 21600ULL);
x86_l_1a86:
	/* 0x1a86: cmove  r12d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_1a8a:
	/* 0x1a8a: cmp    BYTE PTR [rbp+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a8e:
	/* 0x1a8e: je     1a9f <tail_nodeport_nat_ingress_ipv4+0x1a9f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a8e, 0x1a9f, x86_l_1a9f);
x86_l_1a90:
	/* 0x1a90: mov    rax,QWORD PTR [rip+0x30fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1a97:
	/* 0x1a97: imul   r12d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_1a9b:
	/* 0x1a9b: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1a9f:
	/* 0x1a9f: shr    DWORD PTR [rsp+0x20],0x8 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_32, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_SHR)), 137438953480ULL);
x86_l_1aa4:
	/* 0x1aa4: cmp    BYTE PTR [rbp+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1aa8:
	/* 0x1aa8: je     1ab9 <tail_nodeport_nat_ingress_ipv4+0x1ab9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1aa8, 0x1ab9, x86_l_1ab9);
x86_l_1aaa:
	/* 0x1aaa: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_1aaf:
	/* 0x1aaf: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ab1:
	/* 0x1ab1: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1ab3:
	/* 0x1ab3: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_1ab7:
	/* 0x1ab7: jmp    1adc <tail_nodeport_nat_ingress_ipv4+0x1adc> */
	X86_SIM_X86_JMP(0x1ab7, 0x1adc, x86_l_1adc);
x86_l_1ab9:
	/* 0x1ab9: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1abe:
	/* 0x1abe: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ac0:
	/* 0x1ac0: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1ac2:
	/* 0x1ac2: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1ac6:
	/* 0x1ac6: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_1ad0:
	/* 0x1ad0: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1ad3:
	/* 0x1ad3: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1ad8:
	/* 0x1ad8: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_1adc:
	/* 0x1adc: add    r12d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1adf:
	/* 0x1adf: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1ae2:
	/* 0x1ae2: mov    DWORD PTR [r13+0x20],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ae6:
	/* 0x1ae6: movzx  ecx,BYTE PTR [r13+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_1aeb:
	/* 0x1aeb: mov    edx,DWORD PTR [r13+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1aef:
	/* 0x1aef: mov    esi,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1af3:
	/* 0x1af3: and    sil,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_1af7:
	/* 0x1af7: mov    DWORD PTR [rsp+0x20],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1afb:
	/* 0x1afb: cmp    BYTE PTR [rbp+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1aff:
	/* 0x1aff: je     1b12 <tail_nodeport_nat_ingress_ipv4+0x1b12> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1aff, 0x1b12, x86_l_1b12);
x86_l_1b01:
	/* 0x1b01: mov    rsi,QWORD PTR [rip+0x30fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1b08:
	/* 0x1b08: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b0a:
	/* 0x1b0a: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_1b0d:
	/* 0x1b0d: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1b10:
	/* 0x1b10: jmp    1b17 <tail_nodeport_nat_ingress_ipv4+0x1b17> */
	X86_SIM_X86_JMP(0x1b10, 0x1b17, x86_l_1b17);
x86_l_1b12:
	/* 0x1b12: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_1b17:
	/* 0x1b17: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1b19:
	/* 0x1b19: mov    edx,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b1d:
	/* 0x1b1d: or     dl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_1b1f:
	/* 0x1b1f: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_1b21:
	/* 0x1b21: movabs r9,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_64, 2199023255552ULL);
x86_l_1b2b:
	/* 0x1b2b: jb     1b35 <tail_nodeport_nat_ingress_ipv4+0x1b35> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1b2b, 0x1b35, x86_l_1b35);
x86_l_1b2d:
	/* 0x1b2d: cmp    cl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_8);
x86_l_1b2f:
	/* 0x1b2f: je     98f <tail_nodeport_nat_ingress_ipv4+0x98f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1b2f, 0x98f, x86_l_98f);
x86_l_1b35:
	/* 0x1b35: mov    BYTE PTR [r13+0x2b],dl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_1b39:
	/* 0x1b39: mov    DWORD PTR [r13+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1b3d:
	/* 0x1b3d: jmp    986 <tail_nodeport_nat_ingress_ipv4+0x986> */
	X86_SIM_X86_JMP(0x1b3d, 0x986, x86_l_986);
x86_l_1b42:
	/* 0x1b42: mov    r12d,0xffffff51 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967121ULL);
x86_l_1b48:
	/* 0x1b48: jmp    e0e <tail_nodeport_nat_ingress_ipv4+0xe0e> */
	X86_SIM_X86_JMP(0x1b48, 0xe0e, x86_l_e0e);
x86_l_1b4d:
	/* 0x1b4d: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_1b52:
	/* 0x1b52: jmp    1190 <tail_nodeport_nat_ingress_ipv4+0x1190> */
	X86_SIM_X86_JMP(0x1b52, 0x1190, x86_l_1190);
x86_l_1b57:
	/* 0x1b57: mov    QWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_1b60:
	/* 0x1b60: mov    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b65:
	/* 0x1b65: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1b6a:
	/* 0x1b6a: mov    rdi,QWORD PTR [rip+0x30fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1b71:
	/* 0x1b71: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1b76:
	/* 0x1b76: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b7b:
	/* 0x1b7b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b7d:
	/* 0x1b7d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b7f:
	/* 0x1b7f: jmp    df2 <tail_nodeport_nat_ingress_ipv4+0xdf2> */
	X86_SIM_X86_JMP(0x1b7f, 0xdf2, x86_l_df2);
x86_l_1b84:
	/* 0x1b84: mov    ebp,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_1b89:
	/* 0x1b89: cmp    BYTE PTR [rsp+0x40],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 274877906950ULL);
x86_l_1b8e:
	/* 0x1b8e: jne    1bc5 <tail_nodeport_nat_ingress_ipv4+0x1bc5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1b8e, 0x1bc5, x86_l_1bc5);
x86_l_1b90:
	/* 0x1b90: mov    eax,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_32);
x86_l_1b93:
	/* 0x1b93: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1b95:
	/* 0x1b95: shr    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_1b98:
	/* 0x1b98: and    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_1b9b:
	/* 0x1b9b: or     ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1b9d:
	/* 0x1b9d: mov    WORD PTR [r15+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1ba2:
	/* 0x1ba2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1ba4:
	/* 0x1ba4: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_1ba9:
	/* 0x1ba9: mov    ebp,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 21600ULL);
x86_l_1bae:
	/* 0x1bae: cmove  ebp,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_1bb1:
	/* 0x1bb1: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bb6:
	/* 0x1bb6: je     1bc5 <tail_nodeport_nat_ingress_ipv4+0x1bc5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1bb6, 0x1bc5, x86_l_1bc5);
x86_l_1bb8:
	/* 0x1bb8: mov    rax,QWORD PTR [rip+0x30fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1bbf:
	/* 0x1bbf: imul   ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_1bc2:
	/* 0x1bc2: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1bc5:
	/* 0x1bc5: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1bc9:
	/* 0x1bc9: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bce:
	/* 0x1bce: je     1bdf <tail_nodeport_nat_ingress_ipv4+0x1bdf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1bce, 0x1bdf, x86_l_1bdf);
x86_l_1bd0:
	/* 0x1bd0: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_1bd5:
	/* 0x1bd5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1bd7:
	/* 0x1bd7: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1bd9:
	/* 0x1bd9: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_1bdd:
	/* 0x1bdd: jmp    1c02 <tail_nodeport_nat_ingress_ipv4+0x1c02> */
	X86_SIM_X86_JMP(0x1bdd, 0x1c02, x86_l_1c02);
x86_l_1bdf:
	/* 0x1bdf: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1be4:
	/* 0x1be4: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1be6:
	/* 0x1be6: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1be8:
	/* 0x1be8: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1bec:
	/* 0x1bec: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_1bf6:
	/* 0x1bf6: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1bf9:
	/* 0x1bf9: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1bfe:
	/* 0x1bfe: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_1c02:
	/* 0x1c02: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1c04:
	/* 0x1c04: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1c07:
	/* 0x1c07: mov    DWORD PTR [r15+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1c0b:
	/* 0x1c0b: movzx  ecx,BYTE PTR [r15+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_1c10:
	/* 0x1c10: mov    edx,DWORD PTR [r15+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1c14:
	/* 0x1c14: and    r14b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_1c18:
	/* 0x1c18: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c1d:
	/* 0x1c1d: je     1c30 <tail_nodeport_nat_ingress_ipv4+0x1c30> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1c1d, 0x1c30, x86_l_1c30);
x86_l_1c1f:
	/* 0x1c1f: mov    rsi,QWORD PTR [rip+0x30fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1c26:
	/* 0x1c26: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c28:
	/* 0x1c28: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_1c2b:
	/* 0x1c2b: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1c2e:
	/* 0x1c2e: jmp    1c35 <tail_nodeport_nat_ingress_ipv4+0x1c35> */
	X86_SIM_X86_JMP(0x1c2e, 0x1c35, x86_l_1c35);
x86_l_1c30:
	/* 0x1c30: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_1c35:
	/* 0x1c35: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1c37:
	/* 0x1c37: or     r14b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_1c3a:
	/* 0x1c3a: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_1c3c:
	/* 0x1c3c: jb     1c43 <tail_nodeport_nat_ingress_ipv4+0x1c43> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1c3c, 0x1c43, x86_l_1c43);
x86_l_1c3e:
	/* 0x1c3e: cmp    cl,r14b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R14, X86_WIDTH_8);
x86_l_1c41:
	/* 0x1c41: je     1c54 <tail_nodeport_nat_ingress_ipv4+0x1c54> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1c41, 0x1c54, x86_l_1c54);
x86_l_1c43:
	/* 0x1c43: mov    BYTE PTR [r15+0x2b],r14b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R14, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_1c47:
	/* 0x1c47: mov    DWORD PTR [r15+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1c4b:
	/* 0x1c4b: mov    rax,QWORD PTR [rip+0x30fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_1c52:
	/* 0x1c52: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c54:
	/* 0x1c54: mov    r13d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1c59:
	/* 0x1c59: jmp    1019 <tail_nodeport_nat_ingress_ipv4+0x1019> */
	X86_SIM_X86_JMP(0x1c59, 0x1019, x86_l_1019);
x86_l_1c5e:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
