/* Actual immediate/register store prefixes, lanes, index and provenance. */
#define X86_SIM_ENABLE_STACK 1
#include "../../x86/x86_sim_inline.h"
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_MOV_STORE_IMM,X86_OP_MOV_STORE_IMM)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_MOV_STORE_REG,X86_OP_MOV_STORE_REG)
SEC("socket") int x86_store_selectors_compile(struct __sk_buff *ctx)
{
    X86_SIM_ENTRY_RAW(ctx);
    X86_SIM_BIND_INLINE();
    __x86_stack_mem.q[0]=((__u64)ctx->mark<<32)|ctx->priority;
    __x86_stack_mem.q[1]=ctx->hash;
    __x86_stack_mem.q[2]=~__x86_stack_mem.q[0];
    __x86_stack_mem.q[3]=~(__u64)ctx->hash;
    __x86_rsp.ptr=(void *)(long)-64;
    __x86_rax.ptr=(void *)(unsigned long)(((__u64)ctx->mark<<32)|ctx->priority);
    __x86_rsi.ptr=(void *)&__x86_stack_mem.b[0];__x86_rsi_tag=X86_SIM_TAG_STACK;
    __x86_rdx.ptr=(void *)(unsigned long)(ctx->mark&1U);
    X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM,X86_RSP,X86_REG_NONE,8,0,(8ULL<<32)|0x80000001ULL);
    X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG,X86_RSP,X86_RAX,1,(8U<<24)|X86_MEM_AUX(X86_REG_NONE,0),1);
    X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG,X86_RSI,X86_RAX,2,X86_MEM_AUX(X86_RDX,1),3);
    X86_SIM_RUN_OP(X86_OP_MOV_STORE_IMM,X86_RSI,X86_REG_NONE,4,X86_MEM_AUX(X86_REG_NONE,0),(16ULL<<32)|0xfedcba98ULL);
    X86_SIM_RUN_OP(X86_OP_MOV_STORE_REG,X86_RSP,X86_RSI,8,X86_MEM_AUX(X86_REG_NONE,0),24);
    return (__u32)(__x86_stack_mem.q[0]^__x86_stack_mem.q[1]^__x86_stack_mem.q[2]^__x86_stack_mem.q[3]);
}
char LICENSE[] SEC("license")="GPL";
