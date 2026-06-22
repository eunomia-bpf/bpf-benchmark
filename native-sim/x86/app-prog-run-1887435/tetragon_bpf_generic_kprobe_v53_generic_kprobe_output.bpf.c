extern char execve_map;
extern char policy_stats;
extern char process_call_heap;
extern char tcpmon_map;
extern char tg_stats_map;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_generic_kprobe_v53_generic_kprobe_output_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_1:
	/* 0x1: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_4:
	/* 0x4: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_c:
	/* 0xc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_11:
	/* 0x11: mov    rdi,QWORD PTR [rip+0x1fb97] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&process_call_heap)));
x86_l_18:
	/* 0x18: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_1d:
	/* 0x1d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f:
	/* 0x1f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_22:
	/* 0x22: je     2aa <generic_kprobe_output+0x2aa> */
	X86_SIM_X86_JCC(X86_CC_E, 0x22, 0x2aa, x86_l_2aa);
x86_l_28:
	/* 0x28: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_2b:
	/* 0x2b: cmp    QWORD PTR [rax+0x5ee8],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104350525423616ULL);
x86_l_33:
	/* 0x33: je     147 <generic_kprobe_output+0x147> */
	X86_SIM_X86_JCC(X86_CC_E, 0x33, 0x147, x86_l_147);
x86_l_39:
	/* 0x39: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_3e:
	/* 0x3e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_40:
	/* 0x40: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_43:
	/* 0x43: shr    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_47:
	/* 0x47: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_4c:
	/* 0x4c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4e:
	/* 0x4e: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_51:
	/* 0x51: mov    DWORD PTR [rsp],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_55:
	/* 0x55: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_5a:
	/* 0x5a: mov    rdi,QWORD PTR [rip+0x1fb97] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_61:
	/* 0x61: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_64:
	/* 0x64: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_66:
	/* 0x66: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_69:
	/* 0x69: je     147 <generic_kprobe_output+0x147> */
	X86_SIM_X86_JCC(X86_CC_E, 0x69, 0x147, x86_l_147);
x86_l_6f:
	/* 0x6f: mov    rcx,QWORD PTR [r15+0xd48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3400ULL);
x86_l_76:
	/* 0x76: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_79:
	/* 0x79: je     147 <generic_kprobe_output+0x147> */
	X86_SIM_X86_JCC(X86_CC_E, 0x79, 0x147, x86_l_147);
x86_l_7f:
	/* 0x7f: mov    r9,QWORD PTR [rcx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_83:
	/* 0x83: mov    r10,QWORD PTR [rcx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R10, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_87:
	/* 0x87: mov    r11,QWORD PTR [rcx+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R11, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_8b:
	/* 0x8b: mov    r8,QWORD PTR [rcx+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_8f:
	/* 0x8f: mov    rdi,QWORD PTR [rcx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_93:
	/* 0x93: mov    rsi,QWORD PTR [rcx+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_97:
	/* 0x97: mov    rdx,QWORD PTR [rcx+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_9b:
	/* 0x9b: mov    rcx,QWORD PTR [rcx+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_9f:
	/* 0x9f: mov    r9d,DWORD PTR [r9+0x1a8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 424ULL);
x86_l_a6:
	/* 0xa6: mov    DWORD PTR [rax+0x28],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_aa:
	/* 0xaa: mov    r9d,DWORD PTR [r10+0x470] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_R10, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 1136ULL);
x86_l_b1:
	/* 0xb1: mov    DWORD PTR [rax+0x2c],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 44ULL);
x86_l_b5:
	/* 0xb5: mov    r9d,DWORD PTR [r11+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_R11, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b9:
	/* 0xb9: mov    DWORD PTR [rax+0x30],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_bd:
	/* 0xbd: mov    r9,QWORD PTR [r15+0xb38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2872ULL);
x86_l_c4:
	/* 0xc4: test   r9,r9 */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_R9, X86_R9, X86_WIDTH_64);
