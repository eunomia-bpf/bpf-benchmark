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
int cilium_bpf_wireguard_tail_nodeport_rev_dnat_ipv4_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0xb8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 184ULL);
x86_l_a:
	/* 0xa: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: mov    rax,QWORD PTR [rip+0x1a37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_14:
	/* 0x14: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16:
	/* 0x16: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_1f:
	/* 0x1f: mov    DWORD PTR [rsp+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_2a:
	/* 0x2a: mov    QWORD PTR [rsp+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_36:
	/* 0x36: mov    QWORD PTR [rsp+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_42:
	/* 0x42: mov    QWORD PTR [rsp+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_4e:
	/* 0x4e: mov    QWORD PTR [rsp+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_5a:
	/* 0x5a: mov    QWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_66:
	/* 0x66: mov    QWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_72:
	/* 0x72: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_7b:
	/* 0x7b: mov    BYTE PTR [rsp+0x70],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 481036337154ULL);
x86_l_80:
	/* 0x80: mov    rax,QWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_84:
	/* 0x84: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_86:
	/* 0x86: mov    ecx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 0ULL);
x86_l_8b:
	/* 0x8b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8e:
	/* 0x8e: je     96 <tail_nodeport_rev_dnat_ipv4+0x96> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8e, 0x96, x86_l_96);
x86_l_90:
	/* 0x90: mov    ecx,DWORD PTR [rax+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_96:
	/* 0x96: mov    DWORD PTR [rsp+0x78],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_9a:
	/* 0x9a: mov    QWORD PTR [rsp+0x4e],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 335007449088ULL);
x86_l_a3:
	/* 0xa3: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_ac:
	/* 0xac: mov    ecx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_af:
	/* 0xaf: sub    ecx,DWORD PTR [rbx+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_b2:
	/* 0xb2: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_b7:
	/* 0xb7: cmp    ecx,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 20ULL);
x86_l_ba:
	/* 0xba: jb     cde <tail_nodeport_rev_dnat_ipv4+0xcde> */
	X86_SIM_X86_JCC(X86_CC_B, 0xba, 0xcde, x86_l_cde);
x86_l_c0:
	/* 0xc0: movabs r8,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_64, 2199023255552ULL);
x86_l_ca:
	/* 0xca: movabs r12,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 1099511627776ULL);
x86_l_d4:
	/* 0xd4: mov    rdx,QWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_db:
	/* 0xdb: movzx  ecx,WORD PTR [rdx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_df:
	/* 0xdf: movzx  eax,BYTE PTR [rdx+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_e3:
	/* 0xe3: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_e6:
	/* 0xe6: shl    rsi,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_ea:
	/* 0xea: or     rsi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_ed:
	/* 0xed: movzx  ecx,WORD PTR [rdx+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_f1:
	/* 0xf1: lea    rdi,[rsi+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_f5:
	/* 0xf5: test   ecx,0xff3f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_32, 65343ULL);
x86_l_fb:
	/* 0xfb: cmove  rdi,rsi */
	X86_SIM_L_EXEC_CMOV(X86_RDI, X86_RSI, X86_WIDTH_64, X86_CC_E);
x86_l_ff:
	/* 0xff: lea    r13,[rdi+r8*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_103:
	/* 0x103: test   ecx,0xff1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_32, 65311ULL);
x86_l_109:
	/* 0x109: cmove  r13,rdi */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RDI, X86_WIDTH_64, X86_CC_E);
x86_l_10d:
	/* 0x10d: mov    r14d,DWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_110:
	/* 0x110: mov    BYTE PTR [rsp+0x54],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_114:
	/* 0x114: mov    ecx,DWORD PTR [rdx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_117:
	/* 0x117: mov    DWORD PTR [rsp+0x48],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_11b:
	/* 0x11b: mov    edx,DWORD PTR [rdx+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_11e:
	/* 0x11e: mov    DWORD PTR [rsp+0x4c],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_122:
	/* 0x122: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_125:
	/* 0x125: je     130 <tail_nodeport_rev_dnat_ipv4+0x130> */
	X86_SIM_X86_JCC(X86_CC_E, 0x125, 0x130, x86_l_130);
x86_l_127:
	/* 0x127: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_12a:
	/* 0x12a: jne    cb7 <tail_nodeport_rev_dnat_ipv4+0xcb7> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x12a, 0xcb7, x86_l_cb7);
x86_l_130:
	/* 0x130: shl    r14d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHL, 2ULL);
x86_l_134:
	/* 0x134: lea    r15,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_139:
	/* 0x139: mov    rax,QWORD PTR [rip+0x1a37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_ipv4_fragments)));
x86_l_140:
	/* 0x140: and    r14d,0x3c */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 60ULL);
x86_l_144:
	/* 0x144: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_147:
	/* 0x147: je     20a <tail_nodeport_rev_dnat_ipv4+0x20a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x147, 0x20a, x86_l_20a);
x86_l_14d:
	/* 0x14d: mov    DWORD PTR [rsp+0x38],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_151:
	/* 0x151: mov    DWORD PTR [rsp+0x3c],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_155:
	/* 0x155: mov    WORD PTR [rsp+0x40],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_15b:
	/* 0x15b: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_15e:
	/* 0x15e: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_162:
	/* 0x162: mov    BYTE PTR [rsp+0x42],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 66ULL);
x86_l_166:
	/* 0x166: mov    BYTE PTR [rsp+0x43],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 287762808832ULL);
x86_l_16b:
	/* 0x16b: movabs rax,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2199023255552ULL);
x86_l_175:
	/* 0x175: test   r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_178:
	/* 0x178: jne    a98 <tail_nodeport_rev_dnat_ipv4+0xa98> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x178, 0xa98, x86_l_a98);
x86_l_17e:
	/* 0x17e: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_183:
	/* 0x183: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_186:
	/* 0x186: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_189:
	/* 0x189: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_18c:
	/* 0x18c: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_191:
	/* 0x191: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_193:
	/* 0x193: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_195:
	/* 0x195: js     24a <tail_nodeport_rev_dnat_ipv4+0x24a> */
	X86_SIM_X86_JCC(X86_CC_S, 0x195, 0x24a, x86_l_24a);
x86_l_19b:
	/* 0x19b: test   r13,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R12, X86_WIDTH_64);
x86_l_19e:
	/* 0x19e: je     236 <tail_nodeport_rev_dnat_ipv4+0x236> */
	X86_SIM_X86_JCC(X86_CC_E, 0x19e, 0x236, x86_l_236);
x86_l_1a4:
	/* 0x1a4: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1a9:
	/* 0x1a9: mov    rdi,QWORD PTR [rip+0x1a37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv4_frag_datagrams)));
x86_l_1b0:
	/* 0x1b0: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1b5:
	/* 0x1b5: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1b8:
	/* 0x1b8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ba:
	/* 0x1ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bc:
	/* 0x1bc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1be:
	/* 0x1be: je     236 <tail_nodeport_rev_dnat_ipv4+0x236> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1be, 0x236, x86_l_236);
x86_l_1c0:
	/* 0x1c0: mov    r15d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1c4:
	/* 0x1c4: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1cd:
	/* 0x1cd: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1d6:
	/* 0x1d6: movabs rax,0x6b0085020a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 459570217482ULL);
x86_l_1e0:
	/* 0x1e0: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1e5:
	/* 0x1e5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1ea:
	/* 0x1ea: mov    rdi,QWORD PTR [rip+0x1a37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1f1:
	/* 0x1f1: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1f6:
	/* 0x1f6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f8:
	/* 0x1f8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1fb:
	/* 0x1fb: je     baa <tail_nodeport_rev_dnat_ipv4+0xbaa> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1fb, 0xbaa, x86_l_baa);
x86_l_201:
	/* 0x201: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_204:
	/* 0x204: add    QWORD PTR [rax+0x8],r15 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_208:
	/* 0x208: jmp    236 <tail_nodeport_rev_dnat_ipv4+0x236> */
	X86_SIM_X86_JMP(0x208, 0x236, x86_l_236);
