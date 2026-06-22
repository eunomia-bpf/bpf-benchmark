extern char __config_enable_netkit;
extern char __config_eth_header_length;
extern char __config_trace_payload_len;
extern char cilium_call_policy;
extern char cilium_calls;
extern char cilium_devices;
extern char cilium_lxc;
extern char cilium_metrics;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int cilium_bpf_host_tail_handle_ipv4_cont_from_netdev_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 56ULL);
x86_l_7:
	/* 0x7: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_a:
	/* 0xa: mov    ebp,DWORD PTR [rdi+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_d:
	/* 0xd: mov    DWORD PTR [rdi+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_14:
	/* 0x14: mov    rax,QWORD PTR [rip+0xa6b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_1b:
	/* 0x1b: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d:
	/* 0x1d: mov    r12,QWORD PTR [rip+0xa6b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&__config_eth_header_length)));
x86_l_24:
	/* 0x24: movzx  eax,BYTE PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_29:
	/* 0x29: mov    r13,QWORD PTR [rdi+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_30:
	/* 0x30: mov    ecx,DWORD PTR [rdi+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_33:
	/* 0x33: sub    ecx,DWORD PTR [rdi+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RDI, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_36:
	/* 0x36: add    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_39:
	/* 0x39: lea    rdx,[rax+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_3d:
	/* 0x3d: add    rdx,0x14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 20ULL);
x86_l_41:
	/* 0x41: mov    r15d,0x86 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 134ULL);
x86_l_47:
	/* 0x47: cmp    rdx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64);
x86_l_4a:
	/* 0x4a: jbe    a8 <tail_handle_ipv4_cont_from_netdev+0xa8> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x4a, 0xa8, x86_l_a8);
x86_l_4c:
	/* 0x4c: mov    DWORD PTR [rbx+0x28],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4f:
	/* 0x4f: mov    DWORD PTR [rbx+0x2c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561024ULL);
x86_l_56:
	/* 0x56: mov    DWORD PTR [rbx+0x30],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5a:
	/* 0x5a: movabs rax,0x394010200000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 257832186768523264ULL);
x86_l_64:
	/* 0x64: mov    QWORD PTR [rbx+0x34],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_68:
	/* 0x68: mov    r14d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_6c:
	/* 0x6c: movabs rax,0x103940100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 4354998528ULL);
x86_l_76:
	/* 0x76: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_7b:
	/* 0x7b: mov    BYTE PTR [rsp+0x18],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_80:
	/* 0x80: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_85:
	/* 0x85: mov    rdi,QWORD PTR [rip+0xa6b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_8c:
	/* 0x8c: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_91:
	/* 0x91: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_93:
	/* 0x93: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_96:
	/* 0x96: je     1ef <tail_handle_ipv4_cont_from_netdev+0x1ef> */
	X86_SIM_X86_JCC(X86_CC_E, 0x96, 0x1ef, x86_l_1ef);
x86_l_9c:
	/* 0x9c: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_9f:
	/* 0x9f: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_a3:
	/* 0xa3: jmp    214 <tail_handle_ipv4_cont_from_netdev+0x214> */
	X86_SIM_X86_JMP(0xa3, 0x214, x86_l_214);
x86_l_a8:
	/* 0xa8: add    r13,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_ab:
	/* 0xab: mov    eax,DWORD PTR [r13+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_af:
	/* 0xaf: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b7:
	/* 0xb7: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_bf:
	/* 0xbf: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_c8:
	/* 0xc8: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cb:
	/* 0xcb: mov    BYTE PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_d0:
	/* 0xd0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d5:
	/* 0xd5: mov    rdi,QWORD PTR [rip+0xa6b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lxc)));
x86_l_dc:
	/* 0xdc: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_df:
	/* 0xdf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e1:
	/* 0xe1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e3:
	/* 0xe3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e6:
	/* 0xe6: je     22f <tail_handle_ipv4_cont_from_netdev+0x22f> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe6, 0x22f, x86_l_22f);
x86_l_ec:
	/* 0xec: movzx  r14d,BYTE PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_f1:
	/* 0xf1: test   BYTE PTR [rax+0x8],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738371ULL);
x86_l_f5:
	/* 0xf5: jne    22f <tail_handle_ipv4_cont_from_netdev+0x22f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf5, 0x22f, x86_l_22f);
x86_l_fb:
	/* 0xfb: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_100:
	/* 0x100: je     23d <tail_handle_ipv4_cont_from_netdev+0x23d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x100, 0x23d, x86_l_23d);
x86_l_106:
	/* 0x106: mov    rcx,QWORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_10a:
	/* 0x10a: mov    QWORD PTR [rsp+0x30],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_10f:
	/* 0x10f: mov    rcx,QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_113:
	/* 0x113: mov    QWORD PTR [rsp+0x28],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_118:
	/* 0x118: movzx  edx,BYTE PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R13, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_11d:
	/* 0x11d: mov    r15d,0xc4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 196ULL);
x86_l_123:
	/* 0x123: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_126:
	/* 0x126: jb     4c <tail_handle_ipv4_cont_from_netdev+0x4c> */
	X86_SIM_X86_JCC(X86_CC_B, 0x126, 0x4c, x86_l_4c);
