extern char __config_debug_lb;
extern char __config_enable_conntrack_accounting;
extern char __config_enable_ipv4_fragments;
extern char __config_enable_jiffies;
extern char __config_kernel_hz;
extern char __config_trace_payload_len;
extern char cilium_calls;
extern char cilium_ct4_global;
extern char cilium_ct_any4_global;
extern char cilium_devices;
extern char cilium_ipv4_frag_datagrams;
extern char cilium_lb4_reverse_nat;
extern char cilium_metrics;
extern char cilium_nodeport_neigh4;
extern char cilium_xdp_scratch;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int cilium_bpf_xdp_tail_nodeport_rev_dnat_ipv4_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0xa8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 168ULL);
x86_l_a:
	/* 0xa: mov    rax,QWORD PTR [rip+0x1547] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_11:
	/* 0x11: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13:
	/* 0x13: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_1c:
	/* 0x1c: mov    DWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_27:
	/* 0x27: mov    QWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_33:
	/* 0x33: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_3c:
	/* 0x3c: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_45:
	/* 0x45: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_4e:
	/* 0x4e: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_57:
	/* 0x57: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_60:
	/* 0x60: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_63:
	/* 0x63: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_6c:
	/* 0x6c: mov    BYTE PTR [rsp+0x48],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 309237645314ULL);
x86_l_71:
	/* 0x71: mov    eax,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_74:
	/* 0x74: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_78:
	/* 0x78: mov    WORD PTR [rsp+0x2c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 188978561024ULL);
x86_l_7f:
	/* 0x7f: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_87:
	/* 0x87: mov    rax,QWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8a:
	/* 0x8a: mov    rcx,QWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8e:
	/* 0x8e: lea    rdx,[rax+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_92:
	/* 0x92: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_97:
	/* 0x97: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9a:
	/* 0x9a: cmp    rdx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_9d:
	/* 0x9d: jbe    1bf <tail_nodeport_rev_dnat_ipv4+0x1bf> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x9d, 0x1bf, x86_l_1bf);
x86_l_a3:
	/* 0xa3: shl    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_a7:
	/* 0xa7: movzx  r14d,r14w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_R14, X86_WIDTH_32, X86_WIDTH_16);
x86_l_ab:
	/* 0xab: mov    r15d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_32);
x86_l_ae:
	/* 0xae: mov    ebp,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_32);
x86_l_b1:
	/* 0xb1: neg    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_b3:
	/* 0xb3: cmovs  ebp,r15d */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_R15, X86_WIDTH_32, X86_CC_S);
x86_l_b7:
	/* 0xb7: mov    DWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_bf:
	/* 0xbf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c4:
	/* 0xc4: mov    rdi,QWORD PTR [rip+0x1547] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_cb:
	/* 0xcb: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_d0:
	/* 0xd0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d2:
	/* 0xd2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d5:
	/* 0xd5: je     dd <tail_nodeport_rev_dnat_ipv4+0xdd> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd5, 0xdd, x86_l_dd);
x86_l_d7:
	/* 0xd7: mov    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_dd:
	/* 0xdd: mov    DWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_e5:
	/* 0xe5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ea:
	/* 0xea: mov    rdi,QWORD PTR [rip+0x1547] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_f1:
	/* 0xf1: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_f6:
	/* 0xf6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f8:
	/* 0xf8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_fb:
	/* 0xfb: je     104 <tail_nodeport_rev_dnat_ipv4+0x104> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfb, 0x104, x86_l_104);
x86_l_fd:
	/* 0xfd: mov    DWORD PTR [rax+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_104:
	/* 0x104: mov    DWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_10c:
	/* 0x10c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_111:
	/* 0x111: mov    rdi,QWORD PTR [rip+0x1547] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_118:
	/* 0x118: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_11d:
	/* 0x11d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11f:
	/* 0x11f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_122:
	/* 0x122: je     12e <tail_nodeport_rev_dnat_ipv4+0x12e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x122, 0x12e, x86_l_12e);
x86_l_124:
	/* 0x124: movzx  ecx,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_128:
	/* 0x128: or     ecx,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R14, X86_WIDTH_32, X86_ALU_OR);
x86_l_12b:
	/* 0x12b: mov    DWORD PTR [rax+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12e:
	/* 0x12e: mov    DWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_136:
	/* 0x136: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13b:
	/* 0x13b: mov    rdi,QWORD PTR [rip+0x1547] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_142:
	/* 0x142: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_147:
	/* 0x147: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_149:
	/* 0x149: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14c:
	/* 0x14c: je     155 <tail_nodeport_rev_dnat_ipv4+0x155> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14c, 0x155, x86_l_155);
x86_l_14e:
	/* 0x14e: mov    DWORD PTR [rax+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_155:
	/* 0x155: mov    DWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_15d:
	/* 0x15d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_162:
	/* 0x162: mov    rdi,QWORD PTR [rip+0x1547] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_169:
	/* 0x169: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_16e:
	/* 0x16e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_170:
	/* 0x170: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_173:
	/* 0x173: je     17c <tail_nodeport_rev_dnat_ipv4+0x17c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x173, 0x17c, x86_l_17c);
x86_l_175:
	/* 0x175: mov    DWORD PTR [rax+0x10],0x97f6801 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68878821377ULL);
x86_l_17c:
	/* 0x17c: mov    r14,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_180:
	/* 0x180: sub    r14,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 0ULL);
x86_l_183:
	/* 0x183: movabs rax,0x68097f0200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 446835917312ULL);
x86_l_18d:
	/* 0x18d: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_192:
	/* 0x192: mov    BYTE PTR [rsp+0x8],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_197:
	/* 0x197: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_19c:
	/* 0x19c: mov    rdi,QWORD PTR [rip+0x1547] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1a3:
	/* 0x1a3: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a8:
	/* 0x1a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1aa:
	/* 0x1aa: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ad:
	/* 0x1ad: je     2d0 <tail_nodeport_rev_dnat_ipv4+0x2d0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1ad, 0x2d0, x86_l_2d0);
x86_l_1b3:
	/* 0x1b3: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1b6:
	/* 0x1b6: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1ba:
	/* 0x1ba: jmp    2f8 <tail_nodeport_rev_dnat_ipv4+0x2f8> */
	X86_SIM_X86_JMP(0x1ba, 0x2f8, x86_l_2f8);
x86_l_1bf:
	/* 0x1bf: movabs r9,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_64, 2199023255552ULL);
x86_l_1c9:
	/* 0x1c9: movabs r12,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 1099511627776ULL);
x86_l_1d3:
	/* 0x1d3: movzx  edx,WORD PTR [rax+0x12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18ULL);
x86_l_1d7:
	/* 0x1d7: movzx  r13d,BYTE PTR [rax+0x17] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 23ULL);
x86_l_1dc:
	/* 0x1dc: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_1df:
	/* 0x1df: shl    rsi,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_1e3:
	/* 0x1e3: or     rsi,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_64, X86_ALU_OR);
x86_l_1e6:
	/* 0x1e6: movzx  edx,WORD PTR [rax+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 20ULL);
x86_l_1ea:
	/* 0x1ea: lea    r8,[rsi+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_1ee:
	/* 0x1ee: test   edx,0xff3f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_32, 65343ULL);
x86_l_1f4:
	/* 0x1f4: cmove  r8,rsi */
	X86_SIM_L_EXEC_CMOV(X86_R8, X86_RSI, X86_WIDTH_64, X86_CC_E);
x86_l_1f8:
	/* 0x1f8: lea    r10,[r8+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R10, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_1fc:
	/* 0x1fc: test   edx,0xff1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_32, 65311ULL);
x86_l_202:
	/* 0x202: mov    edi,DWORD PTR [rax+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_205:
	/* 0x205: mov    BYTE PTR [rsp+0x2c],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_20a:
	/* 0x20a: mov    edx,DWORD PTR [rax+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_20d:
	/* 0x20d: mov    DWORD PTR [rsp+0x20],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_211:
	/* 0x211: cmove  r10,r8 */
	X86_SIM_L_EXEC_CMOV(X86_R10, X86_R8, X86_WIDTH_64, X86_CC_E);
x86_l_215:
	/* 0x215: mov    esi,DWORD PTR [rax+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_218:
	/* 0x218: mov    DWORD PTR [rsp+0x24],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_21c:
	/* 0x21c: mov    r15d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 2ULL);
x86_l_222:
	/* 0x222: cmp    r13d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 17ULL);
x86_l_226:
	/* 0x226: je     232 <tail_nodeport_rev_dnat_ipv4+0x232> */
	X86_SIM_X86_JCC(X86_CC_E, 0x226, 0x232, x86_l_232);
x86_l_228:
	/* 0x228: cmp    r13d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 6ULL);
x86_l_22c:
	/* 0x22c: jne    e02 <tail_nodeport_rev_dnat_ipv4+0xe02> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x22c, 0xe02, x86_l_e02);
x86_l_232:
	/* 0x232: and    edi,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_235:
	/* 0x235: lea    r11,[rdi*4+0xe] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 2), 14ULL);
x86_l_23d:
	/* 0x23d: mov    r8,QWORD PTR [rip+0x1547] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R8, (void *)(long)(((__u64)(long)&__config_enable_ipv4_fragments)));
x86_l_244:
	/* 0x244: cmp    BYTE PTR [r8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_248:
	/* 0x248: je     326 <tail_nodeport_rev_dnat_ipv4+0x326> */
	X86_SIM_X86_JCC(X86_CC_E, 0x248, 0x326, x86_l_326);
