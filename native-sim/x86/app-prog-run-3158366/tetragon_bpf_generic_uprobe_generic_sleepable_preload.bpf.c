extern char config_map;
extern char heap_ro_zero;
extern char sleepable_preload;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_generic_uprobe_generic_sleepable_preload_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: sub    rsp,0x98 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 152ULL);
x86_l_a:
	/* 0xa: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: mov    DWORD PTR [rsp+0x94],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_18:
	/* 0x18: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_1f:
	/* 0x1f: lea    rsi,[rsp+0x94] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_27:
	/* 0x27: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2c:
	/* 0x2c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e:
	/* 0x2e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_31:
	/* 0x31: je     10a <generic_sleepable_preload+0x10a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x31, 0x10a, x86_l_10a);
x86_l_37:
	/* 0x37: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_3a:
	/* 0x3a: lea    rax,[r14+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_41:
	/* 0x41: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_46:
	/* 0x46: lea    rax,[r14+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_4d:
	/* 0x4d: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_52:
	/* 0x52: lea    rax,[r14+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_56:
	/* 0x56: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_5b:
	/* 0x5b: lea    rax,[r14+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_5f:
	/* 0x5f: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_64:
	/* 0x64: lea    rax,[r14+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_68:
	/* 0x68: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_6d:
	/* 0x6d: lea    r12,[r14+0x58] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_71:
	/* 0x71: lea    rax,[r14+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_75:
	/* 0x75: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_7d:
	/* 0x7d: lea    r13,[r14+0x48] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_81:
	/* 0x81: lea    rax,[r14+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_85:
	/* 0x85: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_8d:
	/* 0x8d: lea    rax,[r14+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_91:
	/* 0x91: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_96:
	/* 0x96: lea    rax,[r14+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9a:
	/* 0x9a: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_9f:
	/* 0x9f: lea    rax,[r14+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a3:
	/* 0xa3: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_a8:
	/* 0xa8: lea    rax,[r14+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ac:
	/* 0xac: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_b1:
	/* 0xb1: lea    rax,[r14+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_b5:
	/* 0xb5: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_ba:
	/* 0xba: lea    rax,[r14+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_be:
	/* 0xbe: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_c3:
	/* 0xc3: lea    rax,[r14+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c7:
	/* 0xc7: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_cc:
	/* 0xcc: mov    eax,DWORD PTR [rbx+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_cf:
	/* 0xcf: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_d4:
	/* 0xd4: jne    11b <generic_sleepable_preload+0x11b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xd4, 0x11b, x86_l_11b);
x86_l_d6:
	/* 0xd6: mov    eax,DWORD PTR [rbx+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_d9:
	/* 0xd9: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_de:
	/* 0xde: jne    153 <generic_sleepable_preload+0x153> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xde, 0x153, x86_l_153);
x86_l_e0:
	/* 0xe0: mov    eax,DWORD PTR [rbx+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_e3:
	/* 0xe3: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_e8:
	/* 0xe8: jne    18b <generic_sleepable_preload+0x18b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe8, 0x18b, x86_l_18b);
x86_l_ee:
	/* 0xee: mov    eax,DWORD PTR [rbx+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_f1:
	/* 0xf1: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_f6:
	/* 0xf6: jne    1c3 <generic_sleepable_preload+0x1c3> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf6, 0x1c3, x86_l_1c3);
x86_l_fc:
	/* 0xfc: mov    eax,DWORD PTR [rbx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_ff:
	/* 0xff: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_104:
	/* 0x104: jne    1fb <generic_sleepable_preload+0x1fb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x104, 0x1fb, x86_l_1fb);
x86_l_10a:
	/* 0x10a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10c:
	/* 0x10c: add    rsp,0x98 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 152ULL);
x86_l_113:
	/* 0x113: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_115:
	/* 0x115: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_116:
	/* 0x116: jmp    1085 <generic_sleepable_preload+0x1085> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_11b:
	/* 0x11b: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_11d:
	/* 0x11d: js     233 <generic_sleepable_preload+0x233> */
	X86_SIM_X86_JCC(X86_CC_S, 0x11d, 0x233, x86_l_233);
x86_l_123:
	/* 0x123: mov    eax,DWORD PTR [rbx+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_126:
	/* 0x126: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_129:
	/* 0x129: jle    4f8 <generic_sleepable_preload+0x4f8> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x129, 0x4f8, x86_l_4f8);
x86_l_12f:
	/* 0x12f: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_132:
	/* 0x132: je     728 <generic_sleepable_preload+0x728> */
	X86_SIM_X86_JCC(X86_CC_E, 0x132, 0x728, x86_l_728);
x86_l_138:
	/* 0x138: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_13b:
	/* 0x13b: je     757 <generic_sleepable_preload+0x757> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13b, 0x757, x86_l_757);
x86_l_141:
	/* 0x141: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_144:
	/* 0x144: jne    78d <generic_sleepable_preload+0x78d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x144, 0x78d, x86_l_78d);
x86_l_14a:
	/* 0x14a: mov    rax,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14e:
	/* 0x14e: jmp    789 <generic_sleepable_preload+0x789> */
	X86_SIM_X86_JMP(0x14e, 0x789, x86_l_789);
x86_l_153:
	/* 0x153: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_155:
	/* 0x155: js     293 <generic_sleepable_preload+0x293> */
	X86_SIM_X86_JCC(X86_CC_S, 0x155, 0x293, x86_l_293);
x86_l_15b:
	/* 0x15b: mov    eax,DWORD PTR [rbx+0x44] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68ULL);
x86_l_15e:
	/* 0x15e: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_161:
	/* 0x161: jle    513 <generic_sleepable_preload+0x513> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x161, 0x513, x86_l_513);
x86_l_167:
	/* 0x167: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_16a:
	/* 0x16a: je     72f <generic_sleepable_preload+0x72f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x16a, 0x72f, x86_l_72f);
x86_l_170:
	/* 0x170: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_173:
	/* 0x173: je     75d <generic_sleepable_preload+0x75d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x173, 0x75d, x86_l_75d);
x86_l_179:
	/* 0x179: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_17c:
	/* 0x17c: jne    824 <generic_sleepable_preload+0x824> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x17c, 0x824, x86_l_824);
x86_l_182:
	/* 0x182: mov    rax,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_186:
	/* 0x186: jmp    820 <generic_sleepable_preload+0x820> */
	X86_SIM_X86_JMP(0x186, 0x820, x86_l_820);
x86_l_18b:
	/* 0x18b: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_18d:
	/* 0x18d: js     2f3 <generic_sleepable_preload+0x2f3> */
	X86_SIM_X86_JCC(X86_CC_S, 0x18d, 0x2f3, x86_l_2f3);
x86_l_193:
	/* 0x193: mov    eax,DWORD PTR [rbx+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_196:
	/* 0x196: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_199:
	/* 0x199: jle    52e <generic_sleepable_preload+0x52e> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x199, 0x52e, x86_l_52e);
x86_l_19f:
	/* 0x19f: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1a2:
	/* 0x1a2: je     739 <generic_sleepable_preload+0x739> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1a2, 0x739, x86_l_739);
x86_l_1a8:
	/* 0x1a8: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1ab:
	/* 0x1ab: je     766 <generic_sleepable_preload+0x766> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1ab, 0x766, x86_l_766);
x86_l_1b1:
	/* 0x1b1: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1b4:
	/* 0x1b4: jne    8bb <generic_sleepable_preload+0x8bb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1b4, 0x8bb, x86_l_8bb);
x86_l_1ba:
	/* 0x1ba: mov    rax,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1be:
	/* 0x1be: jmp    8b7 <generic_sleepable_preload+0x8b7> */
	X86_SIM_X86_JMP(0x1be, 0x8b7, x86_l_8b7);
x86_l_1c3:
	/* 0x1c3: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1c5:
	/* 0x1c5: js     353 <generic_sleepable_preload+0x353> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1c5, 0x353, x86_l_353);
x86_l_1cb:
	/* 0x1cb: mov    eax,DWORD PTR [rbx+0x4c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 76ULL);
x86_l_1ce:
	/* 0x1ce: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d1:
	/* 0x1d1: jle    549 <generic_sleepable_preload+0x549> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x1d1, 0x549, x86_l_549);
x86_l_1d7:
	/* 0x1d7: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1da:
	/* 0x1da: je     743 <generic_sleepable_preload+0x743> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1da, 0x743, x86_l_743);
x86_l_1e0:
	/* 0x1e0: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_1e3:
	/* 0x1e3: je     76f <generic_sleepable_preload+0x76f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1e3, 0x76f, x86_l_76f);
x86_l_1e9:
	/* 0x1e9: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1ec:
	/* 0x1ec: jne    952 <generic_sleepable_preload+0x952> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1ec, 0x952, x86_l_952);
x86_l_1f2:
	/* 0x1f2: mov    rax,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1f6:
	/* 0x1f6: jmp    94e <generic_sleepable_preload+0x94e> */
	X86_SIM_X86_JMP(0x1f6, 0x94e, x86_l_94e);
x86_l_1fb:
	/* 0x1fb: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1fd:
	/* 0x1fd: js     3b3 <generic_sleepable_preload+0x3b3> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1fd, 0x3b3, x86_l_3b3);
x86_l_203:
	/* 0x203: mov    eax,DWORD PTR [rbx+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_206:
	/* 0x206: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_209:
	/* 0x209: jle    564 <generic_sleepable_preload+0x564> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x209, 0x564, x86_l_564);
x86_l_20f:
	/* 0x20f: cmp    eax,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_212:
	/* 0x212: je     74d <generic_sleepable_preload+0x74d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x212, 0x74d, x86_l_74d);
x86_l_218:
	/* 0x218: cmp    eax,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_21b:
	/* 0x21b: je     778 <generic_sleepable_preload+0x778> */
	X86_SIM_X86_JCC(X86_CC_E, 0x21b, 0x778, x86_l_778);
