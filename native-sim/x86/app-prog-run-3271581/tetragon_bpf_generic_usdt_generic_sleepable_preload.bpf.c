extern char config_map;
extern char heap_ro_zero;
extern char sleepable_preload;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_generic_usdt_generic_sleepable_preload_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0xa: sub    rsp,0x98 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 152ULL);
x86_l_11:
	/* 0x11: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_14:
	/* 0x14: mov    DWORD PTR [rsp+0x94],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 635655159808ULL);
x86_l_1f:
	/* 0x1f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_26:
	/* 0x26: lea    rsi,[rsp+0x94] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_2e:
	/* 0x2e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_33:
	/* 0x33: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_35:
	/* 0x35: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_38:
	/* 0x38: je     11a <generic_sleepable_preload+0x11a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x38, 0x11a, x86_l_11a);
x86_l_3e:
	/* 0x3e: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_41:
	/* 0x41: lea    rax,[r14+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_48:
	/* 0x48: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4d:
	/* 0x4d: lea    rax,[r14+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_54:
	/* 0x54: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_59:
	/* 0x59: lea    rax,[r14+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_5d:
	/* 0x5d: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_65:
	/* 0x65: lea    rax,[r14+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_69:
	/* 0x69: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_6e:
	/* 0x6e: lea    rax,[r14+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_72:
	/* 0x72: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_7a:
	/* 0x7a: lea    rax,[r14+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_7e:
	/* 0x7e: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_83:
	/* 0x83: lea    rax,[r14+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_87:
	/* 0x87: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_8c:
	/* 0x8c: lea    rax,[r14+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_90:
	/* 0x90: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_95:
	/* 0x95: lea    rax,[r14+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_99:
	/* 0x99: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_9e:
	/* 0x9e: lea    rax,[r14+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_a2:
	/* 0xa2: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a7:
	/* 0xa7: lea    rax,[r14+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_ab:
	/* 0xab: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_b0:
	/* 0xb0: lea    rax,[r14+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_b4:
	/* 0xb4: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b9:
	/* 0xb9: lea    rax,[r14+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_bd:
	/* 0xbd: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_c2:
	/* 0xc2: lea    rax,[r14+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c6:
	/* 0xc6: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_cb:
	/* 0xcb: lea    rax,[r14+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_cf:
	/* 0xcf: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_d4:
	/* 0xd4: lea    rbp,[r14+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d8:
	/* 0xd8: mov    eax,DWORD PTR [rbx+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_db:
	/* 0xdb: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_e0:
	/* 0xe0: jne    132 <generic_sleepable_preload+0x132> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe0, 0x132, x86_l_132);
x86_l_e2:
	/* 0xe2: mov    eax,DWORD PTR [rbx+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_e5:
	/* 0xe5: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_ea:
	/* 0xea: jne    190 <generic_sleepable_preload+0x190> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xea, 0x190, x86_l_190);
x86_l_f0:
	/* 0xf0: mov    eax,DWORD PTR [rbx+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_f3:
	/* 0xf3: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_f8:
	/* 0xf8: jne    1ee <generic_sleepable_preload+0x1ee> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf8, 0x1ee, x86_l_1ee);
x86_l_fe:
	/* 0xfe: mov    eax,DWORD PTR [rbx+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_101:
	/* 0x101: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_106:
	/* 0x106: jne    24c <generic_sleepable_preload+0x24c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x106, 0x24c, x86_l_24c);
x86_l_10c:
	/* 0x10c: mov    eax,DWORD PTR [rbx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_10f:
	/* 0x10f: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_114:
	/* 0x114: jne    2aa <generic_sleepable_preload+0x2aa> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x114, 0x2aa, x86_l_2aa);
x86_l_11a:
	/* 0x11a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_11c:
	/* 0x11c: add    rsp,0x98 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 152ULL);
x86_l_123:
	/* 0x123: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_124:
	/* 0x124: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_126:
	/* 0x126: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_128:
	/* 0x128: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_12a:
	/* 0x12a: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_12c:
	/* 0x12c: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_12d:
	/* 0x12d: jmp    16b5 <generic_sleepable_preload+0x16b5> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_132:
	/* 0x132: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_134:
	/* 0x134: js     30a <generic_sleepable_preload+0x30a> */
	X86_SIM_X86_JCC(X86_CC_S, 0x134, 0x30a, x86_l_30a);
x86_l_13a:
	/* 0x13a: movzx  ecx,BYTE PTR [rbx+0x211] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 529ULL);
x86_l_141:
	/* 0x141: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_143:
	/* 0x143: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_146:
	/* 0x146: jg     4fe <generic_sleepable_preload+0x4fe> */
	X86_SIM_X86_JCC(X86_CC_G, 0x146, 0x4fe, x86_l_4fe);
x86_l_14c:
	/* 0x14c: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_14f:
	/* 0x14f: je     a0e <generic_sleepable_preload+0xa0e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14f, 0xa0e, x86_l_a0e);
x86_l_155:
	/* 0x155: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_158:
	/* 0x158: jne    b73 <generic_sleepable_preload+0xb73> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x158, 0xb73, x86_l_b73);
x86_l_15e:
	/* 0x15e: mov    edx,DWORD PTR [rbx+0x208] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_164:
	/* 0x164: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_16a:
	/* 0x16a: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_16d:
	/* 0x16d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_170:
	/* 0x170: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_175:
	/* 0x175: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_17a:
	/* 0x17a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_17f:
	/* 0x17f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_181:
	/* 0x181: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_183:
	/* 0x183: je     a19 <generic_sleepable_preload+0xa19> */
	X86_SIM_X86_JCC(X86_CC_E, 0x183, 0xa19, x86_l_a19);
x86_l_189:
	/* 0x189: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18b:
	/* 0x18b: jmp    b73 <generic_sleepable_preload+0xb73> */
	X86_SIM_X86_JMP(0x18b, 0xb73, x86_l_b73);
x86_l_190:
	/* 0x190: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_192:
	/* 0x192: js     36e <generic_sleepable_preload+0x36e> */
	X86_SIM_X86_JCC(X86_CC_S, 0x192, 0x36e, x86_l_36e);
x86_l_198:
	/* 0x198: movzx  ecx,BYTE PTR [rbx+0x229] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 553ULL);
x86_l_19f:
	/* 0x19f: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1a1:
	/* 0x1a1: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1a4:
	/* 0x1a4: jg     5c1 <generic_sleepable_preload+0x5c1> */
	X86_SIM_X86_JCC(X86_CC_G, 0x1a4, 0x5c1, x86_l_5c1);
x86_l_1aa:
	/* 0x1aa: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1ad:
	/* 0x1ad: je     a40 <generic_sleepable_preload+0xa40> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1ad, 0xa40, x86_l_a40);
x86_l_1b3:
	/* 0x1b3: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1b6:
	/* 0x1b6: jne    ca5 <generic_sleepable_preload+0xca5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1b6, 0xca5, x86_l_ca5);
x86_l_1bc:
	/* 0x1bc: mov    edx,DWORD PTR [rbx+0x220] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 544ULL);
x86_l_1c2:
	/* 0x1c2: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1c8:
	/* 0x1c8: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1cb:
	/* 0x1cb: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1ce:
	/* 0x1ce: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_1d3:
	/* 0x1d3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1d8:
	/* 0x1d8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1dd:
	/* 0x1dd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1df:
	/* 0x1df: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1e1:
	/* 0x1e1: je     a4b <generic_sleepable_preload+0xa4b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1e1, 0xa4b, x86_l_a4b);
x86_l_1e7:
	/* 0x1e7: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e9:
	/* 0x1e9: jmp    ca5 <generic_sleepable_preload+0xca5> */
	X86_SIM_X86_JMP(0x1e9, 0xca5, x86_l_ca5);
x86_l_1ee:
	/* 0x1ee: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1f0:
	/* 0x1f0: js     3d2 <generic_sleepable_preload+0x3d2> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1f0, 0x3d2, x86_l_3d2);
x86_l_1f6:
	/* 0x1f6: movzx  ecx,BYTE PTR [rbx+0x241] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 577ULL);
x86_l_1fd:
	/* 0x1fd: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1ff:
	/* 0x1ff: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_202:
	/* 0x202: jg     635 <generic_sleepable_preload+0x635> */
	X86_SIM_X86_JCC(X86_CC_G, 0x202, 0x635, x86_l_635);
x86_l_208:
	/* 0x208: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_20b:
	/* 0x20b: je     a76 <generic_sleepable_preload+0xa76> */
	X86_SIM_X86_JCC(X86_CC_E, 0x20b, 0xa76, x86_l_a76);
x86_l_211:
	/* 0x211: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_214:
	/* 0x214: jne    dd7 <generic_sleepable_preload+0xdd7> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x214, 0xdd7, x86_l_dd7);
x86_l_21a:
	/* 0x21a: mov    edx,DWORD PTR [rbx+0x238] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 568ULL);
x86_l_220:
	/* 0x220: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_226:
	/* 0x226: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_229:
	/* 0x229: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_22c:
	/* 0x22c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_231:
	/* 0x231: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_236:
	/* 0x236: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_23b:
	/* 0x23b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_23d:
	/* 0x23d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_23f:
	/* 0x23f: je     a81 <generic_sleepable_preload+0xa81> */
	X86_SIM_X86_JCC(X86_CC_E, 0x23f, 0xa81, x86_l_a81);
x86_l_245:
	/* 0x245: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_247:
	/* 0x247: jmp    dd7 <generic_sleepable_preload+0xdd7> */
	X86_SIM_X86_JMP(0x247, 0xdd7, x86_l_dd7);
x86_l_24c:
	/* 0x24c: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_24e:
	/* 0x24e: js     436 <generic_sleepable_preload+0x436> */
	X86_SIM_X86_JCC(X86_CC_S, 0x24e, 0x436, x86_l_436);
x86_l_254:
	/* 0x254: movzx  ecx,BYTE PTR [rbx+0x259] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 601ULL);
x86_l_25b:
	/* 0x25b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_25d:
	/* 0x25d: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_260:
	/* 0x260: jg     6a9 <generic_sleepable_preload+0x6a9> */
	X86_SIM_X86_JCC(X86_CC_G, 0x260, 0x6a9, x86_l_6a9);
x86_l_266:
	/* 0x266: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_269:
	/* 0x269: je     aac <generic_sleepable_preload+0xaac> */
	X86_SIM_X86_JCC(X86_CC_E, 0x269, 0xaac, x86_l_aac);
x86_l_26f:
	/* 0x26f: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_272:
	/* 0x272: jne    f09 <generic_sleepable_preload+0xf09> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x272, 0xf09, x86_l_f09);
x86_l_278:
	/* 0x278: mov    edx,DWORD PTR [rbx+0x250] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 592ULL);
x86_l_27e:
	/* 0x27e: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_284:
	/* 0x284: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_287:
	/* 0x287: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_28a:
	/* 0x28a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_28f:
	/* 0x28f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_294:
	/* 0x294: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_299:
	/* 0x299: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_29b:
	/* 0x29b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_29d:
	/* 0x29d: je     ab7 <generic_sleepable_preload+0xab7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x29d, 0xab7, x86_l_ab7);
x86_l_2a3:
	/* 0x2a3: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2a5:
	/* 0x2a5: jmp    f09 <generic_sleepable_preload+0xf09> */
	X86_SIM_X86_JMP(0x2a5, 0xf09, x86_l_f09);
x86_l_2aa:
	/* 0x2aa: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_2ac:
	/* 0x2ac: js     49a <generic_sleepable_preload+0x49a> */
	X86_SIM_X86_JCC(X86_CC_S, 0x2ac, 0x49a, x86_l_49a);
x86_l_2b2:
	/* 0x2b2: movzx  ecx,BYTE PTR [rbx+0x271] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 625ULL);
x86_l_2b9:
	/* 0x2b9: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2bb:
	/* 0x2bb: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2be:
	/* 0x2be: jg     71d <generic_sleepable_preload+0x71d> */
	X86_SIM_X86_JCC(X86_CC_G, 0x2be, 0x71d, x86_l_71d);
