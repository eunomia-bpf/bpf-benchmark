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
	/* 0x0: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_2:
	/* 0x2: sub    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_6:
	/* 0x6: mov    r14,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDX, X86_WIDTH_64);
x86_l_9:
	/* 0x9: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_c:
	/* 0xc: mov    r15,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDI, X86_WIDTH_64);
x86_l_f:
	/* 0xf: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_17:
	/* 0x17: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&data_heap)));
x86_l_1e:
	/* 0x1e: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_23:
	/* 0x23: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_28:
	/* 0x28: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_2a:
	/* 0x2a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_2d:
	/* 0x2d: je     a5 <data_event_str+0xa5> */
	X86_SIM_X86_JCC(X86_CC_E, 0x2d, 0xa5, x86_l_a5);
x86_l_2f:
	/* 0x2f: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_32:
	/* 0x32: mov    DWORD PTR [rax],0x18 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_38:
	/* 0x38: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_3d:
	/* 0x3d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f:
	/* 0x3f: mov    r13,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_R13, X86_R12, X86_WIDTH_64);
x86_l_42:
	/* 0x42: add    r13,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_R13, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_46:
	/* 0x46: mov    QWORD PTR [r12+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_4b:
	/* 0x4b: cmp    rax,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_4f:
	/* 0x4f: jne    59 <data_event_str+0x59> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4f, 0x59, x86_l_59);
x86_l_51:
	/* 0x51: mov    rax,QWORD PTR [r15+0x20] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R15, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_55:
	/* 0x55: mov    QWORD PTR [r13+0x0],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R13, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_59:
	/* 0x59: mov    eax,0x7d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 125ULL);
x86_l_5e:
	/* 0x5e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_60:
	/* 0x60: mov    QWORD PTR [r12+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R12, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_65:
	/* 0x65: mov    rax,QWORD PTR [r13+0x0] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_69:
	/* 0x69: mov    rcx,QWORD PTR [r13+0x8] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_R13, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_6d:
	/* 0x6d: mov    QWORD PTR [rbx+0x10],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_71:
	/* 0x71: mov    QWORD PTR [rbx+0x18],rcx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_75:
	/* 0x75: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_78:
	/* 0x78: mov    rsi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R12, X86_WIDTH_64);
x86_l_7b:
	/* 0x7b: mov    rdx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R14, X86_WIDTH_64);
x86_l_7e:
	/* 0x7e: call   b2 <do_str> */
	X86_SIM_X86_CALL(x86_l_b2, 0x83ULL);
x86_l_83:
	/* 0x83: mov    ecx,eax */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RAX, X86_WIDTH_32);
x86_l_85:
	/* 0x85: sar    ecx,0x1f */
	X86_SIM_L_EXEC_ALU_IMM(X86_RCX, X86_WIDTH_32, X86_ALU_SAR, 31ULL);
x86_l_88:
	/* 0x88: and    ecx,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_32, X86_ALU_AND);
x86_l_8a:
	/* 0x8a: xor    edx,edx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_8c:
	/* 0x8c: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_8e:
	/* 0x8e: mov    DWORD PTR [rbx],ecx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RCX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_90:
	/* 0x90: cmovg  edx,eax */
	X86_SIM_L_EXEC_CMOV(X86_RDX, X86_RAX, X86_WIDTH_32, X86_CC_G);
x86_l_93:
	/* 0x93: mov    QWORD PTR [rbx+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RBX, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_9b:
	/* 0x9b: mov    DWORD PTR [rbx+0xc],edx */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_9e:
	/* 0x9e: mov    eax,0x20 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 32ULL);
x86_l_a3:
	/* 0xa3: jmp    a7 <data_event_str+0xa7> */
	X86_SIM_X86_JMP(0xa3, 0xa7, x86_l_a7);
x86_l_a5:
	/* 0xa5: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a7:
	/* 0xa7: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_ab:
	/* 0xab: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_ad:
	/* 0xad: jmp    2d0 <__do_str+0x1bf> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_2d0:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
	/* native subroutine native_link_sub_b2 */
x86_l_b2:
	/* 0xb2: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_b4:
	/* 0xb4: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_b6:
	/* 0xb6: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_b7:
	/* 0xb7: sub    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_bb:
	/* 0xbb: mov    rbx,rdx */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDX, X86_WIDTH_64);
x86_l_be:
	/* 0xbe: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_c1:
	/* 0xc1: mov    r15,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RDI, X86_WIDTH_64);
x86_l_c4:
	/* 0xc4: mov    BYTE PTR [rsp+0xf],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 64424509440ULL);
x86_l_c9:
	/* 0xc9: lea    rcx,[rsp+0xf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 15ULL);
x86_l_ce:
	/* 0xce: call   111 <__do_str> */
	X86_SIM_X86_CALL(x86_l_111, 0xd3ULL);