x86_l_221:
	/* 0x221: cmp    eax,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_224:
	/* 0x224: jne    9e9 <generic_sleepable_preload+0x9e9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x224, 0x9e9, x86_l_9e9);
x86_l_22a:
	/* 0x22a: mov    rax,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_22e:
	/* 0x22e: jmp    9e5 <generic_sleepable_preload+0x9e5> */
	X86_SIM_X86_JMP(0x22e, 0x9e5, x86_l_9e5);
x86_l_233:
	/* 0x233: movzx  eax,BYTE PTR [rbx+0x2c2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 706ULL);
x86_l_23a:
	/* 0x23a: movzx  ecx,WORD PTR [rbx+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 704ULL);
x86_l_241:
	/* 0x241: rorx   ecx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_247:
	/* 0x247: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_249:
	/* 0x249: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_24c:
	/* 0x24c: jle    414 <generic_sleepable_preload+0x414> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x24c, 0x414, x86_l_414);
x86_l_252:
	/* 0x252: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_255:
	/* 0x255: jle    57f <generic_sleepable_preload+0x57f> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x255, 0x57f, x86_l_57f);
x86_l_25b:
	/* 0x25b: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_25e:
	/* 0x25e: jle    c7e <generic_sleepable_preload+0xc7e> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x25e, 0xc7e, x86_l_c7e);
x86_l_264:
	/* 0x264: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_269:
	/* 0x269: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_26c:
	/* 0x26c: je     c92 <generic_sleepable_preload+0xc92> */
	X86_SIM_X86_JCC(X86_CC_E, 0x26c, 0xc92, x86_l_c92);
x86_l_272:
	/* 0x272: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_277:
	/* 0x277: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_27a:
	/* 0x27a: je     c92 <generic_sleepable_preload+0xc92> */
	X86_SIM_X86_JCC(X86_CC_E, 0x27a, 0xc92, x86_l_c92);
x86_l_280:
	/* 0x280: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_283:
	/* 0x283: jne    ca5 <generic_sleepable_preload+0xca5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x283, 0xca5, x86_l_ca5);
x86_l_289:
	/* 0x289: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_28e:
	/* 0x28e: jmp    c92 <generic_sleepable_preload+0xc92> */
	X86_SIM_X86_JMP(0x28e, 0xc92, x86_l_c92);
x86_l_293:
	/* 0x293: movzx  eax,BYTE PTR [rbx+0x2c6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 710ULL);
x86_l_29a:
	/* 0x29a: movzx  ecx,WORD PTR [rbx+0x2c4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 708ULL);
x86_l_2a1:
	/* 0x2a1: rorx   ecx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_2a7:
	/* 0x2a7: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a9:
	/* 0x2a9: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_2ac:
	/* 0x2ac: jle    444 <generic_sleepable_preload+0x444> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x2ac, 0x444, x86_l_444);
x86_l_2b2:
	/* 0x2b2: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_2b5:
	/* 0x2b5: jle    5aa <generic_sleepable_preload+0x5aa> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x2b5, 0x5aa, x86_l_5aa);
x86_l_2bb:
	/* 0x2bb: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_2be:
	/* 0x2be: jle    d46 <generic_sleepable_preload+0xd46> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x2be, 0xd46, x86_l_d46);
x86_l_2c4:
	/* 0x2c4: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_2c9:
	/* 0x2c9: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_2cc:
	/* 0x2cc: je     e63 <generic_sleepable_preload+0xe63> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2cc, 0xe63, x86_l_e63);
x86_l_2d2:
	/* 0x2d2: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_2d7:
	/* 0x2d7: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_2da:
	/* 0x2da: je     e63 <generic_sleepable_preload+0xe63> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2da, 0xe63, x86_l_e63);
x86_l_2e0:
	/* 0x2e0: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_2e5:
	/* 0x2e5: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_2e8:
	/* 0x2e8: je     e63 <generic_sleepable_preload+0xe63> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2e8, 0xe63, x86_l_e63);
x86_l_2ee:
	/* 0x2ee: jmp    e76 <generic_sleepable_preload+0xe76> */
	X86_SIM_X86_JMP(0x2ee, 0xe76, x86_l_e76);
x86_l_2f3:
	/* 0x2f3: movzx  eax,BYTE PTR [rbx+0x2ca] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 714ULL);
x86_l_2fa:
	/* 0x2fa: movzx  ecx,WORD PTR [rbx+0x2c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 712ULL);
x86_l_301:
	/* 0x301: rorx   ecx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_307:
	/* 0x307: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_309:
	/* 0x309: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_30c:
	/* 0x30c: jle    471 <generic_sleepable_preload+0x471> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x30c, 0x471, x86_l_471);
x86_l_312:
	/* 0x312: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_315:
	/* 0x315: jle    5d5 <generic_sleepable_preload+0x5d5> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x315, 0x5d5, x86_l_5d5);
x86_l_31b:
	/* 0x31b: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_31e:
	/* 0x31e: jle    d67 <generic_sleepable_preload+0xd67> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x31e, 0xd67, x86_l_d67);
x86_l_324:
	/* 0x324: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_329:
	/* 0x329: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_32c:
	/* 0x32c: je     f1a <generic_sleepable_preload+0xf1a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x32c, 0xf1a, x86_l_f1a);
x86_l_332:
	/* 0x332: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_337:
	/* 0x337: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_33a:
	/* 0x33a: je     f1a <generic_sleepable_preload+0xf1a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x33a, 0xf1a, x86_l_f1a);
x86_l_340:
	/* 0x340: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_345:
	/* 0x345: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_348:
	/* 0x348: je     f1a <generic_sleepable_preload+0xf1a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x348, 0xf1a, x86_l_f1a);
x86_l_34e:
	/* 0x34e: jmp    f2d <generic_sleepable_preload+0xf2d> */
	X86_SIM_X86_JMP(0x34e, 0xf2d, x86_l_f2d);
x86_l_353:
	/* 0x353: movzx  eax,BYTE PTR [rbx+0x2ce] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 718ULL);
x86_l_35a:
	/* 0x35a: movzx  ecx,WORD PTR [rbx+0x2cc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 716ULL);
x86_l_361:
	/* 0x361: rorx   ecx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_367:
	/* 0x367: xor    ebp,ebp */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_RBP, X86_WIDTH_32, X86_ALU_XOR);
x86_l_369:
	/* 0x369: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_36c:
	/* 0x36c: jle    49e <generic_sleepable_preload+0x49e> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x36c, 0x49e, x86_l_49e);
x86_l_372:
	/* 0x372: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_375:
	/* 0x375: jle    600 <generic_sleepable_preload+0x600> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x375, 0x600, x86_l_600);
x86_l_37b:
	/* 0x37b: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_37e:
	/* 0x37e: jle    d88 <generic_sleepable_preload+0xd88> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x37e, 0xd88, x86_l_d88);
x86_l_384:
	/* 0x384: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_389:
	/* 0x389: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_38c:
	/* 0x38c: je     fd1 <generic_sleepable_preload+0xfd1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x38c, 0xfd1, x86_l_fd1);
x86_l_392:
	/* 0x392: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_397:
	/* 0x397: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_39a:
	/* 0x39a: je     fd1 <generic_sleepable_preload+0xfd1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x39a, 0xfd1, x86_l_fd1);
x86_l_3a0:
	/* 0x3a0: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_3a5:
	/* 0x3a5: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_3a8:
	/* 0x3a8: je     fd1 <generic_sleepable_preload+0xfd1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3a8, 0xfd1, x86_l_fd1);
x86_l_3ae:
	/* 0x3ae: jmp    fe4 <generic_sleepable_preload+0xfe4> */
	X86_SIM_X86_JMP(0x3ae, 0xfe4, x86_l_fe4);
x86_l_3b3:
	/* 0x3b3: movzx  eax,BYTE PTR [rbx+0x2d2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 722ULL);
x86_l_3ba:
	/* 0x3ba: movzx  ecx,WORD PTR [rbx+0x2d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 720ULL);
x86_l_3c1:
	/* 0x3c1: rorx   ecx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_3c7:
	/* 0x3c7: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3ca:
	/* 0x3ca: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_3cd:
	/* 0x3cd: jle    4cb <generic_sleepable_preload+0x4cb> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x3cd, 0x4cb, x86_l_4cb);
x86_l_3d3:
	/* 0x3d3: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_3d6:
	/* 0x3d6: jle    62b <generic_sleepable_preload+0x62b> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x3d6, 0x62b, x86_l_62b);
x86_l_3dc:
	/* 0x3dc: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_3df:
	/* 0x3df: jle    da9 <generic_sleepable_preload+0xda9> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x3df, 0xda9, x86_l_da9);
x86_l_3e5:
	/* 0x3e5: mov    r14,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_3ea:
	/* 0x3ea: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_3ed:
	/* 0x3ed: je     dbd <generic_sleepable_preload+0xdbd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3ed, 0xdbd, x86_l_dbd);
x86_l_3f3:
	/* 0x3f3: mov    r14,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_3f8:
	/* 0x3f8: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_3fb:
	/* 0x3fb: je     dbd <generic_sleepable_preload+0xdbd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3fb, 0xdbd, x86_l_dbd);
x86_l_401:
	/* 0x401: mov    r14,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_406:
	/* 0x406: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_409:
	/* 0x409: je     dbd <generic_sleepable_preload+0xdbd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x409, 0xdbd, x86_l_dbd);
x86_l_40f:
	/* 0x40f: jmp    dd0 <generic_sleepable_preload+0xdd0> */
	X86_SIM_X86_JMP(0x40f, 0xdd0, x86_l_dd0);
