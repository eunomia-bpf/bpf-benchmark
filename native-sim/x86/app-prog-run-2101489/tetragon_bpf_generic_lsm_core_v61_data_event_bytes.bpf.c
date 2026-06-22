extern char data_heap;
extern char tcpmon_map;
extern char tg_conf_map;
extern char tg_rb_events;
extern char tg_stats_map;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_generic_lsm_core_v61_data_event_bytes_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_1:
	/* 0x1: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_3:
	/* 0x3: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_4:
	/* 0x4: mov    r14,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RCX, X86_WIDTH_64);
x86_l_7:
	/* 0x7: mov    r15,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDX, X86_WIDTH_64);
x86_l_a:
	/* 0xa: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_d:
	/* 0xd: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_10:
	/* 0x10: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_18:
	/* 0x18: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d:
	/* 0x1d: mov    rdi,QWORD PTR [rip+0x227] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&data_heap)));
x86_l_24:
	/* 0x24: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_29:
	/* 0x29: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2b:
	/* 0x2b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2e:
	/* 0x2e: je     a1 <data_event_bytes+0xa1> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2e, 0xa1, x86_l_a1);
x86_l_30:
	/* 0x30: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_33:
	/* 0x33: mov    DWORD PTR [rax],0x18 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_39:
	/* 0x39: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_3e:
	/* 0x3e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_40:
	/* 0x40: mov    rbp,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_R13, X86_WIDTH_64);
x86_l_43:
	/* 0x43: add    rbp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RBP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_47:
	/* 0x47: mov    QWORD PTR [r13+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4b:
	/* 0x4b: cmp    rax,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_4f:
	/* 0x4f: jne    5a <data_event_bytes+0x5a> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4f, 0x5a, x86_l_5a);
x86_l_51:
	/* 0x51: mov    rax,QWORD PTR [r12+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R12, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_56:
	/* 0x56: mov    QWORD PTR [rbp+0x0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_5a:
	/* 0x5a: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_5f:
	/* 0x5f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_61:
	/* 0x61: mov    QWORD PTR [r13+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_65:
	/* 0x65: mov    rax,QWORD PTR [rbp+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_69:
	/* 0x69: mov    rcx,QWORD PTR [rbp+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RBP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6d:
	/* 0x6d: mov    QWORD PTR [rbx+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_71:
	/* 0x71: mov    QWORD PTR [rbx+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_75:
	/* 0x75: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_78:
	/* 0x78: mov    rsi,r13 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R13, X86_WIDTH_64);
x86_l_7b:
	/* 0x7b: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_7e:
	/* 0x7e: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_81:
	/* 0x81: call   c9 <do_bytes> */
	X86_SIM_X86_CALL(x86_l_c9, 0x86ULL);
x86_l_86:
	/* 0x86: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_88:
	/* 0x88: js     a5 <data_event_bytes+0xa5> */
	X86_SIM_X86_JCC(X86_CC_S, 0x88, 0xa5, x86_l_a5);
x86_l_8a:
	/* 0x8a: mov    QWORD PTR [rbx],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_91:
	/* 0x91: mov    edx,r14d */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_32);
x86_l_94:
	/* 0x94: sub    edx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RAX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_96:
	/* 0x96: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_98:
	/* 0x98: cmp    r14,0xffffffffffffffff */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_R14, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_9c:
	/* 0x9c: cmovne ecx,edx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RDX, X86_WIDTH_32, X86_CC_NE);
x86_l_9f:
	/* 0x9f: jmp    b2 <data_event_bytes+0xb2> */
	X86_SIM_X86_JMP(0x9f, 0xb2, x86_l_b2);
x86_l_a1:
	/* 0xa1: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a3:
	/* 0xa3: jmp    bd <data_event_bytes+0xbd> */
	X86_SIM_X86_JMP(0xa3, 0xbd, x86_l_bd);
