extern char __config_nodeport_port_max;
extern char __config_nodeport_port_min;
extern char cilium_ipcache_v2;
extern char cilium_lb4_services_v2;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int cilium_bpf_sock_cil_sock6_post_bind_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: sub    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 40ULL);
x86_l_4:
	/* 0x4: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_7:
	/* 0x7: movzx  eax,BYTE PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 12ULL);
x86_l_b:
	/* 0xb: movzx  ecx,WORD PTR [rdi+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 44ULL);
x86_l_f:
	/* 0xf: mov    WORD PTR [rsp+0x10],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14:
	/* 0x14: movzx  r13d,WORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_1a:
	/* 0x1a: mov    ebx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 1ULL);
x86_l_1f:
	/* 0x1f: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_22:
	/* 0x22: je     34 <cil_sock6_post_bind+0x34> */
	X86_SIM_X86_JCC(X86_CC_E, 0x22, 0x34, x86_l_34);
x86_l_24:
	/* 0x24: cmp    eax,0x88 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 136ULL);
x86_l_29:
	/* 0x29: je     34 <cil_sock6_post_bind+0x34> */
	X86_SIM_X86_JCC(X86_CC_E, 0x29, 0x34, x86_l_34);
x86_l_2b:
	/* 0x2b: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_2e:
	/* 0x2e: jne    1bd <cil_sock6_post_bind+0x1bd> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2e, 0x1bd, x86_l_1bd);
x86_l_34:
	/* 0x34: mov    eax,0x7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 122ULL);
x86_l_39:
	/* 0x39: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_3c:
	/* 0x3c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e:
	/* 0x3e: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_41:
	/* 0x41: mov    eax,0x7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 122ULL);
x86_l_46:
	/* 0x46: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_48:
	/* 0x48: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a:
	/* 0x4a: cmp    r15,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_4d:
	/* 0x4d: jne    1bd <cil_sock6_post_bind+0x1bd> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4d, 0x1bd, x86_l_1bd);
x86_l_53:
	/* 0x53: mov    edx,DWORD PTR [r14+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_57:
	/* 0x57: mov    eax,DWORD PTR [r14+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5b:
	/* 0x5b: mov    esi,DWORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_5f:
	/* 0x5f: mov    ecx,DWORD PTR [r14+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_63:
	/* 0x63: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_nodeport_port_min)));
x86_l_6a:
	/* 0x6a: cmp    r13w,WORD PTR [r15] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_6e:
	/* 0x6e: jb     c8 <cil_sock6_post_bind+0xc8> */
	X86_SIM_X86_JCC(X86_CC_B, 0x6e, 0xc8, x86_l_c8);
x86_l_70:
	/* 0x70: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&__config_nodeport_port_max)));
x86_l_77:
	/* 0x77: cmp    r13w,WORD PTR [rdi] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RDI, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_7b:
	/* 0x7b: ja     c8 <cil_sock6_post_bind+0xc8> */
	X86_SIM_X86_JCC(X86_CC_A, 0x7b, 0xc8, x86_l_c8);
