extern char __config_enable_conntrack_accounting;
extern char __config_enable_ipv4_fragments;
extern char __config_enable_jiffies;
extern char __config_interface_ifindex;
extern char __config_kernel_hz;
extern char __config_nodeport_port_max;
extern char __config_trace_payload_len;
extern char cilium_calls;
extern char cilium_ct4_global;
extern char cilium_ct_any4_global;
extern char cilium_ipv4_frag_datagrams;
extern char cilium_metrics;
extern char cilium_signals;
extern char cilium_snat_v4_alloc_retries;
extern char cilium_snat_v4_external;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int cilium_bpf_overlay_tail_handle_snat_fwd_ipv4_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0xa: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: mov    r11d,DWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_11:
	/* 0x11: mov    QWORD PTR [rdi+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_19:
	/* 0x19: mov    r12,QWORD PTR [rip+0x59e7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&__config_nodeport_port_max)));
x86_l_20:
	/* 0x20: movzx  r10d,WORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_25:
	/* 0x25: mov    DWORD PTR [rsp+0x24],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 154618822656ULL);
x86_l_2d:
	/* 0x2d: mov    eax,DWORD PTR [rdi+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_30:
	/* 0x30: sub    eax,DWORD PTR [rdi+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RDI, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_33:
	/* 0x33: mov    r13d,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967162ULL);
x86_l_39:
	/* 0x39: cmp    eax,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 34ULL);
x86_l_3c:
	/* 0x3c: jae    ad <tail_handle_snat_fwd_ipv4+0xad> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x3c, 0xad, x86_l_ad);
x86_l_3e:
	/* 0x3e: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_41:
	/* 0x41: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_43:
	/* 0x43: neg    r13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_46:
	/* 0x46: movzx  ecx,r13b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R13, X86_WIDTH_32, X86_WIDTH_8);
x86_l_4a:
	/* 0x4a: movzx  edx,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_4e:
	/* 0x4e: shl    edx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_51:
	/* 0x51: or     edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_53:
	/* 0x53: mov    DWORD PTR [rbx+0x28],r11d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_57:
	/* 0x57: mov    DWORD PTR [rbx+0x2c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561024ULL);
x86_l_5e:
	/* 0x5e: mov    DWORD PTR [rbx+0x30],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_61:
	/* 0x61: movabs rdx,0x1bc710200000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 125099143063404544ULL);
x86_l_6b:
	/* 0x6b: mov    QWORD PTR [rbx+0x34],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_6f:
	/* 0x6f: mov    r14d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_32);
x86_l_72:
	/* 0x72: movabs rax,0x7101bc0200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 485360402944ULL);
x86_l_7c:
	/* 0x7c: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_81:
	/* 0x81: mov    BYTE PTR [rsp+0x70],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_85:
	/* 0x85: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_8a:
	/* 0x8a: mov    rdi,QWORD PTR [rip+0x59e7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_91:
	/* 0x91: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_96:
	/* 0x96: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_98:
	/* 0x98: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9b:
	/* 0x9b: je     24f <tail_handle_snat_fwd_ipv4+0x24f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9b, 0x24f, x86_l_24f);
x86_l_a1:
	/* 0xa1: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_a4:
	/* 0xa4: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_a8:
	/* 0xa8: jmp    277 <tail_handle_snat_fwd_ipv4+0x277> */
	X86_SIM_X86_JMP(0xa8, 0x277, x86_l_277);
x86_l_ad:
	/* 0xad: movabs rbp,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 2199023255552ULL);
x86_l_b7:
	/* 0xb7: movabs r14,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 1099511627776ULL);
x86_l_c1:
	/* 0xc1: mov    rdx,QWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_c8:
	/* 0xc8: movzx  eax,WORD PTR [rdx+0x12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18ULL);
x86_l_cc:
	/* 0xcc: movzx  ecx,BYTE PTR [rdx+0x17] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 23ULL);
x86_l_d0:
	/* 0xd0: mov    rsi,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RCX, X86_WIDTH_64);
x86_l_d3:
	/* 0xd3: shl    rsi,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_d7:
	/* 0xd7: or     rsi,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_da:
	/* 0xda: movzx  eax,WORD PTR [rdx+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 20ULL);
x86_l_de:
	/* 0xde: lea    rdi,[rsi+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_e2:
	/* 0xe2: test   eax,0xff3f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 65343ULL);
x86_l_e7:
	/* 0xe7: cmove  rdi,rsi */
	X86_SIM_L_EXEC_CMOV(X86_RDI, X86_RSI, X86_WIDTH_64, X86_CC_E);
x86_l_eb:
	/* 0xeb: lea    r9,[rdi+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_ef:
	/* 0xef: test   eax,0xff1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 65311ULL);
x86_l_f4:
	/* 0xf4: cmove  r9,rdi */
	X86_SIM_L_EXEC_CMOV(X86_R9, X86_RDI, X86_WIDTH_64, X86_CC_E);
x86_l_f8:
	/* 0xf8: mov    BYTE PTR [rsp+0x28],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_fc:
	/* 0xfc: mov    eax,DWORD PTR [rdx+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_ff:
	/* 0xff: mov    DWORD PTR [rsp+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_103:
	/* 0x103: mov    esi,DWORD PTR [rdx+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_106:
	/* 0x106: mov    DWORD PTR [rsp+0x20],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_10a:
	/* 0x10a: mov    BYTE PTR [rsp+0x29],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 176093659136ULL);
x86_l_10f:
	/* 0x10f: mov    edx,DWORD PTR [rdx+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_112:
	/* 0x112: cmp    rcx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 17ULL);
x86_l_116:
	/* 0x116: je     121 <tail_handle_snat_fwd_ipv4+0x121> */
	X86_SIM_X86_JCC(X86_CC_E, 0x116, 0x121, x86_l_121);
x86_l_118:
	/* 0x118: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_11b:
	/* 0x11b: jne    18bf <tail_handle_snat_fwd_ipv4+0x18bf> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x11b, 0x18bf, x86_l_18bf);
x86_l_121:
	/* 0x121: cmp    esi,0xfffff50a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 4294964490ULL);
x86_l_127:
	/* 0x127: jne    18bf <tail_handle_snat_fwd_ipv4+0x18bf> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x127, 0x18bf, x86_l_18bf);
x86_l_12d:
	/* 0x12d: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_130:
	/* 0x130: je     13b <tail_handle_snat_fwd_ipv4+0x13b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x130, 0x13b, x86_l_13b);
x86_l_132:
	/* 0x132: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_135:
	/* 0x135: jne    18bf <tail_handle_snat_fwd_ipv4+0x18bf> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x135, 0x18bf, x86_l_18bf);
x86_l_13b:
	/* 0x13b: mov    rcx,QWORD PTR [rip+0x59e7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_ipv4_fragments)));
x86_l_142:
	/* 0x142: mov    r15,r9 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R9, X86_WIDTH_64);
x86_l_145:
	/* 0x145: mov    r13d,0xffffff63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967139ULL);
x86_l_14b:
	/* 0x14b: and    r15,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_14e:
	/* 0x14e: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_151:
	/* 0x151: jne    15c <tail_handle_snat_fwd_ipv4+0x15c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x151, 0x15c, x86_l_15c);
x86_l_153:
	/* 0x153: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_156:
	/* 0x156: jne    3e <tail_handle_snat_fwd_ipv4+0x3e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x156, 0x3e, x86_l_3e);
x86_l_15c:
	/* 0x15c: and    edx,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_15f:
	/* 0x15f: lea    esi,[rdx*4+0xe] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 2), 14ULL);
x86_l_166:
	/* 0x166: lea    rdx,[rsp+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_16b:
	/* 0x16b: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16e:
	/* 0x16e: mov    DWORD PTR [rsp+0x18],r11d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_173:
	/* 0x173: mov    QWORD PTR [rsp+0x68],r10 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R10, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_178:
	/* 0x178: mov    QWORD PTR [rsp+0xb8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_180:
	/* 0x180: je     297 <tail_handle_snat_fwd_ipv4+0x297> */
	X86_SIM_X86_JCC(X86_CC_E, 0x180, 0x297, x86_l_297);
x86_l_186:
	/* 0x186: mov    DWORD PTR [rsp+0x70],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_18a:
	/* 0x18a: mov    DWORD PTR [rsp+0x74],0xfffff50a */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 502511170826ULL);
x86_l_192:
	/* 0x192: mov    WORD PTR [rsp+0x78],r9w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_198:
	/* 0x198: mov    rax,r9 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R9, X86_WIDTH_64);
x86_l_19b:
	/* 0x19b: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_19f:
	/* 0x19f: mov    BYTE PTR [rsp+0x7a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 122ULL);
x86_l_1a3:
	/* 0x1a3: mov    BYTE PTR [rsp+0x7b],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 528280977408ULL);
x86_l_1a8:
	/* 0x1a8: mov    r13,r9 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R9, X86_WIDTH_64);
x86_l_1ab:
	/* 0x1ab: test   r9,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R9, X86_RBP, X86_WIDTH_64);
x86_l_1ae:
	/* 0x1ae: jne    71d <tail_handle_snat_fwd_ipv4+0x71d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1ae, 0x71d, x86_l_71d);
x86_l_1b4:
	/* 0x1b4: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1b9:
	/* 0x1b9: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1bc:
	/* 0x1bc: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1c1:
	/* 0x1c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c3:
	/* 0x1c3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1c5:
	/* 0x1c5: js     33f <tail_handle_snat_fwd_ipv4+0x33f> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1c5, 0x33f, x86_l_33f);
x86_l_1cb:
	/* 0x1cb: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1ce:
	/* 0x1ce: test   r13,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R14, X86_WIDTH_64);
x86_l_1d1:
	/* 0x1d1: je     2c2 <tail_handle_snat_fwd_ipv4+0x2c2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1d1, 0x2c2, x86_l_2c2);
x86_l_1d7:
	/* 0x1d7: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1dc:
	/* 0x1dc: mov    rdi,QWORD PTR [rip+0x59e7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv4_frag_datagrams)));
x86_l_1e3:
	/* 0x1e3: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1e8:
	/* 0x1e8: lea    rdx,[rsp+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1ed:
	/* 0x1ed: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ef:
	/* 0x1ef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f1:
	/* 0x1f1: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1f4:
	/* 0x1f4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1f6:
	/* 0x1f6: je     2c2 <tail_handle_snat_fwd_ipv4+0x2c2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1f6, 0x2c2, x86_l_2c2);
x86_l_1fc:
	/* 0x1fc: mov    r14d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_200:
	/* 0x200: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_209:
	/* 0x209: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_212:
	/* 0x212: movabs rax,0x6b0085020a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 459570217482ULL);
x86_l_21c:
	/* 0x21c: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_224:
	/* 0x224: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_229:
	/* 0x229: mov    rdi,QWORD PTR [rip+0x59e7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_230:
	/* 0x230: lea    rsi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_238:
	/* 0x238: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23a:
	/* 0x23a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_23d:
	/* 0x23d: je     75e <tail_handle_snat_fwd_ipv4+0x75e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x23d, 0x75e, x86_l_75e);
x86_l_243:
	/* 0x243: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_246:
	/* 0x246: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_24a:
	/* 0x24a: jmp    73b <tail_handle_snat_fwd_ipv4+0x73b> */
	X86_SIM_X86_JMP(0x24a, 0x73b, x86_l_73b);
x86_l_24f:
	/* 0x24f: mov    QWORD PTR [rsp+0x30],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430209ULL);
x86_l_258:
	/* 0x258: mov    QWORD PTR [rsp+0x38],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_25d:
	/* 0x25d: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_262:
	/* 0x262: mov    rdi,QWORD PTR [rip+0x59e7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_269:
	/* 0x269: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_26e:
	/* 0x26e: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_273:
	/* 0x273: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_275:
	/* 0x275: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_277:
	/* 0x277: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_27c:
	/* 0x27c: mov    rsi,QWORD PTR [rip+0x59e7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_283:
	/* 0x283: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_286:
	/* 0x286: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_28b:
	/* 0x28b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28d:
	/* 0x28d: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_292:
	/* 0x292: jmp    192d <tail_handle_snat_fwd_ipv4+0x192d> */
	X86_SIM_X86_JMP(0x292, 0x192d, x86_l_192d);
x86_l_297:
	/* 0x297: test   r9,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R9, X86_RBP, X86_WIDTH_64);
x86_l_29a:
	/* 0x29a: jne    3e <tail_handle_snat_fwd_ipv4+0x3e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x29a, 0x3e, x86_l_3e);
x86_l_2a0:
	/* 0x2a0: mov    r14,r9 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R9, X86_WIDTH_64);
x86_l_2a3:
	/* 0x2a3: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_2a8:
	/* 0x2a8: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2ab:
	/* 0x2ab: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2b0:
	/* 0x2b0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b2:
	/* 0x2b2: mov    r11d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2b7:
	/* 0x2b7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2b9:
	/* 0x2b9: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_2bc:
	/* 0x2bc: js     3e3 <tail_handle_snat_fwd_ipv4+0x3e3> */
	X86_SIM_X86_JCC(X86_CC_S, 0x2bc, 0x3e3, x86_l_3e3);
x86_l_2c2:
	/* 0x2c2: movzx  eax,WORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_2c7:
	/* 0x2c7: movzx  ecx,WORD PTR [rsp+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_2cc:
	/* 0x2cc: mov    WORD PTR [rsp+0x26],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_2d1:
	/* 0x2d1: mov    WORD PTR [rsp+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2d6:
	/* 0x2d6: rol    ax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_2da:
	/* 0x2da: movzx  ecx,WORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2df:
	/* 0x2df: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2e1:
	/* 0x2e1: cmp    ax,cx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_16);
x86_l_2e4:
	/* 0x2e4: jb     18bf <tail_handle_snat_fwd_ipv4+0x18bf> */
	X86_SIM_X86_JCC(X86_CC_B, 0x2e4, 0x18bf, x86_l_18bf);
