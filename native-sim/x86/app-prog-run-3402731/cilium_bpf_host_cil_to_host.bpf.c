extern char __config_cilium_host_ifindex;
extern char __config_cluster_id_bits;
extern char __config_enable_identity_mark;
extern char __config_enable_ipv4_fragments;
extern char __config_enable_tproxy;
extern char __config_eth_header_length;
extern char __config_tracing_ip_option_type;
extern char cilium_calls;
extern char cilium_ipv4_frag_datagrams;
extern char cilium_metrics;
extern char cilium_percpu_trace_id;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int cilium_bpf_host_cil_to_host_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0xa: sub    rsp,0x48 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 72ULL);
x86_l_e:
	/* 0xe: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_11:
	/* 0x11: mov    r15d,DWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_15:
	/* 0x15: mov    r13,QWORD PTR [rip+0x2dd0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&__config_tracing_ip_option_type)));
x86_l_1c:
	/* 0x1c: cmp    BYTE PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21:
	/* 0x21: je     a9 <cil_to_host+0xa9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x21, 0xa9, x86_l_a9);
x86_l_27:
	/* 0x27: movzx  ebp,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2c:
	/* 0x2c: mov    rcx,QWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_33:
	/* 0x33: mov    edx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_36:
	/* 0x36: mov    rax,QWORD PTR [rip+0x2dd0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_3d:
	/* 0x3d: sub    edx,DWORD PTR [rbx+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_40:
	/* 0x40: movzx  esi,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_43:
	/* 0x43: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_46:
	/* 0x46: je     5e <cil_to_host+0x5e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x46, 0x5e, x86_l_5e);
x86_l_48:
	/* 0x48: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_4a:
	/* 0x4a: jb     82 <cil_to_host+0x82> */
	X86_SIM_X86_JCC(X86_CC_B, 0x4a, 0x82, x86_l_82);
x86_l_4c:
	/* 0x4c: movzx  esi,WORD PTR [rcx+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_50:
	/* 0x50: cmp    si,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_16, 6ULL);
x86_l_54:
	/* 0x54: jb     82 <cil_to_host+0x82> */
	X86_SIM_X86_JCC(X86_CC_B, 0x54, 0x82, x86_l_82);
x86_l_56:
	/* 0x56: cmp    si,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_16, 8ULL);
x86_l_5a:
	/* 0x5a: je     6b <cil_to_host+0x6b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5a, 0x6b, x86_l_6b);
x86_l_5c:
	/* 0x5c: jmp    82 <cil_to_host+0x82> */
	X86_SIM_X86_JMP(0x5c, 0x82, x86_l_82);
x86_l_5e:
	/* 0x5e: movzx  esi,WORD PTR [rbx+0xb4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 180ULL);
x86_l_65:
	/* 0x65: cmp    si,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_16, 8ULL);
x86_l_69:
	/* 0x69: jne    82 <cil_to_host+0x82> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x69, 0x82, x86_l_82);
x86_l_6b:
	/* 0x6b: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_6e:
	/* 0x6e: movzx  esi,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_71:
	/* 0x71: lea    rdi,[rcx+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_75:
	/* 0x75: add    rdi,0x14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 20ULL);
x86_l_79:
	/* 0x79: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_7c:
	/* 0x7c: jbe    3d9 <cil_to_host+0x3d9> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x7c, 0x3d9, x86_l_3d9);
x86_l_82:
	/* 0x82: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_8a:
	/* 0x8a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_8f:
	/* 0x8f: mov    rdi,QWORD PTR [rip+0x2dd0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_percpu_trace_id)));
x86_l_96:
	/* 0x96: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9b:
	/* 0x9b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9d:
	/* 0x9d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a0:
	/* 0xa0: je     a9 <cil_to_host+0xa9> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa0, 0xa9, x86_l_a9);
x86_l_a2:
	/* 0xa2: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a9:
	/* 0xa9: mov    rax,QWORD PTR [rip+0x2dd0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_identity_mark)));
x86_l_b0:
	/* 0xb0: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_b3:
	/* 0xb3: mov    eax,DWORD PTR [rbx+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_b9:
	/* 0xb9: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_bb:
	/* 0xbb: and    ecx,0xf00 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 3840ULL);
x86_l_c1:
	/* 0xc1: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_c3:
	/* 0xc3: je     19d <cil_to_host+0x19d> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc3, 0x19d, x86_l_19d);
x86_l_c9:
	/* 0xc9: cmp    ecx,0xf00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3840ULL);
x86_l_cf:
	/* 0xcf: jne    19d <cil_to_host+0x19d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xcf, 0x19d, x86_l_19d);
x86_l_d5:
	/* 0xd5: movzx  edx,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_d8:
	/* 0xd8: mov    rcx,QWORD PTR [rip+0x2dd0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_cluster_id_bits)));
x86_l_df:
	/* 0xdf: mov    esi,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e1:
	/* 0xe1: mov    edi,0x7fffff00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 2147483392ULL);
x86_l_e6:
	/* 0xe6: bzhi   esi,edi,esi */
	X86_SIM_RUN_OP(X86_OP_BZHI, X86_RSI, X86_RDI, X86_WIDTH_32, X86_RSI, 0);
x86_l_eb:
	/* 0xeb: mov    edi,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ed:
	/* 0xed: neg    dil */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_8, X86_ALU_NEG, 0);
x86_l_f0:
	/* 0xf0: shlx   esi,esi,edi */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RSI, X86_RSI, X86_WIDTH_32, X86_RDI, X86_ALU_SHL);
x86_l_f5:
	/* 0xf5: and    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_AND);
x86_l_f7:
	/* 0xf7: mov    edi,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f9:
	/* 0xf9: neg    dil */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_8, X86_ALU_NEG, 0);
