extern char data_heap;
extern char tcpmon_map;
extern char tg_conf_map;
extern char tg_rb_events;
extern char tg_stats_map;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_execve_event_v61_data_event_str_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_2:
	/* 0x2: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_4:
	/* 0x4: push   r13 */
	X86_SIM_L_EXEC_PUSH(X86_R13);
x86_l_6:
	/* 0x6: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_8:
	/* 0x8: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_9:
	/* 0x9: sub    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_d:
	/* 0xd: mov    r14,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_64);
x86_l_10:
	/* 0x10: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_13:
	/* 0x13: mov    r15,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDI, X86_WIDTH_64);
x86_l_16:
	/* 0x16: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_1e:
	/* 0x1e: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&data_heap)));
x86_l_25:
	/* 0x25: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_2a:
	/* 0x2a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_2f:
	/* 0x2f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_31:
	/* 0x31: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_34:
	/* 0x34: je     ac <data_event_str+0xac> */
	X86_SIM_X86_JCC(X86_CC_E, 0x34, 0xac, x86_l_ac);
x86_l_36:
	/* 0x36: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_39:
	/* 0x39: mov    DWORD PTR [rax],0x18 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_3f:
	/* 0x3f: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_44:
	/* 0x44: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_46:
	/* 0x46: mov    r13,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R12, X86_WIDTH_64);
x86_l_49:
	/* 0x49: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_4d:
	/* 0x4d: mov    QWORD PTR [r12+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_52:
	/* 0x52: cmp    rax,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_56:
	/* 0x56: jne    60 <data_event_str+0x60> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x56, 0x60, x86_l_60);
x86_l_58:
	/* 0x58: mov    rax,QWORD PTR [r15+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_5c:
	/* 0x5c: mov    QWORD PTR [r13+0x0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_60:
	/* 0x60: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_65:
	/* 0x65: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_67:
	/* 0x67: mov    QWORD PTR [r12+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6c:
	/* 0x6c: mov    rax,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_70:
	/* 0x70: mov    rcx,QWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_74:
	/* 0x74: mov    QWORD PTR [rbx+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_78:
	/* 0x78: mov    QWORD PTR [rbx+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_7c:
	/* 0x7c: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_7f:
	/* 0x7f: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_82:
	/* 0x82: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_85:
	/* 0x85: call   c0 <do_str> */
	X86_SIM_X86_CALL(x86_l_c0, 0x8aULL);
x86_l_8a:
	/* 0x8a: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_8c:
	/* 0x8c: sar    ecx,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SAR, 31ULL);
x86_l_8f:
	/* 0x8f: and    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_AND);
x86_l_91:
	/* 0x91: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_93:
	/* 0x93: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_95:
	/* 0x95: mov    DWORD PTR [rbx],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_97:
	/* 0x97: cmovg  edx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RAX, X86_WIDTH_32, X86_CC_G);
x86_l_9a:
	/* 0x9a: mov    QWORD PTR [rbx+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_a2:
	/* 0xa2: mov    DWORD PTR [rbx+0xc],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_a5:
	/* 0xa5: mov    eax,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_aa:
	/* 0xaa: jmp    ae <data_event_str+0xae> */
	X86_SIM_X86_JMP(0xaa, 0xae, x86_l_ae);
x86_l_ac:
	/* 0xac: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ae:
	/* 0xae: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_b2:
	/* 0xb2: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_b3:
	/* 0xb3: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_b5:
	/* 0xb5: pop    r13 */
	X86_SIM_L_EXEC_POP(X86_R13, X86_WIDTH_64);
x86_l_b7:
	/* 0xb7: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_b9:
	/* 0xb9: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_bb:
	/* 0xbb: jmp    2de <__do_str+0x1bf> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_2de:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
	/* native subroutine native_link_sub_c0 */
