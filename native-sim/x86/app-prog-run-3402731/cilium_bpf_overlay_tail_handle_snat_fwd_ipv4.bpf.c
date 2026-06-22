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
	/* 0xa: sub    rsp,0xc8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 200ULL);
x86_l_11:
	/* 0x11: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_14:
	/* 0x14: mov    r11d,DWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_18:
	/* 0x18: mov    QWORD PTR [rdi+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_20:
	/* 0x20: mov    r12,QWORD PTR [rip+0x59e0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&__config_nodeport_port_max)));
x86_l_27:
	/* 0x27: movzx  r10d,WORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2c:
	/* 0x2c: mov    DWORD PTR [rsp+0x24],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 154618822656ULL);
x86_l_34:
	/* 0x34: mov    eax,DWORD PTR [rdi+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_37:
	/* 0x37: sub    eax,DWORD PTR [rdi+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RDI, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_3a:
	/* 0x3a: mov    r13d,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967162ULL);
x86_l_40:
	/* 0x40: cmp    eax,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 34ULL);
x86_l_43:
	/* 0x43: jae    b4 <tail_handle_snat_fwd_ipv4+0xb4> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x43, 0xb4, x86_l_b4);
x86_l_45:
	/* 0x45: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_48:
	/* 0x48: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4a:
	/* 0x4a: neg    r13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_4d:
	/* 0x4d: movzx  ecx,r13b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R13, X86_WIDTH_32, X86_WIDTH_8);
x86_l_51:
	/* 0x51: movzx  edx,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_55:
	/* 0x55: shl    edx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_58:
	/* 0x58: or     edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_5a:
	/* 0x5a: mov    DWORD PTR [rbx+0x28],r11d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_5e:
	/* 0x5e: mov    DWORD PTR [rbx+0x2c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561024ULL);
x86_l_65:
	/* 0x65: mov    DWORD PTR [rbx+0x30],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_68:
	/* 0x68: movabs rdx,0x1bc710200000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 125099143063404544ULL);
x86_l_72:
	/* 0x72: mov    QWORD PTR [rbx+0x34],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_76:
	/* 0x76: mov    r14d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_32);
x86_l_79:
	/* 0x79: movabs rax,0x7101bc0200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 485360402944ULL);
x86_l_83:
	/* 0x83: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_88:
	/* 0x88: mov    BYTE PTR [rsp+0x70],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_8c:
	/* 0x8c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_91:
	/* 0x91: mov    rdi,QWORD PTR [rip+0x59e0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_98:
	/* 0x98: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_9d:
	/* 0x9d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9f:
	/* 0x9f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a2:
	/* 0xa2: je     256 <tail_handle_snat_fwd_ipv4+0x256> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa2, 0x256, x86_l_256);
x86_l_a8:
	/* 0xa8: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_ab:
	/* 0xab: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_af:
	/* 0xaf: jmp    27e <tail_handle_snat_fwd_ipv4+0x27e> */
	X86_SIM_X86_JMP(0xaf, 0x27e, x86_l_27e);
x86_l_b4:
	/* 0xb4: movabs rbp,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 2199023255552ULL);
x86_l_be:
	/* 0xbe: movabs r14,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 1099511627776ULL);
x86_l_c8:
	/* 0xc8: mov    rdx,QWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_cf:
	/* 0xcf: movzx  eax,WORD PTR [rdx+0x12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18ULL);
x86_l_d3:
	/* 0xd3: movzx  ecx,BYTE PTR [rdx+0x17] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 23ULL);
x86_l_d7:
	/* 0xd7: mov    rsi,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RCX, X86_WIDTH_64);
x86_l_da:
	/* 0xda: shl    rsi,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_de:
	/* 0xde: or     rsi,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_e1:
	/* 0xe1: movzx  eax,WORD PTR [rdx+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 20ULL);
x86_l_e5:
	/* 0xe5: lea    rdi,[rsi+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_e9:
	/* 0xe9: test   eax,0xff3f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 65343ULL);
x86_l_ee:
	/* 0xee: cmove  rdi,rsi */
	X86_SIM_L_EXEC_CMOV(X86_RDI, X86_RSI, X86_WIDTH_64, X86_CC_E);
x86_l_f2:
	/* 0xf2: lea    r9,[rdi+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_f6:
	/* 0xf6: test   eax,0xff1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 65311ULL);
x86_l_fb:
	/* 0xfb: cmove  r9,rdi */
	X86_SIM_L_EXEC_CMOV(X86_R9, X86_RDI, X86_WIDTH_64, X86_CC_E);
x86_l_ff:
	/* 0xff: mov    BYTE PTR [rsp+0x28],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_103:
	/* 0x103: mov    eax,DWORD PTR [rdx+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_106:
	/* 0x106: mov    DWORD PTR [rsp+0x1c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_10a:
	/* 0x10a: mov    esi,DWORD PTR [rdx+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_10d:
	/* 0x10d: mov    DWORD PTR [rsp+0x20],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_111:
	/* 0x111: mov    BYTE PTR [rsp+0x29],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 176093659136ULL);
x86_l_116:
	/* 0x116: mov    edx,DWORD PTR [rdx+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_119:
	/* 0x119: cmp    rcx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 17ULL);
x86_l_11d:
	/* 0x11d: je     128 <tail_handle_snat_fwd_ipv4+0x128> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11d, 0x128, x86_l_128);
x86_l_11f:
	/* 0x11f: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_122:
	/* 0x122: jne    18c6 <tail_handle_snat_fwd_ipv4+0x18c6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x122, 0x18c6, x86_l_18c6);
x86_l_128:
	/* 0x128: cmp    esi,0xfffff50a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 4294964490ULL);
x86_l_12e:
	/* 0x12e: jne    18c6 <tail_handle_snat_fwd_ipv4+0x18c6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x12e, 0x18c6, x86_l_18c6);
x86_l_134:
	/* 0x134: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_137:
	/* 0x137: je     142 <tail_handle_snat_fwd_ipv4+0x142> */
	X86_SIM_X86_JCC(X86_CC_E, 0x137, 0x142, x86_l_142);
x86_l_139:
	/* 0x139: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_13c:
	/* 0x13c: jne    18c6 <tail_handle_snat_fwd_ipv4+0x18c6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x13c, 0x18c6, x86_l_18c6);
x86_l_142:
	/* 0x142: mov    rcx,QWORD PTR [rip+0x59e0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_ipv4_fragments)));
x86_l_149:
	/* 0x149: mov    r15,r9 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R9, X86_WIDTH_64);
x86_l_14c:
	/* 0x14c: mov    r13d,0xffffff63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967139ULL);
x86_l_152:
	/* 0x152: and    r15,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_155:
	/* 0x155: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_158:
	/* 0x158: jne    163 <tail_handle_snat_fwd_ipv4+0x163> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x158, 0x163, x86_l_163);
x86_l_15a:
	/* 0x15a: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_15d:
	/* 0x15d: jne    45 <tail_handle_snat_fwd_ipv4+0x45> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x15d, 0x45, x86_l_45);
x86_l_163:
	/* 0x163: and    edx,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_166:
	/* 0x166: lea    esi,[rdx*4+0xe] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 2), 14ULL);
x86_l_16d:
	/* 0x16d: lea    rdx,[rsp+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_172:
	/* 0x172: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_175:
	/* 0x175: mov    DWORD PTR [rsp+0x18],r11d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_17a:
	/* 0x17a: mov    QWORD PTR [rsp+0x68],r10 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R10, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_17f:
	/* 0x17f: mov    QWORD PTR [rsp+0xb8],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_187:
	/* 0x187: je     29e <tail_handle_snat_fwd_ipv4+0x29e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x187, 0x29e, x86_l_29e);
x86_l_18d:
	/* 0x18d: mov    DWORD PTR [rsp+0x70],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_191:
	/* 0x191: mov    DWORD PTR [rsp+0x74],0xfffff50a */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 502511170826ULL);
x86_l_199:
	/* 0x199: mov    WORD PTR [rsp+0x78],r9w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_19f:
	/* 0x19f: mov    rax,r9 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R9, X86_WIDTH_64);
x86_l_1a2:
	/* 0x1a2: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_1a6:
	/* 0x1a6: mov    BYTE PTR [rsp+0x7a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 122ULL);
x86_l_1aa:
	/* 0x1aa: mov    BYTE PTR [rsp+0x7b],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 528280977408ULL);
x86_l_1af:
	/* 0x1af: mov    r13,r9 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R9, X86_WIDTH_64);
x86_l_1b2:
	/* 0x1b2: test   r9,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R9, X86_RBP, X86_WIDTH_64);
x86_l_1b5:
	/* 0x1b5: jne    724 <tail_handle_snat_fwd_ipv4+0x724> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1b5, 0x724, x86_l_724);
x86_l_1bb:
	/* 0x1bb: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1c0:
	/* 0x1c0: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1c3:
	/* 0x1c3: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1c8:
	/* 0x1c8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ca:
	/* 0x1ca: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1cc:
	/* 0x1cc: js     346 <tail_handle_snat_fwd_ipv4+0x346> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1cc, 0x346, x86_l_346);
x86_l_1d2:
	/* 0x1d2: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1d5:
	/* 0x1d5: test   r13,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R14, X86_WIDTH_64);
x86_l_1d8:
	/* 0x1d8: je     2c9 <tail_handle_snat_fwd_ipv4+0x2c9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1d8, 0x2c9, x86_l_2c9);
x86_l_1de:
	/* 0x1de: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1e3:
	/* 0x1e3: mov    rdi,QWORD PTR [rip+0x59e0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv4_frag_datagrams)));
x86_l_1ea:
	/* 0x1ea: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1ef:
	/* 0x1ef: lea    rdx,[rsp+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1f4:
	/* 0x1f4: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f6:
	/* 0x1f6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f8:
	/* 0x1f8: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_1fb:
	/* 0x1fb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1fd:
	/* 0x1fd: je     2c9 <tail_handle_snat_fwd_ipv4+0x2c9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1fd, 0x2c9, x86_l_2c9);
x86_l_203:
	/* 0x203: mov    r14d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_207:
	/* 0x207: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_210:
	/* 0x210: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_219:
	/* 0x219: movabs rax,0x6b0085020a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 459570217482ULL);
x86_l_223:
	/* 0x223: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_22b:
	/* 0x22b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_230:
	/* 0x230: mov    rdi,QWORD PTR [rip+0x59e0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_237:
	/* 0x237: lea    rsi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_23f:
	/* 0x23f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_241:
	/* 0x241: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_244:
	/* 0x244: je     765 <tail_handle_snat_fwd_ipv4+0x765> */
	X86_SIM_X86_JCC(X86_CC_E, 0x244, 0x765, x86_l_765);
x86_l_24a:
	/* 0x24a: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_24d:
	/* 0x24d: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_251:
	/* 0x251: jmp    742 <tail_handle_snat_fwd_ipv4+0x742> */
	X86_SIM_X86_JMP(0x251, 0x742, x86_l_742);
x86_l_256:
	/* 0x256: mov    QWORD PTR [rsp+0x30],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430209ULL);
x86_l_25f:
	/* 0x25f: mov    QWORD PTR [rsp+0x38],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_264:
	/* 0x264: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_269:
	/* 0x269: mov    rdi,QWORD PTR [rip+0x59e0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_270:
	/* 0x270: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_275:
	/* 0x275: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_27a:
	/* 0x27a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_27c:
	/* 0x27c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27e:
	/* 0x27e: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_283:
	/* 0x283: mov    rsi,QWORD PTR [rip+0x59e0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_28a:
	/* 0x28a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_28d:
	/* 0x28d: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_292:
	/* 0x292: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_294:
	/* 0x294: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_299:
	/* 0x299: jmp    1934 <tail_handle_snat_fwd_ipv4+0x1934> */
	X86_SIM_X86_JMP(0x299, 0x1934, x86_l_1934);
x86_l_29e:
	/* 0x29e: test   r9,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R9, X86_RBP, X86_WIDTH_64);
x86_l_2a1:
	/* 0x2a1: jne    45 <tail_handle_snat_fwd_ipv4+0x45> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2a1, 0x45, x86_l_45);
x86_l_2a7:
	/* 0x2a7: mov    r14,r9 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R9, X86_WIDTH_64);
x86_l_2aa:
	/* 0x2aa: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_2af:
	/* 0x2af: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2b2:
	/* 0x2b2: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2b7:
	/* 0x2b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b9:
	/* 0x2b9: mov    r11d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2be:
	/* 0x2be: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2c0:
	/* 0x2c0: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_2c3:
	/* 0x2c3: js     3ea <tail_handle_snat_fwd_ipv4+0x3ea> */
	X86_SIM_X86_JCC(X86_CC_S, 0x2c3, 0x3ea, x86_l_3ea);
x86_l_2c9:
	/* 0x2c9: movzx  eax,WORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_2ce:
	/* 0x2ce: movzx  ecx,WORD PTR [rsp+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_2d3:
	/* 0x2d3: mov    WORD PTR [rsp+0x26],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_2d8:
	/* 0x2d8: mov    WORD PTR [rsp+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2dd:
	/* 0x2dd: rol    ax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_2e1:
	/* 0x2e1: movzx  ecx,WORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2e6:
	/* 0x2e6: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_2e8:
	/* 0x2e8: cmp    ax,cx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_16);
x86_l_2eb:
	/* 0x2eb: jb     18c6 <tail_handle_snat_fwd_ipv4+0x18c6> */
	X86_SIM_X86_JCC(X86_CC_B, 0x2eb, 0x18c6, x86_l_18c6);
