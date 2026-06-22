extern char __config_debug_lb;
extern char __config_enable_conntrack_accounting;
extern char __config_enable_ipv6_fragments;
extern char __config_enable_jiffies;
extern char __config_kernel_hz;
extern char __config_supports_fib_lookup_skip_neigh;
extern char __config_trace_payload_len;
extern char cilium_calls;
extern char cilium_ct6_global;
extern char cilium_ct_any6_global;
extern char cilium_devices;
extern char cilium_ipcache_v2;
extern char cilium_ipv6_frag_datagrams;
extern char cilium_lb6_reverse_nat;
extern char cilium_metrics;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int cilium_bpf_wireguard_tail_nodeport_rev_dnat_ingress_ipv6_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0xa: mov    r13,QWORD PTR [rip+0x1427] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_11:
	/* 0x11: mov    eax,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15:
	/* 0x15: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_1e:
	/* 0x1e: mov    DWORD PTR [rsp+0xb8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 790273982464ULL);
x86_l_29:
	/* 0x29: mov    QWORD PTR [rsp+0xb0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 755914244096ULL);
x86_l_35:
	/* 0x35: mov    QWORD PTR [rsp+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_41:
	/* 0x41: mov    QWORD PTR [rsp+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_4d:
	/* 0x4d: mov    QWORD PTR [rsp+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_59:
	/* 0x59: mov    QWORD PTR [rsp+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_65:
	/* 0x65: mov    QWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_71:
	/* 0x71: mov    QWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_7d:
	/* 0x7d: mov    BYTE PTR [rsp+0x78],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 515396075530ULL);
x86_l_82:
	/* 0x82: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_85:
	/* 0x85: mov    eax,DWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_88:
	/* 0x88: mov    DWORD PTR [rsp+0x80],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_8f:
	/* 0x8f: mov    QWORD PTR [rsp+0x6e],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 472446402560ULL);
x86_l_98:
	/* 0x98: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_a1:
	/* 0xa1: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_aa:
	/* 0xaa: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_b3:
	/* 0xb3: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_bc:
	/* 0xbc: mov    r15d,DWORD PTR [rdi+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_c0:
	/* 0xc0: mov    eax,DWORD PTR [rdi+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_c3:
	/* 0xc3: lea    rcx,[r15+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c7:
	/* 0xc7: cmp    rcx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_ca:
	/* 0xca: ja     a1d <tail_nodeport_rev_dnat_ingress_ipv6+0xa1d> */
	X86_SIM_X86_JCC(X86_CC_A, 0xca, 0xa1d, x86_l_a1d);
x86_l_d0:
	/* 0xd0: movzx  r14d,BYTE PTR [r15+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_d5:
	/* 0xd5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d7:
	/* 0xd7: mov    BYTE PTR [rsp+0x74],r14b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_dc:
	/* 0xdc: mov    esi,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 40ULL);
x86_l_e1:
	/* 0xe1: cmp    r14,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_64, 60ULL);
x86_l_e5:
	/* 0xe5: ja     4ed <tail_nodeport_rev_dnat_ingress_ipv6+0x4ed> */
	X86_SIM_X86_JCC(X86_CC_A, 0xe5, 0x4ed, x86_l_4ed);