x86_l_414:
	/* 0x414: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_417:
	/* 0x417: jg     656 <generic_sleepable_preload+0x656> */
	X86_SIM_X86_JCC(X86_CC_G, 0x417, 0x656, x86_l_656);
x86_l_41d:
	/* 0x41d: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_420:
	/* 0x420: jg     b34 <generic_sleepable_preload+0xb34> */
	X86_SIM_X86_JCC(X86_CC_G, 0x420, 0xb34, x86_l_b34);
x86_l_426:
	/* 0x426: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_429:
	/* 0x429: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_42b:
	/* 0x42b: je     c92 <generic_sleepable_preload+0xc92> */
	X86_SIM_X86_JCC(X86_CC_E, 0x42b, 0xc92, x86_l_c92);
x86_l_431:
	/* 0x431: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_436:
	/* 0x436: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_439:
	/* 0x439: je     c92 <generic_sleepable_preload+0xc92> */
	X86_SIM_X86_JCC(X86_CC_E, 0x439, 0xc92, x86_l_c92);
x86_l_43f:
	/* 0x43f: jmp    ca5 <generic_sleepable_preload+0xca5> */
	X86_SIM_X86_JMP(0x43f, 0xca5, x86_l_ca5);
x86_l_444:
	/* 0x444: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_447:
	/* 0x447: jg     680 <generic_sleepable_preload+0x680> */
	X86_SIM_X86_JCC(X86_CC_G, 0x447, 0x680, x86_l_680);
x86_l_44d:
	/* 0x44d: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_450:
	/* 0x450: jg     b55 <generic_sleepable_preload+0xb55> */
	X86_SIM_X86_JCC(X86_CC_G, 0x450, 0xb55, x86_l_b55);
x86_l_456:
	/* 0x456: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_458:
	/* 0x458: je     e60 <generic_sleepable_preload+0xe60> */
	X86_SIM_X86_JCC(X86_CC_E, 0x458, 0xe60, x86_l_e60);
x86_l_45e:
	/* 0x45e: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_463:
	/* 0x463: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_466:
	/* 0x466: je     e63 <generic_sleepable_preload+0xe63> */
	X86_SIM_X86_JCC(X86_CC_E, 0x466, 0xe63, x86_l_e63);
x86_l_46c:
	/* 0x46c: jmp    e76 <generic_sleepable_preload+0xe76> */
	X86_SIM_X86_JMP(0x46c, 0xe76, x86_l_e76);
x86_l_471:
	/* 0x471: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_474:
	/* 0x474: jg     6aa <generic_sleepable_preload+0x6aa> */
	X86_SIM_X86_JCC(X86_CC_G, 0x474, 0x6aa, x86_l_6aa);
x86_l_47a:
	/* 0x47a: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_47d:
	/* 0x47d: jg     b76 <generic_sleepable_preload+0xb76> */
	X86_SIM_X86_JCC(X86_CC_G, 0x47d, 0xb76, x86_l_b76);
x86_l_483:
	/* 0x483: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_485:
	/* 0x485: je     f17 <generic_sleepable_preload+0xf17> */
	X86_SIM_X86_JCC(X86_CC_E, 0x485, 0xf17, x86_l_f17);
x86_l_48b:
	/* 0x48b: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_490:
	/* 0x490: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_493:
	/* 0x493: je     f1a <generic_sleepable_preload+0xf1a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x493, 0xf1a, x86_l_f1a);
x86_l_499:
	/* 0x499: jmp    f2d <generic_sleepable_preload+0xf2d> */
	X86_SIM_X86_JMP(0x499, 0xf2d, x86_l_f2d);
x86_l_49e:
	/* 0x49e: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_4a1:
	/* 0x4a1: jg     6d4 <generic_sleepable_preload+0x6d4> */
	X86_SIM_X86_JCC(X86_CC_G, 0x4a1, 0x6d4, x86_l_6d4);
x86_l_4a7:
	/* 0x4a7: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_4aa:
	/* 0x4aa: jg     b97 <generic_sleepable_preload+0xb97> */
	X86_SIM_X86_JCC(X86_CC_G, 0x4aa, 0xb97, x86_l_b97);
x86_l_4b0:
	/* 0x4b0: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_4b2:
	/* 0x4b2: je     fce <generic_sleepable_preload+0xfce> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4b2, 0xfce, x86_l_fce);
x86_l_4b8:
	/* 0x4b8: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4bd:
	/* 0x4bd: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_4c0:
	/* 0x4c0: je     fd1 <generic_sleepable_preload+0xfd1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4c0, 0xfd1, x86_l_fd1);
x86_l_4c6:
	/* 0x4c6: jmp    fe4 <generic_sleepable_preload+0xfe4> */
	X86_SIM_X86_JMP(0x4c6, 0xfe4, x86_l_fe4);
x86_l_4cb:
	/* 0x4cb: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_4ce:
	/* 0x4ce: jg     6fe <generic_sleepable_preload+0x6fe> */
	X86_SIM_X86_JCC(X86_CC_G, 0x4ce, 0x6fe, x86_l_6fe);
x86_l_4d4:
	/* 0x4d4: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_4d7:
	/* 0x4d7: jg     bb8 <generic_sleepable_preload+0xbb8> */
	X86_SIM_X86_JCC(X86_CC_G, 0x4d7, 0xbb8, x86_l_bb8);
x86_l_4dd:
	/* 0x4dd: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_4df:
	/* 0x4df: je     dbd <generic_sleepable_preload+0xdbd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4df, 0xdbd, x86_l_dbd);
x86_l_4e5:
	/* 0x4e5: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_4e8:
	/* 0x4e8: mov    r14,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4ed:
	/* 0x4ed: je     dbd <generic_sleepable_preload+0xdbd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4ed, 0xdbd, x86_l_dbd);
x86_l_4f3:
	/* 0x4f3: jmp    dd0 <generic_sleepable_preload+0xdd0> */
	X86_SIM_X86_JMP(0x4f3, 0xdd0, x86_l_dd0);
x86_l_4f8:
	/* 0x4f8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4fa:
	/* 0x4fa: je     781 <generic_sleepable_preload+0x781> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4fa, 0x781, x86_l_781);
x86_l_500:
	/* 0x500: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_503:
	/* 0x503: jne    78d <generic_sleepable_preload+0x78d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x503, 0x78d, x86_l_78d);
x86_l_509:
	/* 0x509: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_50e:
	/* 0x50e: jmp    786 <generic_sleepable_preload+0x786> */
	X86_SIM_X86_JMP(0x50e, 0x786, x86_l_786);
x86_l_513:
	/* 0x513: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_515:
	/* 0x515: je     818 <generic_sleepable_preload+0x818> */
	X86_SIM_X86_JCC(X86_CC_E, 0x515, 0x818, x86_l_818);
x86_l_51b:
	/* 0x51b: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_51e:
	/* 0x51e: jne    824 <generic_sleepable_preload+0x824> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x51e, 0x824, x86_l_824);
x86_l_524:
	/* 0x524: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_529:
	/* 0x529: jmp    81d <generic_sleepable_preload+0x81d> */
	X86_SIM_X86_JMP(0x529, 0x81d, x86_l_81d);
x86_l_52e:
	/* 0x52e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_530:
	/* 0x530: je     8af <generic_sleepable_preload+0x8af> */
	X86_SIM_X86_JCC(X86_CC_E, 0x530, 0x8af, x86_l_8af);
x86_l_536:
	/* 0x536: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_539:
	/* 0x539: jne    8bb <generic_sleepable_preload+0x8bb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x539, 0x8bb, x86_l_8bb);
x86_l_53f:
	/* 0x53f: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_544:
	/* 0x544: jmp    8b4 <generic_sleepable_preload+0x8b4> */
	X86_SIM_X86_JMP(0x544, 0x8b4, x86_l_8b4);
x86_l_549:
	/* 0x549: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_54b:
	/* 0x54b: je     946 <generic_sleepable_preload+0x946> */
	X86_SIM_X86_JCC(X86_CC_E, 0x54b, 0x946, x86_l_946);
x86_l_551:
	/* 0x551: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_554:
	/* 0x554: jne    952 <generic_sleepable_preload+0x952> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x554, 0x952, x86_l_952);
x86_l_55a:
	/* 0x55a: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_55f:
	/* 0x55f: jmp    94b <generic_sleepable_preload+0x94b> */
	X86_SIM_X86_JMP(0x55f, 0x94b, x86_l_94b);
x86_l_564:
	/* 0x564: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_566:
	/* 0x566: je     9dd <generic_sleepable_preload+0x9dd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x566, 0x9dd, x86_l_9dd);
x86_l_56c:
	/* 0x56c: cmp    eax,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_56f:
	/* 0x56f: jne    9e9 <generic_sleepable_preload+0x9e9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x56f, 0x9e9, x86_l_9e9);
x86_l_575:
	/* 0x575: mov    rax,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_57a:
	/* 0x57a: jmp    9e2 <generic_sleepable_preload+0x9e2> */
	X86_SIM_X86_JMP(0x57a, 0x9e2, x86_l_9e2);
x86_l_57f:
	/* 0x57f: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_582:
	/* 0x582: jg     a8a <generic_sleepable_preload+0xa8a> */
	X86_SIM_X86_JCC(X86_CC_G, 0x582, 0xa8a, x86_l_a8a);
x86_l_588:
	/* 0x588: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_590:
	/* 0x590: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_593:
	/* 0x593: je     c92 <generic_sleepable_preload+0xc92> */
	X86_SIM_X86_JCC(X86_CC_E, 0x593, 0xc92, x86_l_c92);
