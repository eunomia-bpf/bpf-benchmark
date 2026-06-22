extern char __config_events_map_burst_limit;
extern char __config_events_map_rate_limit;
extern char __config_trace_payload_len;
extern char __config_trace_payload_len_overlay;
extern char __config_tracing_ip_option_type;
extern char __config_tunnel_port;
extern char __config_tunnel_protocol;
extern char cilium_events;
extern char cilium_percpu_trace_id;
extern char cilium_ratelimit;
extern char cilium_ratelimit_metrics;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int cilium_bpf_wireguard_tail_drop_notify_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0xa: sub    rsp,0x58 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 88ULL);
x86_l_e:
	/* 0xe: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_11:
	/* 0x11: mov    r15d,DWORD PTR [rdi+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_15:
	/* 0x15: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_tracing_ip_option_type)));
x86_l_1c:
	/* 0x1c: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f:
	/* 0x1f: je     46 <tail_drop_notify+0x46> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1f, 0x46, x86_l_46);
x86_l_21:
	/* 0x21: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_29:
	/* 0x29: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2e:
	/* 0x2e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_percpu_trace_id)));
x86_l_35:
	/* 0x35: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3a:
	/* 0x3a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3c:
	/* 0x3c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3f:
	/* 0x3f: je     46 <tail_drop_notify+0x46> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3f, 0x46, x86_l_46);
x86_l_41:
	/* 0x41: mov    r12,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_44:
	/* 0x44: jmp    49 <tail_drop_notify+0x49> */
	X86_SIM_X86_JMP(0x44, 0x49, x86_l_49);
x86_l_46:
	/* 0x46: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_49:
	/* 0x49: mov    ebp,DWORD PTR [rbx+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_4c:
	/* 0x4c: mov    r13d,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_50:
	/* 0x50: mov    QWORD PTR [rsp+0x40],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906946ULL);
x86_l_59:
	/* 0x59: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_events_map_rate_limit)));
x86_l_60:
	/* 0x60: cmp    DWORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_63:
	/* 0x63: je     1af <tail_drop_notify+0x1af> */
	X86_SIM_X86_JCC(X86_CC_E, 0x63, 0x1af, x86_l_1af);
x86_l_69:
	/* 0x69: mov    DWORD PTR [rsp+0x38],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_6e:
	/* 0x6e: mov    QWORD PTR [rsp+0x48],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_73:
	/* 0x73: mov    DWORD PTR [rsp+0x3c],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_78:
	/* 0x78: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_events_map_burst_limit)));
x86_l_7f:
	/* 0x7f: mov    r13d,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_82:
	/* 0x82: mov    r12d,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_85:
	/* 0x85: mov    ecx,0x5 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_8a:
	/* 0x8a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8c:
	/* 0x8c: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_8e:
	/* 0x8e: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_91:
	/* 0x91: mov    DWORD PTR [rsp+0x4],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869186ULL);
x86_l_99:
	/* 0x99: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_9e:
	/* 0x9e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit_metrics)));
x86_l_a5:
	/* 0xa5: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_aa:
	/* 0xaa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ac:
	/* 0xac: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_af:
	/* 0xaf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b2:
	/* 0xb2: jne    e2 <tail_drop_notify+0xe2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb2, 0xe2, x86_l_e2);
x86_l_b4:
	/* 0xb4: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_bd:
	/* 0xbd: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_c2:
	/* 0xc2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit_metrics)));
x86_l_c9:
	/* 0xc9: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_ce:
	/* 0xce: lea    r14,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_d3:
	/* 0xd3: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_d6:
	/* 0xd6: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d8:
	/* 0xd8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_da:
	/* 0xda: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_dc:
	/* 0xdc: js     36d <tail_drop_notify+0x36d> */
	X86_SIM_X86_JCC(X86_CC_S, 0xdc, 0x36d, x86_l_36d);
