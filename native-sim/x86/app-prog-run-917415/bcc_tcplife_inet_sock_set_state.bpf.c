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
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0xb8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 184ULL);
x86_l_a:
	/* 0xa: mov    DWORD PTR [rsp+0x38],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 240518168576ULL);
x86_l_12:
	/* 0x12: mov    QWORD PTR [rsp+0x30],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 206158430208ULL);
x86_l_1b:
	/* 0x1b: mov    QWORD PTR [rsp+0x28],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_24:
	/* 0x24: mov    QWORD PTR [rsp+0x98],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 652835028992ULL);
x86_l_30:
	/* 0x30: mov    QWORD PTR [rsp+0x90],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 618475290624ULL);
x86_l_3c:
	/* 0x3c: mov    QWORD PTR [rsp+0x88],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584115552256ULL);
x86_l_48:
	/* 0x48: mov    QWORD PTR [rsp+0x80],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 549755813888ULL);
x86_l_54:
	/* 0x54: mov    QWORD PTR [rsp+0x78],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 515396075520ULL);
x86_l_5d:
	/* 0x5d: mov    QWORD PTR [rsp+0x70],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 481036337152ULL);
x86_l_66:
	/* 0x66: mov    QWORD PTR [rsp+0x68],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 446676598784ULL);
x86_l_6f:
	/* 0x6f: mov    QWORD PTR [rsp+0x60],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 412316860416ULL);
x86_l_78:
	/* 0x78: mov    QWORD PTR [rsp+0x58],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 377957122048ULL);
x86_l_81:
	/* 0x81: mov    QWORD PTR [rsp+0x50],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 343597383680ULL);
x86_l_8a:
	/* 0x8a: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_8d:
	/* 0x8d: mov    QWORD PTR [rsp+0x48],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 309237645312ULL);
x86_l_96:
	/* 0x96: mov    QWORD PTR [rsp+0x40],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 274877906944ULL);
x86_l_9f:
	/* 0x9f: lea    rdx,[rdi+0x1e] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_a3:
	/* 0xa3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_a6:
	/* 0xa6: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_ab:
	/* 0xab: call   b0 <inet_sock_set_state+0xb0> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_b0:
	/* 0xb0: cmp    WORD PTR [rsp],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_b5:
	/* 0xb5: jne    5cf <inet_sock_set_state+0x5cf> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb5, 0x5cf, x86_l_5cf);
x86_l_bb:
	/* 0xbb: lea    rdx,[rbx+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_bf:
	/* 0xbf: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_c2:
	/* 0xc2: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_c7:
	/* 0xc7: call   cc <inet_sock_set_state+0xcc> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_cc:
	/* 0xcc: movzx  ebp,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_d0:
	/* 0xd0: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&target_family)));
x86_l_d7:
	/* 0xd7: cmp    WORD PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_db:
	/* 0xdb: je     e6 <inet_sock_set_state+0xe6> */
	X86_SIM_X86_JCC(X86_CC_E, 0xdb, 0xe6, x86_l_e6);
