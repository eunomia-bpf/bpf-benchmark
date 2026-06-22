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
	/* 0x1: sub    rsp,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 64ULL);
x86_l_5:
	/* 0x5: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_8:
	/* 0x8: mov    eax,DWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b:
	/* 0xb: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f:
	/* 0xf: mov    r14d,DWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14:
	/* 0x14: mov    r15d,DWORD PTR [rdi+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_18:
	/* 0x18: mov    ebp,DWORD PTR [rdi+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1b:
	/* 0x1b: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_20:
	/* 0x20: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22:
	/* 0x22: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_27:
	/* 0x27: mov    DWORD PTR [rsp+0x30],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2c:
	/* 0x2c: mov    WORD PTR [rsp+0x34],r14w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_32:
	/* 0x32: mov    WORD PTR [rsp+0x36],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 231928233984ULL);
x86_l_39:
	/* 0x39: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3e:
	/* 0x3e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_reverse_sk)));
x86_l_45:
	/* 0x45: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4a:
	/* 0x4a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c:
	/* 0x4c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4f:
	/* 0x4f: je     2af <cil_sock4_recvmsg+0x2af> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4f, 0x2af, x86_l_2af);
x86_l_55:
	/* 0x55: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_58:
	/* 0x58: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5a:
	/* 0x5a: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_5e:
	/* 0x5e: movzx  eax,WORD PTR [r14+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_63:
	/* 0x63: mov    WORD PTR [rsp+0x8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_68:
	/* 0x68: mov    BYTE PTR [rsp+0xc],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_6d:
	/* 0x6d: mov    WORD PTR [rsp+0xe],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 60129542144ULL);
x86_l_74:
	/* 0x74: mov    WORD PTR [rsp+0xa],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 42949672960ULL);
x86_l_7b:
	/* 0x7b: mov    BYTE PTR [rsp+0xd],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 55834574848ULL);
x86_l_80:
	/* 0x80: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_85:
	/* 0x85: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_services_v2)));
x86_l_8c:
	/* 0x8c: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_91:
	/* 0x91: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_93:
	/* 0x93: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_96:
	/* 0x96: je     e8 <cil_sock4_recvmsg+0xe8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x96, 0xe8, x86_l_e8);
x86_l_98:
	/* 0x98: test   BYTE PTR [rax+0x9],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38654705696ULL);
x86_l_9c:
	/* 0x9c: je     bb <cil_sock4_recvmsg+0xbb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9c, 0xbb, x86_l_bb);
x86_l_9e:
	/* 0x9e: mov    BYTE PTR [rsp+0xd],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 55834574849ULL);
x86_l_a3:
	/* 0xa3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a8:
	/* 0xa8: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_services_v2)));
x86_l_af:
	/* 0xaf: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_b4:
	/* 0xb4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b6:
	/* 0xb6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b9:
	/* 0xb9: je     e8 <cil_sock4_recvmsg+0xe8> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb9, 0xe8, x86_l_e8);
x86_l_bb:
	/* 0xbb: movzx  ecx,WORD PTR [rax+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_bf:
	/* 0xbf: cmp    cx,WORD PTR [r14+0x6] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RCX, X86_R14, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 6ULL);
x86_l_c4:
	/* 0xc4: jne    244 <cil_sock4_recvmsg+0x244> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xc4, 0x244, x86_l_244);
x86_l_ca:
	/* 0xca: cmp    WORD PTR [rax+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_cf:
	/* 0xcf: je     244 <cil_sock4_recvmsg+0x244> */
	X86_SIM_X86_JCC(X86_CC_E, 0xcf, 0x244, x86_l_244);
x86_l_d5:
	/* 0xd5: mov    eax,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d8:
	/* 0xd8: mov    DWORD PTR [rbx+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_db:
	/* 0xdb: movzx  eax,WORD PTR [r14+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_e0:
	/* 0xe0: mov    DWORD PTR [rbx+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_e3:
	/* 0xe3: jmp    2af <cil_sock4_recvmsg+0x2af> */
	X86_SIM_X86_JMP(0xe3, 0x2af, x86_l_2af);
