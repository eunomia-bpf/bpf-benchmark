extern char execve_map;
extern char tcpmon_map;
extern char tg_cgrps_msg_heap;
extern char tg_cgrps_tracking_map;
extern char tg_conf_map;
extern char tg_errmetrics_map;
extern char tg_rb_events;
extern char tg_stats_map;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_cgroup_rmdir_v511_tg_tp_cgrp_rmdir_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 56ULL);
x86_l_7:
	/* 0x7: mov    DWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_f:
	/* 0xf: mov    r14,QWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12:
	/* 0x12: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1b:
	/* 0x1b: test   r14,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64);
x86_l_1e:
	/* 0x1e: je     3b6 <tg_tp_cgrp_rmdir+0x3b6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1e, 0x3b6, x86_l_3b6);
x86_l_24:
	/* 0x24: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_27:
	/* 0x27: lea    rdx,[r14+0x100] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 256ULL);
x86_l_2e:
	/* 0x2e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_33:
	/* 0x33: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_38:
	/* 0x38: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_3d:
	/* 0x3d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f:
	/* 0x3f: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_44:
	/* 0x44: mov    QWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_4d:
	/* 0x4d: test   rdx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_64);
x86_l_50:
	/* 0x50: je     3b6 <tg_tp_cgrp_rmdir+0x3b6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x50, 0x3b6, x86_l_3b6);
x86_l_56:
	/* 0x56: add    rdx,0x60 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 96ULL);
x86_l_5a:
	/* 0x5a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5f:
	/* 0x5f: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_64:
	/* 0x64: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_69:
	/* 0x69: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6b:
	/* 0x6b: mov    rax,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_70:
	/* 0x70: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_75:
	/* 0x75: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_78:
	/* 0x78: je     3b6 <tg_tp_cgrp_rmdir+0x3b6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x78, 0x3b6, x86_l_3b6);
x86_l_7e:
	/* 0x7e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_83:
	/* 0x83: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_cgrps_tracking_map)));
x86_l_8a:
	/* 0x8a: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_8f:
	/* 0x8f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_91:
	/* 0x91: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_94:
	/* 0x94: je     2d6 <tg_tp_cgrp_rmdir+0x2d6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x94, 0x2d6, x86_l_2d6);
x86_l_9a:
	/* 0x9a: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_9d:
	/* 0x9d: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_a2:
	/* 0xa2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_cgrps_tracking_map)));
x86_l_a9:
	/* 0xa9: lea    rsi,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_ae:
	/* 0xae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b0:
	/* 0xb0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b5:
	/* 0xb5: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_conf_map)));
x86_l_bc:
	/* 0xbc: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c1:
	/* 0xc1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c3:
	/* 0xc3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_c6:
	/* 0xc6: je     3b6 <tg_tp_cgrp_rmdir+0x3b6> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc6, 0x3b6, x86_l_3b6);
x86_l_cc:
	/* 0xcc: cmp    DWORD PTR [rax],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_cf:
	/* 0xcf: jne    3b6 <tg_tp_cgrp_rmdir+0x3b6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xcf, 0x3b6, x86_l_3b6);
x86_l_d5:
	/* 0xd5: mov    rbp,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_da:
	/* 0xda: mov    DWORD PTR [rsp+0x34],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 223338299392ULL);
x86_l_e2:
	/* 0xe2: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e7:
	/* 0xe7: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_cgrps_msg_heap)));
x86_l_ee:
	/* 0xee: lea    rsi,[rsp+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_f3:
	/* 0xf3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f5:
	/* 0xf5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f8:
	/* 0xf8: je     3b6 <tg_tp_cgrp_rmdir+0x3b6> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf8, 0x3b6, x86_l_3b6);
x86_l_fe:
	/* 0xfe: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_101:
	/* 0x101: mov    BYTE PTR [rax],0x19 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 25ULL);
x86_l_104:
	/* 0x104: mov    DWORD PTR [rax+0x4],0x10d8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179873496ULL);
x86_l_10b:
	/* 0x10b: mov    r15,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10f:
	/* 0x10f: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_114:
	/* 0x114: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_116:
	/* 0x116: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_119:
	/* 0x119: shr    r12,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_11d:
	/* 0x11d: mov    DWORD PTR [rsp+0x8],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_122:
	/* 0x122: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_127:
	/* 0x127: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_12e:
	/* 0x12e: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_133:
	/* 0x133: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_135:
	/* 0x135: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_138:
	/* 0x138: je     161 <tg_tp_cgrp_rmdir+0x161> */
	X86_SIM_X86_JCC(X86_CC_E, 0x138, 0x161, x86_l_161);
