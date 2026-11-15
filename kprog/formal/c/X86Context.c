#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "X86Context.h"

__u64 kprog_x86_skb_read(struct x86_sim_register_state *state,
                        __u64 base, __s64 offset, __u64 width)
{
    struct x86_sim_register_state *__x86_state=state;
    __u64 result;
    X86_SIM_L_SKB_READ_INTO(result,base,offset,width);
    return result;
}
__u64 kprog_x86_xdp_read(struct x86_sim_register_state *state,
                        const void *base, __s64 offset, __u64 width)
{
    struct x86_sim_register_state *__x86_state=state;
    __u64 result;
    X86_SIM_L_XDP_READ_INTO(result,base,offset,width);
    return result;
}
__u64 kprog_x86_cb_read(const void *context, __s64 offset, __u64 width)
{
    __u64 result;
    X86_SIM_L_SKB_CB_READ_BYTES_INTO(result,context,offset,width);
    return result;
}
__u8 kprog_x86_context_tag(__u64 kind, __s64 offset)
{
    __u8 tag;
    KPROG_ABI_LOAD_TAG_INTO(tag,kind,offset,X86_SIM_TAG_SCALAR,X86_SIM_TAG_PACKET,X86_SIM_TAG_PACKET_END);
    return tag;
}
