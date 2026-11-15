/* Actual stack read/fact consumers, with dynamic alignment and release. */
#define X86_SIM_ENABLE_STACK 1
#include "../../x86/x86_sim_inline.h"
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_MOV_LOAD, X86_OP_MOV_LOAD)

SEC("socket") int x86_stack_read_compile(struct __sk_buff *ctx)
{
    X86_SIM_ENTRY_RAW(ctx);
    X86_SIM_BIND_INLINE();
    __x86_stack_mem.q[0]=((__u64)ctx->mark<<32)|ctx->priority;
    __x86_stack_mem.q[1]=~__x86_stack_mem.q[0];
    __x86_stack_mem.q[2]=ctx->hash;
    __x86_stack_mem.q[3]=~(__u64)ctx->hash;
    __x86_stack_mem.q[4]=ctx->mark;
    __x86_stack_mem.q[5]=ctx->priority;
    __x86_stack_mem.q[6]=ctx->hash;
    __x86_stack_mem.q[7]=~(__u64)ctx->mark;
    __x86_rsp.ptr=(void *)(long)-(32+(ctx->mark&1U)*32);
    X86_SIM_L_SV_TAG(0)=ctx->mark&7U;
    X86_SIM_L_SV_PTR(0)=(void *)&__x86_stack_mem.b[24];
    __s64 offset=-64+(ctx->priority&7U);
    __u64 result=X86_SIM_L_STACK_READ(offset,1);
    result^=X86_SIM_L_STACK_READ(offset,2);
    result^=X86_SIM_L_STACK_READ(offset,4);
    result^=X86_SIM_L_STACK_READ(offset,8);
    result^=X86_SIM_L_STACK_READ_OWNED(offset,ctx->mark);
    struct x86_sim_stack_value fact=X86_SIM_L_STACK_VALUES_READ(ctx->priority&15U,8);
    result^=fact.tag^(__u64)(unsigned long)fact.pointer;
    X86_SIM_RUN_OP(X86_OP_MOV_LOAD,X86_RAX,X86_RSP,1,0,1);
    result^=(unsigned long)__x86_rax.ptr;
    X86_SIM_RUN_OP(X86_OP_MOV_LOAD,X86_RAX,X86_RSP,2,0,2);
    result^=(unsigned long)__x86_rax.ptr;
    X86_SIM_RUN_OP(X86_OP_MOV_LOAD,X86_RAX,X86_RSP,4,0,4);
    result^=(unsigned long)__x86_rax.ptr;
    X86_SIM_RUN_OP(X86_OP_MOV_LOAD,X86_RAX,X86_RSP,8,0,8);
    return (__u32)(result^(unsigned long)__x86_rax.ptr);
}
char LICENSE[] SEC("license")="GPL";
