extern char __config_debug_lb;
extern char __config_enable_conntrack_accounting;
extern char __config_enable_ipv4_fragments;
extern char __config_enable_jiffies;
extern char __config_kernel_hz;
extern char __config_supports_fib_lookup_skip_neigh;
extern char __config_trace_payload_len;
extern char cilium_calls;
extern char cilium_ct4_global;
extern char cilium_ct_any4_global;
extern char cilium_devices;
extern char cilium_ipcache_v2;
extern char cilium_ipv4_frag_datagrams;
extern char cilium_lb4_reverse_nat;
extern char cilium_metrics;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int cilium_bpf_overlay_tail_nodeport_rev_dnat_ipv4_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0xa: sub    rsp,0xb8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 184ULL);
x86_l_11:
	/* 0x11: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_14:
	/* 0x14: mov    rax,QWORD PTR [rip+0x18e0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_1b:
	/* 0x1b: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d:
	/* 0x1d: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_26:
	/* 0x26: mov    DWORD PTR [rsp+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_31:
	/* 0x31: mov    QWORD PTR [rsp+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_3d:
	/* 0x3d: mov    QWORD PTR [rsp+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_49:
	/* 0x49: mov    QWORD PTR [rsp+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_55:
	/* 0x55: mov    QWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_61:
	/* 0x61: mov    QWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_6d:
	/* 0x6d: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_76:
	/* 0x76: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_7f:
	/* 0x7f: mov    BYTE PTR [rsp+0x68],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 446676598786ULL);
x86_l_84:
	/* 0x84: mov    rax,QWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_88:
	/* 0x88: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8b:
	/* 0x8b: mov    ecx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 0ULL);
x86_l_90:
	/* 0x90: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_93:
	/* 0x93: je     9b <tail_nodeport_rev_dnat_ipv4+0x9b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x93, 0x9b, x86_l_9b);
x86_l_95:
	/* 0x95: mov    ecx,DWORD PTR [rax+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_9b:
	/* 0x9b: mov    DWORD PTR [rsp+0x70],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_9f:
	/* 0x9f: mov    WORD PTR [rsp+0x24],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 154618822656ULL);
x86_l_a6:
	/* 0xa6: mov    DWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_ae:
	/* 0xae: mov    ecx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_b1:
	/* 0xb1: sub    ecx,DWORD PTR [rbx+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_b4:
	/* 0xb4: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_b9:
	/* 0xb9: cmp    ecx,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 34ULL);
x86_l_bc:
	/* 0xbc: jb     bfd <tail_nodeport_rev_dnat_ipv4+0xbfd> */
	X86_SIM_X86_JCC(X86_CC_B, 0xbc, 0xbfd, x86_l_bfd);
x86_l_c2:
	/* 0xc2: movabs r8,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_64, 2199023255552ULL);
x86_l_cc:
	/* 0xcc: movabs rbp,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 1099511627776ULL);
x86_l_d6:
	/* 0xd6: mov    rdx,QWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_dd:
	/* 0xdd: movzx  ecx,WORD PTR [rdx+0x12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18ULL);
x86_l_e1:
	/* 0xe1: movzx  eax,BYTE PTR [rdx+0x17] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 23ULL);
x86_l_e5:
	/* 0xe5: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_e8:
	/* 0xe8: shl    rsi,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_ec:
	/* 0xec: or     rsi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_ef:
	/* 0xef: movzx  ecx,WORD PTR [rdx+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 20ULL);
x86_l_f3:
	/* 0xf3: lea    rdi,[rsi+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_f7:
	/* 0xf7: test   ecx,0xff3f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_32, 65343ULL);
x86_l_fd:
	/* 0xfd: cmove  rdi,rsi */
	X86_SIM_L_EXEC_CMOV(X86_RDI, X86_RSI, X86_WIDTH_64, X86_CC_E);
x86_l_101:
	/* 0x101: lea    r13,[rdi+r8*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_105:
	/* 0x105: test   ecx,0xff1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_32, 65311ULL);
x86_l_10b:
	/* 0x10b: cmove  r13,rdi */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RDI, X86_WIDTH_64, X86_CC_E);
x86_l_10f:
	/* 0x10f: mov    esi,DWORD PTR [rdx+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_112:
	/* 0x112: mov    BYTE PTR [rsp+0x24],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_116:
	/* 0x116: mov    ecx,DWORD PTR [rdx+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_119:
	/* 0x119: mov    DWORD PTR [rsp+0x18],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_11d:
	/* 0x11d: mov    edx,DWORD PTR [rdx+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_120:
	/* 0x120: mov    DWORD PTR [rsp+0x1c],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_124:
	/* 0x124: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_127:
	/* 0x127: je     132 <tail_nodeport_rev_dnat_ipv4+0x132> */
	X86_SIM_X86_JCC(X86_CC_E, 0x127, 0x132, x86_l_132);
x86_l_129:
	/* 0x129: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_12c:
	/* 0x12c: jne    bd5 <tail_nodeport_rev_dnat_ipv4+0xbd5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x12c, 0xbd5, x86_l_bd5);
x86_l_132:
	/* 0x132: and    esi,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_135:
	/* 0x135: lea    esi,[rsi*4+0xe] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 14ULL);
x86_l_13c:
	/* 0x13c: lea    r15,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_141:
	/* 0x141: mov    r12,QWORD PTR [rip+0x18e0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&__config_enable_ipv4_fragments)));
x86_l_148:
	/* 0x148: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14d:
	/* 0x14d: mov    QWORD PTR [rsp+0x58],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_152:
	/* 0x152: je     212 <tail_nodeport_rev_dnat_ipv4+0x212> */
	X86_SIM_X86_JCC(X86_CC_E, 0x152, 0x212, x86_l_212);
x86_l_158:
	/* 0x158: mov    DWORD PTR [rsp+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15c:
	/* 0x15c: mov    DWORD PTR [rsp+0xc],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_160:
	/* 0x160: mov    WORD PTR [rsp+0x10],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_166:
	/* 0x166: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_169:
	/* 0x169: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_16d:
	/* 0x16d: mov    BYTE PTR [rsp+0x12],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_171:
	/* 0x171: mov    BYTE PTR [rsp+0x13],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 81604378624ULL);
x86_l_176:
	/* 0x176: movabs rax,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2199023255552ULL);
x86_l_180:
	/* 0x180: test   r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_183:
	/* 0x183: jne    a82 <tail_nodeport_rev_dnat_ipv4+0xa82> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x183, 0xa82, x86_l_a82);
x86_l_189:
	/* 0x189: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_18e:
	/* 0x18e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_191:
	/* 0x191: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_194:
	/* 0x194: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_199:
	/* 0x199: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19b:
	/* 0x19b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_19d:
	/* 0x19d: js     250 <tail_nodeport_rev_dnat_ipv4+0x250> */
	X86_SIM_X86_JCC(X86_CC_S, 0x19d, 0x250, x86_l_250);
x86_l_1a3:
	/* 0x1a3: test   r13,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_RBP, X86_WIDTH_64);
x86_l_1a6:
	/* 0x1a6: je     23b <tail_nodeport_rev_dnat_ipv4+0x23b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a6, 0x23b, x86_l_23b);
x86_l_1ac:
	/* 0x1ac: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1b1:
	/* 0x1b1: mov    rdi,QWORD PTR [rip+0x18e0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv4_frag_datagrams)));
x86_l_1b8:
	/* 0x1b8: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bd:
	/* 0x1bd: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1c0:
	/* 0x1c0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c2:
	/* 0x1c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c4:
	/* 0x1c4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1c6:
	/* 0x1c6: je     23b <tail_nodeport_rev_dnat_ipv4+0x23b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1c6, 0x23b, x86_l_23b);
x86_l_1c8:
	/* 0x1c8: mov    r14d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1cc:
	/* 0x1cc: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1d5:
	/* 0x1d5: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1de:
	/* 0x1de: movabs rax,0x6b0085020a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 459570217482ULL);
x86_l_1e8:
	/* 0x1e8: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1ed:
	/* 0x1ed: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1f2:
	/* 0x1f2: mov    rdi,QWORD PTR [rip+0x18e0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1f9:
	/* 0x1f9: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1fe:
	/* 0x1fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_200:
	/* 0x200: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_203:
	/* 0x203: je     ac3 <tail_nodeport_rev_dnat_ipv4+0xac3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x203, 0xac3, x86_l_ac3);
x86_l_209:
	/* 0x209: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_20c:
	/* 0x20c: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_210:
	/* 0x210: jmp    23b <tail_nodeport_rev_dnat_ipv4+0x23b> */
	X86_SIM_X86_JMP(0x210, 0x23b, x86_l_23b);
