extern char do_count;
extern char events;
extern char filter_ports;
extern char filter_ports_len;
extern char ipv6_count;
extern char sockets;
extern char source_port;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

static const __u64 __x86_rodata_0[2] = {18446744069414584320ULL, 0ULL};

SEC("xdp")
int bcc_tcpconnect_tcp_v6_connect_ret_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0x58 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 88ULL);
x86_l_7:
	/* 0x7: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_a:
	/* 0xa: mov    r14d,DWORD PTR [rdi+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_e:
	/* 0xe: call   13 <tcp_v6_connect_ret+0x13> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_get_current_pid_tgid);
x86_l_13:
	/* 0x13: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_16:
	/* 0x16: mov    DWORD PTR [rsp+0xc],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_1b:
	/* 0x1b: mov    WORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_22:
	/* 0x22: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sockets)));
x86_l_29:
	/* 0x29: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2e:
	/* 0x2e: call   33 <tcp_v6_connect_ret+0x33> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_33:
	/* 0x33: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_36:
	/* 0x36: je     4e <tcp_v6_connect_ret+0x4e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x36, 0x4e, x86_l_4e);
x86_l_38:
	/* 0x38: test   r14,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64);
x86_l_3b:
	/* 0x3b: je     5c <tcp_v6_connect_ret+0x5c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3b, 0x5c, x86_l_5c);
x86_l_3d:
	/* 0x3d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sockets)));
x86_l_44:
	/* 0x44: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_49:
	/* 0x49: call   4e <tcp_v6_connect_ret+0x4e> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_map_delete_elem);
x86_l_4e:
	/* 0x4e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_50:
	/* 0x50: add    rsp,0x58 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 88ULL);
x86_l_54:
	/* 0x54: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_56:
	/* 0x56: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_57:
	/* 0x57: jmp    2b6 <tcp_v6_connect_ret+0x2b6> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_5c:
	/* 0x5c: mov    r14,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5f:
	/* 0x5f: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&source_port)));
x86_l_66:
	/* 0x66: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_69:
	/* 0x69: je     7e <tcp_v6_connect_ret+0x7e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x69, 0x7e, x86_l_7e);
x86_l_6b:
	/* 0x6b: lea    rdx,[r14+0xe] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_6f:
	/* 0x6f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_74:
	/* 0x74: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_79:
	/* 0x79: call   7e <tcp_v6_connect_ret+0x7e> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_7e:
	/* 0x7e: lea    rdx,[r14+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_82:
	/* 0x82: lea    rdi,[rsp+0xa] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 10ULL);
x86_l_87:
	/* 0x87: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_8c:
	/* 0x8c: call   91 <tcp_v6_connect_ret+0x91> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_91:
	/* 0x91: movzx  ebp,WORD PTR [rsp+0xa] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 10ULL);
x86_l_96:
	/* 0x96: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&filter_ports_len)));
x86_l_9d:
	/* 0x9d: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a0:
	/* 0xa0: je     d4 <tcp_v6_connect_ret+0xd4> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa0, 0xd4, x86_l_d4);
x86_l_a2:
	/* 0xa2: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a5:
	/* 0xa5: jle    3d <tcp_v6_connect_ret+0x3d> */
	X86_SIM_X86_JCC(X86_CC_LE, 0xa5, 0x3d, x86_l_3d);
x86_l_a7:
	/* 0xa7: movzx  ecx,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_aa:
	/* 0xaa: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ac:
	/* 0xac: mov    rsi,QWORD PTR [rip+0xa] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&filter_ports)));
x86_l_b3:
	/* 0xb3: mov    edi,DWORD PTR [rsi+rdx*4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 2), 0ULL);
x86_l_b6:
	/* 0xb6: cmp    edi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RCX, X86_WIDTH_32);
x86_l_b8:
	/* 0xb8: je     d4 <tcp_v6_connect_ret+0xd4> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb8, 0xd4, x86_l_d4);
x86_l_ba:
	/* 0xba: movsxd rdi,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_bd:
	/* 0xbd: cmp    rdx,0x3e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 62ULL);
x86_l_c1:
	/* 0xc1: ja     3d <tcp_v6_connect_ret+0x3d> */
	X86_SIM_X86_JCC(X86_CC_A, 0xc1, 0x3d, x86_l_3d);
x86_l_c7:
	/* 0xc7: inc    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_ca:
	/* 0xca: cmp    rdx,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_cd:
	/* 0xcd: jl     b3 <tcp_v6_connect_ret+0xb3> */
	X86_SIM_X86_JCC(X86_CC_L, 0xcd, 0xb3, x86_l_b3);
x86_l_cf:
	/* 0xcf: jmp    3d <tcp_v6_connect_ret+0x3d> */
	X86_SIM_X86_JMP(0xcf, 0x3d, x86_l_3d);