x86_l_2f1:
	/* 0x2f1: mov    r12,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDX, X86_WIDTH_64);
x86_l_2f4:
	/* 0x2f4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f9:
	/* 0x2f9: mov    rdi,QWORD PTR [rip+0x59e0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_300:
	/* 0x300: lea    rsi,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_305:
	/* 0x305: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_307:
	/* 0x307: movzx  ecx,WORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 40ULL);
x86_l_30c:
	/* 0x30c: mov    WORD PTR [rsp+0x7c],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_311:
	/* 0x311: mov    edx,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_315:
	/* 0x315: mov    DWORD PTR [rsp+0x78],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_319:
	/* 0x319: mov    rdx,QWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_31e:
	/* 0x31e: mov    DWORD PTR [rsp+0x74],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_322:
	/* 0x322: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_32a:
	/* 0x32a: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_32e:
	/* 0x32e: mov    DWORD PTR [rsp+0x70],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_332:
	/* 0x332: movzx  r14d,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_336:
	/* 0x336: cmp    r14w,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_16, 6ULL);
x86_l_33b:
	/* 0x33b: jne    356 <tail_handle_snat_fwd_ipv4+0x356> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x33b, 0x356, x86_l_356);
x86_l_33d:
	/* 0x33d: mov    rdi,QWORD PTR [rip+0x59e0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct4_global)));
x86_l_344:
	/* 0x344: jmp    35d <tail_handle_snat_fwd_ipv4+0x35d> */
	X86_SIM_X86_JMP(0x344, 0x35d, x86_l_35d);
x86_l_346:
	/* 0x346: mov    r13d,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967161ULL);
x86_l_34c:
	/* 0x34c: mov    r11d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_351:
	/* 0x351: jmp    45 <tail_handle_snat_fwd_ipv4+0x45> */
	X86_SIM_X86_JMP(0x351, 0x45, x86_l_45);
x86_l_356:
	/* 0x356: mov    rdi,QWORD PTR [rip+0x59e0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct_any4_global)));
x86_l_35d:
	/* 0x35d: mov    r13,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_365:
	/* 0x365: mov    rax,QWORD PTR [rip+0x59e0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_ipv4_fragments)));
x86_l_36c:
	/* 0x36c: mov    BYTE PTR [rsp+0x7d],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 536870912000ULL);
x86_l_371:
	/* 0x371: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_379:
	/* 0x379: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_37c:
	/* 0x37c: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_37f:
	/* 0x37f: mov    DWORD PTR [rsp+0x2c],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_384:
	/* 0x384: je     433 <tail_handle_snat_fwd_ipv4+0x433> */
	X86_SIM_X86_JCC(X86_CC_E, 0x384, 0x433, x86_l_433);
x86_l_38a:
	/* 0x38a: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_38d:
	/* 0x38d: je     433 <tail_handle_snat_fwd_ipv4+0x433> */
	X86_SIM_X86_JCC(X86_CC_E, 0x38d, 0x433, x86_l_433);
x86_l_393:
	/* 0x393: mov    QWORD PTR [rsp+0xc0],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_39b:
	/* 0x39b: mov    r15,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_64);
x86_l_39e:
	/* 0x39e: mov    r14d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3a2:
	/* 0x3a2: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_3ab:
	/* 0x3ab: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_3b4:
	/* 0x3b4: movabs rax,0x6c03a50209 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 463917613577ULL);
x86_l_3be:
	/* 0x3be: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_3c6:
	/* 0x3c6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3cb:
	/* 0x3cb: mov    rdi,QWORD PTR [rip+0x59e0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_3d2:
	/* 0x3d2: lea    rsi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_3da:
	/* 0x3da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3dc:
	/* 0x3dc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3df:
	/* 0x3df: je     3f5 <tail_handle_snat_fwd_ipv4+0x3f5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3df, 0x3f5, x86_l_3f5);
x86_l_3e1:
	/* 0x3e1: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_3e4:
	/* 0x3e4: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3e8:
	/* 0x3e8: jmp    420 <tail_handle_snat_fwd_ipv4+0x420> */
	X86_SIM_X86_JMP(0x3e8, 0x420, x86_l_420);
x86_l_3ea:
	/* 0x3ea: mov    r13d,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967161ULL);
x86_l_3f0:
	/* 0x3f0: jmp    45 <tail_handle_snat_fwd_ipv4+0x45> */
	X86_SIM_X86_JMP(0x3f0, 0x45, x86_l_45);
x86_l_3f5:
	/* 0x3f5: mov    QWORD PTR [rsp+0x30],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430209ULL);
x86_l_3fe:
	/* 0x3fe: mov    QWORD PTR [rsp+0x38],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_403:
	/* 0x403: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_408:
	/* 0x408: mov    rdi,QWORD PTR [rip+0x59e0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_40f:
	/* 0x40f: lea    rsi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_417:
	/* 0x417: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_41c:
	/* 0x41c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_41e:
	/* 0x41e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_420:
	/* 0x420: mov    r13,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R15, X86_WIDTH_64);
x86_l_423:
	/* 0x423: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_426:
	/* 0x426: mov    r14d,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_42b:
	/* 0x42b: mov    rdi,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_433:
	/* 0x433: and    rax,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_436:
	/* 0x436: cmp    r14w,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_16, 6ULL);
x86_l_43b:
	/* 0x43b: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_443:
	/* 0x443: jne    49a <tail_handle_snat_fwd_ipv4+0x49a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x443, 0x49a, x86_l_49a);
x86_l_445:
	/* 0x445: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_448:
	/* 0x448: jne    49a <tail_handle_snat_fwd_ipv4+0x49a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x448, 0x49a, x86_l_49a);
x86_l_44a:
	/* 0x44a: mov    rbp,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDI, X86_WIDTH_64);
x86_l_44d:
	/* 0x44d: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_452:
	/* 0x452: lea    esi,[r13+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_456:
	/* 0x456: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_45b:
	/* 0x45b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_45e:
	/* 0x45e: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_463:
	/* 0x463: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_465:
	/* 0x465: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_467:
	/* 0x467: js     4ea <tail_handle_snat_fwd_ipv4+0x4ea> */
	X86_SIM_X86_JCC(X86_CC_S, 0x467, 0x4ea, x86_l_4ea);
x86_l_46d:
	/* 0x46d: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_472:
	/* 0x472: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_475:
	/* 0x475: and    eax,0x1200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4608ULL);
x86_l_47a:
	/* 0x47a: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_47d:
	/* 0x47d: cmp    eax,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 512ULL);
x86_l_482:
	/* 0x482: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_485:
	/* 0x485: test   r12d,0x500 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R12, X86_WIDTH_32, 1280ULL);
x86_l_48c:
	/* 0x48c: jne    75a <tail_handle_snat_fwd_ipv4+0x75a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x48c, 0x75a, x86_l_75a);
x86_l_492:
	/* 0x492: mov    r15b,al */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_8);
x86_l_495:
	/* 0x495: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_498:
	/* 0x498: jmp    4a2 <tail_handle_snat_fwd_ipv4+0x4a2> */
	X86_SIM_X86_JMP(0x498, 0x4a2, x86_l_4a2);
x86_l_49a:
	/* 0x49a: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_49d:
	/* 0x49d: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a2:
	/* 0x4a2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4a7:
	/* 0x4a7: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_4ac:
	/* 0x4ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ae:
	/* 0x4ae: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4b1:
	/* 0x4b1: je     854 <tail_handle_snat_fwd_ipv4+0x854> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4b1, 0x854, x86_l_854);
x86_l_4b7:
	/* 0x4b7: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_4ba:
	/* 0x4ba: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_4bd:
	/* 0x4bd: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_4bf:
	/* 0x4bf: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_4c1:
	/* 0x4c1: test   cl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_4c4:
	/* 0x4c4: mov    rdi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_4c9:
	/* 0x4c9: je     5d0 <tail_handle_snat_fwd_ipv4+0x5d0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4c9, 0x5d0, x86_l_5d0);
x86_l_4cf:
	/* 0x4cf: mov    rdx,QWORD PTR [rip+0x59dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_4d6:
	/* 0x4d6: cmp    BYTE PTR [rdx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4d9:
	/* 0x4d9: je     4f7 <tail_handle_snat_fwd_ipv4+0x4f7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4d9, 0x4f7, x86_l_4f7);
x86_l_4db:
	/* 0x4db: mov    rcx,QWORD PTR [rip+0x59dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_4e2:
	/* 0x4e2: imul   ebp,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_4e5:
	/* 0x4e5: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_4e8:
	/* 0x4e8: jmp    4fc <tail_handle_snat_fwd_ipv4+0x4fc> */
	X86_SIM_X86_JMP(0x4e8, 0x4fc, x86_l_4fc);
x86_l_4ea:
	/* 0x4ea: mov    r13d,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967161ULL);
x86_l_4f0:
	/* 0x4f0: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4f2:
	/* 0x4f2: jmp    18b4 <tail_handle_snat_fwd_ipv4+0x18b4> */
	X86_SIM_X86_JMP(0x4f2, 0x18b4, x86_l_18b4);
x86_l_4f7:
	/* 0x4f7: mov    ebp,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_4fc:
	/* 0x4fc: mov    ecx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_500:
	/* 0x500: cmp    cx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_16, 6ULL);
x86_l_504:
	/* 0x504: jne    539 <tail_handle_snat_fwd_ipv4+0x539> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x504, 0x539, x86_l_539);
x86_l_506:
	/* 0x506: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_509:
	/* 0x509: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_50b:
	/* 0x50b: shr    ecx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_50e:
	/* 0x50e: and    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_511:
	/* 0x511: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_513:
	/* 0x513: mov    WORD PTR [r13+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_518:
	/* 0x518: test   al,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 16ULL);
x86_l_51a:
	/* 0x51a: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_51f:
	/* 0x51f: mov    ebp,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 21600ULL);
x86_l_524:
	/* 0x524: cmove  ebp,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_527:
	/* 0x527: cmp    BYTE PTR [rdx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_52a:
	/* 0x52a: je     539 <tail_handle_snat_fwd_ipv4+0x539> */
	X86_SIM_X86_JCC(X86_CC_E, 0x52a, 0x539, x86_l_539);
x86_l_52c:
	/* 0x52c: mov    rax,QWORD PTR [rip+0x59dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_533:
	/* 0x533: imul   ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_536:
	/* 0x536: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_539:
	/* 0x539: mov    r14d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R12, X86_WIDTH_32);
x86_l_53c:
	/* 0x53c: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_540:
	/* 0x540: cmp    BYTE PTR [rdx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_543:
	/* 0x543: je     554 <tail_handle_snat_fwd_ipv4+0x554> */
	X86_SIM_X86_JCC(X86_CC_E, 0x543, 0x554, x86_l_554);
x86_l_545:
	/* 0x545: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_54a:
	/* 0x54a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_54c:
	/* 0x54c: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_54e:
	/* 0x54e: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_552:
	/* 0x552: jmp    577 <tail_handle_snat_fwd_ipv4+0x577> */
	X86_SIM_X86_JMP(0x552, 0x577, x86_l_577);
x86_l_554:
	/* 0x554: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_559:
	/* 0x559: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_55b:
	/* 0x55b: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_55d:
	/* 0x55d: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_561:
	/* 0x561: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_56b:
	/* 0x56b: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_56e:
	/* 0x56e: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_573:
	/* 0x573: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_577:
	/* 0x577: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_579:
	/* 0x579: mov    DWORD PTR [r13+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_57d:
	/* 0x57d: movzx  ecx,BYTE PTR [r13+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_582:
	/* 0x582: mov    edx,DWORD PTR [r13+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_586:
	/* 0x586: and    r14b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_58a:
	/* 0x58a: mov    rsi,QWORD PTR [rip+0x59dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_591:
	/* 0x591: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_594:
	/* 0x594: mov    rdi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_599:
	/* 0x599: je     5ac <tail_handle_snat_fwd_ipv4+0x5ac> */
	X86_SIM_X86_JCC(X86_CC_E, 0x599, 0x5ac, x86_l_5ac);
x86_l_59b:
	/* 0x59b: mov    rsi,QWORD PTR [rip+0x59dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_5a2:
	/* 0x5a2: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5a4:
	/* 0x5a4: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_5a7:
	/* 0x5a7: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_5aa:
	/* 0x5aa: jmp    5b1 <tail_handle_snat_fwd_ipv4+0x5b1> */
	X86_SIM_X86_JMP(0x5aa, 0x5b1, x86_l_5b1);
x86_l_5ac:
	/* 0x5ac: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_5b1:
	/* 0x5b1: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_5b3:
	/* 0x5b3: or     r14b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_5b6:
	/* 0x5b6: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_5b8:
	/* 0x5b8: jb     5bf <tail_handle_snat_fwd_ipv4+0x5bf> */
	X86_SIM_X86_JCC(X86_CC_B, 0x5b8, 0x5bf, x86_l_5bf);
x86_l_5ba:
	/* 0x5ba: cmp    cl,r14b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R14, X86_WIDTH_8);
x86_l_5bd:
	/* 0x5bd: je     5d0 <tail_handle_snat_fwd_ipv4+0x5d0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5bd, 0x5d0, x86_l_5d0);
x86_l_5bf:
	/* 0x5bf: mov    BYTE PTR [r13+0x2a],r14b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R14, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_5c3:
	/* 0x5c3: mov    DWORD PTR [r13+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5c7:
	/* 0x5c7: mov    rax,QWORD PTR [rip+0x59dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_5ce:
	/* 0x5ce: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5d0:
	/* 0x5d0: mov    rax,QWORD PTR [rip+0x59dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_5d7:
	/* 0x5d7: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5da:
	/* 0x5da: je     5e9 <tail_handle_snat_fwd_ipv4+0x5e9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5da, 0x5e9, x86_l_5e9);
x86_l_5dc:
	/* 0x5dc: inc QWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 16ULL);
x86_l_5e1:
	/* 0x5e1: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_5e4:
	/* 0x5e4: add QWORD PTR [r13+0x18],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R13, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_5e9:
	/* 0x5e9: cmp    r15d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 2ULL);
x86_l_5ed:
	/* 0x5ed: je     63a <tail_handle_snat_fwd_ipv4+0x63a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5ed, 0x63a, x86_l_63a);
x86_l_5ef:
	/* 0x5ef: cmp    r15d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 1ULL);
x86_l_5f3:
	/* 0x5f3: jne    717 <tail_handle_snat_fwd_ipv4+0x717> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x5f3, 0x717, x86_l_717);
x86_l_5f9:
	/* 0x5f9: movzx  eax,WORD PTR [r13+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_5fe:
	/* 0x5fe: test   al,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 3ULL);
x86_l_600:
	/* 0x600: je     717 <tail_handle_snat_fwd_ipv4+0x717> */
	X86_SIM_X86_JCC(X86_CC_E, 0x600, 0x717, x86_l_717);
