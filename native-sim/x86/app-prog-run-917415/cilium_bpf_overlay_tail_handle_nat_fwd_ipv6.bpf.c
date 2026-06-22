extern char __config_debug_lb;
extern char __config_enable_conntrack_accounting;
extern char __config_enable_ipv6_fragments;
extern char __config_enable_jiffies;
extern char __config_interface_ifindex;
extern char __config_kernel_hz;
extern char __config_trace_payload_len;
extern char cilium_calls;
extern char cilium_ct6_global;
extern char cilium_ct_any6_global;
extern char cilium_ipv6_frag_datagrams;
extern char cilium_lb6_reverse_nat;
extern char cilium_metrics;
extern char cilium_snat_v6_external;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int cilium_bpf_overlay_tail_handle_nat_fwd_ipv6_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0x98 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 152ULL);
x86_l_a:
	/* 0xa: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: mov    r15d,DWORD PTR [rdi+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_11:
	/* 0x11: mov    r14d,DWORD PTR [rdi+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_15:
	/* 0x15: mov    DWORD PTR [rdi+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1c:
	/* 0x1c: mov    DWORD PTR [rdi+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_23:
	/* 0x23: mov    rax,QWORD PTR [rip+0xd037] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_2a:
	/* 0x2a: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c:
	/* 0x2c: mov    QWORD PTR [rsp+0x6e],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 472446402560ULL);
x86_l_35:
	/* 0x35: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_3e:
	/* 0x3e: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_47:
	/* 0x47: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_50:
	/* 0x50: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_59:
	/* 0x59: mov    r13d,DWORD PTR [rdi+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_5d:
	/* 0x5d: mov    eax,DWORD PTR [rdi+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_60:
	/* 0x60: lea    rcx,[r13+0x36] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_64:
	/* 0x64: mov    r12d,0x86 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 134ULL);
x86_l_6a:
	/* 0x6a: cmp    rcx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_6d:
	/* 0x6d: ja     6d5 <tail_handle_nat_fwd_ipv6+0x6d5> */
	X86_SIM_X86_JCC(X86_CC_A, 0x6d, 0x6d5, x86_l_6d5);
x86_l_73:
	/* 0x73: movzx  ebp,BYTE PTR [r13+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 20ULL);
x86_l_78:
	/* 0x78: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7a:
	/* 0x7a: mov    BYTE PTR [rsp+0x74],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_7f:
	/* 0x7f: mov    edi,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 40ULL);
x86_l_84:
	/* 0x84: cmp    rbp,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 60ULL);
x86_l_88:
	/* 0x88: ja     541 <tail_handle_nat_fwd_ipv6+0x541> */
	X86_SIM_X86_JCC(X86_CC_A, 0x88, 0x541, x86_l_541);
x86_l_8e:
	/* 0x8e: mov    r12d,0x9c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 156ULL);
x86_l_94:
	/* 0x94: movabs rax,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_9e:
	/* 0x9e: bt     rax,rbp */
	X86_SIM_L_EXEC_BT(X86_RAX, X86_RBP, X86_WIDTH_64);
x86_l_a2:
	/* 0xa2: jae    1b5 <tail_handle_nat_fwd_ipv6+0x1b5> */
	X86_SIM_X86_JCC(X86_CC_AE, 0xa2, 0x1b5, x86_l_1b5);
x86_l_a8:
	/* 0xa8: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ad:
	/* 0xad: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_b2:
	/* 0xb2: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_b5:
	/* 0xb5: mov    esi,0x36 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 54ULL);
x86_l_ba:
	/* 0xba: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_bf:
	/* 0xbf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c1:
	/* 0xc1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c3:
	/* 0xc3: js     519 <tail_handle_nat_fwd_ipv6+0x519> */
	X86_SIM_X86_JCC(X86_CC_S, 0xc3, 0x519, x86_l_519);
x86_l_c9:
	/* 0xc9: movzx  esi,BYTE PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 24ULL);
x86_l_ce:
	/* 0xce: cmp    ebp,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 43ULL);
x86_l_d1:
	/* 0xd1: mov    DWORD PTR [rsp+0x4],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_d6:
	/* 0xd6: mov    DWORD PTR [rsp+0x8],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_db:
	/* 0xdb: jle    fa <tail_handle_nat_fwd_ipv6+0xfa> */
	X86_SIM_X86_JCC(X86_CC_LE, 0xdb, 0xfa, x86_l_fa);
x86_l_dd:
	/* 0xdd: cmp    ebp,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_e0:
	/* 0xe0: je     fa <tail_handle_nat_fwd_ipv6+0xfa> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe0, 0xfa, x86_l_fa);
x86_l_e2:
	/* 0xe2: cmp    ebp,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 51ULL);
x86_l_e5:
	/* 0xe5: jne    1c4 <tail_handle_nat_fwd_ipv6+0x1c4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe5, 0x1c4, x86_l_1c4);
x86_l_eb:
	/* 0xeb: movzx  eax,BYTE PTR [rsp+0x19] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 25ULL);
x86_l_f0:
	/* 0xf0: lea    r14d,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_f8:
	/* 0xf8: jmp    114 <tail_handle_nat_fwd_ipv6+0x114> */
	X86_SIM_X86_JMP(0xf8, 0x114, x86_l_114);
x86_l_fa:
	/* 0xfa: movzx  eax,BYTE PTR [rsp+0x19] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 25ULL);
x86_l_ff:
	/* 0xff: lea    r14d,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_107:
	/* 0x107: cmp    bpl,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 44ULL);
x86_l_10b:
	/* 0x10b: jne    114 <tail_handle_nat_fwd_ipv6+0x114> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x10b, 0x114, x86_l_114);
x86_l_10d:
	/* 0x10d: mov    ebp,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RSI, X86_WIDTH_32);
x86_l_10f:
	/* 0x10f: jmp    1cc <tail_handle_nat_fwd_ipv6+0x1cc> */
	X86_SIM_X86_JMP(0x10f, 0x1cc, x86_l_1cc);
x86_l_114:
	/* 0x114: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_116:
	/* 0x116: movzx  r15d,sil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_RSI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_11a:
	/* 0x11a: lea    edi,[r14+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_11e:
	/* 0x11e: cmp    r15d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 60ULL);
x86_l_122:
	/* 0x122: ja     24b <tail_handle_nat_fwd_ipv6+0x24b> */
	X86_SIM_X86_JCC(X86_CC_A, 0x122, 0x24b, x86_l_24b);
x86_l_128:
	/* 0x128: mov    eax,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_12b:
	/* 0x12b: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_135:
	/* 0x135: bt     rdx,rax */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_139:
	/* 0x139: jae    252 <tail_handle_nat_fwd_ipv6+0x252> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x139, 0x252, x86_l_252);
x86_l_13f:
	/* 0x13f: mov    BYTE PTR [rsp+0xc],sil */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_144:
	/* 0x144: mov    QWORD PTR [rsp+0x40],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_149:
	/* 0x149: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14e:
	/* 0x14e: add    r14d,0x36 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 54ULL);
x86_l_152:
	/* 0x152: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_157:
	/* 0x157: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_15c:
	/* 0x15c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_15f:
	/* 0x15f: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_162:
	/* 0x162: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_167:
	/* 0x167: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_169:
	/* 0x169: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_16b:
	/* 0x16b: js     3a4 <tail_handle_nat_fwd_ipv6+0x3a4> */
	X86_SIM_X86_JCC(X86_CC_S, 0x16b, 0x3a4, x86_l_3a4);
x86_l_171:
	/* 0x171: movzx  ebp,BYTE PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 24ULL);
x86_l_176:
	/* 0x176: cmp    r15d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 43ULL);
x86_l_17a:
	/* 0x17a: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17f:
	/* 0x17f: jle    259 <tail_handle_nat_fwd_ipv6+0x259> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x17f, 0x259, x86_l_259);
x86_l_185:
	/* 0x185: cmp    r15d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 44ULL);
x86_l_189:
	/* 0x189: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_18e:
	/* 0x18e: je     281 <tail_handle_nat_fwd_ipv6+0x281> */
	X86_SIM_X86_JCC(X86_CC_E, 0x18e, 0x281, x86_l_281);
x86_l_194:
	/* 0x194: cmp    r15d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 51ULL);
x86_l_198:
	/* 0x198: movzx  esi,BYTE PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 12ULL);
x86_l_19d:
	/* 0x19d: jne    28e <tail_handle_nat_fwd_ipv6+0x28e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x19d, 0x28e, x86_l_28e);
x86_l_1a3:
	/* 0x1a3: movzx  eax,BYTE PTR [rsp+0x19] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 25ULL);
x86_l_1a8:
	/* 0x1a8: lea    r8d,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_1b0:
	/* 0x1b0: jmp    31e <tail_handle_nat_fwd_ipv6+0x31e> */
	X86_SIM_X86_JMP(0x1b0, 0x31e, x86_l_31e);
x86_l_1b5:
	/* 0x1b5: cmp    rbp,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 59ULL);
x86_l_1b9:
	/* 0x1b9: je     6d5 <tail_handle_nat_fwd_ipv6+0x6d5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1b9, 0x6d5, x86_l_6d5);
x86_l_1bf:
	/* 0x1bf: jmp    541 <tail_handle_nat_fwd_ipv6+0x541> */
	X86_SIM_X86_JMP(0x1bf, 0x541, x86_l_541);
x86_l_1c4:
	/* 0x1c4: mov    ebp,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RSI, X86_WIDTH_32);
x86_l_1c6:
	/* 0x1c6: mov    r14d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 8ULL);
x86_l_1cc:
	/* 0x1cc: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1d5:
	/* 0x1d5: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1da:
	/* 0x1da: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1df:
	/* 0x1df: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1e2:
	/* 0x1e2: mov    esi,0x36 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 54ULL);
x86_l_1e7:
	/* 0x1e7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1ec:
	/* 0x1ec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ee:
	/* 0x1ee: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1f0:
	/* 0x1f0: js     519 <tail_handle_nat_fwd_ipv6+0x519> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1f0, 0x519, x86_l_519);
x86_l_1f6:
	/* 0x1f6: mov    eax,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1fa:
	/* 0x1fa: movzx  ecx,BYTE PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 24ULL);
x86_l_1ff:
	/* 0x1ff: shl    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_203:
	/* 0x203: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_206:
	/* 0x206: movzx  eax,WORD PTR [rsp+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 26ULL);
x86_l_20b:
	/* 0x20b: movabs rdx,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1099511627776ULL);
x86_l_215:
	/* 0x215: or     rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_218:
	/* 0x218: test   eax,0xf9ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63999ULL);
x86_l_21d:
	/* 0x21d: cmove  rdx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_64, X86_CC_E);
x86_l_221:
	/* 0x221: movabs rcx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2199023255552ULL);
x86_l_22b:
	/* 0x22b: or     rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_OR);
x86_l_22e:
	/* 0x22e: test   eax,0xf8ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63743ULL);
x86_l_233:
	/* 0x233: cmove  rcx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_237:
	/* 0x237: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_239:
	/* 0x239: movzx  r15d,sil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_RSI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_23d:
	/* 0x23d: lea    edi,[r14+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_241:
	/* 0x241: cmp    r15d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 60ULL);
x86_l_245:
	/* 0x245: jbe    128 <tail_handle_nat_fwd_ipv6+0x128> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x245, 0x128, x86_l_128);
x86_l_24b:
	/* 0x24b: mov    ebp,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RSI, X86_WIDTH_32);
x86_l_24d:
	/* 0x24d: jmp    537 <tail_handle_nat_fwd_ipv6+0x537> */
	X86_SIM_X86_JMP(0x24d, 0x537, x86_l_537);
