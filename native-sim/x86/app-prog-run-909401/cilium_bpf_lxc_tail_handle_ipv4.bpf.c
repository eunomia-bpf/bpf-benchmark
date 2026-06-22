extern char __config_debug_lb;
extern char __config_enable_conntrack_accounting;
extern char __config_enable_ipv4_fragments;
extern char __config_enable_jiffies;
extern char __config_enable_lrp;
extern char __config_enable_no_service_endpoints_routable;
extern char __config_endpoint_netns_cookie;
extern char __config_kernel_hz;
extern char __config_nodeport_port_max;
extern char __config_nodeport_port_min;
extern char __config_security_label;
extern char __config_service_loopback_ipv4;
extern char __config_trace_payload_len;
extern char cilium_calls;
extern char cilium_ct4_global;
extern char cilium_ct_any4_global;
extern char cilium_ipcache_v2;
extern char cilium_ipv4_frag_datagrams;
extern char cilium_lb4_affinity;
extern char cilium_lb4_backends_v3;
extern char cilium_lb4_services_v2;
extern char cilium_lb_affinity_match;
extern char cilium_metrics;
extern char cilium_nodeport_nat_buffer;
extern char cilium_skip_lb4;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int cilium_bpf_lxc_tail_handle_ipv4_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0xb8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 184ULL);
x86_l_a:
	/* 0xa: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: mov    eax,DWORD PTR [rdi+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_10:
	/* 0x10: sub    eax,DWORD PTR [rdi+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RDI, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_13:
	/* 0x13: cmp    eax,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 34ULL);
x86_l_16:
	/* 0x16: jae    25 <tail_handle_ipv4+0x25> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x16, 0x25, x86_l_25);
x86_l_18:
	/* 0x18: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a:
	/* 0x1a: mov    r14d,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4294967162ULL);
x86_l_20:
	/* 0x20: jmp    4fe <tail_handle_ipv4+0x4fe> */
	X86_SIM_X86_JMP(0x20, 0x4fe, x86_l_4fe);
x86_l_25:
	/* 0x25: mov    rax,QWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_2c:
	/* 0x2c: mov    r13,QWORD PTR [rip+0xa857] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&__config_enable_ipv4_fragments)));
x86_l_33:
	/* 0x33: movzx  esi,BYTE PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_38:
	/* 0x38: movzx  ecx,WORD PTR [rax+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 20ULL);
x86_l_3c:
	/* 0x3c: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_3e:
	/* 0x3e: and    edx,0xff3f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 65343ULL);
x86_l_44:
	/* 0x44: test   sil,sil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_8);
x86_l_47:
	/* 0x47: je     1af <tail_handle_ipv4+0x1af> */
	X86_SIM_X86_JCC(X86_CC_E, 0x47, 0x1af, x86_l_1af);
x86_l_4d:
	/* 0x4d: movabs r9,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_64, 2199023255552ULL);
x86_l_57:
	/* 0x57: movabs r14,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 1099511627776ULL);
x86_l_61:
	/* 0x61: mov    WORD PTR [rsp+0x1c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 120259084288ULL);
x86_l_68:
	/* 0x68: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_70:
	/* 0x70: mov    DWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_78:
	/* 0x78: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_81:
	/* 0x81: movzx  edi,WORD PTR [rax+0x12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18ULL);
x86_l_85:
	/* 0x85: movzx  esi,BYTE PTR [rax+0x17] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 23ULL);
x86_l_89:
	/* 0x89: mov    r8,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RSI, X86_WIDTH_64);
x86_l_8c:
	/* 0x8c: shl    r8,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_90:
	/* 0x90: or     r8,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDI, X86_WIDTH_64, X86_ALU_OR);
x86_l_93:
	/* 0x93: lea    rdi,[r8+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_97:
	/* 0x97: test   dx,dx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_16);
x86_l_9a:
	/* 0x9a: cmove  rdi,r8 */
	X86_SIM_L_EXEC_CMOV(X86_RDI, X86_R8, X86_WIDTH_64, X86_CC_E);
x86_l_9e:
	/* 0x9e: lea    r12,[rdi+r9*1] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_R9, 0), 0ULL);
x86_l_a2:
	/* 0xa2: test   ecx,0xff1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_32, 65311ULL);
x86_l_a8:
	/* 0xa8: cmove  r12,rdi */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RDI, X86_WIDTH_64, X86_CC_E);
x86_l_ac:
	/* 0xac: mov    edx,DWORD PTR [rax+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_af:
	/* 0xaf: mov    BYTE PTR [rsp+0x1c],sil */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_b4:
	/* 0xb4: mov    ecx,DWORD PTR [rax+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_b7:
	/* 0xb7: mov    DWORD PTR [rsp+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_bb:
	/* 0xbb: mov    eax,DWORD PTR [rax+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_be:
	/* 0xbe: mov    DWORD PTR [rsp+0x14],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_c2:
	/* 0xc2: cmp    esi,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_c5:
	/* 0xc5: je     d0 <tail_handle_ipv4+0xd0> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc5, 0xd0, x86_l_d0);
x86_l_c7:
	/* 0xc7: cmp    esi,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 6ULL);
x86_l_ca:
	/* 0xca: jne    387 <tail_handle_ipv4+0x387> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xca, 0x387, x86_l_387);
x86_l_d0:
	/* 0xd0: and    edx,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_d3:
	/* 0xd3: lea    rbp,[rdx*4+0xe] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 2), 14ULL);
x86_l_db:
	/* 0xdb: lea    r15,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_e0:
	/* 0xe0: cmp    BYTE PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e5:
	/* 0xe5: je     1c7 <tail_handle_ipv4+0x1c7> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe5, 0x1c7, x86_l_1c7);
x86_l_eb:
	/* 0xeb: mov    DWORD PTR [rsp+0x28],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_ef:
	/* 0xef: mov    DWORD PTR [rsp+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_f3:
	/* 0xf3: mov    WORD PTR [rsp+0x30],r12w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f9:
	/* 0xf9: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_fc:
	/* 0xfc: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_100:
	/* 0x100: mov    BYTE PTR [rsp+0x32],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 50ULL);
x86_l_104:
	/* 0x104: mov    BYTE PTR [rsp+0x33],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 219043332096ULL);
x86_l_109:
	/* 0x109: test   r12,r9 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R9, X86_WIDTH_64);
x86_l_10c:
	/* 0x10c: jne    afc <tail_handle_ipv4+0xafc> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x10c, 0xafc, x86_l_afc);
x86_l_112:
	/* 0x112: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_117:
	/* 0x117: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_11a:
	/* 0x11a: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_11c:
	/* 0x11c: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_11f:
	/* 0x11f: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_124:
	/* 0x124: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_126:
	/* 0x126: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_128:
	/* 0x128: js     4f6 <tail_handle_ipv4+0x4f6> */
	X86_SIM_X86_JCC(X86_CC_S, 0x128, 0x4f6, x86_l_4f6);
x86_l_12e:
	/* 0x12e: mov    QWORD PTR [rsp+0xa8],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_136:
	/* 0x136: test   r12,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R14, X86_WIDTH_64);
x86_l_139:
	/* 0x139: je     1fc <tail_handle_ipv4+0x1fc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x139, 0x1fc, x86_l_1fc);
x86_l_13f:
	/* 0x13f: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_144:
	/* 0x144: mov    rdi,QWORD PTR [rip+0xa857] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv4_frag_datagrams)));
x86_l_14b:
	/* 0x14b: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_150:
	/* 0x150: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_153:
	/* 0x153: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_155:
	/* 0x155: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_157:
	/* 0x157: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_159:
	/* 0x159: je     1fc <tail_handle_ipv4+0x1fc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x159, 0x1fc, x86_l_1fc);
x86_l_15f:
	/* 0x15f: mov    r15d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_163:
	/* 0x163: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_16c:
	/* 0x16c: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_175:
	/* 0x175: movabs rax,0x6b0085020a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 459570217482ULL);
x86_l_17f:
	/* 0x17f: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_187:
	/* 0x187: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_18c:
	/* 0x18c: mov    rdi,QWORD PTR [rip+0xa857] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_193:
	/* 0x193: lea    rsi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_19b:
	/* 0x19b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19d:
	/* 0x19d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a0:
	/* 0x1a0: je     b4a <tail_handle_ipv4+0xb4a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a0, 0xb4a, x86_l_b4a);
x86_l_1a6:
	/* 0x1a6: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1a9:
	/* 0x1a9: add    QWORD PTR [rax+0x8],r15 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1ad:
	/* 0x1ad: jmp    1fc <tail_handle_ipv4+0x1fc> */
	X86_SIM_X86_JMP(0x1ad, 0x1fc, x86_l_1fc);
x86_l_1af:
	/* 0x1af: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b1:
	/* 0x1b1: mov    r14d,0xffffff63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4294967139ULL);
x86_l_1b7:
	/* 0x1b7: test   dx,dx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_16);
x86_l_1ba:
	/* 0x1ba: jne    4fe <tail_handle_ipv4+0x4fe> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1ba, 0x4fe, x86_l_4fe);
x86_l_1c0:
	/* 0x1c0: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c2:
	/* 0x1c2: jmp    4d <tail_handle_ipv4+0x4d> */
	X86_SIM_X86_JMP(0x1c2, 0x4d, x86_l_4d);
x86_l_1c7:
	/* 0x1c7: mov    QWORD PTR [rsp+0xa8],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1cf:
	/* 0x1cf: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d1:
	/* 0x1d1: test   r12,r9 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R9, X86_WIDTH_64);
x86_l_1d4:
	/* 0x1d4: jne    b27 <tail_handle_ipv4+0xb27> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1d4, 0xb27, x86_l_b27);
x86_l_1da:
	/* 0x1da: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1df:
	/* 0x1df: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1e2:
	/* 0x1e2: mov    rsi,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1ea:
	/* 0x1ea: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1ed:
	/* 0x1ed: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1f2:
	/* 0x1f2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f4:
	/* 0x1f4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1f6:
	/* 0x1f6: js     3c9 <tail_handle_ipv4+0x3c9> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1f6, 0x3c9, x86_l_3c9);
x86_l_1fc:
	/* 0x1fc: movzx  eax,BYTE PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_201:
	/* 0x201: mov    BYTE PTR [rsp+0x48],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_205:
	/* 0x205: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_209:
	/* 0x209: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_20d:
	/* 0x20d: movzx  eax,WORD PTR [rsp+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 26ULL);
x86_l_212:
	/* 0x212: mov    WORD PTR [rsp+0x44],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_217:
	/* 0x217: mov    WORD PTR [rsp+0x46],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 300647710720ULL);
x86_l_21e:
	/* 0x21e: mov    BYTE PTR [rsp+0x49],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 313532612608ULL);
x86_l_223:
	/* 0x223: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_228:
	/* 0x228: mov    rdi,QWORD PTR [rip+0xa857] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_services_v2)));
x86_l_22f:
	/* 0x22f: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_234:
	/* 0x234: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_236:
	/* 0x236: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_239:
	/* 0x239: je     282 <tail_handle_ipv4+0x282> */
	X86_SIM_X86_JCC(X86_CC_E, 0x239, 0x282, x86_l_282);
x86_l_23b:
	/* 0x23b: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_23e:
	/* 0x23e: test   BYTE PTR [rax+0x9],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38654705696ULL);
x86_l_242:
	/* 0x242: je     264 <tail_handle_ipv4+0x264> */
	X86_SIM_X86_JCC(X86_CC_E, 0x242, 0x264, x86_l_264);
x86_l_244:
	/* 0x244: mov    BYTE PTR [rsp+0x49],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 313532612609ULL);
x86_l_249:
	/* 0x249: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_24e:
	/* 0x24e: mov    rdi,QWORD PTR [rip+0xa857] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_services_v2)));
x86_l_255:
	/* 0x255: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_25a:
	/* 0x25a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25c:
	/* 0x25c: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_25f:
	/* 0x25f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_262:
	/* 0x262: je     282 <tail_handle_ipv4+0x282> */
	X86_SIM_X86_JCC(X86_CC_E, 0x262, 0x282, x86_l_282);
