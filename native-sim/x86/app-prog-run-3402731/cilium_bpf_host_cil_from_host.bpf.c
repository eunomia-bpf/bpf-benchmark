extern char __config_cluster_id_bits;
extern char __config_enable_l2_announcements;
extern char __config_eth_header_length;
extern char __config_interface_mac;
extern char __config_l2_announcements_max_liveness;
extern char __config_trace_payload_len;
extern char __config_tracing_ip_option_type;
extern char cilium_calls;
extern char cilium_ipcache_v2;
extern char cilium_l2_responder_v4;
extern char cilium_metrics;
extern char cilium_percpu_trace_id;
extern char cilium_runtime_config;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int cilium_bpf_host_cil_from_host_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0xa: sub    rsp,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 56ULL);
x86_l_e:
	/* 0xe: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_11:
	/* 0x11: mov    DWORD PTR [rdi+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_18:
	/* 0x18: mov    DWORD PTR [rdi+0x2c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561024ULL);
x86_l_1f:
	/* 0x1f: mov    DWORD PTR [rdi+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_26:
	/* 0x26: mov    DWORD PTR [rdi+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_2d:
	/* 0x2d: mov    DWORD PTR [rdi+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_34:
	/* 0x34: mov    r15,QWORD PTR [rip+0xb70] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_tracing_ip_option_type)));
x86_l_3b:
	/* 0x3b: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f:
	/* 0x3f: je     c6 <cil_from_host+0xc6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3f, 0xc6, x86_l_c6);
x86_l_45:
	/* 0x45: movzx  ebp,BYTE PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_49:
	/* 0x49: mov    rcx,QWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_50:
	/* 0x50: mov    edx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_53:
	/* 0x53: mov    rax,QWORD PTR [rip+0xb70] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_5a:
	/* 0x5a: sub    edx,DWORD PTR [rbx+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_5d:
	/* 0x5d: movzx  esi,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_60:
	/* 0x60: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_63:
	/* 0x63: je     7b <cil_from_host+0x7b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x63, 0x7b, x86_l_7b);
x86_l_65:
	/* 0x65: cmp    edx,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_32);
x86_l_67:
	/* 0x67: jb     9f <cil_from_host+0x9f> */
	X86_SIM_X86_JCC(X86_CC_B, 0x67, 0x9f, x86_l_9f);
x86_l_69:
	/* 0x69: movzx  esi,WORD PTR [rcx+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_6d:
	/* 0x6d: cmp    si,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_16, 6ULL);
x86_l_71:
	/* 0x71: jb     9f <cil_from_host+0x9f> */
	X86_SIM_X86_JCC(X86_CC_B, 0x71, 0x9f, x86_l_9f);
x86_l_73:
	/* 0x73: cmp    si,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_16, 8ULL);
x86_l_77:
	/* 0x77: je     88 <cil_from_host+0x88> */
	X86_SIM_X86_JCC(X86_CC_E, 0x77, 0x88, x86_l_88);
x86_l_79:
	/* 0x79: jmp    9f <cil_from_host+0x9f> */
	X86_SIM_X86_JMP(0x79, 0x9f, x86_l_9f);
x86_l_7b:
	/* 0x7b: movzx  esi,WORD PTR [rbx+0xb4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 180ULL);
x86_l_82:
	/* 0x82: cmp    si,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_16, 8ULL);
x86_l_86:
	/* 0x86: jne    9f <cil_from_host+0x9f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x86, 0x9f, x86_l_9f);
x86_l_88:
	/* 0x88: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_8b:
	/* 0x8b: movzx  esi,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_8e:
	/* 0x8e: lea    rdi,[rcx+rsi*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_RSI, 0), 0ULL);
x86_l_92:
	/* 0x92: add    rdi,0x14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 20ULL);
x86_l_96:
	/* 0x96: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_99:
	/* 0x99: jbe    5b9 <cil_from_host+0x5b9> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x99, 0x5b9, x86_l_5b9);
x86_l_9f:
	/* 0x9f: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_a7:
	/* 0xa7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ac:
	/* 0xac: mov    rdi,QWORD PTR [rip+0xb70] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_percpu_trace_id)));
x86_l_b3:
	/* 0xb3: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b8:
	/* 0xb8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ba:
	/* 0xba: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_bd:
	/* 0xbd: je     c6 <cil_from_host+0xc6> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbd, 0xc6, x86_l_c6);
x86_l_bf:
	/* 0xbf: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c6:
	/* 0xc6: mov    rax,QWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_cd:
	/* 0xcd: mov    ecx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_d0:
	/* 0xd0: mov    edx,DWORD PTR [rbx+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_d3:
	/* 0xd3: mov    r12,QWORD PTR [rip+0xb70] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_da:
	/* 0xda: movzx  esi,BYTE PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_df:
	/* 0xdf: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e4:
	/* 0xe4: je     15a <cil_from_host+0x15a> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe4, 0x15a, x86_l_15a);
x86_l_e6:
	/* 0xe6: mov    edi,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RCX, X86_WIDTH_32);
x86_l_e8:
	/* 0xe8: sub    edi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_ea:
	/* 0xea: cmp    edi,esi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RSI, X86_WIDTH_32);
x86_l_ec:
	/* 0xec: jb     f8 <cil_from_host+0xf8> */
	X86_SIM_X86_JCC(X86_CC_B, 0xec, 0xf8, x86_l_f8);
x86_l_ee:
	/* 0xee: movzx  eax,WORD PTR [rax+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_f2:
	/* 0xf2: cmp    ax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_16, 5ULL);
x86_l_f6:
	/* 0xf6: ja     161 <cil_from_host+0x161> */
	X86_SIM_X86_JCC(X86_CC_A, 0xf6, 0x161, x86_l_161);
x86_l_f8:
	/* 0xf8: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fc:
	/* 0xfc: je     11c <cil_from_host+0x11c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfc, 0x11c, x86_l_11c);
x86_l_fe:
	/* 0xfe: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_106:
	/* 0x106: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_10b:
	/* 0x10b: mov    rdi,QWORD PTR [rip+0xb70] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_percpu_trace_id)));
x86_l_112:
	/* 0x112: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_117:
	/* 0x117: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_119:
	/* 0x119: mov    ecx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_11c:
	/* 0x11c: mov    ebx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RCX, X86_WIDTH_32);
x86_l_11e:
	/* 0x11e: movabs rax,0x1045c0103 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 4368105731ULL);
x86_l_128:
	/* 0x128: add    rax,0xa700fd */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 10944765ULL);
x86_l_12e:
	/* 0x12e: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_132:
	/* 0x132: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_137:
	/* 0x137: mov    rdi,QWORD PTR [rip+0xb70] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_13e:
	/* 0x13e: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_141:
	/* 0x141: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_143:
	/* 0x143: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_146:
	/* 0x146: je     259 <cil_from_host+0x259> */
	X86_SIM_X86_JCC(X86_CC_E, 0x146, 0x259, x86_l_259);
x86_l_14c:
	/* 0x14c: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_14f:
	/* 0x14f: add    QWORD PTR [rax+0x8],rbx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_153:
	/* 0x153: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_155:
	/* 0x155: jmp    9fb <cil_from_host+0x9fb> */
	X86_SIM_X86_JMP(0x155, 0x9fb, x86_l_9fb);
