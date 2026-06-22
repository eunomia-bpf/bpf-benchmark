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
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0x48 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 72ULL);
x86_l_7:
	/* 0x7: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_a:
	/* 0xa: mov    r15d,DWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_e:
	/* 0xe: mov    r13,QWORD PTR [rip+0x2dd7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&__config_tracing_ip_option_type)));
x86_l_15:
	/* 0x15: cmp    BYTE PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a:
	/* 0x1a: je     a2 <cil_to_host+0xa2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a, 0xa2, x86_l_a2);
x86_l_20:
	/* 0x20: movzx  ebp,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_25:
	/* 0x25: mov    rcx,QWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_2c:
	/* 0x2c: mov    edx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2f:
	/* 0x2f: mov    rax,QWORD PTR [rip+0x2dd7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_36:
	/* 0x36: sub    edx,DWORD PTR [rbx+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_39:
	/* 0x39: movzx  esi,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_3c:
	/* 0x3c: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f:
	/* 0x3f: je     57 <cil_to_host+0x57> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3f, 0x57, x86_l_57);
x86_l_41:
	/* 0x41: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_43:
	/* 0x43: jb     7b <cil_to_host+0x7b> */
	X86_SIM_X86_JCC(X86_CC_B, 0x43, 0x7b, x86_l_7b);
x86_l_45:
	/* 0x45: movzx  esi,WORD PTR [rcx+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_49:
	/* 0x49: cmp    si,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_16, 6ULL);
x86_l_4d:
	/* 0x4d: jb     7b <cil_to_host+0x7b> */
	X86_SIM_X86_JCC(X86_CC_B, 0x4d, 0x7b, x86_l_7b);
x86_l_4f:
	/* 0x4f: cmp    si,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_16, 8ULL);
x86_l_53:
	/* 0x53: je     64 <cil_to_host+0x64> */
	X86_SIM_X86_JCC(X86_CC_E, 0x53, 0x64, x86_l_64);
x86_l_55:
	/* 0x55: jmp    7b <cil_to_host+0x7b> */
	X86_SIM_X86_JMP(0x55, 0x7b, x86_l_7b);
x86_l_57:
	/* 0x57: movzx  esi,WORD PTR [rbx+0xb4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 180ULL);
x86_l_5e:
	/* 0x5e: cmp    si,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_16, 8ULL);
x86_l_62:
	/* 0x62: jne    7b <cil_to_host+0x7b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x62, 0x7b, x86_l_7b);
x86_l_64:
	/* 0x64: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_67:
	/* 0x67: movzx  esi,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_6a:
	/* 0x6a: lea    rdi,[rcx+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_6e:
	/* 0x6e: add    rdi,0x14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 20ULL);
x86_l_72:
	/* 0x72: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_75:
	/* 0x75: jbe    3d2 <cil_to_host+0x3d2> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x75, 0x3d2, x86_l_3d2);
x86_l_7b:
	/* 0x7b: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_83:
	/* 0x83: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_88:
	/* 0x88: mov    rdi,QWORD PTR [rip+0x2dd7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_percpu_trace_id)));
x86_l_8f:
	/* 0x8f: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_94:
	/* 0x94: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_96:
	/* 0x96: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_99:
	/* 0x99: je     a2 <cil_to_host+0xa2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x99, 0xa2, x86_l_a2);
x86_l_9b:
	/* 0x9b: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a2:
	/* 0xa2: mov    rax,QWORD PTR [rip+0x2dd7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_identity_mark)));
x86_l_a9:
	/* 0xa9: movzx  edx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_ac:
	/* 0xac: mov    eax,DWORD PTR [rbx+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_b2:
	/* 0xb2: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_b4:
	/* 0xb4: and    ecx,0xf00 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 3840ULL);
x86_l_ba:
	/* 0xba: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_bc:
	/* 0xbc: je     196 <cil_to_host+0x196> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbc, 0x196, x86_l_196);
x86_l_c2:
	/* 0xc2: cmp    ecx,0xf00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3840ULL);
x86_l_c8:
	/* 0xc8: jne    196 <cil_to_host+0x196> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xc8, 0x196, x86_l_196);
x86_l_ce:
	/* 0xce: movzx  edx,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_d1:
	/* 0xd1: mov    rcx,QWORD PTR [rip+0x2dd7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_cluster_id_bits)));
x86_l_d8:
	/* 0xd8: mov    esi,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_da:
	/* 0xda: mov    edi,0x7fffff00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 2147483392ULL);
x86_l_df:
	/* 0xdf: bzhi   esi,edi,esi */
	X86_SIM_RUN_OP(X86_OP_BZHI, X86_RSI, X86_RDI, X86_WIDTH_32, X86_RSI, 0);
x86_l_e4:
	/* 0xe4: mov    edi,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e6:
	/* 0xe6: neg    dil */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_8, X86_ALU_NEG, 0);
x86_l_e9:
	/* 0xe9: shlx   esi,esi,edi */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RSI, X86_RSI, X86_WIDTH_32, X86_RDI, X86_ALU_SHL);
x86_l_ee:
	/* 0xee: and    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_AND);
x86_l_f0:
	/* 0xf0: mov    edi,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f2:
	/* 0xf2: neg    dil */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_8, X86_ALU_NEG, 0);
x86_l_f5:
	/* 0xf5: shrx   esi,esi,edi */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RSI, X86_RSI, X86_WIDTH_32, X86_RDI, X86_ALU_SHR);
x86_l_fa:
	/* 0xfa: or     esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_fc:
	/* 0xfc: shr    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_ff:
	/* 0xff: mov    edx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_101:
	/* 0x101: mov    dil,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_8, 24ULL);
x86_l_104:
	/* 0x104: mov    r8b,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_8, 24ULL);
x86_l_107:
	/* 0x107: sub    r8b,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_10a:
	/* 0x10a: bzhi   eax,eax,r8d */
	X86_SIM_RUN_OP(X86_OP_BZHI, X86_RAX, X86_RAX, X86_WIDTH_32, X86_R8, 0);