x86_l_eb:
	/* 0xeb: mov    ebp,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967140ULL);
x86_l_f0:
	/* 0xf0: movabs rax,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_fa:
	/* 0xfa: bt     rax,r14 */
	X86_SIM_L_EXEC_BT(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_fe:
	/* 0xfe: jae    1f9 <tail_nodeport_rev_dnat_ingress_ipv6+0x1f9> */
	X86_SIM_X86_JCC(X86_CC_AE, 0xfe, 0x1f9, x86_l_1f9);
x86_l_104:
	/* 0x104: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_107:
	/* 0x107: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_10c:
	/* 0x10c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_10f:
	/* 0x10f: mov    esi,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 40ULL);
x86_l_114:
	/* 0x114: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_119:
	/* 0x119: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11b:
	/* 0x11b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_11d:
	/* 0x11d: js     a1d <tail_nodeport_rev_dnat_ingress_ipv6+0xa1d> */
	X86_SIM_X86_JCC(X86_CC_S, 0x11d, 0xa1d, x86_l_a1d);
x86_l_123:
	/* 0x123: movzx  r13d,BYTE PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_128:
	/* 0x128: cmp    r14d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 43ULL);
x86_l_12c:
	/* 0x12c: jle    14c <tail_nodeport_rev_dnat_ingress_ipv6+0x14c> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x12c, 0x14c, x86_l_14c);
x86_l_12e:
	/* 0x12e: cmp    r14d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 60ULL);
x86_l_132:
	/* 0x132: je     14c <tail_nodeport_rev_dnat_ingress_ipv6+0x14c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x132, 0x14c, x86_l_14c);
x86_l_134:
	/* 0x134: cmp    r14d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 51ULL);
x86_l_138:
	/* 0x138: jne    208 <tail_nodeport_rev_dnat_ingress_ipv6+0x208> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x138, 0x208, x86_l_208);
x86_l_13e:
	/* 0x13e: movzx  eax,BYTE PTR [rsp+0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 1ULL);
x86_l_143:
	/* 0x143: lea    esi,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_14a:
	/* 0x14a: jmp    166 <tail_nodeport_rev_dnat_ingress_ipv6+0x166> */
	X86_SIM_X86_JMP(0x14a, 0x166, x86_l_166);
x86_l_14c:
	/* 0x14c: movzx  eax,BYTE PTR [rsp+0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 1ULL);
x86_l_151:
	/* 0x151: lea    esi,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_158:
	/* 0x158: cmp    r14b,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 44ULL);
x86_l_15c:
	/* 0x15c: jne    166 <tail_nodeport_rev_dnat_ingress_ipv6+0x166> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x15c, 0x166, x86_l_166);
x86_l_15e:
	/* 0x15e: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_161:
	/* 0x161: jmp    20e <tail_nodeport_rev_dnat_ingress_ipv6+0x20e> */
	X86_SIM_X86_JMP(0x161, 0x20e, x86_l_20e);
x86_l_166:
	/* 0x166: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_168:
	/* 0x168: movzx  r12d,r13b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R13, X86_WIDTH_32, X86_WIDTH_8);
x86_l_16c:
	/* 0x16c: add    esi,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 40ULL);
x86_l_16f:
	/* 0x16f: cmp    r12d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 60ULL);
x86_l_173:
	/* 0x173: ja     289 <tail_nodeport_rev_dnat_ingress_ipv6+0x289> */
	X86_SIM_X86_JCC(X86_CC_A, 0x173, 0x289, x86_l_289);
x86_l_179:
	/* 0x179: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_17c:
	/* 0x17c: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_186:
	/* 0x186: bt     rdx,rax */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_18a:
	/* 0x18a: jae    291 <tail_nodeport_rev_dnat_ingress_ipv6+0x291> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x18a, 0x291, x86_l_291);
x86_l_190:
	/* 0x190: mov    BYTE PTR [rsp+0x38],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_195:
	/* 0x195: mov    r13,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RCX, X86_WIDTH_64);
x86_l_198:
	/* 0x198: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_19b:
	/* 0x19b: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1a0:
	/* 0x1a0: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1a3:
	/* 0x1a3: mov    QWORD PTR [rsp+0x30],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1a8:
	/* 0x1a8: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1ad:
	/* 0x1ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1af:
	/* 0x1af: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1b1:
	/* 0x1b1: js     a1d <tail_nodeport_rev_dnat_ingress_ipv6+0xa1d> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1b1, 0xa1d, x86_l_a1d);
x86_l_1b7:
	/* 0x1b7: movzx  r14d,BYTE PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1bc:
	/* 0x1bc: cmp    r12d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 43ULL);
x86_l_1c0:
	/* 0x1c0: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_1c3:
	/* 0x1c3: jle    299 <tail_nodeport_rev_dnat_ingress_ipv6+0x299> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x1c3, 0x299, x86_l_299);
x86_l_1c9:
	/* 0x1c9: cmp    r12d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 44ULL);
x86_l_1cd:
	/* 0x1cd: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1d2:
	/* 0x1d2: movzx  edx,BYTE PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 56ULL);
x86_l_1d7:
	/* 0x1d7: je     2b7 <tail_nodeport_rev_dnat_ingress_ipv6+0x2b7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1d7, 0x2b7, x86_l_2b7);
x86_l_1dd:
	/* 0x1dd: cmp    r12d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 51ULL);
x86_l_1e1:
	/* 0x1e1: jne    2a3 <tail_nodeport_rev_dnat_ingress_ipv6+0x2a3> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1e1, 0x2a3, x86_l_2a3);
x86_l_1e7:
	/* 0x1e7: movzx  eax,BYTE PTR [rsp+0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 1ULL);
x86_l_1ec:
	/* 0x1ec: lea    r12d,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_1f4:
	/* 0x1f4: jmp    324 <tail_nodeport_rev_dnat_ingress_ipv6+0x324> */
	X86_SIM_X86_JMP(0x1f4, 0x324, x86_l_324);
x86_l_1f9:
	/* 0x1f9: cmp    r14,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_64, 59ULL);
x86_l_1fd:
	/* 0x1fd: je     a22 <tail_nodeport_rev_dnat_ingress_ipv6+0xa22> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1fd, 0xa22, x86_l_a22);
x86_l_203:
	/* 0x203: jmp    4ed <tail_nodeport_rev_dnat_ingress_ipv6+0x4ed> */
	X86_SIM_X86_JMP(0x203, 0x4ed, x86_l_4ed);
x86_l_208:
	/* 0x208: mov    r14d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 8ULL);
x86_l_20e:
	/* 0x20e: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_216:
	/* 0x216: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_219:
	/* 0x219: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_21e:
	/* 0x21e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_221:
	/* 0x221: mov    esi,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 40ULL);
x86_l_226:
	/* 0x226: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_22b:
	/* 0x22b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22d:
	/* 0x22d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_22f:
	/* 0x22f: js     a1d <tail_nodeport_rev_dnat_ingress_ipv6+0xa1d> */
	X86_SIM_X86_JCC(X86_CC_S, 0x22f, 0xa1d, x86_l_a1d);
x86_l_235:
	/* 0x235: mov    eax,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_239:
	/* 0x239: movzx  ecx,BYTE PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_23d:
	/* 0x23d: shl    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_241:
	/* 0x241: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_244:
	/* 0x244: movzx  eax,WORD PTR [rsp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_249:
	/* 0x249: movabs rdx,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1099511627776ULL);
x86_l_253:
	/* 0x253: or     rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_256:
	/* 0x256: test   eax,0xf9ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63999ULL);
x86_l_25b:
	/* 0x25b: cmove  rdx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_64, X86_CC_E);
x86_l_25f:
	/* 0x25f: movabs rcx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2199023255552ULL);
x86_l_269:
	/* 0x269: or     rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_OR);
x86_l_26c:
	/* 0x26c: test   eax,0xf8ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63743ULL);
x86_l_271:
	/* 0x271: cmove  rcx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_275:
	/* 0x275: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_278:
	/* 0x278: movzx  r12d,r13b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R13, X86_WIDTH_32, X86_WIDTH_8);
x86_l_27c:
	/* 0x27c: add    esi,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 40ULL);
x86_l_27f:
	/* 0x27f: cmp    r12d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 60ULL);
x86_l_283:
	/* 0x283: jbe    179 <tail_nodeport_rev_dnat_ingress_ipv6+0x179> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x283, 0x179, x86_l_179);
x86_l_289:
	/* 0x289: mov    r14d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R13, X86_WIDTH_32);
x86_l_28c:
	/* 0x28c: jmp    4e6 <tail_nodeport_rev_dnat_ingress_ipv6+0x4e6> */
	X86_SIM_X86_JMP(0x28c, 0x4e6, x86_l_4e6);
x86_l_291:
	/* 0x291: mov    r14d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R13, X86_WIDTH_32);
x86_l_294:
	/* 0x294: jmp    39a <tail_nodeport_rev_dnat_ingress_ipv6+0x39a> */
	X86_SIM_X86_JMP(0x294, 0x39a, x86_l_39a);
x86_l_299:
	/* 0x299: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_29e:
	/* 0x29e: movzx  edx,BYTE PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 56ULL);
x86_l_2a3:
	/* 0x2a3: movzx  eax,BYTE PTR [rsp+0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 1ULL);
x86_l_2a8:
	/* 0x2a8: lea    r12d,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2b0:
	/* 0x2b0: cmp    dl,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_8, 44ULL);
x86_l_2b3:
	/* 0x2b3: je     2bd <tail_nodeport_rev_dnat_ingress_ipv6+0x2bd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2b3, 0x2bd, x86_l_2bd);
x86_l_2b5:
	/* 0x2b5: jmp    324 <tail_nodeport_rev_dnat_ingress_ipv6+0x324> */
	X86_SIM_X86_JMP(0x2b5, 0x324, x86_l_324);
x86_l_2b7:
	/* 0x2b7: mov    r12d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 8ULL);
x86_l_2bd:
	/* 0x2bd: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c5:
	/* 0x2c5: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_2c8:
	/* 0x2c8: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_2cd:
	/* 0x2cd: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2d0:
	/* 0x2d0: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2d5:
	/* 0x2d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d7:
	/* 0x2d7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2d9:
	/* 0x2d9: js     a1d <tail_nodeport_rev_dnat_ingress_ipv6+0xa1d> */
	X86_SIM_X86_JCC(X86_CC_S, 0x2d9, 0xa1d, x86_l_a1d);
x86_l_2df:
	/* 0x2df: mov    eax,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2e3:
	/* 0x2e3: movzx  ecx,BYTE PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2e7:
	/* 0x2e7: shl    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_2eb:
	/* 0x2eb: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2ee:
	/* 0x2ee: movzx  eax,WORD PTR [rsp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_2f3:
	/* 0x2f3: movabs rdx,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1099511627776ULL);
x86_l_2fd:
	/* 0x2fd: or     rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_300:
	/* 0x300: test   eax,0xf9ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63999ULL);
x86_l_305:
	/* 0x305: cmove  rdx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_64, X86_CC_E);
x86_l_309:
	/* 0x309: movabs rcx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2199023255552ULL);
x86_l_313:
	/* 0x313: or     rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_OR);
x86_l_316:
	/* 0x316: test   eax,0xf8ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63743ULL);
x86_l_31b:
	/* 0x31b: cmove  rcx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_31f:
	/* 0x31f: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_324:
	/* 0x324: movzx  r13d,r14b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R13, X86_R14, X86_WIDTH_32, X86_WIDTH_8);
x86_l_328:
	/* 0x328: add    esi,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R12, X86_WIDTH_32, X86_ALU_ADD);
x86_l_32b:
	/* 0x32b: cmp    r13d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 60ULL);
x86_l_32f:
	/* 0x32f: ja     4e6 <tail_nodeport_rev_dnat_ingress_ipv6+0x4e6> */
	X86_SIM_X86_JCC(X86_CC_A, 0x32f, 0x4e6, x86_l_4e6);
x86_l_335:
	/* 0x335: mov    eax,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_338:
	/* 0x338: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_342:
	/* 0x342: bt     rdx,rax */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_346:
	/* 0x346: jae    39a <tail_nodeport_rev_dnat_ingress_ipv6+0x39a> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x346, 0x39a, x86_l_39a);
x86_l_348:
	/* 0x348: mov    r12,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_34b:
	/* 0x34b: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_34e:
	/* 0x34e: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_353:
	/* 0x353: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_356:
	/* 0x356: mov    QWORD PTR [rsp+0x30],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_35b:
	/* 0x35b: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_360:
	/* 0x360: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_362:
	/* 0x362: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_364:
	/* 0x364: js     a1d <tail_nodeport_rev_dnat_ingress_ipv6+0xa1d> */
	X86_SIM_X86_JCC(X86_CC_S, 0x364, 0xa1d, x86_l_a1d);
x86_l_36a:
	/* 0x36a: movzx  edi,BYTE PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_36e:
	/* 0x36e: cmp    r13d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 43ULL);
x86_l_372:
	/* 0x372: mov    rcx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_375:
	/* 0x375: jle    3b0 <tail_nodeport_rev_dnat_ingress_ipv6+0x3b0> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x375, 0x3b0, x86_l_3b0);
x86_l_377:
	/* 0x377: cmp    r13d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 44ULL);
x86_l_37b:
	/* 0x37b: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_380:
	/* 0x380: je     3ca <tail_nodeport_rev_dnat_ingress_ipv6+0x3ca> */
	X86_SIM_X86_JCC(X86_CC_E, 0x380, 0x3ca, x86_l_3ca);
x86_l_382:
	/* 0x382: cmp    r13d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 51ULL);
x86_l_386:
	/* 0x386: jne    3b5 <tail_nodeport_rev_dnat_ingress_ipv6+0x3b5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x386, 0x3b5, x86_l_3b5);
x86_l_388:
	/* 0x388: movzx  eax,BYTE PTR [rsp+0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 1ULL);
x86_l_38d:
	/* 0x38d: lea    r13d,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_395:
	/* 0x395: jmp    43d <tail_nodeport_rev_dnat_ingress_ipv6+0x43d> */
	X86_SIM_X86_JMP(0x395, 0x43d, x86_l_43d);
x86_l_39a:
	/* 0x39a: cmp    rax,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 59ULL);
x86_l_39e:
	/* 0x39e: mov    r13,QWORD PTR [rip+0x1427] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_3a5:
	/* 0x3a5: je     a22 <tail_nodeport_rev_dnat_ingress_ipv6+0xa22> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3a5, 0xa22, x86_l_a22);
x86_l_3ab:
	/* 0x3ab: jmp    4ed <tail_nodeport_rev_dnat_ingress_ipv6+0x4ed> */
	X86_SIM_X86_JMP(0x3ab, 0x4ed, x86_l_4ed);
x86_l_3b0:
	/* 0x3b0: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3b5:
	/* 0x3b5: movzx  eax,BYTE PTR [rsp+0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 1ULL);
x86_l_3ba:
	/* 0x3ba: lea    r13d,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_3c2:
	/* 0x3c2: cmp    r14b,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 44ULL);
x86_l_3c6:
	/* 0x3c6: je     3d0 <tail_nodeport_rev_dnat_ingress_ipv6+0x3d0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3c6, 0x3d0, x86_l_3d0);
x86_l_3c8:
	/* 0x3c8: jmp    43d <tail_nodeport_rev_dnat_ingress_ipv6+0x43d> */
	X86_SIM_X86_JMP(0x3c8, 0x43d, x86_l_43d);
x86_l_3ca:
	/* 0x3ca: mov    r13d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 8ULL);
x86_l_3d0:
	/* 0x3d0: mov    r14d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_32);
x86_l_3d3:
	/* 0x3d3: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3db:
	/* 0x3db: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_3de:
	/* 0x3de: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_3e3:
	/* 0x3e3: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_3e6:
	/* 0x3e6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3eb:
	/* 0x3eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ed:
	/* 0x3ed: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3ef:
	/* 0x3ef: js     a1d <tail_nodeport_rev_dnat_ingress_ipv6+0xa1d> */
	X86_SIM_X86_JCC(X86_CC_S, 0x3ef, 0xa1d, x86_l_a1d);
x86_l_3f5:
	/* 0x3f5: mov    eax,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3f9:
	/* 0x3f9: movzx  ecx,BYTE PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_3fd:
	/* 0x3fd: shl    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_401:
	/* 0x401: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_404:
	/* 0x404: movzx  eax,WORD PTR [rsp+0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 2ULL);
x86_l_409:
	/* 0x409: movabs rdx,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1099511627776ULL);
x86_l_413:
	/* 0x413: or     rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_416:
	/* 0x416: test   eax,0xf9ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63999ULL);
x86_l_41b:
	/* 0x41b: cmove  rdx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_64, X86_CC_E);
x86_l_41f:
	/* 0x41f: movabs rcx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2199023255552ULL);
x86_l_429:
	/* 0x429: or     rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_OR);
x86_l_42c:
	/* 0x42c: test   eax,0xf8ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63743ULL);
x86_l_431:
	/* 0x431: cmove  rcx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_435:
	/* 0x435: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_43a:
	/* 0x43a: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_43d:
	/* 0x43d: movzx  r14d,dil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_RDI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_441:
	/* 0x441: add    esi,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_444:
	/* 0x444: cmp    r14d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 60ULL);
x86_l_448:
	/* 0x448: ja     4e3 <tail_nodeport_rev_dnat_ingress_ipv6+0x4e3> */
	X86_SIM_X86_JCC(X86_CC_A, 0x448, 0x4e3, x86_l_4e3);
x86_l_44e:
	/* 0x44e: mov    eax,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_32);
x86_l_451:
	/* 0x451: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_45b:
	/* 0x45b: bt     rdx,rax */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_45f:
	/* 0x45f: mov    r13,QWORD PTR [rip+0x1427] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_466:
	/* 0x466: jae    4d4 <tail_nodeport_rev_dnat_ingress_ipv6+0x4d4> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x466, 0x4d4, x86_l_4d4);
x86_l_468:
	/* 0x468: mov    r12d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_32);
x86_l_46b:
	/* 0x46b: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_46e:
	/* 0x46e: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_473:
	/* 0x473: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_476:
	/* 0x476: mov    r15,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSI, X86_WIDTH_64);
x86_l_479:
	/* 0x479: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_47e:
	/* 0x47e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_480:
	/* 0x480: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_485:
	/* 0x485: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_487:
	/* 0x487: js     a22 <tail_nodeport_rev_dnat_ingress_ipv6+0xa22> */
	X86_SIM_X86_JCC(X86_CC_S, 0x487, 0xa22, x86_l_a22);
x86_l_48d:
	/* 0x48d: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_490:
	/* 0x490: cmp    r14d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 43ULL);
x86_l_494:
	/* 0x494: jle    4a2 <tail_nodeport_rev_dnat_ingress_ipv6+0x4a2> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x494, 0x4a2, x86_l_4a2);
x86_l_496:
	/* 0x496: cmp    r14d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 44ULL);
x86_l_49a:
	/* 0x49a: je     4a8 <tail_nodeport_rev_dnat_ingress_ipv6+0x4a8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x49a, 0x4a8, x86_l_4a8);
x86_l_49c:
	/* 0x49c: cmp    r14d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 51ULL);
x86_l_4a0:
	/* 0x4a0: je     4ca <tail_nodeport_rev_dnat_ingress_ipv6+0x4ca> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4a0, 0x4ca, x86_l_4ca);
x86_l_4a2:
	/* 0x4a2: cmp    r12b,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_8, 44ULL);
x86_l_4a6:
	/* 0x4a6: jne    4ca <tail_nodeport_rev_dnat_ingress_ipv6+0x4ca> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4a6, 0x4ca, x86_l_4ca);
x86_l_4a8:
	/* 0x4a8: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4b0:
	/* 0x4b0: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_4b3:
	/* 0x4b3: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_4b8:
	/* 0x4b8: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_4bb:
	/* 0x4bb: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4c0:
	/* 0x4c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c2:
	/* 0x4c2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4c4:
	/* 0x4c4: js     a1d <tail_nodeport_rev_dnat_ingress_ipv6+0xa1d> */
	X86_SIM_X86_JCC(X86_CC_S, 0x4c4, 0xa1d, x86_l_a1d);
x86_l_4ca:
	/* 0x4ca: mov    ebp,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967140ULL);
x86_l_4cf:
	/* 0x4cf: jmp    a22 <tail_nodeport_rev_dnat_ingress_ipv6+0xa22> */
	X86_SIM_X86_JMP(0x4cf, 0xa22, x86_l_a22);
x86_l_4d4:
	/* 0x4d4: mov    r14d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_32);
x86_l_4d7:
	/* 0x4d7: cmp    rax,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 59ULL);
x86_l_4db:
	/* 0x4db: je     a22 <tail_nodeport_rev_dnat_ingress_ipv6+0xa22> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4db, 0xa22, x86_l_a22);
x86_l_4e1:
	/* 0x4e1: jmp    4ed <tail_nodeport_rev_dnat_ingress_ipv6+0x4ed> */
	X86_SIM_X86_JMP(0x4e1, 0x4ed, x86_l_4ed);
x86_l_4e3:
	/* 0x4e3: mov    r14d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_32);
x86_l_4e6:
	/* 0x4e6: mov    r13,QWORD PTR [rip+0x1427] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_4ed:
	/* 0x4ed: mov    BYTE PTR [rsp+0x74],r14b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_4f2:
	/* 0x4f2: mov    rax,QWORD PTR [r15+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4f6:
	/* 0x4f6: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_4fb:
	/* 0x4fb: mov    rax,QWORD PTR [r15+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4ff:
	/* 0x4ff: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_504:
	/* 0x504: mov    rax,QWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_508:
	/* 0x508: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_50d:
	/* 0x50d: mov    rax,QWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_511:
	/* 0x511: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_516:
	/* 0x516: cmp    r14b,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 17ULL);
x86_l_51a:
	/* 0x51a: je     529 <tail_nodeport_rev_dnat_ingress_ipv6+0x529> */
	X86_SIM_X86_JCC(X86_CC_E, 0x51a, 0x529, x86_l_529);
x86_l_51c:
	/* 0x51c: movzx  eax,r14b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R14, X86_WIDTH_32, X86_WIDTH_8);
x86_l_520:
	/* 0x520: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_523:
	/* 0x523: jne    120f <tail_nodeport_rev_dnat_ingress_ipv6+0x120f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x523, 0x120f, x86_l_120f);
x86_l_529:
	/* 0x529: movabs rdx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 2199023255552ULL);
x86_l_533:
	/* 0x533: movabs rbp,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 1099511627776ULL);
x86_l_53d:
	/* 0x53d: lea    r12,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_542:
	/* 0x542: mov    rax,QWORD PTR [rip+0x1427] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_549:
	/* 0x549: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_54c:
	/* 0x54c: mov    rax,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RSI, X86_WIDTH_64);
x86_l_54f:
	/* 0x54f: mov    QWORD PTR [rsp+0x30],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_554:
	/* 0x554: je     5ac <tail_nodeport_rev_dnat_ingress_ipv6+0x5ac> */
	X86_SIM_X86_JCC(X86_CC_E, 0x554, 0x5ac, x86_l_5ac);
x86_l_556:
	/* 0x556: mov    r13,QWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_559:
	/* 0x559: mov    QWORD PTR [r15],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_560:
	/* 0x560: mov    DWORD PTR [r15],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_563:
	/* 0x563: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_566:
	/* 0x566: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_56a:
	/* 0x56a: mov    BYTE PTR [r15+0x4],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_56e:
	/* 0x56e: mov    r14,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RCX, X86_WIDTH_64);
x86_l_571:
	/* 0x571: test   rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_574:
	/* 0x574: jne    f23 <tail_nodeport_rev_dnat_ingress_ipv6+0xf23> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x574, 0xf23, x86_l_f23);
x86_l_57a:
	/* 0x57a: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_57f:
	/* 0x57f: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_582:
	/* 0x582: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_585:
	/* 0x585: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_58a:
	/* 0x58a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_58c:
	/* 0x58c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_58e:
	/* 0x58e: js     678 <tail_nodeport_rev_dnat_ingress_ipv6+0x678> */
	X86_SIM_X86_JCC(X86_CC_S, 0x58e, 0x678, x86_l_678);
x86_l_594:
	/* 0x594: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_597:
	/* 0x597: test   r14,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_RBP, X86_WIDTH_64);
x86_l_59a:
	/* 0x59a: jne    f55 <tail_nodeport_rev_dnat_ingress_ipv6+0xf55> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x59a, 0xf55, x86_l_f55);
x86_l_5a0:
	/* 0x5a0: mov    QWORD PTR [r15],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5a3:
	/* 0x5a3: mov    r13,QWORD PTR [rip+0x1427] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_5aa:
	/* 0x5aa: jmp    5d8 <tail_nodeport_rev_dnat_ingress_ipv6+0x5d8> */
	X86_SIM_X86_JMP(0x5aa, 0x5d8, x86_l_5d8);
x86_l_5ac:
	/* 0x5ac: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5af:
	/* 0x5af: test   rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_5b2:
	/* 0x5b2: jne    fc1 <tail_nodeport_rev_dnat_ingress_ipv6+0xfc1> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x5b2, 0xfc1, x86_l_fc1);
x86_l_5b8:
	/* 0x5b8: mov    r14,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RCX, X86_WIDTH_64);
x86_l_5bb:
	/* 0x5bb: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_5c0:
	/* 0x5c0: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_5c3:
	/* 0x5c3: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_5c6:
	/* 0x5c6: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_5cb:
	/* 0x5cb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5cd:
	/* 0x5cd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5cf:
	/* 0x5cf: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_5d2:
	/* 0x5d2: js     685 <tail_nodeport_rev_dnat_ingress_ipv6+0x685> */
	X86_SIM_X86_JCC(X86_CC_S, 0x5d2, 0x685, x86_l_685);
x86_l_5d8:
	/* 0x5d8: movzx  r14d,BYTE PTR [rsp+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 116ULL);
x86_l_5de:
	/* 0x5de: cmp    r14b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 6ULL);
x86_l_5e2:
	/* 0x5e2: jne    5ed <tail_nodeport_rev_dnat_ingress_ipv6+0x5ed> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x5e2, 0x5ed, x86_l_5ed);
x86_l_5e4:
	/* 0x5e4: mov    r15,QWORD PTR [rip+0x1427] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&cilium_ct6_global)));
x86_l_5eb:
	/* 0x5eb: jmp    5f4 <tail_nodeport_rev_dnat_ingress_ipv6+0x5f4> */
	X86_SIM_X86_JMP(0x5eb, 0x5f4, x86_l_5f4);
x86_l_5ed:
	/* 0x5ed: mov    r15,QWORD PTR [rip+0x1427] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&cilium_ct_any6_global)));
x86_l_5f4:
	/* 0x5f4: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5f9:
	/* 0x5f9: movabs r12,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 2199023255552ULL);
x86_l_603:
	/* 0x603: mov    BYTE PTR [rsp+0x75],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 502511173632ULL);
x86_l_608:
	/* 0x608: mov    DWORD PTR [rsp+0x4c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 326417514496ULL);
x86_l_610:
	/* 0x610: mov    rdx,QWORD PTR [rip+0x1427] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_617:
	/* 0x617: cmp    BYTE PTR [rdx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_61a:
	/* 0x61a: je     6c4 <tail_nodeport_rev_dnat_ingress_ipv6+0x6c4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x61a, 0x6c4, x86_l_6c4);
x86_l_620:
	/* 0x620: and    rbp,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_623:
	/* 0x623: je     6c4 <tail_nodeport_rev_dnat_ingress_ipv6+0x6c4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x623, 0x6c4, x86_l_6c4);
x86_l_629:
	/* 0x629: mov    QWORD PTR [rsp+0x38],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_62e:
	/* 0x62e: mov    r15d,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R14, X86_WIDTH_32);
x86_l_631:
	/* 0x631: mov    rbp,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RCX, X86_WIDTH_64);
x86_l_634:
	/* 0x634: mov    r14d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_637:
	/* 0x637: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_640:
	/* 0x640: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_648:
	/* 0x648: movabs rax,0x6c02a30109 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 463900705033ULL);
x86_l_652:
	/* 0x652: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_657:
	/* 0x657: mov    rdi,QWORD PTR [rip+0x1427] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_65e:
	/* 0x65e: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_663:
	/* 0x663: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_668:
	/* 0x668: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_66a:
	/* 0x66a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_66d:
	/* 0x66d: je     68f <tail_nodeport_rev_dnat_ingress_ipv6+0x68f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x66d, 0x68f, x86_l_68f);
x86_l_66f:
	/* 0x66f: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_672:
	/* 0x672: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_676:
	/* 0x676: jmp    6b4 <tail_nodeport_rev_dnat_ingress_ipv6+0x6b4> */
	X86_SIM_X86_JMP(0x676, 0x6b4, x86_l_6b4);
x86_l_678:
	/* 0x678: mov    ebp,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967161ULL);
x86_l_67d:
	/* 0x67d: mov    QWORD PTR [r15],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_680:
	/* 0x680: jmp    a22 <tail_nodeport_rev_dnat_ingress_ipv6+0xa22> */
	X86_SIM_X86_JMP(0x680, 0xa22, x86_l_a22);
x86_l_685:
	/* 0x685: mov    ebp,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967161ULL);
x86_l_68a:
	/* 0x68a: jmp    a25 <tail_nodeport_rev_dnat_ingress_ipv6+0xa25> */
	X86_SIM_X86_JMP(0x68a, 0xa25, x86_l_a25);
x86_l_68f:
	/* 0x68f: mov    QWORD PTR [rsp],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_697:
	/* 0x697: mov    QWORD PTR [rsp+0x8],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_69c:
	/* 0x69c: mov    rdi,QWORD PTR [rip+0x1427] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_6a3:
	/* 0x6a3: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_6a8:
	/* 0x6a8: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_6ab:
	/* 0x6ab: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_6b0:
	/* 0x6b0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6b2:
	/* 0x6b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6b4:
	/* 0x6b4: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6b9:
	/* 0x6b9: mov    rcx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_64);
x86_l_6bc:
	/* 0x6bc: mov    r14d,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R15, X86_WIDTH_32);
x86_l_6bf:
	/* 0x6bf: mov    r15,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_6c4:
	/* 0x6c4: and    rcx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_6c7:
	/* 0x6c7: cmp    r14b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 6ULL);
x86_l_6cb:
	/* 0x6cb: mov    QWORD PTR [rsp+0x38],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_6d0:
	/* 0x6d0: jne    720 <tail_nodeport_rev_dnat_ingress_ipv6+0x720> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x6d0, 0x720, x86_l_720);
x86_l_6d2:
	/* 0x6d2: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_6d5:
	/* 0x6d5: jne    720 <tail_nodeport_rev_dnat_ingress_ipv6+0x720> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x6d5, 0x720, x86_l_720);
x86_l_6d7:
	/* 0x6d7: lea    esi,[rax+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_6da:
	/* 0x6da: lea    rdx,[rsp+0x4c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_6df:
	/* 0x6df: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_6e4:
	/* 0x6e4: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_6e7:
	/* 0x6e7: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_6ec:
	/* 0x6ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6ee:
	/* 0x6ee: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_6f0:
	/* 0x6f0: js     120f <tail_nodeport_rev_dnat_ingress_ipv6+0x120f> */
	X86_SIM_X86_JCC(X86_CC_S, 0x6f0, 0x120f, x86_l_120f);
x86_l_6f6:
	/* 0x6f6: mov    r12d,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R14, X86_WIDTH_32);
x86_l_6f9:
	/* 0x6f9: mov    ebp,DWORD PTR [rsp+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_6fd:
	/* 0x6fd: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_6ff:
	/* 0x6ff: and    eax,0x1200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4608ULL);
x86_l_704:
	/* 0x704: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_707:
	/* 0x707: cmp    eax,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 512ULL);
x86_l_70c:
	/* 0x70c: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_70f:
	/* 0x70f: test   ebp,0x500 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RBP, X86_WIDTH_32, 1280ULL);
x86_l_715:
	/* 0x715: jne    10f8 <tail_nodeport_rev_dnat_ingress_ipv6+0x10f8> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x715, 0x10f8, x86_l_10f8);
x86_l_71b:
	/* 0x71b: mov    r14b,al */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_8);
