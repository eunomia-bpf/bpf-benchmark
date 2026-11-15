/* Compile the same by-reference inline body used by the producer. */
#define X86_SIM_ENABLE_STACK 1
#include "../../x86/x86_sim_inline.h"

X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_MOV_IMM, X86_OP_MOV_IMM)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_MOV_REG, X86_OP_MOV_REG)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_MOV_LOAD, X86_OP_MOV_LOAD)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_LOAD_XMM0, X86_OP_LOAD_XMM0)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_CALL_MEMCPY, X86_OP_CALL_MEMCPY)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_REP_MOVS, X86_OP_REP_MOVS)

SEC("socket") int x86_inline_compile(struct __sk_buff *ctx)
{
	X86_SIM_ENTRY_RAW(ctx);
	X86_SIM_BIND_INLINE();
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0,
		((__u64)ctx->mark << 32) | ctx->priority);
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
	__x86_stack_mem.q[0]=((__u64)ctx->mark<<32)|ctx->priority;
	__x86_stack_mem.q[1]=~__x86_stack_mem.q[0];
	__x86_stack_mem.q[2]=ctx->hash;
	__x86_rsp.ptr=(void *)(long)-(32+(ctx->mark&1U)*32);
	__x86_rsi.ptr=(void *)&__x86_stack_mem.b[0]; __x86_rsi_tag=X86_SIM_TAG_STACK;
	__x86_rdx.ptr=(void *)(long)(ctx->priority&7U);
	X86_SIM_RUN_OP(X86_OP_MOV_LOAD, X86_RAX, X86_RSI, X86_WIDTH_64, X86_MEM_AUX(X86_RDX,0), 0);
	X86_SIM_RUN_OP(X86_OP_LOAD_XMM0, X86_REG_NONE, X86_RSI, 0, X86_MEM_AUX(X86_RDX,0), 0);
	__x86_rdi.ptr=(void *)&__x86_stack_mem.b[16]; __x86_rdi_tag=X86_SIM_TAG_STACK;
	X86_SIM_RUN_OP(X86_OP_CALL_MEMCPY, X86_REG_NONE, X86_REG_NONE, 0, 0, 3);
	__x86_rcx.ptr=(void *)(long)2;
	X86_SIM_RUN_OP(X86_OP_REP_MOVS, X86_REG_NONE, X86_REG_NONE, X86_WIDTH_8, 0, 0);
	return (__u32)((unsigned long)__x86_rcx.ptr^__x86_xmm0_lo^__x86_xmm0_hi^__x86_stack_mem.q[2]);
}
char LICENSE[] SEC("license") = "GPL";
