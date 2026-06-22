extern char __aux_snat_v6_args;
extern char __config_interface_ifindex;
extern char __config_nodeport_port_max;
extern char _aux_max_off;
extern char _aux_stride;
extern char cilium_calls;
extern char cilium_metrics;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int cilium_bpf_wireguard_tail_handle_snat_fwd_ipv6_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 40ULL);
x86_l_7:
	/* 0x7: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_a:
	/* 0xa: mov    r15d,DWORD PTR [rdi+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_e:
	/* 0xe: mov    DWORD PTR [rdi+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_15:
	/* 0x15: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1a:
	/* 0x1a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c:
	/* 0x1c: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_1e:
	/* 0x1e: mov    rcx,QWORD PTR [rip+0xca87] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&_aux_stride)));
x86_l_25:
	/* 0x25: mov    eax,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_27:
	/* 0x27: imul   rax,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_2b:
	/* 0x2b: mov    rcx,QWORD PTR [rip+0xca87] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&_aux_max_off)));
x86_l_32:
	/* 0x32: cmp    rax,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 0ULL);
x86_l_35:
	/* 0x35: jbe    3a <tail_handle_snat_fwd_ipv6+0x3a> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x35, 0x3a, x86_l_3a);
x86_l_37:
	/* 0x37: mov    rax,QWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3a:
	/* 0x3a: mov    r12,QWORD PTR [rip+0xca87] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&__aux_snat_v6_args)));
x86_l_41:
	/* 0x41: mov    QWORD PTR [r12+rax*1+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 309237645312ULL);
x86_l_4a:
	/* 0x4a: mov    QWORD PTR [r12+rax*1+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 240518168576ULL);
x86_l_53:
	/* 0x53: mov    QWORD PTR [r12+rax*1+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 274877906944ULL);
x86_l_5c:
	/* 0x5c: mov    QWORD PTR [r12+rax*1+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 206158430208ULL);
x86_l_65:
	/* 0x65: mov    QWORD PTR [r12+rax*1+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 171798691840ULL);
x86_l_6e:
	/* 0x6e: mov    QWORD PTR [r12+rax*1+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 137438953472ULL);
x86_l_77:
	/* 0x77: mov    QWORD PTR [r12+rax*1+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 103079215104ULL);
x86_l_80:
	/* 0x80: mov    QWORD PTR [r12+rax*1+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 68719476736ULL);
x86_l_89:
	/* 0x89: mov    QWORD PTR [r12+rax*1+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 34359738368ULL);
x86_l_92:
	/* 0x92: mov    QWORD PTR [r12+rax*1],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_RAX, 0), 0ULL);
x86_l_9a:
	/* 0x9a: mov    BYTE PTR [r12+rax*1+0x48],0x5 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_RAX, 0), 309237645317ULL);
x86_l_a0:
	/* 0xa0: mov    rcx,QWORD PTR [rip+0xca87] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_nodeport_port_max)));
x86_l_a7:
	/* 0xa7: movzx  ecx,WORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_aa:
	/* 0xaa: inc    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_ac:
	/* 0xac: mov    WORD PTR [r12+rax*1+0x38],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 0), 56ULL);
x86_l_b2:
	/* 0xb2: mov    WORD PTR [r12+rax*1+0x3a],0xffff */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 0), 249108168703ULL);
x86_l_ba:
	/* 0xba: mov    r14d,DWORD PTR [rbx+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_be:
	/* 0xbe: mov    ecx,DWORD PTR [rbx+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_c1:
	/* 0xc1: lea    rdx,[r14+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c5:
	/* 0xc5: mov    r13d,0x86 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 134ULL);
x86_l_cb:
	/* 0xcb: cmp    rdx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_ce:
	/* 0xce: ja     3c4 <tail_handle_snat_fwd_ipv6+0x3c4> */
	X86_SIM_X86_JCC(X86_CC_A, 0xce, 0x3c4, x86_l_3c4);
x86_l_d4:
	/* 0xd4: mov    DWORD PTR [rsp+0xc],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_d9:
	/* 0xd9: add    r12,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_dc:
	/* 0xdc: movzx  r15d,BYTE PTR [r14+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_e1:
	/* 0xe1: mov    BYTE PTR [r12+0x24],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_e6:
	/* 0xe6: cmp    r15,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 60ULL);
x86_l_ea:
	/* 0xea: ja     47a <tail_handle_snat_fwd_ipv6+0x47a> */
	X86_SIM_X86_JCC(X86_CC_A, 0xea, 0x47a, x86_l_47a);
