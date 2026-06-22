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
int cilium_bpf_sock_cil_sock4_recvmsg_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0xc: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_f:
	/* 0xf: mov    eax,DWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_12:
	/* 0x12: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16:
	/* 0x16: mov    r14d,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b:
	/* 0x1b: mov    r15d,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1f:
	/* 0x1f: mov    ebp,DWORD PTR [rdi+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_22:
	/* 0x22: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_27:
	/* 0x27: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29:
	/* 0x29: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2e:
	/* 0x2e: mov    DWORD PTR [rsp+0x30],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_33:
	/* 0x33: mov    WORD PTR [rsp+0x34],r14w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_39:
	/* 0x39: mov    WORD PTR [rsp+0x36],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 231928233984ULL);
x86_l_40:
	/* 0x40: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_45:
	/* 0x45: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_reverse_sk)));
x86_l_4c:
	/* 0x4c: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_51:
	/* 0x51: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_53:
	/* 0x53: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_56:
	/* 0x56: je     2b6 <cil_sock4_recvmsg+0x2b6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x56, 0x2b6, x86_l_2b6);
x86_l_5c:
	/* 0x5c: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_5f:
	/* 0x5f: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_61:
	/* 0x61: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_65:
	/* 0x65: movzx  eax,WORD PTR [r14+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_6a:
	/* 0x6a: mov    WORD PTR [rsp+0x8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6f:
	/* 0x6f: mov    BYTE PTR [rsp+0xc],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_74:
	/* 0x74: mov    WORD PTR [rsp+0xe],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 60129542144ULL);
x86_l_7b:
	/* 0x7b: mov    WORD PTR [rsp+0xa],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 42949672960ULL);
x86_l_82:
	/* 0x82: mov    BYTE PTR [rsp+0xd],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 55834574848ULL);
x86_l_87:
	/* 0x87: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_8c:
	/* 0x8c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_services_v2)));
x86_l_93:
	/* 0x93: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_98:
	/* 0x98: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9a:
	/* 0x9a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9d:
	/* 0x9d: je     ef <cil_sock4_recvmsg+0xef> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9d, 0xef, x86_l_ef);
x86_l_9f:
	/* 0x9f: test   BYTE PTR [rax+0x9],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38654705696ULL);
x86_l_a3:
	/* 0xa3: je     c2 <cil_sock4_recvmsg+0xc2> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa3, 0xc2, x86_l_c2);
x86_l_a5:
	/* 0xa5: mov    BYTE PTR [rsp+0xd],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 55834574849ULL);
x86_l_aa:
	/* 0xaa: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_af:
	/* 0xaf: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_services_v2)));
x86_l_b6:
	/* 0xb6: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_bb:
	/* 0xbb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bd:
	/* 0xbd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c0:
	/* 0xc0: je     ef <cil_sock4_recvmsg+0xef> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc0, 0xef, x86_l_ef);
x86_l_c2:
	/* 0xc2: movzx  ecx,WORD PTR [rax+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_c6:
	/* 0xc6: cmp    cx,WORD PTR [r14+0x6] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_R14, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_cb:
	/* 0xcb: jne    24b <cil_sock4_recvmsg+0x24b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xcb, 0x24b, x86_l_24b);
x86_l_d1:
	/* 0xd1: cmp    WORD PTR [rax+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_d6:
	/* 0xd6: je     24b <cil_sock4_recvmsg+0x24b> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd6, 0x24b, x86_l_24b);
x86_l_dc:
	/* 0xdc: mov    eax,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_df:
	/* 0xdf: mov    DWORD PTR [rbx+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_e2:
	/* 0xe2: movzx  eax,WORD PTR [r14+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_e7:
	/* 0xe7: mov    DWORD PTR [rbx+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ea:
	/* 0xea: jmp    2b6 <cil_sock4_recvmsg+0x2b6> */
	X86_SIM_X86_JMP(0xea, 0x2b6, x86_l_2b6);
x86_l_ef:
	/* 0xef: mov    eax,0x7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 122ULL);
x86_l_f4:
	/* 0xf4: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_f7:
	/* 0xf7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f9:
	/* 0xf9: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_fc:
	/* 0xfc: mov    eax,0x7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 122ULL);
x86_l_101:
	/* 0x101: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_104:
	/* 0x104: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_106:
	/* 0x106: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_108:
	/* 0x108: mov    ecx,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_10c:
	/* 0x10c: movbe  dx,WORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOVBE_LOAD, X86_RDX, X86_RSP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_113:
	/* 0x113: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_nodeport_port_min)));
x86_l_11a:
	/* 0x11a: cmp    dx,WORD PTR [rsi] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSI, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_11d:
	/* 0x11d: jb     12d <cil_sock4_recvmsg+0x12d> */
	X86_SIM_X86_JCC(X86_CC_B, 0x11d, 0x12d, x86_l_12d);
