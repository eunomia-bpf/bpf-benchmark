extern char __config_cilium_host_ifindex;
extern char __config_cilium_host_mac;
extern char __config_cluster_id;
extern char __config_cluster_id_bits;
extern char __config_enable_conntrack_accounting;
extern char __config_enable_ipv4_fragments;
extern char __config_enable_jiffies;
extern char __config_enable_netkit;
extern char __config_interface_mac;
extern char __config_kernel_hz;
extern char __config_nodeport_port_max;
extern char __config_trace_payload_len;
extern char cilium_call_policy;
extern char cilium_calls;
extern char cilium_ct4_global;
extern char cilium_ct_any4_global;
extern char cilium_ipv4_frag_datagrams;
extern char cilium_lxc;
extern char cilium_metrics;
extern char cilium_per_cluster_snat_v4_external;
extern char cilium_snat_v4_external;
extern char cilium_throttle;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int cilium_bpf_overlay_tail_handle_inter_cluster_revsnat_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0xd: mov    ebp,DWORD PTR [rdi+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_10:
	/* 0x10: mov    DWORD PTR [rdi+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_17:
	/* 0x17: mov    rax,QWORD PTR [rip+0x7bb7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_cluster_id_bits)));
x86_l_1e:
	/* 0x1e: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20:
	/* 0x20: mov    rax,QWORD PTR [rip+0x7bb7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_nodeport_port_max)));
x86_l_27:
	/* 0x27: movzx  r12d,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_2b:
	/* 0x2b: mov    DWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_33:
	/* 0x33: mov    eax,DWORD PTR [rdi+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_36:
	/* 0x36: mov    edx,DWORD PTR [rdi+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_39:
	/* 0x39: lea    rsi,[rax+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_3d:
	/* 0x3d: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_40:
	/* 0x40: jbe    4c <tail_handle_inter_cluster_revsnat+0x4c> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x40, 0x4c, x86_l_4c);
x86_l_42:
	/* 0x42: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_47:
	/* 0x47: jmp    ac8 <tail_handle_inter_cluster_revsnat+0xac8> */
	X86_SIM_X86_JMP(0x47, 0xac8, x86_l_ac8);
x86_l_4c:
	/* 0x4c: mov    dl,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_8, 24ULL);
x86_l_4e:
	/* 0x4e: sub    dl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_50:
	/* 0x50: shrx   r15d,ebp,edx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_R15, X86_RBP, X86_WIDTH_32, X86_RDX, X86_ALU_SHR);
x86_l_55:
	/* 0x55: movabs r8,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_64, 2199023255552ULL);
x86_l_5f:
	/* 0x5f: movabs r14,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_64, 1099511627776ULL);
x86_l_69:
	/* 0x69: movzx  edx,WORD PTR [rax+0x12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18ULL);
x86_l_6d:
	/* 0x6d: movzx  ecx,BYTE PTR [rax+0x17] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 23ULL);
x86_l_71:
	/* 0x71: mov    rsi,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RCX, X86_WIDTH_64);
x86_l_74:
	/* 0x74: shl    rsi,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_78:
	/* 0x78: or     rsi,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_64, X86_ALU_OR);
x86_l_7b:
	/* 0x7b: movzx  edx,WORD PTR [rax+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 20ULL);
x86_l_7f:
	/* 0x7f: lea    rdi,[rsi+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_83:
	/* 0x83: test   edx,0xff3f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_32, 65343ULL);
x86_l_89:
	/* 0x89: cmove  rdi,rsi */
	X86_SIM_L_EXEC_CMOV(X86_RDI, X86_RSI, X86_WIDTH_64, X86_CC_E);
x86_l_8d:
	/* 0x8d: add    r8,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RDI, X86_WIDTH_64, X86_ALU_ADD);
x86_l_90:
	/* 0x90: test   edx,0xff1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDX, X86_WIDTH_32, 65311ULL);
x86_l_96:
	/* 0x96: cmove  r8,rdi */
	X86_SIM_L_EXEC_CMOV(X86_R8, X86_RDI, X86_WIDTH_64, X86_CC_E);
x86_l_9a:
	/* 0x9a: mov    BYTE PTR [rsp+0x3c],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_9e:
	/* 0x9e: mov    edx,DWORD PTR [rax+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_a1:
	/* 0xa1: mov    DWORD PTR [rsp+0x30],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a5:
	/* 0xa5: mov    edi,DWORD PTR [rax+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_a8:
	/* 0xa8: mov    DWORD PTR [rsp+0x34],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_ac:
	/* 0xac: mov    BYTE PTR [rsp+0x3d],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 261993005057ULL);
x86_l_b1:
	/* 0xb1: mov    eax,DWORD PTR [rax+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_b4:
	/* 0xb4: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_b7:
	/* 0xb7: lea    rsi,[rax*4+0xe] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 2), 14ULL);
x86_l_bf:
	/* 0xbf: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_c2:
	/* 0xc2: je     1d3 <tail_handle_inter_cluster_revsnat+0x1d3> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc2, 0x1d3, x86_l_1d3);
x86_l_c8:
	/* 0xc8: mov    QWORD PTR [rsp],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cc:
	/* 0xcc: mov    r13d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBP, X86_WIDTH_32);
x86_l_cf:
	/* 0xcf: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_d2:
	/* 0xd2: je     dd <tail_handle_inter_cluster_revsnat+0xdd> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd2, 0xdd, x86_l_dd);
x86_l_d4:
	/* 0xd4: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_d7:
	/* 0xd7: jne    2a4 <tail_handle_inter_cluster_revsnat+0x2a4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xd7, 0x2a4, x86_l_2a4);
x86_l_dd:
	/* 0xdd: mov    DWORD PTR [rsp+0x60],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_e2:
	/* 0xe2: lea    r15,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_e7:
	/* 0xe7: mov    rax,QWORD PTR [rip+0x7bb7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_ipv4_fragments)));
x86_l_ee:
	/* 0xee: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f1:
	/* 0xf1: je     242 <tail_handle_inter_cluster_revsnat+0x242> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf1, 0x242, x86_l_242);
x86_l_f7:
	/* 0xf7: mov    DWORD PTR [rsp+0x8],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fb:
	/* 0xfb: mov    DWORD PTR [rsp+0xc],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_ff:
	/* 0xff: mov    WORD PTR [rsp+0x10],r8w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_105:
	/* 0x105: mov    rax,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R8, X86_WIDTH_64);
x86_l_108:
	/* 0x108: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_10c:
	/* 0x10c: mov    BYTE PTR [rsp+0x12],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_110:
	/* 0x110: mov    BYTE PTR [rsp+0x13],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 81604378624ULL);
x86_l_115:
	/* 0x115: movabs rax,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2199023255552ULL);
x86_l_11f:
	/* 0x11f: mov    QWORD PTR [rsp+0x20],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_124:
	/* 0x124: test   r8,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R8, X86_RAX, X86_WIDTH_64);
x86_l_127:
	/* 0x127: jne    11f1 <tail_handle_inter_cluster_revsnat+0x11f1> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x127, 0x11f1, x86_l_11f1);
x86_l_12d:
	/* 0x12d: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_132:
	/* 0x132: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_135:
	/* 0x135: mov    rbp,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RSI, X86_WIDTH_64);
x86_l_138:
	/* 0x138: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_13b:
	/* 0x13b: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_140:
	/* 0x140: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_142:
	/* 0x142: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_144:
	/* 0x144: js     2af <tail_handle_inter_cluster_revsnat+0x2af> */
	X86_SIM_X86_JCC(X86_CC_S, 0x144, 0x2af, x86_l_2af);
x86_l_14a:
	/* 0x14a: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_14f:
	/* 0x14f: movabs rax,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 1099511627776ULL);
x86_l_159:
	/* 0x159: test   rdx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_15c:
	/* 0x15c: je     274 <tail_handle_inter_cluster_revsnat+0x274> */
	X86_SIM_X86_JCC(X86_CC_E, 0x15c, 0x274, x86_l_274);
x86_l_162:
	/* 0x162: mov    rdi,QWORD PTR [rip+0x7bb7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv4_frag_datagrams)));
x86_l_169:
	/* 0x169: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16e:
	/* 0x16e: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_173:
	/* 0x173: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_176:
	/* 0x176: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_178:
	/* 0x178: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17a:
	/* 0x17a: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_17f:
	/* 0x17f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_181:
	/* 0x181: je     274 <tail_handle_inter_cluster_revsnat+0x274> */
	X86_SIM_X86_JCC(X86_CC_E, 0x181, 0x274, x86_l_274);
x86_l_187:
	/* 0x187: mov    r15d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18a:
	/* 0x18a: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_193:
	/* 0x193: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_19c:
	/* 0x19c: movabs rax,0x6b0085010a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 459570217226ULL);
x86_l_1a6:
	/* 0x1a6: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1ab:
	/* 0x1ab: mov    rdi,QWORD PTR [rip+0x7bb7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1b2:
	/* 0x1b2: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1b7:
	/* 0x1b7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1bc:
	/* 0x1bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1be:
	/* 0x1be: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1c1:
	/* 0x1c1: je     12e4 <tail_handle_inter_cluster_revsnat+0x12e4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1c1, 0x12e4, x86_l_12e4);
x86_l_1c7:
	/* 0x1c7: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1ca:
	/* 0x1ca: add    QWORD PTR [rax+0x8],r15 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1ce:
	/* 0x1ce: jmp    1216 <tail_handle_inter_cluster_revsnat+0x1216> */
	X86_SIM_X86_JMP(0x1ce, 0x1216, x86_l_1216);
x86_l_1d3:
	/* 0x1d3: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_1d8:
	/* 0x1d8: mov    QWORD PTR [rsp+0x20],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1dd:
	/* 0x1dd: test   r8,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R8, X86_R14, X86_WIDTH_64);
x86_l_1e0:
	/* 0x1e0: jne    7d7 <tail_handle_inter_cluster_revsnat+0x7d7> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1e0, 0x7d7, x86_l_7d7);
x86_l_1e6:
	/* 0x1e6: lea    rdx,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1eb:
	/* 0x1eb: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1f0:
	/* 0x1f0: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1f3:
	/* 0x1f3: mov    QWORD PTR [rsp+0x48],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1f8:
	/* 0x1f8: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1fd:
	/* 0x1fd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ff:
	/* 0x1ff: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_201:
	/* 0x201: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_206:
	/* 0x206: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_208:
	/* 0x208: js     7d7 <tail_handle_inter_cluster_revsnat+0x7d7> */
	X86_SIM_X86_JCC(X86_CC_S, 0x208, 0x7d7, x86_l_7d7);
x86_l_20e:
	/* 0x20e: movzx  ecx,BYTE PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 88ULL);
x86_l_213:
	/* 0x213: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_215:
	/* 0x215: je     3e7 <tail_handle_inter_cluster_revsnat+0x3e7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x215, 0x3e7, x86_l_3e7);
x86_l_21b:
	/* 0x21b: mov    eax,0xffffff53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967123ULL);
x86_l_220:
	/* 0x220: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_223:
	/* 0x223: je     2d7 <tail_handle_inter_cluster_revsnat+0x2d7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x223, 0x2d7, x86_l_2d7);
x86_l_229:
	/* 0x229: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_22c:
	/* 0x22c: jne    7d7 <tail_handle_inter_cluster_revsnat+0x7d7> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x22c, 0x7d7, x86_l_7d7);
x86_l_232:
	/* 0x232: cmp    BYTE PTR [rsp+0x59],0xf */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 382252089359ULL);
x86_l_237:
	/* 0x237: jbe    2e2 <tail_handle_inter_cluster_revsnat+0x2e2> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x237, 0x2e2, x86_l_2e2);
x86_l_23d:
	/* 0x23d: jmp    7d7 <tail_handle_inter_cluster_revsnat+0x7d7> */
	X86_SIM_X86_JMP(0x23d, 0x7d7, x86_l_7d7);
x86_l_242:
	/* 0x242: movabs rax,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2199023255552ULL);
x86_l_24c:
	/* 0x24c: test   r8,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R8, X86_RAX, X86_WIDTH_64);
x86_l_24f:
	/* 0x24f: jne    1299 <tail_handle_inter_cluster_revsnat+0x1299> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x24f, 0x1299, x86_l_1299);
x86_l_255:
	/* 0x255: mov    r14,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R8, X86_WIDTH_64);
x86_l_258:
	/* 0x258: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_25d:
	/* 0x25d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_260:
	/* 0x260: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_263:
	/* 0x263: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_268:
	/* 0x268: mov    rbp,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RSI, X86_WIDTH_64);
x86_l_26b:
	/* 0x26b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26d:
	/* 0x26d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_26f:
	/* 0x26f: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_272:
	/* 0x272: js     2ca <tail_handle_inter_cluster_revsnat+0x2ca> */
	X86_SIM_X86_JCC(X86_CC_S, 0x272, 0x2ca, x86_l_2ca);
