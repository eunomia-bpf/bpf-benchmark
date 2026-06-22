extern char birth;
extern char events;
extern char filter_dport;
extern char filter_sport;
extern char idents;
extern char target_dports;
extern char target_family;
extern char target_pid;
extern char target_sports;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int bcc_tcplife_inet_sock_set_state_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0xa: sub    rsp,0xb8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 184ULL);
x86_l_11:
	/* 0x11: mov    DWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_19:
	/* 0x19: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_22:
	/* 0x22: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_2b:
	/* 0x2b: mov    QWORD PTR [rsp+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_37:
	/* 0x37: mov    QWORD PTR [rsp+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_43:
	/* 0x43: mov    QWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_4f:
	/* 0x4f: mov    QWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_5b:
	/* 0x5b: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_64:
	/* 0x64: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_6d:
	/* 0x6d: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_76:
	/* 0x76: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_7f:
	/* 0x7f: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_88:
	/* 0x88: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_91:
	/* 0x91: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_94:
	/* 0x94: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_9d:
	/* 0x9d: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_a6:
	/* 0xa6: lea    rdx,[rdi+0x1e] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_aa:
	/* 0xaa: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_ad:
	/* 0xad: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_b2:
	/* 0xb2: call   b7 <inet_sock_set_state+0xb7> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_b7:
	/* 0xb7: cmp    WORD PTR [rsp],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_bc:
	/* 0xbc: jne    5d6 <inet_sock_set_state+0x5d6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xbc, 0x5d6, x86_l_5d6);
x86_l_c2:
	/* 0xc2: lea    rdx,[rbx+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_c6:
	/* 0xc6: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_c9:
	/* 0xc9: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_ce:
	/* 0xce: call   d3 <inet_sock_set_state+0xd3> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_d3:
	/* 0xd3: movzx  ebp,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_d7:
	/* 0xd7: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&target_family)));
x86_l_de:
	/* 0xde: cmp    WORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e2:
	/* 0xe2: je     ed <inet_sock_set_state+0xed> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe2, 0xed, x86_l_ed);
x86_l_e4:
	/* 0xe4: cmp    bp,WORD PTR [rax] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_e7:
	/* 0xe7: jne    5d6 <inet_sock_set_state+0x5d6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe7, 0x5d6, x86_l_5d6);
x86_l_ed:
	/* 0xed: lea    rdx,[rbx+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_f1:
	/* 0xf1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_f4:
	/* 0xf4: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_f9:
	/* 0xf9: call   fe <inet_sock_set_state+0xfe> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_fe:
	/* 0xfe: movzx  r13d,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_103:
	/* 0x103: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&filter_sport)));
x86_l_10a:
	/* 0x10a: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10d:
	/* 0x10d: je     1d7 <inet_sock_set_state+0x1d7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10d, 0x1d7, x86_l_1d7);
x86_l_113:
	/* 0x113: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_115:
	/* 0x115: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&target_sports)));
x86_l_11c:
	/* 0x11c: cmp    WORD PTR [rcx+rax*2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_121:
	/* 0x121: je     5d6 <inet_sock_set_state+0x5d6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x121, 0x5d6, x86_l_5d6);
x86_l_127:
	/* 0x127: cmp    r13w,WORD PTR [rcx+rax*2] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RCX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_RAX, 1, X86_WIDTH_16), 0ULL);
x86_l_12c:
	/* 0x12c: je     1d7 <inet_sock_set_state+0x1d7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12c, 0x1d7, x86_l_1d7);
x86_l_132:
	/* 0x132: cmp    WORD PTR [rcx+rax*2+0x2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 1), 8589934592ULL);
x86_l_138:
	/* 0x138: je     5d6 <inet_sock_set_state+0x5d6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x138, 0x5d6, x86_l_5d6);
x86_l_13e:
	/* 0x13e: cmp    r13w,WORD PTR [rcx+rax*2+0x2] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RCX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_RAX, 1, X86_WIDTH_16), 2ULL);
x86_l_144:
	/* 0x144: je     1d7 <inet_sock_set_state+0x1d7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x144, 0x1d7, x86_l_1d7);
x86_l_14a:
	/* 0x14a: cmp    WORD PTR [rcx+rax*2+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 1), 17179869184ULL);
x86_l_150:
	/* 0x150: je     5d6 <inet_sock_set_state+0x5d6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x150, 0x5d6, x86_l_5d6);
x86_l_156:
	/* 0x156: cmp    r13w,WORD PTR [rcx+rax*2+0x4] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RCX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_RAX, 1, X86_WIDTH_16), 4ULL);
x86_l_15c:
	/* 0x15c: je     1d7 <inet_sock_set_state+0x1d7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x15c, 0x1d7, x86_l_1d7);
x86_l_15e:
	/* 0x15e: cmp    WORD PTR [rcx+rax*2+0x6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 1), 25769803776ULL);
x86_l_164:
	/* 0x164: je     5d6 <inet_sock_set_state+0x5d6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x164, 0x5d6, x86_l_5d6);
x86_l_16a:
	/* 0x16a: cmp    r13w,WORD PTR [rcx+rax*2+0x6] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RCX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_RAX, 1, X86_WIDTH_16), 6ULL);
x86_l_170:
	/* 0x170: je     1d7 <inet_sock_set_state+0x1d7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x170, 0x1d7, x86_l_1d7);
x86_l_172:
	/* 0x172: cmp    WORD PTR [rcx+rax*2+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 1), 34359738368ULL);
x86_l_178:
	/* 0x178: je     5d6 <inet_sock_set_state+0x5d6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x178, 0x5d6, x86_l_5d6);
x86_l_17e:
	/* 0x17e: cmp    r13w,WORD PTR [rcx+rax*2+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RCX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_RAX, 1, X86_WIDTH_16), 8ULL);
x86_l_184:
	/* 0x184: je     1d7 <inet_sock_set_state+0x1d7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x184, 0x1d7, x86_l_1d7);
x86_l_186:
	/* 0x186: cmp    WORD PTR [rcx+rax*2+0xa],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 1), 42949672960ULL);
x86_l_18c:
	/* 0x18c: je     5d6 <inet_sock_set_state+0x5d6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x18c, 0x5d6, x86_l_5d6);
x86_l_192:
	/* 0x192: cmp    r13w,WORD PTR [rcx+rax*2+0xa] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RCX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_RAX, 1, X86_WIDTH_16), 10ULL);
x86_l_198:
	/* 0x198: je     1d7 <inet_sock_set_state+0x1d7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x198, 0x1d7, x86_l_1d7);
x86_l_19a:
	/* 0x19a: cmp    WORD PTR [rcx+rax*2+0xc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 1), 51539607552ULL);
x86_l_1a0:
	/* 0x1a0: je     5d6 <inet_sock_set_state+0x5d6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a0, 0x5d6, x86_l_5d6);
x86_l_1a6:
	/* 0x1a6: cmp    r13w,WORD PTR [rcx+rax*2+0xc] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RCX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_RAX, 1, X86_WIDTH_16), 12ULL);
x86_l_1ac:
	/* 0x1ac: je     1d7 <inet_sock_set_state+0x1d7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1ac, 0x1d7, x86_l_1d7);
x86_l_1ae:
	/* 0x1ae: cmp    WORD PTR [rcx+rax*2+0xe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 1), 60129542144ULL);
x86_l_1b4:
	/* 0x1b4: je     5d6 <inet_sock_set_state+0x5d6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1b4, 0x5d6, x86_l_5d6);
x86_l_1ba:
	/* 0x1ba: cmp    r13w,WORD PTR [rcx+rax*2+0xe] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RCX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_RAX, 1, X86_WIDTH_16), 14ULL);
x86_l_1c0:
	/* 0x1c0: je     1d7 <inet_sock_set_state+0x1d7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1c0, 0x1d7, x86_l_1d7);
x86_l_1c2:
	/* 0x1c2: add    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1c6:
	/* 0x1c6: cmp    rax,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 1024ULL);
x86_l_1cc:
	/* 0x1cc: jne    11c <inet_sock_set_state+0x11c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1cc, 0x11c, x86_l_11c);
x86_l_1d2:
	/* 0x1d2: jmp    5d6 <inet_sock_set_state+0x5d6> */
	X86_SIM_X86_JMP(0x1d2, 0x5d6, x86_l_5d6);
