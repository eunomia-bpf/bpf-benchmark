extern char tcpmon_map;
extern char tg_conf_map;
extern char tg_rb_events;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_generic_rawtp_v61___do_bytes_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   r15 */
	X86_SIM_L_EXEC_PUSH(X86_R15);
x86_l_2:
	/* 0x2: push   r14 */
	X86_SIM_L_EXEC_PUSH(X86_R14);
x86_l_4:
	/* 0x4: push   r12 */
	X86_SIM_L_EXEC_PUSH(X86_R12);
x86_l_6:
	/* 0x6: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_7:
	/* 0x7: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_8:
	/* 0x8: test   rcx,rcx */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RCX, X86_RCX, X86_WIDTH_64);
x86_l_b:
	/* 0xb: js     8d <__do_bytes+0x8d> */
	X86_SIM_X86_JCC(X86_CC_S, 0xb, 0x8d, x86_l_8d);
x86_l_11:
	/* 0x11: mov    r14,rsi */
	X86_SIM_L_EXEC_MOV_REG(X86_R14, X86_RSI, X86_WIDTH_64);
x86_l_14:
	/* 0x14: mov    r12,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_R12, X86_RDI, X86_WIDTH_64);
x86_l_17:
	/* 0x17: cmp    rcx,0x7fe0 */
	X86_SIM_L_EXEC_CMP_IMM_OP(X86_OP_CMP_IMM, X86_RCX, X86_WIDTH_64, 32736ULL);
x86_l_1e:
	/* 0x1e: mov    ebx,0x7fe0 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_32, 32736ULL);
x86_l_23:
	/* 0x23: cmovb  rbx,rcx */
	X86_SIM_L_EXEC_CMOV(X86_RBX, X86_RCX, X86_WIDTH_64, X86_CC_B);
x86_l_27:
	/* 0x27: lea    rdi,[rsi+0x20] */
	X86_SIM_L_EXEC_LEA(X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_2b:
	/* 0x2b: mov    eax,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 4ULL);
x86_l_30:
	/* 0x30: mov    esi,ebx */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RBX, X86_WIDTH_32);
x86_l_32:
	/* 0x32: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_34:
	/* 0x34: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_36:
	/* 0x36: js     b2 <__do_bytes+0xb2> */
	X86_SIM_X86_JCC(X86_CC_S, 0x36, 0xb2, x86_l_b2);
x86_l_38:
	/* 0x38: lea    r15d,[rbx+0x20] */
	X86_SIM_L_EXEC_LEA(X86_R15, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 32ULL);
x86_l_3c:
	/* 0x3c: mov    DWORD PTR [r14+0x4],r15d */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_R14, X86_R15, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_40:
	/* 0x40: mov    DWORD PTR [rsp+0x4],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869184ULL);
x86_l_48:
	/* 0x48: mov    rdi,QWORD PTR [rip+0x57c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_conf_map)));
x86_l_4f:
	/* 0x4f: lea    rsi,[rsp+0x4] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 4ULL);
x86_l_54:
	/* 0x54: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_59:
	/* 0x59: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_5b:
	/* 0x5b: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_5e:
	/* 0x5e: je     96 <__do_bytes+0x96> */
	X86_SIM_X86_JCC(X86_CC_E, 0x5e, 0x96, x86_l_96);
x86_l_60:
	/* 0x60: cmp    BYTE PTR [rax+0x28],0x0 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 171798691840ULL);
x86_l_64:
	/* 0x64: je     96 <__do_bytes+0x96> */
	X86_SIM_X86_JCC(X86_CC_E, 0x64, 0x96, x86_l_96);
x86_l_66:
	/* 0x66: mov    rsi,QWORD PTR [rip+0x57c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RSI, (void *)(long)(((__u64)(long)&tcpmon_map)));
x86_l_6d:
	/* 0x6d: mov    ecx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 4294967295ULL);
x86_l_72:
	/* 0x72: mov    eax,0x19 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 25ULL);
x86_l_77:
	/* 0x77: mov    rdi,r12 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_R12, X86_WIDTH_64);
x86_l_7a:
	/* 0x7a: mov    edx,0xffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4294967295ULL);
x86_l_7f:
	/* 0x7f: mov    rcx,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RCX, X86_R14, X86_WIDTH_64);
x86_l_82:
	/* 0x82: mov    r8,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_R8, X86_R15, X86_WIDTH_64);
x86_l_85:
	/* 0x85: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_87:
	/* 0x87: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_89:
	/* 0x89: js     b2 <__do_bytes+0xb2> */
	X86_SIM_X86_JCC(X86_CC_S, 0x89, 0xb2, x86_l_b2);
x86_l_8b:
	/* 0x8b: jmp    b5 <__do_bytes+0xb5> */
	X86_SIM_X86_JMP(0x8b, 0xb5, x86_l_b5);
x86_l_8d:
	/* 0x8d: mov    rbx,0xffffffffffffffff */
	X86_SIM_L_EXEC_MOV_IMM(X86_RBX, X86_WIDTH_64, 18446744073709551615ULL);
x86_l_94:
	/* 0x94: jmp    b5 <__do_bytes+0xb5> */
	X86_SIM_X86_JMP(0x94, 0xb5, x86_l_b5);
x86_l_96:
	/* 0x96: mov    rdi,QWORD PTR [rip+0x57c] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&tg_rb_events)));
x86_l_9d:
	/* 0x9d: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_9f:
	/* 0x9f: mov    eax,0x82 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 130ULL);
x86_l_a4:
	/* 0xa4: mov    rsi,r14 */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_R14, X86_WIDTH_64);
x86_l_a7:
	/* 0xa7: mov    rdx,r15 */
	X86_SIM_L_EXEC_MOV_REG(X86_RDX, X86_R15, X86_WIDTH_64);
x86_l_aa:
	/* 0xaa: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_ac:
	/* 0xac: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_ae:
	/* 0xae: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_b0:
	/* 0xb0: jns    b5 <__do_bytes+0xb5> */
	X86_SIM_X86_JCC(X86_CC_NS, 0xb0, 0xb5, x86_l_b5);
x86_l_b2:
	/* 0xb2: movsxd rbx,eax */
	X86_SIM_L_EXEC_MOVX_REG(X86_OP_MOVSX_REG, X86_RBX, X86_RAX, X86_WIDTH_64, X86_WIDTH_32);
x86_l_b5:
	/* 0xb5: mov    rax,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RBX, X86_WIDTH_64);
x86_l_b8:
	/* 0xb8: add    rsp,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_bc:
	/* 0xbc: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_bd:
	/* 0xbd: pop    r12 */
	X86_SIM_L_EXEC_POP(X86_R12, X86_WIDTH_64);
x86_l_bf:
	/* 0xbf: pop    r14 */
	X86_SIM_L_EXEC_POP(X86_R14, X86_WIDTH_64);
x86_l_c1:
	/* 0xc1: pop    r15 */
	X86_SIM_L_EXEC_POP(X86_R15, X86_WIDTH_64);
x86_l_c3:
	/* 0xc3: jmp    c8 <__do_bytes+0xc8> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_c8:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