x86_l_10f:
	/* 0x10f: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_111:
	/* 0x111: sub    dil,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_114:
	/* 0x114: shlx   r12d,esi,edi */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_R12, X86_RSI, X86_WIDTH_32, X86_RDI, X86_ALU_SHL);
x86_l_119:
	/* 0x119: or     r12d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_32, X86_ALU_OR);
x86_l_11c:
	/* 0x11c: movzx  eax,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_120:
	/* 0x120: cmp    eax,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 512ULL);
x86_l_125:
	/* 0x125: je     1b2 <cil_to_host+0x1b2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x125, 0x1b2, x86_l_1b2);
x86_l_12b:
	/* 0x12b: mov    rax,QWORD PTR [rip+0x2dd7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_cilium_host_ifindex)));
x86_l_132:
	/* 0x132: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_134:
	/* 0x134: cmp    BYTE PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_139:
	/* 0x139: je     156 <cil_to_host+0x156> */
	X86_SIM_X86_JCC(X86_CC_E, 0x139, 0x156, x86_l_156);
x86_l_13b:
	/* 0x13b: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_143:
	/* 0x143: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_148:
	/* 0x148: mov    rdi,QWORD PTR [rip+0x2dd7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_percpu_trace_id)));
x86_l_14f:
	/* 0x14f: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_154:
	/* 0x154: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_156:
	/* 0x156: mov    ebx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_159:
	/* 0x159: movabs rax,0x106f10100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 4411425024ULL);
x86_l_163:
	/* 0x163: add    rax,0x50100 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 327936ULL);
x86_l_169:
	/* 0x169: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_16e:
	/* 0x16e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_173:
	/* 0x173: mov    rdi,QWORD PTR [rip+0x2dd7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_17a:
	/* 0x17a: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_17f:
	/* 0x17f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_181:
	/* 0x181: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_184:
	/* 0x184: je     221 <cil_to_host+0x221> */
	X86_SIM_X86_JCC(X86_CC_E, 0x184, 0x221, x86_l_221);
x86_l_18a:
	/* 0x18a: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_18d:
	/* 0x18d: add    QWORD PTR [rax+0x8],rbx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_191:
	/* 0x191: jmp    90e <cil_to_host+0x90e> */
	X86_SIM_X86_JMP(0x191, 0x90e, x86_l_90e);
x86_l_196:
	/* 0x196: cmp    ecx,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 512ULL);
x86_l_19c:
	/* 0x19c: cmove  r15d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R15, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_1a0:
	/* 0x1a0: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a3:
	/* 0x1a3: movzx  eax,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1a7:
	/* 0x1a7: cmp    eax,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 512ULL);
x86_l_1ac:
	/* 0x1ac: jne    12b <cil_to_host+0x12b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1ac, 0x12b, x86_l_12b);
x86_l_1b2:
	/* 0x1b2: mov    DWORD PTR [rbx+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1b9:
	/* 0x1b9: mov    rax,QWORD PTR [rip+0x2dd7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_tproxy)));
x86_l_1c0:
	/* 0x1c0: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c3:
	/* 0x1c3: je     8fb <cil_to_host+0x8fb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1c3, 0x8fb, x86_l_8fb);
x86_l_1c9:
	/* 0x1c9: mov    r13d,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R15, X86_WIDTH_32);
x86_l_1cc:
	/* 0x1cc: shr    r13d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1d0:
	/* 0x1d0: test   r13w,r13w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_16);
x86_l_1d4:
	/* 0x1d4: je     8fb <cil_to_host+0x8fb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1d4, 0x8fb, x86_l_8fb);
x86_l_1da:
	/* 0x1da: mov    rax,QWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1e1:
	/* 0x1e1: mov    edx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1e4:
	/* 0x1e4: mov    rcx,QWORD PTR [rip+0x2dd7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_1eb:
	/* 0x1eb: sub    edx,DWORD PTR [rbx+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_1ee:
	/* 0x1ee: movzx  esi,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1f1:
	/* 0x1f1: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f4:
	/* 0x1f4: je     24e <cil_to_host+0x24e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1f4, 0x24e, x86_l_24e);
x86_l_1f6:
	/* 0x1f6: mov    ebp,0xffffff5a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967130ULL);
x86_l_1fb:
	/* 0x1fb: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_1fd:
	/* 0x1fd: jb     852 <cil_to_host+0x852> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1fd, 0x852, x86_l_852);
x86_l_203:
	/* 0x203: movzx  esi,WORD PTR [rax+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_207:
	/* 0x207: cmp    si,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_16, 6ULL);
x86_l_20b:
	/* 0x20b: jb     852 <cil_to_host+0x852> */
	X86_SIM_X86_JCC(X86_CC_B, 0x20b, 0x852, x86_l_852);
x86_l_211:
	/* 0x211: mov    ebp,0xffffff75 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967157ULL);
x86_l_216:
	/* 0x216: cmp    si,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_16, 8ULL);
x86_l_21a:
	/* 0x21a: je     264 <cil_to_host+0x264> */
	X86_SIM_X86_JCC(X86_CC_E, 0x21a, 0x264, x86_l_264);
x86_l_21c:
	/* 0x21c: jmp    852 <cil_to_host+0x852> */
	X86_SIM_X86_JMP(0x21c, 0x852, x86_l_852);