x86_l_f0:
	/* 0xf0: mov    r13d,0x9c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 156ULL);
x86_l_f6:
	/* 0xf6: movabs rax,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_100:
	/* 0x100: bt     rax,r15 */
	X86_SIM_L_EXEC_BT(X86_RAX, X86_R15, X86_WIDTH_64);
x86_l_104:
	/* 0x104: jae    160 <tail_handle_snat_fwd_ipv6+0x160> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x104, 0x160, x86_l_160);
x86_l_106:
	/* 0x106: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10b:
	/* 0x10b: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_110:
	/* 0x110: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_113:
	/* 0x113: mov    esi,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 40ULL);
x86_l_118:
	/* 0x118: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_11d:
	/* 0x11d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_11f:
	/* 0x11f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_121:
	/* 0x121: js     3b9 <tail_handle_snat_fwd_ipv6+0x3b9> */
	X86_SIM_X86_JCC(X86_CC_S, 0x121, 0x3b9, x86_l_3b9);
x86_l_127:
	/* 0x127: movzx  edx,BYTE PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_12c:
	/* 0x12c: cmp    r15d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 43ULL);
x86_l_130:
	/* 0x130: jle    14c <tail_handle_snat_fwd_ipv6+0x14c> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x130, 0x14c, x86_l_14c);
x86_l_132:
	/* 0x132: cmp    r15d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 60ULL);
x86_l_136:
	/* 0x136: je     14c <tail_handle_snat_fwd_ipv6+0x14c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x136, 0x14c, x86_l_14c);
x86_l_138:
	/* 0x138: cmp    r15d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 51ULL);
x86_l_13c:
	/* 0x13c: jne    16f <tail_handle_snat_fwd_ipv6+0x16f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x13c, 0x16f, x86_l_16f);
x86_l_13e:
	/* 0x13e: movzx  eax,BYTE PTR [rsp+0x11] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 17ULL);
x86_l_143:
	/* 0x143: lea    esi,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_14a:
	/* 0x14a: jmp    1a8 <tail_handle_snat_fwd_ipv6+0x1a8> */
	X86_SIM_X86_JMP(0x14a, 0x1a8, x86_l_1a8);
x86_l_14c:
	/* 0x14c: movzx  eax,BYTE PTR [rsp+0x11] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 17ULL);
x86_l_151:
	/* 0x151: lea    esi,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_158:
	/* 0x158: cmp    r15b,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_8, 44ULL);
x86_l_15c:
	/* 0x15c: je     174 <tail_handle_snat_fwd_ipv6+0x174> */
	X86_SIM_X86_JCC(X86_CC_E, 0x15c, 0x174, x86_l_174);
x86_l_15e:
	/* 0x15e: jmp    1a8 <tail_handle_snat_fwd_ipv6+0x1a8> */
	X86_SIM_X86_JMP(0x15e, 0x1a8, x86_l_1a8);
x86_l_160:
	/* 0x160: cmp    r15,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 59ULL);
x86_l_164:
	/* 0x164: je     3bf <tail_handle_snat_fwd_ipv6+0x3bf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x164, 0x3bf, x86_l_3bf);
x86_l_16a:
	/* 0x16a: jmp    47a <tail_handle_snat_fwd_ipv6+0x47a> */
	X86_SIM_X86_JMP(0x16a, 0x47a, x86_l_47a);
x86_l_16f:
	/* 0x16f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_174:
	/* 0x174: mov    r15d,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_32);
x86_l_177:
	/* 0x177: mov    ebp,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RSI, X86_WIDTH_32);
x86_l_179:
	/* 0x179: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_182:
	/* 0x182: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_187:
	/* 0x187: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_18c:
	/* 0x18c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_18f:
	/* 0x18f: mov    esi,0x28 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 40ULL);
x86_l_194:
	/* 0x194: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_199:
	/* 0x199: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19b:
	/* 0x19b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_19d:
	/* 0x19d: js     3b9 <tail_handle_snat_fwd_ipv6+0x3b9> */
	X86_SIM_X86_JCC(X86_CC_S, 0x19d, 0x3b9, x86_l_3b9);
x86_l_1a3:
	/* 0x1a3: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_1a5:
	/* 0x1a5: mov    edx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_32);
x86_l_1a8:
	/* 0x1a8: movzx  ebp,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_1ab:
	/* 0x1ab: cmp    ebp,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_1ae:
	/* 0x1ae: ja     477 <tail_handle_snat_fwd_ipv6+0x477> */
	X86_SIM_X86_JCC(X86_CC_A, 0x1ae, 0x477, x86_l_477);