x86_l_13a:
	/* 0x13a: mov    rcx,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13e:
	/* 0x13e: mov    QWORD PTR [r14+0x8],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_142:
	/* 0x142: mov    rcx,QWORD PTR [rax+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_146:
	/* 0x146: mov    rdx,QWORD PTR [rax+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_14a:
	/* 0x14a: mov    QWORD PTR [r14+0x10],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_14e:
	/* 0x14e: mov    QWORD PTR [r14+0x18],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_152:
	/* 0x152: mov    ecx,DWORD PTR [rax+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_155:
	/* 0x155: mov    DWORD PTR [r14+0x2c],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_159:
	/* 0x159: mov    rax,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15d:
	/* 0x15d: mov    QWORD PTR [r14+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_161:
	/* 0x161: mov    DWORD PTR [r14+0x20],0x2 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953474ULL);
x86_l_169:
	/* 0x169: mov    DWORD PTR [r14+0x24],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_16d:
	/* 0x16d: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_172:
	/* 0x172: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_174:
	/* 0x174: lea    rdx,[rax+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_178:
	/* 0x178: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_17d:
	/* 0x17d: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_182:
	/* 0x182: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_187:
	/* 0x187: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_189:
	/* 0x189: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18c:
	/* 0x18c: cmp    QWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_192:
	/* 0x192: je     1e1 <tg_tp_cgrp_rmdir+0x1e1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x192, 0x1e1, x86_l_1e1);
x86_l_194:
	/* 0x194: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_199:
	/* 0x199: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_19e:
	/* 0x19e: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1a2:
	/* 0x1a2: lea    rdi,[rsp+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1a7:
	/* 0x1a7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1ac:
	/* 0x1ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ae:
	/* 0x1ae: cmp    DWORD PTR [rsp+0x24],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 154618822656ULL);
x86_l_1b3:
	/* 0x1b3: je     1e1 <tg_tp_cgrp_rmdir+0x1e1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1b3, 0x1e1, x86_l_1e1);
x86_l_1b5:
	/* 0x1b5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ba:
	/* 0x1ba: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1bf:
	/* 0x1bf: mov    edx,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_1c3:
	/* 0x1c3: shl    edx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_SHL, 4ULL);
x86_l_1c6:
	/* 0x1c6: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1c9:
	/* 0x1c9: add    rdx,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 136ULL);
x86_l_1d0:
	/* 0x1d0: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d5:
	/* 0x1d5: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_1da:
	/* 0x1da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1dc:
	/* 0x1dc: mov    r12d,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1e1:
	/* 0x1e1: mov    DWORD PTR [r14+0x28],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1e5:
	/* 0x1e5: mov    QWORD PTR [r14+0x40],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1e9:
	/* 0x1e9: mov    QWORD PTR [r14+0x38],rbp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1ed:
	/* 0x1ed: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_1f0:
	/* 0x1f0: mov    eax,DWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f4:
	/* 0x1f4: mov    DWORD PTR [r14+0x48],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1f8:
	/* 0x1f8: mov    eax,DWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1fc:
	/* 0x1fc: mov    DWORD PTR [r14+0x50],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_200:
	/* 0x200: mov    eax,DWORD PTR [r13+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_204:
	/* 0x204: mov    DWORD PTR [r14+0x4c],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_208:
	/* 0x208: lea    rdi,[r14+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_20c:
	/* 0x20c: add    rsi,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_210:
	/* 0x210: mov    ecx,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 32ULL);
x86_l_215:
	/* 0x215: rep movs DWORD PTR es:[rdi],DWORD PTR ds:[rsi] */
	X86_SIM_L_EXEC_REP_MOVS(X86_WIDTH_64, 32ULL);
