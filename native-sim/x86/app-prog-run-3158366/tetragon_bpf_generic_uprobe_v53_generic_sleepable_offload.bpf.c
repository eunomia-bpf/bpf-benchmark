extern char regs_map;
extern char sleepable_offload;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_generic_uprobe_v53_generic_sleepable_offload_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 136ULL);
x86_l_a:
	/* 0xa: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_12:
	/* 0x12: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14:
	/* 0x14: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1c:
	/* 0x1c: mov    rdi,QWORD PTR [rip+0x35a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sleepable_offload)));
x86_l_23:
	/* 0x23: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_2b:
	/* 0x2b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_30:
	/* 0x30: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32:
	/* 0x32: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_35:
	/* 0x35: je     1bad <generic_sleepable_offload+0x1bad> */
	X86_SIM_X86_JCC(X86_CC_E, 0x35, 0x1bad, x86_l_1bad);
x86_l_3b:
	/* 0x3b: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_3e:
	/* 0x3e: mov    rdi,QWORD PTR [rip+0x35a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sleepable_offload)));
x86_l_45:
	/* 0x45: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_4d:
	/* 0x4d: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_52:
	/* 0x52: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_54:
	/* 0x54: mov    rdi,QWORD PTR [rip+0x35a7] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&regs_map)));
x86_l_5b:
	/* 0x5b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_60:
	/* 0x60: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_63:
	/* 0x63: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_65:
	/* 0x65: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_68:
	/* 0x68: je     1bad <generic_sleepable_offload+0x1bad> */
	X86_SIM_X86_JCC(X86_CC_E, 0x68, 0x1bad, x86_l_1bad);