x86_l_20a:
	/* 0x20a: movabs rax,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2199023255552ULL);
x86_l_214:
	/* 0x214: test   r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_217:
	/* 0x217: jne    b78 <tail_nodeport_rev_dnat_ipv4+0xb78> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x217, 0xb78, x86_l_b78);
x86_l_21d:
	/* 0x21d: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_222:
	/* 0x222: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_225:
	/* 0x225: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_228:
	/* 0x228: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_22b:
	/* 0x22b: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_230:
	/* 0x230: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_232:
	/* 0x232: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_234:
	/* 0x234: js     24a <tail_nodeport_rev_dnat_ipv4+0x24a> */
	X86_SIM_X86_JCC(X86_CC_S, 0x234, 0x24a, x86_l_24a);
x86_l_236:
	/* 0x236: movzx  ebp,BYTE PTR [rsp+0x54] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 84ULL);
x86_l_23b:
	/* 0x23b: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_23f:
	/* 0x23f: jne    254 <tail_nodeport_rev_dnat_ipv4+0x254> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x23f, 0x254, x86_l_254);
x86_l_241:
	/* 0x241: mov    r15,QWORD PTR [rip+0x1a37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&cilium_ct4_global)));
x86_l_248:
	/* 0x248: jmp    25b <tail_nodeport_rev_dnat_ipv4+0x25b> */
	X86_SIM_X86_JMP(0x248, 0x25b, x86_l_25b);
x86_l_24a:
	/* 0x24a: mov    eax,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967161ULL);
x86_l_24f:
	/* 0x24f: jmp    cde <tail_nodeport_rev_dnat_ipv4+0xcde> */
	X86_SIM_X86_JMP(0x24f, 0xcde, x86_l_cde);
x86_l_254:
	/* 0x254: mov    r15,QWORD PTR [rip+0x1a37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&cilium_ct_any4_global)));
x86_l_25b:
	/* 0x25b: mov    rax,QWORD PTR [rip+0x1a37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_ipv4_fragments)));
x86_l_262:
	/* 0x262: mov    BYTE PTR [rsp+0x55],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 365072220160ULL);
x86_l_267:
	/* 0x267: mov    DWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_26f:
	/* 0x26f: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_272:
	/* 0x272: je     2bd <tail_nodeport_rev_dnat_ipv4+0x2bd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x272, 0x2bd, x86_l_2bd);
x86_l_274:
	/* 0x274: and    r12,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_277:
	/* 0x277: je     2bd <tail_nodeport_rev_dnat_ipv4+0x2bd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x277, 0x2bd, x86_l_2bd);
x86_l_279:
	/* 0x279: mov    r12d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_27d:
	/* 0x27d: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_286:
	/* 0x286: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_28f:
	/* 0x28f: movabs rax,0x6c03a50109 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 463917613321ULL);
x86_l_299:
	/* 0x299: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_29e:
	/* 0x29e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a3:
	/* 0x2a3: mov    rdi,QWORD PTR [rip+0x1a37] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_2aa:
	/* 0x2aa: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2af:
	/* 0x2af: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b1:
	/* 0x2b1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b4:
	/* 0x2b4: je     327 <tail_nodeport_rev_dnat_ipv4+0x327> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2b4, 0x327, x86_l_327);
x86_l_2b6:
	/* 0x2b6: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2b9:
	/* 0x2b9: add    QWORD PTR [rax+0x8],r12 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_2bd:
	/* 0x2bd: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_2c1:
	/* 0x2c1: jne    359 <tail_nodeport_rev_dnat_ipv4+0x359> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2c1, 0x359, x86_l_359);
x86_l_2c7:
	/* 0x2c7: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_2ca:
	/* 0x2ca: movabs rcx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2199023255552ULL);
x86_l_2d4:
	/* 0x2d4: and    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_2d7:
	/* 0x2d7: jne    359 <tail_nodeport_rev_dnat_ipv4+0x359> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2d7, 0x359, x86_l_359);
x86_l_2dd:
	/* 0x2dd: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_2e2:
	/* 0x2e2: lea    esi,[r14+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2e6:
	/* 0x2e6: lea    rdx,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2eb:
	/* 0x2eb: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2ee:
	/* 0x2ee: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2f3:
	/* 0x2f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f5:
	/* 0x2f5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2f7:
	/* 0x2f7: js     cb7 <tail_nodeport_rev_dnat_ipv4+0xcb7> */
	X86_SIM_X86_JCC(X86_CC_S, 0x2f7, 0xcb7, x86_l_cb7);
x86_l_2fd:
	/* 0x2fd: mov    ecx,DWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_301:
	/* 0x301: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_303:
	/* 0x303: and    eax,0x1200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4608ULL);
x86_l_308:
	/* 0x308: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_30b:
	/* 0x30b: cmp    eax,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 512ULL);
x86_l_310:
	/* 0x310: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_313:
	/* 0x313: mov    DWORD PTR [rsp],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_316:
	/* 0x316: test   ecx,0x500 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_32, 1280ULL);
x86_l_31c:
	/* 0x31c: jne    b9f <tail_nodeport_rev_dnat_ipv4+0xb9f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x31c, 0xb9f, x86_l_b9f);
x86_l_322:
	/* 0x322: mov    r12b,al */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_8);
x86_l_325:
	/* 0x325: jmp    363 <tail_nodeport_rev_dnat_ipv4+0x363> */
	X86_SIM_X86_JMP(0x325, 0x363, x86_l_363);
x86_l_327:
	/* 0x327: mov    QWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_330:
	/* 0x330: mov    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_335:
	/* 0x335: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_33a:
	/* 0x33a: mov    rdi,QWORD PTR [rip+0x1a33] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_341:
	/* 0x341: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_346:
	/* 0x346: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_34b:
	/* 0x34b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_34d:
	/* 0x34d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34f:
	/* 0x34f: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_353:
	/* 0x353: je     2c7 <tail_nodeport_rev_dnat_ipv4+0x2c7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x353, 0x2c7, x86_l_2c7);
x86_l_359:
	/* 0x359: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_35c:
	/* 0x35c: mov    eax,DWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_360:
	/* 0x360: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_363:
	/* 0x363: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_368:
	/* 0x368: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_36d:
	/* 0x36d: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_370:
	/* 0x370: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_372:
	/* 0x372: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_375:
	/* 0x375: je     cae <tail_nodeport_rev_dnat_ipv4+0xcae> */
	X86_SIM_X86_JCC(X86_CC_E, 0x375, 0xcae, x86_l_cae);
x86_l_37b:
	/* 0x37b: movzx  ecx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_37f:
	/* 0x37f: test   cl,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_382:
	/* 0x382: je     cae <tail_nodeport_rev_dnat_ipv4+0xcae> */
	X86_SIM_X86_JCC(X86_CC_E, 0x382, 0xcae, x86_l_cae);
x86_l_388:
	/* 0x388: cmp    WORD PTR [rax+0x26],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 163208757248ULL);
x86_l_38d:
	/* 0x38d: je     cae <tail_nodeport_rev_dnat_ipv4+0xcae> */
	X86_SIM_X86_JCC(X86_CC_E, 0x38d, 0xcae, x86_l_cae);
x86_l_393:
	/* 0x393: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_395:
	/* 0x395: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_397:
	/* 0x397: test   dl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_8, 3ULL);
x86_l_39a:
	/* 0x39a: mov    r8,QWORD PTR [rip+0x1a33] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R8, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_3a1:
	/* 0x3a1: je     4ad <tail_nodeport_rev_dnat_ipv4+0x4ad> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3a1, 0x4ad, x86_l_4ad);
x86_l_3a7:
	/* 0x3a7: mov    rsi,QWORD PTR [rip+0x1a33] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_3ae:
	/* 0x3ae: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3b1:
	/* 0x3b1: je     3c4 <tail_nodeport_rev_dnat_ipv4+0x3c4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3b1, 0x3c4, x86_l_3c4);
x86_l_3b3:
	/* 0x3b3: mov    rdx,QWORD PTR [rip+0x1a33] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_3ba:
	/* 0x3ba: imul   r15d,DWORD PTR [rdx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R15, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_3be:
	/* 0x3be: shr    r15d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_3c2:
	/* 0x3c2: jmp    3ca <tail_nodeport_rev_dnat_ipv4+0x3ca> */
	X86_SIM_X86_JMP(0x3c2, 0x3ca, x86_l_3ca);