x86_l_264:
	/* 0x264: mov    rax,QWORD PTR [rip+0xa857] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_lrp)));
x86_l_26b:
	/* 0x26b: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_26e:
	/* 0x26e: movzx  ebp,BYTE PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_273:
	/* 0x273: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_277:
	/* 0x277: jne    2bd <tail_handle_ipv4+0x2bd> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x277, 0x2bd, x86_l_2bd);
x86_l_279:
	/* 0x279: mov    rax,QWORD PTR [rip+0xa857] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&cilium_ct4_global)));
x86_l_280:
	/* 0x280: jmp    2c4 <tail_handle_ipv4+0x2c4> */
	X86_SIM_X86_JMP(0x280, 0x2c4, x86_l_2c4);
x86_l_282:
	/* 0x282: mov    rax,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_287:
	/* 0x287: mov    rcx,QWORD PTR [rsp+0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_28c:
	/* 0x28c: mov    QWORD PTR [rsp+0x2e],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 46ULL);
x86_l_291:
	/* 0x291: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_296:
	/* 0x296: rol    QWORD PTR [rsp+0x28],0x20 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_64, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_ROL)), 171798691872ULL);
x86_l_29c:
	/* 0x29c: rol    DWORD PTR [rsp+0x30],0x10 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_32, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_ROL)), 206158430224ULL);
x86_l_2a1:
	/* 0x2a1: movzx  ebp,BYTE PTR [rsp+0x35] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 53ULL);
x86_l_2a6:
	/* 0x2a6: cmp    BYTE PTR [rsp+0x34],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 223338299398ULL);
x86_l_2ab:
	/* 0x2ab: jne    365 <tail_handle_ipv4+0x365> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2ab, 0x365, x86_l_365);
x86_l_2b1:
	/* 0x2b1: mov    rdi,QWORD PTR [rip+0xa857] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct4_global)));
x86_l_2b8:
	/* 0x2b8: jmp    36c <tail_handle_ipv4+0x36c> */
	X86_SIM_X86_JMP(0x2b8, 0x36c, x86_l_36c);
x86_l_2bd:
	/* 0x2bd: mov    rax,QWORD PTR [rip+0xa857] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&cilium_ct_any4_global)));
x86_l_2c4:
	/* 0x2c4: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_2c9:
	/* 0x2c9: movabs rcx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2199023255552ULL);
x86_l_2d3:
	/* 0x2d3: movzx  eax,BYTE PTR [rsp+0x1d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 29ULL);
x86_l_2d8:
	/* 0x2d8: mov    BYTE PTR [rsp+0x9c],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_2df:
	/* 0x2df: mov    eax,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2e3:
	/* 0x2e3: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_2eb:
	/* 0x2eb: movzx  eax,WORD PTR [r15+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_2f0:
	/* 0x2f0: mov    DWORD PTR [rsp+0x3c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_2f4:
	/* 0x2f4: mov    BYTE PTR [rsp+0x1d],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 124554051588ULL);
x86_l_2f9:
	/* 0x2f9: mov    DWORD PTR [rsp+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_304:
	/* 0x304: cmp    BYTE PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_309:
	/* 0x309: je     48a <tail_handle_ipv4+0x48a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x309, 0x48a, x86_l_48a);
x86_l_30f:
	/* 0x30f: and    r14,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_312:
	/* 0x312: je     48a <tail_handle_ipv4+0x48a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x312, 0x48a, x86_l_48a);
x86_l_318:
	/* 0x318: mov    r14d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_31c:
	/* 0x31c: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_325:
	/* 0x325: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_32e:
	/* 0x32e: movabs rax,0x6c03a50309 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 463917613833ULL);
x86_l_338:
	/* 0x338: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_33d:
	/* 0x33d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_342:
	/* 0x342: mov    rdi,QWORD PTR [rip+0xa857] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_349:
	/* 0x349: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_34e:
	/* 0x34e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_350:
	/* 0x350: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_353:
	/* 0x353: je     458 <tail_handle_ipv4+0x458> */
	X86_SIM_X86_JCC(X86_CC_E, 0x353, 0x458, x86_l_458);
x86_l_359:
	/* 0x359: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_35c:
	/* 0x35c: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_360:
	/* 0x360: jmp    480 <tail_handle_ipv4+0x480> */
	X86_SIM_X86_JMP(0x360, 0x480, x86_l_480);
x86_l_365:
	/* 0x365: mov    rdi,QWORD PTR [rip+0xa857] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct_any4_global)));
x86_l_36c:
	/* 0x36c: mov    BYTE PTR [rsp+0x35],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 227633266688ULL);
x86_l_371:
	/* 0x371: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_376:
	/* 0x376: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_37b:
	/* 0x37b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37d:
	/* 0x37d: mov    BYTE PTR [rsp+0x35],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 53ULL);
x86_l_382:
	/* 0x382: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_385:
	/* 0x385: je     3d4 <tail_handle_ipv4+0x3d4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x385, 0x3d4, x86_l_3d4);
x86_l_387:
	/* 0x387: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_389:
	/* 0x389: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_38c:
	/* 0x38c: mov    QWORD PTR [rbx+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_394:
	/* 0x394: shl    edx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_397:
	/* 0x397: movzx  eax,r13w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R13, X86_WIDTH_32, X86_WIDTH_16);
x86_l_39b:
	/* 0x39b: and    eax,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 1ULL);
x86_l_39e:
	/* 0x39e: or     eax,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_3a0:
	/* 0x3a0: mov    DWORD PTR [rbx+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3a3:
	/* 0x3a3: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_3a8:
	/* 0x3a8: mov    rsi,QWORD PTR [rip+0xa857] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_3af:
	/* 0x3af: mov    ebp,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 30ULL);
x86_l_3b4:
	/* 0x3b4: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_3b7:
	/* 0x3b7: mov    edx,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 30ULL);
x86_l_3bc:
	/* 0x3bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3be:
	/* 0x3be: mov    r14d,0xffffff74 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4294967156ULL);
x86_l_3c4:
	/* 0x3c4: jmp    4fe <tail_handle_ipv4+0x4fe> */
	X86_SIM_X86_JMP(0x3c4, 0x4fe, x86_l_4fe);
x86_l_3c9:
	/* 0x3c9: mov    r14d,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4294967161ULL);
x86_l_3cf:
	/* 0x3cf: jmp    4fe <tail_handle_ipv4+0x4fe> */
	X86_SIM_X86_JMP(0x3cf, 0x4fe, x86_l_4fe);
x86_l_3d4:
	/* 0x3d4: mov    eax,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_3d8:
	/* 0x3d8: mov    QWORD PTR [rsp+0x5e],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 403726925824ULL);
x86_l_3e1:
	/* 0x3e1: mov    WORD PTR [rsp+0x6e],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 472446402560ULL);
x86_l_3e8:
	/* 0x3e8: mov    QWORD PTR [rsp+0x66],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 438086664192ULL);
x86_l_3f1:
	/* 0x3f1: mov    DWORD PTR [rsp+0x58],0x40 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 377957122112ULL);
x86_l_3f9:
	/* 0x3f9: mov    BYTE PTR [rsp+0x5f],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 408021893121ULL);
x86_l_3fe:
	/* 0x3fe: mov    DWORD PTR [rsp+0x60],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_402:
	/* 0x402: mov    WORD PTR [rsp+0x5c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 395136991232ULL);
x86_l_409:
	/* 0x409: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_40e:
	/* 0x40e: mov    rdi,QWORD PTR [rip+0xa857] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipcache_v2)));
x86_l_415:
	/* 0x415: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_41a:
	/* 0x41a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41c:
	/* 0x41c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_41f:
	/* 0x41f: je     387 <tail_handle_ipv4+0x387> */
	X86_SIM_X86_JCC(X86_CC_E, 0x41f, 0x387, x86_l_387);
x86_l_425:
	/* 0x425: movbe  cx,WORD PTR [rsp+0x44] */
	X86_SIM_RUN_OP(X86_OP_MOVBE_LOAD, X86_RCX, X86_RSP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 68ULL);
x86_l_42c:
	/* 0x42c: mov    rdx,QWORD PTR [rip+0xa857] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_nodeport_port_min)));
x86_l_433:
	/* 0x433: cmp    cx,WORD PTR [rdx] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_436:
	/* 0x436: jb     448 <tail_handle_ipv4+0x448> */
	X86_SIM_X86_JCC(X86_CC_B, 0x436, 0x448, x86_l_448);
x86_l_438:
	/* 0x438: mov    rdx,QWORD PTR [rip+0xa857] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_nodeport_port_max)));
x86_l_43f:
	/* 0x43f: cmp    cx,WORD PTR [rdx] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_442:
	/* 0x442: jbe    641 <tail_handle_ipv4+0x641> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x442, 0x641, x86_l_641);
x86_l_448:
	/* 0x448: cmp    DWORD PTR [rax],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_44b:
	/* 0x44b: jne    387 <tail_handle_ipv4+0x387> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x44b, 0x387, x86_l_387);
x86_l_451:
	/* 0x451: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_453:
	/* 0x453: jmp    64f <tail_handle_ipv4+0x64f> */
	X86_SIM_X86_JMP(0x453, 0x64f, x86_l_64f);
x86_l_458:
	/* 0x458: mov    QWORD PTR [rsp+0x58],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122049ULL);
x86_l_461:
	/* 0x461: mov    QWORD PTR [rsp+0x60],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_466:
	/* 0x466: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_46b:
	/* 0x46b: mov    rdi,QWORD PTR [rip+0xa857] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_472:
	/* 0x472: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_477:
	/* 0x477: lea    rdx,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_47c:
	/* 0x47c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_47e:
	/* 0x47e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_480:
	/* 0x480: movabs rcx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2199023255552ULL);
x86_l_48a:
	/* 0x48a: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_48e:
	/* 0x48e: jne    5b9 <tail_handle_ipv4+0x5b9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x48e, 0x5b9, x86_l_5b9);
x86_l_494:
	/* 0x494: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_497:
	/* 0x497: and    rax,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_49a:
	/* 0x49a: jne    5b9 <tail_handle_ipv4+0x5b9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x49a, 0x5b9, x86_l_5b9);
x86_l_4a0:
	/* 0x4a0: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_4a5:
	/* 0x4a5: mov    rcx,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_4ad:
	/* 0x4ad: lea    esi,[rcx+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_4b0:
	/* 0x4b0: lea    rdx,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_4b8:
	/* 0x4b8: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_4bb:
	/* 0x4bb: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_4c0:
	/* 0x4c0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c2:
	/* 0x4c2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4c4:
	/* 0x4c4: js     4f6 <tail_handle_ipv4+0x4f6> */
	X86_SIM_X86_JCC(X86_CC_S, 0x4c4, 0x4f6, x86_l_4f6);
x86_l_4c6:
	/* 0x4c6: mov    r14d,DWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_4ce:
	/* 0x4ce: mov    eax,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_32);
x86_l_4d1:
	/* 0x4d1: and    eax,0x1200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4608ULL);
x86_l_4d6:
	/* 0x4d6: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4d9:
	/* 0x4d9: cmp    eax,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 512ULL);
x86_l_4de:
	/* 0x4de: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_4e1:
	/* 0x4e1: test   r14d,0x500 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R14, X86_WIDTH_32, 1280ULL);
x86_l_4e8:
	/* 0x4e8: jne    b3f <tail_handle_ipv4+0xb3f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4e8, 0xb3f, x86_l_b3f);
x86_l_4ee:
	/* 0x4ee: mov    r13b,al */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_8);
x86_l_4f1:
	/* 0x4f1: jmp    5c4 <tail_handle_ipv4+0x5c4> */
	X86_SIM_X86_JMP(0x4f1, 0x5c4, x86_l_5c4);
