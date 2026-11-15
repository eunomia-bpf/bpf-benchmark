/* Actual context consumers and fixed/dynamic context operands, compile only. */
#define X86_SIM_ENABLE_STACK 1
#include "../../x86/x86_sim_inline.h"
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_MOV_LOAD,X86_OP_MOV_LOAD)

SEC("xdp") int x86_xdp_context_compile(struct xdp_md *ctx)
{
    X86_SIM_ENTRY_XDP(ctx); X86_SIM_BIND_INLINE();
    X86_SIM_RUN_OP(X86_OP_MOV_LOAD,X86_RAX,X86_RDI,8,X86_MEM_AUX(X86_REG_NONE,0),0);
    __u64 result=NATIVE_LAB_NUMERIC((unsigned long)__x86_rax.ptr);
    result^=NATIVE_LAB_NUMERIC(X86_SIM_L_XDP_READ(__x86_sim_helper_abi_base,8,8));
    result^=NATIVE_LAB_NUMERIC(X86_SIM_L_XDP_READ(__x86_sim_helper_abi_base,16,8));
    result^=X86_SIM_L_XDP_READ(__x86_sim_helper_abi_base,ctx->rx_queue_index&3,1);
    return (__u32)result;
}
SEC("tc") int x86_skb_context_compile(struct __sk_buff *ctx)
{
    X86_SIM_ENTRY_SKB(ctx); X86_SIM_BIND_INLINE();
    X86_SIM_RUN_OP(X86_OP_MOV_LOAD,X86_RAX,X86_RDI,8,X86_MEM_AUX(X86_REG_NONE,0),X86_SKB_DATA_OFF);
    __u64 result=NATIVE_LAB_NUMERIC((unsigned long)__x86_rax.ptr);
    result^=NATIVE_LAB_NUMERIC(X86_SIM_L_SKB_READ(X86_RDI,X86_SKB_DATA_END_OFF,8));
    result^=X86_SIM_L_SKB_READ(X86_RDI,X86_SKB_DATA_OFF+1,2);
    result^=X86_SIM_L_SKB_READ(X86_RDI,X86_SKB_CB_OFF,8);
    result^=X86_SIM_L_SKB_READ(X86_RDI,X86_SKB_CB_OFF+(ctx->mark&3),4);
    result^=X86_SIM_L_SKB_READ(X86_RDI,134,2);
    result^=X86_SIM_L_SKB_READ(X86_RDI,145,1);
    result^=X86_SIM_L_SKB_READ(X86_RDI,168,4);
    result^=X86_SIM_L_SKB_READ(X86_RDI,232+(ctx->mark&1),4);
    return (__u32)result;
}
char LICENSE[] SEC("license")="GPL";