x86_l_e2:
	/* 0xe2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e7:
	/* 0xe7: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit)));
x86_l_ee:
	/* 0xee: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_f3:
	/* 0xf3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f5:
	/* 0xf5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f8:
	/* 0xf8: je     15c <tail_drop_notify+0x15c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf8, 0x15c, x86_l_15c);
x86_l_fa:
	/* 0xfa: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fd:
	/* 0xfd: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_100:
	/* 0x100: sub    rsi,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_64, X86_ALU_SUB);
x86_l_103:
	/* 0x103: cmp    rsi,0x3b9aca00 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RSI, X86_WIDTH_64, 1000000000ULL);
x86_l_10a:
	/* 0x10a: jbe    18c <tail_drop_notify+0x18c> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x10a, 0x18c, x86_l_18c);
x86_l_110:
	/* 0x110: mov    rdx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RSI, X86_WIDTH_64);
x86_l_113:
	/* 0x113: shr    rdx,0x9 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 9ULL);
x86_l_117:
	/* 0x117: movabs rcx,0x44b82fa09b5a53 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 19342813113834067ULL);
x86_l_121:
	/* 0x121: mulx   rcx,rcx,rcx */
	X86_SIM_L_EXEC_MULX(X86_RCX, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_126:
	/* 0x126: shr    rcx,0xb */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_SHR, 11ULL);
x86_l_12a:
	/* 0x12a: imul   rdx,rcx,0x3b9aca00 */
	X86_SIM_L_EXEC_IMUL_IMM(X86_RDX, X86_RCX, X86_WIDTH_64, 1000000000ULL);
x86_l_131:
	/* 0x131: imul   rcx,r12 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R12, X86_WIDTH_64, X86_ALU_IMUL);
x86_l_135:
	/* 0x135: add    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_139:
	/* 0x139: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13d:
	/* 0x13d: sub    rdx,rsi */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RSI, X86_WIDTH_64, X86_ALU_SUB);
x86_l_140:
	/* 0x140: add    r15,rdx */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RDX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_143:
	/* 0x143: mov    QWORD PTR [rax],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_146:
	/* 0x146: cmp    rcx,r13 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_149:
	/* 0x149: jbe    152 <tail_drop_notify+0x152> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x149, 0x152, x86_l_152);
x86_l_14b:
	/* 0x14b: mov    QWORD PTR [rax+0x8],r13 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14f:
	/* 0x14f: mov    rcx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R13, X86_WIDTH_64);
x86_l_152:
	/* 0x152: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_155:
	/* 0x155: jne    199 <tail_drop_notify+0x199> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x155, 0x199, x86_l_199);
x86_l_157:
	/* 0x157: jmp    384 <tail_drop_notify+0x384> */
	X86_SIM_X86_JMP(0x157, 0x384, x86_l_384);
x86_l_15c:
	/* 0x15c: mov    QWORD PTR [rsp+0x8],r15 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_161:
	/* 0x161: dec    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_164:
	/* 0x164: mov    QWORD PTR [rsp+0x10],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_169:
	/* 0x169: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_16e:
	/* 0x16e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_ratelimit)));
x86_l_175:
	/* 0x175: lea    rsi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_17a:
	/* 0x17a: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_17f:
	/* 0x17f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_181:
	/* 0x181: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_183:
	/* 0x183: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_185:
	/* 0x185: jns    1a0 <tail_drop_notify+0x1a0> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x185, 0x1a0, x86_l_1a0);
x86_l_187:
	/* 0x187: jmp    384 <tail_drop_notify+0x384> */
	X86_SIM_X86_JMP(0x187, 0x384, x86_l_384);
x86_l_18c:
	/* 0x18c: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_190:
	/* 0x190: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_193:
	/* 0x193: je     384 <tail_drop_notify+0x384> */
	X86_SIM_X86_JCC(X86_CC_E, 0x193, 0x384, x86_l_384);
