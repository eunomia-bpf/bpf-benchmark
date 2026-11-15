/* Actual conditional families through their normal constant-opcode wrappers. */
#define X86_SIM_ENABLE_STACK 1
#include "../../x86/x86_sim_inline.h"
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_CMOV,X86_OP_CMOV)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_CMOV_MEM,X86_OP_CMOV_MEM)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_SETCC,X86_OP_SETCC)
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_SETCC_MEM,X86_OP_SETCC_MEM)
SEC("socket") int x86_conditional_compile(struct __sk_buff *ctx)
{
    X86_SIM_ENTRY_RAW(ctx);
    X86_SIM_BIND_INLINE();
    __x86_stack_mem.q[0]=((__u64)ctx->mark<<32)|ctx->priority;
    __x86_rsp.ptr=(void *)(long)-64;
    __x86_rsi.ptr=(void *)&__x86_stack_mem.b[0];__x86_rsi_tag=X86_SIM_TAG_STACK;
    __x86_rdx.ptr=(void *)(long)(ctx->hash&1U);
    __x86_cf=ctx->priority&1;__x86_zf=ctx->mark&1;__x86_pf=ctx->hash&1;
    X86_SIM_RUN_OP(X86_OP_CMOV,X86_RAX,X86_RSI,8,X86_CC_E,0);
    X86_SIM_RUN_OP(X86_OP_CMOV,X86_RAX,X86_RDX,4,X86_CC_P,0);
    X86_SIM_RUN_OP(X86_OP_CMOV_MEM,X86_RAX,X86_RSP,4,X86_MEM_AUX(X86_REG_NONE,0)|(X86_CC_B<<24),0);
    X86_SIM_RUN_OP(X86_OP_CMOV_MEM,X86_RAX,X86_RSI,8,X86_MEM_AUX(X86_RDX,0)|(X86_CC_NP<<24),1ULL<<32);
    X86_SIM_RUN_OP(X86_OP_SETCC,X86_RAX,0,0,X86_CC_B|(8U<<8),0);
    X86_SIM_RUN_OP(X86_OP_SETCC_MEM,X86_RSP,0,0,X86_MEM_AUX(X86_REG_NONE,0)|(X86_CC_E<<24),16);
    __x86_rdx.ptr=(void *)&__x86_stack_mem.b[0];
    X86_SIM_RUN_OP(X86_OP_SETCC_MEM,X86_REG_NONE,0,0,X86_MEM_AUX(X86_RDX,0)|(X86_CC_NE<<24),17);
    return (__u32)((unsigned long)__x86_rax.ptr^__x86_stack_mem.q[2]);
}
char LICENSE[] SEC("license")="GPL";