x86_l_a5:
	/* 0xa5: mov    DWORD PTR [rbx],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_a7:
	/* 0xa7: mov    DWORD PTR [rbx+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_ae:
	/* 0xae: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b0:
	/* 0xb0: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_b2:
	/* 0xb2: mov    DWORD PTR [rbx+0x8],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_b5:
	/* 0xb5: mov    DWORD PTR [rbx+0xc],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_b8:
	/* 0xb8: mov    eax,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_bd:
	/* 0xbd: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_c1:
	/* 0xc1: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_c3:
	/* 0xc3: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_c4:
	/* 0xc4: jmp    3e2 <__do_bytes+0xb9> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_3e2:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
	/* native subroutine native_link_sub_c9 */
x86_l_c9:
	/* 0xc9: push   rbp */
	X86_SIM_L_EXEC_PUSH(X86_RBP);
x86_l_ca:
	/* 0xca: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_cc:
	/* 0xcc: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_ce:
	/* 0xce: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_d0:
	/* 0xd0: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_d2:
	/* 0xd2: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_d3:
	/* 0xd3: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_d4:
	/* 0xd4: mov    rbx,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RCX, X86_WIDTH_64);
x86_l_d7:
	/* 0xd7: mov    r14,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_64);
x86_l_da:
	/* 0xda: mov    r15,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RSI, X86_WIDTH_64);
x86_l_dd:
	/* 0xdd: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_e0:
	/* 0xe0: call   329 <__do_bytes> */
	X86_SIM_X86_CALL(x86_l_329, 0xe5ULL);
x86_l_e5:
	/* 0xe5: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_e7:
	/* 0xe7: js     290 <do_bytes+0x1c7> */
	X86_SIM_X86_SUB_JCC(X86_CC_S, 0xe7, 0x290, x86_l_290);
x86_l_ed:
	/* 0xed: mov    r13d,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_32);
x86_l_f0:
	/* 0xf0: and    r13d,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_f7:
	/* 0xf7: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_fa:
	/* 0xfa: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_fd:
	/* 0xfd: je     317 <do_bytes+0x24e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0xfd, 0x317, x86_l_317);
x86_l_103:
	/* 0x103: lea    rdx,[r14+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_107:
	/* 0x107: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_10a:
	/* 0x10a: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_10d:
	/* 0x10d: call   329 <__do_bytes> */
	X86_SIM_X86_CALL(x86_l_329, 0x112ULL);
x86_l_112:
	/* 0x112: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_114:
	/* 0x114: js     290 <do_bytes+0x1c7> */
	X86_SIM_X86_SUB_JCC(X86_CC_S, 0x114, 0x290, x86_l_290);
x86_l_11a:
	/* 0x11a: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_11f:
	/* 0x11f: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_122:
	/* 0x122: add    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_125:
	/* 0x125: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_128:
	/* 0x128: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_12b:
	/* 0x12b: je     317 <do_bytes+0x24e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x12b, 0x317, x86_l_317);
x86_l_131:
	/* 0x131: lea    rdx,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_135:
	/* 0x135: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_138:
	/* 0x138: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_13b:
	/* 0x13b: call   329 <__do_bytes> */
	X86_SIM_X86_CALL(x86_l_329, 0x140ULL);
x86_l_140:
	/* 0x140: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_142:
	/* 0x142: js     290 <do_bytes+0x1c7> */
	X86_SIM_X86_SUB_JCC(X86_CC_S, 0x142, 0x290, x86_l_290);
x86_l_148:
	/* 0x148: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_14d:
	/* 0x14d: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_150:
	/* 0x150: add    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_153:
	/* 0x153: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_156:
	/* 0x156: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_159:
	/* 0x159: je     317 <do_bytes+0x24e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x159, 0x317, x86_l_317);
x86_l_15f:
	/* 0x15f: lea    rdx,[r14+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_163:
	/* 0x163: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_166:
	/* 0x166: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_169:
	/* 0x169: call   329 <__do_bytes> */
	X86_SIM_X86_CALL(x86_l_329, 0x16eULL);
x86_l_16e:
	/* 0x16e: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_170:
	/* 0x170: js     290 <do_bytes+0x1c7> */
	X86_SIM_X86_SUB_JCC(X86_CC_S, 0x170, 0x290, x86_l_290);
