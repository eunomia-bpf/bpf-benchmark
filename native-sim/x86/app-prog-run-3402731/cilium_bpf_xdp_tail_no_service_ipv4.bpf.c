extern char cilium_calls;
extern char cilium_metrics;
extern char cilium_xdp_scratch;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int cilium_bpf_xdp_tail_no_service_ipv4_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0xa: sub    rsp,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 56ULL);
x86_l_e:
	/* 0xe: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_11:
	/* 0x11: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_19:
	/* 0x19: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1e:
	/* 0x1e: mov    rdi,QWORD PTR [rip+0x380] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_25:
	/* 0x25: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2a:
	/* 0x2a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c:
	/* 0x2c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2f:
	/* 0x2f: je     3c2 <tail_no_service_ipv4+0x3c2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2f, 0x3c2, x86_l_3c2);
x86_l_35:
	/* 0x35: mov    ebp,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_37:
	/* 0x37: mov    rax,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3a:
	/* 0x3a: mov    r15,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3e:
	/* 0x3e: lea    rcx,[rax+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_42:
	/* 0x42: cmp    rcx,r15 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_R15, X86_WIDTH_64);
x86_l_45:
	/* 0x45: ja     175 <tail_no_service_ipv4+0x175> */
	X86_SIM_X86_JCC(X86_CC_A, 0x45, 0x175, x86_l_175);
x86_l_4b:
	/* 0x4b: movzx  r13d,WORD PTR [rax+0xa] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R13, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 10ULL);
x86_l_50:
	/* 0x50: mov    ecx,DWORD PTR [rax+0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_53:
	/* 0x53: mov    DWORD PTR [rsp+0x24],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_57:
	/* 0x57: movzx  ecx,WORD PTR [rax+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 4ULL);
x86_l_5b:
	/* 0x5b: mov    WORD PTR [rsp+0xe],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_60:
	/* 0x60: mov    ecx,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_62:
	/* 0x62: mov    DWORD PTR [rsp+0x20],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_66:
	/* 0x66: mov    ecx,DWORD PTR [rax+0x1a] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_69:
	/* 0x69: mov    DWORD PTR [rsp+0x2c],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_6d:
	/* 0x6d: mov    ecx,DWORD PTR [rax+0x1e] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_70:
	/* 0x70: mov    DWORD PTR [rsp+0x28],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_74:
	/* 0x74: movzx  ecx,BYTE PTR [rax+0xf] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 15ULL);
x86_l_78:
	/* 0x78: mov    BYTE PTR [rsp+0xd],cl */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 13ULL);
x86_l_7c:
	/* 0x7c: sub    r15d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_7f:
	/* 0x7f: cmp    r15d,0x40 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 64ULL);
x86_l_83:
	/* 0x83: mov    r14d,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R14, X86_WIDTH_32, 64ULL);
x86_l_89:
	/* 0x89: cmovl  r14d,r15d */
	X86_SIM_L_EXEC_CMOV(X86_R14, X86_R15, X86_WIDTH_32, X86_CC_L);
x86_l_8d:
	/* 0x8d: mov    esi,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_32);
x86_l_90:
	/* 0x90: sub    esi,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_R15, X86_WIDTH_32, X86_ALU_SUB);
x86_l_93:
	/* 0x93: add    esi,0xe */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 14ULL);
x86_l_96:
	/* 0x96: mov    eax,0x41 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 65ULL);
x86_l_9b:
	/* 0x9b: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_9e:
	/* 0x9e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a0:
	/* 0xa0: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a3:
	/* 0xa3: test   r15d,r15d */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R15, X86_R15, X86_WIDTH_32);
x86_l_a6:
	/* 0xa6: js     151 <tail_no_service_ipv4+0x151> */
	X86_SIM_X86_JCC(X86_CC_S, 0xa6, 0x151, x86_l_151);
x86_l_ac:
	/* 0xac: mov    rcx,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_af:
	/* 0xaf: mov    rdx,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b3:
	/* 0xb3: lea    rax,[rcx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b7:
	/* 0xb7: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_ba:
	/* 0xba: jbe    d3 <tail_no_service_ipv4+0xd3> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xba, 0xd3, x86_l_d3);
x86_l_bc:
	/* 0xbc: lea    rax,[rcx+0xf] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 15ULL);
x86_l_c0:
	/* 0xc0: cmp    rax,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RAX, X86_RDX, X86_WIDTH_64);
x86_l_c3:
	/* 0xc3: ja     151 <tail_no_service_ipv4+0x151> */
	X86_SIM_X86_JCC(X86_CC_A, 0xc3, 0x151, x86_l_151);
x86_l_c9:
	/* 0xc9: movzx  r12d,BYTE PTR [rcx+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 14ULL);
x86_l_ce:
	/* 0xce: jmp    151 <tail_no_service_ipv4+0x151> */
	X86_SIM_X86_JMP(0xce, 0x151, x86_l_151);
x86_l_d3:
	/* 0xd3: movzx  r12d,WORD PTR [rcx+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RCX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_d8:
	/* 0xd8: cmp    r15d,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 2ULL);
x86_l_dc:
	/* 0xdc: jb     151 <tail_no_service_ipv4+0x151> */
	X86_SIM_X86_JCC(X86_CC_B, 0xdc, 0x151, x86_l_151);
x86_l_de:
	/* 0xde: lea    rsi,[rcx+0x12] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_e2:
	/* 0xe2: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_e5:
	/* 0xe5: jbe    f8 <tail_no_service_ipv4+0xf8> */
	X86_SIM_X86_JCC(X86_CC_BE, 0xe5, 0xf8, x86_l_f8);