x86_l_71e:
	/* 0x71e: jmp    72a <tail_nodeport_rev_dnat_ingress_ipv6+0x72a> */
	X86_SIM_X86_JMP(0x71e, 0x72a, x86_l_72a);
x86_l_720:
	/* 0x720: mov    r12d,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R14, X86_WIDTH_32);
x86_l_723:
	/* 0x723: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_726:
	/* 0x726: mov    ebp,DWORD PTR [rsp+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_72a:
	/* 0x72a: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_72f:
	/* 0x72f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_734:
	/* 0x734: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_737:
	/* 0x737: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_739:
	/* 0x739: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_73c:
	/* 0x73c: je     120b <tail_nodeport_rev_dnat_ingress_ipv6+0x120b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x73c, 0x120b, x86_l_120b);
x86_l_742:
	/* 0x742: movzx  ecx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_746:
	/* 0x746: test   cl,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_749:
	/* 0x749: je     120b <tail_nodeport_rev_dnat_ingress_ipv6+0x120b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x749, 0x120b, x86_l_120b);
x86_l_74f:
	/* 0x74f: cmp    WORD PTR [rax+0x26],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 163208757248ULL);
x86_l_754:
	/* 0x754: je     120b <tail_nodeport_rev_dnat_ingress_ipv6+0x120b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x754, 0x120b, x86_l_120b);
x86_l_75a:
	/* 0x75a: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_75c:
	/* 0x75c: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_75e:
	/* 0x75e: test   dl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_8, 3ULL);
x86_l_761:
	/* 0x761: je     869 <tail_nodeport_rev_dnat_ingress_ipv6+0x869> */
	X86_SIM_X86_JCC(X86_CC_E, 0x761, 0x869, x86_l_869);