x86_l_fc:
	/* 0xfc: shrx   esi,esi,edi */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RSI, X86_RSI, X86_WIDTH_32, X86_RDI, X86_ALU_SHR);
x86_l_101:
	/* 0x101: or     esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_103:
	/* 0x103: shr    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_106:
	/* 0x106: mov    edx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_108:
	/* 0x108: mov    dil,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_8, 24ULL);
x86_l_10b:
	/* 0x10b: mov    r8b,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_8, 24ULL);
x86_l_10e:
	/* 0x10e: sub    r8b,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_111:
	/* 0x111: bzhi   eax,eax,r8d */
	X86_SIM_RUN_OP(X86_OP_BZHI, X86_RAX, X86_RAX, X86_WIDTH_32, X86_R8, 0);
x86_l_116:
	/* 0x116: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_118:
	/* 0x118: sub    dil,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_11b:
	/* 0x11b: shlx   r12d,esi,edi */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_R12, X86_RSI, X86_WIDTH_32, X86_RDI, X86_ALU_SHL);
x86_l_120:
	/* 0x120: or     r12d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_32, X86_ALU_OR);
x86_l_123:
	/* 0x123: movzx  eax,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_127:
	/* 0x127: cmp    eax,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 512ULL);
x86_l_12c:
	/* 0x12c: je     1b9 <cil_to_host+0x1b9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12c, 0x1b9, x86_l_1b9);
x86_l_132:
	/* 0x132: mov    rax,QWORD PTR [rip+0x2dd0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_cilium_host_ifindex)));
x86_l_139:
	/* 0x139: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13b:
	/* 0x13b: cmp    BYTE PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_140:
	/* 0x140: je     15d <cil_to_host+0x15d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x140, 0x15d, x86_l_15d);
x86_l_142:
	/* 0x142: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_14a:
	/* 0x14a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14f:
	/* 0x14f: mov    rdi,QWORD PTR [rip+0x2dd0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_percpu_trace_id)));
x86_l_156:
	/* 0x156: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15b:
	/* 0x15b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15d:
	/* 0x15d: mov    ebx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_160:
	/* 0x160: movabs rax,0x106f10100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 4411425024ULL);
x86_l_16a:
	/* 0x16a: add    rax,0x50100 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 327936ULL);
x86_l_170:
	/* 0x170: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_175:
	/* 0x175: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_17a:
	/* 0x17a: mov    rdi,QWORD PTR [rip+0x2dd0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_181:
	/* 0x181: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_186:
	/* 0x186: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_188:
	/* 0x188: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_18b:
	/* 0x18b: je     228 <cil_to_host+0x228> */
	X86_SIM_X86_JCC(X86_CC_E, 0x18b, 0x228, x86_l_228);
x86_l_191:
	/* 0x191: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_194:
	/* 0x194: add    QWORD PTR [rax+0x8],rbx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_198:
	/* 0x198: jmp    915 <cil_to_host+0x915> */
	X86_SIM_X86_JMP(0x198, 0x915, x86_l_915);
x86_l_19d:
	/* 0x19d: cmp    ecx,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 512ULL);
x86_l_1a3:
	/* 0x1a3: cmove  r15d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R15, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_1a7:
	/* 0x1a7: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1aa:
	/* 0x1aa: movzx  eax,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1ae:
	/* 0x1ae: cmp    eax,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 512ULL);
x86_l_1b3:
	/* 0x1b3: jne    132 <cil_to_host+0x132> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1b3, 0x132, x86_l_132);
x86_l_1b9:
	/* 0x1b9: mov    DWORD PTR [rbx+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1c0:
	/* 0x1c0: mov    rax,QWORD PTR [rip+0x2dd0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_tproxy)));
x86_l_1c7:
	/* 0x1c7: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ca:
	/* 0x1ca: je     902 <cil_to_host+0x902> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1ca, 0x902, x86_l_902);
x86_l_1d0:
	/* 0x1d0: mov    r13d,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R15, X86_WIDTH_32);
x86_l_1d3:
	/* 0x1d3: shr    r13d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1d7:
	/* 0x1d7: test   r13w,r13w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_16);
x86_l_1db:
	/* 0x1db: je     902 <cil_to_host+0x902> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1db, 0x902, x86_l_902);
x86_l_1e1:
	/* 0x1e1: mov    rax,QWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1e8:
	/* 0x1e8: mov    edx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1eb:
	/* 0x1eb: mov    rcx,QWORD PTR [rip+0x2dd0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_1f2:
	/* 0x1f2: sub    edx,DWORD PTR [rbx+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_1f5:
	/* 0x1f5: movzx  esi,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1f8:
	/* 0x1f8: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1fb:
	/* 0x1fb: je     255 <cil_to_host+0x255> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1fb, 0x255, x86_l_255);
x86_l_1fd:
	/* 0x1fd: mov    ebp,0xffffff5a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967130ULL);
x86_l_202:
	/* 0x202: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_204:
	/* 0x204: jb     859 <cil_to_host+0x859> */
	X86_SIM_X86_JCC(X86_CC_B, 0x204, 0x859, x86_l_859);
x86_l_20a:
	/* 0x20a: movzx  esi,WORD PTR [rax+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_20e:
	/* 0x20e: cmp    si,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_16, 6ULL);
x86_l_212:
	/* 0x212: jb     859 <cil_to_host+0x859> */
	X86_SIM_X86_JCC(X86_CC_B, 0x212, 0x859, x86_l_859);
x86_l_218:
	/* 0x218: mov    ebp,0xffffff75 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967157ULL);
x86_l_21d:
	/* 0x21d: cmp    si,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_16, 8ULL);
x86_l_221:
	/* 0x221: je     26b <cil_to_host+0x26b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x221, 0x26b, x86_l_26b);
x86_l_223:
	/* 0x223: jmp    859 <cil_to_host+0x859> */
	X86_SIM_X86_JMP(0x223, 0x859, x86_l_859);
