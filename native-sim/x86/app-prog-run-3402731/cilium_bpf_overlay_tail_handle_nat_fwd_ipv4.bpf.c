extern char __config_debug_lb;
extern char __config_enable_conntrack_accounting;
extern char __config_enable_ipv4_fragments;
extern char __config_enable_jiffies;
extern char __config_interface_ifindex;
extern char __config_kernel_hz;
extern char __config_trace_payload_len;
extern char cilium_calls;
extern char cilium_ct4_global;
extern char cilium_ct_any4_global;
extern char cilium_ipv4_frag_datagrams;
extern char cilium_lb4_reverse_nat;
extern char cilium_metrics;
extern char cilium_snat_v4_external;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int cilium_bpf_overlay_tail_handle_nat_fwd_ipv4_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0xa: sub    rsp,0x68 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 104ULL);
x86_l_e:
	/* 0xe: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_11:
	/* 0x11: mov    r8d,DWORD PTR [rdi+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_15:
	/* 0x15: mov    DWORD PTR [rdi+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1c:
	/* 0x1c: mov    r13d,DWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_20:
	/* 0x20: mov    r15d,DWORD PTR [rdi+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_24:
	/* 0x24: mov    QWORD PTR [rdi+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_2c:
	/* 0x2c: mov    rax,QWORD PTR [rip+0x7350] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_33:
	/* 0x33: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35:
	/* 0x35: mov    WORD PTR [rsp+0x1c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 120259084288ULL);
x86_l_3c:
	/* 0x3c: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_44:
	/* 0x44: mov    eax,DWORD PTR [rdi+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_47:
	/* 0x47: sub    eax,DWORD PTR [rdi+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RDI, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_4a:
	/* 0x4a: mov    ecx,0x86 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 134ULL);
x86_l_4f:
	/* 0x4f: cmp    eax,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 34ULL);
x86_l_52:
	/* 0x52: jae    5b <tail_handle_nat_fwd_ipv4+0x5b> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x52, 0x5b, x86_l_5b);
x86_l_54:
	/* 0x54: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_56:
	/* 0x56: jmp    a29 <tail_handle_nat_fwd_ipv4+0xa29> */
	X86_SIM_X86_JMP(0x56, 0xa29, x86_l_a29);
x86_l_5b:
	/* 0x5b: mov    DWORD PTR [rsp+0x24],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_60:
	/* 0x60: movabs r9,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_64, 2199023255552ULL);
x86_l_6a:
	/* 0x6a: movabs rbp,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 1099511627776ULL);
x86_l_74:
	/* 0x74: mov    rdx,QWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_7b:
	/* 0x7b: movzx  ecx,WORD PTR [rdx+0x12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18ULL);
x86_l_7f:
	/* 0x7f: movzx  eax,BYTE PTR [rdx+0x17] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 23ULL);
x86_l_83:
	/* 0x83: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_86:
	/* 0x86: shl    rsi,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_8a:
	/* 0x8a: or     rsi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_8d:
	/* 0x8d: movzx  ecx,WORD PTR [rdx+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 20ULL);
x86_l_91:
	/* 0x91: lea    rdi,[rsi+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_95:
	/* 0x95: test   ecx,0xff3f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_32, 65343ULL);
x86_l_9b:
	/* 0x9b: cmove  rdi,rsi */
	X86_SIM_L_EXEC_CMOV(X86_RDI, X86_RSI, X86_WIDTH_64, X86_CC_E);
x86_l_9f:
	/* 0x9f: lea    r14,[rdi+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_a3:
	/* 0xa3: test   ecx,0xff1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_32, 65311ULL);
x86_l_a9:
	/* 0xa9: cmove  r14,rdi */
	X86_SIM_L_EXEC_CMOV(X86_R14, X86_RDI, X86_WIDTH_64, X86_CC_E);
x86_l_ad:
	/* 0xad: mov    esi,DWORD PTR [rdx+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_b0:
	/* 0xb0: mov    BYTE PTR [rsp+0x1c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_b4:
	/* 0xb4: mov    ecx,DWORD PTR [rdx+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_b7:
	/* 0xb7: mov    DWORD PTR [rsp+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_bb:
	/* 0xbb: mov    edx,DWORD PTR [rdx+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_be:
	/* 0xbe: mov    DWORD PTR [rsp+0x14],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_c2:
	/* 0xc2: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_c5:
	/* 0xc5: je     d0 <tail_handle_nat_fwd_ipv4+0xd0> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc5, 0xd0, x86_l_d0);
x86_l_c7:
	/* 0xc7: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_ca:
	/* 0xca: jne    9f2 <tail_handle_nat_fwd_ipv4+0x9f2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xca, 0x9f2, x86_l_9f2);
x86_l_d0:
	/* 0xd0: mov    DWORD PTR [rsp+0x20],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d5:
	/* 0xd5: and    esi,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_d8:
	/* 0xd8: lea    esi,[rsi*4+0xe] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 14ULL);
x86_l_df:
	/* 0xdf: lea    r15,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_e4:
	/* 0xe4: mov    rax,QWORD PTR [rip+0x7350] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_ipv4_fragments)));
x86_l_eb:
	/* 0xeb: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ee:
	/* 0xee: mov    DWORD PTR [rsp+0xc],r8d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_f3:
	/* 0xf3: je     1af <tail_handle_nat_fwd_ipv4+0x1af> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf3, 0x1af, x86_l_1af);
x86_l_f9:
	/* 0xf9: mov    DWORD PTR [rsp+0x48],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_fd:
	/* 0xfd: mov    DWORD PTR [rsp+0x4c],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_101:
	/* 0x101: mov    WORD PTR [rsp+0x50],r14w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_107:
	/* 0x107: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_10a:
	/* 0x10a: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_10e:
	/* 0x10e: mov    BYTE PTR [rsp+0x52],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 82ULL);
x86_l_112:
	/* 0x112: mov    BYTE PTR [rsp+0x53],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 356482285568ULL);
x86_l_117:
	/* 0x117: mov    r13,r9 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R9, X86_WIDTH_64);
x86_l_11a:
	/* 0x11a: test   r14,r9 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R9, X86_WIDTH_64);
x86_l_11d:
	/* 0x11d: jne    895 <tail_handle_nat_fwd_ipv4+0x895> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x11d, 0x895, x86_l_895);
x86_l_123:
	/* 0x123: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_128:
	/* 0x128: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_12b:
	/* 0x12b: mov    r12,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RSI, X86_WIDTH_64);
x86_l_12e:
	/* 0x12e: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_131:
	/* 0x131: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_136:
	/* 0x136: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_138:
	/* 0x138: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_13a:
	/* 0x13a: js     1ea <tail_handle_nat_fwd_ipv4+0x1ea> */
	X86_SIM_X86_JCC(X86_CC_S, 0x13a, 0x1ea, x86_l_1ea);
