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
	/* 0x1c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_21:
	/* 0x21: mov    rdi,QWORD PTR [rip+0x2f47] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sleepable_offload)));
x86_l_28:
	/* 0x28: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_30:
	/* 0x30: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_32:
	/* 0x32: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_35:
	/* 0x35: je     1c1e <generic_sleepable_offload+0x1c1e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x35, 0x1c1e, x86_l_1c1e);
x86_l_3b:
	/* 0x3b: mov    r14,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RAX, X86_WIDTH_64);
x86_l_3e:
	/* 0x3e: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_43:
	/* 0x43: mov    rdi,QWORD PTR [rip+0x2f47] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&sleepable_offload)));
x86_l_4a:
	/* 0x4a: lea    rsi,[rsp+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_52:
	/* 0x52: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_54:
	/* 0x54: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_59:
	/* 0x59: mov    rdi,QWORD PTR [rip+0x2f47] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&regs_map)));
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
	/* 0x68: je     1c1e <generic_sleepable_offload+0x1c1e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x68, 0x1c1e, x86_l_1c1e);
x86_l_6e:
	/* 0x6e: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_71:
	/* 0x71: lea    rax,[rbx+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_78:
	/* 0x78: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7d:
	/* 0x7d: lea    rax,[rbx+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_84:
	/* 0x84: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_89:
	/* 0x89: lea    rbp,[rbx+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_8d:
	/* 0x8d: lea    rax,[rbx+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_91:
	/* 0x91: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_96:
	/* 0x96: lea    rax,[rbx+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_9a:
	/* 0x9a: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_9f:
	/* 0x9f: lea    rax,[rbx+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_a3:
	/* 0xa3: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_a8:
	/* 0xa8: lea    rax,[rbx+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_ac:
	/* 0xac: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_b1:
	/* 0xb1: lea    rax,[rbx+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_b5:
	/* 0xb5: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ba:
	/* 0xba: lea    rax,[rbx+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_be:
	/* 0xbe: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_c3:
	/* 0xc3: lea    rax,[rbx+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_c7:
	/* 0xc7: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_cc:
	/* 0xcc: lea    rax,[rbx+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d0:
	/* 0xd0: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_d5:
	/* 0xd5: lea    rax,[rbx+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_d9:
	/* 0xd9: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_de:
	/* 0xde: lea    rax,[rbx+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e2:
	/* 0xe2: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_e7:
	/* 0xe7: lea    rax,[rbx+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_eb:
	/* 0xeb: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_f0:
	/* 0xf0: mov    r14,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R13, X86_WIDTH_64);
x86_l_f3:
	/* 0xf3: add    r14,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_f7:
	/* 0xf7: lea    r12,[rbx+0x10] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_fb:
	/* 0xfb: lea    rax,[rbx+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ff:
	/* 0xff: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_104:
	/* 0x104: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_107:
	/* 0x107: jmp    121 <generic_sleepable_offload+0x121> */
	X86_SIM_X86_JMP(0x107, 0x121, x86_l_121);
x86_l_109:
	/* 0x109: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_10e:
	/* 0x10e: mov    BYTE PTR [rcx],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_110:
	/* 0x110: inc    r15 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_64, X86_ALU_INC, 1);
x86_l_113:
	/* 0x113: add    r14,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R14, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_117:
	/* 0x117: cmp    r15,0x12 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_64, 18ULL);
x86_l_11b:
	/* 0x11b: je     1c1e <generic_sleepable_offload+0x1c1e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11b, 0x1c1e, x86_l_1c1e);
x86_l_121:
	/* 0x121: mov    eax,DWORD PTR [r13+0x120] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 288ULL);
x86_l_128:
	/* 0x128: cmp    r15,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_CMP_REG, X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_12b:
	/* 0x12b: jae    1c1e <generic_sleepable_offload+0x1c1e> */
	X86_SIM_X86_JCC(X86_CC_AE, 0x12b, 0x1c1e, x86_l_1c1e);
x86_l_131:
	/* 0x131: movzx  eax,BYTE PTR [r14-0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551608ULL);
x86_l_136:
	/* 0x136: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_139:
	/* 0x139: jg     1a6 <generic_sleepable_offload+0x1a6> */
	X86_SIM_X86_JCC(X86_CC_G, 0x139, 0x1a6, x86_l_1a6);
x86_l_13b:
	/* 0x13b: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13e:
	/* 0x13e: je     215 <generic_sleepable_offload+0x215> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13e, 0x215, x86_l_215);
x86_l_144:
	/* 0x144: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_147:
	/* 0x147: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x147, 0x110, x86_l_110);
x86_l_149:
	/* 0x149: movzx  eax,WORD PTR [r14-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551610ULL);
x86_l_14e:
	/* 0x14e: movzx  ecx,BYTE PTR [r14-0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551614ULL);
x86_l_153:
	/* 0x153: rorx   edx,eax,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RAX, X86_WIDTH_32, 0, 3ULL);
x86_l_159:
	/* 0x159: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_15c:
	/* 0x15c: jle    2db <generic_sleepable_offload+0x2db> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x15c, 0x2db, x86_l_2db);
x86_l_162:
	/* 0x162: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_165:
	/* 0x165: jle    3b7 <generic_sleepable_offload+0x3b7> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x165, 0x3b7, x86_l_3b7);
x86_l_16b:
	/* 0x16b: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_16e:
	/* 0x16e: jle    730 <generic_sleepable_offload+0x730> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x16e, 0x730, x86_l_730);
x86_l_174:
	/* 0x174: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_177:
	/* 0x177: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_17a:
	/* 0x17a: je     749 <generic_sleepable_offload+0x749> */
	X86_SIM_X86_JCC(X86_CC_E, 0x17a, 0x749, x86_l_749);
x86_l_180:
	/* 0x180: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_185:
	/* 0x185: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_188:
	/* 0x188: je     749 <generic_sleepable_offload+0x749> */
	X86_SIM_X86_JCC(X86_CC_E, 0x188, 0x749, x86_l_749);
x86_l_18e:
	/* 0x18e: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_193:
	/* 0x193: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_196:
	/* 0x196: jne    75c <generic_sleepable_offload+0x75c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x196, 0x75c, x86_l_75c);
x86_l_19c:
	/* 0x19c: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1a1:
	/* 0x1a1: jmp    749 <generic_sleepable_offload+0x749> */
	X86_SIM_X86_JMP(0x1a1, 0x749, x86_l_749);
x86_l_1a6:
	/* 0x1a6: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1a9:
	/* 0x1a9: je     27e <generic_sleepable_offload+0x27e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a9, 0x27e, x86_l_27e);
x86_l_1af:
	/* 0x1af: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b2:
	/* 0x1b2: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1b2, 0x110, x86_l_110);
x86_l_1b8:
	/* 0x1b8: movzx  ecx,WORD PTR [r14-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551610ULL);
x86_l_1bd:
	/* 0x1bd: movzx  eax,BYTE PTR [r14-0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551614ULL);
x86_l_1c2:
	/* 0x1c2: rorx   ecx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_1c8:
	/* 0x1c8: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_1cb:
	/* 0x1cb: jle    310 <generic_sleepable_offload+0x310> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x1cb, 0x310, x86_l_310);
x86_l_1d1:
	/* 0x1d1: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_1d4:
	/* 0x1d4: jle    3e6 <generic_sleepable_offload+0x3e6> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x1d4, 0x3e6, x86_l_3e6);
x86_l_1da:
	/* 0x1da: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_1dd:
	/* 0x1dd: jle    92a <generic_sleepable_offload+0x92a> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x1dd, 0x92a, x86_l_92a);
x86_l_1e3:
	/* 0x1e3: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1e6:
	/* 0x1e6: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_1e9:
	/* 0x1e9: je     943 <generic_sleepable_offload+0x943> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1e9, 0x943, x86_l_943);
x86_l_1ef:
	/* 0x1ef: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1f4:
	/* 0x1f4: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_1f7:
	/* 0x1f7: je     943 <generic_sleepable_offload+0x943> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1f7, 0x943, x86_l_943);
x86_l_1fd:
	/* 0x1fd: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_202:
	/* 0x202: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_205:
	/* 0x205: jne    956 <generic_sleepable_offload+0x956> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x205, 0x956, x86_l_956);
x86_l_20b:
	/* 0x20b: mov    rdx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_210:
	/* 0x210: jmp    943 <generic_sleepable_offload+0x943> */
	X86_SIM_X86_JMP(0x210, 0x943, x86_l_943);
x86_l_215:
	/* 0x215: movzx  edx,WORD PTR [r14-0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551612ULL);
x86_l_21a:
	/* 0x21a: movzx  ecx,BYTE PTR [r14-0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551615ULL);
x86_l_21f:
	/* 0x21f: mov    rax,QWORD PTR [r14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_222:
	/* 0x222: rorx   edx,edx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RDX, X86_WIDTH_32, 0, 3ULL);
x86_l_228:
	/* 0x228: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_22b:
	/* 0x22b: jle    345 <generic_sleepable_offload+0x345> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x22b, 0x345, x86_l_345);
x86_l_231:
	/* 0x231: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_234:
	/* 0x234: jle    415 <generic_sleepable_offload+0x415> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x234, 0x415, x86_l_415);
x86_l_23a:
	/* 0x23a: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_23d:
	/* 0x23d: jle    a58 <generic_sleepable_offload+0xa58> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x23d, 0xa58, x86_l_a58);
x86_l_243:
	/* 0x243: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_246:
	/* 0x246: je     1009 <generic_sleepable_offload+0x1009> */
	X86_SIM_X86_JCC(X86_CC_E, 0x246, 0x1009, x86_l_1009);
x86_l_24c:
	/* 0x24c: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_24f:
	/* 0x24f: je     e73 <generic_sleepable_offload+0xe73> */
	X86_SIM_X86_JCC(X86_CC_E, 0x24f, 0xe73, x86_l_e73);
x86_l_255:
	/* 0x255: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_258:
	/* 0x258: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x258, 0x110, x86_l_110);
x86_l_25e:
	/* 0x25e: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_261:
	/* 0x261: jg     1537 <generic_sleepable_offload+0x1537> */
	X86_SIM_X86_JCC(X86_CC_G, 0x261, 0x1537, x86_l_1537);
x86_l_267:
	/* 0x267: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_26a:
	/* 0x26a: je     9d5 <generic_sleepable_offload+0x9d5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x26a, 0x9d5, x86_l_9d5);
x86_l_270:
	/* 0x270: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_273:
	/* 0x273: je     7be <generic_sleepable_offload+0x7be> */
	X86_SIM_X86_JCC(X86_CC_E, 0x273, 0x7be, x86_l_7be);
x86_l_279:
	/* 0x279: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x279, 0x110, x86_l_110);
x86_l_27e:
	/* 0x27e: movzx  eax,WORD PTR [r14-0x6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551610ULL);
x86_l_283:
	/* 0x283: movzx  ecx,BYTE PTR [r14-0x2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551614ULL);
x86_l_288:
	/* 0x288: rorx   edx,eax,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RAX, X86_WIDTH_32, 0, 3ULL);
x86_l_28e:
	/* 0x28e: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_291:
	/* 0x291: jle    382 <generic_sleepable_offload+0x382> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x291, 0x382, x86_l_382);
x86_l_297:
	/* 0x297: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_29a:
	/* 0x29a: jle    458 <generic_sleepable_offload+0x458> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x29a, 0x458, x86_l_458);
x86_l_2a0:
	/* 0x2a0: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_2a3:
	/* 0x2a3: jle    a92 <generic_sleepable_offload+0xa92> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x2a3, 0xa92, x86_l_a92);
x86_l_2a9:
	/* 0x2a9: mov    rsi,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBP, X86_WIDTH_64);
x86_l_2ac:
	/* 0x2ac: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_2af:
	/* 0x2af: je     aab <generic_sleepable_offload+0xaab> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2af, 0xaab, x86_l_aab);
x86_l_2b5:
	/* 0x2b5: mov    rsi,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_2ba:
	/* 0x2ba: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_2bd:
	/* 0x2bd: je     aab <generic_sleepable_offload+0xaab> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2bd, 0xaab, x86_l_aab);
x86_l_2c3:
	/* 0x2c3: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_2c8:
	/* 0x2c8: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_2cb:
	/* 0x2cb: jne    abe <generic_sleepable_offload+0xabe> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2cb, 0xabe, x86_l_abe);
x86_l_2d1:
	/* 0x2d1: mov    rsi,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_2d6:
	/* 0x2d6: jmp    aab <generic_sleepable_offload+0xaab> */
	X86_SIM_X86_JMP(0x2d6, 0xaab, x86_l_aab);
x86_l_2db:
	/* 0x2db: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_2de:
	/* 0x2de: jg     487 <generic_sleepable_offload+0x487> */
	X86_SIM_X86_JCC(X86_CC_G, 0x2de, 0x487, x86_l_487);
x86_l_2e4:
	/* 0x2e4: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_2e7:
	/* 0x2e7: jg     5ea <generic_sleepable_offload+0x5ea> */
	X86_SIM_X86_JCC(X86_CC_G, 0x2e7, 0x5ea, x86_l_5ea);
x86_l_2ed:
	/* 0x2ed: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_2f0:
	/* 0x2f0: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_2f2:
	/* 0x2f2: je     749 <generic_sleepable_offload+0x749> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2f2, 0x749, x86_l_749);
x86_l_2f8:
	/* 0x2f8: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2fd:
	/* 0x2fd: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_302:
	/* 0x302: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_305:
	/* 0x305: je     749 <generic_sleepable_offload+0x749> */
	X86_SIM_X86_JCC(X86_CC_E, 0x305, 0x749, x86_l_749);
x86_l_30b:
	/* 0x30b: jmp    75c <generic_sleepable_offload+0x75c> */
	X86_SIM_X86_JMP(0x30b, 0x75c, x86_l_75c);
x86_l_310:
	/* 0x310: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_313:
	/* 0x313: jg     4b6 <generic_sleepable_offload+0x4b6> */
	X86_SIM_X86_JCC(X86_CC_G, 0x313, 0x4b6, x86_l_4b6);
x86_l_319:
	/* 0x319: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_31c:
	/* 0x31c: jg     60e <generic_sleepable_offload+0x60e> */
	X86_SIM_X86_JCC(X86_CC_G, 0x31c, 0x60e, x86_l_60e);
x86_l_322:
	/* 0x322: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_325:
	/* 0x325: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_327:
	/* 0x327: je     943 <generic_sleepable_offload+0x943> */
	X86_SIM_X86_JCC(X86_CC_E, 0x327, 0x943, x86_l_943);
x86_l_32d:
	/* 0x32d: mov    rdx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_332:
	/* 0x332: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_337:
	/* 0x337: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_33a:
	/* 0x33a: je     943 <generic_sleepable_offload+0x943> */
	X86_SIM_X86_JCC(X86_CC_E, 0x33a, 0x943, x86_l_943);
x86_l_340:
	/* 0x340: jmp    956 <generic_sleepable_offload+0x956> */
	X86_SIM_X86_JMP(0x340, 0x956, x86_l_956);
x86_l_345:
	/* 0x345: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_348:
	/* 0x348: jg     4e5 <generic_sleepable_offload+0x4e5> */
	X86_SIM_X86_JCC(X86_CC_G, 0x348, 0x4e5, x86_l_4e5);
x86_l_34e:
	/* 0x34e: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_351:
	/* 0x351: jg     67e <generic_sleepable_offload+0x67e> */
	X86_SIM_X86_JCC(X86_CC_G, 0x351, 0x67e, x86_l_67e);
x86_l_357:
	/* 0x357: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_359:
	/* 0x359: jne    7e1 <generic_sleepable_offload+0x7e1> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x359, 0x7e1, x86_l_7e1);
x86_l_35f:
	/* 0x35f: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_362:
	/* 0x362: jg     13ee <generic_sleepable_offload+0x13ee> */
	X86_SIM_X86_JCC(X86_CC_G, 0x362, 0x13ee, x86_l_13ee);
x86_l_368:
	/* 0x368: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_36b:
	/* 0x36b: je     1955 <generic_sleepable_offload+0x1955> */
	X86_SIM_X86_JCC(X86_CC_E, 0x36b, 0x1955, x86_l_1955);
x86_l_371:
	/* 0x371: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_374:
	/* 0x374: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x374, 0x110, x86_l_110);
x86_l_37a:
	/* 0x37a: mov    WORD PTR [rbx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_37d:
	/* 0x37d: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x37d, 0x110, x86_l_110);
x86_l_382:
	/* 0x382: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_385:
	/* 0x385: jg     517 <generic_sleepable_offload+0x517> */
	X86_SIM_X86_JCC(X86_CC_G, 0x385, 0x517, x86_l_517);
x86_l_38b:
	/* 0x38b: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_38e:
	/* 0x38e: jg     6ac <generic_sleepable_offload+0x6ac> */
	X86_SIM_X86_JCC(X86_CC_G, 0x38e, 0x6ac, x86_l_6ac);
x86_l_394:
	/* 0x394: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_397:
	/* 0x397: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_399:
	/* 0x399: je     aab <generic_sleepable_offload+0xaab> */
	X86_SIM_X86_JCC(X86_CC_E, 0x399, 0xaab, x86_l_aab);
x86_l_39f:
	/* 0x39f: mov    rsi,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_3a4:
	/* 0x3a4: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_3a9:
	/* 0x3a9: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_3ac:
	/* 0x3ac: je     aab <generic_sleepable_offload+0xaab> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3ac, 0xaab, x86_l_aab);
x86_l_3b2:
	/* 0x3b2: jmp    abe <generic_sleepable_offload+0xabe> */
	X86_SIM_X86_JMP(0x3b2, 0xabe, x86_l_abe);
x86_l_3b7:
	/* 0x3b7: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_3ba:
	/* 0x3ba: jg     546 <generic_sleepable_offload+0x546> */
	X86_SIM_X86_JCC(X86_CC_G, 0x3ba, 0x546, x86_l_546);