x86_l_4f6:
	/* 0x4f6: mov    r14d,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4294967161ULL);
x86_l_4fc:
	/* 0x4fc: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4fe:
	/* 0x4fe: mov    rax,QWORD PTR [rip+0xa857] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_security_label)));
x86_l_505:
	/* 0x505: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_507:
	/* 0x507: neg    r14d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_50a:
	/* 0x50a: shl    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_50d:
	/* 0x50d: movzx  ecx,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_510:
	/* 0x510: or     ecx,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R14, X86_WIDTH_32, X86_ALU_OR);
x86_l_513:
	/* 0x513: mov    DWORD PTR [rbx+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_516:
	/* 0x516: mov    DWORD PTR [rbx+0x2c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561024ULL);
x86_l_51d:
	/* 0x51d: mov    DWORD PTR [rbx+0x30],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_520:
	/* 0x520: movabs rax,0x6cf020200000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 490613092019863552ULL);
x86_l_52a:
	/* 0x52a: mov    QWORD PTR [rbx+0x34],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_52e:
	/* 0x52e: mov    r15d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_532:
	/* 0x532: movabs rax,0x206cf0200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8704164352ULL);
x86_l_53c:
	/* 0x53c: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_541:
	/* 0x541: mov    BYTE PTR [rsp+0x28],r14b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_546:
	/* 0x546: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_54b:
	/* 0x54b: mov    rdi,QWORD PTR [rip+0xa857] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_552:
	/* 0x552: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_557:
	/* 0x557: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_559:
	/* 0x559: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_55c:
	/* 0x55c: je     567 <tail_handle_ipv4+0x567> */
	X86_SIM_X86_JCC(X86_CC_E, 0x55c, 0x567, x86_l_567);
x86_l_55e:
	/* 0x55e: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_561:
	/* 0x561: add    QWORD PTR [rax+0x8],r15 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_565:
	/* 0x565: jmp    58f <tail_handle_ipv4+0x58f> */
	X86_SIM_X86_JMP(0x565, 0x58f, x86_l_58f);
x86_l_567:
	/* 0x567: mov    QWORD PTR [rsp+0x58],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122049ULL);
x86_l_570:
	/* 0x570: mov    QWORD PTR [rsp+0x60],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_575:
	/* 0x575: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_57a:
	/* 0x57a: mov    rdi,QWORD PTR [rip+0xa857] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_581:
	/* 0x581: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_586:
	/* 0x586: lea    rdx,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_58b:
	/* 0x58b: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_58d:
	/* 0x58d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_58f:
	/* 0x58f: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_594:
	/* 0x594: mov    rsi,QWORD PTR [rip+0xa857] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_59b:
	/* 0x59b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_59e:
	/* 0x59e: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_5a3:
	/* 0x5a3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a5:
	/* 0x5a5: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_5aa:
	/* 0x5aa: add    rsp,0xb8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 184ULL);
x86_l_5b1:
	/* 0x5b1: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_5b3:
	/* 0x5b3: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_5b4:
	/* 0x5b4: jmp    142e <tail_handle_ipv4+0x142e> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_5b9:
	/* 0x5b9: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5bc:
	/* 0x5bc: mov    r14d,DWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_5c4:
	/* 0x5c4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5c9:
	/* 0x5c9: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5ce:
	/* 0x5ce: mov    rdi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_5d3:
	/* 0x5d3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5d5:
	/* 0x5d5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5d8:
	/* 0x5d8: je     c9b <tail_handle_ipv4+0xc9b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5d8, 0xc9b, x86_l_c9b);
x86_l_5de:
	/* 0x5de: mov    ecx,DWORD PTR [rsp+0x3c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_5e2:
	/* 0x5e2: cmp    WORD PTR [rax+0x26],cx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_5e6:
	/* 0x5e6: jne    c9b <tail_handle_ipv4+0xc9b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x5e6, 0xc9b, x86_l_c9b);
x86_l_5ec:
	/* 0x5ec: mov    ecx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_32);
x86_l_5ef:
	/* 0x5ef: and    ecx,0x200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 512ULL);
x86_l_5f5:
	/* 0x5f5: mov    DWORD PTR [rsp+0x38],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_5f9:
	/* 0x5f9: mov    DWORD PTR [rsp+0x20],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5fe:
	/* 0x5fe: mov    DWORD PTR [rsp+0xc],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_603:
	/* 0x603: je     717 <tail_handle_ipv4+0x717> */
	X86_SIM_X86_JCC(X86_CC_E, 0x603, 0x717, x86_l_717);
x86_l_609:
	/* 0x609: test   BYTE PTR [rax+0x24],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 154618822659ULL);
x86_l_60d:
	/* 0x60d: je     717 <tail_handle_ipv4+0x717> */
	X86_SIM_X86_JCC(X86_CC_E, 0x60d, 0x717, x86_l_717);
x86_l_613:
	/* 0x613: mov    rcx,QWORD PTR [rip+0xa85a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_61a:
	/* 0x61a: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_61d:
	/* 0x61d: je     6c7 <tail_handle_ipv4+0x6c7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x61d, 0x6c7, x86_l_6c7);
x86_l_623:
	/* 0x623: mov    rdx,QWORD PTR [rip+0xa85a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_62a:
	/* 0x62a: mov    r14d,DWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_62d:
	/* 0x62d: lea    edx,[r14+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_631:
	/* 0x631: shl    r14d,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHL, 5ULL);
x86_l_635:
	/* 0x635: sub    r14d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_638:
	/* 0x638: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_63c:
	/* 0x63c: jmp    6cd <tail_handle_ipv4+0x6cd> */
	X86_SIM_X86_JMP(0x63c, 0x6cd, x86_l_6cd);
x86_l_641:
	/* 0x641: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_643:
	/* 0x643: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_646:
	/* 0x646: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_649:
	/* 0x649: jne    8f4 <tail_handle_ipv4+0x8f4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x649, 0x8f4, x86_l_8f4);
x86_l_64f:
	/* 0x64f: mov    DWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_657:
	/* 0x657: mov    WORD PTR [rsp+0x46],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 300647710720ULL);
x86_l_65e:
	/* 0x65e: mov    BYTE PTR [rsp+0x49],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 313532612608ULL);
x86_l_663:
	/* 0x663: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_668:
	/* 0x668: mov    rdi,QWORD PTR [rip+0xa85a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_services_v2)));
x86_l_66f:
	/* 0x66f: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_674:
	/* 0x674: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_676:
	/* 0x676: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_679:
	/* 0x679: je     387 <tail_handle_ipv4+0x387> */
	X86_SIM_X86_JCC(X86_CC_E, 0x679, 0x387, x86_l_387);
x86_l_67f:
	/* 0x67f: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_682:
	/* 0x682: test   BYTE PTR [rax+0x9],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38654705696ULL);
x86_l_686:
	/* 0x686: je     6ac <tail_handle_ipv4+0x6ac> */
	X86_SIM_X86_JCC(X86_CC_E, 0x686, 0x6ac, x86_l_6ac);
x86_l_688:
	/* 0x688: mov    BYTE PTR [rsp+0x49],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 313532612609ULL);
x86_l_68d:
	/* 0x68d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_692:
	/* 0x692: mov    rdi,QWORD PTR [rip+0xa85a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_services_v2)));
x86_l_699:
	/* 0x699: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_69e:
	/* 0x69e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6a0:
	/* 0x6a0: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_6a3:
	/* 0x6a3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_6a6:
	/* 0x6a6: je     387 <tail_handle_ipv4+0x387> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6a6, 0x387, x86_l_387);
x86_l_6ac:
	/* 0x6ac: movzx  eax,BYTE PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_6b1:
	/* 0x6b1: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_6b4:
	/* 0x6b4: je     89c <tail_handle_ipv4+0x89c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6b4, 0x89c, x86_l_89c);
x86_l_6ba:
	/* 0x6ba: test   al,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 2ULL);
x86_l_6bc:
	/* 0x6bc: je     387 <tail_handle_ipv4+0x387> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6bc, 0x387, x86_l_387);
x86_l_6c2:
	/* 0x6c2: jmp    8a4 <tail_handle_ipv4+0x8a4> */
	X86_SIM_X86_JMP(0x6c2, 0x8a4, x86_l_8a4);
x86_l_6c7:
	/* 0x6c7: mov    r14d,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 30ULL);
x86_l_6cd:
	/* 0x6cd: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_6d0:
	/* 0x6d0: add    r14d,DWORD PTR [rax+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_6d4:
	/* 0x6d4: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6d7:
	/* 0x6d7: je     6e8 <tail_handle_ipv4+0x6e8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6d7, 0x6e8, x86_l_6e8);
x86_l_6d9:
	/* 0x6d9: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_6de:
	/* 0x6de: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6e0:
	/* 0x6e0: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_6e2:
	/* 0x6e2: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_6e6:
	/* 0x6e6: jmp    70b <tail_handle_ipv4+0x70b> */
	X86_SIM_X86_JMP(0x6e6, 0x70b, x86_l_70b);
x86_l_6e8:
	/* 0x6e8: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_6ed:
	/* 0x6ed: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6ef:
	/* 0x6ef: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_6f1:
	/* 0x6f1: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_6f5:
	/* 0x6f5: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_6ff:
	/* 0x6ff: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_702:
	/* 0x702: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_707:
	/* 0x707: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_70b:
	/* 0x70b: cmp    rax,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_70e:
	/* 0x70e: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_711:
	/* 0x711: jae    c9b <tail_handle_ipv4+0xc9b> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x711, 0xc9b, x86_l_c9b);
x86_l_717:
	/* 0x717: mov    ecx,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_71a:
	/* 0x71a: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_71c:
	/* 0x71c: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_71e:
	/* 0x71e: test   dl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_8, 3ULL);
x86_l_721:
	/* 0x721: je     82c <tail_handle_ipv4+0x82c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x721, 0x82c, x86_l_82c);
x86_l_727:
	/* 0x727: mov    rsi,QWORD PTR [rip+0xa85a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_72e:
	/* 0x72e: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_731:
	/* 0x731: je     744 <tail_handle_ipv4+0x744> */
	X86_SIM_X86_JCC(X86_CC_E, 0x731, 0x744, x86_l_744);
x86_l_733:
	/* 0x733: mov    rdx,QWORD PTR [rip+0xa85a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_73a:
	/* 0x73a: imul   r14d,DWORD PTR [rdx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R14, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_73e:
	/* 0x73e: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_742:
	/* 0x742: jmp    74a <tail_handle_ipv4+0x74a> */
	X86_SIM_X86_JMP(0x742, 0x74a, x86_l_74a);
x86_l_744:
	/* 0x744: mov    r14d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 60ULL);
x86_l_74a:
	/* 0x74a: mov    r13d,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_74f:
	/* 0x74f: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_753:
	/* 0x753: jne    78c <tail_handle_ipv4+0x78c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x753, 0x78c, x86_l_78c);
x86_l_755:
	/* 0x755: mov    edx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_32);
x86_l_758:
	/* 0x758: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_75a:
	/* 0x75a: shr    edx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_75d:
	/* 0x75d: and    edx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_760:
	/* 0x760: or     ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_762:
	/* 0x762: mov    WORD PTR [rax+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_766:
	/* 0x766: test   cl,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 16ULL);
x86_l_769:
	/* 0x769: mov    ecx,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 60ULL);
x86_l_76e:
	/* 0x76e: mov    r14d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 21600ULL);
x86_l_774:
	/* 0x774: cmove  r14d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R14, X86_RCX, X86_WIDTH_32, X86_CC_E);
x86_l_778:
	/* 0x778: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_77b:
	/* 0x77b: je     78c <tail_handle_ipv4+0x78c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x77b, 0x78c, x86_l_78c);
x86_l_77d:
	/* 0x77d: mov    rcx,QWORD PTR [rip+0xa85a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_784:
	/* 0x784: imul   r14d,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_788:
	/* 0x788: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_78c:
	/* 0x78c: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_794:
	/* 0x794: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_798:
	/* 0x798: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_79b:
	/* 0x79b: je     7af <tail_handle_ipv4+0x7af> */
	X86_SIM_X86_JCC(X86_CC_E, 0x79b, 0x7af, x86_l_7af);
x86_l_79d:
	/* 0x79d: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_7a2:
	/* 0x7a2: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7a4:
	/* 0x7a4: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_7a6:
	/* 0x7a6: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_7a9:
	/* 0x7a9: shr    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_7ad:
	/* 0x7ad: jmp    7d2 <tail_handle_ipv4+0x7d2> */
	X86_SIM_X86_JMP(0x7ad, 0x7d2, x86_l_7d2);