x86_l_15a:
	/* 0x15a: movzx  eax,WORD PTR [rbx+0xb4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 180ULL);
x86_l_161:
	/* 0x161: mov    r13d,DWORD PTR [rbx+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_168:
	/* 0x168: mov    ecx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_32);
x86_l_16b:
	/* 0x16b: and    ecx,0xf00 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 3840ULL);
x86_l_171:
	/* 0x171: add    ecx,0xfffff600 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 4294964736ULL);
x86_l_177:
	/* 0x177: shr    ecx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_17a:
	/* 0x17a: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_17d:
	/* 0x17d: jg     1ef <cil_from_host+0x1ef> */
	X86_SIM_X86_JCC(X86_CC_G, 0x17d, 0x1ef, x86_l_1ef);
x86_l_17f:
	/* 0x17f: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_181:
	/* 0x181: je     28e <cil_from_host+0x28e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x181, 0x28e, x86_l_28e);
x86_l_187:
	/* 0x187: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_18a:
	/* 0x18a: jne    286 <cil_from_host+0x286> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x18a, 0x286, x86_l_286);
x86_l_190:
	/* 0x190: movzx  edx,r13b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_R13, X86_WIDTH_32, X86_WIDTH_8);
x86_l_194:
	/* 0x194: mov    rcx,QWORD PTR [rip+0xb70] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_cluster_id_bits)));
x86_l_19b:
	/* 0x19b: mov    esi,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19d:
	/* 0x19d: mov    edi,0x7fffff00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 2147483392ULL);
x86_l_1a2:
	/* 0x1a2: bzhi   esi,edi,esi */
	X86_SIM_RUN_OP(X86_OP_BZHI, X86_RSI, X86_RDI, X86_WIDTH_32, X86_RSI, 0);
x86_l_1a7:
	/* 0x1a7: mov    edi,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a9:
	/* 0x1a9: neg    dil */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_8, X86_ALU_NEG, 0);
x86_l_1ac:
	/* 0x1ac: shlx   esi,esi,edi */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RSI, X86_RSI, X86_WIDTH_32, X86_RDI, X86_ALU_SHL);
x86_l_1b1:
	/* 0x1b1: and    esi,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R13, X86_WIDTH_32, X86_ALU_AND);
x86_l_1b4:
	/* 0x1b4: mov    edi,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b6:
	/* 0x1b6: neg    dil */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_8, X86_ALU_NEG, 0);
x86_l_1b9:
	/* 0x1b9: shrx   esi,esi,edi */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RSI, X86_RSI, X86_WIDTH_32, X86_RDI, X86_ALU_SHR);
x86_l_1be:
	/* 0x1be: or     esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1c0:
	/* 0x1c0: mov    edx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_32);
x86_l_1c3:
	/* 0x1c3: shr    edx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1c6:
	/* 0x1c6: mov    edi,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c8:
	/* 0x1c8: mov    r8b,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_8, 24ULL);
x86_l_1cb:
	/* 0x1cb: mov    r9b,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_8, 24ULL);
x86_l_1ce:
	/* 0x1ce: sub    r9b,dil */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_RDI, X86_WIDTH_8, X86_ALU_SUB);
x86_l_1d1:
	/* 0x1d1: bzhi   edx,edx,r9d */
	X86_SIM_RUN_OP(X86_OP_BZHI, X86_RDX, X86_RDX, X86_WIDTH_32, X86_R9, 0);
x86_l_1d6:
	/* 0x1d6: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d8:
	/* 0x1d8: sub    r8b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_1db:
	/* 0x1db: shlx   r14d,esi,r8d */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_R14, X86_RSI, X86_WIDTH_32, X86_R8, X86_ALU_SHL);
x86_l_1e0:
	/* 0x1e0: or     r14d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1e3:
	/* 0x1e3: or     BYTE PTR [rbx+0x86],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RBX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 575525617666ULL);
x86_l_1ea:
	/* 0x1ea: jmp    2f0 <cil_from_host+0x2f0> */
	X86_SIM_X86_JMP(0x1ea, 0x2f0, x86_l_2f0);
x86_l_1ef:
	/* 0x1ef: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1f2:
	/* 0x1f2: je     2ea <cil_from_host+0x2ea> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1f2, 0x2ea, x86_l_2ea);
x86_l_1f8:
	/* 0x1f8: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1fb:
	/* 0x1fb: jne    286 <cil_from_host+0x286> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1fb, 0x286, x86_l_286);
x86_l_201:
	/* 0x201: movzx  edx,r13b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_R13, X86_WIDTH_32, X86_WIDTH_8);
x86_l_205:
	/* 0x205: mov    rcx,QWORD PTR [rip+0xb70] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_cluster_id_bits)));
x86_l_20c:
	/* 0x20c: mov    esi,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20e:
	/* 0x20e: mov    edi,0x7fffff00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 2147483392ULL);
x86_l_213:
	/* 0x213: bzhi   esi,edi,esi */
	X86_SIM_RUN_OP(X86_OP_BZHI, X86_RSI, X86_RDI, X86_WIDTH_32, X86_RSI, 0);
x86_l_218:
	/* 0x218: mov    edi,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21a:
	/* 0x21a: neg    dil */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_8, X86_ALU_NEG, 0);
x86_l_21d:
	/* 0x21d: shlx   esi,esi,edi */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RSI, X86_RSI, X86_WIDTH_32, X86_RDI, X86_ALU_SHL);
x86_l_222:
	/* 0x222: and    esi,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R13, X86_WIDTH_32, X86_ALU_AND);
x86_l_225:
	/* 0x225: mov    edi,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_227:
	/* 0x227: neg    dil */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_8, X86_ALU_NEG, 0);
x86_l_22a:
	/* 0x22a: shrx   esi,esi,edi */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RSI, X86_RSI, X86_WIDTH_32, X86_RDI, X86_ALU_SHR);
x86_l_22f:
	/* 0x22f: or     esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_231:
	/* 0x231: mov    edx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_32);
x86_l_234:
	/* 0x234: shr    edx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_237:
	/* 0x237: mov    edi,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_239:
	/* 0x239: mov    r8b,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_8, 24ULL);
x86_l_23c:
	/* 0x23c: mov    r9b,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_8, 24ULL);
x86_l_23f:
	/* 0x23f: sub    r9b,dil */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_RDI, X86_WIDTH_8, X86_ALU_SUB);
x86_l_242:
	/* 0x242: bzhi   edx,edx,r9d */
	X86_SIM_RUN_OP(X86_OP_BZHI, X86_RDX, X86_RDX, X86_WIDTH_32, X86_R9, 0);
x86_l_247:
	/* 0x247: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_249:
	/* 0x249: sub    r8b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_24c:
	/* 0x24c: shlx   r14d,esi,r8d */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_R14, X86_RSI, X86_WIDTH_32, X86_R8, X86_ALU_SHL);
x86_l_251:
	/* 0x251: or     r14d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_254:
	/* 0x254: jmp    2f0 <cil_from_host+0x2f0> */
	X86_SIM_X86_JMP(0x254, 0x2f0, x86_l_2f0);
x86_l_259:
	/* 0x259: mov    QWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_262:
	/* 0x262: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_267:
	/* 0x267: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_26c:
	/* 0x26c: mov    rdi,QWORD PTR [rip+0xb70] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_273:
	/* 0x273: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_276:
	/* 0x276: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27b:
	/* 0x27b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_27d:
	/* 0x27d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27f:
	/* 0x27f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_281:
	/* 0x281: jmp    9fb <cil_from_host+0x9fb> */
	X86_SIM_X86_JMP(0x281, 0x9fb, x86_l_9fb);
