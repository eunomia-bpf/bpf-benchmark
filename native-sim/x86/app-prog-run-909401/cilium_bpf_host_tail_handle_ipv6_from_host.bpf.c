extern char __config_enable_conntrack_accounting;
extern char __config_enable_extended_ip_protocols;
extern char __config_enable_ipv6_fragments;
extern char __config_enable_jiffies;
extern char __config_eth_header_length;
extern char __config_kernel_hz;
extern char __config_trace_payload_len;
extern char cilium_calls;
extern char cilium_ct6_global;
extern char cilium_ct_any6_global;
extern char cilium_ipv6_frag_datagrams;
extern char cilium_metrics;
extern char cilium_tail_call_buffer6;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int cilium_bpf_host_tail_handle_ipv6_from_host_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0x58 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 88ULL);
x86_l_7:
	/* 0x7: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_a:
	/* 0xa: mov    r15d,DWORD PTR [rdi+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e:
	/* 0xe: mov    eax,DWORD PTR [rdi+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_11:
	/* 0x11: mov    DWORD PTR [rsp+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_15:
	/* 0x15: mov    QWORD PTR [rdi+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1d:
	/* 0x1d: mov    DWORD PTR [rsp+0x54],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 360777252864ULL);
x86_l_25:
	/* 0x25: mov    rdi,QWORD PTR [rip+0x1a3f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_2c:
	/* 0x2c: movzx  esi,BYTE PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2f:
	/* 0x2f: mov    eax,DWORD PTR [rbx+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_32:
	/* 0x32: mov    ecx,DWORD PTR [rbx+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_35:
	/* 0x35: lea    rdx,[rax+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_39:
	/* 0x39: add    rdx,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_3d:
	/* 0x3d: mov    r13d,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967162ULL);
x86_l_43:
	/* 0x43: cmp    rdx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_46:
	/* 0x46: ja     73e <tail_handle_ipv6_from_host+0x73e> */
	X86_SIM_X86_JCC(X86_CC_A, 0x46, 0x73e, x86_l_73e);
x86_l_4c:
	/* 0x4c: add    rsi,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4f:
	/* 0x4f: mov    rcx,QWORD PTR [rip+0x1a3f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_56:
	/* 0x56: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_59:
	/* 0x59: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_63:
	/* 0x63: mov    QWORD PTR [rsp+0x28],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_68:
	/* 0x68: je     111 <tail_handle_ipv6_from_host+0x111> */
	X86_SIM_X86_JCC(X86_CC_E, 0x68, 0x111, x86_l_111);
x86_l_6e:
	/* 0x6e: movzx  r12d,BYTE PTR [rsi+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_73:
	/* 0x73: movzx  ebp,BYTE PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_76:
	/* 0x76: mov    r14d,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 40ULL);
x86_l_7c:
	/* 0x7c: cmp    r12,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 60ULL);
x86_l_80:
	/* 0x80: ja     4eb <tail_handle_ipv6_from_host+0x4eb> */
	X86_SIM_X86_JCC(X86_CC_A, 0x80, 0x4eb, x86_l_4eb);
x86_l_86:
	/* 0x86: mov    r13d,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967140ULL);
x86_l_8c:
	/* 0x8c: bt     rdx,r12 */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_90:
	/* 0x90: jae    1a5 <tail_handle_ipv6_from_host+0x1a5> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x90, 0x1a5, x86_l_1a5);
x86_l_96:
	/* 0x96: lea    esi,[rbp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_99:
	/* 0x99: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9e:
	/* 0x9e: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_a3:
	/* 0xa3: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_a6:
	/* 0xa6: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_ab:
	/* 0xab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ad:
	/* 0xad: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_af:
	/* 0xaf: js     651 <tail_handle_ipv6_from_host+0x651> */
	X86_SIM_X86_JCC(X86_CC_S, 0xaf, 0x651, x86_l_651);
x86_l_b5:
	/* 0xb5: mov    DWORD PTR [rsp],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b9:
	/* 0xb9: movzx  eax,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_be:
	/* 0xbe: movzx  r15d,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_c2:
	/* 0xc2: cmp    r12d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 43ULL);
x86_l_c6:
	/* 0xc6: jle    1b4 <tail_handle_ipv6_from_host+0x1b4> */
	X86_SIM_X86_JCC(X86_CC_LE, 0xc6, 0x1b4, x86_l_1b4);
x86_l_cc:
	/* 0xcc: cmp    r12d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 44ULL);
x86_l_d0:
	/* 0xd0: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_da:
	/* 0xda: mov    rdi,QWORD PTR [rip+0x1a3f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_e1:
	/* 0xe1: je     32d <tail_handle_ipv6_from_host+0x32d> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe1, 0x32d, x86_l_32d);
x86_l_e7:
	/* 0xe7: cmp    r12d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 60ULL);
x86_l_eb:
	/* 0xeb: je     1c5 <tail_handle_ipv6_from_host+0x1c5> */
	X86_SIM_X86_JCC(X86_CC_E, 0xeb, 0x1c5, x86_l_1c5);
x86_l_f1:
	/* 0xf1: movzx  ecx,BYTE PTR [rsp+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_f6:
	/* 0xf6: lea    r14d,[rcx*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 8ULL);
x86_l_fe:
	/* 0xfe: add    r14d,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 40ULL);
x86_l_102:
	/* 0x102: cmp    r15d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 60ULL);
x86_l_106:
	/* 0x106: jbe    1e0 <tail_handle_ipv6_from_host+0x1e0> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x106, 0x1e0, x86_l_1e0);
x86_l_10c:
	/* 0x10c: jmp    341 <tail_handle_ipv6_from_host+0x341> */
	X86_SIM_X86_JMP(0x10c, 0x341, x86_l_341);
x86_l_111:
	/* 0x111: mov    DWORD PTR [rsp],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_115:
	/* 0x115: movzx  r15d,BYTE PTR [rsi+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_11a:
	/* 0x11a: cmp    r15,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 60ULL);
x86_l_11e:
	/* 0x11e: ja     7f3 <tail_handle_ipv6_from_host+0x7f3> */
	X86_SIM_X86_JCC(X86_CC_A, 0x11e, 0x7f3, x86_l_7f3);
x86_l_124:
	/* 0x124: mov    r13d,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967140ULL);
x86_l_12a:
	/* 0x12a: bt     rdx,r15 */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_12e:
	/* 0x12e: jae    253 <tail_handle_ipv6_from_host+0x253> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x12e, 0x253, x86_l_253);
x86_l_134:
	/* 0x134: mov    r14d,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_32);
x86_l_137:
	/* 0x137: sub    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_13a:
	/* 0x13a: lea    ebp,[r14+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_13e:
	/* 0x13e: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_143:
	/* 0x143: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_148:
	/* 0x148: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_14b:
	/* 0x14b: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_14d:
	/* 0x14d: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_152:
	/* 0x152: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_154:
	/* 0x154: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_156:
	/* 0x156: js     734 <tail_handle_ipv6_from_host+0x734> */
	X86_SIM_X86_JCC(X86_CC_S, 0x156, 0x734, x86_l_734);
x86_l_15c:
	/* 0x15c: movzx  r12d,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_162:
	/* 0x162: cmp    r15d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 43ULL);
x86_l_166:
	/* 0x166: mov    rdi,QWORD PTR [rip+0x1a3f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_16d:
	/* 0x16d: jle    278 <tail_handle_ipv6_from_host+0x278> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x16d, 0x278, x86_l_278);
x86_l_173:
	/* 0x173: cmp    r15d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 60ULL);
x86_l_177:
	/* 0x177: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_17c:
	/* 0x17c: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_186:
	/* 0x186: je     287 <tail_handle_ipv6_from_host+0x287> */
	X86_SIM_X86_JCC(X86_CC_E, 0x186, 0x287, x86_l_287);
x86_l_18c:
	/* 0x18c: cmp    r15d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 51ULL);
x86_l_190:
	/* 0x190: jne    364 <tail_handle_ipv6_from_host+0x364> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x190, 0x364, x86_l_364);
x86_l_196:
	/* 0x196: movzx  r15d,BYTE PTR [rsp+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_19c:
	/* 0x19c: shl    r15d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHL, 2ULL);
x86_l_1a0:
	/* 0x1a0: jmp    29f <tail_handle_ipv6_from_host+0x29f> */
	X86_SIM_X86_JMP(0x1a0, 0x29f, x86_l_29f);
x86_l_1a5:
	/* 0x1a5: cmp    r12,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 59ULL);
x86_l_1a9:
	/* 0x1a9: je     73e <tail_handle_ipv6_from_host+0x73e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a9, 0x73e, x86_l_73e);
x86_l_1af:
	/* 0x1af: jmp    4eb <tail_handle_ipv6_from_host+0x4eb> */
	X86_SIM_X86_JMP(0x1af, 0x4eb, x86_l_4eb);
x86_l_1b4:
	/* 0x1b4: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_1be:
	/* 0x1be: mov    rdi,QWORD PTR [rip+0x1a3f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_1c5:
	/* 0x1c5: movzx  ecx,BYTE PTR [rsp+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_1ca:
	/* 0x1ca: lea    r14d,[rcx*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 3), 8ULL);
x86_l_1d2:
	/* 0x1d2: add    r14d,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 40ULL);
x86_l_1d6:
	/* 0x1d6: cmp    r15d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 60ULL);
x86_l_1da:
	/* 0x1da: ja     341 <tail_handle_ipv6_from_host+0x341> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1da, 0x341, x86_l_341);
x86_l_1e0:
	/* 0x1e0: mov    ecx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_32);
x86_l_1e3:
	/* 0x1e3: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_1e7:
	/* 0x1e7: jae    262 <tail_handle_ipv6_from_host+0x262> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x1e7, 0x262, x86_l_262);
x86_l_1e9:
	/* 0x1e9: lea    esi,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_1ed:
	/* 0x1ed: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1f2:
	/* 0x1f2: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1f7:
	/* 0x1f7: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1fa:
	/* 0x1fa: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1ff:
	/* 0x1ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_201:
	/* 0x201: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_203:
	/* 0x203: js     734 <tail_handle_ipv6_from_host+0x734> */
	X86_SIM_X86_JCC(X86_CC_S, 0x203, 0x734, x86_l_734);
x86_l_209:
	/* 0x209: movzx  r12d,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_20f:
	/* 0x20f: movzx  edx,r12b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_R12, X86_WIDTH_32, X86_WIDTH_8);
x86_l_213:
	/* 0x213: cmp    r15d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 43ULL);
x86_l_217:
	/* 0x217: jle    34d <tail_handle_ipv6_from_host+0x34d> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x217, 0x34d, x86_l_34d);
x86_l_21d:
	/* 0x21d: cmp    r15d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 44ULL);
x86_l_221:
	/* 0x221: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_22b:
	/* 0x22b: mov    rdi,QWORD PTR [rip+0x1a3f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_232:
	/* 0x232: je     36d <tail_handle_ipv6_from_host+0x36d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x232, 0x36d, x86_l_36d);
x86_l_238:
	/* 0x238: cmp    r15d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 51ULL);
x86_l_23c:
	/* 0x23c: jne    378 <tail_handle_ipv6_from_host+0x378> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x23c, 0x378, x86_l_378);
x86_l_242:
	/* 0x242: movzx  eax,BYTE PTR [rsp+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_247:
	/* 0x247: lea    eax,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_24e:
	/* 0x24e: jmp    372 <tail_handle_ipv6_from_host+0x372> */
	X86_SIM_X86_JMP(0x24e, 0x372, x86_l_372);
x86_l_253:
	/* 0x253: cmp    r15,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 59ULL);
x86_l_257:
	/* 0x257: je     73a <tail_handle_ipv6_from_host+0x73a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x257, 0x73a, x86_l_73a);
x86_l_25d:
	/* 0x25d: jmp    7f3 <tail_handle_ipv6_from_host+0x7f3> */
	X86_SIM_X86_JMP(0x25d, 0x7f3, x86_l_7f3);
x86_l_262:
	/* 0x262: mov    r12d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_32);
x86_l_265:
	/* 0x265: cmp    rcx,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 59ULL);
x86_l_269:
	/* 0x269: mov    r15d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_26d:
	/* 0x26d: je     73e <tail_handle_ipv6_from_host+0x73e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x26d, 0x73e, x86_l_73e);
x86_l_273:
	/* 0x273: jmp    4eb <tail_handle_ipv6_from_host+0x4eb> */
	X86_SIM_X86_JMP(0x273, 0x4eb, x86_l_4eb);
x86_l_278:
	/* 0x278: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_27d:
	/* 0x27d: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_287:
	/* 0x287: cmp    r15d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 44ULL);
x86_l_28b:
	/* 0x28b: mov    r15d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28f:
	/* 0x28f: je     44a <tail_handle_ipv6_from_host+0x44a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x28f, 0x44a, x86_l_44a);
x86_l_295:
	/* 0x295: movzx  r15d,BYTE PTR [rsp+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_29b:
	/* 0x29b: shl    r15d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_29f:
	/* 0x29f: cmp    r12d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 60ULL);
x86_l_2a3:
	/* 0x2a3: ja     7f3 <tail_handle_ipv6_from_host+0x7f3> */
	X86_SIM_X86_JCC(X86_CC_A, 0x2a3, 0x7f3, x86_l_7f3);
x86_l_2a9:
	/* 0x2a9: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_2ac:
	/* 0x2ac: bt     rdx,rax */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2b0:
	/* 0x2b0: jae    7e9 <tail_handle_ipv6_from_host+0x7e9> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x2b0, 0x7e9, x86_l_7e9);
x86_l_2b6:
	/* 0x2b6: lea    ebp,[r15+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_2ba:
	/* 0x2ba: add    ebp,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 48ULL);
x86_l_2bd:
	/* 0x2bd: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c2:
	/* 0x2c2: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_2c7:
	/* 0x2c7: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2ca:
	/* 0x2ca: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_2cc:
	/* 0x2cc: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2d1:
	/* 0x2d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d3:
	/* 0x2d3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2d5:
	/* 0x2d5: js     734 <tail_handle_ipv6_from_host+0x734> */
	X86_SIM_X86_JCC(X86_CC_S, 0x2d5, 0x734, x86_l_734);
x86_l_2db:
	/* 0x2db: mov    QWORD PTR [rsp+0x40],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_2e0:
	/* 0x2e0: movzx  r8d,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_2e6:
	/* 0x2e6: cmp    r12d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 43ULL);
x86_l_2ea:
	/* 0x2ea: jle    426 <tail_handle_ipv6_from_host+0x426> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x2ea, 0x426, x86_l_426);
x86_l_2f0:
	/* 0x2f0: cmp    r12d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 44ULL);
x86_l_2f4:
	/* 0x2f4: mov    r15d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f8:
	/* 0x2f8: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2fd:
	/* 0x2fd: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_307:
	/* 0x307: mov    rdi,QWORD PTR [rip+0x1a3f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_30e:
	/* 0x30e: je     44a <tail_handle_ipv6_from_host+0x44a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x30e, 0x44a, x86_l_44a);
x86_l_314:
	/* 0x314: cmp    r12d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 51ULL);
x86_l_318:
	/* 0x318: jne    440 <tail_handle_ipv6_from_host+0x440> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x318, 0x440, x86_l_440);
x86_l_31e:
	/* 0x31e: movzx  r12d,BYTE PTR [rsp+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_324:
	/* 0x324: shl    r12d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHL, 2ULL);
x86_l_328:
	/* 0x328: jmp    6a4 <tail_handle_ipv6_from_host+0x6a4> */
	X86_SIM_X86_JMP(0x328, 0x6a4, x86_l_6a4);
