#include "../x86_vm_bpf.h"

SEC("xdp")
int tc_packet_checksum_fold_x86_vm_xdp(struct xdp_md *ctx)
{
	void *__x86_vm_data = (void *)(long)ctx->data;
	void *__x86_vm_data_end = (void *)(long)ctx->data_end;
	struct x86_vm_checksum_loop_ctx __x86_loop = {};
	struct x86_insn __x86_vm_insn = {};
	#define __x86_vm_state __x86_loop.state
	x86_init_state(&__x86_vm_state, (void *)ctx);
x86_l_1100:
	/* 0x1100: mov    rax,QWORD PTR [rdi] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1103:
	/* 0x1103: mov    rcx,QWORD PTR [rdi+0x8] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1107:
	/* 0x1107: cmp    rax,rcx */
	X86_VM_RUN_OP(x86_exec_cmp_reg, X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_110a:
	/* 0x110a: jbe    1121 <tc_packet_checksum_fold_prog+0x21> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_BE))
		goto x86_l_1121;
x86_l_110c:
	/* 0x110c: mov    DWORD PTR [rdi+0x10],0xffffffff */
	X86_VM_RUN_CTX_OUTPUT_IMM32(16ULL, 4294967295ULL);
x86_l_1113:
	/* 0x1113: mov    eax,0x2 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_1118:
	/* 0x1118: mov    edx,0xffffffff */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967295ULL);
x86_l_111d:
	/* 0x111d: mov    DWORD PTR [rdi+0x14],edx */
	X86_VM_RUN_CTX_OUTPUT_REG32(X86_RDX, 20ULL, X86_MEM_AUX(X86_REG_NONE, 0));
x86_l_1120:
	/* 0x1120: ret */
	X86_VM_RET_RAX();
x86_l_1121:
	/* 0x1121: lea    rdx,[rax+0x8] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1125:
	/* 0x1125: cmp    rdx,rcx */
	X86_VM_RUN_OP(x86_exec_cmp_reg, X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_1128:
	/* 0x1128: ja     110c <tc_packet_checksum_fold_prog+0xc> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_110c;
x86_l_112a:
	/* 0x112a: lea    rdx,[rax+0x410] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1040ULL);
x86_l_1131:
	/* 0x1131: cmp    rdx,rcx */
	X86_VM_RUN_OP(x86_exec_cmp_reg, X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_1134:
	/* 0x1134: ja     110c <tc_packet_checksum_fold_prog+0xc> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_110c;
x86_l_1136:
	/* 0x1136: cmp    DWORD PTR [rax+0x8],0x20 */
	X86_VM_RUN_OP(x86_exec_cmp_mem_imm, X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738400ULL);
x86_l_113a:
	/* 0x113a: jne    110c <tc_packet_checksum_fold_prog+0xc> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_110c;
x86_l_113c:
	/* 0x113c: cmp    DWORD PTR [rax+0xc],0x200 */
	X86_VM_RUN_OP(x86_exec_cmp_mem_imm, X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539608064ULL);
x86_l_1143:
	/* 0x1143: jne    110c <tc_packet_checksum_fold_prog+0xc> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_110c;
x86_l_1145:
	/* 0x1145: push   rbp */
	X86_VM_RUN_OP(x86_exec_push, X86_OP_PUSH, X86_REG_NONE, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_1146:
	/* 0x1146: mov    rbp,rsp */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RBP, X86_RSP, X86_WIDTH_64, 0, 0);
x86_l_1149:
	/* 0x1149: xor    esi,esi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_114b:
	/* 0x114b: xor    edx,edx */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_114d:
	/* 0x114d: nop    DWORD PTR [rax] */
	X86_VM_RUN_OP(x86_exec_nop, X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1150:
	/* 0x1150..0x11b4: C-authored TC checksum loop template */
	__x86_loop.data = __x86_vm_data;
	__x86_loop.data_end = __x86_vm_data_end;
	if (x86_vm_run_tc_packet_checksum_fold(&__x86_loop) < 0)
		return XDP_ABORTED;
x86_l_11b6:
	/* 0x11b6: mov    DWORD PTR [rdi+0x10],edx */
	X86_VM_RUN_CTX_OUTPUT_REG32(X86_RDX, 16ULL, X86_MEM_AUX(X86_REG_NONE, 0));
x86_l_11b9:
	/* 0x11b9: shr    rdx,0x20 */
	X86_VM_RUN_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_11bd:
	/* 0x11bd: xor    eax,eax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_11bf:
	/* 0x11bf: pop    rbp */
	X86_VM_RUN_OP(x86_exec_pop, X86_OP_POP, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_11c0:
	/* 0x11c0: mov    DWORD PTR [rdi+0x14],edx */
	X86_VM_RUN_CTX_OUTPUT_REG32(X86_RDX, 20ULL, X86_MEM_AUX(X86_REG_NONE, 0));
x86_l_11c3:
	/* 0x11c3: ret */
	X86_VM_RET_RAX();
	#undef __x86_vm_state
	return XDP_ABORTED;
}

X86_VM_LICENSE();
