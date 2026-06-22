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
int cilium_bpf_wireguard_tail_handle_nat_fwd_ipv4_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0x2c: mov    rax,QWORD PTR [rip+0x5e80] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_33:
	/* 0x33: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_35:
	/* 0x35: mov    QWORD PTR [rsp+0x16],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 94489280512ULL);
x86_l_3e:
	/* 0x3e: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_47:
	/* 0x47: mov    eax,DWORD PTR [rdi+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_4a:
	/* 0x4a: sub    eax,DWORD PTR [rdi+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RDI, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_4d:
	/* 0x4d: mov    ecx,0x86 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 134ULL);
x86_l_52:
	/* 0x52: cmp    eax,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 20ULL);
x86_l_55:
	/* 0x55: jae    5e <tail_handle_nat_fwd_ipv4+0x5e> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x55, 0x5e, x86_l_5e);
x86_l_57:
	/* 0x57: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_59:
	/* 0x59: jmp    a19 <tail_handle_nat_fwd_ipv4+0xa19> */
	X86_SIM_X86_JMP(0x59, 0xa19, x86_l_a19);
x86_l_5e:
	/* 0x5e: mov    DWORD PTR [rsp+0x24],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_63:
	/* 0x63: movabs r9,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_64, 2199023255552ULL);
x86_l_6d:
	/* 0x6d: movabs r12,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 1099511627776ULL);
x86_l_77:
	/* 0x77: mov    rdx,QWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_7e:
	/* 0x7e: movzx  ecx,WORD PTR [rdx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_82:
	/* 0x82: movzx  eax,BYTE PTR [rdx+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_86:
	/* 0x86: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_89:
	/* 0x89: shl    rsi,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_8d:
	/* 0x8d: or     rsi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_90:
	/* 0x90: movzx  ecx,WORD PTR [rdx+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_94:
	/* 0x94: lea    rdi,[rsi+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_98:
	/* 0x98: test   ecx,0xff3f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_32, 65343ULL);
x86_l_9e:
	/* 0x9e: cmove  rdi,rsi */
	X86_SIM_L_EXEC_CMOV(X86_RDI, X86_RSI, X86_WIDTH_64, X86_CC_E);
x86_l_a2:
	/* 0xa2: lea    rbp,[rdi+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_a6:
	/* 0xa6: test   ecx,0xff1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_32, 65311ULL);
x86_l_ac:
	/* 0xac: cmove  rbp,rdi */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RDI, X86_WIDTH_64, X86_CC_E);
x86_l_b0:
	/* 0xb0: mov    r14d,DWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b3:
	/* 0xb3: mov    BYTE PTR [rsp+0x1c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_b7:
	/* 0xb7: mov    ecx,DWORD PTR [rdx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ba:
	/* 0xba: mov    DWORD PTR [rsp+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_be:
	/* 0xbe: mov    edx,DWORD PTR [rdx+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_c1:
	/* 0xc1: mov    DWORD PTR [rsp+0x14],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_c5:
	/* 0xc5: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_c8:
	/* 0xc8: je     d3 <tail_handle_nat_fwd_ipv4+0xd3> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc8, 0xd3, x86_l_d3);
x86_l_ca:
	/* 0xca: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_cd:
	/* 0xcd: jne    9e2 <tail_handle_nat_fwd_ipv4+0x9e2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xcd, 0x9e2, x86_l_9e2);
x86_l_d3:
	/* 0xd3: mov    DWORD PTR [rsp+0x20],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d8:
	/* 0xd8: shl    r14d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHL, 2ULL);
x86_l_dc:
	/* 0xdc: lea    r15,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_e1:
	/* 0xe1: mov    rax,QWORD PTR [rip+0x5e80] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_ipv4_fragments)));
x86_l_e8:
	/* 0xe8: and    r14d,0x3c */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 60ULL);
x86_l_ec:
	/* 0xec: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ef:
	/* 0xef: mov    DWORD PTR [rsp+0xc],r8d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_f4:
	/* 0xf4: je     1af <tail_handle_nat_fwd_ipv4+0x1af> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf4, 0x1af, x86_l_1af);
x86_l_fa:
	/* 0xfa: mov    DWORD PTR [rsp+0x50],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_fe:
	/* 0xfe: mov    DWORD PTR [rsp+0x54],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_102:
	/* 0x102: mov    WORD PTR [rsp+0x58],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_107:
	/* 0x107: mov    rax,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_64);
x86_l_10a:
	/* 0x10a: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_10e:
	/* 0x10e: mov    BYTE PTR [rsp+0x5a],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 90ULL);
x86_l_112:
	/* 0x112: mov    BYTE PTR [rsp+0x5b],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 390842023936ULL);
x86_l_117:
	/* 0x117: mov    r13,r9 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R9, X86_WIDTH_64);
x86_l_11a:
	/* 0x11a: test   rbp,r9 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_R9, X86_WIDTH_64);
x86_l_11d:
	/* 0x11d: jne    889 <tail_handle_nat_fwd_ipv4+0x889> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x11d, 0x889, x86_l_889);
x86_l_123:
	/* 0x123: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_128:
	/* 0x128: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_12b:
	/* 0x12b: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
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
	/* 0x140: test   rbp,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_143:
	/* 0x143: je     1d4 <tail_handle_nat_fwd_ipv4+0x1d4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x143, 0x1d4, x86_l_1d4);
x86_l_149:
	/* 0x149: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_14e:
	/* 0x14e: mov    rdi,QWORD PTR [rip+0x5e80] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv4_frag_datagrams)));
x86_l_155:
	/* 0x155: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
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
	/* 0x185: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_18a:
	/* 0x18a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_18f:
	/* 0x18f: mov    rdi,QWORD PTR [rip+0x5e80] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_196:
	/* 0x196: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_19b:
	/* 0x19b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19d:
	/* 0x19d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a0:
	/* 0x1a0: je     8ca <tail_handle_nat_fwd_ipv4+0x8ca> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a0, 0x8ca, x86_l_8ca);
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
	/* 0x1af: test   rbp,r9 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_R9, X86_WIDTH_64);
x86_l_1b2:
	/* 0x1b2: jne    8ac <tail_handle_nat_fwd_ipv4+0x8ac> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1b2, 0x8ac, x86_l_8ac);
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
	/* 0x1c3: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
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
	/* 0x1e1: mov    rdi,QWORD PTR [rip+0x5e80] */
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
	/* 0x1f4: jmp    57 <tail_handle_nat_fwd_ipv4+0x57> */
	X86_SIM_X86_JMP(0x1f4, 0x57, x86_l_57);
