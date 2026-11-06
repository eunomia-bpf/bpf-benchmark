/* Catch expanded stack contexts escaping to kernel helpers and stale packet
 * windows after an adjustment. Other helper arguments retain their identity. */
#include <assert.h>
#include <stdio.h>
#include <linux/types.h>
#undef __always_inline
#define __always_inline inline
#define X86_SIM_ENABLE_STACK
#define bpf_xdp_adjust_head oracle_xdp_adjust_head
#include "../../../kprog/formal/oracles/x86_helper_environment_host.h"
#undef bpf_xdp_adjust_head
static struct xdp_md *expected;
static long bpf_xdp_adjust_head(struct xdp_md *ctx, int delta)
{
    assert(ctx == expected);
    ctx->data += delta;
    return 0;
}
#include "../../../kprog/x86/x86_sim_local_bpf.h"
static void xdp(void)
{
    struct xdp_md actual = {.data=0x1000, .data_end=0x1100};
    struct xdp_md *ctx=&actual;
    expected=ctx;
    X86_SIM_ENTRY_XDP(ctx);
    assert(X86_SIM_L_HELPER_CTX_PTR(X86_RDI)==ctx);
    assert(X86_SIM_L_HELPER_ARG_PTR(X86_RDI)==&__x86_sim_abi);
    X86_SIM_L_WRITE_REG_PTR_TAG(X86_RSI, (void *)16, X86_SIM_TAG_SCALAR);
    X86_SIM_BPF_CALL_bpf_xdp_adjust_head();
    assert(actual.data==0x1010);
    assert(__x86_sim_abi.data==(void *)0x1010);
    assert(__x86_sim_abi.data_end==(void *)0x1100);
    X86_SIM_L_WRITE_REG_PTR_TAG(X86_RDI, (char *)&__x86_sim_abi+1, X86_SIM_TAG_ABI);
    assert(X86_SIM_L_HELPER_CTX_PTR(X86_RDI)==(char *)&__x86_sim_abi+1);
}
static void raw(void)
{
    unsigned char actual[32];
    void *ctx=actual;
    X86_SIM_ENTRY_RAW(ctx);
    assert(X86_SIM_L_HELPER_CTX_PTR(X86_RDI)==ctx);
    X86_SIM_L_WRITE_REG_PTR_TAG(X86_RDI, actual+7, X86_SIM_TAG_ABI);
    assert(X86_SIM_L_HELPER_CTX_PTR(X86_RDI)==actual+7);
}
int main(void)
{
    xdp();raw();
    puts("exact XDP helper context, offset/raw identity, refreshed packet window PASS");
}