x86_l_3c4:
	/* 0x3c4: mov    r15d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 60ULL);
x86_l_3ca:
	/* 0x3ca: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_3ce:
	/* 0x3ce: jne    407 <tail_nodeport_rev_dnat_ipv4+0x407> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3ce, 0x407, x86_l_407);
x86_l_3d0:
	/* 0x3d0: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
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
	/* 0x3f8: mov    rcx,QWORD PTR [rip+0x1a33] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_3ff:
	/* 0x3ff: imul   r15d,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_403:
	/* 0x403: shr    r15d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_407:
	/* 0x407: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_40c:
	/* 0x40c: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_40f:
	/* 0x40f: shr    eax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_412:
	/* 0x412: mov    DWORD PTR [rsp+0x6c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_416:
	/* 0x416: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_419:
	/* 0x419: je     42d <tail_nodeport_rev_dnat_ipv4+0x42d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x419, 0x42d, x86_l_42d);
x86_l_41b:
	/* 0x41b: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_420:
	/* 0x420: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_422:
	/* 0x422: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_424:
	/* 0x424: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_427:
	/* 0x427: shr    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_42b:
	/* 0x42b: jmp    450 <tail_nodeport_rev_dnat_ipv4+0x450> */
	X86_SIM_X86_JMP(0x42b, 0x450, x86_l_450);
x86_l_42d:
	/* 0x42d: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_432:
	/* 0x432: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_434:
	/* 0x434: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_436:
	/* 0x436: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_43a:
	/* 0x43a: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_444:
	/* 0x444: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_447:
	/* 0x447: mulx   rcx,rcx,rcx */
	X86_SIM_L_EXEC_MULX(X86_RCX, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_44c:
	/* 0x44c: shr    rcx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_450:
	/* 0x450: add    r15d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_453:
	/* 0x453: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
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
	/* 0x463: mov    r9d,DWORD PTR [rsp+0x6c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 108ULL);
x86_l_468:
	/* 0x468: and    r9b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_46c:
	/* 0x46c: mov    rdi,QWORD PTR [rip+0x1a33] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_473:
	/* 0x473: cmp    BYTE PTR [rdi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_476:
	/* 0x476: je     489 <tail_nodeport_rev_dnat_ipv4+0x489> */
	X86_SIM_X86_JCC(X86_CC_E, 0x476, 0x489, x86_l_489);
x86_l_478:
	/* 0x478: mov    rdi,QWORD PTR [rip+0x1a33] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_47f:
	/* 0x47f: mov    edi,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_481:
	/* 0x481: lea    edi,[rdi+rdi*4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_484:
	/* 0x484: shr    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_487:
	/* 0x487: jmp    48e <tail_nodeport_rev_dnat_ipv4+0x48e> */
	X86_SIM_X86_JMP(0x487, 0x48e, x86_l_48e);
x86_l_489:
	/* 0x489: mov    edi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 5ULL);
x86_l_48e:
	/* 0x48e: mov    r8,QWORD PTR [rip+0x1a33] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R8, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_495:
	/* 0x495: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_497:
	/* 0x497: or     r9b,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_49a:
	/* 0x49a: cmp    edi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RCX, X86_WIDTH_32);
x86_l_49c:
	/* 0x49c: jb     4a3 <tail_nodeport_rev_dnat_ipv4+0x4a3> */
	X86_SIM_X86_JCC(X86_CC_B, 0x49c, 0x4a3, x86_l_4a3);
x86_l_49e:
	/* 0x49e: cmp    dl,r9b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R9, X86_WIDTH_8);
x86_l_4a1:
	/* 0x4a1: je     4ad <tail_nodeport_rev_dnat_ipv4+0x4ad> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4a1, 0x4ad, x86_l_4ad);
x86_l_4a3:
	/* 0x4a3: mov    BYTE PTR [rax+0x2b],r9b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R9, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_4a7:
	/* 0x4a7: mov    DWORD PTR [rax+0x34],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_4aa:
	/* 0x4aa: mov    ecx,DWORD PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4ad:
	/* 0x4ad: mov    rcx,QWORD PTR [rip+0x1a33] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_4b4:
	/* 0x4b4: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4b7:
	/* 0x4b7: je     4c6 <tail_nodeport_rev_dnat_ipv4+0x4c6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4b7, 0x4c6, x86_l_4c6);
x86_l_4b9:
	/* 0x4b9: inc QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 16ULL);
x86_l_4be:
	/* 0x4be: mov    ecx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_4c1:
	/* 0x4c1: add QWORD PTR [rax+0x18],rcx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_4c6:
	/* 0x4c6: cmp    r12d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 2ULL);
x86_l_4ca:
	/* 0x4ca: je     51b <tail_nodeport_rev_dnat_ipv4+0x51b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4ca, 0x51b, x86_l_51b);
x86_l_4cc:
	/* 0x4cc: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_4d0:
	/* 0x4d0: jne    606 <tail_nodeport_rev_dnat_ipv4+0x606> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4d0, 0x606, x86_l_606);
x86_l_4d6:
	/* 0x4d6: movzx  ecx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_4da:
	/* 0x4da: test   cl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_4dd:
	/* 0x4dd: je     606 <tail_nodeport_rev_dnat_ipv4+0x606> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4dd, 0x606, x86_l_606);
x86_l_4e3:
	/* 0x4e3: mov    WORD PTR [rax+0x2a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 180388626432ULL);
x86_l_4e9:
	/* 0x4e9: and    ecx,0xffec */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 65516ULL);
x86_l_4ef:
	/* 0x4ef: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_4f2:
	/* 0x4f2: mov    WORD PTR [rax+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_4f6:
	/* 0x4f6: mov    r15,QWORD PTR [rip+0x1a33] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_4fd:
	/* 0x4fd: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_501:
	/* 0x501: je     bd7 <tail_nodeport_rev_dnat_ipv4+0xbd7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x501, 0xbd7, x86_l_bd7);
x86_l_507:
	/* 0x507: mov    rax,QWORD PTR [rip+0x1a33] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_50e:
	/* 0x50e: imul   r12d,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_512:
	/* 0x512: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_516:
	/* 0x516: jmp    bdd <tail_nodeport_rev_dnat_ipv4+0xbdd> */
	X86_SIM_X86_JMP(0x516, 0xbdd, x86_l_bdd);
x86_l_51b:
	/* 0x51b: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_51e:
	/* 0x51e: shr    ecx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_521:
	/* 0x521: and    ecx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2ULL);
x86_l_524:
	/* 0x524: or     cx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RAX, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 36ULL);
x86_l_528:
	/* 0x528: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_52a:
	/* 0x52a: or     edx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_OR, 1ULL);
x86_l_52d:
	/* 0x52d: mov    WORD PTR [rax+0x24],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_531:
	/* 0x531: mov    edx,DWORD PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_534:
	/* 0x534: test   cl,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_537:
	/* 0x537: je     606 <tail_nodeport_rev_dnat_ipv4+0x606> */
	X86_SIM_X86_JCC(X86_CC_E, 0x537, 0x606, x86_l_606);
x86_l_53d:
	/* 0x53d: mov    r15,QWORD PTR [rip+0x1a33] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_544:
	/* 0x544: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_548:
	/* 0x548: je     55d <tail_nodeport_rev_dnat_ipv4+0x55d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x548, 0x55d, x86_l_55d);
x86_l_54a:
	/* 0x54a: mov    rcx,QWORD PTR [rip+0x1a33] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_551:
	/* 0x551: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_553:
	/* 0x553: add    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_555:
	/* 0x555: lea    ebp,[rcx+rcx*4] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 0ULL);
x86_l_558:
	/* 0x558: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_55b:
	/* 0x55b: jmp    562 <tail_nodeport_rev_dnat_ipv4+0x562> */
	X86_SIM_X86_JMP(0x55b, 0x562, x86_l_562);
x86_l_55d:
	/* 0x55d: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_562:
	/* 0x562: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_565:
	/* 0x565: shr    DWORD PTR [rsp],0x8 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_32, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_SHR)), 8ULL);
x86_l_569:
	/* 0x569: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_56d:
	/* 0x56d: je     581 <tail_nodeport_rev_dnat_ipv4+0x581> */
	X86_SIM_X86_JCC(X86_CC_E, 0x56d, 0x581, x86_l_581);
