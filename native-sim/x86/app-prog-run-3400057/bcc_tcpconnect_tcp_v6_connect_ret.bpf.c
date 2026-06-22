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
	/* 0xa: sub    rsp,0x58 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 88ULL);
x86_l_e:
	/* 0xe: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_11:
	/* 0x11: mov    r14d,DWORD PTR [rdi+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_15:
	/* 0x15: call   1a <tcp_v6_connect_ret+0x1a> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_get_current_pid_tgid);
x86_l_1a:
	/* 0x1a: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1d:
	/* 0x1d: mov    DWORD PTR [rsp+0xc],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_22:
	/* 0x22: mov    WORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_29:
	/* 0x29: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sockets)));
x86_l_30:
	/* 0x30: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_35:
	/* 0x35: call   3a <tcp_v6_connect_ret+0x3a> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_3a:
	/* 0x3a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3d:
	/* 0x3d: je     55 <tcp_v6_connect_ret+0x55> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3d, 0x55, x86_l_55);
x86_l_3f:
	/* 0x3f: test   r14,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64);
x86_l_42:
	/* 0x42: je     6a <tcp_v6_connect_ret+0x6a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x42, 0x6a, x86_l_6a);
x86_l_44:
	/* 0x44: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sockets)));
x86_l_4b:
	/* 0x4b: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_50:
	/* 0x50: call   55 <tcp_v6_connect_ret+0x55> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_map_delete_elem);
x86_l_55:
	/* 0x55: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_57:
	/* 0x57: add    rsp,0x58 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 88ULL);
x86_l_5b:
	/* 0x5b: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_5c:
	/* 0x5c: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_5e:
	/* 0x5e: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_60:
	/* 0x60: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_62:
	/* 0x62: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_64:
	/* 0x64: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_65:
	/* 0x65: jmp    2c4 <tcp_v6_connect_ret+0x2c4> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_6a:
	/* 0x6a: mov    r14,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6d:
	/* 0x6d: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&source_port)));
x86_l_74:
	/* 0x74: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_77:
	/* 0x77: je     8c <tcp_v6_connect_ret+0x8c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x77, 0x8c, x86_l_8c);
x86_l_79:
	/* 0x79: lea    rdx,[r14+0xe] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_7d:
	/* 0x7d: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_82:
	/* 0x82: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_87:
	/* 0x87: call   8c <tcp_v6_connect_ret+0x8c> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_8c:
	/* 0x8c: lea    rdx,[r14+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_90:
	/* 0x90: lea    rdi,[rsp+0xa] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 10ULL);
x86_l_95:
	/* 0x95: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_9a:
	/* 0x9a: call   9f <tcp_v6_connect_ret+0x9f> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_9f:
	/* 0x9f: movzx  ebp,WORD PTR [rsp+0xa] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 10ULL);
x86_l_a4:
	/* 0xa4: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&filter_ports_len)));
x86_l_ab:
	/* 0xab: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ae:
	/* 0xae: je     e2 <tcp_v6_connect_ret+0xe2> */
	X86_SIM_X86_JCC(X86_CC_E, 0xae, 0xe2, x86_l_e2);
x86_l_b0:
	/* 0xb0: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b3:
	/* 0xb3: jle    44 <tcp_v6_connect_ret+0x44> */
	X86_SIM_X86_JCC(X86_CC_LE, 0xb3, 0x44, x86_l_44);
x86_l_b5:
	/* 0xb5: movzx  ecx,bp */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RBP, X86_WIDTH_32, X86_WIDTH_16);
x86_l_b8:
	/* 0xb8: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ba:
	/* 0xba: mov    rsi,QWORD PTR [rip+0xfffffffffffffffc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&filter_ports)));
x86_l_c1:
	/* 0xc1: mov    edi,DWORD PTR [rsi+rdx*4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RDX, 2), 0ULL);
x86_l_c4:
	/* 0xc4: cmp    edi,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RCX, X86_WIDTH_32);
x86_l_c6:
	/* 0xc6: je     e2 <tcp_v6_connect_ret+0xe2> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc6, 0xe2, x86_l_e2);
x86_l_c8:
	/* 0xc8: movsxd rdi,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RDI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_cb:
	/* 0xcb: cmp    rdx,0x3e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_64, 62ULL);
x86_l_cf:
	/* 0xcf: ja     44 <tcp_v6_connect_ret+0x44> */
	X86_SIM_X86_JCC(X86_CC_A, 0xcf, 0x44, x86_l_44);
x86_l_d5:
	/* 0xd5: inc    rdx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_d8:
	/* 0xd8: cmp    rdx,rdi */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_db:
	/* 0xdb: jl     c1 <tcp_v6_connect_ret+0xc1> */
	X86_SIM_X86_JCC(X86_CC_L, 0xdb, 0xc1, x86_l_c1);
x86_l_dd:
	/* 0xdd: jmp    44 <tcp_v6_connect_ret+0x44> */
	X86_SIM_X86_JMP(0xdd, 0x44, x86_l_44);