x86_l_1f9:
	/* 0x1f9: mov    rdi,QWORD PTR [rip+0x5e80] */
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
	/* 0x223: je     9e2 <tail_handle_nat_fwd_ipv4+0x9e2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x223, 0x9e2, x86_l_9e2);
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
	/* 0x234: jns    9e2 <tail_handle_nat_fwd_ipv4+0x9e2> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x234, 0x9e2, x86_l_9e2);
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
	/* 0x246: mov    DWORD PTR [rsp+0x3c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
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
	/* 0x256: je     9e2 <tail_handle_nat_fwd_ipv4+0x9e2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x256, 0x9e2, x86_l_9e2);
x86_l_25c:
	/* 0x25c: mov    WORD PTR [rsp+0x28],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_261:
	/* 0x261: mov    rax,QWORD PTR [rip+0x5e80] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_268:
	/* 0x268: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_26b:
	/* 0x26b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_270:
	/* 0x270: mov    rdi,QWORD PTR [rip+0x5e80] */
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
	/* 0x286: je     9e2 <tail_handle_nat_fwd_ipv4+0x9e2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x286, 0x9e2, x86_l_9e2);
x86_l_28c:
	/* 0x28c: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_28e:
	/* 0x28e: mov    DWORD PTR [rsp+0x3c],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_292:
	/* 0x292: movzx  eax,WORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_296:
	/* 0x296: mov    WORD PTR [rsp+0x40],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
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
	/* 0x2a8: mov    r15,QWORD PTR [rip+0x5e80] */
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
	/* 0x2db: mov    rdi,QWORD PTR [rip+0x5e80] */
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
	/* 0x2ec: je     484 <tail_handle_nat_fwd_ipv4+0x484> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2ec, 0x484, x86_l_484);
x86_l_2f2:
	/* 0x2f2: mov    ecx,DWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2f5:
	/* 0x2f5: mov    DWORD PTR [rsp+0x3c],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_2f9:
	/* 0x2f9: movzx  ecx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_2fd:
	/* 0x2fd: mov    WORD PTR [rsp+0x40],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
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
	/* 0x30f: mov    r15,QWORD PTR [rip+0x5e80] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&cilium_ct4_global)));
x86_l_316:
	/* 0x316: mov    rax,QWORD PTR [rip+0x5e80] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_ipv4_fragments)));
x86_l_31d:
	/* 0x31d: mov    BYTE PTR [rsp+0x1d],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 124554051584ULL);
x86_l_322:
	/* 0x322: mov    DWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_32a:
	/* 0x32a: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_32d:
	/* 0x32d: je     3a2 <tail_handle_nat_fwd_ipv4+0x3a2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x32d, 0x3a2, x86_l_3a2);
x86_l_32f:
	/* 0x32f: and    r12,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RBP, X86_WIDTH_64, X86_ALU_AND);
x86_l_332:
	/* 0x332: je     3a2 <tail_handle_nat_fwd_ipv4+0x3a2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x332, 0x3a2, x86_l_3a2);
x86_l_334:
	/* 0x334: mov    r12d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_338:
	/* 0x338: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_341:
	/* 0x341: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_34a:
	/* 0x34a: movabs rax,0x6c03a50109 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 463917613321ULL);
x86_l_354:
	/* 0x354: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_359:
	/* 0x359: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_35e:
	/* 0x35e: mov    rdi,QWORD PTR [rip+0x5e80] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_365:
	/* 0x365: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_36a:
	/* 0x36a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36c:
	/* 0x36c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_36f:
	/* 0x36f: je     37a <tail_handle_nat_fwd_ipv4+0x37a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x36f, 0x37a, x86_l_37a);
x86_l_371:
	/* 0x371: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_374:
	/* 0x374: add    QWORD PTR [rax+0x8],r12 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_378:
	/* 0x378: jmp    3a2 <tail_handle_nat_fwd_ipv4+0x3a2> */
	X86_SIM_X86_JMP(0x378, 0x3a2, x86_l_3a2);
x86_l_37a:
	/* 0x37a: mov    QWORD PTR [rsp+0x28],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691841ULL);
x86_l_383:
	/* 0x383: mov    QWORD PTR [rsp+0x30],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_388:
	/* 0x388: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_38d:
	/* 0x38d: mov    rdi,QWORD PTR [rip+0x5e80] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_394:
	/* 0x394: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_399:
	/* 0x399: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_39e:
	/* 0x39e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3a0:
	/* 0x3a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a2:
	/* 0x3a2: cmp    BYTE PTR [rsp+0xb],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 47244640262ULL);
x86_l_3a7:
	/* 0x3a7: jne    3fd <tail_handle_nat_fwd_ipv4+0x3fd> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3a7, 0x3fd, x86_l_3fd);
x86_l_3a9:
	/* 0x3a9: mov    rax,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_64);
x86_l_3ac:
	/* 0x3ac: and    rax,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_3af:
	/* 0x3af: jne    3fd <tail_handle_nat_fwd_ipv4+0x3fd> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3af, 0x3fd, x86_l_3fd);
x86_l_3b1:
	/* 0x3b1: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_3b6:
	/* 0x3b6: lea    esi,[r14+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3ba:
	/* 0x3ba: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3bf:
	/* 0x3bf: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_3c2:
	/* 0x3c2: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_3c7:
	/* 0x3c7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c9:
	/* 0x3c9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3cb:
	/* 0x3cb: js     47f <tail_handle_nat_fwd_ipv4+0x47f> */
	X86_SIM_X86_JCC(X86_CC_S, 0x3cb, 0x47f, x86_l_47f);
x86_l_3d1:
	/* 0x3d1: mov    r12d,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3d6:
	/* 0x3d6: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_3d9:
	/* 0x3d9: and    eax,0x1200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4608ULL);
x86_l_3de:
	/* 0x3de: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3e0:
	/* 0x3e0: cmp    eax,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 512ULL);
x86_l_3e5:
	/* 0x3e5: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_3e8:
	/* 0x3e8: test   r12d,0x500 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R12, X86_WIDTH_32, 1280ULL);
x86_l_3ef:
	/* 0x3ef: jne    8f7 <tail_handle_nat_fwd_ipv4+0x8f7> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3ef, 0x8f7, x86_l_8f7);
x86_l_3f5:
	/* 0x3f5: mov    cl,al */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_8);
x86_l_3f7:
	/* 0x3f7: mov    DWORD PTR [rsp+0x5c],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_3fb:
	/* 0x3fb: jmp    40a <tail_handle_nat_fwd_ipv4+0x40a> */
	X86_SIM_X86_JMP(0x3fb, 0x40a, x86_l_40a);
