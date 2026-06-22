extern char LINUX_KERNEL_VERSION;
extern char cgroup_map;
extern char filter_cg;
extern char filter_dev;
extern char start;
extern char targ_dev;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int bcc_biosnoop_block_rq_insert_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: sub    rsp,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 48ULL);
x86_l_4:
	/* 0x4: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_7:
	/* 0x7: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&filter_cg)));
x86_l_e:
	/* 0xe: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11:
	/* 0x11: je     2a <block_rq_insert+0x2a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11, 0x2a, x86_l_2a);
x86_l_13:
	/* 0x13: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cgroup_map)));
x86_l_1a:
	/* 0x1a: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c:
	/* 0x1c: call   21 <block_rq_insert+0x21> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_current_task_under_cgroup);
x86_l_21:
	/* 0x21: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_24:
	/* 0x24: je     140 <block_rq_insert+0x140> */
	X86_SIM_X86_JCC(X86_CC_E, 0x24, 0x140, x86_l_140);
x86_l_2a:
	/* 0x2a: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&LINUX_KERNEL_VERSION)));
x86_l_31:
	/* 0x31: cmp    DWORD PTR [rax],0x50b00 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 330496ULL);
x86_l_37:
	/* 0x37: jb     3e <block_rq_insert+0x3e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x37, 0x3e, x86_l_3e);
x86_l_39:
	/* 0x39: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3c:
	/* 0x3c: jmp    42 <block_rq_insert+0x42> */
	X86_SIM_X86_JMP(0x3c, 0x42, x86_l_42);
x86_l_3e:
	/* 0x3e: mov    rax,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_42:
	/* 0x42: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_47:
	/* 0x47: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_50:
	/* 0x50: mov    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_59:
	/* 0x59: mov    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_62:
	/* 0x62: call   67 <block_rq_insert+0x67> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_ktime_get_ns);
x86_l_67:
	/* 0x67: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_6a:
	/* 0x6a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&start)));
x86_l_71:
	/* 0x71: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_76:
	/* 0x76: call   7b <block_rq_insert+0x7b> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_7b:
	/* 0x7b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7e:
	/* 0x7e: je     96 <block_rq_insert+0x96> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7e, 0x96, x86_l_96);
x86_l_80:
	/* 0x80: mov    QWORD PTR [rax],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_83:
	/* 0x83: lea    rcx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_88:
	/* 0x88: cmp    rax,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_8b:
	/* 0x8b: jne    140 <block_rq_insert+0x140> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x8b, 0x140, x86_l_140);
x86_l_91:
	/* 0x91: jmp    128 <block_rq_insert+0x128> */
	X86_SIM_X86_JMP(0x91, 0x128, x86_l_128);
x86_l_96:
	/* 0x96: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_9b:
	/* 0x9b: add    rdx,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_9f:
	/* 0x9f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a4:
	/* 0xa4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a9:
	/* 0xa9: call   ae <block_rq_insert+0xae> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_ae:
	/* 0xae: mov    r14,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b3:
	/* 0xb3: test   r14,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64);
x86_l_b6:
	/* 0xb6: je     101 <block_rq_insert+0x101> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb6, 0x101, x86_l_101);
x86_l_b8:
	/* 0xb8: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bd:
	/* 0xbd: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_c2:
	/* 0xc2: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_c5:
	/* 0xc5: call   ca <block_rq_insert+0xca> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_ca:
	/* 0xca: mov    r13d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cf:
	/* 0xcf: shl    r13d,0x14 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_SHL, 20ULL);
x86_l_d3:
	/* 0xd3: add    r14,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_d7:
	/* 0xd7: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_dc:
	/* 0xdc: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_e1:
	/* 0xe1: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_e4:
	/* 0xe4: call   e9 <block_rq_insert+0xe9> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_e9:
	/* 0xe9: or     r13d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R13, X86_RSP, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_OR)), 8ULL);
x86_l_ee:
	/* 0xee: mov    DWORD PTR [rsp+0x28],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_f3:
	/* 0xf3: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&filter_dev)));
x86_l_fa:
	/* 0xfa: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fd:
	/* 0xfd: jne    115 <block_rq_insert+0x115> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xfd, 0x115, x86_l_115);
x86_l_ff:
	/* 0xff: jmp    123 <block_rq_insert+0x123> */
	X86_SIM_X86_JMP(0xff, 0x123, x86_l_123);
x86_l_101:
	/* 0x101: xor    r13d,r13d */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_R13, X86_WIDTH_32, X86_ALU_XOR);
x86_l_104:
	/* 0x104: mov    DWORD PTR [rsp+0x28],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_109:
	/* 0x109: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&filter_dev)));
x86_l_110:
	/* 0x110: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_113:
	/* 0x113: je     123 <block_rq_insert+0x123> */
	X86_SIM_X86_JCC(X86_CC_E, 0x113, 0x123, x86_l_123);
x86_l_115:
	/* 0x115: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&targ_dev)));
x86_l_11c:
	/* 0x11c: mov    eax,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11e:
	/* 0x11e: cmp    eax,r13d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R13, X86_WIDTH_32);
x86_l_121:
	/* 0x121: jne    140 <block_rq_insert+0x140> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x121, 0x140, x86_l_140);
x86_l_123:
	/* 0x123: mov    QWORD PTR [rsp+0x18],rbx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_128:
	/* 0x128: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&start)));
x86_l_12f:
	/* 0x12f: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_134:
	/* 0x134: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_139:
	/* 0x139: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13b:
	/* 0x13b: call   140 <block_rq_insert+0x140> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_map_update_elem);
x86_l_140:
	/* 0x140: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_142:
	/* 0x142: add    rsp,0x30 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 48ULL);
x86_l_146:
	/* 0x146: jmp    14b <block_rq_insert+0x14b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_14b:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