x86_l_dd:
	/* 0xdd: cmp    bp,WORD PTR [rax] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_e0:
	/* 0xe0: jne    5cf <inet_sock_set_state+0x5cf> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe0, 0x5cf, x86_l_5cf);
x86_l_e6:
	/* 0xe6: lea    rdx,[rbx+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ea:
	/* 0xea: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_ed:
	/* 0xed: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_f2:
	/* 0xf2: call   f7 <inet_sock_set_state+0xf7> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_f7:
	/* 0xf7: movzx  r13d,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_fc:
	/* 0xfc: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&filter_sport)));
x86_l_103:
	/* 0x103: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_106:
	/* 0x106: je     1d0 <inet_sock_set_state+0x1d0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x106, 0x1d0, x86_l_1d0);
x86_l_10c:
	/* 0x10c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10e:
	/* 0x10e: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&target_sports)));
x86_l_115:
	/* 0x115: cmp    WORD PTR [rcx+rax*2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_11a:
	/* 0x11a: je     5cf <inet_sock_set_state+0x5cf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11a, 0x5cf, x86_l_5cf);
x86_l_120:
	/* 0x120: cmp    r13w,WORD PTR [rcx+rax*2] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RCX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_RAX, 1, X86_WIDTH_16), 0ULL);
x86_l_125:
	/* 0x125: je     1d0 <inet_sock_set_state+0x1d0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x125, 0x1d0, x86_l_1d0);
x86_l_12b:
	/* 0x12b: cmp    WORD PTR [rcx+rax*2+0x2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 1), 8589934592ULL);
x86_l_131:
	/* 0x131: je     5cf <inet_sock_set_state+0x5cf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x131, 0x5cf, x86_l_5cf);
x86_l_137:
	/* 0x137: cmp    r13w,WORD PTR [rcx+rax*2+0x2] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RCX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_RAX, 1, X86_WIDTH_16), 2ULL);
x86_l_13d:
	/* 0x13d: je     1d0 <inet_sock_set_state+0x1d0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13d, 0x1d0, x86_l_1d0);
x86_l_143:
	/* 0x143: cmp    WORD PTR [rcx+rax*2+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 1), 17179869184ULL);
x86_l_149:
	/* 0x149: je     5cf <inet_sock_set_state+0x5cf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x149, 0x5cf, x86_l_5cf);
x86_l_14f:
	/* 0x14f: cmp    r13w,WORD PTR [rcx+rax*2+0x4] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RCX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_RAX, 1, X86_WIDTH_16), 4ULL);
x86_l_155:
	/* 0x155: je     1d0 <inet_sock_set_state+0x1d0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x155, 0x1d0, x86_l_1d0);
x86_l_157:
	/* 0x157: cmp    WORD PTR [rcx+rax*2+0x6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 1), 25769803776ULL);
x86_l_15d:
	/* 0x15d: je     5cf <inet_sock_set_state+0x5cf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x15d, 0x5cf, x86_l_5cf);
x86_l_163:
	/* 0x163: cmp    r13w,WORD PTR [rcx+rax*2+0x6] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RCX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_RAX, 1, X86_WIDTH_16), 6ULL);
x86_l_169:
	/* 0x169: je     1d0 <inet_sock_set_state+0x1d0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x169, 0x1d0, x86_l_1d0);
x86_l_16b:
	/* 0x16b: cmp    WORD PTR [rcx+rax*2+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 1), 34359738368ULL);
x86_l_171:
	/* 0x171: je     5cf <inet_sock_set_state+0x5cf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x171, 0x5cf, x86_l_5cf);
x86_l_177:
	/* 0x177: cmp    r13w,WORD PTR [rcx+rax*2+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RCX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_RAX, 1, X86_WIDTH_16), 8ULL);
x86_l_17d:
	/* 0x17d: je     1d0 <inet_sock_set_state+0x1d0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x17d, 0x1d0, x86_l_1d0);
x86_l_17f:
	/* 0x17f: cmp    WORD PTR [rcx+rax*2+0xa],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 1), 42949672960ULL);
x86_l_185:
	/* 0x185: je     5cf <inet_sock_set_state+0x5cf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x185, 0x5cf, x86_l_5cf);
x86_l_18b:
	/* 0x18b: cmp    r13w,WORD PTR [rcx+rax*2+0xa] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RCX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_RAX, 1, X86_WIDTH_16), 10ULL);
x86_l_191:
	/* 0x191: je     1d0 <inet_sock_set_state+0x1d0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x191, 0x1d0, x86_l_1d0);
x86_l_193:
	/* 0x193: cmp    WORD PTR [rcx+rax*2+0xc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 1), 51539607552ULL);
x86_l_199:
	/* 0x199: je     5cf <inet_sock_set_state+0x5cf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x199, 0x5cf, x86_l_5cf);
x86_l_19f:
	/* 0x19f: cmp    r13w,WORD PTR [rcx+rax*2+0xc] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RCX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_RAX, 1, X86_WIDTH_16), 12ULL);
x86_l_1a5:
	/* 0x1a5: je     1d0 <inet_sock_set_state+0x1d0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a5, 0x1d0, x86_l_1d0);
x86_l_1a7:
	/* 0x1a7: cmp    WORD PTR [rcx+rax*2+0xe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 1), 60129542144ULL);
x86_l_1ad:
	/* 0x1ad: je     5cf <inet_sock_set_state+0x5cf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1ad, 0x5cf, x86_l_5cf);
x86_l_1b3:
	/* 0x1b3: cmp    r13w,WORD PTR [rcx+rax*2+0xe] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R13, X86_RCX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_RAX, 1, X86_WIDTH_16), 14ULL);
x86_l_1b9:
	/* 0x1b9: je     1d0 <inet_sock_set_state+0x1d0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1b9, 0x1d0, x86_l_1d0);
x86_l_1bb:
	/* 0x1bb: add    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_1bf:
	/* 0x1bf: cmp    rax,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 1024ULL);
x86_l_1c5:
	/* 0x1c5: jne    115 <inet_sock_set_state+0x115> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1c5, 0x115, x86_l_115);
x86_l_1cb:
	/* 0x1cb: jmp    5cf <inet_sock_set_state+0x5cf> */
	X86_SIM_X86_JMP(0x1cb, 0x5cf, x86_l_5cf);
