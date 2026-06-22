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
	/* 0x18: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d:
	/* 0x1d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&config_map)));
x86_l_24:
	/* 0x24: lea    rsi,[rsp+0x94] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 148ULL);
x86_l_2c:
	/* 0x2c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2e:
	/* 0x2e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_31:
	/* 0x31: je     113 <generic_sleepable_preload+0x113> */
	X86_SIM_X86_JCC(X86_CC_E, 0x31, 0x113, x86_l_113);
x86_l_37:
	/* 0x37: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_3a:
	/* 0x3a: lea    rax,[r14+0x98] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 152ULL);
x86_l_41:
	/* 0x41: mov    QWORD PTR [rsp+0x50],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_46:
	/* 0x46: lea    rax,[r14+0x80] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_4d:
	/* 0x4d: mov    QWORD PTR [rsp+0x48],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_52:
	/* 0x52: lea    rax,[r14+0x70] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_56:
	/* 0x56: mov    QWORD PTR [rsp+0x88],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_5e:
	/* 0x5e: lea    rax,[r14+0x68] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_62:
	/* 0x62: mov    QWORD PTR [rsp+0x40],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_67:
	/* 0x67: lea    rax,[r14+0x60] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_6b:
	/* 0x6b: mov    QWORD PTR [rsp+0x80],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_73:
	/* 0x73: lea    rax,[r14+0x58] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_77:
	/* 0x77: mov    QWORD PTR [rsp+0x38],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_7c:
	/* 0x7c: lea    rax,[r14+0x50] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_80:
	/* 0x80: mov    QWORD PTR [rsp+0x78],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_85:
	/* 0x85: lea    rax,[r14+0x48] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_89:
	/* 0x89: mov    QWORD PTR [rsp+0x30],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_8e:
	/* 0x8e: lea    rax,[r14+0x40] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_92:
	/* 0x92: mov    QWORD PTR [rsp+0x70],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_97:
	/* 0x97: lea    rax,[r14+0x38] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_9b:
	/* 0x9b: mov    QWORD PTR [rsp+0x28],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_a0:
	/* 0xa0: lea    rax,[r14+0x30] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_a4:
	/* 0xa4: mov    QWORD PTR [rsp+0x68],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_a9:
	/* 0xa9: lea    rax,[r14+0x28] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_ad:
	/* 0xad: mov    QWORD PTR [rsp+0x20],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b2:
	/* 0xb2: lea    rax,[r14+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_b6:
	/* 0xb6: mov    QWORD PTR [rsp+0x60],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_bb:
	/* 0xbb: lea    rax,[r14+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_bf:
	/* 0xbf: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_c4:
	/* 0xc4: lea    rax,[r14+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RAX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c8:
	/* 0xc8: mov    QWORD PTR [rsp+0x58],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_cd:
	/* 0xcd: lea    rbp,[r14+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RBP, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d1:
	/* 0xd1: mov    eax,DWORD PTR [rbx+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_d4:
	/* 0xd4: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_d9:
	/* 0xd9: jne    124 <generic_sleepable_preload+0x124> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xd9, 0x124, x86_l_124);
x86_l_db:
	/* 0xdb: mov    eax,DWORD PTR [rbx+0x1c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 28ULL);
x86_l_de:
	/* 0xde: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_e3:
	/* 0xe3: jne    17d <generic_sleepable_preload+0x17d> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe3, 0x17d, x86_l_17d);
x86_l_e9:
	/* 0xe9: mov    eax,DWORD PTR [rbx+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_ec:
	/* 0xec: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_f1:
	/* 0xf1: jne    1d6 <generic_sleepable_preload+0x1d6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xf1, 0x1d6, x86_l_1d6);
x86_l_f7:
	/* 0xf7: mov    eax,DWORD PTR [rbx+0x24] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 36ULL);
x86_l_fa:
	/* 0xfa: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_ff:
	/* 0xff: jne    22f <generic_sleepable_preload+0x22f> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xff, 0x22f, x86_l_22f);
x86_l_105:
	/* 0x105: mov    eax,DWORD PTR [rbx+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_108:
	/* 0x108: test   eax,0x100 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_TEST_IMM, X86_RAX, X86_WIDTH_32, 256ULL);
x86_l_10d:
	/* 0x10d: jne    288 <generic_sleepable_preload+0x288> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x10d, 0x288, x86_l_288);
x86_l_113:
	/* 0x113: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_115:
	/* 0x115: add    rsp,0x98 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 152ULL);
x86_l_11c:
	/* 0x11c: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_11e:
	/* 0x11e: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_11f:
	/* 0x11f: jmp    14cb <generic_sleepable_preload+0x14cb> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_124:
	/* 0x124: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_126:
	/* 0x126: js     2e3 <generic_sleepable_preload+0x2e3> */
	X86_SIM_X86_JCC(X86_CC_S, 0x126, 0x2e3, x86_l_2e3);
x86_l_12c:
	/* 0x12c: movzx  ecx,BYTE PTR [rbx+0x211] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 529ULL);
x86_l_133:
	/* 0x133: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_135:
	/* 0x135: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_138:
	/* 0x138: jg     4d7 <generic_sleepable_preload+0x4d7> */
	X86_SIM_X86_JCC(X86_CC_G, 0x138, 0x4d7, x86_l_4d7);
x86_l_13e:
	/* 0x13e: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_141:
	/* 0x141: je     90e <generic_sleepable_preload+0x90e> */
	X86_SIM_X86_JCC(X86_CC_E, 0x141, 0x90e, x86_l_90e);
x86_l_147:
	/* 0x147: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_14a:
	/* 0x14a: jne    a5e <generic_sleepable_preload+0xa5e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x14a, 0xa5e, x86_l_a5e);
x86_l_150:
	/* 0x150: mov    edx,DWORD PTR [rbx+0x208] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_156:
	/* 0x156: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_15c:
	/* 0x15c: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_15f:
	/* 0x15f: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_164:
	/* 0x164: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_167:
	/* 0x167: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_16c:
	/* 0x16c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_16e:
	/* 0x16e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_170:
	/* 0x170: je     919 <generic_sleepable_preload+0x919> */
	X86_SIM_X86_JCC(X86_CC_E, 0x170, 0x919, x86_l_919);
x86_l_176:
	/* 0x176: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_178:
	/* 0x178: jmp    a5e <generic_sleepable_preload+0xa5e> */
	X86_SIM_X86_JMP(0x178, 0xa5e, x86_l_a5e);
x86_l_17d:
	/* 0x17d: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_17f:
	/* 0x17f: js     347 <generic_sleepable_preload+0x347> */
	X86_SIM_X86_JCC(X86_CC_S, 0x17f, 0x347, x86_l_347);
x86_l_185:
	/* 0x185: movzx  ecx,BYTE PTR [rbx+0x229] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 553ULL);
x86_l_18c:
	/* 0x18c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_18e:
	/* 0x18e: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_191:
	/* 0x191: jg     55d <generic_sleepable_preload+0x55d> */
	X86_SIM_X86_JCC(X86_CC_G, 0x191, 0x55d, x86_l_55d);
x86_l_197:
	/* 0x197: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_19a:
	/* 0x19a: je     940 <generic_sleepable_preload+0x940> */
	X86_SIM_X86_JCC(X86_CC_E, 0x19a, 0x940, x86_l_940);
x86_l_1a0:
	/* 0x1a0: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1a3:
	/* 0x1a3: jne    b5c <generic_sleepable_preload+0xb5c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1a3, 0xb5c, x86_l_b5c);
x86_l_1a9:
	/* 0x1a9: mov    edx,DWORD PTR [rbx+0x220] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 544ULL);
x86_l_1af:
	/* 0x1af: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_1b5:
	/* 0x1b5: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1b8:
	/* 0x1b8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_1bd:
	/* 0x1bd: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_1c0:
	/* 0x1c0: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_1c5:
	/* 0x1c5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c7:
	/* 0x1c7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1c9:
	/* 0x1c9: je     94b <generic_sleepable_preload+0x94b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1c9, 0x94b, x86_l_94b);
x86_l_1cf:
	/* 0x1cf: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d1:
	/* 0x1d1: jmp    b5c <generic_sleepable_preload+0xb5c> */
	X86_SIM_X86_JMP(0x1d1, 0xb5c, x86_l_b5c);
x86_l_1d6:
	/* 0x1d6: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_1d8:
	/* 0x1d8: js     3ab <generic_sleepable_preload+0x3ab> */
	X86_SIM_X86_JCC(X86_CC_S, 0x1d8, 0x3ab, x86_l_3ab);
x86_l_1de:
	/* 0x1de: movzx  ecx,BYTE PTR [rbx+0x241] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 577ULL);
x86_l_1e5:
	/* 0x1e5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1e7:
	/* 0x1e7: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1ea:
	/* 0x1ea: jg     5aa <generic_sleepable_preload+0x5aa> */
	X86_SIM_X86_JCC(X86_CC_G, 0x1ea, 0x5aa, x86_l_5aa);
x86_l_1f0:
	/* 0x1f0: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_1f3:
	/* 0x1f3: je     976 <generic_sleepable_preload+0x976> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1f3, 0x976, x86_l_976);
x86_l_1f9:
	/* 0x1f9: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1fc:
	/* 0x1fc: jne    c5a <generic_sleepable_preload+0xc5a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1fc, 0xc5a, x86_l_c5a);
x86_l_202:
	/* 0x202: mov    edx,DWORD PTR [rbx+0x238] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 568ULL);
x86_l_208:
	/* 0x208: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_20e:
	/* 0x20e: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_211:
	/* 0x211: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_216:
	/* 0x216: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_219:
	/* 0x219: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_21e:
	/* 0x21e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_220:
	/* 0x220: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_222:
	/* 0x222: je     981 <generic_sleepable_preload+0x981> */
	X86_SIM_X86_JCC(X86_CC_E, 0x222, 0x981, x86_l_981);
x86_l_228:
	/* 0x228: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_22a:
	/* 0x22a: jmp    c5a <generic_sleepable_preload+0xc5a> */
	X86_SIM_X86_JMP(0x22a, 0xc5a, x86_l_c5a);
x86_l_22f:
	/* 0x22f: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_231:
	/* 0x231: js     40f <generic_sleepable_preload+0x40f> */
	X86_SIM_X86_JCC(X86_CC_S, 0x231, 0x40f, x86_l_40f);
x86_l_237:
	/* 0x237: movzx  ecx,BYTE PTR [rbx+0x259] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 601ULL);
x86_l_23e:
	/* 0x23e: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_240:
	/* 0x240: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_243:
	/* 0x243: jg     5f7 <generic_sleepable_preload+0x5f7> */
	X86_SIM_X86_JCC(X86_CC_G, 0x243, 0x5f7, x86_l_5f7);
x86_l_249:
	/* 0x249: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_24c:
	/* 0x24c: je     9ac <generic_sleepable_preload+0x9ac> */
	X86_SIM_X86_JCC(X86_CC_E, 0x24c, 0x9ac, x86_l_9ac);
x86_l_252:
	/* 0x252: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_255:
	/* 0x255: jne    d58 <generic_sleepable_preload+0xd58> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x255, 0xd58, x86_l_d58);
x86_l_25b:
	/* 0x25b: mov    edx,DWORD PTR [rbx+0x250] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 592ULL);
x86_l_261:
	/* 0x261: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_267:
	/* 0x267: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_26a:
	/* 0x26a: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_26f:
	/* 0x26f: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_272:
	/* 0x272: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_277:
	/* 0x277: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_279:
	/* 0x279: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_27b:
	/* 0x27b: je     9b7 <generic_sleepable_preload+0x9b7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x27b, 0x9b7, x86_l_9b7);
x86_l_281:
	/* 0x281: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_283:
	/* 0x283: jmp    d58 <generic_sleepable_preload+0xd58> */
	X86_SIM_X86_JMP(0x283, 0xd58, x86_l_d58);
x86_l_288:
	/* 0x288: test   al,al */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_8);
x86_l_28a:
	/* 0x28a: js     473 <generic_sleepable_preload+0x473> */
	X86_SIM_X86_JCC(X86_CC_S, 0x28a, 0x473, x86_l_473);
x86_l_290:
	/* 0x290: movzx  ecx,BYTE PTR [rbx+0x271] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 625ULL);
x86_l_297:
	/* 0x297: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_299:
	/* 0x299: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_29c:
	/* 0x29c: jg     644 <generic_sleepable_preload+0x644> */
	X86_SIM_X86_JCC(X86_CC_G, 0x29c, 0x644, x86_l_644);