x86_l_274:
	/* 0x274: inc    r12d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_277:
	/* 0x277: movzx  eax,WORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_27c:
	/* 0x27c: movzx  ecx,WORD PTR [rsp+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_281:
	/* 0x281: mov    WORD PTR [rsp+0x3a],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_286:
	/* 0x286: mov    WORD PTR [rsp+0x38],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_28b:
	/* 0x28b: rol    cx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_28f:
	/* 0x28f: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_295:
	/* 0x295: cmp    cx,r12w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R12, X86_WIDTH_16);
x86_l_299:
	/* 0x299: mov    r15d,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_29e:
	/* 0x29e: jae    40f <tail_handle_inter_cluster_revsnat+0x40f> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x29e, 0x40f, x86_l_40f);
x86_l_2a4:
	/* 0x2a4: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a7:
	/* 0x2a7: mov    ebp,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R13, X86_WIDTH_32);
x86_l_2aa:
	/* 0x2aa: jmp    7fa <tail_handle_inter_cluster_revsnat+0x7fa> */
	X86_SIM_X86_JMP(0x2aa, 0x7fa, x86_l_7fa);
x86_l_2af:
	/* 0x2af: mov    eax,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967161ULL);
x86_l_2b4:
	/* 0x2b4: mov    ebp,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R13, X86_WIDTH_32);
x86_l_2b7:
	/* 0x2b7: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ba:
	/* 0x2ba: cmp    eax,0xffffff53 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967123ULL);
x86_l_2bf:
	/* 0x2bf: jne    7e6 <tail_handle_inter_cluster_revsnat+0x7e6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2bf, 0x7e6, x86_l_7e6);
x86_l_2c5:
	/* 0x2c5: jmp    7fa <tail_handle_inter_cluster_revsnat+0x7fa> */
	X86_SIM_X86_JMP(0x2c5, 0x7fa, x86_l_7fa);
x86_l_2ca:
	/* 0x2ca: mov    eax,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967161ULL);
x86_l_2cf:
	/* 0x2cf: mov    ebp,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R13, X86_WIDTH_32);
x86_l_2d2:
	/* 0x2d2: jmp    ac8 <tail_handle_inter_cluster_revsnat+0xac8> */
	X86_SIM_X86_JMP(0x2d2, 0xac8, x86_l_ac8);
x86_l_2d7:
	/* 0x2d7: cmp    BYTE PTR [rsp+0x59],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 382252089345ULL);
x86_l_2dc:
	/* 0x2dc: ja     7d7 <tail_handle_inter_cluster_revsnat+0x7d7> */
	X86_SIM_X86_JCC(X86_CC_A, 0x2dc, 0x7d7, x86_l_7d7);
x86_l_2e2:
	/* 0x2e2: mov    QWORD PTR [rsp+0xe],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60129542144ULL);
x86_l_2eb:
	/* 0x2eb: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2f4:
	/* 0x2f4: mov    r14d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f7:
	/* 0x2f7: mov    rax,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_2fc:
	/* 0x2fc: lea    r12d,[rax+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_300:
	/* 0x300: lea    rdx,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_305:
	/* 0x305: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_30a:
	/* 0x30a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_30d:
	/* 0x30d: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_310:
	/* 0x310: mov    ecx,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 20ULL);
x86_l_315:
	/* 0x315: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_317:
	/* 0x317: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_319:
	/* 0x319: js     7d2 <tail_handle_inter_cluster_revsnat+0x7d2> */
	X86_SIM_X86_JCC(X86_CC_S, 0x319, 0x7d2, x86_l_7d2);
x86_l_31f:
	/* 0x31f: movzx  ecx,BYTE PTR [rsp+0x71] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 113ULL);
x86_l_324:
	/* 0x324: mov    eax,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_328:
	/* 0x328: mov    BYTE PTR [rsp+0x14],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_32c:
	/* 0x32c: mov    rdx,QWORD PTR [rsp+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_331:
	/* 0x331: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_336:
	/* 0x336: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_339:
	/* 0x339: mov    BYTE PTR [rsp+0x15],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 90194313217ULL);
x86_l_33e:
	/* 0x33e: lea    r13d,[r12+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_342:
	/* 0x342: mov    eax,0xffffff53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967123ULL);
x86_l_347:
	/* 0x347: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_34a:
	/* 0x34a: je     77c <tail_handle_inter_cluster_revsnat+0x77c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x34a, 0x77c, x86_l_77c);
x86_l_350:
	/* 0x350: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_353:
	/* 0x353: je     35e <tail_handle_inter_cluster_revsnat+0x35e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x353, 0x35e, x86_l_35e);
x86_l_355:
	/* 0x355: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_358:
	/* 0x358: jne    7d7 <tail_handle_inter_cluster_revsnat+0x7d7> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x358, 0x7d7, x86_l_7d7);
x86_l_35e:
	/* 0x35e: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_363:
	/* 0x363: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_368:
	/* 0x368: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_36b:
	/* 0x36b: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_36e:
	/* 0x36e: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_373:
	/* 0x373: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_375:
	/* 0x375: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_377:
	/* 0x377: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_379:
	/* 0x379: js     7d2 <tail_handle_inter_cluster_revsnat+0x7d2> */
	X86_SIM_X86_JCC(X86_CC_S, 0x379, 0x7d2, x86_l_7d2);
x86_l_37f:
	/* 0x37f: mov    DWORD PTR [rsp+0x50],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_383:
	/* 0x383: mov    QWORD PTR [rsp+0x60],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_388:
	/* 0x388: mov    rdi,QWORD PTR [rip+0x7bb7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_38f:
	/* 0x38f: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_394:
	/* 0x394: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_399:
	/* 0x399: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39b:
	/* 0x39b: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_39e:
	/* 0x39e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3a1:
	/* 0x3a1: mov    eax,0xffffff53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967123ULL);
x86_l_3a6:
	/* 0x3a6: mov    r8,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3ab:
	/* 0x3ab: je     7d7 <tail_handle_inter_cluster_revsnat+0x7d7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3ab, 0x7d7, x86_l_7d7);
x86_l_3b1:
	/* 0x3b1: movzx  eax,BYTE PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 20ULL);
x86_l_3b6:
	/* 0x3b6: mov    dl,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_8, 1ULL);
x86_l_3b8:
	/* 0x3b8: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_3bb:
	/* 0x3bb: je     fdb <tail_handle_inter_cluster_revsnat+0xfdb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3bb, 0xfdb, x86_l_fdb);
x86_l_3c1:
	/* 0x3c1: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_3c4:
	/* 0x3c4: jne    101f <tail_handle_inter_cluster_revsnat+0x101f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3c4, 0x101f, x86_l_101f);
x86_l_3ca:
	/* 0x3ca: sub    r14d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R12, X86_WIDTH_32, X86_ALU_SUB);
x86_l_3cd:
	/* 0x3cd: mov    eax,DWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_3d1:
	/* 0x3d1: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_3d4:
	/* 0x3d4: lea    eax,[rax*4+0x12] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 18ULL);
x86_l_3db:
	/* 0x3db: cmp    r14d,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R14, X86_RAX, X86_WIDTH_32);
x86_l_3de:
	/* 0x3de: setae  sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_AE);
x86_l_3e2:
	/* 0x3e2: jmp    1022 <tail_handle_inter_cluster_revsnat+0x1022> */
	X86_SIM_X86_JMP(0x3e2, 0x1022, x86_l_1022);
x86_l_3e7:
	/* 0x3e7: mov    QWORD PTR [rsp],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3eb:
	/* 0x3eb: mov    r13d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBP, X86_WIDTH_32);
x86_l_3ee:
	/* 0x3ee: movzx  eax,WORD PTR [rsp+0x5c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 92ULL);
x86_l_3f3:
	/* 0x3f3: mov    WORD PTR [rsp+0x38],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3f8:
	/* 0x3f8: mov    WORD PTR [rsp+0x3a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 249108103168ULL);
x86_l_3ff:
	/* 0x3ff: mov    r14d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 4ULL);
x86_l_405:
	/* 0x405: mov    rbp,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_40a:
	/* 0x40a: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_40f:
	/* 0x40f: mov    QWORD PTR [rsp+0x20],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_414:
	/* 0x414: mov    QWORD PTR [rsp+0x48],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_419:
	/* 0x419: mov    DWORD PTR [rsp+0x68],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_41e:
	/* 0x41e: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_421:
	/* 0x421: je     431 <tail_handle_inter_cluster_revsnat+0x431> */
	X86_SIM_X86_JCC(X86_CC_E, 0x421, 0x431, x86_l_431);
x86_l_423:
	/* 0x423: mov    rax,QWORD PTR [rip+0x7bb7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_cluster_id)));
x86_l_42a:
	/* 0x42a: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_42c:
	/* 0x42c: cmp    eax,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_42f:
	/* 0x42f: jne    43a <tail_handle_inter_cluster_revsnat+0x43a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x42f, 0x43a, x86_l_43a);
x86_l_431:
	/* 0x431: mov    r12,QWORD PTR [rip+0x7bb7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&cilium_snat_v4_external)));
x86_l_438:
	/* 0x438: jmp    459 <tail_handle_inter_cluster_revsnat+0x459> */
	X86_SIM_X86_JMP(0x438, 0x459, x86_l_459);
x86_l_43a:
	/* 0x43a: mov    rdi,QWORD PTR [rip+0x7bb7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_per_cluster_snat_v4_external)));
x86_l_441:
	/* 0x441: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_446:
	/* 0x446: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_44b:
	/* 0x44b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_44d:
	/* 0x44d: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_450:
	/* 0x450: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_453:
	/* 0x453: je     532 <tail_handle_inter_cluster_revsnat+0x532> */
	X86_SIM_X86_JCC(X86_CC_E, 0x453, 0x532, x86_l_532);
x86_l_459:
	/* 0x459: mov    DWORD PTR [rsp+0x60],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_45e:
	/* 0x45e: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_463:
	/* 0x463: mov    r15d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 1ULL);
x86_l_469:
	/* 0x469: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_46c:
	/* 0x46c: call   r15 */
	X86_SIM_BPF_CALL_REG(X86_R15);
x86_l_46f:
	/* 0x46f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_472:
	/* 0x472: mov    ebp,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R13, X86_WIDTH_32);
x86_l_475:
	/* 0x475: je     5da <tail_handle_inter_cluster_revsnat+0x5da> */
	X86_SIM_X86_JCC(X86_CC_E, 0x475, 0x5da, x86_l_5da);
x86_l_47b:
	/* 0x47b: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_47e:
	/* 0x47e: mov    eax,DWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_481:
	/* 0x481: mov    DWORD PTR [rsp+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_485:
	/* 0x485: movzx  eax,WORD PTR [r13+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_48a:
	/* 0x48a: mov    WORD PTR [rsp+0x12],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_48f:
	/* 0x48f: mov    eax,DWORD PTR [rsp+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_493:
	/* 0x493: mov    DWORD PTR [rsp+0x8],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_497:
	/* 0x497: movzx  eax,WORD PTR [rsp+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_49c:
	/* 0x49c: mov    WORD PTR [rsp+0x10],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4a1:
	/* 0x4a1: movzx  eax,BYTE PTR [rsp+0x3c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 60ULL);
x86_l_4a6:
	/* 0x4a6: mov    BYTE PTR [rsp+0x14],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_4aa:
	/* 0x4aa: mov    BYTE PTR [rsp+0x15],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 90194313216ULL);
x86_l_4af:
	/* 0x4af: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4b4:
	/* 0x4b4: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_4b7:
	/* 0x4b7: call   r15 */
	X86_SIM_BPF_CALL_REG(X86_R15);
x86_l_4ba:
	/* 0x4ba: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4bd:
	/* 0x4bd: jne    581 <tail_handle_inter_cluster_revsnat+0x581> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4bd, 0x581, x86_l_581);
x86_l_4c3:
	/* 0x4c3: mov    QWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_4cf:
	/* 0x4cf: mov    QWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_4db:
	/* 0x4db: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_4e4:
	/* 0x4e4: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_4ed:
	/* 0x4ed: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_4f6:
	/* 0x4f6: mov    eax,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4fa:
	/* 0x4fa: mov    DWORD PTR [rsp+0x88],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_501:
	/* 0x501: movzx  eax,WORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_506:
	/* 0x506: mov    WORD PTR [rsp+0x8c],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 140ULL);
x86_l_50e:
	/* 0x50e: mov    rax,QWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_512:
	/* 0x512: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_517:
	/* 0x517: mov    rax,QWORD PTR [rip+0x7bb7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_51e:
	/* 0x51e: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_521:
	/* 0x521: je     53f <tail_handle_inter_cluster_revsnat+0x53f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x521, 0x53f, x86_l_53f);
x86_l_523:
	/* 0x523: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_528:
	/* 0x528: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_52a:
	/* 0x52a: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_52c:
	/* 0x52c: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_530:
	/* 0x530: jmp    562 <tail_handle_inter_cluster_revsnat+0x562> */
	X86_SIM_X86_JMP(0x530, 0x562, x86_l_562);
x86_l_532:
	/* 0x532: mov    eax,0xffffff41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967105ULL);
x86_l_537:
	/* 0x537: mov    ebp,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R13, X86_WIDTH_32);
x86_l_53a:
	/* 0x53a: jmp    ac8 <tail_handle_inter_cluster_revsnat+0xac8> */
	X86_SIM_X86_JMP(0x53a, 0xac8, x86_l_ac8);
