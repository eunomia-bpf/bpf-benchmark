extern char __config_cluster_id_bits;
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
int cilium_bpf_lxc_cil_to_container_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 40ULL);
x86_l_7:
	/* 0x7: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_a:
	/* 0xa: movabs r15,0x20a510103 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_64, 8763015427ULL);
x86_l_14:
	/* 0x14: mov    rax,QWORD PTR [rip+0x1717] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_security_label)));
x86_l_1b:
	/* 0x1b: mov    ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1d:
	/* 0x1d: mov    edx,DWORD PTR [rdi+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_20:
	/* 0x20: sub    edx,DWORD PTR [rdi+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RDI, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_23:
	/* 0x23: mov    ecx,0xa6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 166ULL);
x86_l_28:
	/* 0x28: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a:
	/* 0x2a: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_2d:
	/* 0x2d: jb     149 <cil_to_container+0x149> */
	X86_SIM_X86_JCC(X86_CC_B, 0x2d, 0x149, x86_l_149);
x86_l_33:
	/* 0x33: mov    rdx,QWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_3a:
	/* 0x3a: movzx  r13d,WORD PTR [rdx+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_3f:
	/* 0x3f: cmp    r13d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 6ULL);
x86_l_43:
	/* 0x43: jb     149 <cil_to_container+0x149> */
	X86_SIM_X86_JCC(X86_CC_B, 0x43, 0x149, x86_l_149);
x86_l_49:
	/* 0x49: mov    DWORD PTR [rbx+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_50:
	/* 0x50: mov    DWORD PTR [rbx+0x2c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561024ULL);
x86_l_57:
	/* 0x57: mov    DWORD PTR [rbx+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_5e:
	/* 0x5e: mov    DWORD PTR [rbx+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_65:
	/* 0x65: mov    DWORD PTR [rbx+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_6c:
	/* 0x6c: mov    r9,QWORD PTR [rip+0x1717] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R9, (void *)(long)(((__u64)(long)&__config_tracing_ip_option_type)));
x86_l_73:
	/* 0x73: cmp    BYTE PTR [r9],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_77:
	/* 0x77: je     b9 <cil_to_container+0xb9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x77, 0xb9, x86_l_b9);
x86_l_79:
	/* 0x79: movzx  r14d,BYTE PTR [r9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R9, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_7d:
	/* 0x7d: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_80:
	/* 0x80: sub    eax,DWORD PTR [rbx+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_83:
	/* 0x83: cmp    eax,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_86:
	/* 0x86: jae    25a <cil_to_container+0x25a> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x86, 0x25a, x86_l_25a);
x86_l_8c:
	/* 0x8c: mov    r14,r9 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R9, X86_WIDTH_64);
x86_l_8f:
	/* 0x8f: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_97:
	/* 0x97: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_9c:
	/* 0x9c: mov    rdi,QWORD PTR [rip+0x1717] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_percpu_trace_id)));
x86_l_a3:
	/* 0xa3: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a8:
	/* 0xa8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aa:
	/* 0xaa: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ad:
	/* 0xad: je     b6 <cil_to_container+0xb6> */
	X86_SIM_X86_JCC(X86_CC_E, 0xad, 0xb6, x86_l_b6);
x86_l_af:
	/* 0xaf: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b6:
	/* 0xb6: mov    r9,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_R14, X86_WIDTH_64);
x86_l_b9:
	/* 0xb9: mov    r12d,DWORD PTR [rbx+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_c0:
	/* 0xc0: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_c3:
	/* 0xc3: and    eax,0xf00 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 3840ULL);
x86_l_c8:
	/* 0xc8: add    eax,0xfffff600 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4294964736ULL);
x86_l_cd:
	/* 0xcd: shr    eax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_d0:
	/* 0xd0: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d3:
	/* 0xd3: jg     1f0 <cil_to_container+0x1f0> */
	X86_SIM_X86_JCC(X86_CC_G, 0xd3, 0x1f0, x86_l_1f0);
x86_l_d9:
	/* 0xd9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_db:
	/* 0xdb: je     2c1 <cil_to_container+0x2c1> */
	X86_SIM_X86_JCC(X86_CC_E, 0xdb, 0x2c1, x86_l_2c1);
