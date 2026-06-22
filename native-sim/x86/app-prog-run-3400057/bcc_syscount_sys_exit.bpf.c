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
	/* 0x0: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_2:
	/* 0x2: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_4:
	/* 0x4: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_6:
	/* 0x6: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_8:
	/* 0x8: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_9:
	/* 0x9: sub    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_d:
	/* 0xd: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_10:
	/* 0x10: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&filter_cg)));
x86_l_17:
	/* 0x17: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a:
	/* 0x1a: je     33 <sys_exit+0x33> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a, 0x33, x86_l_33);
x86_l_1c:
	/* 0x1c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cgroup_map)));
x86_l_23:
	/* 0x23: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_25:
	/* 0x25: call   2a <sys_exit+0x2a> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_current_task_under_cgroup);
x86_l_2a:
	/* 0x2a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2d:
	/* 0x2d: je     19c <sys_exit+0x19c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2d, 0x19c, x86_l_19c);
x86_l_33:
	/* 0x33: call   38 <sys_exit+0x38> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_get_current_pid_tgid);
x86_l_38:
	/* 0x38: mov    DWORD PTR [rsp+0x4],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_3c:
	/* 0x3c: cmp    QWORD PTR [r14+0x8],0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738367ULL);
x86_l_41:
	/* 0x41: je     19c <sys_exit+0x19c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x41, 0x19c, x86_l_19c);
x86_l_47:
	/* 0x47: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&filter_pid)));
x86_l_4e:
	/* 0x4e: cmp    DWORD PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_51:
	/* 0x51: je     64 <sys_exit+0x64> */
	X86_SIM_X86_JCC(X86_CC_E, 0x51, 0x64, x86_l_64);
x86_l_53:
	/* 0x53: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_56:
	/* 0x56: shr    rdx,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_5a:
	/* 0x5a: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5c:
	/* 0x5c: cmp    ecx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_32);
x86_l_5e:
	/* 0x5e: jne    19c <sys_exit+0x19c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x5e, 0x19c, x86_l_19c);
x86_l_64:
	/* 0x64: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&filter_failed)));
x86_l_6b:
	/* 0x6b: cmp    BYTE PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6e:
	/* 0x6e: je     7b <sys_exit+0x7b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6e, 0x7b, x86_l_7b);
x86_l_70:
	/* 0x70: cmp    QWORD PTR [r14+0x10],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_75:
	/* 0x75: jns    19c <sys_exit+0x19c> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x75, 0x19c, x86_l_19c);
x86_l_7b:
	/* 0x7b: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&filter_errno)));
x86_l_82:
	/* 0x82: cmp    DWORD PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_85:
	/* 0x85: je     94 <sys_exit+0x94> */
	X86_SIM_X86_JCC(X86_CC_E, 0x85, 0x94, x86_l_94);
x86_l_87:
	/* 0x87: movsxd rcx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RCX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_8a:
	/* 0x8a: add    rcx,QWORD PTR [r14+0x10] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 16ULL);
x86_l_8e:
	/* 0x8e: jne    19c <sys_exit+0x19c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x8e, 0x19c, x86_l_19c);
x86_l_94:
	/* 0x94: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&measure_latency)));
x86_l_9b:
	/* 0x9b: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a0:
	/* 0xa0: je     e3 <sys_exit+0xe3> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa0, 0xe3, x86_l_e3);
x86_l_a2:
	/* 0xa2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&start)));
x86_l_a9:
	/* 0xa9: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_ae:
	/* 0xae: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_b1:
	/* 0xb1: call   b6 <sys_exit+0xb6> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_b6:
	/* 0xb6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_b9:
	/* 0xb9: je     19c <sys_exit+0x19c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb9, 0x19c, x86_l_19c);
x86_l_bf:
	/* 0xbf: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_c2:
	/* 0xc2: call   c7 <sys_exit+0xc7> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_ktime_get_ns);
x86_l_c7:
	/* 0xc7: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_ca:
	/* 0xca: mov    rax,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R13, X86_WIDTH_64);
x86_l_cd:
	/* 0xcd: sub    rbx,QWORD PTR [r15] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RBX, X86_R15, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 0ULL);
x86_l_d0:
	/* 0xd0: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&count_by_process)));
x86_l_d7:
	/* 0xd7: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_db:
	/* 0xdb: je     f2 <sys_exit+0xf2> */
	X86_SIM_X86_JCC(X86_CC_E, 0xdb, 0xf2, x86_l_f2);