x86_l_53f:
	/* 0x53f: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_544:
	/* 0x544: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_546:
	/* 0x546: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_548:
	/* 0x548: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_54c:
	/* 0x54c: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_556:
	/* 0x556: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_559:
	/* 0x559: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_55e:
	/* 0x55e: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_562:
	/* 0x562: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_567:
	/* 0x567: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_56c:
	/* 0x56c: lea    rdx,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_571:
	/* 0x571: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_576:
	/* 0x576: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_579:
	/* 0x579: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_57b:
	/* 0x57b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_57d:
	/* 0x57d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_57f:
	/* 0x57f: js     5da <tail_handle_inter_cluster_revsnat+0x5da> */
	X86_SIM_X86_JCC(X86_CC_S, 0x57f, 0x5da, x86_l_5da);
x86_l_581:
	/* 0x581: cmp    QWORD PTR [r13+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_586:
	/* 0x586: mov    r9,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_58b:
	/* 0x58b: mov    DWORD PTR [rsp+0x50],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_590:
	/* 0x590: je     dca <tail_handle_inter_cluster_revsnat+0xdca> */
	X86_SIM_X86_JCC(X86_CC_E, 0x590, 0xdca, x86_l_dca);
x86_l_596:
	/* 0x596: movzx  eax,WORD PTR [rsp+0x3c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 60ULL);
x86_l_59b:
	/* 0x59b: mov    WORD PTR [rsp+0x14],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_5a0:
	/* 0x5a0: movzx  ecx,WORD PTR [rsp+0x3a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 58ULL);
x86_l_5a5:
	/* 0x5a5: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5aa:
	/* 0x5aa: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5af:
	/* 0x5af: mov    edx,DWORD PTR [r13+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5b3:
	/* 0x5b3: mov    DWORD PTR [rsp+0x8],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b7:
	/* 0x5b7: movzx  edx,WORD PTR [r13+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_5bc:
	/* 0x5bc: mov    WORD PTR [rsp+0x12],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_5c1:
	/* 0x5c1: mov    WORD PTR [rsp+0x10],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5c6:
	/* 0x5c6: movzx  r15d,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_5ca:
	/* 0x5ca: cmp    r15w,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_16, 6ULL);
x86_l_5cf:
	/* 0x5cf: jne    5e2 <tail_handle_inter_cluster_revsnat+0x5e2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x5cf, 0x5e2, x86_l_5e2);
x86_l_5d1:
	/* 0x5d1: mov    rdi,QWORD PTR [rip+0x7bb7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct4_global)));
x86_l_5d8:
	/* 0x5d8: jmp    5e9 <tail_handle_inter_cluster_revsnat+0x5e9> */
	X86_SIM_X86_JMP(0x5d8, 0x5e9, x86_l_5e9);
x86_l_5da:
	/* 0x5da: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5dd:
	/* 0x5dd: jmp    7fa <tail_handle_inter_cluster_revsnat+0x7fa> */
	X86_SIM_X86_JMP(0x5dd, 0x7fa, x86_l_7fa);
x86_l_5e2:
	/* 0x5e2: mov    rdi,QWORD PTR [rip+0x7bb7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ct_any4_global)));
x86_l_5e9:
	/* 0x5e9: mov    rcx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_5ee:
	/* 0x5ee: mov    BYTE PTR [rsp+0x15],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 90194313216ULL);
x86_l_5f3:
	/* 0x5f3: mov    DWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_5fb:
	/* 0x5fb: mov    rax,QWORD PTR [rip+0x7bb7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_ipv4_fragments)));
x86_l_602:
	/* 0x602: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_605:
	/* 0x605: je     6a0 <tail_handle_inter_cluster_revsnat+0x6a0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x605, 0x6a0, x86_l_6a0);
x86_l_60b:
	/* 0x60b: and    QWORD PTR [rsp],r9 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RSP, X86_R9, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 0ULL);
x86_l_60f:
	/* 0x60f: je     6a0 <tail_handle_inter_cluster_revsnat+0x6a0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x60f, 0x6a0, x86_l_6a0);
x86_l_615:
	/* 0x615: mov    QWORD PTR [rsp],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_619:
	/* 0x619: mov    r12,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R13, X86_WIDTH_64);
x86_l_61c:
	/* 0x61c: mov    r13d,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R15, X86_WIDTH_32);
x86_l_61f:
	/* 0x61f: mov    r14d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_622:
	/* 0x622: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_62b:
	/* 0x62b: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_634:
	/* 0x634: movabs rax,0x6c03a50109 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 463917613321ULL);
x86_l_63e:
	/* 0x63e: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_643:
	/* 0x643: mov    rdi,QWORD PTR [rip+0x7bb7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_64a:
	/* 0x64a: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_64f:
	/* 0x64f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_654:
	/* 0x654: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_656:
	/* 0x656: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_659:
	/* 0x659: je     664 <tail_handle_inter_cluster_revsnat+0x664> */
	X86_SIM_X86_JCC(X86_CC_E, 0x659, 0x664, x86_l_664);
x86_l_65b:
	/* 0x65b: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_65e:
	/* 0x65e: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_662:
	/* 0x662: jmp    68c <tail_handle_inter_cluster_revsnat+0x68c> */
	X86_SIM_X86_JMP(0x662, 0x68c, x86_l_68c);
x86_l_664:
	/* 0x664: mov    QWORD PTR [rsp+0x68],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598785ULL);
x86_l_66d:
	/* 0x66d: mov    QWORD PTR [rsp+0x70],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_672:
	/* 0x672: mov    rdi,QWORD PTR [rip+0x7bb7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_679:
	/* 0x679: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_67e:
	/* 0x67e: lea    rdx,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_683:
	/* 0x683: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_688:
	/* 0x688: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_68a:
	/* 0x68a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_68c:
	/* 0x68c: mov    rcx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_691:
	/* 0x691: mov    r9,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_696:
	/* 0x696: mov    r15d,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_32);
x86_l_699:
	/* 0x699: mov    r13,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R12, X86_WIDTH_64);
x86_l_69c:
	/* 0x69c: mov    rdi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6a0:
	/* 0x6a0: cmp    r15w,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_16, 6ULL);
x86_l_6a5:
	/* 0x6a5: jne    712 <tail_handle_inter_cluster_revsnat+0x712> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x6a5, 0x712, x86_l_712);
x86_l_6a7:
	/* 0x6a7: mov    rax,r9 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R9, X86_WIDTH_64);
x86_l_6aa:
	/* 0x6aa: movabs rdx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 2199023255552ULL);
x86_l_6b4:
	/* 0x6b4: and    rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_AND);
x86_l_6b7:
	/* 0x6b7: jne    712 <tail_handle_inter_cluster_revsnat+0x712> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x6b7, 0x712, x86_l_712);
x86_l_6b9:
	/* 0x6b9: mov    QWORD PTR [rsp+0x18],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6be:
	/* 0x6be: mov    r13,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RDI, X86_WIDTH_64);
x86_l_6c1:
	/* 0x6c1: lea    esi,[rcx+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_6c4:
	/* 0x6c4: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6c9:
	/* 0x6c9: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_6ce:
	/* 0x6ce: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_6d1:
	/* 0x6d1: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_6d6:
	/* 0x6d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6d8:
	/* 0x6d8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_6da:
	/* 0x6da: js     772 <tail_handle_inter_cluster_revsnat+0x772> */
	X86_SIM_X86_JCC(X86_CC_S, 0x6da, 0x772, x86_l_772);
x86_l_6e0:
	/* 0x6e0: mov    ecx,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6e4:
	/* 0x6e4: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_6e6:
	/* 0x6e6: and    eax,0x1200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4608ULL);
x86_l_6eb:
	/* 0x6eb: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_6ee:
	/* 0x6ee: cmp    eax,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 512ULL);
x86_l_6f3:
	/* 0x6f3: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_6f6:
	/* 0x6f6: mov    DWORD PTR [rsp],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6f9:
	/* 0x6f9: test   ecx,0x500 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_32, 1280ULL);
x86_l_6ff:
	/* 0x6ff: jne    1311 <tail_handle_inter_cluster_revsnat+0x1311> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x6ff, 0x1311, x86_l_1311);
x86_l_705:
	/* 0x705: mov    r12b,al */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_8);
x86_l_708:
	/* 0x708: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_70b:
	/* 0x70b: mov    r13,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_710:
	/* 0x710: jmp    71c <tail_handle_inter_cluster_revsnat+0x71c> */
	X86_SIM_X86_JMP(0x710, 0x71c, x86_l_71c);
x86_l_712:
	/* 0x712: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_715:
	/* 0x715: mov    eax,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_719:
	/* 0x719: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_71c:
	/* 0x71c: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_721:
	/* 0x721: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_726:
	/* 0x726: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_728:
	/* 0x728: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_72b:
	/* 0x72b: mov    r9,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_730:
	/* 0x730: je     dc1 <tail_handle_inter_cluster_revsnat+0xdc1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x730, 0xdc1, x86_l_dc1);
x86_l_736:
	/* 0x736: mov    r8,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_RAX, X86_WIDTH_64);
x86_l_739:
	/* 0x739: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_73c:
	/* 0x73c: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_73e:
	/* 0x73e: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_740:
	/* 0x740: test   cl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_743:
	/* 0x743: je     c68 <tail_handle_inter_cluster_revsnat+0xc68> */
	X86_SIM_X86_JCC(X86_CC_E, 0x743, 0xc68, x86_l_c68);
x86_l_749:
	/* 0x749: mov    DWORD PTR [rsp+0x44],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_74e:
	/* 0x74e: mov    rdx,QWORD PTR [rip+0x7bb7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_755:
	/* 0x755: cmp    BYTE PTR [rdx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_758:
	/* 0x758: je     b76 <tail_handle_inter_cluster_revsnat+0xb76> */
	X86_SIM_X86_JCC(X86_CC_E, 0x758, 0xb76, x86_l_b76);
x86_l_75e:
	/* 0x75e: mov    rcx,QWORD PTR [rip+0x7bb7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_765:
	/* 0x765: imul   r12d,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_769:
	/* 0x769: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_76d:
	/* 0x76d: jmp    b7c <tail_handle_inter_cluster_revsnat+0xb7c> */
	X86_SIM_X86_JMP(0x76d, 0xb7c, x86_l_b7c);
x86_l_772:
	/* 0x772: mov    eax,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967161ULL);
x86_l_777:
	/* 0x777: jmp    ac8 <tail_handle_inter_cluster_revsnat+0xac8> */
	X86_SIM_X86_JMP(0x777, 0xac8, x86_l_ac8);
x86_l_77c:
	/* 0x77c: lea    rdx,[rsp+0x2f] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 47ULL);
x86_l_781:
	/* 0x781: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_786:
	/* 0x786: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_789:
	/* 0x789: mov    esi,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_32);
x86_l_78c:
	/* 0x78c: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_791:
	/* 0x791: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_793:
	/* 0x793: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_795:
	/* 0x795: js     7d2 <tail_handle_inter_cluster_revsnat+0x7d2> */
	X86_SIM_X86_JCC(X86_CC_S, 0x795, 0x7d2, x86_l_7d2);
x86_l_797:
	/* 0x797: movzx  eax,BYTE PTR [rsp+0x2f] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 47ULL);
x86_l_79c:
	/* 0x79c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_79e:
	/* 0x79e: je     1126 <tail_handle_inter_cluster_revsnat+0x1126> */
	X86_SIM_X86_JCC(X86_CC_E, 0x79e, 0x1126, x86_l_1126);
x86_l_7a4:
	/* 0x7a4: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_7a7:
	/* 0x7a7: jne    1130 <tail_handle_inter_cluster_revsnat+0x1130> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x7a7, 0x1130, x86_l_1130);
x86_l_7ad:
	/* 0x7ad: lea    esi,[r13+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_7b1:
	/* 0x7b1: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_7b6:
	/* 0x7b6: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_7bb:
	/* 0x7bb: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_7be:
	/* 0x7be: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_7c3:
	/* 0x7c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7c5:
	/* 0x7c5: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_7ca:
	/* 0x7ca: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_7cc:
	/* 0x7cc: jns    37f <tail_handle_inter_cluster_revsnat+0x37f> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x7cc, 0x37f, x86_l_37f);
x86_l_7d2:
	/* 0x7d2: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_7d7:
	/* 0x7d7: mov    DWORD PTR [rsp+0x60],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_7dc:
	/* 0x7dc: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7df:
	/* 0x7df: cmp    eax,0xffffff53 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967123ULL);
x86_l_7e4:
	/* 0x7e4: je     7fa <tail_handle_inter_cluster_revsnat+0x7fa> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7e4, 0x7fa, x86_l_7fa);
x86_l_7e6:
	/* 0x7e6: cmp    eax,0xffffff59 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967129ULL);
x86_l_7eb:
	/* 0x7eb: je     7fa <tail_handle_inter_cluster_revsnat+0x7fa> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7eb, 0x7fa, x86_l_7fa);
x86_l_7ed:
	/* 0x7ed: mov    r15d,DWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_7f2:
	/* 0x7f2: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_7f4:
	/* 0x7f4: js     ac8 <tail_handle_inter_cluster_revsnat+0xac8> */
	X86_SIM_X86_JCC(X86_CC_S, 0x7f4, 0xac8, x86_l_ac8);
x86_l_7fa:
	/* 0x7fa: mov    r14d,DWORD PTR [rbx+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_7fe:
	/* 0x7fe: mov    ecx,DWORD PTR [rbx+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_801:
	/* 0x801: lea    rdx,[r14+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_805:
	/* 0x805: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_80a:
	/* 0x80a: cmp    rdx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_80d:
	/* 0x80d: ja     ac8 <tail_handle_inter_cluster_revsnat+0xac8> */
	X86_SIM_X86_JCC(X86_CC_A, 0x80d, 0xac8, x86_l_ac8);