x86_l_2a2:
	/* 0x2a2: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_2a5:
	/* 0x2a5: je     9e2 <generic_sleepable_preload+0x9e2> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2a5, 0x9e2, x86_l_9e2);
x86_l_2ab:
	/* 0x2ab: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_2ae:
	/* 0x2ae: jne    e58 <generic_sleepable_preload+0xe58> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x2ae, 0xe58, x86_l_e58);
x86_l_2b4:
	/* 0x2b4: mov    eax,DWORD PTR [rbx+0x268] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 616ULL);
x86_l_2ba:
	/* 0x2ba: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_2bf:
	/* 0x2bf: add    r14,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_2c2:
	/* 0x2c2: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_2c7:
	/* 0x2c7: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_2ca:
	/* 0x2ca: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_2cf:
	/* 0x2cf: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_2d2:
	/* 0x2d2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2d4:
	/* 0x2d4: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_2d6:
	/* 0x2d6: je     9ed <generic_sleepable_preload+0x9ed> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2d6, 0x9ed, x86_l_9ed);
x86_l_2dc:
	/* 0x2dc: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2de:
	/* 0x2de: jmp    e58 <generic_sleepable_preload+0xe58> */
	X86_SIM_X86_JMP(0x2de, 0xe58, x86_l_e58);
x86_l_2e3:
	/* 0x2e3: movzx  eax,BYTE PTR [rbx+0x2c2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 706ULL);
x86_l_2ea:
	/* 0x2ea: movzx  ecx,WORD PTR [rbx+0x2c0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 704ULL);
x86_l_2f1:
	/* 0x2f1: rorx   ecx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_2f7:
	/* 0x2f7: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_2fa:
	/* 0x2fa: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_2fd:
	/* 0x2fd: jle    693 <generic_sleepable_preload+0x693> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x2fd, 0x693, x86_l_693);
x86_l_303:
	/* 0x303: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_306:
	/* 0x306: jle    76a <generic_sleepable_preload+0x76a> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x306, 0x76a, x86_l_76a);
x86_l_30c:
	/* 0x30c: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_30f:
	/* 0x30f: jle    10e8 <generic_sleepable_preload+0x10e8> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x30f, 0x10e8, x86_l_10e8);
x86_l_315:
	/* 0x315: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_31d:
	/* 0x31d: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_320:
	/* 0x320: je     10ff <generic_sleepable_preload+0x10ff> */
	X86_SIM_X86_JCC(X86_CC_E, 0x320, 0x10ff, x86_l_10ff);
x86_l_326:
	/* 0x326: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_32b:
	/* 0x32b: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_32e:
	/* 0x32e: je     10ff <generic_sleepable_preload+0x10ff> */
	X86_SIM_X86_JCC(X86_CC_E, 0x32e, 0x10ff, x86_l_10ff);
x86_l_334:
	/* 0x334: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_337:
	/* 0x337: jne    1112 <generic_sleepable_preload+0x1112> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x337, 0x1112, x86_l_1112);
x86_l_33d:
	/* 0x33d: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_342:
	/* 0x342: jmp    10ff <generic_sleepable_preload+0x10ff> */
	X86_SIM_X86_JMP(0x342, 0x10ff, x86_l_10ff);
x86_l_347:
	/* 0x347: movzx  eax,BYTE PTR [rbx+0x2c6] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 710ULL);
x86_l_34e:
	/* 0x34e: movzx  ecx,WORD PTR [rbx+0x2c4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 708ULL);
x86_l_355:
	/* 0x355: rorx   ecx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_35b:
	/* 0x35b: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_35e:
	/* 0x35e: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_361:
	/* 0x361: jle    6c1 <generic_sleepable_preload+0x6c1> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x361, 0x6c1, x86_l_6c1);
x86_l_367:
	/* 0x367: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_36a:
	/* 0x36a: jle    794 <generic_sleepable_preload+0x794> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x36a, 0x794, x86_l_794);
x86_l_370:
	/* 0x370: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_373:
	/* 0x373: jle    11a3 <generic_sleepable_preload+0x11a3> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x373, 0x11a3, x86_l_11a3);
x86_l_379:
	/* 0x379: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_381:
	/* 0x381: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_384:
	/* 0x384: je     1232 <generic_sleepable_preload+0x1232> */
	X86_SIM_X86_JCC(X86_CC_E, 0x384, 0x1232, x86_l_1232);
x86_l_38a:
	/* 0x38a: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_38f:
	/* 0x38f: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_392:
	/* 0x392: je     1232 <generic_sleepable_preload+0x1232> */
	X86_SIM_X86_JCC(X86_CC_E, 0x392, 0x1232, x86_l_1232);
x86_l_398:
	/* 0x398: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_39d:
	/* 0x39d: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_3a0:
	/* 0x3a0: je     1232 <generic_sleepable_preload+0x1232> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3a0, 0x1232, x86_l_1232);
x86_l_3a6:
	/* 0x3a6: jmp    1245 <generic_sleepable_preload+0x1245> */
	X86_SIM_X86_JMP(0x3a6, 0x1245, x86_l_1245);
x86_l_3ab:
	/* 0x3ab: movzx  eax,BYTE PTR [rbx+0x2ca] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 714ULL);
x86_l_3b2:
	/* 0x3b2: movzx  ecx,WORD PTR [rbx+0x2c8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 712ULL);
x86_l_3b9:
	/* 0x3b9: rorx   ecx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_3bf:
	/* 0x3bf: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3c2:
	/* 0x3c2: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_3c5:
	/* 0x3c5: jle    6ec <generic_sleepable_preload+0x6ec> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x3c5, 0x6ec, x86_l_6ec);
x86_l_3cb:
	/* 0x3cb: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_3ce:
	/* 0x3ce: jle    7be <generic_sleepable_preload+0x7be> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x3ce, 0x7be, x86_l_7be);
x86_l_3d4:
	/* 0x3d4: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_3d7:
	/* 0x3d7: jle    11c3 <generic_sleepable_preload+0x11c3> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x3d7, 0x11c3, x86_l_11c3);
x86_l_3dd:
	/* 0x3dd: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_3e5:
	/* 0x3e5: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_3e8:
	/* 0x3e8: je     12d9 <generic_sleepable_preload+0x12d9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3e8, 0x12d9, x86_l_12d9);
x86_l_3ee:
	/* 0x3ee: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_3f3:
	/* 0x3f3: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_3f6:
	/* 0x3f6: je     12d9 <generic_sleepable_preload+0x12d9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x3f6, 0x12d9, x86_l_12d9);
x86_l_3fc:
	/* 0x3fc: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_401:
	/* 0x401: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_404:
	/* 0x404: je     12d9 <generic_sleepable_preload+0x12d9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x404, 0x12d9, x86_l_12d9);
x86_l_40a:
	/* 0x40a: jmp    12ec <generic_sleepable_preload+0x12ec> */
	X86_SIM_X86_JMP(0x40a, 0x12ec, x86_l_12ec);
x86_l_40f:
	/* 0x40f: movzx  eax,BYTE PTR [rbx+0x2ce] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 718ULL);
x86_l_416:
	/* 0x416: movzx  ecx,WORD PTR [rbx+0x2cc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 716ULL);
x86_l_41d:
	/* 0x41d: rorx   ecx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_423:
	/* 0x423: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_426:
	/* 0x426: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_429:
	/* 0x429: jle    717 <generic_sleepable_preload+0x717> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x429, 0x717, x86_l_717);
x86_l_42f:
	/* 0x42f: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_432:
	/* 0x432: jle    7e8 <generic_sleepable_preload+0x7e8> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x432, 0x7e8, x86_l_7e8);
x86_l_438:
	/* 0x438: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_43b:
	/* 0x43b: jle    11e7 <generic_sleepable_preload+0x11e7> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x43b, 0x11e7, x86_l_11e7);
x86_l_441:
	/* 0x441: mov    rdx,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_449:
	/* 0x449: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_44c:
	/* 0x44c: je     1380 <generic_sleepable_preload+0x1380> */
	X86_SIM_X86_JCC(X86_CC_E, 0x44c, 0x1380, x86_l_1380);
x86_l_452:
	/* 0x452: mov    rdx,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_457:
	/* 0x457: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_45a:
	/* 0x45a: je     1380 <generic_sleepable_preload+0x1380> */
	X86_SIM_X86_JCC(X86_CC_E, 0x45a, 0x1380, x86_l_1380);
x86_l_460:
	/* 0x460: mov    rdx,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_465:
	/* 0x465: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_468:
	/* 0x468: je     1380 <generic_sleepable_preload+0x1380> */
	X86_SIM_X86_JCC(X86_CC_E, 0x468, 0x1380, x86_l_1380);
x86_l_46e:
	/* 0x46e: jmp    1393 <generic_sleepable_preload+0x1393> */
	X86_SIM_X86_JMP(0x46e, 0x1393, x86_l_1393);
x86_l_473:
	/* 0x473: movzx  eax,BYTE PTR [rbx+0x2d2] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 722ULL);
x86_l_47a:
	/* 0x47a: movzx  ecx,WORD PTR [rbx+0x2d0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 720ULL);
x86_l_481:
	/* 0x481: rorx   ecx,ecx,0x3 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RCX, X86_WIDTH_32, 0, 3ULL);
x86_l_487:
	/* 0x487: xor    r15d,r15d */
	X86_SIM_L_EXEC_ALU_REG(X86_R15, X86_R15, X86_WIDTH_32, X86_ALU_XOR);
x86_l_48a:
	/* 0x48a: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_48d:
	/* 0x48d: jle    742 <generic_sleepable_preload+0x742> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x48d, 0x742, x86_l_742);
x86_l_493:
	/* 0x493: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_496:
	/* 0x496: jle    812 <generic_sleepable_preload+0x812> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x496, 0x812, x86_l_812);
x86_l_49c:
	/* 0x49c: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_49f:
	/* 0x49f: jle    120b <generic_sleepable_preload+0x120b> */
	X86_SIM_X86_JCC(X86_CC_LE, 0x49f, 0x120b, x86_l_120b);
x86_l_4a5:
	/* 0x4a5: mov    rbp,QWORD PTR [rsp+0x88] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 136ULL);
x86_l_4ad:
	/* 0x4ad: cmp    ecx,0xe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 14ULL);
x86_l_4b0:
	/* 0x4b0: je     1427 <generic_sleepable_preload+0x1427> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4b0, 0x1427, x86_l_1427);
x86_l_4b6:
	/* 0x4b6: mov    rbp,QWORD PTR [rsp+0x50] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 80ULL);
x86_l_4bb:
	/* 0x4bb: cmp    ecx,0x13 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 19ULL);
x86_l_4be:
	/* 0x4be: je     1427 <generic_sleepable_preload+0x1427> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4be, 0x1427, x86_l_1427);
x86_l_4c4:
	/* 0x4c4: mov    rbp,QWORD PTR [rsp+0x48] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_4c9:
	/* 0x4c9: cmp    ecx,0x10 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 16ULL);
x86_l_4cc:
	/* 0x4cc: je     1427 <generic_sleepable_preload+0x1427> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4cc, 0x1427, x86_l_1427);
x86_l_4d2:
	/* 0x4d2: jmp    143b <generic_sleepable_preload+0x143b> */
	X86_SIM_X86_JMP(0x4d2, 0x143b, x86_l_143b);
x86_l_4d7:
	/* 0x4d7: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_4da:
	/* 0x4da: je     a18 <generic_sleepable_preload+0xa18> */
	X86_SIM_X86_JCC(X86_CC_E, 0x4da, 0xa18, x86_l_a18);
x86_l_4e0:
	/* 0x4e0: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_4e3:
	/* 0x4e3: jne    a5e <generic_sleepable_preload+0xa5e> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4e3, 0xa5e, x86_l_a5e);
x86_l_4e9:
	/* 0x4e9: mov    edx,DWORD PTR [rbx+0x208] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_4ef:
	/* 0x4ef: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_4f5:
	/* 0x4f5: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_4f8:
	/* 0x4f8: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_4fd:
	/* 0x4fd: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_500:
	/* 0x500: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_505:
	/* 0x505: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_507:
	/* 0x507: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_509:
	/* 0x509: jne    a5c <generic_sleepable_preload+0xa5c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x509, 0xa5c, x86_l_a5c);
x86_l_50f:
	/* 0x50f: mov    edx,DWORD PTR [rbx+0x20c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 524ULL);
x86_l_515:
	/* 0x515: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_51b:
	/* 0x51b: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_51e:
	/* 0x51e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_523:
	/* 0x523: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_528:
	/* 0x528: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_52d:
	/* 0x52d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_52f:
	/* 0x52f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_531:
	/* 0x531: jne    a5c <generic_sleepable_preload+0xa5c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x531, 0xa5c, x86_l_a5c);
x86_l_537:
	/* 0x537: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_53c:
	/* 0x53c: movzx  ecx,BYTE PTR [rbx+0x213] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 531ULL);
x86_l_543:
	/* 0x543: shlx   rcx,QWORD PTR [rsp+0x8],rcx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_54a:
	/* 0x54a: mov    rdx,QWORD PTR [rbx+0x200] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 512ULL);
x86_l_551:
	/* 0x551: add    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_555:
	/* 0x555: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_558:
	/* 0x558: jmp    a4a <generic_sleepable_preload+0xa4a> */
	X86_SIM_X86_JMP(0x558, 0xa4a, x86_l_a4a);
