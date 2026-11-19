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