x86_l_3c0:
	/* 0x3c0: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3c5:
	/* 0x3c5: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_3c8:
	/* 0x3c8: je     749 <generic_sleepable_offload+0x749> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3c8, 0x749, x86_l_749);
x86_l_3ce:
	/* 0x3ce: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3d3:
	/* 0x3d3: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_3d8:
	/* 0x3d8: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_3db:
	/* 0x3db: je     749 <generic_sleepable_offload+0x749> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3db, 0x749, x86_l_749);
x86_l_3e1:
	/* 0x3e1: jmp    75c <generic_sleepable_offload+0x75c> */
	X86_SIM_X86_JMP(0x3e1, 0x75c, x86_l_75c);
x86_l_3e6:
	/* 0x3e6: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_3e9:
	/* 0x3e9: jg     56c <generic_sleepable_offload+0x56c> */
	X86_SIM_X86_JCC(X86_CC_G, 0x3e9, 0x56c, x86_l_56c);
x86_l_3ef:
	/* 0x3ef: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3f4:
	/* 0x3f4: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_3f7:
	/* 0x3f7: je     943 <generic_sleepable_offload+0x943> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3f7, 0x943, x86_l_943);
x86_l_3fd:
	/* 0x3fd: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_402:
	/* 0x402: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_407:
	/* 0x407: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_40a:
	/* 0x40a: je     943 <generic_sleepable_offload+0x943> */
	X86_SIM_X86_JCC(X86_CC_E, 0x40a, 0x943, x86_l_943);
x86_l_410:
	/* 0x410: jmp    956 <generic_sleepable_offload+0x956> */
	X86_SIM_X86_JMP(0x410, 0x956, x86_l_956);
x86_l_415:
	/* 0x415: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_418:
	/* 0x418: jg     592 <generic_sleepable_offload+0x592> */
	X86_SIM_X86_JCC(X86_CC_G, 0x418, 0x592, x86_l_592);
x86_l_41e:
	/* 0x41e: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_421:
	/* 0x421: je     dc3 <generic_sleepable_offload+0xdc3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x421, 0xdc3, x86_l_dc3);
x86_l_427:
	/* 0x427: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_42a:
	/* 0x42a: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x42a, 0x110, x86_l_110);
x86_l_430:
	/* 0x430: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_433:
	/* 0x433: jg     12ff <generic_sleepable_offload+0x12ff> */
	X86_SIM_X86_JCC(X86_CC_G, 0x433, 0x12ff, x86_l_12ff);
x86_l_439:
	/* 0x439: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_43c:
	/* 0x43c: je     18d3 <generic_sleepable_offload+0x18d3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x43c, 0x18d3, x86_l_18d3);
x86_l_442:
	/* 0x442: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_445:
	/* 0x445: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x445, 0x110, x86_l_110);
x86_l_44b:
	/* 0x44b: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_450:
	/* 0x450: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_453:
	/* 0x453: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x453, 0x110, x86_l_110);
x86_l_458:
	/* 0x458: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_45b:
	/* 0x45b: jg     5c4 <generic_sleepable_offload+0x5c4> */
	X86_SIM_X86_JCC(X86_CC_G, 0x45b, 0x5c4, x86_l_5c4);
x86_l_461:
	/* 0x461: mov    rsi,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_466:
	/* 0x466: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_469:
	/* 0x469: je     aab <generic_sleepable_offload+0xaab> */
	X86_SIM_X86_JCC(X86_CC_E, 0x469, 0xaab, x86_l_aab);
x86_l_46f:
	/* 0x46f: mov    rsi,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_474:
	/* 0x474: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_479:
	/* 0x479: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_47c:
	/* 0x47c: je     aab <generic_sleepable_offload+0xaab> */
	X86_SIM_X86_JCC(X86_CC_E, 0x47c, 0xaab, x86_l_aab);
x86_l_482:
	/* 0x482: jmp    abe <generic_sleepable_offload+0xabe> */
	X86_SIM_X86_JMP(0x482, 0xabe, x86_l_abe);
x86_l_487:
	/* 0x487: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_48a:
	/* 0x48a: jg     632 <generic_sleepable_offload+0x632> */
	X86_SIM_X86_JCC(X86_CC_G, 0x48a, 0x632, x86_l_632);
x86_l_490:
	/* 0x490: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_495:
	/* 0x495: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_498:
	/* 0x498: je     749 <generic_sleepable_offload+0x749> */
	X86_SIM_X86_JCC(X86_CC_E, 0x498, 0x749, x86_l_749);
x86_l_49e:
	/* 0x49e: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4a3:
	/* 0x4a3: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_4a8:
	/* 0x4a8: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_4ab:
	/* 0x4ab: je     749 <generic_sleepable_offload+0x749> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4ab, 0x749, x86_l_749);
x86_l_4b1:
	/* 0x4b1: jmp    75c <generic_sleepable_offload+0x75c> */
	X86_SIM_X86_JMP(0x4b1, 0x75c, x86_l_75c);
x86_l_4b6:
	/* 0x4b6: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_4b9:
	/* 0x4b9: jg     658 <generic_sleepable_offload+0x658> */
	X86_SIM_X86_JCC(X86_CC_G, 0x4b9, 0x658, x86_l_658);
x86_l_4bf:
	/* 0x4bf: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_4c4:
	/* 0x4c4: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_4c7:
	/* 0x4c7: je     943 <generic_sleepable_offload+0x943> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4c7, 0x943, x86_l_943);
x86_l_4cd:
	/* 0x4cd: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_4d2:
	/* 0x4d2: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_4d7:
	/* 0x4d7: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_4da:
	/* 0x4da: je     943 <generic_sleepable_offload+0x943> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4da, 0x943, x86_l_943);
x86_l_4e0:
	/* 0x4e0: jmp    956 <generic_sleepable_offload+0x956> */
	X86_SIM_X86_JMP(0x4e0, 0x956, x86_l_956);
x86_l_4e5:
	/* 0x4e5: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_4e8:
	/* 0x4e8: jg     6d0 <generic_sleepable_offload+0x6d0> */
	X86_SIM_X86_JCC(X86_CC_G, 0x4e8, 0x6d0, x86_l_6d0);
x86_l_4ee:
	/* 0x4ee: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_4f1:
	/* 0x4f1: je     cd5 <generic_sleepable_offload+0xcd5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4f1, 0xcd5, x86_l_cd5);
x86_l_4f7:
	/* 0x4f7: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_4fa:
	/* 0x4fa: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4fa, 0x110, x86_l_110);
x86_l_500:
	/* 0x500: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_503:
	/* 0x503: jg     10d8 <generic_sleepable_offload+0x10d8> */
	X86_SIM_X86_JCC(X86_CC_G, 0x503, 0x10d8, x86_l_10d8);
x86_l_509:
	/* 0x509: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_50c:
	/* 0x50c: jne    876 <generic_sleepable_offload+0x876> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x50c, 0x876, x86_l_876);
x86_l_512:
	/* 0x512: jmp    1911 <generic_sleepable_offload+0x1911> */
	X86_SIM_X86_JMP(0x512, 0x1911, x86_l_1911);
x86_l_517:
	/* 0x517: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_51a:
	/* 0x51a: jg     70a <generic_sleepable_offload+0x70a> */
	X86_SIM_X86_JCC(X86_CC_G, 0x51a, 0x70a, x86_l_70a);
x86_l_520:
	/* 0x520: mov    rsi,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_525:
	/* 0x525: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_528:
	/* 0x528: je     aab <generic_sleepable_offload+0xaab> */
	X86_SIM_X86_JCC(X86_CC_E, 0x528, 0xaab, x86_l_aab);
x86_l_52e:
	/* 0x52e: mov    rsi,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_533:
	/* 0x533: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_538:
	/* 0x538: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_53b:
	/* 0x53b: je     aab <generic_sleepable_offload+0xaab> */
	X86_SIM_X86_JCC(X86_CC_E, 0x53b, 0xaab, x86_l_aab);
x86_l_541:
	/* 0x541: jmp    abe <generic_sleepable_offload+0xabe> */
	X86_SIM_X86_JMP(0x541, 0xabe, x86_l_abe);
x86_l_546:
	/* 0x546: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_54b:
	/* 0x54b: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_54e:
	/* 0x54e: je     749 <generic_sleepable_offload+0x749> */
	X86_SIM_X86_JCC(X86_CC_E, 0x54e, 0x749, x86_l_749);
x86_l_554:
	/* 0x554: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_559:
	/* 0x559: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_55e:
	/* 0x55e: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_561:
	/* 0x561: je     749 <generic_sleepable_offload+0x749> */
	X86_SIM_X86_JCC(X86_CC_E, 0x561, 0x749, x86_l_749);
x86_l_567:
	/* 0x567: jmp    75c <generic_sleepable_offload+0x75c> */
	X86_SIM_X86_JMP(0x567, 0x75c, x86_l_75c);
x86_l_56c:
	/* 0x56c: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_571:
	/* 0x571: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_574:
	/* 0x574: je     943 <generic_sleepable_offload+0x943> */
	X86_SIM_X86_JCC(X86_CC_E, 0x574, 0x943, x86_l_943);
x86_l_57a:
	/* 0x57a: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_57f:
	/* 0x57f: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_584:
	/* 0x584: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_587:
	/* 0x587: je     943 <generic_sleepable_offload+0x943> */
	X86_SIM_X86_JCC(X86_CC_E, 0x587, 0x943, x86_l_943);
x86_l_58d:
	/* 0x58d: jmp    956 <generic_sleepable_offload+0x956> */
	X86_SIM_X86_JMP(0x58d, 0x956, x86_l_956);
x86_l_592:
	/* 0x592: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_595:
	/* 0x595: je     deb <generic_sleepable_offload+0xdeb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x595, 0xdeb, x86_l_deb);
x86_l_59b:
	/* 0x59b: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_59e:
	/* 0x59e: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x59e, 0x110, x86_l_110);
x86_l_5a4:
	/* 0x5a4: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_5a7:
	/* 0x5a7: jg     131e <generic_sleepable_offload+0x131e> */
	X86_SIM_X86_JCC(X86_CC_G, 0x5a7, 0x131e, x86_l_131e);
x86_l_5ad:
	/* 0x5ad: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_5b0:
	/* 0x5b0: je     18dd <generic_sleepable_offload+0x18dd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5b0, 0x18dd, x86_l_18dd);
x86_l_5b6:
	/* 0x5b6: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_5b9:
	/* 0x5b9: je     c22 <generic_sleepable_offload+0xc22> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5b9, 0xc22, x86_l_c22);
x86_l_5bf:
	/* 0x5bf: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x5bf, 0x110, x86_l_110);
x86_l_5c4:
	/* 0x5c4: mov    rsi,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_5c9:
	/* 0x5c9: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_5cc:
	/* 0x5cc: je     aab <generic_sleepable_offload+0xaab> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5cc, 0xaab, x86_l_aab);
x86_l_5d2:
	/* 0x5d2: mov    rsi,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_5d7:
	/* 0x5d7: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_5dc:
	/* 0x5dc: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_5df:
	/* 0x5df: je     aab <generic_sleepable_offload+0xaab> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5df, 0xaab, x86_l_aab);
x86_l_5e5:
	/* 0x5e5: jmp    abe <generic_sleepable_offload+0xabe> */
	X86_SIM_X86_JMP(0x5e5, 0xabe, x86_l_abe);
x86_l_5ea:
	/* 0x5ea: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_5ed:
	/* 0x5ed: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_5f0:
	/* 0x5f0: je     749 <generic_sleepable_offload+0x749> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5f0, 0x749, x86_l_749);
x86_l_5f6:
	/* 0x5f6: mov    rsi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5fb:
	/* 0x5fb: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_600:
	/* 0x600: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_603:
	/* 0x603: je     749 <generic_sleepable_offload+0x749> */
	X86_SIM_X86_JCC(X86_CC_E, 0x603, 0x749, x86_l_749);
x86_l_609:
	/* 0x609: jmp    75c <generic_sleepable_offload+0x75c> */
	X86_SIM_X86_JMP(0x609, 0x75c, x86_l_75c);
x86_l_60e:
	/* 0x60e: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_611:
	/* 0x611: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_614:
	/* 0x614: je     943 <generic_sleepable_offload+0x943> */
	X86_SIM_X86_JCC(X86_CC_E, 0x614, 0x943, x86_l_943);
x86_l_61a:
	/* 0x61a: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_61f:
	/* 0x61f: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_624:
	/* 0x624: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_627:
	/* 0x627: je     943 <generic_sleepable_offload+0x943> */
	X86_SIM_X86_JCC(X86_CC_E, 0x627, 0x943, x86_l_943);
x86_l_62d:
	/* 0x62d: jmp    956 <generic_sleepable_offload+0x956> */
	X86_SIM_X86_JMP(0x62d, 0x956, x86_l_956);
x86_l_632:
	/* 0x632: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_637:
	/* 0x637: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_63a:
	/* 0x63a: je     749 <generic_sleepable_offload+0x749> */
	X86_SIM_X86_JCC(X86_CC_E, 0x63a, 0x749, x86_l_749);
x86_l_640:
	/* 0x640: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_645:
	/* 0x645: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_64a:
	/* 0x64a: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_64d:
	/* 0x64d: je     749 <generic_sleepable_offload+0x749> */
	X86_SIM_X86_JCC(X86_CC_E, 0x64d, 0x749, x86_l_749);
x86_l_653:
	/* 0x653: jmp    75c <generic_sleepable_offload+0x75c> */
	X86_SIM_X86_JMP(0x653, 0x75c, x86_l_75c);
x86_l_658:
	/* 0x658: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_65d:
	/* 0x65d: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_660:
	/* 0x660: je     943 <generic_sleepable_offload+0x943> */
	X86_SIM_X86_JCC(X86_CC_E, 0x660, 0x943, x86_l_943);
x86_l_666:
	/* 0x666: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_66b:
	/* 0x66b: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_670:
	/* 0x670: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_673:
	/* 0x673: je     943 <generic_sleepable_offload+0x943> */
	X86_SIM_X86_JCC(X86_CC_E, 0x673, 0x943, x86_l_943);
x86_l_679:
	/* 0x679: jmp    956 <generic_sleepable_offload+0x956> */
	X86_SIM_X86_JMP(0x679, 0x956, x86_l_956);
x86_l_67e:
	/* 0x67e: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_681:
	/* 0x681: jne    8c7 <generic_sleepable_offload+0x8c7> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x681, 0x8c7, x86_l_8c7);
x86_l_687:
	/* 0x687: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_68a:
	/* 0x68a: jg     1408 <generic_sleepable_offload+0x1408> */
	X86_SIM_X86_JCC(X86_CC_G, 0x68a, 0x1408, x86_l_1408);
x86_l_690:
	/* 0x690: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_693:
	/* 0x693: je     195c <generic_sleepable_offload+0x195c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x693, 0x195c, x86_l_195c);
x86_l_699:
	/* 0x699: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_69c:
	/* 0x69c: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x69c, 0x110, x86_l_110);
x86_l_6a2:
	/* 0x6a2: mov    WORD PTR [r12],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6a7:
	/* 0x6a7: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x6a7, 0x110, x86_l_110);
x86_l_6ac:
	/* 0x6ac: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_6af:
	/* 0x6af: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_6b2:
	/* 0x6b2: je     aab <generic_sleepable_offload+0xaab> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6b2, 0xaab, x86_l_aab);
x86_l_6b8:
	/* 0x6b8: mov    rsi,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6bd:
	/* 0x6bd: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_6c2:
	/* 0x6c2: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_6c5:
	/* 0x6c5: je     aab <generic_sleepable_offload+0xaab> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6c5, 0xaab, x86_l_aab);
x86_l_6cb:
	/* 0x6cb: jmp    abe <generic_sleepable_offload+0xabe> */
	X86_SIM_X86_JMP(0x6cb, 0xabe, x86_l_abe);
x86_l_6d0:
	/* 0x6d0: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_6d3:
	/* 0x6d3: je     f51 <generic_sleepable_offload+0xf51> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6d3, 0xf51, x86_l_f51);
x86_l_6d9:
	/* 0x6d9: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_6dc:
	/* 0x6dc: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x6dc, 0x110, x86_l_110);
x86_l_6e2:
	/* 0x6e2: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_6e5:
	/* 0x6e5: jg     156d <generic_sleepable_offload+0x156d> */
	X86_SIM_X86_JCC(X86_CC_G, 0x6e5, 0x156d, x86_l_156d);
x86_l_6eb:
	/* 0x6eb: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_6ee:
	/* 0x6ee: je     191b <generic_sleepable_offload+0x191b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6ee, 0x191b, x86_l_191b);
x86_l_6f4:
	/* 0x6f4: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_6f7:
	/* 0x6f7: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x6f7, 0x110, x86_l_110);
x86_l_6fd:
	/* 0x6fd: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_702:
	/* 0x702: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_705:
	/* 0x705: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x705, 0x110, x86_l_110);
x86_l_70a:
	/* 0x70a: mov    rsi,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_70f:
	/* 0x70f: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_712:
	/* 0x712: je     aab <generic_sleepable_offload+0xaab> */
	X86_SIM_X86_JCC(X86_CC_E, 0x712, 0xaab, x86_l_aab);
x86_l_718:
	/* 0x718: mov    rsi,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_71d:
	/* 0x71d: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_722:
	/* 0x722: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_725:
	/* 0x725: je     aab <generic_sleepable_offload+0xaab> */
	X86_SIM_X86_JCC(X86_CC_E, 0x725, 0xaab, x86_l_aab);
x86_l_72b:
	/* 0x72b: jmp    abe <generic_sleepable_offload+0xabe> */
	X86_SIM_X86_JMP(0x72b, 0xabe, x86_l_abe);