x86_l_221:
	/* 0x221: mov    QWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_22a:
	/* 0x22a: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22f:
	/* 0x22f: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_234:
	/* 0x234: mov    rdi,QWORD PTR [rip+0x2dd7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_23b:
	/* 0x23b: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_240:
	/* 0x240: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_245:
	/* 0x245: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_247:
	/* 0x247: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_249:
	/* 0x249: jmp    90e <cil_to_host+0x90e> */
	X86_SIM_X86_JMP(0x249, 0x90e, x86_l_90e);
x86_l_24e:
	/* 0x24e: movzx  esi,WORD PTR [rbx+0xb4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 180ULL);
x86_l_255:
	/* 0x255: mov    ebp,0xffffff75 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967157ULL);
x86_l_25a:
	/* 0x25a: cmp    si,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_16, 8ULL);
x86_l_25e:
	/* 0x25e: jne    852 <cil_to_host+0x852> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x25e, 0x852, x86_l_852);
x86_l_264:
	/* 0x264: add    rdx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_267:
	/* 0x267: movzx  esi,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_26a:
	/* 0x26a: lea    rdi,[rax+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_26e:
	/* 0x26e: add    rdi,0x14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 20ULL);
x86_l_272:
	/* 0x272: mov    ebp,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967162ULL);
x86_l_277:
	/* 0x277: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_27a:
	/* 0x27a: ja     852 <cil_to_host+0x852> */
	X86_SIM_X86_JCC(X86_CC_A, 0x27a, 0x852, x86_l_852);
x86_l_280:
	/* 0x280: add    rax,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_283:
	/* 0x283: movabs rdx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 2199023255552ULL);
x86_l_28d:
	/* 0x28d: movabs r9,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_64, 1099511627776ULL);
x86_l_297:
	/* 0x297: movzx  edi,WORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_29b:
	/* 0x29b: movzx  esi,BYTE PTR [rax+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_29f:
	/* 0x29f: mov    r8,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RSI, X86_WIDTH_64);
x86_l_2a2:
	/* 0x2a2: shl    r8,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_2a6:
	/* 0x2a6: or     r8,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDI, X86_WIDTH_64, X86_ALU_OR);
x86_l_2a9:
	/* 0x2a9: movzx  edi,WORD PTR [rax+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_2ad:
	/* 0x2ad: add    r9,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2b0:
	/* 0x2b0: test   edi,0xff3f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDI, X86_WIDTH_32, 65343ULL);
x86_l_2b6:
	/* 0x2b6: cmove  r9,r8 */
	X86_SIM_L_EXEC_CMOV(X86_R9, X86_R8, X86_WIDTH_64, X86_CC_E);
x86_l_2ba:
	/* 0x2ba: lea    r14,[r9+rdx*1] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_2be:
	/* 0x2be: test   edi,0xff1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDI, X86_WIDTH_32, 65311ULL);
x86_l_2c4:
	/* 0x2c4: cmove  r14,r9 */
	X86_SIM_L_EXEC_CMOV(X86_R14, X86_R9, X86_WIDTH_64, X86_CC_E);
x86_l_2c8:
	/* 0x2c8: mov    BYTE PTR [rsp+0x24],sil */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2cd:
	/* 0x2cd: cmp    esi,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_2d0:
	/* 0x2d0: je     2e0 <cil_to_host+0x2e0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2d0, 0x2e0, x86_l_2e0);
x86_l_2d2:
	/* 0x2d2: mov    ebp,0xffffff77 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967159ULL);
x86_l_2d7:
	/* 0x2d7: cmp    esi,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 6ULL);
x86_l_2da:
	/* 0x2da: jne    852 <cil_to_host+0x852> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2da, 0x852, x86_l_852);
x86_l_2e0:
	/* 0x2e0: mov    edi,DWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e3:
	/* 0x2e3: mov    DWORD PTR [rsp+0x18],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2e7:
	/* 0x2e7: mov    r8d,DWORD PTR [rax+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2eb:
	/* 0x2eb: mov    DWORD PTR [rsp+0x1c],r8d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2f0:
	/* 0x2f0: movzx  ecx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_2f3:
	/* 0x2f3: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f5:
	/* 0x2f5: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_2f8:
	/* 0x2f8: lea    esi,[rcx+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_2fb:
	/* 0x2fb: lea    rbp,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_300:
	/* 0x300: mov    rax,QWORD PTR [rip+0x2dd7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_ipv4_fragments)));
x86_l_307:
	/* 0x307: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30a:
	/* 0x30a: je     43e <cil_to_host+0x43e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x30a, 0x43e, x86_l_43e);
x86_l_310:
	/* 0x310: mov    DWORD PTR [rsp+0x34],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_314:
	/* 0x314: mov    DWORD PTR [rsp+0x38],r8d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_319:
	/* 0x319: mov    WORD PTR [rsp+0x3c],r14w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_31f:
	/* 0x31f: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_322:
	/* 0x322: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_326:
	/* 0x326: mov    BYTE PTR [rsp+0x3e],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 62ULL);
x86_l_32a:
	/* 0x32a: mov    BYTE PTR [rsp+0x3f],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 270582939648ULL);
x86_l_32f:
	/* 0x32f: test   r14,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_RDX, X86_WIDTH_64);
x86_l_332:
	/* 0x332: jne    982 <cil_to_host+0x982> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x332, 0x982, x86_l_982);
x86_l_338:
	/* 0x338: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_33d:
	/* 0x33d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_340:
	/* 0x340: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_343:
	/* 0x343: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_348:
	/* 0x348: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34a:
	/* 0x34a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_34c:
	/* 0x34c: js     4bb <cil_to_host+0x4bb> */
	X86_SIM_X86_JCC(X86_CC_S, 0x34c, 0x4bb, x86_l_4bb);