x86_l_140:
	/* 0x140: test   r14,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_RBP, X86_WIDTH_64);
x86_l_143:
	/* 0x143: je     1d4 <tail_handle_nat_fwd_ipv4+0x1d4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x143, 0x1d4, x86_l_1d4);
x86_l_149:
	/* 0x149: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_14e:
	/* 0x14e: mov    rdi,QWORD PTR [rip+0x7350] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv4_frag_datagrams)));
x86_l_155:
	/* 0x155: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_15a:
	/* 0x15a: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_15d:
	/* 0x15d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15f:
	/* 0x15f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_161:
	/* 0x161: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_163:
	/* 0x163: je     1d4 <tail_handle_nat_fwd_ipv4+0x1d4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x163, 0x1d4, x86_l_1d4);
x86_l_165:
	/* 0x165: mov    r15d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_169:
	/* 0x169: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_172:
	/* 0x172: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_17b:
	/* 0x17b: movabs rax,0x6b0085020a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 459570217482ULL);
x86_l_185:
	/* 0x185: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_18a:
	/* 0x18a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_18f:
	/* 0x18f: mov    rdi,QWORD PTR [rip+0x7350] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_196:
	/* 0x196: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_19b:
	/* 0x19b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19d:
	/* 0x19d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a0:
	/* 0x1a0: je     8d9 <tail_handle_nat_fwd_ipv4+0x8d9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a0, 0x8d9, x86_l_8d9);
x86_l_1a6:
	/* 0x1a6: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1a9:
	/* 0x1a9: add    QWORD PTR [rax+0x8],r15 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1ad:
	/* 0x1ad: jmp    1d4 <tail_handle_nat_fwd_ipv4+0x1d4> */
	X86_SIM_X86_JMP(0x1ad, 0x1d4, x86_l_1d4);
x86_l_1af:
	/* 0x1af: test   r14,r9 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R9, X86_WIDTH_64);
x86_l_1b2:
	/* 0x1b2: jne    8bb <tail_handle_nat_fwd_ipv4+0x8bb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1b2, 0x8bb, x86_l_8bb);
x86_l_1b8:
	/* 0x1b8: mov    r13,r9 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R9, X86_WIDTH_64);
x86_l_1bb:
	/* 0x1bb: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1c0:
	/* 0x1c0: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1c3:
	/* 0x1c3: mov    r12,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RSI, X86_WIDTH_64);
x86_l_1c6:
	/* 0x1c6: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1c9:
	/* 0x1c9: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1ce:
	/* 0x1ce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d0:
	/* 0x1d0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1d2:
	/* 0x1d2: js     1ea <tail_handle_nat_fwd_ipv4+0x1ea> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1d2, 0x1ea, x86_l_1ea);
x86_l_1d4:
	/* 0x1d4: movzx  r15d,BYTE PTR [rsp+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_1da:
	/* 0x1da: cmp    BYTE PTR [rsp+0x1c],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 120259084294ULL);
x86_l_1df:
	/* 0x1df: jne    1f9 <tail_handle_nat_fwd_ipv4+0x1f9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1df, 0x1f9, x86_l_1f9);
x86_l_1e1:
	/* 0x1e1: mov    rdi,QWORD PTR [rip+0x7350] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct4_global)));
x86_l_1e8:
	/* 0x1e8: jmp    200 <tail_handle_nat_fwd_ipv4+0x200> */
	X86_SIM_X86_JMP(0x1e8, 0x200, x86_l_200);
x86_l_1ea:
	/* 0x1ea: mov    ecx,0x87 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 135ULL);
x86_l_1ef:
	/* 0x1ef: mov    r13d,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1f4:
	/* 0x1f4: jmp    54 <tail_handle_nat_fwd_ipv4+0x54> */
	X86_SIM_X86_JMP(0x1f4, 0x54, x86_l_54);
x86_l_1f9:
	/* 0x1f9: mov    rdi,QWORD PTR [rip+0x7350] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct_any4_global)));
x86_l_200:
	/* 0x200: mov    BYTE PTR [rsp+0x1d],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 124554051584ULL);
x86_l_205:
	/* 0x205: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_20a:
	/* 0x20a: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20f:
	/* 0x20f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_211:
	/* 0x211: mov    BYTE PTR [rsp+0x1d],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 29ULL);
x86_l_216:
	/* 0x216: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_219:
	/* 0x219: mov    r15d,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_21e:
	/* 0x21e: mov    r8d,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_223:
	/* 0x223: je     9f2 <tail_handle_nat_fwd_ipv4+0x9f2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x223, 0x9f2, x86_l_9f2);
x86_l_229:
	/* 0x229: movzx  ecx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_22d:
	/* 0x22d: test   cl,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_230:
	/* 0x230: jne    24f <tail_handle_nat_fwd_ipv4+0x24f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x230, 0x24f, x86_l_24f);
x86_l_232:
	/* 0x232: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_234:
	/* 0x234: jns    9f2 <tail_handle_nat_fwd_ipv4+0x9f2> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x234, 0x9f2, x86_l_9f2);
x86_l_23a:
	/* 0x23a: movzx  ecx,WORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 40ULL);
x86_l_23e:
	/* 0x23e: test   cx,cx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_16);
x86_l_241:
	/* 0x241: je     2b1 <tail_handle_nat_fwd_ipv4+0x2b1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x241, 0x2b1, x86_l_2b1);
x86_l_243:
	/* 0x243: mov    eax,DWORD PTR [rax+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_246:
	/* 0x246: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_24a:
	/* 0x24a: jmp    2fd <tail_handle_nat_fwd_ipv4+0x2fd> */
	X86_SIM_X86_JMP(0x24a, 0x2fd, x86_l_2fd);
x86_l_24f:
	/* 0x24f: movzx  eax,WORD PTR [rax+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_253:
	/* 0x253: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_256:
	/* 0x256: je     9f2 <tail_handle_nat_fwd_ipv4+0x9f2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x256, 0x9f2, x86_l_9f2);
x86_l_25c:
	/* 0x25c: mov    WORD PTR [rsp+0x28],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_261:
	/* 0x261: mov    rax,QWORD PTR [rip+0x7350] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_268:
	/* 0x268: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_26b:
	/* 0x26b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_270:
	/* 0x270: mov    rdi,QWORD PTR [rip+0x7350] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_reverse_nat)));
x86_l_277:
	/* 0x277: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_27c:
	/* 0x27c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27e:
	/* 0x27e: mov    r8d,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_283:
	/* 0x283: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_286:
	/* 0x286: je     9f2 <tail_handle_nat_fwd_ipv4+0x9f2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x286, 0x9f2, x86_l_9f2);
x86_l_28c:
	/* 0x28c: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28e:
	/* 0x28e: mov    DWORD PTR [rsp+0x38],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_292:
	/* 0x292: movzx  eax,WORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_296:
	/* 0x296: mov    WORD PTR [rsp+0x3c],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_29b:
	/* 0x29b: movzx  eax,BYTE PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_2a0:
	/* 0x2a0: mov    BYTE PTR [rsp+0xb],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 11ULL);
x86_l_2a4:
	/* 0x2a4: cmp    al,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 6ULL);
x86_l_2a6:
	/* 0x2a6: je     30f <tail_handle_nat_fwd_ipv4+0x30f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2a6, 0x30f, x86_l_30f);
x86_l_2a8:
	/* 0x2a8: mov    r15,QWORD PTR [rip+0x7350] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&cilium_ct_any4_global)));
x86_l_2af:
	/* 0x2af: jmp    316 <tail_handle_nat_fwd_ipv4+0x316> */
	X86_SIM_X86_JMP(0x2af, 0x316, x86_l_316);
x86_l_2b1:
	/* 0x2b1: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b6:
	/* 0x2b6: mov    rcx,QWORD PTR [rsp+0x15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 21ULL);
x86_l_2bb:
	/* 0x2bb: mov    QWORD PTR [rsp+0x2d],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 45ULL);
x86_l_2c0:
	/* 0x2c0: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2c5:
	/* 0x2c5: mov    BYTE PTR [rsp+0x35],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 227633266688ULL);
x86_l_2ca:
	/* 0x2ca: rorx   eax,DWORD PTR [rsp+0x18],0x10 */
	X86_SIM_RUN_OP(X86_OP_RORX_MEM, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 103079215120ULL);