x86_l_212:
	/* 0x212: movabs rax,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2199023255552ULL);
x86_l_21c:
	/* 0x21c: test   r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_21f:
	/* 0x21f: jne    aa5 <tail_nodeport_rev_dnat_ipv4+0xaa5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x21f, 0xaa5, x86_l_aa5);
x86_l_225:
	/* 0x225: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_22a:
	/* 0x22a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_22d:
	/* 0x22d: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_230:
	/* 0x230: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_235:
	/* 0x235: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_237:
	/* 0x237: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_239:
	/* 0x239: js     250 <tail_nodeport_rev_dnat_ipv4+0x250> */
	X86_SIM_X86_JCC(X86_CC_S, 0x239, 0x250, x86_l_250);
x86_l_23b:
	/* 0x23b: movzx  r14d,BYTE PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 36ULL);
x86_l_241:
	/* 0x241: cmp    r14b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 6ULL);
x86_l_245:
	/* 0x245: jne    25a <tail_nodeport_rev_dnat_ipv4+0x25a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x245, 0x25a, x86_l_25a);
x86_l_247:
	/* 0x247: mov    r15,QWORD PTR [rip+0x18e0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&cilium_ct4_global)));
x86_l_24e:
	/* 0x24e: jmp    261 <tail_nodeport_rev_dnat_ipv4+0x261> */
	X86_SIM_X86_JMP(0x24e, 0x261, x86_l_261);
x86_l_250:
	/* 0x250: mov    eax,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967161ULL);
x86_l_255:
	/* 0x255: jmp    bfd <tail_nodeport_rev_dnat_ipv4+0xbfd> */
	X86_SIM_X86_JMP(0x255, 0xbfd, x86_l_bfd);
x86_l_25a:
	/* 0x25a: mov    r15,QWORD PTR [rip+0x18e0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&cilium_ct_any4_global)));
x86_l_261:
	/* 0x261: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_266:
	/* 0x266: mov    BYTE PTR [rsp+0x25],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 158913789952ULL);
x86_l_26b:
	/* 0x26b: mov    DWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_273:
	/* 0x273: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_278:
	/* 0x278: je     2f2 <tail_nodeport_rev_dnat_ipv4+0x2f2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x278, 0x2f2, x86_l_2f2);
x86_l_27a:
	/* 0x27a: and    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_27d:
	/* 0x27d: je     2f2 <tail_nodeport_rev_dnat_ipv4+0x2f2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x27d, 0x2f2, x86_l_2f2);
x86_l_27f:
	/* 0x27f: mov    r12d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_283:
	/* 0x283: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_28c:
	/* 0x28c: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_295:
	/* 0x295: movabs rax,0x6c03a50109 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 463917613321ULL);
x86_l_29f:
	/* 0x29f: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a4:
	/* 0x2a4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a9:
	/* 0x2a9: mov    rdi,QWORD PTR [rip+0x18e0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_2b0:
	/* 0x2b0: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2b5:
	/* 0x2b5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b7:
	/* 0x2b7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2ba:
	/* 0x2ba: je     2c5 <tail_nodeport_rev_dnat_ipv4+0x2c5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2ba, 0x2c5, x86_l_2c5);
x86_l_2bc:
	/* 0x2bc: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2bf:
	/* 0x2bf: add    QWORD PTR [rax+0x8],r12 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2c3:
	/* 0x2c3: jmp    2ed <tail_nodeport_rev_dnat_ipv4+0x2ed> */
	X86_SIM_X86_JMP(0x2c3, 0x2ed, x86_l_2ed);
x86_l_2c5:
	/* 0x2c5: mov    QWORD PTR [rsp+0x28],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691841ULL);
x86_l_2ce:
	/* 0x2ce: mov    QWORD PTR [rsp+0x30],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2d3:
	/* 0x2d3: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2d8:
	/* 0x2d8: mov    rdi,QWORD PTR [rip+0x18e0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_2df:
	/* 0x2df: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e4:
	/* 0x2e4: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2e9:
	/* 0x2e9: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2eb:
	/* 0x2eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ed:
	/* 0x2ed: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2f2:
	/* 0x2f2: cmp    r14b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 6ULL);
x86_l_2f6:
	/* 0x2f6: jne    352 <tail_nodeport_rev_dnat_ipv4+0x352> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2f6, 0x352, x86_l_352);
x86_l_2f8:
	/* 0x2f8: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_2fb:
	/* 0x2fb: movabs rdx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 2199023255552ULL);
x86_l_305:
	/* 0x305: and    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_AND);
x86_l_308:
	/* 0x308: jne    352 <tail_nodeport_rev_dnat_ipv4+0x352> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x308, 0x352, x86_l_352);
x86_l_30a:
	/* 0x30a: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_30f:
	/* 0x30f: lea    esi,[rcx+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_312:
	/* 0x312: lea    rdx,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_317:
	/* 0x317: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_31a:
	/* 0x31a: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_31f:
	/* 0x31f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_321:
	/* 0x321: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_323:
	/* 0x323: js     bd5 <tail_nodeport_rev_dnat_ipv4+0xbd5> */
	X86_SIM_X86_JCC(X86_CC_S, 0x323, 0xbd5, x86_l_bd5);
x86_l_329:
	/* 0x329: mov    r12d,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_32e:
	/* 0x32e: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_331:
	/* 0x331: and    eax,0x1200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4608ULL);
x86_l_336:
	/* 0x336: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_338:
	/* 0x338: cmp    eax,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 512ULL);
x86_l_33d:
	/* 0x33d: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_340:
	/* 0x340: test   r12d,0x500 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R12, X86_WIDTH_32, 1280ULL);
x86_l_347:
	/* 0x347: jne    ab9 <tail_nodeport_rev_dnat_ipv4+0xab9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x347, 0xab9, x86_l_ab9);
x86_l_34d:
	/* 0x34d: mov    bpl,al */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_8);
x86_l_350:
	/* 0x350: jmp    359 <tail_nodeport_rev_dnat_ipv4+0x359> */
	X86_SIM_X86_JMP(0x350, 0x359, x86_l_359);
x86_l_352:
	/* 0x352: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_354:
	/* 0x354: mov    r12d,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_359:
	/* 0x359: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_35e:
	/* 0x35e: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_363:
	/* 0x363: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_366:
	/* 0x366: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_368:
	/* 0x368: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_36b:
	/* 0x36b: je     bcc <tail_nodeport_rev_dnat_ipv4+0xbcc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x36b, 0xbcc, x86_l_bcc);
x86_l_371:
	/* 0x371: movzx  ecx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_375:
	/* 0x375: test   cl,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_378:
	/* 0x378: je     bcc <tail_nodeport_rev_dnat_ipv4+0xbcc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x378, 0xbcc, x86_l_bcc);
x86_l_37e:
	/* 0x37e: cmp    WORD PTR [rax+0x26],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 163208757248ULL);
x86_l_383:
	/* 0x383: je     bcc <tail_nodeport_rev_dnat_ipv4+0xbcc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x383, 0xbcc, x86_l_bcc);
x86_l_389:
	/* 0x389: mov    DWORD PTR [rsp+0x4],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_38e:
	/* 0x38e: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_390:
	/* 0x390: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_392:
	/* 0x392: test   dl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_8, 3ULL);
x86_l_395:
	/* 0x395: mov    r8,QWORD PTR [rip+0x18e0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R8, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_39c:
	/* 0x39c: je     4a8 <tail_nodeport_rev_dnat_ipv4+0x4a8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x39c, 0x4a8, x86_l_4a8);
x86_l_3a2:
	/* 0x3a2: mov    rsi,QWORD PTR [rip+0x18e0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_3a9:
	/* 0x3a9: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3ac:
	/* 0x3ac: je     3bf <tail_nodeport_rev_dnat_ipv4+0x3bf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3ac, 0x3bf, x86_l_3bf);
x86_l_3ae:
	/* 0x3ae: mov    rdx,QWORD PTR [rip+0x18e0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_3b5:
	/* 0x3b5: imul   r15d,DWORD PTR [rdx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R15, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_3b9:
	/* 0x3b9: shr    r15d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_3bd:
	/* 0x3bd: jmp    3c5 <tail_nodeport_rev_dnat_ipv4+0x3c5> */
	X86_SIM_X86_JMP(0x3bd, 0x3c5, x86_l_3c5);
