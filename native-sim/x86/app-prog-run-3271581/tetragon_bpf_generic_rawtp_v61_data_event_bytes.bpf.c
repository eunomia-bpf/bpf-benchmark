extern char data_heap;
extern char tcpmon_map;
extern char tg_conf_map;
extern char tg_rb_events;
extern char tg_stats_map;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_generic_rawtp_v61_data_event_bytes_x86_sim_xdp(struct xdp_md *ctx)
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
	/* 0xa: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_b:
	/* 0xb: mov    r14,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RCX, X86_WIDTH_64);
x86_l_e:
	/* 0xe: mov    r15,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_64);
x86_l_11:
	/* 0x11: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_14:
	/* 0x14: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_17:
	/* 0x17: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_1f:
	/* 0x1f: mov    rdi,QWORD PTR [rip+0x240] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&data_heap)));
x86_l_26:
	/* 0x26: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
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
	/* 0x35: je     a8 <data_event_bytes+0xa8> */
	X86_SIM_X86_JCC(X86_CC_E, 0x35, 0xa8, x86_l_a8);
x86_l_37:
	/* 0x37: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_3a:
	/* 0x3a: mov    DWORD PTR [rax],0x18 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_40:
	/* 0x40: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_45:
	/* 0x45: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_47:
	/* 0x47: mov    rbp,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R13, X86_WIDTH_64);
x86_l_4a:
	/* 0x4a: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4e:
	/* 0x4e: mov    QWORD PTR [r13+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_52:
	/* 0x52: cmp    rax,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_56:
	/* 0x56: jne    61 <data_event_bytes+0x61> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x56, 0x61, x86_l_61);
x86_l_58:
	/* 0x58: mov    rax,QWORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5d:
	/* 0x5d: mov    QWORD PTR [rbp+0x0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_61:
	/* 0x61: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_66:
	/* 0x66: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_68:
	/* 0x68: mov    QWORD PTR [r13+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6c:
	/* 0x6c: mov    rax,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_70:
	/* 0x70: mov    rcx,QWORD PTR [rbp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_74:
	/* 0x74: mov    QWORD PTR [rbx+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_78:
	/* 0x78: mov    QWORD PTR [rbx+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_7c:
	/* 0x7c: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_7f:
	/* 0x7f: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_82:
	/* 0x82: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_85:
	/* 0x85: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_88:
	/* 0x88: call   d7 <do_bytes> */
	X86_SIM_X86_CALL(x86_l_d7, 0x8dULL);
x86_l_8d:
	/* 0x8d: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_8f:
	/* 0x8f: js     ac <data_event_bytes+0xac> */
	X86_SIM_X86_JCC(X86_CC_S, 0x8f, 0xac, x86_l_ac);
x86_l_91:
	/* 0x91: mov    QWORD PTR [rbx],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_98:
	/* 0x98: mov    edx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_32);
x86_l_9b:
	/* 0x9b: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_9d:
	/* 0x9d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9f:
	/* 0x9f: cmp    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_a3:
	/* 0xa3: cmovne ecx,edx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_32, X86_CC_NE);
x86_l_a6:
	/* 0xa6: jmp    b9 <data_event_bytes+0xb9> */
	X86_SIM_X86_JMP(0xa6, 0xb9, x86_l_b9);
x86_l_a8:
	/* 0xa8: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_aa:
	/* 0xaa: jmp    c4 <data_event_bytes+0xc4> */
	X86_SIM_X86_JMP(0xaa, 0xc4, x86_l_c4);
x86_l_ac:
	/* 0xac: mov    DWORD PTR [rbx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_ae:
	/* 0xae: mov    DWORD PTR [rbx+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_b5:
	/* 0xb5: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b7:
	/* 0xb7: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b9:
	/* 0xb9: mov    DWORD PTR [rbx+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_bc:
	/* 0xbc: mov    DWORD PTR [rbx+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_bf:
	/* 0xbf: mov    eax,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_c4:
	/* 0xc4: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_c8:
	/* 0xc8: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_c9:
	/* 0xc9: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_cb:
	/* 0xcb: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_cd:
	/* 0xcd: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_cf:
	/* 0xcf: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_d1:
	/* 0xd1: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_d2:
	/* 0xd2: jmp    3fb <__do_bytes+0xc4> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_3fb:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
	/* native subroutine native_link_sub_d7 */