x86_l_217:
	/* 0x217: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_21a:
	/* 0x21a: add    rdi,0xd8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 216ULL);
x86_l_221:
	/* 0x221: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_226:
	/* 0x226: mov    esi,0xfff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4095ULL);
x86_l_22b:
	/* 0x22b: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_22e:
	/* 0x22e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_230:
	/* 0x230: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_238:
	/* 0x238: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_23d:
	/* 0x23d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_conf_map)));
x86_l_244:
	/* 0x244: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_249:
	/* 0x249: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24b:
	/* 0x24b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_24e:
	/* 0x24e: je     3c4 <tg_tp_cgrp_rmdir+0x3c4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x24e, 0x3c4, x86_l_3c4);
x86_l_254:
	/* 0x254: cmp    BYTE PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_258:
	/* 0x258: je     3c4 <tg_tp_cgrp_rmdir+0x3c4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x258, 0x3c4, x86_l_3c4);
x86_l_25e:
	/* 0x25e: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_263:
	/* 0x263: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tcpmon_map)));
x86_l_26a:
	/* 0x26a: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_26f:
	/* 0x26f: mov    r8d,0x10d8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 4312ULL);
x86_l_275:
	/* 0x275: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_278:
	/* 0x278: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_27b:
	/* 0x27b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_27d:
	/* 0x27d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_280:
	/* 0x280: jns    3b6 <tg_tp_cgrp_rmdir+0x3b6> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x280, 0x3b6, x86_l_3b6);
x86_l_286:
	/* 0x286: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_289:
	/* 0x289: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_291:
	/* 0x291: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_296:
	/* 0x296: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_29d:
	/* 0x29d: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2a2:
	/* 0x2a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a4:
	/* 0x2a4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2a7:
	/* 0x2a7: je     3b6 <tg_tp_cgrp_rmdir+0x3b6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2a7, 0x3b6, x86_l_3b6);
x86_l_2ad:
	/* 0x2ad: cmp    rbx,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_2b1:
	/* 0x2b1: jg     442 <tg_tp_cgrp_rmdir+0x442> */
	X86_SIM_X86_JCC(X86_CC_G, 0x2b1, 0x442, x86_l_442);
x86_l_2b7:
	/* 0x2b7: cmp    rbx,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_2bb:
	/* 0x2bb: je     45c <tg_tp_cgrp_rmdir+0x45c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2bb, 0x45c, x86_l_45c);
x86_l_2c1:
	/* 0x2c1: cmp    rbx,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_2c5:
	/* 0x2c5: jne    41a <tg_tp_cgrp_rmdir+0x41a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2c5, 0x41a, x86_l_41a);
x86_l_2cb:
	/* 0x2cb: add    rax,0x598 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1432ULL);
x86_l_2d1:
	/* 0x2d1: jmp    472 <tg_tp_cgrp_rmdir+0x472> */
	X86_SIM_X86_JMP(0x2d1, 0x472, x86_l_472);