x86_l_2ea:
	/* 0x2ea: mov    r12,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDX, X86_WIDTH_64);
x86_l_2ed:
	/* 0x2ed: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f2:
	/* 0x2f2: mov    rdi,QWORD PTR [rip+0x59e7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_2f9:
	/* 0x2f9: lea    rsi,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2fe:
	/* 0x2fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_300:
	/* 0x300: movzx  ecx,WORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 40ULL);
x86_l_305:
	/* 0x305: mov    WORD PTR [rsp+0x7c],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_30a:
	/* 0x30a: mov    edx,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_30e:
	/* 0x30e: mov    DWORD PTR [rsp+0x78],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_312:
	/* 0x312: mov    rdx,QWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_317:
	/* 0x317: mov    DWORD PTR [rsp+0x74],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_31b:
	/* 0x31b: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_323:
	/* 0x323: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_327:
	/* 0x327: mov    DWORD PTR [rsp+0x70],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_32b:
	/* 0x32b: movzx  r14d,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_32f:
	/* 0x32f: cmp    r14w,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_16, 6ULL);
x86_l_334:
	/* 0x334: jne    34f <tail_handle_snat_fwd_ipv4+0x34f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x334, 0x34f, x86_l_34f);
x86_l_336:
	/* 0x336: mov    rdi,QWORD PTR [rip+0x59e7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct4_global)));
x86_l_33d:
	/* 0x33d: jmp    356 <tail_handle_snat_fwd_ipv4+0x356> */
	X86_SIM_X86_JMP(0x33d, 0x356, x86_l_356);
x86_l_33f:
	/* 0x33f: mov    r13d,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967161ULL);
x86_l_345:
	/* 0x345: mov    r11d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_34a:
	/* 0x34a: jmp    3e <tail_handle_snat_fwd_ipv4+0x3e> */
	X86_SIM_X86_JMP(0x34a, 0x3e, x86_l_3e);
x86_l_34f:
	/* 0x34f: mov    rdi,QWORD PTR [rip+0x59e7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct_any4_global)));
x86_l_356:
	/* 0x356: mov    r13,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_35e:
	/* 0x35e: mov    rax,QWORD PTR [rip+0x59e7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_ipv4_fragments)));
x86_l_365:
	/* 0x365: mov    BYTE PTR [rsp+0x7d],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 536870912000ULL);
x86_l_36a:
	/* 0x36a: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_372:
	/* 0x372: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_375:
	/* 0x375: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_378:
	/* 0x378: mov    DWORD PTR [rsp+0x2c],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_37d:
	/* 0x37d: je     42c <tail_handle_snat_fwd_ipv4+0x42c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x37d, 0x42c, x86_l_42c);
x86_l_383:
	/* 0x383: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_386:
	/* 0x386: je     42c <tail_handle_snat_fwd_ipv4+0x42c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x386, 0x42c, x86_l_42c);
x86_l_38c:
	/* 0x38c: mov    QWORD PTR [rsp+0xc0],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_394:
	/* 0x394: mov    r15,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_64);
x86_l_397:
	/* 0x397: mov    r14d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_39b:
	/* 0x39b: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_3a4:
	/* 0x3a4: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_3ad:
	/* 0x3ad: movabs rax,0x6c03a50209 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 463917613577ULL);
x86_l_3b7:
	/* 0x3b7: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_3bf:
	/* 0x3bf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3c4:
	/* 0x3c4: mov    rdi,QWORD PTR [rip+0x59e7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_3cb:
	/* 0x3cb: lea    rsi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_3d3:
	/* 0x3d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d5:
	/* 0x3d5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3d8:
	/* 0x3d8: je     3ee <tail_handle_snat_fwd_ipv4+0x3ee> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3d8, 0x3ee, x86_l_3ee);
x86_l_3da:
	/* 0x3da: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_3dd:
	/* 0x3dd: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3e1:
	/* 0x3e1: jmp    419 <tail_handle_snat_fwd_ipv4+0x419> */
	X86_SIM_X86_JMP(0x3e1, 0x419, x86_l_419);
x86_l_3e3:
	/* 0x3e3: mov    r13d,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967161ULL);
x86_l_3e9:
	/* 0x3e9: jmp    3e <tail_handle_snat_fwd_ipv4+0x3e> */
	X86_SIM_X86_JMP(0x3e9, 0x3e, x86_l_3e);
x86_l_3ee:
	/* 0x3ee: mov    QWORD PTR [rsp+0x30],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430209ULL);
x86_l_3f7:
	/* 0x3f7: mov    QWORD PTR [rsp+0x38],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3fc:
	/* 0x3fc: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_401:
	/* 0x401: mov    rdi,QWORD PTR [rip+0x59e7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_408:
	/* 0x408: lea    rsi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_410:
	/* 0x410: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_415:
	/* 0x415: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_417:
	/* 0x417: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_419:
	/* 0x419: mov    r13,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R15, X86_WIDTH_64);
x86_l_41c:
	/* 0x41c: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_41f:
	/* 0x41f: mov    r14d,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_424:
	/* 0x424: mov    rdi,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_42c:
	/* 0x42c: and    rax,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_42f:
	/* 0x42f: cmp    r14w,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_16, 6ULL);
x86_l_434:
	/* 0x434: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_43c:
	/* 0x43c: jne    493 <tail_handle_snat_fwd_ipv4+0x493> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x43c, 0x493, x86_l_493);
x86_l_43e:
	/* 0x43e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_441:
	/* 0x441: jne    493 <tail_handle_snat_fwd_ipv4+0x493> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x441, 0x493, x86_l_493);
x86_l_443:
	/* 0x443: mov    rbp,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDI, X86_WIDTH_64);
x86_l_446:
	/* 0x446: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_44b:
	/* 0x44b: lea    esi,[r13+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_44f:
	/* 0x44f: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_454:
	/* 0x454: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_457:
	/* 0x457: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_45c:
	/* 0x45c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_45e:
	/* 0x45e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_460:
	/* 0x460: js     4e3 <tail_handle_snat_fwd_ipv4+0x4e3> */
	X86_SIM_X86_JCC(X86_CC_S, 0x460, 0x4e3, x86_l_4e3);
x86_l_466:
	/* 0x466: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_46b:
	/* 0x46b: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_46e:
	/* 0x46e: and    eax,0x1200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4608ULL);
x86_l_473:
	/* 0x473: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_476:
	/* 0x476: cmp    eax,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 512ULL);
x86_l_47b:
	/* 0x47b: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_47e:
	/* 0x47e: test   r12d,0x500 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R12, X86_WIDTH_32, 1280ULL);
x86_l_485:
	/* 0x485: jne    753 <tail_handle_snat_fwd_ipv4+0x753> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x485, 0x753, x86_l_753);
x86_l_48b:
	/* 0x48b: mov    r15b,al */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_8);
x86_l_48e:
	/* 0x48e: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_491:
	/* 0x491: jmp    49b <tail_handle_snat_fwd_ipv4+0x49b> */
	X86_SIM_X86_JMP(0x491, 0x49b, x86_l_49b);
x86_l_493:
	/* 0x493: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_496:
	/* 0x496: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_49b:
	/* 0x49b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4a0:
	/* 0x4a0: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_4a5:
	/* 0x4a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a7:
	/* 0x4a7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4aa:
	/* 0x4aa: je     84d <tail_handle_snat_fwd_ipv4+0x84d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4aa, 0x84d, x86_l_84d);
x86_l_4b0:
	/* 0x4b0: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_4b3:
	/* 0x4b3: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_4b6:
	/* 0x4b6: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_4b8:
	/* 0x4b8: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_4ba:
	/* 0x4ba: test   cl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_4bd:
	/* 0x4bd: mov    rdi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_4c2:
	/* 0x4c2: je     5c9 <tail_handle_snat_fwd_ipv4+0x5c9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4c2, 0x5c9, x86_l_5c9);
x86_l_4c8:
	/* 0x4c8: mov    rdx,QWORD PTR [rip+0x59e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_4cf:
	/* 0x4cf: cmp    BYTE PTR [rdx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4d2:
	/* 0x4d2: je     4f0 <tail_handle_snat_fwd_ipv4+0x4f0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4d2, 0x4f0, x86_l_4f0);
x86_l_4d4:
	/* 0x4d4: mov    rcx,QWORD PTR [rip+0x59e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_4db:
	/* 0x4db: imul   ebp,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_4de:
	/* 0x4de: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_4e1:
	/* 0x4e1: jmp    4f5 <tail_handle_snat_fwd_ipv4+0x4f5> */
	X86_SIM_X86_JMP(0x4e1, 0x4f5, x86_l_4f5);
x86_l_4e3:
	/* 0x4e3: mov    r13d,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967161ULL);
x86_l_4e9:
	/* 0x4e9: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4eb:
	/* 0x4eb: jmp    18ad <tail_handle_snat_fwd_ipv4+0x18ad> */
	X86_SIM_X86_JMP(0x4eb, 0x18ad, x86_l_18ad);
x86_l_4f0:
	/* 0x4f0: mov    ebp,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_4f5:
	/* 0x4f5: mov    ecx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_4f9:
	/* 0x4f9: cmp    cx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 6ULL);
x86_l_4fd:
	/* 0x4fd: jne    532 <tail_handle_snat_fwd_ipv4+0x532> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4fd, 0x532, x86_l_532);
x86_l_4ff:
	/* 0x4ff: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_502:
	/* 0x502: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_504:
	/* 0x504: shr    ecx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_507:
	/* 0x507: and    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_50a:
	/* 0x50a: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_50c:
	/* 0x50c: mov    WORD PTR [r13+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_511:
	/* 0x511: test   al,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 16ULL);
x86_l_513:
	/* 0x513: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_518:
	/* 0x518: mov    ebp,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 21600ULL);
x86_l_51d:
	/* 0x51d: cmove  ebp,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_520:
	/* 0x520: cmp    BYTE PTR [rdx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_523:
	/* 0x523: je     532 <tail_handle_snat_fwd_ipv4+0x532> */
	X86_SIM_X86_JCC(X86_CC_E, 0x523, 0x532, x86_l_532);
x86_l_525:
	/* 0x525: mov    rax,QWORD PTR [rip+0x59e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_52c:
	/* 0x52c: imul   ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_52f:
	/* 0x52f: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_532:
	/* 0x532: mov    r14d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R12, X86_WIDTH_32);
x86_l_535:
	/* 0x535: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_539:
	/* 0x539: cmp    BYTE PTR [rdx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_53c:
	/* 0x53c: je     54d <tail_handle_snat_fwd_ipv4+0x54d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x53c, 0x54d, x86_l_54d);
x86_l_53e:
	/* 0x53e: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_543:
	/* 0x543: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_545:
	/* 0x545: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_547:
	/* 0x547: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_54b:
	/* 0x54b: jmp    570 <tail_handle_snat_fwd_ipv4+0x570> */
	X86_SIM_X86_JMP(0x54b, 0x570, x86_l_570);
x86_l_54d:
	/* 0x54d: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_552:
	/* 0x552: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_554:
	/* 0x554: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_556:
	/* 0x556: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_55a:
	/* 0x55a: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_564:
	/* 0x564: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_567:
	/* 0x567: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_56c:
	/* 0x56c: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_570:
	/* 0x570: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_572:
	/* 0x572: mov    DWORD PTR [r13+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_576:
	/* 0x576: movzx  ecx,BYTE PTR [r13+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_57b:
	/* 0x57b: mov    edx,DWORD PTR [r13+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_57f:
	/* 0x57f: and    r14b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_583:
	/* 0x583: mov    rsi,QWORD PTR [rip+0x59e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_58a:
	/* 0x58a: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_58d:
	/* 0x58d: mov    rdi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_592:
	/* 0x592: je     5a5 <tail_handle_snat_fwd_ipv4+0x5a5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x592, 0x5a5, x86_l_5a5);
x86_l_594:
	/* 0x594: mov    rsi,QWORD PTR [rip+0x59e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_59b:
	/* 0x59b: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_59d:
	/* 0x59d: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_5a0:
	/* 0x5a0: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_5a3:
	/* 0x5a3: jmp    5aa <tail_handle_snat_fwd_ipv4+0x5aa> */
	X86_SIM_X86_JMP(0x5a3, 0x5aa, x86_l_5aa);
x86_l_5a5:
	/* 0x5a5: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_5aa:
	/* 0x5aa: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_5ac:
	/* 0x5ac: or     r14b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_5af:
	/* 0x5af: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_5b1:
	/* 0x5b1: jb     5b8 <tail_handle_snat_fwd_ipv4+0x5b8> */
	X86_SIM_X86_JCC(X86_CC_B, 0x5b1, 0x5b8, x86_l_5b8);
x86_l_5b3:
	/* 0x5b3: cmp    cl,r14b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R14, X86_WIDTH_8);
x86_l_5b6:
	/* 0x5b6: je     5c9 <tail_handle_snat_fwd_ipv4+0x5c9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5b6, 0x5c9, x86_l_5c9);
x86_l_5b8:
	/* 0x5b8: mov    BYTE PTR [r13+0x2a],r14b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R14, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_5bc:
	/* 0x5bc: mov    DWORD PTR [r13+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5c0:
	/* 0x5c0: mov    rax,QWORD PTR [rip+0x59e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_5c7:
	/* 0x5c7: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5c9:
	/* 0x5c9: mov    rax,QWORD PTR [rip+0x59e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_5d0:
	/* 0x5d0: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5d3:
	/* 0x5d3: je     5e2 <tail_handle_snat_fwd_ipv4+0x5e2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5d3, 0x5e2, x86_l_5e2);
x86_l_5d5:
	/* 0x5d5: inc QWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 16ULL);
x86_l_5da:
	/* 0x5da: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_5dd:
	/* 0x5dd: add QWORD PTR [r13+0x18],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R13, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_5e2:
	/* 0x5e2: cmp    r15d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 2ULL);
x86_l_5e6:
	/* 0x5e6: je     633 <tail_handle_snat_fwd_ipv4+0x633> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5e6, 0x633, x86_l_633);
x86_l_5e8:
	/* 0x5e8: cmp    r15d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 1ULL);
x86_l_5ec:
	/* 0x5ec: jne    710 <tail_handle_snat_fwd_ipv4+0x710> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x5ec, 0x710, x86_l_710);
x86_l_5f2:
	/* 0x5f2: movzx  eax,WORD PTR [r13+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_5f7:
	/* 0x5f7: test   al,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 3ULL);
x86_l_5f9:
	/* 0x5f9: je     710 <tail_handle_snat_fwd_ipv4+0x710> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5f9, 0x710, x86_l_710);
x86_l_5ff:
	/* 0x5ff: mov    WORD PTR [r13+0x2a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 180388626432ULL);
x86_l_606:
	/* 0x606: and    eax,0xffec */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 65516ULL);