x86_l_730:
	/* 0x730: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_735:
	/* 0x735: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_738:
	/* 0x738: je     749 <generic_sleepable_offload+0x749> */
	X86_SIM_X86_JCC(X86_CC_E, 0x738, 0x749, x86_l_749);
x86_l_73a:
	/* 0x73a: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_73f:
	/* 0x73f: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_744:
	/* 0x744: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_747:
	/* 0x747: jne    75c <generic_sleepable_offload+0x75c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x747, 0x75c, x86_l_75c);
x86_l_749:
	/* 0x749: shl    cl,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_74c:
	/* 0x74c: mov    al,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 64ULL);
x86_l_74e:
	/* 0x74e: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_750:
	/* 0x750: mov    ecx,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 64ULL);
x86_l_755:
	/* 0x755: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_757:
	/* 0x757: bzhi   rax,QWORD PTR [rsi],rcx */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RAX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), 0ULL);
x86_l_75c:
	/* 0x75c: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_761:
	/* 0x761: movzx  edx,WORD PTR [r14-0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551612ULL);
x86_l_766:
	/* 0x766: movzx  ecx,BYTE PTR [r14-0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551615ULL);
x86_l_76b:
	/* 0x76b: rorx   edx,edx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RDX, X86_WIDTH_32, 0, 3ULL);
x86_l_771:
	/* 0x771: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_774:
	/* 0x774: jle    7cb <generic_sleepable_offload+0x7cb> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x774, 0x7cb, x86_l_7cb);
x86_l_776:
	/* 0x776: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_779:
	/* 0x779: jle    812 <generic_sleepable_offload+0x812> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x779, 0x812, x86_l_812);
x86_l_77f:
	/* 0x77f: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_782:
	/* 0x782: jle    a2a <generic_sleepable_offload+0xa2a> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x782, 0xa2a, x86_l_a2a);
x86_l_788:
	/* 0x788: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_78b:
	/* 0x78b: je     f12 <generic_sleepable_offload+0xf12> */
	X86_SIM_X86_JCC(X86_CC_E, 0x78b, 0xf12, x86_l_f12);
x86_l_791:
	/* 0x791: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_794:
	/* 0x794: je     e57 <generic_sleepable_offload+0xe57> */
	X86_SIM_X86_JCC(X86_CC_E, 0x794, 0xe57, x86_l_e57);
x86_l_79a:
	/* 0x79a: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_79d:
	/* 0x79d: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x79d, 0x110, x86_l_110);
x86_l_7a3:
	/* 0x7a3: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_7a6:
	/* 0x7a6: jg     1524 <generic_sleepable_offload+0x1524> */
	X86_SIM_X86_JCC(X86_CC_G, 0x7a6, 0x1524, x86_l_1524);
x86_l_7ac:
	/* 0x7ac: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_7af:
	/* 0x7af: je     1999 <generic_sleepable_offload+0x1999> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7af, 0x1999, x86_l_1999);
x86_l_7b5:
	/* 0x7b5: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_7b8:
	/* 0x7b8: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x7b8, 0x110, x86_l_110);
x86_l_7be:
	/* 0x7be: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7c3:
	/* 0x7c3: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7c6:
	/* 0x7c6: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x7c6, 0x110, x86_l_110);
x86_l_7cb:
	/* 0x7cb: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_7ce:
	/* 0x7ce: jg     849 <generic_sleepable_offload+0x849> */
	X86_SIM_X86_JCC(X86_CC_G, 0x7ce, 0x849, x86_l_849);
x86_l_7d0:
	/* 0x7d0: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_7d3:
	/* 0x7d3: jg     8be <generic_sleepable_offload+0x8be> */
	X86_SIM_X86_JCC(X86_CC_G, 0x7d3, 0x8be, x86_l_8be);
x86_l_7d9:
	/* 0x7d9: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_7db:
	/* 0x7db: je     eb2 <generic_sleepable_offload+0xeb2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7db, 0xeb2, x86_l_eb2);
x86_l_7e1:
	/* 0x7e1: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_7e4:
	/* 0x7e4: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x7e4, 0x110, x86_l_110);
x86_l_7ea:
	/* 0x7ea: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_7ed:
	/* 0x7ed: jg     10b9 <generic_sleepable_offload+0x10b9> */
	X86_SIM_X86_JCC(X86_CC_G, 0x7ed, 0x10b9, x86_l_10b9);
x86_l_7f3:
	/* 0x7f3: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_7f6:
	/* 0x7f6: je     162a <generic_sleepable_offload+0x162a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7f6, 0x162a, x86_l_162a);
x86_l_7fc:
	/* 0x7fc: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_7ff:
	/* 0x7ff: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x7ff, 0x110, x86_l_110);
x86_l_805:
	/* 0x805: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_80a:
	/* 0x80a: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_80d:
	/* 0x80d: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x80d, 0x110, x86_l_110);
x86_l_812:
	/* 0x812: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_815:
	/* 0x815: jg     88c <generic_sleepable_offload+0x88c> */
	X86_SIM_X86_JCC(X86_CC_G, 0x815, 0x88c, x86_l_88c);
x86_l_817:
	/* 0x817: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_81a:
	/* 0x81a: je     d83 <generic_sleepable_offload+0xd83> */
	X86_SIM_X86_JCC(X86_CC_E, 0x81a, 0xd83, x86_l_d83);
x86_l_820:
	/* 0x820: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_823:
	/* 0x823: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x823, 0x110, x86_l_110);
x86_l_829:
	/* 0x829: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_82c:
	/* 0x82c: jg     12c2 <generic_sleepable_offload+0x12c2> */
	X86_SIM_X86_JCC(X86_CC_G, 0x82c, 0x12c2, x86_l_12c2);
x86_l_832:
	/* 0x832: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_835:
	/* 0x835: je     1662 <generic_sleepable_offload+0x1662> */
	X86_SIM_X86_JCC(X86_CC_E, 0x835, 0x1662, x86_l_1662);
x86_l_83b:
	/* 0x83b: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_83e:
	/* 0x83e: je     bad <generic_sleepable_offload+0xbad> */
	X86_SIM_X86_JCC(X86_CC_E, 0x83e, 0xbad, x86_l_bad);
x86_l_844:
	/* 0x844: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x844, 0x110, x86_l_110);
x86_l_849:
	/* 0x849: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_84c:
	/* 0x84c: jg     8f8 <generic_sleepable_offload+0x8f8> */
	X86_SIM_X86_JCC(X86_CC_G, 0x84c, 0x8f8, x86_l_8f8);
x86_l_852:
	/* 0x852: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_855:
	/* 0x855: je     cd5 <generic_sleepable_offload+0xcd5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x855, 0xcd5, x86_l_cd5);
x86_l_85b:
	/* 0x85b: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_85e:
	/* 0x85e: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x85e, 0x110, x86_l_110);
x86_l_864:
	/* 0x864: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_867:
	/* 0x867: jg     10d8 <generic_sleepable_offload+0x10d8> */
	X86_SIM_X86_JCC(X86_CC_G, 0x867, 0x10d8, x86_l_10d8);
x86_l_86d:
	/* 0x86d: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_870:
	/* 0x870: je     16fe <generic_sleepable_offload+0x16fe> */
	X86_SIM_X86_JCC(X86_CC_E, 0x870, 0x16fe, x86_l_16fe);
x86_l_876:
	/* 0x876: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_879:
	/* 0x879: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x879, 0x110, x86_l_110);
x86_l_87f:
	/* 0x87f: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_884:
	/* 0x884: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_887:
	/* 0x887: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x887, 0x110, x86_l_110);
x86_l_88c:
	/* 0x88c: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_88f:
	/* 0x88f: je     da3 <generic_sleepable_offload+0xda3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x88f, 0xda3, x86_l_da3);
x86_l_895:
	/* 0x895: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_898:
	/* 0x898: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x898, 0x110, x86_l_110);
x86_l_89e:
	/* 0x89e: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_8a1:
	/* 0x8a1: jg     12d5 <generic_sleepable_offload+0x12d5> */
	X86_SIM_X86_JCC(X86_CC_G, 0x8a1, 0x12d5, x86_l_12d5);
x86_l_8a7:
	/* 0x8a7: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_8aa:
	/* 0x8aa: je     166e <generic_sleepable_offload+0x166e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8aa, 0x166e, x86_l_166e);
x86_l_8b0:
	/* 0x8b0: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_8b3:
	/* 0x8b3: je     c22 <generic_sleepable_offload+0xc22> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8b3, 0xc22, x86_l_c22);
x86_l_8b9:
	/* 0x8b9: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x8b9, 0x110, x86_l_110);
x86_l_8be:
	/* 0x8be: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_8c1:
	/* 0x8c1: je     ed2 <generic_sleepable_offload+0xed2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8c1, 0xed2, x86_l_ed2);
x86_l_8c7:
	/* 0x8c7: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_8ca:
	/* 0x8ca: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x8ca, 0x110, x86_l_110);
x86_l_8d0:
	/* 0x8d0: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_8d3:
	/* 0x8d3: jg     10f7 <generic_sleepable_offload+0x10f7> */
	X86_SIM_X86_JCC(X86_CC_G, 0x8d3, 0x10f7, x86_l_10f7);
x86_l_8d9:
	/* 0x8d9: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_8dc:
	/* 0x8dc: je     1634 <generic_sleepable_offload+0x1634> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8dc, 0x1634, x86_l_1634);
x86_l_8e2:
	/* 0x8e2: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_8e5:
	/* 0x8e5: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x8e5, 0x110, x86_l_110);
x86_l_8eb:
	/* 0x8eb: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_8f0:
	/* 0x8f0: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8f3:
	/* 0x8f3: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x8f3, 0x110, x86_l_110);
x86_l_8f8:
	/* 0x8f8: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_8fb:
	/* 0x8fb: je     ef2 <generic_sleepable_offload+0xef2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8fb, 0xef2, x86_l_ef2);
x86_l_901:
	/* 0x901: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_904:
	/* 0x904: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x904, 0x110, x86_l_110);
x86_l_90a:
	/* 0x90a: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_90d:
	/* 0x90d: jg     1556 <generic_sleepable_offload+0x1556> */
	X86_SIM_X86_JCC(X86_CC_G, 0x90d, 0x1556, x86_l_1556);
x86_l_913:
	/* 0x913: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_916:
	/* 0x916: je     170a <generic_sleepable_offload+0x170a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x916, 0x170a, x86_l_170a);
x86_l_91c:
	/* 0x91c: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_91f:
	/* 0x91f: je     c8e <generic_sleepable_offload+0xc8e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x91f, 0xc8e, x86_l_c8e);
x86_l_925:
	/* 0x925: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x925, 0x110, x86_l_110);
x86_l_92a:
	/* 0x92a: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_92f:
	/* 0x92f: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_932:
	/* 0x932: je     943 <generic_sleepable_offload+0x943> */
	X86_SIM_X86_JCC(X86_CC_E, 0x932, 0x943, x86_l_943);
x86_l_934:
	/* 0x934: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_939:
	/* 0x939: mov    esi,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 0ULL);
x86_l_93e:
	/* 0x93e: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_941:
	/* 0x941: jne    956 <generic_sleepable_offload+0x956> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x941, 0x956, x86_l_956);
x86_l_943:
	/* 0x943: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_946:
	/* 0x946: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_948:
	/* 0x948: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_94a:
	/* 0x94a: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_94f:
	/* 0x94f: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_951:
	/* 0x951: bzhi   rsi,QWORD PTR [rdx],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RSI, X86_RDX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_956:
	/* 0x956: mov    QWORD PTR [rsp+0x78],rsi */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_95b:
	/* 0x95b: mov    eax,0x70 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 112ULL);
x86_l_960:
	/* 0x960: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_965:
	/* 0x965: add    rdx,QWORD PTR [r14] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_968:
	/* 0x968: lea    rdi,[rsp+0x78] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_96d:
	/* 0x96d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_972:
	/* 0x972: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_974:
	/* 0x974: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_976:
	/* 0x976: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x976, 0x110, x86_l_110);
x86_l_97c:
	/* 0x97c: movzx  edx,WORD PTR [r14-0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551612ULL);
x86_l_981:
	/* 0x981: movzx  ecx,BYTE PTR [r14-0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551615ULL);
x86_l_986:
	/* 0x986: mov    rax,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_98b:
	/* 0x98b: rorx   edx,edx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RDX, X86_WIDTH_32, 0, 3ULL);
x86_l_991:
	/* 0x991: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_994:
	/* 0x994: jle    9df <generic_sleepable_offload+0x9df> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x994, 0x9df, x86_l_9df);
x86_l_996:
	/* 0x996: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_999:
	/* 0x999: jle    cfd <generic_sleepable_offload+0xcfd> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x999, 0xcfd, x86_l_cfd);
x86_l_99f:
	/* 0x99f: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_9a2:
	/* 0x9a2: jle    11c4 <generic_sleepable_offload+0x11c4> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x9a2, 0x11c4, x86_l_11c4);
x86_l_9a8:
	/* 0x9a8: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_9ab:
	/* 0x9ab: je     1883 <generic_sleepable_offload+0x1883> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9ab, 0x1883, x86_l_1883);
x86_l_9b1:
	/* 0x9b1: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_9b4:
	/* 0x9b4: je     17a2 <generic_sleepable_offload+0x17a2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9b4, 0x17a2, x86_l_17a2);
x86_l_9ba:
	/* 0x9ba: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_9bd:
	/* 0x9bd: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x9bd, 0x110, x86_l_110);
x86_l_9c3:
	/* 0x9c3: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_9c6:
	/* 0x9c6: jg     11ee <generic_sleepable_offload+0x11ee> */
	X86_SIM_X86_JCC(X86_CC_G, 0x9c6, 0x11ee, x86_l_11ee);
x86_l_9cc:
	/* 0x9cc: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_9cf:
	/* 0x9cf: jne    b1a <generic_sleepable_offload+0xb1a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x9cf, 0xb1a, x86_l_b1a);
x86_l_9d5:
	/* 0x9d5: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9da:
	/* 0x9da: jmp    10e <generic_sleepable_offload+0x10e> */
	X86_SIM_X86_JMP(0x9da, 0x10e, x86_l_10e);
x86_l_9df:
	/* 0x9df: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_9e2:
	/* 0x9e2: jg     d40 <generic_sleepable_offload+0xd40> */
	X86_SIM_X86_JCC(X86_CC_G, 0x9e2, 0xd40, x86_l_d40);
x86_l_9e8:
	/* 0x9e8: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_9eb:
	/* 0x9eb: jg     1150 <generic_sleepable_offload+0x1150> */
	X86_SIM_X86_JCC(X86_CC_G, 0x9eb, 0x1150, x86_l_1150);
x86_l_9f1:
	/* 0x9f1: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_9f3:
	/* 0x9f3: je     17e5 <generic_sleepable_offload+0x17e5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9f3, 0x17e5, x86_l_17e5);
x86_l_9f9:
	/* 0x9f9: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_9fc:
	/* 0x9fc: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x9fc, 0x110, x86_l_110);
x86_l_a02:
	/* 0xa02: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_a05:
	/* 0xa05: jg     1b1e <generic_sleepable_offload+0x1b1e> */
	X86_SIM_X86_JCC(X86_CC_G, 0xa05, 0x1b1e, x86_l_1b1e);
x86_l_a0b:
	/* 0xa0b: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_a0e:
	/* 0xa0e: je     162a <generic_sleepable_offload+0x162a> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa0e, 0x162a, x86_l_162a);
x86_l_a14:
	/* 0xa14: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_a17:
	/* 0xa17: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa17, 0x110, x86_l_110);
x86_l_a1d:
	/* 0xa1d: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a22:
	/* 0xa22: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a25:
	/* 0xa25: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0xa25, 0x110, x86_l_110);
x86_l_a2a:
	/* 0xa2a: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_a2d:
	/* 0xa2d: je     104d <generic_sleepable_offload+0x104d> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa2d, 0x104d, x86_l_104d);
x86_l_a33:
	/* 0xa33: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_a36:
	/* 0xa36: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa36, 0x110, x86_l_110);
x86_l_a3c:
	/* 0xa3c: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_a3f:
	/* 0xa3f: jg     15f8 <generic_sleepable_offload+0x15f8> */
	X86_SIM_X86_JCC(X86_CC_G, 0xa3f, 0x15f8, x86_l_15f8);
x86_l_a45:
	/* 0xa45: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_a48:
	/* 0xa48: je     19d5 <generic_sleepable_offload+0x19d5> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa48, 0x19d5, x86_l_19d5);
x86_l_a4e:
	/* 0xa4e: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_a51:
	/* 0xa51: je     a85 <generic_sleepable_offload+0xa85> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa51, 0xa85, x86_l_a85);
x86_l_a53:
	/* 0xa53: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0xa53, 0x110, x86_l_110);
x86_l_a58:
	/* 0xa58: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_a5b:
	/* 0xa5b: je     1069 <generic_sleepable_offload+0x1069> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa5b, 0x1069, x86_l_1069);
x86_l_a61:
	/* 0xa61: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_a64:
	/* 0xa64: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa64, 0x110, x86_l_110);
x86_l_a6a:
	/* 0xa6a: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_a6d:
	/* 0xa6d: jg     160b <generic_sleepable_offload+0x160b> */
	X86_SIM_X86_JCC(X86_CC_G, 0xa6d, 0x160b, x86_l_160b);