x86_l_352:
	/* 0x352: movabs rax,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 1099511627776ULL);
x86_l_35c:
	/* 0x35c: test   r14,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_35f:
	/* 0x35f: je     45d <cil_to_host+0x45d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x35f, 0x45d, x86_l_45d);
x86_l_365:
	/* 0x365: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_36a:
	/* 0x36a: mov    rdi,QWORD PTR [rip+0x2dd7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv4_frag_datagrams)));
x86_l_371:
	/* 0x371: lea    rsi,[rsp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_376:
	/* 0x376: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_379:
	/* 0x379: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_37b:
	/* 0x37b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37d:
	/* 0x37d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_37f:
	/* 0x37f: je     45d <cil_to_host+0x45d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x37f, 0x45d, x86_l_45d);
x86_l_385:
	/* 0x385: mov    r14d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_389:
	/* 0x389: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_392:
	/* 0x392: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_39b:
	/* 0x39b: movabs rax,0x6b0085020a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 459570217482ULL);
x86_l_3a5:
	/* 0x3a5: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3aa:
	/* 0x3aa: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3af:
	/* 0x3af: mov    rdi,QWORD PTR [rip+0x2dd7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_3b6:
	/* 0x3b6: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3bb:
	/* 0x3bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3bd:
	/* 0x3bd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3c0:
	/* 0x3c0: je     9b9 <cil_to_host+0x9b9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3c0, 0x9b9, x86_l_9b9);
x86_l_3c6:
	/* 0x3c6: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_3c9:
	/* 0x3c9: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3cd:
	/* 0x3cd: jmp    45d <cil_to_host+0x45d> */
	X86_SIM_X86_JMP(0x3cd, 0x45d, x86_l_45d);
x86_l_3d2:
	/* 0x3d2: add    rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_3d5:
	/* 0x3d5: movzx  r12d,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_3d9:
	/* 0x3d9: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_3dc:
	/* 0x3dc: and    cl,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 14ULL);
x86_l_3df:
	/* 0x3df: cmp    cl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 6ULL);
x86_l_3e2:
	/* 0x3e2: jb     6ab <cil_to_host+0x6ab> */
	X86_SIM_X86_JCC(X86_CC_B, 0x3e2, 0x6ab, x86_l_6ab);
x86_l_3e8:
	/* 0x3e8: movzx  r14d,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_3ec:
	/* 0x3ec: shl    r12d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHL, 2ULL);
x86_l_3f0:
	/* 0x3f0: and    r12d,0x3c */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 60ULL);
x86_l_3f4:
	/* 0x3f4: je     6ab <cil_to_host+0x6ab> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3f4, 0x6ab, x86_l_6ab);
x86_l_3fa:
	/* 0x3fa: lea    esi,[r14+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_3fe:
	/* 0x3fe: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_403:
	/* 0x403: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_408:
	/* 0x408: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_40b:
	/* 0x40b: mov    QWORD PTR [rsp+0x28],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_410:
	/* 0x410: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_415:
	/* 0x415: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_417:
	/* 0x417: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_419:
	/* 0x419: js     7b <cil_to_host+0x7b> */
	X86_SIM_X86_JCC(X86_CC_S, 0x419, 0x7b, x86_l_7b);
x86_l_41f:
	/* 0x41f: movzx  eax,BYTE PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 24ULL);
x86_l_424:
	/* 0x424: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_426:
	/* 0x426: je     6ab <cil_to_host+0x6ab> */
	X86_SIM_X86_JCC(X86_CC_E, 0x426, 0x6ab, x86_l_6ab);
x86_l_42c:
	/* 0x42c: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_42f:
	/* 0x42f: jne    541 <cil_to_host+0x541> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x42f, 0x541, x86_l_541);
x86_l_435:
	/* 0x435: lea    eax,[r14+0x15] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 21ULL);
x86_l_439:
	/* 0x439: jmp    5c7 <cil_to_host+0x5c7> */
	X86_SIM_X86_JMP(0x439, 0x5c7, x86_l_5c7);
x86_l_43e:
	/* 0x43e: test   r14,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_RDX, X86_WIDTH_64);
x86_l_441:
	/* 0x441: jne    9a5 <cil_to_host+0x9a5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x441, 0x9a5, x86_l_9a5);
x86_l_447:
	/* 0x447: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_44c:
	/* 0x44c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_44f:
	/* 0x44f: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_452:
	/* 0x452: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_457:
	/* 0x457: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_459:
	/* 0x459: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_45b:
	/* 0x45b: js     4bb <cil_to_host+0x4bb> */
	X86_SIM_X86_JCC(X86_CC_S, 0x45b, 0x4bb, x86_l_4bb);
x86_l_45d:
	/* 0x45d: rol    QWORD PTR [rsp+0x18],0x20 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_64, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_ROL)), 103079215136ULL);
x86_l_463:
	/* 0x463: movzx  r14d,BYTE PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 36ULL);
x86_l_469:
	/* 0x469: cmp    r14d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 6ULL);
x86_l_46d:
	/* 0x46d: jne    4c5 <cil_to_host+0x4c5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x46d, 0x4c5, x86_l_4c5);
x86_l_46f:
	/* 0x46f: mov    eax,0x63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 99ULL);
x86_l_474:
	/* 0x474: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_479:
	/* 0x479: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_47c:
	/* 0x47c: mov    edx,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_481:
	/* 0x481: mov    rcx,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_488:
	/* 0x488: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_48b:
	/* 0x48b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_48d:
	/* 0x48d: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_492:
	/* 0x492: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_495:
	/* 0x495: je     706 <cil_to_host+0x706> */
	X86_SIM_X86_JCC(X86_CC_E, 0x495, 0x706, x86_l_706);