x86_l_56f:
	/* 0x56f: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_574:
	/* 0x574: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_576:
	/* 0x576: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_578:
	/* 0x578: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_57b:
	/* 0x57b: shr    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_57f:
	/* 0x57f: jmp    5a4 <tail_nodeport_rev_dnat_ipv4+0x5a4> */
	X86_SIM_X86_JMP(0x57f, 0x5a4, x86_l_5a4);
x86_l_581:
	/* 0x581: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_586:
	/* 0x586: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_588:
	/* 0x588: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_58a:
	/* 0x58a: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_58e:
	/* 0x58e: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_598:
	/* 0x598: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_59b:
	/* 0x59b: mulx   rcx,rcx,rcx */
	X86_SIM_L_EXEC_MULX(X86_RCX, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_5a0:
	/* 0x5a0: shr    rcx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_5a4:
	/* 0x5a4: add    ebp,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_5a6:
	/* 0x5a6: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_5a9:
	/* 0x5a9: mov    DWORD PTR [r12+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5ae:
	/* 0x5ae: movzx  edx,BYTE PTR [r12+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_5b4:
	/* 0x5b4: mov    esi,DWORD PTR [r12+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_5b9:
	/* 0x5b9: mov    edi,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5bc:
	/* 0x5bc: and    dil,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_5c0:
	/* 0x5c0: mov    DWORD PTR [rsp],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5c3:
	/* 0x5c3: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5c7:
	/* 0x5c7: je     5da <tail_nodeport_rev_dnat_ipv4+0x5da> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5c7, 0x5da, x86_l_5da);
x86_l_5c9:
	/* 0x5c9: mov    rdi,QWORD PTR [rip+0x1a33] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_5d0:
	/* 0x5d0: mov    edi,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5d2:
	/* 0x5d2: lea    edi,[rdi+rdi*4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_5d5:
	/* 0x5d5: shr    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_5d8:
	/* 0x5d8: jmp    5df <tail_nodeport_rev_dnat_ipv4+0x5df> */
	X86_SIM_X86_JMP(0x5d8, 0x5df, x86_l_5df);
x86_l_5da:
	/* 0x5da: mov    edi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 5ULL);
x86_l_5df:
	/* 0x5df: mov    r8,QWORD PTR [rip+0x1a33] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R8, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_5e6:
	/* 0x5e6: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_5e8:
	/* 0x5e8: mov    esi,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5eb:
	/* 0x5eb: or     sil,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_5ee:
	/* 0x5ee: mov    DWORD PTR [rsp],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5f1:
	/* 0x5f1: cmp    edi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RCX, X86_WIDTH_32);
x86_l_5f3:
	/* 0x5f3: jb     5fa <tail_nodeport_rev_dnat_ipv4+0x5fa> */
	X86_SIM_X86_JCC(X86_CC_B, 0x5f3, 0x5fa, x86_l_5fa);
x86_l_5f5:
	/* 0x5f5: cmp    dl,BYTE PTR [rsp] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSP, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_5f8:
	/* 0x5f8: je     606 <tail_nodeport_rev_dnat_ipv4+0x606> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5f8, 0x606, x86_l_606);
x86_l_5fa:
	/* 0x5fa: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5fd:
	/* 0x5fd: mov    BYTE PTR [rax+0x2b],dl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_600:
	/* 0x600: mov    DWORD PTR [rax+0x34],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_603:
	/* 0x603: mov    ecx,DWORD PTR [r8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_606:
	/* 0x606: test   BYTE PTR [rsp+0x55],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 365072220162ULL);
x86_l_60b:
	/* 0x60b: jne    cb7 <tail_nodeport_rev_dnat_ipv4+0xcb7> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x60b, 0xcb7, x86_l_cb7);
x86_l_611:
	/* 0x611: movzx  eax,WORD PTR [rax+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_615:
	/* 0x615: mov    WORD PTR [rsp+0x8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_61a:
	/* 0x61a: mov    rbp,QWORD PTR [rip+0x1a33] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBP, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_621:
	/* 0x621: movzx  eax,BYTE PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_625:
	/* 0x625: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_62a:
	/* 0x62a: mov    rdi,QWORD PTR [rip+0x1a33] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_reverse_nat)));
x86_l_631:
	/* 0x631: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_636:
	/* 0x636: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_638:
	/* 0x638: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_63b:
	/* 0x63b: je     7d7 <tail_nodeport_rev_dnat_ipv4+0x7d7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x63b, 0x7d7, x86_l_7d7);
x86_l_641:
	/* 0x641: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_644:
	/* 0x644: mov    r15d,DWORD PTR [rsp+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_649:
	/* 0x649: movzx  eax,BYTE PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_64d:
	/* 0x64d: mov    eax,DWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_651:
	/* 0x651: mov    DWORD PTR [rsp+0x4c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_655:
	/* 0x655: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_65a:
	/* 0x65a: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_65c:
	/* 0x65c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_65f:
	/* 0x65f: mov    esi,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 12ULL);
x86_l_664:
	/* 0x664: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_667:
	/* 0x667: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_66c:
	/* 0x66c: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_66f:
	/* 0x66f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_671:
	/* 0x671: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_673:
	/* 0x673: mov    eax,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967155ULL);
x86_l_678:
	/* 0x678: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_67a:
	/* 0x67a: js     cde <tail_nodeport_rev_dnat_ipv4+0xcde> */
	X86_SIM_X86_JCC(X86_CC_S, 0x67a, 0xcde, x86_l_cde);
x86_l_680:
	/* 0x680: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_683:
	/* 0x683: je     cde <tail_nodeport_rev_dnat_ipv4+0xcde> */
	X86_SIM_X86_JCC(X86_CC_E, 0x683, 0xcde, x86_l_cde);
x86_l_689:
	/* 0x689: not    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_68c:
	/* 0x68c: add    r15d,DWORD PTR [r12] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_R12, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_690:
	/* 0x690: adc    r15d,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_694:
	/* 0x694: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_696:
	/* 0x696: mov    eax,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_69b:
	/* 0x69b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_69e:
	/* 0x69e: mov    esi,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 10ULL);
x86_l_6a3:
	/* 0x6a3: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6a5:
	/* 0x6a5: mov    ecx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_32);
x86_l_6a8:
	/* 0x6a8: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6ab:
	/* 0x6ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6ad:
	/* 0x6ad: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_6af:
	/* 0x6af: js     973 <tail_nodeport_rev_dnat_ipv4+0x973> */
	X86_SIM_X86_JCC(X86_CC_S, 0x6af, 0x973, x86_l_973);
x86_l_6b5:
	/* 0x6b5: movabs rax,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2199023255552ULL);
x86_l_6bf:
	/* 0x6bf: test   r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_6c2:
	/* 0x6c2: jne    7d7 <tail_nodeport_rev_dnat_ipv4+0x7d7> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x6c2, 0x7d7, x86_l_7d7);
x86_l_6c8:
	/* 0x6c8: movzx  ecx,BYTE PTR [rsp+0x54] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 84ULL);
x86_l_6cd:
	/* 0x6cd: cmp    ecx,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 58ULL);
x86_l_6d0:
	/* 0x6d0: je     6f4 <tail_nodeport_rev_dnat_ipv4+0x6f4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6d0, 0x6f4, x86_l_6f4);
x86_l_6d2:
	/* 0x6d2: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_6d5:
	/* 0x6d5: je     6e5 <tail_nodeport_rev_dnat_ipv4+0x6e5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6d5, 0x6e5, x86_l_6e5);
x86_l_6d7:
	/* 0x6d7: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_6da:
	/* 0x6da: jne    6fd <tail_nodeport_rev_dnat_ipv4+0x6fd> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x6da, 0x6fd, x86_l_6fd);
x86_l_6dc:
	/* 0x6dc: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6de:
	/* 0x6de: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_6e3:
	/* 0x6e3: jmp    702 <tail_nodeport_rev_dnat_ipv4+0x702> */
	X86_SIM_X86_JMP(0x6e3, 0x702, x86_l_702);
x86_l_6e5:
	/* 0x6e5: mov    r13d,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 32ULL);
x86_l_6eb:
	/* 0x6eb: mov    esi,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 6ULL);
x86_l_6f0:
	/* 0x6f0: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6f2:
	/* 0x6f2: jmp    705 <tail_nodeport_rev_dnat_ipv4+0x705> */
	X86_SIM_X86_JMP(0x6f2, 0x705, x86_l_705);
x86_l_6f4:
	/* 0x6f4: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6f6:
	/* 0x6f6: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_6fb:
	/* 0x6fb: jmp    702 <tail_nodeport_rev_dnat_ipv4+0x702> */
	X86_SIM_X86_JMP(0x6fb, 0x702, x86_l_702);
x86_l_6fd:
	/* 0x6fd: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6ff:
	/* 0x6ff: mov    dil,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_8, 1ULL);
x86_l_702:
	/* 0x702: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_705:
	/* 0x705: movzx  edx,WORD PTR [r12+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_70b:
	/* 0x70b: test   dx,dx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_16);
x86_l_70e:
	/* 0x70e: je     7af <tail_nodeport_rev_dnat_ipv4+0x7af> */
	X86_SIM_X86_JCC(X86_CC_E, 0x70e, 0x7af, x86_l_7af);
x86_l_714:
	/* 0x714: movzx  r12d,WORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 80ULL);
x86_l_71a:
	/* 0x71a: mov    eax,0xffffff72 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967154ULL);
x86_l_71f:
	/* 0x71f: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_721:
	/* 0x721: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_724:
	/* 0x724: jg     739 <tail_nodeport_rev_dnat_ipv4+0x739> */
	X86_SIM_X86_JCC(X86_CC_G, 0x724, 0x739, x86_l_739);
x86_l_726:
	/* 0x726: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_729:
	/* 0x729: je     7af <tail_nodeport_rev_dnat_ipv4+0x7af> */
	X86_SIM_X86_JCC(X86_CC_E, 0x729, 0x7af, x86_l_7af);
x86_l_72f:
	/* 0x72f: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_732:
	/* 0x732: je     747 <tail_nodeport_rev_dnat_ipv4+0x747> */
	X86_SIM_X86_JCC(X86_CC_E, 0x732, 0x747, x86_l_747);
x86_l_734:
	/* 0x734: jmp    cde <tail_nodeport_rev_dnat_ipv4+0xcde> */
	X86_SIM_X86_JMP(0x734, 0xcde, x86_l_cde);
x86_l_739:
	/* 0x739: cmp    ecx,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 58ULL);
x86_l_73c:
	/* 0x73c: je     7af <tail_nodeport_rev_dnat_ipv4+0x7af> */
	X86_SIM_X86_JCC(X86_CC_E, 0x73c, 0x7af, x86_l_7af);
x86_l_73e:
	/* 0x73e: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_741:
	/* 0x741: jne    cde <tail_nodeport_rev_dnat_ipv4+0xcde> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x741, 0xcde, x86_l_cde);
x86_l_747:
	/* 0x747: cmp    dx,r12w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_16);
x86_l_74b:
	/* 0x74b: je     7af <tail_nodeport_rev_dnat_ipv4+0x7af> */
	X86_SIM_X86_JCC(X86_CC_E, 0x74b, 0x7af, x86_l_7af);
x86_l_74d:
	/* 0x74d: mov    DWORD PTR [rsp+0x60],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_751:
	/* 0x751: mov    QWORD PTR [rsp],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_755:
	/* 0x755: mov    WORD PTR [rsp+0x8],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_75a:
	/* 0x75a: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_75f:
	/* 0x75f: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_764:
	/* 0x764: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_766:
	/* 0x766: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_769:
	/* 0x769: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_76c:
	/* 0x76c: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_771:
	/* 0x771: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_774:
	/* 0x774: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_776:
	/* 0x776: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_778:
	/* 0x778: js     a12 <tail_nodeport_rev_dnat_ipv4+0xa12> */
	X86_SIM_X86_JCC(X86_CC_S, 0x778, 0xa12, x86_l_a12);
x86_l_77e:
	/* 0x77e: movzx  ecx,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_783:
	/* 0x783: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_787:
	/* 0x787: lea    esi,[rax+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_78b:
	/* 0x78b: mov    r8d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R13, X86_WIDTH_32);
x86_l_78e:
	/* 0x78e: or     r8d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_792:
	/* 0x792: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_797:
	/* 0x797: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_79a:
	/* 0x79a: mov    edx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_32);
x86_l_79d:
	/* 0x79d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_79f:
	/* 0x79f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_7a1:
	/* 0x7a1: js     9f8 <tail_nodeport_rev_dnat_ipv4+0x9f8> */
	X86_SIM_X86_JCC(X86_CC_S, 0x7a1, 0x9f8, x86_l_9f8);
x86_l_7a7:
	/* 0x7a7: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7ab:
	/* 0x7ab: mov    edi,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_7af:
	/* 0x7af: test   dil,dil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_8);
x86_l_7b2:
	/* 0x7b2: jne    7d7 <tail_nodeport_rev_dnat_ipv4+0x7d7> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x7b2, 0x7d7, x86_l_7d7);
x86_l_7b4:
	/* 0x7b4: add    esi,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R14, X86_WIDTH_32, X86_ALU_ADD);
x86_l_7b7:
	/* 0x7b7: or     r13d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_OR, 16ULL);
x86_l_7bb:
	/* 0x7bb: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7bd:
	/* 0x7bd: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_7c2:
	/* 0x7c2: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_7c5:
	/* 0x7c5: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7c7:
	/* 0x7c7: mov    ecx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_32);
x86_l_7ca:
	/* 0x7ca: mov    r8d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R13, X86_WIDTH_32);
x86_l_7cd:
	/* 0x7cd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7cf:
	/* 0x7cf: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_7d1:
	/* 0x7d1: js     9f8 <tail_nodeport_rev_dnat_ipv4+0x9f8> */
	X86_SIM_X86_JCC(X86_CC_S, 0x7d1, 0x9f8, x86_l_9f8);
x86_l_7d7:
	/* 0x7d7: mov    ecx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_7da:
	/* 0x7da: sub    ecx,DWORD PTR [rbx+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_7dd:
	/* 0x7dd: mov    ebp,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 0ULL);
x86_l_7e2:
	/* 0x7e2: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_7e7:
	/* 0x7e7: cmp    ecx,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 20ULL);
x86_l_7ea:
	/* 0x7ea: jb     cde <tail_nodeport_rev_dnat_ipv4+0xcde> */
	X86_SIM_X86_JCC(X86_CC_B, 0x7ea, 0xcde, x86_l_cde);
x86_l_7f0:
	/* 0x7f0: mov    r12,QWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_7f7:
	/* 0x7f7: mov    eax,0xfffff0ff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294963455ULL);
x86_l_7fc:
	/* 0x7fc: and    eax,DWORD PTR [rbx+0xa8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 168ULL);
x86_l_802:
	/* 0x802: or     eax,0x300 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 768ULL);
x86_l_807:
	/* 0x807: mov    DWORD PTR [rbx+0xa8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_80d:
	/* 0x80d: mov    eax,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_812:
	/* 0x812: mov    QWORD PTR [rsp+0xe],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60129542144ULL);
x86_l_81b:
	/* 0x81b: mov    WORD PTR [rsp+0x1e],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 128849018880ULL);
x86_l_822:
	/* 0x822: mov    QWORD PTR [rsp+0x16],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 94489280512ULL);
x86_l_82b:
	/* 0x82b: mov    DWORD PTR [rsp+0x8],0x40 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738432ULL);
x86_l_833:
	/* 0x833: mov    BYTE PTR [rsp+0xf],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 64424509441ULL);
x86_l_838:
	/* 0x838: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_83c:
	/* 0x83c: mov    WORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_843:
	/* 0x843: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_848:
	/* 0x848: mov    rdi,QWORD PTR [rip+0x1a33] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipcache_v2)));
x86_l_84f:
	/* 0x84f: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_854:
	/* 0x854: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_856:
	/* 0x856: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_858:
	/* 0x858: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_85e:
	/* 0x85e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_861:
	/* 0x861: je     881 <tail_nodeport_rev_dnat_ipv4+0x881> */
	X86_SIM_X86_JCC(X86_CC_E, 0x861, 0x881, x86_l_881);
x86_l_863:
	/* 0x863: movzx  ecx,BYTE PTR [rax+0x17] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 23ULL);
x86_l_867:
	/* 0x867: and    cl,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 3ULL);
x86_l_86a:
	/* 0x86a: mov    r15d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 0ULL);
x86_l_870:
	/* 0x870: cmp    cl,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_873:
	/* 0x873: jne    884 <tail_nodeport_rev_dnat_ipv4+0x884> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x873, 0x884, x86_l_884);
x86_l_875:
	/* 0x875: mov    r15d,DWORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_879:
	/* 0x879: mov    r14d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 6ULL);
x86_l_87f:
	/* 0x87f: jmp    884 <tail_nodeport_rev_dnat_ipv4+0x884> */
	X86_SIM_X86_JMP(0x87f, 0x884, x86_l_884);
x86_l_881:
	/* 0x881: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_884:
	/* 0x884: mov    eax,DWORD PTR [r12+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_889:
	/* 0x889: mov    DWORD PTR [rsp+0x80],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_890:
	/* 0x890: mov    eax,DWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_895:
	/* 0x895: mov    DWORD PTR [rsp+0x90],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_89c:
	/* 0x89c: movzx  edx,BYTE PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_8a2:
	/* 0x8a2: mov    eax,0xffffff3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967100ULL);
x86_l_8a7:
	/* 0x8a7: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_8aa:
	/* 0x8aa: jb     cde <tail_nodeport_rev_dnat_ipv4+0xcde> */
	X86_SIM_X86_JCC(X86_CC_B, 0x8aa, 0xcde, x86_l_cde);
x86_l_8b0:
	/* 0x8b0: lea    eax,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_8b3:
	/* 0x8b3: mov    BYTE PTR [r12+0x8],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8b8:
	/* 0x8b8: movzx  ecx,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_8bb:
	/* 0x8bb: mov    eax,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_8c0:
	/* 0x8c0: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_8c3:
	/* 0x8c3: mov    esi,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 10ULL);
x86_l_8c8:
	/* 0x8c8: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_8ce:
	/* 0x8ce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8d0:
	/* 0x8d0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_8d2:
	/* 0x8d2: js     973 <tail_nodeport_rev_dnat_ipv4+0x973> */
	X86_SIM_X86_JCC(X86_CC_S, 0x8d2, 0x973, x86_l_973);
x86_l_8d8:
	/* 0x8d8: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_8db:
	/* 0x8db: je     97d <tail_nodeport_rev_dnat_ipv4+0x97d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8db, 0x97d, x86_l_97d);
x86_l_8e1:
	/* 0x8e1: movzx  ebp,WORD PTR [rbx+0xb4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 180ULL);
x86_l_8e8:
	/* 0x8e8: mov    eax,0x2b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_8ed:
	/* 0x8ed: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_8f0:
	/* 0x8f0: mov    esi,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 14ULL);
x86_l_8f5:
	/* 0x8f5: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8f7:
	/* 0x8f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8f9:
	/* 0x8f9: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_8fb:
	/* 0x8fb: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_900:
	/* 0x900: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_902:
	/* 0x902: jne    9f1 <tail_nodeport_rev_dnat_ipv4+0x9f1> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x902, 0x9f1, x86_l_9f1);
x86_l_908:
	/* 0x908: mov    WORD PTR [rsp+0x8],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_90d:
	/* 0x90d: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_912:
	/* 0x912: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_917:
	/* 0x917: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_91a:
	/* 0x91a: mov    esi,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 12ULL);
x86_l_91f:
	/* 0x91f: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_924:
	/* 0x924: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_927:
	/* 0x927: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_929:
	/* 0x929: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_92b:
	/* 0x92b: mov    eax,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967155ULL);
x86_l_930:
	/* 0x930: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_932:
	/* 0x932: js     9f1 <tail_nodeport_rev_dnat_ipv4+0x9f1> */
	X86_SIM_X86_JCC(X86_CC_S, 0x932, 0x9f1, x86_l_9f1);
x86_l_938:
	/* 0x938: mov    r12d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_93c:
	/* 0x93c: movabs rax,0x6f00220200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 476743598592ULL);
x86_l_946:
	/* 0x946: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_94b:
	/* 0x94b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_950:
	/* 0x950: mov    rdi,QWORD PTR [rip+0x1a33] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_957:
	/* 0x957: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_95c:
	/* 0x95c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_95e:
	/* 0x95e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_961:
	/* 0x961: je     abf <tail_nodeport_rev_dnat_ipv4+0xabf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x961, 0xabf, x86_l_abf);
x86_l_967:
	/* 0x967: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_96a:
	/* 0x96a: add    QWORD PTR [rax+0x8],r12 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_96e:
	/* 0x96e: jmp    ae7 <tail_nodeport_rev_dnat_ipv4+0xae7> */
	X86_SIM_X86_JMP(0x96e, 0xae7, x86_l_ae7);
x86_l_973:
	/* 0x973: mov    eax,0xffffff67 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967143ULL);
x86_l_978:
	/* 0x978: jmp    cde <tail_nodeport_rev_dnat_ipv4+0xcde> */
	X86_SIM_X86_JMP(0x978, 0xcde, x86_l_cde);
x86_l_97d:
	/* 0x97d: mov    eax,0x45 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 69ULL);
x86_l_982:
	/* 0x982: mov    rcx,QWORD PTR [rip+0x1a33] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_supports_fib_lookup_skip_neigh)));
x86_l_989:
	/* 0x989: movzx  ecx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_98c:
	/* 0x98c: shl    ecx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 2ULL);
x86_l_98f:
	/* 0x98f: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_994:
	/* 0x994: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_997:
	/* 0x997: mov    edx,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 64ULL);
x86_l_99c:
	/* 0x99c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_99e:
	/* 0x99e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_9a0:
	/* 0x9a0: je     9a7 <tail_nodeport_rev_dnat_ipv4+0x9a7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9a0, 0x9a7, x86_l_9a7);
x86_l_9a2:
	/* 0x9a2: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_9a5:
	/* 0x9a5: jne    a02 <tail_nodeport_rev_dnat_ipv4+0xa02> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x9a5, 0xa02, x86_l_a02);
x86_l_9a7:
	/* 0x9a7: mov    ebp,DWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_9ab:
	/* 0x9ab: mov    DWORD PTR [rsp+0x8],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9af:
	/* 0x9af: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_9b4:
	/* 0x9b4: mov    rdi,QWORD PTR [rip+0x1a33] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_devices)));
x86_l_9bb:
	/* 0x9bb: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9c0:
	/* 0x9c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9c2:
	/* 0x9c2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9c5:
	/* 0x9c5: je     9cd <tail_nodeport_rev_dnat_ipv4+0x9cd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9c5, 0x9cd, x86_l_9cd);
x86_l_9c7:
	/* 0x9c7: test   BYTE PTR [rax+0x8],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_9cb:
	/* 0x9cb: jne    a1c <tail_nodeport_rev_dnat_ipv4+0xa1c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x9cb, 0xa1c, x86_l_a1c);
x86_l_9cd:
	/* 0x9cd: movzx  r14d,WORD PTR [rbx+0xb4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 180ULL);
x86_l_9d5:
	/* 0x9d5: mov    eax,0x2b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_9da:
	/* 0x9da: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_9dd:
	/* 0x9dd: mov    esi,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 14ULL);
x86_l_9e2:
	/* 0x9e2: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9e4:
	/* 0x9e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9e6:
	/* 0x9e6: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_9e8:
	/* 0x9e8: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_9ed:
	/* 0x9ed: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_9ef:
	/* 0x9ef: je     a28 <tail_nodeport_rev_dnat_ipv4+0xa28> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9ef, 0xa28, x86_l_a28);
x86_l_9f1:
	/* 0x9f1: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9f3:
	/* 0x9f3: jmp    cde <tail_nodeport_rev_dnat_ipv4+0xcde> */
	X86_SIM_X86_JMP(0x9f3, 0xcde, x86_l_cde);
x86_l_9f8:
	/* 0x9f8: mov    eax,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967142ULL);
x86_l_9fd:
	/* 0x9fd: jmp    cde <tail_nodeport_rev_dnat_ipv4+0xcde> */
	X86_SIM_X86_JMP(0x9fd, 0xcde, x86_l_cde);
x86_l_a02:
	/* 0xa02: shl    eax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_a05:
	/* 0xa05: movzx  ebp,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_a08:
	/* 0xa08: mov    eax,0xffffff57 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967127ULL);
x86_l_a0d:
	/* 0xa0d: jmp    cde <tail_nodeport_rev_dnat_ipv4+0xcde> */
	X86_SIM_X86_JMP(0xa0d, 0xcde, x86_l_cde);
x86_l_a12:
	/* 0xa12: mov    eax,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967155ULL);
x86_l_a17:
	/* 0xa17: jmp    cde <tail_nodeport_rev_dnat_ipv4+0xcde> */
	X86_SIM_X86_JMP(0xa17, 0xcde, x86_l_cde);
x86_l_a1c:
	/* 0xa1c: mov    eax,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 23ULL);
x86_l_a21:
	/* 0xa21: mov    edi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_32);
x86_l_a23:
	/* 0xa23: jmp    b54 <tail_nodeport_rev_dnat_ipv4+0xb54> */
	X86_SIM_X86_JMP(0xa23, 0xb54, x86_l_b54);
x86_l_a28:
	/* 0xa28: mov    WORD PTR [rsp+0x8],r14w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a2e:
	/* 0xa2e: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_a33:
	/* 0xa33: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a38:
	/* 0xa38: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_a3b:
	/* 0xa3b: mov    esi,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 12ULL);
x86_l_a40:
	/* 0xa40: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_a45:
	/* 0xa45: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a48:
	/* 0xa48: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a4a:
	/* 0xa4a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a4c:
	/* 0xa4c: js     b82 <tail_nodeport_rev_dnat_ipv4+0xb82> */
	X86_SIM_X86_JCC(X86_CC_S, 0xa4c, 0xb82, x86_l_b82);
x86_l_a52:
	/* 0xa52: lea    rax,[rsp+0x90] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_a5a:
	/* 0xa5a: movzx  ecx,BYTE PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 112ULL);
x86_l_a5f:
	/* 0xa5f: mov    DWORD PTR [rsp+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a63:
	/* 0xa63: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a66:
	/* 0xa66: mov    rax,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a6a:
	/* 0xa6a: mov    QWORD PTR [rsp+0xc],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_a6f:
	/* 0xa6f: mov    QWORD PTR [rsp+0x14],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_a74:
	/* 0xa74: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a79:
	/* 0xa79: mov    eax,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 152ULL);
x86_l_a7e:
	/* 0xa7e: mov    edi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_32);
x86_l_a80:
	/* 0xa80: mov    edx,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 20ULL);
x86_l_a85:
	/* 0xa85: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a87:
	/* 0xa87: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a89:
	/* 0xa89: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a8b:
	/* 0xa8b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a8d:
	/* 0xa8d: jns    b62 <tail_nodeport_rev_dnat_ipv4+0xb62> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xa8d, 0xb62, x86_l_b62);
x86_l_a93:
	/* 0xa93: jmp    cde <tail_nodeport_rev_dnat_ipv4+0xcde> */
	X86_SIM_X86_JMP(0xa93, 0xcde, x86_l_cde);
x86_l_a98:
	/* 0xa98: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a9d:
	/* 0xa9d: mov    rdi,QWORD PTR [rip+0x1a33] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv4_frag_datagrams)));
x86_l_aa4:
	/* 0xaa4: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_aa9:
	/* 0xaa9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aab:
	/* 0xaab: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_aae:
	/* 0xaae: je     b95 <tail_nodeport_rev_dnat_ipv4+0xb95> */
	X86_SIM_X86_JCC(X86_CC_E, 0xaae, 0xb95, x86_l_b95);
x86_l_ab4:
	/* 0xab4: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ab6:
	/* 0xab6: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_aba:
	/* 0xaba: jmp    236 <tail_nodeport_rev_dnat_ipv4+0x236> */
	X86_SIM_X86_JMP(0xaba, 0x236, x86_l_236);
x86_l_abf:
	/* 0xabf: mov    QWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_ac8:
	/* 0xac8: mov    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_acd:
	/* 0xacd: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_ad2:
	/* 0xad2: mov    rdi,QWORD PTR [rip+0x1a33] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_ad9:
	/* 0xad9: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_ade:
	/* 0xade: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ae3:
	/* 0xae3: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ae5:
	/* 0xae5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ae7:
	/* 0xae7: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_af0:
	/* 0xaf0: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_af8:
	/* 0xaf8: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_b01:
	/* 0xb01: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_b0a:
	/* 0xb0a: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_b13:
	/* 0xb13: mov    DWORD PTR [rsp+0x8],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b18:
	/* 0xb18: movbe  DWORD PTR [rsp+0xc],r15d */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 12ULL);
