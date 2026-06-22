extern char override_tasks;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_multi_kprobe_v61_generic_fmodret_override_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   rbx */
	X86_SIM_L_EXEC_PUSH(X86_RBX);
x86_l_1:
	/* 0x1: sub    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_SUB, 16ULL);
x86_l_5:
	/* 0x5: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_a:
	/* 0xa: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_c:
	/* 0xc: mov    QWORD PTR [rsp+0x8],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_11:
	/* 0x11: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&override_tasks)));
x86_l_18:
	/* 0x18: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1d:
	/* 0x1d: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_22:
	/* 0x22: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_24:
	/* 0x24: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_27:
	/* 0x27: je     4c <generic_fmodret_override+0x4c> */
	X86_SIM_X86_JCC(X86_CC_E, 0x27, 0x4c, x86_l_4c);
x86_l_29:
	/* 0x29: mov    rbx,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RBX, X86_RAX, X86_WIDTH_64);
x86_l_2c:
	/* 0x2c: mov    rdi,QWORD PTR [rip+0x0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&override_tasks)));
x86_l_33:
	/* 0x33: lea    rsi,[rsp+0x8] */
	X86_SIM_L_EXEC_LEA(X86_RSI, X86_RSP, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_38:
	/* 0x38: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_3d:
	/* 0x3d: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_3f:
	/* 0x3f: movsxd rax,DWORD PTR [rbx] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOVSX_LOAD, X86_RAX, X86_RBX, X86_WIDTH_64, X86_MEM_AUX_FULL(X86_REG_NONE, 0, X86_WIDTH_32), 0ULL);
x86_l_42:
	/* 0x42: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_46:
	/* 0x46: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_47:
	/* 0x47: jmp    58 <generic_fmodret_override+0x58> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_4c:
	/* 0x4c: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4e:
	/* 0x4e: add    rsp,0x10 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSP, X86_WIDTH_64, X86_ALU_ADD, 16ULL);
x86_l_52:
	/* 0x52: pop    rbx */
	X86_SIM_L_EXEC_POP(X86_RBX, X86_WIDTH_64);
x86_l_53:
	/* 0x53: jmp    58 <generic_fmodret_override+0x58> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_58:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
