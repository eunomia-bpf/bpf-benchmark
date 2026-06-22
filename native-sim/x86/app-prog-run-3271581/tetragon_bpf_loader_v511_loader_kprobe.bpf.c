extern char execve_map;
extern char ids_map;
extern char loader_heap;
extern char tcpmon_map;
extern char tg_conf_map;
extern char tg_rb_events;
extern char tg_stats_map;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_loader_v511_loader_kprobe_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0x5: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_7:
	/* 0x7: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_8:
	/* 0x8: sub    rsp,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 32ULL);
x86_l_c:
	/* 0xc: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_f:
	/* 0xf: mov    DWORD PTR [rsp+0x18],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 103079215104ULL);
x86_l_17:
	/* 0x17: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&loader_heap)));
x86_l_1e:
	/* 0x1e: lea    rcx,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_23:
	/* 0x23: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_28:
	/* 0x28: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_30:
	/* 0x30: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_35:
	/* 0x35: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_37:
	/* 0x37: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3a:
	/* 0x3a: je     2ff <loader_kprobe+0x2ff> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3a, 0x2ff, x86_l_2ff);
x86_l_40:
	/* 0x40: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_43:
	/* 0x43: mov    r12,QWORD PTR [r14+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_47:
	/* 0x47: mov    rax,QWORD PTR [rax+0x1040] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4160ULL);
x86_l_4e:
	/* 0x4e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_51:
	/* 0x51: je     5e <loader_kprobe+0x5e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x51, 0x5e, x86_l_5e);
x86_l_53:
	/* 0x53: cmp    rax,r12 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_56:
	/* 0x56: jne    2ff <loader_kprobe+0x2ff> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x56, 0x2ff, x86_l_2ff);
x86_l_5c:
	/* 0x5c: jmp    c2 <loader_kprobe+0xc2> */
	X86_SIM_X86_JMP(0x5c, 0xc2, x86_l_c2);
x86_l_5e:
	/* 0x5e: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_66:
	/* 0x66: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&ids_map)));
x86_l_6d:
	/* 0x6d: lea    rcx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_72:
	/* 0x72: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_77:
	/* 0x77: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_7f:
	/* 0x7f: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_84:
	/* 0x84: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_86:
	/* 0x86: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_89:
	/* 0x89: je     2ff <loader_kprobe+0x2ff> */
	X86_SIM_X86_JCC(X86_CC_E, 0x89, 0x2ff, x86_l_2ff);
x86_l_8f:
	/* 0x8f: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_92:
	/* 0x92: lea    rdx,[r12+0x3d8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 984ULL);
x86_l_9a:
	/* 0x9a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_9d:
	/* 0x9d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_a2:
	/* 0xa2: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_a7:
	/* 0xa7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ac:
	/* 0xac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ae:
	/* 0xae: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b2:
	/* 0xb2: cmp    QWORD PTR [r15],rax */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_REG, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b5:
	/* 0xb5: jne    2ff <loader_kprobe+0x2ff> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb5, 0x2ff, x86_l_2ff);
x86_l_bb:
	/* 0xbb: mov    QWORD PTR [rbx+0x1040],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4160ULL);
x86_l_c2:
	/* 0xc2: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_c7:
	/* 0xc7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c9:
	/* 0xc9: lea    rdx,[rax+0xad4] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2772ULL);
x86_l_d0:
	/* 0xd0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_d3:
	/* 0xd3: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_d8:
	/* 0xd8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_dd:
	/* 0xdd: mov    r12d,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R12, X86_WIDTH_32, 4ULL);
x86_l_e3:
	/* 0xe3: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_e8:
	/* 0xe8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ea:
	/* 0xea: mov    ebp,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ed:
	/* 0xed: mov    DWORD PTR [rsp],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f0:
	/* 0xf0: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_f7:
	/* 0xf7: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_fa:
	/* 0xfa: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ff:
	/* 0xff: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_101:
	/* 0x101: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_104:
	/* 0x104: je     2ff <loader_kprobe+0x2ff> */
	X86_SIM_X86_JCC(X86_CC_E, 0x104, 0x2ff, x86_l_2ff);
x86_l_10a:
	/* 0x10a: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10c:
	/* 0x10c: mov    DWORD PTR [rbx+0x10],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10f:
	/* 0x10f: mov    rax,QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_113:
	/* 0x113: mov    QWORD PTR [rbx+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_117:
	/* 0x117: mov    r15,QWORD PTR [r14+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_11b:
	/* 0x11b: lea    rdx,[r15+0x4c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_11f:
	/* 0x11f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_122:
	/* 0x122: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_127:
	/* 0x127: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_12c:
	/* 0x12c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12e:
	/* 0x12e: mov    eax,DWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_131:
	/* 0x131: mov    DWORD PTR [rbx+0x24],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_134:
	/* 0x134: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_136:
	/* 0x136: je     2ff <loader_kprobe+0x2ff> */
	X86_SIM_X86_JCC(X86_CC_E, 0x136, 0x2ff, x86_l_2ff);