x86_l_1d0:
	/* 0x1d0: lea    rdx,[rbx+0x1a] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_1d4:
	/* 0x1d4: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1d7:
	/* 0x1d7: mov    esi,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 2ULL);
x86_l_1dc:
	/* 0x1dc: call   1e1 <inet_sock_set_state+0x1e1> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_1e1:
	/* 0x1e1: movzx  r15d,WORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_1e6:
	/* 0x1e6: mov    rax,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RAX, (void *)(long)(((__u64)(long)&filter_dport)));
x86_l_1ed:
	/* 0x1ed: cmp    BYTE PTR [rax],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f0:
	/* 0x1f0: je     2ba <inet_sock_set_state+0x2ba> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1f0, 0x2ba, x86_l_2ba);
x86_l_1f6:
	/* 0x1f6: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1f8:
	/* 0x1f8: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&target_dports)));
x86_l_1ff:
	/* 0x1ff: cmp    WORD PTR [rcx+rax*2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 1), 0ULL);
x86_l_204:
	/* 0x204: je     5cf <inet_sock_set_state+0x5cf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x204, 0x5cf, x86_l_5cf);
x86_l_20a:
	/* 0x20a: cmp    r15w,WORD PTR [rcx+rax*2] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RCX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_RAX, 1, X86_WIDTH_16), 0ULL);
x86_l_20f:
	/* 0x20f: je     2ba <inet_sock_set_state+0x2ba> */
	X86_SIM_X86_JCC(X86_CC_E, 0x20f, 0x2ba, x86_l_2ba);
x86_l_215:
	/* 0x215: cmp    WORD PTR [rcx+rax*2+0x2],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 1), 8589934592ULL);
x86_l_21b:
	/* 0x21b: je     5cf <inet_sock_set_state+0x5cf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x21b, 0x5cf, x86_l_5cf);
x86_l_221:
	/* 0x221: cmp    r15w,WORD PTR [rcx+rax*2+0x2] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RCX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_RAX, 1, X86_WIDTH_16), 2ULL);
x86_l_227:
	/* 0x227: je     2ba <inet_sock_set_state+0x2ba> */
	X86_SIM_X86_JCC(X86_CC_E, 0x227, 0x2ba, x86_l_2ba);
x86_l_22d:
	/* 0x22d: cmp    WORD PTR [rcx+rax*2+0x4],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 1), 17179869184ULL);
x86_l_233:
	/* 0x233: je     5cf <inet_sock_set_state+0x5cf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x233, 0x5cf, x86_l_5cf);
x86_l_239:
	/* 0x239: cmp    r15w,WORD PTR [rcx+rax*2+0x4] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RCX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_RAX, 1, X86_WIDTH_16), 4ULL);
x86_l_23f:
	/* 0x23f: je     2ba <inet_sock_set_state+0x2ba> */
	X86_SIM_X86_JCC(X86_CC_E, 0x23f, 0x2ba, x86_l_2ba);
x86_l_241:
	/* 0x241: cmp    WORD PTR [rcx+rax*2+0x6],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 1), 25769803776ULL);
x86_l_247:
	/* 0x247: je     5cf <inet_sock_set_state+0x5cf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x247, 0x5cf, x86_l_5cf);
x86_l_24d:
	/* 0x24d: cmp    r15w,WORD PTR [rcx+rax*2+0x6] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RCX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_RAX, 1, X86_WIDTH_16), 6ULL);
x86_l_253:
	/* 0x253: je     2ba <inet_sock_set_state+0x2ba> */
	X86_SIM_X86_JCC(X86_CC_E, 0x253, 0x2ba, x86_l_2ba);
