extern char __config_cluster_id_bits;
extern char __config_debug_lb;
extern char __config_enable_conntrack_accounting;
extern char __config_enable_ipv4_fragments;
extern char __config_enable_jiffies;
extern char __config_interface_ifindex;
extern char __config_kernel_hz;
extern char __config_trace_payload_len;
extern char __config_tracing_ip_option_type;
extern char cilium_calls;
extern char cilium_ct4_global;
extern char cilium_ct_any4_global;
extern char cilium_ipv4_frag_datagrams;
extern char cilium_lb4_reverse_nat;
extern char cilium_metrics;
extern char cilium_percpu_trace_id;
extern char cilium_snat_v4_external;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int cilium_bpf_wireguard_cil_to_wireguard_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0x68 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 104ULL);
x86_l_7:
	/* 0x7: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_a:
	/* 0xa: movzx  ebp,WORD PTR [rdi+0xb4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 180ULL);
x86_l_11:
	/* 0x11: mov    eax,DWORD PTR [rdi+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_17:
	/* 0x17: mov    r15d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_32);
x86_l_1a:
	/* 0x1a: and    r15d,0xf00 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 3840ULL);
x86_l_21:
	/* 0x21: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_24:
	/* 0x24: cmp    r15d,0xf00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 3840ULL);
x86_l_2b:
	/* 0x2b: jne    7b <cil_to_wireguard+0x7b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2b, 0x7b, x86_l_7b);
x86_l_2d:
	/* 0x2d: movzx  edx,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_30:
	/* 0x30: mov    rcx,QWORD PTR [rip+0x2f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_cluster_id_bits)));
x86_l_37:
	/* 0x37: mov    esi,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_39:
	/* 0x39: mov    edi,0x7fffff00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 2147483392ULL);
x86_l_3e:
	/* 0x3e: bzhi   esi,edi,esi */
	X86_SIM_RUN_OP(X86_OP_BZHI, X86_RSI, X86_RDI, X86_WIDTH_32, X86_RSI, 0);
x86_l_43:
	/* 0x43: mov    edi,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_45:
	/* 0x45: neg    dil */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_8, X86_ALU_NEG, 0);
x86_l_48:
	/* 0x48: shlx   esi,esi,edi */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RSI, X86_RSI, X86_WIDTH_32, X86_RDI, X86_ALU_SHL);
x86_l_4d:
	/* 0x4d: and    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_AND);
x86_l_4f:
	/* 0x4f: mov    edi,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_51:
	/* 0x51: neg    dil */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_8, X86_ALU_NEG, 0);
x86_l_54:
	/* 0x54: shrx   esi,esi,edi */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RSI, X86_RSI, X86_WIDTH_32, X86_RDI, X86_ALU_SHR);
x86_l_59:
	/* 0x59: or     esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_5b:
	/* 0x5b: shr    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_5e:
	/* 0x5e: mov    edx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_60:
	/* 0x60: mov    dil,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_8, 24ULL);
x86_l_63:
	/* 0x63: mov    r8b,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_8, 24ULL);
x86_l_66:
	/* 0x66: sub    r8b,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_69:
	/* 0x69: bzhi   eax,eax,r8d */
	X86_SIM_RUN_OP(X86_OP_BZHI, X86_RAX, X86_RAX, X86_WIDTH_32, X86_R8, 0);
x86_l_6e:
	/* 0x6e: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_70:
	/* 0x70: sub    dil,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_73:
	/* 0x73: shlx   r13d,esi,edi */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_R13, X86_RSI, X86_WIDTH_32, X86_RDI, X86_ALU_SHL);
x86_l_78:
	/* 0x78: or     r13d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_32, X86_ALU_OR);
x86_l_7b:
	/* 0x7b: mov    DWORD PTR [rbx+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_82:
	/* 0x82: mov    DWORD PTR [rbx+0x2c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561024ULL);
x86_l_89:
	/* 0x89: mov    DWORD PTR [rbx+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_90:
	/* 0x90: mov    DWORD PTR [rbx+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_97:
	/* 0x97: mov    DWORD PTR [rbx+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_9e:
	/* 0x9e: mov    rax,QWORD PTR [rip+0x2f7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_tracing_ip_option_type)));
x86_l_a5:
	/* 0xa5: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a8:
	/* 0xa8: je     325 <cil_to_wireguard+0x325> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa8, 0x325, x86_l_325);
x86_l_ae:
	/* 0xae: movzx  r12d,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_b2:
	/* 0xb2: cmp    WORD PTR [rbx+0xb4],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 773094113288ULL);
x86_l_ba:
	/* 0xba: jne    2fe <cil_to_wireguard+0x2fe> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xba, 0x2fe, x86_l_2fe);
x86_l_c0:
	/* 0xc0: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_c3:
	/* 0xc3: sub    eax,DWORD PTR [rbx+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_c6:
	/* 0xc6: cmp    eax,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 20ULL);
x86_l_c9:
	/* 0xc9: jb     2fe <cil_to_wireguard+0x2fe> */
	X86_SIM_X86_JCC(X86_CC_B, 0xc9, 0x2fe, x86_l_2fe);
x86_l_cf:
	/* 0xcf: mov    rax,QWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_d6:
	/* 0xd6: movzx  r14d,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_da:
	/* 0xda: and    r14d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_de:
	/* 0xde: cmp    r14b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 6ULL);
x86_l_e2:
	/* 0xe2: jae    113 <cil_to_wireguard+0x113> */
	X86_SIM_X86_JCC(X86_CC_AE, 0xe2, 0x113, x86_l_113);
x86_l_e4:
	/* 0xe4: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e7:
	/* 0xe7: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_ef:
	/* 0xef: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f4:
	/* 0xf4: mov    rdi,QWORD PTR [rip+0x2f4] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_percpu_trace_id)));
x86_l_fb:
	/* 0xfb: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_100:
	/* 0x100: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_102:
	/* 0x102: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_105:
	/* 0x105: je     325 <cil_to_wireguard+0x325> */
	X86_SIM_X86_JCC(X86_CC_E, 0x105, 0x325, x86_l_325);
x86_l_10b:
	/* 0x10b: mov    QWORD PTR [rax],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10e:
	/* 0x10e: jmp    325 <cil_to_wireguard+0x325> */
	X86_SIM_X86_JMP(0x10e, 0x325, x86_l_325);
x86_l_113:
	/* 0x113: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_118:
	/* 0x118: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_11b:
	/* 0x11b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_11e:
	/* 0x11e: mov    esi,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 20ULL);
x86_l_123:
	/* 0x123: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_128:
	/* 0x128: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12a:
	/* 0x12a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_12c:
	/* 0x12c: js     2fe <cil_to_wireguard+0x2fe> */
	X86_SIM_X86_JCC(X86_CC_S, 0x12c, 0x2fe, x86_l_2fe);
x86_l_132:
	/* 0x132: movzx  eax,BYTE PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_136:
	/* 0x136: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_138:
	/* 0x138: je     e4 <cil_to_wireguard+0xe4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x138, 0xe4, x86_l_e4);
x86_l_13a:
	/* 0x13a: mov    esi,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 21ULL);
x86_l_13f:
	/* 0x13f: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_142:
	/* 0x142: je     1c7 <cil_to_wireguard+0x1c7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x142, 0x1c7, x86_l_1c7);
x86_l_148:
	/* 0x148: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_14d:
	/* 0x14d: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_152:
	/* 0x152: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_155:
	/* 0x155: mov    esi,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 21ULL);
x86_l_15a:
	/* 0x15a: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_15f:
	/* 0x15f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_161:
	/* 0x161: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_163:
	/* 0x163: js     2fe <cil_to_wireguard+0x2fe> */
	X86_SIM_X86_JCC(X86_CC_S, 0x163, 0x2fe, x86_l_2fe);
x86_l_169:
	/* 0x169: mov    esi,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 20ULL);
x86_l_16e:
	/* 0x16e: cmp    BYTE PTR [rsp],r12b */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_172:
	/* 0x172: jne    1bf <cil_to_wireguard+0x1bf> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x172, 0x1bf, x86_l_1bf);
x86_l_174:
	/* 0x174: movzx  eax,BYTE PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 56ULL);
x86_l_179:
	/* 0x179: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_17c:
	/* 0x17c: je     267 <cil_to_wireguard+0x267> */
	X86_SIM_X86_JCC(X86_CC_E, 0x17c, 0x267, x86_l_267);