x86_l_1b4:
	/* 0x1b4: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_1b6:
	/* 0x1b6: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_1c0:
	/* 0x1c0: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1c4:
	/* 0x1c4: jae    468 <tail_handle_snat_fwd_ipv6+0x468> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x1c4, 0x468, x86_l_468);
x86_l_1ca:
	/* 0x1ca: mov    BYTE PTR [rsp+0xb],dl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 11ULL);
x86_l_1ce:
	/* 0x1ce: add    esi,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 40ULL);
x86_l_1d1:
	/* 0x1d1: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d6:
	/* 0x1d6: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1db:
	/* 0x1db: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1de:
	/* 0x1de: mov    DWORD PTR [rsp+0x4],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1e2:
	/* 0x1e2: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1e7:
	/* 0x1e7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e9:
	/* 0x1e9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1eb:
	/* 0x1eb: js     3b9 <tail_handle_snat_fwd_ipv6+0x3b9> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1eb, 0x3b9, x86_l_3b9);
x86_l_1f1:
	/* 0x1f1: movzx  r15d,BYTE PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_1f7:
	/* 0x1f7: cmp    ebp,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 43ULL);
x86_l_1fa:
	/* 0x1fa: jle    219 <tail_handle_snat_fwd_ipv6+0x219> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x1fa, 0x219, x86_l_219);
x86_l_1fc:
	/* 0x1fc: cmp    ebp,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 44ULL);
x86_l_1ff:
	/* 0x1ff: mov    r8d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_204:
	/* 0x204: je     233 <tail_handle_snat_fwd_ipv6+0x233> */
	X86_SIM_X86_JCC(X86_CC_E, 0x204, 0x233, x86_l_233);
x86_l_206:
	/* 0x206: cmp    ebp,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 51ULL);
x86_l_209:
	/* 0x209: jne    21e <tail_handle_snat_fwd_ipv6+0x21e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x209, 0x21e, x86_l_21e);
x86_l_20b:
	/* 0x20b: movzx  eax,BYTE PTR [rsp+0x11] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 17ULL);
x86_l_210:
	/* 0x210: lea    esi,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_217:
	/* 0x217: jmp    269 <tail_handle_snat_fwd_ipv6+0x269> */
	X86_SIM_X86_JMP(0x217, 0x269, x86_l_269);
x86_l_219:
	/* 0x219: mov    r8d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_21e:
	/* 0x21e: movzx  eax,BYTE PTR [rsp+0x11] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 17ULL);
x86_l_223:
	/* 0x223: lea    esi,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_22a:
	/* 0x22a: cmp    BYTE PTR [rsp+0xb],0x2c */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 47244640300ULL);
x86_l_22f:
	/* 0x22f: je     238 <tail_handle_snat_fwd_ipv6+0x238> */
	X86_SIM_X86_JCC(X86_CC_E, 0x22f, 0x238, x86_l_238);
x86_l_231:
	/* 0x231: jmp    269 <tail_handle_snat_fwd_ipv6+0x269> */
	X86_SIM_X86_JMP(0x231, 0x269, x86_l_269);
x86_l_233:
	/* 0x233: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_238:
	/* 0x238: mov    ebp,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RSI, X86_WIDTH_32);
x86_l_23a:
	/* 0x23a: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_243:
	/* 0x243: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_248:
	/* 0x248: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_24d:
	/* 0x24d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_250:
	/* 0x250: mov    esi,r8d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R8, X86_WIDTH_32);
x86_l_253:
	/* 0x253: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_258:
	/* 0x258: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25a:
	/* 0x25a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_25c:
	/* 0x25c: js     3b9 <tail_handle_snat_fwd_ipv6+0x3b9> */
	X86_SIM_X86_JCC(X86_CC_S, 0x25c, 0x3b9, x86_l_3b9);
x86_l_262:
	/* 0x262: mov    r8d,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_267:
	/* 0x267: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_269:
	/* 0x269: movzx  ebp,r15b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_R15, X86_WIDTH_32, X86_WIDTH_8);
x86_l_26d:
	/* 0x26d: cmp    ebp,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_270:
	/* 0x270: ja     47a <tail_handle_snat_fwd_ipv6+0x47a> */
	X86_SIM_X86_JCC(X86_CC_A, 0x270, 0x47a, x86_l_47a);
