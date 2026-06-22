extern char __config_enable_conntrack_accounting;
extern char __config_enable_extended_ip_protocols;
extern char __config_enable_ipv4_fragments;
extern char __config_enable_jiffies;
extern char __config_endpoint_id;
extern char __config_kernel_hz;
extern char __config_security_label;
extern char __config_trace_payload_len;
extern char cilium_calls;
extern char cilium_ct4_global;
extern char cilium_ct_any4_global;
extern char cilium_ipv4_frag_datagrams;
extern char cilium_metrics;
extern char cilium_tail_call_buffer4;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int cilium_bpf_lxc_tail_ipv4_ct_ingress_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0xa: sub    rsp,0x48 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 72ULL);
x86_l_e:
	/* 0xe: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_11:
	/* 0x11: movabs r15,0x201ff0100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_64, 8623423744ULL);
x86_l_1b:
	/* 0x1b: mov    DWORD PTR [rsp+0x44],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 292057776128ULL);
x86_l_23:
	/* 0x23: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_28:
	/* 0x28: mov    rdi,QWORD PTR [rip+0x10700] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_tail_call_buffer4)));
x86_l_2f:
	/* 0x2f: lea    rsi,[rsp+0x44] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_34:
	/* 0x34: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36:
	/* 0x36: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_39:
	/* 0x39: je     ab <tail_ipv4_ct_ingress+0xab> */
	X86_SIM_X86_JCC(X86_CC_E, 0x39, 0xab, x86_l_ab);
x86_l_3b:
	/* 0x3b: mov    r14d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3f:
	/* 0x3f: mov    ecx,DWORD PTR [rbx+0x74] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 116ULL);
x86_l_42:
	/* 0x42: mov    edx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_32);
x86_l_45:
	/* 0x45: sub    edx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_47:
	/* 0x47: cmp    edx,0x21 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 33ULL);
x86_l_4a:
	/* 0x4a: ja     10a <tail_ipv4_ct_ingress+0x10a> */
	X86_SIM_X86_JCC(X86_CC_A, 0x4a, 0x10a, x86_l_10a);
x86_l_50:
	/* 0x50: mov    rax,QWORD PTR [rip+0x10700] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_security_label)));
x86_l_57:
	/* 0x57: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_59:
	/* 0x59: mov    rcx,QWORD PTR [rip+0x10700] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_endpoint_id)));
x86_l_60:
	/* 0x60: movzx  ecx,WORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_63:
	/* 0x63: mov    DWORD PTR [rbx+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_66:
	/* 0x66: mov    DWORD PTR [rbx+0x30],0x86 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430342ULL);
x86_l_6d:
	/* 0x6d: mov    DWORD PTR [rbx+0x34],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_70:
	/* 0x70: mov    DWORD PTR [rbx+0x38],0x1ff0202 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240551657986ULL);
x86_l_77:
	/* 0x77: add    r15,0x86 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 134ULL);
x86_l_7e:
	/* 0x7e: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_83:
	/* 0x83: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_88:
	/* 0x88: mov    rdi,QWORD PTR [rip+0x10700] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_8f:
	/* 0x8f: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_94:
	/* 0x94: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_96:
	/* 0x96: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_99:
	/* 0x99: je     30a <tail_ipv4_ct_ingress+0x30a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x99, 0x30a, x86_l_30a);
x86_l_9f:
	/* 0x9f: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_a2:
	/* 0xa2: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_a6:
	/* 0xa6: jmp    332 <tail_ipv4_ct_ingress+0x332> */
	X86_SIM_X86_JMP(0xa6, 0x332, x86_l_332);
x86_l_ab:
	/* 0xab: mov    rax,QWORD PTR [rip+0x10700] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_security_label)));
x86_l_b2:
	/* 0xb2: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b4:
	/* 0xb4: mov    rcx,QWORD PTR [rip+0x10700] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_endpoint_id)));
x86_l_bb:
	/* 0xbb: movzx  ecx,WORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_be:
	/* 0xbe: mov    DWORD PTR [rbx+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_c1:
	/* 0xc1: mov    DWORD PTR [rbx+0x30],0xb8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430392ULL);
x86_l_c8:
	/* 0xc8: mov    DWORD PTR [rbx+0x34],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_cb:
	/* 0xcb: mov    DWORD PTR [rbx+0x38],0x1ff0202 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240551657986ULL);
x86_l_d2:
	/* 0xd2: mov    r14d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_d6:
	/* 0xd6: add    r15,0xb8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 184ULL);
x86_l_dd:
	/* 0xdd: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e2:
	/* 0xe2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e7:
	/* 0xe7: mov    rdi,QWORD PTR [rip+0x10700] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_ee:
	/* 0xee: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f3:
	/* 0xf3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f5:
	/* 0xf5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f8:
	/* 0xf8: je     2d8 <tail_ipv4_ct_ingress+0x2d8> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf8, 0x2d8, x86_l_2d8);
x86_l_fe:
	/* 0xfe: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_101:
	/* 0x101: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_105:
	/* 0x105: jmp    300 <tail_ipv4_ct_ingress+0x300> */
	X86_SIM_X86_JMP(0x105, 0x300, x86_l_300);
x86_l_10a:
	/* 0x10a: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_10d:
	/* 0x10d: movabs r13,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 2199023255552ULL);
x86_l_117:
	/* 0x117: movabs rbp,0x10000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_64, 1099511627776ULL);
x86_l_121:
	/* 0x121: mov    rdi,QWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_128:
	/* 0x128: movzx  esi,BYTE PTR [rdi+0x17] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 23ULL);
x86_l_12c:
	/* 0x12c: mov    BYTE PTR [rax+0xc],sil */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RSI, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_130:
	/* 0x130: mov    ecx,DWORD PTR [rdi+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_133:
	/* 0x133: mov    DWORD PTR [rax],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_135:
	/* 0x135: mov    edx,DWORD PTR [rdi+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_138:
	/* 0x138: mov    DWORD PTR [rax+0x4],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_13b:
	/* 0x13b: mov    r8d,DWORD PTR [rdi+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_13f:
	/* 0x13f: and    r8d,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_R8, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_143:
	/* 0x143: lea    r12d,[r8*4+0xe] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_R8, 2), 14ULL);
x86_l_14b:
	/* 0x14b: mov    DWORD PTR [rax+0x38],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_14f:
	/* 0x14f: cmp    esi,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 6ULL);
x86_l_152:
	/* 0x152: jne    15d <tail_ipv4_ct_ingress+0x15d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x152, 0x15d, x86_l_15d);
x86_l_154:
	/* 0x154: mov    r8,QWORD PTR [rip+0x10700] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R8, (void *)(long)(((__u64)(long)&cilium_ct4_global)));
x86_l_15b:
	/* 0x15b: jmp    164 <tail_ipv4_ct_ingress+0x164> */
	X86_SIM_X86_JMP(0x15b, 0x164, x86_l_164);
x86_l_15d:
	/* 0x15d: mov    r8,QWORD PTR [rip+0x10700] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R8, (void *)(long)(((__u64)(long)&cilium_ct_any4_global)));
x86_l_164:
	/* 0x164: mov    QWORD PTR [rsp+0x38],r8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_169:
	/* 0x169: movzx  r8d,WORD PTR [rdi+0x12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18ULL);
x86_l_16e:
	/* 0x16e: mov    r9,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R9, X86_RSI, X86_WIDTH_64);
x86_l_171:
	/* 0x171: shl    r9,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R9, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_175:
	/* 0x175: or     r9,r8 */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R8, X86_WIDTH_64, X86_ALU_OR);
x86_l_178:
	/* 0x178: movzx  edi,WORD PTR [rdi+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 20ULL);
x86_l_17c:
	/* 0x17c: lea    r8,[r9+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_R8, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_180:
	/* 0x180: test   edi,0xff3f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDI, X86_WIDTH_32, 65343ULL);
x86_l_186:
	/* 0x186: cmove  r8,r9 */
	X86_SIM_L_EXEC_CMOV(X86_R8, X86_R9, X86_WIDTH_64, X86_CC_E);
x86_l_18a:
	/* 0x18a: lea    r15,[r8+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_R8, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_18e:
	/* 0x18e: test   edi,0xff1f */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RDI, X86_WIDTH_32, 65311ULL);
x86_l_194:
	/* 0x194: cmove  r15,r8 */
	X86_SIM_L_EXEC_CMOV(X86_R15, X86_R8, X86_WIDTH_64, X86_CC_E);
x86_l_198:
	/* 0x198: mov    BYTE PTR [r14+0xd],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 55834574848ULL);
x86_l_19d:
	/* 0x19d: cmp    esi,0x11 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 17ULL);
x86_l_1a0:
	/* 0x1a0: je     263 <tail_ipv4_ct_ingress+0x263> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a0, 0x263, x86_l_263);
x86_l_1a6:
	/* 0x1a6: cmp    esi,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 6ULL);
x86_l_1a9:
	/* 0x1a9: je     263 <tail_ipv4_ct_ingress+0x263> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a9, 0x263, x86_l_263);
x86_l_1af:
	/* 0x1af: cmp    esi,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_32, 1ULL);
x86_l_1b2:
	/* 0x1b2: jne    33c <tail_ipv4_ct_ingress+0x33c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1b2, 0x33c, x86_l_33c);
x86_l_1b8:
	/* 0x1b8: mov    WORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1bf:
	/* 0x1bf: test   r15,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_RBP, X86_WIDTH_64);
x86_l_1c2:
	/* 0x1c2: jne    97a <tail_ipv4_ct_ingress+0x97a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1c2, 0x97a, x86_l_97a);
x86_l_1c8:
	/* 0x1c8: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1cd:
	/* 0x1cd: lea    rdx,[rsp+0x1e] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_1d2:
	/* 0x1d2: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1d5:
	/* 0x1d5: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_1d8:
	/* 0x1d8: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1dd:
	/* 0x1dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1df:
	/* 0x1df: mov    r13d,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967161ULL);
x86_l_1e5:
	/* 0x1e5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1e7:
	/* 0x1e7: js     50b <tail_ipv4_ct_ingress+0x50b> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1e7, 0x50b, x86_l_50b);
x86_l_1ed:
	/* 0x1ed: movzx  eax,BYTE PTR [rsp+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_1f2:
	/* 0x1f2: test   al,0xf7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 247ULL);
x86_l_1f4:
	/* 0x1f4: jne    21c <tail_ipv4_ct_ingress+0x21c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1f4, 0x21c, x86_l_21c);
x86_l_1f6:
	/* 0x1f6: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_1fb:
	/* 0x1fb: lea    esi,[r12+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_200:
	/* 0x200: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_205:
	/* 0x205: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_208:
	/* 0x208: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_20d:
	/* 0x20d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_20f:
	/* 0x20f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_211:
	/* 0x211: js     50b <tail_ipv4_ct_ingress+0x50b> */
	X86_SIM_X86_JCC(X86_CC_S, 0x211, 0x50b, x86_l_50b);