x86_l_182:
	/* 0x182: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_185:
	/* 0x185: je     23f <cil_to_wireguard+0x23f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x185, 0x23f, x86_l_23f);
x86_l_18b:
	/* 0x18b: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_18e:
	/* 0x18e: jne    2fe <cil_to_wireguard+0x2fe> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x18e, 0x2fe, x86_l_2fe);
x86_l_194:
	/* 0x194: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_199:
	/* 0x199: add    esi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_19c:
	/* 0x19c: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a1:
	/* 0x1a1: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1a4:
	/* 0x1a4: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1a9:
	/* 0x1a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ab:
	/* 0x1ab: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ae:
	/* 0x1ae: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1b0:
	/* 0x1b0: movbe  cx,WORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOVBE_LOAD, X86_RCX, X86_RSP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_1b7:
	/* 0x1b7: movzx  ecx,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1ba:
	/* 0x1ba: jmp    28a <cil_to_wireguard+0x28a> */
	X86_SIM_X86_JMP(0x1ba, 0x28a, x86_l_28a);
x86_l_1bf:
	/* 0x1bf: movzx  esi,BYTE PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 56ULL);
x86_l_1c4:
	/* 0x1c4: add    esi,0x14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 20ULL);
x86_l_1c7:
	/* 0x1c7: lea    r14d,[r14*4+0x14] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 2), 20ULL);
x86_l_1cf:
	/* 0x1cf: cmp    esi,r14d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_1d2:
	/* 0x1d2: jae    e4 <cil_to_wireguard+0xe4> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x1d2, 0xe4, x86_l_e4);
x86_l_1d8:
	/* 0x1d8: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1dd:
	/* 0x1dd: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_1e0:
	/* 0x1e0: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1e3:
	/* 0x1e3: mov    QWORD PTR [rsp+0x20],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1e8:
	/* 0x1e8: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1ed:
	/* 0x1ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ef:
	/* 0x1ef: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1f1:
	/* 0x1f1: js     2fe <cil_to_wireguard+0x2fe> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1f1, 0x2fe, x86_l_2fe);
x86_l_1f7:
	/* 0x1f7: movzx  eax,BYTE PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1fb:
	/* 0x1fb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1fd:
	/* 0x1fd: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_202:
	/* 0x202: je     e4 <cil_to_wireguard+0xe4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x202, 0xe4, x86_l_e4);
x86_l_208:
	/* 0x208: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_20b:
	/* 0x20b: je     2a2 <cil_to_wireguard+0x2a2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x20b, 0x2a2, x86_l_2a2);
x86_l_211:
	/* 0x211: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_216:
	/* 0x216: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_218:
	/* 0x218: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_21d:
	/* 0x21d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_220:
	/* 0x220: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_225:
	/* 0x225: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_227:
	/* 0x227: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_229:
	/* 0x229: js     2fe <cil_to_wireguard+0x2fe> */
	X86_SIM_X86_JCC(X86_CC_S, 0x229, 0x2fe, x86_l_2fe);
x86_l_22f:
	/* 0x22f: cmp    BYTE PTR [rsp],r12b */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_233:
	/* 0x233: jne    298 <cil_to_wireguard+0x298> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x233, 0x298, x86_l_298);
x86_l_235:
	/* 0x235: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_23a:
	/* 0x23a: jmp    174 <cil_to_wireguard+0x174> */
	X86_SIM_X86_JMP(0x23a, 0x174, x86_l_174);
x86_l_23f:
	/* 0x23f: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_244:
	/* 0x244: add    esi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_247:
	/* 0x247: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24c:
	/* 0x24c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_24f:
	/* 0x24f: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_254:
	/* 0x254: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_256:
	/* 0x256: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_258:
	/* 0x258: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_25a:
	/* 0x25a: movbe  r14d,DWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOVBE_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 16ULL);
x86_l_261:
	/* 0x261: cmovs  r14d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R14, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_265:
	/* 0x265: jmp    28e <cil_to_wireguard+0x28e> */
	X86_SIM_X86_JMP(0x265, 0x28e, x86_l_28e);
x86_l_267:
	/* 0x267: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_26c:
	/* 0x26c: add    esi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_26f:
	/* 0x26f: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_274:
	/* 0x274: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_277:
	/* 0x277: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_27c:
	/* 0x27c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27e:
	/* 0x27e: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_281:
	/* 0x281: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_283:
	/* 0x283: movbe  rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOVBE_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_28a:
	/* 0x28a: cmovns r14,rcx */
	X86_SIM_L_EXEC_CMOV(X86_R14, X86_RCX, X86_WIDTH_64, X86_CC_NS);
x86_l_28e:
	/* 0x28e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_290:
	/* 0x290: jns    e7 <cil_to_wireguard+0xe7> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x290, 0xe7, x86_l_e7);
x86_l_296:
	/* 0x296: jmp    2fe <cil_to_wireguard+0x2fe> */
	X86_SIM_X86_JMP(0x296, 0x2fe, x86_l_2fe);
x86_l_298:
	/* 0x298: movzx  eax,BYTE PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 56ULL);
x86_l_29d:
	/* 0x29d: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2a2:
	/* 0x2a2: add    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_2a4:
	/* 0x2a4: cmp    esi,r14d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_2a7:
	/* 0x2a7: jae    e4 <cil_to_wireguard+0xe4> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x2a7, 0xe4, x86_l_e4);
x86_l_2ad:
	/* 0x2ad: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_2b2:
	/* 0x2b2: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_2b5:
	/* 0x2b5: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2b8:
	/* 0x2b8: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_2bb:
	/* 0x2bb: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2c0:
	/* 0x2c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c2:
	/* 0x2c2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2c4:
	/* 0x2c4: js     2fe <cil_to_wireguard+0x2fe> */
	X86_SIM_X86_JCC(X86_CC_S, 0x2c4, 0x2fe, x86_l_2fe);
x86_l_2c6:
	/* 0x2c6: cmp    BYTE PTR [rsp],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_2ca:
	/* 0x2ca: jb     e4 <cil_to_wireguard+0xe4> */
	X86_SIM_X86_JCC(X86_CC_B, 0x2ca, 0xe4, x86_l_e4);
x86_l_2d0:
	/* 0x2d0: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_2d5:
	/* 0x2d5: lea    esi,[r14+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_2d9:
	/* 0x2d9: lea    rdx,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2de:
	/* 0x2de: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2e1:
	/* 0x2e1: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2e6:
	/* 0x2e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e8:
	/* 0x2e8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2ea:
	/* 0x2ea: js     2fe <cil_to_wireguard+0x2fe> */
	X86_SIM_X86_JCC(X86_CC_S, 0x2ea, 0x2fe, x86_l_2fe);
x86_l_2ec:
	/* 0x2ec: cmp    BYTE PTR [rsp],r12b */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f0:
	/* 0x2f0: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_2f3:
	/* 0x2f3: jne    e4 <cil_to_wireguard+0xe4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2f3, 0xe4, x86_l_e4);
x86_l_2f9:
	/* 0x2f9: jmp    174 <cil_to_wireguard+0x174> */
	X86_SIM_X86_JMP(0x2f9, 0x174, x86_l_174);
x86_l_2fe:
	/* 0x2fe: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_306:
	/* 0x306: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_30b:
	/* 0x30b: mov    rdi,QWORD PTR [rip+0x2f3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_percpu_trace_id)));
x86_l_312:
	/* 0x312: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_317:
	/* 0x317: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_319:
	/* 0x319: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_31c:
	/* 0x31c: je     325 <cil_to_wireguard+0x325> */
	X86_SIM_X86_JCC(X86_CC_E, 0x31c, 0x325, x86_l_325);
x86_l_31e:
	/* 0x31e: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_325:
	/* 0x325: cmp    r15d,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 1024ULL);
x86_l_32c:
	/* 0x32c: je     d17 <cil_to_wireguard+0xd17> */
	X86_SIM_X86_JCC(X86_CC_E, 0x32c, 0xd17, x86_l_d17);
