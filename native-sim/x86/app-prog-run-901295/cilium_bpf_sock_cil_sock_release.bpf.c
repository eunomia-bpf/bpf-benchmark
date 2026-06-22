extern char cilium_lb4_reverse_sk;
extern char cilium_metrics;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int cilium_bpf_sock_cil_sock_release_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: cmp    DWORD PTR [rdi+0x4],0x2 */
	X86_SIM_L_EXEC_CMP_MEM(X86_OP_CMP_MEM_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 17179869186ULL);
x86_l_4:
	/* 0x4: jne    ab <cil_sock_release+0xab> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4, 0xab, x86_l_ab);
x86_l_a:
	/* 0xa: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_b:
	/* 0xb: sub    rsp,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 32ULL);
x86_l_f:
	/* 0xf: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_18:
	/* 0x18: mov    eax,0x2e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 46ULL);
x86_l_1d:
	/* 0x1d: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_20:
	/* 0x20: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_22:
	/* 0x22: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_27:
	/* 0x27: mov    eax,DWORD PTR [rbx+0x34] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 52ULL);
x86_l_2a:
	/* 0x2a: mov    DWORD PTR [rsp+0x10],eax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_2e:
	/* 0x2e: movzx  eax,WORD PTR [rbx+0x30] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RAX, X86_RBX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_16), 48ULL);
x86_l_32:
	/* 0x32: mov    WORD PTR [rsp+0x14],ax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_37:
	/* 0x37: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_3c:
	/* 0x3c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_lb4_reverse_sk)));
x86_l_43:
	/* 0x43: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_48:
	/* 0x48: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4a:
	/* 0x4a: test   eax,eax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_32);
x86_l_4c:
	/* 0x4c: jne    a6 <cil_sock_release+0xa6> */
	X86_SIM_X86_JCC(X86_CC_NE, 0x4c, 0xa6, x86_l_a6);
x86_l_4e:
	/* 0x4e: movabs rax,0x5050e020e */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_64, 21559640590ULL);
x86_l_58:
	/* 0x58: mov    QWORD PTR [rsp+0x18],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_5d:
	/* 0x5d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_62:
	/* 0x62: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_69:
	/* 0x69: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_6e:
	/* 0x6e: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_70:
	/* 0x70: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_73:
	/* 0x73: je     7a <cil_sock_release+0x7a> */
	X86_SIM_X86_JCC(X86_CC_E, 0x73, 0x7a, x86_l_7a);
x86_l_75:
	/* 0x75: inc    QWORD PTR [rax] */
	X86_SIM_L_EXEC_ALU_MEM_UNARY(X86_RAX, X86_WIDTH_64, (X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_64) | X86_MEM_AUX_ALU_OP(X86_ALU_INC)), 0ULL);
x86_l_78:
	/* 0x78: jmp    a6 <cil_sock_release+0xa6> */
	X86_SIM_X86_JMP(0x78, 0xa6, x86_l_a6);
x86_l_7a:
	/* 0x7a: mov    QWORD PTR [rsp+0x8],0x1 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 34359738369ULL);
x86_l_83:
	/* 0x83: mov    QWORD PTR [rsp+0x10],0x0 */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_IMM, X86_RSP, X86_REG_NONE, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 68719476736ULL);
x86_l_8c:
	/* 0x8c: mov    eax,0x2 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 2ULL);
x86_l_91:
	/* 0x91: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&cilium_metrics)));
x86_l_98:
	/* 0x98: lea    rsi,[rsp+0x18] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 24ULL);
x86_l_9d:
	/* 0x9d: lea    rdx,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RDX, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_a2:
	/* 0xa2: xor    ecx,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_a4:
	/* 0xa4: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_a6:
	/* 0xa6: add    rsp,0x20 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 32ULL);
x86_l_aa:
	/* 0xaa: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_ab:
	/* 0xab: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_b0:
	/* 0xb0: jmp    b5 <cil_sock_release+0xb5> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_b5:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