x86_l_286:
	/* 0x286: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_28c:
	/* 0x28c: jmp    2f0 <cil_from_host+0x2f0> */
	X86_SIM_X86_JMP(0x28c, 0x2f0, x86_l_2f0);
x86_l_28e:
	/* 0x28e: movzx  edx,r13b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_R13, X86_WIDTH_32, X86_WIDTH_8);
x86_l_292:
	/* 0x292: mov    rcx,QWORD PTR [rip+0xb70] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_cluster_id_bits)));
x86_l_299:
	/* 0x299: mov    esi,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_29b:
	/* 0x29b: mov    edi,0x7fffff00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 2147483392ULL);
x86_l_2a0:
	/* 0x2a0: bzhi   esi,edi,esi */
	X86_SIM_RUN_OP(X86_OP_BZHI, X86_RSI, X86_RDI, X86_WIDTH_32, X86_RSI, 0);
x86_l_2a5:
	/* 0x2a5: mov    edi,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2a7:
	/* 0x2a7: neg    dil */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_8, X86_ALU_NEG, 0);
x86_l_2aa:
	/* 0x2aa: shlx   esi,esi,edi */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RSI, X86_RSI, X86_WIDTH_32, X86_RDI, X86_ALU_SHL);
x86_l_2af:
	/* 0x2af: and    esi,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R13, X86_WIDTH_32, X86_ALU_AND);
x86_l_2b2:
	/* 0x2b2: mov    edi,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b4:
	/* 0x2b4: neg    dil */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_8, X86_ALU_NEG, 0);
x86_l_2b7:
	/* 0x2b7: shrx   esi,esi,edi */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RSI, X86_RSI, X86_WIDTH_32, X86_RDI, X86_ALU_SHR);
x86_l_2bc:
	/* 0x2bc: or     esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_2be:
	/* 0x2be: mov    edx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_32);
x86_l_2c1:
	/* 0x2c1: shr    edx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_2c4:
	/* 0x2c4: mov    edi,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c6:
	/* 0x2c6: mov    r8b,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_8, 24ULL);
x86_l_2c9:
	/* 0x2c9: mov    r9b,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_8, 24ULL);
x86_l_2cc:
	/* 0x2cc: sub    r9b,dil */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_RDI, X86_WIDTH_8, X86_ALU_SUB);
x86_l_2cf:
	/* 0x2cf: bzhi   edx,edx,r9d */
	X86_SIM_RUN_OP(X86_OP_BZHI, X86_RDX, X86_RDX, X86_WIDTH_32, X86_R9, 0);
x86_l_2d4:
	/* 0x2d4: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d6:
	/* 0x2d6: sub    r8b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_2d9:
	/* 0x2d9: shlx   r14d,esi,r8d */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_R14, X86_RSI, X86_WIDTH_32, X86_R8, X86_ALU_SHL);
x86_l_2de:
	/* 0x2de: or     r14d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_2e1:
	/* 0x2e1: or     BYTE PTR [rbx+0x86],0x1 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RBX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 575525617665ULL);
x86_l_2e8:
	/* 0x2e8: jmp    2f0 <cil_from_host+0x2f0> */
	X86_SIM_X86_JMP(0x2e8, 0x2f0, x86_l_2f0);
x86_l_2ea:
	/* 0x2ea: mov    r14d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 1ULL);
x86_l_2f0:
	/* 0x2f0: mov    DWORD PTR [rbx+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_2fa:
	/* 0x2fa: and    r13d,0xe00 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 3584ULL);
x86_l_301:
	/* 0x301: mov    rcx,QWORD PTR [rip+0xb70] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_308:
	/* 0x308: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_30a:
	/* 0x30a: movzx  eax,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_30d:
	/* 0x30d: cmp    eax,0x608 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1544ULL);
x86_l_312:
	/* 0x312: je     3b6 <cil_from_host+0x3b6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x312, 0x3b6, x86_l_3b6);
x86_l_318:
	/* 0x318: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_31b:
	/* 0x31b: jne    44b <cil_from_host+0x44b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x31b, 0x44b, x86_l_44b);
x86_l_321:
	/* 0x321: movzx  r12d,BYTE PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_326:
	/* 0x326: lea    ebp,[r12+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_32b:
	/* 0x32b: mov    eax,0x27 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 39ULL);
x86_l_330:
	/* 0x330: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_333:
	/* 0x333: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_335:
	/* 0x335: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_337:
	/* 0x337: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_33a:
	/* 0x33a: sub    eax,DWORD PTR [rbx+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_33d:
	/* 0x33d: cmp    ebp,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_33f:
	/* 0x33f: ja     3d8 <cil_from_host+0x3d8> */
	X86_SIM_X86_JCC(X86_CC_A, 0x33f, 0x3d8, x86_l_3d8);
x86_l_345:
	/* 0x345: mov    rax,QWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_34c:
	/* 0x34c: cmp    r14d,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 3ULL);
x86_l_350:
	/* 0x350: jae    666 <cil_from_host+0x666> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x350, 0x666, x86_l_666);
x86_l_356:
	/* 0x356: mov    eax,DWORD PTR [rax+r12*1+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 12ULL);
x86_l_35b:
	/* 0x35b: mov    QWORD PTR [rsp+0xe],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60129542144ULL);
x86_l_364:
	/* 0x364: mov    WORD PTR [rsp+0x1e],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 128849018880ULL);
x86_l_36b:
	/* 0x36b: mov    QWORD PTR [rsp+0x16],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 94489280512ULL);
x86_l_374:
	/* 0x374: mov    DWORD PTR [rsp+0x8],0x40 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738432ULL);
x86_l_37c:
	/* 0x37c: mov    BYTE PTR [rsp+0xf],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 64424509441ULL);
x86_l_381:
	/* 0x381: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_385:
	/* 0x385: mov    WORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_38c:
	/* 0x38c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_391:
	/* 0x391: mov    rdi,QWORD PTR [rip+0xb70] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipcache_v2)));
x86_l_398:
	/* 0x398: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_39d:
	/* 0x39d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39f:
	/* 0x39f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3a2:
	/* 0x3a2: je     68a <cil_from_host+0x68a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3a2, 0x68a, x86_l_68a);
x86_l_3a8:
	/* 0x3a8: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3aa:
	/* 0x3aa: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3ad:
	/* 0x3ad: cmovne r14d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R14, X86_RAX, X86_WIDTH_32, X86_CC_NE);
x86_l_3b1:
	/* 0x3b1: jmp    68a <cil_from_host+0x68a> */
	X86_SIM_X86_JMP(0x3b1, 0x68a, x86_l_68a);
x86_l_3b6:
	/* 0x3b6: movzx  ebp,BYTE PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_3bb:
	/* 0x3bb: add    ebp,0x1c */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 28ULL);