x86_l_332:
	/* 0x332: cmp    bp,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_16, 8ULL);
x86_l_336:
	/* 0x336: jne    d17 <cil_to_wireguard+0xd17> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x336, 0xd17, x86_l_d17);
x86_l_33c:
	/* 0x33c: mov    QWORD PTR [rsp+0x6],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 25769803776ULL);
x86_l_345:
	/* 0x345: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_34d:
	/* 0x34d: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_350:
	/* 0x350: sub    eax,DWORD PTR [rbx+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_353:
	/* 0x353: mov    ecx,0x86 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 134ULL);
x86_l_358:
	/* 0x358: cmp    eax,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 20ULL);
x86_l_35b:
	/* 0x35b: jae    3b4 <cil_to_wireguard+0x3b4> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x35b, 0x3b4, x86_l_3b4);
x86_l_35d:
	/* 0x35d: mov    DWORD PTR [rbx+0x28],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_361:
	/* 0x361: mov    DWORD PTR [rbx+0x2c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561024ULL);
x86_l_368:
	/* 0x368: mov    DWORD PTR [rbx+0x30],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_36b:
	/* 0x36b: movabs rax,0x176070200000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 105279346461114368ULL);
x86_l_375:
	/* 0x375: mov    QWORD PTR [rbx+0x34],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_379:
	/* 0x379: mov    r14d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_37d:
	/* 0x37d: movabs rax,0x701760200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 30089282048ULL);
x86_l_387:
	/* 0x387: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_38b:
	/* 0x38b: mov    BYTE PTR [rsp],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_38e:
	/* 0x38e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_393:
	/* 0x393: mov    rdi,QWORD PTR [rip+0x2f3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_39a:
	/* 0x39a: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_39d:
	/* 0x39d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39f:
	/* 0x39f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3a2:
	/* 0x3a2: je     502 <cil_to_wireguard+0x502> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3a2, 0x502, x86_l_502);
x86_l_3a8:
	/* 0x3a8: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_3ab:
	/* 0x3ab: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3af:
	/* 0x3af: jmp    528 <cil_to_wireguard+0x528> */
	X86_SIM_X86_JMP(0x3af, 0x528, x86_l_528);
x86_l_3b4:
	/* 0x3b4: movabs r8,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_64, 2199023255552ULL);
x86_l_3be:
	/* 0x3be: movabs r12,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 1099511627776ULL);
x86_l_3c8:
	/* 0x3c8: mov    rdx,QWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_3cf:
	/* 0x3cf: movzx  ecx,WORD PTR [rdx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_3d3:
	/* 0x3d3: movzx  eax,BYTE PTR [rdx+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_3d7:
	/* 0x3d7: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_3da:
	/* 0x3da: shl    rsi,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_3de:
	/* 0x3de: or     rsi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_3e1:
	/* 0x3e1: movzx  ecx,WORD PTR [rdx+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_3e5:
	/* 0x3e5: lea    rdi,[rsi+r12*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_R12, 0), 0ULL);
x86_l_3e9:
	/* 0x3e9: test   ecx,0xff3f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_32, 65343ULL);
x86_l_3ef:
	/* 0x3ef: cmove  rdi,rsi */
	X86_SIM_L_EXEC_CMOV(X86_RDI, X86_RSI, X86_WIDTH_64, X86_CC_E);
x86_l_3f3:
	/* 0x3f3: lea    rsi,[rdi+r8*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_3f7:
	/* 0x3f7: test   ecx,0xff1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_32, 65311ULL);
x86_l_3fd:
	/* 0x3fd: cmove  rsi,rdi */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RDI, X86_WIDTH_64, X86_CC_E);
x86_l_401:
	/* 0x401: mov    QWORD PTR [rsp+0x20],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_406:
	/* 0x406: mov    esi,DWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_408:
	/* 0x408: mov    BYTE PTR [rsp+0xc],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_40c:
	/* 0x40c: mov    ecx,DWORD PTR [rdx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_40f:
	/* 0x40f: mov    DWORD PTR [rsp],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_412:
	/* 0x412: mov    edx,DWORD PTR [rdx+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_415:
	/* 0x415: mov    DWORD PTR [rsp+0x4],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_419:
	/* 0x419: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_41c:
	/* 0x41c: je     427 <cil_to_wireguard+0x427> */
	X86_SIM_X86_JCC(X86_CC_E, 0x41c, 0x427, x86_l_427);
x86_l_41e:
	/* 0x41e: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_421:
	/* 0x421: jne    d17 <cil_to_wireguard+0xd17> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x421, 0xd17, x86_l_d17);
x86_l_427:
	/* 0x427: shl    esi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHL, 2ULL);
x86_l_42a:
	/* 0x42a: lea    r15,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_42f:
	/* 0x42f: mov    rax,QWORD PTR [rip+0x2f3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_ipv4_fragments)));
x86_l_436:
	/* 0x436: and    esi,0x3c */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_AND, 60ULL);
x86_l_439:
	/* 0x439: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_43c:
	/* 0x43c: je     548 <cil_to_wireguard+0x548> */
	X86_SIM_X86_JCC(X86_CC_E, 0x43c, 0x548, x86_l_548);
x86_l_442:
	/* 0x442: mov    DWORD PTR [rsp+0x38],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_446:
	/* 0x446: mov    DWORD PTR [rsp+0x3c],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_44a:
	/* 0x44a: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_44f:
	/* 0x44f: mov    WORD PTR [rsp+0x40],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_454:
	/* 0x454: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_457:
	/* 0x457: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_45b:
	/* 0x45b: mov    BYTE PTR [rsp+0x42],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 66ULL);
x86_l_45f:
	/* 0x45f: mov    BYTE PTR [rsp+0x43],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 287762808832ULL);
x86_l_464:
	/* 0x464: mov    r14,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R8, X86_WIDTH_64);
x86_l_467:
	/* 0x467: test   rcx,r8 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_R8, X86_WIDTH_64);
x86_l_46a:
	/* 0x46a: jne    bd8 <cil_to_wireguard+0xbd8> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x46a, 0xbd8, x86_l_bd8);
x86_l_470:
	/* 0x470: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_475:
	/* 0x475: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_478:
	/* 0x478: mov    rbp,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RSI, X86_WIDTH_64);
x86_l_47b:
	/* 0x47b: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_47e:
	/* 0x47e: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_483:
	/* 0x483: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_485:
	/* 0x485: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_487:
	/* 0x487: js     585 <cil_to_wireguard+0x585> */
	X86_SIM_X86_JCC(X86_CC_S, 0x487, 0x585, x86_l_585);
x86_l_48d:
	/* 0x48d: test   QWORD PTR [rsp+0x20],r12 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_492:
	/* 0x492: je     56f <cil_to_wireguard+0x56f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x492, 0x56f, x86_l_56f);
x86_l_498:
	/* 0x498: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_49d:
	/* 0x49d: mov    rdi,QWORD PTR [rip+0x2f3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv4_frag_datagrams)));
x86_l_4a4:
	/* 0x4a4: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_4a9:
	/* 0x4a9: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_4ac:
	/* 0x4ac: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4ae:
	/* 0x4ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b0:
	/* 0x4b0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4b2:
	/* 0x4b2: je     56f <cil_to_wireguard+0x56f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4b2, 0x56f, x86_l_56f);
x86_l_4b8:
	/* 0x4b8: mov    r15d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_4bc:
	/* 0x4bc: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_4c5:
	/* 0x4c5: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4ce:
	/* 0x4ce: movabs rax,0x6b0085020a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 459570217482ULL);
x86_l_4d8:
	/* 0x4d8: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_4dd:
	/* 0x4dd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4e2:
	/* 0x4e2: mov    rdi,QWORD PTR [rip+0x2f3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_4e9:
	/* 0x4e9: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_4ee:
	/* 0x4ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4f0:
	/* 0x4f0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4f3:
	/* 0x4f3: je     c12 <cil_to_wireguard+0xc12> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4f3, 0xc12, x86_l_c12);
x86_l_4f9:
	/* 0x4f9: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_4fc:
	/* 0x4fc: add    QWORD PTR [rax+0x8],r15 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_500:
	/* 0x500: jmp    56f <cil_to_wireguard+0x56f> */
	X86_SIM_X86_JMP(0x500, 0x56f, x86_l_56f);
x86_l_502:
	/* 0x502: mov    QWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_50b:
	/* 0x50b: mov    QWORD PTR [rsp+0x18],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_510:
	/* 0x510: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_515:
	/* 0x515: mov    rdi,QWORD PTR [rip+0x2f3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_51c:
	/* 0x51c: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_51f:
	/* 0x51f: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_524:
	/* 0x524: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_526:
	/* 0x526: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_528:
	/* 0x528: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_52d:
	/* 0x52d: mov    rsi,QWORD PTR [rip+0x2f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_534:
	/* 0x534: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_537:
	/* 0x537: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_53c:
	/* 0x53c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_53e:
	/* 0x53e: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_543:
	/* 0x543: jmp    d7e <cil_to_wireguard+0xd7e> */
	X86_SIM_X86_JMP(0x543, 0xd7e, x86_l_d7e);
x86_l_548:
	/* 0x548: test   QWORD PTR [rsp+0x20],r8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_54d:
	/* 0x54d: jne    bfe <cil_to_wireguard+0xbfe> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x54d, 0xbfe, x86_l_bfe);
x86_l_553:
	/* 0x553: mov    r14,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R8, X86_WIDTH_64);
x86_l_556:
	/* 0x556: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_55b:
	/* 0x55b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_55e:
	/* 0x55e: mov    rbp,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RSI, X86_WIDTH_64);
x86_l_561:
	/* 0x561: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_564:
	/* 0x564: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_569:
	/* 0x569: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_56b:
	/* 0x56b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_56d:
	/* 0x56d: js     585 <cil_to_wireguard+0x585> */
	X86_SIM_X86_JCC(X86_CC_S, 0x56d, 0x585, x86_l_585);
