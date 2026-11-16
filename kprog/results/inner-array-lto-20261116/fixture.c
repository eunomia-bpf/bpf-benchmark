#include <stdint.h>
extern unsigned char outer_a[], outer_b[], outer_c[];
extern void *bpf_map_lookup_elem(void *, const void *);
struct context { uint32_t selector, key; };
static void *const choices[] = {outer_a, outer_b, outer_c};
void *mutable_choices[] = {outer_a, outer_b, outer_c};

uintptr_t entry(struct context *ctx)
{
    void *inner = bpf_map_lookup_elem(choices[ctx->selector % 3], &ctx->key);
    return inner ? (uintptr_t)bpf_map_lookup_elem(inner, &ctx->key) : 0;
}

uintptr_t entry_select(struct context *ctx)
{
    void *outer = ctx->selector & 1 ? outer_a : outer_b;
    void *inner = bpf_map_lookup_elem(outer, &ctx->key);
    return inner ? (uintptr_t)bpf_map_lookup_elem(inner, &ctx->key) : 0;
}

typedef void *(*lookup_fn)(void *, const void *);
uintptr_t entry_numeric(struct context *ctx)
{
    void *inner = ((lookup_fn)1)(choices[ctx->selector % 3], &ctx->key);
    return inner ? (uintptr_t)((lookup_fn)1)(inner, &ctx->key) : 0;
}

uintptr_t entry_mutable(struct context *ctx)
{
    void *inner = bpf_map_lookup_elem(mutable_choices[ctx->selector % 3], &ctx->key);
    return inner ? (uintptr_t)bpf_map_lookup_elem(inner, &ctx->key) : 0;
}

uintptr_t entry_arithmetic(struct context *ctx)
{
    char *inner = bpf_map_lookup_elem(choices[ctx->selector % 3], &ctx->key);
    return inner ? (uintptr_t)bpf_map_lookup_elem(inner + 1, &ctx->key) : 0;
}