x86_l_55d:
	/* 0x55d: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_560:
	/* 0x560: je     ae1 <generic_sleepable_preload+0xae1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x560, 0xae1, x86_l_ae1);
x86_l_566:
	/* 0x566: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_569:
	/* 0x569: jne    b5c <generic_sleepable_preload+0xb5c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x569, 0xb5c, x86_l_b5c);
x86_l_56f:
	/* 0x56f: mov    edx,DWORD PTR [rbx+0x220] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 544ULL);
x86_l_575:
	/* 0x575: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_57b:
	/* 0x57b: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_57e:
	/* 0x57e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_583:
	/* 0x583: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_586:
	/* 0x586: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_58b:
	/* 0x58b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_58d:
	/* 0x58d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_58f:
	/* 0x58f: jne    b5a <generic_sleepable_preload+0xb5a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x58f, 0xb5a, x86_l_b5a);
x86_l_595:
	/* 0x595: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_59a:
	/* 0x59a: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_59e:
	/* 0x59e: add    rdx,QWORD PTR [rbx+0x218] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 536ULL);
x86_l_5a5:
	/* 0x5a5: jmp    b48 <generic_sleepable_preload+0xb48> */
	X86_SIM_X86_JMP(0x5a5, 0xb48, x86_l_b48);
x86_l_5aa:
	/* 0x5aa: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_5ad:
	/* 0x5ad: je     bdf <generic_sleepable_preload+0xbdf> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5ad, 0xbdf, x86_l_bdf);
x86_l_5b3:
	/* 0x5b3: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_5b6:
	/* 0x5b6: jne    c5a <generic_sleepable_preload+0xc5a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x5b6, 0xc5a, x86_l_c5a);
x86_l_5bc:
	/* 0x5bc: mov    edx,DWORD PTR [rbx+0x238] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 568ULL);
x86_l_5c2:
	/* 0x5c2: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_5c8:
	/* 0x5c8: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_5cb:
	/* 0x5cb: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_5d0:
	/* 0x5d0: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_5d3:
	/* 0x5d3: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_5d8:
	/* 0x5d8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5da:
	/* 0x5da: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_5dc:
	/* 0x5dc: jne    c58 <generic_sleepable_preload+0xc58> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x5dc, 0xc58, x86_l_c58);
x86_l_5e2:
	/* 0x5e2: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_5e7:
	/* 0x5e7: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5eb:
	/* 0x5eb: add    rdx,QWORD PTR [rbx+0x230] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 560ULL);
x86_l_5f2:
	/* 0x5f2: jmp    c46 <generic_sleepable_preload+0xc46> */
	X86_SIM_X86_JMP(0x5f2, 0xc46, x86_l_c46);
x86_l_5f7:
	/* 0x5f7: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_5fa:
	/* 0x5fa: je     cdd <generic_sleepable_preload+0xcdd> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5fa, 0xcdd, x86_l_cdd);
x86_l_600:
	/* 0x600: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_603:
	/* 0x603: jne    d58 <generic_sleepable_preload+0xd58> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x603, 0xd58, x86_l_d58);
x86_l_609:
	/* 0x609: mov    edx,DWORD PTR [rbx+0x250] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 592ULL);
x86_l_60f:
	/* 0x60f: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_615:
	/* 0x615: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_618:
	/* 0x618: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_61d:
	/* 0x61d: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_620:
	/* 0x620: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_625:
	/* 0x625: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_627:
	/* 0x627: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_629:
	/* 0x629: jne    d56 <generic_sleepable_preload+0xd56> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x629, 0xd56, x86_l_d56);
x86_l_62f:
	/* 0x62f: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_634:
	/* 0x634: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_638:
	/* 0x638: add    rdx,QWORD PTR [rbx+0x248] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 584ULL);
x86_l_63f:
	/* 0x63f: jmp    d44 <generic_sleepable_preload+0xd44> */
	X86_SIM_X86_JMP(0x63f, 0xd44, x86_l_d44);
x86_l_644:
	/* 0x644: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_647:
	/* 0x647: je     ddb <generic_sleepable_preload+0xddb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x647, 0xddb, x86_l_ddb);
x86_l_64d:
	/* 0x64d: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_650:
	/* 0x650: jne    e58 <generic_sleepable_preload+0xe58> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x650, 0xe58, x86_l_e58);
x86_l_656:
	/* 0x656: mov    eax,DWORD PTR [rbx+0x268] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 616ULL);
x86_l_65c:
	/* 0x65c: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_661:
	/* 0x661: add    r14,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_664:
	/* 0x664: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_669:
	/* 0x669: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_66c:
	/* 0x66c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_671:
	/* 0x671: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_674:
	/* 0x674: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_676:
	/* 0x676: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_678:
	/* 0x678: jne    e56 <generic_sleepable_preload+0xe56> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x678, 0xe56, x86_l_e56);
x86_l_67e:
	/* 0x67e: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_683:
	/* 0x683: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_687:
	/* 0x687: add    rdx,QWORD PTR [rbx+0x260] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 608ULL);
x86_l_68e:
	/* 0x68e: jmp    e44 <generic_sleepable_preload+0xe44> */
	X86_SIM_X86_JMP(0x68e, 0xe44, x86_l_e44);
x86_l_693:
	/* 0x693: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_696:
	/* 0x696: jg     83c <generic_sleepable_preload+0x83c> */
	X86_SIM_X86_JCC(X86_CC_G, 0x696, 0x83c, x86_l_83c);
x86_l_69c:
	/* 0x69c: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_69f:
	/* 0x69f: jg     f9e <generic_sleepable_preload+0xf9e> */
	X86_SIM_X86_JCC(X86_CC_G, 0x69f, 0xf9e, x86_l_f9e);
x86_l_6a5:
	/* 0x6a5: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_6a8:
	/* 0x6a8: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_6aa:
	/* 0x6aa: je     10ff <generic_sleepable_preload+0x10ff> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6aa, 0x10ff, x86_l_10ff);
x86_l_6b0:
	/* 0x6b0: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_6b3:
	/* 0x6b3: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_6b6:
	/* 0x6b6: je     10ff <generic_sleepable_preload+0x10ff> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6b6, 0x10ff, x86_l_10ff);
x86_l_6bc:
	/* 0x6bc: jmp    1112 <generic_sleepable_preload+0x1112> */
	X86_SIM_X86_JMP(0x6bc, 0x1112, x86_l_1112);
x86_l_6c1:
	/* 0x6c1: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_6c4:
	/* 0x6c4: jg     866 <generic_sleepable_preload+0x866> */
	X86_SIM_X86_JCC(X86_CC_G, 0x6c4, 0x866, x86_l_866);
x86_l_6ca:
	/* 0x6ca: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_6cd:
	/* 0x6cd: jg     fbf <generic_sleepable_preload+0xfbf> */
	X86_SIM_X86_JCC(X86_CC_G, 0x6cd, 0xfbf, x86_l_fbf);
x86_l_6d3:
	/* 0x6d3: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_6d5:
	/* 0x6d5: je     122f <generic_sleepable_preload+0x122f> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6d5, 0x122f, x86_l_122f);
x86_l_6db:
	/* 0x6db: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_6de:
	/* 0x6de: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_6e1:
	/* 0x6e1: je     1232 <generic_sleepable_preload+0x1232> */
	X86_SIM_X86_JCC(X86_CC_E, 0x6e1, 0x1232, x86_l_1232);
x86_l_6e7:
	/* 0x6e7: jmp    1245 <generic_sleepable_preload+0x1245> */
	X86_SIM_X86_JMP(0x6e7, 0x1245, x86_l_1245);
x86_l_6ec:
	/* 0x6ec: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_6ef:
	/* 0x6ef: jg     890 <generic_sleepable_preload+0x890> */
	X86_SIM_X86_JCC(X86_CC_G, 0x6ef, 0x890, x86_l_890);
x86_l_6f5:
	/* 0x6f5: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_6f8:
	/* 0x6f8: jg     fe0 <generic_sleepable_preload+0xfe0> */
	X86_SIM_X86_JCC(X86_CC_G, 0x6f8, 0xfe0, x86_l_fe0);
x86_l_6fe:
	/* 0x6fe: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_700:
	/* 0x700: je     12d6 <generic_sleepable_preload+0x12d6> */
	X86_SIM_X86_JCC(X86_CC_E, 0x700, 0x12d6, x86_l_12d6);
x86_l_706:
	/* 0x706: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_709:
	/* 0x709: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_70c:
	/* 0x70c: je     12d9 <generic_sleepable_preload+0x12d9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x70c, 0x12d9, x86_l_12d9);
x86_l_712:
	/* 0x712: jmp    12ec <generic_sleepable_preload+0x12ec> */
	X86_SIM_X86_JMP(0x712, 0x12ec, x86_l_12ec);
x86_l_717:
	/* 0x717: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_71a:
	/* 0x71a: jg     8ba <generic_sleepable_preload+0x8ba> */
	X86_SIM_X86_JCC(X86_CC_G, 0x71a, 0x8ba, x86_l_8ba);
x86_l_720:
	/* 0x720: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_723:
	/* 0x723: jg     1001 <generic_sleepable_preload+0x1001> */
	X86_SIM_X86_JCC(X86_CC_G, 0x723, 0x1001, x86_l_1001);
x86_l_729:
	/* 0x729: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_72b:
	/* 0x72b: je     137d <generic_sleepable_preload+0x137d> */
	X86_SIM_X86_JCC(X86_CC_E, 0x72b, 0x137d, x86_l_137d);
x86_l_731:
	/* 0x731: mov    rdx,rbp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBP, X86_WIDTH_64);
x86_l_734:
	/* 0x734: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_737:
	/* 0x737: je     1380 <generic_sleepable_preload+0x1380> */
	X86_SIM_X86_JCC(X86_CC_E, 0x737, 0x1380, x86_l_1380);
x86_l_73d:
	/* 0x73d: jmp    1393 <generic_sleepable_preload+0x1393> */
	X86_SIM_X86_JMP(0x73d, 0x1393, x86_l_1393);
x86_l_742:
	/* 0x742: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_745:
	/* 0x745: jg     8e4 <generic_sleepable_preload+0x8e4> */
	X86_SIM_X86_JCC(X86_CC_G, 0x745, 0x8e4, x86_l_8e4);
x86_l_74b:
	/* 0x74b: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_74e:
	/* 0x74e: jg     1022 <generic_sleepable_preload+0x1022> */
	X86_SIM_X86_JCC(X86_CC_G, 0x74e, 0x1022, x86_l_1022);
x86_l_754:
	/* 0x754: test   ecx,ecx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_32);
x86_l_756:
	/* 0x756: je     1424 <generic_sleepable_preload+0x1424> */
	X86_SIM_X86_JCC(X86_CC_E, 0x756, 0x1424, x86_l_1424);
x86_l_75c:
	/* 0x75c: cmp    ecx,0x1 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 1ULL);
x86_l_75f:
	/* 0x75f: je     1427 <generic_sleepable_preload+0x1427> */
	X86_SIM_X86_JCC(X86_CC_E, 0x75f, 0x1427, x86_l_1427);
x86_l_765:
	/* 0x765: jmp    143b <generic_sleepable_preload+0x143b> */
	X86_SIM_X86_JMP(0x765, 0x143b, x86_l_143b);
x86_l_76a:
	/* 0x76a: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_76d:
	/* 0x76d: jg     ef9 <generic_sleepable_preload+0xef9> */
	X86_SIM_X86_JCC(X86_CC_G, 0x76d, 0xef9, x86_l_ef9);
x86_l_773:
	/* 0x773: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_778:
	/* 0x778: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_77b:
	/* 0x77b: je     10ff <generic_sleepable_preload+0x10ff> */
	X86_SIM_X86_JCC(X86_CC_E, 0x77b, 0x10ff, x86_l_10ff);
