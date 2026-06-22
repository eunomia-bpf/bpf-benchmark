extern char __config_nodeport_port_max;
extern char __config_nodeport_port_min;
extern char cilium_ipcache_v2;
extern char cilium_lb4_services_v2;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int cilium_bpf_sock_cil_sock4_post_bind_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_1:
	/* 0x1: sub    rsp,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 48ULL);
x86_l_5:
	/* 0x5: movzx  eax,BYTE PTR [rdi+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 12ULL);
x86_l_9:
	/* 0x9: mov    ecx,DWORD PTR [rdi+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c:
	/* 0xc: mov    DWORD PTR [rsp+0xc],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_10:
	/* 0x10: movzx  ecx,WORD PTR [rdi+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 44ULL);
x86_l_14:
	/* 0x14: mov    WORD PTR [rsp+0x18],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_19:
	/* 0x19: movzx  ecx,WORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 24ULL);
x86_l_1e:
	/* 0x1e: movbe  WORD PTR [rsp+0x10],cx */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_25:
	/* 0x25: mov    BYTE PTR [rsp+0x14],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_29:
	/* 0x29: mov    WORD PTR [rsp+0x16],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 94489280512ULL);
x86_l_30:
	/* 0x30: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_33:
	/* 0x33: je     45 <cil_sock4_post_bind+0x45> */
	X86_SIM_X86_JCC(X86_CC_E, 0x33, 0x45, x86_l_45);
x86_l_35:
	/* 0x35: cmp    eax,0x88 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 136ULL);
x86_l_3a:
	/* 0x3a: je     45 <cil_sock4_post_bind+0x45> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3a, 0x45, x86_l_45);
x86_l_3c:
	/* 0x3c: cmp    eax,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 17ULL);
x86_l_3f:
	/* 0x3f: jne    e7 <cil_sock4_post_bind+0xe7> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3f, 0xe7, x86_l_e7);
x86_l_45:
	/* 0x45: mov    eax,0x7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 122ULL);
x86_l_4a:
	/* 0x4a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4c:
	/* 0x4c: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_4f:
	/* 0x4f: mov    eax,0x7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 122ULL);
x86_l_54:
	/* 0x54: xor    edi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_56:
	/* 0x56: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_58:
	/* 0x58: cmp    rbx,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_5b:
	/* 0x5b: jne    e7 <cil_sock4_post_bind+0xe7> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x5b, 0xe7, x86_l_e7);
x86_l_61:
	/* 0x61: mov    WORD PTR [rsp+0x12],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 77309411328ULL);
x86_l_68:
	/* 0x68: mov    BYTE PTR [rsp+0x15],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 90194313216ULL);
x86_l_6d:
	/* 0x6d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_72:
	/* 0x72: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_services_v2)));
x86_l_79:
	/* 0x79: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_7e:
	/* 0x7e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_80:
	/* 0x80: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_83:
	/* 0x83: je     c8 <cil_sock4_post_bind+0xc8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x83, 0xc8, x86_l_c8);
x86_l_85:
	/* 0x85: test   BYTE PTR [rax+0x9],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38654705696ULL);
x86_l_89:
	/* 0x89: je     a8 <cil_sock4_post_bind+0xa8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x89, 0xa8, x86_l_a8);
x86_l_8b:
	/* 0x8b: mov    BYTE PTR [rsp+0x15],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 90194313217ULL);
x86_l_90:
	/* 0x90: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_95:
	/* 0x95: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_services_v2)));
x86_l_9c:
	/* 0x9c: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_a1:
	/* 0xa1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a3:
	/* 0xa3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a6:
	/* 0xa6: je     c8 <cil_sock4_post_bind+0xc8> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa6, 0xc8, x86_l_c8);
x86_l_a8:
	/* 0xa8: movzx  ecx,BYTE PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_ac:
	/* 0xac: test   cl,0x23 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 35ULL);
x86_l_af:
	/* 0xaf: je     e7 <cil_sock4_post_bind+0xe7> */
	X86_SIM_X86_JCC(X86_CC_E, 0xaf, 0xe7, x86_l_e7);