x86_l_e7:
	/* 0xe7: add    rcx,0x11 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 17ULL);
x86_l_eb:
	/* 0xeb: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_ee:
	/* 0xee: ja     151 <tail_no_service_ipv4+0x151> */
	X86_SIM_X86_JCC(X86_CC_A, 0xee, 0x151, x86_l_151);
x86_l_f0:
	/* 0xf0: movzx  eax,BYTE PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_f3:
	/* 0xf3: add    r12d,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_f6:
	/* 0xf6: jmp    151 <tail_no_service_ipv4+0x151> */
	X86_SIM_X86_JMP(0xf6, 0x151, x86_l_151);
x86_l_f8:
	/* 0xf8: movzx  eax,WORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_fb:
	/* 0xfb: add    eax,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R12, X86_WIDTH_32, X86_ALU_ADD);
x86_l_fe:
	/* 0xfe: cmp    r15d,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 4ULL);
x86_l_102:
	/* 0x102: jb     14e <tail_no_service_ipv4+0x14e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x102, 0x14e, x86_l_14e);
x86_l_104:
	/* 0x104: lea    rdi,[rcx+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_108:
	/* 0x108: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_10b:
	/* 0x10b: jbe    11d <tail_no_service_ipv4+0x11d> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x10b, 0x11d, x86_l_11d);
x86_l_10d:
	/* 0x10d: add    rcx,0x13 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 19ULL);
x86_l_111:
	/* 0x111: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_114:
	/* 0x114: ja     14e <tail_no_service_ipv4+0x14e> */
	X86_SIM_X86_JCC(X86_CC_A, 0x114, 0x14e, x86_l_14e);
x86_l_116:
	/* 0x116: movzx  ecx,BYTE PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_119:
	/* 0x119: add    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_11b:
	/* 0x11b: jmp    14e <tail_no_service_ipv4+0x14e> */
	X86_SIM_X86_JMP(0x11b, 0x14e, x86_l_14e);
x86_l_11d:
	/* 0x11d: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_120:
	/* 0x120: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_122:
	/* 0x122: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_126:
	/* 0x126: jb     14e <tail_no_service_ipv4+0x14e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x126, 0x14e, x86_l_14e);
x86_l_128:
	/* 0x128: lea    rsi,[rcx+0x16] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 22ULL);
x86_l_12c:
	/* 0x12c: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_12f:
	/* 0x12f: jbe    13f <tail_no_service_ipv4+0x13f> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x12f, 0x13f, x86_l_13f);
x86_l_131:
	/* 0x131: add    rcx,0x15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 21ULL);
x86_l_135:
	/* 0x135: cmp    rcx,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64);
x86_l_138:
	/* 0x138: ja     14e <tail_no_service_ipv4+0x14e> */
	X86_SIM_X86_JCC(X86_CC_A, 0x138, 0x14e, x86_l_14e);
x86_l_13a:
	/* 0x13a: movzx  ecx,BYTE PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 0ULL);
x86_l_13d:
	/* 0x13d: jmp    119 <tail_no_service_ipv4+0x119> */
	X86_SIM_X86_JMP(0x13d, 0x119, x86_l_119);
x86_l_13f:
	/* 0x13f: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_142:
	/* 0x142: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_144:
	/* 0x144: cmp    r15d,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 8ULL);
x86_l_148:
	/* 0x148: jae    38f <tail_no_service_ipv4+0x38f> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x148, 0x38f, x86_l_38f);
x86_l_14e:
	/* 0x14e: mov    r12d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_32);
x86_l_151:
	/* 0x151: mov    eax,0x2c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 44ULL);
x86_l_156:
	/* 0x156: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_159:
	/* 0x159: mov    esi,0xffffffe4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4294967268ULL);
x86_l_15e:
	/* 0x15e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_160:
	/* 0x160: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_162:
	/* 0x162: js     175 <tail_no_service_ipv4+0x175> */
	X86_SIM_X86_JCC(X86_CC_S, 0x162, 0x175, x86_l_175);
x86_l_164:
	/* 0x164: mov    r15,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_167:
	/* 0x167: lea    rax,[r15+0x2a] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_16b:
	/* 0x16b: cmp    rax,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_CMP_REG_MEM(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64), 8ULL);
x86_l_16f:
	/* 0x16f: jbe    2c2 <tail_no_service_ipv4+0x2c2> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x16f, 0x2c2, x86_l_2c2);
x86_l_175:
	/* 0x175: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_17d:
	/* 0x17d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_182:
	/* 0x182: mov    rdi,QWORD PTR [rip+0x37d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_189:
	/* 0x189: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_18e:
	/* 0x18e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_190:
	/* 0x190: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_193:
	/* 0x193: je     197 <tail_no_service_ipv4+0x197> */
	X86_SIM_X86_JCC(X86_CC_E, 0x193, 0x197, x86_l_197);