x86_l_7af:
	/* 0x7af: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_7b4:
	/* 0x7b4: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7b6:
	/* 0x7b6: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_7b8:
	/* 0x7b8: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_7bc:
	/* 0x7bc: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_7c6:
	/* 0x7c6: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_7c9:
	/* 0x7c9: mulx   rcx,rcx,rcx */
	X86_SIM_L_EXEC_MULX(X86_RCX, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_7ce:
	/* 0x7ce: shr    rcx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_7d2:
	/* 0x7d2: add    r14d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_7d5:
	/* 0x7d5: mov    rax,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_7dd:
	/* 0x7dd: mov    DWORD PTR [rax+0x20],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7e1:
	/* 0x7e1: movzx  edx,BYTE PTR [rax+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_7e5:
	/* 0x7e5: mov    esi,DWORD PTR [rax+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7e8:
	/* 0x7e8: and    r13b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_7ec:
	/* 0x7ec: mov    rdi,QWORD PTR [rip+0xa85a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_7f3:
	/* 0x7f3: cmp    BYTE PTR [rdi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7f6:
	/* 0x7f6: je     809 <tail_handle_ipv4+0x809> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7f6, 0x809, x86_l_809);
x86_l_7f8:
	/* 0x7f8: mov    rdi,QWORD PTR [rip+0xa85a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_7ff:
	/* 0x7ff: mov    edi,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_801:
	/* 0x801: lea    edi,[rdi+rdi*4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_804:
	/* 0x804: shr    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_807:
	/* 0x807: jmp    80e <tail_handle_ipv4+0x80e> */
	X86_SIM_X86_JMP(0x807, 0x80e, x86_l_80e);
x86_l_809:
	/* 0x809: mov    edi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 5ULL);
x86_l_80e:
	/* 0x80e: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_810:
	/* 0x810: or     r13b,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_813:
	/* 0x813: cmp    edi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RCX, X86_WIDTH_32);
x86_l_815:
	/* 0x815: jb     81c <tail_handle_ipv4+0x81c> */
	X86_SIM_X86_JCC(X86_CC_B, 0x815, 0x81c, x86_l_81c);
x86_l_817:
	/* 0x817: cmp    dl,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R13, X86_WIDTH_8);
x86_l_81a:
	/* 0x81a: je     82c <tail_handle_ipv4+0x82c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x81a, 0x82c, x86_l_82c);
x86_l_81c:
	/* 0x81c: mov    BYTE PTR [rax+0x2a],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_820:
	/* 0x820: mov    DWORD PTR [rax+0x30],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_823:
	/* 0x823: mov    rcx,QWORD PTR [rip+0xa85a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_82a:
	/* 0x82a: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_82c:
	/* 0x82c: mov    rcx,QWORD PTR [rip+0xa85a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_833:
	/* 0x833: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_836:
	/* 0x836: je     845 <tail_handle_ipv4+0x845> */
	X86_SIM_X86_JCC(X86_CC_E, 0x836, 0x845, x86_l_845);
x86_l_838:
	/* 0x838: inc QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 16ULL);
x86_l_83d:
	/* 0x83d: mov    ecx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_840:
	/* 0x840: add QWORD PTR [rax+0x18],rcx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_845:
	/* 0x845: mov    ecx,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_849:
	/* 0x849: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_84c:
	/* 0x84c: je     867 <tail_handle_ipv4+0x867> */
	X86_SIM_X86_JCC(X86_CC_E, 0x84c, 0x867, x86_l_867);
x86_l_84e:
	/* 0x84e: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_851:
	/* 0x851: jne    860 <tail_handle_ipv4+0x860> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x851, 0x860, x86_l_860);
x86_l_853:
	/* 0x853: movzx  ecx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_857:
	/* 0x857: test   cl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_85a:
	/* 0x85a: jne    b7a <tail_handle_ipv4+0xb7a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x85a, 0xb7a, x86_l_b7a);
x86_l_860:
	/* 0x860: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_862:
	/* 0x862: jmp    9ca <tail_handle_ipv4+0x9ca> */
	X86_SIM_X86_JMP(0x862, 0x9ca, x86_l_9ca);
x86_l_867:
	/* 0x867: or     BYTE PTR [rax+0x24],0x3 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RAX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 154618822659ULL);
x86_l_86b:
	/* 0x86b: mov    rcx,QWORD PTR [rip+0xa85a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_872:
	/* 0x872: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_874:
	/* 0x874: mov    r13,QWORD PTR [rip+0xa85a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_87b:
	/* 0x87b: cmp    BYTE PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_880:
	/* 0x880: je     91f <tail_handle_ipv4+0x91f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x880, 0x91f, x86_l_91f);
x86_l_886:
	/* 0x886: mov    rcx,QWORD PTR [rip+0xa85a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_88d:
	/* 0x88d: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_88f:
	/* 0x88f: add    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_891:
	/* 0x891: lea    ebp,[rcx+rcx*4] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 0ULL);
x86_l_894:
	/* 0x894: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_897:
	/* 0x897: jmp    924 <tail_handle_ipv4+0x924> */
	X86_SIM_X86_JMP(0x897, 0x924, x86_l_924);
x86_l_89c:
	/* 0x89c: test   al,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 8ULL);
x86_l_89e:
	/* 0x89e: je     387 <tail_handle_ipv4+0x387> */
	X86_SIM_X86_JCC(X86_CC_E, 0x89e, 0x387, x86_l_387);
x86_l_8a4:
	/* 0x8a4: mov    DWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_8ac:
	/* 0x8ac: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_8b5:
	/* 0x8b5: mov    DWORD PTR [rsp+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_8c0:
	/* 0x8c0: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8c4:
	/* 0x8c4: mov    DWORD PTR [rsp+0x64],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 100ULL);
x86_l_8c8:
	/* 0x8c8: movzx  eax,WORD PTR [rsp+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 26ULL);
x86_l_8cd:
	/* 0x8cd: mov    WORD PTR [rsp+0x68],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_8d2:
	/* 0x8d2: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_8d7:
	/* 0x8d7: mov    rdi,QWORD PTR [rip+0xa85a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_nodeport_nat_buffer)));
x86_l_8de:
	/* 0x8de: lea    rsi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_8e6:
	/* 0x8e6: lea    rdx,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_8eb:
	/* 0x8eb: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8ed:
	/* 0x8ed: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8ef:
	/* 0x8ef: jmp    264 <tail_handle_ipv4+0x264> */
	X86_SIM_X86_JMP(0x8ef, 0x264, x86_l_264);
x86_l_8f4:
	/* 0x8f4: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_8f6:
	/* 0x8f6: and    edx,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_8f9:
	/* 0x8f9: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_8fc:
	/* 0x8fc: je     910 <tail_handle_ipv4+0x910> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8fc, 0x910, x86_l_910);
x86_l_8fe:
	/* 0x8fe: and    ecx,0xff000000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4278190080ULL);
x86_l_904:
	/* 0x904: cmp    ecx,0x2000000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 33554432ULL);
x86_l_90a:
	/* 0x90a: jne    387 <tail_handle_ipv4+0x387> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x90a, 0x387, x86_l_387);
x86_l_910:
	/* 0x910: test   BYTE PTR [rax+0x17],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 98784247816ULL);
x86_l_914:
	/* 0x914: jne    387 <tail_handle_ipv4+0x387> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x914, 0x387, x86_l_387);
x86_l_91a:
	/* 0x91a: jmp    64f <tail_handle_ipv4+0x64f> */
	X86_SIM_X86_JMP(0x91a, 0x64f, x86_l_64f);
x86_l_91f:
	/* 0x91f: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_924:
	/* 0x924: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_927:
	/* 0x927: shr    DWORD PTR [rsp+0x20],0x8 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_32, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_SHR)), 137438953480ULL);
x86_l_92c:
	/* 0x92c: cmp    BYTE PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_931:
	/* 0x931: je     945 <tail_handle_ipv4+0x945> */
	X86_SIM_X86_JCC(X86_CC_E, 0x931, 0x945, x86_l_945);
x86_l_933:
	/* 0x933: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_938:
	/* 0x938: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_93a:
	/* 0x93a: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_93c:
	/* 0x93c: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_93f:
	/* 0x93f: shr    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_943:
	/* 0x943: jmp    968 <tail_handle_ipv4+0x968> */
	X86_SIM_X86_JMP(0x943, 0x968, x86_l_968);
x86_l_945:
	/* 0x945: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_94a:
	/* 0x94a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_94c:
	/* 0x94c: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_94e:
	/* 0x94e: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_952:
	/* 0x952: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_95c:
	/* 0x95c: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_95f:
	/* 0x95f: mulx   rcx,rcx,rcx */
	X86_SIM_L_EXEC_MULX(X86_RCX, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_964:
	/* 0x964: shr    rcx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_968:
	/* 0x968: add    ebp,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_96a:
	/* 0x96a: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_96d:
	/* 0x96d: mov    DWORD PTR [r14+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_971:
	/* 0x971: movzx  esi,BYTE PTR [r14+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_976:
	/* 0x976: mov    edx,DWORD PTR [r14+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_97a:
	/* 0x97a: mov    edi,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_97e:
	/* 0x97e: and    dil,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_982:
	/* 0x982: mov    DWORD PTR [rsp+0x20],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_986:
	/* 0x986: cmp    BYTE PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_98b:
	/* 0x98b: je     99e <tail_handle_ipv4+0x99e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x98b, 0x99e, x86_l_99e);
x86_l_98d:
	/* 0x98d: mov    rdi,QWORD PTR [rip+0xa85a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_994:
	/* 0x994: mov    edi,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_996:
	/* 0x996: lea    edi,[rdi+rdi*4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_999:
	/* 0x999: shr    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_99c:
	/* 0x99c: jmp    9a3 <tail_handle_ipv4+0x9a3> */
	X86_SIM_X86_JMP(0x99c, 0x9a3, x86_l_9a3);
x86_l_99e:
	/* 0x99e: mov    edi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 5ULL);
x86_l_9a3:
	/* 0x9a3: add    edi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_9a5:
	/* 0x9a5: mov    r8d,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9aa:
	/* 0x9aa: or     r8b,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RSI, X86_WIDTH_8, X86_ALU_OR);
x86_l_9ad:
	/* 0x9ad: mov    dx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_16, 256ULL);
x86_l_9b1:
	/* 0x9b1: cmp    edi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RCX, X86_WIDTH_32);
x86_l_9b3:
	/* 0x9b3: jb     9ba <tail_handle_ipv4+0x9ba> */
	X86_SIM_X86_JCC(X86_CC_B, 0x9b3, 0x9ba, x86_l_9ba);
x86_l_9b5:
	/* 0x9b5: cmp    sil,r8b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_R8, X86_WIDTH_8);
x86_l_9b8:
	/* 0x9b8: je     9ca <tail_handle_ipv4+0x9ca> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9b8, 0x9ca, x86_l_9ca);
x86_l_9ba:
	/* 0x9ba: mov    BYTE PTR [rax+0x2a],r8b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R8, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_9be:
	/* 0x9be: mov    DWORD PTR [rax+0x30],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9c1:
	/* 0x9c1: mov    rcx,QWORD PTR [rip+0xa85a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_9c8:
	/* 0x9c8: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9ca:
	/* 0x9ca: test   BYTE PTR [rsp+0x1d],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 124554051586ULL);
x86_l_9cf:
	/* 0x9cf: jne    a32 <tail_handle_ipv4+0xa32> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x9cf, 0xa32, x86_l_a32);
x86_l_9d1:
	/* 0x9d1: movzx  ebp,WORD PTR [rax+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_9d5:
	/* 0x9d5: mov    eax,DWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9d8:
	/* 0x9d8: mov    ecx,DWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_9dc:
	/* 0x9dc: shr    ecx,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 6ULL);
x86_l_9df:
	/* 0x9df: movzx  r13d,dx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R13, X86_RDX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_9e3:
	/* 0x9e3: mov    DWORD PTR [rsp+0x38],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_9e7:
	/* 0x9e7: or     r13d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_9ea:
	/* 0x9ea: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_9ee:
	/* 0x9ee: mov    DWORD PTR [rsp+0x58],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_9f2:
	/* 0x9f2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_9f7:
	/* 0x9f7: mov    rdi,QWORD PTR [rip+0xa85a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_backends_v3)));
x86_l_9fe:
	/* 0x9fe: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_a03:
	/* 0xa03: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a05:
	/* 0xa05: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a08:
	/* 0xa08: je     a3f <tail_handle_ipv4+0xa3f> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa08, 0xa3f, x86_l_a3f);
x86_l_a0a:
	/* 0xa0a: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_a0d:
	/* 0xa0d: mov    DWORD PTR [rsp+0x3c],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_a11:
	/* 0xa11: cmp    BYTE PTR [rax+0x7],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30064771072ULL);
x86_l_a15:
	/* 0xa15: movabs rcx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2199023255552ULL);
x86_l_a1f:
	/* 0xa1f: je     1035 <tail_handle_ipv4+0x1035> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa1f, 0x1035, x86_l_1035);
x86_l_a25:
	/* 0xa25: cmp    WORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_a2b:
	/* 0xa2b: jne    a49 <tail_handle_ipv4+0xa49> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa2b, 0xa49, x86_l_a49);
x86_l_a2d:
	/* 0xa2d: jmp    1035 <tail_handle_ipv4+0x1035> */
	X86_SIM_X86_JMP(0xa2d, 0x1035, x86_l_1035);
x86_l_a32:
	/* 0xa32: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a34:
	/* 0xa34: mov    r14d,0xffffff5d */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4294967133ULL);
x86_l_a3a:
	/* 0xa3a: jmp    4fe <tail_handle_ipv4+0x4fe> */
	X86_SIM_X86_JMP(0xa3a, 0x4fe, x86_l_4fe);
x86_l_a3f:
	/* 0xa3f: mov    rax,QWORD PTR [rip+0xa85a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_a46:
	/* 0xa46: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_a49:
	/* 0xa49: cmp    WORD PTR [r15+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_a4f:
	/* 0xa4f: je     ed4 <tail_handle_ipv4+0xed4> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa4f, 0xed4, x86_l_ed4);
x86_l_a55:
	/* 0xa55: mov    ecx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_a5a:
	/* 0xa5a: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a5c:
	/* 0xa5c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a5e:
	/* 0xa5e: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_a60:
	/* 0xa60: movzx  ecx,WORD PTR [r15+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_a65:
	/* 0xa65: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a67:
	/* 0xa67: div    ecx */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_a69:
	/* 0xa69: inc    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_a6b:
	/* 0xa6b: mov    WORD PTR [rsp+0x46],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 70ULL);
x86_l_a70:
	/* 0xa70: mov    r14,QWORD PTR [rip+0xa85a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_a77:
	/* 0xa77: movzx  eax,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_a7b:
	/* 0xa7b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a80:
	/* 0xa80: mov    rdi,QWORD PTR [rip+0xa85a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_services_v2)));
x86_l_a87:
	/* 0xa87: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_a8c:
	/* 0xa8c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a8e:
	/* 0xa8e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a91:
	/* 0xa91: je     a97 <tail_handle_ipv4+0xa97> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa91, 0xa97, x86_l_a97);
x86_l_a93:
	/* 0xa93: mov    ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a95:
	/* 0xa95: jmp    a9b <tail_handle_ipv4+0xa9b> */
	X86_SIM_X86_JMP(0xa95, 0xa9b, x86_l_a9b);
x86_l_a97:
	/* 0xa97: movzx  eax,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_a9b:
	/* 0xa9b: mov    DWORD PTR [rsp+0x58],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_a9f:
	/* 0xa9f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_aa4:
	/* 0xaa4: mov    rdi,QWORD PTR [rip+0xa85a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_backends_v3)));
x86_l_aab:
	/* 0xaab: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_ab0:
	/* 0xab0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ab2:
	/* 0xab2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ab5:
	/* 0xab5: je     eca <tail_handle_ipv4+0xeca> */
	X86_SIM_X86_JCC(X86_CC_E, 0xab5, 0xeca, x86_l_eca);
x86_l_abb:
	/* 0xabb: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_abe:
	/* 0xabe: mov    DWORD PTR [rsp+0xc],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_ac2:
	/* 0xac2: movzx  ebp,WORD PTR [r15+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_ac7:
	/* 0xac7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_acc:
	/* 0xacc: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ad1:
	/* 0xad1: mov    rdi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_ad6:
	/* 0xad6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ad8:
	/* 0xad8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_adb:
	/* 0xadb: mov    DWORD PTR [rsp+0x3c],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_adf:
	/* 0xadf: je     aed <tail_handle_ipv4+0xaed> */
	X86_SIM_X86_JCC(X86_CC_E, 0xadf, 0xaed, x86_l_aed);
x86_l_ae1:
	/* 0xae1: mov    ecx,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_ae5:
	/* 0xae5: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ae9:
	/* 0xae9: mov    WORD PTR [rax+0x26],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_aed:
	/* 0xaed: movabs rcx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2199023255552ULL);
x86_l_af7:
	/* 0xaf7: jmp    1035 <tail_handle_ipv4+0x1035> */
	X86_SIM_X86_JMP(0xaf7, 0x1035, x86_l_1035);
x86_l_afc:
	/* 0xafc: mov    QWORD PTR [rsp+0xa8],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_b04:
	/* 0xb04: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b09:
	/* 0xb09: mov    rdi,QWORD PTR [rip+0xa85a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv4_frag_datagrams)));
x86_l_b10:
	/* 0xb10: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b15:
	/* 0xb15: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b17:
	/* 0xb17: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b1a:
	/* 0xb1a: je     b32 <tail_handle_ipv4+0xb32> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb1a, 0xb32, x86_l_b32);
x86_l_b1c:
	/* 0xb1c: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b1e:
	/* 0xb1e: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b22:
	/* 0xb22: jmp    1fc <tail_handle_ipv4+0x1fc> */
	X86_SIM_X86_JMP(0xb22, 0x1fc, x86_l_1fc);
x86_l_b27:
	/* 0xb27: mov    r14d,0xffffff63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4294967139ULL);
x86_l_b2d:
	/* 0xb2d: jmp    4fe <tail_handle_ipv4+0x4fe> */
	X86_SIM_X86_JMP(0xb2d, 0x4fe, x86_l_4fe);
x86_l_b32:
	/* 0xb32: mov    r14d,0xffffff51 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4294967121ULL);
x86_l_b38:
	/* 0xb38: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b3a:
	/* 0xb3a: jmp    4fe <tail_handle_ipv4+0x4fe> */
	X86_SIM_X86_JMP(0xb3a, 0x4fe, x86_l_4fe);
x86_l_b3f:
	/* 0xb3f: mov    r13d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 2ULL);
x86_l_b45:
	/* 0xb45: jmp    5c4 <tail_handle_ipv4+0x5c4> */
	X86_SIM_X86_JMP(0xb45, 0x5c4, x86_l_5c4);
x86_l_b4a:
	/* 0xb4a: mov    QWORD PTR [rsp+0x58],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122049ULL);
x86_l_b53:
	/* 0xb53: mov    QWORD PTR [rsp+0x60],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_b58:
	/* 0xb58: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_b5d:
	/* 0xb5d: mov    rdi,QWORD PTR [rip+0xa85a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_b64:
	/* 0xb64: lea    rsi,[rsp+0xa0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_b6c:
	/* 0xb6c: lea    rdx,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_b71:
	/* 0xb71: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b73:
	/* 0xb73: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b75:
	/* 0xb75: jmp    1fc <tail_handle_ipv4+0x1fc> */
	X86_SIM_X86_JMP(0xb75, 0x1fc, x86_l_1fc);
x86_l_b7a:
	/* 0xb7a: mov    WORD PTR [rax+0x2a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 180388626432ULL);
x86_l_b80:
	/* 0xb80: and    ecx,0xffec */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 65516ULL);
