extern char write_offload;
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_ENABLE_STACK_DEEP 1
#include "../x86_sim_local_bpf.h"

SEC("xdp")
int tetragon_bpf_multi_usdt_v61_generic_sleepable_offload_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: push   rax */
	X86_SIM_L_EXEC_PUSH(X86_RAX);
x86_l_1:
	/* 0x1: mov    eax,0xe */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 14ULL);
x86_l_6:
	/* 0x6: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_8:
	/* 0x8: mov    QWORD PTR [rsp],rax */
	X86_SIM_L_EXEC_STORE(X86_OP_MOV_STORE_REG, X86_RSP, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_c:
	/* 0xc: mov    rdi,QWORD PTR [rip+0xf0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&write_offload)));
x86_l_13:
	/* 0x13: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_16:
	/* 0x16: mov    eax,0x1 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 1ULL);
x86_l_1b:
	/* 0x1b: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_1d:
	/* 0x1d: test   rax,rax */
	X86_SIM_L_EXEC_CMP_REG_OP(X86_OP_TEST_REG, X86_RAX, X86_RAX, X86_WIDTH_64);
x86_l_20:
	/* 0x20: je     54 <generic_sleepable_offload+0x54> */
	X86_SIM_X86_JCC(X86_CC_E, 0x20, 0x54, x86_l_54);
x86_l_22:
	/* 0x22: mov    rcx,QWORD PTR [rax] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RCX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_25:
	/* 0x25: mov    rsi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RAX, X86_WIDTH_64);
x86_l_28:
	/* 0x28: add    rsi,0x8 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_64, X86_ALU_ADD, 8ULL);
x86_l_2c:
	/* 0x2c: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_31:
	/* 0x31: mov    rdi,rax */
	X86_SIM_L_EXEC_MOV_REG(X86_RDI, X86_RAX, X86_WIDTH_64);
x86_l_34:
	/* 0x34: mov    eax,0x24 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 36ULL);
x86_l_39:
	/* 0x39: mov    rdi,QWORD PTR [rdi] */
	X86_SIM_L_EXEC_MOV_LOAD(X86_OP_MOV_LOAD, X86_RDI, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3c:
	/* 0x3c: mov    edx,0x4 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RDX, X86_WIDTH_32, 4ULL);
x86_l_41:
	/* 0x41: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_43:
	/* 0x43: mov    rdi,QWORD PTR [rip+0xf0] */
	X86_SIM_L_WRITE_REG_MAP_PTR(X86_RDI, (void *)(long)(((__u64)(long)&write_offload)));
x86_l_4a:
	/* 0x4a: mov    rsi,rsp */
	X86_SIM_L_EXEC_MOV_REG(X86_RSI, X86_RSP, X86_WIDTH_64);
x86_l_4d:
	/* 0x4d: mov    eax,0x3 */
	X86_SIM_L_EXEC_MOV_IMM(X86_RAX, X86_WIDTH_32, 3ULL);
x86_l_52:
	/* 0x52: call   rax */
	X86_SIM_BPF_CALL_REG(X86_RAX);
x86_l_54:
	/* 0x54: xor    eax,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_56:
	/* 0x56: pop    rcx */
	X86_SIM_L_EXEC_POP(X86_RCX, X86_WIDTH_64);
x86_l_57:
	/* 0x57: jmp    5c <generic_sleepable_offload+0x5c> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_5c:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
