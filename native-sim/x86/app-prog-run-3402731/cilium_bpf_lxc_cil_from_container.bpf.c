extern char __config_enable_arp_responder;
extern char __config_endpoint_id;
extern char __config_security_label;
extern char __config_trace_payload_len;
extern char __config_tracing_ip_option_type;
extern char cilium_calls;
extern char cilium_metrics;
extern char cilium_percpu_trace_id;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int cilium_bpf_lxc_cil_from_container_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0xa: sub    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 40ULL);
x86_l_e:
	/* 0xe: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_11:
	/* 0x11: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_security_label)));
x86_l_18:
	/* 0x18: mov    ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a:
	/* 0x1a: mov    eax,DWORD PTR [rdi+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1d:
	/* 0x1d: sub    eax,DWORD PTR [rdi+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RDI, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_20:
	/* 0x20: cmp    eax,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_23:
	/* 0x23: jae    2d <cil_from_container+0x2d> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x23, 0x2d, x86_l_2d);
x86_l_25:
	/* 0x25: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_28:
	/* 0x28: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2b:
	/* 0x2b: jmp    42 <cil_from_container+0x42> */
	X86_SIM_X86_JMP(0x2b, 0x42, x86_l_42);
x86_l_2d:
	/* 0x2d: mov    rax,QWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_34:
	/* 0x34: movzx  r12d,WORD PTR [rax+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_39:
	/* 0x39: cmp    r12w,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_16, 6ULL);
x86_l_3e:
	/* 0x3e: setae  r13b */
	X86_SIM_L_EXEC_SETCC(X86_R13, X86_CC_AE);
x86_l_42:
	/* 0x42: mov    DWORD PTR [rbx+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_49:
	/* 0x49: mov    DWORD PTR [rbx+0x2c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561024ULL);
x86_l_50:
	/* 0x50: mov    DWORD PTR [rbx+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_57:
	/* 0x57: mov    DWORD PTR [rbx+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_5e:
	/* 0x5e: mov    DWORD PTR [rbx+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_65:
	/* 0x65: mov    r14,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&__config_tracing_ip_option_type)));
x86_l_6c:
	/* 0x6c: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_70:
	/* 0x70: je     ac <cil_from_container+0xac> */
	X86_SIM_X86_JCC(X86_CC_E, 0x70, 0xac, x86_l_ac);
x86_l_72:
	/* 0x72: movzx  ecx,BYTE PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_76:
	/* 0x76: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_79:
	/* 0x79: sub    eax,DWORD PTR [rbx+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_7c:
	/* 0x7c: cmp    eax,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_7f:
	/* 0x7f: jae    13f <cil_from_container+0x13f> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x7f, 0x13f, x86_l_13f);
x86_l_85:
	/* 0x85: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_8d:
	/* 0x8d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_92:
	/* 0x92: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_percpu_trace_id)));
x86_l_99:
	/* 0x99: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9e:
	/* 0x9e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a0:
	/* 0xa0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a3:
	/* 0xa3: je     ac <cil_from_container+0xac> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa3, 0xac, x86_l_ac);
x86_l_a5:
	/* 0xa5: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ac:
	/* 0xac: mov    WORD PTR [rbx+0x7c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 532575944704ULL);
x86_l_b2:
	/* 0xb2: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_endpoint_id)));
x86_l_b9:
	/* 0xb9: movzx  eax,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_bc:
	/* 0xbc: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_c3:
	/* 0xc3: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c5:
	/* 0xc5: cmp    BYTE PTR [r14],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c9:
	/* 0xc9: je     e6 <cil_from_container+0xe6> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc9, 0xe6, x86_l_e6);
x86_l_cb:
	/* 0xcb: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_d3:
	/* 0xd3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d8:
	/* 0xd8: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_percpu_trace_id)));
x86_l_df:
	/* 0xdf: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e4:
	/* 0xe4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e6:
	/* 0xe6: mov    eax,0xa6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 166ULL);
x86_l_eb:
	/* 0xeb: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ee:
	/* 0xee: test   r13b,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R13, X86_R13, X86_WIDTH_8);
x86_l_f1:
	/* 0xf1: je     22e <cil_from_container+0x22e> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf1, 0x22e, x86_l_22e);
x86_l_f7:
	/* 0xf7: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_fa:
	/* 0xfa: rol    ax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_fe:
	/* 0xfe: movzx  eax,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_101:
	/* 0x101: cmp    eax,0x806 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2054ULL);
x86_l_106:
	/* 0x106: je     19c <cil_from_container+0x19c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x106, 0x19c, x86_l_19c);
x86_l_10c:
	/* 0x10c: cmp    eax,0x800 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2048ULL);
x86_l_111:
	/* 0x111: jne    1bb <cil_from_container+0x1bb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x111, 0x1bb, x86_l_1bb);
x86_l_117:
	/* 0x117: mov    eax,0x27 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 39ULL);
x86_l_11c:
	/* 0x11c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_11f:
	/* 0x11f: mov    esi,0x22 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 34ULL);
x86_l_124:
	/* 0x124: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_126:
	/* 0x126: mov    ecx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_129:
	/* 0x129: sub    ecx,DWORD PTR [rbx+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_12c:
	/* 0x12c: mov    eax,0x86 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 134ULL);
x86_l_131:
	/* 0x131: cmp    ecx,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 34ULL);
x86_l_134:
	/* 0x134: jae    1bb <cil_from_container+0x1bb> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x134, 0x1bb, x86_l_1bb);
x86_l_13a:
	/* 0x13a: jmp    22e <cil_from_container+0x22e> */
	X86_SIM_X86_JMP(0x13a, 0x22e, x86_l_22e);