x86_l_606:
	/* 0x606: mov    WORD PTR [r13+0x2a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 180388626432ULL);
x86_l_60d:
	/* 0x60d: and    eax,0xffec */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 65516ULL);
x86_l_612:
	/* 0x612: mov    WORD PTR [r13+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_617:
	/* 0x617: mov    r15,QWORD PTR [rip+0x59dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_61e:
	/* 0x61e: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_622:
	/* 0x622: je     792 <tail_handle_snat_fwd_ipv4+0x792> */
	X86_SIM_X86_JCC(X86_CC_E, 0x622, 0x792, x86_l_792);
x86_l_628:
	/* 0x628: mov    rcx,QWORD PTR [rip+0x59dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_62f:
	/* 0x62f: imul   ebp,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_632:
	/* 0x632: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_635:
	/* 0x635: jmp    797 <tail_handle_snat_fwd_ipv4+0x797> */
	X86_SIM_X86_JMP(0x635, 0x797, x86_l_797);
x86_l_63a:
	/* 0x63a: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_63d:
	/* 0x63d: and    eax,0x400 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 1024ULL);
x86_l_642:
	/* 0x642: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_645:
	/* 0x645: mov    ax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 3ULL);
x86_l_649:
	/* 0x649: sbb    ax,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_16, X86_ALU_SBB, 0ULL);
x86_l_64d:
	/* 0x64d: or     ax,WORD PTR [r13+0x24] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R13, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 36ULL);
x86_l_652:
	/* 0x652: mov    WORD PTR [r13+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_657:
	/* 0x657: mov    r15,QWORD PTR [rip+0x59dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_65e:
	/* 0x65e: mov    ecx,DWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_661:
	/* 0x661: test   al,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_663:
	/* 0x663: je     717 <tail_handle_snat_fwd_ipv4+0x717> */
	X86_SIM_X86_JCC(X86_CC_E, 0x663, 0x717, x86_l_717);
x86_l_669:
	/* 0x669: mov    r14,QWORD PTR [rip+0x59dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_670:
	/* 0x670: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_674:
	/* 0x674: je     689 <tail_handle_snat_fwd_ipv4+0x689> */
	X86_SIM_X86_JCC(X86_CC_E, 0x674, 0x689, x86_l_689);
x86_l_676:
	/* 0x676: mov    rax,QWORD PTR [rip+0x59dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_67d:
	/* 0x67d: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_67f:
	/* 0x67f: add    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_681:
	/* 0x681: lea    ebp,[rax+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_684:
	/* 0x684: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_687:
	/* 0x687: jmp    68e <tail_handle_snat_fwd_ipv4+0x68e> */
	X86_SIM_X86_JMP(0x687, 0x68e, x86_l_68e);
x86_l_689:
	/* 0x689: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_68e:
	/* 0x68e: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_692:
	/* 0x692: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_696:
	/* 0x696: je     6a7 <tail_handle_snat_fwd_ipv4+0x6a7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x696, 0x6a7, x86_l_6a7);
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
	/* 0x6a1: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_6a5:
	/* 0x6a5: jmp    6ca <tail_handle_snat_fwd_ipv4+0x6ca> */
	X86_SIM_X86_JMP(0x6a5, 0x6ca, x86_l_6ca);
x86_l_6a7:
	/* 0x6a7: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_6ac:
	/* 0x6ac: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6ae:
	/* 0x6ae: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_6b0:
	/* 0x6b0: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_6b4:
	/* 0x6b4: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_6be:
	/* 0x6be: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_6c1:
	/* 0x6c1: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_6c6:
	/* 0x6c6: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_6ca:
	/* 0x6ca: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_6cc:
	/* 0x6cc: mov    DWORD PTR [r13+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6d0:
	/* 0x6d0: movzx  ecx,BYTE PTR [r13+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_6d5:
	/* 0x6d5: mov    edx,DWORD PTR [r13+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6d9:
	/* 0x6d9: and    r12b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_6dd:
	/* 0x6dd: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6e1:
	/* 0x6e1: mov    rdi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_6e6:
	/* 0x6e6: je     6f9 <tail_handle_snat_fwd_ipv4+0x6f9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6e6, 0x6f9, x86_l_6f9);
x86_l_6e8:
	/* 0x6e8: mov    rsi,QWORD PTR [rip+0x59dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_6ef:
	/* 0x6ef: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6f1:
	/* 0x6f1: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_6f4:
	/* 0x6f4: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_6f7:
	/* 0x6f7: jmp    6fe <tail_handle_snat_fwd_ipv4+0x6fe> */
	X86_SIM_X86_JMP(0x6f7, 0x6fe, x86_l_6fe);
x86_l_6f9:
	/* 0x6f9: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_6fe:
	/* 0x6fe: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_700:
	/* 0x700: or     r12b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_703:
	/* 0x703: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_705:
	/* 0x705: jb     70c <tail_handle_snat_fwd_ipv4+0x70c> */
	X86_SIM_X86_JCC(X86_CC_B, 0x705, 0x70c, x86_l_70c);
x86_l_707:
	/* 0x707: cmp    cl,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R12, X86_WIDTH_8);
x86_l_70a:
	/* 0x70a: je     717 <tail_handle_snat_fwd_ipv4+0x717> */
	X86_SIM_X86_JCC(X86_CC_E, 0x70a, 0x717, x86_l_717);
x86_l_70c:
	/* 0x70c: mov    BYTE PTR [r13+0x2a],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_710:
	/* 0x710: mov    DWORD PTR [r13+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_714:
	/* 0x714: mov    eax,DWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_717:
	/* 0x717: mov    r15,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_71f:
	/* 0x71f: jmp    9d1 <tail_handle_snat_fwd_ipv4+0x9d1> */
	X86_SIM_X86_JMP(0x71f, 0x9d1, x86_l_9d1);
x86_l_724:
	/* 0x724: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_729:
	/* 0x729: mov    rdi,QWORD PTR [rip+0x59dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv4_frag_datagrams)));
x86_l_730:
	/* 0x730: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_735:
	/* 0x735: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_737:
	/* 0x737: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_73a:
	/* 0x73a: je     74a <tail_handle_snat_fwd_ipv4+0x74a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x73a, 0x74a, x86_l_74a);
x86_l_73c:
	/* 0x73c: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_73e:
	/* 0x73e: mov    DWORD PTR [rsp+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_742:
	/* 0x742: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_745:
	/* 0x745: jmp    2c9 <tail_handle_snat_fwd_ipv4+0x2c9> */
	X86_SIM_X86_JMP(0x745, 0x2c9, x86_l_2c9);
x86_l_74a:
	/* 0x74a: mov    r13d,0xffffff51 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967121ULL);
x86_l_750:
	/* 0x750: mov    r11d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_755:
	/* 0x755: jmp    45 <tail_handle_snat_fwd_ipv4+0x45> */
	X86_SIM_X86_JMP(0x755, 0x45, x86_l_45);
x86_l_75a:
	/* 0x75a: mov    r15d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 2ULL);
x86_l_760:
	/* 0x760: jmp    495 <tail_handle_snat_fwd_ipv4+0x495> */
	X86_SIM_X86_JMP(0x760, 0x495, x86_l_495);
x86_l_765:
	/* 0x765: mov    QWORD PTR [rsp+0x30],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430209ULL);
x86_l_76e:
	/* 0x76e: mov    QWORD PTR [rsp+0x38],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_773:
	/* 0x773: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_778:
	/* 0x778: mov    rdi,QWORD PTR [rip+0x59dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_77f:
	/* 0x77f: lea    rsi,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_787:
	/* 0x787: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_78c:
	/* 0x78c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_78e:
	/* 0x78e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_790:
	/* 0x790: jmp    742 <tail_handle_snat_fwd_ipv4+0x742> */
	X86_SIM_X86_JMP(0x790, 0x742, x86_l_742);
x86_l_792:
	/* 0x792: mov    ebp,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_797:
	/* 0x797: cmp    WORD PTR [rsp+0x2c],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 188978561030ULL);
x86_l_79d:
	/* 0x79d: jne    7d3 <tail_handle_snat_fwd_ipv4+0x7d3> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x79d, 0x7d3, x86_l_7d3);
x86_l_79f:
	/* 0x79f: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_7a2:
	/* 0x7a2: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_7a4:
	/* 0x7a4: shr    ecx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_7a7:
	/* 0x7a7: and    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_7aa:
	/* 0x7aa: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_7ac:
	/* 0x7ac: mov    WORD PTR [r13+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_7b1:
	/* 0x7b1: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_7b3:
	/* 0x7b3: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_7b8:
	/* 0x7b8: mov    ebp,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 21600ULL);
x86_l_7bd:
	/* 0x7bd: cmove  ebp,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_7c0:
	/* 0x7c0: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7c4:
	/* 0x7c4: je     7d3 <tail_handle_snat_fwd_ipv4+0x7d3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7c4, 0x7d3, x86_l_7d3);
x86_l_7c6:
	/* 0x7c6: mov    rax,QWORD PTR [rip+0x59dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_7cd:
	/* 0x7cd: imul   ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_7d0:
	/* 0x7d0: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_7d3:
	/* 0x7d3: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_7d7:
	/* 0x7d7: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7db:
	/* 0x7db: je     7ec <tail_handle_snat_fwd_ipv4+0x7ec> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7db, 0x7ec, x86_l_7ec);
x86_l_7dd:
	/* 0x7dd: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_7e2:
	/* 0x7e2: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7e4:
	/* 0x7e4: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_7e6:
	/* 0x7e6: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_7ea:
	/* 0x7ea: jmp    80f <tail_handle_snat_fwd_ipv4+0x80f> */
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
	/* 0x806: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_80b:
	/* 0x80b: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_80f:
	/* 0x80f: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_811:
	/* 0x811: mov    DWORD PTR [r13+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_815:
	/* 0x815: movzx  ecx,BYTE PTR [r13+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_81a:
	/* 0x81a: mov    edx,DWORD PTR [r13+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_81e:
	/* 0x81e: and    r12b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_822:
	/* 0x822: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_826:
	/* 0x826: je     839 <tail_handle_snat_fwd_ipv4+0x839> */
	X86_SIM_X86_JCC(X86_CC_E, 0x826, 0x839, x86_l_839);
x86_l_828:
	/* 0x828: mov    rsi,QWORD PTR [rip+0x59dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_82f:
	/* 0x82f: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_831:
	/* 0x831: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_834:
	/* 0x834: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_837:
	/* 0x837: jmp    83e <tail_handle_snat_fwd_ipv4+0x83e> */
	X86_SIM_X86_JMP(0x837, 0x83e, x86_l_83e);
x86_l_839:
	/* 0x839: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_83e:
	/* 0x83e: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_840:
	/* 0x840: or     r12b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_843:
	/* 0x843: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_845:
	/* 0x845: jb     84c <tail_handle_snat_fwd_ipv4+0x84c> */
	X86_SIM_X86_JCC(X86_CC_B, 0x845, 0x84c, x86_l_84c);
x86_l_847:
	/* 0x847: cmp    cl,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R12, X86_WIDTH_8);
x86_l_84a:
	/* 0x84a: je     85d <tail_handle_snat_fwd_ipv4+0x85d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x84a, 0x85d, x86_l_85d);
x86_l_84c:
	/* 0x84c: mov    BYTE PTR [r13+0x2a],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_850:
	/* 0x850: mov    DWORD PTR [r13+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_854:
	/* 0x854: mov    rax,QWORD PTR [rip+0x59dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_85b:
	/* 0x85b: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_85d:
	/* 0x85d: movzx  ebp,BYTE PTR [rsp+0x7c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 124ULL);
x86_l_862:
	/* 0x862: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_866:
	/* 0x866: jne    871 <tail_handle_snat_fwd_ipv4+0x871> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x866, 0x871, x86_l_871);
x86_l_868:
	/* 0x868: mov    r13,QWORD PTR [rip+0x59dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&cilium_ct4_global)));
x86_l_86f:
	/* 0x86f: jmp    878 <tail_handle_snat_fwd_ipv4+0x878> */
	X86_SIM_X86_JMP(0x86f, 0x878, x86_l_878);
x86_l_871:
	/* 0x871: mov    r13,QWORD PTR [rip+0x59dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&cilium_ct_any4_global)));
x86_l_878:
	/* 0x878: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_881:
	/* 0x881: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_88a:
	/* 0x88a: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_893:
	/* 0x893: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_89c:
	/* 0x89c: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_8a5:
	/* 0x8a5: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_8ae:
	/* 0x8ae: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_8b7:
	/* 0x8b7: mov    r14,QWORD PTR [rip+0x59dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_8be:
	/* 0x8be: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8c2:
	/* 0x8c2: je     8d5 <tail_handle_snat_fwd_ipv4+0x8d5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8c2, 0x8d5, x86_l_8d5);
x86_l_8c4:
	/* 0x8c4: mov    rax,QWORD PTR [rip+0x59dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_8cb:
	/* 0x8cb: imul   r15d,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_8cf:
	/* 0x8cf: shr    r15d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_8d3:
	/* 0x8d3: jmp    8db <tail_handle_snat_fwd_ipv4+0x8db> */
	X86_SIM_X86_JMP(0x8d3, 0x8db, x86_l_8db);
