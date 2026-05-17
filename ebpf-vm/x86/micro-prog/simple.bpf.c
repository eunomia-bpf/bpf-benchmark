#define X86_VM_ENABLE_STACK 1
#include "../x86_vm_bpf.h"

SEC("xdp")
int simple_x86_vm_xdp(struct xdp_md *ctx)
{
	X86_VM_DECLARE_XDP(ctx);
x86_l_1100:
	/* 0x1100: mov    rcx,QWORD PTR [rdi] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1103:
	/* 0x1103: mov    rdx,QWORD PTR [rdi+0x8] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1107:
	/* 0x1107: xor    eax,eax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1109:
	/* 0x1109: cmp    rcx,rdx */
	X86_VM_RUN_OP(x86_exec_cmp_reg, X86_OP_CMP_REG, X86_RCX, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_110c:
	/* 0x110c: ja     113e <simple_xdp+0x3e> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_113e;
x86_l_110e:
	/* 0x110e: lea    rsi,[rcx+0x8] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1112:
	/* 0x1112: cmp    rsi,rdx */
	X86_VM_RUN_OP(x86_exec_cmp_reg, X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_1115:
	/* 0x1115: ja     113e <simple_xdp+0x3e> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_113e;
x86_l_1117:
	/* 0x1117: lea    rsi,[rcx+0x48] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_RSI, X86_RCX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 72ULL);
x86_l_111b:
	/* 0x111b: cmp    rsi,rdx */
	X86_VM_RUN_OP(x86_exec_cmp_reg, X86_OP_CMP_REG, X86_RSI, X86_RDX, X86_WIDTH_64, 0, 0);
x86_l_111e:
	/* 0x111e: ja     113e <simple_xdp+0x3e> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_113e;
x86_l_1120:
	/* 0x1120: push   rbp */
	X86_VM_RUN_OP(x86_exec_push, X86_OP_PUSH, X86_REG_NONE, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_1121:
	/* 0x1121: mov    rbp,rsp */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RBP, X86_RSP, X86_WIDTH_64, 0, 0);
x86_l_1124:
	/* 0x1124: mov    WORD PTR [rcx],0x614e */
	X86_VM_RUN_OP(x86_exec_mov_store_imm, X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_16, X86_MEM_AUX(X86_REG_NONE, 0), 24910ULL);
x86_l_1129:
	/* 0x1129: mov    BYTE PTR [rcx+0x2],0xbc */
	X86_VM_RUN_OP(x86_exec_mov_store_imm, X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 8589934780ULL);
x86_l_112d:
	/* 0x112d: mov    DWORD PTR [rcx+0x3],0x0 */
	X86_VM_RUN_OP(x86_exec_mov_store_imm, X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 12884901888ULL);
x86_l_1134:
	/* 0x1134: mov    BYTE PTR [rcx+0x7],0x0 */
	X86_VM_RUN_OP(x86_exec_mov_store_imm, X86_OP_MOV_STORE_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_8, X86_MEM_AUX(X86_REG_NONE, 0), 30064771072ULL);
x86_l_1138:
	/* 0x1138: mov    eax,0x2 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_113d:
	/* 0x113d: pop    rbp */
	X86_VM_RUN_OP(x86_exec_pop, X86_OP_POP, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_113e:
	/* 0x113e: ret */
	X86_VM_RET_RAX();
	return XDP_ABORTED;
}

X86_VM_LICENSE();