x86_l_2d6:
	/* 0x2d6: mov    DWORD PTR [rsp+0x24],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 154618822656ULL);
x86_l_2de:
	/* 0x2de: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2e6:
	/* 0x2e6: lea    rdx,[r14+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_2ed:
	/* 0x2ed: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2f2:
	/* 0x2f2: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f7:
	/* 0x2f7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2fc:
	/* 0x2fc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fe:
	/* 0x2fe: mov    ebx,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_302:
	/* 0x302: add    r14,0x2e0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 736ULL);
x86_l_309:
	/* 0x309: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_30e:
	/* 0x30e: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_313:
	/* 0x313: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_318:
	/* 0x318: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_31b:
	/* 0x31b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31d:
	/* 0x31d: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_322:
	/* 0x322: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_327:
	/* 0x327: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_32b:
	/* 0x32b: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_330:
	/* 0x330: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_335:
	/* 0x335: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_337:
	/* 0x337: mov    ebp,DWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_33b:
	/* 0x33b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_340:
	/* 0x340: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_conf_map)));
x86_l_347:
	/* 0x347: lea    rsi,[rsp+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_34c:
	/* 0x34c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34e:
	/* 0x34e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_351:
	/* 0x351: je     3b6 <tg_tp_cgrp_rmdir+0x3b6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x351, 0x3b6, x86_l_3b6);
x86_l_353:
	/* 0x353: mov    ecx,DWORD PTR [rax+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_356:
	/* 0x356: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_358:
	/* 0x358: je     3b6 <tg_tp_cgrp_rmdir+0x3b6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x358, 0x3b6, x86_l_3b6);
x86_l_35a:
	/* 0x35a: cmp    DWORD PTR [rax+0xc],ebp */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_35d:
	/* 0x35d: jne    3b6 <tg_tp_cgrp_rmdir+0x3b6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x35d, 0x3b6, x86_l_3b6);
x86_l_35f:
	/* 0x35f: test   ebx,ebx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32);
x86_l_361:
	/* 0x361: je     3b6 <tg_tp_cgrp_rmdir+0x3b6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x361, 0x3b6, x86_l_3b6);
x86_l_363:
	/* 0x363: cmp    ebx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_RCX, X86_WIDTH_32);
x86_l_365:
	/* 0x365: ja     3b6 <tg_tp_cgrp_rmdir+0x3b6> */
	X86_SIM_X86_JCC(X86_CC_A, 0x365, 0x3b6, x86_l_3b6);
x86_l_367:
	/* 0x367: mov    DWORD PTR [rsp+0x8],0xd0002 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34360590338ULL);
x86_l_36f:
	/* 0x36f: mov    QWORD PTR [rsp+0xc],0x27 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 51539607591ULL);
x86_l_378:
	/* 0x378: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_37d:
	/* 0x37d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_384:
	/* 0x384: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_389:
	/* 0x389: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_38b:
	/* 0x38b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_38e:
	/* 0x38e: je     394 <tg_tp_cgrp_rmdir+0x394> */
	X86_SIM_X86_JCC(X86_CC_E, 0x38e, 0x394, x86_l_394);
x86_l_390:
	/* 0x390: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_392:
	/* 0x392: jmp    3b6 <tg_tp_cgrp_rmdir+0x3b6> */
	X86_SIM_X86_JMP(0x392, 0x3b6, x86_l_3b6);
x86_l_394:
	/* 0x394: mov    DWORD PTR [rsp+0x18],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215105ULL);
x86_l_39c:
	/* 0x39c: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_3a1:
	/* 0x3a1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_3a8:
	/* 0x3a8: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3ad:
	/* 0x3ad: lea    rdx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3b2:
	/* 0x3b2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3b4:
	/* 0x3b4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b6:
	/* 0x3b6: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3b8:
	/* 0x3b8: add    rsp,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 56ULL);
x86_l_3bc:
	/* 0x3bc: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_3be:
	/* 0x3be: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_3bf:
	/* 0x3bf: jmp    47b <tg_tp_cgrp_rmdir+0x47b> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_3c4:
	/* 0x3c4: mov    eax,0x82 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 130ULL);
x86_l_3c9:
	/* 0x3c9: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_rb_events)));
x86_l_3d0:
	/* 0x3d0: mov    edx,0x10d8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4312ULL);
x86_l_3d5:
	/* 0x3d5: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_3d8:
	/* 0x3d8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3da:
	/* 0x3da: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3dc:
	/* 0x3dc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3df:
	/* 0x3df: jns    3b6 <tg_tp_cgrp_rmdir+0x3b6> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x3df, 0x3b6, x86_l_3b6);
x86_l_3e1:
	/* 0x3e1: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_3e4:
	/* 0x3e4: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_3ec:
	/* 0x3ec: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3f1:
	/* 0x3f1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_3f8:
	/* 0x3f8: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3fd:
	/* 0x3fd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ff:
	/* 0x3ff: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_402:
	/* 0x402: je     3b6 <tg_tp_cgrp_rmdir+0x3b6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x402, 0x3b6, x86_l_3b6);
x86_l_404:
	/* 0x404: cmp    rbx,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_408:
	/* 0x408: jg     428 <tg_tp_cgrp_rmdir+0x428> */
	X86_SIM_X86_JCC(X86_CC_G, 0x408, 0x428, x86_l_428);