x86_l_813:
	/* 0x813: mov    eax,DWORD PTR [r14+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_817:
	/* 0x817: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_820:
	/* 0x820: mov    DWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_828:
	/* 0x828: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_831:
	/* 0x831: mov    DWORD PTR [rsp+0x68],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_835:
	/* 0x835: mov    BYTE PTR [rsp+0x78],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 515396075521ULL);
x86_l_83a:
	/* 0x83a: mov    rdi,QWORD PTR [rip+0x7bb7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lxc)));
x86_l_841:
	/* 0x841: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_846:
	/* 0x846: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_84b:
	/* 0x84b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_84d:
	/* 0x84d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_850:
	/* 0x850: je     925 <tail_handle_inter_cluster_revsnat+0x925> */
	X86_SIM_X86_JCC(X86_CC_E, 0x850, 0x925, x86_l_925);
x86_l_856:
	/* 0x856: test   BYTE PTR [rax+0x8],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738371ULL);
x86_l_85a:
	/* 0x85a: je     92f <tail_handle_inter_cluster_revsnat+0x92f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x85a, 0x92f, x86_l_92f);
x86_l_860:
	/* 0x860: mov    rax,QWORD PTR [rip+0x7bb7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_interface_mac)));
x86_l_867:
	/* 0x867: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_86a:
	/* 0x86a: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_86f:
	/* 0x86f: mov    rax,QWORD PTR [rip+0x7bb7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_cilium_host_mac)));
x86_l_876:
	/* 0x876: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_879:
	/* 0x879: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_87e:
	/* 0x87e: movzx  edx,BYTE PTR [r14+0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 22ULL);
x86_l_883:
	/* 0x883: mov    eax,0xffffff3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967100ULL);
x86_l_888:
	/* 0x888: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_88b:
	/* 0x88b: jb     abb <tail_handle_inter_cluster_revsnat+0xabb> */
	X86_SIM_X86_JCC(X86_CC_B, 0x88b, 0xabb, x86_l_abb);
x86_l_891:
	/* 0x891: lea    eax,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_894:
	/* 0x894: mov    BYTE PTR [r14+0x16],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_898:
	/* 0x898: movzx  ecx,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_89b:
	/* 0x89b: mov    eax,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_8a0:
	/* 0x8a0: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_8a3:
	/* 0x8a3: mov    esi,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 24ULL);
x86_l_8a8:
	/* 0x8a8: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_8ae:
	/* 0x8ae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8b0:
	/* 0x8b0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_8b2:
	/* 0x8b2: js     ab6 <tail_handle_inter_cluster_revsnat+0xab6> */
	X86_SIM_X86_JCC(X86_CC_S, 0x8b2, 0xab6, x86_l_ab6);
x86_l_8b8:
	/* 0x8b8: lea    rdx,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_8bd:
	/* 0x8bd: mov    r14d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 9ULL);
x86_l_8c3:
	/* 0x8c3: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_8c6:
	/* 0x8c6: mov    esi,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 6ULL);
x86_l_8cb:
	/* 0x8cb: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_8d0:
	/* 0x8d0: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8d3:
	/* 0x8d3: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_8d6:
	/* 0x8d6: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_8d8:
	/* 0x8d8: mov    eax,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967155ULL);
x86_l_8dd:
	/* 0x8dd: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_8df:
	/* 0x8df: js     abb <tail_handle_inter_cluster_revsnat+0xabb> */
	X86_SIM_X86_JCC(X86_CC_S, 0x8df, 0xabb, x86_l_abb);
x86_l_8e5:
	/* 0x8e5: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8ea:
	/* 0x8ea: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_8ed:
	/* 0x8ed: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8ef:
	/* 0x8ef: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_8f4:
	/* 0x8f4: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8f7:
	/* 0x8f7: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_8fa:
	/* 0x8fa: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_8fc:
	/* 0x8fc: mov    eax,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967155ULL);
x86_l_901:
	/* 0x901: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_903:
	/* 0x903: js     abb <tail_handle_inter_cluster_revsnat+0xabb> */
	X86_SIM_X86_JCC(X86_CC_S, 0x903, 0xabb, x86_l_abb);
x86_l_909:
	/* 0x909: mov    rax,QWORD PTR [rip+0x7bb7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_cilium_host_ifindex)));
x86_l_910:
	/* 0x910: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_912:
	/* 0x912: mov    edi,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_914:
	/* 0x914: mov    eax,0x17 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 23ULL);
x86_l_919:
	/* 0x919: mov    esi,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_91e:
	/* 0x91e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_920:
	/* 0x920: jmp    abb <tail_handle_inter_cluster_revsnat+0xabb> */
	X86_SIM_X86_JMP(0x920, 0xabb, x86_l_abb);
x86_l_925:
	/* 0x925: mov    eax,0xffffff69 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967145ULL);
x86_l_92a:
	/* 0x92a: jmp    ac8 <tail_handle_inter_cluster_revsnat+0xac8> */
	X86_SIM_X86_JMP(0x92a, 0xac8, x86_l_ac8);
x86_l_92f:
	/* 0x92f: mov    rcx,QWORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_933:
	/* 0x933: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_938:
	/* 0x938: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_93b:
	/* 0x93b: mov    rax,QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_93f:
	/* 0x93f: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_944:
	/* 0x944: movzx  edx,BYTE PTR [r14+0x16] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 22ULL);
x86_l_949:
	/* 0x949: mov    eax,0xffffff3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967100ULL);
x86_l_94e:
	/* 0x94e: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_951:
	/* 0x951: jb     abb <tail_handle_inter_cluster_revsnat+0xabb> */
	X86_SIM_X86_JCC(X86_CC_B, 0x951, 0xabb, x86_l_abb);
x86_l_957:
	/* 0x957: lea    eax,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_95a:
	/* 0x95a: mov    BYTE PTR [r14+0x16],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_95e:
	/* 0x95e: movzx  ecx,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_961:
	/* 0x961: mov    eax,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_966:
	/* 0x966: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_969:
	/* 0x969: mov    esi,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 24ULL);
x86_l_96e:
	/* 0x96e: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_974:
	/* 0x974: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_976:
	/* 0x976: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_978:
	/* 0x978: js     ab6 <tail_handle_inter_cluster_revsnat+0xab6> */
	X86_SIM_X86_JCC(X86_CC_S, 0x978, 0xab6, x86_l_ab6);
x86_l_97e:
	/* 0x97e: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_983:
	/* 0x983: mov    r14d,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 9ULL);
x86_l_989:
	/* 0x989: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_98c:
	/* 0x98c: mov    esi,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 6ULL);
x86_l_991:
	/* 0x991: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_996:
	/* 0x996: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_999:
	/* 0x999: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_99c:
	/* 0x99c: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_99e:
	/* 0x99e: mov    eax,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967155ULL);
x86_l_9a3:
	/* 0x9a3: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_9a5:
	/* 0x9a5: js     abb <tail_handle_inter_cluster_revsnat+0xabb> */
	X86_SIM_X86_JCC(X86_CC_S, 0x9a5, 0xabb, x86_l_abb);
x86_l_9ab:
	/* 0x9ab: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9b0:
	/* 0x9b0: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_9b3:
	/* 0x9b3: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9b5:
	/* 0x9b5: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_9ba:
	/* 0x9ba: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9bd:
	/* 0x9bd: call   r14 */
	X86_SIM_BPF_CALL_REG(X86_R14);
x86_l_9c0:
	/* 0x9c0: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_9c2:
	/* 0x9c2: mov    eax,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967155ULL);
x86_l_9c7:
	/* 0x9c7: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_9c9:
	/* 0x9c9: js     abb <tail_handle_inter_cluster_revsnat+0xabb> */
	X86_SIM_X86_JCC(X86_CC_S, 0x9c9, 0xabb, x86_l_abb);
x86_l_9cf:
	/* 0x9cf: movzx  eax,WORD PTR [r12+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_9d5:
	/* 0x9d5: movabs r13,0x100000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 4294967296ULL);
x86_l_9df:
	/* 0x9df: mov    QWORD PTR [rsp+0x68],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_9e4:
	/* 0x9e4: mov    DWORD PTR [rsp+0x68],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_9e8:
	/* 0x9e8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_9ea:
	/* 0x9ea: je     a7c <tail_handle_inter_cluster_revsnat+0xa7c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9ea, 0xa7c, x86_l_a7c);
x86_l_9f0:
	/* 0x9f0: mov    rdi,QWORD PTR [rip+0x7bb7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_throttle)));
x86_l_9f7:
	/* 0x9f7: lea    rsi,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_9fc:
	/* 0x9fc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a01:
	/* 0xa01: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a03:
	/* 0xa03: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a06:
	/* 0xa06: je     a7c <tail_handle_inter_cluster_revsnat+0xa7c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa06, 0xa7c, x86_l_a7c);
x86_l_a08:
	/* 0xa08: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_a0b:
	/* 0xa0b: cmp    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a0f:
	/* 0xa0f: je     a7c <tail_handle_inter_cluster_revsnat+0xa7c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa0f, 0xa7c, x86_l_a7c);
x86_l_a11:
	/* 0xa11: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_a16:
	/* 0xa16: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a18:
	/* 0xa18: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_a1a:
	/* 0xa1a: mov    rsi,QWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a1d:
	/* 0xa1d: mov    rdi,QWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a21:
	/* 0xa21: mov    rcx,QWORD PTR [r14+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a25:
	/* 0xa25: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_a28:
	/* 0xa28: sub    rdx,rdi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_a2b:
	/* 0xa2b: je     a55 <tail_handle_inter_cluster_revsnat+0xa55> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa2b, 0xa55, x86_l_a55);
x86_l_a2d:
	/* 0xa2d: imul   rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_IMUL);
x86_l_a31:
	/* 0xa31: shr    rdx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_a35:
	/* 0xa35: movabs rdi,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_64, 19342813113834067ULL);
x86_l_a3f:
	/* 0xa3f: mulx   rdx,rdx,rdi */
	X86_SIM_L_EXEC_MULX(X86_RDX, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_a44:
	/* 0xa44: shr    rdx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_a48:
	/* 0xa48: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_a4b:
	/* 0xa4b: cmp    rdx,rsi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_a4e:
	/* 0xa4e: cmovae rdx,rsi */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RSI, X86_WIDTH_64, X86_CC_AE);
x86_l_a52:
	/* 0xa52: mov    rcx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_a55:
	/* 0xa55: mov    edx,DWORD PTR [rbx+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_a5b:
	/* 0xa5b: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a5d:
	/* 0xa5d: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_a60:
	/* 0xa60: cmovae rsi,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RSI, X86_RDX, X86_WIDTH_64, X86_CC_AE);
x86_l_a64:
	/* 0xa64: mov    rdi,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RCX, X86_WIDTH_64);
x86_l_a67:
	/* 0xa67: sub    rdi,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_a6a:
	/* 0xa6a: mov    QWORD PTR [r14+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a6e:
	/* 0xa6e: mov    QWORD PTR [r14+0x10],rdi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a72:
	/* 0xa72: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_a77:
	/* 0xa77: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_a7a:
	/* 0xa7a: jb     abb <tail_handle_inter_cluster_revsnat+0xabb> */
	X86_SIM_X86_JCC(X86_CC_B, 0xa7a, 0xabb, x86_l_abb);
x86_l_a7c:
	/* 0xa7c: mov    rax,QWORD PTR [rip+0x7bb7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_netkit)));
x86_l_a83:
	/* 0xa83: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_a86:
	/* 0xa86: mov    DWORD PTR [rbx+0x30],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a89:
	/* 0xa89: mov    DWORD PTR [rbx+0x34],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 223338299393ULL);
x86_l_a90:
	/* 0xa90: mov    QWORD PTR [rbx+0x3c],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_a94:
	/* 0xa94: mov    DWORD PTR [rbx+0x38],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_a98:
	/* 0xa98: movzx  edx,WORD PTR [r12+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_a9e:
	/* 0xa9e: mov    rsi,QWORD PTR [rip+0x7bb7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_call_policy)));
x86_l_aa5:
	/* 0xaa5: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_aaa:
	/* 0xaaa: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_aad:
	/* 0xaad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aaf:
	/* 0xaaf: mov    eax,0xffffff35 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967093ULL);
x86_l_ab4:
	/* 0xab4: jmp    abb <tail_handle_inter_cluster_revsnat+0xabb> */
	X86_SIM_X86_JMP(0xab4, 0xabb, x86_l_abb);
x86_l_ab6:
	/* 0xab6: mov    eax,0xffffff67 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967143ULL);
x86_l_abb:
	/* 0xabb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_abd:
	/* 0xabd: js     ac8 <tail_handle_inter_cluster_revsnat+0xac8> */
	X86_SIM_X86_JCC(X86_CC_S, 0xabd, 0xac8, x86_l_ac8);
