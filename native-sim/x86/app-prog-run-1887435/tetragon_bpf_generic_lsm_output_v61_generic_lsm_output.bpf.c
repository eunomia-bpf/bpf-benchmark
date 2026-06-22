extern char execve_map;
extern char ima_hash_map;
extern char override_tasks;
extern char policy_stats;
extern char process_call_heap;
extern char tcpmon_map;
extern char tg_conf_map;
extern char tg_rb_events;
extern char tg_stats_map;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_generic_lsm_output_v61_generic_lsm_output_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: sub    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
x86_l_4:
	/* 0x4: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_7:
	/* 0x7: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_f:
	/* 0xf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_14:
	/* 0x14: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_1b:
	/* 0x1b: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_20:
	/* 0x20: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22:
	/* 0x22: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_25:
	/* 0x25: je     338 <generic_lsm_output+0x338> */
	X86_SIM_X86_JCC(X86_CC_E, 0x25, 0x338, x86_l_338);
x86_l_2b:
	/* 0x2b: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_2e:
	/* 0x2e: test   BYTE PTR [rax+0x1],0x8 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_TEST_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 4294967304ULL);
x86_l_32:
	/* 0x32: je     9e <generic_lsm_output+0x9e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x32, 0x9e, x86_l_9e);
x86_l_34:
	/* 0x34: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_39:
	/* 0x39: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3b:
	/* 0x3b: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3f:
	/* 0x3f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_44:
	/* 0x44: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&ima_hash_map)));
x86_l_4b:
	/* 0x4b: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_4e:
	/* 0x4e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_50:
	/* 0x50: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_53:
	/* 0x53: je     9e <generic_lsm_output+0x9e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x53, 0x9e, x86_l_9e);
x86_l_55:
	/* 0x55: cmp    BYTE PTR [rax],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2ULL);
x86_l_58:
	/* 0x58: jne    9e <generic_lsm_output+0x9e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x58, 0x9e, x86_l_9e);
x86_l_5a:
	/* 0x5a: cmp    DWORD PTR [r14+0x4],0x3fbd */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179885501ULL);
x86_l_62:
	/* 0x62: ja     8d <generic_lsm_output+0x8d> */
	X86_SIM_X86_JCC(X86_CC_A, 0x62, 0x8d, x86_l_8d);