x86_l_195:
	/* 0x195: mov    DWORD PTR [rax],ebp */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RBP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_197:
	/* 0x197: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_19f:
	/* 0x19f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1a4:
	/* 0x1a4: mov    rdi,QWORD PTR [rip+0x384] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_1ab:
	/* 0x1ab: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b0:
	/* 0x1b0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b2:
	/* 0x1b2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b5:
	/* 0x1b5: je     1be <tail_no_service_ipv4+0x1be> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1b5, 0x1be, x86_l_1be);
x86_l_1b7:
	/* 0x1b7: mov    DWORD PTR [rax+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_1be:
	/* 0x1be: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1c6:
	/* 0x1c6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1cb:
	/* 0x1cb: mov    rdi,QWORD PTR [rip+0x37d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_1d2:
	/* 0x1d2: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1d7:
	/* 0x1d7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d9:
	/* 0x1d9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1dc:
	/* 0x1dc: je     1e5 <tail_no_service_ipv4+0x1e5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1dc, 0x1e5, x86_l_1e5);
x86_l_1de:
	/* 0x1de: mov    DWORD PTR [rax+0x8],0x86 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738502ULL);
x86_l_1e5:
	/* 0x1e5: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_1ed:
	/* 0x1ed: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1f2:
	/* 0x1f2: mov    rdi,QWORD PTR [rip+0x37d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_1f9:
	/* 0x1f9: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1fe:
	/* 0x1fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_200:
	/* 0x200: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_203:
	/* 0x203: je     20c <tail_no_service_ipv4+0x20c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x203, 0x20c, x86_l_20c);
x86_l_205:
	/* 0x205: mov    DWORD PTR [rax+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_20c:
	/* 0x20c: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_214:
	/* 0x214: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_219:
	/* 0x219: mov    rdi,QWORD PTR [rip+0x37d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_xdp_scratch)));
x86_l_220:
	/* 0x220: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_225:
	/* 0x225: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_227:
	/* 0x227: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_22a:
	/* 0x22a: je     233 <tail_no_service_ipv4+0x233> */
	X86_SIM_X86_JCC(X86_CC_E, 0x22a, 0x233, x86_l_233);
x86_l_22c:
	/* 0x22c: mov    DWORD PTR [rax+0x10],0x9026901 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68870629633ULL);
x86_l_233:
	/* 0x233: mov    r14,QWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_237:
	/* 0x237: sub    r14,QWORD PTR [rbx] */
	X86_SIM_L_EXEC_ALU_MEM(X86_R14, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_SUB)), 0ULL);
x86_l_23a:
	/* 0x23a: movabs rax,0x6909020186 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 451122692486ULL);
x86_l_244:
	/* 0x244: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_249:
	/* 0x249: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_24e:
	/* 0x24e: mov    rdi,QWORD PTR [rip+0x384] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_255:
	/* 0x255: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_25a:
	/* 0x25a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_25c:
	/* 0x25c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_25f:
	/* 0x25f: je     26a <tail_no_service_ipv4+0x26a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x25f, 0x26a, x86_l_26a);
x86_l_261:
	/* 0x261: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_264:
	/* 0x264: add    QWORD PTR [rax+0x8],r14 */
	X86_SIM_L_EXEC_ALU_MEM_REG(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 8ULL);
x86_l_268:
	/* 0x268: jmp    292 <tail_no_service_ipv4+0x292> */
	X86_SIM_X86_JMP(0x268, 0x292, x86_l_292);
x86_l_26a:
	/* 0x26a: mov    QWORD PTR [rsp+0x10],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476737ULL);
x86_l_273:
	/* 0x273: mov    QWORD PTR [rsp+0x18],r14 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_278:
	/* 0x278: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_27d:
	/* 0x27d: mov    rdi,QWORD PTR [rip+0x37d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_284:
	/* 0x284: lea    rsi,[rsp+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_289:
	/* 0x289: lea    rdx,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_28e:
	/* 0x28e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_290:
	/* 0x290: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_292:
	/* 0x292: mov    eax,0xc */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 12ULL);
x86_l_297:
	/* 0x297: mov    rsi,QWORD PTR [rip+0x37d] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&cilium_calls)));
x86_l_29e:
	/* 0x29e: mov    ebp,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 1ULL);
x86_l_2a3:
	/* 0x2a3: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_2a6:
	/* 0x2a6: mov    edx,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_2ab:
	/* 0x2ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ad:
	/* 0x2ad: mov    eax,ebp */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBP, X86_WIDTH_32);
x86_l_2af:
	/* 0x2af: add    rsp,0x38 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 56ULL);
x86_l_2b3:
	/* 0x2b3: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_2b4:
	/* 0x2b4: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_2b6:
	/* 0x2b6: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_2b8:
	/* 0x2b8: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_2ba:
	/* 0x2ba: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_2bc:
	/* 0x2bc: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_2bd:
	/* 0x2bd: jmp    74c <tail_no_service_ipv4+0x74c> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_2c2:
	/* 0x2c2: mov    WORD PTR [r15+0x4],r13w */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_R13, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2c7:
	/* 0x2c7: mov    eax,DWORD PTR [rsp+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_2cb:
	/* 0x2cb: mov    DWORD PTR [r15],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ce:
	/* 0x2ce: movzx  eax,WORD PTR [rsp+0xe] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 14ULL);
x86_l_2d3:
	/* 0x2d3: mov    WORD PTR [r15+0xa],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 10ULL);
x86_l_2d8:
	/* 0x2d8: mov    eax,DWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2dc:
	/* 0x2dc: mov    DWORD PTR [r15+0x6],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 6ULL);
x86_l_2e0:
	/* 0x2e0: mov    WORD PTR [r15+0xc],0x8 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 51539607560ULL);
x86_l_2e7:
	/* 0x2e7: lea    rdi,[r15+0xe] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 14ULL);
x86_l_2eb:
	/* 0x2eb: mov    BYTE PTR [r15+0xe],0x45 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 60129542213ULL);
x86_l_2f0:
	/* 0x2f0: movzx  eax,BYTE PTR [rsp+0xd] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 13ULL);
x86_l_2f5:
	/* 0x2f5: mov    BYTE PTR [r15+0xf],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 15ULL);
x86_l_2f9:
	/* 0x2f9: add    r14d,0x1c */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_32, X86_ALU_ADD, 28ULL);
x86_l_2fd:
	/* 0x2fd: movbe  WORD PTR [r15+0x10],r14w */
	X86_SIM_RUN_OP(X86_OP_MOVBE_STORE, X86_R15, X86_R14, X86_WIDTH_16, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 16ULL);