x86_l_199:
	/* 0x199: dec    rcx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_19c:
	/* 0x19c: mov    QWORD PTR [rax+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a0:
	/* 0x1a0: mov    r15d,DWORD PTR [rsp+0x3c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_1a5:
	/* 0x1a5: mov    r12,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1aa:
	/* 0x1aa: mov    r13d,DWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1af:
	/* 0x1af: movzx  eax,WORD PTR [rbx+0xb4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 180ULL);
x86_l_1b6:
	/* 0x1b6: cmp    eax,0xdd86 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 56710ULL);
x86_l_1bb:
	/* 0x1bb: sete   r14b */
	X86_SIM_L_EXEC_SETCC(X86_R14, X86_CC_E);
x86_l_1bf:
	/* 0x1bf: or     r14b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_8, X86_ALU_OR, 2ULL);
x86_l_1c3:
	/* 0x1c3: mov    ecx,0xf00 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 3840ULL);
x86_l_1c8:
	/* 0x1c8: and    ecx,DWORD PTR [rbx+0xa8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_AND)), 168ULL);
x86_l_1ce:
	/* 0x1ce: cmp    ecx,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1024ULL);
x86_l_1d4:
	/* 0x1d4: jne    1f7 <tail_drop_notify+0x1f7> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1d4, 0x1f7, x86_l_1f7);
x86_l_1d6:
	/* 0x1d6: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_tunnel_protocol)));
x86_l_1dd:
	/* 0x1dd: movzx  edx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1e0:
	/* 0x1e0: mov    al,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 4ULL);
x86_l_1e2:
	/* 0x1e2: cmp    dl,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_8, 1ULL);
x86_l_1e5:
	/* 0x1e5: je     1f2 <tail_drop_notify+0x1f2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1e5, 0x1f2, x86_l_1f2);
x86_l_1e7:
	/* 0x1e7: movzx  eax,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_1ea:
	/* 0x1ea: cmp    al,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 2ULL);
x86_l_1ec:
	/* 0x1ec: sete   al */
	X86_SIM_L_EXEC_SETCC(X86_RAX, X86_CC_E);
x86_l_1ef:
	/* 0x1ef: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_1f2:
	/* 0x1f2: or     r14b,al */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_8, X86_ALU_OR);
x86_l_1f5:
	/* 0x1f5: jmp    26f <tail_drop_notify+0x26f> */
	X86_SIM_X86_JMP(0x1f5, 0x26f, x86_l_26f);
x86_l_1f7:
	/* 0x1f7: cmp    ax,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_16, 8ULL);
x86_l_1fb:
	/* 0x1fb: jne    26f <tail_drop_notify+0x26f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1fb, 0x26f, x86_l_26f);
x86_l_1fd:
	/* 0x1fd: mov    eax,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_200:
	/* 0x200: sub    eax,DWORD PTR [rbx+0x74] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_RBX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 116ULL);
x86_l_203:
	/* 0x203: cmp    eax,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 20ULL);
x86_l_206:
	/* 0x206: jb     26f <tail_drop_notify+0x26f> */
	X86_SIM_X86_JCC(X86_CC_B, 0x206, 0x26f, x86_l_26f);
x86_l_208:
	/* 0x208: mov    rax,QWORD PTR [rbx+0xd0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 208ULL);
x86_l_20f:
	/* 0x20f: cmp    BYTE PTR [rax+0x9],0x11 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38654705681ULL);
x86_l_213:
	/* 0x213: jne    26f <tail_drop_notify+0x26f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x213, 0x26f, x86_l_26f);
x86_l_215:
	/* 0x215: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_217:
	/* 0x217: and    eax,0xf */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 15ULL);
x86_l_21a:
	/* 0x21a: lea    esi,[rax*4+0x2] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_RAX, 2), 2ULL);
x86_l_221:
	/* 0x221: mov    eax,0x1a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 26ULL);
x86_l_226:
	/* 0x226: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_22b:
	/* 0x22b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_22e:
	/* 0x22e: mov    ecx,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_233:
	/* 0x233: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_235:
	/* 0x235: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_237:
	/* 0x237: js     26f <tail_drop_notify+0x26f> */
	X86_SIM_X86_JCC(X86_CC_S, 0x237, 0x26f, x86_l_26f);
