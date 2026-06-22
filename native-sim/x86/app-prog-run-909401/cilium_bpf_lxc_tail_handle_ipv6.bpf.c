extern char __config_debug_lb;
extern char __config_enable_conntrack_accounting;
extern char __config_enable_ipv6_fragments;
extern char __config_enable_jiffies;
extern char __config_enable_lrp;
extern char __config_enable_no_service_endpoints_routable;
extern char __config_endpoint_netns_cookie;
extern char __config_kernel_hz;
extern char __config_nodeport_port_max;
extern char __config_nodeport_port_min;
extern char __config_security_label;
extern char __config_service_loopback_ipv6;
extern char __config_trace_payload_len;
extern char cilium_calls;
extern char cilium_ct6_global;
extern char cilium_ct_any6_global;
extern char cilium_ipcache_v2;
extern char cilium_ipv6_frag_datagrams;
extern char cilium_lb6_affinity;
extern char cilium_lb6_backends_v3;
extern char cilium_lb6_services_v2;
extern char cilium_lb_affinity_match;
extern char cilium_metrics;
extern char cilium_nodeport_nat_buffer;
extern char cilium_skip_lb6;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int cilium_bpf_lxc_tail_handle_ipv6_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0x108 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 264ULL);
x86_l_a:
	/* 0xa: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: mov    r13d,DWORD PTR [rdi+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_11:
	/* 0x11: mov    eax,DWORD PTR [rdi+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_14:
	/* 0x14: lea    rcx,[r13+0x36] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_18:
	/* 0x18: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1b:
	/* 0x1b: mov    r12d,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967162ULL);
x86_l_21:
	/* 0x21: cmp    rcx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_24:
	/* 0x24: jbe    99 <tail_handle_ipv6+0x99> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x24, 0x99, x86_l_99);
x86_l_26:
	/* 0x26: mov    rax,QWORD PTR [rip+0x14027] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_security_label)));
x86_l_2d:
	/* 0x2d: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f:
	/* 0x2f: neg    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_32:
	/* 0x32: movzx  ecx,r12b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R12, X86_WIDTH_32, X86_WIDTH_8);
x86_l_36:
	/* 0x36: shl    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHL, 8ULL);
x86_l_3a:
	/* 0x3a: movzx  edx,r14w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RDX, X86_R14, X86_WIDTH_32, X86_WIDTH_16);
x86_l_3e:
	/* 0x3e: mov    DWORD PTR [rbx+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_41:
	/* 0x41: mov    DWORD PTR [rbx+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_48:
	/* 0x48: or     edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_4a:
	/* 0x4a: mov    DWORD PTR [rbx+0x38],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_4d:
	/* 0x4d: movabs rax,0x471020200000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 320039256133206016ULL);
x86_l_57:
	/* 0x57: mov    QWORD PTR [rbx+0x3c],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_5b:
	/* 0x5b: mov    r14d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5e:
	/* 0x5e: movabs rax,0x204710200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8664449536ULL);
x86_l_68:
	/* 0x68: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_6d:
	/* 0x6d: mov    BYTE PTR [rsp+0x58],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_71:
	/* 0x71: mov    rdi,QWORD PTR [rip+0x14027] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_78:
	/* 0x78: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_7d:
	/* 0x7d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_82:
	/* 0x82: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_84:
	/* 0x84: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_87:
	/* 0x87: je     1bf <tail_handle_ipv6+0x1bf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x87, 0x1bf, x86_l_1bf);
x86_l_8d:
	/* 0x8d: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_90:
	/* 0x90: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_94:
	/* 0x94: jmp    1e7 <tail_handle_ipv6+0x1e7> */
	X86_SIM_X86_JMP(0x94, 0x1e7, x86_l_1e7);
x86_l_99:
	/* 0x99: lea    rax,[r13+0xe] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_9d:
	/* 0x9d: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a1:
	/* 0xa1: mov    rax,QWORD PTR [rip+0x14027] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_a8:
	/* 0xa8: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ab:
	/* 0xab: movabs r15,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_b5:
	/* 0xb5: je     207 <tail_handle_ipv6+0x207> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb5, 0x207, x86_l_207);
x86_l_bb:
	/* 0xbb: cmp    BYTE PTR [r13+0x14],0x3a */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 85899345978ULL);
x86_l_c0:
	/* 0xc0: jne    ee <tail_handle_ipv6+0xee> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xc0, 0xee, x86_l_ee);
x86_l_c2:
	/* 0xc2: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c7:
	/* 0xc7: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_cc:
	/* 0xcc: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_cf:
	/* 0xcf: mov    esi,0x36 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 54ULL);
x86_l_d4:
	/* 0xd4: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_d9:
	/* 0xd9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_db:
	/* 0xdb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_dd:
	/* 0xdd: js     ee <tail_handle_ipv6+0xee> */
	X86_SIM_X86_JCC(X86_CC_S, 0xdd, 0xee, x86_l_ee);
x86_l_df:
	/* 0xdf: movzx  eax,BYTE PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_e4:
	/* 0xe4: add    al,0x79 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_ADD, 121ULL);
x86_l_e6:
	/* 0xe6: cmp    al,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_e8:
	/* 0xe8: jbe    f75 <tail_handle_ipv6+0xf75> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xe8, 0xf75, x86_l_f75);
x86_l_ee:
	/* 0xee: mov    QWORD PTR [rsp+0x76],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 506806140928ULL);
x86_l_f7:
	/* 0xf7: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_100:
	/* 0x100: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_109:
	/* 0x109: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_112:
	/* 0x112: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_11b:
	/* 0x11b: mov    QWORD PTR [rsp+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_127:
	/* 0x127: mov    QWORD PTR [rsp+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_133:
	/* 0x133: mov    QWORD PTR [rsp+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_13f:
	/* 0x13f: movzx  ebp,BYTE PTR [r13+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 20ULL);
x86_l_144:
	/* 0x144: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_147:
	/* 0x147: mov    BYTE PTR [rsp+0x7c],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_14c:
	/* 0x14c: mov    edx,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 40ULL);
x86_l_151:
	/* 0x151: cmp    rbp,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 60ULL);
x86_l_155:
	/* 0x155: ja     47e <tail_handle_ipv6+0x47e> */
	X86_SIM_X86_JCC(X86_CC_A, 0x155, 0x47e, x86_l_47e);
x86_l_15b:
	/* 0x15b: mov    r12d,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967140ULL);
x86_l_161:
	/* 0x161: bt     r15,rbp */
	X86_SIM_L_EXEC_BT(X86_R15, X86_RBP, X86_WIDTH_64);
x86_l_165:
	/* 0x165: jae    29e <tail_handle_ipv6+0x29e> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x165, 0x29e, x86_l_29e);
x86_l_16b:
	/* 0x16b: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_170:
	/* 0x170: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_175:
	/* 0x175: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_178:
	/* 0x178: mov    esi,0x36 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 54ULL);
x86_l_17d:
	/* 0x17d: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_182:
	/* 0x182: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_184:
	/* 0x184: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_186:
	/* 0x186: js     fcf <tail_handle_ipv6+0xfcf> */
	X86_SIM_X86_JCC(X86_CC_S, 0x186, 0xfcf, x86_l_fcf);
x86_l_18c:
	/* 0x18c: movzx  r14d,BYTE PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_192:
	/* 0x192: cmp    ebp,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 43ULL);
x86_l_195:
	/* 0x195: jle    280 <tail_handle_ipv6+0x280> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x195, 0x280, x86_l_280);
x86_l_19b:
	/* 0x19b: cmp    ebp,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_19e:
	/* 0x19e: je     280 <tail_handle_ipv6+0x280> */
	X86_SIM_X86_JCC(X86_CC_E, 0x19e, 0x280, x86_l_280);
x86_l_1a4:
	/* 0x1a4: cmp    ebp,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 51ULL);
x86_l_1a7:
	/* 0x1a7: jne    361 <tail_handle_ipv6+0x361> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1a7, 0x361, x86_l_361);
x86_l_1ad:
	/* 0x1ad: movzx  eax,BYTE PTR [rsp+0x11] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 17ULL);
x86_l_1b2:
	/* 0x1b2: lea    r15d,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_1ba:
	/* 0x1ba: jmp    297 <tail_handle_ipv6+0x297> */
	X86_SIM_X86_JMP(0x1ba, 0x297, x86_l_297);
x86_l_1bf:
	/* 0x1bf: mov    QWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_1c8:
	/* 0x1c8: mov    QWORD PTR [rsp+0x18],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1cd:
	/* 0x1cd: mov    rdi,QWORD PTR [rip+0x14027] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1d4:
	/* 0x1d4: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1d9:
	/* 0x1d9: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1de:
	/* 0x1de: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1e3:
	/* 0x1e3: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e5:
	/* 0x1e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e7:
	/* 0x1e7: mov    rsi,QWORD PTR [rip+0x14027] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_1ee:
	/* 0x1ee: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1f3:
	/* 0x1f3: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1f6:
	/* 0x1f6: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_1fb:
	/* 0x1fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fd:
	/* 0x1fd: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_202:
	/* 0x202: jmp    fe3 <tail_handle_ipv6+0xfe3> */
	X86_SIM_X86_JMP(0x202, 0xfe3, x86_l_fe3);
x86_l_207:
	/* 0x207: movzx  r14d,BYTE PTR [r13+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 20ULL);
x86_l_20c:
	/* 0x20c: cmp    r14,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_64, 60ULL);
x86_l_210:
	/* 0x210: ja     f4f <tail_handle_ipv6+0xf4f> */
	X86_SIM_X86_JCC(X86_CC_A, 0x210, 0xf4f, x86_l_f4f);
x86_l_216:
	/* 0x216: mov    r12d,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967140ULL);
x86_l_21c:
	/* 0x21c: movabs rax,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_226:
	/* 0x226: bt     rax,r14 */
	X86_SIM_L_EXEC_BT(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_22a:
	/* 0x22a: jae    352 <tail_handle_ipv6+0x352> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x22a, 0x352, x86_l_352);
x86_l_230:
	/* 0x230: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_234:
	/* 0x234: sub    r15d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R13, X86_WIDTH_32, X86_ALU_SUB);
x86_l_237:
	/* 0x237: lea    ebp,[r15+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_23b:
	/* 0x23b: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_240:
	/* 0x240: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_245:
	/* 0x245: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_248:
	/* 0x248: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_24a:
	/* 0x24a: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_24f:
	/* 0x24f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_251:
	/* 0x251: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_253:
	/* 0x253: js     6d3 <tail_handle_ipv6+0x6d3> */
	X86_SIM_X86_JCC(X86_CC_S, 0x253, 0x6d3, x86_l_6d3);
x86_l_259:
	/* 0x259: movzx  edx,BYTE PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_25e:
	/* 0x25e: cmp    r14d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 43ULL);
x86_l_262:
	/* 0x262: jle    2b2 <tail_handle_ipv6+0x2b2> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x262, 0x2b2, x86_l_2b2);
x86_l_264:
	/* 0x264: cmp    r14d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 60ULL);
x86_l_268:
	/* 0x268: je     2b2 <tail_handle_ipv6+0x2b2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x268, 0x2b2, x86_l_2b2);
x86_l_26a:
	/* 0x26a: cmp    r14d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 51ULL);
x86_l_26e:
	/* 0x26e: jne    4ab <tail_handle_ipv6+0x4ab> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x26e, 0x4ab, x86_l_4ab);
x86_l_274:
	/* 0x274: movzx  r14d,BYTE PTR [rsp+0x11] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 17ULL);
x86_l_27a:
	/* 0x27a: shl    r14d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHL, 2ULL);
x86_l_27e:
	/* 0x27e: jmp    2cc <tail_handle_ipv6+0x2cc> */
	X86_SIM_X86_JMP(0x27e, 0x2cc, x86_l_2cc);
x86_l_280:
	/* 0x280: movzx  eax,BYTE PTR [rsp+0x11] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 17ULL);
x86_l_285:
	/* 0x285: lea    r15d,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_28d:
	/* 0x28d: cmp    bpl,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 44ULL);
x86_l_291:
	/* 0x291: je     367 <tail_handle_ipv6+0x367> */
	X86_SIM_X86_JCC(X86_CC_E, 0x291, 0x367, x86_l_367);
x86_l_297:
	/* 0x297: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_299:
	/* 0x299: jmp    3d2 <tail_handle_ipv6+0x3d2> */
	X86_SIM_X86_JMP(0x299, 0x3d2, x86_l_3d2);
x86_l_29e:
	/* 0x29e: mov    ecx,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 0ULL);
x86_l_2a3:
	/* 0x2a3: cmp    rbp,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_64, 59ULL);
x86_l_2a7:
	/* 0x2a7: je     fd5 <tail_handle_ipv6+0xfd5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2a7, 0xfd5, x86_l_fd5);
x86_l_2ad:
	/* 0x2ad: jmp    8ee <tail_handle_ipv6+0x8ee> */
	X86_SIM_X86_JMP(0x2ad, 0x8ee, x86_l_8ee);
x86_l_2b2:
	/* 0x2b2: cmp    r14d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 44ULL);
x86_l_2b6:
	/* 0x2b6: mov    r14d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 0ULL);
x86_l_2bc:
	/* 0x2bc: je     5fb <tail_handle_ipv6+0x5fb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2bc, 0x5fb, x86_l_5fb);
x86_l_2c2:
	/* 0x2c2: movzx  r14d,BYTE PTR [rsp+0x11] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 17ULL);
x86_l_2c8:
	/* 0x2c8: shl    r14d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_2cc:
	/* 0x2cc: cmp    edx,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 60ULL);
x86_l_2cf:
	/* 0x2cf: ja     f4f <tail_handle_ipv6+0xf4f> */
	X86_SIM_X86_JCC(X86_CC_A, 0x2cf, 0xf4f, x86_l_f4f);
x86_l_2d5:
	/* 0x2d5: mov    eax,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RDX, X86_WIDTH_32);
x86_l_2d7:
	/* 0x2d7: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_2e1:
	/* 0x2e1: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_2e5:
	/* 0x2e5: jae    6e1 <tail_handle_ipv6+0x6e1> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x2e5, 0x6e1, x86_l_6e1);
x86_l_2eb:
	/* 0x2eb: mov    DWORD PTR [rsp+0x48],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2ef:
	/* 0x2ef: lea    ebp,[r14+r15*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 0), 0ULL);
x86_l_2f3:
	/* 0x2f3: add    ebp,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 48ULL);
x86_l_2f6:
	/* 0x2f6: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2fb:
	/* 0x2fb: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_300:
	/* 0x300: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_303:
	/* 0x303: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_305:
	/* 0x305: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_30a:
	/* 0x30a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30c:
	/* 0x30c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_30e:
	/* 0x30e: js     6d3 <tail_handle_ipv6+0x6d3> */
	X86_SIM_X86_JCC(X86_CC_S, 0x30e, 0x6d3, x86_l_6d3);
x86_l_314:
	/* 0x314: mov    QWORD PTR [rsp+0x8],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_319:
	/* 0x319: movzx  esi,BYTE PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_31e:
	/* 0x31e: mov    eax,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_322:
	/* 0x322: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_325:
	/* 0x325: jle    5f3 <tail_handle_ipv6+0x5f3> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x325, 0x5f3, x86_l_5f3);
x86_l_32b:
	/* 0x32b: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_32e:
	/* 0x32e: mov    r14d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 0ULL);
x86_l_334:
	/* 0x334: je     5fb <tail_handle_ipv6+0x5fb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x334, 0x5fb, x86_l_5fb);
x86_l_33a:
	/* 0x33a: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_33d:
	/* 0x33d: jne    5f6 <tail_handle_ipv6+0x5f6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x33d, 0x5f6, x86_l_5f6);
x86_l_343:
	/* 0x343: movzx  r14d,BYTE PTR [rsp+0x11] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 17ULL);
x86_l_349:
	/* 0x349: shl    r14d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHL, 2ULL);
x86_l_34d:
	/* 0x34d: jmp    64f <tail_handle_ipv6+0x64f> */
	X86_SIM_X86_JMP(0x34d, 0x64f, x86_l_64f);
x86_l_352:
	/* 0x352: cmp    r14,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_64, 59ULL);
x86_l_356:
	/* 0x356: je     6eb <tail_handle_ipv6+0x6eb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x356, 0x6eb, x86_l_6eb);
x86_l_35c:
	/* 0x35c: jmp    f4f <tail_handle_ipv6+0xf4f> */
	X86_SIM_X86_JMP(0x35c, 0xf4f, x86_l_f4f);
x86_l_361:
	/* 0x361: mov    r15d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 8ULL);
x86_l_367:
	/* 0x367: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_370:
	/* 0x370: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_375:
	/* 0x375: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_37a:
	/* 0x37a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_37d:
	/* 0x37d: mov    esi,0x36 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 54ULL);
x86_l_382:
	/* 0x382: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_387:
	/* 0x387: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_389:
	/* 0x389: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_38b:
	/* 0x38b: js     fcf <tail_handle_ipv6+0xfcf> */
	X86_SIM_X86_JCC(X86_CC_S, 0x38b, 0xfcf, x86_l_fcf);
x86_l_391:
	/* 0x391: mov    eax,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_395:
	/* 0x395: movzx  ecx,BYTE PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_39a:
	/* 0x39a: shl    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_39e:
	/* 0x39e: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_3a1:
	/* 0x3a1: movzx  eax,WORD PTR [rsp+0x12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18ULL);
x86_l_3a6:
	/* 0x3a6: movabs rdx,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1099511627776ULL);
x86_l_3b0:
	/* 0x3b0: or     rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_3b3:
	/* 0x3b3: test   eax,0xf9ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63999ULL);
x86_l_3b8:
	/* 0x3b8: cmove  rdx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_64, X86_CC_E);
x86_l_3bc:
	/* 0x3bc: movabs rcx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2199023255552ULL);
x86_l_3c6:
	/* 0x3c6: or     rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_OR);
x86_l_3c9:
	/* 0x3c9: test   eax,0xf8ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63743ULL);
x86_l_3ce:
	/* 0x3ce: cmove  rcx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_3d2:
	/* 0x3d2: mov    BYTE PTR [rsp+0x8],r14b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3d7:
	/* 0x3d7: movzx  r14d,r14b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_R14, X86_WIDTH_32, X86_WIDTH_8);
x86_l_3db:
	/* 0x3db: lea    edx,[r15+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3df:
	/* 0x3df: cmp    r14d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 60ULL);
x86_l_3e3:
	/* 0x3e3: ja     5d4 <tail_handle_ipv6+0x5d4> */
	X86_SIM_X86_JCC(X86_CC_A, 0x3e3, 0x5d4, x86_l_5d4);
x86_l_3e9:
	/* 0x3e9: mov    eax,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_32);
x86_l_3ec:
	/* 0x3ec: movabs rsi,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_3f6:
	/* 0x3f6: bt     rsi,rax */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_3fa:
	/* 0x3fa: jae    462 <tail_handle_ipv6+0x462> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x3fa, 0x462, x86_l_462);
x86_l_3fc:
	/* 0x3fc: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_401:
	/* 0x401: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_404:
	/* 0x404: mov    QWORD PTR [rsp+0xd8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_40c:
	/* 0x40c: add    r15d,0x36 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADD, 54ULL);
x86_l_410:
	/* 0x410: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_415:
	/* 0x415: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_41a:
	/* 0x41a: mov    esi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_41d:
	/* 0x41d: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_422:
	/* 0x422: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_424:
	/* 0x424: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_426:
	/* 0x426: js     fcf <tail_handle_ipv6+0xfcf> */
	X86_SIM_X86_JCC(X86_CC_S, 0x426, 0xfcf, x86_l_fcf);
x86_l_42c:
	/* 0x42c: movzx  ebp,BYTE PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_431:
	/* 0x431: cmp    r14d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 43ULL);
x86_l_435:
	/* 0x435: jle    485 <tail_handle_ipv6+0x485> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x435, 0x485, x86_l_485);
x86_l_437:
	/* 0x437: cmp    r14d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 44ULL);
x86_l_43b:
	/* 0x43b: mov    rcx,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_443:
	/* 0x443: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_448:
	/* 0x448: je     4b3 <tail_handle_ipv6+0x4b3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x448, 0x4b3, x86_l_4b3);
x86_l_44a:
	/* 0x44a: cmp    r14d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 51ULL);
x86_l_44e:
	/* 0x44e: jne    492 <tail_handle_ipv6+0x492> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x44e, 0x492, x86_l_492);
x86_l_450:
	/* 0x450: movzx  eax,BYTE PTR [rsp+0x11] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 17ULL);
x86_l_455:
	/* 0x455: lea    r8d,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_45d:
	/* 0x45d: jmp    52d <tail_handle_ipv6+0x52d> */
	X86_SIM_X86_JMP(0x45d, 0x52d, x86_l_52d);
x86_l_462:
	/* 0x462: movzx  esi,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_467:
	/* 0x467: mov    ebp,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RSI, X86_WIDTH_32);
x86_l_469:
	/* 0x469: cmp    rax,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 59ULL);
x86_l_46d:
	/* 0x46d: mov    r14d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 0ULL);
x86_l_473:
	/* 0x473: je     fd5 <tail_handle_ipv6+0xfd5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x473, 0xfd5, x86_l_fd5);
x86_l_479:
	/* 0x479: jmp    8ee <tail_handle_ipv6+0x8ee> */
	X86_SIM_X86_JMP(0x479, 0x8ee, x86_l_8ee);
x86_l_47e:
	/* 0x47e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_480:
	/* 0x480: jmp    8ee <tail_handle_ipv6+0x8ee> */
	X86_SIM_X86_JMP(0x480, 0x8ee, x86_l_8ee);
x86_l_485:
	/* 0x485: mov    rcx,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_48d:
	/* 0x48d: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_492:
	/* 0x492: movzx  eax,BYTE PTR [rsp+0x11] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 17ULL);
x86_l_497:
	/* 0x497: lea    r8d,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_49f:
	/* 0x49f: cmp    BYTE PTR [rsp+0x8],0x2c */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738412ULL);