x86_l_3fd:
	/* 0x3fd: mov    DWORD PTR [rsp+0x5c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 395136991232ULL);
x86_l_405:
	/* 0x405: mov    r12d,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_40a:
	/* 0x40a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_40f:
	/* 0x40f: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_414:
	/* 0x414: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_417:
	/* 0x417: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_419:
	/* 0x419: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_41c:
	/* 0x41c: mov    r15d,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_421:
	/* 0x421: mov    r8d,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_426:
	/* 0x426: je     9d9 <tail_handle_nat_fwd_ipv4+0x9d9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x426, 0x9d9, x86_l_9d9);
x86_l_42c:
	/* 0x42c: movzx  ecx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_430:
	/* 0x430: test   cl,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_433:
	/* 0x433: jne    43e <tail_handle_nat_fwd_ipv4+0x43e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x433, 0x43e, x86_l_43e);
x86_l_435:
	/* 0x435: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_437:
	/* 0x437: js     450 <tail_handle_nat_fwd_ipv4+0x450> */
	X86_SIM_X86_JCC(X86_CC_S, 0x437, 0x450, x86_l_450);
x86_l_439:
	/* 0x439: jmp    9d9 <tail_handle_nat_fwd_ipv4+0x9d9> */
	X86_SIM_X86_JMP(0x439, 0x9d9, x86_l_9d9);
x86_l_43e:
	/* 0x43e: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_440:
	/* 0x440: and    edx,0x80 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 128ULL);
x86_l_446:
	/* 0x446: or     dx,WORD PTR [rax+0x26] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RAX, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 38ULL);
x86_l_44a:
	/* 0x44a: je     9d9 <tail_handle_nat_fwd_ipv4+0x9d9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x44a, 0x9d9, x86_l_9d9);
x86_l_450:
	/* 0x450: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_452:
	/* 0x452: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_454:
	/* 0x454: test   dl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_8, 3ULL);
x86_l_457:
	/* 0x457: je     57c <tail_handle_nat_fwd_ipv4+0x57c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x457, 0x57c, x86_l_57c);
x86_l_45d:
	/* 0x45d: mov    DWORD PTR [rsp+0x44],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_462:
	/* 0x462: mov    rsi,QWORD PTR [rip+0x5e80] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_469:
	/* 0x469: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_46c:
	/* 0x46c: je     48e <tail_handle_nat_fwd_ipv4+0x48e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x46c, 0x48e, x86_l_48e);
x86_l_46e:
	/* 0x46e: mov    rdx,QWORD PTR [rip+0x5e80] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_475:
	/* 0x475: imul   r12d,DWORD PTR [rdx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R12, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_479:
	/* 0x479: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_47d:
	/* 0x47d: jmp    494 <tail_handle_nat_fwd_ipv4+0x494> */
	X86_SIM_X86_JMP(0x47d, 0x494, x86_l_494);
x86_l_47f:
	/* 0x47f: mov    r15d,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_484:
	/* 0x484: mov    r8d,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_489:
	/* 0x489: jmp    9e2 <tail_handle_nat_fwd_ipv4+0x9e2> */
	X86_SIM_X86_JMP(0x489, 0x9e2, x86_l_9e2);
x86_l_48e:
	/* 0x48e: mov    r12d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 60ULL);
x86_l_494:
	/* 0x494: cmp    BYTE PTR [rsp+0xb],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 47244640262ULL);
x86_l_499:
	/* 0x499: jne    4d3 <tail_handle_nat_fwd_ipv4+0x4d3> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x499, 0x4d3, x86_l_4d3);
x86_l_49b:
	/* 0x49b: mov    edx,DWORD PTR [rsp+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_49f:
	/* 0x49f: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_4a1:
	/* 0x4a1: shr    edx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_4a4:
	/* 0x4a4: and    edx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_4a7:
	/* 0x4a7: or     edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_4a9:
	/* 0x4a9: mov    WORD PTR [rax+0x24],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_4ad:
	/* 0x4ad: test   dl,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_8, 16ULL);
x86_l_4b0:
	/* 0x4b0: mov    ecx,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 60ULL);
x86_l_4b5:
	/* 0x4b5: mov    r12d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 21600ULL);
x86_l_4bb:
	/* 0x4bb: cmove  r12d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RCX, X86_WIDTH_32, X86_CC_E);
x86_l_4bf:
	/* 0x4bf: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4c2:
	/* 0x4c2: je     4d3 <tail_handle_nat_fwd_ipv4+0x4d3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4c2, 0x4d3, x86_l_4d3);
x86_l_4c4:
	/* 0x4c4: mov    rcx,QWORD PTR [rip+0x5e80] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_4cb:
	/* 0x4cb: imul   r12d,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_4cf:
	/* 0x4cf: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_4d3:
	/* 0x4d3: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_4d8:
	/* 0x4d8: mov    r15d,DWORD PTR [rsp+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_4dd:
	/* 0x4dd: shr    r15d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_4e1:
	/* 0x4e1: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4e4:
	/* 0x4e4: je     4f8 <tail_handle_nat_fwd_ipv4+0x4f8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4e4, 0x4f8, x86_l_4f8);
x86_l_4e6:
	/* 0x4e6: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_4eb:
	/* 0x4eb: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4ed:
	/* 0x4ed: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_4ef:
	/* 0x4ef: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_4f2:
	/* 0x4f2: shr    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_4f6:
	/* 0x4f6: jmp    51b <tail_handle_nat_fwd_ipv4+0x51b> */
	X86_SIM_X86_JMP(0x4f6, 0x51b, x86_l_51b);
