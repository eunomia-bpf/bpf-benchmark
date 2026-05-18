#define X86_VM_ENABLE_STACK 1
#include "../x86_vm_bpf.h"

static long x86_loop_1160_1160_cb(__u32 __x86_loop_index, void *ctx)
{
	struct x86_vm_loop_ctx *loop = ctx;
	void *__x86_vm_data = loop->data;
	void *__x86_vm_data_end = loop->data_end;
	struct x86_insn __x86_vm_insn = {};
	#define __x86_vm_state loop->state

	(void)__x86_loop_index;
	if (loop->failed || loop->done || loop->next)
		return 1;
x86_l_1160:
	/* 0x1160: movzx  r9d,WORD PTR [rax+rcx*2+0x10] */
	X86_VM_LOOP_OP(X86_OP_MOV_LOAD, X86_R9, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 1, X86_WIDTH_16), 16ULL);
x86_l_1166:
	/* 0x1166: add    r9d,r8d */
	X86_VM_LOOP_OP(X86_OP_ALU_REG, X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_ADD, 0);
x86_l_1169:
	/* 0x1169: movzx  r8d,r9w */
	X86_VM_LOOP_OP(X86_OP_MOVZX_REG, X86_R8, X86_R9, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_116d:
	/* 0x116d: shr    r9d,0x10 */
	X86_VM_LOOP_OP(X86_OP_ALU_IMM, X86_R9, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1171:
	/* 0x1171: add    r9d,r8d */
	X86_VM_LOOP_OP(X86_OP_ALU_REG, X86_R9, X86_R8, X86_WIDTH_32, X86_ALU_ADD, 0);
x86_l_1174:
	/* 0x1174: movzx  r8d,WORD PTR [rax+rcx*2+0x12] */
	X86_VM_LOOP_OP(X86_OP_MOV_LOAD, X86_R8, X86_RAX, X86_WIDTH_32, X86_MEM_AUX_FULL(X86_RCX, 1, X86_WIDTH_16), 18ULL);
x86_l_117a:
	/* 0x117a: add    r8d,r9d */
	X86_VM_LOOP_OP(X86_OP_ALU_REG, X86_R8, X86_R9, X86_WIDTH_32, X86_ALU_ADD, 0);
x86_l_117d:
	/* 0x117d: movzx  r9d,r8w */
	X86_VM_LOOP_OP(X86_OP_MOVZX_REG, X86_R9, X86_R8, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_1181:
	/* 0x1181: shr    r8d,0x10 */
	X86_VM_LOOP_OP(X86_OP_ALU_IMM, X86_R8, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_1185:
	/* 0x1185: add    r8d,r9d */
	X86_VM_LOOP_OP(X86_OP_ALU_REG, X86_R8, X86_R9, X86_WIDTH_32, X86_ALU_ADD, 0);
x86_l_1188:
	/* 0x1188: add    rcx,0x2 */
	X86_VM_LOOP_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_ADD, 2ULL);
x86_l_118c:
	/* 0x118c: cmp    rcx,0x200 */
	X86_VM_LOOP_OP(X86_OP_CMP_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_64, 0, 512ULL);
x86_l_1193:
	/* 0x1193: jne    1160 <tc_packet_checksum_fold_prog+0x60> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		return 0;
	loop->next = 0x1195;
	return 1;
	#undef __x86_vm_state
	return 0;
}

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
	/* 0x1150: xor    ecx,ecx */
	X86_VM_LOOP_OP(X86_OP_ALU_REG, X86_RCX, X86_RCX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1152:
	/* 0x1152: xor    r8d,r8d */
	X86_VM_LOOP_OP(X86_OP_ALU_REG, X86_R8, X86_R8, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_1155:
	/* 0x1155: data16 cs nop WORD PTR [rax+rax*1+0x0] */
	X86_VM_LOOP_OP(X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1160:
	/* 0x1160: movzx  r9d,WORD PTR [rax+rcx*2+0x10] */
	/* nested verifier loop lowering */
	struct x86_vm_reg_save __x86_loop_save_1160_1160_rdi = {};
	x86_vm_loop_prepare(loop, __x86_vm_data, __x86_vm_data_end, &__x86_loop_save_1160_1160_rdi);
	if (bpf_loop(256, x86_loop_1160_1160_cb, loop, 0) < 0) {
		loop->failed = __LINE__;
		return 1;
	}
	x86_vm_loop_restore_rdi(loop, &__x86_loop_save_1160_1160_rdi);
	if (loop->failed)
		return 1;
	if (loop->done)
		return 1;
	if (loop->next == 0x1195) {
		loop->next = 0;
		goto x86_l_1195;
	}
	return 1;
x86_l_1195:
	/* 0x1195: mov    ecx,r8d */
	X86_VM_LOOP_OP(X86_OP_MOV_REG, X86_RCX, X86_R8, X86_WIDTH_32, 0, 0);
x86_l_1198:
	/* 0x1198: shr    ecx,0x10 */
	X86_VM_LOOP_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHR, 16ULL);
x86_l_119b:
	/* 0x119b: add    ecx,r8d */
	X86_VM_LOOP_OP(X86_OP_ALU_REG, X86_RCX, X86_R8, X86_WIDTH_32, X86_ALU_ADD, 0);
x86_l_119e:
	/* 0x119e: not    ecx */
	X86_VM_LOOP_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_NOT, 0);
x86_l_11a0:
	/* 0x11a0: movzx  r8d,cx */
	X86_VM_LOOP_OP(X86_OP_MOVZX_REG, X86_R8, X86_RCX, X86_WIDTH_32, X86_WIDTH_16, 0);
x86_l_11a4:
	/* 0x11a4: mov    ecx,esi */
	X86_VM_LOOP_OP(X86_OP_MOV_REG, X86_RCX, X86_RSI, X86_WIDTH_32, 0, 0);
x86_l_11a6:
	/* 0x11a6: shl    ecx,0x4 */
	X86_VM_LOOP_OP(X86_OP_ALU_IMM, X86_RCX, X86_REG_NONE, X86_WIDTH_32, X86_ALU_SHL, 4ULL);
x86_l_11a9:
	/* 0x11a9: shl    r8,cl */
	X86_VM_LOOP_OP(X86_OP_ALU_REG, X86_R8, X86_RCX, X86_WIDTH_64, X86_ALU_SHL, 0);
x86_l_11ac:
	/* 0x11ac: xor    rdx,r8 */
	X86_VM_LOOP_OP(X86_OP_ALU_REG, X86_RDX, X86_R8, X86_WIDTH_64, X86_ALU_XOR, 0);
x86_l_11af:
	/* 0x11af: inc    esi */
	X86_VM_LOOP_OP(X86_OP_ALU_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, X86_ALU_INC, 1);
x86_l_11b1:
	/* 0x11b1: cmp    esi,0x20 */
	X86_VM_LOOP_OP(X86_OP_CMP_IMM, X86_RSI, X86_REG_NONE, X86_WIDTH_32, 0, 32ULL);
x86_l_11b4:
	/* 0x11b4: jne    1150 <tc_packet_checksum_fold_prog+0x50> */
	if (__x86_loop_index + 1 >= 32) {
		X86_VM_LOOP_EXIT(0x11b6);
	}
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		return 0;
	loop->next = 0x11b6;
	return 1;
	#undef __x86_vm_state
	return 0;
}

SEC("xdp")
int tc_packet_checksum_fold_x86_vm_xdp(struct xdp_md *ctx)
{
	void *__x86_vm_ctx = (void *)ctx;
	void *__x86_vm_data = (void *)(long)ctx->data;
	void *__x86_vm_data_end = (void *)(long)ctx->data_end;
	struct x86_vm_loop_ctx __x86_loop = {};
	struct x86_insn __x86_vm_insn = {};
	#define __x86_vm_state __x86_loop.state
	x86_init_state(&__x86_vm_state, (void *)ctx);
x86_l_1100:
	/* 0x1100: mov    rax,QWORD PTR [rdi] */
	X86_VM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 0ULL);
x86_l_1103:
	/* 0x1103: mov    rcx,QWORD PTR [rdi+0x8] */
	X86_VM_RUN_OP(X86_OP_MOV_LOAD, X86_RCX, X86_RDI, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1107:
	/* 0x1107: cmp    rax,rcx */
	X86_VM_RUN_OP(X86_OP_CMP_REG, X86_RAX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_110a:
	/* 0x110a: jbe    1121 <tc_packet_checksum_fold_prog+0x21> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_BE))
		goto x86_l_1121;
x86_l_110c:
	/* 0x110c: mov    DWORD PTR [rdi+0x10],0xffffffff */
	X86_VM_RUN_OP(X86_OP_MOV_STORE_IMM, X86_RDI, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 73014444031ULL);
x86_l_1113:
	/* 0x1113: mov    eax,0x2 */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, 0, 2ULL);
x86_l_1118:
	/* 0x1118: mov    edx,0xffffffff */
	X86_VM_RUN_OP(X86_OP_MOV_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_32, 0, 4294967295ULL);
x86_l_111d:
	/* 0x111d: mov    DWORD PTR [rdi+0x14],edx */
	X86_VM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_1120:
	/* 0x1120: ret */
	X86_VM_RET_RAX();
x86_l_1121:
	/* 0x1121: lea    rdx,[rax+0x8] */
	X86_VM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 8ULL);
x86_l_1125:
	/* 0x1125: cmp    rdx,rcx */
	X86_VM_RUN_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_1128:
	/* 0x1128: ja     110c <tc_packet_checksum_fold_prog+0xc> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_110c;
x86_l_112a:
	/* 0x112a: lea    rdx,[rax+0x410] */
	X86_VM_RUN_OP(X86_OP_LEA, X86_RDX, X86_RAX, X86_WIDTH_64, X86_MEM_AUX(X86_REG_NONE, 0), 1040ULL);
x86_l_1131:
	/* 0x1131: cmp    rdx,rcx */
	X86_VM_RUN_OP(X86_OP_CMP_REG, X86_RDX, X86_RCX, X86_WIDTH_64, 0, 0);
x86_l_1134:
	/* 0x1134: ja     110c <tc_packet_checksum_fold_prog+0xc> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_A))
		goto x86_l_110c;
x86_l_1136:
	/* 0x1136: cmp    DWORD PTR [rax+0x8],0x20 */
	X86_VM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 34359738400ULL);
x86_l_113a:
	/* 0x113a: jne    110c <tc_packet_checksum_fold_prog+0xc> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_110c;
x86_l_113c:
	/* 0x113c: cmp    DWORD PTR [rax+0xc],0x200 */
	X86_VM_RUN_OP(X86_OP_CMP_MEM_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 51539608064ULL);
x86_l_1143:
	/* 0x1143: jne    110c <tc_packet_checksum_fold_prog+0xc> */
	if (x86_eval_cc(&__x86_vm_state, X86_CC_NE))
		goto x86_l_110c;
x86_l_1145:
	/* 0x1145: push   rbp */
	X86_VM_RUN_OP(X86_OP_PUSH, X86_REG_NONE, X86_RBP, X86_WIDTH_64, 0, 0);
x86_l_1146:
	/* 0x1146: mov    rbp,rsp */
	X86_VM_RUN_OP(X86_OP_MOV_REG, X86_RBP, X86_RSP, X86_WIDTH_64, 0, 0);
x86_l_1149:
	/* 0x1149: xor    esi,esi */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RSI, X86_RSI, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_114b:
	/* 0x114b: xor    edx,edx */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RDX, X86_RDX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_114d:
	/* 0x114d: nop    DWORD PTR [rax] */
	X86_VM_RUN_OP(X86_OP_NOP, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_1150:
	/* 0x1150: xor    ecx,ecx */
	/* verifier loop lowering: bpf_loop callback preserves x86 steps */
	struct x86_vm_reg_save __x86_loop_save_1150_1150_rdi = {};
	x86_vm_loop_prepare((&__x86_loop), __x86_vm_data, __x86_vm_data_end, &__x86_loop_save_1150_1150_rdi);
	if (bpf_loop(32, x86_loop_1150_1150_cb, (&__x86_loop), 0) < 0) {
		(&__x86_loop)->failed = __LINE__;
		return XDP_ABORTED;
	}
	x86_vm_loop_restore_rdi((&__x86_loop), &__x86_loop_save_1150_1150_rdi);
	if ((&__x86_loop)->failed)
		return XDP_ABORTED;
	if ((&__x86_loop)->done)
		X86_VM_RET_RAX();
	if ((&__x86_loop)->next == 0x11b6) {
		goto x86_l_11b6;
	}
	return XDP_ABORTED;
x86_l_11b6:
	/* 0x11b6: mov    DWORD PTR [rdi+0x10],edx */
	X86_VM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 16ULL);
x86_l_11b9:
	/* 0x11b9: shr    rdx,0x20 */
	X86_VM_RUN_OP(X86_OP_ALU_IMM, X86_RDX, X86_REG_NONE, X86_WIDTH_64, X86_ALU_SHR, 32ULL);
x86_l_11bd:
	/* 0x11bd: xor    eax,eax */
	X86_VM_RUN_OP(X86_OP_ALU_REG, X86_RAX, X86_RAX, X86_WIDTH_32, X86_ALU_XOR, 0);
x86_l_11bf:
	/* 0x11bf: pop    rbp */
	X86_VM_RUN_OP(X86_OP_POP, X86_RBP, X86_REG_NONE, X86_WIDTH_64, 0, 0);
x86_l_11c0:
	/* 0x11c0: mov    DWORD PTR [rdi+0x14],edx */
	X86_VM_RUN_OP(X86_OP_MOV_STORE_REG, X86_RDI, X86_RDX, X86_WIDTH_32, X86_MEM_AUX(X86_REG_NONE, 0), 20ULL);
x86_l_11c3:
	/* 0x11c3: ret */
	X86_VM_RET_RAX();
	#undef __x86_vm_state
	return XDP_ABORTED;
}

X86_VM_LICENSE();
