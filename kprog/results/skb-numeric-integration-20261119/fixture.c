#include "../../x86/x86_sim_local_bpf.h"

#define FIELD_VALUE(NAME, FIELD) \
__attribute__((section("classifier"))) \
unsigned long NAME(struct __sk_buff *ctx) { \
    return X86_SIM_L_CTX_NUMERIC(X86_SIM_L_SKB_FIELD(ctx, FIELD)); \
}
#define FIELD_LANE(NAME, FIELD) \
__attribute__((section("classifier"))) \
unsigned long NAME(struct __sk_buff *ctx, unsigned lane) { \
    return (X86_SIM_L_CTX_NUMERIC(X86_SIM_L_SKB_FIELD(ctx, FIELD)) >> ((lane & 7) * 8)) & 0xffffffffUL; \
}
FIELD_VALUE(data_value, data)
FIELD_VALUE(end_value, data_end)
FIELD_LANE(data_lane, data)
FIELD_LANE(end_lane, data_end)

__attribute__((section("classifier")))
unsigned long mark_value(struct __sk_buff *ctx)
{
    return X86_SIM_L_SKB_FIELD(ctx, mark);
}

/* Keep a public-context root visible without the shared field asm. */
#define DIRECT_FIELD(NAME, FIELD) \
__attribute__((section("classifier"))) \
unsigned long NAME(struct __sk_buff *ctx) { return ctx->FIELD; }
DIRECT_FIELD(data_direct, data)
DIRECT_FIELD(end_direct, data_end)
DIRECT_FIELD(mark_direct, mark)

/* Compile and inspect this faulting address; never execute it on the host. */
unsigned long absolute_address_control(void)
{
    unsigned long value;
    void *base = 0;
    asm volatile("$0 = *(u64 *)($1 + 112)" : "=r"(value) : "r"(base));
    return value;
}