x86_l_304:
	/* 0x304: movabs rax,0x14000000000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 1374389534720ULL);
x86_l_30e:
	/* 0x30e: mov    QWORD PTR [r15+0x12],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 18ULL);
x86_l_312:
	/* 0x312: mov    eax,DWORD PTR [rsp+0x2c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_316:
	/* 0x316: mov    DWORD PTR [r15+0x1e],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_31a:
	/* 0x31a: mov    eax,DWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_31e:
	/* 0x31e: mov    DWORD PTR [r15+0x1a],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_322:
	/* 0x322: mov    eax,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_327:
	/* 0x327: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_329:
	/* 0x329: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_32c:
	/* 0x32c: mov    ecx,0x14 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 20ULL);
x86_l_331:
	/* 0x331: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_334:
	/* 0x334: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_336:
	/* 0x336: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_339:
	/* 0x339: shr    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_33c:
	/* 0x33c: add    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_33e:
	/* 0x33e: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_340:
	/* 0x340: shr    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_343:
	/* 0x343: add    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_345:
	/* 0x345: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_347:
	/* 0x347: mov    WORD PTR [r15+0x18],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_34c:
	/* 0x34c: lea    rdi,[r15+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_350:
	/* 0x350: mov    QWORD PTR [r15+0x22],0x303 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_R15, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 146028888835ULL);
x86_l_358:
	/* 0x358: mov    eax,0x1c */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 28ULL);
x86_l_35d:
	/* 0x35d: xor    esi,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_35f:
	/* 0x35f: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_362:
	/* 0x362: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_367:
	/* 0x367: xor    r8d,r8d */
	X86_SIM_L_EXEC_ALU_REG(X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR);
x86_l_36a:
	/* 0x36a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36c:
	/* 0x36c: add    eax,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R12, X86_WIDTH_32, X86_ALU_ADD);
x86_l_36f:
	/* 0x36f: movzx  ecx,ax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVZX_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_WIDTH_16);
x86_l_372:
	/* 0x372: shr    eax,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_375:
	/* 0x375: add    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_377:
	/* 0x377: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_379:
	/* 0x379: shr    ecx,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_37c:
	/* 0x37c: add    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_ADD);
x86_l_37e:
	/* 0x37e: not    ecx */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_380:
	/* 0x380: mov    WORD PTR [r15+0x24],cx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RCX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_385:
	/* 0x385: mov    ebp,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBP, X86_WIDTH_32, 3ULL);
x86_l_38a:
	/* 0x38a: jmp    2ad <tail_no_service_ipv4+0x2ad> */
	X86_SIM_X86_JMP(0x38a, 0x2ad, x86_l_2ad);
x86_l_38f:
	/* 0x38f: lea    rdi,[rcx+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_393:
	/* 0x393: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_396:
	/* 0x396: jbe    3a1 <tail_no_service_ipv4+0x3a1> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x396, 0x3a1, x86_l_3a1);
x86_l_398:
	/* 0x398: add    rcx,0x17 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 23ULL);
x86_l_39c:
	/* 0x39c: jmp    111 <tail_no_service_ipv4+0x111> */
	X86_SIM_X86_JMP(0x39c, 0x111, x86_l_111);
x86_l_3a1:
	/* 0x3a1: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3a4:
	/* 0x3a4: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3a6:
	/* 0x3a6: cmp    r15d,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 10ULL);
x86_l_3aa:
	/* 0x3aa: jb     14e <tail_no_service_ipv4+0x14e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x3aa, 0x14e, x86_l_14e);
x86_l_3b0:
	/* 0x3b0: lea    rsi,[rcx+0x1a] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 26ULL);
x86_l_3b4:
	/* 0x3b4: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_3b7:
	/* 0x3b7: jbe    3c9 <tail_no_service_ipv4+0x3c9> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x3b7, 0x3c9, x86_l_3c9);
x86_l_3b9:
	/* 0x3b9: add    rcx,0x19 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 25ULL);
x86_l_3bd:
	/* 0x3bd: jmp    135 <tail_no_service_ipv4+0x135> */
	X86_SIM_X86_JMP(0x3bd, 0x135, x86_l_135);
x86_l_3c2:
	/* 0x3c2: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3c4:
	/* 0x3c4: jmp    37 <tail_no_service_ipv4+0x37> */
	X86_SIM_X86_JMP(0x3c4, 0x37, x86_l_37);
x86_l_3c9:
	/* 0x3c9: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3cc:
	/* 0x3cc: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3ce:
	/* 0x3ce: cmp    r15d,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 12ULL);
x86_l_3d2:
	/* 0x3d2: jb     14e <tail_no_service_ipv4+0x14e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x3d2, 0x14e, x86_l_14e);
x86_l_3d8:
	/* 0x3d8: lea    rdi,[rcx+0x1c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_3dc:
	/* 0x3dc: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_3df:
	/* 0x3df: jbe    3ea <tail_no_service_ipv4+0x3ea> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x3df, 0x3ea, x86_l_3ea);
x86_l_3e1:
	/* 0x3e1: add    rcx,0x1b */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 27ULL);
x86_l_3e5:
	/* 0x3e5: jmp    111 <tail_no_service_ipv4+0x111> */
	X86_SIM_X86_JMP(0x3e5, 0x111, x86_l_111);
x86_l_3ea:
	/* 0x3ea: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_3ed:
	/* 0x3ed: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_3ef:
	/* 0x3ef: cmp    r15d,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 14ULL);
x86_l_3f3:
	/* 0x3f3: jb     14e <tail_no_service_ipv4+0x14e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x3f3, 0x14e, x86_l_14e);
x86_l_3f9:
	/* 0x3f9: lea    rsi,[rcx+0x1e] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 30ULL);
x86_l_3fd:
	/* 0x3fd: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_400:
	/* 0x400: jbe    40b <tail_no_service_ipv4+0x40b> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x400, 0x40b, x86_l_40b);
x86_l_402:
	/* 0x402: add    rcx,0x1d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 29ULL);
x86_l_406:
	/* 0x406: jmp    135 <tail_no_service_ipv4+0x135> */
	X86_SIM_X86_JMP(0x406, 0x135, x86_l_135);