x86_l_12c:
	/* 0x12c: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_12f:
	/* 0x12f: lea    eax,[rdx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_132:
	/* 0x132: mov    BYTE PTR [r13+0x8],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_136:
	/* 0x136: add    r14d,0xa */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 10ULL);
x86_l_13a:
	/* 0x13a: movzx  ecx,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_13d:
	/* 0x13d: mov    eax,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_142:
	/* 0x142: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_145:
	/* 0x145: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_148:
	/* 0x148: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_14e:
	/* 0x14e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_150:
	/* 0x150: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_152:
	/* 0x152: js     2a3 <tail_handle_ipv4_cont_from_netdev+0x2a3> */
	X86_SIM_X86_JCC(X86_CC_S, 0x152, 0x2a3, x86_l_2a3);
x86_l_158:
	/* 0x158: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_15d:
	/* 0x15d: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_162:
	/* 0x162: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_165:
	/* 0x165: mov    esi,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 6ULL);
x86_l_16a:
	/* 0x16a: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_16f:
	/* 0x16f: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_172:
	/* 0x172: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_174:
	/* 0x174: mov    r15d,0x8d */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 141ULL);
x86_l_17a:
	/* 0x17a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_17c:
	/* 0x17c: js     4c <tail_handle_ipv4_cont_from_netdev+0x4c> */
	X86_SIM_X86_JCC(X86_CC_S, 0x17c, 0x4c, x86_l_4c);
x86_l_182:
	/* 0x182: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_187:
	/* 0x187: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_18c:
	/* 0x18c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_18f:
	/* 0x18f: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_191:
	/* 0x191: mov    ecx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_196:
	/* 0x196: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_199:
	/* 0x199: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19b:
	/* 0x19b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_19d:
	/* 0x19d: js     4c <tail_handle_ipv4_cont_from_netdev+0x4c> */
	X86_SIM_X86_JCC(X86_CC_S, 0x19d, 0x4c, x86_l_4c);
x86_l_1a3:
	/* 0x1a3: mov    r14d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1a7:
	/* 0x1a7: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1b0:
	/* 0x1b0: mov    QWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b8:
	/* 0x1b8: movabs rax,0x6d00840100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 468160086272ULL);
x86_l_1c2:
	/* 0x1c2: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1c7:
	/* 0x1c7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1cc:
	/* 0x1cc: mov    rdi,QWORD PTR [rip+0xa6b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1d3:
	/* 0x1d3: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d8:
	/* 0x1d8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1da:
	/* 0x1da: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1dd:
	/* 0x1dd: je     310 <tail_handle_ipv4_cont_from_netdev+0x310> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1dd, 0x310, x86_l_310);
x86_l_1e3:
	/* 0x1e3: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1e6:
	/* 0x1e6: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1ea:
	/* 0x1ea: jmp    335 <tail_handle_ipv4_cont_from_netdev+0x335> */
	X86_SIM_X86_JMP(0x1ea, 0x335, x86_l_335);
x86_l_1ef:
	/* 0x1ef: mov    QWORD PTR [rsp],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_1f7:
	/* 0x1f7: mov    QWORD PTR [rsp+0x8],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1fc:
	/* 0x1fc: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_201:
	/* 0x201: mov    rdi,QWORD PTR [rip+0xa6b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_208:
	/* 0x208: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_20d:
	/* 0x20d: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_210:
	/* 0x210: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_212:
	/* 0x212: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_214:
	/* 0x214: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_219:
	/* 0x219: mov    rsi,QWORD PTR [rip+0xa6b7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_220:
	/* 0x220: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_223:
	/* 0x223: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_228:
	/* 0x228: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22a:
	/* 0x22a: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_22f:
	/* 0x22f: mov    eax,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_32);
x86_l_231:
	/* 0x231: add    rsp,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 56ULL);
x86_l_235:
	/* 0x235: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_237:
	/* 0x237: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_238:
	/* 0x238: jmp    374 <tail_handle_ipv4_cont_from_netdev+0x374> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_23d:
	/* 0x23d: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_242:
	/* 0x242: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_244:
	/* 0x244: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_247:
	/* 0x247: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_24c:
	/* 0x24c: mov    rdi,QWORD PTR [rip+0xa6ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_devices)));
x86_l_253:
	/* 0x253: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_256:
	/* 0x256: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_258:
	/* 0x258: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_25b:
	/* 0x25b: je     263 <tail_handle_ipv4_cont_from_netdev+0x263> */
	X86_SIM_X86_JCC(X86_CC_E, 0x25b, 0x263, x86_l_263);