x86_l_4f8:
	/* 0x4f8: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_4fd:
	/* 0x4fd: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4ff:
	/* 0x4ff: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_501:
	/* 0x501: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_505:
	/* 0x505: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_50f:
	/* 0x50f: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_512:
	/* 0x512: mulx   rcx,rcx,rcx */
	X86_SIM_L_EXEC_MULX(X86_RCX, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_517:
	/* 0x517: shr    rcx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_51b:
	/* 0x51b: add    r12d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_51e:
	/* 0x51e: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_523:
	/* 0x523: mov    DWORD PTR [rax+0x20],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_527:
	/* 0x527: movzx  edx,BYTE PTR [rax+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_52b:
	/* 0x52b: mov    esi,DWORD PTR [rax+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_52e:
	/* 0x52e: and    r15b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_532:
	/* 0x532: mov    rdi,QWORD PTR [rip+0x5e80] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_539:
	/* 0x539: cmp    BYTE PTR [rdi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_53c:
	/* 0x53c: mov    r8d,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_541:
	/* 0x541: je     554 <tail_handle_nat_fwd_ipv4+0x554> */
	X86_SIM_X86_JCC(X86_CC_E, 0x541, 0x554, x86_l_554);
x86_l_543:
	/* 0x543: mov    rdi,QWORD PTR [rip+0x5e80] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_54a:
	/* 0x54a: mov    edi,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_54c:
	/* 0x54c: lea    edi,[rdi+rdi*4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_54f:
	/* 0x54f: shr    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_552:
	/* 0x552: jmp    559 <tail_handle_nat_fwd_ipv4+0x559> */
	X86_SIM_X86_JMP(0x552, 0x559, x86_l_559);
x86_l_554:
	/* 0x554: mov    edi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 5ULL);
x86_l_559:
	/* 0x559: mov    r12d,DWORD PTR [rsp+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_55e:
	/* 0x55e: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_560:
	/* 0x560: or     r15b,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_563:
	/* 0x563: cmp    edi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RCX, X86_WIDTH_32);
x86_l_565:
	/* 0x565: jb     56c <tail_handle_nat_fwd_ipv4+0x56c> */
	X86_SIM_X86_JCC(X86_CC_B, 0x565, 0x56c, x86_l_56c);
x86_l_567:
	/* 0x567: cmp    dl,r15b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_8);
x86_l_56a:
	/* 0x56a: je     57c <tail_handle_nat_fwd_ipv4+0x57c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x56a, 0x57c, x86_l_57c);
x86_l_56c:
	/* 0x56c: mov    BYTE PTR [rax+0x2b],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_570:
	/* 0x570: mov    DWORD PTR [rax+0x34],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_573:
	/* 0x573: mov    rcx,QWORD PTR [rip+0x5e80] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_57a:
	/* 0x57a: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_57c:
	/* 0x57c: mov    rcx,QWORD PTR [rip+0x5e80] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_583:
	/* 0x583: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_586:
	/* 0x586: je     595 <tail_handle_nat_fwd_ipv4+0x595> */
	X86_SIM_X86_JCC(X86_CC_E, 0x586, 0x595, x86_l_595);
x86_l_588:
	/* 0x588: inc QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 16ULL);
x86_l_58d:
	/* 0x58d: mov    ecx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_590:
	/* 0x590: add QWORD PTR [rax+0x18],rcx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_595:
	/* 0x595: mov    ecx,DWORD PTR [rsp+0x5c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 92ULL);
x86_l_599:
	/* 0x599: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_59c:
	/* 0x59c: je     5ea <tail_handle_nat_fwd_ipv4+0x5ea> */
	X86_SIM_X86_JCC(X86_CC_E, 0x59c, 0x5ea, x86_l_5ea);
x86_l_59e:
	/* 0x59e: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_5a1:
	/* 0x5a1: jne    6e1 <tail_handle_nat_fwd_ipv4+0x6e1> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x5a1, 0x6e1, x86_l_6e1);
x86_l_5a7:
	/* 0x5a7: movzx  ecx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_5ab:
	/* 0x5ab: test   cl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_5ae:
	/* 0x5ae: je     6e1 <tail_handle_nat_fwd_ipv4+0x6e1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5ae, 0x6e1, x86_l_6e1);
x86_l_5b4:
	/* 0x5b4: mov    WORD PTR [rax+0x2a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 180388626432ULL);
x86_l_5ba:
	/* 0x5ba: and    ecx,0xffec */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 65516ULL);
x86_l_5c0:
	/* 0x5c0: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_5c3:
	/* 0x5c3: mov    WORD PTR [rax+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_5c7:
	/* 0x5c7: mov    r15,QWORD PTR [rip+0x5e80] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_5ce:
	/* 0x5ce: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5d2:
	/* 0x5d2: je     90b <tail_handle_nat_fwd_ipv4+0x90b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5d2, 0x90b, x86_l_90b);
x86_l_5d8:
	/* 0x5d8: mov    rax,QWORD PTR [rip+0x5e80] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_5df:
	/* 0x5df: imul   ebp,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_5e2:
	/* 0x5e2: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_5e5:
	/* 0x5e5: jmp    910 <tail_handle_nat_fwd_ipv4+0x910> */
	X86_SIM_X86_JMP(0x5e5, 0x910, x86_l_910);
x86_l_5ea:
	/* 0x5ea: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_5ed:
	/* 0x5ed: shr    ecx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_5f0:
	/* 0x5f0: and    ecx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2ULL);
x86_l_5f3:
	/* 0x5f3: or     cx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RAX, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 36ULL);
x86_l_5f7:
	/* 0x5f7: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_5f9:
	/* 0x5f9: or     edx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_OR, 1ULL);
x86_l_5fc:
	/* 0x5fc: mov    WORD PTR [rax+0x24],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_600:
	/* 0x600: mov    rdx,QWORD PTR [rip+0x5e80] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_607:
	/* 0x607: mov    edx,DWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_609:
	/* 0x609: test   cl,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_60c:
	/* 0x60c: je     6e1 <tail_handle_nat_fwd_ipv4+0x6e1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x60c, 0x6e1, x86_l_6e1);
x86_l_612:
	/* 0x612: mov    r13d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R12, X86_WIDTH_32);
x86_l_615:
	/* 0x615: mov    rdx,QWORD PTR [rip+0x5e80] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_61c:
	/* 0x61c: cmp    BYTE PTR [rdx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_61f:
	/* 0x61f: je     636 <tail_handle_nat_fwd_ipv4+0x636> */
	X86_SIM_X86_JCC(X86_CC_E, 0x61f, 0x636, x86_l_636);
x86_l_621:
	/* 0x621: mov    rcx,QWORD PTR [rip+0x5e80] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_628:
	/* 0x628: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_62a:
	/* 0x62a: add    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_62c:
	/* 0x62c: lea    r12d,[rcx+rcx*4] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 0ULL);
x86_l_630:
	/* 0x630: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_634:
	/* 0x634: jmp    63c <tail_handle_nat_fwd_ipv4+0x63c> */
	X86_SIM_X86_JMP(0x634, 0x63c, x86_l_63c);
x86_l_636:
	/* 0x636: mov    r12d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 10ULL);
x86_l_63c:
	/* 0x63c: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_63f:
	/* 0x63f: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_643:
	/* 0x643: cmp    BYTE PTR [rdx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_646:
	/* 0x646: je     657 <tail_handle_nat_fwd_ipv4+0x657> */
	X86_SIM_X86_JCC(X86_CC_E, 0x646, 0x657, x86_l_657);