x86_l_781:
	/* 0x781: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_786:
	/* 0x786: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_789:
	/* 0x789: je     10ff <generic_sleepable_preload+0x10ff> */
	X86_SIM_X86_JCC(X86_CC_E, 0x789, 0x10ff, x86_l_10ff);
x86_l_78f:
	/* 0x78f: jmp    1112 <generic_sleepable_preload+0x1112> */
	X86_SIM_X86_JMP(0x78f, 0x1112, x86_l_1112);
x86_l_794:
	/* 0x794: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_797:
	/* 0x797: jg     f1a <generic_sleepable_preload+0xf1a> */
	X86_SIM_X86_JCC(X86_CC_G, 0x797, 0xf1a, x86_l_f1a);
x86_l_79d:
	/* 0x79d: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_7a2:
	/* 0x7a2: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_7a5:
	/* 0x7a5: je     1232 <generic_sleepable_preload+0x1232> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7a5, 0x1232, x86_l_1232);
x86_l_7ab:
	/* 0x7ab: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7b0:
	/* 0x7b0: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_7b3:
	/* 0x7b3: je     1232 <generic_sleepable_preload+0x1232> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7b3, 0x1232, x86_l_1232);
x86_l_7b9:
	/* 0x7b9: jmp    1245 <generic_sleepable_preload+0x1245> */
	X86_SIM_X86_JMP(0x7b9, 0x1245, x86_l_1245);
x86_l_7be:
	/* 0x7be: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_7c1:
	/* 0x7c1: jg     f3b <generic_sleepable_preload+0xf3b> */
	X86_SIM_X86_JCC(X86_CC_G, 0x7c1, 0xf3b, x86_l_f3b);
x86_l_7c7:
	/* 0x7c7: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_7cc:
	/* 0x7cc: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_7cf:
	/* 0x7cf: je     12d9 <generic_sleepable_preload+0x12d9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7cf, 0x12d9, x86_l_12d9);
x86_l_7d5:
	/* 0x7d5: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_7da:
	/* 0x7da: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_7dd:
	/* 0x7dd: je     12d9 <generic_sleepable_preload+0x12d9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7dd, 0x12d9, x86_l_12d9);
x86_l_7e3:
	/* 0x7e3: jmp    12ec <generic_sleepable_preload+0x12ec> */
	X86_SIM_X86_JMP(0x7e3, 0x12ec, x86_l_12ec);
x86_l_7e8:
	/* 0x7e8: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_7eb:
	/* 0x7eb: jg     f5c <generic_sleepable_preload+0xf5c> */
	X86_SIM_X86_JCC(X86_CC_G, 0x7eb, 0xf5c, x86_l_f5c);
x86_l_7f1:
	/* 0x7f1: mov    rdx,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_7f6:
	/* 0x7f6: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_7f9:
	/* 0x7f9: je     1380 <generic_sleepable_preload+0x1380> */
	X86_SIM_X86_JCC(X86_CC_E, 0x7f9, 0x1380, x86_l_1380);
x86_l_7ff:
	/* 0x7ff: mov    rdx,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_804:
	/* 0x804: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_807:
	/* 0x807: je     1380 <generic_sleepable_preload+0x1380> */
	X86_SIM_X86_JCC(X86_CC_E, 0x807, 0x1380, x86_l_1380);
x86_l_80d:
	/* 0x80d: jmp    1393 <generic_sleepable_preload+0x1393> */
	X86_SIM_X86_JMP(0x80d, 0x1393, x86_l_1393);
x86_l_812:
	/* 0x812: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_815:
	/* 0x815: jg     f7d <generic_sleepable_preload+0xf7d> */
	X86_SIM_X86_JCC(X86_CC_G, 0x815, 0xf7d, x86_l_f7d);
x86_l_81b:
	/* 0x81b: mov    rbp,QWORD PTR [rsp+0x70] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 112ULL);
x86_l_820:
	/* 0x820: cmp    ecx,0x8 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 8ULL);
x86_l_823:
	/* 0x823: je     1427 <generic_sleepable_preload+0x1427> */
	X86_SIM_X86_JCC(X86_CC_E, 0x823, 0x1427, x86_l_1427);
x86_l_829:
	/* 0x829: mov    rbp,QWORD PTR [rsp+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 48ULL);
x86_l_82e:
	/* 0x82e: cmp    ecx,0x9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 9ULL);
x86_l_831:
	/* 0x831: je     1427 <generic_sleepable_preload+0x1427> */
	X86_SIM_X86_JCC(X86_CC_E, 0x831, 0x1427, x86_l_1427);
x86_l_837:
	/* 0x837: jmp    143b <generic_sleepable_preload+0x143b> */
	X86_SIM_X86_JMP(0x837, 0x143b, x86_l_143b);
x86_l_83c:
	/* 0x83c: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_83f:
	/* 0x83f: jg     1043 <generic_sleepable_preload+0x1043> */
	X86_SIM_X86_JCC(X86_CC_G, 0x83f, 0x1043, x86_l_1043);
x86_l_845:
	/* 0x845: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_84a:
	/* 0x84a: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_84d:
	/* 0x84d: je     10ff <generic_sleepable_preload+0x10ff> */
	X86_SIM_X86_JCC(X86_CC_E, 0x84d, 0x10ff, x86_l_10ff);
x86_l_853:
	/* 0x853: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_858:
	/* 0x858: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_85b:
	/* 0x85b: je     10ff <generic_sleepable_preload+0x10ff> */
	X86_SIM_X86_JCC(X86_CC_E, 0x85b, 0x10ff, x86_l_10ff);
x86_l_861:
	/* 0x861: jmp    1112 <generic_sleepable_preload+0x1112> */
	X86_SIM_X86_JMP(0x861, 0x1112, x86_l_1112);
x86_l_866:
	/* 0x866: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_869:
	/* 0x869: jg     1064 <generic_sleepable_preload+0x1064> */
	X86_SIM_X86_JCC(X86_CC_G, 0x869, 0x1064, x86_l_1064);
x86_l_86f:
	/* 0x86f: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_874:
	/* 0x874: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_877:
	/* 0x877: je     1232 <generic_sleepable_preload+0x1232> */
	X86_SIM_X86_JCC(X86_CC_E, 0x877, 0x1232, x86_l_1232);
x86_l_87d:
	/* 0x87d: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_882:
	/* 0x882: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_885:
	/* 0x885: je     1232 <generic_sleepable_preload+0x1232> */
	X86_SIM_X86_JCC(X86_CC_E, 0x885, 0x1232, x86_l_1232);
x86_l_88b:
	/* 0x88b: jmp    1245 <generic_sleepable_preload+0x1245> */
	X86_SIM_X86_JMP(0x88b, 0x1245, x86_l_1245);
x86_l_890:
	/* 0x890: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_893:
	/* 0x893: jg     1085 <generic_sleepable_preload+0x1085> */
	X86_SIM_X86_JCC(X86_CC_G, 0x893, 0x1085, x86_l_1085);
x86_l_899:
	/* 0x899: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_89e:
	/* 0x89e: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_8a1:
	/* 0x8a1: je     12d9 <generic_sleepable_preload+0x12d9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8a1, 0x12d9, x86_l_12d9);
x86_l_8a7:
	/* 0x8a7: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_8ac:
	/* 0x8ac: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_8af:
	/* 0x8af: je     12d9 <generic_sleepable_preload+0x12d9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8af, 0x12d9, x86_l_12d9);
x86_l_8b5:
	/* 0x8b5: jmp    12ec <generic_sleepable_preload+0x12ec> */
	X86_SIM_X86_JMP(0x8b5, 0x12ec, x86_l_12ec);
x86_l_8ba:
	/* 0x8ba: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_8bd:
	/* 0x8bd: jg     10a6 <generic_sleepable_preload+0x10a6> */
	X86_SIM_X86_JCC(X86_CC_G, 0x8bd, 0x10a6, x86_l_10a6);
x86_l_8c3:
	/* 0x8c3: mov    rdx,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_8c8:
	/* 0x8c8: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_8cb:
	/* 0x8cb: je     1380 <generic_sleepable_preload+0x1380> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8cb, 0x1380, x86_l_1380);
x86_l_8d1:
	/* 0x8d1: mov    rdx,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_8d6:
	/* 0x8d6: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_8d9:
	/* 0x8d9: je     1380 <generic_sleepable_preload+0x1380> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8d9, 0x1380, x86_l_1380);
x86_l_8df:
	/* 0x8df: jmp    1393 <generic_sleepable_preload+0x1393> */
	X86_SIM_X86_JMP(0x8df, 0x1393, x86_l_1393);
x86_l_8e4:
	/* 0x8e4: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_8e7:
	/* 0x8e7: jg     10c7 <generic_sleepable_preload+0x10c7> */
	X86_SIM_X86_JCC(X86_CC_G, 0x8e7, 0x10c7, x86_l_10c7);
x86_l_8ed:
	/* 0x8ed: mov    rbp,QWORD PTR [rsp+0x60] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 96ULL);
x86_l_8f2:
	/* 0x8f2: cmp    ecx,0x4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 4ULL);
x86_l_8f5:
	/* 0x8f5: je     1427 <generic_sleepable_preload+0x1427> */
	X86_SIM_X86_JCC(X86_CC_E, 0x8f5, 0x1427, x86_l_1427);
x86_l_8fb:
	/* 0x8fb: mov    rbp,QWORD PTR [rsp+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_900:
	/* 0x900: cmp    ecx,0x5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 5ULL);
x86_l_903:
	/* 0x903: je     1427 <generic_sleepable_preload+0x1427> */
	X86_SIM_X86_JCC(X86_CC_E, 0x903, 0x1427, x86_l_1427);
x86_l_909:
	/* 0x909: jmp    143b <generic_sleepable_preload+0x143b> */
	X86_SIM_X86_JMP(0x909, 0x143b, x86_l_143b);
x86_l_90e:
	/* 0x90e: mov    rax,QWORD PTR [rbx+0x200] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 512ULL);
x86_l_915:
	/* 0x915: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_919:
	/* 0x919: movzx  eax,BYTE PTR [rbx+0x210] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 528ULL);
x86_l_920:
	/* 0x920: shlx   rcx,QWORD PTR [rsp],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((0ULL << 32) | X86_ALU_SHL));
x86_l_926:
	/* 0x926: cmp    BYTE PTR [rbx+0x212],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2276332666880ULL);
x86_l_92d:
	/* 0x92d: shrx   rdx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SHR);
x86_l_932:
	/* 0x932: sarx   rax,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RAX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SAR);
x86_l_937:
	/* 0x937: cmove  rax,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_93b:
	/* 0x93b: jmp    a5e <generic_sleepable_preload+0xa5e> */
	X86_SIM_X86_JMP(0x93b, 0xa5e, x86_l_a5e);
x86_l_940:
	/* 0x940: mov    rax,QWORD PTR [rbx+0x218] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 536ULL);
x86_l_947:
	/* 0x947: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_94b:
	/* 0x94b: movzx  eax,BYTE PTR [rbx+0x228] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 552ULL);
x86_l_952:
	/* 0x952: shlx   rcx,QWORD PTR [rsp],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((0ULL << 32) | X86_ALU_SHL));
x86_l_958:
	/* 0x958: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_95c:
	/* 0x95c: cmp    BYTE PTR [rbx+0x22a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2379411881984ULL);
x86_l_963:
	/* 0x963: shrx   rdx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SHR);
x86_l_968:
	/* 0x968: sarx   rax,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RAX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SAR);
x86_l_96d:
	/* 0x96d: cmove  rax,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_971:
	/* 0x971: jmp    b5c <generic_sleepable_preload+0xb5c> */
	X86_SIM_X86_JMP(0x971, 0xb5c, x86_l_b5c);
x86_l_976:
	/* 0x976: mov    rax,QWORD PTR [rbx+0x230] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 560ULL);
x86_l_97d:
	/* 0x97d: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_981:
	/* 0x981: movzx  eax,BYTE PTR [rbx+0x240] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 576ULL);
x86_l_988:
	/* 0x988: shlx   rcx,QWORD PTR [rsp],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((0ULL << 32) | X86_ALU_SHL));
x86_l_98e:
	/* 0x98e: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_992:
	/* 0x992: cmp    BYTE PTR [rbx+0x242],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2482491097088ULL);
x86_l_999:
	/* 0x999: shrx   rdx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SHR);
x86_l_99e:
	/* 0x99e: sarx   rax,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RAX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SAR);
x86_l_9a3:
	/* 0x9a3: cmove  rax,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_9a7:
	/* 0x9a7: jmp    c5a <generic_sleepable_preload+0xc5a> */
	X86_SIM_X86_JMP(0x9a7, 0xc5a, x86_l_c5a);