x86_l_2c4:
	/* 0x2c4: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2c7:
	/* 0x2c7: je     ae2 <generic_sleepable_preload+0xae2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2c7, 0xae2, x86_l_ae2);
x86_l_2cd:
	/* 0x2cd: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2d0:
	/* 0x2d0: jne    103d <generic_sleepable_preload+0x103d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2d0, 0x103d, x86_l_103d);
x86_l_2d6:
	/* 0x2d6: mov    eax,DWORD PTR [rbx+0x268] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 616ULL);
x86_l_2dc:
	/* 0x2dc: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2e1:
	/* 0x2e1: add    r14,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2e4:
	/* 0x2e4: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2e7:
	/* 0x2e7: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_2ec:
	/* 0x2ec: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2f1:
	/* 0x2f1: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2f6:
	/* 0x2f6: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_2f9:
	/* 0x2f9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2fb:
	/* 0x2fb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2fd:
	/* 0x2fd: je     aed <generic_sleepable_preload+0xaed> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2fd, 0xaed, x86_l_aed);
x86_l_303:
	/* 0x303: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_305:
	/* 0x305: jmp    103d <generic_sleepable_preload+0x103d> */
	X86_SIM_X86_JMP(0x305, 0x103d, x86_l_103d);
x86_l_30a:
	/* 0x30a: movzx  eax,BYTE PTR [rbx+0x2c2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 706ULL);
x86_l_311:
	/* 0x311: movzx  ecx,WORD PTR [rbx+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 704ULL);
x86_l_318:
	/* 0x318: rorx   ecx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_31e:
	/* 0x31e: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_321:
	/* 0x321: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_324:
	/* 0x324: jle    793 <generic_sleepable_preload+0x793> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x324, 0x793, x86_l_793);
x86_l_32a:
	/* 0x32a: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_32d:
	/* 0x32d: jle    86a <generic_sleepable_preload+0x86a> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x32d, 0x86a, x86_l_86a);
x86_l_333:
	/* 0x333: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_336:
	/* 0x336: jle    12d2 <generic_sleepable_preload+0x12d2> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x336, 0x12d2, x86_l_12d2);
x86_l_33c:
	/* 0x33c: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_344:
	/* 0x344: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_347:
	/* 0x347: je     12e9 <generic_sleepable_preload+0x12e9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x347, 0x12e9, x86_l_12e9);
x86_l_34d:
	/* 0x34d: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_352:
	/* 0x352: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_355:
	/* 0x355: je     12e9 <generic_sleepable_preload+0x12e9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x355, 0x12e9, x86_l_12e9);
x86_l_35b:
	/* 0x35b: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_35e:
	/* 0x35e: jne    12fc <generic_sleepable_preload+0x12fc> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x35e, 0x12fc, x86_l_12fc);
x86_l_364:
	/* 0x364: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_369:
	/* 0x369: jmp    12e9 <generic_sleepable_preload+0x12e9> */
	X86_SIM_X86_JMP(0x369, 0x12e9, x86_l_12e9);
x86_l_36e:
	/* 0x36e: movzx  eax,BYTE PTR [rbx+0x2c6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 710ULL);
x86_l_375:
	/* 0x375: movzx  ecx,WORD PTR [rbx+0x2c4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 708ULL);
x86_l_37c:
	/* 0x37c: rorx   ecx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_382:
	/* 0x382: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_385:
	/* 0x385: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_388:
	/* 0x388: jle    7c1 <generic_sleepable_preload+0x7c1> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x388, 0x7c1, x86_l_7c1);
x86_l_38e:
	/* 0x38e: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_391:
	/* 0x391: jle    894 <generic_sleepable_preload+0x894> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x391, 0x894, x86_l_894);
x86_l_397:
	/* 0x397: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_39a:
	/* 0x39a: jle    138d <generic_sleepable_preload+0x138d> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x39a, 0x138d, x86_l_138d);
x86_l_3a0:
	/* 0x3a0: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_3a8:
	/* 0x3a8: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_3ab:
	/* 0x3ab: je     141c <generic_sleepable_preload+0x141c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3ab, 0x141c, x86_l_141c);
x86_l_3b1:
	/* 0x3b1: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3b6:
	/* 0x3b6: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_3b9:
	/* 0x3b9: je     141c <generic_sleepable_preload+0x141c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3b9, 0x141c, x86_l_141c);
x86_l_3bf:
	/* 0x3bf: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_3c4:
	/* 0x3c4: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_3c7:
	/* 0x3c7: je     141c <generic_sleepable_preload+0x141c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3c7, 0x141c, x86_l_141c);
x86_l_3cd:
	/* 0x3cd: jmp    142f <generic_sleepable_preload+0x142f> */
	X86_SIM_X86_JMP(0x3cd, 0x142f, x86_l_142f);
x86_l_3d2:
	/* 0x3d2: movzx  eax,BYTE PTR [rbx+0x2ca] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 714ULL);
x86_l_3d9:
	/* 0x3d9: movzx  ecx,WORD PTR [rbx+0x2c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 712ULL);
x86_l_3e0:
	/* 0x3e0: rorx   ecx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_3e6:
	/* 0x3e6: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3e9:
	/* 0x3e9: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_3ec:
	/* 0x3ec: jle    7ec <generic_sleepable_preload+0x7ec> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x3ec, 0x7ec, x86_l_7ec);
x86_l_3f2:
	/* 0x3f2: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_3f5:
	/* 0x3f5: jle    8be <generic_sleepable_preload+0x8be> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x3f5, 0x8be, x86_l_8be);
x86_l_3fb:
	/* 0x3fb: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_3fe:
	/* 0x3fe: jle    13ad <generic_sleepable_preload+0x13ad> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x3fe, 0x13ad, x86_l_13ad);
x86_l_404:
	/* 0x404: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_40c:
	/* 0x40c: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_40f:
	/* 0x40f: je     14c3 <generic_sleepable_preload+0x14c3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x40f, 0x14c3, x86_l_14c3);
x86_l_415:
	/* 0x415: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_41a:
	/* 0x41a: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_41d:
	/* 0x41d: je     14c3 <generic_sleepable_preload+0x14c3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x41d, 0x14c3, x86_l_14c3);
x86_l_423:
	/* 0x423: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_428:
	/* 0x428: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_42b:
	/* 0x42b: je     14c3 <generic_sleepable_preload+0x14c3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x42b, 0x14c3, x86_l_14c3);
x86_l_431:
	/* 0x431: jmp    14d6 <generic_sleepable_preload+0x14d6> */
	X86_SIM_X86_JMP(0x431, 0x14d6, x86_l_14d6);
x86_l_436:
	/* 0x436: movzx  eax,BYTE PTR [rbx+0x2ce] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 718ULL);
x86_l_43d:
	/* 0x43d: movzx  ecx,WORD PTR [rbx+0x2cc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 716ULL);
x86_l_444:
	/* 0x444: rorx   ecx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_44a:
	/* 0x44a: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_44d:
	/* 0x44d: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_450:
	/* 0x450: jle    817 <generic_sleepable_preload+0x817> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x450, 0x817, x86_l_817);
x86_l_456:
	/* 0x456: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_459:
	/* 0x459: jle    8e8 <generic_sleepable_preload+0x8e8> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x459, 0x8e8, x86_l_8e8);
x86_l_45f:
	/* 0x45f: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_462:
	/* 0x462: jle    13d1 <generic_sleepable_preload+0x13d1> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x462, 0x13d1, x86_l_13d1);
x86_l_468:
	/* 0x468: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_470:
	/* 0x470: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_473:
	/* 0x473: je     156a <generic_sleepable_preload+0x156a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x473, 0x156a, x86_l_156a);
x86_l_479:
	/* 0x479: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_47e:
	/* 0x47e: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_481:
	/* 0x481: je     156a <generic_sleepable_preload+0x156a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x481, 0x156a, x86_l_156a);
x86_l_487:
	/* 0x487: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_48c:
	/* 0x48c: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_48f:
	/* 0x48f: je     156a <generic_sleepable_preload+0x156a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x48f, 0x156a, x86_l_156a);
x86_l_495:
	/* 0x495: jmp    157d <generic_sleepable_preload+0x157d> */
	X86_SIM_X86_JMP(0x495, 0x157d, x86_l_157d);
x86_l_49a:
	/* 0x49a: movzx  eax,BYTE PTR [rbx+0x2d2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 722ULL);
x86_l_4a1:
	/* 0x4a1: movzx  ecx,WORD PTR [rbx+0x2d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 720ULL);
x86_l_4a8:
	/* 0x4a8: rorx   ecx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_4ae:
	/* 0x4ae: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4b1:
	/* 0x4b1: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_4b4:
	/* 0x4b4: jle    842 <generic_sleepable_preload+0x842> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x4b4, 0x842, x86_l_842);
x86_l_4ba:
	/* 0x4ba: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_4bd:
	/* 0x4bd: jle    912 <generic_sleepable_preload+0x912> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x4bd, 0x912, x86_l_912);
x86_l_4c3:
	/* 0x4c3: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_4c6:
	/* 0x4c6: jle    13f5 <generic_sleepable_preload+0x13f5> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x4c6, 0x13f5, x86_l_13f5);
x86_l_4cc:
	/* 0x4cc: mov    rbp,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_4d4:
	/* 0x4d4: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_4d7:
	/* 0x4d7: je     1611 <generic_sleepable_preload+0x1611> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4d7, 0x1611, x86_l_1611);
x86_l_4dd:
	/* 0x4dd: mov    rbp,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4e2:
	/* 0x4e2: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_4e5:
	/* 0x4e5: je     1611 <generic_sleepable_preload+0x1611> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4e5, 0x1611, x86_l_1611);
x86_l_4eb:
	/* 0x4eb: mov    rbp,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_4f0:
	/* 0x4f0: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_4f3:
	/* 0x4f3: je     1611 <generic_sleepable_preload+0x1611> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4f3, 0x1611, x86_l_1611);
x86_l_4f9:
	/* 0x4f9: jmp    1625 <generic_sleepable_preload+0x1625> */
	X86_SIM_X86_JMP(0x4f9, 0x1625, x86_l_1625);
x86_l_4fe:
	/* 0x4fe: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_501:
	/* 0x501: je     b18 <generic_sleepable_preload+0xb18> */
	X86_SIM_X86_JCC(X86_CC_E, 0x501, 0xb18, x86_l_b18);
x86_l_507:
	/* 0x507: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_50a:
	/* 0x50a: jne    b73 <generic_sleepable_preload+0xb73> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x50a, 0xb73, x86_l_b73);
x86_l_510:
	/* 0x510: mov    edx,DWORD PTR [rbx+0x208] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_516:
	/* 0x516: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_51c:
	/* 0x51c: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_51f:
	/* 0x51f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_522:
	/* 0x522: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_527:
	/* 0x527: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_52c:
	/* 0x52c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_531:
	/* 0x531: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_533:
	/* 0x533: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_535:
	/* 0x535: jne    b71 <generic_sleepable_preload+0xb71> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x535, 0xb71, x86_l_b71);
x86_l_53b:
	/* 0x53b: mov    edx,DWORD PTR [rbx+0x20c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 524ULL);
x86_l_541:
	/* 0x541: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_547:
	/* 0x547: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_54a:
	/* 0x54a: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_54f:
	/* 0x54f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_554:
	/* 0x554: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_559:
	/* 0x559: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_55e:
	/* 0x55e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_560:
	/* 0x560: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_562:
	/* 0x562: jne    b71 <generic_sleepable_preload+0xb71> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x562, 0xb71, x86_l_b71);
x86_l_568:
	/* 0x568: movzx  eax,BYTE PTR [rbx+0x213] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 531ULL);
x86_l_56f:
	/* 0x56f: shlx   rax,QWORD PTR [rsp+0x8],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_576:
	/* 0x576: mov    rcx,QWORD PTR [rbx+0x200] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 512ULL);
x86_l_57d:
	/* 0x57d: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_581:
	/* 0x581: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_584:
	/* 0x584: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_587:
	/* 0x587: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_58c:
	/* 0x58c: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_591:
	/* 0x591: movzx  ecx,BYTE PTR [rbx+0x213] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 531ULL);
x86_l_598:
	/* 0x598: shlx   rcx,QWORD PTR [rsp+0x8],rcx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_59f:
	/* 0x59f: mov    rdx,QWORD PTR [rbx+0x200] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 512ULL);
x86_l_5a6:
	/* 0x5a6: add    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_5aa:
	/* 0x5aa: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5ad:
	/* 0x5ad: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5b2:
	/* 0x5b2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b4:
	/* 0x5b4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5b6:
	/* 0x5b6: jne    b71 <generic_sleepable_preload+0xb71> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x5b6, 0xb71, x86_l_b71);
x86_l_5bc:
	/* 0x5bc: jmp    a19 <generic_sleepable_preload+0xa19> */
	X86_SIM_X86_JMP(0x5bc, 0xa19, x86_l_a19);