x86_l_276:
	/* 0x276: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_278:
	/* 0x278: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_282:
	/* 0x282: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_286:
	/* 0x286: jae    46b <tail_handle_snat_fwd_ipv6+0x46b> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x286, 0x46b, x86_l_46b);
x86_l_28c:
	/* 0x28c: add    esi,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R8, X86_WIDTH_32, X86_ALU_ADD);
x86_l_28f:
	/* 0x28f: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_294:
	/* 0x294: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_299:
	/* 0x299: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_29c:
	/* 0x29c: mov    DWORD PTR [rsp+0x4],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2a0:
	/* 0x2a0: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2a5:
	/* 0x2a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a7:
	/* 0x2a7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2a9:
	/* 0x2a9: js     3b9 <tail_handle_snat_fwd_ipv6+0x3b9> */
	X86_SIM_X86_JCC(X86_CC_S, 0x2a9, 0x3b9, x86_l_3b9);
x86_l_2af:
	/* 0x2af: movzx  edx,BYTE PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 16ULL);
x86_l_2b4:
	/* 0x2b4: cmp    ebp,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 43ULL);
x86_l_2b7:
	/* 0x2b7: jle    2d5 <tail_handle_snat_fwd_ipv6+0x2d5> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x2b7, 0x2d5, x86_l_2d5);
x86_l_2b9:
	/* 0x2b9: cmp    ebp,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 44ULL);
x86_l_2bc:
	/* 0x2bc: mov    esi,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2c0:
	/* 0x2c0: je     2ed <tail_handle_snat_fwd_ipv6+0x2ed> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2c0, 0x2ed, x86_l_2ed);
x86_l_2c2:
	/* 0x2c2: cmp    ebp,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 51ULL);
x86_l_2c5:
	/* 0x2c5: jne    2d9 <tail_handle_snat_fwd_ipv6+0x2d9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2c5, 0x2d9, x86_l_2d9);
x86_l_2c7:
	/* 0x2c7: movzx  eax,BYTE PTR [rsp+0x11] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 17ULL);
x86_l_2cc:
	/* 0x2cc: lea    ebp,[rax*4+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 8ULL);
x86_l_2d3:
	/* 0x2d3: jmp    321 <tail_handle_snat_fwd_ipv6+0x321> */
	X86_SIM_X86_JMP(0x2d3, 0x321, x86_l_321);
x86_l_2d5:
	/* 0x2d5: mov    esi,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2d9:
	/* 0x2d9: movzx  eax,BYTE PTR [rsp+0x11] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 17ULL);
x86_l_2de:
	/* 0x2de: lea    ebp,[rax*8+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 3), 8ULL);
x86_l_2e5:
	/* 0x2e5: cmp    r15b,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_8, 44ULL);
x86_l_2e9:
	/* 0x2e9: je     2f2 <tail_handle_snat_fwd_ipv6+0x2f2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2e9, 0x2f2, x86_l_2f2);
x86_l_2eb:
	/* 0x2eb: jmp    321 <tail_handle_snat_fwd_ipv6+0x321> */
	X86_SIM_X86_JMP(0x2eb, 0x321, x86_l_321);
x86_l_2ed:
	/* 0x2ed: mov    ebp,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 8ULL);
x86_l_2f2:
	/* 0x2f2: mov    r15d,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_32);
x86_l_2f5:
	/* 0x2f5: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2fe:
	/* 0x2fe: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_303:
	/* 0x303: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_308:
	/* 0x308: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_30b:
	/* 0x30b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_310:
	/* 0x310: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_312:
	/* 0x312: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_314:
	/* 0x314: js     3b9 <tail_handle_snat_fwd_ipv6+0x3b9> */
	X86_SIM_X86_JCC(X86_CC_S, 0x314, 0x3b9, x86_l_3b9);
x86_l_31a:
	/* 0x31a: mov    esi,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_31e:
	/* 0x31e: mov    edx,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_32);
x86_l_321:
	/* 0x321: movzx  r15d,dl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_R15, X86_RDX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_325:
	/* 0x325: cmp    r15d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 60ULL);
x86_l_329:
	/* 0x329: ja     477 <tail_handle_snat_fwd_ipv6+0x477> */
	X86_SIM_X86_JCC(X86_CC_A, 0x329, 0x477, x86_l_477);