x86_l_e1:
	/* 0xe1: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e4:
	/* 0xe4: jne    2b9 <cil_to_container+0x2b9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe4, 0x2b9, x86_l_2b9);
x86_l_ea:
	/* 0xea: movzx  ecx,r12b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R12, X86_WIDTH_32, X86_WIDTH_8);
x86_l_ee:
	/* 0xee: mov    rax,QWORD PTR [rip+0x1717] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_cluster_id_bits)));
x86_l_f5:
	/* 0xf5: mov    edx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f7:
	/* 0xf7: mov    esi,0x7fffff00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2147483392ULL);
x86_l_fc:
	/* 0xfc: bzhi   edx,esi,edx */
	X86_SIM_RUN_OP(X86_OP_BZHI, X86_RDX, X86_RSI, X86_WIDTH_32, X86_RDX, 0);
x86_l_101:
	/* 0x101: mov    esi,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_103:
	/* 0x103: neg    sil */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_8, X86_ALU_NEG, 0);
x86_l_106:
	/* 0x106: shlx   edx,edx,esi */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RDX, X86_WIDTH_32, X86_RSI, X86_ALU_SHL);
x86_l_10b:
	/* 0x10b: and    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_AND);
x86_l_10e:
	/* 0x10e: mov    esi,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_110:
	/* 0x110: neg    sil */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_8, X86_ALU_NEG, 0);
x86_l_113:
	/* 0x113: shrx   edx,edx,esi */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RDX, X86_WIDTH_32, X86_RSI, X86_ALU_SHR);
x86_l_118:
	/* 0x118: or     edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_11a:
	/* 0x11a: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_11d:
	/* 0x11d: shr    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_120:
	/* 0x120: mov    esi,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_122:
	/* 0x122: mov    dil,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_8, 24ULL);
x86_l_125:
	/* 0x125: mov    r8b,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_8, 24ULL);
x86_l_128:
	/* 0x128: sub    r8b,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RSI, X86_WIDTH_8, X86_ALU_SUB);
x86_l_12b:
	/* 0x12b: bzhi   ecx,ecx,r8d */
	X86_SIM_RUN_OP(X86_OP_BZHI, X86_RCX, X86_RCX, X86_WIDTH_32, X86_R8, 0);
x86_l_130:
	/* 0x130: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_132:
	/* 0x132: sub    dil,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_135:
	/* 0x135: shlx   r14d,edx,edi */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_R14, X86_RDX, X86_WIDTH_32, X86_RDI, X86_ALU_SHL);
x86_l_13a:
	/* 0x13a: or     r14d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_13d:
	/* 0x13d: or     BYTE PTR [rbx+0x86],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RBX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 575525617666ULL);
x86_l_144:
	/* 0x144: jmp    323 <cil_to_container+0x323> */
	X86_SIM_X86_JMP(0x144, 0x323, x86_l_323);
x86_l_149:
	/* 0x149: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14c:
	/* 0x14c: mov    rdx,QWORD PTR [rip+0x1717] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_endpoint_id)));
x86_l_153:
	/* 0x153: movzx  edx,WORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_156:
	/* 0x156: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_158:
	/* 0x158: mov    DWORD PTR [rbx+0x28],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_15c:
	/* 0x15c: mov    DWORD PTR [rbx+0x2c],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_15f:
	/* 0x15f: mov    DWORD PTR [rbx+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_162:
	/* 0x162: mov    DWORD PTR [rbx+0x34],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_165:
	/* 0x165: mov    DWORD PTR [rbx+0x38],0xa850202 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240694657538ULL);
x86_l_16c:
	/* 0x16c: mov    r14d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_170:
	/* 0x170: add    r15,0x33fffd */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 3407869ULL);
x86_l_177:
	/* 0x177: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17c:
	/* 0x17c: mov    BYTE PTR [rsp+0x8],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_180:
	/* 0x180: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_185:
	/* 0x185: mov    rdi,QWORD PTR [rip+0x1717] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_18c:
	/* 0x18c: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_191:
	/* 0x191: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_193:
	/* 0x193: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_196:
	/* 0x196: je     1a1 <cil_to_container+0x1a1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x196, 0x1a1, x86_l_1a1);
x86_l_198:
	/* 0x198: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_19b:
	/* 0x19b: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_19f:
	/* 0x19f: jmp    1c9 <cil_to_container+0x1c9> */
	X86_SIM_X86_JMP(0x19f, 0x1c9, x86_l_1c9);