x86_l_60b:
	/* 0x60b: mov    WORD PTR [r13+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_610:
	/* 0x610: mov    r15,QWORD PTR [rip+0x59e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_617:
	/* 0x617: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_61b:
	/* 0x61b: je     78b <tail_handle_snat_fwd_ipv4+0x78b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x61b, 0x78b, x86_l_78b);
x86_l_621:
	/* 0x621: mov    rcx,QWORD PTR [rip+0x59e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_628:
	/* 0x628: imul   ebp,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_62b:
	/* 0x62b: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_62e:
	/* 0x62e: jmp    790 <tail_handle_snat_fwd_ipv4+0x790> */
	X86_SIM_X86_JMP(0x62e, 0x790, x86_l_790);
x86_l_633:
	/* 0x633: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_636:
	/* 0x636: and    eax,0x400 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 1024ULL);
x86_l_63b:
	/* 0x63b: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_63e:
	/* 0x63e: mov    ax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 3ULL);
x86_l_642:
	/* 0x642: sbb    ax,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_16, X86_ALU_SBB, 0ULL);
x86_l_646:
	/* 0x646: or     ax,WORD PTR [r13+0x24] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R13, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 36ULL);
x86_l_64b:
	/* 0x64b: mov    WORD PTR [r13+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_650:
	/* 0x650: mov    r15,QWORD PTR [rip+0x59e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_657:
	/* 0x657: mov    ecx,DWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_65a:
	/* 0x65a: test   al,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_65c:
	/* 0x65c: je     710 <tail_handle_snat_fwd_ipv4+0x710> */
	X86_SIM_X86_JCC(X86_CC_E, 0x65c, 0x710, x86_l_710);
x86_l_662:
	/* 0x662: mov    r14,QWORD PTR [rip+0x59e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_669:
	/* 0x669: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_66d:
	/* 0x66d: je     682 <tail_handle_snat_fwd_ipv4+0x682> */
	X86_SIM_X86_JCC(X86_CC_E, 0x66d, 0x682, x86_l_682);
x86_l_66f:
	/* 0x66f: mov    rax,QWORD PTR [rip+0x59e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_676:
	/* 0x676: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_678:
	/* 0x678: add    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_67a:
	/* 0x67a: lea    ebp,[rax+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_67d:
	/* 0x67d: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_680:
	/* 0x680: jmp    687 <tail_handle_snat_fwd_ipv4+0x687> */
	X86_SIM_X86_JMP(0x680, 0x687, x86_l_687);
x86_l_682:
	/* 0x682: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_687:
	/* 0x687: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_68b:
	/* 0x68b: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_68f:
	/* 0x68f: je     6a0 <tail_handle_snat_fwd_ipv4+0x6a0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x68f, 0x6a0, x86_l_6a0);
x86_l_691:
	/* 0x691: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_696:
	/* 0x696: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_698:
	/* 0x698: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_69a:
	/* 0x69a: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_69e:
	/* 0x69e: jmp    6c3 <tail_handle_snat_fwd_ipv4+0x6c3> */
	X86_SIM_X86_JMP(0x69e, 0x6c3, x86_l_6c3);
x86_l_6a0:
	/* 0x6a0: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_6a5:
	/* 0x6a5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6a7:
	/* 0x6a7: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_6a9:
	/* 0x6a9: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_6ad:
	/* 0x6ad: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_6b7:
	/* 0x6b7: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_6ba:
	/* 0x6ba: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_6bf:
	/* 0x6bf: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_6c3:
	/* 0x6c3: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_6c5:
	/* 0x6c5: mov    DWORD PTR [r13+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6c9:
	/* 0x6c9: movzx  ecx,BYTE PTR [r13+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_6ce:
	/* 0x6ce: mov    edx,DWORD PTR [r13+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6d2:
	/* 0x6d2: and    r12b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_6d6:
	/* 0x6d6: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6da:
	/* 0x6da: mov    rdi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_6df:
	/* 0x6df: je     6f2 <tail_handle_snat_fwd_ipv4+0x6f2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6df, 0x6f2, x86_l_6f2);
x86_l_6e1:
	/* 0x6e1: mov    rsi,QWORD PTR [rip+0x59e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_6e8:
	/* 0x6e8: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6ea:
	/* 0x6ea: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_6ed:
	/* 0x6ed: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_6f0:
	/* 0x6f0: jmp    6f7 <tail_handle_snat_fwd_ipv4+0x6f7> */
	X86_SIM_X86_JMP(0x6f0, 0x6f7, x86_l_6f7);
x86_l_6f2:
	/* 0x6f2: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_6f7:
	/* 0x6f7: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_6f9:
	/* 0x6f9: or     r12b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_6fc:
	/* 0x6fc: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_6fe:
	/* 0x6fe: jb     705 <tail_handle_snat_fwd_ipv4+0x705> */
	X86_SIM_X86_JCC(X86_CC_B, 0x6fe, 0x705, x86_l_705);
x86_l_700:
	/* 0x700: cmp    cl,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R12, X86_WIDTH_8);
x86_l_703:
	/* 0x703: je     710 <tail_handle_snat_fwd_ipv4+0x710> */
	X86_SIM_X86_JCC(X86_CC_E, 0x703, 0x710, x86_l_710);
x86_l_705:
	/* 0x705: mov    BYTE PTR [r13+0x2a],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_709:
	/* 0x709: mov    DWORD PTR [r13+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_70d:
	/* 0x70d: mov    eax,DWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_710:
	/* 0x710: mov    r15,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_718:
	/* 0x718: jmp    9ca <tail_handle_snat_fwd_ipv4+0x9ca> */
	X86_SIM_X86_JMP(0x718, 0x9ca, x86_l_9ca);
x86_l_71d:
	/* 0x71d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_722:
	/* 0x722: mov    rdi,QWORD PTR [rip+0x59e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv4_frag_datagrams)));
x86_l_729:
	/* 0x729: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_72e:
	/* 0x72e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_730:
	/* 0x730: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_733:
	/* 0x733: je     743 <tail_handle_snat_fwd_ipv4+0x743> */
	X86_SIM_X86_JCC(X86_CC_E, 0x733, 0x743, x86_l_743);
x86_l_735:
	/* 0x735: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_737:
	/* 0x737: mov    DWORD PTR [rsp+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_73b:
	/* 0x73b: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_73e:
	/* 0x73e: jmp    2c2 <tail_handle_snat_fwd_ipv4+0x2c2> */
	X86_SIM_X86_JMP(0x73e, 0x2c2, x86_l_2c2);
x86_l_743:
	/* 0x743: mov    r13d,0xffffff51 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967121ULL);
x86_l_749:
	/* 0x749: mov    r11d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_74e:
	/* 0x74e: jmp    3e <tail_handle_snat_fwd_ipv4+0x3e> */
	X86_SIM_X86_JMP(0x74e, 0x3e, x86_l_3e);
x86_l_753:
	/* 0x753: mov    r15d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 2ULL);
x86_l_759:
	/* 0x759: jmp    48e <tail_handle_snat_fwd_ipv4+0x48e> */
	X86_SIM_X86_JMP(0x759, 0x48e, x86_l_48e);
x86_l_75e:
	/* 0x75e: mov    QWORD PTR [rsp+0x30],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430209ULL);
x86_l_767:
	/* 0x767: mov    QWORD PTR [rsp+0x38],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_76c:
	/* 0x76c: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_771:
	/* 0x771: mov    rdi,QWORD PTR [rip+0x59e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_778:
	/* 0x778: lea    rsi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_780:
	/* 0x780: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_785:
	/* 0x785: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_787:
	/* 0x787: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_789:
	/* 0x789: jmp    73b <tail_handle_snat_fwd_ipv4+0x73b> */
	X86_SIM_X86_JMP(0x789, 0x73b, x86_l_73b);
x86_l_78b:
	/* 0x78b: mov    ebp,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_790:
	/* 0x790: cmp    WORD PTR [rsp+0x2c],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 188978561030ULL);
x86_l_796:
	/* 0x796: jne    7cc <tail_handle_snat_fwd_ipv4+0x7cc> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x796, 0x7cc, x86_l_7cc);
x86_l_798:
	/* 0x798: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_79b:
	/* 0x79b: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_79d:
	/* 0x79d: shr    ecx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_7a0:
	/* 0x7a0: and    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_7a3:
	/* 0x7a3: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_7a5:
	/* 0x7a5: mov    WORD PTR [r13+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_7aa:
	/* 0x7aa: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_7ac:
	/* 0x7ac: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_7b1:
	/* 0x7b1: mov    ebp,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 21600ULL);
x86_l_7b6:
	/* 0x7b6: cmove  ebp,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_7b9:
	/* 0x7b9: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7bd:
	/* 0x7bd: je     7cc <tail_handle_snat_fwd_ipv4+0x7cc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7bd, 0x7cc, x86_l_7cc);
x86_l_7bf:
	/* 0x7bf: mov    rax,QWORD PTR [rip+0x59e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_7c6:
	/* 0x7c6: imul   ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_7c9:
	/* 0x7c9: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_7cc:
	/* 0x7cc: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_7d0:
	/* 0x7d0: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7d4:
	/* 0x7d4: je     7e5 <tail_handle_snat_fwd_ipv4+0x7e5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7d4, 0x7e5, x86_l_7e5);
x86_l_7d6:
	/* 0x7d6: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_7db:
	/* 0x7db: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7dd:
	/* 0x7dd: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_7df:
	/* 0x7df: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_7e3:
	/* 0x7e3: jmp    808 <tail_handle_snat_fwd_ipv4+0x808> */
	X86_SIM_X86_JMP(0x7e3, 0x808, x86_l_808);
x86_l_7e5:
	/* 0x7e5: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_7ea:
	/* 0x7ea: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7ec:
	/* 0x7ec: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_7ee:
	/* 0x7ee: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_7f2:
	/* 0x7f2: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_7fc:
	/* 0x7fc: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_7ff:
	/* 0x7ff: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_804:
	/* 0x804: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_808:
	/* 0x808: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_80a:
	/* 0x80a: mov    DWORD PTR [r13+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_80e:
	/* 0x80e: movzx  ecx,BYTE PTR [r13+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_813:
	/* 0x813: mov    edx,DWORD PTR [r13+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_817:
	/* 0x817: and    r12b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_81b:
	/* 0x81b: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_81f:
	/* 0x81f: je     832 <tail_handle_snat_fwd_ipv4+0x832> */
	X86_SIM_X86_JCC(X86_CC_E, 0x81f, 0x832, x86_l_832);
x86_l_821:
	/* 0x821: mov    rsi,QWORD PTR [rip+0x59e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_828:
	/* 0x828: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_82a:
	/* 0x82a: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_82d:
	/* 0x82d: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_830:
	/* 0x830: jmp    837 <tail_handle_snat_fwd_ipv4+0x837> */
	X86_SIM_X86_JMP(0x830, 0x837, x86_l_837);
x86_l_832:
	/* 0x832: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_837:
	/* 0x837: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_839:
	/* 0x839: or     r12b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_83c:
	/* 0x83c: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_83e:
	/* 0x83e: jb     845 <tail_handle_snat_fwd_ipv4+0x845> */
	X86_SIM_X86_JCC(X86_CC_B, 0x83e, 0x845, x86_l_845);
x86_l_840:
	/* 0x840: cmp    cl,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R12, X86_WIDTH_8);
x86_l_843:
	/* 0x843: je     856 <tail_handle_snat_fwd_ipv4+0x856> */
	X86_SIM_X86_JCC(X86_CC_E, 0x843, 0x856, x86_l_856);
x86_l_845:
	/* 0x845: mov    BYTE PTR [r13+0x2a],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_849:
	/* 0x849: mov    DWORD PTR [r13+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_84d:
	/* 0x84d: mov    rax,QWORD PTR [rip+0x59e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_854:
	/* 0x854: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_856:
	/* 0x856: movzx  ebp,BYTE PTR [rsp+0x7c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 124ULL);
x86_l_85b:
	/* 0x85b: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_85f:
	/* 0x85f: jne    86a <tail_handle_snat_fwd_ipv4+0x86a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x85f, 0x86a, x86_l_86a);
x86_l_861:
	/* 0x861: mov    r13,QWORD PTR [rip+0x59e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&cilium_ct4_global)));
x86_l_868:
	/* 0x868: jmp    871 <tail_handle_snat_fwd_ipv4+0x871> */
	X86_SIM_X86_JMP(0x868, 0x871, x86_l_871);
x86_l_86a:
	/* 0x86a: mov    r13,QWORD PTR [rip+0x59e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&cilium_ct_any4_global)));
x86_l_871:
	/* 0x871: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_87a:
	/* 0x87a: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_883:
	/* 0x883: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_88c:
	/* 0x88c: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_895:
	/* 0x895: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_89e:
	/* 0x89e: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_8a7:
	/* 0x8a7: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_8b0:
	/* 0x8b0: mov    r14,QWORD PTR [rip+0x59e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_8b7:
	/* 0x8b7: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8bb:
	/* 0x8bb: je     8ce <tail_handle_snat_fwd_ipv4+0x8ce> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8bb, 0x8ce, x86_l_8ce);
x86_l_8bd:
	/* 0x8bd: mov    rax,QWORD PTR [rip+0x59e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_8c4:
	/* 0x8c4: imul   r15d,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_8c8:
	/* 0x8c8: shr    r15d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_8cc:
	/* 0x8cc: jmp    8d4 <tail_handle_snat_fwd_ipv4+0x8d4> */
	X86_SIM_X86_JMP(0x8cc, 0x8d4, x86_l_8d4);