x86_l_40b:
	/* 0x40b: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_40e:
	/* 0x40e: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_410:
	/* 0x410: cmp    r15d,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 16ULL);
x86_l_414:
	/* 0x414: jb     14e <tail_no_service_ipv4+0x14e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x414, 0x14e, x86_l_14e);
x86_l_41a:
	/* 0x41a: lea    rdi,[rcx+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_41e:
	/* 0x41e: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_421:
	/* 0x421: jbe    42c <tail_no_service_ipv4+0x42c> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x421, 0x42c, x86_l_42c);
x86_l_423:
	/* 0x423: add    rcx,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 31ULL);
x86_l_427:
	/* 0x427: jmp    111 <tail_no_service_ipv4+0x111> */
	X86_SIM_X86_JMP(0x427, 0x111, x86_l_111);
x86_l_42c:
	/* 0x42c: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_42f:
	/* 0x42f: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_431:
	/* 0x431: cmp    r15d,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 18ULL);
x86_l_435:
	/* 0x435: jb     14e <tail_no_service_ipv4+0x14e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x435, 0x14e, x86_l_14e);
x86_l_43b:
	/* 0x43b: lea    rsi,[rcx+0x22] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34ULL);
x86_l_43f:
	/* 0x43f: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_442:
	/* 0x442: jbe    44d <tail_no_service_ipv4+0x44d> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x442, 0x44d, x86_l_44d);
x86_l_444:
	/* 0x444: add    rcx,0x21 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 33ULL);
x86_l_448:
	/* 0x448: jmp    135 <tail_no_service_ipv4+0x135> */
	X86_SIM_X86_JMP(0x448, 0x135, x86_l_135);
x86_l_44d:
	/* 0x44d: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_450:
	/* 0x450: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_452:
	/* 0x452: cmp    r15d,0x14 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 20ULL);
x86_l_456:
	/* 0x456: jb     14e <tail_no_service_ipv4+0x14e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x456, 0x14e, x86_l_14e);
x86_l_45c:
	/* 0x45c: lea    rdi,[rcx+0x24] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_460:
	/* 0x460: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_463:
	/* 0x463: jbe    46e <tail_no_service_ipv4+0x46e> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x463, 0x46e, x86_l_46e);
x86_l_465:
	/* 0x465: add    rcx,0x23 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 35ULL);
x86_l_469:
	/* 0x469: jmp    111 <tail_no_service_ipv4+0x111> */
	X86_SIM_X86_JMP(0x469, 0x111, x86_l_111);
x86_l_46e:
	/* 0x46e: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_471:
	/* 0x471: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_473:
	/* 0x473: cmp    r15d,0x16 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 22ULL);
x86_l_477:
	/* 0x477: jb     14e <tail_no_service_ipv4+0x14e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x477, 0x14e, x86_l_14e);
x86_l_47d:
	/* 0x47d: lea    rsi,[rcx+0x26] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 38ULL);
x86_l_481:
	/* 0x481: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_484:
	/* 0x484: jbe    48f <tail_no_service_ipv4+0x48f> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x484, 0x48f, x86_l_48f);
x86_l_486:
	/* 0x486: add    rcx,0x25 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 37ULL);
x86_l_48a:
	/* 0x48a: jmp    135 <tail_no_service_ipv4+0x135> */
	X86_SIM_X86_JMP(0x48a, 0x135, x86_l_135);
x86_l_48f:
	/* 0x48f: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_492:
	/* 0x492: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_494:
	/* 0x494: cmp    r15d,0x18 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 24ULL);
x86_l_498:
	/* 0x498: jb     14e <tail_no_service_ipv4+0x14e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x498, 0x14e, x86_l_14e);
x86_l_49e:
	/* 0x49e: lea    rdi,[rcx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_4a2:
	/* 0x4a2: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_4a5:
	/* 0x4a5: jbe    4b0 <tail_no_service_ipv4+0x4b0> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x4a5, 0x4b0, x86_l_4b0);
x86_l_4a7:
	/* 0x4a7: add    rcx,0x27 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 39ULL);
x86_l_4ab:
	/* 0x4ab: jmp    111 <tail_no_service_ipv4+0x111> */
	X86_SIM_X86_JMP(0x4ab, 0x111, x86_l_111);
x86_l_4b0:
	/* 0x4b0: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4b3:
	/* 0x4b3: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_4b5:
	/* 0x4b5: cmp    r15d,0x1a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 26ULL);
x86_l_4b9:
	/* 0x4b9: jb     14e <tail_no_service_ipv4+0x14e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x4b9, 0x14e, x86_l_14e);
x86_l_4bf:
	/* 0x4bf: lea    rsi,[rcx+0x2a] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 42ULL);
x86_l_4c3:
	/* 0x4c3: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_4c6:
	/* 0x4c6: jbe    4d1 <tail_no_service_ipv4+0x4d1> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x4c6, 0x4d1, x86_l_4d1);
x86_l_4c8:
	/* 0x4c8: add    rcx,0x29 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 41ULL);
x86_l_4cc:
	/* 0x4cc: jmp    135 <tail_no_service_ipv4+0x135> */
	X86_SIM_X86_JMP(0x4cc, 0x135, x86_l_135);
