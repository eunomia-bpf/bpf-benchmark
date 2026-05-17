#define X86_VM_ENABLE_STACK 1
#include "../x86_vm_bpf.h"

static long x86_loop_1150_1150_cb(__u32 __x86_loop_index, void *ctx)
{
	struct x86_vm_loop_ctx *loop = ctx;
	void *__x86_vm_data = loop->data;
	void *__x86_vm_data_end = loop->data_end;
	struct x86_insn __x86_vm_insn = {};
	#define __x86_vm_state loop->state

	(void)__x86_loop_index;
	if (loop->failed || loop->done || loop->next)
		return 1;
x86_l_1150:
	/* 0x1150: movzx  r8d,WORD PTR [rdx+rcx*1-0x3] */
	X86_VM_LOOP_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_R8, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_16), 18446744073709551613ULL);
x86_l_1156:
	/* 0x1156: add    r8d,edi */
	X86_VM_LOOP_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R8, X86_RDI, X86_WIDTH_32, X86_ALU_ADD, 0);
x86_l_1159:
	/* 0x1159: movzx  edi,r8w */
	X86_VM_LOOP_OP(x86_exec_movzx_reg, X86_OP_MOVZX_REG, X86_RDI, X86_R8, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_115d:
	/* 0x115d: shr    r8d,0x10 */
	X86_VM_LOOP_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1161:
	/* 0x1161: add    r8d,edi */
	X86_VM_LOOP_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_R8, X86_RDI, X86_WIDTH_32, X86_ALU_ADD, 0);
x86_l_1164:
	/* 0x1164: movzx  edi,WORD PTR [rdx+rcx*1-0x1] */
	X86_VM_LOOP_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 0, X86_WIDTH_16), 18446744073709551615ULL);
x86_l_1169:
	/* 0x1169: add    edi,r8d */
	X86_VM_LOOP_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_R8, X86_WIDTH_32, X86_ALU_ADD, 0);
x86_l_116c:
	/* 0x116c: movzx  r8d,di */
	X86_VM_LOOP_OP(x86_exec_movzx_reg, X86_OP_MOVZX_REG, X86_R8, X86_RDI, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_1170:
	/* 0x1170: shr    edi,0x10 */
	X86_VM_LOOP_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1173:
	/* 0x1173: add    edi,r8d */
	X86_VM_LOOP_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_R8, X86_WIDTH_32, X86_ALU_ADD, 0);
x86_l_1176:
	/* 0x1176: add    rcx,0x4 */
	X86_VM_LOOP_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 4ULL);
x86_l_117a:
	/* 0x117a: cmp    rcx,0x413 */
	X86_VM_LOOP_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, 0, 1043ULL);
x86_l_1181:
	/* 0x1181: jne    1150 <packet_checksum_fold_xdp+0x50> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		return 0;
	loop->next = 0x1183;
	return 1;
	#undef __x86_vm_state
	return 0;
}

static long x86_loop_1140_1140_cb(__u32 __x86_loop_index, void *ctx)
{
	struct x86_vm_loop_ctx *loop = ctx;
	void *__x86_vm_data = loop->data;
	void *__x86_vm_data_end = loop->data_end;
	struct x86_insn __x86_vm_insn = {};
	#define __x86_vm_state loop->state

	(void)__x86_loop_index;
	if (loop->failed || loop->done || loop->next)
		return 1;
x86_l_1140:
	/* 0x1140: mov    ecx,0x13 */
	X86_VM_LOOP_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, 0, 19ULL);
x86_l_1145:
	/* 0x1145: xor    edi,edi */
	X86_VM_LOOP_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RDI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1147:
	/* 0x1147: nop    WORD PTR [rax+rax*1+0x0] */
	X86_VM_LOOP_OP(x86_exec_nop, X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1150:
	/* 0x1150: movzx  r8d,WORD PTR [rdx+rcx*1-0x3] */
	/* nested verifier loop lowering */
	loop->failed = 0;
	loop->done = 0;
	loop->next = 0;
	loop->data = __x86_vm_data;
	loop->data_end = __x86_vm_data_end;
	if (bpf_loop(256, x86_loop_1150_1150_cb, loop, 0) < 0) {
		loop->failed = __LINE__;
		return 1;
	}
	if (loop->failed)
		return 1;
	if (loop->done)
		return 1;
	if (loop->next == 0x1183) {
		loop->next = 0;
		goto x86_l_1183;
	}
	return 1;
x86_l_1183:
	/* 0x1183: mov    ecx,edi */
	X86_VM_LOOP_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RCX, X86_RDI, X86_WIDTH_32, 0, 0);
x86_l_1185:
	/* 0x1185: shr    ecx,0x10 */
	X86_VM_LOOP_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1188:
	/* 0x1188: add    ecx,edi */
	X86_VM_LOOP_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RCX, X86_RDI, X86_WIDTH_32, X86_ALU_ADD, 0);
x86_l_118a:
	/* 0x118a: not    ecx */
	X86_VM_LOOP_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_118c:
	/* 0x118c: movzx  edi,cx */
	X86_VM_LOOP_OP(x86_exec_movzx_reg, X86_OP_MOVZX_REG, X86_RDI, X86_RCX, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_118f:
	/* 0x118f: mov    ecx,eax */
	X86_VM_LOOP_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
x86_l_1191:
	/* 0x1191: shl    ecx,0x4 */
	X86_VM_LOOP_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 4ULL);
x86_l_1194:
	/* 0x1194: shl    rdi,cl */
	X86_VM_LOOP_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RDI, X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 0);
