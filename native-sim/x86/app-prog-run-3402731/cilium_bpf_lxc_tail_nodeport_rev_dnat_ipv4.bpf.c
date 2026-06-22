extern char __config_debug_lb;
extern char __config_enable_conntrack_accounting;
extern char __config_enable_ipv4_fragments;
extern char __config_enable_jiffies;
extern char __config_kernel_hz;
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
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int cilium_bpf_lxc_tail_nodeport_rev_dnat_ipv4_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0xa: sub    rsp,0xa8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 168ULL);
x86_l_11:
	/* 0x11: mov    rax,QWORD PTR [rip+0x26f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_18:
	/* 0x18: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a:
	/* 0x1a: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_23:
	/* 0x23: mov    DWORD PTR [rsp+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_2e:
	/* 0x2e: mov    QWORD PTR [rsp+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_3a:
	/* 0x3a: mov    QWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_46:
	/* 0x46: mov    QWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_52:
	/* 0x52: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_5b:
	/* 0x5b: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_64:
	/* 0x64: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_6d:
	/* 0x6d: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_76:
	/* 0x76: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_79:
	/* 0x79: mov    BYTE PTR [rsp+0x58],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 377957122050ULL);
x86_l_7e:
	/* 0x7e: mov    rax,QWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_82:
	/* 0x82: mov    ecx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 0ULL);
x86_l_87:
	/* 0x87: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8a:
	/* 0x8a: je     92 <tail_nodeport_rev_dnat_ipv4+0x92> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8a, 0x92, x86_l_92);
x86_l_8c:
	/* 0x8c: mov    ecx,DWORD PTR [rax+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_92:
	/* 0x92: mov    DWORD PTR [rsp+0x60],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_96:
	/* 0x96: mov    WORD PTR [rsp+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_9d:
	/* 0x9d: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_a5:
	/* 0xa5: mov    rax,QWORD PTR [rip+0x26f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_security_label)));
x86_l_ac:
	/* 0xac: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ae:
	/* 0xae: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_b1:
	/* 0xb1: sub    eax,DWORD PTR [rbx+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_b4:
	/* 0xb4: cmp    eax,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 34ULL);
x86_l_b7:
	/* 0xb7: jae    c6 <tail_nodeport_rev_dnat_ipv4+0xc6> */
	X86_SIM_X86_JCC(X86_CC_AE, 0xb7, 0xc6, x86_l_c6);
x86_l_b9:
	/* 0xb9: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bc:
	/* 0xbc: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_c1:
	/* 0xc1: jmp    aae <tail_nodeport_rev_dnat_ipv4+0xaae> */
	X86_SIM_X86_JMP(0xc1, 0xaae, x86_l_aae);
x86_l_c6:
	/* 0xc6: movabs r8,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_64, 2199023255552ULL);
x86_l_d0:
	/* 0xd0: movabs rbp,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 1099511627776ULL);
x86_l_da:
	/* 0xda: mov    rdx,QWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_e1:
	/* 0xe1: movzx  ecx,WORD PTR [rdx+0x12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18ULL);
x86_l_e5:
	/* 0xe5: movzx  eax,BYTE PTR [rdx+0x17] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 23ULL);
x86_l_e9:
	/* 0xe9: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_ec:
	/* 0xec: shl    rsi,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_f0:
	/* 0xf0: or     rsi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_f3:
	/* 0xf3: movzx  ecx,WORD PTR [rdx+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 20ULL);
x86_l_f7:
	/* 0xf7: lea    rdi,[rsi+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_fb:
	/* 0xfb: test   ecx,0xff3f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_32, 65343ULL);
x86_l_101:
	/* 0x101: cmove  rdi,rsi */
	X86_SIM_L_EXEC_CMOV(X86_RDI, X86_RSI, X86_WIDTH_64, X86_CC_E);
x86_l_105:
	/* 0x105: lea    r13,[rdi+r8*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_109:
	/* 0x109: test   ecx,0xff1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_32, 65311ULL);
x86_l_10f:
	/* 0x10f: cmove  r13,rdi */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RDI, X86_WIDTH_64, X86_CC_E);
x86_l_113:
	/* 0x113: mov    esi,DWORD PTR [rdx+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_116:
	/* 0x116: mov    BYTE PTR [rsp+0x34],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_11a:
	/* 0x11a: mov    ecx,DWORD PTR [rdx+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_11d:
	/* 0x11d: mov    DWORD PTR [rsp+0x28],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_121:
	/* 0x121: mov    edx,DWORD PTR [rdx+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_124:
	/* 0x124: mov    DWORD PTR [rsp+0x2c],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_128:
	/* 0x128: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_12b:
	/* 0x12b: je     136 <tail_nodeport_rev_dnat_ipv4+0x136> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12b, 0x136, x86_l_136);
x86_l_12d:
	/* 0x12d: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_130:
	/* 0x130: jne    aa6 <tail_nodeport_rev_dnat_ipv4+0xaa6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x130, 0xaa6, x86_l_aa6);
x86_l_136:
	/* 0x136: and    esi,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_139:
	/* 0x139: lea    r14d,[rsi*4+0xe] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 14ULL);
x86_l_141:
	/* 0x141: lea    r15,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_146:
	/* 0x146: mov    r12,QWORD PTR [rip+0x26f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&__config_enable_ipv4_fragments)));
x86_l_14d:
	/* 0x14d: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_152:
	/* 0x152: je     21f <tail_nodeport_rev_dnat_ipv4+0x21f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x152, 0x21f, x86_l_21f);
x86_l_158:
	/* 0x158: mov    DWORD PTR [rsp+0x40],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_15c:
	/* 0x15c: mov    DWORD PTR [rsp+0x44],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_160:
	/* 0x160: mov    WORD PTR [rsp+0x48],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_166:
	/* 0x166: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_169:
	/* 0x169: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_16d:
	/* 0x16d: mov    BYTE PTR [rsp+0x4a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 74ULL);
x86_l_171:
	/* 0x171: mov    BYTE PTR [rsp+0x4b],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 322122547200ULL);
x86_l_176:
	/* 0x176: movabs rax,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2199023255552ULL);
x86_l_180:
	/* 0x180: test   r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_183:
	/* 0x183: jne    950 <tail_nodeport_rev_dnat_ipv4+0x950> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x183, 0x950, x86_l_950);
x86_l_189:
	/* 0x189: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_18e:
	/* 0x18e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_191:
	/* 0x191: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_194:
	/* 0x194: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_197:
	/* 0x197: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_19c:
	/* 0x19c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19e:
	/* 0x19e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1a0:
	/* 0x1a0: js     279 <tail_nodeport_rev_dnat_ipv4+0x279> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1a0, 0x279, x86_l_279);
x86_l_1a6:
	/* 0x1a6: test   r13,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_RBP, X86_WIDTH_64);
x86_l_1a9:
	/* 0x1a9: je     24b <tail_nodeport_rev_dnat_ipv4+0x24b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a9, 0x24b, x86_l_24b);
x86_l_1af:
	/* 0x1af: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1b4:
	/* 0x1b4: mov    rdi,QWORD PTR [rip+0x26f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv4_frag_datagrams)));
x86_l_1bb:
	/* 0x1bb: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1c0:
	/* 0x1c0: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1c3:
	/* 0x1c3: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c5:
	/* 0x1c5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c7:
	/* 0x1c7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1c9:
	/* 0x1c9: je     24b <tail_nodeport_rev_dnat_ipv4+0x24b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1c9, 0x24b, x86_l_24b);
x86_l_1cf:
	/* 0x1cf: mov    r15,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R14, X86_WIDTH_64);
x86_l_1d2:
	/* 0x1d2: mov    r14d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1d6:
	/* 0x1d6: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1df:
	/* 0x1df: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1e8:
	/* 0x1e8: movabs rax,0x6b0085020a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 459570217482ULL);
x86_l_1f2:
	/* 0x1f2: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1f7:
	/* 0x1f7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1fc:
	/* 0x1fc: mov    rdi,QWORD PTR [rip+0x26ec] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_203:
	/* 0x203: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_208:
	/* 0x208: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20a:
	/* 0x20a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_20d:
	/* 0x20d: je     991 <tail_nodeport_rev_dnat_ipv4+0x991> */
	X86_SIM_X86_JCC(X86_CC_E, 0x20d, 0x991, x86_l_991);