x86_l_599:
	/* 0x599: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_59c:
	/* 0x59c: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_59f:
	/* 0x59f: je     c92 <generic_sleepable_preload+0xc92> */
	X86_SIM_X86_JCC(X86_CC_E, 0x59f, 0xc92, x86_l_c92);
x86_l_5a5:
	/* 0x5a5: jmp    ca5 <generic_sleepable_preload+0xca5> */
	X86_SIM_X86_JMP(0x5a5, 0xca5, x86_l_ca5);
x86_l_5aa:
	/* 0x5aa: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_5ad:
	/* 0x5ad: jg     aac <generic_sleepable_preload+0xaac> */
	X86_SIM_X86_JCC(X86_CC_G, 0x5ad, 0xaac, x86_l_aac);
x86_l_5b3:
	/* 0x5b3: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_5bb:
	/* 0x5bb: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5be:
	/* 0x5be: je     e63 <generic_sleepable_preload+0xe63> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5be, 0xe63, x86_l_e63);
x86_l_5c4:
	/* 0x5c4: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_5c7:
	/* 0x5c7: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_5ca:
	/* 0x5ca: je     e63 <generic_sleepable_preload+0xe63> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5ca, 0xe63, x86_l_e63);
x86_l_5d0:
	/* 0x5d0: jmp    e76 <generic_sleepable_preload+0xe76> */
	X86_SIM_X86_JMP(0x5d0, 0xe76, x86_l_e76);
x86_l_5d5:
	/* 0x5d5: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_5d8:
	/* 0x5d8: jg     ace <generic_sleepable_preload+0xace> */
	X86_SIM_X86_JCC(X86_CC_G, 0x5d8, 0xace, x86_l_ace);
x86_l_5de:
	/* 0x5de: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_5e6:
	/* 0x5e6: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5e9:
	/* 0x5e9: je     f1a <generic_sleepable_preload+0xf1a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5e9, 0xf1a, x86_l_f1a);
x86_l_5ef:
	/* 0x5ef: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_5f2:
	/* 0x5f2: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_5f5:
	/* 0x5f5: je     f1a <generic_sleepable_preload+0xf1a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5f5, 0xf1a, x86_l_f1a);
x86_l_5fb:
	/* 0x5fb: jmp    f2d <generic_sleepable_preload+0xf2d> */
	X86_SIM_X86_JMP(0x5fb, 0xf2d, x86_l_f2d);
x86_l_600:
	/* 0x600: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_603:
	/* 0x603: jg     af0 <generic_sleepable_preload+0xaf0> */
	X86_SIM_X86_JCC(X86_CC_G, 0x603, 0xaf0, x86_l_af0);
x86_l_609:
	/* 0x609: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_611:
	/* 0x611: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_614:
	/* 0x614: je     fd1 <generic_sleepable_preload+0xfd1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x614, 0xfd1, x86_l_fd1);
x86_l_61a:
	/* 0x61a: mov    rdx,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R13, X86_WIDTH_64);
x86_l_61d:
	/* 0x61d: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_620:
	/* 0x620: je     fd1 <generic_sleepable_preload+0xfd1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x620, 0xfd1, x86_l_fd1);
x86_l_626:
	/* 0x626: jmp    fe4 <generic_sleepable_preload+0xfe4> */
	X86_SIM_X86_JMP(0x626, 0xfe4, x86_l_fe4);
x86_l_62b:
	/* 0x62b: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_62e:
	/* 0x62e: jg     b12 <generic_sleepable_preload+0xb12> */
	X86_SIM_X86_JCC(X86_CC_G, 0x62e, 0xb12, x86_l_b12);
x86_l_634:
	/* 0x634: mov    r14,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_63c:
	/* 0x63c: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_63f:
	/* 0x63f: je     dbd <generic_sleepable_preload+0xdbd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x63f, 0xdbd, x86_l_dbd);
x86_l_645:
	/* 0x645: mov    r14,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R13, X86_WIDTH_64);
x86_l_648:
	/* 0x648: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_64b:
	/* 0x64b: je     dbd <generic_sleepable_preload+0xdbd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x64b, 0xdbd, x86_l_dbd);
x86_l_651:
	/* 0x651: jmp    dd0 <generic_sleepable_preload+0xdd0> */
	X86_SIM_X86_JMP(0x651, 0xdd0, x86_l_dd0);
x86_l_656:
	/* 0x656: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_659:
	/* 0x659: jg     bd9 <generic_sleepable_preload+0xbd9> */
	X86_SIM_X86_JCC(X86_CC_G, 0x659, 0xbd9, x86_l_bd9);
x86_l_65f:
	/* 0x65f: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_664:
	/* 0x664: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_667:
	/* 0x667: je     c92 <generic_sleepable_preload+0xc92> */
	X86_SIM_X86_JCC(X86_CC_E, 0x667, 0xc92, x86_l_c92);
x86_l_66d:
	/* 0x66d: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_672:
	/* 0x672: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_675:
	/* 0x675: je     c92 <generic_sleepable_preload+0xc92> */
	X86_SIM_X86_JCC(X86_CC_E, 0x675, 0xc92, x86_l_c92);
x86_l_67b:
	/* 0x67b: jmp    ca5 <generic_sleepable_preload+0xca5> */
	X86_SIM_X86_JMP(0x67b, 0xca5, x86_l_ca5);
x86_l_680:
	/* 0x680: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_683:
	/* 0x683: jg     bfa <generic_sleepable_preload+0xbfa> */
	X86_SIM_X86_JCC(X86_CC_G, 0x683, 0xbfa, x86_l_bfa);
x86_l_689:
	/* 0x689: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_68e:
	/* 0x68e: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_691:
	/* 0x691: je     e63 <generic_sleepable_preload+0xe63> */
	X86_SIM_X86_JCC(X86_CC_E, 0x691, 0xe63, x86_l_e63);
x86_l_697:
	/* 0x697: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_69c:
	/* 0x69c: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_69f:
	/* 0x69f: je     e63 <generic_sleepable_preload+0xe63> */
	X86_SIM_X86_JCC(X86_CC_E, 0x69f, 0xe63, x86_l_e63);
x86_l_6a5:
	/* 0x6a5: jmp    e76 <generic_sleepable_preload+0xe76> */
	X86_SIM_X86_JMP(0x6a5, 0xe76, x86_l_e76);
x86_l_6aa:
	/* 0x6aa: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_6ad:
	/* 0x6ad: jg     c1b <generic_sleepable_preload+0xc1b> */
	X86_SIM_X86_JCC(X86_CC_G, 0x6ad, 0xc1b, x86_l_c1b);
x86_l_6b3:
	/* 0x6b3: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_6b8:
	/* 0x6b8: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_6bb:
	/* 0x6bb: je     f1a <generic_sleepable_preload+0xf1a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6bb, 0xf1a, x86_l_f1a);
x86_l_6c1:
	/* 0x6c1: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_6c6:
	/* 0x6c6: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_6c9:
	/* 0x6c9: je     f1a <generic_sleepable_preload+0xf1a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6c9, 0xf1a, x86_l_f1a);
x86_l_6cf:
	/* 0x6cf: jmp    f2d <generic_sleepable_preload+0xf2d> */
	X86_SIM_X86_JMP(0x6cf, 0xf2d, x86_l_f2d);
x86_l_6d4:
	/* 0x6d4: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_6d7:
	/* 0x6d7: jg     c3c <generic_sleepable_preload+0xc3c> */
	X86_SIM_X86_JCC(X86_CC_G, 0x6d7, 0xc3c, x86_l_c3c);
x86_l_6dd:
	/* 0x6dd: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_6e2:
	/* 0x6e2: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_6e5:
	/* 0x6e5: je     fd1 <generic_sleepable_preload+0xfd1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6e5, 0xfd1, x86_l_fd1);
x86_l_6eb:
	/* 0x6eb: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_6f0:
	/* 0x6f0: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_6f3:
	/* 0x6f3: je     fd1 <generic_sleepable_preload+0xfd1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6f3, 0xfd1, x86_l_fd1);
x86_l_6f9:
	/* 0x6f9: jmp    fe4 <generic_sleepable_preload+0xfe4> */
	X86_SIM_X86_JMP(0x6f9, 0xfe4, x86_l_fe4);
x86_l_6fe:
	/* 0x6fe: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_701:
	/* 0x701: jg     c5d <generic_sleepable_preload+0xc5d> */
	X86_SIM_X86_JCC(X86_CC_G, 0x701, 0xc5d, x86_l_c5d);
x86_l_707:
	/* 0x707: mov    r14,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_70c:
	/* 0x70c: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_70f:
	/* 0x70f: je     dbd <generic_sleepable_preload+0xdbd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x70f, 0xdbd, x86_l_dbd);
x86_l_715:
	/* 0x715: mov    r14,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_71a:
	/* 0x71a: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_71d:
	/* 0x71d: je     dbd <generic_sleepable_preload+0xdbd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x71d, 0xdbd, x86_l_dbd);
x86_l_723:
	/* 0x723: jmp    dd0 <generic_sleepable_preload+0xdd0> */
	X86_SIM_X86_JMP(0x723, 0xdd0, x86_l_dd0);
x86_l_728:
	/* 0x728: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_72d:
	/* 0x72d: jmp    786 <generic_sleepable_preload+0x786> */
	X86_SIM_X86_JMP(0x72d, 0x786, x86_l_786);
x86_l_72f:
	/* 0x72f: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_734:
	/* 0x734: jmp    81d <generic_sleepable_preload+0x81d> */
	X86_SIM_X86_JMP(0x734, 0x81d, x86_l_81d);
x86_l_739:
	/* 0x739: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_73e:
	/* 0x73e: jmp    8b4 <generic_sleepable_preload+0x8b4> */
	X86_SIM_X86_JMP(0x73e, 0x8b4, x86_l_8b4);