x86_l_56f:
	/* 0x56f: movzx  r15d,BYTE PTR [rsp+0xd] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 13ULL);
x86_l_575:
	/* 0x575: cmp    BYTE PTR [rsp+0xc],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 51539607558ULL);
x86_l_57a:
	/* 0x57a: jne    58f <cil_to_wireguard+0x58f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x57a, 0x58f, x86_l_58f);
x86_l_57c:
	/* 0x57c: mov    rdi,QWORD PTR [rip+0x2f3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct4_global)));
x86_l_583:
	/* 0x583: jmp    596 <cil_to_wireguard+0x596> */
	X86_SIM_X86_JMP(0x583, 0x596, x86_l_596);
x86_l_585:
	/* 0x585: mov    ecx,0x87 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 135ULL);
x86_l_58a:
	/* 0x58a: jmp    35d <cil_to_wireguard+0x35d> */
	X86_SIM_X86_JMP(0x58a, 0x35d, x86_l_35d);
x86_l_58f:
	/* 0x58f: mov    rdi,QWORD PTR [rip+0x2f3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct_any4_global)));
x86_l_596:
	/* 0x596: mov    BYTE PTR [rsp+0xd],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 55834574848ULL);
x86_l_59b:
	/* 0x59b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5a0:
	/* 0x5a0: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_5a3:
	/* 0x5a3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a5:
	/* 0x5a5: mov    BYTE PTR [rsp+0xd],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 13ULL);
x86_l_5aa:
	/* 0x5aa: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5ad:
	/* 0x5ad: je     d17 <cil_to_wireguard+0xd17> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5ad, 0xd17, x86_l_d17);
x86_l_5b3:
	/* 0x5b3: movzx  ecx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_5b7:
	/* 0x5b7: test   cl,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_5ba:
	/* 0x5ba: jne    5d9 <cil_to_wireguard+0x5d9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x5ba, 0x5d9, x86_l_5d9);
x86_l_5bc:
	/* 0x5bc: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_5be:
	/* 0x5be: jns    d17 <cil_to_wireguard+0xd17> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x5be, 0xd17, x86_l_d17);
x86_l_5c4:
	/* 0x5c4: movzx  ecx,WORD PTR [rax+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 40ULL);
x86_l_5c8:
	/* 0x5c8: test   cx,cx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_16);
x86_l_5cb:
	/* 0x5cb: je     622 <cil_to_wireguard+0x622> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5cb, 0x622, x86_l_622);
x86_l_5cd:
	/* 0x5cd: mov    eax,DWORD PTR [rax+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_5d0:
	/* 0x5d0: mov    DWORD PTR [rsp+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5d4:
	/* 0x5d4: jmp    66d <cil_to_wireguard+0x66d> */
	X86_SIM_X86_JMP(0x5d4, 0x66d, x86_l_66d);
x86_l_5d9:
	/* 0x5d9: movzx  eax,WORD PTR [rax+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_5dd:
	/* 0x5dd: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_5e0:
	/* 0x5e0: je     d17 <cil_to_wireguard+0xd17> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5e0, 0xd17, x86_l_d17);
x86_l_5e6:
	/* 0x5e6: mov    WORD PTR [rsp+0x10],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5eb:
	/* 0x5eb: mov    rax,QWORD PTR [rip+0x2f3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_5f2:
	/* 0x5f2: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_5f5:
	/* 0x5f5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5fa:
	/* 0x5fa: mov    rdi,QWORD PTR [rip+0x2f3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_reverse_nat)));
x86_l_601:
	/* 0x601: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_606:
	/* 0x606: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_608:
	/* 0x608: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_60b:
	/* 0x60b: je     d17 <cil_to_wireguard+0xd17> */
	X86_SIM_X86_JCC(X86_CC_E, 0x60b, 0xd17, x86_l_d17);
x86_l_611:
	/* 0x611: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_613:
	/* 0x613: mov    DWORD PTR [rsp+0x30],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_617:
	/* 0x617: movzx  eax,WORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_61b:
	/* 0x61b: mov    WORD PTR [rsp+0x34],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_620:
	/* 0x620: jmp    672 <cil_to_wireguard+0x672> */
	X86_SIM_X86_JMP(0x620, 0x672, x86_l_672);
x86_l_622:
	/* 0x622: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_626:
	/* 0x626: mov    rcx,QWORD PTR [rsp+0x5] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 5ULL);
x86_l_62b:
	/* 0x62b: mov    QWORD PTR [rsp+0x15],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 21ULL);
x86_l_630:
	/* 0x630: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_635:
	/* 0x635: mov    BYTE PTR [rsp+0x1d],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 124554051584ULL);
x86_l_63a:
	/* 0x63a: rorx   eax,DWORD PTR [rsp+0x8],0x10 */
	X86_SIM_RUN_OP(X86_OP_RORX_MEM, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 34359738384ULL);
x86_l_642:
	/* 0x642: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_646:
	/* 0x646: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_64b:
	/* 0x64b: mov    rdi,QWORD PTR [rip+0x2f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_652:
	/* 0x652: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_657:
	/* 0x657: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_659:
	/* 0x659: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_65c:
	/* 0x65c: je     d17 <cil_to_wireguard+0xd17> */
	X86_SIM_X86_JCC(X86_CC_E, 0x65c, 0xd17, x86_l_d17);
x86_l_662:
	/* 0x662: mov    ecx,DWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_665:
	/* 0x665: mov    DWORD PTR [rsp+0x30],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_669:
	/* 0x669: movzx  ecx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_66d:
	/* 0x66d: mov    WORD PTR [rsp+0x34],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_672:
	/* 0x672: movzx  eax,BYTE PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 12ULL);
x86_l_677:
	/* 0x677: mov    BYTE PTR [rsp+0x2c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_67b:
	/* 0x67b: cmp    al,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 6ULL);
x86_l_67d:
	/* 0x67d: jne    688 <cil_to_wireguard+0x688> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x67d, 0x688, x86_l_688);
x86_l_67f:
	/* 0x67f: mov    r15,QWORD PTR [rip+0x2f3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&cilium_ct4_global)));
x86_l_686:
	/* 0x686: jmp    68f <cil_to_wireguard+0x68f> */
	X86_SIM_X86_JMP(0x686, 0x68f, x86_l_68f);
x86_l_688:
	/* 0x688: mov    r15,QWORD PTR [rip+0x2f3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&cilium_ct_any4_global)));
x86_l_68f:
	/* 0x68f: mov    BYTE PTR [rsp+0xd],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 55834574848ULL);
x86_l_694:
	/* 0x694: mov    DWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_69c:
	/* 0x69c: mov    rax,QWORD PTR [rip+0x2f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_ipv4_fragments)));
x86_l_6a3:
	/* 0x6a3: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6a6:
	/* 0x6a6: je     71d <cil_to_wireguard+0x71d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6a6, 0x71d, x86_l_71d);
x86_l_6a8:
	/* 0x6a8: and    r12,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 32ULL);
x86_l_6ad:
	/* 0x6ad: je     71d <cil_to_wireguard+0x71d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6ad, 0x71d, x86_l_71d);
x86_l_6af:
	/* 0x6af: mov    r12d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_6b3:
	/* 0x6b3: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_6bc:
	/* 0x6bc: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_6c5:
	/* 0x6c5: movabs rax,0x6c03a50109 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 463917613321ULL);
x86_l_6cf:
	/* 0x6cf: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_6d4:
	/* 0x6d4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6d9:
	/* 0x6d9: mov    rdi,QWORD PTR [rip+0x2f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_6e0:
	/* 0x6e0: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_6e5:
	/* 0x6e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6e7:
	/* 0x6e7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6ea:
	/* 0x6ea: je     6f5 <cil_to_wireguard+0x6f5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6ea, 0x6f5, x86_l_6f5);
x86_l_6ec:
	/* 0x6ec: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_6ef:
	/* 0x6ef: add    QWORD PTR [rax+0x8],r12 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_6f3:
	/* 0x6f3: jmp    71d <cil_to_wireguard+0x71d> */
	X86_SIM_X86_JMP(0x6f3, 0x71d, x86_l_71d);