x86_l_767:
	/* 0x767: mov    rsi,QWORD PTR [rip+0x1427] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_76e:
	/* 0x76e: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_771:
	/* 0x771: je     784 <tail_nodeport_rev_dnat_ingress_ipv6+0x784> */
	X86_SIM_X86_JCC(X86_CC_E, 0x771, 0x784, x86_l_784);
x86_l_773:
	/* 0x773: mov    rdx,QWORD PTR [rip+0x1427] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_77a:
	/* 0x77a: imul   r15d,DWORD PTR [rdx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R15, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_77e:
	/* 0x77e: shr    r15d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_782:
	/* 0x782: jmp    78a <tail_nodeport_rev_dnat_ingress_ipv6+0x78a> */
	X86_SIM_X86_JMP(0x782, 0x78a, x86_l_78a);
x86_l_784:
	/* 0x784: mov    r15d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 60ULL);
x86_l_78a:
	/* 0x78a: cmp    r12b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_8, 6ULL);
x86_l_78e:
	/* 0x78e: jne    7c6 <tail_nodeport_rev_dnat_ingress_ipv6+0x7c6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x78e, 0x7c6, x86_l_7c6);
x86_l_790:
	/* 0x790: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_792:
	/* 0x792: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_794:
	/* 0x794: shr    edx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_797:
	/* 0x797: and    edx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_79a:
	/* 0x79a: or     ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_79c:
	/* 0x79c: mov    WORD PTR [rax+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_7a0:
	/* 0x7a0: test   cl,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 16ULL);
x86_l_7a3:
	/* 0x7a3: mov    ecx,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 60ULL);
x86_l_7a8:
	/* 0x7a8: mov    r15d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 21600ULL);
x86_l_7ae:
	/* 0x7ae: cmove  r15d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R15, X86_RCX, X86_WIDTH_32, X86_CC_E);
x86_l_7b2:
	/* 0x7b2: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7b5:
	/* 0x7b5: je     7c6 <tail_nodeport_rev_dnat_ingress_ipv6+0x7c6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7b5, 0x7c6, x86_l_7c6);
x86_l_7b7:
	/* 0x7b7: mov    rcx,QWORD PTR [rip+0x1427] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_7be:
	/* 0x7be: imul   r15d,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_7c2:
	/* 0x7c2: shr    r15d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_7c6:
	/* 0x7c6: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_7ce:
	/* 0x7ce: mov    r13d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBP, X86_WIDTH_32);
x86_l_7d1:
	/* 0x7d1: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_7d5:
	/* 0x7d5: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7d8:
	/* 0x7d8: je     7ec <tail_nodeport_rev_dnat_ingress_ipv6+0x7ec> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7d8, 0x7ec, x86_l_7ec);
x86_l_7da:
	/* 0x7da: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_7df:
	/* 0x7df: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7e1:
	/* 0x7e1: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_7e3:
	/* 0x7e3: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_7e6:
	/* 0x7e6: shr    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_7ea:
	/* 0x7ea: jmp    80f <tail_nodeport_rev_dnat_ingress_ipv6+0x80f> */
	X86_SIM_X86_JMP(0x7ea, 0x80f, x86_l_80f);
x86_l_7ec:
	/* 0x7ec: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_7f1:
	/* 0x7f1: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7f3:
	/* 0x7f3: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_7f5:
	/* 0x7f5: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_7f9:
	/* 0x7f9: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_803:
	/* 0x803: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_806:
	/* 0x806: mulx   rcx,rcx,rcx */
	X86_SIM_L_EXEC_MULX(X86_RCX, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_80b:
	/* 0x80b: shr    rcx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_80f:
	/* 0x80f: add    r15d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_812:
	/* 0x812: mov    rax,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_81a:
	/* 0x81a: mov    DWORD PTR [rax+0x20],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_81e:
	/* 0x81e: movzx  edx,BYTE PTR [rax+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_822:
	/* 0x822: mov    esi,DWORD PTR [rax+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_825:
	/* 0x825: and    r13b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_829:
	/* 0x829: mov    rdi,QWORD PTR [rip+0x1427] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_830:
	/* 0x830: cmp    BYTE PTR [rdi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_833:
	/* 0x833: je     846 <tail_nodeport_rev_dnat_ingress_ipv6+0x846> */
	X86_SIM_X86_JCC(X86_CC_E, 0x833, 0x846, x86_l_846);
x86_l_835:
	/* 0x835: mov    rdi,QWORD PTR [rip+0x1427] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_83c:
	/* 0x83c: mov    edi,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_83e:
	/* 0x83e: lea    edi,[rdi+rdi*4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_841:
	/* 0x841: shr    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_844:
	/* 0x844: jmp    84b <tail_nodeport_rev_dnat_ingress_ipv6+0x84b> */
	X86_SIM_X86_JMP(0x844, 0x84b, x86_l_84b);
x86_l_846:
	/* 0x846: mov    edi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 5ULL);
x86_l_84b:
	/* 0x84b: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_84d:
	/* 0x84d: or     r13b,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_850:
	/* 0x850: cmp    edi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RCX, X86_WIDTH_32);
x86_l_852:
	/* 0x852: jb     859 <tail_nodeport_rev_dnat_ingress_ipv6+0x859> */
	X86_SIM_X86_JCC(X86_CC_B, 0x852, 0x859, x86_l_859);
x86_l_854:
	/* 0x854: cmp    dl,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_8);
x86_l_857:
	/* 0x857: je     869 <tail_nodeport_rev_dnat_ingress_ipv6+0x869> */
	X86_SIM_X86_JCC(X86_CC_E, 0x857, 0x869, x86_l_869);
x86_l_859:
	/* 0x859: mov    BYTE PTR [rax+0x2b],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_85d:
	/* 0x85d: mov    DWORD PTR [rax+0x34],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_860:
	/* 0x860: mov    rcx,QWORD PTR [rip+0x1427] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_867:
	/* 0x867: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_869:
	/* 0x869: mov    rcx,QWORD PTR [rip+0x1427] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_870:
	/* 0x870: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_873:
	/* 0x873: je     881 <tail_nodeport_rev_dnat_ingress_ipv6+0x881> */
	X86_SIM_X86_JCC(X86_CC_E, 0x873, 0x881, x86_l_881);
x86_l_875:
	/* 0x875: inc QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 16ULL);
x86_l_87a:
	/* 0x87a: mov    ecx,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_87c:
	/* 0x87c: add QWORD PTR [rax+0x18],rcx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_881:
	/* 0x881: cmp    r14d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 2ULL);
x86_l_885:
	/* 0x885: mov    r13,QWORD PTR [rip+0x1427] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_88c:
	/* 0x88c: je     8dd <tail_nodeport_rev_dnat_ingress_ipv6+0x8dd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x88c, 0x8dd, x86_l_8dd);
x86_l_88e:
	/* 0x88e: cmp    r14d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1ULL);
x86_l_892:
	/* 0x892: jne    9b7 <tail_nodeport_rev_dnat_ingress_ipv6+0x9b7> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x892, 0x9b7, x86_l_9b7);
x86_l_898:
	/* 0x898: movzx  ecx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_89c:
	/* 0x89c: test   cl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_89f:
	/* 0x89f: je     9b7 <tail_nodeport_rev_dnat_ingress_ipv6+0x9b7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x89f, 0x9b7, x86_l_9b7);
x86_l_8a5:
	/* 0x8a5: mov    WORD PTR [rax+0x2a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 180388626432ULL);
x86_l_8ab:
	/* 0x8ab: and    ecx,0xffec */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 65516ULL);
x86_l_8b1:
	/* 0x8b1: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_8b4:
	/* 0x8b4: mov    WORD PTR [rax+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_8b8:
	/* 0x8b8: mov    r15,QWORD PTR [rip+0x1427] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_8bf:
	/* 0x8bf: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8c3:
	/* 0x8c3: je     113d <tail_nodeport_rev_dnat_ingress_ipv6+0x113d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8c3, 0x113d, x86_l_113d);
x86_l_8c9:
	/* 0x8c9: mov    rax,QWORD PTR [rip+0x1427] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_8d0:
	/* 0x8d0: imul   r13d,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_8d4:
	/* 0x8d4: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_8d8:
	/* 0x8d8: jmp    1143 <tail_nodeport_rev_dnat_ingress_ipv6+0x1143> */
	X86_SIM_X86_JMP(0x8d8, 0x1143, x86_l_1143);
x86_l_8dd:
	/* 0x8dd: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_8df:
	/* 0x8df: shr    ecx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_8e2:
	/* 0x8e2: and    ecx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2ULL);
x86_l_8e5:
	/* 0x8e5: or     cx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RAX, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 36ULL);
x86_l_8e9:
	/* 0x8e9: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_8eb:
	/* 0x8eb: or     edx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_OR, 1ULL);
x86_l_8ee:
	/* 0x8ee: mov    WORD PTR [rax+0x24],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_8f2:
	/* 0x8f2: mov    edx,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8f6:
	/* 0x8f6: test   cl,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_8f9:
	/* 0x8f9: je     9b7 <tail_nodeport_rev_dnat_ingress_ipv6+0x9b7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8f9, 0x9b7, x86_l_9b7);
x86_l_8ff:
	/* 0x8ff: mov    r14,QWORD PTR [rip+0x1427] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_906:
	/* 0x906: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_90a:
	/* 0x90a: je     921 <tail_nodeport_rev_dnat_ingress_ipv6+0x921> */
	X86_SIM_X86_JCC(X86_CC_E, 0x90a, 0x921, x86_l_921);