x86_l_648:
	/* 0x648: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_64d:
	/* 0x64d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_64f:
	/* 0x64f: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_651:
	/* 0x651: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_655:
	/* 0x655: jmp    67a <tail_handle_nat_fwd_ipv4+0x67a> */
	X86_SIM_X86_JMP(0x655, 0x67a, x86_l_67a);
x86_l_657:
	/* 0x657: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_65c:
	/* 0x65c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_65e:
	/* 0x65e: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_660:
	/* 0x660: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_664:
	/* 0x664: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_66e:
	/* 0x66e: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_671:
	/* 0x671: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_676:
	/* 0x676: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_67a:
	/* 0x67a: add    r12d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_67d:
	/* 0x67d: mov    DWORD PTR [r15+0x20],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_681:
	/* 0x681: movzx  ecx,BYTE PTR [r15+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_686:
	/* 0x686: mov    edx,DWORD PTR [r15+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_68a:
	/* 0x68a: mov    edi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_32);
x86_l_68d:
	/* 0x68d: and    dil,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_691:
	/* 0x691: mov    rsi,QWORD PTR [rip+0x5e80] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_698:
	/* 0x698: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_69b:
	/* 0x69b: mov    r8d,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_6a0:
	/* 0x6a0: movabs r13,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 2199023255552ULL);
x86_l_6aa:
	/* 0x6aa: je     6bd <tail_handle_nat_fwd_ipv4+0x6bd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6aa, 0x6bd, x86_l_6bd);
x86_l_6ac:
	/* 0x6ac: mov    rsi,QWORD PTR [rip+0x5e80] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_6b3:
	/* 0x6b3: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6b5:
	/* 0x6b5: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_6b8:
	/* 0x6b8: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_6bb:
	/* 0x6bb: jmp    6c2 <tail_handle_nat_fwd_ipv4+0x6c2> */
	X86_SIM_X86_JMP(0x6bb, 0x6c2, x86_l_6c2);
x86_l_6bd:
	/* 0x6bd: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_6c2:
	/* 0x6c2: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_6c4:
	/* 0x6c4: or     dil,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_6c7:
	/* 0x6c7: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_6c9:
	/* 0x6c9: jb     6d0 <tail_handle_nat_fwd_ipv4+0x6d0> */
	X86_SIM_X86_JCC(X86_CC_B, 0x6c9, 0x6d0, x86_l_6d0);
x86_l_6cb:
	/* 0x6cb: cmp    cl,dil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDI, X86_WIDTH_8);
x86_l_6ce:
	/* 0x6ce: je     6e1 <tail_handle_nat_fwd_ipv4+0x6e1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6ce, 0x6e1, x86_l_6e1);
x86_l_6d0:
	/* 0x6d0: mov    BYTE PTR [r15+0x2b],dil */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RDI, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_6d4:
	/* 0x6d4: mov    DWORD PTR [r15+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_6d8:
	/* 0x6d8: mov    rax,QWORD PTR [rip+0x5e80] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_6df:
	/* 0x6df: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6e1:
	/* 0x6e1: test   BYTE PTR [rsp+0x1d],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 124554051586ULL);
x86_l_6e6:
	/* 0x6e6: mov    r15d,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6eb:
	/* 0x6eb: jne    9e2 <tail_handle_nat_fwd_ipv4+0x9e2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x6eb, 0x9e2, x86_l_9e2);
x86_l_6f1:
	/* 0x6f1: mov    r12,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R13, X86_WIDTH_64);
x86_l_6f4:
	/* 0x6f4: mov    r15d,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_6f9:
	/* 0x6f9: mov    rax,QWORD PTR [rip+0x5e80] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_700:
	/* 0x700: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_703:
	/* 0x703: mov    eax,DWORD PTR [rsp+0x3c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_707:
	/* 0x707: mov    DWORD PTR [rsp+0x14],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_70b:
	/* 0x70b: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_710:
	/* 0x710: lea    rdx,[rsp+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_715:
	/* 0x715: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_718:
	/* 0x718: mov    esi,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 12ULL);
x86_l_71d:
	/* 0x71d: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_722:
	/* 0x722: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_725:
	/* 0x725: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_727:
	/* 0x727: mov    ecx,0x8d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 141ULL);
x86_l_72c:
	/* 0x72c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_72e:
	/* 0x72e: js     901 <tail_handle_nat_fwd_ipv4+0x901> */
	X86_SIM_X86_JCC(X86_CC_S, 0x72e, 0x901, x86_l_901);
x86_l_734:
	/* 0x734: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_737:
	/* 0x737: mov    r13d,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_73c:
	/* 0x73c: je     57 <tail_handle_nat_fwd_ipv4+0x57> */
	X86_SIM_X86_JCC(X86_CC_E, 0x73c, 0x57, x86_l_57);
x86_l_742:
	/* 0x742: not    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_745:
	/* 0x745: add    r15d,DWORD PTR [rsp+0x3c] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 60ULL);
x86_l_74a:
	/* 0x74a: adc    r15d,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_74e:
	/* 0x74e: mov    eax,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_753:
	/* 0x753: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_756:
	/* 0x756: mov    esi,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 10ULL);
x86_l_75b:
	/* 0x75b: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_75d:
	/* 0x75d: mov    ecx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_32);
x86_l_760:
	/* 0x760: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_763:
	/* 0x763: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_765:
	/* 0x765: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_767:
	/* 0x767: js     78f <tail_handle_nat_fwd_ipv4+0x78f> */
	X86_SIM_X86_JCC(X86_CC_S, 0x767, 0x78f, x86_l_78f);
x86_l_769:
	/* 0x769: test   rbp,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_R12, X86_WIDTH_64);
x86_l_76c:
	/* 0x76c: jne    ac5 <tail_handle_nat_fwd_ipv4+0xac5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x76c, 0xac5, x86_l_ac5);
x86_l_772:
	/* 0x772: movzx  eax,BYTE PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_777:
	/* 0x777: cmp    eax,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 58ULL);
x86_l_77a:
	/* 0x77a: je     7a8 <tail_handle_nat_fwd_ipv4+0x7a8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x77a, 0x7a8, x86_l_7a8);
x86_l_77c:
	/* 0x77c: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_77f:
	/* 0x77f: je     799 <tail_handle_nat_fwd_ipv4+0x799> */
	X86_SIM_X86_JCC(X86_CC_E, 0x77f, 0x799, x86_l_799);
