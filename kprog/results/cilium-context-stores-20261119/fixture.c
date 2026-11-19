#include <linux/bpf.h>
#include <bpf/bpf_helpers.h>
extern void *bpf_cast_to_kern_ctx(void *) __ksym;
static __always_inline void store16(void *base, unsigned long value)
{ asm volatile("*(u16 *)(%0 + 0) = %1" :: "r"(base), "r"(value) : "memory"); }
SEC("classifier") int class_store(struct __sk_buff *ctx)
{
    void *kernel = bpf_cast_to_kern_ctx(ctx);
    store16((char *)kernel+46, ctx->mark);
    return ctx->tc_classid;
}
#ifdef SELECTOR_CONTROLS
SEC("classifier") int wrong_root(struct __sk_buff *ctx)
{ store16((char *)ctx+46, ctx->mark); return 0; }
SEC("classifier") int wrong_offset(struct __sk_buff *ctx)
{ store16((char *)bpf_cast_to_kern_ctx(ctx)+48, ctx->mark); return 0; }
SEC("xdp") int wrong_section(void *ctx)
{ store16((char *)bpf_cast_to_kern_ctx(ctx)+46, 7); return 0; }
SEC("classifier") int wrong_width(struct __sk_buff *ctx)
{
    void *p = (char *)bpf_cast_to_kern_ctx(ctx)+46;
    asm volatile("*(u32 *)(%0 + 0) = %1" :: "r"(p), "r"(7UL) : "memory");
    return 0;
}
SEC("classifier") int variable_offset(struct __sk_buff *ctx)
{ store16((char *)bpf_cast_to_kern_ctx(ctx)+ctx->mark, 7); return 0; }
#endif
char fixture_license[] SEC("license") = "GPL";
