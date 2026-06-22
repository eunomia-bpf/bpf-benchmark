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
	/* 0x1: sub    rsp,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 64ULL);
x86_l_5:
	/* 0x5: mov    ecx,DWORD PTR [rdi+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8:
	/* 0x8: mov    edx,DWORD PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_b:
	/* 0xb: mov    eax,DWORD PTR [rdi+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e:
	/* 0xe: mov    r14d,DWORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_12:
	/* 0x12: or     edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_14:
	/* 0x14: jne    2eb <cil_sock6_recvmsg+0x2eb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x14, 0x2eb, x86_l_2eb);
x86_l_1a:
	/* 0x1a: cmp    eax,0xffff0000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294901760ULL);
x86_l_1f:
	/* 0x1f: jne    2eb <cil_sock6_recvmsg+0x2eb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1f, 0x2eb, x86_l_2eb);
x86_l_25:
	/* 0x25: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_28:
	/* 0x28: mov    ebp,DWORD PTR [rdi+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2b:
	/* 0x2b: mov    eax,DWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2e:
	/* 0x2e: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_32:
	/* 0x32: mov    eax,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_36:
	/* 0x36: movzx  eax,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_39:
	/* 0x39: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3d:
	/* 0x3d: mov    r15d,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_42:
	/* 0x42: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_47:
	/* 0x47: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_49:
	/* 0x49: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4e:
	/* 0x4e: mov    DWORD PTR [rsp+0x30],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_53:
	/* 0x53: mov    WORD PTR [rsp+0x34],r15w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_59:
	/* 0x59: mov    WORD PTR [rsp+0x36],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 231928233984ULL);
x86_l_60:
	/* 0x60: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_65:
	/* 0x65: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_reverse_sk)));
x86_l_6c:
	/* 0x6c: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_71:
	/* 0x71: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_73:
	/* 0x73: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_76:
	/* 0x76: je     2eb <cil_sock6_recvmsg+0x2eb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x76, 0x2eb, x86_l_2eb);
x86_l_7c:
	/* 0x7c: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_7f:
	/* 0x7f: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_81:
	/* 0x81: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_85:
	/* 0x85: movzx  eax,WORD PTR [r14+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_8a:
	/* 0x8a: mov    WORD PTR [rsp+0x8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8f:
	/* 0x8f: mov    BYTE PTR [rsp+0xc],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_94:
	/* 0x94: mov    WORD PTR [rsp+0xe],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 60129542144ULL);
x86_l_9b:
	/* 0x9b: mov    WORD PTR [rsp+0xa],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 42949672960ULL);
x86_l_a2:
	/* 0xa2: mov    BYTE PTR [rsp+0xd],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 55834574848ULL);
x86_l_a7:
	/* 0xa7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ac:
	/* 0xac: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_services_v2)));
x86_l_b3:
	/* 0xb3: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_b8:
	/* 0xb8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ba:
	/* 0xba: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_bd:
	/* 0xbd: je     124 <cil_sock6_recvmsg+0x124> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbd, 0x124, x86_l_124);
x86_l_bf:
	/* 0xbf: test   BYTE PTR [rax+0x9],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38654705696ULL);
x86_l_c3:
	/* 0xc3: je     e2 <cil_sock6_recvmsg+0xe2> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc3, 0xe2, x86_l_e2);
x86_l_c5:
	/* 0xc5: mov    BYTE PTR [rsp+0xd],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 55834574849ULL);
x86_l_ca:
	/* 0xca: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_cf:
	/* 0xcf: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_services_v2)));
x86_l_d6:
	/* 0xd6: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_db:
	/* 0xdb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dd:
	/* 0xdd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e0:
	/* 0xe0: je     124 <cil_sock6_recvmsg+0x124> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe0, 0x124, x86_l_124);
x86_l_e2:
	/* 0xe2: movzx  ecx,WORD PTR [rax+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_e6:
	/* 0xe6: cmp    cx,WORD PTR [r14+0x6] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_R14, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_eb:
	/* 0xeb: jne    280 <cil_sock6_recvmsg+0x280> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xeb, 0x280, x86_l_280);
x86_l_f1:
	/* 0xf1: cmp    WORD PTR [rax+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_f6:
	/* 0xf6: je     280 <cil_sock6_recvmsg+0x280> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf6, 0x280, x86_l_280);
x86_l_fc:
	/* 0xfc: mov    eax,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ff:
	/* 0xff: movzx  ecx,WORD PTR [r14+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_104:
	/* 0x104: mov    DWORD PTR [rbx+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_10b:
	/* 0x10b: mov    DWORD PTR [rbx+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_112:
	/* 0x112: mov    DWORD PTR [rbx+0x10],0xffff0000 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 73014378496ULL);
x86_l_119:
	/* 0x119: mov    DWORD PTR [rbx+0x14],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_11c:
	/* 0x11c: mov    DWORD PTR [rbx+0x18],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_11f:
	/* 0x11f: jmp    2eb <cil_sock6_recvmsg+0x2eb> */
	X86_SIM_X86_JMP(0x11f, 0x2eb, x86_l_2eb);