x86_l_255:
	/* 0x255: cmp    WORD PTR [rcx+rax*2+0x8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 1), 34359738368ULL);
x86_l_25b:
	/* 0x25b: je     5cf <inet_sock_set_state+0x5cf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x25b, 0x5cf, x86_l_5cf);
x86_l_261:
	/* 0x261: cmp    r15w,WORD PTR [rcx+rax*2+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RCX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_RAX, 1, X86_WIDTH_16), 8ULL);
x86_l_267:
	/* 0x267: je     2ba <inet_sock_set_state+0x2ba> */
	X86_SIM_X86_JCC(X86_CC_E, 0x267, 0x2ba, x86_l_2ba);
x86_l_269:
	/* 0x269: cmp    WORD PTR [rcx+rax*2+0xa],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 1), 42949672960ULL);
x86_l_26f:
	/* 0x26f: je     5cf <inet_sock_set_state+0x5cf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x26f, 0x5cf, x86_l_5cf);
x86_l_275:
	/* 0x275: cmp    r15w,WORD PTR [rcx+rax*2+0xa] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RCX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_RAX, 1, X86_WIDTH_16), 10ULL);
x86_l_27b:
	/* 0x27b: je     2ba <inet_sock_set_state+0x2ba> */
	X86_SIM_X86_JCC(X86_CC_E, 0x27b, 0x2ba, x86_l_2ba);
x86_l_27d:
	/* 0x27d: cmp    WORD PTR [rcx+rax*2+0xc],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 1), 51539607552ULL);
x86_l_283:
	/* 0x283: je     5cf <inet_sock_set_state+0x5cf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x283, 0x5cf, x86_l_5cf);
x86_l_289:
	/* 0x289: cmp    r15w,WORD PTR [rcx+rax*2+0xc] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RCX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_RAX, 1, X86_WIDTH_16), 12ULL);
x86_l_28f:
	/* 0x28f: je     2ba <inet_sock_set_state+0x2ba> */
	X86_SIM_X86_JCC(X86_CC_E, 0x28f, 0x2ba, x86_l_2ba);
x86_l_291:
	/* 0x291: cmp    WORD PTR [rcx+rax*2+0xe],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_RAX, 1), 60129542144ULL);
x86_l_297:
	/* 0x297: je     5cf <inet_sock_set_state+0x5cf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x297, 0x5cf, x86_l_5cf);
x86_l_29d:
	/* 0x29d: cmp    r15w,WORD PTR [rcx+rax*2+0xe] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_R15, X86_RCX, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_RAX, 1, X86_WIDTH_16), 14ULL);
x86_l_2a3:
	/* 0x2a3: je     2ba <inet_sock_set_state+0x2ba> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2a3, 0x2ba, x86_l_2ba);
x86_l_2a5:
	/* 0x2a5: add    rax,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2a9:
	/* 0x2a9: cmp    rax,0x400 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 1024ULL);
x86_l_2af:
	/* 0x2af: jne    1ff <inet_sock_set_state+0x1ff> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2af, 0x1ff, x86_l_1ff);
x86_l_2b5:
	/* 0x2b5: jmp    5cf <inet_sock_set_state+0x5cf> */
	X86_SIM_X86_JMP(0x2b5, 0x5cf, x86_l_5cf);
x86_l_2ba:
	/* 0x2ba: lea    rdx,[rbx+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2be:
	/* 0x2be: lea    rdi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2c3:
	/* 0x2c3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2c8:
	/* 0x2c8: call   2cd <inet_sock_set_state+0x2cd> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_2cd:
	/* 0x2cd: lea    r14,[rbx+0x14] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_2d1:
	/* 0x2d1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2d4:
	/* 0x2d4: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_2d9:
	/* 0x2d9: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_2dc:
	/* 0x2dc: call   2e1 <inet_sock_set_state+0x2e1> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_2e1:
	/* 0x2e1: cmp    DWORD PTR [rsp],0x3 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 3ULL);
x86_l_2e5:
	/* 0x2e5: jg     309 <inet_sock_set_state+0x309> */
	X86_SIM_X86_JCC(X86_CC_G, 0x2e5, 0x309, x86_l_309);
