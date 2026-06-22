extern char execve_map;
extern char override_tasks;
extern char policy_stats;
extern char process_call_heap;
extern char tcpmon_map;
extern char tg_stats_map;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_generic_lsm_output_generic_lsm_output_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: sub    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
x86_l_4:
	/* 0x4: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_7:
	/* 0x7: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_f:
	/* 0xf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14:
	/* 0x14: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_1b:
	/* 0x1b: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_20:
	/* 0x20: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22:
	/* 0x22: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_25:
	/* 0x25: je     30c <generic_lsm_output+0x30c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x25, 0x30c, x86_l_30c);
x86_l_2b:
	/* 0x2b: cmp    BYTE PTR [rax+0x5f08],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104487964377088ULL);
x86_l_32:
	/* 0x32: je     2be <generic_lsm_output+0x2be> */
	X86_SIM_X86_JCC(X86_CC_E, 0x32, 0x2be, x86_l_2be);
x86_l_38:
	/* 0x38: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_40:
	/* 0x40: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_45:
	/* 0x45: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_4c:
	/* 0x4c: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_51:
	/* 0x51: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_53:
	/* 0x53: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_56:
	/* 0x56: je     2be <generic_lsm_output+0x2be> */
	X86_SIM_X86_JCC(X86_CC_E, 0x56, 0x2be, x86_l_2be);
x86_l_5c:
	/* 0x5c: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_5f:
	/* 0x5f: cmp    QWORD PTR [rax+0x5ee8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104350525423616ULL);
x86_l_67:
	/* 0x67: je     170 <generic_lsm_output+0x170> */
	X86_SIM_X86_JCC(X86_CC_E, 0x67, 0x170, x86_l_170);
x86_l_6d:
	/* 0x6d: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_72:
	/* 0x72: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_74:
	/* 0x74: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_77:
	/* 0x77: shr    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_7b:
	/* 0x7b: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_80:
	/* 0x80: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_82:
	/* 0x82: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_85:
	/* 0x85: mov    DWORD PTR [rsp+0x8],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8a:
	/* 0x8a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_8f:
	/* 0x8f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_96:
	/* 0x96: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9b:
	/* 0x9b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9d:
	/* 0x9d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a0:
	/* 0xa0: je     170 <generic_lsm_output+0x170> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa0, 0x170, x86_l_170);
x86_l_a6:
	/* 0xa6: mov    rcx,QWORD PTR [r15+0xd48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3400ULL);
x86_l_ad:
	/* 0xad: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_b0:
	/* 0xb0: je     170 <generic_lsm_output+0x170> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb0, 0x170, x86_l_170);
x86_l_b6:
	/* 0xb6: mov    r9,QWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ba:
	/* 0xba: mov    r10,QWORD PTR [rcx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_be:
	/* 0xbe: mov    r11,QWORD PTR [rcx+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c2:
	/* 0xc2: mov    r8,QWORD PTR [rcx+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c6:
	/* 0xc6: mov    rdi,QWORD PTR [rcx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_ca:
	/* 0xca: mov    rsi,QWORD PTR [rcx+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ce:
	/* 0xce: mov    rdx,QWORD PTR [rcx+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_d2:
	/* 0xd2: mov    rcx,QWORD PTR [rcx+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_d6:
	/* 0xd6: mov    r9d,DWORD PTR [r9+0x1a8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 424ULL);
x86_l_dd:
	/* 0xdd: mov    DWORD PTR [rax+0x28],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_e1:
	/* 0xe1: mov    r9d,DWORD PTR [r10+0x470] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_R10, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1136ULL);
x86_l_e8:
	/* 0xe8: mov    DWORD PTR [rax+0x2c],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_ec:
	/* 0xec: mov    r9d,DWORD PTR [r11+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f0:
	/* 0xf0: mov    DWORD PTR [rax+0x30],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_f4:
	/* 0xf4: mov    r9,QWORD PTR [r15+0xb38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2872ULL);
x86_l_fb:
	/* 0xfb: test   r9,r9 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R9, X86_R9, X86_WIDTH_64);
x86_l_fe:
	/* 0xfe: je     119 <generic_lsm_output+0x119> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfe, 0x119, x86_l_119);
x86_l_100:
	/* 0x100: movsxd r10,DWORD PTR [r9+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R10, X86_R9, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 4ULL);
x86_l_104:
	/* 0x104: shl    r10,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_108:
	/* 0x108: mov    r9,QWORD PTR [r9+r10*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_R10, 0), 144ULL);
x86_l_110:
	/* 0x110: mov    r9d,DWORD PTR [r9+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_117:
	/* 0x117: jmp    11c <generic_lsm_output+0x11c> */
	X86_SIM_X86_JMP(0x117, 0x11c, x86_l_11c);