x86_l_3bf:
	/* 0x3bf: mov    r15d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 60ULL);
x86_l_3c5:
	/* 0x3c5: mov    r12d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3ca:
	/* 0x3ca: cmp    r14b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 6ULL);
x86_l_3ce:
	/* 0x3ce: jne    407 <tail_nodeport_rev_dnat_ipv4+0x407> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3ce, 0x407, x86_l_407);
x86_l_3d0:
	/* 0x3d0: mov    edx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_32);
x86_l_3d3:
	/* 0x3d3: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_3d5:
	/* 0x3d5: shr    edx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_3d8:
	/* 0x3d8: and    edx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_3db:
	/* 0x3db: or     ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_3dd:
	/* 0x3dd: mov    WORD PTR [rax+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_3e1:
	/* 0x3e1: test   cl,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 16ULL);
x86_l_3e4:
	/* 0x3e4: mov    ecx,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 60ULL);
x86_l_3e9:
	/* 0x3e9: mov    r15d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 21600ULL);
x86_l_3ef:
	/* 0x3ef: cmove  r15d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R15, X86_RCX, X86_WIDTH_32, X86_CC_E);
x86_l_3f3:
	/* 0x3f3: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f6:
	/* 0x3f6: je     407 <tail_nodeport_rev_dnat_ipv4+0x407> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3f6, 0x407, x86_l_407);
x86_l_3f8:
	/* 0x3f8: mov    rcx,QWORD PTR [rip+0x18e0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_3ff:
	/* 0x3ff: imul   r15d,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_403:
	/* 0x403: shr    r15d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_407:
	/* 0x407: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_40f:
	/* 0x40f: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_413:
	/* 0x413: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_416:
	/* 0x416: je     42a <tail_nodeport_rev_dnat_ipv4+0x42a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x416, 0x42a, x86_l_42a);
x86_l_418:
	/* 0x418: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_41d:
	/* 0x41d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_41f:
	/* 0x41f: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_421:
	/* 0x421: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_424:
	/* 0x424: shr    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_428:
	/* 0x428: jmp    44d <tail_nodeport_rev_dnat_ipv4+0x44d> */
	X86_SIM_X86_JMP(0x428, 0x44d, x86_l_44d);
x86_l_42a:
	/* 0x42a: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_42f:
	/* 0x42f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_431:
	/* 0x431: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_433:
	/* 0x433: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_437:
	/* 0x437: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_441:
	/* 0x441: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_444:
	/* 0x444: mulx   rcx,rcx,rcx */
	X86_SIM_L_EXEC_MULX(X86_RCX, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_449:
	/* 0x449: shr    rcx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_44d:
	/* 0x44d: add    r15d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_450:
	/* 0x450: mov    rax,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_458:
	/* 0x458: mov    DWORD PTR [rax+0x20],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_45c:
	/* 0x45c: movzx  edx,BYTE PTR [rax+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_460:
	/* 0x460: mov    esi,DWORD PTR [rax+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_463:
	/* 0x463: and    r12b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_467:
	/* 0x467: mov    rdi,QWORD PTR [rip+0x18e0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_46e:
	/* 0x46e: cmp    BYTE PTR [rdi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_471:
	/* 0x471: je     484 <tail_nodeport_rev_dnat_ipv4+0x484> */
	X86_SIM_X86_JCC(X86_CC_E, 0x471, 0x484, x86_l_484);
x86_l_473:
	/* 0x473: mov    rdi,QWORD PTR [rip+0x18e0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_47a:
	/* 0x47a: mov    edi,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_47c:
	/* 0x47c: lea    edi,[rdi+rdi*4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_47f:
	/* 0x47f: shr    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_482:
	/* 0x482: jmp    489 <tail_nodeport_rev_dnat_ipv4+0x489> */
	X86_SIM_X86_JMP(0x482, 0x489, x86_l_489);
x86_l_484:
	/* 0x484: mov    edi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 5ULL);
x86_l_489:
	/* 0x489: mov    r8,QWORD PTR [rip+0x18e0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R8, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_490:
	/* 0x490: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_492:
	/* 0x492: or     r12b,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_495:
	/* 0x495: cmp    edi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RCX, X86_WIDTH_32);
x86_l_497:
	/* 0x497: jb     49e <tail_nodeport_rev_dnat_ipv4+0x49e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x497, 0x49e, x86_l_49e);
x86_l_499:
	/* 0x499: cmp    dl,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_8);
x86_l_49c:
	/* 0x49c: je     4a8 <tail_nodeport_rev_dnat_ipv4+0x4a8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x49c, 0x4a8, x86_l_4a8);
x86_l_49e:
	/* 0x49e: mov    BYTE PTR [rax+0x2b],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_4a2:
	/* 0x4a2: mov    DWORD PTR [rax+0x34],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_4a5:
	/* 0x4a5: mov    ecx,DWORD PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4a8:
	/* 0x4a8: mov    rcx,QWORD PTR [rip+0x18e0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_4af:
	/* 0x4af: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4b2:
	/* 0x4b2: je     4c1 <tail_nodeport_rev_dnat_ipv4+0x4c1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4b2, 0x4c1, x86_l_4c1);
x86_l_4b4:
	/* 0x4b4: inc QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 16ULL);
x86_l_4b9:
	/* 0x4b9: mov    ecx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_4bc:
	/* 0x4bc: add QWORD PTR [rax+0x18],rcx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_4c1:
	/* 0x4c1: cmp    ebp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_4c4:
	/* 0x4c4: mov    r12d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_4c9:
	/* 0x4c9: je     518 <tail_nodeport_rev_dnat_ipv4+0x518> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4c9, 0x518, x86_l_518);
x86_l_4cb:
	/* 0x4cb: cmp    ebp,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_4ce:
	/* 0x4ce: jne    5f2 <tail_nodeport_rev_dnat_ipv4+0x5f2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4ce, 0x5f2, x86_l_5f2);
x86_l_4d4:
	/* 0x4d4: movzx  ecx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_4d8:
	/* 0x4d8: test   cl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_4db:
	/* 0x4db: je     5f2 <tail_nodeport_rev_dnat_ipv4+0x5f2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4db, 0x5f2, x86_l_5f2);
x86_l_4e1:
	/* 0x4e1: mov    WORD PTR [rax+0x2a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 180388626432ULL);
x86_l_4e7:
	/* 0x4e7: and    ecx,0xffec */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 65516ULL);
x86_l_4ed:
	/* 0x4ed: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_4f0:
	/* 0x4f0: mov    WORD PTR [rax+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_4f4:
	/* 0x4f4: mov    r12,QWORD PTR [rip+0x18e0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_4fb:
	/* 0x4fb: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_500:
	/* 0x500: je     af0 <tail_nodeport_rev_dnat_ipv4+0xaf0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x500, 0xaf0, x86_l_af0);
x86_l_506:
	/* 0x506: mov    rax,QWORD PTR [rip+0x18e0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_50d:
	/* 0x50d: imul   ebp,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_510:
	/* 0x510: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_513:
	/* 0x513: jmp    af5 <tail_nodeport_rev_dnat_ipv4+0xaf5> */
	X86_SIM_X86_JMP(0x513, 0xaf5, x86_l_af5);