x86_l_b1f:
	/* 0xb1f: mov    BYTE PTR [rsp+0x1d],0x40 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 124554051648ULL);
x86_l_b24:
	/* 0xb24: mov    eax,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 21ULL);
x86_l_b29:
	/* 0xb29: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b2e:
	/* 0xb2e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_b31:
	/* 0xb31: mov    edx,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 28ULL);
x86_l_b36:
	/* 0xb36: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_b3b:
	/* 0xb3b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b3d:
	/* 0xb3d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b3f:
	/* 0xb3f: mov    eax,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967155ULL);
x86_l_b44:
	/* 0xb44: js     9f1 <tail_nodeport_rev_dnat_ipv4+0x9f1> */
	X86_SIM_X86_JCC(X86_CC_S, 0xb44, 0x9f1, x86_l_9f1);
x86_l_b4a:
	/* 0xb4a: mov    eax,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 23ULL);
x86_l_b4f:
	/* 0xb4f: mov    edi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 1ULL);
x86_l_b54:
	/* 0xb54: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b56:
	/* 0xb56: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b58:
	/* 0xb58: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b5a:
	/* 0xb5a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b5c:
	/* 0xb5c: js     cde <tail_nodeport_rev_dnat_ipv4+0xcde> */
	X86_SIM_X86_JCC(X86_CC_S, 0xb5c, 0xcde, x86_l_cde);