x86_l_4d1:
	/* 0x4d1: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4d4:
	/* 0x4d4: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_4d6:
	/* 0x4d6: cmp    r15d,0x1c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 28ULL);
x86_l_4da:
	/* 0x4da: jb     14e <tail_no_service_ipv4+0x14e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x4da, 0x14e, x86_l_14e);
x86_l_4e0:
	/* 0x4e0: lea    rdi,[rcx+0x2c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_4e4:
	/* 0x4e4: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_4e7:
	/* 0x4e7: jbe    4f2 <tail_no_service_ipv4+0x4f2> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x4e7, 0x4f2, x86_l_4f2);
x86_l_4e9:
	/* 0x4e9: add    rcx,0x2b */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 43ULL);
x86_l_4ed:
	/* 0x4ed: jmp    111 <tail_no_service_ipv4+0x111> */
	X86_SIM_X86_JMP(0x4ed, 0x111, x86_l_111);
x86_l_4f2:
	/* 0x4f2: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_4f5:
	/* 0x4f5: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_4f7:
	/* 0x4f7: cmp    r15d,0x1e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 30ULL);
x86_l_4fb:
	/* 0x4fb: jb     14e <tail_no_service_ipv4+0x14e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x4fb, 0x14e, x86_l_14e);
x86_l_501:
	/* 0x501: lea    rsi,[rcx+0x2e] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 46ULL);
x86_l_505:
	/* 0x505: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_508:
	/* 0x508: jbe    513 <tail_no_service_ipv4+0x513> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x508, 0x513, x86_l_513);
x86_l_50a:
	/* 0x50a: add    rcx,0x2d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 45ULL);
x86_l_50e:
	/* 0x50e: jmp    135 <tail_no_service_ipv4+0x135> */
	X86_SIM_X86_JMP(0x50e, 0x135, x86_l_135);
x86_l_513:
	/* 0x513: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_516:
	/* 0x516: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_518:
	/* 0x518: cmp    r15d,0x20 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 32ULL);
x86_l_51c:
	/* 0x51c: jb     14e <tail_no_service_ipv4+0x14e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x51c, 0x14e, x86_l_14e);
x86_l_522:
	/* 0x522: lea    rdi,[rcx+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_526:
	/* 0x526: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_529:
	/* 0x529: jbe    534 <tail_no_service_ipv4+0x534> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x529, 0x534, x86_l_534);
x86_l_52b:
	/* 0x52b: add    rcx,0x2f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 47ULL);
x86_l_52f:
	/* 0x52f: jmp    111 <tail_no_service_ipv4+0x111> */
	X86_SIM_X86_JMP(0x52f, 0x111, x86_l_111);
x86_l_534:
	/* 0x534: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_537:
	/* 0x537: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_539:
	/* 0x539: cmp    r15d,0x22 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 34ULL);
x86_l_53d:
	/* 0x53d: jb     14e <tail_no_service_ipv4+0x14e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x53d, 0x14e, x86_l_14e);
x86_l_543:
	/* 0x543: lea    rsi,[rcx+0x32] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 50ULL);
x86_l_547:
	/* 0x547: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_54a:
	/* 0x54a: jbe    555 <tail_no_service_ipv4+0x555> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x54a, 0x555, x86_l_555);
x86_l_54c:
	/* 0x54c: add    rcx,0x31 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 49ULL);
x86_l_550:
	/* 0x550: jmp    135 <tail_no_service_ipv4+0x135> */
	X86_SIM_X86_JMP(0x550, 0x135, x86_l_135);
x86_l_555:
	/* 0x555: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_558:
	/* 0x558: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_55a:
	/* 0x55a: cmp    r15d,0x24 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 36ULL);
x86_l_55e:
	/* 0x55e: jb     14e <tail_no_service_ipv4+0x14e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x55e, 0x14e, x86_l_14e);
x86_l_564:
	/* 0x564: lea    rdi,[rcx+0x34] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_568:
	/* 0x568: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_56b:
	/* 0x56b: jbe    576 <tail_no_service_ipv4+0x576> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x56b, 0x576, x86_l_576);
x86_l_56d:
	/* 0x56d: add    rcx,0x33 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 51ULL);
x86_l_571:
	/* 0x571: jmp    111 <tail_no_service_ipv4+0x111> */
	X86_SIM_X86_JMP(0x571, 0x111, x86_l_111);
x86_l_576:
	/* 0x576: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_579:
	/* 0x579: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_57b:
	/* 0x57b: cmp    r15d,0x26 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 38ULL);
x86_l_57f:
	/* 0x57f: jb     14e <tail_no_service_ipv4+0x14e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x57f, 0x14e, x86_l_14e);
x86_l_585:
	/* 0x585: lea    rsi,[rcx+0x36] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 54ULL);
x86_l_589:
	/* 0x589: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_58c:
	/* 0x58c: jbe    597 <tail_no_service_ipv4+0x597> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x58c, 0x597, x86_l_597);
x86_l_58e:
	/* 0x58e: add    rcx,0x35 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 53ULL);
x86_l_592:
	/* 0x592: jmp    135 <tail_no_service_ipv4+0x135> */
	X86_SIM_X86_JMP(0x592, 0x135, x86_l_135);
x86_l_597:
	/* 0x597: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_59a:
	/* 0x59a: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_59c:
	/* 0x59c: cmp    r15d,0x28 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 40ULL);
x86_l_5a0:
	/* 0x5a0: jb     14e <tail_no_service_ipv4+0x14e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x5a0, 0x14e, x86_l_14e);
x86_l_5a6:
	/* 0x5a6: lea    rdi,[rcx+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_5aa:
	/* 0x5aa: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_5ad:
	/* 0x5ad: jbe    5b8 <tail_no_service_ipv4+0x5b8> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x5ad, 0x5b8, x86_l_5b8);
x86_l_5af:
	/* 0x5af: add    rcx,0x37 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 55ULL);
x86_l_5b3:
	/* 0x5b3: jmp    111 <tail_no_service_ipv4+0x111> */
	X86_SIM_X86_JMP(0x5b3, 0x111, x86_l_111);