x86_l_8ce:
	/* 0x8ce: mov    r15d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 60ULL);
x86_l_8d4:
	/* 0x8d4: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_8d8:
	/* 0x8d8: jne    8f7 <tail_handle_snat_fwd_ipv4+0x8f7> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x8d8, 0x8f7, x86_l_8f7);
x86_l_8da:
	/* 0x8da: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8de:
	/* 0x8de: je     8f1 <tail_handle_snat_fwd_ipv4+0x8f1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8de, 0x8f1, x86_l_8f1);
x86_l_8e0:
	/* 0x8e0: mov    rax,QWORD PTR [rip+0x59e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_8e7:
	/* 0x8e7: imul   r15d,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_8eb:
	/* 0x8eb: shr    r15d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_8ef:
	/* 0x8ef: jmp    8f7 <tail_handle_snat_fwd_ipv4+0x8f7> */
	X86_SIM_X86_JMP(0x8ef, 0x8f7, x86_l_8f7);
x86_l_8f1:
	/* 0x8f1: mov    r15d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 60ULL);
x86_l_8f7:
	/* 0x8f7: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8fb:
	/* 0x8fb: je     90c <tail_handle_snat_fwd_ipv4+0x90c> */
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
	/* 0x90a: jmp    92f <tail_handle_snat_fwd_ipv4+0x92f> */
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
	/* 0x92f: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_933:
	/* 0x933: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_936:
	/* 0x936: add    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_939:
	/* 0x939: mov    DWORD PTR [rsp+0x50],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_93e:
	/* 0x93e: movzx  edx,BYTE PTR [rsp+0x5a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 90ULL);
x86_l_943:
	/* 0x943: mov    esi,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_947:
	/* 0x947: add    cl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_8, X86_ALU_ADD);
x86_l_949:
	/* 0x949: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_94d:
	/* 0x94d: je     960 <tail_handle_snat_fwd_ipv4+0x960> */
	X86_SIM_X86_JCC(X86_CC_E, 0x94d, 0x960, x86_l_960);
x86_l_94f:
	/* 0x94f: mov    rdi,QWORD PTR [rip+0x59e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_956:
	/* 0x956: mov    edi,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_958:
	/* 0x958: lea    edi,[rdi+rdi*4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_95b:
	/* 0x95b: shr    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_95e:
	/* 0x95e: jmp    965 <tail_handle_snat_fwd_ipv4+0x965> */
	X86_SIM_X86_JMP(0x95e, 0x965, x86_l_965);
x86_l_960:
	/* 0x960: mov    edi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 5ULL);
x86_l_965:
	/* 0x965: mov    r15,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_96d:
	/* 0x96d: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_96f:
	/* 0x96f: or     cl,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_971:
	/* 0x971: cmp    edi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_973:
	/* 0x973: jb     979 <tail_handle_snat_fwd_ipv4+0x979> */
	X86_SIM_X86_JCC(X86_CC_B, 0x973, 0x979, x86_l_979);
x86_l_975:
	/* 0x975: cmp    dl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_8);
x86_l_977:
	/* 0x977: je     98a <tail_handle_snat_fwd_ipv4+0x98a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x977, 0x98a, x86_l_98a);
x86_l_979:
	/* 0x979: mov    BYTE PTR [rsp+0x5a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 90ULL);
x86_l_97d:
	/* 0x97d: mov    DWORD PTR [rsp+0x60],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_981:
	/* 0x981: mov    rax,QWORD PTR [rip+0x59e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_988:
	/* 0x988: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_98a:
	/* 0x98a: mov    rax,QWORD PTR [rip+0x59e3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_991:
	/* 0x991: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_994:
	/* 0x994: je     9a7 <tail_handle_snat_fwd_ipv4+0x9a7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x994, 0x9a7, x86_l_9a7);
x86_l_996:
	/* 0x996: mov    QWORD PTR [rsp+0x40],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906945ULL);
x86_l_99f:
	/* 0x99f: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_9a2:
	/* 0x9a2: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_9a7:
	/* 0x9a7: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_9ac:
	/* 0x9ac: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_9b1:
	/* 0x9b1: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9b6:
	/* 0x9b6: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_9b9:
	/* 0x9b9: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9bb:
	/* 0x9bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9bd:
	/* 0x9bd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_9bf:
	/* 0x9bf: js     157e <tail_handle_snat_fwd_ipv4+0x157e> */
	X86_SIM_X86_JCC(X86_CC_S, 0x9bf, 0x157e, x86_l_157e);
x86_l_9c5:
	/* 0x9c5: mov    rdi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_9ca:
	/* 0x9ca: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_9cd:
	/* 0x9cd: je     af2 <tail_handle_snat_fwd_ipv4+0xaf2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9cd, 0xaf2, x86_l_af2);
x86_l_9d3:
	/* 0x9d3: mov    BYTE PTR [rsp+0x7d],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 536870912001ULL);
x86_l_9d8:
	/* 0x9d8: movzx  eax,BYTE PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 40ULL);
x86_l_9dd:
	/* 0x9dd: mov    BYTE PTR [rsp+0x7c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_9e1:
	/* 0x9e1: mov    eax,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_9e5:
	/* 0x9e5: mov    DWORD PTR [rsp+0x74],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_9e9:
	/* 0x9e9: mov    eax,DWORD PTR [r15+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9ed:
	/* 0x9ed: mov    DWORD PTR [rsp+0x70],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_9f1:
	/* 0x9f1: movzx  ecx,WORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_9f6:
	/* 0x9f6: mov    WORD PTR [rsp+0x7a],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 122ULL);
x86_l_9fb:
	/* 0x9fb: movzx  ecx,WORD PTR [r15+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_a00:
	/* 0xa00: mov    WORD PTR [rsp+0x78],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_a05:
	/* 0xa05: cmp    eax,0xfffff50a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294964490ULL);
x86_l_a0a:
	/* 0xa0a: jne    a98 <tail_handle_snat_fwd_ipv4+0xa98> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa0a, 0xa98, x86_l_a98);
x86_l_a10:
	/* 0xa10: cmp    QWORD PTR [r15+0x8],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_a15:
	/* 0xa15: jne    a98 <tail_handle_snat_fwd_ipv4+0xa98> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa15, 0xa98, x86_l_a98);
x86_l_a1b:
	/* 0xa1b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a20:
	/* 0xa20: mov    rdi,QWORD PTR [rip+0x59df] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_a27:
	/* 0xa27: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_a2c:
	/* 0xa2c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a2e:
	/* 0xa2e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a31:
	/* 0xa31: jne    14db <tail_handle_snat_fwd_ipv4+0x14db> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa31, 0x14db, x86_l_14db);
x86_l_a37:
	/* 0xa37: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_a40:
	/* 0xa40: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_a49:
	/* 0xa49: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_a52:
	/* 0xa52: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_a5b:
	/* 0xa5b: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a5f:
	/* 0xa5f: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_a63:
	/* 0xa63: movzx  eax,WORD PTR [rsp+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_a68:
	/* 0xa68: mov    WORD PTR [rsp+0x54],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_a6d:
	/* 0xa6d: mov    QWORD PTR [rsp+0x38],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168577ULL);
x86_l_a76:
	/* 0xa76: mov    rax,QWORD PTR [rip+0x59df] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_a7d:
	/* 0xa7d: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a80:
	/* 0xa80: je     1495 <tail_handle_snat_fwd_ipv4+0x1495> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa80, 0x1495, x86_l_1495);
x86_l_a86:
	/* 0xa86: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_a8b:
	/* 0xa8b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a8d:
	/* 0xa8d: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_a8f:
	/* 0xa8f: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_a93:
	/* 0xa93: jmp    14b8 <tail_handle_snat_fwd_ipv4+0x14b8> */
	X86_SIM_X86_JMP(0xa93, 0x14b8, x86_l_14b8);
x86_l_a98:
	/* 0xa98: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_a9d:
	/* 0xa9d: mov    rdi,QWORD PTR [rip+0x59df] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_aa4:
	/* 0xaa4: lea    rsi,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_aa9:
	/* 0xaa9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aab:
	/* 0xaab: mov    r13d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_aae:
	/* 0xaae: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ab0:
	/* 0xab0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ab2:
	/* 0xab2: js     16c4 <tail_handle_snat_fwd_ipv4+0x16c4> */
	X86_SIM_X86_JCC(X86_CC_S, 0xab2, 0x16c4, x86_l_16c4);
x86_l_ab8:
	/* 0xab8: cmp    r13d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 2ULL);
x86_l_abc:
	/* 0xabc: je     16c4 <tail_handle_snat_fwd_ipv4+0x16c4> */
	X86_SIM_X86_JCC(X86_CC_E, 0xabc, 0x16c4, x86_l_16c4);
x86_l_ac2:
	/* 0xac2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ac7:
	/* 0xac7: mov    rdi,QWORD PTR [rip+0x59df] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_ace:
	/* 0xace: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_ad3:
	/* 0xad3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ad5:
	/* 0xad5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ad8:
	/* 0xad8: je     aed <tail_handle_snat_fwd_ipv4+0xaed> */
	X86_SIM_X86_JCC(X86_CC_E, 0xad8, 0xaed, x86_l_aed);
x86_l_ada:
	/* 0xada: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_adf:
	/* 0xadf: mov    rdi,QWORD PTR [rip+0x59df] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_ae6:
	/* 0xae6: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_aeb:
	/* 0xaeb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aed:
	/* 0xaed: mov    rdi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_af2:
	/* 0xaf2: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_afb:
	/* 0xafb: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_b04:
	/* 0xb04: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_b0d:
	/* 0xb0d: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_b16:
	/* 0xb16: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_b1f:
	/* 0xb1f: mov    QWORD PTR [rsp+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_b2b:
	/* 0xb2b: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_b34:
	/* 0xb34: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_b3d:
	/* 0xb3d: mov    QWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_b49:
	/* 0xb49: mov    QWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_b55:
	/* 0xb55: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b59:
	/* 0xb59: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_b5d:
	/* 0xb5d: movzx  r14d,WORD PTR [rsp+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_b63:
	/* 0xb63: mov    WORD PTR [rsp+0x54],r14w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_b69:
	/* 0xb69: mov    DWORD PTR [rsp+0x90],0xfffff50a */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 622770255114ULL);
x86_l_b74:
	/* 0xb74: mov    BYTE PTR [rsp+0x15],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 90194313217ULL);
x86_l_b79:
	/* 0xb79: movzx  eax,BYTE PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 40ULL);
x86_l_b7e:
	/* 0xb7e: mov    BYTE PTR [rsp+0x14],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_b82:
	/* 0xb82: mov    eax,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_b86:
	/* 0xb86: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_b8a:
	/* 0xb8a: mov    DWORD PTR [rsp+0x8],0xfffff50a */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 38654702858ULL);
x86_l_b92:
	/* 0xb92: movzx  eax,WORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_b97:
	/* 0xb97: mov    WORD PTR [rsp+0x12],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_b9c:
	/* 0xb9c: lea    ebp,[rdi+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_b9f:
	/* 0xb9f: mov    WORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_ba6:
	/* 0xba6: rol    r14w,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_bab:
	/* 0xbab: cmp    r14w,bp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R14, X86_RBP, X86_WIDTH_16);
x86_l_baf:
	/* 0xbaf: jae    bd4 <tail_handle_snat_fwd_ipv4+0xbd4> */
	X86_SIM_X86_JCC(X86_CC_AE, 0xbaf, 0xbd4, x86_l_bd4);
x86_l_bb1:
	/* 0xbb1: mov    ecx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_bb6:
	/* 0xbb6: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bb8:
	/* 0xbb8: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_bba:
	/* 0xbba: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_bbf:
	/* 0xbbf: xor    ecx,0xffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 65535ULL);
x86_l_bc5:
	/* 0xbc5: movzx  r14d,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_bc9:
	/* 0xbc9: imul   r14d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_bcd:
	/* 0xbcd: shr    r14d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_bd1:
	/* 0xbd1: add    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_bd4:
	/* 0xbd4: mov    QWORD PTR [rsp+0x78],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075521ULL);
x86_l_bdd:
	/* 0xbdd: mov    QWORD PTR [rsp+0x38],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168577ULL);
x86_l_be6:
	/* 0xbe6: mov    rax,QWORD PTR [rip+0x59df] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_bed:
	/* 0xbed: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bf0:
	/* 0xbf0: je     c01 <tail_handle_snat_fwd_ipv4+0xc01> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbf0, 0xc01, x86_l_c01);
x86_l_bf2:
	/* 0xbf2: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_bf7:
	/* 0xbf7: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bf9:
	/* 0xbf9: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_bfb:
	/* 0xbfb: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_bff:
	/* 0xbff: jmp    c24 <tail_handle_snat_fwd_ipv4+0xc24> */
	X86_SIM_X86_JMP(0xbff, 0xc24, x86_l_c24);