x86_l_d7:
	/* 0xd7: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_d8:
	/* 0xd8: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_da:
	/* 0xda: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_dc:
	/* 0xdc: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_de:
	/* 0xde: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_e0:
	/* 0xe0: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_e1:
	/* 0xe1: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_e2:
	/* 0xe2: mov    rbx,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RCX, X86_WIDTH_64);
x86_l_e5:
	/* 0xe5: mov    r14,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_64);
x86_l_e8:
	/* 0xe8: mov    r15,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSI, X86_WIDTH_64);
x86_l_eb:
	/* 0xeb: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_ee:
	/* 0xee: call   337 <__do_bytes> */
	X86_SIM_X86_CALL(x86_l_337, 0xf3ULL);
x86_l_f3:
	/* 0xf3: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_f5:
	/* 0xf5: js     29e <do_bytes+0x1c7> */
	X86_SIM_X86_SUB_JCC(X86_CC_S, 0xf5, 0x29e, x86_l_29e);
x86_l_fb:
	/* 0xfb: mov    r13d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_fe:
	/* 0xfe: and    r13d,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_105:
	/* 0x105: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_108:
	/* 0x108: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_10b:
	/* 0x10b: je     325 <do_bytes+0x24e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x10b, 0x325, x86_l_325);
x86_l_111:
	/* 0x111: lea    rdx,[r14+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_115:
	/* 0x115: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_118:
	/* 0x118: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_11b:
	/* 0x11b: call   337 <__do_bytes> */
	X86_SIM_X86_CALL(x86_l_337, 0x120ULL);
x86_l_120:
	/* 0x120: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_122:
	/* 0x122: js     29e <do_bytes+0x1c7> */
	X86_SIM_X86_SUB_JCC(X86_CC_S, 0x122, 0x29e, x86_l_29e);
x86_l_128:
	/* 0x128: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_12d:
	/* 0x12d: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_130:
	/* 0x130: add    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_133:
	/* 0x133: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_136:
	/* 0x136: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_139:
	/* 0x139: je     325 <do_bytes+0x24e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x139, 0x325, x86_l_325);
x86_l_13f:
	/* 0x13f: lea    rdx,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_143:
	/* 0x143: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_146:
	/* 0x146: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_149:
	/* 0x149: call   337 <__do_bytes> */
	X86_SIM_X86_CALL(x86_l_337, 0x14eULL);
x86_l_14e:
	/* 0x14e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_150:
	/* 0x150: js     29e <do_bytes+0x1c7> */
	X86_SIM_X86_SUB_JCC(X86_CC_S, 0x150, 0x29e, x86_l_29e);
x86_l_156:
	/* 0x156: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_15b:
	/* 0x15b: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_15e:
	/* 0x15e: add    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_161:
	/* 0x161: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_164:
	/* 0x164: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_167:
	/* 0x167: je     325 <do_bytes+0x24e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x167, 0x325, x86_l_325);
x86_l_16d:
	/* 0x16d: lea    rdx,[r14+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_171:
	/* 0x171: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_174:
	/* 0x174: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_177:
	/* 0x177: call   337 <__do_bytes> */
	X86_SIM_X86_CALL(x86_l_337, 0x17cULL);
x86_l_17c:
	/* 0x17c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_17e:
	/* 0x17e: js     29e <do_bytes+0x1c7> */
	X86_SIM_X86_SUB_JCC(X86_CC_S, 0x17e, 0x29e, x86_l_29e);
x86_l_184:
	/* 0x184: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_189:
	/* 0x189: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_18c:
	/* 0x18c: add    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_18f:
	/* 0x18f: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_192:
	/* 0x192: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_195:
	/* 0x195: je     325 <do_bytes+0x24e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x195, 0x325, x86_l_325);
x86_l_19b:
	/* 0x19b: lea    rdx,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_19f:
	/* 0x19f: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1a2:
	/* 0x1a2: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_1a5:
	/* 0x1a5: call   337 <__do_bytes> */
	X86_SIM_X86_CALL(x86_l_337, 0x1aaULL);
x86_l_1aa:
	/* 0x1aa: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1ac:
	/* 0x1ac: js     29e <do_bytes+0x1c7> */
	X86_SIM_X86_SUB_JCC(X86_CC_S, 0x1ac, 0x29e, x86_l_29e);
x86_l_1b2:
	/* 0x1b2: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_1b7:
	/* 0x1b7: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_1ba:
	/* 0x1ba: add    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1bd:
	/* 0x1bd: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_1c0:
	/* 0x1c0: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1c3:
	/* 0x1c3: je     325 <do_bytes+0x24e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1c3, 0x325, x86_l_325);
x86_l_1c9:
	/* 0x1c9: lea    rdx,[r14+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_1cd:
	/* 0x1cd: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1d0:
	/* 0x1d0: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_1d3:
	/* 0x1d3: call   337 <__do_bytes> */
	X86_SIM_X86_CALL(x86_l_337, 0x1d8ULL);