x86_l_217:
	/* 0x217: movzx  eax,BYTE PTR [rsp+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 30ULL);
x86_l_21c:
	/* 0x21c: mov    DWORD PTR [r14+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_224:
	/* 0x224: movzx  eax,al */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_WIDTH_8);
x86_l_227:
	/* 0x227: cmp    eax,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 10ULL);
x86_l_22a:
	/* 0x22a: jg     386 <tail_ipv4_ct_ingress+0x386> */
	X86_SIM_X86_JCC(X86_CC_G, 0x22a, 0x386, x86_l_386);
x86_l_230:
	/* 0x230: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_232:
	/* 0x232: movabs r13,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 2199023255552ULL);
x86_l_23c:
	/* 0x23c: je     39f <tail_ipv4_ct_ingress+0x39f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x23c, 0x39f, x86_l_39f);
x86_l_242:
	/* 0x242: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_245:
	/* 0x245: je     758 <tail_ipv4_ct_ingress+0x758> */
	X86_SIM_X86_JCC(X86_CC_E, 0x245, 0x758, x86_l_758);
x86_l_24b:
	/* 0x24b: cmp    eax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 8ULL);
x86_l_24e:
	/* 0x24e: jne    3a9 <tail_ipv4_ct_ingress+0x3a9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x24e, 0x3a9, x86_l_3a9);
x86_l_254:
	/* 0x254: movzx  eax,WORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_259:
	/* 0x259: mov    WORD PTR [r14+0x8],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_25e:
	/* 0x25e: jmp    3a9 <tail_ipv4_ct_ingress+0x3a9> */
	X86_SIM_X86_JMP(0x25e, 0x3a9, x86_l_3a9);
x86_l_263:
	/* 0x263: add    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_267:
	/* 0x267: mov    rsi,QWORD PTR [rip+0x10700] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_ipv4_fragments)));
x86_l_26e:
	/* 0x26e: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_271:
	/* 0x271: je     352 <tail_ipv4_ct_ingress+0x352> */
	X86_SIM_X86_JCC(X86_CC_E, 0x271, 0x352, x86_l_352);
x86_l_277:
	/* 0x277: mov    DWORD PTR [rsp+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27b:
	/* 0x27b: mov    DWORD PTR [rsp+0xc],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_27f:
	/* 0x27f: mov    WORD PTR [rsp+0x10],r15w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_285:
	/* 0x285: mov    rcx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_288:
	/* 0x288: shr    rcx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_28c:
	/* 0x28c: mov    BYTE PTR [rsp+0x12],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_290:
	/* 0x290: mov    BYTE PTR [rsp+0x13],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 81604378624ULL);
x86_l_295:
	/* 0x295: test   r15,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R13, X86_WIDTH_64);
x86_l_298:
	/* 0x298: jne    950 <tail_ipv4_ct_ingress+0x950> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x298, 0x950, x86_l_950);
x86_l_29e:
	/* 0x29e: mov    r8d,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 26ULL);
x86_l_2a4:
	/* 0x2a4: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2a7:
	/* 0x2a7: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_2aa:
	/* 0x2aa: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_2ad:
	/* 0x2ad: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_2b0:
	/* 0x2b0: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_2b5:
	/* 0x2b5: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_2b8:
	/* 0x2b8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2ba:
	/* 0x2ba: js     505 <tail_ipv4_ct_ingress+0x505> */
	X86_SIM_X86_JCC(X86_CC_S, 0x2ba, 0x505, x86_l_505);
x86_l_2c0:
	/* 0x2c0: test   r15,rbp */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_RBP, X86_WIDTH_64);
x86_l_2c3:
	/* 0x2c3: jne    985 <tail_ipv4_ct_ingress+0x985> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2c3, 0x985, x86_l_985);
x86_l_2c9:
	/* 0x2c9: movabs r13,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 2199023255552ULL);
x86_l_2d3:
	/* 0x2d3: jmp    3a9 <tail_ipv4_ct_ingress+0x3a9> */
	X86_SIM_X86_JMP(0x2d3, 0x3a9, x86_l_3a9);
x86_l_2d8:
	/* 0x2d8: mov    QWORD PTR [rsp+0x20],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953473ULL);
x86_l_2e1:
	/* 0x2e1: mov    QWORD PTR [rsp+0x28],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2e6:
	/* 0x2e6: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_2eb:
	/* 0x2eb: mov    rdi,QWORD PTR [rip+0x10700] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_2f2:
	/* 0x2f2: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f7:
	/* 0x2f7: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2fc:
	/* 0x2fc: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2fe:
	/* 0x2fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_300:
	/* 0x300: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_305:
	/* 0x305: jmp    f43 <tail_ipv4_ct_ingress+0xf43> */
	X86_SIM_X86_JMP(0x305, 0xf43, x86_l_f43);
x86_l_30a:
	/* 0x30a: mov    QWORD PTR [rsp+0x20],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953473ULL);
x86_l_313:
	/* 0x313: mov    QWORD PTR [rsp+0x28],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_318:
	/* 0x318: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_31d:
	/* 0x31d: mov    rdi,QWORD PTR [rip+0x10700] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_324:
	/* 0x324: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_329:
	/* 0x329: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_32e:
	/* 0x32e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_330:
	/* 0x330: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_332:
	/* 0x332: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_337:
	/* 0x337: jmp    f43 <tail_ipv4_ct_ingress+0xf43> */
	X86_SIM_X86_JMP(0x337, 0xf43, x86_l_f43);
x86_l_33c:
	/* 0x33c: mov    rax,QWORD PTR [rip+0x10700] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_extended_ip_protocols)));
x86_l_343:
	/* 0x343: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_346:
	/* 0x346: je     37b <tail_ipv4_ct_ingress+0x37b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x346, 0x37b, x86_l_37b);
x86_l_348:
	/* 0x348: mov    DWORD PTR [r14+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_350:
	/* 0x350: jmp    3a9 <tail_ipv4_ct_ingress+0x3a9> */
	X86_SIM_X86_JMP(0x350, 0x3a9, x86_l_3a9);
x86_l_352:
	/* 0x352: test   r15,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R13, X86_WIDTH_64);
x86_l_355:
	/* 0x355: jne    a03 <tail_ipv4_ct_ingress+0xa03> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x355, 0xa03, x86_l_a03);
x86_l_35b:
	/* 0x35b: mov    r8d,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 26ULL);
x86_l_361:
	/* 0x361: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_364:
	/* 0x364: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_367:
	/* 0x367: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_36a:
	/* 0x36a: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_36f:
	/* 0x36f: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_372:
	/* 0x372: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_374:
	/* 0x374: jns    3a9 <tail_ipv4_ct_ingress+0x3a9> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x374, 0x3a9, x86_l_3a9);
x86_l_376:
	/* 0x376: jmp    505 <tail_ipv4_ct_ingress+0x505> */
	X86_SIM_X86_JMP(0x376, 0x505, x86_l_505);
x86_l_37b:
	/* 0x37b: mov    r13d,0xffffff77 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967159ULL);
x86_l_381:
	/* 0x381: jmp    50b <tail_ipv4_ct_ingress+0x50b> */
	X86_SIM_X86_JMP(0x381, 0x50b, x86_l_50b);
x86_l_386:
	/* 0x386: add    eax,0xfffffff5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_ADD, 4294967285ULL);
x86_l_389:
	/* 0x389: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_38c:
	/* 0x38c: movabs r13,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 2199023255552ULL);
x86_l_396:
	/* 0x396: jae    3a9 <tail_ipv4_ct_ingress+0x3a9> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x396, 0x3a9, x86_l_3a9);
x86_l_398:
	/* 0x398: or     BYTE PTR [r14+0xd],0x2 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 55834574850ULL);
x86_l_39d:
	/* 0x39d: jmp    3a9 <tail_ipv4_ct_ingress+0x3a9> */
	X86_SIM_X86_JMP(0x39d, 0x3a9, x86_l_3a9);
x86_l_39f:
	/* 0x39f: movzx  eax,WORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_3a4:
	/* 0x3a4: mov    WORD PTR [r14+0xa],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 10ULL);
x86_l_3a9:
	/* 0x3a9: movzx  eax,BYTE PTR [r14+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 12ULL);
x86_l_3ae:
	/* 0x3ae: mov    BYTE PTR [rsp+0x7],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_3b2:
	/* 0x3b2: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_3ba:
	/* 0x3ba: mov    rax,QWORD PTR [rip+0x10700] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_ipv4_fragments)));
x86_l_3c1:
	/* 0x3c1: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3c4:
	/* 0x3c4: je     449 <tail_ipv4_ct_ingress+0x449> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3c4, 0x449, x86_l_449);
x86_l_3ca:
	/* 0x3ca: and    rbp,r15 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R15, X86_WIDTH_64, X86_ALU_AND);
x86_l_3cd:
	/* 0x3cd: je     449 <tail_ipv4_ct_ingress+0x449> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3cd, 0x449, x86_l_449);
x86_l_3cf:
	/* 0x3cf: mov    rbp,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R13, X86_WIDTH_64);
x86_l_3d2:
	/* 0x3d2: mov    r13d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_3d6:
	/* 0x3d6: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_3df:
	/* 0x3df: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_3e8:
	/* 0x3e8: movabs rax,0x6c036f010f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 463914074383ULL);
x86_l_3f2:
	/* 0x3f2: add    rax,0x35fffa */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 3538938ULL);