x86_l_c0:
	/* 0xc0: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_c2:
	/* 0xc2: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_c4:
	/* 0xc4: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_c5:
	/* 0xc5: sub    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_c9:
	/* 0xc9: mov    rbx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDX, X86_WIDTH_64);
x86_l_cc:
	/* 0xcc: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_cf:
	/* 0xcf: mov    r15,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDI, X86_WIDTH_64);
x86_l_d2:
	/* 0xd2: mov    BYTE PTR [rsp+0xf],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 64424509440ULL);
x86_l_d7:
	/* 0xd7: lea    rcx,[rsp+0xf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 15ULL);
x86_l_dc:
	/* 0xdc: call   11f <__do_str> */
	X86_SIM_X86_CALL(x86_l_11f, 0xe1ULL);
x86_l_e1:
	/* 0xe1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_e4:
	/* 0xe4: js     115 <do_str+0x55> */
	X86_SIM_X86_SUB_JCC(X86_CC_S, 0xe4, 0x115, x86_l_115);
x86_l_e6:
	/* 0xe6: cmp    BYTE PTR [rsp+0xf],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 64424509440ULL);
x86_l_eb:
	/* 0xeb: jne    115 <do_str+0x55> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xeb, 0x115, x86_l_115);
x86_l_ed:
	/* 0xed: add    rbx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_f0:
	/* 0xf0: lea    rcx,[rsp+0xf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 15ULL);
x86_l_f5:
	/* 0xf5: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_f8:
	/* 0xf8: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_fb:
	/* 0xfb: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_fe:
	/* 0xfe: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_101:
	/* 0x101: call   11f <__do_str> */
	X86_SIM_X86_CALL(x86_l_11f, 0x106ULL);
x86_l_106:
	/* 0x106: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_108:
	/* 0x108: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_10b:
	/* 0x10b: cmovns rcx,rbx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RBX, X86_WIDTH_64, X86_CC_NS);
x86_l_10f:
	/* 0x10f: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_112:
	/* 0x112: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_115:
	/* 0x115: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_119:
	/* 0x119: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_11a:
	/* 0x11a: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_11c:
	/* 0x11c: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_11e:
	/* 0x11e: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

	/* native subroutine native_link_sub_11f */
x86_l_11f:
	/* 0x11f: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_121:
	/* 0x121: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_123:
	/* 0x123: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_125:
	/* 0x125: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_126:
	/* 0x126: sub    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
x86_l_12a:
	/* 0x12a: mov    r15,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RCX, X86_WIDTH_64);
x86_l_12d:
	/* 0x12d: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_130:
	/* 0x130: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_133:
	/* 0x133: lea    rdi,[rsi+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_137:
	/* 0x137: mov    ecx,0x7fdf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 32735ULL);
x86_l_13c:
	/* 0x13c: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_141:
	/* 0x141: mov    esi,0x7fdf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 32735ULL);
x86_l_146:
	/* 0x146: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_148:
	/* 0x148: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_14b:
	/* 0x14b: js     2d2 <__do_str+0x1b3> */
	X86_SIM_X86_SUB_JCC(X86_CC_S, 0x14b, 0x2d2, x86_l_2d2);
x86_l_151:
	/* 0x151: cmp    rax,0x7fdf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 32735ULL);
x86_l_157:
	/* 0x157: setne  BYTE PTR [r15] */
	X86_SIM_L_EXEC_SETCC_MEM(X86_R15, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_REG_AUX_SRC_SHIFT(X86_CC_NE)), 0ULL);
x86_l_15b:
	/* 0x15b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_15e:
	/* 0x15e: je     27a <__do_str+0x15b> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x15e, 0x27a, x86_l_27a);
x86_l_164:
	/* 0x164: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_167:
	/* 0x167: lea    r15d,[rax+0x1f] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 31ULL);
x86_l_16b:
	/* 0x16b: and    r15d,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_172:
	/* 0x172: mov    DWORD PTR [rbx+0x4],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_176:
	/* 0x176: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_17e:
	/* 0x17e: mov    rdi,QWORD PTR [rip+0x120] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_conf_map)));
x86_l_185:
	/* 0x185: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_18a:
	/* 0x18a: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_18f:
	/* 0x18f: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_191:
	/* 0x191: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_194:
	/* 0x194: je     216 <__do_str+0xf7> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x194, 0x216, x86_l_216);
x86_l_19a:
	/* 0x19a: cmp    BYTE PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_19e:
	/* 0x19e: je     216 <__do_str+0xf7> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x19e, 0x216, x86_l_216);
x86_l_1a0:
	/* 0x1a0: mov    rsi,QWORD PTR [rip+0x11c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tcpmon_map)));
x86_l_1a7:
	/* 0x1a7: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_1ac:
	/* 0x1ac: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_1b1:
	/* 0x1b1: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_1b6:
	/* 0x1b6: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_1b9:
	/* 0x1b9: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_1bc:
	/* 0x1bc: mov    r8,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R15, X86_WIDTH_64);
x86_l_1bf:
	/* 0x1bf: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1c1:
	/* 0x1c1: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1c4:
	/* 0x1c4: jns    2cc <__do_str+0x1ad> */
	X86_SIM_X86_SUB_JCC(X86_CC_NS, 0x1c4, 0x2cc, x86_l_2cc);