x86_l_2d2:
	/* 0x2d2: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2d6:
	/* 0x2d6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2db:
	/* 0x2db: mov    rdi,QWORD PTR [rip+0x7350] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_2e2:
	/* 0x2e2: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2e7:
	/* 0x2e7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e9:
	/* 0x2e9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2ec:
	/* 0x2ec: je     47d <tail_handle_nat_fwd_ipv4+0x47d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2ec, 0x47d, x86_l_47d);
x86_l_2f2:
	/* 0x2f2: mov    ecx,DWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2f5:
	/* 0x2f5: mov    DWORD PTR [rsp+0x38],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2f9:
	/* 0x2f9: movzx  ecx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_2fd:
	/* 0x2fd: mov    WORD PTR [rsp+0x3c],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_302:
	/* 0x302: movzx  eax,BYTE PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_307:
	/* 0x307: mov    BYTE PTR [rsp+0xb],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 11ULL);
x86_l_30b:
	/* 0x30b: cmp    al,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 6ULL);
x86_l_30d:
	/* 0x30d: jne    2a8 <tail_handle_nat_fwd_ipv4+0x2a8> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x30d, 0x2a8, x86_l_2a8);
x86_l_30f:
	/* 0x30f: mov    r15,QWORD PTR [rip+0x7350] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&cilium_ct4_global)));
x86_l_316:
	/* 0x316: mov    rax,QWORD PTR [rip+0x7350] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_ipv4_fragments)));
x86_l_31d:
	/* 0x31d: mov    BYTE PTR [rsp+0x1d],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 124554051584ULL);
x86_l_322:
	/* 0x322: mov    DWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_32a:
	/* 0x32a: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32d:
	/* 0x32d: je     3a1 <tail_handle_nat_fwd_ipv4+0x3a1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x32d, 0x3a1, x86_l_3a1);
x86_l_32f:
	/* 0x32f: and    rbp,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_332:
	/* 0x332: je     3a1 <tail_handle_nat_fwd_ipv4+0x3a1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x332, 0x3a1, x86_l_3a1);
x86_l_334:
	/* 0x334: mov    ebp,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_337:
	/* 0x337: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_340:
	/* 0x340: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_349:
	/* 0x349: movabs rax,0x6c03a50109 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 463917613321ULL);
x86_l_353:
	/* 0x353: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_358:
	/* 0x358: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_35d:
	/* 0x35d: mov    rdi,QWORD PTR [rip+0x7350] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_364:
	/* 0x364: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_369:
	/* 0x369: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36b:
	/* 0x36b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_36e:
	/* 0x36e: je     379 <tail_handle_nat_fwd_ipv4+0x379> */
	X86_SIM_X86_JCC(X86_CC_E, 0x36e, 0x379, x86_l_379);
x86_l_370:
	/* 0x370: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_373:
	/* 0x373: add    QWORD PTR [rax+0x8],rbp */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_377:
	/* 0x377: jmp    3a1 <tail_handle_nat_fwd_ipv4+0x3a1> */
	X86_SIM_X86_JMP(0x377, 0x3a1, x86_l_3a1);
x86_l_379:
	/* 0x379: mov    QWORD PTR [rsp+0x28],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691841ULL);
x86_l_382:
	/* 0x382: mov    QWORD PTR [rsp+0x30],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_387:
	/* 0x387: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_38c:
	/* 0x38c: mov    rdi,QWORD PTR [rip+0x7350] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_393:
	/* 0x393: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_398:
	/* 0x398: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_39d:
	/* 0x39d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_39f:
	/* 0x39f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a1:
	/* 0x3a1: cmp    BYTE PTR [rsp+0xb],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 47244640262ULL);
x86_l_3a6:
	/* 0x3a6: mov    QWORD PTR [rsp+0x58],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3ab:
	/* 0x3ab: jne    3fd <tail_handle_nat_fwd_ipv4+0x3fd> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3ab, 0x3fd, x86_l_3fd);
x86_l_3ad:
	/* 0x3ad: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_3b0:
	/* 0x3b0: and    rax,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_3b3:
	/* 0x3b3: jne    3fd <tail_handle_nat_fwd_ipv4+0x3fd> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3b3, 0x3fd, x86_l_3fd);
x86_l_3b5:
	/* 0x3b5: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_3ba:
	/* 0x3ba: lea    esi,[r12+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3bf:
	/* 0x3bf: lea    rdx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3c4:
	/* 0x3c4: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_3c7:
	/* 0x3c7: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_3cc:
	/* 0x3cc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ce:
	/* 0x3ce: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3d0:
	/* 0x3d0: js     478 <tail_handle_nat_fwd_ipv4+0x478> */
	X86_SIM_X86_JCC(X86_CC_S, 0x3d0, 0x478, x86_l_478);
x86_l_3d6:
	/* 0x3d6: mov    ebp,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3da:
	/* 0x3da: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_3dc:
	/* 0x3dc: and    eax,0x1200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4608ULL);
x86_l_3e1:
	/* 0x3e1: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3e4:
	/* 0x3e4: cmp    eax,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 512ULL);
x86_l_3e9:
	/* 0x3e9: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_3ec:
	/* 0x3ec: test   ebp,0x500 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RBP, X86_WIDTH_32, 1280ULL);
x86_l_3f2:
	/* 0x3f2: jne    906 <tail_handle_nat_fwd_ipv4+0x906> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3f2, 0x906, x86_l_906);
x86_l_3f8:
	/* 0x3f8: mov    r12b,al */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_8);
x86_l_3fb:
	/* 0x3fb: jmp    404 <tail_handle_nat_fwd_ipv4+0x404> */
	X86_SIM_X86_JMP(0x3fb, 0x404, x86_l_404);
x86_l_3fd:
	/* 0x3fd: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_400:
	/* 0x400: mov    ebp,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_404:
	/* 0x404: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_409:
	/* 0x409: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_40e:
	/* 0x40e: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_411:
	/* 0x411: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_413:
	/* 0x413: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_416:
	/* 0x416: mov    r15d,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_41b:
	/* 0x41b: mov    r8d,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_420:
	/* 0x420: je     9e9 <tail_handle_nat_fwd_ipv4+0x9e9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x420, 0x9e9, x86_l_9e9);
x86_l_426:
	/* 0x426: movzx  ecx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_42a:
	/* 0x42a: test   cl,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_42d:
	/* 0x42d: jne    438 <tail_handle_nat_fwd_ipv4+0x438> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x42d, 0x438, x86_l_438);
x86_l_42f:
	/* 0x42f: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_431:
	/* 0x431: js     44a <tail_handle_nat_fwd_ipv4+0x44a> */
	X86_SIM_X86_JCC(X86_CC_S, 0x431, 0x44a, x86_l_44a);
x86_l_433:
	/* 0x433: jmp    9e9 <tail_handle_nat_fwd_ipv4+0x9e9> */
	X86_SIM_X86_JMP(0x433, 0x9e9, x86_l_9e9);
x86_l_438:
	/* 0x438: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_43a:
	/* 0x43a: and    edx,0x80 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 128ULL);
x86_l_440:
	/* 0x440: or     dx,WORD PTR [rax+0x26] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RAX, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 38ULL);
x86_l_444:
	/* 0x444: je     9e9 <tail_handle_nat_fwd_ipv4+0x9e9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x444, 0x9e9, x86_l_9e9);
x86_l_44a:
	/* 0x44a: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_44c:
	/* 0x44c: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_44e:
	/* 0x44e: test   dl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_8, 3ULL);
x86_l_451:
	/* 0x451: mov    r9,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_R13, X86_WIDTH_64);
x86_l_454:
	/* 0x454: je     579 <tail_handle_nat_fwd_ipv4+0x579> */
	X86_SIM_X86_JCC(X86_CC_E, 0x454, 0x579, x86_l_579);