x86_l_228:
	/* 0x228: mov    QWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_231:
	/* 0x231: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_236:
	/* 0x236: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_23b:
	/* 0x23b: mov    rdi,QWORD PTR [rip+0x2dd0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_242:
	/* 0x242: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_247:
	/* 0x247: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24c:
	/* 0x24c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_24e:
	/* 0x24e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_250:
	/* 0x250: jmp    915 <cil_to_host+0x915> */
	X86_SIM_X86_JMP(0x250, 0x915, x86_l_915);
x86_l_255:
	/* 0x255: movzx  esi,WORD PTR [rbx+0xb4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 180ULL);
x86_l_25c:
	/* 0x25c: mov    ebp,0xffffff75 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967157ULL);
x86_l_261:
	/* 0x261: cmp    si,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_16, 8ULL);
x86_l_265:
	/* 0x265: jne    859 <cil_to_host+0x859> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x265, 0x859, x86_l_859);
x86_l_26b:
	/* 0x26b: add    rdx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_26e:
	/* 0x26e: movzx  esi,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_271:
	/* 0x271: lea    rdi,[rax+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_275:
	/* 0x275: add    rdi,0x14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 20ULL);
x86_l_279:
	/* 0x279: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_27e:
	/* 0x27e: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_281:
	/* 0x281: ja     859 <cil_to_host+0x859> */
	X86_SIM_X86_JCC(X86_CC_A, 0x281, 0x859, x86_l_859);
x86_l_287:
	/* 0x287: add    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_28a:
	/* 0x28a: movabs rdx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 2199023255552ULL);
x86_l_294:
	/* 0x294: movabs r9,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_64, 1099511627776ULL);
x86_l_29e:
	/* 0x29e: movzx  edi,WORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_2a2:
	/* 0x2a2: movzx  esi,BYTE PTR [rax+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_2a6:
	/* 0x2a6: mov    r8,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RSI, X86_WIDTH_64);
x86_l_2a9:
	/* 0x2a9: shl    r8,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_2ad:
	/* 0x2ad: or     r8,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDI, X86_WIDTH_64, X86_ALU_OR);
x86_l_2b0:
	/* 0x2b0: movzx  edi,WORD PTR [rax+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_2b4:
	/* 0x2b4: add    r9,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2b7:
	/* 0x2b7: test   edi,0xff3f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDI, X86_WIDTH_32, 65343ULL);
x86_l_2bd:
	/* 0x2bd: cmove  r9,r8 */
	X86_SIM_L_EXEC_CMOV(X86_R9, X86_R8, X86_WIDTH_64, X86_CC_E);
x86_l_2c1:
	/* 0x2c1: lea    r14,[r9+rdx*1] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_2c5:
	/* 0x2c5: test   edi,0xff1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDI, X86_WIDTH_32, 65311ULL);
x86_l_2cb:
	/* 0x2cb: cmove  r14,r9 */
	X86_SIM_L_EXEC_CMOV(X86_R14, X86_R9, X86_WIDTH_64, X86_CC_E);
x86_l_2cf:
	/* 0x2cf: mov    BYTE PTR [rsp+0x24],sil */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2d4:
	/* 0x2d4: cmp    esi,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_2d7:
	/* 0x2d7: je     2e7 <cil_to_host+0x2e7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2d7, 0x2e7, x86_l_2e7);
x86_l_2d9:
	/* 0x2d9: mov    ebp,0xffffff77 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967159ULL);
x86_l_2de:
	/* 0x2de: cmp    esi,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 6ULL);
x86_l_2e1:
	/* 0x2e1: jne    859 <cil_to_host+0x859> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2e1, 0x859, x86_l_859);
x86_l_2e7:
	/* 0x2e7: mov    edi,DWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ea:
	/* 0x2ea: mov    DWORD PTR [rsp+0x18],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2ee:
	/* 0x2ee: mov    r8d,DWORD PTR [rax+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2f2:
	/* 0x2f2: mov    DWORD PTR [rsp+0x1c],r8d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2f7:
	/* 0x2f7: movzx  ecx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2fa:
	/* 0x2fa: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fc:
	/* 0x2fc: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_2ff:
	/* 0x2ff: lea    esi,[rcx+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_302:
	/* 0x302: lea    rbp,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_307:
	/* 0x307: mov    rax,QWORD PTR [rip+0x2dd0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_ipv4_fragments)));
x86_l_30e:
	/* 0x30e: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_311:
	/* 0x311: je     445 <cil_to_host+0x445> */
	X86_SIM_X86_JCC(X86_CC_E, 0x311, 0x445, x86_l_445);
x86_l_317:
	/* 0x317: mov    DWORD PTR [rsp+0x34],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_31b:
	/* 0x31b: mov    DWORD PTR [rsp+0x38],r8d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_320:
	/* 0x320: mov    WORD PTR [rsp+0x3c],r14w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_326:
	/* 0x326: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_329:
	/* 0x329: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_32d:
	/* 0x32d: mov    BYTE PTR [rsp+0x3e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 62ULL);
x86_l_331:
	/* 0x331: mov    BYTE PTR [rsp+0x3f],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 270582939648ULL);
x86_l_336:
	/* 0x336: test   r14,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_RDX, X86_WIDTH_64);
x86_l_339:
	/* 0x339: jne    990 <cil_to_host+0x990> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x339, 0x990, x86_l_990);
x86_l_33f:
	/* 0x33f: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_344:
	/* 0x344: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_347:
	/* 0x347: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_34a:
	/* 0x34a: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_34f:
	/* 0x34f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_351:
	/* 0x351: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_353:
	/* 0x353: js     4c2 <cil_to_host+0x4c2> */
	X86_SIM_X86_JCC(X86_CC_S, 0x353, 0x4c2, x86_l_4c2);