x86_l_1ca:
	/* 0x1ca: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1cd:
	/* 0x1cd: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_1d5:
	/* 0x1d5: mov    rdi,QWORD PTR [rip+0x11c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_1dc:
	/* 0x1dc: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1e1:
	/* 0x1e1: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1e6:
	/* 0x1e6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1e8:
	/* 0x1e8: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1eb:
	/* 0x1eb: je     2cc <__do_str+0x1ad> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1eb, 0x2cc, x86_l_2cc);
x86_l_1f1:
	/* 0x1f1: cmp    rbx,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_1f5:
	/* 0x1f5: jg     298 <__do_str+0x179> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x1f5, 0x298, x86_l_298);
x86_l_1fb:
	/* 0x1fb: cmp    rbx,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_1ff:
	/* 0x1ff: je     2b2 <__do_str+0x193> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1ff, 0x2b2, x86_l_2b2);
x86_l_205:
	/* 0x205: cmp    rbx,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_209:
	/* 0x209: jne    26c <__do_str+0x14d> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x209, 0x26c, x86_l_26c);
x86_l_20b:
	/* 0x20b: add    rax,0x560 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1376ULL);
x86_l_211:
	/* 0x211: jmp    2c8 <__do_str+0x1a9> */
	X86_SIM_X86_SUB_JMP(0x211, 0x2c8, x86_l_2c8);
x86_l_216:
	/* 0x216: mov    rdi,QWORD PTR [rip+0x11c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_rb_events)));
x86_l_21d:
	/* 0x21d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_21f:
	/* 0x21f: mov    eax,0x82 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 130ULL);
x86_l_224:
	/* 0x224: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_227:
	/* 0x227: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_22a:
	/* 0x22a: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_22c:
	/* 0x22c: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22e:
	/* 0x22e: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_231:
	/* 0x231: jns    2cc <__do_str+0x1ad> */
	X86_SIM_X86_SUB_JCC(X86_CC_NS, 0x231, 0x2cc, x86_l_2cc);
x86_l_237:
	/* 0x237: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_23a:
	/* 0x23a: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_242:
	/* 0x242: mov    rdi,QWORD PTR [rip+0x11c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_249:
	/* 0x249: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_24e:
	/* 0x24e: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_253:
	/* 0x253: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_255:
	/* 0x255: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_258:
	/* 0x258: je     2cc <__do_str+0x1ad> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x258, 0x2cc, x86_l_2cc);
x86_l_25a:
	/* 0x25a: cmp    rbx,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_25e:
	/* 0x25e: jg     27e <__do_str+0x15f> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x25e, 0x27e, x86_l_27e);
x86_l_260:
	/* 0x260: cmp    rbx,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_264:
	/* 0x264: je     2b2 <__do_str+0x193> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x264, 0x2b2, x86_l_2b2);
x86_l_266:
	/* 0x266: cmp    rbx,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_26a:
	/* 0x26a: je     20b <__do_str+0xec> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x26a, 0x20b, x86_l_20b);
x86_l_26c:
	/* 0x26c: cmp    rbx,0xfffffffffffffff0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551600ULL);
x86_l_270:
	/* 0x270: jne    2aa <__do_str+0x18b> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x270, 0x2aa, x86_l_2aa);
x86_l_272:
	/* 0x272: add    rax,0x558 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1368ULL);
x86_l_278:
	/* 0x278: jmp    2c8 <__do_str+0x1a9> */
	X86_SIM_X86_SUB_JMP(0x278, 0x2c8, x86_l_2c8);