x86_l_239:
	/* 0x239: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_tunnel_port)));
x86_l_240:
	/* 0x240: movbe  ax,WORD PTR [rax] */
	X86_SIM_RUN_OP(X86_OP_MOVBE_LOAD, X86_RAX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_245:
	/* 0x245: cmp    ax,WORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RSP, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 8ULL);
x86_l_24a:
	/* 0x24a: jne    26f <tail_drop_notify+0x26f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x24a, 0x26f, x86_l_26f);
x86_l_24c:
	/* 0x24c: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_tunnel_protocol)));
x86_l_253:
	/* 0x253: movzx  ecx,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_256:
	/* 0x256: mov    r14b,0x6 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_8, 6ULL);
x86_l_259:
	/* 0x259: cmp    cl,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 1ULL);
x86_l_25c:
	/* 0x25c: je     26f <tail_drop_notify+0x26f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x25c, 0x26f, x86_l_26f);
x86_l_25e:
	/* 0x25e: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_261:
	/* 0x261: cmp    al,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_8, 2ULL);
x86_l_263:
	/* 0x263: sete   r14b */
	X86_SIM_L_EXEC_SETCC(X86_R14, X86_CC_E);
x86_l_267:
	/* 0x267: shl    r14b,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_26b:
	/* 0x26b: or     r14b,0x2 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_8, X86_ALU_OR, 2ULL);
x86_l_26f:
	/* 0x26f: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len)));
x86_l_276:
	/* 0x276: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_278:
	/* 0x278: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&__config_tunnel_protocol)));
x86_l_27f:
	/* 0x27f: movzx  edx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_282:
	/* 0x282: mov    sil,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_8, 4ULL);
x86_l_285:
	/* 0x285: cmp    dl,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_8, 1ULL);
x86_l_288:
	/* 0x288: je     298 <tail_drop_notify+0x298> */
	X86_SIM_X86_JCC(X86_CC_E, 0x288, 0x298, x86_l_298);
x86_l_28a:
	/* 0x28a: movzx  ecx,BYTE PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_28d:
	/* 0x28d: cmp    cl,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_8, 2ULL);
x86_l_290:
	/* 0x290: sete   sil */
	X86_SIM_L_EXEC_SETCC(X86_RSI, X86_CC_E);
x86_l_294:
	/* 0x294: shl    sil,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_298:
	/* 0x298: mov    ecx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBP, X86_WIDTH_32);
x86_l_29a:
	/* 0x29a: shr    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_29d:
	/* 0x29d: mov    edx,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_32);
x86_l_29f:
	/* 0x29f: shr    edx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_2a2:
	/* 0x2a2: test   sil,r14b */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RSI, X86_R14, X86_WIDTH_8);
x86_l_2a5:
	/* 0x2a5: je     2b0 <tail_drop_notify+0x2b0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2a5, 0x2b0, x86_l_2b0);
x86_l_2a7:
	/* 0x2a7: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&__config_trace_payload_len_overlay)));
x86_l_2ae:
	/* 0x2ae: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2b0:
	/* 0x2b0: mov    esi,DWORD PTR [rbx+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2b3:
	/* 0x2b3: cmp    esi,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RAX, X86_WIDTH_32);
x86_l_2b5:
	/* 0x2b5: cmovb  eax,esi */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RSI, X86_WIDTH_32, X86_CC_B);