x86_l_124:
	/* 0x124: mov    eax,0x7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 122ULL);
x86_l_129:
	/* 0x129: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_12c:
	/* 0x12c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12e:
	/* 0x12e: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_131:
	/* 0x131: mov    eax,0x7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 122ULL);
x86_l_136:
	/* 0x136: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_139:
	/* 0x139: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13b:
	/* 0x13b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13d:
	/* 0x13d: mov    ecx,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_141:
	/* 0x141: movbe  dx,WORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOVBE_LOAD, X86_RDX, X86_RSP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_148:
	/* 0x148: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_nodeport_port_min)));
x86_l_14f:
	/* 0x14f: cmp    dx,WORD PTR [rsi] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSI, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_152:
	/* 0x152: jb     162 <cil_sock6_recvmsg+0x162> */
	X86_SIM_X86_JCC(X86_CC_B, 0x152, 0x162, x86_l_162);
x86_l_154:
	/* 0x154: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_nodeport_port_max)));
x86_l_15b:
	/* 0x15b: cmp    dx,WORD PTR [rsi] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSI, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_15e:
	/* 0x15e: setbe  r13b */
	X86_SIM_L_EXEC_SETCC(X86_R13, X86_CC_BE);
x86_l_162:
	/* 0x162: movzx  ebp,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_165:
	/* 0x165: cmp    r15,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_168:
	/* 0x168: jne    1e1 <cil_sock6_recvmsg+0x1e1> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x168, 0x1e1, x86_l_1e1);
x86_l_16a:
	/* 0x16a: cmp    ebp,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 127ULL);
x86_l_16d:
	/* 0x16d: jne    1e1 <cil_sock6_recvmsg+0x1e1> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x16d, 0x1e1, x86_l_1e1);
x86_l_16f:
	/* 0x16f: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_177:
	/* 0x177: mov    WORD PTR [rsp+0xa],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 42949672960ULL);
x86_l_17e:
	/* 0x17e: mov    BYTE PTR [rsp+0xd],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 55834574848ULL);
x86_l_183:
	/* 0x183: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_188:
	/* 0x188: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_services_v2)));
x86_l_18f:
	/* 0x18f: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_194:
	/* 0x194: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_196:
	/* 0x196: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_199:
	/* 0x199: je     280 <cil_sock6_recvmsg+0x280> */
	X86_SIM_X86_JCC(X86_CC_E, 0x199, 0x280, x86_l_280);
x86_l_19f:
	/* 0x19f: test   BYTE PTR [rax+0x9],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38654705696ULL);
x86_l_1a3:
	/* 0x1a3: je     1c6 <cil_sock6_recvmsg+0x1c6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a3, 0x1c6, x86_l_1c6);
x86_l_1a5:
	/* 0x1a5: mov    BYTE PTR [rsp+0xd],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 55834574849ULL);
x86_l_1aa:
	/* 0x1aa: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1af:
	/* 0x1af: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_services_v2)));
x86_l_1b6:
	/* 0x1b6: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1bb:
	/* 0x1bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1bd:
	/* 0x1bd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1c0:
	/* 0x1c0: je     280 <cil_sock6_recvmsg+0x280> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1c0, 0x280, x86_l_280);
x86_l_1c6:
	/* 0x1c6: movzx  ecx,BYTE PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_1ca:
	/* 0x1ca: test   r13b,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_8);
x86_l_1cd:
	/* 0x1cd: je     25e <cil_sock6_recvmsg+0x25e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1cd, 0x25e, x86_l_25e);
x86_l_1d3:
	/* 0x1d3: test   cl,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_1d6:
	/* 0x1d6: jne    e2 <cil_sock6_recvmsg+0xe2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1d6, 0xe2, x86_l_e2);
x86_l_1dc:
	/* 0x1dc: jmp    280 <cil_sock6_recvmsg+0x280> */
	X86_SIM_X86_JMP(0x1dc, 0x280, x86_l_280);
x86_l_1e1:
	/* 0x1e1: mov    QWORD PTR [rsp+0x16],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 94489280512ULL);
x86_l_1ea:
	/* 0x1ea: mov    WORD PTR [rsp+0x26],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 163208757248ULL);
x86_l_1f1:
	/* 0x1f1: mov    QWORD PTR [rsp+0x1e],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128849018880ULL);
x86_l_1fa:
	/* 0x1fa: mov    DWORD PTR [rsp+0x10],0x40 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476800ULL);
x86_l_202:
	/* 0x202: mov    BYTE PTR [rsp+0x17],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 98784247809ULL);
x86_l_207:
	/* 0x207: mov    DWORD PTR [rsp+0x18],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_20b:
	/* 0x20b: mov    WORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_212:
	/* 0x212: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_217:
	/* 0x217: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipcache_v2)));
x86_l_21e:
	/* 0x21e: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_223:
	/* 0x223: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_225:
	/* 0x225: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_228:
	/* 0x228: je     280 <cil_sock6_recvmsg+0x280> */
	X86_SIM_X86_JCC(X86_CC_E, 0x228, 0x280, x86_l_280);
