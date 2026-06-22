extern char execve_map;
extern char tcpmon_map;
extern char tg_cgrps_msg_heap;
extern char tg_cgrps_tracking_map;
extern char tg_conf_map;
extern char tg_errmetrics_map;
extern char tg_stats_map;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_cgroup_release_tg_tp_cgrp_release_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0x1e: je     392 <tg_tp_cgrp_release+0x392> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1e, 0x392, x86_l_392);
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
	/* 0x50: je     392 <tg_tp_cgrp_release+0x392> */
	X86_SIM_X86_JCC(X86_CC_E, 0x50, 0x392, x86_l_392);
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
	/* 0x78: je     392 <tg_tp_cgrp_release+0x392> */
	X86_SIM_X86_JCC(X86_CC_E, 0x78, 0x392, x86_l_392);
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
	/* 0x94: je     2b2 <tg_tp_cgrp_release+0x2b2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x94, 0x2b2, x86_l_2b2);
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
	/* 0xc6: je     392 <tg_tp_cgrp_release+0x392> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc6, 0x392, x86_l_392);
x86_l_cc:
	/* 0xcc: cmp    DWORD PTR [rax],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_cf:
	/* 0xcf: jne    392 <tg_tp_cgrp_release+0x392> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xcf, 0x392, x86_l_392);
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
	/* 0xf8: je     392 <tg_tp_cgrp_release+0x392> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf8, 0x392, x86_l_392);
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
	/* 0x138: je     161 <tg_tp_cgrp_release+0x161> */
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
	/* 0x161: mov    DWORD PTR [r14+0x20],0x3 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953475ULL);
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
	/* 0x17d: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
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
	/* 0x18c: cmp    QWORD PTR [rsp+0x20],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 137438953472ULL);
x86_l_192:
	/* 0x192: je     1e1 <tg_tp_cgrp_release+0x1e1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x192, 0x1e1, x86_l_1e1);
x86_l_194:
	/* 0x194: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_199:
	/* 0x199: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_19e:
	/* 0x19e: add    rdx,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1a2:
	/* 0x1a2: lea    rdi,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1a7:
	/* 0x1a7: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_1ac:
	/* 0x1ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1ae:
	/* 0x1ae: cmp    DWORD PTR [rsp+0x1c],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084288ULL);
x86_l_1b3:
	/* 0x1b3: je     1e1 <tg_tp_cgrp_release+0x1e1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1b3, 0x1e1, x86_l_1e1);
x86_l_1b5:
	/* 0x1b5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1ba:
	/* 0x1ba: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1bf:
	/* 0x1bf: mov    edx,DWORD PTR [rsp+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
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
	/* 0x230: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_235:
	/* 0x235: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tcpmon_map)));
x86_l_23c:
	/* 0x23c: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_241:
	/* 0x241: mov    r8d,0x10d8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 4312ULL);
x86_l_247:
	/* 0x247: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_24a:
	/* 0x24a: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_24d:
	/* 0x24d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24f:
	/* 0x24f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_252:
	/* 0x252: jns    392 <tg_tp_cgrp_release+0x392> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x252, 0x392, x86_l_392);
x86_l_258:
	/* 0x258: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_25b:
	/* 0x25b: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_263:
	/* 0x263: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_268:
	/* 0x268: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_26f:
	/* 0x26f: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_274:
	/* 0x274: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_276:
	/* 0x276: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_279:
	/* 0x279: je     392 <tg_tp_cgrp_release+0x392> */
	X86_SIM_X86_JCC(X86_CC_E, 0x279, 0x392, x86_l_392);
x86_l_27f:
	/* 0x27f: cmp    rbx,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_283:
	/* 0x283: jg     3a0 <tg_tp_cgrp_release+0x3a0> */
	X86_SIM_X86_JCC(X86_CC_G, 0x283, 0x3a0, x86_l_3a0);
