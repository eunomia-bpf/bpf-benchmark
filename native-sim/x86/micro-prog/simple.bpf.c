#include "../x86_sim_local_bpf.h"

SEC("xdp")
int simple_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: mov    rcx,QWORD PTR [rdi] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_3:
	/* 0x3: mov    rdx,QWORD PTR [rdi+0x8] */
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_7:
	/* 0x7: mov    rsi,rcx */
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RSI, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_a:
	/* 0xa: xor    eax,eax */
	X86_SIM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_c:
	/* 0xc: cmp    rsi,rdx */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_f:
	/* 0xf: ja     0x3c */
	X86_SIM_X86_JCC(X86_CC_A, 0xf, 0x3c, x86_l_3c);
x86_l_11:
	/* 0x11: lea    rdi,[rsi+0x8] */
	X86_SIM_RUN_OP(X86_OP_LEA, X86_RDI, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_15:
	/* 0x15: cmp    rdi,rdx */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RDI, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_18:
	/* 0x18: ja     0x3c */
	X86_SIM_X86_JCC(X86_CC_A, 0x18, 0x3c, x86_l_3c);
x86_l_1a:
	/* 0x1a: add    rsi,0x48 */
	X86_SIM_RUN_OP(X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 72ULL);
x86_l_1e:
	/* 0x1e: cmp    rsi,rdx */
	X86_SIM_RUN_OP(X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_21:
	/* 0x21: ja     0x3c */
	X86_SIM_X86_JCC(X86_CC_A, 0x21, 0x3c, x86_l_3c);
x86_l_23:
	/* 0x23: mov    WORD PTR [rcx],0x614e */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 24910ULL);
x86_l_28:
	/* 0x28: mov    BYTE PTR [rcx+0x2],0xbc */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8589934780ULL);
x86_l_2c:
	/* 0x2c: mov    DWORD PTR [rcx+0x3],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12884901888ULL);
x86_l_33:
	/* 0x33: mov    BYTE PTR [rcx+0x7],0x0 */
	X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30064771072ULL);
x86_l_37:
	/* 0x37: mov    eax,0x2 */
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_3c:
	/* 0x3c: jmp    0x41 ; native-link entry RET */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