x86_l_781:
	/* 0x781: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_784:
	/* 0x784: jne    7b1 <tail_handle_nat_fwd_ipv4+0x7b1> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x784, 0x7b1, x86_l_7b1);
x86_l_786:
	/* 0x786: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_788:
	/* 0x788: mov    ebp,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 16ULL);
x86_l_78d:
	/* 0x78d: jmp    7b6 <tail_handle_nat_fwd_ipv4+0x7b6> */
	X86_SIM_X86_JMP(0x78d, 0x7b6, x86_l_7b6);
x86_l_78f:
	/* 0x78f: mov    ecx,0x99 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 153ULL);
x86_l_794:
	/* 0x794: jmp    57 <tail_handle_nat_fwd_ipv4+0x57> */
	X86_SIM_X86_JMP(0x794, 0x57, x86_l_57);
x86_l_799:
	/* 0x799: mov    r12d,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 32ULL);
x86_l_79f:
	/* 0x79f: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_7a4:
	/* 0x7a4: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7a6:
	/* 0x7a6: jmp    7b9 <tail_handle_nat_fwd_ipv4+0x7b9> */
	X86_SIM_X86_JMP(0x7a6, 0x7b9, x86_l_7b9);
x86_l_7a8:
	/* 0x7a8: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7aa:
	/* 0x7aa: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_7af:
	/* 0x7af: jmp    7b6 <tail_handle_nat_fwd_ipv4+0x7b6> */
	X86_SIM_X86_JMP(0x7af, 0x7b6, x86_l_7b6);
x86_l_7b1:
	/* 0x7b1: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7b3:
	/* 0x7b3: mov    sil,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_8, 1ULL);
x86_l_7b6:
	/* 0x7b6: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7b9:
	/* 0x7b9: movzx  edx,WORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 64ULL);
x86_l_7be:
	/* 0x7be: test   dx,dx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_16);
x86_l_7c1:
	/* 0x7c1: je     849 <tail_handle_nat_fwd_ipv4+0x849> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7c1, 0x849, x86_l_849);
x86_l_7c7:
	/* 0x7c7: movzx  edi,WORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 24ULL);
x86_l_7cc:
	/* 0x7cc: mov    ecx,0x8e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 142ULL);
x86_l_7d1:
	/* 0x7d1: cmp    eax,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_7d4:
	/* 0x7d4: jg     7e5 <tail_handle_nat_fwd_ipv4+0x7e5> */
	X86_SIM_X86_JCC(X86_CC_G, 0x7d4, 0x7e5, x86_l_7e5);
x86_l_7d6:
	/* 0x7d6: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7d9:
	/* 0x7d9: je     849 <tail_handle_nat_fwd_ipv4+0x849> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7d9, 0x849, x86_l_849);
x86_l_7db:
	/* 0x7db: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_7de:
	/* 0x7de: je     7f3 <tail_handle_nat_fwd_ipv4+0x7f3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7de, 0x7f3, x86_l_7f3);
x86_l_7e0:
	/* 0x7e0: jmp    57 <tail_handle_nat_fwd_ipv4+0x57> */
	X86_SIM_X86_JMP(0x7e0, 0x57, x86_l_57);
x86_l_7e5:
	/* 0x7e5: cmp    eax,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 58ULL);
x86_l_7e8:
	/* 0x7e8: je     849 <tail_handle_nat_fwd_ipv4+0x849> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7e8, 0x849, x86_l_849);
x86_l_7ea:
	/* 0x7ea: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_7ed:
	/* 0x7ed: jne    57 <tail_handle_nat_fwd_ipv4+0x57> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x7ed, 0x57, x86_l_57);
x86_l_7f3:
	/* 0x7f3: cmp    dx,di */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_16);
x86_l_7f6:
	/* 0x7f6: je     849 <tail_handle_nat_fwd_ipv4+0x849> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7f6, 0x849, x86_l_849);
x86_l_7f8:
	/* 0x7f8: mov    DWORD PTR [rsp+0xc],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_7fc:
	/* 0x7fc: mov    DWORD PTR [rsp+0x20],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_800:
	/* 0x800: mov    WORD PTR [rsp+0x28],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_805:
	/* 0x805: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_80a:
	/* 0x80a: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_80f:
	/* 0x80f: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_812:
	/* 0x812: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_815:
	/* 0x815: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_81a:
	/* 0x81a: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_81d:
	/* 0x81d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_81f:
	/* 0x81f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_821:
	/* 0x821: js     87f <tail_handle_nat_fwd_ipv4+0x87f> */
	X86_SIM_X86_JCC(X86_CC_S, 0x821, 0x87f, x86_l_87f);
x86_l_823:
	/* 0x823: movzx  ecx,WORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 40ULL);
x86_l_828:
	/* 0x828: lea    esi,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_82c:
	/* 0x82c: mov    r8d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R12, X86_WIDTH_32);
x86_l_82f:
	/* 0x82f: or     r8d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_833:
	/* 0x833: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_838:
	/* 0x838: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_83b:
	/* 0x83b: mov    edx,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_83f:
	/* 0x83f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_841:
	/* 0x841: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_843:
	/* 0x843: js     875 <tail_handle_nat_fwd_ipv4+0x875> */
	X86_SIM_X86_JCC(X86_CC_S, 0x843, 0x875, x86_l_875);
x86_l_845:
	/* 0x845: mov    esi,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_849:
	/* 0x849: test   sil,sil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_8);
x86_l_84c:
	/* 0x84c: jne    ac5 <tail_handle_nat_fwd_ipv4+0xac5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x84c, 0xac5, x86_l_ac5);
x86_l_852:
	/* 0x852: add    ebp,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R14, X86_WIDTH_32, X86_ALU_ADD);
x86_l_855:
	/* 0x855: or     r12d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_OR, 16ULL);
x86_l_859:
	/* 0x859: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_85e:
	/* 0x85e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_861:
	/* 0x861: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_863:
	/* 0x863: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_865:
	/* 0x865: mov    ecx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_32);
x86_l_868:
	/* 0x868: mov    r8d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R12, X86_WIDTH_32);
x86_l_86b:
	/* 0x86b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_86d:
	/* 0x86d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_86f:
	/* 0x86f: jns    ac5 <tail_handle_nat_fwd_ipv4+0xac5> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x86f, 0xac5, x86_l_ac5);
x86_l_875:
	/* 0x875: mov    ecx,0x9a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 154ULL);
x86_l_87a:
	/* 0x87a: jmp    57 <tail_handle_nat_fwd_ipv4+0x57> */
	X86_SIM_X86_JMP(0x87a, 0x57, x86_l_57);