x86_l_4a4:
	/* 0x4a4: je     4b9 <tail_handle_ipv6+0x4b9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4a4, 0x4b9, x86_l_4b9);
x86_l_4a6:
	/* 0x4a6: jmp    52d <tail_handle_ipv6+0x52d> */
	X86_SIM_X86_JMP(0x4a6, 0x52d, x86_l_52d);
x86_l_4ab:
	/* 0x4ab: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4ae:
	/* 0x4ae: jmp    5fb <tail_handle_ipv6+0x5fb> */
	X86_SIM_X86_JMP(0x4ae, 0x5fb, x86_l_5fb);
x86_l_4b3:
	/* 0x4b3: mov    r8d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 8ULL);
x86_l_4b9:
	/* 0x4b9: mov    r14,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R8, X86_WIDTH_64);
x86_l_4bc:
	/* 0x4bc: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_4c5:
	/* 0x4c5: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4ca:
	/* 0x4ca: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_4cf:
	/* 0x4cf: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_4d2:
	/* 0x4d2: mov    esi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_4d5:
	/* 0x4d5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_4da:
	/* 0x4da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4dc:
	/* 0x4dc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4de:
	/* 0x4de: js     fcf <tail_handle_ipv6+0xfcf> */
	X86_SIM_X86_JCC(X86_CC_S, 0x4de, 0xfcf, x86_l_fcf);
x86_l_4e4:
	/* 0x4e4: mov    eax,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_4e8:
	/* 0x4e8: movzx  ecx,BYTE PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_4ed:
	/* 0x4ed: shl    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_4f1:
	/* 0x4f1: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_4f4:
	/* 0x4f4: movzx  eax,WORD PTR [rsp+0x12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18ULL);
x86_l_4f9:
	/* 0x4f9: movabs rdx,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1099511627776ULL);
x86_l_503:
	/* 0x503: or     rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_506:
	/* 0x506: test   eax,0xf9ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63999ULL);
x86_l_50b:
	/* 0x50b: cmove  rdx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_64, X86_CC_E);
x86_l_50f:
	/* 0x50f: movabs rcx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2199023255552ULL);
x86_l_519:
	/* 0x519: or     rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_OR);
x86_l_51c:
	/* 0x51c: test   eax,0xf8ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63743ULL);
x86_l_521:
	/* 0x521: cmove  rcx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_525:
	/* 0x525: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_52a:
	/* 0x52a: mov    r8,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R14, X86_WIDTH_64);
x86_l_52d:
	/* 0x52d: movzx  r14d,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R14, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_531:
	/* 0x531: lea    edi,[r8+rdx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_535:
	/* 0x535: cmp    r14d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 60ULL);
x86_l_539:
	/* 0x539: ja     83f <tail_handle_ipv6+0x83f> */
	X86_SIM_X86_JCC(X86_CC_A, 0x539, 0x83f, x86_l_83f);
x86_l_53f:
	/* 0x53f: mov    eax,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_32);
x86_l_542:
	/* 0x542: movabs rsi,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_54c:
	/* 0x54c: bt     rsi,rax */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_550:
	/* 0x550: jae    5bd <tail_handle_ipv6+0x5bd> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x550, 0x5bd, x86_l_5bd);
x86_l_552:
	/* 0x552: mov    QWORD PTR [rsp+0x48],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_557:
	/* 0x557: mov    r15,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RCX, X86_WIDTH_64);
x86_l_55a:
	/* 0x55a: lea    esi,[r8+rdx*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_55e:
	/* 0x55e: add    esi,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 14ULL);
x86_l_561:
	/* 0x561: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_566:
	/* 0x566: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_56b:
	/* 0x56b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_56e:
	/* 0x56e: mov    DWORD PTR [rsp+0x8],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_572:
	/* 0x572: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_577:
	/* 0x577: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_579:
	/* 0x579: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_57b:
	/* 0x57b: js     fcf <tail_handle_ipv6+0xfcf> */
	X86_SIM_X86_JCC(X86_CC_S, 0x57b, 0xfcf, x86_l_fcf);
x86_l_581:
	/* 0x581: movzx  edi,BYTE PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_586:
	/* 0x586: cmp    r14d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 43ULL);
x86_l_58a:
	/* 0x58a: jle    5e3 <tail_handle_ipv6+0x5e3> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x58a, 0x5e3, x86_l_5e3);
x86_l_58c:
	/* 0x58c: cmp    r14d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 44ULL);
x86_l_590:
	/* 0x590: mov    r8,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_595:
	/* 0x595: je     6f3 <tail_handle_ipv6+0x6f3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x595, 0x6f3, x86_l_6f3);
x86_l_59b:
	/* 0x59b: mov    rcx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_59e:
	/* 0x59e: cmp    r14d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 51ULL);
x86_l_5a2:
	/* 0x5a2: jne    6fb <tail_handle_ipv6+0x6fb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x5a2, 0x6fb, x86_l_6fb);
x86_l_5a8:
	/* 0x5a8: movzx  eax,BYTE PTR [rsp+0x11] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 17ULL);
x86_l_5ad:
	/* 0x5ad: lea    r9d,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_5b5:
	/* 0x5b5: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5b8:
	/* 0x5b8: jmp    791 <tail_handle_ipv6+0x791> */
	X86_SIM_X86_JMP(0x5b8, 0x791, x86_l_791);
x86_l_5bd:
	/* 0x5bd: mov    edx,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_32);
x86_l_5bf:
	/* 0x5bf: cmp    rax,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 59ULL);
x86_l_5c3:
	/* 0x5c3: mov    r14d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 0ULL);
x86_l_5c9:
	/* 0x5c9: je     fd5 <tail_handle_ipv6+0xfd5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5c9, 0xfd5, x86_l_fd5);
x86_l_5cf:
	/* 0x5cf: jmp    8ee <tail_handle_ipv6+0x8ee> */
	X86_SIM_X86_JMP(0x5cf, 0x8ee, x86_l_8ee);
x86_l_5d4:
	/* 0x5d4: movzx  eax,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_5d9:
	/* 0x5d9: mov    ebp,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_32);
x86_l_5db:
	/* 0x5db: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5de:
	/* 0x5de: jmp    8ee <tail_handle_ipv6+0x8ee> */
	X86_SIM_X86_JMP(0x5de, 0x8ee, x86_l_8ee);
x86_l_5e3:
	/* 0x5e3: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5e6:
	/* 0x5e6: mov    rcx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_5e9:
	/* 0x5e9: mov    r8,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_5ee:
	/* 0x5ee: jmp    6fe <tail_handle_ipv6+0x6fe> */
	X86_SIM_X86_JMP(0x5ee, 0x6fe, x86_l_6fe);
x86_l_5f3:
	/* 0x5f3: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5f6:
	/* 0x5f6: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_5f9:
	/* 0x5f9: jne    645 <tail_handle_ipv6+0x645> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x5f9, 0x645, x86_l_645);
x86_l_5fb:
	/* 0x5fb: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_600:
	/* 0x600: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_605:
	/* 0x605: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_608:
	/* 0x608: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_60a:
	/* 0x60a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_60f:
	/* 0x60f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_611:
	/* 0x611: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_613:
	/* 0x613: js     63a <tail_handle_ipv6+0x63a> */
	X86_SIM_X86_JCC(X86_CC_S, 0x613, 0x63a, x86_l_63a);
x86_l_615:
	/* 0x615: movzx  eax,WORD PTR [rsp+0x12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18ULL);
x86_l_61a:
	/* 0x61a: mov    r12d,0xffffff63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967139ULL);
x86_l_620:
	/* 0x620: test   eax,0xf9ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63999ULL);
x86_l_625:
	/* 0x625: movabs r15,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_62f:
	/* 0x62f: jne    26 <tail_handle_ipv6+0x26> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x62f, 0x26, x86_l_26);
x86_l_635:
	/* 0x635: jmp    bb <tail_handle_ipv6+0xbb> */
	X86_SIM_X86_JMP(0x635, 0xbb, x86_l_bb);
x86_l_63a:
	/* 0x63a: mov    r12d,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967162ULL);
x86_l_640:
	/* 0x640: jmp    26 <tail_handle_ipv6+0x26> */
	X86_SIM_X86_JMP(0x640, 0x26, x86_l_26);
x86_l_645:
	/* 0x645: movzx  r14d,BYTE PTR [rsp+0x11] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 17ULL);
x86_l_64b:
	/* 0x64b: shl    r14d,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_64f:
	/* 0x64f: cmp    esi,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 60ULL);
x86_l_652:
	/* 0x652: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_657:
	/* 0x657: ja     f4f <tail_handle_ipv6+0xf4f> */
	X86_SIM_X86_JCC(X86_CC_A, 0x657, 0xf4f, x86_l_f4f);
x86_l_65d:
	/* 0x65d: mov    eax,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RSI, X86_WIDTH_32);
x86_l_65f:
	/* 0x65f: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_669:
	/* 0x669: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_66d:
	/* 0x66d: jae    6e1 <tail_handle_ipv6+0x6e1> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x66d, 0x6e1, x86_l_6e1);
x86_l_66f:
	/* 0x66f: mov    DWORD PTR [rsp+0x48],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_673:
	/* 0x673: lea    eax,[rdx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_677:
	/* 0x677: lea    ebp,[r15+rax*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_67b:
	/* 0x67b: add    ebp,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 56ULL);
x86_l_67e:
	/* 0x67e: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_683:
	/* 0x683: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_688:
	/* 0x688: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_68b:
	/* 0x68b: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_68d:
	/* 0x68d: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_692:
	/* 0x692: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_694:
	/* 0x694: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_696:
	/* 0x696: js     6d3 <tail_handle_ipv6+0x6d3> */
	X86_SIM_X86_JCC(X86_CC_S, 0x696, 0x6d3, x86_l_6d3);
x86_l_698:
	/* 0x698: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_69b:
	/* 0x69b: movzx  r8d,BYTE PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_6a1:
	/* 0x6a1: mov    eax,DWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_6a5:
	/* 0x6a5: cmp    eax,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_6a8:
	/* 0x6a8: jle    849 <tail_handle_ipv6+0x849> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x6a8, 0x849, x86_l_849);
x86_l_6ae:
	/* 0x6ae: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_6b1:
	/* 0x6b1: mov    r14d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 0ULL);
x86_l_6b7:
	/* 0x6b7: je     5fb <tail_handle_ipv6+0x5fb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6b7, 0x5fb, x86_l_5fb);
x86_l_6bd:
	/* 0x6bd: cmp    eax,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 51ULL);
x86_l_6c0:
	/* 0x6c0: jne    84c <tail_handle_ipv6+0x84c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x6c0, 0x84c, x86_l_84c);
x86_l_6c6:
	/* 0x6c6: movzx  eax,BYTE PTR [rsp+0x11] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 17ULL);
x86_l_6cb:
	/* 0x6cb: shl    eax,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 2ULL);
x86_l_6ce:
	/* 0x6ce: jmp    85d <tail_handle_ipv6+0x85d> */
	X86_SIM_X86_JMP(0x6ce, 0x85d, x86_l_85d);
x86_l_6d3:
	/* 0x6d3: mov    r12d,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967162ULL);
x86_l_6d9:
	/* 0x6d9: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6dc:
	/* 0x6dc: jmp    26 <tail_handle_ipv6+0x26> */
	X86_SIM_X86_JMP(0x6dc, 0x26, x86_l_26);
x86_l_6e1:
	/* 0x6e1: cmp    rax,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 59ULL);
x86_l_6e5:
	/* 0x6e5: jne    f4f <tail_handle_ipv6+0xf4f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x6e5, 0xf4f, x86_l_f4f);
x86_l_6eb:
	/* 0x6eb: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6ee:
	/* 0x6ee: jmp    26 <tail_handle_ipv6+0x26> */
	X86_SIM_X86_JMP(0x6ee, 0x26, x86_l_26);
x86_l_6f3:
	/* 0x6f3: mov    r9d,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 8ULL);
x86_l_6f9:
	/* 0x6f9: jmp    715 <tail_handle_ipv6+0x715> */
	X86_SIM_X86_JMP(0x6f9, 0x715, x86_l_715);
x86_l_6fb:
	/* 0x6fb: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6fe:
	/* 0x6fe: movzx  eax,BYTE PTR [rsp+0x11] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 17ULL);
x86_l_703:
	/* 0x703: lea    r9d,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R9, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_70b:
	/* 0x70b: cmp    bpl,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 44ULL);
x86_l_70f:
	/* 0x70f: jne    791 <tail_handle_ipv6+0x791> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x70f, 0x791, x86_l_791);
x86_l_715:
	/* 0x715: mov    r15,r9 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R9, X86_WIDTH_64);
x86_l_718:
	/* 0x718: mov    ebp,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDI, X86_WIDTH_32);
x86_l_71a:
	/* 0x71a: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_723:
	/* 0x723: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_728:
	/* 0x728: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_72d:
	/* 0x72d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_730:
	/* 0x730: mov    esi,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_734:
	/* 0x734: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_739:
	/* 0x739: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_73b:
	/* 0x73b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_73d:
	/* 0x73d: js     fcf <tail_handle_ipv6+0xfcf> */
	X86_SIM_X86_JCC(X86_CC_S, 0x73d, 0xfcf, x86_l_fcf);