x86_l_c01:
	/* 0xc01: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_c06:
	/* 0xc06: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c08:
	/* 0xc08: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_c0a:
	/* 0xc0a: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_c0e:
	/* 0xc0e: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_c18:
	/* 0xc18: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_c1b:
	/* 0xc1b: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_c20:
	/* 0xc20: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_c24:
	/* 0xc24: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c29:
	/* 0xc29: movbe  WORD PTR [rsp+0x10],r14w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_c31:
	/* 0xc31: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_c36:
	/* 0xc36: mov    rdi,QWORD PTR [rip+0x59df] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_c3d:
	/* 0xc3d: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c42:
	/* 0xc42: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c47:
	/* 0xc47: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_c4d:
	/* 0xc4d: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_c52:
	/* 0xc52: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c54:
	/* 0xc54: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c56:
	/* 0xc56: je     1452 <tail_handle_snat_fwd_ipv4+0x1452> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc56, 0x1452, x86_l_1452);
x86_l_c5c:
	/* 0xc5c: mov    eax,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967294ULL);
x86_l_c61:
	/* 0xc61: sub    eax,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 104ULL);
x86_l_c65:
	/* 0xc65: movzx  r14d,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_c69:
	/* 0xc69: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_c6c:
	/* 0xc6c: mov    ecx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_c71:
	/* 0xc71: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c74:
	/* 0xc74: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c76:
	/* 0xc76: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_c78:
	/* 0xc78: movzx  r13d,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_c7c:
	/* 0xc7c: imul   r13d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R14, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_c80:
	/* 0xc80: shr    r13d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_c84:
	/* 0xc84: add    r13d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_c87:
	/* 0xc87: movbe  WORD PTR [rsp+0x10],r13w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_c8f:
	/* 0xc8f: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_c94:
	/* 0xc94: mov    rdi,QWORD PTR [rip+0x59df] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_c9b:
	/* 0xc9b: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ca0:
	/* 0xca0: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ca5:
	/* 0xca5: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_caa:
	/* 0xcaa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cac:
	/* 0xcac: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_cae:
	/* 0xcae: je     160c <tail_handle_snat_fwd_ipv4+0x160c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xcae, 0x160c, x86_l_160c);
x86_l_cb4:
	/* 0xcb4: inc    r13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_cb7:
	/* 0xcb7: movzx  r15d,r13w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R13, X86_WIDTH_32, X86_WIDTH_16);
x86_l_cbb:
	/* 0xcbb: imul   r15d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R14, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_cbf:
	/* 0xcbf: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_cc3:
	/* 0xcc3: add    r15d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_cc6:
	/* 0xcc6: movbe  WORD PTR [rsp+0x10],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_cce:
	/* 0xcce: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_cd3:
	/* 0xcd3: mov    rdi,QWORD PTR [rip+0x59df] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_cda:
	/* 0xcda: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cdf:
	/* 0xcdf: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ce4:
	/* 0xce4: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_ce9:
	/* 0xce9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ceb:
	/* 0xceb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ced:
	/* 0xced: je     145d <tail_handle_snat_fwd_ipv4+0x145d> */
	X86_SIM_X86_JCC(X86_CC_E, 0xced, 0x145d, x86_l_145d);
x86_l_cf3:
	/* 0xcf3: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_cf6:
	/* 0xcf6: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_cfa:
	/* 0xcfa: imul   r15d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R14, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_cfe:
	/* 0xcfe: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_d02:
	/* 0xd02: add    r15d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_d05:
	/* 0xd05: movbe  WORD PTR [rsp+0x10],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_d0d:
	/* 0xd0d: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_d12:
	/* 0xd12: mov    rdi,QWORD PTR [rip+0x59df] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_d19:
	/* 0xd19: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d1e:
	/* 0xd1e: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d23:
	/* 0xd23: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_d28:
	/* 0xd28: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d2a:
	/* 0xd2a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_d2c:
	/* 0xd2c: je     146b <tail_handle_snat_fwd_ipv4+0x146b> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd2c, 0x146b, x86_l_146b);
x86_l_d32:
	/* 0xd32: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_d35:
	/* 0xd35: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_d39:
	/* 0xd39: imul   r15d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R14, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_d3d:
	/* 0xd3d: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_d41:
	/* 0xd41: add    r15d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_d44:
	/* 0xd44: movbe  WORD PTR [rsp+0x10],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_d4c:
	/* 0xd4c: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_d51:
	/* 0xd51: mov    rdi,QWORD PTR [rip+0x59df] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_d58:
	/* 0xd58: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d5d:
	/* 0xd5d: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d62:
	/* 0xd62: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_d67:
	/* 0xd67: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d69:
	/* 0xd69: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_d6b:
	/* 0xd6b: je     1479 <tail_handle_snat_fwd_ipv4+0x1479> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd6b, 0x1479, x86_l_1479);
x86_l_d71:
	/* 0xd71: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_d74:
	/* 0xd74: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_d78:
	/* 0xd78: imul   r15d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R14, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_d7c:
	/* 0xd7c: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_d80:
	/* 0xd80: add    r15d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_d83:
	/* 0xd83: movbe  WORD PTR [rsp+0x10],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_d8b:
	/* 0xd8b: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_d90:
	/* 0xd90: mov    rdi,QWORD PTR [rip+0x59df] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_d97:
	/* 0xd97: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d9c:
	/* 0xd9c: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_da1:
	/* 0xda1: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_da6:
	/* 0xda6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_da8:
	/* 0xda8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_daa:
	/* 0xdaa: je     1487 <tail_handle_snat_fwd_ipv4+0x1487> */
	X86_SIM_X86_JCC(X86_CC_E, 0xdaa, 0x1487, x86_l_1487);
x86_l_db0:
	/* 0xdb0: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_db3:
	/* 0xdb3: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_db7:
	/* 0xdb7: imul   r15d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R14, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_dbb:
	/* 0xdbb: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_dbf:
	/* 0xdbf: add    r15d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_dc2:
	/* 0xdc2: movbe  WORD PTR [rsp+0x10],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_dca:
	/* 0xdca: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_dcf:
	/* 0xdcf: mov    rdi,QWORD PTR [rip+0x59df] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_dd6:
	/* 0xdd6: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ddb:
	/* 0xddb: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_de0:
	/* 0xde0: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_de5:
	/* 0xde5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_de7:
	/* 0xde7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_de9:
	/* 0xde9: je     14f2 <tail_handle_snat_fwd_ipv4+0x14f2> */
	X86_SIM_X86_JCC(X86_CC_E, 0xde9, 0x14f2, x86_l_14f2);
x86_l_def:
	/* 0xdef: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_df2:
	/* 0xdf2: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_df6:
	/* 0xdf6: imul   r15d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R14, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_dfa:
	/* 0xdfa: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_dfe:
	/* 0xdfe: add    r15d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_e01:
	/* 0xe01: movbe  WORD PTR [rsp+0x10],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_e09:
	/* 0xe09: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_e0e:
	/* 0xe0e: mov    rdi,QWORD PTR [rip+0x59df] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_e15:
	/* 0xe15: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e1a:
	/* 0xe1a: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e1f:
	/* 0xe1f: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_e24:
	/* 0xe24: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e26:
	/* 0xe26: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_e28:
	/* 0xe28: je     1500 <tail_handle_snat_fwd_ipv4+0x1500> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe28, 0x1500, x86_l_1500);
x86_l_e2e:
	/* 0xe2e: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_e31:
	/* 0xe31: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_e35:
	/* 0xe35: imul   r15d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R14, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_e39:
	/* 0xe39: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_e3d:
	/* 0xe3d: add    r15d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_e40:
	/* 0xe40: movbe  WORD PTR [rsp+0x10],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_e48:
	/* 0xe48: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_e4d:
	/* 0xe4d: mov    rdi,QWORD PTR [rip+0x59df] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_e54:
	/* 0xe54: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e59:
	/* 0xe59: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e5e:
	/* 0xe5e: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_e63:
	/* 0xe63: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e65:
	/* 0xe65: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_e67:
	/* 0xe67: je     150e <tail_handle_snat_fwd_ipv4+0x150e> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe67, 0x150e, x86_l_150e);
x86_l_e6d:
	/* 0xe6d: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_e70:
	/* 0xe70: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_e74:
	/* 0xe74: imul   r15d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R14, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_e78:
	/* 0xe78: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_e7c:
	/* 0xe7c: add    r15d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_e7f:
	/* 0xe7f: movbe  WORD PTR [rsp+0x10],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_e87:
	/* 0xe87: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_e8c:
	/* 0xe8c: mov    rdi,QWORD PTR [rip+0x59df] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_e93:
	/* 0xe93: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e98:
	/* 0xe98: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e9d:
	/* 0xe9d: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_ea2:
	/* 0xea2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ea4:
	/* 0xea4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ea6:
	/* 0xea6: je     151c <tail_handle_snat_fwd_ipv4+0x151c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xea6, 0x151c, x86_l_151c);
x86_l_eac:
	/* 0xeac: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_eaf:
	/* 0xeaf: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_eb3:
	/* 0xeb3: imul   r15d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R14, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_eb7:
	/* 0xeb7: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_ebb:
	/* 0xebb: add    r15d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_ebe:
	/* 0xebe: movbe  WORD PTR [rsp+0x10],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_ec6:
	/* 0xec6: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_ecb:
	/* 0xecb: mov    rdi,QWORD PTR [rip+0x59df] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_ed2:
	/* 0xed2: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ed7:
	/* 0xed7: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_edc:
	/* 0xedc: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_ee1:
	/* 0xee1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ee3:
	/* 0xee3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ee5:
	/* 0xee5: je     152a <tail_handle_snat_fwd_ipv4+0x152a> */
	X86_SIM_X86_JCC(X86_CC_E, 0xee5, 0x152a, x86_l_152a);
x86_l_eeb:
	/* 0xeeb: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_eee:
	/* 0xeee: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_ef2:
	/* 0xef2: imul   r15d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R14, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_ef6:
	/* 0xef6: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_efa:
	/* 0xefa: add    r15d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_efd:
	/* 0xefd: movbe  WORD PTR [rsp+0x10],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_f05:
	/* 0xf05: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_f0a:
	/* 0xf0a: mov    rdi,QWORD PTR [rip+0x59df] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_f11:
	/* 0xf11: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f16:
	/* 0xf16: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f1b:
	/* 0xf1b: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_f20:
	/* 0xf20: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f22:
	/* 0xf22: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_f24:
	/* 0xf24: je     1538 <tail_handle_snat_fwd_ipv4+0x1538> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf24, 0x1538, x86_l_1538);
x86_l_f2a:
	/* 0xf2a: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_f2d:
	/* 0xf2d: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_f31:
	/* 0xf31: imul   r15d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R14, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_f35:
	/* 0xf35: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_f39:
	/* 0xf39: add    r15d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_f3c:
	/* 0xf3c: movbe  WORD PTR [rsp+0x10],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_f44:
	/* 0xf44: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_f49:
	/* 0xf49: mov    rdi,QWORD PTR [rip+0x59df] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_f50:
	/* 0xf50: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f55:
	/* 0xf55: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f5a:
	/* 0xf5a: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_f5f:
	/* 0xf5f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f61:
	/* 0xf61: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_f63:
	/* 0xf63: je     1546 <tail_handle_snat_fwd_ipv4+0x1546> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf63, 0x1546, x86_l_1546);
x86_l_f69:
	/* 0xf69: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_f6c:
	/* 0xf6c: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_f70:
	/* 0xf70: imul   r15d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R14, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_f74:
	/* 0xf74: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_f78:
	/* 0xf78: add    r15d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_f7b:
	/* 0xf7b: movbe  WORD PTR [rsp+0x10],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_f83:
	/* 0xf83: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_f88:
	/* 0xf88: mov    rdi,QWORD PTR [rip+0x59df] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_f8f:
	/* 0xf8f: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f94:
	/* 0xf94: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f99:
	/* 0xf99: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_f9e:
	/* 0xf9e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fa0:
	/* 0xfa0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_fa2:
	/* 0xfa2: je     1554 <tail_handle_snat_fwd_ipv4+0x1554> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfa2, 0x1554, x86_l_1554);
x86_l_fa8:
	/* 0xfa8: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_fab:
	/* 0xfab: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_faf:
	/* 0xfaf: imul   r15d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R14, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_fb3:
	/* 0xfb3: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_fb7:
	/* 0xfb7: add    r15d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_fba:
	/* 0xfba: movbe  WORD PTR [rsp+0x10],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_fc2:
	/* 0xfc2: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_fc7:
	/* 0xfc7: mov    rdi,QWORD PTR [rip+0x59df] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_fce:
	/* 0xfce: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fd3:
	/* 0xfd3: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_fd8:
	/* 0xfd8: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_fdd:
	/* 0xfdd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fdf:
	/* 0xfdf: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_fe1:
	/* 0xfe1: je     1562 <tail_handle_snat_fwd_ipv4+0x1562> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfe1, 0x1562, x86_l_1562);
x86_l_fe7:
	/* 0xfe7: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_fea:
	/* 0xfea: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_fee:
	/* 0xfee: imul   r15d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R14, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_ff2:
	/* 0xff2: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_ff6:
	/* 0xff6: add    r15d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_ff9:
	/* 0xff9: movbe  WORD PTR [rsp+0x10],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_1001:
	/* 0x1001: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1006:
	/* 0x1006: mov    rdi,QWORD PTR [rip+0x59df] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_100d:
	/* 0x100d: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1012:
	/* 0x1012: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1017:
	/* 0x1017: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_101c:
	/* 0x101c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_101e:
	/* 0x101e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1020:
	/* 0x1020: je     1570 <tail_handle_snat_fwd_ipv4+0x1570> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1020, 0x1570, x86_l_1570);
x86_l_1026:
	/* 0x1026: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1029:
	/* 0x1029: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_102d:
	/* 0x102d: imul   r15d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R14, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_1031:
	/* 0x1031: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1035:
	/* 0x1035: add    r15d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1038:
	/* 0x1038: movbe  WORD PTR [rsp+0x10],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_1040:
	/* 0x1040: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1045:
	/* 0x1045: mov    rdi,QWORD PTR [rip+0x59df] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_104c:
	/* 0x104c: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1051:
	/* 0x1051: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1056:
	/* 0x1056: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_105b:
	/* 0x105b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_105d:
	/* 0x105d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_105f:
	/* 0x105f: je     158b <tail_handle_snat_fwd_ipv4+0x158b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x105f, 0x158b, x86_l_158b);
x86_l_1065:
	/* 0x1065: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1068:
	/* 0x1068: movzx  r12d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_106c:
	/* 0x106c: imul   r12d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_1070:
	/* 0x1070: shr    r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1074:
	/* 0x1074: add    r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1077:
	/* 0x1077: movbe  WORD PTR [rsp+0x10],r12w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_107f:
	/* 0x107f: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1084:
	/* 0x1084: mov    rdi,QWORD PTR [rip+0x59df] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_108b:
	/* 0x108b: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1090:
	/* 0x1090: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1095:
	/* 0x1095: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_109a:
	/* 0x109a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_109c:
	/* 0x109c: mov    r15b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_8, 1ULL);
x86_l_109f:
	/* 0x109f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_10a1:
	/* 0x10a1: je     1596 <tail_handle_snat_fwd_ipv4+0x1596> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10a1, 0x1596, x86_l_1596);
x86_l_10a7:
	/* 0x10a7: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_10aa:
	/* 0x10aa: movzx  r12d,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_10ae:
	/* 0x10ae: imul   r12d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_10b2:
	/* 0x10b2: shr    r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_10b6:
	/* 0x10b6: add    r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_10b9:
	/* 0x10b9: movbe  WORD PTR [rsp+0x10],r12w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_10c1:
	/* 0x10c1: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_10c6:
	/* 0x10c6: mov    rdi,QWORD PTR [rip+0x59df] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_10cd:
	/* 0x10cd: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10d2:
	/* 0x10d2: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_10d7:
	/* 0x10d7: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_10dc:
	/* 0x10dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10de:
	/* 0x10de: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_10e0:
	/* 0x10e0: je     159e <tail_handle_snat_fwd_ipv4+0x159e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10e0, 0x159e, x86_l_159e);
x86_l_10e6:
	/* 0x10e6: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_10e9:
	/* 0x10e9: movzx  r12d,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_10ed:
	/* 0x10ed: imul   r12d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_10f1:
	/* 0x10f1: shr    r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_10f5:
	/* 0x10f5: add    r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_10f8:
	/* 0x10f8: movbe  WORD PTR [rsp+0x10],r12w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_1100:
	/* 0x1100: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1105:
	/* 0x1105: mov    rdi,QWORD PTR [rip+0x59df] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_110c:
	/* 0x110c: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1111:
	/* 0x1111: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1116:
	/* 0x1116: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_111b:
	/* 0x111b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_111d:
	/* 0x111d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_111f:
	/* 0x111f: je     15a6 <tail_handle_snat_fwd_ipv4+0x15a6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x111f, 0x15a6, x86_l_15a6);
x86_l_1125:
	/* 0x1125: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1128:
	/* 0x1128: movzx  r12d,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_112c:
	/* 0x112c: imul   r12d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_1130:
	/* 0x1130: shr    r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1134:
	/* 0x1134: add    r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1137:
	/* 0x1137: movbe  WORD PTR [rsp+0x10],r12w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_113f:
	/* 0x113f: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1144:
	/* 0x1144: mov    rdi,QWORD PTR [rip+0x59df] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_114b:
	/* 0x114b: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1150:
	/* 0x1150: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1155:
	/* 0x1155: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_115a:
	/* 0x115a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_115c:
	/* 0x115c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_115e:
	/* 0x115e: je     15ae <tail_handle_snat_fwd_ipv4+0x15ae> */
	X86_SIM_X86_JCC(X86_CC_E, 0x115e, 0x15ae, x86_l_15ae);