x86_l_8d5:
	/* 0x8d5: mov    r15d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 60ULL);
x86_l_8db:
	/* 0x8db: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_8df:
	/* 0x8df: jne    8fe <tail_handle_snat_fwd_ipv4+0x8fe> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x8df, 0x8fe, x86_l_8fe);
x86_l_8e1:
	/* 0x8e1: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8e5:
	/* 0x8e5: je     8f8 <tail_handle_snat_fwd_ipv4+0x8f8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8e5, 0x8f8, x86_l_8f8);
x86_l_8e7:
	/* 0x8e7: mov    rax,QWORD PTR [rip+0x59dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_8ee:
	/* 0x8ee: imul   r15d,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_8f2:
	/* 0x8f2: shr    r15d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_8f6:
	/* 0x8f6: jmp    8fe <tail_handle_snat_fwd_ipv4+0x8fe> */
	X86_SIM_X86_JMP(0x8f6, 0x8fe, x86_l_8fe);
x86_l_8f8:
	/* 0x8f8: mov    r15d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 60ULL);
x86_l_8fe:
	/* 0x8fe: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_902:
	/* 0x902: je     913 <tail_handle_snat_fwd_ipv4+0x913> */
	X86_SIM_X86_JCC(X86_CC_E, 0x902, 0x913, x86_l_913);
x86_l_904:
	/* 0x904: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_909:
	/* 0x909: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_90b:
	/* 0x90b: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_90d:
	/* 0x90d: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_911:
	/* 0x911: jmp    936 <tail_handle_snat_fwd_ipv4+0x936> */
	X86_SIM_X86_JMP(0x911, 0x936, x86_l_936);
x86_l_913:
	/* 0x913: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_918:
	/* 0x918: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_91a:
	/* 0x91a: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_91c:
	/* 0x91c: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_920:
	/* 0x920: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_92a:
	/* 0x92a: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_92d:
	/* 0x92d: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_932:
	/* 0x932: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_936:
	/* 0x936: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_93a:
	/* 0x93a: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_93d:
	/* 0x93d: add    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_940:
	/* 0x940: mov    DWORD PTR [rsp+0x50],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_945:
	/* 0x945: movzx  edx,BYTE PTR [rsp+0x5a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 90ULL);
x86_l_94a:
	/* 0x94a: mov    esi,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_94e:
	/* 0x94e: add    cl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_8, X86_ALU_ADD);
x86_l_950:
	/* 0x950: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_954:
	/* 0x954: je     967 <tail_handle_snat_fwd_ipv4+0x967> */
	X86_SIM_X86_JCC(X86_CC_E, 0x954, 0x967, x86_l_967);
x86_l_956:
	/* 0x956: mov    rdi,QWORD PTR [rip+0x59dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_95d:
	/* 0x95d: mov    edi,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_95f:
	/* 0x95f: lea    edi,[rdi+rdi*4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_962:
	/* 0x962: shr    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_965:
	/* 0x965: jmp    96c <tail_handle_snat_fwd_ipv4+0x96c> */
	X86_SIM_X86_JMP(0x965, 0x96c, x86_l_96c);
x86_l_967:
	/* 0x967: mov    edi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 5ULL);
x86_l_96c:
	/* 0x96c: mov    r15,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_974:
	/* 0x974: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_976:
	/* 0x976: or     cl,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_978:
	/* 0x978: cmp    edi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_97a:
	/* 0x97a: jb     980 <tail_handle_snat_fwd_ipv4+0x980> */
	X86_SIM_X86_JCC(X86_CC_B, 0x97a, 0x980, x86_l_980);
x86_l_97c:
	/* 0x97c: cmp    dl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_8);
x86_l_97e:
	/* 0x97e: je     991 <tail_handle_snat_fwd_ipv4+0x991> */
	X86_SIM_X86_JCC(X86_CC_E, 0x97e, 0x991, x86_l_991);
x86_l_980:
	/* 0x980: mov    BYTE PTR [rsp+0x5a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 90ULL);
x86_l_984:
	/* 0x984: mov    DWORD PTR [rsp+0x60],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_988:
	/* 0x988: mov    rax,QWORD PTR [rip+0x59dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_98f:
	/* 0x98f: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_991:
	/* 0x991: mov    rax,QWORD PTR [rip+0x59dc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_998:
	/* 0x998: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_99b:
	/* 0x99b: je     9ae <tail_handle_snat_fwd_ipv4+0x9ae> */
	X86_SIM_X86_JCC(X86_CC_E, 0x99b, 0x9ae, x86_l_9ae);
x86_l_99d:
	/* 0x99d: mov    QWORD PTR [rsp+0x40],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906945ULL);
x86_l_9a6:
	/* 0x9a6: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_9a9:
	/* 0x9a9: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_9ae:
	/* 0x9ae: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_9b3:
	/* 0x9b3: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_9b8:
	/* 0x9b8: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9bd:
	/* 0x9bd: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_9c0:
	/* 0x9c0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9c2:
	/* 0x9c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9c4:
	/* 0x9c4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_9c6:
	/* 0x9c6: js     1585 <tail_handle_snat_fwd_ipv4+0x1585> */
	X86_SIM_X86_JCC(X86_CC_S, 0x9c6, 0x1585, x86_l_1585);
x86_l_9cc:
	/* 0x9cc: mov    rdi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_9d1:
	/* 0x9d1: test   r15,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_64);
x86_l_9d4:
	/* 0x9d4: je     af9 <tail_handle_snat_fwd_ipv4+0xaf9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9d4, 0xaf9, x86_l_af9);
x86_l_9da:
	/* 0x9da: mov    BYTE PTR [rsp+0x7d],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 536870912001ULL);
x86_l_9df:
	/* 0x9df: movzx  eax,BYTE PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 40ULL);
x86_l_9e4:
	/* 0x9e4: mov    BYTE PTR [rsp+0x7c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_9e8:
	/* 0x9e8: mov    eax,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_9ec:
	/* 0x9ec: mov    DWORD PTR [rsp+0x74],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_9f0:
	/* 0x9f0: mov    eax,DWORD PTR [r15+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9f4:
	/* 0x9f4: mov    DWORD PTR [rsp+0x70],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_9f8:
	/* 0x9f8: movzx  ecx,WORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_9fd:
	/* 0x9fd: mov    WORD PTR [rsp+0x7a],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 122ULL);
x86_l_a02:
	/* 0xa02: movzx  ecx,WORD PTR [r15+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_a07:
	/* 0xa07: mov    WORD PTR [rsp+0x78],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_a0c:
	/* 0xa0c: cmp    eax,0xfffff50a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294964490ULL);
x86_l_a11:
	/* 0xa11: jne    a9f <tail_handle_snat_fwd_ipv4+0xa9f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa11, 0xa9f, x86_l_a9f);
x86_l_a17:
	/* 0xa17: cmp    QWORD PTR [r15+0x8],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_a1c:
	/* 0xa1c: jne    a9f <tail_handle_snat_fwd_ipv4+0xa9f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa1c, 0xa9f, x86_l_a9f);
x86_l_a22:
	/* 0xa22: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a27:
	/* 0xa27: mov    rdi,QWORD PTR [rip+0x59d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_a2e:
	/* 0xa2e: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_a33:
	/* 0xa33: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a35:
	/* 0xa35: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a38:
	/* 0xa38: jne    14e2 <tail_handle_snat_fwd_ipv4+0x14e2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa38, 0x14e2, x86_l_14e2);
x86_l_a3e:
	/* 0xa3e: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_a47:
	/* 0xa47: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_a50:
	/* 0xa50: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_a59:
	/* 0xa59: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_a62:
	/* 0xa62: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a66:
	/* 0xa66: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_a6a:
	/* 0xa6a: movzx  eax,WORD PTR [rsp+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_a6f:
	/* 0xa6f: mov    WORD PTR [rsp+0x54],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_a74:
	/* 0xa74: mov    QWORD PTR [rsp+0x38],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168577ULL);
x86_l_a7d:
	/* 0xa7d: mov    rax,QWORD PTR [rip+0x59d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_a84:
	/* 0xa84: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a87:
	/* 0xa87: je     149c <tail_handle_snat_fwd_ipv4+0x149c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa87, 0x149c, x86_l_149c);
x86_l_a8d:
	/* 0xa8d: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_a92:
	/* 0xa92: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a94:
	/* 0xa94: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_a96:
	/* 0xa96: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_a9a:
	/* 0xa9a: jmp    14bf <tail_handle_snat_fwd_ipv4+0x14bf> */
	X86_SIM_X86_JMP(0xa9a, 0x14bf, x86_l_14bf);
x86_l_a9f:
	/* 0xa9f: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_aa4:
	/* 0xaa4: mov    rdi,QWORD PTR [rip+0x59d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_aab:
	/* 0xaab: lea    rsi,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_ab0:
	/* 0xab0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ab2:
	/* 0xab2: mov    r13d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_ab5:
	/* 0xab5: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ab7:
	/* 0xab7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ab9:
	/* 0xab9: js     16cb <tail_handle_snat_fwd_ipv4+0x16cb> */
	X86_SIM_X86_JCC(X86_CC_S, 0xab9, 0x16cb, x86_l_16cb);
x86_l_abf:
	/* 0xabf: cmp    r13d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 2ULL);
x86_l_ac3:
	/* 0xac3: je     16cb <tail_handle_snat_fwd_ipv4+0x16cb> */
	X86_SIM_X86_JCC(X86_CC_E, 0xac3, 0x16cb, x86_l_16cb);
x86_l_ac9:
	/* 0xac9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ace:
	/* 0xace: mov    rdi,QWORD PTR [rip+0x59d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_ad5:
	/* 0xad5: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_ada:
	/* 0xada: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_adc:
	/* 0xadc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_adf:
	/* 0xadf: je     af4 <tail_handle_snat_fwd_ipv4+0xaf4> */
	X86_SIM_X86_JCC(X86_CC_E, 0xadf, 0xaf4, x86_l_af4);
x86_l_ae1:
	/* 0xae1: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_ae6:
	/* 0xae6: mov    rdi,QWORD PTR [rip+0x59d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_aed:
	/* 0xaed: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_af2:
	/* 0xaf2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_af4:
	/* 0xaf4: mov    rdi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_af9:
	/* 0xaf9: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_b02:
	/* 0xb02: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_b0b:
	/* 0xb0b: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_b14:
	/* 0xb14: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_b1d:
	/* 0xb1d: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_b26:
	/* 0xb26: mov    QWORD PTR [rsp+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_b32:
	/* 0xb32: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_b3b:
	/* 0xb3b: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_b44:
	/* 0xb44: mov    QWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_b50:
	/* 0xb50: mov    QWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_b5c:
	/* 0xb5c: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b60:
	/* 0xb60: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_b64:
	/* 0xb64: movzx  r14d,WORD PTR [rsp+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_b6a:
	/* 0xb6a: mov    WORD PTR [rsp+0x54],r14w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_b70:
	/* 0xb70: mov    DWORD PTR [rsp+0x90],0xfffff50a */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 622770255114ULL);
x86_l_b7b:
	/* 0xb7b: mov    BYTE PTR [rsp+0x15],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 90194313217ULL);
x86_l_b80:
	/* 0xb80: movzx  eax,BYTE PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 40ULL);
x86_l_b85:
	/* 0xb85: mov    BYTE PTR [rsp+0x14],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_b89:
	/* 0xb89: mov    eax,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_b8d:
	/* 0xb8d: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_b91:
	/* 0xb91: mov    DWORD PTR [rsp+0x8],0xfffff50a */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 38654702858ULL);
x86_l_b99:
	/* 0xb99: movzx  eax,WORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_b9e:
	/* 0xb9e: mov    WORD PTR [rsp+0x12],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_ba3:
	/* 0xba3: lea    ebp,[rdi+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_ba6:
	/* 0xba6: mov    WORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_bad:
	/* 0xbad: rol    r14w,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_bb2:
	/* 0xbb2: cmp    r14w,bp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R14, X86_RBP, X86_WIDTH_16);
x86_l_bb6:
	/* 0xbb6: jae    bdb <tail_handle_snat_fwd_ipv4+0xbdb> */
	X86_SIM_X86_JCC(X86_CC_AE, 0xbb6, 0xbdb, x86_l_bdb);
x86_l_bb8:
	/* 0xbb8: mov    ecx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_bbd:
	/* 0xbbd: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bbf:
	/* 0xbbf: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_bc1:
	/* 0xbc1: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_bc6:
	/* 0xbc6: xor    ecx,0xffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 65535ULL);
x86_l_bcc:
	/* 0xbcc: movzx  r14d,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_bd0:
	/* 0xbd0: imul   r14d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_bd4:
	/* 0xbd4: shr    r14d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_bd8:
	/* 0xbd8: add    r14d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_bdb:
	/* 0xbdb: mov    QWORD PTR [rsp+0x78],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075521ULL);
x86_l_be4:
	/* 0xbe4: mov    QWORD PTR [rsp+0x38],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168577ULL);
x86_l_bed:
	/* 0xbed: mov    rax,QWORD PTR [rip+0x59d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_bf4:
	/* 0xbf4: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bf7:
	/* 0xbf7: je     c08 <tail_handle_snat_fwd_ipv4+0xc08> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbf7, 0xc08, x86_l_c08);
x86_l_bf9:
	/* 0xbf9: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_bfe:
	/* 0xbfe: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c00:
	/* 0xc00: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_c02:
	/* 0xc02: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_c06:
	/* 0xc06: jmp    c2b <tail_handle_snat_fwd_ipv4+0xc2b> */
	X86_SIM_X86_JMP(0xc06, 0xc2b, x86_l_c2b);