x86_l_1d8:
	/* 0x1d8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1da:
	/* 0x1da: js     29e <do_bytes+0x1c7> */
	X86_SIM_X86_SUB_JCC(X86_CC_S, 0x1da, 0x29e, x86_l_29e);
x86_l_1e0:
	/* 0x1e0: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_1e5:
	/* 0x1e5: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_1e8:
	/* 0x1e8: add    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1eb:
	/* 0x1eb: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_1ee:
	/* 0x1ee: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1f1:
	/* 0x1f1: je     325 <do_bytes+0x24e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1f1, 0x325, x86_l_325);
x86_l_1f7:
	/* 0x1f7: lea    rdx,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_1fb:
	/* 0x1fb: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1fe:
	/* 0x1fe: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_201:
	/* 0x201: call   337 <__do_bytes> */
	X86_SIM_X86_CALL(x86_l_337, 0x206ULL);
x86_l_206:
	/* 0x206: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_208:
	/* 0x208: js     29e <do_bytes+0x1c7> */
	X86_SIM_X86_SUB_JCC(X86_CC_S, 0x208, 0x29e, x86_l_29e);
x86_l_20e:
	/* 0x20e: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_213:
	/* 0x213: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_216:
	/* 0x216: add    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_219:
	/* 0x219: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_21c:
	/* 0x21c: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_21f:
	/* 0x21f: je     325 <do_bytes+0x24e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x21f, 0x325, x86_l_325);
x86_l_225:
	/* 0x225: lea    rdx,[r14+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_229:
	/* 0x229: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_22c:
	/* 0x22c: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_22f:
	/* 0x22f: call   337 <__do_bytes> */
	X86_SIM_X86_CALL(x86_l_337, 0x234ULL);
x86_l_234:
	/* 0x234: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_236:
	/* 0x236: js     29e <do_bytes+0x1c7> */
	X86_SIM_X86_SUB_JCC(X86_CC_S, 0x236, 0x29e, x86_l_29e);
x86_l_238:
	/* 0x238: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_23d:
	/* 0x23d: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_240:
	/* 0x240: add    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_243:
	/* 0x243: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_246:
	/* 0x246: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_249:
	/* 0x249: je     325 <do_bytes+0x24e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x249, 0x325, x86_l_325);
x86_l_24f:
	/* 0x24f: lea    rdx,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_253:
	/* 0x253: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_256:
	/* 0x256: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_259:
	/* 0x259: call   337 <__do_bytes> */
	X86_SIM_X86_CALL(x86_l_337, 0x25eULL);
x86_l_25e:
	/* 0x25e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_260:
	/* 0x260: js     29e <do_bytes+0x1c7> */
	X86_SIM_X86_SUB_JCC(X86_CC_S, 0x260, 0x29e, x86_l_29e);
x86_l_262:
	/* 0x262: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_267:
	/* 0x267: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_26a:
	/* 0x26a: add    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_26d:
	/* 0x26d: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_270:
	/* 0x270: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_273:
	/* 0x273: je     325 <do_bytes+0x24e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x273, 0x325, x86_l_325);
x86_l_279:
	/* 0x279: add    r14,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_27c:
	/* 0x27c: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_27f:
	/* 0x27f: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_282:
	/* 0x282: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_285:
	/* 0x285: call   337 <__do_bytes> */
	X86_SIM_X86_CALL(x86_l_337, 0x28aULL);
x86_l_28a:
	/* 0x28a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_28c:
	/* 0x28c: js     29e <do_bytes+0x1c7> */
	X86_SIM_X86_SUB_JCC(X86_CC_S, 0x28c, 0x29e, x86_l_29e);
x86_l_28e:
	/* 0x28e: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_293:
	/* 0x293: add    rax,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_296:
	/* 0x296: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_299:
	/* 0x299: jmp    325 <do_bytes+0x24e> */
	X86_SIM_X86_SUB_JMP(0x299, 0x325, x86_l_325);