x86_l_518:
	/* 0x518: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_51b:
	/* 0x51b: shr    ecx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_51e:
	/* 0x51e: and    ecx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2ULL);
x86_l_521:
	/* 0x521: or     cx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RAX, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 36ULL);
x86_l_525:
	/* 0x525: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_527:
	/* 0x527: or     edx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_OR, 1ULL);
x86_l_52a:
	/* 0x52a: mov    WORD PTR [rax+0x24],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_52e:
	/* 0x52e: mov    edx,DWORD PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_531:
	/* 0x531: test   cl,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_534:
	/* 0x534: je     5f2 <tail_nodeport_rev_dnat_ipv4+0x5f2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x534, 0x5f2, x86_l_5f2);
x86_l_53a:
	/* 0x53a: mov    r14,QWORD PTR [rip+0x18e0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_541:
	/* 0x541: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_545:
	/* 0x545: je     55a <tail_nodeport_rev_dnat_ipv4+0x55a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x545, 0x55a, x86_l_55a);
x86_l_547:
	/* 0x547: mov    rcx,QWORD PTR [rip+0x18e0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_54e:
	/* 0x54e: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_550:
	/* 0x550: add    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_552:
	/* 0x552: lea    ebp,[rcx+rcx*4] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 0ULL);
x86_l_555:
	/* 0x555: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_558:
	/* 0x558: jmp    55f <tail_nodeport_rev_dnat_ipv4+0x55f> */
	X86_SIM_X86_JMP(0x558, 0x55f, x86_l_55f);
x86_l_55a:
	/* 0x55a: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_55f:
	/* 0x55f: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_562:
	/* 0x562: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_566:
	/* 0x566: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_56a:
	/* 0x56a: je     57e <tail_nodeport_rev_dnat_ipv4+0x57e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x56a, 0x57e, x86_l_57e);
x86_l_56c:
	/* 0x56c: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_571:
	/* 0x571: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_573:
	/* 0x573: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_575:
	/* 0x575: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_578:
	/* 0x578: shr    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_57c:
	/* 0x57c: jmp    5a1 <tail_nodeport_rev_dnat_ipv4+0x5a1> */
	X86_SIM_X86_JMP(0x57c, 0x5a1, x86_l_5a1);