x86_l_d3:
	/* 0xd3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_d6:
	/* 0xd6: js     107 <do_str+0x55> */
	X86_SIM_X86_SUB_JCC(X86_CC_S, 0xd6, 0x107, x86_l_107);
x86_l_d8:
	/* 0xd8: cmp    BYTE PTR [rsp+0xf],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 64424509440ULL);
x86_l_dd:
	/* 0xdd: jne    107 <do_str+0x55> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0xdd, 0x107, x86_l_107);
x86_l_df:
	/* 0xdf: add    rbx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RBX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_e2:
	/* 0xe2: lea    rcx,[rsp+0xf] */
	X86_SIM_L_EXEC_LEA(X86_RCX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 15ULL);
x86_l_e7:
	/* 0xe7: mov    rdi,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R15, X86_WIDTH_64);
x86_l_ea:
	/* 0xea: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_ed:
	/* 0xed: mov    rdx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_RBX, X86_WIDTH_64);
x86_l_f0:
	/* 0xf0: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_f3:
	/* 0xf3: call   111 <__do_str> */
	X86_SIM_X86_CALL(x86_l_111, 0xf8ULL);
x86_l_f8:
	/* 0xf8: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_fa:
	/* 0xfa: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_fd:
	/* 0xfd: cmovns rcx,rbx */
	X86_SIM_L_EXEC_CMOV(X86_RCX, X86_RBX, X86_WIDTH_64, X86_CC_NS);
x86_l_101:
	/* 0x101: add    rcx,rax */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RAX, X86_WIDTH_64, X86_ALU_ADD);
x86_l_104:
	/* 0x104: mov    rax,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RCX, X86_WIDTH_64);
x86_l_107:
	/* 0x107: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_10b:
	/* 0x10b: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_10c:
	/* 0x10c: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_10e:
	/* 0x10e: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_110:
	/* 0x110: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

	/* native subroutine native_link_sub_111 */
x86_l_111:
	/* 0x111: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_113:
	/* 0x113: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_115:
	/* 0x115: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_117:
	/* 0x117: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_118:
	/* 0x118: sub    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 24ULL);
x86_l_11c:
	/* 0x11c: mov    r15,rcx */
	X86_SIM_L_EXEC_MOV_REG(X86_R15, X86_RCX, X86_WIDTH_64);
x86_l_11f:
	/* 0x11f: mov    rbx,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RSI, X86_WIDTH_64);
x86_l_122:
	/* 0x122: mov    r14,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RDI, X86_WIDTH_64);
x86_l_125:
	/* 0x125: lea    rdi,[rsi+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_129:
	/* 0x129: mov    ecx,0x7fdf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 32735ULL);
x86_l_12e:
	/* 0x12e: mov    eax,0x2d */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 45ULL);
x86_l_133:
	/* 0x133: mov    esi,0x7fdf */
	X86_SIM_L_EXEC_MOV_IMM(X86_RSI, X86_WIDTH_32, 32735ULL);
x86_l_138:
	/* 0x138: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_13a:
	/* 0x13a: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_13d:
	/* 0x13d: js     2c4 <__do_str+0x1b3> */
	X86_SIM_X86_SUB_JCC(X86_CC_S, 0x13d, 0x2c4, x86_l_2c4);
x86_l_143:
	/* 0x143: cmp    rax,0x7fdf */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RAX, X86_WIDTH_64, 32735ULL);
x86_l_149:
	/* 0x149: setne  BYTE PTR [r15] */
	X86_SIM_L_EXEC_SETCC_MEM(X86_R15, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_8) | X86_REG_AUX_SRC_SHIFT(X86_CC_NE)), 0ULL);
x86_l_14d:
	/* 0x14d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_150:
	/* 0x150: je     26c <__do_str+0x15b> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x150, 0x26c, x86_l_26c);
x86_l_156:
	/* 0x156: mov    r12,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RAX, X86_WIDTH_64);
x86_l_159:
	/* 0x159: lea    r15d,[rax+0x1f] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 31ULL);
x86_l_15d:
	/* 0x15d: and    r15d,0x7fff */
	X86_SIM_L_EXEC_ALU_IMM(X86_R15, X86_WIDTH_32, X86_ALU_AND, 32767ULL);