x86_l_45a:
	/* 0x45a: mov    r13d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBP, X86_WIDTH_32);
x86_l_45d:
	/* 0x45d: mov    rsi,QWORD PTR [rip+0x7350] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_464:
	/* 0x464: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_467:
	/* 0x467: je     487 <tail_handle_nat_fwd_ipv4+0x487> */
	X86_SIM_X86_JCC(X86_CC_E, 0x467, 0x487, x86_l_487);
x86_l_469:
	/* 0x469: mov    rdx,QWORD PTR [rip+0x7350] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_470:
	/* 0x470: imul   ebp,DWORD PTR [rdx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_RBP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_473:
	/* 0x473: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_476:
	/* 0x476: jmp    48c <tail_handle_nat_fwd_ipv4+0x48c> */
	X86_SIM_X86_JMP(0x476, 0x48c, x86_l_48c);
x86_l_478:
	/* 0x478: mov    r15d,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_47d:
	/* 0x47d: mov    r8d,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_482:
	/* 0x482: jmp    9f2 <tail_handle_nat_fwd_ipv4+0x9f2> */
	X86_SIM_X86_JMP(0x482, 0x9f2, x86_l_9f2);
x86_l_487:
	/* 0x487: mov    ebp,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_48c:
	/* 0x48c: cmp    BYTE PTR [rsp+0xb],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 47244640262ULL);
x86_l_491:
	/* 0x491: jne    4c6 <tail_handle_nat_fwd_ipv4+0x4c6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x491, 0x4c6, x86_l_4c6);
x86_l_493:
	/* 0x493: mov    edx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_32);
x86_l_496:
	/* 0x496: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_498:
	/* 0x498: shr    edx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_49b:
	/* 0x49b: and    edx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_49e:
	/* 0x49e: or     edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_4a0:
	/* 0x4a0: mov    WORD PTR [rax+0x24],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_4a4:
	/* 0x4a4: test   dl,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_8, 16ULL);
x86_l_4a7:
	/* 0x4a7: mov    ecx,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 60ULL);
x86_l_4ac:
	/* 0x4ac: mov    ebp,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 21600ULL);
x86_l_4b1:
	/* 0x4b1: cmove  ebp,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RCX, X86_WIDTH_32, X86_CC_E);
x86_l_4b4:
	/* 0x4b4: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4b7:
	/* 0x4b7: je     4c6 <tail_handle_nat_fwd_ipv4+0x4c6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4b7, 0x4c6, x86_l_4c6);
x86_l_4b9:
	/* 0x4b9: mov    rcx,QWORD PTR [rip+0x7350] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_4c0:
	/* 0x4c0: imul   ebp,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_4c3:
	/* 0x4c3: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_4c6:
	/* 0x4c6: mov    DWORD PTR [rsp+0x54],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_4cb:
	/* 0x4cb: mov    r12,r9 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R9, X86_WIDTH_64);
x86_l_4ce:
	/* 0x4ce: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_4d3:
	/* 0x4d3: mov    r15d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_32);
x86_l_4d6:
	/* 0x4d6: shr    r15d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_4da:
	/* 0x4da: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4dd:
	/* 0x4dd: je     4f1 <tail_handle_nat_fwd_ipv4+0x4f1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4dd, 0x4f1, x86_l_4f1);
x86_l_4df:
	/* 0x4df: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_4e4:
	/* 0x4e4: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4e6:
	/* 0x4e6: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_4e8:
	/* 0x4e8: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_4eb:
	/* 0x4eb: shr    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_4ef:
	/* 0x4ef: jmp    514 <tail_handle_nat_fwd_ipv4+0x514> */
	X86_SIM_X86_JMP(0x4ef, 0x514, x86_l_514);
x86_l_4f1:
	/* 0x4f1: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_4f6:
	/* 0x4f6: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4f8:
	/* 0x4f8: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_4fa:
	/* 0x4fa: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_4fe:
	/* 0x4fe: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_508:
	/* 0x508: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_50b:
	/* 0x50b: mulx   rcx,rcx,rcx */
	X86_SIM_L_EXEC_MULX(X86_RCX, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_510:
	/* 0x510: shr    rcx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_514:
	/* 0x514: add    ebp,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_516:
	/* 0x516: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_51b:
	/* 0x51b: mov    DWORD PTR [rax+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_51e:
	/* 0x51e: movzx  edx,BYTE PTR [rax+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_522:
	/* 0x522: mov    esi,DWORD PTR [rax+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_525:
	/* 0x525: and    r15b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_529:
	/* 0x529: mov    rdi,QWORD PTR [rip+0x7350] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_530:
	/* 0x530: cmp    BYTE PTR [rdi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_533:
	/* 0x533: mov    r8d,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_538:
	/* 0x538: mov    r9,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_R12, X86_WIDTH_64);
x86_l_53b:
	/* 0x53b: je     54e <tail_handle_nat_fwd_ipv4+0x54e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x53b, 0x54e, x86_l_54e);
x86_l_53d:
	/* 0x53d: mov    rdi,QWORD PTR [rip+0x7350] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_544:
	/* 0x544: mov    edi,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_546:
	/* 0x546: lea    edi,[rdi+rdi*4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_549:
	/* 0x549: shr    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_54c:
	/* 0x54c: jmp    553 <tail_handle_nat_fwd_ipv4+0x553> */
	X86_SIM_X86_JMP(0x54c, 0x553, x86_l_553);
x86_l_54e:
	/* 0x54e: mov    edi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 5ULL);
x86_l_553:
	/* 0x553: mov    ebp,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R13, X86_WIDTH_32);
x86_l_556:
	/* 0x556: mov    r12d,DWORD PTR [rsp+0x54] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_55b:
	/* 0x55b: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_55d:
	/* 0x55d: or     r15b,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_560:
	/* 0x560: cmp    edi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RCX, X86_WIDTH_32);
x86_l_562:
	/* 0x562: jb     569 <tail_handle_nat_fwd_ipv4+0x569> */
	X86_SIM_X86_JCC(X86_CC_B, 0x562, 0x569, x86_l_569);
x86_l_564:
	/* 0x564: cmp    dl,r15b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_8);
x86_l_567:
	/* 0x567: je     579 <tail_handle_nat_fwd_ipv4+0x579> */
	X86_SIM_X86_JCC(X86_CC_E, 0x567, 0x579, x86_l_579);
x86_l_569:
	/* 0x569: mov    BYTE PTR [rax+0x2b],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_56d:
	/* 0x56d: mov    DWORD PTR [rax+0x34],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_570:
	/* 0x570: mov    rcx,QWORD PTR [rip+0x7350] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_577:
	/* 0x577: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_579:
	/* 0x579: mov    rcx,QWORD PTR [rip+0x7350] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_580:
	/* 0x580: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_583:
	/* 0x583: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_588:
	/* 0x588: je     597 <tail_handle_nat_fwd_ipv4+0x597> */
	X86_SIM_X86_JCC(X86_CC_E, 0x588, 0x597, x86_l_597);
x86_l_58a:
	/* 0x58a: inc QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 16ULL);
x86_l_58f:
	/* 0x58f: mov    ecx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_592:
	/* 0x592: add QWORD PTR [rax+0x18],rcx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_597:
	/* 0x597: cmp    r12d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 2ULL);
x86_l_59b:
	/* 0x59b: je     5ed <tail_handle_nat_fwd_ipv4+0x5ed> */
	X86_SIM_X86_JCC(X86_CC_E, 0x59b, 0x5ed, x86_l_5ed);
x86_l_59d:
	/* 0x59d: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_5a1:
	/* 0x5a1: jne    6dd <tail_handle_nat_fwd_ipv4+0x6dd> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x5a1, 0x6dd, x86_l_6dd);
x86_l_5a7:
	/* 0x5a7: movzx  ecx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_5ab:
	/* 0x5ab: test   cl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_5ae:
	/* 0x5ae: je     6dd <tail_handle_nat_fwd_ipv4+0x6dd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5ae, 0x6dd, x86_l_6dd);
x86_l_5b4:
	/* 0x5b4: mov    r12d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_5b7:
	/* 0x5b7: mov    WORD PTR [rax+0x2a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 180388626432ULL);
x86_l_5bd:
	/* 0x5bd: and    ecx,0xffec */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 65516ULL);