x86_l_252:
	/* 0x252: mov    ebp,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RSI, X86_WIDTH_32);
x86_l_254:
	/* 0x254: jmp    3af <tail_handle_nat_fwd_ipv6+0x3af> */
	X86_SIM_X86_JMP(0x254, 0x3af, x86_l_3af);
x86_l_259:
	/* 0x259: mov    r15d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_25e:
	/* 0x25e: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_263:
	/* 0x263: movzx  esi,BYTE PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 12ULL);
x86_l_268:
	/* 0x268: movzx  eax,BYTE PTR [rsp+0x19] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 25ULL);
x86_l_26d:
	/* 0x26d: lea    r8d,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_275:
	/* 0x275: cmp    sil,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_8, 44ULL);
x86_l_279:
	/* 0x279: jne    31e <tail_handle_nat_fwd_ipv6+0x31e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x279, 0x31e, x86_l_31e);
x86_l_27f:
	/* 0x27f: jmp    2a6 <tail_handle_nat_fwd_ipv6+0x2a6> */
	X86_SIM_X86_JMP(0x27f, 0x2a6, x86_l_2a6);
x86_l_281:
	/* 0x281: mov    r8d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 8ULL);
x86_l_287:
	/* 0x287: mov    r15d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_28c:
	/* 0x28c: jmp    2a6 <tail_handle_nat_fwd_ipv6+0x2a6> */
	X86_SIM_X86_JMP(0x28c, 0x2a6, x86_l_2a6);
x86_l_28e:
	/* 0x28e: mov    r15d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_293:
	/* 0x293: movzx  eax,BYTE PTR [rsp+0x19] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 25ULL);
x86_l_298:
	/* 0x298: lea    r8d,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2a0:
	/* 0x2a0: cmp    sil,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_8, 44ULL);
x86_l_2a4:
	/* 0x2a4: jne    31e <tail_handle_nat_fwd_ipv6+0x31e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2a4, 0x31e, x86_l_31e);
x86_l_2a6:
	/* 0x2a6: mov    QWORD PTR [rsp+0x10],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ab:
	/* 0x2ab: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_2b4:
	/* 0x2b4: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2b9:
	/* 0x2b9: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_2be:
	/* 0x2be: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2c1:
	/* 0x2c1: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_2c4:
	/* 0x2c4: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2c9:
	/* 0x2c9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2cb:
	/* 0x2cb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2cd:
	/* 0x2cd: js     519 <tail_handle_nat_fwd_ipv6+0x519> */
	X86_SIM_X86_JCC(X86_CC_S, 0x2cd, 0x519, x86_l_519);
x86_l_2d3:
	/* 0x2d3: mov    eax,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_2d7:
	/* 0x2d7: movzx  ecx,BYTE PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 24ULL);
x86_l_2dc:
	/* 0x2dc: shl    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_2e0:
	/* 0x2e0: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2e3:
	/* 0x2e3: movzx  eax,WORD PTR [rsp+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 26ULL);
x86_l_2e8:
	/* 0x2e8: movabs rdx,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1099511627776ULL);
x86_l_2f2:
	/* 0x2f2: or     rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_2f5:
	/* 0x2f5: test   eax,0xf9ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63999ULL);
x86_l_2fa:
	/* 0x2fa: cmove  rdx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_64, X86_CC_E);
x86_l_2fe:
	/* 0x2fe: movabs rcx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2199023255552ULL);
x86_l_308:
	/* 0x308: or     rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_OR);
x86_l_30b:
	/* 0x30b: test   eax,0xf8ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63743ULL);
x86_l_310:
	/* 0x310: cmove  rcx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_314:
	/* 0x314: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_319:
	/* 0x319: mov    r8,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_31e:
	/* 0x31e: movzx  r15d,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_322:
	/* 0x322: lea    edi,[r8+rdx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_326:
	/* 0x326: cmp    r15d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 60ULL);
x86_l_32a:
	/* 0x32a: ja     537 <tail_handle_nat_fwd_ipv6+0x537> */
	X86_SIM_X86_JCC(X86_CC_A, 0x32a, 0x537, x86_l_537);
x86_l_330:
	/* 0x330: mov    eax,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_333:
	/* 0x333: movabs rsi,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_33d:
	/* 0x33d: bt     rsi,rax */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_341:
	/* 0x341: jae    3af <tail_handle_nat_fwd_ipv6+0x3af> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x341, 0x3af, x86_l_3af);
x86_l_343:
	/* 0x343: mov    QWORD PTR [rsp+0x10],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_348:
	/* 0x348: mov    r14,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RCX, X86_WIDTH_64);
x86_l_34b:
	/* 0x34b: lea    esi,[r8+rdx*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_34f:
	/* 0x34f: add    esi,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 14ULL);
x86_l_352:
	/* 0x352: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_357:
	/* 0x357: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_35c:
	/* 0x35c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_35f:
	/* 0x35f: mov    DWORD PTR [rsp+0x40],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_363:
	/* 0x363: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_368:
	/* 0x368: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36a:
	/* 0x36a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_36c:
	/* 0x36c: js     3a4 <tail_handle_nat_fwd_ipv6+0x3a4> */
	X86_SIM_X86_JCC(X86_CC_S, 0x36c, 0x3a4, x86_l_3a4);
x86_l_36e:
	/* 0x36e: movzx  esi,BYTE PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 24ULL);
x86_l_373:
	/* 0x373: cmp    r15d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 43ULL);
x86_l_377:
	/* 0x377: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_37a:
	/* 0x37a: jle    3c8 <tail_handle_nat_fwd_ipv6+0x3c8> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x37a, 0x3c8, x86_l_3c8);
x86_l_37c:
	/* 0x37c: cmp    r15d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 44ULL);
x86_l_380:
	/* 0x380: mov    r8,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_385:
	/* 0x385: je     3d4 <tail_handle_nat_fwd_ipv6+0x3d4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x385, 0x3d4, x86_l_3d4);
x86_l_387:
	/* 0x387: cmp    r15d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 51ULL);
x86_l_38b:
	/* 0x38b: jne    3e1 <tail_handle_nat_fwd_ipv6+0x3e1> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x38b, 0x3e1, x86_l_3e1);
x86_l_38d:
	/* 0x38d: movzx  eax,BYTE PTR [rsp+0x19] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 25ULL);
x86_l_392:
	/* 0x392: lea    r9d,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_39a:
	/* 0x39a: mov    r15d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_39f:
	/* 0x39f: jmp    472 <tail_handle_nat_fwd_ipv6+0x472> */
	X86_SIM_X86_JMP(0x39f, 0x472, x86_l_472);
x86_l_3a4:
	/* 0x3a4: mov    r12d,0x86 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 134ULL);
x86_l_3aa:
	/* 0x3aa: jmp    6d0 <tail_handle_nat_fwd_ipv6+0x6d0> */
	X86_SIM_X86_JMP(0x3aa, 0x6d0, x86_l_6d0);
x86_l_3af:
	/* 0x3af: cmp    rax,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 59ULL);
x86_l_3b3:
	/* 0x3b3: mov    r15d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3b8:
	/* 0x3b8: mov    r14d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3bd:
	/* 0x3bd: je     6d5 <tail_handle_nat_fwd_ipv6+0x6d5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3bd, 0x6d5, x86_l_6d5);
x86_l_3c3:
	/* 0x3c3: jmp    541 <tail_handle_nat_fwd_ipv6+0x541> */
	X86_SIM_X86_JMP(0x3c3, 0x541, x86_l_541);
x86_l_3c8:
	/* 0x3c8: mov    r15d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3cd:
	/* 0x3cd: mov    r8,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3d2:
	/* 0x3d2: jmp    3e6 <tail_handle_nat_fwd_ipv6+0x3e6> */
	X86_SIM_X86_JMP(0x3d2, 0x3e6, x86_l_3e6);
x86_l_3d4:
	/* 0x3d4: mov    r9d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 8ULL);
x86_l_3da:
	/* 0x3da: mov    r15d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3df:
	/* 0x3df: jmp    3f9 <tail_handle_nat_fwd_ipv6+0x3f9> */
	X86_SIM_X86_JMP(0x3df, 0x3f9, x86_l_3f9);
x86_l_3e1:
	/* 0x3e1: mov    r15d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3e6:
	/* 0x3e6: movzx  eax,BYTE PTR [rsp+0x19] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 25ULL);
x86_l_3eb:
	/* 0x3eb: lea    r9d,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_3f3:
	/* 0x3f3: cmp    bpl,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 44ULL);
x86_l_3f7:
	/* 0x3f7: jne    472 <tail_handle_nat_fwd_ipv6+0x472> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3f7, 0x472, x86_l_472);
x86_l_3f9:
	/* 0x3f9: mov    r14,r9 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R9, X86_WIDTH_64);
x86_l_3fc:
	/* 0x3fc: mov    ebp,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RSI, X86_WIDTH_32);
x86_l_3fe:
	/* 0x3fe: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_407:
	/* 0x407: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_40c:
	/* 0x40c: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_411:
	/* 0x411: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_414:
	/* 0x414: mov    esi,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_418:
	/* 0x418: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_41d:
	/* 0x41d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41f:
	/* 0x41f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_421:
	/* 0x421: js     519 <tail_handle_nat_fwd_ipv6+0x519> */
	X86_SIM_X86_JCC(X86_CC_S, 0x421, 0x519, x86_l_519);
