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
	/* 0x11: movabs r15,0x20a510103 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_64, 8763015427ULL);
x86_l_1b:
	/* 0x1b: mov    rax,QWORD PTR [rip+0x1710] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_security_label)));
x86_l_22:
	/* 0x22: mov    ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_24:
	/* 0x24: mov    edx,DWORD PTR [rdi+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_27:
	/* 0x27: sub    edx,DWORD PTR [rdi+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RDI, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_2a:
	/* 0x2a: mov    ecx,0xa6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 166ULL);
x86_l_2f:
	/* 0x2f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_31:
	/* 0x31: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_34:
	/* 0x34: jb     150 <cil_to_container+0x150> */
	X86_SIM_X86_JCC(X86_CC_B, 0x34, 0x150, x86_l_150);
x86_l_3a:
	/* 0x3a: mov    rdx,QWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_41:
	/* 0x41: movzx  r13d,WORD PTR [rdx+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 12ULL);
x86_l_46:
	/* 0x46: cmp    r13d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 6ULL);
x86_l_4a:
	/* 0x4a: jb     150 <cil_to_container+0x150> */
	X86_SIM_X86_JCC(X86_CC_B, 0x4a, 0x150, x86_l_150);
x86_l_50:
	/* 0x50: mov    DWORD PTR [rbx+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_57:
	/* 0x57: mov    DWORD PTR [rbx+0x2c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 188978561024ULL);
x86_l_5e:
	/* 0x5e: mov    DWORD PTR [rbx+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_65:
	/* 0x65: mov    DWORD PTR [rbx+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_6c:
	/* 0x6c: mov    DWORD PTR [rbx+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_73:
	/* 0x73: mov    r9,QWORD PTR [rip+0x1710] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R9, (void *)(long)(((__u64)(long)&__config_tracing_ip_option_type)));
x86_l_7a:
	/* 0x7a: cmp    BYTE PTR [r9],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7e:
	/* 0x7e: je     c0 <cil_to_container+0xc0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7e, 0xc0, x86_l_c0);
x86_l_80:
	/* 0x80: movzx  r14d,BYTE PTR [r9] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_R9, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_84:
	/* 0x84: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_87:
	/* 0x87: sub    eax,DWORD PTR [rbx+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_8a:
	/* 0x8a: cmp    eax,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_8d:
	/* 0x8d: jae    268 <cil_to_container+0x268> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x8d, 0x268, x86_l_268);
x86_l_93:
	/* 0x93: mov    r14,r9 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R9, X86_WIDTH_64);
x86_l_96:
	/* 0x96: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_9e:
	/* 0x9e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a3:
	/* 0xa3: mov    rdi,QWORD PTR [rip+0x1710] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_percpu_trace_id)));
x86_l_aa:
	/* 0xaa: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_af:
	/* 0xaf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b1:
	/* 0xb1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b4:
	/* 0xb4: je     bd <cil_to_container+0xbd> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb4, 0xbd, x86_l_bd);
x86_l_b6:
	/* 0xb6: mov    QWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bd:
	/* 0xbd: mov    r9,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_R14, X86_WIDTH_64);
x86_l_c0:
	/* 0xc0: mov    r12d,DWORD PTR [rbx+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_c7:
	/* 0xc7: mov    eax,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_32);
x86_l_ca:
	/* 0xca: and    eax,0xf00 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 3840ULL);
x86_l_cf:
	/* 0xcf: add    eax,0xfffff600 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4294964736ULL);
x86_l_d4:
	/* 0xd4: shr    eax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_d7:
	/* 0xd7: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_da:
	/* 0xda: jg     1fe <cil_to_container+0x1fe> */
	X86_SIM_X86_JCC(X86_CC_G, 0xda, 0x1fe, x86_l_1fe);
x86_l_e0:
	/* 0xe0: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_e2:
	/* 0xe2: je     2cf <cil_to_container+0x2cf> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe2, 0x2cf, x86_l_2cf);
x86_l_e8:
	/* 0xe8: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_eb:
	/* 0xeb: jne    2c7 <cil_to_container+0x2c7> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xeb, 0x2c7, x86_l_2c7);
x86_l_f1:
	/* 0xf1: movzx  ecx,r12b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R12, X86_WIDTH_32, X86_WIDTH_8);
x86_l_f5:
	/* 0xf5: mov    rax,QWORD PTR [rip+0x1710] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_cluster_id_bits)));
x86_l_fc:
	/* 0xfc: mov    edx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fe:
	/* 0xfe: mov    esi,0x7fffff00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2147483392ULL);
x86_l_103:
	/* 0x103: bzhi   edx,esi,edx */
	X86_SIM_RUN_OP(X86_OP_BZHI, X86_RDX, X86_RSI, X86_WIDTH_32, X86_RDX, 0);