x86_l_57e:
	/* 0x57e: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_583:
	/* 0x583: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_585:
	/* 0x585: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_587:
	/* 0x587: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_58b:
	/* 0x58b: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_595:
	/* 0x595: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_598:
	/* 0x598: mulx   rcx,rcx,rcx */
	X86_SIM_L_EXEC_MULX(X86_RCX, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_59d:
	/* 0x59d: shr    rcx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_5a1:
	/* 0x5a1: add    ebp,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_5a3:
	/* 0x5a3: mov    rax,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_5a6:
	/* 0x5a6: mov    DWORD PTR [r15+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5aa:
	/* 0x5aa: movzx  edx,BYTE PTR [r15+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_5af:
	/* 0x5af: mov    esi,DWORD PTR [r15+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_5b3:
	/* 0x5b3: and    r12b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_5b7:
	/* 0x5b7: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5bb:
	/* 0x5bb: je     5ce <tail_nodeport_rev_dnat_ipv4+0x5ce> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5bb, 0x5ce, x86_l_5ce);
x86_l_5bd:
	/* 0x5bd: mov    rdi,QWORD PTR [rip+0x18e0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_5c4:
	/* 0x5c4: mov    edi,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5c6:
	/* 0x5c6: lea    edi,[rdi+rdi*4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_5c9:
	/* 0x5c9: shr    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_5cc:
	/* 0x5cc: jmp    5d3 <tail_nodeport_rev_dnat_ipv4+0x5d3> */
	X86_SIM_X86_JMP(0x5cc, 0x5d3, x86_l_5d3);
x86_l_5ce:
	/* 0x5ce: mov    edi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 5ULL);
x86_l_5d3:
	/* 0x5d3: mov    r8,QWORD PTR [rip+0x18e0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R8, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_5da:
	/* 0x5da: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_5dc:
	/* 0x5dc: or     r12b,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_5df:
	/* 0x5df: cmp    edi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RCX, X86_WIDTH_32);
x86_l_5e1:
	/* 0x5e1: jb     5e8 <tail_nodeport_rev_dnat_ipv4+0x5e8> */
	X86_SIM_X86_JCC(X86_CC_B, 0x5e1, 0x5e8, x86_l_5e8);
x86_l_5e3:
	/* 0x5e3: cmp    dl,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_8);
x86_l_5e6:
	/* 0x5e6: je     5f2 <tail_nodeport_rev_dnat_ipv4+0x5f2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5e6, 0x5f2, x86_l_5f2);
x86_l_5e8:
	/* 0x5e8: mov    BYTE PTR [rax+0x2b],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_5ec:
	/* 0x5ec: mov    DWORD PTR [rax+0x34],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_5ef:
	/* 0x5ef: mov    ecx,DWORD PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5f2:
	/* 0x5f2: test   BYTE PTR [rsp+0x25],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 158913789954ULL);
x86_l_5f7:
	/* 0x5f7: jne    bd5 <tail_nodeport_rev_dnat_ipv4+0xbd5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x5f7, 0xbd5, x86_l_bd5);
x86_l_5fd:
	/* 0x5fd: movzx  eax,WORD PTR [rax+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_601:
	/* 0x601: mov    WORD PTR [rsp+0x28],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_606:
	/* 0x606: mov    r14,QWORD PTR [rip+0x18e0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_60d:
	/* 0x60d: movzx  eax,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_611:
	/* 0x611: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_616:
	/* 0x616: mov    rdi,QWORD PTR [rip+0x18e0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_reverse_nat)));
x86_l_61d:
	/* 0x61d: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_622:
	/* 0x622: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_624:
	/* 0x624: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_627:
	/* 0x627: je     7c8 <tail_nodeport_rev_dnat_ipv4+0x7c8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x627, 0x7c8, x86_l_7c8);
x86_l_62d:
	/* 0x62d: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_630:
	/* 0x630: mov    r15d,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_635:
	/* 0x635: movzx  eax,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_639:
	/* 0x639: mov    eax,DWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_63d:
	/* 0x63d: mov    DWORD PTR [rsp+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_641:
	/* 0x641: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_646:
	/* 0x646: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_649:
	/* 0x649: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_64c:
	/* 0x64c: mov    esi,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 26ULL);
x86_l_651:
	/* 0x651: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_654:
	/* 0x654: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_659:
	/* 0x659: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_65c:
	/* 0x65c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_65e:
	/* 0x65e: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_660:
	/* 0x660: mov    eax,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967155ULL);
x86_l_665:
	/* 0x665: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_667:
	/* 0x667: js     bfd <tail_nodeport_rev_dnat_ipv4+0xbfd> */
	X86_SIM_X86_JCC(X86_CC_S, 0x667, 0xbfd, x86_l_bfd);
x86_l_66d:
	/* 0x66d: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_670:
	/* 0x670: je     bfd <tail_nodeport_rev_dnat_ipv4+0xbfd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x670, 0xbfd, x86_l_bfd);
x86_l_676:
	/* 0x676: not    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_679:
	/* 0x679: add    r15d,DWORD PTR [r12] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_R12, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_67d:
	/* 0x67d: adc    r15d,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_681:
	/* 0x681: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_684:
	/* 0x684: mov    eax,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_689:
	/* 0x689: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_68c:
	/* 0x68c: mov    esi,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 24ULL);
x86_l_691:
	/* 0x691: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_693:
	/* 0x693: mov    ecx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_32);
x86_l_696:
	/* 0x696: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_699:
	/* 0x699: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_69b:
	/* 0x69b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_69d:
	/* 0x69d: js     902 <tail_nodeport_rev_dnat_ipv4+0x902> */
	X86_SIM_X86_JCC(X86_CC_S, 0x69d, 0x902, x86_l_902);
x86_l_6a3:
	/* 0x6a3: movabs rax,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2199023255552ULL);
x86_l_6ad:
	/* 0x6ad: test   r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_6b0:
	/* 0x6b0: jne    7c8 <tail_nodeport_rev_dnat_ipv4+0x7c8> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x6b0, 0x7c8, x86_l_7c8);
x86_l_6b6:
	/* 0x6b6: movzx  ecx,BYTE PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 36ULL);
x86_l_6bb:
	/* 0x6bb: cmp    ecx,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 58ULL);
x86_l_6be:
	/* 0x6be: je     6e2 <tail_nodeport_rev_dnat_ipv4+0x6e2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6be, 0x6e2, x86_l_6e2);
x86_l_6c0:
	/* 0x6c0: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_6c3:
	/* 0x6c3: je     6d3 <tail_nodeport_rev_dnat_ipv4+0x6d3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6c3, 0x6d3, x86_l_6d3);
x86_l_6c5:
	/* 0x6c5: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_6c8:
	/* 0x6c8: jne    6eb <tail_nodeport_rev_dnat_ipv4+0x6eb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x6c8, 0x6eb, x86_l_6eb);
x86_l_6ca:
	/* 0x6ca: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6cc:
	/* 0x6cc: mov    ebp,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 16ULL);
x86_l_6d1:
	/* 0x6d1: jmp    6f0 <tail_nodeport_rev_dnat_ipv4+0x6f0> */
	X86_SIM_X86_JMP(0x6d1, 0x6f0, x86_l_6f0);
x86_l_6d3:
	/* 0x6d3: mov    r13d,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 32ULL);
x86_l_6d9:
	/* 0x6d9: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_6de:
	/* 0x6de: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6e0:
	/* 0x6e0: jmp    6f3 <tail_nodeport_rev_dnat_ipv4+0x6f3> */
	X86_SIM_X86_JMP(0x6e0, 0x6f3, x86_l_6f3);
x86_l_6e2:
	/* 0x6e2: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6e4:
	/* 0x6e4: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_6e9:
	/* 0x6e9: jmp    6f0 <tail_nodeport_rev_dnat_ipv4+0x6f0> */
	X86_SIM_X86_JMP(0x6e9, 0x6f0, x86_l_6f0);
x86_l_6eb:
	/* 0x6eb: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6ed:
	/* 0x6ed: mov    sil,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_8, 1ULL);
x86_l_6f0:
	/* 0x6f0: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6f3:
	/* 0x6f3: movzx  edx,WORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_6f9:
	/* 0x6f9: test   dx,dx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_16);
x86_l_6fc:
	/* 0x6fc: je     79c <tail_nodeport_rev_dnat_ipv4+0x79c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6fc, 0x79c, x86_l_79c);
x86_l_702:
	/* 0x702: movzx  r12d,WORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 32ULL);
x86_l_708:
	/* 0x708: mov    eax,0xffffff72 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967154ULL);
x86_l_70d:
	/* 0x70d: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_710:
	/* 0x710: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_713:
	/* 0x713: jg     728 <tail_nodeport_rev_dnat_ipv4+0x728> */
	X86_SIM_X86_JCC(X86_CC_G, 0x713, 0x728, x86_l_728);
x86_l_715:
	/* 0x715: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_718:
	/* 0x718: je     79c <tail_nodeport_rev_dnat_ipv4+0x79c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x718, 0x79c, x86_l_79c);
x86_l_71e:
	/* 0x71e: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_721:
	/* 0x721: je     736 <tail_nodeport_rev_dnat_ipv4+0x736> */
	X86_SIM_X86_JCC(X86_CC_E, 0x721, 0x736, x86_l_736);
x86_l_723:
	/* 0x723: jmp    bfd <tail_nodeport_rev_dnat_ipv4+0xbfd> */
	X86_SIM_X86_JMP(0x723, 0xbfd, x86_l_bfd);
x86_l_728:
	/* 0x728: cmp    ecx,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 58ULL);
x86_l_72b:
	/* 0x72b: je     79c <tail_nodeport_rev_dnat_ipv4+0x79c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x72b, 0x79c, x86_l_79c);
x86_l_72d:
	/* 0x72d: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_730:
	/* 0x730: jne    bfd <tail_nodeport_rev_dnat_ipv4+0xbfd> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x730, 0xbfd, x86_l_bfd);
x86_l_736:
	/* 0x736: cmp    dx,r12w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_16);
x86_l_73a:
	/* 0x73a: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_73f:
	/* 0x73f: je     79c <tail_nodeport_rev_dnat_ipv4+0x79c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x73f, 0x79c, x86_l_79c);
x86_l_741:
	/* 0x741: mov    DWORD PTR [rsp+0x4],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_745:
	/* 0x745: mov    WORD PTR [rsp+0x28],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_74a:
	/* 0x74a: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_74f:
	/* 0x74f: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_754:
	/* 0x754: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_757:
	/* 0x757: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_75a:
	/* 0x75a: mov    rsi,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RCX, X86_WIDTH_64);
x86_l_75d:
	/* 0x75d: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_762:
	/* 0x762: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_765:
	/* 0x765: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_767:
	/* 0x767: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_769:
	/* 0x769: js     a6f <tail_nodeport_rev_dnat_ipv4+0xa6f> */
	X86_SIM_X86_JCC(X86_CC_S, 0x769, 0xa6f, x86_l_a6f);
x86_l_76f:
	/* 0x76f: movzx  ecx,WORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 40ULL);
x86_l_774:
	/* 0x774: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_779:
	/* 0x779: lea    esi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_77c:
	/* 0x77c: mov    r8d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R13, X86_WIDTH_32);
x86_l_77f:
	/* 0x77f: or     r8d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_783:
	/* 0x783: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_788:
	/* 0x788: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_78b:
	/* 0x78b: mov    edx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_32);
x86_l_78e:
	/* 0x78e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_790:
	/* 0x790: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_792:
	/* 0x792: js     9a0 <tail_nodeport_rev_dnat_ipv4+0x9a0> */
	X86_SIM_X86_JCC(X86_CC_S, 0x792, 0x9a0, x86_l_9a0);
x86_l_798:
	/* 0x798: mov    esi,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_79c:
	/* 0x79c: test   sil,sil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_8);
x86_l_79f:
	/* 0x79f: jne    7c8 <tail_nodeport_rev_dnat_ipv4+0x7c8> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x79f, 0x7c8, x86_l_7c8);
x86_l_7a1:
	/* 0x7a1: add    ebp,DWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 88ULL);
x86_l_7a5:
	/* 0x7a5: or     r13d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_OR, 16ULL);
x86_l_7a9:
	/* 0x7a9: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7ac:
	/* 0x7ac: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_7b1:
	/* 0x7b1: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_7b4:
	/* 0x7b4: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_7b6:
	/* 0x7b6: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7b8:
	/* 0x7b8: mov    ecx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_32);
x86_l_7bb:
	/* 0x7bb: mov    r8d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R13, X86_WIDTH_32);
x86_l_7be:
	/* 0x7be: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7c0:
	/* 0x7c0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_7c2:
	/* 0x7c2: js     9a0 <tail_nodeport_rev_dnat_ipv4+0x9a0> */
	X86_SIM_X86_JCC(X86_CC_S, 0x7c2, 0x9a0, x86_l_9a0);
x86_l_7c8:
	/* 0x7c8: mov    ecx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_7cb:
	/* 0x7cb: sub    ecx,DWORD PTR [rbx+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_7ce:
	/* 0x7ce: mov    r14d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 0ULL);
x86_l_7d4:
	/* 0x7d4: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_7d9:
	/* 0x7d9: cmp    ecx,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 34ULL);
x86_l_7dc:
	/* 0x7dc: jb     bfd <tail_nodeport_rev_dnat_ipv4+0xbfd> */
	X86_SIM_X86_JCC(X86_CC_B, 0x7dc, 0xbfd, x86_l_bfd);
x86_l_7e2:
	/* 0x7e2: mov    r12,QWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_7e9:
	/* 0x7e9: mov    eax,0xfffff0ff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294963455ULL);
x86_l_7ee:
	/* 0x7ee: and    eax,DWORD PTR [rbx+0xa8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 168ULL);
x86_l_7f4:
	/* 0x7f4: or     eax,0x300 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 768ULL);
x86_l_7f9:
	/* 0x7f9: mov    DWORD PTR [rbx+0xa8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_7ff:
	/* 0x7ff: mov    eax,DWORD PTR [r12+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_804:
	/* 0x804: mov    QWORD PTR [rsp+0x2e],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 197568495616ULL);
x86_l_80d:
	/* 0x80d: mov    WORD PTR [rsp+0x3e],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 266287972352ULL);
x86_l_814:
	/* 0x814: mov    QWORD PTR [rsp+0x36],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 231928233984ULL);
x86_l_81d:
	/* 0x81d: mov    DWORD PTR [rsp+0x28],0x40 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691904ULL);
x86_l_825:
	/* 0x825: mov    BYTE PTR [rsp+0x2f],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 201863462913ULL);
x86_l_82a:
	/* 0x82a: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_82e:
	/* 0x82e: mov    WORD PTR [rsp+0x2c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 188978561024ULL);
x86_l_835:
	/* 0x835: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_83a:
	/* 0x83a: mov    rdi,QWORD PTR [rip+0x18dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipcache_v2)));
x86_l_841:
	/* 0x841: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_846:
	/* 0x846: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_848:
	/* 0x848: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_84b:
	/* 0x84b: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_850:
	/* 0x850: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_853:
	/* 0x853: je     872 <tail_nodeport_rev_dnat_ipv4+0x872> */
	X86_SIM_X86_JCC(X86_CC_E, 0x853, 0x872, x86_l_872);
x86_l_855:
	/* 0x855: movzx  ecx,BYTE PTR [rax+0x17] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 23ULL);
x86_l_859:
	/* 0x859: and    cl,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 3ULL);
x86_l_85c:
	/* 0x85c: mov    r15d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 0ULL);
x86_l_862:
	/* 0x862: cmp    cl,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_865:
	/* 0x865: jne    875 <tail_nodeport_rev_dnat_ipv4+0x875> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x865, 0x875, x86_l_875);
x86_l_867:
	/* 0x867: mov    r15d,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_86b:
	/* 0x86b: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_870:
	/* 0x870: jmp    875 <tail_nodeport_rev_dnat_ipv4+0x875> */
	X86_SIM_X86_JMP(0x870, 0x875, x86_l_875);
x86_l_872:
	/* 0x872: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_875:
	/* 0x875: mov    eax,DWORD PTR [r12+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_87a:
	/* 0x87a: mov    DWORD PTR [rsp+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_87e:
	/* 0x87e: mov    eax,DWORD PTR [r12+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_883:
	/* 0x883: mov    DWORD PTR [rsp+0x88],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_88a:
	/* 0x88a: movzx  edx,BYTE PTR [r12+0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 22ULL);
x86_l_890:
	/* 0x890: mov    eax,0xffffff3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967100ULL);
x86_l_895:
	/* 0x895: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_898:
	/* 0x898: jb     bfd <tail_nodeport_rev_dnat_ipv4+0xbfd> */
	X86_SIM_X86_JCC(X86_CC_B, 0x898, 0xbfd, x86_l_bfd);
x86_l_89e:
	/* 0x89e: lea    eax,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_8a1:
	/* 0x8a1: mov    BYTE PTR [r12+0x16],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_8a6:
	/* 0x8a6: movzx  ecx,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_8a9:
	/* 0x8a9: mov    eax,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_8ae:
	/* 0x8ae: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_8b1:
	/* 0x8b1: mov    esi,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 24ULL);
x86_l_8b6:
	/* 0x8b6: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_8bc:
	/* 0x8bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8be:
	/* 0x8be: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_8c0:
	/* 0x8c0: js     902 <tail_nodeport_rev_dnat_ipv4+0x902> */
	X86_SIM_X86_JCC(X86_CC_S, 0x8c0, 0x902, x86_l_902);
x86_l_8c2:
	/* 0x8c2: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_8c5:
	/* 0x8c5: je     90c <tail_nodeport_rev_dnat_ipv4+0x90c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8c5, 0x90c, x86_l_90c);
x86_l_8c7:
	/* 0x8c7: mov    r14d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_8cb:
	/* 0x8cb: movabs rax,0x6f00220200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 476743598592ULL);
x86_l_8d5:
	/* 0x8d5: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8da:
	/* 0x8da: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_8df:
	/* 0x8df: mov    rdi,QWORD PTR [rip+0x18dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_8e6:
	/* 0x8e6: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8eb:
	/* 0x8eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8ed:
	/* 0x8ed: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8f0:
	/* 0x8f0: je     9aa <tail_nodeport_rev_dnat_ipv4+0x9aa> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8f0, 0x9aa, x86_l_9aa);
x86_l_8f6:
	/* 0x8f6: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_8f9:
	/* 0x8f9: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_8fd:
	/* 0x8fd: jmp    9d2 <tail_nodeport_rev_dnat_ipv4+0x9d2> */
	X86_SIM_X86_JMP(0x8fd, 0x9d2, x86_l_9d2);
x86_l_902:
	/* 0x902: mov    eax,0xffffff67 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967143ULL);
x86_l_907:
	/* 0x907: jmp    bfd <tail_nodeport_rev_dnat_ipv4+0xbfd> */
	X86_SIM_X86_JMP(0x907, 0xbfd, x86_l_bfd);
x86_l_90c:
	/* 0x90c: mov    eax,0x45 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 69ULL);
x86_l_911:
	/* 0x911: mov    rcx,QWORD PTR [rip+0x18dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_supports_fib_lookup_skip_neigh)));
x86_l_918:
	/* 0x918: movzx  ecx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_91b:
	/* 0x91b: shl    ecx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 2ULL);
x86_l_91e:
	/* 0x91e: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_923:
	/* 0x923: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_926:
	/* 0x926: mov    edx,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 64ULL);
x86_l_92b:
	/* 0x92b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_92d:
	/* 0x92d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_92f:
	/* 0x92f: je     93a <tail_nodeport_rev_dnat_ipv4+0x93a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x92f, 0x93a, x86_l_93a);
x86_l_931:
	/* 0x931: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_934:
	/* 0x934: jne    a5e <tail_nodeport_rev_dnat_ipv4+0xa5e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x934, 0xa5e, x86_l_a5e);
x86_l_93a:
	/* 0x93a: mov    ebp,DWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_93e:
	/* 0x93e: mov    DWORD PTR [rsp+0x28],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_942:
	/* 0x942: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_947:
	/* 0x947: mov    rdi,QWORD PTR [rip+0x18dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_devices)));
x86_l_94e:
	/* 0x94e: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_953:
	/* 0x953: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_955:
	/* 0x955: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_958:
	/* 0x958: je     964 <tail_nodeport_rev_dnat_ipv4+0x964> */
	X86_SIM_X86_JCC(X86_CC_E, 0x958, 0x964, x86_l_964);
x86_l_95a:
	/* 0x95a: test   BYTE PTR [rax+0x8],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_95e:
	/* 0x95e: jne    a79 <tail_nodeport_rev_dnat_ipv4+0xa79> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x95e, 0xa79, x86_l_a79);
x86_l_964:
	/* 0x964: lea    rax,[rsp+0x88] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_96c:
	/* 0x96c: movzx  ecx,BYTE PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 104ULL);
x86_l_971:
	/* 0x971: mov    DWORD PTR [rsp+0x28],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_975:
	/* 0x975: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_978:
	/* 0x978: mov    rax,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_97c:
	/* 0x97c: mov    QWORD PTR [rsp+0x2c],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_981:
	/* 0x981: mov    QWORD PTR [rsp+0x34],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_986:
	/* 0x986: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_98b:
	/* 0x98b: mov    eax,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 152ULL);
x86_l_990:
	/* 0x990: mov    edi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_32);
x86_l_992:
	/* 0x992: mov    edx,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 20ULL);
x86_l_997:
	/* 0x997: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_999:
	/* 0x999: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_99b:
	/* 0x99b: jmp    a3d <tail_nodeport_rev_dnat_ipv4+0xa3d> */
	X86_SIM_X86_JMP(0x99b, 0xa3d, x86_l_a3d);
x86_l_9a0:
	/* 0x9a0: mov    eax,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967142ULL);
x86_l_9a5:
	/* 0x9a5: jmp    bfd <tail_nodeport_rev_dnat_ipv4+0xbfd> */
	X86_SIM_X86_JMP(0x9a5, 0xbfd, x86_l_bfd);
x86_l_9aa:
	/* 0x9aa: mov    QWORD PTR [rsp+0x28],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691841ULL);
x86_l_9b3:
	/* 0x9b3: mov    QWORD PTR [rsp+0x30],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9b8:
	/* 0x9b8: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_9bd:
	/* 0x9bd: mov    rdi,QWORD PTR [rip+0x18dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_9c4:
	/* 0x9c4: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9c9:
	/* 0x9c9: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_9ce:
	/* 0x9ce: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9d0:
	/* 0x9d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9d2:
	/* 0x9d2: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_9db:
	/* 0x9db: mov    DWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_9e3:
	/* 0x9e3: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_9ec:
	/* 0x9ec: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_9f5:
	/* 0x9f5: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_9fe:
	/* 0x9fe: mov    DWORD PTR [rsp+0x28],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a02:
	/* 0xa02: movbe  DWORD PTR [rsp+0x2c],r15d */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 44ULL);