x86_l_427:
	/* 0x427: mov    eax,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_42b:
	/* 0x42b: movzx  ecx,BYTE PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 24ULL);
x86_l_430:
	/* 0x430: shl    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_434:
	/* 0x434: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_437:
	/* 0x437: movzx  eax,WORD PTR [rsp+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 26ULL);
x86_l_43c:
	/* 0x43c: movabs rdx,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1099511627776ULL);
x86_l_446:
	/* 0x446: or     rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_449:
	/* 0x449: test   eax,0xf9ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63999ULL);
x86_l_44e:
	/* 0x44e: cmove  rdx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_64, X86_CC_E);
x86_l_452:
	/* 0x452: movabs rcx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2199023255552ULL);
x86_l_45c:
	/* 0x45c: or     rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_OR);
x86_l_45f:
	/* 0x45f: test   eax,0xf8ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63743ULL);
x86_l_464:
	/* 0x464: cmove  rcx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_468:
	/* 0x468: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_46a:
	/* 0x46a: mov    r8,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_46f:
	/* 0x46f: mov    r9,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_R14, X86_WIDTH_64);
x86_l_472:
	/* 0x472: movzx  r14d,sil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_RSI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_476:
	/* 0x476: lea    edi,[r9+r8*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_47a:
	/* 0x47a: cmp    r14d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 60ULL);
x86_l_47e:
	/* 0x47e: ja     a2c <tail_handle_nat_fwd_ipv6+0xa2c> */
	X86_SIM_X86_JCC(X86_CC_A, 0x47e, 0xa2c, x86_l_a2c);
x86_l_484:
	/* 0x484: mov    eax,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_32);
x86_l_487:
	/* 0x487: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_491:
	/* 0x491: bt     rdx,rax */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_495:
	/* 0x495: jae    524 <tail_handle_nat_fwd_ipv6+0x524> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x495, 0x524, x86_l_524);
x86_l_49b:
	/* 0x49b: mov    r13d,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSI, X86_WIDTH_32);
x86_l_49e:
	/* 0x49e: lea    ebp,[r9+r8*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_4a2:
	/* 0x4a2: add    ebp,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 14ULL);
x86_l_4a5:
	/* 0x4a5: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4aa:
	/* 0x4aa: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_4af:
	/* 0x4af: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_4b2:
	/* 0x4b2: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_4b4:
	/* 0x4b4: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_4b9:
	/* 0x4b9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4bb:
	/* 0x4bb: mov    r12d,0x86 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 134ULL);
x86_l_4c1:
	/* 0x4c1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4c3:
	/* 0x4c3: js     6d5 <tail_handle_nat_fwd_ipv6+0x6d5> */
	X86_SIM_X86_JCC(X86_CC_S, 0x4c3, 0x6d5, x86_l_6d5);
x86_l_4c9:
	/* 0x4c9: cmp    r14d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 43ULL);
x86_l_4cd:
	/* 0x4cd: jle    4db <tail_handle_nat_fwd_ipv6+0x4db> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x4cd, 0x4db, x86_l_4db);
x86_l_4cf:
	/* 0x4cf: cmp    r14d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 44ULL);
x86_l_4d3:
	/* 0x4d3: je     4eb <tail_handle_nat_fwd_ipv6+0x4eb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4d3, 0x4eb, x86_l_4eb);
x86_l_4d5:
	/* 0x4d5: cmp    r14d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 51ULL);
x86_l_4d9:
	/* 0x4d9: je     50e <tail_handle_nat_fwd_ipv6+0x50e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4d9, 0x50e, x86_l_50e);
x86_l_4db:
	/* 0x4db: mov    r12d,0x9c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 156ULL);
x86_l_4e1:
	/* 0x4e1: cmp    r13b,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_8, 44ULL);
x86_l_4e5:
	/* 0x4e5: jne    6d5 <tail_handle_nat_fwd_ipv6+0x6d5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4e5, 0x6d5, x86_l_6d5);
x86_l_4eb:
	/* 0x4eb: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_4f4:
	/* 0x4f4: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4f9:
	/* 0x4f9: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_4fe:
	/* 0x4fe: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_501:
	/* 0x501: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_503:
	/* 0x503: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_508:
	/* 0x508: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_50a:
	/* 0x50a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_50c:
	/* 0x50c: js     519 <tail_handle_nat_fwd_ipv6+0x519> */
	X86_SIM_X86_JCC(X86_CC_S, 0x50c, 0x519, x86_l_519);
x86_l_50e:
	/* 0x50e: mov    r12d,0x9c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 156ULL);
x86_l_514:
	/* 0x514: jmp    6d5 <tail_handle_nat_fwd_ipv6+0x6d5> */
	X86_SIM_X86_JMP(0x514, 0x6d5, x86_l_6d5);
x86_l_519:
	/* 0x519: mov    r12d,0x86 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 134ULL);
x86_l_51f:
	/* 0x51f: jmp    6d5 <tail_handle_nat_fwd_ipv6+0x6d5> */
	X86_SIM_X86_JMP(0x51f, 0x6d5, x86_l_6d5);
x86_l_524:
	/* 0x524: mov    ebp,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RSI, X86_WIDTH_32);
x86_l_526:
	/* 0x526: cmp    rax,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 59ULL);
x86_l_52a:
	/* 0x52a: mov    r14d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_52f:
	/* 0x52f: je     6d5 <tail_handle_nat_fwd_ipv6+0x6d5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x52f, 0x6d5, x86_l_6d5);
x86_l_535:
	/* 0x535: jmp    541 <tail_handle_nat_fwd_ipv6+0x541> */
	X86_SIM_X86_JMP(0x535, 0x541, x86_l_541);
x86_l_537:
	/* 0x537: mov    r15d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_53c:
	/* 0x53c: mov    r14d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_541:
	/* 0x541: mov    BYTE PTR [rsp+0x74],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_546:
	/* 0x546: mov    rax,QWORD PTR [r13+0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 46ULL);
x86_l_54a:
	/* 0x54a: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_54f:
	/* 0x54f: mov    rax,QWORD PTR [r13+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_553:
	/* 0x553: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_558:
	/* 0x558: mov    rax,QWORD PTR [r13+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_55c:
	/* 0x55c: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_561:
	/* 0x561: mov    rax,QWORD PTR [r13+0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_565:
	/* 0x565: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_56a:
	/* 0x56a: cmp    bpl,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 17ULL);
x86_l_56e:
	/* 0x56e: je     57d <tail_handle_nat_fwd_ipv6+0x57d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x56e, 0x57d, x86_l_57d);
x86_l_570:
	/* 0x570: movzx  eax,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_574:
	/* 0x574: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_577:
	/* 0x577: jne    100d <tail_handle_nat_fwd_ipv6+0x100d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x577, 0x100d, x86_l_100d);
x86_l_57d:
	/* 0x57d: mov    DWORD PTR [rsp+0x8],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_582:
	/* 0x582: lea    esi,[rdi+0xe] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_585:
	/* 0x585: movabs rdx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 2199023255552ULL);
x86_l_58f:
	/* 0x58f: lea    r14,[rsp+0x70] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_594:
	/* 0x594: mov    rax,QWORD PTR [rip+0xd037] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_59b:
	/* 0x59b: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_59e:
	/* 0x59e: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5a3:
	/* 0x5a3: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_5a6:
	/* 0x5a6: mov    QWORD PTR [rsp+0x40],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_5ab:
	/* 0x5ab: je     60f <tail_handle_nat_fwd_ipv6+0x60f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5ab, 0x60f, x86_l_60f);
x86_l_5ad:
	/* 0x5ad: mov    DWORD PTR [rsp+0x4],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_5b2:
	/* 0x5b2: lea    rbp,[r13+0xe] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_5b6:
	/* 0x5b6: mov    r15,QWORD PTR [r13+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_5ba:
	/* 0x5ba: mov    QWORD PTR [r13+0xe],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60129542144ULL);
x86_l_5c2:
	/* 0x5c2: mov    DWORD PTR [r13+0xe],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_5c6:
	/* 0x5c6: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_5c9:
	/* 0x5c9: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_5cd:
	/* 0x5cd: mov    BYTE PTR [r13+0x12],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_5d1:
	/* 0x5d1: mov    r13,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_64);
x86_l_5d4:
	/* 0x5d4: test   rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_5d7:
	/* 0x5d7: jne    e5e <tail_handle_nat_fwd_ipv6+0xe5e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x5d7, 0xe5e, x86_l_e5e);
x86_l_5dd:
	/* 0x5dd: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_5e2:
	/* 0x5e2: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_5e5:
	/* 0x5e5: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_5e8:
	/* 0x5e8: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_5ed:
	/* 0x5ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5ef:
	/* 0x5ef: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5f1:
	/* 0x5f1: js     6c6 <tail_handle_nat_fwd_ipv6+0x6c6> */
	X86_SIM_X86_JCC(X86_CC_S, 0x5f1, 0x6c6, x86_l_6c6);
x86_l_5f7:
	/* 0x5f7: bt     QWORD PTR [rsp+0x10],0x28 */
	X86_SIM_L_EXEC_BT_MEM_IMM(X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 68719476776ULL);
x86_l_5fe:
	/* 0x5fe: jb     e83 <tail_handle_nat_fwd_ipv6+0xe83> */
	X86_SIM_X86_JCC(X86_CC_B, 0x5fe, 0xe83, x86_l_e83);
x86_l_604:
	/* 0x604: mov    QWORD PTR [rbp+0x0],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_608:
	/* 0x608: mov    r15d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_60d:
	/* 0x60d: jmp    635 <tail_handle_nat_fwd_ipv6+0x635> */
	X86_SIM_X86_JMP(0x60d, 0x635, x86_l_635);
x86_l_60f:
	/* 0x60f: test   rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_612:
	/* 0x612: jne    ee9 <tail_handle_nat_fwd_ipv6+0xee9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x612, 0xee9, x86_l_ee9);
x86_l_618:
	/* 0x618: mov    r13,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDX, X86_WIDTH_64);
x86_l_61b:
	/* 0x61b: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_620:
	/* 0x620: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_623:
	/* 0x623: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_626:
	/* 0x626: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_62b:
	/* 0x62b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_62d:
	/* 0x62d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_62f:
	/* 0x62f: js     7ee <tail_handle_nat_fwd_ipv6+0x7ee> */
	X86_SIM_X86_JCC(X86_CC_S, 0x62f, 0x7ee, x86_l_7ee);