x86_l_5c1:
	/* 0x5c1: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_5c4:
	/* 0x5c4: je     bfb <generic_sleepable_preload+0xbfb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5c4, 0xbfb, x86_l_bfb);
x86_l_5ca:
	/* 0x5ca: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_5cd:
	/* 0x5cd: jne    ca5 <generic_sleepable_preload+0xca5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x5cd, 0xca5, x86_l_ca5);
x86_l_5d3:
	/* 0x5d3: mov    edx,DWORD PTR [rbx+0x220] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 544ULL);
x86_l_5d9:
	/* 0x5d9: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5df:
	/* 0x5df: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5e2:
	/* 0x5e2: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5e5:
	/* 0x5e5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_5ea:
	/* 0x5ea: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5ef:
	/* 0x5ef: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5f4:
	/* 0x5f4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5f6:
	/* 0x5f6: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5f8:
	/* 0x5f8: jne    ca3 <generic_sleepable_preload+0xca3> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x5f8, 0xca3, x86_l_ca3);
x86_l_5fe:
	/* 0x5fe: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_602:
	/* 0x602: add    rcx,QWORD PTR [rbx+0x218] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 536ULL);
x86_l_609:
	/* 0x609: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_60c:
	/* 0x60c: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_611:
	/* 0x611: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_616:
	/* 0x616: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_61a:
	/* 0x61a: add    rdx,QWORD PTR [rbx+0x218] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 536ULL);
x86_l_621:
	/* 0x621: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_626:
	/* 0x626: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_628:
	/* 0x628: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_62a:
	/* 0x62a: jne    ca3 <generic_sleepable_preload+0xca3> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x62a, 0xca3, x86_l_ca3);
x86_l_630:
	/* 0x630: jmp    a4b <generic_sleepable_preload+0xa4b> */
	X86_SIM_X86_JMP(0x630, 0xa4b, x86_l_a4b);
x86_l_635:
	/* 0x635: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_638:
	/* 0x638: je     d2d <generic_sleepable_preload+0xd2d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x638, 0xd2d, x86_l_d2d);
x86_l_63e:
	/* 0x63e: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_641:
	/* 0x641: jne    dd7 <generic_sleepable_preload+0xdd7> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x641, 0xdd7, x86_l_dd7);
x86_l_647:
	/* 0x647: mov    edx,DWORD PTR [rbx+0x238] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 568ULL);
x86_l_64d:
	/* 0x64d: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_653:
	/* 0x653: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_656:
	/* 0x656: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_659:
	/* 0x659: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_65e:
	/* 0x65e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_663:
	/* 0x663: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_668:
	/* 0x668: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_66a:
	/* 0x66a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_66c:
	/* 0x66c: jne    dd5 <generic_sleepable_preload+0xdd5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x66c, 0xdd5, x86_l_dd5);
x86_l_672:
	/* 0x672: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_676:
	/* 0x676: add    rcx,QWORD PTR [rbx+0x230] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 560ULL);
x86_l_67d:
	/* 0x67d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_680:
	/* 0x680: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_685:
	/* 0x685: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_68a:
	/* 0x68a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_68e:
	/* 0x68e: add    rdx,QWORD PTR [rbx+0x230] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 560ULL);
x86_l_695:
	/* 0x695: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_69a:
	/* 0x69a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_69c:
	/* 0x69c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_69e:
	/* 0x69e: jne    dd5 <generic_sleepable_preload+0xdd5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x69e, 0xdd5, x86_l_dd5);
x86_l_6a4:
	/* 0x6a4: jmp    a81 <generic_sleepable_preload+0xa81> */
	X86_SIM_X86_JMP(0x6a4, 0xa81, x86_l_a81);
x86_l_6a9:
	/* 0x6a9: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_6ac:
	/* 0x6ac: je     e5f <generic_sleepable_preload+0xe5f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6ac, 0xe5f, x86_l_e5f);
x86_l_6b2:
	/* 0x6b2: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_6b5:
	/* 0x6b5: jne    f09 <generic_sleepable_preload+0xf09> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x6b5, 0xf09, x86_l_f09);
x86_l_6bb:
	/* 0x6bb: mov    edx,DWORD PTR [rbx+0x250] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 592ULL);
x86_l_6c1:
	/* 0x6c1: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_6c7:
	/* 0x6c7: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_6ca:
	/* 0x6ca: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_6cd:
	/* 0x6cd: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_6d2:
	/* 0x6d2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_6d7:
	/* 0x6d7: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_6dc:
	/* 0x6dc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_6de:
	/* 0x6de: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_6e0:
	/* 0x6e0: jne    f07 <generic_sleepable_preload+0xf07> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x6e0, 0xf07, x86_l_f07);
x86_l_6e6:
	/* 0x6e6: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_6ea:
	/* 0x6ea: add    rcx,QWORD PTR [rbx+0x248] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 584ULL);
x86_l_6f1:
	/* 0x6f1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_6f4:
	/* 0x6f4: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_6f9:
	/* 0x6f9: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_6fe:
	/* 0x6fe: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_702:
	/* 0x702: add    rdx,QWORD PTR [rbx+0x248] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 584ULL);
x86_l_709:
	/* 0x709: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_70e:
	/* 0x70e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_710:
	/* 0x710: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_712:
	/* 0x712: jne    f07 <generic_sleepable_preload+0xf07> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x712, 0xf07, x86_l_f07);
x86_l_718:
	/* 0x718: jmp    ab7 <generic_sleepable_preload+0xab7> */
	X86_SIM_X86_JMP(0x718, 0xab7, x86_l_ab7);
x86_l_71d:
	/* 0x71d: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_720:
	/* 0x720: je     f91 <generic_sleepable_preload+0xf91> */
	X86_SIM_X86_JCC(X86_CC_E, 0x720, 0xf91, x86_l_f91);
x86_l_726:
	/* 0x726: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_729:
	/* 0x729: jne    103d <generic_sleepable_preload+0x103d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x729, 0x103d, x86_l_103d);
x86_l_72f:
	/* 0x72f: mov    eax,DWORD PTR [rbx+0x268] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 616ULL);
x86_l_735:
	/* 0x735: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_73a:
	/* 0x73a: add    r14,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_73d:
	/* 0x73d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_740:
	/* 0x740: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_745:
	/* 0x745: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_74a:
	/* 0x74a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_74f:
	/* 0x74f: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_752:
	/* 0x752: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_754:
	/* 0x754: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_756:
	/* 0x756: jne    103b <generic_sleepable_preload+0x103b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x756, 0x103b, x86_l_103b);
x86_l_75c:
	/* 0x75c: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_760:
	/* 0x760: add    rcx,QWORD PTR [rbx+0x260] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 608ULL);
x86_l_767:
	/* 0x767: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_76a:
	/* 0x76a: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_76f:
	/* 0x76f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_774:
	/* 0x774: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_778:
	/* 0x778: add    rdx,QWORD PTR [rbx+0x260] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 608ULL);
x86_l_77f:
	/* 0x77f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_784:
	/* 0x784: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_786:
	/* 0x786: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_788:
	/* 0x788: jne    103b <generic_sleepable_preload+0x103b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x788, 0x103b, x86_l_103b);
x86_l_78e:
	/* 0x78e: jmp    aed <generic_sleepable_preload+0xaed> */
	X86_SIM_X86_JMP(0x78e, 0xaed, x86_l_aed);
x86_l_793:
	/* 0x793: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_796:
	/* 0x796: jg     93c <generic_sleepable_preload+0x93c> */
	X86_SIM_X86_JCC(X86_CC_G, 0x796, 0x93c, x86_l_93c);
x86_l_79c:
	/* 0x79c: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_79f:
	/* 0x79f: jg     1188 <generic_sleepable_preload+0x1188> */
	X86_SIM_X86_JCC(X86_CC_G, 0x79f, 0x1188, x86_l_1188);
x86_l_7a5:
	/* 0x7a5: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_7a8:
	/* 0x7a8: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_7aa:
	/* 0x7aa: je     12e9 <generic_sleepable_preload+0x12e9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7aa, 0x12e9, x86_l_12e9);
x86_l_7b0:
	/* 0x7b0: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_7b3:
	/* 0x7b3: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_7b6:
	/* 0x7b6: je     12e9 <generic_sleepable_preload+0x12e9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7b6, 0x12e9, x86_l_12e9);
x86_l_7bc:
	/* 0x7bc: jmp    12fc <generic_sleepable_preload+0x12fc> */
	X86_SIM_X86_JMP(0x7bc, 0x12fc, x86_l_12fc);
x86_l_7c1:
	/* 0x7c1: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_7c4:
	/* 0x7c4: jg     966 <generic_sleepable_preload+0x966> */
	X86_SIM_X86_JCC(X86_CC_G, 0x7c4, 0x966, x86_l_966);
x86_l_7ca:
	/* 0x7ca: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_7cd:
	/* 0x7cd: jg     11a9 <generic_sleepable_preload+0x11a9> */
	X86_SIM_X86_JCC(X86_CC_G, 0x7cd, 0x11a9, x86_l_11a9);
x86_l_7d3:
	/* 0x7d3: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_7d5:
	/* 0x7d5: je     1419 <generic_sleepable_preload+0x1419> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7d5, 0x1419, x86_l_1419);
x86_l_7db:
	/* 0x7db: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_7de:
	/* 0x7de: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_7e1:
	/* 0x7e1: je     141c <generic_sleepable_preload+0x141c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7e1, 0x141c, x86_l_141c);
x86_l_7e7:
	/* 0x7e7: jmp    142f <generic_sleepable_preload+0x142f> */
	X86_SIM_X86_JMP(0x7e7, 0x142f, x86_l_142f);
x86_l_7ec:
	/* 0x7ec: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_7ef:
	/* 0x7ef: jg     990 <generic_sleepable_preload+0x990> */
	X86_SIM_X86_JCC(X86_CC_G, 0x7ef, 0x990, x86_l_990);
x86_l_7f5:
	/* 0x7f5: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_7f8:
	/* 0x7f8: jg     11ca <generic_sleepable_preload+0x11ca> */
	X86_SIM_X86_JCC(X86_CC_G, 0x7f8, 0x11ca, x86_l_11ca);
x86_l_7fe:
	/* 0x7fe: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_800:
	/* 0x800: je     14c0 <generic_sleepable_preload+0x14c0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x800, 0x14c0, x86_l_14c0);
x86_l_806:
	/* 0x806: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_809:
	/* 0x809: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_80c:
	/* 0x80c: je     14c3 <generic_sleepable_preload+0x14c3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x80c, 0x14c3, x86_l_14c3);
x86_l_812:
	/* 0x812: jmp    14d6 <generic_sleepable_preload+0x14d6> */
	X86_SIM_X86_JMP(0x812, 0x14d6, x86_l_14d6);
x86_l_817:
	/* 0x817: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_81a:
	/* 0x81a: jg     9ba <generic_sleepable_preload+0x9ba> */
	X86_SIM_X86_JCC(X86_CC_G, 0x81a, 0x9ba, x86_l_9ba);
x86_l_820:
	/* 0x820: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_823:
	/* 0x823: jg     11eb <generic_sleepable_preload+0x11eb> */
	X86_SIM_X86_JCC(X86_CC_G, 0x823, 0x11eb, x86_l_11eb);
x86_l_829:
	/* 0x829: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_82b:
	/* 0x82b: je     1567 <generic_sleepable_preload+0x1567> */
	X86_SIM_X86_JCC(X86_CC_E, 0x82b, 0x1567, x86_l_1567);
x86_l_831:
	/* 0x831: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_834:
	/* 0x834: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_837:
	/* 0x837: je     156a <generic_sleepable_preload+0x156a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x837, 0x156a, x86_l_156a);
x86_l_83d:
	/* 0x83d: jmp    157d <generic_sleepable_preload+0x157d> */
	X86_SIM_X86_JMP(0x83d, 0x157d, x86_l_157d);