x86_l_213:
	/* 0x213: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_216:
	/* 0x216: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_21a:
	/* 0x21a: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_21d:
	/* 0x21d: jmp    24b <tail_nodeport_rev_dnat_ipv4+0x24b> */
	X86_SIM_X86_JMP(0x21d, 0x24b, x86_l_24b);
x86_l_21f:
	/* 0x21f: movabs rax,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2199023255552ULL);
x86_l_229:
	/* 0x229: test   r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_22c:
	/* 0x22c: jne    973 <tail_nodeport_rev_dnat_ipv4+0x973> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x22c, 0x973, x86_l_973);
x86_l_232:
	/* 0x232: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_237:
	/* 0x237: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_23a:
	/* 0x23a: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_23d:
	/* 0x23d: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_240:
	/* 0x240: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_245:
	/* 0x245: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_247:
	/* 0x247: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_249:
	/* 0x249: js     279 <tail_nodeport_rev_dnat_ipv4+0x279> */
	X86_SIM_X86_JCC(X86_CC_S, 0x249, 0x279, x86_l_279);
x86_l_24b:
	/* 0x24b: mov    QWORD PTR [rsp+0x50],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_250:
	/* 0x250: movzx  r14d,BYTE PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 52ULL);
x86_l_256:
	/* 0x256: cmp    r14b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 6ULL);
x86_l_25a:
	/* 0x25a: jne    283 <tail_nodeport_rev_dnat_ipv4+0x283> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x25a, 0x283, x86_l_283);
x86_l_25c:
	/* 0x25c: mov    r15,QWORD PTR [rip+0x26ec] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&cilium_ct4_global)));
x86_l_263:
	/* 0x263: mov    BYTE PTR [rsp+0x35],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 227633266688ULL);
x86_l_268:
	/* 0x268: mov    DWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_270:
	/* 0x270: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_275:
	/* 0x275: jne    29e <tail_nodeport_rev_dnat_ipv4+0x29e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x275, 0x29e, x86_l_29e);
x86_l_277:
	/* 0x277: jmp    2e7 <tail_nodeport_rev_dnat_ipv4+0x2e7> */
	X86_SIM_X86_JMP(0x277, 0x2e7, x86_l_2e7);
x86_l_279:
	/* 0x279: mov    eax,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967161ULL);
x86_l_27e:
	/* 0x27e: jmp    aab <tail_nodeport_rev_dnat_ipv4+0xaab> */
	X86_SIM_X86_JMP(0x27e, 0xaab, x86_l_aab);
x86_l_283:
	/* 0x283: mov    r15,QWORD PTR [rip+0x26ec] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&cilium_ct_any4_global)));
x86_l_28a:
	/* 0x28a: mov    BYTE PTR [rsp+0x35],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 227633266688ULL);
x86_l_28f:
	/* 0x28f: mov    DWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_297:
	/* 0x297: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29c:
	/* 0x29c: je     2e7 <tail_nodeport_rev_dnat_ipv4+0x2e7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x29c, 0x2e7, x86_l_2e7);
x86_l_29e:
	/* 0x29e: and    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_2a1:
	/* 0x2a1: je     2e7 <tail_nodeport_rev_dnat_ipv4+0x2e7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2a1, 0x2e7, x86_l_2e7);
x86_l_2a3:
	/* 0x2a3: mov    r12d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2a7:
	/* 0x2a7: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_2b0:
	/* 0x2b0: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2b9:
	/* 0x2b9: movabs rax,0x6c03a50109 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 463917613321ULL);
x86_l_2c3:
	/* 0x2c3: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2c8:
	/* 0x2c8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2cd:
	/* 0x2cd: mov    rdi,QWORD PTR [rip+0x26ec] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_2d4:
	/* 0x2d4: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2d9:
	/* 0x2d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2db:
	/* 0x2db: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2de:
	/* 0x2de: je     354 <tail_nodeport_rev_dnat_ipv4+0x354> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2de, 0x354, x86_l_354);
x86_l_2e0:
	/* 0x2e0: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2e3:
	/* 0x2e3: add    QWORD PTR [rax+0x8],r12 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2e7:
	/* 0x2e7: cmp    r14b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 6ULL);
x86_l_2eb:
	/* 0x2eb: jne    386 <tail_nodeport_rev_dnat_ipv4+0x386> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2eb, 0x386, x86_l_386);
x86_l_2f1:
	/* 0x2f1: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_2f4:
	/* 0x2f4: movabs rcx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2199023255552ULL);
x86_l_2fe:
	/* 0x2fe: and    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_301:
	/* 0x301: jne    386 <tail_nodeport_rev_dnat_ipv4+0x386> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x301, 0x386, x86_l_386);
x86_l_307:
	/* 0x307: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_30c:
	/* 0x30c: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_311:
	/* 0x311: lea    esi,[rcx+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_314:
	/* 0x314: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_319:
	/* 0x319: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_31c:
	/* 0x31c: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_321:
	/* 0x321: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_323:
	/* 0x323: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_325:
	/* 0x325: js     aa6 <tail_nodeport_rev_dnat_ipv4+0xaa6> */
	X86_SIM_X86_JCC(X86_CC_S, 0x325, 0xaa6, x86_l_aa6);
x86_l_32b:
	/* 0x32b: mov    r12d,DWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_330:
	/* 0x330: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_333:
	/* 0x333: and    eax,0x1200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4608ULL);
x86_l_338:
	/* 0x338: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_33a:
	/* 0x33a: cmp    eax,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 512ULL);
x86_l_33f:
	/* 0x33f: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_342:
	/* 0x342: test   r12d,0x500 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R12, X86_WIDTH_32, 1280ULL);
x86_l_349:
	/* 0x349: jne    987 <tail_nodeport_rev_dnat_ipv4+0x987> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x349, 0x987, x86_l_987);
x86_l_34f:
	/* 0x34f: mov    bpl,al */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_8);
x86_l_352:
	/* 0x352: jmp    38d <tail_nodeport_rev_dnat_ipv4+0x38d> */
	X86_SIM_X86_JMP(0x352, 0x38d, x86_l_38d);
