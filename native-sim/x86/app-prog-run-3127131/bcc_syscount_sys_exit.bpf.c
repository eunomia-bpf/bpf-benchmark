extern char cgroup_map;
extern char count_by_process;
extern char data;
extern char filter_cg;
extern char filter_errno;
extern char filter_failed;
extern char filter_pid;
extern char measure_latency;
extern char start;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

static const __u64 __x86_rodata_0[2] = {0ULL, 0ULL};

SEC("xdp")
int bcc_syscount_sys_exit_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_2:
	/* 0x2: sub    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_6:
	/* 0x6: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_9:
	/* 0x9: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&filter_cg)));
x86_l_10:
	/* 0x10: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13:
	/* 0x13: je     2c <sys_exit+0x2c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13, 0x2c, x86_l_2c);
x86_l_15:
	/* 0x15: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cgroup_map)));
x86_l_1c:
	/* 0x1c: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e:
	/* 0x1e: call   23 <sys_exit+0x23> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_current_task_under_cgroup);
x86_l_23:
	/* 0x23: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_26:
	/* 0x26: je     195 <sys_exit+0x195> */
	X86_SIM_X86_JCC(X86_CC_E, 0x26, 0x195, x86_l_195);
x86_l_2c:
	/* 0x2c: call   31 <sys_exit+0x31> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_get_current_pid_tgid);
x86_l_31:
	/* 0x31: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_35:
	/* 0x35: cmp    QWORD PTR [r14+0x8],0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738367ULL);
x86_l_3a:
	/* 0x3a: je     195 <sys_exit+0x195> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3a, 0x195, x86_l_195);
x86_l_40:
	/* 0x40: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&filter_pid)));
x86_l_47:
	/* 0x47: cmp    DWORD PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_4a:
	/* 0x4a: je     5d <sys_exit+0x5d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4a, 0x5d, x86_l_5d);
x86_l_4c:
	/* 0x4c: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_4f:
	/* 0x4f: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_53:
	/* 0x53: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_55:
	/* 0x55: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_57:
	/* 0x57: jne    195 <sys_exit+0x195> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x57, 0x195, x86_l_195);
x86_l_5d:
	/* 0x5d: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&filter_failed)));
x86_l_64:
	/* 0x64: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_67:
	/* 0x67: je     74 <sys_exit+0x74> */
	X86_SIM_X86_JCC(X86_CC_E, 0x67, 0x74, x86_l_74);
x86_l_69:
	/* 0x69: cmp    QWORD PTR [r14+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_6e:
	/* 0x6e: jns    195 <sys_exit+0x195> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x6e, 0x195, x86_l_195);
x86_l_74:
	/* 0x74: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&filter_errno)));
x86_l_7b:
	/* 0x7b: cmp    DWORD PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7e:
	/* 0x7e: je     8d <sys_exit+0x8d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7e, 0x8d, x86_l_8d);
x86_l_80:
	/* 0x80: movsxd rcx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_83:
	/* 0x83: add    rcx,QWORD PTR [r14+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_87:
	/* 0x87: jne    195 <sys_exit+0x195> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x87, 0x195, x86_l_195);
x86_l_8d:
	/* 0x8d: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&measure_latency)));
x86_l_94:
	/* 0x94: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_99:
	/* 0x99: je     dc <sys_exit+0xdc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x99, 0xdc, x86_l_dc);
x86_l_9b:
	/* 0x9b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&start)));
x86_l_a2:
	/* 0xa2: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_a7:
	/* 0xa7: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_aa:
	/* 0xaa: call   af <sys_exit+0xaf> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_af:
	/* 0xaf: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b2:
	/* 0xb2: je     195 <sys_exit+0x195> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb2, 0x195, x86_l_195);
x86_l_b8:
	/* 0xb8: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_bb:
	/* 0xbb: call   c0 <sys_exit+0xc0> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_ktime_get_ns);
x86_l_c0:
	/* 0xc0: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_c3:
	/* 0xc3: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_c6:
	/* 0xc6: sub    rbx,QWORD PTR [r15] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 0ULL);
x86_l_c9:
	/* 0xc9: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&count_by_process)));
x86_l_d0:
	/* 0xd0: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d4:
	/* 0xd4: je     eb <sys_exit+0xeb> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd4, 0xeb, x86_l_eb);
x86_l_d6:
	/* 0xd6: sar    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SAR, 32ULL);
x86_l_da:
	/* 0xda: jmp    ef <sys_exit+0xef> */
	X86_SIM_X86_JMP(0xda, 0xef, x86_l_ef);