x86_l_dd:
	/* 0xdd: sar    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SAR, 32ULL);
x86_l_e1:
	/* 0xe1: jmp    f6 <sys_exit+0xf6> */
	X86_SIM_X86_JMP(0xe1, 0xf6, x86_l_f6);
x86_l_e3:
	/* 0xe3: xor    ebx,ebx */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RBX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e5:
	/* 0xe5: mov    r15,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R15, (void *)(long)(((__u64)(long)&count_by_process)));
x86_l_ec:
	/* 0xec: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f0:
	/* 0xf0: jne    dd <sys_exit+0xdd> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf0, 0xdd, x86_l_dd);
x86_l_f2:
	/* 0xf2: mov    rax,QWORD PTR [r14+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f6:
	/* 0xf6: mov    DWORD PTR [rsp],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f9:
	/* 0xf9: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&data)));
x86_l_100:
	/* 0x100: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_103:
	/* 0x103: call   108 <sys_exit+0x108> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_108:
	/* 0x108: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_10b:
	/* 0x10b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10e:
	/* 0x10e: je     15b <sys_exit+0x15b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10e, 0x15b, x86_l_15b);
x86_l_110:
	/* 0x110: inc QWORD PTR [r14] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_114:
	/* 0x114: cmp    BYTE PTR [r15],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_118:
	/* 0x118: je     14d <sys_exit+0x14d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x118, 0x14d, x86_l_14d);
x86_l_11a:
	/* 0x11a: call   11f <sys_exit+0x11f> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_get_current_task);
x86_l_11f:
	/* 0x11f: lea    rdx,[rax+0xb10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2832ULL);
x86_l_126:
	/* 0x126: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12b:
	/* 0x12b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_130:
	/* 0x130: call   135 <sys_exit+0x135> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel_str);
x86_l_135:
	/* 0x135: lea    rdi,[r14+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_139:
	/* 0x139: mov    edx,0xcf0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 3312ULL);
x86_l_13e:
	/* 0x13e: add    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_143:
	/* 0x143: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_148:
	/* 0x148: call   14d <sys_exit+0x14d> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel_str);
x86_l_14d:
	/* 0x14d: cmp    BYTE PTR [r12],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R12, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_152:
	/* 0x152: je     19c <sys_exit+0x19c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x152, 0x19c, x86_l_19c);
x86_l_154:
	/* 0x154: add QWORD PTR [r14+0x8],rbx */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_R14, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_159:
	/* 0x159: jmp    19c <sys_exit+0x19c> */
	X86_SIM_X86_JMP(0x159, 0x19c, x86_l_19c);
x86_l_15b:
	/* 0x15b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&data)));
x86_l_162:
	/* 0x162: lea    rdx,[rip+0x0] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_LEA_AUX_RODATA, 0ULL);
x86_l_169:
	/* 0x169: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_16c:
	/* 0x16c: mov    ecx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_171:
	/* 0x171: call   176 <sys_exit+0x176> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_map_update_elem);
x86_l_176:
	/* 0x176: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_179:
	/* 0x179: je     181 <sys_exit+0x181> */
	X86_SIM_X86_JCC(X86_CC_E, 0x179, 0x181, x86_l_181);
x86_l_17b:
	/* 0x17b: cmp    rax,0xffffffffffffffef */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 18446744073709551599ULL);
x86_l_17f:
	/* 0x17f: jne    19c <sys_exit+0x19c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x17f, 0x19c, x86_l_19c);
x86_l_181:
	/* 0x181: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&data)));
x86_l_188:
	/* 0x188: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_18b:
	/* 0x18b: call   190 <sys_exit+0x190> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_190:
	/* 0x190: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_193:
	/* 0x193: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_196:
	/* 0x196: jne    110 <sys_exit+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x196, 0x110, x86_l_110);
x86_l_19c:
	/* 0x19c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_19e:
	/* 0x19e: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_1a2:
	/* 0x1a2: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_1a3:
	/* 0x1a3: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_1a5:
	/* 0x1a5: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_1a7:
	/* 0x1a7: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_1a9:
	/* 0x1a9: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_1ab:
	/* 0x1ab: jmp    1b0 <sys_exit+0x1b0> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_1b0:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