x86_l_743:
	/* 0x743: mov    eax,DWORD PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_747:
	/* 0x747: movzx  ecx,BYTE PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_74c:
	/* 0x74c: shl    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_750:
	/* 0x750: or     rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_753:
	/* 0x753: movzx  eax,WORD PTR [rsp+0x12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18ULL);
x86_l_758:
	/* 0x758: movabs rdx,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1099511627776ULL);
x86_l_762:
	/* 0x762: or     rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_OR);
x86_l_765:
	/* 0x765: test   eax,0xf9ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63999ULL);
x86_l_76a:
	/* 0x76a: cmove  rdx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RCX, X86_WIDTH_64, X86_CC_E);
x86_l_76e:
	/* 0x76e: movabs rcx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2199023255552ULL);
x86_l_778:
	/* 0x778: or     rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_OR);
x86_l_77b:
	/* 0x77b: test   eax,0xf8ff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 63743ULL);
x86_l_780:
	/* 0x780: cmove  rcx,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_784:
	/* 0x784: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_787:
	/* 0x787: mov    edi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBP, X86_WIDTH_32);
x86_l_789:
	/* 0x789: mov    r8,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_78e:
	/* 0x78e: mov    r9,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_R15, X86_WIDTH_64);
x86_l_791:
	/* 0x791: movzx  r15d,dil */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_RDI, X86_WIDTH_32, X86_WIDTH_8);
x86_l_795:
	/* 0x795: lea    edx,[r9+r8*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_799:
	/* 0x799: cmp    r15d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 60ULL);
x86_l_79d:
	/* 0x79d: ja     8ec <tail_handle_ipv6+0x8ec> */
	X86_SIM_X86_JCC(X86_CC_A, 0x79d, 0x8ec, x86_l_8ec);
