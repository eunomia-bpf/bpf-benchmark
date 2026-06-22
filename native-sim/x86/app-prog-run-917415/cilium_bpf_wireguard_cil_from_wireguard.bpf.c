extern char __config_enable_identity_mark;
extern char __config_tracing_ip_option_type;
extern char cilium_percpu_trace_id;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int cilium_bpf_wireguard_cil_from_wireguard_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: sub    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
x86_l_4:
	/* 0x4: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_7:
	/* 0x7: and    BYTE PTR [rdi+0x86],0xfb */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RDI, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 575525617915ULL);
x86_l_e:
	/* 0xe: mov    DWORD PTR [rdi+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_15:
	/* 0x15: mov    DWORD PTR [rdi+0x2c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561024ULL);
x86_l_1c:
	/* 0x1c: mov    DWORD PTR [rdi+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_23:
	/* 0x23: mov    DWORD PTR [rdi+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_2a:
	/* 0x2a: mov    DWORD PTR [rdi+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_31:
	/* 0x31: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_tracing_ip_option_type)));
x86_l_38:
	/* 0x38: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3b:
	/* 0x3b: je     2c0 <cil_from_wireguard+0x2c0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3b, 0x2c0, x86_l_2c0);
x86_l_41:
	/* 0x41: movzx  r13d,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_45:
	/* 0x45: cmp    WORD PTR [rbx+0xb4],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 773094113288ULL);
x86_l_4d:
	/* 0x4d: jne    299 <cil_from_wireguard+0x299> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4d, 0x299, x86_l_299);
x86_l_53:
	/* 0x53: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_56:
	/* 0x56: sub    eax,DWORD PTR [rbx+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_59:
	/* 0x59: cmp    eax,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 20ULL);
x86_l_5c:
	/* 0x5c: jb     299 <cil_from_wireguard+0x299> */
	X86_SIM_X86_JCC(X86_CC_B, 0x5c, 0x299, x86_l_299);
x86_l_62:
	/* 0x62: mov    rax,QWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_69:
	/* 0x69: movzx  r15d,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_6d:
	/* 0x6d: and    r15d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_71:
	/* 0x71: cmp    r15b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_8, 6ULL);
x86_l_75:
	/* 0x75: jae    a6 <cil_from_wireguard+0xa6> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x75, 0xa6, x86_l_a6);
x86_l_77:
	/* 0x77: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7a:
	/* 0x7a: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_82:
	/* 0x82: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_87:
	/* 0x87: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_percpu_trace_id)));
x86_l_8e:
	/* 0x8e: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_93:
	/* 0x93: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_95:
	/* 0x95: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_98:
	/* 0x98: je     2c0 <cil_from_wireguard+0x2c0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x98, 0x2c0, x86_l_2c0);
x86_l_9e:
	/* 0x9e: mov    QWORD PTR [rax],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a1:
	/* 0xa1: jmp    2c0 <cil_from_wireguard+0x2c0> */
	X86_SIM_X86_JMP(0xa1, 0x2c0, x86_l_2c0);
x86_l_a6:
	/* 0xa6: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_ab:
	/* 0xab: lea    rdx,[rsp+0xe] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_b0:
	/* 0xb0: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_b3:
	/* 0xb3: mov    esi,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 20ULL);
x86_l_b8:
	/* 0xb8: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_bd:
	/* 0xbd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bf:
	/* 0xbf: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c1:
	/* 0xc1: js     299 <cil_from_wireguard+0x299> */
	X86_SIM_X86_JCC(X86_CC_S, 0xc1, 0x299, x86_l_299);
x86_l_c7:
	/* 0xc7: movzx  eax,BYTE PTR [rsp+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 14ULL);
x86_l_cc:
	/* 0xcc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_ce:
	/* 0xce: je     77 <cil_from_wireguard+0x77> */
	X86_SIM_X86_JCC(X86_CC_E, 0xce, 0x77, x86_l_77);
x86_l_d0:
	/* 0xd0: mov    r14d,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 21ULL);
x86_l_d6:
	/* 0xd6: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d9:
	/* 0xd9: je     166 <cil_from_wireguard+0x166> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd9, 0x166, x86_l_166);
x86_l_df:
	/* 0xdf: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_e4:
	/* 0xe4: lea    rdx,[rsp+0xf] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 15ULL);
x86_l_e9:
	/* 0xe9: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_ec:
	/* 0xec: mov    esi,0x15 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 21ULL);
x86_l_f1:
	/* 0xf1: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_f6:
	/* 0xf6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f8:
	/* 0xf8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_fa:
	/* 0xfa: js     299 <cil_from_wireguard+0x299> */
	X86_SIM_X86_JCC(X86_CC_S, 0xfa, 0x299, x86_l_299);