x86_l_635:
	/* 0x635: movzx  ebp,BYTE PTR [rsp+0x75] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 117ULL);
x86_l_63a:
	/* 0x63a: cmp    BYTE PTR [rsp+0x74],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 498216206342ULL);
x86_l_63f:
	/* 0x63f: jne    64a <tail_handle_nat_fwd_ipv6+0x64a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x63f, 0x64a, x86_l_64a);
x86_l_641:
	/* 0x641: mov    rdi,QWORD PTR [rip+0xd037] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct6_global)));
x86_l_648:
	/* 0x648: jmp    651 <tail_handle_nat_fwd_ipv6+0x651> */
	X86_SIM_X86_JMP(0x648, 0x651, x86_l_651);
x86_l_64a:
	/* 0x64a: mov    rdi,QWORD PTR [rip+0xd037] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct_any6_global)));
x86_l_651:
	/* 0x651: mov    r14d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_656:
	/* 0x656: mov    BYTE PTR [rsp+0x75],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 502511173632ULL);
x86_l_65b:
	/* 0x65b: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_660:
	/* 0x660: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_665:
	/* 0x665: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_667:
	/* 0x667: mov    BYTE PTR [rsp+0x75],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 117ULL);
x86_l_66c:
	/* 0x66c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_66f:
	/* 0x66f: mov    r8,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_674:
	/* 0x674: je     100d <tail_handle_nat_fwd_ipv6+0x100d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x674, 0x100d, x86_l_100d);
x86_l_67a:
	/* 0x67a: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_67d:
	/* 0x67d: movzx  ecx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_681:
	/* 0x681: test   cl,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_684:
	/* 0x684: jne    780 <tail_handle_nat_fwd_ipv6+0x780> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x684, 0x780, x86_l_780);
x86_l_68a:
	/* 0x68a: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_68c:
	/* 0x68c: jns    100d <tail_handle_nat_fwd_ipv6+0x100d> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x68c, 0x100d, x86_l_100d);
x86_l_692:
	/* 0x692: movzx  ecx,WORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 40ULL);
x86_l_696:
	/* 0x696: test   cx,cx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_16);
x86_l_699:
	/* 0x699: je     7f9 <tail_handle_nat_fwd_ipv6+0x7f9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x699, 0x7f9, x86_l_7f9);
x86_l_69f:
	/* 0x69f: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_6a2:
	/* 0x6a2: mov    rdx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6a6:
	/* 0x6a6: mov    QWORD PTR [rsp+0x88],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_6ae:
	/* 0x6ae: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6b1:
	/* 0x6b1: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_6b9:
	/* 0x6b9: mov    WORD PTR [rsp+0x90],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_6c1:
	/* 0x6c1: jmp    88a <tail_handle_nat_fwd_ipv6+0x88a> */
	X86_SIM_X86_JMP(0x6c1, 0x88a, x86_l_88a);
x86_l_6c6:
	/* 0x6c6: mov    r12d,0x87 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 135ULL);
x86_l_6cc:
	/* 0x6cc: mov    QWORD PTR [rbp+0x0],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6d0:
	/* 0x6d0: mov    r15d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_6d5:
	/* 0x6d5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6d7:
	/* 0x6d7: mov    DWORD PTR [rbx+0x30],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_6db:
	/* 0x6db: mov    DWORD PTR [rbx+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_6e2:
	/* 0x6e2: or     eax,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R12, X86_WIDTH_32, X86_ALU_OR);
x86_l_6e5:
	/* 0x6e5: mov    DWORD PTR [rbx+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_6e8:
	/* 0x6e8: movabs rax,0x118710200000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 78937246882856960ULL);
x86_l_6f2:
	/* 0x6f2: mov    QWORD PTR [rbx+0x3c],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_6f6:
	/* 0x6f6: mov    r14d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6f9:
	/* 0x6f9: movabs rax,0x7101180200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 485349655040ULL);
x86_l_703:
	/* 0x703: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_708:
	/* 0x708: mov    BYTE PTR [rsp+0x50],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_70d:
	/* 0x70d: mov    rdi,QWORD PTR [rip+0xd037] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_714:
	/* 0x714: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_719:
	/* 0x719: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_71e:
	/* 0x71e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_720:
	/* 0x720: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_723:
	/* 0x723: je     72e <tail_handle_nat_fwd_ipv6+0x72e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x723, 0x72e, x86_l_72e);
x86_l_725:
	/* 0x725: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_728:
	/* 0x728: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_72c:
	/* 0x72c: jmp    756 <tail_handle_nat_fwd_ipv6+0x756> */
	X86_SIM_X86_JMP(0x72c, 0x756, x86_l_756);
x86_l_72e:
	/* 0x72e: mov    QWORD PTR [rsp+0x18],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215105ULL);
x86_l_737:
	/* 0x737: mov    QWORD PTR [rsp+0x20],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_73c:
	/* 0x73c: mov    rdi,QWORD PTR [rip+0xd037] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_743:
	/* 0x743: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_748:
	/* 0x748: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_74d:
	/* 0x74d: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_752:
	/* 0x752: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_754:
	/* 0x754: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_756:
	/* 0x756: mov    rsi,QWORD PTR [rip+0xd037] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_75d:
	/* 0x75d: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_762:
	/* 0x762: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_765:
	/* 0x765: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_76a:
	/* 0x76a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_76c:
	/* 0x76c: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_771:
	/* 0x771: add    rsp,0x98 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 152ULL);
x86_l_778:
	/* 0x778: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_77a:
	/* 0x77a: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_77b:
	/* 0x77b: jmp    10ad <tail_handle_nat_fwd_ipv6+0x10ad> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_780:
	/* 0x780: movzx  eax,WORD PTR [rax+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_784:
	/* 0x784: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_787:
	/* 0x787: je     100d <tail_handle_nat_fwd_ipv6+0x100d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x787, 0x100d, x86_l_100d);
x86_l_78d:
	/* 0x78d: mov    WORD PTR [rsp+0x18],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_792:
	/* 0x792: mov    rax,QWORD PTR [rip+0xd03a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_799:
	/* 0x799: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_79c:
	/* 0x79c: mov    r13,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDI, X86_WIDTH_64);
x86_l_79f:
	/* 0x79f: mov    rdi,QWORD PTR [rip+0xd03a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb6_reverse_nat)));
x86_l_7a6:
	/* 0x7a6: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_7ab:
	/* 0x7ab: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7b0:
	/* 0x7b0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7b2:
	/* 0x7b2: mov    r8,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7b7:
	/* 0x7b7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7ba:
	/* 0x7ba: je     100d <tail_handle_nat_fwd_ipv6+0x100d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7ba, 0x100d, x86_l_100d);
x86_l_7c0:
	/* 0x7c0: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_7c3:
	/* 0x7c3: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_7c6:
	/* 0x7c6: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7ca:
	/* 0x7ca: mov    QWORD PTR [rsp+0x88],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_7d2:
	/* 0x7d2: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7d5:
	/* 0x7d5: mov    QWORD PTR [rsp+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_7dd:
	/* 0x7dd: movzx  eax,WORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_7e1:
	/* 0x7e1: mov    WORD PTR [rsp+0x90],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_7e9:
	/* 0x7e9: jmp    88a <tail_handle_nat_fwd_ipv6+0x88a> */
	X86_SIM_X86_JMP(0x7e9, 0x88a, x86_l_88a);
x86_l_7ee:
	/* 0x7ee: mov    r12d,0x87 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 135ULL);
x86_l_7f4:
	/* 0x7f4: jmp    6d5 <tail_handle_nat_fwd_ipv6+0x6d5> */
	X86_SIM_X86_JMP(0x7f4, 0x6d5, x86_l_6d5);
x86_l_7f9:
	/* 0x7f9: mov    r13,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDI, X86_WIDTH_64);
x86_l_7fc:
	/* 0x7fc: mov    rax,QWORD PTR [rsp+0x6d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 109ULL);
x86_l_801:
	/* 0x801: mov    QWORD PTR [rsp+0x35],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 53ULL);
x86_l_806:
	/* 0x806: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_80b:
	/* 0x80b: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_810:
	/* 0x810: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_815:
	/* 0x815: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_81a:
	/* 0x81a: mov    rax,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_81f:
	/* 0x81f: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_824:
	/* 0x824: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_829:
	/* 0x829: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_82e:
	/* 0x82e: mov    BYTE PTR [rsp+0x3d],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 261993005056ULL);
x86_l_833:
	/* 0x833: rorx   eax,DWORD PTR [rsp+0x70],0x10 */
	X86_SIM_RUN_OP(X86_OP_RORX_MEM, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 481036337168ULL);
x86_l_83b:
	/* 0x83b: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_83f:
	/* 0x83f: mov    rdi,QWORD PTR [rip+0xd03a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v6_external)));
x86_l_846:
	/* 0x846: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_84b:
	/* 0x84b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_850:
	/* 0x850: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_852:
	/* 0x852: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_855:
	/* 0x855: je     100d <tail_handle_nat_fwd_ipv6+0x100d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x855, 0x100d, x86_l_100d);
x86_l_85b:
	/* 0x85b: mov    rcx,QWORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_85f:
	/* 0x85f: mov    QWORD PTR [rsp+0x88],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_867:
	/* 0x867: mov    rcx,QWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_86b:
	/* 0x86b: mov    QWORD PTR [rsp+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_873:
	/* 0x873: movzx  eax,WORD PTR [rax+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_877:
	/* 0x877: mov    WORD PTR [rsp+0x90],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_87f:
	/* 0x87f: mov    r8,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_884:
	/* 0x884: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_887:
	/* 0x887: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_88a:
	/* 0x88a: mov    rax,QWORD PTR [rip+0xd03a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_891:
	/* 0x891: movzx  r13d,BYTE PTR [rsp+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 116ULL);
x86_l_897:
	/* 0x897: cmp    r13b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_8, 6ULL);
x86_l_89b:
	/* 0x89b: jne    8a6 <tail_handle_nat_fwd_ipv6+0x8a6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x89b, 0x8a6, x86_l_8a6);
x86_l_89d:
	/* 0x89d: mov    rbp,QWORD PTR [rip+0xd03a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBP, (void *)(long)(((__u64)(long)&cilium_ct6_global)));
x86_l_8a4:
	/* 0x8a4: jmp    8ad <tail_handle_nat_fwd_ipv6+0x8ad> */
	X86_SIM_X86_JMP(0x8a4, 0x8ad, x86_l_8ad);