x86_l_b86:
	/* 0xb86: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_b89:
	/* 0xb89: mov    WORD PTR [rax+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_b8d:
	/* 0xb8d: mov    rax,QWORD PTR [rip+0xa85a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_b94:
	/* 0xb94: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b97:
	/* 0xb97: je     baa <tail_handle_ipv4+0xbaa> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb97, 0xbaa, x86_l_baa);
x86_l_b99:
	/* 0xb99: mov    rax,QWORD PTR [rip+0xa85a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_ba0:
	/* 0xba0: imul   r13d,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_ba4:
	/* 0xba4: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_ba8:
	/* 0xba8: jmp    bb0 <tail_handle_ipv4+0xbb0> */
	X86_SIM_X86_JMP(0xba8, 0xbb0, x86_l_bb0);
x86_l_baa:
	/* 0xbaa: mov    r13d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 60ULL);
x86_l_bb0:
	/* 0xbb0: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_bb4:
	/* 0xbb4: jne    bf5 <tail_handle_ipv4+0xbf5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xbb4, 0xbf5, x86_l_bf5);
x86_l_bb6:
	/* 0xbb6: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_bba:
	/* 0xbba: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_bbc:
	/* 0xbbc: shr    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_bbf:
	/* 0xbbf: and    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_bc2:
	/* 0xbc2: or     ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_OR);
x86_l_bc4:
	/* 0xbc4: mov    WORD PTR [r14+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_bc9:
	/* 0xbc9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_bcb:
	/* 0xbcb: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_bd0:
	/* 0xbd0: mov    r13d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 21600ULL);
x86_l_bd6:
	/* 0xbd6: cmove  r13d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_bda:
	/* 0xbda: mov    rax,QWORD PTR [rip+0xa85a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_be1:
	/* 0xbe1: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_be4:
	/* 0xbe4: je     bf5 <tail_handle_ipv4+0xbf5> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbe4, 0xbf5, x86_l_bf5);
x86_l_be6:
	/* 0xbe6: mov    rax,QWORD PTR [rip+0xa85a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_bed:
	/* 0xbed: imul   r13d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_bf1:
	/* 0xbf1: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_bf5:
	/* 0xbf5: shr    DWORD PTR [rsp+0x20],0x8 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_32, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_SHR)), 137438953480ULL);
x86_l_bfa:
	/* 0xbfa: mov    rax,QWORD PTR [rip+0xa85a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_c01:
	/* 0xc01: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c04:
	/* 0xc04: je     c15 <tail_handle_ipv4+0xc15> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc04, 0xc15, x86_l_c15);
x86_l_c06:
	/* 0xc06: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_c0b:
	/* 0xc0b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c0d:
	/* 0xc0d: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_c0f:
	/* 0xc0f: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_c13:
	/* 0xc13: jmp    c38 <tail_handle_ipv4+0xc38> */
	X86_SIM_X86_JMP(0xc13, 0xc38, x86_l_c38);
x86_l_c15:
	/* 0xc15: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_c1a:
	/* 0xc1a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c1c:
	/* 0xc1c: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_c1e:
	/* 0xc1e: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_c22:
	/* 0xc22: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_c2c:
	/* 0xc2c: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_c2f:
	/* 0xc2f: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_c34:
	/* 0xc34: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_c38:
	/* 0xc38: add    r13d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_c3b:
	/* 0xc3b: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_c3e:
	/* 0xc3e: mov    DWORD PTR [r14+0x20],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c42:
	/* 0xc42: movzx  ecx,BYTE PTR [r14+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_c47:
	/* 0xc47: mov    edx,DWORD PTR [r14+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c4b:
	/* 0xc4b: mov    esi,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c4f:
	/* 0xc4f: and    sil,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_c53:
	/* 0xc53: mov    DWORD PTR [rsp+0x20],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c57:
	/* 0xc57: mov    rsi,QWORD PTR [rip+0xa85a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_c5e:
	/* 0xc5e: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c61:
	/* 0xc61: je     c74 <tail_handle_ipv4+0xc74> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc61, 0xc74, x86_l_c74);
x86_l_c63:
	/* 0xc63: mov    rsi,QWORD PTR [rip+0xa85a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_c6a:
	/* 0xc6a: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c6c:
	/* 0xc6c: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_c6f:
	/* 0xc6f: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_c72:
	/* 0xc72: jmp    c79 <tail_handle_ipv4+0xc79> */
	X86_SIM_X86_JMP(0xc72, 0xc79, x86_l_c79);