x86_l_6e:
	/* 0x6e: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_71:
	/* 0x71: lea    rax,[rbx+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_78:
	/* 0x78: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7c:
	/* 0x7c: lea    rax,[rbx+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_83:
	/* 0x83: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_88:
	/* 0x88: lea    rbp,[rbx+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_8c:
	/* 0x8c: lea    rax,[rbx+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_90:
	/* 0x90: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_95:
	/* 0x95: lea    rax,[rbx+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_99:
	/* 0x99: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_9e:
	/* 0x9e: lea    rax,[rbx+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_a2:
	/* 0xa2: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a7:
	/* 0xa7: lea    rax,[rbx+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_ab:
	/* 0xab: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_b0:
	/* 0xb0: lea    rax,[rbx+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_b4:
	/* 0xb4: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b9:
	/* 0xb9: lea    rax,[rbx+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_bd:
	/* 0xbd: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_c2:
	/* 0xc2: lea    rax,[rbx+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_c6:
	/* 0xc6: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_cb:
	/* 0xcb: lea    rax,[rbx+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_cf:
	/* 0xcf: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_d4:
	/* 0xd4: lea    rax,[rbx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_d8:
	/* 0xd8: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_dd:
	/* 0xdd: lea    rax,[rbx+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e1:
	/* 0xe1: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_e6:
	/* 0xe6: lea    rax,[rbx+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ea:
	/* 0xea: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ef:
	/* 0xef: mov    r14,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R13, X86_WIDTH_64);
x86_l_f2:
	/* 0xf2: add    r14,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_f6:
	/* 0xf6: lea    rax,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_fa:
	/* 0xfa: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_ff:
	/* 0xff: lea    rax,[rbx+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_103:
	/* 0x103: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_108:
	/* 0x108: xor    r12d,r12d */
	X86_SIM_L_EXEC_ALU_REG(X86_R12, X86_R12, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10b:
	/* 0x10b: lea    r15,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_110:
	/* 0x110: jmp    12a <generic_sleepable_offload+0x12a> */
	X86_SIM_X86_JMP(0x110, 0x12a, x86_l_12a);
x86_l_112:
	/* 0x112: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_117:
	/* 0x117: mov    BYTE PTR [rcx],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_119:
	/* 0x119: inc    r12 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R12, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_11c:
	/* 0x11c: add    r14,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_120:
	/* 0x120: cmp    r12,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R12, X86_WIDTH_64, 18ULL);
x86_l_124:
	/* 0x124: je     1bad <generic_sleepable_offload+0x1bad> */
	X86_SIM_X86_JCC(X86_CC_E, 0x124, 0x1bad, x86_l_1bad);
x86_l_12a:
	/* 0x12a: mov    eax,DWORD PTR [r13+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_131:
	/* 0x131: cmp    r12,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_134:
	/* 0x134: jae    1bad <generic_sleepable_offload+0x1bad> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x134, 0x1bad, x86_l_1bad);
x86_l_13a:
	/* 0x13a: movzx  eax,BYTE PTR [r14-0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551608ULL);
x86_l_13f:
	/* 0x13f: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_142:
	/* 0x142: jg     1ae <generic_sleepable_offload+0x1ae> */
	X86_SIM_X86_JCC(X86_CC_G, 0x142, 0x1ae, x86_l_1ae);
x86_l_144:
	/* 0x144: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_147:
	/* 0x147: je     21c <generic_sleepable_offload+0x21c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x147, 0x21c, x86_l_21c);
x86_l_14d:
	/* 0x14d: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_150:
	/* 0x150: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x150, 0x119, x86_l_119);
x86_l_152:
	/* 0x152: movzx  eax,WORD PTR [r14-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551610ULL);
x86_l_157:
	/* 0x157: movzx  ecx,BYTE PTR [r14-0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551614ULL);
x86_l_15c:
	/* 0x15c: rorx   edx,eax,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RAX, X86_WIDTH_32, 0, 3ULL);
x86_l_162:
	/* 0x162: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_165:
	/* 0x165: jle    2e1 <generic_sleepable_offload+0x2e1> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x165, 0x2e1, x86_l_2e1);
x86_l_16b:
	/* 0x16b: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_16e:
	/* 0x16e: jle    3bd <generic_sleepable_offload+0x3bd> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x16e, 0x3bd, x86_l_3bd);
x86_l_174:
	/* 0x174: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_177:
	/* 0x177: jle    706 <generic_sleepable_offload+0x706> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x177, 0x706, x86_l_706);
x86_l_17d:
	/* 0x17d: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_180:
	/* 0x180: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_183:
	/* 0x183: je     71f <generic_sleepable_offload+0x71f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x183, 0x71f, x86_l_71f);
x86_l_189:
	/* 0x189: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_18e:
	/* 0x18e: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_191:
	/* 0x191: je     71f <generic_sleepable_offload+0x71f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x191, 0x71f, x86_l_71f);
x86_l_197:
	/* 0x197: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_19c:
	/* 0x19c: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_19f:
	/* 0x19f: jne    732 <generic_sleepable_offload+0x732> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x19f, 0x732, x86_l_732);
x86_l_1a5:
	/* 0x1a5: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a9:
	/* 0x1a9: jmp    71f <generic_sleepable_offload+0x71f> */
	X86_SIM_X86_JMP(0x1a9, 0x71f, x86_l_71f);
x86_l_1ae:
	/* 0x1ae: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1b1:
	/* 0x1b1: je     285 <generic_sleepable_offload+0x285> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1b1, 0x285, x86_l_285);
x86_l_1b7:
	/* 0x1b7: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ba:
	/* 0x1ba: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1ba, 0x119, x86_l_119);
x86_l_1c0:
	/* 0x1c0: movzx  ecx,WORD PTR [r14-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551610ULL);
x86_l_1c5:
	/* 0x1c5: movzx  eax,BYTE PTR [r14-0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551614ULL);
x86_l_1ca:
	/* 0x1ca: rorx   ecx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_1d0:
	/* 0x1d0: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_1d3:
	/* 0x1d3: jle    316 <generic_sleepable_offload+0x316> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x1d3, 0x316, x86_l_316);
x86_l_1d9:
	/* 0x1d9: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_1dc:
	/* 0x1dc: jle    3ec <generic_sleepable_offload+0x3ec> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x1dc, 0x3ec, x86_l_3ec);
x86_l_1e2:
	/* 0x1e2: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_1e5:
	/* 0x1e5: jle    907 <generic_sleepable_offload+0x907> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x1e5, 0x907, x86_l_907);
x86_l_1eb:
	/* 0x1eb: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1ee:
	/* 0x1ee: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_1f1:
	/* 0x1f1: je     920 <generic_sleepable_offload+0x920> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1f1, 0x920, x86_l_920);
x86_l_1f7:
	/* 0x1f7: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1fc:
	/* 0x1fc: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1ff:
	/* 0x1ff: je     920 <generic_sleepable_offload+0x920> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1ff, 0x920, x86_l_920);
x86_l_205:
	/* 0x205: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_20a:
	/* 0x20a: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_20d:
	/* 0x20d: jne    933 <generic_sleepable_offload+0x933> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x20d, 0x933, x86_l_933);
x86_l_213:
	/* 0x213: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_217:
	/* 0x217: jmp    920 <generic_sleepable_offload+0x920> */
	X86_SIM_X86_JMP(0x217, 0x920, x86_l_920);
x86_l_21c:
	/* 0x21c: movzx  edx,WORD PTR [r14-0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551612ULL);
x86_l_221:
	/* 0x221: movzx  ecx,BYTE PTR [r14-0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551615ULL);
x86_l_226:
	/* 0x226: mov    rax,QWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_229:
	/* 0x229: rorx   edx,edx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RDX, X86_WIDTH_32, 0, 3ULL);
x86_l_22f:
	/* 0x22f: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_232:
	/* 0x232: jle    34b <generic_sleepable_offload+0x34b> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x232, 0x34b, x86_l_34b);
x86_l_238:
	/* 0x238: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_23b:
	/* 0x23b: jle    41b <generic_sleepable_offload+0x41b> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x23b, 0x41b, x86_l_41b);
x86_l_241:
	/* 0x241: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_244:
	/* 0x244: jle    a3a <generic_sleepable_offload+0xa3a> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x244, 0xa3a, x86_l_a3a);
x86_l_24a:
	/* 0x24a: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_24d:
	/* 0x24d: je     1004 <generic_sleepable_offload+0x1004> */
	X86_SIM_X86_JCC(X86_CC_E, 0x24d, 0x1004, x86_l_1004);
x86_l_253:
	/* 0x253: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_256:
	/* 0x256: je     e6c <generic_sleepable_offload+0xe6c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x256, 0xe6c, x86_l_e6c);
x86_l_25c:
	/* 0x25c: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_25f:
	/* 0x25f: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x25f, 0x119, x86_l_119);
x86_l_265:
	/* 0x265: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_268:
	/* 0x268: jg     14f7 <generic_sleepable_offload+0x14f7> */
	X86_SIM_X86_JCC(X86_CC_G, 0x268, 0x14f7, x86_l_14f7);
x86_l_26e:
	/* 0x26e: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_271:
	/* 0x271: je     9b8 <generic_sleepable_offload+0x9b8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x271, 0x9b8, x86_l_9b8);
x86_l_277:
	/* 0x277: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_27a:
	/* 0x27a: je     794 <generic_sleepable_offload+0x794> */
	X86_SIM_X86_JCC(X86_CC_E, 0x27a, 0x794, x86_l_794);
x86_l_280:
	/* 0x280: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x280, 0x119, x86_l_119);
x86_l_285:
	/* 0x285: movzx  eax,WORD PTR [r14-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551610ULL);
x86_l_28a:
	/* 0x28a: movzx  ecx,BYTE PTR [r14-0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551614ULL);
x86_l_28f:
	/* 0x28f: rorx   edx,eax,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RAX, X86_WIDTH_32, 0, 3ULL);
x86_l_295:
	/* 0x295: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_298:
	/* 0x298: jle    388 <generic_sleepable_offload+0x388> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x298, 0x388, x86_l_388);
x86_l_29e:
	/* 0x29e: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_2a1:
	/* 0x2a1: jle    456 <generic_sleepable_offload+0x456> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x2a1, 0x456, x86_l_456);
x86_l_2a7:
	/* 0x2a7: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_2aa:
	/* 0x2aa: jle    a74 <generic_sleepable_offload+0xa74> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x2aa, 0xa74, x86_l_a74);
x86_l_2b0:
	/* 0x2b0: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_2b3:
	/* 0x2b3: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_2b6:
	/* 0x2b6: je     a8d <generic_sleepable_offload+0xa8d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2b6, 0xa8d, x86_l_a8d);
x86_l_2bc:
	/* 0x2bc: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2c1:
	/* 0x2c1: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_2c4:
	/* 0x2c4: je     a8d <generic_sleepable_offload+0xa8d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2c4, 0xa8d, x86_l_a8d);
x86_l_2ca:
	/* 0x2ca: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_2cf:
	/* 0x2cf: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_2d2:
	/* 0x2d2: jne    aa0 <generic_sleepable_offload+0xaa0> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2d2, 0xaa0, x86_l_aa0);
x86_l_2d8:
	/* 0x2d8: mov    rsi,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_2dc:
	/* 0x2dc: jmp    a8d <generic_sleepable_offload+0xa8d> */
	X86_SIM_X86_JMP(0x2dc, 0xa8d, x86_l_a8d);
x86_l_2e1:
	/* 0x2e1: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_2e4:
	/* 0x2e4: jg     485 <generic_sleepable_offload+0x485> */
	X86_SIM_X86_JCC(X86_CC_G, 0x2e4, 0x485, x86_l_485);
x86_l_2ea:
	/* 0x2ea: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_2ed:
	/* 0x2ed: jg     5e8 <generic_sleepable_offload+0x5e8> */
	X86_SIM_X86_JCC(X86_CC_G, 0x2ed, 0x5e8, x86_l_5e8);
x86_l_2f3:
	/* 0x2f3: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_2f6:
	/* 0x2f6: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_2f8:
	/* 0x2f8: je     71f <generic_sleepable_offload+0x71f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2f8, 0x71f, x86_l_71f);
x86_l_2fe:
	/* 0x2fe: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_303:
	/* 0x303: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_308:
	/* 0x308: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_30b:
	/* 0x30b: je     71f <generic_sleepable_offload+0x71f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x30b, 0x71f, x86_l_71f);
x86_l_311:
	/* 0x311: jmp    732 <generic_sleepable_offload+0x732> */
	X86_SIM_X86_JMP(0x311, 0x732, x86_l_732);
x86_l_316:
	/* 0x316: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_319:
	/* 0x319: jg     4b4 <generic_sleepable_offload+0x4b4> */
	X86_SIM_X86_JCC(X86_CC_G, 0x319, 0x4b4, x86_l_4b4);
x86_l_31f:
	/* 0x31f: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_322:
	/* 0x322: jg     60e <generic_sleepable_offload+0x60e> */
	X86_SIM_X86_JCC(X86_CC_G, 0x322, 0x60e, x86_l_60e);
x86_l_328:
	/* 0x328: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_32b:
	/* 0x32b: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_32d:
	/* 0x32d: je     920 <generic_sleepable_offload+0x920> */
	X86_SIM_X86_JCC(X86_CC_E, 0x32d, 0x920, x86_l_920);
x86_l_333:
	/* 0x333: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_338:
	/* 0x338: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_33d:
	/* 0x33d: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_340:
	/* 0x340: je     920 <generic_sleepable_offload+0x920> */
	X86_SIM_X86_JCC(X86_CC_E, 0x340, 0x920, x86_l_920);
x86_l_346:
	/* 0x346: jmp    933 <generic_sleepable_offload+0x933> */
	X86_SIM_X86_JMP(0x346, 0x933, x86_l_933);
x86_l_34b:
	/* 0x34b: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_34e:
	/* 0x34e: jg     4e3 <generic_sleepable_offload+0x4e3> */
	X86_SIM_X86_JCC(X86_CC_G, 0x34e, 0x4e3, x86_l_4e3);
x86_l_354:
	/* 0x354: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_357:
	/* 0x357: jg     869 <generic_sleepable_offload+0x869> */
	X86_SIM_X86_JCC(X86_CC_G, 0x357, 0x869, x86_l_869);
x86_l_35d:
	/* 0x35d: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_35f:
	/* 0x35f: jne    7ba <generic_sleepable_offload+0x7ba> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x35f, 0x7ba, x86_l_7ba);
x86_l_365:
	/* 0x365: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_368:
	/* 0x368: jg     13c5 <generic_sleepable_offload+0x13c5> */
	X86_SIM_X86_JCC(X86_CC_G, 0x368, 0x13c5, x86_l_13c5);
x86_l_36e:
	/* 0x36e: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_371:
	/* 0x371: je     18e5 <generic_sleepable_offload+0x18e5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x371, 0x18e5, x86_l_18e5);
x86_l_377:
	/* 0x377: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_37a:
	/* 0x37a: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x37a, 0x119, x86_l_119);
x86_l_380:
	/* 0x380: mov    WORD PTR [rbx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_383:
	/* 0x383: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x383, 0x119, x86_l_119);
x86_l_388:
	/* 0x388: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_38b:
	/* 0x38b: jg     515 <generic_sleepable_offload+0x515> */
	X86_SIM_X86_JCC(X86_CC_G, 0x38b, 0x515, x86_l_515);
x86_l_391:
	/* 0x391: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_394:
	/* 0x394: jg     680 <generic_sleepable_offload+0x680> */
	X86_SIM_X86_JCC(X86_CC_G, 0x394, 0x680, x86_l_680);
x86_l_39a:
	/* 0x39a: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_39d:
	/* 0x39d: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_39f:
	/* 0x39f: je     a8d <generic_sleepable_offload+0xa8d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x39f, 0xa8d, x86_l_a8d);
x86_l_3a5:
	/* 0x3a5: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_3aa:
	/* 0x3aa: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_3af:
	/* 0x3af: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_3b2:
	/* 0x3b2: je     a8d <generic_sleepable_offload+0xa8d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3b2, 0xa8d, x86_l_a8d);
x86_l_3b8:
	/* 0x3b8: jmp    aa0 <generic_sleepable_offload+0xaa0> */
	X86_SIM_X86_JMP(0x3b8, 0xaa0, x86_l_aa0);
x86_l_3bd:
	/* 0x3bd: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_3c0:
	/* 0x3c0: jg     544 <generic_sleepable_offload+0x544> */
	X86_SIM_X86_JCC(X86_CC_G, 0x3c0, 0x544, x86_l_544);
x86_l_3c6:
	/* 0x3c6: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3cb:
	/* 0x3cb: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3ce:
	/* 0x3ce: je     71f <generic_sleepable_offload+0x71f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3ce, 0x71f, x86_l_71f);
x86_l_3d4:
	/* 0x3d4: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_3d9:
	/* 0x3d9: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_3de:
	/* 0x3de: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_3e1:
	/* 0x3e1: je     71f <generic_sleepable_offload+0x71f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3e1, 0x71f, x86_l_71f);
x86_l_3e7:
	/* 0x3e7: jmp    732 <generic_sleepable_offload+0x732> */
	X86_SIM_X86_JMP(0x3e7, 0x732, x86_l_732);
x86_l_3ec:
	/* 0x3ec: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_3ef:
	/* 0x3ef: jg     56a <generic_sleepable_offload+0x56a> */
	X86_SIM_X86_JCC(X86_CC_G, 0x3ef, 0x56a, x86_l_56a);
x86_l_3f5:
	/* 0x3f5: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3fa:
	/* 0x3fa: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3fd:
	/* 0x3fd: je     920 <generic_sleepable_offload+0x920> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3fd, 0x920, x86_l_920);
x86_l_403:
	/* 0x403: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_408:
	/* 0x408: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_40d:
	/* 0x40d: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_410:
	/* 0x410: je     920 <generic_sleepable_offload+0x920> */
	X86_SIM_X86_JCC(X86_CC_E, 0x410, 0x920, x86_l_920);
x86_l_416:
	/* 0x416: jmp    933 <generic_sleepable_offload+0x933> */
	X86_SIM_X86_JMP(0x416, 0x933, x86_l_933);
x86_l_41b:
	/* 0x41b: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_41e:
	/* 0x41e: jg     590 <generic_sleepable_offload+0x590> */
	X86_SIM_X86_JCC(X86_CC_G, 0x41e, 0x590, x86_l_590);
x86_l_424:
	/* 0x424: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_427:
	/* 0x427: je     dc8 <generic_sleepable_offload+0xdc8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x427, 0xdc8, x86_l_dc8);
x86_l_42d:
	/* 0x42d: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_430:
	/* 0x430: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x430, 0x119, x86_l_119);
x86_l_436:
	/* 0x436: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_439:
	/* 0x439: jg     12f5 <generic_sleepable_offload+0x12f5> */
	X86_SIM_X86_JCC(X86_CC_G, 0x439, 0x12f5, x86_l_12f5);
x86_l_43f:
	/* 0x43f: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_442:
	/* 0x442: je     187c <generic_sleepable_offload+0x187c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x442, 0x187c, x86_l_187c);
x86_l_448:
	/* 0x448: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_44b:
	/* 0x44b: je     b8e <generic_sleepable_offload+0xb8e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x44b, 0xb8e, x86_l_b8e);
x86_l_451:
	/* 0x451: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x451, 0x119, x86_l_119);
x86_l_456:
	/* 0x456: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_459:
	/* 0x459: jg     5c2 <generic_sleepable_offload+0x5c2> */
	X86_SIM_X86_JCC(X86_CC_G, 0x459, 0x5c2, x86_l_5c2);
x86_l_45f:
	/* 0x45f: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_464:
	/* 0x464: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_467:
	/* 0x467: je     a8d <generic_sleepable_offload+0xa8d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x467, 0xa8d, x86_l_a8d);
x86_l_46d:
	/* 0x46d: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_472:
	/* 0x472: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_477:
	/* 0x477: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_47a:
	/* 0x47a: je     a8d <generic_sleepable_offload+0xa8d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x47a, 0xa8d, x86_l_a8d);
x86_l_480:
	/* 0x480: jmp    aa0 <generic_sleepable_offload+0xaa0> */
	X86_SIM_X86_JMP(0x480, 0xaa0, x86_l_aa0);
x86_l_485:
	/* 0x485: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_488:
	/* 0x488: jg     634 <generic_sleepable_offload+0x634> */
	X86_SIM_X86_JCC(X86_CC_G, 0x488, 0x634, x86_l_634);
x86_l_48e:
	/* 0x48e: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_493:
	/* 0x493: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_496:
	/* 0x496: je     71f <generic_sleepable_offload+0x71f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x496, 0x71f, x86_l_71f);
x86_l_49c:
	/* 0x49c: mov    rsi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4a1:
	/* 0x4a1: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_4a6:
	/* 0x4a6: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_4a9:
	/* 0x4a9: je     71f <generic_sleepable_offload+0x71f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4a9, 0x71f, x86_l_71f);
x86_l_4af:
	/* 0x4af: jmp    732 <generic_sleepable_offload+0x732> */
	X86_SIM_X86_JMP(0x4af, 0x732, x86_l_732);
x86_l_4b4:
	/* 0x4b4: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_4b7:
	/* 0x4b7: jg     65a <generic_sleepable_offload+0x65a> */
	X86_SIM_X86_JCC(X86_CC_G, 0x4b7, 0x65a, x86_l_65a);
x86_l_4bd:
	/* 0x4bd: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_4c2:
	/* 0x4c2: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_4c5:
	/* 0x4c5: je     920 <generic_sleepable_offload+0x920> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4c5, 0x920, x86_l_920);
x86_l_4cb:
	/* 0x4cb: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_4d0:
	/* 0x4d0: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_4d5:
	/* 0x4d5: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_4d8:
	/* 0x4d8: je     920 <generic_sleepable_offload+0x920> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4d8, 0x920, x86_l_920);
x86_l_4de:
	/* 0x4de: jmp    933 <generic_sleepable_offload+0x933> */
	X86_SIM_X86_JMP(0x4de, 0x933, x86_l_933);
x86_l_4e3:
	/* 0x4e3: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_4e6:
	/* 0x4e6: jg     6a6 <generic_sleepable_offload+0x6a6> */
	X86_SIM_X86_JCC(X86_CC_G, 0x4e6, 0x6a6, x86_l_6a6);
x86_l_4ec:
	/* 0x4ec: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_4ef:
	/* 0x4ef: je     cb6 <generic_sleepable_offload+0xcb6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4ef, 0xcb6, x86_l_cb6);
x86_l_4f5:
	/* 0x4f5: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_4f8:
	/* 0x4f8: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4f8, 0x119, x86_l_119);
x86_l_4fe:
	/* 0x4fe: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_501:
	/* 0x501: jg     10d3 <generic_sleepable_offload+0x10d3> */
	X86_SIM_X86_JCC(X86_CC_G, 0x501, 0x10d3, x86_l_10d3);
x86_l_507:
	/* 0x507: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_50a:
	/* 0x50a: jne    853 <generic_sleepable_offload+0x853> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x50a, 0x853, x86_l_853);
x86_l_510:
	/* 0x510: jmp    18b9 <generic_sleepable_offload+0x18b9> */
	X86_SIM_X86_JMP(0x510, 0x18b9, x86_l_18b9);
x86_l_515:
	/* 0x515: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_518:
	/* 0x518: jg     6e0 <generic_sleepable_offload+0x6e0> */
	X86_SIM_X86_JCC(X86_CC_G, 0x518, 0x6e0, x86_l_6e0);
x86_l_51e:
	/* 0x51e: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_523:
	/* 0x523: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_526:
	/* 0x526: je     a8d <generic_sleepable_offload+0xa8d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x526, 0xa8d, x86_l_a8d);
x86_l_52c:
	/* 0x52c: mov    rsi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_531:
	/* 0x531: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_536:
	/* 0x536: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_539:
	/* 0x539: je     a8d <generic_sleepable_offload+0xa8d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x539, 0xa8d, x86_l_a8d);
x86_l_53f:
	/* 0x53f: jmp    aa0 <generic_sleepable_offload+0xaa0> */
	X86_SIM_X86_JMP(0x53f, 0xaa0, x86_l_aa0);
x86_l_544:
	/* 0x544: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_549:
	/* 0x549: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_54c:
	/* 0x54c: je     71f <generic_sleepable_offload+0x71f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x54c, 0x71f, x86_l_71f);
x86_l_552:
	/* 0x552: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_557:
	/* 0x557: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_55c:
	/* 0x55c: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_55f:
	/* 0x55f: je     71f <generic_sleepable_offload+0x71f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x55f, 0x71f, x86_l_71f);
x86_l_565:
	/* 0x565: jmp    732 <generic_sleepable_offload+0x732> */
	X86_SIM_X86_JMP(0x565, 0x732, x86_l_732);
x86_l_56a:
	/* 0x56a: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_56f:
	/* 0x56f: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_572:
	/* 0x572: je     920 <generic_sleepable_offload+0x920> */
	X86_SIM_X86_JCC(X86_CC_E, 0x572, 0x920, x86_l_920);
x86_l_578:
	/* 0x578: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_57d:
	/* 0x57d: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_582:
	/* 0x582: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_585:
	/* 0x585: je     920 <generic_sleepable_offload+0x920> */
	X86_SIM_X86_JCC(X86_CC_E, 0x585, 0x920, x86_l_920);
x86_l_58b:
	/* 0x58b: jmp    933 <generic_sleepable_offload+0x933> */
	X86_SIM_X86_JMP(0x58b, 0x933, x86_l_933);
x86_l_590:
	/* 0x590: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_593:
	/* 0x593: je     de4 <generic_sleepable_offload+0xde4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x593, 0xde4, x86_l_de4);
x86_l_599:
	/* 0x599: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_59c:
	/* 0x59c: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x59c, 0x119, x86_l_119);
x86_l_5a2:
	/* 0x5a2: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_5a5:
	/* 0x5a5: jg     1304 <generic_sleepable_offload+0x1304> */
	X86_SIM_X86_JCC(X86_CC_G, 0x5a5, 0x1304, x86_l_1304);
x86_l_5ab:
	/* 0x5ab: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_5ae:
	/* 0x5ae: je     1886 <generic_sleepable_offload+0x1886> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5ae, 0x1886, x86_l_1886);
x86_l_5b4:
	/* 0x5b4: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_5b7:
	/* 0x5b7: je     c03 <generic_sleepable_offload+0xc03> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5b7, 0xc03, x86_l_c03);
x86_l_5bd:
	/* 0x5bd: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x5bd, 0x119, x86_l_119);
x86_l_5c2:
	/* 0x5c2: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_5c7:
	/* 0x5c7: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_5ca:
	/* 0x5ca: je     a8d <generic_sleepable_offload+0xa8d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5ca, 0xa8d, x86_l_a8d);
x86_l_5d0:
	/* 0x5d0: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5d5:
	/* 0x5d5: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_5da:
	/* 0x5da: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_5dd:
	/* 0x5dd: je     a8d <generic_sleepable_offload+0xa8d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5dd, 0xa8d, x86_l_a8d);
x86_l_5e3:
	/* 0x5e3: jmp    aa0 <generic_sleepable_offload+0xaa0> */
	X86_SIM_X86_JMP(0x5e3, 0xaa0, x86_l_aa0);
x86_l_5e8:
	/* 0x5e8: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_5ed:
	/* 0x5ed: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_5f0:
	/* 0x5f0: je     71f <generic_sleepable_offload+0x71f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5f0, 0x71f, x86_l_71f);
x86_l_5f6:
	/* 0x5f6: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_5fb:
	/* 0x5fb: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_600:
	/* 0x600: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_603:
	/* 0x603: je     71f <generic_sleepable_offload+0x71f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x603, 0x71f, x86_l_71f);
x86_l_609:
	/* 0x609: jmp    732 <generic_sleepable_offload+0x732> */
	X86_SIM_X86_JMP(0x609, 0x732, x86_l_732);
x86_l_60e:
	/* 0x60e: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_613:
	/* 0x613: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_616:
	/* 0x616: je     920 <generic_sleepable_offload+0x920> */
	X86_SIM_X86_JCC(X86_CC_E, 0x616, 0x920, x86_l_920);
x86_l_61c:
	/* 0x61c: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_621:
	/* 0x621: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_626:
	/* 0x626: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_629:
	/* 0x629: je     920 <generic_sleepable_offload+0x920> */
	X86_SIM_X86_JCC(X86_CC_E, 0x629, 0x920, x86_l_920);
x86_l_62f:
	/* 0x62f: jmp    933 <generic_sleepable_offload+0x933> */
	X86_SIM_X86_JMP(0x62f, 0x933, x86_l_933);
x86_l_634:
	/* 0x634: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_639:
	/* 0x639: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_63c:
	/* 0x63c: je     71f <generic_sleepable_offload+0x71f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x63c, 0x71f, x86_l_71f);
x86_l_642:
	/* 0x642: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_647:
	/* 0x647: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_64c:
	/* 0x64c: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_64f:
	/* 0x64f: je     71f <generic_sleepable_offload+0x71f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x64f, 0x71f, x86_l_71f);
x86_l_655:
	/* 0x655: jmp    732 <generic_sleepable_offload+0x732> */
	X86_SIM_X86_JMP(0x655, 0x732, x86_l_732);
x86_l_65a:
	/* 0x65a: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_65f:
	/* 0x65f: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_662:
	/* 0x662: je     920 <generic_sleepable_offload+0x920> */
	X86_SIM_X86_JCC(X86_CC_E, 0x662, 0x920, x86_l_920);
x86_l_668:
	/* 0x668: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_66d:
	/* 0x66d: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_672:
	/* 0x672: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_675:
	/* 0x675: je     920 <generic_sleepable_offload+0x920> */
	X86_SIM_X86_JCC(X86_CC_E, 0x675, 0x920, x86_l_920);
x86_l_67b:
	/* 0x67b: jmp    933 <generic_sleepable_offload+0x933> */
	X86_SIM_X86_JMP(0x67b, 0x933, x86_l_933);
x86_l_680:
	/* 0x680: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_685:
	/* 0x685: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_688:
	/* 0x688: je     a8d <generic_sleepable_offload+0xa8d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x688, 0xa8d, x86_l_a8d);
x86_l_68e:
	/* 0x68e: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_693:
	/* 0x693: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_698:
	/* 0x698: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_69b:
	/* 0x69b: je     a8d <generic_sleepable_offload+0xa8d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x69b, 0xa8d, x86_l_a8d);
x86_l_6a1:
	/* 0x6a1: jmp    aa0 <generic_sleepable_offload+0xaa0> */
	X86_SIM_X86_JMP(0x6a1, 0xaa0, x86_l_aa0);
x86_l_6a6:
	/* 0x6a6: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_6a9:
	/* 0x6a9: je     f49 <generic_sleepable_offload+0xf49> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6a9, 0xf49, x86_l_f49);
x86_l_6af:
	/* 0x6af: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_6b2:
	/* 0x6b2: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x6b2, 0x119, x86_l_119);
x86_l_6b8:
	/* 0x6b8: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_6bb:
	/* 0x6bb: jg     152c <generic_sleepable_offload+0x152c> */
	X86_SIM_X86_JCC(X86_CC_G, 0x6bb, 0x152c, x86_l_152c);
x86_l_6c1:
	/* 0x6c1: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_6c4:
	/* 0x6c4: je     18c3 <generic_sleepable_offload+0x18c3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6c4, 0x18c3, x86_l_18c3);
x86_l_6ca:
	/* 0x6ca: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_6cd:
	/* 0x6cd: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x6cd, 0x119, x86_l_119);
x86_l_6d3:
	/* 0x6d3: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6d8:
	/* 0x6d8: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6db:
	/* 0x6db: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x6db, 0x119, x86_l_119);
x86_l_6e0:
	/* 0x6e0: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_6e5:
	/* 0x6e5: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_6e8:
	/* 0x6e8: je     a8d <generic_sleepable_offload+0xa8d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6e8, 0xa8d, x86_l_a8d);
x86_l_6ee:
	/* 0x6ee: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_6f3:
	/* 0x6f3: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_6f8:
	/* 0x6f8: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_6fb:
	/* 0x6fb: je     a8d <generic_sleepable_offload+0xa8d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6fb, 0xa8d, x86_l_a8d);
x86_l_701:
	/* 0x701: jmp    aa0 <generic_sleepable_offload+0xaa0> */
	X86_SIM_X86_JMP(0x701, 0xaa0, x86_l_aa0);
x86_l_706:
	/* 0x706: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_70b:
	/* 0x70b: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_70e:
	/* 0x70e: je     71f <generic_sleepable_offload+0x71f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x70e, 0x71f, x86_l_71f);
x86_l_710:
	/* 0x710: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_715:
	/* 0x715: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_71a:
	/* 0x71a: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_71d:
	/* 0x71d: jne    732 <generic_sleepable_offload+0x732> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x71d, 0x732, x86_l_732);
x86_l_71f:
	/* 0x71f: shl    cl,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_722:
	/* 0x722: mov    al,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 64ULL);
x86_l_724:
	/* 0x724: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_726:
	/* 0x726: mov    ecx,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 64ULL);
x86_l_72b:
	/* 0x72b: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_72d:
	/* 0x72d: bzhi   rax,QWORD PTR [rsi],rcx */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RAX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), 0ULL);