x86_l_e8:
	/* 0xe8: mov    eax,0x7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 122ULL);
x86_l_ed:
	/* 0xed: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_f0:
	/* 0xf0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f2:
	/* 0xf2: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_f5:
	/* 0xf5: mov    eax,0x7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 122ULL);
x86_l_fa:
	/* 0xfa: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_fd:
	/* 0xfd: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ff:
	/* 0xff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_101:
	/* 0x101: mov    ecx,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_105:
	/* 0x105: movbe  dx,WORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOVBE_LOAD, X86_RDX, X86_RSP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_10c:
	/* 0x10c: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_nodeport_port_min)));
x86_l_113:
	/* 0x113: cmp    dx,WORD PTR [rsi] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSI, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_116:
	/* 0x116: jb     126 <cil_sock4_recvmsg+0x126> */
	X86_SIM_X86_JCC(X86_CC_B, 0x116, 0x126, x86_l_126);
x86_l_118:
	/* 0x118: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_nodeport_port_max)));
x86_l_11f:
	/* 0x11f: cmp    dx,WORD PTR [rsi] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RDX, X86_RSI, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_122:
	/* 0x122: setbe  r13b */
	X86_SIM_L_EXEC_SETCC(X86_R13, X86_CC_BE);
x86_l_126:
	/* 0x126: movzx  ebp,cl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RBP, X86_RCX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_129:
	/* 0x129: cmp    r15,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_12c:
	/* 0x12c: jne    1a5 <cil_sock4_recvmsg+0x1a5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x12c, 0x1a5, x86_l_1a5);
x86_l_12e:
	/* 0x12e: cmp    ebp,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 127ULL);
x86_l_131:
	/* 0x131: jne    1a5 <cil_sock4_recvmsg+0x1a5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x131, 0x1a5, x86_l_1a5);
x86_l_133:
	/* 0x133: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_13b:
	/* 0x13b: mov    WORD PTR [rsp+0xa],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 42949672960ULL);
x86_l_142:
	/* 0x142: mov    BYTE PTR [rsp+0xd],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 55834574848ULL);
x86_l_147:
	/* 0x147: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14c:
	/* 0x14c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_services_v2)));
x86_l_153:
	/* 0x153: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_158:
	/* 0x158: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15a:
	/* 0x15a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15d:
	/* 0x15d: je     244 <cil_sock4_recvmsg+0x244> */
	X86_SIM_X86_JCC(X86_CC_E, 0x15d, 0x244, x86_l_244);
x86_l_163:
	/* 0x163: test   BYTE PTR [rax+0x9],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38654705696ULL);
x86_l_167:
	/* 0x167: je     18a <cil_sock4_recvmsg+0x18a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x167, 0x18a, x86_l_18a);
x86_l_169:
	/* 0x169: mov    BYTE PTR [rsp+0xd],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 55834574849ULL);
x86_l_16e:
	/* 0x16e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_173:
	/* 0x173: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_services_v2)));
x86_l_17a:
	/* 0x17a: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_17f:
	/* 0x17f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_181:
	/* 0x181: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_184:
	/* 0x184: je     244 <cil_sock4_recvmsg+0x244> */
	X86_SIM_X86_JCC(X86_CC_E, 0x184, 0x244, x86_l_244);
x86_l_18a:
	/* 0x18a: movzx  ecx,BYTE PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_18e:
	/* 0x18e: test   r13b,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_8);
x86_l_191:
	/* 0x191: je     222 <cil_sock4_recvmsg+0x222> */
	X86_SIM_X86_JCC(X86_CC_E, 0x191, 0x222, x86_l_222);
x86_l_197:
	/* 0x197: test   cl,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_19a:
	/* 0x19a: jne    bb <cil_sock4_recvmsg+0xbb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x19a, 0xbb, x86_l_bb);
x86_l_1a0:
	/* 0x1a0: jmp    244 <cil_sock4_recvmsg+0x244> */
	X86_SIM_X86_JMP(0x1a0, 0x244, x86_l_244);
x86_l_1a5:
	/* 0x1a5: mov    QWORD PTR [rsp+0x16],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 94489280512ULL);
x86_l_1ae:
	/* 0x1ae: mov    WORD PTR [rsp+0x26],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 163208757248ULL);
x86_l_1b5:
	/* 0x1b5: mov    QWORD PTR [rsp+0x1e],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128849018880ULL);
x86_l_1be:
	/* 0x1be: mov    DWORD PTR [rsp+0x10],0x40 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476800ULL);
x86_l_1c6:
	/* 0x1c6: mov    BYTE PTR [rsp+0x17],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 98784247809ULL);
x86_l_1cb:
	/* 0x1cb: mov    DWORD PTR [rsp+0x18],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1cf:
	/* 0x1cf: mov    WORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_1d6:
	/* 0x1d6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1db:
	/* 0x1db: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipcache_v2)));
x86_l_1e2:
	/* 0x1e2: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1e7:
	/* 0x1e7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e9:
	/* 0x1e9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ec:
	/* 0x1ec: je     244 <cil_sock4_recvmsg+0x244> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1ec, 0x244, x86_l_244);
x86_l_1ee:
	/* 0x1ee: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f0:
	/* 0x1f0: test   r13b,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_8);
x86_l_1f3:
	/* 0x1f3: je     23b <cil_sock4_recvmsg+0x23b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1f3, 0x23b, x86_l_23b);
x86_l_1f5:
	/* 0x1f5: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1f8:
	/* 0x1f8: je     133 <cil_sock4_recvmsg+0x133> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1f8, 0x133, x86_l_133);
x86_l_1fe:
	/* 0x1fe: mov    edx,ecx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RCX, X86_WIDTH_32);
x86_l_200:
	/* 0x200: and    edx,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_203:
	/* 0x203: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_206:
	/* 0x206: je     216 <cil_sock4_recvmsg+0x216> */
	X86_SIM_X86_JCC(X86_CC_E, 0x206, 0x216, x86_l_216);