x86_l_c74:
	/* 0xc74: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_c79:
	/* 0xc79: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_c7b:
	/* 0xc7b: mov    edx,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c7f:
	/* 0xc7f: or     dl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_c81:
	/* 0xc81: mov    DWORD PTR [rsp+0x20],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c85:
	/* 0xc85: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_c87:
	/* 0xc87: jb     c8f <tail_handle_ipv4+0xc8f> */
	X86_SIM_X86_JCC(X86_CC_B, 0xc87, 0xc8f, x86_l_c8f);
x86_l_c89:
	/* 0xc89: cmp    cl,BYTE PTR [rsp+0x20] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 32ULL);
x86_l_c8d:
	/* 0xc8d: je     ca4 <tail_handle_ipv4+0xca4> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc8d, 0xca4, x86_l_ca4);
x86_l_c8f:
	/* 0xc8f: mov    ecx,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c93:
	/* 0xc93: mov    BYTE PTR [r14+0x2a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_c97:
	/* 0xc97: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c9b:
	/* 0xc9b: mov    rax,QWORD PTR [rip+0xa85a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_ca2:
	/* 0xca2: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ca4:
	/* 0xca4: cmp    WORD PTR [r15+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_caa:
	/* 0xcaa: je     ed4 <tail_handle_ipv4+0xed4> */
	X86_SIM_X86_JCC(X86_CC_E, 0xcaa, 0xed4, x86_l_ed4);
x86_l_cb0:
	/* 0xcb0: test   BYTE PTR [r15+0x8],0x10 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738384ULL);
x86_l_cb5:
	/* 0xcb5: je     dee <tail_handle_ipv4+0xdee> */
	X86_SIM_X86_JCC(X86_CC_E, 0xcb5, 0xdee, x86_l_dee);
x86_l_cbb:
	/* 0xcbb: mov    rax,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_cc3:
	/* 0xcc3: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_cc8:
	/* 0xcc8: movzx  eax,WORD PTR [r15+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_ccd:
	/* 0xccd: mov    WORD PTR [rsp+0x60],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_cd2:
	/* 0xcd2: mov    WORD PTR [rsp+0x62],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 420906795008ULL);
x86_l_cd9:
	/* 0xcd9: mov    DWORD PTR [rsp+0x64],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 429496729600ULL);
x86_l_ce1:
	/* 0xce1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ce6:
	/* 0xce6: mov    rdi,QWORD PTR [rip+0xa85a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_affinity)));
x86_l_ced:
	/* 0xced: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_cf2:
	/* 0xcf2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cf4:
	/* 0xcf4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_cf7:
	/* 0xcf7: je     dee <tail_handle_ipv4+0xdee> */
	X86_SIM_X86_JCC(X86_CC_E, 0xcf7, 0xdee, x86_l_dee);
x86_l_cfd:
	/* 0xcfd: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_d00:
	/* 0xd00: mov    r14,QWORD PTR [rip+0xa85a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_d07:
	/* 0xd07: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d0b:
	/* 0xd0b: je     d1c <tail_handle_ipv4+0xd1c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd0b, 0xd1c, x86_l_d1c);
x86_l_d0d:
	/* 0xd0d: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_d12:
	/* 0xd12: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d14:
	/* 0xd14: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_d16:
	/* 0xd16: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_d1a:
	/* 0xd1a: jmp    d3f <tail_handle_ipv4+0xd3f> */
	X86_SIM_X86_JMP(0xd1a, 0xd3f, x86_l_d3f);
x86_l_d1c:
	/* 0xd1c: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_d21:
	/* 0xd21: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d23:
	/* 0xd23: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_d25:
	/* 0xd25: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_d29:
	/* 0xd29: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_d33:
	/* 0xd33: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_d36:
	/* 0xd36: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_d3b:
	/* 0xd3b: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_d3f:
	/* 0xd3f: mov    ecx,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d43:
	/* 0xd43: mov    DWORD PTR [rsp+0x28],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_d47:
	/* 0xd47: movzx  ecx,WORD PTR [r15+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_d4c:
	/* 0xd4c: mov    WORD PTR [rsp+0x2c],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_d51:
	/* 0xd51: mov    WORD PTR [rsp+0x2e],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 197568495616ULL);
x86_l_d58:
	/* 0xd58: mov    rcx,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d5c:
	/* 0xd5c: mov    edx,0xffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 16777215ULL);
x86_l_d61:
	/* 0xd61: and    edx,DWORD PTR [r15] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R15, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 0ULL);
x86_l_d64:
	/* 0xd64: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d68:
	/* 0xd68: je     d77 <tail_handle_ipv4+0xd77> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd68, 0xd77, x86_l_d77);
x86_l_d6a:
	/* 0xd6a: mov    rsi,QWORD PTR [rip+0xa85a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_d71:
	/* 0xd71: imul   edx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSI, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_d74:
	/* 0xd74: shr    edx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_d77:
	/* 0xd77: mov    edx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_d79:
	/* 0xd79: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_d7c:
	/* 0xd7c: mov    r14d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_32);
x86_l_d7f:
	/* 0xd7f: cmp    rcx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_d82:
	/* 0xd82: jbe    dd4 <tail_handle_ipv4+0xdd4> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xd82, 0xdd4, x86_l_dd4);
x86_l_d84:
	/* 0xd84: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d89:
	/* 0xd89: mov    rdi,QWORD PTR [rip+0xa85a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb_affinity_match)));
x86_l_d90:
	/* 0xd90: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_d95:
	/* 0xd95: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d97:
	/* 0xd97: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d9a:
	/* 0xd9a: je     ddb <tail_handle_ipv4+0xddb> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd9a, 0xddb, x86_l_ddb);
x86_l_d9c:
	/* 0xd9c: mov    QWORD PTR [r13+0x0],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_da0:
	/* 0xda0: mov    ebp,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_da4:
	/* 0xda4: test   ebp,ebp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_32);
x86_l_da6:
	/* 0xda6: je     dee <tail_handle_ipv4+0xdee> */
	X86_SIM_X86_JCC(X86_CC_E, 0xda6, 0xdee, x86_l_dee);
x86_l_da8:
	/* 0xda8: mov    DWORD PTR [rsp+0x58],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_dac:
	/* 0xdac: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_db1:
	/* 0xdb1: mov    rdi,QWORD PTR [rip+0xa85a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_backends_v3)));
x86_l_db8:
	/* 0xdb8: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_dbd:
	/* 0xdbd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dbf:
	/* 0xdbf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_dc2:
	/* 0xdc2: jne    e50 <tail_handle_ipv4+0xe50> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xdc2, 0xe50, x86_l_e50);
x86_l_dc8:
	/* 0xdc8: mov    rax,QWORD PTR [rip+0xa85a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_dcf:
	/* 0xdcf: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_dd2:
	/* 0xdd2: jmp    dee <tail_handle_ipv4+0xdee> */
	X86_SIM_X86_JMP(0xdd2, 0xdee, x86_l_dee);
x86_l_dd4:
	/* 0xdd4: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_dd9:
	/* 0xdd9: jmp    de0 <tail_handle_ipv4+0xde0> */
	X86_SIM_X86_JMP(0xdd9, 0xde0, x86_l_de0);
x86_l_ddb:
	/* 0xddb: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_de0:
	/* 0xde0: mov    rdi,QWORD PTR [rip+0xa85a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_affinity)));
x86_l_de7:
	/* 0xde7: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_dec:
	/* 0xdec: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dee:
	/* 0xdee: mov    ecx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_df3:
	/* 0xdf3: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_df5:
	/* 0xdf5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_df7:
	/* 0xdf7: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_df9:
	/* 0xdf9: movzx  ecx,WORD PTR [r15+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_dfe:
	/* 0xdfe: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e00:
	/* 0xe00: div    ecx */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_e02:
	/* 0xe02: inc    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_e04:
	/* 0xe04: mov    WORD PTR [rsp+0x46],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 70ULL);
x86_l_e09:
	/* 0xe09: mov    r14,QWORD PTR [rip+0xa85a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_e10:
	/* 0xe10: movzx  eax,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_e14:
	/* 0xe14: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e19:
	/* 0xe19: mov    rdi,QWORD PTR [rip+0xa85a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_services_v2)));
x86_l_e20:
	/* 0xe20: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_e25:
	/* 0xe25: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e27:
	/* 0xe27: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e2a:
	/* 0xe2a: je     e30 <tail_handle_ipv4+0xe30> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe2a, 0xe30, x86_l_e30);
x86_l_e2c:
	/* 0xe2c: mov    ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e2e:
	/* 0xe2e: jmp    e34 <tail_handle_ipv4+0xe34> */
	X86_SIM_X86_JMP(0xe2e, 0xe34, x86_l_e34);
x86_l_e30:
	/* 0xe30: movzx  eax,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_e34:
	/* 0xe34: mov    DWORD PTR [rsp+0x58],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_e38:
	/* 0xe38: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e3d:
	/* 0xe3d: mov    rdi,QWORD PTR [rip+0xa85a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_backends_v3)));
x86_l_e44:
	/* 0xe44: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_e49:
	/* 0xe49: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e4b:
	/* 0xe4b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e4e:
	/* 0xe4e: je     eca <tail_handle_ipv4+0xeca> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe4e, 0xeca, x86_l_eca);
x86_l_e50:
	/* 0xe50: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e55:
	/* 0xe55: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_e5e:
	/* 0xe5e: mov    QWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_e6a:
	/* 0xe6a: mov    QWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_e76:
	/* 0xe76: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_e7f:
	/* 0xe7f: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_e88:
	/* 0xe88: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_e91:
	/* 0xe91: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_e93:
	/* 0xe93: movzx  ebp,BYTE PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_e98:
	/* 0xe98: mov    eax,DWORD PTR [rsp+0x3c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_e9c:
	/* 0xe9c: mov    WORD PTR [rsp+0x7e],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 126ULL);
x86_l_ea1:
	/* 0xea1: mov    DWORD PTR [rsp+0xc],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_ea5:
	/* 0xea5: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_ea7:
	/* 0xea7: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_eac:
	/* 0xeac: mov    r14,QWORD PTR [rip+0xa85a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_eb3:
	/* 0xeb3: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_eb7:
	/* 0xeb7: je     f0a <tail_handle_ipv4+0xf0a> */
	X86_SIM_X86_JCC(X86_CC_E, 0xeb7, 0xf0a, x86_l_f0a);
x86_l_eb9:
	/* 0xeb9: mov    rax,QWORD PTR [rip+0xa85a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_ec0:
	/* 0xec0: imul   r13d,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_ec4:
	/* 0xec4: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_ec8:
	/* 0xec8: jmp    f10 <tail_handle_ipv4+0xf10> */
	X86_SIM_X86_JMP(0xec8, 0xf10, x86_l_f10);
x86_l_eca:
	/* 0xeca: mov    rax,QWORD PTR [rip+0xa85a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_ed1:
	/* 0xed1: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_ed4:
	/* 0xed4: movzx  eax,BYTE PTR [rsp+0x9c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 156ULL);
x86_l_edc:
	/* 0xedc: mov    BYTE PTR [rsp+0x1d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 29ULL);
x86_l_ee0:
	/* 0xee0: mov    rax,QWORD PTR [rip+0xa85a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_no_service_endpoints_routable)));
x86_l_ee7:
	/* 0xee7: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_eea:
	/* 0xeea: je     f2d <tail_handle_ipv4+0xf2d> */
	X86_SIM_X86_JCC(X86_CC_E, 0xeea, 0xf2d, x86_l_f2d);
x86_l_eec:
	/* 0xeec: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_ef1:
	/* 0xef1: mov    rsi,QWORD PTR [rip+0xa85a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_ef8:
	/* 0xef8: mov    ebp,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 45ULL);
x86_l_efd:
	/* 0xefd: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_f00:
	/* 0xf00: mov    edx,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 45ULL);
x86_l_f05:
	/* 0xf05: jmp    3bc <tail_handle_ipv4+0x3bc> */
	X86_SIM_X86_JMP(0xf05, 0x3bc, x86_l_3bc);