x86_l_176:
	/* 0x176: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_17b:
	/* 0x17b: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_17e:
	/* 0x17e: add    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_181:
	/* 0x181: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_184:
	/* 0x184: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_187:
	/* 0x187: je     317 <do_bytes+0x24e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x187, 0x317, x86_l_317);
x86_l_18d:
	/* 0x18d: lea    rdx,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_191:
	/* 0x191: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_194:
	/* 0x194: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_197:
	/* 0x197: call   329 <__do_bytes> */
	X86_SIM_X86_CALL(x86_l_329, 0x19cULL);
x86_l_19c:
	/* 0x19c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_19e:
	/* 0x19e: js     290 <do_bytes+0x1c7> */
	X86_SIM_X86_SUB_JCC(X86_CC_S, 0x19e, 0x290, x86_l_290);
x86_l_1a4:
	/* 0x1a4: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_1a9:
	/* 0x1a9: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_1ac:
	/* 0x1ac: add    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1af:
	/* 0x1af: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_1b2:
	/* 0x1b2: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1b5:
	/* 0x1b5: je     317 <do_bytes+0x24e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1b5, 0x317, x86_l_317);
x86_l_1bb:
	/* 0x1bb: lea    rdx,[r14+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_1bf:
	/* 0x1bf: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1c2:
	/* 0x1c2: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_1c5:
	/* 0x1c5: call   329 <__do_bytes> */
	X86_SIM_X86_CALL(x86_l_329, 0x1caULL);
x86_l_1ca:
	/* 0x1ca: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1cc:
	/* 0x1cc: js     290 <do_bytes+0x1c7> */
	X86_SIM_X86_SUB_JCC(X86_CC_S, 0x1cc, 0x290, x86_l_290);
x86_l_1d2:
	/* 0x1d2: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_1d7:
	/* 0x1d7: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_1da:
	/* 0x1da: add    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_1dd:
	/* 0x1dd: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_1e0:
	/* 0x1e0: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_1e3:
	/* 0x1e3: je     317 <do_bytes+0x24e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1e3, 0x317, x86_l_317);
x86_l_1e9:
	/* 0x1e9: lea    rdx,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_1ed:
	/* 0x1ed: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_1f0:
	/* 0x1f0: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_1f3:
	/* 0x1f3: call   329 <__do_bytes> */
	X86_SIM_X86_CALL(x86_l_329, 0x1f8ULL);
x86_l_1f8:
	/* 0x1f8: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_1fa:
	/* 0x1fa: js     290 <do_bytes+0x1c7> */
	X86_SIM_X86_SUB_JCC(X86_CC_S, 0x1fa, 0x290, x86_l_290);
x86_l_200:
	/* 0x200: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_205:
	/* 0x205: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_208:
	/* 0x208: add    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_20b:
	/* 0x20b: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_20e:
	/* 0x20e: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_211:
	/* 0x211: je     317 <do_bytes+0x24e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x211, 0x317, x86_l_317);
x86_l_217:
	/* 0x217: lea    rdx,[r14+r13*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_R13, 0), 0ULL);
x86_l_21b:
	/* 0x21b: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_21e:
	/* 0x21e: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_221:
	/* 0x221: call   329 <__do_bytes> */
	X86_SIM_X86_CALL(x86_l_329, 0x226ULL);
x86_l_226:
	/* 0x226: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_228:
	/* 0x228: js     290 <do_bytes+0x1c7> */
	X86_SIM_X86_SUB_JCC(X86_CC_S, 0x228, 0x290, x86_l_290);
x86_l_22a:
	/* 0x22a: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_22f:
	/* 0x22f: mov    rbp,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBP, X86_RAX, X86_WIDTH_64);
x86_l_232:
	/* 0x232: add    rbp,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RBP, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_235:
	/* 0x235: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_238:
	/* 0x238: sub    rcx,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RBP, X86_WIDTH_64, X86_ALU_SUB);
x86_l_23b:
	/* 0x23b: je     317 <do_bytes+0x24e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x23b, 0x317, x86_l_317);
x86_l_241:
	/* 0x241: lea    rdx,[r14+rbp*1] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_R14, X86_WIDTH_64, X86_MEM_AUX(X86_RBP, 0), 0ULL);
x86_l_245:
	/* 0x245: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_248:
	/* 0x248: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_24b:
	/* 0x24b: call   329 <__do_bytes> */
	X86_SIM_X86_CALL(x86_l_329, 0x250ULL);