x86_l_a73:
	/* 0xa73: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_a76:
	/* 0xa76: je     11e4 <generic_sleepable_offload+0x11e4> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa76, 0x11e4, x86_l_11e4);
x86_l_a7c:
	/* 0xa7c: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_a7f:
	/* 0xa7f: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa7f, 0x110, x86_l_110);
x86_l_a85:
	/* 0xa85: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_a8a:
	/* 0xa8a: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a8d:
	/* 0xa8d: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0xa8d, 0x110, x86_l_110);
x86_l_a92:
	/* 0xa92: mov    rsi,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_a97:
	/* 0xa97: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_a9a:
	/* 0xa9a: je     aab <generic_sleepable_offload+0xaab> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa9a, 0xaab, x86_l_aab);
x86_l_a9c:
	/* 0xa9c: mov    rsi,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_aa1:
	/* 0xaa1: mov    eax,0x0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 0ULL);
x86_l_aa6:
	/* 0xaa6: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_aa9:
	/* 0xaa9: jne    abe <generic_sleepable_offload+0xabe> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xaa9, 0xabe, x86_l_abe);
x86_l_aab:
	/* 0xaab: shl    cl,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_aae:
	/* 0xaae: mov    al,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_8, 64ULL);
x86_l_ab0:
	/* 0xab0: sub    al,cl */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_ab2:
	/* 0xab2: mov    ecx,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 64ULL);
x86_l_ab7:
	/* 0xab7: sub    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_ab9:
	/* 0xab9: bzhi   rax,QWORD PTR [rsi],rcx */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RAX, X86_RSI, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), 0ULL);
x86_l_abe:
	/* 0xabe: add    rax,QWORD PTR [r14] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RAX, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_ac1:
	/* 0xac1: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_ac6:
	/* 0xac6: movzx  edx,WORD PTR [r14-0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 18446744073709551612ULL);
x86_l_acb:
	/* 0xacb: movzx  ecx,BYTE PTR [r14-0x1] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R14, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 18446744073709551615ULL);
x86_l_ad0:
	/* 0xad0: rorx   edx,edx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RDX, X86_RDX, X86_WIDTH_32, 0, 3ULL);
x86_l_ad6:
	/* 0xad6: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_ad9:
	/* 0xad9: jle    b30 <generic_sleepable_offload+0xb30> */
	X86_SIM_X86_JCC(X86_CC_LE, 0xad9, 0xb30, x86_l_b30);
x86_l_adb:
	/* 0xadb: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_ade:
	/* 0xade: jle    b7b <generic_sleepable_offload+0xb7b> */
	X86_SIM_X86_JCC(X86_CC_LE, 0xade, 0xb7b, x86_l_b7b);
x86_l_ae4:
	/* 0xae4: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_ae7:
	/* 0xae7: jle    c9b <generic_sleepable_offload+0xc9b> */
	X86_SIM_X86_JCC(X86_CC_LE, 0xae7, 0xc9b, x86_l_c9b);
x86_l_aed:
	/* 0xaed: cmp    edx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 14ULL);
x86_l_af0:
	/* 0xaf0: je     102d <generic_sleepable_offload+0x102d> */
	X86_SIM_X86_JCC(X86_CC_E, 0xaf0, 0x102d, x86_l_102d);
x86_l_af6:
	/* 0xaf6: cmp    edx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 16ULL);
x86_l_af9:
	/* 0xaf9: je     e9b <generic_sleepable_offload+0xe9b> */
	X86_SIM_X86_JCC(X86_CC_E, 0xaf9, 0xe9b, x86_l_e9b);
x86_l_aff:
	/* 0xaff: cmp    edx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 19ULL);
x86_l_b02:
	/* 0xb02: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb02, 0x110, x86_l_110);
x86_l_b08:
	/* 0xb08: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_b0b:
	/* 0xb0b: jg     11ee <generic_sleepable_offload+0x11ee> */
	X86_SIM_X86_JCC(X86_CC_G, 0xb0b, 0x11ee, x86_l_11ee);
x86_l_b11:
	/* 0xb11: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_b14:
	/* 0xb14: je     9d5 <generic_sleepable_offload+0x9d5> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb14, 0x9d5, x86_l_9d5);
x86_l_b1a:
	/* 0xb1a: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_b1d:
	/* 0xb1d: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb1d, 0x110, x86_l_110);
x86_l_b23:
	/* 0xb23: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b28:
	/* 0xb28: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b2b:
	/* 0xb2b: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0xb2b, 0x110, x86_l_110);
x86_l_b30:
	/* 0xb30: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_b33:
	/* 0xb33: jg     bba <generic_sleepable_offload+0xbba> */
	X86_SIM_X86_JCC(X86_CC_G, 0xb33, 0xbba, x86_l_bba);
x86_l_b39:
	/* 0xb39: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_b3c:
	/* 0xb3c: jg     c2f <generic_sleepable_offload+0xc2f> */
	X86_SIM_X86_JCC(X86_CC_G, 0xb3c, 0xc2f, x86_l_c2f);
x86_l_b42:
	/* 0xb42: test   edx,edx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RDX, X86_RDX, X86_WIDTH_32);
x86_l_b44:
	/* 0xb44: je     f79 <generic_sleepable_offload+0xf79> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb44, 0xf79, x86_l_f79);
x86_l_b4a:
	/* 0xb4a: cmp    edx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 1ULL);
x86_l_b4d:
	/* 0xb4d: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb4d, 0x110, x86_l_110);
x86_l_b53:
	/* 0xb53: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_b56:
	/* 0xb56: jg     158c <generic_sleepable_offload+0x158c> */
	X86_SIM_X86_JCC(X86_CC_G, 0xb56, 0x158c, x86_l_158c);
x86_l_b5c:
	/* 0xb5c: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_b5f:
	/* 0xb5f: je     19a5 <generic_sleepable_offload+0x19a5> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb5f, 0x19a5, x86_l_19a5);
x86_l_b65:
	/* 0xb65: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_b68:
	/* 0xb68: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb68, 0x110, x86_l_110);
x86_l_b6e:
	/* 0xb6e: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b73:
	/* 0xb73: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b76:
	/* 0xb76: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0xb76, 0x110, x86_l_110);
x86_l_b7b:
	/* 0xb7b: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_b7e:
	/* 0xb7e: jg     bf5 <generic_sleepable_offload+0xbf5> */
	X86_SIM_X86_JCC(X86_CC_G, 0xb7e, 0xbf5, x86_l_bf5);
x86_l_b80:
	/* 0xb80: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_b83:
	/* 0xb83: je     e07 <generic_sleepable_offload+0xe07> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb83, 0xe07, x86_l_e07);
x86_l_b89:
	/* 0xb89: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_b8c:
	/* 0xb8c: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb8c, 0x110, x86_l_110);
x86_l_b92:
	/* 0xb92: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_b95:
	/* 0xb95: jg     132d <generic_sleepable_offload+0x132d> */
	X86_SIM_X86_JCC(X86_CC_G, 0xb95, 0x132d, x86_l_132d);
x86_l_b9b:
	/* 0xb9b: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_b9e:
	/* 0xb9e: je     1662 <generic_sleepable_offload+0x1662> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb9e, 0x1662, x86_l_1662);
x86_l_ba4:
	/* 0xba4: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_ba7:
	/* 0xba7: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xba7, 0x110, x86_l_110);
x86_l_bad:
	/* 0xbad: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_bb2:
	/* 0xbb2: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_bb5:
	/* 0xbb5: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0xbb5, 0x110, x86_l_110);
x86_l_bba:
	/* 0xbba: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_bbd:
	/* 0xbbd: jg     c61 <generic_sleepable_offload+0xc61> */
	X86_SIM_X86_JCC(X86_CC_G, 0xbbd, 0xc61, x86_l_c61);
x86_l_bc3:
	/* 0xbc3: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_bc6:
	/* 0xbc6: je     f9c <generic_sleepable_offload+0xf9c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbc6, 0xf9c, x86_l_f9c);
x86_l_bcc:
	/* 0xbcc: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_bcf:
	/* 0xbcf: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xbcf, 0x110, x86_l_110);
x86_l_bd5:
	/* 0xbd5: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_bd8:
	/* 0xbd8: jg     15ab <generic_sleepable_offload+0x15ab> */
	X86_SIM_X86_JCC(X86_CC_G, 0xbd8, 0x15ab, x86_l_15ab);
x86_l_bde:
	/* 0xbde: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_be1:
	/* 0xbe1: je     16fe <generic_sleepable_offload+0x16fe> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbe1, 0x16fe, x86_l_16fe);
x86_l_be7:
	/* 0xbe7: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_bea:
	/* 0xbea: je     d76 <generic_sleepable_offload+0xd76> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbea, 0xd76, x86_l_d76);
x86_l_bf0:
	/* 0xbf0: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0xbf0, 0x110, x86_l_110);
x86_l_bf5:
	/* 0xbf5: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_bf8:
	/* 0xbf8: je     e2f <generic_sleepable_offload+0xe2f> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbf8, 0xe2f, x86_l_e2f);
x86_l_bfe:
	/* 0xbfe: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_c01:
	/* 0xc01: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xc01, 0x110, x86_l_110);
x86_l_c07:
	/* 0xc07: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_c0a:
	/* 0xc0a: jg     134c <generic_sleepable_offload+0x134c> */
	X86_SIM_X86_JCC(X86_CC_G, 0xc0a, 0x134c, x86_l_134c);
x86_l_c10:
	/* 0xc10: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_c13:
	/* 0xc13: je     166e <generic_sleepable_offload+0x166e> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc13, 0x166e, x86_l_166e);
x86_l_c19:
	/* 0xc19: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_c1c:
	/* 0xc1c: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xc1c, 0x110, x86_l_110);
x86_l_c22:
	/* 0xc22: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_c27:
	/* 0xc27: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c2a:
	/* 0xc2a: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0xc2a, 0x110, x86_l_110);
x86_l_c2f:
	/* 0xc2f: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_c32:
	/* 0xc32: je     fbc <generic_sleepable_offload+0xfbc> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc32, 0xfbc, x86_l_fbc);
x86_l_c38:
	/* 0xc38: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_c3b:
	/* 0xc3b: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xc3b, 0x110, x86_l_110);
x86_l_c41:
	/* 0xc41: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_c44:
	/* 0xc44: jg     15c2 <generic_sleepable_offload+0x15c2> */
	X86_SIM_X86_JCC(X86_CC_G, 0xc44, 0x15c2, x86_l_15c2);
x86_l_c4a:
	/* 0xc4a: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_c4d:
	/* 0xc4d: je     19b1 <generic_sleepable_offload+0x19b1> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc4d, 0x19b1, x86_l_19b1);
x86_l_c53:
	/* 0xc53: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_c56:
	/* 0xc56: je     117d <generic_sleepable_offload+0x117d> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc56, 0x117d, x86_l_117d);
x86_l_c5c:
	/* 0xc5c: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0xc5c, 0x110, x86_l_110);
x86_l_c61:
	/* 0xc61: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_c64:
	/* 0xc64: je     fe1 <generic_sleepable_offload+0xfe1> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc64, 0xfe1, x86_l_fe1);
x86_l_c6a:
	/* 0xc6a: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_c6d:
	/* 0xc6d: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xc6d, 0x110, x86_l_110);
x86_l_c73:
	/* 0xc73: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_c76:
	/* 0xc76: jg     15d9 <generic_sleepable_offload+0x15d9> */
	X86_SIM_X86_JCC(X86_CC_G, 0xc76, 0x15d9, x86_l_15d9);
x86_l_c7c:
	/* 0xc7c: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_c7f:
	/* 0xc7f: je     170a <generic_sleepable_offload+0x170a> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc7f, 0x170a, x86_l_170a);
x86_l_c85:
	/* 0xc85: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_c88:
	/* 0xc88: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xc88, 0x110, x86_l_110);
x86_l_c8e:
	/* 0xc8e: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c93:
	/* 0xc93: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c96:
	/* 0xc96: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0xc96, 0x110, x86_l_110);
x86_l_c9b:
	/* 0xc9b: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_c9e:
	/* 0xc9e: je     1091 <generic_sleepable_offload+0x1091> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc9e, 0x1091, x86_l_1091);
x86_l_ca4:
	/* 0xca4: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_ca7:
	/* 0xca7: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xca7, 0x110, x86_l_110);
x86_l_cad:
	/* 0xcad: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_cb0:
	/* 0xcb0: jg     120d <generic_sleepable_offload+0x120d> */
	X86_SIM_X86_JCC(X86_CC_G, 0xcb0, 0x120d, x86_l_120d);
x86_l_cb6:
	/* 0xcb6: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_cb9:
	/* 0xcb9: je     11e4 <generic_sleepable_offload+0x11e4> */
	X86_SIM_X86_JCC(X86_CC_E, 0xcb9, 0x11e4, x86_l_11e4);
x86_l_cbf:
	/* 0xcbf: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_cc2:
	/* 0xcc2: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xcc2, 0x110, x86_l_110);
x86_l_cc8:
	/* 0xcc8: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_ccd:
	/* 0xccd: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cd0:
	/* 0xcd0: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0xcd0, 0x110, x86_l_110);
x86_l_cd5:
	/* 0xcd5: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_cd8:
	/* 0xcd8: jg     f32 <generic_sleepable_offload+0xf32> */
	X86_SIM_X86_JCC(X86_CC_G, 0xcd8, 0xf32, x86_l_f32);
x86_l_cde:
	/* 0xcde: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_ce1:
	/* 0xce1: je     182c <generic_sleepable_offload+0x182c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xce1, 0x182c, x86_l_182c);
x86_l_ce7:
	/* 0xce7: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_cea:
	/* 0xcea: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xcea, 0x110, x86_l_110);
x86_l_cf0:
	/* 0xcf0: mov    rcx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_cf5:
	/* 0xcf5: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cf8:
	/* 0xcf8: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0xcf8, 0x110, x86_l_110);
x86_l_cfd:
	/* 0xcfd: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_d00:
	/* 0xd00: jg     1116 <generic_sleepable_offload+0x1116> */
	X86_SIM_X86_JCC(X86_CC_G, 0xd00, 0x1116, x86_l_1116);
x86_l_d06:
	/* 0xd06: cmp    edx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_d09:
	/* 0xd09: je     1752 <generic_sleepable_offload+0x1752> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd09, 0x1752, x86_l_1752);
x86_l_d0f:
	/* 0xd0f: cmp    edx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 9ULL);
x86_l_d12:
	/* 0xd12: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xd12, 0x110, x86_l_110);
x86_l_d18:
	/* 0xd18: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_d1b:
	/* 0xd1b: jg     1a1f <generic_sleepable_offload+0x1a1f> */
	X86_SIM_X86_JCC(X86_CC_G, 0xd1b, 0x1a1f, x86_l_1a1f);
x86_l_d21:
	/* 0xd21: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_d24:
	/* 0xd24: je     18d3 <generic_sleepable_offload+0x18d3> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd24, 0x18d3, x86_l_18d3);
x86_l_d2a:
	/* 0xd2a: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_d2d:
	/* 0xd2d: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xd2d, 0x110, x86_l_110);
x86_l_d33:
	/* 0xd33: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_d38:
	/* 0xd38: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d3b:
	/* 0xd3b: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0xd3b, 0x110, x86_l_110);
x86_l_d40:
	/* 0xd40: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_d43:
	/* 0xd43: jg     118a <generic_sleepable_offload+0x118a> */
	X86_SIM_X86_JCC(X86_CC_G, 0xd43, 0x118a, x86_l_118a);
x86_l_d49:
	/* 0xd49: cmp    edx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_d4c:
	/* 0xd4c: je     1808 <generic_sleepable_offload+0x1808> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd4c, 0x1808, x86_l_1808);
x86_l_d52:
	/* 0xd52: cmp    edx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 5ULL);
x86_l_d55:
	/* 0xd55: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xd55, 0x110, x86_l_110);
x86_l_d5b:
	/* 0xd5b: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_d5e:
	/* 0xd5e: jg     1b3d <generic_sleepable_offload+0x1b3d> */
	X86_SIM_X86_JCC(X86_CC_G, 0xd5e, 0x1b3d, x86_l_1b3d);
x86_l_d64:
	/* 0xd64: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_d67:
	/* 0xd67: je     1911 <generic_sleepable_offload+0x1911> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd67, 0x1911, x86_l_1911);
x86_l_d6d:
	/* 0xd6d: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_d70:
	/* 0xd70: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xd70, 0x110, x86_l_110);
x86_l_d76:
	/* 0xd76: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d7b:
	/* 0xd7b: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d7e:
	/* 0xd7e: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0xd7e, 0x110, x86_l_110);
x86_l_d83:
	/* 0xd83: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_d86:
	/* 0xd86: jg     122c <generic_sleepable_offload+0x122c> */
	X86_SIM_X86_JCC(X86_CC_G, 0xd86, 0x122c, x86_l_122c);
x86_l_d8c:
	/* 0xd8c: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_d8f:
	/* 0xd8f: je     163e <generic_sleepable_offload+0x163e> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd8f, 0x163e, x86_l_163e);
x86_l_d95:
	/* 0xd95: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_d98:
	/* 0xd98: je     e22 <generic_sleepable_offload+0xe22> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd98, 0xe22, x86_l_e22);
x86_l_d9e:
	/* 0xd9e: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0xd9e, 0x110, x86_l_110);
x86_l_da3:
	/* 0xda3: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_da6:
	/* 0xda6: jg     123f <generic_sleepable_offload+0x123f> */
	X86_SIM_X86_JCC(X86_CC_G, 0xda6, 0x123f, x86_l_123f);
x86_l_dac:
	/* 0xdac: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_daf:
	/* 0xdaf: je     164a <generic_sleepable_offload+0x164a> */
	X86_SIM_X86_JCC(X86_CC_E, 0xdaf, 0x164a, x86_l_164a);
x86_l_db5:
	/* 0xdb5: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_db8:
	/* 0xdb8: je     e4a <generic_sleepable_offload+0xe4a> */
	X86_SIM_X86_JCC(X86_CC_E, 0xdb8, 0xe4a, x86_l_e4a);
x86_l_dbe:
	/* 0xdbe: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0xdbe, 0x110, x86_l_110);
x86_l_dc3:
	/* 0xdc3: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_dc6:
	/* 0xdc6: jg     124e <generic_sleepable_offload+0x124e> */
	X86_SIM_X86_JCC(X86_CC_G, 0xdc6, 0x124e, x86_l_124e);