x86_l_49b:
	/* 0x49b: mov    ecx,DWORD PTR [rax+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_49e:
	/* 0x49e: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_4a1:
	/* 0x4a1: je     4ac <cil_to_host+0x4ac> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4a1, 0x4ac, x86_l_4ac);
x86_l_4a3:
	/* 0x4a3: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_4a6:
	/* 0x4a6: jne    6da <cil_to_host+0x6da> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4a6, 0x6da, x86_l_6da);
x86_l_4ac:
	/* 0x4ac: mov    ecx,0x56 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 86ULL);
x86_l_4b1:
	/* 0x4b1: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_4b4:
	/* 0x4b4: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_4b6:
	/* 0x4b6: jmp    706 <cil_to_host+0x706> */
	X86_SIM_X86_JMP(0x4b6, 0x706, x86_l_706);
x86_l_4bb:
	/* 0x4bb: mov    ebp,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967161ULL);
x86_l_4c0:
	/* 0x4c0: jmp    852 <cil_to_host+0x852> */
	X86_SIM_X86_JMP(0x4c0, 0x852, x86_l_852);
x86_l_4c5:
	/* 0x4c5: mov    WORD PTR [rsp+0x22],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_4cb:
	/* 0x4cb: mov    WORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_4d2:
	/* 0x4d2: movabs rax,0x100007f00000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 72058139498774528ULL);
x86_l_4dc:
	/* 0x4dc: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4e1:
	/* 0x4e1: cmp    r14d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 17ULL);
x86_l_4e5:
	/* 0x4e5: jne    785 <cil_to_host+0x785> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4e5, 0x785, x86_l_785);
x86_l_4eb:
	/* 0x4eb: mov    eax,0x55 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 85ULL);
x86_l_4f0:
	/* 0x4f0: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4f5:
	/* 0x4f5: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_4f8:
	/* 0x4f8: mov    edx,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_4fd:
	/* 0x4fd: mov    rcx,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_504:
	/* 0x504: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_507:
	/* 0x507: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_509:
	/* 0x509: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_50e:
	/* 0x50e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_511:
	/* 0x511: je     778 <cil_to_host+0x778> */
	X86_SIM_X86_JCC(X86_CC_E, 0x511, 0x778, x86_l_778);
x86_l_517:
	/* 0x517: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_51c:
	/* 0x51c: mov    eax,0x7c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 124ULL);
x86_l_521:
	/* 0x521: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_526:
	/* 0x526: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_529:
	/* 0x529: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_52b:
	/* 0x52b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_52d:
	/* 0x52d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_52f:
	/* 0x52f: mov    ebp,0xffffff4d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967117ULL);
x86_l_534:
	/* 0x534: cmove  ebp,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_537:
	/* 0x537: mov    eax,0x56 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 86ULL);
x86_l_53c:
	/* 0x53c: jmp    76f <cil_to_host+0x76f> */
	X86_SIM_X86_JMP(0x53c, 0x76f, x86_l_76f);
x86_l_541:
	/* 0x541: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_546:
	/* 0x546: lea    esi,[r14+0x15] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 21ULL);
x86_l_54a:
	/* 0x54a: lea    rdx,[rsp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_54f:
	/* 0x54f: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_552:
	/* 0x552: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_557:
	/* 0x557: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_559:
	/* 0x559: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_55b:
	/* 0x55b: js     7b <cil_to_host+0x7b> */
	X86_SIM_X86_JCC(X86_CC_S, 0x55b, 0x7b, x86_l_7b);
x86_l_561:
	/* 0x561: cmp    BYTE PTR [rsp+0x18],bpl */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_566:
	/* 0x566: jne    5b8 <cil_to_host+0x5b8> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x566, 0x5b8, x86_l_5b8);
x86_l_568:
	/* 0x568: movzx  eax,BYTE PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 52ULL);
x86_l_56d:
	/* 0x56d: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_570:
	/* 0x570: je     949 <cil_to_host+0x949> */
	X86_SIM_X86_JCC(X86_CC_E, 0x570, 0x949, x86_l_949);
x86_l_576:
	/* 0x576: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_579:
	/* 0x579: je     91c <cil_to_host+0x91c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x579, 0x91c, x86_l_91c);
x86_l_57f:
	/* 0x57f: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_582:
	/* 0x582: jne    7b <cil_to_host+0x7b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x582, 0x7b, x86_l_7b);
x86_l_588:
	/* 0x588: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_58d:
	/* 0x58d: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_592:
	/* 0x592: add    esi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_595:
	/* 0x595: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_59a:
	/* 0x59a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_59d:
	/* 0x59d: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_5a2:
	/* 0x5a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a4:
	/* 0x5a4: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5a7:
	/* 0x5a7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5a9:
	/* 0x5a9: movbe  cx,WORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOVBE_LOAD, X86_RCX, X86_RSP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_5b0:
	/* 0x5b0: movzx  ecx,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_5b3:
	/* 0x5b3: jmp    971 <cil_to_host+0x971> */
	X86_SIM_X86_JMP(0x5b3, 0x971, x86_l_971);
x86_l_5b8:
	/* 0x5b8: movzx  eax,BYTE PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 52ULL);
x86_l_5bd:
	/* 0x5bd: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5c2:
	/* 0x5c2: add    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_5c4:
	/* 0x5c4: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_5c7:
	/* 0x5c7: add    r14d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R12, X86_WIDTH_32, X86_ALU_ADD);
x86_l_5ca:
	/* 0x5ca: add    r14d,0x14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 20ULL);
x86_l_5ce:
	/* 0x5ce: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5d3:
	/* 0x5d3: cmp    eax,r14d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R14, X86_WIDTH_32);
x86_l_5d6:
	/* 0x5d6: jae    6ab <cil_to_host+0x6ab> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x5d6, 0x6ab, x86_l_6ab);
x86_l_5dc:
	/* 0x5dc: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_5e1:
	/* 0x5e1: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5e6:
	/* 0x5e6: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_5e9:
	/* 0x5e9: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5ee:
	/* 0x5ee: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_5f3:
	/* 0x5f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f5:
	/* 0x5f5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5f7:
	/* 0x5f7: js     7b <cil_to_host+0x7b> */
	X86_SIM_X86_JCC(X86_CC_S, 0x5f7, 0x7b, x86_l_7b);