x86_l_13c:
	/* 0x13c: lea    rdi,[rbx+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_140:
	/* 0x140: lea    rdx,[r15+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_144:
	/* 0x144: mov    ecx,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 20ULL);
x86_l_149:
	/* 0x149: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_14e:
	/* 0x14e: mov    esi,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 20ULL);
x86_l_153:
	/* 0x153: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_155:
	/* 0x155: add    r15,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_159:
	/* 0x159: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_15c:
	/* 0x15c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_161:
	/* 0x161: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_166:
	/* 0x166: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16b:
	/* 0x16b: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_16e:
	/* 0x16e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_170:
	/* 0x170: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_174:
	/* 0x174: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_177:
	/* 0x177: add    rdi,0x40 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 64ULL);
x86_l_17b:
	/* 0x17b: mov    ecx,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4096ULL);
x86_l_180:
	/* 0x180: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_185:
	/* 0x185: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_18a:
	/* 0x18a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18c:
	/* 0x18c: mov    DWORD PTR [rbx+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_18f:
	/* 0x18f: mov    DWORD PTR [rbx+0x20],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_192:
	/* 0x192: mov    DWORD PTR [rbx+0x4],0x1040 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179873344ULL);
x86_l_199:
	/* 0x199: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_19e:
	/* 0x19e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1a0:
	/* 0x1a0: mov    QWORD PTR [rbx+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a4:
	/* 0x1a4: mov    WORD PTR [rbx],0x1a */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_1a9:
	/* 0x1a9: mov    DWORD PTR [rsp+0x1c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 120259084288ULL);
x86_l_1b1:
	/* 0x1b1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_conf_map)));
x86_l_1b8:
	/* 0x1b8: lea    rsi,[rsp+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_1bd:
	/* 0x1bd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1c2:
	/* 0x1c2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c4:
	/* 0x1c4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1c7:
	/* 0x1c7: je     24e <loader_kprobe+0x24e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1c7, 0x24e, x86_l_24e);
x86_l_1cd:
	/* 0x1cd: cmp    BYTE PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_1d1:
	/* 0x1d1: je     24e <loader_kprobe+0x24e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1d1, 0x24e, x86_l_24e);
x86_l_1d3:
	/* 0x1d3: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tcpmon_map)));
x86_l_1da:
	/* 0x1da: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_1df:
	/* 0x1df: mov    edx,0x1040 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4160ULL);
x86_l_1e4:
	/* 0x1e4: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_1e9:
	/* 0x1e9: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_1ee:
	/* 0x1ee: mov    r8d,0x1040 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 4160ULL);
x86_l_1f4:
	/* 0x1f4: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_1f7:
	/* 0x1f7: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_1fa:
	/* 0x1fa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1fc:
	/* 0x1fc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ff:
	/* 0x1ff: jns    2ff <loader_kprobe+0x2ff> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x1ff, 0x2ff, x86_l_2ff);
x86_l_205:
	/* 0x205: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_208:
	/* 0x208: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_20f:
	/* 0x20f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_216:
	/* 0x216: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_219:
	/* 0x219: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_21e:
	/* 0x21e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_220:
	/* 0x220: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_223:
	/* 0x223: je     2ff <loader_kprobe+0x2ff> */
	X86_SIM_X86_JCC(X86_CC_E, 0x223, 0x2ff, x86_l_2ff);
x86_l_229:
	/* 0x229: cmp    rbx,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_22d:
	/* 0x22d: jg     2cb <loader_kprobe+0x2cb> */
	X86_SIM_X86_JCC(X86_CC_G, 0x22d, 0x2cb, x86_l_2cb);
x86_l_233:
	/* 0x233: cmp    rbx,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_237:
	/* 0x237: je     2e5 <loader_kprobe+0x2e5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x237, 0x2e5, x86_l_2e5);
x86_l_23d:
	/* 0x23d: cmp    rbx,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_241:
	/* 0x241: jne    2a3 <loader_kprobe+0x2a3> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x241, 0x2a3, x86_l_2a3);
x86_l_243:
	/* 0x243: add    rax,0x5d0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1488ULL);
x86_l_249:
	/* 0x249: jmp    2fb <loader_kprobe+0x2fb> */
	X86_SIM_X86_JMP(0x249, 0x2fb, x86_l_2fb);
x86_l_24e:
	/* 0x24e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_rb_events)));
x86_l_255:
	/* 0x255: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_257:
	/* 0x257: mov    edx,0x1040 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4160ULL);
x86_l_25c:
	/* 0x25c: mov    eax,0x82 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 130ULL);
x86_l_261:
	/* 0x261: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_264:
	/* 0x264: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_266:
	/* 0x266: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_268:
	/* 0x268: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_26b:
	/* 0x26b: jns    2ff <loader_kprobe+0x2ff> */
	X86_SIM_X86_JCC(X86_CC_NS, 0x26b, 0x2ff, x86_l_2ff);