x86_l_dcc:
	/* 0xdcc: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_dcf:
	/* 0xdcf: je     18bf <generic_sleepable_offload+0x18bf> */
	X86_SIM_X86_JCC(X86_CC_E, 0xdcf, 0x18bf, x86_l_18bf);
x86_l_dd5:
	/* 0xdd5: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_dd8:
	/* 0xdd8: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xdd8, 0x110, x86_l_110);
x86_l_dde:
	/* 0xdde: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_de3:
	/* 0xde3: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_de6:
	/* 0xde6: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0xde6, 0x110, x86_l_110);
x86_l_deb:
	/* 0xdeb: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_dee:
	/* 0xdee: jg     126d <generic_sleepable_offload+0x126d> */
	X86_SIM_X86_JCC(X86_CC_G, 0xdee, 0x126d, x86_l_126d);
x86_l_df4:
	/* 0xdf4: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_df7:
	/* 0xdf7: je     18c9 <generic_sleepable_offload+0x18c9> */
	X86_SIM_X86_JCC(X86_CC_E, 0xdf7, 0x18c9, x86_l_18c9);
x86_l_dfd:
	/* 0xdfd: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_e00:
	/* 0xe00: je     e4a <generic_sleepable_offload+0xe4a> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe00, 0xe4a, x86_l_e4a);
x86_l_e02:
	/* 0xe02: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0xe02, 0x110, x86_l_110);
x86_l_e07:
	/* 0xe07: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_e0a:
	/* 0xe0a: jg     127c <generic_sleepable_offload+0x127c> */
	X86_SIM_X86_JCC(X86_CC_G, 0xe0a, 0x127c, x86_l_127c);
x86_l_e10:
	/* 0xe10: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_e13:
	/* 0xe13: je     163e <generic_sleepable_offload+0x163e> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe13, 0x163e, x86_l_163e);
x86_l_e19:
	/* 0xe19: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_e1c:
	/* 0xe1c: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe1c, 0x110, x86_l_110);
x86_l_e22:
	/* 0xe22: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_e27:
	/* 0xe27: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e2a:
	/* 0xe2a: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0xe2a, 0x110, x86_l_110);
x86_l_e2f:
	/* 0xe2f: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_e32:
	/* 0xe32: jg     129b <generic_sleepable_offload+0x129b> */
	X86_SIM_X86_JCC(X86_CC_G, 0xe32, 0x129b, x86_l_129b);
x86_l_e38:
	/* 0xe38: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_e3b:
	/* 0xe3b: je     164a <generic_sleepable_offload+0x164a> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe3b, 0x164a, x86_l_164a);
x86_l_e41:
	/* 0xe41: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_e44:
	/* 0xe44: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe44, 0x110, x86_l_110);
x86_l_e4a:
	/* 0xe4a: mov    rcx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_e4f:
	/* 0xe4f: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e52:
	/* 0xe52: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0xe52, 0x110, x86_l_110);
x86_l_e57:
	/* 0xe57: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_e5a:
	/* 0xe5a: jg     12e8 <generic_sleepable_offload+0x12e8> */
	X86_SIM_X86_JCC(X86_CC_G, 0xe5a, 0x12e8, x86_l_12e8);
x86_l_e60:
	/* 0xe60: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_e63:
	/* 0xe63: je     193d <generic_sleepable_offload+0x193d> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe63, 0x193d, x86_l_193d);
x86_l_e69:
	/* 0xe69: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_e6c:
	/* 0xe6c: je     e8e <generic_sleepable_offload+0xe8e> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe6c, 0xe8e, x86_l_e8e);
x86_l_e6e:
	/* 0xe6e: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0xe6e, 0x110, x86_l_110);
x86_l_e73:
	/* 0xe73: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_e76:
	/* 0xe76: jg     1373 <generic_sleepable_offload+0x1373> */
	X86_SIM_X86_JCC(X86_CC_G, 0xe76, 0x1373, x86_l_1373);
x86_l_e7c:
	/* 0xe7c: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_e7f:
	/* 0xe7f: je     109 <generic_sleepable_offload+0x109> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe7f, 0x109, x86_l_109);
x86_l_e85:
	/* 0xe85: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_e88:
	/* 0xe88: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe88, 0x110, x86_l_110);
x86_l_e8e:
	/* 0xe8e: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_e93:
	/* 0xe93: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e96:
	/* 0xe96: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0xe96, 0x110, x86_l_110);
x86_l_e9b:
	/* 0xe9b: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_e9e:
	/* 0xe9e: jg     17c6 <generic_sleepable_offload+0x17c6> */
	X86_SIM_X86_JCC(X86_CC_G, 0xe9e, 0x17c6, x86_l_17c6);
x86_l_ea4:
	/* 0xea4: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_ea7:
	/* 0xea7: jne    17b0 <generic_sleepable_offload+0x17b0> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xea7, 0x17b0, x86_l_17b0);
x86_l_ead:
	/* 0xead: jmp    109 <generic_sleepable_offload+0x109> */
	X86_SIM_X86_JMP(0xead, 0x109, x86_l_109);
x86_l_eb2:
	/* 0xeb2: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_eb5:
	/* 0xeb5: jg     1392 <generic_sleepable_offload+0x1392> */
	X86_SIM_X86_JCC(X86_CC_G, 0xeb5, 0x1392, x86_l_1392);
x86_l_ebb:
	/* 0xebb: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_ebe:
	/* 0xebe: je     169e <generic_sleepable_offload+0x169e> */
	X86_SIM_X86_JCC(X86_CC_E, 0xebe, 0x169e, x86_l_169e);
x86_l_ec4:
	/* 0xec4: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_ec7:
	/* 0xec7: je     f94 <generic_sleepable_offload+0xf94> */
	X86_SIM_X86_JCC(X86_CC_E, 0xec7, 0xf94, x86_l_f94);
x86_l_ecd:
	/* 0xecd: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0xecd, 0x110, x86_l_110);
x86_l_ed2:
	/* 0xed2: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_ed5:
	/* 0xed5: jg     13a9 <generic_sleepable_offload+0x13a9> */
	X86_SIM_X86_JCC(X86_CC_G, 0xed5, 0x13a9, x86_l_13a9);
x86_l_edb:
	/* 0xedb: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_ede:
	/* 0xede: je     16a5 <generic_sleepable_offload+0x16a5> */
	X86_SIM_X86_JCC(X86_CC_E, 0xede, 0x16a5, x86_l_16a5);
x86_l_ee4:
	/* 0xee4: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_ee7:
	/* 0xee7: je     fd7 <generic_sleepable_offload+0xfd7> */
	X86_SIM_X86_JCC(X86_CC_E, 0xee7, 0xfd7, x86_l_fd7);
x86_l_eed:
	/* 0xeed: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0xeed, 0x110, x86_l_110);
x86_l_ef2:
	/* 0xef2: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_ef5:
	/* 0xef5: jg     13c0 <generic_sleepable_offload+0x13c0> */
	X86_SIM_X86_JCC(X86_CC_G, 0xef5, 0x13c0, x86_l_13c0);
x86_l_efb:
	/* 0xefb: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_efe:
	/* 0xefe: je     16ae <generic_sleepable_offload+0x16ae> */
	X86_SIM_X86_JCC(X86_CC_E, 0xefe, 0x16ae, x86_l_16ae);
x86_l_f04:
	/* 0xf04: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_f07:
	/* 0xf07: je     ffc <generic_sleepable_offload+0xffc> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf07, 0xffc, x86_l_ffc);
x86_l_f0d:
	/* 0xf0d: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0xf0d, 0x110, x86_l_110);
x86_l_f12:
	/* 0xf12: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_f15:
	/* 0xf15: jg     13d7 <generic_sleepable_offload+0x13d7> */
	X86_SIM_X86_JCC(X86_CC_G, 0xf15, 0x13d7, x86_l_13d7);
x86_l_f1b:
	/* 0xf1b: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_f1e:
	/* 0xf1e: je     16d6 <generic_sleepable_offload+0x16d6> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf1e, 0x16d6, x86_l_16d6);
x86_l_f24:
	/* 0xf24: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_f27:
	/* 0xf27: je     1024 <generic_sleepable_offload+0x1024> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf27, 0x1024, x86_l_1024);
x86_l_f2d:
	/* 0xf2d: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0xf2d, 0x110, x86_l_110);
x86_l_f32:
	/* 0xf32: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_f35:
	/* 0xf35: je     1692 <generic_sleepable_offload+0x1692> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf35, 0x1692, x86_l_1692);
x86_l_f3b:
	/* 0xf3b: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_f3e:
	/* 0xf3e: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf3e, 0x110, x86_l_110);
x86_l_f44:
	/* 0xf44: mov    rcx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_f49:
	/* 0xf49: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f4c:
	/* 0xf4c: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0xf4c, 0x110, x86_l_110);
x86_l_f51:
	/* 0xf51: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_f54:
	/* 0xf54: jg     1423 <generic_sleepable_offload+0x1423> */
	X86_SIM_X86_JCC(X86_CC_G, 0xf54, 0x1423, x86_l_1423);
x86_l_f5a:
	/* 0xf5a: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_f5d:
	/* 0xf5d: je     18f3 <generic_sleepable_offload+0x18f3> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf5d, 0x18f3, x86_l_18f3);
x86_l_f63:
	/* 0xf63: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_f66:
	/* 0xf66: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf66, 0x110, x86_l_110);
x86_l_f6c:
	/* 0xf6c: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_f71:
	/* 0xf71: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f74:
	/* 0xf74: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0xf74, 0x110, x86_l_110);
x86_l_f79:
	/* 0xf79: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_f7c:
	/* 0xf7c: jg     1442 <generic_sleepable_offload+0x1442> */
	X86_SIM_X86_JCC(X86_CC_G, 0xf7c, 0x1442, x86_l_1442);
x86_l_f82:
	/* 0xf82: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_f85:
	/* 0xf85: je     169e <generic_sleepable_offload+0x169e> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf85, 0x169e, x86_l_169e);
x86_l_f8b:
	/* 0xf8b: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_f8e:
	/* 0xf8e: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf8e, 0x110, x86_l_110);
x86_l_f94:
	/* 0xf94: mov    WORD PTR [rbx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f97:
	/* 0xf97: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0xf97, 0x110, x86_l_110);
x86_l_f9c:
	/* 0xf9c: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_f9f:
	/* 0xf9f: jg     145c <generic_sleepable_offload+0x145c> */
	X86_SIM_X86_JCC(X86_CC_G, 0xf9f, 0x145c, x86_l_145c);
x86_l_fa5:
	/* 0xfa5: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_fa8:
	/* 0xfa8: je     1965 <generic_sleepable_offload+0x1965> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfa8, 0x1965, x86_l_1965);
x86_l_fae:
	/* 0xfae: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_fb1:
	/* 0xfb1: je     181f <generic_sleepable_offload+0x181f> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfb1, 0x181f, x86_l_181f);
x86_l_fb7:
	/* 0xfb7: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0xfb7, 0x110, x86_l_110);
x86_l_fbc:
	/* 0xfbc: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_fbf:
	/* 0xfbf: jg     1473 <generic_sleepable_offload+0x1473> */
	X86_SIM_X86_JCC(X86_CC_G, 0xfbf, 0x1473, x86_l_1473);
x86_l_fc5:
	/* 0xfc5: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_fc8:
	/* 0xfc8: je     16a5 <generic_sleepable_offload+0x16a5> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfc8, 0x16a5, x86_l_16a5);
x86_l_fce:
	/* 0xfce: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_fd1:
	/* 0xfd1: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xfd1, 0x110, x86_l_110);
x86_l_fd7:
	/* 0xfd7: mov    WORD PTR [r12],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fdc:
	/* 0xfdc: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0xfdc, 0x110, x86_l_110);
x86_l_fe1:
	/* 0xfe1: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_fe4:
	/* 0xfe4: jg     148e <generic_sleepable_offload+0x148e> */
	X86_SIM_X86_JCC(X86_CC_G, 0xfe4, 0x148e, x86_l_148e);
x86_l_fea:
	/* 0xfea: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_fed:
	/* 0xfed: je     16ae <generic_sleepable_offload+0x16ae> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfed, 0x16ae, x86_l_16ae);
x86_l_ff3:
	/* 0xff3: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_ff6:
	/* 0xff6: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xff6, 0x110, x86_l_110);
x86_l_ffc:
	/* 0xffc: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1001:
	/* 0x1001: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1004:
	/* 0x1004: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1004, 0x110, x86_l_110);
x86_l_1009:
	/* 0x1009: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_100c:
	/* 0x100c: jg     14ad <generic_sleepable_offload+0x14ad> */
	X86_SIM_X86_JCC(X86_CC_G, 0x100c, 0x14ad, x86_l_14ad);
x86_l_1012:
	/* 0x1012: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1015:
	/* 0x1015: je     16d6 <generic_sleepable_offload+0x16d6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1015, 0x16d6, x86_l_16d6);
x86_l_101b:
	/* 0x101b: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_101e:
	/* 0x101e: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x101e, 0x110, x86_l_110);
x86_l_1024:
	/* 0x1024: mov    WORD PTR [rbp+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1028:
	/* 0x1028: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1028, 0x110, x86_l_110);
x86_l_102d:
	/* 0x102d: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_1030:
	/* 0x1030: jg     14c8 <generic_sleepable_offload+0x14c8> */
	X86_SIM_X86_JCC(X86_CC_G, 0x1030, 0x14c8, x86_l_14c8);
x86_l_1036:
	/* 0x1036: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1039:
	/* 0x1039: je     18fd <generic_sleepable_offload+0x18fd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1039, 0x18fd, x86_l_18fd);
x86_l_103f:
	/* 0x103f: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1042:
	/* 0x1042: je     189a <generic_sleepable_offload+0x189a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1042, 0x189a, x86_l_189a);
x86_l_1048:
	/* 0x1048: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1048, 0x110, x86_l_110);
x86_l_104d:
	/* 0x104d: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_1050:
	/* 0x1050: jg     14df <generic_sleepable_offload+0x14df> */
	X86_SIM_X86_JCC(X86_CC_G, 0x1050, 0x14df, x86_l_14df);
x86_l_1056:
	/* 0x1056: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1059:
	/* 0x1059: je     198d <generic_sleepable_offload+0x198d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1059, 0x198d, x86_l_198d);
x86_l_105f:
	/* 0x105f: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1062:
	/* 0x1062: je     1084 <generic_sleepable_offload+0x1084> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1062, 0x1084, x86_l_1084);
x86_l_1064:
	/* 0x1064: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1064, 0x110, x86_l_110);
x86_l_1069:
	/* 0x1069: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_106c:
	/* 0x106c: jg     14f2 <generic_sleepable_offload+0x14f2> */
	X86_SIM_X86_JCC(X86_CC_G, 0x106c, 0x14f2, x86_l_14f2);
x86_l_1072:
	/* 0x1072: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1075:
	/* 0x1075: je     18b5 <generic_sleepable_offload+0x18b5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1075, 0x18b5, x86_l_18b5);
x86_l_107b:
	/* 0x107b: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_107e:
	/* 0x107e: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x107e, 0x110, x86_l_110);
x86_l_1084:
	/* 0x1084: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1089:
	/* 0x1089: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_108c:
	/* 0x108c: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x108c, 0x110, x86_l_110);
x86_l_1091:
	/* 0x1091: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_1094:
	/* 0x1094: jg     1505 <generic_sleepable_offload+0x1505> */
	X86_SIM_X86_JCC(X86_CC_G, 0x1094, 0x1505, x86_l_1505);
x86_l_109a:
	/* 0x109a: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_109d:
	/* 0x109d: je     18b5 <generic_sleepable_offload+0x18b5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x109d, 0x18b5, x86_l_18b5);
x86_l_10a3:
	/* 0x10a3: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_10a6:
	/* 0x10a6: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x10a6, 0x110, x86_l_110);
x86_l_10ac:
	/* 0x10ac: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_10b1:
	/* 0x10b1: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10b4:
	/* 0x10b4: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x10b4, 0x110, x86_l_110);
x86_l_10b9:
	/* 0x10b9: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_10bc:
	/* 0x10bc: je     1716 <generic_sleepable_offload+0x1716> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10bc, 0x1716, x86_l_1716);
x86_l_10c2:
	/* 0x10c2: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_10c5:
	/* 0x10c5: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x10c5, 0x110, x86_l_110);
x86_l_10cb:
	/* 0x10cb: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_10d0:
	/* 0x10d0: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10d3:
	/* 0x10d3: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x10d3, 0x110, x86_l_110);
x86_l_10d8:
	/* 0x10d8: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_10db:
	/* 0x10db: je     1722 <generic_sleepable_offload+0x1722> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10db, 0x1722, x86_l_1722);
x86_l_10e1:
	/* 0x10e1: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_10e4:
	/* 0x10e4: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x10e4, 0x110, x86_l_110);
x86_l_10ea:
	/* 0x10ea: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_10ef:
	/* 0x10ef: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_10f2:
	/* 0x10f2: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x10f2, 0x110, x86_l_110);
x86_l_10f7:
	/* 0x10f7: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_10fa:
	/* 0x10fa: je     172e <generic_sleepable_offload+0x172e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10fa, 0x172e, x86_l_172e);
x86_l_1100:
	/* 0x1100: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1103:
	/* 0x1103: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1103, 0x110, x86_l_110);
x86_l_1109:
	/* 0x1109: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_110e:
	/* 0x110e: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1111:
	/* 0x1111: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1111, 0x110, x86_l_110);
x86_l_1116:
	/* 0x1116: cmp    edx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 10ULL);
x86_l_1119:
	/* 0x1119: je     177a <generic_sleepable_offload+0x177a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1119, 0x177a, x86_l_177a);
x86_l_111f:
	/* 0x111f: cmp    edx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 11ULL);
x86_l_1122:
	/* 0x1122: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1122, 0x110, x86_l_110);
x86_l_1128:
	/* 0x1128: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_112b:
	/* 0x112b: jg     1a3e <generic_sleepable_offload+0x1a3e> */
	X86_SIM_X86_JCC(X86_CC_G, 0x112b, 0x1a3e, x86_l_1a3e);