x86_l_b62:
	/* 0xb62: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_b65:
	/* 0xb65: je     cde <tail_nodeport_rev_dnat_ipv4+0xcde> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb65, 0xcde, x86_l_cde);
x86_l_b6b:
	/* 0xb6b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b6d:
	/* 0xb6d: jne    d7e <tail_nodeport_rev_dnat_ipv4+0xd7e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb6d, 0xd7e, x86_l_d7e);
x86_l_b73:
	/* 0xb73: jmp    cb7 <tail_nodeport_rev_dnat_ipv4+0xcb7> */
	X86_SIM_X86_JMP(0xb73, 0xcb7, x86_l_cb7);
x86_l_b78:
	/* 0xb78: mov    eax,0xffffff63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967139ULL);
x86_l_b7d:
	/* 0xb7d: jmp    cde <tail_nodeport_rev_dnat_ipv4+0xcde> */
	X86_SIM_X86_JMP(0xb7d, 0xcde, x86_l_cde);
x86_l_b82:
	/* 0xb82: sar    eax,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SAR, 31ULL);
x86_l_b85:
	/* 0xb85: and    eax,0xffffff73 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967155ULL);
x86_l_b8a:
	/* 0xb8a: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b8c:
	/* 0xb8c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b8e:
	/* 0xb8e: jns    b62 <tail_nodeport_rev_dnat_ipv4+0xb62> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xb8e, 0xb62, x86_l_b62);
x86_l_b90:
	/* 0xb90: jmp    cde <tail_nodeport_rev_dnat_ipv4+0xcde> */
	X86_SIM_X86_JMP(0xb90, 0xcde, x86_l_cde);