x86_l_743:
	/* 0x743: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_748:
	/* 0x748: jmp    94b <generic_sleepable_preload+0x94b> */
	X86_SIM_X86_JMP(0x748, 0x94b, x86_l_94b);
x86_l_74d:
	/* 0x74d: mov    rax,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_752:
	/* 0x752: jmp    9e2 <generic_sleepable_preload+0x9e2> */
	X86_SIM_X86_JMP(0x752, 0x9e2, x86_l_9e2);
x86_l_757:
	/* 0x757: mov    rax,QWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_75b:
	/* 0x75b: jmp    789 <generic_sleepable_preload+0x789> */
	X86_SIM_X86_JMP(0x75b, 0x789, x86_l_789);
x86_l_75d:
	/* 0x75d: mov    rax,QWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_761:
	/* 0x761: jmp    820 <generic_sleepable_preload+0x820> */
	X86_SIM_X86_JMP(0x761, 0x820, x86_l_820);
x86_l_766:
	/* 0x766: mov    rax,QWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_76a:
	/* 0x76a: jmp    8b7 <generic_sleepable_preload+0x8b7> */
	X86_SIM_X86_JMP(0x76a, 0x8b7, x86_l_8b7);
x86_l_76f:
	/* 0x76f: mov    rax,QWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_773:
	/* 0x773: jmp    94e <generic_sleepable_preload+0x94e> */
	X86_SIM_X86_JMP(0x773, 0x94e, x86_l_94e);
x86_l_778:
	/* 0x778: mov    rax,QWORD PTR [r12] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_77c:
	/* 0x77c: jmp    9e5 <generic_sleepable_preload+0x9e5> */
	X86_SIM_X86_JMP(0x77c, 0x9e5, x86_l_9e5);
x86_l_781:
	/* 0x781: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_786:
	/* 0x786: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_789:
	/* 0x789: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_78d:
	/* 0x78d: mov    r15d,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_791:
	/* 0x791: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_794:
	/* 0x794: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_799:
	/* 0x799: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_79e:
	/* 0x79e: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_7a3:
	/* 0x7a3: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_7a6:
	/* 0x7a6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7a8:
	/* 0x7a8: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_7ac:
	/* 0x7ac: jne    d6 <generic_sleepable_preload+0xd6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x7ac, 0xd6, x86_l_d6);
x86_l_7b2:
	/* 0x7b2: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_7b6:
	/* 0x7b6: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_7bb:
	/* 0x7bb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7bd:
	/* 0x7bd: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7c2:
	/* 0x7c2: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_7ca:
	/* 0x7ca: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_7d1:
	/* 0x7d1: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_7d6:
	/* 0x7d6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_7db:
	/* 0x7db: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_7dd:
	/* 0x7dd: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_7e0:
	/* 0x7e0: je     d6 <generic_sleepable_preload+0xd6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7e0, 0xd6, x86_l_d6);
x86_l_7e6:
	/* 0x7e6: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_7e9:
	/* 0x7e9: mov    QWORD PTR [rsp+0x18],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_7ee:
	/* 0x7ee: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_7f5:
	/* 0x7f5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_7f7:
	/* 0x7f7: mov    r15,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_64);
x86_l_7fa:
	/* 0x7fa: lea    r13,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7ff:
	/* 0x7ff: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_804:
	/* 0x804: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_807:
	/* 0x807: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_80a:
	/* 0x80a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_80c:
	/* 0x80c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_80e:
	/* 0x80e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_813:
	/* 0x813: jmp    d09 <generic_sleepable_preload+0xd09> */
	X86_SIM_X86_JMP(0x813, 0xd09, x86_l_d09);
x86_l_818:
	/* 0x818: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_81d:
	/* 0x81d: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_820:
	/* 0x820: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_824:
	/* 0x824: mov    r15d,DWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_828:
	/* 0x828: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_82b:
	/* 0x82b: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_830:
	/* 0x830: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_835:
	/* 0x835: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_83a:
	/* 0x83a: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_83d:
	/* 0x83d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_83f:
	/* 0x83f: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_843:
	/* 0x843: jne    e0 <generic_sleepable_preload+0xe0> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x843, 0xe0, x86_l_e0);
x86_l_849:
	/* 0x849: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_84d:
	/* 0x84d: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_852:
	/* 0x852: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_854:
	/* 0x854: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_859:
	/* 0x859: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_861:
	/* 0x861: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_868:
	/* 0x868: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_86d:
	/* 0x86d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_872:
	/* 0x872: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_874:
	/* 0x874: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_877:
	/* 0x877: je     e0 <generic_sleepable_preload+0xe0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x877, 0xe0, x86_l_e0);
x86_l_87d:
	/* 0x87d: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_880:
	/* 0x880: mov    QWORD PTR [rsp+0x18],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_885:
	/* 0x885: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_88c:
	/* 0x88c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_88e:
	/* 0x88e: mov    r15,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_64);
x86_l_891:
	/* 0x891: lea    r13,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_896:
	/* 0x896: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_89b:
	/* 0x89b: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_89e:
	/* 0x89e: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_8a1:
	/* 0x8a1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8a3:
	/* 0x8a3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8a5:
	/* 0x8a5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_8aa:
	/* 0x8aa: jmp    eda <generic_sleepable_preload+0xeda> */
	X86_SIM_X86_JMP(0x8aa, 0xeda, x86_l_eda);
x86_l_8af:
	/* 0x8af: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_8b4:
	/* 0x8b4: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8b7:
	/* 0x8b7: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8bb:
	/* 0x8bb: mov    r15d,DWORD PTR [rbx+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_8bf:
	/* 0x8bf: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_8c2:
	/* 0x8c2: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_8c7:
	/* 0x8c7: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_8cc:
	/* 0x8cc: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_8d1:
	/* 0x8d1: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_8d4:
	/* 0x8d4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8d6:
	/* 0x8d6: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_8da:
	/* 0x8da: jne    ee <generic_sleepable_preload+0xee> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x8da, 0xee, x86_l_ee);
x86_l_8e0:
	/* 0x8e0: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_8e4:
	/* 0x8e4: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_8e9:
	/* 0x8e9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8eb:
	/* 0x8eb: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_8f0:
	/* 0x8f0: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_8f8:
	/* 0x8f8: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_8ff:
	/* 0x8ff: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_904:
	/* 0x904: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_909:
	/* 0x909: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_90b:
	/* 0x90b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_90e:
	/* 0x90e: je     ee <generic_sleepable_preload+0xee> */
	X86_SIM_X86_JCC(X86_CC_E, 0x90e, 0xee, x86_l_ee);
x86_l_914:
	/* 0x914: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_917:
	/* 0x917: mov    QWORD PTR [rsp+0x18],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_91c:
	/* 0x91c: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_923:
	/* 0x923: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_925:
	/* 0x925: mov    r15,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_64);
x86_l_928:
	/* 0x928: lea    r13,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_92d:
	/* 0x92d: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_932:
	/* 0x932: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_935:
	/* 0x935: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_938:
	/* 0x938: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_93a:
	/* 0x93a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_93c:
	/* 0x93c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_941:
	/* 0x941: jmp    f91 <generic_sleepable_preload+0xf91> */
	X86_SIM_X86_JMP(0x941, 0xf91, x86_l_f91);
x86_l_946:
	/* 0x946: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_94b:
	/* 0x94b: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_94e:
	/* 0x94e: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_952:
	/* 0x952: mov    r15d,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_956:
	/* 0x956: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_959:
	/* 0x959: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_95e:
	/* 0x95e: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_963:
	/* 0x963: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_968:
	/* 0x968: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_96b:
	/* 0x96b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_96d:
	/* 0x96d: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_971:
	/* 0x971: jne    fc <generic_sleepable_preload+0xfc> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x971, 0xfc, x86_l_fc);
x86_l_977:
	/* 0x977: mov    rbp,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_97b:
	/* 0x97b: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_980:
	/* 0x980: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_982:
	/* 0x982: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_987:
	/* 0x987: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_98f:
	/* 0x98f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_996:
	/* 0x996: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_99b:
	/* 0x99b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_9a0:
	/* 0x9a0: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9a2:
	/* 0x9a2: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_9a5:
	/* 0x9a5: je     fc <generic_sleepable_preload+0xfc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9a5, 0xfc, x86_l_fc);
x86_l_9ab:
	/* 0x9ab: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_9ae:
	/* 0x9ae: mov    QWORD PTR [rsp+0x18],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_9b3:
	/* 0x9b3: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_9ba:
	/* 0x9ba: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9bc:
	/* 0x9bc: mov    r15,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_64);
x86_l_9bf:
	/* 0x9bf: lea    r13,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_9c4:
	/* 0x9c4: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_9c9:
	/* 0x9c9: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_9cc:
	/* 0x9cc: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_9cf:
	/* 0x9cf: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9d1:
	/* 0x9d1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_9d3:
	/* 0x9d3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_9d8:
	/* 0x9d8: jmp    1048 <generic_sleepable_preload+0x1048> */
	X86_SIM_X86_JMP(0x9d8, 0x1048, x86_l_1048);