x86_l_32d:
	/* 0x32d: mov    r14d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 8ULL);
x86_l_333:
	/* 0x333: add    r14d,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 40ULL);
x86_l_337:
	/* 0x337: cmp    r15d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 60ULL);
x86_l_33b:
	/* 0x33b: jbe    1e0 <tail_handle_ipv6_from_host+0x1e0> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x33b, 0x1e0, x86_l_1e0);
x86_l_341:
	/* 0x341: mov    r12d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_32);
x86_l_344:
	/* 0x344: mov    r15d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_348:
	/* 0x348: jmp    4eb <tail_handle_ipv6_from_host+0x4eb> */
	X86_SIM_X86_JMP(0x348, 0x4eb, x86_l_4eb);
x86_l_34d:
	/* 0x34d: mov    r15d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_351:
	/* 0x351: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_35b:
	/* 0x35b: mov    rdi,QWORD PTR [rip+0x1a3f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_362:
	/* 0x362: jmp    37c <tail_handle_ipv6_from_host+0x37c> */
	X86_SIM_X86_JMP(0x362, 0x37c, x86_l_37c);
x86_l_364:
	/* 0x364: mov    r15d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_368:
	/* 0x368: jmp    44a <tail_handle_ipv6_from_host+0x44a> */
	X86_SIM_X86_JMP(0x368, 0x44a, x86_l_44a);
x86_l_36d:
	/* 0x36d: mov    eax,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_372:
	/* 0x372: mov    r15d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_376:
	/* 0x376: jmp    388 <tail_handle_ipv6_from_host+0x388> */
	X86_SIM_X86_JMP(0x376, 0x388, x86_l_388);
x86_l_378:
	/* 0x378: mov    r15d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_37c:
	/* 0x37c: movzx  eax,BYTE PTR [rsp+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_381:
	/* 0x381: lea    eax,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_388:
	/* 0x388: add    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_38b:
	/* 0x38b: cmp    edx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 60ULL);
x86_l_38e:
	/* 0x38e: ja     4eb <tail_handle_ipv6_from_host+0x4eb> */
	X86_SIM_X86_JCC(X86_CC_A, 0x38e, 0x4eb, x86_l_4eb);
x86_l_394:
	/* 0x394: mov    eax,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_396:
	/* 0x396: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_39a:
	/* 0x39a: jae    4e1 <tail_handle_ipv6_from_host+0x4e1> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x39a, 0x4e1, x86_l_4e1);
x86_l_3a0:
	/* 0x3a0: mov    DWORD PTR [rsp+0x40],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3a4:
	/* 0x3a4: lea    esi,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_3a8:
	/* 0x3a8: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3ad:
	/* 0x3ad: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_3b2:
	/* 0x3b2: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_3b5:
	/* 0x3b5: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_3ba:
	/* 0x3ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3bc:
	/* 0x3bc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3be:
	/* 0x3be: js     651 <tail_handle_ipv6_from_host+0x651> */
	X86_SIM_X86_JCC(X86_CC_S, 0x3be, 0x651, x86_l_651);
x86_l_3c4:
	/* 0x3c4: movzx  r12d,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_3ca:
	/* 0x3ca: movzx  eax,r12b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R12, X86_WIDTH_32, X86_WIDTH_8);
x86_l_3ce:
	/* 0x3ce: mov    ecx,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3d2:
	/* 0x3d2: cmp    ecx,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 43ULL);
x86_l_3d5:
	/* 0x3d5: jle    407 <tail_handle_ipv6_from_host+0x407> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x3d5, 0x407, x86_l_407);
x86_l_3d7:
	/* 0x3d7: cmp    ecx,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 44ULL);
x86_l_3da:
	/* 0x3da: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_3e4:
	/* 0x3e4: mov    rdi,QWORD PTR [rip+0x1a3f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_3eb:
	/* 0x3eb: je     499 <tail_handle_ipv6_from_host+0x499> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3eb, 0x499, x86_l_499);
x86_l_3f1:
	/* 0x3f1: cmp    ecx,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 51ULL);
x86_l_3f4:
	/* 0x3f4: jne    418 <tail_handle_ipv6_from_host+0x418> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3f4, 0x418, x86_l_418);
x86_l_3f6:
	/* 0x3f6: movzx  ecx,BYTE PTR [rsp+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_3fb:
	/* 0x3fb: lea    ecx,[rcx*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 8ULL);
x86_l_402:
	/* 0x402: jmp    49e <tail_handle_ipv6_from_host+0x49e> */
	X86_SIM_X86_JMP(0x402, 0x49e, x86_l_49e);
x86_l_407:
	/* 0x407: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_411:
	/* 0x411: mov    rdi,QWORD PTR [rip+0x1a3f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_418:
	/* 0x418: movzx  ecx,BYTE PTR [rsp+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_41d:
	/* 0x41d: lea    ecx,[rcx*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 3), 8ULL);
x86_l_424:
	/* 0x424: jmp    49e <tail_handle_ipv6_from_host+0x49e> */
	X86_SIM_X86_JMP(0x424, 0x49e, x86_l_49e);
x86_l_426:
	/* 0x426: mov    r15d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_42a:
	/* 0x42a: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_42f:
	/* 0x42f: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_439:
	/* 0x439: mov    rdi,QWORD PTR [rip+0x1a3f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_440:
	/* 0x440: cmp    r12d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 44ULL);
x86_l_444:
	/* 0x444: jne    69a <tail_handle_ipv6_from_host+0x69a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x444, 0x69a, x86_l_69a);
x86_l_44a:
	/* 0x44a: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_44f:
	/* 0x44f: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_454:
	/* 0x454: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_457:
	/* 0x457: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_459:
	/* 0x459: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_45e:
	/* 0x45e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_460:
	/* 0x460: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_462:
	/* 0x462: js     651 <tail_handle_ipv6_from_host+0x651> */
	X86_SIM_X86_JCC(X86_CC_S, 0x462, 0x651, x86_l_651);
x86_l_468:
	/* 0x468: movzx  eax,WORD PTR [rsp+0xa] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 10ULL);
x86_l_46d:
	/* 0x46d: mov    r13d,0xffffff63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967139ULL);
x86_l_473:
	/* 0x473: test   eax,0xf9ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63999ULL);
x86_l_478:
	/* 0x478: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_47d:
	/* 0x47d: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_487:
	/* 0x487: mov    rdi,QWORD PTR [rip+0x1a3f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_48e:
	/* 0x48e: jne    73e <tail_handle_ipv6_from_host+0x73e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x48e, 0x73e, x86_l_73e);
x86_l_494:
	/* 0x494: jmp    6e <tail_handle_ipv6_from_host+0x6e> */
	X86_SIM_X86_JMP(0x494, 0x6e, x86_l_6e);
x86_l_499:
	/* 0x499: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_49e:
	/* 0x49e: add    r14d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_4a1:
	/* 0x4a1: cmp    eax,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_4a4:
	/* 0x4a4: ja     4eb <tail_handle_ipv6_from_host+0x4eb> */
	X86_SIM_X86_JCC(X86_CC_A, 0x4a4, 0x4eb, x86_l_4eb);
x86_l_4a6:
	/* 0x4a6: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4a8:
	/* 0x4a8: bt     rdx,rax */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_4ac:
	/* 0x4ac: jae    4e1 <tail_handle_ipv6_from_host+0x4e1> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x4ac, 0x4e1, x86_l_4e1);
x86_l_4ae:
	/* 0x4ae: add    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_4b1:
	/* 0x4b1: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b6:
	/* 0x4b6: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_4bb:
	/* 0x4bb: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_4be:
	/* 0x4be: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_4c1:
	/* 0x4c1: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_4c6:
	/* 0x4c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c8:
	/* 0x4c8: mov    r13d,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967162ULL);
x86_l_4ce:
	/* 0x4ce: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4d0:
	/* 0x4d0: js     73e <tail_handle_ipv6_from_host+0x73e> */
	X86_SIM_X86_JCC(X86_CC_S, 0x4d0, 0x73e, x86_l_73e);
x86_l_4d6:
	/* 0x4d6: mov    r13d,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967140ULL);
x86_l_4dc:
	/* 0x4dc: jmp    73e <tail_handle_ipv6_from_host+0x73e> */
	X86_SIM_X86_JMP(0x4dc, 0x73e, x86_l_73e);
x86_l_4e1:
	/* 0x4e1: cmp    rax,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 59ULL);
x86_l_4e5:
	/* 0x4e5: je     73e <tail_handle_ipv6_from_host+0x73e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4e5, 0x73e, x86_l_73e);
x86_l_4eb:
	/* 0x4eb: cmp    r12b,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_8, 58ULL);
x86_l_4ef:
	/* 0x4ef: jne    543 <tail_handle_ipv6_from_host+0x543> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4ef, 0x543, x86_l_543);
x86_l_4f1:
	/* 0x4f1: movzx  eax,BYTE PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_4f4:
	/* 0x4f4: add    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_4f7:
	/* 0x4f7: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4fc:
	/* 0x4fc: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_501:
	/* 0x501: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_504:
	/* 0x504: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_507:
	/* 0x507: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_50c:
	/* 0x50c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_50e:
	/* 0x50e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_510:
	/* 0x510: js     651 <tail_handle_ipv6_from_host+0x651> */
	X86_SIM_X86_JCC(X86_CC_S, 0x510, 0x651, x86_l_651);
x86_l_516:
	/* 0x516: movzx  eax,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_51b:
	/* 0x51b: lea    ecx,[rax-0x80] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551488ULL);
x86_l_51e:
	/* 0x51e: cmp    ecx,0x19 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 25ULL);
x86_l_521:
	/* 0x521: ja     65c <tail_handle_ipv6_from_host+0x65c> */
	X86_SIM_X86_JCC(X86_CC_A, 0x521, 0x65c, x86_l_65c);
x86_l_527:
	/* 0x527: mov    edx,0x3b0e17c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 61923708ULL);
x86_l_52c:
	/* 0x52c: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_52f:
	/* 0x52f: jb     667 <tail_handle_ipv6_from_host+0x667> */
	X86_SIM_X86_JCC(X86_CC_B, 0x52f, 0x667, x86_l_667);
x86_l_535:
	/* 0x535: mov    edx,0x83 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 131ULL);
x86_l_53a:
	/* 0x53a: bt     edx,ecx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_53d:
	/* 0x53d: jae    65c <tail_handle_ipv6_from_host+0x65c> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x53d, 0x65c, x86_l_65c);
x86_l_543:
	/* 0x543: mov    rdi,QWORD PTR [rip+0x1a3f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_tail_call_buffer6)));
x86_l_54a:
	/* 0x54a: lea    rsi,[rsp+0x54] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_54f:
	/* 0x54f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_554:
	/* 0x554: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_556:
	/* 0x556: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_559:
	/* 0x559: je     7fc <tail_handle_ipv6_from_host+0x7fc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x559, 0x7fc, x86_l_7fc);
x86_l_55f:
	/* 0x55f: mov    rsi,QWORD PTR [rip+0x1a3f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_566:
	/* 0x566: movzx  r12d,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_56a:
	/* 0x56a: cmp    DWORD PTR [rsp+0x20],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953473ULL);
x86_l_56f:
	/* 0x56f: je     582 <tail_handle_ipv6_from_host+0x582> */
	X86_SIM_X86_JCC(X86_CC_E, 0x56f, 0x582, x86_l_582);
x86_l_571:
	/* 0x571: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_573:
	/* 0x573: mov    ecx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 0ULL);
x86_l_578:
	/* 0x578: cmp    r15d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 1ULL);
x86_l_57c:
	/* 0x57c: jne    66b <tail_handle_ipv6_from_host+0x66b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x57c, 0x66b, x86_l_66b);
x86_l_582:
	/* 0x582: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_587:
	/* 0x587: movzx  r14d,BYTE PTR [rdx+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_58c:
	/* 0x58c: mov    BYTE PTR [rax+0x24],r14b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R14, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_590:
	/* 0x590: mov    rcx,QWORD PTR [rdx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_594:
	/* 0x594: mov    QWORD PTR [rax+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_598:
	/* 0x598: mov    rcx,QWORD PTR [rdx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_59c:
	/* 0x59c: mov    QWORD PTR [rax+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5a0:
	/* 0x5a0: mov    rcx,QWORD PTR [rdx+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5a4:
	/* 0x5a4: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a8:
	/* 0x5a8: mov    rcx,QWORD PTR [rdx+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5ac:
	/* 0x5ac: mov    QWORD PTR [rax],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5af:
	/* 0x5af: movzx  ecx,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_5b2:
	/* 0x5b2: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5b7:
	/* 0x5b7: mov    QWORD PTR [rax+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_5bf:
	/* 0x5bf: mov    esi,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 40ULL);
x86_l_5c4:
	/* 0x5c4: cmp    r14,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_64, 60ULL);
x86_l_5c8:
	/* 0x5c8: ja     d18 <tail_handle_ipv6_from_host+0xd18> */
	X86_SIM_X86_JCC(X86_CC_A, 0x5c8, 0xd18, x86_l_d18);