x86_l_354:
	/* 0x354: mov    QWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_35d:
	/* 0x35d: mov    QWORD PTR [rsp+0x18],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_362:
	/* 0x362: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_367:
	/* 0x367: mov    rdi,QWORD PTR [rip+0x26e8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_36e:
	/* 0x36e: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_373:
	/* 0x373: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_378:
	/* 0x378: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_37a:
	/* 0x37a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37c:
	/* 0x37c: cmp    r14b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 6ULL);
x86_l_380:
	/* 0x380: je     2f1 <tail_nodeport_rev_dnat_ipv4+0x2f1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x380, 0x2f1, x86_l_2f1);
x86_l_386:
	/* 0x386: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_388:
	/* 0x388: mov    r12d,DWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_38d:
	/* 0x38d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_392:
	/* 0x392: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_397:
	/* 0x397: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_39a:
	/* 0x39a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39c:
	/* 0x39c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_39f:
	/* 0x39f: je     a9d <tail_nodeport_rev_dnat_ipv4+0xa9d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x39f, 0xa9d, x86_l_a9d);
x86_l_3a5:
	/* 0x3a5: movzx  ecx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_3a9:
	/* 0x3a9: test   cl,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_3ac:
	/* 0x3ac: je     a9d <tail_nodeport_rev_dnat_ipv4+0xa9d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3ac, 0xa9d, x86_l_a9d);
x86_l_3b2:
	/* 0x3b2: cmp    WORD PTR [rax+0x26],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 163208757248ULL);
x86_l_3b7:
	/* 0x3b7: je     a9d <tail_nodeport_rev_dnat_ipv4+0xa9d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3b7, 0xa9d, x86_l_a9d);
x86_l_3bd:
	/* 0x3bd: mov    DWORD PTR [rsp+0xc],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3c2:
	/* 0x3c2: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_3c4:
	/* 0x3c4: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_3c6:
	/* 0x3c6: test   dl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_8, 3ULL);
x86_l_3c9:
	/* 0x3c9: je     4d4 <tail_nodeport_rev_dnat_ipv4+0x4d4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3c9, 0x4d4, x86_l_4d4);
x86_l_3cf:
	/* 0x3cf: mov    rsi,QWORD PTR [rip+0x26e8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_3d6:
	/* 0x3d6: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3d9:
	/* 0x3d9: je     3ec <tail_nodeport_rev_dnat_ipv4+0x3ec> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3d9, 0x3ec, x86_l_3ec);
x86_l_3db:
	/* 0x3db: mov    rdx,QWORD PTR [rip+0x26e8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_3e2:
	/* 0x3e2: imul   r15d,DWORD PTR [rdx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R15, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_3e6:
	/* 0x3e6: shr    r15d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_3ea:
	/* 0x3ea: jmp    3f2 <tail_nodeport_rev_dnat_ipv4+0x3f2> */
	X86_SIM_X86_JMP(0x3ea, 0x3f2, x86_l_3f2);
x86_l_3ec:
	/* 0x3ec: mov    r15d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 60ULL);
x86_l_3f2:
	/* 0x3f2: mov    r12d,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3f7:
	/* 0x3f7: cmp    r14b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 6ULL);
x86_l_3fb:
	/* 0x3fb: jne    434 <tail_nodeport_rev_dnat_ipv4+0x434> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3fb, 0x434, x86_l_434);
x86_l_3fd:
	/* 0x3fd: mov    edx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_32);
x86_l_400:
	/* 0x400: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_402:
	/* 0x402: shr    edx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_405:
	/* 0x405: and    edx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_408:
	/* 0x408: or     ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_40a:
	/* 0x40a: mov    WORD PTR [rax+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_40e:
	/* 0x40e: test   cl,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 16ULL);
x86_l_411:
	/* 0x411: mov    ecx,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 60ULL);
x86_l_416:
	/* 0x416: mov    r15d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 21600ULL);
x86_l_41c:
	/* 0x41c: cmove  r15d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R15, X86_RCX, X86_WIDTH_32, X86_CC_E);
x86_l_420:
	/* 0x420: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_423:
	/* 0x423: je     434 <tail_nodeport_rev_dnat_ipv4+0x434> */
	X86_SIM_X86_JCC(X86_CC_E, 0x423, 0x434, x86_l_434);
x86_l_425:
	/* 0x425: mov    rcx,QWORD PTR [rip+0x26e8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_42c:
	/* 0x42c: imul   r15d,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_430:
	/* 0x430: shr    r15d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_434:
	/* 0x434: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_43c:
	/* 0x43c: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_440:
	/* 0x440: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_443:
	/* 0x443: je     457 <tail_nodeport_rev_dnat_ipv4+0x457> */
	X86_SIM_X86_JCC(X86_CC_E, 0x443, 0x457, x86_l_457);
x86_l_445:
	/* 0x445: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_44a:
	/* 0x44a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_44c:
	/* 0x44c: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_44e:
	/* 0x44e: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_451:
	/* 0x451: shr    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_455:
	/* 0x455: jmp    47a <tail_nodeport_rev_dnat_ipv4+0x47a> */
	X86_SIM_X86_JMP(0x455, 0x47a, x86_l_47a);