x86_l_359:
	/* 0x359: movabs rax,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 1099511627776ULL);
x86_l_363:
	/* 0x363: test   r14,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_366:
	/* 0x366: je     464 <cil_to_host+0x464> */
	X86_SIM_X86_JCC(X86_CC_E, 0x366, 0x464, x86_l_464);
x86_l_36c:
	/* 0x36c: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_371:
	/* 0x371: mov    rdi,QWORD PTR [rip+0x2dd0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv4_frag_datagrams)));
x86_l_378:
	/* 0x378: lea    rsi,[rsp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_37d:
	/* 0x37d: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_380:
	/* 0x380: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_382:
	/* 0x382: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_384:
	/* 0x384: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_386:
	/* 0x386: je     464 <cil_to_host+0x464> */
	X86_SIM_X86_JCC(X86_CC_E, 0x386, 0x464, x86_l_464);
x86_l_38c:
	/* 0x38c: mov    r14d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_390:
	/* 0x390: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_399:
	/* 0x399: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_3a2:
	/* 0x3a2: movabs rax,0x6b0085020a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 459570217482ULL);
x86_l_3ac:
	/* 0x3ac: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3b1:
	/* 0x3b1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3b6:
	/* 0x3b6: mov    rdi,QWORD PTR [rip+0x2dd0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_3bd:
	/* 0x3bd: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3c2:
	/* 0x3c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c4:
	/* 0x3c4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3c7:
	/* 0x3c7: je     9c7 <cil_to_host+0x9c7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3c7, 0x9c7, x86_l_9c7);
x86_l_3cd:
	/* 0x3cd: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_3d0:
	/* 0x3d0: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3d4:
	/* 0x3d4: jmp    464 <cil_to_host+0x464> */
	X86_SIM_X86_JMP(0x3d4, 0x464, x86_l_464);
x86_l_3d9:
	/* 0x3d9: add    rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3dc:
	/* 0x3dc: movzx  r12d,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_3e0:
	/* 0x3e0: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_3e3:
	/* 0x3e3: and    cl,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 14ULL);
x86_l_3e6:
	/* 0x3e6: cmp    cl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 6ULL);
x86_l_3e9:
	/* 0x3e9: jb     6b2 <cil_to_host+0x6b2> */
	X86_SIM_X86_JCC(X86_CC_B, 0x3e9, 0x6b2, x86_l_6b2);
x86_l_3ef:
	/* 0x3ef: movzx  r14d,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_3f3:
	/* 0x3f3: shl    r12d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHL, 2ULL);
x86_l_3f7:
	/* 0x3f7: and    r12d,0x3c */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 60ULL);
x86_l_3fb:
	/* 0x3fb: je     6b2 <cil_to_host+0x6b2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3fb, 0x6b2, x86_l_6b2);
x86_l_401:
	/* 0x401: lea    esi,[r14+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_405:
	/* 0x405: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_40a:
	/* 0x40a: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_40f:
	/* 0x40f: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_412:
	/* 0x412: mov    QWORD PTR [rsp+0x28],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_417:
	/* 0x417: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_41c:
	/* 0x41c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41e:
	/* 0x41e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_420:
	/* 0x420: js     82 <cil_to_host+0x82> */
	X86_SIM_X86_JCC(X86_CC_S, 0x420, 0x82, x86_l_82);
x86_l_426:
	/* 0x426: movzx  eax,BYTE PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 24ULL);
x86_l_42b:
	/* 0x42b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_42d:
	/* 0x42d: je     6b2 <cil_to_host+0x6b2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x42d, 0x6b2, x86_l_6b2);
x86_l_433:
	/* 0x433: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_436:
	/* 0x436: jne    548 <cil_to_host+0x548> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x436, 0x548, x86_l_548);
x86_l_43c:
	/* 0x43c: lea    eax,[r14+0x15] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 21ULL);
x86_l_440:
	/* 0x440: jmp    5ce <cil_to_host+0x5ce> */
	X86_SIM_X86_JMP(0x440, 0x5ce, x86_l_5ce);
x86_l_445:
	/* 0x445: test   r14,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_RDX, X86_WIDTH_64);
x86_l_448:
	/* 0x448: jne    9b3 <cil_to_host+0x9b3> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x448, 0x9b3, x86_l_9b3);
x86_l_44e:
	/* 0x44e: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_453:
	/* 0x453: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_456:
	/* 0x456: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_459:
	/* 0x459: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_45e:
	/* 0x45e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_460:
	/* 0x460: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_462:
	/* 0x462: js     4c2 <cil_to_host+0x4c2> */
	X86_SIM_X86_JCC(X86_CC_S, 0x462, 0x4c2, x86_l_4c2);
x86_l_464:
	/* 0x464: rol    QWORD PTR [rsp+0x18],0x20 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_64, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_ROL)), 103079215136ULL);
x86_l_46a:
	/* 0x46a: movzx  r14d,BYTE PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 36ULL);
x86_l_470:
	/* 0x470: cmp    r14d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 6ULL);
x86_l_474:
	/* 0x474: jne    4cc <cil_to_host+0x4cc> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x474, 0x4cc, x86_l_4cc);
x86_l_476:
	/* 0x476: mov    eax,0x63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 99ULL);
x86_l_47b:
	/* 0x47b: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_480:
	/* 0x480: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_483:
	/* 0x483: mov    edx,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_488:
	/* 0x488: mov    rcx,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_48f:
	/* 0x48f: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_492:
	/* 0x492: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_494:
	/* 0x494: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_499:
	/* 0x499: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_49c:
	/* 0x49c: je     70d <cil_to_host+0x70d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x49c, 0x70d, x86_l_70d);
x86_l_4a2:
	/* 0x4a2: mov    ecx,DWORD PTR [rax+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_4a5:
	/* 0x4a5: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_4a8:
	/* 0x4a8: je     4b3 <cil_to_host+0x4b3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4a8, 0x4b3, x86_l_4b3);
x86_l_4aa:
	/* 0x4aa: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_4ad:
	/* 0x4ad: jne    6e1 <cil_to_host+0x6e1> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4ad, 0x6e1, x86_l_6e1);
x86_l_4b3:
	/* 0x4b3: mov    ecx,0x56 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 86ULL);
x86_l_4b8:
	/* 0x4b8: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_4bb:
	/* 0x4bb: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_4bd:
	/* 0x4bd: jmp    70d <cil_to_host+0x70d> */
	X86_SIM_X86_JMP(0x4bd, 0x70d, x86_l_70d);