x86_l_f0a:
	/* 0xf0a: mov    r13d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 60ULL);
x86_l_f10:
	/* 0xf10: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_f14:
	/* 0xf14: jne    f4f <tail_handle_ipv4+0xf4f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf14, 0xf4f, x86_l_f4f);
x86_l_f16:
	/* 0xf16: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f1a:
	/* 0xf1a: je     f49 <tail_handle_ipv4+0xf49> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf1a, 0xf49, x86_l_f49);
x86_l_f1c:
	/* 0xf1c: mov    rax,QWORD PTR [rip+0xa85a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_f23:
	/* 0xf23: imul   r13d,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_f27:
	/* 0xf27: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_f2b:
	/* 0xf2b: jmp    f4f <tail_handle_ipv4+0xf4f> */
	X86_SIM_X86_JMP(0xf2b, 0xf4f, x86_l_f4f);
x86_l_f2d:
	/* 0xf2d: movzx  eax,BYTE PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_f32:
	/* 0xf32: test   al,0x23 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 35ULL);
x86_l_f34:
	/* 0xf34: je     139f <tail_handle_ipv4+0x139f> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf34, 0x139f, x86_l_139f);
x86_l_f3a:
	/* 0xf3a: test   al,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 4ULL);
x86_l_f3c:
	/* 0xf3c: jne    13aa <tail_handle_ipv4+0x13aa> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf3c, 0x13aa, x86_l_13aa);
x86_l_f42:
	/* 0xf42: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f44:
	/* 0xf44: jmp    5aa <tail_handle_ipv4+0x5aa> */
	X86_SIM_X86_JMP(0xf44, 0x5aa, x86_l_5aa);
x86_l_f49:
	/* 0xf49: mov    r13d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 60ULL);
x86_l_f4f:
	/* 0xf4f: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f53:
	/* 0xf53: je     f64 <tail_handle_ipv4+0xf64> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf53, 0xf64, x86_l_f64);
x86_l_f55:
	/* 0xf55: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_f5a:
	/* 0xf5a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f5c:
	/* 0xf5c: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_f5e:
	/* 0xf5e: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_f62:
	/* 0xf62: jmp    f87 <tail_handle_ipv4+0xf87> */
	X86_SIM_X86_JMP(0xf62, 0xf87, x86_l_f87);
x86_l_f64:
	/* 0xf64: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_f69:
	/* 0xf69: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f6b:
	/* 0xf6b: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_f6d:
	/* 0xf6d: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_f71:
	/* 0xf71: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_f7b:
	/* 0xf7b: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_f7e:
	/* 0xf7e: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_f83:
	/* 0xf83: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_f87:
	/* 0xf87: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_f8b:
	/* 0xf8b: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_f8e:
	/* 0xf8e: add    r13d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_f91:
	/* 0xf91: mov    DWORD PTR [rsp+0x78],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_f96:
	/* 0xf96: movzx  edx,BYTE PTR [rsp+0x82] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 130ULL);
x86_l_f9e:
	/* 0xf9e: mov    esi,DWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_fa5:
	/* 0xfa5: add    cl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_8, X86_ALU_ADD);
x86_l_fa7:
	/* 0xfa7: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fab:
	/* 0xfab: je     fbe <tail_handle_ipv4+0xfbe> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfab, 0xfbe, x86_l_fbe);
x86_l_fad:
	/* 0xfad: mov    rdi,QWORD PTR [rip+0xa85a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_fb4:
	/* 0xfb4: mov    edi,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fb6:
	/* 0xfb6: lea    edi,[rdi+rdi*4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_fb9:
	/* 0xfb9: shr    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_fbc:
	/* 0xfbc: jmp    fc3 <tail_handle_ipv4+0xfc3> */
	X86_SIM_X86_JMP(0xfbc, 0xfc3, x86_l_fc3);
x86_l_fbe:
	/* 0xfbe: mov    edi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 5ULL);
x86_l_fc3:
	/* 0xfc3: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_fc8:
	/* 0xfc8: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_fca:
	/* 0xfca: or     cl,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_fcc:
	/* 0xfcc: cmp    edi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_fce:
	/* 0xfce: jb     fd4 <tail_handle_ipv4+0xfd4> */
	X86_SIM_X86_JCC(X86_CC_B, 0xfce, 0xfd4, x86_l_fd4);
x86_l_fd0:
	/* 0xfd0: cmp    dl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_8);
x86_l_fd2:
	/* 0xfd2: je     feb <tail_handle_ipv4+0xfeb> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfd2, 0xfeb, x86_l_feb);
x86_l_fd4:
	/* 0xfd4: mov    BYTE PTR [rsp+0x82],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 130ULL);
x86_l_fdb:
	/* 0xfdb: mov    DWORD PTR [rsp+0x88],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_fe2:
	/* 0xfe2: mov    rax,QWORD PTR [rip+0xa85a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_fe9:
	/* 0xfe9: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_feb:
	/* 0xfeb: mov    rax,QWORD PTR [rip+0xa85a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_ff2:
	/* 0xff2: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ff5:
	/* 0xff5: je     1008 <tail_handle_ipv4+0x1008> */
	X86_SIM_X86_JCC(X86_CC_E, 0xff5, 0x1008, x86_l_1008);
x86_l_ff7:
	/* 0xff7: mov    QWORD PTR [rsp+0x68],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598785ULL);
x86_l_1000:
	/* 0x1000: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1003:
	/* 0x1003: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1008:
	/* 0x1008: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_100d:
	/* 0x100d: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1012:
	/* 0x1012: lea    rdx,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1017:
	/* 0x1017: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_101a:
	/* 0x101a: mov    rdi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_101f:
	/* 0x101f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1021:
	/* 0x1021: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1023:
	/* 0x1023: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1025:
	/* 0x1025: movabs rcx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2199023255552ULL);
x86_l_102f:
	/* 0x102f: js     13d2 <tail_handle_ipv4+0x13d2> */
	X86_SIM_X86_JCC(X86_CC_S, 0x102f, 0x13d2, x86_l_13d2);
x86_l_1035:
	/* 0x1035: movzx  eax,BYTE PTR [rsp+0x9c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 156ULL);
x86_l_103d:
	/* 0x103d: mov    BYTE PTR [rsp+0x1d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 29ULL);
x86_l_1041:
	/* 0x1041: test   BYTE PTR [r15+0x8],0x10 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738384ULL);
x86_l_1046:
	/* 0x1046: je     10eb <tail_handle_ipv4+0x10eb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1046, 0x10eb, x86_l_10eb);
x86_l_104c:
	/* 0x104c: mov    rax,QWORD PTR [rip+0xa85a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1053:
	/* 0x1053: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1056:
	/* 0x1056: je     1067 <tail_handle_ipv4+0x1067> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1056, 0x1067, x86_l_1067);
x86_l_1058:
	/* 0x1058: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_105d:
	/* 0x105d: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_105f:
	/* 0x105f: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1061:
	/* 0x1061: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_1065:
	/* 0x1065: jmp    108a <tail_handle_ipv4+0x108a> */
	X86_SIM_X86_JMP(0x1065, 0x108a, x86_l_108a);
x86_l_1067:
	/* 0x1067: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_106c:
	/* 0x106c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_106e:
	/* 0x106e: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1070:
	/* 0x1070: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1074:
	/* 0x1074: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_107e:
	/* 0x107e: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1081:
	/* 0x1081: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1086:
	/* 0x1086: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_108a:
	/* 0x108a: mov    edx,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_108e:
	/* 0x108e: mov    rcx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1096:
	/* 0x1096: mov    QWORD PTR [rsp+0x58],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_109b:
	/* 0x109b: movzx  ecx,WORD PTR [r15+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_10a0:
	/* 0x10a0: mov    WORD PTR [rsp+0x60],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_10a5:
	/* 0x10a5: mov    WORD PTR [rsp+0x62],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 420906795008ULL);
x86_l_10ac:
	/* 0x10ac: mov    DWORD PTR [rsp+0x64],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 429496729600ULL);
x86_l_10b4:
	/* 0x10b4: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_10b6:
	/* 0x10b6: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_10bb:
	/* 0x10bb: mov    DWORD PTR [rsp+0x30],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_10bf:
	/* 0x10bf: mov    DWORD PTR [rsp+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_10c7:
	/* 0x10c7: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_10cc:
	/* 0x10cc: mov    rdi,QWORD PTR [rip+0xa85a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_affinity)));
x86_l_10d3:
	/* 0x10d3: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_10d8:
	/* 0x10d8: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_10dd:
	/* 0x10dd: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10df:
	/* 0x10df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10e1:
	/* 0x10e1: movabs rcx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2199023255552ULL);
x86_l_10eb:
	/* 0x10eb: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_10ef:
	/* 0x10ef: cmp    esi,DWORD PTR [r14] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RSI, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_10f2:
	/* 0x10f2: jne    1130 <tail_handle_ipv4+0x1130> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x10f2, 0x1130, x86_l_1130);
x86_l_10f4:
	/* 0x10f4: mov    rax,QWORD PTR [rip+0xa85a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_lrp)));
x86_l_10fb:
	/* 0x10fb: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10fe:
	/* 0x10fe: je     111a <tail_handle_ipv4+0x111a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10fe, 0x111a, x86_l_111a);
x86_l_1100:
	/* 0x1100: mov    rax,QWORD PTR [rip+0xa85a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_endpoint_netns_cookie)));
x86_l_1107:
	/* 0x1107: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_110a:
	/* 0x110a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_110d:
	/* 0x110d: je     111a <tail_handle_ipv4+0x111a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x110d, 0x111a, x86_l_111a);
x86_l_110f:
	/* 0x110f: test   BYTE PTR [r15+0x9],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38654705665ULL);
x86_l_1114:
	/* 0x1114: jne    13df <tail_handle_ipv4+0x13df> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1114, 0x13df, x86_l_13df);
x86_l_111a:
	/* 0x111a: mov    r15d,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_111f:
	/* 0x111f: movzx  eax,WORD PTR [rsp+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 26ULL);
x86_l_1124:
	/* 0x1124: mov    WORD PTR [rsp+0x38],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1129:
	/* 0x1129: mov    r13w,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_16, 1ULL);
x86_l_112e:
	/* 0x112e: jmp    1158 <tail_handle_ipv4+0x1158> */
	X86_SIM_X86_JMP(0x112e, 0x1158, x86_l_1158);
x86_l_1130:
	/* 0x1130: movzx  eax,r13w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R13, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1134:
	/* 0x1134: mov    r15d,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1139:
	/* 0x1139: movzx  edx,WORD PTR [rsp+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 26ULL);
x86_l_113e:
	/* 0x113e: mov    WORD PTR [rsp+0x38],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1143:
	/* 0x1143: mov    DWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_114b:
	/* 0x114b: test   al,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_114d:
	/* 0x114d: jne    1158 <tail_handle_ipv4+0x1158> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x114d, 0x1158, x86_l_1158);
x86_l_114f:
	/* 0x114f: mov    eax,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1152:
	/* 0x1152: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1156:
	/* 0x1156: jmp    1165 <tail_handle_ipv4+0x1165> */
	X86_SIM_X86_JMP(0x1156, 0x1165, x86_l_1165);
x86_l_1158:
	/* 0x1158: mov    rax,QWORD PTR [rip+0xa85a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_service_loopback_ipv4)));
x86_l_115f:
	/* 0x115f: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1161:
	/* 0x1161: mov    DWORD PTR [rsp+0x58],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1165:
	/* 0x1165: movzx  eax,WORD PTR [r14+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_116a:
	/* 0x116a: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_116d:
	/* 0x116d: je     1174 <tail_handle_ipv4+0x1174> */
	X86_SIM_X86_JCC(X86_CC_E, 0x116d, 0x1174, x86_l_1174);
x86_l_116f:
	/* 0x116f: mov    WORD PTR [rsp+0x1a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_1174:
	/* 0x1174: test   r12,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_1177:
	/* 0x1177: mov    DWORD PTR [rsp+0x9c],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_117e:
	/* 0x117e: je     1260 <tail_handle_ipv4+0x1260> */
	X86_SIM_X86_JCC(X86_CC_E, 0x117e, 0x1260, x86_l_1260);