x86_l_5c3:
	/* 0x5c3: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_5c6:
	/* 0x5c6: mov    WORD PTR [rax+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_5ca:
	/* 0x5ca: mov    r15,QWORD PTR [rip+0x7350] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_5d1:
	/* 0x5d1: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5d5:
	/* 0x5d5: je     91b <tail_handle_nat_fwd_ipv4+0x91b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5d5, 0x91b, x86_l_91b);
x86_l_5db:
	/* 0x5db: mov    rax,QWORD PTR [rip+0x7350] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_5e2:
	/* 0x5e2: imul   ebp,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_5e5:
	/* 0x5e5: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_5e8:
	/* 0x5e8: jmp    920 <tail_handle_nat_fwd_ipv4+0x920> */
	X86_SIM_X86_JMP(0x5e8, 0x920, x86_l_920);
x86_l_5ed:
	/* 0x5ed: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_5ef:
	/* 0x5ef: shr    ecx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_5f2:
	/* 0x5f2: and    ecx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2ULL);
x86_l_5f5:
	/* 0x5f5: or     cx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RAX, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 36ULL);
x86_l_5f9:
	/* 0x5f9: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_5fb:
	/* 0x5fb: or     edx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_OR, 1ULL);
x86_l_5fe:
	/* 0x5fe: mov    WORD PTR [rax+0x24],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_602:
	/* 0x602: mov    rdx,QWORD PTR [rip+0x7350] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_609:
	/* 0x609: mov    edx,DWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_60b:
	/* 0x60b: test   cl,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_60e:
	/* 0x60e: je     6dd <tail_handle_nat_fwd_ipv4+0x6dd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x60e, 0x6dd, x86_l_6dd);
x86_l_614:
	/* 0x614: mov    r12d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_617:
	/* 0x617: mov    rdx,QWORD PTR [rip+0x7350] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_61e:
	/* 0x61e: cmp    BYTE PTR [rdx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_621:
	/* 0x621: je     636 <tail_handle_nat_fwd_ipv4+0x636> */
	X86_SIM_X86_JCC(X86_CC_E, 0x621, 0x636, x86_l_636);
x86_l_623:
	/* 0x623: mov    rcx,QWORD PTR [rip+0x7350] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_62a:
	/* 0x62a: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_62c:
	/* 0x62c: add    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_62e:
	/* 0x62e: lea    ebp,[rcx+rcx*4] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 0ULL);
x86_l_631:
	/* 0x631: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_634:
	/* 0x634: jmp    63b <tail_handle_nat_fwd_ipv4+0x63b> */
	X86_SIM_X86_JMP(0x634, 0x63b, x86_l_63b);
x86_l_636:
	/* 0x636: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_63b:
	/* 0x63b: mov    r13,r9 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R9, X86_WIDTH_64);
x86_l_63e:
	/* 0x63e: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_641:
	/* 0x641: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_645:
	/* 0x645: cmp    BYTE PTR [rdx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_648:
	/* 0x648: je     659 <tail_handle_nat_fwd_ipv4+0x659> */
	X86_SIM_X86_JCC(X86_CC_E, 0x648, 0x659, x86_l_659);
x86_l_64a:
	/* 0x64a: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_64f:
	/* 0x64f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_651:
	/* 0x651: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_653:
	/* 0x653: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_657:
	/* 0x657: jmp    67c <tail_handle_nat_fwd_ipv4+0x67c> */
	X86_SIM_X86_JMP(0x657, 0x67c, x86_l_67c);
x86_l_659:
	/* 0x659: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_65e:
	/* 0x65e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_660:
	/* 0x660: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_662:
	/* 0x662: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_666:
	/* 0x666: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_670:
	/* 0x670: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_673:
	/* 0x673: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_678:
	/* 0x678: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_67c:
	/* 0x67c: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_67e:
	/* 0x67e: mov    DWORD PTR [r15+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_682:
	/* 0x682: movzx  ecx,BYTE PTR [r15+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_687:
	/* 0x687: mov    edx,DWORD PTR [r15+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_68b:
	/* 0x68b: and    r12b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_68f:
	/* 0x68f: mov    rsi,QWORD PTR [rip+0x7350] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_696:
	/* 0x696: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_699:
	/* 0x699: mov    r8d,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_69e:
	/* 0x69e: mov    r9,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_R13, X86_WIDTH_64);
x86_l_6a1:
	/* 0x6a1: je     6b4 <tail_handle_nat_fwd_ipv4+0x6b4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6a1, 0x6b4, x86_l_6b4);
x86_l_6a3:
	/* 0x6a3: mov    rsi,QWORD PTR [rip+0x7350] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_6aa:
	/* 0x6aa: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6ac:
	/* 0x6ac: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_6af:
	/* 0x6af: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_6b2:
	/* 0x6b2: jmp    6b9 <tail_handle_nat_fwd_ipv4+0x6b9> */
	X86_SIM_X86_JMP(0x6b2, 0x6b9, x86_l_6b9);
x86_l_6b4:
	/* 0x6b4: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_6b9:
	/* 0x6b9: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_6bb:
	/* 0x6bb: or     r12b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_6be:
	/* 0x6be: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_6c0:
	/* 0x6c0: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_6c5:
	/* 0x6c5: jb     6cc <tail_handle_nat_fwd_ipv4+0x6cc> */
	X86_SIM_X86_JCC(X86_CC_B, 0x6c5, 0x6cc, x86_l_6cc);