x86_l_1a1:
	/* 0x1a1: mov    QWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_1aa:
	/* 0x1aa: mov    QWORD PTR [rsp+0x18],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1af:
	/* 0x1af: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1b4:
	/* 0x1b4: mov    rdi,QWORD PTR [rip+0x1717] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1bb:
	/* 0x1bb: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c0:
	/* 0x1c0: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c5:
	/* 0x1c5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c7:
	/* 0x1c7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c9:
	/* 0x1c9: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1ce:
	/* 0x1ce: mov    rsi,QWORD PTR [rip+0x1717] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_1d5:
	/* 0x1d5: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1d8:
	/* 0x1d8: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_1dd:
	/* 0x1dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1df:
	/* 0x1df: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1e4:
	/* 0x1e4: add    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_1e8:
	/* 0x1e8: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_1ea:
	/* 0x1ea: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_1eb:
	/* 0x1eb: jmp    6a8 <cil_to_container+0x6a8> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_1f0:
	/* 0x1f0: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1f3:
	/* 0x1f3: je     31d <cil_to_container+0x31d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1f3, 0x31d, x86_l_31d);
x86_l_1f9:
	/* 0x1f9: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_1fc:
	/* 0x1fc: jne    2b9 <cil_to_container+0x2b9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1fc, 0x2b9, x86_l_2b9);
x86_l_202:
	/* 0x202: movzx  ecx,r12b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R12, X86_WIDTH_32, X86_WIDTH_8);
x86_l_206:
	/* 0x206: mov    rax,QWORD PTR [rip+0x171a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_cluster_id_bits)));
x86_l_20d:
	/* 0x20d: mov    edx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20f:
	/* 0x20f: mov    esi,0x7fffff00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2147483392ULL);
x86_l_214:
	/* 0x214: bzhi   edx,esi,edx */
	X86_SIM_RUN_OP(X86_OP_BZHI, X86_RDX, X86_RSI, X86_WIDTH_32, X86_RDX, 0);
x86_l_219:
	/* 0x219: mov    esi,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21b:
	/* 0x21b: neg    sil */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_8, X86_ALU_NEG, 0);
x86_l_21e:
	/* 0x21e: shlx   edx,edx,esi */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RDX, X86_WIDTH_32, X86_RSI, X86_ALU_SHL);
x86_l_223:
	/* 0x223: and    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_AND);
x86_l_226:
	/* 0x226: mov    esi,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_228:
	/* 0x228: neg    sil */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_8, X86_ALU_NEG, 0);
x86_l_22b:
	/* 0x22b: shrx   edx,edx,esi */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RDX, X86_WIDTH_32, X86_RSI, X86_ALU_SHR);
x86_l_230:
	/* 0x230: or     edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_232:
	/* 0x232: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_235:
	/* 0x235: shr    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_238:
	/* 0x238: mov    esi,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_23a:
	/* 0x23a: mov    dil,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_8, 24ULL);
x86_l_23d:
	/* 0x23d: mov    r8b,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_8, 24ULL);
x86_l_240:
	/* 0x240: sub    r8b,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RSI, X86_WIDTH_8, X86_ALU_SUB);
x86_l_243:
	/* 0x243: bzhi   ecx,ecx,r8d */
	X86_SIM_RUN_OP(X86_OP_BZHI, X86_RCX, X86_RCX, X86_WIDTH_32, X86_R8, 0);
x86_l_248:
	/* 0x248: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24a:
	/* 0x24a: sub    dil,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_24d:
	/* 0x24d: shlx   r14d,edx,edi */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_R14, X86_RDX, X86_WIDTH_32, X86_RDI, X86_ALU_SHL);
x86_l_252:
	/* 0x252: or     r14d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_255:
	/* 0x255: jmp    323 <cil_to_container+0x323> */
	X86_SIM_X86_JMP(0x255, 0x323, x86_l_323);
x86_l_25a:
	/* 0x25a: cmp    eax,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 34ULL);
x86_l_25d:
	/* 0x25d: jb     8c <cil_to_container+0x8c> */
	X86_SIM_X86_JCC(X86_CC_B, 0x25d, 0x8c, x86_l_8c);