x86_l_3f8:
	/* 0x3f8: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3fd:
	/* 0x3fd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_402:
	/* 0x402: mov    rdi,QWORD PTR [rip+0x106fc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_409:
	/* 0x409: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_40e:
	/* 0x40e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_410:
	/* 0x410: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_413:
	/* 0x413: je     41e <tail_ipv4_ct_ingress+0x41e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x413, 0x41e, x86_l_41e);
x86_l_415:
	/* 0x415: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_418:
	/* 0x418: add    QWORD PTR [rax+0x8],r13 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_41c:
	/* 0x41c: jmp    446 <tail_ipv4_ct_ingress+0x446> */
	X86_SIM_X86_JMP(0x41c, 0x446, x86_l_446);
x86_l_41e:
	/* 0x41e: mov    QWORD PTR [rsp+0x20],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953473ULL);
x86_l_427:
	/* 0x427: mov    QWORD PTR [rsp+0x28],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_42c:
	/* 0x42c: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_431:
	/* 0x431: mov    rdi,QWORD PTR [rip+0x106fc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_438:
	/* 0x438: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_43d:
	/* 0x43d: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_442:
	/* 0x442: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_444:
	/* 0x444: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_446:
	/* 0x446: mov    r13,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBP, X86_WIDTH_64);
x86_l_449:
	/* 0x449: cmp    BYTE PTR [rsp+0x7],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30064771078ULL);
x86_l_44e:
	/* 0x44e: jne    49f <tail_ipv4_ct_ingress+0x49f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x44e, 0x49f, x86_l_49f);
x86_l_450:
	/* 0x450: and    r15,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R13, X86_WIDTH_64, X86_ALU_AND);
x86_l_453:
	/* 0x453: jne    49f <tail_ipv4_ct_ingress+0x49f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x453, 0x49f, x86_l_49f);
x86_l_455:
	/* 0x455: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_45a:
	/* 0x45a: add    r12d,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_ADD, 12ULL);
x86_l_45e:
	/* 0x45e: lea    rdx,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_463:
	/* 0x463: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_466:
	/* 0x466: mov    esi,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_32);
x86_l_469:
	/* 0x469: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_46e:
	/* 0x46e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_470:
	/* 0x470: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_472:
	/* 0x472: js     505 <tail_ipv4_ct_ingress+0x505> */
	X86_SIM_X86_JCC(X86_CC_S, 0x472, 0x505, x86_l_505);
x86_l_478:
	/* 0x478: mov    ebp,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_47c:
	/* 0x47c: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_47e:
	/* 0x47e: and    eax,0x1200 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4608ULL);
x86_l_483:
	/* 0x483: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_486:
	/* 0x486: cmp    eax,0x200 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 512ULL);
x86_l_48b:
	/* 0x48b: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_48e:
	/* 0x48e: test   ebp,0x500 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RBP, X86_WIDTH_32, 1280ULL);
x86_l_494:
	/* 0x494: jne    9f8 <tail_ipv4_ct_ingress+0x9f8> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x494, 0x9f8, x86_l_9f8);
x86_l_49a:
	/* 0x49a: mov    r13b,al */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_8);
x86_l_49d:
	/* 0x49d: jmp    4a6 <tail_ipv4_ct_ingress+0x4a6> */
	X86_SIM_X86_JMP(0x49d, 0x4a6, x86_l_4a6);
x86_l_49f:
	/* 0x49f: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4a2:
	/* 0x4a2: mov    ebp,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_4a6:
	/* 0x4a6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_4ab:
	/* 0x4ab: mov    rdi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_4b0:
	/* 0x4b0: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_4b3:
	/* 0x4b3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b5:
	/* 0x4b5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_4b8:
	/* 0x4b8: je     b22 <tail_ipv4_ct_ingress+0xb22> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4b8, 0xb22, x86_l_b22);
x86_l_4be:
	/* 0x4be: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_4c1:
	/* 0x4c1: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_4c4:
	/* 0x4c4: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_4c6:
	/* 0x4c6: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_4c8:
	/* 0x4c8: test   cl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_4cb:
	/* 0x4cb: je     688 <tail_ipv4_ct_ingress+0x688> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4cb, 0x688, x86_l_688);
x86_l_4d1:
	/* 0x4d1: mov    DWORD PTR [rsp+0x18],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4d6:
	/* 0x4d6: mov    rdx,QWORD PTR [rip+0x106fc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_4dd:
	/* 0x4dd: cmp    BYTE PTR [rdx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4e0:
	/* 0x4e0: je     5a1 <tail_ipv4_ct_ingress+0x5a1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4e0, 0x5a1, x86_l_5a1);
x86_l_4e6:
	/* 0x4e6: mov    rcx,QWORD PTR [rip+0x106fc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_4ed:
	/* 0x4ed: imul   r13d,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_4f1:
	/* 0x4f1: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_4f5:
	/* 0x4f5: cmp    BYTE PTR [rsp+0x7],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30064771078ULL);
x86_l_4fa:
	/* 0x4fa: je     5ae <tail_ipv4_ct_ingress+0x5ae> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4fa, 0x5ae, x86_l_5ae);
x86_l_500:
	/* 0x500: jmp    5e5 <tail_ipv4_ct_ingress+0x5e5> */
	X86_SIM_X86_JMP(0x500, 0x5e5, x86_l_5e5);
x86_l_505:
	/* 0x505: mov    r13d,0xffffff79 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967161ULL);
x86_l_50b:
	/* 0x50b: movabs rdx,0x201ff0100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_64, 8623423744ULL);
x86_l_515:
	/* 0x515: mov    DWORD PTR [r14+0x34],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_519:
	/* 0x519: mov    rax,QWORD PTR [rip+0x106fc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_security_label)));
x86_l_520:
	/* 0x520: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_522:
	/* 0x522: mov    rcx,QWORD PTR [rip+0x106fc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_endpoint_id)));
x86_l_529:
	/* 0x529: movzx  ecx,WORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_52c:
	/* 0x52c: neg    r13d */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_NEG, 0);
x86_l_52f:
	/* 0x52f: mov    DWORD PTR [rbx+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_532:
	/* 0x532: mov    DWORD PTR [rbx+0x30],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_536:
	/* 0x536: mov    DWORD PTR [rbx+0x34],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_539:
	/* 0x539: mov    DWORD PTR [rbx+0x38],0x1ff0202 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240551657986ULL);
x86_l_540:
	/* 0x540: mov    r14d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_544:
	/* 0x544: mov    QWORD PTR [rsp+0x8],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_549:
	/* 0x549: mov    BYTE PTR [rsp+0x8],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_54e:
	/* 0x54e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_553:
	/* 0x553: mov    rdi,QWORD PTR [rip+0x106fc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_55a:
	/* 0x55a: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_55f:
	/* 0x55f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_561:
	/* 0x561: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_564:
	/* 0x564: je     56f <tail_ipv4_ct_ingress+0x56f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x564, 0x56f, x86_l_56f);
x86_l_566:
	/* 0x566: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_569:
	/* 0x569: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_56d:
	/* 0x56d: jmp    597 <tail_ipv4_ct_ingress+0x597> */
	X86_SIM_X86_JMP(0x56d, 0x597, x86_l_597);
x86_l_56f:
	/* 0x56f: mov    QWORD PTR [rsp+0x20],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953473ULL);
x86_l_578:
	/* 0x578: mov    QWORD PTR [rsp+0x28],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_57d:
	/* 0x57d: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_582:
	/* 0x582: mov    rdi,QWORD PTR [rip+0x106fc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_589:
	/* 0x589: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_58e:
	/* 0x58e: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_593:
	/* 0x593: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_595:
	/* 0x595: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_597:
	/* 0x597: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_59c:
	/* 0x59c: jmp    f43 <tail_ipv4_ct_ingress+0xf43> */
	X86_SIM_X86_JMP(0x59c, 0xf43, x86_l_f43);
x86_l_5a1:
	/* 0x5a1: mov    r13d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 60ULL);
x86_l_5a7:
	/* 0x5a7: cmp    BYTE PTR [rsp+0x7],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30064771078ULL);
x86_l_5ac:
	/* 0x5ac: jne    5e5 <tail_ipv4_ct_ingress+0x5e5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x5ac, 0x5e5, x86_l_5e5);
x86_l_5ae:
	/* 0x5ae: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_5b0:
	/* 0x5b0: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_5b2:
	/* 0x5b2: shr    ecx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_5b5:
	/* 0x5b5: and    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_5b8:
	/* 0x5b8: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_5ba:
	/* 0x5ba: mov    WORD PTR [r12+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_5c0:
	/* 0x5c0: test   al,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 16ULL);
x86_l_5c2:
	/* 0x5c2: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_5c7:
	/* 0x5c7: mov    r13d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 21600ULL);
x86_l_5cd:
	/* 0x5cd: cmove  r13d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_5d1:
	/* 0x5d1: cmp    BYTE PTR [rdx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5d4:
	/* 0x5d4: je     5e5 <tail_ipv4_ct_ingress+0x5e5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5d4, 0x5e5, x86_l_5e5);
x86_l_5d6:
	/* 0x5d6: mov    rax,QWORD PTR [rip+0x106fc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_5dd:
	/* 0x5dd: imul   r13d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_5e1:
	/* 0x5e1: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_5e5:
	/* 0x5e5: mov    r15d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RBP, X86_WIDTH_32);
x86_l_5e8:
	/* 0x5e8: shr    r15d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_5ec:
	/* 0x5ec: cmp    BYTE PTR [rdx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5ef:
	/* 0x5ef: je     600 <tail_ipv4_ct_ingress+0x600> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5ef, 0x600, x86_l_600);
x86_l_5f1:
	/* 0x5f1: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_5f6:
	/* 0x5f6: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5f8:
	/* 0x5f8: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_5fa:
	/* 0x5fa: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_5fe:
	/* 0x5fe: jmp    623 <tail_ipv4_ct_ingress+0x623> */
	X86_SIM_X86_JMP(0x5fe, 0x623, x86_l_623);
x86_l_600:
	/* 0x600: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_605:
	/* 0x605: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_607:
	/* 0x607: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_609:
	/* 0x609: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_60d:
	/* 0x60d: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_617:
	/* 0x617: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_61a:
	/* 0x61a: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_61f:
	/* 0x61f: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_623:
	/* 0x623: add    r13d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_626:
	/* 0x626: mov    DWORD PTR [r12+0x20],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_62b:
	/* 0x62b: movzx  ecx,BYTE PTR [r12+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_631:
	/* 0x631: mov    edx,DWORD PTR [r12+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_636:
	/* 0x636: and    r15b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_63a:
	/* 0x63a: mov    rsi,QWORD PTR [rip+0x106fc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_641:
	/* 0x641: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_644:
	/* 0x644: je     657 <tail_ipv4_ct_ingress+0x657> */
	X86_SIM_X86_JCC(X86_CC_E, 0x644, 0x657, x86_l_657);