x86_l_119:
	/* 0x119: xor    r9d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R9, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11c:
	/* 0x11c: mov    DWORD PTR [rax+0x34],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_120:
	/* 0x120: mov    r8d,DWORD PTR [r8+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_127:
	/* 0x127: mov    DWORD PTR [rax+0x38],r8d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_12b:
	/* 0x12b: mov    edi,DWORD PTR [rdi+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_131:
	/* 0x131: mov    DWORD PTR [rax+0x3c],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_134:
	/* 0x134: mov    esi,DWORD PTR [rsi+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_137:
	/* 0x137: mov    DWORD PTR [rax+0x40],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_13a:
	/* 0x13a: mov    edx,DWORD PTR [rdx+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_13d:
	/* 0x13d: mov    DWORD PTR [rax+0x44],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_140:
	/* 0x140: mov    ecx,DWORD PTR [rcx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_143:
	/* 0x143: mov    DWORD PTR [rax+0x48],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_146:
	/* 0x146: mov    rcx,QWORD PTR [r15+0xa50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2640ULL);
x86_l_14d:
	/* 0x14d: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_150:
	/* 0x150: je     169 <generic_lsm_output+0x169> */
	X86_SIM_X86_JCC(X86_CC_E, 0x150, 0x169, x86_l_169);
x86_l_152:
	/* 0x152: mov    rcx,QWORD PTR [rcx+0x4a0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1184ULL);
x86_l_159:
	/* 0x159: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_15c:
	/* 0x15c: je     169 <generic_lsm_output+0x169> */
	X86_SIM_X86_JCC(X86_CC_E, 0x15c, 0x169, x86_l_169);
x86_l_15e:
	/* 0x15e: mov    ecx,DWORD PTR [rcx+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_164:
	/* 0x164: mov    DWORD PTR [rax+0x4c],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_167:
	/* 0x167: jmp    170 <generic_lsm_output+0x170> */
	X86_SIM_X86_JMP(0x167, 0x170, x86_l_170);
x86_l_169:
	/* 0x169: mov    DWORD PTR [rax+0x4c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 326417514496ULL);
x86_l_170:
	/* 0x170: cmp    QWORD PTR [r14+0x5ef0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104384885161984ULL);
x86_l_178:
	/* 0x178: je     1ce <generic_lsm_output+0x1ce> */
	X86_SIM_X86_JCC(X86_CC_E, 0x178, 0x1ce, x86_l_1ce);