x86_l_732:
	/* 0x732: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_737:
	/* 0x737: movzx  edx,WORD PTR [r14-0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551612ULL);
x86_l_73c:
	/* 0x73c: movzx  ecx,BYTE PTR [r14-0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551615ULL);
x86_l_741:
	/* 0x741: rorx   edx,edx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RDX, X86_WIDTH_32, 0, 3ULL);
x86_l_747:
	/* 0x747: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_74a:
	/* 0x74a: jle    7a0 <generic_sleepable_offload+0x7a0> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x74a, 0x7a0, x86_l_7a0);
x86_l_74c:
	/* 0x74c: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_74f:
	/* 0x74f: jle    7eb <generic_sleepable_offload+0x7eb> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x74f, 0x7eb, x86_l_7eb);
x86_l_755:
	/* 0x755: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_758:
	/* 0x758: jle    a0c <generic_sleepable_offload+0xa0c> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x758, 0xa0c, x86_l_a0c);
x86_l_75e:
	/* 0x75e: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_761:
	/* 0x761: je     eeb <generic_sleepable_offload+0xeeb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x761, 0xeeb, x86_l_eeb);
x86_l_767:
	/* 0x767: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_76a:
	/* 0x76a: je     e50 <generic_sleepable_offload+0xe50> */
	X86_SIM_X86_JCC(X86_CC_E, 0x76a, 0xe50, x86_l_e50);
x86_l_770:
	/* 0x770: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_773:
	/* 0x773: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x773, 0x119, x86_l_119);
x86_l_779:
	/* 0x779: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_77c:
	/* 0x77c: jg     14e4 <generic_sleepable_offload+0x14e4> */
	X86_SIM_X86_JCC(X86_CC_G, 0x77c, 0x14e4, x86_l_14e4);
x86_l_782:
	/* 0x782: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_785:
	/* 0x785: je     192f <generic_sleepable_offload+0x192f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x785, 0x192f, x86_l_192f);
x86_l_78b:
	/* 0x78b: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_78e:
	/* 0x78e: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x78e, 0x119, x86_l_119);
x86_l_794:
	/* 0x794: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_798:
	/* 0x798: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_79b:
	/* 0x79b: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x79b, 0x119, x86_l_119);
x86_l_7a0:
	/* 0x7a0: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_7a3:
	/* 0x7a3: jg     826 <generic_sleepable_offload+0x826> */
	X86_SIM_X86_JCC(X86_CC_G, 0x7a3, 0x826, x86_l_826);
x86_l_7a9:
	/* 0x7a9: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_7ac:
	/* 0x7ac: jg     869 <generic_sleepable_offload+0x869> */
	X86_SIM_X86_JCC(X86_CC_G, 0x7ac, 0x869, x86_l_869);
x86_l_7b2:
	/* 0x7b2: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_7b4:
	/* 0x7b4: je     eab <generic_sleepable_offload+0xeab> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7b4, 0xeab, x86_l_eab);
x86_l_7ba:
	/* 0x7ba: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_7bd:
	/* 0x7bd: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x7bd, 0x119, x86_l_119);
x86_l_7c3:
	/* 0x7c3: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_7c6:
	/* 0x7c6: jg     10b4 <generic_sleepable_offload+0x10b4> */
	X86_SIM_X86_JCC(X86_CC_G, 0x7c6, 0x10b4, x86_l_10b4);
x86_l_7cc:
	/* 0x7cc: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_7cf:
	/* 0x7cf: je     15e9 <generic_sleepable_offload+0x15e9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7cf, 0x15e9, x86_l_15e9);
x86_l_7d5:
	/* 0x7d5: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_7d8:
	/* 0x7d8: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x7d8, 0x119, x86_l_119);
x86_l_7de:
	/* 0x7de: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7e3:
	/* 0x7e3: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7e6:
	/* 0x7e6: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x7e6, 0x119, x86_l_119);
x86_l_7eb:
	/* 0x7eb: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_7ee:
	/* 0x7ee: jg     8a3 <generic_sleepable_offload+0x8a3> */
	X86_SIM_X86_JCC(X86_CC_G, 0x7ee, 0x8a3, x86_l_8a3);
x86_l_7f4:
	/* 0x7f4: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_7f7:
	/* 0x7f7: je     d8c <generic_sleepable_offload+0xd8c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7f7, 0xd8c, x86_l_d8c);
x86_l_7fd:
	/* 0x7fd: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_800:
	/* 0x800: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x800, 0x119, x86_l_119);
x86_l_806:
	/* 0x806: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_809:
	/* 0x809: jg     12bc <generic_sleepable_offload+0x12bc> */
	X86_SIM_X86_JCC(X86_CC_G, 0x809, 0x12bc, x86_l_12bc);
x86_l_80f:
	/* 0x80f: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_812:
	/* 0x812: je     1615 <generic_sleepable_offload+0x1615> */
	X86_SIM_X86_JCC(X86_CC_E, 0x812, 0x1615, x86_l_1615);
x86_l_818:
	/* 0x818: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_81b:
	/* 0x81b: je     b8e <generic_sleepable_offload+0xb8e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x81b, 0xb8e, x86_l_b8e);
x86_l_821:
	/* 0x821: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x821, 0x119, x86_l_119);
x86_l_826:
	/* 0x826: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_829:
	/* 0x829: jg     8d5 <generic_sleepable_offload+0x8d5> */
	X86_SIM_X86_JCC(X86_CC_G, 0x829, 0x8d5, x86_l_8d5);
x86_l_82f:
	/* 0x82f: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_832:
	/* 0x832: je     cb6 <generic_sleepable_offload+0xcb6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x832, 0xcb6, x86_l_cb6);
x86_l_838:
	/* 0x838: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_83b:
	/* 0x83b: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x83b, 0x119, x86_l_119);
x86_l_841:
	/* 0x841: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_844:
	/* 0x844: jg     10d3 <generic_sleepable_offload+0x10d3> */
	X86_SIM_X86_JCC(X86_CC_G, 0x844, 0x10d3, x86_l_10d3);
x86_l_84a:
	/* 0x84a: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_84d:
	/* 0x84d: je     169e <generic_sleepable_offload+0x169e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x84d, 0x169e, x86_l_169e);
x86_l_853:
	/* 0x853: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_856:
	/* 0x856: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x856, 0x119, x86_l_119);
x86_l_85c:
	/* 0x85c: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_861:
	/* 0x861: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_864:
	/* 0x864: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x864, 0x119, x86_l_119);
x86_l_869:
	/* 0x869: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_86c:
	/* 0x86c: je     cde <generic_sleepable_offload+0xcde> */
	X86_SIM_X86_JCC(X86_CC_E, 0x86c, 0xcde, x86_l_cde);
x86_l_872:
	/* 0x872: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_875:
	/* 0x875: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x875, 0x119, x86_l_119);
x86_l_87b:
	/* 0x87b: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_87e:
	/* 0x87e: jg     10f2 <generic_sleepable_offload+0x10f2> */
	X86_SIM_X86_JCC(X86_CC_G, 0x87e, 0x10f2, x86_l_10f2);
x86_l_884:
	/* 0x884: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_887:
	/* 0x887: je     15f3 <generic_sleepable_offload+0x15f3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x887, 0x15f3, x86_l_15f3);
x86_l_88d:
	/* 0x88d: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_890:
	/* 0x890: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x890, 0x119, x86_l_119);
x86_l_896:
	/* 0x896: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_89b:
	/* 0x89b: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_89e:
	/* 0x89e: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x89e, 0x119, x86_l_119);
x86_l_8a3:
	/* 0x8a3: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_8a6:
	/* 0x8a6: je     da8 <generic_sleepable_offload+0xda8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8a6, 0xda8, x86_l_da8);
x86_l_8ac:
	/* 0x8ac: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_8af:
	/* 0x8af: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x8af, 0x119, x86_l_119);
x86_l_8b5:
	/* 0x8b5: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_8b8:
	/* 0x8b8: jg     12cb <generic_sleepable_offload+0x12cb> */
	X86_SIM_X86_JCC(X86_CC_G, 0x8b8, 0x12cb, x86_l_12cb);
x86_l_8be:
	/* 0x8be: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_8c1:
	/* 0x8c1: je     1621 <generic_sleepable_offload+0x1621> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8c1, 0x1621, x86_l_1621);
x86_l_8c7:
	/* 0x8c7: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_8ca:
	/* 0x8ca: je     c03 <generic_sleepable_offload+0xc03> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8ca, 0xc03, x86_l_c03);
x86_l_8d0:
	/* 0x8d0: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x8d0, 0x119, x86_l_119);
x86_l_8d5:
	/* 0x8d5: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_8d8:
	/* 0x8d8: je     ecb <generic_sleepable_offload+0xecb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8d8, 0xecb, x86_l_ecb);
x86_l_8de:
	/* 0x8de: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_8e1:
	/* 0x8e1: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x8e1, 0x119, x86_l_119);
x86_l_8e7:
	/* 0x8e7: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_8ea:
	/* 0x8ea: jg     1515 <generic_sleepable_offload+0x1515> */
	X86_SIM_X86_JCC(X86_CC_G, 0x8ea, 0x1515, x86_l_1515);
x86_l_8f0:
	/* 0x8f0: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_8f3:
	/* 0x8f3: je     16aa <generic_sleepable_offload+0x16aa> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8f3, 0x16aa, x86_l_16aa);
x86_l_8f9:
	/* 0x8f9: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_8fc:
	/* 0x8fc: je     c6f <generic_sleepable_offload+0xc6f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8fc, 0xc6f, x86_l_c6f);
x86_l_902:
	/* 0x902: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x902, 0x119, x86_l_119);
x86_l_907:
	/* 0x907: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_90c:
	/* 0x90c: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_90f:
	/* 0x90f: je     920 <generic_sleepable_offload+0x920> */
	X86_SIM_X86_JCC(X86_CC_E, 0x90f, 0x920, x86_l_920);
x86_l_911:
	/* 0x911: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_916:
	/* 0x916: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_91b:
	/* 0x91b: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_91e:
	/* 0x91e: jne    933 <generic_sleepable_offload+0x933> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x91e, 0x933, x86_l_933);
x86_l_920:
	/* 0x920: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_923:
	/* 0x923: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_925:
	/* 0x925: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_927:
	/* 0x927: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_92c:
	/* 0x92c: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_92e:
	/* 0x92e: bzhi   rsi,QWORD PTR [rdx],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RSI, X86_RDX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_933:
	/* 0x933: mov    QWORD PTR [rsp+0x78],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_938:
	/* 0x938: add    rsi,QWORD PTR [r14] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RSI, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_93b:
	/* 0x93b: mov    eax,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 112ULL);
x86_l_940:
	/* 0x940: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_945:
	/* 0x945: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_94a:
	/* 0x94a: add    rdx,QWORD PTR [r14] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_94d:
	/* 0x94d: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_950:
	/* 0x950: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_955:
	/* 0x955: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_957:
	/* 0x957: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_959:
	/* 0x959: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x959, 0x119, x86_l_119);
x86_l_95f:
	/* 0x95f: movzx  edx,WORD PTR [r14-0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551612ULL);
x86_l_964:
	/* 0x964: movzx  ecx,BYTE PTR [r14-0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551615ULL);
x86_l_969:
	/* 0x969: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_96e:
	/* 0x96e: rorx   edx,edx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RDX, X86_WIDTH_32, 0, 3ULL);
x86_l_974:
	/* 0x974: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_977:
	/* 0x977: jle    9c1 <generic_sleepable_offload+0x9c1> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x977, 0x9c1, x86_l_9c1);
x86_l_979:
	/* 0x979: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_97c:
	/* 0x97c: jle    d06 <generic_sleepable_offload+0xd06> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x97c, 0xd06, x86_l_d06);
x86_l_982:
	/* 0x982: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_985:
	/* 0x985: jle    11bf <generic_sleepable_offload+0x11bf> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x985, 0x11bf, x86_l_11bf);
x86_l_98b:
	/* 0x98b: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_98e:
	/* 0x98e: je     182c <generic_sleepable_offload+0x182c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x98e, 0x182c, x86_l_182c);
x86_l_994:
	/* 0x994: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_997:
	/* 0x997: je     1742 <generic_sleepable_offload+0x1742> */
	X86_SIM_X86_JCC(X86_CC_E, 0x997, 0x1742, x86_l_1742);
x86_l_99d:
	/* 0x99d: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_9a0:
	/* 0x9a0: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x9a0, 0x119, x86_l_119);
x86_l_9a6:
	/* 0x9a6: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_9a9:
	/* 0x9a9: jg     11e9 <generic_sleepable_offload+0x11e9> */
	X86_SIM_X86_JCC(X86_CC_G, 0x9a9, 0x11e9, x86_l_11e9);
x86_l_9af:
	/* 0x9af: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_9b2:
	/* 0x9b2: jne    afc <generic_sleepable_offload+0xafc> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x9b2, 0xafc, x86_l_afc);
x86_l_9b8:
	/* 0x9b8: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9bc:
	/* 0x9bc: jmp    117 <generic_sleepable_offload+0x117> */
	X86_SIM_X86_JMP(0x9bc, 0x117, x86_l_117);
x86_l_9c1:
	/* 0x9c1: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_9c4:
	/* 0x9c4: jg     d49 <generic_sleepable_offload+0xd49> */
	X86_SIM_X86_JCC(X86_CC_G, 0x9c4, 0xd49, x86_l_d49);
x86_l_9ca:
	/* 0x9ca: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_9cd:
	/* 0x9cd: jg     114b <generic_sleepable_offload+0x114b> */
	X86_SIM_X86_JCC(X86_CC_G, 0x9cd, 0x114b, x86_l_114b);
x86_l_9d3:
	/* 0x9d3: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_9d5:
	/* 0x9d5: je     1785 <generic_sleepable_offload+0x1785> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9d5, 0x1785, x86_l_1785);
x86_l_9db:
	/* 0x9db: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_9de:
	/* 0x9de: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x9de, 0x119, x86_l_119);
x86_l_9e4:
	/* 0x9e4: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_9e7:
	/* 0x9e7: jg     1ab7 <generic_sleepable_offload+0x1ab7> */
	X86_SIM_X86_JCC(X86_CC_G, 0x9e7, 0x1ab7, x86_l_1ab7);
x86_l_9ed:
	/* 0x9ed: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_9f0:
	/* 0x9f0: je     15e9 <generic_sleepable_offload+0x15e9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9f0, 0x15e9, x86_l_15e9);
x86_l_9f6:
	/* 0x9f6: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_9f9:
	/* 0x9f9: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x9f9, 0x119, x86_l_119);
x86_l_9ff:
	/* 0x9ff: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a04:
	/* 0xa04: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a07:
	/* 0xa07: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0xa07, 0x119, x86_l_119);
x86_l_a0c:
	/* 0xa0c: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_a0f:
	/* 0xa0f: je     1048 <generic_sleepable_offload+0x1048> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa0f, 0x1048, x86_l_1048);
x86_l_a15:
	/* 0xa15: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_a18:
	/* 0xa18: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa18, 0x119, x86_l_119);
x86_l_a1e:
	/* 0xa1e: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_a21:
	/* 0xa21: jg     15b7 <generic_sleepable_offload+0x15b7> */
	X86_SIM_X86_JCC(X86_CC_G, 0xa21, 0x15b7, x86_l_15b7);
x86_l_a27:
	/* 0xa27: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_a2a:
	/* 0xa2a: je     196a <generic_sleepable_offload+0x196a> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa2a, 0x196a, x86_l_196a);
x86_l_a30:
	/* 0xa30: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_a33:
	/* 0xa33: je     a67 <generic_sleepable_offload+0xa67> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa33, 0xa67, x86_l_a67);
x86_l_a35:
	/* 0xa35: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0xa35, 0x119, x86_l_119);
x86_l_a3a:
	/* 0xa3a: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_a3d:
	/* 0xa3d: je     1064 <generic_sleepable_offload+0x1064> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa3d, 0x1064, x86_l_1064);
x86_l_a43:
	/* 0xa43: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_a46:
	/* 0xa46: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa46, 0x119, x86_l_119);
x86_l_a4c:
	/* 0xa4c: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_a4f:
	/* 0xa4f: jg     15ca <generic_sleepable_offload+0x15ca> */
	X86_SIM_X86_JCC(X86_CC_G, 0xa4f, 0x15ca, x86_l_15ca);
x86_l_a55:
	/* 0xa55: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_a58:
	/* 0xa58: je     11df <generic_sleepable_offload+0x11df> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa58, 0x11df, x86_l_11df);
x86_l_a5e:
	/* 0xa5e: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_a61:
	/* 0xa61: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa61, 0x119, x86_l_119);
x86_l_a67:
	/* 0xa67: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_a6c:
	/* 0xa6c: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a6f:
	/* 0xa6f: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0xa6f, 0x119, x86_l_119);
x86_l_a74:
	/* 0xa74: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_a79:
	/* 0xa79: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_a7c:
	/* 0xa7c: je     a8d <generic_sleepable_offload+0xa8d> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa7c, 0xa8d, x86_l_a8d);
x86_l_a7e:
	/* 0xa7e: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_a83:
	/* 0xa83: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_a88:
	/* 0xa88: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_a8b:
	/* 0xa8b: jne    aa0 <generic_sleepable_offload+0xaa0> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa8b, 0xaa0, x86_l_aa0);
x86_l_a8d:
	/* 0xa8d: shl    cl,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_a90:
	/* 0xa90: mov    al,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 64ULL);
x86_l_a92:
	/* 0xa92: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_a94:
	/* 0xa94: mov    ecx,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 64ULL);
x86_l_a99:
	/* 0xa99: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_a9b:
	/* 0xa9b: bzhi   rax,QWORD PTR [rsi],rcx */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RAX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), 0ULL);