x86_l_11f:
	/* 0x11f: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_nodeport_port_max)));
x86_l_126:
	/* 0x126: cmp    dx,WORD PTR [rsi] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSI, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_129:
	/* 0x129: setbe  r12b */
	X86_SIM_L_EXEC_SETCC(X86_R12, X86_CC_BE);
x86_l_12d:
	/* 0x12d: movzx  ebp,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_130:
	/* 0x130: cmp    r15,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_133:
	/* 0x133: jne    1ac <cil_sock4_recvmsg+0x1ac> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x133, 0x1ac, x86_l_1ac);
x86_l_135:
	/* 0x135: cmp    ebp,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 127ULL);
x86_l_138:
	/* 0x138: jne    1ac <cil_sock4_recvmsg+0x1ac> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x138, 0x1ac, x86_l_1ac);
x86_l_13a:
	/* 0x13a: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_142:
	/* 0x142: mov    WORD PTR [rsp+0xa],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 42949672960ULL);
x86_l_149:
	/* 0x149: mov    BYTE PTR [rsp+0xd],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 55834574848ULL);
x86_l_14e:
	/* 0x14e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_153:
	/* 0x153: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_services_v2)));
x86_l_15a:
	/* 0x15a: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_15f:
	/* 0x15f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_161:
	/* 0x161: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_164:
	/* 0x164: je     24b <cil_sock4_recvmsg+0x24b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x164, 0x24b, x86_l_24b);
x86_l_16a:
	/* 0x16a: test   BYTE PTR [rax+0x9],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38654705696ULL);
x86_l_16e:
	/* 0x16e: je     191 <cil_sock4_recvmsg+0x191> */
	X86_SIM_X86_JCC(X86_CC_E, 0x16e, 0x191, x86_l_191);
x86_l_170:
	/* 0x170: mov    BYTE PTR [rsp+0xd],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 55834574849ULL);
x86_l_175:
	/* 0x175: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_17a:
	/* 0x17a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_services_v2)));
x86_l_181:
	/* 0x181: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_186:
	/* 0x186: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_188:
	/* 0x188: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_18b:
	/* 0x18b: je     24b <cil_sock4_recvmsg+0x24b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x18b, 0x24b, x86_l_24b);
x86_l_191:
	/* 0x191: movzx  ecx,BYTE PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_195:
	/* 0x195: test   r12b,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_8);
x86_l_198:
	/* 0x198: je     229 <cil_sock4_recvmsg+0x229> */
	X86_SIM_X86_JCC(X86_CC_E, 0x198, 0x229, x86_l_229);
x86_l_19e:
	/* 0x19e: test   cl,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_1a1:
	/* 0x1a1: jne    c2 <cil_sock4_recvmsg+0xc2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1a1, 0xc2, x86_l_c2);
x86_l_1a7:
	/* 0x1a7: jmp    24b <cil_sock4_recvmsg+0x24b> */
	X86_SIM_X86_JMP(0x1a7, 0x24b, x86_l_24b);
