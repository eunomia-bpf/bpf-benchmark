extern char __config_nodeport_port_max;
extern char __config_nodeport_port_min;
extern char cilium_ipcache_v2;
extern char cilium_lb4_reverse_sk;
extern char cilium_lb4_services_v2;
extern char cilium_metrics;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int cilium_bpf_sock_cil_sock6_recvmsg_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0x5: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_7:
	/* 0x7: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_8:
	/* 0x8: sub    rsp,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 64ULL);
x86_l_c:
	/* 0xc: mov    ecx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f:
	/* 0xf: mov    edx,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_12:
	/* 0x12: mov    eax,DWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15:
	/* 0x15: mov    r14d,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_19:
	/* 0x19: or     edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_1b:
	/* 0x1b: jne    2f2 <cil_sock6_recvmsg+0x2f2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1b, 0x2f2, x86_l_2f2);
x86_l_21:
	/* 0x21: cmp    eax,0xffff0000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294901760ULL);
x86_l_26:
	/* 0x26: jne    2f2 <cil_sock6_recvmsg+0x2f2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x26, 0x2f2, x86_l_2f2);
x86_l_2c:
	/* 0x2c: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_2f:
	/* 0x2f: mov    ebp,DWORD PTR [rdi+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_32:
	/* 0x32: mov    eax,DWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_35:
	/* 0x35: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_39:
	/* 0x39: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3d:
	/* 0x3d: movzx  eax,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_40:
	/* 0x40: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_44:
	/* 0x44: mov    r15d,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_49:
	/* 0x49: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_4e:
	/* 0x4e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_50:
	/* 0x50: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_55:
	/* 0x55: mov    DWORD PTR [rsp+0x30],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5a:
	/* 0x5a: mov    WORD PTR [rsp+0x34],r15w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_60:
	/* 0x60: mov    WORD PTR [rsp+0x36],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 231928233984ULL);
x86_l_67:
	/* 0x67: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_6c:
	/* 0x6c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_reverse_sk)));
x86_l_73:
	/* 0x73: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_78:
	/* 0x78: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7a:
	/* 0x7a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7d:
	/* 0x7d: je     2f2 <cil_sock6_recvmsg+0x2f2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7d, 0x2f2, x86_l_2f2);
x86_l_83:
	/* 0x83: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_86:
	/* 0x86: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_88:
	/* 0x88: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_8c:
	/* 0x8c: movzx  eax,WORD PTR [r14+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_91:
	/* 0x91: mov    WORD PTR [rsp+0x8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_96:
	/* 0x96: mov    BYTE PTR [rsp+0xc],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_9b:
	/* 0x9b: mov    WORD PTR [rsp+0xe],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 60129542144ULL);
x86_l_a2:
	/* 0xa2: mov    WORD PTR [rsp+0xa],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 42949672960ULL);
x86_l_a9:
	/* 0xa9: mov    BYTE PTR [rsp+0xd],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 55834574848ULL);
x86_l_ae:
	/* 0xae: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b3:
	/* 0xb3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_services_v2)));
x86_l_ba:
	/* 0xba: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_bf:
	/* 0xbf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c1:
	/* 0xc1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c4:
	/* 0xc4: je     12b <cil_sock6_recvmsg+0x12b> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc4, 0x12b, x86_l_12b);
x86_l_c6:
	/* 0xc6: test   BYTE PTR [rax+0x9],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38654705696ULL);
x86_l_ca:
	/* 0xca: je     e9 <cil_sock6_recvmsg+0xe9> */
	X86_SIM_X86_JCC(X86_CC_E, 0xca, 0xe9, x86_l_e9);
x86_l_cc:
	/* 0xcc: mov    BYTE PTR [rsp+0xd],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 55834574849ULL);
x86_l_d1:
	/* 0xd1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d6:
	/* 0xd6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_services_v2)));
x86_l_dd:
	/* 0xdd: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_e2:
	/* 0xe2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e4:
	/* 0xe4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e7:
	/* 0xe7: je     12b <cil_sock6_recvmsg+0x12b> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe7, 0x12b, x86_l_12b);
x86_l_e9:
	/* 0xe9: movzx  ecx,WORD PTR [rax+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_ed:
	/* 0xed: cmp    cx,WORD PTR [r14+0x6] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_R14, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_f2:
	/* 0xf2: jne    287 <cil_sock6_recvmsg+0x287> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf2, 0x287, x86_l_287);
x86_l_f8:
	/* 0xf8: cmp    WORD PTR [rax+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_fd:
	/* 0xfd: je     287 <cil_sock6_recvmsg+0x287> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfd, 0x287, x86_l_287);
x86_l_103:
	/* 0x103: mov    eax,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_106:
	/* 0x106: movzx  ecx,WORD PTR [r14+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_10b:
	/* 0x10b: mov    DWORD PTR [rbx+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_112:
	/* 0x112: mov    DWORD PTR [rbx+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_119:
	/* 0x119: mov    DWORD PTR [rbx+0x10],0xffff0000 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 73014378496ULL);
x86_l_120:
	/* 0x120: mov    DWORD PTR [rbx+0x14],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_123:
	/* 0x123: mov    DWORD PTR [rbx+0x18],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_126:
	/* 0x126: jmp    2f2 <cil_sock6_recvmsg+0x2f2> */
	X86_SIM_X86_JMP(0x126, 0x2f2, x86_l_2f2);
