/* Compile both actual XMM0 handlers through the producer's by-reference entry. */
#define X86_SIM_ENABLE_STACK 1
#include "../../x86/x86_sim_inline.h"
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_LOAD_XMM0,X86_OP_LOAD_XMM0)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_STORE_XMM0,X86_OP_STORE_XMM0)
SEC("socket") int x86_xmm0_compile(struct __sk_buff *ctx)
{
    X86_SIM_ENTRY_RAW(ctx);
    X86_SIM_BIND_INLINE();
    __x86_stack_mem.q[0]=ctx->mark;__x86_stack_mem.q[1]=ctx->priority;
    __x86_rsp.ptr=(void *)(long)-64;
    __x86_rsi.ptr=(void *)&__x86_stack_mem.b[0];__x86_rsi_tag=X86_SIM_TAG_STACK;
    __x86_rdx.ptr=(void *)(long)(ctx->hash&1U);
    X86_SIM_RUN_OP(X86_OP_LOAD_XMM0,0,X86_RSP,0,0,0);
    X86_SIM_RUN_OP(X86_OP_STORE_XMM0,X86_RSP,0,0,0,16);
    X86_SIM_RUN_OP(X86_OP_LOAD_XMM0,0,X86_RSI,0,X86_MEM_AUX(X86_RDX,0),1);
    X86_SIM_RUN_OP(X86_OP_STORE_XMM0,X86_RSI,0,0,X86_MEM_AUX(X86_RDX,0),17);
    __x86_rdx.ptr=(void *)&__x86_stack_mem.b[0];
    X86_SIM_RUN_OP(X86_OP_LOAD_XMM0,0,X86_REG_NONE,0,X86_MEM_AUX(X86_RDX,0),0);
    X86_SIM_RUN_OP(X86_OP_STORE_XMM0,X86_REG_NONE,0,0,X86_MEM_AUX(X86_RDX,0),32);
    return (__u32)(__x86_stack_mem.q[2]^__x86_stack_mem.q[3]^__x86_stack_mem.q[4]^__x86_xmm0_hi);
}
char LICENSE[] SEC("license")="GPL";