x86_l_2e7:
	/* 0x2e7: call   2ec <inet_sock_set_state+0x2ec> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_ktime_get_ns);
x86_l_2ec:
	/* 0x2ec: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2f1:
	/* 0x2f1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&birth)));
x86_l_2f8:
	/* 0x2f8: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_2fd:
	/* 0x2fd: lea    rdx,[rsp+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_302:
	/* 0x302: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_304:
	/* 0x304: call   309 <inet_sock_set_state+0x309> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_map_update_elem);
x86_l_309:
	/* 0x309: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_30c:
	/* 0x30c: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_311:
	/* 0x311: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_314:
	/* 0x314: call   319 <inet_sock_set_state+0x319> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_319:
	/* 0x319: cmp    DWORD PTR [rsp],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_31d:
	/* 0x31d: je     335 <inet_sock_set_state+0x335> */
	X86_SIM_X86_JCC(X86_CC_E, 0x31d, 0x335, x86_l_335);
x86_l_31f:
	/* 0x31f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_322:
	/* 0x322: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_327:
	/* 0x327: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_32a:
	/* 0x32a: call   32f <inet_sock_set_state+0x32f> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_32f:
	/* 0x32f: cmp    DWORD PTR [rsp],0x9 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 9ULL);
x86_l_333:
	/* 0x333: jne    37f <inet_sock_set_state+0x37f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x333, 0x37f, x86_l_37f);
x86_l_335:
	/* 0x335: call   33a <inet_sock_set_state+0x33a> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_get_current_pid_tgid);
x86_l_33a:
	/* 0x33a: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_33e:
	/* 0x33e: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&target_pid)));
x86_l_345:
	/* 0x345: cmp    DWORD PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_348:
	/* 0x348: je     354 <inet_sock_set_state+0x354> */
	X86_SIM_X86_JCC(X86_CC_E, 0x348, 0x354, x86_l_354);
x86_l_34a:
	/* 0x34a: mov    ecx,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_34c:
	/* 0x34c: cmp    ecx,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_34e:
	/* 0x34e: jne    5cf <inet_sock_set_state+0x5cf> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x34e, 0x5cf, x86_l_5cf);
x86_l_354:
	/* 0x354: mov    DWORD PTR [rsp+0x28],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_358:
	/* 0x358: lea    rdi,[rsp+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_35d:
	/* 0x35d: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_362:
	/* 0x362: call   367 <inet_sock_set_state+0x367> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_get_current_comm);
x86_l_367:
	/* 0x367: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&idents)));
x86_l_36e:
	/* 0x36e: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_373:
	/* 0x373: lea    rdx,[rsp+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_378:
	/* 0x378: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_37a:
	/* 0x37a: call   37f <inet_sock_set_state+0x37f> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_map_update_elem);
x86_l_37f:
	/* 0x37f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_382:
	/* 0x382: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_387:
	/* 0x387: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_38a:
	/* 0x38a: call   38f <inet_sock_set_state+0x38f> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_38f:
	/* 0x38f: cmp    DWORD PTR [rsp],0x7 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 7ULL);
x86_l_393:
	/* 0x393: jne    5cf <inet_sock_set_state+0x5cf> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x393, 0x5cf, x86_l_5cf);
x86_l_399:
	/* 0x399: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&birth)));
x86_l_3a0:
	/* 0x3a0: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3a5:
	/* 0x3a5: call   3aa <inet_sock_set_state+0x3aa> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_3aa:
	/* 0x3aa: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3ad:
	/* 0x3ad: je     5be <inet_sock_set_state+0x5be> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3ad, 0x5be, x86_l_5be);
x86_l_3b3:
	/* 0x3b3: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_3b6:
	/* 0x3b6: call   3bb <inet_sock_set_state+0x3bb> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_ktime_get_ns);
x86_l_3bb:
	/* 0x3bb: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3c0:
	/* 0x3c0: sub    rax,QWORD PTR [r14] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 0ULL);
x86_l_3c3:
	/* 0x3c3: shr    rax,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 3ULL);
x86_l_3c7:
	/* 0x3c7: movabs rcx,0x20c49ba5e353f7cf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_64, 2361183241434822607ULL);
x86_l_3d1:
	/* 0x3d1: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_3d4:
	/* 0x3d4: mulx   r12,r12,rcx */
	X86_SIM_L_EXEC_MULX(X86_R12, X86_RCX, X86_R12, X86_WIDTH_64);