x86_l_24e:
	/* 0x24e: mov    DWORD PTR [rsp+0x30],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_252:
	/* 0x252: mov    DWORD PTR [rsp+0x34],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_256:
	/* 0x256: mov    WORD PTR [rsp+0x38],r10w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R10, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_25c:
	/* 0x25c: mov    rdx,r10 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R10, X86_WIDTH_64);
x86_l_25f:
	/* 0x25f: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_263:
	/* 0x263: mov    BYTE PTR [rsp+0x3a],dl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_267:
	/* 0x267: mov    BYTE PTR [rsp+0x3b],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 253403070464ULL);
x86_l_26c:
	/* 0x26c: test   r10,r9 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R10, X86_R9, X86_WIDTH_64);
x86_l_26f:
	/* 0x26f: jne    b62 <tail_nodeport_rev_dnat_ipv4+0xb62> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x26f, 0xb62, x86_l_b62);
x86_l_275:
	/* 0x275: lea    rdx,[rax+r11*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R11, 0), 0ULL);
x86_l_279:
	/* 0x279: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_27d:
	/* 0x27d: mov    ebp,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967161ULL);
x86_l_282:
	/* 0x282: cmp    rdx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_285:
	/* 0x285: ja     a3 <tail_nodeport_rev_dnat_ipv4+0xa3> */
	X86_SIM_X86_JCC(X86_CC_A, 0x285, 0xa3, x86_l_a3);
x86_l_28b:
	/* 0x28b: add    rax,r11 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R11, X86_WIDTH_64, X86_ALU_ADD);
x86_l_28e:
	/* 0x28e: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_290:
	/* 0x290: mov    DWORD PTR [rsp+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_294:
	/* 0x294: test   r10,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R10, X86_R12, X86_WIDTH_64);
x86_l_297:
	/* 0x297: jne    bcd <tail_nodeport_rev_dnat_ipv4+0xbcd> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x297, 0xbcd, x86_l_bcd);
x86_l_29d:
	/* 0x29d: movzx  r13d,BYTE PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 44ULL);
x86_l_2a3:
	/* 0x2a3: cmp    r13b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_8, 6ULL);
x86_l_2a7:
	/* 0x2a7: jne    35c <tail_nodeport_rev_dnat_ipv4+0x35c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2a7, 0x35c, x86_l_35c);
x86_l_2ad:
	/* 0x2ad: mov    rdi,QWORD PTR [rip+0x1547] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct4_global)));
x86_l_2b4:
	/* 0x2b4: mov    BYTE PTR [rsp+0x2d],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 193273528320ULL);
x86_l_2b9:
	/* 0x2b9: cmp    BYTE PTR [r8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bd:
	/* 0x2bd: mov    QWORD PTR [rsp+0x90],r10 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R10, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2c5:
	/* 0x2c5: jne    37a <tail_nodeport_rev_dnat_ipv4+0x37a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2c5, 0x37a, x86_l_37a);
x86_l_2cb:
	/* 0x2cb: jmp    412 <tail_nodeport_rev_dnat_ipv4+0x412> */
	X86_SIM_X86_JMP(0x2cb, 0x412, x86_l_412);
x86_l_2d0:
	/* 0x2d0: mov    QWORD PTR [rsp+0x48],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645313ULL);
x86_l_2d9:
	/* 0x2d9: mov    QWORD PTR [rsp+0x50],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2de:
	/* 0x2de: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2e3:
	/* 0x2e3: mov    rdi,QWORD PTR [rip+0x1547] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_2ea:
	/* 0x2ea: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ef:
	/* 0x2ef: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2f4:
	/* 0x2f4: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f6:
	/* 0x2f6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f8:
	/* 0x2f8: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2fd:
	/* 0x2fd: mov    rsi,QWORD PTR [rip+0x1547] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_304:
	/* 0x304: mov    r15d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 1ULL);
x86_l_30a:
	/* 0x30a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_30d:
	/* 0x30d: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_312:
	/* 0x312: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_314:
	/* 0x314: mov    eax,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_317:
	/* 0x317: add    rsp,0xa8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 168ULL);
x86_l_31e:
	/* 0x31e: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_320:
	/* 0x320: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_321:
	/* 0x321: jmp    e70 <tail_nodeport_rev_dnat_ipv4+0xe70> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_326:
	/* 0x326: test   r10,r9 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R10, X86_R9, X86_WIDTH_64);
x86_l_329:
	/* 0x329: jne    b8f <tail_nodeport_rev_dnat_ipv4+0xb8f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x329, 0xb8f, x86_l_b8f);
x86_l_32f:
	/* 0x32f: movzx  edx,r11b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_R11, X86_WIDTH_32, X86_WIDTH_8);
x86_l_333:
	/* 0x333: lea    rsi,[rax+rdx*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_337:
	/* 0x337: add    rsi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_33b:
	/* 0x33b: mov    ebp,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967161ULL);
x86_l_340:
	/* 0x340: cmp    rsi,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_64);
x86_l_343:
	/* 0x343: ja     a3 <tail_nodeport_rev_dnat_ipv4+0xa3> */
	X86_SIM_X86_JCC(X86_CC_A, 0x343, 0xa3, x86_l_a3);
x86_l_349:
	/* 0x349: add    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_34c:
	/* 0x34c: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_34e:
	/* 0x34e: mov    DWORD PTR [rsp+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_352:
	/* 0x352: cmp    r13b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_8, 6ULL);
x86_l_356:
	/* 0x356: je     2ad <tail_nodeport_rev_dnat_ipv4+0x2ad> */
	X86_SIM_X86_JCC(X86_CC_E, 0x356, 0x2ad, x86_l_2ad);
x86_l_35c:
	/* 0x35c: mov    rdi,QWORD PTR [rip+0x154a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct_any4_global)));
x86_l_363:
	/* 0x363: mov    BYTE PTR [rsp+0x2d],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 193273528320ULL);
x86_l_368:
	/* 0x368: cmp    BYTE PTR [r8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_36c:
	/* 0x36c: mov    QWORD PTR [rsp+0x90],r10 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R10, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_374:
	/* 0x374: je     412 <tail_nodeport_rev_dnat_ipv4+0x412> */
	X86_SIM_X86_JCC(X86_CC_E, 0x374, 0x412, x86_l_412);
x86_l_37a:
	/* 0x37a: and    r12,r10 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R10, X86_WIDTH_64, X86_ALU_AND);
x86_l_37d:
	/* 0x37d: je     412 <tail_nodeport_rev_dnat_ipv4+0x412> */
	X86_SIM_X86_JCC(X86_CC_E, 0x37d, 0x412, x86_l_412);
x86_l_383:
	/* 0x383: mov    QWORD PTR [rsp+0x40],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_388:
	/* 0x388: mov    r14,r9 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R9, X86_WIDTH_64);
x86_l_38b:
	/* 0x38b: mov    rbp,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R11, X86_WIDTH_64);
x86_l_38e:
	/* 0x38e: mov    r12,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_392:
	/* 0x392: sub    r12,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 0ULL);
x86_l_395:
	/* 0x395: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_39e:
	/* 0x39e: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_3a7:
	/* 0x3a7: movabs rax,0x6c03a50109 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 463917613321ULL);
x86_l_3b1:
	/* 0x3b1: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3b6:
	/* 0x3b6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3bb:
	/* 0x3bb: mov    rdi,QWORD PTR [rip+0x154a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_3c2:
	/* 0x3c2: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3c7:
	/* 0x3c7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c9:
	/* 0x3c9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3cc:
	/* 0x3cc: je     3d7 <tail_nodeport_rev_dnat_ipv4+0x3d7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3cc, 0x3d7, x86_l_3d7);
x86_l_3ce:
	/* 0x3ce: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_3d1:
	/* 0x3d1: add    QWORD PTR [rax+0x8],r12 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3d5:
	/* 0x3d5: jmp    3ff <tail_nodeport_rev_dnat_ipv4+0x3ff> */
	X86_SIM_X86_JMP(0x3d5, 0x3ff, x86_l_3ff);
x86_l_3d7:
	/* 0x3d7: mov    QWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_3e0:
	/* 0x3e0: mov    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3e5:
	/* 0x3e5: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3ea:
	/* 0x3ea: mov    rdi,QWORD PTR [rip+0x154a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_3f1:
	/* 0x3f1: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3f6:
	/* 0x3f6: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3fb:
	/* 0x3fb: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3fd:
	/* 0x3fd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ff:
	/* 0x3ff: mov    r11,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_RBP, X86_WIDTH_64);
x86_l_402:
	/* 0x402: mov    r9,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_R14, X86_WIDTH_64);
x86_l_405:
	/* 0x405: mov    r10,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_40d:
	/* 0x40d: mov    rdi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_412:
	/* 0x412: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_415:
	/* 0x415: cmp    r13b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_8, 6ULL);
x86_l_419:
	/* 0x419: jne    46f <tail_nodeport_rev_dnat_ipv4+0x46f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x419, 0x46f, x86_l_46f);
x86_l_41b:
	/* 0x41b: mov    rax,r10 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R10, X86_WIDTH_64);
x86_l_41e:
	/* 0x41e: mov    r12d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 0ULL);
x86_l_424:
	/* 0x424: and    rax,r9 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R9, X86_WIDTH_64, X86_ALU_AND);
x86_l_427:
	/* 0x427: jne    472 <tail_nodeport_rev_dnat_ipv4+0x472> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x427, 0x472, x86_l_472);
x86_l_429:
	/* 0x429: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_42c:
	/* 0x42c: movzx  ecx,r11b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R11, X86_WIDTH_32, X86_WIDTH_8);
x86_l_430:
	/* 0x430: lea    rdx,[rax+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_434:
	/* 0x434: add    rdx,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 14ULL);
x86_l_438:
	/* 0x438: cmp    rdx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_43c:
	/* 0x43c: ja     e02 <tail_nodeport_rev_dnat_ipv4+0xe02> */
	X86_SIM_X86_JCC(X86_CC_A, 0x43c, 0xe02, x86_l_e02);