x86_l_b95:
	/* 0xb95: mov    eax,0xffffff51 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967121ULL);
x86_l_b9a:
	/* 0xb9a: jmp    cde <tail_nodeport_rev_dnat_ipv4+0xcde> */
	X86_SIM_X86_JMP(0xb9a, 0xcde, x86_l_cde);
x86_l_b9f:
	/* 0xb9f: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_ba5:
	/* 0xba5: jmp    363 <tail_nodeport_rev_dnat_ipv4+0x363> */
	X86_SIM_X86_JMP(0xba5, 0x363, x86_l_363);
x86_l_baa:
	/* 0xbaa: mov    QWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_bb3:
	/* 0xbb3: mov    QWORD PTR [rsp+0x10],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_bb8:
	/* 0xbb8: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_bbd:
	/* 0xbbd: mov    rdi,QWORD PTR [rip+0x1a33] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_bc4:
	/* 0xbc4: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_bc9:
	/* 0xbc9: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bce:
	/* 0xbce: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bd0:
	/* 0xbd0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bd2:
	/* 0xbd2: jmp    236 <tail_nodeport_rev_dnat_ipv4+0x236> */
	X86_SIM_X86_JMP(0xbd2, 0x236, x86_l_236);
x86_l_bd7:
	/* 0xbd7: mov    r12d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 60ULL);
x86_l_bdd:
	/* 0xbdd: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_be1:
	/* 0xbe1: jne    c1b <tail_nodeport_rev_dnat_ipv4+0xc1b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xbe1, 0xc1b, x86_l_c1b);
x86_l_be3:
	/* 0xbe3: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_be6:
	/* 0xbe6: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_be8:
	/* 0xbe8: shr    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_beb:
	/* 0xbeb: and    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_bee:
	/* 0xbee: or     ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_OR);
x86_l_bf0:
	/* 0xbf0: mov    WORD PTR [r14+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_bf5:
	/* 0xbf5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_bf7:
	/* 0xbf7: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_bfc:
	/* 0xbfc: mov    r12d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 21600ULL);
x86_l_c02:
	/* 0xc02: cmove  r12d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_c06:
	/* 0xc06: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c0a:
	/* 0xc0a: je     c1b <tail_nodeport_rev_dnat_ipv4+0xc1b> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc0a, 0xc1b, x86_l_c1b);
x86_l_c0c:
	/* 0xc0c: mov    rax,QWORD PTR [rip+0x1a33] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_c13:
	/* 0xc13: imul   r12d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_c17:
	/* 0xc17: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_c1b:
	/* 0xc1b: shr    DWORD PTR [rsp],0x8 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_32, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_SHR)), 8ULL);
x86_l_c1f:
	/* 0xc1f: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c23:
	/* 0xc23: je     c34 <tail_nodeport_rev_dnat_ipv4+0xc34> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc23, 0xc34, x86_l_c34);
x86_l_c25:
	/* 0xc25: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_c2a:
	/* 0xc2a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c2c:
	/* 0xc2c: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_c2e:
	/* 0xc2e: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_c32:
	/* 0xc32: jmp    c57 <tail_nodeport_rev_dnat_ipv4+0xc57> */
	X86_SIM_X86_JMP(0xc32, 0xc57, x86_l_c57);