x86_l_dc:
	/* 0xdc: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_de:
	/* 0xde: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&count_by_process)));
x86_l_e5:
	/* 0xe5: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e9:
	/* 0xe9: jne    d6 <sys_exit+0xd6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe9, 0xd6, x86_l_d6);
x86_l_eb:
	/* 0xeb: mov    rax,QWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ef:
	/* 0xef: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f2:
	/* 0xf2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&data)));
x86_l_f9:
	/* 0xf9: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_fc:
	/* 0xfc: call   101 <sys_exit+0x101> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_101:
	/* 0x101: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_104:
	/* 0x104: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_107:
	/* 0x107: je     154 <sys_exit+0x154> */
	X86_SIM_X86_JCC(X86_CC_E, 0x107, 0x154, x86_l_154);
x86_l_109:
	/* 0x109: inc QWORD PTR [r14] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_10d:
	/* 0x10d: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_111:
	/* 0x111: je     146 <sys_exit+0x146> */
	X86_SIM_X86_JCC(X86_CC_E, 0x111, 0x146, x86_l_146);
x86_l_113:
	/* 0x113: call   118 <sys_exit+0x118> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_get_current_task);
x86_l_118:
	/* 0x118: lea    rdx,[rax+0xb10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2832ULL);
x86_l_11f:
	/* 0x11f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_124:
	/* 0x124: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_129:
	/* 0x129: call   12e <sys_exit+0x12e> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel_str);
x86_l_12e:
	/* 0x12e: lea    rdi,[r14+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_132:
	/* 0x132: mov    edx,0xcf0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3312ULL);
x86_l_137:
	/* 0x137: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_13c:
	/* 0x13c: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_141:
	/* 0x141: call   146 <sys_exit+0x146> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel_str);
x86_l_146:
	/* 0x146: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14b:
	/* 0x14b: je     195 <sys_exit+0x195> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14b, 0x195, x86_l_195);
x86_l_14d:
	/* 0x14d: add QWORD PTR [r14+0x8],rbx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R14, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_152:
	/* 0x152: jmp    195 <sys_exit+0x195> */
	X86_SIM_X86_JMP(0x152, 0x195, x86_l_195);
x86_l_154:
	/* 0x154: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&data)));
x86_l_15b:
	/* 0x15b: lea    rdx,[rip+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 0ULL);
x86_l_162:
	/* 0x162: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_165:
	/* 0x165: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_16a:
	/* 0x16a: call   16f <sys_exit+0x16f> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_map_update_elem);
x86_l_16f:
	/* 0x16f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_172:
	/* 0x172: je     17a <sys_exit+0x17a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x172, 0x17a, x86_l_17a);
x86_l_174:
	/* 0x174: cmp    rax,0xffffffffffffffef */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 18446744073709551599ULL);
x86_l_178:
	/* 0x178: jne    195 <sys_exit+0x195> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x178, 0x195, x86_l_195);
x86_l_17a:
	/* 0x17a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&data)));
x86_l_181:
	/* 0x181: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_184:
	/* 0x184: call   189 <sys_exit+0x189> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_189:
	/* 0x189: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_18c:
	/* 0x18c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_18f:
	/* 0x18f: jne    109 <sys_exit+0x109> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x18f, 0x109, x86_l_109);
x86_l_195:
	/* 0x195: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_197:
	/* 0x197: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_19b:
	/* 0x19b: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_19d:
	/* 0x19d: jmp    1a2 <sys_exit+0x1a2> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_1a2:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