x86_l_442:
	/* 0x442: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_445:
	/* 0x445: movzx  r14d,WORD PTR [rax+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_44a:
	/* 0x44a: mov    eax,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_32);
x86_l_44d:
	/* 0x44d: and    eax,0x1200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4608ULL);
x86_l_452:
	/* 0x452: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_455:
	/* 0x455: cmp    eax,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 512ULL);
x86_l_45a:
	/* 0x45a: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_45d:
	/* 0x45d: test   r14d,0x500 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R14, X86_WIDTH_32, 1280ULL);
x86_l_464:
	/* 0x464: jne    c68 <tail_nodeport_rev_dnat_ipv4+0xc68> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x464, 0xc68, x86_l_c68);
x86_l_46a:
	/* 0x46a: mov    r12b,al */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_8);
x86_l_46d:
	/* 0x46d: jmp    472 <tail_nodeport_rev_dnat_ipv4+0x472> */
	X86_SIM_X86_JMP(0x46d, 0x472, x86_l_472);
x86_l_46f:
	/* 0x46f: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_472:
	/* 0x472: mov    QWORD PTR [rsp+0x40],r11 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_477:
	/* 0x477: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_47c:
	/* 0x47c: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_481:
	/* 0x481: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_483:
	/* 0x483: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_486:
	/* 0x486: je     df9 <tail_nodeport_rev_dnat_ipv4+0xdf9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x486, 0xdf9, x86_l_df9);
x86_l_48c:
	/* 0x48c: movzx  ecx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_490:
	/* 0x490: test   cl,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_493:
	/* 0x493: je     df9 <tail_nodeport_rev_dnat_ipv4+0xdf9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x493, 0xdf9, x86_l_df9);
x86_l_499:
	/* 0x499: cmp    WORD PTR [rax+0x26],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 163208757248ULL);
x86_l_49e:
	/* 0x49e: je     df9 <tail_nodeport_rev_dnat_ipv4+0xdf9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x49e, 0xdf9, x86_l_df9);
x86_l_4a4:
	/* 0x4a4: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_4a6:
	/* 0x4a6: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_4a8:
	/* 0x4a8: test   dl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_8, 3ULL);
x86_l_4ab:
	/* 0x4ab: mov    r8,QWORD PTR [rip+0x154a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R8, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_4b2:
	/* 0x4b2: je     5c8 <tail_nodeport_rev_dnat_ipv4+0x5c8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4b2, 0x5c8, x86_l_5c8);
x86_l_4b8:
	/* 0x4b8: mov    DWORD PTR [rsp+0x1c],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_4bd:
	/* 0x4bd: mov    rsi,QWORD PTR [rip+0x154a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_4c4:
	/* 0x4c4: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4c7:
	/* 0x4c7: je     4da <tail_nodeport_rev_dnat_ipv4+0x4da> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4c7, 0x4da, x86_l_4da);
x86_l_4c9:
	/* 0x4c9: mov    rdx,QWORD PTR [rip+0x154a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_4d0:
	/* 0x4d0: imul   r14d,DWORD PTR [rdx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R14, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_4d4:
	/* 0x4d4: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_4d8:
	/* 0x4d8: jmp    4e0 <tail_nodeport_rev_dnat_ipv4+0x4e0> */
	X86_SIM_X86_JMP(0x4d8, 0x4e0, x86_l_4e0);
x86_l_4da:
	/* 0x4da: mov    r14d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 60ULL);
x86_l_4e0:
	/* 0x4e0: cmp    r13b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_8, 6ULL);
x86_l_4e4:
	/* 0x4e4: jne    51e <tail_nodeport_rev_dnat_ipv4+0x51e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4e4, 0x51e, x86_l_51e);
x86_l_4e6:
	/* 0x4e6: mov    edx,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_4ea:
	/* 0x4ea: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_4ec:
	/* 0x4ec: shr    edx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_4ef:
	/* 0x4ef: and    edx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_4f2:
	/* 0x4f2: or     ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_4f4:
	/* 0x4f4: mov    WORD PTR [rax+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_4f8:
	/* 0x4f8: test   cl,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 16ULL);
x86_l_4fb:
	/* 0x4fb: mov    ecx,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 60ULL);
x86_l_500:
	/* 0x500: mov    r14d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 21600ULL);
x86_l_506:
	/* 0x506: cmove  r14d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R14, X86_RCX, X86_WIDTH_32, X86_CC_E);
x86_l_50a:
	/* 0x50a: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_50d:
	/* 0x50d: je     51e <tail_nodeport_rev_dnat_ipv4+0x51e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x50d, 0x51e, x86_l_51e);
x86_l_50f:
	/* 0x50f: mov    rcx,QWORD PTR [rip+0x154a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_516:
	/* 0x516: imul   r14d,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_51a:
	/* 0x51a: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_51e:
	/* 0x51e: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_526:
	/* 0x526: movzx  ebp,WORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 28ULL);
x86_l_52b:
	/* 0x52b: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_52e:
	/* 0x52e: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_531:
	/* 0x531: je     545 <tail_nodeport_rev_dnat_ipv4+0x545> */
	X86_SIM_X86_JCC(X86_CC_E, 0x531, 0x545, x86_l_545);
x86_l_533:
	/* 0x533: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_538:
	/* 0x538: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_53a:
	/* 0x53a: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_53c:
	/* 0x53c: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_53f:
	/* 0x53f: shr    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_543:
	/* 0x543: jmp    568 <tail_nodeport_rev_dnat_ipv4+0x568> */
	X86_SIM_X86_JMP(0x543, 0x568, x86_l_568);
x86_l_545:
	/* 0x545: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_54a:
	/* 0x54a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_54c:
	/* 0x54c: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_54e:
	/* 0x54e: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_552:
	/* 0x552: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_55c:
	/* 0x55c: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_55f:
	/* 0x55f: mulx   rcx,rcx,rcx */
	X86_SIM_L_EXEC_MULX(X86_RCX, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_564:
	/* 0x564: shr    rcx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_568:
	/* 0x568: add    r14d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_56b:
	/* 0x56b: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_573:
	/* 0x573: mov    DWORD PTR [rax+0x20],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_577:
	/* 0x577: movzx  edx,BYTE PTR [rax+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_57b:
	/* 0x57b: mov    esi,DWORD PTR [rax+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_57e:
	/* 0x57e: and    bpl,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_582:
	/* 0x582: mov    rdi,QWORD PTR [rip+0x154a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_589:
	/* 0x589: cmp    BYTE PTR [rdi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_58c:
	/* 0x58c: mov    r8,QWORD PTR [rip+0x154a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R8, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_593:
	/* 0x593: je     5a6 <tail_nodeport_rev_dnat_ipv4+0x5a6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x593, 0x5a6, x86_l_5a6);
x86_l_595:
	/* 0x595: mov    rdi,QWORD PTR [rip+0x154a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_59c:
	/* 0x59c: mov    edi,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_59e:
	/* 0x59e: lea    edi,[rdi+rdi*4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_5a1:
	/* 0x5a1: shr    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_5a4:
	/* 0x5a4: jmp    5ab <tail_nodeport_rev_dnat_ipv4+0x5ab> */
	X86_SIM_X86_JMP(0x5a4, 0x5ab, x86_l_5ab);
x86_l_5a6:
	/* 0x5a6: mov    edi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 5ULL);
x86_l_5ab:
	/* 0x5ab: mov    r14d,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_5b0:
	/* 0x5b0: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_5b2:
	/* 0x5b2: or     bpl,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_5b5:
	/* 0x5b5: cmp    edi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RCX, X86_WIDTH_32);
x86_l_5b7:
	/* 0x5b7: jb     5be <tail_nodeport_rev_dnat_ipv4+0x5be> */
	X86_SIM_X86_JCC(X86_CC_B, 0x5b7, 0x5be, x86_l_5be);
x86_l_5b9:
	/* 0x5b9: cmp    dl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBP, X86_WIDTH_8);
x86_l_5bc:
	/* 0x5bc: je     5c8 <tail_nodeport_rev_dnat_ipv4+0x5c8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5bc, 0x5c8, x86_l_5c8);
x86_l_5be:
	/* 0x5be: mov    BYTE PTR [rax+0x2b],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_5c2:
	/* 0x5c2: mov    DWORD PTR [rax+0x34],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_5c5:
	/* 0x5c5: mov    ecx,DWORD PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5c8:
	/* 0x5c8: mov    rcx,QWORD PTR [rip+0x154a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_5cf:
	/* 0x5cf: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5d2:
	/* 0x5d2: je     5e5 <tail_nodeport_rev_dnat_ipv4+0x5e5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5d2, 0x5e5, x86_l_5e5);
x86_l_5d4:
	/* 0x5d4: inc QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 16ULL);
x86_l_5d9:
	/* 0x5d9: mov    rcx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5dd:
	/* 0x5dd: sub    rcx,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 0ULL);
x86_l_5e0:
	/* 0x5e0: add QWORD PTR [rax+0x18],rcx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_5e5:
	/* 0x5e5: cmp    r12d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 2ULL);
x86_l_5e9:
	/* 0x5e9: je     63c <tail_nodeport_rev_dnat_ipv4+0x63c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5e9, 0x63c, x86_l_63c);
x86_l_5eb:
	/* 0x5eb: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_5ef:
	/* 0x5ef: jne    71f <tail_nodeport_rev_dnat_ipv4+0x71f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x5ef, 0x71f, x86_l_71f);
x86_l_5f5:
	/* 0x5f5: movzx  ecx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_5f9:
	/* 0x5f9: test   cl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_5fc:
	/* 0x5fc: je     71f <tail_nodeport_rev_dnat_ipv4+0x71f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5fc, 0x71f, x86_l_71f);
x86_l_602:
	/* 0x602: mov    edx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_32);
x86_l_605:
	/* 0x605: mov    WORD PTR [rax+0x2a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 180388626432ULL);
x86_l_60b:
	/* 0x60b: and    ecx,0xffec */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 65516ULL);