x86_l_12b:
	/* 0x12b: mov    eax,0x7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 122ULL);
x86_l_130:
	/* 0x130: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_133:
	/* 0x133: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_135:
	/* 0x135: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_138:
	/* 0x138: mov    eax,0x7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 122ULL);
x86_l_13d:
	/* 0x13d: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_140:
	/* 0x140: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_142:
	/* 0x142: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_144:
	/* 0x144: mov    ecx,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_148:
	/* 0x148: movbe  dx,WORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOVBE_LOAD, X86_RDX, X86_RSP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_14f:
	/* 0x14f: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_nodeport_port_min)));
x86_l_156:
	/* 0x156: cmp    dx,WORD PTR [rsi] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSI, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_159:
	/* 0x159: jb     169 <cil_sock6_recvmsg+0x169> */
	X86_SIM_X86_JCC(X86_CC_B, 0x159, 0x169, x86_l_169);
x86_l_15b:
	/* 0x15b: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_nodeport_port_max)));
x86_l_162:
	/* 0x162: cmp    dx,WORD PTR [rsi] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSI, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_165:
	/* 0x165: setbe  r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_BE);
x86_l_169:
	/* 0x169: movzx  ebp,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_16c:
	/* 0x16c: cmp    r15,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_16f:
	/* 0x16f: jne    1e8 <cil_sock6_recvmsg+0x1e8> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x16f, 0x1e8, x86_l_1e8);
x86_l_171:
	/* 0x171: cmp    ebp,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 127ULL);
x86_l_174:
	/* 0x174: jne    1e8 <cil_sock6_recvmsg+0x1e8> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x174, 0x1e8, x86_l_1e8);
x86_l_176:
	/* 0x176: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_17e:
	/* 0x17e: mov    WORD PTR [rsp+0xa],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 42949672960ULL);
x86_l_185:
	/* 0x185: mov    BYTE PTR [rsp+0xd],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 55834574848ULL);
x86_l_18a:
	/* 0x18a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_18f:
	/* 0x18f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_services_v2)));
x86_l_196:
	/* 0x196: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_19b:
	/* 0x19b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19d:
	/* 0x19d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a0:
	/* 0x1a0: je     287 <cil_sock6_recvmsg+0x287> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a0, 0x287, x86_l_287);
x86_l_1a6:
	/* 0x1a6: test   BYTE PTR [rax+0x9],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38654705696ULL);
x86_l_1aa:
	/* 0x1aa: je     1cd <cil_sock6_recvmsg+0x1cd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1aa, 0x1cd, x86_l_1cd);
x86_l_1ac:
	/* 0x1ac: mov    BYTE PTR [rsp+0xd],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 55834574849ULL);
x86_l_1b1:
	/* 0x1b1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1b6:
	/* 0x1b6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_services_v2)));
x86_l_1bd:
	/* 0x1bd: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1c2:
	/* 0x1c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c4:
	/* 0x1c4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1c7:
	/* 0x1c7: je     287 <cil_sock6_recvmsg+0x287> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1c7, 0x287, x86_l_287);
x86_l_1cd:
	/* 0x1cd: movzx  ecx,BYTE PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_1d1:
	/* 0x1d1: test   r12b,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_8);
x86_l_1d4:
	/* 0x1d4: je     265 <cil_sock6_recvmsg+0x265> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1d4, 0x265, x86_l_265);
x86_l_1da:
	/* 0x1da: test   cl,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_1dd:
	/* 0x1dd: jne    e9 <cil_sock6_recvmsg+0xe9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1dd, 0xe9, x86_l_e9);
x86_l_1e3:
	/* 0x1e3: jmp    287 <cil_sock6_recvmsg+0x287> */
	X86_SIM_X86_JMP(0x1e3, 0x287, x86_l_287);
x86_l_1e8:
	/* 0x1e8: mov    QWORD PTR [rsp+0x16],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 94489280512ULL);
x86_l_1f1:
	/* 0x1f1: mov    WORD PTR [rsp+0x26],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 163208757248ULL);
x86_l_1f8:
	/* 0x1f8: mov    QWORD PTR [rsp+0x1e],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128849018880ULL);
x86_l_201:
	/* 0x201: mov    DWORD PTR [rsp+0x10],0x40 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476800ULL);
x86_l_209:
	/* 0x209: mov    BYTE PTR [rsp+0x17],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 98784247809ULL);
x86_l_20e:
	/* 0x20e: mov    DWORD PTR [rsp+0x18],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_212:
	/* 0x212: mov    WORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_219:
	/* 0x219: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_21e:
	/* 0x21e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipcache_v2)));
x86_l_225:
	/* 0x225: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_22a:
	/* 0x22a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22c:
	/* 0x22c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_22f:
	/* 0x22f: je     287 <cil_sock6_recvmsg+0x287> */
	X86_SIM_X86_JCC(X86_CC_E, 0x22f, 0x287, x86_l_287);