x86_l_108:
	/* 0x108: mov    esi,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10a:
	/* 0x10a: neg    sil */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_8, X86_ALU_NEG, 0);
x86_l_10d:
	/* 0x10d: shlx   edx,edx,esi */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RDX, X86_WIDTH_32, X86_RSI, X86_ALU_SHL);
x86_l_112:
	/* 0x112: and    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_AND);
x86_l_115:
	/* 0x115: mov    esi,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_117:
	/* 0x117: neg    sil */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_8, X86_ALU_NEG, 0);
x86_l_11a:
	/* 0x11a: shrx   edx,edx,esi */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RDX, X86_WIDTH_32, X86_RSI, X86_ALU_SHR);
x86_l_11f:
	/* 0x11f: or     edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_121:
	/* 0x121: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_124:
	/* 0x124: shr    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_127:
	/* 0x127: mov    esi,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_129:
	/* 0x129: mov    dil,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_8, 24ULL);
x86_l_12c:
	/* 0x12c: mov    r8b,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_8, 24ULL);
x86_l_12f:
	/* 0x12f: sub    r8b,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RSI, X86_WIDTH_8, X86_ALU_SUB);
x86_l_132:
	/* 0x132: bzhi   ecx,ecx,r8d */
	X86_SIM_RUN_OP(X86_OP_BZHI, X86_RCX, X86_RCX, X86_WIDTH_32, X86_R8, 0);
x86_l_137:
	/* 0x137: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_139:
	/* 0x139: sub    dil,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_13c:
	/* 0x13c: shlx   r14d,edx,edi */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_R14, X86_RDX, X86_WIDTH_32, X86_RDI, X86_ALU_SHL);
x86_l_141:
	/* 0x141: or     r14d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_144:
	/* 0x144: or     BYTE PTR [rbx+0x86],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RBX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 575525617666ULL);
x86_l_14b:
	/* 0x14b: jmp    331 <cil_to_container+0x331> */
	X86_SIM_X86_JMP(0x14b, 0x331, x86_l_331);
x86_l_150:
	/* 0x150: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_153:
	/* 0x153: mov    rdx,QWORD PTR [rip+0x1710] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_endpoint_id)));
x86_l_15a:
	/* 0x15a: movzx  edx,WORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_15d:
	/* 0x15d: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_15f:
	/* 0x15f: mov    DWORD PTR [rbx+0x28],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_163:
	/* 0x163: mov    DWORD PTR [rbx+0x2c],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_166:
	/* 0x166: mov    DWORD PTR [rbx+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_169:
	/* 0x169: mov    DWORD PTR [rbx+0x34],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_16c:
	/* 0x16c: mov    DWORD PTR [rbx+0x38],0xa850202 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240694657538ULL);
x86_l_173:
	/* 0x173: mov    r14d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_177:
	/* 0x177: add    r15,0x33fffd */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 3407869ULL);
x86_l_17e:
	/* 0x17e: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_183:
	/* 0x183: mov    BYTE PTR [rsp+0x8],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_187:
	/* 0x187: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_18c:
	/* 0x18c: mov    rdi,QWORD PTR [rip+0x1710] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_193:
	/* 0x193: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_198:
	/* 0x198: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_19a:
	/* 0x19a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_19d:
	/* 0x19d: je     1a8 <cil_to_container+0x1a8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x19d, 0x1a8, x86_l_1a8);
x86_l_19f:
	/* 0x19f: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_1a2:
	/* 0x1a2: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_1a6:
	/* 0x1a6: jmp    1d0 <cil_to_container+0x1d0> */
	X86_SIM_X86_JMP(0x1a6, 0x1d0, x86_l_1d0);