x86_l_b1:
	/* 0xb1: test   cl,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 8ULL);
x86_l_b4:
	/* 0xb4: jne    bc <cil_sock4_post_bind+0xbc> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb4, 0xbc, x86_l_bc);
x86_l_b6:
	/* 0xb6: test   BYTE PTR [rax+0x9],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38654705672ULL);
x86_l_ba:
	/* 0xba: jne    e7 <cil_sock4_post_bind+0xe7> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xba, 0xe7, x86_l_e7);
x86_l_bc:
	/* 0xbc: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_be:
	/* 0xbe: add    rsp,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_c2:
	/* 0xc2: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_c3:
	/* 0xc3: jmp    1ac <cil_sock4_post_bind+0x1ac> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_c8:
	/* 0xc8: movbe  ax,WORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOVBE_LOAD, X86_RAX, X86_RSP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_cf:
	/* 0xcf: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_nodeport_port_min)));
x86_l_d6:
	/* 0xd6: cmp    ax,WORD PTR [rcx] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_d9:
	/* 0xd9: jb     e7 <cil_sock4_post_bind+0xe7> */
	X86_SIM_X86_JCC(X86_CC_B, 0xd9, 0xe7, x86_l_e7);
x86_l_db:
	/* 0xdb: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_nodeport_port_max)));
x86_l_e2:
	/* 0xe2: cmp    ax,WORD PTR [rcx] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RCX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_e5:
	/* 0xe5: jbe    f6 <cil_sock4_post_bind+0xf6> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xe5, 0xf6, x86_l_f6);
x86_l_e7:
	/* 0xe7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ec:
	/* 0xec: add    rsp,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_f0:
	/* 0xf0: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_f1:
	/* 0xf1: jmp    1ac <cil_sock4_post_bind+0x1ac> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_f6:
	/* 0xf6: mov    eax,DWORD PTR [rsp+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_fa:
	/* 0xfa: cmp    al,0x7f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 127ULL);
x86_l_fc:
	/* 0xfc: je     14c <cil_sock4_post_bind+0x14c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfc, 0x14c, x86_l_14c);
x86_l_fe:
	/* 0xfe: mov    QWORD PTR [rsp+0x1e],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128849018880ULL);
x86_l_107:
	/* 0x107: mov    WORD PTR [rsp+0x2e],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 197568495616ULL);
x86_l_10e:
	/* 0x10e: mov    QWORD PTR [rsp+0x26],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 163208757248ULL);
x86_l_117:
	/* 0x117: mov    DWORD PTR [rsp+0x18],0x40 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215168ULL);
x86_l_11f:
	/* 0x11f: mov    BYTE PTR [rsp+0x1f],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 133143986177ULL);
x86_l_124:
	/* 0x124: mov    DWORD PTR [rsp+0x20],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_128:
	/* 0x128: mov    WORD PTR [rsp+0x1c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 120259084288ULL);
x86_l_12f:
	/* 0x12f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_134:
	/* 0x134: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipcache_v2)));
x86_l_13b:
	/* 0x13b: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_140:
	/* 0x140: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_142:
	/* 0x142: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_145:
	/* 0x145: je     e7 <cil_sock4_post_bind+0xe7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x145, 0xe7, x86_l_e7);
x86_l_147:
	/* 0x147: cmp    DWORD PTR [rax],0x1 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_14a:
	/* 0x14a: jne    e7 <cil_sock4_post_bind+0xe7> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x14a, 0xe7, x86_l_e7);
x86_l_14c:
	/* 0x14c: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_154:
	/* 0x154: mov    WORD PTR [rsp+0x12],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 77309411328ULL);
x86_l_15b:
	/* 0x15b: mov    BYTE PTR [rsp+0x15],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 90194313216ULL);
x86_l_160:
	/* 0x160: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_165:
	/* 0x165: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_services_v2)));
x86_l_16c:
	/* 0x16c: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_171:
	/* 0x171: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_173:
	/* 0x173: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_176:
	/* 0x176: je     e7 <cil_sock4_post_bind+0xe7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x176, 0xe7, x86_l_e7);
x86_l_17c:
	/* 0x17c: test   BYTE PTR [rax+0x9],0x20 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38654705696ULL);
x86_l_180:
	/* 0x180: je     a8 <cil_sock4_post_bind+0xa8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x180, 0xa8, x86_l_a8);
x86_l_186:
	/* 0x186: mov    BYTE PTR [rsp+0x15],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 90194313217ULL);
x86_l_18b:
	/* 0x18b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_190:
	/* 0x190: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_services_v2)));
x86_l_197:
	/* 0x197: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_19c:
	/* 0x19c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19e:
	/* 0x19e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1a1:
	/* 0x1a1: jne    a8 <cil_sock4_post_bind+0xa8> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1a1, 0xa8, x86_l_a8);
x86_l_1a7:
	/* 0x1a7: jmp    e7 <cil_sock4_post_bind+0xe7> */
	X86_SIM_X86_JMP(0x1a7, 0xe7, x86_l_e7);
x86_l_1ac:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