x86_l_1131:
	/* 0x1131: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1134:
	/* 0x1134: je     18dd <generic_sleepable_offload+0x18dd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1134, 0x18dd, x86_l_18dd);
x86_l_113a:
	/* 0x113a: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_113d:
	/* 0x113d: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x113d, 0x110, x86_l_110);
x86_l_1143:
	/* 0x1143: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1148:
	/* 0x1148: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_114b:
	/* 0x114b: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x114b, 0x110, x86_l_110);
x86_l_1150:
	/* 0x1150: cmp    edx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 2ULL);
x86_l_1153:
	/* 0x1153: je     1836 <generic_sleepable_offload+0x1836> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1153, 0x1836, x86_l_1836);
x86_l_1159:
	/* 0x1159: cmp    edx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 3ULL);
x86_l_115c:
	/* 0x115c: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x115c, 0x110, x86_l_110);
x86_l_1162:
	/* 0x1162: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_1165:
	/* 0x1165: jg     1b64 <generic_sleepable_offload+0x1b64> */
	X86_SIM_X86_JCC(X86_CC_G, 0x1165, 0x1b64, x86_l_1b64);
x86_l_116b:
	/* 0x116b: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_116e:
	/* 0x116e: je     1634 <generic_sleepable_offload+0x1634> */
	X86_SIM_X86_JCC(X86_CC_E, 0x116e, 0x1634, x86_l_1634);
x86_l_1174:
	/* 0x1174: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1177:
	/* 0x1177: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1177, 0x110, x86_l_110);
x86_l_117d:
	/* 0x117d: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1182:
	/* 0x1182: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1185:
	/* 0x1185: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1185, 0x110, x86_l_110);
x86_l_118a:
	/* 0x118a: cmp    edx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 6ULL);
x86_l_118d:
	/* 0x118d: je     185b <generic_sleepable_offload+0x185b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x118d, 0x185b, x86_l_185b);
x86_l_1193:
	/* 0x1193: cmp    edx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 7ULL);
x86_l_1196:
	/* 0x1196: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1196, 0x110, x86_l_110);
x86_l_119c:
	/* 0x119c: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_119f:
	/* 0x119f: jg     1b8b <generic_sleepable_offload+0x1b8b> */
	X86_SIM_X86_JCC(X86_CC_G, 0x119f, 0x1b8b, x86_l_1b8b);
x86_l_11a5:
	/* 0x11a5: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_11a8:
	/* 0x11a8: je     191b <generic_sleepable_offload+0x191b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11a8, 0x191b, x86_l_191b);
x86_l_11ae:
	/* 0x11ae: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_11b1:
	/* 0x11b1: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x11b1, 0x110, x86_l_110);
x86_l_11b7:
	/* 0x11b7: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_11bc:
	/* 0x11bc: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11bf:
	/* 0x11bf: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x11bf, 0x110, x86_l_110);
x86_l_11c4:
	/* 0x11c4: cmp    edx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 12ULL);
x86_l_11c7:
	/* 0x11c7: je     18a3 <generic_sleepable_offload+0x18a3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11c7, 0x18a3, x86_l_18a3);
x86_l_11cd:
	/* 0x11cd: cmp    edx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RDX, X86_WIDTH_32, 13ULL);
x86_l_11d0:
	/* 0x11d0: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x11d0, 0x110, x86_l_110);
x86_l_11d6:
	/* 0x11d6: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_11d9:
	/* 0x11d9: jg     120d <generic_sleepable_offload+0x120d> */
	X86_SIM_X86_JCC(X86_CC_G, 0x11d9, 0x120d, x86_l_120d);
x86_l_11db:
	/* 0x11db: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_11de:
	/* 0x11de: jne    cbf <generic_sleepable_offload+0xcbf> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x11de, 0xcbf, x86_l_cbf);
x86_l_11e4:
	/* 0x11e4: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_11e9:
	/* 0x11e9: jmp    10e <generic_sleepable_offload+0x10e> */
	X86_SIM_X86_JMP(0x11e9, 0x10e, x86_l_10e);
x86_l_11ee:
	/* 0x11ee: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_11f1:
	/* 0x11f1: je     1905 <generic_sleepable_offload+0x1905> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11f1, 0x1905, x86_l_1905);
x86_l_11f7:
	/* 0x11f7: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_11fa:
	/* 0x11fa: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x11fa, 0x110, x86_l_110);
x86_l_1200:
	/* 0x1200: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1205:
	/* 0x1205: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1208:
	/* 0x1208: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1208, 0x110, x86_l_110);
x86_l_120d:
	/* 0x120d: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1210:
	/* 0x1210: je     1925 <generic_sleepable_offload+0x1925> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1210, 0x1925, x86_l_1925);
x86_l_1216:
	/* 0x1216: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1219:
	/* 0x1219: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1219, 0x110, x86_l_110);
x86_l_121f:
	/* 0x121f: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1224:
	/* 0x1224: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1227:
	/* 0x1227: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1227, 0x110, x86_l_110);
x86_l_122c:
	/* 0x122c: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_122f:
	/* 0x122f: je     1656 <generic_sleepable_offload+0x1656> */
	X86_SIM_X86_JCC(X86_CC_E, 0x122f, 0x1656, x86_l_1656);
x86_l_1235:
	/* 0x1235: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1238:
	/* 0x1238: je     128e <generic_sleepable_offload+0x128e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1238, 0x128e, x86_l_128e);
x86_l_123a:
	/* 0x123a: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x123a, 0x110, x86_l_110);
x86_l_123f:
	/* 0x123f: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1242:
	/* 0x1242: je     12b6 <generic_sleepable_offload+0x12b6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1242, 0x12b6, x86_l_12b6);
x86_l_1244:
	/* 0x1244: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1247:
	/* 0x1247: je     12a9 <generic_sleepable_offload+0x12a9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1247, 0x12a9, x86_l_12a9);
x86_l_1249:
	/* 0x1249: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1249, 0x110, x86_l_110);
x86_l_124e:
	/* 0x124e: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1251:
	/* 0x1251: je     1931 <generic_sleepable_offload+0x1931> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1251, 0x1931, x86_l_1931);
x86_l_1257:
	/* 0x1257: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_125a:
	/* 0x125a: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x125a, 0x110, x86_l_110);
x86_l_1260:
	/* 0x1260: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1265:
	/* 0x1265: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1268:
	/* 0x1268: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1268, 0x110, x86_l_110);
x86_l_126d:
	/* 0x126d: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1270:
	/* 0x1270: je     12b6 <generic_sleepable_offload+0x12b6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1270, 0x12b6, x86_l_12b6);
x86_l_1272:
	/* 0x1272: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1275:
	/* 0x1275: je     12a9 <generic_sleepable_offload+0x12a9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1275, 0x12a9, x86_l_12a9);
x86_l_1277:
	/* 0x1277: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1277, 0x110, x86_l_110);
x86_l_127c:
	/* 0x127c: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_127f:
	/* 0x127f: je     1656 <generic_sleepable_offload+0x1656> */
	X86_SIM_X86_JCC(X86_CC_E, 0x127f, 0x1656, x86_l_1656);
x86_l_1285:
	/* 0x1285: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1288:
	/* 0x1288: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1288, 0x110, x86_l_110);
x86_l_128e:
	/* 0x128e: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1293:
	/* 0x1293: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1296:
	/* 0x1296: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1296, 0x110, x86_l_110);
x86_l_129b:
	/* 0x129b: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_129e:
	/* 0x129e: je     12b6 <generic_sleepable_offload+0x12b6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x129e, 0x12b6, x86_l_12b6);
x86_l_12a0:
	/* 0x12a0: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_12a3:
	/* 0x12a3: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x12a3, 0x110, x86_l_110);
x86_l_12a9:
	/* 0x12a9: mov    rcx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_12ae:
	/* 0x12ae: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12b1:
	/* 0x12b1: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x12b1, 0x110, x86_l_110);
x86_l_12b6:
	/* 0x12b6: mov    rcx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_12bb:
	/* 0x12bb: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12bd:
	/* 0x12bd: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x12bd, 0x110, x86_l_110);
x86_l_12c2:
	/* 0x12c2: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_12c5:
	/* 0x12c5: je     167a <generic_sleepable_offload+0x167a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12c5, 0x167a, x86_l_167a);
x86_l_12cb:
	/* 0x12cb: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_12ce:
	/* 0x12ce: je     133f <generic_sleepable_offload+0x133f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12ce, 0x133f, x86_l_133f);
x86_l_12d0:
	/* 0x12d0: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x12d0, 0x110, x86_l_110);
x86_l_12d5:
	/* 0x12d5: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_12d8:
	/* 0x12d8: je     1367 <generic_sleepable_offload+0x1367> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12d8, 0x1367, x86_l_1367);
x86_l_12de:
	/* 0x12de: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_12e1:
	/* 0x12e1: je     135a <generic_sleepable_offload+0x135a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12e1, 0x135a, x86_l_135a);
x86_l_12e3:
	/* 0x12e3: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x12e3, 0x110, x86_l_110);
x86_l_12e8:
	/* 0x12e8: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_12eb:
	/* 0x12eb: je     1686 <generic_sleepable_offload+0x1686> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12eb, 0x1686, x86_l_1686);
x86_l_12f1:
	/* 0x12f1: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_12f4:
	/* 0x12f4: je     1385 <generic_sleepable_offload+0x1385> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12f4, 0x1385, x86_l_1385);
x86_l_12fa:
	/* 0x12fa: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x12fa, 0x110, x86_l_110);
x86_l_12ff:
	/* 0x12ff: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1302:
	/* 0x1302: je     1949 <generic_sleepable_offload+0x1949> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1302, 0x1949, x86_l_1949);
x86_l_1308:
	/* 0x1308: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_130b:
	/* 0x130b: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x130b, 0x110, x86_l_110);
x86_l_1311:
	/* 0x1311: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1316:
	/* 0x1316: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1319:
	/* 0x1319: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1319, 0x110, x86_l_110);
x86_l_131e:
	/* 0x131e: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1321:
	/* 0x1321: je     1367 <generic_sleepable_offload+0x1367> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1321, 0x1367, x86_l_1367);
x86_l_1323:
	/* 0x1323: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1326:
	/* 0x1326: je     135a <generic_sleepable_offload+0x135a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1326, 0x135a, x86_l_135a);
x86_l_1328:
	/* 0x1328: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1328, 0x110, x86_l_110);
x86_l_132d:
	/* 0x132d: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1330:
	/* 0x1330: je     167a <generic_sleepable_offload+0x167a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1330, 0x167a, x86_l_167a);
x86_l_1336:
	/* 0x1336: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1339:
	/* 0x1339: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1339, 0x110, x86_l_110);
x86_l_133f:
	/* 0x133f: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1344:
	/* 0x1344: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1347:
	/* 0x1347: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1347, 0x110, x86_l_110);
x86_l_134c:
	/* 0x134c: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_134f:
	/* 0x134f: je     1367 <generic_sleepable_offload+0x1367> */
	X86_SIM_X86_JCC(X86_CC_E, 0x134f, 0x1367, x86_l_1367);
x86_l_1351:
	/* 0x1351: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1354:
	/* 0x1354: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1354, 0x110, x86_l_110);
x86_l_135a:
	/* 0x135a: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_135f:
	/* 0x135f: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1362:
	/* 0x1362: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1362, 0x110, x86_l_110);
x86_l_1367:
	/* 0x1367: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_136c:
	/* 0x136c: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_136e:
	/* 0x136e: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x136e, 0x110, x86_l_110);
x86_l_1373:
	/* 0x1373: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1376:
	/* 0x1376: je     1686 <generic_sleepable_offload+0x1686> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1376, 0x1686, x86_l_1686);
x86_l_137c:
	/* 0x137c: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_137f:
	/* 0x137f: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x137f, 0x110, x86_l_110);
x86_l_1385:
	/* 0x1385: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_138a:
	/* 0x138a: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_138d:
	/* 0x138d: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x138d, 0x110, x86_l_110);
x86_l_1392:
	/* 0x1392: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1395:
	/* 0x1395: je     16ba <generic_sleepable_offload+0x16ba> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1395, 0x16ba, x86_l_16ba);
x86_l_139b:
	/* 0x139b: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_139e:
	/* 0x139e: je     1454 <generic_sleepable_offload+0x1454> */
	X86_SIM_X86_JCC(X86_CC_E, 0x139e, 0x1454, x86_l_1454);
x86_l_13a4:
	/* 0x13a4: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x13a4, 0x110, x86_l_110);
x86_l_13a9:
	/* 0x13a9: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_13ac:
	/* 0x13ac: je     16c1 <generic_sleepable_offload+0x16c1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13ac, 0x16c1, x86_l_16c1);
x86_l_13b2:
	/* 0x13b2: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_13b5:
	/* 0x13b5: je     1485 <generic_sleepable_offload+0x1485> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13b5, 0x1485, x86_l_1485);
x86_l_13bb:
	/* 0x13bb: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x13bb, 0x110, x86_l_110);
x86_l_13c0:
	/* 0x13c0: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_13c3:
	/* 0x13c3: je     16ca <generic_sleepable_offload+0x16ca> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13c3, 0x16ca, x86_l_16ca);
x86_l_13c9:
	/* 0x13c9: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_13cc:
	/* 0x13cc: je     14a0 <generic_sleepable_offload+0x14a0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13cc, 0x14a0, x86_l_14a0);
x86_l_13d2:
	/* 0x13d2: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x13d2, 0x110, x86_l_110);
x86_l_13d7:
	/* 0x13d7: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_13da:
	/* 0x13da: je     16de <generic_sleepable_offload+0x16de> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13da, 0x16de, x86_l_16de);
x86_l_13e0:
	/* 0x13e0: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_13e3:
	/* 0x13e3: je     14bf <generic_sleepable_offload+0x14bf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13e3, 0x14bf, x86_l_14bf);
x86_l_13e9:
	/* 0x13e9: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x13e9, 0x110, x86_l_110);
x86_l_13ee:
	/* 0x13ee: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_13f1:
	/* 0x13f1: je     1971 <generic_sleepable_offload+0x1971> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13f1, 0x1971, x86_l_1971);
x86_l_13f7:
	/* 0x13f7: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_13fa:
	/* 0x13fa: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x13fa, 0x110, x86_l_110);
x86_l_1400:
	/* 0x1400: mov    QWORD PTR [rbx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1403:
	/* 0x1403: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1403, 0x110, x86_l_110);
x86_l_1408:
	/* 0x1408: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_140b:
	/* 0x140b: je     1978 <generic_sleepable_offload+0x1978> */
	X86_SIM_X86_JCC(X86_CC_E, 0x140b, 0x1978, x86_l_1978);
x86_l_1411:
	/* 0x1411: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1414:
	/* 0x1414: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1414, 0x110, x86_l_110);
x86_l_141a:
	/* 0x141a: mov    QWORD PTR [r12],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_141e:
	/* 0x141e: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x141e, 0x110, x86_l_110);
x86_l_1423:
	/* 0x1423: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1426:
	/* 0x1426: je     1981 <generic_sleepable_offload+0x1981> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1426, 0x1981, x86_l_1981);
x86_l_142c:
	/* 0x142c: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_142f:
	/* 0x142f: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x142f, 0x110, x86_l_110);
x86_l_1435:
	/* 0x1435: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_143a:
	/* 0x143a: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_143d:
	/* 0x143d: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x143d, 0x110, x86_l_110);
x86_l_1442:
	/* 0x1442: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1445:
	/* 0x1445: je     16ba <generic_sleepable_offload+0x16ba> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1445, 0x16ba, x86_l_16ba);
x86_l_144b:
	/* 0x144b: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_144e:
	/* 0x144e: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x144e, 0x110, x86_l_110);
x86_l_1454:
	/* 0x1454: mov    QWORD PTR [rbx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1457:
	/* 0x1457: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1457, 0x110, x86_l_110);
x86_l_145c:
	/* 0x145c: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_145f:
	/* 0x145f: je     1a92 <generic_sleepable_offload+0x1a92> */
	X86_SIM_X86_JCC(X86_CC_E, 0x145f, 0x1a92, x86_l_1a92);