x86_l_6f5:
	/* 0x6f5: mov    QWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_6fe:
	/* 0x6fe: mov    QWORD PTR [rsp+0x18],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_703:
	/* 0x703: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_708:
	/* 0x708: mov    rdi,QWORD PTR [rip+0x2f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_70f:
	/* 0x70f: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_714:
	/* 0x714: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_719:
	/* 0x719: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_71b:
	/* 0x71b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_71d:
	/* 0x71d: cmp    BYTE PTR [rsp+0x2c],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 188978561030ULL);
x86_l_722:
	/* 0x722: mov    QWORD PTR [rsp+0x58],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_727:
	/* 0x727: jne    779 <cil_to_wireguard+0x779> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x727, 0x779, x86_l_779);
x86_l_729:
	/* 0x729: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_72e:
	/* 0x72e: and    rax,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R14, X86_WIDTH_64, X86_ALU_AND);
x86_l_731:
	/* 0x731: jne    779 <cil_to_wireguard+0x779> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x731, 0x779, x86_l_779);
x86_l_733:
	/* 0x733: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_738:
	/* 0x738: lea    esi,[rbp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_73b:
	/* 0x73b: lea    rdx,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_740:
	/* 0x740: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_743:
	/* 0x743: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_748:
	/* 0x748: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_74a:
	/* 0x74a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_74c:
	/* 0x74c: js     d17 <cil_to_wireguard+0xd17> */
	X86_SIM_X86_JCC(X86_CC_S, 0x74c, 0xd17, x86_l_d17);
x86_l_752:
	/* 0x752: mov    ebp,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_756:
	/* 0x756: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_758:
	/* 0x758: and    eax,0x1200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4608ULL);
x86_l_75d:
	/* 0x75d: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_760:
	/* 0x760: cmp    eax,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 512ULL);
x86_l_765:
	/* 0x765: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_768:
	/* 0x768: test   ebp,0x500 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RBP, X86_WIDTH_32, 1280ULL);
x86_l_76e:
	/* 0x76e: jne    c3f <cil_to_wireguard+0xc3f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x76e, 0xc3f, x86_l_c3f);
x86_l_774:
	/* 0x774: mov    r12b,al */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_8);
x86_l_777:
	/* 0x777: jmp    780 <cil_to_wireguard+0x780> */
	X86_SIM_X86_JMP(0x777, 0x780, x86_l_780);
x86_l_779:
	/* 0x779: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_77c:
	/* 0x77c: mov    ebp,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_780:
	/* 0x780: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_785:
	/* 0x785: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_788:
	/* 0x788: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_78b:
	/* 0x78b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_78d:
	/* 0x78d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_790:
	/* 0x790: je     d0e <cil_to_wireguard+0xd0e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x790, 0xd0e, x86_l_d0e);
x86_l_796:
	/* 0x796: movzx  ecx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_79a:
	/* 0x79a: test   cl,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 32ULL);
x86_l_79d:
	/* 0x79d: jne    7a8 <cil_to_wireguard+0x7a8> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x79d, 0x7a8, x86_l_7a8);
x86_l_79f:
	/* 0x79f: test   cl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_8);
x86_l_7a1:
	/* 0x7a1: js     7ba <cil_to_wireguard+0x7ba> */
	X86_SIM_X86_JCC(X86_CC_S, 0x7a1, 0x7ba, x86_l_7ba);
x86_l_7a3:
	/* 0x7a3: jmp    d0e <cil_to_wireguard+0xd0e> */
	X86_SIM_X86_JMP(0x7a3, 0xd0e, x86_l_d0e);
x86_l_7a8:
	/* 0x7a8: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_7aa:
	/* 0x7aa: and    edx,0x80 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 128ULL);
x86_l_7b0:
	/* 0x7b0: or     dx,WORD PTR [rax+0x26] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RAX, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 38ULL);
x86_l_7b4:
	/* 0x7b4: je     d0e <cil_to_wireguard+0xd0e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7b4, 0xd0e, x86_l_d0e);
x86_l_7ba:
	/* 0x7ba: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_7bc:
	/* 0x7bc: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_7be:
	/* 0x7be: test   dl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_8, 3ULL);
x86_l_7c1:
	/* 0x7c1: je     8ce <cil_to_wireguard+0x8ce> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7c1, 0x8ce, x86_l_8ce);
x86_l_7c7:
	/* 0x7c7: mov    DWORD PTR [rsp+0x54],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_7cc:
	/* 0x7cc: mov    rsi,QWORD PTR [rip+0x2f3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_7d3:
	/* 0x7d3: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7d6:
	/* 0x7d6: je     7e9 <cil_to_wireguard+0x7e9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7d6, 0x7e9, x86_l_7e9);
x86_l_7d8:
	/* 0x7d8: mov    rdx,QWORD PTR [rip+0x2f3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_7df:
	/* 0x7df: imul   r12d,DWORD PTR [rdx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R12, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_7e3:
	/* 0x7e3: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_7e7:
	/* 0x7e7: jmp    7ef <cil_to_wireguard+0x7ef> */
	X86_SIM_X86_JMP(0x7e7, 0x7ef, x86_l_7ef);
x86_l_7e9:
	/* 0x7e9: mov    r12d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 60ULL);
x86_l_7ef:
	/* 0x7ef: cmp    BYTE PTR [rsp+0x2c],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 188978561030ULL);
x86_l_7f4:
	/* 0x7f4: jne    82c <cil_to_wireguard+0x82c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x7f4, 0x82c, x86_l_82c);
x86_l_7f6:
	/* 0x7f6: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_7f8:
	/* 0x7f8: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_7fa:
	/* 0x7fa: shr    edx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_7fd:
	/* 0x7fd: and    edx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_800:
	/* 0x800: or     edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_802:
	/* 0x802: mov    WORD PTR [rax+0x24],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_806:
	/* 0x806: test   dl,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_8, 16ULL);
x86_l_809:
	/* 0x809: mov    ecx,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 60ULL);
x86_l_80e:
	/* 0x80e: mov    r12d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 21600ULL);
x86_l_814:
	/* 0x814: cmove  r12d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RCX, X86_WIDTH_32, X86_CC_E);
x86_l_818:
	/* 0x818: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_81b:
	/* 0x81b: je     82c <cil_to_wireguard+0x82c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x81b, 0x82c, x86_l_82c);
x86_l_81d:
	/* 0x81d: mov    rcx,QWORD PTR [rip+0x2f3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_824:
	/* 0x824: imul   r12d,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_828:
	/* 0x828: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_82c:
	/* 0x82c: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_831:
	/* 0x831: mov    r15d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_32);
x86_l_834:
	/* 0x834: shr    r15d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_838:
	/* 0x838: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_83b:
	/* 0x83b: je     84f <cil_to_wireguard+0x84f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x83b, 0x84f, x86_l_84f);
x86_l_83d:
	/* 0x83d: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_842:
	/* 0x842: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_844:
	/* 0x844: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_846:
	/* 0x846: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_849:
	/* 0x849: shr    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_84d:
	/* 0x84d: jmp    872 <cil_to_wireguard+0x872> */
	X86_SIM_X86_JMP(0x84d, 0x872, x86_l_872);