x86_l_289:
	/* 0x289: cmp    rbx,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_28d:
	/* 0x28d: je     3ba <tg_tp_cgrp_release+0x3ba> */
	X86_SIM_X86_JCC(X86_CC_E, 0x28d, 0x3ba, x86_l_3ba);
x86_l_293:
	/* 0x293: cmp    rbx,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_297:
	/* 0x297: je     3d2 <tg_tp_cgrp_release+0x3d2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x297, 0x3d2, x86_l_3d2);
x86_l_29d:
	/* 0x29d: cmp    rbx,0xfffffffffffffff0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551600ULL);
x86_l_2a1:
	/* 0x2a1: jne    3ca <tg_tp_cgrp_release+0x3ca> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2a1, 0x3ca, x86_l_3ca);
x86_l_2a7:
	/* 0x2a7: add    rax,0x590 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1424ULL);
x86_l_2ad:
	/* 0x2ad: jmp    3e0 <tg_tp_cgrp_release+0x3e0> */
	X86_SIM_X86_JMP(0x2ad, 0x3e0, x86_l_3e0);
x86_l_2b2:
	/* 0x2b2: mov    DWORD PTR [rsp+0x1c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084288ULL);
x86_l_2ba:
	/* 0x2ba: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_2c2:
	/* 0x2c2: lea    rdx,[r14+0xd8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 216ULL);
x86_l_2c9:
	/* 0x2c9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2ce:
	/* 0x2ce: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d3:
	/* 0x2d3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2d8:
	/* 0x2d8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2da:
	/* 0x2da: mov    ebx,DWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2de:
	/* 0x2de: add    r14,0x2e0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 736ULL);
x86_l_2e5:
	/* 0x2e5: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2ea:
	/* 0x2ea: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ef:
	/* 0x2ef: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f4:
	/* 0x2f4: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_2f7:
	/* 0x2f7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f9:
	/* 0x2f9: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2fe:
	/* 0x2fe: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_303:
	/* 0x303: add    rdx,0xc */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_ADD, 12ULL);
x86_l_307:
	/* 0x307: lea    rdi,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_30c:
	/* 0x30c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_311:
	/* 0x311: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_313:
	/* 0x313: mov    ebp,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_317:
	/* 0x317: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_31c:
	/* 0x31c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_conf_map)));
x86_l_323:
	/* 0x323: lea    rsi,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_328:
	/* 0x328: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32a:
	/* 0x32a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_32d:
	/* 0x32d: je     392 <tg_tp_cgrp_release+0x392> */
	X86_SIM_X86_JCC(X86_CC_E, 0x32d, 0x392, x86_l_392);
x86_l_32f:
	/* 0x32f: mov    ecx,DWORD PTR [rax+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_332:
	/* 0x332: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_334:
	/* 0x334: je     392 <tg_tp_cgrp_release+0x392> */
	X86_SIM_X86_JCC(X86_CC_E, 0x334, 0x392, x86_l_392);
x86_l_336:
	/* 0x336: cmp    DWORD PTR [rax+0xc],ebp */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_339:
	/* 0x339: jne    392 <tg_tp_cgrp_release+0x392> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x339, 0x392, x86_l_392);
x86_l_33b:
	/* 0x33b: test   ebx,ebx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RBX, X86_RBX, X86_WIDTH_32);
x86_l_33d:
	/* 0x33d: je     392 <tg_tp_cgrp_release+0x392> */
	X86_SIM_X86_JCC(X86_CC_E, 0x33d, 0x392, x86_l_392);
x86_l_33f:
	/* 0x33f: cmp    ebx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RBX, X86_RCX, X86_WIDTH_32);
x86_l_341:
	/* 0x341: ja     392 <tg_tp_cgrp_release+0x392> */
	X86_SIM_X86_JCC(X86_CC_A, 0x341, 0x392, x86_l_392);
