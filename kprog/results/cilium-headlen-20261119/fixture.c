#include <linux/bpf.h>
#include <bpf/bpf_helpers.h>
extern void *bpf_cast_to_kern_ctx(void *) __ksym;

static __always_inline unsigned long read32(void *base, unsigned long offset)
{
    unsigned long value;
    asm volatile("%0 = *(u32 *)(%1 + %2)" : "=r"(value) : "r"(base), "i"(offset) : "memory");
    return value;
}
static __always_inline unsigned word(unsigned value)
{ asm volatile("%0 = %0" : "+w"(value)); return value; }
static __always_inline int packet_byte(struct __sk_buff *ctx)
{
    unsigned long value;
    void *data = (void *)read32(ctx, 76);
    asm volatile("%0 = *(u8 *)(%1 + %2)" : "=r"(value) : "r"(data), "i"(23) : "memory");
    return value;
}
#define HEAD(NAME, CONDITION) \
SEC("classifier") int NAME(struct __sk_buff *ctx) { \
    void *kernel = bpf_cast_to_kern_ctx(ctx); \
    unsigned span = word(word(read32(kernel,112)) - word(read32(kernel,116))); \
    return (CONDITION) ? packet_byte(ctx) : 0; \
}
HEAD(head_ge, span >= 42)
HEAD(head_not_lt, !(span < 42))

SEC("tc") int old_tc(struct __sk_buff *ctx)
{
    unsigned long start=ctx->data, end=ctx->data_end;
    return end-start >= 42 ? *(unsigned char *)(start+23) : 0;
}
SEC("xdp") int old_xdp(struct xdp_md *ctx)
{
    unsigned long start=ctx->data, end=ctx->data_end;
    return end-start >= 42 ? *(unsigned char *)(start+23) : 0;
}
SEC("tc") int asm_tc(struct __sk_buff *ctx)
{
    unsigned long start=read32(ctx,76), end=read32(ctx,80);
    return end-start >= 42 ? packet_byte(ctx) : 0;
}

#ifdef SELECTOR_CONTROLS
extern void mutate_context(void *);
SEC("classifier") int wrong_root(struct __sk_buff *ctx)
{ unsigned n=word(read32(ctx,112)-read32(ctx,116)); return n>=42; }
SEC("classifier") int wrong_offset(struct __sk_buff *ctx)
{ void *k=bpf_cast_to_kern_ctx(ctx); unsigned n=word(read32(k,112)-read32(k,120)); return n>=42; }
SEC("kprobe/test") int wrong_section(struct __sk_buff *ctx)
{ void *k=bpf_cast_to_kern_ctx(ctx); unsigned n=word(read32(k,112)-read32(k,116)); return n>=42; }
SEC("classifier") int equality(struct __sk_buff *ctx)
{ void *k=bpf_cast_to_kern_ctx(ctx); unsigned n=word(read32(k,112)-read32(k,116)); return n==42; }
SEC("classifier") int signed_negative(struct __sk_buff *ctx)
{ void *k=bpf_cast_to_kern_ctx(ctx); unsigned n=word(read32(k,112)-read32(k,116)); return (int)n>=-1; }
SEC("classifier") int stale_call(struct __sk_buff *ctx)
{ void *k=bpf_cast_to_kern_ctx(ctx); unsigned n=word(read32(k,112)-read32(k,116)); mutate_context(ctx); return n>=42; }
SEC("classifier") int stale_store(struct __sk_buff *ctx)
{
    void *k=bpf_cast_to_kern_ctx(ctx); unsigned n=word(read32(k,112)-read32(k,116));
    asm volatile("*(u32 *)(%0 + %1) = %2" :: "r"(k),"i"(112),"r"(0UL) : "memory");
    return n>=42;
}
#endif
char license[] SEC("license") = "GPL";
