#ifdef HEADER_ORACLE_BPF
#define _(x) __builtin_preserve_access_index(x)
#define bpf_core_type_exists(t) __builtin_preserve_type_info(*(t *)0, 0)
#else
#include "core-compat.h"
#endif
#define SEC(s) __attribute__((section(s), used))
struct kprog_absent_core_type { int value; };
SEC("query/live_poison") int live_poison(struct kprog_absent_core_type *ctx)
{ return _(ctx->value); }
SEC("query/dead_poison") int dead_poison(struct kprog_absent_core_type *ctx)
{
    if (bpf_core_type_exists(struct kprog_absent_core_type))
        return _(ctx->value);
    return 7;
}