x86_l_7a3:
	/* 0x7a3: mov    eax,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_7a6:
	/* 0x7a6: movabs rsi,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_7b0:
	/* 0x7b0: bt     rsi,rax */
	X86_SIM_L_EXEC_BT(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_7b4:
	/* 0x7b4: jae    82e <tail_handle_ipv6+0x82e> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x7b4, 0x82e, x86_l_82e);
x86_l_7b6:
	/* 0x7b6: mov    r14d,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_32);
x86_l_7b9:
	/* 0x7b9: lea    ebp,[r9+r8*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_R8, 0), 0ULL);
x86_l_7bd:
	/* 0x7bd: add    ebp,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 14ULL);
x86_l_7c0:
	/* 0x7c0: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7c5:
	/* 0x7c5: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_7ca:
	/* 0x7ca: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_7cd:
	/* 0x7cd: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_7cf:
	/* 0x7cf: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_7d4:
	/* 0x7d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7d6:
	/* 0x7d6: mov    r12d,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967162ULL);
x86_l_7dc:
	/* 0x7dc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_7de:
	/* 0x7de: js     fd5 <tail_handle_ipv6+0xfd5> */
	X86_SIM_X86_JCC(X86_CC_S, 0x7de, 0xfd5, x86_l_fd5);
x86_l_7e4:
	/* 0x7e4: cmp    r15d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 43ULL);
x86_l_7e8:
	/* 0x7e8: jle    7f6 <tail_handle_ipv6+0x7f6> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x7e8, 0x7f6, x86_l_7f6);
x86_l_7ea:
	/* 0x7ea: cmp    r15d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 44ULL);
x86_l_7ee:
	/* 0x7ee: je     7fc <tail_handle_ipv6+0x7fc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7ee, 0x7fc, x86_l_7fc);
x86_l_7f0:
	/* 0x7f0: cmp    r15d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 51ULL);
x86_l_7f4:
	/* 0x7f4: je     823 <tail_handle_ipv6+0x823> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7f4, 0x823, x86_l_823);
x86_l_7f6:
	/* 0x7f6: cmp    r14b,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 44ULL);
x86_l_7fa:
	/* 0x7fa: jne    823 <tail_handle_ipv6+0x823> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x7fa, 0x823, x86_l_823);
x86_l_7fc:
	/* 0x7fc: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_805:
	/* 0x805: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_80a:
	/* 0x80a: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_80f:
	/* 0x80f: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_812:
	/* 0x812: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_814:
	/* 0x814: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_819:
	/* 0x819: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_81b:
	/* 0x81b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_81d:
	/* 0x81d: js     fcf <tail_handle_ipv6+0xfcf> */
	X86_SIM_X86_JCC(X86_CC_S, 0x81d, 0xfcf, x86_l_fcf);
x86_l_823:
	/* 0x823: mov    r12d,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967140ULL);
x86_l_829:
	/* 0x829: jmp    fd5 <tail_handle_ipv6+0xfd5> */
	X86_SIM_X86_JMP(0x829, 0xfd5, x86_l_fd5);
x86_l_82e:
	/* 0x82e: mov    ebp,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDI, X86_WIDTH_32);
x86_l_830:
	/* 0x830: cmp    rax,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 59ULL);
x86_l_834:
	/* 0x834: je     fd5 <tail_handle_ipv6+0xfd5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x834, 0xfd5, x86_l_fd5);
x86_l_83a:
	/* 0x83a: jmp    8ee <tail_handle_ipv6+0x8ee> */
	X86_SIM_X86_JMP(0x83a, 0x8ee, x86_l_8ee);
x86_l_83f:
	/* 0x83f: mov    edx,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_32);
x86_l_841:
	/* 0x841: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_844:
	/* 0x844: jmp    8ee <tail_handle_ipv6+0x8ee> */
	X86_SIM_X86_JMP(0x844, 0x8ee, x86_l_8ee);
x86_l_849:
	/* 0x849: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_84c:
	/* 0x84c: cmp    eax,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_84f:
	/* 0x84f: je     5fb <tail_handle_ipv6+0x5fb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x84f, 0x5fb, x86_l_5fb);
x86_l_855:
	/* 0x855: movzx  eax,BYTE PTR [rsp+0x11] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 17ULL);
x86_l_85a:
	/* 0x85a: shl    eax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHL, 3ULL);
x86_l_85d:
	/* 0x85d: cmp    r8d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R8, X86_WIDTH_32, 60ULL);
x86_l_861:
	/* 0x861: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_866:
	/* 0x866: ja     f4f <tail_handle_ipv6+0xf4f> */
	X86_SIM_X86_JCC(X86_CC_A, 0x866, 0xf4f, x86_l_f4f);
x86_l_86c:
	/* 0x86c: mov    rdi,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RCX, X86_WIDTH_64);
x86_l_86f:
	/* 0x86f: mov    ecx,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R8, X86_WIDTH_32);
x86_l_872:
	/* 0x872: movabs rdx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_87c:
	/* 0x87c: bt     rdx,rcx */
	X86_SIM_L_EXEC_BT(X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_880:
	/* 0x880: jae    f45 <tail_handle_ipv6+0xf45> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x880, 0xf45, x86_l_f45);
x86_l_886:
	/* 0x886: lea    ecx,[rsi+rdi*1] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 0), 0ULL);
x86_l_889:
	/* 0x889: add    ecx,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_ADD, 56ULL);
x86_l_88c:
	/* 0x88c: add    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_88e:
	/* 0x88e: lea    ebp,[r15+rcx*1] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 0), 0ULL);
x86_l_892:
	/* 0x892: add    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_ADD, 8ULL);
x86_l_895:
	/* 0x895: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_89a:
	/* 0x89a: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_89f:
	/* 0x89f: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_8a2:
	/* 0x8a2: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_8a4:
	/* 0x8a4: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_8a9:
	/* 0x8a9: mov    r14d,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R8, X86_WIDTH_32);
x86_l_8ac:
	/* 0x8ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8ae:
	/* 0x8ae: mov    r12d,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967162ULL);
x86_l_8b4:
	/* 0x8b4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_8b6:
	/* 0x8b6: js     6eb <tail_handle_ipv6+0x6eb> */
	X86_SIM_X86_JCC(X86_CC_S, 0x8b6, 0x6eb, x86_l_6eb);
x86_l_8bc:
	/* 0x8bc: mov    ecx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_32);
x86_l_8bf:
	/* 0x8bf: cmp    r14d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 43ULL);
x86_l_8c3:
	/* 0x8c3: jle    f5e <tail_handle_ipv6+0xf5e> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x8c3, 0xf5e, x86_l_f5e);
x86_l_8c9:
	/* 0x8c9: cmp    ecx,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 44ULL);
x86_l_8cc:
	/* 0x8cc: mov    r14d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 0ULL);
x86_l_8d2:
	/* 0x8d2: je     5fb <tail_handle_ipv6+0x5fb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8d2, 0x5fb, x86_l_5fb);
x86_l_8d8:
	/* 0x8d8: cmp    ecx,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 51ULL);
x86_l_8db:
	/* 0x8db: jne    f61 <tail_handle_ipv6+0xf61> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x8db, 0xf61, x86_l_f61);
x86_l_8e1:
	/* 0x8e1: mov    r12d,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967140ULL);
x86_l_8e7:
	/* 0x8e7: jmp    26 <tail_handle_ipv6+0x26> */
	X86_SIM_X86_JMP(0x8e7, 0x26, x86_l_26);
x86_l_8ec:
	/* 0x8ec: mov    ebp,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RDI, X86_WIDTH_32);
x86_l_8ee:
	/* 0x8ee: mov    BYTE PTR [rsp+0x7c],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 124ULL);
x86_l_8f3:
	/* 0x8f3: mov    rax,QWORD PTR [r13+0x2e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 46ULL);
x86_l_8f7:
	/* 0x8f7: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_8fc:
	/* 0x8fc: mov    rax,QWORD PTR [r13+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_900:
	/* 0x900: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_905:
	/* 0x905: mov    rax,QWORD PTR [r13+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_909:
	/* 0x909: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_90e:
	/* 0x90e: mov    rax,QWORD PTR [r13+0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_912:
	/* 0x912: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_917:
	/* 0x917: cmp    bpl,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 17ULL);
x86_l_91b:
	/* 0x91b: je     935 <tail_handle_ipv6+0x935> */
	X86_SIM_X86_JCC(X86_CC_E, 0x91b, 0x935, x86_l_935);
x86_l_91d:
	/* 0x91d: movzx  eax,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_921:
	/* 0x921: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_926:
	/* 0x926: mov    r15d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 0ULL);
x86_l_92c:
	/* 0x92c: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_92f:
	/* 0x92f: jne    cc7 <tail_handle_ipv6+0xcc7> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x92f, 0xcc7, x86_l_cc7);
x86_l_935:
	/* 0x935: lea    ebp,[rdx+0xe] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_938:
	/* 0x938: movabs rsi,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 2199023255552ULL);
x86_l_942:
	/* 0x942: lea    r15,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_947:
	/* 0x947: mov    rax,QWORD PTR [rip+0x14023] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_94e:
	/* 0x94e: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_951:
	/* 0x951: mov    QWORD PTR [rsp+0x48],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_956:
	/* 0x956: je     9b2 <tail_handle_ipv6+0x9b2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x956, 0x9b2, x86_l_9b2);
x86_l_958:
	/* 0x958: mov    r14,QWORD PTR [r13+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_95c:
	/* 0x95c: mov    QWORD PTR [r13+0xe],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60129542144ULL);
x86_l_964:
	/* 0x964: mov    DWORD PTR [r13+0xe],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_968:
	/* 0x968: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_96b:
	/* 0x96b: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_96f:
	/* 0x96f: mov    BYTE PTR [r13+0x12],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_973:
	/* 0x973: mov    r12,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_976:
	/* 0x976: mov    r13,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSI, X86_WIDTH_64);
x86_l_979:
	/* 0x979: test   rcx,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RSI, X86_WIDTH_64);
x86_l_97c:
	/* 0x97c: jne    13ca <tail_handle_ipv6+0x13ca> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x97c, 0x13ca, x86_l_13ca);
x86_l_982:
	/* 0x982: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_987:
	/* 0x987: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_98a:
	/* 0x98a: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_98c:
	/* 0x98c: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_98f:
	/* 0x98f: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_994:
	/* 0x994: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_996:
	/* 0x996: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_998:
	/* 0x998: js     ae4 <tail_handle_ipv6+0xae4> */
	X86_SIM_X86_JCC(X86_CC_S, 0x998, 0xae4, x86_l_ae4);
x86_l_99e:
	/* 0x99e: bt     r12,0x28 */
	X86_SIM_L_EXEC_BT_IMM(X86_R12, X86_WIDTH_64, 40ULL);
x86_l_9a3:
	/* 0x9a3: jb     13f0 <tail_handle_ipv6+0x13f0> */
	X86_SIM_X86_JCC(X86_CC_B, 0x9a3, 0x13f0, x86_l_13f0);
x86_l_9a9:
	/* 0x9a9: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9ad:
	/* 0x9ad: mov    QWORD PTR [rax],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9b0:
	/* 0x9b0: jmp    9e0 <tail_handle_ipv6+0x9e0> */
	X86_SIM_X86_JMP(0x9b0, 0x9e0, x86_l_9e0);
x86_l_9b2:
	/* 0x9b2: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9b5:
	/* 0x9b5: test   rcx,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RSI, X86_WIDTH_64);
x86_l_9b8:
	/* 0x9b8: jne    1465 <tail_handle_ipv6+0x1465> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x9b8, 0x1465, x86_l_1465);
x86_l_9be:
	/* 0x9be: mov    r12,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RCX, X86_WIDTH_64);
x86_l_9c1:
	/* 0x9c1: mov    r13,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSI, X86_WIDTH_64);
x86_l_9c4:
	/* 0x9c4: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_9c9:
	/* 0x9c9: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_9cc:
	/* 0x9cc: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_9ce:
	/* 0x9ce: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_9d1:
	/* 0x9d1: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_9d6:
	/* 0x9d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9d8:
	/* 0x9d8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_9da:
	/* 0x9da: js     b27 <tail_handle_ipv6+0xb27> */
	X86_SIM_X86_JCC(X86_CC_S, 0x9da, 0xb27, x86_l_b27);
x86_l_9e0:
	/* 0x9e0: movzx  eax,BYTE PTR [rsp+0x7c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 124ULL);
x86_l_9e5:
	/* 0x9e5: mov    BYTE PTR [rsp+0xac],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 172ULL);
x86_l_9ec:
	/* 0x9ec: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_9f1:
	/* 0x9f1: mov    rcx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_9f6:
	/* 0x9f6: mov    QWORD PTR [rsp+0xa0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_9fe:
	/* 0x9fe: mov    QWORD PTR [rsp+0x98],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_a06:
	/* 0xa06: movzx  eax,WORD PTR [rsp+0x7a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 122ULL);
x86_l_a0b:
	/* 0xa0b: mov    WORD PTR [rsp+0xa8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_a13:
	/* 0xa13: mov    WORD PTR [rsp+0xaa],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 730144440320ULL);
x86_l_a1d:
	/* 0xa1d: mov    BYTE PTR [rsp+0xad],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 743029342208ULL);
x86_l_a25:
	/* 0xa25: mov    rdi,QWORD PTR [rip+0x14023] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb6_services_v2)));
x86_l_a2c:
	/* 0xa2c: lea    rsi,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_a34:
	/* 0xa34: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a39:
	/* 0xa39: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a3b:
	/* 0xa3b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a3e:
	/* 0xa3e: je     a8b <tail_handle_ipv6+0xa8b> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa3e, 0xa8b, x86_l_a8b);
x86_l_a40:
	/* 0xa40: test   BYTE PTR [rax+0x9],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38654705696ULL);
x86_l_a44:
	/* 0xa44: je     a69 <tail_handle_ipv6+0xa69> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa44, 0xa69, x86_l_a69);
x86_l_a46:
	/* 0xa46: mov    BYTE PTR [rsp+0xad],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 743029342209ULL);
x86_l_a4e:
	/* 0xa4e: mov    rdi,QWORD PTR [rip+0x14023] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb6_services_v2)));
x86_l_a55:
	/* 0xa55: lea    rsi,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_a5d:
	/* 0xa5d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a62:
	/* 0xa62: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a64:
	/* 0xa64: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a67:
	/* 0xa67: je     a8b <tail_handle_ipv6+0xa8b> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa67, 0xa8b, x86_l_a8b);
x86_l_a69:
	/* 0xa69: movzx  ecx,BYTE PTR [rax+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_a6d:
	/* 0xa6d: test   cl,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 4ULL);
x86_l_a70:
	/* 0xa70: je     cb1 <tail_handle_ipv6+0xcb1> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa70, 0xcb1, x86_l_cb1);
x86_l_a76:
	/* 0xa76: mov    r14d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a79:
	/* 0xa79: test   r14d,r14d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_32);
x86_l_a7c:
	/* 0xa7c: je     cb1 <tail_handle_ipv6+0xcb1> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa7c, 0xcb1, x86_l_cb1);
x86_l_a82:
	/* 0xa82: shl    r14d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_a86:
	/* 0xa86: jmp    cc2 <tail_handle_ipv6+0xcc2> */
	X86_SIM_X86_JMP(0xa86, 0xcc2, x86_l_cc2);
x86_l_a8b:
	/* 0xa8b: mov    r15,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_64);
x86_l_a8e:
	/* 0xa8e: mov    rax,QWORD PTR [rsp+0x76] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 118ULL);
x86_l_a93:
	/* 0xa93: mov    QWORD PTR [rsp+0x2e],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 46ULL);
x86_l_a98:
	/* 0xa98: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_a9d:
	/* 0xa9d: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_aa2:
	/* 0xaa2: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_aa7:
	/* 0xaa7: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_aac:
	/* 0xaac: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_ab1:
	/* 0xab1: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_ab6:
	/* 0xab6: mov    QWORD PTR [rsp+0x28],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_abb:
	/* 0xabb: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ac0:
	/* 0xac0: mov    QWORD PTR [rsp+0x18],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ac5:
	/* 0xac5: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_aca:
	/* 0xaca: rol    DWORD PTR [rsp+0x30],0x10 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_32, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_ROL)), 206158430224ULL);
x86_l_acf:
	/* 0xacf: movzx  ebp,BYTE PTR [rsp+0x35] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 53ULL);
x86_l_ad4:
	/* 0xad4: cmp    BYTE PTR [rsp+0x34],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 223338299398ULL);
x86_l_ad9:
	/* 0xad9: jne    af6 <tail_handle_ipv6+0xaf6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xad9, 0xaf6, x86_l_af6);
x86_l_adb:
	/* 0xadb: mov    rdi,QWORD PTR [rip+0x14023] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct6_global)));
x86_l_ae2:
	/* 0xae2: jmp    afd <tail_handle_ipv6+0xafd> */
	X86_SIM_X86_JMP(0xae2, 0xafd, x86_l_afd);
x86_l_ae4:
	/* 0xae4: mov    r12d,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967161ULL);
x86_l_aea:
	/* 0xaea: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_aee:
	/* 0xaee: mov    QWORD PTR [rax],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_af1:
	/* 0xaf1: jmp    fd5 <tail_handle_ipv6+0xfd5> */
	X86_SIM_X86_JMP(0xaf1, 0xfd5, x86_l_fd5);
x86_l_af6:
	/* 0xaf6: mov    rdi,QWORD PTR [rip+0x14023] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct_any6_global)));
x86_l_afd:
	/* 0xafd: mov    BYTE PTR [rsp+0x35],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 227633266688ULL);
x86_l_b02:
	/* 0xb02: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b07:
	/* 0xb07: mov    r14d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 1ULL);
x86_l_b0d:
	/* 0xb0d: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_b10:
	/* 0xb10: mov    BYTE PTR [rsp+0x35],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 53ULL);
x86_l_b15:
	/* 0xb15: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b18:
	/* 0xb18: je     b32 <tail_handle_ipv6+0xb32> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb18, 0xb32, x86_l_b32);
x86_l_b1a:
	/* 0xb1a: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b1c:
	/* 0xb1c: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b1f:
	/* 0xb1f: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b22:
	/* 0xb22: jmp    cc7 <tail_handle_ipv6+0xcc7> */
	X86_SIM_X86_JMP(0xb22, 0xcc7, x86_l_cc7);
x86_l_b27:
	/* 0xb27: mov    r12d,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967161ULL);
x86_l_b2d:
	/* 0xb2d: jmp    fd8 <tail_handle_ipv6+0xfd8> */
	X86_SIM_X86_JMP(0xb2d, 0xfd8, x86_l_fd8);
x86_l_b32:
	/* 0xb32: movabs rax,0x2000000000000a0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 144115188075856032ULL);
x86_l_b3c:
	/* 0xb3c: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_b44:
	/* 0xb44: mov    rax,QWORD PTR [rsp+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_b4c:
	/* 0xb4c: mov    rcx,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_b54:
	/* 0xb54: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_b5c:
	/* 0xb5c: mov    QWORD PTR [rsp+0x90],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_b64:
	/* 0xb64: mov    rdi,QWORD PTR [rip+0x14023] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipcache_v2)));
x86_l_b6b:
	/* 0xb6b: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_b73:
	/* 0xb73: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_b76:
	/* 0xb76: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b79:
	/* 0xb79: je     b1a <tail_handle_ipv6+0xb1a> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb79, 0xb1a, x86_l_b1a);
x86_l_b7b:
	/* 0xb7b: movbe  cx,WORD PTR [rsp+0xa8] */
	X86_SIM_RUN_OP(X86_OP_MOVBE_LOAD, X86_RCX, X86_RSP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 168ULL);
x86_l_b85:
	/* 0xb85: mov    rdx,QWORD PTR [rip+0x14023] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_nodeport_port_min)));
x86_l_b8c:
	/* 0xb8c: cmp    cx,WORD PTR [rdx] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_b8f:
	/* 0xb8f: jb     b9d <tail_handle_ipv6+0xb9d> */
	X86_SIM_X86_JCC(X86_CC_B, 0xb8f, 0xb9d, x86_l_b9d);
x86_l_b91:
	/* 0xb91: mov    rdx,QWORD PTR [rip+0x14023] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_nodeport_port_max)));
x86_l_b98:
	/* 0xb98: cmp    cx,WORD PTR [rdx] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RDX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_b9b:
	/* 0xb9b: jbe    baa <tail_handle_ipv6+0xbaa> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xb9b, 0xbaa, x86_l_baa);
x86_l_b9d:
	/* 0xb9d: cmp    DWORD PTR [rax],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_ba0:
	/* 0xba0: jne    b1a <tail_handle_ipv6+0xb1a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xba0, 0xb1a, x86_l_b1a);
x86_l_ba6:
	/* 0xba6: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ba8:
	/* 0xba8: jmp    bb8 <tail_handle_ipv6+0xbb8> */
	X86_SIM_X86_JMP(0xba8, 0xbb8, x86_l_bb8);
x86_l_baa:
	/* 0xbaa: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bac:
	/* 0xbac: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_baf:
	/* 0xbaf: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_bb2:
	/* 0xbb2: jne    f1a <tail_handle_ipv6+0xf1a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xbb2, 0xf1a, x86_l_f1a);
x86_l_bb8:
	/* 0xbb8: mov    WORD PTR [rsp+0xaa],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 730144440320ULL);
x86_l_bc2:
	/* 0xbc2: mov    BYTE PTR [rsp+0xad],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 743029342208ULL);
x86_l_bca:
	/* 0xbca: mov    QWORD PTR [rsp+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_bd6:
	/* 0xbd6: mov    QWORD PTR [rsp+0xa0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 687194767360ULL);
x86_l_be2:
	/* 0xbe2: mov    rdi,QWORD PTR [rip+0x14023] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb6_services_v2)));
x86_l_be9:
	/* 0xbe9: lea    rsi,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_bf1:
	/* 0xbf1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_bf6:
	/* 0xbf6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bf8:
	/* 0xbf8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_bfb:
	/* 0xbfb: je     b1a <tail_handle_ipv6+0xb1a> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbfb, 0xb1a, x86_l_b1a);
x86_l_c01:
	/* 0xc01: test   BYTE PTR [rax+0x9],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38654705696ULL);
x86_l_c05:
	/* 0xc05: je     c2e <tail_handle_ipv6+0xc2e> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc05, 0xc2e, x86_l_c2e);
x86_l_c07:
	/* 0xc07: mov    BYTE PTR [rsp+0xad],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 743029342209ULL);
x86_l_c0f:
	/* 0xc0f: mov    rdi,QWORD PTR [rip+0x14023] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb6_services_v2)));
x86_l_c16:
	/* 0xc16: lea    rsi,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_c1e:
	/* 0xc1e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c23:
	/* 0xc23: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c25:
	/* 0xc25: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c28:
	/* 0xc28: je     b1a <tail_handle_ipv6+0xb1a> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc28, 0xb1a, x86_l_b1a);
x86_l_c2e:
	/* 0xc2e: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_c31:
	/* 0xc31: movzx  eax,BYTE PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_c35:
	/* 0xc35: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_c38:
	/* 0xc38: je     c44 <tail_handle_ipv6+0xc44> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc38, 0xc44, x86_l_c44);
x86_l_c3a:
	/* 0xc3a: test   al,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 2ULL);
x86_l_c3c:
	/* 0xc3c: je     b1a <tail_handle_ipv6+0xb1a> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc3c, 0xb1a, x86_l_b1a);
x86_l_c42:
	/* 0xc42: jmp    c4c <tail_handle_ipv6+0xc4c> */
	X86_SIM_X86_JMP(0xc42, 0xc4c, x86_l_c4c);
x86_l_c44:
	/* 0xc44: test   al,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 8ULL);
x86_l_c46:
	/* 0xc46: je     b1a <tail_handle_ipv6+0xb1a> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc46, 0xb1a, x86_l_b1a);
x86_l_c4c:
	/* 0xc4c: mov    DWORD PTR [rsp+0xe0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 962072674304ULL);
x86_l_c57:
	/* 0xc57: mov    rax,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_c5c:
	/* 0xc5c: mov    rcx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_c61:
	/* 0xc61: mov    QWORD PTR [rsp+0x88],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_c69:
	/* 0xc69: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_c71:
	/* 0xc71: movzx  eax,WORD PTR [rsp+0x7a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 122ULL);
x86_l_c76:
	/* 0xc76: mov    WORD PTR [rsp+0x90],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_c7e:
	/* 0xc7e: mov    rdi,QWORD PTR [rip+0x14023] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_nodeport_nat_buffer)));
x86_l_c85:
	/* 0xc85: lea    rsi,[rsp+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_c8d:
	/* 0xc8d: lea    rdx,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_c95:
	/* 0xc95: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_c9a:
	/* 0xc9a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c9c:
	/* 0xc9c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c9e:
	/* 0xc9e: mov    rbp,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R15, X86_WIDTH_64);
x86_l_ca1:
	/* 0xca1: mov    rax,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_ca4:
	/* 0xca4: movzx  ecx,BYTE PTR [rax+0x9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 9ULL);
x86_l_ca8:
	/* 0xca8: test   cl,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 4ULL);
x86_l_cab:
	/* 0xcab: jne    a76 <tail_handle_ipv6+0xa76> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xcab, 0xa76, x86_l_a76);
x86_l_cb1:
	/* 0xcb1: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_cb4:
	/* 0xcb4: test   cl,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 8ULL);
x86_l_cb7:
	/* 0xcb7: je     d01 <tail_handle_ipv6+0xd01> */
	X86_SIM_X86_JCC(X86_CC_E, 0xcb7, 0xd01, x86_l_d01);
x86_l_cb9:
	/* 0xcb9: movzx  ecx,BYTE PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_cbd:
	/* 0xcbd: and    cl,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_AND, 8ULL);
x86_l_cc0:
	/* 0xcc0: jne    d01 <tail_handle_ipv6+0xd01> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xcc0, 0xd01, x86_l_d01);
x86_l_cc2:
	/* 0xcc2: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_cc4:
	/* 0xcc4: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_cc7:
	/* 0xcc7: mov    DWORD PTR [rbx+0x30],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ccb:
	/* 0xccb: shl    esi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHL, 16ULL);
x86_l_cce:
	/* 0xcce: movzx  eax,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_cd2:
	/* 0xcd2: and    eax,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 1ULL);
x86_l_cd5:
	/* 0xcd5: or     eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_OR);
x86_l_cd7:
	/* 0xcd7: mov    DWORD PTR [rbx+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_cda:
	/* 0xcda: mov    rsi,QWORD PTR [rip+0x14023] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_ce1:
	/* 0xce1: mov    r14d,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 33ULL);
x86_l_ce7:
	/* 0xce7: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_cec:
	/* 0xcec: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_cef:
	/* 0xcef: mov    edx,0x21 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_cf4:
	/* 0xcf4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cf6:
	/* 0xcf6: mov    r12d,0xffffff74 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967156ULL);
x86_l_cfc:
	/* 0xcfc: jmp    fd8 <tail_handle_ipv6+0xfd8> */
	X86_SIM_X86_JMP(0xcfc, 0xfd8, x86_l_fd8);
x86_l_d01:
	/* 0xd01: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d05:
	/* 0xd05: mov    rax,QWORD PTR [rip+0x14023] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_lrp)));
x86_l_d0c:
	/* 0xd0c: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_d0f:
	/* 0xd0f: movzx  r15d,BYTE PTR [rsp+0x7c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 124ULL);
x86_l_d15:
	/* 0xd15: cmp    r15b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_8, 6ULL);
x86_l_d19:
	/* 0xd19: jne    d24 <tail_handle_ipv6+0xd24> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xd19, 0xd24, x86_l_d24);
x86_l_d1b:
	/* 0xd1b: mov    rax,QWORD PTR [rip+0x14023] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&cilium_ct6_global)));
x86_l_d22:
	/* 0xd22: jmp    d2b <tail_handle_ipv6+0xd2b> */
	X86_SIM_X86_JMP(0xd22, 0xd2b, x86_l_d2b);
x86_l_d24:
	/* 0xd24: mov    rax,QWORD PTR [rip+0x14023] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&cilium_ct_any6_global)));
x86_l_d2b:
	/* 0xd2b: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d30:
	/* 0xd30: mov    rcx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_d35:
	/* 0xd35: movzx  eax,BYTE PTR [rsp+0x7d] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 125ULL);
x86_l_d3a:
	/* 0xd3a: mov    BYTE PTR [rsp+0x57],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 87ULL);
x86_l_d3e:
	/* 0xd3e: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_d43:
	/* 0xd43: mov    QWORD PTR [rsp+0xf8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_d4b:
	/* 0xd4b: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_d50:
	/* 0xd50: mov    QWORD PTR [rsp+0xd0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_d58:
	/* 0xd58: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d5c:
	/* 0xd5c: movzx  eax,WORD PTR [rax+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_d60:
	/* 0xd60: mov    QWORD PTR [rsp+0xb8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_d68:
	/* 0xd68: mov    BYTE PTR [rsp+0x7d],0x4 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 536870912004ULL);
x86_l_d6d:
	/* 0xd6d: mov    DWORD PTR [rsp+0xe0],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 962072674304ULL);
x86_l_d78:
	/* 0xd78: mov    rax,QWORD PTR [rip+0x14023] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_ipv6_fragments)));
x86_l_d7f:
	/* 0xd7f: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d82:
	/* 0xd82: je     e12 <tail_handle_ipv6+0xe12> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd82, 0xe12, x86_l_e12);
x86_l_d88:
	/* 0xd88: movabs rax,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 1099511627776ULL);
x86_l_d92:
	/* 0xd92: and    rax,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R12, X86_WIDTH_64, X86_ALU_AND);
x86_l_d95:
	/* 0xd95: je     e12 <tail_handle_ipv6+0xe12> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd95, 0xe12, x86_l_e12);
x86_l_d97:
	/* 0xd97: mov    r14d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d9a:
	/* 0xd9a: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_da3:
	/* 0xda3: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_dac:
	/* 0xdac: movabs rax,0x6c02a30309 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 463900705545ULL);
x86_l_db6:
	/* 0xdb6: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_dbe:
	/* 0xdbe: mov    rdi,QWORD PTR [rip+0x14023] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_dc5:
	/* 0xdc5: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_dcd:
	/* 0xdcd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_dd2:
	/* 0xdd2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dd4:
	/* 0xdd4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_dd7:
	/* 0xdd7: je     de2 <tail_handle_ipv6+0xde2> */
	X86_SIM_X86_JCC(X86_CC_E, 0xdd7, 0xde2, x86_l_de2);
x86_l_dd9:
	/* 0xdd9: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_ddc:
	/* 0xddc: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_de0:
	/* 0xde0: jmp    e0d <tail_handle_ipv6+0xe0d> */
	X86_SIM_X86_JMP(0xde0, 0xe0d, x86_l_e0d);
x86_l_de2:
	/* 0xde2: mov    QWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_deb:
	/* 0xdeb: mov    QWORD PTR [rsp+0x18],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_df0:
	/* 0xdf0: mov    rdi,QWORD PTR [rip+0x14023] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_df7:
	/* 0xdf7: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_dff:
	/* 0xdff: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e04:
	/* 0xe04: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_e09:
	/* 0xe09: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e0b:
	/* 0xe0b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e0d:
	/* 0xe0d: mov    rcx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_e12:
	/* 0xe12: cmp    r15b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_8, 6ULL);
x86_l_e16:
	/* 0xe16: mov    QWORD PTR [rsp+0xd8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_e1e:
	/* 0xe1e: jne    e77 <tail_handle_ipv6+0xe77> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe1e, 0xe77, x86_l_e77);
x86_l_e20:
	/* 0xe20: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_e23:
	/* 0xe23: and    rax,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_e26:
	/* 0xe26: jne    e77 <tail_handle_ipv6+0xe77> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe26, 0xe77, x86_l_e77);
x86_l_e28:
	/* 0xe28: lea    esi,[rcx+0x1a] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_e2b:
	/* 0xe2b: lea    rdx,[rsp+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_e33:
	/* 0xe33: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_e38:
	/* 0xe38: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_e3b:
	/* 0xe3b: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_e40:
	/* 0xe40: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e42:
	/* 0xe42: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_e44:
	/* 0xe44: js     f0f <tail_handle_ipv6+0xf0f> */
	X86_SIM_X86_JCC(X86_CC_S, 0xe44, 0xf0f, x86_l_f0f);
x86_l_e4a:
	/* 0xe4a: mov    r14d,DWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_e52:
	/* 0xe52: mov    eax,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_32);
x86_l_e55:
	/* 0xe55: and    eax,0x1200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4608ULL);
x86_l_e5a:
	/* 0xe5a: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e5d:
	/* 0xe5d: cmp    eax,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 512ULL);
x86_l_e62:
	/* 0xe62: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_e65:
	/* 0xe65: test   r14d,0x500 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_R14, X86_WIDTH_32, 1280ULL);
x86_l_e6c:
	/* 0xe6c: jne    14b6 <tail_handle_ipv6+0x14b6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe6c, 0x14b6, x86_l_14b6);
x86_l_e72:
	/* 0xe72: mov    r12b,al */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_8);
x86_l_e75:
	/* 0xe75: jmp    e82 <tail_handle_ipv6+0xe82> */
	X86_SIM_X86_JMP(0xe75, 0xe82, x86_l_e82);
x86_l_e77:
	/* 0xe77: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e7a:
	/* 0xe7a: mov    r14d,DWORD PTR [rsp+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_e82:
	/* 0xe82: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e87:
	/* 0xe87: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_e8c:
	/* 0xe8c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e91:
	/* 0xe91: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_e94:
	/* 0xe94: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e96:
	/* 0xe96: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e99:
	/* 0xe99: mov    QWORD PTR [rsp+0xc8],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_ea1:
	/* 0xea1: je     15c2 <tail_handle_ipv6+0x15c2> */
	X86_SIM_X86_JCC(X86_CC_E, 0xea1, 0x15c2, x86_l_15c2);
x86_l_ea7:
	/* 0xea7: mov    rcx,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_eaf:
	/* 0xeaf: cmp    WORD PTR [rax+0x26],cx */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_eb3:
	/* 0xeb3: jne    15c2 <tail_handle_ipv6+0x15c2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xeb3, 0x15c2, x86_l_15c2);
x86_l_eb9:
	/* 0xeb9: mov    ecx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_32);
x86_l_ebc:
	/* 0xebc: and    ecx,0x200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 512ULL);
x86_l_ec2:
	/* 0xec2: mov    DWORD PTR [rsp+0xb0],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_ec9:
	/* 0xec9: mov    QWORD PTR [rsp+0x8],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ece:
	/* 0xece: je     104a <tail_handle_ipv6+0x104a> */
	X86_SIM_X86_JCC(X86_CC_E, 0xece, 0x104a, x86_l_104a);
x86_l_ed4:
	/* 0xed4: test   BYTE PTR [rax+0x24],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 154618822659ULL);
x86_l_ed8:
	/* 0xed8: je     104a <tail_handle_ipv6+0x104a> */
	X86_SIM_X86_JCC(X86_CC_E, 0xed8, 0x104a, x86_l_104a);
x86_l_ede:
	/* 0xede: mov    r13d,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R14, X86_WIDTH_32);
x86_l_ee1:
	/* 0xee1: mov    rcx,QWORD PTR [rip+0x14023] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_ee8:
	/* 0xee8: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_eeb:
	/* 0xeeb: je     ff2 <tail_handle_ipv6+0xff2> */
	X86_SIM_X86_JCC(X86_CC_E, 0xeeb, 0xff2, x86_l_ff2);
x86_l_ef1:
	/* 0xef1: mov    rdx,QWORD PTR [rip+0x14023] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_ef8:
	/* 0xef8: mov    r14d,DWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_efb:
	/* 0xefb: lea    edx,[r14+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_eff:
	/* 0xeff: shl    r14d,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHL, 5ULL);
x86_l_f03:
	/* 0xf03: sub    r14d,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RDX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_f06:
	/* 0xf06: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_f0a:
	/* 0xf0a: jmp    ff8 <tail_handle_ipv6+0xff8> */
	X86_SIM_X86_JMP(0xf0a, 0xff8, x86_l_ff8);
x86_l_f0f:
	/* 0xf0f: mov    r12d,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967161ULL);
x86_l_f15:
	/* 0xf15: jmp    fd5 <tail_handle_ipv6+0xfd5> */
	X86_SIM_X86_JMP(0xf15, 0xfd5, x86_l_fd5);
x86_l_f1a:
	/* 0xf1a: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_f1c:
	/* 0xf1c: and    edx,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_f1f:
	/* 0xf1f: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_f22:
	/* 0xf22: je     f36 <tail_handle_ipv6+0xf36> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf22, 0xf36, x86_l_f36);
x86_l_f24:
	/* 0xf24: and    ecx,0xff000000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4278190080ULL);
x86_l_f2a:
	/* 0xf2a: cmp    ecx,0x2000000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 33554432ULL);
x86_l_f30:
	/* 0xf30: jne    b1a <tail_handle_ipv6+0xb1a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf30, 0xb1a, x86_l_b1a);
x86_l_f36:
	/* 0xf36: test   BYTE PTR [rax+0x17],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 98784247816ULL);
x86_l_f3a:
	/* 0xf3a: jne    b1a <tail_handle_ipv6+0xb1a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf3a, 0xb1a, x86_l_b1a);
x86_l_f40:
	/* 0xf40: jmp    bb8 <tail_handle_ipv6+0xbb8> */
	X86_SIM_X86_JMP(0xf40, 0xbb8, x86_l_bb8);
x86_l_f45:
	/* 0xf45: cmp    rcx,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 59ULL);
x86_l_f49:
	/* 0xf49: je     6eb <tail_handle_ipv6+0x6eb> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf49, 0x6eb, x86_l_6eb);
x86_l_f4f:
	/* 0xf4f: movabs r15,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_f59:
	/* 0xf59: jmp    bb <tail_handle_ipv6+0xbb> */
	X86_SIM_X86_JMP(0xf59, 0xbb, x86_l_bb);
x86_l_f5e:
	/* 0xf5e: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f61:
	/* 0xf61: mov    r12d,0xffffff64 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967140ULL);
x86_l_f67:
	/* 0xf67: cmp    ecx,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 44ULL);
x86_l_f6a:
	/* 0xf6a: jne    26 <tail_handle_ipv6+0x26> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf6a, 0x26, x86_l_26);
x86_l_f70:
	/* 0xf70: jmp    5fb <tail_handle_ipv6+0x5fb> */
	X86_SIM_X86_JMP(0xf70, 0x5fb, x86_l_5fb);
x86_l_f75:
	/* 0xf75: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f7a:
	/* 0xf7a: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_f7f:
	/* 0xf7f: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_f82:
	/* 0xf82: mov    esi,0x36 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 54ULL);
x86_l_f87:
	/* 0xf87: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_f8c:
	/* 0xf8c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f8e:
	/* 0xf8e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_f90:
	/* 0xf90: js     fcf <tail_handle_ipv6+0xfcf> */
	X86_SIM_X86_JCC(X86_CC_S, 0xf90, 0xfcf, x86_l_fcf);
x86_l_f92:
	/* 0xf92: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f95:
	/* 0xf95: cmp    BYTE PTR [rsp+0x10],0x87 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68719476871ULL);
x86_l_f9a:
	/* 0xf9a: mov    r12d,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 0ULL);
x86_l_fa0:
	/* 0xfa0: jne    fd8 <tail_handle_ipv6+0xfd8> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xfa0, 0xfd8, x86_l_fd8);
x86_l_fa2:
	/* 0xfa2: movabs rax,0x20000000e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 8589934606ULL);
x86_l_fac:
	/* 0xfac: mov    QWORD PTR [rbx+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_fb0:
	/* 0xfb0: mov    rsi,QWORD PTR [rip+0x14023] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_fb7:
	/* 0xfb7: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_fbd:
	/* 0xfbd: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_fc2:
	/* 0xfc2: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_fc5:
	/* 0xfc5: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_fca:
	/* 0xfca: jmp    cf4 <tail_handle_ipv6+0xcf4> */
	X86_SIM_X86_JMP(0xfca, 0xcf4, x86_l_cf4);
x86_l_fcf:
	/* 0xfcf: mov    r12d,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967162ULL);
x86_l_fd5:
	/* 0xfd5: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_fd8:
	/* 0xfd8: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_fda:
	/* 0xfda: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_fdd:
	/* 0xfdd: js     26 <tail_handle_ipv6+0x26> */
	X86_SIM_X86_JCC(X86_CC_S, 0xfdd, 0x26, x86_l_26);
x86_l_fe3:
	/* 0xfe3: add    rsp,0x108 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 264ULL);
x86_l_fea:
	/* 0xfea: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_fec:
	/* 0xfec: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_fed:
	/* 0xfed: jmp    1df8 <tail_handle_ipv6+0x1df8> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_ff2:
	/* 0xff2: mov    r14d,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 30ULL);
x86_l_ff8:
	/* 0xff8: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_ffb:
	/* 0xffb: add    r14d,DWORD PTR [rax+0x30] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 48ULL);
x86_l_fff:
	/* 0xfff: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1002:
	/* 0x1002: je     1013 <tail_handle_ipv6+0x1013> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1002, 0x1013, x86_l_1013);
x86_l_1004:
	/* 0x1004: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_1009:
	/* 0x1009: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_100b:
	/* 0x100b: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_100d:
	/* 0x100d: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_1011:
	/* 0x1011: jmp    1036 <tail_handle_ipv6+0x1036> */
	X86_SIM_X86_JMP(0x1011, 0x1036, x86_l_1036);
x86_l_1013:
	/* 0x1013: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1018:
	/* 0x1018: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_101a:
	/* 0x101a: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_101c:
	/* 0x101c: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1020:
	/* 0x1020: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_102a:
	/* 0x102a: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_102d:
	/* 0x102d: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1032:
	/* 0x1032: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_1036:
	/* 0x1036: cmp    rax,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R14, X86_WIDTH_64);
x86_l_1039:
	/* 0x1039: mov    rax,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_64);
x86_l_103c:
	/* 0x103c: mov    r14d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R13, X86_WIDTH_32);
x86_l_103f:
	/* 0x103f: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1044:
	/* 0x1044: jae    15c2 <tail_handle_ipv6+0x15c2> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x1044, 0x15c2, x86_l_15c2);
x86_l_104a:
	/* 0x104a: mov    ecx,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_104d:
	/* 0x104d: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_104f:
	/* 0x104f: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1051:
	/* 0x1051: test   dl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_8, 3ULL);
x86_l_1054:
	/* 0x1054: je     1167 <tail_handle_ipv6+0x1167> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1054, 0x1167, x86_l_1167);
x86_l_105a:
	/* 0x105a: mov    r13d,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R14, X86_WIDTH_32);
x86_l_105d:
	/* 0x105d: mov    rsi,QWORD PTR [rip+0x14026] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1064:
	/* 0x1064: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1067:
	/* 0x1067: je     107a <tail_handle_ipv6+0x107a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1067, 0x107a, x86_l_107a);
x86_l_1069:
	/* 0x1069: mov    rdx,QWORD PTR [rip+0x14026] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1070:
	/* 0x1070: imul   r14d,DWORD PTR [rdx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R14, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_1074:
	/* 0x1074: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1078:
	/* 0x1078: jmp    1080 <tail_handle_ipv6+0x1080> */
	X86_SIM_X86_JMP(0x1078, 0x1080, x86_l_1080);
x86_l_107a:
	/* 0x107a: mov    r14d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 60ULL);
x86_l_1080:
	/* 0x1080: cmp    r15b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_8, 6ULL);
x86_l_1084:
	/* 0x1084: jne    10bd <tail_handle_ipv6+0x10bd> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1084, 0x10bd, x86_l_10bd);
x86_l_1086:
	/* 0x1086: mov    edx,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_32);
x86_l_1089:
	/* 0x1089: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_108b:
	/* 0x108b: shr    edx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_108e:
	/* 0x108e: and    edx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_1091:
	/* 0x1091: or     ecx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1093:
	/* 0x1093: mov    WORD PTR [rax+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1097:
	/* 0x1097: test   cl,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 16ULL);
x86_l_109a:
	/* 0x109a: mov    ecx,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 60ULL);
x86_l_109f:
	/* 0x109f: mov    r14d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 21600ULL);
x86_l_10a5:
	/* 0x10a5: cmove  r14d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R14, X86_RCX, X86_WIDTH_32, X86_CC_E);
x86_l_10a9:
	/* 0x10a9: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10ac:
	/* 0x10ac: je     10bd <tail_handle_ipv6+0x10bd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10ac, 0x10bd, x86_l_10bd);
x86_l_10ae:
	/* 0x10ae: mov    rcx,QWORD PTR [rip+0x14026] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_10b5:
	/* 0x10b5: imul   r14d,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RCX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_10b9:
	/* 0x10b9: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_10bd:
	/* 0x10bd: mov    QWORD PTR [rsp+0xc0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_10c5:
	/* 0x10c5: mov    ebp,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R13, X86_WIDTH_32);
x86_l_10c8:
	/* 0x10c8: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_10cb:
	/* 0x10cb: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10ce:
	/* 0x10ce: je     10e2 <tail_handle_ipv6+0x10e2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10ce, 0x10e2, x86_l_10e2);
x86_l_10d0:
	/* 0x10d0: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_10d5:
	/* 0x10d5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10d7:
	/* 0x10d7: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_10d9:
	/* 0x10d9: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_10dc:
	/* 0x10dc: shr    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_10e0:
	/* 0x10e0: jmp    1105 <tail_handle_ipv6+0x1105> */
	X86_SIM_X86_JMP(0x10e0, 0x1105, x86_l_1105);
x86_l_10e2:
	/* 0x10e2: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_10e7:
	/* 0x10e7: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10e9:
	/* 0x10e9: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_10eb:
	/* 0x10eb: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_10ef:
	/* 0x10ef: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_10f9:
	/* 0x10f9: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_10fc:
	/* 0x10fc: mulx   rcx,rcx,rcx */
	X86_SIM_L_EXEC_MULX(X86_RCX, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_1101:
	/* 0x1101: shr    rcx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_1105:
	/* 0x1105: add    r14d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1108:
	/* 0x1108: mov    rax,QWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_1110:
	/* 0x1110: mov    DWORD PTR [rax+0x20],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1114:
	/* 0x1114: movzx  edx,BYTE PTR [rax+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_1118:
	/* 0x1118: mov    esi,DWORD PTR [rax+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_111b:
	/* 0x111b: and    bpl,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_111f:
	/* 0x111f: mov    rdi,QWORD PTR [rip+0x14026] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1126:
	/* 0x1126: cmp    BYTE PTR [rdi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1129:
	/* 0x1129: je     113c <tail_handle_ipv6+0x113c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1129, 0x113c, x86_l_113c);
x86_l_112b:
	/* 0x112b: mov    rdi,QWORD PTR [rip+0x14026] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1132:
	/* 0x1132: mov    edi,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1134:
	/* 0x1134: lea    edi,[rdi+rdi*4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_1137:
	/* 0x1137: shr    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_113a:
	/* 0x113a: jmp    1141 <tail_handle_ipv6+0x1141> */
	X86_SIM_X86_JMP(0x113a, 0x1141, x86_l_1141);
x86_l_113c:
	/* 0x113c: mov    edi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 5ULL);
x86_l_1141:
	/* 0x1141: mov    r14d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R13, X86_WIDTH_32);
x86_l_1144:
	/* 0x1144: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1146:
	/* 0x1146: or     bpl,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_1149:
	/* 0x1149: cmp    edi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RCX, X86_WIDTH_32);
x86_l_114b:
	/* 0x114b: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1150:
	/* 0x1150: jb     1157 <tail_handle_ipv6+0x1157> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1150, 0x1157, x86_l_1157);
x86_l_1152:
	/* 0x1152: cmp    dl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RBP, X86_WIDTH_8);
x86_l_1155:
	/* 0x1155: je     1167 <tail_handle_ipv6+0x1167> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1155, 0x1167, x86_l_1167);
x86_l_1157:
	/* 0x1157: mov    BYTE PTR [rax+0x2a],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_115b:
	/* 0x115b: mov    DWORD PTR [rax+0x30],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_115e:
	/* 0x115e: mov    rcx,QWORD PTR [rip+0x14026] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_1165:
	/* 0x1165: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1167:
	/* 0x1167: mov    rcx,QWORD PTR [rip+0x14026] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_116e:
	/* 0x116e: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1171:
	/* 0x1171: je     117f <tail_handle_ipv6+0x117f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1171, 0x117f, x86_l_117f);
x86_l_1173:
	/* 0x1173: inc QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 16ULL);
x86_l_1178:
	/* 0x1178: mov    ecx,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_117a:
	/* 0x117a: add QWORD PTR [rax+0x18],rcx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_117f:
	/* 0x117f: cmp    r12d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 2ULL);
x86_l_1183:
	/* 0x1183: je     11a3 <tail_handle_ipv6+0x11a3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1183, 0x11a3, x86_l_11a3);
x86_l_1185:
	/* 0x1185: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_1189:
	/* 0x1189: jne    1198 <tail_handle_ipv6+0x1198> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1189, 0x1198, x86_l_1198);
x86_l_118b:
	/* 0x118b: movzx  ecx,WORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_118f:
	/* 0x118f: test   cl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_1192:
	/* 0x1192: jne    14c1 <tail_handle_ipv6+0x14c1> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1192, 0x14c1, x86_l_14c1);
x86_l_1198:
	/* 0x1198: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_119a:
	/* 0x119a: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_119e:
	/* 0x119e: jmp    1275 <tail_handle_ipv6+0x1275> */
	X86_SIM_X86_JMP(0x119e, 0x1275, x86_l_1275);
x86_l_11a3:
	/* 0x11a3: mov    r13d,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R14, X86_WIDTH_32);
x86_l_11a6:
	/* 0x11a6: or     BYTE PTR [rax+0x24],0x3 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RAX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 154618822659ULL);
x86_l_11aa:
	/* 0x11aa: mov    r14,QWORD PTR [rip+0x14026] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_11b1:
	/* 0x11b1: mov    ecx,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11b4:
	/* 0x11b4: mov    r15,QWORD PTR [rip+0x14026] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_11bb:
	/* 0x11bb: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11bf:
	/* 0x11bf: je     11d4 <tail_handle_ipv6+0x11d4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11bf, 0x11d4, x86_l_11d4);
x86_l_11c1:
	/* 0x11c1: mov    rcx,QWORD PTR [rip+0x14026] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_11c8:
	/* 0x11c8: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11ca:
	/* 0x11ca: add    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_11cc:
	/* 0x11cc: lea    ebp,[rcx+rcx*4] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_RCX, 2), 0ULL);
x86_l_11cf:
	/* 0x11cf: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_11d2:
	/* 0x11d2: jmp    11d9 <tail_handle_ipv6+0x11d9> */
	X86_SIM_X86_JMP(0x11d2, 0x11d9, x86_l_11d9);
x86_l_11d4:
	/* 0x11d4: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_11d9:
	/* 0x11d9: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_11dc:
	/* 0x11dc: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_11e0:
	/* 0x11e0: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11e4:
	/* 0x11e4: je     11f8 <tail_handle_ipv6+0x11f8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11e4, 0x11f8, x86_l_11f8);
x86_l_11e6:
	/* 0x11e6: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_11eb:
	/* 0x11eb: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11ed:
	/* 0x11ed: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_11ef:
	/* 0x11ef: mov    rcx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_11f2:
	/* 0x11f2: shr    rcx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_11f6:
	/* 0x11f6: jmp    121b <tail_handle_ipv6+0x121b> */
	X86_SIM_X86_JMP(0x11f6, 0x121b, x86_l_121b);
x86_l_11f8:
	/* 0x11f8: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_11fd:
	/* 0x11fd: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11ff:
	/* 0x11ff: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1201:
	/* 0x1201: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1205:
	/* 0x1205: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_120f:
	/* 0x120f: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1212:
	/* 0x1212: mulx   rcx,rcx,rcx */
	X86_SIM_L_EXEC_MULX(X86_RCX, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_1217:
	/* 0x1217: shr    rcx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_121b:
	/* 0x121b: add    ebp,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_121d:
	/* 0x121d: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_1220:
	/* 0x1220: mov    DWORD PTR [r12+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1225:
	/* 0x1225: movzx  esi,BYTE PTR [r12+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_122b:
	/* 0x122b: mov    edx,DWORD PTR [r12+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1230:
	/* 0x1230: and    r13b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_1234:
	/* 0x1234: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1238:
	/* 0x1238: je     124b <tail_handle_ipv6+0x124b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1238, 0x124b, x86_l_124b);
x86_l_123a:
	/* 0x123a: mov    rdi,QWORD PTR [rip+0x14026] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1241:
	/* 0x1241: mov    edi,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1243:
	/* 0x1243: lea    edi,[rdi+rdi*4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_1246:
	/* 0x1246: shr    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1249:
	/* 0x1249: jmp    1250 <tail_handle_ipv6+0x1250> */
	X86_SIM_X86_JMP(0x1249, 0x1250, x86_l_1250);
x86_l_124b:
	/* 0x124b: mov    edi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 5ULL);
x86_l_1250:
	/* 0x1250: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1254:
	/* 0x1254: add    edi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1256:
	/* 0x1256: or     r13b,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RSI, X86_WIDTH_8, X86_ALU_OR);
x86_l_1259:
	/* 0x1259: mov    dx,0x100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_16, 256ULL);
x86_l_125d:
	/* 0x125d: cmp    edi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RCX, X86_WIDTH_32);
x86_l_125f:
	/* 0x125f: jb     1266 <tail_handle_ipv6+0x1266> */
	X86_SIM_X86_JCC(X86_CC_B, 0x125f, 0x1266, x86_l_1266);
x86_l_1261:
	/* 0x1261: cmp    sil,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_R13, X86_WIDTH_8);
x86_l_1264:
	/* 0x1264: je     1270 <tail_handle_ipv6+0x1270> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1264, 0x1270, x86_l_1270);
x86_l_1266:
	/* 0x1266: mov    BYTE PTR [rax+0x2a],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_126a:
	/* 0x126a: mov    DWORD PTR [rax+0x30],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_126d:
	/* 0x126d: mov    ecx,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1270:
	/* 0x1270: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1275:
	/* 0x1275: test   BYTE PTR [rsp+0x7d],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 536870912002ULL);
x86_l_127a:
	/* 0x127a: mov    r14d,DWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1282:
	/* 0x1282: jne    12e9 <tail_handle_ipv6+0x12e9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1282, 0x12e9, x86_l_12e9);
x86_l_1284:
	/* 0x1284: movzx  ecx,WORD PTR [rax+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_1288:
	/* 0x1288: mov    QWORD PTR [rsp+0xb8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1290:
	/* 0x1290: mov    r12d,DWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1294:
	/* 0x1294: shr    r14d,0x6 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 6ULL);
x86_l_1298:
	/* 0x1298: movzx  eax,dx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_129b:
	/* 0x129b: or     eax,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R14, X86_WIDTH_32, X86_ALU_OR);
x86_l_129e:
	/* 0x129e: mov    DWORD PTR [rsp+0xc0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_12a5:
	/* 0x12a5: mov    DWORD PTR [rsp+0x10],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12aa:
	/* 0x12aa: mov    rdi,QWORD PTR [rip+0x14026] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb6_backends_v3)));
x86_l_12b1:
	/* 0x12b1: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12b6:
	/* 0x12b6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_12bb:
	/* 0x12bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12bd:
	/* 0x12bd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_12c0:
	/* 0x12c0: je     12f7 <tail_handle_ipv6+0x12f7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12c0, 0x12f7, x86_l_12f7);
x86_l_12c2:
	/* 0x12c2: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_12ca:
	/* 0x12ca: cmp    BYTE PTR [rax+0x13],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 81604378624ULL);
x86_l_12ce:
	/* 0x12ce: movabs rsi,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 2199023255552ULL);
x86_l_12d8:
	/* 0x12d8: je     13bd <tail_handle_ipv6+0x13bd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12d8, 0x13bd, x86_l_13bd);
x86_l_12de:
	/* 0x12de: test   r14w,r14w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_16);
x86_l_12e2:
	/* 0x12e2: jne    1301 <tail_handle_ipv6+0x1301> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x12e2, 0x1301, x86_l_1301);
x86_l_12e4:
	/* 0x12e4: jmp    13bd <tail_handle_ipv6+0x13bd> */
	X86_SIM_X86_JMP(0x12e4, 0x13bd, x86_l_13bd);
x86_l_12e9:
	/* 0x12e9: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12ec:
	/* 0x12ec: mov    r12d,0xffffff5d */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967133ULL);
x86_l_12f2:
	/* 0x12f2: jmp    fd8 <tail_handle_ipv6+0xfd8> */
	X86_SIM_X86_JMP(0x12f2, 0xfd8, x86_l_fd8);
x86_l_12f7:
	/* 0x12f7: mov    rax,QWORD PTR [rip+0x14026] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_12fe:
	/* 0x12fe: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1301:
	/* 0x1301: cmp    WORD PTR [r15+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_1307:
	/* 0x1307: je     1833 <tail_handle_ipv6+0x1833> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1307, 0x1833, x86_l_1833);
x86_l_130d:
	/* 0x130d: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1310:
	/* 0x1310: mov    ecx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_1315:
	/* 0x1315: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1317:
	/* 0x1317: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1319:
	/* 0x1319: movzx  ecx,WORD PTR [r15+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_131e:
	/* 0x131e: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1320:
	/* 0x1320: div    ecx */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_1322:
	/* 0x1322: inc    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_1324:
	/* 0x1324: mov    WORD PTR [rsp+0xaa],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 170ULL);
x86_l_132c:
	/* 0x132c: mov    r14,QWORD PTR [rip+0x14026] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_1333:
	/* 0x1333: movzx  eax,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1337:
	/* 0x1337: mov    rdi,QWORD PTR [rip+0x14026] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb6_services_v2)));
x86_l_133e:
	/* 0x133e: lea    rsi,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1346:
	/* 0x1346: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_134b:
	/* 0x134b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_134d:
	/* 0x134d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1350:
	/* 0x1350: je     1357 <tail_handle_ipv6+0x1357> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1350, 0x1357, x86_l_1357);
x86_l_1352:
	/* 0x1352: mov    r12d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1355:
	/* 0x1355: jmp    135b <tail_handle_ipv6+0x135b> */
	X86_SIM_X86_JMP(0x1355, 0x135b, x86_l_135b);
x86_l_1357:
	/* 0x1357: movzx  eax,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_135b:
	/* 0x135b: mov    DWORD PTR [rsp+0x10],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1360:
	/* 0x1360: mov    rdi,QWORD PTR [rip+0x14026] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb6_backends_v3)));
x86_l_1367:
	/* 0x1367: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_136c:
	/* 0x136c: mov    r14d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 1ULL);
x86_l_1372:
	/* 0x1372: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_1375:
	/* 0x1375: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_137d:
	/* 0x137d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1380:
	/* 0x1380: je     1829 <tail_handle_ipv6+0x1829> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1380, 0x1829, x86_l_1829);
x86_l_1386:
	/* 0x1386: movzx  r15d,WORD PTR [r15+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_138b:
	/* 0x138b: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1390:
	/* 0x1390: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_1393:
	/* 0x1393: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_1396:
	/* 0x1396: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1399:
	/* 0x1399: mov    QWORD PTR [rsp+0xb8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_13a1:
	/* 0x13a1: je     13af <tail_handle_ipv6+0x13af> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13a1, 0x13af, x86_l_13af);
x86_l_13a3:
	/* 0x13a3: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_13a6:
	/* 0x13a6: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13aa:
	/* 0x13aa: mov    WORD PTR [rax+0x26],r15w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_13af:
	/* 0x13af: movabs rsi,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 2199023255552ULL);
x86_l_13b9:
	/* 0x13b9: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13bd:
	/* 0x13bd: mov    r14d,DWORD PTR [rsp+0xc0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 192ULL);
x86_l_13c5:
	/* 0x13c5: jmp    1965 <tail_handle_ipv6+0x1965> */
	X86_SIM_X86_JMP(0x13c5, 0x1965, x86_l_1965);
x86_l_13ca:
	/* 0x13ca: mov    rdi,QWORD PTR [rip+0x14026] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv6_frag_datagrams)));
x86_l_13d1:
	/* 0x13d1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13d6:
	/* 0x13d6: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13da:
	/* 0x13da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13dc:
	/* 0x13dc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13df:
	/* 0x13df: je     1470 <tail_handle_ipv6+0x1470> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13df, 0x1470, x86_l_1470);
x86_l_13e5:
	/* 0x13e5: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13e7:
	/* 0x13e7: mov    DWORD PTR [rsp+0x78],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_13eb:
	/* 0x13eb: jmp    9a9 <tail_handle_ipv6+0x9a9> */
	X86_SIM_X86_JMP(0x13eb, 0x9a9, x86_l_9a9);
x86_l_13f0:
	/* 0x13f0: mov    rdi,QWORD PTR [rip+0x14026] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv6_frag_datagrams)));
x86_l_13f7:
	/* 0x13f7: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_13fc:
	/* 0x13fc: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1400:
	/* 0x1400: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1403:
	/* 0x1403: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1405:
	/* 0x1405: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1407:
	/* 0x1407: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1409:
	/* 0x1409: je     9a9 <tail_handle_ipv6+0x9a9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1409, 0x9a9, x86_l_9a9);
x86_l_140f:
	/* 0x140f: mov    QWORD PTR [rsp+0xc8],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1417:
	/* 0x1417: mov    rbp,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RBX, X86_WIDTH_64);
x86_l_141a:
	/* 0x141a: mov    r15d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_141d:
	/* 0x141d: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1426:
	/* 0x1426: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_142f:
	/* 0x142f: movabs rax,0x7201a9020a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 489654125066ULL);
x86_l_1439:
	/* 0x1439: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1441:
	/* 0x1441: mov    rdi,QWORD PTR [rip+0x14026] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1448:
	/* 0x1448: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1450:
	/* 0x1450: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1455:
	/* 0x1455: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1457:
	/* 0x1457: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_145a:
	/* 0x145a: je     147b <tail_handle_ipv6+0x147b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x145a, 0x147b, x86_l_147b);
x86_l_145c:
	/* 0x145c: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_145f:
	/* 0x145f: add    QWORD PTR [rax+0x8],r15 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1463:
	/* 0x1463: jmp    14a6 <tail_handle_ipv6+0x14a6> */
	X86_SIM_X86_JMP(0x1463, 0x14a6, x86_l_14a6);
x86_l_1465:
	/* 0x1465: mov    r12d,0xffffff63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967139ULL);
x86_l_146b:
	/* 0x146b: jmp    fd8 <tail_handle_ipv6+0xfd8> */
	X86_SIM_X86_JMP(0x146b, 0xfd8, x86_l_fd8);
x86_l_1470:
	/* 0x1470: mov    r12d,0xffffff51 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967121ULL);
x86_l_1476:
	/* 0x1476: jmp    aea <tail_handle_ipv6+0xaea> */
	X86_SIM_X86_JMP(0x1476, 0xaea, x86_l_aea);
x86_l_147b:
	/* 0x147b: mov    QWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_1484:
	/* 0x1484: mov    QWORD PTR [rsp+0x18],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1489:
	/* 0x1489: mov    rdi,QWORD PTR [rip+0x14026] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1490:
	/* 0x1490: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1498:
	/* 0x1498: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_149d:
	/* 0x149d: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_14a2:
	/* 0x14a2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14a4:
	/* 0x14a4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14a6:
	/* 0x14a6: mov    rbx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RBP, X86_WIDTH_64);
x86_l_14a9:
	/* 0x14a9: mov    rbp,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_14b1:
	/* 0x14b1: jmp    9a9 <tail_handle_ipv6+0x9a9> */
	X86_SIM_X86_JMP(0x14b1, 0x9a9, x86_l_9a9);
x86_l_14b6:
	/* 0x14b6: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_14bc:
	/* 0x14bc: jmp    e82 <tail_handle_ipv6+0xe82> */
	X86_SIM_X86_JMP(0x14bc, 0xe82, x86_l_e82);
x86_l_14c1:
	/* 0x14c1: mov    WORD PTR [rax+0x2a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 180388626432ULL);
x86_l_14c7:
	/* 0x14c7: and    ecx,0xffec */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 65516ULL);
x86_l_14cd:
	/* 0x14cd: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_14d0:
	/* 0x14d0: mov    WORD PTR [rax+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_14d4:
	/* 0x14d4: mov    r13,QWORD PTR [rip+0x14026] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_14db:
	/* 0x14db: cmp    BYTE PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14e0:
	/* 0x14e0: je     14f1 <tail_handle_ipv6+0x14f1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14e0, 0x14f1, x86_l_14f1);
x86_l_14e2:
	/* 0x14e2: mov    rax,QWORD PTR [rip+0x14026] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_14e9:
	/* 0x14e9: imul   ebp,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_14ec:
	/* 0x14ec: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_14ef:
	/* 0x14ef: jmp    14f6 <tail_handle_ipv6+0x14f6> */
	X86_SIM_X86_JMP(0x14ef, 0x14f6, x86_l_14f6);
x86_l_14f1:
	/* 0x14f1: mov    ebp,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_14f6:
	/* 0x14f6: cmp    r15b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_8, 6ULL);
x86_l_14fa:
	/* 0x14fa: jne    1532 <tail_handle_ipv6+0x1532> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x14fa, 0x1532, x86_l_1532);
x86_l_14fc:
	/* 0x14fc: mov    eax,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R14, X86_WIDTH_32);
x86_l_14ff:
	/* 0x14ff: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1501:
	/* 0x1501: shr    eax,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_1504:
	/* 0x1504: and    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_1507:
	/* 0x1507: or     ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1509:
	/* 0x1509: mov    WORD PTR [r12+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_150f:
	/* 0x150f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1511:
	/* 0x1511: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_1516:
	/* 0x1516: mov    ebp,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 21600ULL);
x86_l_151b:
	/* 0x151b: cmove  ebp,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_151e:
	/* 0x151e: cmp    BYTE PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1523:
	/* 0x1523: je     1532 <tail_handle_ipv6+0x1532> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1523, 0x1532, x86_l_1532);
x86_l_1525:
	/* 0x1525: mov    rax,QWORD PTR [rip+0x14026] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_152c:
	/* 0x152c: imul   ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_152f:
	/* 0x152f: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1532:
	/* 0x1532: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1536:
	/* 0x1536: cmp    BYTE PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_153b:
	/* 0x153b: je     154c <tail_handle_ipv6+0x154c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x153b, 0x154c, x86_l_154c);
x86_l_153d:
	/* 0x153d: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_1542:
	/* 0x1542: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1544:
	/* 0x1544: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1546:
	/* 0x1546: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_154a:
	/* 0x154a: jmp    156f <tail_handle_ipv6+0x156f> */
	X86_SIM_X86_JMP(0x154a, 0x156f, x86_l_156f);
x86_l_154c:
	/* 0x154c: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1551:
	/* 0x1551: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1553:
	/* 0x1553: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1555:
	/* 0x1555: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1559:
	/* 0x1559: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_1563:
	/* 0x1563: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1566:
	/* 0x1566: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_156b:
	/* 0x156b: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_156f:
	/* 0x156f: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1571:
	/* 0x1571: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1574:
	/* 0x1574: mov    DWORD PTR [r12+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1579:
	/* 0x1579: movzx  ecx,BYTE PTR [r12+0x2a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 42ULL);
x86_l_157f:
	/* 0x157f: mov    edx,DWORD PTR [r12+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1584:
	/* 0x1584: and    r14b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_1588:
	/* 0x1588: cmp    BYTE PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_158d:
	/* 0x158d: je     15a0 <tail_handle_ipv6+0x15a0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x158d, 0x15a0, x86_l_15a0);
x86_l_158f:
	/* 0x158f: mov    rsi,QWORD PTR [rip+0x14026] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_1596:
	/* 0x1596: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1598:
	/* 0x1598: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_159b:
	/* 0x159b: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_159e:
	/* 0x159e: jmp    15a5 <tail_handle_ipv6+0x15a5> */
	X86_SIM_X86_JMP(0x159e, 0x15a5, x86_l_15a5);
x86_l_15a0:
	/* 0x15a0: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_15a5:
	/* 0x15a5: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_15a7:
	/* 0x15a7: or     r14b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_15aa:
	/* 0x15aa: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_15ac:
	/* 0x15ac: mov    r13,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15b1:
	/* 0x15b1: jb     15b8 <tail_handle_ipv6+0x15b8> */
	X86_SIM_X86_JCC(X86_CC_B, 0x15b1, 0x15b8, x86_l_15b8);
x86_l_15b3:
	/* 0x15b3: cmp    cl,r14b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R14, X86_WIDTH_8);
x86_l_15b6:
	/* 0x15b6: je     15cb <tail_handle_ipv6+0x15cb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x15b6, 0x15cb, x86_l_15cb);
x86_l_15b8:
	/* 0x15b8: mov    BYTE PTR [r12+0x2a],r14b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R14, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_15bd:
	/* 0x15bd: mov    DWORD PTR [r12+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_15c2:
	/* 0x15c2: mov    rax,QWORD PTR [rip+0x14026] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_15c9:
	/* 0x15c9: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15cb:
	/* 0x15cb: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15cf:
	/* 0x15cf: cmp    WORD PTR [r15+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_15d5:
	/* 0x15d5: je     1833 <tail_handle_ipv6+0x1833> */
	X86_SIM_X86_JCC(X86_CC_E, 0x15d5, 0x1833, x86_l_1833);
x86_l_15db:
	/* 0x15db: test   BYTE PTR [r15+0x8],0x10 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738384ULL);
x86_l_15e0:
	/* 0x15e0: je     1748 <tail_handle_ipv6+0x1748> */
	X86_SIM_X86_JCC(X86_CC_E, 0x15e0, 0x1748, x86_l_1748);
x86_l_15e6:
	/* 0x15e6: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_15ef:
	/* 0x15ef: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_15f8:
	/* 0x15f8: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1601:
	/* 0x1601: movzx  eax,WORD PTR [r15+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_1606:
	/* 0x1606: mov    WORD PTR [rsp+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_160b:
	/* 0x160b: mov    BYTE PTR [rsp+0x22],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 146028888064ULL);
x86_l_1610:
	/* 0x1610: mov    rax,QWORD PTR [rsp+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_1618:
	/* 0x1618: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_161d:
	/* 0x161d: mov    rax,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1625:
	/* 0x1625: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_162a:
	/* 0x162a: mov    rdi,QWORD PTR [rip+0x14026] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb6_affinity)));
x86_l_1631:
	/* 0x1631: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1636:
	/* 0x1636: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_163b:
	/* 0x163b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_163d:
	/* 0x163d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1640:
	/* 0x1640: je     1748 <tail_handle_ipv6+0x1748> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1640, 0x1748, x86_l_1748);
x86_l_1646:
	/* 0x1646: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_1649:
	/* 0x1649: mov    r14,QWORD PTR [rip+0x14026] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1650:
	/* 0x1650: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1654:
	/* 0x1654: je     1665 <tail_handle_ipv6+0x1665> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1654, 0x1665, x86_l_1665);
x86_l_1656:
	/* 0x1656: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_165b:
	/* 0x165b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_165d:
	/* 0x165d: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_165f:
	/* 0x165f: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_1663:
	/* 0x1663: jmp    1688 <tail_handle_ipv6+0x1688> */
	X86_SIM_X86_JMP(0x1663, 0x1688, x86_l_1688);
x86_l_1665:
	/* 0x1665: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_166a:
	/* 0x166a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_166c:
	/* 0x166c: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_166e:
	/* 0x166e: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_1672:
	/* 0x1672: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_167c:
	/* 0x167c: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_167f:
	/* 0x167f: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1684:
	/* 0x1684: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_1688:
	/* 0x1688: mov    ecx,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_168d:
	/* 0x168d: mov    DWORD PTR [rsp+0x80],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1694:
	/* 0x1694: movzx  ecx,WORD PTR [r15+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_1699:
	/* 0x1699: mov    WORD PTR [rsp+0x84],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_16a1:
	/* 0x16a1: mov    WORD PTR [rsp+0x86],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 575525617664ULL);
x86_l_16ab:
	/* 0x16ab: mov    rcx,QWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16af:
	/* 0x16af: mov    edx,0xffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 16777215ULL);
x86_l_16b4:
	/* 0x16b4: and    edx,DWORD PTR [r15] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R15, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 0ULL);
x86_l_16b7:
	/* 0x16b7: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16bb:
	/* 0x16bb: je     16ca <tail_handle_ipv6+0x16ca> */
	X86_SIM_X86_JCC(X86_CC_E, 0x16bb, 0x16ca, x86_l_16ca);
x86_l_16bd:
	/* 0x16bd: mov    rsi,QWORD PTR [rip+0x14026] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_16c4:
	/* 0x16c4: imul   edx,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSI, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_16c7:
	/* 0x16c7: shr    edx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_16ca:
	/* 0x16ca: mov    edx,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_16cc:
	/* 0x16cc: add    rcx,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_16cf:
	/* 0x16cf: mov    r14d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_32);
x86_l_16d2:
	/* 0x16d2: cmp    rcx,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_16d5:
	/* 0x16d5: jbe    1735 <tail_handle_ipv6+0x1735> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x16d5, 0x1735, x86_l_1735);
x86_l_16d7:
	/* 0x16d7: mov    rdi,QWORD PTR [rip+0x14026] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb_affinity_match)));
x86_l_16de:
	/* 0x16de: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_16e6:
	/* 0x16e6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_16eb:
	/* 0x16eb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16ed:
	/* 0x16ed: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_16f0:
	/* 0x16f0: je     1735 <tail_handle_ipv6+0x1735> */
	X86_SIM_X86_JCC(X86_CC_E, 0x16f0, 0x1735, x86_l_1735);
x86_l_16f2:
	/* 0x16f2: mov    QWORD PTR [r12],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16f6:
	/* 0x16f6: mov    r12d,DWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16fb:
	/* 0x16fb: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_16fe:
	/* 0x16fe: je     1748 <tail_handle_ipv6+0x1748> */
	X86_SIM_X86_JCC(X86_CC_E, 0x16fe, 0x1748, x86_l_1748);
x86_l_1700:
	/* 0x1700: mov    DWORD PTR [rsp+0x10],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1705:
	/* 0x1705: mov    rdi,QWORD PTR [rip+0x14026] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb6_backends_v3)));
x86_l_170c:
	/* 0x170c: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1711:
	/* 0x1711: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1716:
	/* 0x1716: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1718:
	/* 0x1718: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1720:
	/* 0x1720: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1723:
	/* 0x1723: jne    17bb <tail_handle_ipv6+0x17bb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1723, 0x17bb, x86_l_17bb);
x86_l_1729:
	/* 0x1729: mov    rax,QWORD PTR [rip+0x14026] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_1730:
	/* 0x1730: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1733:
	/* 0x1733: jmp    1748 <tail_handle_ipv6+0x1748> */
	X86_SIM_X86_JMP(0x1733, 0x1748, x86_l_1748);
x86_l_1735:
	/* 0x1735: mov    rdi,QWORD PTR [rip+0x14026] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb6_affinity)));
x86_l_173c:
	/* 0x173c: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1741:
	/* 0x1741: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1746:
	/* 0x1746: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1748:
	/* 0x1748: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_174b:
	/* 0x174b: mov    ecx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_1750:
	/* 0x1750: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1752:
	/* 0x1752: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1754:
	/* 0x1754: movzx  ecx,WORD PTR [r15+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_1759:
	/* 0x1759: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_175b:
	/* 0x175b: div    ecx */
	X86_SIM_RUN_OP(X86_OP_DIV, X86_REG_NONE, X86_RCX, X86_WIDTH_32, 0, 0);
x86_l_175d:
	/* 0x175d: inc    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_175f:
	/* 0x175f: mov    WORD PTR [rsp+0xaa],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 170ULL);
x86_l_1767:
	/* 0x1767: mov    r14,QWORD PTR [rip+0x14026] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_176e:
	/* 0x176e: movzx  eax,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1772:
	/* 0x1772: mov    rdi,QWORD PTR [rip+0x14026] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb6_services_v2)));
x86_l_1779:
	/* 0x1779: lea    rsi,[rsp+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_1781:
	/* 0x1781: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1786:
	/* 0x1786: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1788:
	/* 0x1788: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_178b:
	/* 0x178b: je     1792 <tail_handle_ipv6+0x1792> */
	X86_SIM_X86_JCC(X86_CC_E, 0x178b, 0x1792, x86_l_1792);
x86_l_178d:
	/* 0x178d: mov    r12d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1790:
	/* 0x1790: jmp    1796 <tail_handle_ipv6+0x1796> */
	X86_SIM_X86_JMP(0x1790, 0x1796, x86_l_1796);
x86_l_1792:
	/* 0x1792: movzx  eax,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1796:
	/* 0x1796: mov    DWORD PTR [rsp+0x10],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_179b:
	/* 0x179b: mov    rdi,QWORD PTR [rip+0x14026] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb6_backends_v3)));
x86_l_17a2:
	/* 0x17a2: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_17a7:
	/* 0x17a7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_17ac:
	/* 0x17ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17ae:
	/* 0x17ae: mov    QWORD PTR [rsp+0xb0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_17b6:
	/* 0x17b6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_17b9:
	/* 0x17b9: je     1829 <tail_handle_ipv6+0x1829> */
	X86_SIM_X86_JCC(X86_CC_E, 0x17b9, 0x1829, x86_l_1829);
x86_l_17bb:
	/* 0x17bb: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_17c4:
	/* 0x17c4: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_17cd:
	/* 0x17cd: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_17d6:
	/* 0x17d6: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_17df:
	/* 0x17df: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_17e8:
	/* 0x17e8: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_17f1:
	/* 0x17f1: movzx  ebp,BYTE PTR [rsp+0x7c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 124ULL);
x86_l_17f6:
	/* 0x17f6: mov    rax,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_17fe:
	/* 0x17fe: mov    WORD PTR [rsp+0x36],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_1803:
	/* 0x1803: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_1806:
	/* 0x1806: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_180b:
	/* 0x180b: mov    r14,QWORD PTR [rip+0x14026] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1812:
	/* 0x1812: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1816:
	/* 0x1816: je     1866 <tail_handle_ipv6+0x1866> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1816, 0x1866, x86_l_1866);
x86_l_1818:
	/* 0x1818: mov    rax,QWORD PTR [rip+0x14026] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_181f:
	/* 0x181f: imul   r15d,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_1823:
	/* 0x1823: shr    r15d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1827:
	/* 0x1827: jmp    186c <tail_handle_ipv6+0x186c> */
	X86_SIM_X86_JMP(0x1827, 0x186c, x86_l_186c);
x86_l_1829:
	/* 0x1829: mov    rax,QWORD PTR [rip+0x14026] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_1830:
	/* 0x1830: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1833:
	/* 0x1833: mov    rax,QWORD PTR [rip+0x14026] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_no_service_endpoints_routable)));
x86_l_183a:
	/* 0x183a: mov    r12d,0xffffff62 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967138ULL);
x86_l_1840:
	/* 0x1840: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1843:
	/* 0x1843: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1846:
	/* 0x1846: jne    fd8 <tail_handle_ipv6+0xfd8> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1846, 0xfd8, x86_l_fd8);
x86_l_184c:
	/* 0x184c: movzx  eax,BYTE PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_1851:
	/* 0x1851: test   al,0x23 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 35ULL);
x86_l_1853:
	/* 0x1853: je     1db5 <tail_handle_ipv6+0x1db5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1853, 0x1db5, x86_l_1db5);
x86_l_1859:
	/* 0x1859: test   al,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 4ULL);
x86_l_185b:
	/* 0x185b: jne    fd8 <tail_handle_ipv6+0xfd8> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x185b, 0xfd8, x86_l_fd8);
x86_l_1861:
	/* 0x1861: jmp    1dc0 <tail_handle_ipv6+0x1dc0> */
	X86_SIM_X86_JMP(0x1861, 0x1dc0, x86_l_1dc0);
x86_l_1866:
	/* 0x1866: mov    r15d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 60ULL);
x86_l_186c:
	/* 0x186c: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_1870:
	/* 0x1870: jne    188f <tail_handle_ipv6+0x188f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1870, 0x188f, x86_l_188f);
x86_l_1872:
	/* 0x1872: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1876:
	/* 0x1876: je     1889 <tail_handle_ipv6+0x1889> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1876, 0x1889, x86_l_1889);
x86_l_1878:
	/* 0x1878: mov    rax,QWORD PTR [rip+0x14026] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_187f:
	/* 0x187f: imul   r15d,DWORD PTR [rax],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_1883:
	/* 0x1883: shr    r15d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1887:
	/* 0x1887: jmp    188f <tail_handle_ipv6+0x188f> */
	X86_SIM_X86_JMP(0x1887, 0x188f, x86_l_188f);
x86_l_1889:
	/* 0x1889: mov    r15d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 60ULL);
x86_l_188f:
	/* 0x188f: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1893:
	/* 0x1893: je     18a4 <tail_handle_ipv6+0x18a4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1893, 0x18a4, x86_l_18a4);
x86_l_1895:
	/* 0x1895: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_189a:
	/* 0x189a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_189c:
	/* 0x189c: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_189e:
	/* 0x189e: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_18a2:
	/* 0x18a2: jmp    18c7 <tail_handle_ipv6+0x18c7> */
	X86_SIM_X86_JMP(0x18a2, 0x18c7, x86_l_18c7);
x86_l_18a4:
	/* 0x18a4: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_18a9:
	/* 0x18a9: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18ab:
	/* 0x18ab: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_18ad:
	/* 0x18ad: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_18b1:
	/* 0x18b1: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_18bb:
	/* 0x18bb: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_18be:
	/* 0x18be: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_18c3:
	/* 0x18c3: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_18c7:
	/* 0x18c7: cmp    bpl,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_8, 6ULL);
x86_l_18cb:
	/* 0x18cb: sete   cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_E);
x86_l_18ce:
	/* 0x18ce: add    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_18d1:
	/* 0x18d1: mov    DWORD PTR [rsp+0x30],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_18d6:
	/* 0x18d6: movzx  edx,BYTE PTR [rsp+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 58ULL);
x86_l_18db:
	/* 0x18db: mov    esi,DWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_18df:
	/* 0x18df: add    cl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_8, X86_ALU_ADD);
x86_l_18e1:
	/* 0x18e1: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18e5:
	/* 0x18e5: je     18f8 <tail_handle_ipv6+0x18f8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x18e5, 0x18f8, x86_l_18f8);
x86_l_18e7:
	/* 0x18e7: mov    rdi,QWORD PTR [rip+0x14026] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_18ee:
	/* 0x18ee: mov    edi,DWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18f0:
	/* 0x18f0: lea    edi,[rdi+rdi*4] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_RDI, 2), 0ULL);
x86_l_18f3:
	/* 0x18f3: shr    edi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_18f6:
	/* 0x18f6: jmp    18fd <tail_handle_ipv6+0x18fd> */
	X86_SIM_X86_JMP(0x18f6, 0x18fd, x86_l_18fd);
x86_l_18f8:
	/* 0x18f8: mov    edi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_32, 5ULL);
x86_l_18fd:
	/* 0x18fd: mov    r15,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1901:
	/* 0x1901: add    edi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1903:
	/* 0x1903: or     cl,dl */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RDX, X86_WIDTH_8, X86_ALU_OR);