x86_l_842:
	/* 0x842: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_845:
	/* 0x845: jg     9e4 <generic_sleepable_preload+0x9e4> */
	X86_SIM_X86_JCC(X86_CC_G, 0x845, 0x9e4, x86_l_9e4);
x86_l_84b:
	/* 0x84b: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_84e:
	/* 0x84e: jg     120c <generic_sleepable_preload+0x120c> */
	X86_SIM_X86_JCC(X86_CC_G, 0x84e, 0x120c, x86_l_120c);
x86_l_854:
	/* 0x854: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_856:
	/* 0x856: je     160e <generic_sleepable_preload+0x160e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x856, 0x160e, x86_l_160e);
x86_l_85c:
	/* 0x85c: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_85f:
	/* 0x85f: je     1611 <generic_sleepable_preload+0x1611> */
	X86_SIM_X86_JCC(X86_CC_E, 0x85f, 0x1611, x86_l_1611);
x86_l_865:
	/* 0x865: jmp    1625 <generic_sleepable_preload+0x1625> */
	X86_SIM_X86_JMP(0x865, 0x1625, x86_l_1625);
x86_l_86a:
	/* 0x86a: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_86d:
	/* 0x86d: jg     10e3 <generic_sleepable_preload+0x10e3> */
	X86_SIM_X86_JCC(X86_CC_G, 0x86d, 0x10e3, x86_l_10e3);
x86_l_873:
	/* 0x873: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_878:
	/* 0x878: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_87b:
	/* 0x87b: je     12e9 <generic_sleepable_preload+0x12e9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x87b, 0x12e9, x86_l_12e9);
x86_l_881:
	/* 0x881: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_886:
	/* 0x886: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_889:
	/* 0x889: je     12e9 <generic_sleepable_preload+0x12e9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x889, 0x12e9, x86_l_12e9);
x86_l_88f:
	/* 0x88f: jmp    12fc <generic_sleepable_preload+0x12fc> */
	X86_SIM_X86_JMP(0x88f, 0x12fc, x86_l_12fc);
x86_l_894:
	/* 0x894: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_897:
	/* 0x897: jg     1104 <generic_sleepable_preload+0x1104> */
	X86_SIM_X86_JCC(X86_CC_G, 0x897, 0x1104, x86_l_1104);
x86_l_89d:
	/* 0x89d: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_8a2:
	/* 0x8a2: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_8a5:
	/* 0x8a5: je     141c <generic_sleepable_preload+0x141c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8a5, 0x141c, x86_l_141c);
x86_l_8ab:
	/* 0x8ab: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_8b0:
	/* 0x8b0: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_8b3:
	/* 0x8b3: je     141c <generic_sleepable_preload+0x141c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8b3, 0x141c, x86_l_141c);
x86_l_8b9:
	/* 0x8b9: jmp    142f <generic_sleepable_preload+0x142f> */
	X86_SIM_X86_JMP(0x8b9, 0x142f, x86_l_142f);
x86_l_8be:
	/* 0x8be: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_8c1:
	/* 0x8c1: jg     1125 <generic_sleepable_preload+0x1125> */
	X86_SIM_X86_JCC(X86_CC_G, 0x8c1, 0x1125, x86_l_1125);
x86_l_8c7:
	/* 0x8c7: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_8cc:
	/* 0x8cc: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_8cf:
	/* 0x8cf: je     14c3 <generic_sleepable_preload+0x14c3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8cf, 0x14c3, x86_l_14c3);
x86_l_8d5:
	/* 0x8d5: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_8da:
	/* 0x8da: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_8dd:
	/* 0x8dd: je     14c3 <generic_sleepable_preload+0x14c3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8dd, 0x14c3, x86_l_14c3);
x86_l_8e3:
	/* 0x8e3: jmp    14d6 <generic_sleepable_preload+0x14d6> */
	X86_SIM_X86_JMP(0x8e3, 0x14d6, x86_l_14d6);
x86_l_8e8:
	/* 0x8e8: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_8eb:
	/* 0x8eb: jg     1146 <generic_sleepable_preload+0x1146> */
	X86_SIM_X86_JCC(X86_CC_G, 0x8eb, 0x1146, x86_l_1146);
x86_l_8f1:
	/* 0x8f1: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_8f6:
	/* 0x8f6: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_8f9:
	/* 0x8f9: je     156a <generic_sleepable_preload+0x156a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8f9, 0x156a, x86_l_156a);
x86_l_8ff:
	/* 0x8ff: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_904:
	/* 0x904: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_907:
	/* 0x907: je     156a <generic_sleepable_preload+0x156a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x907, 0x156a, x86_l_156a);
x86_l_90d:
	/* 0x90d: jmp    157d <generic_sleepable_preload+0x157d> */
	X86_SIM_X86_JMP(0x90d, 0x157d, x86_l_157d);
x86_l_912:
	/* 0x912: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_915:
	/* 0x915: jg     1167 <generic_sleepable_preload+0x1167> */
	X86_SIM_X86_JCC(X86_CC_G, 0x915, 0x1167, x86_l_1167);
x86_l_91b:
	/* 0x91b: mov    rbp,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_920:
	/* 0x920: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_923:
	/* 0x923: je     1611 <generic_sleepable_preload+0x1611> */
	X86_SIM_X86_JCC(X86_CC_E, 0x923, 0x1611, x86_l_1611);
x86_l_929:
	/* 0x929: mov    rbp,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_92e:
	/* 0x92e: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_931:
	/* 0x931: je     1611 <generic_sleepable_preload+0x1611> */
	X86_SIM_X86_JCC(X86_CC_E, 0x931, 0x1611, x86_l_1611);
x86_l_937:
	/* 0x937: jmp    1625 <generic_sleepable_preload+0x1625> */
	X86_SIM_X86_JMP(0x937, 0x1625, x86_l_1625);
x86_l_93c:
	/* 0x93c: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_93f:
	/* 0x93f: jg     122d <generic_sleepable_preload+0x122d> */
	X86_SIM_X86_JCC(X86_CC_G, 0x93f, 0x122d, x86_l_122d);
x86_l_945:
	/* 0x945: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_94a:
	/* 0x94a: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_94d:
	/* 0x94d: je     12e9 <generic_sleepable_preload+0x12e9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x94d, 0x12e9, x86_l_12e9);
x86_l_953:
	/* 0x953: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_958:
	/* 0x958: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_95b:
	/* 0x95b: je     12e9 <generic_sleepable_preload+0x12e9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x95b, 0x12e9, x86_l_12e9);
x86_l_961:
	/* 0x961: jmp    12fc <generic_sleepable_preload+0x12fc> */
	X86_SIM_X86_JMP(0x961, 0x12fc, x86_l_12fc);
x86_l_966:
	/* 0x966: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_969:
	/* 0x969: jg     124e <generic_sleepable_preload+0x124e> */
	X86_SIM_X86_JCC(X86_CC_G, 0x969, 0x124e, x86_l_124e);
x86_l_96f:
	/* 0x96f: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_974:
	/* 0x974: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_977:
	/* 0x977: je     141c <generic_sleepable_preload+0x141c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x977, 0x141c, x86_l_141c);
x86_l_97d:
	/* 0x97d: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_982:
	/* 0x982: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_985:
	/* 0x985: je     141c <generic_sleepable_preload+0x141c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x985, 0x141c, x86_l_141c);
x86_l_98b:
	/* 0x98b: jmp    142f <generic_sleepable_preload+0x142f> */
	X86_SIM_X86_JMP(0x98b, 0x142f, x86_l_142f);
x86_l_990:
	/* 0x990: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_993:
	/* 0x993: jg     126f <generic_sleepable_preload+0x126f> */
	X86_SIM_X86_JCC(X86_CC_G, 0x993, 0x126f, x86_l_126f);
x86_l_999:
	/* 0x999: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_99e:
	/* 0x99e: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_9a1:
	/* 0x9a1: je     14c3 <generic_sleepable_preload+0x14c3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9a1, 0x14c3, x86_l_14c3);
x86_l_9a7:
	/* 0x9a7: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9ac:
	/* 0x9ac: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_9af:
	/* 0x9af: je     14c3 <generic_sleepable_preload+0x14c3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9af, 0x14c3, x86_l_14c3);
x86_l_9b5:
	/* 0x9b5: jmp    14d6 <generic_sleepable_preload+0x14d6> */
	X86_SIM_X86_JMP(0x9b5, 0x14d6, x86_l_14d6);
x86_l_9ba:
	/* 0x9ba: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_9bd:
	/* 0x9bd: jg     1290 <generic_sleepable_preload+0x1290> */
	X86_SIM_X86_JCC(X86_CC_G, 0x9bd, 0x1290, x86_l_1290);
x86_l_9c3:
	/* 0x9c3: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_9c8:
	/* 0x9c8: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_9cb:
	/* 0x9cb: je     156a <generic_sleepable_preload+0x156a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9cb, 0x156a, x86_l_156a);
x86_l_9d1:
	/* 0x9d1: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_9d6:
	/* 0x9d6: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_9d9:
	/* 0x9d9: je     156a <generic_sleepable_preload+0x156a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9d9, 0x156a, x86_l_156a);
x86_l_9df:
	/* 0x9df: jmp    157d <generic_sleepable_preload+0x157d> */
	X86_SIM_X86_JMP(0x9df, 0x157d, x86_l_157d);
x86_l_9e4:
	/* 0x9e4: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_9e7:
	/* 0x9e7: jg     12b1 <generic_sleepable_preload+0x12b1> */
	X86_SIM_X86_JCC(X86_CC_G, 0x9e7, 0x12b1, x86_l_12b1);
x86_l_9ed:
	/* 0x9ed: mov    rbp,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_9f2:
	/* 0x9f2: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_9f5:
	/* 0x9f5: je     1611 <generic_sleepable_preload+0x1611> */
	X86_SIM_X86_JCC(X86_CC_E, 0x9f5, 0x1611, x86_l_1611);
x86_l_9fb:
	/* 0x9fb: mov    rbp,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_a00:
	/* 0xa00: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_a03:
	/* 0xa03: je     1611 <generic_sleepable_preload+0x1611> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa03, 0x1611, x86_l_1611);
x86_l_a09:
	/* 0xa09: jmp    1625 <generic_sleepable_preload+0x1625> */
	X86_SIM_X86_JMP(0xa09, 0x1625, x86_l_1625);
x86_l_a0e:
	/* 0xa0e: mov    rax,QWORD PTR [rbx+0x200] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 512ULL);
x86_l_a15:
	/* 0xa15: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a19:
	/* 0xa19: movzx  eax,BYTE PTR [rbx+0x210] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 528ULL);
x86_l_a20:
	/* 0xa20: shlx   rcx,QWORD PTR [rsp],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((0ULL << 32) | X86_ALU_SHL));
x86_l_a26:
	/* 0xa26: cmp    BYTE PTR [rbx+0x212],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2276332666880ULL);
x86_l_a2d:
	/* 0xa2d: shrx   rdx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SHR);
x86_l_a32:
	/* 0xa32: sarx   rax,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RAX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SAR);
x86_l_a37:
	/* 0xa37: cmove  rax,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_a3b:
	/* 0xa3b: jmp    b73 <generic_sleepable_preload+0xb73> */
	X86_SIM_X86_JMP(0xa3b, 0xb73, x86_l_b73);
x86_l_a40:
	/* 0xa40: mov    rax,QWORD PTR [rbx+0x218] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 536ULL);
x86_l_a47:
	/* 0xa47: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a4b:
	/* 0xa4b: movzx  eax,BYTE PTR [rbx+0x228] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 552ULL);
x86_l_a52:
	/* 0xa52: shlx   rcx,QWORD PTR [rsp],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((0ULL << 32) | X86_ALU_SHL));
x86_l_a58:
	/* 0xa58: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a5c:
	/* 0xa5c: cmp    BYTE PTR [rbx+0x22a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2379411881984ULL);
x86_l_a63:
	/* 0xa63: shrx   rdx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SHR);
x86_l_a68:
	/* 0xa68: sarx   rax,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RAX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SAR);
x86_l_a6d:
	/* 0xa6d: cmove  rax,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_a71:
	/* 0xa71: jmp    ca5 <generic_sleepable_preload+0xca5> */
	X86_SIM_X86_JMP(0xa71, 0xca5, x86_l_ca5);