x86_l_d4:
	/* 0xd4: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&do_count)));
x86_l_db:
	/* 0xdb: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_de:
	/* 0xde: movzx  r12d,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_e4:
	/* 0xe4: je     171 <tcp_v6_connect_ret+0x171> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe4, 0x171, x86_l_171);
x86_l_ea:
	/* 0xea: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_f2:
	/* 0xf2: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_fb:
	/* 0xfb: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_104:
	/* 0x104: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_10d:
	/* 0x10d: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_116:
	/* 0x116: lea    rbx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_11b:
	/* 0x11b: lea    rdx,[r14+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_11f:
	/* 0x11f: lea    r15,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_124:
	/* 0x124: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_127:
	/* 0x127: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_12c:
	/* 0x12c: call   131 <tcp_v6_connect_ret+0x131> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_131:
	/* 0x131: add    r14,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 56ULL);
x86_l_135:
	/* 0x135: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_138:
	/* 0x138: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_13d:
	/* 0x13d: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_140:
	/* 0x140: call   145 <tcp_v6_connect_ret+0x145> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_145:
	/* 0x145: mov    WORD PTR [rsp+0x30],r12w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_14b:
	/* 0x14b: mov    WORD PTR [rsp+0x32],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 50ULL);
x86_l_150:
	/* 0x150: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&ipv6_count)));
x86_l_157:
	/* 0x157: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_15a:
	/* 0x15a: call   15f <tcp_v6_connect_ret+0x15f> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_15f:
	/* 0x15f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_162:
	/* 0x162: je     26b <tcp_v6_connect_ret+0x26b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x162, 0x26b, x86_l_26b);
x86_l_168:
	/* 0x168: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_16c:
	/* 0x16c: jmp    3d <tcp_v6_connect_ret+0x3d> */
	X86_SIM_X86_JMP(0x16c, 0x3d, x86_l_3d);
x86_l_171:
	/* 0x171: shr    r15,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_175:
	/* 0x175: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_17e:
	/* 0x17e: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_187:
	/* 0x187: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_190:
	/* 0x190: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_199:
	/* 0x199: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1a2:
	/* 0x1a2: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1ab:
	/* 0x1ab: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1b4:
	/* 0x1b4: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1bd:
	/* 0x1bd: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1c6:
	/* 0x1c6: lea    r13,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1cb:
	/* 0x1cb: mov    DWORD PTR [rsp+0x48],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 309237645322ULL);
x86_l_1d3:
	/* 0x1d3: mov    DWORD PTR [rsp+0x4c],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_1d8:
	/* 0x1d8: call   1dd <tcp_v6_connect_ret+0x1dd> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_get_current_uid_gid);
x86_l_1dd:
	/* 0x1dd: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1e1:
	/* 0x1e1: call   1e6 <tcp_v6_connect_ret+0x1e6> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_ktime_get_ns);
x86_l_1e6:
	/* 0x1e6: shr    rax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 3ULL);
x86_l_1ea:
	/* 0x1ea: movabs rcx,0x20c49ba5e353f7cf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2361183241434822607ULL);
x86_l_1f4:
	/* 0x1f4: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1f7:
	/* 0x1f7: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_1fc:
	/* 0x1fc: shr    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 4ULL);
x86_l_200:
	/* 0x200: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_205:
	/* 0x205: lea    rdx,[r14+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_209:
	/* 0x209: lea    r15,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20e:
	/* 0x20e: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_211:
	/* 0x211: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_216:
	/* 0x216: call   21b <tcp_v6_connect_ret+0x21b> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_21b:
	/* 0x21b: add    r14,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 56ULL);
x86_l_21f:
	/* 0x21f: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_222:
	/* 0x222: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_227:
	/* 0x227: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_22a:
	/* 0x22a: call   22f <tcp_v6_connect_ret+0x22f> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_22f:
	/* 0x22f: mov    WORD PTR [rsp+0x54],r12w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_235:
	/* 0x235: mov    WORD PTR [rsp+0x56],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_23a:
	/* 0x23a: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_23f:
	/* 0x23f: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_244:
	/* 0x244: call   249 <tcp_v6_connect_ret+0x249> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_get_current_comm);
x86_l_249:
	/* 0x249: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&events)));
x86_l_250:
	/* 0x250: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_255:
	/* 0x255: mov    r8d,0x48 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 72ULL);
x86_l_25b:
	/* 0x25b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_25e:
	/* 0x25e: mov    rcx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_261:
	/* 0x261: call   266 <tcp_v6_connect_ret+0x266> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_perf_event_output);
x86_l_266:
	/* 0x266: jmp    3d <tcp_v6_connect_ret+0x3d> */
	X86_SIM_X86_JMP(0x266, 0x3d, x86_l_3d);
x86_l_26b:
	/* 0x26b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&ipv6_count)));
x86_l_272:
	/* 0x272: lea    rdx,[rip+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 0ULL);
x86_l_279:
	/* 0x279: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_27e:
	/* 0x27e: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_283:
	/* 0x283: call   288 <tcp_v6_connect_ret+0x288> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_map_update_elem);
x86_l_288:
	/* 0x288: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_28b:
	/* 0x28b: je     297 <tcp_v6_connect_ret+0x297> */
	X86_SIM_X86_JCC(X86_CC_E, 0x28b, 0x297, x86_l_297);
x86_l_28d:
	/* 0x28d: cmp    rax,0xffffffffffffffef */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 18446744073709551599ULL);
x86_l_291:
	/* 0x291: jne    3d <tcp_v6_connect_ret+0x3d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x291, 0x3d, x86_l_3d);
x86_l_297:
	/* 0x297: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&ipv6_count)));
x86_l_29e:
	/* 0x29e: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a3:
	/* 0x2a3: call   2a8 <tcp_v6_connect_ret+0x2a8> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_2a8:
	/* 0x2a8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2ab:
	/* 0x2ab: jne    168 <tcp_v6_connect_ret+0x168> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2ab, 0x168, x86_l_168);
x86_l_2b1:
	/* 0x2b1: jmp    3d <tcp_v6_connect_ret+0x3d> */
	X86_SIM_X86_JMP(0x2b1, 0x3d, x86_l_3d);
x86_l_2b6:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