x86_l_8a6:
	/* 0x8a6: mov    rbp,QWORD PTR [rip+0xd03a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBP, (void *)(long)(((__u64)(long)&cilium_ct_any6_global)));
x86_l_8ad:
	/* 0x8ad: mov    DWORD PTR [rsp+0x4],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_8b2:
	/* 0x8b2: mov    BYTE PTR [rsp+0x75],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 502511173632ULL);
x86_l_8b7:
	/* 0x8b7: mov    DWORD PTR [rsp+0x7c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_8bf:
	/* 0x8bf: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8c2:
	/* 0x8c2: je     95b <tail_handle_nat_fwd_ipv6+0x95b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8c2, 0x95b, x86_l_95b);
x86_l_8c8:
	/* 0x8c8: movabs rax,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 1099511627776ULL);
x86_l_8d2:
	/* 0x8d2: and    rax,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R8, X86_WIDTH_64, X86_ALU_AND);
x86_l_8d5:
	/* 0x8d5: je     95b <tail_handle_nat_fwd_ipv6+0x95b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8d5, 0x95b, x86_l_95b);
x86_l_8db:
	/* 0x8db: mov    r15,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDI, X86_WIDTH_64);
x86_l_8de:
	/* 0x8de: mov    r14d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8e1:
	/* 0x8e1: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_8ea:
	/* 0x8ea: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_8f3:
	/* 0x8f3: movabs rax,0x6c02a30109 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 463900705033ULL);
x86_l_8fd:
	/* 0x8fd: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_902:
	/* 0x902: mov    rdi,QWORD PTR [rip+0xd03a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_909:
	/* 0x909: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_90e:
	/* 0x90e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_913:
	/* 0x913: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_915:
	/* 0x915: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_918:
	/* 0x918: je     923 <tail_handle_nat_fwd_ipv6+0x923> */
	X86_SIM_X86_JCC(X86_CC_E, 0x918, 0x923, x86_l_923);
x86_l_91a:
	/* 0x91a: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_91d:
	/* 0x91d: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_921:
	/* 0x921: jmp    94b <tail_handle_nat_fwd_ipv6+0x94b> */
	X86_SIM_X86_JMP(0x921, 0x94b, x86_l_94b);
x86_l_923:
	/* 0x923: mov    QWORD PTR [rsp+0x18],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215105ULL);
x86_l_92c:
	/* 0x92c: mov    QWORD PTR [rsp+0x20],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_931:
	/* 0x931: mov    rdi,QWORD PTR [rip+0xd03a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_938:
	/* 0x938: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_93d:
	/* 0x93d: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_942:
	/* 0x942: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_947:
	/* 0x947: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_949:
	/* 0x949: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_94b:
	/* 0x94b: mov    r14d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_950:
	/* 0x950: mov    r8,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_955:
	/* 0x955: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_958:
	/* 0x958: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_95b:
	/* 0x95b: cmp    r13b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_8, 6ULL);
x86_l_95f:
	/* 0x95f: jne    9b2 <tail_handle_nat_fwd_ipv6+0x9b2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x95f, 0x9b2, x86_l_9b2);
x86_l_961:
	/* 0x961: mov    rax,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R8, X86_WIDTH_64);
x86_l_964:
	/* 0x964: and    rax,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_64, X86_ALU_AND);
x86_l_967:
	/* 0x967: jne    9b2 <tail_handle_nat_fwd_ipv6+0x9b2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x967, 0x9b2, x86_l_9b2);
x86_l_969:
	/* 0x969: add    esi,0x1a */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 26ULL);
x86_l_96c:
	/* 0x96c: lea    rdx,[rsp+0x7c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_971:
	/* 0x971: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_976:
	/* 0x976: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_979:
	/* 0x979: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_97e:
	/* 0x97e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_980:
	/* 0x980: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_982:
	/* 0x982: js     1008 <tail_handle_nat_fwd_ipv6+0x1008> */
	X86_SIM_X86_JCC(X86_CC_S, 0x982, 0x1008, x86_l_1008);
x86_l_988:
	/* 0x988: mov    r12d,DWORD PTR [rsp+0x7c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_98d:
	/* 0x98d: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_990:
	/* 0x990: and    eax,0x1200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4608ULL);
x86_l_995:
	/* 0x995: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_998:
	/* 0x998: cmp    eax,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 512ULL);
x86_l_99d:
	/* 0x99d: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_9a0:
	/* 0x9a0: test   r12d,0x500 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R12, X86_WIDTH_32, 1280ULL);
x86_l_9a7:
	/* 0x9a7: jne    f2c <tail_handle_nat_fwd_ipv6+0xf2c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x9a7, 0xf2c, x86_l_f2c);
x86_l_9ad:
	/* 0x9ad: mov    r15b,al */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_8);
x86_l_9b0:
	/* 0x9b0: jmp    9ba <tail_handle_nat_fwd_ipv6+0x9ba> */
	X86_SIM_X86_JMP(0x9b0, 0x9ba, x86_l_9ba);
x86_l_9b2:
	/* 0x9b2: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9b5:
	/* 0x9b5: mov    r12d,DWORD PTR [rsp+0x7c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_9ba:
	/* 0x9ba: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_9bf:
	/* 0x9bf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_9c4:
	/* 0x9c4: mov    rdi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_64);
x86_l_9c7:
	/* 0x9c7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9c9:
	/* 0x9c9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9cc:
	/* 0x9cc: mov    rsi,QWORD PTR [rip+0xd03a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_9d3:
	/* 0x9d3: je     1006 <tail_handle_nat_fwd_ipv6+0x1006> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9d3, 0x1006, x86_l_1006);
x86_l_9d9:
	/* 0x9d9: movzx  ecx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_9dd:
	/* 0x9dd: test   cl,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_9e0:
	/* 0x9e0: jne    9eb <tail_handle_nat_fwd_ipv6+0x9eb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x9e0, 0x9eb, x86_l_9eb);
x86_l_9e2:
	/* 0x9e2: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_9e4:
	/* 0x9e4: js     9fd <tail_handle_nat_fwd_ipv6+0x9fd> */
	X86_SIM_X86_JCC(X86_CC_S, 0x9e4, 0x9fd, x86_l_9fd);
x86_l_9e6:
	/* 0x9e6: jmp    1006 <tail_handle_nat_fwd_ipv6+0x1006> */
	X86_SIM_X86_JMP(0x9e6, 0x1006, x86_l_1006);
x86_l_9eb:
	/* 0x9eb: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_9ed:
	/* 0x9ed: and    edx,0x80 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 128ULL);
x86_l_9f3:
	/* 0x9f3: or     dx,WORD PTR [rax+0x26] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RAX, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 38ULL);
x86_l_9f7:
	/* 0x9f7: je     1006 <tail_handle_nat_fwd_ipv6+0x1006> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9f7, 0x1006, x86_l_1006);
x86_l_9fd:
	/* 0x9fd: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_9ff:
	/* 0x9ff: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_a01:
	/* 0xa01: test   dl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_8, 3ULL);
x86_l_a04:
	/* 0xa04: je     b17 <tail_handle_nat_fwd_ipv6+0xb17> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa04, 0xb17, x86_l_b17);
x86_l_a0a:
	/* 0xa0a: mov    DWORD PTR [rsp+0xc],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_a0f:
	/* 0xa0f: mov    rsi,QWORD PTR [rip+0xd03a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_a16:
	/* 0xa16: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a19:
	/* 0xa19: je     a33 <tail_handle_nat_fwd_ipv6+0xa33> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa19, 0xa33, x86_l_a33);
x86_l_a1b:
	/* 0xa1b: mov    rdx,QWORD PTR [rip+0xd03a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_a22:
	/* 0xa22: imul   r12d,DWORD PTR [rdx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R12, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_a26:
	/* 0xa26: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_a2a:
	/* 0xa2a: jmp    a39 <tail_handle_nat_fwd_ipv6+0xa39> */
	X86_SIM_X86_JMP(0xa2a, 0xa39, x86_l_a39);
x86_l_a2c:
	/* 0xa2c: mov    ebp,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RSI, X86_WIDTH_32);
x86_l_a2e:
	/* 0xa2e: jmp    53c <tail_handle_nat_fwd_ipv6+0x53c> */
	X86_SIM_X86_JMP(0xa2e, 0x53c, x86_l_53c);
x86_l_a33:
	/* 0xa33: mov    r12d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 60ULL);
x86_l_a39:
	/* 0xa39: cmp    r13b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_8, 6ULL);
x86_l_a3d:
	/* 0xa3d: jne    a77 <tail_handle_nat_fwd_ipv6+0xa77> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa3d, 0xa77, x86_l_a77);
x86_l_a3f:
	/* 0xa3f: mov    edx,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_a43:
	/* 0xa43: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_a45:
	/* 0xa45: shr    edx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_a48:
	/* 0xa48: and    edx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_a4b:
	/* 0xa4b: or     edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_a4d:
	/* 0xa4d: mov    WORD PTR [rax+0x24],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_a51:
	/* 0xa51: test   dl,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_8, 16ULL);
x86_l_a54:
	/* 0xa54: mov    ecx,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 60ULL);
x86_l_a59:
	/* 0xa59: mov    r12d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 21600ULL);
x86_l_a5f:
	/* 0xa5f: cmove  r12d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RCX, X86_WIDTH_32, X86_CC_E);
x86_l_a63:
	/* 0xa63: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a66:
	/* 0xa66: je     a77 <tail_handle_nat_fwd_ipv6+0xa77> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa66, 0xa77, x86_l_a77);
x86_l_a68:
	/* 0xa68: mov    rcx,QWORD PTR [rip+0xd03a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_a6f:
	/* 0xa6f: imul   r12d,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_a73:
	/* 0xa73: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_a77:
	/* 0xa77: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_a7a:
	/* 0xa7a: mov    ebp,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_a7e:
	/* 0xa7e: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_a81:
	/* 0xa81: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a84:
	/* 0xa84: je     a98 <tail_handle_nat_fwd_ipv6+0xa98> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa84, 0xa98, x86_l_a98);
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
	/* 0xa8f: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_a92:
	/* 0xa92: shr    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_a96:
	/* 0xa96: jmp    abb <tail_handle_nat_fwd_ipv6+0xabb> */
	X86_SIM_X86_JMP(0xa96, 0xabb, x86_l_abb);