x86_l_250:
	/* 0x250: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_252:
	/* 0x252: js     290 <do_bytes+0x1c7> */
	X86_SIM_X86_SUB_JCC(X86_CC_S, 0x252, 0x290, x86_l_290);
x86_l_254:
	/* 0x254: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_259:
	/* 0x259: mov    r13,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_RAX, X86_WIDTH_64);
x86_l_25c:
	/* 0x25c: add    r13,rbp */
	X86_SIM_L_EXEC_ALU_REG(X86_R13, X86_RBP, X86_WIDTH_64, X86_ALU_ADD);
x86_l_25f:
	/* 0x25f: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_262:
	/* 0x262: sub    rcx,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_R13, X86_WIDTH_64, X86_ALU_SUB);
x86_l_265:
	/* 0x265: je     317 <do_bytes+0x24e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x265, 0x317, x86_l_317);
x86_l_26b:
	/* 0x26b: add    r14,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_R14, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_26e:
	/* 0x26e: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_271:
	/* 0x271: mov    rsi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R15, X86_WIDTH_64);
x86_l_274:
	/* 0x274: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_277:
	/* 0x277: call   329 <__do_bytes> */
	X86_SIM_X86_CALL(x86_l_329, 0x27cULL);
x86_l_27c:
	/* 0x27c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_27e:
	/* 0x27e: js     290 <do_bytes+0x1c7> */
	X86_SIM_X86_SUB_JCC(X86_CC_S, 0x27e, 0x290, x86_l_290);
x86_l_280:
	/* 0x280: and    eax,0x7fffffff */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_AND, 2147483647ULL);
x86_l_285:
	/* 0x285: add    rax,r13 */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_R13, X86_WIDTH_64, X86_ALU_ADD);
x86_l_288:
	/* 0x288: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_28b:
	/* 0x28b: jmp    317 <do_bytes+0x24e> */
	X86_SIM_X86_SUB_JMP(0x28b, 0x317, x86_l_317);
x86_l_290:
	/* 0x290: movsxd rbx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_293:
	/* 0x293: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_29b:
	/* 0x29b: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2a0:
	/* 0x2a0: mov    rdi,QWORD PTR [rip+0x300] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_2a7:
	/* 0x2a7: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_2ac:
	/* 0x2ac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2ae:
	/* 0x2ae: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2b1:
	/* 0x2b1: je     317 <do_bytes+0x24e> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x2b1, 0x317, x86_l_317);
x86_l_2b3:
	/* 0x2b3: cmp    rbx,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_2b7:
	/* 0x2b7: jg     2d3 <do_bytes+0x20a> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x2b7, 0x2d3, x86_l_2d3);
x86_l_2b9:
	/* 0x2b9: cmp    rbx,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_2bd:
	/* 0x2bd: je     2ed <do_bytes+0x224> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x2bd, 0x2ed, x86_l_2ed);
x86_l_2bf:
	/* 0x2bf: cmp    rbx,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_2c3:
	/* 0x2c3: je     305 <do_bytes+0x23c> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x2c3, 0x305, x86_l_305);
x86_l_2c5:
	/* 0x2c5: cmp    rbx,0xfffffffffffffff0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551600ULL);
x86_l_2c9:
	/* 0x2c9: jne    2fd <do_bytes+0x234> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x2c9, 0x2fd, x86_l_2fd);
x86_l_2cb:
	/* 0x2cb: add    rax,0x558 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1368ULL);
x86_l_2d1:
	/* 0x2d1: jmp    313 <do_bytes+0x24a> */
	X86_SIM_X86_SUB_JMP(0x2d1, 0x313, x86_l_313);