x86_l_1184:
	/* 0x1184: mov    al,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_1186:
	/* 0x1186: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_118a:
	/* 0x118a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_118c:
	/* 0x118c: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1194:
	/* 0x1194: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_119c:
	/* 0x119c: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_11a1:
	/* 0x11a1: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11a3:
	/* 0x11a3: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_11a6:
	/* 0x11a6: mov    esi,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 30ULL);
x86_l_11ab:
	/* 0x11ab: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_11ae:
	/* 0x11ae: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_11b3:
	/* 0x11b3: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11b6:
	/* 0x11b6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11b8:
	/* 0x11b8: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_11bb:
	/* 0x11bb: mov    r14d,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4294967155ULL);
x86_l_11c1:
	/* 0x11c1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_11c3:
	/* 0x11c3: js     4fe <tail_handle_ipv4+0x4fe> */
	X86_SIM_X86_JCC(X86_CC_S, 0x11c3, 0x4fe, x86_l_4fe);
x86_l_11c9:
	/* 0x11c9: not    r15d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_11cc:
	/* 0x11cc: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_11d1:
	/* 0x11d1: add    r15d,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R15, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_11d4:
	/* 0x11d4: adc    r15d,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_11d8:
	/* 0x11d8: cmp    DWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_11dd:
	/* 0x11dd: je     1226 <tail_handle_ipv4+0x1226> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11dd, 0x1226, x86_l_1226);
x86_l_11df:
	/* 0x11df: mov    rax,QWORD PTR [rip+0xa85a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_11e6:
	/* 0x11e6: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_11e9:
	/* 0x11e9: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_11ee:
	/* 0x11ee: lea    rdx,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_11f3:
	/* 0x11f3: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_11f6:
	/* 0x11f6: mov    esi,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 26ULL);
x86_l_11fb:
	/* 0x11fb: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1200:
	/* 0x1200: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1203:
	/* 0x1203: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1205:
	/* 0x1205: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1207:
	/* 0x1207: js     4fe <tail_handle_ipv4+0x4fe> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1207, 0x4fe, x86_l_4fe);
x86_l_120d:
	/* 0x120d: mov    eax,DWORD PTR [rsp+0x9c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 156ULL);
x86_l_1214:
	/* 0x1214: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1216:
	/* 0x1216: add    eax,DWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 88ULL);
x86_l_121a:
	/* 0x121a: adc    eax,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_121d:
	/* 0x121d: add    eax,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R15, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1220:
	/* 0x1220: adc    eax,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_1223:
	/* 0x1223: mov    r15d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_32);
x86_l_1226:
	/* 0x1226: mov    eax,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_122b:
	/* 0x122b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_122e:
	/* 0x122e: mov    esi,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 24ULL);
x86_l_1233:
	/* 0x1233: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1235:
	/* 0x1235: mov    ecx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_32);
x86_l_1238:
	/* 0x1238: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_123b:
	/* 0x123b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_123d:
	/* 0x123d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_123f:
	/* 0x123f: js     1292 <tail_handle_ipv4+0x1292> */
	X86_SIM_X86_JCC(X86_CC_S, 0x123f, 0x1292, x86_l_1292);
x86_l_1241:
	/* 0x1241: cmp    BYTE PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_1246:
	/* 0x1246: je     129d <tail_handle_ipv4+0x129d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1246, 0x129d, x86_l_129d);
x86_l_1248:
	/* 0x1248: movabs rax,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2199023255552ULL);
x86_l_1252:
	/* 0x1252: test   r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1255:
	/* 0x1255: je     12ee <tail_handle_ipv4+0x12ee> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1255, 0x12ee, x86_l_12ee);
x86_l_125b:
	/* 0x125b: jmp    1362 <tail_handle_ipv4+0x1362> */
	X86_SIM_X86_JMP(0x125b, 0x1362, x86_l_1362);
x86_l_1260:
	/* 0x1260: movzx  eax,BYTE PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 28ULL);
x86_l_1265:
	/* 0x1265: cmp    eax,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 58ULL);
x86_l_1268:
	/* 0x1268: je     138d <tail_handle_ipv4+0x138d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1268, 0x138d, x86_l_138d);
x86_l_126e:
	/* 0x126e: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_1271:
	/* 0x1271: je     136b <tail_handle_ipv4+0x136b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1271, 0x136b, x86_l_136b);
x86_l_1277:
	/* 0x1277: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_127a:
	/* 0x127a: jne    1184 <tail_handle_ipv4+0x1184> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x127a, 0x1184, x86_l_1184);
x86_l_1280:
	/* 0x1280: mov    DWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_1288:
	/* 0x1288: mov    eax,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 16ULL);
x86_l_128d:
	/* 0x128d: jmp    118c <tail_handle_ipv4+0x118c> */
	X86_SIM_X86_JMP(0x128d, 0x118c, x86_l_118c);
x86_l_1292:
	/* 0x1292: mov    r14d,0xffffff67 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4294967143ULL);
x86_l_1298:
	/* 0x1298: jmp    4fe <tail_handle_ipv4+0x4fe> */
	X86_SIM_X86_JMP(0x1298, 0x4fe, x86_l_4fe);
x86_l_129d:
	/* 0x129d: mov    rax,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_12a5:
	/* 0x12a5: mov    rcx,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_12ad:
	/* 0x12ad: lea    esi,[rcx+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_12b0:
	/* 0x12b0: mov    r8d,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_12b5:
	/* 0x12b5: or     r8d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 16ULL);
x86_l_12b9:
	/* 0x12b9: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_12be:
	/* 0x12be: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_12c1:
	/* 0x12c1: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12c3:
	/* 0x12c3: mov    ecx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_32);
x86_l_12c6:
	/* 0x12c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12c8:
	/* 0x12c8: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_12ca:
	/* 0x12ca: sar    ecx,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SAR, 31ULL);
x86_l_12cd:
	/* 0x12cd: and    ecx,0xffffff66 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4294967142ULL);
x86_l_12d3:
	/* 0x12d3: movabs rdx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 2199023255552ULL);
x86_l_12dd:
	/* 0x12dd: test   r12,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_RDX, X86_WIDTH_64);
x86_l_12e0:
	/* 0x12e0: jne    13bc <tail_handle_ipv4+0x13bc> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x12e0, 0x13bc, x86_l_13bc);
x86_l_12e6:
	/* 0x12e6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_12e8:
	/* 0x12e8: js     13bc <tail_handle_ipv4+0x13bc> */
	X86_SIM_X86_JCC(X86_CC_S, 0x12e8, 0x13bc, x86_l_13bc);
x86_l_12ee:
	/* 0x12ee: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_12f3:
	/* 0x12f3: movzx  eax,WORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_12f7:
	/* 0x12f7: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_12fa:
	/* 0x12fa: je     1362 <tail_handle_ipv4+0x1362> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12fa, 0x1362, x86_l_1362);
x86_l_12fc:
	/* 0x12fc: cmp    WORD PTR [rsp+0x38],ax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1301:
	/* 0x1301: je     1362 <tail_handle_ipv4+0x1362> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1301, 0x1362, x86_l_1362);
x86_l_1303:
	/* 0x1303: mov    WORD PTR [rsp+0x28],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1308:
	/* 0x1308: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_130d:
	/* 0x130d: mov    r15,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1315:
	/* 0x1315: lea    esi,[r15+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_1319:
	/* 0x1319: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_131e:
	/* 0x131e: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1321:
	/* 0x1321: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1326:
	/* 0x1326: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1329:
	/* 0x1329: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_132b:
	/* 0x132b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_132d:
	/* 0x132d: js     4fe <tail_handle_ipv4+0x4fe> */
	X86_SIM_X86_JCC(X86_CC_S, 0x132d, 0x4fe, x86_l_4fe);
x86_l_1333:
	/* 0x1333: movzx  edx,WORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_1338:
	/* 0x1338: movzx  ecx,WORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 40ULL);
x86_l_133d:
	/* 0x133d: movzx  eax,r15b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R15, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1341:
	/* 0x1341: mov    rsi,QWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1349:
	/* 0x1349: add    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_134b:
	/* 0x134b: mov    r8d,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1350:
	/* 0x1350: or     r8d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_1354:
	/* 0x1354: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_1359:
	/* 0x1359: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_135c:
	/* 0x135c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_135e:
	/* 0x135e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1360:
	/* 0x1360: js     13b7 <tail_handle_ipv4+0x13b7> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1360, 0x13b7, x86_l_13b7);
x86_l_1362:
	/* 0x1362: mov    edx,DWORD PTR [rsp+0x3c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_1366:
	/* 0x1366: jmp    38c <tail_handle_ipv4+0x38c> */
	X86_SIM_X86_JMP(0x1366, 0x38c, x86_l_38c);
x86_l_136b:
	/* 0x136b: mov    DWORD PTR [rsp+0xc],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607584ULL);
x86_l_1373:
	/* 0x1373: mov    eax,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_1378:
	/* 0x1378: mov    QWORD PTR [rsp+0x90],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1380:
	/* 0x1380: mov    DWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_1388:
	/* 0x1388: jmp    119c <tail_handle_ipv4+0x119c> */
	X86_SIM_X86_JMP(0x1388, 0x119c, x86_l_119c);
x86_l_138d:
	/* 0x138d: mov    DWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_1395:
	/* 0x1395: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_139a:
	/* 0x139a: jmp    118c <tail_handle_ipv4+0x118c> */
	X86_SIM_X86_JMP(0x139a, 0x118c, x86_l_118c);
x86_l_139f:
	/* 0x139f: test   BYTE PTR [r15+0x9],0x10 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38654705680ULL);
x86_l_13a4:
	/* 0x13a4: je     f42 <tail_handle_ipv4+0xf42> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13a4, 0xf42, x86_l_f42);
x86_l_13aa:
	/* 0x13aa: mov    r14d,0xffffff62 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4294967138ULL);
x86_l_13b0:
	/* 0x13b0: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13b2:
	/* 0x13b2: jmp    4fe <tail_handle_ipv4+0x4fe> */
	X86_SIM_X86_JMP(0x13b2, 0x4fe, x86_l_4fe);
x86_l_13b7:
	/* 0x13b7: mov    ecx,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967142ULL);
x86_l_13bc:
	/* 0x13bc: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_13be:
	/* 0x13be: mov    edx,DWORD PTR [rsp+0x3c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_13c2:
	/* 0x13c2: jns    38c <tail_handle_ipv4+0x38c> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x13c2, 0x38c, x86_l_38c);
x86_l_13c8:
	/* 0x13c8: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13ca:
	/* 0x13ca: mov    r14d,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RCX, X86_WIDTH_32);
x86_l_13cd:
	/* 0x13cd: jmp    4fe <tail_handle_ipv4+0x4fe> */
	X86_SIM_X86_JMP(0x13cd, 0x4fe, x86_l_4fe);
x86_l_13d2:
	/* 0x13d2: mov    ebp,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_13d4:
	/* 0x13d4: mov    r14d,0xffffff65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4294967141ULL);
x86_l_13da:
	/* 0x13da: jmp    4fe <tail_handle_ipv4+0x4fe> */
	X86_SIM_X86_JMP(0x13da, 0x4fe, x86_l_4fe);
x86_l_13df:
	/* 0x13df: mov    ecx,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13e3:
	/* 0x13e3: movzx  edx,WORD PTR [rsp+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 26ULL);
x86_l_13e8:
	/* 0x13e8: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_13f1:
	/* 0x13f1: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_13f6:
	/* 0x13f6: mov    DWORD PTR [rsp+0x60],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_13fa:
	/* 0x13fa: mov    WORD PTR [rsp+0x64],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 100ULL);
x86_l_13ff:
	/* 0x13ff: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1404:
	/* 0x1404: mov    rdi,QWORD PTR [rip+0xa85a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_skip_lb4)));
x86_l_140b:
	/* 0x140b: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1410:
	/* 0x1410: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1412:
	/* 0x1412: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1415:
	/* 0x1415: jne    1362 <tail_handle_ipv4+0x1362> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1415, 0x1362, x86_l_1362);
x86_l_141b:
	/* 0x141b: mov    esi,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_141f:
	/* 0x141f: movabs rcx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2199023255552ULL);
x86_l_1429:
	/* 0x1429: jmp    111a <tail_handle_ipv4+0x111a> */
	X86_SIM_X86_JMP(0x1429, 0x111a, x86_l_111a);
x86_l_142e:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