x86_l_263:
	/* 0x263: mov    rax,QWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_26a:
	/* 0x26a: cmp    WORD PTR [rax+0xc],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 51539607560ULL);
x86_l_26f:
	/* 0x26f: jne    8c <cil_to_container+0x8c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x26f, 0x8c, x86_l_8c);
x86_l_275:
	/* 0x275: movzx  r12d,BYTE PTR [rax+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 14ULL);
x86_l_27a:
	/* 0x27a: and    r12d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_27e:
	/* 0x27e: cmp    r12b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_8, 6ULL);
x86_l_282:
	/* 0x282: jae    470 <cil_to_container+0x470> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x282, 0x470, x86_l_470);
x86_l_288:
	/* 0x288: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_28b:
	/* 0x28b: mov    r12,r9 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R9, X86_WIDTH_64);
x86_l_28e:
	/* 0x28e: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_296:
	/* 0x296: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_29b:
	/* 0x29b: mov    rdi,QWORD PTR [rip+0x171a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_percpu_trace_id)));
x86_l_2a2:
	/* 0x2a2: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a7:
	/* 0x2a7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a9:
	/* 0x2a9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2ac:
	/* 0x2ac: je     2b1 <cil_to_container+0x2b1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2ac, 0x2b1, x86_l_2b1);
x86_l_2ae:
	/* 0x2ae: mov    QWORD PTR [rax],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b1:
	/* 0x2b1: mov    r9,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_R12, X86_WIDTH_64);
x86_l_2b4:
	/* 0x2b4: jmp    b9 <cil_to_container+0xb9> */
	X86_SIM_X86_JMP(0x2b4, 0xb9, x86_l_b9);
x86_l_2b9:
	/* 0x2b9: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_2bf:
	/* 0x2bf: jmp    323 <cil_to_container+0x323> */
	X86_SIM_X86_JMP(0x2bf, 0x323, x86_l_323);
x86_l_2c1:
	/* 0x2c1: movzx  ecx,r12b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R12, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2c5:
	/* 0x2c5: mov    rax,QWORD PTR [rip+0x171a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_cluster_id_bits)));
x86_l_2cc:
	/* 0x2cc: mov    edx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ce:
	/* 0x2ce: mov    esi,0x7fffff00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2147483392ULL);
x86_l_2d3:
	/* 0x2d3: bzhi   edx,esi,edx */
	X86_SIM_RUN_OP(X86_OP_BZHI, X86_RDX, X86_RSI, X86_WIDTH_32, X86_RDX, 0);
x86_l_2d8:
	/* 0x2d8: mov    esi,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2da:
	/* 0x2da: neg    sil */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_8, X86_ALU_NEG, 0);
x86_l_2dd:
	/* 0x2dd: shlx   edx,edx,esi */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RDX, X86_WIDTH_32, X86_RSI, X86_ALU_SHL);
x86_l_2e2:
	/* 0x2e2: and    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_AND);
x86_l_2e5:
	/* 0x2e5: mov    esi,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e7:
	/* 0x2e7: neg    sil */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_8, X86_ALU_NEG, 0);
x86_l_2ea:
	/* 0x2ea: shrx   edx,edx,esi */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RDX, X86_WIDTH_32, X86_RSI, X86_ALU_SHR);
x86_l_2ef:
	/* 0x2ef: or     edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_2f1:
	/* 0x2f1: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_2f4:
	/* 0x2f4: shr    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_2f7:
	/* 0x2f7: mov    esi,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f9:
	/* 0x2f9: mov    dil,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_8, 24ULL);
x86_l_2fc:
	/* 0x2fc: mov    r8b,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_8, 24ULL);
x86_l_2ff:
	/* 0x2ff: sub    r8b,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RSI, X86_WIDTH_8, X86_ALU_SUB);
x86_l_302:
	/* 0x302: bzhi   ecx,ecx,r8d */
	X86_SIM_RUN_OP(X86_OP_BZHI, X86_RCX, X86_RCX, X86_WIDTH_32, X86_R8, 0);
x86_l_307:
	/* 0x307: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_309:
	/* 0x309: sub    dil,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_30c:
	/* 0x30c: shlx   r14d,edx,edi */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_R14, X86_RDX, X86_WIDTH_32, X86_RDI, X86_ALU_SHL);
x86_l_311:
	/* 0x311: or     r14d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_314:
	/* 0x314: or     BYTE PTR [rbx+0x86],0x1 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RBX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 575525617665ULL);
x86_l_31b:
	/* 0x31b: jmp    323 <cil_to_container+0x323> */
	X86_SIM_X86_JMP(0x31b, 0x323, x86_l_323);