x86_l_5ce:
	/* 0x5ce: mov    r13d,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967140ULL);
x86_l_5d4:
	/* 0x5d4: movabs rax,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_5de:
	/* 0x5de: bt     rax,r14 */
	X86_SIM_L_EXEC_BT(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_5e2:
	/* 0x5e2: jae    8b4 <tail_handle_ipv6_from_host+0x8b4> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x5e2, 0x8b4, x86_l_8b4);
x86_l_5e8:
	/* 0x5e8: mov    QWORD PTR [rsp+0x40],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_5ed:
	/* 0x5ed: lea    ebp,[rcx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5f0:
	/* 0x5f0: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5f5:
	/* 0x5f5: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_5fa:
	/* 0x5fa: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_5fd:
	/* 0x5fd: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_5ff:
	/* 0x5ff: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_604:
	/* 0x604: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_606:
	/* 0x606: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_608:
	/* 0x608: js     8a9 <tail_handle_ipv6_from_host+0x8a9> */
	X86_SIM_X86_JCC(X86_CC_S, 0x608, 0x8a9, x86_l_8a9);
x86_l_60e:
	/* 0x60e: movzx  edi,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_613:
	/* 0x613: cmp    r14d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 43ULL);
x86_l_617:
	/* 0x617: mov    DWORD PTR [rsp],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_61b:
	/* 0x61b: mov    DWORD PTR [rsp+0x3c],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_620:
	/* 0x620: jle    8d2 <tail_handle_ipv6_from_host+0x8d2> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x620, 0x8d2, x86_l_8d2);
x86_l_626:
	/* 0x626: cmp    r14d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 60ULL);
x86_l_62a:
	/* 0x62a: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_62f:
	/* 0x62f: je     8d7 <tail_handle_ipv6_from_host+0x8d7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x62f, 0x8d7, x86_l_8d7);
x86_l_635:
	/* 0x635: cmp    r14d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 51ULL);
x86_l_639:
	/* 0x639: jne    907 <tail_handle_ipv6_from_host+0x907> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x639, 0x907, x86_l_907);
x86_l_63f:
	/* 0x63f: movzx  eax,BYTE PTR [rsp+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_644:
	/* 0x644: lea    r12d,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_64c:
	/* 0x64c: jmp    989 <tail_handle_ipv6_from_host+0x989> */
	X86_SIM_X86_JMP(0x64c, 0x989, x86_l_989);
x86_l_651:
	/* 0x651: mov    r13d,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967162ULL);
x86_l_657:
	/* 0x657: jmp    73e <tail_handle_ipv6_from_host+0x73e> */
	X86_SIM_X86_JMP(0x657, 0x73e, x86_l_73e);
x86_l_65c:
	/* 0x65c: dec    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_DEC, 1);
x86_l_65e:
	/* 0x65e: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_661:
	/* 0x661: jae    807 <tail_handle_ipv6_from_host+0x807> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x661, 0x807, x86_l_807);
x86_l_667:
	/* 0x667: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_669:
	/* 0x669: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_66b:
	/* 0x66b: or     edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_66d:
	/* 0x66d: mov    DWORD PTR [rbx+0x3c],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_670:
	/* 0x670: mov    DWORD PTR [rbx+0x30],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_674:
	/* 0x674: mov    rsi,QWORD PTR [rip+0x1a3f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_67b:
	/* 0x67b: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_680:
	/* 0x680: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_683:
	/* 0x683: mov    edx,0x2b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 43ULL);
x86_l_688:
	/* 0x688: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_68a:
	/* 0x68a: mov    r13d,0xffffff74 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967156ULL);
x86_l_690:
	/* 0x690: mov    eax,0x2b00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11008ULL);
x86_l_695:
	/* 0x695: jmp    740 <tail_handle_ipv6_from_host+0x740> */
	X86_SIM_X86_JMP(0x695, 0x740, x86_l_740);
x86_l_69a:
	/* 0x69a: movzx  r12d,BYTE PTR [rsp+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_6a0:
	/* 0x6a0: shl    r12d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_6a4:
	/* 0x6a4: cmp    r8d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 60ULL);
x86_l_6a8:
	/* 0x6a8: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_6ad:
	/* 0x6ad: ja     7f3 <tail_handle_ipv6_from_host+0x7f3> */
	X86_SIM_X86_JCC(X86_CC_A, 0x6ad, 0x7f3, x86_l_7f3);
x86_l_6b3:
	/* 0x6b3: mov    eax,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R8, X86_WIDTH_32);
x86_l_6b6:
	/* 0x6b6: bt     rdx,rax */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_6ba:
	/* 0x6ba: jae    7e9 <tail_handle_ipv6_from_host+0x7e9> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x6ba, 0x7e9, x86_l_7e9);
x86_l_6c0:
	/* 0x6c0: mov    r15d,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R8, X86_WIDTH_32);
x86_l_6c3:
	/* 0x6c3: lea    eax,[rcx+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_6c7:
	/* 0x6c7: lea    ebp,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_6cb:
	/* 0x6cb: add    ebp,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 56ULL);
x86_l_6ce:
	/* 0x6ce: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6d3:
	/* 0x6d3: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_6d8:
	/* 0x6d8: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_6db:
	/* 0x6db: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_6dd:
	/* 0x6dd: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_6e2:
	/* 0x6e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6e4:
	/* 0x6e4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_6e6:
	/* 0x6e6: js     734 <tail_handle_ipv6_from_host+0x734> */
	X86_SIM_X86_JCC(X86_CC_S, 0x6e6, 0x734, x86_l_734);
x86_l_6e8:
	/* 0x6e8: movzx  r9d,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_6ee:
	/* 0x6ee: mov    eax,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_6f1:
	/* 0x6f1: cmp    r15d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 43ULL);
x86_l_6f5:
	/* 0x6f5: jle    812 <tail_handle_ipv6_from_host+0x812> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x6f5, 0x812, x86_l_812);
x86_l_6fb:
	/* 0x6fb: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_6fe:
	/* 0x6fe: mov    r15d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_702:
	/* 0x702: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_707:
	/* 0x707: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_711:
	/* 0x711: mov    rdi,QWORD PTR [rip+0x1a3f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_718:
	/* 0x718: je     44a <tail_handle_ipv6_from_host+0x44a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x718, 0x44a, x86_l_44a);
x86_l_71e:
	/* 0x71e: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_721:
	/* 0x721: jne    82c <tail_handle_ipv6_from_host+0x82c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x721, 0x82c, x86_l_82c);
x86_l_727:
	/* 0x727: movzx  eax,BYTE PTR [rsp+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_72c:
	/* 0x72c: shl    eax,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 2ULL);
x86_l_72f:
	/* 0x72f: jmp    83d <tail_handle_ipv6_from_host+0x83d> */
	X86_SIM_X86_JMP(0x72f, 0x83d, x86_l_83d);
x86_l_734:
	/* 0x734: mov    r13d,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967162ULL);
x86_l_73a:
	/* 0x73a: mov    r15d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_73e:
	/* 0x73e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_740:
	/* 0x740: sub    eax,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_32, X86_ALU_SUB);
x86_l_743:
	/* 0x743: mov    DWORD PTR [rbx+0x30],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_747:
	/* 0x747: mov    DWORD PTR [rbx+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_74e:
	/* 0x74e: mov    DWORD PTR [rbx+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_751:
	/* 0x751: movabs rax,0x1ee010200000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 139049746596626432ULL);
x86_l_75b:
	/* 0x75b: mov    QWORD PTR [rbx+0x3c],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_75f:
	/* 0x75f: mov    r14d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_762:
	/* 0x762: neg    r13b */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_8, X86_ALU_NEG, 0);
x86_l_765:
	/* 0x765: movabs rax,0x101ee0100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 4327342336ULL);
x86_l_76f:
	/* 0x76f: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_774:
	/* 0x774: mov    BYTE PTR [rsp+0x48],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_779:
	/* 0x779: mov    rdi,QWORD PTR [rip+0x1a3f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_780:
	/* 0x780: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_785:
	/* 0x785: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_78a:
	/* 0x78a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_78c:
	/* 0x78c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_78f:
	/* 0x78f: je     79a <tail_handle_ipv6_from_host+0x79a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x78f, 0x79a, x86_l_79a);
x86_l_791:
	/* 0x791: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_794:
	/* 0x794: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_798:
	/* 0x798: jmp    7c2 <tail_handle_ipv6_from_host+0x7c2> */
	X86_SIM_X86_JMP(0x798, 0x7c2, x86_l_7c2);
x86_l_79a:
	/* 0x79a: mov    QWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_7a3:
	/* 0x7a3: mov    QWORD PTR [rsp+0x10],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7a8:
	/* 0x7a8: mov    rdi,QWORD PTR [rip+0x1a3f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_7af:
	/* 0x7af: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_7b4:
	/* 0x7b4: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7b9:
	/* 0x7b9: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_7be:
	/* 0x7be: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7c0:
	/* 0x7c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7c2:
	/* 0x7c2: mov    rsi,QWORD PTR [rip+0x1a3f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_7c9:
	/* 0x7c9: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_7ce:
	/* 0x7ce: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_7d1:
	/* 0x7d1: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_7d6:
	/* 0x7d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7d8:
	/* 0x7d8: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_7dd:
	/* 0x7dd: add    rsp,0x58 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 88ULL);
x86_l_7e1:
	/* 0x7e1: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_7e3:
	/* 0x7e3: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_7e4:
	/* 0x7e4: jmp    19c1 <tail_handle_ipv6_from_host+0x19c1> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_7e9:
	/* 0x7e9: cmp    rax,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 59ULL);
x86_l_7ed:
	/* 0x7ed: je     73a <tail_handle_ipv6_from_host+0x73a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7ed, 0x73a, x86_l_73a);
x86_l_7f3:
	/* 0x7f3: mov    r15d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7f7:
	/* 0x7f7: jmp    6e <tail_handle_ipv6_from_host+0x6e> */
	X86_SIM_X86_JMP(0x7f7, 0x6e, x86_l_6e);
x86_l_7fc:
	/* 0x7fc: mov    r13d,0xffffff48 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967112ULL);
x86_l_802:
	/* 0x802: jmp    73e <tail_handle_ipv6_from_host+0x73e> */
	X86_SIM_X86_JMP(0x802, 0x73e, x86_l_73e);
x86_l_807:
	/* 0x807: mov    r13d,0xffffff50 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967120ULL);
x86_l_80d:
	/* 0x80d: jmp    73e <tail_handle_ipv6_from_host+0x73e> */
	X86_SIM_X86_JMP(0x80d, 0x73e, x86_l_73e);
x86_l_812:
	/* 0x812: mov    r15d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_816:
	/* 0x816: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_81b:
	/* 0x81b: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_825:
	/* 0x825: mov    rdi,QWORD PTR [rip+0x1a3fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_82c:
	/* 0x82c: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_82f:
	/* 0x82f: je     44a <tail_handle_ipv6_from_host+0x44a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x82f, 0x44a, x86_l_44a);
x86_l_835:
	/* 0x835: movzx  eax,BYTE PTR [rsp+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_83a:
	/* 0x83a: shl    eax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_83d:
	/* 0x83d: cmp    r9d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R9, X86_WIDTH_32, 60ULL);
x86_l_841:
	/* 0x841: mov    r8,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_846:
	/* 0x846: ja     7f3 <tail_handle_ipv6_from_host+0x7f3> */
	X86_SIM_X86_JCC(X86_CC_A, 0x846, 0x7f3, x86_l_7f3);
x86_l_848:
	/* 0x848: mov    ecx,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R9, X86_WIDTH_32);
x86_l_84b:
	/* 0x84b: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_84f:
	/* 0x84f: jae    8c3 <tail_handle_ipv6_from_host+0x8c3> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x84f, 0x8c3, x86_l_8c3);
x86_l_851:
	/* 0x851: lea    ecx,[r8+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_855:
	/* 0x855: add    ecx,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 56ULL);
x86_l_858:
	/* 0x858: add    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_85a:
	/* 0x85a: lea    ebp,[r14+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_85e:
	/* 0x85e: add    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 8ULL);
x86_l_861:
	/* 0x861: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_866:
	/* 0x866: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_86b:
	/* 0x86b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_86e:
	/* 0x86e: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_870:
	/* 0x870: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_875:
	/* 0x875: mov    r14d,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R9, X86_WIDTH_32);
x86_l_878:
	/* 0x878: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_87a:
	/* 0x87a: mov    r13d,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967162ULL);
x86_l_880:
	/* 0x880: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_882:
	/* 0x882: js     73a <tail_handle_ipv6_from_host+0x73a> */
	X86_SIM_X86_JCC(X86_CC_S, 0x882, 0x73a, x86_l_73a);
x86_l_888:
	/* 0x888: mov    ecx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_32);
x86_l_88b:
	/* 0x88b: cmp    r14d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 43ULL);
x86_l_88f:
	/* 0x88f: jle    8ef <tail_handle_ipv6_from_host+0x8ef> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x88f, 0x8ef, x86_l_8ef);
x86_l_891:
	/* 0x891: cmp    ecx,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 44ULL);
x86_l_894:
	/* 0x894: mov    r15d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_898:
	/* 0x898: je     44a <tail_handle_ipv6_from_host+0x44a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x898, 0x44a, x86_l_44a);
x86_l_89e:
	/* 0x89e: cmp    ecx,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 51ULL);
x86_l_8a1:
	/* 0x8a1: je     4d6 <tail_handle_ipv6_from_host+0x4d6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8a1, 0x4d6, x86_l_4d6);
x86_l_8a7:
	/* 0x8a7: jmp    8f3 <tail_handle_ipv6_from_host+0x8f3> */
	X86_SIM_X86_JMP(0x8a7, 0x8f3, x86_l_8f3);
x86_l_8a9:
	/* 0x8a9: mov    r13d,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967162ULL);
x86_l_8af:
	/* 0x8af: jmp    e39 <tail_handle_ipv6_from_host+0xe39> */
	X86_SIM_X86_JMP(0x8af, 0xe39, x86_l_e39);
x86_l_8b4:
	/* 0x8b4: cmp    r14,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_64, 59ULL);
x86_l_8b8:
	/* 0x8b8: je     e39 <tail_handle_ipv6_from_host+0xe39> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8b8, 0xe39, x86_l_e39);
x86_l_8be:
	/* 0x8be: jmp    d18 <tail_handle_ipv6_from_host+0xd18> */
	X86_SIM_X86_JMP(0x8be, 0xd18, x86_l_d18);
x86_l_8c3:
	/* 0x8c3: cmp    rcx,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 59ULL);
x86_l_8c7:
	/* 0x8c7: je     73a <tail_handle_ipv6_from_host+0x73a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8c7, 0x73a, x86_l_73a);
x86_l_8cd:
	/* 0x8cd: jmp    7f3 <tail_handle_ipv6_from_host+0x7f3> */
	X86_SIM_X86_JMP(0x8cd, 0x7f3, x86_l_7f3);
x86_l_8d2:
	/* 0x8d2: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_8d7:
	/* 0x8d7: movzx  eax,BYTE PTR [rsp+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_8dc:
	/* 0x8dc: lea    r12d,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_8e4:
	/* 0x8e4: cmp    r14b,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 44ULL);
x86_l_8e8:
	/* 0x8e8: je     90d <tail_handle_ipv6_from_host+0x90d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8e8, 0x90d, x86_l_90d);
x86_l_8ea:
	/* 0x8ea: jmp    989 <tail_handle_ipv6_from_host+0x989> */
	X86_SIM_X86_JMP(0x8ea, 0x989, x86_l_989);
x86_l_8ef:
	/* 0x8ef: mov    r15d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8f3:
	/* 0x8f3: mov    r13d,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967140ULL);
x86_l_8f9:
	/* 0x8f9: cmp    ecx,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 44ULL);
x86_l_8fc:
	/* 0x8fc: je     44a <tail_handle_ipv6_from_host+0x44a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8fc, 0x44a, x86_l_44a);
x86_l_902:
	/* 0x902: jmp    73e <tail_handle_ipv6_from_host+0x73e> */
	X86_SIM_X86_JMP(0x902, 0x73e, x86_l_73e);
x86_l_907:
	/* 0x907: mov    r12d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 8ULL);
x86_l_90d:
	/* 0x90d: mov    r14d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_32);
x86_l_910:
	/* 0x910: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_919:
	/* 0x919: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_91e:
	/* 0x91e: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_923:
	/* 0x923: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_926:
	/* 0x926: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_928:
	/* 0x928: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_92d:
	/* 0x92d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_92f:
	/* 0x92f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_931:
	/* 0x931: js     e2f <tail_handle_ipv6_from_host+0xe2f> */
	X86_SIM_X86_JCC(X86_CC_S, 0x931, 0xe2f, x86_l_e2f);
x86_l_937:
	/* 0x937: mov    eax,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_93b:
	/* 0x93b: movzx  ecx,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_940:
	/* 0x940: shl    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_944:
	/* 0x944: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_947:
	/* 0x947: movzx  eax,WORD PTR [rsp+0xa] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 10ULL);
x86_l_94c:
	/* 0x94c: movabs rdx,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1099511627776ULL);
x86_l_956:
	/* 0x956: or     rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_959:
	/* 0x959: test   eax,0xf9ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63999ULL);
x86_l_95e:
	/* 0x95e: cmove  rdx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_64, X86_CC_E);
x86_l_962:
	/* 0x962: movabs rcx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2199023255552ULL);
x86_l_96c:
	/* 0x96c: or     rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_OR);
x86_l_96f:
	/* 0x96f: test   eax,0xf8ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63743ULL);
x86_l_974:
	/* 0x974: cmove  rcx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_978:
	/* 0x978: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_97d:
	/* 0x97d: mov    QWORD PTR [rax+0x58],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_981:
	/* 0x981: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_986:
	/* 0x986: mov    edi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_32);
x86_l_989:
	/* 0x989: movzx  r15d,dil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_RDI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_98d:
	/* 0x98d: lea    esi,[r12+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_992:
	/* 0x992: cmp    r15d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 60ULL);
x86_l_996:
	/* 0x996: ja     b62 <tail_handle_ipv6_from_host+0xb62> */
	X86_SIM_X86_JCC(X86_CC_A, 0x996, 0xb62, x86_l_b62);