x86_l_32f:
	/* 0x32f: mov    eax,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R15, X86_WIDTH_32);
x86_l_332:
	/* 0x332: movabs rcx,0x1008180000000001 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 1155199692699598849ULL);
x86_l_33c:
	/* 0x33c: bt     rcx,rax */
	X86_SIM_L_EXEC_BT(X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_340:
	/* 0x340: jae    468 <tail_handle_snat_fwd_ipv6+0x468> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x340, 0x468, x86_l_468);
x86_l_346:
	/* 0x346: mov    r14d,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_32);
x86_l_349:
	/* 0x349: add    ebp,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_34b:
	/* 0x34b: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_350:
	/* 0x350: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_355:
	/* 0x355: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_358:
	/* 0x358: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_35a:
	/* 0x35a: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_35f:
	/* 0x35f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_361:
	/* 0x361: mov    r13d,0x86 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 134ULL);
x86_l_367:
	/* 0x367: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_369:
	/* 0x369: js     3bf <tail_handle_snat_fwd_ipv6+0x3bf> */
	X86_SIM_X86_JCC(X86_CC_S, 0x369, 0x3bf, x86_l_3bf);
x86_l_36b:
	/* 0x36b: cmp    r15d,0x2b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 43ULL);
x86_l_36f:
	/* 0x36f: jle    37d <tail_handle_snat_fwd_ipv6+0x37d> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x36f, 0x37d, x86_l_37d);
x86_l_371:
	/* 0x371: cmp    r15d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 44ULL);
x86_l_375:
	/* 0x375: je     38e <tail_handle_snat_fwd_ipv6+0x38e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x375, 0x38e, x86_l_38e);
x86_l_377:
	/* 0x377: cmp    r15d,0x33 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 51ULL);
x86_l_37b:
	/* 0x37b: je     3b1 <tail_handle_snat_fwd_ipv6+0x3b1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x37b, 0x3b1, x86_l_3b1);
x86_l_37d:
	/* 0x37d: mov    r15d,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_382:
	/* 0x382: mov    r13d,0x9c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 156ULL);
x86_l_388:
	/* 0x388: cmp    r14b,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_8, 44ULL);
x86_l_38c:
	/* 0x38c: jne    3c4 <tail_handle_snat_fwd_ipv6+0x3c4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x38c, 0x3c4, x86_l_3c4);
x86_l_38e:
	/* 0x38e: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_397:
	/* 0x397: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_39c:
	/* 0x39c: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_3a1:
	/* 0x3a1: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_3a4:
	/* 0x3a4: mov    esi,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_32);
x86_l_3a6:
	/* 0x3a6: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3ab:
	/* 0x3ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ad:
	/* 0x3ad: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3af:
	/* 0x3af: js     3b9 <tail_handle_snat_fwd_ipv6+0x3b9> */
	X86_SIM_X86_JCC(X86_CC_S, 0x3af, 0x3b9, x86_l_3b9);
x86_l_3b1:
	/* 0x3b1: mov    r13d,0x9c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 156ULL);
x86_l_3b7:
	/* 0x3b7: jmp    3bf <tail_handle_snat_fwd_ipv6+0x3bf> */
	X86_SIM_X86_JMP(0x3b7, 0x3bf, x86_l_3bf);
x86_l_3b9:
	/* 0x3b9: mov    r13d,0x86 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 134ULL);
x86_l_3bf:
	/* 0x3bf: mov    r15d,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_3c4:
	/* 0x3c4: mov    DWORD PTR [rbx+0x30],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3c8:
	/* 0x3c8: mov    DWORD PTR [rbx+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_3cf:
	/* 0x3cf: mov    DWORD PTR [rbx+0x38],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_3d3:
	/* 0x3d3: movabs rax,0x8f710200000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 40375175073497088ULL);
x86_l_3dd:
	/* 0x3dd: mov    QWORD PTR [rbx+0x3c],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_3e1:
	/* 0x3e1: mov    r14d,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3e4:
	/* 0x3e4: movabs rax,0x71008f0200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 485340676608ULL);
x86_l_3ee:
	/* 0x3ee: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3f3:
	/* 0x3f3: mov    BYTE PTR [rsp+0x20],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3f8:
	/* 0x3f8: mov    rdi,QWORD PTR [rip+0xca87] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_3ff:
	/* 0x3ff: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_404:
	/* 0x404: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_409:
	/* 0x409: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_40b:
	/* 0x40b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_40e:
	/* 0x40e: je     419 <tail_handle_snat_fwd_ipv6+0x419> */
	X86_SIM_X86_JCC(X86_CC_E, 0x40e, 0x419, x86_l_419);
x86_l_410:
	/* 0x410: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_413:
	/* 0x413: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_417:
	/* 0x417: jmp    441 <tail_handle_snat_fwd_ipv6+0x441> */
	X86_SIM_X86_JMP(0x417, 0x441, x86_l_441);
x86_l_419:
	/* 0x419: mov    QWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_422:
	/* 0x422: mov    QWORD PTR [rsp+0x18],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_427:
	/* 0x427: mov    rdi,QWORD PTR [rip+0xca87] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_42e:
	/* 0x42e: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_433:
	/* 0x433: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_438:
	/* 0x438: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_43d:
	/* 0x43d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_43f:
	/* 0x43f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_441:
	/* 0x441: mov    rsi,QWORD PTR [rip+0xca87] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_448:
	/* 0x448: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_44d:
	/* 0x44d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_450:
	/* 0x450: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_455:
	/* 0x455: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_457:
	/* 0x457: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_45c:
	/* 0x45c: add    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_460:
	/* 0x460: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_462:
	/* 0x462: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_463:
	/* 0x463: jmp    518 <tail_handle_snat_fwd_ipv6+0x518> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_468:
	/* 0x468: mov    r15d,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_32);
x86_l_46b:
	/* 0x46b: cmp    rax,0x3b */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 59ULL);