x86_l_5b8:
	/* 0x5b8: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5bb:
	/* 0x5bb: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_5bd:
	/* 0x5bd: cmp    r15d,0x2a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 42ULL);
x86_l_5c1:
	/* 0x5c1: jb     14e <tail_no_service_ipv4+0x14e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x5c1, 0x14e, x86_l_14e);
x86_l_5c7:
	/* 0x5c7: lea    rsi,[rcx+0x3a] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 58ULL);
x86_l_5cb:
	/* 0x5cb: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_5ce:
	/* 0x5ce: jbe    5d9 <tail_no_service_ipv4+0x5d9> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x5ce, 0x5d9, x86_l_5d9);
x86_l_5d0:
	/* 0x5d0: add    rcx,0x39 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 57ULL);
x86_l_5d4:
	/* 0x5d4: jmp    135 <tail_no_service_ipv4+0x135> */
	X86_SIM_X86_JMP(0x5d4, 0x135, x86_l_135);
x86_l_5d9:
	/* 0x5d9: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5dc:
	/* 0x5dc: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_5de:
	/* 0x5de: cmp    r15d,0x2c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 44ULL);
x86_l_5e2:
	/* 0x5e2: jb     14e <tail_no_service_ipv4+0x14e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x5e2, 0x14e, x86_l_14e);
x86_l_5e8:
	/* 0x5e8: lea    rdi,[rcx+0x3c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_5ec:
	/* 0x5ec: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_5ef:
	/* 0x5ef: jbe    5fa <tail_no_service_ipv4+0x5fa> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x5ef, 0x5fa, x86_l_5fa);
x86_l_5f1:
	/* 0x5f1: add    rcx,0x3b */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 59ULL);
x86_l_5f5:
	/* 0x5f5: jmp    111 <tail_no_service_ipv4+0x111> */
	X86_SIM_X86_JMP(0x5f5, 0x111, x86_l_111);
x86_l_5fa:
	/* 0x5fa: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_5fd:
	/* 0x5fd: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_5ff:
	/* 0x5ff: cmp    r15d,0x2e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 46ULL);
x86_l_603:
	/* 0x603: jb     14e <tail_no_service_ipv4+0x14e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x603, 0x14e, x86_l_14e);
x86_l_609:
	/* 0x609: lea    rsi,[rcx+0x3e] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 62ULL);
x86_l_60d:
	/* 0x60d: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_610:
	/* 0x610: jbe    61b <tail_no_service_ipv4+0x61b> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x610, 0x61b, x86_l_61b);
x86_l_612:
	/* 0x612: add    rcx,0x3d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 61ULL);
x86_l_616:
	/* 0x616: jmp    135 <tail_no_service_ipv4+0x135> */
	X86_SIM_X86_JMP(0x616, 0x135, x86_l_135);
x86_l_61b:
	/* 0x61b: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_61e:
	/* 0x61e: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_620:
	/* 0x620: cmp    r15d,0x30 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 48ULL);
x86_l_624:
	/* 0x624: jb     14e <tail_no_service_ipv4+0x14e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x624, 0x14e, x86_l_14e);
x86_l_62a:
	/* 0x62a: lea    rdi,[rcx+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_62e:
	/* 0x62e: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_631:
	/* 0x631: jbe    63c <tail_no_service_ipv4+0x63c> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x631, 0x63c, x86_l_63c);
x86_l_633:
	/* 0x633: add    rcx,0x3f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 63ULL);
x86_l_637:
	/* 0x637: jmp    111 <tail_no_service_ipv4+0x111> */
	X86_SIM_X86_JMP(0x637, 0x111, x86_l_111);
x86_l_63c:
	/* 0x63c: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_63f:
	/* 0x63f: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_641:
	/* 0x641: cmp    r15d,0x32 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 50ULL);
x86_l_645:
	/* 0x645: jb     14e <tail_no_service_ipv4+0x14e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x645, 0x14e, x86_l_14e);
x86_l_64b:
	/* 0x64b: lea    rsi,[rcx+0x42] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 66ULL);
x86_l_64f:
	/* 0x64f: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_652:
	/* 0x652: jbe    65d <tail_no_service_ipv4+0x65d> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x652, 0x65d, x86_l_65d);
x86_l_654:
	/* 0x654: add    rcx,0x41 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 65ULL);
x86_l_658:
	/* 0x658: jmp    135 <tail_no_service_ipv4+0x135> */
	X86_SIM_X86_JMP(0x658, 0x135, x86_l_135);
x86_l_65d:
	/* 0x65d: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_660:
	/* 0x660: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_662:
	/* 0x662: cmp    r15d,0x34 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 52ULL);
x86_l_666:
	/* 0x666: jb     14e <tail_no_service_ipv4+0x14e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x666, 0x14e, x86_l_14e);
x86_l_66c:
	/* 0x66c: lea    rdi,[rcx+0x44] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_670:
	/* 0x670: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_673:
	/* 0x673: jbe    67e <tail_no_service_ipv4+0x67e> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x673, 0x67e, x86_l_67e);
x86_l_675:
	/* 0x675: add    rcx,0x43 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 67ULL);
x86_l_679:
	/* 0x679: jmp    111 <tail_no_service_ipv4+0x111> */
	X86_SIM_X86_JMP(0x679, 0x111, x86_l_111);