x86_l_611:
	/* 0x611: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_614:
	/* 0x614: mov    WORD PTR [rax+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_618:
	/* 0x618: mov    rax,QWORD PTR [rip+0x154a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_61f:
	/* 0x61f: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_622:
	/* 0x622: je     d1d <tail_nodeport_rev_dnat_ipv4+0xd1d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x622, 0xd1d, x86_l_d1d);
x86_l_628:
	/* 0x628: mov    rax,QWORD PTR [rip+0x154a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_62f:
	/* 0x62f: imul   r12d,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_633:
	/* 0x633: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_637:
	/* 0x637: jmp    d23 <tail_nodeport_rev_dnat_ipv4+0xd23> */
	X86_SIM_X86_JMP(0x637, 0xd23, x86_l_d23);
x86_l_63c:
	/* 0x63c: mov    ecx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_32);
x86_l_63f:
	/* 0x63f: shr    ecx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_642:
	/* 0x642: and    ecx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2ULL);
x86_l_645:
	/* 0x645: or     cx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RAX, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 36ULL);
x86_l_649:
	/* 0x649: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_64b:
	/* 0x64b: or     edx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_OR, 1ULL);
x86_l_64e:
	/* 0x64e: mov    WORD PTR [rax+0x24],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_652:
	/* 0x652: mov    edx,DWORD PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_655:
	/* 0x655: test   cl,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_658:
	/* 0x658: je     71f <tail_nodeport_rev_dnat_ipv4+0x71f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x658, 0x71f, x86_l_71f);
x86_l_65e:
	/* 0x65e: mov    edx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_32);
x86_l_661:
	/* 0x661: mov    r14,QWORD PTR [rip+0x154a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_668:
	/* 0x668: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_66c:
	/* 0x66c: je     683 <tail_nodeport_rev_dnat_ipv4+0x683> */
	X86_SIM_X86_JCC(X86_CC_E, 0x66c, 0x683, x86_l_683);
x86_l_66e:
	/* 0x66e: mov    rcx,QWORD PTR [rip+0x154a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_675:
	/* 0x675: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_677:
	/* 0x677: add    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_679:
	/* 0x679: lea    r12d,[rcx+rcx*4] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 0ULL);
x86_l_67d:
	/* 0x67d: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_681:
	/* 0x681: jmp    689 <tail_nodeport_rev_dnat_ipv4+0x689> */
	X86_SIM_X86_JMP(0x681, 0x689, x86_l_689);
x86_l_683:
	/* 0x683: mov    r12d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 10ULL);
x86_l_689:
	/* 0x689: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_68c:
	/* 0x68c: movzx  ebp,dx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RDX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_68f:
	/* 0x68f: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_692:
	/* 0x692: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_696:
	/* 0x696: je     6aa <tail_nodeport_rev_dnat_ipv4+0x6aa> */
	X86_SIM_X86_JCC(X86_CC_E, 0x696, 0x6aa, x86_l_6aa);
x86_l_698:
	/* 0x698: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_69d:
	/* 0x69d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_69f:
	/* 0x69f: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_6a1:
	/* 0x6a1: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_6a4:
	/* 0x6a4: shr    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_6a8:
	/* 0x6a8: jmp    6cd <tail_nodeport_rev_dnat_ipv4+0x6cd> */
	X86_SIM_X86_JMP(0x6a8, 0x6cd, x86_l_6cd);