x86_l_646:
	/* 0x646: mov    rsi,QWORD PTR [rip+0x106fc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_64d:
	/* 0x64d: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_64f:
	/* 0x64f: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_652:
	/* 0x652: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_655:
	/* 0x655: jmp    65c <tail_ipv4_ct_ingress+0x65c> */
	X86_SIM_X86_JMP(0x655, 0x65c, x86_l_65c);
x86_l_657:
	/* 0x657: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_65c:
	/* 0x65c: mov    r13d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_661:
	/* 0x661: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_663:
	/* 0x663: or     r15b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_666:
	/* 0x666: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_668:
	/* 0x668: jb     671 <tail_ipv4_ct_ingress+0x671> */
	X86_SIM_X86_JCC(X86_CC_B, 0x668, 0x671, x86_l_671);
x86_l_66a:
	/* 0x66a: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_66c:
	/* 0x66c: cmp    cl,r15b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R15, X86_WIDTH_8);
x86_l_66f:
	/* 0x66f: je     684 <tail_ipv4_ct_ingress+0x684> */
	X86_SIM_X86_JCC(X86_CC_E, 0x66f, 0x684, x86_l_684);
x86_l_671:
	/* 0x671: mov    BYTE PTR [r12+0x2b],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_676:
	/* 0x676: mov    DWORD PTR [r12+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_67b:
	/* 0x67b: mov    rax,QWORD PTR [rip+0x106fc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_682:
	/* 0x682: mov    edx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_684:
	/* 0x684: mov    DWORD PTR [r14+0x30],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_688:
	/* 0x688: mov    rax,QWORD PTR [rip+0x106fc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_68f:
	/* 0x68f: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_692:
	/* 0x692: je     6a3 <tail_ipv4_ct_ingress+0x6a3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x692, 0x6a3, x86_l_6a3);
x86_l_694:
	/* 0x694: inc QWORD PTR [r12+0x10] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R12, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 16ULL);
x86_l_69a:
	/* 0x69a: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_69d:
	/* 0x69d: add QWORD PTR [r12+0x18],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R12, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_6a3:
	/* 0x6a3: cmp    r13d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 2ULL);
x86_l_6a7:
	/* 0x6a7: je     6fe <tail_ipv4_ct_ingress+0x6fe> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6a7, 0x6fe, x86_l_6fe);
x86_l_6a9:
	/* 0x6a9: cmp    r13d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 1ULL);
x86_l_6ad:
	/* 0x6ad: jne    845 <tail_ipv4_ct_ingress+0x845> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x6ad, 0x845, x86_l_845);
x86_l_6b3:
	/* 0x6b3: movzx  eax,WORD PTR [r12+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_6b9:
	/* 0x6b9: test   al,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 3ULL);
x86_l_6bb:
	/* 0x6bb: je     845 <tail_ipv4_ct_ingress+0x845> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6bb, 0x845, x86_l_845);
x86_l_6c1:
	/* 0x6c1: mov    DWORD PTR [rsp+0x18],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6c6:
	/* 0x6c6: mov    WORD PTR [r12+0x2a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 180388626432ULL);
x86_l_6ce:
	/* 0x6ce: and    eax,0xffec */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 65516ULL);
x86_l_6d3:
	/* 0x6d3: mov    WORD PTR [r12+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_6d9:
	/* 0x6d9: mov    r15,QWORD PTR [rip+0x106fc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_6e0:
	/* 0x6e0: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6e4:
	/* 0x6e4: je     a50 <tail_ipv4_ct_ingress+0xa50> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6e4, 0xa50, x86_l_a50);
x86_l_6ea:
	/* 0x6ea: mov    rcx,QWORD PTR [rip+0x106fc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_6f1:
	/* 0x6f1: imul   r13d,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_6f5:
	/* 0x6f5: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_6f9:
	/* 0x6f9: jmp    a56 <tail_ipv4_ct_ingress+0xa56> */
	X86_SIM_X86_JMP(0x6f9, 0xa56, x86_l_a56);
x86_l_6fe:
	/* 0x6fe: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_700:
	/* 0x700: shr    eax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_703:
	/* 0x703: and    eax,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2ULL);
x86_l_706:
	/* 0x706: or     ax,WORD PTR [r12+0x24] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R12, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 36ULL);
x86_l_70c:
	/* 0x70c: or     eax,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 1ULL);
x86_l_70f:
	/* 0x70f: mov    WORD PTR [r12+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_715:
	/* 0x715: or     BYTE PTR [r14+0x25],0x1 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 158913789953ULL);
x86_l_71a:
	/* 0x71a: mov    rax,QWORD PTR [rip+0x106fc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_721:
	/* 0x721: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_723:
	/* 0x723: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_727:
	/* 0x727: mov    eax,DWORD PTR [r12+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_72c:
	/* 0x72c: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_72e:
	/* 0x72e: test   al,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 3ULL);
x86_l_730:
	/* 0x730: jne    845 <tail_ipv4_ct_ingress+0x845> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x730, 0x845, x86_l_845);
x86_l_736:
	/* 0x736: mov    r15,QWORD PTR [rip+0x106fc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_73d:
	/* 0x73d: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_741:
	/* 0x741: je     7b0 <tail_ipv4_ct_ingress+0x7b0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x741, 0x7b0, x86_l_7b0);
x86_l_743:
	/* 0x743: mov    rax,QWORD PTR [rip+0x106fc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_74a:
	/* 0x74a: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_74c:
	/* 0x74c: add    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_74e:
	/* 0x74e: lea    r13d,[rax+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_752:
	/* 0x752: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_756:
	/* 0x756: jmp    7b6 <tail_ipv4_ct_ingress+0x7b6> */
	X86_SIM_X86_JMP(0x756, 0x7b6, x86_l_7b6);
x86_l_758:
	/* 0x758: cmp    BYTE PTR [rsp+0x1f],0x4 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 133143986180ULL);
x86_l_75d:
	/* 0x75d: jne    398 <tail_ipv4_ct_ingress+0x398> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x75d, 0x398, x86_l_398);
x86_l_763:
	/* 0x763: mov    r13d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_767:
	/* 0x767: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_770:
	/* 0x770: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_779:
	/* 0x779: movabs rax,0x6c036f010f */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 463914074383ULL);
x86_l_783:
	/* 0x783: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_788:
	/* 0x788: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_78d:
	/* 0x78d: mov    rdi,QWORD PTR [rip+0x106fc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_794:
	/* 0x794: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_799:
	/* 0x799: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_79b:
	/* 0x79b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_79e:
	/* 0x79e: je     919 <tail_ipv4_ct_ingress+0x919> */
	X86_SIM_X86_JCC(X86_CC_E, 0x79e, 0x919, x86_l_919);
x86_l_7a4:
	/* 0x7a4: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_7a7:
	/* 0x7a7: add    QWORD PTR [rax+0x8],r13 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_7ab:
	/* 0x7ab: jmp    941 <tail_ipv4_ct_ingress+0x941> */
	X86_SIM_X86_JMP(0x7ab, 0x941, x86_l_941);
x86_l_7b0:
	/* 0x7b0: mov    r13d,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 10ULL);
x86_l_7b6:
	/* 0x7b6: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_7b9:
	/* 0x7b9: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7bd:
	/* 0x7bd: je     7ce <tail_ipv4_ct_ingress+0x7ce> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7bd, 0x7ce, x86_l_7ce);
x86_l_7bf:
	/* 0x7bf: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_7c4:
	/* 0x7c4: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7c6:
	/* 0x7c6: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_7c8:
	/* 0x7c8: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_7cc:
	/* 0x7cc: jmp    7f1 <tail_ipv4_ct_ingress+0x7f1> */
	X86_SIM_X86_JMP(0x7cc, 0x7f1, x86_l_7f1);
x86_l_7ce:
	/* 0x7ce: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_7d3:
	/* 0x7d3: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7d5:
	/* 0x7d5: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_7d7:
	/* 0x7d7: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_7db:
	/* 0x7db: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_7e5:
	/* 0x7e5: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_7e8:
	/* 0x7e8: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_7ed:
	/* 0x7ed: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_7f1:
	/* 0x7f1: add    r13d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_7f4:
	/* 0x7f4: mov    DWORD PTR [r12+0x20],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_7f9:
	/* 0x7f9: movzx  ecx,BYTE PTR [r12+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_7ff:
	/* 0x7ff: mov    edx,DWORD PTR [r12+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_804:
	/* 0x804: and    bpl,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_808:
	/* 0x808: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_80c:
	/* 0x80c: je     81f <tail_ipv4_ct_ingress+0x81f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x80c, 0x81f, x86_l_81f);
x86_l_80e:
	/* 0x80e: mov    rsi,QWORD PTR [rip+0x106fc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_815:
	/* 0x815: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_817:
	/* 0x817: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_81a:
	/* 0x81a: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_81d:
	/* 0x81d: jmp    824 <tail_ipv4_ct_ingress+0x824> */
	X86_SIM_X86_JMP(0x81d, 0x824, x86_l_824);
x86_l_81f:
	/* 0x81f: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_824:
	/* 0x824: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_826:
	/* 0x826: or     bpl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_829:
	/* 0x829: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_82b:
	/* 0x82b: mov    rdx,QWORD PTR [rip+0x106fc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_832:
	/* 0x832: jb     839 <tail_ipv4_ct_ingress+0x839> */
	X86_SIM_X86_JCC(X86_CC_B, 0x832, 0x839, x86_l_839);
x86_l_834:
	/* 0x834: cmp    cl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_8);
x86_l_837:
	/* 0x837: je     845 <tail_ipv4_ct_ingress+0x845> */
	X86_SIM_X86_JCC(X86_CC_E, 0x837, 0x845, x86_l_845);