x86_l_1465:
	/* 0x1465: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1468:
	/* 0x1468: je     1a85 <generic_sleepable_offload+0x1a85> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1468, 0x1a85, x86_l_1a85);
x86_l_146e:
	/* 0x146e: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x146e, 0x110, x86_l_110);
x86_l_1473:
	/* 0x1473: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1476:
	/* 0x1476: je     16c1 <generic_sleepable_offload+0x16c1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1476, 0x16c1, x86_l_16c1);
x86_l_147c:
	/* 0x147c: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_147f:
	/* 0x147f: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x147f, 0x110, x86_l_110);
x86_l_1485:
	/* 0x1485: mov    QWORD PTR [r12],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1489:
	/* 0x1489: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1489, 0x110, x86_l_110);
x86_l_148e:
	/* 0x148e: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1491:
	/* 0x1491: je     16ca <generic_sleepable_offload+0x16ca> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1491, 0x16ca, x86_l_16ca);
x86_l_1497:
	/* 0x1497: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_149a:
	/* 0x149a: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x149a, 0x110, x86_l_110);
x86_l_14a0:
	/* 0x14a0: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_14a5:
	/* 0x14a5: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14a8:
	/* 0x14a8: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x14a8, 0x110, x86_l_110);
x86_l_14ad:
	/* 0x14ad: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_14b0:
	/* 0x14b0: je     16de <generic_sleepable_offload+0x16de> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14b0, 0x16de, x86_l_16de);
x86_l_14b6:
	/* 0x14b6: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_14b9:
	/* 0x14b9: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x14b9, 0x110, x86_l_110);
x86_l_14bf:
	/* 0x14bf: mov    QWORD PTR [rbp+0x0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14c3:
	/* 0x14c3: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x14c3, 0x110, x86_l_110);
x86_l_14c8:
	/* 0x14c8: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_14cb:
	/* 0x14cb: je     1aef <generic_sleepable_offload+0x1aef> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14cb, 0x1aef, x86_l_1aef);
x86_l_14d1:
	/* 0x14d1: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_14d4:
	/* 0x14d4: je     1ae6 <generic_sleepable_offload+0x1ae6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14d4, 0x1ae6, x86_l_1ae6);
x86_l_14da:
	/* 0x14da: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x14da, 0x110, x86_l_110);
x86_l_14df:
	/* 0x14df: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_14e2:
	/* 0x14e2: je     16e6 <generic_sleepable_offload+0x16e6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14e2, 0x16e6, x86_l_16e6);
x86_l_14e8:
	/* 0x14e8: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_14eb:
	/* 0x14eb: je     1517 <generic_sleepable_offload+0x1517> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14eb, 0x1517, x86_l_1517);
x86_l_14ed:
	/* 0x14ed: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x14ed, 0x110, x86_l_110);
x86_l_14f2:
	/* 0x14f2: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_14f5:
	/* 0x14f5: je     16e6 <generic_sleepable_offload+0x16e6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14f5, 0x16e6, x86_l_16e6);
x86_l_14fb:
	/* 0x14fb: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_14fe:
	/* 0x14fe: je     1517 <generic_sleepable_offload+0x1517> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14fe, 0x1517, x86_l_1517);
x86_l_1500:
	/* 0x1500: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1500, 0x110, x86_l_110);
x86_l_1505:
	/* 0x1505: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1508:
	/* 0x1508: je     1b12 <generic_sleepable_offload+0x1b12> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1508, 0x1b12, x86_l_1b12);
x86_l_150e:
	/* 0x150e: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1511:
	/* 0x1511: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1511, 0x110, x86_l_110);
x86_l_1517:
	/* 0x1517: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_151c:
	/* 0x151c: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_151f:
	/* 0x151f: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x151f, 0x110, x86_l_110);
x86_l_1524:
	/* 0x1524: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1527:
	/* 0x1527: je     16f2 <generic_sleepable_offload+0x16f2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1527, 0x16f2, x86_l_16f2);
x86_l_152d:
	/* 0x152d: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1530:
	/* 0x1530: je     1549 <generic_sleepable_offload+0x1549> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1530, 0x1549, x86_l_1549);
x86_l_1532:
	/* 0x1532: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1532, 0x110, x86_l_110);
x86_l_1537:
	/* 0x1537: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_153a:
	/* 0x153a: je     16f2 <generic_sleepable_offload+0x16f2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x153a, 0x16f2, x86_l_16f2);
x86_l_1540:
	/* 0x1540: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1543:
	/* 0x1543: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1543, 0x110, x86_l_110);
x86_l_1549:
	/* 0x1549: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_154e:
	/* 0x154e: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1551:
	/* 0x1551: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1551, 0x110, x86_l_110);
x86_l_1556:
	/* 0x1556: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1559:
	/* 0x1559: je     173a <generic_sleepable_offload+0x173a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1559, 0x173a, x86_l_173a);
x86_l_155f:
	/* 0x155f: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1562:
	/* 0x1562: je     15eb <generic_sleepable_offload+0x15eb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1562, 0x15eb, x86_l_15eb);
x86_l_1568:
	/* 0x1568: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1568, 0x110, x86_l_110);
x86_l_156d:
	/* 0x156d: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1570:
	/* 0x1570: je     19bd <generic_sleepable_offload+0x19bd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1570, 0x19bd, x86_l_19bd);
x86_l_1576:
	/* 0x1576: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1579:
	/* 0x1579: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1579, 0x110, x86_l_110);
x86_l_157f:
	/* 0x157f: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1584:
	/* 0x1584: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1587:
	/* 0x1587: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1587, 0x110, x86_l_110);
x86_l_158c:
	/* 0x158c: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_158f:
	/* 0x158f: je     19c9 <generic_sleepable_offload+0x19c9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x158f, 0x19c9, x86_l_19c9);
x86_l_1595:
	/* 0x1595: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1598:
	/* 0x1598: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1598, 0x110, x86_l_110);
x86_l_159e:
	/* 0x159e: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_15a3:
	/* 0x15a3: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15a6:
	/* 0x15a6: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x15a6, 0x110, x86_l_110);
x86_l_15ab:
	/* 0x15ab: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_15ae:
	/* 0x15ae: je     1b58 <generic_sleepable_offload+0x1b58> */
	X86_SIM_X86_JCC(X86_CC_E, 0x15ae, 0x1b58, x86_l_1b58);
x86_l_15b4:
	/* 0x15b4: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_15b7:
	/* 0x15b7: je     1b4b <generic_sleepable_offload+0x1b4b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x15b7, 0x1b4b, x86_l_1b4b);
x86_l_15bd:
	/* 0x15bd: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x15bd, 0x110, x86_l_110);
x86_l_15c2:
	/* 0x15c2: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_15c5:
	/* 0x15c5: je     1b7f <generic_sleepable_offload+0x1b7f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x15c5, 0x1b7f, x86_l_1b7f);
x86_l_15cb:
	/* 0x15cb: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_15ce:
	/* 0x15ce: je     1b72 <generic_sleepable_offload+0x1b72> */
	X86_SIM_X86_JCC(X86_CC_E, 0x15ce, 0x1b72, x86_l_1b72);
x86_l_15d4:
	/* 0x15d4: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x15d4, 0x110, x86_l_110);
x86_l_15d9:
	/* 0x15d9: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_15dc:
	/* 0x15dc: je     173a <generic_sleepable_offload+0x173a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x15dc, 0x173a, x86_l_173a);
x86_l_15e2:
	/* 0x15e2: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_15e5:
	/* 0x15e5: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x15e5, 0x110, x86_l_110);
x86_l_15eb:
	/* 0x15eb: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_15f0:
	/* 0x15f0: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_15f3:
	/* 0x15f3: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x15f3, 0x110, x86_l_110);
x86_l_15f8:
	/* 0x15f8: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_15fb:
	/* 0x15fb: je     1746 <generic_sleepable_offload+0x1746> */
	X86_SIM_X86_JCC(X86_CC_E, 0x15fb, 0x1746, x86_l_1746);
x86_l_1601:
	/* 0x1601: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1604:
	/* 0x1604: je     161d <generic_sleepable_offload+0x161d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1604, 0x161d, x86_l_161d);
x86_l_1606:
	/* 0x1606: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1606, 0x110, x86_l_110);
x86_l_160b:
	/* 0x160b: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_160e:
	/* 0x160e: je     1746 <generic_sleepable_offload+0x1746> */
	X86_SIM_X86_JCC(X86_CC_E, 0x160e, 0x1746, x86_l_1746);
x86_l_1614:
	/* 0x1614: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1617:
	/* 0x1617: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1617, 0x110, x86_l_110);
x86_l_161d:
	/* 0x161d: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1622:
	/* 0x1622: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1625:
	/* 0x1625: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1625, 0x110, x86_l_110);
x86_l_162a:
	/* 0x162a: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_162f:
	/* 0x162f: jmp    10e <generic_sleepable_offload+0x10e> */
	X86_SIM_X86_JMP(0x162f, 0x10e, x86_l_10e);
x86_l_1634:
	/* 0x1634: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1639:
	/* 0x1639: jmp    10e <generic_sleepable_offload+0x10e> */
	X86_SIM_X86_JMP(0x1639, 0x10e, x86_l_10e);
x86_l_163e:
	/* 0x163e: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1643:
	/* 0x1643: mov    BYTE PTR [rcx],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1645:
	/* 0x1645: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1645, 0x110, x86_l_110);
x86_l_164a:
	/* 0x164a: mov    rcx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_164f:
	/* 0x164f: mov    BYTE PTR [rcx],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1651:
	/* 0x1651: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1651, 0x110, x86_l_110);
x86_l_1656:
	/* 0x1656: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_165b:
	/* 0x165b: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_165d:
	/* 0x165d: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x165d, 0x110, x86_l_110);
x86_l_1662:
	/* 0x1662: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1667:
	/* 0x1667: mov    BYTE PTR [rcx],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1669:
	/* 0x1669: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1669, 0x110, x86_l_110);
x86_l_166e:
	/* 0x166e: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1673:
	/* 0x1673: mov    BYTE PTR [rcx],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1675:
	/* 0x1675: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1675, 0x110, x86_l_110);
x86_l_167a:
	/* 0x167a: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_167f:
	/* 0x167f: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1681:
	/* 0x1681: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1681, 0x110, x86_l_110);
x86_l_1686:
	/* 0x1686: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_168b:
	/* 0x168b: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_168d:
	/* 0x168d: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x168d, 0x110, x86_l_110);
x86_l_1692:
	/* 0x1692: mov    rcx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1697:
	/* 0x1697: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1699:
	/* 0x1699: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1699, 0x110, x86_l_110);
x86_l_169e:
	/* 0x169e: mov    BYTE PTR [rbx],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16a0:
	/* 0x16a0: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x16a0, 0x110, x86_l_110);
x86_l_16a5:
	/* 0x16a5: mov    BYTE PTR [r12],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16a9:
	/* 0x16a9: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x16a9, 0x110, x86_l_110);
x86_l_16ae:
	/* 0x16ae: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_16b3:
	/* 0x16b3: mov    BYTE PTR [rcx],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16b5:
	/* 0x16b5: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x16b5, 0x110, x86_l_110);
x86_l_16ba:
	/* 0x16ba: mov    DWORD PTR [rbx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16bc:
	/* 0x16bc: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x16bc, 0x110, x86_l_110);
x86_l_16c1:
	/* 0x16c1: mov    DWORD PTR [r12],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16c5:
	/* 0x16c5: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x16c5, 0x110, x86_l_110);
x86_l_16ca:
	/* 0x16ca: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_16cf:
	/* 0x16cf: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16d1:
	/* 0x16d1: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x16d1, 0x110, x86_l_110);
x86_l_16d6:
	/* 0x16d6: mov    BYTE PTR [rbp+0x0],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16d9:
	/* 0x16d9: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x16d9, 0x110, x86_l_110);
x86_l_16de:
	/* 0x16de: mov    DWORD PTR [rbp+0x0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16e1:
	/* 0x16e1: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x16e1, 0x110, x86_l_110);
x86_l_16e6:
	/* 0x16e6: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_16eb:
	/* 0x16eb: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16ed:
	/* 0x16ed: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x16ed, 0x110, x86_l_110);
x86_l_16f2:
	/* 0x16f2: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_16f7:
	/* 0x16f7: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16f9:
	/* 0x16f9: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x16f9, 0x110, x86_l_110);
x86_l_16fe:
	/* 0x16fe: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1703:
	/* 0x1703: mov    BYTE PTR [rcx],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1705:
	/* 0x1705: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1705, 0x110, x86_l_110);
x86_l_170a:
	/* 0x170a: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_170f:
	/* 0x170f: mov    BYTE PTR [rcx],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1711:
	/* 0x1711: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1711, 0x110, x86_l_110);
x86_l_1716:
	/* 0x1716: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_171b:
	/* 0x171b: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_171d:
	/* 0x171d: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x171d, 0x110, x86_l_110);
x86_l_1722:
	/* 0x1722: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1727:
	/* 0x1727: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1729:
	/* 0x1729: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1729, 0x110, x86_l_110);
x86_l_172e:
	/* 0x172e: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1733:
	/* 0x1733: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1735:
	/* 0x1735: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1735, 0x110, x86_l_110);
x86_l_173a:
	/* 0x173a: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_173f:
	/* 0x173f: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1741:
	/* 0x1741: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1741, 0x110, x86_l_110);
x86_l_1746:
	/* 0x1746: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_174b:
	/* 0x174b: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_174d:
	/* 0x174d: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x174d, 0x110, x86_l_110);
x86_l_1752:
	/* 0x1752: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_1755:
	/* 0x1755: jg     19e1 <generic_sleepable_offload+0x19e1> */
	X86_SIM_X86_JCC(X86_CC_G, 0x1755, 0x19e1, x86_l_19e1);
x86_l_175b:
	/* 0x175b: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_175e:
	/* 0x175e: je     18bf <generic_sleepable_offload+0x18bf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x175e, 0x18bf, x86_l_18bf);
x86_l_1764:
	/* 0x1764: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1767:
	/* 0x1767: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1767, 0x110, x86_l_110);
x86_l_176d:
	/* 0x176d: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1772:
	/* 0x1772: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1775:
	/* 0x1775: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1775, 0x110, x86_l_110);
x86_l_177a:
	/* 0x177a: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_177d:
	/* 0x177d: jg     1a00 <generic_sleepable_offload+0x1a00> */
	X86_SIM_X86_JCC(X86_CC_G, 0x177d, 0x1a00, x86_l_1a00);
x86_l_1783:
	/* 0x1783: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1786:
	/* 0x1786: je     18c9 <generic_sleepable_offload+0x18c9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1786, 0x18c9, x86_l_18c9);
x86_l_178c:
	/* 0x178c: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_178f:
	/* 0x178f: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x178f, 0x110, x86_l_110);
x86_l_1795:
	/* 0x1795: mov    rcx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_179a:
	/* 0x179a: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_179d:
	/* 0x179d: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x179d, 0x110, x86_l_110);
x86_l_17a2:
	/* 0x17a2: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_17a5:
	/* 0x17a5: jg     17c6 <generic_sleepable_offload+0x17c6> */
	X86_SIM_X86_JCC(X86_CC_G, 0x17a5, 0x17c6, x86_l_17c6);
x86_l_17a7:
	/* 0x17a7: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_17aa:
	/* 0x17aa: je     109 <generic_sleepable_offload+0x109> */
	X86_SIM_X86_JCC(X86_CC_E, 0x17aa, 0x109, x86_l_109);
x86_l_17b0:
	/* 0x17b0: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_17b3:
	/* 0x17b3: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x17b3, 0x110, x86_l_110);
x86_l_17b9:
	/* 0x17b9: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_17be:
	/* 0x17be: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17c1:
	/* 0x17c1: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x17c1, 0x110, x86_l_110);
x86_l_17c6:
	/* 0x17c6: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_17c9:
	/* 0x17c9: je     18e7 <generic_sleepable_offload+0x18e7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x17c9, 0x18e7, x86_l_18e7);
x86_l_17cf:
	/* 0x17cf: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_17d2:
	/* 0x17d2: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x17d2, 0x110, x86_l_110);
x86_l_17d8:
	/* 0x17d8: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_17dd:
	/* 0x17dd: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_17e0:
	/* 0x17e0: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x17e0, 0x110, x86_l_110);
x86_l_17e5:
	/* 0x17e5: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_17e8:
	/* 0x17e8: jg     1a5d <generic_sleepable_offload+0x1a5d> */
	X86_SIM_X86_JCC(X86_CC_G, 0x17e8, 0x1a5d, x86_l_1a5d);
x86_l_17ee:
	/* 0x17ee: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_17f1:
	/* 0x17f1: je     1bda <generic_sleepable_offload+0x1bda> */
	X86_SIM_X86_JCC(X86_CC_E, 0x17f1, 0x1bda, x86_l_1bda);
x86_l_17f7:
	/* 0x17f7: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_17fa:
	/* 0x17fa: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x17fa, 0x110, x86_l_110);
x86_l_1800:
	/* 0x1800: mov    WORD PTR [rbx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1803:
	/* 0x1803: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1803, 0x110, x86_l_110);
x86_l_1808:
	/* 0x1808: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_180b:
	/* 0x180b: jg     1a77 <generic_sleepable_offload+0x1a77> */
	X86_SIM_X86_JCC(X86_CC_G, 0x180b, 0x1a77, x86_l_1a77);
x86_l_1811:
	/* 0x1811: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1814:
	/* 0x1814: je     182c <generic_sleepable_offload+0x182c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1814, 0x182c, x86_l_182c);
x86_l_1816:
	/* 0x1816: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1819:
	/* 0x1819: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1819, 0x110, x86_l_110);
x86_l_181f:
	/* 0x181f: mov    rcx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1824:
	/* 0x1824: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1827:
	/* 0x1827: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1827, 0x110, x86_l_110);
x86_l_182c:
	/* 0x182c: mov    rcx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1831:
	/* 0x1831: jmp    10e <generic_sleepable_offload+0x10e> */
	X86_SIM_X86_JMP(0x1831, 0x10e, x86_l_10e);
x86_l_1836:
	/* 0x1836: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_1839:
	/* 0x1839: jg     1a9e <generic_sleepable_offload+0x1a9e> */
	X86_SIM_X86_JCC(X86_CC_G, 0x1839, 0x1a9e, x86_l_1a9e);
x86_l_183f:
	/* 0x183f: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1842:
	/* 0x1842: je     1be1 <generic_sleepable_offload+0x1be1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1842, 0x1be1, x86_l_1be1);
x86_l_1848:
	/* 0x1848: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_184b:
	/* 0x184b: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x184b, 0x110, x86_l_110);
x86_l_1851:
	/* 0x1851: mov    WORD PTR [r12],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1856:
	/* 0x1856: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1856, 0x110, x86_l_110);
x86_l_185b:
	/* 0x185b: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_185e:
	/* 0x185e: jg     1ab9 <generic_sleepable_offload+0x1ab9> */
	X86_SIM_X86_JCC(X86_CC_G, 0x185e, 0x1ab9, x86_l_1ab9);