x86_l_67e:
	/* 0x67e: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_681:
	/* 0x681: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_683:
	/* 0x683: cmp    r15d,0x36 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 54ULL);
x86_l_687:
	/* 0x687: jb     14e <tail_no_service_ipv4+0x14e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x687, 0x14e, x86_l_14e);
x86_l_68d:
	/* 0x68d: lea    rsi,[rcx+0x46] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 70ULL);
x86_l_691:
	/* 0x691: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_694:
	/* 0x694: jbe    69f <tail_no_service_ipv4+0x69f> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x694, 0x69f, x86_l_69f);
x86_l_696:
	/* 0x696: add    rcx,0x45 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 69ULL);
x86_l_69a:
	/* 0x69a: jmp    135 <tail_no_service_ipv4+0x135> */
	X86_SIM_X86_JMP(0x69a, 0x135, x86_l_135);
x86_l_69f:
	/* 0x69f: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_6a2:
	/* 0x6a2: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_6a4:
	/* 0x6a4: cmp    r15d,0x38 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 56ULL);
x86_l_6a8:
	/* 0x6a8: jb     14e <tail_no_service_ipv4+0x14e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x6a8, 0x14e, x86_l_14e);
x86_l_6ae:
	/* 0x6ae: lea    rdi,[rcx+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_6b2:
	/* 0x6b2: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_6b5:
	/* 0x6b5: jbe    6c0 <tail_no_service_ipv4+0x6c0> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x6b5, 0x6c0, x86_l_6c0);
x86_l_6b7:
	/* 0x6b7: add    rcx,0x47 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 71ULL);
x86_l_6bb:
	/* 0x6bb: jmp    111 <tail_no_service_ipv4+0x111> */
	X86_SIM_X86_JMP(0x6bb, 0x111, x86_l_111);
x86_l_6c0:
	/* 0x6c0: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_6c3:
	/* 0x6c3: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_6c5:
	/* 0x6c5: cmp    r15d,0x3a */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 58ULL);
x86_l_6c9:
	/* 0x6c9: jb     14e <tail_no_service_ipv4+0x14e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x6c9, 0x14e, x86_l_14e);
x86_l_6cf:
	/* 0x6cf: lea    rsi,[rcx+0x4a] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 74ULL);
x86_l_6d3:
	/* 0x6d3: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_6d6:
	/* 0x6d6: jbe    6e1 <tail_no_service_ipv4+0x6e1> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x6d6, 0x6e1, x86_l_6e1);
x86_l_6d8:
	/* 0x6d8: add    rcx,0x49 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 73ULL);
x86_l_6dc:
	/* 0x6dc: jmp    135 <tail_no_service_ipv4+0x135> */
	X86_SIM_X86_JMP(0x6dc, 0x135, x86_l_135);
x86_l_6e1:
	/* 0x6e1: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_6e4:
	/* 0x6e4: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_6e6:
	/* 0x6e6: cmp    r15d,0x3c */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 60ULL);
x86_l_6ea:
	/* 0x6ea: jb     14e <tail_no_service_ipv4+0x14e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x6ea, 0x14e, x86_l_14e);
x86_l_6f0:
	/* 0x6f0: lea    rdi,[rcx+0x4c] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_6f4:
	/* 0x6f4: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_6f7:
	/* 0x6f7: jbe    702 <tail_no_service_ipv4+0x702> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x6f7, 0x702, x86_l_702);
x86_l_6f9:
	/* 0x6f9: add    rcx,0x4b */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 75ULL);
x86_l_6fd:
	/* 0x6fd: jmp    111 <tail_no_service_ipv4+0x111> */
	X86_SIM_X86_JMP(0x6fd, 0x111, x86_l_111);
x86_l_702:
	/* 0x702: movzx  esi,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_705:
	/* 0x705: add    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_707:
	/* 0x707: cmp    r15d,0x3e */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 62ULL);
x86_l_70b:
	/* 0x70b: jb     14e <tail_no_service_ipv4+0x14e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x70b, 0x14e, x86_l_14e);
x86_l_711:
	/* 0x711: lea    rsi,[rcx+0x4e] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 78ULL);
x86_l_715:
	/* 0x715: cmp    rsi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64);
x86_l_718:
	/* 0x718: jbe    723 <tail_no_service_ipv4+0x723> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x718, 0x723, x86_l_723);
x86_l_71a:
	/* 0x71a: add    rcx,0x4d */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 77ULL);
x86_l_71e:
	/* 0x71e: jmp    135 <tail_no_service_ipv4+0x135> */
	X86_SIM_X86_JMP(0x71e, 0x135, x86_l_135);
x86_l_723:
	/* 0x723: movzx  edi,WORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_726:
	/* 0x726: add    eax,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD);
x86_l_728:
	/* 0x728: cmp    r15d,0x40 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 64ULL);
x86_l_72c:
	/* 0x72c: jb     14e <tail_no_service_ipv4+0x14e> */
	X86_SIM_X86_JCC(X86_CC_B, 0x72c, 0x14e, x86_l_14e);
x86_l_732:
	/* 0x732: lea    rdi,[rcx+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_736:
	/* 0x736: cmp    rdi,rdx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64);
x86_l_739:
	/* 0x739: jbe    744 <tail_no_service_ipv4+0x744> */
	X86_SIM_X86_JCC(X86_CC_BE, 0x739, 0x744, x86_l_744);
x86_l_73b:
	/* 0x73b: add    rcx,0x4f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_64, X86_ALU_ADD, 79ULL);
x86_l_73f:
	/* 0x73f: jmp    111 <tail_no_service_ipv4+0x111> */
	X86_SIM_X86_JMP(0x73f, 0x111, x86_l_111);
x86_l_744:
	/* 0x744: movzx  ecx,WORD PTR [rsi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 0ULL);
x86_l_747:
	/* 0x747: jmp    119 <tail_no_service_ipv4+0x119> */
	X86_SIM_X86_JMP(0x747, 0x119, x86_l_119);
x86_l_74c:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