x86_l_1a8:
	/* 0x1a8: mov    QWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_1b1:
	/* 0x1b1: mov    QWORD PTR [rsp+0x18],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1b6:
	/* 0x1b6: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1bb:
	/* 0x1bb: mov    rdi,QWORD PTR [rip+0x1710] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_1c2:
	/* 0x1c2: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1c7:
	/* 0x1c7: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1cc:
	/* 0x1cc: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ce:
	/* 0x1ce: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d0:
	/* 0x1d0: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_1d5:
	/* 0x1d5: mov    rsi,QWORD PTR [rip+0x1710] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_1dc:
	/* 0x1dc: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1df:
	/* 0x1df: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_1e4:
	/* 0x1e4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e6:
	/* 0x1e6: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1eb:
	/* 0x1eb: add    rsp,0x28 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 40ULL);
x86_l_1ef:
	/* 0x1ef: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_1f0:
	/* 0x1f0: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_1f2:
	/* 0x1f2: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_1f4:
	/* 0x1f4: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_1f6:
	/* 0x1f6: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_1f8:
	/* 0x1f8: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_1f9:
	/* 0x1f9: jmp    6b6 <cil_to_container+0x6b6> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_1fe:
	/* 0x1fe: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_201:
	/* 0x201: je     32b <cil_to_container+0x32b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x201, 0x32b, x86_l_32b);
x86_l_207:
	/* 0x207: cmp    eax,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 5ULL);
x86_l_20a:
	/* 0x20a: jne    2c7 <cil_to_container+0x2c7> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x20a, 0x2c7, x86_l_2c7);
x86_l_210:
	/* 0x210: movzx  ecx,r12b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R12, X86_WIDTH_32, X86_WIDTH_8);
x86_l_214:
	/* 0x214: mov    rax,QWORD PTR [rip+0x170c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_cluster_id_bits)));
x86_l_21b:
	/* 0x21b: mov    edx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_21d:
	/* 0x21d: mov    esi,0x7fffff00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2147483392ULL);
x86_l_222:
	/* 0x222: bzhi   edx,esi,edx */
	X86_SIM_RUN_OP(X86_OP_BZHI, X86_RDX, X86_RSI, X86_WIDTH_32, X86_RDX, 0);
x86_l_227:
	/* 0x227: mov    esi,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_229:
	/* 0x229: neg    sil */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_8, X86_ALU_NEG, 0);
x86_l_22c:
	/* 0x22c: shlx   edx,edx,esi */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RDX, X86_WIDTH_32, X86_RSI, X86_ALU_SHL);
x86_l_231:
	/* 0x231: and    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_AND);
x86_l_234:
	/* 0x234: mov    esi,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_236:
	/* 0x236: neg    sil */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_8, X86_ALU_NEG, 0);
x86_l_239:
	/* 0x239: shrx   edx,edx,esi */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RDX, X86_WIDTH_32, X86_RSI, X86_ALU_SHR);
x86_l_23e:
	/* 0x23e: or     edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_240:
	/* 0x240: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_243:
	/* 0x243: shr    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_246:
	/* 0x246: mov    esi,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_248:
	/* 0x248: mov    dil,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_8, 24ULL);
x86_l_24b:
	/* 0x24b: mov    r8b,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_8, 24ULL);
x86_l_24e:
	/* 0x24e: sub    r8b,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RSI, X86_WIDTH_8, X86_ALU_SUB);
x86_l_251:
	/* 0x251: bzhi   ecx,ecx,r8d */
	X86_SIM_RUN_OP(X86_OP_BZHI, X86_RCX, X86_RCX, X86_WIDTH_32, X86_R8, 0);
x86_l_256:
	/* 0x256: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_258:
	/* 0x258: sub    dil,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_25b:
	/* 0x25b: shlx   r14d,edx,edi */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_R14, X86_RDX, X86_WIDTH_32, X86_RDI, X86_ALU_SHL);
x86_l_260:
	/* 0x260: or     r14d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_263:
	/* 0x263: jmp    331 <cil_to_container+0x331> */
	X86_SIM_X86_JMP(0x263, 0x331, x86_l_331);
x86_l_268:
	/* 0x268: cmp    eax,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 34ULL);
x86_l_26b:
	/* 0x26b: jb     93 <cil_to_container+0x93> */
	X86_SIM_X86_JCC(X86_CC_B, 0x26b, 0x93, x86_l_93);
x86_l_271:
	/* 0x271: mov    rax,QWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_278:
	/* 0x278: cmp    WORD PTR [rax+0xc],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 51539607560ULL);
x86_l_27d:
	/* 0x27d: jne    93 <cil_to_container+0x93> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x27d, 0x93, x86_l_93);
x86_l_283:
	/* 0x283: movzx  r12d,BYTE PTR [rax+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 14ULL);
x86_l_288:
	/* 0x288: and    r12d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_28c:
	/* 0x28c: cmp    r12b,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_8, 6ULL);
x86_l_290:
	/* 0x290: jae    47e <cil_to_container+0x47e> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x290, 0x47e, x86_l_47e);
x86_l_296:
	/* 0x296: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_299:
	/* 0x299: mov    r12,r9 */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_R9, X86_WIDTH_64);