x86_l_31d:
	/* 0x31d: mov    r14d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 1ULL);
x86_l_323:
	/* 0x323: mov    DWORD PTR [rbx+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_32d:
	/* 0x32d: mov    rax,QWORD PTR [rip+0x171a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_endpoint_id)));
x86_l_334:
	/* 0x334: movzx  eax,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_337:
	/* 0x337: mov    rax,QWORD PTR [rip+0x171a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_33e:
	/* 0x33e: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_340:
	/* 0x340: and    r12d,0xe00 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 3584ULL);
x86_l_347:
	/* 0x347: cmp    BYTE PTR [r9],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_34b:
	/* 0x34b: je     368 <cil_to_container+0x368> */
	X86_SIM_X86_JCC(X86_CC_E, 0x34b, 0x368, x86_l_368);
x86_l_34d:
	/* 0x34d: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_355:
	/* 0x355: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_35a:
	/* 0x35a: mov    rdi,QWORD PTR [rip+0x171a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_percpu_trace_id)));
x86_l_361:
	/* 0x361: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_366:
	/* 0x366: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_368:
	/* 0x368: cmp    r12d,0xa00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 2560ULL);
x86_l_36f:
	/* 0x36f: je     3c3 <cil_to_container+0x3c3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x36f, 0x3c3, x86_l_3c3);
x86_l_371:
	/* 0x371: mov    r12d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_375:
	/* 0x375: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_37a:
	/* 0x37a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_37f:
	/* 0x37f: mov    rdi,QWORD PTR [rip+0x171a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_386:
	/* 0x386: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_38b:
	/* 0x38b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38d:
	/* 0x38d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_390:
	/* 0x390: je     39b <cil_to_container+0x39b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x390, 0x39b, x86_l_39b);
x86_l_392:
	/* 0x392: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_395:
	/* 0x395: add    QWORD PTR [rax+0x8],r12 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_399:
	/* 0x399: jmp    3c3 <cil_to_container+0x3c3> */
	X86_SIM_X86_JMP(0x399, 0x3c3, x86_l_3c3);
x86_l_39b:
	/* 0x39b: mov    QWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_3a4:
	/* 0x3a4: mov    QWORD PTR [rsp+0x18],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3a9:
	/* 0x3a9: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3ae:
	/* 0x3ae: mov    rdi,QWORD PTR [rip+0x171a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_3b5:
	/* 0x3b5: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3ba:
	/* 0x3ba: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3bf:
	/* 0x3bf: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3c1:
	/* 0x3c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c3:
	/* 0x3c3: mov    eax,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_3c6:
	/* 0x3c6: rol    ax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_3ca:
	/* 0x3ca: movzx  eax,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_3cd:
	/* 0x3cd: cmp    eax,0x806 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2054ULL);
x86_l_3d2:
	/* 0x3d2: je     401 <cil_to_container+0x401> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3d2, 0x401, x86_l_401);
x86_l_3d4:
	/* 0x3d4: cmp    eax,0x800 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2048ULL);
x86_l_3d9:
	/* 0x3d9: jne    420 <cil_to_container+0x420> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3d9, 0x420, x86_l_420);
x86_l_3db:
	/* 0x3db: mov    eax,0x27 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 39ULL);
x86_l_3e0:
	/* 0x3e0: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_3e3:
	/* 0x3e3: mov    esi,0x22 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 34ULL);
x86_l_3e8:
	/* 0x3e8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ea:
	/* 0x3ea: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3ed:
	/* 0x3ed: sub    eax,DWORD PTR [rbx+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_3f0:
	/* 0x3f0: mov    ecx,0x86 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 134ULL);
x86_l_3f5:
	/* 0x3f5: cmp    eax,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 34ULL);
x86_l_3f8:
	/* 0x3f8: jae    420 <cil_to_container+0x420> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x3f8, 0x420, x86_l_420);
x86_l_3fa:
	/* 0x3fa: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3fc:
	/* 0x3fc: jmp    14c <cil_to_container+0x14c> */
	X86_SIM_X86_JMP(0x3fc, 0x14c, x86_l_14c);