x86_l_6aa:
	/* 0x6aa: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_6af:
	/* 0x6af: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6b1:
	/* 0x6b1: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_6b3:
	/* 0x6b3: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_6b7:
	/* 0x6b7: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_6c1:
	/* 0x6c1: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_6c4:
	/* 0x6c4: mulx   rcx,rcx,rcx */
	X86_SIM_L_EXEC_MULX(X86_RCX, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_6c9:
	/* 0x6c9: shr    rcx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_6cd:
	/* 0x6cd: add    r12d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_6d0:
	/* 0x6d0: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_6d3:
	/* 0x6d3: mov    DWORD PTR [r13+0x20],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6d7:
	/* 0x6d7: movzx  edx,BYTE PTR [r13+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_6dc:
	/* 0x6dc: mov    esi,DWORD PTR [r13+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_6e0:
	/* 0x6e0: and    bpl,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_6e4:
	/* 0x6e4: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6e8:
	/* 0x6e8: mov    r8,QWORD PTR [rip+0x154a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R8, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_6ef:
	/* 0x6ef: je     702 <tail_nodeport_rev_dnat_ipv4+0x702> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6ef, 0x702, x86_l_702);
x86_l_6f1:
	/* 0x6f1: mov    rdi,QWORD PTR [rip+0x154a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_6f8:
	/* 0x6f8: mov    edi,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6fa:
	/* 0x6fa: lea    edi,[rdi+rdi*4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_6fd:
	/* 0x6fd: shr    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_700:
	/* 0x700: jmp    707 <tail_nodeport_rev_dnat_ipv4+0x707> */
	X86_SIM_X86_JMP(0x700, 0x707, x86_l_707);
x86_l_702:
	/* 0x702: mov    edi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 5ULL);
x86_l_707:
	/* 0x707: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_709:
	/* 0x709: or     bpl,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_70c:
	/* 0x70c: cmp    edi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RCX, X86_WIDTH_32);
x86_l_70e:
	/* 0x70e: jb     715 <tail_nodeport_rev_dnat_ipv4+0x715> */
	X86_SIM_X86_JCC(X86_CC_B, 0x70e, 0x715, x86_l_715);
x86_l_710:
	/* 0x710: cmp    dl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBP, X86_WIDTH_8);
x86_l_713:
	/* 0x713: je     71f <tail_nodeport_rev_dnat_ipv4+0x71f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x713, 0x71f, x86_l_71f);
x86_l_715:
	/* 0x715: mov    BYTE PTR [rax+0x2b],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_719:
	/* 0x719: mov    DWORD PTR [rax+0x34],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_71c:
	/* 0x71c: mov    ecx,DWORD PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_71f:
	/* 0x71f: test   BYTE PTR [rsp+0x2d],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 193273528322ULL);
x86_l_724:
	/* 0x724: jne    e02 <tail_nodeport_rev_dnat_ipv4+0xe02> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x724, 0xe02, x86_l_e02);
x86_l_72a:
	/* 0x72a: movzx  eax,WORD PTR [rax+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_72e:
	/* 0x72e: mov    WORD PTR [rsp+0x8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_733:
	/* 0x733: mov    r14,QWORD PTR [rip+0x154a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_73a:
	/* 0x73a: movzx  eax,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_73e:
	/* 0x73e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_743:
	/* 0x743: mov    rdi,QWORD PTR [rip+0x154a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_reverse_nat)));
x86_l_74a:
	/* 0x74a: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_74f:
	/* 0x74f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_751:
	/* 0x751: mov    r12,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_754:
	/* 0x754: mov    rcx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_758:
	/* 0x758: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_75b:
	/* 0x75b: je     863 <tail_nodeport_rev_dnat_ipv4+0x863> */
	X86_SIM_X86_JCC(X86_CC_E, 0x75b, 0x863, x86_l_863);
x86_l_761:
	/* 0x761: mov    edx,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_765:
	/* 0x765: movzx  esi,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_769:
	/* 0x769: mov    esi,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_76b:
	/* 0x76b: mov    DWORD PTR [rsp+0x24],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_76f:
	/* 0x76f: lea    rsi,[r12+0x1e] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_774:
	/* 0x774: cmp    rsi,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_64);
x86_l_777:
	/* 0x777: jbe    786 <tail_nodeport_rev_dnat_ipv4+0x786> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x777, 0x786, x86_l_786);
x86_l_779:
	/* 0x779: mov    ebp,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967155ULL);
x86_l_77e:
	/* 0x77e: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_781:
	/* 0x781: jmp    a3 <tail_nodeport_rev_dnat_ipv4+0xa3> */
	X86_SIM_X86_JMP(0x781, 0xa3, x86_l_a3);
x86_l_786:
	/* 0x786: mov    esi,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_788:
	/* 0x788: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_78a:
	/* 0x78a: add    edx,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_78c:
	/* 0x78c: adc    edx,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_78f:
	/* 0x78f: movzx  edi,WORD PTR [r12+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 24ULL);
x86_l_795:
	/* 0x795: not    edi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_797:
	/* 0x797: add    edi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_799:
	/* 0x799: adc    edi,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_79c:
	/* 0x79c: movzx  r8d,di */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R8, X86_RDI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_7a0:
	/* 0x7a0: shr    edi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_7a3:
	/* 0x7a3: add    edi,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R8, X86_WIDTH_32, X86_ALU_ADD);
x86_l_7a6:
	/* 0x7a6: mov    r8d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RDI, X86_WIDTH_32);
x86_l_7a9:
	/* 0x7a9: shr    r8d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_7ad:
	/* 0x7ad: add    r8d,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_7b0:
	/* 0x7b0: mov    DWORD PTR [r12+0x1a],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_7b5:
	/* 0x7b5: not    r8d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_7b8:
	/* 0x7b8: mov    WORD PTR [r12+0x18],r8w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R8, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_7be:
	/* 0x7be: movabs rsi,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 2199023255552ULL);
x86_l_7c8:
	/* 0x7c8: test   QWORD PTR [rsp+0x90],rsi */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_7d0:
	/* 0x7d0: jne    863 <tail_nodeport_rev_dnat_ipv4+0x863> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x7d0, 0x863, x86_l_863);
x86_l_7d6:
	/* 0x7d6: movzx  r11d,BYTE PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 44ULL);
x86_l_7dc:
	/* 0x7dc: mov    sil,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_8, 1ULL);
x86_l_7df:
	/* 0x7df: cmp    r11d,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 58ULL);
x86_l_7e3:
	/* 0x7e3: je     804 <tail_nodeport_rev_dnat_ipv4+0x804> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7e3, 0x804, x86_l_804);
x86_l_7e5:
	/* 0x7e5: cmp    r11d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 17ULL);
x86_l_7e9:
	/* 0x7e9: je     7f8 <tail_nodeport_rev_dnat_ipv4+0x7f8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7e9, 0x7f8, x86_l_7f8);
x86_l_7eb:
	/* 0x7eb: cmp    r11d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 6ULL);
x86_l_7ef:
	/* 0x7ef: jne    80e <tail_nodeport_rev_dnat_ipv4+0x80e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x7ef, 0x80e, x86_l_80e);
x86_l_7f1:
	/* 0x7f1: mov    edi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 16ULL);
x86_l_7f6:
	/* 0x7f6: jmp    809 <tail_nodeport_rev_dnat_ipv4+0x809> */
	X86_SIM_X86_JMP(0x7f6, 0x809, x86_l_809);
x86_l_7f8:
	/* 0x7f8: mov    edi,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 6ULL);
x86_l_7fd:
	/* 0x7fd: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_800:
	/* 0x800: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_802:
	/* 0x802: jmp    813 <tail_nodeport_rev_dnat_ipv4+0x813> */
	X86_SIM_X86_JMP(0x802, 0x813, x86_l_813);
x86_l_804:
	/* 0x804: mov    edi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 2ULL);
x86_l_809:
	/* 0x809: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_80c:
	/* 0x80c: jmp    813 <tail_nodeport_rev_dnat_ipv4+0x813> */
	X86_SIM_X86_JMP(0x80c, 0x813, x86_l_813);
x86_l_80e:
	/* 0x80e: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_810:
	/* 0x810: mov    r8b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_8, 1ULL);
x86_l_813:
	/* 0x813: movzx  r9d,WORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_818:
	/* 0x818: test   r9d,r9d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R9, X86_R9, X86_WIDTH_32);
x86_l_81b:
	/* 0x81b: je     85a <tail_nodeport_rev_dnat_ipv4+0x85a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x81b, 0x85a, x86_l_85a);
x86_l_81d:
	/* 0x81d: movzx  r10d,WORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 40ULL);
x86_l_823:
	/* 0x823: mov    r15d,0xffffff72 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967154ULL);
x86_l_829:
	/* 0x829: cmp    r11d,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 16ULL);
x86_l_82d:
	/* 0x82d: jg     840 <tail_nodeport_rev_dnat_ipv4+0x840> */
	X86_SIM_X86_JCC(X86_CC_G, 0x82d, 0x840, x86_l_840);
x86_l_82f:
	/* 0x82f: cmp    r11d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 1ULL);
x86_l_833:
	/* 0x833: je     85a <tail_nodeport_rev_dnat_ipv4+0x85a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x833, 0x85a, x86_l_85a);
x86_l_835:
	/* 0x835: cmp    r11d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 6ULL);
x86_l_839:
	/* 0x839: je     850 <tail_nodeport_rev_dnat_ipv4+0x850> */
	X86_SIM_X86_JCC(X86_CC_E, 0x839, 0x850, x86_l_850);
x86_l_83b:
	/* 0x83b: jmp    ae3 <tail_nodeport_rev_dnat_ipv4+0xae3> */
	X86_SIM_X86_JMP(0x83b, 0xae3, x86_l_ae3);
x86_l_840:
	/* 0x840: cmp    r11d,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 58ULL);
x86_l_844:
	/* 0x844: je     85a <tail_nodeport_rev_dnat_ipv4+0x85a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x844, 0x85a, x86_l_85a);
x86_l_846:
	/* 0x846: cmp    r11d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R11, X86_WIDTH_32, 17ULL);
x86_l_84a:
	/* 0x84a: jne    ae3 <tail_nodeport_rev_dnat_ipv4+0xae3> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x84a, 0xae3, x86_l_ae3);
x86_l_850:
	/* 0x850: cmp    r9w,r10w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R9, X86_R10, X86_WIDTH_16);
x86_l_854:
	/* 0x854: jne    aa7 <tail_nodeport_rev_dnat_ipv4+0xaa7> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x854, 0xaa7, x86_l_aa7);
x86_l_85a:
	/* 0x85a: test   r8b,r8b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R8, X86_R8, X86_WIDTH_8);
x86_l_85d:
	/* 0x85d: je     a36 <tail_nodeport_rev_dnat_ipv4+0xa36> */
	X86_SIM_X86_JCC(X86_CC_E, 0x85d, 0xa36, x86_l_a36);
x86_l_863:
	/* 0x863: lea    rax,[r12+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_868:
	/* 0x868: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_86b:
	/* 0x86b: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_870:
	/* 0x870: cmp    rax,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_873:
	/* 0x873: ja     a3 <tail_nodeport_rev_dnat_ipv4+0xa3> */
	X86_SIM_X86_JCC(X86_CC_A, 0x873, 0xa3, x86_l_a3);
x86_l_879:
	/* 0x879: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_881:
	/* 0x881: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_886:
	/* 0x886: mov    rdi,QWORD PTR [rip+0x154a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_88d:
	/* 0x88d: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_892:
	/* 0x892: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_894:
	/* 0x894: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_897:
	/* 0x897: je     d16 <tail_nodeport_rev_dnat_ipv4+0xd16> */
	X86_SIM_X86_JCC(X86_CC_E, 0x897, 0xd16, x86_l_d16);
x86_l_89d:
	/* 0x89d: mov    ebp,DWORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_8a0:
	/* 0x8a0: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_8a8:
	/* 0x8a8: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_8ad:
	/* 0x8ad: mov    rdi,QWORD PTR [rip+0x154a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_8b4:
	/* 0x8b4: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8b9:
	/* 0x8b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8bb:
	/* 0x8bb: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8be:
	/* 0x8be: je     8c6 <tail_nodeport_rev_dnat_ipv4+0x8c6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8be, 0x8c6, x86_l_8c6);
x86_l_8c0:
	/* 0x8c0: or     ebp,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_OR, 4ULL);
x86_l_8c3:
	/* 0x8c3: mov    DWORD PTR [rax+0x18],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_8c6:
	/* 0x8c6: mov    eax,DWORD PTR [r12+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_8cb:
	/* 0x8cb: mov    DWORD PTR [rsp+0x58],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_8cf:
	/* 0x8cf: mov    eax,DWORD PTR [r12+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_8d4:
	/* 0x8d4: mov    DWORD PTR [rsp+0x68],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_8d8:
	/* 0x8d8: movzx  ecx,BYTE PTR [r12+0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 22ULL);
x86_l_8de:
	/* 0x8de: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8e1:
	/* 0x8e1: mov    ebp,0xffffff3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967100ULL);
x86_l_8e6:
	/* 0x8e6: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_8e9:
	/* 0x8e9: jb     a3 <tail_nodeport_rev_dnat_ipv4+0xa3> */
	X86_SIM_X86_JCC(X86_CC_B, 0x8e9, 0xa3, x86_l_a3);
x86_l_8ef:
	/* 0x8ef: lea    edx,[rcx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_8f2:
	/* 0x8f2: mov    BYTE PTR [r12+0x16],dl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_8f7:
	/* 0x8f7: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8fa:
	/* 0x8fa: lea    rsi,[rax+0x1a] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_8fe:
	/* 0x8fe: mov    ebp,0xffffff67 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967143ULL);
x86_l_903:
	/* 0x903: cmp    rsi,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_907:
	/* 0x907: ja     a3 <tail_nodeport_rev_dnat_ipv4+0xa3> */
	X86_SIM_X86_JCC(X86_CC_A, 0x907, 0xa3, x86_l_a3);
x86_l_90d:
	/* 0x90d: movzx  edx,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_910:
	/* 0x910: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_912:
	/* 0x912: add    ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_914:
	/* 0x914: adc    ecx,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_917:
	/* 0x917: movzx  edx,WORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 24ULL);
x86_l_91b:
	/* 0x91b: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_91d:
	/* 0x91d: add    edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_91f:
	/* 0x91f: adc    edx,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_922:
	/* 0x922: movzx  ecx,dx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RDX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_925:
	/* 0x925: shr    edx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_928:
	/* 0x928: add    edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_92a:
	/* 0x92a: mov    ecx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_92c:
	/* 0x92c: shr    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_92f:
	/* 0x92f: add    ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_931:
	/* 0x931: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_933:
	/* 0x933: mov    WORD PTR [rax+0x18],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_937:
	/* 0x937: mov    eax,0x45 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 69ULL);
x86_l_93c:
	/* 0x93c: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_941:
	/* 0x941: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_944:
	/* 0x944: mov    edx,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 64ULL);
x86_l_949:
	/* 0x949: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_94b:
	/* 0x94b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_94d:
	/* 0x94d: mov    r14d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_32);
x86_l_950:
	/* 0x950: mov    ebp,0xffffff57 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967127ULL);
x86_l_955:
	/* 0x955: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_958:
	/* 0x958: je     963 <tail_nodeport_rev_dnat_ipv4+0x963> */
	X86_SIM_X86_JCC(X86_CC_E, 0x958, 0x963, x86_l_963);
x86_l_95a:
	/* 0x95a: test   r14d,r14d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_32);
x86_l_95d:
	/* 0x95d: jne    a3 <tail_nodeport_rev_dnat_ipv4+0xa3> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x95d, 0xa3, x86_l_a3);
x86_l_963:
	/* 0x963: mov    r15d,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_968:
	/* 0x968: mov    DWORD PTR [rsp+0x8],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_96d:
	/* 0x96d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_972:
	/* 0x972: mov    rdi,QWORD PTR [rip+0x154a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_devices)));
x86_l_979:
	/* 0x979: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_97e:
	/* 0x97e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_980:
	/* 0x980: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_983:
	/* 0x983: je     98f <tail_nodeport_rev_dnat_ipv4+0x98f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x983, 0x98f, x86_l_98f);
x86_l_985:
	/* 0x985: test   BYTE PTR [rax+0x8],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_989:
	/* 0x989: jne    b3d <tail_nodeport_rev_dnat_ipv4+0xb3d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x989, 0xb3d, x86_l_b3d);
x86_l_98f:
	/* 0x98f: test   r14d,r14d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_32);
x86_l_992:
	/* 0x992: je     aeb <tail_nodeport_rev_dnat_ipv4+0xaeb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x992, 0xaeb, x86_l_aeb);
x86_l_998:
	/* 0x998: mov    DWORD PTR [rsp+0x8],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_99d:
	/* 0x99d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_9a2:
	/* 0x9a2: mov    rdi,QWORD PTR [rip+0x154a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_devices)));
x86_l_9a9:
	/* 0x9a9: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9ae:
	/* 0x9ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9b0:
	/* 0x9b0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9b3:
	/* 0x9b3: lea    r12,[rip+0x154a] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 5450ULL);
x86_l_9ba:
	/* 0x9ba: cmovne r12,rax */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RAX, X86_WIDTH_64, X86_CC_NE);