x86_l_29c:
	/* 0x29c: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_2a4:
	/* 0x2a4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a9:
	/* 0x2a9: mov    rdi,QWORD PTR [rip+0x170c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_percpu_trace_id)));
x86_l_2b0:
	/* 0x2b0: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2b5:
	/* 0x2b5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b7:
	/* 0x2b7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2ba:
	/* 0x2ba: je     2bf <cil_to_container+0x2bf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2ba, 0x2bf, x86_l_2bf);
x86_l_2bc:
	/* 0x2bc: mov    QWORD PTR [rax],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2bf:
	/* 0x2bf: mov    r9,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_R12, X86_WIDTH_64);
x86_l_2c2:
	/* 0x2c2: jmp    c0 <cil_to_container+0xc0> */
	X86_SIM_X86_JMP(0x2c2, 0xc0, x86_l_c0);
x86_l_2c7:
	/* 0x2c7: mov    r14d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 2ULL);
x86_l_2cd:
	/* 0x2cd: jmp    331 <cil_to_container+0x331> */
	X86_SIM_X86_JMP(0x2cd, 0x331, x86_l_331);
x86_l_2cf:
	/* 0x2cf: movzx  ecx,r12b */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_R12, X86_WIDTH_32, X86_WIDTH_8);
x86_l_2d3:
	/* 0x2d3: mov    rax,QWORD PTR [rip+0x170c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_cluster_id_bits)));
x86_l_2da:
	/* 0x2da: mov    edx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2dc:
	/* 0x2dc: mov    esi,0x7fffff00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2147483392ULL);
x86_l_2e1:
	/* 0x2e1: bzhi   edx,esi,edx */
	X86_SIM_RUN_OP(X86_OP_BZHI, X86_RDX, X86_RSI, X86_WIDTH_32, X86_RDX, 0);
x86_l_2e6:
	/* 0x2e6: mov    esi,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2e8:
	/* 0x2e8: neg    sil */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_8, X86_ALU_NEG, 0);
x86_l_2eb:
	/* 0x2eb: shlx   edx,edx,esi */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RDX, X86_WIDTH_32, X86_RSI, X86_ALU_SHL);
x86_l_2f0:
	/* 0x2f0: and    edx,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R12, X86_WIDTH_32, X86_ALU_AND);
x86_l_2f3:
	/* 0x2f3: mov    esi,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2f5:
	/* 0x2f5: neg    sil */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_8, X86_ALU_NEG, 0);
x86_l_2f8:
	/* 0x2f8: shrx   edx,edx,esi */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RDX, X86_WIDTH_32, X86_RSI, X86_ALU_SHR);
x86_l_2fd:
	/* 0x2fd: or     edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_2ff:
	/* 0x2ff: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_302:
	/* 0x302: shr    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_305:
	/* 0x305: mov    esi,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_307:
	/* 0x307: mov    dil,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDI, X86_WIDTH_8, 24ULL);
x86_l_30a:
	/* 0x30a: mov    r8b,0x18 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_8, 24ULL);
x86_l_30d:
	/* 0x30d: sub    r8b,sil */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_RSI, X86_WIDTH_8, X86_ALU_SUB);
x86_l_310:
	/* 0x310: bzhi   ecx,ecx,r8d */
	X86_SIM_RUN_OP(X86_OP_BZHI, X86_RCX, X86_RCX, X86_WIDTH_32, X86_R8, 0);
x86_l_315:
	/* 0x315: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_317:
	/* 0x317: sub    dil,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_31a:
	/* 0x31a: shlx   r14d,edx,edi */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_R14, X86_RDX, X86_WIDTH_32, X86_RDI, X86_ALU_SHL);
x86_l_31f:
	/* 0x31f: or     r14d,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_322:
	/* 0x322: or     BYTE PTR [rbx+0x86],0x1 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_RBX, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 575525617665ULL);
x86_l_329:
	/* 0x329: jmp    331 <cil_to_container+0x331> */
	X86_SIM_X86_JMP(0x329, 0x331, x86_l_331);