x86_l_25d:
	/* 0x25d: test   BYTE PTR [rax+0x8],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_261:
	/* 0x261: jne    2ae <tail_handle_ipv4_cont_from_netdev+0x2ae> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x261, 0x2ae, x86_l_2ae);
x86_l_263:
	/* 0x263: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_268:
	/* 0x268: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_26d:
	/* 0x26d: je     2b8 <tail_handle_ipv4_cont_from_netdev+0x2b8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x26d, 0x2b8, x86_l_2b8);
x86_l_26f:
	/* 0x26f: mov    rcx,QWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_276:
	/* 0x276: mov    edx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_279:
	/* 0x279: sub    edx,DWORD PTR [rbx+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_27c:
	/* 0x27c: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_27f:
	/* 0x27f: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_282:
	/* 0x282: add    rsi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_285:
	/* 0x285: add    rsi,0x22 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 34ULL);
x86_l_289:
	/* 0x289: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_28c:
	/* 0x28c: ja     4c <tail_handle_ipv4_cont_from_netdev+0x4c> */
	X86_SIM_X86_JCC(X86_CC_A, 0x28c, 0x4c, x86_l_4c);
x86_l_292:
	/* 0x292: lea    r13,[rcx+r14*1] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_R14, 0), 0ULL);
x86_l_296:
	/* 0x296: add    r13,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 14ULL);
x86_l_29a:
	/* 0x29a: add    r14,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 14ULL);
x86_l_29e:
	/* 0x29e: jmp    106 <tail_handle_ipv4_cont_from_netdev+0x106> */
	X86_SIM_X86_JMP(0x29e, 0x106, x86_l_106);
x86_l_2a3:
	/* 0x2a3: mov    r15d,0x99 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 153ULL);
x86_l_2a9:
	/* 0x2a9: jmp    4c <tail_handle_ipv4_cont_from_netdev+0x4c> */
	X86_SIM_X86_JMP(0x2a9, 0x4c, x86_l_4c);
x86_l_2ae:
	/* 0x2ae: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2b3:
	/* 0x2b3: jmp    106 <tail_handle_ipv4_cont_from_netdev+0x106> */
	X86_SIM_X86_JMP(0x2b3, 0x106, x86_l_106);
x86_l_2b8:
	/* 0x2b8: movzx  r12d,WORD PTR [rbx+0xb4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 180ULL);
x86_l_2c0:
	/* 0x2c0: mov    eax,0x2b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 43ULL);
x86_l_2c5:
	/* 0x2c5: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2c8:
	/* 0x2c8: mov    esi,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 14ULL);
x86_l_2cd:
	/* 0x2cd: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2cf:
	/* 0x2cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d1:
	/* 0x2d1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2d3:
	/* 0x2d3: jne    4c <tail_handle_ipv4_cont_from_netdev+0x4c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2d3, 0x4c, x86_l_4c);
x86_l_2d9:
	/* 0x2d9: mov    WORD PTR [rsp],r12w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2de:
	/* 0x2de: mov    eax,0x9 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 9ULL);
x86_l_2e3:
	/* 0x2e3: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_2e6:
	/* 0x2e6: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2e9:
	/* 0x2e9: mov    esi,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 12ULL);
x86_l_2ee:
	/* 0x2ee: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2f3:
	/* 0x2f3: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f6:
	/* 0x2f6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f8:
	/* 0x2f8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2fa:
	/* 0x2fa: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2ff:
	/* 0x2ff: jns    26f <tail_handle_ipv4_cont_from_netdev+0x26f> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x2ff, 0x26f, x86_l_26f);
x86_l_305:
	/* 0x305: mov    r15d,0x8d */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 141ULL);
x86_l_30b:
	/* 0x30b: jmp    4c <tail_handle_ipv4_cont_from_netdev+0x4c> */
	X86_SIM_X86_JMP(0x30b, 0x4c, x86_l_4c);
x86_l_310:
	/* 0x310: mov    QWORD PTR [rsp],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_318:
	/* 0x318: mov    QWORD PTR [rsp+0x8],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_31d:
	/* 0x31d: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_322:
	/* 0x322: mov    rdi,QWORD PTR [rip+0xa6ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_329:
	/* 0x329: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_32e:
	/* 0x32e: mov    rdx,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSP, X86_WIDTH_64);
x86_l_331:
	/* 0x331: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_333:
	/* 0x333: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_335:
	/* 0x335: movzx  edx,WORD PTR [r12+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_33b:
	/* 0x33b: mov    rax,QWORD PTR [rip+0xa6ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_netkit)));
x86_l_342:
	/* 0x342: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_345:
	/* 0x345: mov    DWORD PTR [rbx+0x28],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_348:
	/* 0x348: mov    QWORD PTR [rbx+0x2c],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 188978561025ULL);
x86_l_350:
	/* 0x350: mov    QWORD PTR [rbx+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_358:
	/* 0x358: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_35d:
	/* 0x35d: mov    rsi,QWORD PTR [rip+0xa6ba] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_call_policy)));
x86_l_364:
	/* 0x364: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_367:
	/* 0x367: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_369:
	/* 0x369: mov    r15d,0xcb */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 203ULL);
x86_l_36f:
	/* 0x36f: jmp    4c <tail_handle_ipv4_cont_from_netdev+0x4c> */
	X86_SIM_X86_JMP(0x36f, 0x4c, x86_l_4c);
x86_l_374:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