x86_l_3be:
	/* 0x3be: mov    eax,0x27 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 39ULL);
x86_l_3c3:
	/* 0x3c3: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_3c6:
	/* 0x3c6: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_3c8:
	/* 0x3c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ca:
	/* 0x3ca: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3cd:
	/* 0x3cd: sub    eax,DWORD PTR [rbx+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_3d0:
	/* 0x3d0: cmp    ebp,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_3d2:
	/* 0x3d2: jbe    4c4 <cil_from_host+0x4c4> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x3d2, 0x4c4, x86_l_4c4);
x86_l_3d8:
	/* 0x3d8: mov    cl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_3da:
	/* 0x3da: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_3df:
	/* 0x3df: mov    edx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_32);
x86_l_3e1:
	/* 0x3e1: neg    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_3e3:
	/* 0x3e3: cmovs  edx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RAX, X86_WIDTH_32, X86_CC_S);
x86_l_3e6:
	/* 0x3e6: mov    DWORD PTR [rbx+0x28],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3ea:
	/* 0x3ea: mov    DWORD PTR [rbx+0x2c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561024ULL);
x86_l_3f1:
	/* 0x3f1: movzx  eax,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_3f4:
	/* 0x3f4: mov    DWORD PTR [rbx+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3f7:
	/* 0x3f7: movabs rdx,0x48d010200000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 327919455969476608ULL);
x86_l_401:
	/* 0x401: mov    QWORD PTR [rbx+0x34],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_405:
	/* 0x405: mov    r14d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_409:
	/* 0x409: movabs rdx,0x1045c0103 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 4368105731ULL);
x86_l_413:
	/* 0x413: add    rdx,0x30fefd */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 3211005ULL);
x86_l_41a:
	/* 0x41a: mov    QWORD PTR [rsp],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_41e:
	/* 0x41e: mov    BYTE PTR [rsp],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_421:
	/* 0x421: mov    BYTE PTR [rsp+0x1],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_425:
	/* 0x425: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_42a:
	/* 0x42a: mov    rdi,QWORD PTR [rip+0xb70] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_431:
	/* 0x431: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_434:
	/* 0x434: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_436:
	/* 0x436: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_439:
	/* 0x439: je     620 <cil_from_host+0x620> */
	X86_SIM_X86_JCC(X86_CC_E, 0x439, 0x620, x86_l_620);
x86_l_43f:
	/* 0x43f: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_442:
	/* 0x442: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_446:
	/* 0x446: jmp    646 <cil_from_host+0x646> */
	X86_SIM_X86_JMP(0x446, 0x646, x86_l_646);
x86_l_44b:
	/* 0x44b: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_44f:
	/* 0x44f: je     46c <cil_from_host+0x46c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x44f, 0x46c, x86_l_46c);
x86_l_451:
	/* 0x451: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_459:
	/* 0x459: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_45e:
	/* 0x45e: mov    rdi,QWORD PTR [rip+0xb70] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_percpu_trace_id)));
x86_l_465:
	/* 0x465: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_46a:
	/* 0x46a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_46c:
	/* 0x46c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_46e:
	/* 0x46e: cmp    r13d,0xa00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 2560ULL);
x86_l_475:
	/* 0x475: je     9fb <cil_from_host+0x9fb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x475, 0x9fb, x86_l_9fb);
x86_l_47b:
	/* 0x47b: mov    ebx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_47e:
	/* 0x47e: movabs rax,0x1045c0103 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 4368105731ULL);
x86_l_488:
	/* 0x488: or     rax,0x220000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_OR, 2228224ULL);
x86_l_48e:
	/* 0x48e: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_492:
	/* 0x492: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_497:
	/* 0x497: mov    rdi,QWORD PTR [rip+0xb70] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_49e:
	/* 0x49e: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_4a1:
	/* 0x4a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a3:
	/* 0x4a3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4a6:
	/* 0x4a6: jne    14c <cil_from_host+0x14c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4a6, 0x14c, x86_l_14c);
x86_l_4ac:
	/* 0x4ac: mov    QWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_4b5:
	/* 0x4b5: mov    QWORD PTR [rsp+0x10],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4ba:
	/* 0x4ba: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_4bf:
	/* 0x4bf: jmp    26c <cil_from_host+0x26c> */
	X86_SIM_X86_JMP(0x4bf, 0x26c, x86_l_26c);
x86_l_4c4:
	/* 0x4c4: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4c8:
	/* 0x4c8: je     4e5 <cil_from_host+0x4e5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4c8, 0x4e5, x86_l_4e5);
x86_l_4ca:
	/* 0x4ca: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_4d2:
	/* 0x4d2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4d7:
	/* 0x4d7: mov    rdi,QWORD PTR [rip+0xb70] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_percpu_trace_id)));
x86_l_4de:
	/* 0x4de: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e3:
	/* 0x4e3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e5:
	/* 0x4e5: cmp    r13d,0xa00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 2560ULL);
x86_l_4ec:
	/* 0x4ec: je     539 <cil_from_host+0x539> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4ec, 0x539, x86_l_539);
x86_l_4ee:
	/* 0x4ee: mov    r15d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_4f2:
	/* 0x4f2: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4fb:
	/* 0x4fb: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_504:
	/* 0x504: movabs rax,0x1045c0103 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 4368105731ULL);
x86_l_50e:
	/* 0x50e: add    rax,0x140000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1310720ULL);
x86_l_514:
	/* 0x514: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_518:
	/* 0x518: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_51d:
	/* 0x51d: mov    rdi,QWORD PTR [rip+0xb70] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_524:
	/* 0x524: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_527:
	/* 0x527: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_529:
	/* 0x529: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_52c:
	/* 0x52c: je     7b6 <cil_from_host+0x7b6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x52c, 0x7b6, x86_l_7b6);
x86_l_532:
	/* 0x532: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_535:
	/* 0x535: add    QWORD PTR [rax+0x8],r15 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_539:
	/* 0x539: mov    rax,QWORD PTR [rip+0xb70] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_l2_announcements)));
x86_l_540:
	/* 0x540: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_543:
	/* 0x543: je     7ec <cil_from_host+0x7ec> */
	X86_SIM_X86_JCC(X86_CC_E, 0x543, 0x7ec, x86_l_7ec);
x86_l_549:
	/* 0x549: mov    rax,QWORD PTR [rip+0xb70] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_interface_mac)));
x86_l_550:
	/* 0x550: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_553:
	/* 0x553: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_558:
	/* 0x558: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_55a:
	/* 0x55a: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_55f:
	/* 0x55f: je     9e8 <cil_from_host+0x9e8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x55f, 0x9e8, x86_l_9e8);
x86_l_565:
	/* 0x565: mov    DWORD PTR [rsp+0x24],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 154618822657ULL);
x86_l_56d:
	/* 0x56d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_572:
	/* 0x572: mov    rdi,QWORD PTR [rip+0xb70] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_runtime_config)));
x86_l_579:
	/* 0x579: lea    rsi,[rsp+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_57e:
	/* 0x57e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_580:
	/* 0x580: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_583:
	/* 0x583: je     5b2 <cil_from_host+0x5b2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x583, 0x5b2, x86_l_5b2);
x86_l_585:
	/* 0x585: mov    r15,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_588:
	/* 0x588: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_58b:
	/* 0x58b: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_590:
	/* 0x590: je     9e8 <cil_from_host+0x9e8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x590, 0x9e8, x86_l_9e8);
x86_l_596:
	/* 0x596: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_59b:
	/* 0x59b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_59d:
	/* 0x59d: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_59f:
	/* 0x59f: sub    rax,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_64, X86_ALU_SUB);
x86_l_5a2:
	/* 0x5a2: mov    rcx,QWORD PTR [rip+0xb70] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_l2_announcements_max_liveness)));
x86_l_5a9:
	/* 0x5a9: cmp    rax,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_5ac:
	/* 0x5ac: jbe    7f3 <cil_from_host+0x7f3> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x5ac, 0x7f3, x86_l_7f3);
x86_l_5b2:
	/* 0x5b2: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5b4:
	/* 0x5b4: jmp    9e8 <cil_from_host+0x9e8> */
	X86_SIM_X86_JMP(0x5b4, 0x9e8, x86_l_9e8);