x86_l_9ac:
	/* 0x9ac: mov    rax,QWORD PTR [rbx+0x248] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584ULL);
x86_l_9b3:
	/* 0x9b3: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9b7:
	/* 0x9b7: movzx  eax,BYTE PTR [rbx+0x258] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 600ULL);
x86_l_9be:
	/* 0x9be: shlx   rcx,QWORD PTR [rsp],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((0ULL << 32) | X86_ALU_SHL));
x86_l_9c4:
	/* 0x9c4: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9c8:
	/* 0x9c8: cmp    BYTE PTR [rbx+0x25a],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2585570312192ULL);
x86_l_9cf:
	/* 0x9cf: shrx   rdx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SHR);
x86_l_9d4:
	/* 0x9d4: sarx   rax,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RAX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SAR);
x86_l_9d9:
	/* 0x9d9: cmove  rax,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_9dd:
	/* 0x9dd: jmp    d58 <generic_sleepable_preload+0xd58> */
	X86_SIM_X86_JMP(0x9dd, 0xd58, x86_l_d58);
x86_l_9e2:
	/* 0x9e2: mov    rax,QWORD PTR [rbx+0x260] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 608ULL);
x86_l_9e9:
	/* 0x9e9: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9ed:
	/* 0x9ed: movzx  eax,BYTE PTR [rbx+0x270] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 624ULL);
x86_l_9f4:
	/* 0x9f4: shlx   rcx,QWORD PTR [rsp],rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), ((0ULL << 32) | X86_ALU_SHL));
x86_l_9fa:
	/* 0x9fa: mov    QWORD PTR [rsp],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_9fe:
	/* 0x9fe: cmp    BYTE PTR [rbx+0x272],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 2688649527296ULL);
x86_l_a05:
	/* 0xa05: shrx   rdx,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RDX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SHR);
x86_l_a0a:
	/* 0xa0a: sarx   rax,rcx,rax */
	X86_SIM_RUN_OP(X86_OP_SHIFTX, X86_RAX, X86_RCX, X86_WIDTH_64, X86_RAX, X86_ALU_SAR);
x86_l_a0f:
	/* 0xa0f: cmove  rax,rdx */
	X86_SIM_L_EXEC_CMOV(X86_RAX, X86_RDX, X86_WIDTH_64, X86_CC_E);
x86_l_a13:
	/* 0xa13: jmp    e58 <generic_sleepable_preload+0xe58> */
	X86_SIM_X86_JMP(0xa13, 0xe58, x86_l_e58);
x86_l_a18:
	/* 0xa18: mov    edx,DWORD PTR [rbx+0x208] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 520ULL);
x86_l_a1e:
	/* 0xa1e: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_a24:
	/* 0xa24: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_a27:
	/* 0xa27: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_a2c:
	/* 0xa2c: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_a2f:
	/* 0xa2f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a34:
	/* 0xa34: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a36:
	/* 0xa36: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a38:
	/* 0xa38: jne    a5c <generic_sleepable_preload+0xa5c> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa38, 0xa5c, x86_l_a5c);
x86_l_a3a:
	/* 0xa3a: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_a3f:
	/* 0xa3f: mov    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a43:
	/* 0xa43: add    rdx,QWORD PTR [rbx+0x200] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RBX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 512ULL);
x86_l_a4a:
	/* 0xa4a: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_a4d:
	/* 0xa4d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a52:
	/* 0xa52: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a54:
	/* 0xa54: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_a56:
	/* 0xa56: je     919 <generic_sleepable_preload+0x919> */
	X86_SIM_X86_JCC(X86_CC_E, 0xa56, 0x919, x86_l_919);
x86_l_a5c:
	/* 0xa5c: cdqe */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RAX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_a5e:
	/* 0xa5e: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a63:
	/* 0xa63: mov    r15d,DWORD PTR [rbx+0x4] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_a67:
	/* 0xa67: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_a6c:
	/* 0xa6c: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a71:
	/* 0xa71: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_a76:
	/* 0xa76: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_a79:
	/* 0xa79: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a7b:
	/* 0xa7b: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_a7f:
	/* 0xa7f: jne    db <generic_sleepable_preload+0xdb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xa7f, 0xdb, x86_l_db);
x86_l_a85:
	/* 0xa85: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_a8a:
	/* 0xa8a: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_a8f:
	/* 0xa8f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a91:
	/* 0xa91: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a95:
	/* 0xa95: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_a9d:
	/* 0xa9d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_aa2:
	/* 0xaa2: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_aa9:
	/* 0xaa9: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_aae:
	/* 0xaae: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ab0:
	/* 0xab0: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_ab3:
	/* 0xab3: je     db <generic_sleepable_preload+0xdb> */
	X86_SIM_X86_JCC(X86_CC_E, 0xab3, 0xdb, x86_l_db);
x86_l_ab9:
	/* 0xab9: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_abf:
	/* 0xabf: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_ac6:
	/* 0xac6: mov    r13,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSP, X86_WIDTH_64);
x86_l_ac9:
	/* 0xac9: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_acc:
	/* 0xacc: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_acf:
	/* 0xacf: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_ad2:
	/* 0xad2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ad4:
	/* 0xad4: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_ad7:
	/* 0xad7: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_adc:
	/* 0xadc: jmp    116e <generic_sleepable_preload+0x116e> */
	X86_SIM_X86_JMP(0xadc, 0x116e, x86_l_116e);
x86_l_ae1:
	/* 0xae1: mov    edx,DWORD PTR [rbx+0x220] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 544ULL);
x86_l_ae7:
	/* 0xae7: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_aed:
	/* 0xaed: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_af0:
	/* 0xaf0: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_af5:
	/* 0xaf5: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_af8:
	/* 0xaf8: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_afd:
	/* 0xafd: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_aff:
	/* 0xaff: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b01:
	/* 0xb01: jne    b5a <generic_sleepable_preload+0xb5a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb01, 0xb5a, x86_l_b5a);
x86_l_b03:
	/* 0xb03: mov    edx,DWORD PTR [rbx+0x224] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 548ULL);
x86_l_b09:
	/* 0xb09: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_b0f:
	/* 0xb0f: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_b12:
	/* 0xb12: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_b17:
	/* 0xb17: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b1c:
	/* 0xb1c: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b21:
	/* 0xb21: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b23:
	/* 0xb23: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b25:
	/* 0xb25: jne    b5a <generic_sleepable_preload+0xb5a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb25, 0xb5a, x86_l_b5a);
x86_l_b27:
	/* 0xb27: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_b2c:
	/* 0xb2c: movzx  ecx,BYTE PTR [rbx+0x22b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 555ULL);
x86_l_b33:
	/* 0xb33: shlx   rcx,QWORD PTR [rsp+0x8],rcx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_b3a:
	/* 0xb3a: mov    rdx,QWORD PTR [rbx+0x218] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 536ULL);
x86_l_b41:
	/* 0xb41: add    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_b45:
	/* 0xb45: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_b48:
	/* 0xb48: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_b4b:
	/* 0xb4b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b50:
	/* 0xb50: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b52:
	/* 0xb52: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b54:
	/* 0xb54: je     94b <generic_sleepable_preload+0x94b> */
	X86_SIM_X86_JCC(X86_CC_E, 0xb54, 0x94b, x86_l_94b);
x86_l_b5a:
	/* 0xb5a: cdqe */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RAX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_b5c:
	/* 0xb5c: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b61:
	/* 0xb61: mov    r15d,DWORD PTR [rbx+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b65:
	/* 0xb65: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_b6a:
	/* 0xb6a: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b6f:
	/* 0xb6f: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_b74:
	/* 0xb74: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_b77:
	/* 0xb77: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b79:
	/* 0xb79: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_b7d:
	/* 0xb7d: jne    e9 <generic_sleepable_preload+0xe9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xb7d, 0xe9, x86_l_e9);
x86_l_b83:
	/* 0xb83: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_b88:
	/* 0xb88: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_b8d:
	/* 0xb8d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_b8f:
	/* 0xb8f: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_b93:
	/* 0xb93: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_b9b:
	/* 0xb9b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ba0:
	/* 0xba0: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_ba7:
	/* 0xba7: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bac:
	/* 0xbac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bae:
	/* 0xbae: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_bb1:
	/* 0xbb1: je     e9 <generic_sleepable_preload+0xe9> */
	X86_SIM_X86_JCC(X86_CC_E, 0xbb1, 0xe9, x86_l_e9);
x86_l_bb7:
	/* 0xbb7: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_bbd:
	/* 0xbbd: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_bc4:
	/* 0xbc4: mov    r13,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSP, X86_WIDTH_64);
x86_l_bc7:
	/* 0xbc7: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_bca:
	/* 0xbca: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_bcd:
	/* 0xbcd: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_bd0:
	/* 0xbd0: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_bd2:
	/* 0xbd2: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_bd5:
	/* 0xbd5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_bda:
	/* 0xbda: jmp    12a1 <generic_sleepable_preload+0x12a1> */
	X86_SIM_X86_JMP(0xbda, 0x12a1, x86_l_12a1);
x86_l_bdf:
	/* 0xbdf: mov    edx,DWORD PTR [rbx+0x238] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 568ULL);
x86_l_be5:
	/* 0xbe5: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_beb:
	/* 0xbeb: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_bee:
	/* 0xbee: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_bf3:
	/* 0xbf3: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_bf6:
	/* 0xbf6: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_bfb:
	/* 0xbfb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_bfd:
	/* 0xbfd: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_bff:
	/* 0xbff: jne    c58 <generic_sleepable_preload+0xc58> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xbff, 0xc58, x86_l_c58);
x86_l_c01:
	/* 0xc01: mov    edx,DWORD PTR [rbx+0x23c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 572ULL);
x86_l_c07:
	/* 0xc07: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_c0d:
	/* 0xc0d: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_c10:
	/* 0xc10: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_c15:
	/* 0xc15: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_c1a:
	/* 0xc1a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c1f:
	/* 0xc1f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c21:
	/* 0xc21: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c23:
	/* 0xc23: jne    c58 <generic_sleepable_preload+0xc58> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xc23, 0xc58, x86_l_c58);
x86_l_c25:
	/* 0xc25: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_c2a:
	/* 0xc2a: movzx  ecx,BYTE PTR [rbx+0x243] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 579ULL);
x86_l_c31:
	/* 0xc31: shlx   rcx,QWORD PTR [rsp+0x8],rcx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_c38:
	/* 0xc38: mov    rdx,QWORD PTR [rbx+0x230] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 560ULL);
x86_l_c3f:
	/* 0xc3f: add    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_c43:
	/* 0xc43: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_c46:
	/* 0xc46: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_c49:
	/* 0xc49: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c4e:
	/* 0xc4e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c50:
	/* 0xc50: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_c52:
	/* 0xc52: je     981 <generic_sleepable_preload+0x981> */
	X86_SIM_X86_JCC(X86_CC_E, 0xc52, 0x981, x86_l_981);
x86_l_c58:
	/* 0xc58: cdqe */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RAX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_c5a:
	/* 0xc5a: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c5f:
	/* 0xc5f: mov    r15d,DWORD PTR [rbx+0xc] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_c63:
	/* 0xc63: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_c68:
	/* 0xc68: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c6d:
	/* 0xc6d: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_c72:
	/* 0xc72: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_c75:
	/* 0xc75: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c77:
	/* 0xc77: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_c7b:
	/* 0xc7b: jne    f7 <generic_sleepable_preload+0xf7> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xc7b, 0xf7, x86_l_f7);
x86_l_c81:
	/* 0xc81: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_c86:
	/* 0xc86: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_c8b:
	/* 0xc8b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c8d:
	/* 0xc8d: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c91:
	/* 0xc91: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_c99:
	/* 0xc99: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_c9e:
	/* 0xc9e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_ca5:
	/* 0xca5: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_caa:
	/* 0xcaa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cac:
	/* 0xcac: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_caf:
	/* 0xcaf: je     f7 <generic_sleepable_preload+0xf7> */
	X86_SIM_X86_JCC(X86_CC_E, 0xcaf, 0xf7, x86_l_f7);
x86_l_cb5:
	/* 0xcb5: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_cbb:
	/* 0xcbb: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_cc2:
	/* 0xcc2: mov    r13,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSP, X86_WIDTH_64);
x86_l_cc5:
	/* 0xcc5: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_cc8:
	/* 0xcc8: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_ccb:
	/* 0xccb: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_cce:
	/* 0xcce: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_cd0:
	/* 0xcd0: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_cd3:
	/* 0xcd3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_cd8:
	/* 0xcd8: jmp    1348 <generic_sleepable_preload+0x1348> */
	X86_SIM_X86_JMP(0xcd8, 0x1348, x86_l_1348);