x86_l_100:
	/* 0x100: mov    r14d,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 20ULL);
x86_l_106:
	/* 0x106: cmp    BYTE PTR [rsp+0xe],r13b */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_10b:
	/* 0x10b: jne    15c <cil_from_wireguard+0x15c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x10b, 0x15c, x86_l_15c);
x86_l_10d:
	/* 0x10d: movzx  eax,BYTE PTR [rsp+0xf] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 15ULL);
x86_l_112:
	/* 0x112: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_115:
	/* 0x115: je     266 <cil_from_wireguard+0x266> */
	X86_SIM_X86_JCC(X86_CC_E, 0x115, 0x266, x86_l_266);
x86_l_11b:
	/* 0x11b: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_11e:
	/* 0x11e: je     23a <cil_from_wireguard+0x23a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11e, 0x23a, x86_l_23a);
x86_l_124:
	/* 0x124: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_127:
	/* 0x127: jne    299 <cil_from_wireguard+0x299> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x127, 0x299, x86_l_299);
x86_l_12d:
	/* 0x12d: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_132:
	/* 0x132: add    r14d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_136:
	/* 0x136: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_13b:
	/* 0x13b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_13e:
	/* 0x13e: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_141:
	/* 0x141: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_146:
	/* 0x146: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_148:
	/* 0x148: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14b:
	/* 0x14b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_14d:
	/* 0x14d: movbe  cx,WORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOVBE_LOAD, X86_RCX, X86_RSP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_154:
	/* 0x154: movzx  ecx,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_157:
	/* 0x157: jmp    28d <cil_from_wireguard+0x28d> */
	X86_SIM_X86_JMP(0x157, 0x28d, x86_l_28d);
x86_l_15c:
	/* 0x15c: movzx  r14d,BYTE PTR [rsp+0xf] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 15ULL);
x86_l_162:
	/* 0x162: add    r14d,0x14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 20ULL);
x86_l_166:
	/* 0x166: lea    r15d,[r15*4+0x14] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 20ULL);
x86_l_16e:
	/* 0x16e: cmp    r14d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R14, X86_R15, X86_WIDTH_32);
x86_l_171:
	/* 0x171: jae    77 <cil_from_wireguard+0x77> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x171, 0x77, x86_l_77);
x86_l_177:
	/* 0x177: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_17c:
	/* 0x17c: lea    rdx,[rsp+0xe] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_181:
	/* 0x181: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_184:
	/* 0x184: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_187:
	/* 0x187: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_18c:
	/* 0x18c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18e:
	/* 0x18e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_190:
	/* 0x190: js     299 <cil_from_wireguard+0x299> */
	X86_SIM_X86_JCC(X86_CC_S, 0x190, 0x299, x86_l_299);
x86_l_196:
	/* 0x196: movzx  eax,BYTE PTR [rsp+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 14ULL);
x86_l_19b:
	/* 0x19b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_19d:
	/* 0x19d: je     77 <cil_from_wireguard+0x77> */
	X86_SIM_X86_JCC(X86_CC_E, 0x19d, 0x77, x86_l_77);
x86_l_1a3:
	/* 0x1a3: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a6:
	/* 0x1a6: je     1d8 <cil_from_wireguard+0x1d8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a6, 0x1d8, x86_l_1d8);
x86_l_1a8:
	/* 0x1a8: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1ad:
	/* 0x1ad: lea    esi,[r14+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_1b1:
	/* 0x1b1: lea    rdx,[rsp+0xf] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 15ULL);
x86_l_1b6:
	/* 0x1b6: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1b9:
	/* 0x1b9: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1be:
	/* 0x1be: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c0:
	/* 0x1c0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1c2:
	/* 0x1c2: js     299 <cil_from_wireguard+0x299> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1c2, 0x299, x86_l_299);
x86_l_1c8:
	/* 0x1c8: cmp    BYTE PTR [rsp+0xe],r13b */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_1cd:
	/* 0x1cd: je     10d <cil_from_wireguard+0x10d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1cd, 0x10d, x86_l_10d);
x86_l_1d3:
	/* 0x1d3: movzx  eax,BYTE PTR [rsp+0xf] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 15ULL);
x86_l_1d8:
	/* 0x1d8: add    r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_1db:
	/* 0x1db: cmp    r14d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R14, X86_R15, X86_WIDTH_32);
x86_l_1de:
	/* 0x1de: jae    77 <cil_from_wireguard+0x77> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x1de, 0x77, x86_l_77);
x86_l_1e4:
	/* 0x1e4: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1e9:
	/* 0x1e9: lea    rdx,[rsp+0xe] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_1ee:
	/* 0x1ee: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1f1:
	/* 0x1f1: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_1f4:
	/* 0x1f4: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1f9:
	/* 0x1f9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fb:
	/* 0x1fb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1fd:
	/* 0x1fd: js     299 <cil_from_wireguard+0x299> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1fd, 0x299, x86_l_299);
x86_l_203:
	/* 0x203: cmp    BYTE PTR [rsp+0xe],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 60129542146ULL);
x86_l_208:
	/* 0x208: jb     77 <cil_from_wireguard+0x77> */
	X86_SIM_X86_JCC(X86_CC_B, 0x208, 0x77, x86_l_77);