x86_l_2b8:
	/* 0x2b8: mov    r10d,DWORD PTR [rbx+0x98] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_2bf:
	/* 0x2bf: mov    edi,DWORD PTR [rbx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_2c2:
	/* 0x2c2: mov    r8d,DWORD PTR [rbx+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_2c6:
	/* 0x2c6: mov    r9d,DWORD PTR [rbx+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2ca:
	/* 0x2ca: mov    esi,r15d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_32);
x86_l_2cd:
	/* 0x2cd: shr    esi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_SHR, 8ULL);
x86_l_2d0:
	/* 0x2d0: mov    r11,QWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2d4:
	/* 0x2d4: test   r11,r11 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R11, X86_R11, X86_WIDTH_64);
x86_l_2d7:
	/* 0x2d7: je     2e2 <tail_drop_notify+0x2e2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2d7, 0x2e2, x86_l_2e2);
x86_l_2d9:
	/* 0x2d9: mov    r11d,DWORD PTR [r11+0xe0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 224ULL);
x86_l_2e0:
	/* 0x2e0: jmp    2e5 <tail_drop_notify+0x2e5> */
	X86_SIM_X86_JMP(0x2e0, 0x2e5, x86_l_2e5);
x86_l_2e2:
	/* 0x2e2: xor    r11d,r11d */
	X86_SIM_L_EXEC_ALU_REG(X86_R11, X86_R11, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2e5:
	/* 0x2e5: mov    BYTE PTR [rsp+0x2f],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 201863462912ULL);
x86_l_2ea:
	/* 0x2ea: mov    WORD PTR [rsp+0x2d],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 193273528320ULL);
x86_l_2f1:
	/* 0x2f1: mov    BYTE PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_2f6:
	/* 0x2f6: mov    BYTE PTR [rsp+0x9],r15b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 9ULL);
x86_l_2fb:
	/* 0x2fb: mov    WORD PTR [rsp+0xa],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 42949672960ULL);
x86_l_302:
	/* 0x302: mov    DWORD PTR [rsp+0xc],r10d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R10, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_307:
	/* 0x307: mov    DWORD PTR [rsp+0x10],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_30c:
	/* 0x30c: mov    WORD PTR [rsp+0x14],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_311:
	/* 0x311: mov    WORD PTR [rsp+0x16],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 94489280515ULL);
x86_l_318:
	/* 0x318: mov    DWORD PTR [rsp+0x18],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_31c:
	/* 0x31c: mov    DWORD PTR [rsp+0x1c],r8d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_321:
	/* 0x321: mov    DWORD PTR [rsp+0x20],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_326:
	/* 0x326: mov    WORD PTR [rsp+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_32b:
	/* 0x32b: mov    BYTE PTR [rsp+0x26],dl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RDX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_32f:
	/* 0x32f: mov    BYTE PTR [rsp+0x27],sil */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 39ULL);
x86_l_334:
	/* 0x334: mov    DWORD PTR [rsp+0x28],r11d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_339:
	/* 0x339: mov    BYTE PTR [rsp+0x2c],r14b */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_33e:
	/* 0x33e: mov    QWORD PTR [rsp+0x30],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_343:
	/* 0x343: mov    r9d,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R9, X86_WIDTH_32, 25ULL);
x86_l_349:
	/* 0x349: shl    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHL, 32ULL);
x86_l_34d:
	/* 0x34d: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_352:
	/* 0x352: or     rdx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_64, X86_ALU_OR);
x86_l_355:
	/* 0x355: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_events)));
x86_l_35c:
	/* 0x35c: lea    rcx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_361:
	/* 0x361: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_364:
	/* 0x364: mov    r8d,0x30 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 48ULL);
x86_l_36a:
	/* 0x36a: call   r9 */
	X86_SIM_BPF_CALL_REG(X86_R9);
x86_l_36d:
	/* 0x36d: movzx  eax,bpl */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_WIDTH_8);
x86_l_371:
	/* 0x371: add    rsp,0x58 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 88ULL);
x86_l_375:
	/* 0x375: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_376:
	/* 0x376: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_378:
	/* 0x378: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_37a:
	/* 0x37a: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_37c:
	/* 0x37c: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_37e:
	/* 0x37e: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_37f:
	/* 0x37f: jmp    389 <tail_drop_notify+0x389> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_384:
	/* 0x384: inc    QWORD PTR [r14] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_387:
	/* 0x387: jmp    36d <tail_drop_notify+0x36d> */
	X86_SIM_X86_JMP(0x387, 0x36d, x86_l_36d);
x86_l_389:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