x86_l_32b:
	/* 0x32b: mov    r14d,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 1ULL);
x86_l_331:
	/* 0x331: mov    DWORD PTR [rbx+0xa8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 721554505728ULL);
x86_l_33b:
	/* 0x33b: mov    rax,QWORD PTR [rip+0x170c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_endpoint_id)));
x86_l_342:
	/* 0x342: movzx  eax,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_345:
	/* 0x345: mov    rax,QWORD PTR [rip+0x170c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_34c:
	/* 0x34c: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_34e:
	/* 0x34e: and    r12d,0xe00 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_AND, 3584ULL);
x86_l_355:
	/* 0x355: cmp    BYTE PTR [r9],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_359:
	/* 0x359: je     376 <cil_to_container+0x376> */
	X86_SIM_X86_JCC(X86_CC_E, 0x359, 0x376, x86_l_376);
x86_l_35b:
	/* 0x35b: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_363:
	/* 0x363: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_368:
	/* 0x368: mov    rdi,QWORD PTR [rip+0x170c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_percpu_trace_id)));
x86_l_36f:
	/* 0x36f: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_374:
	/* 0x374: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_376:
	/* 0x376: cmp    r12d,0xa00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_32, 2560ULL);
x86_l_37d:
	/* 0x37d: je     3d1 <cil_to_container+0x3d1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x37d, 0x3d1, x86_l_3d1);
x86_l_37f:
	/* 0x37f: mov    r12d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_383:
	/* 0x383: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_388:
	/* 0x388: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_38d:
	/* 0x38d: mov    rdi,QWORD PTR [rip+0x170c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_394:
	/* 0x394: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_399:
	/* 0x399: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_39b:
	/* 0x39b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_39e:
	/* 0x39e: je     3a9 <cil_to_container+0x3a9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x39e, 0x3a9, x86_l_3a9);
x86_l_3a0:
	/* 0x3a0: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_3a3:
	/* 0x3a3: add    QWORD PTR [rax+0x8],r12 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_3a7:
	/* 0x3a7: jmp    3d1 <cil_to_container+0x3d1> */
	X86_SIM_X86_JMP(0x3a7, 0x3d1, x86_l_3d1);
x86_l_3a9:
	/* 0x3a9: mov    QWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_3b2:
	/* 0x3b2: mov    QWORD PTR [rsp+0x18],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3b7:
	/* 0x3b7: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3bc:
	/* 0x3bc: mov    rdi,QWORD PTR [rip+0x170c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_3c3:
	/* 0x3c3: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3c8:
	/* 0x3c8: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3cd:
	/* 0x3cd: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3cf:
	/* 0x3cf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3d1:
	/* 0x3d1: mov    eax,r13d */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_3d4:
	/* 0x3d4: rol    ax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_16, X86_ALU_ROL, 8ULL);
x86_l_3d8:
	/* 0x3d8: movzx  eax,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_3db:
	/* 0x3db: cmp    eax,0x806 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2054ULL);
x86_l_3e0:
	/* 0x3e0: je     40f <cil_to_container+0x40f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3e0, 0x40f, x86_l_40f);
x86_l_3e2:
	/* 0x3e2: cmp    eax,0x800 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2048ULL);
x86_l_3e7:
	/* 0x3e7: jne    42e <cil_to_container+0x42e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3e7, 0x42e, x86_l_42e);
x86_l_3e9:
	/* 0x3e9: mov    eax,0x27 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 39ULL);
x86_l_3ee:
	/* 0x3ee: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_3f1:
	/* 0x3f1: mov    esi,0x22 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 34ULL);
x86_l_3f6:
	/* 0x3f6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f8:
	/* 0x3f8: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3fb:
	/* 0x3fb: sub    eax,DWORD PTR [rbx+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_3fe:
	/* 0x3fe: mov    ecx,0x86 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 134ULL);
x86_l_403:
	/* 0x403: cmp    eax,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 34ULL);
x86_l_406:
	/* 0x406: jae    42e <cil_to_container+0x42e> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x406, 0x42e, x86_l_42e);
x86_l_408:
	/* 0x408: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_40a:
	/* 0x40a: jmp    153 <cil_to_container+0x153> */
	X86_SIM_X86_JMP(0x40a, 0x153, x86_l_153);