x86_l_9dd:
	/* 0x9dd: mov    rax,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_9e2:
	/* 0x9e2: mov    rax,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9e5:
	/* 0x9e5: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9e9:
	/* 0x9e9: mov    ebx,DWORD PTR [rbx+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_9ec:
	/* 0x9ec: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_9ef:
	/* 0x9ef: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_9f4:
	/* 0x9f4: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_9f9:
	/* 0x9f9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_9fe:
	/* 0x9fe: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_a01:
	/* 0xa01: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a03:
	/* 0xa03: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_a06:
	/* 0xa06: jne    10a <generic_sleepable_preload+0x10a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa06, 0x10a, x86_l_10a);
x86_l_a0c:
	/* 0xa0c: mov    rbx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a10:
	/* 0xa10: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_a15:
	/* 0xa15: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a17:
	/* 0xa17: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a1c:
	/* 0xa1c: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_a24:
	/* 0xa24: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_a2b:
	/* 0xa2b: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_a30:
	/* 0xa30: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a35:
	/* 0xa35: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a37:
	/* 0xa37: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a3a:
	/* 0xa3a: je     10a <generic_sleepable_preload+0x10a> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa3a, 0x10a, x86_l_10a);
x86_l_a40:
	/* 0xa40: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_a43:
	/* 0xa43: mov    r14,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_a4a:
	/* 0xa4a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a4c:
	/* 0xa4c: lea    r15,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a51:
	/* 0xa51: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_a56:
	/* 0xa56: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_a59:
	/* 0xa59: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_a5c:
	/* 0xa5c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a5e:
	/* 0xa5e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a60:
	/* 0xa60: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_a65:
	/* 0xa65: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_a68:
	/* 0xa68: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_a6b:
	/* 0xa6b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a6d:
	/* 0xa6d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_a70:
	/* 0xa70: je     10a <generic_sleepable_preload+0x10a> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa70, 0x10a, x86_l_10a);
x86_l_a76:
	/* 0xa76: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_a79:
	/* 0xa79: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_a7d:
	/* 0xa7d: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_a82:
	/* 0xa82: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_a85:
	/* 0xa85: jmp    e4c <generic_sleepable_preload+0xe4c> */
	X86_SIM_X86_JMP(0xa85, 0xe4c, x86_l_e4c);
x86_l_a8a:
	/* 0xa8a: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_a92:
	/* 0xa92: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_a95:
	/* 0xa95: je     c92 <generic_sleepable_preload+0xc92> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa95, 0xc92, x86_l_c92);
x86_l_a9b:
	/* 0xa9b: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_a9e:
	/* 0xa9e: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_aa1:
	/* 0xaa1: je     c92 <generic_sleepable_preload+0xc92> */
	X86_SIM_X86_JCC(X86_CC_E, 0xaa1, 0xc92, x86_l_c92);
x86_l_aa7:
	/* 0xaa7: jmp    ca5 <generic_sleepable_preload+0xca5> */
	X86_SIM_X86_JMP(0xaa7, 0xca5, x86_l_ca5);
x86_l_aac:
	/* 0xaac: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_ab4:
	/* 0xab4: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_ab7:
	/* 0xab7: je     e63 <generic_sleepable_preload+0xe63> */
	X86_SIM_X86_JCC(X86_CC_E, 0xab7, 0xe63, x86_l_e63);
x86_l_abd:
	/* 0xabd: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_ac0:
	/* 0xac0: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_ac3:
	/* 0xac3: je     e63 <generic_sleepable_preload+0xe63> */
	X86_SIM_X86_JCC(X86_CC_E, 0xac3, 0xe63, x86_l_e63);
x86_l_ac9:
	/* 0xac9: jmp    e76 <generic_sleepable_preload+0xe76> */
	X86_SIM_X86_JMP(0xac9, 0xe76, x86_l_e76);
x86_l_ace:
	/* 0xace: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_ad6:
	/* 0xad6: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_ad9:
	/* 0xad9: je     f1a <generic_sleepable_preload+0xf1a> */
	X86_SIM_X86_JCC(X86_CC_E, 0xad9, 0xf1a, x86_l_f1a);
x86_l_adf:
	/* 0xadf: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_ae2:
	/* 0xae2: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_ae5:
	/* 0xae5: je     f1a <generic_sleepable_preload+0xf1a> */
	X86_SIM_X86_JCC(X86_CC_E, 0xae5, 0xf1a, x86_l_f1a);
x86_l_aeb:
	/* 0xaeb: jmp    f2d <generic_sleepable_preload+0xf2d> */
	X86_SIM_X86_JMP(0xaeb, 0xf2d, x86_l_f2d);
x86_l_af0:
	/* 0xaf0: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_af8:
	/* 0xaf8: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_afb:
	/* 0xafb: je     fd1 <generic_sleepable_preload+0xfd1> */
	X86_SIM_X86_JCC(X86_CC_E, 0xafb, 0xfd1, x86_l_fd1);
x86_l_b01:
	/* 0xb01: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_b04:
	/* 0xb04: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_b07:
	/* 0xb07: je     fd1 <generic_sleepable_preload+0xfd1> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb07, 0xfd1, x86_l_fd1);
x86_l_b0d:
	/* 0xb0d: jmp    fe4 <generic_sleepable_preload+0xfe4> */
	X86_SIM_X86_JMP(0xb0d, 0xfe4, x86_l_fe4);
x86_l_b12:
	/* 0xb12: mov    r14,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_b1a:
	/* 0xb1a: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_b1d:
	/* 0xb1d: je     dbd <generic_sleepable_preload+0xdbd> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb1d, 0xdbd, x86_l_dbd);
x86_l_b23:
	/* 0xb23: mov    r14,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_R12, X86_WIDTH_64);
x86_l_b26:
	/* 0xb26: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_b29:
	/* 0xb29: je     dbd <generic_sleepable_preload+0xdbd> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb29, 0xdbd, x86_l_dbd);
x86_l_b2f:
	/* 0xb2f: jmp    dd0 <generic_sleepable_preload+0xdd0> */
	X86_SIM_X86_JMP(0xb2f, 0xdd0, x86_l_dd0);
x86_l_b34:
	/* 0xb34: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_b39:
	/* 0xb39: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_b3c:
	/* 0xb3c: je     c92 <generic_sleepable_preload+0xc92> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb3c, 0xc92, x86_l_c92);
x86_l_b42:
	/* 0xb42: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_b47:
	/* 0xb47: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_b4a:
	/* 0xb4a: je     c92 <generic_sleepable_preload+0xc92> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb4a, 0xc92, x86_l_c92);
x86_l_b50:
	/* 0xb50: jmp    ca5 <generic_sleepable_preload+0xca5> */
	X86_SIM_X86_JMP(0xb50, 0xca5, x86_l_ca5);
x86_l_b55:
	/* 0xb55: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_b5a:
	/* 0xb5a: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_b5d:
	/* 0xb5d: je     e63 <generic_sleepable_preload+0xe63> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb5d, 0xe63, x86_l_e63);
x86_l_b63:
	/* 0xb63: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_b68:
	/* 0xb68: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_b6b:
	/* 0xb6b: je     e63 <generic_sleepable_preload+0xe63> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb6b, 0xe63, x86_l_e63);
x86_l_b71:
	/* 0xb71: jmp    e76 <generic_sleepable_preload+0xe76> */
	X86_SIM_X86_JMP(0xb71, 0xe76, x86_l_e76);
x86_l_b76:
	/* 0xb76: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_b7b:
	/* 0xb7b: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_b7e:
	/* 0xb7e: je     f1a <generic_sleepable_preload+0xf1a> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb7e, 0xf1a, x86_l_f1a);
x86_l_b84:
	/* 0xb84: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_b89:
	/* 0xb89: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_b8c:
	/* 0xb8c: je     f1a <generic_sleepable_preload+0xf1a> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb8c, 0xf1a, x86_l_f1a);
x86_l_b92:
	/* 0xb92: jmp    f2d <generic_sleepable_preload+0xf2d> */
	X86_SIM_X86_JMP(0xb92, 0xf2d, x86_l_f2d);
x86_l_b97:
	/* 0xb97: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_b9c:
	/* 0xb9c: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_b9f:
	/* 0xb9f: je     fd1 <generic_sleepable_preload+0xfd1> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb9f, 0xfd1, x86_l_fd1);
x86_l_ba5:
	/* 0xba5: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_baa:
	/* 0xbaa: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_bad:
	/* 0xbad: je     fd1 <generic_sleepable_preload+0xfd1> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbad, 0xfd1, x86_l_fd1);
x86_l_bb3:
	/* 0xbb3: jmp    fe4 <generic_sleepable_preload+0xfe4> */
	X86_SIM_X86_JMP(0xbb3, 0xfe4, x86_l_fe4);
x86_l_bb8:
	/* 0xbb8: mov    r14,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_bbd:
	/* 0xbbd: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_bc0:
	/* 0xbc0: je     dbd <generic_sleepable_preload+0xdbd> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbc0, 0xdbd, x86_l_dbd);
x86_l_bc6:
	/* 0xbc6: mov    r14,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_bcb:
	/* 0xbcb: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_bce:
	/* 0xbce: je     dbd <generic_sleepable_preload+0xdbd> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbce, 0xdbd, x86_l_dbd);
x86_l_bd4:
	/* 0xbd4: jmp    dd0 <generic_sleepable_preload+0xdd0> */
	X86_SIM_X86_JMP(0xbd4, 0xdd0, x86_l_dd0);
x86_l_bd9:
	/* 0xbd9: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_bde:
	/* 0xbde: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_be1:
	/* 0xbe1: je     c92 <generic_sleepable_preload+0xc92> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbe1, 0xc92, x86_l_c92);
x86_l_be7:
	/* 0xbe7: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_bec:
	/* 0xbec: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_bef:
	/* 0xbef: je     c92 <generic_sleepable_preload+0xc92> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbef, 0xc92, x86_l_c92);
x86_l_bf5:
	/* 0xbf5: jmp    ca5 <generic_sleepable_preload+0xca5> */
	X86_SIM_X86_JMP(0xbf5, 0xca5, x86_l_ca5);