x86_l_271:
	/* 0x271: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_274:
	/* 0x274: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_27b:
	/* 0x27b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_282:
	/* 0x282: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_285:
	/* 0x285: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_28a:
	/* 0x28a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_28c:
	/* 0x28c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_28f:
	/* 0x28f: je     2ff <loader_kprobe+0x2ff> */
	X86_SIM_X86_JCC(X86_CC_E, 0x28f, 0x2ff, x86_l_2ff);
x86_l_291:
	/* 0x291: cmp    rbx,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_295:
	/* 0x295: jg     2b1 <loader_kprobe+0x2b1> */
	X86_SIM_X86_JCC(X86_CC_G, 0x295, 0x2b1, x86_l_2b1);
x86_l_297:
	/* 0x297: cmp    rbx,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_29b:
	/* 0x29b: je     2e5 <loader_kprobe+0x2e5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x29b, 0x2e5, x86_l_2e5);
x86_l_29d:
	/* 0x29d: cmp    rbx,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_2a1:
	/* 0x2a1: je     243 <loader_kprobe+0x243> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2a1, 0x243, x86_l_243);
x86_l_2a3:
	/* 0x2a3: cmp    rbx,0xfffffffffffffff0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551600ULL);
x86_l_2a7:
	/* 0x2a7: jne    2dd <loader_kprobe+0x2dd> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2a7, 0x2dd, x86_l_2dd);
x86_l_2a9:
	/* 0x2a9: add    rax,0x5c8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1480ULL);
x86_l_2af:
	/* 0x2af: jmp    2fb <loader_kprobe+0x2fb> */
	X86_SIM_X86_JMP(0x2af, 0x2fb, x86_l_2fb);
x86_l_2b1:
	/* 0x2b1: cmp    rbx,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_2b5:
	/* 0x2b5: je     2ed <loader_kprobe+0x2ed> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2b5, 0x2ed, x86_l_2ed);
x86_l_2b7:
	/* 0x2b7: cmp    rbx,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_2bb:
	/* 0x2bb: je     2f5 <loader_kprobe+0x2f5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2bb, 0x2f5, x86_l_2f5);
x86_l_2bd:
	/* 0x2bd: cmp    rbx,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_2c1:
	/* 0x2c1: jne    2dd <loader_kprobe+0x2dd> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2c1, 0x2dd, x86_l_2dd);
x86_l_2c3:
	/* 0x2c3: add    rax,0x5b8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1464ULL);
x86_l_2c9:
	/* 0x2c9: jmp    2fb <loader_kprobe+0x2fb> */
	X86_SIM_X86_JMP(0x2c9, 0x2fb, x86_l_2fb);
x86_l_2cb:
	/* 0x2cb: cmp    rbx,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_2cf:
	/* 0x2cf: je     2ed <loader_kprobe+0x2ed> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2cf, 0x2ed, x86_l_2ed);
x86_l_2d1:
	/* 0x2d1: cmp    rbx,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_2d5:
	/* 0x2d5: je     2f5 <loader_kprobe+0x2f5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2d5, 0x2f5, x86_l_2f5);
x86_l_2d7:
	/* 0x2d7: cmp    rbx,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_2db:
	/* 0x2db: je     2c3 <loader_kprobe+0x2c3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2db, 0x2c3, x86_l_2c3);
x86_l_2dd:
	/* 0x2dd: add    rax,0x5b0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1456ULL);
x86_l_2e3:
	/* 0x2e3: jmp    2fb <loader_kprobe+0x2fb> */
	X86_SIM_X86_JMP(0x2e3, 0x2fb, x86_l_2fb);
x86_l_2e5:
	/* 0x2e5: add    rax,0x5d8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1496ULL);
x86_l_2eb:
	/* 0x2eb: jmp    2fb <loader_kprobe+0x2fb> */
	X86_SIM_X86_JMP(0x2eb, 0x2fb, x86_l_2fb);
x86_l_2ed:
	/* 0x2ed: add    rax,0x5e0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1504ULL);
x86_l_2f3:
	/* 0x2f3: jmp    2fb <loader_kprobe+0x2fb> */
	X86_SIM_X86_JMP(0x2f3, 0x2fb, x86_l_2fb);
x86_l_2f5:
	/* 0x2f5: add    rax,0x5c0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1472ULL);
x86_l_2fb:
	/* 0x2fb: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2ff:
	/* 0x2ff: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_301:
	/* 0x301: add    rsp,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_305:
	/* 0x305: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_306:
	/* 0x306: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_308:
	/* 0x308: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_30a:
	/* 0x30a: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_30c:
	/* 0x30c: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_30d:
	/* 0x30d: jmp    312 <loader_kprobe+0x312> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_312:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