x86_l_4c2:
	/* 0x4c2: mov    ebp,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967161ULL);
x86_l_4c7:
	/* 0x4c7: jmp    859 <cil_to_host+0x859> */
	X86_SIM_X86_JMP(0x4c7, 0x859, x86_l_859);
x86_l_4cc:
	/* 0x4cc: mov    WORD PTR [rsp+0x22],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_4d2:
	/* 0x4d2: mov    WORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_4d9:
	/* 0x4d9: movabs rax,0x100007f00000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 72058139498774528ULL);
x86_l_4e3:
	/* 0x4e3: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4e8:
	/* 0x4e8: cmp    r14d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 17ULL);
x86_l_4ec:
	/* 0x4ec: jne    78c <cil_to_host+0x78c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4ec, 0x78c, x86_l_78c);
x86_l_4f2:
	/* 0x4f2: mov    eax,0x55 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 85ULL);
x86_l_4f7:
	/* 0x4f7: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4fc:
	/* 0x4fc: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_4ff:
	/* 0x4ff: mov    edx,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_504:
	/* 0x504: mov    rcx,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_50b:
	/* 0x50b: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_50e:
	/* 0x50e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_510:
	/* 0x510: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_515:
	/* 0x515: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_518:
	/* 0x518: je     77f <cil_to_host+0x77f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x518, 0x77f, x86_l_77f);
x86_l_51e:
	/* 0x51e: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_523:
	/* 0x523: mov    eax,0x7c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 124ULL);
x86_l_528:
	/* 0x528: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_52d:
	/* 0x52d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_530:
	/* 0x530: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_532:
	/* 0x532: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_534:
	/* 0x534: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_536:
	/* 0x536: mov    ebp,0xffffff4d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967117ULL);
x86_l_53b:
	/* 0x53b: cmove  ebp,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_53e:
	/* 0x53e: mov    eax,0x56 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 86ULL);
x86_l_543:
	/* 0x543: jmp    776 <cil_to_host+0x776> */
	X86_SIM_X86_JMP(0x543, 0x776, x86_l_776);
x86_l_548:
	/* 0x548: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_54d:
	/* 0x54d: lea    esi,[r14+0x15] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 21ULL);
x86_l_551:
	/* 0x551: lea    rdx,[rsp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_556:
	/* 0x556: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_559:
	/* 0x559: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_55e:
	/* 0x55e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_560:
	/* 0x560: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_562:
	/* 0x562: js     82 <cil_to_host+0x82> */
	X86_SIM_X86_JCC(X86_CC_S, 0x562, 0x82, x86_l_82);
x86_l_568:
	/* 0x568: cmp    BYTE PTR [rsp+0x18],bpl */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_56d:
	/* 0x56d: jne    5bf <cil_to_host+0x5bf> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x56d, 0x5bf, x86_l_5bf);
x86_l_56f:
	/* 0x56f: movzx  eax,BYTE PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 52ULL);
x86_l_574:
	/* 0x574: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_577:
	/* 0x577: je     957 <cil_to_host+0x957> */
	X86_SIM_X86_JCC(X86_CC_E, 0x577, 0x957, x86_l_957);
x86_l_57d:
	/* 0x57d: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_580:
	/* 0x580: je     92a <cil_to_host+0x92a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x580, 0x92a, x86_l_92a);
x86_l_586:
	/* 0x586: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_589:
	/* 0x589: jne    82 <cil_to_host+0x82> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x589, 0x82, x86_l_82);
x86_l_58f:
	/* 0x58f: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_594:
	/* 0x594: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_599:
	/* 0x599: add    esi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_59c:
	/* 0x59c: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5a1:
	/* 0x5a1: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_5a4:
	/* 0x5a4: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_5a9:
	/* 0x5a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5ab:
	/* 0x5ab: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5ae:
	/* 0x5ae: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5b0:
	/* 0x5b0: movbe  cx,WORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOVBE_LOAD, X86_RCX, X86_RSP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_5b7:
	/* 0x5b7: movzx  ecx,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_5ba:
	/* 0x5ba: jmp    97f <cil_to_host+0x97f> */
	X86_SIM_X86_JMP(0x5ba, 0x97f, x86_l_97f);
x86_l_5bf:
	/* 0x5bf: movzx  eax,BYTE PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 52ULL);
x86_l_5c4:
	/* 0x5c4: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5c9:
	/* 0x5c9: add    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_5cb:
	/* 0x5cb: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_5ce:
	/* 0x5ce: add    r14d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R12, X86_WIDTH_32, X86_ALU_ADD);
x86_l_5d1:
	/* 0x5d1: add    r14d,0x14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 20ULL);
x86_l_5d5:
	/* 0x5d5: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5da:
	/* 0x5da: cmp    eax,r14d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R14, X86_WIDTH_32);
x86_l_5dd:
	/* 0x5dd: jae    6b2 <cil_to_host+0x6b2> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x5dd, 0x6b2, x86_l_6b2);
x86_l_5e3:
	/* 0x5e3: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_5e8:
	/* 0x5e8: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5ed:
	/* 0x5ed: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_5f0:
	/* 0x5f0: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5f5:
	/* 0x5f5: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_5fa:
	/* 0x5fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5fc:
	/* 0x5fc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5fe:
	/* 0x5fe: js     82 <cil_to_host+0x82> */
	X86_SIM_X86_JCC(X86_CC_S, 0x5fe, 0x82, x86_l_82);