x86_l_13f:
	/* 0x13f: cmp    eax,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 34ULL);
x86_l_142:
	/* 0x142: jb     85 <cil_from_container+0x85> */
	X86_SIM_X86_JCC(X86_CC_B, 0x142, 0x85, x86_l_85);
x86_l_148:
	/* 0x148: mov    rax,QWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_14f:
	/* 0x14f: cmp    WORD PTR [rax+0xc],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 51539607560ULL);
x86_l_154:
	/* 0x154: jne    85 <cil_from_container+0x85> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x154, 0x85, x86_l_85);
x86_l_15a:
	/* 0x15a: movzx  r15d,BYTE PTR [rax+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 14ULL);
x86_l_15f:
	/* 0x15f: and    r15d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_163:
	/* 0x163: cmp    r15b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_8, 6ULL);
x86_l_167:
	/* 0x167: jae    2db <cil_from_container+0x2db> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x167, 0x2db, x86_l_2db);
x86_l_16d:
	/* 0x16d: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_170:
	/* 0x170: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_178:
	/* 0x178: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_17d:
	/* 0x17d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_percpu_trace_id)));
x86_l_184:
	/* 0x184: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_189:
	/* 0x189: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18b:
	/* 0x18b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_18e:
	/* 0x18e: je     ac <cil_from_container+0xac> */
	X86_SIM_X86_JCC(X86_CC_E, 0x18e, 0xac, x86_l_ac);
x86_l_194:
	/* 0x194: mov    QWORD PTR [rax],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_197:
	/* 0x197: jmp    ac <cil_from_container+0xac> */
	X86_SIM_X86_JMP(0x197, 0xac, x86_l_ac);
x86_l_19c:
	/* 0x19c: mov    eax,0x27 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 39ULL);
x86_l_1a1:
	/* 0x1a1: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1a4:
	/* 0x1a4: mov    esi,0x2a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 42ULL);
x86_l_1a9:
	/* 0x1a9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ab:
	/* 0x1ab: mov    ecx,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1ae:
	/* 0x1ae: sub    ecx,DWORD PTR [rbx+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_1b1:
	/* 0x1b1: mov    eax,0x86 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 134ULL);
x86_l_1b6:
	/* 0x1b6: cmp    ecx,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 42ULL);
x86_l_1b9:
	/* 0x1b9: jb     22e <cil_from_container+0x22e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1b9, 0x22e, x86_l_22e);
x86_l_1bb:
	/* 0x1bb: movzx  ecx,r12w */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R12, X86_WIDTH_32, X86_WIDTH_16);
x86_l_1bf:
	/* 0x1bf: cmp    ecx,0x608 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1544ULL);
x86_l_1c5:
	/* 0x1c5: je     1fd <cil_from_container+0x1fd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1c5, 0x1fd, x86_l_1fd);
x86_l_1c7:
	/* 0x1c7: mov    eax,0x8b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 139ULL);
x86_l_1cc:
	/* 0x1cc: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1cf:
	/* 0x1cf: jne    22e <cil_from_container+0x22e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1cf, 0x22e, x86_l_22e);
x86_l_1d1:
	/* 0x1d1: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1d6:
	/* 0x1d6: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_1dd:
	/* 0x1dd: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1e0:
	/* 0x1e0: mov    edx,0x7 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_1e5:
	/* 0x1e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e7:
	/* 0x1e7: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_security_label)));
x86_l_1ee:
	/* 0x1ee: mov    ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f0:
	/* 0x1f0: mov    eax,0x8c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 140ULL);
x86_l_1f5:
	/* 0x1f5: mov    r14d,0x700 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 1792ULL);
x86_l_1fb:
	/* 0x1fb: jmp    22e <cil_from_container+0x22e> */
	X86_SIM_X86_JMP(0x1fb, 0x22e, x86_l_22e);