x86_l_20e:
	/* 0x20e: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_213:
	/* 0x213: lea    esi,[r14+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_217:
	/* 0x217: lea    rdx,[rsp+0xf] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 15ULL);
x86_l_21c:
	/* 0x21c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_21f:
	/* 0x21f: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_224:
	/* 0x224: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_226:
	/* 0x226: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_228:
	/* 0x228: js     299 <cil_from_wireguard+0x299> */
	X86_SIM_X86_JCC(X86_CC_S, 0x228, 0x299, x86_l_299);
x86_l_22a:
	/* 0x22a: cmp    BYTE PTR [rsp+0xe],r13b */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_22f:
	/* 0x22f: jne    77 <cil_from_wireguard+0x77> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x22f, 0x77, x86_l_77);
x86_l_235:
	/* 0x235: jmp    10d <cil_from_wireguard+0x10d> */
	X86_SIM_X86_JMP(0x235, 0x10d, x86_l_10d);
x86_l_23a:
	/* 0x23a: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_23f:
	/* 0x23f: add    r14d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_243:
	/* 0x243: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_248:
	/* 0x248: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_24b:
	/* 0x24b: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_24e:
	/* 0x24e: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_253:
	/* 0x253: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_255:
	/* 0x255: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_257:
	/* 0x257: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_259:
	/* 0x259: movbe  r14d,DWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOVBE_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 16ULL);
x86_l_260:
	/* 0x260: cmovs  r14d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R14, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_264:
	/* 0x264: jmp    291 <cil_from_wireguard+0x291> */
	X86_SIM_X86_JMP(0x264, 0x291, x86_l_291);
x86_l_266:
	/* 0x266: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_26b:
	/* 0x26b: add    r14d,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_26f:
	/* 0x26f: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_274:
	/* 0x274: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_277:
	/* 0x277: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_27a:
	/* 0x27a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_27f:
	/* 0x27f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_281:
	/* 0x281: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_284:
	/* 0x284: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_286:
	/* 0x286: movbe  rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOVBE_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_28d:
	/* 0x28d: cmovns r14,rcx */
	X86_SIM_L_EXEC_CMOV(X86_R14, X86_RCX, X86_WIDTH_64, X86_CC_NS);
x86_l_291:
	/* 0x291: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_293:
	/* 0x293: jns    7a <cil_from_wireguard+0x7a> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x293, 0x7a, x86_l_7a);
x86_l_299:
	/* 0x299: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2a1:
	/* 0x2a1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a6:
	/* 0x2a6: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_percpu_trace_id)));
x86_l_2ad:
	/* 0x2ad: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b2:
	/* 0x2b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b4:
	/* 0x2b4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b7:
	/* 0x2b7: je     2c0 <cil_from_wireguard+0x2c0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2b7, 0x2c0, x86_l_2c0);
x86_l_2b9:
	/* 0x2b9: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2c0:
	/* 0x2c0: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_identity_mark)));
x86_l_2c7:
	/* 0x2c7: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ca:
	/* 0x2ca: je     2d6 <cil_from_wireguard+0x2d6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2ca, 0x2d6, x86_l_2d6);
x86_l_2cc:
	/* 0x2cc: mov    DWORD PTR [rbx+0xa8],0xd00 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 721554509056ULL);
x86_l_2d6:
	/* 0x2d6: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2d8:
	/* 0x2d8: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_2dc:
	/* 0x2dc: jmp    2e1 <cil_from_wireguard+0x2e1> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_2e1:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