x86_l_5fd:
	/* 0x5fd: movzx  eax,BYTE PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 24ULL);
x86_l_602:
	/* 0x602: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_604:
	/* 0x604: je     6ab <cil_to_host+0x6ab> */
	X86_SIM_X86_JCC(X86_CC_E, 0x604, 0x6ab, x86_l_6ab);
x86_l_60a:
	/* 0x60a: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_60d:
	/* 0x60d: je     643 <cil_to_host+0x643> */
	X86_SIM_X86_JCC(X86_CC_E, 0x60d, 0x643, x86_l_643);
x86_l_60f:
	/* 0x60f: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_614:
	/* 0x614: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_619:
	/* 0x619: lea    esi,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_61c:
	/* 0x61c: lea    rdx,[rsp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_621:
	/* 0x621: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_624:
	/* 0x624: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_629:
	/* 0x629: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_62b:
	/* 0x62b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_62d:
	/* 0x62d: js     7b <cil_to_host+0x7b> */
	X86_SIM_X86_JCC(X86_CC_S, 0x62d, 0x7b, x86_l_7b);
x86_l_633:
	/* 0x633: cmp    BYTE PTR [rsp+0x18],bpl */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_638:
	/* 0x638: je     568 <cil_to_host+0x568> */
	X86_SIM_X86_JCC(X86_CC_E, 0x638, 0x568, x86_l_568);
x86_l_63e:
	/* 0x63e: movzx  eax,BYTE PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 52ULL);
x86_l_643:
	/* 0x643: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_648:
	/* 0x648: add    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_64a:
	/* 0x64a: mov    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_64f:
	/* 0x64f: cmp    ecx,r14d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R14, X86_WIDTH_32);
x86_l_652:
	/* 0x652: jae    6ab <cil_to_host+0x6ab> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x652, 0x6ab, x86_l_6ab);
x86_l_654:
	/* 0x654: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_659:
	/* 0x659: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_65e:
	/* 0x65e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_661:
	/* 0x661: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_666:
	/* 0x666: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_66b:
	/* 0x66b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_66d:
	/* 0x66d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_66f:
	/* 0x66f: js     7b <cil_to_host+0x7b> */
	X86_SIM_X86_JCC(X86_CC_S, 0x66f, 0x7b, x86_l_7b);
x86_l_675:
	/* 0x675: cmp    BYTE PTR [rsp+0x18],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 103079215106ULL);
x86_l_67a:
	/* 0x67a: jb     6ab <cil_to_host+0x6ab> */
	X86_SIM_X86_JCC(X86_CC_B, 0x67a, 0x6ab, x86_l_6ab);
x86_l_67c:
	/* 0x67c: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_681:
	/* 0x681: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_686:
	/* 0x686: lea    esi,[rcx+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_689:
	/* 0x689: lea    rdx,[rsp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_68e:
	/* 0x68e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_691:
	/* 0x691: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_696:
	/* 0x696: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_698:
	/* 0x698: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_69a:
	/* 0x69a: js     7b <cil_to_host+0x7b> */
	X86_SIM_X86_JCC(X86_CC_S, 0x69a, 0x7b, x86_l_7b);
x86_l_6a0:
	/* 0x6a0: cmp    BYTE PTR [rsp+0x18],bpl */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6a5:
	/* 0x6a5: je     568 <cil_to_host+0x568> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6a5, 0x568, x86_l_568);
x86_l_6ab:
	/* 0x6ab: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6ae:
	/* 0x6ae: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_6b6:
	/* 0x6b6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6bb:
	/* 0x6bb: mov    rdi,QWORD PTR [rip+0x2dd7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_percpu_trace_id)));
x86_l_6c2:
	/* 0x6c2: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6c7:
	/* 0x6c7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6c9:
	/* 0x6c9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6cc:
	/* 0x6cc: je     a2 <cil_to_host+0xa2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6cc, 0xa2, x86_l_a2);
x86_l_6d2:
	/* 0x6d2: mov    QWORD PTR [rax],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6d5:
	/* 0x6d5: jmp    a2 <cil_to_host+0xa2> */
	X86_SIM_X86_JMP(0x6d5, 0xa2, x86_l_a2);
x86_l_6da:
	/* 0x6da: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6df:
	/* 0x6df: mov    eax,0x7c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 124ULL);
x86_l_6e4:
	/* 0x6e4: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6e9:
	/* 0x6e9: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_6ec:
	/* 0x6ec: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6ee:
	/* 0x6ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6f0:
	/* 0x6f0: mov    ebp,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_6f2:
	/* 0x6f2: mov    eax,0x56 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 86ULL);
x86_l_6f7:
	/* 0x6f7: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6fc:
	/* 0x6fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6fe:
	/* 0x6fe: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_700:
	/* 0x700: je     8fb <cil_to_host+0x8fb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x700, 0x8fb, x86_l_8fb);
x86_l_706:
	/* 0x706: mov    WORD PTR [rsp+0x22],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_70c:
	/* 0x70c: mov    WORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_713:
	/* 0x713: movabs rax,0x100007f00000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 72058139498774528ULL);
x86_l_71d:
	/* 0x71d: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_722:
	/* 0x722: mov    eax,0x63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 99ULL);
x86_l_727:
	/* 0x727: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_72c:
	/* 0x72c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_72f:
	/* 0x72f: mov    edx,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_734:
	/* 0x734: mov    rcx,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_73b:
	/* 0x73b: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_73e:
	/* 0x73e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_740:
	/* 0x740: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_745:
	/* 0x745: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_748:
	/* 0x748: je     778 <cil_to_host+0x778> */
	X86_SIM_X86_JCC(X86_CC_E, 0x748, 0x778, x86_l_778);