x86_l_3d9:
	/* 0x3d9: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&idents)));
x86_l_3e0:
	/* 0x3e0: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3e5:
	/* 0x3e5: call   3ea <inet_sock_set_state+0x3ea> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_map_lookup_elem);
x86_l_3ea:
	/* 0x3ea: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_3ed:
	/* 0x3ed: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3f0:
	/* 0x3f0: je     3f7 <inet_sock_set_state+0x3f7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3f0, 0x3f7, x86_l_3f7);
x86_l_3f2:
	/* 0x3f2: mov    eax,DWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f5:
	/* 0x3f5: jmp    400 <inet_sock_set_state+0x400> */
	X86_SIM_X86_JMP(0x3f5, 0x400, x86_l_400);
x86_l_3f7:
	/* 0x3f7: call   3fc <inet_sock_set_state+0x3fc> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_get_current_pid_tgid);
x86_l_3fc:
	/* 0x3fc: shr    rax,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_400:
	/* 0x400: mov    rcx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RCX, (void *)(long)(((__u64)(long)&target_pid)));
x86_l_407:
	/* 0x407: cmp    DWORD PTR [rcx],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_40a:
	/* 0x40a: je     414 <inet_sock_set_state+0x414> */
	X86_SIM_X86_JCC(X86_CC_E, 0x40a, 0x414, x86_l_414);