x86_l_a76:
	/* 0xa76: mov    rax,QWORD PTR [rbx+0x230] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 560ULL);
x86_l_a7d:
	/* 0xa7d: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a81:
	/* 0xa81: movzx  eax,BYTE PTR [rbx+0x240] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 576ULL);
x86_l_a88:
	/* 0xa88: shlx   rcx,QWORD PTR [rsp],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((0ULL << 32) | X86_ALU_SHL));
x86_l_a8e:
	/* 0xa8e: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a92:
	/* 0xa92: cmp    BYTE PTR [rbx+0x242],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2482491097088ULL);
x86_l_a99:
	/* 0xa99: shrx   rdx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SHR);
x86_l_a9e:
	/* 0xa9e: sarx   rax,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RAX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SAR);
x86_l_aa3:
	/* 0xaa3: cmove  rax,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_aa7:
	/* 0xaa7: jmp    dd7 <generic_sleepable_preload+0xdd7> */
	X86_SIM_X86_JMP(0xaa7, 0xdd7, x86_l_dd7);
x86_l_aac:
	/* 0xaac: mov    rax,QWORD PTR [rbx+0x248] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584ULL);
x86_l_ab3:
	/* 0xab3: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ab7:
	/* 0xab7: movzx  eax,BYTE PTR [rbx+0x258] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 600ULL);
x86_l_abe:
	/* 0xabe: shlx   rcx,QWORD PTR [rsp],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((0ULL << 32) | X86_ALU_SHL));
x86_l_ac4:
	/* 0xac4: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ac8:
	/* 0xac8: cmp    BYTE PTR [rbx+0x25a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2585570312192ULL);
x86_l_acf:
	/* 0xacf: shrx   rdx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SHR);
x86_l_ad4:
	/* 0xad4: sarx   rax,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RAX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SAR);
x86_l_ad9:
	/* 0xad9: cmove  rax,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_add:
	/* 0xadd: jmp    f09 <generic_sleepable_preload+0xf09> */
	X86_SIM_X86_JMP(0xadd, 0xf09, x86_l_f09);
x86_l_ae2:
	/* 0xae2: mov    rax,QWORD PTR [rbx+0x260] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 608ULL);
x86_l_ae9:
	/* 0xae9: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_aed:
	/* 0xaed: movzx  eax,BYTE PTR [rbx+0x270] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 624ULL);
x86_l_af4:
	/* 0xaf4: shlx   rcx,QWORD PTR [rsp],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((0ULL << 32) | X86_ALU_SHL));
x86_l_afa:
	/* 0xafa: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_afe:
	/* 0xafe: cmp    BYTE PTR [rbx+0x272],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2688649527296ULL);
x86_l_b05:
	/* 0xb05: shrx   rdx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SHR);
x86_l_b0a:
	/* 0xb0a: sarx   rax,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RAX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SAR);
x86_l_b0f:
	/* 0xb0f: cmove  rax,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_b13:
	/* 0xb13: jmp    103d <generic_sleepable_preload+0x103d> */
	X86_SIM_X86_JMP(0xb13, 0x103d, x86_l_103d);
x86_l_b18:
	/* 0xb18: mov    edx,DWORD PTR [rbx+0x208] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_b1e:
	/* 0xb1e: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b24:
	/* 0xb24: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_b27:
	/* 0xb27: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_b2a:
	/* 0xb2a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_b2f:
	/* 0xb2f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b34:
	/* 0xb34: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b39:
	/* 0xb39: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b3b:
	/* 0xb3b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b3d:
	/* 0xb3d: jne    b71 <generic_sleepable_preload+0xb71> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb3d, 0xb71, x86_l_b71);
x86_l_b3f:
	/* 0xb3f: mov    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b43:
	/* 0xb43: add    rcx,QWORD PTR [rbx+0x200] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 512ULL);
x86_l_b4a:
	/* 0xb4a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_b4d:
	/* 0xb4d: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_b52:
	/* 0xb52: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_b57:
	/* 0xb57: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b5b:
	/* 0xb5b: add    rdx,QWORD PTR [rbx+0x200] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 512ULL);
x86_l_b62:
	/* 0xb62: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b67:
	/* 0xb67: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b69:
	/* 0xb69: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b6b:
	/* 0xb6b: je     a19 <generic_sleepable_preload+0xa19> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb6b, 0xa19, x86_l_a19);
x86_l_b71:
	/* 0xb71: cdqe */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RAX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_b73:
	/* 0xb73: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b78:
	/* 0xb78: mov    r15d,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_b7c:
	/* 0xb7c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b81:
	/* 0xb81: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_b86:
	/* 0xb86: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b8b:
	/* 0xb8b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b90:
	/* 0xb90: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_b93:
	/* 0xb93: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b95:
	/* 0xb95: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_b99:
	/* 0xb99: jne    e2 <generic_sleepable_preload+0xe2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb99, 0xe2, x86_l_e2);
x86_l_b9f:
	/* 0xb9f: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ba4:
	/* 0xba4: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_ba9:
	/* 0xba9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bab:
	/* 0xbab: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_baf:
	/* 0xbaf: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_bb7:
	/* 0xbb7: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_bbe:
	/* 0xbbe: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bc3:
	/* 0xbc3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_bc8:
	/* 0xbc8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bca:
	/* 0xbca: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_bcd:
	/* 0xbcd: je     e2 <generic_sleepable_preload+0xe2> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbcd, 0xe2, x86_l_e2);
x86_l_bd3:
	/* 0xbd3: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_bd6:
	/* 0xbd6: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_bdd:
	/* 0xbdd: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bdf:
	/* 0xbdf: mov    r13,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSP, X86_WIDTH_64);
x86_l_be2:
	/* 0xbe2: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_be7:
	/* 0xbe7: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_bea:
	/* 0xbea: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_bed:
	/* 0xbed: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bef:
	/* 0xbef: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bf1:
	/* 0xbf1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_bf6:
	/* 0xbf6: jmp    1358 <generic_sleepable_preload+0x1358> */
	X86_SIM_X86_JMP(0xbf6, 0x1358, x86_l_1358);
x86_l_bfb:
	/* 0xbfb: mov    edx,DWORD PTR [rbx+0x220] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 544ULL);
x86_l_c01:
	/* 0xc01: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_c07:
	/* 0xc07: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_c0a:
	/* 0xc0a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_c0d:
	/* 0xc0d: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_c12:
	/* 0xc12: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_c17:
	/* 0xc17: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c1c:
	/* 0xc1c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c1e:
	/* 0xc1e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c20:
	/* 0xc20: jne    ca3 <generic_sleepable_preload+0xca3> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xc20, 0xca3, x86_l_ca3);
x86_l_c26:
	/* 0xc26: mov    edx,DWORD PTR [rbx+0x224] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 548ULL);
x86_l_c2c:
	/* 0xc2c: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_c32:
	/* 0xc32: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_c35:
	/* 0xc35: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c3a:
	/* 0xc3a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_c3f:
	/* 0xc3f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_c44:
	/* 0xc44: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c49:
	/* 0xc49: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c4b:
	/* 0xc4b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c4d:
	/* 0xc4d: jne    ca3 <generic_sleepable_preload+0xca3> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xc4d, 0xca3, x86_l_ca3);
x86_l_c4f:
	/* 0xc4f: movzx  eax,BYTE PTR [rbx+0x22b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 555ULL);
x86_l_c56:
	/* 0xc56: shlx   rax,QWORD PTR [rsp+0x8],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_c5d:
	/* 0xc5d: mov    rcx,QWORD PTR [rbx+0x218] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 536ULL);
x86_l_c64:
	/* 0xc64: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_c68:
	/* 0xc68: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_c6b:
	/* 0xc6b: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_c6e:
	/* 0xc6e: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_c73:
	/* 0xc73: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_c78:
	/* 0xc78: movzx  ecx,BYTE PTR [rbx+0x22b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 555ULL);
x86_l_c7f:
	/* 0xc7f: shlx   rcx,QWORD PTR [rsp+0x8],rcx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_c86:
	/* 0xc86: mov    rdx,QWORD PTR [rbx+0x218] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 536ULL);
x86_l_c8d:
	/* 0xc8d: add    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_c91:
	/* 0xc91: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_c94:
	/* 0xc94: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c99:
	/* 0xc99: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c9b:
	/* 0xc9b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c9d:
	/* 0xc9d: je     a4b <generic_sleepable_preload+0xa4b> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc9d, 0xa4b, x86_l_a4b);
x86_l_ca3:
	/* 0xca3: cdqe */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RAX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_ca5:
	/* 0xca5: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_caa:
	/* 0xcaa: mov    r15d,DWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cae:
	/* 0xcae: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_cb3:
	/* 0xcb3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_cb8:
	/* 0xcb8: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_cbd:
	/* 0xcbd: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_cc2:
	/* 0xcc2: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_cc5:
	/* 0xcc5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cc7:
	/* 0xcc7: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_ccb:
	/* 0xccb: jne    f0 <generic_sleepable_preload+0xf0> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xccb, 0xf0, x86_l_f0);
x86_l_cd1:
	/* 0xcd1: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_cd6:
	/* 0xcd6: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_cdb:
	/* 0xcdb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cdd:
	/* 0xcdd: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ce1:
	/* 0xce1: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_ce9:
	/* 0xce9: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_cf0:
	/* 0xcf0: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_cf5:
	/* 0xcf5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_cfa:
	/* 0xcfa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cfc:
	/* 0xcfc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_cff:
	/* 0xcff: je     f0 <generic_sleepable_preload+0xf0> */
	X86_SIM_X86_JCC(X86_CC_E, 0xcff, 0xf0, x86_l_f0);
x86_l_d05:
	/* 0xd05: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_d08:
	/* 0xd08: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_d0f:
	/* 0xd0f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d11:
	/* 0xd11: mov    r13,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSP, X86_WIDTH_64);
x86_l_d14:
	/* 0xd14: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_d19:
	/* 0xd19: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_d1c:
	/* 0xd1c: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_d1f:
	/* 0xd1f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_d21:
	/* 0xd21: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d23:
	/* 0xd23: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d28:
	/* 0xd28: jmp    148b <generic_sleepable_preload+0x148b> */
	X86_SIM_X86_JMP(0xd28, 0x148b, x86_l_148b);
x86_l_d2d:
	/* 0xd2d: mov    edx,DWORD PTR [rbx+0x238] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 568ULL);
x86_l_d33:
	/* 0xd33: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_d39:
	/* 0xd39: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_d3c:
	/* 0xd3c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_d3f:
	/* 0xd3f: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_d44:
	/* 0xd44: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d49:
	/* 0xd49: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d4e:
	/* 0xd4e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d50:
	/* 0xd50: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_d52:
	/* 0xd52: jne    dd5 <generic_sleepable_preload+0xdd5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xd52, 0xdd5, x86_l_dd5);
x86_l_d58:
	/* 0xd58: mov    edx,DWORD PTR [rbx+0x23c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 572ULL);
x86_l_d5e:
	/* 0xd5e: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_d64:
	/* 0xd64: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_d67:
	/* 0xd67: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d6c:
	/* 0xd6c: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_d71:
	/* 0xd71: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d76:
	/* 0xd76: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d7b:
	/* 0xd7b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d7d:
	/* 0xd7d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_d7f:
	/* 0xd7f: jne    dd5 <generic_sleepable_preload+0xdd5> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xd7f, 0xdd5, x86_l_dd5);
x86_l_d81:
	/* 0xd81: movzx  eax,BYTE PTR [rbx+0x243] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 579ULL);
x86_l_d88:
	/* 0xd88: shlx   rax,QWORD PTR [rsp+0x8],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_d8f:
	/* 0xd8f: mov    rcx,QWORD PTR [rbx+0x230] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 560ULL);
x86_l_d96:
	/* 0xd96: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_d9a:
	/* 0xd9a: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_d9d:
	/* 0xd9d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_da0:
	/* 0xda0: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_da5:
	/* 0xda5: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_daa:
	/* 0xdaa: movzx  ecx,BYTE PTR [rbx+0x243] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 579ULL);
x86_l_db1:
	/* 0xdb1: shlx   rcx,QWORD PTR [rsp+0x8],rcx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_db8:
	/* 0xdb8: mov    rdx,QWORD PTR [rbx+0x230] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 560ULL);
x86_l_dbf:
	/* 0xdbf: add    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_dc3:
	/* 0xdc3: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_dc6:
	/* 0xdc6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_dcb:
	/* 0xdcb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_dcd:
	/* 0xdcd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_dcf:
	/* 0xdcf: je     a81 <generic_sleepable_preload+0xa81> */
	X86_SIM_X86_JCC(X86_CC_E, 0xdcf, 0xa81, x86_l_a81);