x86_l_74a:
	/* 0x74a: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_74f:
	/* 0x74f: mov    eax,0x7c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 124ULL);
x86_l_754:
	/* 0x754: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_759:
	/* 0x759: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_75c:
	/* 0x75c: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_75e:
	/* 0x75e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_760:
	/* 0x760: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_762:
	/* 0x762: mov    ebp,0xffffff4d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967117ULL);
x86_l_767:
	/* 0x767: cmove  ebp,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_76a:
	/* 0x76a: mov    eax,0x56 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 86ULL);
x86_l_76f:
	/* 0x76f: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_774:
	/* 0x774: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_776:
	/* 0x776: jmp    77d <cil_to_host+0x77d> */
	X86_SIM_X86_JMP(0x776, 0x77d, x86_l_77d);
x86_l_778:
	/* 0x778: mov    ebp,0xffffff4e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967118ULL);
x86_l_77d:
	/* 0x77d: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_77f:
	/* 0x77f: je     8fb <cil_to_host+0x8fb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x77f, 0x8fb, x86_l_8fb);
x86_l_785:
	/* 0x785: mov    DWORD PTR [rsp+0x1c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084288ULL);
x86_l_78d:
	/* 0x78d: cmp    r14d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 6ULL);
x86_l_791:
	/* 0x791: je     7f0 <cil_to_host+0x7f0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x791, 0x7f0, x86_l_7f0);
x86_l_793:
	/* 0x793: cmp    r14d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 17ULL);
x86_l_797:
	/* 0x797: jne    84d <cil_to_host+0x84d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x797, 0x84d, x86_l_84d);
x86_l_79d:
	/* 0x79d: mov    eax,0x55 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 85ULL);
x86_l_7a2:
	/* 0x7a2: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_7a7:
	/* 0x7a7: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_7aa:
	/* 0x7aa: mov    edx,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_7af:
	/* 0x7af: mov    rcx,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_7b6:
	/* 0x7b6: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7b9:
	/* 0x7b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7bb:
	/* 0x7bb: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7c0:
	/* 0x7c0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7c3:
	/* 0x7c3: je     8ee <cil_to_host+0x8ee> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7c3, 0x8ee, x86_l_8ee);
x86_l_7c9:
	/* 0x7c9: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7ce:
	/* 0x7ce: mov    eax,0x7c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 124ULL);
x86_l_7d3:
	/* 0x7d3: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7d8:
	/* 0x7d8: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_7db:
	/* 0x7db: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7dd:
	/* 0x7dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7df:
	/* 0x7df: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_7e1:
	/* 0x7e1: mov    ebp,0xffffff4d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967117ULL);
x86_l_7e6:
	/* 0x7e6: cmove  ebp,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_7e9:
	/* 0x7e9: mov    eax,0x56 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 86ULL);
x86_l_7ee:
	/* 0x7ee: jmp    841 <cil_to_host+0x841> */
	X86_SIM_X86_JMP(0x7ee, 0x841, x86_l_841);
x86_l_7f0:
	/* 0x7f0: mov    eax,0x63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 99ULL);
x86_l_7f5:
	/* 0x7f5: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_7fa:
	/* 0x7fa: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_7fd:
	/* 0x7fd: mov    edx,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_802:
	/* 0x802: mov    rcx,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_809:
	/* 0x809: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_80c:
	/* 0x80c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_80e:
	/* 0x80e: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_813:
	/* 0x813: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_816:
	/* 0x816: je     8ee <cil_to_host+0x8ee> */
	X86_SIM_X86_JCC(X86_CC_E, 0x816, 0x8ee, x86_l_8ee);
x86_l_81c:
	/* 0x81c: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_821:
	/* 0x821: mov    eax,0x7c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 124ULL);
x86_l_826:
	/* 0x826: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_82b:
	/* 0x82b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_82e:
	/* 0x82e: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_830:
	/* 0x830: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_832:
	/* 0x832: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_834:
	/* 0x834: mov    ebp,0xffffff4d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967117ULL);
x86_l_839:
	/* 0x839: cmove  ebp,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_83c:
	/* 0x83c: mov    eax,0x56 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 86ULL);
x86_l_841:
	/* 0x841: mov    rdi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_846:
	/* 0x846: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_848:
	/* 0x848: jmp    8f3 <cil_to_host+0x8f3> */
	X86_SIM_X86_JMP(0x848, 0x8f3, x86_l_8f3);
x86_l_84d:
	/* 0x84d: mov    ebp,0xffffff4c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967116ULL);
x86_l_852:
	/* 0x852: neg    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_854:
	/* 0x854: mov    DWORD PTR [rbx+0x28],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_858:
	/* 0x858: mov    DWORD PTR [rbx+0x2c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561024ULL);
x86_l_85f:
	/* 0x85f: mov    DWORD PTR [rbx+0x30],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_862:
	/* 0x862: movabs rax,0x6f1010200000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 500182141716398080ULL);
x86_l_86c:
	/* 0x86c: mov    QWORD PTR [rbx+0x34],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_870:
	/* 0x870: mov    r14d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_874:
	/* 0x874: movabs rax,0x106f10100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 4411425024ULL);
x86_l_87e:
	/* 0x87e: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_883:
	/* 0x883: mov    BYTE PTR [rsp+0x18],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_888:
	/* 0x888: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_88d:
	/* 0x88d: mov    rdi,QWORD PTR [rip+0x2dd7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_894:
	/* 0x894: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_899:
	/* 0x899: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_89b:
	/* 0x89b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_89e:
	/* 0x89e: je     8a9 <cil_to_host+0x8a9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x89e, 0x8a9, x86_l_8a9);
x86_l_8a0:
	/* 0x8a0: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_8a3:
	/* 0x8a3: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_8a7:
	/* 0x8a7: jmp    8d1 <cil_to_host+0x8d1> */
	X86_SIM_X86_JMP(0x8a7, 0x8d1, x86_l_8d1);