x86_l_90c:
	/* 0x90c: mov    rcx,QWORD PTR [rip+0x1427] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_913:
	/* 0x913: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_915:
	/* 0x915: add    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_917:
	/* 0x917: lea    r15d,[rcx+rcx*4] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 0ULL);
x86_l_91b:
	/* 0x91b: shr    r15d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_91f:
	/* 0x91f: jmp    927 <tail_nodeport_rev_dnat_ingress_ipv6+0x927> */
	X86_SIM_X86_JMP(0x91f, 0x927, x86_l_927);
x86_l_921:
	/* 0x921: mov    r15d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 10ULL);
x86_l_927:
	/* 0x927: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_92a:
	/* 0x92a: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_92d:
	/* 0x92d: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_931:
	/* 0x931: je     945 <tail_nodeport_rev_dnat_ingress_ipv6+0x945> */
	X86_SIM_X86_JCC(X86_CC_E, 0x931, 0x945, x86_l_945);
x86_l_933:
	/* 0x933: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_938:
	/* 0x938: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_93a:
	/* 0x93a: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_93c:
	/* 0x93c: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_93f:
	/* 0x93f: shr    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_943:
	/* 0x943: jmp    968 <tail_nodeport_rev_dnat_ingress_ipv6+0x968> */
	X86_SIM_X86_JMP(0x943, 0x968, x86_l_968);
x86_l_945:
	/* 0x945: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_94a:
	/* 0x94a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_94c:
	/* 0x94c: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_94e:
	/* 0x94e: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_952:
	/* 0x952: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_95c:
	/* 0x95c: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_95f:
	/* 0x95f: mulx   rcx,rcx,rcx */
	X86_SIM_L_EXEC_MULX(X86_RCX, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_964:
	/* 0x964: shr    rcx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_968:
	/* 0x968: add    r15d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_96b:
	/* 0x96b: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_96e:
	/* 0x96e: mov    DWORD PTR [r12+0x20],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_973:
	/* 0x973: movzx  edx,BYTE PTR [r12+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_979:
	/* 0x979: mov    esi,DWORD PTR [r12+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_97e:
	/* 0x97e: and    bpl,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_982:
	/* 0x982: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_986:
	/* 0x986: je     999 <tail_nodeport_rev_dnat_ingress_ipv6+0x999> */
	X86_SIM_X86_JCC(X86_CC_E, 0x986, 0x999, x86_l_999);
x86_l_988:
	/* 0x988: mov    rdi,QWORD PTR [rip+0x1427] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_98f:
	/* 0x98f: mov    edi,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_991:
	/* 0x991: lea    edi,[rdi+rdi*4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_994:
	/* 0x994: shr    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_997:
	/* 0x997: jmp    99e <tail_nodeport_rev_dnat_ingress_ipv6+0x99e> */
	X86_SIM_X86_JMP(0x997, 0x99e, x86_l_99e);
x86_l_999:
	/* 0x999: mov    edi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 5ULL);
x86_l_99e:
	/* 0x99e: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_9a0:
	/* 0x9a0: or     bpl,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_9a3:
	/* 0x9a3: cmp    edi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RCX, X86_WIDTH_32);
x86_l_9a5:
	/* 0x9a5: jb     9ac <tail_nodeport_rev_dnat_ingress_ipv6+0x9ac> */
	X86_SIM_X86_JCC(X86_CC_B, 0x9a5, 0x9ac, x86_l_9ac);
x86_l_9a7:
	/* 0x9a7: cmp    dl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBP, X86_WIDTH_8);
x86_l_9aa:
	/* 0x9aa: je     9b7 <tail_nodeport_rev_dnat_ingress_ipv6+0x9b7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9aa, 0x9b7, x86_l_9b7);
x86_l_9ac:
	/* 0x9ac: mov    BYTE PTR [rax+0x2b],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_9b0:
	/* 0x9b0: mov    DWORD PTR [rax+0x34],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_9b3:
	/* 0x9b3: mov    ecx,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9b7:
	/* 0x9b7: test   BYTE PTR [rsp+0x75],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 502511173634ULL);
x86_l_9bc:
	/* 0x9bc: mov    r12,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_9c1:
	/* 0x9c1: jne    120f <tail_nodeport_rev_dnat_ingress_ipv6+0x120f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x9c1, 0x120f, x86_l_120f);
x86_l_9c7:
	/* 0x9c7: movzx  ebp,WORD PTR [rax+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_9cb:
	/* 0x9cb: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_9ce:
	/* 0x9ce: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_9d3:
	/* 0x9d3: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_9d6:
	/* 0x9d6: mov    esi,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 7ULL);
x86_l_9db:
	/* 0x9db: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_9e0:
	/* 0x9e0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9e2:
	/* 0x9e2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_9e4:
	/* 0x9e4: js     a1d <tail_nodeport_rev_dnat_ingress_ipv6+0xa1d> */
	X86_SIM_X86_JCC(X86_CC_S, 0x9e4, 0xa1d, x86_l_a1d);
x86_l_9e6:
	/* 0x9e6: movzx  eax,BYTE PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_9ea:
	/* 0x9ea: cmp    al,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 2ULL);
x86_l_9ec:
	/* 0x9ec: jae    ad3 <tail_nodeport_rev_dnat_ingress_ipv6+0xad3> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x9ec, 0xad3, x86_l_ad3);
x86_l_9f2:
	/* 0x9f2: movabs rax,0x200000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934592ULL);
x86_l_9fc:
	/* 0x9fc: mov    QWORD PTR [rbx+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a00:
	/* 0xa00: mov    rsi,QWORD PTR [rip+0x1427] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_a07:
	/* 0xa07: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_a0c:
	/* 0xa0c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_a0f:
	/* 0xa0f: mov    edx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_a14:
	/* 0xa14: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a16:
	/* 0xa16: mov    ebp,0xffffff74 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967156ULL);
x86_l_a1b:
	/* 0xa1b: jmp    a22 <tail_nodeport_rev_dnat_ingress_ipv6+0xa22> */
	X86_SIM_X86_JMP(0xa1b, 0xa22, x86_l_a22);
x86_l_a1d:
	/* 0xa1d: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_a22:
	/* 0xa22: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a25:
	/* 0xa25: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_a27:
	/* 0xa27: neg    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_a29:
	/* 0xa29: cmovs  eax,ebp */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RBP, X86_WIDTH_32, X86_CC_S);
x86_l_a2c:
	/* 0xa2c: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_a2f:
	/* 0xa2f: mov    QWORD PTR [rbx+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_a37:
	/* 0xa37: or     eax,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_32, X86_ALU_OR);
x86_l_a3a:
	/* 0xa3a: mov    DWORD PTR [rbx+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_a3d:
	/* 0xa3d: movabs rcx,0x453680200000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 311707157017919488ULL);
x86_l_a47:
	/* 0xa47: mov    QWORD PTR [rbx+0x3c],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_a4b:
	/* 0xa4b: mov    r14d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a4e:
	/* 0xa4e: movabs rcx,0x6804530200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 446749147648ULL);
x86_l_a58:
	/* 0xa58: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a5c:
	/* 0xa5c: mov    BYTE PTR [rsp],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a5f:
	/* 0xa5f: mov    rdi,QWORD PTR [rip+0x1427] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_a66:
	/* 0xa66: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_a69:
	/* 0xa69: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a6e:
	/* 0xa6e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a70:
	/* 0xa70: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a73:
	/* 0xa73: je     a7e <tail_nodeport_rev_dnat_ingress_ipv6+0xa7e> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa73, 0xa7e, x86_l_a7e);
x86_l_a75:
	/* 0xa75: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_a78:
	/* 0xa78: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_a7c:
	/* 0xa7c: jmp    aa7 <tail_nodeport_rev_dnat_ingress_ipv6+0xaa7> */
	X86_SIM_X86_JMP(0xa7c, 0xaa7, x86_l_aa7);
x86_l_a7e:
	/* 0xa7e: mov    QWORD PTR [rsp+0x78],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075521ULL);
x86_l_a87:
	/* 0xa87: mov    QWORD PTR [rsp+0x80],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_a8f:
	/* 0xa8f: mov    rdi,QWORD PTR [rip+0x1427] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_a96:
	/* 0xa96: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_a99:
	/* 0xa99: lea    rdx,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_a9e:
	/* 0xa9e: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_aa3:
	/* 0xaa3: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_aa5:
	/* 0xaa5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aa7:
	/* 0xaa7: mov    rsi,QWORD PTR [rip+0x1427] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_aae:
	/* 0xaae: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_ab3:
	/* 0xab3: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_ab6:
	/* 0xab6: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_abb:
	/* 0xabb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_abd:
	/* 0xabd: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_ac2:
	/* 0xac2: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_ac4:
	/* 0xac4: add    rsp,0xc8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 200ULL);
x86_l_acb:
	/* 0xacb: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_acd:
	/* 0xacd: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_ace:
	/* 0xace: jmp    1258 <tail_nodeport_rev_dnat_ingress_ipv6+0x1258> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_ad3:
	/* 0xad3: dec    al */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_DEC, 1);
x86_l_ad5:
	/* 0xad5: mov    BYTE PTR [rsp],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ad8:
	/* 0xad8: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_adb:
	/* 0xadb: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_ae0:
	/* 0xae0: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_ae3:
	/* 0xae3: mov    esi,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 7ULL);
x86_l_ae8:
	/* 0xae8: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_aed:
	/* 0xaed: mov    r8d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 1ULL);
x86_l_af3:
	/* 0xaf3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_af5:
	/* 0xaf5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_af7:
	/* 0xaf7: js     dd9 <tail_nodeport_rev_dnat_ingress_ipv6+0xdd9> */
	X86_SIM_X86_JCC(X86_CC_S, 0xaf7, 0xdd9, x86_l_dd9);
x86_l_afd:
	/* 0xafd: mov    WORD PTR [rsp],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b01:
	/* 0xb01: mov    r14,QWORD PTR [rip+0x142a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_b08:
	/* 0xb08: movzx  eax,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_b0c:
	/* 0xb0c: mov    rdi,QWORD PTR [rip+0x142a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb6_reverse_nat)));
x86_l_b13:
	/* 0xb13: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_b16:
	/* 0xb16: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b1b:
	/* 0xb1b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b1d:
	/* 0xb1d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b20:
	/* 0xb20: je     cdc <tail_nodeport_rev_dnat_ingress_ipv6+0xcdc> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb20, 0xcdc, x86_l_cdc);
x86_l_b26:
	/* 0xb26: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_b29:
	/* 0xb29: movzx  eax,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_b2d:
	/* 0xb2d: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_b32:
	/* 0xb32: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_b37:
	/* 0xb37: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b3c:
	/* 0xb3c: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b40:
	/* 0xb40: mov    rax,QWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b44:
	/* 0xb44: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_b49:
	/* 0xb49: mov    rax,QWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b4c:
	/* 0xb4c: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_b51:
	/* 0xb51: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_b56:
	/* 0xb56: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_b59:
	/* 0xb59: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b5e:
	/* 0xb5e: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_b61:
	/* 0xb61: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_b66:
	/* 0xb66: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b69:
	/* 0xb69: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b6b:
	/* 0xb6b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b6d:
	/* 0xb6d: sets   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_S);
x86_l_b70:
	/* 0xb70: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_b73:
	/* 0xb73: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_b76:
	/* 0xb76: or     al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_b78:
	/* 0xb78: jne    b9e <tail_nodeport_rev_dnat_ingress_ipv6+0xb9e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb78, 0xb9e, x86_l_b9e);
x86_l_b7a:
	/* 0xb7a: test   r12,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_64);
x86_l_b7d:
	/* 0xb7d: jne    b9e <tail_nodeport_rev_dnat_ingress_ipv6+0xb9e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb7d, 0xb9e, x86_l_b9e);
x86_l_b7f:
	/* 0xb7f: movzx  eax,BYTE PTR [rsp+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 116ULL);
x86_l_b84:
	/* 0xb84: cmp    eax,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 58ULL);
x86_l_b87:
	/* 0xb87: je     bc8 <tail_nodeport_rev_dnat_ingress_ipv6+0xbc8> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb87, 0xbc8, x86_l_bc8);
x86_l_b89:
	/* 0xb89: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_b8c:
	/* 0xb8c: je     bb5 <tail_nodeport_rev_dnat_ingress_ipv6+0xbb5> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb8c, 0xbb5, x86_l_bb5);
x86_l_b8e:
	/* 0xb8e: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_b91:
	/* 0xb91: jne    bd3 <tail_nodeport_rev_dnat_ingress_ipv6+0xbd3> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb91, 0xbd3, x86_l_bd3);
x86_l_b93:
	/* 0xb93: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b96:
	/* 0xb96: mov    r12d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 16ULL);
x86_l_b9c:
	/* 0xb9c: jmp    bd9 <tail_nodeport_rev_dnat_ingress_ipv6+0xbd9> */
	X86_SIM_X86_JMP(0xb9c, 0xbd9, x86_l_bd9);