x86_l_40c:
	/* 0x40c: cmp    eax,DWORD PTR [rcx] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_40e:
	/* 0x40e: jne    5ad <inet_sock_set_state+0x5ad> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x40e, 0x5ad, x86_l_5ad);
x86_l_414:
	/* 0x414: shr    r12,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_SHR, 4ULL);
x86_l_418:
	/* 0x418: mov    QWORD PTR [rsp+0xb0],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_420:
	/* 0x420: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_425:
	/* 0x425: lea    rdx,[r12+0x6f8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1784ULL);
x86_l_42d:
	/* 0x42d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_430:
	/* 0x430: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_435:
	/* 0x435: mov    QWORD PTR [rsp+0xa8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_43d:
	/* 0x43d: call   442 <inet_sock_set_state+0x442> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_442:
	/* 0x442: mov    rax,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_446:
	/* 0x446: mov    QWORD PTR [rsp+0xa0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_44e:
	/* 0x44e: add    r12,0x730 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_ADD, 1840ULL);
x86_l_455:
	/* 0x455: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_45a:
	/* 0x45a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_45f:
	/* 0x45f: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_462:
	/* 0x462: call   467 <inet_sock_set_state+0x467> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_467:
	/* 0x467: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_46c:
	/* 0x46c: shr    rdx,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_64, X86_ALU_SHR, 3ULL);
x86_l_470:
	/* 0x470: movabs rax,0x20c49ba5e353f7cf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 2361183241434822607ULL);
x86_l_47a:
	/* 0x47a: mulx   rax,rax,rax */
	X86_SIM_L_EXEC_MULX(X86_RAX, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_47f:
	/* 0x47f: shr    rax,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_SHR, 4ULL);
x86_l_483:
	/* 0x483: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_488:
	/* 0x488: mov    rax,QWORD PTR [rsp+0xb0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 176ULL);
x86_l_490:
	/* 0x490: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_495:
	/* 0x495: mov    rax,QWORD PTR [rsp+0xa0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 160ULL);
x86_l_49d:
	/* 0x49d: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_4a2:
	/* 0x4a2: mov    rax,QWORD PTR [rsp+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_4aa:
	/* 0x4aa: mov    DWORD PTR [rsp+0x80],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_4b1:
	/* 0x4b1: mov    WORD PTR [rsp+0x84],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 132ULL);
x86_l_4ba:
	/* 0x4ba: mov    WORD PTR [rsp+0x86],r15w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R15, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 134ULL);
x86_l_4c3:
	/* 0x4c3: mov    WORD PTR [rsp+0x88],bp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RBP, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_4cb:
	/* 0x4cb: lea    rdi,[rsp+0x8a] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 138ULL);
x86_l_4d3:
	/* 0x4d3: test   r14,r14 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R14, X86_R14, X86_WIDTH_64);
x86_l_4d6:
	/* 0x4d6: je     4eb <inet_sock_set_state+0x4eb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4d6, 0x4eb, x86_l_4eb);
x86_l_4d8:
	/* 0x4d8: add    r14,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_4dc:
	/* 0x4dc: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_4e1:
	/* 0x4e1: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_4e4:
	/* 0x4e4: call   4e9 <inet_sock_set_state+0x4e9> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_4e9:
	/* 0x4e9: jmp    4f5 <inet_sock_set_state+0x4f5> */
	X86_SIM_X86_JMP(0x4e9, 0x4f5, x86_l_4f5);
x86_l_4eb:
	/* 0x4eb: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_4f0:
	/* 0x4f0: call   4f5 <inet_sock_set_state+0x4f5> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_get_current_comm);
x86_l_4f5:
	/* 0x4f5: lea    r14,[rsp+0x50] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4fa:
	/* 0x4fa: cmp    bp,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBP, X86_WIDTH_16, 2ULL);
x86_l_4fe:
	/* 0x4fe: jne    544 <inet_sock_set_state+0x544> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4fe, 0x544, x86_l_544);
x86_l_500:
	/* 0x500: lea    rdx,[rbx+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_504:
	/* 0x504: mov    r15,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSP, X86_WIDTH_64);
x86_l_507:
	/* 0x507: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_50a:
	/* 0x50a: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_50f:
	/* 0x50f: call   514 <inet_sock_set_state+0x514> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_514:
	/* 0x514: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_519:
	/* 0x519: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_51e:
	/* 0x51e: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_521:
	/* 0x521: call   526 <inet_sock_set_state+0x526> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_526:
	/* 0x526: lea    rdx,[rbx+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_52a:
	/* 0x52a: mov    r15,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSP, X86_WIDTH_64);
x86_l_52d:
	/* 0x52d: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_530:
	/* 0x530: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_535:
	/* 0x535: call   53a <inet_sock_set_state+0x53a> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_53a:
	/* 0x53a: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_53d:
	/* 0x53d: mov    esi,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4ULL);
x86_l_542:
	/* 0x542: jmp    586 <inet_sock_set_state+0x586> */
	X86_SIM_X86_JMP(0x542, 0x586, x86_l_586);
x86_l_544:
	/* 0x544: lea    rdx,[rbx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_548:
	/* 0x548: mov    r15,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSP, X86_WIDTH_64);
x86_l_54b:
	/* 0x54b: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_54e:
	/* 0x54e: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_553:
	/* 0x553: call   558 <inet_sock_set_state+0x558> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_558:
	/* 0x558: lea    rdi,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_55d:
	/* 0x55d: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_562:
	/* 0x562: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_565:
	/* 0x565: call   56a <inet_sock_set_state+0x56a> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_56a:
	/* 0x56a: lea    rdx,[rbx+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_56e:
	/* 0x56e: mov    r15,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSP, X86_WIDTH_64);
x86_l_571:
	/* 0x571: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_574:
	/* 0x574: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_579:
	/* 0x579: call   57e <inet_sock_set_state+0x57e> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_57e:
	/* 0x57e: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_581:
	/* 0x581: mov    esi,0x10 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 16ULL);
x86_l_586:
	/* 0x586: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_589:
	/* 0x589: call   58e <inet_sock_set_state+0x58e> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_probe_read_kernel);
x86_l_58e:
	/* 0x58e: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&events)));
x86_l_595:
	/* 0x595: lea    rcx,[rsp+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_59a:
	/* 0x59a: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_59f:
	/* 0x59f: mov    r8d,0x60 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 96ULL);
x86_l_5a5:
	/* 0x5a5: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_5a8:
	/* 0x5a8: call   5ad <inet_sock_set_state+0x5ad> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_perf_event_output);
x86_l_5ad:
	/* 0x5ad: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&birth)));
x86_l_5b4:
	/* 0x5b4: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5b9:
	/* 0x5b9: call   5be <inet_sock_set_state+0x5be> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_map_delete_elem);
x86_l_5be:
	/* 0x5be: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&idents)));
x86_l_5c5:
	/* 0x5c5: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5ca:
	/* 0x5ca: call   5cf <inet_sock_set_state+0x5cf> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_map_delete_elem);
x86_l_5cf:
	/* 0x5cf: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_5d1:
	/* 0x5d1: add    rsp,0xb8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 184ULL);
x86_l_5d8:
	/* 0x5d8: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_5da:
	/* 0x5da: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_5db:
	/* 0x5db: jmp    5e0 <inet_sock_set_state+0x5e0> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_5e0:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