x86_l_99c:
	/* 0x99c: mov    eax,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_99f:
	/* 0x99f: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_9a9:
	/* 0x9a9: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_9ad:
	/* 0x9ad: jae    a12 <tail_handle_ipv6_from_host+0xa12> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x9ad, 0xa12, x86_l_a12);
x86_l_9af:
	/* 0x9af: mov    BYTE PTR [rsp+0x7],dil */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_9b4:
	/* 0x9b4: mov    QWORD PTR [rsp+0x18],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_9b9:
	/* 0x9b9: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_9be:
	/* 0x9be: lea    ebp,[r12+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_9c2:
	/* 0x9c2: add    ebp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 40ULL);
x86_l_9c5:
	/* 0x9c5: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9ca:
	/* 0x9ca: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_9cf:
	/* 0x9cf: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_9d2:
	/* 0x9d2: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_9d4:
	/* 0x9d4: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_9d9:
	/* 0x9d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9db:
	/* 0x9db: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_9dd:
	/* 0x9dd: js     e2f <tail_handle_ipv6_from_host+0xe2f> */
	X86_SIM_X86_JCC(X86_CC_S, 0x9dd, 0xe2f, x86_l_e2f);
x86_l_9e3:
	/* 0x9e3: movzx  r14d,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_9e9:
	/* 0x9e9: cmp    r15d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 43ULL);
x86_l_9ed:
	/* 0x9ed: jle    a22 <tail_handle_ipv6_from_host+0xa22> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x9ed, 0xa22, x86_l_a22);
x86_l_9ef:
	/* 0x9ef: cmp    r15d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 44ULL);
x86_l_9f3:
	/* 0x9f3: je     a40 <tail_handle_ipv6_from_host+0xa40> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9f3, 0xa40, x86_l_a40);
x86_l_9f5:
	/* 0x9f5: cmp    r15d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 51ULL);
x86_l_9f9:
	/* 0x9f9: mov    rsi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_9fe:
	/* 0x9fe: jne    a27 <tail_handle_ipv6_from_host+0xa27> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x9fe, 0xa27, x86_l_a27);
x86_l_a00:
	/* 0xa00: movzx  eax,BYTE PTR [rsp+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_a05:
	/* 0xa05: lea    r15d,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_a0d:
	/* 0xa0d: jmp    abc <tail_handle_ipv6_from_host+0xabc> */
	X86_SIM_X86_JMP(0xa0d, 0xabc, x86_l_abc);
x86_l_a12:
	/* 0xa12: mov    r14d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_32);
x86_l_a15:
	/* 0xa15: cmp    rax,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 59ULL);
x86_l_a19:
	/* 0xa19: mov    r15d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a1d:
	/* 0xa1d: jmp    d0d <tail_handle_ipv6_from_host+0xd0d> */
	X86_SIM_X86_JMP(0xa1d, 0xd0d, x86_l_d0d);
x86_l_a22:
	/* 0xa22: mov    rsi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_a27:
	/* 0xa27: movzx  ecx,BYTE PTR [rsp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_a2c:
	/* 0xa2c: movzx  eax,BYTE PTR [rsp+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_a31:
	/* 0xa31: lea    r15d,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_a39:
	/* 0xa39: cmp    cl,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 44ULL);
x86_l_a3c:
	/* 0xa3c: je     a46 <tail_handle_ipv6_from_host+0xa46> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa3c, 0xa46, x86_l_a46);
x86_l_a3e:
	/* 0xa3e: jmp    abc <tail_handle_ipv6_from_host+0xabc> */
	X86_SIM_X86_JMP(0xa3e, 0xabc, x86_l_abc);
x86_l_a40:
	/* 0xa40: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_a46:
	/* 0xa46: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_a4f:
	/* 0xa4f: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a54:
	/* 0xa54: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_a59:
	/* 0xa59: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_a5c:
	/* 0xa5c: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_a5e:
	/* 0xa5e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a63:
	/* 0xa63: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a65:
	/* 0xa65: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a67:
	/* 0xa67: js     e2f <tail_handle_ipv6_from_host+0xe2f> */
	X86_SIM_X86_JCC(X86_CC_S, 0xa67, 0xe2f, x86_l_e2f);
x86_l_a6d:
	/* 0xa6d: mov    eax,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_a71:
	/* 0xa71: movzx  ecx,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_a76:
	/* 0xa76: shl    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_a7a:
	/* 0xa7a: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_a7d:
	/* 0xa7d: movzx  eax,WORD PTR [rsp+0xa] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 10ULL);
x86_l_a82:
	/* 0xa82: movabs rdx,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1099511627776ULL);
x86_l_a8c:
	/* 0xa8c: or     rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_a8f:
	/* 0xa8f: test   eax,0xf9ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63999ULL);
x86_l_a94:
	/* 0xa94: cmove  rdx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_64, X86_CC_E);
x86_l_a98:
	/* 0xa98: movabs rcx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2199023255552ULL);
x86_l_aa2:
	/* 0xaa2: or     rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_OR);
x86_l_aa5:
	/* 0xaa5: test   eax,0xf8ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63743ULL);
x86_l_aaa:
	/* 0xaaa: cmove  rcx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_aae:
	/* 0xaae: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ab3:
	/* 0xab3: mov    QWORD PTR [rax+0x58],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_ab7:
	/* 0xab7: mov    rsi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_abc:
	/* 0xabc: movzx  r12d,r14b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R14, X86_WIDTH_32, X86_WIDTH_8);
x86_l_ac0:
	/* 0xac0: add    esi,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R15, X86_WIDTH_32, X86_ALU_ADD);
x86_l_ac3:
	/* 0xac3: cmp    r12d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 60ULL);
x86_l_ac7:
	/* 0xac7: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_ad1:
	/* 0xad1: ja     fba <tail_handle_ipv6_from_host+0xfba> */
	X86_SIM_X86_JCC(X86_CC_A, 0xad1, 0xfba, x86_l_fba);
x86_l_ad7:
	/* 0xad7: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_ada:
	/* 0xada: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_ade:
	/* 0xade: jae    b50 <tail_handle_ipv6_from_host+0xb50> */
	X86_SIM_X86_JCC(X86_CC_AE, 0xade, 0xb50, x86_l_b50);
x86_l_ae0:
	/* 0xae0: mov    QWORD PTR [rsp+0x18],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ae5:
	/* 0xae5: mov    rax,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_aea:
	/* 0xaea: lea    ebp,[rsi+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_aed:
	/* 0xaed: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_af2:
	/* 0xaf2: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_af7:
	/* 0xaf7: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_afa:
	/* 0xafa: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_afc:
	/* 0xafc: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_b01:
	/* 0xb01: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b03:
	/* 0xb03: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b05:
	/* 0xb05: js     e2f <tail_handle_ipv6_from_host+0xe2f> */
	X86_SIM_X86_JCC(X86_CC_S, 0xb05, 0xe2f, x86_l_e2f);
x86_l_b0b:
	/* 0xb0b: movzx  eax,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_b10:
	/* 0xb10: mov    BYTE PTR [rsp+0x7],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_b14:
	/* 0xb14: cmp    r12d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 43ULL);
x86_l_b18:
	/* 0xb18: jle    b38 <tail_handle_ipv6_from_host+0xb38> */
	X86_SIM_X86_JCC(X86_CC_LE, 0xb18, 0xb38, x86_l_b38);
x86_l_b1a:
	/* 0xb1a: cmp    r12d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 44ULL);
x86_l_b1e:
	/* 0xb1e: je     b73 <tail_handle_ipv6_from_host+0xb73> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb1e, 0xb73, x86_l_b73);
x86_l_b20:
	/* 0xb20: cmp    r12d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 51ULL);
x86_l_b24:
	/* 0xb24: jne    b38 <tail_handle_ipv6_from_host+0xb38> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb24, 0xb38, x86_l_b38);
x86_l_b26:
	/* 0xb26: movzx  eax,BYTE PTR [rsp+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_b2b:
	/* 0xb2b: lea    r15d,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_b33:
	/* 0xb33: jmp    bea <tail_handle_ipv6_from_host+0xbea> */
	X86_SIM_X86_JMP(0xb33, 0xbea, x86_l_bea);
x86_l_b38:
	/* 0xb38: movzx  eax,BYTE PTR [rsp+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_b3d:
	/* 0xb3d: lea    r15d,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_b45:
	/* 0xb45: cmp    r14b,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 44ULL);
x86_l_b49:
	/* 0xb49: je     b79 <tail_handle_ipv6_from_host+0xb79> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb49, 0xb79, x86_l_b79);
x86_l_b4b:
	/* 0xb4b: jmp    bea <tail_handle_ipv6_from_host+0xbea> */
	X86_SIM_X86_JMP(0xb4b, 0xbea, x86_l_bea);
x86_l_b50:
	/* 0xb50: cmp    rax,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 59ULL);
x86_l_b54:
	/* 0xb54: mov    r15d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b58:
	/* 0xb58: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b5d:
	/* 0xb5d: jmp    d0d <tail_handle_ipv6_from_host+0xd0d> */
	X86_SIM_X86_JMP(0xb5d, 0xd0d, x86_l_d0d);
x86_l_b62:
	/* 0xb62: mov    r14d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_32);
x86_l_b65:
	/* 0xb65: mov    r15d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b69:
	/* 0xb69: mov    r12d,DWORD PTR [rsp+0x3c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_b6e:
	/* 0xb6e: jmp    d18 <tail_handle_ipv6_from_host+0xd18> */
	X86_SIM_X86_JMP(0xb6e, 0xd18, x86_l_d18);
x86_l_b73:
	/* 0xb73: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_b79:
	/* 0xb79: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_b82:
	/* 0xb82: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b87:
	/* 0xb87: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_b8c:
	/* 0xb8c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_b8f:
	/* 0xb8f: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_b91:
	/* 0xb91: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_b96:
	/* 0xb96: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b98:
	/* 0xb98: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b9a:
	/* 0xb9a: js     e2f <tail_handle_ipv6_from_host+0xe2f> */
	X86_SIM_X86_JCC(X86_CC_S, 0xb9a, 0xe2f, x86_l_e2f);
x86_l_ba0:
	/* 0xba0: mov    eax,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_ba4:
	/* 0xba4: movzx  ecx,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_ba9:
	/* 0xba9: shl    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_bad:
	/* 0xbad: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_bb0:
	/* 0xbb0: movzx  eax,WORD PTR [rsp+0xa] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 10ULL);
x86_l_bb5:
	/* 0xbb5: movabs rdx,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1099511627776ULL);
x86_l_bbf:
	/* 0xbbf: or     rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_bc2:
	/* 0xbc2: test   eax,0xf9ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63999ULL);
x86_l_bc7:
	/* 0xbc7: cmove  rdx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_64, X86_CC_E);
x86_l_bcb:
	/* 0xbcb: movabs rcx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2199023255552ULL);
x86_l_bd5:
	/* 0xbd5: or     rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_OR);
x86_l_bd8:
	/* 0xbd8: test   eax,0xf8ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63743ULL);
x86_l_bdd:
	/* 0xbdd: cmove  rcx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_be1:
	/* 0xbe1: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_be6:
	/* 0xbe6: mov    QWORD PTR [rax+0x58],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_bea:
	/* 0xbea: movzx  ebp,BYTE PTR [rsp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_bef:
	/* 0xbef: mov    rax,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_bf4:
	/* 0xbf4: add    eax,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_32, X86_ALU_ADD);
x86_l_bf7:
	/* 0xbf7: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_bfc:
	/* 0xbfc: cmp    ebp,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_bff:
	/* 0xbff: ja     fde <tail_handle_ipv6_from_host+0xfde> */
	X86_SIM_X86_JCC(X86_CC_A, 0xbff, 0xfde, x86_l_fde);
x86_l_c05:
	/* 0xc05: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_c07:
	/* 0xc07: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_c11:
	/* 0xc11: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_c15:
	/* 0xc15: jae    cf3 <tail_handle_ipv6_from_host+0xcf3> */
	X86_SIM_X86_JCC(X86_CC_AE, 0xc15, 0xcf3, x86_l_cf3);
x86_l_c1b:
	/* 0xc1b: mov    r14,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c20:
	/* 0xc20: add    r14d,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_c25:
	/* 0xc25: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c2a:
	/* 0xc2a: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_c2f:
	/* 0xc2f: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_c32:
	/* 0xc32: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_c35:
	/* 0xc35: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_c3a:
	/* 0xc3a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c3c:
	/* 0xc3c: mov    r13d,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967162ULL);
x86_l_c42:
	/* 0xc42: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c44:
	/* 0xc44: mov    r15d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c48:
	/* 0xc48: js     e39 <tail_handle_ipv6_from_host+0xe39> */
	X86_SIM_X86_JCC(X86_CC_S, 0xc48, 0xe39, x86_l_e39);
x86_l_c4e:
	/* 0xc4e: cmp    ebp,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 43ULL);
x86_l_c51:
	/* 0xc51: jle    c61 <tail_handle_ipv6_from_host+0xc61> */
	X86_SIM_X86_JCC(X86_CC_LE, 0xc51, 0xc61, x86_l_c61);
x86_l_c53:
	/* 0xc53: cmp    ebp,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 44ULL);
x86_l_c56:
	/* 0xc56: je     c76 <tail_handle_ipv6_from_host+0xc76> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc56, 0xc76, x86_l_c76);
x86_l_c58:
	/* 0xc58: cmp    ebp,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 51ULL);
x86_l_c5b:
	/* 0xc5b: je     ce8 <tail_handle_ipv6_from_host+0xce8> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc5b, 0xce8, x86_l_ce8);
x86_l_c61:
	/* 0xc61: mov    r13d,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967140ULL);
x86_l_c67:
	/* 0xc67: cmp    BYTE PTR [rsp+0x7],0x2c */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30064771116ULL);
x86_l_c6c:
	/* 0xc6c: mov    r15d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c70:
	/* 0xc70: jne    e39 <tail_handle_ipv6_from_host+0xe39> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xc70, 0xe39, x86_l_e39);
x86_l_c76:
	/* 0xc76: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_c7f:
	/* 0xc7f: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c84:
	/* 0xc84: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_c89:
	/* 0xc89: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_c8c:
	/* 0xc8c: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_c8f:
	/* 0xc8f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_c94:
	/* 0xc94: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c96:
	/* 0xc96: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c98:
	/* 0xc98: js     e2f <tail_handle_ipv6_from_host+0xe2f> */
	X86_SIM_X86_JCC(X86_CC_S, 0xc98, 0xe2f, x86_l_e2f);
x86_l_c9e:
	/* 0xc9e: mov    eax,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_ca2:
	/* 0xca2: movzx  ecx,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_ca7:
	/* 0xca7: shl    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_cab:
	/* 0xcab: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_cae:
	/* 0xcae: movzx  eax,WORD PTR [rsp+0xa] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 10ULL);
x86_l_cb3:
	/* 0xcb3: movabs rdx,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1099511627776ULL);
x86_l_cbd:
	/* 0xcbd: or     rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_cc0:
	/* 0xcc0: test   eax,0xf9ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63999ULL);
x86_l_cc5:
	/* 0xcc5: cmove  rdx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_64, X86_CC_E);
x86_l_cc9:
	/* 0xcc9: movabs rcx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2199023255552ULL);
x86_l_cd3:
	/* 0xcd3: or     rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_OR);
x86_l_cd6:
	/* 0xcd6: test   eax,0xf8ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63743ULL);
x86_l_cdb:
	/* 0xcdb: cmove  rcx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_cdf:
	/* 0xcdf: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ce4:
	/* 0xce4: mov    QWORD PTR [rax+0x58],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_ce8:
	/* 0xce8: mov    r13d,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967140ULL);
x86_l_cee:
	/* 0xcee: jmp    e35 <tail_handle_ipv6_from_host+0xe35> */
	X86_SIM_X86_JMP(0xcee, 0xe35, x86_l_e35);