x86_l_1905:
	/* 0x1905: cmp    edi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RAX, X86_WIDTH_32);
x86_l_1907:
	/* 0x1907: jb     190d <tail_handle_ipv6+0x190d> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1907, 0x190d, x86_l_190d);
x86_l_1909:
	/* 0x1909: cmp    dl,cl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_8);
x86_l_190b:
	/* 0x190b: je     191e <tail_handle_ipv6+0x191e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x190b, 0x191e, x86_l_191e);
x86_l_190d:
	/* 0x190d: mov    BYTE PTR [rsp+0x3a],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_1911:
	/* 0x1911: mov    DWORD PTR [rsp+0x40],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1915:
	/* 0x1915: mov    rax,QWORD PTR [rip+0x14026] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_191c:
	/* 0x191c: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_191e:
	/* 0x191e: mov    rax,QWORD PTR [rip+0x14026] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_1925:
	/* 0x1925: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1928:
	/* 0x1928: je     193a <tail_handle_ipv6+0x193a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1928, 0x193a, x86_l_193a);
x86_l_192a:
	/* 0x192a: mov    QWORD PTR [rsp+0x20],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953473ULL);
x86_l_1933:
	/* 0x1933: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1935:
	/* 0x1935: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_193a:
	/* 0x193a: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_193f:
	/* 0x193f: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1944:
	/* 0x1944: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1947:
	/* 0x1947: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_194c:
	/* 0x194c: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_194f:
	/* 0x194f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1951:
	/* 0x1951: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1953:
	/* 0x1953: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1955:
	/* 0x1955: movabs rsi,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_64, 2199023255552ULL);
x86_l_195f:
	/* 0x195f: js     1dea <tail_handle_ipv6+0x1dea> */
	X86_SIM_X86_JCC(X86_CC_S, 0x195f, 0x1dea, x86_l_1dea);