x86_l_87f:
	/* 0x87f: mov    ecx,0x8d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 141ULL);
x86_l_884:
	/* 0x884: jmp    57 <tail_handle_nat_fwd_ipv4+0x57> */
	X86_SIM_X86_JMP(0x884, 0x57, x86_l_57);
x86_l_889:
	/* 0x889: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_88e:
	/* 0x88e: mov    rdi,QWORD PTR [rip+0x5e80] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv4_frag_datagrams)));
x86_l_895:
	/* 0x895: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_89a:
	/* 0x89a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_89c:
	/* 0x89c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_89f:
	/* 0x89f: je     8bb <tail_handle_nat_fwd_ipv4+0x8bb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x89f, 0x8bb, x86_l_8bb);
x86_l_8a1:
	/* 0x8a1: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8a3:
	/* 0x8a3: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_8a7:
	/* 0x8a7: jmp    1d4 <tail_handle_nat_fwd_ipv4+0x1d4> */
	X86_SIM_X86_JMP(0x8a7, 0x1d4, x86_l_1d4);
x86_l_8ac:
	/* 0x8ac: mov    ecx,0x9d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 157ULL);
x86_l_8b1:
	/* 0x8b1: mov    r13d,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_8b6:
	/* 0x8b6: jmp    57 <tail_handle_nat_fwd_ipv4+0x57> */
	X86_SIM_X86_JMP(0x8b6, 0x57, x86_l_57);
x86_l_8bb:
	/* 0x8bb: mov    ecx,0xaf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 175ULL);
x86_l_8c0:
	/* 0x8c0: mov    r13d,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_8c5:
	/* 0x8c5: jmp    57 <tail_handle_nat_fwd_ipv4+0x57> */
	X86_SIM_X86_JMP(0x8c5, 0x57, x86_l_57);
x86_l_8ca:
	/* 0x8ca: mov    QWORD PTR [rsp+0x28],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691841ULL);
x86_l_8d3:
	/* 0x8d3: mov    QWORD PTR [rsp+0x30],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_8d8:
	/* 0x8d8: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_8dd:
	/* 0x8dd: mov    rdi,QWORD PTR [rip+0x5e80] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_8e4:
	/* 0x8e4: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_8e9:
	/* 0x8e9: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_8ee:
	/* 0x8ee: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8f0:
	/* 0x8f0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8f2:
	/* 0x8f2: jmp    1d4 <tail_handle_nat_fwd_ipv4+0x1d4> */
	X86_SIM_X86_JMP(0x8f2, 0x1d4, x86_l_1d4);
x86_l_8f7:
	/* 0x8f7: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_8fc:
	/* 0x8fc: jmp    3f7 <tail_handle_nat_fwd_ipv4+0x3f7> */
	X86_SIM_X86_JMP(0x8fc, 0x3f7, x86_l_3f7);
x86_l_901:
	/* 0x901: mov    r13d,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_906:
	/* 0x906: jmp    57 <tail_handle_nat_fwd_ipv4+0x57> */
	X86_SIM_X86_JMP(0x906, 0x57, x86_l_57);
x86_l_90b:
	/* 0x90b: mov    ebp,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_910:
	/* 0x910: cmp    BYTE PTR [rsp+0xb],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 47244640262ULL);
x86_l_915:
	/* 0x915: jne    94b <tail_handle_nat_fwd_ipv4+0x94b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x915, 0x94b, x86_l_94b);
x86_l_917:
	/* 0x917: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_91a:
	/* 0x91a: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_91c:
	/* 0x91c: shr    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_91f:
	/* 0x91f: and    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_922:
	/* 0x922: or     ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_OR);
x86_l_924:
	/* 0x924: mov    WORD PTR [r14+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_929:
	/* 0x929: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_92b:
	/* 0x92b: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_930:
	/* 0x930: mov    ebp,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 21600ULL);
x86_l_935:
	/* 0x935: cmove  ebp,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_938:
	/* 0x938: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_93c:
	/* 0x93c: je     94b <tail_handle_nat_fwd_ipv4+0x94b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x93c, 0x94b, x86_l_94b);
x86_l_93e:
	/* 0x93e: mov    rax,QWORD PTR [rip+0x5e80] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_945:
	/* 0x945: imul   ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_948:
	/* 0x948: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_94b:
	/* 0x94b: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_94f:
	/* 0x94f: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_953:
	/* 0x953: je     964 <tail_handle_nat_fwd_ipv4+0x964> */
	X86_SIM_X86_JCC(X86_CC_E, 0x953, 0x964, x86_l_964);
x86_l_955:
	/* 0x955: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_95a:
	/* 0x95a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_95c:
	/* 0x95c: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_95e:
	/* 0x95e: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_962:
	/* 0x962: jmp    987 <tail_handle_nat_fwd_ipv4+0x987> */
	X86_SIM_X86_JMP(0x962, 0x987, x86_l_987);
x86_l_964:
	/* 0x964: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_969:
	/* 0x969: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_96b:
	/* 0x96b: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_96d:
	/* 0x96d: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_971:
	/* 0x971: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_97b:
	/* 0x97b: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_97e:
	/* 0x97e: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_983:
	/* 0x983: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_987:
	/* 0x987: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_989:
	/* 0x989: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_98c:
	/* 0x98c: mov    DWORD PTR [r14+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_990:
	/* 0x990: movzx  ecx,BYTE PTR [r14+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_995:
	/* 0x995: mov    edx,DWORD PTR [r14+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_999:
	/* 0x999: and    r12b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_99d:
	/* 0x99d: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9a1:
	/* 0x9a1: je     9b4 <tail_handle_nat_fwd_ipv4+0x9b4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9a1, 0x9b4, x86_l_9b4);
x86_l_9a3:
	/* 0x9a3: mov    rsi,QWORD PTR [rip+0x5e80] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_9aa:
	/* 0x9aa: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9ac:
	/* 0x9ac: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_9af:
	/* 0x9af: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_9b2:
	/* 0x9b2: jmp    9b9 <tail_handle_nat_fwd_ipv4+0x9b9> */
	X86_SIM_X86_JMP(0x9b2, 0x9b9, x86_l_9b9);
x86_l_9b4:
	/* 0x9b4: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_9b9:
	/* 0x9b9: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_9bb:
	/* 0x9bb: or     r12b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_9be:
	/* 0x9be: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_9c0:
	/* 0x9c0: mov    r15d,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9c5:
	/* 0x9c5: mov    r8d,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_9ca:
	/* 0x9ca: jb     9d1 <tail_handle_nat_fwd_ipv4+0x9d1> */
	X86_SIM_X86_JCC(X86_CC_B, 0x9ca, 0x9d1, x86_l_9d1);