x86_l_604:
	/* 0x604: movzx  eax,BYTE PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 24ULL);
x86_l_609:
	/* 0x609: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_60b:
	/* 0x60b: je     6b2 <cil_to_host+0x6b2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x60b, 0x6b2, x86_l_6b2);
x86_l_611:
	/* 0x611: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_614:
	/* 0x614: je     64a <cil_to_host+0x64a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x614, 0x64a, x86_l_64a);
x86_l_616:
	/* 0x616: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_61b:
	/* 0x61b: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_620:
	/* 0x620: lea    esi,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_623:
	/* 0x623: lea    rdx,[rsp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_628:
	/* 0x628: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_62b:
	/* 0x62b: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_630:
	/* 0x630: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_632:
	/* 0x632: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_634:
	/* 0x634: js     82 <cil_to_host+0x82> */
	X86_SIM_X86_JCC(X86_CC_S, 0x634, 0x82, x86_l_82);
x86_l_63a:
	/* 0x63a: cmp    BYTE PTR [rsp+0x18],bpl */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_63f:
	/* 0x63f: je     56f <cil_to_host+0x56f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x63f, 0x56f, x86_l_56f);
x86_l_645:
	/* 0x645: movzx  eax,BYTE PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 52ULL);
x86_l_64a:
	/* 0x64a: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_64f:
	/* 0x64f: add    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_651:
	/* 0x651: mov    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_656:
	/* 0x656: cmp    ecx,r14d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R14, X86_WIDTH_32);
x86_l_659:
	/* 0x659: jae    6b2 <cil_to_host+0x6b2> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x659, 0x6b2, x86_l_6b2);
x86_l_65b:
	/* 0x65b: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_660:
	/* 0x660: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_665:
	/* 0x665: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_668:
	/* 0x668: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_66d:
	/* 0x66d: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_672:
	/* 0x672: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_674:
	/* 0x674: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_676:
	/* 0x676: js     82 <cil_to_host+0x82> */
	X86_SIM_X86_JCC(X86_CC_S, 0x676, 0x82, x86_l_82);
x86_l_67c:
	/* 0x67c: cmp    BYTE PTR [rsp+0x18],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 103079215106ULL);
x86_l_681:
	/* 0x681: jb     6b2 <cil_to_host+0x6b2> */
	X86_SIM_X86_JCC(X86_CC_B, 0x681, 0x6b2, x86_l_6b2);
x86_l_683:
	/* 0x683: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_688:
	/* 0x688: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_68d:
	/* 0x68d: lea    esi,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_690:
	/* 0x690: lea    rdx,[rsp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_695:
	/* 0x695: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_698:
	/* 0x698: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_69d:
	/* 0x69d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_69f:
	/* 0x69f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_6a1:
	/* 0x6a1: js     82 <cil_to_host+0x82> */
	X86_SIM_X86_JCC(X86_CC_S, 0x6a1, 0x82, x86_l_82);
x86_l_6a7:
	/* 0x6a7: cmp    BYTE PTR [rsp+0x18],bpl */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6ac:
	/* 0x6ac: je     56f <cil_to_host+0x56f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6ac, 0x56f, x86_l_56f);
x86_l_6b2:
	/* 0x6b2: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6b5:
	/* 0x6b5: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_6bd:
	/* 0x6bd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6c2:
	/* 0x6c2: mov    rdi,QWORD PTR [rip+0x2dd0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_percpu_trace_id)));
x86_l_6c9:
	/* 0x6c9: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6ce:
	/* 0x6ce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6d0:
	/* 0x6d0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6d3:
	/* 0x6d3: je     a9 <cil_to_host+0xa9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6d3, 0xa9, x86_l_a9);
x86_l_6d9:
	/* 0x6d9: mov    QWORD PTR [rax],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6dc:
	/* 0x6dc: jmp    a9 <cil_to_host+0xa9> */
	X86_SIM_X86_JMP(0x6dc, 0xa9, x86_l_a9);
x86_l_6e1:
	/* 0x6e1: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6e6:
	/* 0x6e6: mov    eax,0x7c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 124ULL);
x86_l_6eb:
	/* 0x6eb: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6f0:
	/* 0x6f0: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_6f3:
	/* 0x6f3: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6f5:
	/* 0x6f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6f7:
	/* 0x6f7: mov    ebp,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_6f9:
	/* 0x6f9: mov    eax,0x56 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 86ULL);
x86_l_6fe:
	/* 0x6fe: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_703:
	/* 0x703: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_705:
	/* 0x705: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_707:
	/* 0x707: je     902 <cil_to_host+0x902> */
	X86_SIM_X86_JCC(X86_CC_E, 0x707, 0x902, x86_l_902);