x86_l_abf:
	/* 0xabf: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_ac2:
	/* 0xac2: jne    b67 <tail_handle_inter_cluster_revsnat+0xb67> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xac2, 0xb67, x86_l_b67);
x86_l_ac8:
	/* 0xac8: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_aca:
	/* 0xaca: neg    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_acc:
	/* 0xacc: cmovs  ecx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RAX, X86_WIDTH_32, X86_CC_S);
x86_l_acf:
	/* 0xacf: mov    DWORD PTR [rbx+0x30],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ad2:
	/* 0xad2: mov    DWORD PTR [rbx+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_ad9:
	/* 0xad9: movzx  eax,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_adc:
	/* 0xadc: mov    DWORD PTR [rbx+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_adf:
	/* 0xadf: movabs rcx,0xf9030200000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 70090576325771264ULL);
x86_l_ae9:
	/* 0xae9: mov    QWORD PTR [rbx+0x3c],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_aed:
	/* 0xaed: mov    r14d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_af0:
	/* 0xaf0: movabs rcx,0x300f90100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 12901220608ULL);
x86_l_afa:
	/* 0xafa: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_aff:
	/* 0xaff: mov    BYTE PTR [rsp+0x8],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b03:
	/* 0xb03: mov    rdi,QWORD PTR [rip+0x7bb7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_b0a:
	/* 0xb0a: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b0f:
	/* 0xb0f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b14:
	/* 0xb14: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b16:
	/* 0xb16: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b19:
	/* 0xb19: je     b24 <tail_handle_inter_cluster_revsnat+0xb24> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb19, 0xb24, x86_l_b24);
x86_l_b1b:
	/* 0xb1b: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_b1e:
	/* 0xb1e: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_b22:
	/* 0xb22: jmp    b4c <tail_handle_inter_cluster_revsnat+0xb4c> */
	X86_SIM_X86_JMP(0xb22, 0xb4c, x86_l_b4c);
x86_l_b24:
	/* 0xb24: mov    QWORD PTR [rsp+0x68],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598785ULL);
x86_l_b2d:
	/* 0xb2d: mov    QWORD PTR [rsp+0x70],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_b32:
	/* 0xb32: mov    rdi,QWORD PTR [rip+0x7bb7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_b39:
	/* 0xb39: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b3e:
	/* 0xb3e: lea    rdx,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_b43:
	/* 0xb43: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_b48:
	/* 0xb48: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b4a:
	/* 0xb4a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b4c:
	/* 0xb4c: mov    rsi,QWORD PTR [rip+0x7bb7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_b53:
	/* 0xb53: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_b58:
	/* 0xb58: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_b5b:
	/* 0xb5b: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_b60:
	/* 0xb60: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b62:
	/* 0xb62: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_b67:
	/* 0xb67: add    rsp,0x98 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 152ULL);
x86_l_b6e:
	/* 0xb6e: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_b70:
	/* 0xb70: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_b71:
	/* 0xb71: jmp    1409 <tail_handle_inter_cluster_revsnat+0x1409> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_b76:
	/* 0xb76: mov    r12d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 60ULL);
x86_l_b7c:
	/* 0xb7c: cmp    r15w,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_16, 6ULL);
x86_l_b81:
	/* 0xb81: jne    bba <tail_handle_inter_cluster_revsnat+0xbba> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb81, 0xbba, x86_l_bba);
x86_l_b83:
	/* 0xb83: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b86:
	/* 0xb86: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_b88:
	/* 0xb88: shr    ecx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_b8b:
	/* 0xb8b: and    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_b8e:
	/* 0xb8e: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_b90:
	/* 0xb90: mov    WORD PTR [r8+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R8, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_b95:
	/* 0xb95: test   al,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 16ULL);
x86_l_b97:
	/* 0xb97: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_b9c:
	/* 0xb9c: mov    r12d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 21600ULL);
x86_l_ba2:
	/* 0xba2: cmove  r12d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_ba6:
	/* 0xba6: cmp    BYTE PTR [rdx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ba9:
	/* 0xba9: je     bba <tail_handle_inter_cluster_revsnat+0xbba> */
	X86_SIM_X86_JCC(X86_CC_E, 0xba9, 0xbba, x86_l_bba);
x86_l_bab:
	/* 0xbab: mov    rax,QWORD PTR [rip+0x7bba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_bb2:
	/* 0xbb2: imul   r12d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_bb6:
	/* 0xbb6: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_bba:
	/* 0xbba: mov    DWORD PTR [rsp+0x18],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_bbf:
	/* 0xbbf: mov    r15,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R8, X86_WIDTH_64);
x86_l_bc2:
	/* 0xbc2: mov    r14d,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bc6:
	/* 0xbc6: shr    r14d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_bca:
	/* 0xbca: cmp    BYTE PTR [rdx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bcd:
	/* 0xbcd: je     bde <tail_handle_inter_cluster_revsnat+0xbde> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbcd, 0xbde, x86_l_bde);
x86_l_bcf:
	/* 0xbcf: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_bd4:
	/* 0xbd4: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bd6:
	/* 0xbd6: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_bd8:
	/* 0xbd8: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_bdc:
	/* 0xbdc: jmp    c01 <tail_handle_inter_cluster_revsnat+0xc01> */
	X86_SIM_X86_JMP(0xbdc, 0xc01, x86_l_c01);
x86_l_bde:
	/* 0xbde: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_be3:
	/* 0xbe3: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_be5:
	/* 0xbe5: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_be7:
	/* 0xbe7: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_beb:
	/* 0xbeb: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_bf5:
	/* 0xbf5: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_bf8:
	/* 0xbf8: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_bfd:
	/* 0xbfd: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_c01:
	/* 0xc01: add    r12d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_c04:
	/* 0xc04: mov    r8,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R15, X86_WIDTH_64);
x86_l_c07:
	/* 0xc07: mov    DWORD PTR [r15+0x20],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c0b:
	/* 0xc0b: movzx  ecx,BYTE PTR [r15+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_c10:
	/* 0xc10: mov    edx,DWORD PTR [r15+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_c14:
	/* 0xc14: and    r14b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_c18:
	/* 0xc18: mov    rsi,QWORD PTR [rip+0x7bba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_c1f:
	/* 0xc1f: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c22:
	/* 0xc22: mov    r9,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c27:
	/* 0xc27: je     c3a <tail_handle_inter_cluster_revsnat+0xc3a> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc27, 0xc3a, x86_l_c3a);
x86_l_c29:
	/* 0xc29: mov    rsi,QWORD PTR [rip+0x7bba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_c30:
	/* 0xc30: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c32:
	/* 0xc32: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_c35:
	/* 0xc35: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_c38:
	/* 0xc38: jmp    c3f <tail_handle_inter_cluster_revsnat+0xc3f> */
	X86_SIM_X86_JMP(0xc38, 0xc3f, x86_l_c3f);
x86_l_c3a:
	/* 0xc3a: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_c3f:
	/* 0xc3f: mov    r15d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c44:
	/* 0xc44: mov    r12d,DWORD PTR [rsp+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_c49:
	/* 0xc49: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_c4b:
	/* 0xc4b: or     r14b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_c4e:
	/* 0xc4e: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_c50:
	/* 0xc50: jb     c57 <tail_handle_inter_cluster_revsnat+0xc57> */
	X86_SIM_X86_JCC(X86_CC_B, 0xc50, 0xc57, x86_l_c57);
x86_l_c52:
	/* 0xc52: cmp    cl,r14b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R14, X86_WIDTH_8);
x86_l_c55:
	/* 0xc55: je     c68 <tail_handle_inter_cluster_revsnat+0xc68> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc55, 0xc68, x86_l_c68);
x86_l_c57:
	/* 0xc57: mov    BYTE PTR [r8+0x2b],r14b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R8, X86_R14, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_c5b:
	/* 0xc5b: mov    DWORD PTR [r8+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R8, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_c5f:
	/* 0xc5f: mov    rax,QWORD PTR [rip+0x7bba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_c66:
	/* 0xc66: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c68:
	/* 0xc68: mov    rax,QWORD PTR [rip+0x7bba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_c6f:
	/* 0xc6f: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c72:
	/* 0xc72: je     c80 <tail_handle_inter_cluster_revsnat+0xc80> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc72, 0xc80, x86_l_c80);
x86_l_c74:
	/* 0xc74: inc QWORD PTR [r8+0x10] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R8, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 16ULL);
x86_l_c79:
	/* 0xc79: mov    eax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c7b:
	/* 0xc7b: add QWORD PTR [r8+0x18],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R8, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_c80:
	/* 0xc80: cmp    r12d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 2ULL);
x86_l_c84:
	/* 0xc84: je     cd8 <tail_handle_inter_cluster_revsnat+0xcd8> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc84, 0xcd8, x86_l_cd8);
x86_l_c86:
	/* 0xc86: cmp    r12d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 1ULL);
x86_l_c8a:
	/* 0xc8a: jne    dca <tail_handle_inter_cluster_revsnat+0xdca> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xc8a, 0xdca, x86_l_dca);
x86_l_c90:
	/* 0xc90: movzx  eax,WORD PTR [r8+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R8, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_c95:
	/* 0xc95: test   al,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 3ULL);
x86_l_c97:
	/* 0xc97: je     dca <tail_handle_inter_cluster_revsnat+0xdca> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc97, 0xdca, x86_l_dca);
x86_l_c9d:
	/* 0xc9d: mov    WORD PTR [r8+0x2a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 180388626432ULL);
x86_l_ca4:
	/* 0xca4: and    eax,0xffec */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 65516ULL);
x86_l_ca9:
	/* 0xca9: mov    QWORD PTR [rsp+0x18],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_cae:
	/* 0xcae: mov    WORD PTR [r8+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R8, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_cb3:
	/* 0xcb3: mov    r14,QWORD PTR [rip+0x7bba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_cba:
	/* 0xcba: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cbe:
	/* 0xcbe: je     131c <tail_handle_inter_cluster_revsnat+0x131c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xcbe, 0x131c, x86_l_131c);
x86_l_cc4:
	/* 0xcc4: mov    rcx,QWORD PTR [rip+0x7bba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_ccb:
	/* 0xccb: imul   r12d,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_ccf:
	/* 0xccf: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_cd3:
	/* 0xcd3: jmp    1322 <tail_handle_inter_cluster_revsnat+0x1322> */
	X86_SIM_X86_JMP(0xcd3, 0x1322, x86_l_1322);
x86_l_cd8:
	/* 0xcd8: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cdb:
	/* 0xcdb: shr    eax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_cde:
	/* 0xcde: and    eax,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2ULL);
x86_l_ce1:
	/* 0xce1: or     ax,WORD PTR [r8+0x24] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R8, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 36ULL);
x86_l_ce6:
	/* 0xce6: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_ce8:
	/* 0xce8: or     ecx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_OR, 1ULL);
x86_l_ceb:
	/* 0xceb: mov    WORD PTR [r8+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R8, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_cf0:
	/* 0xcf0: mov    rcx,QWORD PTR [rip+0x7bba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_cf7:
	/* 0xcf7: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cf9:
	/* 0xcf9: test   al,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 2ULL);
x86_l_cfb:
	/* 0xcfb: je     dca <tail_handle_inter_cluster_revsnat+0xdca> */
	X86_SIM_X86_JCC(X86_CC_E, 0xcfb, 0xdca, x86_l_dca);
x86_l_d01:
	/* 0xd01: mov    r14,QWORD PTR [rip+0x7bba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_d08:
	/* 0xd08: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d0c:
	/* 0xd0c: je     d23 <tail_handle_inter_cluster_revsnat+0xd23> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd0c, 0xd23, x86_l_d23);
x86_l_d0e:
	/* 0xd0e: mov    rax,QWORD PTR [rip+0x7bba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_d15:
	/* 0xd15: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d17:
	/* 0xd17: add    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_d19:
	/* 0xd19: lea    r12d,[rax+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_d1d:
	/* 0xd1d: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_d21:
	/* 0xd21: jmp    d29 <tail_handle_inter_cluster_revsnat+0xd29> */
	X86_SIM_X86_JMP(0xd21, 0xd29, x86_l_d29);
x86_l_d23:
	/* 0xd23: mov    r12d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 10ULL);
x86_l_d29:
	/* 0xd29: mov    r15,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R8, X86_WIDTH_64);
x86_l_d2c:
	/* 0xd2c: shr    DWORD PTR [rsp],0x8 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_32, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_SHR)), 8ULL);
x86_l_d30:
	/* 0xd30: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d34:
	/* 0xd34: je     d45 <tail_handle_inter_cluster_revsnat+0xd45> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd34, 0xd45, x86_l_d45);
x86_l_d36:
	/* 0xd36: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_d3b:
	/* 0xd3b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d3d:
	/* 0xd3d: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_d3f:
	/* 0xd3f: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_d43:
	/* 0xd43: jmp    d68 <tail_handle_inter_cluster_revsnat+0xd68> */
	X86_SIM_X86_JMP(0xd43, 0xd68, x86_l_d68);