x86_l_2d3:
	/* 0x2d3: cmp    rbx,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_2d7:
	/* 0x2d7: je     2f5 <do_bytes+0x22c> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x2d7, 0x2f5, x86_l_2f5);
x86_l_2d9:
	/* 0x2d9: cmp    rbx,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_2dd:
	/* 0x2dd: je     30d <do_bytes+0x244> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x2dd, 0x30d, x86_l_30d);
x86_l_2df:
	/* 0x2df: cmp    rbx,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_2e3:
	/* 0x2e3: jne    2fd <do_bytes+0x234> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x2e3, 0x2fd, x86_l_2fd);
x86_l_2e5:
	/* 0x2e5: add    rax,0x548 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1352ULL);
x86_l_2eb:
	/* 0x2eb: jmp    313 <do_bytes+0x24a> */
	X86_SIM_X86_SUB_JMP(0x2eb, 0x313, x86_l_313);
x86_l_2ed:
	/* 0x2ed: add    rax,0x568 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1384ULL);
x86_l_2f3:
	/* 0x2f3: jmp    313 <do_bytes+0x24a> */
	X86_SIM_X86_SUB_JMP(0x2f3, 0x313, x86_l_313);
x86_l_2f5:
	/* 0x2f5: add    rax,0x570 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1392ULL);
x86_l_2fb:
	/* 0x2fb: jmp    313 <do_bytes+0x24a> */
	X86_SIM_X86_SUB_JMP(0x2fb, 0x313, x86_l_313);
x86_l_2fd:
	/* 0x2fd: add    rax,0x540 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1344ULL);
x86_l_303:
	/* 0x303: jmp    313 <do_bytes+0x24a> */
	X86_SIM_X86_SUB_JMP(0x303, 0x313, x86_l_313);
x86_l_305:
	/* 0x305: add    rax,0x560 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1376ULL);
x86_l_30b:
	/* 0x30b: jmp    313 <do_bytes+0x24a> */
	X86_SIM_X86_SUB_JMP(0x30b, 0x313, x86_l_313);
x86_l_30d:
	/* 0x30d: add    rax,0x550 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1360ULL);
x86_l_313:
	/* 0x313: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_317:
	/* 0x317: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_31a:
	/* 0x31a: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_31e:
	/* 0x31e: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_31f:
	/* 0x31f: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_321:
	/* 0x321: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_323:
	/* 0x323: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_325:
	/* 0x325: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_327:
	/* 0x327: pop    rbp */
	X86_SIM_L_EXEC_POP(X86_RBP, X86_WIDTH_64);
x86_l_328:
	/* 0x328: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

	/* native subroutine native_link_sub_329 */
x86_l_329:
	/* 0x329: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_32b:
	/* 0x32b: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_32d:
	/* 0x32d: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_32f:
	/* 0x32f: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_330:
	/* 0x330: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_331:
	/* 0x331: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_334:
	/* 0x334: js     3ad <__do_bytes+0x84> */
	X86_SIM_X86_SUB_JCC(X86_CC_S, 0x334, 0x3ad, x86_l_3ad);
x86_l_336:
	/* 0x336: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_339:
	/* 0x339: mov    r15,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDI, X86_WIDTH_64);
x86_l_33c:
	/* 0x33c: cmp    rcx,0x7fe0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 32736ULL);
x86_l_343:
	/* 0x343: mov    ebx,0x7fe0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 32736ULL);
x86_l_348:
	/* 0x348: cmovb  rbx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_RCX, X86_WIDTH_64, X86_CC_B);
x86_l_34c:
	/* 0x34c: lea    rdi,[rsi+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_350:
	/* 0x350: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_355:
	/* 0x355: mov    esi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_32);
x86_l_357:
	/* 0x357: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_359:
	/* 0x359: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_35b:
	/* 0x35b: js     3d0 <__do_bytes+0xa7> */
	X86_SIM_X86_SUB_JCC(X86_CC_S, 0x35b, 0x3d0, x86_l_3d0);