x86_l_70d:
	/* 0x70d: mov    WORD PTR [rsp+0x22],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_713:
	/* 0x713: mov    WORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_71a:
	/* 0x71a: movabs rax,0x100007f00000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 72058139498774528ULL);
x86_l_724:
	/* 0x724: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_729:
	/* 0x729: mov    eax,0x63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 99ULL);
x86_l_72e:
	/* 0x72e: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_733:
	/* 0x733: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_736:
	/* 0x736: mov    edx,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_73b:
	/* 0x73b: mov    rcx,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_742:
	/* 0x742: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_745:
	/* 0x745: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_747:
	/* 0x747: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_74c:
	/* 0x74c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_74f:
	/* 0x74f: je     77f <cil_to_host+0x77f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x74f, 0x77f, x86_l_77f);
x86_l_751:
	/* 0x751: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_756:
	/* 0x756: mov    eax,0x7c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 124ULL);
x86_l_75b:
	/* 0x75b: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_760:
	/* 0x760: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_763:
	/* 0x763: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_765:
	/* 0x765: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_767:
	/* 0x767: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_769:
	/* 0x769: mov    ebp,0xffffff4d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967117ULL);
x86_l_76e:
	/* 0x76e: cmove  ebp,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_771:
	/* 0x771: mov    eax,0x56 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 86ULL);
x86_l_776:
	/* 0x776: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_77b:
	/* 0x77b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_77d:
	/* 0x77d: jmp    784 <cil_to_host+0x784> */
	X86_SIM_X86_JMP(0x77d, 0x784, x86_l_784);
x86_l_77f:
	/* 0x77f: mov    ebp,0xffffff4e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967118ULL);
x86_l_784:
	/* 0x784: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_786:
	/* 0x786: je     902 <cil_to_host+0x902> */
	X86_SIM_X86_JCC(X86_CC_E, 0x786, 0x902, x86_l_902);
x86_l_78c:
	/* 0x78c: mov    DWORD PTR [rsp+0x1c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084288ULL);
x86_l_794:
	/* 0x794: cmp    r14d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 6ULL);
x86_l_798:
	/* 0x798: je     7f7 <cil_to_host+0x7f7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x798, 0x7f7, x86_l_7f7);
x86_l_79a:
	/* 0x79a: cmp    r14d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 17ULL);
x86_l_79e:
	/* 0x79e: jne    854 <cil_to_host+0x854> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x79e, 0x854, x86_l_854);
x86_l_7a4:
	/* 0x7a4: mov    eax,0x55 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 85ULL);
x86_l_7a9:
	/* 0x7a9: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_7ae:
	/* 0x7ae: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_7b1:
	/* 0x7b1: mov    edx,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_7b6:
	/* 0x7b6: mov    rcx,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_7bd:
	/* 0x7bd: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7c0:
	/* 0x7c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7c2:
	/* 0x7c2: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7c7:
	/* 0x7c7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7ca:
	/* 0x7ca: je     8f5 <cil_to_host+0x8f5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7ca, 0x8f5, x86_l_8f5);
x86_l_7d0:
	/* 0x7d0: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7d5:
	/* 0x7d5: mov    eax,0x7c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 124ULL);
x86_l_7da:
	/* 0x7da: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7df:
	/* 0x7df: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_7e2:
	/* 0x7e2: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7e4:
	/* 0x7e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7e6:
	/* 0x7e6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_7e8:
	/* 0x7e8: mov    ebp,0xffffff4d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967117ULL);
x86_l_7ed:
	/* 0x7ed: cmove  ebp,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_7f0:
	/* 0x7f0: mov    eax,0x56 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 86ULL);
x86_l_7f5:
	/* 0x7f5: jmp    848 <cil_to_host+0x848> */
	X86_SIM_X86_JMP(0x7f5, 0x848, x86_l_848);
x86_l_7f7:
	/* 0x7f7: mov    eax,0x63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 99ULL);
x86_l_7fc:
	/* 0x7fc: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_801:
	/* 0x801: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_804:
	/* 0x804: mov    edx,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_809:
	/* 0x809: mov    rcx,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_810:
	/* 0x810: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_813:
	/* 0x813: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_815:
	/* 0x815: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_81a:
	/* 0x81a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_81d:
	/* 0x81d: je     8f5 <cil_to_host+0x8f5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x81d, 0x8f5, x86_l_8f5);
x86_l_823:
	/* 0x823: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_828:
	/* 0x828: mov    eax,0x7c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 124ULL);
x86_l_82d:
	/* 0x82d: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_832:
	/* 0x832: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_835:
	/* 0x835: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_837:
	/* 0x837: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_839:
	/* 0x839: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_83b:
	/* 0x83b: mov    ebp,0xffffff4d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967117ULL);
x86_l_840:
	/* 0x840: cmove  ebp,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_843:
	/* 0x843: mov    eax,0x56 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 86ULL);
x86_l_848:
	/* 0x848: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_84d:
	/* 0x84d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_84f:
	/* 0x84f: jmp    8fa <cil_to_host+0x8fa> */
	X86_SIM_X86_JMP(0x84f, 0x8fa, x86_l_8fa);
x86_l_854:
	/* 0x854: mov    ebp,0xffffff4c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967116ULL);
x86_l_859:
	/* 0x859: neg    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_85b:
	/* 0x85b: mov    DWORD PTR [rbx+0x28],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_85f:
	/* 0x85f: mov    DWORD PTR [rbx+0x2c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561024ULL);
x86_l_866:
	/* 0x866: mov    DWORD PTR [rbx+0x30],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_869:
	/* 0x869: movabs rax,0x6f1010200000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 500182141716398080ULL);
x86_l_873:
	/* 0x873: mov    QWORD PTR [rbx+0x34],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_877:
	/* 0x877: mov    r14d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_87b:
	/* 0x87b: movabs rax,0x106f10100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 4411425024ULL);
x86_l_885:
	/* 0x885: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_88a:
	/* 0x88a: mov    BYTE PTR [rsp+0x18],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_88f:
	/* 0x88f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_894:
	/* 0x894: mov    rdi,QWORD PTR [rip+0x2dd0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_89b:
	/* 0x89b: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_8a0:
	/* 0x8a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8a2:
	/* 0x8a2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8a5:
	/* 0x8a5: je     8b0 <cil_to_host+0x8b0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8a5, 0x8b0, x86_l_8b0);
x86_l_8a7:
	/* 0x8a7: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_8aa:
	/* 0x8aa: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_8ae:
	/* 0x8ae: jmp    8d8 <cil_to_host+0x8d8> */
	X86_SIM_X86_JMP(0x8ae, 0x8d8, x86_l_8d8);