x86_l_cf3:
	/* 0xcf3: movzx  ecx,BYTE PTR [rsp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_cf8:
	/* 0xcf8: mov    r14d,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RCX, X86_WIDTH_32);
x86_l_cfb:
	/* 0xcfb: cmp    rax,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 59ULL);
x86_l_cff:
	/* 0xcff: mov    r15d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d03:
	/* 0xd03: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_d08:
	/* 0xd08: mov    rsi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d0d:
	/* 0xd0d: mov    r12d,DWORD PTR [rsp+0x3c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_d12:
	/* 0xd12: je     e39 <tail_handle_ipv6_from_host+0xe39> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd12, 0xe39, x86_l_e39);
x86_l_d18:
	/* 0xd18: add    esi,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R12, X86_WIDTH_32, X86_ALU_ADD);
x86_l_d1b:
	/* 0xd1b: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d20:
	/* 0xd20: mov    BYTE PTR [r13+0x24],r14b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R14, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_d24:
	/* 0xd24: mov    DWORD PTR [r13+0x50],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_d28:
	/* 0xd28: cmp    r14b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 6ULL);
x86_l_d2c:
	/* 0xd2c: jne    d37 <tail_handle_ipv6_from_host+0xd37> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xd2c, 0xd37, x86_l_d37);
x86_l_d2e:
	/* 0xd2e: mov    rax,QWORD PTR [rip+0x1a3fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&cilium_ct6_global)));
x86_l_d35:
	/* 0xd35: jmp    d3e <tail_handle_ipv6_from_host+0xd3e> */
	X86_SIM_X86_JMP(0xd35, 0xd3e, x86_l_d3e);
x86_l_d37:
	/* 0xd37: mov    rax,QWORD PTR [rip+0x1a3fa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&cilium_ct_any6_global)));
x86_l_d3e:
	/* 0xd3e: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_d43:
	/* 0xd43: movabs rcx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2199023255552ULL);
x86_l_d4d:
	/* 0xd4d: movabs rdi,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_64, 1099511627776ULL);
x86_l_d57:
	/* 0xd57: mov    r12,QWORD PTR [r13+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_d5b:
	/* 0xd5b: mov    BYTE PTR [r13+0x25],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 158913789953ULL);
x86_l_d60:
	/* 0xd60: je     e47 <tail_handle_ipv6_from_host+0xe47> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd60, 0xe47, x86_l_e47);
x86_l_d66:
	/* 0xd66: movzx  eax,r14b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R14, X86_WIDTH_32, X86_WIDTH_8);
x86_l_d6a:
	/* 0xd6a: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_d6d:
	/* 0xd6d: je     e47 <tail_handle_ipv6_from_host+0xe47> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd6d, 0xe47, x86_l_e47);
x86_l_d73:
	/* 0xd73: cmp    eax,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 58ULL);
x86_l_d76:
	/* 0xd76: jne    ed6 <tail_handle_ipv6_from_host+0xed6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xd76, 0xed6, x86_l_ed6);
x86_l_d7c:
	/* 0xd7c: mov    WORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_d83:
	/* 0xd83: test   r12,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_d86:
	/* 0xd86: mov    DWORD PTR [rsp],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d8a:
	/* 0xd8a: jne    e2f <tail_handle_ipv6_from_host+0xe2f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xd8a, 0xe2f, x86_l_e2f);
x86_l_d90:
	/* 0xd90: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_d93:
	/* 0xd93: lea    rdx,[rsp+0x37] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 55ULL);
x86_l_d98:
	/* 0xd98: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_d9d:
	/* 0xd9d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_da0:
	/* 0xda0: mov    rbp,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RSI, X86_WIDTH_64);
x86_l_da3:
	/* 0xda3: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_da8:
	/* 0xda8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_daa:
	/* 0xdaa: mov    r13d,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967161ULL);
x86_l_db0:
	/* 0xdb0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_db2:
	/* 0xdb2: js     e35 <tail_handle_ipv6_from_host+0xe35> */
	X86_SIM_X86_JCC(X86_CC_S, 0xdb2, 0xe35, x86_l_e35);
x86_l_db8:
	/* 0xdb8: movzx  eax,BYTE PTR [rsp+0x37] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 55ULL);
x86_l_dbd:
	/* 0xdbd: cmp    al,0x81 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 129ULL);
x86_l_dbf:
	/* 0xdbf: jg     de1 <tail_handle_ipv6_from_host+0xde1> */
	X86_SIM_X86_JCC(X86_CC_G, 0xdbf, 0xde1, x86_l_de1);
x86_l_dc1:
	/* 0xdc1: lea    esi,[rbp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_dc4:
	/* 0xdc4: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_dc9:
	/* 0xdc9: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_dce:
	/* 0xdce: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_dd1:
	/* 0xdd1: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_dd6:
	/* 0xdd6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dd8:
	/* 0xdd8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_dda:
	/* 0xdda: js     e35 <tail_handle_ipv6_from_host+0xe35> */
	X86_SIM_X86_JCC(X86_CC_S, 0xdda, 0xe35, x86_l_e35);
x86_l_ddc:
	/* 0xddc: movzx  eax,BYTE PTR [rsp+0x37] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 55ULL);
x86_l_de1:
	/* 0xde1: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_de6:
	/* 0xde6: mov    DWORD PTR [rcx+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_ded:
	/* 0xded: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_df0:
	/* 0xdf0: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_df3:
	/* 0xdf3: jle    f5e <tail_handle_ipv6_from_host+0xf5e> */
	X86_SIM_X86_JCC(X86_CC_LE, 0xdf3, 0xf5e, x86_l_f5e);
x86_l_df9:
	/* 0xdf9: lea    ecx,[rax-0x3] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551613ULL);
x86_l_dfc:
	/* 0xdfc: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_dff:
	/* 0xdff: jb     1026 <tail_handle_ipv6_from_host+0x1026> */
	X86_SIM_X86_JCC(X86_CC_B, 0xdff, 0x1026, x86_l_1026);
x86_l_e05:
	/* 0xe05: cmp    eax,0x80 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 128ULL);
x86_l_e0a:
	/* 0xe0a: je     fcd <tail_handle_ipv6_from_host+0xfcd> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe0a, 0xfcd, x86_l_fcd);
x86_l_e10:
	/* 0xe10: cmp    eax,0x81 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 129ULL);
x86_l_e15:
	/* 0xe15: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e1a:
	/* 0xe1a: jne    1030 <tail_handle_ipv6_from_host+0x1030> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe1a, 0x1030, x86_l_1030);
x86_l_e20:
	/* 0xe20: movzx  eax,WORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_e25:
	/* 0xe25: mov    WORD PTR [r13+0x22],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_e2a:
	/* 0xe2a: jmp    1030 <tail_handle_ipv6_from_host+0x1030> */
	X86_SIM_X86_JMP(0xe2a, 0x1030, x86_l_1030);
x86_l_e2f:
	/* 0xe2f: mov    r13d,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967162ULL);
x86_l_e35:
	/* 0xe35: mov    r15d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e39:
	/* 0xe39: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e3e:
	/* 0xe3e: mov    DWORD PTR [rax+0x4c],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_e42:
	/* 0xe42: jmp    73e <tail_handle_ipv6_from_host+0x73e> */
	X86_SIM_X86_JMP(0xe42, 0x73e, x86_l_73e);
x86_l_e47:
	/* 0xe47: mov    rbp,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R13, X86_WIDTH_64);
x86_l_e4a:
	/* 0xe4a: add    rbp,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_e4e:
	/* 0xe4e: mov    rax,QWORD PTR [rip+0x1a3f6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_e55:
	/* 0xe55: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e58:
	/* 0xe58: je     ef3 <tail_handle_ipv6_from_host+0xef3> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe58, 0xef3, x86_l_ef3);
x86_l_e5e:
	/* 0xe5e: mov    rax,QWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e61:
	/* 0xe61: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_e66:
	/* 0xe66: mov    QWORD PTR [rdx],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e6d:
	/* 0xe6d: mov    DWORD PTR [rdx],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e70:
	/* 0xe70: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_e73:
	/* 0xe73: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_e77:
	/* 0xe77: mov    BYTE PTR [rdx+0x4],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_e7a:
	/* 0xe7a: test   r12,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_e7d:
	/* 0xe7d: jne    13fb <tail_handle_ipv6_from_host+0x13fb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe7d, 0x13fb, x86_l_13fb);
x86_l_e83:
	/* 0xe83: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_e88:
	/* 0xe88: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_e8b:
	/* 0xe8b: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_e8e:
	/* 0xe8e: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_e91:
	/* 0xe91: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_e96:
	/* 0xe96: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e98:
	/* 0xe98: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_e9a:
	/* 0xe9a: js     f3b <tail_handle_ipv6_from_host+0xf3b> */
	X86_SIM_X86_JCC(X86_CC_S, 0xe9a, 0xf3b, x86_l_f3b);
x86_l_ea0:
	/* 0xea0: mov    DWORD PTR [rsp],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ea4:
	/* 0xea4: movabs rdi,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_64, 1099511627776ULL);
x86_l_eae:
	/* 0xeae: test   r12,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_eb1:
	/* 0xeb1: jne    1428 <tail_handle_ipv6_from_host+0x1428> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xeb1, 0x1428, x86_l_1428);
x86_l_eb7:
	/* 0xeb7: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_ebc:
	/* 0xebc: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ec1:
	/* 0xec1: mov    QWORD PTR [rax],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ec4:
	/* 0xec4: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_ec7:
	/* 0xec7: movabs rcx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2199023255552ULL);
x86_l_ed1:
	/* 0xed1: jmp    1040 <tail_handle_ipv6_from_host+0x1040> */
	X86_SIM_X86_JMP(0xed1, 0x1040, x86_l_1040);
x86_l_ed6:
	/* 0xed6: mov    rax,QWORD PTR [rip+0x1a3f6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_extended_ip_protocols)));
x86_l_edd:
	/* 0xedd: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ee0:
	/* 0xee0: je     f53 <tail_handle_ipv6_from_host+0xf53> */
	X86_SIM_X86_JCC(X86_CC_E, 0xee0, 0xf53, x86_l_f53);
x86_l_ee2:
	/* 0xee2: mov    DWORD PTR [rsp],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ee6:
	/* 0xee6: mov    DWORD PTR [r13+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_eee:
	/* 0xeee: jmp    1040 <tail_handle_ipv6_from_host+0x1040> */
	X86_SIM_X86_JMP(0xeee, 0x1040, x86_l_1040);
x86_l_ef3:
	/* 0xef3: mov    DWORD PTR [rsp],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ef7:
	/* 0xef7: test   r12,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_efa:
	/* 0xefa: jne    1497 <tail_handle_ipv6_from_host+0x1497> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xefa, 0x1497, x86_l_1497);
x86_l_f00:
	/* 0xf00: mov    r15,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RCX, X86_WIDTH_64);
x86_l_f03:
	/* 0xf03: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_f08:
	/* 0xf08: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_f0b:
	/* 0xf0b: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_f0e:
	/* 0xf0e: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_f11:
	/* 0xf11: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_f16:
	/* 0xf16: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f18:
	/* 0xf18: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_f1b:
	/* 0xf1b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_f1d:
	/* 0xf1d: mov    rcx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_f20:
	/* 0xf20: movabs rdi,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_64, 1099511627776ULL);
x86_l_f2a:
	/* 0xf2a: jns    1040 <tail_handle_ipv6_from_host+0x1040> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xf2a, 0x1040, x86_l_1040);
x86_l_f30:
	/* 0xf30: mov    r13d,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967161ULL);
x86_l_f36:
	/* 0xf36: jmp    e35 <tail_handle_ipv6_from_host+0xe35> */
	X86_SIM_X86_JMP(0xf36, 0xe35, x86_l_e35);
x86_l_f3b:
	/* 0xf3b: mov    r13d,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967161ULL);
x86_l_f41:
	/* 0xf41: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_f46:
	/* 0xf46: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_f4b:
	/* 0xf4b: mov    QWORD PTR [rax],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f4e:
	/* 0xf4e: jmp    e39 <tail_handle_ipv6_from_host+0xe39> */
	X86_SIM_X86_JMP(0xf4e, 0xe39, x86_l_e39);
x86_l_f53:
	/* 0xf53: mov    r13d,0xffffff77 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967159ULL);
x86_l_f59:
	/* 0xf59: jmp    e39 <tail_handle_ipv6_from_host+0xe39> */
	X86_SIM_X86_JMP(0xf59, 0xe39, x86_l_e39);
x86_l_f5e:
	/* 0xf5e: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f61:
	/* 0xf61: je     1026 <tail_handle_ipv6_from_host+0x1026> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf61, 0x1026, x86_l_1026);
x86_l_f67:
	/* 0xf67: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_f6a:
	/* 0xf6a: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f6f:
	/* 0xf6f: jne    1030 <tail_handle_ipv6_from_host+0x1030> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf6f, 0x1030, x86_l_1030);
x86_l_f75:
	/* 0xf75: mov    r15d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f78:
	/* 0xf78: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_f81:
	/* 0xf81: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_f8a:
	/* 0xf8a: movabs rax,0x6c0269020f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 463896904207ULL);
x86_l_f94:
	/* 0xf94: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_f99:
	/* 0xf99: mov    rdi,QWORD PTR [rip+0x1a3f6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_fa0:
	/* 0xfa0: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
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
	/* 0xfaf: je     ffe <tail_handle_ipv6_from_host+0xffe> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfaf, 0xffe, x86_l_ffe);
x86_l_fb1:
	/* 0xfb1: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_fb4:
	/* 0xfb4: add    QWORD PTR [rax+0x8],r15 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_fb8:
	/* 0xfb8: jmp    1026 <tail_handle_ipv6_from_host+0x1026> */
	X86_SIM_X86_JMP(0xfb8, 0x1026, x86_l_1026);
x86_l_fba:
	/* 0xfba: mov    r15d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fbe:
	/* 0xfbe: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_fc3:
	/* 0xfc3: mov    r12d,DWORD PTR [rsp+0x3c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_fc8:
	/* 0xfc8: jmp    d18 <tail_handle_ipv6_from_host+0xd18> */
	X86_SIM_X86_JMP(0xfc8, 0xd18, x86_l_d18);
x86_l_fcd:
	/* 0xfcd: movzx  eax,WORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_fd2:
	/* 0xfd2: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_fd7:
	/* 0xfd7: mov    WORD PTR [r13+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_fdc:
	/* 0xfdc: jmp    1030 <tail_handle_ipv6_from_host+0x1030> */
	X86_SIM_X86_JMP(0xfdc, 0x1030, x86_l_1030);
x86_l_fde:
	/* 0xfde: movzx  eax,BYTE PTR [rsp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_fe3:
	/* 0xfe3: mov    r14d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_32);
x86_l_fe6:
	/* 0xfe6: mov    r15d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fea:
	/* 0xfea: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_fef:
	/* 0xfef: mov    rsi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ff4:
	/* 0xff4: mov    r12d,DWORD PTR [rsp+0x3c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_ff9:
	/* 0xff9: jmp    d18 <tail_handle_ipv6_from_host+0xd18> */
	X86_SIM_X86_JMP(0xff9, 0xd18, x86_l_d18);