x86_l_bfa:
	/* 0xbfa: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_bff:
	/* 0xbff: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_c02:
	/* 0xc02: je     e63 <generic_sleepable_preload+0xe63> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc02, 0xe63, x86_l_e63);
x86_l_c08:
	/* 0xc08: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_c0d:
	/* 0xc0d: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_c10:
	/* 0xc10: je     e63 <generic_sleepable_preload+0xe63> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc10, 0xe63, x86_l_e63);
x86_l_c16:
	/* 0xc16: jmp    e76 <generic_sleepable_preload+0xe76> */
	X86_SIM_X86_JMP(0xc16, 0xe76, x86_l_e76);
x86_l_c1b:
	/* 0xc1b: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_c20:
	/* 0xc20: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_c23:
	/* 0xc23: je     f1a <generic_sleepable_preload+0xf1a> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc23, 0xf1a, x86_l_f1a);
x86_l_c29:
	/* 0xc29: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_c2e:
	/* 0xc2e: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_c31:
	/* 0xc31: je     f1a <generic_sleepable_preload+0xf1a> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc31, 0xf1a, x86_l_f1a);
x86_l_c37:
	/* 0xc37: jmp    f2d <generic_sleepable_preload+0xf2d> */
	X86_SIM_X86_JMP(0xc37, 0xf2d, x86_l_f2d);
x86_l_c3c:
	/* 0xc3c: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_c41:
	/* 0xc41: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_c44:
	/* 0xc44: je     fd1 <generic_sleepable_preload+0xfd1> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc44, 0xfd1, x86_l_fd1);
x86_l_c4a:
	/* 0xc4a: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_c4f:
	/* 0xc4f: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_c52:
	/* 0xc52: je     fd1 <generic_sleepable_preload+0xfd1> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc52, 0xfd1, x86_l_fd1);
x86_l_c58:
	/* 0xc58: jmp    fe4 <generic_sleepable_preload+0xfe4> */
	X86_SIM_X86_JMP(0xc58, 0xfe4, x86_l_fe4);
x86_l_c5d:
	/* 0xc5d: mov    r14,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_c62:
	/* 0xc62: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_c65:
	/* 0xc65: je     dbd <generic_sleepable_preload+0xdbd> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc65, 0xdbd, x86_l_dbd);
x86_l_c6b:
	/* 0xc6b: mov    r14,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_c70:
	/* 0xc70: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_c73:
	/* 0xc73: je     dbd <generic_sleepable_preload+0xdbd> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc73, 0xdbd, x86_l_dbd);
x86_l_c79:
	/* 0xc79: jmp    dd0 <generic_sleepable_preload+0xdd0> */
	X86_SIM_X86_JMP(0xc79, 0xdd0, x86_l_dd0);
x86_l_c7e:
	/* 0xc7e: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_c83:
	/* 0xc83: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_c86:
	/* 0xc86: je     c92 <generic_sleepable_preload+0xc92> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc86, 0xc92, x86_l_c92);
x86_l_c88:
	/* 0xc88: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_c8d:
	/* 0xc8d: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_c90:
	/* 0xc90: jne    ca5 <generic_sleepable_preload+0xca5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xc90, 0xca5, x86_l_ca5);
x86_l_c92:
	/* 0xc92: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_c95:
	/* 0xc95: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_c97:
	/* 0xc97: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_c99:
	/* 0xc99: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_c9e:
	/* 0xc9e: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_ca0:
	/* 0xca0: bzhi   rbp,QWORD PTR [rdx],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RBP, X86_RDX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_ca5:
	/* 0xca5: cmp    DWORD PTR [rbx+0x4],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869190ULL);
x86_l_ca9:
	/* 0xca9: jne    d6 <generic_sleepable_preload+0xd6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xca9, 0xd6, x86_l_d6);
x86_l_caf:
	/* 0xcaf: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_cb4:
	/* 0xcb4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cb6:
	/* 0xcb6: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cbb:
	/* 0xcbb: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_cc2:
	/* 0xcc2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_cc9:
	/* 0xcc9: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_ccc:
	/* 0xccc: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_cd1:
	/* 0xcd1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cd3:
	/* 0xcd3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_cd6:
	/* 0xcd6: je     d6 <generic_sleepable_preload+0xd6> */
	X86_SIM_X86_JCC(X86_CC_E, 0xcd6, 0xd6, x86_l_d6);
x86_l_cdc:
	/* 0xcdc: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_cdf:
	/* 0xcdf: mov    QWORD PTR [rsp+0x18],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ce4:
	/* 0xce4: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_ceb:
	/* 0xceb: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ced:
	/* 0xced: mov    r15,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_64);
x86_l_cf0:
	/* 0xcf0: lea    r13,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cf5:
	/* 0xcf5: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_cfa:
	/* 0xcfa: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_cfd:
	/* 0xcfd: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_d00:
	/* 0xd00: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d02:
	/* 0xd02: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d04:
	/* 0xd04: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d09:
	/* 0xd09: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_d0c:
	/* 0xd0c: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d11:
	/* 0xd11: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_d14:
	/* 0xd14: mov    r13,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R15, X86_WIDTH_64);
x86_l_d17:
	/* 0xd17: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d19:
	/* 0xd19: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d1c:
	/* 0xd1c: je     d6 <generic_sleepable_preload+0xd6> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd1c, 0xd6, x86_l_d6);
x86_l_d22:
	/* 0xd22: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_d25:
	/* 0xd25: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_d29:
	/* 0xd29: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_d2e:
	/* 0xd2e: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_d31:
	/* 0xd31: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d33:
	/* 0xd33: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_d36:
	/* 0xd36: call   d3b <generic_sleepable_preload+0xd3b> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_d3b:
	/* 0xd3b: sar    eax,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SAR, 31ULL);
x86_l_d3e:
	/* 0xd3e: mov    DWORD PTR [r15],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d41:
	/* 0xd41: jmp    d6 <generic_sleepable_preload+0xd6> */
	X86_SIM_X86_JMP(0xd41, 0xd6, x86_l_d6);
x86_l_d46:
	/* 0xd46: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_d4b:
	/* 0xd4b: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_d4e:
	/* 0xd4e: je     e63 <generic_sleepable_preload+0xe63> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd4e, 0xe63, x86_l_e63);
x86_l_d54:
	/* 0xd54: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d59:
	/* 0xd59: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_d5c:
	/* 0xd5c: je     e63 <generic_sleepable_preload+0xe63> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd5c, 0xe63, x86_l_e63);
x86_l_d62:
	/* 0xd62: jmp    e76 <generic_sleepable_preload+0xe76> */
	X86_SIM_X86_JMP(0xd62, 0xe76, x86_l_e76);
x86_l_d67:
	/* 0xd67: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_d6c:
	/* 0xd6c: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_d6f:
	/* 0xd6f: je     f1a <generic_sleepable_preload+0xf1a> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd6f, 0xf1a, x86_l_f1a);
x86_l_d75:
	/* 0xd75: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d7a:
	/* 0xd7a: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_d7d:
	/* 0xd7d: je     f1a <generic_sleepable_preload+0xf1a> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd7d, 0xf1a, x86_l_f1a);
x86_l_d83:
	/* 0xd83: jmp    f2d <generic_sleepable_preload+0xf2d> */
	X86_SIM_X86_JMP(0xd83, 0xf2d, x86_l_f2d);
x86_l_d88:
	/* 0xd88: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_d8d:
	/* 0xd8d: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_d90:
	/* 0xd90: je     fd1 <generic_sleepable_preload+0xfd1> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd90, 0xfd1, x86_l_fd1);
x86_l_d96:
	/* 0xd96: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_d9b:
	/* 0xd9b: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_d9e:
	/* 0xd9e: je     fd1 <generic_sleepable_preload+0xfd1> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd9e, 0xfd1, x86_l_fd1);
x86_l_da4:
	/* 0xda4: jmp    fe4 <generic_sleepable_preload+0xfe4> */
	X86_SIM_X86_JMP(0xda4, 0xfe4, x86_l_fe4);
x86_l_da9:
	/* 0xda9: mov    r14,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_dae:
	/* 0xdae: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_db1:
	/* 0xdb1: je     dbd <generic_sleepable_preload+0xdbd> */
	X86_SIM_X86_JCC(X86_CC_E, 0xdb1, 0xdbd, x86_l_dbd);
x86_l_db3:
	/* 0xdb3: mov    r14,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_db8:
	/* 0xdb8: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_dbb:
	/* 0xdbb: jne    dd0 <generic_sleepable_preload+0xdd0> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xdbb, 0xdd0, x86_l_dd0);
x86_l_dbd:
	/* 0xdbd: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_dc0:
	/* 0xdc0: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_dc2:
	/* 0xdc2: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_dc4:
	/* 0xdc4: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_dc9:
	/* 0xdc9: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_dcb:
	/* 0xdcb: bzhi   r15,QWORD PTR [r14],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_R15, X86_R14, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_dd0:
	/* 0xdd0: cmp    DWORD PTR [rbx+0x14],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345926ULL);
x86_l_dd4:
	/* 0xdd4: jne    10a <generic_sleepable_preload+0x10a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xdd4, 0x10a, x86_l_10a);
x86_l_dda:
	/* 0xdda: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_ddf:
	/* 0xddf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_de1:
	/* 0xde1: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_de6:
	/* 0xde6: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ded:
	/* 0xded: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_df4:
	/* 0xdf4: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_df7:
	/* 0xdf7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_dfc:
	/* 0xdfc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dfe:
	/* 0xdfe: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e01:
	/* 0xe01: je     10a <generic_sleepable_preload+0x10a> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe01, 0x10a, x86_l_10a);
x86_l_e07:
	/* 0xe07: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_e0a:
	/* 0xe0a: mov    rbx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_e11:
	/* 0xe11: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e13:
	/* 0xe13: lea    r14,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R14, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e18:
	/* 0xe18: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_e1d:
	/* 0xe1d: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_e20:
	/* 0xe20: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_e23:
	/* 0xe23: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e25:
	/* 0xe25: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e27:
	/* 0xe27: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e2c:
	/* 0xe2c: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_e2f:
	/* 0xe2f: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_e32:
	/* 0xe32: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e34:
	/* 0xe34: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e37:
	/* 0xe37: je     10a <generic_sleepable_preload+0x10a> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe37, 0x10a, x86_l_10a);
x86_l_e3d:
	/* 0xe3d: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_e40:
	/* 0xe40: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_e44:
	/* 0xe44: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_e49:
	/* 0xe49: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_e4c:
	/* 0xe4c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e4e:
	/* 0xe4e: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_e51:
	/* 0xe51: call   e56 <generic_sleepable_preload+0xe56> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_e56:
	/* 0xe56: sar    eax,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SAR, 31ULL);
x86_l_e59:
	/* 0xe59: mov    DWORD PTR [rbx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e5b:
	/* 0xe5b: jmp    10a <generic_sleepable_preload+0x10a> */
	X86_SIM_X86_JMP(0xe5b, 0x10a, x86_l_10a);