x86_l_a98:
	/* 0xa98: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_a9d:
	/* 0xa9d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a9f:
	/* 0xa9f: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_aa1:
	/* 0xaa1: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_aa5:
	/* 0xaa5: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_aaf:
	/* 0xaaf: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_ab2:
	/* 0xab2: mulx   rcx,rcx,rcx */
	X86_SIM_L_EXEC_MULX(X86_RCX, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_ab7:
	/* 0xab7: shr    rcx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_abb:
	/* 0xabb: add    r12d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_abe:
	/* 0xabe: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_ac1:
	/* 0xac1: mov    DWORD PTR [r14+0x20],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ac5:
	/* 0xac5: movzx  edx,BYTE PTR [r14+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_aca:
	/* 0xaca: mov    esi,DWORD PTR [r14+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_ace:
	/* 0xace: and    bpl,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_ad2:
	/* 0xad2: mov    rdi,QWORD PTR [rip+0xd03a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_ad9:
	/* 0xad9: cmp    BYTE PTR [rdi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_adc:
	/* 0xadc: je     aef <tail_handle_nat_fwd_ipv6+0xaef> */
	X86_SIM_X86_JCC(X86_CC_E, 0xadc, 0xaef, x86_l_aef);
x86_l_ade:
	/* 0xade: mov    rdi,QWORD PTR [rip+0xd03a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_ae5:
	/* 0xae5: mov    edi,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ae7:
	/* 0xae7: lea    edi,[rdi+rdi*4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_aea:
	/* 0xaea: shr    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_aed:
	/* 0xaed: jmp    af4 <tail_handle_nat_fwd_ipv6+0xaf4> */
	X86_SIM_X86_JMP(0xaed, 0xaf4, x86_l_af4);
x86_l_aef:
	/* 0xaef: mov    edi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 5ULL);
x86_l_af4:
	/* 0xaf4: mov    r12d,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_af9:
	/* 0xaf9: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_afb:
	/* 0xafb: or     bpl,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_afe:
	/* 0xafe: cmp    edi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RCX, X86_WIDTH_32);
x86_l_b00:
	/* 0xb00: jb     b07 <tail_handle_nat_fwd_ipv6+0xb07> */
	X86_SIM_X86_JCC(X86_CC_B, 0xb00, 0xb07, x86_l_b07);
x86_l_b02:
	/* 0xb02: cmp    dl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBP, X86_WIDTH_8);
x86_l_b05:
	/* 0xb05: je     b17 <tail_handle_nat_fwd_ipv6+0xb17> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb05, 0xb17, x86_l_b17);
x86_l_b07:
	/* 0xb07: mov    BYTE PTR [rax+0x2b],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_b0b:
	/* 0xb0b: mov    DWORD PTR [rax+0x34],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_b0e:
	/* 0xb0e: mov    rcx,QWORD PTR [rip+0xd03a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_b15:
	/* 0xb15: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b17:
	/* 0xb17: mov    rcx,QWORD PTR [rip+0xd03a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_b1e:
	/* 0xb1e: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b21:
	/* 0xb21: je     b2f <tail_handle_nat_fwd_ipv6+0xb2f> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb21, 0xb2f, x86_l_b2f);
x86_l_b23:
	/* 0xb23: inc QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 16ULL);
x86_l_b28:
	/* 0xb28: mov    ecx,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b2a:
	/* 0xb2a: add QWORD PTR [rax+0x18],rcx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_b2f:
	/* 0xb2f: cmp    r15d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 2ULL);
x86_l_b33:
	/* 0xb33: mov    rsi,QWORD PTR [rip+0xd03a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_b3a:
	/* 0xb3a: je     b8e <tail_handle_nat_fwd_ipv6+0xb8e> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb3a, 0xb8e, x86_l_b8e);
x86_l_b3c:
	/* 0xb3c: cmp    r15d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 1ULL);
x86_l_b40:
	/* 0xb40: mov    r15d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_b45:
	/* 0xb45: jne    c6b <tail_handle_nat_fwd_ipv6+0xc6b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb45, 0xc6b, x86_l_c6b);
x86_l_b4b:
	/* 0xb4b: movzx  ecx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_b4f:
	/* 0xb4f: test   cl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_b52:
	/* 0xb52: je     c6b <tail_handle_nat_fwd_ipv6+0xc6b> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb52, 0xc6b, x86_l_c6b);
x86_l_b58:
	/* 0xb58: mov    WORD PTR [rax+0x2a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 180388626432ULL);
x86_l_b5e:
	/* 0xb5e: and    ecx,0xffec */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 65516ULL);
x86_l_b64:
	/* 0xb64: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_b67:
	/* 0xb67: mov    WORD PTR [rax+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_b6b:
	/* 0xb6b: mov    r14,QWORD PTR [rip+0xd03a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_b72:
	/* 0xb72: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b76:
	/* 0xb76: je     f37 <tail_handle_nat_fwd_ipv6+0xf37> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb76, 0xf37, x86_l_f37);
x86_l_b7c:
	/* 0xb7c: mov    rax,QWORD PTR [rip+0xd03a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_b83:
	/* 0xb83: imul   ebp,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_b86:
	/* 0xb86: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_b89:
	/* 0xb89: jmp    f3c <tail_handle_nat_fwd_ipv6+0xf3c> */
	X86_SIM_X86_JMP(0xb89, 0xf3c, x86_l_f3c);
x86_l_b8e:
	/* 0xb8e: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_b91:
	/* 0xb91: shr    ecx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_b94:
	/* 0xb94: and    ecx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2ULL);
x86_l_b97:
	/* 0xb97: or     cx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RAX, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 36ULL);
x86_l_b9b:
	/* 0xb9b: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_b9d:
	/* 0xb9d: or     edx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_OR, 1ULL);
x86_l_ba0:
	/* 0xba0: mov    WORD PTR [rax+0x24],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_ba4:
	/* 0xba4: mov    edx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ba6:
	/* 0xba6: test   cl,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_ba9:
	/* 0xba9: mov    r15d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_bae:
	/* 0xbae: je     c6b <tail_handle_nat_fwd_ipv6+0xc6b> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbae, 0xc6b, x86_l_c6b);
x86_l_bb4:
	/* 0xbb4: mov    r15,QWORD PTR [rip+0xd03a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_bbb:
	/* 0xbbb: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bbf:
	/* 0xbbf: je     bd4 <tail_handle_nat_fwd_ipv6+0xbd4> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbbf, 0xbd4, x86_l_bd4);
x86_l_bc1:
	/* 0xbc1: mov    rcx,QWORD PTR [rip+0xd03a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_bc8:
	/* 0xbc8: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bca:
	/* 0xbca: add    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_bcc:
	/* 0xbcc: lea    ebp,[rcx+rcx*4] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 0ULL);
x86_l_bcf:
	/* 0xbcf: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_bd2:
	/* 0xbd2: jmp    bd9 <tail_handle_nat_fwd_ipv6+0xbd9> */
	X86_SIM_X86_JMP(0xbd2, 0xbd9, x86_l_bd9);
x86_l_bd4:
	/* 0xbd4: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_bd9:
	/* 0xbd9: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_bdc:
	/* 0xbdc: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_be0:
	/* 0xbe0: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_be4:
	/* 0xbe4: je     bf5 <tail_handle_nat_fwd_ipv6+0xbf5> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbe4, 0xbf5, x86_l_bf5);
x86_l_be6:
	/* 0xbe6: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_beb:
	/* 0xbeb: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bed:
	/* 0xbed: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_bef:
	/* 0xbef: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_bf3:
	/* 0xbf3: jmp    c18 <tail_handle_nat_fwd_ipv6+0xc18> */
	X86_SIM_X86_JMP(0xbf3, 0xc18, x86_l_c18);
x86_l_bf5:
	/* 0xbf5: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_bfa:
	/* 0xbfa: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bfc:
	/* 0xbfc: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_bfe:
	/* 0xbfe: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_c02:
	/* 0xc02: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_c0c:
	/* 0xc0c: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_c0f:
	/* 0xc0f: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_c14:
	/* 0xc14: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_c18:
	/* 0xc18: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_c1a:
	/* 0xc1a: mov    DWORD PTR [r14+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c1e:
	/* 0xc1e: movzx  ecx,BYTE PTR [r14+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_c23:
	/* 0xc23: mov    edx,DWORD PTR [r14+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_c27:
	/* 0xc27: and    r12b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_c2b:
	/* 0xc2b: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c2f:
	/* 0xc2f: je     c42 <tail_handle_nat_fwd_ipv6+0xc42> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc2f, 0xc42, x86_l_c42);
x86_l_c31:
	/* 0xc31: mov    rsi,QWORD PTR [rip+0xd03a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_c38:
	/* 0xc38: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c3a:
	/* 0xc3a: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_c3d:
	/* 0xc3d: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_c40:
	/* 0xc40: jmp    c47 <tail_handle_nat_fwd_ipv6+0xc47> */
	X86_SIM_X86_JMP(0xc40, 0xc47, x86_l_c47);
x86_l_c42:
	/* 0xc42: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_c47:
	/* 0xc47: mov    r15d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_c4c:
	/* 0xc4c: mov    rdi,QWORD PTR [rip+0xd03a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_c53:
	/* 0xc53: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_c55:
	/* 0xc55: or     r12b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_c58:
	/* 0xc58: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_c5a:
	/* 0xc5a: jb     c61 <tail_handle_nat_fwd_ipv6+0xc61> */
	X86_SIM_X86_JCC(X86_CC_B, 0xc5a, 0xc61, x86_l_c61);
x86_l_c5c:
	/* 0xc5c: cmp    cl,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R12, X86_WIDTH_8);
x86_l_c5f:
	/* 0xc5f: je     c6b <tail_handle_nat_fwd_ipv6+0xc6b> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc5f, 0xc6b, x86_l_c6b);
x86_l_c61:
	/* 0xc61: mov    BYTE PTR [r14+0x2b],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_c65:
	/* 0xc65: mov    DWORD PTR [r14+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_c69:
	/* 0xc69: mov    eax,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c6b:
	/* 0xc6b: test   BYTE PTR [rsp+0x75],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 502511173634ULL);
x86_l_c70:
	/* 0xc70: mov    r14d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c75:
	/* 0xc75: movabs rax,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2199023255552ULL);
x86_l_c7f:
	/* 0xc7f: jne    100d <tail_handle_nat_fwd_ipv6+0x100d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xc7f, 0x100d, x86_l_100d);
x86_l_c85:
	/* 0xc85: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_c88:
	/* 0xc88: mov    rax,QWORD PTR [rip+0xd03a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_c8f:
	/* 0xc8f: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_c92:
	/* 0xc92: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_c97:
	/* 0xc97: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_c9c:
	/* 0xc9c: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ca1:
	/* 0xca1: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ca6:
	/* 0xca6: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_cae:
	/* 0xcae: mov    rcx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_cb6:
	/* 0xcb6: mov    QWORD PTR [rsp+0x68],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_cbb:
	/* 0xcbb: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_cc0:
	/* 0xcc0: lea    rdx,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_cc8:
	/* 0xcc8: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_ccd:
	/* 0xccd: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_cd0:
	/* 0xcd0: mov    esi,0x16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 22ULL);
x86_l_cd5:
	/* 0xcd5: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_cda:
	/* 0xcda: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_cdd:
	/* 0xcdd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cdf:
	/* 0xcdf: mov    r12d,0x8d */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 141ULL);