x86_l_64:
	/* 0x64: mov    ecx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_69:
	/* 0x69: mov    edx,DWORD PTR [r14+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_6d:
	/* 0x6d: and    edx,0x3fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 16383ULL);
x86_l_73:
	/* 0x73: lea    rdi,[r14+rdx*1] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RDX, 0), 0ULL);
x86_l_77:
	/* 0x77: add    rdi,0x90 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 144ULL);
x86_l_7e:
	/* 0x7e: mov    esi,0x42 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 66ULL);
x86_l_83:
	/* 0x83: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_86:
	/* 0x86: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_88:
	/* 0x88: add    DWORD PTR [r14+0x4],0x42 */
	X86_SIM_L_EXEC_ALU_MEM_IMM(X86_R14, X86_WIDTH_32, (X86_MEM_AUX(X86_REG_NONE, 0) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 17179869250ULL);
x86_l_8d:
	/* 0x8d: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_92:
	/* 0x92: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&ima_hash_map)));
x86_l_99:
	/* 0x99: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_9c:
	/* 0x9c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9e:
	/* 0x9e: cmp    BYTE PTR [r14+0x5f08],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 104487964377088ULL);
x86_l_a6:
	/* 0xa6: je     2ef <generic_lsm_output+0x2ef> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa6, 0x2ef, x86_l_2ef);
x86_l_ac:
	/* 0xac: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_b4:
	/* 0xb4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b9:
	/* 0xb9: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_c0:
	/* 0xc0: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c5:
	/* 0xc5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c7:
	/* 0xc7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ca:
	/* 0xca: je     2ef <generic_lsm_output+0x2ef> */
	X86_SIM_X86_JCC(X86_CC_E, 0xca, 0x2ef, x86_l_2ef);
x86_l_d0:
	/* 0xd0: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_d3:
	/* 0xd3: cmp    QWORD PTR [rax+0x5ee8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104350525423616ULL);
x86_l_db:
	/* 0xdb: je     1e1 <generic_lsm_output+0x1e1> */
	X86_SIM_X86_JCC(X86_CC_E, 0xdb, 0x1e1, x86_l_1e1);
x86_l_e1:
	/* 0xe1: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_e6:
	/* 0xe6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e8:
	/* 0xe8: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_eb:
	/* 0xeb: shr    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_ef:
	/* 0xef: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_f4:
	/* 0xf4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f6:
	/* 0xf6: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_f9:
	/* 0xf9: mov    DWORD PTR [rsp],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fd:
	/* 0xfd: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_102:
	/* 0x102: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_109:
	/* 0x109: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_10c:
	/* 0x10c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10e:
	/* 0x10e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_111:
	/* 0x111: je     1e1 <generic_lsm_output+0x1e1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x111, 0x1e1, x86_l_1e1);
x86_l_117:
	/* 0x117: mov    rcx,QWORD PTR [r15+0xd48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3400ULL);
x86_l_11e:
	/* 0x11e: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_121:
	/* 0x121: je     1e1 <generic_lsm_output+0x1e1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x121, 0x1e1, x86_l_1e1);
x86_l_127:
	/* 0x127: mov    r9,QWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_12b:
	/* 0x12b: mov    r10,QWORD PTR [rcx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_12f:
	/* 0x12f: mov    r11,QWORD PTR [rcx+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_133:
	/* 0x133: mov    r8,QWORD PTR [rcx+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_137:
	/* 0x137: mov    rdi,QWORD PTR [rcx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_13b:
	/* 0x13b: mov    rsi,QWORD PTR [rcx+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_13f:
	/* 0x13f: mov    rdx,QWORD PTR [rcx+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_143:
	/* 0x143: mov    rcx,QWORD PTR [rcx+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_147:
	/* 0x147: mov    r9d,DWORD PTR [r9+0x1a8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 424ULL);
x86_l_14e:
	/* 0x14e: mov    DWORD PTR [rax+0x28],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_152:
	/* 0x152: mov    r9d,DWORD PTR [r10+0x470] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_R10, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1136ULL);
x86_l_159:
	/* 0x159: mov    DWORD PTR [rax+0x2c],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_15d:
	/* 0x15d: mov    r9d,DWORD PTR [r11+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_161:
	/* 0x161: mov    DWORD PTR [rax+0x30],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_165:
	/* 0x165: mov    r9,QWORD PTR [r15+0xb38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2872ULL);
x86_l_16c:
	/* 0x16c: test   r9,r9 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R9, X86_R9, X86_WIDTH_64);
x86_l_16f:
	/* 0x16f: je     18a <generic_lsm_output+0x18a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x16f, 0x18a, x86_l_18a);
x86_l_171:
	/* 0x171: movsxd r10,DWORD PTR [r9+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R10, X86_R9, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 4ULL);
x86_l_175:
	/* 0x175: shl    r10,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_179:
	/* 0x179: mov    r9,QWORD PTR [r9+r10*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_R10, 0), 144ULL);
x86_l_181:
	/* 0x181: mov    r9d,DWORD PTR [r9+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_188:
	/* 0x188: jmp    18d <generic_lsm_output+0x18d> */
	X86_SIM_X86_JMP(0x188, 0x18d, x86_l_18d);
x86_l_18a:
	/* 0x18a: xor    r9d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R9, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18d:
	/* 0x18d: mov    DWORD PTR [rax+0x34],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_191:
	/* 0x191: mov    r8d,DWORD PTR [r8+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_198:
	/* 0x198: mov    DWORD PTR [rax+0x38],r8d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_19c:
	/* 0x19c: mov    edi,DWORD PTR [rdi+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_1a2:
	/* 0x1a2: mov    DWORD PTR [rax+0x3c],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_1a5:
	/* 0x1a5: mov    esi,DWORD PTR [rsi+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1a8:
	/* 0x1a8: mov    DWORD PTR [rax+0x40],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1ab:
	/* 0x1ab: mov    edx,DWORD PTR [rdx+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ae:
	/* 0x1ae: mov    DWORD PTR [rax+0x44],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_1b1:
	/* 0x1b1: mov    ecx,DWORD PTR [rcx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b4:
	/* 0x1b4: mov    DWORD PTR [rax+0x48],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1b7:
	/* 0x1b7: mov    rcx,QWORD PTR [r15+0xa50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2640ULL);
x86_l_1be:
	/* 0x1be: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_1c1:
	/* 0x1c1: je     1da <generic_lsm_output+0x1da> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1c1, 0x1da, x86_l_1da);
x86_l_1c3:
	/* 0x1c3: mov    rcx,QWORD PTR [rcx+0x4a0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1184ULL);
x86_l_1ca:
	/* 0x1ca: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_1cd:
	/* 0x1cd: je     1da <generic_lsm_output+0x1da> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1cd, 0x1da, x86_l_1da);
x86_l_1cf:
	/* 0x1cf: mov    ecx,DWORD PTR [rcx+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_1d5:
	/* 0x1d5: mov    DWORD PTR [rax+0x4c],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_1d8:
	/* 0x1d8: jmp    1e1 <generic_lsm_output+0x1e1> */
	X86_SIM_X86_JMP(0x1d8, 0x1e1, x86_l_1e1);
x86_l_1da:
	/* 0x1da: mov    DWORD PTR [rax+0x4c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 326417514496ULL);
x86_l_1e1:
	/* 0x1e1: cmp    QWORD PTR [r14+0x5ef0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104384885161984ULL);
x86_l_1e9:
	/* 0x1e9: je     23c <generic_lsm_output+0x23c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1e9, 0x23c, x86_l_23c);
x86_l_1eb:
	/* 0x1eb: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1f0:
	/* 0x1f0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f2:
	/* 0x1f2: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_1f5:
	/* 0x1f5: shr    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_1f9:
	/* 0x1f9: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_1fe:
	/* 0x1fe: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_200:
	/* 0x200: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_203:
	/* 0x203: mov    DWORD PTR [rsp],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_207:
	/* 0x207: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_20c:
	/* 0x20c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_213:
	/* 0x213: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_216:
	/* 0x216: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_218:
	/* 0x218: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_21b:
	/* 0x21b: je     23c <generic_lsm_output+0x23c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x21b, 0x23c, x86_l_23c);
x86_l_21d:
	/* 0x21d: mov    rcx,QWORD PTR [r15+0xce0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3296ULL);
x86_l_224:
	/* 0x224: mov    rdx,QWORD PTR [rcx+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_228:
	/* 0x228: mov    QWORD PTR [rax+0x58],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_22c:
	/* 0x22c: mov    rdx,QWORD PTR [rcx+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_230:
	/* 0x230: mov    QWORD PTR [rax+0x60],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_234:
	/* 0x234: mov    rcx,QWORD PTR [rcx+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_238:
	/* 0x238: mov    QWORD PTR [rax+0x50],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_23c:
	/* 0x23c: mov    eax,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 144ULL);
x86_l_241:
	/* 0x241: add    eax,DWORD PTR [r14+0x4] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 4ULL);
x86_l_245:
	/* 0x245: and    eax,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_24a:
	/* 0x24a: cmp    eax,0x2328 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9000ULL);
x86_l_24f:
	/* 0x24f: mov    r15d,0x2328 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R15, X86_WIDTH_32, 9000ULL);
x86_l_255:
	/* 0x255: cmovb  r15d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R15, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_259:
	/* 0x259: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_261:
	/* 0x261: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_266:
	/* 0x266: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_conf_map)));
x86_l_26d:
	/* 0x26d: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_272:
	/* 0x272: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_274:
	/* 0x274: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_277:
	/* 0x277: je     2b2 <generic_lsm_output+0x2b2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x277, 0x2b2, x86_l_2b2);
x86_l_279:
	/* 0x279: cmp    BYTE PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_27d:
	/* 0x27d: je     2b2 <generic_lsm_output+0x2b2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x27d, 0x2b2, x86_l_2b2);
x86_l_27f:
	/* 0x27f: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_284:
	/* 0x284: mov    rsi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tcpmon_map)));
x86_l_28b:
	/* 0x28b: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_290:
	/* 0x290: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_293:
	/* 0x293: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_296:
	/* 0x296: mov    r8,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R15, X86_WIDTH_64);
x86_l_299:
	/* 0x299: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29b:
	/* 0x29b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_29e:
	/* 0x29e: js     392 <generic_lsm_output+0x392> */
	X86_SIM_X86_JCC(X86_CC_S, 0x29e, 0x392, x86_l_392);
x86_l_2a4:
	/* 0x2a4: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2ab:
	/* 0x2ab: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2b0:
	/* 0x2b0: jmp    2d9 <generic_lsm_output+0x2d9> */
	X86_SIM_X86_JMP(0x2b0, 0x2d9, x86_l_2d9);
x86_l_2b2:
	/* 0x2b2: mov    eax,0x82 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 130ULL);
x86_l_2b7:
	/* 0x2b7: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_rb_events)));
x86_l_2be:
	/* 0x2be: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_2c1:
	/* 0x2c1: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_2c4:
	/* 0x2c4: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2c6:
	/* 0x2c6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2c8:
	/* 0x2c8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2cb:
	/* 0x2cb: js     343 <generic_lsm_output+0x343> */
	X86_SIM_X86_JCC(X86_CC_S, 0x2cb, 0x343, x86_l_343);
x86_l_2cd:
	/* 0x2cd: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2d4:
	/* 0x2d4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2d9:
	/* 0x2d9: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_stats)));
x86_l_2e0:
	/* 0x2e0: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_2e3:
	/* 0x2e3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e5:
	/* 0x2e5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2e8:
	/* 0x2e8: je     2ef <generic_lsm_output+0x2ef> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2e8, 0x2ef, x86_l_2ef);
x86_l_2ea:
	/* 0x2ea: inc QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 8ULL);
x86_l_2ef:
	/* 0x2ef: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_2f4:
	/* 0x2f4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2f6:
	/* 0x2f6: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2fa:
	/* 0x2fa: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2ff:
	/* 0x2ff: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&override_tasks)));
x86_l_306:
	/* 0x306: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_309:
	/* 0x309: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_30b:
	/* 0x30b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_30e:
	/* 0x30e: je     338 <generic_lsm_output+0x338> */
	X86_SIM_X86_JCC(X86_CC_E, 0x30e, 0x338, x86_l_338);
x86_l_310:
	/* 0x310: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_313:
	/* 0x313: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_318:
	/* 0x318: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&override_tasks)));
x86_l_31f:
	/* 0x31f: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_322:
	/* 0x322: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_324:
	/* 0x324: mov    ecx,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_326:
	/* 0x326: lea    eax,[rcx-0x1] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 18446744073709551615ULL);
x86_l_329:
	/* 0x329: cmp    eax,0xfffff000 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4294963200ULL);
x86_l_32e:
	/* 0x32e: mov    eax,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4294967295ULL);
x86_l_333:
	/* 0x333: cmovae eax,ecx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RCX, X86_WIDTH_32, X86_CC_AE);
x86_l_336:
	/* 0x336: jmp    33a <generic_lsm_output+0x33a> */
	X86_SIM_X86_JMP(0x336, 0x33a, x86_l_33a);
x86_l_338:
	/* 0x338: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_33a:
	/* 0x33a: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_33e:
	/* 0x33e: jmp    446 <generic_lsm_output+0x446> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_343:
	/* 0x343: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_346:
	/* 0x346: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_34d:
	/* 0x34d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_352:
	/* 0x352: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_359:
	/* 0x359: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_35c:
	/* 0x35c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35e:
	/* 0x35e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_361:
	/* 0x361: je     2ef <generic_lsm_output+0x2ef> */
	X86_SIM_X86_JCC(X86_CC_E, 0x361, 0x2ef, x86_l_2ef);
x86_l_363:
	/* 0x363: cmp    rbx,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_367:
	/* 0x367: jg     3d7 <generic_lsm_output+0x3d7> */
	X86_SIM_X86_JCC(X86_CC_G, 0x367, 0x3d7, x86_l_3d7);
x86_l_369:
	/* 0x369: cmp    rbx,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_36d:
	/* 0x36d: je     419 <generic_lsm_output+0x419> */
	X86_SIM_X86_JCC(X86_CC_E, 0x36d, 0x419, x86_l_419);
x86_l_373:
	/* 0x373: cmp    rbx,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_377:
	/* 0x377: je     3c8 <generic_lsm_output+0x3c8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x377, 0x3c8, x86_l_3c8);
x86_l_379:
	/* 0x379: cmp    rbx,0xfffffffffffffff0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551600ULL);
x86_l_37d:
	/* 0x37d: jne    40a <generic_lsm_output+0x40a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x37d, 0x40a, x86_l_40a);
x86_l_383:
	/* 0x383: add    rax,0x398 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 920ULL);
x86_l_389:
	/* 0x389: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_38d:
	/* 0x38d: jmp    2ef <generic_lsm_output+0x2ef> */
	X86_SIM_X86_JMP(0x38d, 0x2ef, x86_l_2ef);
x86_l_392:
	/* 0x392: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_395:
	/* 0x395: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_39c:
	/* 0x39c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_3a1:
	/* 0x3a1: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_3a8:
	/* 0x3a8: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_3ab:
	/* 0x3ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3ad:
	/* 0x3ad: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_3b0:
	/* 0x3b0: je     2ef <generic_lsm_output+0x2ef> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3b0, 0x2ef, x86_l_2ef);
x86_l_3b6:
	/* 0x3b6: cmp    rbx,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_3ba:
	/* 0x3ba: jg     3f8 <generic_lsm_output+0x3f8> */
	X86_SIM_X86_JCC(X86_CC_G, 0x3ba, 0x3f8, x86_l_3f8);
x86_l_3bc:
	/* 0x3bc: cmp    rbx,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_3c0:
	/* 0x3c0: je     419 <generic_lsm_output+0x419> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3c0, 0x419, x86_l_419);
x86_l_3c2:
	/* 0x3c2: cmp    rbx,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_3c6:
	/* 0x3c6: jne    379 <generic_lsm_output+0x379> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3c6, 0x379, x86_l_379);
x86_l_3c8:
	/* 0x3c8: add    rax,0x3a0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 928ULL);
x86_l_3ce:
	/* 0x3ce: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_3d2:
	/* 0x3d2: jmp    2ef <generic_lsm_output+0x2ef> */
	X86_SIM_X86_JMP(0x3d2, 0x2ef, x86_l_2ef);
x86_l_3d7:
	/* 0x3d7: cmp    rbx,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_3db:
	/* 0x3db: je     428 <generic_lsm_output+0x428> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3db, 0x428, x86_l_428);
x86_l_3dd:
	/* 0x3dd: cmp    rbx,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_3e1:
	/* 0x3e1: je     437 <generic_lsm_output+0x437> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3e1, 0x437, x86_l_437);
x86_l_3e3:
	/* 0x3e3: cmp    rbx,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_3e7:
	/* 0x3e7: jne    40a <generic_lsm_output+0x40a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x3e7, 0x40a, x86_l_40a);
x86_l_3e9:
	/* 0x3e9: add    rax,0x388 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 904ULL);
x86_l_3ef:
	/* 0x3ef: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_3f3:
	/* 0x3f3: jmp    2ef <generic_lsm_output+0x2ef> */
	X86_SIM_X86_JMP(0x3f3, 0x2ef, x86_l_2ef);
x86_l_3f8:
	/* 0x3f8: cmp    rbx,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_3fc:
	/* 0x3fc: je     428 <generic_lsm_output+0x428> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3fc, 0x428, x86_l_428);
x86_l_3fe:
	/* 0x3fe: cmp    rbx,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_402:
	/* 0x402: je     437 <generic_lsm_output+0x437> */
	X86_SIM_X86_JCC(X86_CC_E, 0x402, 0x437, x86_l_437);
x86_l_404:
	/* 0x404: cmp    rbx,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_408:
	/* 0x408: je     3e9 <generic_lsm_output+0x3e9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x408, 0x3e9, x86_l_3e9);
x86_l_40a:
	/* 0x40a: add    rax,0x380 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 896ULL);
x86_l_410:
	/* 0x410: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_414:
	/* 0x414: jmp    2ef <generic_lsm_output+0x2ef> */
	X86_SIM_X86_JMP(0x414, 0x2ef, x86_l_2ef);
x86_l_419:
	/* 0x419: add    rax,0x3a8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 936ULL);
x86_l_41f:
	/* 0x41f: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_423:
	/* 0x423: jmp    2ef <generic_lsm_output+0x2ef> */
	X86_SIM_X86_JMP(0x423, 0x2ef, x86_l_2ef);
x86_l_428:
	/* 0x428: add    rax,0x3b0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 944ULL);
x86_l_42e:
	/* 0x42e: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_432:
	/* 0x432: jmp    2ef <generic_lsm_output+0x2ef> */
	X86_SIM_X86_JMP(0x432, 0x2ef, x86_l_2ef);
x86_l_437:
	/* 0x437: add    rax,0x390 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 912ULL);
x86_l_43d:
	/* 0x43d: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_441:
	/* 0x441: jmp    2ef <generic_lsm_output+0x2ef> */
	X86_SIM_X86_JMP(0x441, 0x2ef, x86_l_2ef);
x86_l_446:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