x86_l_343:
	/* 0x343: mov    DWORD PTR [rsp+0x8],0xc0002 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34360524802ULL);
x86_l_34b:
	/* 0x34b: mov    QWORD PTR [rsp+0xc],0x27 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 51539607591ULL);
x86_l_354:
	/* 0x354: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_359:
	/* 0x359: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_360:
	/* 0x360: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_365:
	/* 0x365: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_367:
	/* 0x367: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_36a:
	/* 0x36a: je     370 <tg_tp_cgrp_release+0x370> */
	X86_SIM_X86_JCC(X86_CC_E, 0x36a, 0x370, x86_l_370);
x86_l_36c:
	/* 0x36c: inc    DWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_36e:
	/* 0x36e: jmp    392 <tg_tp_cgrp_release+0x392> */
	X86_SIM_X86_JMP(0x36e, 0x392, x86_l_392);
x86_l_370:
	/* 0x370: mov    DWORD PTR [rsp+0x20],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 137438953473ULL);
x86_l_378:
	/* 0x378: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_37d:
	/* 0x37d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_errmetrics_map)));
x86_l_384:
	/* 0x384: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_389:
	/* 0x389: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_38e:
	/* 0x38e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_390:
	/* 0x390: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_392:
	/* 0x392: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_394:
	/* 0x394: add    rsp,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 56ULL);
x86_l_398:
	/* 0x398: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_39a:
	/* 0x39a: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_39b:
	/* 0x39b: jmp    3e6 <tg_tp_cgrp_release+0x3e6> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_3a0:
	/* 0x3a0: cmp    rbx,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_3a4:
	/* 0x3a4: je     3c2 <tg_tp_cgrp_release+0x3c2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3a4, 0x3c2, x86_l_3c2);
x86_l_3a6:
	/* 0x3a6: cmp    rbx,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_3aa:
	/* 0x3aa: je     3da <tg_tp_cgrp_release+0x3da> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3aa, 0x3da, x86_l_3da);
x86_l_3ac:
	/* 0x3ac: cmp    rbx,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_3b0:
	/* 0x3b0: jne    3ca <tg_tp_cgrp_release+0x3ca> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3b0, 0x3ca, x86_l_3ca);
x86_l_3b2:
	/* 0x3b2: add    rax,0x580 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1408ULL);
x86_l_3b8:
	/* 0x3b8: jmp    3e0 <tg_tp_cgrp_release+0x3e0> */
	X86_SIM_X86_JMP(0x3b8, 0x3e0, x86_l_3e0);
x86_l_3ba:
	/* 0x3ba: add    rax,0x5a0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1440ULL);
x86_l_3c0:
	/* 0x3c0: jmp    3e0 <tg_tp_cgrp_release+0x3e0> */
	X86_SIM_X86_JMP(0x3c0, 0x3e0, x86_l_3e0);
x86_l_3c2:
	/* 0x3c2: add    rax,0x5a8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1448ULL);
x86_l_3c8:
	/* 0x3c8: jmp    3e0 <tg_tp_cgrp_release+0x3e0> */
	X86_SIM_X86_JMP(0x3c8, 0x3e0, x86_l_3e0);
x86_l_3ca:
	/* 0x3ca: add    rax,0x578 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1400ULL);
x86_l_3d0:
	/* 0x3d0: jmp    3e0 <tg_tp_cgrp_release+0x3e0> */
	X86_SIM_X86_JMP(0x3d0, 0x3e0, x86_l_3e0);
x86_l_3d2:
	/* 0x3d2: add    rax,0x598 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1432ULL);
x86_l_3d8:
	/* 0x3d8: jmp    3e0 <tg_tp_cgrp_release+0x3e0> */
	X86_SIM_X86_JMP(0x3d8, 0x3e0, x86_l_3e0);
x86_l_3da:
	/* 0x3da: add    rax,0x588 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1416ULL);
x86_l_3e0:
	/* 0x3e0: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_3e4:
	/* 0x3e4: jmp    392 <tg_tp_cgrp_release+0x392> */
	X86_SIM_X86_JMP(0x3e4, 0x392, x86_l_392);
x86_l_3e6:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