x86_l_1965:
	/* 0x1965: movzx  eax,BYTE PTR [rsp+0x57] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 87ULL);
x86_l_196a:
	/* 0x196a: mov    BYTE PTR [rsp+0x7d],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 125ULL);
x86_l_196e:
	/* 0x196e: test   BYTE PTR [r15+0x8],0x10 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738384ULL);
x86_l_1973:
	/* 0x1973: je     1a41 <tail_handle_ipv6+0x1a41> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1973, 0x1a41, x86_l_1a41);
x86_l_1979:
	/* 0x1979: mov    r13d,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R14, X86_WIDTH_32);
x86_l_197c:
	/* 0x197c: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_197f:
	/* 0x197f: mov    rax,QWORD PTR [rip+0x14026] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_1986:
	/* 0x1986: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1989:
	/* 0x1989: je     199a <tail_handle_ipv6+0x199a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1989, 0x199a, x86_l_199a);
x86_l_198b:
	/* 0x198b: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_1990:
	/* 0x1990: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1992:
	/* 0x1992: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1994:
	/* 0x1994: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_1998:
	/* 0x1998: jmp    19bd <tail_handle_ipv6+0x19bd> */
	X86_SIM_X86_JMP(0x1998, 0x19bd, x86_l_19bd);
x86_l_199a:
	/* 0x199a: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_199f:
	/* 0x199f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19a1:
	/* 0x19a1: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_19a3:
	/* 0x19a3: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_19a7:
	/* 0x19a7: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_19b1:
	/* 0x19b1: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_19b4:
	/* 0x19b4: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_19b9:
	/* 0x19b9: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_19bd:
	/* 0x19bd: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_19c6:
	/* 0x19c6: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_19cf:
	/* 0x19cf: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_19d8:
	/* 0x19d8: movzx  ecx,WORD PTR [r15+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_19dd:
	/* 0x19dd: mov    WORD PTR [rsp+0x20],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_19e2:
	/* 0x19e2: mov    BYTE PTR [rsp+0x22],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 146028888064ULL);
x86_l_19e7:
	/* 0x19e7: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_19e9:
	/* 0x19e9: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_19f1:
	/* 0x19f1: mov    DWORD PTR [rsp+0x88],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_19f9:
	/* 0x19f9: mov    DWORD PTR [rsp+0x8c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 601295421440ULL);
x86_l_1a04:
	/* 0x1a04: mov    rax,QWORD PTR [rsp+0xf8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 248ULL);
x86_l_1a0c:
	/* 0x1a0c: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a11:
	/* 0x1a11: mov    rax,QWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1a19:
	/* 0x1a19: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1a1e:
	/* 0x1a1e: mov    rdi,QWORD PTR [rip+0x14026] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb6_affinity)));
x86_l_1a25:
	/* 0x1a25: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1a2a:
	/* 0x1a2a: lea    rdx,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1a32:
	/* 0x1a32: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1a37:
	/* 0x1a37: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a39:
	/* 0x1a39: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a3b:
	/* 0x1a3b: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_1a3e:
	/* 0x1a3e: mov    r14d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R13, X86_WIDTH_32);
x86_l_1a41:
	/* 0x1a41: mov    rax,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1a46:
	/* 0x1a46: mov    r12,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1a4e:
	/* 0x1a4e: cmp    rax,QWORD PTR [r12] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_1a52:
	/* 0x1a52: jne    1ae7 <tail_handle_ipv6+0x1ae7> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1a52, 0x1ae7, x86_l_1ae7);
x86_l_1a58:
	/* 0x1a58: mov    rax,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1a5d:
	/* 0x1a5d: cmp    rax,QWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_1a62:
	/* 0x1a62: jne    1ae7 <tail_handle_ipv6+0x1ae7> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1a62, 0x1ae7, x86_l_1ae7);
x86_l_1a68:
	/* 0x1a68: mov    r15w,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_16, 1ULL);
x86_l_1a6d:
	/* 0x1a6d: mov    rax,QWORD PTR [rip+0x14022] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_lrp)));
x86_l_1a74:
	/* 0x1a74: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a77:
	/* 0x1a77: je     1aea <tail_handle_ipv6+0x1aea> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a77, 0x1aea, x86_l_1aea);
x86_l_1a79:
	/* 0x1a79: mov    rax,QWORD PTR [rip+0x14022] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_endpoint_netns_cookie)));
x86_l_1a80:
	/* 0x1a80: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a83:
	/* 0x1a83: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a86:
	/* 0x1a86: je     1aea <tail_handle_ipv6+0x1aea> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a86, 0x1aea, x86_l_1aea);
x86_l_1a88:
	/* 0x1a88: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a8c:
	/* 0x1a8c: test   BYTE PTR [rcx+0x9],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38654705665ULL);
x86_l_1a90:
	/* 0x1a90: je     1aea <tail_handle_ipv6+0x1aea> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a90, 0x1aea, x86_l_1aea);
x86_l_1a92:
	/* 0x1a92: mov    r13d,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R14, X86_WIDTH_32);
x86_l_1a95:
	/* 0x1a95: movzx  ecx,WORD PTR [rsp+0x7a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 122ULL);
x86_l_1a9a:
	/* 0x1a9a: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1a9f:
	/* 0x1a9f: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_1aa2:
	/* 0x1aa2: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1aa7:
	/* 0x1aa7: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1ab0:
	/* 0x1ab0: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ab5:
	/* 0x1ab5: mov    QWORD PTR [rsp+0x18],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1aba:
	/* 0x1aba: mov    QWORD PTR [rsp+0x20],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1abf:
	/* 0x1abf: mov    WORD PTR [rsp+0x2c],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_1ac4:
	/* 0x1ac4: mov    rdi,QWORD PTR [rip+0x14022] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_skip_lb6)));
x86_l_1acb:
	/* 0x1acb: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ad0:
	/* 0x1ad0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1ad5:
	/* 0x1ad5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ad7:
	/* 0x1ad7: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_1ada:
	/* 0x1ada: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1add:
	/* 0x1add: je     1aea <tail_handle_ipv6+0x1aea> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1add, 0x1aea, x86_l_1aea);
x86_l_1adf:
	/* 0x1adf: mov    r15d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_32);
x86_l_1ae2:
	/* 0x1ae2: jmp    1d86 <tail_handle_ipv6+0x1d86> */
	X86_SIM_X86_JMP(0x1ae2, 0x1d86, x86_l_1d86);