x86_l_dd5:
	/* 0xdd5: cdqe */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RAX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_dd7:
	/* 0xdd7: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_ddc:
	/* 0xddc: mov    r15d,DWORD PTR [rbx+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_de0:
	/* 0xde0: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_de5:
	/* 0xde5: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_dea:
	/* 0xdea: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_def:
	/* 0xdef: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_df4:
	/* 0xdf4: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_df7:
	/* 0xdf7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_df9:
	/* 0xdf9: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_dfd:
	/* 0xdfd: jne    fe <generic_sleepable_preload+0xfe> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xdfd, 0xfe, x86_l_fe);
x86_l_e03:
	/* 0xe03: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e08:
	/* 0xe08: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_e0d:
	/* 0xe0d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e0f:
	/* 0xe0f: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e13:
	/* 0xe13: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_e1b:
	/* 0xe1b: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_e22:
	/* 0xe22: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e27:
	/* 0xe27: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e2c:
	/* 0xe2c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e2e:
	/* 0xe2e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e31:
	/* 0xe31: je     fe <generic_sleepable_preload+0xfe> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe31, 0xfe, x86_l_fe);
x86_l_e37:
	/* 0xe37: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_e3a:
	/* 0xe3a: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_e41:
	/* 0xe41: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e43:
	/* 0xe43: mov    r13,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSP, X86_WIDTH_64);
x86_l_e46:
	/* 0xe46: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_e4b:
	/* 0xe4b: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_e4e:
	/* 0xe4e: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_e51:
	/* 0xe51: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_e53:
	/* 0xe53: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e55:
	/* 0xe55: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e5a:
	/* 0xe5a: jmp    1532 <generic_sleepable_preload+0x1532> */
	X86_SIM_X86_JMP(0xe5a, 0x1532, x86_l_1532);
x86_l_e5f:
	/* 0xe5f: mov    edx,DWORD PTR [rbx+0x250] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 592ULL);
x86_l_e65:
	/* 0xe65: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_e6b:
	/* 0xe6b: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_e6e:
	/* 0xe6e: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_e71:
	/* 0xe71: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_e76:
	/* 0xe76: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_e7b:
	/* 0xe7b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e80:
	/* 0xe80: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e82:
	/* 0xe82: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_e84:
	/* 0xe84: jne    f07 <generic_sleepable_preload+0xf07> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe84, 0xf07, x86_l_f07);
x86_l_e8a:
	/* 0xe8a: mov    edx,DWORD PTR [rbx+0x254] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 596ULL);
x86_l_e90:
	/* 0xe90: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_e96:
	/* 0xe96: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_e99:
	/* 0xe99: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e9e:
	/* 0xe9e: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_ea3:
	/* 0xea3: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_ea8:
	/* 0xea8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_ead:
	/* 0xead: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_eaf:
	/* 0xeaf: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_eb1:
	/* 0xeb1: jne    f07 <generic_sleepable_preload+0xf07> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xeb1, 0xf07, x86_l_f07);
x86_l_eb3:
	/* 0xeb3: movzx  eax,BYTE PTR [rbx+0x25b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 603ULL);
x86_l_eba:
	/* 0xeba: shlx   rax,QWORD PTR [rsp+0x8],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_ec1:
	/* 0xec1: mov    rcx,QWORD PTR [rbx+0x248] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584ULL);
x86_l_ec8:
	/* 0xec8: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_ecc:
	/* 0xecc: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_ecf:
	/* 0xecf: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_ed2:
	/* 0xed2: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_ed7:
	/* 0xed7: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_edc:
	/* 0xedc: movzx  ecx,BYTE PTR [rbx+0x25b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 603ULL);
x86_l_ee3:
	/* 0xee3: shlx   rcx,QWORD PTR [rsp+0x8],rcx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_eea:
	/* 0xeea: mov    rdx,QWORD PTR [rbx+0x248] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584ULL);
x86_l_ef1:
	/* 0xef1: add    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_ef5:
	/* 0xef5: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_ef8:
	/* 0xef8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_efd:
	/* 0xefd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_eff:
	/* 0xeff: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_f01:
	/* 0xf01: je     ab7 <generic_sleepable_preload+0xab7> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf01, 0xab7, x86_l_ab7);
x86_l_f07:
	/* 0xf07: cdqe */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RAX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_f09:
	/* 0xf09: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f0e:
	/* 0xf0e: mov    r15d,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f12:
	/* 0xf12: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f17:
	/* 0xf17: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_f1c:
	/* 0xf1c: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_f21:
	/* 0xf21: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_f26:
	/* 0xf26: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_f29:
	/* 0xf29: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f2b:
	/* 0xf2b: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_f2f:
	/* 0xf2f: jne    10c <generic_sleepable_preload+0x10c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf2f, 0x10c, x86_l_10c);
x86_l_f35:
	/* 0xf35: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_f3a:
	/* 0xf3a: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_f3f:
	/* 0xf3f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f41:
	/* 0xf41: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_f45:
	/* 0xf45: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_f4d:
	/* 0xf4d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_f54:
	/* 0xf54: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_f59:
	/* 0xf59: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f5e:
	/* 0xf5e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f60:
	/* 0xf60: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_f63:
	/* 0xf63: je     10c <generic_sleepable_preload+0x10c> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf63, 0x10c, x86_l_10c);
x86_l_f69:
	/* 0xf69: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_f6c:
	/* 0xf6c: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_f73:
	/* 0xf73: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f75:
	/* 0xf75: mov    r13,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSP, X86_WIDTH_64);
x86_l_f78:
	/* 0xf78: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_f7d:
	/* 0xf7d: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_f80:
	/* 0xf80: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_f83:
	/* 0xf83: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_f85:
	/* 0xf85: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_f87:
	/* 0xf87: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_f8c:
	/* 0xf8c: jmp    15d9 <generic_sleepable_preload+0x15d9> */
	X86_SIM_X86_JMP(0xf8c, 0x15d9, x86_l_15d9);
x86_l_f91:
	/* 0xf91: mov    edx,DWORD PTR [rbx+0x268] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 616ULL);
x86_l_f97:
	/* 0xf97: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_f9d:
	/* 0xf9d: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_fa0:
	/* 0xfa0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_fa3:
	/* 0xfa3: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_fa8:
	/* 0xfa8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_fad:
	/* 0xfad: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_fb2:
	/* 0xfb2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fb4:
	/* 0xfb4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_fb6:
	/* 0xfb6: jne    103b <generic_sleepable_preload+0x103b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xfb6, 0x103b, x86_l_103b);
x86_l_fbc:
	/* 0xfbc: mov    eax,DWORD PTR [rbx+0x26c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 620ULL);
x86_l_fc2:
	/* 0xfc2: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_fc7:
	/* 0xfc7: add    r14,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_fca:
	/* 0xfca: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_fcf:
	/* 0xfcf: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_fd4:
	/* 0xfd4: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_fd9:
	/* 0xfd9: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_fde:
	/* 0xfde: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_fe1:
	/* 0xfe1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_fe3:
	/* 0xfe3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_fe5:
	/* 0xfe5: jne    103b <generic_sleepable_preload+0x103b> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xfe5, 0x103b, x86_l_103b);
x86_l_fe7:
	/* 0xfe7: movzx  eax,BYTE PTR [rbx+0x273] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 627ULL);
x86_l_fee:
	/* 0xfee: shlx   rax,QWORD PTR [rsp+0x8],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RAX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_ff5:
	/* 0xff5: mov    rcx,QWORD PTR [rbx+0x260] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 608ULL);
x86_l_ffc:
	/* 0xffc: add    rcx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1000:
	/* 0x1000: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1003:
	/* 0x1003: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1006:
	/* 0x1006: mov    edx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 8ULL);
x86_l_100b:
	/* 0x100b: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_1010:
	/* 0x1010: movzx  ecx,BYTE PTR [rbx+0x273] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 627ULL);
x86_l_1017:
	/* 0x1017: shlx   rcx,QWORD PTR [rsp+0x8],rcx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_101e:
	/* 0x101e: mov    rdx,QWORD PTR [rbx+0x260] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 608ULL);
x86_l_1025:
	/* 0x1025: add    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_1029:
	/* 0x1029: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_102c:
	/* 0x102c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1031:
	/* 0x1031: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1033:
	/* 0x1033: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1035:
	/* 0x1035: je     aed <generic_sleepable_preload+0xaed> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1035, 0xaed, x86_l_aed);
x86_l_103b:
	/* 0x103b: cdqe */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RAX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_103d:
	/* 0x103d: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_1042:
	/* 0x1042: mov    ebx,DWORD PTR [rbx+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1045:
	/* 0x1045: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_104a:
	/* 0x104a: mov    ecx,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_104f:
	/* 0x104f: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_1054:
	/* 0x1054: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1059:
	/* 0x1059: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_105c:
	/* 0x105c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_105e:
	/* 0x105e: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_1061:
	/* 0x1061: jne    11a <generic_sleepable_preload+0x11a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1061, 0x11a, x86_l_11a);
x86_l_1067:
	/* 0x1067: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_106c:
	/* 0x106c: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1071:
	/* 0x1071: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1073:
	/* 0x1073: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1077:
	/* 0x1077: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_107f:
	/* 0x107f: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_1086:
	/* 0x1086: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_108b:
	/* 0x108b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1090:
	/* 0x1090: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1092:
	/* 0x1092: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1095:
	/* 0x1095: je     11a <generic_sleepable_preload+0x11a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1095, 0x11a, x86_l_11a);
x86_l_109b:
	/* 0x109b: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_109e:
	/* 0x109e: mov    r14,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_10a5:
	/* 0x10a5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10a7:
	/* 0x10a7: mov    r15,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSP, X86_WIDTH_64);
x86_l_10aa:
	/* 0x10aa: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_10af:
	/* 0x10af: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_10b2:
	/* 0x10b2: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_10b5:
	/* 0x10b5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_10b7:
	/* 0x10b7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10b9:
	/* 0x10b9: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_10be:
	/* 0x10be: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_10c1:
	/* 0x10c1: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_10c4:
	/* 0x10c4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_10c6:
	/* 0x10c6: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10c9:
	/* 0x10c9: je     11a <generic_sleepable_preload+0x11a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10c9, 0x11a, x86_l_11a);
x86_l_10cf:
	/* 0x10cf: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_10d2:
	/* 0x10d2: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_10d6:
	/* 0x10d6: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_10db:
	/* 0x10db: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_10de:
	/* 0x10de: jmp    16a1 <generic_sleepable_preload+0x16a1> */
	X86_SIM_X86_JMP(0x10de, 0x16a1, x86_l_16a1);
x86_l_10e3:
	/* 0x10e3: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_10e8:
	/* 0x10e8: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_10eb:
	/* 0x10eb: je     12e9 <generic_sleepable_preload+0x12e9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10eb, 0x12e9, x86_l_12e9);
x86_l_10f1:
	/* 0x10f1: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_10f6:
	/* 0x10f6: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_10f9:
	/* 0x10f9: je     12e9 <generic_sleepable_preload+0x12e9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10f9, 0x12e9, x86_l_12e9);
x86_l_10ff:
	/* 0x10ff: jmp    12fc <generic_sleepable_preload+0x12fc> */
	X86_SIM_X86_JMP(0x10ff, 0x12fc, x86_l_12fc);
x86_l_1104:
	/* 0x1104: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_1109:
	/* 0x1109: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_110c:
	/* 0x110c: je     141c <generic_sleepable_preload+0x141c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x110c, 0x141c, x86_l_141c);
x86_l_1112:
	/* 0x1112: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1117:
	/* 0x1117: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_111a:
	/* 0x111a: je     141c <generic_sleepable_preload+0x141c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x111a, 0x141c, x86_l_141c);
x86_l_1120:
	/* 0x1120: jmp    142f <generic_sleepable_preload+0x142f> */
	X86_SIM_X86_JMP(0x1120, 0x142f, x86_l_142f);