x86_l_c08:
	/* 0xc08: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_c0d:
	/* 0xc0d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c0f:
	/* 0xc0f: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_c11:
	/* 0xc11: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_c15:
	/* 0xc15: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_c1f:
	/* 0xc1f: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_c22:
	/* 0xc22: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_c27:
	/* 0xc27: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_c2b:
	/* 0xc2b: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c30:
	/* 0xc30: movbe  WORD PTR [rsp+0x10],r14w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_c38:
	/* 0xc38: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_c3d:
	/* 0xc3d: mov    rdi,QWORD PTR [rip+0x59d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_c44:
	/* 0xc44: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c49:
	/* 0xc49: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c4e:
	/* 0xc4e: mov    r12d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 1ULL);
x86_l_c54:
	/* 0xc54: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_c59:
	/* 0xc59: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c5b:
	/* 0xc5b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c5d:
	/* 0xc5d: je     1459 <tail_handle_snat_fwd_ipv4+0x1459> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc5d, 0x1459, x86_l_1459);
x86_l_c63:
	/* 0xc63: mov    eax,0xfffffffe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967294ULL);
x86_l_c68:
	/* 0xc68: sub    eax,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 104ULL);
x86_l_c6c:
	/* 0xc6c: movzx  r14d,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_c70:
	/* 0xc70: inc    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_c73:
	/* 0xc73: mov    ecx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_c78:
	/* 0xc78: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c7b:
	/* 0xc7b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c7d:
	/* 0xc7d: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_c7f:
	/* 0xc7f: movzx  r13d,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_c83:
	/* 0xc83: imul   r13d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R14, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_c87:
	/* 0xc87: shr    r13d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_c8b:
	/* 0xc8b: add    r13d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_c8e:
	/* 0xc8e: movbe  WORD PTR [rsp+0x10],r13w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_c96:
	/* 0xc96: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_c9b:
	/* 0xc9b: mov    rdi,QWORD PTR [rip+0x59d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_ca2:
	/* 0xca2: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ca7:
	/* 0xca7: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_cac:
	/* 0xcac: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_cb1:
	/* 0xcb1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cb3:
	/* 0xcb3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_cb5:
	/* 0xcb5: je     1613 <tail_handle_snat_fwd_ipv4+0x1613> */
	X86_SIM_X86_JCC(X86_CC_E, 0xcb5, 0x1613, x86_l_1613);
x86_l_cbb:
	/* 0xcbb: inc    r13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_cbe:
	/* 0xcbe: movzx  r15d,r13w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R13, X86_WIDTH_32, X86_WIDTH_16);
x86_l_cc2:
	/* 0xcc2: imul   r15d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R14, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_cc6:
	/* 0xcc6: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_cca:
	/* 0xcca: add    r15d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_ccd:
	/* 0xccd: movbe  WORD PTR [rsp+0x10],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_cd5:
	/* 0xcd5: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_cda:
	/* 0xcda: mov    rdi,QWORD PTR [rip+0x59d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_ce1:
	/* 0xce1: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ce6:
	/* 0xce6: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ceb:
	/* 0xceb: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_cf0:
	/* 0xcf0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cf2:
	/* 0xcf2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_cf4:
	/* 0xcf4: je     1464 <tail_handle_snat_fwd_ipv4+0x1464> */
	X86_SIM_X86_JCC(X86_CC_E, 0xcf4, 0x1464, x86_l_1464);
x86_l_cfa:
	/* 0xcfa: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_cfd:
	/* 0xcfd: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_d01:
	/* 0xd01: imul   r15d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R14, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_d05:
	/* 0xd05: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_d09:
	/* 0xd09: add    r15d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_d0c:
	/* 0xd0c: movbe  WORD PTR [rsp+0x10],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_d14:
	/* 0xd14: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_d19:
	/* 0xd19: mov    rdi,QWORD PTR [rip+0x59d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_d20:
	/* 0xd20: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d25:
	/* 0xd25: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d2a:
	/* 0xd2a: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_d2f:
	/* 0xd2f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d31:
	/* 0xd31: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_d33:
	/* 0xd33: je     1472 <tail_handle_snat_fwd_ipv4+0x1472> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd33, 0x1472, x86_l_1472);
x86_l_d39:
	/* 0xd39: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_d3c:
	/* 0xd3c: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_d40:
	/* 0xd40: imul   r15d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R14, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_d44:
	/* 0xd44: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_d48:
	/* 0xd48: add    r15d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_d4b:
	/* 0xd4b: movbe  WORD PTR [rsp+0x10],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_d53:
	/* 0xd53: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_d58:
	/* 0xd58: mov    rdi,QWORD PTR [rip+0x59d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_d5f:
	/* 0xd5f: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d64:
	/* 0xd64: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d69:
	/* 0xd69: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_d6e:
	/* 0xd6e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d70:
	/* 0xd70: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_d72:
	/* 0xd72: je     1480 <tail_handle_snat_fwd_ipv4+0x1480> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd72, 0x1480, x86_l_1480);
x86_l_d78:
	/* 0xd78: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_d7b:
	/* 0xd7b: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_d7f:
	/* 0xd7f: imul   r15d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R14, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_d83:
	/* 0xd83: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_d87:
	/* 0xd87: add    r15d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_d8a:
	/* 0xd8a: movbe  WORD PTR [rsp+0x10],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_d92:
	/* 0xd92: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_d97:
	/* 0xd97: mov    rdi,QWORD PTR [rip+0x59d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_d9e:
	/* 0xd9e: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_da3:
	/* 0xda3: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_da8:
	/* 0xda8: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_dad:
	/* 0xdad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_daf:
	/* 0xdaf: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_db1:
	/* 0xdb1: je     148e <tail_handle_snat_fwd_ipv4+0x148e> */
	X86_SIM_X86_JCC(X86_CC_E, 0xdb1, 0x148e, x86_l_148e);
x86_l_db7:
	/* 0xdb7: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_dba:
	/* 0xdba: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_dbe:
	/* 0xdbe: imul   r15d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R14, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_dc2:
	/* 0xdc2: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_dc6:
	/* 0xdc6: add    r15d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_dc9:
	/* 0xdc9: movbe  WORD PTR [rsp+0x10],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_dd1:
	/* 0xdd1: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_dd6:
	/* 0xdd6: mov    rdi,QWORD PTR [rip+0x59d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_ddd:
	/* 0xddd: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_de2:
	/* 0xde2: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_de7:
	/* 0xde7: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_dec:
	/* 0xdec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dee:
	/* 0xdee: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_df0:
	/* 0xdf0: je     14f9 <tail_handle_snat_fwd_ipv4+0x14f9> */
	X86_SIM_X86_JCC(X86_CC_E, 0xdf0, 0x14f9, x86_l_14f9);
x86_l_df6:
	/* 0xdf6: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_df9:
	/* 0xdf9: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_dfd:
	/* 0xdfd: imul   r15d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R14, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_e01:
	/* 0xe01: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_e05:
	/* 0xe05: add    r15d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_e08:
	/* 0xe08: movbe  WORD PTR [rsp+0x10],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_e10:
	/* 0xe10: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_e15:
	/* 0xe15: mov    rdi,QWORD PTR [rip+0x59d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_e1c:
	/* 0xe1c: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e21:
	/* 0xe21: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e26:
	/* 0xe26: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_e2b:
	/* 0xe2b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e2d:
	/* 0xe2d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_e2f:
	/* 0xe2f: je     1507 <tail_handle_snat_fwd_ipv4+0x1507> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe2f, 0x1507, x86_l_1507);
x86_l_e35:
	/* 0xe35: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_e38:
	/* 0xe38: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_e3c:
	/* 0xe3c: imul   r15d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R14, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_e40:
	/* 0xe40: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_e44:
	/* 0xe44: add    r15d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_e47:
	/* 0xe47: movbe  WORD PTR [rsp+0x10],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_e4f:
	/* 0xe4f: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_e54:
	/* 0xe54: mov    rdi,QWORD PTR [rip+0x59d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_e5b:
	/* 0xe5b: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e60:
	/* 0xe60: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e65:
	/* 0xe65: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_e6a:
	/* 0xe6a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e6c:
	/* 0xe6c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_e6e:
	/* 0xe6e: je     1515 <tail_handle_snat_fwd_ipv4+0x1515> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe6e, 0x1515, x86_l_1515);
x86_l_e74:
	/* 0xe74: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_e77:
	/* 0xe77: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_e7b:
	/* 0xe7b: imul   r15d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R14, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_e7f:
	/* 0xe7f: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_e83:
	/* 0xe83: add    r15d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_e86:
	/* 0xe86: movbe  WORD PTR [rsp+0x10],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_e8e:
	/* 0xe8e: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_e93:
	/* 0xe93: mov    rdi,QWORD PTR [rip+0x59d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_e9a:
	/* 0xe9a: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e9f:
	/* 0xe9f: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ea4:
	/* 0xea4: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_ea9:
	/* 0xea9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_eab:
	/* 0xeab: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ead:
	/* 0xead: je     1523 <tail_handle_snat_fwd_ipv4+0x1523> */
	X86_SIM_X86_JCC(X86_CC_E, 0xead, 0x1523, x86_l_1523);
x86_l_eb3:
	/* 0xeb3: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_eb6:
	/* 0xeb6: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_eba:
	/* 0xeba: imul   r15d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R14, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_ebe:
	/* 0xebe: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_ec2:
	/* 0xec2: add    r15d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_ec5:
	/* 0xec5: movbe  WORD PTR [rsp+0x10],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_ecd:
	/* 0xecd: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_ed2:
	/* 0xed2: mov    rdi,QWORD PTR [rip+0x59d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_ed9:
	/* 0xed9: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ede:
	/* 0xede: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ee3:
	/* 0xee3: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_ee8:
	/* 0xee8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_eea:
	/* 0xeea: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_eec:
	/* 0xeec: je     1531 <tail_handle_snat_fwd_ipv4+0x1531> */
	X86_SIM_X86_JCC(X86_CC_E, 0xeec, 0x1531, x86_l_1531);