x86_l_ce5:
	/* 0xce5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ce7:
	/* 0xce7: js     6d0 <tail_handle_nat_fwd_ipv6+0x6d0> */
	X86_SIM_X86_JCC(X86_CC_S, 0xce7, 0x6d0, x86_l_6d0);
x86_l_ced:
	/* 0xced: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_cf0:
	/* 0xcf0: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_cf5:
	/* 0xcf5: je     6d0 <tail_handle_nat_fwd_ipv6+0x6d0> */
	X86_SIM_X86_JCC(X86_CC_E, 0xcf5, 0x6d0, x86_l_6d0);
x86_l_cfb:
	/* 0xcfb: test   rax,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_cfe:
	/* 0xcfe: jne    103d <tail_handle_nat_fwd_ipv6+0x103d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xcfe, 0x103d, x86_l_103d);
x86_l_d04:
	/* 0xd04: movzx  eax,BYTE PTR [rsp+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 116ULL);
x86_l_d09:
	/* 0xd09: cmp    eax,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 58ULL);
x86_l_d0c:
	/* 0xd0c: je     d33 <tail_handle_nat_fwd_ipv6+0xd33> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd0c, 0xd33, x86_l_d33);
x86_l_d0e:
	/* 0xd0e: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_d11:
	/* 0xd11: je     d23 <tail_handle_nat_fwd_ipv6+0xd23> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd11, 0xd23, x86_l_d23);
x86_l_d13:
	/* 0xd13: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_d16:
	/* 0xd16: jne    d3e <tail_handle_nat_fwd_ipv6+0xd3e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xd16, 0xd3e, x86_l_d3e);
x86_l_d18:
	/* 0xd18: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d1b:
	/* 0xd1b: mov    r15d,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 16ULL);
x86_l_d21:
	/* 0xd21: jmp    d44 <tail_handle_nat_fwd_ipv6+0xd44> */
	X86_SIM_X86_JMP(0xd21, 0xd44, x86_l_d44);
x86_l_d23:
	/* 0xd23: mov    ebp,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 32ULL);
x86_l_d28:
	/* 0xd28: mov    r15d,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 6ULL);
x86_l_d2e:
	/* 0xd2e: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d31:
	/* 0xd31: jmp    d46 <tail_handle_nat_fwd_ipv6+0xd46> */
	X86_SIM_X86_JMP(0xd31, 0xd46, x86_l_d46);
x86_l_d33:
	/* 0xd33: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d36:
	/* 0xd36: mov    r15d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 2ULL);
x86_l_d3c:
	/* 0xd3c: jmp    d44 <tail_handle_nat_fwd_ipv6+0xd44> */
	X86_SIM_X86_JMP(0xd3c, 0xd44, x86_l_d44);
x86_l_d3e:
	/* 0xd3e: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d41:
	/* 0xd41: mov    r14b,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_8, 1ULL);
x86_l_d44:
	/* 0xd44: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d46:
	/* 0xd46: movzx  ecx,WORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 144ULL);
x86_l_d4e:
	/* 0xd4e: test   cx,cx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_16);
x86_l_d51:
	/* 0xd51: je     dd8 <tail_handle_nat_fwd_ipv6+0xdd8> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd51, 0xdd8, x86_l_dd8);
x86_l_d57:
	/* 0xd57: movzx  r13d,WORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 112ULL);
x86_l_d5d:
	/* 0xd5d: mov    r12d,0x8e */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 142ULL);
x86_l_d63:
	/* 0xd63: cmp    eax,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_d66:
	/* 0xd66: jg     d77 <tail_handle_nat_fwd_ipv6+0xd77> */
	X86_SIM_X86_JCC(X86_CC_G, 0xd66, 0xd77, x86_l_d77);
x86_l_d68:
	/* 0xd68: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d6b:
	/* 0xd6b: je     dd8 <tail_handle_nat_fwd_ipv6+0xdd8> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd6b, 0xdd8, x86_l_dd8);
x86_l_d6d:
	/* 0xd6d: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_d70:
	/* 0xd70: je     d85 <tail_handle_nat_fwd_ipv6+0xd85> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd70, 0xd85, x86_l_d85);
x86_l_d72:
	/* 0xd72: jmp    6d0 <tail_handle_nat_fwd_ipv6+0x6d0> */
	X86_SIM_X86_JMP(0xd72, 0x6d0, x86_l_6d0);
x86_l_d77:
	/* 0xd77: cmp    eax,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 58ULL);
x86_l_d7a:
	/* 0xd7a: je     dd8 <tail_handle_nat_fwd_ipv6+0xdd8> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd7a, 0xdd8, x86_l_dd8);
x86_l_d7c:
	/* 0xd7c: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_d7f:
	/* 0xd7f: jne    6d0 <tail_handle_nat_fwd_ipv6+0x6d0> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xd7f, 0x6d0, x86_l_6d0);
x86_l_d85:
	/* 0xd85: cmp    cx,r13w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R13, X86_WIDTH_16);
x86_l_d89:
	/* 0xd89: je     dd8 <tail_handle_nat_fwd_ipv6+0xdd8> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd89, 0xdd8, x86_l_dd8);
x86_l_d8b:
	/* 0xd8b: mov    WORD PTR [rsp+0x48],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_d90:
	/* 0xd90: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_d95:
	/* 0xd95: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_d9a:
	/* 0xd9a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_d9d:
	/* 0xd9d: mov    r12,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_da2:
	/* 0xda2: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_da5:
	/* 0xda5: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_daa:
	/* 0xdaa: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_dad:
	/* 0xdad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_daf:
	/* 0xdaf: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_db1:
	/* 0xdb1: js     e53 <tail_handle_nat_fwd_ipv6+0xe53> */
	X86_SIM_X86_JCC(X86_CC_S, 0xdb1, 0xe53, x86_l_e53);
x86_l_db7:
	/* 0xdb7: movzx  ecx,WORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 72ULL);
x86_l_dbc:
	/* 0xdbc: lea    esi,[r15+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_dc0:
	/* 0xdc0: mov    r8d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RBP, X86_WIDTH_32);
x86_l_dc3:
	/* 0xdc3: or     r8d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_dc7:
	/* 0xdc7: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_dcc:
	/* 0xdcc: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_dcf:
	/* 0xdcf: mov    edx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_32);
x86_l_dd2:
	/* 0xdd2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dd4:
	/* 0xdd4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_dd6:
	/* 0xdd6: js     e48 <tail_handle_nat_fwd_ipv6+0xe48> */
	X86_SIM_X86_JCC(X86_CC_S, 0xdd6, 0xe48, x86_l_e48);
x86_l_dd8:
	/* 0xdd8: test   r14b,r14b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_8);
x86_l_ddb:
	/* 0xddb: jne    103d <tail_handle_nat_fwd_ipv6+0x103d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xddb, 0x103d, x86_l_103d);
x86_l_de1:
	/* 0xde1: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_de6:
	/* 0xde6: lea    rdx,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_dee:
	/* 0xdee: mov    eax,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_df3:
	/* 0xdf3: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_df8:
	/* 0xdf8: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_dfd:
	/* 0xdfd: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e00:
	/* 0xe00: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e02:
	/* 0xe02: mov    r13d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_e05:
	/* 0xe05: add    r15d,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 64ULL);
x86_l_e0a:
	/* 0xe0a: mov    r8d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RBP, X86_WIDTH_32);
x86_l_e0d:
	/* 0xe0d: or     r8d,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 144ULL);
x86_l_e14:
	/* 0xe14: mov    r14d,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 11ULL);
x86_l_e1a:
	/* 0xe1a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_e1d:
	/* 0xe1d: mov    esi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_e20:
	/* 0xe20: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e22:
	/* 0xe22: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_e24:
	/* 0xe24: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_e27:
	/* 0xe27: cmp    eax,0xffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967274ULL);
x86_l_e2a:
	/* 0xe2a: jne    e40 <tail_handle_nat_fwd_ipv6+0xe40> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe2a, 0xe40, x86_l_e40);
x86_l_e2c:
	/* 0xe2c: or     ebp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_OR, 16ULL);
x86_l_e2f:
	/* 0xe2f: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_e32:
	/* 0xe32: mov    esi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_e35:
	/* 0xe35: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e37:
	/* 0xe37: mov    ecx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_32);
x86_l_e3a:
	/* 0xe3a: mov    r8d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RBP, X86_WIDTH_32);
x86_l_e3d:
	/* 0xe3d: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_e40:
	/* 0xe40: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_e42:
	/* 0xe42: jns    103d <tail_handle_nat_fwd_ipv6+0x103d> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xe42, 0x103d, x86_l_103d);
x86_l_e48:
	/* 0xe48: mov    r12d,0x9a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 154ULL);
x86_l_e4e:
	/* 0xe4e: jmp    6d0 <tail_handle_nat_fwd_ipv6+0x6d0> */
	X86_SIM_X86_JMP(0xe4e, 0x6d0, x86_l_6d0);
x86_l_e53:
	/* 0xe53: mov    r12d,0x8d */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 141ULL);
x86_l_e59:
	/* 0xe59: jmp    6d0 <tail_handle_nat_fwd_ipv6+0x6d0> */
	X86_SIM_X86_JMP(0xe59, 0x6d0, x86_l_6d0);
x86_l_e5e:
	/* 0xe5e: mov    rdi,QWORD PTR [rip+0xd03a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv6_frag_datagrams)));
x86_l_e65:
	/* 0xe65: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e6a:
	/* 0xe6a: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_e6d:
	/* 0xe6d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e6f:
	/* 0xe6f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e72:
	/* 0xe72: je     ef4 <tail_handle_nat_fwd_ipv6+0xef4> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe72, 0xef4, x86_l_ef4);
x86_l_e78:
	/* 0xe78: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e7a:
	/* 0xe7a: mov    DWORD PTR [rsp+0x70],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_e7e:
	/* 0xe7e: jmp    604 <tail_handle_nat_fwd_ipv6+0x604> */
	X86_SIM_X86_JMP(0xe7e, 0x604, x86_l_604);