x86_l_7d:
	/* 0x7d: shl    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_81:
	/* 0x81: shl    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_85:
	/* 0x85: or     rcx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RSI, X86_WIDTH_64, X86_ALU_OR);
x86_l_88:
	/* 0x88: or     rax,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDX, X86_WIDTH_64, X86_ALU_OR);
x86_l_8b:
	/* 0x8b: jne    9c <cil_sock6_post_bind+0x9c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x8b, 0x9c, x86_l_9c);
x86_l_8d:
	/* 0x8d: movabs rdx,0x100000000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 72057594037927936ULL);
x86_l_97:
	/* 0x97: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_9a:
	/* 0x9a: je     c8 <cil_sock6_post_bind+0xc8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9a, 0xc8, x86_l_c8);
x86_l_9c:
	/* 0x9c: movabs rdx,0x2000000000000a0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 144115188075856032ULL);
x86_l_a6:
	/* 0xa6: mov    QWORD PTR [rsp+0x10],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ab:
	/* 0xab: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b0:
	/* 0xb0: mov    QWORD PTR [rsp+0x20],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b5:
	/* 0xb5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ba:
	/* 0xba: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipcache_v2)));
x86_l_c1:
	/* 0xc1: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c6:
	/* 0xc6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c8:
	/* 0xc8: mov    edx,DWORD PTR [r14+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_cc:
	/* 0xcc: mov    esi,DWORD PTR [r14+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d0:
	/* 0xd0: mov    eax,DWORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_d4:
	/* 0xd4: mov    ecx,DWORD PTR [r14+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_d8:
	/* 0xd8: or     esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_OR);
x86_l_da:
	/* 0xda: jne    1bd <cil_sock6_post_bind+0x1bd> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xda, 0x1bd, x86_l_1bd);
x86_l_e0:
	/* 0xe0: cmp    eax,0xffff0000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294901760ULL);
x86_l_e5:
	/* 0xe5: jne    1bd <cil_sock6_post_bind+0x1bd> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe5, 0x1bd, x86_l_1bd);
x86_l_eb:
	/* 0xeb: movzx  eax,BYTE PTR [r14+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 12ULL);
x86_l_f0:
	/* 0xf0: movzx  edx,WORD PTR [r14+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 44ULL);
x86_l_f5:
	/* 0xf5: mov    DWORD PTR [rsp+0x4],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_f9:
	/* 0xf9: mov    WORD PTR [rsp+0x10],dx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_fe:
	/* 0xfe: movzx  ecx,WORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_103:
	/* 0x103: movbe  WORD PTR [rsp+0x8],cx */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_10a:
	/* 0x10a: mov    BYTE PTR [rsp+0xc],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_10e:
	/* 0x10e: mov    WORD PTR [rsp+0xe],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 60129542144ULL);
x86_l_115:
	/* 0x115: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_118:
	/* 0x118: je     12a <cil_sock6_post_bind+0x12a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x118, 0x12a, x86_l_12a);
x86_l_11a:
	/* 0x11a: cmp    eax,0x88 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 136ULL);
x86_l_11f:
	/* 0x11f: je     12a <cil_sock6_post_bind+0x12a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11f, 0x12a, x86_l_12a);
x86_l_121:
	/* 0x121: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_124:
	/* 0x124: jne    1bd <cil_sock6_post_bind+0x1bd> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x124, 0x1bd, x86_l_1bd);
x86_l_12a:
	/* 0x12a: mov    eax,0x7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 122ULL);
x86_l_12f:
	/* 0x12f: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_132:
	/* 0x132: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_134:
	/* 0x134: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_137:
	/* 0x137: mov    eax,0x7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 122ULL);
x86_l_13c:
	/* 0x13c: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13e:
	/* 0x13e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_140:
	/* 0x140: cmp    r14,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_143:
	/* 0x143: jne    1bd <cil_sock6_post_bind+0x1bd> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x143, 0x1bd, x86_l_1bd);
x86_l_145:
	/* 0x145: mov    WORD PTR [rsp+0xa],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 42949672960ULL);
x86_l_14c:
	/* 0x14c: mov    BYTE PTR [rsp+0xd],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 55834574848ULL);
x86_l_151:
	/* 0x151: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_156:
	/* 0x156: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_services_v2)));
x86_l_15d:
	/* 0x15d: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_162:
	/* 0x162: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_164:
	/* 0x164: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_167:
	/* 0x167: je     1a4 <cil_sock6_post_bind+0x1a4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x167, 0x1a4, x86_l_1a4);
x86_l_169:
	/* 0x169: test   BYTE PTR [rax+0x9],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38654705696ULL);
x86_l_16d:
	/* 0x16d: je     18c <cil_sock6_post_bind+0x18c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x16d, 0x18c, x86_l_18c);
x86_l_16f:
	/* 0x16f: mov    BYTE PTR [rsp+0xd],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 55834574849ULL);
x86_l_174:
	/* 0x174: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_179:
	/* 0x179: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_services_v2)));
x86_l_180:
	/* 0x180: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_185:
	/* 0x185: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_187:
	/* 0x187: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_18a:
	/* 0x18a: je     1a4 <cil_sock6_post_bind+0x1a4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x18a, 0x1a4, x86_l_1a4);
x86_l_18c:
	/* 0x18c: movzx  ecx,BYTE PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_190:
	/* 0x190: test   cl,0x23 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 35ULL);
x86_l_193:
	/* 0x193: je     1bd <cil_sock6_post_bind+0x1bd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x193, 0x1bd, x86_l_1bd);
x86_l_195:
	/* 0x195: test   cl,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 8ULL);
x86_l_198:
	/* 0x198: jne    1a0 <cil_sock6_post_bind+0x1a0> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x198, 0x1a0, x86_l_1a0);
x86_l_19a:
	/* 0x19a: test   BYTE PTR [rax+0x9],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38654705672ULL);
x86_l_19e:
	/* 0x19e: jne    1bd <cil_sock6_post_bind+0x1bd> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x19e, 0x1bd, x86_l_1bd);
x86_l_1a0:
	/* 0x1a0: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a2:
	/* 0x1a2: jmp    1bd <cil_sock6_post_bind+0x1bd> */
	X86_SIM_X86_JMP(0x1a2, 0x1bd, x86_l_1bd);