x86_l_cdd:
	/* 0xcdd: mov    edx,DWORD PTR [rbx+0x250] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 592ULL);
x86_l_ce3:
	/* 0xce3: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_ce9:
	/* 0xce9: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_cec:
	/* 0xcec: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_cf1:
	/* 0xcf1: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_cf4:
	/* 0xcf4: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_cf9:
	/* 0xcf9: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_cfb:
	/* 0xcfb: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_cfd:
	/* 0xcfd: jne    d56 <generic_sleepable_preload+0xd56> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xcfd, 0xd56, x86_l_d56);
x86_l_cff:
	/* 0xcff: mov    edx,DWORD PTR [rbx+0x254] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 596ULL);
x86_l_d05:
	/* 0xd05: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_d0b:
	/* 0xd0b: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_d0e:
	/* 0xd0e: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_d13:
	/* 0xd13: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_d18:
	/* 0xd18: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d1d:
	/* 0xd1d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d1f:
	/* 0xd1f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_d21:
	/* 0xd21: jne    d56 <generic_sleepable_preload+0xd56> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xd21, 0xd56, x86_l_d56);
x86_l_d23:
	/* 0xd23: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_d28:
	/* 0xd28: movzx  ecx,BYTE PTR [rbx+0x25b] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 603ULL);
x86_l_d2f:
	/* 0xd2f: shlx   rcx,QWORD PTR [rsp+0x8],rcx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_d36:
	/* 0xd36: mov    rdx,QWORD PTR [rbx+0x248] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 584ULL);
x86_l_d3d:
	/* 0xd3d: add    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_d41:
	/* 0xd41: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_d44:
	/* 0xd44: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_d47:
	/* 0xd47: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d4c:
	/* 0xd4c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d4e:
	/* 0xd4e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_d50:
	/* 0xd50: je     9b7 <generic_sleepable_preload+0x9b7> */
	X86_SIM_X86_JCC(X86_CC_E, 0xd50, 0x9b7, x86_l_9b7);
x86_l_d56:
	/* 0xd56: cdqe */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RAX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_d58:
	/* 0xd58: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d5d:
	/* 0xd5d: mov    r15d,DWORD PTR [rbx+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d61:
	/* 0xd61: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_d66:
	/* 0xd66: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d6b:
	/* 0xd6b: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_d70:
	/* 0xd70: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_d73:
	/* 0xd73: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d75:
	/* 0xd75: cmp    r15d,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R15, X86_WIDTH_32, 6ULL);
x86_l_d79:
	/* 0xd79: jne    105 <generic_sleepable_preload+0x105> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xd79, 0x105, x86_l_105);
x86_l_d7f:
	/* 0xd7f: mov    r15,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_R15, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_d84:
	/* 0xd84: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_d89:
	/* 0xd89: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_d8b:
	/* 0xd8b: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_d8f:
	/* 0xd8f: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_d97:
	/* 0xd97: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_d9c:
	/* 0xd9c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_da3:
	/* 0xda3: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_da8:
	/* 0xda8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_daa:
	/* 0xdaa: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_dad:
	/* 0xdad: je     105 <generic_sleepable_preload+0x105> */
	X86_SIM_X86_JCC(X86_CC_E, 0xdad, 0x105, x86_l_105);
x86_l_db3:
	/* 0xdb3: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_db9:
	/* 0xdb9: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_dc0:
	/* 0xdc0: mov    r13,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSP, X86_WIDTH_64);
x86_l_dc3:
	/* 0xdc3: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_dc6:
	/* 0xdc6: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_dc9:
	/* 0xdc9: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_dcc:
	/* 0xdcc: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_dce:
	/* 0xdce: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_dd1:
	/* 0xdd1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_dd6:
	/* 0xdd6: jmp    13ef <generic_sleepable_preload+0x13ef> */
	X86_SIM_X86_JMP(0xdd6, 0x13ef, x86_l_13ef);
x86_l_ddb:
	/* 0xddb: mov    edx,DWORD PTR [rbx+0x268] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 616ULL);
x86_l_de1:
	/* 0xde1: and    edx,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_de7:
	/* 0xde7: add    rdx,r14 */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_R14, X86_WIDTH_64, X86_ALU_ADD);
x86_l_dea:
	/* 0xdea: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_def:
	/* 0xdef: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_df2:
	/* 0xdf2: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_df7:
	/* 0xdf7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_df9:
	/* 0xdf9: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_dfb:
	/* 0xdfb: jne    e56 <generic_sleepable_preload+0xe56> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xdfb, 0xe56, x86_l_e56);
x86_l_dfd:
	/* 0xdfd: mov    eax,DWORD PTR [rbx+0x26c] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 620ULL);
x86_l_e03:
	/* 0xe03: and    eax,0xfff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 4095ULL);
x86_l_e08:
	/* 0xe08: add    r14,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_e0b:
	/* 0xe0b: mov    eax,0x71 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 113ULL);
x86_l_e10:
	/* 0xe10: lea    rdi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_e15:
	/* 0xe15: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e1a:
	/* 0xe1a: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_e1d:
	/* 0xe1d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e1f:
	/* 0xe1f: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_e21:
	/* 0xe21: jne    e56 <generic_sleepable_preload+0xe56> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe21, 0xe56, x86_l_e56);
x86_l_e23:
	/* 0xe23: mov    eax,0x94 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 148ULL);
x86_l_e28:
	/* 0xe28: movzx  ecx,BYTE PTR [rbx+0x273] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8), 627ULL);
x86_l_e2f:
	/* 0xe2f: shlx   rcx,QWORD PTR [rsp+0x8],rcx */
	X86_SIM_RUN_OP(X86_OP_SHIFTX_MEM, X86_RCX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RCX)), ((8ULL << 32) | X86_ALU_SHL));
x86_l_e36:
	/* 0xe36: mov    rdx,QWORD PTR [rbx+0x260] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 608ULL);
x86_l_e3d:
	/* 0xe3d: add    rdx,QWORD PTR [rsp] */
	X86_SIM_L_EXEC_ALU_MEM(X86_RDX, X86_RSP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_ADD)), 0ULL);
x86_l_e41:
	/* 0xe41: add    rdx,rcx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RCX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_e44:
	/* 0xe44: mov    rdi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RSP, X86_WIDTH_64);
x86_l_e47:
	/* 0xe47: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e4c:
	/* 0xe4c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e4e:
	/* 0xe4e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_e50:
	/* 0xe50: je     9ed <generic_sleepable_preload+0x9ed> */
	X86_SIM_X86_JCC(X86_CC_E, 0xe50, 0x9ed, x86_l_9ed);
x86_l_e56:
	/* 0xe56: cdqe */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RAX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_e58:
	/* 0xe58: mov    QWORD PTR [rsp+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e5d:
	/* 0xe5d: mov    ebx,DWORD PTR [rbx+0x14] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_e60:
	/* 0xe60: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_e65:
	/* 0xe65: lea    rdi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e6a:
	/* 0xe6a: mov    esi,0x8 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 8ULL);
x86_l_e6f:
	/* 0xe6f: mov    rdx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RDI, X86_WIDTH_64);
x86_l_e72:
	/* 0xe72: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e74:
	/* 0xe74: cmp    ebx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_32, 6ULL);
x86_l_e77:
	/* 0xe77: jne    113 <generic_sleepable_preload+0x113> */
	X86_SIM_X86_JCC(X86_CC_NE, 0xe77, 0x113, x86_l_113);
x86_l_e7d:
	/* 0xe7d: mov    rbx,QWORD PTR [rsp+0x10] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_e82:
	/* 0xe82: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_e87:
	/* 0xe87: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e89:
	/* 0xe89: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_e8d:
	/* 0xe8d: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_e95:
	/* 0xe95: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_e9a:
	/* 0xe9a: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_ea1:
	/* 0xea1: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_ea6:
	/* 0xea6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ea8:
	/* 0xea8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_eab:
	/* 0xeab: je     113 <generic_sleepable_preload+0x113> */
	X86_SIM_X86_JCC(X86_CC_E, 0xeab, 0x113, x86_l_113);
x86_l_eb1:
	/* 0xeb1: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_eb7:
	/* 0xeb7: mov    r14,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R14, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_ebe:
	/* 0xebe: mov    r15,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSP, X86_WIDTH_64);
x86_l_ec1:
	/* 0xec1: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_ec4:
	/* 0xec4: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_ec7:
	/* 0xec7: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_eca:
	/* 0xeca: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ecc:
	/* 0xecc: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_ecf:
	/* 0xecf: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_ed4:
	/* 0xed4: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_ed7:
	/* 0xed7: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_eda:
	/* 0xeda: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_edc:
	/* 0xedc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_edf:
	/* 0xedf: je     113 <generic_sleepable_preload+0x113> */
	X86_SIM_X86_JCC(X86_CC_E, 0xedf, 0x113, x86_l_113);
x86_l_ee5:
	/* 0xee5: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_ee8:
	/* 0xee8: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_eec:
	/* 0xeec: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_ef1:
	/* 0xef1: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_ef4:
	/* 0xef4: jmp    14b7 <generic_sleepable_preload+0x14b7> */
	X86_SIM_X86_JMP(0xef4, 0x14b7, x86_l_14b7);
x86_l_ef9:
	/* 0xef9: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_efe:
	/* 0xefe: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_f01:
	/* 0xf01: je     10ff <generic_sleepable_preload+0x10ff> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf01, 0x10ff, x86_l_10ff);
x86_l_f07:
	/* 0xf07: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_f0c:
	/* 0xf0c: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_f0f:
	/* 0xf0f: je     10ff <generic_sleepable_preload+0x10ff> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf0f, 0x10ff, x86_l_10ff);
x86_l_f15:
	/* 0xf15: jmp    1112 <generic_sleepable_preload+0x1112> */
	X86_SIM_X86_JMP(0xf15, 0x1112, x86_l_1112);
x86_l_f1a:
	/* 0xf1a: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_f1f:
	/* 0xf1f: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_f22:
	/* 0xf22: je     1232 <generic_sleepable_preload+0x1232> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf22, 0x1232, x86_l_1232);
x86_l_f28:
	/* 0xf28: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_f2d:
	/* 0xf2d: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_f30:
	/* 0xf30: je     1232 <generic_sleepable_preload+0x1232> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf30, 0x1232, x86_l_1232);
x86_l_f36:
	/* 0xf36: jmp    1245 <generic_sleepable_preload+0x1245> */
	X86_SIM_X86_JMP(0xf36, 0x1245, x86_l_1245);
x86_l_f3b:
	/* 0xf3b: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_f40:
	/* 0xf40: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_f43:
	/* 0xf43: je     12d9 <generic_sleepable_preload+0x12d9> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf43, 0x12d9, x86_l_12d9);
x86_l_f49:
	/* 0xf49: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_f4e:
	/* 0xf4e: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_f51:
	/* 0xf51: je     12d9 <generic_sleepable_preload+0x12d9> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf51, 0x12d9, x86_l_12d9);
x86_l_f57:
	/* 0xf57: jmp    12ec <generic_sleepable_preload+0x12ec> */
	X86_SIM_X86_JMP(0xf57, 0x12ec, x86_l_12ec);
x86_l_f5c:
	/* 0xf5c: mov    rdx,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_f61:
	/* 0xf61: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_f64:
	/* 0xf64: je     1380 <generic_sleepable_preload+0x1380> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf64, 0x1380, x86_l_1380);
x86_l_f6a:
	/* 0xf6a: mov    rdx,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_f6f:
	/* 0xf6f: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_f72:
	/* 0xf72: je     1380 <generic_sleepable_preload+0x1380> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf72, 0x1380, x86_l_1380);
x86_l_f78:
	/* 0xf78: jmp    1393 <generic_sleepable_preload+0x1393> */
	X86_SIM_X86_JMP(0xf78, 0x1393, x86_l_1393);
x86_l_f7d:
	/* 0xf7d: mov    rbp,QWORD PTR [rsp+0x78] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 120ULL);
x86_l_f82:
	/* 0xf82: cmp    ecx,0xa */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 10ULL);
x86_l_f85:
	/* 0xf85: je     1427 <generic_sleepable_preload+0x1427> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf85, 0x1427, x86_l_1427);
x86_l_f8b:
	/* 0xf8b: mov    rbp,QWORD PTR [rsp+0x38] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 56ULL);
x86_l_f90:
	/* 0xf90: cmp    ecx,0xb */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 11ULL);
x86_l_f93:
	/* 0xf93: je     1427 <generic_sleepable_preload+0x1427> */
	X86_SIM_X86_JCC(X86_CC_E, 0xf93, 0x1427, x86_l_1427);