x86_l_ffe:
	/* 0xffe: mov    QWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_1007:
	/* 0x1007: mov    QWORD PTR [rsp+0x10],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_100c:
	/* 0x100c: mov    rdi,QWORD PTR [rip+0x1a3f6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1013:
	/* 0x1013: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1018:
	/* 0x1018: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_101d:
	/* 0x101d: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1022:
	/* 0x1022: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1024:
	/* 0x1024: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1026:
	/* 0x1026: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_102b:
	/* 0x102b: or     BYTE PTR [r13+0x25],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R13, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 158913789954ULL);
x86_l_1030:
	/* 0x1030: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_1033:
	/* 0x1033: movabs rcx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2199023255552ULL);
x86_l_103d:
	/* 0x103d: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_1040:
	/* 0x1040: movzx  ebp,BYTE PTR [r13+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 36ULL);
x86_l_1045:
	/* 0x1045: mov    DWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_104d:
	/* 0x104d: mov    rax,QWORD PTR [rip+0x1a3f6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_1054:
	/* 0x1054: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1057:
	/* 0x1057: je     10e9 <tail_handle_ipv6_from_host+0x10e9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1057, 0x10e9, x86_l_10e9);
x86_l_105d:
	/* 0x105d: and    rdi,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_1060:
	/* 0x1060: je     10e9 <tail_handle_ipv6_from_host+0x10e9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1060, 0x10e9, x86_l_10e9);
x86_l_1066:
	/* 0x1066: mov    r15,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSI, X86_WIDTH_64);
x86_l_1069:
	/* 0x1069: mov    r14d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_106c:
	/* 0x106c: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1075:
	/* 0x1075: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_107e:
	/* 0x107e: movabs rax,0x6c0269020f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 463896904207ULL);
x86_l_1088:
	/* 0x1088: add    rax,0x39fffa */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 3801082ULL);
x86_l_108e:
	/* 0x108e: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1093:
	/* 0x1093: mov    rdi,QWORD PTR [rip+0x1a3f6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_109a:
	/* 0x109a: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_109f:
	/* 0x109f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_10a4:
	/* 0x10a4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10a6:
	/* 0x10a6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10a9:
	/* 0x10a9: je     10b4 <tail_handle_ipv6_from_host+0x10b4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10a9, 0x10b4, x86_l_10b4);
x86_l_10ab:
	/* 0x10ab: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_10ae:
	/* 0x10ae: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_10b2:
	/* 0x10b2: jmp    10dc <tail_handle_ipv6_from_host+0x10dc> */
	X86_SIM_X86_JMP(0x10b2, 0x10dc, x86_l_10dc);
x86_l_10b4:
	/* 0x10b4: mov    QWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_10bd:
	/* 0x10bd: mov    QWORD PTR [rsp+0x10],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10c2:
	/* 0x10c2: mov    rdi,QWORD PTR [rip+0x1a3f6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_10c9:
	/* 0x10c9: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_10ce:
	/* 0x10ce: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10d3:
	/* 0x10d3: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_10d8:
	/* 0x10d8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10da:
	/* 0x10da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10dc:
	/* 0x10dc: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_10df:
	/* 0x10df: movabs rcx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2199023255552ULL);
x86_l_10e9:
	/* 0x10e9: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_10ed:
	/* 0x10ed: mov    BYTE PTR [rsp+0x28],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_10f2:
	/* 0x10f2: jne    1140 <tail_handle_ipv6_from_host+0x1140> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x10f2, 0x1140, x86_l_1140);
x86_l_10f4:
	/* 0x10f4: and    r12,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_10f7:
	/* 0x10f7: jne    1140 <tail_handle_ipv6_from_host+0x1140> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x10f7, 0x1140, x86_l_1140);
x86_l_10f9:
	/* 0x10f9: add    esi,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 12ULL);
x86_l_10fc:
	/* 0x10fc: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1101:
	/* 0x1101: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1106:
	/* 0x1106: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1109:
	/* 0x1109: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_110e:
	/* 0x110e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1110:
	/* 0x1110: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1112:
	/* 0x1112: js     118f <tail_handle_ipv6_from_host+0x118f> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1112, 0x118f, x86_l_118f);
x86_l_1114:
	/* 0x1114: mov    ebp,DWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1118:
	/* 0x1118: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_111a:
	/* 0x111a: and    eax,0x1200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4608ULL);
x86_l_111f:
	/* 0x111f: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1122:
	/* 0x1122: cmp    eax,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 512ULL);
x86_l_1127:
	/* 0x1127: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_112a:
	/* 0x112a: test   ebp,0x500 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RBP, X86_WIDTH_32, 1280ULL);
x86_l_1130:
	/* 0x1130: jne    14a2 <tail_handle_ipv6_from_host+0x14a2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1130, 0x14a2, x86_l_14a2);
x86_l_1136:
	/* 0x1136: mov    r12b,al */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_8);
x86_l_1139:
	/* 0x1139: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_113e:
	/* 0x113e: jmp    1147 <tail_handle_ipv6_from_host+0x1147> */
	X86_SIM_X86_JMP(0x113e, 0x1147, x86_l_1147);
x86_l_1140:
	/* 0x1140: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1143:
	/* 0x1143: mov    ebp,DWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1147:
	/* 0x1147: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_114c:
	/* 0x114c: mov    rdi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1151:
	/* 0x1151: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_1154:
	/* 0x1154: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1156:
	/* 0x1156: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1159:
	/* 0x1159: je     15c4 <tail_handle_ipv6_from_host+0x15c4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1159, 0x15c4, x86_l_15c4);
x86_l_115f:
	/* 0x115f: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1162:
	/* 0x1162: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1165:
	/* 0x1165: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_1167:
	/* 0x1167: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1169:
	/* 0x1169: test   cl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_116c:
	/* 0x116c: je     1291 <tail_handle_ipv6_from_host+0x1291> */
	X86_SIM_X86_JCC(X86_CC_E, 0x116c, 0x1291, x86_l_1291);
x86_l_1172:
	/* 0x1172: mov    rcx,QWORD PTR [rip+0x1a3f6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1179:
	/* 0x1179: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_117c:
	/* 0x117c: je     11a2 <tail_handle_ipv6_from_host+0x11a2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x117c, 0x11a2, x86_l_11a2);
x86_l_117e:
	/* 0x117e: mov    rcx,QWORD PTR [rip+0x1a3f6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1185:
	/* 0x1185: imul   r14d,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_1189:
	/* 0x1189: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_118d:
	/* 0x118d: jmp    11a8 <tail_handle_ipv6_from_host+0x11a8> */
	X86_SIM_X86_JMP(0x118d, 0x11a8, x86_l_11a8);
x86_l_118f:
	/* 0x118f: mov    DWORD PTR [r13+0x4c],0xffffff79 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 330712481657ULL);
x86_l_1197:
	/* 0x1197: mov    r13d,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967161ULL);
x86_l_119d:
	/* 0x119d: jmp    73a <tail_handle_ipv6_from_host+0x73a> */
	X86_SIM_X86_JMP(0x119d, 0x73a, x86_l_73a);
x86_l_11a2:
	/* 0x11a2: mov    r14d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 60ULL);
x86_l_11a8:
	/* 0x11a8: cmp    BYTE PTR [rsp+0x28],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691846ULL);
x86_l_11ad:
	/* 0x11ad: jne    11ec <tail_handle_ipv6_from_host+0x11ec> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x11ad, 0x11ec, x86_l_11ec);
x86_l_11af:
	/* 0x11af: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_11b1:
	/* 0x11b1: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_11b3:
	/* 0x11b3: shr    ecx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_11b6:
	/* 0x11b6: and    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_11b9:
	/* 0x11b9: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_11bb:
	/* 0x11bb: mov    WORD PTR [r15+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_11c0:
	/* 0x11c0: test   al,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 16ULL);
x86_l_11c2:
	/* 0x11c2: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_11c7:
	/* 0x11c7: mov    r14d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 21600ULL);
x86_l_11cd:
	/* 0x11cd: cmove  r14d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R14, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_11d1:
	/* 0x11d1: mov    rax,QWORD PTR [rip+0x1a3f6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_11d8:
	/* 0x11d8: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11db:
	/* 0x11db: je     11ec <tail_handle_ipv6_from_host+0x11ec> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11db, 0x11ec, x86_l_11ec);
x86_l_11dd:
	/* 0x11dd: mov    rax,QWORD PTR [rip+0x1a3f6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_11e4:
	/* 0x11e4: imul   r14d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_11e8:
	/* 0x11e8: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_11ec:
	/* 0x11ec: mov    r13d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBP, X86_WIDTH_32);
x86_l_11ef:
	/* 0x11ef: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_11f3:
	/* 0x11f3: mov    rax,QWORD PTR [rip+0x1a3f6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_11fa:
	/* 0x11fa: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11fd:
	/* 0x11fd: je     120e <tail_handle_ipv6_from_host+0x120e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11fd, 0x120e, x86_l_120e);
x86_l_11ff:
	/* 0x11ff: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_1204:
	/* 0x1204: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1206:
	/* 0x1206: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1208:
	/* 0x1208: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_120c:
	/* 0x120c: jmp    1231 <tail_handle_ipv6_from_host+0x1231> */
	X86_SIM_X86_JMP(0x120c, 0x1231, x86_l_1231);
x86_l_120e:
	/* 0x120e: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1213:
	/* 0x1213: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1215:
	/* 0x1215: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1217:
	/* 0x1217: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_121b:
	/* 0x121b: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_1225:
	/* 0x1225: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1228:
	/* 0x1228: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_122d:
	/* 0x122d: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_1231:
	/* 0x1231: add    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1234:
	/* 0x1234: mov    DWORD PTR [r15+0x20],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1238:
	/* 0x1238: movzx  ecx,BYTE PTR [r15+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_123d:
	/* 0x123d: mov    edx,DWORD PTR [r15+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1241:
	/* 0x1241: and    r13b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_1245:
	/* 0x1245: mov    rsi,QWORD PTR [rip+0x1a3f6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_124c:
	/* 0x124c: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_124f:
	/* 0x124f: je     1262 <tail_handle_ipv6_from_host+0x1262> */
	X86_SIM_X86_JCC(X86_CC_E, 0x124f, 0x1262, x86_l_1262);
x86_l_1251:
	/* 0x1251: mov    rsi,QWORD PTR [rip+0x1a3f6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1258:
	/* 0x1258: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_125a:
	/* 0x125a: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_125d:
	/* 0x125d: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1260:
	/* 0x1260: jmp    1267 <tail_handle_ipv6_from_host+0x1267> */
	X86_SIM_X86_JMP(0x1260, 0x1267, x86_l_1267);
x86_l_1262:
	/* 0x1262: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_1267:
	/* 0x1267: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1269:
	/* 0x1269: or     r13b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_126c:
	/* 0x126c: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_126e:
	/* 0x126e: jb     1277 <tail_handle_ipv6_from_host+0x1277> */
	X86_SIM_X86_JCC(X86_CC_B, 0x126e, 0x1277, x86_l_1277);
x86_l_1270:
	/* 0x1270: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1272:
	/* 0x1272: cmp    cl,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R13, X86_WIDTH_8);
x86_l_1275:
	/* 0x1275: je     1288 <tail_handle_ipv6_from_host+0x1288> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1275, 0x1288, x86_l_1288);
x86_l_1277:
	/* 0x1277: mov    BYTE PTR [r15+0x2a],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_127b:
	/* 0x127b: mov    DWORD PTR [r15+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_127f:
	/* 0x127f: mov    rax,QWORD PTR [rip+0x1a3f6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_1286:
	/* 0x1286: mov    edx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1288:
	/* 0x1288: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_128d:
	/* 0x128d: mov    DWORD PTR [r13+0x48],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1291:
	/* 0x1291: mov    rax,QWORD PTR [rip+0x1a3f6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_1298:
	/* 0x1298: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_129b:
	/* 0x129b: je     12a9 <tail_handle_ipv6_from_host+0x12a9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x129b, 0x12a9, x86_l_12a9);
x86_l_129d:
	/* 0x129d: inc QWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 16ULL);
x86_l_12a2:
	/* 0x12a2: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12a4:
	/* 0x12a4: add QWORD PTR [r15+0x18],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R15, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_12a9:
	/* 0x12a9: cmp    r12d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 2ULL);
x86_l_12ad:
	/* 0x12ad: je     12fc <tail_handle_ipv6_from_host+0x12fc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12ad, 0x12fc, x86_l_12fc);
x86_l_12af:
	/* 0x12af: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_12b3:
	/* 0x12b3: jne    13e3 <tail_handle_ipv6_from_host+0x13e3> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x12b3, 0x13e3, x86_l_13e3);
x86_l_12b9:
	/* 0x12b9: movzx  eax,WORD PTR [r15+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_12be:
	/* 0x12be: test   al,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 3ULL);
x86_l_12c0:
	/* 0x12c0: je     13e3 <tail_handle_ipv6_from_host+0x13e3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12c0, 0x13e3, x86_l_13e3);
x86_l_12c6:
	/* 0x12c6: mov    WORD PTR [r15+0x2a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 180388626432ULL);
x86_l_12cd:
	/* 0x12cd: and    eax,0xffec */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 65516ULL);
x86_l_12d2:
	/* 0x12d2: mov    WORD PTR [r15+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_12d7:
	/* 0x12d7: mov    r14,QWORD PTR [rip+0x1a3f6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_12de:
	/* 0x12de: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12e2:
	/* 0x12e2: je     14f8 <tail_handle_ipv6_from_host+0x14f8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12e2, 0x14f8, x86_l_14f8);
x86_l_12e8:
	/* 0x12e8: mov    rcx,QWORD PTR [rip+0x1a3f6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_12ef:
	/* 0x12ef: imul   r13d,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_12f3:
	/* 0x12f3: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_12f7:
	/* 0x12f7: jmp    14fe <tail_handle_ipv6_from_host+0x14fe> */
	X86_SIM_X86_JMP(0x12f7, 0x14fe, x86_l_14fe);
x86_l_12fc:
	/* 0x12fc: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_12fe:
	/* 0x12fe: and    eax,0x400 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 1024ULL);
x86_l_1303:
	/* 0x1303: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1306:
	/* 0x1306: mov    ax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 3ULL);
x86_l_130a:
	/* 0x130a: sbb    ax,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_16, X86_ALU_SBB, 0ULL);
x86_l_130e:
	/* 0x130e: or     WORD PTR [r15+0x24],ax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R15, X86_RAX, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 36ULL);
x86_l_1313:
	/* 0x1313: mov    r14,QWORD PTR [rip+0x1a3f6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_131a:
	/* 0x131a: mov    eax,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_131d:
	/* 0x131d: mov    DWORD PTR [r13+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1321:
	/* 0x1321: mov    eax,DWORD PTR [r15+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1325:
	/* 0x1325: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1327:
	/* 0x1327: test   al,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 3ULL);
x86_l_1329:
	/* 0x1329: jne    13e3 <tail_handle_ipv6_from_host+0x13e3> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1329, 0x13e3, x86_l_13e3);
x86_l_132f:
	/* 0x132f: mov    r12,QWORD PTR [rip+0x1a3f6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1336:
	/* 0x1336: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_133b:
	/* 0x133b: je     1352 <tail_handle_ipv6_from_host+0x1352> */
	X86_SIM_X86_JCC(X86_CC_E, 0x133b, 0x1352, x86_l_1352);
x86_l_133d:
	/* 0x133d: mov    rax,QWORD PTR [rip+0x1a3f6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1344:
	/* 0x1344: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1346:
	/* 0x1346: add    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1348:
	/* 0x1348: lea    r13d,[rax+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_134c:
	/* 0x134c: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1350:
	/* 0x1350: jmp    1358 <tail_handle_ipv6_from_host+0x1358> */
	X86_SIM_X86_JMP(0x1350, 0x1358, x86_l_1358);
x86_l_1352:
	/* 0x1352: mov    r13d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 10ULL);
x86_l_1358:
	/* 0x1358: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_135b:
	/* 0x135b: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1360:
	/* 0x1360: je     1371 <tail_handle_ipv6_from_host+0x1371> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1360, 0x1371, x86_l_1371);
x86_l_1362:
	/* 0x1362: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_1367:
	/* 0x1367: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1369:
	/* 0x1369: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_136b:
	/* 0x136b: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_136f:
	/* 0x136f: jmp    1394 <tail_handle_ipv6_from_host+0x1394> */
	X86_SIM_X86_JMP(0x136f, 0x1394, x86_l_1394);