x86_l_aa0:
	/* 0xaa0: add    rax,QWORD PTR [r14] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_aa3:
	/* 0xaa3: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_aa8:
	/* 0xaa8: movzx  edx,WORD PTR [r14-0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551612ULL);
x86_l_aad:
	/* 0xaad: movzx  ecx,BYTE PTR [r14-0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551615ULL);
x86_l_ab2:
	/* 0xab2: rorx   edx,edx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RDX, X86_WIDTH_32, 0, 3ULL);
x86_l_ab8:
	/* 0xab8: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_abb:
	/* 0xabb: jle    b11 <generic_sleepable_offload+0xb11> */
	X86_SIM_X86_JCC(X86_CC_LE, 0xabb, 0xb11, x86_l_b11);
x86_l_abd:
	/* 0xabd: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_ac0:
	/* 0xac0: jle    b5c <generic_sleepable_offload+0xb5c> */
	X86_SIM_X86_JCC(X86_CC_LE, 0xac0, 0xb5c, x86_l_b5c);
x86_l_ac6:
	/* 0xac6: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_ac9:
	/* 0xac9: jle    c7c <generic_sleepable_offload+0xc7c> */
	X86_SIM_X86_JCC(X86_CC_LE, 0xac9, 0xc7c, x86_l_c7c);
x86_l_acf:
	/* 0xacf: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_ad2:
	/* 0xad2: je     1028 <generic_sleepable_offload+0x1028> */
	X86_SIM_X86_JCC(X86_CC_E, 0xad2, 0x1028, x86_l_1028);
x86_l_ad8:
	/* 0xad8: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_adb:
	/* 0xadb: je     e94 <generic_sleepable_offload+0xe94> */
	X86_SIM_X86_JCC(X86_CC_E, 0xadb, 0xe94, x86_l_e94);
x86_l_ae1:
	/* 0xae1: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_ae4:
	/* 0xae4: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xae4, 0x119, x86_l_119);
x86_l_aea:
	/* 0xaea: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_aed:
	/* 0xaed: jg     11e9 <generic_sleepable_offload+0x11e9> */
	X86_SIM_X86_JCC(X86_CC_G, 0xaed, 0x11e9, x86_l_11e9);
x86_l_af3:
	/* 0xaf3: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_af6:
	/* 0xaf6: je     9b8 <generic_sleepable_offload+0x9b8> */
	X86_SIM_X86_JCC(X86_CC_E, 0xaf6, 0x9b8, x86_l_9b8);
x86_l_afc:
	/* 0xafc: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_aff:
	/* 0xaff: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xaff, 0x119, x86_l_119);
x86_l_b05:
	/* 0xb05: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b09:
	/* 0xb09: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b0c:
	/* 0xb0c: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0xb0c, 0x119, x86_l_119);
x86_l_b11:
	/* 0xb11: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_b14:
	/* 0xb14: jg     b9b <generic_sleepable_offload+0xb9b> */
	X86_SIM_X86_JCC(X86_CC_G, 0xb14, 0xb9b, x86_l_b9b);
x86_l_b1a:
	/* 0xb1a: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_b1d:
	/* 0xb1d: jg     c10 <generic_sleepable_offload+0xc10> */
	X86_SIM_X86_JCC(X86_CC_G, 0xb1d, 0xc10, x86_l_c10);
x86_l_b23:
	/* 0xb23: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_b25:
	/* 0xb25: je     f71 <generic_sleepable_offload+0xf71> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb25, 0xf71, x86_l_f71);
x86_l_b2b:
	/* 0xb2b: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_b2e:
	/* 0xb2e: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb2e, 0x119, x86_l_119);
x86_l_b34:
	/* 0xb34: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_b37:
	/* 0xb37: jg     154b <generic_sleepable_offload+0x154b> */
	X86_SIM_X86_JCC(X86_CC_G, 0xb37, 0x154b, x86_l_154b);
x86_l_b3d:
	/* 0xb3d: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_b40:
	/* 0xb40: je     193a <generic_sleepable_offload+0x193a> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb40, 0x193a, x86_l_193a);
x86_l_b46:
	/* 0xb46: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_b49:
	/* 0xb49: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb49, 0x119, x86_l_119);
x86_l_b4f:
	/* 0xb4f: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b54:
	/* 0xb54: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b57:
	/* 0xb57: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0xb57, 0x119, x86_l_119);
x86_l_b5c:
	/* 0xb5c: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_b5f:
	/* 0xb5f: jg     bd6 <generic_sleepable_offload+0xbd6> */
	X86_SIM_X86_JCC(X86_CC_G, 0xb5f, 0xbd6, x86_l_bd6);
x86_l_b61:
	/* 0xb61: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_b64:
	/* 0xb64: je     e00 <generic_sleepable_offload+0xe00> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb64, 0xe00, x86_l_e00);
x86_l_b6a:
	/* 0xb6a: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_b6d:
	/* 0xb6d: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb6d, 0x119, x86_l_119);
x86_l_b73:
	/* 0xb73: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_b76:
	/* 0xb76: jg     1313 <generic_sleepable_offload+0x1313> */
	X86_SIM_X86_JCC(X86_CC_G, 0xb76, 0x1313, x86_l_1313);
x86_l_b7c:
	/* 0xb7c: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_b7f:
	/* 0xb7f: je     1615 <generic_sleepable_offload+0x1615> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb7f, 0x1615, x86_l_1615);
x86_l_b85:
	/* 0xb85: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_b88:
	/* 0xb88: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb88, 0x119, x86_l_119);
x86_l_b8e:
	/* 0xb8e: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b93:
	/* 0xb93: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b96:
	/* 0xb96: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0xb96, 0x119, x86_l_119);
x86_l_b9b:
	/* 0xb9b: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_b9e:
	/* 0xb9e: jg     c42 <generic_sleepable_offload+0xc42> */
	X86_SIM_X86_JCC(X86_CC_G, 0xb9e, 0xc42, x86_l_c42);
x86_l_ba4:
	/* 0xba4: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_ba7:
	/* 0xba7: je     f94 <generic_sleepable_offload+0xf94> */
	X86_SIM_X86_JCC(X86_CC_E, 0xba7, 0xf94, x86_l_f94);
x86_l_bad:
	/* 0xbad: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_bb0:
	/* 0xbb0: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xbb0, 0x119, x86_l_119);
x86_l_bb6:
	/* 0xbb6: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_bb9:
	/* 0xbb9: jg     156a <generic_sleepable_offload+0x156a> */
	X86_SIM_X86_JCC(X86_CC_G, 0xbb9, 0x156a, x86_l_156a);
x86_l_bbf:
	/* 0xbbf: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_bc2:
	/* 0xbc2: je     169e <generic_sleepable_offload+0x169e> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbc2, 0x169e, x86_l_169e);
x86_l_bc8:
	/* 0xbc8: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_bcb:
	/* 0xbcb: je     d7f <generic_sleepable_offload+0xd7f> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbcb, 0xd7f, x86_l_d7f);
x86_l_bd1:
	/* 0xbd1: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0xbd1, 0x119, x86_l_119);
x86_l_bd6:
	/* 0xbd6: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_bd9:
	/* 0xbd9: je     e28 <generic_sleepable_offload+0xe28> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbd9, 0xe28, x86_l_e28);
x86_l_bdf:
	/* 0xbdf: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_be2:
	/* 0xbe2: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xbe2, 0x119, x86_l_119);
x86_l_be8:
	/* 0xbe8: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_beb:
	/* 0xbeb: jg     133a <generic_sleepable_offload+0x133a> */
	X86_SIM_X86_JCC(X86_CC_G, 0xbeb, 0x133a, x86_l_133a);
x86_l_bf1:
	/* 0xbf1: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_bf4:
	/* 0xbf4: je     1621 <generic_sleepable_offload+0x1621> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbf4, 0x1621, x86_l_1621);
x86_l_bfa:
	/* 0xbfa: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_bfd:
	/* 0xbfd: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xbfd, 0x119, x86_l_119);
x86_l_c03:
	/* 0xc03: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_c08:
	/* 0xc08: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c0b:
	/* 0xc0b: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0xc0b, 0x119, x86_l_119);
x86_l_c10:
	/* 0xc10: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_c13:
	/* 0xc13: je     fb4 <generic_sleepable_offload+0xfb4> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc13, 0xfb4, x86_l_fb4);
x86_l_c19:
	/* 0xc19: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_c1c:
	/* 0xc1c: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xc1c, 0x119, x86_l_119);
x86_l_c22:
	/* 0xc22: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_c25:
	/* 0xc25: jg     1581 <generic_sleepable_offload+0x1581> */
	X86_SIM_X86_JCC(X86_CC_G, 0xc25, 0x1581, x86_l_1581);
x86_l_c2b:
	/* 0xc2b: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_c2e:
	/* 0xc2e: je     1946 <generic_sleepable_offload+0x1946> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc2e, 0x1946, x86_l_1946);
x86_l_c34:
	/* 0xc34: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_c37:
	/* 0xc37: je     1178 <generic_sleepable_offload+0x1178> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc37, 0x1178, x86_l_1178);
x86_l_c3d:
	/* 0xc3d: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0xc3d, 0x119, x86_l_119);
x86_l_c42:
	/* 0xc42: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_c45:
	/* 0xc45: je     fdc <generic_sleepable_offload+0xfdc> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc45, 0xfdc, x86_l_fdc);
x86_l_c4b:
	/* 0xc4b: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_c4e:
	/* 0xc4e: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xc4e, 0x119, x86_l_119);
x86_l_c54:
	/* 0xc54: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_c57:
	/* 0xc57: jg     1598 <generic_sleepable_offload+0x1598> */
	X86_SIM_X86_JCC(X86_CC_G, 0xc57, 0x1598, x86_l_1598);
x86_l_c5d:
	/* 0xc5d: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_c60:
	/* 0xc60: je     16aa <generic_sleepable_offload+0x16aa> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc60, 0x16aa, x86_l_16aa);
x86_l_c66:
	/* 0xc66: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_c69:
	/* 0xc69: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xc69, 0x119, x86_l_119);
x86_l_c6f:
	/* 0xc6f: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c74:
	/* 0xc74: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c77:
	/* 0xc77: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0xc77, 0x119, x86_l_119);
x86_l_c7c:
	/* 0xc7c: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_c7f:
	/* 0xc7f: je     108c <generic_sleepable_offload+0x108c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc7f, 0x108c, x86_l_108c);
x86_l_c85:
	/* 0xc85: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_c88:
	/* 0xc88: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xc88, 0x119, x86_l_119);
x86_l_c8e:
	/* 0xc8e: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_c91:
	/* 0xc91: jg     1207 <generic_sleepable_offload+0x1207> */
	X86_SIM_X86_JCC(X86_CC_G, 0xc91, 0x1207, x86_l_1207);
x86_l_c97:
	/* 0xc97: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_c9a:
	/* 0xc9a: je     11df <generic_sleepable_offload+0x11df> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc9a, 0x11df, x86_l_11df);
x86_l_ca0:
	/* 0xca0: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_ca3:
	/* 0xca3: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xca3, 0x119, x86_l_119);
x86_l_ca9:
	/* 0xca9: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_cae:
	/* 0xcae: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cb1:
	/* 0xcb1: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0xcb1, 0x119, x86_l_119);
x86_l_cb6:
	/* 0xcb6: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_cb9:
	/* 0xcb9: jg     f0b <generic_sleepable_offload+0xf0b> */
	X86_SIM_X86_JCC(X86_CC_G, 0xcb9, 0xf0b, x86_l_f0b);
x86_l_cbf:
	/* 0xcbf: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_cc2:
	/* 0xcc2: je     17cc <generic_sleepable_offload+0x17cc> */
	X86_SIM_X86_JCC(X86_CC_E, 0xcc2, 0x17cc, x86_l_17cc);
x86_l_cc8:
	/* 0xcc8: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_ccb:
	/* 0xccb: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xccb, 0x119, x86_l_119);
x86_l_cd1:
	/* 0xcd1: mov    rcx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_cd6:
	/* 0xcd6: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cd9:
	/* 0xcd9: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0xcd9, 0x119, x86_l_119);
x86_l_cde:
	/* 0xcde: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_ce1:
	/* 0xce1: jg     f2a <generic_sleepable_offload+0xf2a> */
	X86_SIM_X86_JCC(X86_CC_G, 0xce1, 0xf2a, x86_l_f2a);
x86_l_ce7:
	/* 0xce7: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_cea:
	/* 0xcea: je     17fa <generic_sleepable_offload+0x17fa> */
	X86_SIM_X86_JCC(X86_CC_E, 0xcea, 0x17fa, x86_l_17fa);
x86_l_cf0:
	/* 0xcf0: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_cf3:
	/* 0xcf3: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xcf3, 0x119, x86_l_119);
x86_l_cf9:
	/* 0xcf9: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_cfe:
	/* 0xcfe: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d01:
	/* 0xd01: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0xd01, 0x119, x86_l_119);
x86_l_d06:
	/* 0xd06: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_d09:
	/* 0xd09: jg     1111 <generic_sleepable_offload+0x1111> */
	X86_SIM_X86_JCC(X86_CC_G, 0xd09, 0x1111, x86_l_1111);
x86_l_d0f:
	/* 0xd0f: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_d12:
	/* 0xd12: je     16f2 <generic_sleepable_offload+0x16f2> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd12, 0x16f2, x86_l_16f2);
x86_l_d18:
	/* 0xd18: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_d1b:
	/* 0xd1b: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xd1b, 0x119, x86_l_119);
x86_l_d21:
	/* 0xd21: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_d24:
	/* 0xd24: jg     19b4 <generic_sleepable_offload+0x19b4> */
	X86_SIM_X86_JCC(X86_CC_G, 0xd24, 0x19b4, x86_l_19b4);
x86_l_d2a:
	/* 0xd2a: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_d2d:
	/* 0xd2d: je     187c <generic_sleepable_offload+0x187c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd2d, 0x187c, x86_l_187c);
x86_l_d33:
	/* 0xd33: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_d36:
	/* 0xd36: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xd36, 0x119, x86_l_119);
x86_l_d3c:
	/* 0xd3c: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_d41:
	/* 0xd41: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d44:
	/* 0xd44: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0xd44, 0x119, x86_l_119);
x86_l_d49:
	/* 0xd49: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_d4c:
	/* 0xd4c: jg     1185 <generic_sleepable_offload+0x1185> */
	X86_SIM_X86_JCC(X86_CC_G, 0xd4c, 0x1185, x86_l_1185);
x86_l_d52:
	/* 0xd52: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_d55:
	/* 0xd55: je     17a8 <generic_sleepable_offload+0x17a8> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd55, 0x17a8, x86_l_17a8);
x86_l_d5b:
	/* 0xd5b: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_d5e:
	/* 0xd5e: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xd5e, 0x119, x86_l_119);
x86_l_d64:
	/* 0xd64: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_d67:
	/* 0xd67: jg     1ad6 <generic_sleepable_offload+0x1ad6> */
	X86_SIM_X86_JCC(X86_CC_G, 0xd67, 0x1ad6, x86_l_1ad6);
x86_l_d6d:
	/* 0xd6d: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_d70:
	/* 0xd70: je     18b9 <generic_sleepable_offload+0x18b9> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd70, 0x18b9, x86_l_18b9);
x86_l_d76:
	/* 0xd76: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_d79:
	/* 0xd79: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xd79, 0x119, x86_l_119);
x86_l_d7f:
	/* 0xd7f: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d84:
	/* 0xd84: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d87:
	/* 0xd87: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0xd87, 0x119, x86_l_119);
x86_l_d8c:
	/* 0xd8c: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_d8f:
	/* 0xd8f: jg     1226 <generic_sleepable_offload+0x1226> */
	X86_SIM_X86_JCC(X86_CC_G, 0xd8f, 0x1226, x86_l_1226);
x86_l_d95:
	/* 0xd95: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_d98:
	/* 0xd98: je     15fd <generic_sleepable_offload+0x15fd> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd98, 0x15fd, x86_l_15fd);
x86_l_d9e:
	/* 0xd9e: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_da1:
	/* 0xda1: je     e1b <generic_sleepable_offload+0xe1b> */
	X86_SIM_X86_JCC(X86_CC_E, 0xda1, 0xe1b, x86_l_e1b);
x86_l_da3:
	/* 0xda3: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0xda3, 0x119, x86_l_119);
x86_l_da8:
	/* 0xda8: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_dab:
	/* 0xdab: jg     1235 <generic_sleepable_offload+0x1235> */
	X86_SIM_X86_JCC(X86_CC_G, 0xdab, 0x1235, x86_l_1235);
x86_l_db1:
	/* 0xdb1: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_db4:
	/* 0xdb4: je     1609 <generic_sleepable_offload+0x1609> */
	X86_SIM_X86_JCC(X86_CC_E, 0xdb4, 0x1609, x86_l_1609);