x86_l_5b9:
	/* 0x5b9: add    rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5bc:
	/* 0x5bc: movzx  r12d,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_5c0:
	/* 0x5c0: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_5c3:
	/* 0x5c3: and    cl,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 14ULL);
x86_l_5c6:
	/* 0x5c6: cmp    cl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 6ULL);
x86_l_5c9:
	/* 0x5c9: jb     b4d <cil_from_host+0xb4d> */
	X86_SIM_X86_JCC(X86_CC_B, 0x5c9, 0xb4d, x86_l_b4d);
x86_l_5cf:
	/* 0x5cf: movzx  r13d,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_5d3:
	/* 0x5d3: shl    r12d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHL, 2ULL);
x86_l_5d7:
	/* 0x5d7: and    r12d,0x3c */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 60ULL);
x86_l_5db:
	/* 0x5db: je     b4d <cil_from_host+0xb4d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5db, 0xb4d, x86_l_b4d);
x86_l_5e1:
	/* 0x5e1: lea    r14d,[r13+0x14] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_5e5:
	/* 0x5e5: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_5ea:
	/* 0x5ea: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_5ed:
	/* 0x5ed: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_5f0:
	/* 0x5f0: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_5f3:
	/* 0x5f3: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_5f8:
	/* 0x5f8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5fa:
	/* 0x5fa: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5fc:
	/* 0x5fc: js     9f <cil_from_host+0x9f> */
	X86_SIM_X86_JCC(X86_CC_S, 0x5fc, 0x9f, x86_l_9f);
x86_l_602:
	/* 0x602: movzx  eax,BYTE PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_606:
	/* 0x606: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_608:
	/* 0x608: je     b4d <cil_from_host+0xb4d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x608, 0xb4d, x86_l_b4d);
x86_l_60e:
	/* 0x60e: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_611:
	/* 0x611: jne    a0e <cil_from_host+0xa0e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x611, 0xa0e, x86_l_a0e);
x86_l_617:
	/* 0x617: lea    r14d,[r13+0x15] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 21ULL);
x86_l_61b:
	/* 0x61b: jmp    a8b <cil_from_host+0xa8b> */
	X86_SIM_X86_JMP(0x61b, 0xa8b, x86_l_a8b);
x86_l_620:
	/* 0x620: mov    QWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_629:
	/* 0x629: mov    QWORD PTR [rsp+0x10],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_62e:
	/* 0x62e: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_633:
	/* 0x633: mov    rdi,QWORD PTR [rip+0xb70] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_63a:
	/* 0x63a: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_63d:
	/* 0x63d: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_642:
	/* 0x642: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_644:
	/* 0x644: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_646:
	/* 0x646: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_64b:
	/* 0x64b: mov    rsi,QWORD PTR [rip+0xb70] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_652:
	/* 0x652: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_655:
	/* 0x655: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_65a:
	/* 0x65a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_65c:
	/* 0x65c: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_661:
	/* 0x661: jmp    9fb <cil_from_host+0x9fb> */
	X86_SIM_X86_JMP(0x661, 0x9fb, x86_l_9fb);
x86_l_666:
	/* 0x666: mov    ecx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_32);
x86_l_669:
	/* 0x669: and    ecx,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_66c:
	/* 0x66c: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_66f:
	/* 0x66f: je     356 <cil_from_host+0x356> */
	X86_SIM_X86_JCC(X86_CC_E, 0x66f, 0x356, x86_l_356);
x86_l_675:
	/* 0x675: mov    ecx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_32);
x86_l_678:
	/* 0x678: and    ecx,0xff000000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4278190080ULL);
x86_l_67e:
	/* 0x67e: cmp    ecx,0x2000000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 33554432ULL);
x86_l_684:
	/* 0x684: je     356 <cil_from_host+0x356> */
	X86_SIM_X86_JCC(X86_CC_E, 0x684, 0x356, x86_l_356);
x86_l_68a:
	/* 0x68a: mov    DWORD PTR [rbx+0x28],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_68e:
	/* 0x68e: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_692:
	/* 0x692: je     6af <cil_from_host+0x6af> */
	X86_SIM_X86_JCC(X86_CC_E, 0x692, 0x6af, x86_l_6af);
x86_l_694:
	/* 0x694: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_69c:
	/* 0x69c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6a1:
	/* 0x6a1: mov    rdi,QWORD PTR [rip+0xb70] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_percpu_trace_id)));
x86_l_6a8:
	/* 0x6a8: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6ad:
	/* 0x6ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6af:
	/* 0x6af: movabs r15,0x1045c0103 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_64, 4368105731ULL);
x86_l_6b9:
	/* 0x6b9: cmp    r13d,0xa00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 2560ULL);
x86_l_6c0:
	/* 0x6c0: je     70f <cil_from_host+0x70f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6c0, 0x70f, x86_l_70f);
x86_l_6c2:
	/* 0x6c2: mov    r12d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_6c6:
	/* 0x6c6: mov    QWORD PTR [rsp],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6ca:
	/* 0x6ca: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6cf:
	/* 0x6cf: mov    rdi,QWORD PTR [rip+0xb70] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_6d6:
	/* 0x6d6: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_6d9:
	/* 0x6d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6db:
	/* 0x6db: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6de:
	/* 0x6de: je     6e9 <cil_from_host+0x6e9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6de, 0x6e9, x86_l_6e9);
x86_l_6e0:
	/* 0x6e0: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_6e3:
	/* 0x6e3: add    QWORD PTR [rax+0x8],r12 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_6e7:
	/* 0x6e7: jmp    70f <cil_from_host+0x70f> */
	X86_SIM_X86_JMP(0x6e7, 0x70f, x86_l_70f);
x86_l_6e9:
	/* 0x6e9: mov    QWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_6f2:
	/* 0x6f2: mov    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_6f7:
	/* 0x6f7: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_6fc:
	/* 0x6fc: mov    rdi,QWORD PTR [rip+0xb70] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_703:
	/* 0x703: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_706:
	/* 0x706: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_70b:
	/* 0x70b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_70d:
	/* 0x70d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_70f:
	/* 0x70f: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_714:
	/* 0x714: mov    rsi,QWORD PTR [rip+0xb70] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_71b:
	/* 0x71b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_71e:
	/* 0x71e: mov    edx,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 23ULL);
x86_l_723:
	/* 0x723: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_725:
	/* 0x725: mov    DWORD PTR [rbx+0x28],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_729:
	/* 0x729: movabs rax,0x178c00000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 25890062860288ULL);
x86_l_733:
	/* 0x733: mov    QWORD PTR [rbx+0x2c],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_737:
	/* 0x737: movabs rax,0x468010000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 317504873241247744ULL);
x86_l_741:
	/* 0x741: mov    QWORD PTR [rbx+0x34],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_745:
	/* 0x745: mov    r14d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_749:
	/* 0x749: add    r15,0xc0089 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 786569ULL);
x86_l_750:
	/* 0x750: mov    QWORD PTR [rsp],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_754:
	/* 0x754: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_759:
	/* 0x759: mov    rdi,QWORD PTR [rip+0xb70] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_760:
	/* 0x760: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_763:
	/* 0x763: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_765:
	/* 0x765: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_768:
	/* 0x768: je     773 <cil_from_host+0x773> */
	X86_SIM_X86_JCC(X86_CC_E, 0x768, 0x773, x86_l_773);