x86_l_1ac:
	/* 0x1ac: mov    QWORD PTR [rsp+0x16],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 94489280512ULL);
x86_l_1b5:
	/* 0x1b5: mov    WORD PTR [rsp+0x26],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 163208757248ULL);
x86_l_1bc:
	/* 0x1bc: mov    QWORD PTR [rsp+0x1e],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128849018880ULL);
x86_l_1c5:
	/* 0x1c5: mov    DWORD PTR [rsp+0x10],0x40 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476800ULL);
x86_l_1cd:
	/* 0x1cd: mov    BYTE PTR [rsp+0x17],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 98784247809ULL);
x86_l_1d2:
	/* 0x1d2: mov    DWORD PTR [rsp+0x18],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1d6:
	/* 0x1d6: mov    WORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_1dd:
	/* 0x1dd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1e2:
	/* 0x1e2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipcache_v2)));
x86_l_1e9:
	/* 0x1e9: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1ee:
	/* 0x1ee: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f0:
	/* 0x1f0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f3:
	/* 0x1f3: je     24b <cil_sock4_recvmsg+0x24b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1f3, 0x24b, x86_l_24b);
x86_l_1f5:
	/* 0x1f5: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f7:
	/* 0x1f7: test   r12b,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R12, X86_R12, X86_WIDTH_8);
x86_l_1fa:
	/* 0x1fa: je     242 <cil_sock4_recvmsg+0x242> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1fa, 0x242, x86_l_242);
x86_l_1fc:
	/* 0x1fc: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1ff:
	/* 0x1ff: je     13a <cil_sock4_recvmsg+0x13a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1ff, 0x13a, x86_l_13a);
x86_l_205:
	/* 0x205: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_207:
	/* 0x207: and    edx,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_20a:
	/* 0x20a: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_20d:
	/* 0x20d: je     21d <cil_sock4_recvmsg+0x21d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x20d, 0x21d, x86_l_21d);
x86_l_20f:
	/* 0x20f: and    ecx,0xff000000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4278190080ULL);
x86_l_215:
	/* 0x215: cmp    ecx,0x2000000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 33554432ULL);
x86_l_21b:
	/* 0x21b: jne    24b <cil_sock4_recvmsg+0x24b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x21b, 0x24b, x86_l_24b);
x86_l_21d:
	/* 0x21d: test   BYTE PTR [rax+0x17],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 98784247816ULL);
x86_l_221:
	/* 0x221: je     13a <cil_sock4_recvmsg+0x13a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x221, 0x13a, x86_l_13a);
x86_l_227:
	/* 0x227: jmp    24b <cil_sock4_recvmsg+0x24b> */
	X86_SIM_X86_JMP(0x227, 0x24b, x86_l_24b);
x86_l_229:
	/* 0x229: test   cl,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 8ULL);
x86_l_22c:
	/* 0x22c: je     24b <cil_sock4_recvmsg+0x24b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x22c, 0x24b, x86_l_24b);
x86_l_22e:
	/* 0x22e: test   BYTE PTR [rax+0x9],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38654705672ULL);
x86_l_232:
	/* 0x232: je     c2 <cil_sock4_recvmsg+0xc2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x232, 0xc2, x86_l_c2);
x86_l_238:
	/* 0x238: cmp    ebp,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 127ULL);
x86_l_23b:
	/* 0x23b: jne    24b <cil_sock4_recvmsg+0x24b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x23b, 0x24b, x86_l_24b);
x86_l_23d:
	/* 0x23d: jmp    c2 <cil_sock4_recvmsg+0xc2> */
	X86_SIM_X86_JMP(0x23d, 0xc2, x86_l_c2);
x86_l_242:
	/* 0x242: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_245:
	/* 0x245: je     13a <cil_sock4_recvmsg+0x13a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x245, 0x13a, x86_l_13a);
x86_l_24b:
	/* 0x24b: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_250:
	/* 0x250: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_reverse_sk)));
x86_l_257:
	/* 0x257: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_25c:
	/* 0x25c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25e:
	/* 0x25e: movabs rax,0x502640108 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 21514944776ULL);
x86_l_268:
	/* 0x268: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_26d:
	/* 0x26d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_272:
	/* 0x272: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_279:
	/* 0x279: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_27e:
	/* 0x27e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_280:
	/* 0x280: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_283:
	/* 0x283: je     28a <cil_sock4_recvmsg+0x28a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x283, 0x28a, x86_l_28a);
x86_l_285:
	/* 0x285: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_288:
	/* 0x288: jmp    2b6 <cil_sock4_recvmsg+0x2b6> */
	X86_SIM_X86_JMP(0x288, 0x2b6, x86_l_2b6);
x86_l_28a:
	/* 0x28a: mov    QWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_293:
	/* 0x293: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_29c:
	/* 0x29c: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2a1:
	/* 0x2a1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_2a8:
	/* 0x2a8: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2ad:
	/* 0x2ad: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b2:
	/* 0x2b2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2b4:
	/* 0x2b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b6:
	/* 0x2b6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2bb:
	/* 0x2bb: add    rsp,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_2bf:
	/* 0x2bf: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_2c0:
	/* 0x2c0: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_2c2:
	/* 0x2c2: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_2c4:
	/* 0x2c4: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_2c6:
	/* 0x2c6: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_2c7:
	/* 0x2c7: jmp    2cc <cil_sock4_recvmsg+0x2cc> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_2cc:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