x86_l_839:
	/* 0x839: mov    BYTE PTR [r12+0x2b],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_83e:
	/* 0x83e: mov    DWORD PTR [r12+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_843:
	/* 0x843: mov    eax,DWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_845:
	/* 0x845: movzx  eax,WORD PTR [r12+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_84b:
	/* 0x84b: mov    WORD PTR [r14+0x22],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_850:
	/* 0x850: movzx  ecx,WORD PTR [r12+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_856:
	/* 0x856: shr    ecx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 3ULL);
x86_l_859:
	/* 0x859: and    ecx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1ULL);
x86_l_85c:
	/* 0x85c: mov    eax,DWORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_860:
	/* 0x860: and    eax,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_863:
	/* 0x863: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_865:
	/* 0x865: mov    WORD PTR [r14+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_86a:
	/* 0x86a: movzx  ecx,WORD PTR [r12+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_870:
	/* 0x870: shr    ecx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 4ULL);
x86_l_873:
	/* 0x873: and    ecx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2ULL);
x86_l_876:
	/* 0x876: and    eax,0xfffffffd */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967293ULL);
x86_l_879:
	/* 0x879: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_87b:
	/* 0x87b: mov    WORD PTR [r14+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_880:
	/* 0x880: movzx  ecx,WORD PTR [r12+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_886:
	/* 0x886: shr    ecx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_889:
	/* 0x889: and    ecx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4ULL);
x86_l_88c:
	/* 0x88c: and    eax,0xfffffffb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967291ULL);
x86_l_88f:
	/* 0x88f: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_891:
	/* 0x891: mov    WORD PTR [r14+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_896:
	/* 0x896: movzx  ecx,WORD PTR [r12+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_89c:
	/* 0x89c: shr    ecx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 2ULL);
x86_l_89f:
	/* 0x89f: and    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_8a2:
	/* 0x8a2: and    eax,0xffffffef */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967279ULL);
x86_l_8a5:
	/* 0x8a5: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_8a7:
	/* 0x8a7: mov    WORD PTR [r14+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_8ac:
	/* 0x8ac: movzx  ecx,WORD PTR [r12+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_8b2:
	/* 0x8b2: shr    ecx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 3ULL);
x86_l_8b5:
	/* 0x8b5: and    ecx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32ULL);
x86_l_8b8:
	/* 0x8b8: and    eax,0xffffffdf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967263ULL);
x86_l_8bb:
	/* 0x8bb: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_8bd:
	/* 0x8bd: mov    WORD PTR [r14+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_8c2:
	/* 0x8c2: movzx  ecx,WORD PTR [r12+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_8c8:
	/* 0x8c8: shr    ecx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 3ULL);
x86_l_8cb:
	/* 0x8cb: and    ecx,0x80 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 128ULL);
x86_l_8d1:
	/* 0x8d1: and    eax,0xffffff7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967167ULL);
x86_l_8d6:
	/* 0x8d6: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_8d8:
	/* 0x8d8: mov    WORD PTR [r14+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_8dd:
	/* 0x8dd: mov    rax,QWORD PTR [r12+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8e2:
	/* 0x8e2: mov    QWORD PTR [r14+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_8e6:
	/* 0x8e6: mov    rax,QWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8ea:
	/* 0x8ea: mov    QWORD PTR [r14+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_8ee:
	/* 0x8ee: movzx  eax,WORD PTR [r12+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 40ULL);
x86_l_8f4:
	/* 0x8f4: mov    WORD PTR [r14+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_8f9:
	/* 0x8f9: movzx  eax,BYTE PTR [r14+0xd] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 13ULL);
x86_l_8fe:
	/* 0x8fe: and    al,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_900:
	/* 0x900: cmp    al,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 1ULL);
x86_l_902:
	/* 0x902: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_907:
	/* 0x907: sbb    eax,0x0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SBB, 0ULL);
x86_l_90a:
	/* 0x90a: movabs r12,0x201ff0100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 8623423744ULL);
x86_l_914:
	/* 0x914: jmp    ea4 <tail_ipv4_ct_ingress+0xea4> */
	X86_SIM_X86_JMP(0x914, 0xea4, x86_l_ea4);
x86_l_919:
	/* 0x919: mov    QWORD PTR [rsp+0x20],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953473ULL);
x86_l_922:
	/* 0x922: mov    QWORD PTR [rsp+0x28],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_927:
	/* 0x927: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_92c:
	/* 0x92c: mov    rdi,QWORD PTR [rip+0x106fc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_933:
	/* 0x933: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_938:
	/* 0x938: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_93d:
	/* 0x93d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_93f:
	/* 0x93f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_941:
	/* 0x941: movabs r13,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 2199023255552ULL);
x86_l_94b:
	/* 0x94b: jmp    398 <tail_ipv4_ct_ingress+0x398> */
	X86_SIM_X86_JMP(0x94b, 0x398, x86_l_398);
x86_l_950:
	/* 0x950: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_953:
	/* 0x953: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_958:
	/* 0x958: mov    rdi,QWORD PTR [rip+0x106fc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv4_frag_datagrams)));
x86_l_95f:
	/* 0x95f: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_964:
	/* 0x964: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_966:
	/* 0x966: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_969:
	/* 0x969: je     a0e <tail_ipv4_ct_ingress+0xa0e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x969, 0xa0e, x86_l_a0e);
x86_l_96f:
	/* 0x96f: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_971:
	/* 0x971: mov    DWORD PTR [r13+0x0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_975:
	/* 0x975: jmp    2c9 <tail_ipv4_ct_ingress+0x2c9> */
	X86_SIM_X86_JMP(0x975, 0x2c9, x86_l_2c9);
x86_l_97a:
	/* 0x97a: mov    r13d,0xffffff7a */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967162ULL);
x86_l_980:
	/* 0x980: jmp    50b <tail_ipv4_ct_ingress+0x50b> */
	X86_SIM_X86_JMP(0x980, 0x50b, x86_l_50b);
x86_l_985:
	/* 0x985: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_98a:
	/* 0x98a: mov    rdi,QWORD PTR [rip+0x106fc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ipv4_frag_datagrams)));
x86_l_991:
	/* 0x991: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_996:
	/* 0x996: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_999:
	/* 0x999: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_99b:
	/* 0x99b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_99d:
	/* 0x99d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_99f:
	/* 0x99f: je     2c9 <tail_ipv4_ct_ingress+0x2c9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x99f, 0x2c9, x86_l_2c9);
x86_l_9a5:
	/* 0x9a5: mov    r13d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_9a9:
	/* 0x9a9: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_9b2:
	/* 0x9b2: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_9bb:
	/* 0x9bb: movabs rax,0x6b0085010a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 459570217226ULL);
x86_l_9c5:
	/* 0x9c5: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9ca:
	/* 0x9ca: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_9cf:
	/* 0x9cf: mov    rdi,QWORD PTR [rip+0x106fc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_9d6:
	/* 0x9d6: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9db:
	/* 0x9db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9dd:
	/* 0x9dd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9e0:
	/* 0x9e0: je     a19 <tail_ipv4_ct_ingress+0xa19> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9e0, 0xa19, x86_l_a19);
x86_l_9e2:
	/* 0x9e2: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_9e5:
	/* 0x9e5: add    QWORD PTR [rax+0x8],r13 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R13, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_9e9:
	/* 0x9e9: movabs r13,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 2199023255552ULL);
x86_l_9f3:
	/* 0x9f3: jmp    3a9 <tail_ipv4_ct_ingress+0x3a9> */
	X86_SIM_X86_JMP(0x9f3, 0x3a9, x86_l_3a9);
x86_l_9f8:
	/* 0x9f8: mov    r13d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 2ULL);
x86_l_9fe:
	/* 0x9fe: jmp    4a6 <tail_ipv4_ct_ingress+0x4a6> */
	X86_SIM_X86_JMP(0x9fe, 0x4a6, x86_l_4a6);
x86_l_a03:
	/* 0xa03: mov    r13d,0xffffff63 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967139ULL);
x86_l_a09:
	/* 0xa09: jmp    50b <tail_ipv4_ct_ingress+0x50b> */
	X86_SIM_X86_JMP(0xa09, 0x50b, x86_l_50b);
x86_l_a0e:
	/* 0xa0e: mov    r13d,0xffffff51 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 4294967121ULL);
x86_l_a14:
	/* 0xa14: jmp    50b <tail_ipv4_ct_ingress+0x50b> */
	X86_SIM_X86_JMP(0xa14, 0x50b, x86_l_50b);
x86_l_a19:
	/* 0xa19: mov    QWORD PTR [rsp+0x20],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953473ULL);
x86_l_a22:
	/* 0xa22: mov    QWORD PTR [rsp+0x28],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a27:
	/* 0xa27: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_a2c:
	/* 0xa2c: mov    rdi,QWORD PTR [rip+0x106fc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_a33:
	/* 0xa33: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a38:
	/* 0xa38: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a3d:
	/* 0xa3d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a3f:
	/* 0xa3f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a41:
	/* 0xa41: movabs r13,0x20000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_64, 2199023255552ULL);
x86_l_a4b:
	/* 0xa4b: jmp    3a9 <tail_ipv4_ct_ingress+0x3a9> */
	X86_SIM_X86_JMP(0xa4b, 0x3a9, x86_l_3a9);
x86_l_a50:
	/* 0xa50: mov    r13d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 60ULL);
x86_l_a56:
	/* 0xa56: cmp    BYTE PTR [rsp+0x7],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30064771078ULL);
x86_l_a5b:
	/* 0xa5b: jne    a95 <tail_ipv4_ct_ingress+0xa95> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa5b, 0xa95, x86_l_a95);
x86_l_a5d:
	/* 0xa5d: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_a5f:
	/* 0xa5f: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_a61:
	/* 0xa61: shr    ecx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_a64:
	/* 0xa64: and    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_a67:
	/* 0xa67: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_a69:
	/* 0xa69: mov    WORD PTR [r12+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_a6f:
	/* 0xa6f: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_a71:
	/* 0xa71: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_a76:
	/* 0xa76: mov    r13d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 21600ULL);
x86_l_a7c:
	/* 0xa7c: cmove  r13d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_a80:
	/* 0xa80: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a84:
	/* 0xa84: je     a95 <tail_ipv4_ct_ingress+0xa95> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa84, 0xa95, x86_l_a95);
x86_l_a86:
	/* 0xa86: mov    rax,QWORD PTR [rip+0x106fc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_a8d:
	/* 0xa8d: imul   r13d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_a91:
	/* 0xa91: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_a95:
	/* 0xa95: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_a98:
	/* 0xa98: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a9c:
	/* 0xa9c: je     aad <tail_ipv4_ct_ingress+0xaad> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa9c, 0xaad, x86_l_aad);
x86_l_a9e:
	/* 0xa9e: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_aa3:
	/* 0xaa3: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_aa5:
	/* 0xaa5: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_aa7:
	/* 0xaa7: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_aab:
	/* 0xaab: jmp    ad0 <tail_ipv4_ct_ingress+0xad0> */
	X86_SIM_X86_JMP(0xaab, 0xad0, x86_l_ad0);