x86_l_457:
	/* 0x457: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_45c:
	/* 0x45c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_45e:
	/* 0x45e: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_460:
	/* 0x460: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_464:
	/* 0x464: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_46e:
	/* 0x46e: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_471:
	/* 0x471: mulx   rcx,rcx,rcx */
	X86_SIM_L_EXEC_MULX(X86_RCX, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_476:
	/* 0x476: shr    rcx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_47a:
	/* 0x47a: add    r15d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_47d:
	/* 0x47d: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_485:
	/* 0x485: mov    DWORD PTR [rax+0x20],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_489:
	/* 0x489: movzx  edx,BYTE PTR [rax+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_48d:
	/* 0x48d: mov    esi,DWORD PTR [rax+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_490:
	/* 0x490: and    r12b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_494:
	/* 0x494: mov    rdi,QWORD PTR [rip+0x26e8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_49b:
	/* 0x49b: cmp    BYTE PTR [rdi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_49e:
	/* 0x49e: je     4b1 <tail_nodeport_rev_dnat_ipv4+0x4b1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x49e, 0x4b1, x86_l_4b1);
x86_l_4a0:
	/* 0x4a0: mov    rdi,QWORD PTR [rip+0x26e8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_4a7:
	/* 0x4a7: mov    edi,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4a9:
	/* 0x4a9: lea    edi,[rdi+rdi*4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_4ac:
	/* 0x4ac: shr    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_4af:
	/* 0x4af: jmp    4b6 <tail_nodeport_rev_dnat_ipv4+0x4b6> */
	X86_SIM_X86_JMP(0x4af, 0x4b6, x86_l_4b6);
x86_l_4b1:
	/* 0x4b1: mov    edi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 5ULL);
x86_l_4b6:
	/* 0x4b6: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_4b8:
	/* 0x4b8: or     r12b,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_4bb:
	/* 0x4bb: cmp    edi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RCX, X86_WIDTH_32);
x86_l_4bd:
	/* 0x4bd: jb     4c4 <tail_nodeport_rev_dnat_ipv4+0x4c4> */
	X86_SIM_X86_JCC(X86_CC_B, 0x4bd, 0x4c4, x86_l_4c4);
x86_l_4bf:
	/* 0x4bf: cmp    dl,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_8);
x86_l_4c2:
	/* 0x4c2: je     4d4 <tail_nodeport_rev_dnat_ipv4+0x4d4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4c2, 0x4d4, x86_l_4d4);
x86_l_4c4:
	/* 0x4c4: mov    BYTE PTR [rax+0x2b],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_4c8:
	/* 0x4c8: mov    DWORD PTR [rax+0x34],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_4cb:
	/* 0x4cb: mov    rcx,QWORD PTR [rip+0x26e8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_4d2:
	/* 0x4d2: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4d4:
	/* 0x4d4: mov    rcx,QWORD PTR [rip+0x26e8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_4db:
	/* 0x4db: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4de:
	/* 0x4de: je     4ed <tail_nodeport_rev_dnat_ipv4+0x4ed> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4de, 0x4ed, x86_l_4ed);
x86_l_4e0:
	/* 0x4e0: inc QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 16ULL);
x86_l_4e5:
	/* 0x4e5: mov    ecx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_4e8:
	/* 0x4e8: add QWORD PTR [rax+0x18],rcx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_4ed:
	/* 0x4ed: cmp    ebp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_4f0:
	/* 0x4f0: mov    r12d,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_4f5:
	/* 0x4f5: je     544 <tail_nodeport_rev_dnat_ipv4+0x544> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4f5, 0x544, x86_l_544);
x86_l_4f7:
	/* 0x4f7: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_4fa:
	/* 0x4fa: jne    623 <tail_nodeport_rev_dnat_ipv4+0x623> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4fa, 0x623, x86_l_623);
x86_l_500:
	/* 0x500: movzx  ecx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_504:
	/* 0x504: test   cl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_507:
	/* 0x507: je     623 <tail_nodeport_rev_dnat_ipv4+0x623> */
	X86_SIM_X86_JCC(X86_CC_E, 0x507, 0x623, x86_l_623);
x86_l_50d:
	/* 0x50d: mov    WORD PTR [rax+0x2a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 180388626432ULL);
x86_l_513:
	/* 0x513: and    ecx,0xffec */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 65516ULL);
x86_l_519:
	/* 0x519: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_51c:
	/* 0x51c: mov    WORD PTR [rax+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_520:
	/* 0x520: mov    r12,QWORD PTR [rip+0x26e8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_527:
	/* 0x527: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_52c:
	/* 0x52c: je     9c1 <tail_nodeport_rev_dnat_ipv4+0x9c1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x52c, 0x9c1, x86_l_9c1);
x86_l_532:
	/* 0x532: mov    rax,QWORD PTR [rip+0x26e8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_539:
	/* 0x539: imul   ebp,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_53c:
	/* 0x53c: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_53f:
	/* 0x53f: jmp    9c6 <tail_nodeport_rev_dnat_ipv4+0x9c6> */
	X86_SIM_X86_JMP(0x53f, 0x9c6, x86_l_9c6);
x86_l_544:
	/* 0x544: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_547:
	/* 0x547: shr    ecx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_54a:
	/* 0x54a: and    ecx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2ULL);
x86_l_54d:
	/* 0x54d: or     cx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RAX, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 36ULL);
x86_l_551:
	/* 0x551: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_553:
	/* 0x553: or     edx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_OR, 1ULL);
x86_l_556:
	/* 0x556: mov    WORD PTR [rax+0x24],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_55a:
	/* 0x55a: mov    rdx,QWORD PTR [rip+0x26e8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_561:
	/* 0x561: mov    edx,DWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_563:
	/* 0x563: test   cl,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_566:
	/* 0x566: je     623 <tail_nodeport_rev_dnat_ipv4+0x623> */
	X86_SIM_X86_JCC(X86_CC_E, 0x566, 0x623, x86_l_623);
x86_l_56c:
	/* 0x56c: mov    r14,QWORD PTR [rip+0x26e8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_573:
	/* 0x573: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_577:
	/* 0x577: je     58c <tail_nodeport_rev_dnat_ipv4+0x58c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x577, 0x58c, x86_l_58c);
x86_l_579:
	/* 0x579: mov    rcx,QWORD PTR [rip+0x26e8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_580:
	/* 0x580: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_582:
	/* 0x582: add    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_584:
	/* 0x584: lea    ebp,[rcx+rcx*4] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 0ULL);
x86_l_587:
	/* 0x587: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_58a:
	/* 0x58a: jmp    591 <tail_nodeport_rev_dnat_ipv4+0x591> */
	X86_SIM_X86_JMP(0x58a, 0x591, x86_l_591);
x86_l_58c:
	/* 0x58c: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_591:
	/* 0x591: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_594:
	/* 0x594: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_598:
	/* 0x598: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_59c:
	/* 0x59c: je     5b0 <tail_nodeport_rev_dnat_ipv4+0x5b0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x59c, 0x5b0, x86_l_5b0);
x86_l_59e:
	/* 0x59e: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_5a3:
	/* 0x5a3: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5a5:
	/* 0x5a5: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_5a7:
	/* 0x5a7: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_5aa:
	/* 0x5aa: shr    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_5ae:
	/* 0x5ae: jmp    5d3 <tail_nodeport_rev_dnat_ipv4+0x5d3> */
	X86_SIM_X86_JMP(0x5ae, 0x5d3, x86_l_5d3);
