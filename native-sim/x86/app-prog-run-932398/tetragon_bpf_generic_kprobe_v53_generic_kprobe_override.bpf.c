extern char override_tasks;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_generic_kprobe_v53_generic_kprobe_override_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: sub    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_4:
	/* 0x4: mov    rbx,rdi */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RDI, X86_WIDTH_64);
x86_l_7:
	/* 0x7: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_c:
	/* 0xc: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_e:
	/* 0xe: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_13:
	/* 0x13: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_18:
	/* 0x18: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&override_tasks)));
x86_l_1f:
	/* 0x1f: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_24:
	/* 0x24: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_26:
	/* 0x26: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_29:
	/* 0x29: je     4b <generic_kprobe_override+0x4b> */
	X86_SIM_X86_JCC(X86_CC_E, 0x29, 0x4b, x86_l_4b);
x86_l_2b:
	/* 0x2b: mov    ecx,0x3a */
	X86_SIM_L_EXEC_MOV_IMM(X86_RCX, X86_WIDTH_32, 58ULL);
x86_l_30:
	/* 0x30: movsxd rsi,DWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RSI, X86_RAX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_33:
	/* 0x33: mov    rdi,rbx */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RBX, X86_WIDTH_64);
x86_l_36:
	/* 0x36: call   rcx */
	X86_SIM_BPF_CALL_REG(X86_RCX);
x86_l_38:
	/* 0x38: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_3d:
	/* 0x3d: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&override_tasks)));
x86_l_44:
	/* 0x44: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_49:
	/* 0x49: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_4b:
	/* 0x4b: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4d:
	/* 0x4d: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_51:
	/* 0x51: jmp    56 <generic_kprobe_override+0x56> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_56:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