x86_l_76a:
	/* 0x76a: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_76d:
	/* 0x76d: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_771:
	/* 0x771: jmp    799 <cil_from_host+0x799> */
	X86_SIM_X86_JMP(0x771, 0x799, x86_l_799);
x86_l_773:
	/* 0x773: mov    QWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_77c:
	/* 0x77c: mov    QWORD PTR [rsp+0x10],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_781:
	/* 0x781: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_786:
	/* 0x786: mov    rdi,QWORD PTR [rip+0xb70] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_78d:
	/* 0x78d: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_790:
	/* 0x790: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_795:
	/* 0x795: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_797:
	/* 0x797: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_799:
	/* 0x799: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_79e:
	/* 0x79e: mov    rsi,QWORD PTR [rip+0xb70] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_7a5:
	/* 0x7a5: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_7a8:
	/* 0x7a8: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_7ad:
	/* 0x7ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7af:
	/* 0x7af: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7b1:
	/* 0x7b1: jmp    9fb <cil_from_host+0x9fb> */
	X86_SIM_X86_JMP(0x7b1, 0x9fb, x86_l_9fb);
x86_l_7b6:
	/* 0x7b6: mov    QWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_7bf:
	/* 0x7bf: mov    QWORD PTR [rsp+0x10],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7c4:
	/* 0x7c4: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_7c9:
	/* 0x7c9: mov    rdi,QWORD PTR [rip+0xb70] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_7d0:
	/* 0x7d0: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_7d3:
	/* 0x7d3: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7d8:
	/* 0x7d8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7da:
	/* 0x7da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7dc:
	/* 0x7dc: mov    rax,QWORD PTR [rip+0xb70] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_l2_announcements)));
x86_l_7e3:
	/* 0x7e3: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7e6:
	/* 0x7e6: jne    549 <cil_from_host+0x549> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x7e6, 0x549, x86_l_549);
x86_l_7ec:
	/* 0x7ec: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7ee:
	/* 0x7ee: jmp    9fb <cil_from_host+0x9fb> */
	X86_SIM_X86_JMP(0x7ee, 0x9fb, x86_l_9fb);
x86_l_7f3:
	/* 0x7f3: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_7f6:
	/* 0x7f6: sub    eax,DWORD PTR [rbx+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_7f9:
	/* 0x7f9: mov    rcx,QWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_800:
	/* 0x800: add    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_803:
	/* 0x803: movzx  edx,BYTE PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_808:
	/* 0x808: movzx  esi,BYTE PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_80d:
	/* 0x80d: add    rsi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_810:
	/* 0x810: add    rsi,0x1c */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 28ULL);
x86_l_814:
	/* 0x814: cmp    rsi,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_817:
	/* 0x817: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_81c:
	/* 0x81c: ja     9e8 <cil_from_host+0x9e8> */
	X86_SIM_X86_JCC(X86_CC_A, 0x81c, 0x9e8, x86_l_9e8);
x86_l_822:
	/* 0x822: movzx  esi,WORD PTR [rcx+rdx*1+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RDX, 0, X86_WIDTH_16), 6ULL);
x86_l_827:
	/* 0x827: cmp    esi,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 256ULL);
x86_l_82d:
	/* 0x82d: jne    9e8 <cil_from_host+0x9e8> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x82d, 0x9e8, x86_l_9e8);
x86_l_833:
	/* 0x833: movzx  edx,WORD PTR [rcx+rdx*1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RDX, 0, X86_WIDTH_16), 0ULL);
x86_l_837:
	/* 0x837: cmp    edx,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 256ULL);
x86_l_83d:
	/* 0x83d: jne    9e8 <cil_from_host+0x9e8> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x83d, 0x9e8, x86_l_9e8);
x86_l_843:
	/* 0x843: mov    edx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_845:
	/* 0x845: mov    edi,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RDX, X86_WIDTH_32);
x86_l_847:
	/* 0x847: not    edi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_849:
	/* 0x849: movzx  esi,WORD PTR [rcx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_84d:
	/* 0x84d: mov    r8d,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RSI, X86_WIDTH_32);
x86_l_850:
	/* 0x850: xor    r8d,0xffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_XOR, 65535ULL);
x86_l_857:
	/* 0x857: or     r8d,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDI, X86_WIDTH_32, X86_ALU_OR);
x86_l_85a:
	/* 0x85a: je     870 <cil_from_host+0x870> */
	X86_SIM_X86_JCC(X86_CC_E, 0x85a, 0x870, x86_l_870);
x86_l_85c:
	/* 0x85c: xor    edx,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 8ULL);
x86_l_860:
	/* 0x860: xor    si,WORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RSI, X86_RSP, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 12ULL);
x86_l_865:
	/* 0x865: movzx  esi,si */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_868:
	/* 0x868: or     esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_86a:
	/* 0x86a: jne    9e8 <cil_from_host+0x9e8> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x86a, 0x9e8, x86_l_9e8);
x86_l_870:
	/* 0x870: movzx  eax,BYTE PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_875:
	/* 0x875: mov    rdx,QWORD PTR [rcx+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_879:
	/* 0x879: mov    QWORD PTR [rsp],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_87d:
	/* 0x87d: mov    ebp,DWORD PTR [rcx+rax*1+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 14ULL);
x86_l_881:
	/* 0x881: mov    r12d,DWORD PTR [rcx+rax*1+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 24ULL);
x86_l_886:
	/* 0x886: mov    DWORD PTR [rsp+0x24],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_88b:
	/* 0x88b: mov    eax,DWORD PTR [rbx+0x94] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_891:
	/* 0x891: mov    DWORD PTR [rsp+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_895:
	/* 0x895: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_89a:
	/* 0x89a: mov    rdi,QWORD PTR [rip+0xb70] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_l2_responder_v4)));
x86_l_8a1:
	/* 0x8a1: lea    rsi,[rsp+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_8a6:
	/* 0x8a6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8a8:
	/* 0x8a8: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_8ab:
	/* 0x8ab: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8ad:
	/* 0x8ad: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_8b0:
	/* 0x8b0: je     9e8 <cil_from_host+0x9e8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8b0, 0x9e8, x86_l_9e8);
x86_l_8b6:
	/* 0x8b6: mov    r15,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RCX, X86_WIDTH_64);
x86_l_8b9:
	/* 0x8b9: mov    DWORD PTR [rsp+0x34],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_8be:
	/* 0x8be: mov    DWORD PTR [rsp+0x30],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_8c2:
	/* 0x8c2: mov    WORD PTR [rsp+0x2e],0x200 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 197568496128ULL);
x86_l_8c9:
	/* 0x8c9: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_8ce:
	/* 0x8ce: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8d3:
	/* 0x8d3: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_8d6:
	/* 0x8d6: mov    esi,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 6ULL);
x86_l_8db:
	/* 0x8db: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_8e0:
	/* 0x8e0: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8e3:
	/* 0x8e3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8e5:
	/* 0x8e5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_8e7:
	/* 0x8e7: js     b7c <cil_from_host+0xb7c> */
	X86_SIM_X86_JCC(X86_CC_S, 0x8e7, 0xb7c, x86_l_b7c);