x86_l_35d:
	/* 0x35d: lea    r12d,[rbx+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R12, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_361:
	/* 0x361: mov    DWORD PTR [r14+0x4],r12d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R12, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_365:
	/* 0x365: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_36d:
	/* 0x36d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_372:
	/* 0x372: mov    rdi,QWORD PTR [rip+0x560] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_conf_map)));
x86_l_379:
	/* 0x379: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_37e:
	/* 0x37e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_380:
	/* 0x380: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_383:
	/* 0x383: je     3b6 <__do_bytes+0x8d> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x383, 0x3b6, x86_l_3b6);
x86_l_385:
	/* 0x385: cmp    BYTE PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_389:
	/* 0x389: je     3b6 <__do_bytes+0x8d> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x389, 0x3b6, x86_l_3b6);
x86_l_38b:
	/* 0x38b: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_390:
	/* 0x390: mov    rsi,QWORD PTR [rip+0x560] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tcpmon_map)));
x86_l_397:
	/* 0x397: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_39c:
	/* 0x39c: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_39f:
	/* 0x39f: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_3a2:
	/* 0x3a2: mov    r8,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R12, X86_WIDTH_64);
x86_l_3a5:
	/* 0x3a5: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3a7:
	/* 0x3a7: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3a9:
	/* 0x3a9: js     3d0 <__do_bytes+0xa7> */
	X86_SIM_X86_SUB_JCC(X86_CC_S, 0x3a9, 0x3d0, x86_l_3d0);
x86_l_3ab:
	/* 0x3ab: jmp    3d3 <__do_bytes+0xaa> */
	X86_SIM_X86_SUB_JMP(0x3ab, 0x3d3, x86_l_3d3);
x86_l_3ad:
	/* 0x3ad: mov    rbx,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_3b4:
	/* 0x3b4: jmp    3d3 <__do_bytes+0xaa> */
	X86_SIM_X86_SUB_JMP(0x3b4, 0x3d3, x86_l_3d3);
x86_l_3b6:
	/* 0x3b6: mov    eax,0x82 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 130ULL);
x86_l_3bb:
	/* 0x3bb: mov    rdi,QWORD PTR [rip+0x560] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_rb_events)));
x86_l_3c2:
	/* 0x3c2: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_3c5:
	/* 0x3c5: mov    rdx,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R12, X86_WIDTH_64);
x86_l_3c8:
	/* 0x3c8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3ca:
	/* 0x3ca: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3cc:
	/* 0x3cc: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_3ce:
	/* 0x3ce: jns    3d3 <__do_bytes+0xaa> */
	X86_SIM_X86_SUB_JCC(X86_CC_NS, 0x3ce, 0x3d3, x86_l_3d3);
x86_l_3d0:
	/* 0x3d0: movsxd rbx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_3d3:
	/* 0x3d3: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_3d6:
	/* 0x3d6: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_3da:
	/* 0x3da: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_3db:
	/* 0x3db: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_3dd:
	/* 0x3dd: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_3df:
	/* 0x3df: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_3e1:
	/* 0x3e1: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

x86_sim_ret_dispatch:
	switch (__x86_sim_ret_addr) {
	case 0x2bULL: goto x86_l_2b;
	case 0x40ULL: goto x86_l_40;
	case 0x61ULL: goto x86_l_61;
	case 0x86ULL: goto x86_l_86;
	case 0xe5ULL: goto x86_l_e5;
	case 0x112ULL: goto x86_l_112;
	case 0x140ULL: goto x86_l_140;
	case 0x16eULL: goto x86_l_16e;
	case 0x19cULL: goto x86_l_19c;
	case 0x1caULL: goto x86_l_1ca;
	case 0x1f8ULL: goto x86_l_1f8;
	case 0x226ULL: goto x86_l_226;
	case 0x250ULL: goto x86_l_250;
	case 0x27cULL: goto x86_l_27c;
	case 0x2aeULL: goto x86_l_2ae;
	case 0x359ULL: goto x86_l_359;
	case 0x380ULL: goto x86_l_380;
	case 0x3a7ULL: goto x86_l_3a7;
	case 0x3ccULL: goto x86_l_3cc;
	}

}

X86_SIM_LICENSE();