x86_l_9be:
	/* 0x9be: mov    r14d,0x64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 100ULL);
x86_l_9c4:
	/* 0x9c4: cmp    BYTE PTR [rsp+0x48],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 309237645314ULL);
x86_l_9c9:
	/* 0x9c9: jne    a3 <tail_nodeport_rev_dnat_ipv4+0xa3> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x9c9, 0xa3, x86_l_a3);
x86_l_9cf:
	/* 0x9cf: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_9d4:
	/* 0x9d4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_9d9:
	/* 0x9d9: mov    rdi,QWORD PTR [rip+0x154a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_nodeport_neigh4)));
x86_l_9e0:
	/* 0x9e0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9e2:
	/* 0x9e2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9e5:
	/* 0x9e5: je     a3 <tail_nodeport_rev_dnat_ipv4+0xa3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9e5, 0xa3, x86_l_a3);
x86_l_9eb:
	/* 0x9eb: mov    rcx,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9ee:
	/* 0x9ee: mov    rdx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9f2:
	/* 0x9f2: lea    rsi,[rcx+0x6] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_9f6:
	/* 0x9f6: mov    ebp,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967155ULL);
x86_l_9fb:
	/* 0x9fb: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9fe:
	/* 0x9fe: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_a01:
	/* 0xa01: ja     a3 <tail_nodeport_rev_dnat_ipv4+0xa3> */
	X86_SIM_X86_JCC(X86_CC_A, 0xa01, 0xa3, x86_l_a3);
x86_l_a07:
	/* 0xa07: movzx  esi,WORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_a0b:
	/* 0xa0b: mov    WORD PTR [rcx+0x4],si */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RSI, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_a0f:
	/* 0xa0f: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a11:
	/* 0xa11: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a13:
	/* 0xa13: lea    rax,[rcx+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_a17:
	/* 0xa17: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_a1a:
	/* 0xa1a: ja     a3 <tail_nodeport_rev_dnat_ipv4+0xa3> */
	X86_SIM_X86_JCC(X86_CC_A, 0xa1a, 0xa3, x86_l_a3);
x86_l_a20:
	/* 0xa20: movzx  eax,WORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_a26:
	/* 0xa26: mov    WORD PTR [rcx+0xa],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 10ULL);
x86_l_a2a:
	/* 0xa2a: mov    eax,DWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a2e:
	/* 0xa2e: mov    DWORD PTR [rcx+0x6],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_a31:
	/* 0xa31: jmp    b3d <tail_nodeport_rev_dnat_ipv4+0xb3d> */
	X86_SIM_X86_JMP(0xa31, 0xb3d, x86_l_b3d);
x86_l_a36:
	/* 0xa36: movzx  eax,BYTE PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 64ULL);
x86_l_a3b:
	/* 0xa3b: add    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_a3e:
	/* 0xa3e: lea    r8,[rax+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_a42:
	/* 0xa42: add    r8,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_a46:
	/* 0xa46: mov    r15d,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967142ULL);
x86_l_a4c:
	/* 0xa4c: cmp    r8,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R8, X86_RCX, X86_WIDTH_64);
x86_l_a4f:
	/* 0xa4f: ja     ae3 <tail_nodeport_rev_dnat_ipv4+0xae3> */
	X86_SIM_X86_JCC(X86_CC_A, 0xa4f, 0xae3, x86_l_ae3);
x86_l_a55:
	/* 0xa55: add    rdi,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_a58:
	/* 0xa58: movzx  eax,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_a5b:
	/* 0xa5b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a5d:
	/* 0xa5d: setne  r8b */
	X86_SIM_L_EXEC_SETCC(X86_R8, X86_CC_NE);
x86_l_a61:
	/* 0xa61: or     r8b,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RSI, X86_WIDTH_8, X86_ALU_OR);
x86_l_a64:
	/* 0xa64: cmp    r8b,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_8, 1ULL);
x86_l_a68:
	/* 0xa68: jne    863 <tail_nodeport_rev_dnat_ipv4+0x863> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa68, 0x863, x86_l_863);
x86_l_a6e:
	/* 0xa6e: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_a70:
	/* 0xa70: add    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_a72:
	/* 0xa72: adc    edx,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_a75:
	/* 0xa75: movzx  eax,dx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_a78:
	/* 0xa78: shr    edx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_a7b:
	/* 0xa7b: add    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_a7d:
	/* 0xa7d: mov    eax,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_a7f:
	/* 0xa7f: shr    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_a82:
	/* 0xa82: add    eax,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_a84:
	/* 0xa84: cmp    ax,0xffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_16, 65535ULL);
x86_l_a88:
	/* 0xa88: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_a8a:
	/* 0xa8a: mov    ecx,0xffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 65535ULL);
x86_l_a8f:
	/* 0xa8f: cmovne ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_NE);
x86_l_a92:
	/* 0xa92: test   sil,sil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_8);
x86_l_a95:
	/* 0xa95: cmovne ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_NE);
x86_l_a98:
	/* 0xa98: mov    WORD PTR [rdi],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDI, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a9b:
	/* 0xa9b: mov    r12,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a9e:
	/* 0xa9e: mov    rcx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_aa2:
	/* 0xaa2: jmp    863 <tail_nodeport_rev_dnat_ipv4+0x863> */
	X86_SIM_X86_JMP(0xaa2, 0x863, x86_l_863);
x86_l_aa7:
	/* 0xaa7: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_aac:
	/* 0xaac: add    rax,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R12, X86_WIDTH_64, X86_ALU_ADD);
x86_l_aaf:
	/* 0xaaf: add    rax,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_ab3:
	/* 0xab3: mov    r15d,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967155ULL);
x86_l_ab9:
	/* 0xab9: cmp    rax,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_abc:
	/* 0xabc: ja     ae3 <tail_nodeport_rev_dnat_ipv4+0xae3> */
	X86_SIM_X86_JCC(X86_CC_A, 0xabc, 0xae3, x86_l_ae3);
x86_l_abe:
	/* 0xabe: mov    r11,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_ac3:
	/* 0xac3: lea    rax,[r12+r11*1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_R11, 0), 0ULL);
x86_l_ac7:
	/* 0xac7: mov    WORD PTR [r12+r11*1],r9w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R9, X86_WIDTH_16, X86_MEM_AUX(X86_R11, 0), 0ULL);
x86_l_acc:
	/* 0xacc: lea    r11,[rdi+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_R11, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_ad0:
	/* 0xad0: add    r11,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_ad4:
	/* 0xad4: mov    r15d,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967142ULL);
x86_l_ada:
	/* 0xada: cmp    r11,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R11, X86_RCX, X86_WIDTH_64);
x86_l_add:
	/* 0xadd: jbe    b99 <tail_nodeport_rev_dnat_ipv4+0xb99> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xadd, 0xb99, x86_l_b99);
x86_l_ae3:
	/* 0xae3: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ae6:
	/* 0xae6: jmp    ae <tail_nodeport_rev_dnat_ipv4+0xae> */
	X86_SIM_X86_JMP(0xae6, 0xae, x86_l_ae);
x86_l_aeb:
	/* 0xaeb: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_aee:
	/* 0xaee: lea    rcx,[rax+0x6] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_af2:
	/* 0xaf2: mov    ebp,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967155ULL);
x86_l_af7:
	/* 0xaf7: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_afa:
	/* 0xafa: cmp    rcx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_afe:
	/* 0xafe: ja     a3 <tail_nodeport_rev_dnat_ipv4+0xa3> */
	X86_SIM_X86_JCC(X86_CC_A, 0xafe, 0xa3, x86_l_a3);