x86_l_dba:
	/* 0xdba: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_dbd:
	/* 0xdbd: je     e43 <generic_sleepable_offload+0xe43> */
	X86_SIM_X86_JCC(X86_CC_E, 0xdbd, 0xe43, x86_l_e43);
x86_l_dc3:
	/* 0xdc3: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0xdc3, 0x119, x86_l_119);
x86_l_dc8:
	/* 0xdc8: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_dcb:
	/* 0xdcb: jg     1244 <generic_sleepable_offload+0x1244> */
	X86_SIM_X86_JCC(X86_CC_G, 0xdcb, 0x1244, x86_l_1244);
x86_l_dd1:
	/* 0xdd1: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_dd4:
	/* 0xdd4: je     1868 <generic_sleepable_offload+0x1868> */
	X86_SIM_X86_JCC(X86_CC_E, 0xdd4, 0x1868, x86_l_1868);
x86_l_dda:
	/* 0xdda: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_ddd:
	/* 0xddd: je     e1b <generic_sleepable_offload+0xe1b> */
	X86_SIM_X86_JCC(X86_CC_E, 0xddd, 0xe1b, x86_l_e1b);
x86_l_ddf:
	/* 0xddf: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0xddf, 0x119, x86_l_119);
x86_l_de4:
	/* 0xde4: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_de7:
	/* 0xde7: jg     125f <generic_sleepable_offload+0x125f> */
	X86_SIM_X86_JCC(X86_CC_G, 0xde7, 0x125f, x86_l_125f);
x86_l_ded:
	/* 0xded: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_df0:
	/* 0xdf0: je     1872 <generic_sleepable_offload+0x1872> */
	X86_SIM_X86_JCC(X86_CC_E, 0xdf0, 0x1872, x86_l_1872);
x86_l_df6:
	/* 0xdf6: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_df9:
	/* 0xdf9: je     e43 <generic_sleepable_offload+0xe43> */
	X86_SIM_X86_JCC(X86_CC_E, 0xdf9, 0xe43, x86_l_e43);
x86_l_dfb:
	/* 0xdfb: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0xdfb, 0x119, x86_l_119);
x86_l_e00:
	/* 0xe00: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_e03:
	/* 0xe03: jg     126e <generic_sleepable_offload+0x126e> */
	X86_SIM_X86_JCC(X86_CC_G, 0xe03, 0x126e, x86_l_126e);
x86_l_e09:
	/* 0xe09: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_e0c:
	/* 0xe0c: je     15fd <generic_sleepable_offload+0x15fd> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe0c, 0x15fd, x86_l_15fd);
x86_l_e12:
	/* 0xe12: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_e15:
	/* 0xe15: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe15, 0x119, x86_l_119);
x86_l_e1b:
	/* 0xe1b: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_e20:
	/* 0xe20: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e23:
	/* 0xe23: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0xe23, 0x119, x86_l_119);
x86_l_e28:
	/* 0xe28: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_e2b:
	/* 0xe2b: jg     1295 <generic_sleepable_offload+0x1295> */
	X86_SIM_X86_JCC(X86_CC_G, 0xe2b, 0x1295, x86_l_1295);
x86_l_e31:
	/* 0xe31: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_e34:
	/* 0xe34: je     1609 <generic_sleepable_offload+0x1609> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe34, 0x1609, x86_l_1609);
x86_l_e3a:
	/* 0xe3a: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_e3d:
	/* 0xe3d: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe3d, 0x119, x86_l_119);
x86_l_e43:
	/* 0xe43: mov    rcx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_e48:
	/* 0xe48: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e4b:
	/* 0xe4b: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0xe4b, 0x119, x86_l_119);
x86_l_e50:
	/* 0xe50: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_e53:
	/* 0xe53: jg     12de <generic_sleepable_offload+0x12de> */
	X86_SIM_X86_JCC(X86_CC_G, 0xe53, 0x12de, x86_l_12de);
x86_l_e59:
	/* 0xe59: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_e5c:
	/* 0xe5c: je     18d9 <generic_sleepable_offload+0x18d9> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe5c, 0x18d9, x86_l_18d9);
x86_l_e62:
	/* 0xe62: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_e65:
	/* 0xe65: je     e87 <generic_sleepable_offload+0xe87> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe65, 0xe87, x86_l_e87);
x86_l_e67:
	/* 0xe67: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0xe67, 0x119, x86_l_119);
x86_l_e6c:
	/* 0xe6c: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_e6f:
	/* 0xe6f: jg     1361 <generic_sleepable_offload+0x1361> */
	X86_SIM_X86_JCC(X86_CC_G, 0xe6f, 0x1361, x86_l_1361);
x86_l_e75:
	/* 0xe75: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_e78:
	/* 0xe78: je     112 <generic_sleepable_offload+0x112> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe78, 0x112, x86_l_112);
x86_l_e7e:
	/* 0xe7e: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_e81:
	/* 0xe81: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe81, 0x119, x86_l_119);
x86_l_e87:
	/* 0xe87: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_e8c:
	/* 0xe8c: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e8f:
	/* 0xe8f: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0xe8f, 0x119, x86_l_119);
x86_l_e94:
	/* 0xe94: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_e97:
	/* 0xe97: jg     1766 <generic_sleepable_offload+0x1766> */
	X86_SIM_X86_JCC(X86_CC_G, 0xe97, 0x1766, x86_l_1766);
x86_l_e9d:
	/* 0xe9d: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_ea0:
	/* 0xea0: jne    1750 <generic_sleepable_offload+0x1750> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xea0, 0x1750, x86_l_1750);
x86_l_ea6:
	/* 0xea6: jmp    112 <generic_sleepable_offload+0x112> */
	X86_SIM_X86_JMP(0xea6, 0x112, x86_l_112);
x86_l_eab:
	/* 0xeab: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_eae:
	/* 0xeae: jg     1380 <generic_sleepable_offload+0x1380> */
	X86_SIM_X86_JCC(X86_CC_G, 0xeae, 0x1380, x86_l_1380);
x86_l_eb4:
	/* 0xeb4: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_eb7:
	/* 0xeb7: je     1651 <generic_sleepable_offload+0x1651> */
	X86_SIM_X86_JCC(X86_CC_E, 0xeb7, 0x1651, x86_l_1651);
x86_l_ebd:
	/* 0xebd: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_ec0:
	/* 0xec0: je     f8c <generic_sleepable_offload+0xf8c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xec0, 0xf8c, x86_l_f8c);
x86_l_ec6:
	/* 0xec6: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0xec6, 0x119, x86_l_119);
x86_l_ecb:
	/* 0xecb: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_ece:
	/* 0xece: jg     1397 <generic_sleepable_offload+0x1397> */
	X86_SIM_X86_JCC(X86_CC_G, 0xece, 0x1397, x86_l_1397);
x86_l_ed4:
	/* 0xed4: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_ed7:
	/* 0xed7: je     1658 <generic_sleepable_offload+0x1658> */
	X86_SIM_X86_JCC(X86_CC_E, 0xed7, 0x1658, x86_l_1658);
x86_l_edd:
	/* 0xedd: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_ee0:
	/* 0xee0: je     ff7 <generic_sleepable_offload+0xff7> */
	X86_SIM_X86_JCC(X86_CC_E, 0xee0, 0xff7, x86_l_ff7);
x86_l_ee6:
	/* 0xee6: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0xee6, 0x119, x86_l_119);
x86_l_eeb:
	/* 0xeeb: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_eee:
	/* 0xeee: jg     13ae <generic_sleepable_offload+0x13ae> */
	X86_SIM_X86_JCC(X86_CC_G, 0xeee, 0x13ae, x86_l_13ae);
x86_l_ef4:
	/* 0xef4: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_ef7:
	/* 0xef7: je     1677 <generic_sleepable_offload+0x1677> */
	X86_SIM_X86_JCC(X86_CC_E, 0xef7, 0x1677, x86_l_1677);
x86_l_efd:
	/* 0xefd: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_f00:
	/* 0xf00: je     101f <generic_sleepable_offload+0x101f> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf00, 0x101f, x86_l_101f);
x86_l_f06:
	/* 0xf06: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0xf06, 0x119, x86_l_119);
x86_l_f0b:
	/* 0xf0b: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_f0e:
	/* 0xf0e: je     1639 <generic_sleepable_offload+0x1639> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf0e, 0x1639, x86_l_1639);
x86_l_f14:
	/* 0xf14: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_f17:
	/* 0xf17: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf17, 0x119, x86_l_119);
x86_l_f1d:
	/* 0xf1d: mov    rcx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_f22:
	/* 0xf22: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f25:
	/* 0xf25: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0xf25, 0x119, x86_l_119);
x86_l_f2a:
	/* 0xf2a: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_f2d:
	/* 0xf2d: je     1645 <generic_sleepable_offload+0x1645> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf2d, 0x1645, x86_l_1645);
x86_l_f33:
	/* 0xf33: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_f36:
	/* 0xf36: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf36, 0x119, x86_l_119);
x86_l_f3c:
	/* 0xf3c: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_f41:
	/* 0xf41: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f44:
	/* 0xf44: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0xf44, 0x119, x86_l_119);
x86_l_f49:
	/* 0xf49: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_f4c:
	/* 0xf4c: jg     13df <generic_sleepable_offload+0x13df> */
	X86_SIM_X86_JCC(X86_CC_G, 0xf4c, 0x13df, x86_l_13df);
x86_l_f52:
	/* 0xf52: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_f55:
	/* 0xf55: je     189c <generic_sleepable_offload+0x189c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf55, 0x189c, x86_l_189c);
x86_l_f5b:
	/* 0xf5b: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_f5e:
	/* 0xf5e: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf5e, 0x119, x86_l_119);
x86_l_f64:
	/* 0xf64: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_f69:
	/* 0xf69: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f6c:
	/* 0xf6c: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0xf6c, 0x119, x86_l_119);
x86_l_f71:
	/* 0xf71: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_f74:
	/* 0xf74: jg     13fe <generic_sleepable_offload+0x13fe> */
	X86_SIM_X86_JCC(X86_CC_G, 0xf74, 0x13fe, x86_l_13fe);
x86_l_f7a:
	/* 0xf7a: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_f7d:
	/* 0xf7d: je     1651 <generic_sleepable_offload+0x1651> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf7d, 0x1651, x86_l_1651);
x86_l_f83:
	/* 0xf83: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_f86:
	/* 0xf86: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf86, 0x119, x86_l_119);
x86_l_f8c:
	/* 0xf8c: mov    WORD PTR [rbx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f8f:
	/* 0xf8f: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0xf8f, 0x119, x86_l_119);
x86_l_f94:
	/* 0xf94: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_f97:
	/* 0xf97: jg     1418 <generic_sleepable_offload+0x1418> */
	X86_SIM_X86_JCC(X86_CC_G, 0xf97, 0x1418, x86_l_1418);
x86_l_f9d:
	/* 0xf9d: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_fa0:
	/* 0xfa0: je     18ec <generic_sleepable_offload+0x18ec> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfa0, 0x18ec, x86_l_18ec);
x86_l_fa6:
	/* 0xfa6: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_fa9:
	/* 0xfa9: je     17bf <generic_sleepable_offload+0x17bf> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfa9, 0x17bf, x86_l_17bf);
x86_l_faf:
	/* 0xfaf: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0xfaf, 0x119, x86_l_119);
x86_l_fb4:
	/* 0xfb4: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_fb7:
	/* 0xfb7: jg     142f <generic_sleepable_offload+0x142f> */
	X86_SIM_X86_JCC(X86_CC_G, 0xfb7, 0x142f, x86_l_142f);
x86_l_fbd:
	/* 0xfbd: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_fc0:
	/* 0xfc0: je     18f8 <generic_sleepable_offload+0x18f8> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfc0, 0x18f8, x86_l_18f8);
x86_l_fc6:
	/* 0xfc6: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_fc9:
	/* 0xfc9: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xfc9, 0x119, x86_l_119);
x86_l_fcf:
	/* 0xfcf: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_fd4:
	/* 0xfd4: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fd7:
	/* 0xfd7: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0xfd7, 0x119, x86_l_119);
x86_l_fdc:
	/* 0xfdc: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_fdf:
	/* 0xfdf: jg     144e <generic_sleepable_offload+0x144e> */
	X86_SIM_X86_JCC(X86_CC_G, 0xfdf, 0x144e, x86_l_144e);
x86_l_fe5:
	/* 0xfe5: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_fe8:
	/* 0xfe8: je     1658 <generic_sleepable_offload+0x1658> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfe8, 0x1658, x86_l_1658);
x86_l_fee:
	/* 0xfee: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_ff1:
	/* 0xff1: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xff1, 0x119, x86_l_119);
x86_l_ff7:
	/* 0xff7: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_ffc:
	/* 0xffc: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fff:
	/* 0xfff: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0xfff, 0x119, x86_l_119);
x86_l_1004:
	/* 0x1004: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_1007:
	/* 0x1007: jg     146d <generic_sleepable_offload+0x146d> */
	X86_SIM_X86_JCC(X86_CC_G, 0x1007, 0x146d, x86_l_146d);
x86_l_100d:
	/* 0x100d: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1010:
	/* 0x1010: je     1677 <generic_sleepable_offload+0x1677> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1010, 0x1677, x86_l_1677);
x86_l_1016:
	/* 0x1016: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1019:
	/* 0x1019: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1019, 0x119, x86_l_119);
x86_l_101f:
	/* 0x101f: mov    WORD PTR [rbp+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1023:
	/* 0x1023: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1023, 0x119, x86_l_119);
x86_l_1028:
	/* 0x1028: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_102b:
	/* 0x102b: jg     1488 <generic_sleepable_offload+0x1488> */
	X86_SIM_X86_JCC(X86_CC_G, 0x102b, 0x1488, x86_l_1488);
x86_l_1031:
	/* 0x1031: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1034:
	/* 0x1034: je     18a6 <generic_sleepable_offload+0x18a6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1034, 0x18a6, x86_l_18a6);
x86_l_103a:
	/* 0x103a: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_103d:
	/* 0x103d: je     1843 <generic_sleepable_offload+0x1843> */
	X86_SIM_X86_JCC(X86_CC_E, 0x103d, 0x1843, x86_l_1843);
x86_l_1043:
	/* 0x1043: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1043, 0x119, x86_l_119);
x86_l_1048:
	/* 0x1048: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_104b:
	/* 0x104b: jg     149f <generic_sleepable_offload+0x149f> */
	X86_SIM_X86_JCC(X86_CC_G, 0x104b, 0x149f, x86_l_149f);
x86_l_1051:
	/* 0x1051: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1054:
	/* 0x1054: je     1923 <generic_sleepable_offload+0x1923> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1054, 0x1923, x86_l_1923);
x86_l_105a:
	/* 0x105a: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_105d:
	/* 0x105d: je     107f <generic_sleepable_offload+0x107f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x105d, 0x107f, x86_l_107f);
x86_l_105f:
	/* 0x105f: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x105f, 0x119, x86_l_119);
x86_l_1064:
	/* 0x1064: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_1067:
	/* 0x1067: jg     14b2 <generic_sleepable_offload+0x14b2> */
	X86_SIM_X86_JCC(X86_CC_G, 0x1067, 0x14b2, x86_l_14b2);
x86_l_106d:
	/* 0x106d: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1070:
	/* 0x1070: je     185e <generic_sleepable_offload+0x185e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1070, 0x185e, x86_l_185e);
x86_l_1076:
	/* 0x1076: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1079:
	/* 0x1079: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1079, 0x119, x86_l_119);
x86_l_107f:
	/* 0x107f: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1084:
	/* 0x1084: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1087:
	/* 0x1087: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1087, 0x119, x86_l_119);
x86_l_108c:
	/* 0x108c: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_108f:
	/* 0x108f: jg     14c5 <generic_sleepable_offload+0x14c5> */
	X86_SIM_X86_JCC(X86_CC_G, 0x108f, 0x14c5, x86_l_14c5);
x86_l_1095:
	/* 0x1095: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1098:
	/* 0x1098: je     185e <generic_sleepable_offload+0x185e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1098, 0x185e, x86_l_185e);
x86_l_109e:
	/* 0x109e: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_10a1:
	/* 0x10a1: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x10a1, 0x119, x86_l_119);
x86_l_10a7:
	/* 0x10a7: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_10ac:
	/* 0x10ac: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10af:
	/* 0x10af: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x10af, 0x119, x86_l_119);
x86_l_10b4:
	/* 0x10b4: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_10b7:
	/* 0x10b7: je     16b6 <generic_sleepable_offload+0x16b6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10b7, 0x16b6, x86_l_16b6);
x86_l_10bd:
	/* 0x10bd: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_10c0:
	/* 0x10c0: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x10c0, 0x119, x86_l_119);
x86_l_10c6:
	/* 0x10c6: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_10cb:
	/* 0x10cb: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10ce:
	/* 0x10ce: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x10ce, 0x119, x86_l_119);
x86_l_10d3:
	/* 0x10d3: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_10d6:
	/* 0x10d6: je     16c2 <generic_sleepable_offload+0x16c2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10d6, 0x16c2, x86_l_16c2);
x86_l_10dc:
	/* 0x10dc: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_10df:
	/* 0x10df: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x10df, 0x119, x86_l_119);
x86_l_10e5:
	/* 0x10e5: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_10ea:
	/* 0x10ea: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10ed:
	/* 0x10ed: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x10ed, 0x119, x86_l_119);
x86_l_10f2:
	/* 0x10f2: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_10f5:
	/* 0x10f5: je     16ce <generic_sleepable_offload+0x16ce> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10f5, 0x16ce, x86_l_16ce);
x86_l_10fb:
	/* 0x10fb: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_10fe:
	/* 0x10fe: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x10fe, 0x119, x86_l_119);
x86_l_1104:
	/* 0x1104: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1109:
	/* 0x1109: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_110c:
	/* 0x110c: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x110c, 0x119, x86_l_119);
x86_l_1111:
	/* 0x1111: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_1114:
	/* 0x1114: je     171a <generic_sleepable_offload+0x171a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1114, 0x171a, x86_l_171a);
x86_l_111a:
	/* 0x111a: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_111d:
	/* 0x111d: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x111d, 0x119, x86_l_119);
x86_l_1123:
	/* 0x1123: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_1126:
	/* 0x1126: jg     19d3 <generic_sleepable_offload+0x19d3> */
	X86_SIM_X86_JCC(X86_CC_G, 0x1126, 0x19d3, x86_l_19d3);