x86_l_1ae7:
	/* 0x1ae7: mov    r15d,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R14, X86_WIDTH_32);
x86_l_1aea:
	/* 0x1aea: lea    rax,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1aef:
	/* 0x1aef: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1af2:
	/* 0x1af2: mov    rax,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1af6:
	/* 0x1af6: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1afb:
	/* 0x1afb: mov    QWORD PTR [rsp+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b00:
	/* 0x1b00: mov    QWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_1b0c:
	/* 0x1b0c: mov    QWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_1b18:
	/* 0x1b18: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1b1d:
	/* 0x1b1d: mov    QWORD PTR [rsp+0xe8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_1b25:
	/* 0x1b25: movzx  eax,r15w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R15, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1b29:
	/* 0x1b29: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1b2e:
	/* 0x1b2e: mov    QWORD PTR [rsp+0xe0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_1b36:
	/* 0x1b36: movzx  ecx,WORD PTR [rsp+0x7a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 122ULL);
x86_l_1b3b:
	/* 0x1b3b: mov    DWORD PTR [rsp+0xd0],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1b42:
	/* 0x1b42: test   al,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_1b44:
	/* 0x1b44: jne    1b5b <tail_handle_ipv6+0x1b5b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1b44, 0x1b5b, x86_l_1b5b);
x86_l_1b46:
	/* 0x1b46: mov    rax,QWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b4b:
	/* 0x1b4b: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1b50:
	/* 0x1b50: mov    rax,QWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b54:
	/* 0x1b54: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1b59:
	/* 0x1b59: jmp    1b89 <tail_handle_ipv6+0x1b89> */
	X86_SIM_X86_JMP(0x1b59, 0x1b89, x86_l_1b89);