x86_l_ef2:
	/* 0xef2: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_ef5:
	/* 0xef5: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_ef9:
	/* 0xef9: imul   r15d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R14, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_efd:
	/* 0xefd: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_f01:
	/* 0xf01: add    r15d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_f04:
	/* 0xf04: movbe  WORD PTR [rsp+0x10],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_f0c:
	/* 0xf0c: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_f11:
	/* 0xf11: mov    rdi,QWORD PTR [rip+0x59d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_f18:
	/* 0xf18: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f1d:
	/* 0xf1d: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f22:
	/* 0xf22: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_f27:
	/* 0xf27: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f29:
	/* 0xf29: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_f2b:
	/* 0xf2b: je     153f <tail_handle_snat_fwd_ipv4+0x153f> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf2b, 0x153f, x86_l_153f);
x86_l_f31:
	/* 0xf31: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_f34:
	/* 0xf34: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_f38:
	/* 0xf38: imul   r15d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R14, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_f3c:
	/* 0xf3c: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_f40:
	/* 0xf40: add    r15d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_f43:
	/* 0xf43: movbe  WORD PTR [rsp+0x10],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_f4b:
	/* 0xf4b: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_f50:
	/* 0xf50: mov    rdi,QWORD PTR [rip+0x59d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_f57:
	/* 0xf57: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f5c:
	/* 0xf5c: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f61:
	/* 0xf61: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_f66:
	/* 0xf66: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f68:
	/* 0xf68: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_f6a:
	/* 0xf6a: je     154d <tail_handle_snat_fwd_ipv4+0x154d> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf6a, 0x154d, x86_l_154d);
x86_l_f70:
	/* 0xf70: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_f73:
	/* 0xf73: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_f77:
	/* 0xf77: imul   r15d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R14, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_f7b:
	/* 0xf7b: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_f7f:
	/* 0xf7f: add    r15d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_f82:
	/* 0xf82: movbe  WORD PTR [rsp+0x10],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_f8a:
	/* 0xf8a: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_f8f:
	/* 0xf8f: mov    rdi,QWORD PTR [rip+0x59d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_f96:
	/* 0xf96: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f9b:
	/* 0xf9b: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_fa0:
	/* 0xfa0: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_fa5:
	/* 0xfa5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fa7:
	/* 0xfa7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_fa9:
	/* 0xfa9: je     155b <tail_handle_snat_fwd_ipv4+0x155b> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfa9, 0x155b, x86_l_155b);
x86_l_faf:
	/* 0xfaf: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_fb2:
	/* 0xfb2: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_fb6:
	/* 0xfb6: imul   r15d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R14, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_fba:
	/* 0xfba: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_fbe:
	/* 0xfbe: add    r15d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_fc1:
	/* 0xfc1: movbe  WORD PTR [rsp+0x10],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_fc9:
	/* 0xfc9: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_fce:
	/* 0xfce: mov    rdi,QWORD PTR [rip+0x59d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_fd5:
	/* 0xfd5: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fda:
	/* 0xfda: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_fdf:
	/* 0xfdf: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_fe4:
	/* 0xfe4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fe6:
	/* 0xfe6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_fe8:
	/* 0xfe8: je     1569 <tail_handle_snat_fwd_ipv4+0x1569> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfe8, 0x1569, x86_l_1569);
x86_l_fee:
	/* 0xfee: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_ff1:
	/* 0xff1: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_ff5:
	/* 0xff5: imul   r15d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R14, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_ff9:
	/* 0xff9: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_ffd:
	/* 0xffd: add    r15d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1000:
	/* 0x1000: movbe  WORD PTR [rsp+0x10],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_1008:
	/* 0x1008: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_100d:
	/* 0x100d: mov    rdi,QWORD PTR [rip+0x59d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_1014:
	/* 0x1014: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1019:
	/* 0x1019: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_101e:
	/* 0x101e: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1023:
	/* 0x1023: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1025:
	/* 0x1025: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1027:
	/* 0x1027: je     1577 <tail_handle_snat_fwd_ipv4+0x1577> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1027, 0x1577, x86_l_1577);
x86_l_102d:
	/* 0x102d: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1030:
	/* 0x1030: movzx  r15d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1034:
	/* 0x1034: imul   r15d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R14, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_1038:
	/* 0x1038: shr    r15d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_103c:
	/* 0x103c: add    r15d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_103f:
	/* 0x103f: movbe  WORD PTR [rsp+0x10],r15w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_1047:
	/* 0x1047: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_104c:
	/* 0x104c: mov    rdi,QWORD PTR [rip+0x59d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_1053:
	/* 0x1053: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1058:
	/* 0x1058: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_105d:
	/* 0x105d: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1062:
	/* 0x1062: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1064:
	/* 0x1064: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1066:
	/* 0x1066: je     1592 <tail_handle_snat_fwd_ipv4+0x1592> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1066, 0x1592, x86_l_1592);
x86_l_106c:
	/* 0x106c: inc    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_106f:
	/* 0x106f: movzx  r12d,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1073:
	/* 0x1073: imul   r12d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_1077:
	/* 0x1077: shr    r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_107b:
	/* 0x107b: add    r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_107e:
	/* 0x107e: movbe  WORD PTR [rsp+0x10],r12w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_1086:
	/* 0x1086: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_108b:
	/* 0x108b: mov    rdi,QWORD PTR [rip+0x59d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_1092:
	/* 0x1092: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1097:
	/* 0x1097: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_109c:
	/* 0x109c: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_10a1:
	/* 0x10a1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10a3:
	/* 0x10a3: mov    r15b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_8, 1ULL);
x86_l_10a6:
	/* 0x10a6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_10a8:
	/* 0x10a8: je     159d <tail_handle_snat_fwd_ipv4+0x159d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10a8, 0x159d, x86_l_159d);
x86_l_10ae:
	/* 0x10ae: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_10b1:
	/* 0x10b1: movzx  r12d,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_10b5:
	/* 0x10b5: imul   r12d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_10b9:
	/* 0x10b9: shr    r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_10bd:
	/* 0x10bd: add    r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_10c0:
	/* 0x10c0: movbe  WORD PTR [rsp+0x10],r12w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_10c8:
	/* 0x10c8: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_10cd:
	/* 0x10cd: mov    rdi,QWORD PTR [rip+0x59d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_10d4:
	/* 0x10d4: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10d9:
	/* 0x10d9: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_10de:
	/* 0x10de: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_10e3:
	/* 0x10e3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10e5:
	/* 0x10e5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_10e7:
	/* 0x10e7: je     15a5 <tail_handle_snat_fwd_ipv4+0x15a5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10e7, 0x15a5, x86_l_15a5);
x86_l_10ed:
	/* 0x10ed: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_10f0:
	/* 0x10f0: movzx  r12d,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_10f4:
	/* 0x10f4: imul   r12d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_10f8:
	/* 0x10f8: shr    r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_10fc:
	/* 0x10fc: add    r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_10ff:
	/* 0x10ff: movbe  WORD PTR [rsp+0x10],r12w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_1107:
	/* 0x1107: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_110c:
	/* 0x110c: mov    rdi,QWORD PTR [rip+0x59d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_1113:
	/* 0x1113: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1118:
	/* 0x1118: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_111d:
	/* 0x111d: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1122:
	/* 0x1122: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1124:
	/* 0x1124: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1126:
	/* 0x1126: je     15ad <tail_handle_snat_fwd_ipv4+0x15ad> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1126, 0x15ad, x86_l_15ad);
x86_l_112c:
	/* 0x112c: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_112f:
	/* 0x112f: movzx  r12d,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1133:
	/* 0x1133: imul   r12d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_1137:
	/* 0x1137: shr    r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_113b:
	/* 0x113b: add    r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_113e:
	/* 0x113e: movbe  WORD PTR [rsp+0x10],r12w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_1146:
	/* 0x1146: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_114b:
	/* 0x114b: mov    rdi,QWORD PTR [rip+0x59d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_1152:
	/* 0x1152: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1157:
	/* 0x1157: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_115c:
	/* 0x115c: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1161:
	/* 0x1161: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1163:
	/* 0x1163: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1165:
	/* 0x1165: je     15b5 <tail_handle_snat_fwd_ipv4+0x15b5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1165, 0x15b5, x86_l_15b5);
x86_l_116b:
	/* 0x116b: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_116e:
	/* 0x116e: movzx  r12d,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1172:
	/* 0x1172: imul   r12d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_1176:
	/* 0x1176: shr    r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_117a:
	/* 0x117a: add    r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_117d:
	/* 0x117d: movbe  WORD PTR [rsp+0x10],r12w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_1185:
	/* 0x1185: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_118a:
	/* 0x118a: mov    rdi,QWORD PTR [rip+0x59d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_1191:
	/* 0x1191: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1196:
	/* 0x1196: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_119b:
	/* 0x119b: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_11a0:
	/* 0x11a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11a2:
	/* 0x11a2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_11a4:
	/* 0x11a4: je     15bd <tail_handle_snat_fwd_ipv4+0x15bd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11a4, 0x15bd, x86_l_15bd);
x86_l_11aa:
	/* 0x11aa: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_11ad:
	/* 0x11ad: movzx  r12d,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_11b1:
	/* 0x11b1: imul   r12d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_11b5:
	/* 0x11b5: shr    r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_11b9:
	/* 0x11b9: add    r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_11bc:
	/* 0x11bc: movbe  WORD PTR [rsp+0x10],r12w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_11c4:
	/* 0x11c4: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_11c9:
	/* 0x11c9: mov    rdi,QWORD PTR [rip+0x59d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_11d0:
	/* 0x11d0: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11d5:
	/* 0x11d5: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_11da:
	/* 0x11da: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_11df:
	/* 0x11df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11e1:
	/* 0x11e1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_11e3:
	/* 0x11e3: je     15c5 <tail_handle_snat_fwd_ipv4+0x15c5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11e3, 0x15c5, x86_l_15c5);
x86_l_11e9:
	/* 0x11e9: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_11ec:
	/* 0x11ec: movzx  r12d,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_11f0:
	/* 0x11f0: imul   r12d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_11f4:
	/* 0x11f4: shr    r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_11f8:
	/* 0x11f8: add    r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_11fb:
	/* 0x11fb: movbe  WORD PTR [rsp+0x10],r12w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_1203:
	/* 0x1203: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1208:
	/* 0x1208: mov    rdi,QWORD PTR [rip+0x59d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_120f:
	/* 0x120f: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1214:
	/* 0x1214: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1219:
	/* 0x1219: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_121e:
	/* 0x121e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1220:
	/* 0x1220: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1222:
	/* 0x1222: je     15cd <tail_handle_snat_fwd_ipv4+0x15cd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1222, 0x15cd, x86_l_15cd);
x86_l_1228:
	/* 0x1228: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_122b:
	/* 0x122b: movzx  r12d,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_122f:
	/* 0x122f: imul   r12d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_1233:
	/* 0x1233: shr    r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1237:
	/* 0x1237: add    r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_123a:
	/* 0x123a: movbe  WORD PTR [rsp+0x10],r12w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_1242:
	/* 0x1242: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1247:
	/* 0x1247: mov    rdi,QWORD PTR [rip+0x59d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_124e:
	/* 0x124e: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1253:
	/* 0x1253: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1258:
	/* 0x1258: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_125d:
	/* 0x125d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_125f:
	/* 0x125f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1261:
	/* 0x1261: je     15d5 <tail_handle_snat_fwd_ipv4+0x15d5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1261, 0x15d5, x86_l_15d5);
x86_l_1267:
	/* 0x1267: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_126a:
	/* 0x126a: movzx  r12d,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_126e:
	/* 0x126e: imul   r12d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_1272:
	/* 0x1272: shr    r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1276:
	/* 0x1276: add    r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1279:
	/* 0x1279: movbe  WORD PTR [rsp+0x10],r12w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_1281:
	/* 0x1281: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1286:
	/* 0x1286: mov    rdi,QWORD PTR [rip+0x59d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_128d:
	/* 0x128d: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1292:
	/* 0x1292: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1297:
	/* 0x1297: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_129c:
	/* 0x129c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_129e:
	/* 0x129e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_12a0:
	/* 0x12a0: je     15dd <tail_handle_snat_fwd_ipv4+0x15dd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12a0, 0x15dd, x86_l_15dd);
x86_l_12a6:
	/* 0x12a6: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_12a9:
	/* 0x12a9: movzx  r12d,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_12ad:
	/* 0x12ad: imul   r12d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_12b1:
	/* 0x12b1: shr    r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_12b5:
	/* 0x12b5: add    r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_12b8:
	/* 0x12b8: movbe  WORD PTR [rsp+0x10],r12w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_12c0:
	/* 0x12c0: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_12c5:
	/* 0x12c5: mov    rdi,QWORD PTR [rip+0x59d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_12cc:
	/* 0x12cc: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12d1:
	/* 0x12d1: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_12d6:
	/* 0x12d6: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_12db:
	/* 0x12db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12dd:
	/* 0x12dd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_12df:
	/* 0x12df: je     15e5 <tail_handle_snat_fwd_ipv4+0x15e5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12df, 0x15e5, x86_l_15e5);
x86_l_12e5:
	/* 0x12e5: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_12e8:
	/* 0x12e8: movzx  r12d,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_12ec:
	/* 0x12ec: imul   r12d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_12f0:
	/* 0x12f0: shr    r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_12f4:
	/* 0x12f4: add    r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_12f7:
	/* 0x12f7: movbe  WORD PTR [rsp+0x10],r12w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_12ff:
	/* 0x12ff: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1304:
	/* 0x1304: mov    rdi,QWORD PTR [rip+0x59d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_130b:
	/* 0x130b: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1310:
	/* 0x1310: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1315:
	/* 0x1315: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_131a:
	/* 0x131a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_131c:
	/* 0x131c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_131e:
	/* 0x131e: je     15ed <tail_handle_snat_fwd_ipv4+0x15ed> */
	X86_SIM_X86_JCC(X86_CC_E, 0x131e, 0x15ed, x86_l_15ed);
x86_l_1324:
	/* 0x1324: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1327:
	/* 0x1327: movzx  r12d,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_132b:
	/* 0x132b: imul   r12d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_132f:
	/* 0x132f: shr    r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1333:
	/* 0x1333: add    r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1336:
	/* 0x1336: movbe  WORD PTR [rsp+0x10],r12w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_133e:
	/* 0x133e: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1343:
	/* 0x1343: mov    rdi,QWORD PTR [rip+0x59d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_134a:
	/* 0x134a: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_134f:
	/* 0x134f: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1354:
	/* 0x1354: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1359:
	/* 0x1359: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_135b:
	/* 0x135b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_135d:
	/* 0x135d: je     15f5 <tail_handle_snat_fwd_ipv4+0x15f5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x135d, 0x15f5, x86_l_15f5);
x86_l_1363:
	/* 0x1363: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1366:
	/* 0x1366: movzx  r12d,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_136a:
	/* 0x136a: imul   r12d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_136e:
	/* 0x136e: shr    r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1372:
	/* 0x1372: add    r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1375:
	/* 0x1375: movbe  WORD PTR [rsp+0x10],r12w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_137d:
	/* 0x137d: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1382:
	/* 0x1382: mov    rdi,QWORD PTR [rip+0x59d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_1389:
	/* 0x1389: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_138e:
	/* 0x138e: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1393:
	/* 0x1393: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1398:
	/* 0x1398: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_139a:
	/* 0x139a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_139c:
	/* 0x139c: je     15fd <tail_handle_snat_fwd_ipv4+0x15fd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x139c, 0x15fd, x86_l_15fd);
x86_l_13a2:
	/* 0x13a2: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_13a5:
	/* 0x13a5: movzx  r12d,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R12, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_13a9:
	/* 0x13a9: imul   r12d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R14, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_13ad:
	/* 0x13ad: shr    r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_13b1:
	/* 0x13b1: add    r12d,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_13b4:
	/* 0x13b4: movbe  WORD PTR [rsp+0x10],r12w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_13bc:
	/* 0x13bc: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_13c1:
	/* 0x13c1: mov    rdi,QWORD PTR [rip+0x59d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_13c8:
	/* 0x13c8: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13cd:
	/* 0x13cd: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_13d2:
	/* 0x13d2: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_13d7:
	/* 0x13d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13d9:
	/* 0x13d9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_13db:
	/* 0x13db: je     1605 <tail_handle_snat_fwd_ipv4+0x1605> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13db, 0x1605, x86_l_1605);
x86_l_13e1:
	/* 0x13e1: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_13e4:
	/* 0x13e4: movzx  eax,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_13e8:
	/* 0x13e8: imul   r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_IMUL);
x86_l_13ec:
	/* 0x13ec: shr    r14d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_13f0:
	/* 0x13f0: add    ebp,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R14, X86_WIDTH_32, X86_ALU_ADD);
x86_l_13f3:
	/* 0x13f3: movbe  WORD PTR [rsp+0x10],bp */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_13fa:
	/* 0x13fa: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_13ff:
	/* 0x13ff: mov    rdi,QWORD PTR [rip+0x59d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_1406:
	/* 0x1406: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_140b:
	/* 0x140b: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1410:
	/* 0x1410: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1415:
	/* 0x1415: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1417:
	/* 0x1417: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1419:
	/* 0x1419: je     160d <tail_handle_snat_fwd_ipv4+0x160d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1419, 0x160d, x86_l_160d);
x86_l_141f:
	/* 0x141f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1424:
	/* 0x1424: mov    DWORD PTR [rsp+0x9c],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 670014898208ULL);
x86_l_142f:
	/* 0x142f: mov    rdi,QWORD PTR [rip+0x59d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_alloc_retries)));
x86_l_1436:
	/* 0x1436: lea    rsi,[rsp+0x9c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_143e:
	/* 0x143e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1440:
	/* 0x1440: mov    r13d,0xffffff59 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967129ULL);
x86_l_1446:
	/* 0x1446: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1449:
	/* 0x1449: je     144d <tail_handle_snat_fwd_ipv4+0x144d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1449, 0x144d, x86_l_144d);
x86_l_144b:
	/* 0x144b: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_144d:
	/* 0x144d: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_144f:
	/* 0x144f: lea    r14,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1454:
	/* 0x1454: jmp    1698 <tail_handle_snat_fwd_ipv4+0x1698> */
	X86_SIM_X86_JMP(0x1454, 0x1698, x86_l_1698);
x86_l_1459:
	/* 0x1459: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_145c:
	/* 0x145c: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_145f:
	/* 0x145f: jmp    1613 <tail_handle_snat_fwd_ipv4+0x1613> */
	X86_SIM_X86_JMP(0x145f, 0x1613, x86_l_1613);