x86_l_6c7:
	/* 0x6c7: cmp    cl,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R12, X86_WIDTH_8);
x86_l_6ca:
	/* 0x6ca: je     6dd <tail_handle_nat_fwd_ipv4+0x6dd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6ca, 0x6dd, x86_l_6dd);
x86_l_6cc:
	/* 0x6cc: mov    BYTE PTR [r15+0x2b],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_6d0:
	/* 0x6d0: mov    DWORD PTR [r15+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_6d4:
	/* 0x6d4: mov    rax,QWORD PTR [rip+0x7350] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_6db:
	/* 0x6db: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6dd:
	/* 0x6dd: test   BYTE PTR [rsp+0x1d],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 124554051586ULL);
x86_l_6e2:
	/* 0x6e2: mov    r15d,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6e7:
	/* 0x6e7: jne    9f2 <tail_handle_nat_fwd_ipv4+0x9f2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x6e7, 0x9f2, x86_l_9f2);
x86_l_6ed:
	/* 0x6ed: mov    r12,r9 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R9, X86_WIDTH_64);
x86_l_6f0:
	/* 0x6f0: mov    r15,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSI, X86_WIDTH_64);
x86_l_6f3:
	/* 0x6f3: mov    ebp,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_6f7:
	/* 0x6f7: mov    rax,QWORD PTR [rip+0x7350] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_6fe:
	/* 0x6fe: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_701:
	/* 0x701: mov    eax,DWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_705:
	/* 0x705: mov    DWORD PTR [rsp+0x14],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_709:
	/* 0x709: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_70e:
	/* 0x70e: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_713:
	/* 0x713: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_716:
	/* 0x716: mov    esi,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 26ULL);
x86_l_71b:
	/* 0x71b: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_720:
	/* 0x720: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_723:
	/* 0x723: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_725:
	/* 0x725: mov    ecx,0x8d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 141ULL);
x86_l_72a:
	/* 0x72a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_72c:
	/* 0x72c: js     911 <tail_handle_nat_fwd_ipv4+0x911> */
	X86_SIM_X86_JCC(X86_CC_S, 0x72c, 0x911, x86_l_911);
x86_l_732:
	/* 0x732: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_735:
	/* 0x735: mov    r13d,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_73a:
	/* 0x73a: je     54 <tail_handle_nat_fwd_ipv4+0x54> */
	X86_SIM_X86_JCC(X86_CC_E, 0x73a, 0x54, x86_l_54);
x86_l_740:
	/* 0x740: not    ebp */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_742:
	/* 0x742: add    ebp,DWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 56ULL);
x86_l_746:
	/* 0x746: adc    ebp,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_749:
	/* 0x749: mov    eax,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_74e:
	/* 0x74e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_751:
	/* 0x751: mov    esi,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 24ULL);
x86_l_756:
	/* 0x756: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_758:
	/* 0x758: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_75a:
	/* 0x75a: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_75d:
	/* 0x75d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_75f:
	/* 0x75f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_761:
	/* 0x761: js     78d <tail_handle_nat_fwd_ipv4+0x78d> */
	X86_SIM_X86_JCC(X86_CC_S, 0x761, 0x78d, x86_l_78d);
x86_l_763:
	/* 0x763: test   r14,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R12, X86_WIDTH_64);
x86_l_766:
	/* 0x766: jne    ad5 <tail_handle_nat_fwd_ipv4+0xad5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x766, 0xad5, x86_l_ad5);
x86_l_76c:
	/* 0x76c: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_76f:
	/* 0x76f: movzx  eax,BYTE PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_774:
	/* 0x774: cmp    eax,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 58ULL);
x86_l_777:
	/* 0x777: je     7a7 <tail_handle_nat_fwd_ipv4+0x7a7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x777, 0x7a7, x86_l_7a7);
x86_l_779:
	/* 0x779: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_77c:
	/* 0x77c: je     797 <tail_handle_nat_fwd_ipv4+0x797> */
	X86_SIM_X86_JCC(X86_CC_E, 0x77c, 0x797, x86_l_797);
x86_l_77e:
	/* 0x77e: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_781:
	/* 0x781: jne    7b1 <tail_handle_nat_fwd_ipv4+0x7b1> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x781, 0x7b1, x86_l_7b1);
x86_l_783:
	/* 0x783: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_785:
	/* 0x785: mov    r14d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 16ULL);
x86_l_78b:
	/* 0x78b: jmp    7b7 <tail_handle_nat_fwd_ipv4+0x7b7> */
	X86_SIM_X86_JMP(0x78b, 0x7b7, x86_l_7b7);
x86_l_78d:
	/* 0x78d: mov    ecx,0x99 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 153ULL);
x86_l_792:
	/* 0x792: jmp    54 <tail_handle_nat_fwd_ipv4+0x54> */
	X86_SIM_X86_JMP(0x792, 0x54, x86_l_54);
x86_l_797:
	/* 0x797: mov    r12d,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 32ULL);
x86_l_79d:
	/* 0x79d: mov    r14d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 6ULL);
x86_l_7a3:
	/* 0x7a3: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7a5:
	/* 0x7a5: jmp    7ba <tail_handle_nat_fwd_ipv4+0x7ba> */
	X86_SIM_X86_JMP(0x7a5, 0x7ba, x86_l_7ba);
x86_l_7a7:
	/* 0x7a7: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7a9:
	/* 0x7a9: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_7af:
	/* 0x7af: jmp    7b7 <tail_handle_nat_fwd_ipv4+0x7b7> */
	X86_SIM_X86_JMP(0x7af, 0x7b7, x86_l_7b7);
x86_l_7b1:
	/* 0x7b1: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7b4:
	/* 0x7b4: mov    dil,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_8, 1ULL);
x86_l_7b7:
	/* 0x7b7: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7ba:
	/* 0x7ba: movzx  edx,WORD PTR [rsp+0x3c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 60ULL);
x86_l_7bf:
	/* 0x7bf: test   dx,dx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_16);
x86_l_7c2:
	/* 0x7c2: je     855 <tail_handle_nat_fwd_ipv4+0x855> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7c2, 0x855, x86_l_855);
x86_l_7c8:
	/* 0x7c8: movzx  r8d,WORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 24ULL);
x86_l_7ce:
	/* 0x7ce: mov    ecx,0x8e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 142ULL);
x86_l_7d3:
	/* 0x7d3: cmp    eax,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_7d6:
	/* 0x7d6: jg     7e7 <tail_handle_nat_fwd_ipv4+0x7e7> */
	X86_SIM_X86_JCC(X86_CC_G, 0x7d6, 0x7e7, x86_l_7e7);
x86_l_7d8:
	/* 0x7d8: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7db:
	/* 0x7db: je     855 <tail_handle_nat_fwd_ipv4+0x855> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7db, 0x855, x86_l_855);
x86_l_7dd:
	/* 0x7dd: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_7e0:
	/* 0x7e0: je     7f5 <tail_handle_nat_fwd_ipv4+0x7f5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7e0, 0x7f5, x86_l_7f5);
x86_l_7e2:
	/* 0x7e2: jmp    54 <tail_handle_nat_fwd_ipv4+0x54> */
	X86_SIM_X86_JMP(0x7e2, 0x54, x86_l_54);
x86_l_7e7:
	/* 0x7e7: cmp    eax,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 58ULL);
x86_l_7ea:
	/* 0x7ea: je     855 <tail_handle_nat_fwd_ipv4+0x855> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7ea, 0x855, x86_l_855);
x86_l_7ec:
	/* 0x7ec: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_7ef:
	/* 0x7ef: jne    54 <tail_handle_nat_fwd_ipv4+0x54> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x7ef, 0x54, x86_l_54);
x86_l_7f5:
	/* 0x7f5: cmp    dx,r8w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R8, X86_WIDTH_16);
x86_l_7f9:
	/* 0x7f9: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_7fc:
	/* 0x7fc: je     855 <tail_handle_nat_fwd_ipv4+0x855> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7fc, 0x855, x86_l_855);
x86_l_7fe:
	/* 0x7fe: mov    DWORD PTR [rsp+0xc],r8d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_803:
	/* 0x803: mov    DWORD PTR [rsp+0x20],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_807:
	/* 0x807: mov    WORD PTR [rsp+0x28],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_80c:
	/* 0x80c: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_811:
	/* 0x811: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_816:
	/* 0x816: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_819:
	/* 0x819: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_81e:
	/* 0x81e: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_821:
	/* 0x821: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_823:
	/* 0x823: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_825:
	/* 0x825: js     88b <tail_handle_nat_fwd_ipv4+0x88b> */
	X86_SIM_X86_JCC(X86_CC_S, 0x825, 0x88b, x86_l_88b);