x86_l_5b0:
	/* 0x5b0: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_5b5:
	/* 0x5b5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5b7:
	/* 0x5b7: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_5b9:
	/* 0x5b9: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_5bd:
	/* 0x5bd: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_5c7:
	/* 0x5c7: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_5ca:
	/* 0x5ca: mulx   rcx,rcx,rcx */
	X86_SIM_L_EXEC_MULX(X86_RCX, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_5cf:
	/* 0x5cf: shr    rcx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_5d3:
	/* 0x5d3: add    ebp,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_5d5:
	/* 0x5d5: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_5d8:
	/* 0x5d8: mov    DWORD PTR [r15+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5dc:
	/* 0x5dc: movzx  edx,BYTE PTR [r15+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_5e1:
	/* 0x5e1: mov    esi,DWORD PTR [r15+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_5e5:
	/* 0x5e5: and    r12b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_5e9:
	/* 0x5e9: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5ed:
	/* 0x5ed: je     600 <tail_nodeport_rev_dnat_ipv4+0x600> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5ed, 0x600, x86_l_600);
x86_l_5ef:
	/* 0x5ef: mov    rdi,QWORD PTR [rip+0x26e8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_5f6:
	/* 0x5f6: mov    edi,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5f8:
	/* 0x5f8: lea    edi,[rdi+rdi*4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_5fb:
	/* 0x5fb: shr    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_5fe:
	/* 0x5fe: jmp    605 <tail_nodeport_rev_dnat_ipv4+0x605> */
	X86_SIM_X86_JMP(0x5fe, 0x605, x86_l_605);
x86_l_600:
	/* 0x600: mov    edi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 5ULL);
x86_l_605:
	/* 0x605: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_607:
	/* 0x607: or     r12b,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_60a:
	/* 0x60a: cmp    edi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RCX, X86_WIDTH_32);
x86_l_60c:
	/* 0x60c: jb     613 <tail_nodeport_rev_dnat_ipv4+0x613> */
	X86_SIM_X86_JCC(X86_CC_B, 0x60c, 0x613, x86_l_613);
x86_l_60e:
	/* 0x60e: cmp    dl,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_8);
x86_l_611:
	/* 0x611: je     623 <tail_nodeport_rev_dnat_ipv4+0x623> */
	X86_SIM_X86_JCC(X86_CC_E, 0x611, 0x623, x86_l_623);
x86_l_613:
	/* 0x613: mov    BYTE PTR [rax+0x2b],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_617:
	/* 0x617: mov    DWORD PTR [rax+0x34],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_61a:
	/* 0x61a: mov    rcx,QWORD PTR [rip+0x26e8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_621:
	/* 0x621: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_623:
	/* 0x623: test   BYTE PTR [rsp+0x35],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 227633266690ULL);
x86_l_628:
	/* 0x628: jne    aa6 <tail_nodeport_rev_dnat_ipv4+0xaa6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x628, 0xaa6, x86_l_aa6);
x86_l_62e:
	/* 0x62e: movzx  eax,WORD PTR [rax+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_632:
	/* 0x632: mov    WORD PTR [rsp+0x10],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_637:
	/* 0x637: mov    r14,QWORD PTR [rip+0x26e8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_63e:
	/* 0x63e: movzx  eax,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_642:
	/* 0x642: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_647:
	/* 0x647: mov    rdi,QWORD PTR [rip+0x26e8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_reverse_nat)));
x86_l_64e:
	/* 0x64e: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_653:
	/* 0x653: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_655:
	/* 0x655: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_658:
	/* 0x658: je     7f8 <tail_nodeport_rev_dnat_ipv4+0x7f8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x658, 0x7f8, x86_l_7f8);
x86_l_65e:
	/* 0x65e: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_661:
	/* 0x661: mov    r15d,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_666:
	/* 0x666: movzx  eax,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_66a:
	/* 0x66a: mov    eax,DWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_66e:
	/* 0x66e: mov    DWORD PTR [rsp+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_672:
	/* 0x672: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_677:
	/* 0x677: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_67a:
	/* 0x67a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_67d:
	/* 0x67d: mov    esi,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 26ULL);
x86_l_682:
	/* 0x682: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_685:
	/* 0x685: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_68a:
	/* 0x68a: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_68d:
	/* 0x68d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_68f:
	/* 0x68f: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_691:
	/* 0x691: mov    eax,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967155ULL);
x86_l_696:
	/* 0x696: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_698:
	/* 0x698: js     aae <tail_nodeport_rev_dnat_ipv4+0xaae> */
	X86_SIM_X86_JCC(X86_CC_S, 0x698, 0xaae, x86_l_aae);
x86_l_69e:
	/* 0x69e: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_6a1:
	/* 0x6a1: je     aae <tail_nodeport_rev_dnat_ipv4+0xaae> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6a1, 0xaae, x86_l_aae);
x86_l_6a7:
	/* 0x6a7: not    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_6aa:
	/* 0x6aa: add    r15d,DWORD PTR [r12] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_R12, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_6ae:
	/* 0x6ae: adc    r15d,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_6b2:
	/* 0x6b2: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6b5:
	/* 0x6b5: mov    eax,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_6ba:
	/* 0x6ba: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_6bd:
	/* 0x6bd: mov    esi,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 24ULL);
x86_l_6c2:
	/* 0x6c2: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6c4:
	/* 0x6c4: mov    ecx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_32);
x86_l_6c7:
	/* 0x6c7: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6ca:
	/* 0x6ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6cc:
	/* 0x6cc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_6ce:
	/* 0x6ce: js     700 <tail_nodeport_rev_dnat_ipv4+0x700> */
	X86_SIM_X86_JCC(X86_CC_S, 0x6ce, 0x700, x86_l_700);
x86_l_6d0:
	/* 0x6d0: movabs rax,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2199023255552ULL);
x86_l_6da:
	/* 0x6da: test   r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_6dd:
	/* 0x6dd: jne    7f8 <tail_nodeport_rev_dnat_ipv4+0x7f8> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x6dd, 0x7f8, x86_l_7f8);
x86_l_6e3:
	/* 0x6e3: movzx  ecx,BYTE PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 52ULL);
x86_l_6e8:
	/* 0x6e8: cmp    ecx,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 58ULL);
x86_l_6eb:
	/* 0x6eb: je     719 <tail_nodeport_rev_dnat_ipv4+0x719> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6eb, 0x719, x86_l_719);
x86_l_6ed:
	/* 0x6ed: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_6f0:
	/* 0x6f0: je     70a <tail_nodeport_rev_dnat_ipv4+0x70a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6f0, 0x70a, x86_l_70a);
x86_l_6f2:
	/* 0x6f2: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_6f5:
	/* 0x6f5: jne    722 <tail_nodeport_rev_dnat_ipv4+0x722> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x6f5, 0x722, x86_l_722);
x86_l_6f7:
	/* 0x6f7: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6f9:
	/* 0x6f9: mov    ebp,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 16ULL);
x86_l_6fe:
	/* 0x6fe: jmp    727 <tail_nodeport_rev_dnat_ipv4+0x727> */
	X86_SIM_X86_JMP(0x6fe, 0x727, x86_l_727);
x86_l_700:
	/* 0x700: mov    eax,0xffffff67 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967143ULL);
x86_l_705:
	/* 0x705: jmp    aae <tail_nodeport_rev_dnat_ipv4+0xaae> */
	X86_SIM_X86_JMP(0x705, 0xaae, x86_l_aae);
x86_l_70a:
	/* 0x70a: mov    r13d,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 32ULL);
x86_l_710:
	/* 0x710: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_715:
	/* 0x715: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_717:
	/* 0x717: jmp    72a <tail_nodeport_rev_dnat_ipv4+0x72a> */
	X86_SIM_X86_JMP(0x717, 0x72a, x86_l_72a);
x86_l_719:
	/* 0x719: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_71b:
	/* 0x71b: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_720:
	/* 0x720: jmp    727 <tail_nodeport_rev_dnat_ipv4+0x727> */
	X86_SIM_X86_JMP(0x720, 0x727, x86_l_727);
x86_l_722:
	/* 0x722: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_724:
	/* 0x724: mov    sil,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_8, 1ULL);
x86_l_727:
	/* 0x727: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_72a:
	/* 0x72a: movzx  edx,WORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_730:
	/* 0x730: test   dx,dx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_16);
x86_l_733:
	/* 0x733: je     7cc <tail_nodeport_rev_dnat_ipv4+0x7cc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x733, 0x7cc, x86_l_7cc);
x86_l_739:
	/* 0x739: movzx  r12d,WORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_73f:
	/* 0x73f: mov    eax,0xffffff72 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967154ULL);
x86_l_744:
	/* 0x744: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_747:
	/* 0x747: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_74a:
	/* 0x74a: jg     75b <tail_nodeport_rev_dnat_ipv4+0x75b> */
	X86_SIM_X86_JCC(X86_CC_G, 0x74a, 0x75b, x86_l_75b);
x86_l_74c:
	/* 0x74c: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_74f:
	/* 0x74f: je     7cc <tail_nodeport_rev_dnat_ipv4+0x7cc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x74f, 0x7cc, x86_l_7cc);
x86_l_751:
	/* 0x751: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_754:
	/* 0x754: je     769 <tail_nodeport_rev_dnat_ipv4+0x769> */
	X86_SIM_X86_JCC(X86_CC_E, 0x754, 0x769, x86_l_769);
x86_l_756:
	/* 0x756: jmp    aae <tail_nodeport_rev_dnat_ipv4+0xaae> */
	X86_SIM_X86_JMP(0x756, 0xaae, x86_l_aae);
x86_l_75b:
	/* 0x75b: cmp    ecx,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 58ULL);
x86_l_75e:
	/* 0x75e: je     7cc <tail_nodeport_rev_dnat_ipv4+0x7cc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x75e, 0x7cc, x86_l_7cc);
x86_l_760:
	/* 0x760: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_763:
	/* 0x763: jne    aae <tail_nodeport_rev_dnat_ipv4+0xaae> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x763, 0xaae, x86_l_aae);
x86_l_769:
	/* 0x769: cmp    dx,r12w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_16);
x86_l_76d:
	/* 0x76d: je     7cc <tail_nodeport_rev_dnat_ipv4+0x7cc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x76d, 0x7cc, x86_l_7cc);
x86_l_76f:
	/* 0x76f: mov    DWORD PTR [rsp+0xc],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_773:
	/* 0x773: mov    WORD PTR [rsp+0x10],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_778:
	/* 0x778: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_77d:
	/* 0x77d: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_782:
	/* 0x782: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_785:
	/* 0x785: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_788:
	/* 0x788: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_78d:
	/* 0x78d: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_792:
	/* 0x792: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_795:
	/* 0x795: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_797:
	/* 0x797: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_799:
	/* 0x799: js     946 <tail_nodeport_rev_dnat_ipv4+0x946> */
	X86_SIM_X86_JCC(X86_CC_S, 0x799, 0x946, x86_l_946);
x86_l_79f:
	/* 0x79f: movzx  ecx,WORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_7a4:
	/* 0x7a4: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_7a9:
	/* 0x7a9: lea    esi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_7ac:
	/* 0x7ac: mov    r8d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R13, X86_WIDTH_32);
x86_l_7af:
	/* 0x7af: or     r8d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_7b3:
	/* 0x7b3: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_7b8:
	/* 0x7b8: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_7bb:
	/* 0x7bb: mov    edx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_32);
x86_l_7be:
	/* 0x7be: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7c0:
	/* 0x7c0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_7c2:
	/* 0x7c2: js     90b <tail_nodeport_rev_dnat_ipv4+0x90b> */
	X86_SIM_X86_JCC(X86_CC_S, 0x7c2, 0x90b, x86_l_90b);
x86_l_7c8:
	/* 0x7c8: mov    esi,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_7cc:
	/* 0x7cc: test   sil,sil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_8);
x86_l_7cf:
	/* 0x7cf: jne    7f8 <tail_nodeport_rev_dnat_ipv4+0x7f8> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x7cf, 0x7f8, x86_l_7f8);
x86_l_7d1:
	/* 0x7d1: add    ebp,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 80ULL);
x86_l_7d5:
	/* 0x7d5: or     r13d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_OR, 16ULL);
x86_l_7d9:
	/* 0x7d9: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7dc:
	/* 0x7dc: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_7e1:
	/* 0x7e1: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_7e4:
	/* 0x7e4: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_7e6:
	/* 0x7e6: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7e8:
	/* 0x7e8: mov    ecx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_32);
x86_l_7eb:
	/* 0x7eb: mov    r8d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R13, X86_WIDTH_32);
x86_l_7ee:
	/* 0x7ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7f0:
	/* 0x7f0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_7f2:
	/* 0x7f2: js     90b <tail_nodeport_rev_dnat_ipv4+0x90b> */
	X86_SIM_X86_JCC(X86_CC_S, 0x7f2, 0x90b, x86_l_90b);
x86_l_7f8:
	/* 0x7f8: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_7fb:
	/* 0x7fb: sub    eax,DWORD PTR [rbx+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_7fe:
	/* 0x7fe: cmp    eax,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 34ULL);
x86_l_801:
	/* 0x801: jb     b9 <tail_nodeport_rev_dnat_ipv4+0xb9> */
	X86_SIM_X86_JCC(X86_CC_B, 0x801, 0xb9, x86_l_b9);
x86_l_807:
	/* 0x807: mov    rcx,QWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_80e:
	/* 0x80e: mov    eax,0xfffff0ff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294963455ULL);
x86_l_813:
	/* 0x813: and    eax,DWORD PTR [rbx+0xa8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 168ULL);
x86_l_819:
	/* 0x819: or     eax,0x300 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 768ULL);
x86_l_81e:
	/* 0x81e: mov    DWORD PTR [rbx+0xa8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_824:
	/* 0x824: mov    eax,DWORD PTR [rcx+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_827:
	/* 0x827: mov    DWORD PTR [rsp+0x68],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_82b:
	/* 0x82b: mov    eax,DWORD PTR [rcx+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_82e:
	/* 0x82e: mov    DWORD PTR [rsp+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_832:
	/* 0x832: movzx  edx,BYTE PTR [rcx+0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 22ULL);
x86_l_836:
	/* 0x836: mov    eax,0xffffff3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967100ULL);
x86_l_83b:
	/* 0x83b: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_83e:
	/* 0x83e: jb     aab <tail_nodeport_rev_dnat_ipv4+0xaab> */
	X86_SIM_X86_JCC(X86_CC_B, 0x83e, 0xaab, x86_l_aab);
x86_l_844:
	/* 0x844: lea    eax,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_847:
	/* 0x847: mov    BYTE PTR [rcx+0x16],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_84a:
	/* 0x84a: movzx  ecx,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_84d:
	/* 0x84d: mov    eax,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_852:
	/* 0x852: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_855:
	/* 0x855: mov    esi,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 24ULL);
x86_l_85a:
	/* 0x85a: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_860:
	/* 0x860: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_862:
	/* 0x862: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_864:
	/* 0x864: js     8f0 <tail_nodeport_rev_dnat_ipv4+0x8f0> */
	X86_SIM_X86_JCC(X86_CC_S, 0x864, 0x8f0, x86_l_8f0);
x86_l_86a:
	/* 0x86a: mov    eax,0x45 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 69ULL);
x86_l_86f:
	/* 0x86f: mov    rcx,QWORD PTR [rip+0x26e8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_supports_fib_lookup_skip_neigh)));
x86_l_876:
	/* 0x876: movzx  ecx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_879:
	/* 0x879: shl    ecx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 2ULL);
x86_l_87c:
	/* 0x87c: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_881:
	/* 0x881: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_884:
	/* 0x884: mov    edx,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 64ULL);
x86_l_889:
	/* 0x889: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_88b:
	/* 0x88b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_88d:
	/* 0x88d: je     894 <tail_nodeport_rev_dnat_ipv4+0x894> */
	X86_SIM_X86_JCC(X86_CC_E, 0x88d, 0x894, x86_l_894);
x86_l_88f:
	/* 0x88f: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_892:
	/* 0x892: jne    8fa <tail_nodeport_rev_dnat_ipv4+0x8fa> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x892, 0x8fa, x86_l_8fa);
x86_l_894:
	/* 0x894: mov    ebp,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_898:
	/* 0x898: mov    DWORD PTR [rsp+0x10],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_89c:
	/* 0x89c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_8a1:
	/* 0x8a1: mov    rdi,QWORD PTR [rip+0x26e8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_devices)));
x86_l_8a8:
	/* 0x8a8: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8ad:
	/* 0x8ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8af:
	/* 0x8af: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8b2:
	/* 0x8b2: je     8ba <tail_nodeport_rev_dnat_ipv4+0x8ba> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8b2, 0x8ba, x86_l_8ba);
x86_l_8b4:
	/* 0x8b4: test   BYTE PTR [rax+0x8],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_8b8:
	/* 0x8b8: jne    915 <tail_nodeport_rev_dnat_ipv4+0x915> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x8b8, 0x915, x86_l_915);
x86_l_8ba:
	/* 0x8ba: lea    rax,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_8bf:
	/* 0x8bf: movzx  ecx,BYTE PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 88ULL);
x86_l_8c4:
	/* 0x8c4: mov    DWORD PTR [rsp+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8c8:
	/* 0x8c8: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8cb:
	/* 0x8cb: mov    rax,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8cf:
	/* 0x8cf: mov    QWORD PTR [rsp+0x14],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_8d4:
	/* 0x8d4: mov    QWORD PTR [rsp+0x1c],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_8d9:
	/* 0x8d9: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8de:
	/* 0x8de: mov    eax,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 152ULL);
x86_l_8e3:
	/* 0x8e3: mov    edi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_32);
x86_l_8e5:
	/* 0x8e5: mov    edx,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 20ULL);
x86_l_8ea:
	/* 0x8ea: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8ec:
	/* 0x8ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8ee:
	/* 0x8ee: jmp    920 <tail_nodeport_rev_dnat_ipv4+0x920> */
	X86_SIM_X86_JMP(0x8ee, 0x920, x86_l_920);
x86_l_8f0:
	/* 0x8f0: mov    eax,0xffffff67 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967143ULL);
x86_l_8f5:
	/* 0x8f5: jmp    aab <tail_nodeport_rev_dnat_ipv4+0xaab> */
	X86_SIM_X86_JMP(0x8f5, 0xaab, x86_l_aab);
x86_l_8fa:
	/* 0x8fa: shl    eax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_8fd:
	/* 0x8fd: movzx  r14d,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_901:
	/* 0x901: mov    eax,0xffffff57 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967127ULL);
x86_l_906:
	/* 0x906: jmp    aae <tail_nodeport_rev_dnat_ipv4+0xaae> */
	X86_SIM_X86_JMP(0x906, 0xaae, x86_l_aae);
x86_l_90b:
	/* 0x90b: mov    eax,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967142ULL);
x86_l_910:
	/* 0x910: jmp    aae <tail_nodeport_rev_dnat_ipv4+0xaae> */
	X86_SIM_X86_JMP(0x910, 0xaae, x86_l_aae);
x86_l_915:
	/* 0x915: mov    eax,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 23ULL);
x86_l_91a:
	/* 0x91a: mov    edi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_32);
x86_l_91c:
	/* 0x91c: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_91e:
	/* 0x91e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_920:
	/* 0x920: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_923:
	/* 0x923: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_925:
	/* 0x925: js     aae <tail_nodeport_rev_dnat_ipv4+0xaae> */
	X86_SIM_X86_JCC(X86_CC_S, 0x925, 0xaae, x86_l_aae);
x86_l_92b:
	/* 0x92b: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_92e:
	/* 0x92e: je     aae <tail_nodeport_rev_dnat_ipv4+0xaae> */
	X86_SIM_X86_JCC(X86_CC_E, 0x92e, 0xaae, x86_l_aae);
x86_l_934:
	/* 0x934: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_936:
	/* 0x936: jne    b4f <tail_nodeport_rev_dnat_ipv4+0xb4f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x936, 0xb4f, x86_l_b4f);
x86_l_93c:
	/* 0x93c: mov    eax,0xffffff59 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967129ULL);
x86_l_941:
	/* 0x941: jmp    aae <tail_nodeport_rev_dnat_ipv4+0xaae> */
	X86_SIM_X86_JMP(0x941, 0xaae, x86_l_aae);
x86_l_946:
	/* 0x946: mov    eax,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967155ULL);
x86_l_94b:
	/* 0x94b: jmp    aae <tail_nodeport_rev_dnat_ipv4+0xaae> */
	X86_SIM_X86_JMP(0x94b, 0xaae, x86_l_aae);
x86_l_950:
	/* 0x950: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_955:
	/* 0x955: mov    rdi,QWORD PTR [rip+0x26e8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv4_frag_datagrams)));
x86_l_95c:
	/* 0x95c: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_961:
	/* 0x961: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_963:
	/* 0x963: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_966:
	/* 0x966: je     97d <tail_nodeport_rev_dnat_ipv4+0x97d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x966, 0x97d, x86_l_97d);
x86_l_968:
	/* 0x968: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_96a:
	/* 0x96a: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_96e:
	/* 0x96e: jmp    24b <tail_nodeport_rev_dnat_ipv4+0x24b> */
	X86_SIM_X86_JMP(0x96e, 0x24b, x86_l_24b);
x86_l_973:
	/* 0x973: mov    eax,0xffffff63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967139ULL);
x86_l_978:
	/* 0x978: jmp    aab <tail_nodeport_rev_dnat_ipv4+0xaab> */
	X86_SIM_X86_JMP(0x978, 0xaab, x86_l_aab);
x86_l_97d:
	/* 0x97d: mov    eax,0xffffff51 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967121ULL);
x86_l_982:
	/* 0x982: jmp    aab <tail_nodeport_rev_dnat_ipv4+0xaab> */
	X86_SIM_X86_JMP(0x982, 0xaab, x86_l_aab);
x86_l_987:
	/* 0x987: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_98c:
	/* 0x98c: jmp    38d <tail_nodeport_rev_dnat_ipv4+0x38d> */
	X86_SIM_X86_JMP(0x98c, 0x38d, x86_l_38d);
x86_l_991:
	/* 0x991: mov    QWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_99a:
	/* 0x99a: mov    QWORD PTR [rsp+0x18],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_99f:
	/* 0x99f: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_9a4:
	/* 0x9a4: mov    rdi,QWORD PTR [rip+0x26e8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_9ab:
	/* 0x9ab: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_9b0:
	/* 0x9b0: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9b5:
	/* 0x9b5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9b7:
	/* 0x9b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9b9:
	/* 0x9b9: mov    r14,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_64);
x86_l_9bc:
	/* 0x9bc: jmp    24b <tail_nodeport_rev_dnat_ipv4+0x24b> */
	X86_SIM_X86_JMP(0x9bc, 0x24b, x86_l_24b);
x86_l_9c1:
	/* 0x9c1: mov    ebp,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_9c6:
	/* 0x9c6: cmp    r14b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 6ULL);
x86_l_9ca:
	/* 0x9ca: jne    a02 <tail_nodeport_rev_dnat_ipv4+0xa02> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x9ca, 0xa02, x86_l_a02);
x86_l_9cc:
	/* 0x9cc: mov    eax,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_9d0:
	/* 0x9d0: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_9d2:
	/* 0x9d2: shr    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_9d5:
	/* 0x9d5: and    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_9d8:
	/* 0x9d8: or     ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_OR);
x86_l_9da:
	/* 0x9da: mov    WORD PTR [r15+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_9df:
	/* 0x9df: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_9e1:
	/* 0x9e1: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_9e6:
	/* 0x9e6: mov    ebp,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 21600ULL);
x86_l_9eb:
	/* 0x9eb: cmove  ebp,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_9ee:
	/* 0x9ee: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9f3:
	/* 0x9f3: je     a02 <tail_nodeport_rev_dnat_ipv4+0xa02> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9f3, 0xa02, x86_l_a02);
x86_l_9f5:
	/* 0x9f5: mov    rax,QWORD PTR [rip+0x26e8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_9fc:
	/* 0x9fc: imul   ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_9ff:
	/* 0x9ff: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_a02:
	/* 0xa02: shr    DWORD PTR [rsp+0xc],0x8 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_32, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_SHR)), 51539607560ULL);
x86_l_a07:
	/* 0xa07: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a0c:
	/* 0xa0c: je     a1d <tail_nodeport_rev_dnat_ipv4+0xa1d> */
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
	/* 0xa1b: jmp    a40 <tail_nodeport_rev_dnat_ipv4+0xa40> */
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
	/* 0xa42: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_a45:
	/* 0xa45: mov    DWORD PTR [r15+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a49:
	/* 0xa49: movzx  ecx,BYTE PTR [r15+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_a4e:
	/* 0xa4e: mov    edx,DWORD PTR [r15+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_a52:
	/* 0xa52: mov    esi,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_a56:
	/* 0xa56: and    sil,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_a5a:
	/* 0xa5a: mov    DWORD PTR [rsp+0xc],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_a5e:
	/* 0xa5e: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a63:
	/* 0xa63: je     a76 <tail_nodeport_rev_dnat_ipv4+0xa76> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa63, 0xa76, x86_l_a76);
x86_l_a65:
	/* 0xa65: mov    rsi,QWORD PTR [rip+0x26e8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_a6c:
	/* 0xa6c: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a6e:
	/* 0xa6e: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_a71:
	/* 0xa71: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_a74:
	/* 0xa74: jmp    a7b <tail_nodeport_rev_dnat_ipv4+0xa7b> */
	X86_SIM_X86_JMP(0xa74, 0xa7b, x86_l_a7b);
x86_l_a76:
	/* 0xa76: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_a7b:
	/* 0xa7b: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_a7d:
	/* 0xa7d: mov    edx,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_a81:
	/* 0xa81: or     dl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_a83:
	/* 0xa83: mov    DWORD PTR [rsp+0xc],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_a87:
	/* 0xa87: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_a89:
	/* 0xa89: jb     a91 <tail_nodeport_rev_dnat_ipv4+0xa91> */
	X86_SIM_X86_JCC(X86_CC_B, 0xa89, 0xa91, x86_l_a91);
x86_l_a8b:
	/* 0xa8b: cmp    cl,BYTE PTR [rsp+0xc] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 12ULL);
x86_l_a8f:
	/* 0xa8f: je     aa6 <tail_nodeport_rev_dnat_ipv4+0xaa6> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa8f, 0xaa6, x86_l_aa6);
x86_l_a91:
	/* 0xa91: mov    ecx,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_a95:
	/* 0xa95: mov    BYTE PTR [r15+0x2b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_a99:
	/* 0xa99: mov    DWORD PTR [r15+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_a9d:
	/* 0xa9d: mov    rax,QWORD PTR [rip+0x26e8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_aa4:
	/* 0xaa4: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_aa6:
	/* 0xaa6: mov    eax,0xffffff59 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967129ULL);
x86_l_aab:
	/* 0xaab: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_aae:
	/* 0xaae: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_ab0:
	/* 0xab0: neg    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_ab2:
	/* 0xab2: cmovs  ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_S);
x86_l_ab5:
	/* 0xab5: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_ab8:
	/* 0xab8: or     eax,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R14, X86_WIDTH_32, X86_ALU_OR);
x86_l_abb:
	/* 0xabb: mov    QWORD PTR [rbx+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_ac3:
	/* 0xac3: mov    DWORD PTR [rbx+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ac6:
	/* 0xac6: movabs rcx,0x97f680200000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 684380026182828032ULL);
x86_l_ad0:
	/* 0xad0: mov    QWORD PTR [rbx+0x34],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_ad4:
	/* 0xad4: mov    r14d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_ad8:
	/* 0xad8: movabs rcx,0x68097f0200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 446835917312ULL);
x86_l_ae2:
	/* 0xae2: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ae7:
	/* 0xae7: mov    BYTE PTR [rsp+0x10],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_aeb:
	/* 0xaeb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_af0:
	/* 0xaf0: mov    rdi,QWORD PTR [rip+0x26e8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_af7:
	/* 0xaf7: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_afc:
	/* 0xafc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_afe:
	/* 0xafe: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b01:
	/* 0xb01: je     b0c <tail_nodeport_rev_dnat_ipv4+0xb0c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb01, 0xb0c, x86_l_b0c);
x86_l_b03:
	/* 0xb03: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_b06:
	/* 0xb06: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_b0a:
	/* 0xb0a: jmp    b34 <tail_nodeport_rev_dnat_ipv4+0xb34> */
	X86_SIM_X86_JMP(0xb0a, 0xb34, x86_l_b34);
x86_l_b0c:
	/* 0xb0c: mov    QWORD PTR [rsp+0x58],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122049ULL);
x86_l_b15:
	/* 0xb15: mov    QWORD PTR [rsp+0x60],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_b1a:
	/* 0xb1a: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_b1f:
	/* 0xb1f: mov    rdi,QWORD PTR [rip+0x26e8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_b26:
	/* 0xb26: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b2b:
	/* 0xb2b: lea    rdx,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_b30:
	/* 0xb30: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b32:
	/* 0xb32: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b34:
	/* 0xb34: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_b39:
	/* 0xb39: mov    rsi,QWORD PTR [rip+0x26e8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_b40:
	/* 0xb40: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_b43:
	/* 0xb43: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_b48:
	/* 0xb48: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b4a:
	/* 0xb4a: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_b4f:
	/* 0xb4f: add    rsp,0xa8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 168ULL);
x86_l_b56:
	/* 0xb56: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_b57:
	/* 0xb57: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_b59:
	/* 0xb59: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_b5b:
	/* 0xb5b: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_b5d:
	/* 0xb5d: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_b5f:
	/* 0xb5f: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_b60:
	/* 0xb60: jmp    b65 <tail_nodeport_rev_dnat_ipv4+0xb65> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_b65:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