x86_l_e60:
	/* 0xe60: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_e63:
	/* 0xe63: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_e66:
	/* 0xe66: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_e68:
	/* 0xe68: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_e6a:
	/* 0xe6a: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_e6f:
	/* 0xe6f: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_e71:
	/* 0xe71: bzhi   rbp,QWORD PTR [rdx],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RBP, X86_RDX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_e76:
	/* 0xe76: cmp    DWORD PTR [rbx+0x8],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738374ULL);
x86_l_e7a:
	/* 0xe7a: jne    e0 <generic_sleepable_preload+0xe0> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe7a, 0xe0, x86_l_e0);
x86_l_e80:
	/* 0xe80: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_e85:
	/* 0xe85: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e87:
	/* 0xe87: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e8c:
	/* 0xe8c: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e93:
	/* 0xe93: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_e9a:
	/* 0xe9a: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_e9d:
	/* 0xe9d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ea2:
	/* 0xea2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ea4:
	/* 0xea4: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ea7:
	/* 0xea7: je     e0 <generic_sleepable_preload+0xe0> */
	X86_SIM_X86_JCC(X86_CC_E, 0xea7, 0xe0, x86_l_e0);
x86_l_ead:
	/* 0xead: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_eb0:
	/* 0xeb0: mov    QWORD PTR [rsp+0x18],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_eb5:
	/* 0xeb5: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_ebc:
	/* 0xebc: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ebe:
	/* 0xebe: mov    r15,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_64);
x86_l_ec1:
	/* 0xec1: lea    r13,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ec6:
	/* 0xec6: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_ecb:
	/* 0xecb: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_ece:
	/* 0xece: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_ed1:
	/* 0xed1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ed3:
	/* 0xed3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ed5:
	/* 0xed5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_eda:
	/* 0xeda: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_edd:
	/* 0xedd: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ee2:
	/* 0xee2: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_ee5:
	/* 0xee5: mov    r13,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R15, X86_WIDTH_64);
x86_l_ee8:
	/* 0xee8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_eea:
	/* 0xeea: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_eed:
	/* 0xeed: je     e0 <generic_sleepable_preload+0xe0> */
	X86_SIM_X86_JCC(X86_CC_E, 0xeed, 0xe0, x86_l_e0);
x86_l_ef3:
	/* 0xef3: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_ef6:
	/* 0xef6: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_efa:
	/* 0xefa: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_eff:
	/* 0xeff: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_f02:
	/* 0xf02: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f04:
	/* 0xf04: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_f07:
	/* 0xf07: call   f0c <generic_sleepable_preload+0xf0c> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_f0c:
	/* 0xf0c: sar    eax,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SAR, 31ULL);
x86_l_f0f:
	/* 0xf0f: mov    DWORD PTR [r15],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f12:
	/* 0xf12: jmp    e0 <generic_sleepable_preload+0xe0> */
	X86_SIM_X86_JMP(0xf12, 0xe0, x86_l_e0);
x86_l_f17:
	/* 0xf17: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_f1a:
	/* 0xf1a: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_f1d:
	/* 0xf1d: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_f1f:
	/* 0xf1f: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_f21:
	/* 0xf21: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_f26:
	/* 0xf26: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_f28:
	/* 0xf28: bzhi   rbp,QWORD PTR [rdx],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RBP, X86_RDX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_f2d:
	/* 0xf2d: cmp    DWORD PTR [rbx+0xc],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607558ULL);
x86_l_f31:
	/* 0xf31: jne    ee <generic_sleepable_preload+0xee> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf31, 0xee, x86_l_ee);
x86_l_f37:
	/* 0xf37: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_f3c:
	/* 0xf3c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f3e:
	/* 0xf3e: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f43:
	/* 0xf43: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f4a:
	/* 0xf4a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_f51:
	/* 0xf51: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_f54:
	/* 0xf54: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f59:
	/* 0xf59: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f5b:
	/* 0xf5b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f5e:
	/* 0xf5e: je     ee <generic_sleepable_preload+0xee> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf5e, 0xee, x86_l_ee);
x86_l_f64:
	/* 0xf64: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_f67:
	/* 0xf67: mov    QWORD PTR [rsp+0x18],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_f6c:
	/* 0xf6c: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_f73:
	/* 0xf73: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f75:
	/* 0xf75: mov    r15,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_64);
x86_l_f78:
	/* 0xf78: lea    r13,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f7d:
	/* 0xf7d: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_f82:
	/* 0xf82: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_f85:
	/* 0xf85: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_f88:
	/* 0xf88: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f8a:
	/* 0xf8a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f8c:
	/* 0xf8c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f91:
	/* 0xf91: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_f94:
	/* 0xf94: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_f99:
	/* 0xf99: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_f9c:
	/* 0xf9c: mov    r13,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R15, X86_WIDTH_64);
x86_l_f9f:
	/* 0xf9f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fa1:
	/* 0xfa1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_fa4:
	/* 0xfa4: je     ee <generic_sleepable_preload+0xee> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfa4, 0xee, x86_l_ee);
x86_l_faa:
	/* 0xfaa: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_fad:
	/* 0xfad: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_fb1:
	/* 0xfb1: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_fb6:
	/* 0xfb6: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_fb9:
	/* 0xfb9: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_fbb:
	/* 0xfbb: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_fbe:
	/* 0xfbe: call   fc3 <generic_sleepable_preload+0xfc3> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_fc3:
	/* 0xfc3: sar    eax,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SAR, 31ULL);
x86_l_fc6:
	/* 0xfc6: mov    DWORD PTR [r15],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_fc9:
	/* 0xfc9: jmp    ee <generic_sleepable_preload+0xee> */
	X86_SIM_X86_JMP(0xfc9, 0xee, x86_l_ee);
x86_l_fce:
	/* 0xfce: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_fd1:
	/* 0xfd1: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_fd4:
	/* 0xfd4: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_fd6:
	/* 0xfd6: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_fd8:
	/* 0xfd8: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_fdd:
	/* 0xfdd: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_fdf:
	/* 0xfdf: bzhi   rbp,QWORD PTR [rdx],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_RBP, X86_RDX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_fe4:
	/* 0xfe4: cmp    DWORD PTR [rbx+0x10],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476742ULL);
x86_l_fe8:
	/* 0xfe8: jne    fc <generic_sleepable_preload+0xfc> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xfe8, 0xfc, x86_l_fc);
x86_l_fee:
	/* 0xfee: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_ff3:
	/* 0xff3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ff5:
	/* 0xff5: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ffa:
	/* 0xffa: mov    DWORD PTR [rsp],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1001:
	/* 0x1001: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_1008:
	/* 0x1008: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_100b:
	/* 0x100b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1010:
	/* 0x1010: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1012:
	/* 0x1012: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1015:
	/* 0x1015: je     fc <generic_sleepable_preload+0xfc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1015, 0xfc, x86_l_fc);
x86_l_101b:
	/* 0x101b: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_101e:
	/* 0x101e: mov    QWORD PTR [rsp+0x18],r12 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1023:
	/* 0x1023: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_102a:
	/* 0x102a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_102c:
	/* 0x102c: mov    r15,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_R13, X86_WIDTH_64);
x86_l_102f:
	/* 0x102f: lea    r13,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_R13, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1034:
	/* 0x1034: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1039:
	/* 0x1039: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_103c:
	/* 0x103c: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_103f:
	/* 0x103f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1041:
	/* 0x1041: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1043:
	/* 0x1043: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1048:
	/* 0x1048: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_104b:
	/* 0x104b: mov    r12,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R12, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1050:
	/* 0x1050: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_1053:
	/* 0x1053: mov    r13,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R15, X86_WIDTH_64);
x86_l_1056:
	/* 0x1056: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1058:
	/* 0x1058: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_105b:
	/* 0x105b: je     fc <generic_sleepable_preload+0xfc> */
	X86_SIM_X86_JCC(X86_CC_E, 0x105b, 0xfc, x86_l_fc);
x86_l_1061:
	/* 0x1061: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1064:
	/* 0x1064: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1068:
	/* 0x1068: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_106d:
	/* 0x106d: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_1070:
	/* 0x1070: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1072:
	/* 0x1072: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1075:
	/* 0x1075: call   107a <generic_sleepable_preload+0x107a> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_107a:
	/* 0x107a: sar    eax,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SAR, 31ULL);
x86_l_107d:
	/* 0x107d: mov    DWORD PTR [r15],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1080:
	/* 0x1080: jmp    fc <generic_sleepable_preload+0xfc> */
	X86_SIM_X86_JMP(0x1080, 0xfc, x86_l_fc);
x86_l_1085:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