x86_l_827:
	/* 0x827: movzx  ecx,WORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 40ULL);
x86_l_82c:
	/* 0x82c: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_831:
	/* 0x831: lea    esi,[r14+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_835:
	/* 0x835: mov    r8d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R12, X86_WIDTH_32);
x86_l_838:
	/* 0x838: or     r8d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_83c:
	/* 0x83c: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_841:
	/* 0x841: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_844:
	/* 0x844: mov    edx,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_848:
	/* 0x848: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_84a:
	/* 0x84a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_84c:
	/* 0x84c: js     881 <tail_handle_nat_fwd_ipv4+0x881> */
	X86_SIM_X86_JCC(X86_CC_S, 0x84c, 0x881, x86_l_881);
x86_l_84e:
	/* 0x84e: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_851:
	/* 0x851: mov    edi,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_855:
	/* 0x855: test   dil,dil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_8);
x86_l_858:
	/* 0x858: jne    ad5 <tail_handle_nat_fwd_ipv4+0xad5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x858, 0xad5, x86_l_ad5);
x86_l_85e:
	/* 0x85e: add    r14d,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_861:
	/* 0x861: or     r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_OR, 16ULL);
x86_l_865:
	/* 0x865: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_86a:
	/* 0x86a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_86d:
	/* 0x86d: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_870:
	/* 0x870: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_872:
	/* 0x872: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_874:
	/* 0x874: mov    r8d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R12, X86_WIDTH_32);
x86_l_877:
	/* 0x877: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_879:
	/* 0x879: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_87b:
	/* 0x87b: jns    ad5 <tail_handle_nat_fwd_ipv4+0xad5> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x87b, 0xad5, x86_l_ad5);
x86_l_881:
	/* 0x881: mov    ecx,0x9a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 154ULL);
x86_l_886:
	/* 0x886: jmp    54 <tail_handle_nat_fwd_ipv4+0x54> */
	X86_SIM_X86_JMP(0x886, 0x54, x86_l_54);
x86_l_88b:
	/* 0x88b: mov    ecx,0x8d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 141ULL);
x86_l_890:
	/* 0x890: jmp    54 <tail_handle_nat_fwd_ipv4+0x54> */
	X86_SIM_X86_JMP(0x890, 0x54, x86_l_54);
x86_l_895:
	/* 0x895: mov    r12,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RSI, X86_WIDTH_64);
x86_l_898:
	/* 0x898: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_89d:
	/* 0x89d: mov    rdi,QWORD PTR [rip+0x7350] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv4_frag_datagrams)));
x86_l_8a4:
	/* 0x8a4: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_8a9:
	/* 0x8a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8ab:
	/* 0x8ab: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_8ae:
	/* 0x8ae: je     8ca <tail_handle_nat_fwd_ipv4+0x8ca> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8ae, 0x8ca, x86_l_8ca);
x86_l_8b0:
	/* 0x8b0: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8b2:
	/* 0x8b2: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_8b6:
	/* 0x8b6: jmp    1d4 <tail_handle_nat_fwd_ipv4+0x1d4> */
	X86_SIM_X86_JMP(0x8b6, 0x1d4, x86_l_1d4);
x86_l_8bb:
	/* 0x8bb: mov    ecx,0x9d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 157ULL);
x86_l_8c0:
	/* 0x8c0: mov    r13d,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_8c5:
	/* 0x8c5: jmp    54 <tail_handle_nat_fwd_ipv4+0x54> */
	X86_SIM_X86_JMP(0x8c5, 0x54, x86_l_54);
x86_l_8ca:
	/* 0x8ca: mov    ecx,0xaf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 175ULL);
x86_l_8cf:
	/* 0x8cf: mov    r13d,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_8d4:
	/* 0x8d4: jmp    54 <tail_handle_nat_fwd_ipv4+0x54> */
	X86_SIM_X86_JMP(0x8d4, 0x54, x86_l_54);
x86_l_8d9:
	/* 0x8d9: mov    QWORD PTR [rsp+0x28],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691841ULL);
x86_l_8e2:
	/* 0x8e2: mov    QWORD PTR [rsp+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_8e7:
	/* 0x8e7: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_8ec:
	/* 0x8ec: mov    rdi,QWORD PTR [rip+0x7350] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_8f3:
	/* 0x8f3: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_8f8:
	/* 0x8f8: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_8fd:
	/* 0x8fd: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8ff:
	/* 0x8ff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_901:
	/* 0x901: jmp    1d4 <tail_handle_nat_fwd_ipv4+0x1d4> */
	X86_SIM_X86_JMP(0x901, 0x1d4, x86_l_1d4);
x86_l_906:
	/* 0x906: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_90c:
	/* 0x90c: jmp    404 <tail_handle_nat_fwd_ipv4+0x404> */
	X86_SIM_X86_JMP(0x90c, 0x404, x86_l_404);
x86_l_911:
	/* 0x911: mov    r13d,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_916:
	/* 0x916: jmp    54 <tail_handle_nat_fwd_ipv4+0x54> */
	X86_SIM_X86_JMP(0x916, 0x54, x86_l_54);
x86_l_91b:
	/* 0x91b: mov    ebp,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_920:
	/* 0x920: cmp    BYTE PTR [rsp+0xb],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 47244640262ULL);
x86_l_925:
	/* 0x925: jne    95b <tail_handle_nat_fwd_ipv4+0x95b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x925, 0x95b, x86_l_95b);
x86_l_927:
	/* 0x927: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_92a:
	/* 0x92a: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_92c:
	/* 0x92c: shr    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_92f:
	/* 0x92f: and    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_932:
	/* 0x932: or     ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_OR);
x86_l_934:
	/* 0x934: mov    WORD PTR [r14+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_939:
	/* 0x939: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_93b:
	/* 0x93b: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_940:
	/* 0x940: mov    ebp,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 21600ULL);
x86_l_945:
	/* 0x945: cmove  ebp,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_948:
	/* 0x948: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_94c:
	/* 0x94c: je     95b <tail_handle_nat_fwd_ipv4+0x95b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x94c, 0x95b, x86_l_95b);
x86_l_94e:
	/* 0x94e: mov    rax,QWORD PTR [rip+0x7350] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_955:
	/* 0x955: imul   ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_958:
	/* 0x958: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_95b:
	/* 0x95b: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_95f:
	/* 0x95f: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_963:
	/* 0x963: je     974 <tail_handle_nat_fwd_ipv4+0x974> */
	X86_SIM_X86_JCC(X86_CC_E, 0x963, 0x974, x86_l_974);
x86_l_965:
	/* 0x965: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_96a:
	/* 0x96a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_96c:
	/* 0x96c: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_96e:
	/* 0x96e: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_972:
	/* 0x972: jmp    997 <tail_handle_nat_fwd_ipv4+0x997> */
	X86_SIM_X86_JMP(0x972, 0x997, x86_l_997);
