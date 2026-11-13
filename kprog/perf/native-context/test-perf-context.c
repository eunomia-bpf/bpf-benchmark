// Catches public register loads, sample fields and helper ctx identity drift.
typedef unsigned long u64;
struct public_ctx { u64 regs[21], sample_period, addr; };
struct sample_data { u64 flags, period, padding[21], addr; };
struct physical_ctx { u64 *regs; struct sample_data *data; void *event; };
static void *observed;
__attribute__((noinline)) static void observe(void *ctx) { observed = ctx; }

__attribute__((section("perf_event/test"), noinline))
u64 perf_entry(struct public_ctx *ctx)
{
    observe(ctx);
    return ctx->regs[0] + ctx->regs[20] + ctx->sample_period + ctx->addr
           + *((unsigned int *)&ctx->sample_period + 1);
}

__attribute__((section("kprobe/test"), noinline))
u64 kprobe_entry(struct public_ctx *ctx) { return ctx->regs[0] + ctx->regs[20]; }

int main(void)
{
    u64 regs[21] = {11};
    regs[20] = 43;
    struct sample_data data = {.period = 0x100000005ul, .addr = 700};
    union { struct physical_ctx ctx; struct public_ctx padding; } physical = {0};
    physical.ctx.regs = regs;
    physical.ctx.data = &data;
    struct public_ctx kprobe = {.regs = {17}};
    kprobe.regs[20] = 19;
    u64 result = perf_entry((struct public_ctx *)&physical.ctx);
    if (observed != &physical.ctx || result != 11 + 43 + 0x100000005ul + 700 + 1)
        return 1;
    return kprobe_entry(&kprobe) != 36;
}