x86_l_c34:
	/* 0xc34: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_c39:
	/* 0xc39: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c3b:
	/* 0xc3b: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_c3d:
	/* 0xc3d: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_c41:
	/* 0xc41: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_c4b:
	/* 0xc4b: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_c4e:
	/* 0xc4e: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_c53:
	/* 0xc53: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_c57:
	/* 0xc57: add    r12d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_c5a:
	/* 0xc5a: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_c5d:
	/* 0xc5d: mov    DWORD PTR [r14+0x20],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c61:
	/* 0xc61: movzx  ecx,BYTE PTR [r14+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_c66:
	/* 0xc66: mov    edx,DWORD PTR [r14+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_c6a:
	/* 0xc6a: mov    esi,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c6d:
	/* 0xc6d: and    sil,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_c71:
	/* 0xc71: mov    DWORD PTR [rsp],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c74:
	/* 0xc74: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c78:
	/* 0xc78: je     c8b <tail_nodeport_rev_dnat_ipv4+0xc8b> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc78, 0xc8b, x86_l_c8b);
x86_l_c7a:
	/* 0xc7a: mov    rsi,QWORD PTR [rip+0x1a33] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_c81:
	/* 0xc81: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c83:
	/* 0xc83: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_c86:
	/* 0xc86: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_c89:
	/* 0xc89: jmp    c90 <tail_nodeport_rev_dnat_ipv4+0xc90> */
	X86_SIM_X86_JMP(0xc89, 0xc90, x86_l_c90);
x86_l_c8b:
	/* 0xc8b: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_c90:
	/* 0xc90: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_c92:
	/* 0xc92: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c95:
	/* 0xc95: or     dl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_c97:
	/* 0xc97: mov    DWORD PTR [rsp],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c9a:
	/* 0xc9a: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_c9c:
	/* 0xc9c: jb     ca3 <tail_nodeport_rev_dnat_ipv4+0xca3> */
	X86_SIM_X86_JCC(X86_CC_B, 0xc9c, 0xca3, x86_l_ca3);
x86_l_c9e:
	/* 0xc9e: cmp    cl,BYTE PTR [rsp] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_ca1:
	/* 0xca1: je     cb7 <tail_nodeport_rev_dnat_ipv4+0xcb7> */
	X86_SIM_X86_JCC(X86_CC_E, 0xca1, 0xcb7, x86_l_cb7);
x86_l_ca3:
	/* 0xca3: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ca6:
	/* 0xca6: mov    BYTE PTR [r14+0x2b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_caa:
	/* 0xcaa: mov    DWORD PTR [r14+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_cae:
	/* 0xcae: mov    rax,QWORD PTR [rip+0x1a33] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_cb5:
	/* 0xcb5: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cb7:
	/* 0xcb7: or     BYTE PTR [rbx+0x86],0x4 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RBX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 575525617668ULL);
x86_l_cbe:
	/* 0xcbe: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_cc3:
	/* 0xcc3: mov    rsi,QWORD PTR [rip+0x1a33] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_cca:
	/* 0xcca: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_ccd:
	/* 0xccd: mov    edx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_cd2:
	/* 0xcd2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cd4:
	/* 0xcd4: mov    eax,0xffffff74 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967156ULL);
x86_l_cd9:
	/* 0xcd9: mov    ebp,0x700 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1792ULL);
x86_l_cde:
	/* 0xcde: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_ce0:
	/* 0xce0: neg    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_ce2:
	/* 0xce2: cmovs  ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_S);
x86_l_ce5:
	/* 0xce5: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_ce8:
	/* 0xce8: or     eax,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_32, X86_ALU_OR);
x86_l_cea:
	/* 0xcea: mov    QWORD PTR [rbx+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_cf2:
	/* 0xcf2: mov    DWORD PTR [rbx+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_cf5:
	/* 0xcf5: movabs rcx,0x97f680200000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 684380026182828032ULL);
x86_l_cff:
	/* 0xcff: mov    QWORD PTR [rbx+0x34],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_d03:
	/* 0xd03: mov    r14d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_d07:
	/* 0xd07: movabs rcx,0x68097f0200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 446835917312ULL);
x86_l_d11:
	/* 0xd11: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d16:
	/* 0xd16: mov    BYTE PTR [rsp+0x8],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d1a:
	/* 0xd1a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d1f:
	/* 0xd1f: mov    rdi,QWORD PTR [rip+0x1a33] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_d26:
	/* 0xd26: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d2b:
	/* 0xd2b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d2d:
	/* 0xd2d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d30:
	/* 0xd30: je     d3b <tail_nodeport_rev_dnat_ipv4+0xd3b> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd30, 0xd3b, x86_l_d3b);
x86_l_d32:
	/* 0xd32: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_d35:
	/* 0xd35: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_d39:
	/* 0xd39: jmp    d63 <tail_nodeport_rev_dnat_ipv4+0xd63> */
	X86_SIM_X86_JMP(0xd39, 0xd63, x86_l_d63);
x86_l_d3b:
	/* 0xd3b: mov    QWORD PTR [rsp+0x70],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337153ULL);
x86_l_d44:
	/* 0xd44: mov    QWORD PTR [rsp+0x78],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_d49:
	/* 0xd49: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_d4e:
	/* 0xd4e: mov    rdi,QWORD PTR [rip+0x1a33] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_d55:
	/* 0xd55: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d5a:
	/* 0xd5a: lea    rdx,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_d5f:
	/* 0xd5f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d61:
	/* 0xd61: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d63:
	/* 0xd63: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_d68:
	/* 0xd68: mov    rsi,QWORD PTR [rip+0x1a33] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_d6f:
	/* 0xd6f: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_d72:
	/* 0xd72: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_d77:
	/* 0xd77: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d79:
	/* 0xd79: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_d7e:
	/* 0xd7e: add    rsp,0xb8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 184ULL);
x86_l_d85:
	/* 0xd85: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_d87:
	/* 0xd87: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_d88:
	/* 0xd88: jmp    d8d <tail_nodeport_rev_dnat_ipv4+0xd8d> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_d8d:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