x86_l_84f:
	/* 0x84f: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_854:
	/* 0x854: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_856:
	/* 0x856: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_858:
	/* 0x858: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_85c:
	/* 0x85c: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_866:
	/* 0x866: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_869:
	/* 0x869: mulx   rcx,rcx,rcx */
	X86_SIM_L_EXEC_MULX(X86_RCX, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_86e:
	/* 0x86e: shr    rcx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_872:
	/* 0x872: add    r12d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_875:
	/* 0x875: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_87a:
	/* 0x87a: mov    DWORD PTR [rax+0x20],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_87e:
	/* 0x87e: movzx  edx,BYTE PTR [rax+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_882:
	/* 0x882: mov    esi,DWORD PTR [rax+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_885:
	/* 0x885: and    r15b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_889:
	/* 0x889: mov    rdi,QWORD PTR [rip+0x2f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_890:
	/* 0x890: cmp    BYTE PTR [rdi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_893:
	/* 0x893: je     8a6 <cil_to_wireguard+0x8a6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x893, 0x8a6, x86_l_8a6);
x86_l_895:
	/* 0x895: mov    rdi,QWORD PTR [rip+0x2f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_89c:
	/* 0x89c: mov    edi,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_89e:
	/* 0x89e: lea    edi,[rdi+rdi*4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_8a1:
	/* 0x8a1: shr    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_8a4:
	/* 0x8a4: jmp    8ab <cil_to_wireguard+0x8ab> */
	X86_SIM_X86_JMP(0x8a4, 0x8ab, x86_l_8ab);
x86_l_8a6:
	/* 0x8a6: mov    edi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 5ULL);
x86_l_8ab:
	/* 0x8ab: mov    r12d,DWORD PTR [rsp+0x54] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_8b0:
	/* 0x8b0: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_8b2:
	/* 0x8b2: or     r15b,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_8b5:
	/* 0x8b5: cmp    edi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RCX, X86_WIDTH_32);
x86_l_8b7:
	/* 0x8b7: jb     8be <cil_to_wireguard+0x8be> */
	X86_SIM_X86_JCC(X86_CC_B, 0x8b7, 0x8be, x86_l_8be);
x86_l_8b9:
	/* 0x8b9: cmp    dl,r15b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R15, X86_WIDTH_8);
x86_l_8bc:
	/* 0x8bc: je     8ce <cil_to_wireguard+0x8ce> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8bc, 0x8ce, x86_l_8ce);
x86_l_8be:
	/* 0x8be: mov    BYTE PTR [rax+0x2b],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_8c2:
	/* 0x8c2: mov    DWORD PTR [rax+0x34],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_8c5:
	/* 0x8c5: mov    rcx,QWORD PTR [rip+0x2f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_8cc:
	/* 0x8cc: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8ce:
	/* 0x8ce: mov    rcx,QWORD PTR [rip+0x2f3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_8d5:
	/* 0x8d5: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8d8:
	/* 0x8d8: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_8dd:
	/* 0x8dd: je     8ec <cil_to_wireguard+0x8ec> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8dd, 0x8ec, x86_l_8ec);
x86_l_8df:
	/* 0x8df: inc QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 16ULL);
x86_l_8e4:
	/* 0x8e4: mov    ecx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_8e7:
	/* 0x8e7: add QWORD PTR [rax+0x18],rcx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_8ec:
	/* 0x8ec: cmp    r12d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 2ULL);
x86_l_8f0:
	/* 0x8f0: je     942 <cil_to_wireguard+0x942> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8f0, 0x942, x86_l_942);
x86_l_8f2:
	/* 0x8f2: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_8f6:
	/* 0x8f6: jne    a2c <cil_to_wireguard+0xa2c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x8f6, 0xa2c, x86_l_a2c);
x86_l_8fc:
	/* 0x8fc: movzx  ecx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_900:
	/* 0x900: test   cl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_903:
	/* 0x903: je     a2c <cil_to_wireguard+0xa2c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x903, 0xa2c, x86_l_a2c);
x86_l_909:
	/* 0x909: mov    r12d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_90c:
	/* 0x90c: mov    WORD PTR [rax+0x2a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 180388626432ULL);
x86_l_912:
	/* 0x912: and    ecx,0xffec */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 65516ULL);
x86_l_918:
	/* 0x918: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_91b:
	/* 0x91b: mov    WORD PTR [rax+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_91f:
	/* 0x91f: mov    r15,QWORD PTR [rip+0x2f3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_926:
	/* 0x926: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_92a:
	/* 0x92a: je     c4a <cil_to_wireguard+0xc4a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x92a, 0xc4a, x86_l_c4a);
x86_l_930:
	/* 0x930: mov    rax,QWORD PTR [rip+0x2f3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_937:
	/* 0x937: imul   ebp,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_93a:
	/* 0x93a: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_93d:
	/* 0x93d: jmp    c4f <cil_to_wireguard+0xc4f> */
	X86_SIM_X86_JMP(0x93d, 0xc4f, x86_l_c4f);
x86_l_942:
	/* 0x942: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_944:
	/* 0x944: shr    ecx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_947:
	/* 0x947: and    ecx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2ULL);
x86_l_94a:
	/* 0x94a: or     cx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RAX, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 36ULL);
x86_l_94e:
	/* 0x94e: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_950:
	/* 0x950: or     edx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_OR, 1ULL);
x86_l_953:
	/* 0x953: mov    WORD PTR [rax+0x24],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_957:
	/* 0x957: mov    rdx,QWORD PTR [rip+0x2f3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_95e:
	/* 0x95e: mov    edx,DWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_960:
	/* 0x960: test   cl,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_963:
	/* 0x963: je     a2c <cil_to_wireguard+0xa2c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x963, 0xa2c, x86_l_a2c);
x86_l_969:
	/* 0x969: mov    rdx,QWORD PTR [rip+0x2f3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_970:
	/* 0x970: cmp    BYTE PTR [rdx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_973:
	/* 0x973: je     98a <cil_to_wireguard+0x98a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x973, 0x98a, x86_l_98a);
x86_l_975:
	/* 0x975: mov    rcx,QWORD PTR [rip+0x2f3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_97c:
	/* 0x97c: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_97e:
	/* 0x97e: add    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_980:
	/* 0x980: lea    r15d,[rcx+rcx*4] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 0ULL);
x86_l_984:
	/* 0x984: shr    r15d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_988:
	/* 0x988: jmp    990 <cil_to_wireguard+0x990> */
	X86_SIM_X86_JMP(0x988, 0x990, x86_l_990);
x86_l_98a:
	/* 0x98a: mov    r15d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 10ULL);
x86_l_990:
	/* 0x990: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_993:
	/* 0x993: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_996:
	/* 0x996: cmp    BYTE PTR [rdx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_999:
	/* 0x999: je     9aa <cil_to_wireguard+0x9aa> */
	X86_SIM_X86_JCC(X86_CC_E, 0x999, 0x9aa, x86_l_9aa);
x86_l_99b:
	/* 0x99b: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_9a0:
	/* 0x9a0: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9a2:
	/* 0x9a2: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_9a4:
	/* 0x9a4: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_9a8:
	/* 0x9a8: jmp    9cd <cil_to_wireguard+0x9cd> */
	X86_SIM_X86_JMP(0x9a8, 0x9cd, x86_l_9cd);
x86_l_9aa:
	/* 0x9aa: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_9af:
	/* 0x9af: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9b1:
	/* 0x9b1: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_9b3:
	/* 0x9b3: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_9b7:
	/* 0x9b7: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_9c1:
	/* 0x9c1: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_9c4:
	/* 0x9c4: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_9c9:
	/* 0x9c9: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_9cd:
	/* 0x9cd: add    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_9d0:
	/* 0x9d0: mov    DWORD PTR [r12+0x20],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9d5:
	/* 0x9d5: movzx  ecx,BYTE PTR [r12+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_9db:
	/* 0x9db: mov    edx,DWORD PTR [r12+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_9e0:
	/* 0x9e0: and    bpl,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_9e4:
	/* 0x9e4: mov    rsi,QWORD PTR [rip+0x2f3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_9eb:
	/* 0x9eb: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9ee:
	/* 0x9ee: je     a01 <cil_to_wireguard+0xa01> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9ee, 0xa01, x86_l_a01);
x86_l_9f0:
	/* 0x9f0: mov    rsi,QWORD PTR [rip+0x2f3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_9f7:
	/* 0x9f7: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9f9:
	/* 0x9f9: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_9fc:
	/* 0x9fc: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_9ff:
	/* 0x9ff: jmp    a06 <cil_to_wireguard+0xa06> */
	X86_SIM_X86_JMP(0x9ff, 0xa06, x86_l_a06);
x86_l_a01:
	/* 0xa01: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_a06:
	/* 0xa06: mov    rdi,QWORD PTR [rip+0x2f0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_a0d:
	/* 0xa0d: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_a0f:
	/* 0xa0f: or     bpl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_a12:
	/* 0xa12: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_a14:
	/* 0xa14: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_a19:
	/* 0xa19: jb     a20 <cil_to_wireguard+0xa20> */
	X86_SIM_X86_JCC(X86_CC_B, 0xa19, 0xa20, x86_l_a20);
x86_l_a1b:
	/* 0xa1b: cmp    cl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_8);
x86_l_a1e:
	/* 0xa1e: je     a2c <cil_to_wireguard+0xa2c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa1e, 0xa2c, x86_l_a2c);
x86_l_a20:
	/* 0xa20: mov    BYTE PTR [r12+0x2b],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_a25:
	/* 0xa25: mov    DWORD PTR [r12+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_a2a:
	/* 0xa2a: mov    eax,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a2c:
	/* 0xa2c: test   BYTE PTR [rsp+0xd],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 55834574850ULL);
x86_l_a31:
	/* 0xa31: jne    d17 <cil_to_wireguard+0xd17> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa31, 0xd17, x86_l_d17);
x86_l_a37:
	/* 0xa37: mov    r12,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RSI, X86_WIDTH_64);
x86_l_a3a:
	/* 0xa3a: mov    r15d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_a3f:
	/* 0xa3f: mov    rax,QWORD PTR [rip+0x2f3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_a46:
	/* 0xa46: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_a49:
	/* 0xa49: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a4d:
	/* 0xa4d: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_a51:
	/* 0xa51: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_a56:
	/* 0xa56: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a5b:
	/* 0xa5b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_a5e:
	/* 0xa5e: mov    esi,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 12ULL);
x86_l_a63:
	/* 0xa63: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_a68:
	/* 0xa68: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a6b:
	/* 0xa6b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a6d:
	/* 0xa6d: mov    ecx,0x8d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 141ULL);
x86_l_a72:
	/* 0xa72: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a74:
	/* 0xa74: js     35d <cil_to_wireguard+0x35d> */
	X86_SIM_X86_JCC(X86_CC_S, 0xa74, 0x35d, x86_l_35d);