x86_l_f99:
	/* 0xf99: jmp    143b <generic_sleepable_preload+0x143b> */
	X86_SIM_X86_JMP(0xf99, 0x143b, x86_l_143b);
x86_l_f9e:
	/* 0xf9e: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_fa3:
	/* 0xfa3: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_fa6:
	/* 0xfa6: je     10ff <generic_sleepable_preload+0x10ff> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfa6, 0x10ff, x86_l_10ff);
x86_l_fac:
	/* 0xfac: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_fb1:
	/* 0xfb1: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_fb4:
	/* 0xfb4: je     10ff <generic_sleepable_preload+0x10ff> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfb4, 0x10ff, x86_l_10ff);
x86_l_fba:
	/* 0xfba: jmp    1112 <generic_sleepable_preload+0x1112> */
	X86_SIM_X86_JMP(0xfba, 0x1112, x86_l_1112);
x86_l_fbf:
	/* 0xfbf: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_fc4:
	/* 0xfc4: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_fc7:
	/* 0xfc7: je     1232 <generic_sleepable_preload+0x1232> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfc7, 0x1232, x86_l_1232);
x86_l_fcd:
	/* 0xfcd: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_fd2:
	/* 0xfd2: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_fd5:
	/* 0xfd5: je     1232 <generic_sleepable_preload+0x1232> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfd5, 0x1232, x86_l_1232);
x86_l_fdb:
	/* 0xfdb: jmp    1245 <generic_sleepable_preload+0x1245> */
	X86_SIM_X86_JMP(0xfdb, 0x1245, x86_l_1245);
x86_l_fe0:
	/* 0xfe0: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_fe5:
	/* 0xfe5: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_fe8:
	/* 0xfe8: je     12d9 <generic_sleepable_preload+0x12d9> */
	X86_SIM_X86_JCC(X86_CC_E, 0xfe8, 0x12d9, x86_l_12d9);
x86_l_fee:
	/* 0xfee: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_ff3:
	/* 0xff3: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_ff6:
	/* 0xff6: je     12d9 <generic_sleepable_preload+0x12d9> */
	X86_SIM_X86_JCC(X86_CC_E, 0xff6, 0x12d9, x86_l_12d9);
x86_l_ffc:
	/* 0xffc: jmp    12ec <generic_sleepable_preload+0x12ec> */
	X86_SIM_X86_JMP(0xffc, 0x12ec, x86_l_12ec);
x86_l_1001:
	/* 0x1001: mov    rdx,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1006:
	/* 0x1006: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_1009:
	/* 0x1009: je     1380 <generic_sleepable_preload+0x1380> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1009, 0x1380, x86_l_1380);
x86_l_100f:
	/* 0x100f: mov    rdx,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1014:
	/* 0x1014: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_1017:
	/* 0x1017: je     1380 <generic_sleepable_preload+0x1380> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1017, 0x1380, x86_l_1380);
x86_l_101d:
	/* 0x101d: jmp    1393 <generic_sleepable_preload+0x1393> */
	X86_SIM_X86_JMP(0x101d, 0x1393, x86_l_1393);
x86_l_1022:
	/* 0x1022: mov    rbp,QWORD PTR [rsp+0x58] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 88ULL);
x86_l_1027:
	/* 0x1027: cmp    ecx,0x2 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 2ULL);
x86_l_102a:
	/* 0x102a: je     1427 <generic_sleepable_preload+0x1427> */
	X86_SIM_X86_JCC(X86_CC_E, 0x102a, 0x1427, x86_l_1427);
x86_l_1030:
	/* 0x1030: mov    rbp,QWORD PTR [rsp+0x18] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_1035:
	/* 0x1035: cmp    ecx,0x3 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 3ULL);
x86_l_1038:
	/* 0x1038: je     1427 <generic_sleepable_preload+0x1427> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1038, 0x1427, x86_l_1427);
x86_l_103e:
	/* 0x103e: jmp    143b <generic_sleepable_preload+0x143b> */
	X86_SIM_X86_JMP(0x103e, 0x143b, x86_l_143b);
x86_l_1043:
	/* 0x1043: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1048:
	/* 0x1048: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_104b:
	/* 0x104b: je     10ff <generic_sleepable_preload+0x10ff> */
	X86_SIM_X86_JCC(X86_CC_E, 0x104b, 0x10ff, x86_l_10ff);
x86_l_1051:
	/* 0x1051: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1056:
	/* 0x1056: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_1059:
	/* 0x1059: je     10ff <generic_sleepable_preload+0x10ff> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1059, 0x10ff, x86_l_10ff);
x86_l_105f:
	/* 0x105f: jmp    1112 <generic_sleepable_preload+0x1112> */
	X86_SIM_X86_JMP(0x105f, 0x1112, x86_l_1112);
x86_l_1064:
	/* 0x1064: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_1069:
	/* 0x1069: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_106c:
	/* 0x106c: je     1232 <generic_sleepable_preload+0x1232> */
	X86_SIM_X86_JCC(X86_CC_E, 0x106c, 0x1232, x86_l_1232);
x86_l_1072:
	/* 0x1072: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1077:
	/* 0x1077: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_107a:
	/* 0x107a: je     1232 <generic_sleepable_preload+0x1232> */
	X86_SIM_X86_JCC(X86_CC_E, 0x107a, 0x1232, x86_l_1232);
x86_l_1080:
	/* 0x1080: jmp    1245 <generic_sleepable_preload+0x1245> */
	X86_SIM_X86_JMP(0x1080, 0x1245, x86_l_1245);
x86_l_1085:
	/* 0x1085: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_108a:
	/* 0x108a: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_108d:
	/* 0x108d: je     12d9 <generic_sleepable_preload+0x12d9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x108d, 0x12d9, x86_l_12d9);
x86_l_1093:
	/* 0x1093: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_1098:
	/* 0x1098: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_109b:
	/* 0x109b: je     12d9 <generic_sleepable_preload+0x12d9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x109b, 0x12d9, x86_l_12d9);
x86_l_10a1:
	/* 0x10a1: jmp    12ec <generic_sleepable_preload+0x12ec> */
	X86_SIM_X86_JMP(0x10a1, 0x12ec, x86_l_12ec);
x86_l_10a6:
	/* 0x10a6: mov    rdx,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_10ab:
	/* 0x10ab: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_10ae:
	/* 0x10ae: je     1380 <generic_sleepable_preload+0x1380> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10ae, 0x1380, x86_l_1380);
x86_l_10b4:
	/* 0x10b4: mov    rdx,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_10b9:
	/* 0x10b9: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_10bc:
	/* 0x10bc: je     1380 <generic_sleepable_preload+0x1380> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10bc, 0x1380, x86_l_1380);
x86_l_10c2:
	/* 0x10c2: jmp    1393 <generic_sleepable_preload+0x1393> */
	X86_SIM_X86_JMP(0x10c2, 0x1393, x86_l_1393);
x86_l_10c7:
	/* 0x10c7: mov    rbp,QWORD PTR [rsp+0x68] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 104ULL);
x86_l_10cc:
	/* 0x10cc: cmp    ecx,0x6 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 6ULL);
x86_l_10cf:
	/* 0x10cf: je     1427 <generic_sleepable_preload+0x1427> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10cf, 0x1427, x86_l_1427);
x86_l_10d5:
	/* 0x10d5: mov    rbp,QWORD PTR [rsp+0x28] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 40ULL);
x86_l_10da:
	/* 0x10da: cmp    ecx,0x7 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 7ULL);
x86_l_10dd:
	/* 0x10dd: je     1427 <generic_sleepable_preload+0x1427> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10dd, 0x1427, x86_l_1427);
x86_l_10e3:
	/* 0x10e3: jmp    143b <generic_sleepable_preload+0x143b> */
	X86_SIM_X86_JMP(0x10e3, 0x143b, x86_l_143b);
x86_l_10e8:
	/* 0x10e8: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_10f0:
	/* 0x10f0: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_10f3:
	/* 0x10f3: je     10ff <generic_sleepable_preload+0x10ff> */
	X86_SIM_X86_JCC(X86_CC_E, 0x10f3, 0x10ff, x86_l_10ff);
x86_l_10f5:
	/* 0x10f5: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_10fa:
	/* 0x10fa: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_10fd:
	/* 0x10fd: jne    1112 <generic_sleepable_preload+0x1112> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x10fd, 0x1112, x86_l_1112);
x86_l_10ff:
	/* 0x10ff: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_1102:
	/* 0x1102: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_1104:
	/* 0x1104: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_1106:
	/* 0x1106: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_110b:
	/* 0x110b: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_110d:
	/* 0x110d: bzhi   r15,QWORD PTR [rdx],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_R15, X86_RDX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_1112:
	/* 0x1112: cmp    DWORD PTR [rbx+0x4],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869190ULL);
x86_l_1116:
	/* 0x1116: jne    db <generic_sleepable_preload+0xdb> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1116, 0xdb, x86_l_db);
x86_l_111c:
	/* 0x111c: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1121:
	/* 0x1121: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1123:
	/* 0x1123: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1127:
	/* 0x1127: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_112f:
	/* 0x112f: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1134:
	/* 0x1134: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_113b:
	/* 0x113b: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1140:
	/* 0x1140: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1142:
	/* 0x1142: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1145:
	/* 0x1145: je     db <generic_sleepable_preload+0xdb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1145, 0xdb, x86_l_db);
x86_l_114b:
	/* 0x114b: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_1151:
	/* 0x1151: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_1158:
	/* 0x1158: mov    r13,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSP, X86_WIDTH_64);
x86_l_115b:
	/* 0x115b: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_115e:
	/* 0x115e: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_1161:
	/* 0x1161: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1164:
	/* 0x1164: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1166:
	/* 0x1166: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_1169:
	/* 0x1169: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_116e:
	/* 0x116e: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1171:
	/* 0x1171: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_1174:
	/* 0x1174: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1176:
	/* 0x1176: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1179:
	/* 0x1179: je     db <generic_sleepable_preload+0xdb> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1179, 0xdb, x86_l_db);
x86_l_117f:
	/* 0x117f: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1182:
	/* 0x1182: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1186:
	/* 0x1186: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_118b:
	/* 0x118b: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_118e:
	/* 0x118e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1190:
	/* 0x1190: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1193:
	/* 0x1193: call   1198 <generic_sleepable_preload+0x1198> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_1198:
	/* 0x1198: sar    eax,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SAR, 31ULL);
x86_l_119b:
	/* 0x119b: mov    DWORD PTR [r15],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_119e:
	/* 0x119e: jmp    db <generic_sleepable_preload+0xdb> */
	X86_SIM_X86_JMP(0x119e, 0xdb, x86_l_db);
x86_l_11a3:
	/* 0x11a3: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_11ab:
	/* 0x11ab: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_11ae:
	/* 0x11ae: je     1232 <generic_sleepable_preload+0x1232> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11ae, 0x1232, x86_l_1232);
x86_l_11b4:
	/* 0x11b4: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_11b9:
	/* 0x11b9: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_11bc:
	/* 0x11bc: je     1232 <generic_sleepable_preload+0x1232> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11bc, 0x1232, x86_l_1232);
x86_l_11be:
	/* 0x11be: jmp    1245 <generic_sleepable_preload+0x1245> */
	X86_SIM_X86_JMP(0x11be, 0x1245, x86_l_1245);
x86_l_11c3:
	/* 0x11c3: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_11cb:
	/* 0x11cb: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_11ce:
	/* 0x11ce: je     12d9 <generic_sleepable_preload+0x12d9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11ce, 0x12d9, x86_l_12d9);
x86_l_11d4:
	/* 0x11d4: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_11d9:
	/* 0x11d9: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_11dc:
	/* 0x11dc: je     12d9 <generic_sleepable_preload+0x12d9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11dc, 0x12d9, x86_l_12d9);
x86_l_11e2:
	/* 0x11e2: jmp    12ec <generic_sleepable_preload+0x12ec> */
	X86_SIM_X86_JMP(0x11e2, 0x12ec, x86_l_12ec);
x86_l_11e7:
	/* 0x11e7: mov    rdx,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_11ef:
	/* 0x11ef: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_11f2:
	/* 0x11f2: je     1380 <generic_sleepable_preload+0x1380> */
	X86_SIM_X86_JCC(X86_CC_E, 0x11f2, 0x1380, x86_l_1380);