x86_l_1371:
	/* 0x1371: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1376:
	/* 0x1376: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1378:
	/* 0x1378: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_137a:
	/* 0x137a: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_137e:
	/* 0x137e: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_1388:
	/* 0x1388: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_138b:
	/* 0x138b: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1390:
	/* 0x1390: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_1394:
	/* 0x1394: add    r13d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1397:
	/* 0x1397: mov    DWORD PTR [r15+0x20],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_139b:
	/* 0x139b: movzx  ecx,BYTE PTR [r15+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_13a0:
	/* 0x13a0: mov    edx,DWORD PTR [r15+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_13a4:
	/* 0x13a4: and    bpl,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_13a8:
	/* 0x13a8: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13ad:
	/* 0x13ad: je     13c0 <tail_handle_ipv6_from_host+0x13c0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13ad, 0x13c0, x86_l_13c0);
x86_l_13af:
	/* 0x13af: mov    rsi,QWORD PTR [rip+0x1a3f6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_13b6:
	/* 0x13b6: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13b8:
	/* 0x13b8: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_13bb:
	/* 0x13bb: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_13be:
	/* 0x13be: jmp    13c5 <tail_handle_ipv6_from_host+0x13c5> */
	X86_SIM_X86_JMP(0x13be, 0x13c5, x86_l_13c5);
x86_l_13c0:
	/* 0x13c0: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_13c5:
	/* 0x13c5: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_13c7:
	/* 0x13c7: or     bpl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_13ca:
	/* 0x13ca: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_13cc:
	/* 0x13cc: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_13d1:
	/* 0x13d1: jb     13d8 <tail_handle_ipv6_from_host+0x13d8> */
	X86_SIM_X86_JCC(X86_CC_B, 0x13d1, 0x13d8, x86_l_13d8);
x86_l_13d3:
	/* 0x13d3: cmp    cl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_8);
x86_l_13d6:
	/* 0x13d6: je     13e3 <tail_handle_ipv6_from_host+0x13e3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13d6, 0x13e3, x86_l_13e3);
x86_l_13d8:
	/* 0x13d8: mov    BYTE PTR [r15+0x2a],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_13dc:
	/* 0x13dc: mov    DWORD PTR [r15+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_13e0:
	/* 0x13e0: mov    eax,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13e3:
	/* 0x13e3: movzx  eax,BYTE PTR [r13+0x25] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 37ULL);
x86_l_13e8:
	/* 0x13e8: and    al,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_13ea:
	/* 0x13ea: cmp    al,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_13ec:
	/* 0x13ec: mov    r14d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 3ULL);
x86_l_13f2:
	/* 0x13f2: sbb    r14d,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SBB, 0ULL);
x86_l_13f6:
	/* 0x13f6: jmp    18b0 <tail_handle_ipv6_from_host+0x18b0> */
	X86_SIM_X86_JMP(0x13f6, 0x18b0, x86_l_18b0);
x86_l_13fb:
	/* 0x13fb: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_13fe:
	/* 0x13fe: mov    DWORD PTR [rsp],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1402:
	/* 0x1402: mov    rdi,QWORD PTR [rip+0x1a3f6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv6_frag_datagrams)));
x86_l_1409:
	/* 0x1409: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_140e:
	/* 0x140e: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1413:
	/* 0x1413: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1415:
	/* 0x1415: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1418:
	/* 0x1418: je     14ad <tail_handle_ipv6_from_host+0x14ad> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1418, 0x14ad, x86_l_14ad);
x86_l_141e:
	/* 0x141e: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1420:
	/* 0x1420: mov    DWORD PTR [rbp+0x0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1423:
	/* 0x1423: jmp    14e4 <tail_handle_ipv6_from_host+0x14e4> */
	X86_SIM_X86_JMP(0x1423, 0x14e4, x86_l_14e4);
x86_l_1428:
	/* 0x1428: mov    rdi,QWORD PTR [rip+0x1a3f6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv6_frag_datagrams)));
x86_l_142f:
	/* 0x142f: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1434:
	/* 0x1434: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1439:
	/* 0x1439: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_143c:
	/* 0x143c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_143e:
	/* 0x143e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1440:
	/* 0x1440: movabs rdi,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_64, 1099511627776ULL);
x86_l_144a:
	/* 0x144a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_144c:
	/* 0x144c: je     eb7 <tail_handle_ipv6_from_host+0xeb7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x144c, 0xeb7, x86_l_eb7);
x86_l_1452:
	/* 0x1452: mov    r15d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1455:
	/* 0x1455: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_145e:
	/* 0x145e: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1467:
	/* 0x1467: movabs rax,0x7201a9020a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 489654125066ULL);
x86_l_1471:
	/* 0x1471: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1476:
	/* 0x1476: mov    rdi,QWORD PTR [rip+0x1a3f6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_147d:
	/* 0x147d: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1482:
	/* 0x1482: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1487:
	/* 0x1487: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1489:
	/* 0x1489: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_148c:
	/* 0x148c: je     14bc <tail_handle_ipv6_from_host+0x14bc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x148c, 0x14bc, x86_l_14bc);
x86_l_148e:
	/* 0x148e: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1491:
	/* 0x1491: add    QWORD PTR [rax+0x8],r15 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1495:
	/* 0x1495: jmp    14e4 <tail_handle_ipv6_from_host+0x14e4> */
	X86_SIM_X86_JMP(0x1495, 0x14e4, x86_l_14e4);
x86_l_1497:
	/* 0x1497: mov    r13d,0xffffff63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967139ULL);
x86_l_149d:
	/* 0x149d: jmp    e35 <tail_handle_ipv6_from_host+0xe35> */
	X86_SIM_X86_JMP(0x149d, 0xe35, x86_l_e35);
x86_l_14a2:
	/* 0x14a2: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_14a8:
	/* 0x14a8: jmp    1139 <tail_handle_ipv6_from_host+0x1139> */
	X86_SIM_X86_JMP(0x14a8, 0x1139, x86_l_1139);
x86_l_14ad:
	/* 0x14ad: mov    r13d,0xffffff51 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967121ULL);
x86_l_14b3:
	/* 0x14b3: mov    r15d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14b7:
	/* 0x14b7: jmp    f41 <tail_handle_ipv6_from_host+0xf41> */
	X86_SIM_X86_JMP(0x14b7, 0xf41, x86_l_f41);
x86_l_14bc:
	/* 0x14bc: mov    QWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_14c5:
	/* 0x14c5: mov    QWORD PTR [rsp+0x10],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14ca:
	/* 0x14ca: mov    rdi,QWORD PTR [rip+0x1a3f6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_14d1:
	/* 0x14d1: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_14d6:
	/* 0x14d6: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14db:
	/* 0x14db: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_14e0:
	/* 0x14e0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14e2:
	/* 0x14e2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14e4:
	/* 0x14e4: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_14e9:
	/* 0x14e9: movabs rdi,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_64, 1099511627776ULL);
x86_l_14f3:
	/* 0x14f3: jmp    eb7 <tail_handle_ipv6_from_host+0xeb7> */
	X86_SIM_X86_JMP(0x14f3, 0xeb7, x86_l_eb7);
x86_l_14f8:
	/* 0x14f8: mov    r13d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 60ULL);
x86_l_14fe:
	/* 0x14fe: cmp    BYTE PTR [rsp+0x28],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691846ULL);
x86_l_1503:
	/* 0x1503: jne    153c <tail_handle_ipv6_from_host+0x153c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1503, 0x153c, x86_l_153c);
x86_l_1505:
	/* 0x1505: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_1507:
	/* 0x1507: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1509:
	/* 0x1509: shr    ecx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_150c:
	/* 0x150c: and    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_150f:
	/* 0x150f: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1511:
	/* 0x1511: mov    WORD PTR [r15+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1516:
	/* 0x1516: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1518:
	/* 0x1518: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_151d:
	/* 0x151d: mov    r13d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 21600ULL);
x86_l_1523:
	/* 0x1523: cmove  r13d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_1527:
	/* 0x1527: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_152b:
	/* 0x152b: je     153c <tail_handle_ipv6_from_host+0x153c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x152b, 0x153c, x86_l_153c);
x86_l_152d:
	/* 0x152d: mov    rax,QWORD PTR [rip+0x1a3f6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1534:
	/* 0x1534: imul   r13d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_1538:
	/* 0x1538: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_153c:
	/* 0x153c: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_153f:
	/* 0x153f: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1543:
	/* 0x1543: je     1554 <tail_handle_ipv6_from_host+0x1554> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1543, 0x1554, x86_l_1554);
x86_l_1545:
	/* 0x1545: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_154a:
	/* 0x154a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_154c:
	/* 0x154c: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_154e:
	/* 0x154e: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_1552:
	/* 0x1552: jmp    1577 <tail_handle_ipv6_from_host+0x1577> */
	X86_SIM_X86_JMP(0x1552, 0x1577, x86_l_1577);
x86_l_1554:
	/* 0x1554: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1559:
	/* 0x1559: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_155b:
	/* 0x155b: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_155d:
	/* 0x155d: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1561:
	/* 0x1561: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_156b:
	/* 0x156b: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_156e:
	/* 0x156e: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1573:
	/* 0x1573: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_1577:
	/* 0x1577: add    r13d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_157a:
	/* 0x157a: mov    DWORD PTR [r15+0x20],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_157e:
	/* 0x157e: movzx  ecx,BYTE PTR [r15+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_1583:
	/* 0x1583: mov    edx,DWORD PTR [r15+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1587:
	/* 0x1587: and    bpl,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_158b:
	/* 0x158b: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_158f:
	/* 0x158f: je     15a2 <tail_handle_ipv6_from_host+0x15a2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x158f, 0x15a2, x86_l_15a2);
x86_l_1591:
	/* 0x1591: mov    rsi,QWORD PTR [rip+0x1a3f6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1598:
	/* 0x1598: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_159a:
	/* 0x159a: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_159d:
	/* 0x159d: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_15a0:
	/* 0x15a0: jmp    15a7 <tail_handle_ipv6_from_host+0x15a7> */
	X86_SIM_X86_JMP(0x15a0, 0x15a7, x86_l_15a7);
x86_l_15a2:
	/* 0x15a2: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_15a7:
	/* 0x15a7: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_15a9:
	/* 0x15a9: or     bpl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_15ac:
	/* 0x15ac: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_15ae:
	/* 0x15ae: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_15b3:
	/* 0x15b3: jb     15bc <tail_handle_ipv6_from_host+0x15bc> */
	X86_SIM_X86_JCC(X86_CC_B, 0x15b3, 0x15bc, x86_l_15bc);
x86_l_15b5:
	/* 0x15b5: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15b7:
	/* 0x15b7: cmp    cl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_8);
x86_l_15ba:
	/* 0x15ba: je     15cd <tail_handle_ipv6_from_host+0x15cd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x15ba, 0x15cd, x86_l_15cd);
x86_l_15bc:
	/* 0x15bc: mov    BYTE PTR [r15+0x2a],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_15c0:
	/* 0x15c0: mov    DWORD PTR [r15+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_15c4:
	/* 0x15c4: mov    rax,QWORD PTR [rip+0x1a3f6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_15cb:
	/* 0x15cb: mov    edx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15cd:
	/* 0x15cd: mov    DWORD PTR [r13+0x48],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_15d1:
	/* 0x15d1: mov    rax,QWORD PTR [r13+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_15d5:
	/* 0x15d5: mov    rcx,QWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15d9:
	/* 0x15d9: mov    rdx,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15dd:
	/* 0x15dd: mov    rsi,QWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15e1:
	/* 0x15e1: mov    QWORD PTR [r13+0x18],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_15e5:
	/* 0x15e5: mov    QWORD PTR [r13+0x10],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15e9:
	/* 0x15e9: mov    QWORD PTR [r13+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15ed:
	/* 0x15ed: mov    QWORD PTR [r13+0x0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15f1:
	/* 0x15f1: rol    DWORD PTR [r13+0x20],0x10 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R13, X86_WIDTH_32, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_ROL)), 137438953488ULL);
x86_l_15f6:
	/* 0x15f6: xor    BYTE PTR [r13+0x25],0x1 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R13, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 158913789953ULL);
x86_l_15fb:
	/* 0x15fb: mov    eax,DWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_15ff:
	/* 0x15ff: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1603:
	/* 0x1603: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1608:
	/* 0x1608: mov    rdi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_160d:
	/* 0x160d: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_1610:
	/* 0x1610: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1612:
	/* 0x1612: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1615:
	/* 0x1615: je     1648 <tail_handle_ipv6_from_host+0x1648> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1615, 0x1648, x86_l_1648);
x86_l_1617:
	/* 0x1617: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_161a:
	/* 0x161a: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_161d:
	/* 0x161d: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_161f:
	/* 0x161f: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1621:
	/* 0x1621: test   cl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_1624:
	/* 0x1624: je     173b <tail_handle_ipv6_from_host+0x173b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1624, 0x173b, x86_l_173b);
x86_l_162a:
	/* 0x162a: mov    r14,QWORD PTR [rip+0x1a3f6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1631:
	/* 0x1631: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1635:
	/* 0x1635: je     165d <tail_handle_ipv6_from_host+0x165d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1635, 0x165d, x86_l_165d);
x86_l_1637:
	/* 0x1637: mov    rcx,QWORD PTR [rip+0x1a3f6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_163e:
	/* 0x163e: imul   r13d,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_1642:
	/* 0x1642: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1646:
	/* 0x1646: jmp    1663 <tail_handle_ipv6_from_host+0x1663> */
	X86_SIM_X86_JMP(0x1646, 0x1663, x86_l_1663);
x86_l_1648:
	/* 0x1648: mov    rax,QWORD PTR [rip+0x1a3f6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_164f:
	/* 0x164f: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1651:
	/* 0x1651: mov    DWORD PTR [r13+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1655:
	/* 0x1655: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1658:
	/* 0x1658: jmp    18b0 <tail_handle_ipv6_from_host+0x18b0> */
	X86_SIM_X86_JMP(0x1658, 0x18b0, x86_l_18b0);
x86_l_165d:
	/* 0x165d: mov    r13d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 60ULL);
x86_l_1663:
	/* 0x1663: cmp    BYTE PTR [rsp+0x28],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691846ULL);
x86_l_1668:
	/* 0x1668: jne    16a3 <tail_handle_ipv6_from_host+0x16a3> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1668, 0x16a3, x86_l_16a3);
x86_l_166a:
	/* 0x166a: mov    ecx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_166e:
	/* 0x166e: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1670:
	/* 0x1670: shr    ecx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_1673:
	/* 0x1673: and    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_1676:
	/* 0x1676: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1678:
	/* 0x1678: mov    WORD PTR [r15+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_167d:
	/* 0x167d: test   al,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 16ULL);
x86_l_167f:
	/* 0x167f: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_1684:
	/* 0x1684: mov    r13d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 21600ULL);
x86_l_168a:
	/* 0x168a: cmove  r13d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_168e:
	/* 0x168e: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1692:
	/* 0x1692: je     16a3 <tail_handle_ipv6_from_host+0x16a3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1692, 0x16a3, x86_l_16a3);
x86_l_1694:
	/* 0x1694: mov    rax,QWORD PTR [rip+0x1a3f6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_169b:
	/* 0x169b: imul   r13d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_169f:
	/* 0x169f: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_16a3:
	/* 0x16a3: mov    ebp,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_16a7:
	/* 0x16a7: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_16aa:
	/* 0x16aa: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16ae:
	/* 0x16ae: je     16bf <tail_handle_ipv6_from_host+0x16bf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x16ae, 0x16bf, x86_l_16bf);
x86_l_16b0:
	/* 0x16b0: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_16b5:
	/* 0x16b5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16b7:
	/* 0x16b7: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_16b9:
	/* 0x16b9: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_16bd:
	/* 0x16bd: jmp    16e2 <tail_handle_ipv6_from_host+0x16e2> */
	X86_SIM_X86_JMP(0x16bd, 0x16e2, x86_l_16e2);