x86_l_a09:
	/* 0xa09: mov    BYTE PTR [rsp+0x3d],0x40 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 261993005120ULL);
x86_l_a0e:
	/* 0xa0e: mov    eax,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 21ULL);
x86_l_a13:
	/* 0xa13: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a18:
	/* 0xa18: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_a1b:
	/* 0xa1b: mov    edx,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 28ULL);
x86_l_a20:
	/* 0xa20: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_a25:
	/* 0xa25: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a27:
	/* 0xa27: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a29:
	/* 0xa29: js     cb4 <tail_nodeport_rev_dnat_ipv4+0xcb4> */
	X86_SIM_X86_JCC(X86_CC_S, 0xa29, 0xcb4, x86_l_cb4);
x86_l_a2f:
	/* 0xa2f: mov    eax,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 23ULL);
x86_l_a34:
	/* 0xa34: mov    edi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 1ULL);
x86_l_a39:
	/* 0xa39: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a3b:
	/* 0xa3b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a3d:
	/* 0xa3d: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a40:
	/* 0xa40: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a42:
	/* 0xa42: js     bfd <tail_nodeport_rev_dnat_ipv4+0xbfd> */
	X86_SIM_X86_JCC(X86_CC_S, 0xa42, 0xbfd, x86_l_bfd);