x86_l_1fd:
	/* 0x1fd: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_arp_responder)));
x86_l_204:
	/* 0x204: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_207:
	/* 0x207: je     397 <cil_from_container+0x397> */
	X86_SIM_X86_JCC(X86_CC_E, 0x207, 0x397, x86_l_397);
x86_l_20d:
	/* 0x20d: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_212:
	/* 0x212: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_219:
	/* 0x219: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_21c:
	/* 0x21c: mov    edx,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_221:
	/* 0x221: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_223:
	/* 0x223: mov    eax,0x8c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 140ULL);
x86_l_228:
	/* 0x228: mov    r14d,0x600 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 1536ULL);
x86_l_22e:
	/* 0x22e: or     r14d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_32, X86_ALU_OR);
x86_l_231:
	/* 0x231: mov    DWORD PTR [rbx+0x28],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_234:
	/* 0x234: mov    DWORD PTR [rbx+0x2c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561024ULL);
x86_l_23b:
	/* 0x23b: mov    DWORD PTR [rbx+0x30],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_23f:
	/* 0x23f: movabs rcx,0x73c020200000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 521293864481325056ULL);
x86_l_249:
	/* 0x249: mov    QWORD PTR [rbx+0x34],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_24d:
	/* 0x24d: mov    r14d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_251:
	/* 0x251: movabs rcx,0x2073c0200 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 8711307776ULL);
x86_l_25b:
	/* 0x25b: mov    QWORD PTR [rsp+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_260:
	/* 0x260: mov    BYTE PTR [rsp+0x8],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_264:
	/* 0x264: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_269:
	/* 0x269: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_270:
	/* 0x270: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_275:
	/* 0x275: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_277:
	/* 0x277: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_27a:
	/* 0x27a: je     285 <cil_from_container+0x285> */
	X86_SIM_X86_JCC(X86_CC_E, 0x27a, 0x285, x86_l_285);
x86_l_27c:
	/* 0x27c: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_27f:
	/* 0x27f: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_283:
	/* 0x283: jmp    2ad <cil_from_container+0x2ad> */
	X86_SIM_X86_JMP(0x283, 0x2ad, x86_l_2ad);
x86_l_285:
	/* 0x285: mov    QWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_28e:
	/* 0x28e: mov    QWORD PTR [rsp+0x18],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_293:
	/* 0x293: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_298:
	/* 0x298: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_29f:
	/* 0x29f: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a4:
	/* 0x2a4: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a9:
	/* 0x2a9: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ab:
	/* 0x2ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ad:
	/* 0x2ad: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_2b2:
	/* 0x2b2: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_2b9:
	/* 0x2b9: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2bc:
	/* 0x2bc: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_2c1:
	/* 0x2c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c3:
	/* 0x2c3: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2c8:
	/* 0x2c8: add    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_2cc:
	/* 0x2cc: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_2cd:
	/* 0x2cd: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_2cf:
	/* 0x2cf: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_2d1:
	/* 0x2d1: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_2d3:
	/* 0x2d3: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_2d5:
	/* 0x2d5: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_2d6:
	/* 0x2d6: jmp    4f8 <cil_from_container+0x4f8> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_2db:
	/* 0x2db: mov    BYTE PTR [rsp+0x7],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_2df:
	/* 0x2df: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_2e4:
	/* 0x2e4: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2e9:
	/* 0x2e9: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2ec:
	/* 0x2ec: mov    esi,0x22 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 34ULL);
x86_l_2f1:
	/* 0x2f1: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2f6:
	/* 0x2f6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f8:
	/* 0x2f8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2fa:
	/* 0x2fa: js     85 <cil_from_container+0x85> */
	X86_SIM_X86_JCC(X86_CC_S, 0x2fa, 0x85, x86_l_85);