x86_l_1164:
	/* 0x1164: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1167:
	/* 0x1167: movzx  r12d,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_116b:
	/* 0x116b: imul   r12d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_116f:
	/* 0x116f: shr    r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1173:
	/* 0x1173: add    r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1176:
	/* 0x1176: movbe  WORD PTR [rsp+0x10],r12w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_117e:
	/* 0x117e: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1183:
	/* 0x1183: mov    rdi,QWORD PTR [rip+0x59df] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_118a:
	/* 0x118a: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_118f:
	/* 0x118f: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1194:
	/* 0x1194: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1199:
	/* 0x1199: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_119b:
	/* 0x119b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_119d:
	/* 0x119d: je     15b6 <tail_handle_snat_fwd_ipv4+0x15b6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x119d, 0x15b6, x86_l_15b6);
x86_l_11a3:
	/* 0x11a3: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_11a6:
	/* 0x11a6: movzx  r12d,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_11aa:
	/* 0x11aa: imul   r12d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_11ae:
	/* 0x11ae: shr    r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_11b2:
	/* 0x11b2: add    r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_11b5:
	/* 0x11b5: movbe  WORD PTR [rsp+0x10],r12w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_11bd:
	/* 0x11bd: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_11c2:
	/* 0x11c2: mov    rdi,QWORD PTR [rip+0x59df] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_11c9:
	/* 0x11c9: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11ce:
	/* 0x11ce: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_11d3:
	/* 0x11d3: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_11d8:
	/* 0x11d8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11da:
	/* 0x11da: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_11dc:
	/* 0x11dc: je     15be <tail_handle_snat_fwd_ipv4+0x15be> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11dc, 0x15be, x86_l_15be);
x86_l_11e2:
	/* 0x11e2: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_11e5:
	/* 0x11e5: movzx  r12d,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_11e9:
	/* 0x11e9: imul   r12d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_11ed:
	/* 0x11ed: shr    r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_11f1:
	/* 0x11f1: add    r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_11f4:
	/* 0x11f4: movbe  WORD PTR [rsp+0x10],r12w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_11fc:
	/* 0x11fc: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1201:
	/* 0x1201: mov    rdi,QWORD PTR [rip+0x59df] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_1208:
	/* 0x1208: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_120d:
	/* 0x120d: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1212:
	/* 0x1212: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1217:
	/* 0x1217: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1219:
	/* 0x1219: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_121b:
	/* 0x121b: je     15c6 <tail_handle_snat_fwd_ipv4+0x15c6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x121b, 0x15c6, x86_l_15c6);
x86_l_1221:
	/* 0x1221: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1224:
	/* 0x1224: movzx  r12d,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1228:
	/* 0x1228: imul   r12d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_122c:
	/* 0x122c: shr    r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1230:
	/* 0x1230: add    r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1233:
	/* 0x1233: movbe  WORD PTR [rsp+0x10],r12w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_123b:
	/* 0x123b: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1240:
	/* 0x1240: mov    rdi,QWORD PTR [rip+0x59df] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_1247:
	/* 0x1247: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_124c:
	/* 0x124c: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1251:
	/* 0x1251: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1256:
	/* 0x1256: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1258:
	/* 0x1258: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_125a:
	/* 0x125a: je     15ce <tail_handle_snat_fwd_ipv4+0x15ce> */
	X86_SIM_X86_JCC(X86_CC_E, 0x125a, 0x15ce, x86_l_15ce);
x86_l_1260:
	/* 0x1260: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1263:
	/* 0x1263: movzx  r12d,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1267:
	/* 0x1267: imul   r12d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_126b:
	/* 0x126b: shr    r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_126f:
	/* 0x126f: add    r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1272:
	/* 0x1272: movbe  WORD PTR [rsp+0x10],r12w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_127a:
	/* 0x127a: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_127f:
	/* 0x127f: mov    rdi,QWORD PTR [rip+0x59df] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_1286:
	/* 0x1286: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_128b:
	/* 0x128b: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1290:
	/* 0x1290: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1295:
	/* 0x1295: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1297:
	/* 0x1297: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1299:
	/* 0x1299: je     15d6 <tail_handle_snat_fwd_ipv4+0x15d6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1299, 0x15d6, x86_l_15d6);
x86_l_129f:
	/* 0x129f: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_12a2:
	/* 0x12a2: movzx  r12d,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_12a6:
	/* 0x12a6: imul   r12d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_12aa:
	/* 0x12aa: shr    r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_12ae:
	/* 0x12ae: add    r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_12b1:
	/* 0x12b1: movbe  WORD PTR [rsp+0x10],r12w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_12b9:
	/* 0x12b9: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_12be:
	/* 0x12be: mov    rdi,QWORD PTR [rip+0x59df] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_12c5:
	/* 0x12c5: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12ca:
	/* 0x12ca: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_12cf:
	/* 0x12cf: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_12d4:
	/* 0x12d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12d6:
	/* 0x12d6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_12d8:
	/* 0x12d8: je     15de <tail_handle_snat_fwd_ipv4+0x15de> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12d8, 0x15de, x86_l_15de);
x86_l_12de:
	/* 0x12de: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_12e1:
	/* 0x12e1: movzx  r12d,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_12e5:
	/* 0x12e5: imul   r12d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_12e9:
	/* 0x12e9: shr    r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_12ed:
	/* 0x12ed: add    r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_12f0:
	/* 0x12f0: movbe  WORD PTR [rsp+0x10],r12w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_12f8:
	/* 0x12f8: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_12fd:
	/* 0x12fd: mov    rdi,QWORD PTR [rip+0x59df] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_1304:
	/* 0x1304: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1309:
	/* 0x1309: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_130e:
	/* 0x130e: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1313:
	/* 0x1313: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1315:
	/* 0x1315: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1317:
	/* 0x1317: je     15e6 <tail_handle_snat_fwd_ipv4+0x15e6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1317, 0x15e6, x86_l_15e6);
x86_l_131d:
	/* 0x131d: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1320:
	/* 0x1320: movzx  r12d,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1324:
	/* 0x1324: imul   r12d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_1328:
	/* 0x1328: shr    r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_132c:
	/* 0x132c: add    r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_132f:
	/* 0x132f: movbe  WORD PTR [rsp+0x10],r12w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_1337:
	/* 0x1337: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_133c:
	/* 0x133c: mov    rdi,QWORD PTR [rip+0x59df] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_1343:
	/* 0x1343: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1348:
	/* 0x1348: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_134d:
	/* 0x134d: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1352:
	/* 0x1352: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1354:
	/* 0x1354: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1356:
	/* 0x1356: je     15ee <tail_handle_snat_fwd_ipv4+0x15ee> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1356, 0x15ee, x86_l_15ee);
x86_l_135c:
	/* 0x135c: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_135f:
	/* 0x135f: movzx  r12d,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1363:
	/* 0x1363: imul   r12d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_1367:
	/* 0x1367: shr    r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_136b:
	/* 0x136b: add    r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_136e:
	/* 0x136e: movbe  WORD PTR [rsp+0x10],r12w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_1376:
	/* 0x1376: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_137b:
	/* 0x137b: mov    rdi,QWORD PTR [rip+0x59df] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_1382:
	/* 0x1382: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1387:
	/* 0x1387: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_138c:
	/* 0x138c: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1391:
	/* 0x1391: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1393:
	/* 0x1393: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1395:
	/* 0x1395: je     15f6 <tail_handle_snat_fwd_ipv4+0x15f6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1395, 0x15f6, x86_l_15f6);
x86_l_139b:
	/* 0x139b: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_139e:
	/* 0x139e: movzx  r12d,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_13a2:
	/* 0x13a2: imul   r12d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_13a6:
	/* 0x13a6: shr    r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_13aa:
	/* 0x13aa: add    r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_13ad:
	/* 0x13ad: movbe  WORD PTR [rsp+0x10],r12w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_13b5:
	/* 0x13b5: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_13ba:
	/* 0x13ba: mov    rdi,QWORD PTR [rip+0x59df] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_13c1:
	/* 0x13c1: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13c6:
	/* 0x13c6: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_13cb:
	/* 0x13cb: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_13d0:
	/* 0x13d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13d2:
	/* 0x13d2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_13d4:
	/* 0x13d4: je     15fe <tail_handle_snat_fwd_ipv4+0x15fe> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13d4, 0x15fe, x86_l_15fe);
x86_l_13da:
	/* 0x13da: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_13dd:
	/* 0x13dd: movzx  eax,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_13e1:
	/* 0x13e1: imul   r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_13e5:
	/* 0x13e5: shr    r14d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_13e9:
	/* 0x13e9: add    ebp,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R14, X86_WIDTH_32, X86_ALU_ADD);
x86_l_13ec:
	/* 0x13ec: movbe  WORD PTR [rsp+0x10],bp */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_13f3:
	/* 0x13f3: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_13f8:
	/* 0x13f8: mov    rdi,QWORD PTR [rip+0x59df] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_13ff:
	/* 0x13ff: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1404:
	/* 0x1404: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1409:
	/* 0x1409: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_140e:
	/* 0x140e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1410:
	/* 0x1410: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1412:
	/* 0x1412: je     1606 <tail_handle_snat_fwd_ipv4+0x1606> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1412, 0x1606, x86_l_1606);
x86_l_1418:
	/* 0x1418: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_141d:
	/* 0x141d: mov    DWORD PTR [rsp+0x9c],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 670014898208ULL);
x86_l_1428:
	/* 0x1428: mov    rdi,QWORD PTR [rip+0x59df] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_alloc_retries)));
x86_l_142f:
	/* 0x142f: lea    rsi,[rsp+0x9c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_1437:
	/* 0x1437: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1439:
	/* 0x1439: mov    r13d,0xffffff59 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967129ULL);
x86_l_143f:
	/* 0x143f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1442:
	/* 0x1442: je     1446 <tail_handle_snat_fwd_ipv4+0x1446> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1442, 0x1446, x86_l_1446);
x86_l_1444:
	/* 0x1444: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1446:
	/* 0x1446: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1448:
	/* 0x1448: lea    r14,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_144d:
	/* 0x144d: jmp    1691 <tail_handle_snat_fwd_ipv4+0x1691> */
	X86_SIM_X86_JMP(0x144d, 0x1691, x86_l_1691);
x86_l_1452:
	/* 0x1452: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1455:
	/* 0x1455: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1458:
	/* 0x1458: jmp    160c <tail_handle_snat_fwd_ipv4+0x160c> */
	X86_SIM_X86_JMP(0x1458, 0x160c, x86_l_160c);