x86_l_164:
	/* 0x164: mov    DWORD PTR [rbx+0x4],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RBX, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_168:
	/* 0x168: mov    DWORD PTR [rsp+0xc],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539607552ULL);
x86_l_170:
	/* 0x170: mov    rdi,QWORD PTR [rip+0x120] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_conf_map)));
x86_l_177:
	/* 0x177: lea    rsi,[rsp+0xc] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 12ULL);
x86_l_17c:
	/* 0x17c: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_181:
	/* 0x181: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_183:
	/* 0x183: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_186:
	/* 0x186: je     208 <__do_str+0xf7> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x186, 0x208, x86_l_208);
x86_l_18c:
	/* 0x18c: cmp    BYTE PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_190:
	/* 0x190: je     208 <__do_str+0xf7> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x190, 0x208, x86_l_208);
x86_l_192:
	/* 0x192: mov    rsi,QWORD PTR [rip+0x11c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tcpmon_map)));
x86_l_199:
	/* 0x199: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_19e:
	/* 0x19e: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_1a3:
	/* 0x1a3: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_1a8:
	/* 0x1a8: mov    rdi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R14, X86_WIDTH_64);
x86_l_1ab:
	/* 0x1ab: mov    rcx,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_RBX, X86_WIDTH_64);
x86_l_1ae:
	/* 0x1ae: mov    r8,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R15, X86_WIDTH_64);
x86_l_1b1:
	/* 0x1b1: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1b3:
	/* 0x1b3: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1b6:
	/* 0x1b6: jns    2be <__do_str+0x1ad> */
	X86_SIM_X86_SUB_JCC(X86_CC_NS, 0x1b6, 0x2be, x86_l_2be);
x86_l_1bc:
	/* 0x1bc: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_1bf:
	/* 0x1bf: mov    DWORD PTR [rsp+0x14],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 85899345920ULL);
x86_l_1c7:
	/* 0x1c7: mov    rdi,QWORD PTR [rip+0x11c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_1ce:
	/* 0x1ce: lea    rsi,[rsp+0x14] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1d3:
	/* 0x1d3: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1d8:
	/* 0x1d8: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1da:
	/* 0x1da: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_1dd:
	/* 0x1dd: je     2be <__do_str+0x1ad> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1dd, 0x2be, x86_l_2be);
x86_l_1e3:
	/* 0x1e3: cmp    rbx,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_1e7:
	/* 0x1e7: jg     28a <__do_str+0x179> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x1e7, 0x28a, x86_l_28a);
x86_l_1ed:
	/* 0x1ed: cmp    rbx,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_1f1:
	/* 0x1f1: je     2a4 <__do_str+0x193> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x1f1, 0x2a4, x86_l_2a4);
x86_l_1f7:
	/* 0x1f7: cmp    rbx,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_1fb:
	/* 0x1fb: jne    25e <__do_str+0x14d> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x1fb, 0x25e, x86_l_25e);
x86_l_1fd:
	/* 0x1fd: add    rax,0x560 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1376ULL);
x86_l_203:
	/* 0x203: jmp    2ba <__do_str+0x1a9> */
	X86_SIM_X86_SUB_JMP(0x203, 0x2ba, x86_l_2ba);
x86_l_208:
	/* 0x208: mov    rdi,QWORD PTR [rip+0x11c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_rb_events)));
x86_l_20f:
	/* 0x20f: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_211:
	/* 0x211: mov    eax,0x82 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 130ULL);
x86_l_216:
	/* 0x216: mov    rsi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_64);
x86_l_219:
	/* 0x219: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_21c:
	/* 0x21c: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_21e:
	/* 0x21e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_220:
	/* 0x220: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_223:
	/* 0x223: jns    2be <__do_str+0x1ad> */
	X86_SIM_X86_SUB_JCC(X86_CC_NS, 0x223, 0x2be, x86_l_2be);
x86_l_229:
	/* 0x229: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_22c:
	/* 0x22c: mov    DWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_234:
	/* 0x234: mov    rdi,QWORD PTR [rip+0x11c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_stats_map)));
x86_l_23b:
	/* 0x23b: lea    rsi,[rsp+0x10] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_240:
	/* 0x240: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_245:
	/* 0x245: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_247:
	/* 0x247: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_24a:
	/* 0x24a: je     2be <__do_str+0x1ad> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x24a, 0x2be, x86_l_2be);
x86_l_24c:
	/* 0x24c: cmp    rbx,0xfffffffffffffff4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551604ULL);
x86_l_250:
	/* 0x250: jg     270 <__do_str+0x15f> */
	X86_SIM_X86_SUB_JCC(X86_CC_G, 0x250, 0x270, x86_l_270);
x86_l_252:
	/* 0x252: cmp    rbx,0xffffffffffffffe4 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551588ULL);
x86_l_256:
	/* 0x256: je     2a4 <__do_str+0x193> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x256, 0x2a4, x86_l_2a4);
x86_l_258:
	/* 0x258: cmp    rbx,0xffffffffffffffea */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551594ULL);
x86_l_25c:
	/* 0x25c: je     1fd <__do_str+0xec> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x25c, 0x1fd, x86_l_1fd);
x86_l_25e:
	/* 0x25e: cmp    rbx,0xfffffffffffffff0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551600ULL);
x86_l_262:
	/* 0x262: jne    29c <__do_str+0x18b> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x262, 0x29c, x86_l_29c);
x86_l_264:
	/* 0x264: add    rax,0x558 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1368ULL);
x86_l_26a:
	/* 0x26a: jmp    2ba <__do_str+0x1a9> */
	X86_SIM_X86_SUB_JMP(0x26a, 0x2ba, x86_l_2ba);