x86_l_e83:
	/* 0xe83: mov    rdi,QWORD PTR [rip+0xd036] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv6_frag_datagrams)));
x86_l_e8a:
	/* 0xe8a: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_e8f:
	/* 0xe8f: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_e92:
	/* 0xe92: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_e95:
	/* 0xe95: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e97:
	/* 0xe97: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e99:
	/* 0xe99: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_e9b:
	/* 0xe9b: je     604 <tail_handle_nat_fwd_ipv6+0x604> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe9b, 0x604, x86_l_604);
x86_l_ea1:
	/* 0xea1: mov    r14d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ea4:
	/* 0xea4: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_ead:
	/* 0xead: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_eb6:
	/* 0xeb6: movabs rax,0x7201a9020a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 489654125066ULL);
x86_l_ec0:
	/* 0xec0: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_ec5:
	/* 0xec5: mov    rdi,QWORD PTR [rip+0xd036] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_ecc:
	/* 0xecc: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_ed1:
	/* 0xed1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ed6:
	/* 0xed6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ed8:
	/* 0xed8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_edb:
	/* 0xedb: je     eff <tail_handle_nat_fwd_ipv6+0xeff> */
	X86_SIM_X86_JCC(X86_CC_E, 0xedb, 0xeff, x86_l_eff);
x86_l_edd:
	/* 0xedd: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_ee0:
	/* 0xee0: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_ee4:
	/* 0xee4: jmp    604 <tail_handle_nat_fwd_ipv6+0x604> */
	X86_SIM_X86_JMP(0xee4, 0x604, x86_l_604);
x86_l_ee9:
	/* 0xee9: mov    r12d,0x9d */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 157ULL);
x86_l_eef:
	/* 0xeef: jmp    6d5 <tail_handle_nat_fwd_ipv6+0x6d5> */
	X86_SIM_X86_JMP(0xeef, 0x6d5, x86_l_6d5);
x86_l_ef4:
	/* 0xef4: mov    r12d,0xaf */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 175ULL);
x86_l_efa:
	/* 0xefa: jmp    6cc <tail_handle_nat_fwd_ipv6+0x6cc> */
	X86_SIM_X86_JMP(0xefa, 0x6cc, x86_l_6cc);
x86_l_eff:
	/* 0xeff: mov    QWORD PTR [rsp+0x18],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215105ULL);
x86_l_f08:
	/* 0xf08: mov    QWORD PTR [rsp+0x20],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f0d:
	/* 0xf0d: mov    rdi,QWORD PTR [rip+0xd036] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_f14:
	/* 0xf14: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_f19:
	/* 0xf19: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_f1e:
	/* 0xf1e: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_f23:
	/* 0xf23: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f25:
	/* 0xf25: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f27:
	/* 0xf27: jmp    604 <tail_handle_nat_fwd_ipv6+0x604> */
	X86_SIM_X86_JMP(0xf27, 0x604, x86_l_604);
x86_l_f2c:
	/* 0xf2c: mov    r15d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 2ULL);
x86_l_f32:
	/* 0xf32: jmp    9ba <tail_handle_nat_fwd_ipv6+0x9ba> */
	X86_SIM_X86_JMP(0xf32, 0x9ba, x86_l_9ba);
x86_l_f37:
	/* 0xf37: mov    ebp,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_f3c:
	/* 0xf3c: cmp    r13b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_8, 6ULL);
x86_l_f40:
	/* 0xf40: jne    f76 <tail_handle_nat_fwd_ipv6+0xf76> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf40, 0xf76, x86_l_f76);
x86_l_f42:
	/* 0xf42: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_f45:
	/* 0xf45: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_f47:
	/* 0xf47: shr    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_f4a:
	/* 0xf4a: and    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_f4d:
	/* 0xf4d: or     ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_OR);
x86_l_f4f:
	/* 0xf4f: mov    WORD PTR [r15+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_f54:
	/* 0xf54: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_f56:
	/* 0xf56: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_f5b:
	/* 0xf5b: mov    ebp,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 21600ULL);
x86_l_f60:
	/* 0xf60: cmove  ebp,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_f63:
	/* 0xf63: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f67:
	/* 0xf67: je     f76 <tail_handle_nat_fwd_ipv6+0xf76> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf67, 0xf76, x86_l_f76);
x86_l_f69:
	/* 0xf69: mov    rax,QWORD PTR [rip+0xd036] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_f70:
	/* 0xf70: imul   ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_f73:
	/* 0xf73: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_f76:
	/* 0xf76: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_f7a:
	/* 0xf7a: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f7e:
	/* 0xf7e: je     f8f <tail_handle_nat_fwd_ipv6+0xf8f> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf7e, 0xf8f, x86_l_f8f);
x86_l_f80:
	/* 0xf80: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_f85:
	/* 0xf85: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f87:
	/* 0xf87: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_f89:
	/* 0xf89: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_f8d:
	/* 0xf8d: jmp    fb2 <tail_handle_nat_fwd_ipv6+0xfb2> */
	X86_SIM_X86_JMP(0xf8d, 0xfb2, x86_l_fb2);
x86_l_f8f:
	/* 0xf8f: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_f94:
	/* 0xf94: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f96:
	/* 0xf96: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_f98:
	/* 0xf98: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_f9c:
	/* 0xf9c: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_fa6:
	/* 0xfa6: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_fa9:
	/* 0xfa9: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_fae:
	/* 0xfae: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_fb2:
	/* 0xfb2: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_fb4:
	/* 0xfb4: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_fb7:
	/* 0xfb7: mov    DWORD PTR [r15+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_fbb:
	/* 0xfbb: movzx  ecx,BYTE PTR [r15+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_fc0:
	/* 0xfc0: mov    edx,DWORD PTR [r15+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_fc4:
	/* 0xfc4: and    r12b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_fc8:
	/* 0xfc8: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fcc:
	/* 0xfcc: je     fdf <tail_handle_nat_fwd_ipv6+0xfdf> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfcc, 0xfdf, x86_l_fdf);
x86_l_fce:
	/* 0xfce: mov    rsi,QWORD PTR [rip+0xd036] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_fd5:
	/* 0xfd5: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fd7:
	/* 0xfd7: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_fda:
	/* 0xfda: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_fdd:
	/* 0xfdd: jmp    fe4 <tail_handle_nat_fwd_ipv6+0xfe4> */
	X86_SIM_X86_JMP(0xfdd, 0xfe4, x86_l_fe4);
x86_l_fdf:
	/* 0xfdf: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_fe4:
	/* 0xfe4: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_fe6:
	/* 0xfe6: or     r12b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_fe9:
	/* 0xfe9: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_feb:
	/* 0xfeb: mov    r14d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ff0:
	/* 0xff0: jb     ff7 <tail_handle_nat_fwd_ipv6+0xff7> */
	X86_SIM_X86_JCC(X86_CC_B, 0xff0, 0xff7, x86_l_ff7);
x86_l_ff2:
	/* 0xff2: cmp    cl,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R12, X86_WIDTH_8);
x86_l_ff5:
	/* 0xff5: je     1008 <tail_handle_nat_fwd_ipv6+0x1008> */
	X86_SIM_X86_JCC(X86_CC_E, 0xff5, 0x1008, x86_l_1008);
x86_l_ff7:
	/* 0xff7: mov    BYTE PTR [r15+0x2b],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_ffb:
	/* 0xffb: mov    DWORD PTR [r15+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_fff:
	/* 0xfff: mov    rsi,QWORD PTR [rip+0xd036] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_1006:
	/* 0x1006: mov    eax,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1008:
	/* 0x1008: mov    r15d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_100d:
	/* 0x100d: test   r14b,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R14, X86_WIDTH_8, 1ULL);
x86_l_1011:
	/* 0x1011: jne    103d <tail_handle_nat_fwd_ipv6+0x103d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1011, 0x103d, x86_l_103d);
x86_l_1013:
	/* 0x1013: mov    DWORD PTR [rbx+0x30],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1017:
	/* 0x1017: mov    rsi,QWORD PTR [rip+0xd036] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_101e:
	/* 0x101e: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1023:
	/* 0x1023: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1026:
	/* 0x1026: mov    edx,0x27 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 39ULL);
x86_l_102b:
	/* 0x102b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_102d:
	/* 0x102d: mov    eax,0x2700 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9984ULL);
x86_l_1032:
	/* 0x1032: mov    r12d,0x8c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 140ULL);
x86_l_1038:
	/* 0x1038: jmp    6d7 <tail_handle_nat_fwd_ipv6+0x6d7> */
	X86_SIM_X86_JMP(0x1038, 0x6d7, x86_l_6d7);
x86_l_103d:
	/* 0x103d: mov    rax,QWORD PTR [rip+0xd036] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_interface_ifindex)));
x86_l_1044:
	/* 0x1044: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1046:
	/* 0x1046: mov    ebx,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1048:
	/* 0x1048: movabs rax,0x7101180200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 485349655040ULL);
x86_l_1052:
	/* 0x1052: or     rax,0x50000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_OR, 327680ULL);
x86_l_1058:
	/* 0x1058: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_105d:
	/* 0x105d: mov    rdi,QWORD PTR [rip+0xd036] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1064:
	/* 0x1064: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1069:
	/* 0x1069: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_106e:
	/* 0x106e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1070:
	/* 0x1070: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1073:
	/* 0x1073: je     107e <tail_handle_nat_fwd_ipv6+0x107e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1073, 0x107e, x86_l_107e);
x86_l_1075:
	/* 0x1075: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1078:
	/* 0x1078: add    QWORD PTR [rax+0x8],rbx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_107c:
	/* 0x107c: jmp    10a6 <tail_handle_nat_fwd_ipv6+0x10a6> */
	X86_SIM_X86_JMP(0x107c, 0x10a6, x86_l_10a6);
x86_l_107e:
	/* 0x107e: mov    QWORD PTR [rsp+0x18],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215105ULL);
x86_l_1087:
	/* 0x1087: mov    QWORD PTR [rsp+0x20],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_108c:
	/* 0x108c: mov    rdi,QWORD PTR [rip+0xd036] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1093:
	/* 0x1093: lea    rsi,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1098:
	/* 0x1098: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_109d:
	/* 0x109d: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_10a2:
	/* 0x10a2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10a4:
	/* 0x10a4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10a6:
	/* 0x10a6: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10a8:
	/* 0x10a8: jmp    771 <tail_handle_nat_fwd_ipv6+0x771> */
	X86_SIM_X86_JMP(0x10a8, 0x771, x86_l_771);
x86_l_10ad:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