x86_l_d45:
	/* 0xd45: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_d4a:
	/* 0xd4a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d4c:
	/* 0xd4c: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_d4e:
	/* 0xd4e: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_d52:
	/* 0xd52: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_d5c:
	/* 0xd5c: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_d5f:
	/* 0xd5f: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_d64:
	/* 0xd64: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_d68:
	/* 0xd68: add    r12d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_d6b:
	/* 0xd6b: mov    DWORD PTR [r15+0x20],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d6f:
	/* 0xd6f: movzx  ecx,BYTE PTR [r15+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_d74:
	/* 0xd74: mov    edx,DWORD PTR [r15+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_d78:
	/* 0xd78: mov    esi,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d7b:
	/* 0xd7b: and    sil,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_d7f:
	/* 0xd7f: mov    DWORD PTR [rsp],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d82:
	/* 0xd82: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d86:
	/* 0xd86: mov    r9,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d8b:
	/* 0xd8b: je     d9e <tail_handle_inter_cluster_revsnat+0xd9e> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd8b, 0xd9e, x86_l_d9e);
x86_l_d8d:
	/* 0xd8d: mov    rsi,QWORD PTR [rip+0x7bba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_d94:
	/* 0xd94: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d96:
	/* 0xd96: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_d99:
	/* 0xd99: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_d9c:
	/* 0xd9c: jmp    da3 <tail_handle_inter_cluster_revsnat+0xda3> */
	X86_SIM_X86_JMP(0xd9c, 0xda3, x86_l_da3);
x86_l_d9e:
	/* 0xd9e: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_da3:
	/* 0xda3: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_da5:
	/* 0xda5: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_da8:
	/* 0xda8: or     dl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_daa:
	/* 0xdaa: mov    DWORD PTR [rsp],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_dad:
	/* 0xdad: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_daf:
	/* 0xdaf: jb     db6 <tail_handle_inter_cluster_revsnat+0xdb6> */
	X86_SIM_X86_JCC(X86_CC_B, 0xdaf, 0xdb6, x86_l_db6);
x86_l_db1:
	/* 0xdb1: cmp    cl,BYTE PTR [rsp] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_db4:
	/* 0xdb4: je     dca <tail_handle_inter_cluster_revsnat+0xdca> */
	X86_SIM_X86_JCC(X86_CC_E, 0xdb4, 0xdca, x86_l_dca);
x86_l_db6:
	/* 0xdb6: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_db9:
	/* 0xdb9: mov    BYTE PTR [r15+0x2b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_dbd:
	/* 0xdbd: mov    DWORD PTR [r15+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_dc1:
	/* 0xdc1: mov    rax,QWORD PTR [rip+0x7bba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_dc8:
	/* 0xdc8: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_dca:
	/* 0xdca: movzx  r12d,WORD PTR [r13+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_dcf:
	/* 0xdcf: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_dd1:
	/* 0xdd1: movzx  r14d,BYTE PTR [rsp+0x3c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 60ULL);
x86_l_dd7:
	/* 0xdd7: mov    ecx,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ddb:
	/* 0xddb: mov    r15d,DWORD PTR [r13+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ddf:
	/* 0xddf: movzx  esi,WORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 56ULL);
x86_l_de4:
	/* 0xde4: mov    DWORD PTR [rsp+0x68],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_de9:
	/* 0xde9: cmp    ecx,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R15, X86_WIDTH_32);
x86_l_dec:
	/* 0xdec: jne    dfe <tail_handle_inter_cluster_revsnat+0xdfe> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xdec, 0xdfe, x86_l_dfe);
x86_l_dee:
	/* 0xdee: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_df0:
	/* 0xdf0: jne    dfe <tail_handle_inter_cluster_revsnat+0xdfe> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xdf0, 0xdfe, x86_l_dfe);
x86_l_df2:
	/* 0xdf2: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_df4:
	/* 0xdf4: cmp    si,r12w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_R12, X86_WIDTH_16);
x86_l_df8:
	/* 0xdf8: je     7dc <tail_handle_inter_cluster_revsnat+0x7dc> */
	X86_SIM_X86_JCC(X86_CC_E, 0xdf8, 0x7dc, x86_l_7dc);
x86_l_dfe:
	/* 0xdfe: mov    DWORD PTR [rsp+0x18],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_e02:
	/* 0xe02: mov    DWORD PTR [rsp],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e05:
	/* 0xe05: mov    r13,r9 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R9, X86_WIDTH_64);
x86_l_e08:
	/* 0xe08: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_e0a:
	/* 0xe0a: add    r15d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_e0d:
	/* 0xe0d: adc    r15d,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_e11:
	/* 0xe11: lea    rdx,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_e16:
	/* 0xe16: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_e1b:
	/* 0xe1b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_e1e:
	/* 0xe1e: mov    esi,0x1e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 30ULL);
x86_l_e23:
	/* 0xe23: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_e28:
	/* 0xe28: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e2b:
	/* 0xe2b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e2d:
	/* 0xe2d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_e2f:
	/* 0xe2f: js     fae <tail_handle_inter_cluster_revsnat+0xfae> */
	X86_SIM_X86_JCC(X86_CC_S, 0xe2f, 0xfae, x86_l_fae);
x86_l_e35:
	/* 0xe35: mov    eax,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_e3a:
	/* 0xe3a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_e3d:
	/* 0xe3d: mov    esi,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 24ULL);
x86_l_e42:
	/* 0xe42: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e44:
	/* 0xe44: mov    ecx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_32);
x86_l_e47:
	/* 0xe47: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e4a:
	/* 0xe4a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e4c:
	/* 0xe4c: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_e4e:
	/* 0xe4e: sar    eax,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SAR, 31ULL);
x86_l_e51:
	/* 0xe51: and    eax,0xffffff67 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967143ULL);
x86_l_e56:
	/* 0xe56: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_e58:
	/* 0xe58: js     7dc <tail_handle_inter_cluster_revsnat+0x7dc> */
	X86_SIM_X86_JCC(X86_CC_S, 0xe58, 0x7dc, x86_l_7dc);
x86_l_e5e:
	/* 0xe5e: movabs rcx,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2199023255552ULL);
x86_l_e68:
	/* 0xe68: and    r13,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_64, X86_ALU_AND);
x86_l_e6b:
	/* 0xe6b: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e6e:
	/* 0xe6e: mov    edx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_e72:
	/* 0xe72: jne    7dc <tail_handle_inter_cluster_revsnat+0x7dc> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe72, 0x7dc, x86_l_7dc);
x86_l_e78:
	/* 0xe78: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e7b:
	/* 0xe7b: cmp    r14d,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 58ULL);
x86_l_e7f:
	/* 0xe7f: je     ea6 <tail_handle_inter_cluster_revsnat+0xea6> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe7f, 0xea6, x86_l_ea6);
x86_l_e81:
	/* 0xe81: cmp    r14d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 17ULL);
x86_l_e85:
	/* 0xe85: mov    r9,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_e8a:
	/* 0xe8a: je     e99 <tail_handle_inter_cluster_revsnat+0xe99> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe8a, 0xe99, x86_l_e99);
x86_l_e8c:
	/* 0xe8c: cmp    r14d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 6ULL);
x86_l_e90:
	/* 0xe90: jne    eb2 <tail_handle_inter_cluster_revsnat+0xeb2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe90, 0xeb2, x86_l_eb2);
x86_l_e92:
	/* 0xe92: mov    r13w,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_16, 16ULL);
x86_l_e97:
	/* 0xe97: jmp    eb5 <tail_handle_inter_cluster_revsnat+0xeb5> */
	X86_SIM_X86_JMP(0xe97, 0xeb5, x86_l_eb5);
x86_l_e99:
	/* 0xe99: mov    r8d,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 32ULL);
x86_l_e9f:
	/* 0xe9f: mov    r13w,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_16, 6ULL);
x86_l_ea4:
	/* 0xea4: jmp    eb5 <tail_handle_inter_cluster_revsnat+0xeb5> */
	X86_SIM_X86_JMP(0xea4, 0xeb5, x86_l_eb5);
x86_l_ea6:
	/* 0xea6: mov    r13w,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_16, 2ULL);
x86_l_eab:
	/* 0xeab: mov    r9,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_eb0:
	/* 0xeb0: jmp    eb5 <tail_handle_inter_cluster_revsnat+0xeb5> */
	X86_SIM_X86_JMP(0xeb0, 0xeb5, x86_l_eb5);
x86_l_eb2:
	/* 0xeb2: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_eb5:
	/* 0xeb5: cmp    dx,r12w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_R12, X86_WIDTH_16);
x86_l_eb9:
	/* 0xeb9: jne    ee5 <tail_handle_inter_cluster_revsnat+0xee5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xeb9, 0xee5, x86_l_ee5);
x86_l_ebb:
	/* 0xebb: test   r13w,r13w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_16);
x86_l_ebf:
	/* 0xebf: je     f73 <tail_handle_inter_cluster_revsnat+0xf73> */
	X86_SIM_X86_JCC(X86_CC_E, 0xebf, 0xf73, x86_l_f73);
x86_l_ec5:
	/* 0xec5: movzx  eax,r13w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_R13, X86_WIDTH_32, X86_WIDTH_16);
x86_l_ec9:
	/* 0xec9: add    r9d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_ecc:
	/* 0xecc: or     r8d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 16ULL);
x86_l_ed0:
	/* 0xed0: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_ed5:
	/* 0xed5: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_ed8:
	/* 0xed8: mov    esi,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R9, X86_WIDTH_32);
x86_l_edb:
	/* 0xedb: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_edd:
	/* 0xedd: mov    ecx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_32);
x86_l_ee0:
	/* 0xee0: jmp    f88 <tail_handle_inter_cluster_revsnat+0xf88> */
	X86_SIM_X86_JMP(0xee0, 0xf88, x86_l_f88);
x86_l_ee5:
	/* 0xee5: cmp    r14d,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 17ULL);
x86_l_ee9:
	/* 0xee9: je     f05 <tail_handle_inter_cluster_revsnat+0xf05> */
	X86_SIM_X86_JCC(X86_CC_E, 0xee9, 0xf05, x86_l_f05);
x86_l_eeb:
	/* 0xeeb: cmp    r14d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 6ULL);
x86_l_eef:
	/* 0xeef: je     f05 <tail_handle_inter_cluster_revsnat+0xf05> */
	X86_SIM_X86_JCC(X86_CC_E, 0xeef, 0xf05, x86_l_f05);
x86_l_ef1:
	/* 0xef1: mov    eax,0xffffff72 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967154ULL);
x86_l_ef6:
	/* 0xef6: cmp    r14d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1ULL);
x86_l_efa:
	/* 0xefa: jne    7dc <tail_handle_inter_cluster_revsnat+0x7dc> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xefa, 0x7dc, x86_l_7dc);
x86_l_f00:
	/* 0xf00: mov    r13w,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_16, 2ULL);
x86_l_f05:
	/* 0xf05: mov    DWORD PTR [rsp+0x20],r8d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f0a:
	/* 0xf0a: mov    WORD PTR [rsp+0x8],r12w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f10:
	/* 0xf10: mov    esi,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_f14:
	/* 0xf14: add    esi,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R9, X86_WIDTH_32, X86_ALU_ADD);
x86_l_f17:
	/* 0xf17: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f1c:
	/* 0xf1c: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_f21:
	/* 0xf21: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_f24:
	/* 0xf24: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_f29:
	/* 0xf29: mov    r12,r9 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R9, X86_WIDTH_64);
x86_l_f2c:
	/* 0xf2c: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f2f:
	/* 0xf2f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f31:
	/* 0xf31: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_f33:
	/* 0xf33: js     fae <tail_handle_inter_cluster_revsnat+0xfae> */
	X86_SIM_X86_JCC(X86_CC_S, 0xf33, 0xfae, x86_l_fae);
x86_l_f35:
	/* 0xf35: movzx  ecx,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_f3a:
	/* 0xf3a: movzx  esi,r13w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RSI, X86_R13, X86_WIDTH_32, X86_WIDTH_16);
x86_l_f3e:
	/* 0xf3e: add    esi,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R12, X86_WIDTH_32, X86_ALU_ADD);
x86_l_f41:
	/* 0xf41: mov    r8d,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f46:
	/* 0xf46: or     r8d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_f4a:
	/* 0xf4a: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_f4f:
	/* 0xf4f: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_f52:
	/* 0xf52: mov    edx,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_f56:
	/* 0xf56: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f58:
	/* 0xf58: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_f5a:
	/* 0xf5a: js     f96 <tail_handle_inter_cluster_revsnat+0xf96> */
	X86_SIM_X86_JCC(X86_CC_S, 0xf5a, 0xf96, x86_l_f96);
x86_l_f5c:
	/* 0xf5c: cmp    r14d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_32, 1ULL);
x86_l_f60:
	/* 0xf60: mov    r9,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_f65:
	/* 0xf65: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f68:
	/* 0xf68: mov    r8d,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f6d:
	/* 0xf6d: jne    ebb <tail_handle_inter_cluster_revsnat+0xebb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf6d, 0xebb, x86_l_ebb);
x86_l_f73:
	/* 0xf73: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_f75:
	/* 0xf75: je     fc6 <tail_handle_inter_cluster_revsnat+0xfc6> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf75, 0xfc6, x86_l_fc6);
x86_l_f77:
	/* 0xf77: add    r9d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_f7b:
	/* 0xf7b: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_f80:
	/* 0xf80: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_f83:
	/* 0xf83: mov    esi,r9d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R9, X86_WIDTH_32);
x86_l_f86:
	/* 0xf86: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f88:
	/* 0xf88: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f8a:
	/* 0xf8a: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_f8c:
	/* 0xf8c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f8e:
	/* 0xf8e: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_f90:
	/* 0xf90: jns    7dc <tail_handle_inter_cluster_revsnat+0x7dc> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xf90, 0x7dc, x86_l_7dc);
x86_l_f96:
	/* 0xf96: mov    eax,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967142ULL);
x86_l_f9b:
	/* 0xf9b: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f9e:
	/* 0xf9e: cmp    eax,0xffffff53 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967123ULL);
x86_l_fa3:
	/* 0xfa3: jne    7e6 <tail_handle_inter_cluster_revsnat+0x7e6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xfa3, 0x7e6, x86_l_7e6);
x86_l_fa9:
	/* 0xfa9: jmp    7fa <tail_handle_inter_cluster_revsnat+0x7fa> */
	X86_SIM_X86_JMP(0xfa9, 0x7fa, x86_l_7fa);