x86_l_b9e:
	/* 0xb9e: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_ba0:
	/* 0xba0: jne    1239 <tail_nodeport_rev_dnat_ingress_ipv6+0x1239> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xba0, 0x1239, x86_l_1239);
x86_l_ba6:
	/* 0xba6: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ba8:
	/* 0xba8: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_baa:
	/* 0xbaa: je     cdc <tail_nodeport_rev_dnat_ingress_ipv6+0xcdc> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbaa, 0xcdc, x86_l_cdc);
x86_l_bb0:
	/* 0xbb0: jmp    10c6 <tail_nodeport_rev_dnat_ingress_ipv6+0x10c6> */
	X86_SIM_X86_JMP(0xbb0, 0x10c6, x86_l_10c6);
x86_l_bb5:
	/* 0xbb5: mov    DWORD PTR [rsp+0x38],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168608ULL);
x86_l_bbd:
	/* 0xbbd: mov    r12d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 6ULL);
x86_l_bc3:
	/* 0xbc3: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bc6:
	/* 0xbc6: jmp    be1 <tail_nodeport_rev_dnat_ingress_ipv6+0xbe1> */
	X86_SIM_X86_JMP(0xbc6, 0xbe1, x86_l_be1);
x86_l_bc8:
	/* 0xbc8: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bcb:
	/* 0xbcb: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_bd1:
	/* 0xbd1: jmp    bd9 <tail_nodeport_rev_dnat_ingress_ipv6+0xbd9> */
	X86_SIM_X86_JMP(0xbd1, 0xbd9, x86_l_bd9);
x86_l_bd3:
	/* 0xbd3: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bd6:
	/* 0xbd6: mov    r14b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_8, 1ULL);
x86_l_bd9:
	/* 0xbd9: mov    DWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_be1:
	/* 0xbe1: movzx  ecx,WORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_be6:
	/* 0xbe6: test   cx,cx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_16);
x86_l_be9:
	/* 0xbe9: je     c77 <tail_nodeport_rev_dnat_ingress_ipv6+0xc77> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbe9, 0xc77, x86_l_c77);
x86_l_bef:
	/* 0xbef: movzx  r13d,WORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 112ULL);
x86_l_bf5:
	/* 0xbf5: mov    ebp,0xffffff72 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967154ULL);
x86_l_bfa:
	/* 0xbfa: cmp    eax,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_bfd:
	/* 0xbfd: jg     c0e <tail_nodeport_rev_dnat_ingress_ipv6+0xc0e> */
	X86_SIM_X86_JCC(X86_CC_G, 0xbfd, 0xc0e, x86_l_c0e);
x86_l_bff:
	/* 0xbff: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c02:
	/* 0xc02: je     c77 <tail_nodeport_rev_dnat_ingress_ipv6+0xc77> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc02, 0xc77, x86_l_c77);
x86_l_c04:
	/* 0xc04: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_c07:
	/* 0xc07: je     c1c <tail_nodeport_rev_dnat_ingress_ipv6+0xc1c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc07, 0xc1c, x86_l_c1c);
x86_l_c09:
	/* 0xc09: jmp    a22 <tail_nodeport_rev_dnat_ingress_ipv6+0xa22> */
	X86_SIM_X86_JMP(0xc09, 0xa22, x86_l_a22);
x86_l_c0e:
	/* 0xc0e: cmp    eax,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 58ULL);
x86_l_c11:
	/* 0xc11: je     c77 <tail_nodeport_rev_dnat_ingress_ipv6+0xc77> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc11, 0xc77, x86_l_c77);
x86_l_c13:
	/* 0xc13: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_c16:
	/* 0xc16: jne    a22 <tail_nodeport_rev_dnat_ingress_ipv6+0xa22> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xc16, 0xa22, x86_l_a22);
x86_l_c1c:
	/* 0xc1c: cmp    cx,r13w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R13, X86_WIDTH_16);
x86_l_c20:
	/* 0xc20: je     c77 <tail_nodeport_rev_dnat_ingress_ipv6+0xc77> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc20, 0xc77, x86_l_c77);
x86_l_c22:
	/* 0xc22: mov    WORD PTR [rsp+0x40],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_c27:
	/* 0xc27: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_c2c:
	/* 0xc2c: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_c31:
	/* 0xc31: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_c34:
	/* 0xc34: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c39:
	/* 0xc39: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_c3e:
	/* 0xc3e: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c41:
	/* 0xc41: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c43:
	/* 0xc43: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c45:
	/* 0xc45: js     dd9 <tail_nodeport_rev_dnat_ingress_ipv6+0xdd9> */
	X86_SIM_X86_JCC(X86_CC_S, 0xc45, 0xdd9, x86_l_dd9);
x86_l_c4b:
	/* 0xc4b: movzx  ecx,WORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 64ULL);
x86_l_c50:
	/* 0xc50: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c55:
	/* 0xc55: lea    esi,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_c59:
	/* 0xc59: mov    r8d,DWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_c5e:
	/* 0xc5e: or     r8d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_c62:
	/* 0xc62: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_c67:
	/* 0xc67: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_c6a:
	/* 0xc6a: mov    edx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_32);
x86_l_c6d:
	/* 0xc6d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c6f:
	/* 0xc6f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c71:
	/* 0xc71: js     f08 <tail_nodeport_rev_dnat_ingress_ipv6+0xf08> */
	X86_SIM_X86_JCC(X86_CC_S, 0xc71, 0xf08, x86_l_f08);
x86_l_c77:
	/* 0xc77: test   r14b,r14b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_8);
x86_l_c7a:
	/* 0xc7a: jne    cdc <tail_nodeport_rev_dnat_ingress_ipv6+0xcdc> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xc7a, 0xcdc, x86_l_cdc);
x86_l_c7c:
	/* 0xc7c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_c7f:
	/* 0xc7f: mov    eax,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_c84:
	/* 0xc84: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_c89:
	/* 0xc89: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_c8c:
	/* 0xc8c: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_c91:
	/* 0xc91: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c94:
	/* 0xc94: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c96:
	/* 0xc96: mov    ebp,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_c98:
	/* 0xc98: add    r12d,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_c9d:
	/* 0xc9d: mov    r15d,DWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_ca2:
	/* 0xca2: mov    r8d,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R15, X86_WIDTH_32);
x86_l_ca5:
	/* 0xca5: or     r8d,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 144ULL);
x86_l_cac:
	/* 0xcac: mov    r14d,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 11ULL);
x86_l_cb2:
	/* 0xcb2: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_cb5:
	/* 0xcb5: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_cb8:
	/* 0xcb8: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_cba:
	/* 0xcba: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_cbc:
	/* 0xcbc: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_cbf:
	/* 0xcbf: cmp    eax,0xffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967274ULL);
x86_l_cc2:
	/* 0xcc2: jne    cd4 <tail_nodeport_rev_dnat_ingress_ipv6+0xcd4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xcc2, 0xcd4, x86_l_cd4);
x86_l_cc4:
	/* 0xcc4: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_cc7:
	/* 0xcc7: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_cca:
	/* 0xcca: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ccc:
	/* 0xccc: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_cce:
	/* 0xcce: mov    r8d,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R15, X86_WIDTH_32);
x86_l_cd1:
	/* 0xcd1: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_cd4:
	/* 0xcd4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_cd6:
	/* 0xcd6: js     f08 <tail_nodeport_rev_dnat_ingress_ipv6+0xf08> */
	X86_SIM_X86_JCC(X86_CC_S, 0xcd6, 0xf08, x86_l_f08);
x86_l_cdc:
	/* 0xcdc: mov    r14d,DWORD PTR [rbx+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_ce0:
	/* 0xce0: mov    eax,DWORD PTR [rbx+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_ce3:
	/* 0xce3: lea    rcx,[r14+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_ce7:
	/* 0xce7: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_cec:
	/* 0xcec: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_cef:
	/* 0xcef: cmp    rcx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_cf2:
	/* 0xcf2: ja     a25 <tail_nodeport_rev_dnat_ingress_ipv6+0xa25> */
	X86_SIM_X86_JCC(X86_CC_A, 0xcf2, 0xa25, x86_l_a25);
x86_l_cf8:
	/* 0xcf8: mov    eax,0xfffff0ff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294963455ULL);
x86_l_cfd:
	/* 0xcfd: and    eax,DWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 8ULL);
x86_l_d00:
	/* 0xd00: or     eax,0x300 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 768ULL);
x86_l_d05:
	/* 0xd05: mov    DWORD PTR [rbx+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d08:
	/* 0xd08: mov    WORD PTR [rsp+0x6],0x200 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 25769804288ULL);
x86_l_d0f:
	/* 0xd0f: mov    DWORD PTR [rsp],0xa0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_d16:
	/* 0xd16: mov    rax,QWORD PTR [r14+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d1a:
	/* 0xd1a: mov    rcx,QWORD PTR [r14+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d1e:
	/* 0xd1e: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d23:
	/* 0xd23: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d28:
	/* 0xd28: mov    WORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_d2f:
	/* 0xd2f: mov    rdi,QWORD PTR [rip+0x142a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipcache_v2)));
x86_l_d36:
	/* 0xd36: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_d39:
	/* 0xd39: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d3e:
	/* 0xd3e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d40:
	/* 0xd40: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d43:
	/* 0xd43: je     de3 <tail_nodeport_rev_dnat_ingress_ipv6+0xde3> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd43, 0xde3, x86_l_de3);
x86_l_d49:
	/* 0xd49: movzx  ecx,BYTE PTR [rax+0x17] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 23ULL);
x86_l_d4d:
	/* 0xd4d: and    cl,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 3ULL);
x86_l_d50:
	/* 0xd50: cmp    cl,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_d53:
	/* 0xd53: jne    de3 <tail_nodeport_rev_dnat_ingress_ipv6+0xde3> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xd53, 0xde3, x86_l_de3);
x86_l_d59:
	/* 0xd59: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_d5c:
	/* 0xd5c: mov    r12d,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d60:
	/* 0xd60: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d63:
	/* 0xd63: mov    eax,0x2b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_d68:
	/* 0xd68: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_d6b:
	/* 0xd6b: mov    esi,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 14ULL);
x86_l_d70:
	/* 0xd70: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d72:
	/* 0xd72: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d74:
	/* 0xd74: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_d76:
	/* 0xd76: jne    a25 <tail_nodeport_rev_dnat_ingress_ipv6+0xa25> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xd76, 0xa25, x86_l_a25);
x86_l_d7c:
	/* 0xd7c: mov    WORD PTR [rsp],r12w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d81:
	/* 0xd81: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_d84:
	/* 0xd84: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_d89:
	/* 0xd89: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_d8c:
	/* 0xd8c: mov    esi,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 12ULL);
x86_l_d91:
	/* 0xd91: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_d96:
	/* 0xd96: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d99:
	/* 0xd99: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d9b:
	/* 0xd9b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_d9d:
	/* 0xd9d: js     dd9 <tail_nodeport_rev_dnat_ingress_ipv6+0xdd9> */
	X86_SIM_X86_JCC(X86_CC_S, 0xd9d, 0xdd9, x86_l_dd9);