x86_l_300:
	/* 0x300: movzx  eax,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_305:
	/* 0x305: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_307:
	/* 0x307: je     16d <cil_from_container+0x16d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x307, 0x16d, x86_l_16d);
x86_l_30d:
	/* 0x30d: mov    esi,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 35ULL);
x86_l_312:
	/* 0x312: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_315:
	/* 0x315: je     3a6 <cil_from_container+0x3a6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x315, 0x3a6, x86_l_3a6);
x86_l_31b:
	/* 0x31b: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_320:
	/* 0x320: lea    rdx,[rsp+0x6] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_325:
	/* 0x325: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_328:
	/* 0x328: mov    esi,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 35ULL);
x86_l_32d:
	/* 0x32d: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_332:
	/* 0x332: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_334:
	/* 0x334: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_336:
	/* 0x336: js     85 <cil_from_container+0x85> */
	X86_SIM_X86_JCC(X86_CC_S, 0x336, 0x85, x86_l_85);
x86_l_33c:
	/* 0x33c: mov    esi,0x22 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 34ULL);
x86_l_341:
	/* 0x341: movzx  eax,BYTE PTR [rsp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_346:
	/* 0x346: cmp    BYTE PTR [rsp+0x8],al */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_34a:
	/* 0x34a: jne    39e <cil_from_container+0x39e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x34a, 0x39e, x86_l_39e);
x86_l_34c:
	/* 0x34c: movzx  eax,BYTE PTR [rsp+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_351:
	/* 0x351: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_354:
	/* 0x354: je     44e <cil_from_container+0x44e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x354, 0x44e, x86_l_44e);
x86_l_35a:
	/* 0x35a: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_35d:
	/* 0x35d: je     426 <cil_from_container+0x426> */
	X86_SIM_X86_JCC(X86_CC_E, 0x35d, 0x426, x86_l_426);
x86_l_363:
	/* 0x363: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_366:
	/* 0x366: jne    85 <cil_from_container+0x85> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x366, 0x85, x86_l_85);
x86_l_36c:
	/* 0x36c: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_371:
	/* 0x371: add    esi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_374:
	/* 0x374: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_379:
	/* 0x379: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_37c:
	/* 0x37c: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_381:
	/* 0x381: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_383:
	/* 0x383: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_386:
	/* 0x386: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_388:
	/* 0x388: movbe  cx,WORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOVBE_LOAD, X86_RCX, X86_RSP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_38f:
	/* 0x38f: movzx  ecx,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_392:
	/* 0x392: jmp    471 <cil_from_container+0x471> */
	X86_SIM_X86_JMP(0x392, 0x471, x86_l_471);
x86_l_397:
	/* 0x397: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_399:
	/* 0x399: jmp    2c8 <cil_from_container+0x2c8> */
	X86_SIM_X86_JMP(0x399, 0x2c8, x86_l_2c8);
x86_l_39e:
	/* 0x39e: movzx  esi,BYTE PTR [rsp+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_3a3:
	/* 0x3a3: add    esi,0x22 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 34ULL);
x86_l_3a6:
	/* 0x3a6: lea    r15d,[r15*4+0x22] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R15, 2), 34ULL);
x86_l_3ae:
	/* 0x3ae: cmp    esi,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_3b1:
	/* 0x3b1: jae    16d <cil_from_container+0x16d> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x3b1, 0x16d, x86_l_16d);
x86_l_3b7:
	/* 0x3b7: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_3bc:
	/* 0x3bc: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3c1:
	/* 0x3c1: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_3c4:
	/* 0x3c4: mov    QWORD PTR [rsp+0x20],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3c9:
	/* 0x3c9: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_3ce:
	/* 0x3ce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d0:
	/* 0x3d0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3d2:
	/* 0x3d2: js     85 <cil_from_container+0x85> */
	X86_SIM_X86_JCC(X86_CC_S, 0x3d2, 0x85, x86_l_85);
x86_l_3d8:
	/* 0x3d8: movzx  eax,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_3dd:
	/* 0x3dd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3df:
	/* 0x3df: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3e4:
	/* 0x3e4: je     16d <cil_from_container+0x16d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3e4, 0x16d, x86_l_16d);
x86_l_3ea:
	/* 0x3ea: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3ed:
	/* 0x3ed: je     48c <cil_from_container+0x48c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3ed, 0x48c, x86_l_48c);
x86_l_3f3:
	/* 0x3f3: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_3f8:
	/* 0x3f8: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_3fa:
	/* 0x3fa: lea    rdx,[rsp+0x6] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_3ff:
	/* 0x3ff: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_402:
	/* 0x402: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_407:
	/* 0x407: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_409:
	/* 0x409: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_40b:
	/* 0x40b: js     85 <cil_from_container+0x85> */
	X86_SIM_X86_JCC(X86_CC_S, 0x40b, 0x85, x86_l_85);