x86_l_fae:
	/* 0xfae: mov    eax,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967155ULL);
x86_l_fb3:
	/* 0xfb3: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_fb6:
	/* 0xfb6: cmp    eax,0xffffff53 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967123ULL);
x86_l_fbb:
	/* 0xfbb: jne    7e6 <tail_handle_inter_cluster_revsnat+0x7e6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xfbb, 0x7e6, x86_l_7e6);
x86_l_fc1:
	/* 0xfc1: jmp    7fa <tail_handle_inter_cluster_revsnat+0x7fa> */
	X86_SIM_X86_JMP(0xfc1, 0x7fa, x86_l_7fa);
x86_l_fc6:
	/* 0xfc6: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_fc8:
	/* 0xfc8: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_fcb:
	/* 0xfcb: cmp    eax,0xffffff53 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967123ULL);
x86_l_fd0:
	/* 0xfd0: jne    7e6 <tail_handle_inter_cluster_revsnat+0x7e6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xfd0, 0x7e6, x86_l_7e6);
x86_l_fd6:
	/* 0xfd6: jmp    7fa <tail_handle_inter_cluster_revsnat+0x7fa> */
	X86_SIM_X86_JMP(0xfd6, 0x7fa, x86_l_7fa);
x86_l_fdb:
	/* 0xfdb: mov    WORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_fe2:
	/* 0xfe2: mov    rax,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_fe7:
	/* 0xfe7: lea    esi,[rax+0x6] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_fea:
	/* 0xfea: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_fef:
	/* 0xfef: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_ff4:
	/* 0xff4: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_ff7:
	/* 0xff7: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_ffc:
	/* 0xffc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ffe:
	/* 0xffe: mov    r8,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1003:
	/* 0x1003: cmp    WORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1009:
	/* 0x1009: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_100b:
	/* 0x100b: setne  dl */
	X86_SIM_L_EXEC_SETCC(X86_RDX, X86_CC_NE);
x86_l_100e:
	/* 0x100e: mov    sil,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_8, 1ULL);
x86_l_1011:
	/* 0x1011: mov    eax,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967162ULL);
x86_l_1016:
	/* 0x1016: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1018:
	/* 0x1018: jns    1022 <tail_handle_inter_cluster_revsnat+0x1022> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1018, 0x1022, x86_l_1022);
x86_l_101a:
	/* 0x101a: jmp    7d7 <tail_handle_inter_cluster_revsnat+0x7d7> */
	X86_SIM_X86_JMP(0x101a, 0x7d7, x86_l_7d7);
x86_l_101f:
	/* 0x101f: mov    sil,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_8, 1ULL);
x86_l_1022:
	/* 0x1022: mov    eax,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1026:
	/* 0x1026: mov    r12d,DWORD PTR [r13+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_102a:
	/* 0x102a: movzx  edi,WORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_102f:
	/* 0x102f: movzx  r14d,WORD PTR [r13+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_1034:
	/* 0x1034: test   sil,sil */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_8);
x86_l_1037:
	/* 0x1037: je     104d <tail_handle_inter_cluster_revsnat+0x104d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1037, 0x104d, x86_l_104d);
x86_l_1039:
	/* 0x1039: test   dl,dl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_8);
x86_l_103b:
	/* 0x103b: je     104d <tail_handle_inter_cluster_revsnat+0x104d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x103b, 0x104d, x86_l_104d);
x86_l_103d:
	/* 0x103d: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_103f:
	/* 0x103f: cmp    eax,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_1042:
	/* 0x1042: je     1062 <tail_handle_inter_cluster_revsnat+0x1062> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1042, 0x1062, x86_l_1062);
x86_l_1044:
	/* 0x1044: mov    edx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_32);
x86_l_1047:
	/* 0x1047: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_1049:
	/* 0x1049: add    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_104b:
	/* 0x104b: jmp    105f <tail_handle_inter_cluster_revsnat+0x105f> */
	X86_SIM_X86_JMP(0x104b, 0x105f, x86_l_105f);
x86_l_104d:
	/* 0x104d: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_104f:
	/* 0x104f: cmp    di,r14w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_R14, X86_WIDTH_16);
x86_l_1053:
	/* 0x1053: je     1062 <tail_handle_inter_cluster_revsnat+0x1062> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1053, 0x1062, x86_l_1062);
x86_l_1055:
	/* 0x1055: movzx  ecx,r14w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R14, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1059:
	/* 0x1059: mov    edx,edi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_32);
x86_l_105b:
	/* 0x105b: not    edx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_105d:
	/* 0x105d: add    edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_105f:
	/* 0x105f: adc    edx,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_1062:
	/* 0x1062: movzx  ecx,BYTE PTR [rsp+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 20ULL);
x86_l_1067:
	/* 0x1067: mov    DWORD PTR [rsp+0x28],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_106c:
	/* 0x106c: cmp    eax,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_106f:
	/* 0x106f: jne    1091 <tail_handle_inter_cluster_revsnat+0x1091> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x106f, 0x1091, x86_l_1091);
x86_l_1071:
	/* 0x1071: cmp    di,r14w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_R14, X86_WIDTH_16);
x86_l_1075:
	/* 0x1075: jne    1091 <tail_handle_inter_cluster_revsnat+0x1091> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1075, 0x1091, x86_l_1091);
x86_l_1077:
	/* 0x1077: mov    DWORD PTR [rsp+0x60],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_107c:
	/* 0x107c: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_107f:
	/* 0x107f: mov    DWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_1087:
	/* 0x1087: mov    r9,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_108c:
	/* 0x108c: jmp    dd1 <tail_handle_inter_cluster_revsnat+0xdd1> */
	X86_SIM_X86_JMP(0x108c, 0xdd1, x86_l_dd1);
x86_l_1091:
	/* 0x1091: mov    DWORD PTR [rsp+0x94],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_1098:
	/* 0x1098: mov    DWORD PTR [rsp+0x44],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_109c:
	/* 0x109c: mov    BYTE PTR [rsp+0x17],sil */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 23ULL);
x86_l_10a1:
	/* 0x10a1: mov    DWORD PTR [rsp],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10a4:
	/* 0x10a4: mov    QWORD PTR [rsp+0x18],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_10a9:
	/* 0x10a9: mov    r13d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBP, X86_WIDTH_32);
x86_l_10ac:
	/* 0x10ac: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_10ae:
	/* 0x10ae: add    r12d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_10b1:
	/* 0x10b1: adc    r12d,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_ADC, 0ULL);
x86_l_10b5:
	/* 0x10b5: lea    esi,[r8+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_10b9:
	/* 0x10b9: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_10be:
	/* 0x10be: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_10c3:
	/* 0x10c3: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_10c6:
	/* 0x10c6: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_10cb:
	/* 0x10cb: mov    rbp,r8 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R8, X86_WIDTH_64);
x86_l_10ce:
	/* 0x10ce: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10d1:
	/* 0x10d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10d3:
	/* 0x10d3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_10d5:
	/* 0x10d5: js     113a <tail_handle_inter_cluster_revsnat+0x113a> */
	X86_SIM_X86_JCC(X86_CC_S, 0x10d5, 0x113a, x86_l_113a);
x86_l_10d7:
	/* 0x10d7: lea    esi,[rbp+0x12] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_10da:
	/* 0x10da: mov    eax,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_10df:
	/* 0x10df: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_10e2:
	/* 0x10e2: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10e4:
	/* 0x10e4: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_10e7:
	/* 0x10e7: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10ea:
	/* 0x10ea: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10ec:
	/* 0x10ec: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_10ee:
	/* 0x10ee: js     1147 <tail_handle_inter_cluster_revsnat+0x1147> */
	X86_SIM_X86_JCC(X86_CC_S, 0x10ee, 0x1147, x86_l_1147);
x86_l_10f0:
	/* 0x10f0: mov    DWORD PTR [rsp+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_10fb:
	/* 0x10fb: mov    ecx,DWORD PTR [rsp+0x94] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_1102:
	/* 0x1102: cmp    ecx,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 58ULL);
x86_l_1105:
	/* 0x1105: mov    ebp,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R13, X86_WIDTH_32);
x86_l_1108:
	/* 0x1108: je     1165 <tail_handle_inter_cluster_revsnat+0x1165> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1108, 0x1165, x86_l_1165);
x86_l_110a:
	/* 0x110a: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_110d:
	/* 0x110d: mov    r13,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1112:
	/* 0x1112: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1115:
	/* 0x1115: mov    eax,DWORD PTR [rsp+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_1119:
	/* 0x1119: je     1154 <tail_handle_inter_cluster_revsnat+0x1154> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1119, 0x1154, x86_l_1154);
x86_l_111b:
	/* 0x111b: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_111e:
	/* 0x111e: jne    1177 <tail_handle_inter_cluster_revsnat+0x1177> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x111e, 0x1177, x86_l_1177);
x86_l_1120:
	/* 0x1120: mov    si,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_16, 16ULL);
x86_l_1124:
	/* 0x1124: jmp    1179 <tail_handle_inter_cluster_revsnat+0x1179> */
	X86_SIM_X86_JMP(0x1124, 0x1179, x86_l_1179);
x86_l_1126:
	/* 0x1126: mov    eax,0xffffff53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967123ULL);
x86_l_112b:
	/* 0x112b: jmp    7d7 <tail_handle_inter_cluster_revsnat+0x7d7> */
	X86_SIM_X86_JMP(0x112b, 0x7d7, x86_l_7d7);
x86_l_1130:
	/* 0x1130: mov    eax,0xffffff71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967153ULL);
x86_l_1135:
	/* 0x1135: jmp    7d7 <tail_handle_inter_cluster_revsnat+0x7d7> */
	X86_SIM_X86_JMP(0x1135, 0x7d7, x86_l_7d7);
x86_l_113a:
	/* 0x113a: mov    eax,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967155ULL);
x86_l_113f:
	/* 0x113f: mov    ebp,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R13, X86_WIDTH_32);
x86_l_1142:
	/* 0x1142: jmp    7d7 <tail_handle_inter_cluster_revsnat+0x7d7> */
	X86_SIM_X86_JMP(0x1142, 0x7d7, x86_l_7d7);
x86_l_1147:
	/* 0x1147: mov    eax,0xffffff67 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967143ULL);
x86_l_114c:
	/* 0x114c: mov    ebp,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R13, X86_WIDTH_32);
x86_l_114f:
	/* 0x114f: jmp    7d7 <tail_handle_inter_cluster_revsnat+0x7d7> */
	X86_SIM_X86_JMP(0x114f, 0x7d7, x86_l_7d7);
x86_l_1154:
	/* 0x1154: mov    DWORD PTR [rsp+0x90],0x20 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 618475290656ULL);
x86_l_115f:
	/* 0x115f: mov    si,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_16, 6ULL);
x86_l_1163:
	/* 0x1163: jmp    1179 <tail_handle_inter_cluster_revsnat+0x1179> */
	X86_SIM_X86_JMP(0x1163, 0x1179, x86_l_1179);
x86_l_1165:
	/* 0x1165: mov    si,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_16, 2ULL);
x86_l_1169:
	/* 0x1169: mov    r13,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_116e:
	/* 0x116e: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1171:
	/* 0x1171: mov    eax,DWORD PTR [rsp+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_1175:
	/* 0x1175: jmp    1179 <tail_handle_inter_cluster_revsnat+0x1179> */
	X86_SIM_X86_JMP(0x1175, 0x1179, x86_l_1179);
x86_l_1177:
	/* 0x1177: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1179:
	/* 0x1179: cmp    ax,r14w */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R14, X86_WIDTH_16);
x86_l_117d:
	/* 0x117d: jne    11c7 <tail_handle_inter_cluster_revsnat+0x11c7> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x117d, 0x11c7, x86_l_11c7);
x86_l_117f:
	/* 0x117f: test   si,si */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_RSI, X86_WIDTH_16);
x86_l_1182:
	/* 0x1182: je     1077 <tail_handle_inter_cluster_revsnat+0x1077> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1182, 0x1077, x86_l_1077);
x86_l_1188:
	/* 0x1188: movzx  eax,si */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RSI, X86_WIDTH_32, X86_WIDTH_16);
x86_l_118b:
	/* 0x118b: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1190:
	/* 0x1190: add    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1192:
	/* 0x1192: mov    r8d,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_119a:
	/* 0x119a: or     r8d,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 16ULL);
x86_l_119e:
	/* 0x119e: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_11a3:
	/* 0x11a3: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_11a6:
	/* 0x11a6: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11a8:
	/* 0x11a8: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_11ab:
	/* 0x11ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11ad:
	/* 0x11ad: movzx  esi,BYTE PTR [rsp+0x17] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 23ULL);
x86_l_11b2:
	/* 0x11b2: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11b5:
	/* 0x11b5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_11b7:
	/* 0x11b7: jns    1077 <tail_handle_inter_cluster_revsnat+0x1077> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x11b7, 0x1077, x86_l_1077);
x86_l_11bd:
	/* 0x11bd: mov    eax,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967142ULL);
x86_l_11c2:
	/* 0x11c2: jmp    12b3 <tail_handle_inter_cluster_revsnat+0x12b3> */
	X86_SIM_X86_JMP(0x11c2, 0x12b3, x86_l_12b3);