x86_l_11f8:
	/* 0x11f8: mov    rdx,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_11fd:
	/* 0x11fd: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_1200:
	/* 0x1200: je     1380 <generic_sleepable_preload+0x1380> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1200, 0x1380, x86_l_1380);
x86_l_1206:
	/* 0x1206: jmp    1393 <generic_sleepable_preload+0x1393> */
	X86_SIM_X86_JMP(0x1206, 0x1393, x86_l_1393);
x86_l_120b:
	/* 0x120b: mov    rbp,QWORD PTR [rsp+0x80] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 128ULL);
x86_l_1213:
	/* 0x1213: cmp    ecx,0xc */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 12ULL);
x86_l_1216:
	/* 0x1216: je     1427 <generic_sleepable_preload+0x1427> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1216, 0x1427, x86_l_1427);
x86_l_121c:
	/* 0x121c: mov    rbp,QWORD PTR [rsp+0x40] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RBP, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 64ULL);
x86_l_1221:
	/* 0x1221: cmp    ecx,0xd */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_32, 13ULL);
x86_l_1224:
	/* 0x1224: je     1427 <generic_sleepable_preload+0x1427> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1224, 0x1427, x86_l_1427);
x86_l_122a:
	/* 0x122a: jmp    143b <generic_sleepable_preload+0x143b> */
	X86_SIM_X86_JMP(0x122a, 0x143b, x86_l_143b);
x86_l_122f:
	/* 0x122f: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_1232:
	/* 0x1232: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_1235:
	/* 0x1235: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_1237:
	/* 0x1237: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_1239:
	/* 0x1239: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_123e:
	/* 0x123e: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1240:
	/* 0x1240: bzhi   r15,QWORD PTR [rdx],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_R15, X86_RDX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_1245:
	/* 0x1245: cmp    DWORD PTR [rbx+0x8],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738374ULL);
x86_l_1249:
	/* 0x1249: jne    e9 <generic_sleepable_preload+0xe9> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1249, 0xe9, x86_l_e9);
x86_l_124f:
	/* 0x124f: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_1254:
	/* 0x1254: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1256:
	/* 0x1256: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_125a:
	/* 0x125a: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1262:
	/* 0x1262: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1267:
	/* 0x1267: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_126e:
	/* 0x126e: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1273:
	/* 0x1273: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1275:
	/* 0x1275: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1278:
	/* 0x1278: je     e9 <generic_sleepable_preload+0xe9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1278, 0xe9, x86_l_e9);
x86_l_127e:
	/* 0x127e: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_1284:
	/* 0x1284: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_128b:
	/* 0x128b: mov    r13,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSP, X86_WIDTH_64);
x86_l_128e:
	/* 0x128e: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1291:
	/* 0x1291: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_1294:
	/* 0x1294: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_1297:
	/* 0x1297: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1299:
	/* 0x1299: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_129c:
	/* 0x129c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_12a1:
	/* 0x12a1: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_12a4:
	/* 0x12a4: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_12a7:
	/* 0x12a7: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12a9:
	/* 0x12a9: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_12ac:
	/* 0x12ac: je     e9 <generic_sleepable_preload+0xe9> */
	X86_SIM_X86_JCC(X86_CC_E, 0x12ac, 0xe9, x86_l_e9);
x86_l_12b2:
	/* 0x12b2: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_12b5:
	/* 0x12b5: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_12b9:
	/* 0x12b9: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_12be:
	/* 0x12be: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_12c1:
	/* 0x12c1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_12c3:
	/* 0x12c3: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_12c6:
	/* 0x12c6: call   12cb <generic_sleepable_preload+0x12cb> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_12cb:
	/* 0x12cb: sar    eax,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SAR, 31ULL);
x86_l_12ce:
	/* 0x12ce: mov    DWORD PTR [r15],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_12d1:
	/* 0x12d1: jmp    e9 <generic_sleepable_preload+0xe9> */
	X86_SIM_X86_JMP(0x12d1, 0xe9, x86_l_e9);
x86_l_12d6:
	/* 0x12d6: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_12d9:
	/* 0x12d9: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_12dc:
	/* 0x12dc: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_12de:
	/* 0x12de: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_12e0:
	/* 0x12e0: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_12e5:
	/* 0x12e5: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_12e7:
	/* 0x12e7: bzhi   r15,QWORD PTR [rdx],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_R15, X86_RDX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_12ec:
	/* 0x12ec: cmp    DWORD PTR [rbx+0xc],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607558ULL);
x86_l_12f0:
	/* 0x12f0: jne    f7 <generic_sleepable_preload+0xf7> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x12f0, 0xf7, x86_l_f7);
x86_l_12f6:
	/* 0x12f6: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_12fb:
	/* 0x12fb: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_12fd:
	/* 0x12fd: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1301:
	/* 0x1301: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1309:
	/* 0x1309: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_130e:
	/* 0x130e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_1315:
	/* 0x1315: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_131a:
	/* 0x131a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_131c:
	/* 0x131c: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_131f:
	/* 0x131f: je     f7 <generic_sleepable_preload+0xf7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x131f, 0xf7, x86_l_f7);
x86_l_1325:
	/* 0x1325: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_132b:
	/* 0x132b: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_1332:
	/* 0x1332: mov    r13,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSP, X86_WIDTH_64);
x86_l_1335:
	/* 0x1335: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1338:
	/* 0x1338: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_133b:
	/* 0x133b: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_133e:
	/* 0x133e: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1340:
	/* 0x1340: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_1343:
	/* 0x1343: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1348:
	/* 0x1348: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_134b:
	/* 0x134b: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_134e:
	/* 0x134e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1350:
	/* 0x1350: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1353:
	/* 0x1353: je     f7 <generic_sleepable_preload+0xf7> */
	X86_SIM_X86_JCC(X86_CC_E, 0x1353, 0xf7, x86_l_f7);
x86_l_1359:
	/* 0x1359: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_135c:
	/* 0x135c: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1360:
	/* 0x1360: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_1365:
	/* 0x1365: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_1368:
	/* 0x1368: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_136a:
	/* 0x136a: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_136d:
	/* 0x136d: call   1372 <generic_sleepable_preload+0x1372> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_1372:
	/* 0x1372: sar    eax,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SAR, 31ULL);
x86_l_1375:
	/* 0x1375: mov    DWORD PTR [r15],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1378:
	/* 0x1378: jmp    f7 <generic_sleepable_preload+0xf7> */
	X86_SIM_X86_JMP(0x1378, 0xf7, x86_l_f7);
x86_l_137d:
	/* 0x137d: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_1380:
	/* 0x1380: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_1383:
	/* 0x1383: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_1385:
	/* 0x1385: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_1387:
	/* 0x1387: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_138c:
	/* 0x138c: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_138e:
	/* 0x138e: bzhi   r15,QWORD PTR [rdx],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_R15, X86_RDX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_1393:
	/* 0x1393: cmp    DWORD PTR [rbx+0x10],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476742ULL);
x86_l_1397:
	/* 0x1397: jne    105 <generic_sleepable_preload+0x105> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x1397, 0x105, x86_l_105);
x86_l_139d:
	/* 0x139d: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_13a2:
	/* 0x13a2: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13a4:
	/* 0x13a4: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_13a8:
	/* 0x13a8: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_13b0:
	/* 0x13b0: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13b5:
	/* 0x13b5: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_13bc:
	/* 0x13bc: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13c1:
	/* 0x13c1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13c3:
	/* 0x13c3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13c6:
	/* 0x13c6: je     105 <generic_sleepable_preload+0x105> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13c6, 0x105, x86_l_105);
x86_l_13cc:
	/* 0x13cc: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_13d2:
	/* 0x13d2: mov    r12,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_R12, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_13d9:
	/* 0x13d9: mov    r13,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RSP, X86_WIDTH_64);
x86_l_13dc:
	/* 0x13dc: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_13df:
	/* 0x13df: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_13e2:
	/* 0x13e2: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_13e5:
	/* 0x13e5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_13e7:
	/* 0x13e7: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_13ea:
	/* 0x13ea: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_13ef:
	/* 0x13ef: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_13f2:
	/* 0x13f2: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_13f5:
	/* 0x13f5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13f7:
	/* 0x13f7: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13fa:
	/* 0x13fa: je     105 <generic_sleepable_preload+0x105> */
	X86_SIM_X86_JCC(X86_CC_E, 0x13fa, 0x105, x86_l_105);
x86_l_1400:
	/* 0x1400: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_1403:
	/* 0x1403: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_1407:
	/* 0x1407: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_140c:
	/* 0x140c: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_140f:
	/* 0x140f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1411:
	/* 0x1411: mov    r15,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RAX, X86_WIDTH_64);
x86_l_1414:
	/* 0x1414: call   1419 <generic_sleepable_preload+0x1419> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_1419:
	/* 0x1419: sar    eax,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SAR, 31ULL);
x86_l_141c:
	/* 0x141c: mov    DWORD PTR [r15],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_141f:
	/* 0x141f: jmp    105 <generic_sleepable_preload+0x105> */
	X86_SIM_X86_JMP(0x141f, 0x105, x86_l_105);
x86_l_1424:
	/* 0x1424: mov    rbp,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R14, X86_WIDTH_64);
x86_l_1427:
	/* 0x1427: shl    al,0x3 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_8, X86_ALU_SHL, 3ULL);
x86_l_142a:
	/* 0x142a: mov    cl,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_8, 64ULL);
x86_l_142c:
	/* 0x142c: sub    cl,al */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_8, X86_ALU_SUB);
x86_l_142e:
	/* 0x142e: mov    eax,0x40 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 64ULL);
x86_l_1433:
	/* 0x1433: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1435:
	/* 0x1435: bzhi   r15,QWORD PTR [rbp+0x0],rax */
	X86_SIM_RUN_OP(X86_OP_BZHI_MEM, X86_R15, X86_RBP, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_REG_AUX_SRC_SHIFT(X86_RAX)), 0ULL);
x86_l_143b:
	/* 0x143b: cmp    DWORD PTR [rbx+0x14],0x6 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345926ULL);
x86_l_143f:
	/* 0x143f: jne    113 <generic_sleepable_preload+0x113> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x143f, 0x113, x86_l_113);
x86_l_1445:
	/* 0x1445: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_144a:
	/* 0x144a: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_144c:
	/* 0x144c: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1450:
	/* 0x1450: mov    DWORD PTR [rsp+0x8],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738368ULL);
x86_l_1458:
	/* 0x1458: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_145d:
	/* 0x145d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&heap_ro_zero)));
x86_l_1464:
	/* 0x1464: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1469:
	/* 0x1469: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_146b:
	/* 0x146b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_146e:
	/* 0x146e: je     113 <generic_sleepable_preload+0x113> */
	X86_SIM_X86_JCC(X86_CC_E, 0x146e, 0x113, x86_l_113);
x86_l_1474:
	/* 0x1474: mov    r8d,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_R8, X86_WIDTH_32, 2ULL);
x86_l_147a:
	/* 0x147a: mov    rbx,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RBX, (void *)(long)(((__u64)(long)&sleepable_preload)));
x86_l_1481:
	/* 0x1481: mov    r14,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSP, X86_WIDTH_64);
x86_l_1484:
	/* 0x1484: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_1487:
	/* 0x1487: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_148a:
	/* 0x148a: mov    rdx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RAX, X86_WIDTH_64);
x86_l_148d:
	/* 0x148d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_148f:
	/* 0x148f: call   r8 */
	X86_SIM_BPF_CALL_REG(X86_R8);
x86_l_1492:
	/* 0x1492: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1497:
	/* 0x1497: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_149a:
	/* 0x149a: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_149d:
	/* 0x149d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_149f:
	/* 0x149f: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14a2:
	/* 0x14a2: je     113 <generic_sleepable_preload+0x113> */
	X86_SIM_X86_JCC(X86_CC_E, 0x14a2, 0x113, x86_l_113);
x86_l_14a8:
	/* 0x14a8: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_14ab:
	/* 0x14ab: add    rdi,0x4 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_14af:
	/* 0x14af: mov    esi,0x1000 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 4096ULL);
x86_l_14b4:
	/* 0x14b4: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_14b7:
	/* 0x14b7: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_14b9:
	/* 0x14b9: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_14bc:
	/* 0x14bc: call   14c1 <generic_sleepable_preload+0x14c1> */
	X86_SIM_BPF_CALL_ID(X86_SIM_HELPER_bpf_copy_from_user_str);
x86_l_14c1:
	/* 0x14c1: sar    eax,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_SAR, 31ULL);
x86_l_14c4:
	/* 0x14c4: mov    DWORD PTR [rbx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_14c6:
	/* 0x14c6: jmp    113 <generic_sleepable_preload+0x113> */
	X86_SIM_X86_JMP(0x14c6, 0x113, x86_l_113);
x86_l_14cb:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