x86_l_401:
	/* 0x401: mov    eax,0x27 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 39ULL);
x86_l_406:
	/* 0x406: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_409:
	/* 0x409: mov    esi,0x2a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 42ULL);
x86_l_40e:
	/* 0x40e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_410:
	/* 0x410: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_413:
	/* 0x413: sub    eax,DWORD PTR [rbx+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_416:
	/* 0x416: mov    ecx,0x86 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 134ULL);
x86_l_41b:
	/* 0x41b: cmp    eax,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 42ULL);
x86_l_41e:
	/* 0x41e: jb     3fa <cil_to_container+0x3fa> */
	X86_SIM_X86_JCC(X86_CC_B, 0x41e, 0x3fa, x86_l_3fa);
x86_l_420:
	/* 0x420: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_422:
	/* 0x422: cmp    r13d,0x608 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 1544ULL);
x86_l_429:
	/* 0x429: je     1e4 <cil_to_container+0x1e4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x429, 0x1e4, x86_l_1e4);
x86_l_42f:
	/* 0x42f: mov    ecx,0x8b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 139ULL);
x86_l_434:
	/* 0x434: cmp    r13d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 8ULL);
x86_l_438:
	/* 0x438: jne    14c <cil_to_container+0x14c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x438, 0x14c, x86_l_14c);
x86_l_43e:
	/* 0x43e: mov    rax,QWORD PTR [rip+0x171a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_security_label)));
x86_l_445:
	/* 0x445: mov    ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_447:
	/* 0x447: mov    DWORD PTR [rbx+0x28],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_44b:
	/* 0x44b: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_450:
	/* 0x450: mov    rsi,QWORD PTR [rip+0x171a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_457:
	/* 0x457: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_45a:
	/* 0x45a: mov    edx,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 28ULL);
x86_l_45f:
	/* 0x45f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_461:
	/* 0x461: mov    ecx,0x8c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 140ULL);
x86_l_466:
	/* 0x466: mov    eax,0x1c00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 7168ULL);
x86_l_46b:
	/* 0x46b: jmp    14c <cil_to_container+0x14c> */
	X86_SIM_X86_JMP(0x46b, 0x14c, x86_l_14c);
x86_l_470:
	/* 0x470: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_475:
	/* 0x475: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_47a:
	/* 0x47a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_47d:
	/* 0x47d: mov    esi,0x22 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 34ULL);
x86_l_482:
	/* 0x482: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_487:
	/* 0x487: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_489:
	/* 0x489: mov    r9,QWORD PTR [rip+0x171a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R9, (void *)(long)(((__u64)(long)&__config_tracing_ip_option_type)));
x86_l_490:
	/* 0x490: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_492:
	/* 0x492: js     8c <cil_to_container+0x8c> */
	X86_SIM_X86_JCC(X86_CC_S, 0x492, 0x8c, x86_l_8c);
x86_l_498:
	/* 0x498: movzx  eax,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_49d:
	/* 0x49d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_49f:
	/* 0x49f: je     288 <cil_to_container+0x288> */
	X86_SIM_X86_JCC(X86_CC_E, 0x49f, 0x288, x86_l_288);
x86_l_4a5:
	/* 0x4a5: mov    esi,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 35ULL);
x86_l_4aa:
	/* 0x4aa: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4ad:
	/* 0x4ad: je     53a <cil_to_container+0x53a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4ad, 0x53a, x86_l_53a);
x86_l_4b3:
	/* 0x4b3: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_4b8:
	/* 0x4b8: lea    rdx,[rsp+0x7] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_4bd:
	/* 0x4bd: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_4c0:
	/* 0x4c0: mov    esi,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 35ULL);
x86_l_4c5:
	/* 0x4c5: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_4ca:
	/* 0x4ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4cc:
	/* 0x4cc: mov    r9,QWORD PTR [rip+0x171a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R9, (void *)(long)(((__u64)(long)&__config_tracing_ip_option_type)));
x86_l_4d3:
	/* 0x4d3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4d5:
	/* 0x4d5: js     8c <cil_to_container+0x8c> */
	X86_SIM_X86_JCC(X86_CC_S, 0x4d5, 0x8c, x86_l_8c);