x86_l_11c7:
	/* 0x11c7: cmp    ecx,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 17ULL);
x86_l_11ca:
	/* 0x11ca: mov    DWORD PTR [rsp+0x18],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_11ce:
	/* 0x11ce: je     1220 <tail_handle_inter_cluster_revsnat+0x1220> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11ce, 0x1220, x86_l_1220);
x86_l_11d0:
	/* 0x11d0: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_11d3:
	/* 0x11d3: mov    esi,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_11d7:
	/* 0x11d7: je     1224 <tail_handle_inter_cluster_revsnat+0x1224> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11d7, 0x1224, x86_l_1224);
x86_l_11d9:
	/* 0x11d9: mov    eax,0xffffff72 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967154ULL);
x86_l_11de:
	/* 0x11de: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_11e1:
	/* 0x11e1: jne    7d7 <tail_handle_inter_cluster_revsnat+0x7d7> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x11e1, 0x7d7, x86_l_7d7);
x86_l_11e7:
	/* 0x11e7: mov    ax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_16, 2ULL);
x86_l_11eb:
	/* 0x11eb: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_11ef:
	/* 0x11ef: jmp    1224 <tail_handle_inter_cluster_revsnat+0x1224> */
	X86_SIM_X86_JMP(0x11ef, 0x1224, x86_l_1224);
x86_l_11f1:
	/* 0x11f1: mov    rbp,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RSI, X86_WIDTH_64);
x86_l_11f4:
	/* 0x11f4: mov    rdi,QWORD PTR [rip+0x7bba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv4_frag_datagrams)));
x86_l_11fb:
	/* 0x11fb: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1200:
	/* 0x1200: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1205:
	/* 0x1205: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1207:
	/* 0x1207: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_120a:
	/* 0x120a: je     12c9 <tail_handle_inter_cluster_revsnat+0x12c9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x120a, 0x12c9, x86_l_12c9);
x86_l_1210:
	/* 0x1210: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1212:
	/* 0x1212: mov    DWORD PTR [rsp+0x38],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1216:
	/* 0x1216: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_121b:
	/* 0x121b: jmp    274 <tail_handle_inter_cluster_revsnat+0x274> */
	X86_SIM_X86_JMP(0x121b, 0x274, x86_l_274);
x86_l_1220:
	/* 0x1220: mov    esi,DWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1224:
	/* 0x1224: mov    WORD PTR [rsp+0x56],r14w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_122a:
	/* 0x122a: mov    r14,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_122f:
	/* 0x122f: add    esi,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R14, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1232:
	/* 0x1232: lea    rdx,[rsp+0x56] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_1237:
	/* 0x1237: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_123c:
	/* 0x123c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_123f:
	/* 0x123f: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1244:
	/* 0x1244: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1247:
	/* 0x1247: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1249:
	/* 0x1249: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_124b:
	/* 0x124b: js     1292 <tail_handle_inter_cluster_revsnat+0x1292> */
	X86_SIM_X86_JCC(X86_CC_S, 0x124b, 0x1292, x86_l_1292);
x86_l_124d:
	/* 0x124d: movzx  ecx,WORD PTR [rsp+0x56] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 86ULL);
x86_l_1252:
	/* 0x1252: movzx  esi,WORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 24ULL);
x86_l_1257:
	/* 0x1257: add    esi,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R14, X86_WIDTH_32, X86_ALU_ADD);
x86_l_125a:
	/* 0x125a: mov    r8d,DWORD PTR [rsp+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 144ULL);
x86_l_1262:
	/* 0x1262: or     r8d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_OR, 2ULL);
x86_l_1266:
	/* 0x1266: mov    eax,0xb */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 11ULL);
x86_l_126b:
	/* 0x126b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_126e:
	/* 0x126e: mov    edx,DWORD PTR [rsp+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_1272:
	/* 0x1272: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1274:
	/* 0x1274: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1276:
	/* 0x1276: js     12a6 <tail_handle_inter_cluster_revsnat+0x12a6> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1276, 0x12a6, x86_l_12a6);
x86_l_1278:
	/* 0x1278: cmp    DWORD PTR [rsp+0x94],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 635655159809ULL);
x86_l_1280:
	/* 0x1280: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1283:
	/* 0x1283: mov    esi,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1287:
	/* 0x1287: je     1077 <tail_handle_inter_cluster_revsnat+0x1077> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1287, 0x1077, x86_l_1077);
x86_l_128d:
	/* 0x128d: jmp    117f <tail_handle_inter_cluster_revsnat+0x117f> */
	X86_SIM_X86_JMP(0x128d, 0x117f, x86_l_117f);
x86_l_1292:
	/* 0x1292: mov    eax,0xffffff73 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967155ULL);
x86_l_1297:
	/* 0x1297: jmp    12ab <tail_handle_inter_cluster_revsnat+0x12ab> */
	X86_SIM_X86_JMP(0x1297, 0x12ab, x86_l_12ab);
x86_l_1299:
	/* 0x1299: mov    eax,0xffffff63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967139ULL);
x86_l_129e:
	/* 0x129e: mov    ebp,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R13, X86_WIDTH_32);
x86_l_12a1:
	/* 0x12a1: jmp    ac8 <tail_handle_inter_cluster_revsnat+0xac8> */
	X86_SIM_X86_JMP(0x12a1, 0xac8, x86_l_ac8);
x86_l_12a6:
	/* 0x12a6: mov    eax,0xffffff66 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967142ULL);
x86_l_12ab:
	/* 0x12ab: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12ae:
	/* 0x12ae: movzx  esi,BYTE PTR [rsp+0x17] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 23ULL);
x86_l_12b3:
	/* 0x12b3: cmp    eax,0xffffff66 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967142ULL);
x86_l_12b8:
	/* 0x12b8: setne  cl */
	X86_SIM_L_EXEC_SETCC(X86_RCX, X86_CC_NE);
x86_l_12bb:
	/* 0x12bb: or     sil,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_12be:
	/* 0x12be: je     1077 <tail_handle_inter_cluster_revsnat+0x1077> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12be, 0x1077, x86_l_1077);
x86_l_12c4:
	/* 0x12c4: jmp    7d7 <tail_handle_inter_cluster_revsnat+0x7d7> */
	X86_SIM_X86_JMP(0x12c4, 0x7d7, x86_l_7d7);
x86_l_12c9:
	/* 0x12c9: mov    eax,0xffffff51 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967121ULL);
x86_l_12ce:
	/* 0x12ce: mov    ebp,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R13, X86_WIDTH_32);
x86_l_12d1:
	/* 0x12d1: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12d4:
	/* 0x12d4: cmp    eax,0xffffff53 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294967123ULL);
x86_l_12d9:
	/* 0x12d9: jne    7e6 <tail_handle_inter_cluster_revsnat+0x7e6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x12d9, 0x7e6, x86_l_7e6);
x86_l_12df:
	/* 0x12df: jmp    7fa <tail_handle_inter_cluster_revsnat+0x7fa> */
	X86_SIM_X86_JMP(0x12df, 0x7fa, x86_l_7fa);
x86_l_12e4:
	/* 0x12e4: mov    QWORD PTR [rsp+0x68],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598785ULL);
x86_l_12ed:
	/* 0x12ed: mov    QWORD PTR [rsp+0x70],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_12f2:
	/* 0x12f2: mov    rdi,QWORD PTR [rip+0x7bba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_12f9:
	/* 0x12f9: lea    rsi,[rsp+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_12fe:
	/* 0x12fe: lea    rdx,[rsp+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1303:
	/* 0x1303: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1308:
	/* 0x1308: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_130a:
	/* 0x130a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_130c:
	/* 0x130c: jmp    1216 <tail_handle_inter_cluster_revsnat+0x1216> */
	X86_SIM_X86_JMP(0x130c, 0x1216, x86_l_1216);
x86_l_1311:
	/* 0x1311: mov    r12d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 2ULL);
x86_l_1317:
	/* 0x1317: jmp    708 <tail_handle_inter_cluster_revsnat+0x708> */
	X86_SIM_X86_JMP(0x1317, 0x708, x86_l_708);
x86_l_131c:
	/* 0x131c: mov    r12d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 60ULL);
x86_l_1322:
	/* 0x1322: cmp    r15w,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_16, 6ULL);
x86_l_1327:
	/* 0x1327: jne    1365 <tail_handle_inter_cluster_revsnat+0x1365> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1327, 0x1365, x86_l_1365);
x86_l_1329:
	/* 0x1329: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_132c:
	/* 0x132c: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_132e:
	/* 0x132e: shr    ecx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_1331:
	/* 0x1331: and    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_1334:
	/* 0x1334: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1336:
	/* 0x1336: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_133b:
	/* 0x133b: mov    WORD PTR [rdx+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_133f:
	/* 0x133f: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_1341:
	/* 0x1341: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_1346:
	/* 0x1346: mov    r12d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 21600ULL);
x86_l_134c:
	/* 0x134c: cmove  r12d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R12, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_1350:
	/* 0x1350: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1354:
	/* 0x1354: je     1365 <tail_handle_inter_cluster_revsnat+0x1365> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1354, 0x1365, x86_l_1365);
x86_l_1356:
	/* 0x1356: mov    rax,QWORD PTR [rip+0x7bba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_135d:
	/* 0x135d: imul   r12d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R12, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_1361:
	/* 0x1361: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1365:
	/* 0x1365: shr    DWORD PTR [rsp],0x8 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RSP, X86_WIDTH_32, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_SHR)), 8ULL);
x86_l_1369:
	/* 0x1369: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_136d:
	/* 0x136d: je     137e <tail_handle_inter_cluster_revsnat+0x137e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x136d, 0x137e, x86_l_137e);
x86_l_136f:
	/* 0x136f: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_1374:
	/* 0x1374: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1376:
	/* 0x1376: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1378:
	/* 0x1378: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_137c:
	/* 0x137c: jmp    13a1 <tail_handle_inter_cluster_revsnat+0x13a1> */
	X86_SIM_X86_JMP(0x137c, 0x13a1, x86_l_13a1);
x86_l_137e:
	/* 0x137e: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_1383:
	/* 0x1383: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1385:
	/* 0x1385: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1387:
	/* 0x1387: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_138b:
	/* 0x138b: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_1395:
	/* 0x1395: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1398:
	/* 0x1398: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_139d:
	/* 0x139d: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_13a1:
	/* 0x13a1: add    r12d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_13a4:
	/* 0x13a4: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_13a9:
	/* 0x13a9: mov    DWORD PTR [rdx+0x20],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_13ad:
	/* 0x13ad: movzx  ecx,BYTE PTR [rdx+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_13b1:
	/* 0x13b1: mov    edx,DWORD PTR [rdx+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_13b4:
	/* 0x13b4: mov    esi,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13b7:
	/* 0x13b7: and    sil,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_13bb:
	/* 0x13bb: mov    DWORD PTR [rsp],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13be:
	/* 0x13be: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13c2:
	/* 0x13c2: je     13d5 <tail_handle_inter_cluster_revsnat+0x13d5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13c2, 0x13d5, x86_l_13d5);
x86_l_13c4:
	/* 0x13c4: mov    rsi,QWORD PTR [rip+0x7bba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_13cb:
	/* 0x13cb: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13cd:
	/* 0x13cd: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_13d0:
	/* 0x13d0: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_13d3:
	/* 0x13d3: jmp    13da <tail_handle_inter_cluster_revsnat+0x13da> */
	X86_SIM_X86_JMP(0x13d3, 0x13da, x86_l_13da);
x86_l_13d5:
	/* 0x13d5: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_13da:
	/* 0x13da: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_13dc:
	/* 0x13dc: mov    edx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13df:
	/* 0x13df: or     dl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_13e1:
	/* 0x13e1: mov    DWORD PTR [rsp],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13e4:
	/* 0x13e4: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_13e6:
	/* 0x13e6: mov    r9,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_13eb:
	/* 0x13eb: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_13f0:
	/* 0x13f0: jb     13fb <tail_handle_inter_cluster_revsnat+0x13fb> */
	X86_SIM_X86_JCC(X86_CC_B, 0x13f0, 0x13fb, x86_l_13fb);
x86_l_13f2:
	/* 0x13f2: cmp    cl,BYTE PTR [rsp] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_RSP, X86_WIDTH_8, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_13f5:
	/* 0x13f5: je     dca <tail_handle_inter_cluster_revsnat+0xdca> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13f5, 0xdca, x86_l_dca);
x86_l_13fb:
	/* 0x13fb: mov    ecx,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13fe:
	/* 0x13fe: mov    BYTE PTR [rdx+0x2b],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_1401:
	/* 0x1401: mov    DWORD PTR [rdx+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1404:
	/* 0x1404: jmp    dc1 <tail_handle_inter_cluster_revsnat+0xdc1> */
	X86_SIM_X86_JMP(0x1404, 0xdc1, x86_l_dc1);
x86_l_1409:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