x86_l_29e:
	/* 0x29e: movsxd rbx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_2a1:
	/* 0x2a1: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_2a9:
	/* 0x2a9: mov    rdi,QWORD PTR [rip+0x320] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_2b0:
	/* 0x2b0: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2b5:
	/* 0x2b5: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2ba:
	/* 0x2ba: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2bc:
	/* 0x2bc: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2bf:
	/* 0x2bf: je     325 <do_bytes+0x24e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x2bf, 0x325, x86_l_325);
x86_l_2c1:
	/* 0x2c1: cmp    rbx,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_2c5:
	/* 0x2c5: jg     2e1 <do_bytes+0x20a> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x2c5, 0x2e1, x86_l_2e1);
x86_l_2c7:
	/* 0x2c7: cmp    rbx,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_2cb:
	/* 0x2cb: je     2fb <do_bytes+0x224> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x2cb, 0x2fb, x86_l_2fb);
x86_l_2cd:
	/* 0x2cd: cmp    rbx,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_2d1:
	/* 0x2d1: je     313 <do_bytes+0x23c> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x2d1, 0x313, x86_l_313);
x86_l_2d3:
	/* 0x2d3: cmp    rbx,0xfffffffffffffff0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551600ULL);
x86_l_2d7:
	/* 0x2d7: jne    30b <do_bytes+0x234> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x2d7, 0x30b, x86_l_30b);
x86_l_2d9:
	/* 0x2d9: add    rax,0x558 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1368ULL);
x86_l_2df:
	/* 0x2df: jmp    321 <do_bytes+0x24a> */
	X86_SIM_X86_SUB_JMP(0x2df, 0x321, x86_l_321);
x86_l_2e1:
	/* 0x2e1: cmp    rbx,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_2e5:
	/* 0x2e5: je     303 <do_bytes+0x22c> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x2e5, 0x303, x86_l_303);
x86_l_2e7:
	/* 0x2e7: cmp    rbx,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_2eb:
	/* 0x2eb: je     31b <do_bytes+0x244> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x2eb, 0x31b, x86_l_31b);
x86_l_2ed:
	/* 0x2ed: cmp    rbx,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_2f1:
	/* 0x2f1: jne    30b <do_bytes+0x234> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x2f1, 0x30b, x86_l_30b);
x86_l_2f3:
	/* 0x2f3: add    rax,0x548 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1352ULL);
x86_l_2f9:
	/* 0x2f9: jmp    321 <do_bytes+0x24a> */
	X86_SIM_X86_SUB_JMP(0x2f9, 0x321, x86_l_321);
x86_l_2fb:
	/* 0x2fb: add    rax,0x568 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1384ULL);
x86_l_301:
	/* 0x301: jmp    321 <do_bytes+0x24a> */
	X86_SIM_X86_SUB_JMP(0x301, 0x321, x86_l_321);
x86_l_303:
	/* 0x303: add    rax,0x570 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1392ULL);
x86_l_309:
	/* 0x309: jmp    321 <do_bytes+0x24a> */
	X86_SIM_X86_SUB_JMP(0x309, 0x321, x86_l_321);
x86_l_30b:
	/* 0x30b: add    rax,0x540 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1344ULL);
x86_l_311:
	/* 0x311: jmp    321 <do_bytes+0x24a> */
	X86_SIM_X86_SUB_JMP(0x311, 0x321, x86_l_321);
x86_l_313:
	/* 0x313: add    rax,0x560 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1376ULL);
x86_l_319:
	/* 0x319: jmp    321 <do_bytes+0x24a> */
	X86_SIM_X86_SUB_JMP(0x319, 0x321, x86_l_321);
x86_l_31b:
	/* 0x31b: add    rax,0x550 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1360ULL);
x86_l_321:
	/* 0x321: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_325:
	/* 0x325: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_328:
	/* 0x328: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_32c:
	/* 0x32c: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_32d:
	/* 0x32d: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_32f:
	/* 0x32f: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_331:
	/* 0x331: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_333:
	/* 0x333: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_335:
	/* 0x335: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_336:
	/* 0x336: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

	/* native subroutine native_link_sub_337 */
x86_l_337:
	/* 0x337: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_339:
	/* 0x339: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_33b:
	/* 0x33b: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_33d:
	/* 0x33d: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_33e:
	/* 0x33e: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_33f:
	/* 0x33f: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_342:
	/* 0x342: js     3c4 <__do_bytes+0x8d> */
	X86_SIM_X86_SUB_JCC(X86_CC_S, 0x342, 0x3c4, x86_l_3c4);
x86_l_348:
	/* 0x348: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_34b:
	/* 0x34b: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_34e:
	/* 0x34e: cmp    rcx,0x7fe0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 32736ULL);
x86_l_355:
	/* 0x355: mov    ebx,0x7fe0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 32736ULL);
x86_l_35a:
	/* 0x35a: cmovb  rbx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_RCX, X86_WIDTH_64, X86_CC_B);
x86_l_35e:
	/* 0x35e: lea    rdi,[rsi+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_362:
	/* 0x362: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_367:
	/* 0x367: mov    esi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_32);
x86_l_369:
	/* 0x369: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_36b:
	/* 0x36b: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_36d:
	/* 0x36d: js     3e9 <__do_bytes+0xb2> */
	X86_SIM_X86_SUB_JCC(X86_CC_S, 0x36d, 0x3e9, x86_l_3e9);