x86_l_40f:
	/* 0x40f: mov    eax,0x27 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 39ULL);
x86_l_414:
	/* 0x414: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_417:
	/* 0x417: mov    esi,0x2a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 42ULL);
x86_l_41c:
	/* 0x41c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_41e:
	/* 0x41e: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_421:
	/* 0x421: sub    eax,DWORD PTR [rbx+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_424:
	/* 0x424: mov    ecx,0x86 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 134ULL);
x86_l_429:
	/* 0x429: cmp    eax,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 42ULL);
x86_l_42c:
	/* 0x42c: jb     408 <cil_to_container+0x408> */
	X86_SIM_X86_JCC(X86_CC_B, 0x42c, 0x408, x86_l_408);
x86_l_42e:
	/* 0x42e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_430:
	/* 0x430: cmp    r13d,0x608 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 1544ULL);
x86_l_437:
	/* 0x437: je     1eb <cil_to_container+0x1eb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x437, 0x1eb, x86_l_1eb);
x86_l_43d:
	/* 0x43d: mov    ecx,0x8b */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 139ULL);
x86_l_442:
	/* 0x442: cmp    r13d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 8ULL);
x86_l_446:
	/* 0x446: jne    153 <cil_to_container+0x153> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x446, 0x153, x86_l_153);
x86_l_44c:
	/* 0x44c: mov    rax,QWORD PTR [rip+0x170c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_security_label)));
x86_l_453:
	/* 0x453: mov    ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_455:
	/* 0x455: mov    DWORD PTR [rbx+0x28],r14d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_459:
	/* 0x459: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_45e:
	/* 0x45e: mov    rsi,QWORD PTR [rip+0x170c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_465:
	/* 0x465: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_468:
	/* 0x468: mov    edx,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 28ULL);
x86_l_46d:
	/* 0x46d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_46f:
	/* 0x46f: mov    ecx,0x8c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 140ULL);
x86_l_474:
	/* 0x474: mov    eax,0x1c00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 7168ULL);
x86_l_479:
	/* 0x479: jmp    153 <cil_to_container+0x153> */
	X86_SIM_X86_JMP(0x479, 0x153, x86_l_153);
x86_l_47e:
	/* 0x47e: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_483:
	/* 0x483: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_488:
	/* 0x488: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_48b:
	/* 0x48b: mov    esi,0x22 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 34ULL);
x86_l_490:
	/* 0x490: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_495:
	/* 0x495: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_497:
	/* 0x497: mov    r9,QWORD PTR [rip+0x170c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R9, (void *)(long)(((__u64)(long)&__config_tracing_ip_option_type)));
x86_l_49e:
	/* 0x49e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4a0:
	/* 0x4a0: js     93 <cil_to_container+0x93> */
	X86_SIM_X86_JCC(X86_CC_S, 0x4a0, 0x93, x86_l_93);
x86_l_4a6:
	/* 0x4a6: movzx  eax,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_4ab:
	/* 0x4ab: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4ad:
	/* 0x4ad: je     296 <cil_to_container+0x296> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4ad, 0x296, x86_l_296);
x86_l_4b3:
	/* 0x4b3: mov    esi,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 35ULL);
x86_l_4b8:
	/* 0x4b8: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4bb:
	/* 0x4bb: je     548 <cil_to_container+0x548> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4bb, 0x548, x86_l_548);
x86_l_4c1:
	/* 0x4c1: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_4c6:
	/* 0x4c6: lea    rdx,[rsp+0x7] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_4cb:
	/* 0x4cb: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_4ce:
	/* 0x4ce: mov    esi,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 35ULL);
x86_l_4d3:
	/* 0x4d3: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_4d8:
	/* 0x4d8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4da:
	/* 0x4da: mov    r9,QWORD PTR [rip+0x170c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R9, (void *)(long)(((__u64)(long)&__config_tracing_ip_option_type)));
x86_l_4e1:
	/* 0x4e1: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4e3:
	/* 0x4e3: js     93 <cil_to_container+0x93> */
	X86_SIM_X86_JCC(X86_CC_S, 0x4e3, 0x93, x86_l_93);