x86_l_112c:
	/* 0x112c: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_112f:
	/* 0x112f: je     1886 <generic_sleepable_offload+0x1886> */
	X86_SIM_X86_JCC(X86_CC_E, 0x112f, 0x1886, x86_l_1886);
x86_l_1135:
	/* 0x1135: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1138:
	/* 0x1138: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1138, 0x119, x86_l_119);
x86_l_113e:
	/* 0x113e: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1143:
	/* 0x1143: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1146:
	/* 0x1146: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1146, 0x119, x86_l_119);
x86_l_114b:
	/* 0x114b: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_114e:
	/* 0x114e: je     17d6 <generic_sleepable_offload+0x17d6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x114e, 0x17d6, x86_l_17d6);
x86_l_1154:
	/* 0x1154: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_1157:
	/* 0x1157: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1157, 0x119, x86_l_119);
x86_l_115d:
	/* 0x115d: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_1160:
	/* 0x1160: jg     1afd <generic_sleepable_offload+0x1afd> */
	X86_SIM_X86_JCC(X86_CC_G, 0x1160, 0x1afd, x86_l_1afd);
x86_l_1166:
	/* 0x1166: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1169:
	/* 0x1169: je     15f3 <generic_sleepable_offload+0x15f3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1169, 0x15f3, x86_l_15f3);
x86_l_116f:
	/* 0x116f: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1172:
	/* 0x1172: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1172, 0x119, x86_l_119);
x86_l_1178:
	/* 0x1178: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_117d:
	/* 0x117d: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1180:
	/* 0x1180: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1180, 0x119, x86_l_119);
x86_l_1185:
	/* 0x1185: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_1188:
	/* 0x1188: je     1804 <generic_sleepable_offload+0x1804> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1188, 0x1804, x86_l_1804);
x86_l_118e:
	/* 0x118e: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_1191:
	/* 0x1191: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1191, 0x119, x86_l_119);
x86_l_1197:
	/* 0x1197: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_119a:
	/* 0x119a: jg     1b24 <generic_sleepable_offload+0x1b24> */
	X86_SIM_X86_JCC(X86_CC_G, 0x119a, 0x1b24, x86_l_1b24);
x86_l_11a0:
	/* 0x11a0: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_11a3:
	/* 0x11a3: je     18c3 <generic_sleepable_offload+0x18c3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11a3, 0x18c3, x86_l_18c3);
x86_l_11a9:
	/* 0x11a9: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_11ac:
	/* 0x11ac: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x11ac, 0x119, x86_l_119);
x86_l_11b2:
	/* 0x11b2: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_11b7:
	/* 0x11b7: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11ba:
	/* 0x11ba: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x11ba, 0x119, x86_l_119);
x86_l_11bf:
	/* 0x11bf: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_11c2:
	/* 0x11c2: je     184c <generic_sleepable_offload+0x184c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11c2, 0x184c, x86_l_184c);
x86_l_11c8:
	/* 0x11c8: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_11cb:
	/* 0x11cb: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x11cb, 0x119, x86_l_119);
x86_l_11d1:
	/* 0x11d1: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_11d4:
	/* 0x11d4: jg     1207 <generic_sleepable_offload+0x1207> */
	X86_SIM_X86_JCC(X86_CC_G, 0x11d4, 0x1207, x86_l_1207);
x86_l_11d6:
	/* 0x11d6: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_11d9:
	/* 0x11d9: jne    ca0 <generic_sleepable_offload+0xca0> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x11d9, 0xca0, x86_l_ca0);
x86_l_11df:
	/* 0x11df: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_11e4:
	/* 0x11e4: jmp    117 <generic_sleepable_offload+0x117> */
	X86_SIM_X86_JMP(0x11e4, 0x117, x86_l_117);
x86_l_11e9:
	/* 0x11e9: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_11ec:
	/* 0x11ec: je     18ae <generic_sleepable_offload+0x18ae> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11ec, 0x18ae, x86_l_18ae);
x86_l_11f2:
	/* 0x11f2: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_11f5:
	/* 0x11f5: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x11f5, 0x119, x86_l_119);
x86_l_11fb:
	/* 0x11fb: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11ff:
	/* 0x11ff: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1202:
	/* 0x1202: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1202, 0x119, x86_l_119);
x86_l_1207:
	/* 0x1207: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_120a:
	/* 0x120a: je     18cd <generic_sleepable_offload+0x18cd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x120a, 0x18cd, x86_l_18cd);
x86_l_1210:
	/* 0x1210: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1213:
	/* 0x1213: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1213, 0x119, x86_l_119);
x86_l_1219:
	/* 0x1219: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_121e:
	/* 0x121e: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1221:
	/* 0x1221: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1221, 0x119, x86_l_119);
x86_l_1226:
	/* 0x1226: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1229:
	/* 0x1229: je     1289 <generic_sleepable_offload+0x1289> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1229, 0x1289, x86_l_1289);
x86_l_122b:
	/* 0x122b: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_122e:
	/* 0x122e: je     127c <generic_sleepable_offload+0x127c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x122e, 0x127c, x86_l_127c);
x86_l_1230:
	/* 0x1230: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1230, 0x119, x86_l_119);
x86_l_1235:
	/* 0x1235: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1238:
	/* 0x1238: je     12b0 <generic_sleepable_offload+0x12b0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1238, 0x12b0, x86_l_12b0);
x86_l_123a:
	/* 0x123a: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_123d:
	/* 0x123d: je     12a3 <generic_sleepable_offload+0x12a3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x123d, 0x12a3, x86_l_12a3);
x86_l_123f:
	/* 0x123f: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x123f, 0x119, x86_l_119);
x86_l_1244:
	/* 0x1244: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1247:
	/* 0x1247: je     1289 <generic_sleepable_offload+0x1289> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1247, 0x1289, x86_l_1289);
x86_l_1249:
	/* 0x1249: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_124c:
	/* 0x124c: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x124c, 0x119, x86_l_119);
x86_l_1252:
	/* 0x1252: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1257:
	/* 0x1257: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_125a:
	/* 0x125a: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x125a, 0x119, x86_l_119);
x86_l_125f:
	/* 0x125f: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1262:
	/* 0x1262: je     12b0 <generic_sleepable_offload+0x12b0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1262, 0x12b0, x86_l_12b0);
x86_l_1264:
	/* 0x1264: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1267:
	/* 0x1267: je     12a3 <generic_sleepable_offload+0x12a3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1267, 0x12a3, x86_l_12a3);
x86_l_1269:
	/* 0x1269: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1269, 0x119, x86_l_119);
x86_l_126e:
	/* 0x126e: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1271:
	/* 0x1271: je     1289 <generic_sleepable_offload+0x1289> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1271, 0x1289, x86_l_1289);
x86_l_1273:
	/* 0x1273: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1276:
	/* 0x1276: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1276, 0x119, x86_l_119);
x86_l_127c:
	/* 0x127c: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1281:
	/* 0x1281: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1284:
	/* 0x1284: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1284, 0x119, x86_l_119);
x86_l_1289:
	/* 0x1289: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_128e:
	/* 0x128e: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1290:
	/* 0x1290: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1290, 0x119, x86_l_119);
x86_l_1295:
	/* 0x1295: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1298:
	/* 0x1298: je     12b0 <generic_sleepable_offload+0x12b0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1298, 0x12b0, x86_l_12b0);
x86_l_129a:
	/* 0x129a: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_129d:
	/* 0x129d: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x129d, 0x119, x86_l_119);
x86_l_12a3:
	/* 0x12a3: mov    rcx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_12a8:
	/* 0x12a8: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12ab:
	/* 0x12ab: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x12ab, 0x119, x86_l_119);
x86_l_12b0:
	/* 0x12b0: mov    rcx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_12b5:
	/* 0x12b5: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12b7:
	/* 0x12b7: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x12b7, 0x119, x86_l_119);
x86_l_12bc:
	/* 0x12bc: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_12bf:
	/* 0x12bf: je     132e <generic_sleepable_offload+0x132e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12bf, 0x132e, x86_l_132e);
x86_l_12c1:
	/* 0x12c1: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_12c4:
	/* 0x12c4: je     1321 <generic_sleepable_offload+0x1321> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12c4, 0x1321, x86_l_1321);
x86_l_12c6:
	/* 0x12c6: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x12c6, 0x119, x86_l_119);
x86_l_12cb:
	/* 0x12cb: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_12ce:
	/* 0x12ce: je     1355 <generic_sleepable_offload+0x1355> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12ce, 0x1355, x86_l_1355);
x86_l_12d4:
	/* 0x12d4: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_12d7:
	/* 0x12d7: je     1348 <generic_sleepable_offload+0x1348> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12d7, 0x1348, x86_l_1348);
x86_l_12d9:
	/* 0x12d9: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x12d9, 0x119, x86_l_119);
x86_l_12de:
	/* 0x12de: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_12e1:
	/* 0x12e1: je     162d <generic_sleepable_offload+0x162d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12e1, 0x162d, x86_l_162d);
x86_l_12e7:
	/* 0x12e7: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_12ea:
	/* 0x12ea: je     1373 <generic_sleepable_offload+0x1373> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12ea, 0x1373, x86_l_1373);
x86_l_12f0:
	/* 0x12f0: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x12f0, 0x119, x86_l_119);
x86_l_12f5:
	/* 0x12f5: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_12f8:
	/* 0x12f8: je     132e <generic_sleepable_offload+0x132e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12f8, 0x132e, x86_l_132e);
x86_l_12fa:
	/* 0x12fa: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_12fd:
	/* 0x12fd: je     1321 <generic_sleepable_offload+0x1321> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12fd, 0x1321, x86_l_1321);
x86_l_12ff:
	/* 0x12ff: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x12ff, 0x119, x86_l_119);
x86_l_1304:
	/* 0x1304: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1307:
	/* 0x1307: je     1355 <generic_sleepable_offload+0x1355> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1307, 0x1355, x86_l_1355);
x86_l_1309:
	/* 0x1309: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_130c:
	/* 0x130c: je     1348 <generic_sleepable_offload+0x1348> */
	X86_SIM_X86_JCC(X86_CC_E, 0x130c, 0x1348, x86_l_1348);
x86_l_130e:
	/* 0x130e: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x130e, 0x119, x86_l_119);
x86_l_1313:
	/* 0x1313: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1316:
	/* 0x1316: je     132e <generic_sleepable_offload+0x132e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1316, 0x132e, x86_l_132e);
x86_l_1318:
	/* 0x1318: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_131b:
	/* 0x131b: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x131b, 0x119, x86_l_119);
x86_l_1321:
	/* 0x1321: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1326:
	/* 0x1326: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1329:
	/* 0x1329: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1329, 0x119, x86_l_119);
x86_l_132e:
	/* 0x132e: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1333:
	/* 0x1333: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1335:
	/* 0x1335: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1335, 0x119, x86_l_119);
x86_l_133a:
	/* 0x133a: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_133d:
	/* 0x133d: je     1355 <generic_sleepable_offload+0x1355> */
	X86_SIM_X86_JCC(X86_CC_E, 0x133d, 0x1355, x86_l_1355);
x86_l_133f:
	/* 0x133f: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1342:
	/* 0x1342: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1342, 0x119, x86_l_119);
x86_l_1348:
	/* 0x1348: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_134d:
	/* 0x134d: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1350:
	/* 0x1350: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1350, 0x119, x86_l_119);
x86_l_1355:
	/* 0x1355: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_135a:
	/* 0x135a: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_135c:
	/* 0x135c: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x135c, 0x119, x86_l_119);
x86_l_1361:
	/* 0x1361: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1364:
	/* 0x1364: je     162d <generic_sleepable_offload+0x162d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1364, 0x162d, x86_l_162d);
x86_l_136a:
	/* 0x136a: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_136d:
	/* 0x136d: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x136d, 0x119, x86_l_119);
x86_l_1373:
	/* 0x1373: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1378:
	/* 0x1378: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_137b:
	/* 0x137b: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x137b, 0x119, x86_l_119);
x86_l_1380:
	/* 0x1380: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1383:
	/* 0x1383: je     1664 <generic_sleepable_offload+0x1664> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1383, 0x1664, x86_l_1664);
x86_l_1389:
	/* 0x1389: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_138c:
	/* 0x138c: je     1410 <generic_sleepable_offload+0x1410> */
	X86_SIM_X86_JCC(X86_CC_E, 0x138c, 0x1410, x86_l_1410);
x86_l_1392:
	/* 0x1392: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1392, 0x119, x86_l_119);
x86_l_1397:
	/* 0x1397: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_139a:
	/* 0x139a: je     166b <generic_sleepable_offload+0x166b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x139a, 0x166b, x86_l_166b);
x86_l_13a0:
	/* 0x13a0: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_13a3:
	/* 0x13a3: je     1460 <generic_sleepable_offload+0x1460> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13a3, 0x1460, x86_l_1460);
x86_l_13a9:
	/* 0x13a9: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x13a9, 0x119, x86_l_119);
x86_l_13ae:
	/* 0x13ae: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_13b1:
	/* 0x13b1: je     167f <generic_sleepable_offload+0x167f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13b1, 0x167f, x86_l_167f);
x86_l_13b7:
	/* 0x13b7: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_13ba:
	/* 0x13ba: je     147f <generic_sleepable_offload+0x147f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13ba, 0x147f, x86_l_147f);
x86_l_13c0:
	/* 0x13c0: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x13c0, 0x119, x86_l_119);
x86_l_13c5:
	/* 0x13c5: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_13c8:
	/* 0x13c8: je     1904 <generic_sleepable_offload+0x1904> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13c8, 0x1904, x86_l_1904);
x86_l_13ce:
	/* 0x13ce: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_13d1:
	/* 0x13d1: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x13d1, 0x119, x86_l_119);
x86_l_13d7:
	/* 0x13d7: mov    QWORD PTR [rbx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13da:
	/* 0x13da: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x13da, 0x119, x86_l_119);
x86_l_13df:
	/* 0x13df: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_13e2:
	/* 0x13e2: je     190b <generic_sleepable_offload+0x190b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13e2, 0x190b, x86_l_190b);
x86_l_13e8:
	/* 0x13e8: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_13eb:
	/* 0x13eb: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x13eb, 0x119, x86_l_119);
x86_l_13f1:
	/* 0x13f1: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_13f6:
	/* 0x13f6: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13f9:
	/* 0x13f9: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x13f9, 0x119, x86_l_119);
x86_l_13fe:
	/* 0x13fe: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1401:
	/* 0x1401: je     1664 <generic_sleepable_offload+0x1664> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1401, 0x1664, x86_l_1664);
x86_l_1407:
	/* 0x1407: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_140a:
	/* 0x140a: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x140a, 0x119, x86_l_119);
x86_l_1410:
	/* 0x1410: mov    QWORD PTR [rbx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1413:
	/* 0x1413: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1413, 0x119, x86_l_119);
x86_l_1418:
	/* 0x1418: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_141b:
	/* 0x141b: je     1a27 <generic_sleepable_offload+0x1a27> */
	X86_SIM_X86_JCC(X86_CC_E, 0x141b, 0x1a27, x86_l_1a27);
x86_l_1421:
	/* 0x1421: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1424:
	/* 0x1424: je     1a1a <generic_sleepable_offload+0x1a1a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1424, 0x1a1a, x86_l_1a1a);
x86_l_142a:
	/* 0x142a: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x142a, 0x119, x86_l_119);
x86_l_142f:
	/* 0x142f: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1432:
	/* 0x1432: je     1917 <generic_sleepable_offload+0x1917> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1432, 0x1917, x86_l_1917);
x86_l_1438:
	/* 0x1438: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_143b:
	/* 0x143b: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x143b, 0x119, x86_l_119);
x86_l_1441:
	/* 0x1441: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1446:
	/* 0x1446: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1449:
	/* 0x1449: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1449, 0x119, x86_l_119);
x86_l_144e:
	/* 0x144e: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1451:
	/* 0x1451: je     166b <generic_sleepable_offload+0x166b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1451, 0x166b, x86_l_166b);
x86_l_1457:
	/* 0x1457: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_145a:
	/* 0x145a: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x145a, 0x119, x86_l_119);
x86_l_1460:
	/* 0x1460: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1465:
	/* 0x1465: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1468:
	/* 0x1468: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1468, 0x119, x86_l_119);
x86_l_146d:
	/* 0x146d: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1470:
	/* 0x1470: je     167f <generic_sleepable_offload+0x167f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1470, 0x167f, x86_l_167f);
x86_l_1476:
	/* 0x1476: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1479:
	/* 0x1479: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1479, 0x119, x86_l_119);
x86_l_147f:
	/* 0x147f: mov    QWORD PTR [rbp+0x0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1483:
	/* 0x1483: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1483, 0x119, x86_l_119);
x86_l_1488:
	/* 0x1488: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_148b:
	/* 0x148b: je     1a88 <generic_sleepable_offload+0x1a88> */
	X86_SIM_X86_JCC(X86_CC_E, 0x148b, 0x1a88, x86_l_1a88);