x86_l_1197:
	/* 0x1197: xor    rsi,rdi */
	X86_VM_LOOP_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RSI, X86_RDI, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_119a:
	/* 0x119a: inc    eax */
	X86_VM_LOOP_OP(x86_exec_alu_imm, X86_OP_ALU_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_119c:
	/* 0x119c: cmp    eax,0x20 */
	X86_VM_LOOP_OP(x86_exec_cmp_imm, X86_OP_CMP_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 32ULL);
x86_l_119f:
	/* 0x119f: jne    1140 <packet_checksum_fold_xdp+0x40> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE)) {
		if (__x86_vm_state.rax == 32) {
			loop->next = 0xbeef;
			return 1;
		}
		return 0;
	}
	loop->next = 0x11a1;
	return 1;
	#undef __x86_vm_state
	return 0;
}

SEC("xdp")
int packet_checksum_fold_x86_vm_xdp(struct xdp_md *ctx)
{
	void *__x86_vm_data = (void *)(long)ctx->data;
	void *__x86_vm_data_end = (void *)(long)ctx->data_end;
	struct x86_vm_loop_ctx __x86_loop = {};
	struct x86_insn __x86_vm_insn = {};
	#define __x86_vm_state __x86_loop.state
	x86_init_state(&__x86_vm_state, (void *)ctx);
x86_l_1100:
	/* 0x1100: mov    rdx,QWORD PTR [rdi] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RDX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1103:
	/* 0x1103: mov    rcx,QWORD PTR [rdi+0x8] */
	X86_VM_RUN_OP(x86_exec_mov_load, X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1107:
	/* 0x1107: xor    eax,eax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1109:
	/* 0x1109: cmp    rdx,rcx */
	X86_VM_RUN_OP(x86_exec_cmp_reg, X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_110c:
	/* 0x110c: jbe    110f <packet_checksum_fold_xdp+0xf> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_BE))
		goto x86_l_110f;
x86_l_110e:
	/* 0x110e: ret */
	return 13;
x86_l_110f:
	/* 0x110f: lea    rsi,[rdx+0x8] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1113:
	/* 0x1113: cmp    rsi,rcx */
	X86_VM_RUN_OP(x86_exec_cmp_reg, X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_1116:
	/* 0x1116: ja     110e <packet_checksum_fold_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_110e;
x86_l_1118:
	/* 0x1118: lea    rsi,[rdx+0x410] */
	X86_VM_RUN_OP(x86_exec_lea, X86_OP_LEA, X86_RSI, X86_RDX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1040ULL);
x86_l_111f:
	/* 0x111f: cmp    rsi,rcx */
	X86_VM_RUN_OP(x86_exec_cmp_reg, X86_OP_CMP_REG, X86_RSI, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_1122:
	/* 0x1122: ja     110e <packet_checksum_fold_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_110e;
x86_l_1124:
	/* 0x1124: cmp    DWORD PTR [rdx+0x8],0x20 */
	X86_VM_RUN_OP(x86_exec_cmp_mem_imm, X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738400ULL);
x86_l_1128:
	/* 0x1128: jne    110e <packet_checksum_fold_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_110e;
x86_l_112a:
	/* 0x112a: cmp    DWORD PTR [rdx+0xc],0x200 */
	X86_VM_RUN_OP(x86_exec_cmp_mem_imm, X86_OP_CMP_MEM_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539608064ULL);
x86_l_1131:
	/* 0x1131: jne    110e <packet_checksum_fold_xdp+0xe> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_110e;
x86_l_1133:
	/* 0x1133: push   rbp */
	X86_VM_RUN_OP(x86_exec_push, X86_OP_PUSH, X86_REG_NONE, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_1134:
	/* 0x1134: mov    rbp,rsp */
	X86_VM_RUN_OP(x86_exec_mov_reg, X86_OP_MOV_REG, X86_RBP, X86_RSP, X86_WIDTH_64, 0, 0);
x86_l_1137:
	/* 0x1137: xor    eax,eax */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1139:
	/* 0x1139: xor    esi,esi */
	X86_VM_RUN_OP(x86_exec_alu_reg, X86_OP_ALU_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_113b:
	/* 0x113b: nop    DWORD PTR [rax+rax*1+0x0] */
	X86_VM_RUN_OP(x86_exec_nop, X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1140:
	/* 0x1140: mov    ecx,0x13 */
	/* verifier loop lowering: bpf_loop callback preserves x86 steps */
	(&__x86_loop)->failed = 0;
	(&__x86_loop)->done = 0;
	(&__x86_loop)->next = 0;
	(&__x86_loop)->data = __x86_vm_data;
	(&__x86_loop)->data_end = __x86_vm_data_end;
	if (bpf_loop(32, x86_loop_1140_1140_cb, (&__x86_loop), 0) < 0) {
		(&__x86_loop)->failed = __LINE__;
		return 14;
	}
	if ((&__x86_loop)->failed)
		return 10;
	if ((&__x86_loop)->done)
		return 11;
	if ((&__x86_loop)->next == 0x11a1) {
		goto x86_l_11a1;
	}
	return 100 + ((__u32)(&__x86_loop)->state.zf * 10) + ((__u32)(&__x86_loop)->state.rax & 0xf);
x86_l_11a1:
	/* 0x11a1: mov    QWORD PTR [rdx],rsi */
	X86_VM_RUN_OP(x86_exec_mov_store_reg, X86_OP_MOV_STORE_REG, X86_RDX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_11a4:
	/* 0x11a4: mov    eax,0x2 */
	X86_VM_RUN_OP(x86_exec_mov_imm, X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_11a9:
	/* 0x11a9: pop    rbp */
	X86_VM_RUN_OP(x86_exec_pop, X86_OP_POP, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_11aa:
	/* 0x11aa: ret */
	X86_VM_RET_RAX();
	#undef __x86_vm_state
	return 15;
}

X86_VM_LICENSE();