x86_l_974:
	/* 0x974: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_979:
	/* 0x979: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_97b:
	/* 0x97b: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_97d:
	/* 0x97d: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_981:
	/* 0x981: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_98b:
	/* 0x98b: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_98e:
	/* 0x98e: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_993:
	/* 0x993: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_997:
	/* 0x997: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_999:
	/* 0x999: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_99c:
	/* 0x99c: mov    DWORD PTR [r14+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9a0:
	/* 0x9a0: movzx  ecx,BYTE PTR [r14+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_9a5:
	/* 0x9a5: mov    edx,DWORD PTR [r14+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_9a9:
	/* 0x9a9: and    r12b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_9ad:
	/* 0x9ad: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9b1:
	/* 0x9b1: je     9c4 <tail_handle_nat_fwd_ipv4+0x9c4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9b1, 0x9c4, x86_l_9c4);
x86_l_9b3:
	/* 0x9b3: mov    rsi,QWORD PTR [rip+0x7350] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_9ba:
	/* 0x9ba: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9bc:
	/* 0x9bc: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_9bf:
	/* 0x9bf: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_9c2:
	/* 0x9c2: jmp    9c9 <tail_handle_nat_fwd_ipv4+0x9c9> */
	X86_SIM_X86_JMP(0x9c2, 0x9c9, x86_l_9c9);
x86_l_9c4:
	/* 0x9c4: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_9c9:
	/* 0x9c9: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_9cb:
	/* 0x9cb: or     r12b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_9ce:
	/* 0x9ce: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_9d0:
	/* 0x9d0: mov    r15d,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9d5:
	/* 0x9d5: mov    r8d,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_9da:
	/* 0x9da: jb     9e1 <tail_handle_nat_fwd_ipv4+0x9e1> */
	X86_SIM_X86_JCC(X86_CC_B, 0x9da, 0x9e1, x86_l_9e1);
x86_l_9dc:
	/* 0x9dc: cmp    cl,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R12, X86_WIDTH_8);
x86_l_9df:
	/* 0x9df: je     9f2 <tail_handle_nat_fwd_ipv4+0x9f2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9df, 0x9f2, x86_l_9f2);
x86_l_9e1:
	/* 0x9e1: mov    BYTE PTR [r14+0x2b],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_9e5:
	/* 0x9e5: mov    DWORD PTR [r14+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_9e9:
	/* 0x9e9: mov    rax,QWORD PTR [rip+0x7350] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_9f0:
	/* 0x9f0: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9f2:
	/* 0x9f2: test   r8b,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R8, X86_WIDTH_8, 1ULL);
x86_l_9f6:
	/* 0x9f6: jne    ad5 <tail_handle_nat_fwd_ipv4+0xad5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x9f6, 0xad5, x86_l_ad5);
x86_l_9fc:
	/* 0x9fc: mov    DWORD PTR [rbx+0x2c],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_a00:
	/* 0xa00: mov    r13d,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_a05:
	/* 0xa05: mov    DWORD PTR [rbx+0x28],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a09:
	/* 0xa09: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_a0e:
	/* 0xa0e: mov    rsi,QWORD PTR [rip+0x7350] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_a15:
	/* 0xa15: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_a18:
	/* 0xa18: mov    edx,0x26 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 38ULL);
x86_l_a1d:
	/* 0xa1d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a1f:
	/* 0xa1f: mov    eax,0x2600 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9728ULL);
x86_l_a24:
	/* 0xa24: mov    ecx,0x8c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 140ULL);
x86_l_a29:
	/* 0xa29: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_a2b:
	/* 0xa2b: mov    DWORD PTR [rbx+0x28],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a2f:
	/* 0xa2f: mov    DWORD PTR [rbx+0x2c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561024ULL);
x86_l_a36:
	/* 0xa36: mov    DWORD PTR [rbx+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a39:
	/* 0xa39: movabs rax,0x24d710200000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 165913014686449664ULL);
x86_l_a43:
	/* 0xa43: mov    QWORD PTR [rbx+0x34],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_a47:
	/* 0xa47: mov    r14d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_a4b:
	/* 0xa4b: movabs rax,0x71024d0200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 485369905664ULL);
x86_l_a55:
	/* 0xa55: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a5a:
	/* 0xa5a: mov    BYTE PTR [rsp+0x10],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a5e:
	/* 0xa5e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a63:
	/* 0xa63: mov    rdi,QWORD PTR [rip+0x7350] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_a6a:
	/* 0xa6a: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a6f:
	/* 0xa6f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a71:
	/* 0xa71: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a74:
	/* 0xa74: je     a7f <tail_handle_nat_fwd_ipv4+0xa7f> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa74, 0xa7f, x86_l_a7f);
x86_l_a76:
	/* 0xa76: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_a79:
	/* 0xa79: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_a7d:
	/* 0xa7d: jmp    aa7 <tail_handle_nat_fwd_ipv4+0xaa7> */
	X86_SIM_X86_JMP(0xa7d, 0xaa7, x86_l_aa7);
x86_l_a7f:
	/* 0xa7f: mov    QWORD PTR [rsp+0x28],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691841ULL);
x86_l_a88:
	/* 0xa88: mov    QWORD PTR [rsp+0x30],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a8d:
	/* 0xa8d: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_a92:
	/* 0xa92: mov    rdi,QWORD PTR [rip+0x7350] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_a99:
	/* 0xa99: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a9e:
	/* 0xa9e: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_aa3:
	/* 0xaa3: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_aa5:
	/* 0xaa5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aa7:
	/* 0xaa7: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_aac:
	/* 0xaac: mov    rsi,QWORD PTR [rip+0x7350] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
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
	/* 0xabd: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_ac2:
	/* 0xac2: add    rsp,0x68 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 104ULL);
x86_l_ac6:
	/* 0xac6: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_ac7:
	/* 0xac7: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_ac9:
	/* 0xac9: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_acb:
	/* 0xacb: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_acd:
	/* 0xacd: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_acf:
	/* 0xacf: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_ad0:
	/* 0xad0: jmp    b46 <tail_handle_nat_fwd_ipv4+0xb46> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_ad5:
	/* 0xad5: mov    rax,QWORD PTR [rip+0x734c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_interface_ifindex)));
x86_l_adc:
	/* 0xadc: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ade:
	/* 0xade: mov    ebx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_ae1:
	/* 0xae1: movabs rax,0x71024d0200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 485369905664ULL);
x86_l_aeb:
	/* 0xaeb: add    rax,0x50000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 327680ULL);
x86_l_af1:
	/* 0xaf1: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_af6:
	/* 0xaf6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_afb:
	/* 0xafb: mov    rdi,QWORD PTR [rip+0x734c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_b02:
	/* 0xb02: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b07:
	/* 0xb07: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b09:
	/* 0xb09: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b0c:
	/* 0xb0c: je     b17 <tail_handle_nat_fwd_ipv4+0xb17> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb0c, 0xb17, x86_l_b17);
x86_l_b0e:
	/* 0xb0e: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_b11:
	/* 0xb11: add    QWORD PTR [rax+0x8],rbx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_b15:
	/* 0xb15: jmp    b3f <tail_handle_nat_fwd_ipv4+0xb3f> */
	X86_SIM_X86_JMP(0xb15, 0xb3f, x86_l_b3f);
x86_l_b17:
	/* 0xb17: mov    QWORD PTR [rsp+0x28],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691841ULL);
x86_l_b20:
	/* 0xb20: mov    QWORD PTR [rsp+0x30],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_b25:
	/* 0xb25: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_b2a:
	/* 0xb2a: mov    rdi,QWORD PTR [rip+0x734c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_b31:
	/* 0xb31: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b36:
	/* 0xb36: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b3b:
	/* 0xb3b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b3d:
	/* 0xb3d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b3f:
	/* 0xb3f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b41:
	/* 0xb41: jmp    ac2 <tail_handle_nat_fwd_ipv4+0xac2> */
	X86_SIM_X86_JMP(0xb41, 0xac2, x86_l_ac2);
x86_l_b46:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