x86_l_1125:
	/* 0x1125: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_112a:
	/* 0x112a: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_112d:
	/* 0x112d: je     14c3 <generic_sleepable_preload+0x14c3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x112d, 0x14c3, x86_l_14c3);
x86_l_1133:
	/* 0x1133: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1138:
	/* 0x1138: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_113b:
	/* 0x113b: je     14c3 <generic_sleepable_preload+0x14c3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x113b, 0x14c3, x86_l_14c3);
x86_l_1141:
	/* 0x1141: jmp    14d6 <generic_sleepable_preload+0x14d6> */
	X86_SIM_X86_JMP(0x1141, 0x14d6, x86_l_14d6);
x86_l_1146:
	/* 0x1146: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_114b:
	/* 0x114b: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_114e:
	/* 0x114e: je     156a <generic_sleepable_preload+0x156a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x114e, 0x156a, x86_l_156a);
x86_l_1154:
	/* 0x1154: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_1159:
	/* 0x1159: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_115c:
	/* 0x115c: je     156a <generic_sleepable_preload+0x156a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x115c, 0x156a, x86_l_156a);
x86_l_1162:
	/* 0x1162: jmp    157d <generic_sleepable_preload+0x157d> */
	X86_SIM_X86_JMP(0x1162, 0x157d, x86_l_157d);
x86_l_1167:
	/* 0x1167: mov    rbp,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_116c:
	/* 0x116c: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_116f:
	/* 0x116f: je     1611 <generic_sleepable_preload+0x1611> */
	X86_SIM_X86_JCC(X86_CC_E, 0x116f, 0x1611, x86_l_1611);
x86_l_1175:
	/* 0x1175: mov    rbp,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_117a:
	/* 0x117a: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_117d:
	/* 0x117d: je     1611 <generic_sleepable_preload+0x1611> */
	X86_SIM_X86_JCC(X86_CC_E, 0x117d, 0x1611, x86_l_1611);
x86_l_1183:
	/* 0x1183: jmp    1625 <generic_sleepable_preload+0x1625> */
	X86_SIM_X86_JMP(0x1183, 0x1625, x86_l_1625);
x86_l_1188:
	/* 0x1188: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_118d:
	/* 0x118d: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1190:
	/* 0x1190: je     12e9 <generic_sleepable_preload+0x12e9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1190, 0x12e9, x86_l_12e9);
x86_l_1196:
	/* 0x1196: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_119b:
	/* 0x119b: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_119e:
	/* 0x119e: je     12e9 <generic_sleepable_preload+0x12e9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x119e, 0x12e9, x86_l_12e9);
x86_l_11a4:
	/* 0x11a4: jmp    12fc <generic_sleepable_preload+0x12fc> */
	X86_SIM_X86_JMP(0x11a4, 0x12fc, x86_l_12fc);
x86_l_11a9:
	/* 0x11a9: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_11ae:
	/* 0x11ae: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_11b1:
	/* 0x11b1: je     141c <generic_sleepable_preload+0x141c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11b1, 0x141c, x86_l_141c);
x86_l_11b7:
	/* 0x11b7: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_11bc:
	/* 0x11bc: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_11bf:
	/* 0x11bf: je     141c <generic_sleepable_preload+0x141c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11bf, 0x141c, x86_l_141c);
x86_l_11c5:
	/* 0x11c5: jmp    142f <generic_sleepable_preload+0x142f> */
	X86_SIM_X86_JMP(0x11c5, 0x142f, x86_l_142f);
x86_l_11ca:
	/* 0x11ca: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_11cf:
	/* 0x11cf: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_11d2:
	/* 0x11d2: je     14c3 <generic_sleepable_preload+0x14c3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11d2, 0x14c3, x86_l_14c3);
x86_l_11d8:
	/* 0x11d8: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_11dd:
	/* 0x11dd: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_11e0:
	/* 0x11e0: je     14c3 <generic_sleepable_preload+0x14c3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11e0, 0x14c3, x86_l_14c3);
x86_l_11e6:
	/* 0x11e6: jmp    14d6 <generic_sleepable_preload+0x14d6> */
	X86_SIM_X86_JMP(0x11e6, 0x14d6, x86_l_14d6);
x86_l_11eb:
	/* 0x11eb: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_11f0:
	/* 0x11f0: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_11f3:
	/* 0x11f3: je     156a <generic_sleepable_preload+0x156a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11f3, 0x156a, x86_l_156a);
x86_l_11f9:
	/* 0x11f9: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_11fe:
	/* 0x11fe: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_1201:
	/* 0x1201: je     156a <generic_sleepable_preload+0x156a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1201, 0x156a, x86_l_156a);
x86_l_1207:
	/* 0x1207: jmp    157d <generic_sleepable_preload+0x157d> */
	X86_SIM_X86_JMP(0x1207, 0x157d, x86_l_157d);
x86_l_120c:
	/* 0x120c: mov    rbp,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1211:
	/* 0x1211: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1214:
	/* 0x1214: je     1611 <generic_sleepable_preload+0x1611> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1214, 0x1611, x86_l_1611);
x86_l_121a:
	/* 0x121a: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_121f:
	/* 0x121f: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_1222:
	/* 0x1222: je     1611 <generic_sleepable_preload+0x1611> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1222, 0x1611, x86_l_1611);
x86_l_1228:
	/* 0x1228: jmp    1625 <generic_sleepable_preload+0x1625> */
	X86_SIM_X86_JMP(0x1228, 0x1625, x86_l_1625);
x86_l_122d:
	/* 0x122d: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1232:
	/* 0x1232: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1235:
	/* 0x1235: je     12e9 <generic_sleepable_preload+0x12e9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1235, 0x12e9, x86_l_12e9);
x86_l_123b:
	/* 0x123b: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1240:
	/* 0x1240: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_1243:
	/* 0x1243: je     12e9 <generic_sleepable_preload+0x12e9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1243, 0x12e9, x86_l_12e9);
x86_l_1249:
	/* 0x1249: jmp    12fc <generic_sleepable_preload+0x12fc> */
	X86_SIM_X86_JMP(0x1249, 0x12fc, x86_l_12fc);
x86_l_124e:
	/* 0x124e: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1253:
	/* 0x1253: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1256:
	/* 0x1256: je     141c <generic_sleepable_preload+0x141c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1256, 0x141c, x86_l_141c);
x86_l_125c:
	/* 0x125c: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1261:
	/* 0x1261: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_1264:
	/* 0x1264: je     141c <generic_sleepable_preload+0x141c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1264, 0x141c, x86_l_141c);
x86_l_126a:
	/* 0x126a: jmp    142f <generic_sleepable_preload+0x142f> */
	X86_SIM_X86_JMP(0x126a, 0x142f, x86_l_142f);
x86_l_126f:
	/* 0x126f: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1274:
	/* 0x1274: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1277:
	/* 0x1277: je     14c3 <generic_sleepable_preload+0x14c3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1277, 0x14c3, x86_l_14c3);
x86_l_127d:
	/* 0x127d: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1282:
	/* 0x1282: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_1285:
	/* 0x1285: je     14c3 <generic_sleepable_preload+0x14c3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1285, 0x14c3, x86_l_14c3);
x86_l_128b:
	/* 0x128b: jmp    14d6 <generic_sleepable_preload+0x14d6> */
	X86_SIM_X86_JMP(0x128b, 0x14d6, x86_l_14d6);
x86_l_1290:
	/* 0x1290: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1295:
	/* 0x1295: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_1298:
	/* 0x1298: je     156a <generic_sleepable_preload+0x156a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1298, 0x156a, x86_l_156a);
x86_l_129e:
	/* 0x129e: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_12a3:
	/* 0x12a3: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_12a6:
	/* 0x12a6: je     156a <generic_sleepable_preload+0x156a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12a6, 0x156a, x86_l_156a);
x86_l_12ac:
	/* 0x12ac: jmp    157d <generic_sleepable_preload+0x157d> */
	X86_SIM_X86_JMP(0x12ac, 0x157d, x86_l_157d);
x86_l_12b1:
	/* 0x12b1: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_12b6:
	/* 0x12b6: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_12b9:
	/* 0x12b9: je     1611 <generic_sleepable_preload+0x1611> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12b9, 0x1611, x86_l_1611);
x86_l_12bf:
	/* 0x12bf: mov    rbp,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_12c4:
	/* 0x12c4: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_12c7:
	/* 0x12c7: je     1611 <generic_sleepable_preload+0x1611> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12c7, 0x1611, x86_l_1611);
x86_l_12cd:
	/* 0x12cd: jmp    1625 <generic_sleepable_preload+0x1625> */
	X86_SIM_X86_JMP(0x12cd, 0x1625, x86_l_1625);
x86_l_12d2:
	/* 0x12d2: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_12da:
	/* 0x12da: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_12dd:
	/* 0x12dd: je     12e9 <generic_sleepable_preload+0x12e9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12dd, 0x12e9, x86_l_12e9);
x86_l_12df:
	/* 0x12df: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_12e4:
	/* 0x12e4: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_12e7:
	/* 0x12e7: jne    12fc <generic_sleepable_preload+0x12fc> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x12e7, 0x12fc, x86_l_12fc);
x86_l_12e9:
	/* 0x12e9: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_12ec:
	/* 0x12ec: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_12ee:
	/* 0x12ee: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_12f0:
	/* 0x12f0: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_12f5:
	/* 0x12f5: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_12f7:
	/* 0x12f7: bzhi   r15,QWORD PTR [rdx],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_R15, X86_RDX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_12fc:
	/* 0x12fc: cmp    DWORD PTR [rbx+0x4],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869190ULL);
x86_l_1300:
	/* 0x1300: jne    e2 <generic_sleepable_preload+0xe2> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1300, 0xe2, x86_l_e2);
x86_l_1306:
	/* 0x1306: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_130b:
	/* 0x130b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_130d:
	/* 0x130d: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1311:
	/* 0x1311: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1319:
	/* 0x1319: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_1320:
	/* 0x1320: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1325:
	/* 0x1325: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_132a:
	/* 0x132a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_132c:
	/* 0x132c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_132f:
	/* 0x132f: je     e2 <generic_sleepable_preload+0xe2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x132f, 0xe2, x86_l_e2);
x86_l_1335:
	/* 0x1335: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1338:
	/* 0x1338: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_133f:
	/* 0x133f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1341:
	/* 0x1341: mov    r13,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSP, X86_WIDTH_64);
x86_l_1344:
	/* 0x1344: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1349:
	/* 0x1349: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_134c:
	/* 0x134c: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_134f:
	/* 0x134f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1351:
	/* 0x1351: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1353:
	/* 0x1353: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1358:
	/* 0x1358: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_135b:
	/* 0x135b: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_135e:
	/* 0x135e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1360:
	/* 0x1360: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1363:
	/* 0x1363: je     e2 <generic_sleepable_preload+0xe2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1363, 0xe2, x86_l_e2);
x86_l_1369:
	/* 0x1369: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_136c:
	/* 0x136c: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1370:
	/* 0x1370: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1375:
	/* 0x1375: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1378:
	/* 0x1378: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_137a:
	/* 0x137a: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_137d:
	/* 0x137d: call   1382 <generic_sleepable_preload+0x1382> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_1382:
	/* 0x1382: sar    eax,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SAR, 31ULL);
x86_l_1385:
	/* 0x1385: mov    DWORD PTR [r15],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1388:
	/* 0x1388: jmp    e2 <generic_sleepable_preload+0xe2> */
	X86_SIM_X86_JMP(0x1388, 0xe2, x86_l_e2);
x86_l_138d:
	/* 0x138d: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1395:
	/* 0x1395: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1398:
	/* 0x1398: je     141c <generic_sleepable_preload+0x141c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1398, 0x141c, x86_l_141c);
x86_l_139e:
	/* 0x139e: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_13a3:
	/* 0x13a3: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_13a6:
	/* 0x13a6: je     141c <generic_sleepable_preload+0x141c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13a6, 0x141c, x86_l_141c);
x86_l_13a8:
	/* 0x13a8: jmp    142f <generic_sleepable_preload+0x142f> */
	X86_SIM_X86_JMP(0x13a8, 0x142f, x86_l_142f);