x86_l_27a:
	/* 0x27a: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_27c:
	/* 0x27c: jmp    2d2 <__do_str+0x1b3> */
	X86_SIM_X86_SUB_JMP(0x27c, 0x2d2, x86_l_2d2);
x86_l_27e:
	/* 0x27e: cmp    rbx,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_282:
	/* 0x282: je     2ba <__do_str+0x19b> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x282, 0x2ba, x86_l_2ba);
x86_l_284:
	/* 0x284: cmp    rbx,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_288:
	/* 0x288: je     2c2 <__do_str+0x1a3> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x288, 0x2c2, x86_l_2c2);
x86_l_28a:
	/* 0x28a: cmp    rbx,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_28e:
	/* 0x28e: jne    2aa <__do_str+0x18b> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x28e, 0x2aa, x86_l_2aa);
x86_l_290:
	/* 0x290: add    rax,0x548 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1352ULL);
x86_l_296:
	/* 0x296: jmp    2c8 <__do_str+0x1a9> */
	X86_SIM_X86_SUB_JMP(0x296, 0x2c8, x86_l_2c8);
x86_l_298:
	/* 0x298: cmp    rbx,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_29c:
	/* 0x29c: je     2ba <__do_str+0x19b> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x29c, 0x2ba, x86_l_2ba);
x86_l_29e:
	/* 0x29e: cmp    rbx,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_2a2:
	/* 0x2a2: je     2c2 <__do_str+0x1a3> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x2a2, 0x2c2, x86_l_2c2);
x86_l_2a4:
	/* 0x2a4: cmp    rbx,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_2a8:
	/* 0x2a8: je     290 <__do_str+0x171> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x2a8, 0x290, x86_l_290);
x86_l_2aa:
	/* 0x2aa: add    rax,0x540 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1344ULL);
x86_l_2b0:
	/* 0x2b0: jmp    2c8 <__do_str+0x1a9> */
	X86_SIM_X86_SUB_JMP(0x2b0, 0x2c8, x86_l_2c8);
x86_l_2b2:
	/* 0x2b2: add    rax,0x568 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1384ULL);
x86_l_2b8:
	/* 0x2b8: jmp    2c8 <__do_str+0x1a9> */
	X86_SIM_X86_SUB_JMP(0x2b8, 0x2c8, x86_l_2c8);
x86_l_2ba:
	/* 0x2ba: add    rax,0x570 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1392ULL);
x86_l_2c0:
	/* 0x2c0: jmp    2c8 <__do_str+0x1a9> */
	X86_SIM_X86_SUB_JMP(0x2c0, 0x2c8, x86_l_2c8);
x86_l_2c2:
	/* 0x2c2: add    rax,0x550 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1360ULL);
x86_l_2c8:
	/* 0x2c8: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2cc:
	/* 0x2cc: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_2cf:
	/* 0x2cf: dec    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_2d2:
	/* 0x2d2: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_2d6:
	/* 0x2d6: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_2d7:
	/* 0x2d7: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_2d9:
	/* 0x2d9: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_2db:
	/* 0x2db: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_2dd:
	/* 0x2dd: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

x86_sim_ret_dispatch:
	switch (__x86_sim_ret_addr) {
	case 0x31ULL: goto x86_l_31;
	case 0x46ULL: goto x86_l_46;
	case 0x67ULL: goto x86_l_67;
	case 0x8aULL: goto x86_l_8a;
	case 0xe1ULL: goto x86_l_e1;
	case 0x106ULL: goto x86_l_106;
	case 0x148ULL: goto x86_l_148;
	case 0x191ULL: goto x86_l_191;
	case 0x1c1ULL: goto x86_l_1c1;
	case 0x1e8ULL: goto x86_l_1e8;
	case 0x22eULL: goto x86_l_22e;
	case 0x255ULL: goto x86_l_255;
	}

}

X86_SIM_LICENSE();