x86_l_1864:
	/* 0x1864: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1867:
	/* 0x1867: je     18f3 <generic_sleepable_offload+0x18f3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1867, 0x18f3, x86_l_18f3);
x86_l_186d:
	/* 0x186d: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1870:
	/* 0x1870: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1870, 0x110, x86_l_110);
x86_l_1876:
	/* 0x1876: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_187b:
	/* 0x187b: mov    WORD PTR [rcx],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_187e:
	/* 0x187e: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x187e, 0x110, x86_l_110);
x86_l_1883:
	/* 0x1883: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_1886:
	/* 0x1886: jg     1ad8 <generic_sleepable_offload+0x1ad8> */
	X86_SIM_X86_JCC(X86_CC_G, 0x1886, 0x1ad8, x86_l_1ad8);
x86_l_188c:
	/* 0x188c: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_188f:
	/* 0x188f: je     18fd <generic_sleepable_offload+0x18fd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x188f, 0x18fd, x86_l_18fd);
x86_l_1891:
	/* 0x1891: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1894:
	/* 0x1894: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1894, 0x110, x86_l_110);
x86_l_189a:
	/* 0x189a: mov    WORD PTR [rbp+0x0],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_189e:
	/* 0x189e: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x189e, 0x110, x86_l_110);
x86_l_18a3:
	/* 0x18a3: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_18a6:
	/* 0x18a6: jg     1af7 <generic_sleepable_offload+0x1af7> */
	X86_SIM_X86_JCC(X86_CC_G, 0x18a6, 0x1af7, x86_l_1af7);
x86_l_18ac:
	/* 0x18ac: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_18af:
	/* 0x18af: jne    10a3 <generic_sleepable_offload+0x10a3> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x18af, 0x10a3, x86_l_10a3);
x86_l_18b5:
	/* 0x18b5: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_18ba:
	/* 0x18ba: jmp    10e <generic_sleepable_offload+0x10e> */
	X86_SIM_X86_JMP(0x18ba, 0x10e, x86_l_10e);
x86_l_18bf:
	/* 0x18bf: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_18c4:
	/* 0x18c4: jmp    10e <generic_sleepable_offload+0x10e> */
	X86_SIM_X86_JMP(0x18c4, 0x10e, x86_l_10e);
x86_l_18c9:
	/* 0x18c9: mov    rcx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_18ce:
	/* 0x18ce: jmp    10e <generic_sleepable_offload+0x10e> */
	X86_SIM_X86_JMP(0x18ce, 0x10e, x86_l_10e);
x86_l_18d3:
	/* 0x18d3: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_18d8:
	/* 0x18d8: jmp    10e <generic_sleepable_offload+0x10e> */
	X86_SIM_X86_JMP(0x18d8, 0x10e, x86_l_10e);
x86_l_18dd:
	/* 0x18dd: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_18e2:
	/* 0x18e2: jmp    10e <generic_sleepable_offload+0x10e> */
	X86_SIM_X86_JMP(0x18e2, 0x10e, x86_l_10e);
x86_l_18e7:
	/* 0x18e7: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_18ec:
	/* 0x18ec: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_18ee:
	/* 0x18ee: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x18ee, 0x110, x86_l_110);
x86_l_18f3:
	/* 0x18f3: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_18f8:
	/* 0x18f8: jmp    10e <generic_sleepable_offload+0x10e> */
	X86_SIM_X86_JMP(0x18f8, 0x10e, x86_l_10e);
x86_l_18fd:
	/* 0x18fd: mov    BYTE PTR [rbp+0x0],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1900:
	/* 0x1900: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1900, 0x110, x86_l_110);
x86_l_1905:
	/* 0x1905: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_190a:
	/* 0x190a: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_190c:
	/* 0x190c: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x190c, 0x110, x86_l_110);
x86_l_1911:
	/* 0x1911: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1916:
	/* 0x1916: jmp    10e <generic_sleepable_offload+0x10e> */
	X86_SIM_X86_JMP(0x1916, 0x10e, x86_l_10e);
x86_l_191b:
	/* 0x191b: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1920:
	/* 0x1920: jmp    10e <generic_sleepable_offload+0x10e> */
	X86_SIM_X86_JMP(0x1920, 0x10e, x86_l_10e);
x86_l_1925:
	/* 0x1925: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_192a:
	/* 0x192a: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_192c:
	/* 0x192c: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x192c, 0x110, x86_l_110);
x86_l_1931:
	/* 0x1931: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1936:
	/* 0x1936: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1938:
	/* 0x1938: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1938, 0x110, x86_l_110);
x86_l_193d:
	/* 0x193d: mov    rcx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_1942:
	/* 0x1942: mov    BYTE PTR [rcx],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1944:
	/* 0x1944: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1944, 0x110, x86_l_110);
x86_l_1949:
	/* 0x1949: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_194e:
	/* 0x194e: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1950:
	/* 0x1950: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1950, 0x110, x86_l_110);
x86_l_1955:
	/* 0x1955: mov    BYTE PTR [rbx],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1957:
	/* 0x1957: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1957, 0x110, x86_l_110);
x86_l_195c:
	/* 0x195c: mov    BYTE PTR [r12],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1960:
	/* 0x1960: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1960, 0x110, x86_l_110);
x86_l_1965:
	/* 0x1965: mov    rcx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_196a:
	/* 0x196a: mov    BYTE PTR [rcx],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_196c:
	/* 0x196c: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x196c, 0x110, x86_l_110);
x86_l_1971:
	/* 0x1971: mov    DWORD PTR [rbx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1973:
	/* 0x1973: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1973, 0x110, x86_l_110);
x86_l_1978:
	/* 0x1978: mov    DWORD PTR [r12],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_197c:
	/* 0x197c: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x197c, 0x110, x86_l_110);
x86_l_1981:
	/* 0x1981: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1986:
	/* 0x1986: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1988:
	/* 0x1988: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1988, 0x110, x86_l_110);
x86_l_198d:
	/* 0x198d: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1992:
	/* 0x1992: mov    BYTE PTR [rcx],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1994:
	/* 0x1994: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1994, 0x110, x86_l_110);
x86_l_1999:
	/* 0x1999: mov    rcx,QWORD PTR [rsp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_199e:
	/* 0x199e: mov    BYTE PTR [rcx],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19a0:
	/* 0x19a0: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x19a0, 0x110, x86_l_110);
x86_l_19a5:
	/* 0x19a5: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19aa:
	/* 0x19aa: mov    BYTE PTR [rcx],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19ac:
	/* 0x19ac: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x19ac, 0x110, x86_l_110);
x86_l_19b1:
	/* 0x19b1: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_19b6:
	/* 0x19b6: mov    BYTE PTR [rcx],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19b8:
	/* 0x19b8: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x19b8, 0x110, x86_l_110);
x86_l_19bd:
	/* 0x19bd: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_19c2:
	/* 0x19c2: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19c4:
	/* 0x19c4: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x19c4, 0x110, x86_l_110);
x86_l_19c9:
	/* 0x19c9: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_19ce:
	/* 0x19ce: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19d0:
	/* 0x19d0: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x19d0, 0x110, x86_l_110);
x86_l_19d5:
	/* 0x19d5: mov    rcx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_19da:
	/* 0x19da: mov    BYTE PTR [rcx],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19dc:
	/* 0x19dc: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x19dc, 0x110, x86_l_110);
x86_l_19e1:
	/* 0x19e1: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_19e4:
	/* 0x19e4: je     1baa <generic_sleepable_offload+0x1baa> */
	X86_SIM_X86_JCC(X86_CC_E, 0x19e4, 0x1baa, x86_l_1baa);
x86_l_19ea:
	/* 0x19ea: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_19ed:
	/* 0x19ed: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x19ed, 0x110, x86_l_110);
x86_l_19f3:
	/* 0x19f3: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_19f8:
	/* 0x19f8: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_19fb:
	/* 0x19fb: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x19fb, 0x110, x86_l_110);
x86_l_1a00:
	/* 0x1a00: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1a03:
	/* 0x1a03: je     1bb6 <generic_sleepable_offload+0x1bb6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a03, 0x1bb6, x86_l_1bb6);
x86_l_1a09:
	/* 0x1a09: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1a0c:
	/* 0x1a0c: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1a0c, 0x110, x86_l_110);
x86_l_1a12:
	/* 0x1a12: mov    rcx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1a17:
	/* 0x1a17: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a1a:
	/* 0x1a1a: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1a1a, 0x110, x86_l_110);
x86_l_1a1f:
	/* 0x1a1f: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1a22:
	/* 0x1a22: je     1bc2 <generic_sleepable_offload+0x1bc2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a22, 0x1bc2, x86_l_1bc2);
x86_l_1a28:
	/* 0x1a28: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1a2b:
	/* 0x1a2b: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1a2b, 0x110, x86_l_110);
x86_l_1a31:
	/* 0x1a31: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1a36:
	/* 0x1a36: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a39:
	/* 0x1a39: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1a39, 0x110, x86_l_110);
x86_l_1a3e:
	/* 0x1a3e: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1a41:
	/* 0x1a41: je     1bce <generic_sleepable_offload+0x1bce> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a41, 0x1bce, x86_l_1bce);
x86_l_1a47:
	/* 0x1a47: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1a4a:
	/* 0x1a4a: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1a4a, 0x110, x86_l_110);
x86_l_1a50:
	/* 0x1a50: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1a55:
	/* 0x1a55: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a58:
	/* 0x1a58: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1a58, 0x110, x86_l_110);
x86_l_1a5d:
	/* 0x1a5d: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1a60:
	/* 0x1a60: je     1bea <generic_sleepable_offload+0x1bea> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a60, 0x1bea, x86_l_1bea);
x86_l_1a66:
	/* 0x1a66: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1a69:
	/* 0x1a69: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1a69, 0x110, x86_l_110);
x86_l_1a6f:
	/* 0x1a6f: mov    QWORD PTR [rbx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a72:
	/* 0x1a72: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1a72, 0x110, x86_l_110);
x86_l_1a77:
	/* 0x1a77: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1a7a:
	/* 0x1a7a: je     1a92 <generic_sleepable_offload+0x1a92> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a7a, 0x1a92, x86_l_1a92);
x86_l_1a7c:
	/* 0x1a7c: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1a7f:
	/* 0x1a7f: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1a7f, 0x110, x86_l_110);
x86_l_1a85:
	/* 0x1a85: mov    rcx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1a8a:
	/* 0x1a8a: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a8d:
	/* 0x1a8d: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1a8d, 0x110, x86_l_110);
x86_l_1a92:
	/* 0x1a92: mov    rcx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_1a97:
	/* 0x1a97: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1a99:
	/* 0x1a99: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1a99, 0x110, x86_l_110);
x86_l_1a9e:
	/* 0x1a9e: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1aa1:
	/* 0x1aa1: je     1bf1 <generic_sleepable_offload+0x1bf1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1aa1, 0x1bf1, x86_l_1bf1);
x86_l_1aa7:
	/* 0x1aa7: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1aaa:
	/* 0x1aaa: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1aaa, 0x110, x86_l_110);
x86_l_1ab0:
	/* 0x1ab0: mov    QWORD PTR [r12],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ab4:
	/* 0x1ab4: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1ab4, 0x110, x86_l_110);
x86_l_1ab9:
	/* 0x1ab9: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1abc:
	/* 0x1abc: je     1bfa <generic_sleepable_offload+0x1bfa> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1abc, 0x1bfa, x86_l_1bfa);
x86_l_1ac2:
	/* 0x1ac2: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1ac5:
	/* 0x1ac5: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1ac5, 0x110, x86_l_110);
x86_l_1acb:
	/* 0x1acb: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1ad0:
	/* 0x1ad0: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ad3:
	/* 0x1ad3: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1ad3, 0x110, x86_l_110);
x86_l_1ad8:
	/* 0x1ad8: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1adb:
	/* 0x1adb: je     1aef <generic_sleepable_offload+0x1aef> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1adb, 0x1aef, x86_l_1aef);
x86_l_1add:
	/* 0x1add: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1ae0:
	/* 0x1ae0: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1ae0, 0x110, x86_l_110);
x86_l_1ae6:
	/* 0x1ae6: mov    QWORD PTR [rbp+0x0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1aea:
	/* 0x1aea: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1aea, 0x110, x86_l_110);
x86_l_1aef:
	/* 0x1aef: mov    DWORD PTR [rbp+0x0],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1af2:
	/* 0x1af2: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1af2, 0x110, x86_l_110);
x86_l_1af7:
	/* 0x1af7: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1afa:
	/* 0x1afa: je     1b12 <generic_sleepable_offload+0x1b12> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1afa, 0x1b12, x86_l_1b12);
x86_l_1afc:
	/* 0x1afc: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1aff:
	/* 0x1aff: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1aff, 0x110, x86_l_110);
x86_l_1b05:
	/* 0x1b05: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1b0a:
	/* 0x1b0a: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b0d:
	/* 0x1b0d: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1b0d, 0x110, x86_l_110);
x86_l_1b12:
	/* 0x1b12: mov    rcx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1b17:
	/* 0x1b17: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b19:
	/* 0x1b19: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1b19, 0x110, x86_l_110);
x86_l_1b1e:
	/* 0x1b1e: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1b21:
	/* 0x1b21: je     1c06 <generic_sleepable_offload+0x1c06> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1b21, 0x1c06, x86_l_1c06);
x86_l_1b27:
	/* 0x1b27: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1b2a:
	/* 0x1b2a: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1b2a, 0x110, x86_l_110);
x86_l_1b30:
	/* 0x1b30: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1b35:
	/* 0x1b35: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b38:
	/* 0x1b38: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1b38, 0x110, x86_l_110);
x86_l_1b3d:
	/* 0x1b3d: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1b40:
	/* 0x1b40: je     1b58 <generic_sleepable_offload+0x1b58> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1b40, 0x1b58, x86_l_1b58);
x86_l_1b42:
	/* 0x1b42: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1b45:
	/* 0x1b45: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1b45, 0x110, x86_l_110);
x86_l_1b4b:
	/* 0x1b4b: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b50:
	/* 0x1b50: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b53:
	/* 0x1b53: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1b53, 0x110, x86_l_110);
x86_l_1b58:
	/* 0x1b58: mov    rcx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_1b5d:
	/* 0x1b5d: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b5f:
	/* 0x1b5f: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1b5f, 0x110, x86_l_110);
x86_l_1b64:
	/* 0x1b64: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1b67:
	/* 0x1b67: je     1b7f <generic_sleepable_offload+0x1b7f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1b67, 0x1b7f, x86_l_1b7f);
x86_l_1b69:
	/* 0x1b69: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1b6c:
	/* 0x1b6c: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1b6c, 0x110, x86_l_110);
x86_l_1b72:
	/* 0x1b72: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1b77:
	/* 0x1b77: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b7a:
	/* 0x1b7a: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1b7a, 0x110, x86_l_110);
x86_l_1b7f:
	/* 0x1b7f: mov    rcx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1b84:
	/* 0x1b84: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1b86:
	/* 0x1b86: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1b86, 0x110, x86_l_110);
x86_l_1b8b:
	/* 0x1b8b: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_1b8e:
	/* 0x1b8e: je     1c12 <generic_sleepable_offload+0x1c12> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1b8e, 0x1c12, x86_l_1c12);
x86_l_1b94:
	/* 0x1b94: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1b97:
	/* 0x1b97: jne    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1b97, 0x110, x86_l_110);
x86_l_1b9d:
	/* 0x1b9d: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1ba2:
	/* 0x1ba2: mov    QWORD PTR [rcx],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1ba5:
	/* 0x1ba5: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1ba5, 0x110, x86_l_110);
x86_l_1baa:
	/* 0x1baa: mov    rcx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1baf:
	/* 0x1baf: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bb1:
	/* 0x1bb1: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1bb1, 0x110, x86_l_110);
x86_l_1bb6:
	/* 0x1bb6: mov    rcx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_1bbb:
	/* 0x1bbb: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bbd:
	/* 0x1bbd: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1bbd, 0x110, x86_l_110);
x86_l_1bc2:
	/* 0x1bc2: mov    rcx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_1bc7:
	/* 0x1bc7: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bc9:
	/* 0x1bc9: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1bc9, 0x110, x86_l_110);
x86_l_1bce:
	/* 0x1bce: mov    rcx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1bd3:
	/* 0x1bd3: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bd5:
	/* 0x1bd5: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1bd5, 0x110, x86_l_110);
x86_l_1bda:
	/* 0x1bda: mov    BYTE PTR [rbx],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bdc:
	/* 0x1bdc: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1bdc, 0x110, x86_l_110);
x86_l_1be1:
	/* 0x1be1: mov    BYTE PTR [r12],al */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1be5:
	/* 0x1be5: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1be5, 0x110, x86_l_110);
x86_l_1bea:
	/* 0x1bea: mov    DWORD PTR [rbx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bec:
	/* 0x1bec: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1bec, 0x110, x86_l_110);
x86_l_1bf1:
	/* 0x1bf1: mov    DWORD PTR [r12],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1bf5:
	/* 0x1bf5: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1bf5, 0x110, x86_l_110);
x86_l_1bfa:
	/* 0x1bfa: mov    rcx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_1bff:
	/* 0x1bff: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c01:
	/* 0x1c01: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1c01, 0x110, x86_l_110);
x86_l_1c06:
	/* 0x1c06: mov    rcx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1c0b:
	/* 0x1c0b: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c0d:
	/* 0x1c0d: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1c0d, 0x110, x86_l_110);
x86_l_1c12:
	/* 0x1c12: mov    rcx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1c17:
	/* 0x1c17: mov    DWORD PTR [rcx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RCX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1c19:
	/* 0x1c19: jmp    110 <generic_sleepable_offload+0x110> */
	X86_SIM_X86_JMP(0x1c19, 0x110, x86_l_110);
x86_l_1c1e:
	/* 0x1c1e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1c20:
	/* 0x1c20: add    rsp,0x88 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 136ULL);
x86_l_1c27:
	/* 0x1c27: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_1c29:
	/* 0x1c29: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_1c2a:
	/* 0x1c2a: jmp    1c2f <generic_sleepable_offload+0x1c2f> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_1c2f:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