x86_l_4e9:
	/* 0x4e9: mov    esi,0x22 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 34ULL);
x86_l_4ee:
	/* 0x4ee: cmp    BYTE PTR [rsp+0x8],r14b */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R14, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_4f3:
	/* 0x4f3: jne    540 <cil_to_container+0x540> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4f3, 0x540, x86_l_540);
x86_l_4f5:
	/* 0x4f5: movzx  eax,BYTE PTR [rsp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_4fa:
	/* 0x4fa: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_4fd:
	/* 0x4fd: je     5fa <cil_to_container+0x5fa> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4fd, 0x5fa, x86_l_5fa);
x86_l_503:
	/* 0x503: cmp    eax,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 6ULL);
x86_l_506:
	/* 0x506: je     5d2 <cil_to_container+0x5d2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x506, 0x5d2, x86_l_5d2);
x86_l_50c:
	/* 0x50c: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_50f:
	/* 0x50f: jne    93 <cil_to_container+0x93> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x50f, 0x93, x86_l_93);
x86_l_515:
	/* 0x515: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_51a:
	/* 0x51a: add    esi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_51d:
	/* 0x51d: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_522:
	/* 0x522: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_525:
	/* 0x525: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_52a:
	/* 0x52a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_52c:
	/* 0x52c: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_52f:
	/* 0x52f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_531:
	/* 0x531: movbe  cx,WORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOVBE_LOAD, X86_RCX, X86_RSP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_538:
	/* 0x538: movzx  ecx,cx */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_53b:
	/* 0x53b: jmp    61d <cil_to_container+0x61d> */
	X86_SIM_X86_JMP(0x53b, 0x61d, x86_l_61d);
x86_l_540:
	/* 0x540: movzx  esi,BYTE PTR [rsp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_545:
	/* 0x545: add    esi,0x22 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 34ULL);
x86_l_548:
	/* 0x548: lea    r12d,[r12*4+0x22] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R12, 2), 34ULL);
x86_l_550:
	/* 0x550: cmp    esi,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_553:
	/* 0x553: jae    296 <cil_to_container+0x296> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x553, 0x296, x86_l_296);
x86_l_559:
	/* 0x559: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_55e:
	/* 0x55e: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_563:
	/* 0x563: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_566:
	/* 0x566: mov    QWORD PTR [rsp+0x20],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_56b:
	/* 0x56b: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_570:
	/* 0x570: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_572:
	/* 0x572: mov    r9,QWORD PTR [rip+0x170c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R9, (void *)(long)(((__u64)(long)&__config_tracing_ip_option_type)));
x86_l_579:
	/* 0x579: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_57b:
	/* 0x57b: js     93 <cil_to_container+0x93> */
	X86_SIM_X86_JCC(X86_CC_S, 0x57b, 0x93, x86_l_93);
x86_l_581:
	/* 0x581: movzx  eax,BYTE PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 8ULL);
x86_l_586:
	/* 0x586: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_588:
	/* 0x588: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_58d:
	/* 0x58d: je     296 <cil_to_container+0x296> */
	X86_SIM_X86_JCC(X86_CC_E, 0x58d, 0x296, x86_l_296);
x86_l_593:
	/* 0x593: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_596:
	/* 0x596: je     63f <cil_to_container+0x63f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x596, 0x63f, x86_l_63f);
x86_l_59c:
	/* 0x59c: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_5a1:
	/* 0x5a1: inc    esi */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_5a3:
	/* 0x5a3: lea    rdx,[rsp+0x7] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_5a8:
	/* 0x5a8: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_5ab:
	/* 0x5ab: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_5b0:
	/* 0x5b0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b2:
	/* 0x5b2: mov    r9,QWORD PTR [rip+0x170c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R9, (void *)(long)(((__u64)(long)&__config_tracing_ip_option_type)));
x86_l_5b9:
	/* 0x5b9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5bb:
	/* 0x5bb: js     93 <cil_to_container+0x93> */
	X86_SIM_X86_JCC(X86_CC_S, 0x5bb, 0x93, x86_l_93);
x86_l_5c1:
	/* 0x5c1: cmp    BYTE PTR [rsp+0x8],r14b */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R14, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_5c6:
	/* 0x5c6: jne    635 <cil_to_container+0x635> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x5c6, 0x635, x86_l_635);
x86_l_5c8:
	/* 0x5c8: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5cd:
	/* 0x5cd: jmp    4f5 <cil_to_container+0x4f5> */
	X86_SIM_X86_JMP(0x5cd, 0x4f5, x86_l_4f5);
x86_l_5d2:
	/* 0x5d2: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_5d7:
	/* 0x5d7: add    esi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_5da:
	/* 0x5da: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5df:
	/* 0x5df: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_5e2:
	/* 0x5e2: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_5e7:
	/* 0x5e7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5e9:
	/* 0x5e9: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5eb:
	/* 0x5eb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5ed:
	/* 0x5ed: movbe  r14d,DWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOVBE_LOAD, X86_R14, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 16ULL);
x86_l_5f4:
	/* 0x5f4: cmovs  r14d,ecx */
	X86_SIM_L_EXEC_CMOV(X86_R14, X86_RCX, X86_WIDTH_32, X86_CC_S);