x86_l_d9f:
	/* 0xd9f: mov    r15d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_da2:
	/* 0xda2: movabs rax,0x6f00220200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 476743598592ULL);
x86_l_dac:
	/* 0xdac: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_db1:
	/* 0xdb1: mov    rdi,QWORD PTR [rip+0x142a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_db8:
	/* 0xdb8: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_dbd:
	/* 0xdbd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_dc2:
	/* 0xdc2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dc4:
	/* 0xdc4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_dc7:
	/* 0xdc7: je     fcb <tail_nodeport_rev_dnat_ingress_ipv6+0xfcb> */
	X86_SIM_X86_JCC(X86_CC_E, 0xdc7, 0xfcb, x86_l_fcb);
x86_l_dcd:
	/* 0xdcd: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_dd0:
	/* 0xdd0: add    QWORD PTR [rax+0x8],r15 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_dd4:
	/* 0xdd4: jmp    ff0 <tail_nodeport_rev_dnat_ingress_ipv6+0xff0> */
	X86_SIM_X86_JMP(0xdd4, 0xff0, x86_l_ff0);
x86_l_dd9:
	/* 0xdd9: mov    ebp,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967155ULL);
x86_l_dde:
	/* 0xdde: jmp    a22 <tail_nodeport_rev_dnat_ingress_ipv6+0xa22> */
	X86_SIM_X86_JMP(0xdde, 0xa22, x86_l_a22);
x86_l_de3:
	/* 0xde3: mov    rax,QWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_de7:
	/* 0xde7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_dea:
	/* 0xdea: jne    dff <tail_nodeport_rev_dnat_ingress_ipv6+0xdff> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xdea, 0xdff, x86_l_dff);
x86_l_dec:
	/* 0xdec: mov    ebp,0xffffff5f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967135ULL);
x86_l_df1:
	/* 0xdf1: cmp    DWORD PTR [r14+0x10],0xffff0000 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 73014378496ULL);
x86_l_df9:
	/* 0xdf9: je     a25 <tail_nodeport_rev_dnat_ingress_ipv6+0xa25> */
	X86_SIM_X86_JCC(X86_CC_E, 0xdf9, 0xa25, x86_l_a25);
x86_l_dff:
	/* 0xdff: mov    rcx,QWORD PTR [r14+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e03:
	/* 0xe03: mov    QWORD PTR [rsp+0x90],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_e0b:
	/* 0xe0b: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_e13:
	/* 0xe13: mov    rax,QWORD PTR [r14+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e17:
	/* 0xe17: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_e1f:
	/* 0xe1f: mov    rax,QWORD PTR [r14+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_e23:
	/* 0xe23: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_e2b:
	/* 0xe2b: mov    rax,QWORD PTR [rip+0x142a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_supports_fib_lookup_skip_neigh)));
x86_l_e32:
	/* 0xe32: movzx  ecx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_e35:
	/* 0xe35: shl    ecx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHL, 2ULL);
x86_l_e38:
	/* 0xe38: lea    rsi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_e3d:
	/* 0xe3d: mov    eax,0x45 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 69ULL);
x86_l_e42:
	/* 0xe42: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_e45:
	/* 0xe45: mov    edx,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 64ULL);
x86_l_e4a:
	/* 0xe4a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e4c:
	/* 0xe4c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_e4e:
	/* 0xe4e: je     e59 <tail_nodeport_rev_dnat_ingress_ipv6+0xe59> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe4e, 0xe59, x86_l_e59);
x86_l_e50:
	/* 0xe50: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_e53:
	/* 0xe53: jne    f12 <tail_nodeport_rev_dnat_ingress_ipv6+0xf12> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe53, 0xf12, x86_l_f12);
x86_l_e59:
	/* 0xe59: mov    r14d,DWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_e61:
	/* 0xe61: mov    DWORD PTR [rsp],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e65:
	/* 0xe65: mov    rdi,QWORD PTR [rip+0x142a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_devices)));
x86_l_e6c:
	/* 0xe6c: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_e6f:
	/* 0xe6f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e74:
	/* 0xe74: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e76:
	/* 0xe76: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e79:
	/* 0xe79: je     e85 <tail_nodeport_rev_dnat_ingress_ipv6+0xe85> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe79, 0xe85, x86_l_e85);
x86_l_e7b:
	/* 0xe7b: test   BYTE PTR [rax+0x8],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_e7f:
	/* 0xe7f: jne    f48 <tail_nodeport_rev_dnat_ingress_ipv6+0xf48> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe7f, 0xf48, x86_l_f48);
x86_l_e85:
	/* 0xe85: mov    r15d,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e89:
	/* 0xe89: mov    eax,0x2b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_e8e:
	/* 0xe8e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_e91:
	/* 0xe91: mov    esi,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 14ULL);
x86_l_e96:
	/* 0xe96: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e98:
	/* 0xe98: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e9a:
	/* 0xe9a: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_e9f:
	/* 0xe9f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ea1:
	/* 0xea1: jne    a22 <tail_nodeport_rev_dnat_ingress_ipv6+0xa22> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xea1, 0xa22, x86_l_a22);
x86_l_ea7:
	/* 0xea7: mov    WORD PTR [rsp],r15w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_eac:
	/* 0xeac: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_eaf:
	/* 0xeaf: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_eb4:
	/* 0xeb4: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_eb7:
	/* 0xeb7: mov    esi,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 12ULL);
x86_l_ebc:
	/* 0xebc: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_ec1:
	/* 0xec1: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ec4:
	/* 0xec4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ec6:
	/* 0xec6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ec8:
	/* 0xec8: js     1103 <tail_nodeport_rev_dnat_ingress_ipv6+0x1103> */
	X86_SIM_X86_JCC(X86_CC_S, 0xec8, 0x1103, x86_l_1103);
x86_l_ece:
	/* 0xece: lea    rax,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_ed6:
	/* 0xed6: movzx  ecx,BYTE PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 120ULL);
x86_l_edb:
	/* 0xedb: mov    DWORD PTR [rsp],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ede:
	/* 0xede: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ee1:
	/* 0xee1: mov    rax,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ee5:
	/* 0xee5: mov    QWORD PTR [rsp+0x4],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_eea:
	/* 0xeea: mov    QWORD PTR [rsp+0xc],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_eef:
	/* 0xeef: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_ef2:
	/* 0xef2: mov    eax,0x98 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 152ULL);
x86_l_ef7:
	/* 0xef7: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_efa:
	/* 0xefa: mov    edx,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 20ULL);
x86_l_eff:
	/* 0xeff: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f01:
	/* 0xf01: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f03:
	/* 0xf03: jmp    10c4 <tail_nodeport_rev_dnat_ingress_ipv6+0x10c4> */
	X86_SIM_X86_JMP(0xf03, 0x10c4, x86_l_10c4);
x86_l_f08:
	/* 0xf08: mov    ebp,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967142ULL);
x86_l_f0d:
	/* 0xf0d: jmp    a22 <tail_nodeport_rev_dnat_ingress_ipv6+0xa22> */
	X86_SIM_X86_JMP(0xf0d, 0xa22, x86_l_a22);
x86_l_f12:
	/* 0xf12: shl    eax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_f15:
	/* 0xf15: movzx  r15d,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_f19:
	/* 0xf19: mov    ebp,0xffffff57 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967127ULL);
x86_l_f1e:
	/* 0xf1e: jmp    a25 <tail_nodeport_rev_dnat_ingress_ipv6+0xa25> */
	X86_SIM_X86_JMP(0xf1e, 0xa25, x86_l_a25);
x86_l_f23:
	/* 0xf23: mov    rdi,QWORD PTR [rip+0x142a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv6_frag_datagrams)));
x86_l_f2a:
	/* 0xf2a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f2f:
	/* 0xf2f: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_f32:
	/* 0xf32: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f34:
	/* 0xf34: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f37:
	/* 0xf37: je     10ee <tail_nodeport_rev_dnat_ingress_ipv6+0x10ee> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf37, 0x10ee, x86_l_10ee);
x86_l_f3d:
	/* 0xf3d: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f3f:
	/* 0xf3f: mov    DWORD PTR [rsp+0x70],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_f43:
	/* 0xf43: jmp    1135 <tail_nodeport_rev_dnat_ingress_ipv6+0x1135> */
	X86_SIM_X86_JMP(0xf43, 0x1135, x86_l_1135);
x86_l_f48:
	/* 0xf48: mov    eax,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 23ULL);
x86_l_f4d:
	/* 0xf4d: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_f50:
	/* 0xf50: jmp    10c0 <tail_nodeport_rev_dnat_ingress_ipv6+0x10c0> */
	X86_SIM_X86_JMP(0xf50, 0x10c0, x86_l_10c0);
x86_l_f55:
	/* 0xf55: mov    rdi,QWORD PTR [rip+0x142a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv6_frag_datagrams)));
x86_l_f5c:
	/* 0xf5c: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_f61:
	/* 0xf61: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_f64:
	/* 0xf64: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_f67:
	/* 0xf67: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f69:
	/* 0xf69: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f6b:
	/* 0xf6b: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_f6e:
	/* 0xf6e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_f70:
	/* 0xf70: je     5a0 <tail_nodeport_rev_dnat_ingress_ipv6+0x5a0> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf70, 0x5a0, x86_l_5a0);
x86_l_f76:
	/* 0xf76: mov    r12d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f79:
	/* 0xf79: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_f82:
	/* 0xf82: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f8a:
	/* 0xf8a: movabs rax,0x7201a9020a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 489654125066ULL);
x86_l_f94:
	/* 0xf94: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_f99:
	/* 0xf99: mov    rdi,QWORD PTR [rip+0x142a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_fa0:
	/* 0xfa0: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_fa5:
	/* 0xfa5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_faa:
	/* 0xfaa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fac:
	/* 0xfac: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_faf:
	/* 0xfaf: je     1110 <tail_nodeport_rev_dnat_ingress_ipv6+0x1110> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfaf, 0x1110, x86_l_1110);
x86_l_fb5:
	/* 0xfb5: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_fb8:
	/* 0xfb8: add    QWORD PTR [rax+0x8],r12 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_fbc:
	/* 0xfbc: jmp    1135 <tail_nodeport_rev_dnat_ingress_ipv6+0x1135> */
	X86_SIM_X86_JMP(0xfbc, 0x1135, x86_l_1135);
x86_l_fc1:
	/* 0xfc1: mov    ebp,0xffffff63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967139ULL);
x86_l_fc6:
	/* 0xfc6: jmp    a25 <tail_nodeport_rev_dnat_ingress_ipv6+0xa25> */
	X86_SIM_X86_JMP(0xfc6, 0xa25, x86_l_a25);
x86_l_fcb:
	/* 0xfcb: mov    QWORD PTR [rsp],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_fd3:
	/* 0xfd3: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fd8:
	/* 0xfd8: mov    rdi,QWORD PTR [rip+0x142a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_fdf:
	/* 0xfdf: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_fe4:
	/* 0xfe4: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_fe7:
	/* 0xfe7: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_fec:
	/* 0xfec: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_fee:
	/* 0xfee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ff0:
	/* 0xff0: test   BYTE PTR [r14+0x17],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 98784247812ULL);
x86_l_ff5:
	/* 0xff5: jne    1050 <tail_nodeport_rev_dnat_ingress_ipv6+0x1050> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xff5, 0x1050, x86_l_1050);
x86_l_ff7:
	/* 0xff7: mov    eax,DWORD PTR [r14+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_ffb:
	/* 0xffb: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1004:
	/* 0x1004: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_100c:
	/* 0x100c: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1015:
	/* 0x1015: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_101e:
	/* 0x101e: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1027:
	/* 0x1027: mov    DWORD PTR [rsp],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_102e:
	/* 0x102e: movbe  DWORD PTR [rsp+0x4],eax */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 4ULL);