x86_l_c7:
	/* 0xc7: je     e2 <generic_kprobe_output+0xe2> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc7, 0xe2, x86_l_e2);
x86_l_c9:
	/* 0xc9: movsxd r10,DWORD PTR [r9+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_R10, X86_R9, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 4ULL);
x86_l_cd:
	/* 0xcd: shl    r10,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R10, X86_WIDTH_64, X86_ALU_SHL, 4ULL);
x86_l_d1:
	/* 0xd1: mov    r9,QWORD PTR [r9+r10*1+0x90] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_R9, X86_WIDTH_64, X86_MEM_AUX(X86_R10, 0), 144ULL);
x86_l_d9:
	/* 0xd9: mov    r9d,DWORD PTR [r9+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R9, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_e0:
	/* 0xe0: jmp    e5 <generic_kprobe_output+0xe5> */
	X86_SIM_X86_JMP(0xe0, 0xe5, x86_l_e5);
x86_l_e2:
	/* 0xe2: xor    r9d,r9d */
	X86_SIM_L_EXEC_ALU_REG(X86_R9, X86_R9, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e5:
	/* 0xe5: mov    DWORD PTR [rax+0x34],r9d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R9, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_e9:
	/* 0xe9: mov    r8d,DWORD PTR [r8+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R8, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_f0:
	/* 0xf0: mov    DWORD PTR [rax+0x38],r8d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_R8, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_f4:
	/* 0xf4: mov    edi,DWORD PTR [rdi+0xa8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 168ULL);
x86_l_fa:
	/* 0xfa: mov    DWORD PTR [rax+0x3c],edi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 60ULL);
x86_l_fd:
	/* 0xfd: mov    esi,DWORD PTR [rsi+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_100:
	/* 0x100: mov    DWORD PTR [rax+0x40],esi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RSI, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_103:
	/* 0x103: mov    edx,DWORD PTR [rdx+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_106:
	/* 0x106: mov    DWORD PTR [rax+0x44],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_109:
	/* 0x109: mov    ecx,DWORD PTR [rcx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10c:
	/* 0x10c: mov    DWORD PTR [rax+0x48],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_10f:
	/* 0x10f: mov    rcx,QWORD PTR [r15+0xa50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 2640ULL);
x86_l_116:
	/* 0x116: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_119:
	/* 0x119: je     140 <generic_kprobe_output+0x140> */
	X86_SIM_X86_JCC(X86_CC_E, 0x119, 0x140, x86_l_140);
x86_l_11b:
	/* 0x11b: mov    rcx,QWORD PTR [rcx+0x4a0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1184ULL);
x86_l_122:
	/* 0x122: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_125:
	/* 0x125: je     266 <generic_kprobe_output+0x266> */
	X86_SIM_X86_JCC(X86_CC_E, 0x125, 0x266, x86_l_266);
x86_l_12b:
	/* 0x12b: mov    ecx,DWORD PTR [rcx+0xe8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 232ULL);
x86_l_131:
	/* 0x131: mov    DWORD PTR [rax+0x4c],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_134:
	/* 0x134: cmp    QWORD PTR [r14+0x5ef0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104384885161984ULL);
x86_l_13c:
	/* 0x13c: jne    151 <generic_kprobe_output+0x151> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x13c, 0x151, x86_l_151);
x86_l_13e:
	/* 0x13e: jmp    1a2 <generic_kprobe_output+0x1a2> */
	X86_SIM_X86_JMP(0x13e, 0x1a2, x86_l_1a2);
x86_l_140:
	/* 0x140: mov    DWORD PTR [rax+0x4c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 326417514496ULL);
x86_l_147:
	/* 0x147: cmp    QWORD PTR [r14+0x5ef0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104384885161984ULL);
x86_l_14f:
	/* 0x14f: je     1a2 <generic_kprobe_output+0x1a2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14f, 0x1a2, x86_l_1a2);
x86_l_151:
	/* 0x151: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_156:
	/* 0x156: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_158:
	/* 0x158: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_15b:
	/* 0x15b: shr    r13,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_15f:
	/* 0x15f: mov    eax,0x23 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 35ULL);
x86_l_164:
	/* 0x164: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_166:
	/* 0x166: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_169:
	/* 0x169: mov    DWORD PTR [rsp],r13d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16d:
	/* 0x16d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_172:
	/* 0x172: mov    rdi,QWORD PTR [rip+0x1fb97] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&execve_map)));
x86_l_179:
	/* 0x179: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_17c:
	/* 0x17c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_17e:
	/* 0x17e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_181:
	/* 0x181: je     1a2 <generic_kprobe_output+0x1a2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x181, 0x1a2, x86_l_1a2);
x86_l_183:
	/* 0x183: mov    rcx,QWORD PTR [r15+0xce0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 3296ULL);
x86_l_18a:
	/* 0x18a: mov    rdx,QWORD PTR [rcx+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_18e:
	/* 0x18e: mov    QWORD PTR [rax+0x58],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_192:
	/* 0x192: mov    rdx,QWORD PTR [rcx+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_196:
	/* 0x196: mov    QWORD PTR [rax+0x60],rdx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_19a:
	/* 0x19a: mov    rcx,QWORD PTR [rcx+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_19e:
	/* 0x19e: mov    QWORD PTR [rax+0x50],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RAX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1a2:
	/* 0x1a2: mov    eax,0x90 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 144ULL);
x86_l_1a7:
	/* 0x1a7: add    eax,DWORD PTR [r14+0x4] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_32, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 4ULL);
x86_l_1ab:
	/* 0x1ab: and    eax,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_1b0:
	/* 0x1b0: cmp    eax,0x2328 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 9000ULL);
x86_l_1b5:
	/* 0x1b5: mov    r8d,0x2328 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 9000ULL);
x86_l_1bb:
	/* 0x1bb: cmovb  r8d,eax */
	X86_SIM_L_EXEC_CMOV(X86_R8, X86_RAX, X86_WIDTH_32, X86_CC_B);
x86_l_1bf:
	/* 0x1bf: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_1c4:
	/* 0x1c4: mov    rsi,QWORD PTR [rip+0x1fb97] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tcpmon_map)));
x86_l_1cb:
	/* 0x1cb: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_1d0:
	/* 0x1d0: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1d3:
	/* 0x1d3: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_1d6:
	/* 0x1d6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d8:
	/* 0x1d8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1db:
	/* 0x1db: js     208 <generic_kprobe_output+0x208> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1db, 0x208, x86_l_208);
x86_l_1dd:
	/* 0x1dd: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1e4:
	/* 0x1e4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1e9:
	/* 0x1e9: mov    rdi,QWORD PTR [rip+0x1fb97] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&policy_stats)));
x86_l_1f0:
	/* 0x1f0: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_1f3:
	/* 0x1f3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1f5:
	/* 0x1f5: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1f8:
	/* 0x1f8: je     2aa <generic_kprobe_output+0x2aa> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1f8, 0x2aa, x86_l_2aa);
x86_l_1fe:
	/* 0x1fe: inc QWORD PTR [rax+0x8] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 8ULL);
x86_l_203:
	/* 0x203: jmp    2aa <generic_kprobe_output+0x2aa> */
	X86_SIM_X86_JMP(0x203, 0x2aa, x86_l_2aa);
x86_l_208:
	/* 0x208: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_20b:
	/* 0x20b: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_212:
	/* 0x212: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_217:
	/* 0x217: mov    rdi,QWORD PTR [rip+0x1fb97] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_21e:
	/* 0x21e: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_221:
	/* 0x221: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_223:
	/* 0x223: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_226:
	/* 0x226: je     2aa <generic_kprobe_output+0x2aa> */
	X86_SIM_X86_JCC(X86_CC_E, 0x226, 0x2aa, x86_l_2aa);
x86_l_22c:
	/* 0x22c: cmp    rbx,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_230:
	/* 0x230: jg     24c <generic_kprobe_output+0x24c> */
	X86_SIM_X86_JCC(X86_CC_G, 0x230, 0x24c, x86_l_24c);
x86_l_232:
	/* 0x232: cmp    rbx,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_236:
	/* 0x236: je     280 <generic_kprobe_output+0x280> */
	X86_SIM_X86_JCC(X86_CC_E, 0x236, 0x280, x86_l_280);
x86_l_238:
	/* 0x238: cmp    rbx,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_23c:
	/* 0x23c: je     298 <generic_kprobe_output+0x298> */
	X86_SIM_X86_JCC(X86_CC_E, 0x23c, 0x298, x86_l_298);
x86_l_23e:
	/* 0x23e: cmp    rbx,0xfffffffffffffff0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551600ULL);
x86_l_242:
	/* 0x242: jne    290 <generic_kprobe_output+0x290> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x242, 0x290, x86_l_290);
x86_l_244:
	/* 0x244: add    rax,0x2f0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 752ULL);
x86_l_24a:
	/* 0x24a: jmp    2a6 <generic_kprobe_output+0x2a6> */
	X86_SIM_X86_JMP(0x24a, 0x2a6, x86_l_2a6);
x86_l_24c:
	/* 0x24c: cmp    rbx,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_250:
	/* 0x250: je     288 <generic_kprobe_output+0x288> */
	X86_SIM_X86_JCC(X86_CC_E, 0x250, 0x288, x86_l_288);
x86_l_252:
	/* 0x252: cmp    rbx,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_256:
	/* 0x256: je     2a0 <generic_kprobe_output+0x2a0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x256, 0x2a0, x86_l_2a0);
x86_l_258:
	/* 0x258: cmp    rbx,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_25c:
	/* 0x25c: jne    290 <generic_kprobe_output+0x290> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x25c, 0x290, x86_l_290);
x86_l_25e:
	/* 0x25e: add    rax,0x2e0 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 736ULL);
x86_l_264:
	/* 0x264: jmp    2a6 <generic_kprobe_output+0x2a6> */
	X86_SIM_X86_JMP(0x264, 0x2a6, x86_l_2a6);
x86_l_266:
	/* 0x266: mov    DWORD PTR [rax+0x4c],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 326417514496ULL);
x86_l_26d:
	/* 0x26d: cmp    QWORD PTR [r14+0x5ef0],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_R14, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104384885161984ULL);
x86_l_275:
	/* 0x275: jne    151 <generic_kprobe_output+0x151> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x275, 0x151, x86_l_151);
x86_l_27b:
	/* 0x27b: jmp    1a2 <generic_kprobe_output+0x1a2> */
	X86_SIM_X86_JMP(0x27b, 0x1a2, x86_l_1a2);
x86_l_280:
	/* 0x280: add    rax,0x300 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 768ULL);
x86_l_286:
	/* 0x286: jmp    2a6 <generic_kprobe_output+0x2a6> */
	X86_SIM_X86_JMP(0x286, 0x2a6, x86_l_2a6);
x86_l_288:
	/* 0x288: add    rax,0x308 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 776ULL);
x86_l_28e:
	/* 0x28e: jmp    2a6 <generic_kprobe_output+0x2a6> */
	X86_SIM_X86_JMP(0x28e, 0x2a6, x86_l_2a6);
x86_l_290:
	/* 0x290: add    rax,0x2d8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 728ULL);
x86_l_296:
	/* 0x296: jmp    2a6 <generic_kprobe_output+0x2a6> */
	X86_SIM_X86_JMP(0x296, 0x2a6, x86_l_2a6);
x86_l_298:
	/* 0x298: add    rax,0x2f8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 760ULL);
x86_l_29e:
	/* 0x29e: jmp    2a6 <generic_kprobe_output+0x2a6> */
	X86_SIM_X86_JMP(0x29e, 0x2a6, x86_l_2a6);
x86_l_2a0:
	/* 0x2a0: add    rax,0x2e8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 744ULL);
x86_l_2a6:
	/* 0x2a6: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2aa:
	/* 0x2aa: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2ac:
	/* 0x2ac: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2b0:
	/* 0x2b0: jmp    2b5 <generic_kprobe_output+0x2b5> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_2b5:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
