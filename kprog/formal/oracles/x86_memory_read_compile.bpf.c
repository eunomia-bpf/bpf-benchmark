/* Actual shared fixed/indexed/private read and MOVBE consumers. */
#define X86_SIM_ENABLE_STACK 1
#include "../../x86/x86_sim_inline.h"
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_MOVBE_LOAD,X86_OP_MOVBE_LOAD)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_MOVBE_STORE,X86_OP_MOVBE_STORE)
SEC("socket") int x86_memory_read_compile(struct __sk_buff *ctx)
{
    X86_SIM_ENTRY_RAW(ctx);
    X86_SIM_BIND_INLINE();
    __x86_stack_mem.q[0]=((__u64)ctx->mark<<32)|ctx->priority;
    __x86_stack_mem.q[1]=~__x86_stack_mem.q[0];
    __x86_stack_mem.q[2]=ctx->hash;
    __x86_stack_mem.q[3]=~(__u64)ctx->hash;
    __x86_rsp.ptr=(void *)(long)-64;
    __x86_rsi.ptr=(void *)&__x86_stack_mem.b[0];__x86_rsi_tag=X86_SIM_TAG_STACK;
    __x86_rdx.ptr=(void *)(long)(ctx->priority&1U);
    __u64 result=X86_SIM_L_READ_MEM_VALUE(X86_RSI,X86_MEM_AUX(X86_REG_NONE,0),1,2,0);
    result^=X86_SIM_L_READ_MEM_VALUE(X86_RSI,X86_MEM_AUX(X86_RDX,1),1,8,0);
    result^=X86_SIM_L_READ_MEM_VALUE(X86_RSI,X86_MEM_AUX(X86_REG_NONE,0),3ULL<<32,4,1);
    X86_SIM_RUN_OP(X86_OP_MOVBE_LOAD,X86_RAX,X86_RSP,2,0,2);
    result^=(unsigned long)__x86_rax.ptr;
    X86_SIM_RUN_OP(X86_OP_MOVBE_LOAD,X86_RAX,X86_RSI,4,X86_MEM_AUX(X86_REG_NONE,0),1);
    result^=(unsigned long)__x86_rax.ptr;
    X86_SIM_RUN_OP(X86_OP_MOVBE_LOAD,X86_RAX,X86_RSI,8,X86_MEM_AUX(X86_RDX,1),1);
    result^=(unsigned long)__x86_rax.ptr;
    X86_SIM_RUN_OP(X86_OP_MOVBE_STORE,X86_RSP,X86_RAX,4,0,8);
    X86_SIM_RUN_OP(X86_OP_MOVBE_STORE,X86_RSI,X86_RAX,8,X86_MEM_AUX(X86_REG_NONE,0),16);
    return (__u32)(result^__x86_stack_mem.q[1]^__x86_stack_mem.q[2]);
}
char LICENSE[] SEC("license")="GPL";