x86_l_5f8:
	/* 0x5f8: jmp    621 <cil_to_container+0x621> */
	X86_SIM_X86_JMP(0x5f8, 0x621, x86_l_621);
x86_l_5fa:
	/* 0x5fa: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_5ff:
	/* 0x5ff: add    esi,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 2ULL);
x86_l_602:
	/* 0x602: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_607:
	/* 0x607: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_60a:
	/* 0x60a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_60f:
	/* 0x60f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_611:
	/* 0x611: xor    r14d,r14d */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R14, X86_WIDTH_32, X86_ALU_XOR);
x86_l_614:
	/* 0x614: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_616:
	/* 0x616: movbe  rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_RUN_OP(X86_OP_MOVBE_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 16ULL);
x86_l_61d:
	/* 0x61d: cmovns r14,rcx */
	X86_SIM_L_EXEC_CMOV(X86_R14, X86_RCX, X86_WIDTH_64, X86_CC_NS);
x86_l_621:
	/* 0x621: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_623:
	/* 0x623: mov    r9,QWORD PTR [rip+0x170c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R9, (void *)(long)(((__u64)(long)&__config_tracing_ip_option_type)));
x86_l_62a:
	/* 0x62a: jns    299 <cil_to_container+0x299> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x62a, 0x299, x86_l_299);
x86_l_630:
	/* 0x630: jmp    93 <cil_to_container+0x93> */
	X86_SIM_X86_JMP(0x630, 0x93, x86_l_93);
x86_l_635:
	/* 0x635: movzx  eax,BYTE PTR [rsp+0x7] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 7ULL);
x86_l_63a:
	/* 0x63a: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_63f:
	/* 0x63f: add    esi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_641:
	/* 0x641: cmp    esi,r12d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_644:
	/* 0x644: jae    296 <cil_to_container+0x296> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x644, 0x296, x86_l_296);
x86_l_64a:
	/* 0x64a: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_64f:
	/* 0x64f: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_654:
	/* 0x654: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_657:
	/* 0x657: mov    r12,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RSI, X86_WIDTH_64);
x86_l_65a:
	/* 0x65a: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_65f:
	/* 0x65f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_661:
	/* 0x661: mov    r9,QWORD PTR [rip+0x170c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R9, (void *)(long)(((__u64)(long)&__config_tracing_ip_option_type)));
x86_l_668:
	/* 0x668: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_66a:
	/* 0x66a: js     93 <cil_to_container+0x93> */
	X86_SIM_X86_JCC(X86_CC_S, 0x66a, 0x93, x86_l_93);
x86_l_670:
	/* 0x670: cmp    BYTE PTR [rsp+0x8],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738370ULL);
x86_l_675:
	/* 0x675: jb     296 <cil_to_container+0x296> */
	X86_SIM_X86_JCC(X86_CC_B, 0x675, 0x296, x86_l_296);
x86_l_67b:
	/* 0x67b: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_680:
	/* 0x680: lea    esi,[r12+0x1] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1ULL);
x86_l_685:
	/* 0x685: lea    rdx,[rsp+0x7] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_68a:
	/* 0x68a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_68d:
	/* 0x68d: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_692:
	/* 0x692: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_694:
	/* 0x694: mov    r9,QWORD PTR [rip+0x170c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R9, (void *)(long)(((__u64)(long)&__config_tracing_ip_option_type)));
x86_l_69b:
	/* 0x69b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_69d:
	/* 0x69d: js     93 <cil_to_container+0x93> */
	X86_SIM_X86_JCC(X86_CC_S, 0x69d, 0x93, x86_l_93);
x86_l_6a3:
	/* 0x6a3: cmp    BYTE PTR [rsp+0x8],r14b */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RSP, X86_R14, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6a8:
	/* 0x6a8: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_6ab:
	/* 0x6ab: jne    296 <cil_to_container+0x296> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x6ab, 0x296, x86_l_296);
x86_l_6b1:
	/* 0x6b1: jmp    4f5 <cil_to_container+0x4f5> */
	X86_SIM_X86_JMP(0x6b1, 0x4f5, x86_l_4f5);
x86_l_6b6:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