x86_l_1b5b:
	/* 0x1b5b: mov    rax,QWORD PTR [rip+0x14022] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_service_loopback_ipv6)));
x86_l_1b62:
	/* 0x1b62: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b65:
	/* 0x1b65: mov    QWORD PTR [rsp+0xf0],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_1b6d:
	/* 0x1b6d: mov    rax,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b71:
	/* 0x1b71: mov    QWORD PTR [rsp+0x100],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_1b79:
	/* 0x1b79: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_1b81:
	/* 0x1b81: mov    QWORD PTR [rsp+0x80],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1b89:
	/* 0x1b89: mov    r13,QWORD PTR [rsp+0xd8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_1b91:
	/* 0x1b91: movzx  eax,WORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_1b97:
	/* 0x1b97: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_1b9a:
	/* 0x1b9a: je     1ba1 <tail_handle_ipv6+0x1ba1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1b9a, 0x1ba1, x86_l_1ba1);
x86_l_1b9c:
	/* 0x1b9c: mov    WORD PTR [rsp+0x7a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 122ULL);
x86_l_1ba1:
	/* 0x1ba1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ba3:
	/* 0x1ba3: mov    bpl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_8, 1ULL);
x86_l_1ba6:
	/* 0x1ba6: test   r13,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_RSI, X86_WIDTH_64);
x86_l_1ba9:
	/* 0x1ba9: je     1c8e <tail_handle_ipv6+0x1c8e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1ba9, 0x1c8e, x86_l_1c8e);
x86_l_1baf:
	/* 0x1baf: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bb6:
	/* 0x1bb6: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1bbb:
	/* 0x1bbb: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1bbe:
	/* 0x1bbe: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_1bc3:
	/* 0x1bc3: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1bc6:
	/* 0x1bc6: mov    esi,0x26 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 38ULL);
x86_l_1bcb:
	/* 0x1bcb: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1bce:
	/* 0x1bce: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1bd3:
	/* 0x1bd3: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1bd6:
	/* 0x1bd6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bd8:
	/* 0x1bd8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1bda:
	/* 0x1bda: js     1d8b <tail_handle_ipv6+0x1d8b> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1bda, 0x1d8b, x86_l_1d8b);
x86_l_1be0:
	/* 0x1be0: lea    rdi,[rsp+0xe0] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_1be8:
	/* 0x1be8: mov    eax,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_1bed:
	/* 0x1bed: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1bf2:
	/* 0x1bf2: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_1bf5:
	/* 0x1bf5: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1bfa:
	/* 0x1bfa: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1bfd:
	/* 0x1bfd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bff:
	/* 0x1bff: mov    r12d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_32);
x86_l_1c02:
	/* 0x1c02: mov    rax,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1c0a:
	/* 0x1c0a: or     rax,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 136ULL);
x86_l_1c12:
	/* 0x1c12: je     1c69 <tail_handle_ipv6+0x1c69> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1c12, 0x1c69, x86_l_1c69);
x86_l_1c14:
	/* 0x1c14: mov    rax,QWORD PTR [rip+0x14022] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_debug_lb)));
x86_l_1c1b:
	/* 0x1c1b: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1c1e:
	/* 0x1c1e: lea    rdx,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1c26:
	/* 0x1c26: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_1c2b:
	/* 0x1c2b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1c2e:
	/* 0x1c2e: mov    esi,0x16 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 22ULL);
x86_l_1c33:
	/* 0x1c33: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1c38:
	/* 0x1c38: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c3b:
	/* 0x1c3b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c3d:
	/* 0x1c3d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1c3f:
	/* 0x1c3f: js     1d8b <tail_handle_ipv6+0x1d8b> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1c3f, 0x1d8b, x86_l_1d8b);
x86_l_1c45:
	/* 0x1c45: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c4a:
	/* 0x1c4a: lea    rdx,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1c52:
	/* 0x1c52: mov    eax,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_1c57:
	/* 0x1c57: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1c5c:
	/* 0x1c5c: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1c61:
	/* 0x1c61: mov    r8d,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R12, X86_WIDTH_32);
x86_l_1c64:
	/* 0x1c64: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c66:
	/* 0x1c66: mov    r12d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_32);
x86_l_1c69:
	/* 0x1c69: test   bpl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBP, X86_RBP, X86_WIDTH_8);
x86_l_1c6c:
	/* 0x1c6c: je     1cc1 <tail_handle_ipv6+0x1cc1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1c6c, 0x1cc1, x86_l_1cc1);
x86_l_1c6e:
	/* 0x1c6e: movabs rax,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2199023255552ULL);
x86_l_1c78:
	/* 0x1c78: test   r13,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_1c7b:
	/* 0x1c7b: mov    rbp,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1c83:
	/* 0x1c83: je     1d11 <tail_handle_ipv6+0x1d11> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1c83, 0x1d11, x86_l_1d11);
x86_l_1c89:
	/* 0x1c89: jmp    1d86 <tail_handle_ipv6+0x1d86> */
	X86_SIM_X86_JMP(0x1c89, 0x1d86, x86_l_1d86);
x86_l_1c8e:
	/* 0x1c8e: movzx  eax,BYTE PTR [rsp+0x7c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 124ULL);
x86_l_1c93:
	/* 0x1c93: cmp    eax,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 58ULL);
x86_l_1c96:
	/* 0x1c96: je     1da9 <tail_handle_ipv6+0x1da9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1c96, 0x1da9, x86_l_1da9);
x86_l_1c9c:
	/* 0x1c9c: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_1c9f:
	/* 0x1c9f: je     1d96 <tail_handle_ipv6+0x1d96> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1c9f, 0x1d96, x86_l_1d96);
x86_l_1ca5:
	/* 0x1ca5: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cac:
	/* 0x1cac: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_1caf:
	/* 0x1caf: jne    1bb6 <tail_handle_ipv6+0x1bb6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1caf, 0x1bb6, x86_l_1bb6);
x86_l_1cb5:
	/* 0x1cb5: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1cb7:
	/* 0x1cb7: mov    ecx,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1cbc:
	/* 0x1cbc: jmp    1baf <tail_handle_ipv6+0x1baf> */
	X86_SIM_X86_JMP(0x1cbc, 0x1baf, x86_l_1baf);
x86_l_1cc1:
	/* 0x1cc1: mov    rbp,QWORD PTR [rsp+0xc8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 200ULL);
x86_l_1cc9:
	/* 0x1cc9: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1cce:
	/* 0x1cce: lea    esi,[rax+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_1cd1:
	/* 0x1cd1: mov    r8d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1cd5:
	/* 0x1cd5: or     r8d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 16ULL);
x86_l_1cd9:
	/* 0x1cd9: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_1cde:
	/* 0x1cde: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1ce1:
	/* 0x1ce1: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ce3:
	/* 0x1ce3: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_1ce6:
	/* 0x1ce6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ce8:
	/* 0x1ce8: mov    r12d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_32);
x86_l_1ceb:
	/* 0x1ceb: sar    r12d,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SAR, 31ULL);
x86_l_1cef:
	/* 0x1cef: and    r12d,0xffffff66 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 4294967142ULL);
x86_l_1cf6:
	/* 0x1cf6: movabs rcx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2199023255552ULL);
x86_l_1d00:
	/* 0x1d00: test   r13,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_RCX, X86_WIDTH_64);
x86_l_1d03:
	/* 0x1d03: jne    1dd1 <tail_handle_ipv6+0x1dd1> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1d03, 0x1dd1, x86_l_1dd1);
x86_l_1d09:
	/* 0x1d09: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1d0b:
	/* 0x1d0b: js     1dd1 <tail_handle_ipv6+0x1dd1> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1d0b, 0x1dd1, x86_l_1dd1);
x86_l_1d11:
	/* 0x1d11: mov    rax,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_1d19:
	/* 0x1d19: movzx  eax,WORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_1d1d:
	/* 0x1d1d: test   ax,ax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_16);
x86_l_1d20:
	/* 0x1d20: je     1d86 <tail_handle_ipv6+0x1d86> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1d20, 0x1d86, x86_l_1d86);
x86_l_1d22:
	/* 0x1d22: cmp    WORD PTR [rsp+0xd0],ax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1d2a:
	/* 0x1d2a: je     1d86 <tail_handle_ipv6+0x1d86> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1d2a, 0x1d86, x86_l_1d86);
x86_l_1d2c:
	/* 0x1d2c: mov    WORD PTR [rsp+0xf0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_1d34:
	/* 0x1d34: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1d39:
	/* 0x1d39: add    esi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 16ULL);
x86_l_1d3c:
	/* 0x1d3c: lea    rdx,[rsp+0xf0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240ULL);
x86_l_1d44:
	/* 0x1d44: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_1d49:
	/* 0x1d49: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1d4c:
	/* 0x1d4c: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1d51:
	/* 0x1d51: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d54:
	/* 0x1d54: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d56:
	/* 0x1d56: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1d58:
	/* 0x1d58: js     1d8b <tail_handle_ipv6+0x1d8b> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1d58, 0x1d8b, x86_l_1d8b);
x86_l_1d5a:
	/* 0x1d5a: movzx  ecx,WORD PTR [rsp+0xf0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 240ULL);
x86_l_1d62:
	/* 0x1d62: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d67:
	/* 0x1d67: add    esi,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RBP, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1d69:
	/* 0x1d69: mov    r8d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d6d:
	/* 0x1d6d: or     r8d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_1d71:
	/* 0x1d71: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_1d76:
	/* 0x1d76: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1d79:
	/* 0x1d79: mov    edx,DWORD PTR [rsp+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_1d80:
	/* 0x1d80: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d82:
	/* 0x1d82: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1d84:
	/* 0x1d84: js     1dcb <tail_handle_ipv6+0x1dcb> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1d84, 0x1dcb, x86_l_1dcb);
x86_l_1d86:
	/* 0x1d86: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d89:
	/* 0x1d89: jmp    1ddd <tail_handle_ipv6+0x1ddd> */
	X86_SIM_X86_JMP(0x1d89, 0x1ddd, x86_l_1ddd);
x86_l_1d8b:
	/* 0x1d8b: mov    r12d,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967155ULL);
x86_l_1d91:
	/* 0x1d91: jmp    fd8 <tail_handle_ipv6+0xfd8> */
	X86_SIM_X86_JMP(0x1d91, 0xfd8, x86_l_fd8);
x86_l_1d96:
	/* 0x1d96: mov    DWORD PTR [rsp],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d9d:
	/* 0x1d9d: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1da2:
	/* 0x1da2: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1da4:
	/* 0x1da4: jmp    1bb6 <tail_handle_ipv6+0x1bb6> */
	X86_SIM_X86_JMP(0x1da4, 0x1bb6, x86_l_1bb6);
x86_l_1da9:
	/* 0x1da9: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1dab:
	/* 0x1dab: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1db0:
	/* 0x1db0: jmp    1baf <tail_handle_ipv6+0x1baf> */
	X86_SIM_X86_JMP(0x1db0, 0x1baf, x86_l_1baf);
x86_l_1db5:
	/* 0x1db5: test   BYTE PTR [r15+0x9],0x10 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38654705680ULL);
x86_l_1dba:
	/* 0x1dba: jne    fd8 <tail_handle_ipv6+0xfd8> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1dba, 0xfd8, x86_l_fd8);
x86_l_1dc0:
	/* 0x1dc0: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1dc3:
	/* 0x1dc3: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1dc6:
	/* 0x1dc6: jmp    fd8 <tail_handle_ipv6+0xfd8> */
	X86_SIM_X86_JMP(0x1dc6, 0xfd8, x86_l_fd8);
x86_l_1dcb:
	/* 0x1dcb: mov    r12d,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967142ULL);
x86_l_1dd1:
	/* 0x1dd1: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1dd4:
	/* 0x1dd4: test   r12d,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_32);
x86_l_1dd7:
	/* 0x1dd7: js     fd8 <tail_handle_ipv6+0xfd8> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1dd7, 0xfd8, x86_l_fd8);
x86_l_1ddd:
	/* 0x1ddd: mov    rsi,QWORD PTR [rsp+0xb8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 184ULL);
x86_l_1de5:
	/* 0x1de5: jmp    cc7 <tail_handle_ipv6+0xcc7> */
	X86_SIM_X86_JMP(0x1de5, 0xcc7, x86_l_cc7);
x86_l_1dea:
	/* 0x1dea: mov    r12d,0xffffff65 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4294967141ULL);
x86_l_1df0:
	/* 0x1df0: mov    r14d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_32);
x86_l_1df3:
	/* 0x1df3: jmp    fd8 <tail_handle_ipv6+0xfd8> */
	X86_SIM_X86_JMP(0x1df3, 0xfd8, x86_l_fd8);
x86_l_1df8:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