x86_l_17a:
	/* 0x17a: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_17f:
	/* 0x17f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_181:
	/* 0x181: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_184:
	/* 0x184: shr    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_188:
	/* 0x188: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_18d:
	/* 0x18d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_18f:
	/* 0x18f: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_192:
	/* 0x192: mov    DWORD PTR [rsp+0x8],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_197:
	/* 0x197: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_19c:
	/* 0x19c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_1a3:
	/* 0x1a3: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a8:
	/* 0x1a8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1aa:
	/* 0x1aa: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1ad:
	/* 0x1ad: je     1ce <generic_lsm_output+0x1ce> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1ad, 0x1ce, x86_l_1ce);
x86_l_1af:
	/* 0x1af: mov    rcx,QWORD PTR [r15+0xce0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3296ULL);
x86_l_1b6:
	/* 0x1b6: mov    rdx,QWORD PTR [rcx+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1ba:
	/* 0x1ba: mov    QWORD PTR [rax+0x58],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1be:
	/* 0x1be: mov    rdx,QWORD PTR [rcx+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1c2:
	/* 0x1c2: mov    QWORD PTR [rax+0x60],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1c6:
	/* 0x1c6: mov    rcx,QWORD PTR [rcx+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1ca:
	/* 0x1ca: mov    QWORD PTR [rax+0x50],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1ce:
	/* 0x1ce: mov    eax,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 144ULL);
x86_l_1d3:
	/* 0x1d3: add    eax,DWORD PTR [r14+0x4] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 4ULL);
x86_l_1d7:
	/* 0x1d7: and    eax,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_1dc:
	/* 0x1dc: cmp    eax,0x2328 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9000ULL);
x86_l_1e1:
	/* 0x1e1: mov    r8d,0x2328 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 9000ULL);
x86_l_1e7:
	/* 0x1e7: cmovb  r8d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R8, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_1eb:
	/* 0x1eb: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_1f0:
	/* 0x1f0: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tcpmon_map)));
x86_l_1f7:
	/* 0x1f7: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_1fc:
	/* 0x1fc: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1ff:
	/* 0x1ff: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_202:
	/* 0x202: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_204:
	/* 0x204: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_207:
	/* 0x207: js     237 <generic_lsm_output+0x237> */
	X86_SIM_X86_JCC(X86_CC_S, 0x207, 0x237, x86_l_237);
x86_l_209:
	/* 0x209: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_211:
	/* 0x211: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_216:
	/* 0x216: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_stats)));
x86_l_21d:
	/* 0x21d: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_222:
	/* 0x222: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_224:
	/* 0x224: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_227:
	/* 0x227: je     2be <generic_lsm_output+0x2be> */
	X86_SIM_X86_JCC(X86_CC_E, 0x227, 0x2be, x86_l_2be);
x86_l_22d:
	/* 0x22d: inc QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 8ULL);
x86_l_232:
	/* 0x232: jmp    2be <generic_lsm_output+0x2be> */
	X86_SIM_X86_JMP(0x232, 0x2be, x86_l_2be);
x86_l_237:
	/* 0x237: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_23a:
	/* 0x23a: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_242:
	/* 0x242: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_247:
	/* 0x247: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_24e:
	/* 0x24e: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_253:
	/* 0x253: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_255:
	/* 0x255: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_258:
	/* 0x258: je     2be <generic_lsm_output+0x2be> */
	X86_SIM_X86_JCC(X86_CC_E, 0x258, 0x2be, x86_l_2be);
x86_l_25a:
	/* 0x25a: cmp    rbx,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_25e:
	/* 0x25e: jg     27a <generic_lsm_output+0x27a> */
	X86_SIM_X86_JCC(X86_CC_G, 0x25e, 0x27a, x86_l_27a);
x86_l_260:
	/* 0x260: cmp    rbx,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_264:
	/* 0x264: je     294 <generic_lsm_output+0x294> */
	X86_SIM_X86_JCC(X86_CC_E, 0x264, 0x294, x86_l_294);
x86_l_266:
	/* 0x266: cmp    rbx,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_26a:
	/* 0x26a: je     2ac <generic_lsm_output+0x2ac> */
	X86_SIM_X86_JCC(X86_CC_E, 0x26a, 0x2ac, x86_l_2ac);
x86_l_26c:
	/* 0x26c: cmp    rbx,0xfffffffffffffff0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551600ULL);
x86_l_270:
	/* 0x270: jne    2a4 <generic_lsm_output+0x2a4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x270, 0x2a4, x86_l_2a4);
x86_l_272:
	/* 0x272: add    rax,0x398 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 920ULL);
x86_l_278:
	/* 0x278: jmp    2ba <generic_lsm_output+0x2ba> */
	X86_SIM_X86_JMP(0x278, 0x2ba, x86_l_2ba);