x86_l_1d7:
	/* 0x1d7: lea    rdx,[rbx+0x1a] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_1db:
	/* 0x1db: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1de:
	/* 0x1de: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1e3:
	/* 0x1e3: call   1e8 <inet_sock_set_state+0x1e8> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_1e8:
	/* 0x1e8: movzx  r15d,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1ed:
	/* 0x1ed: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&filter_dport)));
x86_l_1f4:
	/* 0x1f4: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f7:
	/* 0x1f7: je     2c1 <inet_sock_set_state+0x2c1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1f7, 0x2c1, x86_l_2c1);
x86_l_1fd:
	/* 0x1fd: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ff:
	/* 0x1ff: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&target_dports)));
x86_l_206:
	/* 0x206: cmp    WORD PTR [rcx+rax*2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_20b:
	/* 0x20b: je     5d6 <inet_sock_set_state+0x5d6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x20b, 0x5d6, x86_l_5d6);
x86_l_211:
	/* 0x211: cmp    r15w,WORD PTR [rcx+rax*2] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RCX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_RAX, 1, X86_WIDTH_16), 0ULL);
x86_l_216:
	/* 0x216: je     2c1 <inet_sock_set_state+0x2c1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x216, 0x2c1, x86_l_2c1);
x86_l_21c:
	/* 0x21c: cmp    WORD PTR [rcx+rax*2+0x2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 1), 8589934592ULL);
x86_l_222:
	/* 0x222: je     5d6 <inet_sock_set_state+0x5d6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x222, 0x5d6, x86_l_5d6);
x86_l_228:
	/* 0x228: cmp    r15w,WORD PTR [rcx+rax*2+0x2] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RCX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_RAX, 1, X86_WIDTH_16), 2ULL);
x86_l_22e:
	/* 0x22e: je     2c1 <inet_sock_set_state+0x2c1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x22e, 0x2c1, x86_l_2c1);
x86_l_234:
	/* 0x234: cmp    WORD PTR [rcx+rax*2+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 1), 17179869184ULL);
x86_l_23a:
	/* 0x23a: je     5d6 <inet_sock_set_state+0x5d6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x23a, 0x5d6, x86_l_5d6);
x86_l_240:
	/* 0x240: cmp    r15w,WORD PTR [rcx+rax*2+0x4] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RCX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_RAX, 1, X86_WIDTH_16), 4ULL);
x86_l_246:
	/* 0x246: je     2c1 <inet_sock_set_state+0x2c1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x246, 0x2c1, x86_l_2c1);
x86_l_248:
	/* 0x248: cmp    WORD PTR [rcx+rax*2+0x6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 1), 25769803776ULL);
x86_l_24e:
	/* 0x24e: je     5d6 <inet_sock_set_state+0x5d6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x24e, 0x5d6, x86_l_5d6);
x86_l_254:
	/* 0x254: cmp    r15w,WORD PTR [rcx+rax*2+0x6] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RCX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_RAX, 1, X86_WIDTH_16), 6ULL);
x86_l_25a:
	/* 0x25a: je     2c1 <inet_sock_set_state+0x2c1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x25a, 0x2c1, x86_l_2c1);
x86_l_25c:
	/* 0x25c: cmp    WORD PTR [rcx+rax*2+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 1), 34359738368ULL);
x86_l_262:
	/* 0x262: je     5d6 <inet_sock_set_state+0x5d6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x262, 0x5d6, x86_l_5d6);
x86_l_268:
	/* 0x268: cmp    r15w,WORD PTR [rcx+rax*2+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RCX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_RAX, 1, X86_WIDTH_16), 8ULL);
x86_l_26e:
	/* 0x26e: je     2c1 <inet_sock_set_state+0x2c1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x26e, 0x2c1, x86_l_2c1);
x86_l_270:
	/* 0x270: cmp    WORD PTR [rcx+rax*2+0xa],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 1), 42949672960ULL);
x86_l_276:
	/* 0x276: je     5d6 <inet_sock_set_state+0x5d6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x276, 0x5d6, x86_l_5d6);
x86_l_27c:
	/* 0x27c: cmp    r15w,WORD PTR [rcx+rax*2+0xa] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RCX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_RAX, 1, X86_WIDTH_16), 10ULL);
x86_l_282:
	/* 0x282: je     2c1 <inet_sock_set_state+0x2c1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x282, 0x2c1, x86_l_2c1);
x86_l_284:
	/* 0x284: cmp    WORD PTR [rcx+rax*2+0xc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 1), 51539607552ULL);
x86_l_28a:
	/* 0x28a: je     5d6 <inet_sock_set_state+0x5d6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x28a, 0x5d6, x86_l_5d6);
x86_l_290:
	/* 0x290: cmp    r15w,WORD PTR [rcx+rax*2+0xc] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RCX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_RAX, 1, X86_WIDTH_16), 12ULL);
x86_l_296:
	/* 0x296: je     2c1 <inet_sock_set_state+0x2c1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x296, 0x2c1, x86_l_2c1);
x86_l_298:
	/* 0x298: cmp    WORD PTR [rcx+rax*2+0xe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 1), 60129542144ULL);
x86_l_29e:
	/* 0x29e: je     5d6 <inet_sock_set_state+0x5d6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x29e, 0x5d6, x86_l_5d6);
x86_l_2a4:
	/* 0x2a4: cmp    r15w,WORD PTR [rcx+rax*2+0xe] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RCX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_RAX, 1, X86_WIDTH_16), 14ULL);
x86_l_2aa:
	/* 0x2aa: je     2c1 <inet_sock_set_state+0x2c1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2aa, 0x2c1, x86_l_2c1);
x86_l_2ac:
	/* 0x2ac: add    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2b0:
	/* 0x2b0: cmp    rax,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 1024ULL);
x86_l_2b6:
	/* 0x2b6: jne    206 <inet_sock_set_state+0x206> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2b6, 0x206, x86_l_206);
x86_l_2bc:
	/* 0x2bc: jmp    5d6 <inet_sock_set_state+0x5d6> */
	X86_SIM_X86_JMP(0x2bc, 0x5d6, x86_l_5d6);
