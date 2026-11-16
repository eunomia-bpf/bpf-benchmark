/* Full producer entries: live context fields, helper identity and return/input
 * prefixes. Platform values are test interpretations, not kernel refinements. */
#include <linux/bpf.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <setjmp.h>
#if SKB
extern int x86_context_skb_x86_sim_xdp(struct __sk_buff *);
#define ENTRY x86_context_skb_x86_sim_xdp
static struct __sk_buff ctx,expected;
#else
extern int x86_context_xdp_x86_sim_xdp(struct xdp_md *);
#define ENTRY x86_context_xdp_x86_sim_xdp
static struct xdp_md ctx,expected;
#endif
static __u64 values[2][3],entropy,stack_base;
static unsigned inputs,sp_calls,helpers,fields,rejecting;
static jmp_buf refusal;
static void require(int ok)
{ if (!ok) {fprintf(stderr,"x86 context program mismatch: inputs %u helpers %u fields %u\n",inputs,helpers,fields);exit(1);} }
unsigned long native_lab_entry_input(unsigned kind)
{
    require(kind==1 || kind==6);++inputs;
    if (kind==1) {++sp_calls;return stack_base;}
    entropy^=entropy<<13;entropy^=entropy>>7;entropy^=entropy<<17;return entropy;
}
static __u64 helper_result(void) { return 0xfedcba9876543210ULL; }
static void update_context(void)
{
    expected=ctx;expected.data=(__u32)values[1][0];expected.data_end=(__u32)values[1][1];
#if SKB
    expected.cb[0]=(__u32)values[1][2];expected.cb[1]=values[1][2]>>32;
#else
    expected.data_meta=(__u32)values[1][2];
#endif
    ctx=expected;
}
static long helper(void *p,unsigned arg)
{
    require(p==&ctx && arg==0 && helpers==0 && inputs==24);
    require(fields==(ADAPTER?(SKB?2U:3U):0U));
    ++helpers;update_context();
    if (rejecting) longjmp(refusal,1);
    return (long)helper_result();
}
long kprog_x86_callee_bpf_xdp_adjust_head(struct xdp_md *p,int delta)
{ require(!SKB);return helper(p,(unsigned)delta); }
long kprog_x86_callee_bpf_skb_pull_data(struct __sk_buff *p,__u32 length)
{ require(SKB);return helper(p,length); }
void *kprog_c_context_pointer(const void *p,__u8 kind,__u32 offset)
{
    require(ADAPTER && p==&ctx && kind==(SKB?1U:0U));
#if SKB
    unsigned index=fields%2;unsigned expected_offset=index?__builtin_offsetof(struct __sk_buff,data_end):__builtin_offsetof(struct __sk_buff,data);
#else
    unsigned index=fields%3;unsigned expected_offset=index==0?__builtin_offsetof(struct xdp_md,data):index==1?__builtin_offsetof(struct xdp_md,data_end):__builtin_offsetof(struct xdp_md,data_meta);
#endif
    require(offset==expected_offset && fields/(SKB?2U:3U)==helpers);
    require(ctx.data==(__u32)values[helpers][0] && ctx.data_end==(__u32)values[helpers][1]);
#if !SKB
    require(ctx.data_meta==(__u32)values[helpers][2]);
#endif
    ++fields;
    return (void *)(uintptr_t)values[helpers][index];
}
__u64 kprog_c_pointer_bits(const void *p) { return (uintptr_t)p; }
static __attribute__((noreturn)) void unexpected(void)
{ fputs("unexpected context program platform call\n",stderr);exit(1); }
void kprog_x86_observe_unresolved(void) { unexpected(); }
unsigned long long kprog_x86_observe_time(void) { unexpected(); }
void kprog_c_trap(void) { unexpected(); }
void __builtin_memcpy_aligned(void *d,const void *s,size_t n,size_t a)
{ require(a==1);memcpy(d,s,n); }
static __u64 observed(unsigned phase,unsigned index)
{
    __u64 value=values[phase][index];
    return ADAPTER || (SKB && index==2) ? value : (__u32)value;
}
int main(void)
{
    for (volatile unsigned seed=1;seed<=16;++seed) for (rejecting=0;rejecting<2;++rejecting) {
        for (unsigned phase=0;phase<2;++phase) for (unsigned i=0;i<3;++i)
            values[phase][i]=((__u64)seed*0x9e3779b97f4a7c15ULL)^((__u64)(phase+1)*(i+1)*0x1122334455667788ULL)^((__u64)i*0x807060504030201ULL);
        memset(&ctx,0x5a,sizeof(ctx));ctx.data=(__u32)values[0][0];ctx.data_end=(__u32)values[0][1];
#if SKB
        ctx.cb[0]=(__u32)values[0][2];ctx.cb[1]=values[0][2]>>32;
#else
        ctx.data_meta=(__u32)values[0][2];
#endif
        expected=ctx;inputs=sp_calls=helpers=fields=0;entropy=seed;
        stack_base=0xffff000012340000ULL+((__u64)seed<<12);
        volatile __u32 got=0;
        if (!setjmp(refusal)) {
            got=ENTRY(&ctx);require(!rejecting);
            __u64 value=helper_result();
            for (unsigned i=0;i<3;++i) value^=observed(0,i)^observed(1,i);
            require(got==(__u32)(value^(value>>32)));
        } else require(rejecting);
        require(helpers==1 && sp_calls==1 && inputs==(rejecting?24U:46U));
        require(fields==(ADAPTER?(SKB?2U:3U)*(rejecting?1U:2U):0U));
        require(!memcmp(&ctx,&expected,sizeof(ctx)));
    }
    printf("x86 %s producer: 16 live-context returns and 16 helper-refusal prefixes (%s)\n",SKB?"SKB":"XDP",ADAPTER?"full-pointer adapter":"native UAPI host");
    return 0;
}