x86_l_aad:
	/* 0xaad: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_ab2:
	/* 0xab2: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ab4:
	/* 0xab4: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_ab6:
	/* 0xab6: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_aba:
	/* 0xaba: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_ac4:
	/* 0xac4: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_ac7:
	/* 0xac7: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_acc:
	/* 0xacc: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_ad0:
	/* 0xad0: add    r13d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_ad3:
	/* 0xad3: mov    DWORD PTR [r12+0x20],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ad8:
	/* 0xad8: movzx  ecx,BYTE PTR [r12+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R12, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_ade:
	/* 0xade: mov    edx,DWORD PTR [r12+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_ae3:
	/* 0xae3: and    bpl,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_ae7:
	/* 0xae7: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_aeb:
	/* 0xaeb: je     afe <tail_ipv4_ct_ingress+0xafe> */
	X86_SIM_X86_JCC(X86_CC_E, 0xaeb, 0xafe, x86_l_afe);
x86_l_aed:
	/* 0xaed: mov    rsi,QWORD PTR [rip+0x106fc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_af4:
	/* 0xaf4: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_af6:
	/* 0xaf6: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_af9:
	/* 0xaf9: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_afc:
	/* 0xafc: jmp    b03 <tail_ipv4_ct_ingress+0xb03> */
	X86_SIM_X86_JMP(0xafc, 0xb03, x86_l_b03);
x86_l_afe:
	/* 0xafe: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_b03:
	/* 0xb03: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_b05:
	/* 0xb05: or     bpl,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_b08:
	/* 0xb08: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_b0a:
	/* 0xb0a: mov    r13d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b0f:
	/* 0xb0f: jb     b18 <tail_ipv4_ct_ingress+0xb18> */
	X86_SIM_X86_JCC(X86_CC_B, 0xb0f, 0xb18, x86_l_b18);
x86_l_b11:
	/* 0xb11: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b13:
	/* 0xb13: cmp    cl,bpl */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RBP, X86_WIDTH_8);
x86_l_b16:
	/* 0xb16: je     b2b <tail_ipv4_ct_ingress+0xb2b> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb16, 0xb2b, x86_l_b2b);
x86_l_b18:
	/* 0xb18: mov    BYTE PTR [r12+0x2b],bpl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RBP, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_b1d:
	/* 0xb1d: mov    DWORD PTR [r12+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_b22:
	/* 0xb22: mov    rax,QWORD PTR [rip+0x106fc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_b29:
	/* 0xb29: mov    edx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b2b:
	/* 0xb2b: mov    DWORD PTR [r14+0x30],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_b2f:
	/* 0xb2f: rol    QWORD PTR [r14],0x20 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_64, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_ROL)), 32ULL);
x86_l_b33:
	/* 0xb33: rol    DWORD PTR [r14+0x8],0x10 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_32, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_ROL)), 34359738384ULL);
x86_l_b38:
	/* 0xb38: xor    BYTE PTR [r14+0xd],0x1 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_XOR)), 55834574849ULL);
x86_l_b3d:
	/* 0xb3d: mov    ebp,DWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_b41:
	/* 0xb41: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b46:
	/* 0xb46: mov    rdi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_b4b:
	/* 0xb4b: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_b4e:
	/* 0xb4e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b50:
	/* 0xb50: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b53:
	/* 0xb53: je     b94 <tail_ipv4_ct_ingress+0xb94> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb53, 0xb94, x86_l_b94);
x86_l_b55:
	/* 0xb55: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_b58:
	/* 0xb58: mov    eax,DWORD PTR [rax+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_b5b:
	/* 0xb5b: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_b5d:
	/* 0xb5d: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_b5f:
	/* 0xb5f: test   cl,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RCX, X86_WIDTH_8, 3ULL);
x86_l_b62:
	/* 0xb62: movabs r12,0x201ff0100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 8623423744ULL);
x86_l_b6c:
	/* 0xb6c: je     c93 <tail_ipv4_ct_ingress+0xc93> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb6c, 0xc93, x86_l_c93);
x86_l_b72:
	/* 0xb72: mov    DWORD PTR [rsp+0x18],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b77:
	/* 0xb77: mov    rdx,QWORD PTR [rip+0x106fc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_b7e:
	/* 0xb7e: cmp    BYTE PTR [rdx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b81:
	/* 0xb81: je     ba8 <tail_ipv4_ct_ingress+0xba8> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb81, 0xba8, x86_l_ba8);
x86_l_b83:
	/* 0xb83: mov    rcx,QWORD PTR [rip+0x106fc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_b8a:
	/* 0xb8a: imul   r13d,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_b8e:
	/* 0xb8e: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_b92:
	/* 0xb92: jmp    bae <tail_ipv4_ct_ingress+0xbae> */
	X86_SIM_X86_JMP(0xb92, 0xbae, x86_l_bae);
x86_l_b94:
	/* 0xb94: mov    rax,QWORD PTR [rip+0x106fc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_b9b:
	/* 0xb9b: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b9d:
	/* 0xb9d: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ba1:
	/* 0xba1: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ba3:
	/* 0xba3: jmp    90a <tail_ipv4_ct_ingress+0x90a> */
	X86_SIM_X86_JMP(0xba3, 0x90a, x86_l_90a);
x86_l_ba8:
	/* 0xba8: mov    r13d,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 60ULL);
x86_l_bae:
	/* 0xbae: cmp    BYTE PTR [rsp+0x7],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30064771078ULL);
x86_l_bb3:
	/* 0xbb3: jne    beb <tail_ipv4_ct_ingress+0xbeb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xbb3, 0xbeb, x86_l_beb);
x86_l_bb5:
	/* 0xbb5: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_bb7:
	/* 0xbb7: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_bb9:
	/* 0xbb9: shr    ecx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_bbc:
	/* 0xbbc: and    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_bbf:
	/* 0xbbf: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_bc1:
	/* 0xbc1: mov    WORD PTR [r15+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_bc6:
	/* 0xbc6: test   al,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 16ULL);
x86_l_bc8:
	/* 0xbc8: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_bcd:
	/* 0xbcd: mov    r13d,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R13, X86_WIDTH_32, 21600ULL);
x86_l_bd3:
	/* 0xbd3: cmove  r13d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R13, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_bd7:
	/* 0xbd7: cmp    BYTE PTR [rdx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bda:
	/* 0xbda: je     beb <tail_ipv4_ct_ingress+0xbeb> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbda, 0xbeb, x86_l_beb);
x86_l_bdc:
	/* 0xbdc: mov    rax,QWORD PTR [rip+0x106fc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_be3:
	/* 0xbe3: imul   r13d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_be7:
	/* 0xbe7: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_beb:
	/* 0xbeb: mov    r12d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_bee:
	/* 0xbee: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_bf2:
	/* 0xbf2: cmp    BYTE PTR [rdx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bf5:
	/* 0xbf5: je     c06 <tail_ipv4_ct_ingress+0xc06> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbf5, 0xc06, x86_l_c06);
x86_l_bf7:
	/* 0xbf7: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_bfc:
	/* 0xbfc: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bfe:
	/* 0xbfe: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_c00:
	/* 0xc00: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_c04:
	/* 0xc04: jmp    c29 <tail_ipv4_ct_ingress+0xc29> */
	X86_SIM_X86_JMP(0xc04, 0xc29, x86_l_c29);
x86_l_c06:
	/* 0xc06: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_c0b:
	/* 0xc0b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c0d:
	/* 0xc0d: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_c0f:
	/* 0xc0f: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_c13:
	/* 0xc13: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_c1d:
	/* 0xc1d: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_c20:
	/* 0xc20: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_c25:
	/* 0xc25: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_c29:
	/* 0xc29: add    r13d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_c2c:
	/* 0xc2c: mov    DWORD PTR [r15+0x20],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c30:
	/* 0xc30: movzx  ecx,BYTE PTR [r15+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_c35:
	/* 0xc35: mov    edx,DWORD PTR [r15+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_c39:
	/* 0xc39: and    r12b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_c3d:
	/* 0xc3d: mov    rsi,QWORD PTR [rip+0x106fc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_c44:
	/* 0xc44: cmp    BYTE PTR [rsi],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c47:
	/* 0xc47: je     c5a <tail_ipv4_ct_ingress+0xc5a> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc47, 0xc5a, x86_l_c5a);
x86_l_c49:
	/* 0xc49: mov    rsi,QWORD PTR [rip+0x106fc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_c50:
	/* 0xc50: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c52:
	/* 0xc52: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_c55:
	/* 0xc55: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_c58:
	/* 0xc58: jmp    c5f <tail_ipv4_ct_ingress+0xc5f> */
	X86_SIM_X86_JMP(0xc58, 0xc5f, x86_l_c5f);
x86_l_c5a:
	/* 0xc5a: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_c5f:
	/* 0xc5f: mov    r13d,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c64:
	/* 0xc64: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_c66:
	/* 0xc66: or     r12b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_c69:
	/* 0xc69: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_c6b:
	/* 0xc6b: jb     c74 <tail_ipv4_ct_ingress+0xc74> */
	X86_SIM_X86_JCC(X86_CC_B, 0xc6b, 0xc74, x86_l_c74);
x86_l_c6d:
	/* 0xc6d: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_c6f:
	/* 0xc6f: cmp    cl,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R12, X86_WIDTH_8);
x86_l_c72:
	/* 0xc72: je     c85 <tail_ipv4_ct_ingress+0xc85> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc72, 0xc85, x86_l_c85);
x86_l_c74:
	/* 0xc74: mov    BYTE PTR [r15+0x2b],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_c78:
	/* 0xc78: mov    DWORD PTR [r15+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_c7c:
	/* 0xc7c: mov    rax,QWORD PTR [rip+0x106fc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_c83:
	/* 0xc83: mov    edx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c85:
	/* 0xc85: mov    DWORD PTR [r14+0x30],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c89:
	/* 0xc89: movabs r12,0x201ff0100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 8623423744ULL);
x86_l_c93:
	/* 0xc93: mov    rax,QWORD PTR [rip+0x106fc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_enable_conntrack_accounting)));
x86_l_c9a:
	/* 0xc9a: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c9d:
	/* 0xc9d: je     cac <tail_ipv4_ct_ingress+0xcac> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc9d, 0xcac, x86_l_cac);
x86_l_c9f:
	/* 0xc9f: inc QWORD PTR [r15+0x10] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 16ULL);
x86_l_ca4:
	/* 0xca4: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_ca7:
	/* 0xca7: add QWORD PTR [r15+0x18],rax */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R15, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 24ULL);