x86_l_8ed:
	/* 0x8ed: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_8f2:
	/* 0x8f2: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_8f5:
	/* 0x8f5: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_8f8:
	/* 0x8f8: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8fa:
	/* 0x8fa: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_8ff:
	/* 0x8ff: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_902:
	/* 0x902: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_904:
	/* 0x904: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_906:
	/* 0x906: js     b7c <cil_from_host+0xb7c> */
	X86_SIM_X86_JCC(X86_CC_S, 0x906, 0xb7c, x86_l_b7c);
x86_l_90c:
	/* 0x90c: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_911:
	/* 0x911: lea    rdx,[rsp+0x2e] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 46ULL);
x86_l_916:
	/* 0x916: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_919:
	/* 0x919: mov    esi,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 20ULL);
x86_l_91e:
	/* 0x91e: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_923:
	/* 0x923: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_926:
	/* 0x926: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_928:
	/* 0x928: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_92a:
	/* 0x92a: js     b7c <cil_from_host+0xb7c> */
	X86_SIM_X86_JCC(X86_CC_S, 0x92a, 0xb7c, x86_l_b7c);
x86_l_930:
	/* 0x930: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_935:
	/* 0x935: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_93a:
	/* 0x93a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_93d:
	/* 0x93d: mov    esi,0x16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 22ULL);
x86_l_942:
	/* 0x942: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_947:
	/* 0x947: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_94a:
	/* 0x94a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_94c:
	/* 0x94c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_94e:
	/* 0x94e: js     b7c <cil_from_host+0xb7c> */
	X86_SIM_X86_JCC(X86_CC_S, 0x94e, 0xb7c, x86_l_b7c);
x86_l_954:
	/* 0x954: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_959:
	/* 0x959: lea    rdx,[rsp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_95e:
	/* 0x95e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_961:
	/* 0x961: mov    esi,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 28ULL);
x86_l_966:
	/* 0x966: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_96b:
	/* 0x96b: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_96e:
	/* 0x96e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_970:
	/* 0x970: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_972:
	/* 0x972: js     b7c <cil_from_host+0xb7c> */
	X86_SIM_X86_JCC(X86_CC_S, 0x972, 0xb7c, x86_l_b7c);
x86_l_978:
	/* 0x978: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_97d:
	/* 0x97d: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_980:
	/* 0x980: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_983:
	/* 0x983: mov    esi,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 32ULL);
x86_l_988:
	/* 0x988: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_98d:
	/* 0x98d: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_990:
	/* 0x990: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_992:
	/* 0x992: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_994:
	/* 0x994: js     b7c <cil_from_host+0xb7c> */
	X86_SIM_X86_JCC(X86_CC_S, 0x994, 0xb7c, x86_l_b7c);
x86_l_99a:
	/* 0x99a: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_99f:
	/* 0x99f: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9a4:
	/* 0x9a4: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9a6:
	/* 0x9a6: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_9a9:
	/* 0x9a9: mov    esi,0x26 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 38ULL);
x86_l_9ae:
	/* 0x9ae: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_9b3:
	/* 0x9b3: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9b6:
	/* 0x9b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9b8:
	/* 0x9b8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_9ba:
	/* 0x9ba: js     b7c <cil_from_host+0xb7c> */
	X86_SIM_X86_JCC(X86_CC_S, 0x9ba, 0xb7c, x86_l_b7c);
x86_l_9c0:
	/* 0x9c0: mov    rax,QWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9c4:
	/* 0x9c4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9c7:
	/* 0x9c7: je     9cf <cil_from_host+0x9cf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9c7, 0x9cf, x86_l_9cf);
x86_l_9c9:
	/* 0x9c9: mov    ebp,DWORD PTR [rax+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_9cf:
	/* 0x9cf: mov    eax,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 23ULL);
x86_l_9d4:
	/* 0x9d4: mov    edi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_32);
x86_l_9d6:
	/* 0x9d6: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9d8:
	/* 0x9d8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9da:
	/* 0x9da: cmp    eax,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_9dd:
	/* 0x9dd: jne    9e8 <cil_from_host+0x9e8> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x9dd, 0x9e8, x86_l_9e8);
x86_l_9df:
	/* 0x9df: inc QWORD PTR [r15] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_9e3:
	/* 0x9e3: mov    eax,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 7ULL);
x86_l_9e8:
	/* 0x9e8: mov    cl,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_9ea:
	/* 0x9ea: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_9ec:
	/* 0x9ec: js     3df <cil_from_host+0x3df> */
	X86_SIM_X86_JCC(X86_CC_S, 0x9ec, 0x3df, x86_l_3df);
x86_l_9f2:
	/* 0x9f2: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_9f5:
	/* 0x9f5: je     3df <cil_from_host+0x3df> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9f5, 0x3df, x86_l_3df);
x86_l_9fb:
	/* 0x9fb: add    rsp,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 56ULL);
x86_l_9ff:
	/* 0x9ff: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_a00:
	/* 0xa00: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_a02:
	/* 0xa02: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_a04:
	/* 0xa04: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_a06:
	/* 0xa06: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_a08:
	/* 0xa08: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_a09:
	/* 0xa09: jmp    bec <cil_from_host+0xbec> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_a0e:
	/* 0xa0e: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_a13:
	/* 0xa13: lea    esi,[r13+0x15] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 21ULL);
x86_l_a17:
	/* 0xa17: lea    rdx,[rsp+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_a1c:
	/* 0xa1c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_a1f:
	/* 0xa1f: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_a24:
	/* 0xa24: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a26:
	/* 0xa26: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a28:
	/* 0xa28: js     9f <cil_from_host+0x9f> */
	X86_SIM_X86_JCC(X86_CC_S, 0xa28, 0x9f, x86_l_9f);
x86_l_a2e:
	/* 0xa2e: cmp    BYTE PTR [rsp],bpl */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a32:
	/* 0xa32: jne    a83 <cil_from_host+0xa83> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa32, 0xa83, x86_l_a83);
x86_l_a34:
	/* 0xa34: movzx  eax,BYTE PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 36ULL);
x86_l_a39:
	/* 0xa39: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_a3c:
	/* 0xa3c: je     bb4 <cil_from_host+0xbb4> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa3c, 0xbb4, x86_l_bb4);
x86_l_a42:
	/* 0xa42: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_a45:
	/* 0xa45: je     b88 <cil_from_host+0xb88> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa45, 0xb88, x86_l_b88);
x86_l_a4b:
	/* 0xa4b: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_a4e:
	/* 0xa4e: jne    9f <cil_from_host+0x9f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa4e, 0x9f, x86_l_9f);
x86_l_a54:
	/* 0xa54: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_a59:
	/* 0xa59: add    r14d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_a5d:
	/* 0xa5d: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a62:
	/* 0xa62: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_a65:
	/* 0xa65: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_a68:
	/* 0xa68: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_a6d:
	/* 0xa6d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a6f:
	/* 0xa6f: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a72:
	/* 0xa72: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a74:
	/* 0xa74: movbe  cx,WORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOVBE_LOAD, X86_RCX, X86_RSP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_a7b:
	/* 0xa7b: movzx  ecx,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_a7e:
	/* 0xa7e: jmp    bdb <cil_from_host+0xbdb> */
	X86_SIM_X86_JMP(0xa7e, 0xbdb, x86_l_bdb);