x86_l_4db:
	/* 0x4db: mov    esi,0x22 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 34ULL);
x86_l_4e0:
	/* 0x4e0: cmp    BYTE PTR [rsp+0x8],r14b */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R14, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4e5:
	/* 0x4e5: jne    532 <cil_to_container+0x532> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4e5, 0x532, x86_l_532);
x86_l_4e7:
	/* 0x4e7: movzx  eax,BYTE PTR [rsp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_4ec:
	/* 0x4ec: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_4ef:
	/* 0x4ef: je     5ec <cil_to_container+0x5ec> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4ef, 0x5ec, x86_l_5ec);
x86_l_4f5:
	/* 0x4f5: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_4f8:
	/* 0x4f8: je     5c4 <cil_to_container+0x5c4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4f8, 0x5c4, x86_l_5c4);
x86_l_4fe:
	/* 0x4fe: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_501:
	/* 0x501: jne    8c <cil_to_container+0x8c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x501, 0x8c, x86_l_8c);
x86_l_507:
	/* 0x507: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_50c:
	/* 0x50c: add    esi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_50f:
	/* 0x50f: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_514:
	/* 0x514: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_517:
	/* 0x517: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_51c:
	/* 0x51c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_51e:
	/* 0x51e: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_521:
	/* 0x521: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_523:
	/* 0x523: movbe  cx,WORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOVBE_LOAD, X86_RCX, X86_RSP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_52a:
	/* 0x52a: movzx  ecx,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_52d:
	/* 0x52d: jmp    60f <cil_to_container+0x60f> */
	X86_SIM_X86_JMP(0x52d, 0x60f, x86_l_60f);
x86_l_532:
	/* 0x532: movzx  esi,BYTE PTR [rsp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_537:
	/* 0x537: add    esi,0x22 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 34ULL);
x86_l_53a:
	/* 0x53a: lea    r12d,[r12*4+0x22] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 2), 34ULL);
x86_l_542:
	/* 0x542: cmp    esi,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_545:
	/* 0x545: jae    288 <cil_to_container+0x288> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x545, 0x288, x86_l_288);
x86_l_54b:
	/* 0x54b: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_550:
	/* 0x550: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_555:
	/* 0x555: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_558:
	/* 0x558: mov    QWORD PTR [rsp+0x20],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_55d:
	/* 0x55d: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_562:
	/* 0x562: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_564:
	/* 0x564: mov    r9,QWORD PTR [rip+0x171a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R9, (void *)(long)(((__u64)(long)&__config_tracing_ip_option_type)));
x86_l_56b:
	/* 0x56b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_56d:
	/* 0x56d: js     8c <cil_to_container+0x8c> */
	X86_SIM_X86_JCC(X86_CC_S, 0x56d, 0x8c, x86_l_8c);
x86_l_573:
	/* 0x573: movzx  eax,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_578:
	/* 0x578: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_57a:
	/* 0x57a: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_57f:
	/* 0x57f: je     288 <cil_to_container+0x288> */
	X86_SIM_X86_JCC(X86_CC_E, 0x57f, 0x288, x86_l_288);
x86_l_585:
	/* 0x585: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_588:
	/* 0x588: je     631 <cil_to_container+0x631> */
	X86_SIM_X86_JCC(X86_CC_E, 0x588, 0x631, x86_l_631);
x86_l_58e:
	/* 0x58e: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_593:
	/* 0x593: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_595:
	/* 0x595: lea    rdx,[rsp+0x7] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_59a:
	/* 0x59a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_59d:
	/* 0x59d: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_5a2:
	/* 0x5a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5a4:
	/* 0x5a4: mov    r9,QWORD PTR [rip+0x171a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R9, (void *)(long)(((__u64)(long)&__config_tracing_ip_option_type)));
x86_l_5ab:
	/* 0x5ab: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5ad:
	/* 0x5ad: js     8c <cil_to_container+0x8c> */
	X86_SIM_X86_JCC(X86_CC_S, 0x5ad, 0x8c, x86_l_8c);
x86_l_5b3:
	/* 0x5b3: cmp    BYTE PTR [rsp+0x8],r14b */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R14, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5b8:
	/* 0x5b8: jne    627 <cil_to_container+0x627> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x5b8, 0x627, x86_l_627);
x86_l_5ba:
	/* 0x5ba: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5bf:
	/* 0x5bf: jmp    4e7 <cil_to_container+0x4e7> */
	X86_SIM_X86_JMP(0x5bf, 0x4e7, x86_l_4e7);