x86_l_145d:
	/* 0x145d: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_1463:
	/* 0x1463: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1466:
	/* 0x1466: jmp    160c <tail_handle_snat_fwd_ipv4+0x160c> */
	X86_SIM_X86_JMP(0x1466, 0x160c, x86_l_160c);
x86_l_146b:
	/* 0x146b: mov    r12d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 3ULL);
x86_l_1471:
	/* 0x1471: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1474:
	/* 0x1474: jmp    160c <tail_handle_snat_fwd_ipv4+0x160c> */
	X86_SIM_X86_JMP(0x1474, 0x160c, x86_l_160c);
x86_l_1479:
	/* 0x1479: mov    r12d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4ULL);
x86_l_147f:
	/* 0x147f: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1482:
	/* 0x1482: jmp    160c <tail_handle_snat_fwd_ipv4+0x160c> */
	X86_SIM_X86_JMP(0x1482, 0x160c, x86_l_160c);
x86_l_1487:
	/* 0x1487: mov    r12d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 5ULL);
x86_l_148d:
	/* 0x148d: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1490:
	/* 0x1490: jmp    160c <tail_handle_snat_fwd_ipv4+0x160c> */
	X86_SIM_X86_JMP(0x1490, 0x160c, x86_l_160c);
x86_l_1495:
	/* 0x1495: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_149a:
	/* 0x149a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_149c:
	/* 0x149c: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_149e:
	/* 0x149e: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_14a2:
	/* 0x14a2: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_14ac:
	/* 0x14ac: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_14af:
	/* 0x14af: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_14b4:
	/* 0x14b4: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_14b8:
	/* 0x14b8: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_14bd:
	/* 0x14bd: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_14c2:
	/* 0x14c2: mov    rdi,QWORD PTR [rip+0x59df] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_14c9:
	/* 0x14c9: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_14ce:
	/* 0x14ce: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_14d3:
	/* 0x14d3: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14d5:
	/* 0x14d5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14d7:
	/* 0x14d7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_14d9:
	/* 0x14d9: js     14e5 <tail_handle_snat_fwd_ipv4+0x14e5> */
	X86_SIM_X86_JCC(X86_CC_S, 0x14d9, 0x14e5, x86_l_14e5);
x86_l_14db:
	/* 0x14db: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14dd:
	/* 0x14dd: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14e0:
	/* 0x14e0: jmp    16c4 <tail_handle_snat_fwd_ipv4+0x16c4> */
	X86_SIM_X86_JMP(0x14e0, 0x16c4, x86_l_16c4);
x86_l_14e5:
	/* 0x14e5: mov    ebp,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_14e7:
	/* 0x14e7: mov    r13d,0xffffff59 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967129ULL);
x86_l_14ed:
	/* 0x14ed: jmp    16c4 <tail_handle_snat_fwd_ipv4+0x16c4> */
	X86_SIM_X86_JMP(0x14ed, 0x16c4, x86_l_16c4);
x86_l_14f2:
	/* 0x14f2: mov    r12d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 6ULL);
x86_l_14f8:
	/* 0x14f8: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14fb:
	/* 0x14fb: jmp    160c <tail_handle_snat_fwd_ipv4+0x160c> */
	X86_SIM_X86_JMP(0x14fb, 0x160c, x86_l_160c);
x86_l_1500:
	/* 0x1500: mov    r12d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 7ULL);
x86_l_1506:
	/* 0x1506: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1509:
	/* 0x1509: jmp    160c <tail_handle_snat_fwd_ipv4+0x160c> */
	X86_SIM_X86_JMP(0x1509, 0x160c, x86_l_160c);
x86_l_150e:
	/* 0x150e: mov    r12d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 8ULL);
x86_l_1514:
	/* 0x1514: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1517:
	/* 0x1517: jmp    160c <tail_handle_snat_fwd_ipv4+0x160c> */
	X86_SIM_X86_JMP(0x1517, 0x160c, x86_l_160c);
x86_l_151c:
	/* 0x151c: mov    r12d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 9ULL);
x86_l_1522:
	/* 0x1522: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1525:
	/* 0x1525: jmp    160c <tail_handle_snat_fwd_ipv4+0x160c> */
	X86_SIM_X86_JMP(0x1525, 0x160c, x86_l_160c);
x86_l_152a:
	/* 0x152a: mov    r12d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 10ULL);
x86_l_1530:
	/* 0x1530: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1533:
	/* 0x1533: jmp    160c <tail_handle_snat_fwd_ipv4+0x160c> */
	X86_SIM_X86_JMP(0x1533, 0x160c, x86_l_160c);
x86_l_1538:
	/* 0x1538: mov    r12d,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 11ULL);
x86_l_153e:
	/* 0x153e: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1541:
	/* 0x1541: jmp    160c <tail_handle_snat_fwd_ipv4+0x160c> */
	X86_SIM_X86_JMP(0x1541, 0x160c, x86_l_160c);
x86_l_1546:
	/* 0x1546: mov    r12d,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 12ULL);
x86_l_154c:
	/* 0x154c: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_154f:
	/* 0x154f: jmp    160c <tail_handle_snat_fwd_ipv4+0x160c> */
	X86_SIM_X86_JMP(0x154f, 0x160c, x86_l_160c);
x86_l_1554:
	/* 0x1554: mov    r12d,0xd */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 13ULL);
x86_l_155a:
	/* 0x155a: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_155d:
	/* 0x155d: jmp    160c <tail_handle_snat_fwd_ipv4+0x160c> */
	X86_SIM_X86_JMP(0x155d, 0x160c, x86_l_160c);
x86_l_1562:
	/* 0x1562: mov    r12d,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 14ULL);
x86_l_1568:
	/* 0x1568: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_156b:
	/* 0x156b: jmp    160c <tail_handle_snat_fwd_ipv4+0x160c> */
	X86_SIM_X86_JMP(0x156b, 0x160c, x86_l_160c);
x86_l_1570:
	/* 0x1570: mov    r12d,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 15ULL);
x86_l_1576:
	/* 0x1576: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1579:
	/* 0x1579: jmp    160c <tail_handle_snat_fwd_ipv4+0x160c> */
	X86_SIM_X86_JMP(0x1579, 0x160c, x86_l_160c);
x86_l_157e:
	/* 0x157e: mov    ebp,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_1580:
	/* 0x1580: mov    r13d,0xffffff65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967141ULL);
x86_l_1586:
	/* 0x1586: jmp    18ad <tail_handle_snat_fwd_ipv4+0x18ad> */
	X86_SIM_X86_JMP(0x1586, 0x18ad, x86_l_18ad);
x86_l_158b:
	/* 0x158b: mov    r12d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 16ULL);
x86_l_1591:
	/* 0x1591: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1594:
	/* 0x1594: jmp    160c <tail_handle_snat_fwd_ipv4+0x160c> */
	X86_SIM_X86_JMP(0x1594, 0x160c, x86_l_160c);
x86_l_1596:
	/* 0x1596: mov    r12d,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 17ULL);
x86_l_159c:
	/* 0x159c: jmp    160c <tail_handle_snat_fwd_ipv4+0x160c> */
	X86_SIM_X86_JMP(0x159c, 0x160c, x86_l_160c);
x86_l_159e:
	/* 0x159e: mov    r12d,0x12 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 18ULL);
x86_l_15a4:
	/* 0x15a4: jmp    160c <tail_handle_snat_fwd_ipv4+0x160c> */
	X86_SIM_X86_JMP(0x15a4, 0x160c, x86_l_160c);
x86_l_15a6:
	/* 0x15a6: mov    r12d,0x13 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 19ULL);
x86_l_15ac:
	/* 0x15ac: jmp    160c <tail_handle_snat_fwd_ipv4+0x160c> */
	X86_SIM_X86_JMP(0x15ac, 0x160c, x86_l_160c);
x86_l_15ae:
	/* 0x15ae: mov    r12d,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 20ULL);
x86_l_15b4:
	/* 0x15b4: jmp    160c <tail_handle_snat_fwd_ipv4+0x160c> */
	X86_SIM_X86_JMP(0x15b4, 0x160c, x86_l_160c);
x86_l_15b6:
	/* 0x15b6: mov    r12d,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 21ULL);
x86_l_15bc:
	/* 0x15bc: jmp    160c <tail_handle_snat_fwd_ipv4+0x160c> */
	X86_SIM_X86_JMP(0x15bc, 0x160c, x86_l_160c);
x86_l_15be:
	/* 0x15be: mov    r12d,0x16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 22ULL);
x86_l_15c4:
	/* 0x15c4: jmp    160c <tail_handle_snat_fwd_ipv4+0x160c> */
	X86_SIM_X86_JMP(0x15c4, 0x160c, x86_l_160c);
x86_l_15c6:
	/* 0x15c6: mov    r12d,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 23ULL);
x86_l_15cc:
	/* 0x15cc: jmp    160c <tail_handle_snat_fwd_ipv4+0x160c> */
	X86_SIM_X86_JMP(0x15cc, 0x160c, x86_l_160c);
x86_l_15ce:
	/* 0x15ce: mov    r12d,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 24ULL);
x86_l_15d4:
	/* 0x15d4: jmp    160c <tail_handle_snat_fwd_ipv4+0x160c> */
	X86_SIM_X86_JMP(0x15d4, 0x160c, x86_l_160c);
x86_l_15d6:
	/* 0x15d6: mov    r12d,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 25ULL);
x86_l_15dc:
	/* 0x15dc: jmp    160c <tail_handle_snat_fwd_ipv4+0x160c> */
	X86_SIM_X86_JMP(0x15dc, 0x160c, x86_l_160c);
x86_l_15de:
	/* 0x15de: mov    r12d,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 26ULL);
x86_l_15e4:
	/* 0x15e4: jmp    160c <tail_handle_snat_fwd_ipv4+0x160c> */
	X86_SIM_X86_JMP(0x15e4, 0x160c, x86_l_160c);
x86_l_15e6:
	/* 0x15e6: mov    r12d,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 27ULL);
x86_l_15ec:
	/* 0x15ec: jmp    160c <tail_handle_snat_fwd_ipv4+0x160c> */
	X86_SIM_X86_JMP(0x15ec, 0x160c, x86_l_160c);
x86_l_15ee:
	/* 0x15ee: mov    r12d,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 28ULL);
x86_l_15f4:
	/* 0x15f4: jmp    160c <tail_handle_snat_fwd_ipv4+0x160c> */
	X86_SIM_X86_JMP(0x15f4, 0x160c, x86_l_160c);
x86_l_15f6:
	/* 0x15f6: mov    r12d,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 29ULL);
x86_l_15fc:
	/* 0x15fc: jmp    160c <tail_handle_snat_fwd_ipv4+0x160c> */
	X86_SIM_X86_JMP(0x15fc, 0x160c, x86_l_160c);
x86_l_15fe:
	/* 0x15fe: mov    r12d,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 30ULL);
x86_l_1604:
	/* 0x1604: jmp    160c <tail_handle_snat_fwd_ipv4+0x160c> */
	X86_SIM_X86_JMP(0x1604, 0x160c, x86_l_160c);
x86_l_1606:
	/* 0x1606: mov    r12d,0x1f */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 31ULL);
x86_l_160c:
	/* 0x160c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1611:
	/* 0x1611: mov    DWORD PTR [rsp+0x9c],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_1619:
	/* 0x1619: mov    rdi,QWORD PTR [rip+0x59df] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_alloc_retries)));
x86_l_1620:
	/* 0x1620: lea    rsi,[rsp+0x9c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_1628:
	/* 0x1628: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_162a:
	/* 0x162a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_162d:
	/* 0x162d: je     1631 <tail_handle_snat_fwd_ipv4+0x1631> */
	X86_SIM_X86_JCC(X86_CC_E, 0x162d, 0x1631, x86_l_1631);
x86_l_162f:
	/* 0x162f: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1631:
	/* 0x1631: movzx  eax,WORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_1636:
	/* 0x1636: mov    WORD PTR [rsp+0x94],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_163e:
	/* 0x163e: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1643:
	/* 0x1643: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1648:
	/* 0x1648: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_164d:
	/* 0x164d: mov    rdi,QWORD PTR [rip+0x59df] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_1654:
	/* 0x1654: lea    rsi,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1659:
	/* 0x1659: lea    rdx,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_165e:
	/* 0x165e: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1660:
	/* 0x1660: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1662:
	/* 0x1662: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1664:
	/* 0x1664: mov    r13d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_1667:
	/* 0x1667: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1669:
	/* 0x1669: lea    r14,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_166e:
	/* 0x166e: jns    168c <tail_handle_snat_fwd_ipv4+0x168c> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x166e, 0x168c, x86_l_168c);
x86_l_1670:
	/* 0x1670: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1675:
	/* 0x1675: mov    rdi,QWORD PTR [rip+0x59df] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_167c:
	/* 0x167c: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1681:
	/* 0x1681: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1683:
	/* 0x1683: mov    ebp,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R13, X86_WIDTH_32);
x86_l_1686:
	/* 0x1686: mov    r13d,0xffffff59 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967129ULL);
x86_l_168c:
	/* 0x168c: test   r15b,r15b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_8);
x86_l_168f:
	/* 0x168f: je     16c1 <tail_handle_snat_fwd_ipv4+0x16c1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x168f, 0x16c1, x86_l_16c1);
x86_l_1691:
	/* 0x1691: mov    QWORD PTR [rsp+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_169d:
	/* 0x169d: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_16a2:
	/* 0x16a2: mov    rsi,QWORD PTR [rip+0x59df] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_signals)));
x86_l_16a9:
	/* 0x16a9: lea    rcx,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_16b1:
	/* 0x16b1: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_16b6:
	/* 0x16b6: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_16b9:
	/* 0x16b9: mov    r8d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 8ULL);
x86_l_16bf:
	/* 0x16bf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16c1:
	/* 0x16c1: mov    r15,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R14, X86_WIDTH_64);
x86_l_16c4:
	/* 0x16c4: mov    r11d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_16c9:
	/* 0x16c9: test   r13d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_32);
x86_l_16cc:
	/* 0x16cc: js     18b2 <tail_handle_snat_fwd_ipv4+0x18b2> */
	X86_SIM_X86_JCC(X86_CC_S, 0x16cc, 0x18b2, x86_l_18b2);