x86_l_a83:
	/* 0xa83: movzx  eax,BYTE PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 36ULL);
x86_l_a88:
	/* 0xa88: add    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_a8b:
	/* 0xa8b: add    r12d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R13, X86_WIDTH_32, X86_ALU_ADD);
x86_l_a8e:
	/* 0xa8e: add    r12d,0x14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_ADD, 20ULL);
x86_l_a92:
	/* 0xa92: cmp    r14d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R14, X86_R12, X86_WIDTH_32);
x86_l_a95:
	/* 0xa95: jae    b4d <cil_from_host+0xb4d> */
	X86_SIM_X86_JCC(X86_CC_AE, 0xa95, 0xb4d, x86_l_b4d);
x86_l_a9b:
	/* 0xa9b: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_aa0:
	/* 0xaa0: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_aa3:
	/* 0xaa3: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_aa6:
	/* 0xaa6: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_aa9:
	/* 0xaa9: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_aae:
	/* 0xaae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ab0:
	/* 0xab0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ab2:
	/* 0xab2: js     9f <cil_from_host+0x9f> */
	X86_SIM_X86_JCC(X86_CC_S, 0xab2, 0x9f, x86_l_9f);
x86_l_ab8:
	/* 0xab8: movzx  eax,BYTE PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_abc:
	/* 0xabc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_abe:
	/* 0xabe: je     b4d <cil_from_host+0xb4d> */
	X86_SIM_X86_JCC(X86_CC_E, 0xabe, 0xb4d, x86_l_b4d);
x86_l_ac4:
	/* 0xac4: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ac7:
	/* 0xac7: je     af8 <cil_from_host+0xaf8> */
	X86_SIM_X86_JCC(X86_CC_E, 0xac7, 0xaf8, x86_l_af8);
x86_l_ac9:
	/* 0xac9: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_ace:
	/* 0xace: lea    esi,[r14+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_ad2:
	/* 0xad2: lea    rdx,[rsp+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_ad7:
	/* 0xad7: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_ada:
	/* 0xada: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_adf:
	/* 0xadf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ae1:
	/* 0xae1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ae3:
	/* 0xae3: js     9f <cil_from_host+0x9f> */
	X86_SIM_X86_JCC(X86_CC_S, 0xae3, 0x9f, x86_l_9f);
x86_l_ae9:
	/* 0xae9: cmp    BYTE PTR [rsp],bpl */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_aed:
	/* 0xaed: je     a34 <cil_from_host+0xa34> */
	X86_SIM_X86_JCC(X86_CC_E, 0xaed, 0xa34, x86_l_a34);
x86_l_af3:
	/* 0xaf3: movzx  eax,BYTE PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 36ULL);
x86_l_af8:
	/* 0xaf8: add    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_afb:
	/* 0xafb: cmp    r14d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R14, X86_R12, X86_WIDTH_32);
x86_l_afe:
	/* 0xafe: jae    b4d <cil_from_host+0xb4d> */
	X86_SIM_X86_JCC(X86_CC_AE, 0xafe, 0xb4d, x86_l_b4d);
x86_l_b00:
	/* 0xb00: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_b05:
	/* 0xb05: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_b08:
	/* 0xb08: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_b0b:
	/* 0xb0b: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_b0e:
	/* 0xb0e: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_b13:
	/* 0xb13: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b15:
	/* 0xb15: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b17:
	/* 0xb17: js     9f <cil_from_host+0x9f> */
	X86_SIM_X86_JCC(X86_CC_S, 0xb17, 0x9f, x86_l_9f);
x86_l_b1d:
	/* 0xb1d: cmp    BYTE PTR [rsp],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_b21:
	/* 0xb21: jb     b4d <cil_from_host+0xb4d> */
	X86_SIM_X86_JCC(X86_CC_B, 0xb21, 0xb4d, x86_l_b4d);
x86_l_b23:
	/* 0xb23: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_b28:
	/* 0xb28: lea    esi,[r14+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_b2c:
	/* 0xb2c: lea    rdx,[rsp+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_b31:
	/* 0xb31: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_b34:
	/* 0xb34: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_b39:
	/* 0xb39: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b3b:
	/* 0xb3b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b3d:
	/* 0xb3d: js     9f <cil_from_host+0x9f> */
	X86_SIM_X86_JCC(X86_CC_S, 0xb3d, 0x9f, x86_l_9f);
x86_l_b43:
	/* 0xb43: cmp    BYTE PTR [rsp],bpl */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b47:
	/* 0xb47: je     a34 <cil_from_host+0xa34> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb47, 0xa34, x86_l_a34);
x86_l_b4d:
	/* 0xb4d: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b50:
	/* 0xb50: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_b58:
	/* 0xb58: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b5d:
	/* 0xb5d: mov    rdi,QWORD PTR [rip+0xb6c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_percpu_trace_id)));
x86_l_b64:
	/* 0xb64: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b69:
	/* 0xb69: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b6b:
	/* 0xb6b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b6e:
	/* 0xb6e: je     c6 <cil_from_host+0xc6> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb6e, 0xc6, x86_l_c6);
x86_l_b74:
	/* 0xb74: mov    QWORD PTR [rax],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b77:
	/* 0xb77: jmp    c6 <cil_from_host+0xc6> */
	X86_SIM_X86_JMP(0xb77, 0xc6, x86_l_c6);
x86_l_b7c:
	/* 0xb7c: mov    cl,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_b7e:
	/* 0xb7e: mov    eax,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967155ULL);
x86_l_b83:
	/* 0xb83: jmp    3df <cil_from_host+0x3df> */
	X86_SIM_X86_JMP(0xb83, 0x3df, x86_l_3df);
x86_l_b88:
	/* 0xb88: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_b8d:
	/* 0xb8d: add    r14d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_b91:
	/* 0xb91: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b96:
	/* 0xb96: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_b99:
	/* 0xb99: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_b9c:
	/* 0xb9c: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_ba1:
	/* 0xba1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ba3:
	/* 0xba3: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ba5:
	/* 0xba5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ba7:
	/* 0xba7: movbe  r14d,DWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOVBE_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 8ULL);
x86_l_bae:
	/* 0xbae: cmovs  r14d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R14, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_bb2:
	/* 0xbb2: jmp    bdf <cil_from_host+0xbdf> */
	X86_SIM_X86_JMP(0xbb2, 0xbdf, x86_l_bdf);
x86_l_bb4:
	/* 0xbb4: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_bb9:
	/* 0xbb9: add    r14d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_bbd:
	/* 0xbbd: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bc2:
	/* 0xbc2: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_bc5:
	/* 0xbc5: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_bc8:
	/* 0xbc8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_bcd:
	/* 0xbcd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bcf:
	/* 0xbcf: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bd2:
	/* 0xbd2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_bd4:
	/* 0xbd4: movbe  rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOVBE_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_bdb:
	/* 0xbdb: cmovns r14,rcx */
	X86_SIM_L_EXEC_CMOV(X86_R14, X86_RCX, X86_WIDTH_64, X86_CC_NS);
x86_l_bdf:
	/* 0xbdf: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_be1:
	/* 0xbe1: jns    b50 <cil_from_host+0xb50> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xbe1, 0xb50, x86_l_b50);
x86_l_be7:
	/* 0xbe7: jmp    9f <cil_from_host+0x9f> */
	X86_SIM_X86_JMP(0xbe7, 0x9f, x86_l_9f);
x86_l_bec:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