x86_l_8a9:
	/* 0x8a9: mov    QWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_8b2:
	/* 0x8b2: mov    QWORD PTR [rsp+0x10],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8b7:
	/* 0x8b7: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_8bc:
	/* 0x8bc: mov    rdi,QWORD PTR [rip+0x2dd7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_8c3:
	/* 0x8c3: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_8c8:
	/* 0x8c8: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8cd:
	/* 0x8cd: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8cf:
	/* 0x8cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8d1:
	/* 0x8d1: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_8d6:
	/* 0x8d6: mov    rsi,QWORD PTR [rip+0x2dd7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_8dd:
	/* 0x8dd: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_8e0:
	/* 0x8e0: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_8e5:
	/* 0x8e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8e7:
	/* 0x8e7: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_8ec:
	/* 0x8ec: jmp    910 <cil_to_host+0x910> */
	X86_SIM_X86_JMP(0x8ec, 0x910, x86_l_910);
x86_l_8ee:
	/* 0x8ee: mov    ebp,0xffffff4e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967118ULL);
x86_l_8f3:
	/* 0x8f3: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_8f5:
	/* 0x8f5: js     852 <cil_to_host+0x852> */
	X86_SIM_X86_JCC(X86_CC_S, 0x8f5, 0x852, x86_l_852);
x86_l_8fb:
	/* 0x8fb: mov    DWORD PTR [rbx+0xa8],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_902:
	/* 0x902: mov    eax,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_907:
	/* 0x907: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_90a:
	/* 0x90a: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_90c:
	/* 0x90c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_90e:
	/* 0x90e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_910:
	/* 0x910: add    rsp,0x48 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 72ULL);
x86_l_914:
	/* 0x914: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_916:
	/* 0x916: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_917:
	/* 0x917: jmp    9e6 <cil_to_host+0x9e6> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_91c:
	/* 0x91c: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_921:
	/* 0x921: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_926:
	/* 0x926: add    esi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_929:
	/* 0x929: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_92e:
	/* 0x92e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_931:
	/* 0x931: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_936:
	/* 0x936: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_938:
	/* 0x938: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_93a:
	/* 0x93a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_93c:
	/* 0x93c: movbe  r14d,DWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOVBE_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_943:
	/* 0x943: cmovs  r14d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R14, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_947:
	/* 0x947: jmp    975 <cil_to_host+0x975> */
	X86_SIM_X86_JMP(0x947, 0x975, x86_l_975);
x86_l_949:
	/* 0x949: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_94e:
	/* 0x94e: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_953:
	/* 0x953: add    esi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_956:
	/* 0x956: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_95b:
	/* 0x95b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_95e:
	/* 0x95e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_963:
	/* 0x963: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_965:
	/* 0x965: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_968:
	/* 0x968: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_96a:
	/* 0x96a: movbe  rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOVBE_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_971:
	/* 0x971: cmovns r14,rcx */
	X86_SIM_L_EXEC_CMOV(X86_R14, X86_RCX, X86_WIDTH_64, X86_CC_NS);
x86_l_975:
	/* 0x975: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_977:
	/* 0x977: jns    6ae <cil_to_host+0x6ae> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x977, 0x6ae, x86_l_6ae);
x86_l_97d:
	/* 0x97d: jmp    7b <cil_to_host+0x7b> */
	X86_SIM_X86_JMP(0x97d, 0x7b, x86_l_7b);
x86_l_982:
	/* 0x982: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_987:
	/* 0x987: mov    rdi,QWORD PTR [rip+0x2dda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv4_frag_datagrams)));
x86_l_98e:
	/* 0x98e: lea    rsi,[rsp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_993:
	/* 0x993: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_995:
	/* 0x995: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_998:
	/* 0x998: je     9af <cil_to_host+0x9af> */
	X86_SIM_X86_JCC(X86_CC_E, 0x998, 0x9af, x86_l_9af);
x86_l_99a:
	/* 0x99a: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_99c:
	/* 0x99c: mov    DWORD PTR [rsp+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9a0:
	/* 0x9a0: jmp    45d <cil_to_host+0x45d> */
	X86_SIM_X86_JMP(0x9a0, 0x45d, x86_l_45d);
x86_l_9a5:
	/* 0x9a5: mov    ebp,0xffffff63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967139ULL);
x86_l_9aa:
	/* 0x9aa: jmp    852 <cil_to_host+0x852> */
	X86_SIM_X86_JMP(0x9aa, 0x852, x86_l_852);
x86_l_9af:
	/* 0x9af: mov    ebp,0xffffff51 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 4294967121ULL);
x86_l_9b4:
	/* 0x9b4: jmp    852 <cil_to_host+0x852> */
	X86_SIM_X86_JMP(0x9b4, 0x852, x86_l_852);
x86_l_9b9:
	/* 0x9b9: mov    QWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_9c2:
	/* 0x9c2: mov    QWORD PTR [rsp+0x10],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9c7:
	/* 0x9c7: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_9cc:
	/* 0x9cc: mov    rdi,QWORD PTR [rip+0x2dda] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_9d3:
	/* 0x9d3: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_9d8:
	/* 0x9d8: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9dd:
	/* 0x9dd: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9df:
	/* 0x9df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9e1:
	/* 0x9e1: jmp    45d <cil_to_host+0x45d> */
	X86_SIM_X86_JMP(0x9e1, 0x45d, x86_l_45d);
x86_l_9e6:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
