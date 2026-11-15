/* Compile the same by-reference inline body used by the producer. */
#define X86_SIM_ENABLE_STACK 1
#include "../../x86/x86_sim_inline.h"

X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_MOV_IMM, X86_OP_MOV_IMM)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_MOV_REG, X86_OP_MOV_REG)

SEC("socket") int x86_inline_compile(struct __sk_buff *ctx)
{
	X86_SIM_ENTRY_RAW(ctx);
	X86_SIM_BIND_INLINE();
	X86_SIM_RUN_OP(X86_OP_MOV_IMM, X86_RAX, X86_REG_NONE, X86_WIDTH_64, 0,
		((__u64)ctx->mark << 32) | ctx->priority);
	X86_SIM_RUN_OP(X86_OP_MOV_REG, X86_RCX, X86_RAX, X86_WIDTH_32, 0, 0);
	return (__u32)(unsigned long)__x86_rcx.ptr;
}
char LICENSE[] SEC("license") = "GPL";