x86_l_b04:
	/* 0xb04: movzx  ecx,WORD PTR [rsp+0x86] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 134ULL);
x86_l_b0c:
	/* 0xb0c: mov    WORD PTR [rax+0x4],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_b10:
	/* 0xb10: mov    ecx,DWORD PTR [rsp+0x82] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 130ULL);
x86_l_b17:
	/* 0xb17: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b19:
	/* 0xb19: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b1c:
	/* 0xb1c: lea    rcx,[rax+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_b20:
	/* 0xb20: cmp    rcx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_b24:
	/* 0xb24: ja     a3 <tail_nodeport_rev_dnat_ipv4+0xa3> */
	X86_SIM_X86_JCC(X86_CC_A, 0xb24, 0xa3, x86_l_a3);
x86_l_b2a:
	/* 0xb2a: movzx  ecx,WORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 128ULL);
x86_l_b32:
	/* 0xb32: mov    WORD PTR [rax+0xa],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 10ULL);
x86_l_b36:
	/* 0xb36: mov    ecx,DWORD PTR [rsp+0x7c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_b3a:
	/* 0xb3a: mov    DWORD PTR [rax+0x6],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_b3d:
	/* 0xb3d: cmp    DWORD PTR [rbx+0xc],r15d */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RBX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_b41:
	/* 0xb41: jne    b4e <tail_nodeport_rev_dnat_ipv4+0xb4e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb41, 0xb4e, x86_l_b4e);
x86_l_b43:
	/* 0xb43: mov    r15d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 3ULL);
x86_l_b49:
	/* 0xb49: jmp    314 <tail_nodeport_rev_dnat_ipv4+0x314> */
	X86_SIM_X86_JMP(0xb49, 0x314, x86_l_314);
x86_l_b4e:
	/* 0xb4e: mov    eax,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 23ULL);
x86_l_b53:
	/* 0xb53: mov    edi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_32);
x86_l_b56:
	/* 0xb56: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b58:
	/* 0xb58: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b5a:
	/* 0xb5a: mov    r15d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_32);
x86_l_b5d:
	/* 0xb5d: jmp    e02 <tail_nodeport_rev_dnat_ipv4+0xe02> */
	X86_SIM_X86_JMP(0xb5d, 0xe02, x86_l_e02);
x86_l_b62:
	/* 0xb62: mov    rbp,r10 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R10, X86_WIDTH_64);
x86_l_b65:
	/* 0xb65: mov    r13,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R11, X86_WIDTH_64);
x86_l_b68:
	/* 0xb68: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b6d:
	/* 0xb6d: mov    rdi,QWORD PTR [rip+0x154a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv4_frag_datagrams)));
x86_l_b74:
	/* 0xb74: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_b79:
	/* 0xb79: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b7b:
	/* 0xb7b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b7e:
	/* 0xb7e: je     c5e <tail_nodeport_rev_dnat_ipv4+0xc5e> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb7e, 0xc5e, x86_l_c5e);
x86_l_b84:
	/* 0xb84: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b86:
	/* 0xb86: mov    DWORD PTR [rsp+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b8a:
	/* 0xb8a: jmp    cea <tail_nodeport_rev_dnat_ipv4+0xcea> */
	X86_SIM_X86_JMP(0xb8a, 0xcea, x86_l_cea);
x86_l_b8f:
	/* 0xb8f: mov    ebp,0xffffff63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967139ULL);
x86_l_b94:
	/* 0xb94: jmp    a3 <tail_nodeport_rev_dnat_ipv4+0xa3> */
	X86_SIM_X86_JMP(0xb94, 0xa3, x86_l_a3);
x86_l_b99:
	/* 0xb99: add    rax,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_b9c:
	/* 0xb9c: test   sil,sil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_8);
x86_l_b9f:
	/* 0xb9f: jne    bab <tail_nodeport_rev_dnat_ipv4+0xbab> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb9f, 0xbab, x86_l_bab);
x86_l_ba1:
	/* 0xba1: cmp    WORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ba5:
	/* 0xba5: je     85a <tail_nodeport_rev_dnat_ipv4+0x85a> */
	X86_SIM_X86_JCC(X86_CC_E, 0xba5, 0x85a, x86_l_85a);
x86_l_bab:
	/* 0xbab: test   r10d,r10d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R10, X86_R10, X86_WIDTH_32);
x86_l_bae:
	/* 0xbae: je     c73 <tail_nodeport_rev_dnat_ipv4+0xc73> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbae, 0xc73, x86_l_c73);
x86_l_bb4:
	/* 0xbb4: not    r10d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_bb7:
	/* 0xbb7: add    r10d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R9, X86_WIDTH_32, X86_ALU_ADD);
x86_l_bba:
	/* 0xbba: adc    r10d,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_bbe:
	/* 0xbbe: movzx  r11d,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_bc2:
	/* 0xbc2: not    r11d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_bc5:
	/* 0xbc5: add    r11d,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_R10, X86_WIDTH_32, X86_ALU_ADD);
x86_l_bc8:
	/* 0xbc8: jmp    c7d <tail_nodeport_rev_dnat_ipv4+0xc7d> */
	X86_SIM_X86_JMP(0xbc8, 0xc7d, x86_l_c7d);
x86_l_bcd:
	/* 0xbcd: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_bd2:
	/* 0xbd2: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_bd7:
	/* 0xbd7: mov    r13,r11 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R11, X86_WIDTH_64);
x86_l_bda:
	/* 0xbda: mov    rdi,QWORD PTR [rip+0x154a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv4_frag_datagrams)));
x86_l_be1:
	/* 0xbe1: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_be6:
	/* 0xbe6: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_be8:
	/* 0xbe8: mov    rbp,r10 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R10, X86_WIDTH_64);
x86_l_beb:
	/* 0xbeb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bed:
	/* 0xbed: mov    r8,QWORD PTR [rip+0x154a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R8, (void *)(long)(((__u64)(long)&__config_enable_ipv4_fragments)));
x86_l_bf4:
	/* 0xbf4: mov    r10,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R10, X86_RBP, X86_WIDTH_64);
x86_l_bf7:
	/* 0xbf7: movabs r9,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_64, 2199023255552ULL);
x86_l_c01:
	/* 0xc01: mov    r11,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R13, X86_WIDTH_64);
x86_l_c04:
	/* 0xc04: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c06:
	/* 0xc06: je     29d <tail_nodeport_rev_dnat_ipv4+0x29d> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc06, 0x29d, x86_l_29d);
x86_l_c0c:
	/* 0xc0c: mov    r14,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c10:
	/* 0xc10: sub    r14,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 0ULL);
x86_l_c13:
	/* 0xc13: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_c1c:
	/* 0xc1c: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_c25:
	/* 0xc25: movabs rax,0x6b0085020a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 459570217482ULL);
x86_l_c2f:
	/* 0xc2f: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_c37:
	/* 0xc37: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c3c:
	/* 0xc3c: mov    rdi,QWORD PTR [rip+0x154a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_c43:
	/* 0xc43: lea    rsi,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_c4b:
	/* 0xc4b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c4d:
	/* 0xc4d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c50:
	/* 0xc50: je     cbf <tail_nodeport_rev_dnat_ipv4+0xcbf> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc50, 0xcbf, x86_l_cbf);
x86_l_c52:
	/* 0xc52: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_c55:
	/* 0xc55: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_c59:
	/* 0xc59: jmp    cea <tail_nodeport_rev_dnat_ipv4+0xcea> */
	X86_SIM_X86_JMP(0xc59, 0xcea, x86_l_cea);
x86_l_c5e:
	/* 0xc5e: mov    ebp,0xffffff51 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967121ULL);
x86_l_c63:
	/* 0xc63: jmp    a3 <tail_nodeport_rev_dnat_ipv4+0xa3> */
	X86_SIM_X86_JMP(0xc63, 0xa3, x86_l_a3);
x86_l_c68:
	/* 0xc68: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_c6e:
	/* 0xc6e: jmp    472 <tail_nodeport_rev_dnat_ipv4+0x472> */
	X86_SIM_X86_JMP(0xc6e, 0x472, x86_l_472);
x86_l_c73:
	/* 0xc73: movzx  r11d,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_c77:
	/* 0xc77: not    r11d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R11, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_c7a:
	/* 0xc7a: add    r11d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_R9, X86_WIDTH_32, X86_ALU_ADD);
x86_l_c7d:
	/* 0xc7d: setb   r9b */
	X86_SIM_L_EXEC_SETCC(X86_R9, X86_CC_B);
x86_l_c81:
	/* 0xc81: movzx  r9d,r9b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R9, X86_R9, X86_WIDTH_32, X86_WIDTH_8);
x86_l_c85:
	/* 0xc85: add    r9d,r11d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R11, X86_WIDTH_32, X86_ALU_ADD);
x86_l_c88:
	/* 0xc88: movzx  r10d,r9w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R10, X86_R9, X86_WIDTH_32, X86_WIDTH_16);
x86_l_c8c:
	/* 0xc8c: shr    r9d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_c90:
	/* 0xc90: add    r9d,r10d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R10, X86_WIDTH_32, X86_ALU_ADD);
x86_l_c93:
	/* 0xc93: mov    r10d,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_R10, X86_R9, X86_WIDTH_32);
x86_l_c96:
	/* 0xc96: shr    r10d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_c9a:
	/* 0xc9a: add    r10d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R10, X86_R9, X86_WIDTH_32, X86_ALU_ADD);
x86_l_c9d:
	/* 0xc9d: cmp    r10w,0xffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R10, X86_WIDTH_16, 65535ULL);
x86_l_ca2:
	/* 0xca2: not    r10d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_ca5:
	/* 0xca5: mov    r9d,0xffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 65535ULL);
x86_l_cab:
	/* 0xcab: cmovne r9d,r10d */
	X86_SIM_L_EXEC_CMOV(X86_R9, X86_R10, X86_WIDTH_32, X86_CC_NE);