x86_l_1034:
	/* 0x1034: mov    BYTE PTR [rsp+0x15],0x40 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 90194313280ULL);
x86_l_1039:
	/* 0x1039: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_103c:
	/* 0x103c: mov    eax,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 21ULL);
x86_l_1041:
	/* 0x1041: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1044:
	/* 0x1044: mov    edx,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 28ULL);
x86_l_1049:
	/* 0x1049: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_104e:
	/* 0x104e: jmp    10ac <tail_nodeport_rev_dnat_ingress_ipv6+0x10ac> */
	X86_SIM_X86_JMP(0x104e, 0x10ac, x86_l_10ac);
x86_l_1050:
	/* 0x1050: mov    QWORD PTR [rsp+0x24],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 154618822656ULL);
x86_l_1059:
	/* 0x1059: mov    QWORD PTR [rsp+0x1c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120259084288ULL);
x86_l_1062:
	/* 0x1062: mov    QWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_106b:
	/* 0x106b: mov    DWORD PTR [rsp],0x6 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_1072:
	/* 0x1072: mov    eax,DWORD PTR [r14+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1076:
	/* 0x1076: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_107a:
	/* 0x107a: mov    eax,DWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_107e:
	/* 0x107e: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1082:
	/* 0x1082: mov    eax,DWORD PTR [r14+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1086:
	/* 0x1086: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_108a:
	/* 0x108a: mov    eax,DWORD PTR [r14+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_108e:
	/* 0x108e: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1092:
	/* 0x1092: mov    BYTE PTR [rsp+0x15],0x40 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 90194313280ULL);
x86_l_1097:
	/* 0x1097: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_109a:
	/* 0x109a: mov    eax,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 21ULL);
x86_l_109f:
	/* 0x109f: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_10a2:
	/* 0x10a2: mov    edx,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 28ULL);
x86_l_10a7:
	/* 0x10a7: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_10ac:
	/* 0x10ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10ae:
	/* 0x10ae: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_10b0:
	/* 0x10b0: js     124b <tail_nodeport_rev_dnat_ingress_ipv6+0x124b> */
	X86_SIM_X86_JCC(X86_CC_S, 0x10b0, 0x124b, x86_l_124b);
x86_l_10b6:
	/* 0x10b6: mov    eax,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 23ULL);
x86_l_10bb:
	/* 0x10bb: mov    edi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 1ULL);
x86_l_10c0:
	/* 0x10c0: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10c2:
	/* 0x10c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10c4:
	/* 0x10c4: mov    ebp,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_10c6:
	/* 0x10c6: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10c9:
	/* 0x10c9: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_10cb:
	/* 0x10cb: js     a25 <tail_nodeport_rev_dnat_ingress_ipv6+0xa25> */
	X86_SIM_X86_JCC(X86_CC_S, 0x10cb, 0xa25, x86_l_a25);
x86_l_10d1:
	/* 0x10d1: cmp    ebp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_10d4:
	/* 0x10d4: je     a25 <tail_nodeport_rev_dnat_ingress_ipv6+0xa25> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10d4, 0xa25, x86_l_a25);
x86_l_10da:
	/* 0x10da: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_10dc:
	/* 0x10dc: je     120f <tail_nodeport_rev_dnat_ingress_ipv6+0x120f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10dc, 0x120f, x86_l_120f);
x86_l_10e2:
	/* 0x10e2: mov    DWORD PTR [rbx+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_10e9:
	/* 0x10e9: jmp    ac2 <tail_nodeport_rev_dnat_ingress_ipv6+0xac2> */
	X86_SIM_X86_JMP(0x10e9, 0xac2, x86_l_ac2);
x86_l_10ee:
	/* 0x10ee: mov    ebp,0xffffff51 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967121ULL);
x86_l_10f3:
	/* 0x10f3: jmp    67d <tail_nodeport_rev_dnat_ingress_ipv6+0x67d> */
	X86_SIM_X86_JMP(0x10f3, 0x67d, x86_l_67d);
x86_l_10f8:
	/* 0x10f8: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_10fe:
	/* 0x10fe: jmp    72a <tail_nodeport_rev_dnat_ingress_ipv6+0x72a> */
	X86_SIM_X86_JMP(0x10fe, 0x72a, x86_l_72a);
x86_l_1103:
	/* 0x1103: mov    ebp,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_1105:
	/* 0x1105: sar    ebp,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SAR, 31ULL);
x86_l_1108:
	/* 0x1108: and    ebp,0xffffff73 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_AND, 4294967155ULL);
x86_l_110e:
	/* 0x110e: jmp    10c6 <tail_nodeport_rev_dnat_ingress_ipv6+0x10c6> */
	X86_SIM_X86_JMP(0x110e, 0x10c6, x86_l_10c6);
x86_l_1110:
	/* 0x1110: mov    QWORD PTR [rsp],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_1118:
	/* 0x1118: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_111d:
	/* 0x111d: mov    rdi,QWORD PTR [rip+0x142a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1124:
	/* 0x1124: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1129:
	/* 0x1129: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_112c:
	/* 0x112c: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1131:
	/* 0x1131: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1133:
	/* 0x1133: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1135:
	/* 0x1135: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_1138:
	/* 0x1138: jmp    5a0 <tail_nodeport_rev_dnat_ingress_ipv6+0x5a0> */
	X86_SIM_X86_JMP(0x1138, 0x5a0, x86_l_5a0);
x86_l_113d:
	/* 0x113d: mov    r13d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 60ULL);
x86_l_1143:
	/* 0x1143: cmp    r12b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_8, 6ULL);
x86_l_1147:
	/* 0x1147: jne    1180 <tail_nodeport_rev_dnat_ingress_ipv6+0x1180> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1147, 0x1180, x86_l_1180);
x86_l_1149:
	/* 0x1149: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_114b:
	/* 0x114b: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_114d:
	/* 0x114d: shr    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_1150:
	/* 0x1150: and    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_1153:
	/* 0x1153: or     ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1155:
	/* 0x1155: mov    WORD PTR [r14+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_115a:
	/* 0x115a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_115c:
	/* 0x115c: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_1161:
	/* 0x1161: mov    r13d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 21600ULL);
x86_l_1167:
	/* 0x1167: cmove  r13d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_116b:
	/* 0x116b: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_116f:
	/* 0x116f: je     1180 <tail_nodeport_rev_dnat_ingress_ipv6+0x1180> */
	X86_SIM_X86_JCC(X86_CC_E, 0x116f, 0x1180, x86_l_1180);
x86_l_1171:
	/* 0x1171: mov    rax,QWORD PTR [rip+0x142a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1178:
	/* 0x1178: imul   r13d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_117c:
	/* 0x117c: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1180:
	/* 0x1180: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1183:
	/* 0x1183: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1187:
	/* 0x1187: je     1198 <tail_nodeport_rev_dnat_ingress_ipv6+0x1198> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1187, 0x1198, x86_l_1198);
x86_l_1189:
	/* 0x1189: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_118e:
	/* 0x118e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1190:
	/* 0x1190: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1192:
	/* 0x1192: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_1196:
	/* 0x1196: jmp    11bb <tail_nodeport_rev_dnat_ingress_ipv6+0x11bb> */
	X86_SIM_X86_JMP(0x1196, 0x11bb, x86_l_11bb);
x86_l_1198:
	/* 0x1198: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_119d:
	/* 0x119d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_119f:
	/* 0x119f: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_11a1:
	/* 0x11a1: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_11a5:
	/* 0x11a5: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_11af:
	/* 0x11af: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_11b2:
	/* 0x11b2: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_11b7:
	/* 0x11b7: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_11bb:
	/* 0x11bb: add    r13d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_11be:
	/* 0x11be: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_11c1:
	/* 0x11c1: mov    DWORD PTR [r14+0x20],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_11c5:
	/* 0x11c5: movzx  ecx,BYTE PTR [r14+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_11ca:
	/* 0x11ca: mov    edx,DWORD PTR [r14+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_11ce:
	/* 0x11ce: and    bpl,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_11d2:
	/* 0x11d2: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11d6:
	/* 0x11d6: je     11e9 <tail_nodeport_rev_dnat_ingress_ipv6+0x11e9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11d6, 0x11e9, x86_l_11e9);
x86_l_11d8:
	/* 0x11d8: mov    rsi,QWORD PTR [rip+0x142a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_11df:
	/* 0x11df: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11e1:
	/* 0x11e1: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_11e4:
	/* 0x11e4: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_11e7:
	/* 0x11e7: jmp    11ee <tail_nodeport_rev_dnat_ingress_ipv6+0x11ee> */
	X86_SIM_X86_JMP(0x11e7, 0x11ee, x86_l_11ee);
x86_l_11e9:
	/* 0x11e9: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_11ee:
	/* 0x11ee: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_11f0:
	/* 0x11f0: or     bpl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_11f3:
	/* 0x11f3: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_11f5:
	/* 0x11f5: jb     11fc <tail_nodeport_rev_dnat_ingress_ipv6+0x11fc> */
	X86_SIM_X86_JCC(X86_CC_B, 0x11f5, 0x11fc, x86_l_11fc);
x86_l_11f7:
	/* 0x11f7: cmp    cl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_8);
x86_l_11fa:
	/* 0x11fa: je     120f <tail_nodeport_rev_dnat_ingress_ipv6+0x120f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11fa, 0x120f, x86_l_120f);
x86_l_11fc:
	/* 0x11fc: mov    BYTE PTR [r14+0x2b],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_1200:
	/* 0x1200: mov    DWORD PTR [r14+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1204:
	/* 0x1204: mov    r13,QWORD PTR [rip+0x142a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_120b:
	/* 0x120b: mov    eax,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_120f:
	/* 0x120f: or     BYTE PTR [rbx+0x2c],0x4 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RBX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 188978561028ULL);
x86_l_1213:
	/* 0x1213: mov    rsi,QWORD PTR [rip+0x142a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_121a:
	/* 0x121a: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_121f:
	/* 0x121f: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1222:
	/* 0x1222: mov    edx,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_1227:
	/* 0x1227: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1229:
	/* 0x1229: mov    ebp,0xffffff74 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967156ULL);
x86_l_122e:
	/* 0x122e: mov    r15d,0xa00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 2560ULL);
x86_l_1234:
	/* 0x1234: jmp    a25 <tail_nodeport_rev_dnat_ingress_ipv6+0xa25> */
	X86_SIM_X86_JMP(0x1234, 0xa25, x86_l_a25);
x86_l_1239:
	/* 0x1239: mov    ebp,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967155ULL);
x86_l_123e:
	/* 0x123e: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1240:
	/* 0x1240: je     cdc <tail_nodeport_rev_dnat_ingress_ipv6+0xcdc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1240, 0xcdc, x86_l_cdc);
x86_l_1246:
	/* 0x1246: jmp    10c6 <tail_nodeport_rev_dnat_ingress_ipv6+0x10c6> */
	X86_SIM_X86_JMP(0x1246, 0x10c6, x86_l_10c6);
x86_l_124b:
	/* 0x124b: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_124e:
	/* 0x124e: mov    ebp,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967155ULL);
x86_l_1253:
	/* 0x1253: jmp    a25 <tail_nodeport_rev_dnat_ingress_ipv6+0xa25> */
	X86_SIM_X86_JMP(0x1253, 0xa25, x86_l_a25);
x86_l_1258:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