x86_l_22a:
	/* 0x22a: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22c:
	/* 0x22c: test   r13b,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_8);
x86_l_22f:
	/* 0x22f: je     277 <cil_sock6_recvmsg+0x277> */
	X86_SIM_X86_JCC(X86_CC_E, 0x22f, 0x277, x86_l_277);
x86_l_231:
	/* 0x231: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_234:
	/* 0x234: je     16f <cil_sock6_recvmsg+0x16f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x234, 0x16f, x86_l_16f);
x86_l_23a:
	/* 0x23a: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_23c:
	/* 0x23c: and    edx,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_23f:
	/* 0x23f: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_242:
	/* 0x242: je     252 <cil_sock6_recvmsg+0x252> */
	X86_SIM_X86_JCC(X86_CC_E, 0x242, 0x252, x86_l_252);
x86_l_244:
	/* 0x244: and    ecx,0xff000000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4278190080ULL);
x86_l_24a:
	/* 0x24a: cmp    ecx,0x2000000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 33554432ULL);
x86_l_250:
	/* 0x250: jne    280 <cil_sock6_recvmsg+0x280> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x250, 0x280, x86_l_280);
x86_l_252:
	/* 0x252: test   BYTE PTR [rax+0x17],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 98784247816ULL);
x86_l_256:
	/* 0x256: je     16f <cil_sock6_recvmsg+0x16f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x256, 0x16f, x86_l_16f);
x86_l_25c:
	/* 0x25c: jmp    280 <cil_sock6_recvmsg+0x280> */
	X86_SIM_X86_JMP(0x25c, 0x280, x86_l_280);
x86_l_25e:
	/* 0x25e: test   cl,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 8ULL);
x86_l_261:
	/* 0x261: je     280 <cil_sock6_recvmsg+0x280> */
	X86_SIM_X86_JCC(X86_CC_E, 0x261, 0x280, x86_l_280);
x86_l_263:
	/* 0x263: test   BYTE PTR [rax+0x9],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38654705672ULL);
x86_l_267:
	/* 0x267: je     e2 <cil_sock6_recvmsg+0xe2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x267, 0xe2, x86_l_e2);
x86_l_26d:
	/* 0x26d: cmp    ebp,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 127ULL);
x86_l_270:
	/* 0x270: jne    280 <cil_sock6_recvmsg+0x280> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x270, 0x280, x86_l_280);
x86_l_272:
	/* 0x272: jmp    e2 <cil_sock6_recvmsg+0xe2> */
	X86_SIM_X86_JMP(0x272, 0xe2, x86_l_e2);
x86_l_277:
	/* 0x277: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_27a:
	/* 0x27a: je     16f <cil_sock6_recvmsg+0x16f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x27a, 0x16f, x86_l_16f);
x86_l_280:
	/* 0x280: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_285:
	/* 0x285: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_reverse_sk)));
x86_l_28c:
	/* 0x28c: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_291:
	/* 0x291: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_293:
	/* 0x293: movabs rax,0x502640108 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 21514944776ULL);
x86_l_29d:
	/* 0x29d: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2a2:
	/* 0x2a2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a7:
	/* 0x2a7: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_2ae:
	/* 0x2ae: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2b3:
	/* 0x2b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b5:
	/* 0x2b5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b8:
	/* 0x2b8: je     2bf <cil_sock6_recvmsg+0x2bf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2b8, 0x2bf, x86_l_2bf);
x86_l_2ba:
	/* 0x2ba: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2bd:
	/* 0x2bd: jmp    2eb <cil_sock6_recvmsg+0x2eb> */
	X86_SIM_X86_JMP(0x2bd, 0x2eb, x86_l_2eb);
x86_l_2bf:
	/* 0x2bf: mov    QWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_2c8:
	/* 0x2c8: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_2d1:
	/* 0x2d1: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2d6:
	/* 0x2d6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_2dd:
	/* 0x2dd: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2e2:
	/* 0x2e2: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e7:
	/* 0x2e7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e9:
	/* 0x2e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2eb:
	/* 0x2eb: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f0:
	/* 0x2f0: add    rsp,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_2f4:
	/* 0x2f4: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_2f5:
	/* 0x2f5: jmp    2fa <cil_sock6_recvmsg+0x2fa> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_2fa:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