x86_l_8b0:
	/* 0x8b0: mov    QWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_8b9:
	/* 0x8b9: mov    QWORD PTR [rsp+0x10],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8be:
	/* 0x8be: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_8c3:
	/* 0x8c3: mov    rdi,QWORD PTR [rip+0x2dd0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_8ca:
	/* 0x8ca: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_8cf:
	/* 0x8cf: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8d4:
	/* 0x8d4: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8d6:
	/* 0x8d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8d8:
	/* 0x8d8: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_8dd:
	/* 0x8dd: mov    rsi,QWORD PTR [rip+0x2dd0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_8e4:
	/* 0x8e4: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_8e7:
	/* 0x8e7: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_8ec:
	/* 0x8ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8ee:
	/* 0x8ee: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_8f3:
	/* 0x8f3: jmp    917 <cil_to_host+0x917> */
	X86_SIM_X86_JMP(0x8f3, 0x917, x86_l_917);
x86_l_8f5:
	/* 0x8f5: mov    ebp,0xffffff4e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967118ULL);
x86_l_8fa:
	/* 0x8fa: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_8fc:
	/* 0x8fc: js     859 <cil_to_host+0x859> */
	X86_SIM_X86_JCC(X86_CC_S, 0x8fc, 0x859, x86_l_859);
x86_l_902:
	/* 0x902: mov    DWORD PTR [rbx+0xa8],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_909:
	/* 0x909: mov    eax,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_90e:
	/* 0x90e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_911:
	/* 0x911: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_913:
	/* 0x913: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_915:
	/* 0x915: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_917:
	/* 0x917: add    rsp,0x48 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 72ULL);
x86_l_91b:
	/* 0x91b: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_91c:
	/* 0x91c: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_91e:
	/* 0x91e: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_920:
	/* 0x920: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_922:
	/* 0x922: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_924:
	/* 0x924: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_925:
	/* 0x925: jmp    9f4 <cil_to_host+0x9f4> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_92a:
	/* 0x92a: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_92f:
	/* 0x92f: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_934:
	/* 0x934: add    esi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_937:
	/* 0x937: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_93c:
	/* 0x93c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_93f:
	/* 0x93f: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_944:
	/* 0x944: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_946:
	/* 0x946: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_948:
	/* 0x948: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_94a:
	/* 0x94a: movbe  r14d,DWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOVBE_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_951:
	/* 0x951: cmovs  r14d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R14, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_955:
	/* 0x955: jmp    983 <cil_to_host+0x983> */
	X86_SIM_X86_JMP(0x955, 0x983, x86_l_983);
x86_l_957:
	/* 0x957: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_95c:
	/* 0x95c: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_961:
	/* 0x961: add    esi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_964:
	/* 0x964: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_969:
	/* 0x969: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_96c:
	/* 0x96c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_971:
	/* 0x971: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_973:
	/* 0x973: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_976:
	/* 0x976: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_978:
	/* 0x978: movbe  rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOVBE_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_97f:
	/* 0x97f: cmovns r14,rcx */
	X86_SIM_L_EXEC_CMOV(X86_R14, X86_RCX, X86_WIDTH_64, X86_CC_NS);
x86_l_983:
	/* 0x983: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_985:
	/* 0x985: jns    6b5 <cil_to_host+0x6b5> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x985, 0x6b5, x86_l_6b5);
x86_l_98b:
	/* 0x98b: jmp    82 <cil_to_host+0x82> */
	X86_SIM_X86_JMP(0x98b, 0x82, x86_l_82);
x86_l_990:
	/* 0x990: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_995:
	/* 0x995: mov    rdi,QWORD PTR [rip+0x2dcc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv4_frag_datagrams)));
x86_l_99c:
	/* 0x99c: lea    rsi,[rsp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_9a1:
	/* 0x9a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9a3:
	/* 0x9a3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9a6:
	/* 0x9a6: je     9bd <cil_to_host+0x9bd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9a6, 0x9bd, x86_l_9bd);
x86_l_9a8:
	/* 0x9a8: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9aa:
	/* 0x9aa: mov    DWORD PTR [rsp+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9ae:
	/* 0x9ae: jmp    464 <cil_to_host+0x464> */
	X86_SIM_X86_JMP(0x9ae, 0x464, x86_l_464);
x86_l_9b3:
	/* 0x9b3: mov    ebp,0xffffff63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967139ULL);
x86_l_9b8:
	/* 0x9b8: jmp    859 <cil_to_host+0x859> */
	X86_SIM_X86_JMP(0x9b8, 0x859, x86_l_859);
x86_l_9bd:
	/* 0x9bd: mov    ebp,0xffffff51 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967121ULL);
x86_l_9c2:
	/* 0x9c2: jmp    859 <cil_to_host+0x859> */
	X86_SIM_X86_JMP(0x9c2, 0x859, x86_l_859);
x86_l_9c7:
	/* 0x9c7: mov    QWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_9d0:
	/* 0x9d0: mov    QWORD PTR [rsp+0x10],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9d5:
	/* 0x9d5: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_9da:
	/* 0x9da: mov    rdi,QWORD PTR [rip+0x2dcc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_9e1:
	/* 0x9e1: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_9e6:
	/* 0x9e6: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9eb:
	/* 0x9eb: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9ed:
	/* 0x9ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9ef:
	/* 0x9ef: jmp    464 <cil_to_host+0x464> */
	X86_SIM_X86_JMP(0x9ef, 0x464, x86_l_464);
x86_l_9f4:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