x86_l_a48:
	/* 0xa48: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_a4b:
	/* 0xa4b: je     bfd <tail_nodeport_rev_dnat_ipv4+0xbfd> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa4b, 0xbfd, x86_l_bfd);
x86_l_a51:
	/* 0xa51: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a53:
	/* 0xa53: jne    c9e <tail_nodeport_rev_dnat_ipv4+0xc9e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa53, 0xc9e, x86_l_c9e);
x86_l_a59:
	/* 0xa59: jmp    bd5 <tail_nodeport_rev_dnat_ipv4+0xbd5> */
	X86_SIM_X86_JMP(0xa59, 0xbd5, x86_l_bd5);
x86_l_a5e:
	/* 0xa5e: shl    eax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_a61:
	/* 0xa61: movzx  r14d,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_a65:
	/* 0xa65: mov    eax,0xffffff57 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967127ULL);
x86_l_a6a:
	/* 0xa6a: jmp    bfd <tail_nodeport_rev_dnat_ipv4+0xbfd> */
	X86_SIM_X86_JMP(0xa6a, 0xbfd, x86_l_bfd);
x86_l_a6f:
	/* 0xa6f: mov    eax,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967155ULL);
x86_l_a74:
	/* 0xa74: jmp    bfd <tail_nodeport_rev_dnat_ipv4+0xbfd> */
	X86_SIM_X86_JMP(0xa74, 0xbfd, x86_l_bfd);
x86_l_a79:
	/* 0xa79: mov    eax,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 23ULL);
x86_l_a7e:
	/* 0xa7e: mov    edi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_32);
x86_l_a80:
	/* 0xa80: jmp    a39 <tail_nodeport_rev_dnat_ipv4+0xa39> */
	X86_SIM_X86_JMP(0xa80, 0xa39, x86_l_a39);
x86_l_a82:
	/* 0xa82: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a87:
	/* 0xa87: mov    rdi,QWORD PTR [rip+0x18dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv4_frag_datagrams)));
x86_l_a8e:
	/* 0xa8e: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a93:
	/* 0xa93: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a95:
	/* 0xa95: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a98:
	/* 0xa98: je     aaf <tail_nodeport_rev_dnat_ipv4+0xaaf> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa98, 0xaaf, x86_l_aaf);
x86_l_a9a:
	/* 0xa9a: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a9c:
	/* 0xa9c: mov    DWORD PTR [rsp+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_aa0:
	/* 0xaa0: jmp    23b <tail_nodeport_rev_dnat_ipv4+0x23b> */
	X86_SIM_X86_JMP(0xaa0, 0x23b, x86_l_23b);
x86_l_aa5:
	/* 0xaa5: mov    eax,0xffffff63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967139ULL);
x86_l_aaa:
	/* 0xaaa: jmp    bfd <tail_nodeport_rev_dnat_ipv4+0xbfd> */
	X86_SIM_X86_JMP(0xaaa, 0xbfd, x86_l_bfd);
x86_l_aaf:
	/* 0xaaf: mov    eax,0xffffff51 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967121ULL);
x86_l_ab4:
	/* 0xab4: jmp    bfd <tail_nodeport_rev_dnat_ipv4+0xbfd> */
	X86_SIM_X86_JMP(0xab4, 0xbfd, x86_l_bfd);
x86_l_ab9:
	/* 0xab9: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_abe:
	/* 0xabe: jmp    359 <tail_nodeport_rev_dnat_ipv4+0x359> */
	X86_SIM_X86_JMP(0xabe, 0x359, x86_l_359);
x86_l_ac3:
	/* 0xac3: mov    QWORD PTR [rsp+0x28],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691841ULL);
x86_l_acc:
	/* 0xacc: mov    QWORD PTR [rsp+0x30],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ad1:
	/* 0xad1: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_ad6:
	/* 0xad6: mov    rdi,QWORD PTR [rip+0x18dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_add:
	/* 0xadd: lea    rsi,[rsp+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_ae2:
	/* 0xae2: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_ae7:
	/* 0xae7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ae9:
	/* 0xae9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aeb:
	/* 0xaeb: jmp    23b <tail_nodeport_rev_dnat_ipv4+0x23b> */
	X86_SIM_X86_JMP(0xaeb, 0x23b, x86_l_23b);