x86_l_1491:
	/* 0x1491: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1494:
	/* 0x1494: je     1a7f <generic_sleepable_offload+0x1a7f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1494, 0x1a7f, x86_l_1a7f);
x86_l_149a:
	/* 0x149a: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x149a, 0x119, x86_l_119);
x86_l_149f:
	/* 0x149f: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_14a2:
	/* 0x14a2: je     1687 <generic_sleepable_offload+0x1687> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14a2, 0x1687, x86_l_1687);
x86_l_14a8:
	/* 0x14a8: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_14ab:
	/* 0x14ab: je     14d7 <generic_sleepable_offload+0x14d7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14ab, 0x14d7, x86_l_14d7);
x86_l_14ad:
	/* 0x14ad: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x14ad, 0x119, x86_l_119);
x86_l_14b2:
	/* 0x14b2: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_14b5:
	/* 0x14b5: je     1687 <generic_sleepable_offload+0x1687> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14b5, 0x1687, x86_l_1687);
x86_l_14bb:
	/* 0x14bb: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_14be:
	/* 0x14be: je     14d7 <generic_sleepable_offload+0x14d7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14be, 0x14d7, x86_l_14d7);
x86_l_14c0:
	/* 0x14c0: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x14c0, 0x119, x86_l_119);
x86_l_14c5:
	/* 0x14c5: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_14c8:
	/* 0x14c8: je     1aab <generic_sleepable_offload+0x1aab> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14c8, 0x1aab, x86_l_1aab);
x86_l_14ce:
	/* 0x14ce: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_14d1:
	/* 0x14d1: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x14d1, 0x119, x86_l_119);
x86_l_14d7:
	/* 0x14d7: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_14dc:
	/* 0x14dc: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14df:
	/* 0x14df: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x14df, 0x119, x86_l_119);
x86_l_14e4:
	/* 0x14e4: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_14e7:
	/* 0x14e7: je     1693 <generic_sleepable_offload+0x1693> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14e7, 0x1693, x86_l_1693);
x86_l_14ed:
	/* 0x14ed: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_14f0:
	/* 0x14f0: je     1509 <generic_sleepable_offload+0x1509> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14f0, 0x1509, x86_l_1509);
x86_l_14f2:
	/* 0x14f2: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x14f2, 0x119, x86_l_119);
x86_l_14f7:
	/* 0x14f7: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_14fa:
	/* 0x14fa: je     1693 <generic_sleepable_offload+0x1693> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14fa, 0x1693, x86_l_1693);
x86_l_1500:
	/* 0x1500: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1503:
	/* 0x1503: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1503, 0x119, x86_l_119);
x86_l_1509:
	/* 0x1509: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_150d:
	/* 0x150d: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1510:
	/* 0x1510: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1510, 0x119, x86_l_119);
x86_l_1515:
	/* 0x1515: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1518:
	/* 0x1518: je     16da <generic_sleepable_offload+0x16da> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1518, 0x16da, x86_l_16da);
x86_l_151e:
	/* 0x151e: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1521:
	/* 0x1521: je     15aa <generic_sleepable_offload+0x15aa> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1521, 0x15aa, x86_l_15aa);
x86_l_1527:
	/* 0x1527: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1527, 0x119, x86_l_119);
x86_l_152c:
	/* 0x152c: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_152f:
	/* 0x152f: je     1952 <generic_sleepable_offload+0x1952> */
	X86_SIM_X86_JCC(X86_CC_E, 0x152f, 0x1952, x86_l_1952);
x86_l_1535:
	/* 0x1535: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1538:
	/* 0x1538: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1538, 0x119, x86_l_119);
x86_l_153e:
	/* 0x153e: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1543:
	/* 0x1543: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1546:
	/* 0x1546: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1546, 0x119, x86_l_119);
x86_l_154b:
	/* 0x154b: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_154e:
	/* 0x154e: je     195e <generic_sleepable_offload+0x195e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x154e, 0x195e, x86_l_195e);
x86_l_1554:
	/* 0x1554: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1557:
	/* 0x1557: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1557, 0x119, x86_l_119);
x86_l_155d:
	/* 0x155d: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1562:
	/* 0x1562: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1565:
	/* 0x1565: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1565, 0x119, x86_l_119);
x86_l_156a:
	/* 0x156a: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_156d:
	/* 0x156d: je     1af1 <generic_sleepable_offload+0x1af1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x156d, 0x1af1, x86_l_1af1);
x86_l_1573:
	/* 0x1573: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1576:
	/* 0x1576: je     1ae4 <generic_sleepable_offload+0x1ae4> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1576, 0x1ae4, x86_l_1ae4);
x86_l_157c:
	/* 0x157c: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x157c, 0x119, x86_l_119);
x86_l_1581:
	/* 0x1581: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1584:
	/* 0x1584: je     1b18 <generic_sleepable_offload+0x1b18> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1584, 0x1b18, x86_l_1b18);
x86_l_158a:
	/* 0x158a: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_158d:
	/* 0x158d: je     1b0b <generic_sleepable_offload+0x1b0b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x158d, 0x1b0b, x86_l_1b0b);
x86_l_1593:
	/* 0x1593: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1593, 0x119, x86_l_119);
x86_l_1598:
	/* 0x1598: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_159b:
	/* 0x159b: je     16da <generic_sleepable_offload+0x16da> */
	X86_SIM_X86_JCC(X86_CC_E, 0x159b, 0x16da, x86_l_16da);
x86_l_15a1:
	/* 0x15a1: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_15a4:
	/* 0x15a4: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x15a4, 0x119, x86_l_119);
x86_l_15aa:
	/* 0x15aa: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_15af:
	/* 0x15af: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15b2:
	/* 0x15b2: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x15b2, 0x119, x86_l_119);
x86_l_15b7:
	/* 0x15b7: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_15ba:
	/* 0x15ba: je     16e6 <generic_sleepable_offload+0x16e6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x15ba, 0x16e6, x86_l_16e6);
x86_l_15c0:
	/* 0x15c0: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_15c3:
	/* 0x15c3: je     15dc <generic_sleepable_offload+0x15dc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x15c3, 0x15dc, x86_l_15dc);
x86_l_15c5:
	/* 0x15c5: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x15c5, 0x119, x86_l_119);
x86_l_15ca:
	/* 0x15ca: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_15cd:
	/* 0x15cd: je     16e6 <generic_sleepable_offload+0x16e6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x15cd, 0x16e6, x86_l_16e6);
x86_l_15d3:
	/* 0x15d3: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_15d6:
	/* 0x15d6: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x15d6, 0x119, x86_l_119);
x86_l_15dc:
	/* 0x15dc: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_15e1:
	/* 0x15e1: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15e4:
	/* 0x15e4: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x15e4, 0x119, x86_l_119);
x86_l_15e9:
	/* 0x15e9: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15ee:
	/* 0x15ee: jmp    117 <generic_sleepable_offload+0x117> */
	X86_SIM_X86_JMP(0x15ee, 0x117, x86_l_117);
x86_l_15f3:
	/* 0x15f3: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15f8:
	/* 0x15f8: jmp    117 <generic_sleepable_offload+0x117> */
	X86_SIM_X86_JMP(0x15f8, 0x117, x86_l_117);
x86_l_15fd:
	/* 0x15fd: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1602:
	/* 0x1602: mov    BYTE PTR [rcx],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1604:
	/* 0x1604: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1604, 0x119, x86_l_119);
x86_l_1609:
	/* 0x1609: mov    rcx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_160e:
	/* 0x160e: mov    BYTE PTR [rcx],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1610:
	/* 0x1610: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1610, 0x119, x86_l_119);
x86_l_1615:
	/* 0x1615: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_161a:
	/* 0x161a: mov    BYTE PTR [rcx],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_161c:
	/* 0x161c: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x161c, 0x119, x86_l_119);
x86_l_1621:
	/* 0x1621: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1626:
	/* 0x1626: mov    BYTE PTR [rcx],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1628:
	/* 0x1628: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1628, 0x119, x86_l_119);
x86_l_162d:
	/* 0x162d: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1632:
	/* 0x1632: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1634:
	/* 0x1634: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1634, 0x119, x86_l_119);
x86_l_1639:
	/* 0x1639: mov    rcx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_163e:
	/* 0x163e: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1640:
	/* 0x1640: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1640, 0x119, x86_l_119);
x86_l_1645:
	/* 0x1645: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_164a:
	/* 0x164a: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_164c:
	/* 0x164c: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x164c, 0x119, x86_l_119);
x86_l_1651:
	/* 0x1651: mov    BYTE PTR [rbx],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1653:
	/* 0x1653: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1653, 0x119, x86_l_119);
x86_l_1658:
	/* 0x1658: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_165d:
	/* 0x165d: mov    BYTE PTR [rcx],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_165f:
	/* 0x165f: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x165f, 0x119, x86_l_119);
x86_l_1664:
	/* 0x1664: mov    DWORD PTR [rbx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1666:
	/* 0x1666: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1666, 0x119, x86_l_119);
x86_l_166b:
	/* 0x166b: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1670:
	/* 0x1670: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1672:
	/* 0x1672: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1672, 0x119, x86_l_119);
x86_l_1677:
	/* 0x1677: mov    BYTE PTR [rbp+0x0],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_167a:
	/* 0x167a: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x167a, 0x119, x86_l_119);
x86_l_167f:
	/* 0x167f: mov    DWORD PTR [rbp+0x0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1682:
	/* 0x1682: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1682, 0x119, x86_l_119);
x86_l_1687:
	/* 0x1687: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_168c:
	/* 0x168c: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_168e:
	/* 0x168e: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x168e, 0x119, x86_l_119);
x86_l_1693:
	/* 0x1693: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1697:
	/* 0x1697: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1699:
	/* 0x1699: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1699, 0x119, x86_l_119);
x86_l_169e:
	/* 0x169e: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_16a3:
	/* 0x16a3: mov    BYTE PTR [rcx],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16a5:
	/* 0x16a5: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x16a5, 0x119, x86_l_119);
x86_l_16aa:
	/* 0x16aa: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_16af:
	/* 0x16af: mov    BYTE PTR [rcx],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16b1:
	/* 0x16b1: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x16b1, 0x119, x86_l_119);
x86_l_16b6:
	/* 0x16b6: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16bb:
	/* 0x16bb: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16bd:
	/* 0x16bd: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x16bd, 0x119, x86_l_119);
x86_l_16c2:
	/* 0x16c2: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_16c7:
	/* 0x16c7: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16c9:
	/* 0x16c9: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x16c9, 0x119, x86_l_119);
x86_l_16ce:
	/* 0x16ce: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_16d3:
	/* 0x16d3: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16d5:
	/* 0x16d5: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x16d5, 0x119, x86_l_119);
x86_l_16da:
	/* 0x16da: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_16df:
	/* 0x16df: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16e1:
	/* 0x16e1: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x16e1, 0x119, x86_l_119);
x86_l_16e6:
	/* 0x16e6: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_16eb:
	/* 0x16eb: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16ed:
	/* 0x16ed: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x16ed, 0x119, x86_l_119);
x86_l_16f2:
	/* 0x16f2: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_16f5:
	/* 0x16f5: jg     1976 <generic_sleepable_offload+0x1976> */
	X86_SIM_X86_JCC(X86_CC_G, 0x16f5, 0x1976, x86_l_1976);
x86_l_16fb:
	/* 0x16fb: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_16fe:
	/* 0x16fe: je     1868 <generic_sleepable_offload+0x1868> */
	X86_SIM_X86_JCC(X86_CC_E, 0x16fe, 0x1868, x86_l_1868);
x86_l_1704:
	/* 0x1704: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1707:
	/* 0x1707: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1707, 0x119, x86_l_119);
x86_l_170d:
	/* 0x170d: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1712:
	/* 0x1712: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1715:
	/* 0x1715: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1715, 0x119, x86_l_119);
x86_l_171a:
	/* 0x171a: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_171d:
	/* 0x171d: jg     1995 <generic_sleepable_offload+0x1995> */
	X86_SIM_X86_JCC(X86_CC_G, 0x171d, 0x1995, x86_l_1995);
x86_l_1723:
	/* 0x1723: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1726:
	/* 0x1726: je     1872 <generic_sleepable_offload+0x1872> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1726, 0x1872, x86_l_1872);
x86_l_172c:
	/* 0x172c: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_172f:
	/* 0x172f: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x172f, 0x119, x86_l_119);
x86_l_1735:
	/* 0x1735: mov    rcx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_173a:
	/* 0x173a: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_173d:
	/* 0x173d: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x173d, 0x119, x86_l_119);
x86_l_1742:
	/* 0x1742: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_1745:
	/* 0x1745: jg     1766 <generic_sleepable_offload+0x1766> */
	X86_SIM_X86_JCC(X86_CC_G, 0x1745, 0x1766, x86_l_1766);
x86_l_1747:
	/* 0x1747: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_174a:
	/* 0x174a: je     112 <generic_sleepable_offload+0x112> */
	X86_SIM_X86_JCC(X86_CC_E, 0x174a, 0x112, x86_l_112);
x86_l_1750:
	/* 0x1750: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1753:
	/* 0x1753: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1753, 0x119, x86_l_119);
x86_l_1759:
	/* 0x1759: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_175e:
	/* 0x175e: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1761:
	/* 0x1761: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1761, 0x119, x86_l_119);
x86_l_1766:
	/* 0x1766: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1769:
	/* 0x1769: je     1890 <generic_sleepable_offload+0x1890> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1769, 0x1890, x86_l_1890);
x86_l_176f:
	/* 0x176f: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1772:
	/* 0x1772: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1772, 0x119, x86_l_119);
x86_l_1778:
	/* 0x1778: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_177d:
	/* 0x177d: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1780:
	/* 0x1780: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1780, 0x119, x86_l_119);
x86_l_1785:
	/* 0x1785: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_1788:
	/* 0x1788: jg     19f2 <generic_sleepable_offload+0x19f2> */
	X86_SIM_X86_JCC(X86_CC_G, 0x1788, 0x19f2, x86_l_19f2);
x86_l_178e:
	/* 0x178e: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1791:
	/* 0x1791: je     1b6f <generic_sleepable_offload+0x1b6f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1791, 0x1b6f, x86_l_1b6f);
x86_l_1797:
	/* 0x1797: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_179a:
	/* 0x179a: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x179a, 0x119, x86_l_119);
x86_l_17a0:
	/* 0x17a0: mov    WORD PTR [rbx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17a3:
	/* 0x17a3: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x17a3, 0x119, x86_l_119);
x86_l_17a8:
	/* 0x17a8: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_17ab:
	/* 0x17ab: jg     1a0c <generic_sleepable_offload+0x1a0c> */
	X86_SIM_X86_JCC(X86_CC_G, 0x17ab, 0x1a0c, x86_l_1a0c);
x86_l_17b1:
	/* 0x17b1: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_17b4:
	/* 0x17b4: je     17cc <generic_sleepable_offload+0x17cc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x17b4, 0x17cc, x86_l_17cc);
x86_l_17b6:
	/* 0x17b6: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_17b9:
	/* 0x17b9: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x17b9, 0x119, x86_l_119);
x86_l_17bf:
	/* 0x17bf: mov    rcx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_17c4:
	/* 0x17c4: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17c7:
	/* 0x17c7: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x17c7, 0x119, x86_l_119);
x86_l_17cc:
	/* 0x17cc: mov    rcx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_17d1:
	/* 0x17d1: jmp    117 <generic_sleepable_offload+0x117> */
	X86_SIM_X86_JMP(0x17d1, 0x117, x86_l_117);
x86_l_17d6:
	/* 0x17d6: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_17d9:
	/* 0x17d9: jg     1a33 <generic_sleepable_offload+0x1a33> */
	X86_SIM_X86_JCC(X86_CC_G, 0x17d9, 0x1a33, x86_l_1a33);
x86_l_17df:
	/* 0x17df: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_17e2:
	/* 0x17e2: je     17fa <generic_sleepable_offload+0x17fa> */
	X86_SIM_X86_JCC(X86_CC_E, 0x17e2, 0x17fa, x86_l_17fa);
x86_l_17e4:
	/* 0x17e4: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_17e7:
	/* 0x17e7: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x17e7, 0x119, x86_l_119);
x86_l_17ed:
	/* 0x17ed: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_17f2:
	/* 0x17f2: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17f5:
	/* 0x17f5: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x17f5, 0x119, x86_l_119);
x86_l_17fa:
	/* 0x17fa: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_17ff:
	/* 0x17ff: jmp    117 <generic_sleepable_offload+0x117> */
	X86_SIM_X86_JMP(0x17ff, 0x117, x86_l_117);