x86_l_e2:
	/* 0xe2: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&do_count)));
x86_l_e9:
	/* 0xe9: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ec:
	/* 0xec: movzx  r12d,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_f2:
	/* 0xf2: je     17f <tcp_v6_connect_ret+0x17f> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf2, 0x17f, x86_l_17f);
x86_l_f8:
	/* 0xf8: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_100:
	/* 0x100: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_109:
	/* 0x109: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_112:
	/* 0x112: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_11b:
	/* 0x11b: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_124:
	/* 0x124: lea    rbx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_129:
	/* 0x129: lea    rdx,[r14+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_12d:
	/* 0x12d: lea    r15,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_132:
	/* 0x132: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_135:
	/* 0x135: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_13a:
	/* 0x13a: call   13f <tcp_v6_connect_ret+0x13f> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_13f:
	/* 0x13f: add    r14,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 56ULL);
x86_l_143:
	/* 0x143: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_146:
	/* 0x146: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_14b:
	/* 0x14b: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_14e:
	/* 0x14e: call   153 <tcp_v6_connect_ret+0x153> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_153:
	/* 0x153: mov    WORD PTR [rsp+0x30],r12w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_159:
	/* 0x159: mov    WORD PTR [rsp+0x32],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 50ULL);
x86_l_15e:
	/* 0x15e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&ipv6_count)));
x86_l_165:
	/* 0x165: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_168:
	/* 0x168: call   16d <tcp_v6_connect_ret+0x16d> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_16d:
	/* 0x16d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_170:
	/* 0x170: je     279 <tcp_v6_connect_ret+0x279> */
	X86_SIM_X86_JCC(X86_CC_E, 0x170, 0x279, x86_l_279);
x86_l_176:
	/* 0x176: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_17a:
	/* 0x17a: jmp    44 <tcp_v6_connect_ret+0x44> */
	X86_SIM_X86_JMP(0x17a, 0x44, x86_l_44);
x86_l_17f:
	/* 0x17f: shr    r15,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_183:
	/* 0x183: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_18c:
	/* 0x18c: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_195:
	/* 0x195: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_19e:
	/* 0x19e: mov    QWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_1a7:
	/* 0x1a7: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1b0:
	/* 0x1b0: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1b9:
	/* 0x1b9: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_1c2:
	/* 0x1c2: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_1cb:
	/* 0x1cb: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1d4:
	/* 0x1d4: lea    r13,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1d9:
	/* 0x1d9: mov    DWORD PTR [rsp+0x48],0xa */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 309237645322ULL);
x86_l_1e1:
	/* 0x1e1: mov    DWORD PTR [rsp+0x4c],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_1e6:
	/* 0x1e6: call   1eb <tcp_v6_connect_ret+0x1eb> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_get_current_uid_gid);
x86_l_1eb:
	/* 0x1eb: mov    DWORD PTR [rsp+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1ef:
	/* 0x1ef: call   1f4 <tcp_v6_connect_ret+0x1f4> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_ktime_get_ns);
x86_l_1f4:
	/* 0x1f4: shr    rax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 3ULL);
x86_l_1f8:
	/* 0x1f8: movabs rcx,0x20c49ba5e353f7cf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2361183241434822607ULL);
x86_l_202:
	/* 0x202: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_205:
	/* 0x205: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_20a:
	/* 0x20a: shr    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 4ULL);
x86_l_20e:
	/* 0x20e: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_213:
	/* 0x213: lea    rdx,[r14+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_217:
	/* 0x217: lea    r15,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_21c:
	/* 0x21c: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_21f:
	/* 0x21f: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_224:
	/* 0x224: call   229 <tcp_v6_connect_ret+0x229> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_229:
	/* 0x229: add    r14,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 56ULL);
x86_l_22d:
	/* 0x22d: mov    rdi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R13, X86_WIDTH_64);
x86_l_230:
	/* 0x230: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_235:
	/* 0x235: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_238:
	/* 0x238: call   23d <tcp_v6_connect_ret+0x23d> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_23d:
	/* 0x23d: mov    WORD PTR [rsp+0x54],r12w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 84ULL);
x86_l_243:
	/* 0x243: mov    WORD PTR [rsp+0x56],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 86ULL);
x86_l_248:
	/* 0x248: lea    rdi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_24d:
	/* 0x24d: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_252:
	/* 0x252: call   257 <tcp_v6_connect_ret+0x257> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_get_current_comm);
x86_l_257:
	/* 0x257: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&events)));
x86_l_25e:
	/* 0x25e: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_263:
	/* 0x263: mov    r8d,0x48 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 72ULL);
x86_l_269:
	/* 0x269: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_26c:
	/* 0x26c: mov    rcx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_26f:
	/* 0x26f: call   274 <tcp_v6_connect_ret+0x274> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_perf_event_output);
x86_l_274:
	/* 0x274: jmp    44 <tcp_v6_connect_ret+0x44> */
	X86_SIM_X86_JMP(0x274, 0x44, x86_l_44);
x86_l_279:
	/* 0x279: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&ipv6_count)));
x86_l_280:
	/* 0x280: lea    rdx,[rip+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 0ULL);
x86_l_287:
	/* 0x287: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_28c:
	/* 0x28c: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_291:
	/* 0x291: call   296 <tcp_v6_connect_ret+0x296> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_map_update_elem);
x86_l_296:
	/* 0x296: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_299:
	/* 0x299: je     2a5 <tcp_v6_connect_ret+0x2a5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x299, 0x2a5, x86_l_2a5);
x86_l_29b:
	/* 0x29b: cmp    rax,0xffffffffffffffef */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 18446744073709551599ULL);
x86_l_29f:
	/* 0x29f: jne    44 <tcp_v6_connect_ret+0x44> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x29f, 0x44, x86_l_44);
x86_l_2a5:
	/* 0x2a5: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&ipv6_count)));
x86_l_2ac:
	/* 0x2ac: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b1:
	/* 0x2b1: call   2b6 <tcp_v6_connect_ret+0x2b6> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_2b6:
	/* 0x2b6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b9:
	/* 0x2b9: jne    176 <tcp_v6_connect_ret+0x176> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2b9, 0x176, x86_l_176);
x86_l_2bf:
	/* 0x2bf: jmp    44 <tcp_v6_connect_ret+0x44> */
	X86_SIM_X86_JMP(0x2bf, 0x44, x86_l_44);
x86_l_2c4:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