x86_l_1464:
	/* 0x1464: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_146a:
	/* 0x146a: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_146d:
	/* 0x146d: jmp    1613 <tail_handle_snat_fwd_ipv4+0x1613> */
	X86_SIM_X86_JMP(0x146d, 0x1613, x86_l_1613);
x86_l_1472:
	/* 0x1472: mov    r12d,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 3ULL);
x86_l_1478:
	/* 0x1478: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_147b:
	/* 0x147b: jmp    1613 <tail_handle_snat_fwd_ipv4+0x1613> */
	X86_SIM_X86_JMP(0x147b, 0x1613, x86_l_1613);
x86_l_1480:
	/* 0x1480: mov    r12d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4ULL);
x86_l_1486:
	/* 0x1486: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1489:
	/* 0x1489: jmp    1613 <tail_handle_snat_fwd_ipv4+0x1613> */
	X86_SIM_X86_JMP(0x1489, 0x1613, x86_l_1613);
x86_l_148e:
	/* 0x148e: mov    r12d,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 5ULL);
x86_l_1494:
	/* 0x1494: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1497:
	/* 0x1497: jmp    1613 <tail_handle_snat_fwd_ipv4+0x1613> */
	X86_SIM_X86_JMP(0x1497, 0x1613, x86_l_1613);
x86_l_149c:
	/* 0x149c: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_14a1:
	/* 0x14a1: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14a3:
	/* 0x14a3: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_14a5:
	/* 0x14a5: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_14a9:
	/* 0x14a9: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_14b3:
	/* 0x14b3: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_14b6:
	/* 0x14b6: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_14bb:
	/* 0x14bb: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_14bf:
	/* 0x14bf: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_14c4:
	/* 0x14c4: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_14c9:
	/* 0x14c9: mov    rdi,QWORD PTR [rip+0x59d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_14d0:
	/* 0x14d0: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_14d5:
	/* 0x14d5: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_14da:
	/* 0x14da: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14dc:
	/* 0x14dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14de:
	/* 0x14de: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_14e0:
	/* 0x14e0: js     14ec <tail_handle_snat_fwd_ipv4+0x14ec> */
	X86_SIM_X86_JCC(X86_CC_S, 0x14e0, 0x14ec, x86_l_14ec);
x86_l_14e2:
	/* 0x14e2: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14e4:
	/* 0x14e4: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14e7:
	/* 0x14e7: jmp    16cb <tail_handle_snat_fwd_ipv4+0x16cb> */
	X86_SIM_X86_JMP(0x14e7, 0x16cb, x86_l_16cb);
x86_l_14ec:
	/* 0x14ec: mov    ebp,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_14ee:
	/* 0x14ee: mov    r13d,0xffffff59 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967129ULL);
x86_l_14f4:
	/* 0x14f4: jmp    16cb <tail_handle_snat_fwd_ipv4+0x16cb> */
	X86_SIM_X86_JMP(0x14f4, 0x16cb, x86_l_16cb);
x86_l_14f9:
	/* 0x14f9: mov    r12d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 6ULL);
x86_l_14ff:
	/* 0x14ff: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1502:
	/* 0x1502: jmp    1613 <tail_handle_snat_fwd_ipv4+0x1613> */
	X86_SIM_X86_JMP(0x1502, 0x1613, x86_l_1613);
x86_l_1507:
	/* 0x1507: mov    r12d,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 7ULL);
x86_l_150d:
	/* 0x150d: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1510:
	/* 0x1510: jmp    1613 <tail_handle_snat_fwd_ipv4+0x1613> */
	X86_SIM_X86_JMP(0x1510, 0x1613, x86_l_1613);
x86_l_1515:
	/* 0x1515: mov    r12d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 8ULL);
x86_l_151b:
	/* 0x151b: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_151e:
	/* 0x151e: jmp    1613 <tail_handle_snat_fwd_ipv4+0x1613> */
	X86_SIM_X86_JMP(0x151e, 0x1613, x86_l_1613);
x86_l_1523:
	/* 0x1523: mov    r12d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 9ULL);
x86_l_1529:
	/* 0x1529: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_152c:
	/* 0x152c: jmp    1613 <tail_handle_snat_fwd_ipv4+0x1613> */
	X86_SIM_X86_JMP(0x152c, 0x1613, x86_l_1613);
x86_l_1531:
	/* 0x1531: mov    r12d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 10ULL);
x86_l_1537:
	/* 0x1537: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_153a:
	/* 0x153a: jmp    1613 <tail_handle_snat_fwd_ipv4+0x1613> */
	X86_SIM_X86_JMP(0x153a, 0x1613, x86_l_1613);
x86_l_153f:
	/* 0x153f: mov    r12d,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 11ULL);
x86_l_1545:
	/* 0x1545: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1548:
	/* 0x1548: jmp    1613 <tail_handle_snat_fwd_ipv4+0x1613> */
	X86_SIM_X86_JMP(0x1548, 0x1613, x86_l_1613);
x86_l_154d:
	/* 0x154d: mov    r12d,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 12ULL);
x86_l_1553:
	/* 0x1553: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1556:
	/* 0x1556: jmp    1613 <tail_handle_snat_fwd_ipv4+0x1613> */
	X86_SIM_X86_JMP(0x1556, 0x1613, x86_l_1613);
x86_l_155b:
	/* 0x155b: mov    r12d,0xd */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 13ULL);
x86_l_1561:
	/* 0x1561: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1564:
	/* 0x1564: jmp    1613 <tail_handle_snat_fwd_ipv4+0x1613> */
	X86_SIM_X86_JMP(0x1564, 0x1613, x86_l_1613);
x86_l_1569:
	/* 0x1569: mov    r12d,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 14ULL);
x86_l_156f:
	/* 0x156f: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1572:
	/* 0x1572: jmp    1613 <tail_handle_snat_fwd_ipv4+0x1613> */
	X86_SIM_X86_JMP(0x1572, 0x1613, x86_l_1613);
x86_l_1577:
	/* 0x1577: mov    r12d,0xf */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 15ULL);
x86_l_157d:
	/* 0x157d: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1580:
	/* 0x1580: jmp    1613 <tail_handle_snat_fwd_ipv4+0x1613> */
	X86_SIM_X86_JMP(0x1580, 0x1613, x86_l_1613);
x86_l_1585:
	/* 0x1585: mov    ebp,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_1587:
	/* 0x1587: mov    r13d,0xffffff65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967141ULL);
x86_l_158d:
	/* 0x158d: jmp    18b4 <tail_handle_snat_fwd_ipv4+0x18b4> */
	X86_SIM_X86_JMP(0x158d, 0x18b4, x86_l_18b4);
x86_l_1592:
	/* 0x1592: mov    r12d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 16ULL);
x86_l_1598:
	/* 0x1598: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_159b:
	/* 0x159b: jmp    1613 <tail_handle_snat_fwd_ipv4+0x1613> */
	X86_SIM_X86_JMP(0x159b, 0x1613, x86_l_1613);
x86_l_159d:
	/* 0x159d: mov    r12d,0x11 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 17ULL);
x86_l_15a3:
	/* 0x15a3: jmp    1613 <tail_handle_snat_fwd_ipv4+0x1613> */
	X86_SIM_X86_JMP(0x15a3, 0x1613, x86_l_1613);
x86_l_15a5:
	/* 0x15a5: mov    r12d,0x12 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 18ULL);
x86_l_15ab:
	/* 0x15ab: jmp    1613 <tail_handle_snat_fwd_ipv4+0x1613> */
	X86_SIM_X86_JMP(0x15ab, 0x1613, x86_l_1613);
x86_l_15ad:
	/* 0x15ad: mov    r12d,0x13 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 19ULL);
x86_l_15b3:
	/* 0x15b3: jmp    1613 <tail_handle_snat_fwd_ipv4+0x1613> */
	X86_SIM_X86_JMP(0x15b3, 0x1613, x86_l_1613);
x86_l_15b5:
	/* 0x15b5: mov    r12d,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 20ULL);
x86_l_15bb:
	/* 0x15bb: jmp    1613 <tail_handle_snat_fwd_ipv4+0x1613> */
	X86_SIM_X86_JMP(0x15bb, 0x1613, x86_l_1613);
x86_l_15bd:
	/* 0x15bd: mov    r12d,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 21ULL);
x86_l_15c3:
	/* 0x15c3: jmp    1613 <tail_handle_snat_fwd_ipv4+0x1613> */
	X86_SIM_X86_JMP(0x15c3, 0x1613, x86_l_1613);
x86_l_15c5:
	/* 0x15c5: mov    r12d,0x16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 22ULL);
x86_l_15cb:
	/* 0x15cb: jmp    1613 <tail_handle_snat_fwd_ipv4+0x1613> */
	X86_SIM_X86_JMP(0x15cb, 0x1613, x86_l_1613);
x86_l_15cd:
	/* 0x15cd: mov    r12d,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 23ULL);
x86_l_15d3:
	/* 0x15d3: jmp    1613 <tail_handle_snat_fwd_ipv4+0x1613> */
	X86_SIM_X86_JMP(0x15d3, 0x1613, x86_l_1613);
x86_l_15d5:
	/* 0x15d5: mov    r12d,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 24ULL);
x86_l_15db:
	/* 0x15db: jmp    1613 <tail_handle_snat_fwd_ipv4+0x1613> */
	X86_SIM_X86_JMP(0x15db, 0x1613, x86_l_1613);
x86_l_15dd:
	/* 0x15dd: mov    r12d,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 25ULL);
x86_l_15e3:
	/* 0x15e3: jmp    1613 <tail_handle_snat_fwd_ipv4+0x1613> */
	X86_SIM_X86_JMP(0x15e3, 0x1613, x86_l_1613);
x86_l_15e5:
	/* 0x15e5: mov    r12d,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 26ULL);
x86_l_15eb:
	/* 0x15eb: jmp    1613 <tail_handle_snat_fwd_ipv4+0x1613> */
	X86_SIM_X86_JMP(0x15eb, 0x1613, x86_l_1613);
x86_l_15ed:
	/* 0x15ed: mov    r12d,0x1b */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 27ULL);
x86_l_15f3:
	/* 0x15f3: jmp    1613 <tail_handle_snat_fwd_ipv4+0x1613> */
	X86_SIM_X86_JMP(0x15f3, 0x1613, x86_l_1613);
x86_l_15f5:
	/* 0x15f5: mov    r12d,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 28ULL);
x86_l_15fb:
	/* 0x15fb: jmp    1613 <tail_handle_snat_fwd_ipv4+0x1613> */
	X86_SIM_X86_JMP(0x15fb, 0x1613, x86_l_1613);
x86_l_15fd:
	/* 0x15fd: mov    r12d,0x1d */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 29ULL);
x86_l_1603:
	/* 0x1603: jmp    1613 <tail_handle_snat_fwd_ipv4+0x1613> */
	X86_SIM_X86_JMP(0x1603, 0x1613, x86_l_1613);
x86_l_1605:
	/* 0x1605: mov    r12d,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 30ULL);
x86_l_160b:
	/* 0x160b: jmp    1613 <tail_handle_snat_fwd_ipv4+0x1613> */
	X86_SIM_X86_JMP(0x160b, 0x1613, x86_l_1613);
x86_l_160d:
	/* 0x160d: mov    r12d,0x1f */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 31ULL);
x86_l_1613:
	/* 0x1613: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1618:
	/* 0x1618: mov    DWORD PTR [rsp+0x9c],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_1620:
	/* 0x1620: mov    rdi,QWORD PTR [rip+0x59d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_alloc_retries)));
x86_l_1627:
	/* 0x1627: lea    rsi,[rsp+0x9c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_162f:
	/* 0x162f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1631:
	/* 0x1631: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1634:
	/* 0x1634: je     1638 <tail_handle_snat_fwd_ipv4+0x1638> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1634, 0x1638, x86_l_1638);
x86_l_1636:
	/* 0x1636: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1638:
	/* 0x1638: movzx  eax,WORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_163d:
	/* 0x163d: mov    WORD PTR [rsp+0x94],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_1645:
	/* 0x1645: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_164a:
	/* 0x164a: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_164f:
	/* 0x164f: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1654:
	/* 0x1654: mov    rdi,QWORD PTR [rip+0x59d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_165b:
	/* 0x165b: lea    rsi,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1660:
	/* 0x1660: lea    rdx,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1665:
	/* 0x1665: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1667:
	/* 0x1667: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1669:
	/* 0x1669: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_166b:
	/* 0x166b: mov    r13d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_166e:
	/* 0x166e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1670:
	/* 0x1670: lea    r14,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1675:
	/* 0x1675: jns    1693 <tail_handle_snat_fwd_ipv4+0x1693> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1675, 0x1693, x86_l_1693);
x86_l_1677:
	/* 0x1677: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_167c:
	/* 0x167c: mov    rdi,QWORD PTR [rip+0x59d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_1683:
	/* 0x1683: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1688:
	/* 0x1688: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_168a:
	/* 0x168a: mov    ebp,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R13, X86_WIDTH_32);
x86_l_168d:
	/* 0x168d: mov    r13d,0xffffff59 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967129ULL);
x86_l_1693:
	/* 0x1693: test   r15b,r15b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_8);
x86_l_1696:
	/* 0x1696: je     16c8 <tail_handle_snat_fwd_ipv4+0x16c8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1696, 0x16c8, x86_l_16c8);
x86_l_1698:
	/* 0x1698: mov    QWORD PTR [rsp+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_16a4:
	/* 0x16a4: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_16a9:
	/* 0x16a9: mov    rsi,QWORD PTR [rip+0x59d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_signals)));
x86_l_16b0:
	/* 0x16b0: lea    rcx,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_16b8:
	/* 0x16b8: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_16bd:
	/* 0x16bd: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_16c0:
	/* 0x16c0: mov    r8d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 8ULL);
x86_l_16c6:
	/* 0x16c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16c8:
	/* 0x16c8: mov    r15,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R14, X86_WIDTH_64);
x86_l_16cb:
	/* 0x16cb: mov    r11d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_16d0:
	/* 0x16d0: test   r13d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_32);
x86_l_16d3:
	/* 0x16d3: js     18b9 <tail_handle_snat_fwd_ipv4+0x18b9> */
	X86_SIM_X86_JCC(X86_CC_S, 0x16d3, 0x18b9, x86_l_18b9);