x86_l_27a:
	/* 0x27a: cmp    rbx,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_27e:
	/* 0x27e: je     29c <generic_lsm_output+0x29c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x27e, 0x29c, x86_l_29c);
x86_l_280:
	/* 0x280: cmp    rbx,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_284:
	/* 0x284: je     2b4 <generic_lsm_output+0x2b4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x284, 0x2b4, x86_l_2b4);
x86_l_286:
	/* 0x286: cmp    rbx,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_28a:
	/* 0x28a: jne    2a4 <generic_lsm_output+0x2a4> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x28a, 0x2a4, x86_l_2a4);
x86_l_28c:
	/* 0x28c: add    rax,0x388 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 904ULL);
x86_l_292:
	/* 0x292: jmp    2ba <generic_lsm_output+0x2ba> */
	X86_SIM_X86_JMP(0x292, 0x2ba, x86_l_2ba);
x86_l_294:
	/* 0x294: add    rax,0x3a8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 936ULL);
x86_l_29a:
	/* 0x29a: jmp    2ba <generic_lsm_output+0x2ba> */
	X86_SIM_X86_JMP(0x29a, 0x2ba, x86_l_2ba);
x86_l_29c:
	/* 0x29c: add    rax,0x3b0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 944ULL);
x86_l_2a2:
	/* 0x2a2: jmp    2ba <generic_lsm_output+0x2ba> */
	X86_SIM_X86_JMP(0x2a2, 0x2ba, x86_l_2ba);
x86_l_2a4:
	/* 0x2a4: add    rax,0x380 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 896ULL);
x86_l_2aa:
	/* 0x2aa: jmp    2ba <generic_lsm_output+0x2ba> */
	X86_SIM_X86_JMP(0x2aa, 0x2ba, x86_l_2ba);
x86_l_2ac:
	/* 0x2ac: add    rax,0x3a0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 928ULL);
x86_l_2b2:
	/* 0x2b2: jmp    2ba <generic_lsm_output+0x2ba> */
	X86_SIM_X86_JMP(0x2b2, 0x2ba, x86_l_2ba);
x86_l_2b4:
	/* 0x2b4: add    rax,0x390 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 912ULL);
x86_l_2ba:
	/* 0x2ba: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2be:
	/* 0x2be: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2c3:
	/* 0x2c3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c5:
	/* 0x2c5: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2ca:
	/* 0x2ca: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2cf:
	/* 0x2cf: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&override_tasks)));
x86_l_2d6:
	/* 0x2d6: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2db:
	/* 0x2db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2dd:
	/* 0x2dd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2e0:
	/* 0x2e0: je     30c <generic_lsm_output+0x30c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2e0, 0x30c, x86_l_30c);
x86_l_2e2:
	/* 0x2e2: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_2e5:
	/* 0x2e5: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_2ea:
	/* 0x2ea: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&override_tasks)));
x86_l_2f1:
	/* 0x2f1: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2f6:
	/* 0x2f6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f8:
	/* 0x2f8: mov    ecx,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fa:
	/* 0x2fa: lea    eax,[rcx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_2fd:
	/* 0x2fd: cmp    eax,0xfffff000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294963200ULL);
x86_l_302:
	/* 0x302: mov    eax,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_307:
	/* 0x307: cmovae eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_AE);
x86_l_30a:
	/* 0x30a: jmp    30e <generic_lsm_output+0x30e> */
	X86_SIM_X86_JMP(0x30a, 0x30e, x86_l_30e);
x86_l_30c:
	/* 0x30c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_30e:
	/* 0x30e: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_312:
	/* 0x312: jmp    317 <generic_lsm_output+0x317> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_317:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