x86_l_36f:
	/* 0x36f: lea    r15d,[rbx+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_373:
	/* 0x373: mov    DWORD PTR [r14+0x4],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_377:
	/* 0x377: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_37f:
	/* 0x37f: mov    rdi,QWORD PTR [rip+0x57c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_conf_map)));
x86_l_386:
	/* 0x386: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_38b:
	/* 0x38b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_390:
	/* 0x390: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_392:
	/* 0x392: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_395:
	/* 0x395: je     3cd <__do_bytes+0x96> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x395, 0x3cd, x86_l_3cd);
x86_l_397:
	/* 0x397: cmp    BYTE PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_39b:
	/* 0x39b: je     3cd <__do_bytes+0x96> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x39b, 0x3cd, x86_l_3cd);
x86_l_39d:
	/* 0x39d: mov    rsi,QWORD PTR [rip+0x57c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tcpmon_map)));
x86_l_3a4:
	/* 0x3a4: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_3a9:
	/* 0x3a9: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_3ae:
	/* 0x3ae: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_3b1:
	/* 0x3b1: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_3b6:
	/* 0x3b6: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_3b9:
	/* 0x3b9: mov    r8,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R15, X86_WIDTH_64);
x86_l_3bc:
	/* 0x3bc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3be:
	/* 0x3be: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3c0:
	/* 0x3c0: js     3e9 <__do_bytes+0xb2> */
	X86_SIM_X86_SUB_JCC(X86_CC_S, 0x3c0, 0x3e9, x86_l_3e9);
x86_l_3c2:
	/* 0x3c2: jmp    3ec <__do_bytes+0xb5> */
	X86_SIM_X86_SUB_JMP(0x3c2, 0x3ec, x86_l_3ec);
x86_l_3c4:
	/* 0x3c4: mov    rbx,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_3cb:
	/* 0x3cb: jmp    3ec <__do_bytes+0xb5> */
	X86_SIM_X86_SUB_JMP(0x3cb, 0x3ec, x86_l_3ec);
x86_l_3cd:
	/* 0x3cd: mov    rdi,QWORD PTR [rip+0x57c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_rb_events)));
x86_l_3d4:
	/* 0x3d4: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3d6:
	/* 0x3d6: mov    eax,0x82 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 130ULL);
x86_l_3db:
	/* 0x3db: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_3de:
	/* 0x3de: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_3e1:
	/* 0x3e1: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3e3:
	/* 0x3e3: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3e5:
	/* 0x3e5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3e7:
	/* 0x3e7: jns    3ec <__do_bytes+0xb5> */
	X86_SIM_X86_SUB_JCC(X86_CC_NS, 0x3e7, 0x3ec, x86_l_3ec);
x86_l_3e9:
	/* 0x3e9: movsxd rbx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_3ec:
	/* 0x3ec: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_3ef:
	/* 0x3ef: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3f3:
	/* 0x3f3: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_3f4:
	/* 0x3f4: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_3f6:
	/* 0x3f6: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_3f8:
	/* 0x3f8: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_3fa:
	/* 0x3fa: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

x86_sim_ret_dispatch:
	switch (__x86_sim_ret_addr) {
	case 0x32ULL: goto x86_l_32;
	case 0x47ULL: goto x86_l_47;
	case 0x68ULL: goto x86_l_68;
	case 0x8dULL: goto x86_l_8d;
	case 0xf3ULL: goto x86_l_f3;
	case 0x120ULL: goto x86_l_120;
	case 0x14eULL: goto x86_l_14e;
	case 0x17cULL: goto x86_l_17c;
	case 0x1aaULL: goto x86_l_1aa;
	case 0x1d8ULL: goto x86_l_1d8;
	case 0x206ULL: goto x86_l_206;
	case 0x234ULL: goto x86_l_234;
	case 0x25eULL: goto x86_l_25e;
	case 0x28aULL: goto x86_l_28a;
	case 0x2bcULL: goto x86_l_2bc;
	case 0x36bULL: goto x86_l_36b;
	case 0x392ULL: goto x86_l_392;
	case 0x3beULL: goto x86_l_3be;
	case 0x3e5ULL: goto x86_l_3e5;
	}

}

X86_SIM_LICENSE();