x86_l_cac:
	/* 0xcac: cmp    r13d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 2ULL);
x86_l_cb0:
	/* 0xcb0: je     d01 <tail_ipv4_ct_ingress+0xd01> */
	X86_SIM_X86_JCC(X86_CC_E, 0xcb0, 0xd01, x86_l_d01);
x86_l_cb2:
	/* 0xcb2: cmp    r13d,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R13, X86_WIDTH_32, 1ULL);
x86_l_cb6:
	/* 0xcb6: jne    df5 <tail_ipv4_ct_ingress+0xdf5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xcb6, 0xdf5, x86_l_df5);
x86_l_cbc:
	/* 0xcbc: movzx  eax,WORD PTR [r15+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_cc1:
	/* 0xcc1: test   al,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 3ULL);
x86_l_cc3:
	/* 0xcc3: je     df5 <tail_ipv4_ct_ingress+0xdf5> */
	X86_SIM_X86_JCC(X86_CC_E, 0xcc3, 0xdf5, x86_l_df5);
x86_l_cc9:
	/* 0xcc9: mov    r12d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RBP, X86_WIDTH_32);
x86_l_ccc:
	/* 0xccc: mov    WORD PTR [r15+0x2a],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 180388626432ULL);
x86_l_cd3:
	/* 0xcd3: and    eax,0xffec */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 65516ULL);
x86_l_cd8:
	/* 0xcd8: mov    WORD PTR [r15+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_cdd:
	/* 0xcdd: mov    r13,QWORD PTR [rip+0x106fc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R13, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_ce4:
	/* 0xce4: cmp    BYTE PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ce9:
	/* 0xce9: je     f6c <tail_ipv4_ct_ingress+0xf6c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xce9, 0xf6c, x86_l_f6c);
x86_l_cef:
	/* 0xcef: mov    rcx,QWORD PTR [rip+0x106fc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_cf6:
	/* 0xcf6: imul   ebp,DWORD PTR [rcx],0x3c */
	X86_SIM_L_EXEC_IMUL_MEM_IMM(X86_RBP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 60ULL);
x86_l_cf9:
	/* 0xcf9: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_cfc:
	/* 0xcfc: jmp    f71 <tail_ipv4_ct_ingress+0xf71> */
	X86_SIM_X86_JMP(0xcfc, 0xf71, x86_l_f71);
x86_l_d01:
	/* 0xd01: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_d03:
	/* 0xd03: shr    eax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 9ULL);
x86_l_d06:
	/* 0xd06: and    eax,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2ULL);
x86_l_d09:
	/* 0xd09: or     ax,WORD PTR [r15+0x24] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R15, X86_WIDTH_16, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 36ULL);
x86_l_d0e:
	/* 0xd0e: or     eax,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_OR, 1ULL);
x86_l_d11:
	/* 0xd11: mov    WORD PTR [r15+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_d16:
	/* 0xd16: or     BYTE PTR [r14+0x25],0x1 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_8, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 158913789953ULL);
x86_l_d1b:
	/* 0xd1b: mov    rax,QWORD PTR [rip+0x106fc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_d22:
	/* 0xd22: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d24:
	/* 0xd24: mov    DWORD PTR [r14+0x30],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d28:
	/* 0xd28: mov    eax,DWORD PTR [r15+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_d2c:
	/* 0xd2c: not    eax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_d2e:
	/* 0xd2e: test   al,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_8, 3ULL);
x86_l_d30:
	/* 0xd30: jne    df5 <tail_ipv4_ct_ingress+0xdf5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xd30, 0xdf5, x86_l_df5);
x86_l_d36:
	/* 0xd36: mov    r13d,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RBP, X86_WIDTH_32);
x86_l_d39:
	/* 0xd39: mov    r12,QWORD PTR [rip+0x106fc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&__config_enable_jiffies)));
x86_l_d40:
	/* 0xd40: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d45:
	/* 0xd45: je     d5a <tail_ipv4_ct_ingress+0xd5a> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd45, 0xd5a, x86_l_d5a);
x86_l_d47:
	/* 0xd47: mov    rax,QWORD PTR [rip+0x106fc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_d4e:
	/* 0xd4e: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d50:
	/* 0xd50: add    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_d52:
	/* 0xd52: lea    ebp,[rax+rax*4] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 0ULL);
x86_l_d55:
	/* 0xd55: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_d58:
	/* 0xd58: jmp    d5f <tail_ipv4_ct_ingress+0xd5f> */
	X86_SIM_X86_JMP(0xd58, 0xd5f, x86_l_d5f);
x86_l_d5a:
	/* 0xd5a: mov    ebp,0xa */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 10ULL);
x86_l_d5f:
	/* 0xd5f: shr    r13d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_d63:
	/* 0xd63: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d68:
	/* 0xd68: je     d79 <tail_ipv4_ct_ingress+0xd79> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd68, 0xd79, x86_l_d79);
x86_l_d6a:
	/* 0xd6a: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_d6f:
	/* 0xd6f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d71:
	/* 0xd71: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_d73:
	/* 0xd73: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_d77:
	/* 0xd77: jmp    d9c <tail_ipv4_ct_ingress+0xd9c> */
	X86_SIM_X86_JMP(0xd77, 0xd9c, x86_l_d9c);
x86_l_d79:
	/* 0xd79: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_d7e:
	/* 0xd7e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d80:
	/* 0xd80: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_d82:
	/* 0xd82: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_d86:
	/* 0xd86: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_d90:
	/* 0xd90: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_d93:
	/* 0xd93: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_d98:
	/* 0xd98: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_d9c:
	/* 0xd9c: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_d9e:
	/* 0xd9e: mov    DWORD PTR [r15+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_da2:
	/* 0xda2: movzx  ecx,BYTE PTR [r15+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_da7:
	/* 0xda7: mov    edx,DWORD PTR [r15+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_dab:
	/* 0xdab: and    r13b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_daf:
	/* 0xdaf: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_db4:
	/* 0xdb4: je     dc7 <tail_ipv4_ct_ingress+0xdc7> */
	X86_SIM_X86_JCC(X86_CC_E, 0xdb4, 0xdc7, x86_l_dc7);
x86_l_db6:
	/* 0xdb6: mov    rsi,QWORD PTR [rip+0x106fc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_dbd:
	/* 0xdbd: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_dbf:
	/* 0xdbf: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_dc2:
	/* 0xdc2: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_dc5:
	/* 0xdc5: jmp    dcc <tail_ipv4_ct_ingress+0xdcc> */
	X86_SIM_X86_JMP(0xdc5, 0xdcc, x86_l_dcc);
x86_l_dc7:
	/* 0xdc7: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_dcc:
	/* 0xdcc: movabs r12,0x201ff0100 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_64, 8623423744ULL);
x86_l_dd6:
	/* 0xdd6: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_dd8:
	/* 0xdd8: or     r13b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_ddb:
	/* 0xddb: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_ddd:
	/* 0xddd: mov    rdx,QWORD PTR [rip+0x106fc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_de4:
	/* 0xde4: jb     deb <tail_ipv4_ct_ingress+0xdeb> */
	X86_SIM_X86_JCC(X86_CC_B, 0xde4, 0xdeb, x86_l_deb);
x86_l_de6:
	/* 0xde6: cmp    cl,r13b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R13, X86_WIDTH_8);
x86_l_de9:
	/* 0xde9: je     df5 <tail_ipv4_ct_ingress+0xdf5> */
	X86_SIM_X86_JCC(X86_CC_E, 0xde9, 0xdf5, x86_l_df5);
x86_l_deb:
	/* 0xdeb: mov    BYTE PTR [r15+0x2b],r13b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R13, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_def:
	/* 0xdef: mov    DWORD PTR [r15+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_df3:
	/* 0xdf3: mov    eax,DWORD PTR [rdx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_df5:
	/* 0xdf5: movzx  eax,WORD PTR [r15+0x26] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 38ULL);
x86_l_dfa:
	/* 0xdfa: mov    WORD PTR [r14+0x22],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_dff:
	/* 0xdff: movzx  ecx,WORD PTR [r15+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_e04:
	/* 0xe04: shr    ecx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 3ULL);
x86_l_e07:
	/* 0xe07: and    ecx,0x1 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 1ULL);
x86_l_e0a:
	/* 0xe0a: mov    eax,DWORD PTR [r14+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_e0e:
	/* 0xe0e: and    eax,0xfffffffe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967294ULL);
x86_l_e11:
	/* 0xe11: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_e13:
	/* 0xe13: mov    WORD PTR [r14+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_e18:
	/* 0xe18: movzx  ecx,WORD PTR [r15+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_e1d:
	/* 0xe1d: shr    ecx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 4ULL);
x86_l_e20:
	/* 0xe20: and    ecx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 2ULL);
x86_l_e23:
	/* 0xe23: and    eax,0xfffffffd */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967293ULL);
x86_l_e26:
	/* 0xe26: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_e28:
	/* 0xe28: mov    WORD PTR [r14+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_e2d:
	/* 0xe2d: movzx  ecx,WORD PTR [r15+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_e32:
	/* 0xe32: shr    ecx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_e35:
	/* 0xe35: and    ecx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 4ULL);
x86_l_e38:
	/* 0xe38: and    eax,0xfffffffb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967291ULL);
x86_l_e3b:
	/* 0xe3b: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_e3d:
	/* 0xe3d: mov    WORD PTR [r14+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_e42:
	/* 0xe42: movzx  ecx,WORD PTR [r15+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_e47:
	/* 0xe47: shr    ecx,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 2ULL);
x86_l_e4a:
	/* 0xe4a: and    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_e4d:
	/* 0xe4d: and    eax,0xffffffef */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967279ULL);