x86_l_16d2:
	/* 0x16d2: movzx  r14d,WORD PTR [r15+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_16d7:
	/* 0x16d7: movzx  edx,BYTE PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 40ULL);
x86_l_16dc:
	/* 0x16dc: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_16e0:
	/* 0x16e0: mov    r15d,DWORD PTR [r15+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_16e4:
	/* 0x16e4: movzx  r12d,WORD PTR [rsp+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_16ea:
	/* 0x16ea: mov    DWORD PTR [rsp+0x30],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_16ef:
	/* 0x16ef: cmp    eax,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_16f2:
	/* 0x16f2: jne    1701 <tail_handle_snat_fwd_ipv4+0x1701> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x16f2, 0x1701, x86_l_1701);
x86_l_16f4:
	/* 0x16f4: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16f7:
	/* 0x16f7: cmp    r12w,r14w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_R14, X86_WIDTH_16);
x86_l_16fb:
	/* 0x16fb: je     18b2 <tail_handle_snat_fwd_ipv4+0x18b2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x16fb, 0x18b2, x86_l_18b2);
x86_l_1701:
	/* 0x1701: mov    DWORD PTR [rsp+0x68],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1705:
	/* 0x1705: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1707:
	/* 0x1707: add    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_170a:
	/* 0x170a: adc    r15d,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_170e:
	/* 0x170e: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_1713:
	/* 0x1713: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1718:
	/* 0x1718: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_171b:
	/* 0x171b: mov    esi,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 26ULL);
x86_l_1720:
	/* 0x1720: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1725:
	/* 0x1725: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1728:
	/* 0x1728: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_172a:
	/* 0x172a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_172c:
	/* 0x172c: js     18a7 <tail_handle_snat_fwd_ipv4+0x18a7> */
	X86_SIM_X86_JCC(X86_CC_S, 0x172c, 0x18a7, x86_l_18a7);
x86_l_1732:
	/* 0x1732: mov    eax,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_1737:
	/* 0x1737: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_173a:
	/* 0x173a: mov    esi,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 24ULL);
x86_l_173f:
	/* 0x173f: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1741:
	/* 0x1741: mov    ecx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_32);
x86_l_1744:
	/* 0x1744: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1747:
	/* 0x1747: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1749:
	/* 0x1749: mov    r13d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_174c:
	/* 0x174c: sar    r13d,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SAR, 31ULL);
x86_l_1750:
	/* 0x1750: and    r13d,0xffffff67 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4294967143ULL);
x86_l_1757:
	/* 0x1757: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1759:
	/* 0x1759: js     18ad <tail_handle_snat_fwd_ipv4+0x18ad> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1759, 0x18ad, x86_l_18ad);
x86_l_175f:
	/* 0x175f: cmp    QWORD PTR [rsp+0xc0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_1768:
	/* 0x1768: mov    r11d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_176d:
	/* 0x176d: mov    rcx,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1775:
	/* 0x1775: mov    eax,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1779:
	/* 0x1779: jne    18b2 <tail_handle_snat_fwd_ipv4+0x18b2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1779, 0x18b2, x86_l_18b2);
x86_l_177f:
	/* 0x177f: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1782:
	/* 0x1782: cmp    eax,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 58ULL);
x86_l_1785:
	/* 0x1785: je     17a3 <tail_handle_snat_fwd_ipv4+0x17a3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1785, 0x17a3, x86_l_17a3);
x86_l_1787:
	/* 0x1787: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_178a:
	/* 0x178a: je     1797 <tail_handle_snat_fwd_ipv4+0x1797> */
	X86_SIM_X86_JCC(X86_CC_E, 0x178a, 0x1797, x86_l_1797);
x86_l_178c:
	/* 0x178c: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_178f:
	/* 0x178f: jne    17a9 <tail_handle_snat_fwd_ipv4+0x17a9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x178f, 0x17a9, x86_l_17a9);
x86_l_1791:
	/* 0x1791: mov    dx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_16, 16ULL);
x86_l_1795:
	/* 0x1795: jmp    17ab <tail_handle_snat_fwd_ipv4+0x17ab> */
	X86_SIM_X86_JMP(0x1795, 0x17ab, x86_l_17ab);
x86_l_1797:
	/* 0x1797: mov    r8d,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 32ULL);
x86_l_179d:
	/* 0x179d: mov    dx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_16, 6ULL);
x86_l_17a1:
	/* 0x17a1: jmp    17ab <tail_handle_snat_fwd_ipv4+0x17ab> */
	X86_SIM_X86_JMP(0x17a1, 0x17ab, x86_l_17ab);
x86_l_17a3:
	/* 0x17a3: mov    dx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_16, 2ULL);
x86_l_17a7:
	/* 0x17a7: jmp    17ab <tail_handle_snat_fwd_ipv4+0x17ab> */
	X86_SIM_X86_JMP(0x17a7, 0x17ab, x86_l_17ab);
x86_l_17a9:
	/* 0x17a9: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17ab:
	/* 0x17ab: cmp    r12w,r14w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_R14, X86_WIDTH_16);
x86_l_17af:
	/* 0x17af: jne    17f7 <tail_handle_snat_fwd_ipv4+0x17f7> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x17af, 0x17f7, x86_l_17f7);
x86_l_17b1:
	/* 0x17b1: test   dx,dx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_16);
x86_l_17b4:
	/* 0x17b4: je     193c <tail_handle_snat_fwd_ipv4+0x193c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x17b4, 0x193c, x86_l_193c);
x86_l_17ba:
	/* 0x17ba: movzx  esi,dx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RDX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_17bd:
	/* 0x17bd: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_17bf:
	/* 0x17bf: or     r8d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 16ULL);
x86_l_17c3:
	/* 0x17c3: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_17c8:
	/* 0x17c8: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_17cb:
	/* 0x17cb: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17cd:
	/* 0x17cd: mov    ecx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_32);
x86_l_17d0:
	/* 0x17d0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17d2:
	/* 0x17d2: mov    r11d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_17d7:
	/* 0x17d7: mov    r13d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_17da:
	/* 0x17da: sar    r13d,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SAR, 31ULL);
x86_l_17de:
	/* 0x17de: and    r13d,0xffffff66 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4294967142ULL);
x86_l_17e5:
	/* 0x17e5: cmp    r13d,0xffffff53 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4294967123ULL);
x86_l_17ec:
	/* 0x17ec: jne    194c <tail_handle_snat_fwd_ipv4+0x194c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x17ec, 0x194c, x86_l_194c);
x86_l_17f2:
	/* 0x17f2: jmp    18bf <tail_handle_snat_fwd_ipv4+0x18bf> */
	X86_SIM_X86_JMP(0x17f2, 0x18bf, x86_l_18bf);
x86_l_17f7:
	/* 0x17f7: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_17fa:
	/* 0x17fa: je     1814 <tail_handle_snat_fwd_ipv4+0x1814> */
	X86_SIM_X86_JCC(X86_CC_E, 0x17fa, 0x1814, x86_l_1814);
x86_l_17fc:
	/* 0x17fc: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_17ff:
	/* 0x17ff: je     1814 <tail_handle_snat_fwd_ipv4+0x1814> */
	X86_SIM_X86_JCC(X86_CC_E, 0x17ff, 0x1814, x86_l_1814);
x86_l_1801:
	/* 0x1801: mov    r13d,0xffffff72 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967154ULL);
x86_l_1807:
	/* 0x1807: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_180a:
	/* 0x180a: jne    18b2 <tail_handle_snat_fwd_ipv4+0x18b2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x180a, 0x18b2, x86_l_18b2);
x86_l_1810:
	/* 0x1810: mov    dx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_16, 2ULL);
x86_l_1814:
	/* 0x1814: mov    DWORD PTR [rsp+0x2c],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1818:
	/* 0x1818: mov    DWORD PTR [rsp+0xa0],r8d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1820:
	/* 0x1820: mov    WORD PTR [rsp+0xa8],r14w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1829:
	/* 0x1829: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_182e:
	/* 0x182e: lea    rdx,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1836:
	/* 0x1836: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1839:
	/* 0x1839: mov    esi,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_183b:
	/* 0x183b: mov    r14,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RCX, X86_WIDTH_64);
x86_l_183e:
	/* 0x183e: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1843:
	/* 0x1843: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1846:
	/* 0x1846: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1848:
	/* 0x1848: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_184a:
	/* 0x184a: js     18a7 <tail_handle_snat_fwd_ipv4+0x18a7> */
	X86_SIM_X86_JCC(X86_CC_S, 0x184a, 0x18a7, x86_l_18a7);
x86_l_184c:
	/* 0x184c: movzx  edx,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1850:
	/* 0x1850: movzx  ecx,WORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 168ULL);
x86_l_1858:
	/* 0x1858: movzx  esi,WORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 44ULL);
x86_l_185d:
	/* 0x185d: add    esi,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R14, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1860:
	/* 0x1860: mov    r8d,DWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1868:
	/* 0x1868: or     r8d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_186c:
	/* 0x186c: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_1871:
	/* 0x1871: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1874:
	/* 0x1874: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1876:
	/* 0x1876: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1878:
	/* 0x1878: js     195d <tail_handle_snat_fwd_ipv4+0x195d> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1878, 0x195d, x86_l_195d);
x86_l_187e:
	/* 0x187e: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1881:
	/* 0x1881: cmp    DWORD PTR [rsp+0x68],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 446676598785ULL);
x86_l_1886:
	/* 0x1886: mov    r11d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_188b:
	/* 0x188b: mov    rcx,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1893:
	/* 0x1893: mov    r8d,DWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_189b:
	/* 0x189b: mov    edx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_189f:
	/* 0x189f: jne    17b1 <tail_handle_snat_fwd_ipv4+0x17b1> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x189f, 0x17b1, x86_l_17b1);
x86_l_18a5:
	/* 0x18a5: jmp    18b2 <tail_handle_snat_fwd_ipv4+0x18b2> */
	X86_SIM_X86_JMP(0x18a5, 0x18b2, x86_l_18b2);
x86_l_18a7:
	/* 0x18a7: mov    r13d,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967155ULL);
x86_l_18ad:
	/* 0x18ad: mov    r11d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_18b2:
	/* 0x18b2: cmp    r13d,0xffffff53 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4294967123ULL);
x86_l_18b9:
	/* 0x18b9: jne    194c <tail_handle_snat_fwd_ipv4+0x194c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x18b9, 0x194c, x86_l_194c);
x86_l_18bf:
	/* 0x18bf: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_18c2:
	/* 0x18c2: mov    rcx,QWORD PTR [rip+0x59df] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_interface_ifindex)));
x86_l_18c9:
	/* 0x18c9: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18cb:
	/* 0x18cb: mov    ebx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_32);
x86_l_18cd:
	/* 0x18cd: movabs rax,0x7101bc0200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 485360402944ULL);
x86_l_18d7:
	/* 0x18d7: add    rax,0xa0000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 655360ULL);
x86_l_18dd:
	/* 0x18dd: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_18e2:
	/* 0x18e2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_18e7:
	/* 0x18e7: mov    rdi,QWORD PTR [rip+0x59df] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_18ee:
	/* 0x18ee: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_18f3:
	/* 0x18f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18f5:
	/* 0x18f5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_18f8:
	/* 0x18f8: je     1903 <tail_handle_snat_fwd_ipv4+0x1903> */
	X86_SIM_X86_JCC(X86_CC_E, 0x18f8, 0x1903, x86_l_1903);
x86_l_18fa:
	/* 0x18fa: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_18fd:
	/* 0x18fd: add    QWORD PTR [rax+0x8],rbx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1901:
	/* 0x1901: jmp    192b <tail_handle_snat_fwd_ipv4+0x192b> */
	X86_SIM_X86_JMP(0x1901, 0x192b, x86_l_192b);
x86_l_1903:
	/* 0x1903: mov    QWORD PTR [rsp+0x30],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430209ULL);
x86_l_190c:
	/* 0x190c: mov    QWORD PTR [rsp+0x38],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1911:
	/* 0x1911: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1916:
	/* 0x1916: mov    rdi,QWORD PTR [rip+0x59df] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_191d:
	/* 0x191d: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1922:
	/* 0x1922: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1927:
	/* 0x1927: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1929:
	/* 0x1929: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_192b:
	/* 0x192b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_192d:
	/* 0x192d: add    rsp,0xc8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 200ULL);
x86_l_1934:
	/* 0x1934: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_1936:
	/* 0x1936: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_1937:
	/* 0x1937: jmp    1968 <tail_handle_snat_fwd_ipv4+0x1968> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_193c:
	/* 0x193c: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_193f:
	/* 0x193f: cmp    r13d,0xffffff53 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4294967123ULL);
x86_l_1946:
	/* 0x1946: je     18bf <tail_handle_snat_fwd_ipv4+0x18bf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1946, 0x18bf, x86_l_18bf);
x86_l_194c:
	/* 0x194c: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_194f:
	/* 0x194f: test   r13d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_32);
x86_l_1952:
	/* 0x1952: jns    18c2 <tail_handle_snat_fwd_ipv4+0x18c2> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1952, 0x18c2, x86_l_18c2);
x86_l_1958:
	/* 0x1958: jmp    43 <tail_handle_snat_fwd_ipv4+0x43> */
	X86_SIM_X86_JMP(0x1958, 0x43, x86_l_43);
x86_l_195d:
	/* 0x195d: mov    r13d,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967142ULL);
x86_l_1963:
	/* 0x1963: jmp    18ad <tail_handle_snat_fwd_ipv4+0x18ad> */
	X86_SIM_X86_JMP(0x1963, 0x18ad, x86_l_18ad);
x86_l_1968:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