x86_l_40a:
	/* 0x40a: cmp    rbx,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_40e:
	/* 0x40e: je     45c <tg_tp_cgrp_rmdir+0x45c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x40e, 0x45c, x86_l_45c);
x86_l_410:
	/* 0x410: cmp    rbx,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_414:
	/* 0x414: je     2cb <tg_tp_cgrp_rmdir+0x2cb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x414, 0x2cb, x86_l_2cb);
x86_l_41a:
	/* 0x41a: cmp    rbx,0xfffffffffffffff0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551600ULL);
x86_l_41e:
	/* 0x41e: jne    454 <tg_tp_cgrp_rmdir+0x454> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x41e, 0x454, x86_l_454);
x86_l_420:
	/* 0x420: add    rax,0x590 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1424ULL);
x86_l_426:
	/* 0x426: jmp    472 <tg_tp_cgrp_rmdir+0x472> */
	X86_SIM_X86_JMP(0x426, 0x472, x86_l_472);
x86_l_428:
	/* 0x428: cmp    rbx,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_42c:
	/* 0x42c: je     464 <tg_tp_cgrp_rmdir+0x464> */
	X86_SIM_X86_JCC(X86_CC_E, 0x42c, 0x464, x86_l_464);
x86_l_42e:
	/* 0x42e: cmp    rbx,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_432:
	/* 0x432: je     46c <tg_tp_cgrp_rmdir+0x46c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x432, 0x46c, x86_l_46c);
x86_l_434:
	/* 0x434: cmp    rbx,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_438:
	/* 0x438: jne    454 <tg_tp_cgrp_rmdir+0x454> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x438, 0x454, x86_l_454);
x86_l_43a:
	/* 0x43a: add    rax,0x580 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1408ULL);
x86_l_440:
	/* 0x440: jmp    472 <tg_tp_cgrp_rmdir+0x472> */
	X86_SIM_X86_JMP(0x440, 0x472, x86_l_472);
x86_l_442:
	/* 0x442: cmp    rbx,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_446:
	/* 0x446: je     464 <tg_tp_cgrp_rmdir+0x464> */
	X86_SIM_X86_JCC(X86_CC_E, 0x446, 0x464, x86_l_464);
x86_l_448:
	/* 0x448: cmp    rbx,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_44c:
	/* 0x44c: je     46c <tg_tp_cgrp_rmdir+0x46c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x44c, 0x46c, x86_l_46c);
x86_l_44e:
	/* 0x44e: cmp    rbx,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_452:
	/* 0x452: je     43a <tg_tp_cgrp_rmdir+0x43a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x452, 0x43a, x86_l_43a);
x86_l_454:
	/* 0x454: add    rax,0x578 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1400ULL);
x86_l_45a:
	/* 0x45a: jmp    472 <tg_tp_cgrp_rmdir+0x472> */
	X86_SIM_X86_JMP(0x45a, 0x472, x86_l_472);
x86_l_45c:
	/* 0x45c: add    rax,0x5a0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1440ULL);
x86_l_462:
	/* 0x462: jmp    472 <tg_tp_cgrp_rmdir+0x472> */
	X86_SIM_X86_JMP(0x462, 0x472, x86_l_472);
x86_l_464:
	/* 0x464: add    rax,0x5a8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1448ULL);
x86_l_46a:
	/* 0x46a: jmp    472 <tg_tp_cgrp_rmdir+0x472> */
	X86_SIM_X86_JMP(0x46a, 0x472, x86_l_472);
x86_l_46c:
	/* 0x46c: add    rax,0x588 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1416ULL);
x86_l_472:
	/* 0x472: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_476:
	/* 0x476: jmp    3b6 <tg_tp_cgrp_rmdir+0x3b6> */
	X86_SIM_X86_JMP(0x476, 0x3b6, x86_l_3b6);
x86_l_47b:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