x86_l_2c1:
	/* 0x2c1: lea    rdx,[rbx+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2c5:
	/* 0x2c5: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2ca:
	/* 0x2ca: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2cf:
	/* 0x2cf: call   2d4 <inet_sock_set_state+0x2d4> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_2d4:
	/* 0x2d4: lea    r14,[rbx+0x14] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2d8:
	/* 0x2d8: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2db:
	/* 0x2db: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2e0:
	/* 0x2e0: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_2e3:
	/* 0x2e3: call   2e8 <inet_sock_set_state+0x2e8> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_2e8:
	/* 0x2e8: cmp    DWORD PTR [rsp],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 3ULL);
x86_l_2ec:
	/* 0x2ec: jg     310 <inet_sock_set_state+0x310> */
	X86_SIM_X86_JCC(X86_CC_G, 0x2ec, 0x310, x86_l_310);
x86_l_2ee:
	/* 0x2ee: call   2f3 <inet_sock_set_state+0x2f3> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_ktime_get_ns);
x86_l_2f3:
	/* 0x2f3: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2f8:
	/* 0x2f8: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&birth)));
x86_l_2ff:
	/* 0x2ff: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_304:
	/* 0x304: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_309:
	/* 0x309: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_30b:
	/* 0x30b: call   310 <inet_sock_set_state+0x310> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_map_update_elem);
x86_l_310:
	/* 0x310: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_313:
	/* 0x313: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_318:
	/* 0x318: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_31b:
	/* 0x31b: call   320 <inet_sock_set_state+0x320> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_320:
	/* 0x320: cmp    DWORD PTR [rsp],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_324:
	/* 0x324: je     33c <inet_sock_set_state+0x33c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x324, 0x33c, x86_l_33c);
x86_l_326:
	/* 0x326: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_329:
	/* 0x329: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_32e:
	/* 0x32e: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_331:
	/* 0x331: call   336 <inet_sock_set_state+0x336> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_336:
	/* 0x336: cmp    DWORD PTR [rsp],0x9 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 9ULL);
x86_l_33a:
	/* 0x33a: jne    386 <inet_sock_set_state+0x386> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x33a, 0x386, x86_l_386);
x86_l_33c:
	/* 0x33c: call   341 <inet_sock_set_state+0x341> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_get_current_pid_tgid);
x86_l_341:
	/* 0x341: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_345:
	/* 0x345: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&target_pid)));
x86_l_34c:
	/* 0x34c: cmp    DWORD PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_34f:
	/* 0x34f: je     35b <inet_sock_set_state+0x35b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x34f, 0x35b, x86_l_35b);
x86_l_351:
	/* 0x351: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_353:
	/* 0x353: cmp    ecx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_355:
	/* 0x355: jne    5d6 <inet_sock_set_state+0x5d6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x355, 0x5d6, x86_l_5d6);
x86_l_35b:
	/* 0x35b: mov    DWORD PTR [rsp+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_35f:
	/* 0x35f: lea    rdi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_364:
	/* 0x364: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_369:
	/* 0x369: call   36e <inet_sock_set_state+0x36e> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_get_current_comm);
x86_l_36e:
	/* 0x36e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&idents)));
x86_l_375:
	/* 0x375: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_37a:
	/* 0x37a: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_37f:
	/* 0x37f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_381:
	/* 0x381: call   386 <inet_sock_set_state+0x386> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_map_update_elem);
x86_l_386:
	/* 0x386: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_389:
	/* 0x389: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_38e:
	/* 0x38e: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_391:
	/* 0x391: call   396 <inet_sock_set_state+0x396> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_396:
	/* 0x396: cmp    DWORD PTR [rsp],0x7 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_39a:
	/* 0x39a: jne    5d6 <inet_sock_set_state+0x5d6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x39a, 0x5d6, x86_l_5d6);
x86_l_3a0:
	/* 0x3a0: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&birth)));
x86_l_3a7:
	/* 0x3a7: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3ac:
	/* 0x3ac: call   3b1 <inet_sock_set_state+0x3b1> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_3b1:
	/* 0x3b1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3b4:
	/* 0x3b4: je     5c5 <inet_sock_set_state+0x5c5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3b4, 0x5c5, x86_l_5c5);
x86_l_3ba:
	/* 0x3ba: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_3bd:
	/* 0x3bd: call   3c2 <inet_sock_set_state+0x3c2> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_ktime_get_ns);
x86_l_3c2:
	/* 0x3c2: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3c7:
	/* 0x3c7: sub    rax,QWORD PTR [r14] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 0ULL);
x86_l_3ca:
	/* 0x3ca: shr    rax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 3ULL);
x86_l_3ce:
	/* 0x3ce: movabs rcx,0x20c49ba5e353f7cf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2361183241434822607ULL);
x86_l_3d8:
	/* 0x3d8: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_3db:
	/* 0x3db: mulx   r12,r12,rcx */
	X86_SIM_L_EXEC_MULX(X86_R12, X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_3e0:
	/* 0x3e0: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&idents)));
x86_l_3e7:
	/* 0x3e7: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3ec:
	/* 0x3ec: call   3f1 <inet_sock_set_state+0x3f1> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_3f1:
	/* 0x3f1: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_3f4:
	/* 0x3f4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3f7:
	/* 0x3f7: je     3fe <inet_sock_set_state+0x3fe> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3f7, 0x3fe, x86_l_3fe);
x86_l_3f9:
	/* 0x3f9: mov    eax,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3fc:
	/* 0x3fc: jmp    407 <inet_sock_set_state+0x407> */
	X86_SIM_X86_JMP(0x3fc, 0x407, x86_l_407);
x86_l_3fe:
	/* 0x3fe: call   403 <inet_sock_set_state+0x403> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_get_current_pid_tgid);
x86_l_403:
	/* 0x403: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_407:
	/* 0x407: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&target_pid)));
x86_l_40e:
	/* 0x40e: cmp    DWORD PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_411:
	/* 0x411: je     41b <inet_sock_set_state+0x41b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x411, 0x41b, x86_l_41b);
x86_l_413:
	/* 0x413: cmp    eax,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_415:
	/* 0x415: jne    5b4 <inet_sock_set_state+0x5b4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x415, 0x5b4, x86_l_5b4);
x86_l_41b:
	/* 0x41b: shr    r12,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_SHR, 4ULL);
x86_l_41f:
	/* 0x41f: mov    QWORD PTR [rsp+0xb0],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_427:
	/* 0x427: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_42c:
	/* 0x42c: lea    rdx,[r12+0x6f8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1784ULL);
x86_l_434:
	/* 0x434: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_437:
	/* 0x437: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_43c:
	/* 0x43c: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_444:
	/* 0x444: call   449 <inet_sock_set_state+0x449> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_449:
	/* 0x449: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_44d:
	/* 0x44d: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_455:
	/* 0x455: add    r12,0x730 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 1840ULL);
x86_l_45c:
	/* 0x45c: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_461:
	/* 0x461: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_466:
	/* 0x466: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_469:
	/* 0x469: call   46e <inet_sock_set_state+0x46e> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_46e:
	/* 0x46e: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_473:
	/* 0x473: shr    rdx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 3ULL);
x86_l_477:
	/* 0x477: movabs rax,0x20c49ba5e353f7cf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2361183241434822607ULL);
x86_l_481:
	/* 0x481: mulx   rax,rax,rax */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_486:
	/* 0x486: shr    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 4ULL);
x86_l_48a:
	/* 0x48a: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_48f:
	/* 0x48f: mov    rax,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_497:
	/* 0x497: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_49c:
	/* 0x49c: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_4a4:
	/* 0x4a4: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_4a9:
	/* 0x4a9: mov    rax,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_4b1:
	/* 0x4b1: mov    DWORD PTR [rsp+0x80],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_4b8:
	/* 0x4b8: mov    WORD PTR [rsp+0x84],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_4c1:
	/* 0x4c1: mov    WORD PTR [rsp+0x86],r15w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 134ULL);
x86_l_4ca:
	/* 0x4ca: mov    WORD PTR [rsp+0x88],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_4d2:
	/* 0x4d2: lea    rdi,[rsp+0x8a] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138ULL);
x86_l_4da:
	/* 0x4da: test   r14,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64);
x86_l_4dd:
	/* 0x4dd: je     4f2 <inet_sock_set_state+0x4f2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4dd, 0x4f2, x86_l_4f2);
x86_l_4df:
	/* 0x4df: add    r14,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_4e3:
	/* 0x4e3: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_4e8:
	/* 0x4e8: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_4eb:
	/* 0x4eb: call   4f0 <inet_sock_set_state+0x4f0> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_4f0:
	/* 0x4f0: jmp    4fc <inet_sock_set_state+0x4fc> */
	X86_SIM_X86_JMP(0x4f0, 0x4fc, x86_l_4fc);
x86_l_4f2:
	/* 0x4f2: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_4f7:
	/* 0x4f7: call   4fc <inet_sock_set_state+0x4fc> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_get_current_comm);
x86_l_4fc:
	/* 0x4fc: lea    r14,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_501:
	/* 0x501: cmp    bp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_16, 2ULL);
x86_l_505:
	/* 0x505: jne    54b <inet_sock_set_state+0x54b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x505, 0x54b, x86_l_54b);
x86_l_507:
	/* 0x507: lea    rdx,[rbx+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_50b:
	/* 0x50b: mov    r15,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSP, X86_WIDTH_64);
x86_l_50e:
	/* 0x50e: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_511:
	/* 0x511: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_516:
	/* 0x516: call   51b <inet_sock_set_state+0x51b> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_51b:
	/* 0x51b: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_520:
	/* 0x520: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_525:
	/* 0x525: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_528:
	/* 0x528: call   52d <inet_sock_set_state+0x52d> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_52d:
	/* 0x52d: lea    rdx,[rbx+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_531:
	/* 0x531: mov    r15,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSP, X86_WIDTH_64);
x86_l_534:
	/* 0x534: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_537:
	/* 0x537: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_53c:
	/* 0x53c: call   541 <inet_sock_set_state+0x541> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_541:
	/* 0x541: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_544:
	/* 0x544: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_549:
	/* 0x549: jmp    58d <inet_sock_set_state+0x58d> */
	X86_SIM_X86_JMP(0x549, 0x58d, x86_l_58d);
x86_l_54b:
	/* 0x54b: lea    rdx,[rbx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_54f:
	/* 0x54f: mov    r15,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSP, X86_WIDTH_64);
x86_l_552:
	/* 0x552: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_555:
	/* 0x555: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_55a:
	/* 0x55a: call   55f <inet_sock_set_state+0x55f> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_55f:
	/* 0x55f: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_564:
	/* 0x564: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_569:
	/* 0x569: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_56c:
	/* 0x56c: call   571 <inet_sock_set_state+0x571> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_571:
	/* 0x571: lea    rdx,[rbx+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_575:
	/* 0x575: mov    r15,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSP, X86_WIDTH_64);
x86_l_578:
	/* 0x578: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_57b:
	/* 0x57b: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_580:
	/* 0x580: call   585 <inet_sock_set_state+0x585> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_585:
	/* 0x585: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_588:
	/* 0x588: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_58d:
	/* 0x58d: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_590:
	/* 0x590: call   595 <inet_sock_set_state+0x595> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_595:
	/* 0x595: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&events)));
x86_l_59c:
	/* 0x59c: lea    rcx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_5a1:
	/* 0x5a1: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_5a6:
	/* 0x5a6: mov    r8d,0x60 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 96ULL);
x86_l_5ac:
	/* 0x5ac: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_5af:
	/* 0x5af: call   5b4 <inet_sock_set_state+0x5b4> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_perf_event_output);
x86_l_5b4:
	/* 0x5b4: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&birth)));
x86_l_5bb:
	/* 0x5bb: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5c0:
	/* 0x5c0: call   5c5 <inet_sock_set_state+0x5c5> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_map_delete_elem);
x86_l_5c5:
	/* 0x5c5: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&idents)));
x86_l_5cc:
	/* 0x5cc: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5d1:
	/* 0x5d1: call   5d6 <inet_sock_set_state+0x5d6> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_map_delete_elem);
x86_l_5d6:
	/* 0x5d6: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5d8:
	/* 0x5d8: add    rsp,0xb8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 184ULL);
x86_l_5df:
	/* 0x5df: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_5e0:
	/* 0x5e0: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_5e2:
	/* 0x5e2: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_5e4:
	/* 0x5e4: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_5e6:
	/* 0x5e6: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_5e8:
	/* 0x5e8: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_5e9:
	/* 0x5e9: jmp    5ee <inet_sock_set_state+0x5ee> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_5ee:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