x86_l_1804:
	/* 0x1804: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_1807:
	/* 0x1807: jg     1a52 <generic_sleepable_offload+0x1a52> */
	X86_SIM_X86_JCC(X86_CC_G, 0x1807, 0x1a52, x86_l_1a52);
x86_l_180d:
	/* 0x180d: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1810:
	/* 0x1810: je     189c <generic_sleepable_offload+0x189c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1810, 0x189c, x86_l_189c);
x86_l_1816:
	/* 0x1816: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1819:
	/* 0x1819: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1819, 0x119, x86_l_119);
x86_l_181f:
	/* 0x181f: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1824:
	/* 0x1824: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1827:
	/* 0x1827: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1827, 0x119, x86_l_119);
x86_l_182c:
	/* 0x182c: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_182f:
	/* 0x182f: jg     1a71 <generic_sleepable_offload+0x1a71> */
	X86_SIM_X86_JCC(X86_CC_G, 0x182f, 0x1a71, x86_l_1a71);
x86_l_1835:
	/* 0x1835: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1838:
	/* 0x1838: je     18a6 <generic_sleepable_offload+0x18a6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1838, 0x18a6, x86_l_18a6);
x86_l_183a:
	/* 0x183a: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_183d:
	/* 0x183d: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x183d, 0x119, x86_l_119);
x86_l_1843:
	/* 0x1843: mov    WORD PTR [rbp+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1847:
	/* 0x1847: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1847, 0x119, x86_l_119);
x86_l_184c:
	/* 0x184c: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_184f:
	/* 0x184f: jg     1a90 <generic_sleepable_offload+0x1a90> */
	X86_SIM_X86_JCC(X86_CC_G, 0x184f, 0x1a90, x86_l_1a90);
x86_l_1855:
	/* 0x1855: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1858:
	/* 0x1858: jne    109e <generic_sleepable_offload+0x109e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1858, 0x109e, x86_l_109e);
x86_l_185e:
	/* 0x185e: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1863:
	/* 0x1863: jmp    117 <generic_sleepable_offload+0x117> */
	X86_SIM_X86_JMP(0x1863, 0x117, x86_l_117);
x86_l_1868:
	/* 0x1868: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_186d:
	/* 0x186d: jmp    117 <generic_sleepable_offload+0x117> */
	X86_SIM_X86_JMP(0x186d, 0x117, x86_l_117);
x86_l_1872:
	/* 0x1872: mov    rcx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1877:
	/* 0x1877: jmp    117 <generic_sleepable_offload+0x117> */
	X86_SIM_X86_JMP(0x1877, 0x117, x86_l_117);
x86_l_187c:
	/* 0x187c: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1881:
	/* 0x1881: jmp    117 <generic_sleepable_offload+0x117> */
	X86_SIM_X86_JMP(0x1881, 0x117, x86_l_117);
x86_l_1886:
	/* 0x1886: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_188b:
	/* 0x188b: jmp    117 <generic_sleepable_offload+0x117> */
	X86_SIM_X86_JMP(0x188b, 0x117, x86_l_117);
x86_l_1890:
	/* 0x1890: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1895:
	/* 0x1895: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1897:
	/* 0x1897: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1897, 0x119, x86_l_119);
x86_l_189c:
	/* 0x189c: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_18a1:
	/* 0x18a1: jmp    117 <generic_sleepable_offload+0x117> */
	X86_SIM_X86_JMP(0x18a1, 0x117, x86_l_117);
x86_l_18a6:
	/* 0x18a6: mov    BYTE PTR [rbp+0x0],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18a9:
	/* 0x18a9: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x18a9, 0x119, x86_l_119);
x86_l_18ae:
	/* 0x18ae: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18b2:
	/* 0x18b2: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18b4:
	/* 0x18b4: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x18b4, 0x119, x86_l_119);
x86_l_18b9:
	/* 0x18b9: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_18be:
	/* 0x18be: jmp    117 <generic_sleepable_offload+0x117> */
	X86_SIM_X86_JMP(0x18be, 0x117, x86_l_117);
x86_l_18c3:
	/* 0x18c3: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_18c8:
	/* 0x18c8: jmp    117 <generic_sleepable_offload+0x117> */
	X86_SIM_X86_JMP(0x18c8, 0x117, x86_l_117);
x86_l_18cd:
	/* 0x18cd: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_18d2:
	/* 0x18d2: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18d4:
	/* 0x18d4: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x18d4, 0x119, x86_l_119);
x86_l_18d9:
	/* 0x18d9: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_18de:
	/* 0x18de: mov    BYTE PTR [rcx],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18e0:
	/* 0x18e0: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x18e0, 0x119, x86_l_119);
x86_l_18e5:
	/* 0x18e5: mov    BYTE PTR [rbx],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18e7:
	/* 0x18e7: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x18e7, 0x119, x86_l_119);
x86_l_18ec:
	/* 0x18ec: mov    rcx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_18f1:
	/* 0x18f1: mov    BYTE PTR [rcx],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18f3:
	/* 0x18f3: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x18f3, 0x119, x86_l_119);
x86_l_18f8:
	/* 0x18f8: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_18fd:
	/* 0x18fd: mov    BYTE PTR [rcx],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18ff:
	/* 0x18ff: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x18ff, 0x119, x86_l_119);
x86_l_1904:
	/* 0x1904: mov    DWORD PTR [rbx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1906:
	/* 0x1906: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1906, 0x119, x86_l_119);
x86_l_190b:
	/* 0x190b: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1910:
	/* 0x1910: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1912:
	/* 0x1912: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1912, 0x119, x86_l_119);
x86_l_1917:
	/* 0x1917: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_191c:
	/* 0x191c: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_191e:
	/* 0x191e: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x191e, 0x119, x86_l_119);
x86_l_1923:
	/* 0x1923: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1928:
	/* 0x1928: mov    BYTE PTR [rcx],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_192a:
	/* 0x192a: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x192a, 0x119, x86_l_119);
x86_l_192f:
	/* 0x192f: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1933:
	/* 0x1933: mov    BYTE PTR [rcx],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1935:
	/* 0x1935: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1935, 0x119, x86_l_119);
x86_l_193a:
	/* 0x193a: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_193f:
	/* 0x193f: mov    BYTE PTR [rcx],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1941:
	/* 0x1941: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1941, 0x119, x86_l_119);
x86_l_1946:
	/* 0x1946: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_194b:
	/* 0x194b: mov    BYTE PTR [rcx],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_194d:
	/* 0x194d: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x194d, 0x119, x86_l_119);
x86_l_1952:
	/* 0x1952: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1957:
	/* 0x1957: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1959:
	/* 0x1959: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1959, 0x119, x86_l_119);
x86_l_195e:
	/* 0x195e: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1963:
	/* 0x1963: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1965:
	/* 0x1965: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1965, 0x119, x86_l_119);
x86_l_196a:
	/* 0x196a: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_196f:
	/* 0x196f: mov    BYTE PTR [rcx],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1971:
	/* 0x1971: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1971, 0x119, x86_l_119);
x86_l_1976:
	/* 0x1976: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1979:
	/* 0x1979: je     1b3f <generic_sleepable_offload+0x1b3f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1979, 0x1b3f, x86_l_1b3f);
x86_l_197f:
	/* 0x197f: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1982:
	/* 0x1982: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1982, 0x119, x86_l_119);
x86_l_1988:
	/* 0x1988: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_198d:
	/* 0x198d: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1990:
	/* 0x1990: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1990, 0x119, x86_l_119);
x86_l_1995:
	/* 0x1995: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1998:
	/* 0x1998: je     1b4b <generic_sleepable_offload+0x1b4b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1998, 0x1b4b, x86_l_1b4b);
x86_l_199e:
	/* 0x199e: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_19a1:
	/* 0x19a1: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x19a1, 0x119, x86_l_119);
x86_l_19a7:
	/* 0x19a7: mov    rcx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_19ac:
	/* 0x19ac: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19af:
	/* 0x19af: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x19af, 0x119, x86_l_119);
x86_l_19b4:
	/* 0x19b4: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_19b7:
	/* 0x19b7: je     1b57 <generic_sleepable_offload+0x1b57> */
	X86_SIM_X86_JCC(X86_CC_E, 0x19b7, 0x1b57, x86_l_1b57);
x86_l_19bd:
	/* 0x19bd: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_19c0:
	/* 0x19c0: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x19c0, 0x119, x86_l_119);
x86_l_19c6:
	/* 0x19c6: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_19cb:
	/* 0x19cb: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19ce:
	/* 0x19ce: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x19ce, 0x119, x86_l_119);
x86_l_19d3:
	/* 0x19d3: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_19d6:
	/* 0x19d6: je     1b63 <generic_sleepable_offload+0x1b63> */
	X86_SIM_X86_JCC(X86_CC_E, 0x19d6, 0x1b63, x86_l_1b63);
x86_l_19dc:
	/* 0x19dc: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_19df:
	/* 0x19df: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x19df, 0x119, x86_l_119);
x86_l_19e5:
	/* 0x19e5: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_19ea:
	/* 0x19ea: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19ed:
	/* 0x19ed: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x19ed, 0x119, x86_l_119);
x86_l_19f2:
	/* 0x19f2: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_19f5:
	/* 0x19f5: je     1b76 <generic_sleepable_offload+0x1b76> */
	X86_SIM_X86_JCC(X86_CC_E, 0x19f5, 0x1b76, x86_l_1b76);
x86_l_19fb:
	/* 0x19fb: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_19fe:
	/* 0x19fe: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x19fe, 0x119, x86_l_119);
x86_l_1a04:
	/* 0x1a04: mov    QWORD PTR [rbx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a07:
	/* 0x1a07: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1a07, 0x119, x86_l_119);
x86_l_1a0c:
	/* 0x1a0c: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1a0f:
	/* 0x1a0f: je     1a27 <generic_sleepable_offload+0x1a27> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a0f, 0x1a27, x86_l_1a27);
x86_l_1a11:
	/* 0x1a11: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1a14:
	/* 0x1a14: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1a14, 0x119, x86_l_119);
x86_l_1a1a:
	/* 0x1a1a: mov    rcx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1a1f:
	/* 0x1a1f: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a22:
	/* 0x1a22: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1a22, 0x119, x86_l_119);
x86_l_1a27:
	/* 0x1a27: mov    rcx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1a2c:
	/* 0x1a2c: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a2e:
	/* 0x1a2e: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1a2e, 0x119, x86_l_119);
x86_l_1a33:
	/* 0x1a33: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1a36:
	/* 0x1a36: je     1b7d <generic_sleepable_offload+0x1b7d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a36, 0x1b7d, x86_l_1b7d);
x86_l_1a3c:
	/* 0x1a3c: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1a3f:
	/* 0x1a3f: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1a3f, 0x119, x86_l_119);
x86_l_1a45:
	/* 0x1a45: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1a4a:
	/* 0x1a4a: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a4d:
	/* 0x1a4d: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1a4d, 0x119, x86_l_119);
x86_l_1a52:
	/* 0x1a52: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1a55:
	/* 0x1a55: je     1b89 <generic_sleepable_offload+0x1b89> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a55, 0x1b89, x86_l_1b89);
x86_l_1a5b:
	/* 0x1a5b: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1a5e:
	/* 0x1a5e: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1a5e, 0x119, x86_l_119);
x86_l_1a64:
	/* 0x1a64: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1a69:
	/* 0x1a69: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a6c:
	/* 0x1a6c: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1a6c, 0x119, x86_l_119);
x86_l_1a71:
	/* 0x1a71: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1a74:
	/* 0x1a74: je     1a88 <generic_sleepable_offload+0x1a88> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a74, 0x1a88, x86_l_1a88);
x86_l_1a76:
	/* 0x1a76: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1a79:
	/* 0x1a79: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1a79, 0x119, x86_l_119);
x86_l_1a7f:
	/* 0x1a7f: mov    QWORD PTR [rbp+0x0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a83:
	/* 0x1a83: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1a83, 0x119, x86_l_119);
x86_l_1a88:
	/* 0x1a88: mov    DWORD PTR [rbp+0x0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a8b:
	/* 0x1a8b: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1a8b, 0x119, x86_l_119);
x86_l_1a90:
	/* 0x1a90: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1a93:
	/* 0x1a93: je     1aab <generic_sleepable_offload+0x1aab> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a93, 0x1aab, x86_l_1aab);
x86_l_1a95:
	/* 0x1a95: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1a98:
	/* 0x1a98: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1a98, 0x119, x86_l_119);
x86_l_1a9e:
	/* 0x1a9e: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1aa3:
	/* 0x1aa3: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1aa6:
	/* 0x1aa6: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1aa6, 0x119, x86_l_119);
x86_l_1aab:
	/* 0x1aab: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1ab0:
	/* 0x1ab0: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ab2:
	/* 0x1ab2: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1ab2, 0x119, x86_l_119);
x86_l_1ab7:
	/* 0x1ab7: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1aba:
	/* 0x1aba: je     1b95 <generic_sleepable_offload+0x1b95> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1aba, 0x1b95, x86_l_1b95);
x86_l_1ac0:
	/* 0x1ac0: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1ac3:
	/* 0x1ac3: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1ac3, 0x119, x86_l_119);
x86_l_1ac9:
	/* 0x1ac9: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1ace:
	/* 0x1ace: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ad1:
	/* 0x1ad1: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1ad1, 0x119, x86_l_119);
x86_l_1ad6:
	/* 0x1ad6: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1ad9:
	/* 0x1ad9: je     1af1 <generic_sleepable_offload+0x1af1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1ad9, 0x1af1, x86_l_1af1);
x86_l_1adb:
	/* 0x1adb: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1ade:
	/* 0x1ade: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1ade, 0x119, x86_l_119);
x86_l_1ae4:
	/* 0x1ae4: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1ae9:
	/* 0x1ae9: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1aec:
	/* 0x1aec: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1aec, 0x119, x86_l_119);
x86_l_1af1:
	/* 0x1af1: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1af6:
	/* 0x1af6: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1af8:
	/* 0x1af8: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1af8, 0x119, x86_l_119);
x86_l_1afd:
	/* 0x1afd: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1b00:
	/* 0x1b00: je     1b18 <generic_sleepable_offload+0x1b18> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1b00, 0x1b18, x86_l_1b18);
x86_l_1b02:
	/* 0x1b02: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1b05:
	/* 0x1b05: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1b05, 0x119, x86_l_119);
x86_l_1b0b:
	/* 0x1b0b: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b10:
	/* 0x1b10: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b13:
	/* 0x1b13: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1b13, 0x119, x86_l_119);
x86_l_1b18:
	/* 0x1b18: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b1d:
	/* 0x1b1d: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b1f:
	/* 0x1b1f: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1b1f, 0x119, x86_l_119);
x86_l_1b24:
	/* 0x1b24: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1b27:
	/* 0x1b27: je     1ba1 <generic_sleepable_offload+0x1ba1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1b27, 0x1ba1, x86_l_1ba1);
x86_l_1b29:
	/* 0x1b29: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1b2c:
	/* 0x1b2c: jne    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1b2c, 0x119, x86_l_119);
x86_l_1b32:
	/* 0x1b32: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b37:
	/* 0x1b37: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b3a:
	/* 0x1b3a: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1b3a, 0x119, x86_l_119);
x86_l_1b3f:
	/* 0x1b3f: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1b44:
	/* 0x1b44: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b46:
	/* 0x1b46: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1b46, 0x119, x86_l_119);
x86_l_1b4b:
	/* 0x1b4b: mov    rcx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1b50:
	/* 0x1b50: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b52:
	/* 0x1b52: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1b52, 0x119, x86_l_119);
x86_l_1b57:
	/* 0x1b57: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1b5c:
	/* 0x1b5c: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b5e:
	/* 0x1b5e: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1b5e, 0x119, x86_l_119);
x86_l_1b63:
	/* 0x1b63: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1b68:
	/* 0x1b68: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b6a:
	/* 0x1b6a: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1b6a, 0x119, x86_l_119);
x86_l_1b6f:
	/* 0x1b6f: mov    BYTE PTR [rbx],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b71:
	/* 0x1b71: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1b71, 0x119, x86_l_119);
x86_l_1b76:
	/* 0x1b76: mov    DWORD PTR [rbx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b78:
	/* 0x1b78: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1b78, 0x119, x86_l_119);
x86_l_1b7d:
	/* 0x1b7d: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1b82:
	/* 0x1b82: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b84:
	/* 0x1b84: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1b84, 0x119, x86_l_119);
x86_l_1b89:
	/* 0x1b89: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1b8e:
	/* 0x1b8e: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b90:
	/* 0x1b90: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1b90, 0x119, x86_l_119);
x86_l_1b95:
	/* 0x1b95: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1b9a:
	/* 0x1b9a: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b9c:
	/* 0x1b9c: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1b9c, 0x119, x86_l_119);
x86_l_1ba1:
	/* 0x1ba1: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1ba6:
	/* 0x1ba6: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ba8:
	/* 0x1ba8: jmp    119 <generic_sleepable_offload+0x119> */
	X86_SIM_X86_JMP(0x1ba8, 0x119, x86_l_119);
x86_l_1bad:
	/* 0x1bad: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1baf:
	/* 0x1baf: add    rsp,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 136ULL);
x86_l_1bb6:
	/* 0x1bb6: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_1bb8:
	/* 0x1bb8: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_1bb9:
	/* 0x1bb9: jmp    1bbe <generic_sleepable_offload+0x1bbe> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_1bbe:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