x86_l_411:
	/* 0x411: movzx  eax,BYTE PTR [rsp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_416:
	/* 0x416: cmp    BYTE PTR [rsp+0x8],al */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_41a:
	/* 0x41a: jne    482 <cil_from_container+0x482> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x41a, 0x482, x86_l_482);
x86_l_41c:
	/* 0x41c: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_421:
	/* 0x421: jmp    34c <cil_from_container+0x34c> */
	X86_SIM_X86_JMP(0x421, 0x34c, x86_l_34c);
x86_l_426:
	/* 0x426: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_42b:
	/* 0x42b: add    esi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_42e:
	/* 0x42e: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_433:
	/* 0x433: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_436:
	/* 0x436: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_43b:
	/* 0x43b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_43d:
	/* 0x43d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_43f:
	/* 0x43f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_441:
	/* 0x441: movbe  r15d,DWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOVBE_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 16ULL);
x86_l_448:
	/* 0x448: cmovs  r15d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R15, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_44c:
	/* 0x44c: jmp    475 <cil_from_container+0x475> */
	X86_SIM_X86_JMP(0x44c, 0x475, x86_l_475);
x86_l_44e:
	/* 0x44e: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_453:
	/* 0x453: add    esi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_456:
	/* 0x456: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_45b:
	/* 0x45b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_45e:
	/* 0x45e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_463:
	/* 0x463: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_465:
	/* 0x465: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_468:
	/* 0x468: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_46a:
	/* 0x46a: movbe  rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOVBE_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_471:
	/* 0x471: cmovns r15,rcx */
	X86_SIM_L_EXEC_CMOV(X86_R15, X86_RCX, X86_WIDTH_64, X86_CC_NS);
x86_l_475:
	/* 0x475: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_477:
	/* 0x477: jns    170 <cil_from_container+0x170> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x477, 0x170, x86_l_170);
x86_l_47d:
	/* 0x47d: jmp    85 <cil_from_container+0x85> */
	X86_SIM_X86_JMP(0x47d, 0x85, x86_l_85);
x86_l_482:
	/* 0x482: movzx  eax,BYTE PTR [rsp+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 6ULL);
x86_l_487:
	/* 0x487: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_48c:
	/* 0x48c: add    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_48e:
	/* 0x48e: cmp    esi,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_491:
	/* 0x491: jae    16d <cil_from_container+0x16d> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x491, 0x16d, x86_l_16d);
x86_l_497:
	/* 0x497: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_49c:
	/* 0x49c: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4a1:
	/* 0x4a1: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_4a4:
	/* 0x4a4: mov    r15,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSI, X86_WIDTH_64);
x86_l_4a7:
	/* 0x4a7: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_4ac:
	/* 0x4ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4ae:
	/* 0x4ae: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4b0:
	/* 0x4b0: js     85 <cil_from_container+0x85> */
	X86_SIM_X86_JCC(X86_CC_S, 0x4b0, 0x85, x86_l_85);
x86_l_4b6:
	/* 0x4b6: cmp    BYTE PTR [rsp+0x8],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738370ULL);
x86_l_4bb:
	/* 0x4bb: jb     16d <cil_from_container+0x16d> */
	X86_SIM_X86_JCC(X86_CC_B, 0x4bb, 0x16d, x86_l_16d);
x86_l_4c1:
	/* 0x4c1: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_4c6:
	/* 0x4c6: lea    esi,[r15+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_4ca:
	/* 0x4ca: lea    rdx,[rsp+0x6] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_4cf:
	/* 0x4cf: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_4d2:
	/* 0x4d2: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_4d7:
	/* 0x4d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4d9:
	/* 0x4d9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4db:
	/* 0x4db: js     85 <cil_from_container+0x85> */
	X86_SIM_X86_JCC(X86_CC_S, 0x4db, 0x85, x86_l_85);
x86_l_4e1:
	/* 0x4e1: movzx  eax,BYTE PTR [rsp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_4e6:
	/* 0x4e6: cmp    BYTE PTR [rsp+0x8],al */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4ea:
	/* 0x4ea: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_4ed:
	/* 0x4ed: jne    16d <cil_from_container+0x16d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4ed, 0x16d, x86_l_16d);
x86_l_4f3:
	/* 0x4f3: jmp    34c <cil_from_container+0x34c> */
	X86_SIM_X86_JMP(0x4f3, 0x34c, x86_l_34c);
x86_l_4f8:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