x86_l_16bf:
	/* 0x16bf: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_16c4:
	/* 0x16c4: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16c6:
	/* 0x16c6: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_16c8:
	/* 0x16c8: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_16cc:
	/* 0x16cc: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_16d6:
	/* 0x16d6: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_16d9:
	/* 0x16d9: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_16de:
	/* 0x16de: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_16e2:
	/* 0x16e2: add    r13d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_16e5:
	/* 0x16e5: mov    DWORD PTR [r15+0x20],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_16e9:
	/* 0x16e9: movzx  ecx,BYTE PTR [r15+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_16ee:
	/* 0x16ee: mov    edx,DWORD PTR [r15+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_16f2:
	/* 0x16f2: and    bpl,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_16f6:
	/* 0x16f6: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16fa:
	/* 0x16fa: je     170d <tail_handle_ipv6_from_host+0x170d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x16fa, 0x170d, x86_l_170d);
x86_l_16fc:
	/* 0x16fc: mov    rsi,QWORD PTR [rip+0x1a3f6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1703:
	/* 0x1703: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1705:
	/* 0x1705: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_1708:
	/* 0x1708: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_170b:
	/* 0x170b: jmp    1712 <tail_handle_ipv6_from_host+0x1712> */
	X86_SIM_X86_JMP(0x170b, 0x1712, x86_l_1712);
x86_l_170d:
	/* 0x170d: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_1712:
	/* 0x1712: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1714:
	/* 0x1714: or     bpl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_1717:
	/* 0x1717: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_1719:
	/* 0x1719: jb     1722 <tail_handle_ipv6_from_host+0x1722> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1719, 0x1722, x86_l_1722);
x86_l_171b:
	/* 0x171b: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_171d:
	/* 0x171d: cmp    cl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_8);
x86_l_1720:
	/* 0x1720: je     1733 <tail_handle_ipv6_from_host+0x1733> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1720, 0x1733, x86_l_1733);
x86_l_1722:
	/* 0x1722: mov    BYTE PTR [r15+0x2a],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_1726:
	/* 0x1726: mov    DWORD PTR [r15+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_172a:
	/* 0x172a: mov    rax,QWORD PTR [rip+0x1a3f6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_1731:
	/* 0x1731: mov    edx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1733:
	/* 0x1733: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1738:
	/* 0x1738: mov    DWORD PTR [rax+0x48],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_173b:
	/* 0x173b: mov    rax,QWORD PTR [rip+0x1a3f6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_1742:
	/* 0x1742: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1745:
	/* 0x1745: je     1753 <tail_handle_ipv6_from_host+0x1753> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1745, 0x1753, x86_l_1753);
x86_l_1747:
	/* 0x1747: inc QWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 16ULL);
x86_l_174c:
	/* 0x174c: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_174e:
	/* 0x174e: add QWORD PTR [r15+0x18],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R15, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_1753:
	/* 0x1753: mov    r14d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 1ULL);
x86_l_1759:
	/* 0x1759: cmp    r12d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 2ULL);
x86_l_175d:
	/* 0x175d: je     17af <tail_handle_ipv6_from_host+0x17af> */
	X86_SIM_X86_JCC(X86_CC_E, 0x175d, 0x17af, x86_l_17af);
x86_l_175f:
	/* 0x175f: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_1763:
	/* 0x1763: jne    18ab <tail_handle_ipv6_from_host+0x18ab> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1763, 0x18ab, x86_l_18ab);
x86_l_1769:
	/* 0x1769: movzx  eax,WORD PTR [r15+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_176e:
	/* 0x176e: test   al,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 3ULL);
x86_l_1770:
	/* 0x1770: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1775:
	/* 0x1775: je     18b0 <tail_handle_ipv6_from_host+0x18b0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1775, 0x18b0, x86_l_18b0);
x86_l_177b:
	/* 0x177b: mov    WORD PTR [r15+0x2a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 180388626432ULL);
x86_l_1782:
	/* 0x1782: and    eax,0xffec */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 65516ULL);
x86_l_1787:
	/* 0x1787: mov    WORD PTR [r15+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_178c:
	/* 0x178c: mov    r14,QWORD PTR [rip+0x1a3f6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1793:
	/* 0x1793: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1797:
	/* 0x1797: je     18ce <tail_handle_ipv6_from_host+0x18ce> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1797, 0x18ce, x86_l_18ce);
x86_l_179d:
	/* 0x179d: mov    rcx,QWORD PTR [rip+0x1a3f6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_17a4:
	/* 0x17a4: imul   ebp,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_17a7:
	/* 0x17a7: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_17aa:
	/* 0x17aa: jmp    18d3 <tail_handle_ipv6_from_host+0x18d3> */
	X86_SIM_X86_JMP(0x17aa, 0x18d3, x86_l_18d3);
x86_l_17af:
	/* 0x17af: mov    eax,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_17b3:
	/* 0x17b3: and    eax,0x400 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 1024ULL);
x86_l_17b8:
	/* 0x17b8: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_17bb:
	/* 0x17bb: mov    ax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 3ULL);
x86_l_17bf:
	/* 0x17bf: sbb    ax,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_16, X86_ALU_SBB, 0ULL);
x86_l_17c3:
	/* 0x17c3: or     WORD PTR [r15+0x24],ax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R15, X86_RAX, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 36ULL);
x86_l_17c8:
	/* 0x17c8: mov    r12,QWORD PTR [rip+0x1a3f6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_17cf:
	/* 0x17cf: mov    eax,DWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17d3:
	/* 0x17d3: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_17d8:
	/* 0x17d8: mov    DWORD PTR [rcx+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_17db:
	/* 0x17db: mov    eax,DWORD PTR [r15+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_17df:
	/* 0x17df: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_17e1:
	/* 0x17e1: test   al,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 3ULL);
x86_l_17e3:
	/* 0x17e3: jne    18ab <tail_handle_ipv6_from_host+0x18ab> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x17e3, 0x18ab, x86_l_18ab);
x86_l_17e9:
	/* 0x17e9: mov    r13,QWORD PTR [rip+0x1a3f6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_17f0:
	/* 0x17f0: cmp    BYTE PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17f5:
	/* 0x17f5: je     180a <tail_handle_ipv6_from_host+0x180a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x17f5, 0x180a, x86_l_180a);
x86_l_17f7:
	/* 0x17f7: mov    rax,QWORD PTR [rip+0x1a3f6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_17fe:
	/* 0x17fe: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1800:
	/* 0x1800: add    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1802:
	/* 0x1802: lea    ebp,[rax+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_1805:
	/* 0x1805: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1808:
	/* 0x1808: jmp    180f <tail_handle_ipv6_from_host+0x180f> */
	X86_SIM_X86_JMP(0x1808, 0x180f, x86_l_180f);
x86_l_180a:
	/* 0x180a: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_180f:
	/* 0x180f: shr    DWORD PTR [rsp+0x18],0x8 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_32, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_SHR)), 103079215112ULL);
x86_l_1814:
	/* 0x1814: cmp    BYTE PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1819:
	/* 0x1819: je     182a <tail_handle_ipv6_from_host+0x182a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1819, 0x182a, x86_l_182a);
x86_l_181b:
	/* 0x181b: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_1820:
	/* 0x1820: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1822:
	/* 0x1822: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1824:
	/* 0x1824: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_1828:
	/* 0x1828: jmp    184d <tail_handle_ipv6_from_host+0x184d> */
	X86_SIM_X86_JMP(0x1828, 0x184d, x86_l_184d);
x86_l_182a:
	/* 0x182a: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_182f:
	/* 0x182f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1831:
	/* 0x1831: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1833:
	/* 0x1833: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1837:
	/* 0x1837: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_1841:
	/* 0x1841: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1844:
	/* 0x1844: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1849:
	/* 0x1849: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_184d:
	/* 0x184d: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_184f:
	/* 0x184f: mov    DWORD PTR [r15+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1853:
	/* 0x1853: movzx  ecx,BYTE PTR [r15+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_1858:
	/* 0x1858: mov    edx,DWORD PTR [r15+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_185c:
	/* 0x185c: mov    esi,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1860:
	/* 0x1860: and    sil,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_1864:
	/* 0x1864: mov    DWORD PTR [rsp+0x18],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1868:
	/* 0x1868: cmp    BYTE PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_186d:
	/* 0x186d: je     1880 <tail_handle_ipv6_from_host+0x1880> */
	X86_SIM_X86_JCC(X86_CC_E, 0x186d, 0x1880, x86_l_1880);
x86_l_186f:
	/* 0x186f: mov    rsi,QWORD PTR [rip+0x1a3f6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1876:
	/* 0x1876: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1878:
	/* 0x1878: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_187b:
	/* 0x187b: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_187e:
	/* 0x187e: jmp    1885 <tail_handle_ipv6_from_host+0x1885> */
	X86_SIM_X86_JMP(0x187e, 0x1885, x86_l_1885);
x86_l_1880:
	/* 0x1880: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_1885:
	/* 0x1885: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1887:
	/* 0x1887: mov    edx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_188b:
	/* 0x188b: or     dl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_188d:
	/* 0x188d: mov    DWORD PTR [rsp+0x18],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1891:
	/* 0x1891: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_1893:
	/* 0x1893: jb     189b <tail_handle_ipv6_from_host+0x189b> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1893, 0x189b, x86_l_189b);
x86_l_1895:
	/* 0x1895: cmp    cl,BYTE PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 24ULL);
x86_l_1899:
	/* 0x1899: je     18ab <tail_handle_ipv6_from_host+0x18ab> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1899, 0x18ab, x86_l_18ab);
x86_l_189b:
	/* 0x189b: mov    ecx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_189f:
	/* 0x189f: mov    BYTE PTR [r15+0x2a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_18a3:
	/* 0x18a3: mov    DWORD PTR [r15+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_18a7:
	/* 0x18a7: mov    eax,DWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18ab:
	/* 0x18ab: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_18b0:
	/* 0x18b0: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18b2:
	/* 0x18b2: mov    r15d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18b6:
	/* 0x18b6: cmp    r15d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 1ULL);
x86_l_18ba:
	/* 0x18ba: sete   dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_E);
x86_l_18bd:
	/* 0x18bd: mov    DWORD PTR [r13+0x4c],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_18c1:
	/* 0x18c1: shl    edx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHL, 2ULL);
x86_l_18c4:
	/* 0x18c4: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_18c9:
	/* 0x18c9: jmp    66b <tail_handle_ipv6_from_host+0x66b> */
	X86_SIM_X86_JMP(0x18c9, 0x66b, x86_l_66b);
x86_l_18ce:
	/* 0x18ce: mov    ebp,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_18d3:
	/* 0x18d3: cmp    BYTE PTR [rsp+0x28],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691846ULL);
x86_l_18d8:
	/* 0x18d8: jne    190f <tail_handle_ipv6_from_host+0x190f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x18d8, 0x190f, x86_l_190f);
x86_l_18da:
	/* 0x18da: mov    ecx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_18de:
	/* 0x18de: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_18e0:
	/* 0x18e0: shr    ecx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_18e3:
	/* 0x18e3: and    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_18e6:
	/* 0x18e6: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_18e8:
	/* 0x18e8: mov    WORD PTR [r15+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_18ed:
	/* 0x18ed: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_18ef:
	/* 0x18ef: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_18f4:
	/* 0x18f4: mov    ebp,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 21600ULL);
x86_l_18f9:
	/* 0x18f9: cmove  ebp,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_18fc:
	/* 0x18fc: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1900:
	/* 0x1900: je     190f <tail_handle_ipv6_from_host+0x190f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1900, 0x190f, x86_l_190f);
x86_l_1902:
	/* 0x1902: mov    rax,QWORD PTR [rip+0x1a3f6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1909:
	/* 0x1909: imul   ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_190c:
	/* 0x190c: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_190f:
	/* 0x190f: shr    DWORD PTR [rsp+0x18],0x8 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_32, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_SHR)), 103079215112ULL);
x86_l_1914:
	/* 0x1914: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1918:
	/* 0x1918: je     1929 <tail_handle_ipv6_from_host+0x1929> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1918, 0x1929, x86_l_1929);
x86_l_191a:
	/* 0x191a: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_191f:
	/* 0x191f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1921:
	/* 0x1921: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1923:
	/* 0x1923: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_1927:
	/* 0x1927: jmp    194c <tail_handle_ipv6_from_host+0x194c> */
	X86_SIM_X86_JMP(0x1927, 0x194c, x86_l_194c);
x86_l_1929:
	/* 0x1929: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_192e:
	/* 0x192e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1930:
	/* 0x1930: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1932:
	/* 0x1932: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1936:
	/* 0x1936: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_1940:
	/* 0x1940: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1943:
	/* 0x1943: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1948:
	/* 0x1948: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_194c:
	/* 0x194c: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_194e:
	/* 0x194e: mov    DWORD PTR [r15+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1952:
	/* 0x1952: movzx  ecx,BYTE PTR [r15+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_1957:
	/* 0x1957: mov    edx,DWORD PTR [r15+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_195b:
	/* 0x195b: mov    esi,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_195f:
	/* 0x195f: and    sil,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_1963:
	/* 0x1963: mov    DWORD PTR [rsp+0x18],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1967:
	/* 0x1967: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_196b:
	/* 0x196b: je     197e <tail_handle_ipv6_from_host+0x197e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x196b, 0x197e, x86_l_197e);
x86_l_196d:
	/* 0x196d: mov    rsi,QWORD PTR [rip+0x1a3f6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1974:
	/* 0x1974: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1976:
	/* 0x1976: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_1979:
	/* 0x1979: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_197c:
	/* 0x197c: jmp    1983 <tail_handle_ipv6_from_host+0x1983> */
	X86_SIM_X86_JMP(0x197c, 0x1983, x86_l_1983);
x86_l_197e:
	/* 0x197e: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_1983:
	/* 0x1983: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1985:
	/* 0x1985: mov    edx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1989:
	/* 0x1989: or     dl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_198b:
	/* 0x198b: mov    DWORD PTR [rsp+0x18],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_198f:
	/* 0x198f: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_1991:
	/* 0x1991: jb     199b <tail_handle_ipv6_from_host+0x199b> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1991, 0x199b, x86_l_199b);
x86_l_1993:
	/* 0x1993: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1995:
	/* 0x1995: cmp    cl,BYTE PTR [rsp+0x18] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 24ULL);
x86_l_1999:
	/* 0x1999: je     19b0 <tail_handle_ipv6_from_host+0x19b0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1999, 0x19b0, x86_l_19b0);
x86_l_199b:
	/* 0x199b: mov    ecx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_199f:
	/* 0x199f: mov    BYTE PTR [r15+0x2a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_19a3:
	/* 0x19a3: mov    DWORD PTR [r15+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_19a7:
	/* 0x19a7: mov    rax,QWORD PTR [rip+0x1a3f6] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_19ae:
	/* 0x19ae: mov    edx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19b0:
	/* 0x19b0: mov    r13,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_19b5:
	/* 0x19b5: mov    DWORD PTR [r13+0x48],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_19b9:
	/* 0x19b9: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19bc:
	/* 0x19bc: jmp    18b0 <tail_handle_ipv6_from_host+0x18b0> */
	X86_SIM_X86_JMP(0x19bc, 0x18b0, x86_l_18b0);
x86_l_19c1:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