x86_l_9cc:
	/* 0x9cc: cmp    cl,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R12, X86_WIDTH_8);
x86_l_9cf:
	/* 0x9cf: je     9e2 <tail_handle_nat_fwd_ipv4+0x9e2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9cf, 0x9e2, x86_l_9e2);
x86_l_9d1:
	/* 0x9d1: mov    BYTE PTR [r14+0x2b],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_9d5:
	/* 0x9d5: mov    DWORD PTR [r14+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_9d9:
	/* 0x9d9: mov    rax,QWORD PTR [rip+0x5e80] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_9e0:
	/* 0x9e0: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9e2:
	/* 0x9e2: test   r8b,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R8, X86_WIDTH_8, 1ULL);
x86_l_9e6:
	/* 0x9e6: jne    ac5 <tail_handle_nat_fwd_ipv4+0xac5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x9e6, 0xac5, x86_l_ac5);
x86_l_9ec:
	/* 0x9ec: mov    DWORD PTR [rbx+0x2c],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_9f0:
	/* 0x9f0: mov    r13d,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_9f5:
	/* 0x9f5: mov    DWORD PTR [rbx+0x28],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_9f9:
	/* 0x9f9: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_9fe:
	/* 0x9fe: mov    rsi,QWORD PTR [rip+0x5e80] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_a05:
	/* 0xa05: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_a08:
	/* 0xa08: mov    edx,0x26 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 38ULL);
x86_l_a0d:
	/* 0xa0d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a0f:
	/* 0xa0f: mov    ecx,0x8c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 140ULL);
x86_l_a14:
	/* 0xa14: mov    eax,0x2600 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9728ULL);
x86_l_a19:
	/* 0xa19: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_a1b:
	/* 0xa1b: mov    DWORD PTR [rbx+0x28],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a1f:
	/* 0xa1f: mov    DWORD PTR [rbx+0x2c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561024ULL);
x86_l_a26:
	/* 0xa26: mov    DWORD PTR [rbx+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a29:
	/* 0xa29: movabs rax,0x24d710200000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 165913014686449664ULL);
x86_l_a33:
	/* 0xa33: mov    QWORD PTR [rbx+0x34],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_a37:
	/* 0xa37: mov    r14d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_a3b:
	/* 0xa3b: movabs rax,0x71024d0200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 485369905664ULL);
x86_l_a45:
	/* 0xa45: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a4a:
	/* 0xa4a: mov    BYTE PTR [rsp+0x10],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a4e:
	/* 0xa4e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a53:
	/* 0xa53: mov    rdi,QWORD PTR [rip+0x5e80] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_a5a:
	/* 0xa5a: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a5f:
	/* 0xa5f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a61:
	/* 0xa61: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a64:
	/* 0xa64: je     a6f <tail_handle_nat_fwd_ipv4+0xa6f> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa64, 0xa6f, x86_l_a6f);
x86_l_a66:
	/* 0xa66: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_a69:
	/* 0xa69: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_a6d:
	/* 0xa6d: jmp    a97 <tail_handle_nat_fwd_ipv4+0xa97> */
	X86_SIM_X86_JMP(0xa6d, 0xa97, x86_l_a97);
x86_l_a6f:
	/* 0xa6f: mov    QWORD PTR [rsp+0x28],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691841ULL);
x86_l_a78:
	/* 0xa78: mov    QWORD PTR [rsp+0x30],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a7d:
	/* 0xa7d: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_a82:
	/* 0xa82: mov    rdi,QWORD PTR [rip+0x5e80] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_a89:
	/* 0xa89: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a8e:
	/* 0xa8e: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a93:
	/* 0xa93: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a95:
	/* 0xa95: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a97:
	/* 0xa97: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_a9c:
	/* 0xa9c: mov    rsi,QWORD PTR [rip+0x5e80] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_aa3:
	/* 0xaa3: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_aa6:
	/* 0xaa6: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_aab:
	/* 0xaab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aad:
	/* 0xaad: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_ab2:
	/* 0xab2: add    rsp,0x68 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 104ULL);
x86_l_ab6:
	/* 0xab6: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_ab7:
	/* 0xab7: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_ab9:
	/* 0xab9: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_abb:
	/* 0xabb: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_abd:
	/* 0xabd: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_abf:
	/* 0xabf: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_ac0:
	/* 0xac0: jmp    b36 <tail_handle_nat_fwd_ipv4+0xb36> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_ac5:
	/* 0xac5: mov    rax,QWORD PTR [rip+0x5e7c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_interface_ifindex)));
x86_l_acc:
	/* 0xacc: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ace:
	/* 0xace: mov    ebx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_ad1:
	/* 0xad1: movabs rax,0x71024d0200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 485369905664ULL);
x86_l_adb:
	/* 0xadb: add    rax,0x5000d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 327693ULL);
x86_l_ae1:
	/* 0xae1: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ae6:
	/* 0xae6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_aeb:
	/* 0xaeb: mov    rdi,QWORD PTR [rip+0x5e7c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_af2:
	/* 0xaf2: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_af7:
	/* 0xaf7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_af9:
	/* 0xaf9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_afc:
	/* 0xafc: je     b07 <tail_handle_nat_fwd_ipv4+0xb07> */
	X86_SIM_X86_JCC(X86_CC_E, 0xafc, 0xb07, x86_l_b07);
x86_l_afe:
	/* 0xafe: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_b01:
	/* 0xb01: add    QWORD PTR [rax+0x8],rbx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_b05:
	/* 0xb05: jmp    b2f <tail_handle_nat_fwd_ipv4+0xb2f> */
	X86_SIM_X86_JMP(0xb05, 0xb2f, x86_l_b2f);
x86_l_b07:
	/* 0xb07: mov    QWORD PTR [rsp+0x28],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691841ULL);
x86_l_b10:
	/* 0xb10: mov    QWORD PTR [rsp+0x30],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_b15:
	/* 0xb15: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_b1a:
	/* 0xb1a: mov    rdi,QWORD PTR [rip+0x5e7c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_b21:
	/* 0xb21: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b26:
	/* 0xb26: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b2b:
	/* 0xb2b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b2d:
	/* 0xb2d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b2f:
	/* 0xb2f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b31:
	/* 0xb31: jmp    ab2 <tail_handle_nat_fwd_ipv4+0xab2> */
	X86_SIM_X86_JMP(0xb31, 0xab2, x86_l_ab2);
x86_l_b36:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