x86_l_231:
	/* 0x231: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_233:
	/* 0x233: test   r12b,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_8);
x86_l_236:
	/* 0x236: je     27e <cil_sock6_recvmsg+0x27e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x236, 0x27e, x86_l_27e);
x86_l_238:
	/* 0x238: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_23b:
	/* 0x23b: je     176 <cil_sock6_recvmsg+0x176> */
	X86_SIM_X86_JCC(X86_CC_E, 0x23b, 0x176, x86_l_176);
x86_l_241:
	/* 0x241: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_243:
	/* 0x243: and    edx,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_246:
	/* 0x246: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_249:
	/* 0x249: je     259 <cil_sock6_recvmsg+0x259> */
	X86_SIM_X86_JCC(X86_CC_E, 0x249, 0x259, x86_l_259);
x86_l_24b:
	/* 0x24b: and    ecx,0xff000000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4278190080ULL);
x86_l_251:
	/* 0x251: cmp    ecx,0x2000000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 33554432ULL);
x86_l_257:
	/* 0x257: jne    287 <cil_sock6_recvmsg+0x287> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x257, 0x287, x86_l_287);
x86_l_259:
	/* 0x259: test   BYTE PTR [rax+0x17],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 98784247816ULL);
x86_l_25d:
	/* 0x25d: je     176 <cil_sock6_recvmsg+0x176> */
	X86_SIM_X86_JCC(X86_CC_E, 0x25d, 0x176, x86_l_176);
x86_l_263:
	/* 0x263: jmp    287 <cil_sock6_recvmsg+0x287> */
	X86_SIM_X86_JMP(0x263, 0x287, x86_l_287);
x86_l_265:
	/* 0x265: test   cl,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 8ULL);
x86_l_268:
	/* 0x268: je     287 <cil_sock6_recvmsg+0x287> */
	X86_SIM_X86_JCC(X86_CC_E, 0x268, 0x287, x86_l_287);
x86_l_26a:
	/* 0x26a: test   BYTE PTR [rax+0x9],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38654705672ULL);
x86_l_26e:
	/* 0x26e: je     e9 <cil_sock6_recvmsg+0xe9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x26e, 0xe9, x86_l_e9);
x86_l_274:
	/* 0x274: cmp    ebp,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 127ULL);
x86_l_277:
	/* 0x277: jne    287 <cil_sock6_recvmsg+0x287> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x277, 0x287, x86_l_287);
x86_l_279:
	/* 0x279: jmp    e9 <cil_sock6_recvmsg+0xe9> */
	X86_SIM_X86_JMP(0x279, 0xe9, x86_l_e9);
x86_l_27e:
	/* 0x27e: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_281:
	/* 0x281: je     176 <cil_sock6_recvmsg+0x176> */
	X86_SIM_X86_JCC(X86_CC_E, 0x281, 0x176, x86_l_176);
x86_l_287:
	/* 0x287: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_28c:
	/* 0x28c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_reverse_sk)));
x86_l_293:
	/* 0x293: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_298:
	/* 0x298: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29a:
	/* 0x29a: movabs rax,0x502640108 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 21514944776ULL);
x86_l_2a4:
	/* 0x2a4: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2a9:
	/* 0x2a9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2ae:
	/* 0x2ae: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_2b5:
	/* 0x2b5: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2ba:
	/* 0x2ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bc:
	/* 0x2bc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2bf:
	/* 0x2bf: je     2c6 <cil_sock6_recvmsg+0x2c6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2bf, 0x2c6, x86_l_2c6);
x86_l_2c1:
	/* 0x2c1: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2c4:
	/* 0x2c4: jmp    2f2 <cil_sock6_recvmsg+0x2f2> */
	X86_SIM_X86_JMP(0x2c4, 0x2f2, x86_l_2f2);
x86_l_2c6:
	/* 0x2c6: mov    QWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_2cf:
	/* 0x2cf: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_2d8:
	/* 0x2d8: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2dd:
	/* 0x2dd: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_2e4:
	/* 0x2e4: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2e9:
	/* 0x2e9: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ee:
	/* 0x2ee: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2f0:
	/* 0x2f0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f2:
	/* 0x2f2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f7:
	/* 0x2f7: add    rsp,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_2fb:
	/* 0x2fb: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_2fc:
	/* 0x2fc: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_2fe:
	/* 0x2fe: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_300:
	/* 0x300: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_302:
	/* 0x302: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_303:
	/* 0x303: jmp    308 <cil_sock6_recvmsg+0x308> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_308:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