x86_l_a7a:
	/* 0xa7a: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_a7d:
	/* 0xa7d: je     35d <cil_to_wireguard+0x35d> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa7d, 0x35d, x86_l_35d);
x86_l_a83:
	/* 0xa83: not    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_a86:
	/* 0xa86: add    r15d,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_a8b:
	/* 0xa8b: adc    r15d,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_a8f:
	/* 0xa8f: mov    eax,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_a94:
	/* 0xa94: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_a97:
	/* 0xa97: mov    esi,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 10ULL);
x86_l_a9c:
	/* 0xa9c: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a9e:
	/* 0xa9e: mov    ecx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_32);
x86_l_aa1:
	/* 0xaa1: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_aa4:
	/* 0xaa4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aa6:
	/* 0xaa6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_aa8:
	/* 0xaa8: js     ad5 <cil_to_wireguard+0xad5> */
	X86_SIM_X86_JCC(X86_CC_S, 0xaa8, 0xad5, x86_l_ad5);
x86_l_aaa:
	/* 0xaaa: test   QWORD PTR [rsp+0x20],r14 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_aaf:
	/* 0xaaf: jne    d17 <cil_to_wireguard+0xd17> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xaaf, 0xd17, x86_l_d17);
x86_l_ab5:
	/* 0xab5: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_ab8:
	/* 0xab8: movzx  eax,BYTE PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 12ULL);
x86_l_abd:
	/* 0xabd: cmp    eax,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 58ULL);
x86_l_ac0:
	/* 0xac0: je     aee <cil_to_wireguard+0xaee> */
	X86_SIM_X86_JCC(X86_CC_E, 0xac0, 0xaee, x86_l_aee);
x86_l_ac2:
	/* 0xac2: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_ac5:
	/* 0xac5: je     adf <cil_to_wireguard+0xadf> */
	X86_SIM_X86_JCC(X86_CC_E, 0xac5, 0xadf, x86_l_adf);
x86_l_ac7:
	/* 0xac7: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_aca:
	/* 0xaca: jne    af7 <cil_to_wireguard+0xaf7> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xaca, 0xaf7, x86_l_af7);
x86_l_acc:
	/* 0xacc: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ace:
	/* 0xace: mov    ebp,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 16ULL);
x86_l_ad3:
	/* 0xad3: jmp    afc <cil_to_wireguard+0xafc> */
	X86_SIM_X86_JMP(0xad3, 0xafc, x86_l_afc);
x86_l_ad5:
	/* 0xad5: mov    ecx,0x99 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 153ULL);
x86_l_ada:
	/* 0xada: jmp    35d <cil_to_wireguard+0x35d> */
	X86_SIM_X86_JMP(0xada, 0x35d, x86_l_35d);
x86_l_adf:
	/* 0xadf: mov    r14d,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 32ULL);
x86_l_ae5:
	/* 0xae5: mov    ebp,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 6ULL);
x86_l_aea:
	/* 0xaea: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_aec:
	/* 0xaec: jmp    aff <cil_to_wireguard+0xaff> */
	X86_SIM_X86_JMP(0xaec, 0xaff, x86_l_aff);
x86_l_aee:
	/* 0xaee: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_af0:
	/* 0xaf0: mov    ebp,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 2ULL);
x86_l_af5:
	/* 0xaf5: jmp    afc <cil_to_wireguard+0xafc> */
	X86_SIM_X86_JMP(0xaf5, 0xafc, x86_l_afc);
x86_l_af7:
	/* 0xaf7: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_af9:
	/* 0xaf9: mov    dil,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_8, 1ULL);
x86_l_afc:
	/* 0xafc: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_aff:
	/* 0xaff: movzx  edx,WORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 52ULL);
x86_l_b04:
	/* 0xb04: test   dx,dx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_16);
x86_l_b07:
	/* 0xb07: je     b99 <cil_to_wireguard+0xb99> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb07, 0xb99, x86_l_b99);
x86_l_b0d:
	/* 0xb0d: movzx  r8d,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_b13:
	/* 0xb13: mov    ecx,0x8e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 142ULL);
x86_l_b18:
	/* 0xb18: cmp    eax,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_b1b:
	/* 0xb1b: jg     b2c <cil_to_wireguard+0xb2c> */
	X86_SIM_X86_JCC(X86_CC_G, 0xb1b, 0xb2c, x86_l_b2c);
x86_l_b1d:
	/* 0xb1d: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b20:
	/* 0xb20: je     b99 <cil_to_wireguard+0xb99> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb20, 0xb99, x86_l_b99);
x86_l_b22:
	/* 0xb22: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_b25:
	/* 0xb25: je     b3a <cil_to_wireguard+0xb3a> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb25, 0xb3a, x86_l_b3a);
x86_l_b27:
	/* 0xb27: jmp    35d <cil_to_wireguard+0x35d> */
	X86_SIM_X86_JMP(0xb27, 0x35d, x86_l_35d);
x86_l_b2c:
	/* 0xb2c: cmp    eax,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 58ULL);
x86_l_b2f:
	/* 0xb2f: je     b99 <cil_to_wireguard+0xb99> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb2f, 0xb99, x86_l_b99);
x86_l_b31:
	/* 0xb31: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_b34:
	/* 0xb34: jne    35d <cil_to_wireguard+0x35d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb34, 0x35d, x86_l_35d);
x86_l_b3a:
	/* 0xb3a: cmp    dx,r8w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R8, X86_WIDTH_16);
x86_l_b3e:
	/* 0xb3e: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_b41:
	/* 0xb41: je     b99 <cil_to_wireguard+0xb99> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb41, 0xb99, x86_l_b99);
x86_l_b43:
	/* 0xb43: mov    DWORD PTR [rsp+0x20],r8d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b48:
	/* 0xb48: mov    DWORD PTR [rsp+0x2c],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_b4c:
	/* 0xb4c: mov    WORD PTR [rsp+0x10],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b51:
	/* 0xb51: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_b56:
	/* 0xb56: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b5b:
	/* 0xb5b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_b5e:
	/* 0xb5e: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_b63:
	/* 0xb63: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b66:
	/* 0xb66: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b68:
	/* 0xb68: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b6a:
	/* 0xb6a: js     bce <cil_to_wireguard+0xbce> */
	X86_SIM_X86_JCC(X86_CC_S, 0xb6a, 0xbce, x86_l_bce);
x86_l_b6c:
	/* 0xb6c: movzx  ecx,WORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_b71:
	/* 0xb71: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_b76:
	/* 0xb76: lea    esi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_b79:
	/* 0xb79: mov    r8d,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R14, X86_WIDTH_32);
x86_l_b7c:
	/* 0xb7c: or     r8d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_b80:
	/* 0xb80: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_b85:
	/* 0xb85: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_b88:
	/* 0xb88: mov    edx,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b8c:
	/* 0xb8c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b8e:
	/* 0xb8e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b90:
	/* 0xb90: js     bc4 <cil_to_wireguard+0xbc4> */
	X86_SIM_X86_JCC(X86_CC_S, 0xb90, 0xbc4, x86_l_bc4);
x86_l_b92:
	/* 0xb92: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_b95:
	/* 0xb95: mov    edi,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_b99:
	/* 0xb99: test   dil,dil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDI, X86_RDI, X86_WIDTH_8);
x86_l_b9c:
	/* 0xb9c: jne    d17 <cil_to_wireguard+0xd17> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb9c, 0xd17, x86_l_d17);
x86_l_ba2:
	/* 0xba2: add    ebp,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_ba4:
	/* 0xba4: or     r14d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_OR, 16ULL);
x86_l_ba8:
	/* 0xba8: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_bad:
	/* 0xbad: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_bb0:
	/* 0xbb0: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_bb2:
	/* 0xbb2: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bb4:
	/* 0xbb4: mov    ecx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_32);
x86_l_bb7:
	/* 0xbb7: mov    r8d,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R14, X86_WIDTH_32);
x86_l_bba:
	/* 0xbba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bbc:
	/* 0xbbc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_bbe:
	/* 0xbbe: jns    d17 <cil_to_wireguard+0xd17> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xbbe, 0xd17, x86_l_d17);
x86_l_bc4:
	/* 0xbc4: mov    ecx,0x9a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 154ULL);
x86_l_bc9:
	/* 0xbc9: jmp    35d <cil_to_wireguard+0x35d> */
	X86_SIM_X86_JMP(0xbc9, 0x35d, x86_l_35d);