x86_l_5c4:
	/* 0x5c4: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_5c9:
	/* 0x5c9: add    esi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_5cc:
	/* 0x5cc: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5d1:
	/* 0x5d1: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_5d4:
	/* 0x5d4: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_5d9:
	/* 0x5d9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5db:
	/* 0x5db: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5dd:
	/* 0x5dd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5df:
	/* 0x5df: movbe  r14d,DWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOVBE_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 16ULL);
x86_l_5e6:
	/* 0x5e6: cmovs  r14d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R14, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_5ea:
	/* 0x5ea: jmp    613 <cil_to_container+0x613> */
	X86_SIM_X86_JMP(0x5ea, 0x613, x86_l_613);
x86_l_5ec:
	/* 0x5ec: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_5f1:
	/* 0x5f1: add    esi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_5f4:
	/* 0x5f4: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5f9:
	/* 0x5f9: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_5fc:
	/* 0x5fc: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_601:
	/* 0x601: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_603:
	/* 0x603: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_606:
	/* 0x606: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_608:
	/* 0x608: movbe  rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOVBE_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_60f:
	/* 0x60f: cmovns r14,rcx */
	X86_SIM_L_EXEC_CMOV(X86_R14, X86_RCX, X86_WIDTH_64, X86_CC_NS);
x86_l_613:
	/* 0x613: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_615:
	/* 0x615: mov    r9,QWORD PTR [rip+0x171a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R9, (void *)(long)(((__u64)(long)&__config_tracing_ip_option_type)));
x86_l_61c:
	/* 0x61c: jns    28b <cil_to_container+0x28b> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x61c, 0x28b, x86_l_28b);
x86_l_622:
	/* 0x622: jmp    8c <cil_to_container+0x8c> */
	X86_SIM_X86_JMP(0x622, 0x8c, x86_l_8c);
x86_l_627:
	/* 0x627: movzx  eax,BYTE PTR [rsp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_62c:
	/* 0x62c: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_631:
	/* 0x631: add    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_633:
	/* 0x633: cmp    esi,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_636:
	/* 0x636: jae    288 <cil_to_container+0x288> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x636, 0x288, x86_l_288);
x86_l_63c:
	/* 0x63c: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_641:
	/* 0x641: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_646:
	/* 0x646: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_649:
	/* 0x649: mov    r12,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RSI, X86_WIDTH_64);
x86_l_64c:
	/* 0x64c: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_651:
	/* 0x651: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_653:
	/* 0x653: mov    r9,QWORD PTR [rip+0x171a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R9, (void *)(long)(((__u64)(long)&__config_tracing_ip_option_type)));
x86_l_65a:
	/* 0x65a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_65c:
	/* 0x65c: js     8c <cil_to_container+0x8c> */
	X86_SIM_X86_JCC(X86_CC_S, 0x65c, 0x8c, x86_l_8c);
x86_l_662:
	/* 0x662: cmp    BYTE PTR [rsp+0x8],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738370ULL);
x86_l_667:
	/* 0x667: jb     288 <cil_to_container+0x288> */
	X86_SIM_X86_JCC(X86_CC_B, 0x667, 0x288, x86_l_288);
x86_l_66d:
	/* 0x66d: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_672:
	/* 0x672: lea    esi,[r12+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_677:
	/* 0x677: lea    rdx,[rsp+0x7] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_67c:
	/* 0x67c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_67f:
	/* 0x67f: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_684:
	/* 0x684: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_686:
	/* 0x686: mov    r9,QWORD PTR [rip+0x171a] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R9, (void *)(long)(((__u64)(long)&__config_tracing_ip_option_type)));
x86_l_68d:
	/* 0x68d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_68f:
	/* 0x68f: js     8c <cil_to_container+0x8c> */
	X86_SIM_X86_JCC(X86_CC_S, 0x68f, 0x8c, x86_l_8c);
x86_l_695:
	/* 0x695: cmp    BYTE PTR [rsp+0x8],r14b */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R14, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_69a:
	/* 0x69a: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_69d:
	/* 0x69d: jne    288 <cil_to_container+0x288> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x69d, 0x288, x86_l_288);
x86_l_6a3:
	/* 0x6a3: jmp    4e7 <cil_to_container+0x4e7> */
	X86_SIM_X86_JMP(0x6a3, 0x4e7, x86_l_4e7);
x86_l_6a8:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