x86_l_13ad:
	/* 0x13ad: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_13b5:
	/* 0x13b5: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_13b8:
	/* 0x13b8: je     14c3 <generic_sleepable_preload+0x14c3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13b8, 0x14c3, x86_l_14c3);
x86_l_13be:
	/* 0x13be: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_13c3:
	/* 0x13c3: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_13c6:
	/* 0x13c6: je     14c3 <generic_sleepable_preload+0x14c3> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13c6, 0x14c3, x86_l_14c3);
x86_l_13cc:
	/* 0x13cc: jmp    14d6 <generic_sleepable_preload+0x14d6> */
	X86_SIM_X86_JMP(0x13cc, 0x14d6, x86_l_14d6);
x86_l_13d1:
	/* 0x13d1: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_13d9:
	/* 0x13d9: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_13dc:
	/* 0x13dc: je     156a <generic_sleepable_preload+0x156a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13dc, 0x156a, x86_l_156a);
x86_l_13e2:
	/* 0x13e2: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_13e7:
	/* 0x13e7: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_13ea:
	/* 0x13ea: je     156a <generic_sleepable_preload+0x156a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13ea, 0x156a, x86_l_156a);
x86_l_13f0:
	/* 0x13f0: jmp    157d <generic_sleepable_preload+0x157d> */
	X86_SIM_X86_JMP(0x13f0, 0x157d, x86_l_157d);
x86_l_13f5:
	/* 0x13f5: mov    rbp,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_13fd:
	/* 0x13fd: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1400:
	/* 0x1400: je     1611 <generic_sleepable_preload+0x1611> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1400, 0x1611, x86_l_1611);
x86_l_1406:
	/* 0x1406: mov    rbp,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_140b:
	/* 0x140b: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_140e:
	/* 0x140e: je     1611 <generic_sleepable_preload+0x1611> */
	X86_SIM_X86_JCC(X86_CC_E, 0x140e, 0x1611, x86_l_1611);
x86_l_1414:
	/* 0x1414: jmp    1625 <generic_sleepable_preload+0x1625> */
	X86_SIM_X86_JMP(0x1414, 0x1625, x86_l_1625);
x86_l_1419:
	/* 0x1419: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_141c:
	/* 0x141c: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_141f:
	/* 0x141f: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_1421:
	/* 0x1421: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_1423:
	/* 0x1423: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_1428:
	/* 0x1428: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_142a:
	/* 0x142a: bzhi   r15,QWORD PTR [rdx],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_R15, X86_RDX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_142f:
	/* 0x142f: cmp    DWORD PTR [rbx+0x8],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738374ULL);
x86_l_1433:
	/* 0x1433: jne    f0 <generic_sleepable_preload+0xf0> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1433, 0xf0, x86_l_f0);
x86_l_1439:
	/* 0x1439: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_143e:
	/* 0x143e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1440:
	/* 0x1440: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1444:
	/* 0x1444: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_144c:
	/* 0x144c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_1453:
	/* 0x1453: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1458:
	/* 0x1458: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_145d:
	/* 0x145d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_145f:
	/* 0x145f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1462:
	/* 0x1462: je     f0 <generic_sleepable_preload+0xf0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1462, 0xf0, x86_l_f0);
x86_l_1468:
	/* 0x1468: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_146b:
	/* 0x146b: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_1472:
	/* 0x1472: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1474:
	/* 0x1474: mov    r13,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSP, X86_WIDTH_64);
x86_l_1477:
	/* 0x1477: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_147c:
	/* 0x147c: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_147f:
	/* 0x147f: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_1482:
	/* 0x1482: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1484:
	/* 0x1484: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1486:
	/* 0x1486: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_148b:
	/* 0x148b: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_148e:
	/* 0x148e: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_1491:
	/* 0x1491: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1493:
	/* 0x1493: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1496:
	/* 0x1496: je     f0 <generic_sleepable_preload+0xf0> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1496, 0xf0, x86_l_f0);
x86_l_149c:
	/* 0x149c: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_149f:
	/* 0x149f: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_14a3:
	/* 0x14a3: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_14a8:
	/* 0x14a8: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_14ab:
	/* 0x14ab: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14ad:
	/* 0x14ad: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_14b0:
	/* 0x14b0: call   14b5 <generic_sleepable_preload+0x14b5> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_14b5:
	/* 0x14b5: sar    eax,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SAR, 31ULL);
x86_l_14b8:
	/* 0x14b8: mov    DWORD PTR [r15],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14bb:
	/* 0x14bb: jmp    f0 <generic_sleepable_preload+0xf0> */
	X86_SIM_X86_JMP(0x14bb, 0xf0, x86_l_f0);
x86_l_14c0:
	/* 0x14c0: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_14c3:
	/* 0x14c3: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_14c6:
	/* 0x14c6: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_14c8:
	/* 0x14c8: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_14ca:
	/* 0x14ca: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_14cf:
	/* 0x14cf: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_14d1:
	/* 0x14d1: bzhi   r15,QWORD PTR [rdx],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_R15, X86_RDX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_14d6:
	/* 0x14d6: cmp    DWORD PTR [rbx+0xc],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607558ULL);
x86_l_14da:
	/* 0x14da: jne    fe <generic_sleepable_preload+0xfe> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x14da, 0xfe, x86_l_fe);
x86_l_14e0:
	/* 0x14e0: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_14e5:
	/* 0x14e5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_14e7:
	/* 0x14e7: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14eb:
	/* 0x14eb: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_14f3:
	/* 0x14f3: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_14fa:
	/* 0x14fa: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_14ff:
	/* 0x14ff: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1504:
	/* 0x1504: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1506:
	/* 0x1506: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1509:
	/* 0x1509: je     fe <generic_sleepable_preload+0xfe> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1509, 0xfe, x86_l_fe);
x86_l_150f:
	/* 0x150f: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1512:
	/* 0x1512: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_1519:
	/* 0x1519: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_151b:
	/* 0x151b: mov    r13,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSP, X86_WIDTH_64);
x86_l_151e:
	/* 0x151e: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1523:
	/* 0x1523: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1526:
	/* 0x1526: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_1529:
	/* 0x1529: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_152b:
	/* 0x152b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_152d:
	/* 0x152d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1532:
	/* 0x1532: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1535:
	/* 0x1535: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_1538:
	/* 0x1538: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_153a:
	/* 0x153a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_153d:
	/* 0x153d: je     fe <generic_sleepable_preload+0xfe> */
	X86_SIM_X86_JCC(X86_CC_E, 0x153d, 0xfe, x86_l_fe);
x86_l_1543:
	/* 0x1543: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1546:
	/* 0x1546: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_154a:
	/* 0x154a: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_154f:
	/* 0x154f: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1552:
	/* 0x1552: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1554:
	/* 0x1554: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1557:
	/* 0x1557: call   155c <generic_sleepable_preload+0x155c> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_155c:
	/* 0x155c: sar    eax,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SAR, 31ULL);
x86_l_155f:
	/* 0x155f: mov    DWORD PTR [r15],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1562:
	/* 0x1562: jmp    fe <generic_sleepable_preload+0xfe> */
	X86_SIM_X86_JMP(0x1562, 0xfe, x86_l_fe);
x86_l_1567:
	/* 0x1567: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_156a:
	/* 0x156a: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_156d:
	/* 0x156d: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_156f:
	/* 0x156f: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_1571:
	/* 0x1571: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_1576:
	/* 0x1576: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1578:
	/* 0x1578: bzhi   r15,QWORD PTR [rdx],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_R15, X86_RDX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_157d:
	/* 0x157d: cmp    DWORD PTR [rbx+0x10],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476742ULL);
x86_l_1581:
	/* 0x1581: jne    10c <generic_sleepable_preload+0x10c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1581, 0x10c, x86_l_10c);
x86_l_1587:
	/* 0x1587: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_158c:
	/* 0x158c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_158e:
	/* 0x158e: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1592:
	/* 0x1592: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_159a:
	/* 0x159a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_15a1:
	/* 0x15a1: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15a6:
	/* 0x15a6: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_15ab:
	/* 0x15ab: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15ad:
	/* 0x15ad: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15b0:
	/* 0x15b0: je     10c <generic_sleepable_preload+0x10c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x15b0, 0x10c, x86_l_10c);
x86_l_15b6:
	/* 0x15b6: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_15b9:
	/* 0x15b9: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_15c0:
	/* 0x15c0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15c2:
	/* 0x15c2: mov    r13,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSP, X86_WIDTH_64);
x86_l_15c5:
	/* 0x15c5: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_15ca:
	/* 0x15ca: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_15cd:
	/* 0x15cd: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_15d0:
	/* 0x15d0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15d2:
	/* 0x15d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15d4:
	/* 0x15d4: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_15d9:
	/* 0x15d9: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_15dc:
	/* 0x15dc: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_15df:
	/* 0x15df: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_15e1:
	/* 0x15e1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15e4:
	/* 0x15e4: je     10c <generic_sleepable_preload+0x10c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x15e4, 0x10c, x86_l_10c);
x86_l_15ea:
	/* 0x15ea: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_15ed:
	/* 0x15ed: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_15f1:
	/* 0x15f1: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_15f6:
	/* 0x15f6: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_15f9:
	/* 0x15f9: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_15fb:
	/* 0x15fb: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_15fe:
	/* 0x15fe: call   1603 <generic_sleepable_preload+0x1603> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_1603:
	/* 0x1603: sar    eax,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SAR, 31ULL);
x86_l_1606:
	/* 0x1606: mov    DWORD PTR [r15],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1609:
	/* 0x1609: jmp    10c <generic_sleepable_preload+0x10c> */
	X86_SIM_X86_JMP(0x1609, 0x10c, x86_l_10c);
x86_l_160e:
	/* 0x160e: mov    rbp,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R14, X86_WIDTH_64);
x86_l_1611:
	/* 0x1611: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_1614:
	/* 0x1614: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_1616:
	/* 0x1616: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_1618:
	/* 0x1618: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_161d:
	/* 0x161d: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_161f:
	/* 0x161f: bzhi   r15,QWORD PTR [rbp+0x0],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_R15, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_1625:
	/* 0x1625: cmp    DWORD PTR [rbx+0x14],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345926ULL);
x86_l_1629:
	/* 0x1629: jne    11a <generic_sleepable_preload+0x11a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1629, 0x11a, x86_l_11a);
x86_l_162f:
	/* 0x162f: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1634:
	/* 0x1634: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1636:
	/* 0x1636: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_163a:
	/* 0x163a: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1642:
	/* 0x1642: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_1649:
	/* 0x1649: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_164e:
	/* 0x164e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1653:
	/* 0x1653: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1655:
	/* 0x1655: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1658:
	/* 0x1658: je     11a <generic_sleepable_preload+0x11a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1658, 0x11a, x86_l_11a);
x86_l_165e:
	/* 0x165e: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1661:
	/* 0x1661: mov    rbx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_1668:
	/* 0x1668: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_166a:
	/* 0x166a: mov    r14,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSP, X86_WIDTH_64);
x86_l_166d:
	/* 0x166d: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_1672:
	/* 0x1672: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1675:
	/* 0x1675: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_1678:
	/* 0x1678: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_167a:
	/* 0x167a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_167c:
	/* 0x167c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1681:
	/* 0x1681: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1684:
	/* 0x1684: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_1687:
	/* 0x1687: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1689:
	/* 0x1689: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_168c:
	/* 0x168c: je     11a <generic_sleepable_preload+0x11a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x168c, 0x11a, x86_l_11a);
x86_l_1692:
	/* 0x1692: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1695:
	/* 0x1695: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1699:
	/* 0x1699: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_169e:
	/* 0x169e: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_16a1:
	/* 0x16a1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_16a3:
	/* 0x16a3: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_16a6:
	/* 0x16a6: call   16ab <generic_sleepable_preload+0x16ab> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_16ab:
	/* 0x16ab: sar    eax,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SAR, 31ULL);
x86_l_16ae:
	/* 0x16ae: mov    DWORD PTR [rbx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_16b0:
	/* 0x16b0: jmp    11a <generic_sleepable_preload+0x11a> */
	X86_SIM_X86_JMP(0x16b0, 0x11a, x86_l_11a);
x86_l_16b5:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