x86_l_bce:
	/* 0xbce: mov    ecx,0x8d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 141ULL);
x86_l_bd3:
	/* 0xbd3: jmp    35d <cil_to_wireguard+0x35d> */
	X86_SIM_X86_JMP(0xbd3, 0x35d, x86_l_35d);
x86_l_bd8:
	/* 0xbd8: mov    rbp,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RSI, X86_WIDTH_64);
x86_l_bdb:
	/* 0xbdb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_be0:
	/* 0xbe0: mov    rdi,QWORD PTR [rip+0x2f3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv4_frag_datagrams)));
x86_l_be7:
	/* 0xbe7: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_bec:
	/* 0xbec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bee:
	/* 0xbee: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_bf1:
	/* 0xbf1: je     c08 <cil_to_wireguard+0xc08> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbf1, 0xc08, x86_l_c08);
x86_l_bf3:
	/* 0xbf3: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bf5:
	/* 0xbf5: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bf9:
	/* 0xbf9: jmp    56f <cil_to_wireguard+0x56f> */
	X86_SIM_X86_JMP(0xbf9, 0x56f, x86_l_56f);
x86_l_bfe:
	/* 0xbfe: mov    ecx,0x9d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 157ULL);
x86_l_c03:
	/* 0xc03: jmp    35d <cil_to_wireguard+0x35d> */
	X86_SIM_X86_JMP(0xc03, 0x35d, x86_l_35d);
x86_l_c08:
	/* 0xc08: mov    ecx,0xaf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 175ULL);
x86_l_c0d:
	/* 0xc0d: jmp    35d <cil_to_wireguard+0x35d> */
	X86_SIM_X86_JMP(0xc0d, 0x35d, x86_l_35d);
x86_l_c12:
	/* 0xc12: mov    QWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_c1b:
	/* 0xc1b: mov    QWORD PTR [rsp+0x18],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c20:
	/* 0xc20: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_c25:
	/* 0xc25: mov    rdi,QWORD PTR [rip+0x2f3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_c2c:
	/* 0xc2c: lea    rsi,[rsp+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_c31:
	/* 0xc31: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c36:
	/* 0xc36: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c38:
	/* 0xc38: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c3a:
	/* 0xc3a: jmp    56f <cil_to_wireguard+0x56f> */
	X86_SIM_X86_JMP(0xc3a, 0x56f, x86_l_56f);
x86_l_c3f:
	/* 0xc3f: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_c45:
	/* 0xc45: jmp    780 <cil_to_wireguard+0x780> */
	X86_SIM_X86_JMP(0xc45, 0x780, x86_l_780);
x86_l_c4a:
	/* 0xc4a: mov    ebp,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_c4f:
	/* 0xc4f: cmp    BYTE PTR [rsp+0x2c],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 188978561030ULL);
x86_l_c54:
	/* 0xc54: jne    c8a <cil_to_wireguard+0xc8a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xc54, 0xc8a, x86_l_c8a);
x86_l_c56:
	/* 0xc56: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_c59:
	/* 0xc59: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_c5b:
	/* 0xc5b: shr    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_c5e:
	/* 0xc5e: and    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_c61:
	/* 0xc61: or     ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_OR);
x86_l_c63:
	/* 0xc63: mov    WORD PTR [r14+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_c68:
	/* 0xc68: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c6a:
	/* 0xc6a: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_c6f:
	/* 0xc6f: mov    ebp,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 21600ULL);
x86_l_c74:
	/* 0xc74: cmove  ebp,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_c77:
	/* 0xc77: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c7b:
	/* 0xc7b: je     c8a <cil_to_wireguard+0xc8a> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc7b, 0xc8a, x86_l_c8a);
x86_l_c7d:
	/* 0xc7d: mov    rax,QWORD PTR [rip+0x2f3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_c84:
	/* 0xc84: imul   ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_c87:
	/* 0xc87: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_c8a:
	/* 0xc8a: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_c8e:
	/* 0xc8e: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c92:
	/* 0xc92: je     ca3 <cil_to_wireguard+0xca3> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc92, 0xca3, x86_l_ca3);
x86_l_c94:
	/* 0xc94: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_c99:
	/* 0xc99: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c9b:
	/* 0xc9b: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_c9d:
	/* 0xc9d: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_ca1:
	/* 0xca1: jmp    cc6 <cil_to_wireguard+0xcc6> */
	X86_SIM_X86_JMP(0xca1, 0xcc6, x86_l_cc6);
x86_l_ca3:
	/* 0xca3: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_ca8:
	/* 0xca8: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_caa:
	/* 0xcaa: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_cac:
	/* 0xcac: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_cb0:
	/* 0xcb0: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_cba:
	/* 0xcba: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_cbd:
	/* 0xcbd: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_cc2:
	/* 0xcc2: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_cc6:
	/* 0xcc6: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_cc8:
	/* 0xcc8: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_ccb:
	/* 0xccb: mov    DWORD PTR [r14+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ccf:
	/* 0xccf: movzx  ecx,BYTE PTR [r14+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_cd4:
	/* 0xcd4: mov    edx,DWORD PTR [r14+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_cd8:
	/* 0xcd8: and    r12b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_cdc:
	/* 0xcdc: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ce0:
	/* 0xce0: je     cf3 <cil_to_wireguard+0xcf3> */
	X86_SIM_X86_JCC(X86_CC_E, 0xce0, 0xcf3, x86_l_cf3);
x86_l_ce2:
	/* 0xce2: mov    rsi,QWORD PTR [rip+0x2f3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_ce9:
	/* 0xce9: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ceb:
	/* 0xceb: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_cee:
	/* 0xcee: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_cf1:
	/* 0xcf1: jmp    cf8 <cil_to_wireguard+0xcf8> */
	X86_SIM_X86_JMP(0xcf1, 0xcf8, x86_l_cf8);
x86_l_cf3:
	/* 0xcf3: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_cf8:
	/* 0xcf8: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_cfa:
	/* 0xcfa: or     r12b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_cfd:
	/* 0xcfd: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_cff:
	/* 0xcff: jb     d06 <cil_to_wireguard+0xd06> */
	X86_SIM_X86_JCC(X86_CC_B, 0xcff, 0xd06, x86_l_d06);
x86_l_d01:
	/* 0xd01: cmp    cl,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R12, X86_WIDTH_8);
x86_l_d04:
	/* 0xd04: je     d17 <cil_to_wireguard+0xd17> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd04, 0xd17, x86_l_d17);
x86_l_d06:
	/* 0xd06: mov    BYTE PTR [r14+0x2b],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_d0a:
	/* 0xd0a: mov    DWORD PTR [r14+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_d0e:
	/* 0xd0e: mov    rax,QWORD PTR [rip+0x2f3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_d15:
	/* 0xd15: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d17:
	/* 0xd17: mov    rax,QWORD PTR [rip+0x2f3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_interface_ifindex)));
x86_l_d1e:
	/* 0xd1e: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d20:
	/* 0xd20: mov    ebx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_d23:
	/* 0xd23: movabs rax,0x701760200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 30089282048ULL);
x86_l_d2d:
	/* 0xd2d: add    rax,0x7000d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 458765ULL);
x86_l_d33:
	/* 0xd33: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d37:
	/* 0xd37: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d3c:
	/* 0xd3c: mov    rdi,QWORD PTR [rip+0x2f3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_d43:
	/* 0xd43: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_d46:
	/* 0xd46: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d48:
	/* 0xd48: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d4b:
	/* 0xd4b: je     d56 <cil_to_wireguard+0xd56> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd4b, 0xd56, x86_l_d56);
x86_l_d4d:
	/* 0xd4d: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_d50:
	/* 0xd50: add    QWORD PTR [rax+0x8],rbx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_d54:
	/* 0xd54: jmp    d7c <cil_to_wireguard+0xd7c> */
	X86_SIM_X86_JMP(0xd54, 0xd7c, x86_l_d7c);
x86_l_d56:
	/* 0xd56: mov    QWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_d5f:
	/* 0xd5f: mov    QWORD PTR [rsp+0x18],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d64:
	/* 0xd64: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_d69:
	/* 0xd69: mov    rdi,QWORD PTR [rip+0x2f3] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_d70:
	/* 0xd70: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_d73:
	/* 0xd73: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d78:
	/* 0xd78: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d7a:
	/* 0xd7a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d7c:
	/* 0xd7c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d7e:
	/* 0xd7e: add    rsp,0x68 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 104ULL);
x86_l_d82:
	/* 0xd82: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_d84:
	/* 0xd84: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_d85:
	/* 0xd85: jmp    d8a <cil_to_wireguard+0xd8a> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_d8a:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