x86_l_af0:
	/* 0xaf0: mov    ebp,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_af5:
	/* 0xaf5: cmp    r14b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 6ULL);
x86_l_af9:
	/* 0xaf9: jne    b31 <tail_nodeport_rev_dnat_ipv4+0xb31> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xaf9, 0xb31, x86_l_b31);
x86_l_afb:
	/* 0xafb: mov    eax,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_aff:
	/* 0xaff: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_b01:
	/* 0xb01: shr    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_b04:
	/* 0xb04: and    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_b07:
	/* 0xb07: or     ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_OR);
x86_l_b09:
	/* 0xb09: mov    WORD PTR [r15+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_b0e:
	/* 0xb0e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b10:
	/* 0xb10: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_b15:
	/* 0xb15: mov    ebp,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 21600ULL);
x86_l_b1a:
	/* 0xb1a: cmove  ebp,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_b1d:
	/* 0xb1d: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b22:
	/* 0xb22: je     b31 <tail_nodeport_rev_dnat_ipv4+0xb31> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb22, 0xb31, x86_l_b31);
x86_l_b24:
	/* 0xb24: mov    rax,QWORD PTR [rip+0x18dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_b2b:
	/* 0xb2b: imul   ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_b2e:
	/* 0xb2e: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_b31:
	/* 0xb31: shr    DWORD PTR [rsp+0x4],0x8 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_32, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_SHR)), 17179869192ULL);
x86_l_b36:
	/* 0xb36: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b3b:
	/* 0xb3b: je     b4c <tail_nodeport_rev_dnat_ipv4+0xb4c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb3b, 0xb4c, x86_l_b4c);
x86_l_b3d:
	/* 0xb3d: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_b42:
	/* 0xb42: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b44:
	/* 0xb44: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_b46:
	/* 0xb46: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_b4a:
	/* 0xb4a: jmp    b6f <tail_nodeport_rev_dnat_ipv4+0xb6f> */
	X86_SIM_X86_JMP(0xb4a, 0xb6f, x86_l_b6f);
x86_l_b4c:
	/* 0xb4c: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_b51:
	/* 0xb51: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b53:
	/* 0xb53: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_b55:
	/* 0xb55: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_b59:
	/* 0xb59: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_b63:
	/* 0xb63: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_b66:
	/* 0xb66: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_b6b:
	/* 0xb6b: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_b6f:
	/* 0xb6f: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_b71:
	/* 0xb71: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_b74:
	/* 0xb74: mov    DWORD PTR [r15+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b78:
	/* 0xb78: movzx  ecx,BYTE PTR [r15+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_b7d:
	/* 0xb7d: mov    edx,DWORD PTR [r15+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_b81:
	/* 0xb81: mov    esi,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_b85:
	/* 0xb85: and    sil,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_b89:
	/* 0xb89: mov    DWORD PTR [rsp+0x4],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_b8d:
	/* 0xb8d: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b92:
	/* 0xb92: je     ba5 <tail_nodeport_rev_dnat_ipv4+0xba5> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb92, 0xba5, x86_l_ba5);
x86_l_b94:
	/* 0xb94: mov    rsi,QWORD PTR [rip+0x18dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_b9b:
	/* 0xb9b: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b9d:
	/* 0xb9d: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_ba0:
	/* 0xba0: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_ba3:
	/* 0xba3: jmp    baa <tail_nodeport_rev_dnat_ipv4+0xbaa> */
	X86_SIM_X86_JMP(0xba3, 0xbaa, x86_l_baa);
x86_l_ba5:
	/* 0xba5: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_baa:
	/* 0xbaa: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_bac:
	/* 0xbac: mov    edx,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_bb0:
	/* 0xbb0: or     dl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_bb2:
	/* 0xbb2: mov    DWORD PTR [rsp+0x4],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_bb6:
	/* 0xbb6: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_bb8:
	/* 0xbb8: jb     bc0 <tail_nodeport_rev_dnat_ipv4+0xbc0> */
	X86_SIM_X86_JCC(X86_CC_B, 0xbb8, 0xbc0, x86_l_bc0);
x86_l_bba:
	/* 0xbba: cmp    cl,BYTE PTR [rsp+0x4] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 4ULL);
x86_l_bbe:
	/* 0xbbe: je     bd5 <tail_nodeport_rev_dnat_ipv4+0xbd5> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbbe, 0xbd5, x86_l_bd5);
x86_l_bc0:
	/* 0xbc0: mov    ecx,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_bc4:
	/* 0xbc4: mov    BYTE PTR [r15+0x2b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_bc8:
	/* 0xbc8: mov    DWORD PTR [r15+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_bcc:
	/* 0xbcc: mov    rax,QWORD PTR [rip+0x18dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_bd3:
	/* 0xbd3: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bd5:
	/* 0xbd5: or     BYTE PTR [rbx+0x86],0x4 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RBX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 575525617668ULL);
x86_l_bdc:
	/* 0xbdc: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_be1:
	/* 0xbe1: mov    rsi,QWORD PTR [rip+0x18dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_be8:
	/* 0xbe8: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_beb:
	/* 0xbeb: mov    edx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_bf0:
	/* 0xbf0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bf2:
	/* 0xbf2: mov    eax,0xffffff74 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967156ULL);
x86_l_bf7:
	/* 0xbf7: mov    r14d,0x700 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 1792ULL);
x86_l_bfd:
	/* 0xbfd: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_bff:
	/* 0xbff: neg    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_c01:
	/* 0xc01: cmovs  ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_S);
x86_l_c04:
	/* 0xc04: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_c07:
	/* 0xc07: or     eax,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R14, X86_WIDTH_32, X86_ALU_OR);
x86_l_c0a:
	/* 0xc0a: mov    QWORD PTR [rbx+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_c12:
	/* 0xc12: mov    DWORD PTR [rbx+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c15:
	/* 0xc15: movabs rcx,0x97f680200000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 684380026182828032ULL);
x86_l_c1f:
	/* 0xc1f: mov    QWORD PTR [rbx+0x34],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_c23:
	/* 0xc23: mov    r14d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_c27:
	/* 0xc27: movabs rcx,0x68097f0200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 446835917312ULL);
x86_l_c31:
	/* 0xc31: mov    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c36:
	/* 0xc36: mov    BYTE PTR [rsp+0x28],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c3a:
	/* 0xc3a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c3f:
	/* 0xc3f: mov    rdi,QWORD PTR [rip+0x18dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_c46:
	/* 0xc46: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c4b:
	/* 0xc4b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c4d:
	/* 0xc4d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c50:
	/* 0xc50: je     c5b <tail_nodeport_rev_dnat_ipv4+0xc5b> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc50, 0xc5b, x86_l_c5b);
x86_l_c52:
	/* 0xc52: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_c55:
	/* 0xc55: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_c59:
	/* 0xc59: jmp    c83 <tail_nodeport_rev_dnat_ipv4+0xc83> */
	X86_SIM_X86_JMP(0xc59, 0xc83, x86_l_c83);
x86_l_c5b:
	/* 0xc5b: mov    QWORD PTR [rsp+0x68],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598785ULL);
x86_l_c64:
	/* 0xc64: mov    QWORD PTR [rsp+0x70],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_c69:
	/* 0xc69: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_c6e:
	/* 0xc6e: mov    rdi,QWORD PTR [rip+0x18dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_c75:
	/* 0xc75: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c7a:
	/* 0xc7a: lea    rdx,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_c7f:
	/* 0xc7f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c81:
	/* 0xc81: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c83:
	/* 0xc83: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_c88:
	/* 0xc88: mov    rsi,QWORD PTR [rip+0x18dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_c8f:
	/* 0xc8f: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_c92:
	/* 0xc92: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_c97:
	/* 0xc97: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c99:
	/* 0xc99: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_c9e:
	/* 0xc9e: add    rsp,0xb8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 184ULL);
x86_l_ca5:
	/* 0xca5: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_ca6:
	/* 0xca6: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_ca8:
	/* 0xca8: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_caa:
	/* 0xcaa: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_cac:
	/* 0xcac: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_cae:
	/* 0xcae: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_caf:
	/* 0xcaf: jmp    cc1 <tail_nodeport_rev_dnat_ipv4+0xcc1> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_cb4:
	/* 0xcb4: mov    eax,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967155ULL);
x86_l_cb9:
	/* 0xcb9: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_cbc:
	/* 0xcbc: jmp    bfd <tail_nodeport_rev_dnat_ipv4+0xbfd> */
	X86_SIM_X86_JMP(0xcbc, 0xbfd, x86_l_bfd);
x86_l_cc1:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