x86_l_e50:
	/* 0xe50: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_e52:
	/* 0xe52: mov    WORD PTR [r14+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_e57:
	/* 0xe57: movzx  ecx,WORD PTR [r15+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_e5c:
	/* 0xe5c: shr    ecx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 3ULL);
x86_l_e5f:
	/* 0xe5f: and    ecx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 32ULL);
x86_l_e62:
	/* 0xe62: and    eax,0xffffffdf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967263ULL);
x86_l_e65:
	/* 0xe65: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_e67:
	/* 0xe67: mov    WORD PTR [r14+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_e6c:
	/* 0xe6c: movzx  ecx,WORD PTR [r15+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 36ULL);
x86_l_e71:
	/* 0xe71: shr    ecx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 3ULL);
x86_l_e74:
	/* 0xe74: and    ecx,0x80 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 128ULL);
x86_l_e7a:
	/* 0xe7a: and    eax,0xffffff7f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4294967167ULL);
x86_l_e7f:
	/* 0xe7f: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_e81:
	/* 0xe81: mov    WORD PTR [r14+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_e86:
	/* 0xe86: mov    rax,QWORD PTR [r15+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e8a:
	/* 0xe8a: mov    QWORD PTR [r14+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_e8e:
	/* 0xe8e: mov    rax,QWORD PTR [r15] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e91:
	/* 0xe91: mov    QWORD PTR [r14+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e95:
	/* 0xe95: movzx  eax,WORD PTR [r15+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 40ULL);
x86_l_e9a:
	/* 0xe9a: mov    WORD PTR [r14+0x20],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e9f:
	/* 0xe9f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ea4:
	/* 0xea4: mov    DWORD PTR [r14+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_ea8:
	/* 0xea8: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_ead:
	/* 0xead: mov    rsi,QWORD PTR [rip+0x106fc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_eb4:
	/* 0xeb4: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_eb7:
	/* 0xeb7: mov    edx,0xd */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_ebc:
	/* 0xebc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ebe:
	/* 0xebe: mov    rax,QWORD PTR [rip+0x106fc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_security_label)));
x86_l_ec5:
	/* 0xec5: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ec7:
	/* 0xec7: mov    rcx,QWORD PTR [rip+0x106fc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_endpoint_id)));
x86_l_ece:
	/* 0xece: movzx  ecx,WORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_ed1:
	/* 0xed1: mov    DWORD PTR [rbx+0x2c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_ed4:
	/* 0xed4: mov    DWORD PTR [rbx+0x30],0xd8c */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158433676ULL);
x86_l_edb:
	/* 0xedb: mov    DWORD PTR [rbx+0x34],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_ede:
	/* 0xede: mov    DWORD PTR [rbx+0x38],0x1ff0202 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240551657986ULL);
x86_l_ee5:
	/* 0xee5: mov    r14d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_ee9:
	/* 0xee9: add    r12,0x8c */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 140ULL);
x86_l_ef0:
	/* 0xef0: mov    QWORD PTR [rsp+0x8],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ef5:
	/* 0xef5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_efa:
	/* 0xefa: mov    rdi,QWORD PTR [rip+0x106fc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_f01:
	/* 0xf01: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f06:
	/* 0xf06: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f08:
	/* 0xf08: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f0b:
	/* 0xf0b: je     f16 <tail_ipv4_ct_ingress+0xf16> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf0b, 0xf16, x86_l_f16);
x86_l_f0d:
	/* 0xf0d: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_f10:
	/* 0xf10: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_f14:
	/* 0xf14: jmp    f3e <tail_ipv4_ct_ingress+0xf3e> */
	X86_SIM_X86_JMP(0xf14, 0xf3e, x86_l_f3e);
x86_l_f16:
	/* 0xf16: mov    QWORD PTR [rsp+0x20],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953473ULL);
x86_l_f1f:
	/* 0xf1f: mov    QWORD PTR [rsp+0x28],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_f24:
	/* 0xf24: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_f29:
	/* 0xf29: mov    rdi,QWORD PTR [rip+0x106fc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_f30:
	/* 0xf30: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f35:
	/* 0xf35: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f3a:
	/* 0xf3a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f3c:
	/* 0xf3c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f3e:
	/* 0xf3e: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_f43:
	/* 0xf43: mov    rsi,QWORD PTR [rip+0x106fc] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_f4a:
	/* 0xf4a: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_f4d:
	/* 0xf4d: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_f52:
	/* 0xf52: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f54:
	/* 0xf54: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_f59:
	/* 0xf59: add    rsp,0x48 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 72ULL);
x86_l_f5d:
	/* 0xf5d: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_f5e:
	/* 0xf5e: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_f60:
	/* 0xf60: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_f62:
	/* 0xf62: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_f64:
	/* 0xf64: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_f66:
	/* 0xf66: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_f67:
	/* 0xf67: jmp    1046 <tail_ipv4_ct_ingress+0x1046> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_f6c:
	/* 0xf6c: mov    ebp,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 60ULL);
x86_l_f71:
	/* 0xf71: cmp    BYTE PTR [rsp+0x7],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30064771078ULL);
x86_l_f76:
	/* 0xf76: jne    fad <tail_ipv4_ct_ingress+0xfad> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf76, 0xfad, x86_l_fad);
x86_l_f78:
	/* 0xf78: mov    ecx,r12d */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R12, X86_WIDTH_32);
x86_l_f7b:
	/* 0xf7b: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_f7d:
	/* 0xf7d: shr    ecx,0x5 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 5ULL);
x86_l_f80:
	/* 0xf80: and    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_AND, 16ULL);
x86_l_f83:
	/* 0xf83: or     eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_OR);
x86_l_f85:
	/* 0xf85: mov    WORD PTR [r15+0x24],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_f8a:
	/* 0xf8a: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_f8c:
	/* 0xf8c: mov    eax,0x3c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 60ULL);
x86_l_f91:
	/* 0xf91: mov    ebp,0x5460 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 21600ULL);
x86_l_f96:
	/* 0xf96: cmove  ebp,eax */
	X86_SIM_L_EXEC_CMOV(X86_RBP, X86_RAX, X86_WIDTH_32, X86_CC_E);
x86_l_f99:
	/* 0xf99: cmp    BYTE PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f9e:
	/* 0xf9e: je     fad <tail_ipv4_ct_ingress+0xfad> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf9e, 0xfad, x86_l_fad);
x86_l_fa0:
	/* 0xfa0: mov    rax,QWORD PTR [rip+0x106f8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_fa7:
	/* 0xfa7: imul   ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBP, X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_IMUL)), 0ULL);
x86_l_faa:
	/* 0xfaa: shr    ebp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_fad:
	/* 0xfad: shr    r12d,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_fb1:
	/* 0xfb1: cmp    BYTE PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fb6:
	/* 0xfb6: je     fc7 <tail_ipv4_ct_ingress+0xfc7> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfb6, 0xfc7, x86_l_fc7);
x86_l_fb8:
	/* 0xfb8: mov    ecx,0x76 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 118ULL);
x86_l_fbd:
	/* 0xfbd: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_fbf:
	/* 0xfbf: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_fc1:
	/* 0xfc1: shr    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 8ULL);
x86_l_fc5:
	/* 0xfc5: jmp    fea <tail_ipv4_ct_ingress+0xfea> */
	X86_SIM_X86_JMP(0xfc5, 0xfea, x86_l_fea);
x86_l_fc7:
	/* 0xfc7: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_fcc:
	/* 0xfcc: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_fce:
	/* 0xfce: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_fd0:
	/* 0xfd0: shr    rax,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_fd4:
	/* 0xfd4: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_fde:
	/* 0xfde: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_fe1:
	/* 0xfe1: mulx   rax,rax,rcx */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RCX, X86_RAX, X86_WIDTH_64);
x86_l_fe6:
	/* 0xfe6: shr    rax,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_fea:
	/* 0xfea: add    ebp,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_fec:
	/* 0xfec: mov    DWORD PTR [r15+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ff0:
	/* 0xff0: movzx  ecx,BYTE PTR [r15+0x2b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 43ULL);
x86_l_ff5:
	/* 0xff5: mov    edx,DWORD PTR [r15+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_ff9:
	/* 0xff9: and    r12b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_8, X86_ALU_AND, 2ULL);
x86_l_ffd:
	/* 0xffd: cmp    BYTE PTR [r13+0x0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R13, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1002:
	/* 0x1002: je     1015 <tail_ipv4_ct_ingress+0x1015> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1002, 0x1015, x86_l_1015);
x86_l_1004:
	/* 0x1004: mov    rsi,QWORD PTR [rip+0x106f8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&__config_kernel_hz)));
x86_l_100b:
	/* 0x100b: mov    esi,DWORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_100d:
	/* 0x100d: lea    esi,[rsi+rsi*4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_RSI, 2), 0ULL);
x86_l_1010:
	/* 0x1010: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_1013:
	/* 0x1013: jmp    101a <tail_ipv4_ct_ingress+0x101a> */
	X86_SIM_X86_JMP(0x1013, 0x101a, x86_l_101a);
x86_l_1015:
	/* 0x1015: mov    esi,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 5ULL);
x86_l_101a:
	/* 0x101a: add    esi,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_101c:
	/* 0x101c: or     r12b,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RCX, X86_WIDTH_8, X86_ALU_OR);
x86_l_101f:
	/* 0x101f: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_1021:
	/* 0x1021: jb     102a <tail_ipv4_ct_ingress+0x102a> */
	X86_SIM_X86_JCC(X86_CC_B, 0x1021, 0x102a, x86_l_102a);
x86_l_1023:
	/* 0x1023: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1025:
	/* 0x1025: cmp    cl,r12b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R12, X86_WIDTH_8);
x86_l_1028:
	/* 0x1028: je     103b <tail_ipv4_ct_ingress+0x103b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1028, 0x103b, x86_l_103b);
x86_l_102a:
	/* 0x102a: mov    BYTE PTR [r15+0x2b],r12b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R12, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 43ULL);
x86_l_102e:
	/* 0x102e: mov    DWORD PTR [r15+0x34],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_1032:
	/* 0x1032: mov    rax,QWORD PTR [rip+0x106f8] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_1039:
	/* 0x1039: mov    edx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_103b:
	/* 0x103b: mov    DWORD PTR [r14+0x30],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_103f:
	/* 0x103f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1041:
	/* 0x1041: jmp    90a <tail_ipv4_ct_ingress+0x90a> */
	X86_SIM_X86_JMP(0x1041, 0x90a, x86_l_90a);
x86_l_1046:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