x86_l_16d9:
	/* 0x16d9: movzx  r14d,WORD PTR [r15+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_16de:
	/* 0x16de: movzx  edx,BYTE PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 40ULL);
x86_l_16e3:
	/* 0x16e3: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_16e7:
	/* 0x16e7: mov    r15d,DWORD PTR [r15+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_16eb:
	/* 0x16eb: movzx  r12d,WORD PTR [rsp+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_16f1:
	/* 0x16f1: mov    DWORD PTR [rsp+0x30],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_16f6:
	/* 0x16f6: cmp    eax,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_16f9:
	/* 0x16f9: jne    1708 <tail_handle_snat_fwd_ipv4+0x1708> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x16f9, 0x1708, x86_l_1708);
x86_l_16fb:
	/* 0x16fb: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16fe:
	/* 0x16fe: cmp    r12w,r14w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_R14, X86_WIDTH_16);
x86_l_1702:
	/* 0x1702: je     18b9 <tail_handle_snat_fwd_ipv4+0x18b9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1702, 0x18b9, x86_l_18b9);
x86_l_1708:
	/* 0x1708: mov    DWORD PTR [rsp+0x68],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_170c:
	/* 0x170c: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_170e:
	/* 0x170e: add    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1711:
	/* 0x1711: adc    r15d,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_1715:
	/* 0x1715: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_171a:
	/* 0x171a: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_171f:
	/* 0x171f: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1722:
	/* 0x1722: mov    esi,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 26ULL);
x86_l_1727:
	/* 0x1727: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_172c:
	/* 0x172c: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_172f:
	/* 0x172f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1731:
	/* 0x1731: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1733:
	/* 0x1733: js     18ae <tail_handle_snat_fwd_ipv4+0x18ae> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1733, 0x18ae, x86_l_18ae);
x86_l_1739:
	/* 0x1739: mov    eax,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_173e:
	/* 0x173e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1741:
	/* 0x1741: mov    esi,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 24ULL);
x86_l_1746:
	/* 0x1746: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1748:
	/* 0x1748: mov    ecx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_32);
x86_l_174b:
	/* 0x174b: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_174e:
	/* 0x174e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1750:
	/* 0x1750: mov    r13d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_1753:
	/* 0x1753: sar    r13d,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SAR, 31ULL);
x86_l_1757:
	/* 0x1757: and    r13d,0xffffff67 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4294967143ULL);
x86_l_175e:
	/* 0x175e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1760:
	/* 0x1760: js     18b4 <tail_handle_snat_fwd_ipv4+0x18b4> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1760, 0x18b4, x86_l_18b4);
x86_l_1766:
	/* 0x1766: cmp    QWORD PTR [rsp+0xc0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 824633720832ULL);
x86_l_176f:
	/* 0x176f: mov    r11d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1774:
	/* 0x1774: mov    rcx,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_177c:
	/* 0x177c: mov    eax,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1780:
	/* 0x1780: jne    18b9 <tail_handle_snat_fwd_ipv4+0x18b9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1780, 0x18b9, x86_l_18b9);
x86_l_1786:
	/* 0x1786: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1789:
	/* 0x1789: cmp    eax,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 58ULL);
x86_l_178c:
	/* 0x178c: je     17aa <tail_handle_snat_fwd_ipv4+0x17aa> */
	X86_SIM_X86_JCC(X86_CC_E, 0x178c, 0x17aa, x86_l_17aa);
x86_l_178e:
	/* 0x178e: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_1791:
	/* 0x1791: je     179e <tail_handle_snat_fwd_ipv4+0x179e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1791, 0x179e, x86_l_179e);
x86_l_1793:
	/* 0x1793: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_1796:
	/* 0x1796: jne    17b0 <tail_handle_snat_fwd_ipv4+0x17b0> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1796, 0x17b0, x86_l_17b0);
x86_l_1798:
	/* 0x1798: mov    dx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_16, 16ULL);
x86_l_179c:
	/* 0x179c: jmp    17b2 <tail_handle_snat_fwd_ipv4+0x17b2> */
	X86_SIM_X86_JMP(0x179c, 0x17b2, x86_l_17b2);
x86_l_179e:
	/* 0x179e: mov    r8d,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 32ULL);
x86_l_17a4:
	/* 0x17a4: mov    dx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_16, 6ULL);
x86_l_17a8:
	/* 0x17a8: jmp    17b2 <tail_handle_snat_fwd_ipv4+0x17b2> */
	X86_SIM_X86_JMP(0x17a8, 0x17b2, x86_l_17b2);
x86_l_17aa:
	/* 0x17aa: mov    dx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_16, 2ULL);
x86_l_17ae:
	/* 0x17ae: jmp    17b2 <tail_handle_snat_fwd_ipv4+0x17b2> */
	X86_SIM_X86_JMP(0x17ae, 0x17b2, x86_l_17b2);
x86_l_17b0:
	/* 0x17b0: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17b2:
	/* 0x17b2: cmp    r12w,r14w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_R14, X86_WIDTH_16);
x86_l_17b6:
	/* 0x17b6: jne    17fe <tail_handle_snat_fwd_ipv4+0x17fe> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x17b6, 0x17fe, x86_l_17fe);
x86_l_17b8:
	/* 0x17b8: test   dx,dx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_16);
x86_l_17bb:
	/* 0x17bb: je     194a <tail_handle_snat_fwd_ipv4+0x194a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x17bb, 0x194a, x86_l_194a);
x86_l_17c1:
	/* 0x17c1: movzx  esi,dx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_RDX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_17c4:
	/* 0x17c4: add    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_17c6:
	/* 0x17c6: or     r8d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 16ULL);
x86_l_17ca:
	/* 0x17ca: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_17cf:
	/* 0x17cf: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_17d2:
	/* 0x17d2: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_17d4:
	/* 0x17d4: mov    ecx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_32);
x86_l_17d7:
	/* 0x17d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17d9:
	/* 0x17d9: mov    r11d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_17de:
	/* 0x17de: mov    r13d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_17e1:
	/* 0x17e1: sar    r13d,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SAR, 31ULL);
x86_l_17e5:
	/* 0x17e5: and    r13d,0xffffff66 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 4294967142ULL);
x86_l_17ec:
	/* 0x17ec: cmp    r13d,0xffffff53 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4294967123ULL);
x86_l_17f3:
	/* 0x17f3: jne    195a <tail_handle_snat_fwd_ipv4+0x195a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x17f3, 0x195a, x86_l_195a);
x86_l_17f9:
	/* 0x17f9: jmp    18c6 <tail_handle_snat_fwd_ipv4+0x18c6> */
	X86_SIM_X86_JMP(0x17f9, 0x18c6, x86_l_18c6);
x86_l_17fe:
	/* 0x17fe: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_1801:
	/* 0x1801: je     181b <tail_handle_snat_fwd_ipv4+0x181b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1801, 0x181b, x86_l_181b);
x86_l_1803:
	/* 0x1803: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_1806:
	/* 0x1806: je     181b <tail_handle_snat_fwd_ipv4+0x181b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1806, 0x181b, x86_l_181b);
x86_l_1808:
	/* 0x1808: mov    r13d,0xffffff72 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967154ULL);
x86_l_180e:
	/* 0x180e: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1811:
	/* 0x1811: jne    18b9 <tail_handle_snat_fwd_ipv4+0x18b9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1811, 0x18b9, x86_l_18b9);
x86_l_1817:
	/* 0x1817: mov    dx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_16, 2ULL);
x86_l_181b:
	/* 0x181b: mov    DWORD PTR [rsp+0x2c],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_181f:
	/* 0x181f: mov    DWORD PTR [rsp+0xa0],r8d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_1827:
	/* 0x1827: mov    WORD PTR [rsp+0xa8],r14w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1830:
	/* 0x1830: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_1835:
	/* 0x1835: lea    rdx,[rsp+0xa8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_183d:
	/* 0x183d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1840:
	/* 0x1840: mov    esi,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RCX, X86_WIDTH_32);
x86_l_1842:
	/* 0x1842: mov    r14,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RCX, X86_WIDTH_64);
x86_l_1845:
	/* 0x1845: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_184a:
	/* 0x184a: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_184d:
	/* 0x184d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_184f:
	/* 0x184f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1851:
	/* 0x1851: js     18ae <tail_handle_snat_fwd_ipv4+0x18ae> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1851, 0x18ae, x86_l_18ae);
x86_l_1853:
	/* 0x1853: movzx  edx,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1857:
	/* 0x1857: movzx  ecx,WORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 168ULL);
x86_l_185f:
	/* 0x185f: movzx  esi,WORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 44ULL);
x86_l_1864:
	/* 0x1864: add    esi,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R14, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1867:
	/* 0x1867: mov    r8d,DWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_186f:
	/* 0x186f: or     r8d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_1873:
	/* 0x1873: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_1878:
	/* 0x1878: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_187b:
	/* 0x187b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_187d:
	/* 0x187d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_187f:
	/* 0x187f: js     196b <tail_handle_snat_fwd_ipv4+0x196b> */
	X86_SIM_X86_JCC(X86_CC_S, 0x187f, 0x196b, x86_l_196b);
x86_l_1885:
	/* 0x1885: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1888:
	/* 0x1888: cmp    DWORD PTR [rsp+0x68],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 446676598785ULL);
x86_l_188d:
	/* 0x188d: mov    r11d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1892:
	/* 0x1892: mov    rcx,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_189a:
	/* 0x189a: mov    r8d,DWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_18a2:
	/* 0x18a2: mov    edx,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_18a6:
	/* 0x18a6: jne    17b8 <tail_handle_snat_fwd_ipv4+0x17b8> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x18a6, 0x17b8, x86_l_17b8);
x86_l_18ac:
	/* 0x18ac: jmp    18b9 <tail_handle_snat_fwd_ipv4+0x18b9> */
	X86_SIM_X86_JMP(0x18ac, 0x18b9, x86_l_18b9);
x86_l_18ae:
	/* 0x18ae: mov    r13d,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967155ULL);
x86_l_18b4:
	/* 0x18b4: mov    r11d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_18b9:
	/* 0x18b9: cmp    r13d,0xffffff53 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4294967123ULL);
x86_l_18c0:
	/* 0x18c0: jne    195a <tail_handle_snat_fwd_ipv4+0x195a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x18c0, 0x195a, x86_l_195a);
x86_l_18c6:
	/* 0x18c6: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_18c9:
	/* 0x18c9: mov    rcx,QWORD PTR [rip+0x59d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_interface_ifindex)));
x86_l_18d0:
	/* 0x18d0: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18d2:
	/* 0x18d2: mov    ebx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_32);
x86_l_18d4:
	/* 0x18d4: movabs rax,0x7101bc0200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 485360402944ULL);
x86_l_18de:
	/* 0x18de: add    rax,0xa0000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 655360ULL);
x86_l_18e4:
	/* 0x18e4: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_18e9:
	/* 0x18e9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_18ee:
	/* 0x18ee: mov    rdi,QWORD PTR [rip+0x59d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_18f5:
	/* 0x18f5: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_18fa:
	/* 0x18fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18fc:
	/* 0x18fc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_18ff:
	/* 0x18ff: je     190a <tail_handle_snat_fwd_ipv4+0x190a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x18ff, 0x190a, x86_l_190a);
x86_l_1901:
	/* 0x1901: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1904:
	/* 0x1904: add    QWORD PTR [rax+0x8],rbx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1908:
	/* 0x1908: jmp    1932 <tail_handle_snat_fwd_ipv4+0x1932> */
	X86_SIM_X86_JMP(0x1908, 0x1932, x86_l_1932);
x86_l_190a:
	/* 0x190a: mov    QWORD PTR [rsp+0x30],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430209ULL);
x86_l_1913:
	/* 0x1913: mov    QWORD PTR [rsp+0x38],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1918:
	/* 0x1918: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_191d:
	/* 0x191d: mov    rdi,QWORD PTR [rip+0x59d8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1924:
	/* 0x1924: lea    rsi,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1929:
	/* 0x1929: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_192e:
	/* 0x192e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1930:
	/* 0x1930: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1932:
	/* 0x1932: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1934:
	/* 0x1934: add    rsp,0xc8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 200ULL);
x86_l_193b:
	/* 0x193b: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_193c:
	/* 0x193c: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_193e:
	/* 0x193e: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_1940:
	/* 0x1940: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_1942:
	/* 0x1942: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_1944:
	/* 0x1944: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_1945:
	/* 0x1945: jmp    1976 <tail_handle_snat_fwd_ipv4+0x1976> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_194a:
	/* 0x194a: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_194d:
	/* 0x194d: cmp    r13d,0xffffff53 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 4294967123ULL);
x86_l_1954:
	/* 0x1954: je     18c6 <tail_handle_snat_fwd_ipv4+0x18c6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1954, 0x18c6, x86_l_18c6);
x86_l_195a:
	/* 0x195a: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_195d:
	/* 0x195d: test   r13d,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_32);
x86_l_1960:
	/* 0x1960: jns    18c9 <tail_handle_snat_fwd_ipv4+0x18c9> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1960, 0x18c9, x86_l_18c9);
x86_l_1966:
	/* 0x1966: jmp    4a <tail_handle_snat_fwd_ipv4+0x4a> */
	X86_SIM_X86_JMP(0x1966, 0x4a, x86_l_4a);
x86_l_196b:
	/* 0x196b: mov    r13d,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967142ULL);
x86_l_1971:
	/* 0x1971: jmp    18b4 <tail_handle_snat_fwd_ipv4+0x18b4> */
	X86_SIM_X86_JMP(0x1971, 0x18b4, x86_l_18b4);
x86_l_1976:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