x86_l_1a4:
	/* 0x1a4: movbe  ax,WORD PTR [rsp+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOVBE_LOAD, X86_RAX, X86_RSP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_1ab:
	/* 0x1ab: cmp    ax,WORD PTR [r15] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_R15, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1af:
	/* 0x1af: jb     1bd <cil_sock6_post_bind+0x1bd> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1af, 0x1bd, x86_l_1bd);
x86_l_1b1:
	/* 0x1b1: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_nodeport_port_max)));
x86_l_1b8:
	/* 0x1b8: cmp    ax,WORD PTR [rcx] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1bb:
	/* 0x1bb: jbe    1c8 <cil_sock6_post_bind+0x1c8> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x1bb, 0x1c8, x86_l_1c8);
x86_l_1bd:
	/* 0x1bd: mov    eax,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_32);
x86_l_1bf:
	/* 0x1bf: add    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_1c3:
	/* 0x1c3: jmp    27e <cil_sock6_post_bind+0x27e> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_1c8:
	/* 0x1c8: mov    eax,DWORD PTR [rsp+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1cc:
	/* 0x1cc: cmp    al,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 127ULL);
x86_l_1ce:
	/* 0x1ce: je     21e <cil_sock6_post_bind+0x21e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1ce, 0x21e, x86_l_21e);
x86_l_1d0:
	/* 0x1d0: mov    QWORD PTR [rsp+0x16],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 94489280512ULL);
x86_l_1d9:
	/* 0x1d9: mov    WORD PTR [rsp+0x26],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 163208757248ULL);
x86_l_1e0:
	/* 0x1e0: mov    QWORD PTR [rsp+0x1e],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128849018880ULL);
x86_l_1e9:
	/* 0x1e9: mov    DWORD PTR [rsp+0x10],0x40 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476800ULL);
x86_l_1f1:
	/* 0x1f1: mov    BYTE PTR [rsp+0x17],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 98784247809ULL);
x86_l_1f6:
	/* 0x1f6: mov    DWORD PTR [rsp+0x18],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1fa:
	/* 0x1fa: mov    WORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_201:
	/* 0x201: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_206:
	/* 0x206: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipcache_v2)));
x86_l_20d:
	/* 0x20d: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_212:
	/* 0x212: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_214:
	/* 0x214: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_217:
	/* 0x217: je     1bd <cil_sock6_post_bind+0x1bd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x217, 0x1bd, x86_l_1bd);
x86_l_219:
	/* 0x219: cmp    DWORD PTR [rax],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_21c:
	/* 0x21c: jne    1bd <cil_sock6_post_bind+0x1bd> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x21c, 0x1bd, x86_l_1bd);
x86_l_21e:
	/* 0x21e: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_226:
	/* 0x226: mov    WORD PTR [rsp+0xa],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 42949672960ULL);
x86_l_22d:
	/* 0x22d: mov    BYTE PTR [rsp+0xd],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 55834574848ULL);
x86_l_232:
	/* 0x232: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_237:
	/* 0x237: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_services_v2)));
x86_l_23e:
	/* 0x23e: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_243:
	/* 0x243: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_245:
	/* 0x245: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_248:
	/* 0x248: je     1bd <cil_sock6_post_bind+0x1bd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x248, 0x1bd, x86_l_1bd);
x86_l_24e:
	/* 0x24e: test   BYTE PTR [rax+0x9],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38654705696ULL);
x86_l_252:
	/* 0x252: je     18c <cil_sock6_post_bind+0x18c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x252, 0x18c, x86_l_18c);
x86_l_258:
	/* 0x258: mov    BYTE PTR [rsp+0xd],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 55834574849ULL);
x86_l_25d:
	/* 0x25d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_262:
	/* 0x262: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_services_v2)));
x86_l_269:
	/* 0x269: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_26e:
	/* 0x26e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_270:
	/* 0x270: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_273:
	/* 0x273: jne    18c <cil_sock6_post_bind+0x18c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x273, 0x18c, x86_l_18c);
x86_l_279:
	/* 0x279: jmp    1bd <cil_sock6_post_bind+0x1bd> */
	X86_SIM_X86_JMP(0x279, 0x1bd, x86_l_1bd);
x86_l_27e:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