x86_l_46f:
	/* 0x46f: je     3bf <tail_handle_snat_fwd_ipv6+0x3bf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x46f, 0x3bf, x86_l_3bf);
x86_l_475:
	/* 0x475: jmp    47a <tail_handle_snat_fwd_ipv6+0x47a> */
	X86_SIM_X86_JMP(0x475, 0x47a, x86_l_47a);
x86_l_477:
	/* 0x477: mov    r15d,edx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_32);
x86_l_47a:
	/* 0x47a: mov    BYTE PTR [r12+0x24],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_47f:
	/* 0x47f: mov    rax,QWORD PTR [r14+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_483:
	/* 0x483: mov    QWORD PTR [r12+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_488:
	/* 0x488: mov    rax,QWORD PTR [r14+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_48c:
	/* 0x48c: mov    QWORD PTR [r12],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_490:
	/* 0x490: mov    rax,QWORD PTR [r14+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_494:
	/* 0x494: mov    QWORD PTR [r12+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_499:
	/* 0x499: mov    rax,QWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_49d:
	/* 0x49d: mov    QWORD PTR [r12+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4a2:
	/* 0x4a2: mov    BYTE PTR [r12+0x25],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 158913789952ULL);
x86_l_4a8:
	/* 0x4a8: mov    rax,QWORD PTR [rip+0xca8a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_interface_ifindex)));
x86_l_4af:
	/* 0x4af: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4b1:
	/* 0x4b1: mov    ebx,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4b3:
	/* 0x4b3: movabs rax,0x71008f0200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 485340676608ULL);
x86_l_4bd:
	/* 0x4bd: add    rax,0xa000d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 655373ULL);
x86_l_4c3:
	/* 0x4c3: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4c8:
	/* 0x4c8: mov    rdi,QWORD PTR [rip+0xca8a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_4cf:
	/* 0x4cf: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4d4:
	/* 0x4d4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4d9:
	/* 0x4d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4db:
	/* 0x4db: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4de:
	/* 0x4de: je     4e9 <tail_handle_snat_fwd_ipv6+0x4e9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4de, 0x4e9, x86_l_4e9);
x86_l_4e0:
	/* 0x4e0: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_4e3:
	/* 0x4e3: add    QWORD PTR [rax+0x8],rbx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_4e7:
	/* 0x4e7: jmp    511 <tail_handle_snat_fwd_ipv6+0x511> */
	X86_SIM_X86_JMP(0x4e7, 0x511, x86_l_511);
x86_l_4e9:
	/* 0x4e9: mov    QWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_4f2:
	/* 0x4f2: mov    QWORD PTR [rsp+0x18],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4f7:
	/* 0x4f7: mov    rdi,QWORD PTR [rip+0xca8a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_4fe:
	/* 0x4fe: lea    rsi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_503:
	/* 0x503: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_508:
	/* 0x508: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_50d:
	/* 0x50d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_50f:
	/* 0x50f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_511:
	/* 0x511: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_513:
	/* 0x513: jmp    45c <tail_handle_snat_fwd_ipv6+0x45c> */
	X86_SIM_X86_JMP(0x513, 0x45c, x86_l_45c);
x86_l_518:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
