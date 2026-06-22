#include "../x86_sim_local_bpf.h"

SEC("xdp")
int katran_balancer_jhash_2words_x86_sim_xdp(struct xdp_md *ctx)
{
	X86_SIM_ENTRY_XDP(ctx);
x86_l_0:
	/* 0x0: add    edi,0xe0adc0f7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RDI, X86_WIDTH_32, X86_ALU_ADD, 3769483511ULL);
x86_l_6:
	/* 0x6: add    esi,0xe0adc0f7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RSI, X86_WIDTH_32, X86_ALU_ADD, 3769483511ULL);
x86_l_c:
	/* 0xc: mov    eax,esi */
	X86_SIM_L_EXEC_MOV_REG(X86_RAX, X86_RSI, X86_WIDTH_32);
x86_l_e:
	/* 0xe: xor    eax,0xe0adc0f7 */
	X86_SIM_L_EXEC_ALU_IMM(X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 3769483511ULL);
x86_l_13:
	/* 0x13: rorx   ecx,esi,0x12 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RSI, X86_WIDTH_32, 0, 18ULL);
x86_l_19:
	/* 0x19: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_1b:
	/* 0x1b: xor    edi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_1d:
	/* 0x1d: rorx   ecx,eax,0x15 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 21ULL);
x86_l_23:
	/* 0x23: sub    edi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_25:
	/* 0x25: xor    esi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_27:
	/* 0x27: rorx   ecx,edi,0x7 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RDI, X86_WIDTH_32, 0, 7ULL);
x86_l_2d:
	/* 0x2d: sub    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_2f:
	/* 0x2f: xor    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_31:
	/* 0x31: rorx   ecx,esi,0x10 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RSI, X86_WIDTH_32, 0, 16ULL);
x86_l_37:
	/* 0x37: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_39:
	/* 0x39: xor    edi,eax */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RAX, X86_WIDTH_32, X86_ALU_XOR);
x86_l_3b:
	/* 0x3b: rorx   ecx,eax,0x1c */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 28ULL);
x86_l_41:
	/* 0x41: sub    edi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RDI, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_43:
	/* 0x43: xor    esi,edi */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_45:
	/* 0x45: rorx   ecx,edi,0x12 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RDI, X86_WIDTH_32, 0, 18ULL);
x86_l_4b:
	/* 0x4b: sub    esi,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RSI, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_4d:
	/* 0x4d: xor    eax,esi */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RSI, X86_WIDTH_32, X86_ALU_XOR);
x86_l_4f:
	/* 0x4f: rorx   ecx,esi,0x8 */
	X86_SIM_RUN_OP(X86_OP_RORX, X86_RCX, X86_RSI, X86_WIDTH_32, 0, 8ULL);
x86_l_55:
	/* 0x55: sub    eax,ecx */
	X86_SIM_L_EXEC_ALU_REG(X86_RAX, X86_RCX, X86_WIDTH_32, X86_ALU_SUB);
x86_l_57:
	/* 0x57: jmp    5c <jhash_2words+0x5c> ; native-link entry RET */
	X86_SIM_X86_RET();
x86_l_5c:
	/* native-link entry fallthrough exit */
	X86_SIM_X86_RET();
}

X86_SIM_LICENSE();