x86_l_208:
	/* 0x208: and    ecx,0xff000000 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4278190080ULL);
x86_l_20e:
	/* 0x20e: cmp    ecx,0x2000000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 33554432ULL);
x86_l_214:
	/* 0x214: jne    244 <cil_sock4_recvmsg+0x244> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x214, 0x244, x86_l_244);
x86_l_216:
	/* 0x216: test   BYTE PTR [rax+0x17],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 98784247816ULL);
x86_l_21a:
	/* 0x21a: je     133 <cil_sock4_recvmsg+0x133> */
	X86_SIM_X86_JCC(X86_CC_E, 0x21a, 0x133, x86_l_133);
x86_l_220:
	/* 0x220: jmp    244 <cil_sock4_recvmsg+0x244> */
	X86_SIM_X86_JMP(0x220, 0x244, x86_l_244);
x86_l_222:
	/* 0x222: test   cl,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 8ULL);
x86_l_225:
	/* 0x225: je     244 <cil_sock4_recvmsg+0x244> */
	X86_SIM_X86_JCC(X86_CC_E, 0x225, 0x244, x86_l_244);
x86_l_227:
	/* 0x227: test   BYTE PTR [rax+0x9],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38654705672ULL);
x86_l_22b:
	/* 0x22b: je     bb <cil_sock4_recvmsg+0xbb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x22b, 0xbb, x86_l_bb);
x86_l_231:
	/* 0x231: cmp    ebp,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_32, 127ULL);
x86_l_234:
	/* 0x234: jne    244 <cil_sock4_recvmsg+0x244> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x234, 0x244, x86_l_244);
x86_l_236:
	/* 0x236: jmp    bb <cil_sock4_recvmsg+0xbb> */
	X86_SIM_X86_JMP(0x236, 0xbb, x86_l_bb);
x86_l_23b:
	/* 0x23b: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_23e:
	/* 0x23e: je     133 <cil_sock4_recvmsg+0x133> */
	X86_SIM_X86_JCC(X86_CC_E, 0x23e, 0x133, x86_l_133);
x86_l_244:
	/* 0x244: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_249:
	/* 0x249: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_reverse_sk)));
x86_l_250:
	/* 0x250: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_255:
	/* 0x255: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_257:
	/* 0x257: movabs rax,0x502640108 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 21514944776ULL);
x86_l_261:
	/* 0x261: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_266:
	/* 0x266: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_26b:
	/* 0x26b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_272:
	/* 0x272: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_277:
	/* 0x277: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_279:
	/* 0x279: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_27c:
	/* 0x27c: je     283 <cil_sock4_recvmsg+0x283> */
	X86_SIM_X86_JCC(X86_CC_E, 0x27c, 0x283, x86_l_283);
x86_l_27e:
	/* 0x27e: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_281:
	/* 0x281: jmp    2af <cil_sock4_recvmsg+0x2af> */
	X86_SIM_X86_JMP(0x281, 0x2af, x86_l_2af);
x86_l_283:
	/* 0x283: mov    QWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_28c:
	/* 0x28c: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_295:
	/* 0x295: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_29a:
	/* 0x29a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_2a1:
	/* 0x2a1: lea    rsi,[rsp+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_2a6:
	/* 0x2a6: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2ab:
	/* 0x2ab: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ad:
	/* 0x2ad: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2af:
	/* 0x2af: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2b4:
	/* 0x2b4: add    rsp,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_2b8:
	/* 0x2b8: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_2b9:
	/* 0x2b9: jmp    2be <cil_sock4_recvmsg+0x2be> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_2be:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