x86_l_26c:
	/* 0x26c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_26e:
	/* 0x26e: jmp    2c4 <__do_str+0x1b3> */
	X86_SIM_X86_SUB_JMP(0x26e, 0x2c4, x86_l_2c4);
x86_l_270:
	/* 0x270: cmp    rbx,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_274:
	/* 0x274: je     2ac <__do_str+0x19b> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x274, 0x2ac, x86_l_2ac);
x86_l_276:
	/* 0x276: cmp    rbx,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_27a:
	/* 0x27a: je     2b4 <__do_str+0x1a3> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x27a, 0x2b4, x86_l_2b4);
x86_l_27c:
	/* 0x27c: cmp    rbx,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_280:
	/* 0x280: jne    29c <__do_str+0x18b> */
	X86_SIM_X86_SUB_JCC(X86_CC_NE, 0x280, 0x29c, x86_l_29c);
x86_l_282:
	/* 0x282: add    rax,0x548 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1352ULL);
x86_l_288:
	/* 0x288: jmp    2ba <__do_str+0x1a9> */
	X86_SIM_X86_SUB_JMP(0x288, 0x2ba, x86_l_2ba);
x86_l_28a:
	/* 0x28a: cmp    rbx,0xfffffffffffffff5 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551605ULL);
x86_l_28e:
	/* 0x28e: je     2ac <__do_str+0x19b> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x28e, 0x2ac, x86_l_2ac);
x86_l_290:
	/* 0x290: cmp    rbx,0xfffffffffffffff9 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551609ULL);
x86_l_294:
	/* 0x294: je     2b4 <__do_str+0x1a3> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x294, 0x2b4, x86_l_2b4);
x86_l_296:
	/* 0x296: cmp    rbx,0xfffffffffffffffe */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RBX, X86_WIDTH_64, 18446744073709551614ULL);
x86_l_29a:
	/* 0x29a: je     282 <__do_str+0x171> */
	X86_SIM_X86_SUB_JCC(X86_CC_E, 0x29a, 0x282, x86_l_282);
x86_l_29c:
	/* 0x29c: add    rax,0x540 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1344ULL);
x86_l_2a2:
	/* 0x2a2: jmp    2ba <__do_str+0x1a9> */
	X86_SIM_X86_SUB_JMP(0x2a2, 0x2ba, x86_l_2ba);
x86_l_2a4:
	/* 0x2a4: add    rax,0x568 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1384ULL);
x86_l_2aa:
	/* 0x2aa: jmp    2ba <__do_str+0x1a9> */
	X86_SIM_X86_SUB_JMP(0x2aa, 0x2ba, x86_l_2ba);
x86_l_2ac:
	/* 0x2ac: add    rax,0x570 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1392ULL);
x86_l_2b2:
	/* 0x2b2: jmp    2ba <__do_str+0x1a9> */
	X86_SIM_X86_SUB_JMP(0x2b2, 0x2ba, x86_l_2ba);
x86_l_2b4:
	/* 0x2b4: add    rax,0x550 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_ADD, 1360ULL);
x86_l_2ba:
	/* 0x2ba: inc QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_2be:
	/* 0x2be: mov    rax,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_R12, X86_WIDTH_64);
x86_l_2c1:
	/* 0x2c1: dec    rax */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_64, X86_ALU_DEC, 1);
x86_l_2c4:
	/* 0x2c4: add    rsp,0x18 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 24ULL);
x86_l_2c8:
	/* 0x2c8: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_2c9:
	/* 0x2c9: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_2cb:
	/* 0x2cb: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_2cd:
	/* 0x2cd: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_2cf:
	/* 0x2cf: ret */
	X86_SIM_X86_SUB_RET(x86_sim_ret_dispatch);

x86_sim_ret_dispatch:
	switch (__x86_sim_ret_addr) {
	case 0x2aULL: goto x86_l_2a;
	case 0x3fULL: goto x86_l_3f;
	case 0x60ULL: goto x86_l_60;
	case 0x83ULL: goto x86_l_83;
	case 0xd3ULL: goto x86_l_d3;
	case 0xf8ULL: goto x86_l_f8;
	case 0x13aULL: goto x86_l_13a;
	case 0x183ULL: goto x86_l_183;
	case 0x1b3ULL: goto x86_l_1b3;
	case 0x1daULL: goto x86_l_1da;
	case 0x220ULL: goto x86_l_220;
	case 0x247ULL: goto x86_l_247;
	}

}

X86_SIM_LICENSE();