x86_l_caf:
	/* 0xcaf: test   sil,sil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_8);
x86_l_cb2:
	/* 0xcb2: cmovne r9d,r10d */
	X86_SIM_L_EXEC_CMOV(X86_R9, X86_R10, X86_WIDTH_32, X86_CC_NE);
x86_l_cb6:
	/* 0xcb6: mov    WORD PTR [rax],r9w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R9, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cba:
	/* 0xcba: jmp    85a <tail_nodeport_rev_dnat_ipv4+0x85a> */
	X86_SIM_X86_JMP(0xcba, 0x85a, x86_l_85a);
x86_l_cbf:
	/* 0xcbf: mov    QWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_cc8:
	/* 0xcc8: mov    QWORD PTR [rsp+0x10],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ccd:
	/* 0xccd: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_cd2:
	/* 0xcd2: mov    rdi,QWORD PTR [rip+0x154a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_cd9:
	/* 0xcd9: lea    rsi,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_ce1:
	/* 0xce1: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ce6:
	/* 0xce6: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ce8:
	/* 0xce8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cea:
	/* 0xcea: mov    r11,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R11, X86_R13, X86_WIDTH_64);
x86_l_ced:
	/* 0xced: movabs r9,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_64, 2199023255552ULL);
x86_l_cf7:
	/* 0xcf7: mov    r10,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R10, X86_RBP, X86_WIDTH_64);
x86_l_cfa:
	/* 0xcfa: mov    r8,QWORD PTR [rip+0x154a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R8, (void *)(long)(((__u64)(long)&__config_enable_ipv4_fragments)));
x86_l_d01:
	/* 0xd01: movzx  r13d,BYTE PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 44ULL);
x86_l_d07:
	/* 0xd07: cmp    r13b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_8, 6ULL);
x86_l_d0b:
	/* 0xd0b: je     2ad <tail_nodeport_rev_dnat_ipv4+0x2ad> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd0b, 0x2ad, x86_l_2ad);
x86_l_d11:
	/* 0xd11: jmp    35c <tail_nodeport_rev_dnat_ipv4+0x35c> */
	X86_SIM_X86_JMP(0xd11, 0x35c, x86_l_35c);
x86_l_d16:
	/* 0xd16: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d18:
	/* 0xd18: jmp    8a0 <tail_nodeport_rev_dnat_ipv4+0x8a0> */
	X86_SIM_X86_JMP(0xd18, 0x8a0, x86_l_8a0);
x86_l_d1d:
	/* 0xd1d: mov    r12d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 60ULL);
x86_l_d23:
	/* 0xd23: cmp    r13b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_8, 6ULL);
x86_l_d27:
	/* 0xd27: jne    d66 <tail_nodeport_rev_dnat_ipv4+0xd66> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xd27, 0xd66, x86_l_d66);
x86_l_d29:
	/* 0xd29: mov    eax,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_d2b:
	/* 0xd2b: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_d2d:
	/* 0xd2d: shr    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_d30:
	/* 0xd30: and    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_d33:
	/* 0xd33: or     ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_OR);
x86_l_d35:
	/* 0xd35: mov    WORD PTR [r14+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_d3a:
	/* 0xd3a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_d3c:
	/* 0xd3c: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_d41:
	/* 0xd41: mov    r12d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 21600ULL);
x86_l_d47:
	/* 0xd47: cmove  r12d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_d4b:
	/* 0xd4b: mov    rax,QWORD PTR [rip+0x154a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_d52:
	/* 0xd52: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d55:
	/* 0xd55: je     d66 <tail_nodeport_rev_dnat_ipv4+0xd66> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd55, 0xd66, x86_l_d66);
x86_l_d57:
	/* 0xd57: mov    rax,QWORD PTR [rip+0x154a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_d5e:
	/* 0xd5e: imul   r12d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_d62:
	/* 0xd62: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_d66:
	/* 0xd66: movzx  ebp,dx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RDX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_d69:
	/* 0xd69: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_d6c:
	/* 0xd6c: mov    rax,QWORD PTR [rip+0x154a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_d73:
	/* 0xd73: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d76:
	/* 0xd76: je     d87 <tail_nodeport_rev_dnat_ipv4+0xd87> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd76, 0xd87, x86_l_d87);
x86_l_d78:
	/* 0xd78: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_d7d:
	/* 0xd7d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d7f:
	/* 0xd7f: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_d81:
	/* 0xd81: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_d85:
	/* 0xd85: jmp    daa <tail_nodeport_rev_dnat_ipv4+0xdaa> */
	X86_SIM_X86_JMP(0xd85, 0xdaa, x86_l_daa);
x86_l_d87:
	/* 0xd87: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_d8c:
	/* 0xd8c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d8e:
	/* 0xd8e: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_d90:
	/* 0xd90: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_d94:
	/* 0xd94: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_d9e:
	/* 0xd9e: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_da1:
	/* 0xda1: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_da6:
	/* 0xda6: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_daa:
	/* 0xdaa: add    r12d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_dad:
	/* 0xdad: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_db0:
	/* 0xdb0: mov    DWORD PTR [r14+0x20],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_db4:
	/* 0xdb4: movzx  ecx,BYTE PTR [r14+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_db9:
	/* 0xdb9: mov    edx,DWORD PTR [r14+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_dbd:
	/* 0xdbd: and    bpl,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_dc1:
	/* 0xdc1: mov    rsi,QWORD PTR [rip+0x154a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_dc8:
	/* 0xdc8: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_dcb:
	/* 0xdcb: je     dde <tail_nodeport_rev_dnat_ipv4+0xdde> */
	X86_SIM_X86_JCC(X86_CC_E, 0xdcb, 0xdde, x86_l_dde);
x86_l_dcd:
	/* 0xdcd: mov    rsi,QWORD PTR [rip+0x154a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_dd4:
	/* 0xdd4: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_dd6:
	/* 0xdd6: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_dd9:
	/* 0xdd9: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_ddc:
	/* 0xddc: jmp    de3 <tail_nodeport_rev_dnat_ipv4+0xde3> */
	X86_SIM_X86_JMP(0xddc, 0xde3, x86_l_de3);
x86_l_dde:
	/* 0xdde: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_de3:
	/* 0xde3: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_de5:
	/* 0xde5: or     bpl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_de8:
	/* 0xde8: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_dea:
	/* 0xdea: jb     df1 <tail_nodeport_rev_dnat_ipv4+0xdf1> */
	X86_SIM_X86_JCC(X86_CC_B, 0xdea, 0xdf1, x86_l_df1);
x86_l_dec:
	/* 0xdec: cmp    cl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_8);
x86_l_def:
	/* 0xdef: je     e02 <tail_nodeport_rev_dnat_ipv4+0xe02> */
	X86_SIM_X86_JCC(X86_CC_E, 0xdef, 0xe02, x86_l_e02);
x86_l_df1:
	/* 0xdf1: mov    BYTE PTR [r14+0x2b],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_df5:
	/* 0xdf5: mov    DWORD PTR [r14+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_df9:
	/* 0xdf9: mov    rax,QWORD PTR [rip+0x154a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_e00:
	/* 0xe00: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e02:
	/* 0xe02: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e05:
	/* 0xe05: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_e08:
	/* 0xe08: js     ae <tail_nodeport_rev_dnat_ipv4+0xae> */
	X86_SIM_X86_JCC(X86_CC_S, 0xe08, 0xae, x86_l_ae);
x86_l_e0e:
	/* 0xe0e: cmp    r15d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 1ULL);
x86_l_e12:
	/* 0xe12: je     ae <tail_nodeport_rev_dnat_ipv4+0xae> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe12, 0xae, x86_l_ae);
x86_l_e18:
	/* 0xe18: cmp    r15d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 2ULL);
x86_l_e1c:
	/* 0xe1c: jne    314 <tail_nodeport_rev_dnat_ipv4+0x314> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe1c, 0x314, x86_l_314);
x86_l_e22:
	/* 0xe22: mov    DWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_e2a:
	/* 0xe2a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e2f:
	/* 0xe2f: mov    rdi,QWORD PTR [rip+0x154a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_e36:
	/* 0xe36: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_e3b:
	/* 0xe3b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e3d:
	/* 0xe3d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e40:
	/* 0xe40: je     e49 <tail_nodeport_rev_dnat_ipv4+0xe49> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe40, 0xe49, x86_l_e49);
x86_l_e42:
	/* 0xe42: mov    DWORD PTR [rax+0x14],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345921ULL);
x86_l_e49:
	/* 0xe49: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_e4e:
	/* 0xe4e: mov    rsi,QWORD PTR [rip+0x154a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_e55:
	/* 0xe55: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_e58:
	/* 0xe58: mov    edx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_e5d:
	/* 0xe5d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e5f:
	/* 0xe5f: mov    r15d,0xffffff74 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 4294967156ULL);
x86_l_e65:
	/* 0xe65: mov    r14d,0x700 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 1792ULL);
x86_l_e6b:
	/* 0xe6b: jmp    ae <tail_nodeport_rev_dnat_ipv4+0xae> */
	X86_SIM_X86_JMP(0xe6b, 0xae, x86_l_ae);
x86_l_e70:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
